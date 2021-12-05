#if 1
namespace maxon
{
	namespace enum46 { enum class INTERFACES
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
		} ; }
	maxon::String PrivateToString_INTERFACES46(std::underlying_type<enum46::INTERFACES>::type x, const maxon::FormatStatement* fmt, void*)
	{
		const maxon::UInt64 values[] = {(maxon::UInt64) enum46::INTERFACES::NONE, (maxon::UInt64) enum46::INTERFACES::SINGLETON_CONTAINER, (maxon::UInt64) enum46::INTERFACES::ARRAY_CONTAINER, (maxon::UInt64) enum46::INTERFACES::XFORM_CONTAINER, (maxon::UInt64) enum46::INTERFACES::CONCAT_CONTAINER, (maxon::UInt64) enum46::INTERFACES::STATIC_ARRAY, (maxon::UInt64) enum46::INTERFACES::V_ARRAY, (maxon::UInt64) enum46::INTERFACES::ARRAY, (maxon::UInt64) enum46::INTERFACES::SINGLE_VALUE_ARRAY};
		return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "GenericContainerInterface::INTERFACES", SIZEOF(x), true, values, "NONE\0SINGLETON_CONTAINER\0ARRAY_CONTAINER\0XFORM_CONTAINER\0CONCAT_CONTAINER\0STATIC_ARRAY\0V_ARRAY\0ARRAY\0SINGLE_VALUE_ARRAY\0", fmt);
	}
}
#endif
