
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
	PRIVATE_MAXON_SF_POINTER(GradientInterface_Free, Free, MAXON_EXPAND_VA_ARGS, (void), const GradientInterface* object);
	PRIVATE_MAXON_SF_POINTER(GradientInterface_Alloc, Alloc, MAXON_IGNORE_VA_ARGS, (GradientInterface*), const maxon::SourceLocation& allocLocation);
	PRIVATE_MAXON_SF_POINTER(GradientInterface_Alloc_1, Alloc, MAXON_IGNORE_VA_ARGS, (GradientInterface*), const maxon::SourceLocation& allocLocation, const GradientInterface& object);
	PRIVATE_MAXON_MF_POINTER(GradientInterface_AllocAlphaGradient, AllocAlphaGradient, false, GradientInterface,, (Result<Gradient*>));
	PRIVATE_MAXON_MF_POINTER(GradientInterface_GetAlphaGradient, GetAlphaGradient, false, GradientInterface,, (Gradient*));
	PRIVATE_MAXON_MF_POINTER(GradientInterface_GetKnotCount, GetKnotCount, false, GradientInterface, const, (Int));
	PRIVATE_MAXON_MF_POINTER(GradientInterface_InsertKnot, InsertKnot, false, GradientInterface,, (Result<Int>), const GradientKnot& knot, Bool keepId);
	PRIVATE_MAXON_MF_POINTER(GradientInterface_RemoveKnot, RemoveKnot, false, GradientInterface,, (Result<void>), Int index);
	PRIVATE_MAXON_MF_POINTER(GradientInterface_GetKnot, GetKnot, false, GradientInterface, const, (GradientKnot), Int index);
	PRIVATE_MAXON_MF_POINTER(GradientInterface_SetKnot, SetKnot, false, GradientInterface,, (Result<void>), Int index, const GradientKnot& k);
	PRIVATE_MAXON_MF_POINTER(GradientInterface_ConvertToAlphaGradient, ConvertToAlphaGradient, false, GradientInterface,, (void));
	PRIVATE_MAXON_MF_POINTER(GradientInterface_SortKnots, SortKnots, false, GradientInterface,, (void));
	PRIVATE_MAXON_MF_POINTER(GradientInterface_InvertKnots, InvertKnots, false, GradientInterface,, (Result<Bool>));
	PRIVATE_MAXON_MF_POINTER(GradientInterface_DoubleKnots, DoubleKnots, false, GradientInterface,, (Result<Bool>));
	PRIVATE_MAXON_MF_POINTER(GradientInterface_DistributeKnots, DistributeKnots, false, GradientInterface,, (Bool));
	PRIVATE_MAXON_MF_POINTER(GradientInterface_Flush, Flush, false, GradientInterface,, (void));
	PRIVATE_MAXON_MF_POINTER(GradientInterface_SetIsAlphaGradient, SetIsAlphaGradient, false, GradientInterface,, (void), Bool alphaGradient);
	PRIVATE_MAXON_MF_POINTER(GradientInterface_IsAlphaGradient, IsAlphaGradient, false, GradientInterface, const, (Bool));
	PRIVATE_MAXON_MF_POINTER(GradientInterface_Compare, Compare, false, GradientInterface, const, (COMPARERESULT), const GradientInterface* arg2);
	PRIVATE_MAXON_MF_POINTER(GradientInterface_GetHashCode, GetHashCode, false, GradientInterface, const, (HashInt));
	PRIVATE_MAXON_MF_POINTER(GradientInterface_InitRender, InitRender, false, GradientInterface, const, (Result<GradientRenderData>), const TransformColorDelegate& transformColorDelegate);
	template <typename IMPL> void Init()
	{
		GradientInterface_Free = GradientInterface_Free_GetPtr<IMPL>(true);
		GradientInterface_Alloc = GradientInterface_Alloc_GetPtr<IMPL>(true);
		GradientInterface_Alloc_1 = GradientInterface_Alloc_1_GetPtr<IMPL>(true);
		GradientInterface_AllocAlphaGradient = GradientInterface_AllocAlphaGradient_GetPtr<IMPL>(0, true).first;
		GradientInterface_GetAlphaGradient = GradientInterface_GetAlphaGradient_GetPtr<IMPL>(0, true).first;
		GradientInterface_GetKnotCount = GradientInterface_GetKnotCount_GetPtr<IMPL>(0, true).first;
		GradientInterface_InsertKnot = GradientInterface_InsertKnot_GetPtr<IMPL>(0, true).first;
		GradientInterface_RemoveKnot = GradientInterface_RemoveKnot_GetPtr<IMPL>(0, true).first;
		GradientInterface_GetKnot = GradientInterface_GetKnot_GetPtr<IMPL>(0, true).first;
		GradientInterface_SetKnot = GradientInterface_SetKnot_GetPtr<IMPL>(0, true).first;
		GradientInterface_ConvertToAlphaGradient = GradientInterface_ConvertToAlphaGradient_GetPtr<IMPL>(0, true).first;
		GradientInterface_SortKnots = GradientInterface_SortKnots_GetPtr<IMPL>(0, true).first;
		GradientInterface_InvertKnots = GradientInterface_InvertKnots_GetPtr<IMPL>(0, true).first;
		GradientInterface_DoubleKnots = GradientInterface_DoubleKnots_GetPtr<IMPL>(0, true).first;
		GradientInterface_DistributeKnots = GradientInterface_DistributeKnots_GetPtr<IMPL>(0, true).first;
		GradientInterface_Flush = GradientInterface_Flush_GetPtr<IMPL>(0, true).first;
		GradientInterface_SetIsAlphaGradient = GradientInterface_SetIsAlphaGradient_GetPtr<IMPL>(0, true).first;
		GradientInterface_IsAlphaGradient = GradientInterface_IsAlphaGradient_GetPtr<IMPL>(0, true).first;
		GradientInterface_Compare = GradientInterface_Compare_GetPtr<IMPL>(0, true).first;
		GradientInterface_GetHashCode = GradientInterface_GetHashCode_GetPtr<IMPL>(0, true).first;
		GradientInterface_InitRender = GradientInterface_InitRender_GetPtr<IMPL>(0, true).first;
	}
};

struct GradientInterface::Hxx2
{
	class Unresolved;
	template <typename C> class Wrapper
	{
	public:
		using Implementation = C;
		static void GradientInterface_Free(const GradientInterface* object) { return C::Free(object); }
		static GradientInterface* GradientInterface_Alloc(const maxon::SourceLocation& allocLocation) { return C::Alloc(allocLocation); }
		static GradientInterface* GradientInterface_Alloc_1(const maxon::SourceLocation& allocLocation, const GradientInterface& object) { return C::Alloc(allocLocation, ((const C&) object)); }
		PRIVATE_MAXON_MF_WRAPPER(GradientInterface_AllocAlphaGradient, GradientInterface,, (Result<Gradient*>)) { return C::Get(PRIVATE_MAXON_MF_THIS(GradientInterface))->AllocAlphaGradient(); }
		PRIVATE_MAXON_MF_WRAPPER(GradientInterface_GetAlphaGradient, GradientInterface,, (Gradient*)) { return C::Get(PRIVATE_MAXON_MF_THIS(GradientInterface))->GetAlphaGradient(); }
		PRIVATE_MAXON_MF_WRAPPER(GradientInterface_GetKnotCount, GradientInterface, const, (Int)) { return C::Get(PRIVATE_MAXON_MF_THIS(const GradientInterface))->GetKnotCount(); }
		PRIVATE_MAXON_MF_WRAPPER(GradientInterface_InsertKnot, GradientInterface,, (Result<Int>), const GradientKnot& knot, Bool keepId) { return C::Get(PRIVATE_MAXON_MF_THIS(GradientInterface))->InsertKnot(knot, keepId); }
		PRIVATE_MAXON_MF_WRAPPER(GradientInterface_RemoveKnot, GradientInterface,, (Result<void>), Int index) { return C::Get(PRIVATE_MAXON_MF_THIS(GradientInterface))->RemoveKnot(index); }
		PRIVATE_MAXON_MF_WRAPPER(GradientInterface_GetKnot, GradientInterface, const, (GradientKnot), Int index) { return C::Get(PRIVATE_MAXON_MF_THIS(const GradientInterface))->GetKnot(index); }
		PRIVATE_MAXON_MF_WRAPPER(GradientInterface_SetKnot, GradientInterface,, (Result<void>), Int index, const GradientKnot& k) { return C::Get(PRIVATE_MAXON_MF_THIS(GradientInterface))->SetKnot(index, k); }
		PRIVATE_MAXON_MF_WRAPPER(GradientInterface_ConvertToAlphaGradient, GradientInterface,, (void)) { return C::Get(PRIVATE_MAXON_MF_THIS(GradientInterface))->ConvertToAlphaGradient(); }
		PRIVATE_MAXON_MF_WRAPPER(GradientInterface_SortKnots, GradientInterface,, (void)) { return C::Get(PRIVATE_MAXON_MF_THIS(GradientInterface))->SortKnots(); }
		PRIVATE_MAXON_MF_WRAPPER(GradientInterface_InvertKnots, GradientInterface,, (Result<Bool>)) { return C::Get(PRIVATE_MAXON_MF_THIS(GradientInterface))->InvertKnots(); }
		PRIVATE_MAXON_MF_WRAPPER(GradientInterface_DoubleKnots, GradientInterface,, (Result<Bool>)) { return C::Get(PRIVATE_MAXON_MF_THIS(GradientInterface))->DoubleKnots(); }
		PRIVATE_MAXON_MF_WRAPPER(GradientInterface_DistributeKnots, GradientInterface,, (Bool)) { return C::Get(PRIVATE_MAXON_MF_THIS(GradientInterface))->DistributeKnots(); }
		PRIVATE_MAXON_MF_WRAPPER(GradientInterface_Flush, GradientInterface,, (void)) { return C::Get(PRIVATE_MAXON_MF_THIS(GradientInterface))->Flush(); }
		PRIVATE_MAXON_MF_WRAPPER(GradientInterface_SetIsAlphaGradient, GradientInterface,, (void), Bool alphaGradient) { return C::Get(PRIVATE_MAXON_MF_THIS(GradientInterface))->SetIsAlphaGradient(alphaGradient); }
		PRIVATE_MAXON_MF_WRAPPER(GradientInterface_IsAlphaGradient, GradientInterface, const, (Bool)) { return C::Get(PRIVATE_MAXON_MF_THIS(const GradientInterface))->IsAlphaGradient(); }
		PRIVATE_MAXON_MF_WRAPPER(GradientInterface_Compare, GradientInterface, const, (COMPARERESULT), const GradientInterface* arg2) { return C::Get(PRIVATE_MAXON_MF_THIS(const GradientInterface))->Compare(arg2); }
		PRIVATE_MAXON_MF_WRAPPER(GradientInterface_GetHashCode, GradientInterface, const, (HashInt)) { return C::Get(PRIVATE_MAXON_MF_THIS(const GradientInterface))->GetHashCode(); }
		PRIVATE_MAXON_MF_WRAPPER(GradientInterface_InitRender, GradientInterface, const, (Result<GradientRenderData>), const TransformColorDelegate& transformColorDelegate) { return C::Get(PRIVATE_MAXON_MF_THIS(const GradientInterface))->InitRender(transformColorDelegate); }
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
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.GradientInterface_AllocAlphaGradient);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GradientInterface::GetAlphaGradient() -> Gradient*
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.GradientInterface_GetAlphaGradient);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GradientInterface::GetKnotCount() const -> Int
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.GradientInterface_GetKnotCount);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GradientInterface::InsertKnot(const GradientKnot& knot, Bool keepId) -> Result<Int>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.GradientInterface_InsertKnot, knot, keepId);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GradientInterface::RemoveKnot(Int index) -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.GradientInterface_RemoveKnot, index);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GradientInterface::GetKnot(Int index) const -> GradientKnot
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.GradientInterface_GetKnot, index);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GradientInterface::SetKnot(Int index, const GradientKnot& k) -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.GradientInterface_SetKnot, index, k);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GradientInterface::ConvertToAlphaGradient() -> void
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.GradientInterface_ConvertToAlphaGradient);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GradientInterface::SortKnots() -> void
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.GradientInterface_SortKnots);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GradientInterface::InvertKnots() -> Result<Bool>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.GradientInterface_InvertKnots);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GradientInterface::DoubleKnots() -> Result<Bool>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.GradientInterface_DoubleKnots);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GradientInterface::DistributeKnots() -> Bool
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.GradientInterface_DistributeKnots);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GradientInterface::Flush() -> void
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.GradientInterface_Flush);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GradientInterface::SetIsAlphaGradient(Bool alphaGradient) -> void
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.GradientInterface_SetIsAlphaGradient, alphaGradient);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GradientInterface::IsAlphaGradient() const -> Bool
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.GradientInterface_IsAlphaGradient);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GradientInterface::Compare(const GradientInterface* arg2) const -> COMPARERESULT
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.GradientInterface_Compare, arg2);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GradientInterface::GetHashCode() const -> HashInt
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.GradientInterface_GetHashCode);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GradientInterface::InitRender(const TransformColorDelegate& transformColorDelegate) const -> Result<GradientRenderData>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.GradientInterface_InitRender, transformColorDelegate);
}

auto GradientInterface::Hxx1::Reference::Create() -> maxon::ResultMemT<Gradient>
{
	GradientInterface* res_ = GradientInterface::Alloc(MAXON_SOURCE_LOCATION);
	return Gradient(maxon::ForwardResultPtr<GradientInterface>(res_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto GradientInterface::Hxx1::Fn<S>::AllocAlphaGradient() const -> Result<Gradient*>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Gradient*>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); GradientInterface* o_ = (GradientInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.GradientInterface_AllocAlphaGradient));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto GradientInterface::Hxx1::COWFn<S>::AllocAlphaGradient() -> Result<Gradient*>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Gradient*>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); GradientInterface* o_ = (GradientInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.GradientInterface_AllocAlphaGradient));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto GradientInterface::Hxx1::Fn<S>::GetAlphaGradient() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Gradient*>, Gradient*>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Gradient*>, Gradient*>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); GradientInterface* o_ = (GradientInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return nullptr; } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.GradientInterface_GetAlphaGradient));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto GradientInterface::Hxx1::COWFn<S>::GetAlphaGradient() -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Gradient*, maxon::Result<Gradient*>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Gradient*, maxon::Result<Gradient*>>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); GradientInterface* o_ = (GradientInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.GradientInterface_GetAlphaGradient));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto GradientInterface::Hxx1::ConstFn<S>::GetKnotCount() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const GradientInterface* o_ = (const GradientInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = GradientInterface::NullValuePtr(); if (!o_) return 0; } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.GradientInterface_GetKnotCount));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto GradientInterface::Hxx1::Fn<S>::InsertKnot(const GradientKnot& knot, Bool keepId) const -> Result<Int>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Int>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); GradientInterface* o_ = (GradientInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.GradientInterface_InsertKnot, knot, keepId));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto GradientInterface::Hxx1::COWFn<S>::InsertKnot(const GradientKnot& knot, Bool keepId) -> Result<Int>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Int>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); GradientInterface* o_ = (GradientInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.GradientInterface_InsertKnot, knot, keepId));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto GradientInterface::Hxx1::Fn<S>::RemoveKnot(Int index) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); GradientInterface* o_ = (GradientInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.GradientInterface_RemoveKnot, index));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto GradientInterface::Hxx1::COWFn<S>::RemoveKnot(Int index) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); GradientInterface* o_ = (GradientInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.GradientInterface_RemoveKnot, index));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto GradientInterface::Hxx1::ConstFn<S>::GetKnot(Int index) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<GradientKnot>, GradientKnot>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<GradientKnot>, GradientKnot>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const GradientInterface* o_ = (const GradientInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = GradientInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<GradientKnot>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.GradientInterface_GetKnot, index));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto GradientInterface::Hxx1::Fn<S>::SetKnot(Int index, const GradientKnot& k) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); GradientInterface* o_ = (GradientInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.GradientInterface_SetKnot, index, k));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto GradientInterface::Hxx1::COWFn<S>::SetKnot(Int index, const GradientKnot& k) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); GradientInterface* o_ = (GradientInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.GradientInterface_SetKnot, index, k));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto GradientInterface::Hxx1::Fn<S>::ConvertToAlphaGradient() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); GradientInterface* o_ = (GradientInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { DebugStop(); return maxon::PrivateLogNullptrError(); } 
	PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.GradientInterface_ConvertToAlphaGradient);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto GradientInterface::Hxx1::COWFn<S>::ConvertToAlphaGradient() -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); GradientInterface* o_ = (GradientInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.GradientInterface_ConvertToAlphaGradient);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto GradientInterface::Hxx1::Fn<S>::SortKnots() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); GradientInterface* o_ = (GradientInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { DebugStop(); return maxon::PrivateLogNullptrError(); } 
	PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.GradientInterface_SortKnots);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto GradientInterface::Hxx1::COWFn<S>::SortKnots() -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); GradientInterface* o_ = (GradientInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.GradientInterface_SortKnots);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto GradientInterface::Hxx1::Fn<S>::InvertKnots() const -> Result<Bool>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Bool>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); GradientInterface* o_ = (GradientInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.GradientInterface_InvertKnots));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto GradientInterface::Hxx1::COWFn<S>::InvertKnots() -> Result<Bool>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Bool>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); GradientInterface* o_ = (GradientInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.GradientInterface_InvertKnots));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto GradientInterface::Hxx1::Fn<S>::DoubleKnots() const -> Result<Bool>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Bool>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); GradientInterface* o_ = (GradientInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.GradientInterface_DoubleKnots));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto GradientInterface::Hxx1::COWFn<S>::DoubleKnots() -> Result<Bool>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Bool>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); GradientInterface* o_ = (GradientInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.GradientInterface_DoubleKnots));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto GradientInterface::Hxx1::Fn<S>::DistributeKnots() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); GradientInterface* o_ = (GradientInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateLogNullptrError(false); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.GradientInterface_DistributeKnots));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto GradientInterface::Hxx1::COWFn<S>::DistributeKnots() -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Bool, maxon::Result<Bool>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Bool, maxon::Result<Bool>>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); GradientInterface* o_ = (GradientInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.GradientInterface_DistributeKnots));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto GradientInterface::Hxx1::Fn<S>::Flush() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); GradientInterface* o_ = (GradientInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { DebugStop(); return maxon::PrivateLogNullptrError(); } 
	PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.GradientInterface_Flush);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto GradientInterface::Hxx1::COWFn<S>::Flush() -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); GradientInterface* o_ = (GradientInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.GradientInterface_Flush);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto GradientInterface::Hxx1::Fn<S>::SetIsAlphaGradient(Bool alphaGradient) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); GradientInterface* o_ = (GradientInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { DebugStop(); return maxon::PrivateLogNullptrError(); } 
	PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.GradientInterface_SetIsAlphaGradient, alphaGradient);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto GradientInterface::Hxx1::COWFn<S>::SetIsAlphaGradient(Bool alphaGradient) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); GradientInterface* o_ = (GradientInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.GradientInterface_SetIsAlphaGradient, alphaGradient);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto GradientInterface::Hxx1::ConstFn<S>::IsAlphaGradient() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const GradientInterface* o_ = (const GradientInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = GradientInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.GradientInterface_IsAlphaGradient));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto GradientInterface::Hxx1::ConstFn<S>::Compare(const GradientInterface* arg2) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<COMPARERESULT>, COMPARERESULT>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<COMPARERESULT>, COMPARERESULT>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const GradientInterface* o_ = (const GradientInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = GradientInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<COMPARERESULT>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.GradientInterface_Compare, arg2));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto GradientInterface::Hxx1::ConstFn<S>::InitRender(const TransformColorDelegate& transformColorDelegate) const -> Result<GradientRenderData>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<GradientRenderData>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const GradientInterface* o_ = (const GradientInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = GradientInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.GradientInterface_InitRender, transformColorDelegate));
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
	PRIVATE_MAXON_SF_POINTER(GradientRenderDataInterface_Free, Free, MAXON_EXPAND_VA_ARGS, (void), const GradientRenderDataInterface* object);
	PRIVATE_MAXON_SF_POINTER(GradientRenderDataInterface_Alloc, Alloc, MAXON_IGNORE_VA_ARGS, (GradientRenderDataInterface*), const maxon::SourceLocation& allocLocation);
	PRIVATE_MAXON_SF_POINTER(GradientRenderDataInterface_Alloc_1, Alloc, MAXON_IGNORE_VA_ARGS, (GradientRenderDataInterface*), const maxon::SourceLocation& allocLocation, const GradientRenderDataInterface& object);
	PRIVATE_MAXON_MF_POINTER(GradientRenderDataInterface_CalcGradientPixel, CalcGradientPixel, false, GradientRenderDataInterface, const, (Color), Float pos);
	PRIVATE_MAXON_MF_POINTER(GradientRenderDataInterface_GetKnotCount, GetKnotCount, false, GradientRenderDataInterface, const, (Int));
	PRIVATE_MAXON_MF_POINTER(GradientRenderDataInterface_GetKnot, GetKnot, false, GradientRenderDataInterface, const, (const GradientKnot*), Int index);
	PRIVATE_MAXON_MF_POINTER(GradientRenderDataInterface_GetKnots, GetKnots, false, GradientRenderDataInterface, const, (const BaseArray<GradientKnot>&));
	PRIVATE_MAXON_MF_POINTER(GradientRenderDataInterface_Compare, Compare, false, GradientRenderDataInterface, const, (COMPARERESULT), const GradientRenderDataInterface* arg2);
	PRIVATE_MAXON_MF_POINTER(GradientRenderDataInterface_GetHashCode, GetHashCode, false, GradientRenderDataInterface, const, (HashInt));
	template <typename IMPL> void Init()
	{
		GradientRenderDataInterface_Free = GradientRenderDataInterface_Free_GetPtr<IMPL>(true);
		GradientRenderDataInterface_Alloc = GradientRenderDataInterface_Alloc_GetPtr<IMPL>(true);
		GradientRenderDataInterface_Alloc_1 = GradientRenderDataInterface_Alloc_1_GetPtr<IMPL>(true);
		GradientRenderDataInterface_CalcGradientPixel = GradientRenderDataInterface_CalcGradientPixel_GetPtr<IMPL>(0, true).first;
		GradientRenderDataInterface_GetKnotCount = GradientRenderDataInterface_GetKnotCount_GetPtr<IMPL>(0, true).first;
		GradientRenderDataInterface_GetKnot = GradientRenderDataInterface_GetKnot_GetPtr<IMPL>(0, true).first;
		GradientRenderDataInterface_GetKnots = GradientRenderDataInterface_GetKnots_GetPtr<IMPL>(0, true).first;
		GradientRenderDataInterface_Compare = GradientRenderDataInterface_Compare_GetPtr<IMPL>(0, true).first;
		GradientRenderDataInterface_GetHashCode = GradientRenderDataInterface_GetHashCode_GetPtr<IMPL>(0, true).first;
	}
};

struct GradientRenderDataInterface::Hxx2
{
	class Unresolved;
	template <typename C> class Wrapper
	{
	public:
		using Implementation = C;
		static void GradientRenderDataInterface_Free(const GradientRenderDataInterface* object) { return C::Free(object); }
		static GradientRenderDataInterface* GradientRenderDataInterface_Alloc(const maxon::SourceLocation& allocLocation) { return C::Alloc(allocLocation); }
		static GradientRenderDataInterface* GradientRenderDataInterface_Alloc_1(const maxon::SourceLocation& allocLocation, const GradientRenderDataInterface& object) { return C::Alloc(allocLocation, ((const C&) object)); }
		PRIVATE_MAXON_MF_WRAPPER(GradientRenderDataInterface_CalcGradientPixel, GradientRenderDataInterface, const, (Color), Float pos) { return C::Get(PRIVATE_MAXON_MF_THIS(const GradientRenderDataInterface))->CalcGradientPixel(pos); }
		PRIVATE_MAXON_MF_WRAPPER(GradientRenderDataInterface_GetKnotCount, GradientRenderDataInterface, const, (Int)) { return C::Get(PRIVATE_MAXON_MF_THIS(const GradientRenderDataInterface))->GetKnotCount(); }
		PRIVATE_MAXON_MF_WRAPPER(GradientRenderDataInterface_GetKnot, GradientRenderDataInterface, const, (const GradientKnot*), Int index) { return C::Get(PRIVATE_MAXON_MF_THIS(const GradientRenderDataInterface))->GetKnot(index); }
		PRIVATE_MAXON_MF_WRAPPER(GradientRenderDataInterface_GetKnots, GradientRenderDataInterface, const, (const BaseArray<GradientKnot>&)) { return C::Get(PRIVATE_MAXON_MF_THIS(const GradientRenderDataInterface))->GetKnots(); }
		PRIVATE_MAXON_MF_WRAPPER(GradientRenderDataInterface_Compare, GradientRenderDataInterface, const, (COMPARERESULT), const GradientRenderDataInterface* arg2) { return C::Get(PRIVATE_MAXON_MF_THIS(const GradientRenderDataInterface))->Compare(arg2); }
		PRIVATE_MAXON_MF_WRAPPER(GradientRenderDataInterface_GetHashCode, GradientRenderDataInterface, const, (HashInt)) { return C::Get(PRIVATE_MAXON_MF_THIS(const GradientRenderDataInterface))->GetHashCode(); }
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
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.GradientRenderDataInterface_CalcGradientPixel, pos);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GradientRenderDataInterface::GetKnotCount() const -> Int
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.GradientRenderDataInterface_GetKnotCount);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GradientRenderDataInterface::GetKnot(Int index) const -> const GradientKnot*
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.GradientRenderDataInterface_GetKnot, index);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GradientRenderDataInterface::GetKnots() const -> const BaseArray<GradientKnot>&
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.GradientRenderDataInterface_GetKnots);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GradientRenderDataInterface::Compare(const GradientRenderDataInterface* arg2) const -> COMPARERESULT
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.GradientRenderDataInterface_Compare, arg2);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto GradientRenderDataInterface::GetHashCode() const -> HashInt
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.GradientRenderDataInterface_GetHashCode);
}

auto GradientRenderDataInterface::Hxx1::Reference::Create() -> maxon::ResultMemT<GradientRenderData>
{
	GradientRenderDataInterface* res_ = GradientRenderDataInterface::Alloc(MAXON_SOURCE_LOCATION);
	return GradientRenderData(maxon::ForwardResultPtr<GradientRenderDataInterface>(res_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto GradientRenderDataInterface::Hxx1::ConstFn<S>::CalcGradientPixel(Float pos) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Color>, Color>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Color>, Color>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const GradientRenderDataInterface* o_ = (const GradientRenderDataInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = GradientRenderDataInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<Color>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.GradientRenderDataInterface_CalcGradientPixel, pos));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto GradientRenderDataInterface::Hxx1::ConstFn<S>::GetKnotCount() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const GradientRenderDataInterface* o_ = (const GradientRenderDataInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = GradientRenderDataInterface::NullValuePtr(); if (!o_) return 0; } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.GradientRenderDataInterface_GetKnotCount));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto GradientRenderDataInterface::Hxx1::ConstFn<S>::GetKnot(Int index) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const GradientKnot*>, const GradientKnot*>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const GradientKnot*>, const GradientKnot*>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const GradientRenderDataInterface* o_ = (const GradientRenderDataInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = GradientRenderDataInterface::NullValuePtr(); if (!o_) return nullptr; } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.GradientRenderDataInterface_GetKnot, index));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto GradientRenderDataInterface::Hxx1::ConstFn<S>::GetKnots() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const BaseArray<GradientKnot>&>, const BaseArray<GradientKnot>&>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const BaseArray<GradientKnot>&>, const BaseArray<GradientKnot>&>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const GradientRenderDataInterface* o_ = (const GradientRenderDataInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = GradientRenderDataInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<const BaseArray<GradientKnot>&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.GradientRenderDataInterface_GetKnots));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto GradientRenderDataInterface::Hxx1::ConstFn<S>::Compare(const GradientRenderDataInterface* arg2) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<COMPARERESULT>, COMPARERESULT>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<COMPARERESULT>, COMPARERESULT>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const GradientRenderDataInterface* o_ = (const GradientRenderDataInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = GradientRenderDataInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<COMPARERESULT>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.GradientRenderDataInterface_Compare, arg2));
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

