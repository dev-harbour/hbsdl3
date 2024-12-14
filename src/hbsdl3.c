/*
 * Copyright 2024 Rafał Jopek <https://harbour.pl>
 */

#include "hbsdl3.h"

/* -------------------------------------------------------------------------
Garbage Collector SDL_Window
------------------------------------------------------------------------- */
static HB_GARBAGE_FUNC( hb_sdl_window_Destructor )
{
   SDL_Window **ppSDL_Window = ( SDL_Window ** ) Cargo;

   if( ppSDL_Window && *ppSDL_Window )
   {
      SDL_DestroyWindow( *ppSDL_Window );
      *ppSDL_Window = NULL;
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

   SDL_Quit();
}

static const HB_GC_FUNCS s_gc_sdl_window_Funcs =
{
   hb_sdl_window_Destructor,
   hb_gcDummyMark
};

SDL_Window *hb_sdl_window_ParamPtr( int iParam )
{
   SDL_Window **ppSDL_Window = ( SDL_Window ** ) hb_parptrGC( &s_gc_sdl_window_Funcs, iParam );

   if( ppSDL_Window && *ppSDL_Window )
   {
      return *ppSDL_Window;
   }
   else
   {
      HB_ERR_ARGS();
      return NULL;
   }
}

SDL_Window *hb_sdl_window_ParamGet( int iParam )
{
   SDL_Window **ppSDL_Window = ( SDL_Window ** ) hb_parptrGC( &s_gc_sdl_window_Funcs, iParam );

   return IIF( ppSDL_Window, *ppSDL_Window, NULL );
}

SDL_Window *hb_sdl_window_ItemGet( PHB_ITEM pItem )
{
   SDL_Window **ppSDL_Window = ( SDL_Window ** ) hb_itemGetPtrGC( pItem, &s_gc_sdl_window_Funcs );

   return IIF( ppSDL_Window, *ppSDL_Window, NULL );
}

PHB_ITEM hb_sdl_window_ItemPut( PHB_ITEM pItem, SDL_Window *pSDL_Window )
{
   SDL_Window **ppSDL_Window = ( SDL_Window ** ) hb_gcAllocate( sizeof( SDL_Window * ), &s_gc_sdl_window_Funcs );

   *ppSDL_Window = pSDL_Window;
   return hb_itemPutPtrGC( pItem, ppSDL_Window );
}

void hb_sdl_window_ItemClear( PHB_ITEM pItem )
{
   SDL_Window **ppSDL_Window = ( SDL_Window ** ) hb_itemGetPtrGC( pItem, &s_gc_sdl_window_Funcs );

   if( ppSDL_Window )
      *ppSDL_Window = NULL;
}

void hb_sdl_window_Return( SDL_Window *pSDL_Window )
{
   if( pSDL_Window )
   {
      hb_sdl_window_ItemPut( hb_param( -1, HB_IT_ANY ), pSDL_Window );
   }
   else
   {
      hb_ret();
   }
}

/* -------------------------------------------------------------------------
Garbage Collector SDL_Renderer
------------------------------------------------------------------------- */
static HB_GARBAGE_FUNC( hb_sdl_renderer_Destructor )
{
   SDL_Renderer **ppSDL_Renderer = ( SDL_Renderer ** ) Cargo;

   if( ppSDL_Renderer && *ppSDL_Renderer )
   {
      SDL_DestroyRenderer( *ppSDL_Renderer );

      *ppSDL_Renderer = NULL;
   }
}

static const HB_GC_FUNCS s_gc_sdl_renderer_Funcs =
{
   hb_sdl_renderer_Destructor,
   hb_gcDummyMark
};

SDL_Renderer *hb_sdl_renderer_ParamPtr( int iParam )
{
   SDL_Renderer **ppSDL_Renderer = ( SDL_Renderer ** ) hb_parptrGC( &s_gc_sdl_renderer_Funcs, iParam );

   if( ppSDL_Renderer && *ppSDL_Renderer )
   {
      return *ppSDL_Renderer;
   }
   else
   {
      HB_ERR_ARGS();
      return NULL;
   }
}

SDL_Renderer *hb_sdl_renderer_ParamGet( int iParam )
{
   SDL_Renderer **ppSDL_Renderer = ( SDL_Renderer ** ) hb_parptrGC( &s_gc_sdl_renderer_Funcs, iParam );

   return IIF( ppSDL_Renderer, *ppSDL_Renderer, NULL );
}

SDL_Renderer *hb_sdl_renderer_ItemGet( PHB_ITEM pItem )
{
   SDL_Renderer **ppSDL_Renderer = ( SDL_Renderer ** ) hb_itemGetPtrGC( pItem, &s_gc_sdl_renderer_Funcs );

   return IIF( ppSDL_Renderer, *ppSDL_Renderer, NULL );
}

PHB_ITEM hb_sdl_renderer_ItemPut( PHB_ITEM pItem, SDL_Renderer *pSDL_Renderer )
{
   SDL_Renderer **ppSDL_Renderer = ( SDL_Renderer ** ) hb_gcAllocate( sizeof( SDL_Renderer * ), &s_gc_sdl_renderer_Funcs );

   *ppSDL_Renderer = pSDL_Renderer;
   return hb_itemPutPtrGC( pItem, ppSDL_Renderer );
}

void hb_sdl_renderer_ItemClear( PHB_ITEM pItem )
{
   SDL_Renderer **ppSDL_Renderer = ( SDL_Renderer ** ) hb_itemGetPtrGC( pItem, &s_gc_sdl_renderer_Funcs );

   if( ppSDL_Renderer )
      *ppSDL_Renderer = NULL;
}

void hb_sdl_renderer_Return( SDL_Renderer *pSDL_Renderer )
{
   if( pSDL_Renderer )
   {
      hb_sdl_renderer_ItemPut( hb_param( -1, HB_IT_ANY ), pSDL_Renderer );
   }
   else
   {
      hb_ret();
   }
}

/* -------------------------------------------------------------------------
Garbage Collector SDL_Event
------------------------------------------------------------------------- */
static HB_GARBAGE_FUNC( hb_sdl_event_Destructor )
{
   SDL_Event **ppEvent = ( SDL_Event ** ) Cargo;

   if( ppEvent && *ppEvent )
   {
      hb_xfree( *ppEvent );

      *ppEvent = NULL;
   }
}

static const HB_GC_FUNCS s_gc_sdl_event_Funcs =
{
   hb_sdl_event_Destructor,
   hb_gcDummyMark
};

SDL_Event *hb_sdl_event_ParamPtr( int iParam )
{
   SDL_Event **ppSDL_Event = ( SDL_Event ** ) hb_parptrGC( &s_gc_sdl_event_Funcs, iParam );

   if( ppSDL_Event && *ppSDL_Event )
      return *ppSDL_Event;

   HB_ERR_ARGS();
   return NULL;
}

SDL_Event *hb_sdl_event_ParamGet( int iParam )
{
   SDL_Event **ppSDL_Event = ( SDL_Event ** ) hb_parptrGC( &s_gc_sdl_event_Funcs, iParam );

   return ppSDL_Event ? *ppSDL_Event : NULL;
}

SDL_Event *hb_sdl_event_ItemGet( PHB_ITEM pItem )
{
   SDL_Event **ppSDL_Event = ( SDL_Event ** ) hb_itemGetPtrGC( pItem, &s_gc_sdl_event_Funcs );

   return ppSDL_Event ? *ppSDL_Event : NULL;
}

PHB_ITEM hb_sdl_event_ItemPut( PHB_ITEM pItem, SDL_Event *pSDL_Event )
{
   SDL_Event **ppSDL_Event = ( SDL_Event ** ) hb_gcAllocate( sizeof( SDL_Event * ), &s_gc_sdl_event_Funcs );

   *ppSDL_Event = pSDL_Event;
   return hb_itemPutPtrGC( pItem, ppSDL_Event );
}

void hb_sdl_event_ItemClear( PHB_ITEM pItem )
{
   SDL_Event **ppSDL_Event = ( SDL_Event ** ) hb_itemGetPtrGC( pItem, &s_gc_sdl_event_Funcs );

   if( ppSDL_Event )
      *ppSDL_Event = NULL;
}

void hb_sdl_event_StorPtr( SDL_Event *pSDL_Event, int iParam )
{
   SDL_Event **ppSDL_Event = ( SDL_Event ** ) hb_gcAllocate( sizeof( SDL_Event * ), &s_gc_sdl_event_Funcs );

   *ppSDL_Event = pSDL_Event;
   hb_storptrGC( ppSDL_Event, iParam );
}

void hb_sdl_event_Return( SDL_Event *pSDL_Event )
{
   if( pSDL_Event )
      hb_sdl_event_ItemPut( hb_param( -1, HB_IT_ANY ), pSDL_Event );
   else
      hb_ret();
}

/* -------------------------------------------------------------------------
Garbage Collector SDL_Surface
------------------------------------------------------------------------- */
static HB_GARBAGE_FUNC( hb_sdl_surface_Destructor )
{
   SDL_Surface **ppSDL_Surface = ( SDL_Surface ** ) Cargo;

   if( ppSDL_Surface && *ppSDL_Surface )
   {
      SDL_DestroySurface( *ppSDL_Surface );
      *ppSDL_Surface = NULL;
   }
}

static const HB_GC_FUNCS s_gc_sdl_surface_Funcs =
{
   hb_sdl_surface_Destructor,
   hb_gcDummyMark
};

SDL_Surface *hb_sdl_surface_ParamPtr( int iParam )
{
   SDL_Surface **ppSDL_Surface = ( SDL_Surface ** ) hb_parptrGC( &s_gc_sdl_surface_Funcs, iParam );

   if( ppSDL_Surface && *ppSDL_Surface )
   {
      return *ppSDL_Surface;
   }
   else
   {
      HB_ERR_ARGS();
      return NULL;
   }
}

SDL_Surface *hb_sdl_surface_ParamGet( int iParam )
{
   SDL_Surface **ppSDL_Surface = ( SDL_Surface ** ) hb_parptrGC( &s_gc_sdl_surface_Funcs, iParam );

   return IIF( ppSDL_Surface, *ppSDL_Surface, NULL );
}

SDL_Surface *hb_sdl_surface_ItemGet( PHB_ITEM pItem )
{
   SDL_Surface **ppSDL_Surface = ( SDL_Surface ** ) hb_itemGetPtrGC( pItem, &s_gc_sdl_surface_Funcs );

   return IIF( ppSDL_Surface, *ppSDL_Surface, NULL );
}

PHB_ITEM hb_sdl_surface_ItemPut( PHB_ITEM pItem, SDL_Surface *pSDL_Surface )
{
   SDL_Surface **ppSDL_Surface = ( SDL_Surface ** ) hb_gcAllocate( sizeof( SDL_Surface * ), &s_gc_sdl_surface_Funcs );

   *ppSDL_Surface = pSDL_Surface;
   return hb_itemPutPtrGC( pItem, ppSDL_Surface );
}

void hb_sdl_surface_ItemClear( PHB_ITEM pItem )
{
   SDL_Surface **ppSDL_Surface = ( SDL_Surface ** ) hb_itemGetPtrGC( pItem, &s_gc_sdl_surface_Funcs );

   if( ppSDL_Surface )
      *ppSDL_Surface = NULL;
}

void hb_sdl_surface_Return( SDL_Surface *pSDL_Surface )
{
   if( pSDL_Surface )
   {
      hb_sdl_surface_ItemPut( hb_param( -1, HB_IT_ANY ), pSDL_Surface );
   }
   else
   {
      hb_ret();
   }
}

/* -------------------------------------------------------------------------
Garbage Collector SDL_Texture
------------------------------------------------------------------------- */
static HB_GARBAGE_FUNC( hb_sdl_texture_Destructor )
{
   SDL_Texture **ppSDL_Texture = ( SDL_Texture ** ) Cargo;

   if( ppSDL_Texture && *ppSDL_Texture )
   {
      SDL_DestroyTexture( *ppSDL_Texture );
      *ppSDL_Texture = NULL;
   }
}

static const HB_GC_FUNCS s_gc_sdl_texture_Funcs =
{
   hb_sdl_texture_Destructor,
   hb_gcDummyMark
};

SDL_Texture *hb_sdl_texture_ParamPtr( int iParam )
{
   SDL_Texture **ppSDL_Texture = ( SDL_Texture ** ) hb_parptrGC( &s_gc_sdl_texture_Funcs, iParam );

   if( ppSDL_Texture && *ppSDL_Texture )
   {
      return *ppSDL_Texture;
   }
   else
   {
      HB_ERR_ARGS();
      return NULL;
   }
}

SDL_Texture *hb_sdl_texture_ParamGet( int iParam )
{
   SDL_Texture **ppSDL_Texture = ( SDL_Texture ** ) hb_parptrGC( &s_gc_sdl_texture_Funcs, iParam );

   return IIF( ppSDL_Texture, *ppSDL_Texture, NULL );
}

SDL_Texture *hb_sdl_texture_ItemGet( PHB_ITEM pItem )
{
   SDL_Texture **ppSDL_Texture = ( SDL_Texture ** ) hb_itemGetPtrGC( pItem, &s_gc_sdl_texture_Funcs );

   return IIF( ppSDL_Texture, *ppSDL_Texture, NULL );
}

PHB_ITEM hb_sdl_texture_ItemPut( PHB_ITEM pItem, SDL_Texture *pSDL_Texture )
{
   SDL_Texture **ppSDL_Texture = ( SDL_Texture ** ) hb_gcAllocate( sizeof( SDL_Texture * ), &s_gc_sdl_texture_Funcs );

   *ppSDL_Texture = pSDL_Texture;
   return hb_itemPutPtrGC( pItem, ppSDL_Texture );
}

void hb_sdl_texture_ItemClear( PHB_ITEM pItem )
{
   SDL_Texture **ppSDL_Texture = ( SDL_Texture ** ) hb_itemGetPtrGC( pItem, &s_gc_sdl_texture_Funcs );

   if( ppSDL_Texture )
      *ppSDL_Texture = NULL;
}

void hb_sdl_texture_Return( SDL_Texture *pSDL_Texture )
{
   if( pSDL_Texture )
   {
      hb_sdl_texture_ItemPut( hb_param( -1, HB_IT_ANY ), pSDL_Texture );
   }
   else
   {
      hb_ret();
   }
}

/* -------------------------------------------------------------------------
Harbour Implementation Color
------------------------------------------------------------------------- */
static SDL_Color hb_sdl_color_param_array( PHB_ITEM pArray )
{
   SDL_Color color;

   color.r = ( Uint8 ) hb_arrayGetNI( pArray, 1 );
   color.g = ( Uint8 ) hb_arrayGetNI( pArray, 2 );
   color.b = ( Uint8 ) hb_arrayGetNI( pArray, 3 );
   color.a = ( Uint8 ) hb_arrayGetNI( pArray, 4 );

   return color;
}

static PHB_ITEM __attribute__( ( unused ) ) hb_sdl_color_return_array( const SDL_Color *color )
{
   PHB_ITEM pArray = hb_itemArrayNew( 4 );

   hb_arraySetNI( pArray, 1, color->r );
   hb_arraySetNI( pArray, 2, color->g );
   hb_arraySetNI( pArray, 3, color->b );
   hb_arraySetNI( pArray, 4, color->a );

   return pArray;
}

static SDL_FColor __attribute__( ( unused ) ) hb_sdl_fcolor_param_array( PHB_ITEM pArray )
{
   SDL_FColor color;

   color.r = ( float ) hb_arrayGetND( pArray, 1 );
   color.g = ( float ) hb_arrayGetND( pArray, 2 );
   color.b = ( float ) hb_arrayGetND( pArray, 3 );
   color.a = ( float ) hb_arrayGetND( pArray, 4 );

   return color;
}

static PHB_ITEM __attribute__( ( unused ) ) hb_sdl_fcolor_return_array( const SDL_FColor *fcolor )
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
SDL3 API 2.30.10
------------------------------------------------------------------------- */
HB_FUNC( SDL_ACOS )
{

}

HB_FUNC( SDL_ACOSF )
{

}

HB_FUNC( SDL_ACQUIRECAMERAFRAME )
{

}

HB_FUNC( SDL_ACQUIREGPUCOMMANDBUFFER )
{

}

HB_FUNC( SDL_ACQUIREGPUSWAPCHAINTEXTURE )
{

}

HB_FUNC( SDL_ADDATOMICINT )
{

}

HB_FUNC( SDL_ADDEVENTWATCH )
{

}

HB_FUNC( SDL_ADDGAMEPADMAPPING )
{

}

HB_FUNC( SDL_ADDGAMEPADMAPPINGSFROMFILE )
{

}

HB_FUNC( SDL_ADDGAMEPADMAPPINGSFROMIO )
{

}

HB_FUNC( SDL_ADDHINTCALLBACK )
{

}

HB_FUNC( SDL_ADDSURFACEALTERNATEIMAGE )
{

}

HB_FUNC( SDL_ADDTIMER )
{

}

HB_FUNC( SDL_ADDTIMERNS )
{

}

HB_FUNC( SDL_ADDVULKANRENDERSEMAPHORES )
{

}

HB_FUNC( SDL_ALIGNED_ALLOC )
{

}

HB_FUNC( SDL_ALIGNED_FREE )
{

}

HB_FUNC( SDL_APPEVENT )
{

}

HB_FUNC( SDL_APPINIT )
{

}

HB_FUNC( SDL_APPITERATE )
{

}

HB_FUNC( SDL_APPQUIT )
{

}

HB_FUNC( SDL_ASIN )
{

}

HB_FUNC( SDL_ASINF )
{

}

HB_FUNC( SDL_ASYNCIOFROMFILE )
{

}

HB_FUNC( SDL_ATAN )
{

}

HB_FUNC( SDL_ATAN2 )
{

}

HB_FUNC( SDL_ATAN2F )
{

}

HB_FUNC( SDL_ATANF )
{

}

HB_FUNC( SDL_ATOF )
{

}

HB_FUNC( SDL_ATOI )
{

}

HB_FUNC( SDL_ATTACHVIRTUALJOYSTICK )
{

}

HB_FUNC( SDL_AUDIODEVICEPAUSED )
{

}

HB_FUNC( SDL_BEGINGPUCOMPUTEPASS )
{

}

HB_FUNC( SDL_BEGINGPUCOPYPASS )
{

}

HB_FUNC( SDL_BEGINGPURENDERPASS )
{

}

HB_FUNC( SDL_BINDAUDIOSTREAM )
{

}

HB_FUNC( SDL_BINDAUDIOSTREAMS )
{

}

HB_FUNC( SDL_BINDGPUCOMPUTEPIPELINE )
{

}

HB_FUNC( SDL_BINDGPUCOMPUTESAMPLERS )
{

}

HB_FUNC( SDL_BINDGPUCOMPUTESTORAGEBUFFERS )
{

}

HB_FUNC( SDL_BINDGPUCOMPUTESTORAGETEXTURES )
{

}

HB_FUNC( SDL_BINDGPUFRAGMENTSAMPLERS )
{

}

HB_FUNC( SDL_BINDGPUFRAGMENTSTORAGEBUFFERS )
{

}

HB_FUNC( SDL_BINDGPUFRAGMENTSTORAGETEXTURES )
{

}

HB_FUNC( SDL_BINDGPUGRAPHICSPIPELINE )
{

}

HB_FUNC( SDL_BINDGPUINDEXBUFFER )
{

}

HB_FUNC( SDL_BINDGPUVERTEXBUFFERS )
{

}

HB_FUNC( SDL_BINDGPUVERTEXSAMPLERS )
{

}

HB_FUNC( SDL_BINDGPUVERTEXSTORAGEBUFFERS )
{

}

HB_FUNC( SDL_BINDGPUVERTEXSTORAGETEXTURES )
{

}

HB_FUNC( SDL_BLITGPUTEXTURE )
{

}

HB_FUNC( SDL_BLITSURFACE )
{

}

HB_FUNC( SDL_BLITSURFACE9GRID )
{

}

HB_FUNC( SDL_BLITSURFACESCALED )
{

}

HB_FUNC( SDL_BLITSURFACETILED )
{

}

HB_FUNC( SDL_BLITSURFACETILEDWITHSCALE )
{

}

HB_FUNC( SDL_BLITSURFACEUNCHECKED )
{

}

HB_FUNC( SDL_BLITSURFACEUNCHECKEDSCALED )
{

}

HB_FUNC( SDL_BROADCASTCONDITION )
{

}

HB_FUNC( SDL_BSEARCH )
{

}

HB_FUNC( SDL_BSEARCH_R )
{

}

HB_FUNC( SDL_CALCULATEGPUTEXTUREFORMATSIZE )
{

}

HB_FUNC( SDL_CALLOC )
{

}

HB_FUNC( SDL_CANCELGPUCOMMANDBUFFER )
{

}

HB_FUNC( SDL_CAPTUREMOUSE )
{

}

HB_FUNC( SDL_CEIL )
{

}

HB_FUNC( SDL_CEILF )
{

}

HB_FUNC( SDL_CLAIMWINDOWFORGPUDEVICE )
{

}

HB_FUNC( SDL_CLEANUPTLS )
{

}

HB_FUNC( SDL_CLEARAUDIOSTREAM )
{

}

HB_FUNC( SDL_CLEARCLIPBOARDDATA )
{

}

HB_FUNC( SDL_CLEARCOMPOSITION )
{

}

HB_FUNC( SDL_CLEARERROR )
{

}

HB_FUNC( SDL_CLEARPROPERTY )
{

}

HB_FUNC( SDL_CLEARSURFACE )
{

}

HB_FUNC( SDL_CLOSEASYNCIO )
{

}

HB_FUNC( SDL_CLOSEAUDIODEVICE )
{

}

HB_FUNC( SDL_CLOSECAMERA )
{

}

HB_FUNC( SDL_CLOSEGAMEPAD )
{

}

HB_FUNC( SDL_CLOSEHAPTIC )
{

}

HB_FUNC( SDL_CLOSEIO )
{

}

HB_FUNC( SDL_CLOSEJOYSTICK )
{

}

HB_FUNC( SDL_CLOSESENSOR )
{

}

HB_FUNC( SDL_CLOSESTORAGE )
{

}

HB_FUNC( SDL_COMPAREANDSWAPATOMICINT )
{

}

HB_FUNC( SDL_COMPAREANDSWAPATOMICPOINTER )
{

}

HB_FUNC( SDL_COMPAREANDSWAPATOMICU32 )
{

}

HB_FUNC( SDL_COMPOSECUSTOMBLENDMODE )
{

}

HB_FUNC( SDL_CONVERTAUDIOSAMPLES )
{

}

HB_FUNC( SDL_CONVERTEVENTTORENDERCOORDINATES )
{

}

HB_FUNC( SDL_CONVERTPIXELS )
{

}

HB_FUNC( SDL_CONVERTPIXELSANDCOLORSPACE )
{

}

HB_FUNC( SDL_CONVERTSURFACE )
{

}

HB_FUNC( SDL_CONVERTSURFACEANDCOLORSPACE )
{

}

HB_FUNC( SDL_COPYFILE )
{

}

HB_FUNC( SDL_COPYGPUBUFFERTOBUFFER )
{

}

HB_FUNC( SDL_COPYGPUTEXTURETOTEXTURE )
{

}

HB_FUNC( SDL_COPYPROPERTIES )
{

}

HB_FUNC( SDL_COPYSIGN )
{

}

HB_FUNC( SDL_COPYSIGNF )
{

}

HB_FUNC( SDL_COPYSTORAGEFILE )
{

}

HB_FUNC( SDL_COS )
{

}

HB_FUNC( SDL_COSF )
{

}

HB_FUNC( SDL_CREATEASYNCIOQUEUE )
{

}

HB_FUNC( SDL_CREATEAUDIOSTREAM )
{

}

HB_FUNC( SDL_CREATECOLORCURSOR )
{

}

HB_FUNC( SDL_CREATECONDITION )
{

}

HB_FUNC( SDL_CREATECURSOR )
{

}

HB_FUNC( SDL_CREATEDIRECTORY )
{

}

HB_FUNC( SDL_CREATEENVIRONMENT )
{

}

HB_FUNC( SDL_CREATEGPUBUFFER )
{

}

HB_FUNC( SDL_CREATEGPUCOMPUTEPIPELINE )
{

}

HB_FUNC( SDL_CREATEGPUDEVICE )
{

}

HB_FUNC( SDL_CREATEGPUDEVICEWITHPROPERTIES )
{

}

HB_FUNC( SDL_CREATEGPUGRAPHICSPIPELINE )
{

}

HB_FUNC( SDL_CREATEGPUSAMPLER )
{

}

HB_FUNC( SDL_CREATEGPUSHADER )
{

}

HB_FUNC( SDL_CREATEGPUTEXTURE )
{

}

HB_FUNC( SDL_CREATEGPUTRANSFERBUFFER )
{

}

HB_FUNC( SDL_CREATEHAPTICEFFECT )
{

}

HB_FUNC( SDL_CREATEMUTEX )
{

}

HB_FUNC( SDL_CREATEPALETTE )
{

}

HB_FUNC( SDL_CREATEPOPUPWINDOW )
{

}

HB_FUNC( SDL_CREATEPROCESS )
{

}

HB_FUNC( SDL_CREATEPROCESSWITHPROPERTIES )
{

}

HB_FUNC( SDL_CREATEPROPERTIES )
{

}

// SDL_Renderer *SDL_CreateRenderer( SDL_Window *window, const char *name );
HB_FUNC( SDL_CREATERENDERER )
{
   if( hb_param( 1, HB_IT_POINTER ) != NULL )
   {
      const char *name = NULL;

      if( hb_param( 2, HB_IT_STRING ) != NULL )
      {
         name = hb_parc( 2 );
      }
      else if( hb_param( 2, HB_IT_NIL ) != NULL )
      {
         name = NULL;
      }
      hb_sdl_renderer_Return( SDL_CreateRenderer( hb_sdl_window_ParamPtr( 1 ), name ) );
   }
   else
   {
      HB_ERR_ARGS();
   }
}

HB_FUNC( SDL_CREATERENDERERWITHPROPERTIES )
{

}

HB_FUNC( SDL_CREATERWLOCK )
{

}

HB_FUNC( SDL_CREATESEMAPHORE )
{

}

HB_FUNC( SDL_CREATESOFTWARERENDERER )
{

}

HB_FUNC( SDL_CREATESTORAGEDIRECTORY )
{

}

HB_FUNC( SDL_CREATESURFACE )
{

}

HB_FUNC( SDL_CREATESURFACEFROM )
{

}

HB_FUNC( SDL_CREATESURFACEPALETTE )
{

}

HB_FUNC( SDL_CREATESYSTEMCURSOR )
{

}

HB_FUNC( SDL_CREATETEXTURE )
{

}

HB_FUNC( SDL_CREATETEXTUREFROMSURFACE )
{

}

HB_FUNC( SDL_CREATETEXTUREWITHPROPERTIES )
{

}

HB_FUNC( SDL_CREATETHREAD )
{

}

HB_FUNC( SDL_CREATETHREADWITHPROPERTIES )
{

}

// SDL_Window *SDL_CreateWindow( const char *title, int w, int h, SDL_WindowFlags flags );
HB_FUNC( SDL_CREATEWINDOW )
{
   if( hb_param( 1, HB_IT_STRING ) != NULL && hb_param( 2, HB_IT_INTEGER ) != NULL && hb_param( 3, HB_IT_INTEGER ) != NULL && hb_param( 4, HB_IT_NUMINT ) != NULL )
   {
      hb_sdl_window_Return( SDL_CreateWindow( hb_parc( 1 ), hb_parni( 2 ), hb_parni( 3 ), hb_parni( 4 ) ) );
   }
   else
   {
      HB_ERR_ARGS();
   }
}

HB_FUNC( SDL_CREATEWINDOWANDRENDERER )
{

}

HB_FUNC( SDL_CREATEWINDOWWITHPROPERTIES )
{

}

HB_FUNC( SDL_CURSORVISIBLE )
{

}

HB_FUNC( SDL_DATETIMETOTIME )
{

}

// void SDL_Delay( Uint32 ms );
HB_FUNC( SDL_DELAY )
{
   if( hb_param( 1, HB_IT_NUMINT ) != NULL )
   {
      SDL_Delay( hb_parni( 1 ) );
   }
   else
   {
      HB_ERR_ARGS();
   }
}

HB_FUNC( SDL_DELAYNS )
{

}

HB_FUNC( SDL_DELAYPRECISE )
{

}

HB_FUNC( SDL_DESTROYASYNCIOQUEUE )
{

}

HB_FUNC( SDL_DESTROYAUDIOSTREAM )
{

}

HB_FUNC( SDL_DESTROYCONDITION )
{

}

HB_FUNC( SDL_DESTROYCURSOR )
{

}

HB_FUNC( SDL_DESTROYENVIRONMENT )
{

}

HB_FUNC( SDL_DESTROYGPUDEVICE )
{

}

HB_FUNC( SDL_DESTROYHAPTICEFFECT )
{

}

HB_FUNC( SDL_DESTROYMUTEX )
{

}

HB_FUNC( SDL_DESTROYPALETTE )
{

}

HB_FUNC( SDL_DESTROYPROCESS )
{

}

HB_FUNC( SDL_DESTROYPROPERTIES )
{

}

// void SDL_DestroyRenderer( SDL_Renderer *renderer );
HB_FUNC( SDL_DESTROYRENDERER )
{
   if( hb_param( 1, HB_IT_POINTER ) != NULL )
   {
      SDL_Renderer **ppSDL_Renderer = ( SDL_Renderer ** ) hb_parptrGC( &s_gc_sdl_renderer_Funcs, 1 );

      if( ppSDL_Renderer && *ppSDL_Renderer )
      {
         SDL_DestroyRenderer( *ppSDL_Renderer );
         *ppSDL_Renderer = NULL;
      }
      else
      {
         hb_retc( "Renderer already destroyed or invalid pointer." );
      }
   }
   else
   {
      HB_ERR_ARGS();
   }
}

HB_FUNC( SDL_DESTROYRWLOCK )
{

}

HB_FUNC( SDL_DESTROYSEMAPHORE )
{

}

// void SDL_DestroySurface( SDL_Surface *surface );
HB_FUNC( SDL_DESTROYSURFACE )
{
   if( hb_param( 1, HB_IT_POINTER ) != NULL )
   {
      SDL_Surface **ppSDL_Surface = ( SDL_Surface ** ) hb_parptrGC( &s_gc_sdl_surface_Funcs, 1 );

      if( ppSDL_Surface && *ppSDL_Surface )
      {
         SDL_DestroySurface( *ppSDL_Surface );
         *ppSDL_Surface = NULL;
      }
      else
      {
         hb_retc( "Surface already destroyed or invalid pointer." );
      }
   }
   else
   {
      HB_ERR_ARGS();
   }
}

// void SDL_DestroyTexture( SDL_Texture *texture );
HB_FUNC( SDL_DESTROYTEXTURE )
{
   if( hb_param( 1, HB_IT_POINTER ) != NULL )
   {
      SDL_Texture **ppSDL_Texture = ( SDL_Texture ** ) hb_parptrGC( &s_gc_sdl_texture_Funcs, 1 );

      if( ppSDL_Texture && *ppSDL_Texture )
      {
         SDL_DestroyTexture( *ppSDL_Texture );
         *ppSDL_Texture = NULL;
      }
      else
      {
         hb_retc( "Texture already destroyed or invalid pointer." );
      }
   }
   else
   {
      HB_ERR_ARGS();
   }
}

// void SDL_DestroyWindow( SDL_Window *window );
HB_FUNC( SDL_DESTROYWINDOW )
{
   if( hb_param( 1, HB_IT_POINTER ) != NULL )
   {
      SDL_Window **ppSDL_Window = ( SDL_Window ** ) hb_parptrGC( &s_gc_sdl_window_Funcs, 1 );

      if( ppSDL_Window && *ppSDL_Window )
      {
         SDL_DestroyWindow( *ppSDL_Window );
         *ppSDL_Window = NULL;
      }
      else
      {
         hb_retc( "Window already destroyed or invalid pointer." );
      }
   }
   else
   {
      HB_ERR_ARGS();
   }
}

HB_FUNC( SDL_DESTROYWINDOWSURFACE )
{

}

HB_FUNC( SDL_DETACHTHREAD )
{

}

HB_FUNC( SDL_DETACHVIRTUALJOYSTICK )
{

}

HB_FUNC( SDL_DISABLESCREENSAVER )
{

}

HB_FUNC( SDL_DISPATCHGPUCOMPUTE )
{

}

HB_FUNC( SDL_DISPATCHGPUCOMPUTEINDIRECT )
{

}

HB_FUNC( SDL_DOWNLOADFROMGPUBUFFER )
{

}

HB_FUNC( SDL_DOWNLOADFROMGPUTEXTURE )
{

}

HB_FUNC( SDL_DRAWGPUINDEXEDPRIMITIVES )
{

}

HB_FUNC( SDL_DRAWGPUINDEXEDPRIMITIVESINDIRECT )
{

}

HB_FUNC( SDL_DRAWGPUPRIMITIVES )
{

}

HB_FUNC( SDL_DRAWGPUPRIMITIVESINDIRECT )
{

}

HB_FUNC( SDL_DUPLICATESURFACE )
{

}

HB_FUNC( SDL_EGL_GETCURRENTCONFIG )
{

}

HB_FUNC( SDL_EGL_GETCURRENTDISPLAY )
{

}

HB_FUNC( SDL_EGL_GETPROCADDRESS )
{

}

HB_FUNC( SDL_EGL_GETWINDOWSURFACE )
{

}

HB_FUNC( SDL_EGL_SETATTRIBUTECALLBACKS )
{

}

HB_FUNC( SDL_ENABLESCREENSAVER )
{

}

HB_FUNC( SDL_ENDGPUCOMPUTEPASS )
{

}

HB_FUNC( SDL_ENDGPUCOPYPASS )
{

}

HB_FUNC( SDL_ENDGPURENDERPASS )
{

}

HB_FUNC( SDL_ENTERAPPMAINCALLBACKS )
{

}

HB_FUNC( SDL_ENUMERATEDIRECTORY )
{

}

HB_FUNC( SDL_ENUMERATEPROPERTIES )
{

}

HB_FUNC( SDL_ENUMERATESTORAGEDIRECTORY )
{

}

HB_FUNC( SDL_EVENTENABLED )
{

}

HB_FUNC( SDL_EXP )
{

}

HB_FUNC( SDL_EXPF )
{

}

HB_FUNC( SDL_FABS )
{

}

HB_FUNC( SDL_FABSF )
{

}

HB_FUNC( SDL_FILLSURFACERECT )
{

}

HB_FUNC( SDL_FILLSURFACERECTS )
{

}

HB_FUNC( SDL_FILTEREVENTS )
{

}

HB_FUNC( SDL_FLASHWINDOW )
{

}

HB_FUNC( SDL_FLIPSURFACE )
{

}

HB_FUNC( SDL_FLOOR )
{

}

HB_FUNC( SDL_FLOORF )
{

}

HB_FUNC( SDL_FLUSHAUDIOSTREAM )
{

}

HB_FUNC( SDL_FLUSHEVENT )
{

}

HB_FUNC( SDL_FLUSHEVENTS )
{

}

HB_FUNC( SDL_FLUSHIO )
{

}

HB_FUNC( SDL_FLUSHRENDERER )
{

}

HB_FUNC( SDL_FMOD )
{

}

HB_FUNC( SDL_FMODF )
{

}

HB_FUNC( SDL_FREE )
{

}

HB_FUNC( SDL_GAMEPADCONNECTED )
{

}

HB_FUNC( SDL_GAMEPADEVENTSENABLED )
{

}

HB_FUNC( SDL_GAMEPADHASAXIS )
{

}

HB_FUNC( SDL_GAMEPADHASBUTTON )
{

}

HB_FUNC( SDL_GAMEPADHASSENSOR )
{

}

HB_FUNC( SDL_GAMEPADSENSORENABLED )
{

}

HB_FUNC( SDL_GDKRESUMEGPU )
{

}

HB_FUNC( SDL_GDKSUSPENDCOMPLETE )
{

}

HB_FUNC( SDL_GDKSUSPENDGPU )
{

}

HB_FUNC( SDL_GENERATEMIPMAPSFORGPUTEXTURE )
{

}

HB_FUNC( SDL_GETANDROIDACTIVITY )
{

}

HB_FUNC( SDL_GETANDROIDCACHEPATH )
{

}

HB_FUNC( SDL_GETANDROIDEXTERNALSTORAGEPATH )
{

}

HB_FUNC( SDL_GETANDROIDEXTERNALSTORAGESTATE )
{

}

HB_FUNC( SDL_GETANDROIDINTERNALSTORAGEPATH )
{

}

HB_FUNC( SDL_GETANDROIDJNIENV )
{

}

HB_FUNC( SDL_GETANDROIDSDKVERSION )
{

}

HB_FUNC( SDL_GETAPPMETADATAPROPERTY )
{

}

HB_FUNC( SDL_GETASSERTIONHANDLER )
{

}

HB_FUNC( SDL_GETASSERTIONREPORT )
{

}

HB_FUNC( SDL_GETASYNCIORESULT )
{

}

HB_FUNC( SDL_GETASYNCIOSIZE )
{

}

HB_FUNC( SDL_GETATOMICINT )
{

}

HB_FUNC( SDL_GETATOMICPOINTER )
{

}

HB_FUNC( SDL_GETATOMICU32 )
{

}

HB_FUNC( SDL_GETAUDIODEVICECHANNELMAP )
{

}

HB_FUNC( SDL_GETAUDIODEVICEFORMAT )
{

}

HB_FUNC( SDL_GETAUDIODEVICEGAIN )
{

}

HB_FUNC( SDL_GETAUDIODEVICENAME )
{

}

HB_FUNC( SDL_GETAUDIODRIVER )
{

}

HB_FUNC( SDL_GETAUDIOFORMATNAME )
{

}

HB_FUNC( SDL_GETAUDIOPLAYBACKDEVICES )
{

}

HB_FUNC( SDL_GETAUDIORECORDINGDEVICES )
{

}

HB_FUNC( SDL_GETAUDIOSTREAMAVAILABLE )
{

}

HB_FUNC( SDL_GETAUDIOSTREAMDATA )
{

}

HB_FUNC( SDL_GETAUDIOSTREAMDEVICE )
{

}

HB_FUNC( SDL_GETAUDIOSTREAMFORMAT )
{

}

HB_FUNC( SDL_GETAUDIOSTREAMFREQUENCYRATIO )
{

}

HB_FUNC( SDL_GETAUDIOSTREAMGAIN )
{

}

HB_FUNC( SDL_GETAUDIOSTREAMINPUTCHANNELMAP )
{

}

HB_FUNC( SDL_GETAUDIOSTREAMOUTPUTCHANNELMAP )
{

}

HB_FUNC( SDL_GETAUDIOSTREAMPROPERTIES )
{

}

HB_FUNC( SDL_GETAUDIOSTREAMQUEUED )
{

}

HB_FUNC( SDL_GETBASEPATH )
{

}

HB_FUNC( SDL_GETBOOLEANPROPERTY )
{

}

HB_FUNC( SDL_GETCAMERADRIVER )
{

}

HB_FUNC( SDL_GETCAMERAFORMAT )
{

}

HB_FUNC( SDL_GETCAMERAID )
{

}

HB_FUNC( SDL_GETCAMERANAME )
{

}

HB_FUNC( SDL_GETCAMERAPERMISSIONSTATE )
{

}

HB_FUNC( SDL_GETCAMERAPOSITION )
{

}

HB_FUNC( SDL_GETCAMERAPROPERTIES )
{

}

HB_FUNC( SDL_GETCAMERAS )
{

}

HB_FUNC( SDL_GETCAMERASUPPORTEDFORMATS )
{

}

HB_FUNC( SDL_GETCLIPBOARDDATA )
{

}

HB_FUNC( SDL_GETCLIPBOARDMIMETYPES )
{

}

HB_FUNC( SDL_GETCLIPBOARDTEXT )
{

}

HB_FUNC( SDL_GETCLOSESTFULLSCREENDISPLAYMODE )
{

}

HB_FUNC( SDL_GETCPUCACHELINESIZE )
{

}

HB_FUNC( SDL_GETCURRENTAUDIODRIVER )
{

}

HB_FUNC( SDL_GETCURRENTCAMERADRIVER )
{

}

HB_FUNC( SDL_GETCURRENTDIRECTORY )
{

}

HB_FUNC( SDL_GETCURRENTDISPLAYMODE )
{

}

HB_FUNC( SDL_GETCURRENTDISPLAYORIENTATION )
{

}

HB_FUNC( SDL_GETCURRENTRENDEROUTPUTSIZE )
{

}

HB_FUNC( SDL_GETCURRENTTHREADID )
{

}

HB_FUNC( SDL_GETCURRENTTIME )
{

}

HB_FUNC( SDL_GETCURRENTVIDEODRIVER )
{

}

HB_FUNC( SDL_GETCURSOR )
{

}

HB_FUNC( SDL_GETDATETIMELOCALEPREFERENCES )
{

}

HB_FUNC( SDL_GETDAYOFWEEK )
{

}

HB_FUNC( SDL_GETDAYOFYEAR )
{

}

HB_FUNC( SDL_GETDAYSINMONTH )
{

}

HB_FUNC( SDL_GETDEFAULTASSERTIONHANDLER )
{

}

HB_FUNC( SDL_GETDEFAULTCURSOR )
{

}

HB_FUNC( SDL_GETDEFAULTLOGOUTPUTFUNCTION )
{

}

HB_FUNC( SDL_GETDESKTOPDISPLAYMODE )
{

}

HB_FUNC( SDL_GETDIRECT3D9ADAPTERINDEX )
{

}

HB_FUNC( SDL_GETDISPLAYBOUNDS )
{

}

HB_FUNC( SDL_GETDISPLAYCONTENTSCALE )
{

}

HB_FUNC( SDL_GETDISPLAYFORPOINT )
{

}

HB_FUNC( SDL_GETDISPLAYFORRECT )
{

}

HB_FUNC( SDL_GETDISPLAYFORWINDOW )
{

}

HB_FUNC( SDL_GETDISPLAYNAME )
{

}

HB_FUNC( SDL_GETDISPLAYPROPERTIES )
{

}

HB_FUNC( SDL_GETDISPLAYS )
{

}

HB_FUNC( SDL_GETDISPLAYUSABLEBOUNDS )
{

}

HB_FUNC( SDL_GETDXGIOUTPUTINFO )
{

}

HB_FUNC( SDL_GETENV )
{

}

HB_FUNC( SDL_GETENV_UNSAFE )
{

}

HB_FUNC( SDL_GETENVIRONMENT )
{

}

HB_FUNC( SDL_GETENVIRONMENTVARIABLE )
{

}

HB_FUNC( SDL_GETENVIRONMENTVARIABLES )
{

}

// const char * SDL_GetError( void );
HB_FUNC( SDL_GETERROR )
{
   hb_retc( SDL_GetError() );
}

HB_FUNC( SDL_GETEVENTFILTER )
{

}

HB_FUNC( SDL_GETFLOATPROPERTY )
{

}

HB_FUNC( SDL_GETFULLSCREENDISPLAYMODES )
{

}

HB_FUNC( SDL_GETGAMEPADAPPLESFSYMBOLSNAMEFORAXIS )
{

}

HB_FUNC( SDL_GETGAMEPADAPPLESFSYMBOLSNAMEFORBUTTON )
{

}

HB_FUNC( SDL_GETGAMEPADAXIS )
{

}

HB_FUNC( SDL_GETGAMEPADAXISFROMSTRING )
{

}

HB_FUNC( SDL_GETGAMEPADBINDINGS )
{

}

HB_FUNC( SDL_GETGAMEPADBUTTON )
{

}

HB_FUNC( SDL_GETGAMEPADBUTTONFROMSTRING )
{

}

HB_FUNC( SDL_GETGAMEPADBUTTONLABEL )
{

}

HB_FUNC( SDL_GETGAMEPADBUTTONLABELFORTYPE )
{

}

HB_FUNC( SDL_GETGAMEPADCONNECTIONSTATE )
{

}

HB_FUNC( SDL_GETGAMEPADFIRMWAREVERSION )
{

}

HB_FUNC( SDL_GETGAMEPADFROMID )
{

}

HB_FUNC( SDL_GETGAMEPADFROMPLAYERINDEX )
{

}

HB_FUNC( SDL_GETGAMEPADGUIDFORID )
{

}

HB_FUNC( SDL_GETGAMEPADID )
{

}

HB_FUNC( SDL_GETGAMEPADJOYSTICK )
{

}

HB_FUNC( SDL_GETGAMEPADMAPPING )
{

}

HB_FUNC( SDL_GETGAMEPADMAPPINGFORGUID )
{

}

HB_FUNC( SDL_GETGAMEPADMAPPINGFORID )
{

}

HB_FUNC( SDL_GETGAMEPADMAPPINGS )
{

}

HB_FUNC( SDL_GETGAMEPADNAME )
{

}

HB_FUNC( SDL_GETGAMEPADNAMEFORID )
{

}

HB_FUNC( SDL_GETGAMEPADPATH )
{

}

HB_FUNC( SDL_GETGAMEPADPATHFORID )
{

}

HB_FUNC( SDL_GETGAMEPADPLAYERINDEX )
{

}

HB_FUNC( SDL_GETGAMEPADPLAYERINDEXFORID )
{

}

HB_FUNC( SDL_GETGAMEPADPOWERINFO )
{

}

HB_FUNC( SDL_GETGAMEPADPRODUCT )
{

}

HB_FUNC( SDL_GETGAMEPADPRODUCTFORID )
{

}

HB_FUNC( SDL_GETGAMEPADPRODUCTVERSION )
{

}

HB_FUNC( SDL_GETGAMEPADPRODUCTVERSIONFORID )
{

}

HB_FUNC( SDL_GETGAMEPADPROPERTIES )
{

}

HB_FUNC( SDL_GETGAMEPADS )
{

}

HB_FUNC( SDL_GETGAMEPADSENSORDATA )
{

}

HB_FUNC( SDL_GETGAMEPADSENSORDATARATE )
{

}

HB_FUNC( SDL_GETGAMEPADSERIAL )
{

}

HB_FUNC( SDL_GETGAMEPADSTEAMHANDLE )
{

}

HB_FUNC( SDL_GETGAMEPADSTRINGFORAXIS )
{

}

HB_FUNC( SDL_GETGAMEPADSTRINGFORBUTTON )
{

}

HB_FUNC( SDL_GETGAMEPADSTRINGFORTYPE )
{

}

HB_FUNC( SDL_GETGAMEPADTOUCHPADFINGER )
{

}

HB_FUNC( SDL_GETGAMEPADTYPE )
{

}

HB_FUNC( SDL_GETGAMEPADTYPEFORID )
{

}

HB_FUNC( SDL_GETGAMEPADTYPEFROMSTRING )
{

}

HB_FUNC( SDL_GETGAMEPADVENDOR )
{

}

HB_FUNC( SDL_GETGAMEPADVENDORFORID )
{

}

HB_FUNC( SDL_GETGDKDEFAULTUSER )
{

}

HB_FUNC( SDL_GETGDKTASKQUEUE )
{

}

HB_FUNC( SDL_GETGLOBALMOUSESTATE )
{

}

HB_FUNC( SDL_GETGLOBALPROPERTIES )
{

}

HB_FUNC( SDL_GETGPUDEVICEDRIVER )
{

}

HB_FUNC( SDL_GETGPUDRIVER )
{

}

HB_FUNC( SDL_GETGPUSHADERFORMATS )
{

}

HB_FUNC( SDL_GETGPUSWAPCHAINTEXTUREFORMAT )
{

}

HB_FUNC( SDL_GETGRABBEDWINDOW )
{

}

HB_FUNC( SDL_GETHAPTICEFFECTSTATUS )
{

}

HB_FUNC( SDL_GETHAPTICFEATURES )
{

}

HB_FUNC( SDL_GETHAPTICFROMID )
{

}

HB_FUNC( SDL_GETHAPTICID )
{

}

HB_FUNC( SDL_GETHAPTICNAME )
{

}

HB_FUNC( SDL_GETHAPTICNAMEFORID )
{

}

HB_FUNC( SDL_GETHAPTICS )
{

}

HB_FUNC( SDL_GETHINT )
{

}

HB_FUNC( SDL_GETHINTBOOLEAN )
{

}

HB_FUNC( SDL_GETIOPROPERTIES )
{

}

HB_FUNC( SDL_GETIOSIZE )
{

}

HB_FUNC( SDL_GETIOSTATUS )
{

}

HB_FUNC( SDL_GETJOYSTICKAXIS )
{

}

HB_FUNC( SDL_GETJOYSTICKAXISINITIALSTATE )
{

}

HB_FUNC( SDL_GETJOYSTICKBALL )
{

}

HB_FUNC( SDL_GETJOYSTICKBUTTON )
{

}

HB_FUNC( SDL_GETJOYSTICKCONNECTIONSTATE )
{

}

HB_FUNC( SDL_GETJOYSTICKFIRMWAREVERSION )
{

}

HB_FUNC( SDL_GETJOYSTICKFROMID )
{

}

HB_FUNC( SDL_GETJOYSTICKFROMPLAYERINDEX )
{

}

HB_FUNC( SDL_GETJOYSTICKGUID )
{

}

HB_FUNC( SDL_GETJOYSTICKGUIDFORID )
{

}

HB_FUNC( SDL_GETJOYSTICKGUIDINFO )
{

}

HB_FUNC( SDL_GETJOYSTICKHAT )
{

}

HB_FUNC( SDL_GETJOYSTICKID )
{

}

HB_FUNC( SDL_GETJOYSTICKNAME )
{

}

HB_FUNC( SDL_GETJOYSTICKNAMEFORID )
{

}

HB_FUNC( SDL_GETJOYSTICKPATH )
{

}

HB_FUNC( SDL_GETJOYSTICKPATHFORID )
{

}

HB_FUNC( SDL_GETJOYSTICKPLAYERINDEX )
{

}

HB_FUNC( SDL_GETJOYSTICKPLAYERINDEXFORID )
{

}

HB_FUNC( SDL_GETJOYSTICKPOWERINFO )
{

}

HB_FUNC( SDL_GETJOYSTICKPRODUCT )
{

}

HB_FUNC( SDL_GETJOYSTICKPRODUCTFORID )
{

}

HB_FUNC( SDL_GETJOYSTICKPRODUCTVERSION )
{

}

HB_FUNC( SDL_GETJOYSTICKPRODUCTVERSIONFORID )
{

}

HB_FUNC( SDL_GETJOYSTICKPROPERTIES )
{

}

HB_FUNC( SDL_GETJOYSTICKS )
{

}

HB_FUNC( SDL_GETJOYSTICKSERIAL )
{

}

HB_FUNC( SDL_GETJOYSTICKTYPE )
{

}

HB_FUNC( SDL_GETJOYSTICKTYPEFORID )
{

}

HB_FUNC( SDL_GETJOYSTICKVENDOR )
{

}

HB_FUNC( SDL_GETJOYSTICKVENDORFORID )
{

}

HB_FUNC( SDL_GETKEYBOARDFOCUS )
{

}

HB_FUNC( SDL_GETKEYBOARDNAMEFORID )
{

}

HB_FUNC( SDL_GETKEYBOARDS )
{

}

HB_FUNC( SDL_GETKEYBOARDSTATE )
{

}

HB_FUNC( SDL_GETKEYFROMNAME )
{

}

HB_FUNC( SDL_GETKEYFROMSCANCODE )
{

}

HB_FUNC( SDL_GETKEYNAME )
{

}

HB_FUNC( SDL_GETLOGOUTPUTFUNCTION )
{

}

HB_FUNC( SDL_GETLOGPRIORITY )
{

}

HB_FUNC( SDL_GETMASKSFORPIXELFORMAT )
{

}

HB_FUNC( SDL_GETMAXHAPTICEFFECTS )
{

}

HB_FUNC( SDL_GETMAXHAPTICEFFECTSPLAYING )
{

}

HB_FUNC( SDL_GETMEMORYFUNCTIONS )
{

}

HB_FUNC( SDL_GETMICE )
{

}

HB_FUNC( SDL_GETMODSTATE )
{

}

HB_FUNC( SDL_GETMOUSEFOCUS )
{

}

HB_FUNC( SDL_GETMOUSENAMEFORID )
{

}

HB_FUNC( SDL_GETMOUSESTATE )
{

}

HB_FUNC( SDL_GETNATURALDISPLAYORIENTATION )
{

}

HB_FUNC( SDL_GETNUMALLOCATIONS )
{

}

HB_FUNC( SDL_GETNUMAUDIODRIVERS )
{

}

HB_FUNC( SDL_GETNUMBERPROPERTY )
{

}

HB_FUNC( SDL_GETNUMCAMERADRIVERS )
{

}

HB_FUNC( SDL_GETNUMGAMEPADTOUCHPADFINGERS )
{

}

HB_FUNC( SDL_GETNUMGAMEPADTOUCHPADS )
{

}

HB_FUNC( SDL_GETNUMGPUDRIVERS )
{

}

HB_FUNC( SDL_GETNUMHAPTICAXES )
{

}

HB_FUNC( SDL_GETNUMJOYSTICKAXES )
{

}

HB_FUNC( SDL_GETNUMJOYSTICKBALLS )
{

}

HB_FUNC( SDL_GETNUMJOYSTICKBUTTONS )
{

}

HB_FUNC( SDL_GETNUMJOYSTICKHATS )
{

}

HB_FUNC( SDL_GETNUMLOGICALCPUCORES )
{

}

HB_FUNC( SDL_GETNUMRENDERDRIVERS )
{

}

HB_FUNC( SDL_GETNUMVIDEODRIVERS )
{

}

HB_FUNC( SDL_GETORIGINALMEMORYFUNCTIONS )
{

}

HB_FUNC( SDL_GETPATHINFO )
{

}

HB_FUNC( SDL_GETPERFORMANCECOUNTER )
{

}

HB_FUNC( SDL_GETPERFORMANCEFREQUENCY )
{

}

HB_FUNC( SDL_GETPIXELFORMATDETAILS )
{

}

HB_FUNC( SDL_GETPIXELFORMATFORMASKS )
{

}

HB_FUNC( SDL_GETPIXELFORMATNAME )
{

}

HB_FUNC( SDL_GETPLATFORM )
{

}

HB_FUNC( SDL_GETPOINTERPROPERTY )
{

}

HB_FUNC( SDL_GETPOWERINFO )
{

}

HB_FUNC( SDL_GETPREFERREDLOCALES )
{

}

HB_FUNC( SDL_GETPREFPATH )
{

}

HB_FUNC( SDL_GETPRIMARYDISPLAY )
{

}

HB_FUNC( SDL_GETPRIMARYSELECTIONTEXT )
{

}

HB_FUNC( SDL_GETPROCESSINPUT )
{

}

HB_FUNC( SDL_GETPROCESSOUTPUT )
{

}

HB_FUNC( SDL_GETPROCESSPROPERTIES )
{

}

HB_FUNC( SDL_GETPROPERTYTYPE )
{

}

HB_FUNC( SDL_GETREALGAMEPADTYPE )
{

}

HB_FUNC( SDL_GETREALGAMEPADTYPEFORID )
{

}

HB_FUNC( SDL_GETRECTANDLINEINTERSECTION )
{

}

HB_FUNC( SDL_GETRECTANDLINEINTERSECTIONFLOAT )
{

}

HB_FUNC( SDL_GETRECTENCLOSINGPOINTS )
{

}

HB_FUNC( SDL_GETRECTENCLOSINGPOINTSFLOAT )
{

}

HB_FUNC( SDL_GETRECTINTERSECTION )
{

}

HB_FUNC( SDL_GETRECTINTERSECTIONFLOAT )
{

}

HB_FUNC( SDL_GETRECTUNION )
{

}

HB_FUNC( SDL_GETRECTUNIONFLOAT )
{

}

HB_FUNC( SDL_GETRELATIVEMOUSESTATE )
{

}

HB_FUNC( SDL_GETRENDERCLIPRECT )
{

}

HB_FUNC( SDL_GETRENDERCOLORSCALE )
{

}

HB_FUNC( SDL_GETRENDERDRAWBLENDMODE )
{

}

HB_FUNC( SDL_GETRENDERDRAWCOLOR )
{

}

HB_FUNC( SDL_GETRENDERDRAWCOLORFLOAT )
{

}

HB_FUNC( SDL_GETRENDERDRIVER )
{

}

HB_FUNC( SDL_GETRENDERER )
{

}

HB_FUNC( SDL_GETRENDERERFROMTEXTURE )
{

}

HB_FUNC( SDL_GETRENDERERNAME )
{

}

HB_FUNC( SDL_GETRENDERERPROPERTIES )
{

}

HB_FUNC( SDL_GETRENDERLOGICALPRESENTATION )
{

}

HB_FUNC( SDL_GETRENDERLOGICALPRESENTATIONRECT )
{

}

HB_FUNC( SDL_GETRENDERMETALCOMMANDENCODER )
{

}

HB_FUNC( SDL_GETRENDERMETALLAYER )
{

}

HB_FUNC( SDL_GETRENDEROUTPUTSIZE )
{

}

HB_FUNC( SDL_GETRENDERSAFEAREA )
{

}

HB_FUNC( SDL_GETRENDERSCALE )
{

}

HB_FUNC( SDL_GETRENDERTARGET )
{

}

HB_FUNC( SDL_GETRENDERVIEWPORT )
{

}

HB_FUNC( SDL_GETRENDERVSYNC )
{

}

HB_FUNC( SDL_GETRENDERWINDOW )
{

}

HB_FUNC( SDL_GETREVISION )
{

}

HB_FUNC( SDL_GETRGB )
{

}

HB_FUNC( SDL_GETRGBA )
{

}

HB_FUNC( SDL_GETSANDBOX )
{

}

HB_FUNC( SDL_GETSCANCODEFROMKEY )
{

}

HB_FUNC( SDL_GETSCANCODEFROMNAME )
{

}

HB_FUNC( SDL_GETSCANCODENAME )
{

}

HB_FUNC( SDL_GETSEMAPHOREVALUE )
{

}

HB_FUNC( SDL_GETSENSORDATA )
{

}

HB_FUNC( SDL_GETSENSORFROMID )
{

}

HB_FUNC( SDL_GETSENSORID )
{

}

HB_FUNC( SDL_GETSENSORNAME )
{

}

HB_FUNC( SDL_GETSENSORNAMEFORID )
{

}

HB_FUNC( SDL_GETSENSORNONPORTABLETYPE )
{

}

HB_FUNC( SDL_GETSENSORNONPORTABLETYPEFORID )
{

}

HB_FUNC( SDL_GETSENSORPROPERTIES )
{

}

HB_FUNC( SDL_GETSENSORS )
{

}

HB_FUNC( SDL_GETSENSORTYPE )
{

}

HB_FUNC( SDL_GETSENSORTYPEFORID )
{

}

HB_FUNC( SDL_GETSILENCEVALUEFORFORMAT )
{

}

HB_FUNC( SDL_GETSIMDALIGNMENT )
{

}

HB_FUNC( SDL_GETSTORAGEFILESIZE )
{

}

HB_FUNC( SDL_GETSTORAGEPATHINFO )
{

}

HB_FUNC( SDL_GETSTORAGESPACEREMAINING )
{

}

HB_FUNC( SDL_GETSTRINGPROPERTY )
{

}

HB_FUNC( SDL_GETSURFACEALPHAMOD )
{

}

HB_FUNC( SDL_GETSURFACEBLENDMODE )
{

}

HB_FUNC( SDL_GETSURFACECLIPRECT )
{

}

HB_FUNC( SDL_GETSURFACECOLORKEY )
{

}

HB_FUNC( SDL_GETSURFACECOLORMOD )
{

}

HB_FUNC( SDL_GETSURFACECOLORSPACE )
{

}

HB_FUNC( SDL_GETSURFACEIMAGES )
{

}

HB_FUNC( SDL_GETSURFACEPALETTE )
{

}

HB_FUNC( SDL_GETSURFACEPROPERTIES )
{

}

HB_FUNC( SDL_GETSYSTEMRAM )
{

}

HB_FUNC( SDL_GETSYSTEMTHEME )
{

}

HB_FUNC( SDL_GETTEXTINPUTAREA )
{

}

HB_FUNC( SDL_GETTEXTUREALPHAMOD )
{

}

HB_FUNC( SDL_GETTEXTUREALPHAMODFLOAT )
{

}

HB_FUNC( SDL_GETTEXTUREBLENDMODE )
{

}

HB_FUNC( SDL_GETTEXTURECOLORMOD )
{

}

HB_FUNC( SDL_GETTEXTURECOLORMODFLOAT )
{

}

HB_FUNC( SDL_GETTEXTUREPROPERTIES )
{

}

HB_FUNC( SDL_GETTEXTURESCALEMODE )
{

}

HB_FUNC( SDL_GETTEXTURESIZE )
{

}

HB_FUNC( SDL_GETTHREADID )
{

}

HB_FUNC( SDL_GETTHREADNAME )
{

}

HB_FUNC( SDL_GETTICKS )
{

}

HB_FUNC( SDL_GETTICKSNS )
{

}

HB_FUNC( SDL_GETTLS )
{

}

HB_FUNC( SDL_GETTOUCHDEVICENAME )
{

}

HB_FUNC( SDL_GETTOUCHDEVICES )
{

}

HB_FUNC( SDL_GETTOUCHDEVICETYPE )
{

}

HB_FUNC( SDL_GETTOUCHFINGERS )
{

}

HB_FUNC( SDL_GETUSERFOLDER )
{

}

HB_FUNC( SDL_GETVERSION )
{

}

HB_FUNC( SDL_GETVIDEODRIVER )
{

}

HB_FUNC( SDL_GETWINDOWASPECTRATIO )
{

}

HB_FUNC( SDL_GETWINDOWBORDERSSIZE )
{

}

HB_FUNC( SDL_GETWINDOWDISPLAYSCALE )
{

}

HB_FUNC( SDL_GETWINDOWFLAGS )
{

}

HB_FUNC( SDL_GETWINDOWFROMEVENT )
{

}

HB_FUNC( SDL_GETWINDOWFROMID )
{

}

HB_FUNC( SDL_GETWINDOWFULLSCREENMODE )
{

}

HB_FUNC( SDL_GETWINDOWICCPROFILE )
{

}

HB_FUNC( SDL_GETWINDOWID )
{

}

HB_FUNC( SDL_GETWINDOWKEYBOARDGRAB )
{

}

HB_FUNC( SDL_GETWINDOWMAXIMUMSIZE )
{

}

HB_FUNC( SDL_GETWINDOWMINIMUMSIZE )
{

}

HB_FUNC( SDL_GETWINDOWMOUSEGRAB )
{

}

HB_FUNC( SDL_GETWINDOWMOUSERECT )
{

}

HB_FUNC( SDL_GETWINDOWOPACITY )
{

}

HB_FUNC( SDL_GETWINDOWPARENT )
{

}

HB_FUNC( SDL_GETWINDOWPIXELDENSITY )
{

}

HB_FUNC( SDL_GETWINDOWPIXELFORMAT )
{

}

HB_FUNC( SDL_GETWINDOWPOSITION )
{

}

HB_FUNC( SDL_GETWINDOWPROPERTIES )
{

}

HB_FUNC( SDL_GETWINDOWRELATIVEMOUSEMODE )
{

}

HB_FUNC( SDL_GETWINDOWS )
{

}

HB_FUNC( SDL_GETWINDOWSAFEAREA )
{

}

HB_FUNC( SDL_GETWINDOWSIZE )
{

}

HB_FUNC( SDL_GETWINDOWSIZEINPIXELS )
{

}

HB_FUNC( SDL_GETWINDOWSURFACE )
{

}

HB_FUNC( SDL_GETWINDOWSURFACEVSYNC )
{

}

HB_FUNC( SDL_GETWINDOWTITLE )
{

}

HB_FUNC( SDL_GL_CREATECONTEXT )
{

}

HB_FUNC( SDL_GL_DESTROYCONTEXT )
{

}

HB_FUNC( SDL_GL_EXTENSIONSUPPORTED )
{

}

HB_FUNC( SDL_GL_GETATTRIBUTE )
{

}

HB_FUNC( SDL_GL_GETCURRENTCONTEXT )
{

}

HB_FUNC( SDL_GL_GETCURRENTWINDOW )
{

}

HB_FUNC( SDL_GL_GETPROCADDRESS )
{

}

HB_FUNC( SDL_GL_GETSWAPINTERVAL )
{

}

HB_FUNC( SDL_GL_LOADLIBRARY )
{

}

HB_FUNC( SDL_GL_MAKECURRENT )
{

}

HB_FUNC( SDL_GL_RESETATTRIBUTES )
{

}

HB_FUNC( SDL_GL_SETATTRIBUTE )
{

}

HB_FUNC( SDL_GL_SETSWAPINTERVAL )
{

}

HB_FUNC( SDL_GL_SWAPWINDOW )
{

}

HB_FUNC( SDL_GL_UNLOADLIBRARY )
{

}

HB_FUNC( SDL_GLOBDIRECTORY )
{

}

HB_FUNC( SDL_GLOBSTORAGEDIRECTORY )
{

}

HB_FUNC( SDL_GPUSUPPORTSPROPERTIES )
{

}

HB_FUNC( SDL_GPUSUPPORTSSHADERFORMATS )
{

}

HB_FUNC( SDL_GPUTEXTUREFORMATTEXELBLOCKSIZE )
{

}

HB_FUNC( SDL_GPUTEXTURESUPPORTSFORMAT )
{

}

HB_FUNC( SDL_GPUTEXTURESUPPORTSSAMPLECOUNT )
{

}

HB_FUNC( SDL_GUIDTOSTRING )
{

}

HB_FUNC( SDL_HAPTICEFFECTSUPPORTED )
{

}

HB_FUNC( SDL_HAPTICRUMBLESUPPORTED )
{

}

HB_FUNC( SDL_HASALTIVEC )
{

}

HB_FUNC( SDL_HASARMSIMD )
{

}

HB_FUNC( SDL_HASAVX )
{

}

HB_FUNC( SDL_HASAVX2 )
{

}

HB_FUNC( SDL_HASAVX512F )
{

}

HB_FUNC( SDL_HASCLIPBOARDDATA )
{

}

HB_FUNC( SDL_HASCLIPBOARDTEXT )
{

}

HB_FUNC( SDL_HASEVENT )
{

}

HB_FUNC( SDL_HASEVENTS )
{

}

HB_FUNC( SDL_HASEXACTLYONEBITSET32 )
{

}

HB_FUNC( SDL_HASGAMEPAD )
{

}

HB_FUNC( SDL_HASJOYSTICK )
{

}

HB_FUNC( SDL_HASKEYBOARD )
{

}

HB_FUNC( SDL_HASLASX )
{

}

HB_FUNC( SDL_HASLSX )
{

}

HB_FUNC( SDL_HASMMX )
{

}

HB_FUNC( SDL_HASMOUSE )
{

}

HB_FUNC( SDL_HASNEON )
{

}

HB_FUNC( SDL_HASPRIMARYSELECTIONTEXT )
{

}

HB_FUNC( SDL_HASPROPERTY )
{

}

HB_FUNC( SDL_HASRECTINTERSECTION )
{

}

HB_FUNC( SDL_HASRECTINTERSECTIONFLOAT )
{

}

HB_FUNC( SDL_HASSCREENKEYBOARDSUPPORT )
{

}

HB_FUNC( SDL_HASSSE )
{

}

HB_FUNC( SDL_HASSSE2 )
{

}

HB_FUNC( SDL_HASSSE3 )
{

}

HB_FUNC( SDL_HASSSE41 )
{

}

HB_FUNC( SDL_HASSSE42 )
{

}

HB_FUNC( SDL_HID_BLE_SCAN )
{

}

HB_FUNC( SDL_HID_CLOSE )
{

}

HB_FUNC( SDL_HID_DEVICE_CHANGE_COUNT )
{

}

HB_FUNC( SDL_HID_ENUMERATE )
{

}

HB_FUNC( SDL_HID_EXIT )
{

}

HB_FUNC( SDL_HID_FREE_ENUMERATION )
{

}

HB_FUNC( SDL_HID_GET_DEVICE_INFO )
{

}

HB_FUNC( SDL_HID_GET_FEATURE_REPORT )
{

}

HB_FUNC( SDL_HID_GET_INDEXED_STRING )
{

}

HB_FUNC( SDL_HID_GET_INPUT_REPORT )
{

}

HB_FUNC( SDL_HID_GET_MANUFACTURER_STRING )
{

}

HB_FUNC( SDL_HID_GET_PRODUCT_STRING )
{

}

HB_FUNC( SDL_HID_GET_REPORT_DESCRIPTOR )
{

}

HB_FUNC( SDL_HID_GET_SERIAL_NUMBER_STRING )
{

}

HB_FUNC( SDL_HID_INIT )
{

}

HB_FUNC( SDL_HID_OPEN )
{

}

HB_FUNC( SDL_HID_OPEN_PATH )
{

}

HB_FUNC( SDL_HID_READ )
{

}

HB_FUNC( SDL_HID_READ_TIMEOUT )
{

}

HB_FUNC( SDL_HID_SEND_FEATURE_REPORT )
{

}

HB_FUNC( SDL_HID_SET_NONBLOCKING )
{

}

HB_FUNC( SDL_HID_WRITE )
{

}

HB_FUNC( SDL_HIDECURSOR )
{

}

HB_FUNC( SDL_HIDEWINDOW )
{

}

HB_FUNC( SDL_ICONV )
{

}

HB_FUNC( SDL_ICONV_CLOSE )
{

}

HB_FUNC( SDL_ICONV_OPEN )
{

}

HB_FUNC( SDL_ICONV_STRING )
{

}

// bool SDL_Init( SDL_InitFlags flags );
HB_FUNC( SDL_INIT )
{
   if( hb_param( 1, HB_IT_NUMINT ) != NULL )
   {
      hb_retl( SDL_Init( ( Uint32 ) hb_parni( 1 ) ) );
   }
   else
   {
      HB_ERR_ARGS();
   }
}

HB_FUNC( SDL_INITHAPTICRUMBLE )
{

}

HB_FUNC( SDL_INITSUBSYSTEM )
{

}

HB_FUNC( SDL_INSERTGPUDEBUGLABEL )
{

}

HB_FUNC( SDL_IOFROMCONSTMEM )
{

}

HB_FUNC( SDL_IOFROMDYNAMICMEM )
{

}

HB_FUNC( SDL_IOFROMFILE )
{

}

HB_FUNC( SDL_IOFROMMEM )
{

}

HB_FUNC( SDL_IOPRINTF )
{

}

HB_FUNC( SDL_IOVPRINTF )
{

}

HB_FUNC( SDL_ISALNUM )
{

}

HB_FUNC( SDL_ISALPHA )
{

}

HB_FUNC( SDL_ISAUDIODEVICEPHYSICAL )
{

}

HB_FUNC( SDL_ISAUDIODEVICEPLAYBACK )
{

}

HB_FUNC( SDL_ISBLANK )
{

}

HB_FUNC( SDL_ISCHROMEBOOK )
{

}

HB_FUNC( SDL_ISCNTRL )
{

}

HB_FUNC( SDL_ISDEXMODE )
{

}

HB_FUNC( SDL_ISDIGIT )
{

}

HB_FUNC( SDL_ISGAMEPAD )
{

}

HB_FUNC( SDL_ISGRAPH )
{

}

HB_FUNC( SDL_ISINF )
{

}

HB_FUNC( SDL_ISINFF )
{

}

HB_FUNC( SDL_ISJOYSTICKHAPTIC )
{

}

HB_FUNC( SDL_ISJOYSTICKVIRTUAL )
{

}

HB_FUNC( SDL_ISLOWER )
{

}

HB_FUNC( SDL_ISMAINTHREAD )
{

}

HB_FUNC( SDL_ISMOUSEHAPTIC )
{

}

HB_FUNC( SDL_ISNAN )
{

}

HB_FUNC( SDL_ISNANF )
{

}

HB_FUNC( SDL_ISPRINT )
{

}

HB_FUNC( SDL_ISPUNCT )
{

}

HB_FUNC( SDL_ISSPACE )
{

}

HB_FUNC( SDL_ISTABLET )
{

}

HB_FUNC( SDL_ISTV )
{

}

HB_FUNC( SDL_ISUPPER )
{

}

HB_FUNC( SDL_ISXDIGIT )
{

}

HB_FUNC( SDL_JOYSTICKCONNECTED )
{

}

HB_FUNC( SDL_JOYSTICKEVENTSENABLED )
{

}

HB_FUNC( SDL_KILLPROCESS )
{

}

HB_FUNC( SDL_LOADBMP )
{

}

HB_FUNC( SDL_LOADBMP_IO )
{

}

HB_FUNC( SDL_LOADFILE )
{

}

HB_FUNC( SDL_LOADFILE_IO )
{

}

HB_FUNC( SDL_LOADFILEASYNC )
{

}

HB_FUNC( SDL_LOADFUNCTION )
{

}

HB_FUNC( SDL_LOADOBJECT )
{

}

HB_FUNC( SDL_LOADWAV )
{

}

HB_FUNC( SDL_LOADWAV_IO )
{

}

HB_FUNC( SDL_LOCKAUDIOSTREAM )
{

}

HB_FUNC( SDL_LOCKJOYSTICKS )
{

}

HB_FUNC( SDL_LOCKMUTEX )
{

}

HB_FUNC( SDL_LOCKPROPERTIES )
{

}

HB_FUNC( SDL_LOCKRWLOCKFORREADING )
{

}

HB_FUNC( SDL_LOCKRWLOCKFORWRITING )
{

}

HB_FUNC( SDL_LOCKSPINLOCK )
{

}

HB_FUNC( SDL_LOCKSURFACE )
{

}

HB_FUNC( SDL_LOCKTEXTURE )
{

}

HB_FUNC( SDL_LOCKTEXTURETOSURFACE )
{

}

// HB_FUNC( SDL_LOG )
// {
// }

HB_FUNC( SDL_LOG )
{

}

HB_FUNC( SDL_LOG10 )
{

}

HB_FUNC( SDL_LOG10F )
{

}

HB_FUNC( SDL_LOGCRITICAL )
{

}

HB_FUNC( SDL_LOGDEBUG )
{

}

HB_FUNC( SDL_LOGERROR )
{

}

HB_FUNC( SDL_LOGF )
{

}

HB_FUNC( SDL_LOGINFO )
{

}

HB_FUNC( SDL_LOGMESSAGE )
{

}

HB_FUNC( SDL_LOGMESSAGEV )
{

}

HB_FUNC( SDL_LOGTRACE )
{

}

HB_FUNC( SDL_LOGVERBOSE )
{

}

HB_FUNC( SDL_LOGWARN )
{

}

HB_FUNC( SDL_LROUND )
{

}

HB_FUNC( SDL_LROUNDF )
{

}

HB_FUNC( SDL_MAIN )
{

}

HB_FUNC( SDL_MALLOC )
{

}

HB_FUNC( SDL_MAPGPUTRANSFERBUFFER )
{

}

HB_FUNC( SDL_MAPRGB )
{

}

HB_FUNC( SDL_MAPRGBA )
{

}

HB_FUNC( SDL_MAPSURFACERGB )
{

}

HB_FUNC( SDL_MAPSURFACERGBA )
{

}

HB_FUNC( SDL_MAXIMIZEWINDOW )
{

}

HB_FUNC( SDL_MEMCPY )
{

}

HB_FUNC( SDL_MEMMOVE )
{

}

HB_FUNC( SDL_MEMORYBARRIERACQUIREFUNCTION )
{

}

HB_FUNC( SDL_MEMORYBARRIERRELEASEFUNCTION )
{

}

HB_FUNC( SDL_METAL_CREATEVIEW )
{

}

HB_FUNC( SDL_METAL_DESTROYVIEW )
{

}

HB_FUNC( SDL_METAL_GETLAYER )
{

}

// bool SDL_MinimizeWindow( SDL_Window *window );
HB_FUNC( SDL_MINIMIZEWINDOW )
{
   if( hb_param( 1, HB_IT_POINTER ) != NULL )
   {
      hb_retl( SDL_MinimizeWindow( hb_sdl_window_ParamPtr( 1 ) ) );
   }
   else
   {
      HB_ERR_ARGS();
   }
}

HB_FUNC( SDL_MIXAUDIO )
{

}

HB_FUNC( SDL_MODF )
{

}

HB_FUNC( SDL_MODFF )
{

}

HB_FUNC( SDL_MOSTSIGNIFICANTBITINDEX32 )
{

}

HB_FUNC( SDL_ONAPPLICATIONDIDCHANGESTATUSBARORIENTATION )
{

}

HB_FUNC( SDL_ONAPPLICATIONDIDENTERBACKGROUND )
{

}

HB_FUNC( SDL_ONAPPLICATIONDIDENTERFOREGROUND )
{

}

HB_FUNC( SDL_ONAPPLICATIONDIDRECEIVEMEMORYWARNING )
{

}

HB_FUNC( SDL_ONAPPLICATIONWILLENTERBACKGROUND )
{

}

HB_FUNC( SDL_ONAPPLICATIONWILLENTERFOREGROUND )
{

}

HB_FUNC( SDL_ONAPPLICATIONWILLTERMINATE )
{

}

HB_FUNC( SDL_OPENAUDIODEVICE )
{

}

HB_FUNC( SDL_OPENAUDIODEVICESTREAM )
{

}

HB_FUNC( SDL_OPENCAMERA )
{

}

HB_FUNC( SDL_OPENFILESTORAGE )
{

}

HB_FUNC( SDL_OPENGAMEPAD )
{

}

HB_FUNC( SDL_OPENHAPTIC )
{

}

HB_FUNC( SDL_OPENHAPTICFROMJOYSTICK )
{

}

HB_FUNC( SDL_OPENHAPTICFROMMOUSE )
{

}

HB_FUNC( SDL_OPENIO )
{

}

HB_FUNC( SDL_OPENJOYSTICK )
{

}

HB_FUNC( SDL_OPENSENSOR )
{

}

HB_FUNC( SDL_OPENSTORAGE )
{

}

HB_FUNC( SDL_OPENTITLESTORAGE )
{

}

HB_FUNC( SDL_OPENURL )
{

}

HB_FUNC( SDL_OPENUSERSTORAGE )
{

}

HB_FUNC( SDL_OUTOFMEMORY )
{

}

HB_FUNC( SDL_PAUSEAUDIODEVICE )
{

}

HB_FUNC( SDL_PAUSEAUDIOSTREAMDEVICE )
{

}

HB_FUNC( SDL_PAUSEHAPTIC )
{

}

HB_FUNC( SDL_PEEPEVENTS )
{

}

HB_FUNC( SDL_PLAYHAPTICRUMBLE )
{

}

HB_FUNC( SDL_POINTINRECT )
{

}

HB_FUNC( SDL_POINTINRECTFLOAT )
{

}

// bool SDL_PollEvent( SDL_Event *event );
HB_FUNC( SDL_POLLEVENT )
{
   if( hb_param( 1, HB_IT_BYREF ) != NULL )
   {
      SDL_Event *pEvent = ( SDL_Event * ) hb_xgrab( sizeof( SDL_Event ) );

      if( SDL_PollEvent( pEvent ) )
      {
         hb_retl( T );
         hb_sdl_event_StorPtr( pEvent, 1 );
      }
      else
      {
         hb_xfree( pEvent );
         hb_retl( F );
      }
   }
   else
   {
      HB_ERR_ARGS();
   }
}

HB_FUNC( SDL_POPGPUDEBUGGROUP )
{

}

HB_FUNC( SDL_POW )
{

}

HB_FUNC( SDL_POWF )
{

}

HB_FUNC( SDL_PREMULTIPLYALPHA )
{

}

HB_FUNC( SDL_PREMULTIPLYSURFACEALPHA )
{

}

HB_FUNC( SDL_PUMPEVENTS )
{

}

HB_FUNC( SDL_PUSHEVENT )
{

}

HB_FUNC( SDL_PUSHGPUCOMPUTEUNIFORMDATA )
{

}

HB_FUNC( SDL_PUSHGPUDEBUGGROUP )
{

}

HB_FUNC( SDL_PUSHGPUFRAGMENTUNIFORMDATA )
{

}

HB_FUNC( SDL_PUSHGPUVERTEXUNIFORMDATA )
{

}

HB_FUNC( SDL_PUTAUDIOSTREAMDATA )
{

}

HB_FUNC( SDL_QSORT )
{

}

HB_FUNC( SDL_QSORT_R )
{

}

HB_FUNC( SDL_QUERYGPUFENCE )
{

}

// void SDL_Quit( void );
HB_FUNC( SDL_QUIT )
{
   SDL_Quit();
}

HB_FUNC( SDL_QUITSUBSYSTEM )
{

}

HB_FUNC( SDL_RAISEWINDOW )
{

}

HB_FUNC( SDL_RAND )
{

}

HB_FUNC( SDL_RAND_BITS )
{

}

HB_FUNC( SDL_RAND_BITS_R )
{

}

HB_FUNC( SDL_RAND_R )
{

}

HB_FUNC( SDL_RANDF )
{

}

HB_FUNC( SDL_RANDF_R )
{

}

HB_FUNC( SDL_READASYNCIO )
{

}

HB_FUNC( SDL_READIO )
{

}

HB_FUNC( SDL_READPROCESS )
{

}

HB_FUNC( SDL_READS16BE )
{

}

HB_FUNC( SDL_READS16LE )
{

}

HB_FUNC( SDL_READS32BE )
{

}

HB_FUNC( SDL_READS32LE )
{

}

HB_FUNC( SDL_READS64BE )
{

}

HB_FUNC( SDL_READS64LE )
{

}

HB_FUNC( SDL_READS8 )
{

}

HB_FUNC( SDL_READSTORAGEFILE )
{

}

HB_FUNC( SDL_READSURFACEPIXEL )
{

}

HB_FUNC( SDL_READSURFACEPIXELFLOAT )
{

}

HB_FUNC( SDL_READU16BE )
{

}

HB_FUNC( SDL_READU16LE )
{

}

HB_FUNC( SDL_READU32BE )
{

}

HB_FUNC( SDL_READU32LE )
{

}

HB_FUNC( SDL_READU64BE )
{

}

HB_FUNC( SDL_READU64LE )
{

}

HB_FUNC( SDL_READU8 )
{

}

HB_FUNC( SDL_REALLOC )
{

}

HB_FUNC( SDL_RECTEMPTY )
{

}

HB_FUNC( SDL_RECTEMPTYFLOAT )
{

}

HB_FUNC( SDL_RECTSEQUAL )
{

}

HB_FUNC( SDL_RECTSEQUALEPSILON )
{

}

HB_FUNC( SDL_RECTSEQUALFLOAT )
{

}

HB_FUNC( SDL_RECTTOFRECT )
{

}

HB_FUNC( SDL_REGISTERAPP )
{

}

HB_FUNC( SDL_REGISTEREVENTS )
{

}

HB_FUNC( SDL_RELEASECAMERAFRAME )
{

}

HB_FUNC( SDL_RELEASEGPUBUFFER )
{

}

HB_FUNC( SDL_RELEASEGPUCOMPUTEPIPELINE )
{

}

HB_FUNC( SDL_RELEASEGPUFENCE )
{

}

HB_FUNC( SDL_RELEASEGPUGRAPHICSPIPELINE )
{

}

HB_FUNC( SDL_RELEASEGPUSAMPLER )
{

}

HB_FUNC( SDL_RELEASEGPUSHADER )
{

}

HB_FUNC( SDL_RELEASEGPUTEXTURE )
{

}

HB_FUNC( SDL_RELEASEGPUTRANSFERBUFFER )
{

}

HB_FUNC( SDL_RELEASEWINDOWFROMGPUDEVICE )
{

}

HB_FUNC( SDL_RELOADGAMEPADMAPPINGS )
{

}

HB_FUNC( SDL_REMOVEEVENTWATCH )
{

}

HB_FUNC( SDL_REMOVEHINTCALLBACK )
{

}

HB_FUNC( SDL_REMOVEPATH )
{

}

HB_FUNC( SDL_REMOVESTORAGEPATH )
{

}

HB_FUNC( SDL_REMOVESURFACEALTERNATEIMAGES )
{

}

HB_FUNC( SDL_REMOVETIMER )
{

}

HB_FUNC( SDL_RENAMEPATH )
{

}

HB_FUNC( SDL_RENAMESTORAGEPATH )
{

}

// bool SDL_RenderClear( SDL_Renderer *renderer );
HB_FUNC( SDL_RENDERCLEAR )
{
   if( hb_param( 1, HB_IT_POINTER ) != NULL )
   {
      hb_retl( SDL_RenderClear( hb_sdl_renderer_ParamPtr( 1 ) ) );
   }
   else
   {
      HB_ERR_ARGS();
   }
}

HB_FUNC( SDL_RENDERCLIPENABLED )
{

}

HB_FUNC( SDL_RENDERCOORDINATESFROMWINDOW )
{

}

HB_FUNC( SDL_RENDERCOORDINATESTOWINDOW )
{

}

HB_FUNC( SDL_RENDERDEBUGTEXT )
{

}

HB_FUNC( SDL_RENDERFILLRECT )
{

}

HB_FUNC( SDL_RENDERFILLRECTS )
{

}

HB_FUNC( SDL_RENDERGEOMETRY )
{

}

HB_FUNC( SDL_RENDERGEOMETRYRAW )
{

}

HB_FUNC( SDL_RENDERLINE )
{

}

HB_FUNC( SDL_RENDERLINES )
{

}

HB_FUNC( SDL_RENDERPOINT )
{

}

HB_FUNC( SDL_RENDERPOINTS )
{

}

// bool SDL_RenderPresent( SDL_Renderer *renderer );
HB_FUNC( SDL_RENDERPRESENT )
{
   if( hb_param( 1, HB_IT_POINTER ) != NULL )
   {
      SDL_RenderPresent( hb_sdl_renderer_ParamPtr( 1 ) );
   }
   else
   {
      HB_ERR_ARGS();
   }
}

HB_FUNC( SDL_RENDERREADPIXELS )
{

}

HB_FUNC( SDL_RENDERRECT )
{

}

HB_FUNC( SDL_RENDERRECTS )
{

}

HB_FUNC( SDL_RENDERTEXTURE )
{

}

HB_FUNC( SDL_RENDERTEXTURE9GRID )
{

}

HB_FUNC( SDL_RENDERTEXTUREAFFINE )
{

}

HB_FUNC( SDL_RENDERTEXTUREROTATED )
{

}

HB_FUNC( SDL_RENDERTEXTURETILED )
{

}

HB_FUNC( SDL_RENDERVIEWPORTSET )
{

}

HB_FUNC( SDL_REPORTASSERTION )
{

}

HB_FUNC( SDL_REQUESTANDROIDPERMISSION )
{

}

HB_FUNC( SDL_RESETASSERTIONREPORT )
{

}

HB_FUNC( SDL_RESETHINT )
{

}

HB_FUNC( SDL_RESETHINTS )
{

}

HB_FUNC( SDL_RESETKEYBOARD )
{

}

HB_FUNC( SDL_RESETLOGPRIORITIES )
{

}

HB_FUNC( SDL_RESTOREWINDOW )
{

}

HB_FUNC( SDL_RESUMEAUDIODEVICE )
{

}

HB_FUNC( SDL_RESUMEAUDIOSTREAMDEVICE )
{

}

HB_FUNC( SDL_RESUMEHAPTIC )
{

}

HB_FUNC( SDL_ROUND )
{

}

HB_FUNC( SDL_ROUNDF )
{

}

HB_FUNC( SDL_RUMBLEGAMEPAD )
{

}

HB_FUNC( SDL_RUMBLEGAMEPADTRIGGERS )
{

}

HB_FUNC( SDL_RUMBLEJOYSTICK )
{

}

HB_FUNC( SDL_RUMBLEJOYSTICKTRIGGERS )
{

}

HB_FUNC( SDL_RUNAPP )
{

}

HB_FUNC( SDL_RUNHAPTICEFFECT )
{

}

HB_FUNC( SDL_RUNONMAINTHREAD )
{

}

HB_FUNC( SDL_SAVEBMP )
{

}

HB_FUNC( SDL_SAVEBMP_IO )
{

}

HB_FUNC( SDL_SAVEFILE )
{

}

HB_FUNC( SDL_SAVEFILE_IO )
{

}

HB_FUNC( SDL_SCALBN )
{

}

HB_FUNC( SDL_SCALBNF )
{

}

HB_FUNC( SDL_SCALESURFACE )
{

}

HB_FUNC( SDL_SCREENKEYBOARDSHOWN )
{

}

HB_FUNC( SDL_SCREENSAVERENABLED )
{

}

HB_FUNC( SDL_SEEKIO )
{

}

HB_FUNC( SDL_SENDANDROIDBACKBUTTON )
{

}

HB_FUNC( SDL_SENDANDROIDMESSAGE )
{

}

HB_FUNC( SDL_SENDGAMEPADEFFECT )
{

}

HB_FUNC( SDL_SENDJOYSTICKEFFECT )
{

}

HB_FUNC( SDL_SENDJOYSTICKVIRTUALSENSORDATA )
{

}

HB_FUNC( SDL_SETAPPMETADATA )
{

}

HB_FUNC( SDL_SETAPPMETADATAPROPERTY )
{

}

HB_FUNC( SDL_SETASSERTIONHANDLER )
{

}

HB_FUNC( SDL_SETATOMICINT )
{

}

HB_FUNC( SDL_SETATOMICPOINTER )
{

}

HB_FUNC( SDL_SETATOMICU32 )
{

}

HB_FUNC( SDL_SETAUDIODEVICEGAIN )
{

}

HB_FUNC( SDL_SETAUDIOPOSTMIXCALLBACK )
{

}

HB_FUNC( SDL_SETAUDIOSTREAMFORMAT )
{

}

HB_FUNC( SDL_SETAUDIOSTREAMFREQUENCYRATIO )
{

}

HB_FUNC( SDL_SETAUDIOSTREAMGAIN )
{

}

HB_FUNC( SDL_SETAUDIOSTREAMGETCALLBACK )
{

}

HB_FUNC( SDL_SETAUDIOSTREAMINPUTCHANNELMAP )
{

}

HB_FUNC( SDL_SETAUDIOSTREAMOUTPUTCHANNELMAP )
{

}

HB_FUNC( SDL_SETAUDIOSTREAMPUTCALLBACK )
{

}

HB_FUNC( SDL_SETBOOLEANPROPERTY )
{

}

HB_FUNC( SDL_SETCLIPBOARDDATA )
{

}

HB_FUNC( SDL_SETCLIPBOARDTEXT )
{

}

HB_FUNC( SDL_SETCURRENTTHREADPRIORITY )
{

}

HB_FUNC( SDL_SETCURSOR )
{

}

HB_FUNC( SDL_SETENV_UNSAFE )
{

}

HB_FUNC( SDL_SETENVIRONMENTVARIABLE )
{

}

HB_FUNC( SDL_SETERROR )
{

}

HB_FUNC( SDL_SETERRORV )
{

}

HB_FUNC( SDL_SETEVENTENABLED )
{

}

HB_FUNC( SDL_SETEVENTFILTER )
{

}

HB_FUNC( SDL_SETFLOATPROPERTY )
{

}

HB_FUNC( SDL_SETGAMEPADEVENTSENABLED )
{

}

HB_FUNC( SDL_SETGAMEPADLED )
{

}

HB_FUNC( SDL_SETGAMEPADMAPPING )
{

}

HB_FUNC( SDL_SETGAMEPADPLAYERINDEX )
{

}

HB_FUNC( SDL_SETGAMEPADSENSORENABLED )
{

}

HB_FUNC( SDL_SETGPUALLOWEDFRAMESINFLIGHT )
{

}

HB_FUNC( SDL_SETGPUBLENDCONSTANTS )
{

}

HB_FUNC( SDL_SETGPUBUFFERNAME )
{

}

HB_FUNC( SDL_SETGPUSCISSOR )
{

}

HB_FUNC( SDL_SETGPUSTENCILREFERENCE )
{

}

HB_FUNC( SDL_SETGPUSWAPCHAINPARAMETERS )
{

}

HB_FUNC( SDL_SETGPUTEXTURENAME )
{

}

HB_FUNC( SDL_SETGPUVIEWPORT )
{

}

HB_FUNC( SDL_SETHAPTICAUTOCENTER )
{

}

HB_FUNC( SDL_SETHAPTICGAIN )
{

}

// bool SDL_SetHint( const char *name, const char *value );
HB_FUNC( SDL_SETHINT )
{
   if( hb_param( 1, HB_IT_STRING ) != NULL && hb_param( 2, HB_IT_STRING ) != NULL )
   {
      hb_retl( SDL_SetHint( hb_parc( 1 ), hb_parc( 2 ) ) );
   }
   else
   {
      HB_ERR_ARGS();
   }
}

HB_FUNC( SDL_SETHINTWITHPRIORITY )
{

}

HB_FUNC( SDL_SETINITIALIZED )
{

}

HB_FUNC( SDL_SETIOSANIMATIONCALLBACK )
{

}

HB_FUNC( SDL_SETIOSEVENTPUMP )
{

}

HB_FUNC( SDL_SETJOYSTICKEVENTSENABLED )
{

}

HB_FUNC( SDL_SETJOYSTICKLED )
{

}

HB_FUNC( SDL_SETJOYSTICKPLAYERINDEX )
{

}

HB_FUNC( SDL_SETJOYSTICKVIRTUALAXIS )
{

}

HB_FUNC( SDL_SETJOYSTICKVIRTUALBALL )
{

}

HB_FUNC( SDL_SETJOYSTICKVIRTUALBUTTON )
{

}

HB_FUNC( SDL_SETJOYSTICKVIRTUALHAT )
{

}

HB_FUNC( SDL_SETJOYSTICKVIRTUALTOUCHPAD )
{

}

HB_FUNC( SDL_SETLINUXTHREADPRIORITY )
{

}

HB_FUNC( SDL_SETLINUXTHREADPRIORITYANDPOLICY )
{

}

HB_FUNC( SDL_SETLOGOUTPUTFUNCTION )
{

}

HB_FUNC( SDL_SETLOGPRIORITIES )
{

}

HB_FUNC( SDL_SETLOGPRIORITY )
{

}

HB_FUNC( SDL_SETLOGPRIORITYPREFIX )
{

}

HB_FUNC( SDL_SETMAINREADY )
{

}

HB_FUNC( SDL_SETMEMORYFUNCTIONS )
{

}

HB_FUNC( SDL_SETMODSTATE )
{

}

HB_FUNC( SDL_SETNUMBERPROPERTY )
{

}

HB_FUNC( SDL_SETPALETTECOLORS )
{

}

HB_FUNC( SDL_SETPOINTERPROPERTY )
{

}

HB_FUNC( SDL_SETPOINTERPROPERTYWITHCLEANUP )
{

}

HB_FUNC( SDL_SETPRIMARYSELECTIONTEXT )
{

}

HB_FUNC( SDL_SETRENDERCLIPRECT )
{

}

HB_FUNC( SDL_SETRENDERCOLORSCALE )
{

}

HB_FUNC( SDL_SETRENDERDRAWBLENDMODE )
{

}

// bool SDL_SetRenderDrawColor( SDL_Renderer *renderer, Uint8 r, Uint8 g, Uint8 b, Uint8 a );
HB_FUNC( SDL_SETRENDERDRAWCOLOR )
{
   if( hb_param( 1, HB_IT_POINTER ) != NULL &&
       hb_param( 2, HB_IT_INTEGER ) != NULL &&
       hb_param( 3, HB_IT_INTEGER ) != NULL &&
       hb_param( 4, HB_IT_INTEGER ) != NULL &&
       hb_param( 5, HB_IT_INTEGER ) != NULL )
   {
      SDL_Renderer *pRenderer = hb_sdl_renderer_ParamPtr( 1 );
      int r = ( Uint8 ) hb_parni( 2 );
      int g = ( Uint8 ) hb_parni( 3 );
      int b = ( Uint8 ) hb_parni( 4 );
      int a = ( Uint8 ) hb_parni( 5 );

      if( r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255 || a < 0 || a > 255 )
      {
         HB_ERR_ARGS();
      }
      else
      {
         hb_retl( SDL_SetRenderDrawColor( pRenderer, r, g, b, a ) );
      }
   }
   else
   {
      HB_ERR_ARGS();
   }
}

// bool SDL_SetRenderDrawColorFloat( SDL_Renderer *renderer, float r, float g, float b, float a );
HB_FUNC( SDL_SETRENDERDRAWCOLORFLOAT )
{
   if( hb_param( 1, HB_IT_POINTER ) != NULL &&
       hb_param( 2, HB_IT_NUMERIC ) != NULL &&
       hb_param( 3, HB_IT_NUMERIC ) != NULL &&
       hb_param( 4, HB_IT_NUMERIC ) != NULL &&
       hb_param( 5, HB_IT_NUMERIC ) != NULL )
   {
      SDL_Renderer *pRenderer = hb_sdl_renderer_ParamPtr( 1 );
      float r = ( float ) hb_parnd( 2 );
      float g = ( float ) hb_parnd( 3 );
      float b = ( float ) hb_parnd( 4 );
      float a = ( float ) hb_parnd( 5 );

      hb_retl( SDL_SetRenderDrawColorFloat( pRenderer, r, g, b, a ) );
   }
   else
   {
      HB_ERR_ARGS();
   }
}

HB_FUNC( SDL_SETRENDERLOGICALPRESENTATION )
{

}

HB_FUNC( SDL_SETRENDERSCALE )
{

}

HB_FUNC( SDL_SETRENDERTARGET )
{

}

HB_FUNC( SDL_SETRENDERVIEWPORT )
{

}

HB_FUNC( SDL_SETRENDERVSYNC )
{

}

HB_FUNC( SDL_SETSCANCODENAME )
{

}

HB_FUNC( SDL_SETSTRINGPROPERTY )
{

}

HB_FUNC( SDL_SETSURFACEALPHAMOD )
{

}

HB_FUNC( SDL_SETSURFACEBLENDMODE )
{

}

HB_FUNC( SDL_SETSURFACECLIPRECT )
{

}

HB_FUNC( SDL_SETSURFACECOLORKEY )
{

}

HB_FUNC( SDL_SETSURFACECOLORMOD )
{

}

HB_FUNC( SDL_SETSURFACECOLORSPACE )
{

}

HB_FUNC( SDL_SETSURFACEPALETTE )
{

}

HB_FUNC( SDL_SETSURFACERLE )
{

}

HB_FUNC( SDL_SETTEXTINPUTAREA )
{

}

HB_FUNC( SDL_SETTEXTUREALPHAMOD )
{

}

HB_FUNC( SDL_SETTEXTUREALPHAMODFLOAT )
{

}

HB_FUNC( SDL_SETTEXTUREBLENDMODE )
{

}

HB_FUNC( SDL_SETTEXTURECOLORMOD )
{

}

HB_FUNC( SDL_SETTEXTURECOLORMODFLOAT )
{

}

HB_FUNC( SDL_SETTEXTURESCALEMODE )
{

}

HB_FUNC( SDL_SETTLS )
{

}

HB_FUNC( SDL_SETWINDOWALWAYSONTOP )
{

}

HB_FUNC( SDL_SETWINDOWASPECTRATIO )
{

}

HB_FUNC( SDL_SETWINDOWBORDERED )
{

}

HB_FUNC( SDL_SETWINDOWFOCUSABLE )
{

}

// bool SDL_SetWindowFullscreen( SDL_Window *window, bool fullscreen );
HB_FUNC( SDL_SETWINDOWFULLSCREEN )
{
   if( hb_param( 1, HB_IT_POINTER ) != NULL && hb_param( 2, HB_IT_LOGICAL ) != NULL  )
   {
      hb_retl( SDL_SetWindowFullscreen( hb_sdl_window_ParamPtr( 1 ), hb_parl( 2 ) ) );
   }
   else
   {
      HB_ERR_ARGS();
   }
}

HB_FUNC( SDL_SETWINDOWFULLSCREENMODE )
{

}

HB_FUNC( SDL_SETWINDOWHITTEST )
{

}

HB_FUNC( SDL_SETWINDOWICON )
{

}

HB_FUNC( SDL_SETWINDOWKEYBOARDGRAB )
{

}

// bool SDL_SetWindowMaximumSize( SDL_Window *window, int max_w, int max_h );
HB_FUNC( SDL_SETWINDOWMAXIMUMSIZE )
{
   if( hb_param( 1, HB_IT_POINTER ) != NULL && hb_param( 2, HB_IT_INTEGER ) != NULL && hb_param( 3, HB_IT_INTEGER ) != NULL )
   {
      hb_retl( SDL_SetWindowMaximumSize( hb_sdl_window_ParamPtr( 1 ), hb_parni( 2 ), hb_parni( 3 ) ) );
   }
   else
   {
      HB_ERR_ARGS();
   }
}

// bool SDL_SetWindowMinimumSize( SDL_Window *window, int min_w, int min_h );
HB_FUNC( SDL_SETWINDOWMINIMUMSIZE )
{
   if( hb_param( 1, HB_IT_POINTER ) != NULL && hb_param( 2, HB_IT_INTEGER ) != NULL && hb_param( 3, HB_IT_INTEGER ) != NULL )
   {
      hb_retl( SDL_SetWindowMinimumSize( hb_sdl_window_ParamPtr( 1 ), hb_parni( 2 ), hb_parni( 3 ) ) );
   }
   else
   {
      HB_ERR_ARGS();
   }
}

HB_FUNC( SDL_SETWINDOWMODAL )
{

}

HB_FUNC( SDL_SETWINDOWMOUSEGRAB )
{

}

HB_FUNC( SDL_SETWINDOWMOUSERECT )
{

}

HB_FUNC( SDL_SETWINDOWOPACITY )
{

}

HB_FUNC( SDL_SETWINDOWPARENT )
{

}

bool SDL_SetWindowPosition( SDL_Window *window, int x, int y );
HB_FUNC( SDL_SETWINDOWPOSITION )
{
   if( hb_param( 1, HB_IT_POINTER ) != NULL && hb_param( 2, HB_IT_INTEGER ) != NULL && hb_param( 3, HB_IT_INTEGER ) != NULL )
   {
      hb_retl( SDL_SetWindowPosition( hb_sdl_window_ParamPtr( 1 ), hb_parni( 2 ), hb_parni( 3 ) ) );
   }
   else
   {
      HB_ERR_ARGS();
   }
}

HB_FUNC( SDL_SETWINDOWRELATIVEMOUSEMODE )
{

}

HB_FUNC( SDL_SETWINDOWRESIZABLE )
{

}

HB_FUNC( SDL_SETWINDOWSHAPE )
{

}

// bool SDL_SetWindowSize( SDL_Window *window, int w, int h );
HB_FUNC( SDL_SETWINDOWSIZE )
{
   if( hb_param( 1, HB_IT_POINTER ) != NULL && hb_param( 2, HB_IT_INTEGER ) != NULL && hb_param( 3, HB_IT_INTEGER ) != NULL )
   {
      hb_retl( SDL_SetWindowSize( hb_sdl_window_ParamPtr( 1 ), hb_parni( 2 ), hb_parni( 3 ) ) );
   }
   else
   {
      HB_ERR_ARGS();
   }
}

HB_FUNC( SDL_SETWINDOWSMESSAGEHOOK )
{

}

HB_FUNC( SDL_SETWINDOWSURFACEVSYNC )
{

}

HB_FUNC( SDL_SETWINDOWTITLE )
{

}

HB_FUNC( SDL_SETX11EVENTHOOK )
{

}

HB_FUNC( SDL_SHOULDINIT )
{

}

HB_FUNC( SDL_SHOULDQUIT )
{

}

HB_FUNC( SDL_SHOWANDROIDTOAST )
{

}

HB_FUNC( SDL_SHOWCURSOR )
{

}

HB_FUNC( SDL_SHOWFILEDIALOGWITHPROPERTIES )
{

}

HB_FUNC( SDL_SHOWMESSAGEBOX )
{

}

HB_FUNC( SDL_SHOWOPENFILEDIALOG )
{

}

HB_FUNC( SDL_SHOWOPENFOLDERDIALOG )
{

}

HB_FUNC( SDL_SHOWSAVEFILEDIALOG )
{

}

HB_FUNC( SDL_SHOWSIMPLEMESSAGEBOX )
{

}

HB_FUNC( SDL_SHOWWINDOW )
{

}

HB_FUNC( SDL_SHOWWINDOWSYSTEMMENU )
{

}

HB_FUNC( SDL_SIGNALASYNCIOQUEUE )
{

}

HB_FUNC( SDL_SIGNALCONDITION )
{

}

HB_FUNC( SDL_SIGNALSEMAPHORE )
{

}

HB_FUNC( SDL_SIN )
{

}

HB_FUNC( SDL_SINF )
{

}

HB_FUNC( SDL_SIZE_ADD_CHECK_OVERFLOW )
{

}

HB_FUNC( SDL_SIZE_MUL_CHECK_OVERFLOW )
{

}

HB_FUNC( SDL_SQRT )
{

}

HB_FUNC( SDL_SQRTF )
{

}

HB_FUNC( SDL_SRAND )
{

}

HB_FUNC( SDL_STARTTEXTINPUT )
{

}

HB_FUNC( SDL_STARTTEXTINPUTWITHPROPERTIES )
{

}

HB_FUNC( SDL_STEPBACKUTF8 )
{

}

HB_FUNC( SDL_STEPUTF8 )
{

}

HB_FUNC( SDL_STOPHAPTICEFFECT )
{

}

HB_FUNC( SDL_STOPHAPTICEFFECTS )
{

}

HB_FUNC( SDL_STOPHAPTICRUMBLE )
{

}

HB_FUNC( SDL_STOPTEXTINPUT )
{

}

HB_FUNC( SDL_STORAGEREADY )
{

}

HB_FUNC( SDL_STRCASECMP )
{

}

HB_FUNC( SDL_STRCMP )
{

}

HB_FUNC( SDL_STRINGTOGUID )
{

}

HB_FUNC( SDL_STRLCAT )
{

}

HB_FUNC( SDL_STRLCPY )
{

}

HB_FUNC( SDL_STRLEN )
{

}

HB_FUNC( SDL_STRLWR )
{

}

HB_FUNC( SDL_STRNCASECMP )
{

}

HB_FUNC( SDL_STRNCMP )
{

}

HB_FUNC( SDL_STRNLEN )
{

}

HB_FUNC( SDL_STRPBRK )
{

}

HB_FUNC( SDL_STRTOD )
{

}

HB_FUNC( SDL_STRTOL )
{

}

HB_FUNC( SDL_STRTOLL )
{

}

HB_FUNC( SDL_STRTOUL )
{

}

HB_FUNC( SDL_STRTOULL )
{

}

HB_FUNC( SDL_STRUPR )
{

}

HB_FUNC( SDL_SUBMITGPUCOMMANDBUFFER )
{

}

HB_FUNC( SDL_SUBMITGPUCOMMANDBUFFERANDACQUIREFENCE )
{

}

HB_FUNC( SDL_SURFACEHASALTERNATEIMAGES )
{

}

HB_FUNC( SDL_SURFACEHASCOLORKEY )
{

}

HB_FUNC( SDL_SURFACEHASRLE )
{

}

HB_FUNC( SDL_SWAP16 )
{

}

HB_FUNC( SDL_SWAP32 )
{

}

HB_FUNC( SDL_SWAP64 )
{

}

HB_FUNC( SDL_SWAPFLOAT )
{

}

// bool SDL_SyncWindow( SDL_Window *window );
HB_FUNC( SDL_SYNCWINDOW )
{
   if( hb_param( 1, HB_IT_POINTER ) != NULL )
   {
      hb_retl( SDL_SyncWindow( hb_sdl_window_ParamPtr( 1 ) ) );
   }
   else
   {
      HB_ERR_ARGS();
   }
}

HB_FUNC( SDL_TAN )
{

}

HB_FUNC( SDL_TANF )
{

}

HB_FUNC( SDL_TELLIO )
{

}

HB_FUNC( SDL_TEXTINPUTACTIVE )
{

}

HB_FUNC( SDL_TIMEFROMWINDOWS )
{

}

HB_FUNC( SDL_TIMETODATETIME )
{

}

HB_FUNC( SDL_TIMETOWINDOWS )
{

}

HB_FUNC( SDL_TOLOWER )
{

}

HB_FUNC( SDL_TOUPPER )
{

}

HB_FUNC( SDL_TRUNC )
{

}

HB_FUNC( SDL_TRUNCF )
{

}

HB_FUNC( SDL_TRYLOCKMUTEX )
{

}

HB_FUNC( SDL_TRYLOCKRWLOCKFORREADING )
{

}

HB_FUNC( SDL_TRYLOCKRWLOCKFORWRITING )
{

}

HB_FUNC( SDL_TRYLOCKSPINLOCK )
{

}

HB_FUNC( SDL_TRYWAITSEMAPHORE )
{

}

HB_FUNC( SDL_UCS4TOUTF8 )
{

}

HB_FUNC( SDL_UNBINDAUDIOSTREAM )
{

}

HB_FUNC( SDL_UNBINDAUDIOSTREAMS )
{

}

HB_FUNC( SDL_UNLOADOBJECT )
{

}

HB_FUNC( SDL_UNLOCKAUDIOSTREAM )
{

}

HB_FUNC( SDL_UNLOCKJOYSTICKS )
{

}

HB_FUNC( SDL_UNLOCKMUTEX )
{

}

HB_FUNC( SDL_UNLOCKPROPERTIES )
{

}

HB_FUNC( SDL_UNLOCKRWLOCK )
{

}

HB_FUNC( SDL_UNLOCKSPINLOCK )
{

}

HB_FUNC( SDL_UNLOCKSURFACE )
{

}

HB_FUNC( SDL_UNLOCKTEXTURE )
{

}

HB_FUNC( SDL_UNMAPGPUTRANSFERBUFFER )
{

}

HB_FUNC( SDL_UNREGISTERAPP )
{

}

HB_FUNC( SDL_UNSETENV_UNSAFE )
{

}

HB_FUNC( SDL_UNSETENVIRONMENTVARIABLE )
{

}

HB_FUNC( SDL_UPDATEGAMEPADS )
{

}

HB_FUNC( SDL_UPDATEHAPTICEFFECT )
{

}

HB_FUNC( SDL_UPDATEJOYSTICKS )
{

}

HB_FUNC( SDL_UPDATENVTEXTURE )
{

}

HB_FUNC( SDL_UPDATESENSORS )
{

}

HB_FUNC( SDL_UPDATETEXTURE )
{

}

HB_FUNC( SDL_UPDATEWINDOWSURFACE )
{

}

HB_FUNC( SDL_UPDATEWINDOWSURFACERECTS )
{

}

HB_FUNC( SDL_UPDATEYUVTEXTURE )
{

}

HB_FUNC( SDL_UPLOADTOGPUBUFFER )
{

}

HB_FUNC( SDL_UPLOADTOGPUTEXTURE )
{

}

HB_FUNC( SDL_UTF8STRLCPY )
{

}

HB_FUNC( SDL_VULKAN_CREATESURFACE )
{

}

HB_FUNC( SDL_VULKAN_DESTROYSURFACE )
{

}

HB_FUNC( SDL_VULKAN_GETINSTANCEEXTENSIONS )
{

}

HB_FUNC( SDL_VULKAN_GETPRESENTATIONSUPPORT )
{

}

HB_FUNC( SDL_VULKAN_GETVKGETINSTANCEPROCADDR )
{

}

HB_FUNC( SDL_VULKAN_LOADLIBRARY )
{

}

HB_FUNC( SDL_VULKAN_UNLOADLIBRARY )
{

}

HB_FUNC( SDL_WAITASYNCIORESULT )
{

}

HB_FUNC( SDL_WAITCONDITION )
{

}

HB_FUNC( SDL_WAITCONDITIONTIMEOUT )
{

}

// bool SDL_WaitEvent( SDL_Event *event );
HB_FUNC( SDL_WAITEVENT )
{
   if( hb_param( 1, HB_IT_BYREF ) != NULL )
   {
      SDL_Event *pEvent = ( SDL_Event * ) hb_xgrab( sizeof( SDL_Event ) );

      if( SDL_WaitEvent( pEvent ) )
      {
         hb_retl( T );
         hb_sdl_event_StorPtr( pEvent, 1 );
      }
      else
      {
         hb_xfree( pEvent );
         hb_retl( F );
      }
   }
   else
   {
      HB_ERR_ARGS();
   }
}

// bool SDL_WaitEventTimeout( SDL_Event *event, Sint32 timeoutMS );
HB_FUNC( SDL_WAITEVENTTIMEOUT )
{
   if( hb_param( 1, HB_IT_BYREF ) != NULL && hb_param( 2, HB_IT_NUMINT ) != NULL )
   {
      SDL_Event *pEvent = ( SDL_Event * ) hb_xgrab( sizeof( SDL_Event ) );

      if( SDL_WaitEventTimeout( pEvent, hb_parni( 2 ) ) )
      {
         hb_retl( T );
         hb_sdl_event_StorPtr( pEvent, 1 );
      }
      else
      {
         hb_xfree( pEvent );
         hb_retl( F );
      }
   }
   else
   {
      HB_ERR_ARGS();
   }
}

HB_FUNC( SDL_WAITFORGPUFENCES )
{

}

HB_FUNC( SDL_WAITFORGPUIDLE )
{

}

HB_FUNC( SDL_WAITPROCESS )
{

}

HB_FUNC( SDL_WAITSEMAPHORE )
{

}

HB_FUNC( SDL_WAITSEMAPHORETIMEOUT )
{

}

HB_FUNC( SDL_WAITTHREAD )
{

}

HB_FUNC( SDL_WARPMOUSEGLOBAL )
{

}

HB_FUNC( SDL_WARPMOUSEINWINDOW )
{

}

HB_FUNC( SDL_WASINIT )
{

}

HB_FUNC( SDL_WCSCASECMP )
{

}

HB_FUNC( SDL_WCSCMP )
{

}

HB_FUNC( SDL_WCSLCAT )
{

}

HB_FUNC( SDL_WCSLCPY )
{

}

HB_FUNC( SDL_WCSNCASECMP )
{

}

HB_FUNC( SDL_WCSNCMP )
{

}

HB_FUNC( SDL_WCSTOL )
{

}

HB_FUNC( SDL_WINDOWHASSURFACE )
{

}

HB_FUNC( SDL_WINDOWSUPPORTSGPUPRESENTMODE )
{

}

HB_FUNC( SDL_WINDOWSUPPORTSGPUSWAPCHAINCOMPOSITION )
{

}

HB_FUNC( SDL_WRITEASYNCIO )
{

}

HB_FUNC( SDL_WRITEIO )
{

}

HB_FUNC( SDL_WRITES16BE )
{

}

HB_FUNC( SDL_WRITES16LE )
{

}

HB_FUNC( SDL_WRITES32BE )
{

}

HB_FUNC( SDL_WRITES32LE )
{

}

HB_FUNC( SDL_WRITES64BE )
{

}

HB_FUNC( SDL_WRITES64LE )
{

}

HB_FUNC( SDL_WRITES8 )
{

}

HB_FUNC( SDL_WRITESTORAGEFILE )
{

}

HB_FUNC( SDL_WRITESURFACEPIXEL )
{

}

HB_FUNC( SDL_WRITESURFACEPIXELFLOAT )
{

}

HB_FUNC( SDL_WRITEU16BE )
{

}

HB_FUNC( SDL_WRITEU16LE )
{

}

HB_FUNC( SDL_WRITEU32BE )
{

}

HB_FUNC( SDL_WRITEU32LE )
{

}

HB_FUNC( SDL_WRITEU64BE )
{

}

HB_FUNC( SDL_WRITEU64LE )
{

}

HB_FUNC( SDL_WRITEU8 )
{

}

/* -------------------------------------------------------------------------
SDL3_ttf
------------------------------------------------------------------------- */
static HB_GARBAGE_FUNC( hb_ttf_font_Destructor )
{
   TTF_Font **ppTTF_Font = ( TTF_Font ** ) Cargo;

   if( ppTTF_Font && *ppTTF_Font )
   {
      TTF_CloseFont( *ppTTF_Font );
      TTF_Quit();
      *ppTTF_Font = NULL;
   }
}

static const HB_GC_FUNCS s_gc_ttf_font_Funcs =
{
   hb_ttf_font_Destructor,
   hb_gcDummyMark
};

TTF_Font *hb_ttf_font_ParamPtr( int iParam )
{
   TTF_Font **ppTTF_Font = ( TTF_Font ** ) hb_parptrGC( &s_gc_ttf_font_Funcs, iParam );

   if( ppTTF_Font && *ppTTF_Font )
   {
      return *ppTTF_Font;
   }
   else
   {
      HB_ERR_ARGS();
      return NULL;
   }
}

TTF_Font *hb_ttf_font_ParamGet( int iParam )
{
   TTF_Font **ppTTF_Font = ( TTF_Font ** ) hb_parptrGC( &s_gc_ttf_font_Funcs, iParam );

   return IIF( ppTTF_Font, *ppTTF_Font, NULL );
}

TTF_Font *hb_ttf_font_ItemGet( PHB_ITEM pItem )
{
   TTF_Font **ppTTF_Font = ( TTF_Font ** ) hb_itemGetPtrGC( pItem, &s_gc_ttf_font_Funcs );

   return IIF( ppTTF_Font, *ppTTF_Font, NULL );
}

PHB_ITEM hb_ttf_font_ItemPut( PHB_ITEM pItem, TTF_Font *pTTF_Font )
{
   TTF_Font **ppTTF_Font = ( TTF_Font ** ) hb_gcAllocate( sizeof( TTF_Font * ), &s_gc_ttf_font_Funcs );

   *ppTTF_Font = pTTF_Font;
   return hb_itemPutPtrGC( pItem, ppTTF_Font );
}

void hb_ttf_font_ItemClear( PHB_ITEM pItem )
{
   TTF_Font **ppTTF_Font = ( TTF_Font ** ) hb_itemGetPtrGC( pItem, &s_gc_ttf_font_Funcs );

   if( ppTTF_Font )
      *ppTTF_Font = NULL;
}

void hb_ttf_font_Return( TTF_Font *pTTF_Font )
{
   if( pTTF_Font )
   {
      hb_ttf_font_ItemPut( hb_param( -1, HB_IT_ANY ), pTTF_Font );
   }
   else
   {
      hb_ret();
   }
}

HB_FUNC( TTF_APPENDTEXTSTRING )
{

}

HB_FUNC( TTF_CLOSEFONT )
{

}

HB_FUNC( TTF_CREATEGPUTEXTENGINE )
{

}

HB_FUNC( TTF_CREATERENDERERTEXTENGINE )
{

}

HB_FUNC( TTF_CREATESURFACETEXTENGINE )
{

}

HB_FUNC( TTF_CREATETEXT )
{

}

HB_FUNC( TTF_DELETETEXTSTRING )
{

}

HB_FUNC( TTF_DESTROYGPUTEXTENGINE )
{

}

HB_FUNC( TTF_DESTROYRENDERERTEXTENGINE )
{

}

HB_FUNC( TTF_DESTROYSURFACETEXTENGINE )
{

}

HB_FUNC( TTF_DESTROYTEXT )
{

}

HB_FUNC( TTF_DRAWRENDERERTEXT )
{

}

HB_FUNC( TTF_DRAWSURFACETEXT )
{

}

HB_FUNC( TTF_FONTHASGLYPH )
{

}

HB_FUNC( TTF_FONTISFIXEDWIDTH )
{

}

HB_FUNC( TTF_FONTISSCALABLE )
{

}

HB_FUNC( TTF_GETFONTASCENT )
{

}

HB_FUNC( TTF_GETFONTDESCENT )
{

}

HB_FUNC( TTF_GETFONTDIRECTION )
{

}

HB_FUNC( TTF_GETFONTDPI )
{

}

HB_FUNC( TTF_GETFONTFAMILYNAME )
{

}

HB_FUNC( TTF_GETFONTGENERATION )
{

}

HB_FUNC( TTF_GETFONTHEIGHT )
{

}

HB_FUNC( TTF_GETFONTHINTING )
{

}

HB_FUNC( TTF_GETFONTKERNING )
{

}

HB_FUNC( TTF_GETFONTLINESKIP )
{

}

HB_FUNC( TTF_GETFONTOUTLINE )
{

}

HB_FUNC( TTF_GETFONTPROPERTIES )
{

}

HB_FUNC( TTF_GETFONTSDF )
{

}

HB_FUNC( TTF_GETFONTSIZE )
{

}

HB_FUNC( TTF_GETFONTSTYLE )
{

}

HB_FUNC( TTF_GETFONTSTYLENAME )
{

}

HB_FUNC( TTF_GETFONTWRAPALIGNMENT )
{

}

HB_FUNC( TTF_GETFREETYPEVERSION )
{

}

HB_FUNC( TTF_GETGLYPHIMAGE )
{

}

HB_FUNC( TTF_GETGLYPHIMAGEFORINDEX )
{

}

HB_FUNC( TTF_GETGLYPHKERNING )
{

}

HB_FUNC( TTF_GETGLYPHMETRICS )
{

}

HB_FUNC( TTF_GETGLYPHSCRIPT )
{

}

HB_FUNC( TTF_GETGPUTEXTDRAWDATA )
{

}

HB_FUNC( TTF_GETHARFBUZZVERSION )
{

}

HB_FUNC( TTF_GETNEXTTEXTSUBSTRING )
{

}

HB_FUNC( TTF_GETPREVIOUSTEXTSUBSTRING )
{

}

HB_FUNC( TTF_GETSTRINGSIZE )
{

}

HB_FUNC( TTF_GETSTRINGSIZEWRAPPED )
{

}

HB_FUNC( TTF_GETTEXTCOLOR )
{

}

HB_FUNC( TTF_GETTEXTCOLORFLOAT )
{

}

HB_FUNC( TTF_GETTEXTENGINE )
{

}

HB_FUNC( TTF_GETTEXTFONT )
{

}

HB_FUNC( TTF_GETTEXTPOSITION )
{

}

HB_FUNC( TTF_GETTEXTPROPERTIES )
{

}

HB_FUNC( TTF_GETTEXTSIZE )
{

}

HB_FUNC( TTF_GETTEXTSUBSTRING )
{

}

HB_FUNC( TTF_GETTEXTSUBSTRINGFORLINE )
{

}

HB_FUNC( TTF_GETTEXTSUBSTRINGFORPOINT )
{

}

HB_FUNC( TTF_GETTEXTSUBSTRINGSFORRANGE )
{

}

HB_FUNC( TTF_GETTEXTWRAPWIDTH )
{

}

//bool TTF_Init( void );
HB_FUNC( TTF_INIT )
{
   hb_retl( TTF_Init() );
}

HB_FUNC( TTF_INSERTTEXTSTRING )
{

}

HB_FUNC( TTF_MEASURESTRING )
{

}

// TTF_Font *TTF_OpenFont( const char *file, float ptsize );
HB_FUNC( TTF_OPENFONT )
{
   if( hb_param( 1, HB_IT_STRING ) != NULL && hb_param( 2, HB_IT_NUMERIC ) != NULL )
   {
      hb_ttf_font_Return( TTF_OpenFont( hb_parc( 1 ), ( float ) hb_parnd( 2 ) ) );
   }
   else
   {
      HB_ERR_ARGS();
   }
}

HB_FUNC( TTF_OPENFONTIO )
{

}

HB_FUNC( TTF_OPENFONTWITHPROPERTIES )
{

}

HB_FUNC( TTF_QUIT )
{

}

// SDL_Surface *TTF_RenderGlyph_Blended( TTF_Font *font, Uint32 ch, SDL_Color fg );
HB_FUNC( TTF_RENDERGLYPH_BLENDED )
{
   PHB_ITEM pArray;

   if( hb_param( 1, HB_IT_POINTER ) != NULL && hb_param( 2, HB_IT_NUMINT ) != NULL && ( pArray = hb_param( 3, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pArray ) == 4 )
   {
      SDL_Color color = hb_sdl_color_param_array( pArray );

      hb_sdl_surface_Return( TTF_RenderGlyph_Blended( hb_ttf_font_ParamPtr( 1 ), ( Uint32 ) hb_parni( 2 ), color ) );
   }
   else
   {
      HB_ERR_ARGS();
   }
}

HB_FUNC( TTF_RENDERGLYPH_LCD )
{

}

HB_FUNC( TTF_RENDERGLYPH_SHADED )
{

}

HB_FUNC( TTF_RENDERGLYPH_SOLID )
{

}

HB_FUNC( TTF_RENDERTEXT_BLENDED )
{

}

HB_FUNC( TTF_RENDERTEXT_BLENDED_WRAPPED )
{

}

HB_FUNC( TTF_RENDERTEXT_LCD )
{

}

// SDL_Surface *TTF_RenderText_LCD_Wrapped( TTF_Font *font, const char *text, size_t length, SDL_Color fg, SDL_Color bg, int wrap_width );
HB_FUNC( TTF_RENDERTEXT_LCD_WRAPPED )
{

}

// SDL_Surface *TTF_RenderText_Shaded( TTF_Font *font, const char *text, size_t length, SDL_Color fg, SDL_Color bg );
HB_FUNC( TTF_RENDERTEXT_SHADED )
{
   PHB_ITEM pArray1;
   PHB_ITEM pArray2;

   if( hb_param( 1, HB_IT_POINTER ) != NULL && hb_param( 2, HB_IT_STRING ) != NULL && hb_param( 3, HB_IT_NUMINT ) != NULL &&
      ( pArray1 = hb_param( 4, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pArray1 ) == 4 &&
      ( pArray2 = hb_param( 5, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pArray2 ) == 4 )
   {
      SDL_Color fg = hb_sdl_color_param_array( pArray1 );
      SDL_Color bg = hb_sdl_color_param_array( pArray2 );

      hb_sdl_surface_Return( TTF_RenderText_Shaded( hb_ttf_font_ParamPtr( 1 ), hb_parc( 2 ), ( size_t ) hb_parni( 3 ), fg, bg ) );
   }
   else
   {
      HB_ERR_ARGS();
   }
}

// SDL_Surface *TTF_RenderText_Shaded_Wrapped( TTF_Font *font, const char *text, size_t length, SDL_Color fg, SDL_Color bg, int wrap_width );
HB_FUNC( TTF_RENDERTEXT_SHADED_WRAPPED )
{
   PHB_ITEM pArray1;
   PHB_ITEM pArray2;

   if( hb_param( 1, HB_IT_POINTER ) != NULL && hb_param( 2, HB_IT_STRING ) != NULL && hb_param( 3, HB_IT_NUMINT ) != NULL &&
      ( pArray1 = hb_param( 4, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pArray1 ) == 4 &&
      ( pArray2 = hb_param( 5, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pArray2 ) == 4 &&
      hb_param( 6, HB_IT_INTEGER ) != NULL )
   {
      SDL_Color fg = hb_sdl_color_param_array( pArray1 );
      SDL_Color bg = hb_sdl_color_param_array( pArray2 );

      hb_sdl_surface_Return( TTF_RenderText_Shaded_Wrapped( hb_ttf_font_ParamPtr( 1 ), hb_parc( 2 ), ( size_t ) hb_parni( 3 ), fg, bg, hb_parni( 6 ) ) );
   }
   else
   {
      HB_ERR_ARGS();
   }
}

HB_FUNC( TTF_RENDERTEXT_SOLID )
{

}

HB_FUNC( TTF_RENDERTEXT_SOLID_WRAPPED )
{

}

HB_FUNC( TTF_SETFONTDIRECTION )
{

}

HB_FUNC( TTF_SETFONTHINTING )
{

}

HB_FUNC( TTF_SETFONTKERNING )
{

}

HB_FUNC( TTF_SETFONTLANGUAGE )
{

}

HB_FUNC( TTF_SETFONTLINESKIP )
{

}

HB_FUNC( TTF_SETFONTOUTLINE )
{

}

HB_FUNC( TTF_SETFONTSCRIPT )
{

}

HB_FUNC( TTF_SETFONTSDF )
{

}

HB_FUNC( TTF_SETFONTSIZE )
{

}

HB_FUNC( TTF_SETFONTSIZEDPI )
{

}

HB_FUNC( TTF_SETFONTSTYLE )
{

}

HB_FUNC( TTF_SETFONTWRAPALIGNMENT )
{

}

HB_FUNC( TTF_SETTEXTCOLOR )
{

}

HB_FUNC( TTF_SETTEXTCOLORFLOAT )
{

}

HB_FUNC( TTF_SETTEXTENGINE )
{

}

HB_FUNC( TTF_SETTEXTFONT )
{

}

HB_FUNC( TTF_SETTEXTPOSITION )
{

}

HB_FUNC( TTF_SETTEXTSTRING )
{

}

HB_FUNC( TTF_SETTEXTWRAPWHITESPACEVISIBLE )
{

}

HB_FUNC( TTF_SETTEXTWRAPWIDTH )
{

}

HB_FUNC( TTF_TEXTWRAPWHITESPACEVISIBLE )
{

}

HB_FUNC( TTF_UPDATETEXT )
{

}

HB_FUNC( TTF_VERSION )
{

}

HB_FUNC( TTF_WASINIT )
{

}

