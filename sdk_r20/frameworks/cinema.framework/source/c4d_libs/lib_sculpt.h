/////////////////////////////////////////////////////////////
// CINEMA 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

/// @addtogroup Sculpting
/// @{

#ifndef LIB_SCULPT_H__
#define LIB_SCULPT_H__

#include <stdarg.h>

#include "c4d_library.h"
#include "c4d_baseobject.h"
#include "c4d_basetag.h"

/// @addtogroup group_sculptlibrary Sculpt
/// @ingroup group_library
/// @{

/// Sculpt library ID.
#define LIBRARY_SCULPT	1027453

/// @addtogroup SCULPT
/// @ingroup group_enumeration
/// @{
#define SCULPT_LAYER_ID 1026657							///< Sculpting Layer ID.
#define SCULPT_FOLDER_ID 1025836						///< Sculpting folder ID.
#define SCULPT_OBJECT_ID 1024033						///< Sculpting object ID. The SculptObject is a PolygonObject with a SculptTag
#define SCULPT_LAYERDATA_ID 1024016					///< Sculpting layer data ID.
#define SCULPT_LAYERSYSTEM_ID 1024014				///< Layer system ID.
#define SCULPT_BAKESETTINGS 1027539					///< Container ID for SculptObject Bake settings.
#define SCULPT_POLYGONOBJECT_ID 1028709			///< It SculptObject is just a wrapper for a normal PolygonObject (it has no SculptTag).
/// @}


//----------------------------------------------------------------------------------------
/// A SculptObject contains a SculptLayerSystem. This layer system can have many layers where each layer has exactly @em 1 SculptLayerData.\n
/// There is one exception to this rule, and that is the Base layer, which has a SculptLayerData for every subdivision level.\n
/// A SculptLayerData node contains all the offset and mask data for that layer at its subdivision level.
//----------------------------------------------------------------------------------------
class SculptLayerData : public BaseList2D
{
private:
	SculptLayerData();
	~SculptLayerData();

public:

	//----------------------------------------------------------------------------------------
	/// Gets the subdivision level that the layer contains data for.
	/// @return												The subdivision level.
	//----------------------------------------------------------------------------------------
	Int32 GetSubdivisionLevel();

	//----------------------------------------------------------------------------------------
	/// Gets the number of points on the polygon object that the layer has.
	/// @return												The number of points on the polygon object.
	//----------------------------------------------------------------------------------------
	Int32 GetPointCount();

	//----------------------------------------------------------------------------------------
	/// Gets the offset for the given point @formatParam{index} on the layer.
	/// @param[in] index							The index of the point on the polygon object: @em 0 <= @formatParam{index} < GetPointCount()
	/// @param[out] offset						Assigned the offset value for the point.
	/// @return												@formatConstant{true} if there was offset data for the point. @formatConstant{false} if no offset data was allocated for the point.
	//----------------------------------------------------------------------------------------
	Bool GetOffset(Int32 index, Vector &offset);

	//----------------------------------------------------------------------------------------
	/// Sets the offset for the given point @formatParam{index} on the layer.
	/// @warning	Be sure to call SculptObject::Update() after all changes to the offsets have been made. This will update the SculptObject display.\n
	///						Also call SculptObject::UpdateCollision() if any of the SculptObject::Hit() methods is used afterwards.\n
	///						If this method is going to be called from multiple threads then be sure to call InitializeAllPointData() before using this method.
	/// @param[in] index							The index of the point on the polygon object: @em 0 <= @formatParam{index} < GetPointCount()
	/// @param[out] fullOffset				The offset vector to set.
	//----------------------------------------------------------------------------------------
	void SetOffset(Int32 index, const Vector &fullOffset);

	//----------------------------------------------------------------------------------------
	/// Adds to the existing offset value at the given point @formatParam{index} on the layer.
	/// @warning	Be sure to call SculptObject::Update() after all changes to the offsets have been made. This will update the SculptObject display.\n
	///						Also call SculptObject::UpdateCollision() any of the SculptObject::Hit() methods is used afterwards.\n
	///						If this method is going to be called from multiple threads then be sure to call InitializeAllPointData() before using this method.
	/// @param[in] index							The index of the point on the polygon object: @em 0 <= @formatParam{index} < GetPointCount()
	/// @param[out] offset						The offset vector to add.
	//----------------------------------------------------------------------------------------
	void AddOffset(Int32 index, const Vector &offset);

	//----------------------------------------------------------------------------------------
	/// Gets the value of the mask at the given point @formatParam{index} on the layer.
	/// @param[in] index							The index of the point on the polygon object: @em 0 <= @formatParam{index} < GetPointCount()
	/// @param[out] mask							Assigned the mask value for the point.\n
	///																The value is between @em 0 and @em 1 where @em 0 means no mask and @em 1 fully masked.
	/// @return												@formatConstant{true} if there was mask data for the point. @formatConstant{false} if no mask data was allocated for the point.
	//----------------------------------------------------------------------------------------
	Bool GetMask(Int32 index, Float32 &mask);

	//----------------------------------------------------------------------------------------
	/// Sets the the mask at the given point @formatParam{index} on the layer.
	/// @warning If this method is going to be called from multiple threads then be sure to call InitializeAllMaskData() before using this method.
	/// @param[in] index							The index of the point on the polygon object: @em 0 <= @formatParam{index} < GetPointCount()
	/// @param[in] mask								The value of the mask. The value will be clamped between @em 0 and @em 1; @em 0 means no mask and @em 1 fully masked.
	//----------------------------------------------------------------------------------------
	void SetMask(Int32 index, Float32 mask);

	//----------------------------------------------------------------------------------------
	/// Adds to the existing mask at the given point @formatParam{index} on the layer.
	/// @warning If this method is going to be called from multiple threads then be sure to call InitializeAllMaskData() before using this method.
	/// @param[in] index							The index of the point on the polygon object: @em 0 <= @formatParam{index} < GetPointCount()
	/// @param[in] mask								The amount to add to the existing mask.
	//----------------------------------------------------------------------------------------
	void AddToMask(Int32 index, Float32 mask);

	//----------------------------------------------------------------------------------------
	/// Checks to see if the layer has a mask applied to it.
	/// @return												@trueIfOtherwiseFalse{there is mask data}
	//----------------------------------------------------------------------------------------
	Bool HasMask();

	//----------------------------------------------------------------------------------------
	/// Clears all the mask data for the layer.
	//----------------------------------------------------------------------------------------
	void ClearMask();

	//----------------------------------------------------------------------------------------
	/// Clears all the offsets for the layer.
	//----------------------------------------------------------------------------------------
	void ClearLayer();

	//----------------------------------------------------------------------------------------
	/// Makes sure all the data has been allocated to store all the point data.\n
	/// @note	If SetOffset() or AddOffset() are called from multiple threads then the data needs to be initialized before these calls are made.\n
	///				If multiple threads are not used the calls to SetOffset() and AddOffset() will only allocate data if required.
	//----------------------------------------------------------------------------------------
	void InitializeAllPointData();

	//----------------------------------------------------------------------------------------
	/// Makes sure all the data has been allocated to store all the mask data.\n
	/// @note	If SetMask() or AddToMask() are called from multiple threads then the data needs to be initialized before these calls are made.\n
	///				If multiple threads are not used the calls to SetMask() and AddToMask() will only allocate data if required.
	//----------------------------------------------------------------------------------------
	void InitializeAllMaskData();

	//----------------------------------------------------------------------------------------
	/// Marks the point at @formatParam{index} so that any modifications to it can be undone.
	/// @warning	Must be called after SculptObject::StartUndo().\n
	///						This method can not be called from multiple threads.
	/// @param[in] index							The index of the point on the polygon object: @em 0 <= @formatParam{index} < GetPointCount()
	//----------------------------------------------------------------------------------------
	void TouchPointForUndo(Int32 index);

	//----------------------------------------------------------------------------------------
	/// Marks the masked point at @formatParam{index} so that any modifications to the mask can be undone.
	/// @warning	Must be called after SculptObject::StartUndo().\n
	///						This method can not be called from multiple threads.
	/// @param[in] index							The index of the point on the polygon object: @em 0 <= @formatParam{index} < GetPointCount()
	//----------------------------------------------------------------------------------------
	void TouchMaskForUndo(Int32 index);
};


//----------------------------------------------------------------------------------------
/// Base class for sculpt layers.
//----------------------------------------------------------------------------------------
class SculptLayerBase : public BaseList2D
{
private:
	SculptLayerBase();
	~SculptLayerBase();

public:

	//----------------------------------------------------------------------------------------
	/// Selects the layer. Only works if the subdivision level is at the same level as the layer.
	/// @return												@trueIfOtherwiseFalse{the layer was selected}
	//----------------------------------------------------------------------------------------
	Bool Select();

	//----------------------------------------------------------------------------------------
	/// Checks if the layer is currently visible on the SculptObject.
	/// @return												@trueIfOtherwiseFalse{the layer is visible}
	//----------------------------------------------------------------------------------------
	Bool IsVisible();

	//----------------------------------------------------------------------------------------
	/// Sets the visibility of the layer on the SculptObject.
	/// @param[in] value							The visibility state.
	//----------------------------------------------------------------------------------------
	void SetVisible(Bool value);

	//----------------------------------------------------------------------------------------
	/// Checks if the layer is currently locked on the SculptObject.
	/// @return												@trueIfOtherwiseFalse{the layer is locked}
	//----------------------------------------------------------------------------------------
	Bool IsLocked();

	//----------------------------------------------------------------------------------------
	/// Sets the locked status of the layer on the SculptObject.
	/// @param[in] value							The locked state.
	//----------------------------------------------------------------------------------------
	void SetLocked(Bool value);

	//----------------------------------------------------------------------------------------
	/// Get the currents strength of the layer on the SculptObject.
	/// @return												The strength value.
	//----------------------------------------------------------------------------------------
	Float GetStrength();

	//----------------------------------------------------------------------------------------
	/// Sets the strength of the layer on the SculptObject.
	/// @param[in] value							The strength value to set.
	//----------------------------------------------------------------------------------------
	void SetStrength(Float value);
};


//----------------------------------------------------------------------------------------
/// A sculpt layer can contain one or more SculptLayerData children.
//----------------------------------------------------------------------------------------
class SculptLayer : public SculptLayerBase
{
private:
	SculptLayer();
	~SculptLayer();

public:

	//----------------------------------------------------------------------------------------
	/// Gets the first layer data for the layer.
	/// @note The Base layer has more than @em 1, other layers only have @em 1.
	/// @return												The first layer data.
	//----------------------------------------------------------------------------------------
	SculptLayerData *GetFirstSculptLayerData();

	//----------------------------------------------------------------------------------------
	/// Gets the currently used layer data.
	/// @note	In the case of the Base layer it returns the data for the current subdivision level.\n
	///				For all other layers it returns the same as GetFirstSculptLayerData().
	/// @return												The currently used layer data.
	//----------------------------------------------------------------------------------------
	SculptLayerData *GetCurrentSculptLayerData();

	//----------------------------------------------------------------------------------------
	/// Gets the number of points the layer has.
	/// @note The point count is the same as the number of points on the PolygonObject for the subdivision level that this layer is at.
	/// @return												The number of points.
	//----------------------------------------------------------------------------------------
	Int32 GetPointCount();

	//----------------------------------------------------------------------------------------
	/// Gets the offset value for the point at @formatParam{index} on the layer.
	/// @note This method gets the correct SculptLayerData for the layer and call the corresponding method for it.
	/// @param[in] index							The index of the point on the layer: @em 0 <= @formatParam{index} < GetPointCount()
	/// @param[out] offset						Assigned the offset.
	/// @return												@formatConstant{true} if there was offset data for the point. @formatConstant{false} if no offset data was allocated for the point.
	//----------------------------------------------------------------------------------------
	Bool GetOffset(Int32 index, Vector &offset);

	//----------------------------------------------------------------------------------------
	/// Sets the offset Vector for the given point at @formatParam{index} on the layer.
	/// @note This method gets the correct SculptLayerData for the layer and call the corresponding method for it.
	/// @warning	Be sure to call SculptObject::Update() after all changes to the offsets have been made. This will update the SculptObject display.\n
	///						Also call SculptObject::UpdateCollision() if any of the SculptObject::Hit() methods is used aftewards.\n
	///						If this method is called from multiple threads then be sure to call InitializeAllPointData() before.
	/// @param[in] index							The index of the point on the layer: @em 0 <= @formatParam{index} < GetPointCount()
	/// @param[in] fullOffset					The offset vector to set.
	//----------------------------------------------------------------------------------------
	void SetOffset(Int32 index, const Vector &fullOffset);

	//----------------------------------------------------------------------------------------
	/// Adds an offset Vector to the existing offset for the given point at @formatParam{index} on the layer.
	/// @note This method gets the correct SculptLayerData for the layer and call the corresponding method for it.
	/// @warning	Be sure to call SculptObject::Update() after all changes to the offsets have been made. This will update the SculptObject display.\n
	///						Also call SculptObject::UpdateCollision() if any of the SculptObject::Hit() methods is used aftewards.\n
	///						If this method is called from multiple threads then be sure to call InitializeAllPointData() before.
	/// @param[in] index							The index of the point on the layer: @em 0 <= @formatParam{index} < GetPointCount()
	/// @param[in] offset							The offset vector to add.
	//----------------------------------------------------------------------------------------
	void AddOffset(Int32 index, const Vector &offset);

	//----------------------------------------------------------------------------------------
	/// Gets the mask value for the given point at @formatParam{index} on the layer.
	/// @note This method gets the correct SculptLayerData for the layer and call the corresponding method for it.
	/// @param[in] index							The index of the point on the layer: @em 0 <= @formatParam{index} < GetPointCount()
	/// @param[out] mask							Assigned the mask value for the point.\n
	///																The value is between @em 0 and @em 1 where @em 0 means no mask and @em 1 fully masked.
	/// @return												@formatConstant{true} if there was mask data for the point. @formatConstant{false} if no mask data was allocated for the point.
	//----------------------------------------------------------------------------------------
	Bool GetMask(Int32 index, Float32 &mask);

	//----------------------------------------------------------------------------------------
	/// Sets the mask value for the given point at @formatParam{index} on the layer.
	/// @note This method gets the correct SculptLayerData for the layer and call the corresponding method for it.
	/// @warning If this method is called from multiple threads then be sure to call InitializeAllPointData() before.
	/// @param[in] index							The index of the point on the layer: @em 0 <= @formatParam{index} < GetPointCount()
	/// @param[in] mask								The mask value to set. The value will be clamped between @em 0 and @em 1; @em 0 means no mask and @em 1 fully masked.
	//----------------------------------------------------------------------------------------
	void SetMask(Int32 index, Float32 mask);

	//----------------------------------------------------------------------------------------
	/// Adds to the existing mask value for the given point at @formatParam{index} on the layer.
	/// @note This method gets the correct SculptLayerData for the layer and call the corresponding method for it.
	/// @warning If this method is called from multiple threads then be sure to call InitializeAllMaskData() before.
	/// @param[in] index							The index of the point on the layer: @em 0 <= @formatParam{index} < GetPointCount()
	/// @param[in] mask								The value to add to the mask. The value will be clamped between @em 0 and @em 1; @em 0 means no mask and @em 1 fully masked.
	//----------------------------------------------------------------------------------------
	void AddToMask(Int32 index, Float32 mask);

	//----------------------------------------------------------------------------------------
	/// Clears the mask data for the layer.
	/// @note This method gets the correct SculptLayerData for the layer and call the corresponding method for it.
	//----------------------------------------------------------------------------------------
	void ClearMask();

	//----------------------------------------------------------------------------------------
	/// Clears all the offset data for the layer.
	/// @note This method gets the correct SculptLayerData for the layer and call the corresponding method for it.
	//----------------------------------------------------------------------------------------
	void ClearLayer();

	//----------------------------------------------------------------------------------------
	/// Makes sure all the data has been allocated to store the point data.
	/// @note This method gets the correct SculptLayerData for the layer and call the corresponding method for it.\n
	///				If SetOffset() or AddOffset() are called from multiple threads then the data needs to be initialized before these calls are made.\n
	///				If multiple threads are not used the calls to SetOffset() and AddOffset() will only allocate data if required.
	//----------------------------------------------------------------------------------------
	void InitializeAllPointData();

	//----------------------------------------------------------------------------------------
	/// Makes sure all the data has been allocated to store the mask data.
	/// @note This method gets the correct SculptLayerData for the layer and call the corresponding method for it.\n
	///				If SetMask() or AddToMask() are called from multiple threads then the data needs to be initialized before these calls are made.\n
	///				If multiple threads are not used the calls to SetMask() and AddToMask() will only allocate data if required.
	//----------------------------------------------------------------------------------------
	void InitializeAllMaskData();

	//----------------------------------------------------------------------------------------
	/// Marks the point at @formatParam{index} so that any modifications to it can be undone.
	/// @note This method gets the correct SculptLayerData for the layer and call the corresponding method for it.\n
	/// @warning	Must be called after SculptObject::StartUndo().\n
	///						This method can not be called from multiple threads.
	/// @param[in] index							The index of the point on the layer: @em 0 <= @formatParam{index} < GetPointCount()
	//----------------------------------------------------------------------------------------
	void TouchPointForUndo(Int32 index);

	//----------------------------------------------------------------------------------------
	/// Marks the masked point @formatParam{index} so that any modifications it can be undone.
	/// @note This method gets the correct SculptLayerData for the layer and call the corresponding method for it.\n
	/// @warning	Must be called after SculptObject::StartUndo().\n
	///						This method can not be called from multiple threads.
	/// @param[in] index							The index of the point on the layer: @em 0 <= @formatParam{index} < GetPointCount()
	//----------------------------------------------------------------------------------------
	void TouchMaskForUndo(Int32 index);

	//----------------------------------------------------------------------------------------
	/// Checks if the layer is the Base layer in which case it will have more than one ScultLayerData children.
	/// @return												@formatConstant{true} if the layer is the Base layer, @formatConstant{false} if it is a regular layer.
	//----------------------------------------------------------------------------------------
	Bool IsBaseLayer();

	//----------------------------------------------------------------------------------------
	/// Checks if the layer has a mask at the current subdivision level.
	/// @note This method gets the correct SculptLayerData for this layer and call the corresponding method for it.
	/// @return												@trueIfOtherwiseFalse{there is mask data}
	//----------------------------------------------------------------------------------------
	Bool HasMask();

	//----------------------------------------------------------------------------------------
	/// Checks if the mask is enabled for the layer at the current subdivision level.
	/// @return												@trueIfOtherwiseFalse{mask is enabled}
	//----------------------------------------------------------------------------------------
	Bool IsMaskEnabled();

	//----------------------------------------------------------------------------------------
	/// Sets the mask enabled state for the layer at the current subdivision level.
	/// @param[in] value							The state of the mask.
	//----------------------------------------------------------------------------------------
	void SetMaskEnabled(Bool value);
};


//----------------------------------------------------------------------------------------
/// A SculptFolder can contain many SculptLayer objects or other SculptFolder objects as children.
//----------------------------------------------------------------------------------------
class SculptFolder : public SculptLayerBase
{
private:
	SculptFolder();
	~SculptFolder();
};


//----------------------------------------------------------------------------------------
/// A SculptLayerSystem has one or more SculptLayer or SculptFolder as children.
/// - SculptObject
///		- SculptLayerSystem
///			- SculptLayer (if this is the Base layer it will have more than one SculptLayerData as children, one for each subdivision level).
///				- SculptLayerData (Level 0)
///				- SculptLayerData (Level 1)
///				- SculptLayerData (Level 2)
///			- SculptFolder
///				- SculptLayer (Other layers have one SculptLayerData for the subdivision level that the layer was created at).
///					- SculptLayerData (Level 2)
///			- SculptLayer
///				- SculptLayerData (Level 1)
///			- SculptLayer
///				- SculptLayerData (Level 2)
//----------------------------------------------------------------------------------------
class SculptLayerSystem : public BaseList2D
{
private:
	SculptLayerSystem();
	~SculptLayerSystem();
};


//----------------------------------------------------------------------------------------
/// Data structure filled out by the SculptObject::Hit() methods.
//----------------------------------------------------------------------------------------
struct SculptHitData
{
	Vector localHitPoint;				///< The location of the hit point on the surface of the object in its local coordinate system.
	Vector32 localHitNormal;		///< The normal of the hit point on the surface of the object in its local coordinate system.
	Int32 selectedPolygon;			///< The polygon that was hit.
	Float distance;							///< The distance from @c rayp. See SculptObject::Hit(const Vector &rayp, const Vector &rayv, Bool backfaces, SculptHitData &hitData).
	Bool backface;							///< The hit polygon was a backfacing polygon.
};


//----------------------------------------------------------------------------------------
/// A SculptObject is used to interact with the data referenced by a SculptTag.\n
/// The SculptTag on a PolygonObject references a SculptObject that is stored in a Scene Hook within the document.\n
/// When the SculptTag is deleted the referenced SculptObject is also deleted.
//----------------------------------------------------------------------------------------
class SculptObject : public BaseList2D
{
private:
	SculptObject();
	~SculptObject();

public:
	//----------------------------------------------------------------------------------------
	/// Gets the number of Subdivisions that the SculptObject currently has, i.e. how many times it has been subdivided by the user.
	/// @return												The number of subdivision levels.
	//----------------------------------------------------------------------------------------
	Int32 GetSubdivisionCount();

	//----------------------------------------------------------------------------------------
	/// Gets a copy of the SculptObject at a specific subdivision level.
	/// @note The returned object does not contain a copy of the SculptTag.
	/// @param[in] subdivisionLevel		The subdivision level to copy the PolyonObject at.
	/// @param[in] includeTopLevels		If True includes all the detail from any layers that are above @formatParam{subdivisionLevel}.\n
	///																If false includes only the sculpting data for all layers up to and including the @formatParam{subdivisionLevel} specified.
	/// @return												The PolygonObject for the subdivision level. @callerOwnsPointed{PolygonObject}
	//----------------------------------------------------------------------------------------
	PolygonObject *GetPolygonCopy(Int32 subdivisionLevel, Bool includeTopLevels = true);

	//----------------------------------------------------------------------------------------
	/// Gets the original PolygonObject that the SculptTag is applied to.
	/// @return												The original PolygonObject that the SculptTag is applied to. @theOwnsPointed{document,PolygonObject}
	//----------------------------------------------------------------------------------------
	PolygonObject *GetOriginalObject();

	//----------------------------------------------------------------------------------------
	/// Gets the PolygonObject that is currently being displayed in the viewport.
	/// @note In SculptBrushToolData::FloodSelectedLayer() calls this returns the same as GetOriginalObject() when sculpting on Polygon Objects that have no SculptTag.
	/// @return												The PolygonObject displayed in the viewport. This is the internal Polygon Object and should never be changed!
	//----------------------------------------------------------------------------------------
	PolygonObject *GetDisplayPolygonObject();

	//----------------------------------------------------------------------------------------
	/// From a viewport cast a ray, in screen space, onto the SculptObject and return any data if the ray hits the object.
	/// @note Returns the closest hit point if multiple intersections are found.
	/// @warning To use the Hit() methods the mesh must be unfrozen and both @c NeedCollisionUpdate(true) and @c UpdateCollision() should be called to initialize the collision data.
	/// @param[in] bd									The view that the user is casting the ray from. @callerOwnsPointed{view}
	/// @param[in] mx									The X coordinate (mouse coordinate) in screen space.
	/// @param[in] my									The Y coordinate (mouse coordinate) in screen space.
	/// @param[in] backfaces					@formatConstant{true} to allow back facing polygons to be hit tested.\n
	///																If enabled and the back facing hit point is closer than the front hit point, then it is returned.
	/// @param[out] hitData						Filled with the intersection data if the ray hits the object.
	/// @return												@trueIfOtherwiseFalse{the SculptObject was hit}
	//----------------------------------------------------------------------------------------
	Bool Hit(BaseDraw* bd, Float mx, Float my, Bool backfaces, SculptHitData &hitData);

	//----------------------------------------------------------------------------------------
	/// Given a ray in object space do a hit intersection against the SculptObject and return any data if the ray hits the object.
	/// @note Returns the closest hit point if multiple intersections are found.
	/// @warning To use the Hit() methods the mesh must be unfrozen and both @c NeedCollisionUpdate(true) and @c UpdateCollision() should be called to initialize the collision data.
	/// @param[in] rayp								The starting position of the ray in object space.
	/// @param[in] rayv								The direction the ray is pointing.
	/// @param[in] backfaces					@formatConstant{true} to allow back facing polygons to be hit tested.\n
	///																If enabled and the back facing hit point is closer than the front hit point, then it is returned.
	/// @param[out] hitData						Filled with the intersection data if the ray hits the object.
	/// @return												@trueIfOtherwiseFalse{the SculptObject was hit}
	//----------------------------------------------------------------------------------------
	Bool Hit(const Vector &rayp, const Vector &rayv, Bool backfaces, SculptHitData &hitData);

	//----------------------------------------------------------------------------------------
	/// Gets the number of polygons at the current subdivision level.
	/// @return												The number of polygons.
	//----------------------------------------------------------------------------------------
	Int32 GetPolygonCount();

	//----------------------------------------------------------------------------------------
	/// Gets the number of points at the current subdivision level.
	/// @return												The number of points.
	//----------------------------------------------------------------------------------------
	Int32 GetPointCount();

	//----------------------------------------------------------------------------------------
	/// Gets the currently selected layer, or folder, selected for the SculptObject.
	/// @return												The currently selected layer or folder.
	//----------------------------------------------------------------------------------------
	SculptLayerBase *GetCurrentLayer();

	//----------------------------------------------------------------------------------------
	/// Gets the current subdivision level that the SculptObject is currently at.
	/// @return												The current subdivision level.
	//----------------------------------------------------------------------------------------
	Int32 GetCurrentLevel();

	//----------------------------------------------------------------------------------------
	/// Gets the amount of memory currently used for the SculptObject. This does not include any memory used by @em OpenGL.
	/// @return												The memory used in bytes.
	//----------------------------------------------------------------------------------------
	UInt32 GetMemoryUsage();

	//----------------------------------------------------------------------------------------
	/// Creates a new layer on the SculptObject at the current subdivision level.
	/// @return												The added layer. @theOwnsPointed{SculptObject,SculptLayer}
	//----------------------------------------------------------------------------------------
	SculptLayer *AddLayer();

	//----------------------------------------------------------------------------------------
	/// Creates a new folder for the SculptObject.
	/// @return												The added folder. @theOwnsPointed{SculptObject,SculptFolder}
	//----------------------------------------------------------------------------------------
	SculptFolder *AddFolder();

	//----------------------------------------------------------------------------------------
	/// Deletes the currently selected layer (or folder) on the SculptObject (as specified in the Sculpt Layer Manager UI).
	/// @note	If the currently selected layer is a folder then it will only delete the folder if all the layers
	///				that are contained in that folder are at the same subdivision level as the current subdivision level.
	/// @return												@trueIfOtherwiseFalse{the layer was deleted}
	//----------------------------------------------------------------------------------------
	Bool DeleteSelectedLayer();

	//----------------------------------------------------------------------------------------
	/// Updates all the layers and the SculptObject.
	//----------------------------------------------------------------------------------------
	void Update();

	//----------------------------------------------------------------------------------------
	/// Gets the vertex normals for the PolygonObject at its current subdivision level.
	/// @return												The vertex normals.
	//----------------------------------------------------------------------------------------
	const Vector32 *GetVertexNormals();

	//----------------------------------------------------------------------------------------
	/// Gets the face normals for the PolygonObject at its current subdivision level.
	/// @since R17.032
	/// @return												The face normals.
	//----------------------------------------------------------------------------------------
	const Vector32 *GetFaceNormals();

	//----------------------------------------------------------------------------------------
	/// Gets read only access to the points that will be used for the PolygonObject at its current subdivision level.
	/// @return												The points.
	//----------------------------------------------------------------------------------------
	const Vector *GetPointR();

	//----------------------------------------------------------------------------------------
	/// Gets write access to the points that will be used for the display of the PolygonObject at the current subdivision level in the viewport.
	/// @warning	This method should only be used with the call OffsetPoint(), which should only ever be called from SculptBrushToolData::FloodSelectedLayer().
	/// @return												The points.
	//----------------------------------------------------------------------------------------
	Vector *GetPointW();

	//----------------------------------------------------------------------------------------
	/// Subdivides the SculptObject to the next level.
	/// @warning	Only works if the SculptObject is already at the top most level and the memory limit (as specified in the preferences)
	///						has not been exceeded and also only if there is enough memory on the users computer to successfully do the subdivision.
	/// @return												@trueIfOtherwiseFalse{the object was successfully subdivided}
	//----------------------------------------------------------------------------------------
	Bool Subdivide();

	//----------------------------------------------------------------------------------------
	/// Increases the subdivision level to the next highest level. If it is already at the top subdivision level then it will do nothing.
	/// @return												@trueIfOtherwiseFalse{it was able go up a level}
	//----------------------------------------------------------------------------------------
	Bool IncreaseSubdivisionLevel();

	//----------------------------------------------------------------------------------------
	/// Decreases the subdivision level to the down one level. If it is already at level @em 0 then it will do nothing.
	/// @return												@trueIfOtherwiseFalse{it was able go down a level}
	//----------------------------------------------------------------------------------------
	Bool DecreaseSubdivisionLevel();

	//----------------------------------------------------------------------------------------
	/// Gets the first layer under the SculptLayerSystem. This is usually the Base layer.
	/// @return												The first layer.
	//----------------------------------------------------------------------------------------
	SculptLayerBase *GetFirstLayer();

	//----------------------------------------------------------------------------------------
	/// Gets the Base layer, which is the special layer that has multiple SculptLayerData children, one for each subdivision level, that allows the user to sculpt on while at any subdivision level.
	/// @return												The Base layer.
	//----------------------------------------------------------------------------------------
	SculptLayer		*GetBaseLayer();

	//----------------------------------------------------------------------------------------
	/// Gets the layer system that contains all the layers. This is a child node of the SculptObject.
	/// @return												The layer system.
	//----------------------------------------------------------------------------------------
	SculptLayerSystem *GetLayerSystem();

	//----------------------------------------------------------------------------------------
	/// Checks if the SculptObject been frozen. In the UI this is shown in the SculpTag.
	/// @return												@trueIfOtherwiseFalse{the object was frozen}
	//----------------------------------------------------------------------------------------
	Bool IsFrozen();

	//----------------------------------------------------------------------------------------
	/// Sets the frozen state of the SculptObject. In the UI this is shown in the SculpTag.\n
	/// When the object is frozen no changes to the SculptObject or any of its layers are allowed.
	/// @note	If the PolygonObject has a PhongTag it will also become active when the SculptObject is Frozen.\n
	///				When not Frozen then SculptObject uses its own internal Vertex Normals and disables the PhongTag on the PolygonObject.\n
	/// @param[in] value							The frozen state.
	//----------------------------------------------------------------------------------------
	void SetFrozen(Bool value);

	//----------------------------------------------------------------------------------------
	/// Checks if the object is allowed to be deformed by any deformers. In the UI this is shown in the SculpTag.\n
	/// @note	This option only works if the object is also Frozen.
	///				When both these options are enabled, any deformers that are children of the PolygonObject that the SculptTag is applied to, will be able to deform the object in the viewport.
	/// @return												@trueIfOtherwiseFalse{the object was frozen}
	//----------------------------------------------------------------------------------------
	Bool GetAllowDeformations();

	//----------------------------------------------------------------------------------------
	/// Sets the "Allow Deformations" checkbox thereby allowing any deformers to have an effect on the display of the SculptObject, as long as it is also frozen.\n
	/// In the UI this is shown in the SculpTag.
	/// @param[in] value							The "Allow Deformations" state.
	//----------------------------------------------------------------------------------------
	void SetAllowDeformations(Bool value);

	//----------------------------------------------------------------------------------------
	/// Updates any collision data after any changes to the SculptLayer Offsets have been made.
	/// @warning This is required before calling the Hit() methods.
	//----------------------------------------------------------------------------------------
	void UpdateCollision();

	//----------------------------------------------------------------------------------------
	/// Tells the SculptObject that it requires a collision update before the user tries to use any of the Sculpt tools.\n
	/// Then next time a user tries to use a tool it will first call UpdateCollision() to ensure that the Hit() calls will be correct.
	/// @param[in] fullUpdate					@formatConstant{true} to update the full mesh, this is not always required.
	//----------------------------------------------------------------------------------------
	void NeedCollisionUpdate(Bool fullUpdate = false);

	//----------------------------------------------------------------------------------------
	/// Offsets a point on the layer when when the interactive flood operation has finished. This is called on the SculptObject by the Sculpt tools.
	/// @warning Should only be called from within SculptBrushToolData::FloodSelectedLayer().
	/// @param[in] pLayer							The SculptLayer that the brush is operating on.
	/// @param[in] pPoints						The points from the call to GetPoints() which are used to directly effect the drawing of the SculptObject in the viewport.
	/// @param[in] useMask						@formatConstant{true} to respect the Mask on the Layer or not.
	/// @param[in] strength						The strength of the SculptLayer.
	/// @param[in] index							The index of the point on the PolygonObject for the current subdivision level.
	/// @param[in] offset							The offset to apply to the preview layer.
	/// @param[in] respectLayerStrength	@formatConstant{true} to respect the strength of the layer or ignore it updating the mesh on screen.
	//----------------------------------------------------------------------------------------
	void OffsetPoint(SculptLayer *pLayer, Vector *pPoints, Bool useMask, Float strength, Int32 index, const Vector &offset, Bool respectLayerStrength = false);

	//----------------------------------------------------------------------------------------
	/// Adds to the value of the offset on the preview layer when used to do interactive flood updates on the SculptObject by the Sculpt tools.
	/// @warning Should only be called from within SculptBrushToolData::FloodSelectedLayer().
	/// @param[in] pLayer							The SculptLayer that the brush is operating on.
	/// @param[in] useMask						@formatConstant{true} to respect the Mask on the Layer or not.
	/// @param[in] strength						The strength of the SculptLayer.
	/// @param[in] index							The index of the point on the PolygonObject for the current subdivision level.
	/// @param[in] offset							The offset to apply to the preview layer.
	/// @param[in] respectLayerStrength	@formatConstant{true} to respect the strength of the layer or ignore it updating the mesh on screen.
	//----------------------------------------------------------------------------------------
	void OffsetPreviewPoint(SculptLayer *pLayer, Bool useMask, Float strength, Int32 index, const Vector &offset, Bool respectLayerStrength = false);

	//----------------------------------------------------------------------------------------
	/// Sets the value of the offset on the preview layer when used to do interactive flood updates on the SculptObject by the Sculpt tools.
	/// @warning Should only be called from within SculptBrushToolData::FloodSelectedLayer()
	/// @param[in] pLayer							The SculptLayer that the brush is operating on.
	/// @param[in] useMask						@formatConstant{true} to respect the Mask on the Layer or not.
	/// @param[in] strength						The strength of the SculptLayer.
	/// @param[in] index							The index of the point on the PolygonObject for the current subdivision level.
	/// @param[in] offset							The offset to set on the preview layer.
	/// @param[in] respectLayerStrength	@formatConstant{true} to respect the strength of the layer or ignore it updating the mesh on screen.
	//----------------------------------------------------------------------------------------
	void SetPreviewPoint(SculptLayer *pLayer, Bool useMask, Float strength, Int32 index, const Vector &offset, Bool respectLayerStrength = false);

	//----------------------------------------------------------------------------------------
	/// Calls before any calls to AddOffset(), SetOffset(), AddToMask() or SetMask() to be undone.
	/// @warning	This will only work if making changes to a single layer. Changes to multiple layers or layers at different levels is not allowed.\n
	///						This must be done at the current subdivision level of the layer being changed for these calls to work properly.\n
	///						EndUndo() must be called after all calls to the above methods have been done.\n
	///						This must NEVER be called by a Sculpt brush during a stroke.
	//----------------------------------------------------------------------------------------
	void StartUndo();

	//----------------------------------------------------------------------------------------
	/// Must be called after StartUndo() once all the point and masks have been changed on the layers.
	/// @warning This must NEVER be called by a Sculpt brush during a stroke.
	//----------------------------------------------------------------------------------------
	void EndUndo();

	//----------------------------------------------------------------------------------------
	/// Smooths the SculptObject and applies the offsets to the currently selected layer.
	/// @param[in] count							The number of times to run the smooth algorithm.
	/// @param[in] respectMask				If @formatConstant{true} it will not smooth any masked out points, if @formatConstant{false} it will apply it to every point.
	//----------------------------------------------------------------------------------------
	void Smooth(Int32 count, Bool respectMask);

	//----------------------------------------------------------------------------------------
	/// Gets the current mask values for the PolygonObject.\n
	/// The number of points returned is equal to the number of points on the PolygonObject.
	/// @return												The mask values.
	//----------------------------------------------------------------------------------------
	Float32 *GetMaskCache();

	//----------------------------------------------------------------------------------------
	/// Averages out the values for the @formatParam{vertex} on the PolygonObject.
	/// @param[in] vertex							The vertex number on the PolygonObject to get the average value for.
	/// @param[in] values							The values to average out. This must contain the same number of values as there are points on the PolygonObject.
	/// @return												The mask values.
	//----------------------------------------------------------------------------------------
	Float32 PointPolysAverage(Int32 vertex, Float32 *values);

	//----------------------------------------------------------------------------------------
	/// Averages out the values for the @formatParam{vertex} on the PolygonObject.
	/// @param[in] vertex							The vertex number on the PolygonObject to get the average value for.
	/// @param[in] values							The values to average out. This must contain the same number of values as there are points on the PolygonObject.
	/// @return												The mask values.
	//----------------------------------------------------------------------------------------
	Vector PointPolysAverage(Int32 vertex, Vector *values);

	//----------------------------------------------------------------------------------------
	/// Updates the mask on the SculptObject.
	/// @param[in] fullUpdate					@formatConstant{true} to force a full update of the mask.
	//----------------------------------------------------------------------------------------
	void UpdateMask(Bool fullUpdate = false);

	//----------------------------------------------------------------------------------------
	/// @markPrivate\n
	/// Initializes the SculptObject for the given viewport in OpenGL use.
	/// @param[in] bd									The viewport that is being updated. If it is @formatConstant{nullptr} then the currently active view will be used.
	//----------------------------------------------------------------------------------------
	void InitOpenGL(BaseDraw *bd = nullptr);

	//----------------------------------------------------------------------------------------
	/// Determines if a point should be moved or not in the SculptBrushToolData::FloodSelectedLayer() method.
	/// @note	When in Point mode, and there is a selection, it returns @formatConstant{true} if a point is selected or @formatConstant{false} if the point is not selected.\n
	///				If there are no points selected it returns @formatConstant{true}.
	///				When in Polygon mode, and there is a selection, it returns @formatConstant{true} if a point on any of the selected polygons is selected or @formatConstant{false} if there is no point selected.\n
	///				If there are no polygons selected it returns @formatConstant{true}.
	/// @warning	This method only works when the selected object being sculpted on is by a tool and is a PolygonObject without a SculptTag.\n
	///						It returns @formatConstant{false} in all other cases.
	/// @param[in] index							The index of the point on the object: @em 0<= @formatParam{index} < GetPointCount()
	/// @return												@trueIfOtherwiseFalse{the point was selected}
	//----------------------------------------------------------------------------------------
	Bool IsPointSelected(Int32 index);

	//----------------------------------------------------------------------------------------
	/// Determines if a polygon should be moved or not in the SculptBrushToolData::FloodSelectedLayer() method.
	/// @note	When in Polygon mode, and there is a selection, it returns @formatConstant{true} if a point on any of the selected polygons is selected or @formatConstant{false} if there is no point selected.\n
	///				If there are no polygons selected it returns @formatConstant{true}.
	/// @warning	This method only works when the selected object being sculpted on is by a tool and is a PolygonObject without a SculptTag.\n
	///						It returns @formatConstant{false} in all other cases.
	/// @param[in] index							The index of the polygon on the object: @em 0<= @formatParam{index} < GetPolygonCount()
	/// @return												@trueIfOtherwiseFalse{the polygon was selected}
	//----------------------------------------------------------------------------------------
	Bool IsPolygonSelected(Int32 index);

	//----------------------------------------------------------------------------------------
	/// Gets the polygon data at the given @formatParam{index}.
	/// @param[in] index							The index of the polygon on the object: @em 0<= @formatParam{index} < GetPolygonCount()
	/// @param[out] cpoly							Filled with the polygon data.
	/// @return												True if the polygon was found, false if not.
	//----------------------------------------------------------------------------------------
	Bool GetPolygon(Int32 index, CPolygon &cpoly);
};

//----------------------------------------------------------------------------------------
/// When an PolygonObject is made sculptable it contains a SculptTag.\n
/// Each SculptTag references a SculptObject in the Document. This SculptObject contains all the layers and offsets used by the Sculpt tools.
//----------------------------------------------------------------------------------------
class SculptTag : public BaseTag
{
private:
	SculptTag();
	~SculptTag();
public:

	//----------------------------------------------------------------------------------------
	/// @allocatesA{sculpt tag}
	/// @note This does not usually need to be used. Instead use the helper method MakeSculptObject().
	/// @return												@allocReturn{sculpt tag}
	//----------------------------------------------------------------------------------------
	static SculptTag *Alloc() { return (SculptTag*)BaseTag::Alloc(Tsculpt); }

	//----------------------------------------------------------------------------------------
	/// @destructsAlloc{sculpt tags}
	/// @param[in] pTag								@theToDestruct{sculpt tag}
	//----------------------------------------------------------------------------------------
	static void Free(SculptTag *&pTag) { BaseTag *tag = pTag; BaseTag::Free(tag); pTag = nullptr; }

	//----------------------------------------------------------------------------------------
	/// Gets the SculptObject for the SculptTag.
	/// @return												The SculptObject that the sculpt tag references.
	//----------------------------------------------------------------------------------------
	SculptObject *GetSculptObject();
};

/// @cond IGNORE

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

struct SculptLibrary : public C4DLibrary
{
	// SculptLayerData R14
	Int32						(*sculptlayerdataGetSubdivisionLevel)(SculptLayerData *layerData);
	Int32						(*sculptlayerdataGetPointCount)(SculptLayerData *layerData);
	Bool						(*sculptlayerdataGetOffset)(SculptLayerData *layerData, Int32 index, Vector &offset);
	void						(*sculptlayerdataSetOffset)(SculptLayerData *layerData, Int32 index, const Vector &fullOffset);
	void						(*sculptlayerdataAddOffset)(SculptLayerData *layerData, Int32 index, const Vector &offset);
	Bool						(*sculptlayerdataGetMask)(SculptLayerData *layerData, Int32 index, Float32 &mask);
	void						(*sculptlayerdataSetMask)(SculptLayerData *layerData, Int32 index, Float32 mask);
	void						(*sculptlayerdataAddToMask)(SculptLayerData *layerData, Int32 index, Float32 mask);
	Bool						(*sculptlayerdataSelect)(SculptLayerData *layerData);
	Bool						(*sculptlayerdataHasMask)(SculptLayerData *layerData);

	// SculptLayerBase R14
	Bool						(*sculptlayerbaseSelect)(SculptLayerBase *layer);
	Bool						(*sculptlayerbaseIsVisible)(SculptLayerBase *layer);
	void						(*sculptlayerbaseSetVisible)(SculptLayerBase *layer, Bool value);
	Bool						(*sculptlayerbaseIsLocked)(SculptLayerBase *layer);
	void						(*sculptlayerbaseSetLocked)(SculptLayerBase *layer, Bool value);
	Float						(*sculptlayerbaseGetStrength)(SculptLayerBase *layer);
	void						(*sculptlayerbaseSetStrength)(SculptLayerBase *layer, Float value);

	// SculptLayer R14
	SculptLayerData*	(*sculptlayerGetFirstSculptLayerData)(SculptLayer *layer);
	Int32							(*sculptlayerGetPointCount)(SculptLayer *layer);
	Bool							(*sculptlayerGetOffset)(SculptLayer *layer, Int32 index, Vector &offset);
	void							(*sculptlayerSetOffset)(SculptLayer *layer, Int32 index, const Vector &fullOffset);
	void							(*sculptlayerAddOffset)(SculptLayer *layer, Int32 index, const Vector &offset);
	Bool							(*sculptlayerGetMask)(SculptLayer *layer, Int32 index, Float32 &mask);
	void							(*sculptlayerSetMask)(SculptLayer *layer, Int32 index, Float32 mask);
	void							(*sculptlayerAddToMask)(SculptLayer *layer, Int32 index, Float32 mask);
	Bool							(*sculptlayerIsBaseLayer)(SculptLayer *layer);
	Bool							(*sculptlayerHasMask)(SculptLayer *layer);
	Bool							(*sculptlayerIsMaskEnabled)(SculptLayer *layer);
	void							(*sculptlayerSetMaskEnabled)(SculptLayer *layer, Bool value);

	// SculptObject R14
	Int32							(*sculptobjGetSubdivisionCount)(SculptObject *obj);
	PolygonObject*		(*sculptobjGetPolygonCopy)(SculptObject *obj, Int32 subdivisionLevel, Bool includeTopLevels);
	PolygonObject*		(*sculptobjGetOriginalObject)(SculptObject *obj);
	Int32							(*sculptobjGetPolygonCount)(SculptObject *obj);
	SculptLayerBase*	(*sculptobjGetCurrentLayer)(SculptObject *obj);
	Int32							(*sculptobjGetCurrentLevel)(SculptObject *obj);
	UInt32						(*sculptobjGetMemoryUsage)(SculptObject *obj);
	Bool							(*sculptobjHitScreenEx)(SculptObject *obj, BaseDraw* bd, Float mx, Float my, SculptHitData &hitData);
	Bool							(*sculptobjHitObjectEx)(SculptObject *obj, const Vector &rayp, const Vector &rayv, SculptHitData &hitData);
	SculptLayer*			(*sculptobjAddLayer)(SculptObject *obj);
	SculptFolder*			(*sculptobjAddFolder)(SculptObject *obj);
	Bool							(*sculptobjDeleteSelectedLayer)(SculptObject *obj);
	void							(*sculptobjUpdate)(SculptObject *obj);
	Bool							(*sculptobjSubdivide)(SculptObject *obj);
	Bool							(*sculptobjIncreaseSubdivisionLevel)(SculptObject *obj);
	Bool							(*sculptobjDecreaseSubdivisionLevel)(SculptObject *obj);
	SculptLayerBase*	(*sculptobjGetFirstLayer)(SculptObject *obj);
	SculptLayer*			(*sculptobjGetBaseLayer)(SculptObject *obj);
	Bool							(*sculptobjIsFrozen)(SculptObject *obj);
	void							(*sculptobjSetFrozen)(SculptObject *obj, Bool value);
	void							(*sculptobjUpdateCollision)(SculptObject *obj);
	void							(*sculptobjNeedCollisionUpdate)(SculptObject *obj, Bool fullUpdate);
	Bool							(*sculptobjGetAllowDeformations)(SculptObject *obj);
	void							(*sculptobjSetAllowDeformations)(SculptObject *obj, Bool value);

	// SculptTag R14
	SculptObject*		(*sculpttagGetSculptObject)(SculptTag *tag);

	// SculptLayerData R15
	void						(*sculptlayerdataClearMask)(SculptLayerData *layerData);
	void						(*sculptlayerdataClearLayer)(SculptLayerData *layerData);
	void						(*sculptlayerdataInitializeAllPointData)(SculptLayerData *layerData);
	void						(*sculptlayerdataInitializeAllMaskData)(SculptLayerData *layerData);
	void						(*sculptlayerdataTouchPointForUndo)(SculptLayerData *layerData, Int32 index);
	void						(*sculptlayerdataTouchMaskForUndo)(SculptLayerData *layerData, Int32 index);

	// SculptLayer R15
	SculptLayerData*	(*sculptlayerGetCurrentSculptLayerData)(SculptLayer *layer);
	void							(*sculptlayerClearMask)(SculptLayer *layer);
	void							(*sculptlayerClearLayer)(SculptLayer *layer);
	void							(*sculptlayerInitializeAllPointData)(SculptLayer *layer);
	void							(*sculptlayerInitializeAllMaskData)(SculptLayer *layer);
	void							(*sculptlayerTouchPointForUndo)(SculptLayer *layer, Int32 index);
	void							(*sculptlayerTouchMaskForUndo)(SculptLayer *layer, Int32 index);

	// SculptObject R15
	Int32								(*sculptobjGetPointCount)(SculptObject *obj);
	Bool								(*sculptobjHitScreen)(SculptObject *obj, BaseDraw* bd, Float mx, Float my, Bool backfaces, SculptHitData &hitData);
	Bool								(*sculptobjHitObject)(SculptObject *obj, const Vector &rayp, const Vector &rayv, Bool backfaces, SculptHitData &hitData);
	const Vector32 *		(*sculptobjGetVertexNormals)(SculptObject *obj);
	Vector *						(*sculptobjGetPointW)(SculptObject *obj);
	const Vector *			(*sculptobjGetPointR)(SculptObject *obj);
	void								(*sculptobjOffsetPoint)(SculptObject *obj, SculptLayer *pLayer, Vector *pPoints, Bool useMask, Float opacity, Int32 index, const Vector &offset, Bool respectOpacity);
	void								(*sculptobjOffsetPreviewPoint)(SculptObject *obj, SculptLayer *pLayer, Bool useMask, Float opacity, Int32 index, const Vector &offset, Bool respectOpacity);
	void								(*sculptobjSetPreviewPoint)(SculptObject *obj, SculptLayer *pLayer, Bool useMask, Float opacity, Int32 index, const Vector &offset, Bool respectOpacity);
	SculptLayerSystem*	(*sculptobjGetLayerSystem)(SculptObject *obj);
	void								(*sculptobjStartUndo)(SculptObject *obj);
	void								(*sculptobjEndUndo)(SculptObject *obj);
	void								(*sculptobjSmooth)(SculptObject *obj, Int32 count, Bool respectMask);

	// SculptObject R16
	Float32 *				(*sculptobjGetMaskCache)(SculptObject *obj);
	Float32					(*sculptobjPointPolysAverageFloat32)(SculptObject *obj, Int32 vertex, Float32 *values);
	Vector					(*sculptobjPointPolysAverageVector)(SculptObject *obj, Int32 vertex, Vector *values);
	void						(*sculptobjUpdateMask)(SculptObject *obj, Bool fullUpdate);
	void						(*sculptobjInitOpenGL)(SculptObject *obj, BaseDraw *bd);
	Bool						(*sculptobjIsPointSelected)(SculptObject *obj, Int32 index);
	Bool						(*sculptobjIsPolygonSelected)(SculptObject *obj, Int32 index);
	Bool						(*sculptobjGetPolygon)(SculptObject *obj, Int32 index, CPolygon &cpoly);
	PolygonObject*	(*sculptobjGetDisplayPolygonObject)(SculptObject *obj);

	// SculptObject R17
	const Vector32 *			(*sculptobjGetFaceNormals)(SculptObject *obj);

};

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

/// @endcond

//----------------------------------------------------------------------------------------
/// Gets the currently selected SculptObject in the document. This is the first selected PolygonObject that has a SculptTag.
/// @param[in] doc								The document to search. @callerOwnsPointed{document}
/// @param[in] includeHiddenObjects	@formatConstant{true} to include selected hidden objects.
/// @return												The SculptObject that the SculptTag references.
//----------------------------------------------------------------------------------------
SculptObject *GetSelectedSculptObject(BaseDocument *doc, Bool includeHiddenObjects = false);

//----------------------------------------------------------------------------------------
/// Adds a SculptTag to the PolygonObject if one does not exist then return the SculptObject that the newly created SculptTag references.
/// @param[in] poly								The PolygonObject to add the SculptTag to. @callerOwnsPointed{PolygonObject}
/// @param[in] doc								The document that the PolygonObject belongs to. @callerOwnsPointed{document}
/// @param[in] addUndo						If @formatConstant{true} then an undo event will be added so that the addition of the SculptTag can be undone.
/// @return												The SculptObject that the SculpTag references.
//----------------------------------------------------------------------------------------
SculptObject *MakeSculptObject(PolygonObject *poly, BaseDocument *doc, Bool addUndo = false);

//----------------------------------------------------------------------------------------
/// Checks if an object is currently visible in the viewport.
/// @param[in] pObject						The object to check. @callerOwnsPointed{object}
/// @return												@trueIfOtherwiseFalse{the object is enabled in the editor viewport}
//----------------------------------------------------------------------------------------
Bool IsObjectEnabled(BaseObject *pObject);

//----------------------------------------------------------------------------------------
/// Ensures that a copy a PolygonObject that has a SculptTag on it is initialized correctly straight after adding it to a document.
/// @param[in] obj								The PolygonObject that has the SculptTag. @callerOwnsPointed{PolygonObject}
/// @param[in] doc								The document the object belongs to. @callerOwnsPointed{document}
//----------------------------------------------------------------------------------------
void EnsureSculptObjectReady(PolygonObject *obj, BaseDocument *doc);

/// @}

#endif // LIB_SCULPT_H__

/// @}
