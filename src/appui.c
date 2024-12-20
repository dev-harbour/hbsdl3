/*
 * Copyright 2024 Rafał Jopek <https://harbour.pl>
 */

#include "hbsdl3.h"
#include "hbvm.h"

typedef enum _ComponentType ComponentType;

enum _ComponentType
{
   BOX,
   BUTTON
};

typedef struct _APP   APP;
typedef struct _BoxUI BoxUI;

struct _APP
{
   SDL_Window   *pWindow;
   SDL_Renderer *pRenderer;
   const char   *title;
   int           width;
   int           height;
   SDL_Color     bg;

   ComponentType type;
   union
   {
      BoxUI *box;
   };
   int componentCount;

   PHB_ITEM keyBindings;
   bool quit;
};

struct _BoxUI
{
   const char *title;
   SDL_FRect   rect;
   SDL_Color   bg;
   BoxUI      *next;
};

static void app_add_box( APP *app, BoxUI *newBox );
static void app_draw_components( APP *app );
static void app_clear_components( APP *app );
static void app_handle_key_events( APP *app, SDL_Event *event );
static bool app_ismouse_inside_box( int mouseX, int mouseY, SDL_FRect *rect );
static void app_move_box_to_front( APP *app, BoxUI *box );
static void app_handle_mouse_events( APP *app, SDL_Event *event );

/* -------------------------------------------------------------------------
Garbage Collector APP
------------------------------------------------------------------------- */
static HB_GARBAGE_FUNC( hb_app_Destructor )
{
   APP **ppAPP = ( APP ** ) Cargo;

   if( ppAPP && *ppAPP )
   {
      if( ( *ppAPP )->box != NULL )
      {
         app_clear_components( *ppAPP );
      }

      if( ( *ppAPP )->pWindow )
      {
         SDL_DestroyWindow( ( *ppAPP )->pWindow );
      }
      hb_xfree( *ppAPP );
      *ppAPP = NULL;
   }

   Uint32 subsystems = SDL_WasInit( 0 );
   Uint32 sdlFlags[] =
   {
      SDL_INIT_AUDIO,
      SDL_INIT_VIDEO ,
      SDL_INIT_JOYSTICK,
      SDL_INIT_HAPTIC,
      SDL_INIT_GAMEPAD,
      SDL_INIT_EVENTS,
      SDL_INIT_SENSOR,
      SDL_INIT_CAMERA
   };

   for( size_t i = 0; i < sizeof( sdlFlags ) / sizeof( sdlFlags[ 0 ] ); i++ )
   {
      if( subsystems & sdlFlags[ i ] )
      {
         SDL_QuitSubSystem( sdlFlags[ i ] );
      }
   }

   TTF_Quit();
   SDL_Quit();
}

static const HB_GC_FUNCS s_gc_app_Funcs =
{
   hb_app_Destructor,
   hb_gcDummyMark
};

APP *hb_app_ParamPtr( int iParam )
{
   APP **ppAPP = ( APP ** ) hb_parptrGC( &s_gc_app_Funcs, iParam );

   if( ppAPP && *ppAPP )
   {
      return *ppAPP;
   }
   else
   {
      HB_ERR_ARGS();
      return NULL;
   }
}

APP *hb_app_ParamGet( int iParam )
{
   APP **ppAPP = ( APP ** ) hb_parptrGC( &s_gc_app_Funcs, iParam );

   return IIF( ppAPP, *ppAPP, NULL );
}

APP *hb_app_ItemGet( PHB_ITEM pItem )
{
   APP **ppAPP = ( APP ** ) hb_itemGetPtrGC( pItem, &s_gc_app_Funcs );

   return IIF( ppAPP, *ppAPP, NULL );
}

PHB_ITEM hb_app_ItemPut( PHB_ITEM pItem, APP *pAPP )
{
   APP **ppAPP = ( APP ** ) hb_gcAllocate( sizeof( APP * ), &s_gc_app_Funcs );

   *ppAPP = pAPP;
   return hb_itemPutPtrGC( pItem, ppAPP );
}

void hb_app_ItemClear( PHB_ITEM pItem )
{
   APP **ppAPP = ( APP ** ) hb_itemGetPtrGC( pItem, &s_gc_app_Funcs );

   if( ppAPP )
      *ppAPP = NULL;
}

void hb_app_Return( APP *pAPP )
{
   if( pAPP )
   {
      hb_app_ItemPut( hb_param( -1, HB_IT_ANY ), pAPP );
   }
   else
   {
      hb_ret();
   }
}

/* -------------------------------------------------------------------------
Structure APP
------------------------------------------------------------------------- */
// APP *AppUI( const char *title, int width, int height, SDL_Color bg )
HB_FUNC( APPUI )
{
   PHB_ITEM array;

   if( hb_param( 1, HB_IT_STRING ) != NULL && hb_param( 2, HB_IT_NUMERIC ) != NULL && hb_param( 3, HB_IT_NUMERIC ) != NULL &&
      ( array = hb_param( 4, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( array ) == 4 )
   {
      APP *app = hb_xgrab( sizeof( APP ) );
      if( !app )
      {
         fprintf( stderr, "Memory allocation failed for APP structure.\n" );
      }

      memset( app, 0, sizeof( APP ) );

      app->title  = hb_parc( 1 );
      app->width  = hb_parni( 2 );
      app->height = hb_parni( 3 );
      app->bg     = hb_sdl_color_param_array( array );

      SDL_SetHint( SDL_HINT_SHUTDOWN_DBUS_ON_QUIT, "1" );

      if( !SDL_Init( SDL_INIT_VIDEO ) )
      {
         fprintf( stderr, "Error initializing SDL: %s\n", SDL_GetError() );
         hb_ret();
      }

      if( !TTF_Init() )
      {
         fprintf( stderr, "Error initializing SDL_ttf: %s\n", SDL_GetError() );
         SDL_Quit();
         hb_ret();
      }

      app->pWindow = SDL_CreateWindow( app->title, app->width, app->height, SDL_WINDOW_RESIZABLE );
      if( app->pWindow == NULL )
      {
         fprintf( stderr, "Error creating SDL window: %s\n", SDL_GetError() );
         SDL_Quit();
         hb_ret();
      }

      app->pRenderer = SDL_CreateRenderer( app->pWindow, NULL );
      if( app->pRenderer == NULL )
      {
         fprintf( stderr, "Error creating SDL renderer: %s\n", SDL_GetError() );
         SDL_DestroyWindow( app->pWindow );
         SDL_Quit();
         hb_ret();
      }

      hb_app_Return( app );
   }
   else
   {
      HB_ERR_ARGS();
   }
}

// void AppExec( APP *app )
HB_FUNC( APPEXEC )
{
   SDL_Event event;

   if( hb_param( 1, HB_IT_POINTER ) != NULL )
   {
      APP *app = hb_app_ParamPtr( 1 );
      app->quit = F;

      while( !app->quit )
      {
         while( SDL_PollEvent( &event ) )
         {
            switch( event.type )
            {
               case SDL_EVENT_QUIT:
                  app->quit = T;
                  break;

               case SDL_EVENT_WINDOW_CLOSE_REQUESTED:
                  app->quit = T;
                  break;

               case SDL_EVENT_KEY_DOWN:
                  app_handle_key_events( app, &event );
                  break;

               case SDL_EVENT_MOUSE_BUTTON_DOWN:
                  app_handle_mouse_events( app, &event );
                  break;

               default:
                  break;
            }
         }

         SDL_SetRenderDrawColor( app->pRenderer, app->bg.r, app->bg.g, app->bg.b, app->bg.a );
         SDL_RenderClear( app->pRenderer );

         //---
         app_draw_components( app );
         //---

         SDL_RenderPresent( app->pRenderer );
     }
   }
   else
   {
      HB_ERR_ARGS();
   }
}

// void AppSetBGColor( APP *app, SDL_Color bg )
HB_FUNC( APPSETBGCOLOR )
{
   PHB_ITEM array;

   if( hb_param( 1, HB_IT_POINTER ) != NULL && ( array = hb_param( 2, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( array ) == 4 )
   {
      APP *app = hb_app_ParamPtr( 1 );
      app->bg = hb_sdl_color_param_array( array );
   }
   else
   {
      HB_ERR_ARGS();
   }
}

// void AppBindKey( APP *app, const char *key, void ( *onKeyPress ) ( void ) );
HB_FUNC( APPBINDKEY )
{
   if( hb_param( 1, HB_IT_POINTER ) != NULL && hb_param( 2, HB_IT_STRING ) != NULL && hb_param( 3, HB_IT_BLOCK ) != NULL )
   {
      APP *app = hb_app_ParamPtr( 1 );
      const char *key = hb_parc( 2 );
      PHB_ITEM block = hb_param( 3, HB_IT_BLOCK );

      if( app->keyBindings == NULL )
      {
         app->keyBindings = hb_hashNew( NULL );
      }

      hb_hashAdd( app->keyBindings, hb_itemPutC( NULL, key ), block );
   }
   else
   {
      HB_ERR_ARGS();
   }
}

HB_FUNC( APPQUIT )
{
   if( hb_param( 1, HB_IT_POINTER ) != NULL )
   {
      APP *app = hb_app_ParamPtr( 1 );
      app->quit = T;
   }
   else
   {
      HB_ERR_ARGS();
   }
}

/* -------------------------------------------------------------------------
Static APP
------------------------------------------------------------------------- */
static void app_add_box( APP *app, BoxUI *newBox )
{
   if( app->box == NULL )
   {
      app->box = newBox;
   }
   else
   {
      BoxUI *current = app->box;
      while( current->next != NULL )
      {
         current = current->next;
      }
      current->next = newBox;
   }
   app->componentCount++;
}

static void app_draw_components( APP *app )
{
   BoxUI *stack[ 100 ];
   int count = 0;

   BoxUI *current = app->box;

   while( current != NULL && count < 100 )
   {
      stack[ count++ ] = current;
      current = current->next;
   }

   for( int i = count - 1; i >= 0; i-- )
   {
      current = stack[ i ];
      SDL_SetRenderDrawColor( app->pRenderer, current->bg.r, current->bg.g, current->bg.b, current->bg.a );
      SDL_RenderFillRect( app->pRenderer, &current->rect );
   }
}

void AppRemoveBox( APP *app, BoxUI *boxToRemove )
{
   if( app->box == NULL )
      return;

   if( app->box == boxToRemove )
   {
      // Usuwamy pierwszy element
      app->box = app->box->next;
      hb_xfree( boxToRemove );
      app->componentCount--;
      return;
   }

   BoxUI *current = app->box;
   while( current->next && current->next != boxToRemove )
   {
      current = current->next;
   }

   if( current->next == boxToRemove )
   {
      current->next = boxToRemove->next;
      hb_xfree( boxToRemove );
      app->componentCount--;
   }
}

static void app_clear_components( APP *app )
{
   BoxUI *current = app->box;
   while( current != NULL )
   {
      BoxUI *next = current->next;
      hb_xfree( current );
      current = next;
   }
   app->box = NULL;
   app->componentCount = 0;
}

static void app_handle_key_events( APP *app, SDL_Event *event )
{
   if( event->type == SDL_EVENT_KEY_DOWN )
   {
      const char *key = SDL_GetScancodeName( event->key.scancode );
      // printf( "%s\n", key );
      if( app->keyBindings )
      {
         PHB_ITEM block = hb_hashGetCItemPtr( app->keyBindings, key );
         if( block && hb_vmRequestReenter() )
         {
            hb_vmEvalBlock( block );
            hb_vmRequestRestore();
         }
      }
   }
}

static bool app_ismouse_inside_box( int mouseX, int mouseY, SDL_FRect *rect )
{
   return mouseX >= rect->x && mouseX <= rect->x + rect->w && mouseY >= rect->y && mouseY <= rect->y + rect->h;
}

static void app_move_box_to_front( APP *app, BoxUI *box )
{
   if( app->box == box )
   {
      return;
   }

   BoxUI *current = app->box;
   BoxUI *previous = NULL;

   while( current != NULL && current != box )
   {
      previous = current;
      current = current->next;
   }

   if( current == NULL )
   {
      return;
   }

   if( previous != NULL )
   {
      previous->next = current->next;
   }

   current->next = app->box;
   app->box = current;
}

static void app_handle_mouse_events( APP *app, SDL_Event *event )
{
   if( event->type == SDL_EVENT_MOUSE_BUTTON_DOWN )
   {
      int mouseX = event->button.x;
      int mouseY = event->button.y;

      BoxUI *current = app->box;

      while( current != NULL )
      {
         if( app_ismouse_inside_box( mouseX, mouseY, &current->rect ) )
         {
            app_move_box_to_front( app, current );
            break;
         }
         current = current->next;
      }
   }
}

/* -------------------------------------------------------------------------
Structure BoxUI
------------------------------------------------------------------------- */
// void BoxUI( APP *app, const char *title, SDL_Rect rect, SDL_Color bg )
HB_FUNC( BOXUI )
{
   PHB_ITEM array1;
   PHB_ITEM array2;

   if( hb_param( 1, HB_IT_POINTER ) != NULL && hb_param( 2, HB_IT_STRING ) != NULL &&
     ( array1 = hb_param( 3, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( array1 ) == 4 &&
     ( array2 = hb_param( 4, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( array2 ) == 4 )
   {
      BoxUI *box = hb_xgrab( sizeof( BoxUI ) );
      if( !box )
      {
         fprintf( stderr, "Memory allocation failed for APP structure.\n" );
      }

      memset( box, 0, sizeof( BoxUI ) );

      APP *app   = hb_app_ParamPtr( 1 );
      box->title = hb_parc( 2 );
      box->rect  = hb_sdl_frect_param_array( array1 );
      box->bg    = hb_sdl_color_param_array( array2 );
      box->next  = NULL;

      app_add_box( app, box );
   }
   else
   {
      HB_ERR_ARGS();
   }
}
