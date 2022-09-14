
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1
constexpr const maxon::Char* ConvexHullInterface::PrivateGetCppName() { return "maxon::ConvexHullRef"; }

struct ConvexHullInterface::MTable
{
	static MTable _instance;
	static MTable _unresolvedInstance;
	static const maxon::Char* const _ids;
	static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl);
	static const maxon::NULL_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = true;
	PRIVATE_MAXON_SF_POINTER(ConvexHullInterface_Free, Free, MAXON_EXPAND_VA_ARGS, (void), const ConvexHullInterface* object);
	PRIVATE_MAXON_SF_POINTER(ConvexHullInterface_Alloc, Alloc, MAXON_IGNORE_VA_ARGS, (ConvexHullInterface*), const maxon::SourceLocation& allocLocation);
	PRIVATE_MAXON_MF_POINTER(ConvexHullInterface_ComputeConvexHull, ComputeConvexHull, false, ConvexHullInterface,, (Result<Float>), const Block<const Vector>& vertices, const Float shrink, const Float shrinkClamp, BaseArray<Vector>& resultVertices, BaseArray<ConvEdge>& resultEdges, BaseArray<Int>& resultFaces);
	PRIVATE_MAXON_MF_POINTER(ConvexHullInterface_ComputeConvexHull_1, ComputeConvexHull, false, ConvexHullInterface,, (Result<Float>), const Block<const Vector>& vertices, const Float shrink, const Float shrinkClamp, ConvexHullData& hull);
	template <typename IMPL> void Init()
	{
		ConvexHullInterface_Free = ConvexHullInterface_Free_GetPtr<IMPL>(true);
		ConvexHullInterface_Alloc = ConvexHullInterface_Alloc_GetPtr<IMPL>(true);
		ConvexHullInterface_ComputeConvexHull = ConvexHullInterface_ComputeConvexHull_GetPtr<IMPL>(0, true).first;
		ConvexHullInterface_ComputeConvexHull_1 = ConvexHullInterface_ComputeConvexHull_1_GetPtr<IMPL>(0, true).first;
	}
};

struct ConvexHullInterface::Hxx2
{
	class Unresolved;
	template <typename C> class Wrapper
	{
	public:
		using Implementation = C;
		static void ConvexHullInterface_Free(const ConvexHullInterface* object) { return C::Free(object); }
		static ConvexHullInterface* ConvexHullInterface_Alloc(const maxon::SourceLocation& allocLocation) { return C::Alloc(allocLocation); }
		PRIVATE_MAXON_MF_WRAPPER(ConvexHullInterface_ComputeConvexHull, ConvexHullInterface,, (Result<Float>), const Block<const Vector>& vertices, const Float shrink, const Float shrinkClamp, BaseArray<Vector>& resultVertices, BaseArray<ConvEdge>& resultEdges, BaseArray<Int>& resultFaces) { return C::Get(PRIVATE_MAXON_MF_THIS(ConvexHullInterface))->ComputeConvexHull(vertices, shrink, shrinkClamp, resultVertices, resultEdges, resultFaces); }
		PRIVATE_MAXON_MF_WRAPPER(ConvexHullInterface_ComputeConvexHull_1, ConvexHullInterface,, (Result<Float>), const Block<const Vector>& vertices, const Float shrink, const Float shrinkClamp, ConvexHullData& hull) { return C::Get(PRIVATE_MAXON_MF_THIS(ConvexHullInterface))->ComputeConvexHull(vertices, shrink, shrinkClamp, hull); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto ConvexHullInterface::Free(const ConvexHullInterface* object) -> void
{
	return MTable::_instance.ConvexHullInterface_Free(object);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ConvexHullInterface::Alloc(const maxon::SourceLocation& allocLocation) -> ConvexHullInterface*
{
	return MTable::_instance.ConvexHullInterface_Alloc(allocLocation);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ConvexHullInterface::ComputeConvexHull(const Block<const Vector>& vertices, const Float shrink, const Float shrinkClamp, BaseArray<Vector>& resultVertices, BaseArray<ConvEdge>& resultEdges, BaseArray<Int>& resultFaces) -> Result<Float>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.ConvexHullInterface_ComputeConvexHull, vertices, shrink, shrinkClamp, resultVertices, resultEdges, resultFaces);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ConvexHullInterface::ComputeConvexHull(const Block<const Vector>& vertices, const Float shrink, const Float shrinkClamp, ConvexHullData& hull) -> Result<Float>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.ConvexHullInterface_ComputeConvexHull_1, vertices, shrink, shrinkClamp, hull);
}

auto ConvexHullInterface::Hxx1::Reference::Create() -> maxon::ResultMemT<ConvexHullRef>
{
	ConvexHullInterface* res_ = ConvexHullInterface::Alloc(MAXON_SOURCE_LOCATION);
	return ConvexHullRef(maxon::ForwardResultPtr<ConvexHullInterface>(res_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ConvexHullInterface::Hxx1::Fn<S>::ComputeConvexHull(const Block<const Vector>& vertices, const Float shrink, const Float shrinkClamp, BaseArray<Vector>& resultVertices, BaseArray<ConvEdge>& resultEdges, BaseArray<Int>& resultFaces) const -> Result<Float>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Float>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); ConvexHullInterface* o_ = (ConvexHullInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.ConvexHullInterface_ComputeConvexHull, vertices, shrink, shrinkClamp, resultVertices, resultEdges, resultFaces));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ConvexHullInterface::Hxx1::Fn<S>::ComputeConvexHull(const Block<const Vector>& vertices, const Float shrink, const Float shrinkClamp, ConvexHullData& hull) const -> Result<Float>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Float>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); ConvexHullInterface* o_ = (ConvexHullInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.ConvexHullInterface_ComputeConvexHull_1, vertices, shrink, shrinkClamp, hull));
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

