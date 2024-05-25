/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef C4D_ACCESSEDOBJECTS_H__
#define C4D_ACCESSEDOBJECTS_H__

#include "maxon/interfacebase.h"
#include "maxon/optional.h"
#include "ge_sys_math.h"

#ifdef CINEWARE_NAMESPACE_ENABLE
	CINEWARE_NAMESPACE_BEGIN
#endif

enum class ACCESSED_OBJECTS_MASK
{
	NONE								= 0,

	/// The matrix will be accessed (including e.g. frozen matrix). This doesn't include the global matrix.
	MATRIX							= 1 << 0,

	/// Data accessible via Get/SetParameter (including data stored in the BaseContainer) will be accessed.
	DATA								= 1 << 1,

	/// The Bits (BaseList2D::GetBit) of the object will be accessed.
	BITS								= 1 << 2,

	/// The NBits (GeListNode::GetNBit) of the object will be accessed.
	NBITS								= 1 << 3,

	/// The falloff member will be accessed.
	FALLOFF							=	1 << 4,

	/// Some other member (neither matrix, data container/parameter, bits, nor falloff) of the object will be accessed.
	MEMBER							= 1 << 5,

	/// The deform mode of a generator/deformer will be accessed.
	DEFORM_MODE					= 1 << 6,

	/// The cache of the object will be accessed. This includes cache-related data such as the dependence list, cache proxy tags,
	/// or the IsDirty/ClearDirty/Touch-controlled dirty information.
	/// During generator execution this has a hierarchical meaning, so when a generator tells that it may read from an object's cache,
	/// it is allowed to read nested caches as well.
	/// Don't use this flag directly, use CACHE instead.
	CACHE_FLAG					= 1 << 7,

	/// The cache of the object will be accessed. Combination of CACHE_FLAG and BITS as CACHE_FLAG implies BITS.
	CACHE								= CACHE_FLAG | BITS,

	/// A VariableTag of the object will be accessed. May only be used for METHOD_ID::GET_VIRTUAL_OBJECTS or METHOD_ID::MODIFY_OBJECT.
	VARIABLE_TAG				= 1 << 8,

	/// A non-VariableTag of the object will be accessed. May only be used for METHOD_ID::GET_VIRTUAL_OBJECTS or METHOD_ID::MODIFY_OBJECT.
	NON_VARIABLE_TAG		= 1 << 9,

	/// A tag of the object will be accessed. May only be used for METHOD_ID::GET_VIRTUAL_OBJECTS or METHOD_ID::MODIFY_OBJECT.
	/// Combination of VARIABLE_TAG and NON_VARIABLE_TAG.
	ANY_TAG							= VARIABLE_TAG | NON_VARIABLE_TAG,

	/// The dirty information DIRTYFLAGS::DESCRIPTION will be accessed.
	DESCRIPTION					= 1 << 10,

	/// All flags combined (except GLOBAL_MATRIX and CHILD_CACHE).
	ALL									= (1 << 20) - 1,

	/// The global matrix will be accessed. This flag may only be used for read access. Don't use this flag directly, use GLOBAL_MATRIX instead.
	GLOBAL_MATRIX_FLAG	= 1 << 30,

	/// Only a child cache of the cache will be affected. Don't use this flag directly, it will be set internally together with CACHE_FLAG
	/// to take into account that whenever a cache is modified and it is part of a parent cache, the parent cache is affected as well.
	CHILD_CACHE					= 1 << 29,

	/// The global matrix will be accessed. Combination of GLOBAL_MATRIX_FLAG and MATRIX as GLOBAL_MATRIX_FLAG implies MATRIX.
	GLOBAL_MATRIX				= GLOBAL_MATRIX_FLAG | MATRIX,
} MAXON_ENUM_FLAGS(ACCESSED_OBJECTS_MASK);


//----------------------------------------------------------------------------------------
/// METHOD_ID is used for BaseList2D::GetAccessedObjects to tell for which method accessed objects shall be obtained.
/// Non-negative values represent calls to the generic BaseTag/BaseObject::Execute method with the METHOD_ID as execution priority.
/// Negative values represent calls to specific methods such as GetVirtualObjects.
//----------------------------------------------------------------------------------------
enum class METHOD_ID : Int32
{
	/// Minimum value which encodes a call to BaseTag/BaseObject::Execute with the METHOD_ID as execution priority.
	MIN_EXECUTION_ID = 0,

	/// No method call.
	NONE = -1,

	/// BaseObject::GetVirtualObjects method of generators. For spline generators this includes the methods GetContour and CheckDirty.
	GET_VIRTUAL_OBJECTS = -2,

	/// BaseObject::ModifyObject method of deformers and tags, also used for matrix modifier tags and variable tags with fields.
	MODIFY_OBJECT = -3,

	/// BaseObject::GetVirtualObjects and/or BaseObject::ModifyObject. This this special method id
	/// can be used for BaseList2D::GetAccessedObjectsRec and its related functions
	/// GetAccessedObjectsOfHierarchy, GetAccessedObjectsOfChildren, GetAccessedObjectsOfFirstChildHierarchy.
	/// It will call GetAccessedObjects on generators and modifiers and makes sure that this includes all modifiers which effect a generator.
	/// E.g., if you call GetAccessedObjectsRec on a generator, GetAccessedObjects will be called not only on the generator
	/// but also on its modifier children, modifier tags, matrix modifier tags, and variable tags with fields.
	///
	/// This method id must NOT be used for direct calls to GetAccessedObjects.
	///
	/// You don't have to check for GET_VIRTUAL_OBJECTS_AND_MODIFY_OBJECT in implementations of GetAccessedObjects,
	/// the replacement by GET_VIRTUAL_OBJECTS or MODIFY_OBJECT is done internally before GetAccessedObjects implementations are called.
	GET_VIRTUAL_OBJECTS_AND_MODIFY_OBJECT = -4,

	GV_CALCULATE = -5,

	/// Sampling methods of falloffs and fields, including InitFalloff.
	SAMPLE = -6,

	/// CheckDirty method of falloffs and fields.
	CHECK_DIRTY = -7,

	/// Effector methods.
	EFFECTOR = -8
} MAXON_ENUM_ORDERED_LIST(METHOD_ID);


class BaseList2D;
class BaseObject;
class BaseDocument;
enum class BUILDFLAGS : UInt16;

class AccessedObjectsCallback
{
	MAXON_INTERFACE_SIMPLE_VIRTUAL(AccessedObjectsCallback, MAXON_REFERENCE_NONE);
public:
	MAXON_METHOD Bool IsReadable(const BaseList2D*, ACCESSED_OBJECTS_MASK);

	MAXON_METHOD maxon::Result<void> EnsureReadable(const BaseList2D*, ACCESSED_OBJECTS_MASK);

	MAXON_METHOD maxon::Result<Bool> MayAccess(const BaseList2D*, ACCESSED_OBJECTS_MASK, ACCESSED_OBJECTS_MASK);

	MAXON_METHOD maxon::Result<Bool> MayAccessAnything();

	MAXON_METHOD const BaseDocument* GetDocument();

	/// @MAXON_ANNOTATION{default=BUILDFLAGS(0)}
	MAXON_METHOD BUILDFLAGS GetBuildFlags();
};

#ifdef CINEWARE_NAMESPACE_ENABLE
	CINEWARE_NAMESPACE_END
#endif

#include "c4d_accessedobjects1.hxx"
#include "c4d_accessedobjects2.hxx"

#endif // C4D_ACCESSEDOBJECTS_H__
