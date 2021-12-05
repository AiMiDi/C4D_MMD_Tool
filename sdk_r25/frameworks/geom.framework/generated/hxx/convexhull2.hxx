
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
	void (*_ConvexHullInterface_Free) (const ConvexHullInterface* object);
	ConvexHullInterface* (*_ConvexHullInterface_Alloc) (const maxon::SourceLocation& allocLocation);
	Result<Float> (*_ConvexHullInterface_ComputeConvexHull) (ConvexHullInterface* this_, const Block<const Vector>& vertices, const Float shrink, const Float shrinkClamp, BaseArray<Vector>& resultVertices, BaseArray<ConvEdge>& resultEdges, BaseArray<Int>& resultFaces);
	Result<Float> (*_ConvexHullInterface_ComputeConvexHull_1) (ConvexHullInterface* this_, const Block<const Vector>& vertices, const Float shrink, const Float shrinkClamp, ConvexHullData& hull);
	template <typename IMPL> void Init()
	{
		_ConvexHullInterface_Free = &IMPL::_ConvexHullInterface_Free;
		_ConvexHullInterface_Alloc = &IMPL::_ConvexHullInterface_Alloc;
		_ConvexHullInterface_ComputeConvexHull = &IMPL::_ConvexHullInterface_ComputeConvexHull;
		_ConvexHullInterface_ComputeConvexHull_1 = &IMPL::_ConvexHullInterface_ComputeConvexHull_1;
	}
};

struct ConvexHullInterface::Hxx2
{
	class Unresolved;
	template <typename C> class Wrapper
	{
	public:
		static void _ConvexHullInterface_Free(const ConvexHullInterface* object) { return C::Free(object); }
		static ConvexHullInterface* _ConvexHullInterface_Alloc(const maxon::SourceLocation& allocLocation) { return C::Alloc(allocLocation); }
		static Result<Float> _ConvexHullInterface_ComputeConvexHull(ConvexHullInterface* this_, const Block<const Vector>& vertices, const Float shrink, const Float shrinkClamp, BaseArray<Vector>& resultVertices, BaseArray<ConvEdge>& resultEdges, BaseArray<Int>& resultFaces) { return C::Get(this_)->ComputeConvexHull(vertices, shrink, shrinkClamp, resultVertices, resultEdges, resultFaces); }
		static Result<Float> _ConvexHullInterface_ComputeConvexHull_1(ConvexHullInterface* this_, const Block<const Vector>& vertices, const Float shrink, const Float shrinkClamp, ConvexHullData& hull) { return C::Get(this_)->ComputeConvexHull(vertices, shrink, shrinkClamp, hull); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto ConvexHullInterface::Free(const ConvexHullInterface* object) -> void
{
	return MTable::_instance._ConvexHullInterface_Free(object);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ConvexHullInterface::Alloc(const maxon::SourceLocation& allocLocation) -> ConvexHullInterface*
{
	return MTable::_instance._ConvexHullInterface_Alloc(allocLocation);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ConvexHullInterface::ComputeConvexHull(const Block<const Vector>& vertices, const Float shrink, const Float shrinkClamp, BaseArray<Vector>& resultVertices, BaseArray<ConvEdge>& resultEdges, BaseArray<Int>& resultFaces) -> Result<Float>
{
	return MTable::_instance._ConvexHullInterface_ComputeConvexHull(this, vertices, shrink, shrinkClamp, resultVertices, resultEdges, resultFaces);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ConvexHullInterface::ComputeConvexHull(const Block<const Vector>& vertices, const Float shrink, const Float shrinkClamp, ConvexHullData& hull) -> Result<Float>
{
	return MTable::_instance._ConvexHullInterface_ComputeConvexHull_1(this, vertices, shrink, shrinkClamp, hull);
}

auto ConvexHullInterface::Hxx1::Reference::Create() -> maxon::ResultMemT<ConvexHullRef>
{
	ConvexHullInterface* res_ = ConvexHullInterface::Alloc(MAXON_SOURCE_LOCATION);
	return ConvexHullRef(maxon::ForwardResultPtr<ConvexHullInterface>(res_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ConvexHullInterface::Hxx1::ReferenceFunctionsImpl<S>::ComputeConvexHull(const Block<const Vector>& vertices, const Float shrink, const Float shrinkClamp, BaseArray<Vector>& resultVertices, BaseArray<ConvEdge>& resultEdges, BaseArray<Int>& resultFaces) const -> Result<Float>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Float>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ConvexHullInterface* o_ = (ConvexHullInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance._ConvexHullInterface_ComputeConvexHull(o_, vertices, shrink, shrinkClamp, resultVertices, resultEdges, resultFaces));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ConvexHullInterface::Hxx1::ReferenceFunctionsImpl<S>::ComputeConvexHull(const Block<const Vector>& vertices, const Float shrink, const Float shrinkClamp, ConvexHullData& hull) const -> Result<Float>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Float>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ConvexHullInterface* o_ = (ConvexHullInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance._ConvexHullInterface_ComputeConvexHull_1(o_, vertices, shrink, shrinkClamp, hull));
}
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
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

