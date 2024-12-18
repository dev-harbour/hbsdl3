/*
 * Copyright 2024 Rafał Jopek <https://harbour.pl>
 */

#include "hbsdl3.h"

/* -------------------------------------------------------------------------
Harbour Implementation Color
------------------------------------------------------------------------- */
SDL_Color hb_sdl_color_param_array( PHB_ITEM pArray )
{
   SDL_Color color;

   color.r = ( Uint8 ) hb_arrayGetNI( pArray, 1 );
   color.g = ( Uint8 ) hb_arrayGetNI( pArray, 2 );
   color.b = ( Uint8 ) hb_arrayGetNI( pArray, 3 );
   color.a = ( Uint8 ) hb_arrayGetNI( pArray, 4 );

   return color;
}

PHB_ITEM __attribute__( ( unused ) ) hb_sdl_color_return_array( const SDL_Color *color )
{
   PHB_ITEM pArray = hb_itemArrayNew( 4 );

   hb_arraySetNI( pArray, 1, color->r );
   hb_arraySetNI( pArray, 2, color->g );
   hb_arraySetNI( pArray, 3, color->b );
   hb_arraySetNI( pArray, 4, color->a );

   return pArray;
}

SDL_FColor __attribute__( ( unused ) ) hb_sdl_fcolor_param_array( PHB_ITEM pArray )
{
   SDL_FColor color;

   color.r = ( float ) hb_arrayGetND( pArray, 1 );
   color.g = ( float ) hb_arrayGetND( pArray, 2 );
   color.b = ( float ) hb_arrayGetND( pArray, 3 );
   color.a = ( float ) hb_arrayGetND( pArray, 4 );

   return color;
}

PHB_ITEM __attribute__( ( unused ) ) hb_sdl_fcolor_return_array( const SDL_FColor *fcolor )
{
   PHB_ITEM pArray = hb_itemArrayNew( 4 );

   hb_arraySetND( pArray, 1, fcolor->r );
   hb_arraySetND( pArray, 2, fcolor->g );
   hb_arraySetND( pArray, 3, fcolor->b );
   hb_arraySetND( pArray, 4, fcolor->a );

   return pArray;
}

/* -------------------------------------------------------------------------
Harbour Implementation SDL_Rect
------------------------------------------------------------------------- */
SDL_Rect hb_sdl_rect_param_array( PHB_ITEM pArray )
{
   SDL_Rect rect;

   rect.x = hb_arrayGetNI( pArray, 1 );
   rect.y = hb_arrayGetNI( pArray, 2 );
   rect.w = hb_arrayGetNI( pArray, 3 );
   rect.h = hb_arrayGetNI( pArray, 4 );

   return rect;
}

PHB_ITEM __attribute__( ( unused ) ) hb_sdl_rect_return_array( const SDL_Rect *rect )
{
   PHB_ITEM pArray = hb_itemArrayNew( 4 );

   hb_arraySetNI( pArray, 1, rect->x );
   hb_arraySetNI( pArray, 2, rect->y );
   hb_arraySetNI( pArray, 3, rect->w );
   hb_arraySetNI( pArray, 4, rect->h );

   return pArray;
}

/* -------------------------------------------------------------------------
Harbour Implementation SDL_FRect
------------------------------------------------------------------------- */
SDL_FRect hb_sdl_frect_param_array( PHB_ITEM pArray )
{
   SDL_FRect frect;

   frect.x = ( float ) hb_arrayGetND( pArray, 1 );
   frect.y = ( float ) hb_arrayGetND( pArray, 2 );
   frect.w = ( float ) hb_arrayGetND( pArray, 3 );
   frect.h = ( float ) hb_arrayGetND( pArray, 4 );

   return frect;
}

PHB_ITEM __attribute__( ( unused ) ) hb_sdl_frect_return_array( const SDL_FRect *frect )
{
   PHB_ITEM pArray = hb_itemArrayNew( 4 );

   hb_arraySetND( pArray, 1, frect->x );
   hb_arraySetND( pArray, 2, frect->y );
   hb_arraySetND( pArray, 3, frect->w );
   hb_arraySetND( pArray, 4, frect->h );

   return pArray;
}

/* -------------------------------------------------------------------------
Harbour Implementation SDL_Event
------------------------------------------------------------------------- */
// int EventType( SDL_Event *pEvent ); /**< SDL_EVENT_KEY_DOWN or SDL_EVENT_KEY_UP */
HB_FUNC( EVENTTYPE )
{
   if( hb_param( 1, HB_IT_POINTER ) != NULL )
   {
      SDL_Event *pEvent = hb_sdl_event_ParamPtr( 1 );

      hb_retni( pEvent->type );
   }
   else
   {
      HB_ERR_ARGS();
   }
}

/* SDL_KeyboardEvent */
// Uint32 EventKeyReserved( SDL_Event *pEvent );
HB_FUNC( EVENTKEYRESERVED )
{
   if( hb_param( 1, HB_IT_POINTER ) != NULL )
   {
      SDL_Event *pEvent = hb_sdl_event_ParamPtr( 1 );
      hb_retni( pEvent->key.reserved );
   }
   else
   {
      HB_ERR_ARGS();
   }
}

// Uint64 EventKeyTimestamp( SDL_Event *pEvent ); /**< In nanoseconds, populated using SDL_GetTicksNS() */
HB_FUNC( EVENTKEYTIMESTAMP )
{
   if( hb_param( 1, HB_IT_POINTER ) != NULL )
   {
      SDL_Event *pEvent = hb_sdl_event_ParamPtr( 1 );
      hb_retnint( pEvent->key.timestamp ); // Zwracanie 64-bitowej wartości
   }
   else
   {
      HB_ERR_ARGS();
   }
}

// int EventKeyWindowID( SDL_Event *pEvent ); /**< The window with keyboard focus, if any */
HB_FUNC( EVENTKEYWINDOWID )
{
   if( hb_param( 1, HB_IT_POINTER ) != NULL )
   {
      SDL_Event *pEvent = hb_sdl_event_ParamPtr( 1 );
      hb_retni( pEvent->key.windowID );
   }
   else
   {
      HB_ERR_ARGS();
   }
}

// int EventKeyWhich( SDL_Event *pEvent ); /**< The keyboard instance id, or 0 if unknown or virtual */
HB_FUNC( EVENTKEYWHICH )
{
   if( hb_param( 1, HB_IT_POINTER ) != NULL )
   {
      SDL_Event *pEvent = hb_sdl_event_ParamPtr( 1 );
      hb_retni( pEvent->key.which );
   }
   else
   {
      HB_ERR_ARGS();
   }
}

// int EventKeyScancode( SDL_Event *pEvent );
HB_FUNC( EVENTKEYSCANCODE )
{
   if( hb_param( 1, HB_IT_POINTER ) != NULL )
   {
      SDL_Event *pEvent = hb_sdl_event_ParamPtr( 1 );
      hb_retni( pEvent->key.scancode );
   }
   else
   {
      HB_ERR_ARGS();
   }
}

// int EventKeyKey( SDL_Event *pEvent ); /**< SDL virtual key code */
HB_FUNC( EVENTKEYKEY )
{
   if( hb_param( 1, HB_IT_POINTER ) != NULL )
   {
      SDL_Event *pEvent = hb_sdl_event_ParamPtr( 1 );
      hb_retni( pEvent->key.key );
   }
   else
   {
      HB_ERR_ARGS();
   }
}

// int EventKeyMod( SDL_Event *pEvent ); /**< current key modifiers */
HB_FUNC( EVENTKEYMOD )
{
   if( hb_param( 1, HB_IT_POINTER ) != NULL )
   {
      SDL_Event *pEvent = hb_sdl_event_ParamPtr( 1 );
      hb_retni( pEvent->key.mod );
   }
   else
   {
      HB_ERR_ARGS();
   }
}

// Uint16 EventKeyRaw( SDL_Event *pEvent ); /**< The platform dependent scancode for this event */
HB_FUNC( EVENTKEYRAW )
{
   if( hb_param( 1, HB_IT_POINTER ) != NULL )
   {
      SDL_Event *pEvent = hb_sdl_event_ParamPtr( 1 );

      hb_retni( pEvent->key.raw );
   }
   else
   {
      HB_ERR_ARGS();
   }
}

// bool EventKeyDown( SDL_Event *pEvent ); /**< true if the key is pressed */
HB_FUNC( EVENTKEYDOWN )
{
   if( hb_param( 1, HB_IT_POINTER ) != NULL )
   {
      SDL_Event *pEvent = hb_sdl_event_ParamPtr( 1 );
      hb_retl( pEvent->key.down );
   }
   else
   {
      HB_ERR_ARGS();
   }
}

// bool EventKeyRepeat( SDL_Event *pEvent ); /**< true if this is a key repeat */
HB_FUNC( EVENTKEYREPEAT )
{
   if( hb_param( 1, HB_IT_POINTER ) != NULL )
   {
      SDL_Event *pEvent = hb_sdl_event_ParamPtr( 1 );
      hb_retl( pEvent->key.repeat );
   }
   else
   {
      HB_ERR_ARGS();
   }
}
/* End SDL_KeyboardEvent */

/* -------------------------------------------------------------------------
Harbour Implementation SDL3_ttf
------------------------------------------------------------------------- */
static size_t utf8Len( const char *szUtf8String )
{
   size_t len = 0;
   while( *szUtf8String )
   {
      unsigned char byte = *szUtf8String;

      if( ( byte & 0x80 ) == 0 )         // ASCII (0xxxxxxx)
         szUtf8String += 1;
      else if( ( byte & 0xE0 ) == 0xC0 ) // (110xxxxx)
         szUtf8String += 2;
      else if( ( byte & 0xF0 ) == 0xE0 ) // (1110xxxx)
         szUtf8String += 3;
      else if( ( byte & 0xF8 ) == 0xF0 ) // (11110xxx)
         szUtf8String += 4;
      else
         szUtf8String += 1;

      len++;
   }

   return len;
}

static void calculateFontCellSize( TTF_Font *pFont, int *fontCellWidth, int *fontCellHeight )
{
   const char *szTestChar = "M";
   int measuredWidth = 0;
   size_t measuredLength = 0;

   TTF_MeasureString( pFont, szTestChar, 0, 0, &measuredWidth, &measuredLength );

   *fontCellWidth = measuredWidth;
   *fontCellHeight = TTF_GetFontHeight( pFont );
}

// void drawText( TTF_Font *pFont, SDL_Renderer *pRenderer, int x, int y, const char *szText, SDL_Color fg, SDL_Color bg )
HB_FUNC( DRAWTEXT )
{
   PHB_ITEM pArray1;
   PHB_ITEM pArray2;

   if( hb_param( 1, HB_IT_POINTER ) != NULL &&
       hb_param( 2, HB_IT_POINTER ) != NULL &&
       hb_param( 3, HB_IT_NUMERIC ) != NULL &&
       hb_param( 4, HB_IT_NUMERIC ) != NULL &&
       hb_param( 5, HB_IT_STRING ) != NULL &&
       ( pArray1 = hb_param( 6, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pArray1 ) == 4 &&
       ( pArray2 = hb_param( 7, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pArray2 ) == 4 )
   {
      TTF_Font *pFont = hb_ttf_font_ParamPtr( 1 );
      SDL_Renderer *pRenderer = hb_sdl_renderer_ParamPtr( 2 );

      int x = hb_parni( 3 );
      int y = hb_parni( 4 );
      const char *szText = hb_parc( 5 );
      SDL_Color fg = hb_sdl_color_param_array( pArray1 );
      SDL_Color bg = hb_sdl_color_param_array( pArray2 );

      int fontCellWidth, fontCellHeight;

      calculateFontCellSize( pFont, &fontCellWidth, &fontCellHeight );

      x *= fontCellWidth;
      y *= fontCellHeight;

      size_t len = utf8Len( szText );
      if( len == 0 )
      {
         SDL_FRect rect = { x, y, ( float ) fontCellWidth, ( float ) fontCellHeight };
         SDL_SetRenderDrawColor( pRenderer, bg.r, bg.g, bg.b, bg.a );
         SDL_RenderFillRect( pRenderer, &rect );
         return;
      }

      SDL_Surface *pSurface = TTF_RenderText_Shaded( pFont, szText, 0, fg, bg );
      if( pSurface )
      {
         SDL_Texture *pTextTexture = SDL_CreateTextureFromSurface( pRenderer, pSurface );
         SDL_DestroySurface( pSurface );

         if( pTextTexture )
         {
            SDL_FRect textRect = { x, y, ( float ) fontCellWidth * len, ( float ) fontCellHeight };
            SDL_RenderTexture( pRenderer, pTextTexture, NULL, &textRect );
            SDL_DestroyTexture( pTextTexture );
         }
         else
         {
            fprintf( stderr, "Error creating texture: %s\n", SDL_GetError() );
         }
      }
      else
      {
         fprintf( stderr, "Error rendering text: %s\n", SDL_GetError() );
      }
   }
   else
   {
      HB_ERR_ARGS();
   }
}
