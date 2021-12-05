
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1
constexpr const maxon::Char* GradientInterface::PrivateGetCppName() { return "maxon::Gradient"; }

struct GradientInterface::MTable
{
	static MTable _instance;
	static MTable _unresolvedInstance;
	static const maxon::Char* const _ids;
	static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl);
	static const maxon::NULL_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = true;
	void (*_GradientInterface_Free) (const GradientInterface* object);
	GradientInterface* (*_GradientInterface_Alloc) (const maxon::SourceLocation& allocLocation);
	GradientInterface* (*_GradientInterface_Alloc_1) (const maxon::SourceLocation& allocLocation, const GradientInterface& object);
	Result<Gradient*> (*_GradientInterface_AllocAlphaGradient) (GradientInterface* this_);
	Gradient* (*_GradientInterface_GetAlphaGradient) (GradientInterface* this_);
	Int (*_GradientInterface_GetKnotCount) (const GradientInterface* this_);
	Result<Int> (*_GradientInterface_InsertKnot) (GradientInterface* this_, const GradientKnot& knot, Bool keepId);
	Result<void> (*_GradientInterface_RemoveKnot) (GradientInterface* this_, Int index);
	GradientKnot (*_GradientInterface_GetKnot) (const GradientInterface* this_, Int index);
	Result<void> (*_GradientInterface_SetKnot) (GradientInterface* this_, Int index, const GradientKnot& k);
	void (*_GradientInterface_ConvertToAlphaGradient) (GradientInterface* this_);
	void (*_GradientInterface_SortKnots) (GradientInterface* this_);
	Result<Bool> (*_GradientInterface_InvertKnots) (GradientInterface* this_);
	Result<Bool> (*_GradientInterface_DoubleKnots) (GradientInterface* this_);
	Bool (*_GradientInterface_DistributeKnots) (GradientInterface* this_);
	void (*_GradientInterface_Flush) (GradientInterface* this_);
	void (*_GradientInterface_SetIsAlphaGradient) (GradientInterface* this_, Bool alphaGradient);
	Bool (*_GradientInterface_IsAlphaGradient) (const GradientInterface* this_);
	COMPARERESULT (*_GradientInterface_Compare) (const GradientInterface* this_, const GradientInterface* arg2);
	HashInt (*_GradientInterface_GetHashCode) (const GradientInterface* this_);
	Result<GradientRenderData> (*_GradientInterface_InitRender) (const GradientInterface* this_, const TransformColorDelegate& transformColorDelegate);
	template <typename IMPL> void Init()
	{
		_GradientInterface_Free = &IMPL::_GradientInterface_Free;
		_GradientInterface_Alloc = &IMPL::_GradientInterface_Alloc;
		_GradientInterface_Alloc_1 = &IMPL::_GradientInterface_Alloc_1;
		_GradientInterface_AllocAlphaGradient = &IMPL::_GradientInterface_AllocAlphaGradient;
		_GradientInterface_GetAlphaGradient = &IMPL::_GradientInterface_GetAlphaGradient;
		_GradientInterface_GetKnotCount = &IMPL::_GradientInterface_GetKnotCount;
		_GradientInterface_InsertKnot = &IMPL::_GradientInterface_InsertKnot;
		_GradientInterface_RemoveKnot = &IMPL::_GradientInterface_RemoveKnot;
		_GradientInterface_GetKnot = &IMPL::_GradientInterface_GetKnot;
		_GradientInterface_SetKnot = &IMPL::_GradientInterface_SetKnot;
		_GradientInterface_ConvertToAlphaGradient = &IMPL::_GradientInterface_ConvertToAlphaGradient;
		_GradientInterface_SortKnots = &IMPL::_GradientInterface_SortKnots;
		_GradientInterface_InvertKnots = &IMPL::_GradientInterface_InvertKnots;
		_GradientInterface_DoubleKnots = &IMPL::_GradientInterface_DoubleKnots;
		_GradientInterface_DistributeKnots = &IMPL::_GradientInterface_DistributeKnots;
		_GradientInterface_Flush = &IMPL::_GradientInterface_Flush;
		_GradientInterface_SetIsAlphaGradient = &IMPL::_GradientInterface_SetIsAlphaGradient;
		_GradientInterface_IsAlphaGradient = &IMPL::_GradientInterface_IsAlphaGradient;
		_GradientInterface_Compare = &IMPL::_GradientInterface_Compare;
		_GradientInterface_GetHashCode = &IMPL::_GradientInterface_GetHashCode;
		_GradientInterface_InitRender = &IMPL::_GradientInterface_InitRender;
	}
};

struct GradientInterface::Hxx2
{
	class Unresolved;
	template <typename C> class Wrapper
	{
	public:
		static void _GradientInterface_Free(const GradientInterface* object) { return C::Free(object); }
		static GradientInterface* _GradientInterface_Alloc(const maxon::SourceLocation& allocLocation) { return C::Alloc(allocLocation); }
		static GradientInterface* _GradientInterface_Alloc_1(const maxon::SourceLocation& allocLocation, const GradientInterface& object) { return C::Alloc(allocLocation, ((const C&) object)); }
		static Result<Gradient*> _GradientInterface_AllocAlphaGradient(GradientInterface* this_) { return C::Get(this_)->AllocAlphaGradient(); }
		static Gradient* _GradientInterface_GetAlphaGradient(GradientInterface* this_) { return C::Get(this_)->GetAlphaGradient(); }
		static Int _GradientInterface_GetKnotCount(const GradientInterface* this_) { return C::Get(this_)->GetKnotCount(); }
		static Result<Int> _GradientInterface_InsertKnot(GradientInterface* this_, const GradientKnot& knot, Bool keepId) { return C::Get(this_)->InsertKnot(knot, keepId); }
		static Result<void> _GradientInterface_RemoveKnot(GradientInterface* this_, Int index) { return C::Get(this_)->RemoveKnot(index); }
		static GradientKnot _GradientInterface_GetKnot(const GradientInterface* this_, Int index) { return C::Get(this_)->GetKnot(index); }
		static Result<void> _GradientInterface_SetKnot(GradientInterface* this_, Int index, const GradientKnot& k) { return C::Get(this_)->SetKnot(index, k); }
		static void _GradientInterface_ConvertToAlphaGradient(GradientInterface* this_) { return C::Get(this_)->ConvertToAlphaGradient(); }
		static void _GradientInterface_SortKnots(GradientInterface* this_) { return C::Get(this_)->SortKnots(); }
		static Result<Bool> _GradientInterface_InvertKnots(GradientInterface* this_) { return C::Get(this_)->InvertKnots(); }
		static Result<Bool> _GradientInterface_DoubleKnots(GradientInterface* this_) { return C::Get(this_)->DoubleKnots(); }
		static Bool _GradientInterface_DistributeKnots(GradientInterface* this_) { return C::Get(this_)->DistributeKnots(); }
		static void _GradientInterface_Flush(GradientInterface* this_) { return C::Get(this_)->Flush(); }
		static void _GradientInterface_SetIsAlphaGradient(GradientInterface* this_, Bool alphaGradient) { return C::Get(this_)->SetIsAlphaGradient(alphaGradient); }
		static Bool _GradientInterface_IsAlphaGradient(const GradientInterface* this_) { return C::Get(this_)->IsAlphaGradient(); }
		static COMPARERESULT _GradientInterface_Compare(const GradientInterface* this_, const GradientInterface* arg2) { return C::Get(this_)->Compare(arg2); }
		static HashInt _GradientInterface_GetHashCode(const GradientInterface* this_) { return C::Get(this_)->GetHashCode(); }
		static Result<GradientRenderData> _GradientInterface_InitRender(const GradientInterface* this_, const TransformColorDelegate& transformColorDelegate) { return C::Get(this_)->InitRender(transformColorDelegate); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto GradientInterface::Free(const GradientInterface* object) -> void
{
	return MTable::_instance._GradientInterface_Free(object);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GradientInterface::Alloc(const maxon::SourceLocation& allocLocation) -> GradientInterface*
{
	return MTable::_instance._GradientInterface_Alloc(allocLocation);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GradientInterface::Alloc(const maxon::SourceLocation& allocLocation, const GradientInterface& object) -> GradientInterface*
{
	return MTable::_instance._GradientInterface_Alloc_1(allocLocation, object);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GradientInterface::AllocAlphaGradient() -> Result<Gradient*>
{
	return MTable::_instance._GradientInterface_AllocAlphaGradient(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GradientInterface::GetAlphaGradient() -> Gradient*
{
	return MTable::_instance._GradientInterface_GetAlphaGradient(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GradientInterface::GetKnotCount() const -> Int
{
	return MTable::_instance._GradientInterface_GetKnotCount(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GradientInterface::InsertKnot(const GradientKnot& knot, Bool keepId) -> Result<Int>
{
	return MTable::_instance._GradientInterface_InsertKnot(this, knot, keepId);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GradientInterface::RemoveKnot(Int index) -> Result<void>
{
	return MTable::_instance._GradientInterface_RemoveKnot(this, index);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GradientInterface::GetKnot(Int index) const -> GradientKnot
{
	return MTable::_instance._GradientInterface_GetKnot(this, index);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GradientInterface::SetKnot(Int index, const GradientKnot& k) -> Result<void>
{
	return MTable::_instance._GradientInterface_SetKnot(this, index, k);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GradientInterface::ConvertToAlphaGradient() -> void
{
	return MTable::_instance._GradientInterface_ConvertToAlphaGradient(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GradientInterface::SortKnots() -> void
{
	return MTable::_instance._GradientInterface_SortKnots(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GradientInterface::InvertKnots() -> Result<Bool>
{
	return MTable::_instance._GradientInterface_InvertKnots(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GradientInterface::DoubleKnots() -> Result<Bool>
{
	return MTable::_instance._GradientInterface_DoubleKnots(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GradientInterface::DistributeKnots() -> Bool
{
	return MTable::_instance._GradientInterface_DistributeKnots(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GradientInterface::Flush() -> void
{
	return MTable::_instance._GradientInterface_Flush(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GradientInterface::SetIsAlphaGradient(Bool alphaGradient) -> void
{
	return MTable::_instance._GradientInterface_SetIsAlphaGradient(this, alphaGradient);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GradientInterface::IsAlphaGradient() const -> Bool
{
	return MTable::_instance._GradientInterface_IsAlphaGradient(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GradientInterface::Compare(const GradientInterface* arg2) const -> COMPARERESULT
{
	return MTable::_instance._GradientInterface_Compare(this, arg2);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GradientInterface::GetHashCode() const -> HashInt
{
	return MTable::_instance._GradientInterface_GetHashCode(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GradientInterface::InitRender(const TransformColorDelegate& transformColorDelegate) const -> Result<GradientRenderData>
{
	return MTable::_instance._GradientInterface_InitRender(this, transformColorDelegate);
}

auto GradientInterface::Hxx1::Reference::Create() -> maxon::ResultMemT<Gradient>
{
	GradientInterface* res_ = GradientInterface::Alloc(MAXON_SOURCE_LOCATION);
	return Gradient(maxon::ForwardResultPtr<GradientInterface>(res_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto GradientInterface::Hxx1::ReferenceFunctionsImpl<S>::AllocAlphaGradient() const -> Result<Gradient*>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Gradient*>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); GradientInterface* o_ = (GradientInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance._GradientInterface_AllocAlphaGradient(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto GradientInterface::Hxx1::COWReferenceFunctionsImpl<S>::AllocAlphaGradient() -> Result<Gradient*>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Gradient*>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); GradientInterface* o_ = (GradientInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (MTable::_instance._GradientInterface_AllocAlphaGradient(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto GradientInterface::Hxx1::ReferenceFunctionsImpl<S>::GetAlphaGradient() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Gradient*>, Gradient*>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Gradient*>, Gradient*>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); GradientInterface* o_ = (GradientInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return nullptr; } 
	return (MTable::_instance._GradientInterface_GetAlphaGradient(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto GradientInterface::Hxx1::COWReferenceFunctionsImpl<S>::GetAlphaGradient() -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Gradient*, maxon::Result<Gradient*>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Gradient*, maxon::Result<Gradient*>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); GradientInterface* o_ = (GradientInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (MTable::_instance._GradientInterface_GetAlphaGradient(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto GradientInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetKnotCount() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const GradientInterface* o_ = (const GradientInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = GradientInterface::NullValuePtr(); if (!o_) return 0; } 
	return (MTable::_instance._GradientInterface_GetKnotCount(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto GradientInterface::Hxx1::ReferenceFunctionsImpl<S>::InsertKnot(const GradientKnot& knot, Bool keepId) const -> Result<Int>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Int>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); GradientInterface* o_ = (GradientInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance._GradientInterface_InsertKnot(o_, knot, keepId));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto GradientInterface::Hxx1::COWReferenceFunctionsImpl<S>::InsertKnot(const GradientKnot& knot, Bool keepId) -> Result<Int>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Int>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); GradientInterface* o_ = (GradientInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (MTable::_instance._GradientInterface_InsertKnot(o_, knot, keepId));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto GradientInterface::Hxx1::ReferenceFunctionsImpl<S>::RemoveKnot(Int index) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); GradientInterface* o_ = (GradientInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance._GradientInterface_RemoveKnot(o_, index));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto GradientInterface::Hxx1::COWReferenceFunctionsImpl<S>::RemoveKnot(Int index) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); GradientInterface* o_ = (GradientInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (MTable::_instance._GradientInterface_RemoveKnot(o_, index));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto GradientInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetKnot(Int index) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<GradientKnot>, GradientKnot>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<GradientKnot>, GradientKnot>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const GradientInterface* o_ = (const GradientInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = GradientInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<GradientKnot>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (MTable::_instance._GradientInterface_GetKnot(o_, index));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto GradientInterface::Hxx1::ReferenceFunctionsImpl<S>::SetKnot(Int index, const GradientKnot& k) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); GradientInterface* o_ = (GradientInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance._GradientInterface_SetKnot(o_, index, k));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto GradientInterface::Hxx1::COWReferenceFunctionsImpl<S>::SetKnot(Int index, const GradientKnot& k) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); GradientInterface* o_ = (GradientInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (MTable::_instance._GradientInterface_SetKnot(o_, index, k));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto GradientInterface::Hxx1::ReferenceFunctionsImpl<S>::ConvertToAlphaGradient() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); GradientInterface* o_ = (GradientInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { DebugStop(); return maxon::PrivateLogNullptrError(); } 
	MTable::_instance._GradientInterface_ConvertToAlphaGradient(o_);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto GradientInterface::Hxx1::COWReferenceFunctionsImpl<S>::ConvertToAlphaGradient() -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); GradientInterface* o_ = (GradientInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	MTable::_instance._GradientInterface_ConvertToAlphaGradient(o_);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto GradientInterface::Hxx1::ReferenceFunctionsImpl<S>::SortKnots() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); GradientInterface* o_ = (GradientInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { DebugStop(); return maxon::PrivateLogNullptrError(); } 
	MTable::_instance._GradientInterface_SortKnots(o_);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto GradientInterface::Hxx1::COWReferenceFunctionsImpl<S>::SortKnots() -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); GradientInterface* o_ = (GradientInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	MTable::_instance._GradientInterface_SortKnots(o_);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto GradientInterface::Hxx1::ReferenceFunctionsImpl<S>::InvertKnots() const -> Result<Bool>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Bool>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); GradientInterface* o_ = (GradientInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance._GradientInterface_InvertKnots(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto GradientInterface::Hxx1::COWReferenceFunctionsImpl<S>::InvertKnots() -> Result<Bool>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Bool>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); GradientInterface* o_ = (GradientInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (MTable::_instance._GradientInterface_InvertKnots(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto GradientInterface::Hxx1::ReferenceFunctionsImpl<S>::DoubleKnots() const -> Result<Bool>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Bool>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); GradientInterface* o_ = (GradientInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance._GradientInterface_DoubleKnots(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto GradientInterface::Hxx1::COWReferenceFunctionsImpl<S>::DoubleKnots() -> Result<Bool>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Bool>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); GradientInterface* o_ = (GradientInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (MTable::_instance._GradientInterface_DoubleKnots(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto GradientInterface::Hxx1::ReferenceFunctionsImpl<S>::DistributeKnots() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); GradientInterface* o_ = (GradientInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateLogNullptrError(false); } 
	return (MTable::_instance._GradientInterface_DistributeKnots(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto GradientInterface::Hxx1::COWReferenceFunctionsImpl<S>::DistributeKnots() -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Bool, maxon::Result<Bool>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Bool, maxon::Result<Bool>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); GradientInterface* o_ = (GradientInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (MTable::_instance._GradientInterface_DistributeKnots(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto GradientInterface::Hxx1::ReferenceFunctionsImpl<S>::Flush() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); GradientInterface* o_ = (GradientInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { DebugStop(); return maxon::PrivateLogNullptrError(); } 
	MTable::_instance._GradientInterface_Flush(o_);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto GradientInterface::Hxx1::COWReferenceFunctionsImpl<S>::Flush() -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); GradientInterface* o_ = (GradientInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	MTable::_instance._GradientInterface_Flush(o_);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto GradientInterface::Hxx1::ReferenceFunctionsImpl<S>::SetIsAlphaGradient(Bool alphaGradient) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); GradientInterface* o_ = (GradientInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { DebugStop(); return maxon::PrivateLogNullptrError(); } 
	MTable::_instance._GradientInterface_SetIsAlphaGradient(o_, alphaGradient);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto GradientInterface::Hxx1::COWReferenceFunctionsImpl<S>::SetIsAlphaGradient(Bool alphaGradient) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); GradientInterface* o_ = (GradientInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	MTable::_instance._GradientInterface_SetIsAlphaGradient(o_, alphaGradient);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto GradientInterface::Hxx1::ConstReferenceFunctionsImpl<S>::IsAlphaGradient() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const GradientInterface* o_ = (const GradientInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = GradientInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (MTable::_instance._GradientInterface_IsAlphaGradient(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto GradientInterface::Hxx1::ConstReferenceFunctionsImpl<S>::Compare(const GradientInterface* arg2) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<COMPARERESULT>, COMPARERESULT>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<COMPARERESULT>, COMPARERESULT>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const GradientInterface* o_ = (const GradientInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = GradientInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<COMPARERESULT>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (MTable::_instance._GradientInterface_Compare(o_, arg2));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto GradientInterface::Hxx1::ConstReferenceFunctionsImpl<S>::InitRender(const TransformColorDelegate& transformColorDelegate) const -> Result<GradientRenderData>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<GradientRenderData>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const GradientInterface* o_ = (const GradientInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = GradientInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance._GradientInterface_InitRender(o_, transformColorDelegate));
}
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_GradientInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_GradientInterface() { new (s_ui_maxon_GradientInterface) maxon::EntityUse(GradientInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/gradient.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_GradientInterface(GradientInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/gradient.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
constexpr const maxon::Char* GradientRenderDataInterface::PrivateGetCppName() { return "maxon::GradientRenderData"; }

struct GradientRenderDataInterface::MTable
{
	static MTable _instance;
	static MTable _unresolvedInstance;
	static const maxon::Char* const _ids;
	static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl);
	static const maxon::NULL_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = true;
	void (*_GradientRenderDataInterface_Free) (const GradientRenderDataInterface* object);
	GradientRenderDataInterface* (*_GradientRenderDataInterface_Alloc) (const maxon::SourceLocation& allocLocation);
	GradientRenderDataInterface* (*_GradientRenderDataInterface_Alloc_1) (const maxon::SourceLocation& allocLocation, const GradientRenderDataInterface& object);
	Color (*_GradientRenderDataInterface_CalcGradientPixel) (const GradientRenderDataInterface* this_, Float pos);
	Int (*_GradientRenderDataInterface_GetKnotCount) (const GradientRenderDataInterface* this_);
	const GradientKnot* (*_GradientRenderDataInterface_GetKnot) (const GradientRenderDataInterface* this_, Int index);
	const BaseArray<GradientKnot>& (*_GradientRenderDataInterface_GetKnots) (const GradientRenderDataInterface* this_);
	COMPARERESULT (*_GradientRenderDataInterface_Compare) (const GradientRenderDataInterface* this_, const GradientRenderDataInterface* arg2);
	HashInt (*_GradientRenderDataInterface_GetHashCode) (const GradientRenderDataInterface* this_);
	template <typename IMPL> void Init()
	{
		_GradientRenderDataInterface_Free = &IMPL::_GradientRenderDataInterface_Free;
		_GradientRenderDataInterface_Alloc = &IMPL::_GradientRenderDataInterface_Alloc;
		_GradientRenderDataInterface_Alloc_1 = &IMPL::_GradientRenderDataInterface_Alloc_1;
		_GradientRenderDataInterface_CalcGradientPixel = &IMPL::_GradientRenderDataInterface_CalcGradientPixel;
		_GradientRenderDataInterface_GetKnotCount = &IMPL::_GradientRenderDataInterface_GetKnotCount;
		_GradientRenderDataInterface_GetKnot = &IMPL::_GradientRenderDataInterface_GetKnot;
		_GradientRenderDataInterface_GetKnots = &IMPL::_GradientRenderDataInterface_GetKnots;
		_GradientRenderDataInterface_Compare = &IMPL::_GradientRenderDataInterface_Compare;
		_GradientRenderDataInterface_GetHashCode = &IMPL::_GradientRenderDataInterface_GetHashCode;
	}
};

struct GradientRenderDataInterface::Hxx2
{
	class Unresolved;
	template <typename C> class Wrapper
	{
	public:
		static void _GradientRenderDataInterface_Free(const GradientRenderDataInterface* object) { return C::Free(object); }
		static GradientRenderDataInterface* _GradientRenderDataInterface_Alloc(const maxon::SourceLocation& allocLocation) { return C::Alloc(allocLocation); }
		static GradientRenderDataInterface* _GradientRenderDataInterface_Alloc_1(const maxon::SourceLocation& allocLocation, const GradientRenderDataInterface& object) { return C::Alloc(allocLocation, ((const C&) object)); }
		static Color _GradientRenderDataInterface_CalcGradientPixel(const GradientRenderDataInterface* this_, Float pos) { return C::Get(this_)->CalcGradientPixel(pos); }
		static Int _GradientRenderDataInterface_GetKnotCount(const GradientRenderDataInterface* this_) { return C::Get(this_)->GetKnotCount(); }
		static const GradientKnot* _GradientRenderDataInterface_GetKnot(const GradientRenderDataInterface* this_, Int index) { return C::Get(this_)->GetKnot(index); }
		static const BaseArray<GradientKnot>& _GradientRenderDataInterface_GetKnots(const GradientRenderDataInterface* this_) { return C::Get(this_)->GetKnots(); }
		static COMPARERESULT _GradientRenderDataInterface_Compare(const GradientRenderDataInterface* this_, const GradientRenderDataInterface* arg2) { return C::Get(this_)->Compare(arg2); }
		static HashInt _GradientRenderDataInterface_GetHashCode(const GradientRenderDataInterface* this_) { return C::Get(this_)->GetHashCode(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto GradientRenderDataInterface::Free(const GradientRenderDataInterface* object) -> void
{
	return MTable::_instance._GradientRenderDataInterface_Free(object);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GradientRenderDataInterface::Alloc(const maxon::SourceLocation& allocLocation) -> GradientRenderDataInterface*
{
	return MTable::_instance._GradientRenderDataInterface_Alloc(allocLocation);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GradientRenderDataInterface::Alloc(const maxon::SourceLocation& allocLocation, const GradientRenderDataInterface& object) -> GradientRenderDataInterface*
{
	return MTable::_instance._GradientRenderDataInterface_Alloc_1(allocLocation, object);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GradientRenderDataInterface::CalcGradientPixel(Float pos) const -> Color
{
	return MTable::_instance._GradientRenderDataInterface_CalcGradientPixel(this, pos);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GradientRenderDataInterface::GetKnotCount() const -> Int
{
	return MTable::_instance._GradientRenderDataInterface_GetKnotCount(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GradientRenderDataInterface::GetKnot(Int index) const -> const GradientKnot*
{
	return MTable::_instance._GradientRenderDataInterface_GetKnot(this, index);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GradientRenderDataInterface::GetKnots() const -> const BaseArray<GradientKnot>&
{
	return MTable::_instance._GradientRenderDataInterface_GetKnots(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GradientRenderDataInterface::Compare(const GradientRenderDataInterface* arg2) const -> COMPARERESULT
{
	return MTable::_instance._GradientRenderDataInterface_Compare(this, arg2);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GradientRenderDataInterface::GetHashCode() const -> HashInt
{
	return MTable::_instance._GradientRenderDataInterface_GetHashCode(this);
}

auto GradientRenderDataInterface::Hxx1::Reference::Create() -> maxon::ResultMemT<GradientRenderData>
{
	GradientRenderDataInterface* res_ = GradientRenderDataInterface::Alloc(MAXON_SOURCE_LOCATION);
	return GradientRenderData(maxon::ForwardResultPtr<GradientRenderDataInterface>(res_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto GradientRenderDataInterface::Hxx1::ConstReferenceFunctionsImpl<S>::CalcGradientPixel(Float pos) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Color>, Color>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Color>, Color>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const GradientRenderDataInterface* o_ = (const GradientRenderDataInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = GradientRenderDataInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<Color>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (MTable::_instance._GradientRenderDataInterface_CalcGradientPixel(o_, pos));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto GradientRenderDataInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetKnotCount() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const GradientRenderDataInterface* o_ = (const GradientRenderDataInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = GradientRenderDataInterface::NullValuePtr(); if (!o_) return 0; } 
	return (MTable::_instance._GradientRenderDataInterface_GetKnotCount(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto GradientRenderDataInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetKnot(Int index) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const GradientKnot*>, const GradientKnot*>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const GradientKnot*>, const GradientKnot*>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const GradientRenderDataInterface* o_ = (const GradientRenderDataInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = GradientRenderDataInterface::NullValuePtr(); if (!o_) return nullptr; } 
	return (MTable::_instance._GradientRenderDataInterface_GetKnot(o_, index));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto GradientRenderDataInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetKnots() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const BaseArray<GradientKnot>&>, const BaseArray<GradientKnot>&>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const BaseArray<GradientKnot>&>, const BaseArray<GradientKnot>&>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const GradientRenderDataInterface* o_ = (const GradientRenderDataInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = GradientRenderDataInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<const BaseArray<GradientKnot>&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (MTable::_instance._GradientRenderDataInterface_GetKnots(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto GradientRenderDataInterface::Hxx1::ConstReferenceFunctionsImpl<S>::Compare(const GradientRenderDataInterface* arg2) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<COMPARERESULT>, COMPARERESULT>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<COMPARERESULT>, COMPARERESULT>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const GradientRenderDataInterface* o_ = (const GradientRenderDataInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = GradientRenderDataInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<COMPARERESULT>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (MTable::_instance._GradientRenderDataInterface_Compare(o_, arg2));
}
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_GradientRenderDataInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_GradientRenderDataInterface() { new (s_ui_maxon_GradientRenderDataInterface) maxon::EntityUse(GradientRenderDataInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/gradient.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_GradientRenderDataInterface(GradientRenderDataInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/gradient.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

