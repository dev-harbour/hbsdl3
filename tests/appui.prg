/*
 * Copyright 2024 Rafał Jopek <https://harbour.pl>
 */

#include "appui.ch"

PROCEDURE Main()

   LOCAL app

   app := App( "Simple AppUI", 800, 600, WHITE )

   Box( app, "First window",  { 100, 100, 200, 200 }, BLACK )
   Box( app, "Second window", { 150, 150, 200, 200 }, BLUE )
   Box( app, "Third window",  { 200, 200, 200, 200 }, GREEN )
   Box( app, "Fourth window", { 250, 250, 200, 200 }, CYAN )
   Box( app, "Fifth window",  { 300, 300, 200, 200 }, RED )
   Box( app, "Sixth window",  { 350, 350, 200, 200 }, MAGENTA )

   AppExec( app )

RETURN
