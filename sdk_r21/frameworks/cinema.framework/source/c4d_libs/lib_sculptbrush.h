/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

/// @addtogroup Sculpting
/// @{

#ifndef LIB_SCULPTBRUSH_H__
#define LIB_SCULPTBRUSH_H__

#include "c4d_library.h"
#include "ge_math.h"
#include "lib_description.h"

#include "c4d_baseobject.h"
#include "c4d_basetag.h"
#include "c4d_tooldata.h"
#include "c4d_descriptiondialog.h"
#include "description/toolsculptbrushbase.h"
#include "c4d_nodedata.h"
#include "description/bmbase.h"

class _SculptBrushToolBase;
class iSculptBrushBase;
class SculptBrushToolData;
class SculptObject;

/// @addtogroup group_sculptbrushlibrary Sculpt Brush
/// @ingroup group_library
/// @{

/// Sculpt brush library ID.
#define LIBRARY_SCULPTBRUSH	1028489

/// @addtogroup SCULPTBRUSHID
/// @ingroup group_enumeration
/// @{
/// A list of the IDs for the main Sculpt brushes.\n
/// When registering Modifiers (see RegisterBrushModifier()) use these IDs to either filter out the Modifier for one or more specific brushes, or alternatively only show the Modifier on one or more specific brushes.
enum class SCULPTBRUSHID
{
	SMOOTH		= 1024170,			///< Smooth brush ID.
	PULL			= 1024168,			///< Pull brush ID.
	FLATTEN		= 1024169,			///< Flatten brush ID.
	PINCH			= 1024171,			///< Pinch brush ID.
	ERASE			= 1024189,			///< Erase brush ID.
	GRAB			= 1024197,			///< Grab brush ID.
	MASK			= 1024506,			///< Mask brush ID.
	KNIFE			= 1026519,			///< Knife brush ID.
	WAX				= 1026518,			///< Wax brush ID.
	INFLATE		= 1026708,			///< Inflate brush ID.
	FILL			= 1026710,			///< Fill brush ID.
	SCRAPE		= 1026715,			///< Scrape brush ID.
	REPEAT		= 1027556,			///< Repeat brush ID.
	AMPLIFY		= 1029169,			///< Amplify brush ID.
	SELECT		= 1031429				///< Select brush ID.
} MAXON_ENUM_LIST(SCULPTBRUSHID);
/// @}

/// @addtogroup FIRSTHITPPOINTTYPE
/// @ingroup group_enumeration
/// @{
/// When the user first clicks on a SculptObject this determines what the returned hit point will be.
enum class FIRSTHITPPOINTTYPE
{
	SELECTED,			///< Use the exact hit location on the surface as the hit point.
	AVERAGE,				///< Use the average location of all the points that the brush dab touches.
} MAXON_ENUM_LIST(FIRSTHITPPOINTTYPE);
/// @}

/// @addtogroup SCULPTBRUSHMODE
/// @ingroup group_enumeration
/// @{
/// A brush uses one of 2 modes.
enum class SCULPTBRUSHMODE
{
	NORMAL,			///< Samples the surface as the user moves over it the SculptObject and returns a new hit point and normal each time.
	GRAB,				///< Calculates affected points, hit point and normal the first time the user clicks.\n
							///< These are the only points that are affected as the user moves the mouse.\n
							///< This mode is used by the Grab Tool which uses the BrushDabData::GetMousePos3D() method to get the mouse position in 3D space as the user moves it.
} MAXON_ENUM_LIST(SCULPTBRUSHMODE);
/// @}

/// @addtogroup SCULPTBRUSHDATATYPE
/// @ingroup group_enumeration
/// @{
/// Specifies what kind of data is affected by a brush.
enum class SCULPTBRUSHDATATYPE
{
	NONE				= 0,					///< None.
	POINT				= 1 << 0,			///< The points are changed.
	MASK				= 1 << 1,			///< The mask data is changed.
	COLOR				= 1 << 2,			///< @markInternal
	DIRTYPOINTS	= 1 << 3,			///< @markInternal Used by tiles to check if all its points have already been marked as dirty or not.
} MAXON_ENUM_FLAGS(SCULPTBRUSHDATATYPE);
/// @}

/// @addtogroup OVERRIDE
/// @ingroup group_enumeration
/// @{
/// Overrides are set by modifier keys to signal to the brush that it should do something different.
enum class OVERRIDE
{
	NONE = 0,

	INVERT			= 1 << 0,			///< If the user holds down the @em Ctrl key then the brush should Invert its functionality.
	SMOOTH			= 1 << 1,			///< The user is holding down the @em Shift key and a smooth operation should be done.\n
														///< Brushes can choose to specify their own operation for smooth, like the Mask Tool which does a blur.
	SMOOTHTOOL	= 1 << 2			///< @markInternal Used to specify that the smooth is tool specific.
} MAXON_ENUM_FLAGS(OVERRIDE);
/// @}

/// @addtogroup SAMPLEMODE
/// @ingroup group_enumeration
/// @{
/// The sample mode to use when sampling the textures for stamps or stencils.
enum class SAMPLEMODE
{
	TAKEONEPIXEL	= 1 << 0,			///< Takes the exact pixel at the intersection point.
} MAXON_ENUM_FLAGS(SAMPLEMODE);
/// @}

/// @addtogroup SCULPTOFFSETFLAGS
/// @ingroup group_enumeration
/// @{
/// Flags for the BrushDabData::OffsetPoint() methods to allow to use or ignore settings for the layer such as Mask and Strength.
enum class SCULPTOFFSETFLAGS
{
	NONE						= 0,					///< None.
	RESPECTSTRENGTH	= 1 << 0,			///< Respect the Strength of the current layer.
	IGNOREMASK			= 1 << 1,			///< Ignore the Mask setting for the current layer.
} MAXON_ENUM_FLAGS(SCULPTOFFSETFLAGS);
/// @}

//----------------------------------------------------------------------------------------
/// A specialized class for sculpting that is optimized to store Boolean states.\n
/// Each Boolean state is represented by a single bit which reduces the memory requirements.
//----------------------------------------------------------------------------------------
class SculptFlagChecker
{
private:
	SculptFlagChecker();
	~SculptFlagChecker();
public:

	//----------------------------------------------------------------------------------------
	/// @allocatesA{SculptFlagChecker object}
	/// @return												@allocReturn{SculptFlagChecker object}
	//----------------------------------------------------------------------------------------
	static SculptFlagChecker *Alloc();

	//----------------------------------------------------------------------------------------
	/// @destructsAlloc{SculptFlagChecker objects}
	/// @param[in,out] fc							@theToDestruct{SculptFlagChecker object}
	//----------------------------------------------------------------------------------------
	static void Free(SculptFlagChecker *&fc);

	//----------------------------------------------------------------------------------------
	/// Initializes with the number of states to check. Data will be allocated so that each boolean state will only use a single bit for each state.
	/// @param[in] count							The number of states that need to be set.
	/// @return												@trueIfOtherwiseFalse{the memory could be allocated to store the required number of bits}
	//----------------------------------------------------------------------------------------
	Bool Init(UInt32 count);

	//----------------------------------------------------------------------------------------
	/// Clears the currently set states. This method is optimized for speed to only clear the memory for the bits that were actually set.
	//----------------------------------------------------------------------------------------
	void Clear();

	//----------------------------------------------------------------------------------------
	/// Gets the number of states set in the Init() method.
	/// @return												The value set from the Init() method.
	//----------------------------------------------------------------------------------------
	UInt32 GetCount();

	//----------------------------------------------------------------------------------------
	/// Sets the state of the bit to @formatConstant{true} at the given @formatParam{index}.
	/// @param[in] index							The index of the bit to set: @em <= @formatParam{index} < GetCount()
	//----------------------------------------------------------------------------------------
	void Set(UInt32 index);

	//----------------------------------------------------------------------------------------
	/// Checks the state of the bit at the given @formatParam{index} and also sets it to @formatConstant{true} if it was not previously set.
	/// @param[in] index							The index of the bit to check: @em <= @formatParam{index} < GetCount()
	/// @return												@trueIfOtherwiseFalse{the bit is @formatConstant{true} at the given @formatParam{index}}
	//----------------------------------------------------------------------------------------
	Bool CheckSet(UInt32 index);

	//----------------------------------------------------------------------------------------
	/// Checks the state of the bit at the given @formatParam{index}.
	/// @param[in] index							The index of the bit to check: @em <= @formatParam{index} < GetCount()
	/// @return												@trueIfOtherwiseFalse{the bit is @formatConstant{true} at the given @formatParam{index}}
	//----------------------------------------------------------------------------------------
	Bool Check(UInt32 index);

	//----------------------------------------------------------------------------------------
	/// Clears the state of the bit at the given @formatParam{index}.
	/// @param[in] index							The index of the bit to unset: @em <= @formatParam{index} < GetCount()
	//----------------------------------------------------------------------------------------
	void UnSet(UInt32 index);
};


//----------------------------------------------------------------------------------------
/// Iterates over all the polygons that are connected to a specified vertex.
/// @code
/// SculptObject *pSculpt = GetSelectedSculptObject(GetActiveDocument());
/// AutoAlloc<SculptPointPolysIterator> itr;
/// if (itr)
/// {
/// 	// Iterate over all the polygons connected to vertex 0
/// 	for (itr->Init(pSculpt, 0); itr->IsValid(); itr->Next())
/// 	{
/// 		CPolygon poly = itr->GetPolygon();
/// 	}
/// }
/// @endcode
//----------------------------------------------------------------------------------------
class SculptPointPolysIterator
{
private:
	SculptPointPolysIterator();
	~SculptPointPolysIterator();

public:

	//----------------------------------------------------------------------------------------
	/// @allocatesA{SculptPointPolysIterator object}
	/// @return												@allocReturn{SculptPointPolysIterator object}
	//----------------------------------------------------------------------------------------
	static SculptPointPolysIterator *Alloc();

	//----------------------------------------------------------------------------------------
	/// @destructsAlloc{SculptPointPolysIterator objects}
	/// @param[in,out] itr						@theToDestruct{SculptPointPolysIterator object}
	//----------------------------------------------------------------------------------------
	static void Free(SculptPointPolysIterator *&itr);

	//----------------------------------------------------------------------------------------
	/// Initializes the SculptPointPolysIterator for the given SculptObject and vertex index.
	/// @param[in] pObj								The SculptObject to iterate over the polygons for. @callerOwnsPointed{SculptObject}
	/// @param[in] vertex							The vertex to check for connected polygons.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool Init(const SculptObject *pObj, Int32 vertex);

	//----------------------------------------------------------------------------------------
	/// Moves to the next polygon that is connected to the vertex.
	//----------------------------------------------------------------------------------------
	void Next();

	//----------------------------------------------------------------------------------------
	/// After calling Next() checks if the polygon is valid. If it is valid then call GetPolygon() and GetIndex().
	/// @return												@trueIfOtherwiseFalse{the polygon is valid}
	//----------------------------------------------------------------------------------------
	Bool IsValid();

	//----------------------------------------------------------------------------------------
	/// Gets the current CPolygon connected to the vertex that the iterator is pointing to.
	/// @return												The current CPolygon.
	//----------------------------------------------------------------------------------------
	CPolygon GetPolygon();

	//----------------------------------------------------------------------------------------
	/// Gets the index of the current polygon.\n
	/// @note This is the index of the polygon in the PolygonObject at the SculptObject current subdivision level, which can be accessed calling BrushDabData::GetPolygonObject().
	/// @return												The index of the polygon.
	//----------------------------------------------------------------------------------------
	Int32 GetIndex();
};


//----------------------------------------------------------------------------------------
/// If SculptBrushParams::EnableMouseData(@formatConstant{true}) has been set for the brush then you will receive this data structure in the SculptBrushToolData::MouseData method as the mouse moves over the surface of the model.
/// @since R17.032
//----------------------------------------------------------------------------------------
struct SculptMouseData
{
	SculptObject *pObject;		///< The selected Object underneath the mouse.
	Vector mouseCoord;				///< The screen coordinates for the mouse location in the current viewport.
	Vector hitPoint;					///< The hitpoint on the surface of the model at the center of the brush dab.
	Vector32 normal;					///< The normal on the surface of the model at the center of the brush dab.
	Vector barryCoord;				///< The barycentric coordinates within the triangle for the hit polygon.
	Int polygon;							///< The Index of the hit polygon.
	Bool mouseDrag;						///< This will be set to @formatConstant{true} if the mouse button is held down and being dragged in the viewport.
	Float distance;						///< The distance from the mouse in local space to the surface of the object.
	Bool isBackface;					///< This will be set to @formatConstant{true} if the polygon under the mouse is backfacing.
};

//----------------------------------------------------------------------------------------
/// Allows to change the BaseBitmap used for the dab.\n
/// If SculptBrushParams::EnableCustomStamp(@formatConstant{true}) and SculptBrushParams::EnableBrushAccess(@formatConstant{true}) are both set then a call to @c SculptBrushParams::GetCustomData will be made right before the dab is drawn.\n
/// Simply set there @ref pStamp to point to a BaseBitmap, that is owned by the brush itself.
//----------------------------------------------------------------------------------------
struct SculptCustomData
{
	BaseBitmap *pStamp;			///< The bitmap for the dab.

	//----------------------------------------------------------------------------------------
	/// Default constructor.
	//----------------------------------------------------------------------------------------
	SculptCustomData()
	{
		Clear();
	}

	//----------------------------------------------------------------------------------------
	/// Clears the bitmap.
	//----------------------------------------------------------------------------------------
	void Clear()
	{
		pStamp = nullptr;
	}
};


//----------------------------------------------------------------------------------------
/// The data for each point in a brush dab.
//----------------------------------------------------------------------------------------
struct BrushPointData
{
	Int32 internalData;			///< @markPrivate
	Int32 pointIndex;				///< The index of the the point on the PolygonObject/SculptObject.
	Float distance;					///< The distance from the hit point of the dab.
};

//----------------------------------------------------------------------------------------
/// The data for each point in a brush dab.
//----------------------------------------------------------------------------------------
struct BrushPolyData
{
	Int32 polyIndex;			///< The index of the polygon on the PolygonObject/SculptObject.
};


class SculptPointData; // Internal
class SculptLayer;
class SculptObject;

//----------------------------------------------------------------------------------------
/// The brush data for an individual dab. This is passed into the method defined by the user in SculptBrushParams::SetMovePointFunc.
//----------------------------------------------------------------------------------------
class BrushDabData
{
private:
	BrushDabData();
	~BrushDabData();

public:
	//----------------------------------------------------------------------------------------
	/// Gets the settings data for the brush.
	/// @return												The container for the brush.
	//----------------------------------------------------------------------------------------
	const BaseContainer* GetData();

	//----------------------------------------------------------------------------------------
	/// Gets the sculpt object that the dab is for.
	/// @return												The sculpt object.
	//----------------------------------------------------------------------------------------
	const SculptObject* GetObject();

	//----------------------------------------------------------------------------------------
	/// Gets the list of points that are affected by the brush.
	/// @note Call GetPointCount() to get the number of points in the returned array.
	/// @return												The list of points.
	//----------------------------------------------------------------------------------------
	const BrushPointData* GetPointData();

	//----------------------------------------------------------------------------------------
	/// Gets the list of the polygons that are affected by the brush.
	/// @note Call GetPolyCount() to get the number of polygons in the returned array.
	/// @return												The list of polygons.
	//----------------------------------------------------------------------------------------
	const BrushPolyData* GetPolyData();

	//----------------------------------------------------------------------------------------
	/// Gets the PolygonObject for the SculptObject that is currently being displayed in the viewport.
	/// @return												The polygon object.
	//----------------------------------------------------------------------------------------
	PolygonObject* GetPolygonObject();

	//----------------------------------------------------------------------------------------
	/// Gets the original object that the SculptTag is applied to.
	/// @note In the case where this there is no SculptTag on then this will return the same as the call to GetPolygonObject().
	/// @return												The PolygonObject.
	//----------------------------------------------------------------------------------------
	PolygonObject* GetBaseObject();

	//----------------------------------------------------------------------------------------
	/// Gets the number of points that are touched by the dab.
	/// @note This is the number of points in the array returned from GetPointData().
	/// @return												The number of points.
	//----------------------------------------------------------------------------------------
	Int32 GetPointCount();

	//----------------------------------------------------------------------------------------
	/// Gets the number of polygons that are touched by the dab.
	/// @note this is the number of polygons in the array returned from GetPolyData().
	/// @return												The number of polygons.
	//----------------------------------------------------------------------------------------
	Int32 GetPolyCount();

	//----------------------------------------------------------------------------------------
	/// Gets the Neighbor information for the SculptObject if it is currently at level @em 0.
	/// @note If the user is sculpting a regular unsubdivided PolygonObject then this also returns a valid pointer.
	/// @return												The Neighbor information if SculptObject is at level @em 0 or if the user is sculpting on a regular PolygonObject, otherwise @formatConstant{nullptr}.
	//----------------------------------------------------------------------------------------
	Neighbor* GetNeighbor();

	//----------------------------------------------------------------------------------------
	/// Gets the currently selected Layer for a subdivided SculptObject.
	/// @note If the user is sculpting a regular PolygonObject then this returns @formatConstant{nullptr}.
	/// @return												The currently selected layer in the Layer Manager if it is a subdivided SculptObject, otherwise @formatConstant{nullptr}.
	//----------------------------------------------------------------------------------------
	SculptLayer* GetLayer();

	//----------------------------------------------------------------------------------------
	/// Retrieves the live points that are modified on the surface during a brush stroke.\n
	/// These points may already have been modified by previous brush dabs during the current brush stroke.
	/// @return												The points on the PolygonObject that is currently displayed in the viewport.
	//----------------------------------------------------------------------------------------
	const Vector* GetPoints();

	//----------------------------------------------------------------------------------------
	/// Retrieves a copy of the points in their state @b before the brush stroke started.\n
	/// Use these points to compare where the surface was before the user started sculpting.
	/// @note As an example this data is used by the grab tool to correctly offset the points based on their original location on the surface at the first mouse click.
	/// @return												The points on the PolygonObject at the state it was in when the user first pressed the left mouse button down.
	//----------------------------------------------------------------------------------------
	const Vector32* GetOriginalPoints();

	//----------------------------------------------------------------------------------------
	/// Gets the normal at the current hit point for the dab.\n
	/// This is the average vertex normal of all the points that are affected by the dab.
	/// @return												The normal at the current hit point.
	//----------------------------------------------------------------------------------------
	Vector GetNormal();

	//----------------------------------------------------------------------------------------
	/// If the brush supports the Draw Direction, i.e. the user has set @ref SculptBrushParams::EnableDrawDirection(@formatConstant{true}),\n
	/// then this returns the direction selected by the user, otherwise it just returns the same vector as GetNormal().
	/// @return												The Draw Direction normal.
	//----------------------------------------------------------------------------------------
	Vector GetDrawDirectionNormal();

	//----------------------------------------------------------------------------------------
	/// Gets the brush strength for the dab.
	/// @note	This strength is not the same as the strength in the container returned by GetData().\n
	///				This also takes into account many other variables including tablet pressure to create the value.
	/// @return												The strength of the brush.
	//----------------------------------------------------------------------------------------
	Float GetBrushStrength();

	//----------------------------------------------------------------------------------------
	/// Gets the brush radius for the dab.
	/// @note	This is not the same as the brush size in the container returned by GetData().\n.
	///				This also takes into account other factors such as the distance from the camera, scale of the object and tablet values to determine the correct brush radius.
	/// @return												The radius of the brush. The size of the radius is in the sculpt objects local space.
	//----------------------------------------------------------------------------------------
	Float GetBrushRadius();

	//----------------------------------------------------------------------------------------
	/// If the brush mode is ref SCULPTBRUSHMODE::GRAB then this method can be used to get the location of the mouse pointer in world space in the scene.
	/// @return												If the brush mode is @ref SCULPTBRUSHMODE::GRAB returns the position of the mouse in world space, otherwise @c Vector(0,0,0).
	//----------------------------------------------------------------------------------------
	Vector GetMousePos3D();

	//----------------------------------------------------------------------------------------
	/// Gets the point on the surface of the SculptObject where the dab is going to be placed. This is the center of the dab.
	/// @note If the mode is set to @ref SCULPTBRUSHMODE::GRAB then this always returns the initial hit point that occurred when the user first pressed the left mouse button down.
	/// @return												The hit point on the surface.
	//----------------------------------------------------------------------------------------
	Vector GetHitPoint();

	//----------------------------------------------------------------------------------------
	/// Gets the hit point for the previous dab during the stroke.
	/// @return												The hit point on the surface.
	//----------------------------------------------------------------------------------------
	Vector GetLastHitPoint();

	//----------------------------------------------------------------------------------------
	/// Gets the index of the polygon on the surface of the SculptObject where the dab is going to be placed. This is the center of the dab.
	/// @note	If the mode is set to @ref SCULPTBRUSHMODE::GRAB then this always returns the initial hit polygon that occurred when the user first pressed the left mouse button down.
	/// @since R17.032
	/// @return												The index of the polygon on hit the surface.
	//----------------------------------------------------------------------------------------
	Int32 GetHitPolygon();

	//----------------------------------------------------------------------------------------
	/// Gets the location of the mouse in local space above the model.\n
	/// @note	This point is created by interpolating between previous and next real mouse hit point on the surface of the SculptObject.\n
	///				This is then projected down onto the surface of the model to get the real hit point for the interpolated value.
	/// @return												The virtual mouse location in local space above the surface of the SculptObject.
	//----------------------------------------------------------------------------------------
	Vector GetEyePoint();

	//----------------------------------------------------------------------------------------
	/// Checks if the dab is for a mirrored brush stroke.
	/// @return												@formatConstant{true} it is a mirrored dab or @formatConstant{false} if it is the main brush stroke.
	//----------------------------------------------------------------------------------------
	Bool IsMirroredDab();

	//----------------------------------------------------------------------------------------
	/// Gets the override flags. This can be any combination of the @ref OVERRIDE flags.
	/// @return												The brush override flags if there are any or @em 0 if there are none: @enumerateEnum{OVERRIDE}
	//----------------------------------------------------------------------------------------
	OVERRIDE GetBrushOverride();

	//----------------------------------------------------------------------------------------
	/// Gets the view that the user is currently drawing in.
	/// @return												The view.
	//----------------------------------------------------------------------------------------
	BaseDraw* GetBaseDraw();

	//----------------------------------------------------------------------------------------
	/// Gets the average point and normal.\n
	/// The returned values depend on what the fixed plane (@ref MDATA_SCULPTBRUSH_SETTINGS_FIXEDPLANE) setting is for the brush:
	///	- @ref MDATA_SCULPTBRUSH_SETTINGS_FIXEDPLANE_OFF
	///		- @formatParam{averagePoint} = The average location of all the points that are touched by the dab.
	///		- @formatParam{normal} = The normal at the hit point on the surface of the SculptObject.
	///	- @ref MDATA_SCULPTBRUSH_SETTINGS_FIXEDPLANE_MOUSEDOWN
	///		- @formatParam{averagePoint} = The average location of all the points under the dab area when the mouse was mouse button was first pressed.
	///		- @formatParam{normal} = The average normal of all the points under the dab area when the mouse was mouse button was first pressed.
	///	- @ref MDATA_SCULPTBRUSH_SETTINGS_FIXEDPLANE_WORKPLANE
	///		- @formatParam{averagePoint} = The point on the workplane that is above the hit point on the surface of the SculptObject.
	///		- @formatParam{normal} = The normal of the workplane.
	/// - @ref MDATA_SCULPTBRUSH_SETTINGS_FIXEDPLANE_CUSTOM
	///		- @formatParam{averagePoint}	= The point on the custom plane that is above the hitpoint on the surface of the SculptObject
	///		- @formatParam{normal}	= The normal of the custom plane.
	/// @param[out] averagePoint			Assigned the average point based on the fixed plane settings.
	/// @param[out] normal						Assigned the normal based on the fixed plane setting.
	//----------------------------------------------------------------------------------------
	void GetAveragePointAndNormal(Vector &averagePoint, Vector &normal);

	//----------------------------------------------------------------------------------------
	/// Applies an effect of the smooth brush to the current dab.
	/// @note Call this after modification of the dab to smooth it out.
	//----------------------------------------------------------------------------------------
	void ApplySmooth();

	//----------------------------------------------------------------------------------------
	/// Gets the vertex normals for the SculptObject.
	/// @note The number of vertex normals is equal to the number of points on the PolygonObject returned from @ref GetPolygonObject().
	/// @return												The vertex normals for the SculptObject.
	//----------------------------------------------------------------------------------------
	const Vector32* GetVertexNormals();

	//----------------------------------------------------------------------------------------
	/// Gets the state of the vertex normals before the user started a brush stroke.
	/// @note The number of vertex normals is equal to the number of points on the PolygonObject returned from GetPolygonObject().
	/// @since R17.032
	/// @return												The vertex normals for the SculptObject.
	//----------------------------------------------------------------------------------------
	const Vector32* GetOriginalVertexNormals();

	//----------------------------------------------------------------------------------------
	/// Gets the face normals for the SculptObject.
	/// @note The number of face normals is equal to the number of polygons on the PolygonObject returned from GetPolygonObject().
	/// @since R17.032
	/// @return												The face normals for the SculptObject.
	//----------------------------------------------------------------------------------------
	const Vector32* GetFaceNormals();

	//----------------------------------------------------------------------------------------
	/// Gets a value which represents the scale of the SculptObject.
	/// @note	This value can be used to convert a distance in object space with the value returned from GetBrushRadius() to help adjust the algorithm for the brush\n
	///				since the value returned from GetBrushRadius() is also already adjusted using the same value.
	/// @param[in] noRadius						@formatConstant{true} means it does not take into account the radius of the object in its calculation and only uses the scale.
	/// @return												The scale value with which to adjust the local space vector or distance value.
	//----------------------------------------------------------------------------------------
	Float GetAutoScaleValue(Bool noRadius);

	//----------------------------------------------------------------------------------------
	/// Retrieves the brush falloff for the brush point at @formatParam{index}.\n
	/// The falloff is already adjusted by using the values from the stamp and stencil so it can be used directly to adjust the strength of an offset to add to the layer.\n
	/// @param[in] index							The index of the point on the SculptObject.\n
	/// 															This index can be found for the current point using BrushPointData.pointIndex.
	/// @param[out] pRetStencilColor	Assigned the color of the stencil. This saves an additional call to GetStencilColor().
	/// @param[in] pCustomDistance		The custom distance to use.\n
	/// 															Internally this method uses the distance that the point is from the hit point in its calculation (BrushPointData::distance).\n
	/// 															Pass a value instead to use custom distance.\n
	/// @return												The final falloff value that can be used to adjust the offset value.
	//----------------------------------------------------------------------------------------
	Float GetBrushFalloff(Int32 index, Vector32 *pRetStencilColor = nullptr, Float *pCustomDistance = nullptr);

	//----------------------------------------------------------------------------------------
	/// Retrieves the falloff value, defined by the falloff curve, based on the distance from input @formatParam{pos} to the hit point for the dab.
	/// @param[in] pos								A point in 3D space to get the falloff for.
	/// @return												The falloff value.
	//----------------------------------------------------------------------------------------
	Float GetBrushFalloffFromPos(const Vector &pos);

	//----------------------------------------------------------------------------------------
	/// Offsets the brush point at @formatParam{index} point on the layer by the given @formatParam{offset} amount.
	/// @note This method should be used only if IsPreviewDab() returns @formatConstant{false}, otherwise use OffsetPreviewPoint() method.
	/// @param[in] index							The index of the point on the SculptObject.\n
	/// 															This index can be found for the current point using BrushPointData.pointIndex.
	/// @param[in] offset							The vector to offset the point by.
	/// @param[in] pVertexColor				@markPrivate Used internally.
	/// @param[in] flags							The flags to let use or ignore settings such as the layers mask or strength when offsetting the point: @enumerateEnum{SCULPTOFFSETFLAGS}
	/// 															By setting the SCULPTOFFSETFLAGS::IGNOREMASK flag it will ignore whatever the mask checkbox state is for the layer\n
	/// 															Otherwise it uses this state to determine if it should use the mask.
	//----------------------------------------------------------------------------------------
	void OffsetPoint(Int32 index, const Vector &offset, Vector32 *pVertexColor = nullptr, SCULPTOFFSETFLAGS flags = SCULPTOFFSETFLAGS::NONE);

	//----------------------------------------------------------------------------------------
	/// Checks if the dab is a preview dab.
	/// @note Currently only DragRect and DragDab support preview brushes.
	/// @return												@trueIfOtherwiseFalse{if it is a preview dab}
	//----------------------------------------------------------------------------------------
	Bool IsPreviewDab();

	//----------------------------------------------------------------------------------------
	/// If IsPreviewDab() returns @formatConstant{true} then apply the offset using this method.\n
	/// This adds the offset to a temporary preview layer that is created when using the DragDab and DragRect draw modes.
	/// @note This method should be used only if IsPreviewDab() returns @formatConstant{true}, otherwise use OffsetPoint() method.
	/// @param[in] index							The index of the point on the SculptObject.\n
	/// 															This index can be found for the current point using BrushPointData.pointIndex.
	/// @param[in] offset							The vector to offset the point by.
	/// @param[in] flags							The flags to let use or ignore settings such as the layers mask or strength when offsetting the point: @enumerateEnum{SCULPTOFFSETFLAGS}\n
	/// 															By setting the @ref SCULPTOFFSETFLAGS::IGNOREMASK flag it ignores whatever the mask checkbox state is for the layer.\n
	/// 															Otherwise it uses this state to determine if it should use the mask.
	//----------------------------------------------------------------------------------------
	void OffsetPreviewPoint(Int32 index, const Vector &offset, SCULPTOFFSETFLAGS flags = SCULPTOFFSETFLAGS::NONE);

	//----------------------------------------------------------------------------------------
	/// Makes dirty all the points for the dab according to the @ref SCULPTBRUSHDATATYPE.
	/// @param[in] type								The type to use for the brush data to make dirty.
	//----------------------------------------------------------------------------------------
	void DirtyAllPoints(SCULPTBRUSHDATATYPE type);

	//----------------------------------------------------------------------------------------
	/// Checks if another brush stroke has changed a point.
	/// @note When using Symmetry, another mirrored brush may change the point.
	/// @param[in] index							The index of the point on the SculptObject.\n
	/// 															This index can be found for the current point using BrushPointData.pointIndex.
	/// @return												@trueIfOtherwiseFalse{the point was modified}
	//----------------------------------------------------------------------------------------
	Bool IsPointModified(Int32 index);

	//----------------------------------------------------------------------------------------
	/// Retrieves the color and gray values of the stencil for a point in the SculptObject local space.
	/// @param[in] point							A point on the surface of the SculptObject for which to get a color for.
	/// @param[out] pRetColor					Assigned the color of the stencil.
	/// @param[out] pRetCoords				Assigned the returned coordinates of the pixel on the stencil bitmap.
	/// @param[in] mode								The sample mode used to sample the stencil texture: @enumerateEnum{SAMPLEMODE}
	/// @return												The gray scale value of the stencil, which has been adjusted by the stencil gray value.
	//----------------------------------------------------------------------------------------
	Float GetStencilColor(const Vector &point, Vector32 *pRetColor = nullptr, Vector32 *pRetCoords = nullptr, SAMPLEMODE mode = SAMPLEMODE::TAKEONEPIXEL);

	//----------------------------------------------------------------------------------------
	/// Retrieves the color and gray values of the stamp for a point in the SculptObject local space.
	/// @param[in] point							A point in the SculptObject coordinate system which is used to sample the stamp on the current dab.
	/// @param[in] distanceFromHitPoint	Can be either the BrushPointData.distance value, the length of the vector (hit point - point) or a custom distance value.\n
	/// 															This is used to get the correct falloff for the point.
	/// @param[out] pRetColor					Assigned the color of the stamp.
	/// @param[out] pRetCoords				Assigned the coordinates of the pixel on the stamp bitmap.
	/// @param[in] mode								The sample mode used to sample the stencil texture: @enumerateEnum{SAMPLEMODE}
	/// @return												The gray scale value of the stamp, which has been adjusted by the stamp gray value.
	//----------------------------------------------------------------------------------------
	Float GetStampColor(const Vector &point, Float distanceFromHitPoint, Vector32 *pRetColor = nullptr, Vector32 *pRetCoords = nullptr, SAMPLEMODE mode = SAMPLEMODE::TAKEONEPIXEL);

	//----------------------------------------------------------------------------------------
	/// Get the stencil used for the dab.
	/// @return												The bitmap for the stencil.
	//----------------------------------------------------------------------------------------
	const BaseBitmap* GetStencil();

	//----------------------------------------------------------------------------------------
	/// Gets the stamp used for the dab.
	/// @return												The bitmap for the stamp.
	//----------------------------------------------------------------------------------------
	const BaseBitmap* GetStamp();

	//----------------------------------------------------------------------------------------
	/// Gets the Brush being used.
	/// This only returns the brush if SculptBrushParams::EnableBrushAccess(true) has been set.
	/// @warning	If this is called by a Modifier then it returns @formatConstant{nullptr}.
	///						Always check to make sure the returned pointer is not a @formatConstant{nullptr}.
	/// @return												A pointer to the brush tool data.
	//----------------------------------------------------------------------------------------
	SculptBrushToolData* GetBrush();

	//----------------------------------------------------------------------------------------
	/// Gets the ID of the stroke instance that the dab is being drawn for.
	/// @return												The stroke instance ID.
	//----------------------------------------------------------------------------------------
	Int32 GetStrokeInstanceID();

	//----------------------------------------------------------------------------------------
	/// Checks if the object being touched is a SculptObject (i.e. it has a SculptTag).
	/// @return												trueIfOtherwiseFalse{it is a SculptObject}
	//----------------------------------------------------------------------------------------
	Bool IsSculptObject();

	//----------------------------------------------------------------------------------------
	/// Gets the mirrored point (or Normal) from the objects space to the correct location for the current dab.\n
	/// @warning	This should only be used to get the symmetrically mirrored point for a point.\n
	///						In most cases this method would never be used because the brush system automatically handles symmetrical points.
	/// @param[in] point							The input point, or normal, to mirror.
	/// @param[in] isNormal						Set to @formatConstant{true} if the @formatParam{point} is a normal, the point is then only rotated and not offseted.
	/// @return												The mirrored point.
	//----------------------------------------------------------------------------------------
	Vector GetMirrorPoint(const Vector &point, Bool isNormal);

	//----------------------------------------------------------------------------------------
	/// Gets the current mask values for the PolygonObject.
	/// @note The number of points returned is equal to the number of points on the PolygonObject.
	/// @return												The mask values.
	//----------------------------------------------------------------------------------------
	Float32* GetMaskCache();

	//----------------------------------------------------------------------------------------
	/// Averages out the values for a vertex on the PolygonObject.
	/// @param[in] vertex							The vertex number on the PolygonObject to get the average value for.
	/// @param[out] values						The values to average out. This must contains the same number of values as there are points on the PolygonObject.
	/// @return												The mask values.
	//----------------------------------------------------------------------------------------
	Float32 PointPolysAverage(Int32 vertex, Float32 *values);

	//----------------------------------------------------------------------------------------
	/// Averages out the values for a vertex on the PolygonObject.
	/// @param[in] vertex							The vertex number on the PolygonObject to get the average value for.
	/// @param[in] values							The values to average out. This must contains the same number of values as there are points on the PolygonObject.
	/// @return												The mask values.
	//----------------------------------------------------------------------------------------
	Vector PointPolysAverage(Int32 vertex, Vector *values);

	//----------------------------------------------------------------------------------------
	/// Checks if a point is within the drawn fill area.
	/// @note This method is useful in Fill brush tools.
	/// @param[in] p									A point in local space to check.
	/// @return												@trueIfOtherwiseFalse{if the point is within the fill area}
	//----------------------------------------------------------------------------------------
	Bool IsPointInFillArea(const Vector &p);

	//----------------------------------------------------------------------------------------
	/// Returns @formatConstant{true} if this dab is being applied backfacing polygons.
	/// @note Backface polygons will only be sculpted on if the brush has its BackFaceSculpting option enabled and the Backface option is also checked by the user.
	/// @since R17.032
	/// @return												True if the dab is on backfacing polygons.
	//----------------------------------------------------------------------------------------
	Bool IsBackface();
};


//----------------------------------------------------------------------------------------
/// @markPrivate @markInternal
//----------------------------------------------------------------------------------------
class CustomSculptBrushBase
{
	friend class SculptBrushHotkeyCommandData;
private:

	CustomSculptBrushBase();
	~CustomSculptBrushBase();

	_SculptBrushToolBase *m_pBase;

public:

	static CustomSculptBrushBase *Alloc();
	static void Free(CustomSculptBrushBase *&p);

	Bool InitTool(BaseDocument* doc, BaseContainer& data, BaseThread* bt, SculptBrushToolData *tool);
	void FreeTool(BaseDocument* doc, BaseContainer& data, SculptBrushToolData *tool);
	void InitDefaultSettings(BaseDocument *doc, BaseContainer &data, SculptBrushToolData *tool);
	Bool GetDEnabling(BaseDocument* doc, BaseContainer& data, const DescID& id, const GeData& t_data, DESCFLAGS_ENABLE flags, const BaseContainer* itemdesc, SculptBrushToolData *tool);
	Bool SetDParameter(BaseDocument* doc, BaseContainer& data, const DescID& id, const GeData& t_data, DESCFLAGS_SET& flags, SculptBrushToolData *tool);
	Bool GetDDescription(BaseDocument* doc, BaseContainer& data, Description* description, DESCFLAGS_DESC& flags, SculptBrushToolData *tool);
	Bool Message(BaseDocument *doc, BaseContainer &data, Int32 type, void *t_data, SculptBrushToolData *tool);
	Bool TranslateDescID(BaseDocument* doc, BaseContainer& data, const DescID& id, DescID& res_id, C4DAtom*& res_at, SculptBrushToolData *tool);
	Bool GetCursorInfo(BaseDocument* doc, BaseContainer& data, BaseDraw* bd, Float x, Float y, BaseContainer& bc, SculptBrushToolData *tool);
	Bool MouseInput(BaseDocument* doc, BaseContainer& data, BaseDraw* bd, EditorWindow* win, const BaseContainer& msg, SculptBrushToolData *tool);
	Bool KeyboardInput(BaseDocument *doc, BaseContainer &data, BaseDraw *bd, EditorWindow *win, const BaseContainer &msg, SculptBrushToolData *tool);
	Int32 GetState(BaseDocument *doc, SculptBrushToolData *tool);
	TOOLDRAW Draw(BaseDocument *doc, BaseContainer &data, BaseDraw *bd, BaseDrawHelp *bh, BaseThread *bt, TOOLDRAWFLAGS flags, SculptBrushToolData *tool);
	Bool GetDParameter(BaseDocument* doc, BaseContainer& data, const DescID& id, GeData& t_data, DESCFLAGS_GET& flags, SculptBrushToolData *tool);
	Bool DisplayControl(BaseDocument* doc, BaseObject* op, BaseObject* chainstart, BaseDraw* bd, BaseDrawHelp* bh, ControlDisplayStruct& cds, SculptBrushToolData *tool);
	Bool InitDisplayControl(BaseDocument* doc, BaseContainer& data, BaseDraw* bd, const AtomArray* active, SculptBrushToolData *tool);
	void FreeDisplayControl(SculptBrushToolData *tool);

	// Virtual
public:
	void StartStroke(Int32 strokeCount, const BaseContainer &data);
	void StartStrokeInstance(Int32 strokeInstanceID);
	void StartSymmetry();
	void StartStrokeInstanceDabs(Int32 strokeInstanceID);
	void StartDab(Int32 strokeInstanceID);
	void EndDab(Int32 strokeInstanceID);
	void EndStrokeInstanceDabs(Int32 strokeInstanceID);
	void EndSymmetry();
	void EndStrokeInstance(Int32 strokeInstanceID);
	void EndStroke();
	void MouseData(Int32 strokeInstanceID, const BaseContainer &brushData, const SculptMouseData &md);

	void OverwriteLoadedPresetSettings(BaseContainer &data);
	void PostInitDefaultSettings(BaseDocument *doc, BaseContainer &data);
	Bool GetEnabling(Int32 id);
	Bool HandleFillTool(BaseDocument* doc, BaseContainer& data, BaseDraw* bd, EditorWindow* win, const BaseContainer& msg);
	Bool HandleNonModelPickMode(BaseDocument* doc, BaseContainer& data, BaseDraw* bd, EditorWindow* win, const BaseContainer& msg);
	Bool DrawNonModelPickMode(BaseDocument *doc, BaseContainer &data, BaseDraw *bd, BaseDrawHelp *bh, BaseThread *bt, TOOLDRAWFLAGS flags);
	void FloodSelectedLayer(SculptObject *pSculpt, SculptLayer *pLayer, const BaseContainer& brushData, Int32 function, Bool preview, Float *customStrength = nullptr, const Vector32 *pVertexNormals = nullptr);
	void FloodSelectedLayerWithChannel(SculptObject *pSculpt, SculptLayer *pLayer, const BaseContainer& brushData, Int32 function, BaseChannel *pChannel, Bool preview, Float *customStrength = nullptr, const Vector32 *pVertexNormals = nullptr);
	void FloodSelectedLayerWithBitmap(SculptObject *pSculpt, SculptLayer *pLayer, const BaseContainer& brushData, Int32 function, BaseBitmap *pBitmap, Bool preview, Float *customStrength = nullptr, const Vector32 *pVertexNormals = nullptr);
	Bool HasDrawMode(Int32 mode);

	// Non Virtual
public:
	Bool Flood(BaseDocument* doc, BaseDraw* bd, const BaseContainer& brushData, Int32 button = MDATA_SCULPTBRUSH_SETTINGS_FLOOD);
	Bool FloodWithChannel(BaseDocument* doc, BaseDraw* bd, const BaseContainer& brushData, BaseChannel *pChannel, Int32 button = MDATA_SCULPTBRUSH_SETTINGS_FLOOD);
	Bool FloodWithBitmap(BaseDocument* doc, BaseDraw* bd, const BaseContainer& brushData, BaseBitmap *pBitmap, Int32 button = MDATA_SCULPTBRUSH_SETTINGS_FLOOD);
	void EnableSpecialDrawGizmo();
	void DisableSpecialDrawGizmo();
	void SetMouseDrag(Bool value);
	Bool IsMouseDrag();
	void CacheObjects(BaseDocument *doc);
	Int32 GetSelectionCacheCount();
	BaseList2D *GetSelectionCacheObject(Int32 index);
	Float GetBrushStrength(Bool original);
	void InitZoomScale(BaseDocument *doc);
	Bool HasModifier();
	Bool HasRespectSelections();

	// Methods called by the Preset System
	Bool WritePresetData(HyperFile *hf);
	Bool ReadPresetData(HyperFile *hf, Int32 level);
	Bool WriteStampPresetData(HyperFile *hf);
	Bool ReadStampPresetData(HyperFile *hf, Int32 level);
	Bool WriteSplinePresetData(HyperFile *hf);
	Bool ReadSplinePresetData(HyperFile *hf, Int32 level);
	void UpdateSettingsAfterPresetLoad(BaseContainer *data);
	void UpdateStencilAfterPresetLoad(BaseContainer *data);

	const BaseBitmap *GetStamp();
	const BaseBitmap *GetStencil();
};

//----------------------------------------------------------------------------------------
/// The parameters to pass in when registering a sculpt brush.
/// @code
/// SculptBrushParams* pParams = SculptBrushParams::Alloc();
/// RegisterToolPlugin(MY_BRUSH_ID, "MyBrushName", PLUGINFLAG_HIDEPLUGINMENU|PLUGINFLAG_TOOL_SCULPTBRUSH|PLUGINFLAG_TOOL_NO_OBJECTOUTLINE, nullptr, "MyBrushHelpText", NewObjClear(MySculptBrush,pParams));
/// @endcode
/// By default the .res file includes the tabs for Stamps and Stencils and the options for Size, Pressure, Steady Stroke, Spacing and the Draw Modes.\n
/// If any of these options are need then hide them in the .res file by adding the following lines to the top of it:
/// @code
/// CONTAINER toolmysculptbrush
/// {
///		NAME toolmysculptbrush;
///		INCLUDE toolsculptbrushbase;
///
///		HIDE MDATA_SCULPTBRUSH_STAMP_GROUP;									// Setting EnableStamp(false) will also remove the Stamp Tab
///		HIDE MDATA_SCULPTBRUSH_STENCIL_GROUP;								// Setting EnableStencil(false) will also remove the Stencil Tab
///		HIDE MDATA_SCULPTBRUSH_SETTINGS_RADIUS;							// This is Size
///		HIDE MDATA_SCULPTBRUSH_SETTINGS_RADIUS_MOD;					// This is the FX option for Size.
///		HIDE MDATA_SCULPTBRUSH_SETTINGS_STRENGTH;						// This is Pressure
///		HIDE MDATA_SCULPTBRUSH_SETTINGS_STRENGTH_MOD;				// This is the FX option for Pressure.
///		HIDE MDATA_SCULPTBRUSH_SETTINGS_STEADYSTROKE;
///		HIDE MDATA_SCULPTBRUSH_SETTINGS_STEADYSTROKE_VALUE;
///		HIDE MDATA_SCULPTBRUSH_SETTINGS_STAMPSPACING;
///		HIDE MDATA_SCULPTBRUSH_SETTINGS_STAMPSPACING_VALUE;
///		HIDE MDATA_SCULPTBRUSH_SETTINGS_DRAWMODE;
///		HIDE MDATA_SCULPTBRUSH_SETTINGS_FILL_BACKFACES;
///		HIDE MDATA_SCULPTBRUSH_SETTINGS_DRAWMODE_FILL_SYMMETRY;
/// }
/// @endcode
/// By Default the Draw Modes that are available are Freehand, Line, Lasso Fill, Polygon Fill and Rectangle Fill.\n
/// To remove any of these or add more, customize the list. Here is an example below where support is added for all the different modes, including DragDab and DragRect.\n
/// Just remove any from this list to suit the brush. By default Freehand is set, so if the Draw Mode is hidden the brush will still work.
/// @code
/// CONTAINER toolmysculptbrush
///	{
///		NAME toolmysculptbrush;
///		INCLUDE toolsculptbrushbase;
///
///		GROUP MDATA_SCULPTBRUSH_SETTINGS_GROUP
///		{
///			COLUMNS 3;
///
///			GROUP
///			{
///				COLUMNS 3;
///				LONG MDATA_SCULPTBRUSH_SETTINGS_DRAWMODE
///				{
///					CYCLE
///					{
///						MDATA_SCULPTBRUSH_SETTINGS_DRAWMODE_FREEHAND;
///						MDATA_SCULPTBRUSH_SETTINGS_DRAWMODE_DRAGRECT;
///						MDATA_SCULPTBRUSH_SETTINGS_DRAWMODE_DRAGDAB;
///						MDATA_SCULPTBRUSH_SETTINGS_DRAWMODE_LINE;
///						MDATA_SCULPTBRUSH_SETTINGS_DRAWMODE_LASSO_FILL;
///						MDATA_SCULPTBRUSH_SETTINGS_DRAWMODE_POLY_FILL;
///						MDATA_SCULPTBRUSH_SETTINGS_DRAWMODE_RECTANGLE_FILL;
///					}
///				}
///				BOOL MDATA_SCULPTBRUSH_SETTINGS_DRAWMODE_FILL_SYMMETRY { }
///				BOOL MDATA_SCULPTBRUSH_SETTINGS_FILL_BACKFACES { }
///			}
///			STATICTEXT { JOINENDSCALE; }
///			STATICTEXT { JOINEND; }
///		}
/// }
/// @endcode
/// Also make sure the priority for any sculpting plugins are set correctly. Sculpt brush plugins need to be loaded @b after the main sculpting plugin.\n
/// To ensure this set the priority in @ref PluginMessage(Int32 id, void *data) as shown below:
/// @code
/// Bool PluginMessage(Int32 id, void *data)
/// {
///		switch (id)
///		{
///			case C4DPL_INIT_SYS:
///				if (!g_resource.Init()) return false;
///				return true;
///			case C4DMSG_PRIORITY:
///				SetPluginPriority(data, C4DPL_INIT_PRIORITY_MODULES+1);
///				return true;
///		}
///		return false;
/// }
/// @endcode
//----------------------------------------------------------------------------------------
class SculptBrushParams
{
private:
	SculptBrushParams();
	~SculptBrushParams();

public:

	/// @name Alloc/Free
	/// @{

	//----------------------------------------------------------------------------------------
	/// @allocatesA{SculptBrushParams object}
	/// @return												@allocReturn{SculptBrushParams object}
	//----------------------------------------------------------------------------------------
	static SculptBrushParams *Alloc();

	//----------------------------------------------------------------------------------------
	/// @destructsAlloc{SculptBrushParams objects}
	/// @param[in,out] params					@theToDestruct{SculptBrushParams object}
	//----------------------------------------------------------------------------------------
	static void Free(SculptBrushParams *&params);

	/// @}

	/// @name Enable Methods
	/// @{

	//----------------------------------------------------------------------------------------
	/// Enables/disables stencils in the brush.
	/// @note	Setting to @formatConstant{false} frees up some resource and computation time.\n
	///				Setting to @formatConstant{false} also removes the tab from the brush interface.
	/// @param[in] enable							@formatConstant{true} if the brush uses stencils, @formatConstant{false} if not. Default is @formatConstant{true}.
	//----------------------------------------------------------------------------------------
	void EnableStencil(Bool enable);

	//----------------------------------------------------------------------------------------
	/// Enables/disables stamps in the brush.
	/// @note	Setting to @formatConstant{false} frees up some resource and computation time.\n
	///				Setting to @formatConstant{false} also removes the tab from the brush interface.
	/// @param[in] enable							@formatConstant{true} if the brush uses stamps, @formatConstant{false} if not. Default is @formatConstant{true}.
	//----------------------------------------------------------------------------------------
	void EnableStamp(Bool enable);

	//----------------------------------------------------------------------------------------
	/// Enables/disables the Invert checkbox in the brush.
	/// @note By default the invert checkbox is not part of the base .res file so add it manually:
	/// @code
	/// GROUP MDATA_SCULPTBRUSH_SETTINGS_GROUP
	/// {
	///		COLUMNS 3;
	///
	///		BOOL MDATA_SCULPTBRUSH_SETTINGS_INVERT { }
	///		STATICTEXT { DUMMY; }
	///		STATICTEXT { DUMMY; }
	///	}
	/// @endcode
	/// @param[in] enable							@formatConstant{true} if the brush uses the Invert checkbox, @formatConstant{false} if not. Default is @formatConstant{false}.
	//----------------------------------------------------------------------------------------
	void EnableInvertCheckbox(Bool enable);

	//----------------------------------------------------------------------------------------
	/// Enables/disables the Buildup slider in the brush.
	/// @note By default the Buildup slider is not part of the base .res file so to add it manually:
	/// @code
	/// GROUP MDATA_SCULPTBRUSH_SETTINGS_GROUP
	/// {
	///		COLUMNS 3;
	///
	///		REAL MDATA_SCULPTBRUSH_SETTINGS_BUILDUP { MIN 1; MAX 100; MINSLIDER 1; MAXSLIDER 100; CUSTOMGUI REALSLIDER; FIT_H; SCALE_H; }
	///		STATICTEXT { JOINENDSCALE; }
	///		STATICTEXT { JOINEND; }
	///	}
	/// @endcode
	/// @param[in] enable							@formatConstant{true} if the brush uses the Buildup slider, @formatConstant{false} if not. Default is @formatConstant{false}.
	//----------------------------------------------------------------------------------------
	void EnableBuildup(Bool enable);

	//----------------------------------------------------------------------------------------
	/// Enables/disables non model pick mode, i.e. the brush do anything if the user clicks-off of a model: SculptBrushToolData::HandleNonModelPickMode and SculptBrushToolData::DrawNonModelPickMode are implemented.
	/// @param[in] enable							@formatConstant{true} if SculptBrushToolData::HandleNonModelPickMode and SculptBrushToolData::DrawNonModelPickMode are implemented, @formatConstant{false} if not. Default is @formatConstant{false}.
	//----------------------------------------------------------------------------------------
	void EnableNonModelPickMode(Bool enable);

	//----------------------------------------------------------------------------------------
	/// Enables/disables the Flood function in the brush: SculptBrushToolData::FloodSelectedLayer is implemented.
	/// @note By default the Flood button is not part of the base .res file so add it manually:
	/// @code
	/// GROUP MDATA_SCULPTBRUSH_SETTINGS_GROUP
	/// {
	///		COLUMNS 3;
	///
	///		BUTTON MDATA_SCULPTBRUSH_SETTINGS_FLOOD{ }
	///		STATICTEXT { JOINENDSCALE; }
	///		STATICTEXT { JOINEND; }
	///	}
	/// @endcode
	/// @param[in] enable							@formatConstant{true} if SculptBrushToolData::FloodSelectedLayer is implemented, @formatConstant{false} if not. Default is @formatConstant{false}.
	//----------------------------------------------------------------------------------------
	void EnableFlood(Bool enable);

	//----------------------------------------------------------------------------------------
	/// Enables/disables multithreading for the brush. @markPrivate
	/// @warning Never enable multithreading!
	///
	/// Tells the system that the brush can be multithreaded. If @formatConstant{true} then the dabs are distributed over multiple threads and are drawn in any order.\n
	/// Any calls to the @c MovePointFunc could now be for any stroke instance and could be out of order and from different threads.
	/// @param[in] enable							@formatConstant{true} if the brush multithreaded, @formatConstant{false} if not. Default is @formatConstant{false}.
	//----------------------------------------------------------------------------------------
	void EnableMultiThreading(Bool enable);

	//----------------------------------------------------------------------------------------
	/// Enables/disables getting access to the brush via dab->GetBrush().
	/// @param[in] enable							@formatConstant{true} if access to the brush is needed, @formatConstant{false} if not. Default is @formatConstant{false}.
	//----------------------------------------------------------------------------------------
	void EnableBrushAccess(Bool enable);

	//----------------------------------------------------------------------------------------
	/// Enables/disables the brush own smooth operation that gets used when the @em Shift key is pressed.
	/// @note Check for this in the @c MovePointFunc method if <tt>(GetBrushOverride() & OVERRIDE::SMOOTHTOOL)</tt> is @formatConstant{true} and then implement the custom smooth method.
	/// Otherwise it will use the Smooth Brush for smoothing.
	/// @param[in] enable							@formatConstant{true} if the brush handles smoothing, @formatConstant{false} if not. Default is @formatConstant{false}.
	//----------------------------------------------------------------------------------------
	void EnableToolSpecificSmooth(Bool enable);

	//----------------------------------------------------------------------------------------
	/// Tells the system that the brush can use modifiers from other brushes (display the Modifiers tab).
	/// @param[in] enable							@formatConstant{true} if the brush wants to be able to use modifiers from other brushes.
	//----------------------------------------------------------------------------------------
	void EnableModifier(Bool enable);

	//----------------------------------------------------------------------------------------
	/// Enables/disables Python for the brush. @markPrivate
	/// @warning Never enable for a C++ plugin!
	/// This is only ever used internally by Python brushes. When enabled it routes the calls to SculptBrushToolData::ApplyPythonDab.\n
	/// All calls are only ever single threaded with no access to the brush data.
	//----------------------------------------------------------------------------------------
	void EnablePython(Bool enable);

	//----------------------------------------------------------------------------------------
	/// When enabled the Draw Direction UI will appear in the Settings tab.\n
	/// Calls can then be made to GetDrawDirectionNormal() to get the direction of the normal based on the currently selected Draw Direction.
	/// @param[in] enable							@formatConstant{true} to display the Draw Direction UI options. Disabled by default.
	//----------------------------------------------------------------------------------------
	void EnableDrawDirection(Bool enable);

	//----------------------------------------------------------------------------------------
	/// Enables/disables call to SculptBrushToolData::GetCustomData to change the stamp before a dab is drawn.
	/// @note <tt>EnableBrushAccess(@formatConstant{true})</tt> must also be set.
	/// @param[in] enable							@formatConstant{true} if the brush has a custom stamp, @formatConstant{false} if not. Default is @formatConstant{false}.
	//----------------------------------------------------------------------------------------
	void EnableCustomStamp(Bool enable);

	//----------------------------------------------------------------------------------------
	/// Enables/disables the brush to respect Point and Polygon selections when in Point or Polygon mode respectively.
	/// @param[in] enable							@formatConstant{true} if the brush should respect selections, @formatConstant{false} if not. Default is @formatConstant{false}.
	//----------------------------------------------------------------------------------------
	void EnableRespectSelections(Bool enable);

	//----------------------------------------------------------------------------------------
	/// Enables/disables the Fill algorithm to remove any isolated points. That is any points that are selected but have no neighboring selections.\n
	/// This can happen on high resolution meshes due to the nature of the hit detection against screen space pixels defined by the fill tools.\n
	/// By setting to @formatConstant{false} it keeps any isolated points that are selected. This is @formatConstant{true} by default so isolated points are removed before being sent to the @c MovePointFunc function.
	/// @param[in] enable							@formatConstant{true} if the brush should remove isolated points, @formatConstant{false} if it should keep them. Default is @formatConstant{true}.
	//----------------------------------------------------------------------------------------
	void EnableFillToolIsolatedPointRemover(Bool enable);

	//----------------------------------------------------------------------------------------
	/// Enables/disables displaying the pressure value in the sculpting size/pressure HUD.
	/// @param[in] enable							@formatConstant{true} if the brush should display the pressure value, @formatConstant{false} if not. Default is @formatConstant{true}.
	//----------------------------------------------------------------------------------------
	void EnablePressureHUD(Bool enable);

	//----------------------------------------------------------------------------------------
	/// Enables/disables the callback for the MouseData method.
	/// @since R17.032
	/// @param[in] enable							@formatConstant{true} if you need the MouseData callback, @formatConstant{false} if not. Default is @formatConstant{false}.
	//----------------------------------------------------------------------------------------
	void EnableMouseData(Bool enable);

	//----------------------------------------------------------------------------------------
	/// Tells the system that this brush supports backface sculpting and that the Backface option should be displayed in the brushes settings.
	/// @since R17.032
	/// @param[in] enable							@formatConstant{true} if the brush supports backface sculpting, @formatConstant{false} if not. Default is @formatConstant{false}.
	//----------------------------------------------------------------------------------------
	void EnableBackfaceSculpting(Bool enable);

	/// @}

	/// @name Set Methods
	/// @{

	//----------------------------------------------------------------------------------------
	/// Specifies what kind of data the Flood operation will change (points or mask).
	/// @param[in] type								The flood data type. Default is @ref SCULPTBRUSHDATATYPE::POINT.
	//----------------------------------------------------------------------------------------
	void SetFloodType(SCULPTBRUSHDATATYPE type);

	//----------------------------------------------------------------------------------------
	/// Specifies the type of brush (grab or normal).
	/// @param[in] mode								The brush mode. Default is @ref SCULPTBRUSHMODE::NORMAL.
	//----------------------------------------------------------------------------------------
	void SetBrushMode(SCULPTBRUSHMODE mode);

	//----------------------------------------------------------------------------------------
	/// Specifies what should happen when the user first clicks on model before dragging.
	/// @param[in] type								The first hit point type. Default is @ref FIRSTHITPPOINTTYPE::SELECTED.
	//----------------------------------------------------------------------------------------
	void SetFirstHitPointType(FIRSTHITPPOINTTYPE type);

	//----------------------------------------------------------------------------------------
	/// Specifies what kind of data the brush changes and stores in the undo system (point or mask).
	/// @param[in] type								The brush data type. Default is @ref SCULPTBRUSHDATATYPE::POINT.
	//----------------------------------------------------------------------------------------
	void SetUndoType(SCULPTBRUSHDATATYPE type);

	//----------------------------------------------------------------------------------------
	/// Sets which flags should be checked to do a rebuild of the collision structure for a PolygonObject.\n
	/// These flags are used to check against the PolygonObjects dirty flags when a stroke is about to be done on a PolygonObject.\n
	/// If the flags being checked are dirty since the last check then the collision cache structure for the object will be rebuilt.\n
	/// This can be used in cases such as the Select Brush where you are not directly moving the points of the model during a stroke.\n
	/// So you can set all the flags except the @ref DIRTYFLAGS::SELECT (using something like @c (DIRTYFLAGS::ALL & ~DIRTYFLAGS::SELECT)
	/// to ensure that the object is not recalculated when just the select flags are changed.\n
	/// In all other cases the object will be rebuilt.
	/// @since R17.032
	/// @param[in] flags							The dirty flags to check. By default this is set to @ref DIRTYFLAGS::ALL.
	//----------------------------------------------------------------------------------------
	void SetPolygonObjectDirtyFlags(DIRTYFLAGS flags);

	//----------------------------------------------------------------------------------------
	/// A pointer to the static method that is called to modify the SculptObject.\n
	/// The @c MovePointFunc method must be implemented and passed like the following:
	/// @code
	/// class MySculptBrush : public SculptBrushToolData
	/// {
	///		public:
	///		MySculptBrush(SculptBrushParams *pParams) : SculptBrushToolData(pParams) { }
	///		virtual Int32 GetToolPluginId();									// Return the unique id for the plugin as obtained from www.plugincafe.com
	///		virtual const String GetResourceSymbol();					// Return the name of the resource file for the brush.
	///																											// This is something like "toolmysculptbrush", where the resource file is "toolmysculptbrush.res".
	///
	///		static Bool MovePointFunc(BrushDabData *dab);			// This is the static implementation for the MovePointFunc
	/// };
	///
	/// // Declare the MovePointFunc method
	///	Bool MySculptBrush::MovePointFunc(BrushDabData *dab)
	/// {
	///		// Implement the functionality of the brush here
	///		return true;
	/// }
	///
	/// //Then pass it into the parameters method like
	/// pParams->SetMovePointFunc(&MySculptBrush::MovePointFunc);
	/// @endcode
	/// @param[in] surfaceMovePointFunc	The static method to call for each brush dab.
	//----------------------------------------------------------------------------------------
	void SetMovePointFunc(Bool (*surfaceMovePointFunc)(BrushDabData *dab));

	/// @}
};


//----------------------------------------------------------------------------------------
/// A data class for creating sculpt brush plugins.\n
/// Use RegisterToolPlugin() with @ref PLUGINFLAG_TOOL_SCULPTBRUSH to register a sculpt brush plugin.
/// @code
/// class MySculptBrush : public SculptBrushToolData
/// {
///		public:
///		MySculptBrush(SculptBrushParams *pParams) : SculptBrushToolData(pParams) { }
///		virtual Int32 GetToolPluginId();									// Return the unique ID for the plugin as obtained from www.plugincafe.com
///		virtual const String GetResourceSymbol();					// Return the name of for resource file for for brush.
///																											/// This is something like "toolmysculptbrush", where the resource file is called "toolmysculptbrush.res"
///
///		static Bool MovePointFunc(BrushDabData *dab);			// This is the static implementation for the MovePointFunc
/// };
///
/// Bool RegisterMyBrush()
/// {
///		SculptBrushParams *pParams = SculptBrushParams::Alloc();
///		return RegisterToolPlugin(MY_BRUSH_ID,"BrushName", PLUGINFLAG_HIDEPLUGINMENU|PLUGINFLAG_TOOL_SCULPTBRUSH|PLUGINFLAG_TOOL_NO_OBJECTOUTLINE, nullptr, "MyBrushHelpText", NewObjClear(MySculptBrush, pParams));
/// }
/// @endcode
//----------------------------------------------------------------------------------------
class SculptBrushToolData : public DescriptionToolData
{
	INSTANCEOF(SculptBrushToolData, DescriptionToolData)

public:

	//----------------------------------------------------------------------------------------
	/// Constructor.
	//----------------------------------------------------------------------------------------
	explicit SculptBrushToolData(SculptBrushParams *pParams) :m_pParams(pParams), m_pBrushBase(nullptr) { }

	//----------------------------------------------------------------------------------------
	/// Destructor.
	//----------------------------------------------------------------------------------------
	~SculptBrushToolData()
	{
		CustomSculptBrushBase::Free(m_pBrushBase);
		SculptBrushParams::Free(m_pParams);
	}

	SculptBrushParams *m_pParams;
	CustomSculptBrushBase *m_pBrushBase;

	/// @name ToolData/DescriptionToolData Overrides
	/// @{

	//----------------------------------------------------------------------------------------
	/// If this method is overridden then make sure to call directly @c SculptBrushToolData::InitTool(doc, data, bt) at the start and check that it returns @formatConstant{true}.
	//----------------------------------------------------------------------------------------
	virtual Bool InitTool(BaseDocument* doc, BaseContainer& data, BaseThread* bt);

	//----------------------------------------------------------------------------------------
	/// If this method is overridden then make sure to call @c SculptBrushToolData::FreeTool(doc, data) at the end.
	//----------------------------------------------------------------------------------------
	virtual void FreeTool(BaseDocument* doc, BaseContainer& data);

	//----------------------------------------------------------------------------------------
	/// If this method is overridden then make sure to call directly @c SculptBrushToolData::InitDefaultSettings(doc, data) at the start.
	//----------------------------------------------------------------------------------------
	virtual void InitDefaultSettings(BaseDocument *doc, BaseContainer &data);

	//----------------------------------------------------------------------------------------
	/// If this method is overridden then make sure to call @c SculptBrushToolData::GetDEnabling(doc, data, id, t_data, flags, itemdesc) at the end.
	//----------------------------------------------------------------------------------------
	virtual Bool GetDEnabling(BaseDocument* doc, BaseContainer& data, const DescID& id, const GeData& t_data, DESCFLAGS_ENABLE flags, const BaseContainer* itemdesc);

	//----------------------------------------------------------------------------------------
	/// If this method is overridden then make sure to call directly @c SculptBrushToolData::SetDParameter(doc, data, id, t_data, flags) at the start.
	//----------------------------------------------------------------------------------------
	virtual Bool SetDParameter(BaseDocument* doc, BaseContainer& data, const DescID& id, const GeData& t_data, DESCFLAGS_SET& flags);

	//----------------------------------------------------------------------------------------
	/// If this method is overridden then make sure to call directly @c SculptBrushToolData::GetDDescription(doc, data, description, flags) at the start.
	//----------------------------------------------------------------------------------------
	virtual Bool GetDDescription(BaseDocument* doc, BaseContainer& data, Description* description, DESCFLAGS_DESC& flags);

	//----------------------------------------------------------------------------------------
	/// If this method is overridden then make sure to call @c SculptBrushToolData::Message(doc, data, type, t_data) at the end.
	//----------------------------------------------------------------------------------------
	virtual Bool Message(BaseDocument *doc, BaseContainer &data, Int32 type, void *t_data);

	//----------------------------------------------------------------------------------------
	/// If this method is overridden then make sure to call directly @c SculptBrushToolData::TranslateDescID(doc, data, type, t_data) at the start and return if it is @formatConstant{true}.
	//----------------------------------------------------------------------------------------
	virtual Bool TranslateDescID(BaseDocument* doc, BaseContainer& data, const DescID& id, DescID& res_id, C4DAtom*& res_at);

	//----------------------------------------------------------------------------------------
	/// If this method is overridden then make sure to call @c SculptBrushToolData::GetCursorInfo(doc, data, x, y, bc) at the end.
	//----------------------------------------------------------------------------------------
	virtual Bool GetCursorInfo(BaseDocument* doc, BaseContainer& data, BaseDraw* bd, Float x, Float y, BaseContainer& bc);

	//----------------------------------------------------------------------------------------
	/// If this method is overridden then make sure to call directly @c SculptBrushToolData::MouseInput(doc, data, bd, win, msg) at the end.
	//----------------------------------------------------------------------------------------
	virtual Bool MouseInput(BaseDocument* doc, BaseContainer& data, BaseDraw* bd, EditorWindow* win, const BaseContainer& msg);

	//----------------------------------------------------------------------------------------
	/// If this method is overridden then make sure to call @c SculptBrushToolData::KeyboardInput(doc, data, bd, win, msg) at the end.
	//----------------------------------------------------------------------------------------
	virtual Bool KeyboardInput(BaseDocument *doc, BaseContainer &data, BaseDraw *bd, EditorWindow *win, const BaseContainer &msg);

	//----------------------------------------------------------------------------------------
	/// If this method is overridden then make sure to call @c SculptBrushToolData::Draw(doc, data, bd, bh, bt, flags) at the end.
	//----------------------------------------------------------------------------------------
	virtual TOOLDRAW Draw(BaseDocument *doc, BaseContainer &data, BaseDraw *bd, BaseDrawHelp *bh, BaseThread *bt, TOOLDRAWFLAGS flags);

	//----------------------------------------------------------------------------------------
	/// If this method is overridden then make sure to call @c SculptBrushToolData::GetDParameter(doc, data, id, t_data, flags) at the end.
	//----------------------------------------------------------------------------------------
	virtual Bool GetDParameter(BaseDocument* doc, BaseContainer& data, const DescID& id, GeData& t_data, DESCFLAGS_GET& flags);

	//----------------------------------------------------------------------------------------
	/// If this method is overridden then make sure to call @c SculptBrushToolData::DisplayControl(doc, op, chainstart, bd, bh, cds) at the end.
	//----------------------------------------------------------------------------------------
	virtual Bool DisplayControl(BaseDocument* doc, BaseObject* op, BaseObject* chainstart, BaseDraw* bd, BaseDrawHelp* bh, ControlDisplayStruct& cds);

	//----------------------------------------------------------------------------------------
	/// If this method is overridden then make sure to call @c SculptBrushToolData::InitDisplayControl(doc, data, bd, active) at the end.
	//----------------------------------------------------------------------------------------
	virtual Bool InitDisplayControl(BaseDocument* doc, BaseContainer& data, BaseDraw* bd, const AtomArray* active);

	//----------------------------------------------------------------------------------------
	/// If this method is overridden then make sure to call @c SculptBrushToolData::FreeDisplayControl() at the end.
	//----------------------------------------------------------------------------------------
	virtual void FreeDisplayControl(void);

	//----------------------------------------------------------------------------------------
	/// Indicates if the brush is active or not (grayed out in the interface).\n
	/// If this method is overridden then make sure to call @c SculptBrushToolData::GetState(doc) at the end.
	//----------------------------------------------------------------------------------------
	virtual Int32 GetState(BaseDocument *doc);

	/// @}

	/// @name Brushes Methods to Override
	/// @{

	//----------------------------------------------------------------------------------------
	/// Called once at the start of the stroke.\n
	/// It passes the total number of instances of the brush that is to be drawn. The number of instances will change depending on the symmetry mirroring and radial settings.
	///
	/// Use this method to setup any data on the brush that might be accessed from within the @c MovePointFunc method via the @c dab->GetBrush() method.
	///
	/// @note This method will only be called if @ref SculptBrushParams::EnableBrushAccess(@formatConstant{true}) has been set.
	///
	/// Calling order for brush stroke virtual methods:
	/// - StartStroke(): Called once at the start of the stroke
	///		- StartStrokeInstance(): Called for each instance of a stroke. Use this to initialize any data needed for the duration of the entire brush stroke.
	///			- StartSymmetry(): Called once before all the instances are about to be drawn for a small mouse movement. This will be called @b many times during a stroke as the mouse moves over the model.
	///				- StartStrokeInstanceDabs(): Called once before a bunch of consecutive dabs will be draw for a single instance (mirrored brush).
	///					- StartDab(): Called for each dab that needs to be drawn between @em 2 mouse locations on the object for a single brush stroke instance
	///						- The static method @c MovePointFunc gets called to process the dab.
	///					- EndDab()
	///				- EndStrokeInstanceDabs()
	///			- EndSymmetry(): Called once when all symmetrical strokes have finished.
	///		- EndStrokeInstance(): Called for each instance of a stroke that was used.
	///	- EndStroke()
	///
	/// When multithreading is enabled for the brush then this method can be used to allocate data for each stroke instance.\n
	/// Each instance or dab can then safely read from this data during a brush stroke. This will only be done once at mouse down.
	/// @param[in] strokeCount				Number of instances of the brush that will be drawn.
	/// @param[in] data								The BaseContainer data for the brush.
	//----------------------------------------------------------------------------------------
	virtual void StartStroke(Int32 strokeCount, const BaseContainer &data);

	//----------------------------------------------------------------------------------------
	/// Called after StartStroke(). This is called once for each brush instance at the start of a stroke.
	/// The number of instances changes depending on the symmetry mirroring and radial settings.\n
	///
	/// Use this method to allocate any data accessed during a brush stroke, that may be specific for each individual instance.\n
	/// Setup also any data on the brush that might be accessed from within the @c MovePointFunc method via the @c dab->GetBrush() method.\n
	/// When multithreading is enabled for the brush then this method can be used to initialize data for each stroke instance. This will only be done once at mouse down.
	///
	/// @note This method will only be called if @ref SculptBrushParams::EnableBrushAccess(@formatConstant{true}) has been set.
	/// @param[in] strokeInstanceID		The ID of the brush instance being drawn.
	//----------------------------------------------------------------------------------------
	virtual void StartStrokeInstance(Int32 strokeInstanceID);

	//----------------------------------------------------------------------------------------
	/// Called directly before each individual brush instance is about to be handled.\n
	/// Between StartSymmetry() and EndSymmetry() all the dabs for each instance are drawn from one mouse location on the surface of the model to another.\n
	/// This method will be called every time the user moves the mouse over the object on the screen to indicate that a new batch of dabs is going to be drawn.
	///
	/// Use this method to setup any data on the brush that might be accessed from within the @c MovePointFunc method via the @c dab->GetBrush() method.\n
	/// When multithreading is enabled for the brush then this method can be used to reset any data required for each instance.\n
	/// Between StartSymmetry() and EndSymmetry() the dabs could now be drawn out or order by different threads so no data should be allocated or changed between these @em 2 calls.
	///
	/// @note This method will only be called if @ref SculptBrushParams::EnableBrushAccess(@formatConstant{true}) has been set.
	//----------------------------------------------------------------------------------------
	virtual void StartSymmetry();

	//----------------------------------------------------------------------------------------
	/// Called before all the dabs for a single instance are about to be drawn.\n
	/// After this call all the dabs for just one instance of the brush on the surface will interpolate between the @em 2 mouse locations on the object then draw all the dabs for that instance.
	///
	/// Use this method to setup any data on the brush that might be accessed from within the @c MovePointFunc method via the @c dab->GetBrush() method.\n
	/// When multithreading is enabled no data should be changed on the brush.
	///
	/// @note This method will only be called if @ref SculptBrushParams::EnableBrushAccess(@formatConstant{true}) has been set.
	/// @param[in] strokeInstanceID		The ID of the brush instance being drawn.
	//----------------------------------------------------------------------------------------
	virtual void StartStrokeInstanceDabs(Int32 strokeInstanceID);

	//----------------------------------------------------------------------------------------
	/// Called before the @c MovePointFunc method is called which will then process the dab.
	///
	/// Use this method to setup any data on the brush that might be accessed from within the @c MovePointFunc method via the @c dab->GetBrush() method.\n
	/// When multithreading is enabled no data should be changed on the brush.
	///
	/// @note This method will only be called if @ref SculptBrushParams::EnableBrushAccess(@formatConstant{true}) has been set.
	/// @param[in] strokeInstanceID		The ID of the brush instance being drawn.
	//----------------------------------------------------------------------------------------
	virtual void StartDab(Int32 strokeInstanceID);

	//----------------------------------------------------------------------------------------
	/// Called after the @c MovePointFunc method is called.
	/// @note This method will only be called if @ref SculptBrushParams::EnableBrushAccess(@formatConstant{true}) has been set.
	/// @param[in] strokeInstanceID		The ID of the brush instance being drawn.
	//----------------------------------------------------------------------------------------
	virtual void EndDab(Int32 strokeInstanceID);

	//----------------------------------------------------------------------------------------
	/// Called after all the dabs have been drawn for a single instance of the brush.
	/// @note This method will only be called if @ref SculptBrushParams::EnableBrushAccess(@formatConstant{true}) has been set.
	/// @param[in] strokeInstanceID		The ID of the brush instance being drawn.
	//----------------------------------------------------------------------------------------
	virtual void EndStrokeInstanceDabs(Int32 strokeInstanceID);

	//----------------------------------------------------------------------------------------
	/// Called after all the dabs for all the instances have been drawn for a single mouse movement on screen.\n
	/// If multithreading is enabled then reset any data for each instance from this method and be ready for the next set of dabs.
	/// @note This method will only be called if @ref SculptBrushParams::EnableBrushAccess(@formatConstant{true}) has been set.
	//----------------------------------------------------------------------------------------
	virtual void EndSymmetry();

	//----------------------------------------------------------------------------------------
	/// Called on mouse up after a brush stroke. This method is called once for each instance.
	///
	/// Use this method to delete any temporary data that was allocated in the StartStrokeInstance() method.\n
	/// If multithreading is enabled then reset any data allocated for each brush instance from within this method.
	///
	/// @note This method will only be called if @ref SculptBrushParams::EnableBrushAccess(@formatConstant{true}) has been set.
	/// @param[in] strokeInstanceID		The ID of the brush instance being drawn.
	//----------------------------------------------------------------------------------------
	virtual void EndStrokeInstance(Int32 strokeInstanceID);

	//----------------------------------------------------------------------------------------
	/// Called on mouse up after EndStrokeInstance() has been called for each instance.\n
	/// If multithreading was enabled then free any data allocated for each brush instance.
	/// @note This method will only be called if @ref SculptBrushParams::EnableBrushAccess(@formatConstant{true}) has been set.
	//----------------------------------------------------------------------------------------
	virtual void EndStroke();

	//----------------------------------------------------------------------------------------
	/// Constantly receives data about the object underneath the mouse. This method will get called when you move the cursor over an object on screen and happens when the mouse button is up or down.
	/// @note This method will only be called if @ref SculptBrushParams::EnableMouseData(@formatConstant{true}) has been set.
	/// @since R17.032
	/// @param[in] strokeInstanceID		The ID of the brush instance.
	/// @param[in] brushData					The BaseContainer data for the brush.
	/// @param[in] md									The SculptMouseData for the current position of the mouse on the surface of the object.
	//----------------------------------------------------------------------------------------
	virtual void MouseData(Int32 strokeInstanceID, const BaseContainer& brushData, const SculptMouseData& md);

	//----------------------------------------------------------------------------------------
	/// Called after a preset has been loaded to allow the brush to disable or change any of the loaded settings if required.
	/// @param[in] data								The container with the settings for the loaded brush.
	//----------------------------------------------------------------------------------------
	virtual void OverwriteLoadedPresetSettings(BaseContainer &data);

	//----------------------------------------------------------------------------------------
	/// Called after a brush is reset by the user (and set back to its defaults) to overwrite any of the standard brush settings.
	/// @param[in] doc								The BaseDocument.
	/// @param[in] data								The BaseContainer that contains all the settings for the loaded brush.
	//----------------------------------------------------------------------------------------
	virtual void PostInitDefaultSettings(BaseDocument *doc, BaseContainer &data);

	//----------------------------------------------------------------------------------------
	/// Called by the sculpting system to check if a feature is enabled or not. It is similar to GetDEnabling().\n
	/// If this method is overridden then make sure to also check the return value of the base method by calling @c SculptBrushToolData::GetEnabling(id) at the end.
	/// @param[in] id									The id of the UI element from the .res file.
	//----------------------------------------------------------------------------------------
	virtual Bool GetEnabling(Int32 id);

	//----------------------------------------------------------------------------------------
	/// @markPrivate
	/// @param[in] doc								The current document.
	/// @param[in] data								The BaseContainer for the brush data.
	/// @param[in] bd									The BaseDraw the tool is being used in.
	/// @param[in] win								The Window the tool is being used in.
	/// @param[in] msg								The mouse/tablet message data.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	virtual Bool HandleFillTool(BaseDocument* doc, BaseContainer& data, BaseDraw* bd, EditorWindow* win, const BaseContainer& msg);

	//----------------------------------------------------------------------------------------
	/// @markPrivate
	/// Called to do something special when the first mouse click is not on the model.
	/// @param[in] doc								The current document.
	/// @param[in] data								The BaseContainer for the brush data.
	/// @param[in] bd									The BaseDraw the tool is being used in.
	/// @param[in] win								The Window the tool is being used in.
	/// @param[in] msg								The mouse/tablet message data.
	/// @return												@trueIfOtherwiseFalse{if handled}\n
	/// 															In the case to only handle the mouse click and not the mouse drag, return @formatConstant{false}.
	//----------------------------------------------------------------------------------------
	virtual Bool HandleNonModelPickMode(BaseDocument* doc, BaseContainer& data, BaseDraw* bd, EditorWindow* win, const BaseContainer& msg);

	//----------------------------------------------------------------------------------------
	/// @markPrivate
	/// @param[in] doc								The current document.
	/// @param[in] data								The BaseContainer for the brush data.
	/// @param[in] bd									The BaseDraw the tool is being used in.
	/// @param[in] bh									The BaseDrawHelp.
	/// @param[in] bt									The thread this method is being called from.
	/// @param[in] flags							The flags for this call.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	virtual Bool DrawNonModelPickMode(BaseDocument *doc, BaseContainer &data, BaseDraw *bd, BaseDrawHelp *bh, BaseThread *bt, TOOLDRAWFLAGS flags);

	//----------------------------------------------------------------------------------------
	/// Called to allow flooding of the entire layer with a specific operation.
	///
	/// This method gets called by the default Flood button, which has the function id @ref MDATA_SCULPTBRUSH_SETTINGS_FLOOD.\n
	/// This is also called when the Interactive Flood slider is used. Add this slider to the brush by adding the same UI as the Inflate brush has (@em toolsculptbrushinflate.res).
	///
	/// Setting SculptBrushParams::SetFloodType() defines what data is affected by the flood. This can be either @ref SCULPTBRUSHDATATYPE::POINT or @ref SCULPTBRUSHDATATYPE::MASK.
	/// Setting SculptBrushParams::EnableFlood() to @formatConstant{true} indicates that this method is available to be used, the Flood button will then be active in the UI.
	/// @param[in] pSculpt						The SculptObject.
	/// @param[in] pLayer							The layer to flood.
	/// @param[in] brushData					The brushes BaseContainer data.
	/// @param[in] function						The ID of the function to apply. The default Flood button has the ID @ref MDATA_SCULPTBRUSH_SETTINGS_FLOOD.
	/// @param[in] preview						@formatConstant{true} when the flooding is part of an interactive process, e.g. when the user is moving a slider such as the Interactive Inflate option.
	/// @param[in] customStrength			If not @formatConstant{nullptr} then this contains a special strength value that should be used instead of the one from the brushData. This strength is used for interactive flooding along with the preview option.
	/// @param[in] pVertexNormals			If not @formatConstant{nullptr} then this contains the vertex normals on the current object. These can be used for interactive flooding along with the preview option.
	//----------------------------------------------------------------------------------------
	virtual void FloodSelectedLayer(SculptObject *pSculpt, SculptLayer *pLayer, const BaseContainer& brushData, Int32 function, Bool preview, Float *customStrength = nullptr, const Vector32 *pVertexNormals = nullptr);

	//----------------------------------------------------------------------------------------
	/// Called to allow flooding of the entire layer, using a material channel, with a specific operation.
	///
	/// This method is called if the method FloodWithChannel() is invoked by the brush.\n
	/// This is also called when the Interactive Flood slider is used. Add this slider to the brush by adding the same UI as the Inflate brush has (@em toolsculptbrushinflate.res).
	///
	/// Setting SculptBrushParams::SetFloodType() will define what data is being affected by the flood. This can be either @ref SCULPTBRUSHDATATYPE::POINT or @ref SCULPTBRUSHDATATYPE::MASK.
	/// Setting SculptBrushParams::EnableFlood() to @formatConstant{true} indicates that this method is available to be used, the Flood button will then be active in the UI.
	/// @param[in] pSculpt						The SculptObject.
	/// @param[in] pLayer							The layer to flood.
	/// @param[in] brushData					The brushes BaseContainer data.
	/// @param[in] function						The ID of the function to apply. The default Flood button has the ID @ref MDATA_SCULPTBRUSH_SETTINGS_FLOOD.
	/// @param[in] pChannel						The BaseChannel to use when flooding.
	/// @param[in] preview						@formatConstant{true} when the Flooding is part of an interactive process, e.g. when the user is moving a slider such as the Interactive Inflate option.
	/// @param[in] customStrength			If not @formatConstant{nullptr} then this contains a special strength value that should be used instead of the one from the brushData. This strength is used for interactive flooding along with the preview option.
	/// @param[in] pVertexNormals			If not @formatConstant{nullptr} then this contains the vertex normals on the current object. These can be used for interactive flooding along with the preview option.
	//----------------------------------------------------------------------------------------
	virtual void FloodSelectedLayerWithChannel(SculptObject *pSculpt, SculptLayer *pLayer, const BaseContainer& brushData, Int32 function, BaseChannel *pChannel, Bool preview, Float *customStrength = nullptr, const Vector32 *pVertexNormals = nullptr);

	//----------------------------------------------------------------------------------------
	/// Called to allow flooding of the entire layer, using a bitmap, with a specific operation.
	///
	/// This method is called if the method FloodWithBitmap() is called by the brush.\n
	/// This is also called when the Interactive Flood slider is used. Add this slider to the brush by adding the same UI as the Inflate brush has (@em toolsculptbrushinflate.res).\n
	/// Setting SculptBrushParams::SetFloodType() will define what data is being affected by the flood. This can be either @ref SCULPTBRUSHDATATYPE::POINT or @ref SCULPTBRUSHDATATYPE::MASK.
	///
	/// Setting SculptBrushParams::EnableFlood() to @formatConstant{true} indicates that this method is available to be used, the Flood button will then be active in the UI.
	/// @param[in] pSculpt						The SculptObject.
	/// @param[in] pLayer							The layer to flood.
	/// @param[in] brushData					The brushes BaseContainer data.
	/// @param[in] function						The ID of the function to apply. The default Flood button has the ID @ref MDATA_SCULPTBRUSH_SETTINGS_FLOOD.
	/// @param[in] pBitmap						The BaseBitmap to use when flooding.
	/// @param[in] preview						@formatConstant{true} when the Flooding is part of an interactive process, e.g. when the user is moving a slider such as the Interactive Inflate option.
	/// @param[in] customStrength			If not @formatConstant{nullptr} then this contains a special strength value that should be used instead of the one from the brushData. This strength is used for interactive flooding along with the preview option.
	/// @param[in] pVertexNormals			If not @formatConstant{nullptr} then this contains the vertex normals on the current object. These can be used for interactive flooding along with the preview option.
	//----------------------------------------------------------------------------------------
	virtual void FloodSelectedLayerWithBitmap(SculptObject *pSculpt, SculptLayer *pLayer, const BaseContainer& brushData, Int32 function, BaseBitmap *pBitmap, Bool preview, Float *customStrength = nullptr, const Vector32 *pVertexNormals = nullptr);

	//----------------------------------------------------------------------------------------
	/// Called to let the system know what draw modes the brush supports.\n
	/// The system will call this method to check if a draw mode is supported by the brush.\n
	/// If the brush supports all the draw modes then it can just return @formatConstant{true}.\n
	/// Otherwise specify which draw modes should be enabled by checking each of them.
	/// @param[in] mode								The ID for the Draw Mode. For example @ref MDATA_SCULPTBRUSH_SETTINGS_DRAWMODE_LINE.
	/// @return												@trueIfOtherwiseFalse{the Draw Mode is supported}
	//----------------------------------------------------------------------------------------
	virtual Bool HasDrawMode(Int32 mode);

	//----------------------------------------------------------------------------------------
	/// Floods the entire layer by calling virtual method FloodSelectedLayer().\n
	/// If the brush has different flooding methods (like blur, erase, sharpen etc.) then pass in a different flag for the @formatParam{button} id.\n
	/// FloodSelectedLayer() is then called with this setting passed as the @c function parameter.
	/// @note	By default the button is set to the @ref MDATA_SCULPTBRUSH_SETTINGS_FLOOD which is the standard Flood button that the brushes have.\n
	///				If a different button is used then this method should be called from @c Message() when a button is pushed in the interface.
	/// @param[in] doc								The current document.
	/// @param[in] bd									The viewport that should be used. Usually @c doc->GetActiveBaseDraw().
	/// @param[in] brushData					The tools data container.
	/// @param[in] button							The ID of the button in the UI to use as the function parameter in the subsequent call to FloodSelectedLayer().
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool Flood(BaseDocument* doc, BaseDraw* bd, const BaseContainer& brushData, Int32 button = MDATA_SCULPTBRUSH_SETTINGS_FLOOD);

	//----------------------------------------------------------------------------------------
	/// Floods the entire layer by calling virtual method FloodSelectedLayerWithChannel().\n
	/// If the brush has different flooding methods (like blur, erase, sharpen etc.) then pass in a different flag for the @formatParam{button} id.\n
	/// FloodSelectedLayerWithChannel is then called with this setting passed as the @c function parameter.\n
	/// @note	By default the button is set to the @ref MDATA_SCULPTBRUSH_SETTINGS_FLOOD which is the standard Flood button that the brushes have.\n
	///				If a different button is used then this method should be called from @c Message() when a button is pushed in the interface.
	/// @param[in] doc								The current document.
	/// @param[in] bd									The viewport that should be used. Usually @c doc->GetActiveBaseDraw().
	/// @param[in] brushData					The tools data container.
	/// @param[in] pChannel						The BaseChannel to use when flooding.
	/// @param[in] button							The ID of the button in the UI to use as the function parameter in the subsequent call to FloodSelectedLayerWithChannel().
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool FloodWithChannel(BaseDocument* doc, BaseDraw* bd, const BaseContainer& brushData, BaseChannel *pChannel, Int32 button = MDATA_SCULPTBRUSH_SETTINGS_FLOOD);

	//----------------------------------------------------------------------------------------
	/// Floods the entire layer by calling virtual method FloodSelectedLayerWithBitmap().\n
	/// If the brush has different flooding methods (like blur, erase, sharpen etc.) then pass in a different flag for the @formatParam{button} id.\n
	/// FloodSelectedLayerWithBitmap() is then called with this setting passed as the @c function parameter.
	/// @note	By default the button is set to the @ref MDATA_SCULPTBRUSH_SETTINGS_FLOOD which is the standard Flood button that the brushes have.\n
	///				If a different button is used then this method should be called from @c Message() when a button is pushed in the interface.
	/// @param[in] doc								The current document.
	/// @param[in] bd									The viewport that should be used. Usually @c doc->GetActiveBaseDraw().
	/// @param[in] brushData					The tools data container.
	/// @param[in] pBitmap						The BaseBitmap to use when flooding.
	/// @param[in] button							The ID of the button in the UI to use as the function parameter in the subsequent call to FloodSelectedLayerWithBitmap().
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool FloodWithBitmap(BaseDocument* doc, BaseDraw* bd, const BaseContainer& brushData, BaseBitmap *pBitmap, Int32 button = MDATA_SCULPTBRUSH_SETTINGS_FLOOD);

	//----------------------------------------------------------------------------------------
	/// @markPrivate
	/// Called by Python Brushes.
	//----------------------------------------------------------------------------------------
	virtual Bool ApplyPythonDab(BrushDabData *dab);

	//----------------------------------------------------------------------------------------
	/// If @ref SculptBrushParams::EnableCustomStamp(@formatConstant{true}) and @ref SculptBrushParams::EnableBrushAccess(@formatConstant{true}) are both set then this method is called to allow to change the BaseBitmap used for the next dab.\n
	/// This method is called before each individual dab is drawn. This allows to randomize the stamp image during a stroke. Simply set the @c @formatParam{pCustom}->pStamp pointer to point to a BaseBitmap that is owned by the brush.
	/// @param[in] strokeInstanceID		The ID of the brush instance.
	/// @param[in,out] pCustom				The custom data to set the @c pStamp bitmap pointer.
	/// @return												@trueIfOtherwiseFalse{something changes since the last time it was called}
	//----------------------------------------------------------------------------------------
	virtual Bool GetCustomData(Int32 strokeInstanceID, SculptCustomData *pCustom);

	//----------------------------------------------------------------------------------------
	/// @markPrivate
	/// After preset data has been loaded this method is called to adjust adjust any settings that are specific for the brush.
	/// @param[in] data								The container for the sculpt brush tool.
	//----------------------------------------------------------------------------------------
	virtual void UpdateSettingsAfterPresetLoad(BaseContainer *data);

	//----------------------------------------------------------------------------------------
	/// @markPrivate
	/// After preset data has been loaded this method is called to refresh the stencil for the brush.
	/// @param[in] data								The container for the sculpt brush tool.
	//----------------------------------------------------------------------------------------
	virtual void UpdateStencilAfterPresetLoad(BaseContainer *data);

	/// @}

	/// @name Non-Virtual Methods
	/// @{

	//----------------------------------------------------------------------------------------
	/// Enables a flag so that the brush preview gets drawn.
	//----------------------------------------------------------------------------------------
	void EnableSpecialDrawGizmo();

	//----------------------------------------------------------------------------------------
	/// Clears the flag so that the drawing of the brush preview is not forced.
	//----------------------------------------------------------------------------------------
	void DisableSpecialDrawGizmo();

	//----------------------------------------------------------------------------------------
	/// Tells the brush when the mouse button is down.
	/// @note This method should be called from within HandleFillTool() to let the system know that the mouse is being polled for input.
	/// @param[in] value							Set to @formatConstant{true} if the mouse is being polled. Set to @formatConstant{false} when finished.
	//----------------------------------------------------------------------------------------
	void SetMouseDrag(Bool value);

	//----------------------------------------------------------------------------------------
	/// Checks if a mouse button is held down and being dragged.
	/// @return												@trueIfOtherwiseFalse{a mouse button is down}
	//----------------------------------------------------------------------------------------
	Bool IsMouseDrag();

	//----------------------------------------------------------------------------------------
	/// Caches sculptable objects in the scene so the tool is ready to use on them.\n
	/// This includes sculpt objects (those with a SculptTag) as well as the first selected PolygonObject (without a tag).
	/// Cache objects that are visible in the currently active viewport.
	/// @param[in] doc								The document to check.
	//----------------------------------------------------------------------------------------
	void CacheObjects(BaseDocument *doc);

	//----------------------------------------------------------------------------------------
	/// Gets the number of sculpt objects currently selected. This includes sculpt objects (those with a SculptTag) as well as other internal objects.\n
	/// Checking if an object is of type @ref SCULPT_OBJECT_ID allows the caller to cast to a SculptObject.
	/// @return												The number of selected sculpt objects.
	//----------------------------------------------------------------------------------------
	Int32 GetSelectionCacheCount();

	//----------------------------------------------------------------------------------------
	/// Gets a cached SculptObject.
	/// @param[in] index							The index of the cached object.
	/// @return												The cached Object. If its @c GetType()==SCULPT_OBJECT_ID then it is a SculptObject.
	//----------------------------------------------------------------------------------------
	BaseList2D *GetSelectionCacheObject(Int32 index);

	//----------------------------------------------------------------------------------------
	/// Gets the strength of the brush.\n
	/// This is useful when used in the Flood method to get the strength that the flood should apply.
	/// @param[in] original						If @formatConstant{true} returns the value as defined in the UI.\n
	/// 															If @formatConstant{False} returns an interpolated value between the current and the next sample point and then also adjusted according to any effector settings such as pen pressure.
	/// @return												The strength value.
	//----------------------------------------------------------------------------------------
	Float GetBrushStrength(Bool original);

	//----------------------------------------------------------------------------------------
	/// Initializes the scaling settings for each sculpt brush according to the distance the camera is from the SculptObject.\n
	/// Updates the scaling information for each currently selected SculptObject in the scene.\n
	/// @warning Plugin developers should never have to call this method. It is used internally when a sculpt tag is first applied to an object to ensure the selected brush works correctly.
	/// @param[in] doc								The document to check for SculptObject to update.
	//----------------------------------------------------------------------------------------
	void InitZoomScale(BaseDocument *doc);

	//----------------------------------------------------------------------------------------
	/// Checks if the brush has the SculptBrushParams::EnableModifier flag set to @formatConstant{true}.
	/// @return												@trueIfOtherwiseFalse{the brush can use modifiers}
	//----------------------------------------------------------------------------------------
	Bool HasModifier();

	//----------------------------------------------------------------------------------------
	/// Checks if the brush has the SculptBrushParams::EnableRespectSelections flag set to @formatConstant{true}.\n
	/// This should be checked in the FloodSelectedLayer() method to see if it should respect the current selection or not.\n
	/// This can return @formatConstant{false} if overridden by the internal sculpting system to specifically ignore selections.
	/// @return												@trueIfOtherwiseFalse{the brush should respect the current selection}
	//----------------------------------------------------------------------------------------
	Bool HasRespectSelections();

	//----------------------------------------------------------------------------------------
	/// @markPrivate
	/// Writes the brush preset data.
	/// @param[in] hf									The HyperFile to write to.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool WritePresetData(HyperFile *hf);

	//----------------------------------------------------------------------------------------
	/// @markPrivate
	/// Reads the brush preset data.
	/// @param[in] hf									The HyperFile to write to.
	/// @param[in] level							The version of the plugin that the brush data was written with.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool ReadPresetData(HyperFile *hf, Int32 level);

	//----------------------------------------------------------------------------------------
	/// @markPrivate
	/// Writes the brush stamp preset data.
	/// @param[in] hf									The HyperFile to write to.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool WriteStampPresetData(HyperFile *hf);

	//----------------------------------------------------------------------------------------
	/// @markPrivate
	/// Reads the brush stamp preset data.
	/// @param[in] hf									The HyperFile to write to.
	/// @param[in] level							The version of the plugin that the stamp data was written with.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool ReadStampPresetData(HyperFile *hf, Int32 level);

	//----------------------------------------------------------------------------------------
	/// @markPrivate
	//----------------------------------------------------------------------------------------
	Bool WriteSplinePresetData(HyperFile *hf);

	//----------------------------------------------------------------------------------------
	/// @markPrivate
	//----------------------------------------------------------------------------------------
	Bool ReadSplinePresetData(HyperFile *hf, Int32 level);

	//----------------------------------------------------------------------------------------
	/// Gets the BaseBitmap that is being used for the stamp of the sculpt brush.
	/// @return												The stamp that the brush is using.
	//----------------------------------------------------------------------------------------
	const BaseBitmap *GetStamp();

	//----------------------------------------------------------------------------------------
	/// Gets the BaseBitmap that is being used for the stencil of the sculpt brush.
	/// @return												The stencil that the brush is using.
	//----------------------------------------------------------------------------------------
	const BaseBitmap *GetStencil();

	/// @}
};

//----------------------------------------------------------------------------------------
/// Data class to create sculpt brush modifier plugins. Use RegisterBrushModifier() to register one.
//----------------------------------------------------------------------------------------
class SculptBrushModifierData : public NodeData
{
	INSTANCEOF(SculptBrushModifierData, NodeData)
public:

	//----------------------------------------------------------------------------------------
	/// Checks if the node is part of a document or not.
	/// @warning Do not change the implementation of this method!
	/// @param[in] node								The modifier node to check.
	/// @param[out] docrelated				Set to @formatConstant{true} if the node is part of a document.\n
	/// 															Modifiers are not part of the document so this is always set to @formatConstant{false}.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	virtual Bool IsDocumentRelated(const GeListNode* node, Bool& docrelated) const
	{
		docrelated = false;
		return true;
	}

	//----------------------------------------------------------------------------------------
	/// Applies the effect of the modifier to the dab.
	/// @param[in] dab								The brush dab data.
	/// @param[in] modifierData				The container of the modifier data.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	virtual Bool ApplyModifier(BrushDabData *dab, const BaseContainer &modifierData) = 0;
};

//----------------------------------------------------------------------------------------
/// This interface lets apply the affects of a sculpting modifier to any polygon object.\n
/// It allows to use the same algorithms outside of the sculpting system itself and deform a polygon object using the same brush algorithms that the sculpt brushes use.
//----------------------------------------------------------------------------------------
class SculptModifierInterface
{
private:
	SculptModifierInterface();
	~SculptModifierInterface();

public:

	//----------------------------------------------------------------------------------------
	/// @allocatesA{SculptModifierInterface object}
	/// @return												@allocReturn{SculptModifierInterface object}
	//----------------------------------------------------------------------------------------
	static SculptModifierInterface *Alloc();

	//----------------------------------------------------------------------------------------
	/// @destructsAlloc{SculptModifierInterface objects}
	/// @param[in,out] brush					@theToDestruct{SculptModifierInterface object}
	//----------------------------------------------------------------------------------------
	static void Free(SculptModifierInterface *&brush);

	//----------------------------------------------------------------------------------------
	/// Initializes the interface to apply modifiers to the given polygon object.
	/// @param[in] poly								The polygon object to apply modifiers to.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool Init(PolygonObject *poly);

	//----------------------------------------------------------------------------------------
	/// Clears the interface. Frees up any internal data that was required to apply modifiers to the initialized polygon object.
	//----------------------------------------------------------------------------------------
	void Clear();

	//----------------------------------------------------------------------------------------
	/// Gets the default brush data setting. These settings can be found in toolsculptbrushbase.h
	/// @return												The container containing all the default brush settings.
	//----------------------------------------------------------------------------------------
	BaseContainer GetDefaultData();

	//----------------------------------------------------------------------------------------
	/// Gets the number of available modifiers that are currently registered and able to be used.
	/// @return												The number of modifiers.
	//----------------------------------------------------------------------------------------
	Int32 GetModifierCount();

	//----------------------------------------------------------------------------------------
	/// Gets the information about a modifier given its @formatParam{index}.
	/// @param[in] index							The index into the list of available modifiers: @em 0 <= @formatParam{index} < GetModifierCount()
	/// @param[out] modifierId				Assigned the plugin ID of the modifier.
	/// @param[out] name							Assigned the name of the modifier.
	/// @return												@trueIfOtherwiseFalse{a modifier was found at the given index}
	//----------------------------------------------------------------------------------------
	Bool GetModifierInfo(Int32 index, Int32 &modifierId, String &name);

	//----------------------------------------------------------------------------------------
	/// Sets the brush data and modifier data for the the next dab to be drawn.\n
	/// Initializes any time consuming data before making repeated calls to ApplyModifier().
	///				Operations that take time are things such as enabling stamps, changing a stamps texture, calculation of the falloff values etc.
	/// @param[in] brushData					The brush data container settings. By default just use what is returned from calling GetDefaultData().
	/// @param[in] modifierData				The container for the modifier itself. Each modifier is a BaseList2D node and could have its own settings. Refer to each modifiers BM file (BMknife.h as an example).
	/// @return												@trueIfOtherwiseFalse{the data was correctly set}
	//----------------------------------------------------------------------------------------
	Bool SetData(const BaseContainer &brushData, const BaseContainer &modifierData);

	//----------------------------------------------------------------------------------------
	/// Applies a modifier to the PolygonObject near the specified vertex.
	/// @pre SetData() must be called before.
	/// @note If a hit point is given then it must be on the surface of a polygon that is attached to the specified vertex.
	/// @param[in] modifierId					The plugin ID of the modifier to apply. This is retrieved from a call to GetModifierInfo().
	/// @param[in] vertex							The index of the vertex on the PolygonObject where to apply the modifier to.
	/// @param[in] brushData					The brush data container settings. By default just use what is returned from calling GetDefaultData();
	/// @param[in] modifierData				The container for the modifier itself. Each modifier is a BaseList2D node and could have its own settings. Refer to each modifiers BM file (BMknife.h as an example).
	/// @param[in] pHitPoint					The exact hit point on the surface of a polygon that is connected to the vertex.
	/// @param[in] pLastHitPoint			The last hit point from the previous call to ApplyModifier().\n
	/// 															This is used to determine the direction of the dab for modifiers such as the knife and pinch modifier.
	/// @param[in] respectSelections	@formatConstant{true} to tell the modifier to respect any Polygon or Point selections on the PolygonObject.
	/// @return												@trueIfOtherwiseFalse{the data was correctly set}
	//----------------------------------------------------------------------------------------
	Bool ApplyModifier(Int32 modifierId, Int32 vertex, const BaseContainer &brushData, const BaseContainer &modifierData, Vector *pHitPoint = nullptr, Vector *pLastHitPoint = nullptr, Bool respectSelections = false);
};

/// @cond IGNORE

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

struct SculptBrushBaseLibrary : public C4DLibrary
{
	iSculptBrushBase*	(*Alloc)();
	void							(*Free)(iSculptBrushBase *&p);

	// BrushDabData
	const BaseContainer*	(*brushDabDataGetData)(BrushDabData *dab);
	const SculptObject*		(*brushDabDataGetObject)(BrushDabData *dab);
	const BrushPointData*	(*brushDabDataGetPointData)(BrushDabData *dab);
	const BrushPolyData*	(*brushDabDataGetPolyData)(BrushDabData *dab);
	PolygonObject*				(*brushDabDataGetPolygonObject)(BrushDabData *dab);
	PolygonObject*				(*brushDabDataGetBaseObject)(BrushDabData *dab);
	Int32									(*brushDabDataGetPointCount)(BrushDabData *dab);
	Int32									(*brushDabDataGetPolyCount)(BrushDabData *dab);
	Neighbor*							(*brushDabDataGetNeighbor)(BrushDabData *dab);
	SculptLayer*					(*brushDabDataGetLayer)(BrushDabData *dab);
	const Vector*					(*brushDabDataGetPoints)(BrushDabData *dab);
	const Vector32*				(*brushDabDataGetOriginalPoints)(BrushDabData *dab);
	Vector								(*brushDabDataGetNormal)(BrushDabData *dab);
	Float									(*brushDabDataGetBrushStrength)(BrushDabData *dab);
	Float									(*brushDabDataGetBrushRadius)(BrushDabData *dab);
	Vector								(*brushDabDataGetMousePos3D)(BrushDabData *dab);
	Vector								(*brushDabDataGetHitPoint)(BrushDabData *dab);
	Vector								(*brushDabDataGetLastHitPoint)(BrushDabData *dab);
	Vector								(*brushDabDataGetEyePoint)(BrushDabData *dab);
	Bool									(*brushDabDataIsMirroredDab)(BrushDabData *dab);
	OVERRIDE							(*brushDabDataGetBrushOverride)(BrushDabData *dab);
	BaseDraw*							(*brushDabDataGetBaseDraw)(BrushDabData *dab);
	void									(*brushDabDataGetAveragePointAndNormal)(BrushDabData *dab, Vector &averagePoint, Vector &normal);
	Float									(*brushDabDataGetBrushFalloff)(BrushDabData *dab, Int32 index, Vector32 *pRetStencilColor, Float *pCustomDistance);
	Float									(*brushDabDataGetBrushFalloffFromPos)(BrushDabData *dab, const Vector &pos);
	void									(*brushDabDataOffsetPoint)(BrushDabData *dab, Int32 index, const Vector &offset, Vector32 *pVertexColor, SCULPTOFFSETFLAGS flags);
	Bool									(*brushDabDataIsPreviewDab)(BrushDabData *dab);
	void									(*brushDabDataOffsetPreviewPoint)(BrushDabData *dab, Int32 index, const Vector &offset, SCULPTOFFSETFLAGS flags);
	void									(*brushDabDataApplySmooth)(BrushDabData *dab);
	const Vector32*				(*brushDabDataGetVertexNormals)(BrushDabData *dab);
	Float									(*brushDabDataGetAutoScaleValue)(BrushDabData *dab, Bool noRadius);
	void									(*brushDabDataDirtyAllPoints)(BrushDabData *dab, SCULPTBRUSHDATATYPE type);
	Bool									(*brushDabDataIsPointModified)(BrushDabData *dab, Int32 index);
	Float									(*brushDabDataGetStencilColor)(BrushDabData *dab, const Vector &point, Vector32 *pRetColor, Vector32 *pRetCoords, SAMPLEMODE mode);
	Float									(*brushDabDataGetStampColor)(BrushDabData *dab, const Vector &point, Float distanceFromHitPoint, Vector32 *pRetColor, Vector32 *pRetCoords, SAMPLEMODE mode);
	const BaseBitmap*			(*brushDabDataGetStamp)(BrushDabData *dab);
	const BaseBitmap*			(*brushDabDataGetStencil)(BrushDabData *dab);
	SculptBrushToolData*	(*brushDabDataGetBrush)(BrushDabData *dab);
	Int32									(*brushDabDataGetStrokeInstanceID)(BrushDabData *dab);
	Bool									(*brushDabDataIsSculptObject)(BrushDabData *dab);

	// iSculptBrushBase
	// Virtual
	Bool			(iSculptBrushBase::*InitTool)(BaseDocument* doc, BaseContainer& data, BaseThread* bt, SculptBrushToolData *tool);
	void			(iSculptBrushBase::*FreeTool)(BaseDocument* doc, BaseContainer& data, SculptBrushToolData *tool);
	void			(iSculptBrushBase::*InitDefaultSettings)(BaseDocument *doc, BaseContainer &data, SculptBrushToolData *tool);
	Bool			(iSculptBrushBase::*GetDEnabling)(BaseDocument* doc, BaseContainer& data, const DescID& id, const GeData& t_data, DESCFLAGS_ENABLE flags, const BaseContainer* itemdesc, SculptBrushToolData *tool);
	Bool			(iSculptBrushBase::*SetDParameter)(BaseDocument* doc, BaseContainer& data, const DescID& id, const GeData& t_data, DESCFLAGS_SET& flags, SculptBrushToolData *tool);
	Bool			(iSculptBrushBase::*GetDDescription)(BaseDocument* doc, BaseContainer& data, Description* description, DESCFLAGS_DESC& flags, SculptBrushToolData *tool);
	Bool			(iSculptBrushBase::*Message)(BaseDocument *doc, BaseContainer &data, Int32 type, void *t_data, SculptBrushToolData *tool);
	Bool			(iSculptBrushBase::*GetCursorInfo)(BaseDocument* doc, BaseContainer& data, BaseDraw* bd, Float x, Float y, BaseContainer& bc, SculptBrushToolData *tool);
	Bool			(iSculptBrushBase::*MouseInput)(BaseDocument* doc, BaseContainer& data, BaseDraw* bd, EditorWindow* win, const BaseContainer& msg, SculptBrushToolData *tool);
	Bool			(iSculptBrushBase::*KeyboardInput)(BaseDocument *doc, BaseContainer &data, BaseDraw *bd, EditorWindow *win, const BaseContainer &msg, SculptBrushToolData *tool);
	Int32			(iSculptBrushBase::*GetState)(BaseDocument *doc, SculptBrushToolData *tool);
	TOOLDRAW	(iSculptBrushBase::*Draw)(BaseDocument *doc, BaseContainer &data, BaseDraw *bd, BaseDrawHelp *bh, BaseThread *bt, TOOLDRAWFLAGS flags, SculptBrushToolData *tool);
	Bool			(iSculptBrushBase::*GetDParameter)(BaseDocument* doc, BaseContainer& data, const DescID& id, GeData& t_data, DESCFLAGS_GET& flags, SculptBrushToolData *tool);
	Bool			(iSculptBrushBase::*DisplayControl)(BaseDocument* doc, BaseObject* op, BaseObject* chainstart, BaseDraw* bd, BaseDrawHelp* bh, ControlDisplayStruct& cds, SculptBrushToolData *tool);
	Bool			(iSculptBrushBase::*InitDisplayControl)(BaseDocument* doc, BaseContainer& data, BaseDraw* bd, const AtomArray* active, SculptBrushToolData *tool);
	void			(iSculptBrushBase::*FreeDisplayControl)(SculptBrushToolData *tool);

	void	(iSculptBrushBase::*StartStroke)(Int32 strokeCount, const BaseContainer &data);
	void	(iSculptBrushBase::*EndStroke)();
	void	(iSculptBrushBase::*StartStrokeInstance)(Int32 strokeInstanceID);
	void	(iSculptBrushBase::*EndStrokeInstance)(Int32 strokeInstanceID);
	void	(iSculptBrushBase::*StartStrokeInstanceDabs)(Int32 strokeInstanceID);
	void	(iSculptBrushBase::*EndStrokeInstanceDabs)(Int32 strokeInstanceID);
	void	(iSculptBrushBase::*StartSymmetry)();
	void	(iSculptBrushBase::*EndSymmetry)();
	void	(iSculptBrushBase::*StartDab)(Int32 strokeInstanceID);
	void	(iSculptBrushBase::*EndDab)(Int32 strokeInstanceID);

	void	(iSculptBrushBase::*OverwriteLoadedPresetSettings)(BaseContainer &data);
	void	(iSculptBrushBase::*PostInitDefaultSettings)(BaseDocument *doc, BaseContainer &data);
	Bool	(iSculptBrushBase::*GetEnabling)(Int32 id);
	Bool	(iSculptBrushBase::*HandleFillTool)(BaseDocument* doc, BaseContainer& data, BaseDraw* bd, EditorWindow* win, const BaseContainer& msg);
	Bool	(iSculptBrushBase::*HandleNonModelPickMode)(BaseDocument* doc, BaseContainer& data, BaseDraw* bd, EditorWindow* win, const BaseContainer& msg);
	Bool	(iSculptBrushBase::*DrawNonModelPickMode)(BaseDocument *doc, BaseContainer &data, BaseDraw *bd, BaseDrawHelp *bh, BaseThread *bt, TOOLDRAWFLAGS flags);
	void	(iSculptBrushBase::*FloodSelectedLayer)(SculptObject *pSculpt, SculptLayer *pLayer, const BaseContainer& brushData, Int32 function, Bool preview, Float *customStrength, const Vector32 *pVertexNormals);
	Bool	(iSculptBrushBase::*HasDrawMode)(Int32 mode);

	// Non Virtual
	Bool				(iSculptBrushBase::*Flood)(BaseDocument* doc, BaseDraw* bd, const BaseContainer& brushData, Int32 button);
	void				(iSculptBrushBase::*EnableSpecialDrawGizmo)();
	void				(iSculptBrushBase::*DisableSpecialDrawGizmo)();
	void				(iSculptBrushBase::*SetMouseDrag)(Bool value);
	Bool				(iSculptBrushBase::*IsMouseDrag)();
	void				(iSculptBrushBase::*CacheObjects)(BaseDocument *doc);
	Int32				(iSculptBrushBase::*GetSelectionCacheCount)();
	BaseList2D*	(iSculptBrushBase::*GetSelectionCacheObject)(Int32 index);
	Float				(iSculptBrushBase::*GetBrushStrength)(Bool original);
	void				(iSculptBrushBase::*InitZoomScale)(BaseDocument *doc);

	// Presets
	Bool				(iSculptBrushBase::*WritePresetData)(HyperFile *hf);
	Bool				(iSculptBrushBase::*ReadPresetData)(HyperFile *hf, Int32 level);
	Bool				(iSculptBrushBase::*WriteStampPresetData)(HyperFile *hf);
	Bool				(iSculptBrushBase::*ReadStampPresetData)(HyperFile *hf, Int32 level);
	Bool				(iSculptBrushBase::*WriteSplinePresetData)(HyperFile *hf);
	Bool				(iSculptBrushBase::*ReadSplinePresetData)(HyperFile *hf, Int32 level);
	void				(iSculptBrushBase::*UpdateSettingsAfterPresetLoad)(BaseContainer *data);

	// Other
	const BaseBitmap*	(iSculptBrushBase::*GetStamp)();
	const BaseBitmap*	(iSculptBrushBase::*GetStencil)();

	// SculptBrushParams
	SculptBrushParams*	(*sculptbrushparamsAlloc)();
	void	(*sculptbrushparamsFree)(SculptBrushParams *&params);
	void	(*sculptbrushparamsEnableStencil)(SculptBrushParams *pParams, Bool enable);
	void	(*sculptbrushparamsEnableStamp)(SculptBrushParams *pParams, Bool enable);
	void	(*sculptbrushparamsEnableInvertCheckbox)(SculptBrushParams *pParams, Bool enable);
	void	(*sculptbrushparamsEnableBuildup)(SculptBrushParams *pParams, Bool enable);
	void	(*sculptbrushparamsEnableNonModelPickMode)(SculptBrushParams *pParams, Bool enable);
	void	(*sculptbrushparamsEnableFlood)(SculptBrushParams *pParams, Bool enable);
	void	(*sculptbrushparamsEnableToolSpecificSmooth)(SculptBrushParams *pParams, Bool enable);
	void	(*sculptbrushparamsEnableMultiThreading)(SculptBrushParams *pParams, Bool enable);
	void	(*sculptbrushparamsEnableBrushAccess)(SculptBrushParams *pParams, Bool enable);

	void	(*sculptbrushparamsSetFloodType)(SculptBrushParams *pParams, SCULPTBRUSHDATATYPE type);
	void	(*sculptbrushparamsSetBrushMode)(SculptBrushParams *pParams, SCULPTBRUSHMODE mode);
	void	(*sculptbrushparamsSetFirstHitPointType)(SculptBrushParams *pParams, FIRSTHITPPOINTTYPE type);
	void	(*sculptbrushparamsSetUndoType)(SculptBrushParams *pParams, SCULPTBRUSHDATATYPE type);
	void	(*sculptbrushparamsSetMovePointFunc)(SculptBrushParams *pParams, Bool (*surfaceMovePointFunc)(BrushDabData *dab));


	// R16 additions
	Vector					(*brushDabDataGetDrawDirectionNormal)(BrushDabData *dab);
	Vector					(*brushDabDataGetMirrorPoint)(BrushDabData *dab, const Vector &point, Bool isNormal);
	Float32*				(*brushDabDataGetMaskCache)(BrushDabData *dab);
	Float32					(*brushDabDataPointPolysAverageFloat32)(BrushDabData *dab, Int32 vertex, Float32 *values);
	Vector					(*brushDabDataPointPolysAverageVector)(BrushDabData *dab, Int32 vertex, Vector *values);
	Bool						(*brushDabDataIsPointInFillArea)(BrushDabData *dab, const Vector &p);

	Bool	(iSculptBrushBase::*HasModifier)();
	Bool	(iSculptBrushBase::*HasRespectSelections)();
	Bool	(iSculptBrushBase::*TranslateDescID)(BaseDocument* doc, BaseContainer& data, const DescID& id, DescID& res_id, C4DAtom*& res_at, SculptBrushToolData *tool);
	void	(iSculptBrushBase::*UpdateStencilAfterPresetLoad)(BaseContainer *data);

	void	(*sculptbrushparamsEnableModifier)(SculptBrushParams *pParams, Bool enable);
	void	(*sculptbrushparamsEnablePython)(SculptBrushParams *pParams, Bool enable);
	void	(*sculptbrushparamsEnableDrawDirection)(SculptBrushParams *pParams, Bool enable);
	void	(*sculptbrushparamsEnableCustomStamp)(SculptBrushParams *pParams, Bool enable);
	void	(*sculptbrushparamsEnableRespectSelections)(SculptBrushParams *pParams, Bool enable);
	void	(*sculptbrushparamsEnableFillToolIsolatedPointRemover)(SculptBrushParams *pParams, Bool enable);
	void	(*sculptbrushparamsEnablePressureHUD)(SculptBrushParams *pParams, Bool enable);

	Bool	(*sculptbrushAddModifierFunc)(Int32 id, String name, SCULPTBRUSHMODE mode, SCULPTBRUSHDATATYPE type, maxon::BaseArray<Int32> *brushFilters, maxon::BaseArray<Int32> *brushRestrictions, Bool hide);

	// SculptFlagChecker
	SculptFlagChecker*	(*sculptflagcheckerAlloc)();
	void								(*sculptflagcheckerFree)(SculptFlagChecker *&fc);
	Bool								(*sculptflagcheckerInit)(SculptFlagChecker *fc, UInt32 count);
	void								(*sculptflagcheckerClear)(SculptFlagChecker *fc);
	UInt32							(*sculptflagcheckerGetCount)(SculptFlagChecker *fc);
	void								(*sculptflagcheckerSet)(SculptFlagChecker *fc, UInt32 val);
	Bool								(*sculptflagcheckerCheckSet)(SculptFlagChecker *fc, UInt32 val);
	Bool								(*sculptflagcheckerCheck)(SculptFlagChecker *fc, UInt32 val);
	void								(*sculptflagcheckerUnSet)(SculptFlagChecker *fc, UInt32 val);

	// SculptPointPolysIterator
	SculptPointPolysIterator*	(*sculptpointpolyiteratorAlloc)();
	void											(*sculptpointpolyiteratorFree)(SculptPointPolysIterator *&itr);
	Bool											(*sculptpointpolyiteratorInit)(SculptPointPolysIterator *itr, const SculptObject *pObj, Int32 vertex);
	void											(*sculptpointpolyiteratorNext)(SculptPointPolysIterator *itr);
	Bool											(*sculptpointpolyiteratorIsValid)(SculptPointPolysIterator *itr);
	CPolygon									(*sculptpointpolyiteratorGetPolygon)(SculptPointPolysIterator *itr);
	Int32											(*sculptpointpolyiteratorGetIndex)(SculptPointPolysIterator *itr);

	// SculptModifierInterface
	SculptModifierInterface*	(*sculptmodifierinterfaceAlloc)();
	void											(*sculptmodifierinterfaceFree)(SculptModifierInterface *&brush);
	Bool											(*sculptmodifierinterfaceInit)(SculptModifierInterface *brush, PolygonObject *poly);
	void											(*sculptmodifierinterfaceClear)(SculptModifierInterface *brush);
	BaseContainer							(*sculptmodifierinterfaceGetDefaultData)(SculptModifierInterface *brush);
	Int32											(*sculptmodifierinterfaceGetModifierCount)(SculptModifierInterface *brush);
	Bool											(*sculptmodifierinterfaceGetModifierInfo)(SculptModifierInterface *brush, Int32 index, Int32 &modifierId, String &name);
	Bool											(*sculptmodifierinterfaceSetData)(SculptModifierInterface *brush, const BaseContainer &brushData, const BaseContainer &modifierData);
	Bool											(*sculptmodifierinterfaceApplyModifierPoly)(SculptModifierInterface *brush, Int32 modifierId, Int32 vertex, const BaseContainer &brushData, const BaseContainer &modifierData, Vector *pHitPoint, Vector *pLastHitPoint, Bool respectSelections);

	void	(iSculptBrushBase::*FloodSelectedLayerWithChannel)(SculptObject *pSculpt, SculptLayer *pLayer, const BaseContainer& brushData, Int32 function, BaseChannel *pChannel, Bool preview, Float *customStrength, const Vector32 *pVertexNormals);
	void	(iSculptBrushBase::*FloodSelectedLayerWithBitmap)(SculptObject *pSculpt, SculptLayer *pLayer, const BaseContainer& brushData, Int32 function, BaseBitmap *pBitmap, Bool preview, Float *customStrength, const Vector32 *pVertexNormals);
	Bool	(iSculptBrushBase::*FloodWithChannel)(BaseDocument* doc, BaseDraw* bd, const BaseContainer& brushData, BaseChannel *pChannel, Int32 button);
	Bool	(iSculptBrushBase::*FloodWithBitmap)(BaseDocument* doc, BaseDraw* bd, const BaseContainer& brushData, BaseBitmap *pBitmap, Int32 button);
	//================================================
	// R17 Additions
	//================================================
	void 	(iSculptBrushBase::*MouseData)(Int32 strokeInstanceID, const BaseContainer &brushData, const SculptMouseData &md);
	void 	(*sculptbrushparamsEnableMouseData)(SculptBrushParams *pParams, Bool enable);
	void 	(*sculptbrushparamsEnableBackfaceSculpting)(SculptBrushParams *pParams, Bool enable);
	Bool 	(*brushDabDataIsBackface)(BrushDabData *dab);
	const Vector32*		(*brushDabDataGetFaceNormals)(BrushDabData *dab);
	Int32 	(*brushDabDataGetHitPolygon)(BrushDabData *dab);
	const Vector32*		(*brushDabDataGetOriginalVertexNormals)(BrushDabData *dab);
	void	(*sculptbrushparamsSetPolygonObjectDirtyFlags)(SculptBrushParams *pParams, DIRTYFLAGS flags);

};

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

/// @endcond

//----------------------------------------------------------------------------------------
/// Adds a modifier function. Modifiers can be used with any other sculpting brush.\n
/// It is possible to add as many of these modifiers as needed.
/// @note A brush Modifier can not access the brush data. So calling @c GetBrush() will return @formatConstant{nullptr}.
/// @param[in] id									@uniquePluginID
/// @param[in] name								The name of the modifier that will appear in the modifiers tab for every brush.
/// @param[in] g									The @c Alloc() method for the SculptBrushModifierData node.
/// @param[in] mode								The mode for the modifier. Note that @ref SCULPTBRUSHMODE::NORMAL modes can not use @ref SCULPTBRUSHMODE::GRAB modes as modifiers.
/// @param[in] type								The type of data that the modifier changes.
/// @param[in] resource						The name of the description resource file.
/// @param[in] hide								If @formatConstant{true} the modifier is not be displayed on the Modifier tab for any sculpting brush. But it can still be accessed via the SculptModifierInterface.
/// @param[in] brushFilters				A custom list of brushes ID to not display the modifier on specific sculpting brushes.\n
/// 															If the modifier is the same functionality as a brush include that brushes ID here and the modifier will be filtered when that brush is selected.
/// @param[in] brushRestrictions	A custom list of brushes ID to only display the modifier for specific sculpting brushes.
/// @param[in] diskLevel					The plugin level is similar to a version number. The default level is @em 0.\n
/// 															Increase this for new revisions of a plugin to allow for forward and backward compatibility.\n\n
/// 															As an example you may have updated a plugin. If you now need to write additional information for new settings or changed types for old settings increase the level.\n
/// 															During loading either a @em 0 is passed (if the file was written by the old plugin) or @em 1 (if the file was written by the new plugin). This allows to easily write/read new values.\n
/// 															For forward and backward compatibility to work any existing read order from a given level must not be changed. @C4D skips any new settings automatically if they have not been read.\n\n
/// 															@formatParam{disklevel} is only useful if variables are written/read in @ref NodeData::Write/@ref NodeData::Read.
/// @return												@trueIfOtherwiseFalse{successful}
//----------------------------------------------------------------------------------------
Bool RegisterBrushModifier(Int32 id, const String &name, DataAllocator *g, SCULPTBRUSHMODE mode, SCULPTBRUSHDATATYPE type, const String &resource, Bool hide = false, maxon::BaseArray<Int32> *brushFilters = nullptr, maxon::BaseArray<Int32> *brushRestrictions = nullptr, Int32 diskLevel = 0);

//----------------------------------------------------------------------------------------
/// @markInternal
/// Use RegisterBrushModifier() method instead of this.
/// @param[in] id									@uniquePluginID
/// @param[in] name								The name of the modifier that will appear in the modifiers tab for every brush.
/// @param[in] mode								The mode for the modifier. Note that @ref SCULPTBRUSHMODE::NORMAL modes can not use @ref SCULPTBRUSHMODE::GRAB modes as modifiers.
/// @param[in] type								The type of data that the modifier changes.
/// @param[in] brushFilters				A custom list of brushes ID to not display the modifier on specific sculpting brushes.\n
/// 															If the modifier is the same functionality as a brush include that brushes ID here and the modifier will be filtered when that brush is selected.
/// @param[in] brushRestrictions	A custom list of brushes ID to only display the modifier for specific sculpting brushes.
/// @param[in] hide								If @formatConstant{true} the modifier is not be displayed on the Modifier tab for any sculpting brush. But it can still be accessed via the SculptModifierInterface.
/// @return												@trueIfOtherwiseFalse{successful}
//----------------------------------------------------------------------------------------
Bool AddSculptBrushModifierFunction(Int32 id, String name, SCULPTBRUSHMODE mode, SCULPTBRUSHDATATYPE type, maxon::BaseArray<Int32> *brushFilters = nullptr, maxon::BaseArray<Int32> *brushRestrictions = nullptr, Bool hide = false);

//----------------------------------------------------------------------------------------
/// Determines if a tool is a Sculpt Brush:
/// @code
/// Int32 tool = GetActiveDocument()->GetAction();
/// Bool isBrush = IsSculptBrush(tool);
/// @endcode
/// @param[in] toolID							The ID of the tool to check.
/// @return												@trueIfOtherwiseFalse{the tool is a Sculpt Brush}
//----------------------------------------------------------------------------------------
Bool IsSculptBrush(Int32 toolID);

//----------------------------------------------------------------------------------------
/// Retrieves a pointer to the currently selected Sculpt Brush.
/// @param[in] doc								The document to check. @callerOwnsPointed{document}
/// @return												A pointer to the currently selected SculptBrushToolData if one is currently active, otherwise @formatConstant{nullptr}.
//----------------------------------------------------------------------------------------
SculptBrushToolData *GetSelectedSculptBrush(BaseDocument *doc);

/// @}

#endif // LIB_SCULPTBRUSH_H__

/// @}
