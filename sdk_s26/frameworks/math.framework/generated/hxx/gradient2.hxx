
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
	void (*GradientInterface_Free) (const GradientInterface* object);
	GradientInterface* (*GradientInterface_Alloc) (const maxon::SourceLocation& allocLocation);
	GradientInterface* (*GradientInterface_Alloc_1) (const maxon::SourceLocation& allocLocation, const GradientInterface& object);
	Result<Gradient*> (*GradientInterface_AllocAlphaGradient) (GradientInterface* this_);
	Gradient* (*GradientInterface_GetAlphaGradient) (GradientInterface* this_);
	Int (*GradientInterface_GetKnotCount) (const GradientInterface* this_);
	Result<Int> (*GradientInterface_InsertKnot) (GradientInterface* this_, const GradientKnot& knot, Bool keepId);
	Result<void> (*GradientInterface_RemoveKnot) (GradientInterface* this_, Int index);
	GradientKnot (*GradientInterface_GetKnot) (const GradientInterface* this_, Int index);
	Result<void> (*GradientInterface_SetKnot) (GradientInterface* this_, Int index, const GradientKnot& k);
	void (*GradientInterface_ConvertToAlphaGradient) (GradientInterface* this_);
	void (*GradientInterface_SortKnots) (GradientInterface* this_);
	Result<Bool> (*GradientInterface_InvertKnots) (GradientInterface* this_);
	Result<Bool> (*GradientInterface_DoubleKnots) (GradientInterface* this_);
	Bool (*GradientInterface_DistributeKnots) (GradientInterface* this_);
	void (*GradientInterface_Flush) (GradientInterface* this_);
	void (*GradientInterface_SetIsAlphaGradient) (GradientInterface* this_, Bool alphaGradient);
	Bool (*GradientInterface_IsAlphaGradient) (const GradientInterface* this_);
	COMPARERESULT (*GradientInterface_Compare) (const GradientInterface* this_, const GradientInterface* arg2);
	HashInt (*GradientInterface_GetHashCode) (const GradientInterface* this_);
	Result<GradientRenderData> (*GradientInterface_InitRender) (const GradientInterface* this_, const TransformColorDelegate& transformColorDelegate);
	template <typename IMPL> void Init()
	{
		GradientInterface_Free = &IMPL::GradientInterface_Free;
		GradientInterface_Alloc = &IMPL::GradientInterface_Alloc;
		GradientInterface_Alloc_1 = &IMPL::GradientInterface_Alloc_1;
		GradientInterface_AllocAlphaGradient = &IMPL::GradientInterface_AllocAlphaGradient;
		GradientInterface_GetAlphaGradient = &IMPL::GradientInterface_GetAlphaGradient;
		GradientInterface_GetKnotCount = &IMPL::GradientInterface_GetKnotCount;
		GradientInterface_InsertKnot = &IMPL::GradientInterface_InsertKnot;
		GradientInterface_RemoveKnot = &IMPL::GradientInterface_RemoveKnot;
		GradientInterface_GetKnot = &IMPL::GradientInterface_GetKnot;
		GradientInterface_SetKnot = &IMPL::GradientInterface_SetKnot;
		GradientInterface_ConvertToAlphaGradient = &IMPL::GradientInterface_ConvertToAlphaGradient;
		GradientInterface_SortKnots = &IMPL::GradientInterface_SortKnots;
		GradientInterface_InvertKnots = &IMPL::GradientInterface_InvertKnots;
		GradientInterface_DoubleKnots = &IMPL::GradientInterface_DoubleKnots;
		GradientInterface_DistributeKnots = &IMPL::GradientInterface_DistributeKnots;
		GradientInterface_Flush = &IMPL::GradientInterface_Flush;
		GradientInterface_SetIsAlphaGradient = &IMPL::GradientInterface_SetIsAlphaGradient;
		GradientInterface_IsAlphaGradient = &IMPL::GradientInterface_IsAlphaGradient;
		GradientInterface_Compare = &IMPL::GradientInterface_Compare;
		GradientInterface_GetHashCode = &IMPL::GradientInterface_GetHashCode;
		GradientInterface_InitRender = &IMPL::GradientInterface_InitRender;
	}
};

struct GradientInterface::Hxx2
{
	class Unresolved;
	template <typename C> class Wrapper
	{
	public:
		static void GradientInterface_Free(const GradientInterface* object) { return C::Free(object); }
		static GradientInterface* GradientInterface_Alloc(const maxon::SourceLocation& allocLocation) { return C::Alloc(allocLocation); }
		static GradientInterface* GradientInterface_Alloc_1(const maxon::SourceLocation& allocLocation, const GradientInterface& object) { return C::Alloc(allocLocation, ((const C&) object)); }
		static Result<Gradient*> GradientInterface_AllocAlphaGradient(GradientInterface* this_) { return C::Get(this_)->AllocAlphaGradient(); }
		static Gradient* GradientInterface_GetAlphaGradient(GradientInterface* this_) { return C::Get(this_)->GetAlphaGradient(); }
		static Int GradientInterface_GetKnotCount(const GradientInterface* this_) { return C::Get(this_)->GetKnotCount(); }
		static Result<Int> GradientInterface_InsertKnot(GradientInterface* this_, const GradientKnot& knot, Bool keepId) { return C::Get(this_)->InsertKnot(knot, keepId); }
		static Result<void> GradientInterface_RemoveKnot(GradientInterface* this_, Int index) { return C::Get(this_)->RemoveKnot(index); }
		static GradientKnot GradientInterface_GetKnot(const GradientInterface* this_, Int index) { return C::Get(this_)->GetKnot(index); }
		static Result<void> GradientInterface_SetKnot(GradientInterface* this_, Int index, const GradientKnot& k) { return C::Get(this_)->SetKnot(index, k); }
		static void GradientInterface_ConvertToAlphaGradient(GradientInterface* this_) { return C::Get(this_)->ConvertToAlphaGradient(); }
		static void GradientInterface_SortKnots(GradientInterface* this_) { return C::Get(this_)->SortKnots(); }
		static Result<Bool> GradientInterface_InvertKnots(GradientInterface* this_) { return C::Get(this_)->InvertKnots(); }
		static Result<Bool> GradientInterface_DoubleKnots(GradientInterface* this_) { return C::Get(this_)->DoubleKnots(); }
		static Bool GradientInterface_DistributeKnots(GradientInterface* this_) { return C::Get(this_)->DistributeKnots(); }
		static void GradientInterface_Flush(GradientInterface* this_) { return C::Get(this_)->Flush(); }
		static void GradientInterface_SetIsAlphaGradient(GradientInterface* this_, Bool alphaGradient) { return C::Get(this_)->SetIsAlphaGradient(alphaGradient); }
		static Bool GradientInterface_IsAlphaGradient(const GradientInterface* this_) { return C::Get(this_)->IsAlphaGradient(); }
		static COMPARERESULT GradientInterface_Compare(const GradientInterface* this_, const GradientInterface* arg2) { return C::Get(this_)->Compare(arg2); }
		static HashInt GradientInterface_GetHashCode(const GradientInterface* this_) { return C::Get(this_)->GetHashCode(); }
		static Result<GradientRenderData> GradientInterface_InitRender(const GradientInterface* this_, const TransformColorDelegate& transformColorDelegate) { return C::Get(this_)->InitRender(transformColorDelegate); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto GradientInterface::Free(const GradientInterface* object) -> void
{
	return MTable::_instance.GradientInterface_Free(object);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GradientInterface::Alloc(const maxon::SourceLocation& allocLocation) -> GradientInterface*
{
	return MTable::_instance.GradientInterface_Alloc(allocLocation);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GradientInterface::Alloc(const maxon::SourceLocation& allocLocation, const GradientInterface& object) -> GradientInterface*
{
	return MTable::_instance.GradientInterface_Alloc_1(allocLocation, object);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GradientInterface::AllocAlphaGradient() -> Result<Gradient*>
{
	return MTable::_instance.GradientInterface_AllocAlphaGradient(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GradientInterface::GetAlphaGradient() -> Gradient*
{
	return MTable::_instance.GradientInterface_GetAlphaGradient(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GradientInterface::GetKnotCount() const -> Int
{
	return MTable::_instance.GradientInterface_GetKnotCount(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GradientInterface::InsertKnot(const GradientKnot& knot, Bool keepId) -> Result<Int>
{
	return MTable::_instance.GradientInterface_InsertKnot(this, knot, keepId);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GradientInterface::RemoveKnot(Int index) -> Result<void>
{
	return MTable::_instance.GradientInterface_RemoveKnot(this, index);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GradientInterface::GetKnot(Int index) const -> GradientKnot
{
	return MTable::_instance.GradientInterface_GetKnot(this, index);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GradientInterface::SetKnot(Int index, const GradientKnot& k) -> Result<void>
{
	return MTable::_instance.GradientInterface_SetKnot(this, index, k);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GradientInterface::ConvertToAlphaGradient() -> void
{
	return MTable::_instance.GradientInterface_ConvertToAlphaGradient(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GradientInterface::SortKnots() -> void
{
	return MTable::_instance.GradientInterface_SortKnots(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GradientInterface::InvertKnots() -> Result<Bool>
{
	return MTable::_instance.GradientInterface_InvertKnots(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GradientInterface::DoubleKnots() -> Result<Bool>
{
	return MTable::_instance.GradientInterface_DoubleKnots(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GradientInterface::DistributeKnots() -> Bool
{
	return MTable::_instance.GradientInterface_DistributeKnots(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GradientInterface::Flush() -> void
{
	return MTable::_instance.GradientInterface_Flush(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GradientInterface::SetIsAlphaGradient(Bool alphaGradient) -> void
{
	return MTable::_instance.GradientInterface_SetIsAlphaGradient(this, alphaGradient);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GradientInterface::IsAlphaGradient() const -> Bool
{
	return MTable::_instance.GradientInterface_IsAlphaGradient(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GradientInterface::Compare(const GradientInterface* arg2) const -> COMPARERESULT
{
	return MTable::_instance.GradientInterface_Compare(this, arg2);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GradientInterface::GetHashCode() const -> HashInt
{
	return MTable::_instance.GradientInterface_GetHashCode(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GradientInterface::InitRender(const TransformColorDelegate& transformColorDelegate) const -> Result<GradientRenderData>
{
	return MTable::_instance.GradientInterface_InitRender(this, transformColorDelegate);
}

auto GradientInterface::Hxx1::Reference::Create() -> maxon::ResultMemT<Gradient>
{
	GradientInterface* res_ = GradientInterface::Alloc(MAXON_SOURCE_LOCATION);
	return Gradient(maxon::ForwardResultPtr<GradientInterface>(res_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto GradientInterface::Hxx1::Fn<S>::AllocAlphaGradient() const -> Result<Gradient*>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Gradient*>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); GradientInterface* o_ = (GradientInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.GradientInterface_AllocAlphaGradient(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto GradientInterface::Hxx1::COWFn<S>::AllocAlphaGradient() -> Result<Gradient*>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Gradient*>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); GradientInterface* o_ = (GradientInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (MTable::_instance.GradientInterface_AllocAlphaGradient(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto GradientInterface::Hxx1::Fn<S>::GetAlphaGradient() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Gradient*>, Gradient*>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Gradient*>, Gradient*>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); GradientInterface* o_ = (GradientInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return nullptr; } 
	return (MTable::_instance.GradientInterface_GetAlphaGradient(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto GradientInterface::Hxx1::COWFn<S>::GetAlphaGradient() -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Gradient*, maxon::Result<Gradient*>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Gradient*, maxon::Result<Gradient*>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); GradientInterface* o_ = (GradientInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (MTable::_instance.GradientInterface_GetAlphaGradient(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto GradientInterface::Hxx1::ConstFn<S>::GetKnotCount() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const GradientInterface* o_ = (const GradientInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = GradientInterface::NullValuePtr(); if (!o_) return 0; } 
	return (MTable::_instance.GradientInterface_GetKnotCount(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto GradientInterface::Hxx1::Fn<S>::InsertKnot(const GradientKnot& knot, Bool keepId) const -> Result<Int>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Int>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); GradientInterface* o_ = (GradientInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.GradientInterface_InsertKnot(o_, knot, keepId));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto GradientInterface::Hxx1::COWFn<S>::InsertKnot(const GradientKnot& knot, Bool keepId) -> Result<Int>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Int>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); GradientInterface* o_ = (GradientInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (MTable::_instance.GradientInterface_InsertKnot(o_, knot, keepId));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto GradientInterface::Hxx1::Fn<S>::RemoveKnot(Int index) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); GradientInterface* o_ = (GradientInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.GradientInterface_RemoveKnot(o_, index));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto GradientInterface::Hxx1::COWFn<S>::RemoveKnot(Int index) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); GradientInterface* o_ = (GradientInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (MTable::_instance.GradientInterface_RemoveKnot(o_, index));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto GradientInterface::Hxx1::ConstFn<S>::GetKnot(Int index) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<GradientKnot>, GradientKnot>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<GradientKnot>, GradientKnot>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const GradientInterface* o_ = (const GradientInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = GradientInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<GradientKnot>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (MTable::_instance.GradientInterface_GetKnot(o_, index));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto GradientInterface::Hxx1::Fn<S>::SetKnot(Int index, const GradientKnot& k) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); GradientInterface* o_ = (GradientInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.GradientInterface_SetKnot(o_, index, k));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto GradientInterface::Hxx1::COWFn<S>::SetKnot(Int index, const GradientKnot& k) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); GradientInterface* o_ = (GradientInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (MTable::_instance.GradientInterface_SetKnot(o_, index, k));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto GradientInterface::Hxx1::Fn<S>::ConvertToAlphaGradient() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); GradientInterface* o_ = (GradientInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { DebugStop(); return maxon::PrivateLogNullptrError(); } 
	MTable::_instance.GradientInterface_ConvertToAlphaGradient(o_);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto GradientInterface::Hxx1::COWFn<S>::ConvertToAlphaGradient() -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); GradientInterface* o_ = (GradientInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	MTable::_instance.GradientInterface_ConvertToAlphaGradient(o_);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto GradientInterface::Hxx1::Fn<S>::SortKnots() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); GradientInterface* o_ = (GradientInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { DebugStop(); return maxon::PrivateLogNullptrError(); } 
	MTable::_instance.GradientInterface_SortKnots(o_);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto GradientInterface::Hxx1::COWFn<S>::SortKnots() -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); GradientInterface* o_ = (GradientInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	MTable::_instance.GradientInterface_SortKnots(o_);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto GradientInterface::Hxx1::Fn<S>::InvertKnots() const -> Result<Bool>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Bool>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); GradientInterface* o_ = (GradientInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.GradientInterface_InvertKnots(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto GradientInterface::Hxx1::COWFn<S>::InvertKnots() -> Result<Bool>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Bool>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); GradientInterface* o_ = (GradientInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (MTable::_instance.GradientInterface_InvertKnots(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto GradientInterface::Hxx1::Fn<S>::DoubleKnots() const -> Result<Bool>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Bool>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); GradientInterface* o_ = (GradientInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.GradientInterface_DoubleKnots(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto GradientInterface::Hxx1::COWFn<S>::DoubleKnots() -> Result<Bool>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Bool>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); GradientInterface* o_ = (GradientInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (MTable::_instance.GradientInterface_DoubleKnots(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto GradientInterface::Hxx1::Fn<S>::DistributeKnots() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); GradientInterface* o_ = (GradientInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateLogNullptrError(false); } 
	return (MTable::_instance.GradientInterface_DistributeKnots(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto GradientInterface::Hxx1::COWFn<S>::DistributeKnots() -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Bool, maxon::Result<Bool>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Bool, maxon::Result<Bool>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); GradientInterface* o_ = (GradientInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (MTable::_instance.GradientInterface_DistributeKnots(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto GradientInterface::Hxx1::Fn<S>::Flush() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); GradientInterface* o_ = (GradientInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { DebugStop(); return maxon::PrivateLogNullptrError(); } 
	MTable::_instance.GradientInterface_Flush(o_);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto GradientInterface::Hxx1::COWFn<S>::Flush() -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); GradientInterface* o_ = (GradientInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	MTable::_instance.GradientInterface_Flush(o_);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto GradientInterface::Hxx1::Fn<S>::SetIsAlphaGradient(Bool alphaGradient) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); GradientInterface* o_ = (GradientInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { DebugStop(); return maxon::PrivateLogNullptrError(); } 
	MTable::_instance.GradientInterface_SetIsAlphaGradient(o_, alphaGradient);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto GradientInterface::Hxx1::COWFn<S>::SetIsAlphaGradient(Bool alphaGradient) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); GradientInterface* o_ = (GradientInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	MTable::_instance.GradientInterface_SetIsAlphaGradient(o_, alphaGradient);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto GradientInterface::Hxx1::ConstFn<S>::IsAlphaGradient() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const GradientInterface* o_ = (const GradientInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = GradientInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (MTable::_instance.GradientInterface_IsAlphaGradient(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto GradientInterface::Hxx1::ConstFn<S>::Compare(const GradientInterface* arg2) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<COMPARERESULT>, COMPARERESULT>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<COMPARERESULT>, COMPARERESULT>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const GradientInterface* o_ = (const GradientInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = GradientInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<COMPARERESULT>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (MTable::_instance.GradientInterface_Compare(o_, arg2));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto GradientInterface::Hxx1::ConstFn<S>::InitRender(const TransformColorDelegate& transformColorDelegate) const -> Result<GradientRenderData>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<GradientRenderData>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const GradientInterface* o_ = (const GradientInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = GradientInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.GradientInterface_InitRender(o_, transformColorDelegate));
}
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_gradient)
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
	void (*GradientRenderDataInterface_Free) (const GradientRenderDataInterface* object);
	GradientRenderDataInterface* (*GradientRenderDataInterface_Alloc) (const maxon::SourceLocation& allocLocation);
	GradientRenderDataInterface* (*GradientRenderDataInterface_Alloc_1) (const maxon::SourceLocation& allocLocation, const GradientRenderDataInterface& object);
	Color (*GradientRenderDataInterface_CalcGradientPixel) (const GradientRenderDataInterface* this_, Float pos);
	Int (*GradientRenderDataInterface_GetKnotCount) (const GradientRenderDataInterface* this_);
	const GradientKnot* (*GradientRenderDataInterface_GetKnot) (const GradientRenderDataInterface* this_, Int index);
	const BaseArray<GradientKnot>& (*GradientRenderDataInterface_GetKnots) (const GradientRenderDataInterface* this_);
	COMPARERESULT (*GradientRenderDataInterface_Compare) (const GradientRenderDataInterface* this_, const GradientRenderDataInterface* arg2);
	HashInt (*GradientRenderDataInterface_GetHashCode) (const GradientRenderDataInterface* this_);
	template <typename IMPL> void Init()
	{
		GradientRenderDataInterface_Free = &IMPL::GradientRenderDataInterface_Free;
		GradientRenderDataInterface_Alloc = &IMPL::GradientRenderDataInterface_Alloc;
		GradientRenderDataInterface_Alloc_1 = &IMPL::GradientRenderDataInterface_Alloc_1;
		GradientRenderDataInterface_CalcGradientPixel = &IMPL::GradientRenderDataInterface_CalcGradientPixel;
		GradientRenderDataInterface_GetKnotCount = &IMPL::GradientRenderDataInterface_GetKnotCount;
		GradientRenderDataInterface_GetKnot = &IMPL::GradientRenderDataInterface_GetKnot;
		GradientRenderDataInterface_GetKnots = &IMPL::GradientRenderDataInterface_GetKnots;
		GradientRenderDataInterface_Compare = &IMPL::GradientRenderDataInterface_Compare;
		GradientRenderDataInterface_GetHashCode = &IMPL::GradientRenderDataInterface_GetHashCode;
	}
};

struct GradientRenderDataInterface::Hxx2
{
	class Unresolved;
	template <typename C> class Wrapper
	{
	public:
		static void GradientRenderDataInterface_Free(const GradientRenderDataInterface* object) { return C::Free(object); }
		static GradientRenderDataInterface* GradientRenderDataInterface_Alloc(const maxon::SourceLocation& allocLocation) { return C::Alloc(allocLocation); }
		static GradientRenderDataInterface* GradientRenderDataInterface_Alloc_1(const maxon::SourceLocation& allocLocation, const GradientRenderDataInterface& object) { return C::Alloc(allocLocation, ((const C&) object)); }
		static Color GradientRenderDataInterface_CalcGradientPixel(const GradientRenderDataInterface* this_, Float pos) { return C::Get(this_)->CalcGradientPixel(pos); }
		static Int GradientRenderDataInterface_GetKnotCount(const GradientRenderDataInterface* this_) { return C::Get(this_)->GetKnotCount(); }
		static const GradientKnot* GradientRenderDataInterface_GetKnot(const GradientRenderDataInterface* this_, Int index) { return C::Get(this_)->GetKnot(index); }
		static const BaseArray<GradientKnot>& GradientRenderDataInterface_GetKnots(const GradientRenderDataInterface* this_) { return C::Get(this_)->GetKnots(); }
		static COMPARERESULT GradientRenderDataInterface_Compare(const GradientRenderDataInterface* this_, const GradientRenderDataInterface* arg2) { return C::Get(this_)->Compare(arg2); }
		static HashInt GradientRenderDataInterface_GetHashCode(const GradientRenderDataInterface* this_) { return C::Get(this_)->GetHashCode(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto GradientRenderDataInterface::Free(const GradientRenderDataInterface* object) -> void
{
	return MTable::_instance.GradientRenderDataInterface_Free(object);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GradientRenderDataInterface::Alloc(const maxon::SourceLocation& allocLocation) -> GradientRenderDataInterface*
{
	return MTable::_instance.GradientRenderDataInterface_Alloc(allocLocation);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GradientRenderDataInterface::Alloc(const maxon::SourceLocation& allocLocation, const GradientRenderDataInterface& object) -> GradientRenderDataInterface*
{
	return MTable::_instance.GradientRenderDataInterface_Alloc_1(allocLocation, object);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GradientRenderDataInterface::CalcGradientPixel(Float pos) const -> Color
{
	return MTable::_instance.GradientRenderDataInterface_CalcGradientPixel(this, pos);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GradientRenderDataInterface::GetKnotCount() const -> Int
{
	return MTable::_instance.GradientRenderDataInterface_GetKnotCount(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GradientRenderDataInterface::GetKnot(Int index) const -> const GradientKnot*
{
	return MTable::_instance.GradientRenderDataInterface_GetKnot(this, index);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GradientRenderDataInterface::GetKnots() const -> const BaseArray<GradientKnot>&
{
	return MTable::_instance.GradientRenderDataInterface_GetKnots(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GradientRenderDataInterface::Compare(const GradientRenderDataInterface* arg2) const -> COMPARERESULT
{
	return MTable::_instance.GradientRenderDataInterface_Compare(this, arg2);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GradientRenderDataInterface::GetHashCode() const -> HashInt
{
	return MTable::_instance.GradientRenderDataInterface_GetHashCode(this);
}

auto GradientRenderDataInterface::Hxx1::Reference::Create() -> maxon::ResultMemT<GradientRenderData>
{
	GradientRenderDataInterface* res_ = GradientRenderDataInterface::Alloc(MAXON_SOURCE_LOCATION);
	return GradientRenderData(maxon::ForwardResultPtr<GradientRenderDataInterface>(res_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto GradientRenderDataInterface::Hxx1::ConstFn<S>::CalcGradientPixel(Float pos) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Color>, Color>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Color>, Color>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const GradientRenderDataInterface* o_ = (const GradientRenderDataInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = GradientRenderDataInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<Color>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (MTable::_instance.GradientRenderDataInterface_CalcGradientPixel(o_, pos));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto GradientRenderDataInterface::Hxx1::ConstFn<S>::GetKnotCount() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const GradientRenderDataInterface* o_ = (const GradientRenderDataInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = GradientRenderDataInterface::NullValuePtr(); if (!o_) return 0; } 
	return (MTable::_instance.GradientRenderDataInterface_GetKnotCount(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto GradientRenderDataInterface::Hxx1::ConstFn<S>::GetKnot(Int index) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const GradientKnot*>, const GradientKnot*>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const GradientKnot*>, const GradientKnot*>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const GradientRenderDataInterface* o_ = (const GradientRenderDataInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = GradientRenderDataInterface::NullValuePtr(); if (!o_) return nullptr; } 
	return (MTable::_instance.GradientRenderDataInterface_GetKnot(o_, index));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto GradientRenderDataInterface::Hxx1::ConstFn<S>::GetKnots() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const BaseArray<GradientKnot>&>, const BaseArray<GradientKnot>&>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const BaseArray<GradientKnot>&>, const BaseArray<GradientKnot>&>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const GradientRenderDataInterface* o_ = (const GradientRenderDataInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = GradientRenderDataInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<const BaseArray<GradientKnot>&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (MTable::_instance.GradientRenderDataInterface_GetKnots(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto GradientRenderDataInterface::Hxx1::ConstFn<S>::Compare(const GradientRenderDataInterface* arg2) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<COMPARERESULT>, COMPARERESULT>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<COMPARERESULT>, COMPARERESULT>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const GradientRenderDataInterface* o_ = (const GradientRenderDataInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = GradientRenderDataInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<COMPARERESULT>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (MTable::_instance.GradientRenderDataInterface_Compare(o_, arg2));
}
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_gradient)
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

