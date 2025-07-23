
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1
constexpr const maxon::Char* ConvexHullInterface::PrivateGetCppName() { return nullptr; }

struct ConvexHullInterface::MTable
{
	static MTable _instance;
	static MTable _unresolvedInstance;
	static const maxon::Char* const _ids;
	static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl);
	static const maxon::UNRESOLVED_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = false;
	PRIVATE_MAXON_SF_POINTER(ConvexHullInterface_ComputeConvexHull, ComputeConvexHull, MAXON_EXPAND_VA_ARGS, (Result<Float>), const Block<const Vector>& vertices, Float shrink, Float shrinkClamp, BaseArray<Vector>& resultVertices, BaseArray<ConvEdge>& resultEdges, BaseArray<Int>& resultFaces);
	PRIVATE_MAXON_SF_POINTER(ConvexHullInterface_ComputeConvexHull_1, ComputeConvexHull, MAXON_EXPAND_VA_ARGS, (Result<Float>), const Block<const Vector>& vertices, Float shrink, Float shrinkClamp, ConvexHullData& hull);
	template <typename IMPL> void Init()
	{
		ConvexHullInterface_ComputeConvexHull = ConvexHullInterface_ComputeConvexHull_GetPtr<IMPL>(true);
		ConvexHullInterface_ComputeConvexHull_1 = ConvexHullInterface_ComputeConvexHull_1_GetPtr<IMPL>(true);
	}
};

struct ConvexHullInterface::Hxx2
{
	class Unresolved;
	template <typename S> class Wrapper
	{
	public:
		using Implementation = S;
		static Result<Float> ConvexHullInterface_ComputeConvexHull(const Block<const Vector>& vertices, Float shrink, Float shrinkClamp, BaseArray<Vector>& resultVertices, BaseArray<ConvEdge>& resultEdges, BaseArray<Int>& resultFaces) { return S::ComputeConvexHull(vertices, shrink, shrinkClamp, resultVertices, resultEdges, resultFaces); }
		static Result<Float> ConvexHullInterface_ComputeConvexHull_1(const Block<const Vector>& vertices, Float shrink, Float shrinkClamp, ConvexHullData& hull) { return S::ComputeConvexHull(vertices, shrink, shrinkClamp, hull); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto ConvexHullInterface::ComputeConvexHull(const Block<const Vector>& vertices, Float shrink, Float shrinkClamp, BaseArray<Vector>& resultVertices, BaseArray<ConvEdge>& resultEdges, BaseArray<Int>& resultFaces) -> Result<Float>
{
	return MTable::_instance.ConvexHullInterface_ComputeConvexHull(vertices, shrink, shrinkClamp, resultVertices, resultEdges, resultFaces);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ConvexHullInterface::ComputeConvexHull(const Block<const Vector>& vertices, Float shrink, Float shrinkClamp, ConvexHullData& hull) -> Result<Float>
{
	return MTable::_instance.ConvexHullInterface_ComputeConvexHull_1(vertices, shrink, shrinkClamp, hull);
}

#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_convexhull)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_ConvexHullInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_ConvexHullInterface() { new (s_ui_maxon_ConvexHullInterface) maxon::EntityUse(ConvexHullInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/convexhull.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_ConvexHullInterface(ConvexHullInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/convexhull.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

