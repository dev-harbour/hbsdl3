/*
 * Copyright 2024 Rafał Jopek <https://harbour.pl>
 *
 */

#include "hbsdl.h"

/* -------------------------------------------------------------------------
Harbour Implementation
------------------------------------------------------------------------- */
// void SDL_PrintInitSubsystems( void )
HB_FUNC( SDL_PRINT_INITIALIZED_SUBSYSTEMS )
{
   Uint32 subsystems = SDL_WasInit( 0 );

   if( subsystems & SDL_INIT_AUDIO )
      printf( "SDL_INIT_AUDIO is initialized.\n" );
   if( subsystems & SDL_INIT_VIDEO )
      printf( "SDL_INIT_VIDEO is initialized.\n" );
   if( subsystems & SDL_INIT_JOYSTICK )
      printf( "SDL_INIT_JOYSTICK is initialized.\n" );
   if( subsystems & SDL_INIT_HAPTIC )
      printf( "SDL_INIT_HAPTIC is initialized.\n" );
   if( subsystems & SDL_INIT_GAMEPAD )
      printf( "SDL_INIT_GAMEPAD is initialized.\n" );
   if( subsystems & SDL_INIT_EVENTS )
      printf( "SDL_INIT_EVENTS is initialized.\n" );
   if( subsystems & SDL_INIT_SENSOR )
      printf( "SDL_INIT_SENSOR is initialized.\n" );
   if( subsystems & SDL_INIT_CAMERA )
      printf( "SDL_INIT_CAMERA is initialized.\n" );
}

// int SDL_InitFlags( [ flags... ] )
HB_FUNC( SDL_INITFLAGS )
{
   Uint32 flags = 0;
   int argc = hb_pcount();

   for( int i = 1; i <= argc; i++ )
   {
      if( hb_param( i, HB_IT_NUMERIC ) != NULL )
      {
         flags |= ( Uint32 ) hb_parni( i );
      }
      else
      {
         HB_ERR_ARGS();
      }
   }
   hb_retni( flags );
}

/* -------------------------------------------------------------------------
SDL3 API
------------------------------------------------------------------------- */
// bool SDL_Init(SDL_InitFlags flags);
HB_FUNC( SDL_INIT )
{
   if( hb_param( 1, HB_IT_NUMERIC ) != NULL )
   {
      hb_retl( SDL_Init( ( Uint32 ) hb_parni( 1 ) ) );
   }
   else
   {
      HB_ERR_ARGS();
   }
}

// bool SDL_InitSubSystem(SDL_InitFlags flags);
HB_FUNC( SDL_INITSUBSYSTEM )
{
   if( hb_param( 1, HB_IT_NUMERIC ) != NULL )
   {
      hb_retl( SDL_InitSubSystem( ( Uint32 ) hb_parni( 1 ) ) );
   }
   else
   {
      HB_ERR_ARGS();
   }
}

// void SDL_QuitSubSystem(SDL_InitFlags flags);
HB_FUNC( SDL_QUITSUBSYSTEM )
{
   if( hb_param( 1, HB_IT_NUMERIC ) != NULL )
   {
      SDL_QuitSubSystem( ( Uint32 ) hb_parni( 1 ) );
   }
   else
   {
      HB_ERR_ARGS();
   }
}

// SDL_InitFlags SDL_WasInit(SDL_InitFlags flags);
HB_FUNC( SDL_WASINIT )
{
   if( hb_param( 1, HB_IT_NUMERIC ) != NULL )
   {
      hb_retni( SDL_WasInit( ( Uint32 ) hb_parni( 1 ) ) );
   }
   else
   {
      HB_ERR_ARGS();
   }
}

// void SDL_Quit(void);
// bool SDL_IsMainThread(void);
// bool SDL_RunOnMainThread(SDL_MainThreadCallback callback, void *userdata, bool wait_complete);
// bool SDL_SetAppMetadata(const char *appname, const char *appversion, const char *appidentifier);
// bool SDL_SetAppMetadataProperty(const char *name, const char *value);
// const char * SDL_GetAppMetadataProperty(const char *name);


