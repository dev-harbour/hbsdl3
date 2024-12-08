/*
 * Copyright 2024 Rafał Jopek <https://harbour.pl>
 *
 */

#include "hbsdl.h"

/* -------------------------------------------------------------------------
SDL3 API
------------------------------------------------------------------------- */
// bool SDL_SetHintWithPriority(const char *name, const char *value, SDL_HintPriority priority);

// bool SDL_SetHint(const char *name, const char *value);
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

// bool SDL_ResetHint(const char *name);
// void SDL_ResetHints(void);
// const char *SDL_GetHint(const char *name);
// bool SDL_GetHintBoolean(const char *name, bool default_value);
// bool SDL_AddHintCallback(const char *name, SDL_HintCallback callback, void *userdata);
// void SDL_RemoveHintCallback(const char *name, SDL_HintCallback callback, void *userdata);


