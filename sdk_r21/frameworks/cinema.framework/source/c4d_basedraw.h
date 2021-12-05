/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef C4D_BASEDRAW_H__
#define C4D_BASEDRAW_H__

#ifdef __API_INTERN__
	#error "Not in the kernel"
#endif

#include "ge_math.h"
#include "c4d_baselist.h"
#include "c4d_basecontainer.h"
#include "c4d_general.h"
#include "matrix4.h"

//-------------------------------------------------------------------------------------------------
/// Contains useful data for drawing into a BaseDraw view.
/// Passed by the framework to methods that need it.
/// @addAllocFreeAutoAllocNote
//-------------------------------------------------------------------------------------------------
class BaseDrawHelp
{
private:
	//-------------------------------------------------------------------------------------------------
	/// Constructor.
	//-------------------------------------------------------------------------------------------------
	BaseDrawHelp();

	//-------------------------------------------------------------------------------------------------
	/// Destructor.
	//-------------------------------------------------------------------------------------------------
	~BaseDrawHelp();

public:

	//----------------------------------------------------------------------------------------
	/// @allocatesA{BaseDrawHelp}
	/// @param[in] bd									The BaseDraw the BaseDrawHelp is assigned to.
	/// @param[in] doc								The document of the BaseDraw.
	/// @return												@allocReturn{BaseDrawHelp}
	//----------------------------------------------------------------------------------------
	static BaseDrawHelp* Alloc(BaseDraw* bd, BaseDocument* doc);

	//----------------------------------------------------------------------------------------
	/// @destructsAlloc{BaseDrawHelp instances}
	/// @param[in,out] p							@theToDestruct{BaseDrawHelp}
	//----------------------------------------------------------------------------------------
	static void Free(BaseDrawHelp*& p);

	//----------------------------------------------------------------------------------------
	/// Gets the relevant document for the current draw operation, i.e. the currently active document.
	/// @note Never returns @formatConstant{nullptr}.
	/// @return												The document for the current draw operation. @cinemaOwnsPointed{document}
	//----------------------------------------------------------------------------------------
	BaseDocument* GetDocument(void){ return C4DOS.Br->BbGetDocument(this); }

	//----------------------------------------------------------------------------------------
	/// Gets the active tag, or @formatConstant{nullptr} if no tag is active. (Similar to calling GetDocument()->@link BaseDocument::GetActiveTag() GetActiveTag()@endlink but more efficient since the active tag is cached.)
	/// @return												The active tag. @cinemaOwnsPointed{tag}
	//----------------------------------------------------------------------------------------
	BaseTag* GetActiveTag(void){ return C4DOS.Br->BbGetActiveTag(this); }

	//----------------------------------------------------------------------------------------
	/// Gets the global matrix of the object to be drawn. (Similar to <i>op</i>->@link BaseObject::GetMg() GetMg()@endlink but more efficient since the matrix is cached.)
	/// @return												The global matrix of the object to be drawn.
	//----------------------------------------------------------------------------------------
	const Matrix& GetMg(void){ return C4DOS.Br->BbGetMg(this); }

	//----------------------------------------------------------------------------------------
	/// Sets the matrix returned by GetMg().
	/// @param[in] mg									The new global matrix of the object to be drawn.
	//----------------------------------------------------------------------------------------
	void SetMg(const Matrix& mg){ C4DOS.Br->BbSetMg(this, mg); }

	//----------------------------------------------------------------------------------------
	/// Gets a container with the display mode for the object to be drawn. See @em Tdisplay.h for values.
	/// @return												The display mode container.
	//----------------------------------------------------------------------------------------
	BaseContainer GetDisplay(void){ BaseContainer bc; C4DOS.Br->BbGetDisplay(this, &bc); return bc; }

	//----------------------------------------------------------------------------------------
	/// Sets the display mode for the object to be drawn. See @em Tdisplay.h for values.
	/// @param[in] bc									The new display mode container.
	//----------------------------------------------------------------------------------------
	void SetDisplay(BaseContainer* bc){ C4DOS.Br->BbSetDisplay(this, bc); }

	//----------------------------------------------------------------------------------------
	/// Gets the flags which have been passed to DrawViews().
	/// @return												A combination of the view scheduler flags: @enumerateEnum{DRAWFLAGS}
	//----------------------------------------------------------------------------------------
	DRAWFLAGS GetViewSchedulerFlags() const { return C4DOS.Br->BbGetViewSchedulerFlags(this); }

	//----------------------------------------------------------------------------------------
	/// Checks if the current object is active.
	/// @return												@trueIfOtherwiseFalse{the current object is active}
	//----------------------------------------------------------------------------------------
	Bool IsActive() const { return C4DOS.Br->BbIsActive(this); }

	//----------------------------------------------------------------------------------------
	/// Checks if the current object is highlighted (i.e. when the user has moved the mouse over it).
	/// @return												@trueIfOtherwiseFalse{the current object is highlighted}
	//----------------------------------------------------------------------------------------
	Bool IsHighlight() const { return C4DOS.Br->BbIsHighlight(this); }
};


/// Set if the color is already in the color space of the BaseDraw. Otherwise the color will be converted.
#define SET_PEN_USE_PROFILE_COLOR 1

/// The far clipping value in the editor perspective mode.
#define MAX_Z 1000000

/// The near clipping value in the editor perspective mode.
#define VIEW_NEARCLIPPING 0.01


/// @addtogroup OITOITMODE
/// @ingroup group_enumeration
/// @{
/// @extOpenGlMode
enum class OITMODE
{
	OFF			= 0,
	FIRST		= 1,
	MIDDLE	= 2,
	LAST		= 3
} MAXON_ENUM_LIST(OITMODE);
/// @}

/// @extOpenGlMode
struct OITInfo
{
	OITMODE mode;
	Int32 lPass;
	C4DGLuint nDepthTexture;
	void* pData;
	Vector4d32 vScaleOff;
};


/// Struct for the @ref BASEDRAW_MESSAGE_SET_SCENE_CAMERA message.
struct BDSetSceneCameraMsg
{
	BaseObject* op;			///< The object that will become the new scene camera.
	Bool animate;				///< @formatConstant{true} if the change should be animated.
};


/// Class structure to hold HUD Text for @ref BaseDraw::DrawMultipleHUDText(). @since R18
class HUDTextEntry
{
public:
	explicit HUDTextEntry(const maxon::String& txt = maxon::String(), const Vector& position = Vector()) : _txt(txt), _position(position) { }

	String _txt; 			///< The text to draw to the HUD.
	Vector _position;	///< The screen space position for the text.
};


/// @addtogroup DRAW_STATISTIC
/// @ingroup group_enumeration
/// @{
#define DRAW_STATISTIC_TRIANGLES				0			///< ::Int32 Number of triangles.
#define DRAW_STATISTIC_QUADS						1			///< ::Int32 Number of quadrangles.
#define DRAW_STATISTIC_LINES						2			///< ::Int32 Number of lines.
#define DRAW_STATISTIC_POINTS						3			///< ::Int32 Number of points.
#define DRAW_STATISTIC_TRIANGLE_STRIPS	4			///< ::Int32 Number of triangle strips.
#define DRAW_STATISTIC_LINE_STRIPS			5			///< ::Int32 Number of line strips.
#define DRAW_STATISTIC_PATCHES					6			///< ::Int32 Number of patches. @since R18
/// @}


//-------------------------------------------------------------------------------------------------
/// Represents an editor view. Cannot be instantiated. In most cases the sub-class BaseDraw is used. It adds functions for drawing into the view.
/// See the @em dbasedraw.h description file for container IDs.
//-------------------------------------------------------------------------------------------------
class BaseView : public BaseList2D
{
private:
	BaseView();
	~BaseView();

public:

	/// @name Frame
	/// @{

	//----------------------------------------------------------------------------------------
	/// Assigns the dimension in pixels of the view window. The coordinates are relative to the upper left corner of the view, and specify visible pixels (i.e. the border is not included).
	/// @param[out] cl								Is assigned the first visible left pixel position.
	/// @param[out] ct								Is assigned the first visible top pixel position.
	/// @param[out] cr								Is assigned the first visible right pixel position.
	/// @param[out] cb								Is assigned the first visible bottom pixel position.
	//----------------------------------------------------------------------------------------
	void GetFrame(Int32* cl, Int32* ct, Int32* cr, Int32* cb);

	//----------------------------------------------------------------------------------------
	/// Assigns the dimension in pixels of the safe frame (the frame which is rendered) to the passed pointers. The coordinates are relative to the upper left corner of the view.
	/// @param[out] cl								Is assigned the first visible left pixel position.
	/// @param[out] ct								Is assigned the first visible top pixel position.
	/// @param[out] cr								Is assigned the first visible right pixel position.
	/// @param[out] cb								Is assigned the first visible bottom pixel position.
	//----------------------------------------------------------------------------------------
	void GetSafeFrame(Int32* cl, Int32* ct, Int32* cr, Int32* cb);

	/// @}

	/// @name View Matrix/Rotation
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets the camera matrix, i.e. the global object matrix of the current camera object.
	/// @return												The camera matrix.
	//----------------------------------------------------------------------------------------
	Matrix GetMg(void) { return C4DOS.Bv->GetMg(this); }

	//----------------------------------------------------------------------------------------
	/// Gets the inverse of the camera matrix. Equivalent to !@link GetMg() GetMg()@endlink, but faster.
	/// @return												The inverted camera matrix.
	//----------------------------------------------------------------------------------------
	Matrix GetMi(void) { return C4DOS.Bv->GetMi(this); }

	//----------------------------------------------------------------------------------------
	/// Gets the base matrix.
	/// @note The base matrix is multiplied with the camera matrix so that it is possible to have e.g. a frontal view into another direction than @em +Z.
	/// @return												The base matrix.
	//----------------------------------------------------------------------------------------
	const Matrix& GetBaseMatrix() const { return C4DOS.Bv->GetBaseMatrix(this); }

	//----------------------------------------------------------------------------------------
	/// Sets the base matrix.
	/// @note The base matrix is multiplied with the camera matrix so that it is possible to have e.g. a frontal view into another direction than @em +Z.
	/// @param[in] m									The new base matrix.
	//----------------------------------------------------------------------------------------
	void SetBaseMatrix(const Matrix& m) { C4DOS.Bv->SetBaseMatrix(this, m); }

	//----------------------------------------------------------------------------------------
	/// Gets the rotation of the planar views.
	/// @return												The planar rotation.
	//----------------------------------------------------------------------------------------
	Float GetPlanarRotation() const { return C4DOS.Bv->GetPlanarRotation(this); }

	//----------------------------------------------------------------------------------------
	/// Sets the rotation of the planar views.
	/// @param[in] r									The new planar rotation.
	//----------------------------------------------------------------------------------------
	void SetPlanarRotation(Float r) { C4DOS.Bv->SetPlanarRotation(this, r); }

	/// @}

	/// @name Test Point/Clipping
	/// @{

	//----------------------------------------------------------------------------------------
	/// Tests if the point is within the boundary returned by GetFrame(). The point coordinates must be in screen space.
	/// @param[in] x									The X coordinate of the point to check.
	/// @param[in] y									The Y coordinate of the point to check.
	/// @return												@trueIfOtherwiseFalse{the point is inside the frame}
	//----------------------------------------------------------------------------------------
	Bool TestPoint(Float x, Float y) { return C4DOS.Bv->TestPoint(this, x, y); }

	//----------------------------------------------------------------------------------------
	/// Tests if the point is visible within the near and far clipping planes defined in the view according to the current projection. The point must be in camera space.
	/// @param[in] p									The point to check.
	/// @return												@trueIfOtherwiseFalse{the point is visible in the view}
	//----------------------------------------------------------------------------------------
	Bool TestPointZ(const Vector& p) { return C4DOS.Bv->TestPointZ(this, p); }

	//----------------------------------------------------------------------------------------
	/// Tests if a bounding box is visible in the view according to the current projection. The box is defined by these eight corner coordinates:
	/// @code
	/// p[0] = Vector(mp.x + rad.x, mp.y + rad.y, mp.z + rad.z) * mg;
	/// p[1] = Vector(mp.x + rad.x, mp.y + rad.y, mp.z - rad.z) * mg;
	/// p[2] = Vector(mp.x + rad.x, mp.y - rad.y, mp.z + rad.z) * mg;
	/// p[3] = Vector(mp.x + rad.x, mp.y - rad.y, mp.z - rad.z) * mg;
	/// p[4] = Vector(mp.x - rad.x, mp.y + rad.y, mp.z + rad.z) * mg;
	/// p[5] = Vector(mp.x - rad.x, mp.y + rad.y, mp.z - rad.z) * mg;
	/// p[6] = Vector(mp.x - rad.x, mp.y - rad.y, mp.z + rad.z) * mg;
	/// p[7] = Vector(mp.x - rad.x, mp.y - rad.y, mp.z - rad.z) * mg;
	/// @endcode
	/// @param[in] mp									The center of the box.
	/// @param[in] rad								The radius of the box.
	/// @param[in] mg									The transformation to world space from @formatParam{mp}/@formatParam{rad} space.
	/// @param[out] clip2d						Is assigned @formatConstant{true} if the box needs @em 2D clipping, i.e. if any part of it is outside of the view boundaries. Otherwise @formatConstant{false}.
	/// @param[in] clipz							Is assigned @formatConstant{true} if the box needs @em Z clipping, i.e. if any part of it is too close to or behind the camera. Otherwise @formatConstant{false}.
	/// @return												@trueIfOtherwiseFalse{the box is visible}
	//----------------------------------------------------------------------------------------
	Bool TestClipping3D(const Vector& mp, const Vector& rad, const Matrix& mg, Bool* clip2d, Bool* clipz);

	//----------------------------------------------------------------------------------------
	/// Clips the line defined by @formatParam{p1} and @formatParam{p2} so that it fits within the view boundary. The new values are stored directly in the passed vectors. The points are in screen space.\n
	/// When combined with ClipLineZ(), the @em Z clipping must be done first and then the @em 2D clipping.
	/// @note When combined with ClipLineZ(), the @em Z clipping must be done first and then the @em 2D clipping.
	/// @param[in,out] p1							The start of the line. Is assigned the clipped start point.
	/// @param[in,out] p2							The end of the line. Is assigned the clipped end point.
	/// @return												@trueIfOtherwiseFalse{any part of the line was within the view boundary}
	//----------------------------------------------------------------------------------------
	Bool ClipLine2D(Vector* p1, Vector* p2) { return C4DOS.Bv->ClipLine2D(this, p1, p2); }

	//----------------------------------------------------------------------------------------
	/// Clips the line defined by @formatParam{p1} and @formatParam{p2} so that it does not come too close to or behind the camera (i.e. it assures that, for those projections that have @em Z clipping, no values are negative or goes through the camera's zero plane).\n
	/// The new values are stored directly in the passed vectors. The points must be in camera space.
	/// @note When combined with ClipLine2D(), the @em Z clipping must be done first and then the @em 2D clipping.
	/// @param[in,out] p1							The start of the line. Is assigned the clipped start point.
	/// @param[in,out] p2							The end of the line. Is assigned the clipped end point.
	/// @return												@trueIfOtherwiseFalse{any part of the line was within the camera boundary}
	//----------------------------------------------------------------------------------------
	Bool ClipLineZ(Vector* p1, Vector* p2) { return C4DOS.Bv->ClipLineZ(this, p1, p2); }

	/// @}

	/// @name Spaces Conversion
	/// @{

	//----------------------------------------------------------------------------------------
	/// World to screen conversion. Converts @formatParam{p} from world space to screen space (pixels relative to the view), and returns the conversion.\n
	/// The orthogonal distance to the world point is stored in world units in the Z axis of the result.
	/// @param[in] p									A point in world space.
	/// @return												The point in screen space.
	//----------------------------------------------------------------------------------------
	Vector WS(const Vector& p) { return C4DOS.Bv->WS(this, p); }

	//----------------------------------------------------------------------------------------
	/// Screen to world conversion. Converts @formatParam{p} from screen space (pixels relative to the view) to world space.\n
	/// The X and Y coordinates of the point are given in screen space, the Z coordinate is the orthogonal distance in world units to the point from the view plane.
	/// @param[in] p									A point in screen space.
	/// @return												The point in world space.
	//----------------------------------------------------------------------------------------
	Vector SW(const Vector& p) { return C4DOS.Bv->SW(this, p); }

	//----------------------------------------------------------------------------------------
	/// Screen to world conversion. Converts the point given by @formatParam{x} and @formatParam{y} in screen space (pixels relative to the view) to world space.\n
	/// The Z coordinate is taken from the orthogonal distance in world units to @formatParam{wp} from the view plane.
	/// @param[in] x									The X coordinate in screen space.
	/// @param[in] y									The Y coordinate in screen space.
	/// @param[in] wp									The reference point in world space.
	/// @return												The point in world space.
	//----------------------------------------------------------------------------------------
	Vector SW_Reference(Float x, Float y, const Vector& wp) { return C4DOS.Bv->SW_R(this, x, y, wp); }

	//----------------------------------------------------------------------------------------
	/// World to camera conversion. Converts @formatParam{p} from world to camera space.
	/// @param[in] p									A point in world space.
	/// @return												The point in camera space.
	//----------------------------------------------------------------------------------------
	Vector WC(const Vector& p) { return C4DOS.Bv->WC(this, p); }

	//----------------------------------------------------------------------------------------
	/// Camera to world conversion. Converts @formatParam{p} from camera to world space.
	/// @param[in] p									A point in camera space.
	/// @return												The point in world space.
	//----------------------------------------------------------------------------------------
	Vector CW(const Vector& p) { return C4DOS.Bv->CW(this, p); }

	//----------------------------------------------------------------------------------------
	/// Screen to camera conversion. Converts @formatParam{p} from screen (pixels relative to the view) to camera space.\n
	/// The X and Y coordinates of the point are given in screen space, the Z coordinate is the orthogonal distance in world units to the point from the view plane.
	/// @param[in] p									A point in screen space.
	/// @return												The point in camera space.
	//----------------------------------------------------------------------------------------
	Vector SC(const Vector& p) { return C4DOS.Bv->SC(this, p); }

	//----------------------------------------------------------------------------------------
	/// Camera to screen conversion. Converts @formatParam{p} from camera to screen space (pixels relative to the view).
	/// @param[in] p									A point in camera space.
	/// @param[in] z_inverse					If @trueIfOtherwiseFalse{true} the Z coordinate of the converted point is inverted. This is used by the Z-buffer.
	/// @return												The point in screen space.
	//----------------------------------------------------------------------------------------
	Vector CS(const Vector& p, Bool z_inverse) { return C4DOS.Bv->CS(this, p, z_inverse); }

	//----------------------------------------------------------------------------------------
	/// World to camera vector conversion. Converts the world vector @formatParam{v} to camera space.
	/// @param[in] v									A vector in world space.
	/// @return												The vector in camera space.
	//----------------------------------------------------------------------------------------
	Vector WC_V(const Vector& v) { return C4DOS.Bv->WC_V(this, v); }

	//----------------------------------------------------------------------------------------
	/// Camera to world vector conversion. Converts the camera vector @formatParam{v} to world space.
	/// @param[in] v									A vector in camera space.
	/// @return												The vector in world space.
	//----------------------------------------------------------------------------------------
	Vector CW_V(const Vector& v) { return C4DOS.Bv->CW_V(this, v); }

	//----------------------------------------------------------------------------------------
	/// World to screen vector conversion. Converts @formatParam{v} from world space to screen space (pixels relative to the view), and returns the conversion.\n
	/// The orthogonal distance to the world point is stored in world units in the Z axis of the result.
	/// @param[in] v									A vector in world space.
	/// @param[in] p									A reference point in world space.
	/// @return												The vector in screen space.
	//----------------------------------------------------------------------------------------
	Vector WS_V(const Vector &v, const Vector &p) { return C4DOS.Bv->WS_V(this, v, p); }

	//----------------------------------------------------------------------------------------
	/// Screen to world vector conversion. Converts @formatParam{v} from screen space (pixels relative to the view) to world space.\n
	/// The X and Y coordinates of the point are given in screen space, the Z coordinate is the orthogonal distance in world units to the point from the view plane.
	/// @param[in] v									A vector in screen space.
	/// @param[in] p									A reference point in screen space.
	/// @return												The vector in world space.
	//----------------------------------------------------------------------------------------
	Vector SW_V(const Vector &v, const Vector &p) { return C4DOS.Bv->SW_V(this, v, p); }

	/// @}

	/// @name Pixel Conversion
	// @{

	//----------------------------------------------------------------------------------------
	/// Gets the size in world units for a single pixel at the given Z-depth @formatParam{z}.
	/// @param[in] z									The Z-depth.
	/// @param[in] horizontal					@formatConstant{true} if the size is measured horizontally, @formatConstant{false} for vertically measurement. This is useful for non-square pixel aspect ratios.
	/// @return												The size in world units.
	//----------------------------------------------------------------------------------------
	Float PW_S(Float z, Bool horizontal);

	//----------------------------------------------------------------------------------------
	/// Gets the size in pixels for a single world unit at the given Z-depth @formatParam{z}.
	/// @param[in] z									The Z-depth.
	/// @param[in] horizontal					@formatConstant{true} if the size is measured horizontally, @formatConstant{false} for vertically measurement. This is useful for non-square pixel aspect ratios.
	/// @return												The size in pixels.
	//----------------------------------------------------------------------------------------
	Float WP_S(Float z, Bool horizontal);

	//----------------------------------------------------------------------------------------
	/// Gets the size in world units for a single pixel at screen space vector @formatParam{p}.
	/// @param[in] p									The pixel in screen space.
	/// @param[in] horizontal					@formatConstant{true} if the size is measured horizontally, @formatConstant{false} for vertically measurement. This is useful for non-square pixel aspect ratios.
	/// @return												The size in world units.
	//----------------------------------------------------------------------------------------
	Float PW_W(const Vector& p, Bool horizontal);

	//----------------------------------------------------------------------------------------
	/// Gets the size in screen space pixels for a single world unit at world position @formatParam{p}.
	/// @param[in] p									The point in world space.
	/// @param[in] horizontal					@formatConstant{true} if the size is measured horizontally, @formatConstant{false} for vertically measurement. This is useful for non-square pixel aspect ratios.
	/// @return												The size in screen space pixels.
	//----------------------------------------------------------------------------------------
	Float WP_W(const Vector& p, Bool horizontal);

	/// @}

	/// @name Z-Near/Far
	/// @{

	//----------------------------------------------------------------------------------------
	/// Indicates if the view has @em Z near-clipping.
	/// @return												@trueIfOtherwiseFalse{the view has Z near-clipping}
	//----------------------------------------------------------------------------------------
	Bool ZSensitiveNear(void) { return C4DOS.Bv->ZSensitiveNear(this); }

	//----------------------------------------------------------------------------------------
	/// Gets the near-clipping of @em Z sensitive view.
	/// @return												The Z near-clipping distance.
	//----------------------------------------------------------------------------------------
	Float ZSensitiveNearClipping(void) { return C4DOS.Bv->ZSensitiveNearClipping(this); }

	//----------------------------------------------------------------------------------------
	/// Indicates if the view is @em Z far-clipping sensitive.
	/// @return												@trueIfOtherwiseFalse{the view has Z far-clipping}
	//----------------------------------------------------------------------------------------
	Bool ZSensitiveFar(void) { return C4DOS.Bv->ZSensitiveFar(this); }

	//----------------------------------------------------------------------------------------
	/// Gets the far-clipping of @em Z sensitive view.
	/// @return												The Z far-clipping distance.
	//----------------------------------------------------------------------------------------
	Float ZSensitiveFarClipping(void) { return C4DOS.Bv->ZSensitiveFarClipping(this); }

	/// @}

	/// @name Project Point
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets the nearest point on the line defined by @formatParam{p} and @formatParam{v} for a given mouse coordinate.
	/// @param[in] p									The start position of the line in world space.
	/// @param[in] v									The direction of the line. The length of this vector determines the scaling of @formatParam{offset}.
	/// @param[in] mouse_x						The mouse X-coordinate.
	/// @param[in] mouse_y						The mouse Y-coordinate.
	/// @param[out] offset						Assigned the distance from @formatParam{p} scaled by the length of @formatParam{v}. offset = distance to p / length of v.
	/// @param[out] err								Assigned an error code:
	/// 															- <i>1</i> = Failed to find nearest point correctly, lines may be beyond horizon, behind camera, or ray line and line may be parallel.
	/// 															- <i>2</i> = The point @formatParam{p} is either beyond the start or end of the described segment (but a point will still be returned for the line/ray).
	/// @return												The nearest point on the line.
	//----------------------------------------------------------------------------------------
	Vector ProjectPointOnLine(const Vector& p, const Vector& v, Float mouse_x, Float mouse_y, Float* offset = nullptr, Int32* err = nullptr);

	//----------------------------------------------------------------------------------------
	/// Gets the nearest point on the plane defined by @formatParam{p} and @formatParam{v} for a given mouse coordinate.
	/// @param[in] p									The plane's position in world space.
	/// @param[in] v									The plane's normal in world space.
	/// @param[in] mouse_x						The mouse X-coordinate.
	/// @param[in] mouse_y						The mouse Y-coordinate.
	/// @param[out] err								Assigned an error code:
	/// 															- <i>1</i> = No intersection with plane possible, e.g. plane perpendicular to viewport so ray from view can never hit plane.
	/// 															- <i>2</i> = Out of range error, the calculation will be inaccurate, e.g. can be caused by point being over the horizon.
	/// 															- <i>3</i> = Hit point is behind the clipping plane of the camera, could sometimes result in an incorrect hit value.
	/// @return												The nearest point on the plane.
	//----------------------------------------------------------------------------------------
	Vector ProjectPointOnPlane(const Vector& p, const Vector& v, Float mouse_x, Float mouse_y, Int32* err = nullptr);

	/// @}

	/// @name Miscellaneous
	/// @{

	//----------------------------------------------------------------------------------------
	/// Tests the face with normal @formatParam{n} and center @formatParam{p} for backface culling.
	/// @param[in] n									The face normal in camera space.
	/// @param[in] p									The face center in camera space.
	/// @return												@trueIfOtherwiseFalse{the face is not visible}
	//----------------------------------------------------------------------------------------
	Bool BackfaceCulling(const Vector& n, const Vector& p) { return C4DOS.Bv->BackfaceCulling(this, n, p); }

	//----------------------------------------------------------------------------------------
	/// Gets the projection used by the view. See @em Ocamera.h for projection types values.
	/// @return												The projection type.
	//----------------------------------------------------------------------------------------
	Int32 GetProjection(void) { return C4DOS.Bv->GetProjection(this); }

	//----------------------------------------------------------------------------------------
	/// Gets the stereoscopic camera information data.
	/// @return												The stereoscopic camera data. @cinemaOwnsPointed{StereoCameraInfo}
	//----------------------------------------------------------------------------------------
	StereoCameraInfo* GetStereoInfo() const { return C4DOS.Bv->GetStereoInfo(this); }


	//----------------------------------------------------------------------------------------
	/// Retrieves the parameters for the current projection. See @em Ocamera.h for projection types.\n
	/// The following is the code used internally to project points:
	/// @code
	/// #define CAMDIST 0.05
	///
	/// Vector WorldToCamera(const Vector &p)
	/// {
	/// 	return p*inverse_camera_matrix;
	/// }
	///
	/// Vector CameraToWorld(const Vector &p)
	/// {
	/// 	return p*camera_matrix;
	/// }
	///
	/// Vector CameraToScreen(const Vector &pp)
	/// {
	/// 	Vector p = pp;
	///
	/// 	if (projection==Pperspective)
	/// 	{
	/// 		Float nz = p.z<=0.0 ? 1.0/CAMDIST : 1.0/(p.z + CAMDIST);
	/// 		p.x = p.x*scale.x*nz+off.x;
	/// 		p.y = p.y*scale.y*nz+off.y;
	/// 		return p;
	/// 	}
	///
	/// 	p.x = (p.x*scale.x)+off.x;
	/// 	p.y = (p.y*scale.y)+off.y;
	///
	/// 	switch (projection)
	/// 	{
	/// 		case Pmilitary: case Pfrog: case Pbird: case Pgentleman:
	/// 			p.x += p.z*scale.x*scalez.x;
	/// 			p.y -= p.z*scale.y*scalez.y;
	/// 			break;
	/// 	}
	///
	/// 	return p;
	/// }
	///
	/// Vector ScreenToCamera(const Vector &pp)
	/// {
	/// 	Vector p = pp;
	///
	/// 	switch (projection)
	/// 	{
	/// 		case Pmilitary: case Pfrog: case Pbird: case Pgentleman:
	/// 			p.x -= p.z*scale.x*scalez.x;
	/// 			p.y += p.z*scale.y*scalez.y;
	/// 			break;
	/// 	}
	///
	/// 	p.x = (p.x-off.x)/scale.x;
	/// 	p.y = (p.y-off.y)/scale.y;
	///
	/// 	if (projection==Pperspective)
	/// 	{
	/// 		Float nz = p.z + CAMDIST;
	/// 		p.x *= nz;
	/// 		p.y *= nz;
	/// 	}
	///
	/// 	return p;
	/// }
	/// @endcode
	/// For non-axonometric projection here is the code to calculate offset/scale:
	/// @code
	/// void InitView(BaseObject *camera, Float xres, Float yres, Float pix_x, Float pix_y)
	/// {
	/// 	// xres/yres are the resolution
	/// 	// pix_x/pix_y are the pixel aspect ratio (normally 1:1)
	///
	/// 	Matrix opm = camera->GetMg();
	/// 	Float ap;
	/// 	BaseContainer data = camera->GetDataInstance();
	///
	/// 	projection=data.GetInt32(CAMERA_PROJECTION,Pperspective);
	/// 	if (projection!=Pperspective && projection!=Pparallel)
	/// 	{
	/// 		opm.v1 = Vector(1.0,0.0,0.0);
	/// 		opm.v2 = Vector(0.0,1.0,0.0);
	/// 		opm.v3 = Vector(0.0,0.0,1.0);
	/// 	}
	///
	/// 	off.x = xres*0.5;
	/// 	off.y = yres*0.5;
	///
	/// 	if (b_ab==Pperspective)
	/// 	{
	/// 		ap=data.GetFloat(CAMERAOBJECT_APERTURE,36.0);
	/// 		scale.x = data.GetFloat(CAMERA_FOCUS,36.0) / ap * xres;
	/// 	}
	/// 	else
	/// 		scale.x = xres/1024.0*data.GetFloat(CAMERA_ZOOM,1.0);
	///
	/// 	scale.y = -scale.x*pix_x/pix_y;
	/// }
	/// @endcode
	/// @param[out] offset						Assigned the center of the view in screen space.
	/// @param[out] scale							Depends on the projection mode:
	/// 															- For perspective mode: Assigned the size of the view plane in pixels.
	/// 															- For axonometric modes: Assigned the number of pixels per meter.
	/// @param[out] scale_z						Assigned the different Z scale for the X and Y axes in axonometric projections.
	//----------------------------------------------------------------------------------------
	void GetViewParameter(Vector* offset, Vector* scale, Vector* scale_z) const;

	/// @}
};


/// @addtogroup DRAW_GET_VIEWMATRIX
/// @ingroup group_enumeration
/// @{
/// @see BaseDraw::GetViewMatrix()
#define DRAW_GET_VIEWMATRIX_PROJECTION						0			///< Projection matrix.
#define DRAW_GET_VIEWMATRIX_PROJECTION_LARGE_Z		1			///< Projection matrix without consideration of the set clipping planes. The following values for near and far clipping are used instead: near=1, far=100000 for perspective projection and near=-1000000, far=1000000 for other projection types.
#define DRAW_GET_VIEWMATRIX_INV_CAMERA						2			///< Inverse camera matrix.
#define DRAW_GET_VIEWMATRIX_MODELVIEW_PROJECTION	3			///< Projection*View*Model matrix. @b Slow.
/// @}


//-------------------------------------------------------------------------------------------------
/// Represents a view window that can be drawn into.
/// @addAllocFreeAutoAllocNote
/// @warning The BaseDraw parameters must only be accessed with GetParameter() / SetParameter(), not directly using the data container. GetParameterData() convenience method can be used to get parameters.
//-------------------------------------------------------------------------------------------------
class BaseDraw : public BaseView
{
private:
	BaseDraw();
	~BaseDraw();

	//-------------------------------------------------------------------------------------------------
	/// @markInternal
	/// @warning The BaseDraw parameters must only be accessed with GetParameter() / SetParameter(), not directly using the data container. GetParameterData() convenience method can be used to get parameters.
	//-------------------------------------------------------------------------------------------------
	BaseContainer GetData(void);

	//-------------------------------------------------------------------------------------------------
	/// @markInternal
	/// @warning The BaseDraw parameters must only be accessed with GetParameter() / SetParameter(), not directly using the data container. GetParameterData() convenience method can be used to get parameters.
	//-------------------------------------------------------------------------------------------------
	void SetData(const BaseContainer& bc, Bool add = true);

	//-------------------------------------------------------------------------------------------------
	/// @markInternal
	/// @warning The BaseDraw parameters must only be accessed with GetParameter() / SetParameter(), not directly using the data container. GetParameterData() convenience method can be used to get parameters.
	//-------------------------------------------------------------------------------------------------
	BaseContainer* GetDataInstance(void);

public:

	/// @name Get Parameter
	/// @{

	//----------------------------------------------------------------------------------------
	/// Convenience method to get parameters.\n
	/// Here is his simple implementation:
	/// @code
	/// GeData BaseDraw::GetParameterData(Int32 id)
	/// {
	/// 	GeData t_data;
	/// 	BaseList2D::GetParameter(DescLevel(id), t_data, DESCFLAGS_GET::NONE);
	/// 	return t_data;
	/// }
	/// @endcode
	/// @param[in] id									A parameter ID. See @em dbasedraw.h description file.
	/// @return												The parameter data for @formatParam{id}.
	//----------------------------------------------------------------------------------------
	GeData GetParameterData(Int32 id);

	/// @}

public:
	/// @name Alloc/Free
	/// @{

	//----------------------------------------------------------------------------------------
	/// @allocatesA{base draw}
	/// @markPrivate
	/// @note Useful for situations when there is no base draw available. It is used for instance in Mograph's Camera shader.
	/// @return												@allocReturn{base draw}
	//----------------------------------------------------------------------------------------
	static BaseDraw* Alloc() { return C4DOS.Br->AllocBaseDraw(); }

	//----------------------------------------------------------------------------------------
	/// @destructsAlloc{base draws}
	/// @markPrivate
	/// @param[in,out] bd							@theToDestruct{base draw}
	//----------------------------------------------------------------------------------------
	static void Free(BaseDraw*& bd) { C4DOS.Br->FreeBaseDraw(bd); }

	/// @}

	/// @name Camera
	/// @{

	//----------------------------------------------------------------------------------------
	/// Checks if the camera link is enabled.
	/// @return												@formatConstant{true} if a scene camera is used and @formatConstant{false} if the editor camera is used.
	//----------------------------------------------------------------------------------------
	Bool HasCameraLink(void) { return C4DOS.Br->HasCameraLink(this); }

	//----------------------------------------------------------------------------------------
	/// Gets the current scene camera from the passed document.
	/// @param[in] doc								The document to get the scene camera from. @callerOwnsPointed{document}
	/// @return												The scene camera, or @formatConstant{nullptr} if no scene camera is used.
	//----------------------------------------------------------------------------------------
	BaseObject* GetSceneCamera(const BaseDocument* doc) { return C4DOS.Br->GetSceneCamera(this, doc); }

	//----------------------------------------------------------------------------------------
	/// Sets a new scene camera. If @formatParam{op} is @formatConstant{nullptr}, the editor camera is used.
	/// @param[in] op									The new camera.
	/// @param[in] animate						@markPrivate
	//----------------------------------------------------------------------------------------
	void SetSceneCamera(BaseObject* op, Bool animate = false) { C4DOS.Br->SetSceneCamera(this, op, animate); }

	//----------------------------------------------------------------------------------------
	/// Gets the environment object, which is at the highest position in the scene hierarchy, visible and enabled.
	/// @since R19
	/// @return												The highest environment object.
	//----------------------------------------------------------------------------------------
	BaseObject* GetEnvironmentObject() const { return C4DOS.Br->GetEnvironmentObject(this); }

	//----------------------------------------------------------------------------------------
	/// Gets the sky object, which is at the highest position in the scene hierarchy, visible and enabled.
	/// @since R19
	/// @return												The highest sky object.
	//----------------------------------------------------------------------------------------
	BaseObject* GetSkyObject() const { return C4DOS.Br->GetSkyObject(this); }

	//----------------------------------------------------------------------------------------
	/// Gets the background object, which is at the highest position in the scene hierarchy, visible and enabled.
	/// @return												The highest background object.
	//----------------------------------------------------------------------------------------
	BaseObject* GetBackgroundObject() const { return C4DOS.Br->GetBackgroundObject(this); }

	//----------------------------------------------------------------------------------------
	/// Gets the foreground object, which is at the highest position in the scene hierarchy, visible and enabled.
	/// @return												The highest foreground object.
	//----------------------------------------------------------------------------------------
	BaseObject* GetForegroundObject() const { return C4DOS.Br->GetForegroundObject(this); }

	//----------------------------------------------------------------------------------------
	/// Gets the editor camera.
	/// @return												The editor camera. Guaranteed to never be @formatConstant{nullptr}.
	//----------------------------------------------------------------------------------------
	BaseObject* GetEditorCamera(void) { return C4DOS.Br->GetEditorCamera(this); }

	/// @}

	/// @name Initialization
	/// @{

/// Adjust the size of the frame buffer.
#define INIT_CLIPBOX_ADJUSTGLSIZE 1

	//----------------------------------------------------------------------------------------
	/// Used to render into a frame buffer with a different resolution than the editor view.
	/// @markPrivate
	/// @param[in] left								The left coordinate of the frame buffer.
	/// @param[in] top								The top coordinate of the frame buffer.
	/// @param[in] right							The right coordinate of the frame buffer.
	/// @param[in] bottom							The bottom coordinate of the frame buffer.
	/// @param[in] flags							The flag @ref INIT_CLIPBOX_ADJUSTGLSIZE can be set.
	//----------------------------------------------------------------------------------------
	void InitClipbox(Int32 left, Int32 top, Int32 right, Int32 bottom, Int32 flags) { C4DOS.Br->InitClipbox(this, left, top, right, bottom, flags); }

	//----------------------------------------------------------------------------------------
	/// Used to render into a frame buffer with a different resolution than the editor view.
	/// @markPrivate
	/// @param[in] camera							The camera's container. @callerOwnsPointed{container}
	/// @param[in] op_m								The camera's matrix.
	/// @param[in] sv									The frame's ratio.
	/// @param[in] pix_x							The frame's X size.
	/// @param[in] pix_y							The frame's Y size.
	/// @param[in] fitview						Set to @formatConstant{true} to fit the view.
	//----------------------------------------------------------------------------------------
	void InitView(BaseContainer* camera, const Matrix& op_m, Float sv, Float pix_x, Float pix_y, Bool fitview) { C4DOS.Br->InitView(this, camera, op_m, sv, pix_x, pix_y, fitview); }

	//----------------------------------------------------------------------------------------
	/// Used after rendering into a frame buffer with a different resolution than the editor view.
	/// @markPrivate
	/// @param[in] doc								The view's document. @callerOwnsPointed{document}
	/// @param[in] cam								The view's camera. @callerOwnsPointed{camera}
	/// @param[in] editorsv						Set to @formatConstant{true} to retain the view's ratio.
	//----------------------------------------------------------------------------------------
	void InitializeView(BaseDocument* doc, BaseObject* cam, Bool editorsv) { C4DOS.Br->InitializeView(this, doc, cam, editorsv); }

	//----------------------------------------------------------------------------------------
	/// Must be called from an external renderer to make use of the BaseDraw (e.g. for drawing helper lines).
	/// @since R19.SP2
	/// @markPrivate
	//----------------------------------------------------------------------------------------
	void InitLegacyDrawport() { C4DOS.Br->InitLegacyDrawport(this); }

	//----------------------------------------------------------------------------------------
	/// @markPrivate
	/// @since R19
	//----------------------------------------------------------------------------------------
	void DrawEnd() { C4DOS.Br->DrawEnd(this); }

	/// @}

	/// @name Color/Transparency
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets the wireframe color in the editor for the specified object.\n
	/// Some types of objects have certain colors. For polygon objects the main color is taken into account.
	/// @param[in] bh									The base draw helper.@callerOwnsPointed{base draw helper}
	/// @param[in] op									The object to get the wireframe color. @callerOwnsPointed{object}
	/// @param[in] lines							If set to @formatConstant{true} and the object's color is set to @em Layer but the object is not assigned to a layer the color set for <i>Shaded Wireframe</i> is used.
	/// @return												The object color.
	//----------------------------------------------------------------------------------------
	Vector GetObjectColor(BaseDrawHelp* bh, BaseObject* op, Bool lines = false) { return C4DOS.Br->GetObjectColor(this, op, bh, lines); }

	//----------------------------------------------------------------------------------------
	/// Makes sure that a color has at least 15% difference to the background color.
	/// @param[in] col								The original color.
	/// @return												The new color, adjusted if needed.
	//----------------------------------------------------------------------------------------
	Vector CheckColor(const Vector& col) { return C4DOS.Br->CheckColor(this, col); }

	//----------------------------------------------------------------------------------------
	/// Sets the transparency value for the following polygons drawing. The range is 0 to 255, where 255 is 100% transparent.\n
	/// Use negative values for true transparencies and positive values for 'dotted' transparencies.
	/// @param[in] trans							The transparency.
	//----------------------------------------------------------------------------------------
	void SetTransparency(Int32 trans) { C4DOS.Br->SetTransparency(this, trans); }

	//----------------------------------------------------------------------------------------
	/// Gets the current transparency value for polygons drawing. The range is 0 to 255, where 255 is 100% transparent.\n
	/// Negative values are true transparencies and positive values are 'dotted' transparencies.
	/// @return												The current transparency.
	//----------------------------------------------------------------------------------------
	Int32 GetTransparency(void) { return C4DOS.Br->GetTransparency(this); }

	/// @}

	/// @name Drawing Setup
	/// @{

	//----------------------------------------------------------------------------------------
	/// Sets the pen color for the following drawing operations.
	/// @param[in] col								The new pen color.
	/// @param[in] flags							Flag @ref SET_PEN_USE_PROFILE_COLOR can be set.
	//----------------------------------------------------------------------------------------
	void SetPen(const Vector& col, Int32 flags = 0) { C4DOS.Br->SetPen(this, col, flags); }

	//----------------------------------------------------------------------------------------
	/// Sets the drawn point size.
	/// @param[in] pointsize					The new point size.
	//----------------------------------------------------------------------------------------
	void SetPointSize(Float pointsize) { C4DOS.Br->SetPointSize(this, pointsize); }

	//----------------------------------------------------------------------------------------
	/// Sets the lighting used by the draw functions.
	/// @note This method only affects the new 3D drawing methods below it, i.e. DrawLine(), LineStrip(), DrawHandle(), DrawPoly(), DrawTexture(), DrawCircle(), DrawBox(), DrawPolygon() and DrawSphere().
	/// @param[in] mode								The lighting mode: @enumerateEnum{BDRAW_SETLIGHTLIST}
	//----------------------------------------------------------------------------------------
	void SetLightList(Int32 mode) { C4DOS.Br->SetLightList(this, mode); }
/// @addtogroup BDRAW_SETLIGHTLIST
/// @ingroup group_enumeration
/// @{
#define BDRAW_SETLIGHTLIST_NOLIGHTS			-1			///< No lights.
#define BDRAW_SETLIGHTLIST_SCENELIGHTS	0				///< Scene lights.
#define BDRAW_SETLIGHTLIST_QUICKSHADING	1				///< Quick shading.
/// @}

	/// @}

	/// @name Color Conversion
	/// @{

	//----------------------------------------------------------------------------------------
	/// Converts colors from document color to viewport color profile.
	/// @param[in] c									The color to convert (document).
	/// @return												The converted color (viewport).
	//----------------------------------------------------------------------------------------
	Vector ConvertColor(const Vector& c) { return C4DOS.Br->ConvertColor(this, c); }

	//----------------------------------------------------------------------------------------
	/// Converts colors from viewport color to document color profile.
	/// @param[in] c									The color to convert (viewport).
	/// @return												The converted color (document).
	//----------------------------------------------------------------------------------------
	Vector ConvertColorReverse(const Vector& c) { return C4DOS.Br->ConvertColorReverse(this, c); }

	/// @}

	/// @name Z-Buffer/Depth Setup
	/// @{

	//----------------------------------------------------------------------------------------
	/// Sets the current Z buffer offset. Use this to for example draw lines over shaded polygons in front of the screen.\n
	/// A higher offset value means a higher draw priority in the Z-buffer. For example:
	/// - shaded polygon (level 0)
	/// - unselected edges (level 2)
	/// - selected edges (level 4)
	///
	/// @note This method only affects the new 3D drawing methods below it, i.e. DrawLine(), LineStrip(), DrawHandle(), DrawPoly(), DrawTexture(), DrawCircle(), DrawBox(), DrawPolygon() and DrawSphere().
	/// @param[in] offset							The new Z-buffer offset.
	//----------------------------------------------------------------------------------------
	void LineZOffset(Int32 offset) { C4DOS.Br->LineZOffset(this, offset); }

	//----------------------------------------------------------------------------------------
	/// Enables/disables writing to the depth buffer.
	/// @markPrivate
	/// @param[in] enable							@trueIfOtherwiseFalse{the depth buffer should be enabled for writing}
	//----------------------------------------------------------------------------------------
	void SetDepth(Bool enable) { C4DOS.Br->SetDepth(this, enable); }

	/// @}

	/// @name Matrix Transform
	/// @{

	//-------------------------------------------------------------------------------------------------
	/// @markInternal
	//-------------------------------------------------------------------------------------------------
	void SetMatrix_Projection() { C4DOS.Br->SetMatrix_Projection(this); }

	//-------------------------------------------------------------------------------------------------
	/// Sets the transformation matrix to screen coordinates, i.e. from <i>(0, 0)</i> to <i>(width, height)</i>.
	/// @note This method only affects the new 3D drawing methods below it, i.e. DrawLine(), LineStrip(), DrawHandle(), DrawPoly(), DrawTexture(), DrawCircle(), DrawBox(), DrawPolygon() and DrawSphere().
	//-------------------------------------------------------------------------------------------------
	void SetMatrix_Screen() { C4DOS.Br->SetMatrix_Screen(this); }

	//----------------------------------------------------------------------------------------
	/// Sets the transformation matrix to screen coordinates, i.e. from (0, 0) to (width, height).
	/// @note This method only affects the new 3D drawing methods below it, i.e. DrawLine(), LineStrip(), DrawHandle(), DrawPoly(), DrawTexture(), DrawCircle(), DrawBox(), DrawPolygon() and DrawSphere().
	/// @param[in] zoffset						Sets the current Z buffer offset. Use this to for example draw lines over shaded polygons in front of the screen.\n
	/// 															A higher @formatParam{zoffset} value means a higher draw priority in the Z buffer. For example:
	/// 															- shaded polygon (level @em 0)
	/// 															- unselected edges (level @em 2)
	/// 															- selected edges (level @em 4)
	//----------------------------------------------------------------------------------------
	void SetMatrix_Screen(Int32 zoffset) { C4DOS.Br->SetMatrix_ScreenO(this, zoffset); }

	//-------------------------------------------------------------------------------------------------
	/// @markPrivate
	//-------------------------------------------------------------------------------------------------
	void SetMatrix_Screen(Int32 zoffset, const Matrix4d* m) { C4DOS.Br->SetMatrix_ScreenOM(this, zoffset, m); }

	//-------------------------------------------------------------------------------------------------
	/// Sets the transformation matrix to the camera system.
	/// @note This method only affects the new 3D drawing methods below it, i.e. DrawLine(), LineStrip(), DrawHandle(), DrawPoly(), DrawTexture(), DrawCircle(), DrawBox(), DrawPolygon() and DrawSphere().
	//-------------------------------------------------------------------------------------------------
	void SetMatrix_Camera() { C4DOS.Br->SetMatrix_Camera(this); }

	//----------------------------------------------------------------------------------------
	/// Sets the transformation matrix to the given matrix @formatParam{mg}.\n
	/// The transformation matrix should transform coordinates passed to the draw functions into world coordinates.\n
	/// For example for an object generator with local handle vectors the global matrix, or even better the matrix returned by BaseDrawHelp::GetMg(), should be used.\n
	/// In case of a particle system, which calculates all its particles in global space, a unit matrix can be passed because the vectors are already in global space. Basically the matrix that transforms the vectors into global space should be passed.
	/// @note This method only affects the new 3D drawing methods below it, i.e. DrawLine(), LineStrip(), DrawHandle(), DrawPoly(), DrawTexture(), DrawCircle(), DrawBox(), DrawPolygon() and DrawSphere().
	/// @param[in] op									A scene object or @formatConstant{nullptr}. If an object pointer is passed this is used to compare with an internal pointer to the last passed object pointer.\n
	/// 															If the pointers differ no matrix comparison is required internally. Used for performance reasons. @callerOwnsPointed{object}
	/// @param[in] mg									The new transformation matrix.
	//----------------------------------------------------------------------------------------
	void SetMatrix_Matrix(BaseObject* op, const Matrix& mg) { C4DOS.Br->SetMatrix_Matrix(this, op, mg); }

	//----------------------------------------------------------------------------------------
	/// Sets the transformation matrix to the given matrix @formatParam{mg}.\n
	/// The transformation matrix should transform coordinates passed to the draw functions into world coordinates.\n
	/// For example for an object generator with local handle vectors the global matrix, or even better the matrix returned by BaseDrawHelp::GetMg(), should be used.\n
	/// In case of a particle system, which calculates all its particles in global space, a unit matrix can be passed because the vectors are already in global space. Basically the matrix that transforms the vectors into global space should be passed.
	/// @note This method only affects the new 3D drawing methods below it, i.e. DrawLine(), LineStrip(), DrawHandle(), DrawPoly(), DrawTexture(), DrawCircle(), DrawBox(), DrawPolygon() and DrawSphere().
	/// @param[in] op									A scene object or @formatConstant{nullptr}. If an object pointer is passed this is used to compare with an internal pointer to the last passed object pointer.\n
	/// 															If the pointers differ no matrix comparison is required internally. Used for performance reasons. @callerOwnsPointed{object}
	/// @param[in] mg									The new transformation matrix.
	/// @param[in] zoffset						Sets the current Z buffer offset. Use this to for example draw lines over shaded polygons in front of the screen.\n
	/// 															A higher @formatParam{zoffset} value means a higher draw priority in the Z buffer. For example:
	/// 															- shaded polygon (level @em 0)
	/// 															- unselected edges (level @em 2)
	/// 															- selected edges (level @em 4)
	//----------------------------------------------------------------------------------------
	void SetMatrix_Matrix(BaseObject* op, const Matrix& mg, Int32 zoffset) { C4DOS.Br->SetMatrix_MatrixO(this, op, mg, zoffset); }

	/// @}

/// @addtogroup NOCLIP
/// @ingroup group_enumeration
/// @{
#define NOCLIP_D	1			///< Clip against the view border.
#define NOCLIP_Z	2			///< Z clipping.
/// @}

	/// @name 2D Drawing
	/// @{

	//----------------------------------------------------------------------------------------
	/// Draws a one-pixel point in the current pen color at @formatParam{p}.
	/// @note Changes the matrix to screen with SetMatrix_Screen() prior to drawing.
	/// @param[in] p									A point in screen space coordinate.
	//----------------------------------------------------------------------------------------
	void DrawPoint2D(const Vector& p) { C4DOS.Br->DrawPoint2D(this, p); }

	//----------------------------------------------------------------------------------------
	/// Draws a line in the current pen color between @formatParam{p1} and @formatParam{p2}.
	/// @note Changes the matrix to screen with SetMatrix_Screen() prior to drawing.
	/// @param[in] p1									The start point of the line in screen space coordinate.
	/// @param[in] p2									The end point of the line in screen space coordinate.
	//----------------------------------------------------------------------------------------
	void DrawLine2D(const Vector& p1, const Vector& p2) { C4DOS.Br->DrawLine2D(this, p1, p2); }

	//----------------------------------------------------------------------------------------
	/// Draws a handle at @formatParam{p}.
	/// @note Changes the matrix to screen with SetMatrix_Screen() prior to drawing.
	/// @param[in] p									A point in screen space coordinate.
	/// @param[in] type								The handle type: @enumerateEnum{DRAWHANDLE}
	//----------------------------------------------------------------------------------------
	void DrawHandle2D(const Vector& p, DRAWHANDLE type = DRAWHANDLE::SMALL) { C4DOS.Br->DrawHandle2D(this, p, type); }

	//----------------------------------------------------------------------------------------
	/// Draws a circle in the current pen color with a radius of @formatParam{rad} and the center at (@formatParam{mx}, @formatParam{my}).
	/// @note Changes the matrix to screen with SetMatrix_Screen() prior to drawing.
	/// @param[in] mx									The X coordinate of the circle's center in screen space coordinate.
	/// @param[in] my									The Y coordinate of the circle's center in screen space coordinate.
	/// @param[in] rad								The circle's radius.
	//----------------------------------------------------------------------------------------
	void DrawCircle2D(Int32 mx, Int32 my, Float rad) { C4DOS.Br->DrawCircle2D(this, mx, my, rad); }

	/// @}

	/// @name 3D Drawing
	/// @{

	//----------------------------------------------------------------------------------------
	/// Draws a handle at @formatParam{vp}.
	/// @param[in] vp									A point. The coordinate must be in the space defined by SetMatrix_Screen(), SetMatrix_Camera() or SetMatrix_Matrix().
	/// @param[in] type								The handle type: @enumerateEnum{DRAWHANDLE}
	/// @param[in] flags							The clipping flags: @ref NOCLIP_D or @ref NOCLIP_Z.
	//----------------------------------------------------------------------------------------
	void DrawHandle(const Vector& vp, DRAWHANDLE type, Int32 flags) { C4DOS.Br->DrawHandle(this, vp, type, flags); }

	//----------------------------------------------------------------------------------------
	/// Draws an array of points with individual colors.
	/// @note The coordinates must be in the space defined by SetMatrix_Screen(), SetMatrix_Camera() or SetMatrix_Matrix().
	/// @param[in] cnt								The number of points.
	/// @param[in] vp									An array of point coordinates. @callerOwnsPointed{array}
	/// @param[in] vc									An array of point color elements. @callerOwnsPointed{array}
	/// @param[in] colcnt							The number of color elements, for example @em 3 for RGB.
	/// @param[in] vn									Reserved for future use. @callerOwnsPointed{array}
	//----------------------------------------------------------------------------------------
	void DrawPointArray(Int32 cnt, const Vector32* vp, const Float32* vc = nullptr, Int32 colcnt = 0, const Vector32* vn = nullptr) { C4DOS.Br->DrawPointArray(this, cnt, vp, vc, colcnt, vn); }

	//----------------------------------------------------------------------------------------
	/// Draws a line in the current pen color between @formatParam{p1} and @formatParam{p2}.
	/// @param[in] p1									The start point in world space coordinate.
	/// @param[in] p2									The end point in world space coordinate.
	/// @param[in] flags							The clipping flags: @ref NOCLIP_D or @ref NOCLIP_Z.
	//----------------------------------------------------------------------------------------
	void DrawLine(const Vector& p1, const Vector& p2, Int32 flags) { C4DOS.Br->DrawLine(this, p1, p2, flags); }

	//----------------------------------------------------------------------------------------
	/// Draws an arc (section of a circle) in the current pen color at @formatParam{pos}.
	/// @param[in] pos								The position of the rectangle that defines the arc. The coordinate must be in screen space.
	/// @param[in] radius							The arc's radius.
	/// @param[in] angle_start				The start of the angle in radians.
	/// @param[in] angle_end					The end of the angle in radians.
	/// @param[in] subdiv							The range between @formatParam{angle_start} and @formatParam{angle_end} is divided into @formatParam{subdiv} line segments.
	/// @param[in] flags							The clipping flags: @ref NOCLIP_D or @ref NOCLIP_Z.
	//----------------------------------------------------------------------------------------
	void DrawArc(const Vector& pos, Float radius, Float angle_start, Float angle_end, Int32 subdiv = 32, Int32 flags = 0) { C4DOS.Br->DrawArc(this, pos, radius, angle_start, angle_end, subdiv, flags); }

	//----------------------------------------------------------------------------------------
	/// Draws a colored and shaded polygon using the points in @formatParam{vp}, the colors in @formatParam{vf} and the normals in @formatParam{vn}.\n
	/// Only triangles and quadrangles are accepted. The colors are interpolated between the points. The shading is determined by SetLightList().
	/// @note The coordinates must be in the space defined by SetMatrix_Screen(), SetMatrix_Camera() or SetMatrix_Matrix().
	/// @param[in] vp									An array of point coordinates. @callerOwnsPointed{array}
	/// @param[in] vf									An array of point colors. @callerOwnsPointed{array}
	/// @param[in] vn									An array of point normals. @callerOwnsPointed{array}
	/// @param[in] anz								The number of points. Must be either @em 3 (for triangles) or @em 4 (for quadrangles).
	/// @param[in] flags							The clipping flags: @ref NOCLIP_D or @ref NOCLIP_Z.
	//----------------------------------------------------------------------------------------
	void DrawPoly(const Vector* vp, const Vector* vf, const Vector* vn, Int32 anz, Int32 flags) { C4DOS.Br->DrawPoly(this, vp, vf, vn, anz, flags); }

	//----------------------------------------------------------------------------------------
	/// Draws a colored and shaded texture polygon using the points in @formatParam{padr4}, the colors in @formatParam{cadr}, the normals in @formatParam{vnadr} and the UV coordinates in @formatParam{uvadr}.\n
	/// Only triangles and quadrangles are accepted. The colors are interpolated between the points and mutiplied with the texture color. The shading is determined by SetLightList().
	/// @param[in] bmp								The texture to draw. @callerOwnsPointed{bitmap}
	/// @param[in] padr4							An array of point coordinates. The coordinates must be in the space defined by SetMatrix_Screen(), SetMatrix_Camera() or SetMatrix_Matrix().
	/// @param[in] cadr								An array of colors. Must have @em 4 items regardless of @formatParam{pntcnt}.
	/// @param[in] vnadr							An array of point normals. Must have @em 4 items regardless of @formatParam{pntcnt}.
	/// @param[in] uvadr							An array of UV coordinates. Must have @em 4 items regardless of @formatParam{pntcnt}.
	/// @param[in] pntcnt							The number of points in @formatParam{padr4}. Must be either @em 3 (triangle) or @em 4 (quadrangle).
	/// @param[in] alphamode					The alpha channel mode: @enumerateEnum{DRAW_ALPHA}
	/// @param[in] flags							A combination of these flags: @enumerateEnum{DRAW_TEXTUREFLAGS}
	//----------------------------------------------------------------------------------------
	void DrawTexture(const BaseBitmap* bmp, const Vector* padr4, const Vector* cadr, const Vector* vnadr, const Vector* uvadr, Int32 pntcnt, DRAW_ALPHA alphamode, DRAW_TEXTUREFLAGS flags) { C4DOS.Br->DrawTexture(this, bmp, padr4, cadr, vnadr, uvadr, pntcnt, alphamode, flags); }

	//----------------------------------------------------------------------------------------
	/// Draws a colored and shaded texture polygon using the points in @formatParam{padr4}, the colors in @formatParam{cadr}, the normals in @formatParam{vnadr} and the UV coordinates in @formatParam{uvadr}.\n
	/// Only triangles and quadrangles are accepted. The colors are interpolated between the points and mutiplied with the texture color. The shading is determined by SetLightList().
	/// @param[in] bmp								A handle to an OpenGL bitmap. @extOpenGlMode
	/// @param[in] padr4							An array of point coordinates. The coordinates must be in the space defined by SetMatrix_Screen(), SetMatrix_Camera() or SetMatrix_Matrix().
	/// @param[in] cadr								An array of colors. Must have @em 4 items regardless of @formatParam{pntcnt}.
	/// @param[in] vnadr							An array of point normals. Must have @em 4 items regardless of @formatParam{pntcnt}.
	/// @param[in] uvadr							An array of UV coordinates. Must have @em 4 items regardless of @formatParam{pntcnt}.
	/// @param[in] pntcnt							The number of points in @formatParam{padr4}. Must be either @em 3 (triangle) or @em 4 (quadrangle).
	/// @param[in] alphamode					The alpha channel mode: @enumerateEnum{DRAW_ALPHA}
	//----------------------------------------------------------------------------------------
	void DrawTexture(C4DGLuint bmp, Vector* padr4, Vector* cadr, Vector* vnadr, Vector* uvadr, Int32 pntcnt, DRAW_ALPHA alphamode) { C4DOS.Br->DrawTexture1(this, bmp, padr4, cadr, vnadr, uvadr, pntcnt, alphamode); }

	//----------------------------------------------------------------------------------------
	/// Draws an ellipse in the current pen color. The ellipse is specified by the matrix @formatParam{m}, where @formatParam{m}.v1 and @formatParam{m}.v2 are the axis vectors and @formatParam{m}.off is the center position. (@formatParam{m}.v3 is not used.)
	/// @param[in] m									A matrix describing the ellipse. The coordinates must be in the space defined by SetMatrix_Screen(), SetMatrix_Camera() or SetMatrix_Matrix().
	//----------------------------------------------------------------------------------------
	void DrawCircle(const Matrix& m) { C4DOS.Br->DrawCircle(this, m); }

	//----------------------------------------------------------------------------------------
	/// Draws a box. The eight points of the box are defined as:
	/// @code
	/// p[0] = m * Vector(-size, -size, -size);
	/// p[1] = m * Vector( size, -size, -size);
	/// p[2] = m * Vector( size, -size,  size);
	/// p[3] = m * Vector(-size, -size,  size);
	/// p[4] = m * Vector(-size,  size, -size);
	/// p[5] = m * Vector( size,  size, -size);
	/// p[6] = m * Vector( size,  size,  size);
	/// p[7] = m * Vector(-size,  size,  size);
	/// @endcode
	/// @note To get arbitrary cubic forms, set size to 0.5 and multiply the vectors in the matrix by the length.
	/// @param[in] m									A matrix describing the box. The coordinates must be in the space defined by SetMatrix_Screen(), SetMatrix_Camera() or SetMatrix_Matrix().
	/// @param[in] size								The size of the box.
	/// @param[in] col								The color of the box.
	/// @param[in] wire								If @formatConstant{true} the box is drawn as wireframe.
	//----------------------------------------------------------------------------------------
	void DrawBox(const Matrix& m, Float size, const Vector& col, Bool wire) { C4DOS.Br->DrawBox(this, m, size, col, wire); }

	//----------------------------------------------------------------------------------------
	/// Draws the bounding box of given BaseObject (op).
	/// @param[in] op									BaseObject used to extract the bounding box.
	/// @param[in] mg									Global Matrix for the BoundingBox (may differ from op)
	/// @param[in] bh									The base draw help. @callerOwnsPointed{base draw help}.
	/// @param[in] shading						If @formatConstant{true} the shader is applied
	/// @param[in] colorOverride			Use specified color. If null, object color is used.
	//----------------------------------------------------------------------------------------
	void DrawBoundingBox(BaseObject* op, const Matrix& mg, BaseDrawHelp* bh, Bool shading, Vector* colorOverride = nullptr) { C4DOS.Br->DrawBoundingBox(*this, op, mg, bh, shading, colorOverride); }

	//----------------------------------------------------------------------------------------
	/// Draws a manually shaded triangle or quadrangle.\n
	/// The corner points are given as an array of vectors in @formatParam{p}, and the corner colors as a corresponding array of Vectors in @formatParam{f}. If quad is @formatConstant{false} there should be @em 3 elements in each array, otherwise @em 4. The colors are interpolated between the corners.
	/// @param[in] p									An array of point coordinates. @callerOwnsPointed{array} The points coordinates must be in the space defined by SetMatrix_Screen(), SetMatrix_Camera() or SetMatrix_Matrix().
	/// @param[in] f									An array of point colors. @callerOwnsPointed{array}
	/// @param[in] quad								If @formatConstant{true} the number of points must be @em 4, otherwise it must be @em 3.
	//----------------------------------------------------------------------------------------
	void DrawPolygon(const Vector* p, const Vector* f, Bool quad) { C4DOS.Br->DrawPolygon(this, p, f, quad); }

	//----------------------------------------------------------------------------------------
	/// Draws a sphere at position @formatParam{off} of size specified by the @formatParam{size} vector in each direction and color specified by @formatParam{col}.
	/// @param[in] off								The position of the sphere. The point coordinate must be in the space defined by SetMatrix_Screen(), SetMatrix_Camera() or SetMatrix_Matrix().
	/// @param[in] size								The size of the sphere.
	/// @param[in] col								The color of the sphere.
	/// @param[in] flags							The flags: @ref NOCLIP_D or @ref NOCLIP_Z and/or @ref BDRAW_DRAW_SPHERE_FLAGS_NO_SHADING.
	//----------------------------------------------------------------------------------------
	void DrawSphere(const Vector& off, const Vector& size, const Vector& col, Int32 flags) { C4DOS.Br->DrawSphere(this, off, size, col, flags); }
#define BDRAW_DRAW_SPHERE_FLAGS_NO_SHADING 1 ///< If set for DrawSphere(), the sphere will not be shaded, it will be drawn with the specified color.

	//-------------------------------------------------------------------------------------------------
	/// Each DrawPolygon() puts the polygon into an internal array and draws the polygons when the array is full or an OpenGL state changes (e.g. the matrix). DrawArrayEnd() forces this operation.
	//-------------------------------------------------------------------------------------------------
	void DrawArrayEnd() { C4DOS.Br->DrawArrayEnd(this); }

	/// @}

	/// @name Object Drawing
	/// @{

	//----------------------------------------------------------------------------------------
	/// Draws the polygon object @formatParam{op}.
	/// @param[in] bh									The base draw help. @callerOwnsPointed{base draw help}
	/// @param[in] op									The polygon object to draw. @callerOwnsPointed{object}
	/// @param[in] flags							The flags: @enumerateEnum{DRAWOBJECT}
	/// @param[in] parent							This is used for the viewport filter.\n
	/// 															Take the Floor object for example, it displays a polygon object in the viewport. If parent is set to @formatConstant{nullptr} the drawn polygon is considered by the viewport filter.\n
	/// 															If the Floor object has been passed to parent the Floor object is considered by the viewport filter instead.
	/// @param[in] col								The object's color.
	/// @return												The result of drawing the polygon object: @enumerateEnum{DRAWRESULT}
	//----------------------------------------------------------------------------------------
	DRAWRESULT DrawPolygonObject(BaseDrawHelp* bh, BaseObject* op, DRAWOBJECT flags, BaseObject* parent = nullptr, const Vector& col = Vector(.5)) { return C4DOS.Br->DrawPObject(this, bh, op, flags, DRAWPASS::OBJECT, parent, col); }

	//----------------------------------------------------------------------------------------
	/// Draws the object @formatParam{op}.
	/// @param[in] bh									The base draw help. @callerOwnsPointed{base draw help}
	/// @param[in] op									The object to draw. @callerOwnsPointed{object}
	/// @param[in] flags							The flags: @enumerateEnum{DRAWOBJECT}
	/// @param[in] drawpass						The draw pass: @enumerateEnum{DRAWPASS}
	/// @param[in] parent							This is used for the viewport filter.\n
	/// 															Take the Floor object for example, it displays a polygon object in the viewport. If parent is set to @formatConstant{nullptr} the drawn polygon is considered by the viewport filter.\n
	/// 															If the Floor object has been passed to parent the Floor object is considered by the viewport filter instead.
	/// @param[in] col								The object's color.
	/// @return												The result of drawing the object: @enumerateEnum{DRAWRESULT}
	//----------------------------------------------------------------------------------------
	DRAWRESULT DrawObject(BaseDrawHelp* bh, BaseObject* op, DRAWOBJECT flags, DRAWPASS drawpass, BaseObject* parent = nullptr, const Vector& col = Vector(.5)) { return C4DOS.Br->DrawPObject(this, bh, op, flags | DRAWOBJECT::PRIVATE_ANY, drawpass, parent, col); }

	//----------------------------------------------------------------------------------------
	/// Draws a scene into the framebuffer.
	/// @param[in] flags							Not used.
	/// @return												@trueIfOtherwiseFalse{the scene was drawn successfully}
	//----------------------------------------------------------------------------------------
	Bool DrawScene(Int32 flags) { return C4DOS.Br->DrawScene(this, flags); }

	//----------------------------------------------------------------------------------------
	/// @markPrivate
	/// @since R19
	//----------------------------------------------------------------------------------------
	Bool DrawHighlight(BASEDRAW_HIGHLIGHT flags) { return C4DOS.Br->DrawHighlight(this, flags); }

	/// @}

	/// @name Line Strip Drawing
	/// @{

	//-------------------------------------------------------------------------------------------------
	/// Starts a new colored line strip.\n
	/// Draw several line strip segments with LineStrip() calls and then finish the line strip with LineStripEnd().
	//-------------------------------------------------------------------------------------------------
	void LineStripBegin() { C4DOS.Br->LineStripBegin(this); }

	//-------------------------------------------------------------------------------------------------
	/// Finishes line strips started with LineStripBegin().
	//-------------------------------------------------------------------------------------------------
	void LineStripEnd() { C4DOS.Br->LineStripEnd(this); }

	//----------------------------------------------------------------------------------------
	/// Draws a line strip from the point @formatParam{vp} of the last call to LineStrip() to the current @formatParam{vp}. The line strip is colored with a gradient from the last @formatParam{vc} to the new @formatParam{vc}.
	/// @warning This method must be enclosed between LineStripBegin() and LineStripEnd() calls.
	/// @param[in] vp									The point coordinate. The coordinate must be in the space defined by SetMatrix_Screen(), SetMatrix_Camera() or SetMatrix_Matrix().
	/// @param[in] vc									The point color.
	/// @param[in] flags							The clipping flags: @ref NOCLIP_D or @ref NOCLIP_Z.
	//----------------------------------------------------------------------------------------
	void LineStrip(const Vector& vp, const Vector& vc, Int32 flags) { C4DOS.Br->LineStrip(this, vp, vc, flags); }

	/// @}

	/// @name Polyline Drawing
	/// @{

	//----------------------------------------------------------------------------------------
	/// @markDeprecated
	/// Initializes the view to draw XOR poly line (set the correct projection matrices).
	/// @see Example in DrawXORPolyLine()
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool InitDrawXORPolyLine() { return C4DOS.Br->InitDrawXORLine(this); }

	//-------------------------------------------------------------------------------------------------
	/// @markDeprecated
	/// Frees drawing XOR poly line (restore the old projection matrices).
	// @see Example in DrawXORPolyLine()
	//-------------------------------------------------------------------------------------------------
	void FreeDrawXORPolyLine() { C4DOS.Br->FreeDrawXORLine(this); }

	//----------------------------------------------------------------------------------------
	/// @markDeprecated
	/// Draws a XOR poly line.
	/// @b Example:
	/// @code
	/// Int32 count = 2;
	///
	/// Float32* p = nullptr;
	/// points = (Float*)NewMemClear(2*count*sizeof(Float));
	/// if (p==nullptr)
	/// 	return false;
	///
	/// p[2*0+0] = 0.f;
	/// p[2*0+1] = 0.f;
	/// p[2*1+0] = 100.f;
	/// p[2*1+1] = 100.f;
	///
	/// bd->InitDrawXORPolyLine();
	/// bd->BeginDrawXORPolyLine();
	/// bd->DrawXORPolyLine(points, count);
	/// bd->EndDrawXORPolyLine(false);
	/// bd->FreeDrawXORPolyLine();
	///
	/// DeleteMem(p);
	/// @endcode
	/// @param[in] p									The pointer to the line points array. The format of the array is <i>2*cnt*sizeof(Float32)</i> (2 Float32 per point).
	/// @param[in] cnt								The number of line points.
	//----------------------------------------------------------------------------------------
	void DrawXORPolyLine(const Float32* p, Int32 cnt) { C4DOS.Br->DrawXORPolyLine(this, p, cnt); }

	//-------------------------------------------------------------------------------------------------
	/// @markDeprecated
	/// Begins drawing an XOR poly line (sets the view's context as current context).
	/// @see Example in DrawXORPolyLine().
	//-------------------------------------------------------------------------------------------------
	void BeginDrawXORPolyLine() { C4DOS.Br->BeginDrawXORPolyLine(this); }

	//----------------------------------------------------------------------------------------
	/// @markDeprecated
	/// Ends the drawing of a XOR poly line (makes @formatConstant{nullptr} the current context).
	/// @see Example in DrawXORPolyLine().
	/// @param[in] blit								Set to @formatConstant{true} to use blitting.
	//----------------------------------------------------------------------------------------
	void EndDrawXORPolyLine(Bool blit) { C4DOS.Br->EndDrawXORPolyLine(this, blit); }

	/// @}

	/// @name Highlight Pass
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets the color in which the object is to draw in the highlight pass.\n
	/// If the object is selected or highlighted the function returns @formatConstant{true} and the color is returned in @formatParam{col}.
	/// @note This function should only be called in the highlight pass.
	/// @param[in] bh									The base draw help.
	/// @param[in] lineObject					Must be set to @formatConstant{true}, if the object is a line object.
	/// @param[in] col								Assigned the highlight color.
	/// @return												@formatConstant{true} if the object is selected or highlighted and the color @formatParam{col} is assigned.\n
	/// 															@formatConstant{false} if drawing the object can be skipped.
	//----------------------------------------------------------------------------------------
	Bool GetHighlightPassColor(const BaseDrawHelp& bh, Bool lineObject, Vector& col) const { return C4DOS.Br->GetHighlightPassColor(this, bh, lineObject, col); }

	//----------------------------------------------------------------------------------------
	/// Gets the framebuffer in which the highlights are drawn and sets the bounding box of the highlight area (@formatParam{vMin} and @formatParam{vMax}).\n
	/// Both vectors must be in clip space [-1, 1] on all axes. They should be passed when the bounding box is known for the current object to speed up the calculation of the highlights and outlines.
	/// @markPrivate
	/// @param[in] vMin								The minimum position of the bounding box.
	/// @param[in] vMax								The maximum position of the bounding box.
	/// @return												The highlight framebuffer.
	//----------------------------------------------------------------------------------------
	GlFrameBuffer* GetHighlightFramebuffer(const Vector32& vMin = Vector32(-1.0f), const Vector32& vMax = Vector32(1.0f)) { return C4DOS.Br->GetHighlightFramebuffer(this, vMin, vMax); }

	/// @}

	/// @name View Undo
	/// @{

	//----------------------------------------------------------------------------------------
	/// Call before a change is made to the view to add the old setting to the undo buffer for the view. (This undo buffer is separate from the normal undo buffer.)
	/// @param[in] doc								The view's document. @callerOwnsPointed{document}
	//----------------------------------------------------------------------------------------
	void InitUndo(BaseDocument* doc) { C4DOS.Br->InitUndo(this, doc); }

	//----------------------------------------------------------------------------------------
	/// Performs an undo operation in the view. This is the same as the user selecting <i>Undo View</i> from within @C4D.
	/// @param[in] doc								The view's document. @callerOwnsPointed{document}
	//----------------------------------------------------------------------------------------
	void DoUndo(BaseDocument* doc) { C4DOS.Br->DoUndo(this, doc); }

	/// @}

	/// @name Draw Parameters
	/// @{

	//----------------------------------------------------------------------------------------
	/// Sets draw parameters.
	/// @note This method only affects the new 3D drawing methods below it, i.e. DrawLine(), LineStrip(), DrawHandle(), DrawPoly(), DrawTexture(), DrawCircle(), DrawBox(), DrawPolygon() and DrawSphere().
	/// @param[in] id									The draw parameter ID: @enumerateEnum{DRAW_PARAMETER}
	/// @param[in] data								The new draw parameter data to set.
	//----------------------------------------------------------------------------------------
	void SetDrawParam(Int32 id, const GeData& data) { C4DOS.Br->SetDrawParam(this, id, data); }

	//----------------------------------------------------------------------------------------
	/// Gets draw parameters.
	/// @note This method only affects the new 3D drawing methods below it, i.e. DrawLine(), LineStrip(), DrawHandle(), DrawPoly(), DrawTexture(), DrawCircle(), DrawBox(), DrawPolygon() and DrawSphere().
	/// @param[in] id									The draw parameter ID: @enumerateEnum{DRAW_PARAMETER}
	/// @return												The draw parameter data.
	//----------------------------------------------------------------------------------------
	GeData GetDrawParam(Int32 id) const { return C4DOS.Br->GetDrawParam(this, id); }

/// @addtogroup DRAW_PARAMETER
/// @ingroup group_containerid
/// @{
#define DRAW_PARAMETER_LINEWIDTH									1000			///< ::Float Line width in pixels. (OpenGL only.)
#define DRAW_PARAMETER_ALPHA_THRESHOLD						1002			///< ::Float Alpha threshold between @em 0.0 - @em 1.0. (Make sure to set old value back afterwards!)
#define DRAW_PARAMETER_SETZ												2					///< ::Int32 The Z buffer mode: @enumerateEnum{DRAW_Z}
#define DRAW_PARAMETER_OGL_CULLING								10				///< ::Int32 OpenGL culling: @enumerateEnum{DRAW_PARAMETER_OGL_CULLING}
#define DRAW_PARAMETER_USE_Z											11				///< ::Bool Use Z.
#define DRAW_PARAMETER_OGL_PRIMITIVERESTARTINDEX	14				///< ::UInt16 OpenGL primitive start index.
/// @}

/// @addtogroup DRAW_Z
/// @ingroup group_enumeration
/// @{
#define DRAW_Z_LOWEREQUAL	0			///< Draws the fragment if its Z value is <= then the Z-buffers fragments Z value.
#define DRAW_Z_GREATER		1			///< Draws the fragment if its Z value is > then the Z-buffers fragments Z value.
#define DRAW_Z_ALWAYS			2			///< Always draws a fragment.
#define DRAW_Z_EQUAL			3			///< Draws the fragment if its Z value equals the Z-buffers fragments Z value.
#define DRAW_Z_LOWER			4			///< Draws the fragment if its Z value is < then the Z-buffers fragments Z value.
/// @}

/// @addtogroup DRAW_PARAMETER_OGL_CULLING
/// @ingroup group_enumeration
/// @{
#define DRAW_PARAMETER_OGL_CULLING_OFF						0			///< OpenGL culling Off.
#define DRAW_PARAMETER_OGL_CULLING_FRONT					1			///< OpenGL front culling.
#define DRAW_PARAMETER_OGL_CULLING_BACK						2			///< OpenGL back culling.
#define DRAW_PARAMETER_OGL_CULLING_FRONT_AND_BACK	3			///< OpenGL front and back culling.
/// @}

/// @addtogroup DRAWPORT_TYPE
/// @ingroup group_enumeration
/// @{
/// Use with @ref BASEDRAW_DRAWPORTTYPE.
#define DRAWPORT_TYPE_OGL_HQ		2			///< Enhanced OpenGL.
/// @}

	/// @}

	/// @name Miscellaneous
	/// @{

	//----------------------------------------------------------------------------------------
	/// Adds a message hook to the base draw.\n
	/// This hook is called when the user chooses 'Adapt View', changes the scene camera or if the base draw is deleted.
	/// @markPrivate
	/// @param[in] fn									The message hook.
	//----------------------------------------------------------------------------------------
	void AddMessageHook(BaseDrawMessageHook fn) { C4DOS.Br->AddMessageHook(this, fn); }

	//----------------------------------------------------------------------------------------
	/// Adds the object @formatParam{op} to @ref DRAWPASS::XRAY.\n
	/// @b Example:
	/// @code
	/// DRAWRESULT MyObject::Draw(BaseObject* op, DRAWPASS drawpass, BaseDraw* bd, BaseDrawHelp* bh)
	/// {
	/// 	if (drawpass==DRAWPASS::OBJECT)
	/// 	{
	/// 		bd->AddToPostPass(op, bh);
	/// 		ok = true;
	/// 	}
	/// 	else if (drawpass==DRAWPASS::XRAY)
	/// 	{
	/// 		....
	/// 	}
	/// }
	/// @endcode
	/// The object in this example is drawn both in the object and X-ray pass.
	/// @param[in] op									The object to add to the X-ray pass. @callerOwnsPointed{object}
	/// @param[in] bh									The base draw helper. @callerOwnsPointed{base draw helper}
	/// @return												@trueIfOtherwiseFalse{the object was successfully added to the X-ray pass}
	//----------------------------------------------------------------------------------------
	Bool AddToPostPass(BaseObject* op, BaseDrawHelp* bh) { return C4DOS.Br->AddToPostPass(this, op, bh, 0); }

	//----------------------------------------------------------------------------------------
	/// Gets the current display filter.\n
	/// This is a bit field derived from the BASEDRAW_DISPLAYFILTER_* description flags in @em dbasedraw.h. To set the display filter you have to use the description flags with @link C4DAtom::SetParameter() SetParameter()@endlink.
	/// @return												A bit field with the following flags: @enumerateEnum{DISPLAYFILTER}
	//----------------------------------------------------------------------------------------
	DISPLAYFILTER GetDisplayFilter() { return C4DOS.Br->GetDisplayFilter(this); }

	//----------------------------------------------------------------------------------------
	/// Gets the reduction mode of the base draw.
	/// @return												The reduction mode: @enumerateEnum{DISPLAYMODE}
	//----------------------------------------------------------------------------------------
	DISPLAYMODE GetReductionMode() const { return C4DOS.Br->GetReductionMode(this); }

	//----------------------------------------------------------------------------------------
	/// Gets the current drawpass.
	/// @return												The current drawpass: @enumerateEnum{DRAWPASS}
	//----------------------------------------------------------------------------------------
	DRAWPASS GetDrawPass() const { return C4DOS.Br->GetDrawPass(this); }

	//----------------------------------------------------------------------------------------
	/// Gets OpenGL geometry statistics.
	/// @param[out] bc								The container filled with the statistics: @enumerateEnum{DRAW_STATISTIC}
	/// @return												@trueIfOtherwiseFalse{statistics were returned successfully}
	//----------------------------------------------------------------------------------------
	Bool GetDrawStatistics(BaseContainer& bc) const { return C4DOS.Br->GetDrawStatistics(this, bc); }

	//----------------------------------------------------------------------------------------
	/// Gets the current edit state.\n
	/// This is a bit field derived from the edit state description flags in @em dbasedraw.res. To set the display filter you have to use the description flags with @link C4DAtom::SetParameter() SetParameter()@endlink.
	/// @return												The edit state: @enumerateEnum{DISPLAYEDITSTATE}
	//----------------------------------------------------------------------------------------
	DISPLAYEDITSTATE GetEditState() { return C4DOS.Br->GetEditState(this); }

	//----------------------------------------------------------------------------------------
	/// Gets the EditorWindow for this base draw.
	/// @return												The EditorWindow. @cinemaOwnsPointed{EditorWindow}
	//----------------------------------------------------------------------------------------
	EditorWindow* GetEditorWindow() { return C4DOS.Br->GetEditorWindow(this); }

	//----------------------------------------------------------------------------------------
	/// Gets the grid spacing and the transparency value of the minor grid that fade when the user zoom in or out with dynamic grid.
	/// @param[out] step							Is assigned the workplane grid spacing.
	/// @param[out] fade							Is assigned the transparency value of the minor grid.
	//----------------------------------------------------------------------------------------
	void GetGridStep(Float& step, Float& fade) { C4DOS.Br->GetGridStep(this, step, fade); }

	//----------------------------------------------------------------------------------------
	/// Gets the view matrix.
	/// @param[in] n									The type of view matrix to get: @enumerateEnum{DRAW_GET_VIEWMATRIX}
	/// @return												The view matrix.
	//----------------------------------------------------------------------------------------
	const Matrix4d& GetViewMatrix(Int32 n);

	//----------------------------------------------------------------------------------------
	/// Checks if a view is open. A view is open if it is anywhere in the layout, i.e. even if it is hidden as a tab or behind another window.
	/// @param[in] doc								The document for the operation. @callerOwnsPointed{document}
	/// @return												@trueIfOtherwiseFalse{a view is open}
	//----------------------------------------------------------------------------------------
	Bool IsViewOpen(BaseDocument* doc) { return C4DOS.Br->IsViewOpen(this, doc); }

	//----------------------------------------------------------------------------------------
	/// Changes the stereoscopic camera data for this view.
	/// @param[in] si									The stereoscopic camera data to set. @callerOwnsPointed{StereoCameraInfo}
	//----------------------------------------------------------------------------------------
	void OverrideCamera(StereoCameraInfo* si) { C4DOS.Bv->OverrideCamera(this, si); }

	//----------------------------------------------------------------------------------------
	/// Checks if the screen point (@formatParam{x},@formatParam{y}) is within a hit range of the world point @formatParam{p}, i.e. if the screen point is close to the world points projection on the screen.
	/// @param[in] p									A point in world space.
	/// @param[in] x									A screen X coordinate.
	/// @param[in] y									A screen Y coordinate.
	/// @return												@trueIfOtherwiseFalse{the point is within range}
	//----------------------------------------------------------------------------------------
	Bool PointInRange(const Vector& p, Int32 x, Int32 y) { return C4DOS.Br->PointInRange(this, p, x, y); }

	//----------------------------------------------------------------------------------------
	/// Offsets the OpenGL clipping planes by this offset.
	/// @param[in] o									The offset.
	//----------------------------------------------------------------------------------------
	void SetClipPlaneOffset(Float o) { C4DOS.Br->SetClipPlaneOffset(this, o); }

	//----------------------------------------------------------------------------------------
	/// Sets a texture used by the vertex buffer.
	/// @param[in] bm									The texture's bitmap. @callerOwnsPointed{bitmap}
	/// @param[in] tile								Set to @formatConstant{true} to enable tiling.
	/// @param[in] alphamode					The alpha channel mode: @enumerateEnum{DRAW_ALPHA}
	/// @param[in] flags							The draw texture flags: @enumerateEnum{DRAW_TEXTUREFLAGS}
	//----------------------------------------------------------------------------------------
	void SetTexture(BaseBitmap* bm, Bool tile, DRAW_ALPHA alphamode, DRAW_TEXTUREFLAGS flags) { return C4DOS.Br->SetTexture(this, bm, tile, alphamode, flags); }

	//----------------------------------------------------------------------------------------
	/// A quick shading algorithm that only takes the angle to the camera and a default light into account.\n
	/// A point and a normal in world space are passed and an intensity is returned.
	/// @note Can be combined with DrawPolygon() to draw simple shaded polygons.
	/// @param[in] p									A point in world space.
	/// @param[in] n									A normal in world space.
	/// @return												The intensity of the light. Between @em 0 and @em 1.
	//----------------------------------------------------------------------------------------
	Float SimpleShade(const Vector& p, const Vector& n) { return C4DOS.Br->SimpleShade(this, p, n); }

	//----------------------------------------------------------------------------------------
	/// Checks for thread breaks in the draw.
	/// @return												@trueIfOtherwiseFalse{a stopping condition has occurred}
	//----------------------------------------------------------------------------------------
	Bool TestBreak() { return C4DOS.Br->TestBreak(this); }

	/// @}

	/// @name Extended GL Mode
	/// @{

	//----------------------------------------------------------------------------------------
	/// @extOpenGlMode
	//----------------------------------------------------------------------------------------
	Bool IsOpenGL() { return C4DOS.Br->IsOpenGL(this); }

	//----------------------------------------------------------------------------------------
	/// @extOpenGlMode
	//----------------------------------------------------------------------------------------
	Bool IsEnhancedOpenGL() { return C4DOS.Br->IsEnhancedOpenGL(this); }

	//-------------------------------------------------------------------------------------------------
	/// @extOpenGlMode
	//-------------------------------------------------------------------------------------------------
	Bool DrawFullscreenPolygon(Int32 lVectorInfoCount, const GlVertexBufferVectorInfo* const* ppVectorInfo) { return C4DOS.Br->DrawFullscreenPolygon(this, lVectorInfoCount, ppVectorInfo); }

	//----------------------------------------------------------------------------------------
	/// @extOpenGlMode
	/// @return												@em -2: no OpenGL window, @em -1: off-screen view, @em 0: system error, @em 1: success.
	//----------------------------------------------------------------------------------------
	Int32 GetFrameScreen(Int32* cl, Int32* ct, Int32* cr, Int32* cb);

	//-------------------------------------------------------------------------------------------------
	/// @extOpenGlMode
	//-------------------------------------------------------------------------------------------------
	Bool GetFullscreenPolygonVectors(Int32& lAttributeCount, const GlVertexBufferAttributeInfo* const*& ppAttibuteInfo, Int32& lVectorInfoCount, const GlVertexBufferVectorInfo* const*& ppVectorInfo) { return C4DOS.Br->GetFullscreenPolygonVectors(this, lAttributeCount, ppAttibuteInfo, lVectorInfoCount, ppVectorInfo); }

	//-------------------------------------------------------------------------------------------------
	/// @extOpenGlMode
	//-------------------------------------------------------------------------------------------------
	Int32 GetGlLightCount() const { return C4DOS.Br->GetGlLightCount(this); }

	//-------------------------------------------------------------------------------------------------
	/// @extOpenGlMode
	//-------------------------------------------------------------------------------------------------
	const GlLight* GetGlLight(Int32 lIndex) const { return C4DOS.Br->GetGlLight(this, lIndex); }

	//-------------------------------------------------------------------------------------------------
	/// @extOpenGlMode
	//-------------------------------------------------------------------------------------------------
	OITInfo& GetOITInfo() { return C4DOS.Br->GetOITInfo(this); }

	/// @}

	/// @name 2D Drawing
	/// @{

	//----------------------------------------------------------------------------------------
	/// Draws text into the 2D viewport in the style of the HUD.
	/// @since R18
	/// @param[in] x									The left X coordinate to draw the text at.
	/// @param[in] y									The upper Y coordinate to draw the text at.
	/// @param[in] txt								The text to draw.
	//----------------------------------------------------------------------------------------
	void DrawHUDText(Int32 x, Int32 y, const maxon::String &txt) { return C4DOS.Br->DrawHUDText(this, x, y, txt); }

	//----------------------------------------------------------------------------------------
	/// Draws many HUD text entries at once.
	/// @since R18
	/// @param[in] texts							The array of text entries and their screen space positions to draw to the HUD.
	//----------------------------------------------------------------------------------------
	void DrawMultipleHUDText(const maxon::BaseArray<HUDTextEntry>& texts) { return C4DOS.Br->DrawMultipleHUDText(this, texts); }

	/// @}

	/// @name GPU Renderer
	/// @{

	//----------------------------------------------------------------------------------------
	/// Checks if the view is marked as GPU Renderer.
	/// @since R19
	/// @return												@trueIfOtherwiseFalse{the view is marked to run the GPU Renderer}
	//----------------------------------------------------------------------------------------
	Bool IsMarkedAsGPURenderer() { return C4DOS.Br->IsMarkedAsGPURenderer(this); }

	//----------------------------------------------------------------------------------------
	/// Checks if the view is running the GPU Renderer.
	/// @since R19
	/// @return												@trueIfOtherwiseFalse{the view is running the GPU renderer}
	//----------------------------------------------------------------------------------------
	Bool IsGPURenderer() { return C4DOS.Br->IsGPURenderer(this); }

	//----------------------------------------------------------------------------------------
	/// Returns true if the basedraw is marked as the CPU Renderer.
	/// @since R21
	/// @return												@trueIfOtherwiseFalse{The basedraw is marked to run the CPU Renderer.}
	//----------------------------------------------------------------------------------------
	Bool IsMarkedAsCPURenderer() { return C4DOS.Br->IsMarkedAsCPURenderer(this); }
	
	//----------------------------------------------------------------------------------------
	/// Returns true if the basedraw is running the CPU Renderer.
	/// @since R21
	/// @return												@trueIfOtherwiseFalse{The basedraw is running the CPU renderer.}
	//----------------------------------------------------------------------------------------
	Bool IsCPURenderer() { return C4DOS.Br->IsCPURenderer(this); }
	
	//----------------------------------------------------------------------------------------
	/// @markPrivate
	/// @since R19
	//----------------------------------------------------------------------------------------
	void SetViewportRender(const maxon::Id& id) { return C4DOS.Br->SetViewportRender(this, id); }

	//----------------------------------------------------------------------------------------
	/// @markPrivate
	/// @since R19
	//----------------------------------------------------------------------------------------
	void FrameFinished() { return C4DOS.Br->FrameFinished(this); }

	/// @}

};


//-------------------------------------------------------------------------------------------------
/// This class contains information about objects at a pixel in the viewport.\n
/// The information for each pixel is stored in a linked list, which you can traverse with ViewportPixel::next. Use ViewportSelect to calculate the list.
//-------------------------------------------------------------------------------------------------
struct ViewportPixel
{
	BaseObject* op;									///< The object.
	Float z;												///< The Z coordinate of the current element.
	Int32 i;												///< The element index (may be point, polygon, edge (4*polygon+edge) or spline point (segment offset + point)).
	const ViewportPixel* next;			///< The pointer to the next element, or @formatConstant{nullptr} if this is the last element for the pixel.
};


/// @addtogroup VIEWPORT_CLEAR
/// @ingroup group_enumeration
/// @{
#define VIEWPORT_CLEAR_POINT		1			///< Clear points.
#define VIEWPORT_CLEAR_POLYGON	2			///< Clear polygons.
#define VIEWPORT_CLEAR_EDGE			4			///< Clear edges.
/// @}


//-------------------------------------------------------------------------------------------------
/// This class is used to extract information from a viewport about which objects and object elements are visible at which pixels.\n
/// It is used internally for stuff like highlighting and modeling.
/// @addAllocFreeAutoAllocNote
//-------------------------------------------------------------------------------------------------
class ViewportSelect
{
private:
	ViewportSelect();
	~ViewportSelect();

public:
	/// @name Alloc/Free
	/// @{

	//----------------------------------------------------------------------------------------
	/// @allocatesA{viewport select}
	/// @return												@allocReturn{viewport select}
	//----------------------------------------------------------------------------------------
	static ViewportSelect* Alloc();

	//----------------------------------------------------------------------------------------
	/// @destructsAlloc{viewport selects}
	/// @param[in,out] p							@theToDestruct{viewport select}
	//----------------------------------------------------------------------------------------
	static void Free(ViewportSelect*& p);

	/// @}

	/// @name Initialization
	/// @{

	//----------------------------------------------------------------------------------------
	/// Initializes the viewport information for a single object. This has to be done before the pixel information can be retrieved.
	/// The width and height of the viewport have to be retrieved manually:
	/// @code
	/// Int32 left, top, right, bottom, width, height
	/// bd->GetFrame(&left, &top, &right, &bottom);
	/// width = right - left + 1;
	/// height = bottom - top + 1;
	/// @endcode
	/// @param[in] w									The width of the viewport in pixels.
	/// @param[in] h									The height of the viewport in pixels.
	/// @param[in] bd									The viewport base draw. @callerOwnsPointed{base draw}
	/// @param[in] op									The object to get the information for. @callerOwnsPointed{object}
	/// @param[in] mode								The editor mode: @ref Mpoints, @ref Mpolygons, @ref Medges or @ref Mpolyedgepoint.
	/// @param[in] onlyvisible				If @formatConstant{true} only visible elements are included.
	/// @param[in] flags							The flags: @enumerateEnum{VIEWPORTSELECTFLAGS}
	/// @return												@trueIfOtherwiseFalse{the viewport select was successfully initialized}
	//----------------------------------------------------------------------------------------
	Bool Init(Int32 w, Int32 h, BaseDraw* bd, BaseObject* op, Int32 mode, Bool onlyvisible, VIEWPORTSELECTFLAGS flags = VIEWPORTSELECTFLAGS::NONE);

	//----------------------------------------------------------------------------------------
	/// Initializes the viewport information for multiple objects. This has to be done before the pixel information can be retrieved.
	/// @code
	/// Int32 left, top, right, bottom, width, height
	/// bd->GetFrame(&left, &top, &right, &bottom);
	/// width = right - left + 1;
	/// height = bottom - top + 1;
	/// @endcode
	/// @param[in] w									The width of the viewport in pixels.
	/// @param[in] h									The height of the viewport in pixels.
	/// @param[in] bd									The viewport base draw. @callerOwnsPointed{base draw}
	/// @param[in] ar									An atom array with objects to get the information for. @callerOwnsPointed{array}\n Pass @formatConstant{nullptr} or an empty array to initialize an empty ViewportSelect, for instance to draw your own polygons or handles.
	/// @param[in] mode								The editor mode: @ref Mpoints, @ref Mpolygons, @ref Medges or @ref Mpolyedgepoint.
	/// @param[in] onlyvisible				If @formatConstant{true} only visible elements are included.
	/// @param[in] flags							The flags: @enumerateEnum{VIEWPORTSELECTFLAGS}
	/// @return												@trueIfOtherwiseFalse{the viewport select was successfully initialized}
	//----------------------------------------------------------------------------------------
	Bool Init(Int32 w, Int32 h, BaseDraw* bd, AtomArray* ar, Int32 mode, Bool onlyvisible, VIEWPORTSELECTFLAGS flags = VIEWPORTSELECTFLAGS::NONE);

	/// @}

	/// @name Pick Object
	/// @{

	//----------------------------------------------------------------------------------------
	/// Picks objects within the circle that is defined by @formatParam{x}, @formatParam{y}, and @formatParam{rad} into the provided object @formatParam{list}.
	/// @param[in] bd									The viewport base draw. @callerOwnsPointed{base draw}
	/// @param[in] doc								The document. @callerOwnsPointed{document}
	/// @param[in] x									The X position of the picking circle within the viewport.
	/// @param[in] y									The Y position of the picking circle within the viewport.
	/// @param[in] rad								The radius in pixels for the search.
	/// @param[in] flags							The flags: @enumerateEnum{VIEWPORT_PICK_FLAGS}
	/// @param[in] ls									An optional lasso selection. @callerOwnsPointed{lasso selection}
	/// @param[out] list							The picked object list to fill. @callerOwnsPointed{list}
	/// @param[out] m									The projection matrix. A vector in OpenGL clipping space (@em -1,@em 1) is the result of a vector in world space multiplied by this matrix.
	/// @return												@trueIfOtherwiseFalse{objects were picked successfully}
	//----------------------------------------------------------------------------------------
	static Bool PickObject(BaseDraw* bd, BaseDocument* doc, Int32 x, Int32 y, Int32 rad, VIEWPORT_PICK_FLAGS flags, LassoSelection* ls, C4DObjectList* list, Matrix4d* m = nullptr);

	//----------------------------------------------------------------------------------------
	/// Picks objects within the circle that is defined by @formatParam{x}, @formatParam{y}, and @formatParam{rad} into the provided object @formatParam{list}.
	/// @note @formatParam{xr}, @formatParam{yr}, @formatParam{wr} and @formatParam{hr} hold the region where the picking was done. It can be smaller than the originally defined region. (e.g. If the picking is done close to the view's border.)
	/// @param[in] bd									The viewport base draw. @callerOwnsPointed{base draw}
	/// @param[in] doc								The document. @callerOwnsPointed{document}
	/// @param[in] x									The X position of the picking circle within the viewport.
	/// @param[in] y									The Y position of the picking circle within the viewport.
	/// @param[in] rad								The radius in pixels for the search.
	/// @param[out] xr								Is assigned the X position of the rectangle where the picking was done.
	/// @param[out] yr								Is assigned the Y position of the rectangle where the picking was done.
	/// @param[out] wr								Is assigned the width of the rectangle where the picking was done.
	/// @param[out] hr								Is assigned the height of the rectangle where the picking was done.
	/// @param[out] pixels						Holds an <i>[@formatParam{wr} * @formatParam{hr}]</i> array with the pixel information. For each array index this is a linked list. The array must be deleted by the caller when it is not needed anymore!
	/// @param[in] flags							The flags: @enumerateEnum{VIEWPORT_PICK_FLAGS}
	/// @param[in] ls									An optional lasso selection. @callerOwnsPointed{lasso selection}
	/// @param[out] list							The picked object list to fill. @callerOwnsPointed{list}
	/// @param[out] m									The projection matrix. A vector in OpenGL clipping space (@em -1,@em 1) is the result of a vector in world space multiplied by this matrix.
	/// @return												@trueIfOtherwiseFalse{objects were picked successfully}
	//----------------------------------------------------------------------------------------
	static Bool PickObject(BaseDraw* bd, BaseDocument* doc, Int32 x, Int32 y, Int32 rad, Int32& xr, Int32& yr, Int32& wr, Int32& hr, const ViewportPixel*const*& pixels, VIEWPORT_PICK_FLAGS flags, LassoSelection* ls, C4DObjectList* list, Matrix4d* m = nullptr);

	//----------------------------------------------------------------------------------------
	/// Picks objects within the rectangle that is defined by @formatParam{x1}, @formatParam{y1}, @formatParam{x2} and @formatParam{y2}.
	/// @note	::VIEWPORT_PICK_FLAGS::ALLOW_OGL must be set. @formatParam{x1}, @formatParam{y1}, @formatParam{x2} and @formatParam{y2} are inclusive.\n
	///				@formatParam{xr}, @formatParam{yr}, @formatParam{wr} and @formatParam{hr} hold the region where the picking was done. It can be smaller than the originally defined region. (e.g. If the picking is done close to the view's border.)
	/// @param[in] bd									The viewport base draw. @callerOwnsPointed{base draw}
	/// @param[in] doc								The document. @callerOwnsPointed{document}
	/// @param[in] x1									The X minimum position of the picking rectangle.
	/// @param[in] y1									The Y minimum position of the picking rectangle.
	/// @param[in] x2									The X maximum position of the picking rectangle.
	/// @param[in] y2									The Y maximum position of the picking rectangle.
	/// @param[out] xr								Is assigned the X position of the rectangle where the picking was done.
	/// @param[out] yr								Is assigned the Y position of the rectangle where the picking was done.
	/// @param[out] wr								Is assigned the width of the rectangle where the picking was done.
	/// @param[out] hr								Is assigned the height of the rectangle where the picking was done.
	/// @param[out] pixels						Holds an <i>[@formatParam{wr} * @formatParam{hr}]</i> array with the pixel information. For each array index this is a linked list. The array must be deleted by the caller when it is not needed anymore!
	/// @param[in] flags							The flags: @enumerateEnum{VIEWPORT_PICK_FLAGS}
	/// @param[in] ls									An optional lasso selection. @callerOwnsPointed{lasso selection}
	/// @param[out] list							The picked object list to fill. @callerOwnsPointed{list}
	/// @param[out] m									The projection matrix. A vector in OpenGL clipping space (@em -1,@em 1) is the result of a vector in world space multiplied by this matrix.
	/// @return												@trueIfOtherwiseFalse{objects were picked successfully}
	//----------------------------------------------------------------------------------------
	static Bool PickObject(BaseDraw* bd, BaseDocument* doc, Int32 x1, Int32 y1, Int32 x2, Int32 y2, Int32& xr, Int32& yr, Int32& wr, Int32& hr, const ViewportPixel*const*& pixels, VIEWPORT_PICK_FLAGS flags, LassoSelection* ls, C4DObjectList* list, Matrix4d* m = nullptr);

	/// @}

	/// @name Get Point/Polygon/Edge Viewport Pixel
	/// @{

	//----------------------------------------------------------------------------------------
	/// Retrieves point information at the pixel position (@formatParam{x},@formatParam{y}).
	/// @param[in] x									An X coordinate within the viewport. Must be @em 0 <= @formatParam{x} < @em w, where @em w is the width given to Init().
	/// @param[in] y									A Y coordinate within the viewport. Must be @em 0 <= @formatParam{y} < @em h, where @em h is the height given to Init().
	/// @return												The retrieved point information, or @formatConstant{nullptr} if no information could be retrieved. @theOwnsPointed{ViewportSelect instance, viewport pixel}.
	//----------------------------------------------------------------------------------------
	const ViewportPixel* GetPixelInfoPoint(Int32 x, Int32 y) const;

	//----------------------------------------------------------------------------------------
	/// Retrieves polygon information at the pixel position (@formatParam{x},@formatParam{y}).
	/// @param[in] x									An X coordinate within the viewport. Must be @em 0 <= @formatParam{x} < @em w, where @em w is the width given to Init().
	/// @param[in] y									A Y coordinate within the viewport. Must be @em 0 <= @formatParam{y} < @em h, where @em h is the height given to Init().
	/// @return												The retrieved polygon information, or @formatConstant{nullptr} if no information could be retrieved. @theOwnsPointed{ViewportSelect instance, viewport pixel}.
	//----------------------------------------------------------------------------------------
	const ViewportPixel* GetPixelInfoPolygon(Int32 x, Int32 y) const;

	//----------------------------------------------------------------------------------------
	/// Retrieves edge information at the pixel position (@formatParam{x},@formatParam{y}).
	/// @param[in] x									An X coordinate within the viewport. Must be @em 0 <= @formatParam{x} < @em w, where @em w is the width given to Init().
	/// @param[in] y									A Y coordinate within the viewport. Must be @em 0 <= @formatParam{y} < @em h, where @em h is the height given to Init().
	/// @return												The retrieved edge information, or @formatConstant{nullptr} if no information could be retrieved. @theOwnsPointed{ViewportSelect instance, viewport pixel}.
	//----------------------------------------------------------------------------------------
	const ViewportPixel* GetPixelInfoEdge(Int32 x, Int32 y) const;

	//----------------------------------------------------------------------------------------
	/// Retrieves point information buffer. Direct access to the buffer should always be bound by GetPixelCount().
	/// @since R19
	/// @note Direct browsing of the pixel buffers is always faster than by making a library call pixel per pixel.
	/// @param[out] pixelBuffer				The address of the point pixel buffer. @theOwnsPointed{ViewportSelect instance, pixel buffer}
	/// @param[out] pixelCount				@formatConstant{nullptr} or valid address to write the point pixel buffer count.
	/// @return												@trueIfOtherwiseFalse{the ViewportSelect was properly initialized and the point buffer is valid}
	//----------------------------------------------------------------------------------------
	Bool GetPointPixelBuffer(const ViewportPixel *const*&pixelBuffer, Int32 *pixelCount = nullptr) const;

	//----------------------------------------------------------------------------------------
	/// Retrieves edge information buffer. Direct access to the buffer should always be bound by GetPixelCount().
	/// @since R19
	/// @note Direct browsing of the pixel buffers is always faster than by making a library call pixel per pixel.
	/// @param[out] pixelBuffer				The address of the edge pixel buffer. @theOwnsPointed{ViewportSelect instance, pixel buffer}
	/// @param[out] pixelCount				@formatConstant{nullptr} or valid address to write the edge pixel buffer count.
	/// @return												@trueIfOtherwiseFalse{the ViewportSelect was properly initialized and the edge buffer is valid}
	//----------------------------------------------------------------------------------------
	Bool GetEdgePixelBuffer(const ViewportPixel *const*&pixelBuffer, Int32 *pixelCount = nullptr) const;

	//----------------------------------------------------------------------------------------
	/// Retrieves polygon information buffer. Direct access to the buffer should always be bound by GetPixelCount().
	/// @since R19
	/// @note Direct browsing of the pixel buffers is always faster than by making a library call pixel per pixel.
	/// @param[out] pixelBuffer				The address of the polygon pixel buffer. @theOwnsPointed{ViewportSelect instance, pixel buffer}
	/// @param[out] pixelCount				@formatConstant{nullptr} or valid address to write the polygon pixel buffer count.
	/// @return												@trueIfOtherwiseFalse{the ViewportSelect was properly initialized and the polygon buffer is valid}
	//----------------------------------------------------------------------------------------
	Bool GetPolygonPixelBuffer(const ViewportPixel *const*&pixelBuffer, Int32 *pixelCount = nullptr) const;

	//----------------------------------------------------------------------------------------
	/// Retrieves nearest point information at the pixel position (@formatParam{x},@formatParam{y}).
	/// @param[in] op									The object to search for the closest element. @callerOwnsPointed{object}
	/// @param[in] x									An X coordinate within the viewport. Must be @em 0 <= @formatParam{x} < @em w, where @em w is the width given to Init().\n
	/// 															If an element was found the reference is updated to reflect the X coordinate of the nearest point.
	/// @param[in] y									An Y coordinate within the viewport. Must be @em 0 <= @formatParam{y} < @em h, where @em h is the height given to Init().\n
	/// 															If an element was found the reference is updated to reflect the Y coordinate of the nearest point.
	/// @param[in] maxrad							A maximal radius for the search in pixels.
	/// @param[in] onlyselected				If @formatConstant{true} only selected elements are included in the search.
	/// @param[in] ignorelist					A list with points to ignore. @callerOwnsPointed{list}
	/// @param[in] ignorecnt					The number of points index in @formatParam{ignorelist}.
	/// @return												The retrieved nearest point information, or @formatConstant{nullptr} if no information could be retrieved. @theOwnsPointed{ViewportSelect instance, viewport pixel}.
	//----------------------------------------------------------------------------------------
	const ViewportPixel* GetNearestPoint(BaseObject* op, Int32& x, Int32& y, Int32 maxrad = LIMIT<Int32>::MAX, Bool onlyselected = false, Int32* ignorelist = nullptr, Int32 ignorecnt = 0) const;

	//----------------------------------------------------------------------------------------
	/// Retrieves nearest polygon information at the pixel position (@formatParam{x},@formatParam{y}).
	/// @param[in] op									The object to search for the closest element. @callerOwnsPointed{object}
	/// @param[in] x									An X coordinate within the viewport. Must be @em 0 <= @formatParam{x} < @em w, where @em w is the width given to Init().\n
	/// 															If an element was found the reference is updated to reflect the X coordinate of the nearest point.
	/// @param[in] y									An Y coordinate within the viewport. Must be @em 0 <= @formatParam{y} < @em h, where @em h is the height given to Init().\n
	/// 															If an element was found the reference is updated to reflect the Y coordinate of the nearest point.
	/// @param[in] maxrad							A maximal radius for the search in pixels.
	/// @param[in] onlyselected				If @formatConstant{true} only selected elements are included in the search.
	/// @param[in] ignorelist					A list with points to ignore. @callerOwnsPointed{list}
	/// @param[in] ignorecnt					The number of points index in @formatParam{ignorelist}.
	/// @return												The retrieved nearest polygon information, or @formatConstant{nullptr} if no information could be retrieved. @theOwnsPointed{ViewportSelect instance, viewport pixel}.
	//----------------------------------------------------------------------------------------
	const ViewportPixel* GetNearestPolygon(BaseObject* op, Int32& x, Int32& y, Int32 maxrad = LIMIT<Int32>::MAX, Bool onlyselected = false, Int32* ignorelist = nullptr, Int32 ignorecnt = 0) const;

	//----------------------------------------------------------------------------------------
	/// Retrieves nearest edge information at the pixel position (@formatParam{x},@formatParam{y}).
	/// @param[in] op									The object to search for the closest element. @callerOwnsPointed{object}
	/// @param[in] x									An X coordinate within the viewport. Must be @em 0 <= @formatParam{x} < @em w, where @em w is the width given to Init().\n
	/// 															If an element was found the reference is updated to reflect the X coordinate of the nearest point.
	/// @param[in] y									An Y coordinate within the viewport. Must be @em 0 <= @formatParam{y} < @em h, where @em h is the height given to Init().\n
	/// 															If an element was found the reference is updated to reflect the Y coordinate of the nearest point.
	/// @param[in] maxrad							A maximal radius for the search in pixels.
	/// @param[in] onlyselected				If @formatConstant{true} only selected elements are included in the search.
	/// @param[in] ignorelist					A list with points to ignore. @callerOwnsPointed{list}
	/// @param[in] ignorecnt					The number of points index in @formatParam{ignorelist}.
	/// @return												The retrieved nearest edge information, or @formatConstant{nullptr} if no information could be retrieved. @theOwnsPointed{ViewportSelect instance, viewport pixel}.
	//----------------------------------------------------------------------------------------
	const ViewportPixel* GetNearestEdge(BaseObject* op, Int32& x, Int32& y, Int32 maxrad = LIMIT<Int32>::MAX, Bool onlyselected = false, Int32* ignorelist = nullptr, Int32 ignorecnt = 0) const;

	//----------------------------------------------------------------------------------------
	/// Returns the number of pixels in the pixel buffers fetched with GetPixelInfoPoint()/@link GetPixelInfoEdge()@endlink/@link GetPixelInfoPolygon()@endlink.
	/// @since R19
	/// @warning Pixel array should never be indexed further than the pixel count.
	/// @return												The pixel count.
	//----------------------------------------------------------------------------------------
	Int32 GetPixelCount() const;

	/// @}

	/// @name Draw
	/// @{

	//----------------------------------------------------------------------------------------
	/// Draws a polygon into the internal pixel structure, so that pixels inside the polygon will be associated with @formatParam{i} and @formatParam{op} in the ViewportPixel retrieved.
	/// @param[in] p									An array of @formatParam{ptcnt} points that make up the polygon. @callerOwnsPointed{array} Coordinates are in screen space.
	/// @param[in] ptcnt							The number of points in the polygon @formatParam{p}.
	/// @param[in] i									The polygon index to associate with the polygon.
	/// @param[in] op									The object to associate with the polygon. @callerOwnsPointed{object}
	/// @param[in] onlyvisible				If @formatConstant{true} only visible parts of the polygon are drawn.
	/// @return												@trueIfOtherwiseFalse{the polygon was successfully drawn}
	//----------------------------------------------------------------------------------------
	Bool DrawPolygon(const Vector* p, Int32 ptcnt, Int32 i, BaseObject* op, Int32 onlyvisible = -1);

	//----------------------------------------------------------------------------------------
	/// Draws a handle into the internal pixel structure, so that pixels inside the handle will be associated with @formatParam{i} and @formatParam{op} in the ViewportPixel retrieved.
	/// @param[in] p									The position of the handle. Coordinate is in screen space.
	/// @param[in] i									The polygon index to associate with the handle.
	/// @param[in] op									The object to associate with the handle. @callerOwnsPointed{object}
	/// @param[in] onlyvisible				If @formatConstant{true} only visible parts of the handle are drawn.
	/// @return												@trueIfOtherwiseFalse{the handle was successfully drawn}
	//----------------------------------------------------------------------------------------
	Bool DrawHandle(const Vector& p, Int32 i, BaseObject* op, Int32 onlyvisible = -1);

	/// @}

	/// @name Show Hotspot
	/// @{

	//-------------------------------------------------------------------------------------------------
	/// @markPrivate
	//-------------------------------------------------------------------------------------------------
	static void ShowHotspot(EditorWindow* bw, Int32 x, Int32 y, Int32 rad, Bool bRemove);

	//----------------------------------------------------------------------------------------
	/// Draws an XOR circle to the view @formatParam{bw} at the pixel position (@formatParam{x},@formatParam{y}). The radius is set by SetBrushRadius().
	/// @param[in] bw									The editor window to draw to. @callerOwnsPointed{EditorWindow}
	/// @param[in] x									The X position of the XOR circle within the viewport. Must be @em 0 <= @formatParam{x} < @em w, where @em w is the width given to Init().
	/// @param[in] y									The Y position of the XOR circle within the viewport. Must be @em 0 <= @formatParam{y} < @em h, where @em h is the height given to Init().
	//----------------------------------------------------------------------------------------
	void ShowHotspot(EditorWindow* bw, Int32 x, Int32 y);

	//----------------------------------------------------------------------------------------
	/// Sets the radius size for ShowHotspot() to @formatParam{r}.
	/// @param[in] r									The radius in pixels.
	//----------------------------------------------------------------------------------------
	void SetBrushRadius(Int32 r);

	/// @}

	/// @name Miscellaneous
	/// @{

	//----------------------------------------------------------------------------------------
	/// Deletes the pixel information at (@formatParam{x},@formatParam{y}) according to @formatParam{mask}.
	/// @note	This is used for example in the live edge selection with "tolerant" deactivated to find out how many pixels of a certain edge was selected.\n
	///				If an edge is determined under the cursor, the pixel counter is decremented and the edge information is deleted afterwards.
	/// @param[in] x									An X coordinate within the viewport. Must be @em 0 <= @formatParam{x} < @em w, where @em w is the width given to Init().
	/// @param[in] y									A Y coordinate within the viewport. Must be @em 0 <= @formatParam{y} < @em h, where @em h is the height given to Init().
	/// @param[in] mask								A bitfield of what to clear: @enumerateEnum{VIEWPORT_CLEAR}
	//----------------------------------------------------------------------------------------
	void ClearPixelInfo(Int32 x, Int32 y, UChar mask);

	//----------------------------------------------------------------------------------------
	/// Converts the pixel position (@formatParam{x},@formatParam{y},@formatParam{z}) to camera coordinates in @formatParam{v}.
	/// @note This is not exactly the same as
	/// @code v = bd->SC(Vector(x,y,z)) @endcode
	/// since inverted Z coordinates are used.
	/// @param[in] x									An X coordinate within the viewport. Must be @em 0 <= @formatParam{x} < @em w, where @em w is the width given to Init().
	/// @param[in] y									A Y coordinate within the viewport. Must be @em 0 <= @formatParam{y} < @em h, where @em h is the height given to Init().
	/// @param[in] z									A Z coordinate within the viewport.
	/// @param[in] v									Is assigned the calculated camera coordinate.
	/// @return												@trueIfOtherwiseFalse{the pixel position was successfully converted}
	//----------------------------------------------------------------------------------------
	Bool GetCameraCoordinates(Float x, Float y, Float z, Vector& v) const;

	/// @}
};

//----------------------------------------------------------------------------------------
/// @markPrivate
//----------------------------------------------------------------------------------------
void DrawTools(const AtomArray *activeobjects, const AtomArray *activetags, BaseDocument *doc, BaseDraw *bd, BaseThread *bt, TOOLDRAW drawflags, Bool inversez);

#endif // C4D_BASEDRAW_H__
