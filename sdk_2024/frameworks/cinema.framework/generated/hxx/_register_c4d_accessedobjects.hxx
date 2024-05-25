#if 1
#ifdef CINEWARE_NAMESPACE_ENABLE
CINEWARE_NAMESPACE_BEGIN
#endif
namespace enum78
{
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
	} ;
	static const maxon::UInt64 ACCESSED_OBJECTS_MASK_values[] = {maxon::UInt64(enum78::ACCESSED_OBJECTS_MASK::NONE), maxon::UInt64(enum78::ACCESSED_OBJECTS_MASK::MATRIX), maxon::UInt64(enum78::ACCESSED_OBJECTS_MASK::DATA), maxon::UInt64(enum78::ACCESSED_OBJECTS_MASK::BITS), maxon::UInt64(enum78::ACCESSED_OBJECTS_MASK::NBITS), maxon::UInt64(enum78::ACCESSED_OBJECTS_MASK::FALLOFF), maxon::UInt64(enum78::ACCESSED_OBJECTS_MASK::MEMBER), maxon::UInt64(enum78::ACCESSED_OBJECTS_MASK::DEFORM_MODE), maxon::UInt64(enum78::ACCESSED_OBJECTS_MASK::CACHE_FLAG), maxon::UInt64(enum78::ACCESSED_OBJECTS_MASK::CACHE), maxon::UInt64(enum78::ACCESSED_OBJECTS_MASK::VARIABLE_TAG), maxon::UInt64(enum78::ACCESSED_OBJECTS_MASK::NON_VARIABLE_TAG), maxon::UInt64(enum78::ACCESSED_OBJECTS_MASK::ANY_TAG), maxon::UInt64(enum78::ACCESSED_OBJECTS_MASK::DESCRIPTION), maxon::UInt64(enum78::ACCESSED_OBJECTS_MASK::ALL), maxon::UInt64(enum78::ACCESSED_OBJECTS_MASK::GLOBAL_MATRIX_FLAG), maxon::UInt64(enum78::ACCESSED_OBJECTS_MASK::CHILD_CACHE), maxon::UInt64(enum78::ACCESSED_OBJECTS_MASK::GLOBAL_MATRIX)};
	static const maxon::EnumInfo ACCESSED_OBJECTS_MASK_info{"ACCESSED_OBJECTS_MASK", SIZEOF(ACCESSED_OBJECTS_MASK), true, "NONE\0MATRIX\0DATA\0BITS\0NBITS\0FALLOFF\0MEMBER\0DEFORM_MODE\0CACHE_FLAG\0CACHE\0VARIABLE_TAG\0NON_VARIABLE_TAG\0ANY_TAG\0DESCRIPTION\0ALL\0GLOBAL_MATRIX_FLAG\0CHILD_CACHE\0GLOBAL_MATRIX\0", ACCESSED_OBJECTS_MASK_values, std::extent<decltype(ACCESSED_OBJECTS_MASK_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_ACCESSED_OBJECTS_MASK78(){ return enum78::ACCESSED_OBJECTS_MASK_info; }
namespace enum123
{
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
	} ;
	static const maxon::UInt64 METHOD_ID_values[] = {maxon::UInt64(enum123::METHOD_ID::MIN_EXECUTION_ID), maxon::UInt64(enum123::METHOD_ID::NONE), maxon::UInt64(enum123::METHOD_ID::GET_VIRTUAL_OBJECTS), maxon::UInt64(enum123::METHOD_ID::MODIFY_OBJECT), maxon::UInt64(enum123::METHOD_ID::GET_VIRTUAL_OBJECTS_AND_MODIFY_OBJECT), maxon::UInt64(enum123::METHOD_ID::GV_CALCULATE), maxon::UInt64(enum123::METHOD_ID::SAMPLE), maxon::UInt64(enum123::METHOD_ID::CHECK_DIRTY), maxon::UInt64(enum123::METHOD_ID::EFFECTOR)};
	static const maxon::EnumInfo METHOD_ID_info{"METHOD_ID", SIZEOF(METHOD_ID), false, "MIN_EXECUTION_ID\0NONE\0GET_VIRTUAL_OBJECTS\0MODIFY_OBJECT\0GET_VIRTUAL_OBJECTS_AND_MODIFY_OBJECT\0GV_CALCULATE\0SAMPLE\0CHECK_DIRTY\0EFFECTOR\0", METHOD_ID_values, std::extent<decltype(METHOD_ID_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_METHOD_ID123(){ return enum123::METHOD_ID_info; }
#ifdef CINEWARE_NAMESPACE_ENABLE
CINEWARE_NAMESPACE_END
#endif
#endif
