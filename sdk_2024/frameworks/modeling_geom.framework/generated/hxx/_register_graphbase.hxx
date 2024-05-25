#if 1
namespace maxon
{
	namespace geomgraph
	{
		namespace enum19
		{
			enum class GRAPH_TYPE
			{
				CONTINUOS		= 0,	///< The Graph is continuos so all points in array list order.
				SPARSE			= 1		///< The Graph is sparse so points have to be sorted before modeling.
			} ;
			static const maxon::UInt64 GRAPH_TYPE_values[] = {maxon::UInt64(enum19::GRAPH_TYPE::CONTINUOS), maxon::UInt64(enum19::GRAPH_TYPE::SPARSE)};
			static const maxon::EnumInfo GRAPH_TYPE_info{"GRAPH_TYPE", SIZEOF(GRAPH_TYPE), false, "CONTINUOS\0SPARSE\0", GRAPH_TYPE_values, std::extent<decltype(GRAPH_TYPE_values)>::value};
		}
		const maxon::EnumInfo& PrivateGetEnumInfo_GRAPH_TYPE19(){ return enum19::GRAPH_TYPE_info; }
	}
}
#endif
