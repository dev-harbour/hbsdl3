/*
 * Copyright 2024 Rafał Jopek <https://harbour.pl>
 */

#include "hbsdl3.ch"

PROCEDURE Main()

   LOCAL pWindow
   LOCAL pRenderer
   LOCAL pEvent
   LOCAL lQuit := F

   SDL_SetHint( SDL_HINT_SHUTDOWN_DBUS_ON_QUIT, "1" )

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

         SWITCH( EventType( pEvent ) )

            CASE SDL_EVENT_QUIT
               OutStd( e"\nWindow closed" )
               lQuit := T
               EXIT

            CASE SDL_EVENT_WINDOW_CLOSE_REQUESTED
               OutStd( e"\nWindow close requested" )
               lQuit := T
               EXIT

            CASE SDL_EVENT_KEY_DOWN
               IF( EventKeyKey( pEvent ) == SDLK_ESCAPE )
                  OutStd( e"\nEsc pressed" )
                  lQuit := T
               ELSE
                  OutStd( e"\nOther key pressed (scancode: ", EventKeyKey( pEvent ), ")" )
               ENDIF
               EXIT

            CASE SDL_EVENT_KEY_UP
               OutStd( e"\nKey released (scancode: ", EventKeyKey( pEvent ), ")" )
               EXIT

            OTHERWISE
               OutStd( e"\nUnhandled event (type: ", EventType( pEvent ), ")" )

         ENDSWITCH

      ENDDO

      SDL_SetRenderDrawColor( pRenderer, 50, 50, 50, 255 )
      SDL_RenderClear( pRenderer )
      SDL_RenderPresent( pRenderer )

   ENDDO

   // All cleanup functions are automatically handled by the Harbour Garbage Collector.
   // However, the user can also use SDL's destruction functions (e.g., SDL_Destroy...())
   // to manually release resources if needed. The Garbage Collector will handle any remaining resources upon application termination.

RETURN
