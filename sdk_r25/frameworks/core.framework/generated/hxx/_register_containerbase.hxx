#if 1
namespace maxon
{
	namespace enum46
	{
		enum class INTERFACES
			{
				NONE = 0,
				SINGLETON_CONTAINER = 1,
				ARRAY_CONTAINER = 2,
				XFORM_CONTAINER = 4,
				CONCAT_CONTAINER = 8,
				STATIC_ARRAY = 16,
				V_ARRAY = 32,
				ARRAY = 64,
				SINGLE_VALUE_ARRAY = 128
			} ;
		static const maxon::UInt64 INTERFACES_values[] = {maxon::UInt64(enum46::INTERFACES::NONE), maxon::UInt64(enum46::INTERFACES::SINGLETON_CONTAINER), maxon::UInt64(enum46::INTERFACES::ARRAY_CONTAINER), maxon::UInt64(enum46::INTERFACES::XFORM_CONTAINER), maxon::UInt64(enum46::INTERFACES::CONCAT_CONTAINER), maxon::UInt64(enum46::INTERFACES::STATIC_ARRAY), maxon::UInt64(enum46::INTERFACES::V_ARRAY), maxon::UInt64(enum46::INTERFACES::ARRAY), maxon::UInt64(enum46::INTERFACES::SINGLE_VALUE_ARRAY)};
		static const maxon::EnumInfo INTERFACES_info{"GenericContainerInterface::INTERFACES", SIZEOF(INTERFACES), true, "NONE\0SINGLETON_CONTAINER\0ARRAY_CONTAINER\0XFORM_CONTAINER\0CONCAT_CONTAINER\0STATIC_ARRAY\0V_ARRAY\0ARRAY\0SINGLE_VALUE_ARRAY\0", INTERFACES_values, std::extent<decltype(INTERFACES_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_INTERFACES46(void*){ return enum46::INTERFACES_info; }
}
#endif
