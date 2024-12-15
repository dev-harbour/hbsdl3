/*
 * Copyright 2024 Rafał Jopek <https://harbour.pl>
 */

#include "hbsdl3.h"

/* -------------------------------------------------------------------------
Garbage Collector TTF_Font
------------------------------------------------------------------------- */
static HB_GARBAGE_FUNC( hb_ttf_font_Destructor )
{
   TTF_Font **ppTTF_Font = ( TTF_Font ** ) Cargo;

   if( ppTTF_Font && *ppTTF_Font )
   {
      TTF_CloseFont( *ppTTF_Font );
      TTF_Quit();
      *ppTTF_Font = NULL;
   }
}

static const HB_GC_FUNCS s_gc_ttf_font_Funcs =
{
   hb_ttf_font_Destructor,
   hb_gcDummyMark
};

TTF_Font *hb_ttf_font_ParamPtr( int iParam )
{
   TTF_Font **ppTTF_Font = ( TTF_Font ** ) hb_parptrGC( &s_gc_ttf_font_Funcs, iParam );

   if( ppTTF_Font && *ppTTF_Font )
   {
      return *ppTTF_Font;
   }
   else
   {
      HB_ERR_ARGS();
      return NULL;
   }
}

TTF_Font *hb_ttf_font_ParamGet( int iParam )
{
   TTF_Font **ppTTF_Font = ( TTF_Font ** ) hb_parptrGC( &s_gc_ttf_font_Funcs, iParam );

   return IIF( ppTTF_Font, *ppTTF_Font, NULL );
}

TTF_Font *hb_ttf_font_ItemGet( PHB_ITEM pItem )
{
   TTF_Font **ppTTF_Font = ( TTF_Font ** ) hb_itemGetPtrGC( pItem, &s_gc_ttf_font_Funcs );

   return IIF( ppTTF_Font, *ppTTF_Font, NULL );
}

PHB_ITEM hb_ttf_font_ItemPut( PHB_ITEM pItem, TTF_Font *pTTF_Font )
{
   TTF_Font **ppTTF_Font = ( TTF_Font ** ) hb_gcAllocate( sizeof( TTF_Font * ), &s_gc_ttf_font_Funcs );

   *ppTTF_Font = pTTF_Font;
   return hb_itemPutPtrGC( pItem, ppTTF_Font );
}

void hb_ttf_font_ItemClear( PHB_ITEM pItem )
{
   TTF_Font **ppTTF_Font = ( TTF_Font ** ) hb_itemGetPtrGC( pItem, &s_gc_ttf_font_Funcs );

   if( ppTTF_Font )
      *ppTTF_Font = NULL;
}

void hb_ttf_font_Return( TTF_Font *pTTF_Font )
{
   if( pTTF_Font )
   {
      hb_ttf_font_ItemPut( hb_param( -1, HB_IT_ANY ), pTTF_Font );
   }
   else
   {
      hb_ret();
   }
}

/* -------------------------------------------------------------------------
API SDL3_ttf
------------------------------------------------------------------------- */
HB_FUNC( TTF_APPENDTEXTSTRING )
{

}

HB_FUNC( TTF_CLOSEFONT )
{

}

HB_FUNC( TTF_CREATEGPUTEXTENGINE )
{

}

HB_FUNC( TTF_CREATERENDERERTEXTENGINE )
{

}

HB_FUNC( TTF_CREATESURFACETEXTENGINE )
{

}

HB_FUNC( TTF_CREATETEXT )
{

}

HB_FUNC( TTF_DELETETEXTSTRING )
{

}

HB_FUNC( TTF_DESTROYGPUTEXTENGINE )
{

}

HB_FUNC( TTF_DESTROYRENDERERTEXTENGINE )
{

}

HB_FUNC( TTF_DESTROYSURFACETEXTENGINE )
{

}

HB_FUNC( TTF_DESTROYTEXT )
{

}

HB_FUNC( TTF_DRAWRENDERERTEXT )
{

}

HB_FUNC( TTF_DRAWSURFACETEXT )
{

}

HB_FUNC( TTF_FONTHASGLYPH )
{

}

HB_FUNC( TTF_FONTISFIXEDWIDTH )
{

}

HB_FUNC( TTF_FONTISSCALABLE )
{

}

HB_FUNC( TTF_GETFONTASCENT )
{

}

HB_FUNC( TTF_GETFONTDESCENT )
{

}

HB_FUNC( TTF_GETFONTDIRECTION )
{

}

HB_FUNC( TTF_GETFONTDPI )
{

}

HB_FUNC( TTF_GETFONTFAMILYNAME )
{

}

HB_FUNC( TTF_GETFONTGENERATION )
{

}

HB_FUNC( TTF_GETFONTHEIGHT )
{

}

HB_FUNC( TTF_GETFONTHINTING )
{

}

HB_FUNC( TTF_GETFONTKERNING )
{

}

// int TTF_GetFontLineSkip( const TTF_Font *font );
HB_FUNC( TTF_GETFONTLINESKIP )
{
   if( hb_param( 1, HB_IT_POINTER ) != NULL )
   {
      hb_retni( TTF_GetFontLineSkip( hb_ttf_font_ParamPtr( 1 ) ) );
   }
   else
   {
      HB_ERR_ARGS();
   }
}

HB_FUNC( TTF_GETFONTOUTLINE )
{

}

HB_FUNC( TTF_GETFONTPROPERTIES )
{

}

HB_FUNC( TTF_GETFONTSDF )
{

}

HB_FUNC( TTF_GETFONTSIZE )
{

}

HB_FUNC( TTF_GETFONTSTYLE )
{

}

HB_FUNC( TTF_GETFONTSTYLENAME )
{

}

HB_FUNC( TTF_GETFONTWRAPALIGNMENT )
{

}

HB_FUNC( TTF_GETFREETYPEVERSION )
{

}

HB_FUNC( TTF_GETGLYPHIMAGE )
{

}

HB_FUNC( TTF_GETGLYPHIMAGEFORINDEX )
{

}

HB_FUNC( TTF_GETGLYPHKERNING )
{

}

HB_FUNC( TTF_GETGLYPHMETRICS )
{

}

HB_FUNC( TTF_GETGLYPHSCRIPT )
{

}

HB_FUNC( TTF_GETGPUTEXTDRAWDATA )
{

}

HB_FUNC( TTF_GETHARFBUZZVERSION )
{

}

HB_FUNC( TTF_GETNEXTTEXTSUBSTRING )
{

}

HB_FUNC( TTF_GETPREVIOUSTEXTSUBSTRING )
{

}

HB_FUNC( TTF_GETSTRINGSIZE )
{

}

HB_FUNC( TTF_GETSTRINGSIZEWRAPPED )
{

}

HB_FUNC( TTF_GETTEXTCOLOR )
{

}

HB_FUNC( TTF_GETTEXTCOLORFLOAT )
{

}

HB_FUNC( TTF_GETTEXTENGINE )
{

}

HB_FUNC( TTF_GETTEXTFONT )
{

}

HB_FUNC( TTF_GETTEXTPOSITION )
{

}

HB_FUNC( TTF_GETTEXTPROPERTIES )
{

}

HB_FUNC( TTF_GETTEXTSIZE )
{

}

HB_FUNC( TTF_GETTEXTSUBSTRING )
{

}

HB_FUNC( TTF_GETTEXTSUBSTRINGFORLINE )
{

}

HB_FUNC( TTF_GETTEXTSUBSTRINGFORPOINT )
{

}

HB_FUNC( TTF_GETTEXTSUBSTRINGSFORRANGE )
{

}

HB_FUNC( TTF_GETTEXTWRAPWIDTH )
{

}

//bool TTF_Init( void );
HB_FUNC( TTF_INIT )
{
   hb_retl( TTF_Init() );
}

HB_FUNC( TTF_INSERTTEXTSTRING )
{

}

// bool TTF_MeasureString( TTF_Font *font, const char *text, size_t length, int max_width, int *measured_width, size_t *measured_length );
HB_FUNC( TTF_MEASURESTRING )
{
   PHB_ITEM pItemWidth  = hb_param( 5, HB_IT_BYREF | HB_IT_NIL );
   PHB_ITEM pItemLength = hb_param( 6, HB_IT_BYREF | HB_IT_NIL );

   if( hb_param( 1, HB_IT_POINTER ) != NULL && hb_param( 2, HB_IT_STRING ) != NULL && hb_param( 3, HB_IT_NUMINT ) != NULL && hb_param( 4, HB_IT_INTEGER ) != NULL &&
      ( pItemWidth  || HB_ISNIL( 5 ) ) &&
      ( pItemLength || HB_ISNIL( 6 ) ) )
   {
      int measured_width = 0;
      size_t measured_length = 0;

      hb_retl( TTF_MeasureString( hb_ttf_font_ParamPtr( 1 ), hb_parc( 2 ), hb_parns( 3 ), hb_parni( 4 ), &measured_width, &measured_length ) );
      if( pItemWidth )
      {
         hb_storni( measured_width, 5 );
      }
      if( pItemLength )
      {
         hb_storns( measured_length, 6 );
      }
   }
   else
   {
      HB_ERR_ARGS();
   }
}

// TTF_Font *TTF_OpenFont( const char *file, float ptsize );
HB_FUNC( TTF_OPENFONT )
{
   if( hb_param( 1, HB_IT_STRING ) != NULL && hb_param( 2, HB_IT_NUMERIC ) != NULL )
   {
      hb_ttf_font_Return( TTF_OpenFont( hb_parc( 1 ), ( float ) hb_parnd( 2 ) ) );
   }
   else
   {
      HB_ERR_ARGS();
   }
}

HB_FUNC( TTF_OPENFONTIO )
{

}

HB_FUNC( TTF_OPENFONTWITHPROPERTIES )
{

}

HB_FUNC( TTF_QUIT )
{

}

// SDL_Surface *TTF_RenderGlyph_Blended( TTF_Font *font, Uint32 ch, SDL_Color fg );
HB_FUNC( TTF_RENDERGLYPH_BLENDED )
{
   PHB_ITEM pArray;

   if( hb_param( 1, HB_IT_POINTER ) != NULL && hb_param( 2, HB_IT_NUMINT ) != NULL && ( pArray = hb_param( 3, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pArray ) == 4 )
   {
      SDL_Color color = hb_sdl_color_param_array( pArray );

      hb_sdl_surface_Return( TTF_RenderGlyph_Blended( hb_ttf_font_ParamPtr( 1 ), ( Uint32 ) hb_parni( 2 ), color ) );
   }
   else
   {
      HB_ERR_ARGS();
   }
}

HB_FUNC( TTF_RENDERGLYPH_LCD )
{

}

HB_FUNC( TTF_RENDERGLYPH_SHADED )
{

}

HB_FUNC( TTF_RENDERGLYPH_SOLID )
{

}

HB_FUNC( TTF_RENDERTEXT_BLENDED )
{

}

HB_FUNC( TTF_RENDERTEXT_BLENDED_WRAPPED )
{

}

HB_FUNC( TTF_RENDERTEXT_LCD )
{

}

// SDL_Surface *TTF_RenderText_LCD_Wrapped( TTF_Font *font, const char *text, size_t length, SDL_Color fg, SDL_Color bg, int wrap_width );
HB_FUNC( TTF_RENDERTEXT_LCD_WRAPPED )
{

}

// SDL_Surface *TTF_RenderText_Shaded( TTF_Font *font, const char *text, size_t length, SDL_Color fg, SDL_Color bg );
HB_FUNC( TTF_RENDERTEXT_SHADED )
{
   PHB_ITEM pArray1;
   PHB_ITEM pArray2;

   if( hb_param( 1, HB_IT_POINTER ) != NULL && hb_param( 2, HB_IT_STRING ) != NULL && hb_param( 3, HB_IT_NUMINT ) != NULL &&
      ( pArray1 = hb_param( 4, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pArray1 ) == 4 &&
      ( pArray2 = hb_param( 5, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pArray2 ) == 4 )
   {
      SDL_Color fg = hb_sdl_color_param_array( pArray1 );
      SDL_Color bg = hb_sdl_color_param_array( pArray2 );

      hb_sdl_surface_Return( TTF_RenderText_Shaded( hb_ttf_font_ParamPtr( 1 ), hb_parc( 2 ), hb_parns( 3 ), fg, bg ) );
   }
   else
   {
      HB_ERR_ARGS();
   }
}

// SDL_Surface *TTF_RenderText_Shaded_Wrapped( TTF_Font *font, const char *text, size_t length, SDL_Color fg, SDL_Color bg, int wrap_width );
HB_FUNC( TTF_RENDERTEXT_SHADED_WRAPPED )
{
   PHB_ITEM pArray1;
   PHB_ITEM pArray2;

   if( hb_param( 1, HB_IT_POINTER ) != NULL && hb_param( 2, HB_IT_STRING ) != NULL && hb_param( 3, HB_IT_NUMINT ) != NULL &&
      ( pArray1 = hb_param( 4, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pArray1 ) == 4 &&
      ( pArray2 = hb_param( 5, HB_IT_ARRAY ) ) != NULL && hb_arrayLen( pArray2 ) == 4 &&
      hb_param( 6, HB_IT_INTEGER ) != NULL )
   {
      SDL_Color fg = hb_sdl_color_param_array( pArray1 );
      SDL_Color bg = hb_sdl_color_param_array( pArray2 );

      hb_sdl_surface_Return( TTF_RenderText_Shaded_Wrapped( hb_ttf_font_ParamPtr( 1 ), hb_parc( 2 ), hb_parns( 3 ), fg, bg, hb_parni( 6 ) ) );
   }
   else
   {
      HB_ERR_ARGS();
   }
}

HB_FUNC( TTF_RENDERTEXT_SOLID )
{

}

HB_FUNC( TTF_RENDERTEXT_SOLID_WRAPPED )
{

}

HB_FUNC( TTF_SETFONTDIRECTION )
{

}

HB_FUNC( TTF_SETFONTHINTING )
{

}

HB_FUNC( TTF_SETFONTKERNING )
{

}

HB_FUNC( TTF_SETFONTLANGUAGE )
{

}

HB_FUNC( TTF_SETFONTLINESKIP )
{

}

HB_FUNC( TTF_SETFONTOUTLINE )
{

}

HB_FUNC( TTF_SETFONTSCRIPT )
{

}

HB_FUNC( TTF_SETFONTSDF )
{

}

HB_FUNC( TTF_SETFONTSIZE )
{

}

HB_FUNC( TTF_SETFONTSIZEDPI )
{

}

HB_FUNC( TTF_SETFONTSTYLE )
{

}

HB_FUNC( TTF_SETFONTWRAPALIGNMENT )
{

}

HB_FUNC( TTF_SETTEXTCOLOR )
{

}

HB_FUNC( TTF_SETTEXTCOLORFLOAT )
{

}

HB_FUNC( TTF_SETTEXTENGINE )
{

}

HB_FUNC( TTF_SETTEXTFONT )
{

}

HB_FUNC( TTF_SETTEXTPOSITION )
{

}

HB_FUNC( TTF_SETTEXTSTRING )
{

}

HB_FUNC( TTF_SETTEXTWRAPWHITESPACEVISIBLE )
{

}

HB_FUNC( TTF_SETTEXTWRAPWIDTH )
{

}

HB_FUNC( TTF_TEXTWRAPWHITESPACEVISIBLE )
{

}

HB_FUNC( TTF_UPDATETEXT )
{

}

HB_FUNC( TTF_VERSION )
{

}

HB_FUNC( TTF_WASINIT )
{

}

