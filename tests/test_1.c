/*
 *
 */

#include <stdbool.h>
#include <stdio.h>

#include <SDL3/SDL.h>

int main()
{
   SDL_SetHint( SDL_HINT_SHUTDOWN_DBUS_ON_QUIT, "1" );

   if( !SDL_Init( SDL_INIT_VIDEO ) )
   {
      fprintf( stderr, "Error initializing SDL: %s\n", SDL_GetError() );
      return 1;
   }

   SDL_Delay( 2000 );

   return 0;
}
