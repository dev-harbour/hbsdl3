/*
 * Copyright 2024 Rafał Jopek <https://harbour.pl>
 */

#include "hbsdl3.ch"

PROCEDURE Main()

   SDL_SetHint( SDL_HINT_SHUTDOWN_DBUS_ON_QUIT, "1" )

   IF( !SDL_Init( SDL_INIT_VIDEO ) )
      OutStd( e"\nError initializing SDL: ", SDL_GetError() )
      RETURN
   ENDIF

   SDL_Delay( 2000 )

   // All cleanup functions are automatically handled by the Harbour Garbage Collector.
   // However, the user can also use SDL's destruction functions (e.g., SDL_Destroy...())
   // to manually release resources if needed. The Garbage Collector will handle any remaining resources upon application termination.

RETURN
