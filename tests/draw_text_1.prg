
/*
 *
 */

#include "hbsdl3.ch"

PROCEDURE Main()

   LOCAL pWindow
   LOCAL pRenderer
   LOCAL pFont
   LOCAL pEvent
   LOCAL lQuit := F
   LOCAL nWidth, nHeight
   LOCAL cText := "Hello, Harbour!"
   LOCAL nTextX, nTextY
   LOCAL nCharWidth, nCharHeight

   SDL_SetHint( SDL_HINT_SHUTDOWN_DBUS_ON_QUIT, "1" )

   IF( !SDL_Init( SDL_INIT_VIDEO ) )
      OutStd( e"\nError initializing SDL: ", SDL_GetError() )
      RETURN
   ENDIF

   IF( !TTF_Init() )
      OutStd( e"\nError initializing SDL_ttf: ", SDL_GetError() )
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

   pFont := TTF_OpenFont( "../docs/assets/font/9x18.pcf.gz", 18 )
   IF( pFont == NIL )
      OutStd( e"\nError opening SDL_ttf font: ", SDL_GetError() )
      RETURN
   ENDIF
   nCharWidth  := 9
   nCharHeight := 18

   SDL_GetWindowSize( pWindow, @nWidth, @nHeight )

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

         CASE SDL_EVENT_WINDOW_RESIZED
            SDL_GetWindowSize( pWindow, @nWidth, @nHeight )
            EXIT

         ENDSWITCH

      ENDDO

      SDL_SetRenderDrawColor( pRenderer, 0x32, 0x32, 0x32, 0xFF )
      SDL_RenderClear( pRenderer )

      nTextX := ( nWidth - Len( cText ) * nCharWidth ) / 2
      nTextY := ( nHeight - nCharHeight ) / 2

      drawText( pFont, pRenderer, nTextX / nCharWidth, nTextY / nCharHeight, cText, { 0x00, 0x00, 0x00, 0xFF }, { 0xFF, 0xFF, 0xFF, 0xFF } )

      SDL_RenderPresent( pRenderer )

   ENDDO

   RETURN
