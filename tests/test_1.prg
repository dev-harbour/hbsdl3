/*
 *
 */

#include "hbsdl3.ch"

PROCEDURE Main()

   // SDL_SetHint( SDL_HINT_SHUTDOWN_DBUS_ON_QUIT, "1" )

   IF( !SDL_Init( SDL_INIT_VIDEO ) )
      OutStd( e"\nUnable to initialize SDL: ", SDL_GetError() )
      RETURN
   ENDIF

   SDL_Delay( 2000 )

RETURN
