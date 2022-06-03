
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
	Result<void> (*CustomDataTagDisplayInterface_Init) (maxon::GenericComponent* this_, BaseTag* tag);
	maxon::Int CustomDataTagDisplayInterface_Init_Offset;
	Result<void> (*CustomDataTagDisplayInterface_Draw) (maxon::GenericComponent* this_, BaseTag* tag, BaseObject* op, BaseDraw* bd, BaseDrawHelp* bh);
	maxon::Int CustomDataTagDisplayInterface_Draw_Offset;
	Result<void> (*CustomDataTagDisplayInterface_DisplayControl) (const maxon::GenericComponent* this_, BaseTag* tag, BaseDocument* doc, BaseObject* op, BaseDraw* bd, BaseDrawHelp* bh, ControlDisplayStruct& cds);
	maxon::Int CustomDataTagDisplayInterface_DisplayControl_Offset;
	Result<void> (*CustomDataTagDisplayInterface_InitDisplayControl) (maxon::GenericComponent* this_, BaseTag* tag, BaseDocument* doc, BaseDraw* bd, const AtomArray* active);
	maxon::Int CustomDataTagDisplayInterface_InitDisplayControl_Offset;
	void (*CustomDataTagDisplayInterface_FreeDisplayControl) (maxon::GenericComponent* this_, BaseTag* tag);
	maxon::Int CustomDataTagDisplayInterface_FreeDisplayControl_Offset;
	void (*CustomDataTagDisplayInterface_Reset) (maxon::GenericComponent* this_);
	maxon::Int CustomDataTagDisplayInterface_Reset_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CustomDataTagDisplayInterface, Init))
	{
		CustomDataTagDisplayInterface_Init = &W::CustomDataTagDisplayInterface_Init;
		CustomDataTagDisplayInterface_Init_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CustomDataTagDisplayInterface, Draw))
	{
		CustomDataTagDisplayInterface_Draw = &W::CustomDataTagDisplayInterface_Draw;
		CustomDataTagDisplayInterface_Draw_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CustomDataTagDisplayInterface, DisplayControl))
	{
		CustomDataTagDisplayInterface_DisplayControl = &W::CustomDataTagDisplayInterface_DisplayControl;
		CustomDataTagDisplayInterface_DisplayControl_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CustomDataTagDisplayInterface, InitDisplayControl))
	{
		CustomDataTagDisplayInterface_InitDisplayControl = &W::CustomDataTagDisplayInterface_InitDisplayControl;
		CustomDataTagDisplayInterface_InitDisplayControl_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CustomDataTagDisplayInterface, FreeDisplayControl))
	{
		CustomDataTagDisplayInterface_FreeDisplayControl = &W::CustomDataTagDisplayInterface_FreeDisplayControl;
		CustomDataTagDisplayInterface_FreeDisplayControl_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CustomDataTagDisplayInterface, Reset))
	{
		CustomDataTagDisplayInterface_Reset = &W::CustomDataTagDisplayInterface_Reset;
		CustomDataTagDisplayInterface_Reset_Offset = offset;
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
			if (!S::Implementation::PROXY && !(Super0::InitMTablesWithBases(info, offset))) return false;
			auto* vt = (CustomDataTagDisplayInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, CustomDataTagDisplayInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		static Result<void> CustomDataTagDisplayInterface_Init(maxon::GenericComponent* this_, BaseTag* tag) { return ((typename S::Implementation*) this_)->Init(tag); }
		static Result<void> CustomDataTagDisplayInterface_Draw(maxon::GenericComponent* this_, BaseTag* tag, BaseObject* op, BaseDraw* bd, BaseDrawHelp* bh) { return ((typename S::Implementation*) this_)->Draw(tag, op, bd, bh); }
		static Result<void> CustomDataTagDisplayInterface_DisplayControl(const maxon::GenericComponent* this_, BaseTag* tag, BaseDocument* doc, BaseObject* op, BaseDraw* bd, BaseDrawHelp* bh, ControlDisplayStruct& cds) { return ((const typename S::Implementation*) this_)->DisplayControl(tag, doc, op, bd, bh, cds); }
		static Result<void> CustomDataTagDisplayInterface_InitDisplayControl(maxon::GenericComponent* this_, BaseTag* tag, BaseDocument* doc, BaseDraw* bd, const AtomArray* active) { return ((typename S::Implementation*) this_)->InitDisplayControl(tag, doc, bd, active); }
		static void CustomDataTagDisplayInterface_FreeDisplayControl(maxon::GenericComponent* this_, BaseTag* tag) { return ((typename S::Implementation*) this_)->FreeDisplayControl(tag); }
		static void CustomDataTagDisplayInterface_Reset(maxon::GenericComponent* this_) { return ((typename S::Implementation*) this_)->Reset(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto CustomDataTagDisplayInterface::Init(BaseTag* tag) -> Result<void>
{
	const CustomDataTagDisplayInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(CustomDataTagDisplayInterface, this); return mt_.CustomDataTagDisplayInterface_Init((maxon::GenericComponent*) this + mt_.CustomDataTagDisplayInterface_Init_Offset, tag);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CustomDataTagDisplayInterface::Draw(BaseTag* tag, BaseObject* op, BaseDraw* bd, BaseDrawHelp* bh) -> Result<void>
{
	const CustomDataTagDisplayInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(CustomDataTagDisplayInterface, this); return mt_.CustomDataTagDisplayInterface_Draw((maxon::GenericComponent*) this + mt_.CustomDataTagDisplayInterface_Draw_Offset, tag, op, bd, bh);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CustomDataTagDisplayInterface::DisplayControl(BaseTag* tag, BaseDocument* doc, BaseObject* op, BaseDraw* bd, BaseDrawHelp* bh, ControlDisplayStruct& cds) const -> Result<void>
{
	const CustomDataTagDisplayInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(CustomDataTagDisplayInterface, this); return mt_.CustomDataTagDisplayInterface_DisplayControl((const maxon::GenericComponent*) this + mt_.CustomDataTagDisplayInterface_DisplayControl_Offset, tag, doc, op, bd, bh, cds);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CustomDataTagDisplayInterface::InitDisplayControl(BaseTag* tag, BaseDocument* doc, BaseDraw* bd, const AtomArray* active) -> Result<void>
{
	const CustomDataTagDisplayInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(CustomDataTagDisplayInterface, this); return mt_.CustomDataTagDisplayInterface_InitDisplayControl((maxon::GenericComponent*) this + mt_.CustomDataTagDisplayInterface_InitDisplayControl_Offset, tag, doc, bd, active);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CustomDataTagDisplayInterface::FreeDisplayControl(BaseTag* tag) -> void
{
	const CustomDataTagDisplayInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(CustomDataTagDisplayInterface, this); return mt_.CustomDataTagDisplayInterface_FreeDisplayControl((maxon::GenericComponent*) this + mt_.CustomDataTagDisplayInterface_FreeDisplayControl_Offset, tag);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CustomDataTagDisplayInterface::Reset() -> void
{
	const CustomDataTagDisplayInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(CustomDataTagDisplayInterface, this); return mt_.CustomDataTagDisplayInterface_Reset((maxon::GenericComponent*) this + mt_.CustomDataTagDisplayInterface_Reset_Offset);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CustomDataTagDisplayInterface::Hxx1::Fn<S>::Init(BaseTag* tag) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); CustomDataTagDisplayInterface* o_ = (CustomDataTagDisplayInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CustomDataTagDisplayInterface, o_, CustomDataTagDisplayInterface_Init) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<CustomDataTagDisplayInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CustomDataTagDisplayInterface>() : PRIVATE_MAXON_VTABLE(CustomDataTagDisplayInterface, o_); 
	return (mt_.CustomDataTagDisplayInterface_Init(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.CustomDataTagDisplayInterface_Init_Offset, tag));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CustomDataTagDisplayInterface::Hxx1::COWFn<S>::Init(BaseTag* tag) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); CustomDataTagDisplayInterface* o_ = (CustomDataTagDisplayInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CustomDataTagDisplayInterface, o_, CustomDataTagDisplayInterface_Init) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<CustomDataTagDisplayInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CustomDataTagDisplayInterface>() : PRIVATE_MAXON_VTABLE(CustomDataTagDisplayInterface, o_); 
	return (mt_.CustomDataTagDisplayInterface_Init(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.CustomDataTagDisplayInterface_Init_Offset, tag));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CustomDataTagDisplayInterface::Hxx1::Fn<S>::Draw(BaseTag* tag, BaseObject* op, BaseDraw* bd, BaseDrawHelp* bh) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); CustomDataTagDisplayInterface* o_ = (CustomDataTagDisplayInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CustomDataTagDisplayInterface, o_, CustomDataTagDisplayInterface_Draw) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<CustomDataTagDisplayInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CustomDataTagDisplayInterface>() : PRIVATE_MAXON_VTABLE(CustomDataTagDisplayInterface, o_); 
	return (mt_.CustomDataTagDisplayInterface_Draw(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.CustomDataTagDisplayInterface_Draw_Offset, tag, op, bd, bh));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CustomDataTagDisplayInterface::Hxx1::COWFn<S>::Draw(BaseTag* tag, BaseObject* op, BaseDraw* bd, BaseDrawHelp* bh) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); CustomDataTagDisplayInterface* o_ = (CustomDataTagDisplayInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CustomDataTagDisplayInterface, o_, CustomDataTagDisplayInterface_Draw) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<CustomDataTagDisplayInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CustomDataTagDisplayInterface>() : PRIVATE_MAXON_VTABLE(CustomDataTagDisplayInterface, o_); 
	return (mt_.CustomDataTagDisplayInterface_Draw(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.CustomDataTagDisplayInterface_Draw_Offset, tag, op, bd, bh));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CustomDataTagDisplayInterface::Hxx1::ConstFn<S>::DisplayControl(BaseTag* tag, BaseDocument* doc, BaseObject* op, BaseDraw* bd, BaseDrawHelp* bh, ControlDisplayStruct& cds) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const CustomDataTagDisplayInterface* o_ = (const CustomDataTagDisplayInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = CustomDataTagDisplayInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CustomDataTagDisplayInterface, o_, CustomDataTagDisplayInterface_DisplayControl) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<CustomDataTagDisplayInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CustomDataTagDisplayInterface>() : PRIVATE_MAXON_VTABLE(CustomDataTagDisplayInterface, o_); 
	return (mt_.CustomDataTagDisplayInterface_DisplayControl(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.CustomDataTagDisplayInterface_DisplayControl_Offset, tag, doc, op, bd, bh, cds));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CustomDataTagDisplayInterface::Hxx1::Fn<S>::InitDisplayControl(BaseTag* tag, BaseDocument* doc, BaseDraw* bd, const AtomArray* active) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); CustomDataTagDisplayInterface* o_ = (CustomDataTagDisplayInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CustomDataTagDisplayInterface, o_, CustomDataTagDisplayInterface_InitDisplayControl) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<CustomDataTagDisplayInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CustomDataTagDisplayInterface>() : PRIVATE_MAXON_VTABLE(CustomDataTagDisplayInterface, o_); 
	return (mt_.CustomDataTagDisplayInterface_InitDisplayControl(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.CustomDataTagDisplayInterface_InitDisplayControl_Offset, tag, doc, bd, active));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CustomDataTagDisplayInterface::Hxx1::COWFn<S>::InitDisplayControl(BaseTag* tag, BaseDocument* doc, BaseDraw* bd, const AtomArray* active) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); CustomDataTagDisplayInterface* o_ = (CustomDataTagDisplayInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CustomDataTagDisplayInterface, o_, CustomDataTagDisplayInterface_InitDisplayControl) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<CustomDataTagDisplayInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CustomDataTagDisplayInterface>() : PRIVATE_MAXON_VTABLE(CustomDataTagDisplayInterface, o_); 
	return (mt_.CustomDataTagDisplayInterface_InitDisplayControl(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.CustomDataTagDisplayInterface_InitDisplayControl_Offset, tag, doc, bd, active));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CustomDataTagDisplayInterface::Hxx1::Fn<S>::FreeDisplayControl(BaseTag* tag) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); CustomDataTagDisplayInterface* o_ = (CustomDataTagDisplayInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { DebugStop(); return maxon::PrivateLogNullptrError(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CustomDataTagDisplayInterface, o_, CustomDataTagDisplayInterface_FreeDisplayControl) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<CustomDataTagDisplayInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CustomDataTagDisplayInterface>() : PRIVATE_MAXON_VTABLE(CustomDataTagDisplayInterface, o_); 
	mt_.CustomDataTagDisplayInterface_FreeDisplayControl(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.CustomDataTagDisplayInterface_FreeDisplayControl_Offset, tag);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CustomDataTagDisplayInterface::Hxx1::COWFn<S>::FreeDisplayControl(BaseTag* tag) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); CustomDataTagDisplayInterface* o_ = (CustomDataTagDisplayInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CustomDataTagDisplayInterface, o_, CustomDataTagDisplayInterface_FreeDisplayControl) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<CustomDataTagDisplayInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CustomDataTagDisplayInterface>() : PRIVATE_MAXON_VTABLE(CustomDataTagDisplayInterface, o_); 
	mt_.CustomDataTagDisplayInterface_FreeDisplayControl(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.CustomDataTagDisplayInterface_FreeDisplayControl_Offset, tag);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CustomDataTagDisplayInterface::Hxx1::Fn<S>::Reset() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); CustomDataTagDisplayInterface* o_ = (CustomDataTagDisplayInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { DebugStop(); return maxon::PrivateLogNullptrError(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CustomDataTagDisplayInterface, o_, CustomDataTagDisplayInterface_Reset) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<CustomDataTagDisplayInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CustomDataTagDisplayInterface>() : PRIVATE_MAXON_VTABLE(CustomDataTagDisplayInterface, o_); 
	mt_.CustomDataTagDisplayInterface_Reset(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.CustomDataTagDisplayInterface_Reset_Offset);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CustomDataTagDisplayInterface::Hxx1::COWFn<S>::Reset() -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); CustomDataTagDisplayInterface* o_ = (CustomDataTagDisplayInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CustomDataTagDisplayInterface, o_, CustomDataTagDisplayInterface_Reset) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<CustomDataTagDisplayInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CustomDataTagDisplayInterface>() : PRIVATE_MAXON_VTABLE(CustomDataTagDisplayInterface, o_); 
	mt_.CustomDataTagDisplayInterface_Reset(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.CustomDataTagDisplayInterface_Reset_Offset);
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
	const DataType& (*MeshAttributeClassInterface_GetDataType) (const maxon::GenericComponent* this_);
	maxon::Int MeshAttributeClassInterface_GetDataType_Offset;
	const DataType& (*MeshAttributeClassInterface_GetUnderlyingDataType) (const maxon::GenericComponent* this_);
	maxon::Int MeshAttributeClassInterface_GetUnderlyingDataType_Offset;
	void (*MeshAttributeClassInterface_InterpolateLinear) (const maxon::GenericComponent* this_, void* data1, const void* data2, Float blend);
	maxon::Int MeshAttributeClassInterface_InterpolateLinear_Offset;
	void (*MeshAttributeClassInterface_InterpolateInOutline) (const maxon::GenericComponent* this_, void* data, const Block<void*>& outline, const Block<Float>& weights);
	maxon::Int MeshAttributeClassInterface_InterpolateInOutline_Offset;
	void (*MeshAttributeClassInterface_GetDefaultValue) (const maxon::GenericComponent* this_, void* data);
	maxon::Int MeshAttributeClassInterface_GetDefaultValue_Offset;
	Bool (*MeshAttributeClassInterface_AtrLessThen) (const maxon::GenericComponent* this_, const void* data1, const void* data2);
	maxon::Int MeshAttributeClassInterface_AtrLessThen_Offset;
	Bool (*MeshAttributeClassInterface_AtrIsEqual) (const maxon::GenericComponent* this_, const void* data1, const void* data2);
	maxon::Int MeshAttributeClassInterface_AtrIsEqual_Offset;
	void (*MeshAttributeClassInterface_AtrAdd) (const maxon::GenericComponent* this_, void* data1, const void* data2);
	maxon::Int MeshAttributeClassInterface_AtrAdd_Offset;
	void (*MeshAttributeClassInterface_AtrSubstract) (const maxon::GenericComponent* this_, void* data1, const void* data2);
	maxon::Int MeshAttributeClassInterface_AtrSubstract_Offset;
	void (*MeshAttributeClassInterface_AtrMultiply) (const maxon::GenericComponent* this_, void* data1, const void* data2);
	maxon::Int MeshAttributeClassInterface_AtrMultiply_Offset;
	void (*MeshAttributeClassInterface_AtrMultiply_1) (const maxon::GenericComponent* this_, void* data, Float value);
	maxon::Int MeshAttributeClassInterface_AtrMultiply_1_Offset;
	void (*MeshAttributeClassInterface_AtrDivide) (const maxon::GenericComponent* this_, void* data1, const void* data2);
	maxon::Int MeshAttributeClassInterface_AtrDivide_Offset;
	void (*MeshAttributeClassInterface_AtrDivide_1) (const maxon::GenericComponent* this_, void* data, Float value);
	maxon::Int MeshAttributeClassInterface_AtrDivide_1_Offset;
	String (*MeshAttributeClassInterface_AtrToString) (const maxon::GenericComponent* this_, const void* data, const FormatStatement* formatStatement);
	maxon::Int MeshAttributeClassInterface_AtrToString_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MeshAttributeClassInterface, GetDataType))
	{
		MeshAttributeClassInterface_GetDataType = &W::MeshAttributeClassInterface_GetDataType;
		MeshAttributeClassInterface_GetDataType_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MeshAttributeClassInterface, GetUnderlyingDataType))
	{
		MeshAttributeClassInterface_GetUnderlyingDataType = &W::MeshAttributeClassInterface_GetUnderlyingDataType;
		MeshAttributeClassInterface_GetUnderlyingDataType_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MeshAttributeClassInterface, InterpolateLinear))
	{
		MeshAttributeClassInterface_InterpolateLinear = &W::MeshAttributeClassInterface_InterpolateLinear;
		MeshAttributeClassInterface_InterpolateLinear_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MeshAttributeClassInterface, InterpolateInOutline))
	{
		MeshAttributeClassInterface_InterpolateInOutline = &W::MeshAttributeClassInterface_InterpolateInOutline;
		MeshAttributeClassInterface_InterpolateInOutline_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MeshAttributeClassInterface, GetDefaultValue))
	{
		MeshAttributeClassInterface_GetDefaultValue = &W::MeshAttributeClassInterface_GetDefaultValue;
		MeshAttributeClassInterface_GetDefaultValue_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MeshAttributeClassInterface, AtrLessThen))
	{
		MeshAttributeClassInterface_AtrLessThen = &W::MeshAttributeClassInterface_AtrLessThen;
		MeshAttributeClassInterface_AtrLessThen_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MeshAttributeClassInterface, AtrIsEqual))
	{
		MeshAttributeClassInterface_AtrIsEqual = &W::MeshAttributeClassInterface_AtrIsEqual;
		MeshAttributeClassInterface_AtrIsEqual_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MeshAttributeClassInterface, AtrAdd))
	{
		MeshAttributeClassInterface_AtrAdd = &W::MeshAttributeClassInterface_AtrAdd;
		MeshAttributeClassInterface_AtrAdd_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MeshAttributeClassInterface, AtrSubstract))
	{
		MeshAttributeClassInterface_AtrSubstract = &W::MeshAttributeClassInterface_AtrSubstract;
		MeshAttributeClassInterface_AtrSubstract_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MeshAttributeClassInterface, AtrMultiply))
	{
		MeshAttributeClassInterface_AtrMultiply = &W::MeshAttributeClassInterface_AtrMultiply;
		MeshAttributeClassInterface_AtrMultiply_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MeshAttributeClassInterface, AtrMultiply))
	{
		MeshAttributeClassInterface_AtrMultiply_1 = &W::MeshAttributeClassInterface_AtrMultiply_1;
		MeshAttributeClassInterface_AtrMultiply_1_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MeshAttributeClassInterface, AtrDivide))
	{
		MeshAttributeClassInterface_AtrDivide = &W::MeshAttributeClassInterface_AtrDivide;
		MeshAttributeClassInterface_AtrDivide_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MeshAttributeClassInterface, AtrDivide))
	{
		MeshAttributeClassInterface_AtrDivide_1 = &W::MeshAttributeClassInterface_AtrDivide_1;
		MeshAttributeClassInterface_AtrDivide_1_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MeshAttributeClassInterface, AtrToString))
	{
		MeshAttributeClassInterface_AtrToString = &W::MeshAttributeClassInterface_AtrToString;
		MeshAttributeClassInterface_AtrToString_Offset = offset;
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
			if (!S::Implementation::PROXY && !(Super0::InitMTablesWithBases(info, offset))) return false;
			auto* vt = (MeshAttributeClassInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, MeshAttributeClassInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		static const DataType& MeshAttributeClassInterface_GetDataType(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetDataType(); }
		static const DataType& MeshAttributeClassInterface_GetUnderlyingDataType(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetUnderlyingDataType(); }
		static void MeshAttributeClassInterface_InterpolateLinear(const maxon::GenericComponent* this_, void* data1, const void* data2, Float blend) { return ((const typename S::Implementation*) this_)->InterpolateLinear(data1, data2, blend); }
		static void MeshAttributeClassInterface_InterpolateInOutline(const maxon::GenericComponent* this_, void* data, const Block<void*>& outline, const Block<Float>& weights) { return ((const typename S::Implementation*) this_)->InterpolateInOutline(data, outline, weights); }
		static void MeshAttributeClassInterface_GetDefaultValue(const maxon::GenericComponent* this_, void* data) { return ((const typename S::Implementation*) this_)->GetDefaultValue(data); }
		static Bool MeshAttributeClassInterface_AtrLessThen(const maxon::GenericComponent* this_, const void* data1, const void* data2) { return ((const typename S::Implementation*) this_)->AtrLessThen(data1, data2); }
		static Bool MeshAttributeClassInterface_AtrIsEqual(const maxon::GenericComponent* this_, const void* data1, const void* data2) { return ((const typename S::Implementation*) this_)->AtrIsEqual(data1, data2); }
		static void MeshAttributeClassInterface_AtrAdd(const maxon::GenericComponent* this_, void* data1, const void* data2) { return ((const typename S::Implementation*) this_)->AtrAdd(data1, data2); }
		static void MeshAttributeClassInterface_AtrSubstract(const maxon::GenericComponent* this_, void* data1, const void* data2) { return ((const typename S::Implementation*) this_)->AtrSubstract(data1, data2); }
		static void MeshAttributeClassInterface_AtrMultiply(const maxon::GenericComponent* this_, void* data1, const void* data2) { return ((const typename S::Implementation*) this_)->AtrMultiply(data1, data2); }
		static void MeshAttributeClassInterface_AtrMultiply_1(const maxon::GenericComponent* this_, void* data, Float value) { return ((const typename S::Implementation*) this_)->AtrMultiply(data, value); }
		static void MeshAttributeClassInterface_AtrDivide(const maxon::GenericComponent* this_, void* data1, const void* data2) { return ((const typename S::Implementation*) this_)->AtrDivide(data1, data2); }
		static void MeshAttributeClassInterface_AtrDivide_1(const maxon::GenericComponent* this_, void* data, Float value) { return ((const typename S::Implementation*) this_)->AtrDivide(data, value); }
		static String MeshAttributeClassInterface_AtrToString(const maxon::GenericComponent* this_, const void* data, const FormatStatement* formatStatement) { return ((const typename S::Implementation*) this_)->AtrToString(data, formatStatement); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto MeshAttributeClassInterface::GetDataType() const -> const DataType&
{
	const MeshAttributeClassInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MeshAttributeClassInterface, this); return mt_.MeshAttributeClassInterface_GetDataType((const maxon::GenericComponent*) this + mt_.MeshAttributeClassInterface_GetDataType_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MeshAttributeClassInterface::GetUnderlyingDataType() const -> const DataType&
{
	const MeshAttributeClassInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MeshAttributeClassInterface, this); return mt_.MeshAttributeClassInterface_GetUnderlyingDataType((const maxon::GenericComponent*) this + mt_.MeshAttributeClassInterface_GetUnderlyingDataType_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MeshAttributeClassInterface::InterpolateLinear(void* data1, const void* data2, Float blend) const -> void
{
	const MeshAttributeClassInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MeshAttributeClassInterface, this); return mt_.MeshAttributeClassInterface_InterpolateLinear((const maxon::GenericComponent*) this + mt_.MeshAttributeClassInterface_InterpolateLinear_Offset, data1, data2, blend);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MeshAttributeClassInterface::InterpolateInOutline(void* data, const Block<void*>& outline, const Block<Float>& weights) const -> void
{
	const MeshAttributeClassInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MeshAttributeClassInterface, this); return mt_.MeshAttributeClassInterface_InterpolateInOutline((const maxon::GenericComponent*) this + mt_.MeshAttributeClassInterface_InterpolateInOutline_Offset, data, outline, weights);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MeshAttributeClassInterface::GetDefaultValue(void* data) const -> void
{
	const MeshAttributeClassInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MeshAttributeClassInterface, this); return mt_.MeshAttributeClassInterface_GetDefaultValue((const maxon::GenericComponent*) this + mt_.MeshAttributeClassInterface_GetDefaultValue_Offset, data);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MeshAttributeClassInterface::AtrLessThen(const void* data1, const void* data2) const -> Bool
{
	const MeshAttributeClassInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MeshAttributeClassInterface, this); return mt_.MeshAttributeClassInterface_AtrLessThen((const maxon::GenericComponent*) this + mt_.MeshAttributeClassInterface_AtrLessThen_Offset, data1, data2);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MeshAttributeClassInterface::AtrIsEqual(const void* data1, const void* data2) const -> Bool
{
	const MeshAttributeClassInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MeshAttributeClassInterface, this); return mt_.MeshAttributeClassInterface_AtrIsEqual((const maxon::GenericComponent*) this + mt_.MeshAttributeClassInterface_AtrIsEqual_Offset, data1, data2);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MeshAttributeClassInterface::AtrAdd(void* data1, const void* data2) const -> void
{
	const MeshAttributeClassInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MeshAttributeClassInterface, this); return mt_.MeshAttributeClassInterface_AtrAdd((const maxon::GenericComponent*) this + mt_.MeshAttributeClassInterface_AtrAdd_Offset, data1, data2);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MeshAttributeClassInterface::AtrSubstract(void* data1, const void* data2) const -> void
{
	const MeshAttributeClassInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MeshAttributeClassInterface, this); return mt_.MeshAttributeClassInterface_AtrSubstract((const maxon::GenericComponent*) this + mt_.MeshAttributeClassInterface_AtrSubstract_Offset, data1, data2);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MeshAttributeClassInterface::AtrMultiply(void* data1, const void* data2) const -> void
{
	const MeshAttributeClassInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MeshAttributeClassInterface, this); return mt_.MeshAttributeClassInterface_AtrMultiply((const maxon::GenericComponent*) this + mt_.MeshAttributeClassInterface_AtrMultiply_Offset, data1, data2);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MeshAttributeClassInterface::AtrMultiply(void* data, Float value) const -> void
{
	const MeshAttributeClassInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MeshAttributeClassInterface, this); return mt_.MeshAttributeClassInterface_AtrMultiply_1((const maxon::GenericComponent*) this + mt_.MeshAttributeClassInterface_AtrMultiply_1_Offset, data, value);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MeshAttributeClassInterface::AtrDivide(void* data1, const void* data2) const -> void
{
	const MeshAttributeClassInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MeshAttributeClassInterface, this); return mt_.MeshAttributeClassInterface_AtrDivide((const maxon::GenericComponent*) this + mt_.MeshAttributeClassInterface_AtrDivide_Offset, data1, data2);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MeshAttributeClassInterface::AtrDivide(void* data, Float value) const -> void
{
	const MeshAttributeClassInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MeshAttributeClassInterface, this); return mt_.MeshAttributeClassInterface_AtrDivide_1((const maxon::GenericComponent*) this + mt_.MeshAttributeClassInterface_AtrDivide_1_Offset, data, value);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MeshAttributeClassInterface::AtrToString(const void* data, const FormatStatement* formatStatement) const -> String
{
	const MeshAttributeClassInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MeshAttributeClassInterface, this); return mt_.MeshAttributeClassInterface_AtrToString((const maxon::GenericComponent*) this + mt_.MeshAttributeClassInterface_AtrToString_Offset, data, formatStatement);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MeshAttributeClassInterface::Hxx1::ConstFn<S>::GetDataType() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const DataType&>, const DataType&>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const DataType&>, const DataType&>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const MeshAttributeClassInterface* o_ = (const MeshAttributeClassInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = MeshAttributeClassInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<const DataType&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MeshAttributeClassInterface, o_, MeshAttributeClassInterface_GetDataType) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<MeshAttributeClassInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MeshAttributeClassInterface>() : PRIVATE_MAXON_VTABLE(MeshAttributeClassInterface, o_); 
	return (mt_.MeshAttributeClassInterface_GetDataType(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.MeshAttributeClassInterface_GetDataType_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MeshAttributeClassInterface::Hxx1::ConstFn<S>::GetUnderlyingDataType() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const DataType&>, const DataType&>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const DataType&>, const DataType&>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const MeshAttributeClassInterface* o_ = (const MeshAttributeClassInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = MeshAttributeClassInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<const DataType&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MeshAttributeClassInterface, o_, MeshAttributeClassInterface_GetUnderlyingDataType) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<MeshAttributeClassInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MeshAttributeClassInterface>() : PRIVATE_MAXON_VTABLE(MeshAttributeClassInterface, o_); 
	return (mt_.MeshAttributeClassInterface_GetUnderlyingDataType(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.MeshAttributeClassInterface_GetUnderlyingDataType_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MeshAttributeClassInterface::Hxx1::ConstFn<S>::InterpolateLinear(void* data1, const void* data2, Float blend) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const MeshAttributeClassInterface* o_ = (const MeshAttributeClassInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = MeshAttributeClassInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MeshAttributeClassInterface, o_, MeshAttributeClassInterface_InterpolateLinear) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<MeshAttributeClassInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MeshAttributeClassInterface>() : PRIVATE_MAXON_VTABLE(MeshAttributeClassInterface, o_); 
	mt_.MeshAttributeClassInterface_InterpolateLinear(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.MeshAttributeClassInterface_InterpolateLinear_Offset, data1, data2, blend);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MeshAttributeClassInterface::Hxx1::ConstFn<S>::InterpolateInOutline(void* data, const Block<void*>& outline, const Block<Float>& weights) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const MeshAttributeClassInterface* o_ = (const MeshAttributeClassInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = MeshAttributeClassInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MeshAttributeClassInterface, o_, MeshAttributeClassInterface_InterpolateInOutline) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<MeshAttributeClassInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MeshAttributeClassInterface>() : PRIVATE_MAXON_VTABLE(MeshAttributeClassInterface, o_); 
	mt_.MeshAttributeClassInterface_InterpolateInOutline(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.MeshAttributeClassInterface_InterpolateInOutline_Offset, data, outline, weights);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MeshAttributeClassInterface::Hxx1::ConstFn<S>::GetDefaultValue(void* data) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const MeshAttributeClassInterface* o_ = (const MeshAttributeClassInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = MeshAttributeClassInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MeshAttributeClassInterface, o_, MeshAttributeClassInterface_GetDefaultValue) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<MeshAttributeClassInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MeshAttributeClassInterface>() : PRIVATE_MAXON_VTABLE(MeshAttributeClassInterface, o_); 
	mt_.MeshAttributeClassInterface_GetDefaultValue(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.MeshAttributeClassInterface_GetDefaultValue_Offset, data);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MeshAttributeClassInterface::Hxx1::ConstFn<S>::AtrLessThen(const void* data1, const void* data2) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const MeshAttributeClassInterface* o_ = (const MeshAttributeClassInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = MeshAttributeClassInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MeshAttributeClassInterface, o_, MeshAttributeClassInterface_AtrLessThen) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<MeshAttributeClassInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MeshAttributeClassInterface>() : PRIVATE_MAXON_VTABLE(MeshAttributeClassInterface, o_); 
	return (mt_.MeshAttributeClassInterface_AtrLessThen(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.MeshAttributeClassInterface_AtrLessThen_Offset, data1, data2));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MeshAttributeClassInterface::Hxx1::ConstFn<S>::AtrIsEqual(const void* data1, const void* data2) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const MeshAttributeClassInterface* o_ = (const MeshAttributeClassInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = MeshAttributeClassInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MeshAttributeClassInterface, o_, MeshAttributeClassInterface_AtrIsEqual) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<MeshAttributeClassInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MeshAttributeClassInterface>() : PRIVATE_MAXON_VTABLE(MeshAttributeClassInterface, o_); 
	return (mt_.MeshAttributeClassInterface_AtrIsEqual(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.MeshAttributeClassInterface_AtrIsEqual_Offset, data1, data2));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MeshAttributeClassInterface::Hxx1::ConstFn<S>::AtrAdd(void* data1, const void* data2) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const MeshAttributeClassInterface* o_ = (const MeshAttributeClassInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = MeshAttributeClassInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MeshAttributeClassInterface, o_, MeshAttributeClassInterface_AtrAdd) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<MeshAttributeClassInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MeshAttributeClassInterface>() : PRIVATE_MAXON_VTABLE(MeshAttributeClassInterface, o_); 
	mt_.MeshAttributeClassInterface_AtrAdd(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.MeshAttributeClassInterface_AtrAdd_Offset, data1, data2);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MeshAttributeClassInterface::Hxx1::ConstFn<S>::AtrSubstract(void* data1, const void* data2) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const MeshAttributeClassInterface* o_ = (const MeshAttributeClassInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = MeshAttributeClassInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MeshAttributeClassInterface, o_, MeshAttributeClassInterface_AtrSubstract) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<MeshAttributeClassInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MeshAttributeClassInterface>() : PRIVATE_MAXON_VTABLE(MeshAttributeClassInterface, o_); 
	mt_.MeshAttributeClassInterface_AtrSubstract(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.MeshAttributeClassInterface_AtrSubstract_Offset, data1, data2);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MeshAttributeClassInterface::Hxx1::ConstFn<S>::AtrMultiply(void* data1, const void* data2) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const MeshAttributeClassInterface* o_ = (const MeshAttributeClassInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = MeshAttributeClassInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MeshAttributeClassInterface, o_, MeshAttributeClassInterface_AtrMultiply) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<MeshAttributeClassInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MeshAttributeClassInterface>() : PRIVATE_MAXON_VTABLE(MeshAttributeClassInterface, o_); 
	mt_.MeshAttributeClassInterface_AtrMultiply(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.MeshAttributeClassInterface_AtrMultiply_Offset, data1, data2);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MeshAttributeClassInterface::Hxx1::ConstFn<S>::AtrMultiply(void* data, Float value) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const MeshAttributeClassInterface* o_ = (const MeshAttributeClassInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = MeshAttributeClassInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MeshAttributeClassInterface, o_, MeshAttributeClassInterface_AtrMultiply_1) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<MeshAttributeClassInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MeshAttributeClassInterface>() : PRIVATE_MAXON_VTABLE(MeshAttributeClassInterface, o_); 
	mt_.MeshAttributeClassInterface_AtrMultiply_1(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.MeshAttributeClassInterface_AtrMultiply_1_Offset, data, value);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MeshAttributeClassInterface::Hxx1::ConstFn<S>::AtrDivide(void* data1, const void* data2) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const MeshAttributeClassInterface* o_ = (const MeshAttributeClassInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = MeshAttributeClassInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MeshAttributeClassInterface, o_, MeshAttributeClassInterface_AtrDivide) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<MeshAttributeClassInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MeshAttributeClassInterface>() : PRIVATE_MAXON_VTABLE(MeshAttributeClassInterface, o_); 
	mt_.MeshAttributeClassInterface_AtrDivide(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.MeshAttributeClassInterface_AtrDivide_Offset, data1, data2);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MeshAttributeClassInterface::Hxx1::ConstFn<S>::AtrDivide(void* data, Float value) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const MeshAttributeClassInterface* o_ = (const MeshAttributeClassInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = MeshAttributeClassInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MeshAttributeClassInterface, o_, MeshAttributeClassInterface_AtrDivide_1) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<MeshAttributeClassInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MeshAttributeClassInterface>() : PRIVATE_MAXON_VTABLE(MeshAttributeClassInterface, o_); 
	mt_.MeshAttributeClassInterface_AtrDivide_1(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.MeshAttributeClassInterface_AtrDivide_1_Offset, data, value);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MeshAttributeClassInterface::Hxx1::ConstFn<S>::AtrToString(const void* data, const FormatStatement* formatStatement) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const MeshAttributeClassInterface* o_ = (const MeshAttributeClassInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = MeshAttributeClassInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MeshAttributeClassInterface, o_, MeshAttributeClassInterface_AtrToString) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<MeshAttributeClassInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MeshAttributeClassInterface>() : PRIVATE_MAXON_VTABLE(MeshAttributeClassInterface, o_); 
	return (mt_.MeshAttributeClassInterface_AtrToString(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.MeshAttributeClassInterface_AtrToString_Offset, data, formatStatement));
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
	Int32 (*CustomDataTagClassInterface_GetTagPluginId) (const maxon::GenericComponent* this_);
	maxon::Int CustomDataTagClassInterface_GetTagPluginId_Offset;
	const String& (*CustomDataTagClassInterface_GetTagPluginName) (const maxon::GenericComponent* this_);
	maxon::Int CustomDataTagClassInterface_GetTagPluginName_Offset;
	const String& (*CustomDataTagClassInterface_GetResourceId) (const maxon::GenericComponent* this_);
	maxon::Int CustomDataTagClassInterface_GetResourceId_Offset;
	Int32 (*CustomDataTagClassInterface_GetTagPluginLevel) (const maxon::GenericComponent* this_);
	maxon::Int CustomDataTagClassInterface_GetTagPluginLevel_Offset;
	Id (*CustomDataTagClassInterface_GetDisplayClassId) (const maxon::GenericComponent* this_);
	maxon::Int CustomDataTagClassInterface_GetDisplayClassId_Offset;
	Bool (*CustomDataTagClassInterface_IsSdsCompatible) (const maxon::GenericComponent* this_, Int32& floatSize);
	maxon::Int CustomDataTagClassInterface_IsSdsCompatible_Offset;
	Result<void> (*CustomDataTagClassInterface_Read) (const maxon::GenericComponent* this_, void* data, HyperFile* hf, Int32 level);
	maxon::Int CustomDataTagClassInterface_Read_Offset;
	Result<void> (*CustomDataTagClassInterface_Write) (const maxon::GenericComponent* this_, const void* data, HyperFile* hf);
	maxon::Int CustomDataTagClassInterface_Write_Offset;
	Int32 (*CustomDataTagClassInterface_GetIcon) (const maxon::GenericComponent* this_, Bool perPolyVertex);
	maxon::Int CustomDataTagClassInterface_GetIcon_Offset;
	Int32 (*CustomDataTagClassInterface_GetTagPluginFlags) (const maxon::GenericComponent* this_);
	maxon::Int CustomDataTagClassInterface_GetTagPluginFlags_Offset;
	Bool (*CustomDataTagClassInterface_Message) (const maxon::GenericComponent* this_, GeListNode* node, Int32 type, void* data);
	maxon::Int CustomDataTagClassInterface_Message_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CustomDataTagClassInterface, GetTagPluginId))
	{
		CustomDataTagClassInterface_GetTagPluginId = &W::CustomDataTagClassInterface_GetTagPluginId;
		CustomDataTagClassInterface_GetTagPluginId_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CustomDataTagClassInterface, GetTagPluginName))
	{
		CustomDataTagClassInterface_GetTagPluginName = &W::CustomDataTagClassInterface_GetTagPluginName;
		CustomDataTagClassInterface_GetTagPluginName_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CustomDataTagClassInterface, GetResourceId))
	{
		CustomDataTagClassInterface_GetResourceId = &W::CustomDataTagClassInterface_GetResourceId;
		CustomDataTagClassInterface_GetResourceId_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CustomDataTagClassInterface, GetTagPluginLevel))
	{
		CustomDataTagClassInterface_GetTagPluginLevel = &W::CustomDataTagClassInterface_GetTagPluginLevel;
		CustomDataTagClassInterface_GetTagPluginLevel_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CustomDataTagClassInterface, GetDisplayClassId))
	{
		CustomDataTagClassInterface_GetDisplayClassId = &W::CustomDataTagClassInterface_GetDisplayClassId;
		CustomDataTagClassInterface_GetDisplayClassId_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CustomDataTagClassInterface, IsSdsCompatible))
	{
		CustomDataTagClassInterface_IsSdsCompatible = &W::CustomDataTagClassInterface_IsSdsCompatible;
		CustomDataTagClassInterface_IsSdsCompatible_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CustomDataTagClassInterface, Read))
	{
		CustomDataTagClassInterface_Read = &W::CustomDataTagClassInterface_Read;
		CustomDataTagClassInterface_Read_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CustomDataTagClassInterface, Write))
	{
		CustomDataTagClassInterface_Write = &W::CustomDataTagClassInterface_Write;
		CustomDataTagClassInterface_Write_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CustomDataTagClassInterface, GetIcon))
	{
		CustomDataTagClassInterface_GetIcon = &W::CustomDataTagClassInterface_GetIcon;
		CustomDataTagClassInterface_GetIcon_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CustomDataTagClassInterface, GetTagPluginFlags))
	{
		CustomDataTagClassInterface_GetTagPluginFlags = &W::CustomDataTagClassInterface_GetTagPluginFlags;
		CustomDataTagClassInterface_GetTagPluginFlags_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CustomDataTagClassInterface, Message))
	{
		CustomDataTagClassInterface_Message = &W::CustomDataTagClassInterface_Message;
		CustomDataTagClassInterface_Message_Offset = offset;
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
			if (!S::Implementation::PROXY && !(Super0::InitMTablesWithBases(info, offset))) return false;
			auto* vt = (CustomDataTagClassInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, CustomDataTagClassInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		static Int32 CustomDataTagClassInterface_GetTagPluginId(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetTagPluginId(); }
		static const String& CustomDataTagClassInterface_GetTagPluginName(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetTagPluginName(); }
		static const String& CustomDataTagClassInterface_GetResourceId(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetResourceId(); }
		static Int32 CustomDataTagClassInterface_GetTagPluginLevel(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetTagPluginLevel(); }
		static Id CustomDataTagClassInterface_GetDisplayClassId(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetDisplayClassId(); }
		static Bool CustomDataTagClassInterface_IsSdsCompatible(const maxon::GenericComponent* this_, Int32& floatSize) { return ((const typename S::Implementation*) this_)->IsSdsCompatible(floatSize); }
		static Result<void> CustomDataTagClassInterface_Read(const maxon::GenericComponent* this_, void* data, HyperFile* hf, Int32 level) { return ((const typename S::Implementation*) this_)->Read(data, hf, level); }
		static Result<void> CustomDataTagClassInterface_Write(const maxon::GenericComponent* this_, const void* data, HyperFile* hf) { return ((const typename S::Implementation*) this_)->Write(data, hf); }
		static Int32 CustomDataTagClassInterface_GetIcon(const maxon::GenericComponent* this_, Bool perPolyVertex) { return ((const typename S::Implementation*) this_)->GetIcon(perPolyVertex); }
		static Int32 CustomDataTagClassInterface_GetTagPluginFlags(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetTagPluginFlags(); }
		static Bool CustomDataTagClassInterface_Message(const maxon::GenericComponent* this_, GeListNode* node, Int32 type, void* data) { return ((const typename S::Implementation*) this_)->Message(node, type, data); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto CustomDataTagClassInterface::GetTagPluginId() const -> Int32
{
	const CustomDataTagClassInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(CustomDataTagClassInterface, this); return mt_.CustomDataTagClassInterface_GetTagPluginId((const maxon::GenericComponent*) this + mt_.CustomDataTagClassInterface_GetTagPluginId_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CustomDataTagClassInterface::GetTagPluginName() const -> const String&
{
	const CustomDataTagClassInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(CustomDataTagClassInterface, this); return mt_.CustomDataTagClassInterface_GetTagPluginName((const maxon::GenericComponent*) this + mt_.CustomDataTagClassInterface_GetTagPluginName_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CustomDataTagClassInterface::GetResourceId() const -> const String&
{
	const CustomDataTagClassInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(CustomDataTagClassInterface, this); return mt_.CustomDataTagClassInterface_GetResourceId((const maxon::GenericComponent*) this + mt_.CustomDataTagClassInterface_GetResourceId_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CustomDataTagClassInterface::GetTagPluginLevel() const -> Int32
{
	const CustomDataTagClassInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(CustomDataTagClassInterface, this); return mt_.CustomDataTagClassInterface_GetTagPluginLevel((const maxon::GenericComponent*) this + mt_.CustomDataTagClassInterface_GetTagPluginLevel_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CustomDataTagClassInterface::GetDisplayClassId() const -> Id
{
	const CustomDataTagClassInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(CustomDataTagClassInterface, this); return mt_.CustomDataTagClassInterface_GetDisplayClassId((const maxon::GenericComponent*) this + mt_.CustomDataTagClassInterface_GetDisplayClassId_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CustomDataTagClassInterface::IsSdsCompatible(Int32& floatSize) const -> Bool
{
	const CustomDataTagClassInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(CustomDataTagClassInterface, this); return mt_.CustomDataTagClassInterface_IsSdsCompatible((const maxon::GenericComponent*) this + mt_.CustomDataTagClassInterface_IsSdsCompatible_Offset, floatSize);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CustomDataTagClassInterface::Read(void* data, HyperFile* hf, Int32 level) const -> Result<void>
{
	const CustomDataTagClassInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(CustomDataTagClassInterface, this); return mt_.CustomDataTagClassInterface_Read((const maxon::GenericComponent*) this + mt_.CustomDataTagClassInterface_Read_Offset, data, hf, level);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CustomDataTagClassInterface::Write(const void* data, HyperFile* hf) const -> Result<void>
{
	const CustomDataTagClassInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(CustomDataTagClassInterface, this); return mt_.CustomDataTagClassInterface_Write((const maxon::GenericComponent*) this + mt_.CustomDataTagClassInterface_Write_Offset, data, hf);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CustomDataTagClassInterface::GetIcon(Bool perPolyVertex) const -> Int32
{
	const CustomDataTagClassInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(CustomDataTagClassInterface, this); return mt_.CustomDataTagClassInterface_GetIcon((const maxon::GenericComponent*) this + mt_.CustomDataTagClassInterface_GetIcon_Offset, perPolyVertex);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CustomDataTagClassInterface::GetTagPluginFlags() const -> Int32
{
	const CustomDataTagClassInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(CustomDataTagClassInterface, this); return mt_.CustomDataTagClassInterface_GetTagPluginFlags((const maxon::GenericComponent*) this + mt_.CustomDataTagClassInterface_GetTagPluginFlags_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CustomDataTagClassInterface::Message(GeListNode* node, Int32 type, void* data) const -> Bool
{
	const CustomDataTagClassInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(CustomDataTagClassInterface, this); return mt_.CustomDataTagClassInterface_Message((const maxon::GenericComponent*) this + mt_.CustomDataTagClassInterface_Message_Offset, node, type, data);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CustomDataTagClassInterface::Hxx1::ConstFn<S>::GetTagPluginId() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int32>, Int32>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int32>, Int32>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const CustomDataTagClassInterface* o_ = (const CustomDataTagClassInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = CustomDataTagClassInterface::NullValuePtr(); if (!o_) return 0; } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CustomDataTagClassInterface, o_, CustomDataTagClassInterface_GetTagPluginId) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<CustomDataTagClassInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CustomDataTagClassInterface>() : PRIVATE_MAXON_VTABLE(CustomDataTagClassInterface, o_); 
	return (mt_.CustomDataTagClassInterface_GetTagPluginId(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.CustomDataTagClassInterface_GetTagPluginId_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CustomDataTagClassInterface::Hxx1::ConstFn<S>::GetTagPluginName() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const String&>, const String&>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const String&>, const String&>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const CustomDataTagClassInterface* o_ = (const CustomDataTagClassInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = CustomDataTagClassInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<const String&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CustomDataTagClassInterface, o_, CustomDataTagClassInterface_GetTagPluginName) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<CustomDataTagClassInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CustomDataTagClassInterface>() : PRIVATE_MAXON_VTABLE(CustomDataTagClassInterface, o_); 
	return (mt_.CustomDataTagClassInterface_GetTagPluginName(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.CustomDataTagClassInterface_GetTagPluginName_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CustomDataTagClassInterface::Hxx1::ConstFn<S>::GetResourceId() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const String&>, const String&>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const String&>, const String&>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const CustomDataTagClassInterface* o_ = (const CustomDataTagClassInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = CustomDataTagClassInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<const String&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CustomDataTagClassInterface, o_, CustomDataTagClassInterface_GetResourceId) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<CustomDataTagClassInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CustomDataTagClassInterface>() : PRIVATE_MAXON_VTABLE(CustomDataTagClassInterface, o_); 
	return (mt_.CustomDataTagClassInterface_GetResourceId(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.CustomDataTagClassInterface_GetResourceId_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CustomDataTagClassInterface::Hxx1::ConstFn<S>::GetTagPluginLevel() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int32>, Int32>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int32>, Int32>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const CustomDataTagClassInterface* o_ = (const CustomDataTagClassInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = CustomDataTagClassInterface::NullValuePtr(); if (!o_) return 0; } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CustomDataTagClassInterface, o_, CustomDataTagClassInterface_GetTagPluginLevel) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<CustomDataTagClassInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CustomDataTagClassInterface>() : PRIVATE_MAXON_VTABLE(CustomDataTagClassInterface, o_); 
	return (mt_.CustomDataTagClassInterface_GetTagPluginLevel(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.CustomDataTagClassInterface_GetTagPluginLevel_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CustomDataTagClassInterface::Hxx1::ConstFn<S>::GetDisplayClassId() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Id>, Id>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Id>, Id>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const CustomDataTagClassInterface* o_ = (const CustomDataTagClassInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = CustomDataTagClassInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<Id>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CustomDataTagClassInterface, o_, CustomDataTagClassInterface_GetDisplayClassId) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<CustomDataTagClassInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CustomDataTagClassInterface>() : PRIVATE_MAXON_VTABLE(CustomDataTagClassInterface, o_); 
	return (mt_.CustomDataTagClassInterface_GetDisplayClassId(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.CustomDataTagClassInterface_GetDisplayClassId_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CustomDataTagClassInterface::Hxx1::ConstFn<S>::IsSdsCompatible(Int32& floatSize) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const CustomDataTagClassInterface* o_ = (const CustomDataTagClassInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = CustomDataTagClassInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CustomDataTagClassInterface, o_, CustomDataTagClassInterface_IsSdsCompatible) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<CustomDataTagClassInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CustomDataTagClassInterface>() : PRIVATE_MAXON_VTABLE(CustomDataTagClassInterface, o_); 
	return (mt_.CustomDataTagClassInterface_IsSdsCompatible(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.CustomDataTagClassInterface_IsSdsCompatible_Offset, floatSize));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CustomDataTagClassInterface::Hxx1::ConstFn<S>::Read(void* data, HyperFile* hf, Int32 level) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const CustomDataTagClassInterface* o_ = (const CustomDataTagClassInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = CustomDataTagClassInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CustomDataTagClassInterface, o_, CustomDataTagClassInterface_Read) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<CustomDataTagClassInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CustomDataTagClassInterface>() : PRIVATE_MAXON_VTABLE(CustomDataTagClassInterface, o_); 
	return (mt_.CustomDataTagClassInterface_Read(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.CustomDataTagClassInterface_Read_Offset, data, hf, level));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CustomDataTagClassInterface::Hxx1::ConstFn<S>::Write(const void* data, HyperFile* hf) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const CustomDataTagClassInterface* o_ = (const CustomDataTagClassInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = CustomDataTagClassInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CustomDataTagClassInterface, o_, CustomDataTagClassInterface_Write) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<CustomDataTagClassInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CustomDataTagClassInterface>() : PRIVATE_MAXON_VTABLE(CustomDataTagClassInterface, o_); 
	return (mt_.CustomDataTagClassInterface_Write(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.CustomDataTagClassInterface_Write_Offset, data, hf));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CustomDataTagClassInterface::Hxx1::ConstFn<S>::GetIcon(Bool perPolyVertex) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int32>, Int32>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int32>, Int32>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const CustomDataTagClassInterface* o_ = (const CustomDataTagClassInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = CustomDataTagClassInterface::NullValuePtr(); if (!o_) return 0; } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CustomDataTagClassInterface, o_, CustomDataTagClassInterface_GetIcon) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<CustomDataTagClassInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CustomDataTagClassInterface>() : PRIVATE_MAXON_VTABLE(CustomDataTagClassInterface, o_); 
	return (mt_.CustomDataTagClassInterface_GetIcon(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.CustomDataTagClassInterface_GetIcon_Offset, perPolyVertex));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CustomDataTagClassInterface::Hxx1::ConstFn<S>::GetDefaultResourceId() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const String&>, const String&>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const String&>, const String&>::type>; static_assert(!std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value, "Can't invoke MAXON_FUNCTION CustomDataTagClassInterface::GetDefaultResourceId on super."); if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const CustomDataTagClassInterface* o_ = (const CustomDataTagClassInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = CustomDataTagClassInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<const String&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (o_->GetDefaultResourceId());
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CustomDataTagClassInterface::Hxx1::ConstFn<S>::GetTagPluginFlags() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int32>, Int32>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int32>, Int32>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const CustomDataTagClassInterface* o_ = (const CustomDataTagClassInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = CustomDataTagClassInterface::NullValuePtr(); if (!o_) return 0; } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CustomDataTagClassInterface, o_, CustomDataTagClassInterface_GetTagPluginFlags) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<CustomDataTagClassInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CustomDataTagClassInterface>() : PRIVATE_MAXON_VTABLE(CustomDataTagClassInterface, o_); 
	return (mt_.CustomDataTagClassInterface_GetTagPluginFlags(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.CustomDataTagClassInterface_GetTagPluginFlags_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CustomDataTagClassInterface::Hxx1::ConstFn<S>::Message(GeListNode* node, Int32 type, void* data) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const CustomDataTagClassInterface* o_ = (const CustomDataTagClassInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = CustomDataTagClassInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CustomDataTagClassInterface, o_, CustomDataTagClassInterface_Message) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<CustomDataTagClassInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CustomDataTagClassInterface>() : PRIVATE_MAXON_VTABLE(CustomDataTagClassInterface, o_); 
	return (mt_.CustomDataTagClassInterface_Message(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.CustomDataTagClassInterface_Message_Offset, node, type, data));
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

