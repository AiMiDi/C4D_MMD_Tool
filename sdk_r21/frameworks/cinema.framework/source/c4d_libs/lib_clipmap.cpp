#ifndef __API_INTERN__

#include "lib_clipmap.h"
#include "c4d_basecontainer.h"

static GeClipMapLib *lib_GeClipMap = nullptr;

static GeClipMapLib *CheckLib(Int32 offset)
{
	return (GeClipMapLib*)CheckLib(LIB_CLIPMAP, offset, (C4DLibrary**)&lib_GeClipMap);
}

#define GeClipMapCall(b)      GeClipMapLib *lib = CheckLib(LIBOFFSET(GeClipMapLib, b)); \
															if (!lib || !lib->b) return; \
															(((iGeClipMap*)this)->*lib->b)

#define GeClipMapCallR(a, b)   GeClipMapLib *lib = CheckLib(LIBOFFSET(GeClipMapLib, b)); \
															if (!lib || !lib->b) return a; \
															return (((iGeClipMap*)this)->*lib->b)

GeClipMap* GeClipMap::Alloc()
{
	GeClipMapLib *lib = CheckLib(LIBOFFSET(GeClipMapLib, Alloc));
	if (!lib || !lib->Alloc) return nullptr;
	return lib->Alloc();
}

void GeClipMap::Free(GeClipMap *&data)
{
	GeClipMapLib *lib = CheckLib(LIBOFFSET(GeClipMapLib, Free));
	if (!lib || !lib->Free) return;
	lib->Free(data);
}

GeClipMap::GeClipMap()
{
}

IMAGERESULT GeClipMap::Init(const IconData& iconData)
{
	GeClipMapCallR(IMAGERESULT::NOTEXISTING, InitWithIconData )(iconData);
}

IMAGERESULT GeClipMap::Init(GeUserArea* userArea, Int32 x, Int32 y, Int32 w, Int32 h)
{
	GeClipMapCallR(IMAGERESULT::NOTEXISTING, InitWithUserArea)(userArea, x, y, w, h);
}

IMAGERESULT GeClipMap::Init(Int32 w, Int32 h, Int32 bits)
{
	GeClipMapCallR(IMAGERESULT::NOTEXISTING, Init )(w, h, bits);
}

IMAGERESULT GeClipMap::Init(BaseBitmap *bm)
{
	GeClipMapCallR(IMAGERESULT::NOTEXISTING, InitWith )(bm);
}

IMAGERESULT GeClipMap::Init(BaseBitmap *bm, BaseBitmap *alpha_channel)
{
	GeClipMapCallR(IMAGERESULT::NOTEXISTING, InitFrom )(bm, alpha_channel);
}

IMAGERESULT GeClipMap::Init(const Filename &name, Int32 frame, Bool *ismovie)
{
	GeClipMapCallR(IMAGERESULT::NOTEXISTING, InitFromFile )(name, frame, ismovie);
}

void GeClipMap::Destroy()
{
	GeClipMapCall(Destroy )();
}

void GeClipMap::GetDim(Int32 *w, Int32 *h) const
{
	GeClipMapCall(GetDim )(w, h);
}

Int32 GeClipMap::GetBw() const
{
	GeClipMapCallR(NOTOK, GetBw )();
}

Int32 GeClipMap::GetBh() const
{
	GeClipMapCallR(NOTOK, GetBh )();
}

BaseBitmap* GeClipMap::GetBitmap()
{
	GeClipMapCallR(nullptr, GetBitmap )();
}

const BaseBitmap* GeClipMap::GetBitmap() const
{
	return const_cast<GeClipMap*>(this)->GetBitmap();
}

void GeClipMap::BeginDraw()
{
	GeClipMapCall(BeginDraw )();
}

void GeClipMap::EndDraw()
{
	GeClipMapCall(EndDraw )();
}

void GeClipMap::SetOffset(Int32 off_x, Int32 off_y)
{
	GeClipMapCall(SetOffset )(off_x, off_y);
}

void GeClipMap::SetDrawMode(GE_CM_DRAWMODE mode, UInt32 par)
{
	GeClipMapCall(SetDrawMode )(mode, par);
}

void GeClipMap::SetColor(Int32 r, Int32 g, Int32 b, Int32 a)
{
	GeClipMapCall(SetColor )(r, g, b, a);
}

void GeClipMap::SetPixel(Int32 x, Int32 y)
{
	GeClipMapCall(SetPixel )(x, y);
}

void GeClipMap::Line(Int32 x1, Int32 y1, Int32 x2, Int32 y2)
{
	GeClipMapCall(CMLine )(x1, y1, x2, y2);
}

Bool GeClipMap::SupportsDrawBezierSegment() const
{
	GeClipMapCallR(false, SupportsDrawBezierSegment)();
}

void GeClipMap::DrawBezierSegment(const maxon::Vector2d* p)
{
	GeClipMapCall(DrawBezierSegment)(p);
}

void GeClipMap::PolyLine(Int32 cnt, GE_POINT2D *points)
{
	GeClipMapCall(PolyLine )(cnt, points);
}

void GeClipMap::FillPolygon(Int32 cnt, GE_POINT2D *points)
{
	GeClipMapCall(FillPolygon )(cnt, points);
}

void GeClipMap::Rect(Int32 x1, Int32 y1, Int32 x2, Int32 y2)
{
	GeClipMapCall(Rect )(x1, y1, x2, y2);
}

void GeClipMap::FillRect(Int32 x1, Int32 y1, Int32 x2, Int32 y2)
{
	GeClipMapCall(FillRect )(x1, y1, x2, y2);
}

void GeClipMap::Arc(Int32 x1, Int32 y1, Int32 x2, Int32 y2, GE_CM_ARCSEGMENT seg)
{
	GeClipMapCall(Arc )(x1, y1, x2, y2, seg);
}

void GeClipMap::FillArc(Int32 x1, Int32 y1, Int32 x2, Int32 y2, GE_CM_ARCSEGMENT seg)
{
	GeClipMapCall(FillArc )(x1, y1, x2, y2, seg);
}

void GeClipMap::Ellipse(Int32 x1, Int32 y1, Int32 x2, Int32 y2)
{
	GeClipMapCall(Ellipse )(x1, y1, x2, y2);
}

void GeClipMap::FillEllipse(Int32 x1, Int32 y1, Int32 x2, Int32 y2)
{
	GeClipMapCall(FillEllipse )(x1, y1, x2, y2);
}

void GeClipMap::SetPixelRGBA(Int32 x, Int32 y, Int32 r, Int32 g, Int32 b, Int32 a)
{
	GeClipMapCall(SetPixelRGBA )(x, y, r, g, b, a);
}

void GeClipMap::GetPixelRGBA(Int32 x, Int32 y, Int32 *r, Int32 *g, Int32 *b, Int32 *a)
{
	GeClipMapCall(GetPixelRGBA )(x, y, r, g, b, a);
}

void GeClipMap::TextAt(Int32 x, Int32 y, const String &txt)
{
	GeClipMapCall(TextAt )(x, y, txt);
}

Int32 GeClipMap::GetTextWidth(const String &txt)
{
	GeClipMapCallR(0, GetTextWidth )(txt);
}

Int32 GeClipMap::GetTextHeight()
{
	GeClipMapCallR(0, GetTextHeight )();
}

Int32 GeClipMap::GetTextAscent()
{
	GeClipMapCallR(0, GetTextAscent )();
}

void GeClipMap::Blit(Int32 dx, Int32 dy, const GeClipMap &s_dp, Int32 sx1, Int32 sy1, Int32 sx2, Int32 sy2, GE_CM_BLIT rop)
{
	GeClipMapCall(Blit )(dx, dy, *(const iGeClipMap *) &s_dp, sx1, sy1, sx2, sy2, rop);
}

void GeClipMap::SetClipRgn(Int32 left, Int32 top, Int32 right, Int32 bottom)
{
	GeClipMapCall(SetClipRgn )(left, top, right, bottom);
}

void GeClipMap::SetClipRgn(GE_POINT2D *points, Int32 count, GE_CM_CLIPREGION mode)
{
	GeClipMapCall(SetClipRgn2 )(points, count, mode);
}

Bool GeClipMap::ClipPoint(Int32 x, Int32 y)
{
	GeClipMapCallR(false, ClipPoint )(x, y);
}

Int32 GeClipMap::ClipArea(Int32 x1, Int32 y1, Int32 x2, Int32 y2)
{
	GeClipMapCallR(false, ClipArea )(x1, y1, x2, y2);
}

//----------------------------------------------------------------------------------------
// Set the current font
// Function result:		true if successful
// font_description:	font description (from GeChooseFont(), GetFontDescription() or EnumerateFonts()) or nullptr (default font)
// font_size:					requested font size (0.0: the size is read from the font description and if that doesn't have a size a default setting is used)
//----------------------------------------------------------------------------------------
Bool	GeClipMap::SetFont(BaseContainer const *font_description, Float font_size)
{
	GeClipMapCallR(false, SetFont )(font_description, font_size);
}

//----------------------------------------------------------------------------------------
// Get the current font description
// Function result:		font size
// font_description:	used to return the font description
//----------------------------------------------------------------------------------------
Float	GeClipMap::GetFont(BaseContainer *font_description)
{
	GeClipMapCallR(0.0, GetFont )(font_description);
}

//----------------------------------------------------------------------------------------
// Return a font description for one of the default fonts
// Function result:		true if type is valid
// type:							the requested kind of default font
// font_description:	used to return container with font description (e.g. from GeChooseFont)
//----------------------------------------------------------------------------------------
Bool	GeClipMap::GetDefaultFont(GeFontDefaultType type, BaseContainer *font_description)
{
	GeClipMapLib *lib = CheckLib(LIBOFFSET(GeClipMapLib, GetDefaultFont));
	if (lib && lib->GetFontSize)
		return lib->GetDefaultFont(type, font_description);

	return false;
}

//----------------------------------------------------------------------------------------
// Get the font size (in an unspecified unit)
// To get the size in pixels you have to set the font and call GetHeight() and GetAscent()
// Function result:		true if the font size was specified
// font_description:	container with font description (e.g. from GeChooseFont)
// type:							currently GE_FONT_SIZE_INTERNAL only
// size:							used to return the font size
//----------------------------------------------------------------------------------------
Bool	GeClipMap::GetFontSize(BaseContainer const *font_description, GeFontSizeType type, Float *size)
{
	GeClipMapLib *lib = CheckLib(LIBOFFSET(GeClipMapLib, GetFontSize));
	if (lib && lib->GetFontSize)
		return lib->GetFontSize(font_description, type, size);

	return false;
}

//----------------------------------------------------------------------------------------
// Set the font size (in an OS specific unit)
// Function result:		true if the font size was specified
// font_description:	container with font description (e.g. from GeChooseFont)
// type:							currently GE_FONT_SIZE_INTERNAL only
// size:							the font size
//----------------------------------------------------------------------------------------
Bool	GeClipMap::SetFontSize(BaseContainer *font_description, GeFontSizeType type, Float size)
{
	GeClipMapLib *lib = CheckLib(LIBOFFSET(GeClipMapLib, SetFontSize));
	if (lib && lib->SetFontSize)
		return lib->SetFontSize(font_description, type, size);

	return false;
}

//----------------------------------------------------------------------------------------
// Get a font name from a font description
// Function result:		true if the requested name could be found
// font_description:	container with font description (e.g. from GeChooseFont)
// type:							the requested kind of name (display, family, style or postscript name)
// dst:								used to return the name string
//----------------------------------------------------------------------------------------
Bool	GeClipMap::GetFontName(BaseContainer const *font_description, GeFontNameType type, String *dst)
{
	GeClipMapLib *lib = CheckLib(LIBOFFSET(GeClipMapLib, GetFontName));
	if (lib && lib->GetFontName)
		return lib->GetFontName(font_description, type, dst);

	return false;
}

//----------------------------------------------------------------------------------------
// Build a font description
// Function result:		true if the description is valid
// name:							font name
// type:							kind of name (currently only GE_FONT_NAME_POSTSCRIPT is supported)
// dst:								used to return the font description
//----------------------------------------------------------------------------------------
Bool	GeClipMap::GetFontDescription(String const &name, GeFontNameType type, BaseContainer *dst)
{
	GeClipMapLib *lib = CheckLib(LIBOFFSET(GeClipMapLib, GetFontDescription));
	if (lib && lib->GetFontDescription)
		return lib->GetFontDescription(name, type, dst);

	return false;
}

//----------------------------------------------------------------------------------------
// Enumerate all fonts and return them in a BaseContainer
// If sort_mode is GE_CM_FONTSORT::FLAT for each font a BaseContainer will be inserted that
// can be used for SetFont() or GetFontName() or as input for GeChooseFont(). The font
// descriptions will be in no particular order
// If sort_mode is GE_CM_FONTSORT::HIERARCHICAL for each family a BaseContainer will be inserted
// that will contain BaseContainers describing the fonts belonging to the family. The families
// are guaranteed to be in alphabetical order
// Function result:		-
// dst:								used to return the font list
// sort_mode:					GE_CM_FONTSORT::HIERARCHICAL: for each font family a BaseContainer is
//										stored in dst and will hold a description for each font of this family (one
//										BaseContainer per font). The font families are sorted alphabetically
//										GE_CM_FONTSORT::FLAT: one BaseContainer per font, no order guaranteed
//----------------------------------------------------------------------------------------
void	GeClipMap::EnumerateFonts(BaseContainer *dst, GE_CM_FONTSORT sort_mode)
{
	GeClipMapLib *lib = CheckLib(LIBOFFSET(GeClipMapLib, EnumerateFonts));
	if (lib && lib->EnumerateFonts)
		lib->EnumerateFonts(dst, sort_mode);
	else
		dst->FlushAll();
}

#endif
