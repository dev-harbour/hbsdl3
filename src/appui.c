/*
 * Copyright 2024 Rafał Jopek <https://harbour.pl>
 */

#include "hbsdl3.h"

typedef enum _ComponentType ComponentType;

enum _ComponentType
{
   BOX,
   BUTTON
};

typedef struct _APP APP;
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
};

struct _BoxUI
{
   const char *title;
   SDL_FRect   rect;
   SDL_Color   bg;
   BoxUI      *next;
};

static void AppAddBox( APP *app, BoxUI *newBox );
static void AppDrawComponents( APP *app );
static void AppClearComponents( APP *app );

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
         AppClearComponents( *ppAPP ); // Zwalniamy wszystkie BoxUI
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
// APP *App( const char *title, int width, int height, SDL_Color bg )
HB_FUNC( APP )
{
   PHB_ITEM pArray;

   if( hb_param( 1, HB_IT_STRING ) != NULL && hb_param( 2, HB_IT_NUMERIC ) != NULL && hb_param( 3, HB_IT_NUMERIC ) != NULL &&
      ( pArray = hb_param( 4, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pArray ) == 4 )
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
      app->bg     = hb_sdl_color_param_array( pArray );

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
   bool quit = F;
   SDL_Event event;

   if( hb_param( 1, HB_IT_POINTER ) != NULL )
   {
      APP *app = hb_app_ParamPtr( 1 );

      while( !quit )
      {
         while( SDL_PollEvent( &event ) )
         {
            switch( event.type )
            {
            case SDL_EVENT_QUIT:
               quit = T;
               break;
            case SDL_EVENT_WINDOW_CLOSE_REQUESTED:
               quit = T;
               break;
            }
         }

         SDL_SetRenderDrawColor( app->pRenderer, app->bg.r, app->bg.g, app->bg.b, app->bg.a );
         SDL_RenderClear( app->pRenderer );

         //---
         AppDrawComponents( app );
         //---

         SDL_RenderPresent( app->pRenderer );
     }
   }
   else
   {
      HB_ERR_ARGS();
   }
}

static void AppAddBox( APP *app, BoxUI *newBox )
{
   if( app->box == NULL )
   {
      app->box = newBox;
   }
   else
   {
      // Znajdź ostatni element
      BoxUI *current = app->box;
      while( current->next != NULL )
      {
         current = current->next;
      }
      current->next = newBox;  // Dodaj nowy element na końcu
   }
   app->componentCount++;
}

static void AppDrawComponents( APP *app )
{
   BoxUI *current = app->box;

   while( current != NULL )
   {
      SDL_SetRenderDrawColor( app->pRenderer, current->bg.r, current->bg.g, current->bg.b, current->bg.a );
      SDL_RenderFillRect( app->pRenderer, &current->rect );

      current = current->next;  // Przejdź do następnego elementu
   }
}

void AppRemoveBox( APP *app, BoxUI *boxToRemove )
{
   if( app->box == NULL ) // Lista jest pusta, nic do usunięcia
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

static void AppClearComponents( APP *app )
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

/* -------------------------------------------------------------------------
Structure BoxUI
------------------------------------------------------------------------- */
// void Box( APP *app, const char *title, SDL_Rect rect, SDL_Color bg )
HB_FUNC( BOX )
{
   PHB_ITEM pArray1;
   PHB_ITEM pArray2;

   if( hb_param( 1, HB_IT_POINTER ) != NULL && hb_param( 2, HB_IT_STRING ) != NULL &&
     ( pArray1 = hb_param( 3, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pArray1 ) == 4 &&
     ( pArray2 = hb_param( 4, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pArray2 ) == 4 )
   {
      BoxUI *box = hb_xgrab( sizeof( BoxUI ) );
      if( !box )
      {
         fprintf( stderr, "Memory allocation failed for APP structure.\n" );
      }

      memset( box, 0, sizeof( BoxUI ) );

      APP *app   = hb_app_ParamPtr( 1 );
      box->title = hb_parc( 2 );
      box->rect  = hb_sdl_frect_param_array( pArray1 );
      box->bg    = hb_sdl_color_param_array( pArray2 );
      box->next  = NULL;

      AppAddBox( app, box );  // Dodaj do listy komponentów w APP
   }
   else
   {
      HB_ERR_ARGS();
   }
}