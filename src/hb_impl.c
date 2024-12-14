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
