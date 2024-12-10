
/*
 *
 */

#include <stdio.h>
#include <stdbool.h>

#include <SDL3/SDL.h>

int main()
{
   SDL_Window *pWindow = NULL;
   SDL_Renderer *pRenderer = NULL;
   SDL_Event pEvent;
   bool lQuit = false;

   SDL_SetHint( SDL_HINT_SHUTDOWN_DBUS_ON_QUIT, "1" );

   if( !SDL_Init( SDL_INIT_VIDEO ) )
   {
      fprintf( stderr, "Error initializing SDL: %s\n", SDL_GetError() );
      return 1;
   }

   pWindow = SDL_CreateWindow( "Simple SDL3 Window", 800, 600, SDL_WINDOW_RESIZABLE );
   if( pWindow == NULL )
   {
      fprintf( stderr, "Error creating SDL window: %s\n", SDL_GetError() );
      SDL_Quit();
      return 1;
   }

   pRenderer = SDL_CreateRenderer( pWindow, NULL );
   if( pRenderer == NULL )
   {
      fprintf( stderr, "Error creating SDL renderer: %s\n", SDL_GetError() );
      SDL_DestroyWindow( pWindow );
      SDL_Quit();
      return 1;
   }

   while( !lQuit )
   {
      while( SDL_PollEvent( &pEvent ) )
      {
         switch( pEvent.type )
         {
            case SDL_EVENT_QUIT:
               printf( "Window closed\n" );
               lQuit = true;
               break;

            case SDL_EVENT_WINDOW_CLOSE_REQUESTED:
               printf( "Window close requested\n" );
               lQuit = true;
               break;

            case SDL_EVENT_KEY_DOWN:

               if( pEvent.key.key == SDLK_ESCAPE )
               {
                  printf( "Esc pressed\n" );
                  lQuit = true;
               }
               else
               {
                  printf( "Other key pressed (scancode: %d)\n", pEvent.key.key );
               }
               break;

            default:
               printf( "Unhandled event (type: %d)\n", pEvent.type );
               break;
         }
      }

      SDL_SetRenderDrawColor( pRenderer, 50, 50, 50, 255 );
      SDL_RenderClear( pRenderer );
      SDL_RenderPresent( pRenderer );
   }

   SDL_DestroyRenderer( pRenderer );
   SDL_DestroyWindow( pWindow );
   SDL_Quit();

   return 0;
}
