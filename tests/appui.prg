/*
 * Copyright 2024 Rafał Jopek <https://harbour.pl>
 */

#include "appui.ch"

PROCEDURE Main()

   LOCAL pApp

   pApp := AppUI( "Simple AppUI", 800, 600, WHITE )

   BoxUI( pApp, "First window",  { 100, 100, 200, 200 }, BLACK )
   BoxUI( pApp, "Second window", { 150, 150, 200, 200 }, BLUE )
   BoxUI( pApp, "Third window",  { 200, 200, 200, 200 }, GREEN )
   BoxUI( pApp, "Fourth window", { 250, 250, 200, 200 }, CYAN )
   BoxUI( pApp, "Fifth window",  { 300, 300, 200, 200 }, RED )
   BoxUI( pApp, "Sixth window",  { 350, 350, 200, 200 }, MAGENTA )

   AppBindKey( pApp, "Escape", { || AppQuit( pApp ) } )

   AppExec( pApp )

RETURN
