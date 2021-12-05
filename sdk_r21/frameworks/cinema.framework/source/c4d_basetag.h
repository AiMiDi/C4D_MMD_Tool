/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef C4D_BASETAG_H__
#define C4D_BASETAG_H__

#ifdef __API_INTERN__
#error "Not in the kernel"
#endif

#include "c4d_baselist.h"
#include "c4d_baseobject.h"
#include "operatingsystem.h"

class BaseObject;
class BaseSelect;
class EdgeBaseSelect;
class GvNodeMaster;

/// @addtogroup TAG
/// @ingroup group_enumeration
/// @{
#define TAG_VISIBLE					(1 << 0)			///< The tag can be seen in the Object Manager.
#define TAG_MULTIPLE				(1 << 1)			///< Multiple copies of the tag allowed on a single object.
#define TAG_HIERARCHICAL		(1 << 2)			///< The tag works hierarchical, so that sub-objects inherit its properties (e.g. the material tag).
#define TAG_EXPRESSION			(1 << 3)			///< The tag is an expression.
#define TAG_TEMPORARY				(1 << 4)			///< @markPrivate
#define TAG_MODIFYOBJECT		(1 << 6)			///< @markPrivate
#define TAG_ADDTOTAKEGROUP	(1 << 7)			///< The tag is added to the Take override groups system.
/// @}

//----------------------------------------------------------------------------------------
/// A variety of properties can be added to objects using tags.\n
/// For example, adding smoothing (Phong tag) or preventing an object from being edited accidentally (Protection tag).
/// @addAllocFreeAutoAllocNote
//----------------------------------------------------------------------------------------
class BaseTag : public BaseList2D
{
private:
	BaseTag();
	~BaseTag();

public:
	/// @name Alloc/Free
	/// @{

	//----------------------------------------------------------------------------------------
	/// @allocatesA{base tag}
	/// @param[in] type								The tag type: : @enumerateEnum{TagTypes}
	/// @return												@allocReturn{base tag}
	//----------------------------------------------------------------------------------------
	static BaseTag* Alloc(Int32 type);

	//----------------------------------------------------------------------------------------
	/// @destructsAlloc{base tags}
	/// @param[in,out] bl							@theToDestruct{base tag}
	//----------------------------------------------------------------------------------------
	static void Free(BaseTag*& bl);

	/// @}

	/// @name Navigation
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets the next tag in the list.
	/// @return												The next tag, or @formatConstant{nullptr} if there is none. @cinemaOwnsPointed{tag}
	//----------------------------------------------------------------------------------------
	BaseTag* GetNext(void) { return (BaseTag*)AtCall(GetNext) (); }

	//----------------------------------------------------------------------------------------
	/// Gets the previous tag in the list.
	/// @return												The previous tag, or @formatConstant{nullptr} if there is none. @cinemaOwnsPointed{tag}
	//----------------------------------------------------------------------------------------
	BaseTag* GetPred(void) { return (BaseTag*)AtCall(GetPred) (); }

	/// @}

	/// @name Miscellaneous
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets the object that the tag is attached to.
	/// @return												The host object, or @formatConstant{nullptr} if the tag is not associated with an object. @cinemaOwnsPointed{object}
	//----------------------------------------------------------------------------------------
	BaseObject* GetObject(void) { return (BaseObject*)AtCall(GetMain) (); }

	//----------------------------------------------------------------------------------------
	/// Gets where the tag was cloned from.\n
	/// For example, if the tag is on a cache object, it tells what the original tag was from the original document.
	/// @return												The origin of the tag, or @formatConstant{nullptr} if such information is not available. @cinemaOwnsPointed{object}
	//----------------------------------------------------------------------------------------
	BaseTag* GetOrigin();

	/// @}
};

//----------------------------------------------------------------------------------------
/// Represents the base class for tags storing multiple data elements with variable size.
/// @addAllocFreeAutoAllocNote
//----------------------------------------------------------------------------------------
class VariableTag : public BaseTag
{
private:
	VariableTag();
	~VariableTag();

public:
	/// @name Alloc/Free
	/// @{

	//----------------------------------------------------------------------------------------
	/// @allocatesA{variable tag}
	/// @param[in] type								The variable tag type: @enumerateEnum{VariableTagTypes}
	/// @param[in] count							The number of data elements in the allocated tag.
	/// @return												@allocReturn{variable tag}
	//----------------------------------------------------------------------------------------
	static VariableTag* Alloc(Int32 type, Int32 count);

	//----------------------------------------------------------------------------------------
	/// @destructsAlloc{variable tags}
	/// @param[in,out] bl							@theToDestruct{variable tag}
	//----------------------------------------------------------------------------------------
	static void Free(VariableTag*& bl);

	/// @}

	/// @name Get Data
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets the number of data elements in the variable tag.
	/// @return												The number of data elements.
	//----------------------------------------------------------------------------------------
	Int32 GetDataCount(void) const;

	//----------------------------------------------------------------------------------------
	/// Gets the size of one data element in bytes.
	/// @return												The byte size of a data element.
	//----------------------------------------------------------------------------------------
	Int32 GetDataSize(void) const;

	//----------------------------------------------------------------------------------------
	/// Gets a pointer to the read-only data for the variable tag.
	/// @warning Use with special care.
	/// @return												The read-only data array or @formatConstant{nullptr} if it fails. @theOwnsPointed{tag,data array}
	//----------------------------------------------------------------------------------------
	const void* GetLowlevelDataAddressR(void) const;

	//----------------------------------------------------------------------------------------
	/// Gets a pointer to the writable data for the variable tag.
	/// @warning Use with special care.
	/// @return												The writable data array or @formatConstant{nullptr} if it fails. @theOwnsPointed{tag,data array}
	//----------------------------------------------------------------------------------------
	void* GetLowlevelDataAddressW(void);

	/// @}
};

//----------------------------------------------------------------------------------------
/// Represents the Point tag.
//----------------------------------------------------------------------------------------
class PointTag : public VariableTag
{
private:
	PointTag();
	~PointTag();

public:
	/// @name Get Data
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets a pointer to the read-only point array.
	/// @return												The read-only point array. @theOwnsPointed{tag,point array}
	//----------------------------------------------------------------------------------------
	const Vector* GetDataAddressR(void) const;

	//----------------------------------------------------------------------------------------
	/// Gets a pointer to the writable point array.
	/// @return												The writable point array. @theOwnsPointed{tag,point array}
	//----------------------------------------------------------------------------------------
	Vector* GetDataAddressW(void);

	/// @}
};

//----------------------------------------------------------------------------------------
/// Represents the Vertex Map tag.
//----------------------------------------------------------------------------------------
class VertexMapTag : public VariableTag
{
private:
	VertexMapTag();
	~VertexMapTag();

public:
	/// @name Alloc/Free
	/// @{

	//----------------------------------------------------------------------------------------
	/// @allocatesA{vertex map tag}
	/// @param[in] count							The size of the vertex map data. Should be the same as the number of vertices of the parent object.
	/// @return												@allocReturn{vertex map tag}
	//----------------------------------------------------------------------------------------
	static VertexMapTag* Alloc(Int32 count);

	//----------------------------------------------------------------------------------------
	/// @destructsAlloc{vertex map tags}
	/// @param[in,out] bl							@theToDestruct{vertex map tag}
	//----------------------------------------------------------------------------------------
	static void Free(VertexMapTag*& bl);

	/// @}

	/// @name Get Data
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets a pointer to the read-only vertex map array.
	/// @return												The read-only vertex map array. @theOwnsPointed{tag,vertex map array}
	//----------------------------------------------------------------------------------------
	const Float32* GetDataAddressR(void) const;

	//----------------------------------------------------------------------------------------
	/// Gets a pointer to the writable vertex map array.
	/// @return												The writable vertex map array. @theOwnsPointed{tag,vertex map array}
	//----------------------------------------------------------------------------------------
	Float32* GetDataAddressW(void);

	/// @}
};

//----------------------------------------------------------------------------------------
/// Represents the Segment tag.
//----------------------------------------------------------------------------------------
class SegmentTag : public VariableTag
{
private:
	SegmentTag();
	~SegmentTag();

public:
	/// @name Get Data
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets a pointer to the read-only segment array.
	/// @return												The read-only segment array. @theOwnsPointed{tag,segment array}
	//----------------------------------------------------------------------------------------
	const Segment* GetDataAddressR(void) const;

	//----------------------------------------------------------------------------------------
	/// Gets a pointer to the writable segment array.
	/// @return												The writable segment array. @theOwnsPointed{tag,segment array}
	//----------------------------------------------------------------------------------------
	Segment* GetDataAddressW(void);

	/// @}
};

//----------------------------------------------------------------------------------------
/// Represents the Spline Tangent tag.
//----------------------------------------------------------------------------------------
class TangentTag : public VariableTag
{
private:
	TangentTag();
	~TangentTag();

public:
	/// @name Get Data
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets a pointer to the read-only tangent array.
	/// @return												The read-only tangent array. @theOwnsPointed{tag,tangent array}
	//----------------------------------------------------------------------------------------
	const Tangent* GetDataAddressR(void) const;

	//----------------------------------------------------------------------------------------
	/// Gets a pointer to the writable tangent array.
	/// @return												The writable tangent array. @theOwnsPointed{tag,tangent array}
	//----------------------------------------------------------------------------------------
	Tangent* GetDataAddressW(void);

	/// @}
};

//----------------------------------------------------------------------------------------
/// Represents the Polygon tag.
//----------------------------------------------------------------------------------------
class PolygonTag : public VariableTag
{
private:
	PolygonTag();
	~PolygonTag();

public:
	/// @name Get Data
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets a pointer to the read-only polygon array.
	/// @return												The read-only polygon array. @theOwnsPointed{tag,polygon array}
	//----------------------------------------------------------------------------------------
	const CPolygon* GetDataAddressR(void) const;

	//----------------------------------------------------------------------------------------
	/// Gets a pointer to the writable polygon array.
	/// @return												The writable polygon array. @theOwnsPointed{tag,polygon array}
	//----------------------------------------------------------------------------------------
	CPolygon* GetDataAddressW(void);

	/// @}
};

//----------------------------------------------------------------------------------------
/// Represents the Selection tag.\n
/// Holds user defined point, polygon and edge selections.
/// @addAllocFreeAutoAllocNote
//----------------------------------------------------------------------------------------
class SelectionTag : public BaseTag
{
private:
	SelectionTag();
	~SelectionTag();

public:
	/// @name Alloc/Free
	/// @{

	//----------------------------------------------------------------------------------------
	/// @allocatesA{selection tag}
	/// @param[in] type								The selection tag type: @enumerateEnum{SelectionTagTypes}
	/// @return												@allocReturn{selection tag}
	//----------------------------------------------------------------------------------------
	static SelectionTag* Alloc(Int32 type);

	//----------------------------------------------------------------------------------------
	/// @destructsAlloc{selection tags}
	/// @param[in,out] bl							@theToDestruct{selection tag}
	//----------------------------------------------------------------------------------------
	static void Free(SelectionTag*& bl);

	/// @}

	/// @name Get Selection
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets the selection.
	/// @return												The selection. @theOwnsPointed{tag,selection}
	//----------------------------------------------------------------------------------------
	BaseSelect* GetBaseSelect(void);

	/// @}
};

//----------------------------------------------------------------------------------------
/// Represents the UVW tag.\n
/// Handles the UVW coordinates for textures. When assigning a UVW tag to an object ensure the texture is set to UVW.
/// @addAllocFreeAutoAllocNote
//----------------------------------------------------------------------------------------
class UVWTag : public VariableTag
{
private:
	UVWTag();
	~UVWTag();

public:
	/// @name Alloc/Free
	/// @{

	//----------------------------------------------------------------------------------------
	/// @allocatesA{UVW tag}
	/// @param[in] count							The number of UVW element data.
	/// @return												@allocReturn{UVW tag}
	//----------------------------------------------------------------------------------------
	static UVWTag* Alloc(Int32 count);

	//----------------------------------------------------------------------------------------
	/// @destructsAlloc{UVW tags}
	/// @param[in,out] bl							@theToDestruct{UVW tag}
	//----------------------------------------------------------------------------------------
	static void Free(UVWTag*& bl);

	/// @}

	/// @name Get/Set/Copy UVW Coordinates/Data
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets the UVW coordinates for a polygon.
	/// @param[in] i									The index of the polygon to get the coordinates for.
	/// @return												The UVW coordinates.
	//----------------------------------------------------------------------------------------
	UVWStruct GetSlow(Int32 i) { UVWStruct us; C4DOS.Tg->UvGet(this, i, &us); return us; }

	//----------------------------------------------------------------------------------------
	/// Sets the UVW coordinates for a polygon.
	/// @param[in] i									The index of the polygon to set the coordinates for.
	/// @param[in] s									The UVW coordinates for each point of the polygon.
	//----------------------------------------------------------------------------------------
	void SetSlow(Int32 i, const UVWStruct& s) { C4DOS.Tg->UvSet(this, i, (UVWStruct*) &s); }

	//----------------------------------------------------------------------------------------
	/// Copies a UVW coordinate.
	/// @param[in] dst								The destination polygon index in the UVWTag.
	/// @param[in] srctag							The UVW tag for the source polygon. @callerOwnsPointed{tag}
	/// @param[in] src								The source polygon index in the source UVW tag @formatParam{srctag}.
	//----------------------------------------------------------------------------------------
	void CpySlow(Int32 dst, UVWTag* srctag, Int32 src) { C4DOS.Tg->UvCpy(this, dst, srctag, src); }

	//----------------------------------------------------------------------------------------
	/// Gets a handle to the read-only UVW data.
	/// @return												The read-only UVW data. @theOwnsPointed{tag,UVW data}
	//----------------------------------------------------------------------------------------
	ConstUVWHandle GetDataAddressR(void) const;

	//----------------------------------------------------------------------------------------
	/// Gets a handle to the writable UVW data.
	/// @return												The writable UVW data. @theOwnsPointed{tag,UVW data}
	//----------------------------------------------------------------------------------------
	UVWHandle GetDataAddressW(void);

	/// @}

	/// @name Get/Set/Copy UVWHandle
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets the UVW coordinates for a polygon.
	/// @b Example:
	/// @code
	/// UVWStruct res;
	/// Int32 dataCount = uvwTag->GetDataCount();
	/// ConstUVWHandle data = uvwTag->GetDataAddressR();
	/// for (Int32 i=0; i<dataCount; i++)
	/// {
	/// 	UVWTag::Get(data, i, res);
	/// 	// Do something with 'res'
	/// }
	/// @endcode
	/// @param[in] dataptr						The handle to the UVW data.
	/// @param[in] i									The index of the polygon to get the coordinates for.
	/// @param[out] res								Assigned the UVW coordinates for the polygon.
	//----------------------------------------------------------------------------------------
	static void Get(ConstUVWHandle dataptr, Int32 i, UVWStruct& res) { C4DOS.Tg->UvGet2(dataptr, i, &res); }

	//----------------------------------------------------------------------------------------
	/// Sets the UVW coordinates for a polygon.
	/// @param[in] dataptr						The handle to the UVW data.
	/// @param[in] i									The index of the polygon to set the coordinates for.
	/// @param[in] s									The UVW coordinates for the polygon.
	//----------------------------------------------------------------------------------------
	static void Set(UVWHandle dataptr, Int32 i, const UVWStruct& s) { C4DOS.Tg->UvSet2(dataptr, i, s); }

	//----------------------------------------------------------------------------------------
	/// Copies UVW coordinates.
	/// @param[in] destptr						The handle to the destination UVW data.
	/// @param[in] dst								The destination polygon index in the destination UVW data @formatParam{destptr}.
	/// @param[in] srcptr							The handle to the source UVW data.
	/// @param[in] src								The source polygon index in the source UVW data @formatParam{srcptr}.
	//----------------------------------------------------------------------------------------
	static void Copy(UVWHandle destptr, Int32 dst, ConstUVWHandle srcptr, Int32 src) { C4DOS.Tg->UvCpy2(srcptr, src, destptr, dst); }

	/// @}
};

//----------------------------------------------------------------------------------------
/// Represents a Point Normal tag.
//----------------------------------------------------------------------------------------
class NormalTag : public VariableTag
{
private:
	NormalTag();
	~NormalTag();

public:
	/// @name Alloc/Free
	/// @{

	//----------------------------------------------------------------------------------------
	/// @allocatesA{normal tag}
	/// @param[in] count							The number of point normal data.
	/// @return												@allocReturn{normal tag}
	//----------------------------------------------------------------------------------------
	static NormalTag* Alloc(Int32 count);

	//----------------------------------------------------------------------------------------
	/// @destructsAlloc{normal tags}
	/// @param[in,out] bl							@theToDestruct{normal tag}
	//----------------------------------------------------------------------------------------
	static void Free(NormalTag*& bl);

	/// @}

	/// @name Get Data
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets a handle to the read-only point normal data.
	/// @return												The read-only point normal data. @theOwnsPointed{tag,data}
	//----------------------------------------------------------------------------------------
	ConstNormalHandle GetDataAddressR(void) const;

	//----------------------------------------------------------------------------------------
	/// Gets a handle to the writable point normal data.
	/// @return												The writable point normal data. @theOwnsPointed{tag,data}
	//----------------------------------------------------------------------------------------
	NormalHandle GetDataAddressW(void);

	/// @}

	/// @name Get/Set/Copy NormalHandle
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets the point normals for a polygon.
	/// @b Example:
	/// @code
	/// NormalStruct res;
	/// Int32 dataCount = normalTag->GetDataCount();
	/// ConstNormalHandle data = normalTag->GetDataAddressR();
	/// for (Int32 i=0; i<dataCount; i++)
	/// {
	/// 	NormalTag::Get(data, i, res);
	/// 	// Do something with 'res'
	/// }
	/// @endcode
	/// @param[in] dataptr						The handle to the point normal data.
	/// @param[in] i									The index of the polygon to get the point normals for.
	/// @param[out] res								Assigned the point normals.
	//----------------------------------------------------------------------------------------
	static void Get(ConstNormalHandle dataptr, Int32 i, NormalStruct& res) { C4DOS.Tg->NrmGet(dataptr, i, &res); }

	//----------------------------------------------------------------------------------------
	/// Sets the point normals for a polygon.
	/// @param[in] dataptr						The handle to the point normal data.
	/// @param[in] i									The index of the polygon to set the point normals for.
	/// @param[in] s									The point normals to set.
	//----------------------------------------------------------------------------------------
	static void Set(NormalHandle dataptr, Int32 i, const NormalStruct& s) { C4DOS.Tg->NrmSet(dataptr, i, s); }

	//----------------------------------------------------------------------------------------
	/// Copies point normals.
	/// @param[in] destptr						The handle to the destination point normal data.
	/// @param[in] dst								The destination polygon index in the destination data @formatParam{destptr}.
	/// @param[in] srcptr							The handle to the source point normal data.
	/// @param[in] src								The source polygon index in the source data @formatParam{srcptr}.
	//----------------------------------------------------------------------------------------
	static void Copy(NormalHandle destptr, Int32 dst, ConstNormalHandle srcptr, Int32 src) { C4DOS.Tg->NrmCpy(srcptr, src, destptr, dst); }

	/// @}
};

//----------------------------------------------------------------------------------------
/// Represents the Texture Tag.\n
/// Holds the texture information associated with an object.
/// @addAllocFreeAutoAllocNote
//----------------------------------------------------------------------------------------
class TextureTag : public BaseTag
{
private:
	TextureTag();
	~TextureTag();

public:
	/// @name Alloc/Free
	/// @{

	//----------------------------------------------------------------------------------------
	/// @allocatesA{texture tag}
	/// @return												@allocReturn{texture tag}
	//----------------------------------------------------------------------------------------
	static TextureTag* Alloc();

	//----------------------------------------------------------------------------------------
	/// @destructsAlloc{texture tags}
	/// @param[in,out] bl							@theToDestruct{texture tag}
	//----------------------------------------------------------------------------------------
	static void Free(TextureTag*& bl);

	/// @}

	/// @name Get/Set Pos/Scale/Rot/Ml
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets the position of the texture project.
	/// @return												The texture XYZ position.
	//----------------------------------------------------------------------------------------
	Vector GetPos(void);

	//----------------------------------------------------------------------------------------
	/// Gets the scale of the texture projection.
	/// @return												The scale of the texture.
	//----------------------------------------------------------------------------------------
	Vector GetScale(void);

	//----------------------------------------------------------------------------------------
	/// Gets the HPB rotation of the texture projection.
	/// @return												The HPB rotation of the texture.
	//----------------------------------------------------------------------------------------
	Vector GetRot(void);

	//----------------------------------------------------------------------------------------
	/// Gets the texture projection's coordinate system as a matrix.
	/// @return												The texture projection's coordinate system.
	//----------------------------------------------------------------------------------------
	Matrix GetMl(void);

	//----------------------------------------------------------------------------------------
	/// Sets the position of the texture projection.
	/// @param[in] v									The position of the texture.
	//----------------------------------------------------------------------------------------
	void SetPos(const Vector& v);

	//----------------------------------------------------------------------------------------
	/// Sets the scale of the texture projection.
	/// @param[in] v									The scale of the texture.
	//----------------------------------------------------------------------------------------
	void SetScale(const Vector& v);

	//----------------------------------------------------------------------------------------
	/// Sets the HPB rotation of the texture projection.
	/// @param[in] v									The HPB rotation of the texture.
	//----------------------------------------------------------------------------------------
	void SetRot(const Vector& v);

	//----------------------------------------------------------------------------------------
	/// Sets the texture projection's coordinate system matrix.
	/// @param[in] m									The texture projection's coordinate system.
	//----------------------------------------------------------------------------------------
	void SetMl(const Matrix& m);

	/// @}

	/// @name Get/Set Material
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets the material associated with the tag.
	/// @param[in] ignoredoc					@trueOtherwiseFalse{to ignore the tag's document}
	/// @return												The material for the tag. @cinemaOwnsPointed{material}
	//----------------------------------------------------------------------------------------
	BaseMaterial* GetMaterial(Bool ignoredoc = false);

	//----------------------------------------------------------------------------------------
	/// Sets the material associated with the tag.
	/// @param[in] mat								The material for the tag. @callerOwnsPointed{material}
	//----------------------------------------------------------------------------------------
	void SetMaterial(BaseMaterial* mat);

	/// @}
};

//----------------------------------------------------------------------------------------
/// Represents the Stick Texture Tag.\n
/// Stores points for the stick to texture.\n
/// Contains an array that stores a number of point vectors. These represent the stored state of the object.\n
/// When no data is stored or when the data has been invalidated by a point count change, GetDataCount() returns @em 0.
/// @addAllocFreeAutoAllocNote
//----------------------------------------------------------------------------------------
class StickTextureTag : public VariableTag
{
private:
	StickTextureTag();
	~StickTextureTag();

public:
	/// @name Alloc/Free
	/// @{

	//----------------------------------------------------------------------------------------
	/// @allocatesA{stick-texture tag}
	/// @param[in] type								The tag type. Normally @ref Tsticktexture.
	/// @return												@allocReturn{stick-texture tag}
	//----------------------------------------------------------------------------------------
	static StickTextureTag* Alloc(Int32 type);

	//----------------------------------------------------------------------------------------
	/// @destructsAlloc{stick-texture tags}
	/// @param[in,out] bl							@theToDestruct{stick-texture tag}
	//----------------------------------------------------------------------------------------
	static void Free(StickTextureTag*& bl);

	/// @}

	/// @name Get Data
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets a handle to the read-only stick-texture coordinates array.
	/// @return												The read-only stick-texture coordinates array. @theOwnsPointed{tag,array}
	//----------------------------------------------------------------------------------------
	const Vector* GetDataAddressR(void) const;

	//----------------------------------------------------------------------------------------
	/// Gets a handle to the writable stick-texture coordinates array.
	/// @return												The read-only stick-texture coordinates array. @theOwnsPointed{tag,array}
	//----------------------------------------------------------------------------------------
	Vector* GetDataAddressW(void);

	/// @}

	/// @name Record
	/// @{

	//----------------------------------------------------------------------------------------
	/// Records the state of the object in the same way as the user clicking Record in the Stick Texture Tag within @C4D.
	/// @param[in] op									The object to record. @callerOwnsPointed{object}
	/// @param[in] always							If @formatConstant{false} then it will only be recorded if the point count has changed since the last time Record was called. @formatConstant{true} forces it to record always.
	/// @return												@trueIfOtherwiseFalse{the stick-texture state was recorded successfully}
	//----------------------------------------------------------------------------------------
	Bool Record(BaseObject* op, Bool always);

	/// @}
};

//----------------------------------------------------------------------------------------
/// VertexColorTag is a Variable Tag used to store colors (RGBA) into the mesh structure. It can store data in 2 ways: per polygon vertex and per mesh vertex.
///
/// - Per polygon vertex mode is very similar to how UVWTag or NormalTag store data. Just create it using @ref Alloc() with @formatParam{count}==PolygonObject::GetPolygonCount().
/// - Per mesh vertex stores a single color value for mesh vertex and can be used even on objects without any polygon. Create it using Alloc() with @formatParam{count}==PointObject::GetPointCount().
///
/// Using per polygon vertex mode the tag provides all methods to set/get color per polygons or per vertex(average). It also provides some convenience functions to get/set just color or just alpha value in both modes.
///
/// @addAllocFreeAutoAllocNote
/// @since R18
//----------------------------------------------------------------------------------------
class VertexColorTag : public VariableTag
{
private:
	VertexColorTag();
	~VertexColorTag();

public:

	//----------------------------------------------------------------------------------------
	/// Gets the read-only data handle. It automatically recognizes if the tag is per vertex or per polygon vertex.
	/// @return												The handle to the read-only VertexColor data. @theOwnsPointed{tag,data}
	//----------------------------------------------------------------------------------------
	ConstVertexColorHandle GetDataAddressR(void) const;

	//----------------------------------------------------------------------------------------
	/// Gets the writable data handle. It automatically recognizes if the tag is per vertex or per polygon vertex.
	/// @return												The handle to the writable VertexColor data. @theOwnsPointed{tag,data}
	//----------------------------------------------------------------------------------------
	VertexColorHandle	GetDataAddressW(void);

	//----------------------------------------------------------------------------------------
	/// Checks if the data is stored per vertex or per polygon vertex.
	/// @return												@trueIfOtherwiseFalse{colors are stored per vertex}
	//----------------------------------------------------------------------------------------
	Bool IsPerPointColor();

	//----------------------------------------------------------------------------------------
	/// Sets wether the data is stored per vertex or per polygon vertex.
	/// @note The item count is automatically updated and the data converted if possible.
	/// @warning All handles are invalidated after this call.
	/// @param[in] perPointColor			If @formatConstant{true} the data will be stored per vertex otherwise per polygon vertex.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool SetPerPointMode(Bool perPointColor);

	//----------------------------------------------------------------------------------------
	/// Retrieves the Vertex Colors for the polygon @formatParam{i} in per polygon vertex mode.\n
	/// Example:
	/// @code
	/// ConstVertexColorHandle dataptr = ((VertexColorTag*)tag)->GetDataAddressR()
	/// VertexColorStruct vcs;
	/// for (Int32 i = 0; i < faceCount; ++i)
	/// {
	/// 	VertexColorTag::Get(dataptr, faces[i], vcs);
	/// 	// Do something with vcs (you can just read values)
	///	}
	/// @endcode
	/// @param[in] dataptr						The data handle.
	/// @param[in] i									The polygon index.
	/// @param[out] res								The retrieved Vertex Color data.
	//----------------------------------------------------------------------------------------
	static void Get(ConstVertexColorHandle dataptr, Int32 i, VertexColorStruct& res) { C4DOS.Tg->VcolGet(dataptr, i, &res); }

	//----------------------------------------------------------------------------------------
	/// Sets the Vertex Colors Unclamped for the polygon @formatParam{i} in per polygon vertex mode.\n
	/// Example:
	/// @code
	/// VertexColorHandle dataptr = ((VertexColorTag*)tag)->GetDataAddressW()
	/// VertexColorStruct vcs;
	/// for (Int32 i = 0; i < faceCount; ++i)
	/// {
	/// 	VertexColorTag::Get(dataptr, faces[i], vcs);
	/// 	// Do something with vcs (e.g. write values)
	/// 	for (Int32 a = 0; a < 4; ++a)
	/// 		vcs[a] = Vecor4d32(1, 0, 0, 0.5);
	/// 	// Do not forget to set values again
	/// 	VertexColorTag::Set(dataptr, faces[i], vcs);
	///	}
	/// @endcode
	/// @param[in] dataptr						The data handle.
	/// @param[in] i									The polygon index.
	/// @param[in] s									The Vertex Color data to be set to the polygon.
	//----------------------------------------------------------------------------------------
	static void Set(VertexColorHandle dataptr, Int32 i, const VertexColorStruct& s) { C4DOS.Tg->VcolSet(dataptr, i, s); }

	//----------------------------------------------------------------------------------------
	/// Retrieves the Vertex Color for the vertex @formatParam{pIndex} traversing all polygons attached to it.
	/// @note If different values are found the average value will be returned.
	/// @param[in] dataptr						The data handle.
	/// @param[in] nb									A Neighbor helper class. Can be initialized with a polygon selection to limit the function to a specific object part.
	/// @param[in] vadr								The object CPolygon array. Pass @formatConstant{nullptr} if in per vertex mode.
	/// @param[in] pIndex							The vertex index.
	/// @return												The RGBA color for the passed vertex or the average color if multiple values were found.
	//----------------------------------------------------------------------------------------
	static maxon::ColorA32 Get(ConstVertexColorHandle dataptr, Neighbor* nb, const CPolygon* vadr, Int32 pIndex);

	//----------------------------------------------------------------------------------------
	/// Sets the Vertex Color for the vertex @formatParam{pIndex} traversing all polygons attached to it.
	/// @param[in] dataptr						The data handle.
	/// @param[in] nb									A Neighbor helper class. Can be initialized with a polygon selection to limit the function to a specific object part. Pass @formatConstant{nullptr} if in per vertex mode.
	/// @param[in] vadr								The object CPolygon array. Pass @formatConstant{nullptr} if in per vertex mode.
	/// @param[in] pIndex							The vertex index.
	/// @param[in] color							The new RGBA value to be assigned to the vertex.
	//----------------------------------------------------------------------------------------
	static void Set(VertexColorHandle dataptr, Neighbor* nb, const CPolygon* vadr, Int32 pIndex, const maxon::ColorA32& color);

	//----------------------------------------------------------------------------------------
	/// Retrieves the Vertex Color for the vertex @formatParam{pIndex}.
	/// @note If in per polygon vertex mode it traverses all polygons attached to it.
	/// 			If different values are found in per polygon vertex mode then the average value will be returned.
	/// @param[in] dataptr						The data handle.
	/// @param[in] nb									A Neighbor helper class. Can be initialized with a polygon selection to limit the function to a specific object part. Pass @formatConstant{nullptr} if in per vertex mode.
	/// @param[in] vadr								The object CPolygon array. Pass @formatConstant{nullptr} if in per vertex mode.
	/// @param[in] pIndex							The vertex index.
	/// @return												The RGB color for the passed vertex or the average color if multiple values were found.
	//----------------------------------------------------------------------------------------
	static maxon::Color32 GetColor(ConstVertexColorHandle dataptr, Neighbor* nb, const CPolygon* vadr, Int32 pIndex);

	//----------------------------------------------------------------------------------------
	/// Sets the Vertex Color for the vertex @formatParam{pIndex}.
	/// @note If in per polygon vertex mode it traverses all polygons attached to it.
	/// @param[in] dataptr						The data handle.
	/// @param[in] nb									A Neighbor helper class. Can be initialized with a polygon selection to limit the function to a specific object part. Pass @formatConstant{nullptr} if in per vertex mode.
	/// @param[in] vadr								The object CPolygon array Pass @formatConstant{nullptr} if in per vertex mode.
	/// @param[in] pIndex							The vertex index.
	/// @param[in] color							The new RGB value to be assigned to the Vertex Color.
	//----------------------------------------------------------------------------------------
	static void SetColor(VertexColorHandle dataptr, Neighbor* nb, const CPolygon* vadr, Int32 pIndex, const maxon::Color32& color);

	//----------------------------------------------------------------------------------------
	/// Retrieves the Vertex Color alpha value for the vertex @formatParam{pIndex}.
	/// @note | If in per polygon vertex mode it traverses all polygons attached to it.
	/// 			| If different values are found in per polygon vertex mode then the average value will be returned.
	/// @param[in] dataptr						The data handle.
	/// @param[in] nb									A Neighbor helper class. Can be initialized with a polygon selection to limit the function to a specific object part. Pass @formatConstant{nullptr} if in per vertex mode.
	/// @param[in] vadr								The object CPolygon array Pass @formatConstant{nullptr} if in per vertex mode.
	/// @param[in] pIndex							The vertex index.
	/// @return												The alpha value for the passed vertex or the average alpha value if multiple values were found.
	//----------------------------------------------------------------------------------------
	static Float32 GetAlpha(ConstVertexColorHandle dataptr, Neighbor* nb, const CPolygon* vadr, Int32 pIndex);

	//----------------------------------------------------------------------------------------
	/// Sets the Vertex Color alpha value for the vertex @formatParam{pIndex}.
	/// @note If in per polygon vertex mode it traverses all polygons attached to it.
	/// @param[in] dataptr						The data handle.
	/// @param[in] nb									A Neighbor helper class. Can be initialized with a polygon selection to limit the function to a specific object part. Pass @formatConstant{nullptr} if in per vertex mode.
	/// @param[in] vadr								The object CPolygon array Pass @formatConstant{nullptr} if in per vertex mode.
	/// @param[in] pIndex							The vertex index.
	/// @param[in] value							The new alpha value to be assigned to the vertex.
	//----------------------------------------------------------------------------------------
	static void SetAlpha(VertexColorHandle dataptr, Neighbor* nb, const CPolygon* vadr, Int32 pIndex, Float32 value);

	//----------------------------------------------------------------------------------------
	/// @allocatesA{VertexColorTag instance}
	/// @param[in] count							The element count in the tag. Must be equal to the object polygon count if in per polygon vertex storage, otherwise must be equal to the object point count.
	/// @return												@allocReturn{VertexColorTag instance}
	//----------------------------------------------------------------------------------------
	static VertexColorTag* Alloc(Int32 count);

	//----------------------------------------------------------------------------------------
	/// @destructsAlloc{vertex color tags}
	/// @param[in] bl									@theToDestruct{VertexColorTag instance}
	//----------------------------------------------------------------------------------------
	static void Free(VertexColorTag*& bl);
};

//----------------------------------------------------------------------------------------
/// Represents the XPresso tag.
/// @addAllocFreeAutoAllocNote
//----------------------------------------------------------------------------------------
class XPressoTag : public BaseTag
{
private:
	XPressoTag();
	~XPressoTag();

public:
	/// @name Alloc/Free
	/// @{

	//----------------------------------------------------------------------------------------
	/// @allocatesA{XPresso tag}
	/// @return												@allocReturn{XPresso tag}
	//----------------------------------------------------------------------------------------
	static XPressoTag* Alloc();

	//----------------------------------------------------------------------------------------
	/// @destructsAlloc{XPresso tags}
	/// @param[in,out] bl							@theToDestruct{XPresso tag}
	//----------------------------------------------------------------------------------------
	static void Free(XPressoTag*& bl);

	/// @}

	/// @name Node Master
	/// @{

	//----------------------------------------------------------------------------------------
	/// Retrieves the node master.
	/// @return												The node master. @theOwnsPointed{XPresso tag,node master}
	//----------------------------------------------------------------------------------------
	GvNodeMaster* GetNodeMaster(void);

	/// @}
};


//----------------------------------------------------------------------------------------
/// Holds the weights of the edges for a polygon.\n
/// @note For triangles @ref a, @ref b and @ref d contain valid data.
//----------------------------------------------------------------------------------------
struct PolyWeight
{
	Float32 a,			///< The weight of the first edge.
					b,			///< The weight of the second edge.
					c,			///< The weight of the third edge.
					d;			///< The weight of the fourth edge.
};

//----------------------------------------------------------------------------------------
/// Holds HyperNURBS weight tag data.
//----------------------------------------------------------------------------------------
struct HNData
{
	//----------------------------------------------------------------------------------------
	/// Default constructor.
	//----------------------------------------------------------------------------------------
	HNData() { points = polys = nullptr; pointweight = nullptr; polyweight = nullptr; changed = nullptr; }

	Int32* points,								///< Points to the point count.
				 *polys;								///< Points to the polygon count.
	Float32** pointweight;				///< Points to an array of *@ref points weights, one for each point.
	PolyWeight** polyweight;			///< Points to an array of *@ref polys polygon weights, one for each polygon.
	Bool* changed;								///< Points to a flag to set if any of the values are changed.
};

//----------------------------------------------------------------------------------------
/// Determines the current subdivision for SDS objects.\n
/// Fills @ref op and @ref lod and send a @ref MSG_RETRIEVEPRIVATEDATA message to the SDS object.\n
/// The flags must be @em 0 and data must point to a HNSubdiv struct.\n
/// If the message succeeds, @ref subdiv is filled with the current subdivision of @ref op.
//----------------------------------------------------------------------------------------
struct HNSubdiv
{
	PolygonObject* op;			///< The polygon object that is to be subdivided.
	Float lod;							///< The level of detail.
	Int32 subdiv;						///< The subdivision level of @ref op.
};

//----------------------------------------------------------------------------------------
/// Represent the HyperNURBS weight tag.
/// @addAllocFreeAutoAllocNote
//----------------------------------------------------------------------------------------
class HNWeightTag : public BaseTag
{
private:
	HNWeightTag();
	~HNWeightTag();

public:
	/// @name Alloc/Free
	/// @{

	//----------------------------------------------------------------------------------------
	/// @allocatesA{HyperNURBS weight tag}
	/// @return												@allocReturn{HyperNURBS weight tag}
	//----------------------------------------------------------------------------------------
	static HNWeightTag* Alloc();

	//----------------------------------------------------------------------------------------
	/// @destructsAlloc{HyperNURBS weight tags}
	/// @param[in,out] bl							@theToDestruct{HyperNURBS weight tag}
	//----------------------------------------------------------------------------------------
	static void Free(HNWeightTag*& bl);

	/// @}

	/// @name Get Data
	/// @{

	//----------------------------------------------------------------------------------------
	/// Fills the passed struct with the weight tag data.
	/// @note Remember to set HNData::changed if anything has changed.
	/// @return												@trueIfOtherwiseFalse{the weight tag data was retrieved}
	//----------------------------------------------------------------------------------------
	Bool GetTagData(HNData* data);

	/// @}
};

//----------------------------------------------------------------------------------------
/// Represents the SoftSelection tag.
/// @since R19
//----------------------------------------------------------------------------------------
class SoftSelectionTag : public VariableTag
{
private:
	SoftSelectionTag();
	~SoftSelectionTag();

public:

	/// @name Get Data
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets a pointer to the read-only soft selection array.
	/// @return												The read-only soft selection array. @theOwnsPointed{tag,soft selection array}
	//----------------------------------------------------------------------------------------
	const Float32* GetDataAddressR(void) const;

	//----------------------------------------------------------------------------------------
	/// Gets a pointer to the writable soft selection array.
	/// @return												The writable soft selection array. @theOwnsPointed{tag,soft selection array}
	//----------------------------------------------------------------------------------------
	Float32* GetDataAddressW(void);

	/// @}
};

#define BAKEPARTICLETAG_FROM		1001	/// ::Int32
#define BAKEPARTICLETAG_TO			1002	/// ::Int32
#define BAKEPARTICLETAG_STEP		1003	/// ::Int32
#define BAKEPARTICLETAG_IGNORE	1004	/// ::Bool

#endif // C4D_BASETAG_H__
