/*
 *
 */

#include "hbsdl3.ch"

PROCEDURE Main()

   LOCAL pWindow
   LOCAL pRenderer
   LOCAL pSurface
   LOCAL pTexture
   LOCAL pEvent
   LOCAL lQuit := F

   SDL_SetHint( SDL_HINT_SHUTDOWN_DBUS_ON_QUIT, "1" )

   IF( !SDL_Init( SDL_INIT_VIDEO ) )
      OutStd( e"\nError initializing SDL: ", SDL_GetError() )
      RETURN
   ENDIF

   IF( !SDL_CreateWindowAndRenderer( "Simple SDL3 Window", 512, 512, 0, @pWindow, @pRenderer ) )
      OutStd( e"\nError creating SDL window and renderer: ", SDL_GetError() )
      RETURN
   ENDIF

   pSurface := SDL_LoadBMP( "../docs/assets/img/Harbour-dev.bmp" )
   IF( pSurface == NIL )
      OutStd( e"\nError creating SDL surface from image: ", SDL_GetError() )
      RETURN
   ENDIF

   pTexture := SDL_CreateTextureFromSurface( pRenderer, pSurface )
   IF( pTexture == NIL )
      OutStd( e"\nError create texture from surface: ", SDL_GetError() )
      RETURN
   ENDIF
   SDL_DestroySurface( pSurface )

   WHILE( !lQuit )

      WHILE( SDL_PollEvent( @pEvent ) )

         SWITCH( EventType( pEvent ) )

         CASE SDL_EVENT_QUIT
            OutStd( e"\nWindow closed" )
            lQuit := T
            EXIT

         CASE SDL_EVENT_WINDOW_CLOSE_REQUESTED
            OutStd( e"\nWindow close requested" )
            lQuit := T
            EXIT

         ENDSWITCH

      ENDDO

      SDL_SetRenderDrawColor( pRenderer, 0x00, 0x00, 0x00, 0x00 )
      SDL_RenderClear( pRenderer )
      SDL_RenderTexture( pRenderer, pTexture, NIL, NIL )
      SDL_RenderPresent( pRenderer )

   ENDDO

   RETURN
