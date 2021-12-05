#if 1
namespace maxon
{
	namespace enum144
	{
		enum class COLLECTION_RESIZE_FLAGS
		{
			NONE										= 0,
		
			ON_SHRINK_KEEP_CAPACITY	= 0,				///< Don't change capacity.
			ON_SHRINK_FIT_TO_SIZE		= (1 << 0),	///< Copy the array to a new memory block that is as small as possible to hold the data.
		
			ON_GROW_RESERVE_CAPACITY	= 0,			///< Allocate some extra capacity (based on ComputeArraySize()).
			ON_GROW_FIT_TO_SIZE			= (1 << 1),	///< Grow the array exactly to the requested size.
		
			ON_GROW_UNINITIALIZED		= (1 << 2),	///< Do not initialize added elements (usually PODs) when resizing the array (is supported by all collections).
		
			ON_GROW_UNSPECIFIED			= (1 << 3),	///< Initialize added elements with unspecified (but legal) values. For example PODs can be left uninitialized, strong references can be zero-initialized for best performance.
		
			ON_RESIZE_UNSPECIFIED		= (1 << 4),	///< The resize operation may use unspecified (but legal) values for existing elements as well as for added elements. After resize all elements may contain unspecified values.
		
			FIT_TO_SIZE							= ON_SHRINK_FIT_TO_SIZE | ON_GROW_FIT_TO_SIZE,	///< Fits the array to the requested size for growing and shrinking.
			DEFAULT									= ON_SHRINK_KEEP_CAPACITY | ON_GROW_FIT_TO_SIZE,	///< The default is to keep capacity on shrink and fit to size when growing the array.
			POD_UNINITIALIZED				= DEFAULT | ON_GROW_UNINITIALIZED
		} ;
		static const maxon::UInt64 COLLECTION_RESIZE_FLAGS_values[] = {maxon::UInt64(enum144::COLLECTION_RESIZE_FLAGS::NONE), maxon::UInt64(enum144::COLLECTION_RESIZE_FLAGS::ON_SHRINK_KEEP_CAPACITY), maxon::UInt64(enum144::COLLECTION_RESIZE_FLAGS::ON_SHRINK_FIT_TO_SIZE), maxon::UInt64(enum144::COLLECTION_RESIZE_FLAGS::ON_GROW_RESERVE_CAPACITY), maxon::UInt64(enum144::COLLECTION_RESIZE_FLAGS::ON_GROW_FIT_TO_SIZE), maxon::UInt64(enum144::COLLECTION_RESIZE_FLAGS::ON_GROW_UNINITIALIZED), maxon::UInt64(enum144::COLLECTION_RESIZE_FLAGS::ON_GROW_UNSPECIFIED), maxon::UInt64(enum144::COLLECTION_RESIZE_FLAGS::ON_RESIZE_UNSPECIFIED), maxon::UInt64(enum144::COLLECTION_RESIZE_FLAGS::FIT_TO_SIZE), maxon::UInt64(enum144::COLLECTION_RESIZE_FLAGS::DEFAULT), maxon::UInt64(enum144::COLLECTION_RESIZE_FLAGS::POD_UNINITIALIZED)};
		static const maxon::EnumInfo COLLECTION_RESIZE_FLAGS_info{"COLLECTION_RESIZE_FLAGS", SIZEOF(COLLECTION_RESIZE_FLAGS), true, "NONE\0ON_SHRINK_KEEP_CAPACITY\0ON_SHRINK_FIT_TO_SIZE\0ON_GROW_RESERVE_CAPACITY\0ON_GROW_FIT_TO_SIZE\0ON_GROW_UNINITIALIZED\0ON_GROW_UNSPECIFIED\0ON_RESIZE_UNSPECIFIED\0FIT_TO_SIZE\0DEFAULT\0POD_UNINITIALIZED\0", COLLECTION_RESIZE_FLAGS_values, std::extent<decltype(COLLECTION_RESIZE_FLAGS_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_COLLECTION_RESIZE_FLAGS144(){ return enum144::COLLECTION_RESIZE_FLAGS_info; }
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(DT_COLLECTION_RESIZE_FLAGS, , "net.maxon.datatype.enum.collection_resize_flags");
}
#endif
