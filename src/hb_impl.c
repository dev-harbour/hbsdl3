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

/*
 * SDL_KeyboardEvent
 */
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
// void drawText( TTF_Font *pFont, SDL_Renderer *pRenderer, float x, float y, const char *text, SDL_Color fg, SDL_Color bg )
HB_FUNC( SDLDRAWTEXT )
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

      float x = ( float ) hb_parnd( 3 );
      float y = ( float ) hb_parnd( 4 );
      const char *text = hb_parc( 5 );
      SDL_Color fg = hb_sdl_color_param_array( pArray1 );
      SDL_Color bg = hb_sdl_color_param_array( pArray2 );

      int textWidth = 0;
      size_t textLength = strlen( text );

      TTF_MeasureString( pFont, text, textLength, 0, &textWidth, NULL );

      float fontCellWidth = ( float ) textWidth / textLength;
      float fontCellHeight = ( float ) TTF_GetFontLineSkip( pFont );

      x = x * fontCellWidth;
      y = y * fontCellHeight;

      SDL_Surface *pSurface = TTF_RenderText_Shaded( pFont, text, textLength, fg, bg );
      if( pSurface )
      {
         SDL_Texture *textTexture = SDL_CreateTextureFromSurface( pRenderer, pSurface );
         SDL_DestroySurface( pSurface );

         if( textTexture )
         {
            SDL_FRect textRect = { x, y, ( float ) textWidth, fontCellHeight };
            SDL_RenderTexture( pRenderer, textTexture, NULL, &textRect );
            SDL_DestroyTexture( textTexture );
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
