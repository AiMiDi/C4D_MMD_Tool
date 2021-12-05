#if 1
namespace maxon
{
	namespace enum140 { enum class COLLECTION_RESIZE_FLAGS
	{
		NONE										= 0,
	
		ON_SHRINK_KEEP_CAPACITY	= 0,				///< Don't change capacity.
		ON_SHRINK_FIT_TO_SIZE		= (1 << 0),	///< Copy the array to a new memory block that is as small as possible to hold the data.
	
		ON_GROW_RESERVE_CAPACITY	= 0,			///< Allocate some extra capacity (based on ComputeArraySize()).
		ON_GROW_FIT_TO_SIZE			= (1 << 1),	///< Grow the array exactly to the requested size.
	
		ON_GROW_UNINITIALIZED		= (1 << 2),	///< Do not initialize added elements (usually PODs) when resizing the array (is supported by all collections).
	
		FIT_TO_SIZE							= ON_SHRINK_FIT_TO_SIZE | ON_GROW_FIT_TO_SIZE,	///< Fits the array to the requested size for growing and shrinking.
		DEFAULT									= ON_SHRINK_KEEP_CAPACITY | ON_GROW_FIT_TO_SIZE,	///< The default is to keep capacity on shrink and fit to size when growing the array.
		POD_UNINITIALIZED				= DEFAULT | ON_GROW_UNINITIALIZED
	} ; }
	maxon::String PrivateToString_COLLECTION_RESIZE_FLAGS140(std::underlying_type<enum140::COLLECTION_RESIZE_FLAGS>::type x, const maxon::FormatStatement* fmt)
	{
		const maxon::UInt64 values[] = {(maxon::UInt64) enum140::COLLECTION_RESIZE_FLAGS::NONE, (maxon::UInt64) enum140::COLLECTION_RESIZE_FLAGS::ON_SHRINK_KEEP_CAPACITY, (maxon::UInt64) enum140::COLLECTION_RESIZE_FLAGS::ON_SHRINK_FIT_TO_SIZE, (maxon::UInt64) enum140::COLLECTION_RESIZE_FLAGS::ON_GROW_RESERVE_CAPACITY, (maxon::UInt64) enum140::COLLECTION_RESIZE_FLAGS::ON_GROW_FIT_TO_SIZE, (maxon::UInt64) enum140::COLLECTION_RESIZE_FLAGS::ON_GROW_UNINITIALIZED, (maxon::UInt64) enum140::COLLECTION_RESIZE_FLAGS::FIT_TO_SIZE, (maxon::UInt64) enum140::COLLECTION_RESIZE_FLAGS::DEFAULT, (maxon::UInt64) enum140::COLLECTION_RESIZE_FLAGS::POD_UNINITIALIZED};
		return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "COLLECTION_RESIZE_FLAGS", SIZEOF(x), true, values, "NONE\0ON_SHRINK_KEEP_CAPACITY\0ON_SHRINK_FIT_TO_SIZE\0ON_GROW_RESERVE_CAPACITY\0ON_GROW_FIT_TO_SIZE\0ON_GROW_UNINITIALIZED\0FIT_TO_SIZE\0DEFAULT\0POD_UNINITIALIZED\0", fmt);
	}
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(DT_COLLECTION_RESIZE_FLAGS, , "net.maxon.datatype.enum.collection_resize_flags");
}
#endif
