#if 1
namespace maxon
{
	namespace enum17 { enum class GRAPH_TYPE
	{
		CONTINUOS		= 0,	///< The Graph is continuos so all points in array list order.
		SPARSE			= 1		///< The Graph is sparse so points have to be sorted before modeling.
	} ; }
	maxon::String PrivateToString_GRAPH_TYPE17(std::underlying_type<enum17::GRAPH_TYPE>::type x, const maxon::FormatStatement* fmt)
	{
		const maxon::UInt64 values[] = {(maxon::UInt64) enum17::GRAPH_TYPE::CONTINUOS, (maxon::UInt64) enum17::GRAPH_TYPE::SPARSE};
		return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "GRAPH_TYPE", SIZEOF(x), false, values, "CONTINUOS\0SPARSE\0", fmt);
	}
}
#endif
