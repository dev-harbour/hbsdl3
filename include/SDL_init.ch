#ifndef SDL_INIT_CH_
#define SDL_INIT_CH_

#define SDL_INIT_AUDIO      0x00000010
#define SDL_INIT_VIDEO      0x00000020
#define SDL_INIT_JOYSTICK   0x00000200
#define SDL_INIT_HAPTIC     0x00001000
#define SDL_INIT_GAMEPAD    0x00002000
#define SDL_INIT_EVENTS     0x00004000
#define SDL_INIT_SENSOR     0x00008000
#define SDL_INIT_CAMERA     0x00010000

#define SDL_APP_CONTINUE    0
#define SDL_APP_SUCCESS     1
#define SDL_APP_FAILURE     2

#define SDL_PROP_APP_METADATA_NAME_STRING         "SDL.app.metadata.name"
#define SDL_PROP_APP_METADATA_VERSION_STRING      "SDL.app.metadata.version"
#define SDL_PROP_APP_METADATA_IDENTIFIER_STRING   "SDL.app.metadata.identifier"
#define SDL_PROP_APP_METADATA_CREATOR_STRING      "SDL.app.metadata.creator"
#define SDL_PROP_APP_METADATA_COPYRIGHT_STRING    "SDL.app.metadata.copyright"
#define SDL_PROP_APP_METADATA_URL_STRING          "SDL.app.metadata.url"
#define SDL_PROP_APP_METADATA_TYPE_STRING         "SDL.app.metadata.type"

#endif /* End SDL_INIT_CH_ */
