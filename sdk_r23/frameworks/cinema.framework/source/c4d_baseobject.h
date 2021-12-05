/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef C4D_BASEOBJECT_H__
#define C4D_BASEOBJECT_H__

#ifdef __API_INTERN__
	#error "Not in the kernel"
#endif

#include "c4d_baselist.h"
#include "c4d_basecontainer.h"
#include "operatingsystem.h"

#ifdef CINEWARE_NAMESPACE_ENABLE
	CINEWARE_NAMESPACE_BEGIN
#endif

class BaseTag;
class BaseDocument;
class BaseContainer;
class LineObject;
class BaseThread;

class BaseSelect;
class EdgeBaseSelect;
class Neighbor;

/// @addtogroup MODE
/// @ingroup group_enumeration
/// @{
#define MODE_ON			0			///< The object is enabled regardless of the state of any parent object.
#define MODE_OFF		1			///< The object is disabled regardless of the state of any parent object.
#define MODE_UNDEF	2			///< The object is enabled by default, but the state of any parent object is used if it is enabled or disabled.
/// @}

//-------------------------------------------------------------------------------------------------
/// Represents a polygon that can be either a triangle or a quadrangle.
//-------------------------------------------------------------------------------------------------
struct CPolygon
{
	Int32 a,	///< Index of the first point in the polygon.
				b,	///< Index of the second point in the polygon.
				c,	///< Index of the third point in the polygon.
				d;	///< Index of the fourth point in the polygon.

public:
	//-------------------------------------------------------------------------------------------------
	/// Constructs a polygon by default.
	//-------------------------------------------------------------------------------------------------
	CPolygon() { }

	//----------------------------------------------------------------------------------------
	/// Constructs a triangle.
	/// @param[in] t_a								Index of the first point in the polygon.
	/// @param[in] t_b								Index of the second point in the polygon.
	/// @param[in] t_c								Index of the third point in the polygon.
	//----------------------------------------------------------------------------------------
	CPolygon(Int32 t_a, Int32 t_b, Int32 t_c) { a = t_a; b = t_b; c = d = t_c; }

	//----------------------------------------------------------------------------------------
	/// Constructs a quadrangle.
	/// @param[in] t_a								Index of the first point in the polygon.
	/// @param[in] t_b								Index of the second point in the polygon.
	/// @param[in] t_c								Index of the third point in the polygon.
	/// @param[in] t_d								Index of the fourth point in the polygon.
	//----------------------------------------------------------------------------------------
	CPolygon(Int32 t_a, Int32 t_b, Int32 t_c, Int32 t_d) { a = t_a; b = t_b; c = t_c; d = t_d; }

	//----------------------------------------------------------------------------------------
	/// Vertex index array operator.\n
	/// Accesses the polygon's vertex indices through their polygon vertex numbers (@em 0 - @em 3) instead of @ref a, @ref b, @ref c, @ref d.
	/// @param[in] index							The vertex index (@em 0 - @em 3) to retrieve in the polygon.
	/// @return												The vertex index.
	//----------------------------------------------------------------------------------------
	Int32& operator[](Int32 index) const { return ((Int32*)this)[index & 3]; }

	//----------------------------------------------------------------------------------------
	/// Checks if the polygon is a triangle.
	/// @return												@trueIfOtherwiseFalse{the polygon is a triangle}
	//----------------------------------------------------------------------------------------
	Bool IsTriangle(void) const { return c == d; }

	//----------------------------------------------------------------------------------------
	/// Checks if one of the polygon vertex indices is equal to index and returns the found polygon vertex number (@em 0 - @em 3, equals @ref a - @ref d).
	/// @param[in] index							The vertex index to check.
	/// @return												The matching polygon vertex number (@em 0 - @em 3, equals @ref a - @ref d). @ref NOTOK is returned if there is no match.
	//----------------------------------------------------------------------------------------
	Int32 Find(Int32 index) const { return (d == index ? 3 : (c == index ? 2 : (b == index ? 1 : (a == index ? 0 : NOTOK)))); }

	//----------------------------------------------------------------------------------------
	/// Checks if the vertex indices @formatParam{index1} and @formatParam{index2} form an edge in the polygon. If so the polygon edge number is returned (@em 0 - @em 3).
	/// @param[in] index1							The vertex index of the first edge point.
	/// @param[in] index2							The vertex index of the second edge point.
	/// @return												The found polygon edge number (@em 0 - @em 3), or @ref NOTOK if there is no match.
	//----------------------------------------------------------------------------------------
	Int32 FindEdge(Int32 index1, Int32 index2) const
	{
		if (d == index1)
			return a == index2 ? 3 : (c == d ? (b == index2 ? 1 : NOTOK) : (c == index2 ? 2 : NOTOK));
		if (c == index1)
			return b == index2 ? 1 : (c == d ? (a == index2 ? 3 : NOTOK) : (d == index2 ? 2 : NOTOK));
		if (b == index1)
			return c == index2 ? 1 : (a == index2 ? 0 : NOTOK);
		if (a == index1)
			return b == index2 ? 0 : (d == index2 ? 3 : NOTOK);
		return NOTOK;
	}

	//----------------------------------------------------------------------------------------
	/// Gets the point indices for an @formatParam{edge} index.
	/// @param[in] edge								The edge index.
	/// @param[out] p1								Assigned the index of the first edge point.
	/// @param[out] p2								Assigned the index of the second edge point.
	//----------------------------------------------------------------------------------------
	void EdgePoints(Int32 edge, Int32& p1, Int32& p2) const
	{
		p1 = ((Int32*)this)[edge & 3];
		p2 = ((Int32*)this)[(edge + 1) & 3];
	}

	//----------------------------------------------------------------------------------------
	/// Gets the point with modulo for the number of points in the polygon.\n
	/// If the polygon is a triangle it goes @ref a, @ref b, @ref c, @ref a, @ref b , c etc thus point @em 3 will be point @ref a again, but with a quad it goes @ref a, @ref b, @ref c, @ref d, @ref a, @ref b, @ref c, @ref d... so point @em 3 will be @ref d.
	/// @param[in] index							The point index.
	/// @return												The point index.
	//----------------------------------------------------------------------------------------
	Int32& GetPoint(Int32 index) const
	{
		if (c == d)
			return ((Int32*)this)[(index + (3 << 24)) % 3];
		return ((Int32*)this)[index & 3];
	}
};


//----------------------------------------------------------------------------------------
/// Represents a tangent with its left and right interpolation parts.
//----------------------------------------------------------------------------------------
struct Tangent
{
	Vector	vl,			///< The left part that defines the tangent.
					vr;			///< The right part that defines the tangent.

	//----------------------------------------------------------------------------------------
	/// Checks if the tangent is broken.
	/// @return												@trueIfOtherwiseFalse{the tangent is broken}
	//----------------------------------------------------------------------------------------
	Bool IsBroken(void) const { return Dot(!vl, !vr) > -1.0 + EPSILON; }
};

//----------------------------------------------------------------------------------------
/// Represents a Spline segment data.
//----------------------------------------------------------------------------------------
struct Segment
{
	Int32	cnt;				///< The number of points in the segment.
	Bool	closed;			///< @trueIfOtherwiseFalse{the segment is closed}
};

//----------------------------------------------------------------------------------------
/// Data structure for object color properties.
//----------------------------------------------------------------------------------------
struct ObjectColorProperties
{
	Int32		usecolor;			///< The color mode. @see ::ID_BASEOBJECT_USECOLOR
	Vector	color;				///< The color.
	Bool		xray;					///< The X-ray mode.
};


//----------------------------------------------------------------------------------------
/// Helper class for virtual objects hierarchy handling.
/// @see ObjectData::GetVirtualObjects()
//----------------------------------------------------------------------------------------
class HierarchyHelp
{
private:
	HierarchyHelp();
	~HierarchyHelp();

public:
	//----------------------------------------------------------------------------------------
	/// Gets the level of detail for the virtual objects.
	/// @return												The level of detail.
	/// @see BaseDocument::GetLOD()
	//----------------------------------------------------------------------------------------
	Float GetLOD(void) { return C4DOS.Bd->HhGetLOD(this); }

	//----------------------------------------------------------------------------------------
	/// Gets the build flags for the virtual objects.
	/// @return												The build flags: @enumerateEnum{BUILDFLAGS}
	//----------------------------------------------------------------------------------------
	BUILDFLAGS GetBuildFlags(void) { return C4DOS.Bd->HhGetBuildFlags(this); }

	//----------------------------------------------------------------------------------------
	/// Gets the world (global) matrix for the virtual objects.
	/// @return												The world (global) transformation matrix.
	//----------------------------------------------------------------------------------------
	const Matrix& GetMg(void) { return C4DOS.Bd->HhGetMg(this); }

	//----------------------------------------------------------------------------------------
	/// Gets the calling thread.
	/// @return												The thread using the hierarchy help, or @formatConstant{nullptr}. @cinemaOwnsPointed{thread}
	//----------------------------------------------------------------------------------------
	BaseThread* GetThread(void) { return C4DOS.Bd->HhGetThread(this); }

	//----------------------------------------------------------------------------------------
	/// Gets the document for the virtual objects.
	/// @return												The document. @cinemaOwnsPointed{document}
	//----------------------------------------------------------------------------------------
	BaseDocument* GetDocument(void) { return C4DOS.Bd->HhGetDocument(this); }
};


//----------------------------------------------------------------------------------------
/// All objects in @C4D are derived from the BaseObject class.\n
/// Contains methods for the object's position, scale and rotation, as well as for accessing the sub-items of the object (e.g. tags and animation tracks).
/// @addAllocFreeAutoAllocNote
//----------------------------------------------------------------------------------------
class BaseObject : public BaseList2D
{
private:
	BaseObject();
	~BaseObject();

public:
	/// @name Alloc/Free
	/// @{

	//----------------------------------------------------------------------------------------
	/// @allocatesA{base object}
	/// @param[in] type								The object type: @enumerateEnum{ObjectTypes}
	/// @return												@allocReturn{base object}
	//----------------------------------------------------------------------------------------
	static BaseObject* Alloc(Int32 type);

	//----------------------------------------------------------------------------------------
	/// @destructsAlloc{base objects}
	/// @param[in,out] bl							@theToDestruct{base object}
	//----------------------------------------------------------------------------------------
	static void Free(BaseObject*& bl);

	/// @}

	/// @name Navigation
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets the next object in the list. Convenience version of GeListNode::GetNext().
	/// @return												The next object, or @formatConstant{nullptr} if there is none. @cinemaOwnsPointed{ object}
	//----------------------------------------------------------------------------------------
	BaseObject* GetNext(void) { return (BaseObject*)AtCall(GetNext) (); }

	//----------------------------------------------------------------------------------------
	/// Gets the previous object in the list. Convenience version of GeListNode::GetPred().
	/// @return												The previous base object, or @formatConstant{nullptr} if there is none. @cinemaOwnsPointed{object}
	//----------------------------------------------------------------------------------------
	BaseObject* GetPred(void) { return (BaseObject*)AtCall(GetPred) (); }

	//----------------------------------------------------------------------------------------
	/// Gets the parent object of the list node. Convenience version of GeListNode::GetUp().
	/// @return												The parent object, or @formatConstant{nullptr} if there is none. @cinemaOwnsPointed{object}
	//----------------------------------------------------------------------------------------
	BaseObject* GetUp(void) { return (BaseObject*)AtCall(GetUp) (); }

	//----------------------------------------------------------------------------------------
	/// Gets the first child object of the list node. Convenience version of GeListNode::GetDown().
	/// @return												The first child object, or @formatConstant{nullptr} if there is none. @cinemaOwnsPointed{object}
	//----------------------------------------------------------------------------------------
	BaseObject* GetDown(void) { return (BaseObject*)AtCall(GetDown) (); }

	//----------------------------------------------------------------------------------------
	/// Gets the last child base object of the list node. Convenience version of GeListNode::GetDownLast().
	/// @return												The last child object, or @formatConstant{nullptr} if there is none. @cinemaOwnsPointed{object}
	//----------------------------------------------------------------------------------------
	BaseObject* GetDownLast(void) { return (BaseObject*)AtCall(GetDownLast) (); }

	/// @}


	/// @name Abs Pos/Scale/Rot
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets the absolute position of the object.\n
	/// These are the absolute local coordinates within the parent object.\n
	/// If the object has no parent then these are world coordinates.
	/// @see The @link page_manual_baseobject BaseObject Manual@endlink
	/// @return												The object's absolute position.
	//----------------------------------------------------------------------------------------
	Vector GetAbsPos() const { return BoCall(GetAbsPos) (); }

	//----------------------------------------------------------------------------------------
	/// Sets the absolute local position of the object within its parent.\n
	/// These are the absolute local coordinates within the parent object.\n
	/// If the object has no parent then these are world coordinates.
	/// @see The @link page_manual_baseobject BaseObject Manual@endlink
	/// @param[in] v									The object's absolute position to set.
	//----------------------------------------------------------------------------------------
	void SetAbsPos(const Vector& v) { BoCall(SetAbsPos) (v); }

	//----------------------------------------------------------------------------------------
	/// Gets the absolute scale of the object.\n
	/// This is relative to the object's parent if it has one.
	/// @see The @link page_manual_baseobject BaseObject Manual@endlink
	/// @return												The object's absolute scale.
	//----------------------------------------------------------------------------------------
	Vector GetAbsScale() const { return BoCall(GetAbsScale) (); }

	//----------------------------------------------------------------------------------------
	/// Sets the absolute scale of the object.\n
	/// This is relative to the object's parent if it has one.
	/// @see The @link page_manual_baseobject BaseObject Manual@endlink
	/// @param[in] v									The object's absolute scale to set.
	//----------------------------------------------------------------------------------------
	void SetAbsScale(const Vector& v) { BoCall(SetAbsScale) (v); }

	//----------------------------------------------------------------------------------------
	/// Gets the absolute HPB rotation of the object.\n
	/// This is relative to the object's parent if it has one.
	/// @see The @link page_manual_baseobject BaseObject Manual@endlink
	/// @return												The object's absolute HPB rotation.
	//----------------------------------------------------------------------------------------
	Vector GetAbsRot() const { return BoCall(GetAbsRot) (); }

	//----------------------------------------------------------------------------------------
	/// Sets the absolute HPB rotation of the object.\n
	/// This is relative to the object's parent if it has one.
	/// @see The @link page_manual_baseobject BaseObject Manual@endlink
	/// @param[in] v									The object's absolute HPB rotation to set.
	//----------------------------------------------------------------------------------------
	void SetAbsRot(const Vector& v) { BoCall(SetAbsRot) (v); }

	/// @}

	/// @name Frozen Pos/Scale/Rot
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets the frozen position of the object.
	/// @see The @link page_manual_baseobject BaseObject Manual@endlink
	/// @return												The object's frozen position.
	//----------------------------------------------------------------------------------------
	Vector GetFrozenPos() const { return BoCall(GetFrozenPos) (); }

	//----------------------------------------------------------------------------------------
	/// Sets the frozen position of the object.
	/// @see The @link page_manual_baseobject BaseObject Manual@endlink
	/// @param[in] v									The object's frozen position to set.
	//----------------------------------------------------------------------------------------
	void SetFrozenPos(const Vector& v) { BoCall(SetFrozenPos) (v); }

	//----------------------------------------------------------------------------------------
	/// Gets the frozen scale of the object.
	/// @see The @link page_manual_baseobject BaseObject Manual@endlink
	/// @return												The object's frozen scale.
	//----------------------------------------------------------------------------------------
	Vector GetFrozenScale() const { return BoCall(GetFrozenScale) (); }

	//----------------------------------------------------------------------------------------
	/// Sets the frozen scale of the object.
	/// @see The @link page_manual_baseobject BaseObject Manual@endlink
	/// @param[in] v									The object's frozen scale to set.
	//----------------------------------------------------------------------------------------
	void SetFrozenScale(const Vector& v) { BoCall(SetFrozenScale) (v); }

	//----------------------------------------------------------------------------------------
	/// Gets the frozen HPB rotation of the object.
	/// @see The @link page_manual_baseobject BaseObject Manual@endlink
	/// @return												The object's frozen HPB rotation.
	//----------------------------------------------------------------------------------------
	Vector GetFrozenRot() const { return BoCall(GetFrozenRot) (); }

	//----------------------------------------------------------------------------------------
	/// Sets the frozen HPB rotation of the object.
	/// @see The @link page_manual_baseobject BaseObject Manual@endlink
	/// @param[in] v									The object's frozen HPB rotation to set.
	//----------------------------------------------------------------------------------------
	void SetFrozenRot(const Vector& v) { BoCall(SetFrozenRot) (v); }

	/// @}

	/// @name Rel Pos/Scale/Rot
	/// @{

	//----------------------------------------------------------------------------------------
	/// Get the relative position of the object.
	/// @see The @link page_manual_baseobject BaseObject Manual@endlink
	/// @return												The object's relative position.
	//----------------------------------------------------------------------------------------
	Vector GetRelPos() const { return BoCall(GetRelPos) (); }

	//----------------------------------------------------------------------------------------
	/// Sets the relative position of the object.
	/// @see The @link page_manual_baseobject BaseObject Manual@endlink
	/// @param[in] v									The object's relative position to set.
	//----------------------------------------------------------------------------------------
	void SetRelPos(const Vector& v) { BoCall(SetRelPos) (v); }

	//----------------------------------------------------------------------------------------
	/// Gets the relative scale of the object.
	/// @see The @link page_manual_baseobject BaseObject Manual@endlink
	/// @return												The object's relative scale.
	//----------------------------------------------------------------------------------------
	Vector GetRelScale() const { return BoCall(GetRelScale) (); }

	//----------------------------------------------------------------------------------------
	/// Sets the relative scale of the object.
	/// @see The @link page_manual_baseobject BaseObject Manual@endlink
	/// @param[in] v									The object's relative scale to set.
	//----------------------------------------------------------------------------------------
	void SetRelScale(const Vector& v) { BoCall(SetRelScale) (v); }

	//----------------------------------------------------------------------------------------
	/// Gets the relative HPB rotation of the object.
	/// @see The @link page_manual_baseobject BaseObject Manual@endlink
	/// @return												The object's relative scale.
	//----------------------------------------------------------------------------------------
	Vector GetRelRot() const { return BoCall(GetRelRot) (); }

	//----------------------------------------------------------------------------------------
	/// Sets the relative HPB rotation of the object.
	/// @see The @link page_manual_baseobject BaseObject Manual@endlink
	/// @param[in] v									The object's relative rotation to set.
	//----------------------------------------------------------------------------------------
	void SetRelRot(const Vector& v) { BoCall(SetRelRot) (v); }

	/// @}

	/// @name Ml/Mg Matrix
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets the local matrix representing the object's position, scale and rotation.
	/// @return												The object's local matrix.
	//----------------------------------------------------------------------------------------
	const Matrix& GetMl(void) const { return BoCall(GetMl) (); }

	//----------------------------------------------------------------------------------------
	/// Sets the local matrix representing the object's position, scale and rotation.
	/// @param[in] m									The object's local matrix to set.
	//----------------------------------------------------------------------------------------
	void SetMl(const Matrix& m) { BoCall(SetMl) (m); }

	//----------------------------------------------------------------------------------------
	/// Gets the frozen and normalized matrix of the object.
	/// @see The @link page_manual_baseobject BaseObject Manual@endlink
	/// @return												The object's frozen and normalized matrix.
	//----------------------------------------------------------------------------------------
	Matrix GetFrozenMln() const { return BoCall(GetFrozenMln) (); }

	//----------------------------------------------------------------------------------------
	/// Gets the relative and normalized matrix of the object.
	/// @see The @link page_manual_baseobject BaseObject Manual@endlink
	/// @return												The object's relative and normalized matrix.
	//----------------------------------------------------------------------------------------
	Matrix GetRelMln() const { return BoCall(GetRelMln) (); }

	//----------------------------------------------------------------------------------------
	/// Gets the relative matrix of the object.
	/// @see The @link page_manual_baseobject BaseObject Manual@endlink
	/// @return												The object's relative matrix.
	//----------------------------------------------------------------------------------------
	Matrix GetRelMl() const { return BoCall(GetRelMl) (); }

	//----------------------------------------------------------------------------------------
	/// Sets the relative matrix of the object.
	/// @see The @link page_manual_baseobject BaseObject Manual@endlink
	/// @param[in] m									The object's relative matrix to set.
	//----------------------------------------------------------------------------------------
	void SetRelMl(const Matrix& m) { BoCall(SetRelMl) (m); }

	//----------------------------------------------------------------------------------------
	/// Gets the world (global) matrix representing the object's position, scale and rotation.
	/// @warning Only valid if the object is attached to a document. Virtual objects in caches and deform caches are not attached to a document, so this cannot be used for those objects.
	/// @return												The object's world matrix.
	//----------------------------------------------------------------------------------------
	Matrix GetMg() const { return BoCall(GetMg) (); }

	//----------------------------------------------------------------------------------------
	/// Sets the world (global) matrix representing the object's position, scale and rotation.
	/// @param[in] m									The object's world matrix to set.
	//----------------------------------------------------------------------------------------
	void SetMg(const Matrix& m) { BoCall(SetMg) (m); }

	//----------------------------------------------------------------------------------------
	/// Gets the local normalized matrix representing the object's position, scale and rotation.
	/// @return												The object's normalized local matrix.
	//----------------------------------------------------------------------------------------
	Matrix GetMln() const { return BoCall(GetMln) (); }

	//----------------------------------------------------------------------------------------
	/// Gets the world (global) normalized matrix representing the object's position, scale and rotation.
	/// @return												The object's normalized world matrix.
	//----------------------------------------------------------------------------------------
	Matrix GetMgn() const { return BoCall(GetMgn) (); }

	//----------------------------------------------------------------------------------------
	/// Gets the world (global) matrix of the parent object representing the parent's position, scale and rotation.\n
	/// If the object has no parent object then the method returns a unit matrix.
	/// @return												The parent object's world matrix.
	//----------------------------------------------------------------------------------------
	Matrix GetUpMg() const { return BoCall(GetUpMg) (); }

	//----------------------------------------------------------------------------------------
	/// Copies the object's matrix to another object.
	/// @param[in,out] dst						The destination object to copy the matrix to.
	//----------------------------------------------------------------------------------------
	void CopyMatrixTo(BaseObject* dst) { C4DOS.Bo->CopyMatrixTo(this, dst); }

	/// @}

	/// @name Bounding Box
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets the object's bounding box center in local space.
	/// @return												The bounding box center.
	//----------------------------------------------------------------------------------------
	Vector GetMp(void) { return C4DOS.Bo->GetMp(this); }

	//----------------------------------------------------------------------------------------
	/// Gets the object's bounding box radius (x/y/z).
	/// @note Works for all objects and is faster than manually finding the bounds of even polygon objects, because the radius is internally cached.
	/// @return												The object's bounding box radius.
	//----------------------------------------------------------------------------------------
	Vector GetRad(void) { return C4DOS.Bo->GetRad(this); }

	/// @}

	/// @name Editor/Render/Deform Mode
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets the mode of the editor dot for the object.
	/// @return												The editor mode: @enumerateEnum{MODE}
	//----------------------------------------------------------------------------------------
	Int32 GetEditorMode(void) const;

	//----------------------------------------------------------------------------------------
	/// Gets the mode of the editor dot for the object.
	/// @return												The editor mode: @enumerateEnum{MODE}
	//----------------------------------------------------------------------------------------
	Int32 GetEditorModeH(void) const;

	//----------------------------------------------------------------------------------------
	/// Sets the mode for of editor dot for the object.
	/// @param[in] mode								The editor mode to set: @enumerateEnum{MODE}
	//----------------------------------------------------------------------------------------
	void SetEditorMode(Int32 mode);

	//----------------------------------------------------------------------------------------
	/// Gets the mode of the render dot for the object.
	/// @return												The render mode: @enumerateEnum{MODE}
	//----------------------------------------------------------------------------------------
	Int32 GetRenderMode(void) const;

	//----------------------------------------------------------------------------------------
	/// Gets the mode of the render dot for the object.
	/// @return												The render mode: @enumerateEnum{MODE}
	//----------------------------------------------------------------------------------------
	Int32 GetRenderModeH(void) const;

	//----------------------------------------------------------------------------------------
	/// Sets the mode of the render dot for the object.
	/// @param[in] mode								The render mode to set: @enumerateEnum{MODE}
	//----------------------------------------------------------------------------------------
	void SetRenderMode(Int32 mode);

	//----------------------------------------------------------------------------------------
	/// Gets the enabled mode of the deformation/generator tick.
	/// @return												@trueIfOtherwiseFalse{the deformer/generator is enabled}
	//----------------------------------------------------------------------------------------
	Bool GetDeformMode(void) const;

	//----------------------------------------------------------------------------------------
	/// Sets the enabled mode of the deformation/generator tick.
	/// @param[in] mode								@trueOtherwiseFalse{to enable the generator/deformer object}
	//----------------------------------------------------------------------------------------
	void SetDeformMode(Bool mode);

	//----------------------------------------------------------------------------------------
	/// Gets the real deform mode (MODE_ON, MODE_OFF, MODE_UNKNOWN).
	/// @return												The real deform mode.
	//----------------------------------------------------------------------------------------
	Int32 GetRealDeformMode(void) const;

	//----------------------------------------------------------------------------------------
	/// Sets the real deform mode (MODE_ON, MODE_OFF, MODE_UNKNOWN).
	/// @param[in] mode								MODE_ON, MODE_OFF or MODE_UNKNOWN.
	//----------------------------------------------------------------------------------------
	void SetRealDeformMode(Int32 mode);

	/// @}

	/// @name Unique IP
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets the IP number for the object.\n
	/// GetUniqueIP() and SetUniqueIP() allow @C4D to identify and track objects between different frames (which is necessary for stuff like object motion blur).
	///
	/// In case of a static generator that is easy: for every frame there is exactly the same structure.\n
	/// For a particle system however that is different: e.g. there could always be 3 objects (particles), but some might be the same, some might be new ones.\n
	/// To allow @C4D to track that stuff an IP-like system is used: each object can carry a unique Int32 number and @C4D creates full paths from it, e.g. <i>5.7.102.43.65.2</i>\n
	/// This is done 100% internally.
	///
	/// Only generator objects that have variable output or generator objects that use GetHierarchyClone() need to program some extra lines.\n
	/// Such objects need to set the bit @ref OBJECT_UNIQUEENUMERATION. Then it needs to assign unique Int32 values to all objects returned (except for the top-level object, which is handled by @C4D).
	///
	/// @b Example:<br>
	/// A generator has 3 objects, but those objects appear and disappear during time. Say that @c obj3 is child of @c obj1; @c obj1 and @c obj2 are children of @c main (which is returned). @c obj2 and @c obj3 might not be present:\n
	/// @code
	/// main
	/// 	obj1
	/// 		[obj3]
	/// 	[obj2]
	/// @endcode
	/// The generator will call:
	/// @code
	/// if (obj1) obj->SetUniqueIP(1);
	/// if (obj2) obj->SetUniqueIP(2);
	/// if (obj3) obj->SetUniqueIP(3);
	/// @endcode
	/// That is all that is needed. @C4D will recognize which object matches another object at a different time.\n
	/// If GetHierarchyClone() is called those objects already have a unique numeration. It is only needed to assign a unique value to the top level:
	/// @code
	/// obj1 = GetHierarchyClone(...);
	/// obj2 = GetHierarchyClone(...);
	/// ...
	/// if (obj1) obj1->SetUniqueIP(1);
	/// if (obj2) obj2->SetUniqueIP(2);
	/// @endcode
	/// @return												The IP number for the object.
	//----------------------------------------------------------------------------------------
	Int32 GetUniqueIP(void);

	//----------------------------------------------------------------------------------------
	/// Sets the IP number for the object.
	/// @see GetUniqueIP()
	/// @param[in] ip									The new IP number.
	//----------------------------------------------------------------------------------------
	void SetUniqueIP(Int32 ip);

	/// @}

	/// @name Tag
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets the first tag associated with the object.
	/// @return												The first tag, or @formatConstant{nullptr} if no tags available. @theOwnsPointed{object,tag}
	//----------------------------------------------------------------------------------------
	BaseTag* GetFirstTag(void);

	//----------------------------------------------------------------------------------------
	/// Gets the last tag associated with the object.
	/// @since R19
	/// @return												The last tag, or @formatConstant{nullptr} if no tags available. @theOwnsPointed{object,tag}
	//----------------------------------------------------------------------------------------
	BaseTag* GetLastTag(void);

	//----------------------------------------------------------------------------------------
	/// Gets a tag of a certain type associated with the object.
	/// @param[in] type								The type of tag to fetch from the object: @enumerateEnum{TagTypes}
	/// @param[in] nr									Optionally specify a starting tag index to begin the search.\n
	/// 															If the requested number is not available then @formatConstant{nullptr} will be returned even if there is a tag of that type with a different index.
	/// @return												The requested tag, or @formatConstant{nullptr} if no tags of the requested type are available. @theOwnsPointed{object,tag}
	//----------------------------------------------------------------------------------------
	BaseTag* GetTag(Int32 type, Int32 nr = 0) { return C4DOS.Bo->GetTag(this, type, nr); }

	//----------------------------------------------------------------------------------------
	/// Gets an array of tags of a certain type associated with the object.
	/// @param[in] type								The type of tags to fetch from the object: @enumerateEnum{TagTypes}
	/// @return												An array of tags with the given type.
	//----------------------------------------------------------------------------------------
	const maxon::BaseArray<BaseTag*>* GetTagsOfType(Int32 type) const { return C4DOS.Bo->GetTagsOfType(this, type); }

	//----------------------------------------------------------------------------------------
	/// Gets an array of tags with certain flags associated with the object.
	/// @param[in] flags							The flags of tags to fetch from the object: @enumerateEnum{TagTypes}
	/// @return												An array of tags with the given type.
	//----------------------------------------------------------------------------------------
	const maxon::BaseArray<BaseTag*>* GetTagsWithFlags(Int32 flags) const { return C4DOS.Bo->GetTagsWithFlags(this, flags); }

	//----------------------------------------------------------------------------------------
	/// Gets a variable tag's readable data of a certain type associated with the object.
	/// @param[in] type								The type of tag to fetch the data for: @enumerateEnum{VariableTagTypes}
	/// @param[in] nr									Optionally specify a starting tag index to begin the search.
	/// @return												The variable tag's readable data, @formatConstant{nullptr} if this is not a variable tag or the tag could not be found. @theOwnsPointed{tag,data}
	//----------------------------------------------------------------------------------------
	const void* GetTagDataR(Int32 type, Int32 nr = 0) const { return C4DOS.Bo->GetTagDataR(this, type, nr); }

	//----------------------------------------------------------------------------------------
	/// Gets a variable tag's writable data of a certain type associated with the object.
	/// @param[in] type								The type of tag to fetch the data for: @enumerateEnum{VariableTagTypes}
	/// @param[in] nr									Optionally specify a starting tag index to begin the search.
	/// @return												The variable tag's writable data, @formatConstant{nullptr} if this is not a variable tag or the tag could not be found. @theOwnsPointed{tag,data}
	//----------------------------------------------------------------------------------------
	void* GetTagDataW(Int32 type, Int32 nr = 0) { return C4DOS.Bo->GetTagData(this, type, nr); }

	//----------------------------------------------------------------------------------------
	/// Gets the variable tag data count.
	/// @param[in] type								The type of tag to fetch the data for: @enumerateEnum{VariableTagTypes}
	/// @return												The data count in the variable tag.
	//----------------------------------------------------------------------------------------
	Int32 GetTagDataCount(Int32 type) const { return C4DOS.Bo->GetTagDataCount(this, type); }

	//----------------------------------------------------------------------------------------
	/// Creates and associates a tag with the object.
	/// @param[in] type								The type of tag to create: @enumerateEnum{TagTypes}
	/// @param[in] pred								The previous tag to insert the tag after, or @formatConstant{nullptr} if the tag should be inserted at the start of the tag list. @callerOwnsPointed{tag}
	/// @return												The new tag, or @formatConstant{nullptr} if failed. @theOwnsPointed{object,tag}
	//----------------------------------------------------------------------------------------
	BaseTag* MakeTag(Int32 type, BaseTag* pred = nullptr);

	//----------------------------------------------------------------------------------------
	/// Creates and associates a variable tag with the object.
	/// @param[in] type								The type of variable tag to create: @enumerateEnum{VariableTagTypes}
	/// @param[in] count							The data count.
	/// @param[in] pred								The previous tag to insert the tag after, or @formatConstant{nullptr} if the tag should be inserted at the start of the tag list. @callerOwnsPointed{tag}
	/// @return												The new variable tag, or @formatConstant{nullptr} if failed. @theOwnsPointed{object, variable tag}
	//----------------------------------------------------------------------------------------
	VariableTag* MakeVariableTag(Int32 type, Int32 count, BaseTag* pred = nullptr);

	//----------------------------------------------------------------------------------------
	/// Inserts tag into the object's tag list.
	/// @warning If the tag type was not registered with ::TAG_MULTIPLE, any existing old tag of same type will be implicitly removed. Any previous reference to the old tag will be invalid afterwards.
	/// @param[in] tp									The tag to insert. The object takes over the ownership of the pointed tag.
	/// @param[in] pred								The previous tag to insert the tag after, or @formatConstant{nullptr} if the tag should be inserted at the start of the tag list. @callerOwnsPointed{tag}
	//----------------------------------------------------------------------------------------
	void InsertTag(BaseTag* tp, BaseTag* pred = nullptr);

	//----------------------------------------------------------------------------------------
	/// Removes a tag from the object and frees its resources.
	/// @param[in] type								The type of tag to remove: @enumerateEnum{TagTypes}
	/// @param[in] nr									Optionally specify a starting tag index to begin the search.
	//----------------------------------------------------------------------------------------
	void KillTag(Int32 type, Int32 nr = 0);

	//----------------------------------------------------------------------------------------
	/// Copies the object's tags to another object.
	/// @param[in] dest								The destination object. @callerOwnsPointed{object}
	/// @param[in] visible						@formatConstant{true} if the tag must be visible, @formatConstant{false} if it must not be visible or @ref NOTOK if it can be either (if this property does not need to be checked).
	/// @param[in] variable						@formatConstant{true} if the tag must be variable, @formatConstant{false} if it must not be variable or @ref NOTOK if it can be either (if this property does not need to be checked).
	/// @param[in] hierarchical				@formatConstant{true} if the tag must be hierarchical, @formatConstant{false} if it must not be hierarchical or @ref NOTOK if it can be either (if this property does not need to be checked).
	/// @param[in] trans							An alias translator for the operation. Can be @formatConstant{nullptr}. @callerOwnsPointed{alias translator}
	/// @return												@trueIfOtherwiseFalse{the tags were copied successfully}
	//----------------------------------------------------------------------------------------
	Bool CopyTagsTo(BaseObject* dest, Int32 visible, Int32 variable, Int32 hierarchical, AliasTrans* trans);

	/// @}

	/// @name Cache
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets the object from the previously built cache.\n
	/// Situations can be quite complex in @C4D. For instance GetCache() could return a list of objects.\n
	/// For example the default Sweep Generator internally has some built-in caches for the sweep surface and for the caps.\n
	/// The following helper routine can be used to make things easier. It browses through this rather complex hierarchy of objects and caches recursively:
	/// @code
	/// void DoRecursion(BaseObject *op)
	/// {
	/// 	BaseObject* tp = op->GetDeformCache();
	/// 	if (tp)
	/// 	{
	/// 		DoRecursion(tp);
	/// 	}
	/// 	else
	/// 	{
	/// 		tp = op->GetCache(nullptr);
	/// 		if (tp)
	/// 		{
	/// 			DoRecursion(tp);
	/// 		}
	/// 		else
	/// 		{
	/// 			if (!op->GetBit(BIT_CONTROLOBJECT))
	/// 			{
	/// 				if (op->IsInstanceOf(Opolygon))
	/// 				{
	/// 					...
	/// 				}
	/// 			}
	/// 		}
	/// 	}
	///
	/// 	for (tp = op->GetDown(); tp; tp=tp->GetNext())
	/// 	{
	/// 		DoRecursion(tp);
	/// 	}
	/// }
	/// @endcode
	/// @b Remember:<br>
	/// Use the above routine only if the caches are already built. It is for instance not safe to use it in a @link CommandData command@endlink plugin since the user can have stopped the scene redraw and the building of caches.
	/// @see	CheckCache()
	///				GetDeformCache()
	/// @param[in] hh									A hierarchy help, usually passed from the calling method parameters, for example ObjectData::GetVirtualObjects(). @callerOwnsPointed{hierarchy help}\n
	/// 															Usually @formatConstant{nullptr}. Only for some special cases a hierarchy help must be passed.
	/// @return												The object's previously built cache or @formatConstant{nullptr}. @theOwnsPointed{object,object's cache}\n
	/// 															May return @formatConstant{nullptr} if the cache is not available or is not yet built.
	/// @see Hierarchy if a plugin needs access to pre-built caches.
	//----------------------------------------------------------------------------------------
	BaseObject* GetCache(HierarchyHelp* hh = nullptr) { return C4DOS.Bo->GetCache(this, hh); }

	//----------------------------------------------------------------------------------------
	/// Gets the previously built cache that has been deformed by an active deformer.\n
	/// It is important to understand the concept how the deformer cache operates.\n
	/// For each object in the hierarchy that generates a polygonal cache a deformer cache could also have been created by an active deformer object.\n
	/// A simple example will help to see how this works:
	/// @image html cache_arraycube1.png
	/// Take the simple hierarchy shown above, the array generator object creates a virtual hierarchy in the cache, this can be retrieved using GetCache().\n
	/// This hierarchy is:
	/// @image html cache_arraycube2.png
	/// From each of the Cube objects a further cache is generated, this time polygonal:
	/// @image html cache_arraycube3.png
	/// From these the deformer object generates a deformed polygon cache:
	/// @image html cache_arraycube4.png
	/// So the final hierarchy is:
	/// @image html cache_arraycube5.png
	/// When a deformer becomes active every object/cache object gets a deform cache (if it was a polygonal object). The deformer cache is always polygonal and is only ever a single object.\n
	/// @b Important:<br>
	/// The caches are always built after all plugins and expressions have been called.\n
	/// If the virtual objects have to be accessed to obtain a polygonal based object it is generally advised to call SendModelingCommand() with @ref MCOMMAND_CURRENTSTATETOOBJECT.\n
	/// This will rebuild the cache for the passed object if needed, and then clone the polygonal objects.\n
	/// Another possible solution is to use the Hierarchy class, this will give full access to all virtual objects, or can be used to just rebuild the internal caches.\n
	/// But be aware that rebuilding the internal caches can cause serious overhead, be time consuming and if called too soon in the pipeline, the caches may need to be rebuilt afterwards.
	/// @return												The objects previously built deformed cache or @formatConstant{nullptr}. @theOwnsPointed{object,object's cache}\n
	/// 															May return @formatConstant{nullptr} if the cache is not available or is not yet built.
	/// @see Hierarchy if a plugin needs access to pre-built caches.
	//----------------------------------------------------------------------------------------
	BaseObject* GetDeformCache(void) { return C4DOS.Bo->GetDeformCache(this); }

	//----------------------------------------------------------------------------------------
	/// Gets the previously built isoparm representation of the object.
	/// @return												The isoparm representation of the object or @formatConstant{nullptr}. @theOwnsPointed{object,isoparm}\n
	/// 															May return @formatConstant{nullptr} if the isoparm is not available or is not yet built.
	/// @see Hierarchy if a plugin needs access to pre-built caches.
	//----------------------------------------------------------------------------------------
	LineObject* GetIsoparm(void) { return C4DOS.Bo->GetIsoparm(this); }

	//----------------------------------------------------------------------------------------
	/// Sets the isoparm representation of the object.
	/// @warning Must only be called from within ObjectData::GetVirtualObjects() of a generator object.
	/// @param[in] l									The isoparm representation of the object to set. The object takes over the ownership of the pointed isoparm.
	//----------------------------------------------------------------------------------------
	void SetIsoparm(LineObject* l);

	//----------------------------------------------------------------------------------------
	/// A cache/deform object has no GetUp() link. Instead this method can be called to detect the cache building parent.
	/// @return												The cache parent or @formatConstant{nullptr}. @theOwnsPointed{object,cache parent}
	//----------------------------------------------------------------------------------------
	BaseObject* GetCacheParent(void) const;

	//----------------------------------------------------------------------------------------
	/// A cache/deform object has no GetUp() link. Instead this method can be called to detect the top cache building parent.
	/// @return												The top cache parent or @formatConstant{nullptr}. @theOwnsPointed{object,top cache parent}
	//----------------------------------------------------------------------------------------
	BaseObject* GetCacheTopParent(void) const;

	/// @}

	/// @name Phong
	/// @{

	//----------------------------------------------------------------------------------------
	/// Sets the phong smoothing for the object.\n
	/// Deletes any existing Phong tag. If @formatParam{on} is set to @formatConstant{true} it creates a new Phong tag.
	/// @param[in] on									@formatConstant{false} removes the Phong tag from the object. @formatConstant{true} creates a new Phong tag.
	/// @param[in] anglelimit					@formatConstant{true} if @formatParam{angle} should be used.
	/// @param[in] angle							The phong angle.
	/// @return												@trueIfOtherwiseFalse{the phong smoothing was changed successfully}
	//----------------------------------------------------------------------------------------
	Bool SetPhong(Bool on, Bool anglelimit, Float angle);

	/// @}

	/// @name Dirty
	/// @{

	//----------------------------------------------------------------------------------------
	/// Checks if the object has been changed since the last time the object was touched.
	/// @param[in] flags							The object part to check: @enumerateEnum{DIRTYFLAGS}
	/// @return												@trueIfOtherwiseFalse{the object is dirty}
	//----------------------------------------------------------------------------------------
	Bool IsDirty(DIRTYFLAGS flags) { return C4DOS.Bo->IsDirty(this, flags); }

	//----------------------------------------------------------------------------------------
	/// Sets if any part of the object was changed.
	/// @param[in] flags							The object part that was changed: @enumerateEnum{DIRTYFLAGS}
	//----------------------------------------------------------------------------------------
	void SetDirty(DIRTYFLAGS flags) { C4DOS.Bo->SetDirty(this, flags); }

	//----------------------------------------------------------------------------------------
	/// Check if cache is built and if it matches the requirements (polygonized/isoparm, level of detail etc.)
	/// @note Must only be called from within ObjectData::GetVirtualObjects() of a generator object.
	/// @param[in] hh									A HierarchyHelp, usually passed from the calling method parameters, for instance ObjectData::GetVirtualObjects().
	/// @return												@formatConstant{true} if the cache is dirty, @formatConstant{false} if it is valid.
	//----------------------------------------------------------------------------------------
	Bool CheckCache(HierarchyHelp* hh) { return C4DOS.Bo->CheckCache(this, hh); }

	//----------------------------------------------------------------------------------------
	/// Marks object to be used by generator. Automatically resets dirty values for use with IsDirty().
	//----------------------------------------------------------------------------------------
	void Touch(void);

	/// @}

	/// @name Color Properties
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets the object's color properties and fill @formatParam{prop}.
	/// @param[in] prop								Filled with the color properties. @callerOwnsPointed{color properties}
	//----------------------------------------------------------------------------------------
	void GetColorProperties(ObjectColorProperties* prop);

	//----------------------------------------------------------------------------------------
	/// Sets the object's color properties from @formatParam{prop}.
	/// @param[in] prop								The color properties to set. @callerOwnsPointed{color properties}
	//----------------------------------------------------------------------------------------
	void SetColorProperties(ObjectColorProperties* prop);

	/// @}

	/// @name Modeling Axis
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets the internal matrix for the modeling axis.
	/// @note To access the axis type, and other axis options, use the IDs defined in @em ToolModelingAxis.h.
	/// @param[in] doc								The document for the operation. @callerOwnsPointed{document}
	/// @return												The modeling axis.
	//----------------------------------------------------------------------------------------
	const Matrix& GetModelingAxis(BaseDocument* doc) { return C4DOS.Bo->GetModelingAxis(this, doc); }

	//----------------------------------------------------------------------------------------
	/// Sets the internal matrix for the modeling axis.
	/// @note To access the axis type, and other axis options, use the IDs in ToolModelingAxis.res.
	/// Here is a code sample:
	/// @code
	/// void SetToolData(BaseDocument *doc, Int32 pluginid, Int32 dataid, const GeData &dat)
	/// {
	/// 	BasePlugin *plug = static_cast<BasePlugin*>(FindPlugin(pluginid, PLUGINTYPE::TOOL));
	/// 	if (!plug) return;
	/// 	plug->SetParameter(DescID(dataid), dat, 0);
	/// }
	///
	/// SetToolData(doc, ID_MODELING_LIVESELECTION, MDATA_AXIS_MODE, MDATA_AXIS_MODE_FREE);
	/// @endcode
	/// If the matrix is changed so that it does not fit the current mode the axis mode should be set to @ref MDATA_AXIS_MODE_FREE.
	/// @param[in] m									The new modeling axis to set.
	//----------------------------------------------------------------------------------------
	void SetModelingAxis(const Matrix& m) { C4DOS.Bo->SetModelingAxis(this, m); }

	/// @}

	/// @name Hierarchy Clone
	/// @{

	//----------------------------------------------------------------------------------------
	/// Checks and generates a clone of the child objects of a parent generator.\n
	/// Similar to GetHierarchyClone() except that it checks if the hierarchy is dirty and if not it does not need to generate a new clone.
	/// @see GetHierarchyClone()
	/// @param[in] hh									Usually passed through from a calling method, for instance from ObjectData::GetVirtualObjects(). @callerOwnsPointed{hierarchy helper}
	/// @param[in] op									The object to start the clone from, usually the first child of the parent object. @callerOwnsPointed{object}
	/// @param[in] flags							The flags for the generation of the cloned chain. The values are: @enumerateEnum{HIERARCHYCLONEFLAGS}
	/// @param[in] dirty							Assigned the state of any changes to the chain. @trueIfOtherwiseFalse{some part of the child objects in the chain has changed}
	/// @param[in] trans							An alias translator for the operation. Can be @formatConstant{nullptr}. @callerOwnsPointed{alias translator}
	/// @param[in] allchildren				@formatConstant{true} if all children should be used in the check.
	/// @return												The cloned objects. @callerOwnsPointed{object}
	//----------------------------------------------------------------------------------------
	BaseObject* GetAndCheckHierarchyClone(HierarchyHelp* hh, BaseObject* op, HIERARCHYCLONEFLAGS flags, Bool* dirty, AliasTrans* trans, Bool allchildren);

	//----------------------------------------------------------------------------------------
	/// Generates a clone of the child objects of a parent generator.
	/// @note	The result given by GetAndCheckHierarchyClone() will be a chain of objects with various types.\n
	///				Passing @ref HIERARCHYCLONEFLAGS::ASLINE e.g. will force all splines to be converted, but not every object in the chain will be of type @ref Oline; some objects like PolygonObject cannot be converted, also @ref Onull.
	/// @param[in] hh									Usually passed through from a calling method, for instance from ObjectData::GetVirtualObjects(). @callerOwnsPointed{hierarchy helper}
	/// @param[in] op									The object to start the clone from, usually the parent object itself. @callerOwnsPointed{object}
	/// @param[in] flags							The flags for the generation of the cloned chain. The values are: @enumerateEnum{HIERARCHYCLONEFLAGS}
	/// @param[in] dirty							Has to be set to @formatConstant{nullptr} for the cloning to take place. Set to @formatConstant{true} if some part of the child objects in the chain has changed, or @formatConstant{false} if nothing has changed.
	/// @param[in] trans							An alias translator for the operation. Can be @formatConstant{nullptr}. @callerOwnsPointed{alias translator}
	/// @return												The cloned object(s). @callerOwnsPointed{object}
	//----------------------------------------------------------------------------------------
	BaseObject* GetHierarchyClone(HierarchyHelp* hh, BaseObject* op, HIERARCHYCLONEFLAGS flags, Bool* dirty, AliasTrans* trans);

	//----------------------------------------------------------------------------------------
	/// Generates a clone of the child objects of a parent generator. This version accepts @formatParam{dirtyflags} parameter.
	/// @since R19
	/// @note	The result given by GetAndCheckHierarchyClone() will be a chain of objects with various types.\n
	///				Passing @ref HIERARCHYCLONEFLAGS::ASLINE e.g. will force all splines to be converted, but not every object in the chain will be of type @ref Oline; some objects like PolygonObject cannot be converted, also @ref Onull.
	/// @param[in] hh									Usually passed through from a calling method, for instance from ObjectData::GetVirtualObjects(). @callerOwnsPointed{hierarchy helper}
	/// @param[in] op									The object to start the clone from, usually the parent object itself. @callerOwnsPointed{object}
	/// @param[in] flags							The flags for the generation of the cloned chain. The values are: @enumerateEnum{HIERARCHYCLONEFLAGS}
	/// @param[in] dirty							Has to be set to @formatConstant{nullptr} for the cloning to take place. Set to @formatConstant{true} if some part of the child objects in the chain has changed, or @formatConstant{false} if nothing has changed.
	/// @param[in] trans							An alias translator for the operation. Can be @formatConstant{nullptr}. @callerOwnsPointed{alias translator}
	/// @param[in] dirtyflags					The dirty flags stored within the dependence list.
	/// @return												The cloned object(s). @callerOwnsPointed{object}
	//----------------------------------------------------------------------------------------
	BaseObject* GetHierarchyClone(HierarchyHelp* hh, BaseObject* op, HIERARCHYCLONEFLAGS flags, Bool* dirty, AliasTrans* trans, DIRTYFLAGS dirtyflags);

	/// @}

	/// @name Dependence List
	/// @{

	//----------------------------------------------------------------------------------------
	/// Starts a new dependence list. Enables to keep track of changes made to any children.
	//----------------------------------------------------------------------------------------
	void NewDependenceList(void);

	//----------------------------------------------------------------------------------------
	/// Compares if anything in the dependence list has changed.
	/// @return												@trueIfOtherwiseFalse{the dependence list has not changed}
	//----------------------------------------------------------------------------------------
	Bool CompareDependenceList(void);

	//----------------------------------------------------------------------------------------
	/// Adds a child object to the dependence list.\n
	/// Usually @formatParam{op} is a child object used by a generator object.
	/// @param[in] hh									Usually passed from a calling method, for example from ObjectData::GetVirtualObjects(). @callerOwnsPointed{hierarchy help}
	/// @param[in] op									The child object to add to the dependence list. Should be a child object used by the generator object. @callerOwnsPointed{object}
	//----------------------------------------------------------------------------------------
	void AddDependence(HierarchyHelp* hh, BaseObject* op);

	//----------------------------------------------------------------------------------------
	/// Adds a child object to the dependence list. This version accepts @formatParam{dirtyflags} parameter.
	/// @since R19
	/// @param[in] hh									Usually passed from a calling method, for example from ObjectData::GetVirtualObjects(). @callerOwnsPointed{hierarchy help}
	/// @param[in] op									The child object to add to the dependence list. Should be a child object used by the generator object. @callerOwnsPointed{object}
	/// @param[in] dirtyflags					The dirty flags stored within the dependence list.
	//----------------------------------------------------------------------------------------
	void AddDependence(HierarchyHelp* hh, BaseObject* op, DIRTYFLAGS dirtyflags);

	//----------------------------------------------------------------------------------------
	/// Marks all the objects in the dependence list to be replaced by the generator.
	//----------------------------------------------------------------------------------------
	void TouchDependenceList(void);

	/// @}


	/// @name Rotation Order
	/// @{

	//----------------------------------------------------------------------------------------
	/// Sets the rotation order of the object.
	/// @param[in] order							The rotation order to set for the object: @enumerateEnum{ROTATIONORDER}
	//----------------------------------------------------------------------------------------
	void SetRotationOrder(ROTATIONORDER order) { BoCall(SetRotationOrder) (order); }

	//----------------------------------------------------------------------------------------
	/// Gets the rotation order of the object.
	/// @return												The rotation order of the object: @enumerateEnum{ROTATIONORDER}
	//----------------------------------------------------------------------------------------
	ROTATIONORDER GetRotationOrder(void) const { return BoCall(GetRotationOrder) (); }

	/// @}

	/// @name Synchronized Rotation Mode
	/// @{

	//----------------------------------------------------------------------------------------
	/// Sets the Synchronized Rotation Mode of the object.
	/// @since R18
	/// @param[in] active							Enable/Disable the Synchronized Rotation mode for the object.
	/// @param[in] bUndo							Add undo to value changed (need to manage start and end externally).
	//----------------------------------------------------------------------------------------
	void SetQuaternionRotationMode(Bool active, Bool bUndo) { BoCall(SetQuaternionRotationMode) (active, bUndo); }

	//----------------------------------------------------------------------------------------
	/// Checks if Object Rotation is interpolated in Quaternion Mode.
	/// @since R18
	/// @return												@trueIfOtherwiseFalse{Rotation Interpolation is Quaternion}
	//----------------------------------------------------------------------------------------
	Bool IsQuaternionRotationMode(void) { return BoCall(IsQuaternionRotationMode) (); }

	//----------------------------------------------------------------------------------------
	/// Makes sure that the track Curves component are synchronized (keys on each component).
	/// If a component track is found, the other track component will be synchronized.
	/// @since R18
	/// @param[in] vectorTrackID			ID of the Vector Track to synchronize.
	/// @param[in] bUndo							Add undo to value changed (need to manage start and end externally).
	/// @param[in] startRange					Optional start operation at given time.
	/// @param[in] endRange						Optional end operation at given time.
	/// @return												@trueIfOtherwiseFalse{Track Synchronization was successful}
	//----------------------------------------------------------------------------------------
	Bool SynchronizeVectorTrackKeys(Int32 vectorTrackID, Bool bUndo, BaseTime startRange = BaseTime(-108000, 1), BaseTime endRange = BaseTime(108000, 1));

	//----------------------------------------------------------------------------------------
	/// Tries to find the best Euler Angle according to the previous key. The Object must have keys on each component.
	/// @since R18
	/// @param[in] rotationTrackID		Rotation Track ID to manage (relative, global, absolute, frozen).
	/// @param[in] bAdjustTangent			Try to adjust the tangent with new value, if @formatConstant{false} auto is used.
	/// @param[in] bUndo							Add undo to value changed (need to manage start and end externally).
	/// @param[in] startRange					Optional start operation at given time.
	/// @param[in] endRange						Optional end operation at given time.
	/// @return												@trueIfOtherwiseFalse{Rotation Synchronization was successful}
	//----------------------------------------------------------------------------------------
	Bool FindBestEulerAngle(Int32 rotationTrackID, Bool bAdjustTangent, Bool bUndo, BaseTime startRange = BaseTime(-108000, 1), BaseTime endRange = BaseTime(108000, 1));

	//----------------------------------------------------------------------------------------
	/// Forces an evaluation of all rotation tracks and consider Quaternion interpolation.
	/// This will directly update attribute values if no vector is specified for @formatParam{resultRotation}.
	/// @since R18
	/// @param[in] time								Evaluation time.
	/// @param[in] flags							The animate flags: @enumerateEnum{ANIMATEFLAGS}
	/// @param[in] resultRotation			Optionally store result in Vector instead of updating attributes.
	/// @return												@trueIfOtherwiseFalse{evaluation was a success}
	//----------------------------------------------------------------------------------------
	Bool EvaluateSynchronizedRotation(const BaseTime &time, ANIMATEFLAGS flags, Vector *resultRotation = nullptr);
	/// @}


	/// @name Miscellaneous
	/// @{

	//----------------------------------------------------------------------------------------
	/// Returns each component track for the given DescID.
	/// @since R18
	/// @param[in] id									ID of desired vector.
	/// @param[out] xfound						X Track of Vector if found.
	/// @param[out] yfound						Y Track of Vector if found.
	/// @param[out] zfound						Z Track of Vector if found.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool GetVectorTracks(const DescID &id, CTrack *&xfound, CTrack *&yfound, CTrack *&zfound);

	//----------------------------------------------------------------------------------------
	/// Returns each component CCurve for the given curve.
	/// @since R18
	/// @param[in] curveToSearch			CCurve Component of desired vector.
	/// @param[out] xfound						X CCurve of Vector if found.
	/// @param[out] yfound						Y CCurve of Vector if found.
	/// @param[out] zfound						Z CCurve of Vector if found.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool GetVectorCurves(CCurve *curveToSearch, CCurve *&xfound, CCurve *&yfound, CCurve *&zfound);

	//----------------------------------------------------------------------------------------
	/// Gets a unique ID for any object in a document.\n
	/// Works for generated objects in a cache (e.g. clones generated by a MoGraph cloner) and also for 'real' objects in the document (GetUniqueIP() does not do this).
	/// @note	The ID generation for cache objects is based on GetUniqueIP(), so if two cache objects have the same IP, they will probably also get the same GUID\n
	///				(unless they are PointObject or PolygonObject with different point or polygon count).\n
	///				The ID generation for 'real' objects is based on the object's GeMarker, so if an object has no marker it will not return a unique ID.
	/// @return												A checksum for the object.
	//----------------------------------------------------------------------------------------
	UInt64 GetGUID() { return C4DOS.Bo->GetGUID(this); }


	//----------------------------------------------------------------------------------------
	/// Checks if a highlight handle has been hit.\n
	/// Returns the handle ID previously given by ObjectData::DetectHandle(). The handle can then be drawn in the highlight mode.
	/// @param[in] bd									The base draw for the operation. @callerOwnsPointed{base draw}
	/// @return												The handle ID.
	//----------------------------------------------------------------------------------------
	Int32 GetHighlightHandle(BaseDraw* bd) { return C4DOS.Bo->GetHighlightHandle(this, bd); }

	//----------------------------------------------------------------------------------------
	/// Gets a real spline representation of a primitive spline object.\n
	/// This can for example be used to calculate the length of a spline.\n
	/// If the object is a real spline it returns @c this. Otherwise @formatConstant{nullptr}.
	/// @return												The real spline object. @theOwnsPointed{object owns,spline}
	/// 															@note The matrix of the returned object must not be used. Use the matrix of @c *this instead.
	//----------------------------------------------------------------------------------------
	SplineObject* GetRealSpline(void);

	//----------------------------------------------------------------------------------------
	/// Gets the object's visibility value. The range of values are @em 0.0 <= @formatParam{visibility} <= @em 1.0.\n
	/// The object's visibility depends upon its parent, if it has no visibility track this will return the parent's visibility which is passed.\n
	/// @note In the editor only a visibility of @em 0.0 can be noticed but all other intermediate values are visualized in render only.
	/// @param[in] parent							The parent object's visibility.
	/// @return												The visibility.
	//----------------------------------------------------------------------------------------
	Float GetVisibility(Float parent);

	//----------------------------------------------------------------------------------------
	/// Checks if the object is a child of @formatParam{op}.
	/// @param[in] op									The object to search within his hierarchy.
	/// @return												@trueIfOtherwiseFalse{the object is a child of @formatParam{op}}
	//----------------------------------------------------------------------------------------
	Bool SearchHierarchy(BaseObject* op) { return C4DOS.Bo->SearchHierarchy(this, op); }

	/// @}

	/// @name Private
	/// @{

	//----------------------------------------------------------------------------------------
	/// @markPrivate
	//----------------------------------------------------------------------------------------
	BaseObject* GetOrigin(Bool safe);

	//----------------------------------------------------------------------------------------
	/// @markPrivate
	//----------------------------------------------------------------------------------------
	void SetOrigin(BaseObject* origin);

	//----------------------------------------------------------------------------------------
	/// @markPrivate
	//----------------------------------------------------------------------------------------
	BaseObject* GetTopOrigin(Bool parent, Bool safe);

	//----------------------------------------------------------------------------------------
	/// @markPrivate
	//----------------------------------------------------------------------------------------
	BaseObject* GetEditObject(BaseObject** psds, DISPLAYEDITSTATE state, Bool safetey = true);

	//----------------------------------------------------------------------------------------
	/// @markPrivate
	//----------------------------------------------------------------------------------------
	void RemoveFromCache(void);

	//----------------------------------------------------------------------------------------
	/// @markPrivate
	//----------------------------------------------------------------------------------------
	DRAWRESULT ObjDraw(DRAWPASS drawpass, BaseDraw *bd, BaseDrawHelp *bh);

	/// @}
};

//----------------------------------------------------------------------------------------
/// Represents a Camera object.
/// @addAllocFreeAutoAllocNote
//----------------------------------------------------------------------------------------
class CameraObject : public BaseObject
{
private:
	CameraObject();
	~CameraObject();

public:
	/// @name Alloc/Free
	/// @{

	//----------------------------------------------------------------------------------------
	/// @allocatesA{camera object}
	/// @return												@allocReturn{camera object}
	//----------------------------------------------------------------------------------------
	static CameraObject* Alloc();

	//----------------------------------------------------------------------------------------
	/// @destructsAlloc{camera objects}
	/// @param[in,out] bl							@theToDestruct{camera object}
	//----------------------------------------------------------------------------------------
	static void Free(CameraObject*& bl);

	/// @}

	/// @name Projection
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets the projection of the camera.
	/// @note For information about the projections used in @C4D see BaseView::GetViewParameter()
	/// @return												The camera's projection. See Ocamera.h for values.
	//----------------------------------------------------------------------------------------
	Int32 GetProjection() const;

	//----------------------------------------------------------------------------------------
	/// Sets the projection of the camera.
	/// @note For information about the projections used in @C4D see BaseView::GetViewParameter()
	/// @param[in] projection					The new camera projection to set. See Ocamera.h for values.
	/// @return												@trueIfOtherwiseFalse{the camera projection was successfully set}
	//----------------------------------------------------------------------------------------
	Bool SetProjection(Int32 projection);

	/// @}

	/// @name Zoom
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets the zoom of the camera.
	/// @return												The camera's zoom.
	//----------------------------------------------------------------------------------------
	Float GetZoom() const;

	//----------------------------------------------------------------------------------------
	/// Sets the zoom of the camera.
	/// @param[in] zoom								The new camera zoom to set.
	/// @return												@trueIfOtherwiseFalse{the camera zoom was successfully set}
	//----------------------------------------------------------------------------------------
	Bool SetZoom(Float zoom);

	/// @}

	/// @name Offset
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets the offset of the camera.\n
	/// This is the midpoint for orthogonal projections. (Front/Back/Top/Bottom etc.)
	/// @return												The camera's offset/midpoint.
	//----------------------------------------------------------------------------------------
	Vector GetOffset() const;

	//----------------------------------------------------------------------------------------
	/// Sets the offset of the camera.\n
	/// This is the midpoint for orthogonal projections. (Front/Back/Top/Bottom etc.)
	/// @param[in] offset							The new offset/midpoint.
	/// @return												@trueIfOtherwiseFalse{the camera offset was successfully set}
	//----------------------------------------------------------------------------------------
	Bool SetOffset(const Vector& offset);

	/// @}

	/// @name Aperture
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets the aperture width of the camera.
	/// @return												The camera's aperture.
	//----------------------------------------------------------------------------------------
	Float GetAperture() const;

	//----------------------------------------------------------------------------------------
	/// Sets the aperture width of the camera.
	/// @param[in] v									The new camera aperture to set.
	/// @return												@trueIfOtherwiseFalse{the camera aperture was successfully set}
	//----------------------------------------------------------------------------------------
	Bool SetAperture(Float v);

	/// @}

	/// @name Focus
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets the focus of the camera.
	/// @return												The camera's focus.
	//----------------------------------------------------------------------------------------
	Float GetFocus() const;

	//----------------------------------------------------------------------------------------
	/// Sets the focus of the camera.
	/// @param[in] v									The new camera focus to set.
	/// @return												@trueIfOtherwiseFalse{the camera focus was successfully set}
	//----------------------------------------------------------------------------------------
	Bool SetFocus(Float v);

	//----------------------------------------------------------------------------------------
	/// Gets the target distance of the camera. This function may change the CAMERAOBJECT_TARGETDISTANCE setting of the camera.
	/// @param[in] doc								Document in which the camera is.
	/// @return												The camera's target distance.
	//----------------------------------------------------------------------------------------
	Float GetTargetDistance(BaseDocument* doc);

	/// @}

	/// @name Stereo
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets how many cameras compose a stereo camera.
	/// @param[in] doc								The document for the operation. @callerOwnsPointed{document}
	/// @param[in] bd									The stereoscopic view. @callerOwnsPointed{view}
	/// @param[in] rd									The stereoscopic render settings. @callerOwnsPointed{render data}
	/// @param[in] flags							Currently unused. Set to @em 0.
	/// @return												The number of cameras.
	//----------------------------------------------------------------------------------------
	Int32 StereoGetCameraCount(BaseDocument* doc, BaseDraw* bd, RenderData* rd, Int32 flags) const;

	//----------------------------------------------------------------------------------------
	/// Gets stereoscopic camera information.
	/// @param[in] doc								The document for the operation. @callerOwnsPointed{document}
	/// @param[in] bd									The stereoscopic view. @callerOwnsPointed{view}
	/// @param[in] rd									The stereoscopic render settings. @callerOwnsPointed{render data}
	/// @param[in] n									The stereoscopic camera index: @em 0 <= @formatParam{n} < StereoGetCameraCount()
	/// @param[out] info							Assigned the stereoscopic camera data.
	/// @param[in] flags							Currently unused. Set to @em 0.
	/// @return												@trueIfOtherwiseFalse{the stereoscopic camera information was successfully retrieved}
	//----------------------------------------------------------------------------------------
	Bool StereoGetCameraInfo(BaseDocument* doc, BaseDraw* bd, RenderData* rd, Int32 n, StereoCameraInfo& info, Int32 flags) const;

	/// @}
};

//----------------------------------------------------------------------------------------
/// Represents a Point object.
/// Abstract, so instantiate either PolygonObject or SplineObject.
//----------------------------------------------------------------------------------------
class PointObject : public BaseObject
{
private:
	PointObject();
	~PointObject();

public:
	//----------------------------------------------------------------------------------------
	/// Gets the selected points.
	/// @return												The selected points. @theOwnsPointed{point object,base select}
	//----------------------------------------------------------------------------------------
	BaseSelect* GetPointS(void);

	//----------------------------------------------------------------------------------------
	/// Gets the selected points.
	/// @return												The selected points. @theOwnsPointed{point object,base select}
	//----------------------------------------------------------------------------------------
	const BaseSelect* GetPointS(void) const;

	//----------------------------------------------------------------------------------------
	/// Gets the hidden points.
	/// @return												The hidden points. @theOwnsPointed{point object,base select}
	//----------------------------------------------------------------------------------------
	BaseSelect* GetPointH(void);

	//----------------------------------------------------------------------------------------
	/// Gets the hidden points.
	/// @return												The hidden points. @theOwnsPointed{point object,base select}
	//----------------------------------------------------------------------------------------
	const BaseSelect* GetPointH(void) const;

	//----------------------------------------------------------------------------------------
	/// Gets the start of the read-only points array.
	/// @note While this function may sound trivial and cheap, internally it is not. For performance reasons, it is not recommended to use this function inside a loop or inside a loop condition.
	/// @return												The address of the read-only points array. @theOwnsPointed{point object,points array}
	//----------------------------------------------------------------------------------------
	const Vector* GetPointR(void) const { return (const Vector*)GetTagDataR(Tpoint); }

	//----------------------------------------------------------------------------------------
	/// Gets the start of the writable points array.
	/// @note While this function may sound trivial and cheap, internally it is not. For performance reasons, it is not recommended to use this function inside a loop or inside a loop condition.
	/// @return												The address of the writable points array. @theOwnsPointed{point object,points array}
	//----------------------------------------------------------------------------------------
	Vector* GetPointW(void) { return (Vector*)GetTagDataW(Tpoint); }

	//----------------------------------------------------------------------------------------
	/// Gets the number of points in the object.
	/// @note While this function may sound trivial and cheap, internally it is not. For performance reasons, it is not recommended to use this function inside a loop or inside a loop condition.
	/// @return												The point count in the points array.
	//----------------------------------------------------------------------------------------
	Int32 GetPointCount(void) const { return GetTagDataCount(Tpoint); }

	//----------------------------------------------------------------------------------------
	/// Gets an array of vertex weights.
	/// @warning The returned array must be freed afterwards with DeleteMem()
	/// @param[in] modifier						The modifier object. @callerOwnsPointed{modifier}
	/// @return												The address of the weights array, or @formatConstant{nullptr}. @callerOwnsPointed{array}
	//----------------------------------------------------------------------------------------
	Float32* CalcVertexMap(BaseObject* modifier);

	//----------------------------------------------------------------------------------------
	/// Changes the number of points in the object.
	/// @param[in] pcnt								The new number of points.
	/// @return												@trueIfOtherwiseFalse{the number of points was changed successfully}
	//----------------------------------------------------------------------------------------
	Bool ResizeObject(Int32 pcnt);

	//----------------------------------------------------------------------------------------
	/// Increases the bounding box of the object without making the object dirty.\n
	/// Adds the vectors from v[0] to v[cnt-1] to the bounding box of the object.
	/// @param[in] cnt								The vector count in array @formatParam{v}.
	/// @param[in] v									The Vector array. @callerOwnsPointed{array}
	//----------------------------------------------------------------------------------------
	void IncreaseBoundingBox(Int32 cnt, Vector* v);	// increases the bounding box of the object without making the object dirty
};


//----------------------------------------------------------------------------------------
/// Holds information about Line object points.
///
/// A Line object is created from a spline (think of it as a linear spline).\n
/// It does not appear in the editor, but only in the virtual caches: a spline there is converted to a Line object.\n
/// For instance think of the Circle spline with a Bend on it. The Circle spline only contains 4 points, so it cannot be bended (or it would look very odd).\n
/// So the Circle spline is subdivided and converted into a Line object and then the Line object is bended. Through its subdivision the result looks good.
///
/// During the process of subdividing and converting, the information how the Line object was generated is stored.
///
/// The LineObject contains for every point the values @em t and @em pos:
/// - <i>t</i> is the original spline parameter that generated the point (using SplineObject::GetSplinePoint()).
/// - <i>pos</i> is the percentage position of the point for the whole spline circumference.
//----------------------------------------------------------------------------------------
struct CLine
{
	Float	t,			///< The original spline point for the Line. @see SplineObject::GetSplinePoint()
				pos;		///< The percentage position of the point for the whole spline circumference.
};

//----------------------------------------------------------------------------------------
/// Represents a Line object.
/// @addAllocFreeAutoAllocNote
/// @see CLine
//----------------------------------------------------------------------------------------
class LineObject : public PointObject
{
private:
	LineObject();
	~LineObject();

public:
	/// @name Alloc/Free
	/// @{

	//----------------------------------------------------------------------------------------
	/// @allocatesA{Line object}
	/// @param[in] pcnt								The point count.
	/// @param[in] scnt								The segment count.
	/// @return												@allocReturn{Line object}
	//----------------------------------------------------------------------------------------
	static LineObject* Alloc(Int32 pcnt, Int32 scnt);

	//----------------------------------------------------------------------------------------
	/// @destructsAlloc{Line objects}
	/// @param[in,out] bl							@theToDestruct{Line object}
	//----------------------------------------------------------------------------------------
	static void Free(LineObject*& bl);

	/// @}

	/// @name Segment
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets the start of the read-only segments array.
	/// @return												The first element in the array of read-only segments. @theOwnsPointed{Line object,array}
	//----------------------------------------------------------------------------------------
	const Segment* GetSegmentR(void) { return (const Segment*)GetTagDataR(Tsegment); }

	//----------------------------------------------------------------------------------------
	/// Gets the start of the writable segments array.
	/// @return												The first element in the array of writable segments. @theOwnsPointed{Line object,array}
	//----------------------------------------------------------------------------------------
	Segment* GetSegmentW(void) { return (Segment*)GetTagDataW(Tsegment); }

	//----------------------------------------------------------------------------------------
	/// Gets the number of segments.
	/// @return												The number of elements in the segments array.
	//----------------------------------------------------------------------------------------
	Int32 GetSegmentCount(void) { return GetTagDataCount(Tsegment); }

	/// @}

	/// @name Line
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets the start of the read-only array of lines.\n
	/// The size of the array is found calling PointObject::GetPointCount().
	/// @return												The first element in the array of read-only lines. @theOwnsPointed{Line object,array}
	//----------------------------------------------------------------------------------------
	const CLine* GetLineR(void) { return (const CLine*)GetTagDataR(Tline); }

	//----------------------------------------------------------------------------------------
	/// Gets the start of the writable array of lines.\n
	/// The size of the array is found calling PointObject::GetPointCount().
	/// @return												The first element in the array of writable lines. @theOwnsPointed{Line object,array}
	//----------------------------------------------------------------------------------------
	CLine* GetLineW(void) { return (CLine*)GetTagDataW(Tline); }

	/// @}

	/// @name Miscellaneous
	/// @{

	//----------------------------------------------------------------------------------------
	/// Changes the number of points and segments.
	/// @param[in] pcnt								The new number number of points.
	/// @param[in] scnt								The new number of segments.
	/// @return												@trueIfOtherwiseFalse{the number of points and segments was changed successfully}
	//----------------------------------------------------------------------------------------
	Bool ResizeObject(Int32 pcnt, Int32 scnt);

	//----------------------------------------------------------------------------------------
	/// Converts the LineObject into polygons.
	/// @param[in] regular						The size of polygons to fill the inside of the line object with. Pass @em 0.0 to connect the contour with no filling.
	/// @param[in] bt									The current thread, or @formatConstant{nullptr} for the main @C4D thread. @callerOwnsPointed{thread}
	/// @return												The created polygon object. @callerOwnsPointed{Polygon object}
	//----------------------------------------------------------------------------------------
	PolygonObject* Triangulate(Float regular, BaseThread* bt);

	/// @}
};


/// @addtogroup POLYOBJECT_VBO
/// @ingroup group_enumeration
/// @{
#define POLYOBJECT_VBO_VERTEX						0x00000001			///< Vertex buffer.
#define POLYOBJECT_VBO_PHONG_NORMAL			0x00000002			///< Phong normal buffer.
#define POLYOBJECT_VBO_POLYGON_NORMAL		0x00000004			///< Polygon normal buffer.
#define POLYOBJECT_VBO_DISPLACE_NORMAL	0x00000008			///< Displacement normal buffer.
#define POLYOBJECT_VBO_STICK_TEXTURE		0x00000010			///< Stick texture coordinate buffer.
#define POLYOBJECT_VBO_COLOR						0x00000020			///< Vertex color buffer.
/// @}

//----------------------------------------------------------------------------------------
/// Represents a Polygon object.
/// @addAllocFreeAutoAllocNote
//----------------------------------------------------------------------------------------
class PolygonObject : public PointObject
{
private:
	PolygonObject();
	~PolygonObject();

public:
	/// @name Alloc/Free
	/// @{

	//----------------------------------------------------------------------------------------
	/// @allocatesA{Polygon object}
	/// @param[in] pcnt								The point count.
	/// @param[in] vcnt								The polygon count.
	/// @return												@allocReturn{Polygon object}
	//----------------------------------------------------------------------------------------
	static PolygonObject* Alloc(Int32 pcnt, Int32 vcnt);

	//----------------------------------------------------------------------------------------
	/// @destructsAlloc{Polygon objects}
	/// @param[in,out] bl							@theToDestruct{Polygon object}
	//----------------------------------------------------------------------------------------
	static void Free(PolygonObject*& bl);

	/// @}

	/// @name Selected/Hidden Polygon/Edge
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets the selected polygons (visible ones only).
	/// @return												The selection of visible polygons. @theOwnsPointed{Polygon object,base select}
	//----------------------------------------------------------------------------------------
	BaseSelect* GetPolygonS(void);

	//----------------------------------------------------------------------------------------
	/// Gets the selected polygons (visible ones only).
	/// @return												The selection of visible polygons. @theOwnsPointed{Polygon object,base select}
	//----------------------------------------------------------------------------------------
	const BaseSelect* GetPolygonS(void) const;

	//----------------------------------------------------------------------------------------
	/// Gets the hidden polygons (hidden ones within the editor only).
	/// @return												The hidden polygons. @theOwnsPointed{Polygon object,base select}
	//----------------------------------------------------------------------------------------
	BaseSelect* GetPolygonH(void);

	//----------------------------------------------------------------------------------------
	/// Gets the hidden polygons (hidden ones within the editor only).
	/// @return												The hidden polygons. @theOwnsPointed{Polygon object,base select}
	//----------------------------------------------------------------------------------------
	const BaseSelect* GetPolygonH(void) const;

	//----------------------------------------------------------------------------------------
	/// Gets the selected edges (visible ones only).\n
	/// The edges are indexed by <tt>4 * polygon + edge</tt> where @c polygon is the polygon index and @c edge is the edge index between @em 0 and @em 3.
	/// @note	If the selection is changed make sure it is still valid, so that shared edges have a well-defined selection status.\n
	///				It is safer to use SetSelectedEdges().
	/// @return												The selection of visible edges. @theOwnsPointed{Polygon object,base select}
	/// @sa	GetSelectedEdges()\n
	///			SetSelectedEdges()
	//----------------------------------------------------------------------------------------
	EdgeBaseSelect* GetEdgeS(void);

	//----------------------------------------------------------------------------------------
	/// Gets the selected edges (visible ones only).\n
	/// The edges are indexed by <tt>4 * polygon + edge</tt> where @c polygon is the polygon index and @c edge is the edge index between @em 0 and @em 3.
	/// @note	If the selection is changed make sure it is still valid, so that shared edges have a well-defined selection status.\n
	///				It is safer to use SetSelectedEdges().
	/// @return												The selection of visible edges. @theOwnsPointed{Polygon object,base select}
	/// @sa	GetSelectedEdges()\n
	///			SetSelectedEdges()
	//----------------------------------------------------------------------------------------
	const EdgeBaseSelect* GetEdgeS(void) const;

	//----------------------------------------------------------------------------------------
	/// Gets the hidden edges (hidden ones within the editor only).\n
	/// The edges are indexed by <tt>4 * polygon + edge</tt> where @c polygon is the polygon index and @c edge is the edge index between @em 0 and @em 3.
	/// @note	If this selection is changed make sure it is still valid, so that shared edges have a well-defined selection status.\n
	///				It is safer to use SetSelectedEdges().
	/// @return												The hidden edges. @theOwnsPointed{Polygon object,base select}
	//----------------------------------------------------------------------------------------
	EdgeBaseSelect* GetEdgeH(void);

	//----------------------------------------------------------------------------------------
	/// Gets the hidden edges (hidden ones within the editor only).\n
	/// The edges are indexed by <tt>4 * polygon + edge</tt> where @c polygon is the polygon index and @c edge is the edge index between @em 0 and @em 3.
	/// @note	If this selection is changed make sure it is still valid, so that shared edges have a well-defined selection status.\n
	///				It is safer to use SetSelectedEdges().
	/// @return												The hidden edges. @theOwnsPointed{Polygon object,base select}
	//----------------------------------------------------------------------------------------
	const EdgeBaseSelect* GetEdgeH(void) const;

	//----------------------------------------------------------------------------------------
	/// Gets the Phong break edges.\n
	/// The edges are indexed by <tt>4 * polygon + edge</tt> where @c polygon is the polygon index and @c edge is the edge index between @em 0 and @em 3.
	/// @note	If the selection is changed make sure it is still valid, so that shared edges have a well-defined selection status.\n
	///				It is safer to use SetSelectedEdges().
	/// @return												The Phong break edges. @theOwnsPointed{Polygon object,base select}
	//----------------------------------------------------------------------------------------
	EdgeBaseSelect* GetPhongBreak(void);

	//----------------------------------------------------------------------------------------
	/// Gets the Phong break edges.\n
	/// The edges are indexed by <tt>4 * polygon + edge</tt> where @c polygon is the polygon index and @c edge is the edge index between @em 0 and @em 3.
	/// @note	If the selection is changed make sure it is still valid, so that shared edges have a well-defined selection status.\n
	///				It is safer to use SetSelectedEdges().
	/// @return												The Phong break edges. @theOwnsPointed{Polygon object,base select}
	//----------------------------------------------------------------------------------------
	const EdgeBaseSelect* GetPhongBreak(void) const;

	//----------------------------------------------------------------------------------------
	/// Gets the shading break edges based on neighbor polygons shading edges and a specified
	/// @since R19
	///
	/// Border edges can optionally be marked as break edges.
	/// Current break edges can optionally be included (merged) in the resulting break edges.
	///
	/// Finally, user normal vectors can optionally be considered using a separate angle limit for this purpose.
	/// 
	/// @note The edges are indexed by <tt>4 * polygon + edge</tt> where @c polygon is the polygon index and @c edge is the edge index between @em 0 and @em 3.
	/// @since R19
	/// @param[in] includeBorderEdges	@trueOtherwiseFalse{to mark border edges as break edges}
	/// @param[in] includeUserBreak		@trueOtherwiseFalse{to include the user break edges (same as obtained with GetPhongBreak)}
	/// @param[in] includeUserNormals	@trueOtherwiseFalse{to consider user normals using the userNormalAngle parameter}
	/// @param[in] userNormalsAngle		The angle limit in radians beyond which polygon vertex normals sharing edge vertices create a break edge.
	/// @param[in] autoNormalsAngle		The angle limit in radians beyond which polygon normals sharing an edge create a break edge.
	/// @return												The shading break edges. @theOwnsPointed{PolygonObject,BaseSelect}
	//----------------------------------------------------------------------------------------
	BaseSelect* GetShadingBreak(Bool includeBorderEdges, Bool includeUserBreak, Bool includeUserNormals, Float userNormalsAngle = DegToRad(5.0), Float autoNormalsAngle = DegToRad(180.0));

	/// @}

	/// @name Polygon
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets the start of the read-only array of polygons.
	/// @note While this function may sound trivial and cheap, internally it is not. For performance reasons, it is not recommended to use this function inside a loop or inside a loop condition.
	/// @return												The first element in the read-only polygon array. @theOwnsPointed{Polygon object,array}
	//----------------------------------------------------------------------------------------
	const CPolygon* GetPolygonR(void) const { return (const CPolygon*)GetTagDataR(Tpolygon); }

	//----------------------------------------------------------------------------------------
	/// Gets the start of the writable array of polygons.
	/// @note While this function may sound trivial and cheap, internally it is not. For performance reasons, it is not recommended to use this function inside a loop or inside a loop condition.
	/// @return												The first element in the writable polygon array. @theOwnsPointed{Polygon object,array}
	//----------------------------------------------------------------------------------------
	CPolygon* GetPolygonW(void) { return (CPolygon*)GetTagDataW(Tpolygon); }

	//----------------------------------------------------------------------------------------
	/// Gets the number of polygons in the object.
	/// @note While this function may sound trivial and cheap, internally it is not. For performance reasons, it is not recommended to use this function inside a loop or inside a loop condition.
	/// @return												The polygon count.
	//----------------------------------------------------------------------------------------
	Int32 GetPolygonCount(void) const { return GetTagDataCount(Tpolygon); }

	/// @}

	/// @name Resize Object
	/// @{

	//----------------------------------------------------------------------------------------
	/// Changes the number of points and polygons in the object.
	/// @param[in] pcnt								The new number of points.
	/// @param[in] vcnt								The new number of polygons.
	/// @return												@trueIfOtherwiseFalse{the number of points and polygons was changed successfully}
	//----------------------------------------------------------------------------------------
	Bool ResizeObject(Int32 pcnt, Int32 vcnt);

	//----------------------------------------------------------------------------------------
	/// Changes the number of points, polygons and N-gons in the object.
	/// @param[in] pcnt								The new number of points.
	/// @param[in] vcnt								The new number of polygons.
	/// @param[in] ncnt								The new number of N-gons.
	/// @return												@trueIfOtherwiseFalse{the number of points, polygons and N-gons was changed successfully}
	//----------------------------------------------------------------------------------------
	Bool ResizeObject(Int32 pcnt, Int32 vcnt, Int32 ncnt);

	//----------------------------------------------------------------------------------------
	/// Changes the number of points, polygons and N-gons in the object with variable changed flags.
	/// @param[in] pcnt								The new number of points.
	/// @param[in] vcnt								The new number of polygons.
	/// @param[in] ncnt								The new number of N-gons.
	/// @param[in] vc_flags						The variable changed flags: @enumerateEnum{VC_FLAGS}
	/// @return												@trueIfOtherwiseFalse{the number of points, polygons and N-gons was changed successfully}
	//----------------------------------------------------------------------------------------
	Bool ResizeObject(Int32 pcnt, Int32 vcnt, Int32 ncnt, Int32 vc_flags);

	/// @}

	/// @name Get/Set Edge Selection
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets the selected, hidden or phong break edges.\n
	/// The edges are indexed uniquely by a Neighbor object, so each edge has a single index.
	/// @note Convenience wrapper around GetEdgeS(), GetEdgeH() and GetPhongBreak().
	/// @warning The returned @ref BaseSelect* must be deleted with BaseSelect::Free() afterwards.
	/// @param[in] e									The neighbor object with information about the edge topology.\n
	/// 															Must be initialized with all polygons:
	/// 															@code
	/// 															Neighbor::Init(poly->GetPointCount(), poly->GetPolygonR(), poly->GetPolygonCount(), nullptr);
	/// 															@endcode
	/// @param[in] ltype							The type of edge selection to get: @enumerateEnum{EDGESELECTIONTYPE}
	/// @return												The selected edges. @callerOwnsPointed{base select}
	//----------------------------------------------------------------------------------------
	BaseSelect* GetSelectedEdges(Neighbor* e, EDGESELECTIONTYPE ltype);

	//----------------------------------------------------------------------------------------
	/// Converts a regular edge selection (<tt>4 * polygon + edge</tt>) to an edge selection that can be used with the PolyInfo::edge array.
	/// @warning The returned @ref BaseSelect* must be deleted with BaseSelect::Free() afterwards.
	/// @param[in] e									The neighbor object with information about the edge topology.\n
	/// 															Must be initialized with all polygons:
	/// 															@code
	/// 															Neighbor::Init(poly->GetPointCount(), poly->GetPolygonR(), poly->GetPolygonCount(), nullptr);
	/// 															@endcode
	/// @param[in] sel								The selection to convert. @callerOwnsPointed{base select}
	/// @return												The converted selection. @callerOwnsPointed{base select}
	//----------------------------------------------------------------------------------------
	BaseSelect* GetSelectedEdges(Neighbor* e, BaseSelect* sel);

	//----------------------------------------------------------------------------------------
	/// Sets the selected, hidden or phong break edges.\n
	/// The edges are indexed uniquely by a Neighbor object, so each edge has a single index.
	/// @note Convenience wrapper around GetEdgeS(), GetEdgeH() and GetPhongBreak().
	/// @param[in] e									The neighbor object with information about the edge topology.\n
	/// 															Must be initialized with all polygons:
	/// 															@code
	/// 															Neighbor::Init(poly->GetPointCount(), poly->GetPolygonR(), poly->GetPolygonCount(), nullptr);
	/// 															@endcode
	/// @param[in] pSel								The edge selection. @callerOwnsPointed{base select}
	/// @param[in] ltype							The type of edge selection to set: @enumerateEnum{EDGESELECTIONTYPE}
	/// @return												@trueIfOtherwiseFalse{the edge selection succeeded}
	//----------------------------------------------------------------------------------------
	Bool SetSelectedEdges(Neighbor* e, BaseSelect* pSel, EDGESELECTIONTYPE ltype);

	/// @}

	/// @name Phong Normals
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets an array with the stored Phong normals of the object.\n
	/// The array contains 4* GetPolygonCount() vectors, one for each point of each face (including the unused fourth point for triangles).
	/// @note Only valid if the object has a Phong tag.
	/// @warning The returned array has to be freed with DeleteMem() afterwards.
	/// @return												The Phong normals. @callerOwnsPointed{array}
	//----------------------------------------------------------------------------------------
	Vector32* CreatePhongNormals();

	/// @}

	/// @name N-gon
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets a translation map from polygon indices to N-gon indices.\n
	/// If <tt>polymap[i] = p</tt> then polygon @c i is part of the N-gon @c p.
	/// @warning @formatParam{polymap} needs to be freed with DeleteMem() afterwards.
	/// @param[in,out] ngoncnt				Assigned the number of N-gons.\n
	/// 															This is not the same value as returned by GetNgonCount(). @formatParam{ngoncnt} includes all regular polygons as well.
	/// @param[in,out] polymap				Assigned a pointer to the N-gon index map. @callerOwnsPointed{array}
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool GetPolygonTranslationMap(Int32& ngoncnt, Int32*& polymap);

	//----------------------------------------------------------------------------------------
	/// Gets a translation map from N-gon indices to polygon indices.\n
	/// The number of polygons in N-gon i is stored in <tt>ngons[i][0]</tt>. Then the polygon indices are stored in <tt>ngons[i][j]</tt> where @c j goes from @em 1 to <tt>ngons[i][0]</tt>.
	/// @warning @formatParam{ngons} map needs to be freed with DeleteMem() afterwards.
	/// @param[in,out] ngoncnt				The number of N-gons. Use the value returned by GetPolygonTranslationMap(), not GetNgonCount().
	/// @param[in,out] polymap				The polygon map. Use the map returned by GetPolygonTranslationMap(), or a similarly formatted array. @callerOwnsPointed{array}
	/// @param[in,out] ngons					Assigned a pointer to the polygon index map. @callerOwnsPointed{array}
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool GetNGonTranslationMap(Int32 ngoncnt, Int32* polymap, Int32**& ngons);

	//----------------------------------------------------------------------------------------
	/// Gets the start of the array of N-gons.
	/// @return												The N-gon array. @theOwnsPointed{Polygon object,array}
	//----------------------------------------------------------------------------------------
	Pgon* GetAndBuildNgon(void);

	//----------------------------------------------------------------------------------------
	/// Gets the number of N-gons in the object, i.e. the number of polygons with more points than @em 4.
	/// @return												The number of N-gons.
	//----------------------------------------------------------------------------------------
	Int32 GetNgonCount(void);

	//----------------------------------------------------------------------------------------
	/// Gets the current N-gon selection.\n
	/// It has the same order as the GetNGonTranslationMap().
	/// @param[out] sel								Assigned the current N-gon selection.
	//----------------------------------------------------------------------------------------
	void GetSelectedNgons(BaseSelect* sel);

	//----------------------------------------------------------------------------------------
	/// Gets the current hidden N-gon selection.\n
	/// It has the same order as GetNGonTranslationMap().
	/// @param[out] sel								Assigned the current hidden N-gon selection.
	//----------------------------------------------------------------------------------------
	void GetHiddenNgons(BaseSelect* sel);

	//----------------------------------------------------------------------------------------
	/// Gets the NgonBase instance for the object.
	/// @return												The N-gon base. @theOwnsPointed{Polygon object,NgonBase}
	//----------------------------------------------------------------------------------------
	NgonBase* GetNgonBase();

	//----------------------------------------------------------------------------------------
	/// Deselects all selected edges in @formatParam{sel} that are N-gon edges.
	/// @param[in] sel								The selection to check for N-gon edges. @callerOwnsPointed{BaseSelect}
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool ValidateEdgeSelection(BaseSelect* sel);

	//----------------------------------------------------------------------------------------
	/// Deselects all selected edges that are N-gon edges.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool ValidateEdgeSelection();

	//----------------------------------------------------------------------------------------
	/// Deselects all edges in @formatParam{sel} that are N-gon edges as specified by type.
	/// @param[in] sel								The selection to check for N-gon edges. @callerOwnsPointed{BaseSelect}
	/// @param[in] type								The type of selection to check: @enumerateEnum{EDGESELECTIONTYPE}
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool GetEdgeSelection(BaseSelect* sel, EDGESELECTIONTYPE type);

	//----------------------------------------------------------------------------------------
	/// Retrieves an array that contains N-gon information for each polygon.\n
	/// If <tt>edges[poly_index] & (1 << edge_index) != 0</tt> the edge is a hidden N-gon edge, where @c edge_index is between @em 0 - @em 3 for quads and @em 0, @em 1 or @em 3 for triangles.
	/// @warning @formatParam{edges} array needs to be freed with DeleteMem() afterwards.
	/// @param[out] edges							Assigned a pointer to the compact N-gon edges array. @callerOwnsPointed{array}
	//----------------------------------------------------------------------------------------
	void GetNgonEdgesCompact(UChar*& edges);

	/// @}
};


//----------------------------------------------------------------------------------------
/// Helper class to obtain the length of splines and the natural position along their path.
/// @addAllocFreeAutoAllocNote
//----------------------------------------------------------------------------------------
class SplineLengthData
{
private:
	SplineLengthData();
	~SplineLengthData();

public:
	/// @name Alloc/Free
	/// @{

	//----------------------------------------------------------------------------------------
	/// @allocatesA{spline length data}
	/// @return												@allocReturn{spline length data}
	//----------------------------------------------------------------------------------------
	static SplineLengthData* Alloc();

	//----------------------------------------------------------------------------------------
	/// @destructsAlloc{spline length data}
	/// @param[in,out] bl							@theToDestruct{spline length data}
	//----------------------------------------------------------------------------------------
	static void Free(SplineLengthData*& bl);

	/// @}

	//----------------------------------------------------------------------------------------
	/// Initializes the spline length data.
	/// @warning Must be called before using UniformToNatural(), GetLength() and GetSegmentLength.
	/// @note Cannot be used on spline primitives. Call BaseObject::GetRealSpline() to get a real spline first.
	/// @param[in] op									The spline object to initialize. @callerOwnsPointed{spline object}
	/// @param[in] segment						The segment to use. Decides what spline segment the calculations in SplineLengthData methods will be performed on.
	/// @param[in] padr								For speedup purposes pass a pointer to start of the specified segment in the point array. Otherwise the spline has to search its array manually.
	/// @return												@trueIfOtherwiseFalse{the spline length data was initialized successfully}
	//----------------------------------------------------------------------------------------
	Bool Init(SplineObject* op, Int32 segment = 0, const Vector* padr = nullptr);

	//----------------------------------------------------------------------------------------
	/// Gets the natural position along the spline, to be used in SplineObject::GetSplinePoint() and SplineObject::GetSplineTangent(), from a uniform position.\n
	/// The uniform position is with respect to the actual length of the spline, where the natural position only cares about the interpolation of the curve parameter.
	/// @warning Call Init() before using this method.
	/// @param[in] t									The uniform position along the spline.
	/// @return												The natural position in the segment.
	//----------------------------------------------------------------------------------------
	Float UniformToNatural(Float t);

	//----------------------------------------------------------------------------------------
	/// Gets the length of the spline.
	/// @warning Call Init() before using this method.
	/// @return												The length of the spline.
	//----------------------------------------------------------------------------------------
	Float GetLength(void);

	//----------------------------------------------------------------------------------------
	/// Gets the length of a segment.
	/// @warning Call Init() before using this method.
	/// @param[in] a									Start segment.
	/// @param[in] b									End segment.
	/// @return												The segment length.
	//----------------------------------------------------------------------------------------
	Float GetSegmentLength(Int32 a, Int32 b);
};


//----------------------------------------------------------------------------------------
/// Represents a spline object.
//----------------------------------------------------------------------------------------
class SplineObject : public PointObject
{
private:
	SplineObject();
	~SplineObject();

public:
	/// @name Alloc/Free
	/// @{

	//----------------------------------------------------------------------------------------
	/// @allocatesA{Spline object}
	/// @param[in] pcnt								The point count.
	/// @param[in] type								The spline type: @enumerateEnum{SPLINETYPE}
	/// @return												@allocReturn{Spline object}
	//----------------------------------------------------------------------------------------
	static SplineObject* Alloc(Int32 pcnt, SPLINETYPE type);

	//----------------------------------------------------------------------------------------
	/// @destructsAlloc{Spline objects}
	/// @param[in,out] bl							@theToDestruct{Spline object}
	//----------------------------------------------------------------------------------------
	static void Free(SplineObject*& bl);

	/// @}

	/// @name Spline Point/Tangent
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets the spline point at a position along the given segment.
	/// @param[in] t									The position @em 0.0 <= @formatParam{t} <= @em 1.0 along the segment.\n
	/// 															The positioning is natural, for example @formatParam{t} = @em 0.5 is not necessarily at half the length. Use SplineLengthData::UniformToNatural() to get a uniform distribution.
	/// @param[in] segment						The segment to get the point in.
	/// @param[in] padr								For speedup purposes pass a pointer to the start of the specified @formatParam{segment} in the point array. Otherwise the spline has to search its array manually.
	/// @return												The spline point.
	//----------------------------------------------------------------------------------------
	Vector GetSplinePoint(Float t, Int32 segment = 0, const Vector* padr = nullptr);

	//----------------------------------------------------------------------------------------
	/// Gets the tangent of a spline at a position along the given segment.
	/// @param[in] t									The position @em 0.0 <= @formatParam{t} <= @em 1.0 along the segment.\n
	/// 															The positioning is natural, for example @formatParam{t} = @em 0.5 is not necessarily at half the length. Use SplineLengthData::UniformToNatural() to get a uniform distribution.
	/// @param[in] segment						The segment to get the point in.
	/// @param[in] padr								For speedup purposes pass a pointer to the start of the specified @formatParam{segment} in the point array. Otherwise the spline has to search its array manually.
	/// @return												The spline tangent.
	//----------------------------------------------------------------------------------------
	Vector GetSplineTangent(Float t, Int32 segment = 0, const Vector* padr = nullptr);

	/// @}

	/// @name Segment
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets the first element in the read-only segments array.
	/// @return												The read-only segment array address. @theOwnsPointed{Spline object,array}
	//----------------------------------------------------------------------------------------
	const Segment* GetSegmentR(void) { return (const Segment*)GetTagDataR(Tsegment); }

	//----------------------------------------------------------------------------------------
	/// Gets the first element in the writable segments array.
	/// @return												The writable segment array address. @theOwnsPointed{Spline object,array}
	//----------------------------------------------------------------------------------------
	Segment* GetSegmentW(void) { return (Segment*)GetTagDataW(Tsegment); }

	//----------------------------------------------------------------------------------------
	/// Gets the number of segments.
	/// @return												The segment count.
	//----------------------------------------------------------------------------------------
	Int32 GetSegmentCount(void) { return GetTagDataCount(Tsegment); }

	/// @}

	/// @name Tangent
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets the first element in the read-only tangents array.
	/// @return												The read-only tangent array address. @theOwnsPointed{Spline object,array}
	//----------------------------------------------------------------------------------------
	const Tangent* GetTangentR(void) { return (Tangent*)GetTagDataR(Ttangent); }

	//----------------------------------------------------------------------------------------
	/// Gets the first element in the writable tangents array.
	/// @return												The writable tangent array address. @theOwnsPointed{Spline object,array}
	//----------------------------------------------------------------------------------------
	Tangent* GetTangentW(void) { return (Tangent*)GetTagDataW(Ttangent); }

	//----------------------------------------------------------------------------------------
	/// Gets the number of tangents.
	/// @return												The tangent count.
	//----------------------------------------------------------------------------------------
	Int32 GetTangentCount(void) { return GetTagDataCount(Ttangent); }

	/// @}

	/// @name Miscellaneous
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets the interpolation type of the spline.
	/// @return												The interpolation type: @enumerateEnum{SPLINETYPE}
	//----------------------------------------------------------------------------------------
	SPLINETYPE GetInterpolationType(void) const;

	//----------------------------------------------------------------------------------------
	/// Gets a line based object from the spline.
	/// @param[in] doc								The document containing the spline object. @callerOwnsPointed{document}
	/// @param[in] lod								The level of detail to create the line.
	/// @param[in] thread							A thread to check for a break or @formatConstant{nullptr}. @callerOwnsPointed{thread}
	/// @return												A line based representation of the spline. @callerOwnsPointed{Line object}
	//----------------------------------------------------------------------------------------
	LineObject* GetLineObject(BaseDocument* doc, Float lod, BaseThread* thread = nullptr);

	//----------------------------------------------------------------------------------------
	/// Checks if the spline is closed.
	/// @return												@trueIfOtherwiseFalse{the spline is closed.}
	//----------------------------------------------------------------------------------------
	Bool IsClosed(void);

	//----------------------------------------------------------------------------------------
	/// Changes the number of segments and points for the spline.
	/// @param[in] pcnt								The new point count.
	/// @param[in] scnt								The new segment count.
	/// @return												@trueIfOtherwiseFalse{the number of points and segments was changed successfully}
	//----------------------------------------------------------------------------------------
	Bool ResizeObject(Int32 pcnt, Int32 scnt);

	//----------------------------------------------------------------------------------------
	/// Initializes the spline with default coefficients.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool SetDefaultCoeff(void);

	/// @}
};

//----------------------------------------------------------------------------------------
/// Creates a built-in @C4D primitive objects.
/// @param[in] doc								The document for the primitive object. @callerOwnsPointed{document}
/// @param[in] type								The primitive type: @enumerateEnum{PrimitiveTypes}
/// @param[in] bc									The settings for the primitive.
/// @param[in] lod								The level of detail to use for the primitive.
/// @param[in] isoparm						Pass @formatConstant{true} to create a isoparm of the object.
/// @param[in] bt									The thread to test for a break or @formatConstant{nullptr}. @callerOwnsPointed{thread}
/// @return												The primitive object or @formatConstant{nullptr} if failed. @callerOwnsPointed{object}
//----------------------------------------------------------------------------------------
BaseObject* GeneratePrimitive(BaseDocument* doc, Int32 type, const BaseContainer& bc, Float lod, Bool isoparm, BaseThread* bt = nullptr);

//----------------------------------------------------------------------------------------
/// Creates a built-in @C4D primitive spline objects.
/// @param[in] doc								The document for the spline primitive object. @callerOwnsPointed{document}
/// @param[in] type								The spline primitive type: @enumerateEnum{SplinePrimitiveTypes}
/// @param[in] bc									The settings for the spline primitive.
/// @param[in] lod								The level of detail to use for the primitive.
/// @param[in] bt									The thread to test for a break or @formatConstant{nullptr}. @callerOwnsPointed{thread}
/// @return												The primitive spline object or @formatConstant{nullptr} if failed. @callerOwnsPointed{object}
//----------------------------------------------------------------------------------------
BaseObject* GenerateSplinePrimitive(BaseDocument* doc, Int32 type, const BaseContainer& bc, Float lod, BaseThread* bt = nullptr);

/// Casts a @ref BaseObject* to a @ref PointObject*.
#define ToPoint(op) ((PointObject*)(op))

/// Casts a @ref BaseObject* to a @ref PolygonObject*.
#define ToPoly(op) ((PolygonObject*)(op))

/// Casts a @ref BaseObject* to a @ref SplineObject*.
#define ToSpline(op) ((SplineObject*)(op))

//----------------------------------------------------------------------------------------
/// Calculates the normal of a polygon.
/// @param[in] padr								The points array.
/// @param[in] v									The polygon.
/// @return												The face's normal.
//----------------------------------------------------------------------------------------
inline Vector CalcFaceNormal(const Vector* padr, const CPolygon& v)
{
	if (v.c == v.d)
		return !Cross((padr[v.b] - padr[v.a]), (padr[v.c] - padr[v.a]));
	else
		return !Cross((padr[v.b] - padr[v.d]), (padr[v.c] - padr[v.a]));
}


//----------------------------------------------------------------------------------------
/// Class to enable safe modification of objects under low memory conditions such that any failure can restore the object to its original form.
/// @note Only backups tags (which includes points, polygons etc.).
//----------------------------------------------------------------------------------------
class Safety
{
private:
	ObjectSafety* os;

public:
	//----------------------------------------------------------------------------------------
	/// Default constructor.
	//----------------------------------------------------------------------------------------
	Safety();

	//----------------------------------------------------------------------------------------
	/// Default destructor.
	//----------------------------------------------------------------------------------------
	~Safety();

	//----------------------------------------------------------------------------------------
	/// Initializes the object ready for modification.
	/// @param[in] op									The object that is about to be changed. @callerOwnsPointed{object}
	/// @return												@trueIfOtherwiseFalse{the class was initialized successfully and is ready for the object changes}
	/// 															If @formatConstant{false} then the operation should be terminated.
	//----------------------------------------------------------------------------------------
	Bool Init(BaseObject* op);

	//----------------------------------------------------------------------------------------
	/// Releases the object from the class when modification is complete.
	/// @note	If not called the class will restore the original state when it is destructed.\n
	///				To keep the changes call Detach() before stack deconstruction of private member @ref os.
	//----------------------------------------------------------------------------------------
	void Detach(void);
};


//----------------------------------------------------------------------------------------
/// Helper function to modify a user chosen subdivision value.\n
/// @b Example:
/// @code
/// Int32 sub = CalcLOD(data.GetInt32(TUBEOBJECT_SUB, 1), hh->GetLOD(), 1, 1000);
/// @endcode
/// @param[in] val								The user chosen LOD value.
/// @param[in] lod								The LOD value, from BaseDocument::GetLOD().
/// @param[in] min								The minimum LOD.
/// @param[in] max								The maximum LOD.
/// @return												The level of detail.
//----------------------------------------------------------------------------------------
Int32 CalcLOD(Int32 val, Float lod, Int32 min, Int32 max);

//----------------------------------------------------------------------------------------
/// Separates the mesh of the object to make each polygon/line segment independent.\n
/// Each polygon/line will be given its own points thereby separating them so they can be moved independently, such as the Explosion object.
/// @param[in] op									The Point object to disjoint. @callerOwnsPointed{Point object}
/// @return												@trueIfOtherwiseFalse{the mesh was disjointed successfully}
//----------------------------------------------------------------------------------------
Bool DisjointMesh(PointObject* op);

//----------------------------------------------------------------------------------------
/// Creates a Spline object that has the best fit through the given points.
/// @param[in] padr								The points to fit a curve to. @callerOwnsPointed{array}
/// @param[in] pcnt								The number of points in the point array @formatParam{padr}.
/// @param[in] error							Sets how closely the curve must match the passed points. The range for this is @em 0 to @ref MAXRANGE. The lower the value then the closer the curve will match.
/// @param[in] bt									The current thread, or @formatConstant{nullptr} for the main @C4D thread. @callerOwnsPointed{thread}
/// @return												A Spline object that fits the given points, or @formatConstant{nullptr} if failed. @callerOwnsPointed{Spline object}
//----------------------------------------------------------------------------------------
SplineObject* FitCurve(Vector* padr, Int32 pcnt, Float error, BaseThread* bt);

//----------------------------------------------------------------------------------------
/// Turns the polygon mesh into triangles.
/// @param[in] padr								The points of the object to triangulate. @callerOwnsPointed{array}
/// @param[in] pcnt								The number of points in the points array @formatParam{padr}.
/// @param[out] vadr							The polygons for the object. Assigned the triangulated polygons. @callerOwnsPointed{array}\n
/// 															Can be assigned @formatConstant{nullptr}, always check.
/// @param[out] vcnt							Assigned the triangulated count i.e. the number of polygons in the returned polygons array @formatParam{vadr}.
/// @return												@trueIfOtherwiseFalse{turning the polygons into triangles was successful}
//----------------------------------------------------------------------------------------
Bool Triangulate(const Vector* padr, Int32 pcnt, CPolygon** vadr, Int32* vcnt);

//----------------------------------------------------------------------------------------
/// Triangulates the spline described by (@formatParam{padr},@formatParam{pcnt}) and (@formatParam{list},@formatParam{lcnt}) returning the result in (@formatParam{vadr},@formatParam{vcnt}).
/// @warning The returned data @formatParam{vadr} must be freed with DeleteMem()
/// @param[in] padr								The input points. @callerOwnsPointed{array}
/// @param[in] pcnt								The number of input points in @formatParam{padr}.
/// @param[in] list								The input segments. A list with a ::Int32 for each segment, telling its length within the point array @formatParam{padr}. @callerOwnsPointed{array}
/// @param[in] lcnt								The number of input segments in @formatParam{list}.
/// @param[out] vadr							Assigned the output polygon array. @callerOwnsPointed{array}
/// @param[out] vcnt							The number of polygons in @formatParam{vadr}.
/// @param[in] thread							The current thread, or @formatConstant{nullptr} for the main @C4D thread. @callerOwnsPointed{thread}
/// @return												@trueIfOtherwiseFalse{the spline was triangulated successfully}
//----------------------------------------------------------------------------------------
Bool TriangulateStandard(const Vector* padr, Int32 pcnt, Int32* list, Int32 lcnt, CPolygon*& vadr, Int32& vcnt, BaseThread* thread);

//----------------------------------------------------------------------------------------
/// Triangulates the spline described by (@formatParam{pinp},@formatParam{pinp_cnt}) and (@formatParam{list},@formatParam{lcnt}) returning the result in (@formatParam{padr},@formatParam{pcnt}) and (@formatParam{vadr},@formatParam{vcnt}). Generates new points in a regular mesh specified by @formatParam{regular_width}.
/// @warning The returned data (@formatParam{padr},@formatParam{vadr}) must be freed with DeleteMem().
/// @param[in] pinp								The input points. @callerOwnsPointed{array}
/// @param[in] pinp_cnt						The number of input points in @formatParam{pinp}.
/// @param[in] list								The input segments. A list with a ::Int32 for each segment, telling its length within the point array @formatParam{padr}. @callerOwnsPointed{array}
/// @param[in] lcnt								The number of input segments in @formatParam{list}.
/// @param[out] padr							Assigned the output point array. @callerOwnsPointed{array}
/// @param[out] pcnt							The number of output points in @formatParam{padr}.
/// @param[out] vadr							Assigned the output polygon array. @callerOwnsPointed{array}
/// @param[out] vcnt							The number of output polygons in @formatParam{vadr}.
/// @param[in] regular_width			The width of the regular mesh.
/// @param[in] thread							The current thread, or @formatConstant{nullptr} for the main @C4D thread. @callerOwnsPointed{thread}
/// @return												@trueIfOtherwiseFalse{the spline was triangulated successfully}
//----------------------------------------------------------------------------------------
Bool TriangulateRegular(const Vector* pinp, Int32 pinp_cnt, Int32* list, Int32 lcnt, Vector*& padr, Int32& pcnt, CPolygon*& vadr, Int32& vcnt, Float regular_width, BaseThread* thread);

//----------------------------------------------------------------------------------------
/// Creates a text object.
/// @param[in] cp									The container with settings for the text object.
/// @param[in] bt									The current thread, or @formatConstant{nullptr} for the main @C4D thread. @callerOwnsPointed{thread}
/// @param[in] separate						@trueIfOtherwiseFalse{the letters should be separate}
/// @return												The created text object or @formatConstant{nullptr} if failed. @callerOwnsPointed{object}
//----------------------------------------------------------------------------------------
BaseObject* GenerateText(BaseContainer* cp, BaseThread* bt, Bool separate);

//----------------------------------------------------------------------------------------
/// Checks if an object is covered by a display filter.\n
/// @b Example:
/// @code
/// BaseDraw* bd = doc->GetActiveBaseDraw();
///
/// // Get the BaseDraw's display filter
/// DISPLAYFILTER filter = bd->GetDisplayFilter();
///
/// if (CheckDisplayFilter(op, filter))
/// {
/// 	// Use object
/// }
/// @endcode
/// @param[in] op									The object to check. @callerOwnsPointed{object}
/// @param[in] filter							The filter bitmask: @enumerateEnum{DISPLAYFILTER}
/// @return												@trueIfOtherwiseFalse{the object is included in a display filter}
//----------------------------------------------------------------------------------------
Bool CheckDisplayFilter(BaseObject* op, DISPLAYFILTER filter);


//----------------------------------------------------------------------------------------
/// Checks if an object is visible in the viewport including evaluation of parent hierarchies and layers. Combine with CheckDisplayFilter() to get the visibility in a certain BaseDraw.
/// @since R16.050
/// @param[in] op									The object to check.
/// @return												@trueIfOtherwiseFalse{the object state is visible}
//----------------------------------------------------------------------------------------
Bool CheckEditorVisibility(BaseObject* op);

//----------------------------------------------------------------------------------------
/// Checks for a polygon intersection at position (@formatParam{x}/@formatParam{y}) in the view @formatParam{bd} with object @formatParam{op} and global matrix @formatParam{mg}.\n
/// The resulting Z depth is assigned to @formatParam{z}.\n
/// @param[in] op									The polygon object to check. @callerOwnsPointed{polygon object}
/// @param[in] bd									The base draw to check the intersection in. @callerOwnsPointed{base draw}
/// @param[in] x									The X coordinate to check.
/// @param[in] y									The Y coordinate to check.
/// @param[in] mg									The global matrix of the object.
/// @param[out] z									Assigned the Z coordinate of the intersection if found.
/// @param[in] mode								The intersection mode: @enumerateEnum{MODELINGCOMMANDMODE}
/// 															- If @ref MODELINGCOMMANDMODE::POLYGONSELECTION only the selected polygons will be checked.
/// 															- If @ref MODELINGCOMMANDMODE::POINTSELECTION only the polygons with at least one selected point in the passed array @formatParam{pPointselect} will be checked.
/// 															- If @ref MODELINGCOMMANDMODE::ALL everything will be checked.
/// @param[in] pPointSelect				An optional point selection. @callerOwnsPointed{array}
/// @param[in] lSelectCount				The number of points in @formatParam{pPointselect}.
/// @return												The intersection result.
//----------------------------------------------------------------------------------------
Int32 IntersectionTest(PolygonObject* op, BaseDraw* bd, Float x, Float y, const Matrix& mg, Float* z, MODELINGCOMMANDMODE mode, UChar* pPointSelect, Int32 lSelectCount);

//----------------------------------------------------------------------------------------
/// Computes the color of a light source.
/// @markPrivate
//----------------------------------------------------------------------------------------
Vector ComputeLightColor(BaseObject *op, Bool editor, Float reference);

//----------------------------------------------------------------------------------------
/// Holds polygon neighboring information.
/// @see Neighbor::GetPolyInfo
///
/// @b Example:<br>
/// The following code browses through all available edges:
/// @code
///	if (pObj->GetType() != Opolygon)
///		return;
///
///	PolygonObject* pPolyObj = ToPoly(pObj);
///	if (pPolyObj == nullptr)
///		return;
///
///	Neighbor neighbor;
///	const CPolygon* pPolyR = pPolyObj->GetPolygonR();
///	Int32 pointCount = pPolyObj->GetPointCount();
///	Int32 polyCount = pPolyObj->GetPolygonCount();
///
///	if (pPolyR == nullptr)
///		return;
///
///	if (!neighbor.Init(pointCount, pPolyR, polyCount, nullptr))
///		return;
///
///	for (Int32 polyIdx = 0; polyIdx < polyCount; polyIdx++)
///	{
///		PolyInfo* polyInfo = neighbor.GetPolyInfo(polyIdx);
///
///		for (Int32 edgeIdx = 0; edgeIdx < 4; edgeIdx++) // Test all 4 edges of a polygon
///		{
///			// Only proceed if the edge has not already been processed and edge really exists
///			// For triangles edge 2 from c.......d does not exist as c == d
///			// One can also skip the edgeIdx == 2 && pPolyR[polyIdx].c == pPolyR[polyIdx].d test as polyInfo->mark[2] is always true for triangles
///			if (polyInfo->mark[edgeIdx] || (edgeIdx == 2 && pPolyR[polyIdx].c == pPolyR[polyIdx].d))
///				continue;
///
///			Int32 edgeA = -1, edgeB = -1;
///
///			switch (edgeIdx)
///			{
///				case 0: edgeA = pPolyR[polyIdx].a; edgeB = pPolyR[polyIdx].b; break;
///				case 1: edgeA = pPolyR[polyIdx].b; edgeB = pPolyR[polyIdx].c; break;
///				case 2: edgeA = pPolyR[polyIdx].c; edgeB = pPolyR[polyIdx].d; break;
///				case 3: edgeA = pPolyR[polyIdx].d; edgeB = pPolyR[polyIdx].a; break;
///			}
///
///			GePrint("Triangle " + String::IntToString(polyIdx));
///			GePrint("Edge" + String::IntToString(edgeA) + " ------------ " + String::IntToString(edgeB));
///
///			// Do something with the edge a.......b
///		}
///	}
/// @endcode
//----------------------------------------------------------------------------------------
struct PolyInfo
{
	Int32 face[4];	///< The neighboring polygons. @note If @ref NOTOK it then means there is no neighbor.
	Int32 edge[4];	///< The edges of the polygon.
	Char mark[4];		///< @formatConstant{false} if that polygon "generated" an edge.\n
									///< For example think of 2 polygons that share an edge, one has set @ref mark = @formatConstant{false} for the edge because it was the first and "built" the edge and the other(s) will set mark = @formatConstant{true} as no new edge had to be generated.
};

//----------------------------------------------------------------------------------------
/// N-gon neighbor data for the Neighbor class.
/// @see Neighbor
//----------------------------------------------------------------------------------------
struct NgonNeighbor
{
	//----------------------------------------------------------------------------------------
	/// N-gon segment data for the NgonNeighbor class.
	/// @see Neighbor
	//----------------------------------------------------------------------------------------
	struct NgonNeighborSegment
	{
		Int32 ptcnt;			///< Number of points in the segment.
		Int32* pts;				///< Points array.
		Int32* edges;			///< Edges array.
		Int32* nbr;				///< %Neighbor polygons.
	};
	Int32								 segcnt;				///< Number of segments (always >= @em 1).
	NgonNeighborSegment* segments;			///< Segments array (always != @formatConstant{nullptr}).
};

//----------------------------------------------------------------------------------------
/// Helper class to get neighboring polygons from edges and points:
/// - To get point->poly connections use GetPointPolys().
/// - To get point->oneRingPoints connections use GetPointOneRingPoints(). (Available since R19.)
/// - To get edge->poly connections use GetEdgePolys().
/// - To get poly->edge connections use GetPolyInfo(), which additionally allows to retrieve neighbor polygons directly.
///
/// @note	This class assumes that the geometry is clean such that an edge is only shared by two polygons.\n
///				If this is not the case then the information may not be correct.
/// @warning	The polygon array passed to Init() must not be modified during the use of the class.\n
///						For example, if a polygon object is resized or its polygons modified the class may crash if it is used afterwards.
//----------------------------------------------------------------------------------------
class Neighbor
{
private:
	EnumerateEdges* ee;

public:
	/// @name Constructor/Destructor
	/// @{

	//----------------------------------------------------------------------------------------
	/// Default constructor.
	//----------------------------------------------------------------------------------------
	Neighbor();

	//----------------------------------------------------------------------------------------
	/// Default destructor.
	//----------------------------------------------------------------------------------------
	virtual ~Neighbor();

	/// @}

	/// @name Init
	/// @{

	//----------------------------------------------------------------------------------------
	/// Initializes the internal polygon information.
	/// @warning Must be called before the class can be used to get the neighboring polygons.
	/// @param[in] pcnt								The total number of points from the polygon object. This can be obtained calling PointObject::GetPointCount().
	/// @param[in] vadr								Pointer to the polygons array. This can be obtained calling PolygonObject::GetPolygonR(). @callerOwnsPointed{polygons array}
	/// @param[in] vcnt								The total number of polygons in the polygons array. This can be obtained calling PolygonObject::GetPolygonCount().
	/// @param[in] bs									Pointer to the polygon selection used to build the neighbor information. Set @formatConstant{nullptr} to use all polygons. @callerOwnsPointed{base select}
	/// @return												@trueIfOtherwiseFalse{the initialization was successful}
	//----------------------------------------------------------------------------------------
	virtual Bool Init(Int32 pcnt, const CPolygon* vadr, Int32 vcnt, BaseSelect* bs);

	/// @}

	/// @name Get Neighbor Information
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets the polygons that neighbor the given edge.
	/// @param[in] a									The point index that defines the first edge point.
	/// @param[in] b									The point index that defines the second edge point.
	/// @param[in] first							Assigned the first polygon index associated with the edge.
	/// @param[in] second							Assigned the second polygon index associated with the edge.
	//----------------------------------------------------------------------------------------
	void GetEdgePolys(Int32 a, Int32 b, Int32* first, Int32* second) { C4DOS.Nb->GetEdgePolys(ee, a, b, first, second); }

	//----------------------------------------------------------------------------------------
	/// Gets the polygons that are attached to the given point.
	/// @note No memory allocation/freeing is necessary.
	///
	/// @b Example:<br>
	/// To get the polygons around say point @em 137 we would use:
	/// @code
	/// Int32 *dadr = nullptr, dcnt = 0, poly;
	/// neighbor.GetPointPolys(137, &dadr, &dcnt);
	///
	/// for (Int32 i=0; i<dcnt; i++)
	/// {
	/// 	poly = dadr[i];
	///
	/// 	// Do something
	/// }
	/// @endcode
	/// @param[in] pnt								The point index to use to find the associated polygons.
	/// @param[in] dadr								Assigned the address of the returned polygon array.
	/// @param[in] dcnt								Assigned the number of polygons returned in the array @formatParam{daddr}.
	//----------------------------------------------------------------------------------------
	void GetPointPolys(Int32 pnt, Int32** dadr, Int32* dcnt) { C4DOS.Nb->GetPointPolys(ee, pnt, dadr, dcnt); }

	//----------------------------------------------------------------------------------------
	/// Gets the points that are attached through one edge to the given point.
	/// @since R19
	/// @note No memory allocation/freeing is necessary.
	///
	/// @b Example:<br>
	/// To get the points around say point @em 137 we would use:
	/// @code
	/// Int32 *dadr = nullptr, dcnt = 0, poly;
	/// neighbor.GetPointOneRingPoints(137, &dadr, &dcnt);
	///
	/// for (Int32 i=0; i<dcnt; i++)
	/// {
	/// 	pointIndex = dadr[i];
	///
	/// 	// Do something
	/// }
	/// @endcode
	/// @param[in] pnt								The point index to use to find the associated one ring points.
	/// @param[in] dadr								Assigned the address of the returned points array. @callerOwnsPointed{points array}
	/// @param[in] dcnt								Assigned the number of points returned in @formatParam{daddr}.
	//----------------------------------------------------------------------------------------
	void GetPointOneRingPoints(Int32 pnt, Int32** dadr, Int32* dcnt) { C4DOS.Nb->GetPointOneRingPoints(ee, pnt, dadr, dcnt); }

	//----------------------------------------------------------------------------------------
	/// Gets the total number of edges found.
	/// @return												The number of edges in the given polygons in Init().
	//----------------------------------------------------------------------------------------
	Int32 GetEdgeCount(void);

	//----------------------------------------------------------------------------------------
	/// Gets neighbor information about the given polygon.
	/// @param[in] poly								The polygon index to get the neighbor information for.
	/// @return												The neighbor information. @theOwnsPointed{neighbor object,polygon information}
	//----------------------------------------------------------------------------------------
	PolyInfo* GetPolyInfo(Int32 poly) { return C4DOS.Nb->GetPolyInfo(ee, poly); }

	//----------------------------------------------------------------------------------------
	/// Gets the polygon opposite to @formatParam{poly} with respect to the edge from point @formatParam{a} to @formatParam{b}.
	/// @param[in] a									The point index that defines the first edge point.
	/// @param[in] b									The point index that defines the second edge point.
	/// @param[in] poly								The index of the polygon to get the polygon opposite to.
	/// @return												The opposite polygon index, or if formatParam{poly} is not one of the edge polygons, or @ref NOTOK if none exists.
	//----------------------------------------------------------------------------------------
	Int32 GetNeighbor(Int32 a, Int32 b, Int32 poly);

	//----------------------------------------------------------------------------------------
	/// Gets the N-gon neighbors.
	/// @param[in] op									The polygon object. @callerOwnsPointed{polygon object}
	/// @param[out] ngoncnt						Assigned the N-gon count.
	/// @param[out] ngons							Assigned a pointer to the N-gon neighbor information.\n
	/// 															Free the array afterwards with DeleteMem() (not the segments, points, edges or neighbor members).
	/// @return												@trueIfOtherwiseFalse{the N-gon neighbors were successfully retrieved}
	//----------------------------------------------------------------------------------------
	Bool GetNGons(PolygonObject* op, Int32& ngoncnt, NgonNeighbor*& ngons) { return C4DOS.Nb->GetNGons(ee, op, ngoncnt, ngons); }

	/// @}

	/// @name Miscellaneous
	/// @{

	//----------------------------------------------------------------------------------------
	/// Flushes the neighbor information.
	//----------------------------------------------------------------------------------------
	void Flush() { C4DOS.Nb->Free(ee); ee = nullptr; }

	//----------------------------------------------------------------------------------------
	/// Allows to set the new pointer to the polygon object if changed.\n
	/// It is then possible to continue using the Neighbor data.
	/// @warning	Use carefully!\n
	///						The array lengths and orders must not have changed, only the pointer used.
	/// @param[in] a_polyadr					The new polygon address to set.
	//----------------------------------------------------------------------------------------
	void ResetAddress(const CPolygon* a_polyadr) { C4DOS.Nb->ResetAddress(ee, a_polyadr); }

	/// @}
};


//----------------------------------------------------------------------------------------
/// Gets a LineObject or SplineObject from a spline generator.
/// @param[in] op									The spline object. @callerOwnsPointed{base object}
/// @param[in] hh									The HierarchyHelp usually passed from ObjectData::GetVirtualObjects(). @callerOwnsPointed{hierarchy help}
/// @param[in] mloc								The local matrix of the spline object.
/// @param[in] keep_spline				@formatConstant{true} to generate a SplineObject or @formatConstant{false} for a LineObject.
/// @param[in] recurse						If @formatConstant{true} and the object @formatParam{op} itself did not generate a line object then @C4D will search through all children and caches of @formatParam{op} if any of those objects generates the line form.
/// 															@note The caches are always searched.\n
/// 															If a spline is placed in An array object and the array under the generator then GetVirtualLineObject() will return the first "arrayed" spline.\n
/// 															For example, a Spline is put into a Null object placed under the generator.\n
/// 															With @formatParam{recurse}==@formatConstant{false} then GetVirtualLineObject() return @formatConstant{nullptr}, if @formatParam{recurse}==@formatConstant{true} then it would find the first child Spline of the Null object.
/// @param[out] mres							Assigned the local matrix of the object that created the line form.
/// @param[out] dirty							Assigned @formatConstant{true} if the object that generated the spline was modified. In this case the generator knows that it must rebuild its cache.
/// @return												The LineObject or SplineObject from a spline generator. @callerOwnsPointed{base object}
//----------------------------------------------------------------------------------------
BaseObject* GetVirtualLineObject(BaseObject* op, HierarchyHelp* hh, const Matrix& mloc, Bool keep_spline, Bool recurse, Matrix* mres, Bool* dirty);

//----------------------------------------------------------------------------------------
/// Generates a UVW tag for an object.
/// @param[in] op									The object to generate the UVW coordinates for. @callerOwnsPointed{base object}
/// @param[in] opmg								The object's global matrix.
/// @param[in] tp									The texture tag to generate the UVW coordinates from. @callerOwnsPointed{texture tag}
/// @param[in] texopmg						The global matrix of the object that carries the texture tag.
/// @param[in] view								The current view or @formatConstant{nullptr}. @callerOwnsPointed{base view}
/// @return												The created UVW tag or @formatConstant{nullptr} if the texture type is already UV or if failed.
/// 															If @formatConstant{nullptr} then the UVW tag must retrieved from the object itself. @callerOwnsPointed{UVW tag}
//----------------------------------------------------------------------------------------
UVWTag* GenerateUVW(BaseObject* op, const Matrix& opmg, TextureTag* tp, const Matrix& texopmg, BaseView* view);

//----------------------------------------------------------------------------------------
/// Limits the float value with the specified @formatParam{id} in the container @formatParam{data} between @formatParam{min} and @formatParam{max}.
/// @param[in] data								The container with the value.
/// @param[in] id									The ID of the float value.
/// @param[in] min								The minimum value.
/// @param[in] max								The maximum value.
//----------------------------------------------------------------------------------------
void CutReal(BaseContainer& data, Int32 id, Float min, Float max);

//----------------------------------------------------------------------------------------
/// Limits the vector value with the specified @formatParam{id} in the container @formatParam{data} between @formatParam{min} and @formatParam{max}.
/// @param[in] data								The container with the value.
/// @param[in] id									The ID of the vector value.
/// @param[in] min								The minimum value.
/// @param[in] max								The maximum value.
//----------------------------------------------------------------------------------------
void CutVector(BaseContainer& data, Int32 id, Float min, Float max);

//----------------------------------------------------------------------------------------
/// Checks which points in the points array @formatParam{padr} of @formatParam{op} are visible in the view @formatParam{bd}.
/// @param[in] bd									The base draw to check. @callerOwnsPointed{base draw}
/// @param[in] op									The polygon object to check. @callerOwnsPointed{polygon object}
/// @param[in] padr								The points array. @callerOwnsPointed{points array}
/// @param[in] pset								Assigned an array of size PointObject::GetPointCount() with the visibility status for each point:\n
/// 															@em 1 if the point is visible otherwise @em 0 .
/// @param[in] select_visibonly		If @formatConstant{true} only points that are truly visible are included, otherwise e.g. points from the back of an object are included.
/// @return												@trueIfOtherwiseFalse{successful}
//----------------------------------------------------------------------------------------
Bool CalculateVisiblePoints(BaseDraw* bd, PolygonObject* op, Vector* padr, UChar* pset, Bool select_visibonly);


/// @addtogroup POLY_TRIANG
/// @ingroup group_enumeration
/// @{
#define POLY_TRIANG_CONSTRAINED_OUTLINE	1													///< All points form the outline; the segments are ignored.
#define POLY_TRIANG_QUADS								8													///< Untriangulate where possible.
#define POLY_TRIANG_NGON								32												///< Must be set if an N-gon is to be triangulated.
#define POLY_TRIANG_FORCE_VORONOI				64												///< Force Voronoi triangulation.
#define POLY_TRIANG_FORCE_NGON					(128 | POLY_TRIANG_NGON)	///< Force special N-gon triangulation.
#define POLY_TRIANG_FILL_HOLES					256												///< Fill segment holes (only used for N-gon triangulation).
/// @}

/// @addtogroup TRIANGSTATE
/// @ingroup group_enumeration
/// @{
#define TRIANGSTATE_SKIP_EDGE						1			///< An edge could not be generated.
#define TRIANGSTATE_MISSING_CONSTRAINT	2			///< A constrained edge could not be generated.
/// @}

//----------------------------------------------------------------------------------------
/// Polygon triangulation class.
/// @addAllocFreeAutoAllocNote
//----------------------------------------------------------------------------------------
class PolyTriangulate
{
private:
	PolyTriangulate();
	~PolyTriangulate();

public:
	/// @name Alloc/Free
	/// @{

	//----------------------------------------------------------------------------------------
	/// @allocatesA{poly triangulate}
	/// @return												@allocReturn{poly triangulate}
	//----------------------------------------------------------------------------------------
	static PolyTriangulate* Alloc();

	//----------------------------------------------------------------------------------------
	/// @destructsAlloc{poly triangulates}
	/// @param[in,out] pTriang				@theToDestruct{poly triangulate}
	//----------------------------------------------------------------------------------------
	static void Free(PolyTriangulate*& pTriang);

	/// @}

	//----------------------------------------------------------------------------------------
	/// Triangulates the points in @formatParam{pvPoints} and returns the result in @formatParam{pPolys}.
	/// The allocated array is freed on the next call to Triangulate() or when the PolyTriangulate instance is freed.
	/// @warning Do not store @formatParam{pPolys} for later use. It will get invalid after the next Triangulate() call or when the class instance is destroyed.
	/// @note Use TriangulateRelease() to store @formatParam{pPolys} for a later use.
	/// @param[in] pvPoints						The points to triangulate. @callerOwnsPointed{points array}
	/// @param[in] lPointCount				The number of points in @formatParam{pvPoints} array.
	/// @param[in] plSegments					The segments array, or @formatConstant{nullptr}. The number of segment points is stored in each element. @callerOwnsPointed{segments array}
	/// @param[in] lSegCnt						The number of segments in @formatParam{plSegments} array.
	/// @param[out] pPolys						Assigned a pointer to the triangulated polygons array.
	/// @param[out] lPolyCount				Assigned the number of triangulated polygons in @formatParam{pPolys}.
	/// @param[in] lFlags							The triangulation flags: @enumerateEnum{POLY_TRIANG}
	/// @param[in] plMap							An optional point map. @callerOwnsPointed{point map}\n
	/// 															@formatParam{plMap} allows to choose which vertices should be used in the triangulation.\n
	/// 															Imagine a vector array with @em 100 elements; to triangulate the points @em 10, @em 20, @em 30, @em 40 and @em 50, @formatParam{lPointCount} would be @em 5 and @formatParam{plMap} = <i>{ 10, 20, 30, 40, 50 }</i>.
	/// @param[in] pThread						A thread for the operation. @callerOwnsPointed{thread}
	/// @param[in] lConstraints				Reserved for future use.
	/// @param[in] plConstrainedEdges	Reserved for future use.
	/// @return												@trueIfOtherwiseFalse{triangulation was successful}
	//----------------------------------------------------------------------------------------
	Bool Triangulate(const Vector* pvPoints, Int32 lPointCount, const Int32* plSegments, Int32 lSegCnt,
									 CPolygon*& pPolys, Int32& lPolyCount, Int32 lFlags = 0, const Int32* plMap = nullptr, BaseThread* pThread = nullptr,
									 Int32 lConstraints = 0, const Int32* plConstrainedEdges = nullptr);

	//----------------------------------------------------------------------------------------
	/// Triangulates the points in @formatParam{pvPoints} and returns the result in @formatParam{pPolys}.\n
	/// Same as Triangulate(), except that the memory is not freed by the PolyTriangulate instance.
	/// @warning The returned array @formatParam{pPolys} needs to be freed with DeleteMem() afterwards.
	/// @param[in] pvPoints						The points to triangulate. @callerOwnsPointed{points array}
	/// @param[in] lPointCount				The number of points in @formatParam{pvPoints} array.
	/// @param[in] plSegments					The segments array, or @formatConstant{nullptr}. The number of segment points is stored in each element. @callerOwnsPointed{segments array}
	/// @param[in] lSegCnt						The number of segments in @formatParam{plSegments} array.
	/// @param[out] pPolys						Assigned a pointer to the triangulated polygons array.
	/// @param[out] lPolyCount				Assigned the number of triangulated polygons in @formatParam{pPolys}.
	/// @param[in] lFlags							The triangulation flags: @enumerateEnum{POLY_TRIANG}
	/// @param[in] plMap							An optional point map. @callerOwnsPointed{point map}\n
	/// 															@formatParam{plMap} allows to choose which vertices should be used in the triangulation.\n
	/// 															Imagine a vector array with @em 100 elements; to triangulate the points @em 10, @em 20, @em 30, @em 40 and @em 50, @formatParam{lPointCount} would be @em 5 and @formatParam{plMap} = <i>{ 10, 20, 30, 40, 50 }</i>.
	/// @param[in] pThread						A thread for the operation. @callerOwnsPointed{thread}
	/// @param[in] lConstraints				Reserved for future use.
	/// @param[in] plConstrainedEdges	Reserved for future use.
	/// @return												@trueIfOtherwiseFalse{triangulation was successful}
	//----------------------------------------------------------------------------------------
	Bool TriangulateRelease(const Vector* pvPoints, Int32 lPointCount, const Int32* plSegments, Int32 lSegCnt,
													CPolygon*& pPolys, Int32& lPolyCount, Int32 lFlags = 0, const Int32* plMap = nullptr, BaseThread* pThread = nullptr,
													Int32 lConstraints = 0, const Int32* plConstrainedEdges = nullptr);

	//----------------------------------------------------------------------------------------
	/// Checks if there were any identical points in the triangulation, i.e. points with a distance less than @em 0.0001.
	/// @return												@trueIfOtherwiseFalse{there were identical points}
	//----------------------------------------------------------------------------------------
	Bool HasIdentical();

	//----------------------------------------------------------------------------------------
	/// Sets the matrix for the triangulation.\n
	/// The triangulation usually calculates the normal of the points set and projects the points into a plane that is described by this normal and the point <i>(0, 0, 0)</i>.\n
	/// To speed up the triangulation use this if the matrix is already calculated.\n
	/// The vector in @formatParam{m}->@link Matrix64::v3 v3@endlink must be the polygon normal. All vectors must be perpendicular to each other.
	/// @param[in] m									The polygon matrix to use, or @formatConstant{nullptr} to enable automatic calculation of the polygon normal again.\n
	/// 															The pointed matrix must be valid as long as calls to the triangulate methods are made, or until a new matrix or @formatConstant{nullptr} is set.\n
	/// 															@callerOwnsPointed{matrix}
	//----------------------------------------------------------------------------------------
	void SetPolygonMatrix(Matrix64* m);

	//----------------------------------------------------------------------------------------
	/// Gets the state of the triangulation engine.
	/// @return												The error state flags: @enumerateEnum{TRIANGSTATE}
	//----------------------------------------------------------------------------------------
	UInt32 GetState();
};

#ifdef CINEWARE_NAMESPACE_ENABLE
	CINEWARE_NAMESPACE_END
#endif

#endif // C4D_BASEOBJECT_H__
