#if 1
namespace maxon
{
	namespace enum64
	{
		enum class INTERFACES
			{
				NONE = 0,												///< No interface.
				VIRTUAL_TUPLE_CONTAINER = 1,		///< The container is a virtual tuple container.
				ARRAY_CONTAINER = 2,						///< The container implements GenericArrayContainerInterface.
				XFORM_CONTAINER = 4,						///< The container is an xform container (see XformContainerActionsInterface).
				CONCAT_CONTAINER = 8,						///< The container is a concat container (see ContainerFactory::Concat).
				STATIC_ARRAY = 16,							///< The container implements StaticArrayInterface.
				ARRAY = 32,											///< The container implements ArrayInterface.
				SINGLE_VALUE_ARRAY = 64,				///< The container is a single-value array (see ArrayFactory::NewSingleValueArray). This is set in addition to ARRAY.
				BASE_ARRAY = 128,								///< The container uses an underlying BaseArray (see ArrayFactory::NewBaseArray). This is set in addition to ARRAY.
				PAGED_ARRAY = 256,							///< The container is a paged array (see ArrayFactory::NewPagedArray). This is set in addition to ARRAY.
				INDEXABLE = 512,								///< The container implements GenericIndexableContainerInterface.
				MULTI_DOMAIN_CONTAINER = 1024,	///< The container implements MultiDomainContainerInterface.
				SLICED_ARRAY = 2048,						///< The container is a subset of an array (see ArrayFactory::Slice). This is set in addition to ARRAY.
				MEMBER_ARRAY = 4096							///< The container is an array pointing to member data of a source array (see ArrayFactory::ExtractMember). This is set in addition to ARRAY.
			} ;
		static const maxon::UInt64 INTERFACES_values[] = {maxon::UInt64(enum64::INTERFACES::NONE), maxon::UInt64(enum64::INTERFACES::VIRTUAL_TUPLE_CONTAINER), maxon::UInt64(enum64::INTERFACES::ARRAY_CONTAINER), maxon::UInt64(enum64::INTERFACES::XFORM_CONTAINER), maxon::UInt64(enum64::INTERFACES::CONCAT_CONTAINER), maxon::UInt64(enum64::INTERFACES::STATIC_ARRAY), maxon::UInt64(enum64::INTERFACES::ARRAY), maxon::UInt64(enum64::INTERFACES::SINGLE_VALUE_ARRAY), maxon::UInt64(enum64::INTERFACES::BASE_ARRAY), maxon::UInt64(enum64::INTERFACES::PAGED_ARRAY), maxon::UInt64(enum64::INTERFACES::INDEXABLE), maxon::UInt64(enum64::INTERFACES::MULTI_DOMAIN_CONTAINER), maxon::UInt64(enum64::INTERFACES::SLICED_ARRAY), maxon::UInt64(enum64::INTERFACES::MEMBER_ARRAY)};
		static const maxon::EnumInfo INTERFACES_info{"GenericContainerInterface::INTERFACES", SIZEOF(INTERFACES), true, "NONE\0VIRTUAL_TUPLE_CONTAINER\0ARRAY_CONTAINER\0XFORM_CONTAINER\0CONCAT_CONTAINER\0STATIC_ARRAY\0ARRAY\0SINGLE_VALUE_ARRAY\0BASE_ARRAY\0PAGED_ARRAY\0INDEXABLE\0MULTI_DOMAIN_CONTAINER\0SLICED_ARRAY\0MEMBER_ARRAY\0", INTERFACES_values, std::extent<decltype(INTERFACES_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_INTERFACES64(void*){ return enum64::INTERFACES_info; }
	namespace enum162
	{
		enum class ITERATOR_ACCESS : UChar
			{
				READ,				///< The iterator will only read values.
				WRITE,			///< The iterator will only write values. If a copy has to be made as part of InitIterator, the current values don't have to be copied.
				READ_WRITE	///< The iterator will read and write values.
			} ;
		static const maxon::UInt64 ITERATOR_ACCESS_values[] = {maxon::UInt64(enum162::ITERATOR_ACCESS::READ), maxon::UInt64(enum162::ITERATOR_ACCESS::WRITE), maxon::UInt64(enum162::ITERATOR_ACCESS::READ_WRITE)};
		static const maxon::EnumInfo ITERATOR_ACCESS_info{"GenericContainerInterface::ITERATOR_ACCESS", SIZEOF(ITERATOR_ACCESS), false, "READ\0WRITE\0READ_WRITE\0", ITERATOR_ACCESS_values, std::extent<decltype(ITERATOR_ACCESS_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_ITERATOR_ACCESS162(void*){ return enum162::ITERATOR_ACCESS_info; }
}
#endif
