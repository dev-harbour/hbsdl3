
/*
 *
 */

#include "hbsdl3.ch"

PROCEDURE Main()

   LOCAL pWindow
   LOCAL pRenderer
   LOCAL pEvent
   LOCAL lQuit := .F.

   IF( !SDL_Init( SDL_INIT_VIDEO ) )
      OutStd( e"\nError initializing SDL: ", SDL_GetError() )
      RETURN
   ENDIF

   pWindow := SDL_CreateWindow( "Simple SDL3 Window", 800, 600, SDL_WINDOW_RESIZABLE )
   IF( pWindow == NIL )
      OutStd( e"\nError creating SDL window: ", SDL_GetError() )
      RETURN
   ENDIF

   pRenderer := SDL_CreateRenderer( pWindow, NIL )
   IF( pRenderer == NIL )
      OutStd( e"\nError creating SDL renderer: ", SDL_GetError() )
      RETURN
   ENDIF

   DO WHILE( !lQuit )

      DO WHILE( SDL_PollEvent( @pEvent ) )

         IF( EventType( pEvent ) == SDL_EVENT_QUIT )
            lQuit := .T.
         ENDIF

      ENDDO

      SDL_SetRenderDrawColor( pRenderer, 12, 12, 12, 255 )
      SDL_RenderClear( pRenderer )
      SDL_RenderPresent( pRenderer )

   ENDDO

RETURN
