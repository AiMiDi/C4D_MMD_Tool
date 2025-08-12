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

namespace cinema
{

//----------------------------------------------------------------------------------------
/// ACCESSED_OBJECTS_MASK is used for AccessedObjectsCallback to tell which data of an object is accessed.
//----------------------------------------------------------------------------------------
enum class ACCESSED_OBJECTS_MASK
{
	NONE								= 0,

	/// The matrix will be accessed (including e.g. frozen matrix). This doesn't include the global matrix.
	MATRIX							= 1 << 0,

	/// Data accessible via Get/SetParameter (including data stored in the BaseContainer and the DIRTYFLAGS::DATA bit) will be accessed.
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

	/// BaseObject::GetVirtualObjects and/or BaseObject::ModifyObject. This special method id
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

	/// CheckDirty method of falloffs, fields and deformers. The CheckDirty method of spline generators is subsumed in GET_VIRTUAL_OBJECTS.
	CHECK_DIRTY = -7,

	/// Effector methods.
	EFFECTOR = -8
} MAXON_ENUM_ORDERED_LIST(METHOD_ID);


enum class GET_ACCESSED_OBJECTS_FLAGS
{
	NONE = 0,
	CLONE_WITH_MODIFIED_PARAMETERS = 1
} MAXON_ENUM_FLAGS(GET_ACCESSED_OBJECTS_FLAGS);


class BaseList2D;
class BaseObject;
class BaseDocument;
enum class BUILDFLAGS : UInt16;

//----------------------------------------------------------------------------------------
/// An AccessedObjectsCallback is passed to BaseList2D::GetAccessedObjects so that an
/// implementation of BaseList2D can tell which data it will access within methods
/// like ModifyObject or GetVirtualObjects. This is used to parallelize the execution of
/// those methods as much as possible.
//----------------------------------------------------------------------------------------
class AccessedObjectsCallback
{
	MAXON_INTERFACE_SIMPLE_VIRTUAL(AccessedObjectsCallback, MAXON_REFERENCE_NONE);
public:
	MAXON_METHOD GET_ACCESSED_OBJECTS_FLAGS AddFlags(GET_ACCESSED_OBJECTS_FLAGS newFlags);

	MAXON_METHOD void RestoreFlags(GET_ACCESSED_OBJECTS_FLAGS prevFlags);

	MAXON_METHOD Bool TestFlags(GET_ACCESSED_OBJECTS_FLAGS mask) const;

	//----------------------------------------------------------------------------------------
	/// Marks object as visited to prevent endless recursion in implementations of BaseList2D::GetAccessedObjects.
	/// @param[in] object							An object for which GetAccessedObjects is called.
	/// @return												true if the object hasn't been marked as visited before by a prior call to MarkVisited, false otherwise.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD maxon::Result<Bool> MarkVisited(const BaseList2D* object);

	//----------------------------------------------------------------------------------------
	/// Checks if the data corresponding to readMask is already readable from object.
	/// That's the case unless there's a pending job which will write to that data.
	/// @param[in] object							An object.
	/// @param[in] readMask						The data mask for which readability shall be checked.
	/// @return												True if the data is readable, false otherwise.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Bool IsReadable(const BaseList2D* object, ACCESSED_OBJECTS_MASK readMask);

	//----------------------------------------------------------------------------------------
	/// Waits if necessary until the data corresponding to readMask is readable from object.
	/// This method will wait as long as there are pending jobs which will write to that data.
	/// @param[in] object							An object.
	/// @param[in] readMask						The data mask for which readability shall be checked.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD maxon::Result<void> EnsureReadable(const BaseList2D* object, ACCESSED_OBJECTS_MASK readMask);

	//----------------------------------------------------------------------------------------
	/// Tells the callback that the current method may access object's data corresponding to readMask and writeMask.
	/// MayAccess is called in implementations of BaseList2D::GetAccessedObjects. A simple implementation for
	/// a generator could look like this:
	/// @code
	///	class MyObject : public ObjectData
	///	{
	///		INSTANCE(MyObject, ObjectData)
	///	public:
	///	  ...
	///		Result<Bool> GetAccessedObjects(const BaseList2D* node, METHOD_ID method, AccessedObjectsCallback& access) const override
	///		{
	///			switch (method)
	///			{
	///				case METHOD_ID::GET_VIRTUAL_OBJECTS:
	///				{
	///					return access.MayAccess(node, ACCESSED_OBJECTS_MASK::DATA | ACCESSED_OBJECTS_MASK::ANY_TAG, ACCESSED_OBJECTS_MASK::CACHE);
	///				}
	///			}
	///			return SUPER::GetAccessedObjects(node, method, access);
	///		}
	///	};
	///	@endcode
	///	So when the object's GetVirtualObjects method is called, this may read from the BaseContainer and also from any tag,
	///	and it may write to the cache (namely, it writes the generated virtual object).
	///	If GetVirtualObjects reads from further objects (e.g., children or linked objects), this has to be matched by additional calls to MayAccess.
	///
	/// @param[in] object							An object which the current method will access during execution.
	/// @param[in] readMask						The data identified by readMask will be read from object.
	/// @param[in] writeMask					The data identified by writeMask will be written to object. This also allows to read the data.
	/// @return												If this returns false, the callback isn't interested in further calls to MayAccess and you can do an early exit.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD maxon::Result<Bool> MayAccess(const BaseList2D* object, ACCESSED_OBJECTS_MASK readMask, ACCESSED_OBJECTS_MASK writeMask);

	//----------------------------------------------------------------------------------------
	/// Tells the callback that the current method may access anything from the current document.
	/// You have to use this instead of MayAccess if it's unknown or too complex what the current method will actually do.
	///
	/// The default behaviour of BaseList2D::GetAccessedObjects is to call MayAccessAnything.
	/// @return												If this returns false, the callback isn't interested in further calls to MayAccess and you can do an early exit.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD maxon::Result<Bool> MayAccessAnything();

	//----------------------------------------------------------------------------------------
	/// Returns the current document.
	/// @return												Current document.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD const BaseDocument* GetDocument();

	//----------------------------------------------------------------------------------------
	/// Returns the current build flags.
	/// @return												Current build flags.
	/// @MAXON_ANNOTATION{default=BUILDFLAGS(0)}
	//----------------------------------------------------------------------------------------
	MAXON_METHOD BUILDFLAGS GetBuildFlags();
};

} // namespace cinema

#include "c4d_accessedobjects1.hxx"
#include "c4d_accessedobjects2.hxx"

#endif // C4D_ACCESSEDOBJECTS_H__
	
