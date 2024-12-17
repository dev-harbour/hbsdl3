#ifndef HBSDL3_H_
#define HBSDL3_H_

#include <stdio.h>
#include <stdarg.h>
#include <stdbool.h>
#include <time.h>

#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>

#include "hbapi.h"
#include "hbapierr.h"
#include "hbapiitm.h"

#define F false
#define T true

HB_EXTERN_BEGIN

extern HB_EXPORT SDL_Window *hb_sdl_window_ParamPtr( int iParam );
extern HB_EXPORT SDL_Window *hb_sdl_window_ParamGet( int iParam );
extern HB_EXPORT SDL_Window *hb_sdl_window_ItemGet( PHB_ITEM pItem );
extern HB_EXPORT PHB_ITEM    hb_sdl_window_ItemPut( PHB_ITEM pItem, SDL_Window *pSDL_Window );
extern HB_EXPORT void        hb_sdl_window_ItemClear( PHB_ITEM pItem );
extern HB_EXPORT void        hb_sdl_window_StorPtr( SDL_Window *pSDL_Window, int iParam );
extern HB_EXPORT void        hb_sdl_window_Return( SDL_Window *pSDL_Window );

extern HB_EXPORT SDL_Renderer *hb_sdl_renderer_ParamPtr( int iParam );
extern HB_EXPORT SDL_Renderer *hb_sdl_renderer_ParamGet( int iParam );
extern HB_EXPORT SDL_Renderer *hb_sdl_renderer_ItemGet( PHB_ITEM pItem );
extern HB_EXPORT PHB_ITEM      hb_sdl_renderer_ItemPut( PHB_ITEM pItem, SDL_Renderer *pSDL_Renderer );
extern HB_EXPORT void          hb_sdl_renderer_ItemClear( PHB_ITEM pItem );
extern HB_EXPORT void          hb_sdl_renderer_StorPtr( SDL_Renderer *pSDL_Renderer, int iParam );
extern HB_EXPORT void          hb_sdl_renderer_Return( SDL_Renderer *pSDL_Renderer );

extern HB_EXPORT SDL_Event *hb_sdl_event_ParamPtr( int iParam );
extern HB_EXPORT SDL_Event *hb_sdl_event_ParamGet( int iParam );
extern HB_EXPORT SDL_Event *hb_sdl_event_ItemGet( PHB_ITEM pItem );
extern HB_EXPORT PHB_ITEM   hb_sdl_event_ItemPut( PHB_ITEM pItem, SDL_Event *pSDL_Event );
extern HB_EXPORT void       hb_sdl_event_ItemClear( PHB_ITEM pItem );
extern HB_EXPORT void       hb_sdl_event_StorPtr( SDL_Event *pSDL_Event, int iParam );
extern HB_EXPORT void       hb_sdl_event_Return( SDL_Event *pSDL_Event );

extern HB_EXPORT SDL_Surface *hb_sdl_surface_ParamPtr( int iParam );
extern HB_EXPORT SDL_Surface *hb_sdl_surface_ParamGet( int iParam );
extern HB_EXPORT SDL_Surface *hb_sdl_surface_ItemGet( PHB_ITEM pItem );
extern HB_EXPORT PHB_ITEM     hb_sdl_surface_ItemPut( PHB_ITEM pItem, SDL_Surface *pSDL_Surface );
extern HB_EXPORT void         hb_sdl_surface_ItemClear( PHB_ITEM pItem );
extern HB_EXPORT void         hb_sdl_surface_Return( SDL_Surface *pSDL_Surface );

extern HB_EXPORT SDL_Texture *hb_sdl_texture_ParamPtr( int iParam );
extern HB_EXPORT SDL_Texture *hb_sdl_texture_ParamGet( int iParam );
extern HB_EXPORT SDL_Texture *hb_sdl_texture_ItemGet( PHB_ITEM pItem );
extern HB_EXPORT PHB_ITEM     hb_sdl_texture_ItemPut( PHB_ITEM pItem, SDL_Texture *pSDL_Texture );
extern HB_EXPORT void         hb_sdl_texture_ItemClear( PHB_ITEM pItem );
extern HB_EXPORT void         hb_sdl_texture_Return( SDL_Texture *pSDL_Texture );

extern HB_EXPORT SDL_Color  hb_sdl_color_param_array( PHB_ITEM pArray );
extern HB_EXPORT PHB_ITEM   hb_sdl_color_return_array( const SDL_Color *color );
extern HB_EXPORT SDL_FColor hb_sdl_fcolor_param_array( PHB_ITEM pArray );
extern HB_EXPORT PHB_ITEM   hb_sdl_fcolor_return_array( const SDL_FColor *fcolor );

extern HB_EXPORT SDL_FRect hb_sdl_frect_param_array( PHB_ITEM pArray );
extern HB_EXPORT PHB_ITEM  hb_sdl_frect_return_array( const SDL_FRect *frect );

extern HB_EXPORT TTF_Font *hb_ttf_font_ParamPtr( int iParam );
extern HB_EXPORT TTF_Font *hb_ttf_font_ParamGet( int iParam );
extern HB_EXPORT TTF_Font *hb_ttf_font_ItemGet( PHB_ITEM pItem );
extern HB_EXPORT PHB_ITEM  hb_ttf_font_ItemPut( PHB_ITEM pItem, TTF_Font *pTTF_Font );
extern HB_EXPORT void      hb_ttf_font_ItemClear( PHB_ITEM pItem );
extern HB_EXPORT void      hb_ttf_font_Return( TTF_Font *pTTF_Font );

HB_EXTERN_END

/* -------------------------------------------------------------------------
Macro Definitions
------------------------------------------------------------------------- */
#define HB_ERR_ARGS() ( hb_errRT_BASE_SubstR( EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS ) )

#define UNUSED( n ) ( ( void )( n ) )
#define IIF( condition, trueValue, falseValue ) ( ( condition ) ? ( trueValue ) : ( falseValue ) )

#endif /* End HBSDL3_H_ */
