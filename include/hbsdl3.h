#ifndef HBSDL3_H_
#define HBSDL3_H_

#include <stdio.h>
#include <stdarg.h>
#include <stdbool.h>
#include <time.h>

#include <SDL3/SDL.h>

#include "hbapi.h"
#include "hbapierr.h"
#include "hbapiitm.h"

#define F false
#define T true

HB_EXTERN_BEGIN
extern SDL_Window *hb_sdl_window_ParamPtr( int iParam );
extern SDL_Window *hb_sdl_window_ParamGet( int iParam );
extern SDL_Window *hb_sdl_window_ItemGet( PHB_ITEM pItem );
extern PHB_ITEM    hb_sdl_window_ItemPut( PHB_ITEM pItem, SDL_Window *pSDL_Window );
extern void        hb_sdl_window_ItemClear( PHB_ITEM pItem );
extern void        hb_sdl_window_Return( SDL_Window *pSDL_Window );

extern SDL_Event  *hb_sdl_event_ParamPtr( int iParam );
extern SDL_Event  *hb_sdl_event_ParamGet( int iParam );
extern SDL_Event  *hb_sdl_event_ItemGet( PHB_ITEM pItem );
extern PHB_ITEM    hb_sdl_event_ItemPut( PHB_ITEM pItem, SDL_Event *pSDL_Event );
extern void        hb_sdl_event_ItemClear( PHB_ITEM pItem );
extern void        hb_sdl_event_StorPtr( SDL_Event *pSDL_Event, int iParam );
extern void        hb_sdl_event_Return( SDL_Event *pSDL_Event );
HB_EXTERN_END

/* -------------------------------------------------------------------------
Macro Definitions
------------------------------------------------------------------------- */
#define HB_ERR_ARGS() ( hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS ) )

#define UNUSED( n ) ( ( void )( n ) )
#define IIF( condition, trueValue, falseValue ) ( ( condition ) ? ( trueValue ) : ( falseValue ) )

#endif /* End HBSDL3_H_ */
