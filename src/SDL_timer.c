/*
 * Copyright 2024 Rafał Jopek <https://harbour.pl>
 *
 */

#include "hbsdl.h"

/* -------------------------------------------------------------------------
SDL3 API
------------------------------------------------------------------------- */
// Uint64 SDL_GetTicks(void);
// Uint64 SDL_GetTicksNS(void);
// Uint64 SDL_GetPerformanceCounter(void);
// Uint64 SDL_GetPerformanceFrequency(void);

// void SDL_Delay(Uint32 ms);
HB_FUNC( SDL_DELAY )
{
   if( hb_param( 1, HB_IT_NUMERIC ) != NULL )
   {
      SDL_Delay( hb_parni( 1 ) );
   }
   else
   {
      HB_ERR_ARGS();
   }
}

// void SDL_DelayNS(Uint64 ns);
// void SDL_DelayPrecise(Uint64 ns);
// SDL_TimerID SDL_AddTimer(Uint32 interval, SDL_TimerCallback callback, void *userdata);
// SDL_TimerID SDL_AddTimerNS(Uint64 interval, SDL_NSTimerCallback callback, void *userdata);

// bool SDL_RemoveTimer(SDL_TimerID id);
HB_FUNC( SDL_REMOVETIMER )
{
   if( hb_param( 1, HB_IT_NUMERIC ) != NULL )
   {
      SDL_TimerID id = ( SDL_TimerID ) hb_parni( 1 );
      hb_retl( SDL_RemoveTimer( id ) );
   }
   else
   {
      HB_ERR_ARGS();
   }
}
