
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
   LOCAL cText := {;
      "",;
      "Mathematics and sciences:",;
      "",;
      "  ∮ E⋅da = Q,  n → ∞, ∑ f(i) = ∏ g(i),      ⎧⎡⎛┌─────┐⎞⎤⎫",;
      "                                            ⎪⎢⎜│a²+b³ ⎟⎥⎪",;
      "  ∀x∈ℝ: ⌈x⌉ = −⌊−x⌋, α ∧ ¬β = ¬(¬α ∨ β),    ⎪⎢⎜│───── ⎟⎥⎪",;
      "                                            ⎪⎢⎜⎷ c₈   ⎟⎥⎪",;
      "  ℕ ⊆ ℕ₀ ⊂ ℤ ⊂ ℚ ⊂ ℝ ⊂ ℂ,                   ⎨⎢⎜       ⎟⎥⎬",;
      "                                            ⎪⎢⎜ ∞     ⎟⎥⎪",;
      "  ⊥ < a ≠ b ≡ c ≤ d ≪ ⊤ ⇒ (⟦A⟧ ⇔ ⟪B⟫),      ⎪⎢⎜ ⎲     ⎟⎥⎪",;
      "                                            ⎪⎢⎜ ⎳aⁱ-bⁱ⎟⎥⎪",;
      "  2H₂ + O₂ ⇌ 2H₂O, R = 4.7 kΩ, ⌀ 200 mm     ⎩⎣⎝i=1    ⎠⎦⎭",;
      "",;
      "Linguistics and dictionaries:",;
      "",;
      "  ði ıntəˈnæʃənəl fəˈnɛtık əsoʊsiˈeıʃn",;
      "  Y [ˈʏpsilɔn], Yen [jɛn], Yoga [ˈjoːgɑ]",;
      "",;
      "APL:",;
      "",;
      "  ((V⍳V)=⍳⍴V)/V←,V    ⌷←⍳→⍴∆∇⊃‾⍎⍕⌈" }


   LOCAL nLines := Len( cText )
   LOCAL i


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

      SDL_SetRenderDrawColor( pRenderer, 0x32, 0x32, 0x32, 0xFF )
      SDL_RenderClear( pRenderer )

      FOR i := 1 TO nLines
         drawText( pFont, pRenderer, 1, i -1, cText[ i ], { 0x00, 0x00, 0x00, 0xFF }, { 0xFF, 0xFF, 0xFF, 0xFF } )
      NEXT

      SDL_RenderPresent( pRenderer )

   ENDDO

RETURN
