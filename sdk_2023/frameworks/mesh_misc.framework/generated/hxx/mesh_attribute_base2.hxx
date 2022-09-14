
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1

struct CustomDataTagDisplayInterface::MTable
{
	PRIVATE_MAXON_IMPLEMENTS_CHECK(DisplayControl);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(Draw);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(FreeDisplayControl);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(Init);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(InitDisplayControl);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(Reset);
	static const maxon::Char* const _ids;
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	PRIVATE_MAXON_MF_POINTER(CustomDataTagDisplayInterface_Init, Init, true, maxon::GenericComponent,, (Result<void>), BaseTag* tag);
	maxon::Int CustomDataTagDisplayInterface_Init_Offset;
	PRIVATE_MAXON_MF_POINTER(CustomDataTagDisplayInterface_Draw, Draw, true, maxon::GenericComponent,, (Result<void>), BaseTag* tag, BaseObject* op, BaseDraw* bd, BaseDrawHelp* bh);
	maxon::Int CustomDataTagDisplayInterface_Draw_Offset;
	PRIVATE_MAXON_MF_POINTER(CustomDataTagDisplayInterface_DisplayControl, DisplayControl, true, maxon::GenericComponent, const, (Result<void>), BaseTag* tag, BaseDocument* doc, BaseObject* op, BaseDraw* bd, BaseDrawHelp* bh, ControlDisplayStruct& cds);
	maxon::Int CustomDataTagDisplayInterface_DisplayControl_Offset;
	PRIVATE_MAXON_MF_POINTER(CustomDataTagDisplayInterface_InitDisplayControl, InitDisplayControl, true, maxon::GenericComponent,, (Result<void>), BaseTag* tag, BaseDocument* doc, BaseDraw* bd, const AtomArray* active);
	maxon::Int CustomDataTagDisplayInterface_InitDisplayControl_Offset;
	PRIVATE_MAXON_MF_POINTER(CustomDataTagDisplayInterface_FreeDisplayControl, FreeDisplayControl, true, maxon::GenericComponent,, (void), BaseTag* tag);
	maxon::Int CustomDataTagDisplayInterface_FreeDisplayControl_Offset;
	PRIVATE_MAXON_MF_POINTER(CustomDataTagDisplayInterface_Reset, Reset, true, maxon::GenericComponent,, (void));
	maxon::Int CustomDataTagDisplayInterface_Reset_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CustomDataTagDisplayInterface, Init))
	{
		maxon::Tie(CustomDataTagDisplayInterface_Init, CustomDataTagDisplayInterface_Init_Offset) = CustomDataTagDisplayInterface_Init_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CustomDataTagDisplayInterface, Draw))
	{
		maxon::Tie(CustomDataTagDisplayInterface_Draw, CustomDataTagDisplayInterface_Draw_Offset) = CustomDataTagDisplayInterface_Draw_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CustomDataTagDisplayInterface, DisplayControl))
	{
		maxon::Tie(CustomDataTagDisplayInterface_DisplayControl, CustomDataTagDisplayInterface_DisplayControl_Offset) = CustomDataTagDisplayInterface_DisplayControl_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CustomDataTagDisplayInterface, InitDisplayControl))
	{
		maxon::Tie(CustomDataTagDisplayInterface_InitDisplayControl, CustomDataTagDisplayInterface_InitDisplayControl_Offset) = CustomDataTagDisplayInterface_InitDisplayControl_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CustomDataTagDisplayInterface, FreeDisplayControl))
	{
		maxon::Tie(CustomDataTagDisplayInterface_FreeDisplayControl, CustomDataTagDisplayInterface_FreeDisplayControl_Offset) = CustomDataTagDisplayInterface_FreeDisplayControl_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CustomDataTagDisplayInterface, Reset))
	{
		maxon::Tie(CustomDataTagDisplayInterface_Reset, CustomDataTagDisplayInterface_Reset_Offset) = CustomDataTagDisplayInterface_Reset_GetPtr<W>(offset, true);
	}
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<CustomDataTagDisplayInterface, typename ObjectInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<CustomDataTagDisplayInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct CustomDataTagDisplayInterface::Hxx2
{
	template <typename S> class CWrapper : public ObjectInterface::Hxx2::template CWrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(DisplayControl);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(Draw);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(FreeDisplayControl);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(Init);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(InitDisplayControl);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(Reset);
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename ObjectInterface::Hxx2::template CWrapper<S>;
			if constexpr (!S::Implementation::PROXY)
			{
				if (!(Super0::InitMTablesWithBases(info, offset))) return false;
			}
			auto* vt = (CustomDataTagDisplayInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, CustomDataTagDisplayInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		PRIVATE_MAXON_MF_WRAPPER(CustomDataTagDisplayInterface_Init, maxon::GenericComponent,, (Result<void>), BaseTag* tag) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->Init(tag); }
		PRIVATE_MAXON_MF_WRAPPER(CustomDataTagDisplayInterface_Draw, maxon::GenericComponent,, (Result<void>), BaseTag* tag, BaseObject* op, BaseDraw* bd, BaseDrawHelp* bh) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->Draw(tag, op, bd, bh); }
		PRIVATE_MAXON_MF_WRAPPER(CustomDataTagDisplayInterface_DisplayControl, maxon::GenericComponent, const, (Result<void>), BaseTag* tag, BaseDocument* doc, BaseObject* op, BaseDraw* bd, BaseDrawHelp* bh, ControlDisplayStruct& cds) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->DisplayControl(tag, doc, op, bd, bh, cds); }
		PRIVATE_MAXON_MF_WRAPPER(CustomDataTagDisplayInterface_InitDisplayControl, maxon::GenericComponent,, (Result<void>), BaseTag* tag, BaseDocument* doc, BaseDraw* bd, const AtomArray* active) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->InitDisplayControl(tag, doc, bd, active); }
		PRIVATE_MAXON_MF_WRAPPER(CustomDataTagDisplayInterface_FreeDisplayControl, maxon::GenericComponent,, (void), BaseTag* tag) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->FreeDisplayControl(tag); }
		PRIVATE_MAXON_MF_WRAPPER(CustomDataTagDisplayInterface_Reset, maxon::GenericComponent,, (void)) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->Reset(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto CustomDataTagDisplayInterface::Init(BaseTag* tag) -> Result<void>
{
	const CustomDataTagDisplayInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(CustomDataTagDisplayInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.CustomDataTagDisplayInterface_Init_Offset), mt_.CustomDataTagDisplayInterface_Init, tag);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CustomDataTagDisplayInterface::Draw(BaseTag* tag, BaseObject* op, BaseDraw* bd, BaseDrawHelp* bh) -> Result<void>
{
	const CustomDataTagDisplayInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(CustomDataTagDisplayInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.CustomDataTagDisplayInterface_Draw_Offset), mt_.CustomDataTagDisplayInterface_Draw, tag, op, bd, bh);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CustomDataTagDisplayInterface::DisplayControl(BaseTag* tag, BaseDocument* doc, BaseObject* op, BaseDraw* bd, BaseDrawHelp* bh, ControlDisplayStruct& cds) const -> Result<void>
{
	const CustomDataTagDisplayInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(CustomDataTagDisplayInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.CustomDataTagDisplayInterface_DisplayControl_Offset), mt_.CustomDataTagDisplayInterface_DisplayControl, tag, doc, op, bd, bh, cds);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CustomDataTagDisplayInterface::InitDisplayControl(BaseTag* tag, BaseDocument* doc, BaseDraw* bd, const AtomArray* active) -> Result<void>
{
	const CustomDataTagDisplayInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(CustomDataTagDisplayInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.CustomDataTagDisplayInterface_InitDisplayControl_Offset), mt_.CustomDataTagDisplayInterface_InitDisplayControl, tag, doc, bd, active);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CustomDataTagDisplayInterface::FreeDisplayControl(BaseTag* tag) -> void
{
	const CustomDataTagDisplayInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(CustomDataTagDisplayInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.CustomDataTagDisplayInterface_FreeDisplayControl_Offset), mt_.CustomDataTagDisplayInterface_FreeDisplayControl, tag);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CustomDataTagDisplayInterface::Reset() -> void
{
	const CustomDataTagDisplayInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(CustomDataTagDisplayInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.CustomDataTagDisplayInterface_Reset_Offset), mt_.CustomDataTagDisplayInterface_Reset);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CustomDataTagDisplayInterface::Hxx1::Fn<S>::Init(BaseTag* tag) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); CustomDataTagDisplayInterface* o_ = (CustomDataTagDisplayInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CustomDataTagDisplayInterface, o_, CustomDataTagDisplayInterface_Init) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<CustomDataTagDisplayInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CustomDataTagDisplayInterface>() : PRIVATE_MAXON_VTABLE(CustomDataTagDisplayInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.CustomDataTagDisplayInterface_Init_Offset), mt_.CustomDataTagDisplayInterface_Init, tag));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CustomDataTagDisplayInterface::Hxx1::COWFn<S>::Init(BaseTag* tag) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); CustomDataTagDisplayInterface* o_ = (CustomDataTagDisplayInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CustomDataTagDisplayInterface, o_, CustomDataTagDisplayInterface_Init) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<CustomDataTagDisplayInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CustomDataTagDisplayInterface>() : PRIVATE_MAXON_VTABLE(CustomDataTagDisplayInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.CustomDataTagDisplayInterface_Init_Offset), mt_.CustomDataTagDisplayInterface_Init, tag));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CustomDataTagDisplayInterface::Hxx1::Fn<S>::Draw(BaseTag* tag, BaseObject* op, BaseDraw* bd, BaseDrawHelp* bh) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); CustomDataTagDisplayInterface* o_ = (CustomDataTagDisplayInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CustomDataTagDisplayInterface, o_, CustomDataTagDisplayInterface_Draw) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<CustomDataTagDisplayInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CustomDataTagDisplayInterface>() : PRIVATE_MAXON_VTABLE(CustomDataTagDisplayInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.CustomDataTagDisplayInterface_Draw_Offset), mt_.CustomDataTagDisplayInterface_Draw, tag, op, bd, bh));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CustomDataTagDisplayInterface::Hxx1::COWFn<S>::Draw(BaseTag* tag, BaseObject* op, BaseDraw* bd, BaseDrawHelp* bh) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); CustomDataTagDisplayInterface* o_ = (CustomDataTagDisplayInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CustomDataTagDisplayInterface, o_, CustomDataTagDisplayInterface_Draw) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<CustomDataTagDisplayInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CustomDataTagDisplayInterface>() : PRIVATE_MAXON_VTABLE(CustomDataTagDisplayInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.CustomDataTagDisplayInterface_Draw_Offset), mt_.CustomDataTagDisplayInterface_Draw, tag, op, bd, bh));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CustomDataTagDisplayInterface::Hxx1::ConstFn<S>::DisplayControl(BaseTag* tag, BaseDocument* doc, BaseObject* op, BaseDraw* bd, BaseDrawHelp* bh, ControlDisplayStruct& cds) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const CustomDataTagDisplayInterface* o_ = (const CustomDataTagDisplayInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = CustomDataTagDisplayInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CustomDataTagDisplayInterface, o_, CustomDataTagDisplayInterface_DisplayControl) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<CustomDataTagDisplayInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CustomDataTagDisplayInterface>() : PRIVATE_MAXON_VTABLE(CustomDataTagDisplayInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.CustomDataTagDisplayInterface_DisplayControl_Offset), mt_.CustomDataTagDisplayInterface_DisplayControl, tag, doc, op, bd, bh, cds));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CustomDataTagDisplayInterface::Hxx1::Fn<S>::InitDisplayControl(BaseTag* tag, BaseDocument* doc, BaseDraw* bd, const AtomArray* active) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); CustomDataTagDisplayInterface* o_ = (CustomDataTagDisplayInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CustomDataTagDisplayInterface, o_, CustomDataTagDisplayInterface_InitDisplayControl) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<CustomDataTagDisplayInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CustomDataTagDisplayInterface>() : PRIVATE_MAXON_VTABLE(CustomDataTagDisplayInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.CustomDataTagDisplayInterface_InitDisplayControl_Offset), mt_.CustomDataTagDisplayInterface_InitDisplayControl, tag, doc, bd, active));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CustomDataTagDisplayInterface::Hxx1::COWFn<S>::InitDisplayControl(BaseTag* tag, BaseDocument* doc, BaseDraw* bd, const AtomArray* active) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); CustomDataTagDisplayInterface* o_ = (CustomDataTagDisplayInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CustomDataTagDisplayInterface, o_, CustomDataTagDisplayInterface_InitDisplayControl) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<CustomDataTagDisplayInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CustomDataTagDisplayInterface>() : PRIVATE_MAXON_VTABLE(CustomDataTagDisplayInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.CustomDataTagDisplayInterface_InitDisplayControl_Offset), mt_.CustomDataTagDisplayInterface_InitDisplayControl, tag, doc, bd, active));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CustomDataTagDisplayInterface::Hxx1::Fn<S>::FreeDisplayControl(BaseTag* tag) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); CustomDataTagDisplayInterface* o_ = (CustomDataTagDisplayInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { DebugStop(); return maxon::PrivateLogNullptrError(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CustomDataTagDisplayInterface, o_, CustomDataTagDisplayInterface_FreeDisplayControl) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<CustomDataTagDisplayInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CustomDataTagDisplayInterface>() : PRIVATE_MAXON_VTABLE(CustomDataTagDisplayInterface, o_); 
	PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.CustomDataTagDisplayInterface_FreeDisplayControl_Offset), mt_.CustomDataTagDisplayInterface_FreeDisplayControl, tag);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CustomDataTagDisplayInterface::Hxx1::COWFn<S>::FreeDisplayControl(BaseTag* tag) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); CustomDataTagDisplayInterface* o_ = (CustomDataTagDisplayInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CustomDataTagDisplayInterface, o_, CustomDataTagDisplayInterface_FreeDisplayControl) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<CustomDataTagDisplayInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CustomDataTagDisplayInterface>() : PRIVATE_MAXON_VTABLE(CustomDataTagDisplayInterface, o_); 
	PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.CustomDataTagDisplayInterface_FreeDisplayControl_Offset), mt_.CustomDataTagDisplayInterface_FreeDisplayControl, tag);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CustomDataTagDisplayInterface::Hxx1::Fn<S>::Reset() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); CustomDataTagDisplayInterface* o_ = (CustomDataTagDisplayInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { DebugStop(); return maxon::PrivateLogNullptrError(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CustomDataTagDisplayInterface, o_, CustomDataTagDisplayInterface_Reset) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<CustomDataTagDisplayInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CustomDataTagDisplayInterface>() : PRIVATE_MAXON_VTABLE(CustomDataTagDisplayInterface, o_); 
	PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.CustomDataTagDisplayInterface_Reset_Offset), mt_.CustomDataTagDisplayInterface_Reset);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CustomDataTagDisplayInterface::Hxx1::COWFn<S>::Reset() -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); CustomDataTagDisplayInterface* o_ = (CustomDataTagDisplayInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CustomDataTagDisplayInterface, o_, CustomDataTagDisplayInterface_Reset) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<CustomDataTagDisplayInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CustomDataTagDisplayInterface>() : PRIVATE_MAXON_VTABLE(CustomDataTagDisplayInterface, o_); 
	PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.CustomDataTagDisplayInterface_Reset_Offset), mt_.CustomDataTagDisplayInterface_Reset);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
auto CustomDataTagDisplayInterface::GetPtr() -> Ptr { return Ptr(this); }
auto CustomDataTagDisplayInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_mesh_attribute_base)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_CustomDataTagDisplayInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_CustomDataTagDisplayInterface() { new (s_ui_maxon_CustomDataTagDisplayInterface) maxon::EntityUse(CustomDataTagDisplayInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/mesh_attribute_base.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_CustomDataTagDisplayInterface(CustomDataTagDisplayInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/mesh_attribute_base.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif

struct MeshAttributeClassInterface::MTable
{
	PRIVATE_MAXON_IMPLEMENTS_CHECK(AtrAdd);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(AtrDivide);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(AtrIsEqual);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(AtrLessThen);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(AtrMultiply);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(AtrSubstract);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(AtrToString);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetDataType);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetDefaultValue);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetUnderlyingDataType);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(InterpolateInOutline);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(InterpolateLinear);
	static const maxon::Char* const _ids;
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	PRIVATE_MAXON_MF_POINTER(MeshAttributeClassInterface_GetDataType, GetDataType, true, maxon::GenericComponent, const, (const DataType&));
	maxon::Int MeshAttributeClassInterface_GetDataType_Offset;
	PRIVATE_MAXON_MF_POINTER(MeshAttributeClassInterface_GetUnderlyingDataType, GetUnderlyingDataType, true, maxon::GenericComponent, const, (const DataType&));
	maxon::Int MeshAttributeClassInterface_GetUnderlyingDataType_Offset;
	PRIVATE_MAXON_MF_POINTER(MeshAttributeClassInterface_InterpolateLinear, InterpolateLinear, true, maxon::GenericComponent, const, (void), void* data1, const void* data2, Float blend);
	maxon::Int MeshAttributeClassInterface_InterpolateLinear_Offset;
	PRIVATE_MAXON_MF_POINTER(MeshAttributeClassInterface_InterpolateInOutline, InterpolateInOutline, true, maxon::GenericComponent, const, (void), void* data, const Block<void*>& outline, const Block<Float>& weights);
	maxon::Int MeshAttributeClassInterface_InterpolateInOutline_Offset;
	PRIVATE_MAXON_MF_POINTER(MeshAttributeClassInterface_GetDefaultValue, GetDefaultValue, true, maxon::GenericComponent, const, (void), void* data);
	maxon::Int MeshAttributeClassInterface_GetDefaultValue_Offset;
	PRIVATE_MAXON_MF_POINTER(MeshAttributeClassInterface_AtrLessThen, AtrLessThen, true, maxon::GenericComponent, const, (Bool), const void* data1, const void* data2);
	maxon::Int MeshAttributeClassInterface_AtrLessThen_Offset;
	PRIVATE_MAXON_MF_POINTER(MeshAttributeClassInterface_AtrIsEqual, AtrIsEqual, true, maxon::GenericComponent, const, (Bool), const void* data1, const void* data2);
	maxon::Int MeshAttributeClassInterface_AtrIsEqual_Offset;
	PRIVATE_MAXON_MF_POINTER(MeshAttributeClassInterface_AtrAdd, AtrAdd, true, maxon::GenericComponent, const, (void), void* data1, const void* data2);
	maxon::Int MeshAttributeClassInterface_AtrAdd_Offset;
	PRIVATE_MAXON_MF_POINTER(MeshAttributeClassInterface_AtrSubstract, AtrSubstract, true, maxon::GenericComponent, const, (void), void* data1, const void* data2);
	maxon::Int MeshAttributeClassInterface_AtrSubstract_Offset;
	PRIVATE_MAXON_MF_POINTER(MeshAttributeClassInterface_AtrMultiply, AtrMultiply, true, maxon::GenericComponent, const, (void), void* data1, const void* data2);
	maxon::Int MeshAttributeClassInterface_AtrMultiply_Offset;
	PRIVATE_MAXON_MF_POINTER(MeshAttributeClassInterface_AtrMultiply_1, AtrMultiply, true, maxon::GenericComponent, const, (void), void* data, Float value);
	maxon::Int MeshAttributeClassInterface_AtrMultiply_1_Offset;
	PRIVATE_MAXON_MF_POINTER(MeshAttributeClassInterface_AtrDivide, AtrDivide, true, maxon::GenericComponent, const, (void), void* data1, const void* data2);
	maxon::Int MeshAttributeClassInterface_AtrDivide_Offset;
	PRIVATE_MAXON_MF_POINTER(MeshAttributeClassInterface_AtrDivide_1, AtrDivide, true, maxon::GenericComponent, const, (void), void* data, Float value);
	maxon::Int MeshAttributeClassInterface_AtrDivide_1_Offset;
	PRIVATE_MAXON_MF_POINTER(MeshAttributeClassInterface_AtrToString, AtrToString, true, maxon::GenericComponent, const, (String), const void* data, const FormatStatement* formatStatement);
	maxon::Int MeshAttributeClassInterface_AtrToString_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MeshAttributeClassInterface, GetDataType))
	{
		maxon::Tie(MeshAttributeClassInterface_GetDataType, MeshAttributeClassInterface_GetDataType_Offset) = MeshAttributeClassInterface_GetDataType_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MeshAttributeClassInterface, GetUnderlyingDataType))
	{
		maxon::Tie(MeshAttributeClassInterface_GetUnderlyingDataType, MeshAttributeClassInterface_GetUnderlyingDataType_Offset) = MeshAttributeClassInterface_GetUnderlyingDataType_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MeshAttributeClassInterface, InterpolateLinear))
	{
		maxon::Tie(MeshAttributeClassInterface_InterpolateLinear, MeshAttributeClassInterface_InterpolateLinear_Offset) = MeshAttributeClassInterface_InterpolateLinear_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MeshAttributeClassInterface, InterpolateInOutline))
	{
		maxon::Tie(MeshAttributeClassInterface_InterpolateInOutline, MeshAttributeClassInterface_InterpolateInOutline_Offset) = MeshAttributeClassInterface_InterpolateInOutline_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MeshAttributeClassInterface, GetDefaultValue))
	{
		maxon::Tie(MeshAttributeClassInterface_GetDefaultValue, MeshAttributeClassInterface_GetDefaultValue_Offset) = MeshAttributeClassInterface_GetDefaultValue_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MeshAttributeClassInterface, AtrLessThen))
	{
		maxon::Tie(MeshAttributeClassInterface_AtrLessThen, MeshAttributeClassInterface_AtrLessThen_Offset) = MeshAttributeClassInterface_AtrLessThen_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MeshAttributeClassInterface, AtrIsEqual))
	{
		maxon::Tie(MeshAttributeClassInterface_AtrIsEqual, MeshAttributeClassInterface_AtrIsEqual_Offset) = MeshAttributeClassInterface_AtrIsEqual_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MeshAttributeClassInterface, AtrAdd))
	{
		maxon::Tie(MeshAttributeClassInterface_AtrAdd, MeshAttributeClassInterface_AtrAdd_Offset) = MeshAttributeClassInterface_AtrAdd_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MeshAttributeClassInterface, AtrSubstract))
	{
		maxon::Tie(MeshAttributeClassInterface_AtrSubstract, MeshAttributeClassInterface_AtrSubstract_Offset) = MeshAttributeClassInterface_AtrSubstract_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MeshAttributeClassInterface, AtrMultiply))
	{
		maxon::Tie(MeshAttributeClassInterface_AtrMultiply, MeshAttributeClassInterface_AtrMultiply_Offset) = MeshAttributeClassInterface_AtrMultiply_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MeshAttributeClassInterface, AtrMultiply))
	{
		maxon::Tie(MeshAttributeClassInterface_AtrMultiply_1, MeshAttributeClassInterface_AtrMultiply_1_Offset) = MeshAttributeClassInterface_AtrMultiply_1_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MeshAttributeClassInterface, AtrDivide))
	{
		maxon::Tie(MeshAttributeClassInterface_AtrDivide, MeshAttributeClassInterface_AtrDivide_Offset) = MeshAttributeClassInterface_AtrDivide_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MeshAttributeClassInterface, AtrDivide))
	{
		maxon::Tie(MeshAttributeClassInterface_AtrDivide_1, MeshAttributeClassInterface_AtrDivide_1_Offset) = MeshAttributeClassInterface_AtrDivide_1_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MeshAttributeClassInterface, AtrToString))
	{
		maxon::Tie(MeshAttributeClassInterface_AtrToString, MeshAttributeClassInterface_AtrToString_Offset) = MeshAttributeClassInterface_AtrToString_GetPtr<W>(offset, true);
	}
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<MeshAttributeClassInterface, typename ObjectInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<MeshAttributeClassInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct MeshAttributeClassInterface::Hxx2
{
	template <typename S> class CWrapper : public ObjectInterface::Hxx2::template CWrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(AtrAdd);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(AtrDivide);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(AtrIsEqual);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(AtrLessThen);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(AtrMultiply);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(AtrSubstract);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(AtrToString);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetDataType);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetDefaultValue);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetUnderlyingDataType);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(InterpolateInOutline);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(InterpolateLinear);
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename ObjectInterface::Hxx2::template CWrapper<S>;
			if constexpr (!S::Implementation::PROXY)
			{
				if (!(Super0::InitMTablesWithBases(info, offset))) return false;
			}
			auto* vt = (MeshAttributeClassInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, MeshAttributeClassInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		PRIVATE_MAXON_MF_WRAPPER(MeshAttributeClassInterface_GetDataType, maxon::GenericComponent, const, (const DataType&)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetDataType(); }
		PRIVATE_MAXON_MF_WRAPPER(MeshAttributeClassInterface_GetUnderlyingDataType, maxon::GenericComponent, const, (const DataType&)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetUnderlyingDataType(); }
		PRIVATE_MAXON_MF_WRAPPER(MeshAttributeClassInterface_InterpolateLinear, maxon::GenericComponent, const, (void), void* data1, const void* data2, Float blend) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->InterpolateLinear(data1, data2, blend); }
		PRIVATE_MAXON_MF_WRAPPER(MeshAttributeClassInterface_InterpolateInOutline, maxon::GenericComponent, const, (void), void* data, const Block<void*>& outline, const Block<Float>& weights) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->InterpolateInOutline(data, outline, weights); }
		PRIVATE_MAXON_MF_WRAPPER(MeshAttributeClassInterface_GetDefaultValue, maxon::GenericComponent, const, (void), void* data) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetDefaultValue(data); }
		PRIVATE_MAXON_MF_WRAPPER(MeshAttributeClassInterface_AtrLessThen, maxon::GenericComponent, const, (Bool), const void* data1, const void* data2) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->AtrLessThen(data1, data2); }
		PRIVATE_MAXON_MF_WRAPPER(MeshAttributeClassInterface_AtrIsEqual, maxon::GenericComponent, const, (Bool), const void* data1, const void* data2) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->AtrIsEqual(data1, data2); }
		PRIVATE_MAXON_MF_WRAPPER(MeshAttributeClassInterface_AtrAdd, maxon::GenericComponent, const, (void), void* data1, const void* data2) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->AtrAdd(data1, data2); }
		PRIVATE_MAXON_MF_WRAPPER(MeshAttributeClassInterface_AtrSubstract, maxon::GenericComponent, const, (void), void* data1, const void* data2) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->AtrSubstract(data1, data2); }
		PRIVATE_MAXON_MF_WRAPPER(MeshAttributeClassInterface_AtrMultiply, maxon::GenericComponent, const, (void), void* data1, const void* data2) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->AtrMultiply(data1, data2); }
		PRIVATE_MAXON_MF_WRAPPER(MeshAttributeClassInterface_AtrMultiply_1, maxon::GenericComponent, const, (void), void* data, Float value) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->AtrMultiply(data, value); }
		PRIVATE_MAXON_MF_WRAPPER(MeshAttributeClassInterface_AtrDivide, maxon::GenericComponent, const, (void), void* data1, const void* data2) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->AtrDivide(data1, data2); }
		PRIVATE_MAXON_MF_WRAPPER(MeshAttributeClassInterface_AtrDivide_1, maxon::GenericComponent, const, (void), void* data, Float value) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->AtrDivide(data, value); }
		PRIVATE_MAXON_MF_WRAPPER(MeshAttributeClassInterface_AtrToString, maxon::GenericComponent, const, (String), const void* data, const FormatStatement* formatStatement) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->AtrToString(data, formatStatement); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto MeshAttributeClassInterface::GetDataType() const -> const DataType&
{
	const MeshAttributeClassInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MeshAttributeClassInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.MeshAttributeClassInterface_GetDataType_Offset), mt_.MeshAttributeClassInterface_GetDataType);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MeshAttributeClassInterface::GetUnderlyingDataType() const -> const DataType&
{
	const MeshAttributeClassInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MeshAttributeClassInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.MeshAttributeClassInterface_GetUnderlyingDataType_Offset), mt_.MeshAttributeClassInterface_GetUnderlyingDataType);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MeshAttributeClassInterface::InterpolateLinear(void* data1, const void* data2, Float blend) const -> void
{
	const MeshAttributeClassInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MeshAttributeClassInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.MeshAttributeClassInterface_InterpolateLinear_Offset), mt_.MeshAttributeClassInterface_InterpolateLinear, data1, data2, blend);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MeshAttributeClassInterface::InterpolateInOutline(void* data, const Block<void*>& outline, const Block<Float>& weights) const -> void
{
	const MeshAttributeClassInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MeshAttributeClassInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.MeshAttributeClassInterface_InterpolateInOutline_Offset), mt_.MeshAttributeClassInterface_InterpolateInOutline, data, outline, weights);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MeshAttributeClassInterface::GetDefaultValue(void* data) const -> void
{
	const MeshAttributeClassInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MeshAttributeClassInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.MeshAttributeClassInterface_GetDefaultValue_Offset), mt_.MeshAttributeClassInterface_GetDefaultValue, data);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MeshAttributeClassInterface::AtrLessThen(const void* data1, const void* data2) const -> Bool
{
	const MeshAttributeClassInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MeshAttributeClassInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.MeshAttributeClassInterface_AtrLessThen_Offset), mt_.MeshAttributeClassInterface_AtrLessThen, data1, data2);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MeshAttributeClassInterface::AtrIsEqual(const void* data1, const void* data2) const -> Bool
{
	const MeshAttributeClassInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MeshAttributeClassInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.MeshAttributeClassInterface_AtrIsEqual_Offset), mt_.MeshAttributeClassInterface_AtrIsEqual, data1, data2);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MeshAttributeClassInterface::AtrAdd(void* data1, const void* data2) const -> void
{
	const MeshAttributeClassInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MeshAttributeClassInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.MeshAttributeClassInterface_AtrAdd_Offset), mt_.MeshAttributeClassInterface_AtrAdd, data1, data2);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MeshAttributeClassInterface::AtrSubstract(void* data1, const void* data2) const -> void
{
	const MeshAttributeClassInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MeshAttributeClassInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.MeshAttributeClassInterface_AtrSubstract_Offset), mt_.MeshAttributeClassInterface_AtrSubstract, data1, data2);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MeshAttributeClassInterface::AtrMultiply(void* data1, const void* data2) const -> void
{
	const MeshAttributeClassInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MeshAttributeClassInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.MeshAttributeClassInterface_AtrMultiply_Offset), mt_.MeshAttributeClassInterface_AtrMultiply, data1, data2);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MeshAttributeClassInterface::AtrMultiply(void* data, Float value) const -> void
{
	const MeshAttributeClassInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MeshAttributeClassInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.MeshAttributeClassInterface_AtrMultiply_1_Offset), mt_.MeshAttributeClassInterface_AtrMultiply_1, data, value);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MeshAttributeClassInterface::AtrDivide(void* data1, const void* data2) const -> void
{
	const MeshAttributeClassInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MeshAttributeClassInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.MeshAttributeClassInterface_AtrDivide_Offset), mt_.MeshAttributeClassInterface_AtrDivide, data1, data2);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MeshAttributeClassInterface::AtrDivide(void* data, Float value) const -> void
{
	const MeshAttributeClassInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MeshAttributeClassInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.MeshAttributeClassInterface_AtrDivide_1_Offset), mt_.MeshAttributeClassInterface_AtrDivide_1, data, value);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MeshAttributeClassInterface::AtrToString(const void* data, const FormatStatement* formatStatement) const -> String
{
	const MeshAttributeClassInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MeshAttributeClassInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.MeshAttributeClassInterface_AtrToString_Offset), mt_.MeshAttributeClassInterface_AtrToString, data, formatStatement);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MeshAttributeClassInterface::Hxx1::ConstFn<S>::GetDataType() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const DataType&>, const DataType&>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const DataType&>, const DataType&>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const MeshAttributeClassInterface* o_ = (const MeshAttributeClassInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = MeshAttributeClassInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<const DataType&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MeshAttributeClassInterface, o_, MeshAttributeClassInterface_GetDataType) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<MeshAttributeClassInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MeshAttributeClassInterface>() : PRIVATE_MAXON_VTABLE(MeshAttributeClassInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.MeshAttributeClassInterface_GetDataType_Offset), mt_.MeshAttributeClassInterface_GetDataType));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MeshAttributeClassInterface::Hxx1::ConstFn<S>::GetUnderlyingDataType() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const DataType&>, const DataType&>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const DataType&>, const DataType&>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const MeshAttributeClassInterface* o_ = (const MeshAttributeClassInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = MeshAttributeClassInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<const DataType&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MeshAttributeClassInterface, o_, MeshAttributeClassInterface_GetUnderlyingDataType) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<MeshAttributeClassInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MeshAttributeClassInterface>() : PRIVATE_MAXON_VTABLE(MeshAttributeClassInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.MeshAttributeClassInterface_GetUnderlyingDataType_Offset), mt_.MeshAttributeClassInterface_GetUnderlyingDataType));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MeshAttributeClassInterface::Hxx1::ConstFn<S>::InterpolateLinear(void* data1, const void* data2, Float blend) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const MeshAttributeClassInterface* o_ = (const MeshAttributeClassInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = MeshAttributeClassInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MeshAttributeClassInterface, o_, MeshAttributeClassInterface_InterpolateLinear) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<MeshAttributeClassInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MeshAttributeClassInterface>() : PRIVATE_MAXON_VTABLE(MeshAttributeClassInterface, o_); 
	PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.MeshAttributeClassInterface_InterpolateLinear_Offset), mt_.MeshAttributeClassInterface_InterpolateLinear, data1, data2, blend);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MeshAttributeClassInterface::Hxx1::ConstFn<S>::InterpolateInOutline(void* data, const Block<void*>& outline, const Block<Float>& weights) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const MeshAttributeClassInterface* o_ = (const MeshAttributeClassInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = MeshAttributeClassInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MeshAttributeClassInterface, o_, MeshAttributeClassInterface_InterpolateInOutline) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<MeshAttributeClassInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MeshAttributeClassInterface>() : PRIVATE_MAXON_VTABLE(MeshAttributeClassInterface, o_); 
	PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.MeshAttributeClassInterface_InterpolateInOutline_Offset), mt_.MeshAttributeClassInterface_InterpolateInOutline, data, outline, weights);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MeshAttributeClassInterface::Hxx1::ConstFn<S>::GetDefaultValue(void* data) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const MeshAttributeClassInterface* o_ = (const MeshAttributeClassInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = MeshAttributeClassInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MeshAttributeClassInterface, o_, MeshAttributeClassInterface_GetDefaultValue) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<MeshAttributeClassInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MeshAttributeClassInterface>() : PRIVATE_MAXON_VTABLE(MeshAttributeClassInterface, o_); 
	PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.MeshAttributeClassInterface_GetDefaultValue_Offset), mt_.MeshAttributeClassInterface_GetDefaultValue, data);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MeshAttributeClassInterface::Hxx1::ConstFn<S>::AtrLessThen(const void* data1, const void* data2) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const MeshAttributeClassInterface* o_ = (const MeshAttributeClassInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = MeshAttributeClassInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MeshAttributeClassInterface, o_, MeshAttributeClassInterface_AtrLessThen) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<MeshAttributeClassInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MeshAttributeClassInterface>() : PRIVATE_MAXON_VTABLE(MeshAttributeClassInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.MeshAttributeClassInterface_AtrLessThen_Offset), mt_.MeshAttributeClassInterface_AtrLessThen, data1, data2));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MeshAttributeClassInterface::Hxx1::ConstFn<S>::AtrIsEqual(const void* data1, const void* data2) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const MeshAttributeClassInterface* o_ = (const MeshAttributeClassInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = MeshAttributeClassInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MeshAttributeClassInterface, o_, MeshAttributeClassInterface_AtrIsEqual) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<MeshAttributeClassInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MeshAttributeClassInterface>() : PRIVATE_MAXON_VTABLE(MeshAttributeClassInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.MeshAttributeClassInterface_AtrIsEqual_Offset), mt_.MeshAttributeClassInterface_AtrIsEqual, data1, data2));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MeshAttributeClassInterface::Hxx1::ConstFn<S>::AtrAdd(void* data1, const void* data2) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const MeshAttributeClassInterface* o_ = (const MeshAttributeClassInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = MeshAttributeClassInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MeshAttributeClassInterface, o_, MeshAttributeClassInterface_AtrAdd) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<MeshAttributeClassInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MeshAttributeClassInterface>() : PRIVATE_MAXON_VTABLE(MeshAttributeClassInterface, o_); 
	PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.MeshAttributeClassInterface_AtrAdd_Offset), mt_.MeshAttributeClassInterface_AtrAdd, data1, data2);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MeshAttributeClassInterface::Hxx1::ConstFn<S>::AtrSubstract(void* data1, const void* data2) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const MeshAttributeClassInterface* o_ = (const MeshAttributeClassInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = MeshAttributeClassInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MeshAttributeClassInterface, o_, MeshAttributeClassInterface_AtrSubstract) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<MeshAttributeClassInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MeshAttributeClassInterface>() : PRIVATE_MAXON_VTABLE(MeshAttributeClassInterface, o_); 
	PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.MeshAttributeClassInterface_AtrSubstract_Offset), mt_.MeshAttributeClassInterface_AtrSubstract, data1, data2);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MeshAttributeClassInterface::Hxx1::ConstFn<S>::AtrMultiply(void* data1, const void* data2) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const MeshAttributeClassInterface* o_ = (const MeshAttributeClassInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = MeshAttributeClassInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MeshAttributeClassInterface, o_, MeshAttributeClassInterface_AtrMultiply) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<MeshAttributeClassInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MeshAttributeClassInterface>() : PRIVATE_MAXON_VTABLE(MeshAttributeClassInterface, o_); 
	PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.MeshAttributeClassInterface_AtrMultiply_Offset), mt_.MeshAttributeClassInterface_AtrMultiply, data1, data2);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MeshAttributeClassInterface::Hxx1::ConstFn<S>::AtrMultiply(void* data, Float value) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const MeshAttributeClassInterface* o_ = (const MeshAttributeClassInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = MeshAttributeClassInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MeshAttributeClassInterface, o_, MeshAttributeClassInterface_AtrMultiply_1) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<MeshAttributeClassInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MeshAttributeClassInterface>() : PRIVATE_MAXON_VTABLE(MeshAttributeClassInterface, o_); 
	PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.MeshAttributeClassInterface_AtrMultiply_1_Offset), mt_.MeshAttributeClassInterface_AtrMultiply_1, data, value);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MeshAttributeClassInterface::Hxx1::ConstFn<S>::AtrDivide(void* data1, const void* data2) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const MeshAttributeClassInterface* o_ = (const MeshAttributeClassInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = MeshAttributeClassInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MeshAttributeClassInterface, o_, MeshAttributeClassInterface_AtrDivide) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<MeshAttributeClassInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MeshAttributeClassInterface>() : PRIVATE_MAXON_VTABLE(MeshAttributeClassInterface, o_); 
	PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.MeshAttributeClassInterface_AtrDivide_Offset), mt_.MeshAttributeClassInterface_AtrDivide, data1, data2);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MeshAttributeClassInterface::Hxx1::ConstFn<S>::AtrDivide(void* data, Float value) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const MeshAttributeClassInterface* o_ = (const MeshAttributeClassInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = MeshAttributeClassInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MeshAttributeClassInterface, o_, MeshAttributeClassInterface_AtrDivide_1) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<MeshAttributeClassInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MeshAttributeClassInterface>() : PRIVATE_MAXON_VTABLE(MeshAttributeClassInterface, o_); 
	PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.MeshAttributeClassInterface_AtrDivide_1_Offset), mt_.MeshAttributeClassInterface_AtrDivide_1, data, value);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MeshAttributeClassInterface::Hxx1::ConstFn<S>::AtrToString(const void* data, const FormatStatement* formatStatement) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const MeshAttributeClassInterface* o_ = (const MeshAttributeClassInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = MeshAttributeClassInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MeshAttributeClassInterface, o_, MeshAttributeClassInterface_AtrToString) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<MeshAttributeClassInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MeshAttributeClassInterface>() : PRIVATE_MAXON_VTABLE(MeshAttributeClassInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.MeshAttributeClassInterface_AtrToString_Offset), mt_.MeshAttributeClassInterface_AtrToString, data, formatStatement));
}
auto MeshAttributeClassInterface::GetPtr() -> Ptr { return Ptr(this); }
auto MeshAttributeClassInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_mesh_attribute_base)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_MeshAttributeClassInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_MeshAttributeClassInterface() { new (s_ui_maxon_MeshAttributeClassInterface) maxon::EntityUse(MeshAttributeClassInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/mesh_attribute_base.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_MeshAttributeClassInterface(MeshAttributeClassInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/mesh_attribute_base.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif

struct CustomDataTagClassInterface::MTable
{
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetDisplayClassId);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetIcon);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetResourceId);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetTagPluginFlags);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetTagPluginId);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetTagPluginLevel);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetTagPluginName);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(IsSdsCompatible);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(Message);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(Read);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(Write);
	static const maxon::Char* const _ids;
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	PRIVATE_MAXON_MF_POINTER(CustomDataTagClassInterface_GetTagPluginId, GetTagPluginId, true, maxon::GenericComponent, const, (Int32));
	maxon::Int CustomDataTagClassInterface_GetTagPluginId_Offset;
	PRIVATE_MAXON_MF_POINTER(CustomDataTagClassInterface_GetTagPluginName, GetTagPluginName, true, maxon::GenericComponent, const, (const String&));
	maxon::Int CustomDataTagClassInterface_GetTagPluginName_Offset;
	PRIVATE_MAXON_MF_POINTER(CustomDataTagClassInterface_GetResourceId, GetResourceId, true, maxon::GenericComponent, const, (const String&));
	maxon::Int CustomDataTagClassInterface_GetResourceId_Offset;
	PRIVATE_MAXON_MF_POINTER(CustomDataTagClassInterface_GetTagPluginLevel, GetTagPluginLevel, true, maxon::GenericComponent, const, (Int32));
	maxon::Int CustomDataTagClassInterface_GetTagPluginLevel_Offset;
	PRIVATE_MAXON_MF_POINTER(CustomDataTagClassInterface_GetDisplayClassId, GetDisplayClassId, true, maxon::GenericComponent, const, (Id));
	maxon::Int CustomDataTagClassInterface_GetDisplayClassId_Offset;
	PRIVATE_MAXON_MF_POINTER(CustomDataTagClassInterface_IsSdsCompatible, IsSdsCompatible, true, maxon::GenericComponent, const, (Bool), Int32& floatSize);
	maxon::Int CustomDataTagClassInterface_IsSdsCompatible_Offset;
	PRIVATE_MAXON_MF_POINTER(CustomDataTagClassInterface_Read, Read, true, maxon::GenericComponent, const, (Result<void>), void* data, HyperFile* hf, Int32 level);
	maxon::Int CustomDataTagClassInterface_Read_Offset;
	PRIVATE_MAXON_MF_POINTER(CustomDataTagClassInterface_Write, Write, true, maxon::GenericComponent, const, (Result<void>), const void* data, HyperFile* hf);
	maxon::Int CustomDataTagClassInterface_Write_Offset;
	PRIVATE_MAXON_MF_POINTER(CustomDataTagClassInterface_GetIcon, GetIcon, true, maxon::GenericComponent, const, (Int32), Bool perPolyVertex);
	maxon::Int CustomDataTagClassInterface_GetIcon_Offset;
	PRIVATE_MAXON_MF_POINTER(CustomDataTagClassInterface_GetTagPluginFlags, GetTagPluginFlags, true, maxon::GenericComponent, const, (Int32));
	maxon::Int CustomDataTagClassInterface_GetTagPluginFlags_Offset;
	PRIVATE_MAXON_MF_POINTER(CustomDataTagClassInterface_Message, Message, true, maxon::GenericComponent, const, (Bool), GeListNode* node, Int32 type, void* data);
	maxon::Int CustomDataTagClassInterface_Message_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CustomDataTagClassInterface, GetTagPluginId))
	{
		maxon::Tie(CustomDataTagClassInterface_GetTagPluginId, CustomDataTagClassInterface_GetTagPluginId_Offset) = CustomDataTagClassInterface_GetTagPluginId_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CustomDataTagClassInterface, GetTagPluginName))
	{
		maxon::Tie(CustomDataTagClassInterface_GetTagPluginName, CustomDataTagClassInterface_GetTagPluginName_Offset) = CustomDataTagClassInterface_GetTagPluginName_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CustomDataTagClassInterface, GetResourceId))
	{
		maxon::Tie(CustomDataTagClassInterface_GetResourceId, CustomDataTagClassInterface_GetResourceId_Offset) = CustomDataTagClassInterface_GetResourceId_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CustomDataTagClassInterface, GetTagPluginLevel))
	{
		maxon::Tie(CustomDataTagClassInterface_GetTagPluginLevel, CustomDataTagClassInterface_GetTagPluginLevel_Offset) = CustomDataTagClassInterface_GetTagPluginLevel_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CustomDataTagClassInterface, GetDisplayClassId))
	{
		maxon::Tie(CustomDataTagClassInterface_GetDisplayClassId, CustomDataTagClassInterface_GetDisplayClassId_Offset) = CustomDataTagClassInterface_GetDisplayClassId_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CustomDataTagClassInterface, IsSdsCompatible))
	{
		maxon::Tie(CustomDataTagClassInterface_IsSdsCompatible, CustomDataTagClassInterface_IsSdsCompatible_Offset) = CustomDataTagClassInterface_IsSdsCompatible_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CustomDataTagClassInterface, Read))
	{
		maxon::Tie(CustomDataTagClassInterface_Read, CustomDataTagClassInterface_Read_Offset) = CustomDataTagClassInterface_Read_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CustomDataTagClassInterface, Write))
	{
		maxon::Tie(CustomDataTagClassInterface_Write, CustomDataTagClassInterface_Write_Offset) = CustomDataTagClassInterface_Write_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CustomDataTagClassInterface, GetIcon))
	{
		maxon::Tie(CustomDataTagClassInterface_GetIcon, CustomDataTagClassInterface_GetIcon_Offset) = CustomDataTagClassInterface_GetIcon_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CustomDataTagClassInterface, GetTagPluginFlags))
	{
		maxon::Tie(CustomDataTagClassInterface_GetTagPluginFlags, CustomDataTagClassInterface_GetTagPluginFlags_Offset) = CustomDataTagClassInterface_GetTagPluginFlags_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CustomDataTagClassInterface, Message))
	{
		maxon::Tie(CustomDataTagClassInterface_Message, CustomDataTagClassInterface_Message_Offset) = CustomDataTagClassInterface_Message_GetPtr<W>(offset, true);
	}
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<CustomDataTagClassInterface, typename MeshAttributeClassInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<CustomDataTagClassInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct CustomDataTagClassInterface::Hxx2
{
	template <typename S> class CWrapper : public MeshAttributeClassInterface::Hxx2::template CWrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetDisplayClassId);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetIcon);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetResourceId);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetTagPluginFlags);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetTagPluginId);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetTagPluginLevel);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetTagPluginName);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(IsSdsCompatible);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(Message);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(Read);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(Write);
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename MeshAttributeClassInterface::Hxx2::template CWrapper<S>;
			if constexpr (!S::Implementation::PROXY)
			{
				if (!(Super0::InitMTablesWithBases(info, offset))) return false;
			}
			auto* vt = (CustomDataTagClassInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, CustomDataTagClassInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		PRIVATE_MAXON_MF_WRAPPER(CustomDataTagClassInterface_GetTagPluginId, maxon::GenericComponent, const, (Int32)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetTagPluginId(); }
		PRIVATE_MAXON_MF_WRAPPER(CustomDataTagClassInterface_GetTagPluginName, maxon::GenericComponent, const, (const String&)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetTagPluginName(); }
		PRIVATE_MAXON_MF_WRAPPER(CustomDataTagClassInterface_GetResourceId, maxon::GenericComponent, const, (const String&)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetResourceId(); }
		PRIVATE_MAXON_MF_WRAPPER(CustomDataTagClassInterface_GetTagPluginLevel, maxon::GenericComponent, const, (Int32)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetTagPluginLevel(); }
		PRIVATE_MAXON_MF_WRAPPER(CustomDataTagClassInterface_GetDisplayClassId, maxon::GenericComponent, const, (Id)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetDisplayClassId(); }
		PRIVATE_MAXON_MF_WRAPPER(CustomDataTagClassInterface_IsSdsCompatible, maxon::GenericComponent, const, (Bool), Int32& floatSize) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->IsSdsCompatible(floatSize); }
		PRIVATE_MAXON_MF_WRAPPER(CustomDataTagClassInterface_Read, maxon::GenericComponent, const, (Result<void>), void* data, HyperFile* hf, Int32 level) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->Read(data, hf, level); }
		PRIVATE_MAXON_MF_WRAPPER(CustomDataTagClassInterface_Write, maxon::GenericComponent, const, (Result<void>), const void* data, HyperFile* hf) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->Write(data, hf); }
		PRIVATE_MAXON_MF_WRAPPER(CustomDataTagClassInterface_GetIcon, maxon::GenericComponent, const, (Int32), Bool perPolyVertex) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetIcon(perPolyVertex); }
		PRIVATE_MAXON_MF_WRAPPER(CustomDataTagClassInterface_GetTagPluginFlags, maxon::GenericComponent, const, (Int32)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetTagPluginFlags(); }
		PRIVATE_MAXON_MF_WRAPPER(CustomDataTagClassInterface_Message, maxon::GenericComponent, const, (Bool), GeListNode* node, Int32 type, void* data) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->Message(node, type, data); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto CustomDataTagClassInterface::GetTagPluginId() const -> Int32
{
	const CustomDataTagClassInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(CustomDataTagClassInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.CustomDataTagClassInterface_GetTagPluginId_Offset), mt_.CustomDataTagClassInterface_GetTagPluginId);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CustomDataTagClassInterface::GetTagPluginName() const -> const String&
{
	const CustomDataTagClassInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(CustomDataTagClassInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.CustomDataTagClassInterface_GetTagPluginName_Offset), mt_.CustomDataTagClassInterface_GetTagPluginName);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CustomDataTagClassInterface::GetResourceId() const -> const String&
{
	const CustomDataTagClassInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(CustomDataTagClassInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.CustomDataTagClassInterface_GetResourceId_Offset), mt_.CustomDataTagClassInterface_GetResourceId);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CustomDataTagClassInterface::GetTagPluginLevel() const -> Int32
{
	const CustomDataTagClassInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(CustomDataTagClassInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.CustomDataTagClassInterface_GetTagPluginLevel_Offset), mt_.CustomDataTagClassInterface_GetTagPluginLevel);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CustomDataTagClassInterface::GetDisplayClassId() const -> Id
{
	const CustomDataTagClassInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(CustomDataTagClassInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.CustomDataTagClassInterface_GetDisplayClassId_Offset), mt_.CustomDataTagClassInterface_GetDisplayClassId);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CustomDataTagClassInterface::IsSdsCompatible(Int32& floatSize) const -> Bool
{
	const CustomDataTagClassInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(CustomDataTagClassInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.CustomDataTagClassInterface_IsSdsCompatible_Offset), mt_.CustomDataTagClassInterface_IsSdsCompatible, floatSize);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CustomDataTagClassInterface::Read(void* data, HyperFile* hf, Int32 level) const -> Result<void>
{
	const CustomDataTagClassInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(CustomDataTagClassInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.CustomDataTagClassInterface_Read_Offset), mt_.CustomDataTagClassInterface_Read, data, hf, level);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CustomDataTagClassInterface::Write(const void* data, HyperFile* hf) const -> Result<void>
{
	const CustomDataTagClassInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(CustomDataTagClassInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.CustomDataTagClassInterface_Write_Offset), mt_.CustomDataTagClassInterface_Write, data, hf);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CustomDataTagClassInterface::GetIcon(Bool perPolyVertex) const -> Int32
{
	const CustomDataTagClassInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(CustomDataTagClassInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.CustomDataTagClassInterface_GetIcon_Offset), mt_.CustomDataTagClassInterface_GetIcon, perPolyVertex);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CustomDataTagClassInterface::GetTagPluginFlags() const -> Int32
{
	const CustomDataTagClassInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(CustomDataTagClassInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.CustomDataTagClassInterface_GetTagPluginFlags_Offset), mt_.CustomDataTagClassInterface_GetTagPluginFlags);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CustomDataTagClassInterface::Message(GeListNode* node, Int32 type, void* data) const -> Bool
{
	const CustomDataTagClassInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(CustomDataTagClassInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.CustomDataTagClassInterface_Message_Offset), mt_.CustomDataTagClassInterface_Message, node, type, data);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CustomDataTagClassInterface::Hxx1::ConstFn<S>::GetTagPluginId() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int32>, Int32>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int32>, Int32>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const CustomDataTagClassInterface* o_ = (const CustomDataTagClassInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = CustomDataTagClassInterface::NullValuePtr(); if (!o_) return 0; } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CustomDataTagClassInterface, o_, CustomDataTagClassInterface_GetTagPluginId) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<CustomDataTagClassInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CustomDataTagClassInterface>() : PRIVATE_MAXON_VTABLE(CustomDataTagClassInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.CustomDataTagClassInterface_GetTagPluginId_Offset), mt_.CustomDataTagClassInterface_GetTagPluginId));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CustomDataTagClassInterface::Hxx1::ConstFn<S>::GetTagPluginName() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const String&>, const String&>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const String&>, const String&>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const CustomDataTagClassInterface* o_ = (const CustomDataTagClassInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = CustomDataTagClassInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<const String&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CustomDataTagClassInterface, o_, CustomDataTagClassInterface_GetTagPluginName) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<CustomDataTagClassInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CustomDataTagClassInterface>() : PRIVATE_MAXON_VTABLE(CustomDataTagClassInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.CustomDataTagClassInterface_GetTagPluginName_Offset), mt_.CustomDataTagClassInterface_GetTagPluginName));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CustomDataTagClassInterface::Hxx1::ConstFn<S>::GetResourceId() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const String&>, const String&>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const String&>, const String&>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const CustomDataTagClassInterface* o_ = (const CustomDataTagClassInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = CustomDataTagClassInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<const String&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CustomDataTagClassInterface, o_, CustomDataTagClassInterface_GetResourceId) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<CustomDataTagClassInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CustomDataTagClassInterface>() : PRIVATE_MAXON_VTABLE(CustomDataTagClassInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.CustomDataTagClassInterface_GetResourceId_Offset), mt_.CustomDataTagClassInterface_GetResourceId));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CustomDataTagClassInterface::Hxx1::ConstFn<S>::GetTagPluginLevel() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int32>, Int32>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int32>, Int32>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const CustomDataTagClassInterface* o_ = (const CustomDataTagClassInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = CustomDataTagClassInterface::NullValuePtr(); if (!o_) return 0; } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CustomDataTagClassInterface, o_, CustomDataTagClassInterface_GetTagPluginLevel) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<CustomDataTagClassInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CustomDataTagClassInterface>() : PRIVATE_MAXON_VTABLE(CustomDataTagClassInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.CustomDataTagClassInterface_GetTagPluginLevel_Offset), mt_.CustomDataTagClassInterface_GetTagPluginLevel));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CustomDataTagClassInterface::Hxx1::ConstFn<S>::GetDisplayClassId() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Id>, Id>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Id>, Id>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const CustomDataTagClassInterface* o_ = (const CustomDataTagClassInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = CustomDataTagClassInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<Id>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CustomDataTagClassInterface, o_, CustomDataTagClassInterface_GetDisplayClassId) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<CustomDataTagClassInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CustomDataTagClassInterface>() : PRIVATE_MAXON_VTABLE(CustomDataTagClassInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.CustomDataTagClassInterface_GetDisplayClassId_Offset), mt_.CustomDataTagClassInterface_GetDisplayClassId));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CustomDataTagClassInterface::Hxx1::ConstFn<S>::IsSdsCompatible(Int32& floatSize) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const CustomDataTagClassInterface* o_ = (const CustomDataTagClassInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = CustomDataTagClassInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CustomDataTagClassInterface, o_, CustomDataTagClassInterface_IsSdsCompatible) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<CustomDataTagClassInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CustomDataTagClassInterface>() : PRIVATE_MAXON_VTABLE(CustomDataTagClassInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.CustomDataTagClassInterface_IsSdsCompatible_Offset), mt_.CustomDataTagClassInterface_IsSdsCompatible, floatSize));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CustomDataTagClassInterface::Hxx1::ConstFn<S>::Read(void* data, HyperFile* hf, Int32 level) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const CustomDataTagClassInterface* o_ = (const CustomDataTagClassInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = CustomDataTagClassInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CustomDataTagClassInterface, o_, CustomDataTagClassInterface_Read) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<CustomDataTagClassInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CustomDataTagClassInterface>() : PRIVATE_MAXON_VTABLE(CustomDataTagClassInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.CustomDataTagClassInterface_Read_Offset), mt_.CustomDataTagClassInterface_Read, data, hf, level));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CustomDataTagClassInterface::Hxx1::ConstFn<S>::Write(const void* data, HyperFile* hf) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const CustomDataTagClassInterface* o_ = (const CustomDataTagClassInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = CustomDataTagClassInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CustomDataTagClassInterface, o_, CustomDataTagClassInterface_Write) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<CustomDataTagClassInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CustomDataTagClassInterface>() : PRIVATE_MAXON_VTABLE(CustomDataTagClassInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.CustomDataTagClassInterface_Write_Offset), mt_.CustomDataTagClassInterface_Write, data, hf));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CustomDataTagClassInterface::Hxx1::ConstFn<S>::GetIcon(Bool perPolyVertex) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int32>, Int32>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int32>, Int32>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const CustomDataTagClassInterface* o_ = (const CustomDataTagClassInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = CustomDataTagClassInterface::NullValuePtr(); if (!o_) return 0; } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CustomDataTagClassInterface, o_, CustomDataTagClassInterface_GetIcon) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<CustomDataTagClassInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CustomDataTagClassInterface>() : PRIVATE_MAXON_VTABLE(CustomDataTagClassInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.CustomDataTagClassInterface_GetIcon_Offset), mt_.CustomDataTagClassInterface_GetIcon, perPolyVertex));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CustomDataTagClassInterface::Hxx1::ConstFn<S>::GetDefaultResourceId() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const String&>, const String&>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const String&>, const String&>::type>; static_assert(!std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value, "Can't invoke MAXON_FUNCTION CustomDataTagClassInterface::GetDefaultResourceId on super."); if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const CustomDataTagClassInterface* o_ = (const CustomDataTagClassInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = CustomDataTagClassInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<const String&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (o_->GetDefaultResourceId());
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CustomDataTagClassInterface::Hxx1::ConstFn<S>::GetTagPluginFlags() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int32>, Int32>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int32>, Int32>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const CustomDataTagClassInterface* o_ = (const CustomDataTagClassInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = CustomDataTagClassInterface::NullValuePtr(); if (!o_) return 0; } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CustomDataTagClassInterface, o_, CustomDataTagClassInterface_GetTagPluginFlags) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<CustomDataTagClassInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CustomDataTagClassInterface>() : PRIVATE_MAXON_VTABLE(CustomDataTagClassInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.CustomDataTagClassInterface_GetTagPluginFlags_Offset), mt_.CustomDataTagClassInterface_GetTagPluginFlags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CustomDataTagClassInterface::Hxx1::ConstFn<S>::Message(GeListNode* node, Int32 type, void* data) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const CustomDataTagClassInterface* o_ = (const CustomDataTagClassInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = CustomDataTagClassInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CustomDataTagClassInterface, o_, CustomDataTagClassInterface_Message) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<CustomDataTagClassInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CustomDataTagClassInterface>() : PRIVATE_MAXON_VTABLE(CustomDataTagClassInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.CustomDataTagClassInterface_Message_Offset), mt_.CustomDataTagClassInterface_Message, node, type, data));
}
auto CustomDataTagClassInterface::GetPtr() -> Ptr { return Ptr(this); }
auto CustomDataTagClassInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_mesh_attribute_base)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_CustomDataTagClassInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_CustomDataTagClassInterface() { new (s_ui_maxon_CustomDataTagClassInterface) maxon::EntityUse(CustomDataTagClassInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/mesh_attribute_base.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_CustomDataTagClassInterface(CustomDataTagClassInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/mesh_attribute_base.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

