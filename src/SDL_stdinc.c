/*
 * Copyright 2024 Rafał Jopek <https://harbour.pl>
 *
 */

#include "hbsdl.h"

/* -------------------------------------------------------------------------
Harbour Implementation
------------------------------------------------------------------------- */
HB_FUNC( SDL_UINT64_C )
{
   HB_LONGLONG value = hb_parnll( 1 );
   hb_retnll( value );
}
