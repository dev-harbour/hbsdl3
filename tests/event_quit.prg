/*
 * Copyright 2024 Rafał Jopek <https://harbour.pl>
 */

#include "hbsdl3.ch"

PROCEDURE Main()

   LOCAL objLocal, bLastHandler
   LOCAL pWindow
   LOCAL pRenderer
   LOCAL pEvent
   LOCAL lQuit := F

   bLastHandler := ErrorBlock( {| objErr | MyHandler( objErr, T ) } )
   BEGIN SEQUENCE

      SDL_SetHint( SDL_HINT_SHUTDOWN_DBUS_ON_QUIT, "1" )

      IF( !SDL_Init( SDL_INIT_VIDEO ) )
         OutStd( e"\nError initializing SDL: ", SDL_GetError() )
         BREAK
      ENDIF

      pWindow := SDL_CreateWindow( "Simple SDL3 Window", 800, 600, SDL_WINDOW_RESIZABLE )
      IF( pWindow == NIL )
         OutStd( e"\nError creating SDL window: ", SDL_GetError() )
         BREAK
      ENDIF

      pRenderer := SDL_CreateRenderer( pWindow, NIL )
      IF( pRenderer == NIL )
         OutStd( e"\nError creating SDL renderer: ", SDL_GetError() )
         BREAK
      ENDIF

      WHILE( !lQuit )
         BEGIN SEQUENCE
            WHILE( SDL_PollEvent( @pEvent ) )
               IF( EventType( pEvent ) == SDL_EVENT_QUIT )
                  lQuit := T
                  EXIT
               ENDIF
            ENDDO
         RECOVER USING objLocal
            OutStd( "Błąd w obsłudze zdarzeń:", objLocal:description )
            LogError( "error.log", objLocal )
         END

         SDL_SetRenderDrawColor( pRenderer, 0x32, 0x32, 0x32, 0xFF )
         SDL_RenderClear( pRenderer )
         SDL_RenderPresent( pRenderer )

      ENDDO

   RECOVER USING objLocal
      OutStd( e"\nKrytyczny błąd aplikacji:", objLocal:description )
      LogError( "error.log", objLocal )
   END

   ErrorBlock( bLastHandler )

   RETURN

FUNCTION MyHandler( objError, lLocalHandler )

   IF lLocalHandler
      BREAK objError
   ENDIF

   LogError( "global_error.log", objError )

   RETURN NIL

FUNCTION LogError( cFile, objError )

   LOCAL hFile := FCreate( cFile, 0 )

   IF hFile != -1
      FWrite( hFile, ;
         "Error: " + objError:description + hb_eol() + ;
         "Code : " + Str( objError:genCode ) + hb_eol() )
      FClose( hFile )
   ENDIF

   RETURN NIL
