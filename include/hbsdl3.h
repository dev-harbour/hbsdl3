#ifndef HBSDL3_H_
#define HBSDL3_H_

#include <stdio.h>
#include <stdarg.h>
#include <stdbool.h>
#include <time.h>

#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>

#include "hbapi.h"
#include "hbapierr.h"
#include "hbapiitm.h"

#define F false
#define T true


/* -------------------------------------------------------------------------
Macro Definitions
------------------------------------------------------------------------- */
#define HB_ERR_ARGS() ( hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS ) )

#define UNUSED( n ) ( ( void )( n ) )
#define IIF( condition, trueValue, falseValue ) ( ( condition ) ? ( trueValue ) : ( falseValue ) )

#endif /* End HBSDL3_H_ */
