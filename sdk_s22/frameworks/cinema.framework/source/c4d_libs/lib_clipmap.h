/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef LIB_CLIPMAP_H__
#define LIB_CLIPMAP_H__

#include "c4d_library.h"

#ifdef __API_INTERN__

#include "ge_file.h"
#include "ge_cp2d.h"

#define iGeClipMap	GeClipMap

#else

#include "c4d_file.h"
#include "maxon/vector2d.h"

/// @addtogroup group_clipmaplibrary Clipmap
/// @ingroup group_library
/// @{

/// @addtogroup GE_CM_CLIPREGION
/// @ingroup group_enumeration
/// @{
enum class GE_CM_CLIPREGION
{
	EVENODD		= 1,			///< Enclosed regions of the path alternate between interior and exterior areas as traversed from the outside of the path towards a point inside the region.
	WINDING_	= 2				///< If a ray is drawn in any direction from a given point to infinity and the places where the path intersects the ray are examined:\n
											///< The point is inside of the path if and only if the number of times that the path crosses the ray from left to right does not equal the number of times that the path crosses the ray from right to left.
} MAXON_ENUM_LIST(GE_CM_CLIPREGION);
/// @}

/// @addtogroup GE_CM_DRAWMODE
/// @ingroup group_enumeration
/// @{
enum class GE_CM_DRAWMODE
{
	COPY			= 0,			///< New pixels overwrite old ones.
	BLEND			= 1,			///< New pixels blend with old ones, taking the alpha value of the new pixels in account as well as the blend factor specified by the parameter.\n
											///< The value specified by the parameter is the opacity of the source (bitmap). It ranges from @em 0 to @em 256, where @em 256 equals @em 1.0 and means opaque.
	MASK			= 2				///< New pixels overwrite the old ones at the bits where the mask specified by the parameter equals @em 1.
} MAXON_ENUM_LIST(GE_CM_DRAWMODE);
/// @}

#ifndef GE_CM_SRC_MAX_OPACITY
#define GE_CM_SRC_MAX_OPACITY 256			///< Maximum source opacity for:: GE_CM_DRAWMODE::BLEND and equals @em 1.0, which means opaque (@em 128 equals @em 0.5 etc.).
#endif

/// @addtogroup GE_CM_BLIT
/// @ingroup group_enumeration
/// @{
enum class GE_CM_BLIT
{
	COPY			= 0,			///< Source overwrites destination.
	COL			= 1,			///< Source overwrites destination everywhere where source does not equal the background color.
	FG				= 2				///< Sets pixels to the foreground color if the color is not the background color.
} MAXON_ENUM_LIST(GE_CM_BLIT);
/// @}

/// @addtogroup GE_CM_ARCSEGMENT
/// @ingroup group_enumeration
/// @{
enum class GE_CM_ARCSEGMENT
{
	RIGHTTOP			= 0,			///< (x1,y1) -> (x2,y1) -> (x2,y2)
	RIGHTBOTTOM	= 1,			///< (x2,y1) -> (x2,y2) -> (x1,y2)
	LEFTBOTTOM		= 2,			///< (x2,y2) -> (x1,y2) -> (x1,y1)
	LEFTTOP			= 3			///< (x1,y2) -> (x1,y1) -> (x2,y1)
} MAXON_ENUM_LIST(GE_CM_ARCSEGMENT);
/// @}

/// @addtogroup GE_CM_FONTSORT
/// @ingroup group_enumeration
/// @{
enum class GE_CM_FONTSORT
{
	FLAT					= 0,			///< For each font family a BaseContainer is stored and will hold a description for each font of this family (one BaseContainer per font).\n
																				///< The font families are sorted alphabetically.
	HIERARCHICAL	= 1				///< One BaseContainer per font, no order guaranteed.
} MAXON_ENUM_LIST(GE_CM_FONTSORT);
/// @}

class BaseBitmap;

typedef struct _NGV_DRAW_PORT*		NGVH_DP;
typedef struct _NGV_RGN*					NGVH_RGN;

struct GE_POINT2D
{
	Int32 x;			///< X coordinate.
	Int32 y;			///< Y coordinate.
};

/// @addtogroup GeFontNameType
/// @ingroup group_enumeration
/// @{
enum GeFontNameType
{
	GE_FONT_NAME_DISPLAY	= 0,			///< Human readable font name (e.g. "Helvetica Bold").
	GE_FONT_NAME_FAMILY		= 1,			///< Font family name (e.g. "Helvetica").
	GE_FONT_NAME_STYLE		= 2,			///< Font style name (e.g. "Bold").
	GE_FONT_NAME_POSTSCRIPT = 3			///< Font postscript name (e.g. "Helvetica-Bold").
};
/// @}

/// @addtogroup GeFontDefaultType
/// @ingroup group_enumeration
/// @{
enum GeFontDefaultType
{
	GE_FONT_DEFAULT_SYSTEM			= 0,			///< The @C4D system font.
	GE_FONT_DEFAULT_MONOSPACED	= 1				///< The @C4D monospaced font.
};
/// @}

/// @addtogroup GeFontSizeType
/// @ingroup group_enumeration
/// @{
enum GeFontSizeType
{
	GE_FONT_SIZE_INTERNAL = 0			///< The unit of the font size is not specified (OS or context dependent).\n
																///< It is not guaranteed to be pixels or points or whatever. Use it only to compare the size of 2 font descriptions.
};
/// @}

class GeUserArea;

//----------------------------------------------------------------------------------------
/// This class stores and manipulates a bitmap, providing more advanced drawing tools than BaseBitmap.\n
/// Be sure to call Init() before trying to use a newly allocated clip map.
/// @note Though clip maps support other bit depths than @em 32, the functionality is severely limited.\n
///				It is recommended that the clip map class is only used for @em 32 bit bitmaps. (Please note that the default bit depth for BaseBitmap is @em 24).
///
/// @addAllocFreeAutoAllocNote
//----------------------------------------------------------------------------------------
class GeClipMap

{
	public:
	/// @name Alloc/Free
	/// @{

	//----------------------------------------------------------------------------------------
	/// @allocatesA{clip map}
	/// @return												@allocReturn{clip map}
	//----------------------------------------------------------------------------------------
		static GeClipMap* Alloc();

	//----------------------------------------------------------------------------------------
	/// @destructsAlloc{clip maps}
	/// @param[in] data								@theToDestruct{clip map}
	//----------------------------------------------------------------------------------------
		static void Free(GeClipMap *&data);

	/// @}

	private:
		GeClipMap();
		~GeClipMap();

	public:
		/// @name Init
		/// @{

		//----------------------------------------------------------------------------------------
		/// Initializes the clip map bitmap to the given dimensions and depth. Any previous data is lost.
		/// @param[in] w									The width in pixels.
		/// @param[in] h									The height in pixels.
		/// @param[in] bits								The requested bit depth. The possible values are {@em 1, @em 4, @em 8, @em 16, @em 24, @em 32}. On some platforms @em 32 bits will be used even if @em 24 is requested, to allow for padding.
		/// @return												The result: @enumerateEnum{IMAGERESULT}
		//----------------------------------------------------------------------------------------
		IMAGERESULT Init(Int32 w, Int32 h, Int32 bits);

		//----------------------------------------------------------------------------------------
		/// Loads the clip map bitmap from @formatParam{bm}. Any previous data is lost.
		/// @param[in] bm									The bitmap to initialize the clip map with. @callerOwnsPointed{bitmap}
		/// @return												The result: @enumerateEnum{IMAGERESULT}
		//----------------------------------------------------------------------------------------
		IMAGERESULT Init(BaseBitmap *bm);

		//----------------------------------------------------------------------------------------
		/// Loads the clip map bitmap from @formatParam{bm} with the specified alpha channel. Any previous data is lost.
		/// @param[in] bm									The bitmap to initialize the clip map with. @callerOwnsPointed{bitmap}
		/// @param[in] alpha_channel			The alpha channel to use in @formatParam{bm}. @callerOwnsPointed{bitmap}
		/// @return												The result: @enumerateEnum{IMAGERESULT}
		//----------------------------------------------------------------------------------------
		IMAGERESULT Init(BaseBitmap *bm, BaseBitmap *alpha_channel);

		//----------------------------------------------------------------------------------------
		/// Loads the clip map bitmap from the file specified by @formatParam{name}. The file can be either a movie or a picture. The file format is automatically detected. Any previous data is lost.
		/// @param[in] name								A valid filename.
		/// @param[in] frame							The frame number to load in a movie.
		/// @param[out] ismovie						If not @formatConstant{nullptr} this is assigned @formatConstant{true} if the loaded picture was a movie, and @formatConstant{false} otherwise.
		/// @return												The result: @enumerateEnum{IMAGERESULT}
		//----------------------------------------------------------------------------------------
		IMAGERESULT Init(const Filename &name, Int32 frame, Bool *ismovie);

		//----------------------------------------------------------------------------------------
		/// Loads the clip map bitmap from @formatParam{iconData}. Any previous data is lost.
		/// @param[in] iconData						The icon data to initialize the clip map with.
		/// @return												The result: @enumerateEnum{IMAGERESULT}
		//----------------------------------------------------------------------------------------
		IMAGERESULT Init(const IconData& iconData);

		IMAGERESULT Init(GeUserArea* userArea, Int32 x, Int32 y, Int32 w, Int32 h);

		/// @}

		/// @name Destroy
		/// @{

		//----------------------------------------------------------------------------------------
		/// Resets the clip map to its initial state and frees allocated memory.\n
		/// Requires a new call to Init() before the clip map can be used again.
		//----------------------------------------------------------------------------------------
		void Destroy();

		/// @}

		/// @name Dimensions
		/// @{

		//----------------------------------------------------------------------------------------
		/// Retrieves the pixel dimensions of the clip map.
		/// @param[in] w									Assigned the width.
		/// @param[in] h									Assigned the height.
		//----------------------------------------------------------------------------------------
		void GetDim(Int32 *w, Int32 *h) const;

		//----------------------------------------------------------------------------------------
		/// Retrieves the pixel width of the clip map.
		/// @return												The width.
		//----------------------------------------------------------------------------------------
		Int32 GetBw() const;

		//----------------------------------------------------------------------------------------
		/// Retrieves the pixel height of the clip map.
		/// @return												The height.
		//----------------------------------------------------------------------------------------
		Int32 GetBh() const;

		/// @}

		/// @name Bitmap
		/// @{

		//----------------------------------------------------------------------------------------
		/// Retrieves a pointer to the internal bitmap.
		/// @warning The clip map alpha channel will not be encoded in this bitmap. This is a limitation.
		/// @return												The internal bitmap. @theOwnsPointed{clip map,bitmap}
		//----------------------------------------------------------------------------------------
		BaseBitmap* GetBitmap();
		const BaseBitmap* GetBitmap() const;

		/// @}

		/// @name Begin/End Draw
		/// @{

		//----------------------------------------------------------------------------------------
		/// Must be called before any drawing functions.
		//----------------------------------------------------------------------------------------
		void BeginDraw();

		//----------------------------------------------------------------------------------------
		/// Must be called after a sequence of drawing functions to free the memory allocated by BeginDraw().
		//----------------------------------------------------------------------------------------
		void EndDraw();

		/// @}

		/// @name Set Offset/Draw Mode/Color
		/// @{

		//----------------------------------------------------------------------------------------
		/// Offsets all the following draw commands by the given amount.
		/// @note The clip region is not offset.
		/// @warning This function must be enclosed between BeginDraw() and EndDraw().
		/// @param[in] off_x							The X distance in pixels.
		/// @param[in] off_y							The Y distance in pixels.
		//----------------------------------------------------------------------------------------
		void SetOffset(Int32 off_x, Int32 off_y);

		//----------------------------------------------------------------------------------------
		/// Sets the draw mode.
		/// @warning This function must be enclosed between BeginDraw() and EndDraw().
		/// @param[in] mode								The draw mode: @enumerateEnum{GE_CM_DRAWMODE}
		/// @param[in] par								The parameter, depends on @formatParam{mode}.
		//----------------------------------------------------------------------------------------
		void SetDrawMode(GE_CM_DRAWMODE mode, UInt32 par);

		//----------------------------------------------------------------------------------------
		/// Sets the draw color.
		/// @warning This function must be enclosed between BeginDraw() and EndDraw().
		/// @param[in] r									The red value. (Between @em 0 and @em 255.)
		/// @param[in] g									The green value. (Between @em 0 and @em 255.)
		/// @param[in] b									The blue value. (Between @em 0 and @em 255.)
		/// @param[in] a									The alpha value. (Between @em 0 and @em 255.)
		//----------------------------------------------------------------------------------------
		void SetColor(Int32 r, Int32 g, Int32 b, Int32 a = 255);

		/// @}

		/// @name Drawing
		/// @{

		//----------------------------------------------------------------------------------------
		/// Sets the pixel at (@formatParam{x},@formatParam{y}) to the draw color.
		/// @warning This function must be enclosed between BeginDraw() and EndDraw().
		/// @param[in] x									The X coordinate.
		/// @param[in] y									The Y coordinate.
		//----------------------------------------------------------------------------------------
		void SetPixel(Int32 x, Int32 y);

		//----------------------------------------------------------------------------------------
		/// Draws a line from (@formatParam{x1},@formatParam{y1}) to (@formatParam{x2},@formatParam{y2}) with the draw color.
		/// @warning This function must be enclosed between BeginDraw() and EndDraw().
		/// @param[in] x1									The first X coordinate.
		/// @param[in] y1									The first Y coordinate.
		/// @param[in] x2									The second X coordinate.
		/// @param[in] y2									The second Y coordinate.
		//----------------------------------------------------------------------------------------
		void Line(Int32 x1, Int32 y1, Int32 x2, Int32 y2);

		//----------------------------------------------------------------------------------------
		/// Draws the polygon line specified by the @formatParam{cnt} @formatParam{points} with the draw color.
		/// @warning This function must be enclosed between BeginDraw() and EndDraw().
		/// @param[in] cnt								The number of elements in @formatParam{points}.
		/// @param[in] points							The points in the polygon line. @callerOwnsPointed{array}
		//----------------------------------------------------------------------------------------
		void PolyLine(Int32 cnt, GE_POINT2D *points);

		//----------------------------------------------------------------------------------------
		/// SupportsDrawBezierSegment returns true if the clipmap supports DrawBezierSegment().
		/// @return												true on success.
		//----------------------------------------------------------------------------------------
		Bool SupportsDrawBezierSegment() const;

		//----------------------------------------------------------------------------------------
		/// DrawBezierSegment description.
		/// @param[in] p									4 points for the bezier segment [p1, c1, c2, p2].
		//----------------------------------------------------------------------------------------
		void DrawBezierSegment(const maxon::Vector2d* p);

		//----------------------------------------------------------------------------------------
		/// Fills the polygon line specified by the @formatParam{cnt} @formatParam{points} with the draw color.
		/// @warning This function must be enclosed between BeginDraw() and EndDraw().
		/// @param[in] cnt								The number of elements in @formatParam{points}.
		/// @param[in] points							The points in the polygon. @callerOwnsPointed{array}
		//----------------------------------------------------------------------------------------
		void FillPolygon(Int32 cnt, GE_POINT2D *points);

		//----------------------------------------------------------------------------------------
		/// Draws the outline of a rectangle from (@formatParam{x1},@formatParam{y1}) to (@formatParam{x2},@formatParam{y2}) with the draw color.
		/// @warning This function must be enclosed between BeginDraw() and EndDraw().
		/// @param[in] x1									The top left X coordinate.
		/// @param[in] y1									The top left Y coordinate.
		/// @param[in] x2									The bottom right X coordinate.
		/// @param[in] y2									The bottom right Y coordinate.
		//----------------------------------------------------------------------------------------
		void Rect(Int32 x1, Int32 y1, Int32 x2, Int32 y2);

		//----------------------------------------------------------------------------------------
		/// Fills a rectangle from (@formatParam{x1},@formatParam{y1}) to (@formatParam{x2},@formatParam{y2}) with the draw color.
		/// @warning This function must be enclosed between BeginDraw() and EndDraw().
		/// @param[in] x1									The top left X coordinate.
		/// @param[in] y1									The top left Y coordinate.
		/// @param[in] x2									The bottom right X coordinate.
		/// @param[in] y2									The bottom right Y coordinate.
		//----------------------------------------------------------------------------------------
		void FillRect(Int32 x1, Int32 y1, Int32 x2, Int32 y2);

		//----------------------------------------------------------------------------------------
		/// Draws an arc within the rectangle from (@formatParam{x1},@formatParam{y1}) to (@formatParam{x2},@formatParam{y2}) with the draw color.
		/// @warning This function must be enclosed between BeginDraw() and EndDraw().
		/// @param[in] x1									The top left X coordinate.
		/// @param[in] y1									The top left Y coordinate.
		/// @param[in] x2									The bottom right X coordinate.
		/// @param[in] y2									The bottom right Y coordinate.
		/// @param[in] seg								The arc is drawn in the direction given by: @enumerateEnum{GE_CM_ARCSEGMENT}
		//----------------------------------------------------------------------------------------
		void Arc(Int32 x1, Int32 y1, Int32 x2, Int32 y2, GE_CM_ARCSEGMENT seg);

		//----------------------------------------------------------------------------------------
		/// Fills an arc within the rectangle from (@formatParam{x1},@formatParam{y1}) to (@formatParam{x2},@formatParam{y2}) with the draw color.
		/// @warning This function must be enclosed between BeginDraw() and EndDraw().
		/// @param[in] x1									The top left X coordinate.
		/// @param[in] y1									The top left Y coordinate.
		/// @param[in] x2									The bottom right X coordinate.
		/// @param[in] y2									The bottom right Y coordinate.
		/// @param[in] seg								The arc is drawn in the direction given by: @enumerateEnum{GE_CM_ARCSEGMENT}
		//----------------------------------------------------------------------------------------
		void FillArc(Int32 x1, Int32 y1, Int32 x2, Int32 y2, GE_CM_ARCSEGMENT seg);

		//----------------------------------------------------------------------------------------
		/// Draws an ellipse within the rectangle from (@formatParam{x1},@formatParam{y1}) to (@formatParam{x2},@formatParam{y2}) with the draw color.
		/// @warning This function must be enclosed between BeginDraw() and EndDraw().
		/// @param[in] x1									The top left X coordinate.
		/// @param[in] y1									The top left Y coordinate.
		/// @param[in] x2									The bottom right X coordinate.
		/// @param[in] y2									The bottom right Y coordinate.
		//----------------------------------------------------------------------------------------
		void Ellipse(Int32 x1, Int32 y1, Int32 x2, Int32 y2);

		//----------------------------------------------------------------------------------------
		/// Fills an ellipse within the rectangle from (@formatParam{x1},@formatParam{y1}) to (@formatParam{x2},@formatParam{y2}) with the draw color.
		/// @warning This function must be enclosed between BeginDraw() and EndDraw().
		/// @param[in] x1									The top left X coordinate.
		/// @param[in] y1									The top left Y coordinate.
		/// @param[in] x2									The bottom right X coordinate.
		/// @param[in] y2									The bottom right Y coordinate.
		//----------------------------------------------------------------------------------------
		void FillEllipse(Int32 x1, Int32 y1, Int32 x2, Int32 y2);

		/// @}

		/// @name Get/Set Pixel
		/// @{

		//----------------------------------------------------------------------------------------
		/// Retrieves the color of the pixel at (@formatParam{x},@formatParam{y}).
		/// @warning This function must be enclosed between BeginDraw() and EndDraw().
		/// @param[in] x									The X coordinate.
		/// @param[in] y									The Y coordinate.
		/// @param[out] r									Assigned the red value. (Between @em 0 and @em 255.)
		/// @param[out] g									Assigned the green value. (Between @em 0 and @em 255.)
		/// @param[out] b									Assigned the blue value. (Between @em 0 and @em 255.)
		/// @param[out] a									Assigned the alpha value. (Between @em 0 and @em 255.)
		//----------------------------------------------------------------------------------------
		void GetPixelRGBA(Int32 x, Int32 y, Int32 *r, Int32 *g, Int32 *b, Int32 *a);

		//----------------------------------------------------------------------------------------
		/// Sets the pixel at (@formatParam{x},@formatParam{y}) to the specified color.
		/// @warning This function must be enclosed between BeginDraw() and EndDraw().
		/// @param[in] x									The X coordinate.
		/// @param[in] y									The Y coordinate.
		/// @param[in] r									The red value. (Between @em 0 and @em 255.)
		/// @param[in] g									The green value. (Between @em 0 and @em 255.)
		/// @param[in] b									The blue value. (Between @em 0 and @em 255.)
		/// @param[in] a									Alpha value. (Between @em 0 and @em 255.)
		//----------------------------------------------------------------------------------------
		void SetPixelRGBA(Int32 x, Int32 y, Int32 r, Int32 g, Int32 b, Int32 a = 255);

		/// @}

		/// @name Text
		/// @{

		//----------------------------------------------------------------------------------------
		/// Draws the string @formatParam{txt} at (@formatParam{x},@formatParam{y}) with the current draw color.
		/// @warning This function must be enclosed between BeginDraw() and EndDraw().
		/// @param[in] x									The top left X coordinate.
		/// @param[in] y									The top left Y coordinate.
		/// @param[in] txt								The text.
		//----------------------------------------------------------------------------------------
		void TextAt(Int32 x, Int32 y, const String &txt);

		//----------------------------------------------------------------------------------------
		/// Calculates the width of the string @formatParam{txt} in the current font.
		/// @warning This function must be enclosed between BeginDraw() and EndDraw().
		/// @param[in] txt								The text.
		/// @return												The text width.
		//----------------------------------------------------------------------------------------
		Int32 GetTextWidth(const String &txt);

		//----------------------------------------------------------------------------------------
		/// Calculates the maximum height of text in the current font.
		/// @warning This function must be enclosed between BeginDraw() and EndDraw().
		/// @return												The text height.
		//----------------------------------------------------------------------------------------
		Int32 GetTextHeight();

		//----------------------------------------------------------------------------------------
		/// Calculates the ascent in the current font. This is the distance from the baseline to the ascender line and usually represents the height of capital letters.
		/// @warning This function must be enclosed between BeginDraw() and EndDraw().
		/// @return												The text ascent.
		//----------------------------------------------------------------------------------------
		Int32 GetTextAscent();

		/// @}

		/// @name Blit
		/// @{

		//----------------------------------------------------------------------------------------
		/// Blits from s_dp to the clip map.\n
		/// The region (@formatParam{sx1},@formatParam{sy1}) to (@formatParam{sx2},@formatParam{sy2}) from the source will be copied into the region with the top left corner at (@formatParam{dx},@formatParam{dy}) in the destination. Additionally specify a raster operation with @formatParam{rop}.
		/// @warning This function must be enclosed between BeginDraw() and EndDraw().
		/// @param[in] dx									The top left destination X coordinate.
		/// @param[in] dy									The top left destination Y coordinate.
		/// @param[in] s_dp								The source.
		/// @param[in] sx1								The top left source X coordinate.
		/// @param[in] sy1								The top left source Y coordinate.
		/// @param[in] sx2								The bottom right source X coordinate.
		/// @param[in] sy2								The bottom right source Y coordinate.
		/// @param[in] rop								The raster operation: @enumerateEnum{GE_CM_BLIT}
		//----------------------------------------------------------------------------------------
		void Blit(Int32 dx, Int32 dy, const GeClipMap &s_dp, Int32 sx1, Int32 sy1, Int32 sx2, Int32 sy2, GE_CM_BLIT rop);

		/// @}

		/// @name Clipping
		/// @{

		//----------------------------------------------------------------------------------------
		/// Sets the clipping region of the clip map. This affects all drawing commands so that nothing is drawn outside the region specified by (@formatParam{left},@formatParam{top}) to (@formatParam{right},@formatParam{bottom}).
		/// @param[in] left								The left position of the clipping region.
		/// @param[in] top								The top position of the clipping region.
		/// @param[in] right							The right position of the clipping region.
		/// @param[in] bottom							The bottom position of the clipping region.
		//----------------------------------------------------------------------------------------
		void SetClipRgn(Int32 left, Int32 top, Int32 right, Int32 bottom);

		//----------------------------------------------------------------------------------------
		/// Sets the stored region to the inside of the polygonal path specified by the @formatParam{points} array.
		/// @param[in] points							An array of @formatParam{count} points with the polygonal path. @callerOwnsPointed{array}
		/// @param[in] count							The number of elements in the @formatParam{points} array.
		/// @param[in] mode								The method used to determine the inside of the path: @enumerateEnum{GE_CM_CLIPREGION}
		//----------------------------------------------------------------------------------------
		void SetClipRgn(GE_POINT2D *points, Int32 count, GE_CM_CLIPREGION mode);

		//----------------------------------------------------------------------------------------
		/// Checks if a point is inside the clipping region.
		/// @param[in] x									The X coordinate.
		/// @param[in] y									The Y coordinate.
		/// @return												@trueIfOtherwiseFalse{the point is inside the clipping region}
		//----------------------------------------------------------------------------------------
		Bool ClipPoint(Int32 x, Int32 y);

		//----------------------------------------------------------------------------------------
		/// Checks if a rectangle is inside the clipping region.
		/// @param[in] x1									The top left X coordinate.
		/// @param[in] y1									The top left Y coordinate.
		/// @param[in] x2									The bottom right X coordinate.
		/// @param[in] y2									The bottom right Y coordinate.
		/// @return												The result.
		//----------------------------------------------------------------------------------------
		Int32 ClipArea(Int32 x1, Int32 y1, Int32 x2, Int32 y2);

		/// @}

		/// @name Font
		/// @{

		//----------------------------------------------------------------------------------------
		/// Sets the current font.
		/// @param[in] font_description		The font description. Obtained from ::GeChooseFont(), GetFontDescription(), EnumerateFonts() or @formatConstant{nullptr} for the default font. @callerOwnsPointed{base container}
		/// @param[in] font_size					The font size, or @em 0.0 for the default height.
		/// @return												@trueIfOtherwiseFalse{successful}
		//----------------------------------------------------------------------------------------
		Bool SetFont(BaseContainer const *font_description, Float font_size = 0.0);

		//----------------------------------------------------------------------------------------
		/// Retrieves the current font.
		/// @param[out] font_description	Assigned the current font description. @callerOwnsPointed{base container}
		/// @return												The font size.
		//----------------------------------------------------------------------------------------
		Float GetFont(BaseContainer *font_description);

		//----------------------------------------------------------------------------------------
		/// Retrieves the font name from a font description.
		/// @param[in] font_description		The font description. @callerOwnsPointed{base container}
		/// @param[in] type								The type of name: @enumerateEnum{GeFontNameType}
		/// @param[out] dst								Assigned the font name. @callerOwnsPointed{string}
		/// @return												@trueIfOtherwiseFalse{successful}
		//----------------------------------------------------------------------------------------
		static Bool GetFontName(BaseContainer const *font_description, GeFontNameType type, String *dst);

		//----------------------------------------------------------------------------------------
		/// Retrieves a font description.
		/// @param[in] name								The font name.
		/// @param[in] type								The type of font name: @enumerateEnum{GeFontNameType}
		/// @param[out] dst								Assigned the font description. @callerOwnsPointed{base container}
		/// @return												@trueIfOtherwiseFalse{successful}
		//----------------------------------------------------------------------------------------
		static Bool GetFontDescription(String const &name, GeFontNameType type, BaseContainer *dst);

		//----------------------------------------------------------------------------------------
		/// Enumerates all fonts and returns them in a container.\n
		/// For each font a container (font description) will be inserted. They can be used for SetFont(), GetFontName() or as input for ::GeChooseFont().
		/// @param[out] dst								Assigned the font list. @callerOwnsPointed{base container}
		/// @param[in] sort_mode					The sort mode: @enumerateEnum{GE_CM_FONTSORT}
		//----------------------------------------------------------------------------------------
		static void EnumerateFonts(BaseContainer *dst, GE_CM_FONTSORT sort_mode);

		//----------------------------------------------------------------------------------------
		/// Retrieves @C4D's default font.
		/// @param[in] type								The default font type: @enumerateEnum{GeFontDefaultType}
		/// @param[out] font_description	Assigned the font description. @callerOwnsPointed{base container}
		/// @return												@trueIfOtherwiseFalse{successful}
		//----------------------------------------------------------------------------------------
		static Bool GetDefaultFont(GeFontDefaultType type, BaseContainer *font_description);

		//----------------------------------------------------------------------------------------
		/// Retrieves the font size for a given font.
		/// @param[in] font_description		The font description. @callerOwnsPointed{base container}
		/// @param[in] type								The font size type: @enumerateEnum{GeFontSizeType}
		/// @param[out] size							Assigned the font size.
		/// @return												@trueIfOtherwiseFalse{successful}
		//----------------------------------------------------------------------------------------
		static Bool GetFontSize(BaseContainer const *font_description, GeFontSizeType type, Float *size);

		//----------------------------------------------------------------------------------------
		/// Sets the font size for a given font.
		/// @param[in] font_description		The font description. @callerOwnsPointed{base container}
		/// @param[in] type								The font size type: @enumerateEnum{GeFontSizeType}
		/// @param[in] size								The font size to set.
		/// @return												@trueIfOtherwiseFalse{successful}
		//----------------------------------------------------------------------------------------
		static Bool SetFontSize(BaseContainer *font_description, GeFontSizeType type, Float size);

		/// @}
};

class iGeClipMap;

/// @}

#endif

/// @cond IGNORE

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

#define LIB_CLIPMAP		1000494

struct GeClipMapLib : public C4DLibrary
{
		GeClipMap*	(*Alloc)											();
		void				(*Free)												(GeClipMap *&data);

		IMAGERESULT	(iGeClipMap::*Init)						(Int32 w, Int32 h, Int32 bits);
		IMAGERESULT	(iGeClipMap::*InitWith)				(BaseBitmap *bm);
		IMAGERESULT	(iGeClipMap::*InitFrom)				(BaseBitmap *bm, BaseBitmap *alpha_channel);
		IMAGERESULT	(iGeClipMap::*InitFromFile)		(const Filename &name, Int32 frame, Bool *ismovie);
		void				(iGeClipMap::*Destroy)				();
		void				(iGeClipMap::*GetDim)					(Int32 *w, Int32 *h) const;
		BaseBitmap*	(iGeClipMap::*GetBitmap)			();
		void				(iGeClipMap::*BeginDraw)			();
		void				(iGeClipMap::*EndDraw)				();
		void				(iGeClipMap::*SetOffset)			(Int32 off_x, Int32 off_y);
		void				(iGeClipMap::*SetDrawMode)		(GE_CM_DRAWMODE mode, UInt32 par);
		void				(iGeClipMap::*SetColor)				(Int32 r, Int32 g, Int32 b, Int32 a);
		void				(iGeClipMap::*SetPixel)				(Int32 x, Int32 y);
		void				(iGeClipMap::*CMLine)					(Int32 x1, Int32 y1, Int32 x2, Int32 y2);
		void				(iGeClipMap::*PolyLine)				(Int32 cnt, GE_POINT2D *points);
		void				(iGeClipMap::*FillPolygon)		(Int32 cnt, GE_POINT2D *points);
		void				(iGeClipMap::*Rect)						(Int32 x1, Int32 y1, Int32 x2, Int32 y2);
		void				(iGeClipMap::*FillRect)				(Int32 x1, Int32 y1, Int32 x2, Int32 y2);
		void				(iGeClipMap::*Arc)						(Int32 x1, Int32 y1, Int32 x2, Int32 y2, GE_CM_ARCSEGMENT seg);
		void				(iGeClipMap::*FillArc)				(Int32 x1, Int32 y1, Int32 x2, Int32 y2, GE_CM_ARCSEGMENT seg);
		void				(iGeClipMap::*Ellipse)				(Int32 x1, Int32 y1, Int32 x2, Int32 y2);
		void				(iGeClipMap::*FillEllipse)		(Int32 x1, Int32 y1, Int32 x2, Int32 y2);
		void				(iGeClipMap::*SetPixelRGBA)		(Int32 x, Int32 y, Int32 r, Int32 g, Int32 b, Int32 a);
		void				(iGeClipMap::*GetPixelRGBA)		(Int32 x, Int32 y, Int32 *r, Int32 *g, Int32 *b, Int32 *a);
		void				(iGeClipMap::*TextAt)					(Int32 x, Int32 y, const String &txt);
		Int32				(iGeClipMap::*GetTextWidth)		(const String &txt);
		Int32				(iGeClipMap::*GetTextHeight)	();
		Int32				(iGeClipMap::*GetTextAscent)	();
		void				(iGeClipMap::*Blit)						(Int32 dx, Int32 dy, const iGeClipMap &s_dp, Int32 sx1, Int32 sy1, Int32 sx2, Int32 sy2, GE_CM_BLIT rop);
		void				(iGeClipMap::*SetClipRgn)			(Int32 left, Int32 top, Int32 right, Int32 bottom);
		void				(iGeClipMap::*SetClipRgn2)		(GE_POINT2D *points, Int32 count, GE_CM_CLIPREGION mode);
		Bool				(iGeClipMap::*ClipPoint)			(Int32 x, Int32 y);
		Int32				(iGeClipMap::*ClipArea)				(Int32 x1, Int32 y1, Int32 x2, Int32 y2);
		Int32				(iGeClipMap::*GetBw)					() const;
		Int32				(iGeClipMap::*GetBh)					() const;
		Bool				(iGeClipMap::*SetFont)				(BaseContainer const *font_description, Float font_size);
		Float				(iGeClipMap::*GetFont)				(BaseContainer *font_description);
		Bool				(*GetFontName)								(BaseContainer const *font_description, GeFontNameType type, String *dst);
		Bool				(*GetFontDescription)					(String const &name, GeFontNameType type, BaseContainer *dst);
		void				(*EnumerateFonts)							(BaseContainer *dst, GE_CM_FONTSORT sort_mode);
		Bool				(*GetDefaultFont)							(GeFontDefaultType type, BaseContainer *font_description);
		Bool				(*GetFontSize)								(BaseContainer const *font_description, GeFontSizeType type, Float *size);
		Bool				(*SetFontSize)								(BaseContainer *font_description, GeFontSizeType type, Float size);
		IMAGERESULT	(iGeClipMap::*InitWithIconData)(const IconData& iconData);
		IMAGERESULT (iGeClipMap::*InitWithUserArea)(GeUserArea* userArea, Int32 x, Int32 y, Int32 w, Int32 h);
		void				(iGeClipMap::*DrawBezierSegment)(const maxon::Vector2d* p);
		Bool				(iGeClipMap::*SupportsDrawBezierSegment)() const;
};

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

/// @endcond

#endif // LIB_CLIPMAP_H__
