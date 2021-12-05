/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef C4D_PAINTER_H__
#define C4D_PAINTER_H__

#include "c4d_string.h"
#include "c4d_baselist.h"
#include "c4d_basebitmap.h"
#include "operatingsystem.h"

class BaseDocument;

//----------------------------------------------------------------------------------------
/// Sends commands to @BP3D.
/// @param[in] command						The command: @enumerateEnum{PAINTER}
/// @param[in] doc								The optional document for the operation.
/// @param[in] tex								The optional paint texture for the operation.
/// @param[in] bc									The optional container for the operation: @enumerateEnum{PAINTER}
/// @return												The @BP3D window handle. @markPrivate
//----------------------------------------------------------------------------------------
void* SendPainterCommand(Int32 command, BaseDocument* doc, PaintTexture* tex, BaseContainer* bc);
/// @addtogroup PAINTER
/// @ingroup group_enumeration
/// @{
/// @see SendPainterCommand()
#define PAINTER_SAVETEXTURE					1000			///< Save texture(s).\n
																							///< If @formatParam{doc}!=@formatConstant{nullptr} all textures associated with @formatParam{doc} are saved.\n
																							///< If @formatParam{tex}!=@formatConstant{nullptr} only @formatParam{tex} is saved, otherwise all textures are saved.
																							///< @note Returns @trueIfOtherwiseFalse{successful}
	#define PAINTER_SAVETEXTURE_FLAGS						1				///< ::Int32 Save texture flags:
		#define PAINTER_SAVEBIT_SAVEAS						(1 << 0)			///< Save As.
		#define PAINTER_SAVEBIT_SAVECOPY					(1 << 1)			///< Save As Copy.
		#define PAINTER_SAVEBIT_SAVEALLOWWARNING	(1 << 2)			///< Allow warnings.
		#define PAINTER_SAVEBIT_RENAMEINSCENE			(1 << 3)			///< Rename.
#define	PAINTER_BRINGTOFRONT				1001			///< Bring the @BP3D application window to front (for exchange plugins). @markPrivate
																							///< @note Returns @formatConstant{true}.
#define PAINTER_LOADTEXTURE					1002			///< Load a texture.
																							///< @note Returns the loaded PaintTexture if successful, otherwise @formatConstant{nullptr}.
	#define LOADTEXTURE_FILENAME								1				///< Filename The filename of the texture to load.
#define PAINTER_FORCECLOSETEXTURE		1003			///< Remove a texture from memory. Pass the texture to @formatParam{tex}.
#define PAINTER_CLOSETEXTURE				1004			///< Remove a texture from memory but ask if the texture is unsaved. Pass the texture to @formatParam{tex}.
#define PAINTER_RELOADTEXTURE				1006			///< Reload a texture in @BP3D and @C4D's renderer lock list.
	#define RELOADTEXTURE_FILENAME							1				///< Filename The filename of the texture to reload.
/// @}

#define UV_SET_FROM_PROJECTION_CMD_ID			1030000			///< Set UVW from Projection command in texture view.

struct TempUVHandle
{
private:
	TempUVHandle();
	~TempUVHandle();

public:
	// not allowed to change

	//----------------------------------------------------------------------------------------
	/// Retrieves the current UV editor mode.
	/// @return												The mode: @enumerateEnum{EditorModes}
	//----------------------------------------------------------------------------------------
	Int32 GetMode();

	//----------------------------------------------------------------------------------------
	/// Retrieves the start of the read-only points array.
	/// @return												The pointer to the points array.
	//----------------------------------------------------------------------------------------
	const Vector* GetPoint();

	//----------------------------------------------------------------------------------------
	/// Retrieves the start of the read-only polygons array.
	/// @return												The pointer to the polygons array.
	//----------------------------------------------------------------------------------------
	const CPolygon* GetPoly();

	//----------------------------------------------------------------------------------------
	/// Retrieves the selected polygons.
	/// @return												The polygons selection.
	//----------------------------------------------------------------------------------------
	BaseSelect* GetPolySel();

	//----------------------------------------------------------------------------------------
	/// Retrieves the hidden polygons.
	/// @return												The hidden polygons selection.
	//----------------------------------------------------------------------------------------
	BaseSelect* GetPolyHid();

	//----------------------------------------------------------------------------------------
	/// Retrieves the selected UV points.\n
	/// The points are indexed by <tt>4 * polygon + point</tt> where @c polygon is the polygon index and @c point is the point index between @em 0 and @em 3 (a, b, c, d).
	/// @return												The UV points selection.
	//----------------------------------------------------------------------------------------
	BaseSelect* GetUVPointSel();

	//----------------------------------------------------------------------------------------
	/// Retrieves the point count.
	/// @return												The point count.
	//----------------------------------------------------------------------------------------
	Int32 GetPointCount();

	//----------------------------------------------------------------------------------------
	/// Retrieves the polygon count.
	/// @return												The polygon count.
	//----------------------------------------------------------------------------------------
	Int32 GetPolyCount();

	//----------------------------------------------------------------------------------------
	/// Retrieves the object of the UV set.
	/// @return												The object of the UV set.
	//----------------------------------------------------------------------------------------
	BaseObject* GetBaseObject();

	//----------------------------------------------------------------------------------------
	/// Checks if UVs are editable or not. Polygon objects have editable UVs, object generators usually not.
	/// @return												@trueIfOtherwiseFalse{UVs are editable}
	//----------------------------------------------------------------------------------------
	Bool IsEditable();

	// allowed to change

	//----------------------------------------------------------------------------------------
	/// Retrieves the UV array.
	/// @return												The pointer to the UV array.
	//----------------------------------------------------------------------------------------
	UVWStruct* GetUVW();

	//----------------------------------------------------------------------------------------
	/// Applies changes of the UV set to the object.
	/// @param[in] uv									The pointer to the changed UV array.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool SetUVW(UVWStruct* uv);

	//----------------------------------------------------------------------------------------
	/// Applies changes of the UV set to the object, optionally using the components in the last active Texture View instance.
	/// @param[in] uvw								The pointer to the changed UV array.
	/// @param[in] ignoreHidden				If @formatConstant{true}, do not affect the UV coordinates of UV Polygons or UV Points of hidden polygons.
	/// @param[in] ignoreUnselected		If @formatConstant{true}, do not affect the UV coordinates of UV Polygons, or UV Points (depending on the current mode) that are unselected in the Texture View.
	/// @param[in] autoSelectAll			If @formatConstant{true}, automatically selects all UV Polygons, or UV Points (depending on the current mode).
	/// @param[in] registerUndo				If @formatConstant{true}, an undo is added for the operation. Since @em R16
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool SetUVWFromTextureView(UVWStruct* uvw, Bool ignoreHidden, Bool ignoreUnselected, Bool autoSelectAll, Bool registerUndo = true);
};

//----------------------------------------------------------------------------------------
/// Retrieves the document's active UV set.
/// @param[in] doc								The document returning the active UV set.
/// @param[in] flags							The flags: @enumerateEnum{GETACTIVEUVSET}
/// @return												A temporary handle to the active UV set, or @formatConstant{nullptr} if there is no active UV set. Has to be freed with FreeActiveUVSet().
//----------------------------------------------------------------------------------------
TempUVHandle* GetActiveUVSet(BaseDocument* doc, Int32 flags);
/// @addtogroup GETACTIVEUVSET
/// @ingroup group_enumeration
/// @{
#define GETACTIVEUVSET_CHECKENABLING				(1 << 0)			///< Enable status.
#define GETACTIVEUVSET_UVWS									(1 << 1)			///< Get the UVWStruct array.
#define GETACTIVEUVSET_POLYS								(1 << 2)			///< Get the CPolygon array.
#define GETACTIVEUVSET_POLYSELECTION				(1 << 3)			///< Get the selected polygons array.
#define GETACTIVEUVSET_POINTS								(1 << 4)			///< Get the points array.
#define GETACTIVEUVSET_POINTSELECTION				(1 << 5)			///< Get the selected UV points.
#define GETACTIVEUVSET_OBJECT								(1 << 6)			///< Get the object of the UV set.
#define GETACTIVEUVSET_MODE									(1 << 7)			///< Get the active editor mode.
#define GETACTIVEUVSET_POLYHIDDEN						(1 << 8)			///< Get the hidden polygons array.

#define GETACTIVEUVSET_ALL_CHECKENABLING		(0xFFFF)																			///< Combine all of the previous flags and the enable status.
#define GETACTIVEUVSET_ALL									(0xFFFF & ~GETACTIVEUVSET_CHECKENABLING)			///< Combine all of the previous flags except the enable status.
/// @}

//----------------------------------------------------------------------------------------
/// Frees the active UV set.
/// @param[in] handle							The temporary handle of the UV set to be freed.
//----------------------------------------------------------------------------------------
void FreeActiveUVSet(TempUVHandle* handle);



//----------------------------------------------------------------------------------------
/// Calls UV commands.\n
/// @b Example:
/// @code
/// TempUVHandle *handle = GetActiveUVSet(pDoc, GETACTIVEUVSET_ALL);
///
/// if (!handle)
/// 	return false;
///
/// CallUVCommand(pPoints, lPointCount, pPolys, lPolyCount, pUVW, pPolySel, pPointSel,
///								op, mode, UVCOMMAND_FIT_TO_CANVAS, BaseContainer());
///
/// handle->SetUVW(pUVW);
/// @endcode
/// @param[in] padr								The address of the points array.
/// @param[in] PointCount					The number of points in @formatParam{padr} array.
/// @param[in] polys							The address of the polygons array.
/// @param[in] lPolyCount					The number of polygons in @formatParam{polys} array.
/// @param[in] uvw								The address of the UV array.
/// @param[in] polyselection			The polygon selection.
/// @param[in] pointselection			The UV points selection.\n
/// 															The points are indexed by <tt>4 * polygon + point</tt> where @c polygon is the polygon index and @c point is the point index between @em 0 and @em 3.
/// @param[in] op									The object of the UV set.
/// @param[in] mode								The UV editing mode: @enumerateEnum{EditorModes}
/// @param[in] cmdid							The UV command: @enumerateEnum{UVCOMMAND}
/// @param[in] settings						The optional settings for the UV command.
/// @return												@trueIfOtherwiseFalse{successful}
//----------------------------------------------------------------------------------------
Bool CallUVCommand(const Vector* padr, Int32 PointCount, const CPolygon* polys, Int32 lPolyCount, UVWStruct* uvw, BaseSelect* polyselection,
									 BaseSelect* pointselection, BaseObject* op, Int32 mode, Int32 cmdid, const BaseContainer& settings);
/// @addtogroup UVCOMMAND
/// @ingroup group_enumeration
/// @{
#define UVCOMMAND_OPTIMALMAPPING							10000			///< Optimal Angle UV Mapping.
#define UVCOMMAND_OPTIMALCUBICMAPPING					10001			///< Optimal Cubic UV Mapping.
#define UVCOMMAND_REALIGN											10002			///< Realign UV Mapping.
	#define OPTIMALMAPPING_PRESERVEORIENTATION	1000	///< ::Bool Preserve Orientation (Cubic, Angle, Realign).
	#define OPTIMALMAPPING_STRETCHTOFIT					1001	///< ::Bool Stretch To Fit (Cubic, Angle, Realign).
	#define OPTIMALMAPPING_DISTORTION						1002	///< ::Float Maximum Distortion (Angle).
	#define OPTIMALMAPPING_SPACING							1003	///< ::Float Spacing (Cubic, Angle, Realign).
	#define OPTIMALMAPPING_AREAFAK							1004	///< ::Float Maximum Area Factor (Cubic).
	#define OPTIMALMAPPING_TWOD									1005	///< ::Bool 2D (Cubic).
	#define OPTIMALMAPPING_PROGRESSBAR					1006	///< ::Bool Progress bar (Cubic, Angle, Realign).
	#define OPTIMALMAPPING_RELAXCOUNT						1007	///< ::Int32 Relaxation Steps (Cubic, Angle).
	#define OPTIMALMAPPING_EQUALIZEAREA					1008	///< ::Bool Equalize Island Size (Realign).
#define UVCOMMAND_RELAX												10003			///< Relax UV.
	#define RELAXUV_KEEP_BORDER									1010	///< ::Bool Pin Border Points.
	#define RELAXUV_KEEP_NEIGHBORS							1011	///< ::Bool Pin To Neighbors.
	#define RELAXUV_KEEP_POINTSEL								1012	///< ::Bool Pin Point Selection.
	#define RELAXUV_CUT_EDGESEL									1013	///< ::Bool Cut Selected Edges.
	#define RELAXUV_EDGESEL_POINTER							1022	///< BaseSelect* Pointer to the edge selection.
	#define RELAXUV_MAX_ITERATIONS							1014	///< Int32 Maximum Iteration Steps.
	#define RELAXUV_MODE												1024	///< Int32 Relaxation Mode:
		#define RELAXUV_MODE_LSCM	0	///< LSCM relaxation.
		#define RELAXUV_MODE_ABF	1	///< ABF relaxation.
#define UVCOMMAND_COPY_UV											10004			///< Copy UV Polygon.
#define UVCOMMAND_PASTE_UV										10005			///< Paste UV Polygon.
#define UVCOMMAND_MAX_UV											10006			///< Max UV.
#define UVCOMMAND_FLIP_SEQUENCE								10007			///< Flip Sequence.
#define UVCOMMAND_CYCLE_CW_UV									10008			///< Cycle UV CW. @since R19
#define UVCOMMAND_CYCLE_CCW_UV								10009			///< Cycle UV CCW. @since R19
#define UVCOMMAND_TERRACE											10010			///< UV Terrace.
#define UVCOMMAND_FIT_TO_CANVAS								10011			///< Fit UV To Canvas.
#define UVCOMMAND_TRANSFORM										10012			///< Transform UV:
	#define UVCOMMAND_TRANSFORM_MOVE_X	1020			///< ::Float Move X (U).
	#define UVCOMMAND_TRANSFORM_MOVE_Y	1021			///< ::Float Move Y (V).
	#define UVCOMMAND_TRANSFORM_SCALE_X	1022			///< ::Float Scale X (U).
	#define UVCOMMAND_TRANSFORM_SCALE_Y	1023			///< ::Float Scale Y (V).
	#define UVCOMMAND_TRANSFORM_ANGLE		1024			///< ::Float Rotation Angle in Radians.
#define UVCOMMAND_LINEUP											10013			///< Line Up UV.
#define UVCOMMAND_UNSTITCH										10014			///< Unstitch UV.
#define UVCOMMAND_BOUNDARY2SHAPE							10015			///< UV Boundary To Shape:
	#define UVCOMMAND_BOUNDARY2SHAPE_MODE			1000	///< ::Int32 UV boundary shape:
		#define UVCOMMAND_BOUNDARY2SHAPE_CIRCLE	0	///< UV boundary to circle.
		#define UVCOMMAND_BOUNDARY2SHAPE_QUAD		1	///< UV boundary to square.
/// @}


//----------------------------------------------------------------------------------------
/// Identifies an image's file format.
/// @param[in] texpath						The texture's file path.
/// @return												The image's file format: @enumerateEnum{FILTER}
//----------------------------------------------------------------------------------------
Int32 IdentifyImage(const Filename& texpath);

//----------------------------------------------------------------------------------------
/// Runs @BP3D paint wizard.
/// @param[in] doc								The document.
/// @param[in] settings						The settings for the paint wizard: @enumerateEnum{AMSI}
/// @param[in] objects						An array with the objects the paint wizard is using.
/// @param[in] material						An array with the materials the paint wizard is using.
/// @return												@trueIfOtherwiseFalse{successful}
//----------------------------------------------------------------------------------------
Bool BPSetupWizardWithParameters(BaseDocument* doc, const BaseContainer& settings, AtomArray& objects, AtomArray& material);
/// @addtogroup AMSI
/// @ingroup group_enumeration
/// @{
/// Automatic mapsize interpolation
#define AMSI_CREATE_MISSING_MATERIALS		4000			///< ::Bool Create materials and texture tags if they are missing.
#define AMSI_CREATE_MISSING_CHANNELS		4001			///< ::Bool Create missing texture channels.
#define AMSI_AUTOSELECT_MATERIALS				4002			///< ::Bool Autoselect materials from object selection.
#define AMSI_AUTOSELECT_OBJECTS					4003			///< ::Bool Autoselect objects from materials selection.
#define AMSI_DELETE_BROKENMATERIALTAGS	4004			///< ::Bool Delete material tags with broken material links.
#define AMSI_ENABLEMATERIALS						4005			///< ::Bool Enable all materials for painting.
#define AMSI_SINGLEMATERIAL							4006			///< ::Bool Join UV's in one single material.

#define CREATE_CHANNEL									4100			///< Bool Create missing texture channels (@ref CREATE_CHANNEL + @em CHANNEL_ID). @em 4100 - @em 4199
#define CREATE_CHANNEL_C								4200			///< ::Vector Channel color (@ref CREATE_CHANNEL_C + @em CHANNEL_ID). @em 4200 - @em 4299

#define AMSI_ENABLED										5000			///< ::Bool Enable automatic mapsize interpolation, otherwise minimum size == texsize.
#define AMSI_TEXW												5001			///< ::Int32 Fixed texture size width.
#define AMSI_TEXH												5002			///< ::Int32 Fixed texture size height.
#define AMSI_TEXMIN											5003			///< ::Int32 Minimum texture size (width and height).
#define AMSI_TEXMAX											5004			///< ::Int32 Maximum texture size (width and height).
#define AMSI_QUANTIZE										5005			///< ::Int32 Quantize texture size.
#define AMSI_RESCALE_EXISTING						5006			///< ::Bool Rescale existing material channels.
#define AMSI_USE_SAME_RES								5007			///< ::Bool Use the same texture size if already one channel exists.

#define AMSI_UV_CALC_METHOD							6000			///< ::Int32: Calculation mode:
	#define UV_CALC_METHOD_OPTIMAL1					1			///< Optimal Cube Mapping.
	#define UV_CALC_METHOD_OPTIMAL2					2			///< Optimal Angle Mapping.
	#define UV_CALC_METHOD_REALIGN					3			///< Realign.
#define AMSI_UV_CALC_EXISTING						6001			///< ::Bool Calculate UVs.
#define AMSI_UV_RELAXATION							6002			///< ::Bool Relax UVs
/// @}

struct TextureSize
{
	Float w,			///< The texture width.
				h;			///< The texture height.
};

//----------------------------------------------------------------------------------------
/// Calculates the texture size based on the geometry and the size of the UV polygons.
/// @param[in] doc								The document.
/// @param[in] materials					An array containing the materials the texture size calculation is applied to.
/// @param[in] sizes							An array with the texture sizes, equals the number of materials. Must be freed with DeleteMem.
/// @return												@trueIfOtherwiseFalse{successful}
//----------------------------------------------------------------------------------------
Bool CalculateTextureSize(BaseDocument* doc, AtomArray& materials, TextureSize*& sizes);

/// @addtogroup OBJECT_PAINT
/// @ingroup group_enumeration
/// @{
/// C4DAtom::GetType() returns this for @BP3D objects.
#define OBJECT_PAINTLAYERBMP		(501)			///< PaintLayerBm.
#define OBJECT_PAINTTEXTURE			(502)			///< PaintTexture.
#define OBJECT_PAINTBITMAP			(543)			///< PaintBitmap. For use with C4DAtom::IsInstanceOf().
#define OBJECT_PAINTLAYERFOLDER	(542)			///< PaintLayerFolder.
#define OBJECT_PAINTLAYER				(544)			///< PaintLayer.
/// @}

#ifndef __API_INTERN__

/// @addtogroup UPDATE
/// @ingroup group_enumeration
/// @{
/// @markPrivate
#define UPDATE_CHILDREN				(1 << 0)
#define UPDATE_PARENTS				(1 << 1)
#define UPDATE_PREVIEW				(1 << 2)
#define UPDATE_REFRESH2D			(1 << 3)
#define UPDATE_RECALC					(1 << 4)
#define UPDATE_NOSAVECHG			(1 << 6)
#define UPDATE_NOOFFSET				(1 << 7)
#define UPDATE_REFRESH3D			(1 << 8)
#define UPDATE_REFRESHCURSOR	(1 << 9)
#define UPDATE_NOSTOPTHREADS	(1 << 10)

#define UPDATE_STD						(UPDATE_PARENTS|UPDATE_PREVIEW|UPDATE_REFRESH2D|UPDATE_REFRESH3D|UPDATE_RECALC)
/// @}

//----------------------------------------------------------------------------------------
/// The base class of all paint classes. Can be a texture, material, layer or mask.
//----------------------------------------------------------------------------------------
class PaintBitmap : public BaseList2D
{
private:
	PaintBitmap();
	~PaintBitmap();

public:
	//----------------------------------------------------------------------------------------
	/// Retrieves the width of the paint bitmap.
	/// @return												The width of the paint bitmap.
	//----------------------------------------------------------------------------------------
	Int32 GetBw() { return C4DOS.Pa->PB_GetBw(this); }

	//----------------------------------------------------------------------------------------
	/// Retrieves the height of the paint bitmap.
	/// @return												The height of the paint bitmap.
	//----------------------------------------------------------------------------------------
	Int32 GetBh() { return C4DOS.Pa->PB_GetBh(this); }

	//----------------------------------------------------------------------------------------
	/// Retrieves the paint texture if possible.
	/// @return												The paint texture, otherwise @formatConstant{nullptr}.
	//----------------------------------------------------------------------------------------
	PaintTexture* GetPaintTexture() { return C4DOS.Pa->PB_GetPaintTexture(this); }

	//----------------------------------------------------------------------------------------
	/// Retrieves the parent if available. This can be a layer or a texture for instance.
	/// @return												The parent, otherwise @formatConstant{nullptr}.
	//----------------------------------------------------------------------------------------
	PaintBitmap* GetParent() { return C4DOS.Pa->PB_GetParent(this); }

	//----------------------------------------------------------------------------------------
	/// Retrieves the first child layer.
	/// @return												The first child layer, or @formatConstant{nullptr} if there is none.
	//----------------------------------------------------------------------------------------
	PaintLayer* GetLayerDownFirst() { return C4DOS.Pa->PB_GetLayerDownFirst(this); }

	//----------------------------------------------------------------------------------------
	/// Retrieves the last child layer.
	/// @return												The last child layer, or @formatConstant{nullptr} if there is none.
	//----------------------------------------------------------------------------------------
	PaintLayer* GetLayerDownLast() { return C4DOS.Pa->PB_GetLayerDownLast(this); }

	//----------------------------------------------------------------------------------------
	/// Retrieves the first alpha channel layer.
	/// @return												The first alpha channel layer, or @formatConstant{nullptr} if there is none.
	//----------------------------------------------------------------------------------------
	PaintLayer* GetAlphaFirst() { return C4DOS.Pa->PB_GetAlphaFirst(this); }

	//----------------------------------------------------------------------------------------
	/// Retrieves the last alpha channel layer.
	/// @return												The last alpha channel layer, or @formatConstant{nullptr} if there is none.
	//----------------------------------------------------------------------------------------
	PaintLayer* GetAlphaLast() { return C4DOS.Pa->PB_GetAlphaLast(this); }

	//----------------------------------------------------------------------------------------
	/// Adds an alpha channel to the layer.
	/// @param[in] bitdepth						The bit depth of the alpha channel: @enumerateEnum{BITDEPTH}
	/// @param[in] prev								An optional point to insert the alpha channel.
	/// @param[in] undo								@formatConstant{true} to create an undo on the undo stack, otherwise @formatConstant{false}.
	/// @param[in] activate						@formatConstant{true} to activate alpha channel.
	/// @return												The added alpha channel, or @formatConstant{nullptr} if it failed.
	//----------------------------------------------------------------------------------------
	PaintLayerBmp* AddAlphaChannel(Int32 bitdepth, PaintLayer* prev = nullptr, Bool undo = true, Bool activate = true) { return C4DOS.Pa->PB_AddAlphaChannel(this, bitdepth, prev, undo, activate); }

	//----------------------------------------------------------------------------------------
	/// Checks if the alpha mask can be applied.
	/// @return												@trueIfOtherwiseFalse{the alpha mask can be applied}
	//----------------------------------------------------------------------------------------
	Bool AskApplyAlphaMask() { return C4DOS.Pa->PB_AskApplyAlphaMask(this); }

	//----------------------------------------------------------------------------------------
	/// Applies the alpha mask.
	/// @param[in] x									The X coordinate of the starting point.
	/// @param[in] y									The Y coordinate of the starting point.
	/// @param[in] cnt								The length of the masked line.
	/// @param[in] bits								The masked pixels.
	/// @param[in] mode								The color mode (only with alpha channel): @enumerateEnum{COLORMODE}
	/// @param[in] inverted						@formatConstant{true} to apply an inverted alpha mask.
	/// @param[in] flags							The flags: @enumerateEnum{GETPIXEL}
	//----------------------------------------------------------------------------------------
	void ApplyAlphaMask(Int32 x, Int32 y, Int32 cnt, PIX* bits, COLORMODE mode, Bool inverted, Int32 flags) { C4DOS.Pa->PB_ApplyAlphaMask(this, x, y, cnt, bits, mode, inverted, flags); }

	//----------------------------------------------------------------------------------------
	/// Finds the selection mask.
	/// @param[in] toplevel						The root level. PaintMaterial if the selection is in a material, otherwise PaintTexture.
	/// @param[in] bitdepth						The bit depth of the selection mask.
	/// @return												The selection mask, or @formatConstant{nullptr} if there is none.
	//----------------------------------------------------------------------------------------
	PaintLayerMask* FindSelectionMask(PaintBitmap** toplevel, Int32* bitdepth) { return C4DOS.Pa->PB_FindSelectionMask(this, toplevel, bitdepth); }

	//----------------------------------------------------------------------------------------
	/// Retrieves the color mode of the paint bitmap.
	/// @return												The color mode: @enumerateEnum{COLORMODE}
	//----------------------------------------------------------------------------------------
	COLORMODE GetColorMode() { return C4DOS.Pa->PB_GetColorMode(this); };

	//----------------------------------------------------------------------------------------
	/// Retrieves the dirty count.
	/// @param[in] flags							Reserved, must be @ref DIRTYFLAGS::NONE.
	/// @return												The dirty count, incremented when the paint bitmap changes.
	//----------------------------------------------------------------------------------------
	UInt32 GetDirty(DIRTYFLAGS flags) const { return C4DOS.Pa->PB_GetDirty(this, flags); }

	//----------------------------------------------------------------------------------------
	/// Refreshes an area of the paint bitmap. Must be done after modifying it.
	/// @param[in] xmin								The left coordinate of the refreshed area.
	/// @param[in] ymin								The top coordinate of the refreshed area.
	/// @param[in] xmax								The right coordinate of the refreshed area.
	/// @param[in] ymax								The bottom coordinate of the refreshed area.
	/// @param[in] flags							The flags: @enumerateEnum{UPDATE}
	//----------------------------------------------------------------------------------------
	void UpdateRefresh(Int32 xmin, Int32 ymin, Int32 xmax, Int32 ymax, UInt32 flags) { C4DOS.Pa->PB_UpdateRefresh(this, xmin, ymin, xmax, ymax, flags); }

	//----------------------------------------------------------------------------------------
	/// Refreshes the complete paint bitmap. Has to be done after modifying it.
	/// @param[in] flags							The flags: @enumerateEnum{UPDATE}
	/// @param[in] reallyall					If @formatConstant{true} an infinite bounding box is used for the refresh.\n
	/// 															If @formatConstant{false} the bounding box of the layer is used, this is much faster.
	//----------------------------------------------------------------------------------------
	void UpdateRefreshAll(UInt32 flags, Bool reallyall) { C4DOS.Pa->PB_UpdateRefreshAll(this, flags, reallyall); }

	//----------------------------------------------------------------------------------------
	/// Creates a flattened bitmap of the paint bitmap.
	/// @param[in] thread							Pass the thread to be used for the calculation.
	/// @param[in] x1									The left coordinate of the calculation window.
	/// @param[in] y1									The top coordinate of the calculation window.
	/// @param[in] x2									The right coordinate of the calculation window.
	/// @param[in] y2									The bottom coordinate of the calculation window.
	/// @param[out] bmp								The flattened bitmap.
	/// @param[in] flags							The flags: @enumerateEnum{RECALC}
	/// @param[in] showbit						Must be set to @em 0.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool ReCalc(BaseThread* thread, Int32 x1, Int32 y1, Int32 x2, Int32 y2, BaseBitmap* bmp, Int32 flags, UInt32 showbit) { return C4DOS.Pa->PB_ReCalc(this, thread, x1, y1, x2, y2, bmp, flags, showbit); }
	/// @addtogroup RECALC
	/// @ingroup group_enumeration
	/// @{
	#define RECALC_NOGRID		1			///< If set the checkered background grid will not be evaluated.
	#define RECALC_INITBMP	2			///< Initialize the BaseBitmap of the @formatParam{bmp} parameter.
	/// @}

	//----------------------------------------------------------------------------------------
	/// Converts pixel data.
	/// @param[in] cnt								The number of pixels to convert.
	/// @param[in] src								The pixel source buffer.
	/// @param[in] srcinc							The source step size.
	/// @param[in] srcmode						The source color mode: @enumerateEnum{COLORMODE}
	/// @param[out] dst								The pixel destination buffer.
	/// @param[in] dstinc							The destination step size.
	/// @param[in] dstmode						The destination color mode: @enumerateEnum{COLORMODE}
	/// @param[in] dithery						If @ref NOTOK no dithering is applied, otherwise pass the Y pixel coordinate.
	/// @param[in] ditherx						If @ref NOTOK no dithering is applied, otherwise pass the X pixel coordinate.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	static Bool ConvertBits(Int32 cnt, const PIX* src, Int32 srcinc, COLORMODE srcmode/* MODE_xxx */, PIX* dst, Int32 dstinc, COLORMODE dstmode/* MODE_xxx */, Int32 dithery, Int32 ditherx) { return C4DOS.Pa->PB_ConvertBits(cnt, src, srcinc, srcmode, dst, dstinc, dstmode, dithery, ditherx); }
};

//----------------------------------------------------------------------------------------
/// A class for paint layers. Can be any kind of layer (layer, layer set, etc.).
//----------------------------------------------------------------------------------------
class PaintLayer : public PaintBitmap
{
private:
	PaintLayer();
	~PaintLayer();

public:
	//----------------------------------------------------------------------------------------
	/// Retrieves the visibility of the layer.
	/// @param[in] hierarchy					If @formatConstant{true} the visibility of the parents is taken into account (think of layer sets).
	/// @param[in] bit								Must be set to @em 0.
	/// @return												@trueIfOtherwiseFalse{visible}
	//----------------------------------------------------------------------------------------
	Bool GetShowBit(Bool hierarchy, UInt32 bit) { return C4DOS.Pa->PL_GetShowBit(this, hierarchy, bit); }

	//----------------------------------------------------------------------------------------
	/// Sets the visibility of the layer.
	/// @param[in] onoff							@trueIfOtherwiseFalse{visible}
	/// @param[in] bit								Must be set to @em 0.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool SetShowBit(Bool onoff, UInt32 bit) { return C4DOS.Pa->PL_SetShowBit(this, onoff, bit); }
};

//----------------------------------------------------------------------------------------
/// A class for paint layer masks.
//----------------------------------------------------------------------------------------
class PaintLayerMask : public PaintLayer
{
private:
	PaintLayerMask();
	~PaintLayerMask();

public:
	//----------------------------------------------------------------------------------------
	/// Checks if the selected pixels of this layer mask are being edited.
	/// @return												@trueIfOtherwiseFalse{the selected pixels of this layer mask is being edited}
	//----------------------------------------------------------------------------------------
	Bool GetEditMaskMode() { return C4DOS.Pa->PLM_GetEditMaskMode(this); }
};

//----------------------------------------------------------------------------------------
/// A class for paint layer folders.
//----------------------------------------------------------------------------------------
class PaintLayerFolder : public PaintLayer
{
private:
	PaintLayerFolder();
	~PaintLayerFolder();

public:
};

/// @addtogroup GETPIXEL
/// @ingroup group_enumeration
/// @{
// Flags for GetPixelCnt
#define GETPIXEL_ALPHAMASKS					(1 << 0)			///< Calculate alpha masks.
#define GETPIXEL_USEBLENDING				(1 << 1)			///< Calculate transparent value of layer.
#define GETPIXEL_ALL								(GETPIXEL_ALPHAMASKS | GETPIXEL_USEBLENDING)			///< All: @ref GETPIXEL_ALPHAMASKS | @ref GETPIXEL_USEBLENDING.

#define GETPIXEL_NOMASK							(1 << 2)			///< Do not use masks.
#define GETPIXEL_CACHE							(1 << 3)			///< @markInternal
#define GETPIXEL_NOWORK							(1 << 4)			///< @markPrivate No working layer.
#define GETPIXEL_ONLYWORK						(1 << 5)			///< @markPrivate Only working layer.
#define GETPIXEL_TILE_BOTH					(GETPIXEL_TILE_U | GETPIXEL_TILE_V) ///< Activate tiling in both directions.
#define GETPIXEL_DONTAPPLYMASK			(1 << 7)			///< Do not apply masks on the working layer.
#define GETPIXEL_USESELECTED				(1 << 8)			///< @markPrivate
#define GETPIXEL_DITHERING					(1 << 9)			///< Use dithering.
#define GETPIXEL_PROJECTIONPIXEL		(1 << 10)			///< @markPrivate Use special projection paint RGBA color, a kind of hack.
#define GETPIXEL_RECALCBRUSHSTROKE	(1 << 11)			///< @markPrivate Special flag for brush stroke.
#define GETPIXEL_VOXELCACHING				(1 << 12)			///< @markPrivate Use voxel caching.
#define GETPIXEL_MERGE							(1 << 13)			///< @markPrivate Only merge, no get at collect.
#define GETPIXEL_TILE_U							(1 << 15)			///< Activate tiling in U direction.
#define GETPIXEL_TILE_V							(1 << 16)			///< Activate tiling in V direction.
/// @}

//----------------------------------------------------------------------------------------
/// A class for layers with pixels.
//----------------------------------------------------------------------------------------
class PaintLayerBmp : public PaintLayer
{
private:
	PaintLayerBmp();
	~PaintLayerBmp();

public:
	//----------------------------------------------------------------------------------------
	/// Fills the layer bitmap with an imported bitmap.
	/// @param[in] bmp								The bitmap to import.
	/// @param[in] usealpha						@formatConstant{true} to use the alpha channel of the bitmap, otherwise @formatConstant{false}.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool ImportFromBaseBitmap(BaseBitmap* bmp, Bool usealpha) { return C4DOS.Pa->PLB_ImportFromBaseBitmap(this, bmp, usealpha); }

	//----------------------------------------------------------------------------------------
	/// Fills the layer bitmap with an imported bitmap and a separate alpha channel bitmap.
	/// @param[in] bmp								The bitmap to import.
	/// @param[in] channel						The separate alpha channel bitmap to import.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool ImportFromBaseBitmapAlpha(BaseBitmap* bmp, BaseBitmap* channel) { return C4DOS.Pa->PLB_ImportFromBaseBitmapAlpha(this, bmp, channel); }

	//----------------------------------------------------------------------------------------
	/// Retrieves pixels.
	/// @param[in] x									The starting X coordinate.
	/// @param[in] y									The starting Y coordinate.
	/// @param[in] cnt								The number of pixels.
	/// @param[out] dst								The pixel destination buffer.
	/// @param[in] dstmode						The destination color mode: @enumerateEnum{COLORMODE}
	/// @param[in] flags							The flags: @enumerateEnum{PIXELCNT}
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool GetPixelCnt(Int32 x, Int32 y, Int32 cnt, PIX* dst, COLORMODE dstmode, PIXELCNT flags) { return C4DOS.Pa->PLB_GetPixelCnt(this, x, y, cnt, dst, dstmode, flags); }

	//----------------------------------------------------------------------------------------
	/// Sets pixels.
	/// @param[in] x									The starting X coordinate.
	/// @param[in] y									The starting Y coordinate.
	/// @param[in] cnt								The number of pixels.
	/// @param[in] src								The source pixel buffer.
	/// @param[in] incsrc							The source step size.
	/// @param[in] srcmode						The source color mode: @enumerateEnum{COLORMODE}
	/// @param[in] flags							The flags: @enumerateEnum{PIXELCNT}
	//----------------------------------------------------------------------------------------
	void SetPixelCnt(Int32 x, Int32 y, Int32 cnt, const PIX* src, Int32 incsrc, COLORMODE srcmode, PIXELCNT flags) { C4DOS.Pa->PLB_SetPixelCnt(this, x, y, cnt, src, incsrc, srcmode, flags); }

	//----------------------------------------------------------------------------------------
	/// Retrieves the bounding box of the bitmap layer.
	/// @param[out] x1								Filled with the left coordinate.
	/// @param[out] y1								Filled with the top coordinate.
	/// @param[out] x2								Filled with the right coordinate.
	/// @param[out] y2								Filled with the bottom coordinate.
	/// @param[in] hasselectionpixels	@markPrivate
	//----------------------------------------------------------------------------------------
	void GetBoundingBox(Int32& x1, Int32& y1, Int32& x2, Int32& y2, Bool hasselectionpixels = false) { C4DOS.Pa->PLB_GetBoundingBox(this, x1, y1, x2, y2, hasselectionpixels); }
};

//----------------------------------------------------------------------------------------
/// A class for paint textures, can contain layers and may represent the channel of a material.
//----------------------------------------------------------------------------------------
class PaintTexture : public PaintBitmap
{
private:
	PaintTexture();
	~PaintTexture();

public:
	//----------------------------------------------------------------------------------------
	/// Retrieves the first layer of the paint texture.
	/// @return												The first layer of the paint texture, or @formatConstant{nullptr} if there is none.
	//----------------------------------------------------------------------------------------
	PaintLayer* GetFirstLayer() { return C4DOS.Pa->PB_GetLayerDownFirst(this); }

	//----------------------------------------------------------------------------------------
	/// Retrieves the last layer of the paint texture.
	/// @return												The last layer of the paint texture, or @formatConstant{nullptr} if there is none.
	//----------------------------------------------------------------------------------------
	PaintLayer* GetLastLayer() { return C4DOS.Pa->PB_GetLayerDownLast(this); }

	//----------------------------------------------------------------------------------------
	/// Adds a bitmap layer.
	/// @param[in] insertafter				The layer insertion point.
	/// @param[in] layerset						The parent layer folder.
	/// @param[in] mode								The color mode (should be the same as the paint texture): @enumerateEnum{COLORMODE}
	/// @param[in] useundo						@trueOtherwiseFalse{to create an undo on the undo stack}
	/// @param[in] activate						@formatConstant{true} to select the layer.
	/// @return												The added bitmap layer, or @formatConstant{nullptr} if bitmap layer creation failed.
	//----------------------------------------------------------------------------------------
	PaintLayerBmp* AddLayerBmp(PaintLayer* insertafter, PaintLayer* layerset = nullptr, COLORMODE mode = COLORMODE::ARGB, Bool useundo = true, Bool activate = true) { return C4DOS.Pa->PT_AddLayerBmp(this, insertafter, layerset, mode, useundo, activate); }

	//----------------------------------------------------------------------------------------
	/// Adds a layer folder.
	/// @param[in] insertafter				The layer insertion point.
	/// @param[in] insertunder				The parent layer folder.
	/// @param[in] useundo						@trueOtherwiseFalse{to create an undo on the undo stack}
	/// @param[in] activate						@formatConstant{true} to select the layer.
	/// @return												The added layer folder, or @formatConstant{nullptr} if layer folder creation failed.
	//----------------------------------------------------------------------------------------
	PaintLayerFolder* AddLayerFolder(PaintLayer* insertafter, PaintLayer* insertunder, Bool useundo = true, Bool activate = true) { return C4DOS.Pa->PT_AddLayerFolder(this, insertafter, insertunder, useundo, activate); }

	//----------------------------------------------------------------------------------------
	/// Selects a layer.
	/// @param[in] layer							The layer to select.
	/// @param[in] activatetexture		@trueOtherwiseFalse{to select the layer}
	/// @param[in] show								@trueOtherwiseFalse{to show the layer}
	//----------------------------------------------------------------------------------------
	void SetActiveLayer(PaintLayer* layer, Bool activatetexture, Bool show = true) { C4DOS.Pa->PT_SetActiveLayer(this, layer, activatetexture, show); }

	//----------------------------------------------------------------------------------------
	/// Retrieves the selected layer.
	/// @return												The selected layer, or @formatConstant{nullptr} if there is none.
	//----------------------------------------------------------------------------------------
	PaintLayer* GetActive() { return C4DOS.Pa->PT_GetActive(this); }

	//----------------------------------------------------------------------------------------
	/// Retrieves the linked layers.
	/// @param[in] layers							The array containing the linked layers.
	/// @param[in] addfolders					If @formatConstant{true} the layer hierarchy is taken into account (see layer folders), otherwise @formatConstant{false}.
	//----------------------------------------------------------------------------------------
	void GetLinkLayers(AtomArray& layers, Bool addfolders) { C4DOS.Pa->PT_GetLinkLayers(this, layers, addfolders); }

	//----------------------------------------------------------------------------------------
	/// Changes the color mode of the paint texture.
	/// @param[in] newcolormode				The new color mode: @enumerateEnum{COLORMODE}
	/// @param[in] doundo							@trueOtherwiseFalse{to create an undo for changing the color mode}
	//----------------------------------------------------------------------------------------
	void SetColorMode(COLORMODE newcolormode, Bool doundo) { C4DOS.Pa->PT_SetColorMode(this, newcolormode, doundo); }

	//----------------------------------------------------------------------------------------
	/// Retrieves the filename of the paint texture.
	/// @return												The filename.
	//----------------------------------------------------------------------------------------
	const Filename GetFilename() { return C4DOS.Pa->PT_GetFilename(this); }

	//----------------------------------------------------------------------------------------
	/// Retrieves the number of layers of the paint texture.
	/// @return												The number of layers.
	//----------------------------------------------------------------------------------------
	Int32 GetLayerCount() const;

	//----------------------------------------------------------------------------------------
	/// Retrieves the number of alpha channels of the paint texture.
	/// @return												The number of alpha channels.
	//----------------------------------------------------------------------------------------
	Int32 GetAlphaCount() const;

	//----------------------------------------------------------------------------------------
	/// Retrieves the head of the paint texture list. Use this to browse through the available paint textures.
	/// @return												The head of the paint texture list.
	//----------------------------------------------------------------------------------------
	static GeListHead* GetPaintTextureHead() { return C4DOS.Pa->PT_GetPaintTextureHead(); }

	//----------------------------------------------------------------------------------------
	/// Creates a new paint texture.
	/// @param[in] path								The filename for the paint texture.
	/// @param[in] settings						The settings for the texture creation: @enumerateEnum{TEXTURE}
	/// @return												The created paint texture if successful, otherwise @formatConstant{nullptr}.
	//----------------------------------------------------------------------------------------
	static PaintTexture* CreateNewTexture(const Filename& path, const BaseContainer& settings);

	//----------------------------------------------------------------------------------------
	/// Retrieves the default settings of textures for the passed material @formatParam{channel} ID.
	/// @param[in] channel						The material channel ID: @enumerateEnum{CHANNEL}
	/// @param[out] settings					Filled with the default texture settings of the passed material @formatParam{channel}.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	static Bool GetTextureDefaults(Int32 channel, BaseContainer& settings);

	// resolves the painttexture used in a basechannel

	//----------------------------------------------------------------------------------------
	/// Retrieves the paint texture of a material's channel.
	/// @param[in] doc								The document the material is attached to.
	/// @param[in] bc									The channel queried for the paint texture.
	/// @return												The paint texture if successful, otherwise @formatConstant{nullptr}.
	//----------------------------------------------------------------------------------------
	static inline PaintTexture* GetPaintTextureOfBaseChannel(BaseDocument* doc, BaseChannel* bc) { return C4DOS.Pa->GetPaintTextureOfBaseChannel(doc, bc); }

	//----------------------------------------------------------------------------------------
	/// Selects a paint texture.
	/// @param[in] bmp								The paint texture to select.
	/// @param[in] preferred					The preferred paint material, usually @formatConstant{nullptr}.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	static Bool SetSelected_Texture(PaintBitmap* bmp, PaintMaterial* preferred) { return C4DOS.Pa->PT_SetSelected_Texture(bmp, preferred); }

	//----------------------------------------------------------------------------------------
	/// Retrieves the selected paint texture.
	/// @return												The selected paint texture, or @formatConstant{nullptr} if no paint is selected.
	//----------------------------------------------------------------------------------------
	static PaintTexture* GetSelectedTexture() { return C4DOS.Pa->PT_GetSelectedTexture(); }

	//----------------------------------------------------------------------------------------
	/// Retrieves the selected projection painting texture.
	/// @param[out] ppmat							Filled with the preferred paint material, usually @formatConstant{nullptr}.
	/// @return												The selected projection painting texture, or @formatConstant{nullptr} if not available.
	//----------------------------------------------------------------------------------------
	static PaintTexture* GetSelectedTexturePP(PaintMaterial** ppmat = nullptr) { return C4DOS.Pa->PT_GetSelectedTexturePP(ppmat); }

	//----------------------------------------------------------------------------------------
	/// Sets the color profile for the paint texture.
	/// @since R17.032
	/// @param[in] profile						The color profile to set.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool SetColorProfile(const ColorProfile& profile) { return C4DOS.Pa->PT_SetColorProfile(this, profile); }

	//----------------------------------------------------------------------------------------
	/// Gets the color profile for the paint texture.
	/// @since R17.032
	/// @return												The color profile.
	//----------------------------------------------------------------------------------------
	const ColorProfile& GetColorProfile() const { return C4DOS.Pa->PT_GetColorProfile(this); }
};

//----------------------------------------------------------------------------------------
/// A class for paint materials. It represents a paintable material.
//----------------------------------------------------------------------------------------
class PaintMaterial : public PaintBitmap
{
private:
	PaintMaterial();
	~PaintMaterial();

public:
	//----------------------------------------------------------------------------------------
	/// Enables a material for painting.
	/// @param[in] doc								The document the material belongs to.
	/// @param[in] on									@formatConstant{true} to enable the material for painting, @formatConstant{false} to disable it.
	/// @param[in] suppressevent			@markPrivate
	/// @param[in] domaterialundo			If @formatConstant{true} an undo is created on the undo stack.
	//----------------------------------------------------------------------------------------
	void EnableMaterial(BaseDocument* doc, Bool on, Bool suppressevent = false, Bool domaterialundo = true) { C4DOS.Pa->PM_EnableMaterial(this, doc, on, suppressevent, domaterialundo); }

	//----------------------------------------------------------------------------------------
	/// Retrieves the active paint material.
	/// @param[in] doc								Pass the document to look for active paint materials.
	/// @param[out] mat								Filled with the material linked to the paint material.
	/// @return												The active paint material, or @formatConstant{nullptr} if there is none.
	//----------------------------------------------------------------------------------------
	static PaintMaterial* GetActivePaintMaterial(BaseDocument* doc = nullptr, BaseMaterial** mat = nullptr) { return C4DOS.Pa->PM_GetActivePaintMaterial(doc, mat); }

	//----------------------------------------------------------------------------------------
	/// Retrieves a paint material from a paint texture.
	/// @param[in] tex								The paint texture to retrieve the paint material from.
	/// @param[in] onlyeditable				@formatConstant{true} to retrieve only editable paint materials.
	/// @return												The paint material of the texture, or @formatConstant{nullptr} if there is no paint material available.
	//----------------------------------------------------------------------------------------
	static PaintMaterial* GetPaintMaterialFromTexture(PaintTexture* tex, Bool onlyeditable) { return C4DOS.Pa->PM_GetPaintMaterialFromTexture(tex, onlyeditable); }

	//----------------------------------------------------------------------------------------
	/// Retrieves the paint material of the material.
	/// @param[in] doc								The document of the material.
	/// @param[in] material						The material to evaluate.
	/// @param[in] create							@formatConstant{true} to force a paint material.
	/// @return												The paint material, or @formatConstant{nullptr} if there is none.
	//----------------------------------------------------------------------------------------
	static PaintMaterial* GetPaintMaterial(BaseDocument* doc, BaseMaterial* material, Bool create) { return C4DOS.Pa->PM_GetPaintMaterial(doc, material, create); }

	//----------------------------------------------------------------------------------------
	/// Unloads a paint material (close all textures of the material).
	/// @param[in] doc								The document of the material.
	/// @param[in] material						The material to unload.
	/// @param[in] forcesave					@formatConstant{true} to force save all the textures.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	static Bool UnloadPaintMaterial(BaseDocument* doc, BaseMaterial* material, Bool forcesave) { return C4DOS.Pa->PM_UnloadPaintMaterial(doc, material, forcesave); }

	//----------------------------------------------------------------------------------------
	/// @markPrivate
	//----------------------------------------------------------------------------------------
	static Bool SaveDocument(BaseDocument* doc, Bool& cancel) { return C4DOS.Pa->PM_SaveDocument(doc, cancel); }

	//----------------------------------------------------------------------------------------
	/// @markPrivate
	//----------------------------------------------------------------------------------------
	static Bool AskNeedToSave(BaseDocument* doc) { return C4DOS.Pa->PM_AskNeedToSave(doc); }
};

#endif

/// @addtogroup TEXTURE
/// @ingroup group_enumeration
/// @{
/// Flags for PaintTexture::CreateNewTexture() and PaintTexture::GetTextureDefaults().
#define TEXTURE_FILEFORMAT			1000			///< ::Int32 File format: @enumerateEnum{FILTER}
#define TEXTURE_WIDTH						1001			///< ::Int32 Texture width.
#define TEXTURE_HEIGHT					1002			///< ::Int32 Texture height.
#define TEXTURE_MODE						1003			///< ::Int32 Texture mode (only non-alpha channel modes):\n
																					///< @ref COLORMODE::GRAY, @ref COLORMODE::RGB, @ref COLORMODE::RGBw, @ref COLORMODE::GRAYw, @ref COLORMODE::RGBf, @ref COLORMODE::GRAYf
#define TEXTURE_COLOR						1004			///< ::Vector Texture color.
#define TEXTURE_SAVE_IMMEDIATLY	1005			///< ::Bool Flag to save immediately, otherwise texture is only created in memory.
/// @}

/// @addtogroup GETALLSTRINGS
/// @ingroup group_enumeration
/// @{
/// @markPrivate
#define GETALLSTRINGS_FILESTRING			1
#define GETALLSTRINGS_SUGGESTED_PATH	2
#define GETALLSTRINGS_CHANNEL_ID			3
/// @}

//----------------------------------------------------------------------------------------
/// @markPrivate
//----------------------------------------------------------------------------------------
Bool GetAllStrings_AddTexture(const void* msgdata, const BaseContainer& d);

//----------------------------------------------------------------------------------------
/// Activates/deactivates paint channels.
/// @param[in] channel						The paint channel: @enumerateEnum{CHANNEL}
/// @param[in] multi							@formatConstant{true} for multi channel painting, @formatConstant{false} for single channel painting.
/// @param[in] enable							@formatConstant{true} to activate the paint channel, @formatConstant{false} to deactivate the paint channel.
//----------------------------------------------------------------------------------------
void PainterActivateChannel(Int32 channel, Bool multi, Bool enable);

//----------------------------------------------------------------------------------------
/// Opens the texture creation dialog for a material.
/// @param[out] result						Filled with the texture's name (e.g. the filename).
/// @param[out] resultdirectory		The directory of the texture.
/// @param[in] channelid					The channel type: @enumerateEnum{CHANNEL}
/// @param[in] bmat								The material of the texture.
/// @return												The created paint texture if successful, otherwise @formatConstant{nullptr}. @cinemaOwnsPointed{paint texture}
//----------------------------------------------------------------------------------------
PaintTexture* PainterCreateNewTextureDialog(String& result, Filename& resultdirectory, Int32 channelid, BaseMaterial* bmat);

#endif // C4D_PAINTER_H__
