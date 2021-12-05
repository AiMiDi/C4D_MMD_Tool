
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
	static const maxon::Bool HAS_NONSTATIC = false;
	Result<void> (*_CustomDataTagDisplayInterface_Init) (maxon::GenericComponent* this_, BaseTag* tag);
	maxon::Int _CustomDataTagDisplayInterface_Init_Offset;
	Result<void> (*_CustomDataTagDisplayInterface_Draw) (maxon::GenericComponent* this_, BaseTag* tag, BaseObject* op, BaseDraw* bd, BaseDrawHelp* bh);
	maxon::Int _CustomDataTagDisplayInterface_Draw_Offset;
	Result<void> (*_CustomDataTagDisplayInterface_DisplayControl) (maxon::GenericComponent* this_, BaseTag* tag, BaseDocument* doc, BaseObject* op, BaseDraw* bd, BaseDrawHelp* bh, ControlDisplayStruct& cds);
	maxon::Int _CustomDataTagDisplayInterface_DisplayControl_Offset;
	Result<void> (*_CustomDataTagDisplayInterface_InitDisplayControl) (maxon::GenericComponent* this_, BaseTag* tag, BaseDocument* doc, BaseDraw* bd, const AtomArray* active);
	maxon::Int _CustomDataTagDisplayInterface_InitDisplayControl_Offset;
	void (*_CustomDataTagDisplayInterface_FreeDisplayControl) (maxon::GenericComponent* this_, BaseTag* tag);
	maxon::Int _CustomDataTagDisplayInterface_FreeDisplayControl_Offset;
	void (*_CustomDataTagDisplayInterface_Reset) (maxon::GenericComponent* this_);
	maxon::Int _CustomDataTagDisplayInterface_Reset_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CustomDataTagDisplayInterface, Init))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CustomDataTagDisplayInterface, Init), W, MTable>::type::_CustomDataTagDisplayInterface_Init;
			_CustomDataTagDisplayInterface_Init = reinterpret_cast<const decltype(_CustomDataTagDisplayInterface_Init)&>(ptr);
			_CustomDataTagDisplayInterface_Init_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CustomDataTagDisplayInterface, Draw))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CustomDataTagDisplayInterface, Draw), W, MTable>::type::_CustomDataTagDisplayInterface_Draw;
			_CustomDataTagDisplayInterface_Draw = reinterpret_cast<const decltype(_CustomDataTagDisplayInterface_Draw)&>(ptr);
			_CustomDataTagDisplayInterface_Draw_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CustomDataTagDisplayInterface, DisplayControl))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CustomDataTagDisplayInterface, DisplayControl), W, MTable>::type::_CustomDataTagDisplayInterface_DisplayControl;
			_CustomDataTagDisplayInterface_DisplayControl = reinterpret_cast<const decltype(_CustomDataTagDisplayInterface_DisplayControl)&>(ptr);
			_CustomDataTagDisplayInterface_DisplayControl_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CustomDataTagDisplayInterface, InitDisplayControl))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CustomDataTagDisplayInterface, InitDisplayControl), W, MTable>::type::_CustomDataTagDisplayInterface_InitDisplayControl;
			_CustomDataTagDisplayInterface_InitDisplayControl = reinterpret_cast<const decltype(_CustomDataTagDisplayInterface_InitDisplayControl)&>(ptr);
			_CustomDataTagDisplayInterface_InitDisplayControl_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CustomDataTagDisplayInterface, FreeDisplayControl))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CustomDataTagDisplayInterface, FreeDisplayControl), W, MTable>::type::_CustomDataTagDisplayInterface_FreeDisplayControl;
			_CustomDataTagDisplayInterface_FreeDisplayControl = reinterpret_cast<const decltype(_CustomDataTagDisplayInterface_FreeDisplayControl)&>(ptr);
			_CustomDataTagDisplayInterface_FreeDisplayControl_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CustomDataTagDisplayInterface, Reset))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CustomDataTagDisplayInterface, Reset), W, MTable>::type::_CustomDataTagDisplayInterface_Reset;
			_CustomDataTagDisplayInterface_Reset = reinterpret_cast<const decltype(_CustomDataTagDisplayInterface_Reset)&>(ptr);
			_CustomDataTagDisplayInterface_Reset_Offset = offset;
		}
	}
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset)
	{
		if (!W::Implementation::PROXY && (!ObjectInterface::MTable::template InitWithBases<W>(info, offset))) return false;
		MTable* vt = (MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, _interface); if (!vt) return false;
		vt->Init<W>(offset); return true;
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<CustomDataTagDisplayInterface, typename ObjectInterface::MTable::template CombinedMTable<S>>;
	PRIVATE_MAXON_COMPBASE(CustomDataTagDisplayInterface);
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct CustomDataTagDisplayInterface::Hxx2
{
	template <typename S> class Wrapper : public ObjectInterface::Hxx2::template Wrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(DisplayControl);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(Draw);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(FreeDisplayControl);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(Init);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(InitDisplayControl);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(Reset);
	static Result<void> _CustomDataTagDisplayInterface_Init(maxon::GenericComponent* this_, BaseTag* tag) { return ((typename S::Implementation*) this_)->Init(tag); }
	static Result<void> _CustomDataTagDisplayInterface_Draw(maxon::GenericComponent* this_, BaseTag* tag, BaseObject* op, BaseDraw* bd, BaseDrawHelp* bh) { return ((typename S::Implementation*) this_)->Draw(tag, op, bd, bh); }
	static Result<void> _CustomDataTagDisplayInterface_DisplayControl(maxon::GenericComponent* this_, BaseTag* tag, BaseDocument* doc, BaseObject* op, BaseDraw* bd, BaseDrawHelp* bh, ControlDisplayStruct& cds) { return ((typename S::Implementation*) this_)->DisplayControl(tag, doc, op, bd, bh, cds); }
	static Result<void> _CustomDataTagDisplayInterface_InitDisplayControl(maxon::GenericComponent* this_, BaseTag* tag, BaseDocument* doc, BaseDraw* bd, const AtomArray* active) { return ((typename S::Implementation*) this_)->InitDisplayControl(tag, doc, bd, active); }
	static void _CustomDataTagDisplayInterface_FreeDisplayControl(maxon::GenericComponent* this_, BaseTag* tag) { return ((typename S::Implementation*) this_)->FreeDisplayControl(tag); }
	static void _CustomDataTagDisplayInterface_Reset(maxon::GenericComponent* this_) { return ((typename S::Implementation*) this_)->Reset(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto CustomDataTagDisplayInterface::Init(BaseTag* tag) -> Result<void>
{
	const CustomDataTagDisplayInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(CustomDataTagDisplayInterface, this); return mt_._CustomDataTagDisplayInterface_Init((maxon::GenericComponent*) this + mt_._CustomDataTagDisplayInterface_Init_Offset, tag);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CustomDataTagDisplayInterface::Draw(BaseTag* tag, BaseObject* op, BaseDraw* bd, BaseDrawHelp* bh) -> Result<void>
{
	const CustomDataTagDisplayInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(CustomDataTagDisplayInterface, this); return mt_._CustomDataTagDisplayInterface_Draw((maxon::GenericComponent*) this + mt_._CustomDataTagDisplayInterface_Draw_Offset, tag, op, bd, bh);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CustomDataTagDisplayInterface::DisplayControl(BaseTag* tag, BaseDocument* doc, BaseObject* op, BaseDraw* bd, BaseDrawHelp* bh, ControlDisplayStruct& cds) -> Result<void>
{
	const CustomDataTagDisplayInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(CustomDataTagDisplayInterface, this); return mt_._CustomDataTagDisplayInterface_DisplayControl((maxon::GenericComponent*) this + mt_._CustomDataTagDisplayInterface_DisplayControl_Offset, tag, doc, op, bd, bh, cds);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CustomDataTagDisplayInterface::InitDisplayControl(BaseTag* tag, BaseDocument* doc, BaseDraw* bd, const AtomArray* active) -> Result<void>
{
	const CustomDataTagDisplayInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(CustomDataTagDisplayInterface, this); return mt_._CustomDataTagDisplayInterface_InitDisplayControl((maxon::GenericComponent*) this + mt_._CustomDataTagDisplayInterface_InitDisplayControl_Offset, tag, doc, bd, active);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CustomDataTagDisplayInterface::FreeDisplayControl(BaseTag* tag) -> void
{
	const CustomDataTagDisplayInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(CustomDataTagDisplayInterface, this); return mt_._CustomDataTagDisplayInterface_FreeDisplayControl((maxon::GenericComponent*) this + mt_._CustomDataTagDisplayInterface_FreeDisplayControl_Offset, tag);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CustomDataTagDisplayInterface::Reset() -> void
{
	const CustomDataTagDisplayInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(CustomDataTagDisplayInterface, this); return mt_._CustomDataTagDisplayInterface_Reset((maxon::GenericComponent*) this + mt_._CustomDataTagDisplayInterface_Reset_Offset);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CustomDataTagDisplayInterface::Hxx1::ReferenceFunctionsImpl<S>::Init(BaseTag* tag) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); CustomDataTagDisplayInterface* o_ = (CustomDataTagDisplayInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CustomDataTagDisplayInterface, o_, CustomDataTagDisplayInterface_Init) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<CustomDataTagDisplayInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CustomDataTagDisplayInterface>() : PRIVATE_MAXON_VTABLE(CustomDataTagDisplayInterface, o_); 
	return (mt_._CustomDataTagDisplayInterface_Init(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CustomDataTagDisplayInterface_Init_Offset, tag));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CustomDataTagDisplayInterface::Hxx1::COWReferenceFunctionsImpl<S>::Init(BaseTag* tag) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); CustomDataTagDisplayInterface* o_ = (CustomDataTagDisplayInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CustomDataTagDisplayInterface, o_, CustomDataTagDisplayInterface_Init) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<CustomDataTagDisplayInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CustomDataTagDisplayInterface>() : PRIVATE_MAXON_VTABLE(CustomDataTagDisplayInterface, o_); 
	return (mt_._CustomDataTagDisplayInterface_Init(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CustomDataTagDisplayInterface_Init_Offset, tag));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CustomDataTagDisplayInterface::Hxx1::ReferenceFunctionsImpl<S>::Draw(BaseTag* tag, BaseObject* op, BaseDraw* bd, BaseDrawHelp* bh) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); CustomDataTagDisplayInterface* o_ = (CustomDataTagDisplayInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CustomDataTagDisplayInterface, o_, CustomDataTagDisplayInterface_Draw) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<CustomDataTagDisplayInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CustomDataTagDisplayInterface>() : PRIVATE_MAXON_VTABLE(CustomDataTagDisplayInterface, o_); 
	return (mt_._CustomDataTagDisplayInterface_Draw(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CustomDataTagDisplayInterface_Draw_Offset, tag, op, bd, bh));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CustomDataTagDisplayInterface::Hxx1::COWReferenceFunctionsImpl<S>::Draw(BaseTag* tag, BaseObject* op, BaseDraw* bd, BaseDrawHelp* bh) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); CustomDataTagDisplayInterface* o_ = (CustomDataTagDisplayInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CustomDataTagDisplayInterface, o_, CustomDataTagDisplayInterface_Draw) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<CustomDataTagDisplayInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CustomDataTagDisplayInterface>() : PRIVATE_MAXON_VTABLE(CustomDataTagDisplayInterface, o_); 
	return (mt_._CustomDataTagDisplayInterface_Draw(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CustomDataTagDisplayInterface_Draw_Offset, tag, op, bd, bh));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CustomDataTagDisplayInterface::Hxx1::ReferenceFunctionsImpl<S>::DisplayControl(BaseTag* tag, BaseDocument* doc, BaseObject* op, BaseDraw* bd, BaseDrawHelp* bh, ControlDisplayStruct& cds) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); CustomDataTagDisplayInterface* o_ = (CustomDataTagDisplayInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CustomDataTagDisplayInterface, o_, CustomDataTagDisplayInterface_DisplayControl) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<CustomDataTagDisplayInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CustomDataTagDisplayInterface>() : PRIVATE_MAXON_VTABLE(CustomDataTagDisplayInterface, o_); 
	return (mt_._CustomDataTagDisplayInterface_DisplayControl(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CustomDataTagDisplayInterface_DisplayControl_Offset, tag, doc, op, bd, bh, cds));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CustomDataTagDisplayInterface::Hxx1::COWReferenceFunctionsImpl<S>::DisplayControl(BaseTag* tag, BaseDocument* doc, BaseObject* op, BaseDraw* bd, BaseDrawHelp* bh, ControlDisplayStruct& cds) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); CustomDataTagDisplayInterface* o_ = (CustomDataTagDisplayInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CustomDataTagDisplayInterface, o_, CustomDataTagDisplayInterface_DisplayControl) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<CustomDataTagDisplayInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CustomDataTagDisplayInterface>() : PRIVATE_MAXON_VTABLE(CustomDataTagDisplayInterface, o_); 
	return (mt_._CustomDataTagDisplayInterface_DisplayControl(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CustomDataTagDisplayInterface_DisplayControl_Offset, tag, doc, op, bd, bh, cds));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CustomDataTagDisplayInterface::Hxx1::ReferenceFunctionsImpl<S>::InitDisplayControl(BaseTag* tag, BaseDocument* doc, BaseDraw* bd, const AtomArray* active) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); CustomDataTagDisplayInterface* o_ = (CustomDataTagDisplayInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CustomDataTagDisplayInterface, o_, CustomDataTagDisplayInterface_InitDisplayControl) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<CustomDataTagDisplayInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CustomDataTagDisplayInterface>() : PRIVATE_MAXON_VTABLE(CustomDataTagDisplayInterface, o_); 
	return (mt_._CustomDataTagDisplayInterface_InitDisplayControl(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CustomDataTagDisplayInterface_InitDisplayControl_Offset, tag, doc, bd, active));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CustomDataTagDisplayInterface::Hxx1::COWReferenceFunctionsImpl<S>::InitDisplayControl(BaseTag* tag, BaseDocument* doc, BaseDraw* bd, const AtomArray* active) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); CustomDataTagDisplayInterface* o_ = (CustomDataTagDisplayInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CustomDataTagDisplayInterface, o_, CustomDataTagDisplayInterface_InitDisplayControl) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<CustomDataTagDisplayInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CustomDataTagDisplayInterface>() : PRIVATE_MAXON_VTABLE(CustomDataTagDisplayInterface, o_); 
	return (mt_._CustomDataTagDisplayInterface_InitDisplayControl(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CustomDataTagDisplayInterface_InitDisplayControl_Offset, tag, doc, bd, active));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CustomDataTagDisplayInterface::Hxx1::ReferenceFunctionsImpl<S>::FreeDisplayControl(BaseTag* tag) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); CustomDataTagDisplayInterface* o_ = (CustomDataTagDisplayInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateLogNullptrError(); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CustomDataTagDisplayInterface, o_, CustomDataTagDisplayInterface_FreeDisplayControl) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<CustomDataTagDisplayInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CustomDataTagDisplayInterface>() : PRIVATE_MAXON_VTABLE(CustomDataTagDisplayInterface, o_); 
	mt_._CustomDataTagDisplayInterface_FreeDisplayControl(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CustomDataTagDisplayInterface_FreeDisplayControl_Offset, tag);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CustomDataTagDisplayInterface::Hxx1::COWReferenceFunctionsImpl<S>::FreeDisplayControl(BaseTag* tag) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); CustomDataTagDisplayInterface* o_ = (CustomDataTagDisplayInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CustomDataTagDisplayInterface, o_, CustomDataTagDisplayInterface_FreeDisplayControl) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<CustomDataTagDisplayInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CustomDataTagDisplayInterface>() : PRIVATE_MAXON_VTABLE(CustomDataTagDisplayInterface, o_); 
	mt_._CustomDataTagDisplayInterface_FreeDisplayControl(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CustomDataTagDisplayInterface_FreeDisplayControl_Offset, tag);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CustomDataTagDisplayInterface::Hxx1::ReferenceFunctionsImpl<S>::Reset() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); CustomDataTagDisplayInterface* o_ = (CustomDataTagDisplayInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateLogNullptrError(); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CustomDataTagDisplayInterface, o_, CustomDataTagDisplayInterface_Reset) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<CustomDataTagDisplayInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CustomDataTagDisplayInterface>() : PRIVATE_MAXON_VTABLE(CustomDataTagDisplayInterface, o_); 
	mt_._CustomDataTagDisplayInterface_Reset(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CustomDataTagDisplayInterface_Reset_Offset);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CustomDataTagDisplayInterface::Hxx1::COWReferenceFunctionsImpl<S>::Reset() -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); CustomDataTagDisplayInterface* o_ = (CustomDataTagDisplayInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CustomDataTagDisplayInterface, o_, CustomDataTagDisplayInterface_Reset) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<CustomDataTagDisplayInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CustomDataTagDisplayInterface>() : PRIVATE_MAXON_VTABLE(CustomDataTagDisplayInterface, o_); 
	mt_._CustomDataTagDisplayInterface_Reset(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CustomDataTagDisplayInterface_Reset_Offset);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
auto CustomDataTagDisplayInterface::GetPtr() -> Ptr { return Ptr(this); }
auto CustomDataTagDisplayInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
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
	PRIVATE_MAXON_IMPLEMENTS_CHECK(InterpolateInOutline);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(InterpolateLinear);
	static const maxon::Char* const _ids;
	static const maxon::Bool HAS_NONSTATIC = false;
	const DataType& (*_MeshAttributeClassInterface_GetDataType) (const maxon::GenericComponent* this_);
	maxon::Int _MeshAttributeClassInterface_GetDataType_Offset;
	void (*_MeshAttributeClassInterface_InterpolateLinear) (const maxon::GenericComponent* this_, void* data1, const void* data2, Float blend);
	maxon::Int _MeshAttributeClassInterface_InterpolateLinear_Offset;
	void (*_MeshAttributeClassInterface_InterpolateInOutline) (const maxon::GenericComponent* this_, void* data, const Block<void*>& outline, const Block<Float>& weights);
	maxon::Int _MeshAttributeClassInterface_InterpolateInOutline_Offset;
	void (*_MeshAttributeClassInterface_GetDefaultValue) (const maxon::GenericComponent* this_, void* data);
	maxon::Int _MeshAttributeClassInterface_GetDefaultValue_Offset;
	Bool (*_MeshAttributeClassInterface_AtrLessThen) (const maxon::GenericComponent* this_, const void* data1, const void* data2);
	maxon::Int _MeshAttributeClassInterface_AtrLessThen_Offset;
	Bool (*_MeshAttributeClassInterface_AtrIsEqual) (const maxon::GenericComponent* this_, const void* data1, const void* data2);
	maxon::Int _MeshAttributeClassInterface_AtrIsEqual_Offset;
	void (*_MeshAttributeClassInterface_AtrAdd) (const maxon::GenericComponent* this_, void* data1, const void* data2);
	maxon::Int _MeshAttributeClassInterface_AtrAdd_Offset;
	void (*_MeshAttributeClassInterface_AtrSubstract) (const maxon::GenericComponent* this_, void* data1, const void* data2);
	maxon::Int _MeshAttributeClassInterface_AtrSubstract_Offset;
	void (*_MeshAttributeClassInterface_AtrMultiply) (const maxon::GenericComponent* this_, void* data1, const void* data2);
	maxon::Int _MeshAttributeClassInterface_AtrMultiply_Offset;
	void (*_MeshAttributeClassInterface_AtrMultiply_1) (const maxon::GenericComponent* this_, void* data, Float value);
	maxon::Int _MeshAttributeClassInterface_AtrMultiply_1_Offset;
	void (*_MeshAttributeClassInterface_AtrDivide) (const maxon::GenericComponent* this_, void* data1, const void* data2);
	maxon::Int _MeshAttributeClassInterface_AtrDivide_Offset;
	void (*_MeshAttributeClassInterface_AtrDivide_1) (const maxon::GenericComponent* this_, void* data, Float value);
	maxon::Int _MeshAttributeClassInterface_AtrDivide_1_Offset;
	String (*_MeshAttributeClassInterface_AtrToString) (const maxon::GenericComponent* this_, const void* data, const FormatStatement* formatStatement);
	maxon::Int _MeshAttributeClassInterface_AtrToString_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MeshAttributeClassInterface, GetDataType))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MeshAttributeClassInterface, GetDataType), W, MTable>::type::_MeshAttributeClassInterface_GetDataType;
			_MeshAttributeClassInterface_GetDataType = reinterpret_cast<const decltype(_MeshAttributeClassInterface_GetDataType)&>(ptr);
			_MeshAttributeClassInterface_GetDataType_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MeshAttributeClassInterface, InterpolateLinear))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MeshAttributeClassInterface, InterpolateLinear), W, MTable>::type::_MeshAttributeClassInterface_InterpolateLinear;
			_MeshAttributeClassInterface_InterpolateLinear = reinterpret_cast<const decltype(_MeshAttributeClassInterface_InterpolateLinear)&>(ptr);
			_MeshAttributeClassInterface_InterpolateLinear_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MeshAttributeClassInterface, InterpolateInOutline))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MeshAttributeClassInterface, InterpolateInOutline), W, MTable>::type::_MeshAttributeClassInterface_InterpolateInOutline;
			_MeshAttributeClassInterface_InterpolateInOutline = reinterpret_cast<const decltype(_MeshAttributeClassInterface_InterpolateInOutline)&>(ptr);
			_MeshAttributeClassInterface_InterpolateInOutline_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MeshAttributeClassInterface, GetDefaultValue))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MeshAttributeClassInterface, GetDefaultValue), W, MTable>::type::_MeshAttributeClassInterface_GetDefaultValue;
			_MeshAttributeClassInterface_GetDefaultValue = reinterpret_cast<const decltype(_MeshAttributeClassInterface_GetDefaultValue)&>(ptr);
			_MeshAttributeClassInterface_GetDefaultValue_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MeshAttributeClassInterface, AtrLessThen))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MeshAttributeClassInterface, AtrLessThen), W, MTable>::type::_MeshAttributeClassInterface_AtrLessThen;
			_MeshAttributeClassInterface_AtrLessThen = reinterpret_cast<const decltype(_MeshAttributeClassInterface_AtrLessThen)&>(ptr);
			_MeshAttributeClassInterface_AtrLessThen_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MeshAttributeClassInterface, AtrIsEqual))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MeshAttributeClassInterface, AtrIsEqual), W, MTable>::type::_MeshAttributeClassInterface_AtrIsEqual;
			_MeshAttributeClassInterface_AtrIsEqual = reinterpret_cast<const decltype(_MeshAttributeClassInterface_AtrIsEqual)&>(ptr);
			_MeshAttributeClassInterface_AtrIsEqual_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MeshAttributeClassInterface, AtrAdd))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MeshAttributeClassInterface, AtrAdd), W, MTable>::type::_MeshAttributeClassInterface_AtrAdd;
			_MeshAttributeClassInterface_AtrAdd = reinterpret_cast<const decltype(_MeshAttributeClassInterface_AtrAdd)&>(ptr);
			_MeshAttributeClassInterface_AtrAdd_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MeshAttributeClassInterface, AtrSubstract))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MeshAttributeClassInterface, AtrSubstract), W, MTable>::type::_MeshAttributeClassInterface_AtrSubstract;
			_MeshAttributeClassInterface_AtrSubstract = reinterpret_cast<const decltype(_MeshAttributeClassInterface_AtrSubstract)&>(ptr);
			_MeshAttributeClassInterface_AtrSubstract_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MeshAttributeClassInterface, AtrMultiply))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MeshAttributeClassInterface, AtrMultiply), W, MTable>::type::_MeshAttributeClassInterface_AtrMultiply;
			_MeshAttributeClassInterface_AtrMultiply = reinterpret_cast<const decltype(_MeshAttributeClassInterface_AtrMultiply)&>(ptr);
			_MeshAttributeClassInterface_AtrMultiply_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MeshAttributeClassInterface, AtrMultiply))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MeshAttributeClassInterface, AtrMultiply), W, MTable>::type::_MeshAttributeClassInterface_AtrMultiply_1;
			_MeshAttributeClassInterface_AtrMultiply_1 = reinterpret_cast<const decltype(_MeshAttributeClassInterface_AtrMultiply_1)&>(ptr);
			_MeshAttributeClassInterface_AtrMultiply_1_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MeshAttributeClassInterface, AtrDivide))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MeshAttributeClassInterface, AtrDivide), W, MTable>::type::_MeshAttributeClassInterface_AtrDivide;
			_MeshAttributeClassInterface_AtrDivide = reinterpret_cast<const decltype(_MeshAttributeClassInterface_AtrDivide)&>(ptr);
			_MeshAttributeClassInterface_AtrDivide_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MeshAttributeClassInterface, AtrDivide))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MeshAttributeClassInterface, AtrDivide), W, MTable>::type::_MeshAttributeClassInterface_AtrDivide_1;
			_MeshAttributeClassInterface_AtrDivide_1 = reinterpret_cast<const decltype(_MeshAttributeClassInterface_AtrDivide_1)&>(ptr);
			_MeshAttributeClassInterface_AtrDivide_1_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MeshAttributeClassInterface, AtrToString))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MeshAttributeClassInterface, AtrToString), W, MTable>::type::_MeshAttributeClassInterface_AtrToString;
			_MeshAttributeClassInterface_AtrToString = reinterpret_cast<const decltype(_MeshAttributeClassInterface_AtrToString)&>(ptr);
			_MeshAttributeClassInterface_AtrToString_Offset = offset;
		}
	}
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset)
	{
		if (!W::Implementation::PROXY && (!ObjectInterface::MTable::template InitWithBases<W>(info, offset))) return false;
		MTable* vt = (MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, _interface); if (!vt) return false;
		vt->Init<W>(offset); return true;
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<MeshAttributeClassInterface, typename ObjectInterface::MTable::template CombinedMTable<S>>;
	PRIVATE_MAXON_COMPBASE(MeshAttributeClassInterface);
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct MeshAttributeClassInterface::Hxx2
{
	template <typename S> class Wrapper : public ObjectInterface::Hxx2::template Wrapper<S>
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
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(InterpolateInOutline);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(InterpolateLinear);
	static const DataType& _MeshAttributeClassInterface_GetDataType(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetDataType(); }
	static void _MeshAttributeClassInterface_InterpolateLinear(const maxon::GenericComponent* this_, void* data1, const void* data2, Float blend) { return ((const typename S::Implementation*) this_)->InterpolateLinear(data1, data2, blend); }
	static void _MeshAttributeClassInterface_InterpolateInOutline(const maxon::GenericComponent* this_, void* data, const Block<void*>& outline, const Block<Float>& weights) { return ((const typename S::Implementation*) this_)->InterpolateInOutline(data, outline, weights); }
	static void _MeshAttributeClassInterface_GetDefaultValue(const maxon::GenericComponent* this_, void* data) { return ((const typename S::Implementation*) this_)->GetDefaultValue(data); }
	static Bool _MeshAttributeClassInterface_AtrLessThen(const maxon::GenericComponent* this_, const void* data1, const void* data2) { return ((const typename S::Implementation*) this_)->AtrLessThen(data1, data2); }
	static Bool _MeshAttributeClassInterface_AtrIsEqual(const maxon::GenericComponent* this_, const void* data1, const void* data2) { return ((const typename S::Implementation*) this_)->AtrIsEqual(data1, data2); }
	static void _MeshAttributeClassInterface_AtrAdd(const maxon::GenericComponent* this_, void* data1, const void* data2) { return ((const typename S::Implementation*) this_)->AtrAdd(data1, data2); }
	static void _MeshAttributeClassInterface_AtrSubstract(const maxon::GenericComponent* this_, void* data1, const void* data2) { return ((const typename S::Implementation*) this_)->AtrSubstract(data1, data2); }
	static void _MeshAttributeClassInterface_AtrMultiply(const maxon::GenericComponent* this_, void* data1, const void* data2) { return ((const typename S::Implementation*) this_)->AtrMultiply(data1, data2); }
	static void _MeshAttributeClassInterface_AtrMultiply_1(const maxon::GenericComponent* this_, void* data, Float value) { return ((const typename S::Implementation*) this_)->AtrMultiply(data, value); }
	static void _MeshAttributeClassInterface_AtrDivide(const maxon::GenericComponent* this_, void* data1, const void* data2) { return ((const typename S::Implementation*) this_)->AtrDivide(data1, data2); }
	static void _MeshAttributeClassInterface_AtrDivide_1(const maxon::GenericComponent* this_, void* data, Float value) { return ((const typename S::Implementation*) this_)->AtrDivide(data, value); }
	static String _MeshAttributeClassInterface_AtrToString(const maxon::GenericComponent* this_, const void* data, const FormatStatement* formatStatement) { return ((const typename S::Implementation*) this_)->AtrToString(data, formatStatement); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto MeshAttributeClassInterface::GetDataType() const -> const DataType&
{
	const MeshAttributeClassInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MeshAttributeClassInterface, this); return mt_._MeshAttributeClassInterface_GetDataType((const maxon::GenericComponent*) this + mt_._MeshAttributeClassInterface_GetDataType_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MeshAttributeClassInterface::InterpolateLinear(void* data1, const void* data2, Float blend) const -> void
{
	const MeshAttributeClassInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MeshAttributeClassInterface, this); return mt_._MeshAttributeClassInterface_InterpolateLinear((const maxon::GenericComponent*) this + mt_._MeshAttributeClassInterface_InterpolateLinear_Offset, data1, data2, blend);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MeshAttributeClassInterface::InterpolateInOutline(void* data, const Block<void*>& outline, const Block<Float>& weights) const -> void
{
	const MeshAttributeClassInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MeshAttributeClassInterface, this); return mt_._MeshAttributeClassInterface_InterpolateInOutline((const maxon::GenericComponent*) this + mt_._MeshAttributeClassInterface_InterpolateInOutline_Offset, data, outline, weights);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MeshAttributeClassInterface::GetDefaultValue(void* data) const -> void
{
	const MeshAttributeClassInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MeshAttributeClassInterface, this); return mt_._MeshAttributeClassInterface_GetDefaultValue((const maxon::GenericComponent*) this + mt_._MeshAttributeClassInterface_GetDefaultValue_Offset, data);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MeshAttributeClassInterface::AtrLessThen(const void* data1, const void* data2) const -> Bool
{
	const MeshAttributeClassInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MeshAttributeClassInterface, this); return mt_._MeshAttributeClassInterface_AtrLessThen((const maxon::GenericComponent*) this + mt_._MeshAttributeClassInterface_AtrLessThen_Offset, data1, data2);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MeshAttributeClassInterface::AtrIsEqual(const void* data1, const void* data2) const -> Bool
{
	const MeshAttributeClassInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MeshAttributeClassInterface, this); return mt_._MeshAttributeClassInterface_AtrIsEqual((const maxon::GenericComponent*) this + mt_._MeshAttributeClassInterface_AtrIsEqual_Offset, data1, data2);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MeshAttributeClassInterface::AtrAdd(void* data1, const void* data2) const -> void
{
	const MeshAttributeClassInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MeshAttributeClassInterface, this); return mt_._MeshAttributeClassInterface_AtrAdd((const maxon::GenericComponent*) this + mt_._MeshAttributeClassInterface_AtrAdd_Offset, data1, data2);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MeshAttributeClassInterface::AtrSubstract(void* data1, const void* data2) const -> void
{
	const MeshAttributeClassInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MeshAttributeClassInterface, this); return mt_._MeshAttributeClassInterface_AtrSubstract((const maxon::GenericComponent*) this + mt_._MeshAttributeClassInterface_AtrSubstract_Offset, data1, data2);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MeshAttributeClassInterface::AtrMultiply(void* data1, const void* data2) const -> void
{
	const MeshAttributeClassInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MeshAttributeClassInterface, this); return mt_._MeshAttributeClassInterface_AtrMultiply((const maxon::GenericComponent*) this + mt_._MeshAttributeClassInterface_AtrMultiply_Offset, data1, data2);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MeshAttributeClassInterface::AtrMultiply(void* data, Float value) const -> void
{
	const MeshAttributeClassInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MeshAttributeClassInterface, this); return mt_._MeshAttributeClassInterface_AtrMultiply_1((const maxon::GenericComponent*) this + mt_._MeshAttributeClassInterface_AtrMultiply_1_Offset, data, value);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MeshAttributeClassInterface::AtrDivide(void* data1, const void* data2) const -> void
{
	const MeshAttributeClassInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MeshAttributeClassInterface, this); return mt_._MeshAttributeClassInterface_AtrDivide((const maxon::GenericComponent*) this + mt_._MeshAttributeClassInterface_AtrDivide_Offset, data1, data2);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MeshAttributeClassInterface::AtrDivide(void* data, Float value) const -> void
{
	const MeshAttributeClassInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MeshAttributeClassInterface, this); return mt_._MeshAttributeClassInterface_AtrDivide_1((const maxon::GenericComponent*) this + mt_._MeshAttributeClassInterface_AtrDivide_1_Offset, data, value);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MeshAttributeClassInterface::AtrToString(const void* data, const FormatStatement* formatStatement) const -> String
{
	const MeshAttributeClassInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MeshAttributeClassInterface, this); return mt_._MeshAttributeClassInterface_AtrToString((const maxon::GenericComponent*) this + mt_._MeshAttributeClassInterface_AtrToString_Offset, data, formatStatement);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MeshAttributeClassInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetDataType() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const DataType&>, const DataType&>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const DataType&>, const DataType&>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const MeshAttributeClassInterface* o_ = (const MeshAttributeClassInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = MeshAttributeClassInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<const DataType&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MeshAttributeClassInterface, o_, MeshAttributeClassInterface_GetDataType) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<MeshAttributeClassInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MeshAttributeClassInterface>() : PRIVATE_MAXON_VTABLE(MeshAttributeClassInterface, o_); 
	return (mt_._MeshAttributeClassInterface_GetDataType(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._MeshAttributeClassInterface_GetDataType_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MeshAttributeClassInterface::Hxx1::ConstReferenceFunctionsImpl<S>::InterpolateLinear(void* data1, const void* data2, Float blend) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const MeshAttributeClassInterface* o_ = (const MeshAttributeClassInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = MeshAttributeClassInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MeshAttributeClassInterface, o_, MeshAttributeClassInterface_InterpolateLinear) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<MeshAttributeClassInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MeshAttributeClassInterface>() : PRIVATE_MAXON_VTABLE(MeshAttributeClassInterface, o_); 
	mt_._MeshAttributeClassInterface_InterpolateLinear(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._MeshAttributeClassInterface_InterpolateLinear_Offset, data1, data2, blend);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MeshAttributeClassInterface::Hxx1::ConstReferenceFunctionsImpl<S>::InterpolateInOutline(void* data, const Block<void*>& outline, const Block<Float>& weights) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const MeshAttributeClassInterface* o_ = (const MeshAttributeClassInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = MeshAttributeClassInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MeshAttributeClassInterface, o_, MeshAttributeClassInterface_InterpolateInOutline) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<MeshAttributeClassInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MeshAttributeClassInterface>() : PRIVATE_MAXON_VTABLE(MeshAttributeClassInterface, o_); 
	mt_._MeshAttributeClassInterface_InterpolateInOutline(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._MeshAttributeClassInterface_InterpolateInOutline_Offset, data, outline, weights);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MeshAttributeClassInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetDefaultValue(void* data) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const MeshAttributeClassInterface* o_ = (const MeshAttributeClassInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = MeshAttributeClassInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MeshAttributeClassInterface, o_, MeshAttributeClassInterface_GetDefaultValue) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<MeshAttributeClassInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MeshAttributeClassInterface>() : PRIVATE_MAXON_VTABLE(MeshAttributeClassInterface, o_); 
	mt_._MeshAttributeClassInterface_GetDefaultValue(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._MeshAttributeClassInterface_GetDefaultValue_Offset, data);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MeshAttributeClassInterface::Hxx1::ConstReferenceFunctionsImpl<S>::AtrLessThen(const void* data1, const void* data2) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const MeshAttributeClassInterface* o_ = (const MeshAttributeClassInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = MeshAttributeClassInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MeshAttributeClassInterface, o_, MeshAttributeClassInterface_AtrLessThen) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<MeshAttributeClassInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MeshAttributeClassInterface>() : PRIVATE_MAXON_VTABLE(MeshAttributeClassInterface, o_); 
	return (mt_._MeshAttributeClassInterface_AtrLessThen(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._MeshAttributeClassInterface_AtrLessThen_Offset, data1, data2));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MeshAttributeClassInterface::Hxx1::ConstReferenceFunctionsImpl<S>::AtrIsEqual(const void* data1, const void* data2) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const MeshAttributeClassInterface* o_ = (const MeshAttributeClassInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = MeshAttributeClassInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MeshAttributeClassInterface, o_, MeshAttributeClassInterface_AtrIsEqual) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<MeshAttributeClassInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MeshAttributeClassInterface>() : PRIVATE_MAXON_VTABLE(MeshAttributeClassInterface, o_); 
	return (mt_._MeshAttributeClassInterface_AtrIsEqual(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._MeshAttributeClassInterface_AtrIsEqual_Offset, data1, data2));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MeshAttributeClassInterface::Hxx1::ConstReferenceFunctionsImpl<S>::AtrAdd(void* data1, const void* data2) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const MeshAttributeClassInterface* o_ = (const MeshAttributeClassInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = MeshAttributeClassInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MeshAttributeClassInterface, o_, MeshAttributeClassInterface_AtrAdd) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<MeshAttributeClassInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MeshAttributeClassInterface>() : PRIVATE_MAXON_VTABLE(MeshAttributeClassInterface, o_); 
	mt_._MeshAttributeClassInterface_AtrAdd(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._MeshAttributeClassInterface_AtrAdd_Offset, data1, data2);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MeshAttributeClassInterface::Hxx1::ConstReferenceFunctionsImpl<S>::AtrSubstract(void* data1, const void* data2) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const MeshAttributeClassInterface* o_ = (const MeshAttributeClassInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = MeshAttributeClassInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MeshAttributeClassInterface, o_, MeshAttributeClassInterface_AtrSubstract) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<MeshAttributeClassInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MeshAttributeClassInterface>() : PRIVATE_MAXON_VTABLE(MeshAttributeClassInterface, o_); 
	mt_._MeshAttributeClassInterface_AtrSubstract(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._MeshAttributeClassInterface_AtrSubstract_Offset, data1, data2);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MeshAttributeClassInterface::Hxx1::ConstReferenceFunctionsImpl<S>::AtrMultiply(void* data1, const void* data2) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const MeshAttributeClassInterface* o_ = (const MeshAttributeClassInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = MeshAttributeClassInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MeshAttributeClassInterface, o_, MeshAttributeClassInterface_AtrMultiply) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<MeshAttributeClassInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MeshAttributeClassInterface>() : PRIVATE_MAXON_VTABLE(MeshAttributeClassInterface, o_); 
	mt_._MeshAttributeClassInterface_AtrMultiply(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._MeshAttributeClassInterface_AtrMultiply_Offset, data1, data2);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MeshAttributeClassInterface::Hxx1::ConstReferenceFunctionsImpl<S>::AtrMultiply(void* data, Float value) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const MeshAttributeClassInterface* o_ = (const MeshAttributeClassInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = MeshAttributeClassInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MeshAttributeClassInterface, o_, MeshAttributeClassInterface_AtrMultiply_1) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<MeshAttributeClassInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MeshAttributeClassInterface>() : PRIVATE_MAXON_VTABLE(MeshAttributeClassInterface, o_); 
	mt_._MeshAttributeClassInterface_AtrMultiply_1(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._MeshAttributeClassInterface_AtrMultiply_1_Offset, data, value);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MeshAttributeClassInterface::Hxx1::ConstReferenceFunctionsImpl<S>::AtrDivide(void* data1, const void* data2) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const MeshAttributeClassInterface* o_ = (const MeshAttributeClassInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = MeshAttributeClassInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MeshAttributeClassInterface, o_, MeshAttributeClassInterface_AtrDivide) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<MeshAttributeClassInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MeshAttributeClassInterface>() : PRIVATE_MAXON_VTABLE(MeshAttributeClassInterface, o_); 
	mt_._MeshAttributeClassInterface_AtrDivide(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._MeshAttributeClassInterface_AtrDivide_Offset, data1, data2);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MeshAttributeClassInterface::Hxx1::ConstReferenceFunctionsImpl<S>::AtrDivide(void* data, Float value) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const MeshAttributeClassInterface* o_ = (const MeshAttributeClassInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = MeshAttributeClassInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MeshAttributeClassInterface, o_, MeshAttributeClassInterface_AtrDivide_1) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<MeshAttributeClassInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MeshAttributeClassInterface>() : PRIVATE_MAXON_VTABLE(MeshAttributeClassInterface, o_); 
	mt_._MeshAttributeClassInterface_AtrDivide_1(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._MeshAttributeClassInterface_AtrDivide_1_Offset, data, value);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MeshAttributeClassInterface::Hxx1::ConstReferenceFunctionsImpl<S>::AtrToString(const void* data, const FormatStatement* formatStatement) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const MeshAttributeClassInterface* o_ = (const MeshAttributeClassInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = MeshAttributeClassInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MeshAttributeClassInterface, o_, MeshAttributeClassInterface_AtrToString) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<MeshAttributeClassInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MeshAttributeClassInterface>() : PRIVATE_MAXON_VTABLE(MeshAttributeClassInterface, o_); 
	return (mt_._MeshAttributeClassInterface_AtrToString(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._MeshAttributeClassInterface_AtrToString_Offset, data, formatStatement));
}
auto MeshAttributeClassInterface::GetPtr() -> Ptr { return Ptr(this); }
auto MeshAttributeClassInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
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
	PRIVATE_MAXON_IMPLEMENTS_CHECK(Read);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(Write);
	static const maxon::Char* const _ids;
	static const maxon::Bool HAS_NONSTATIC = false;
	Int32 (*_CustomDataTagClassInterface_GetTagPluginId) (const maxon::GenericComponent* this_);
	maxon::Int _CustomDataTagClassInterface_GetTagPluginId_Offset;
	const String& (*_CustomDataTagClassInterface_GetTagPluginName) (const maxon::GenericComponent* this_);
	maxon::Int _CustomDataTagClassInterface_GetTagPluginName_Offset;
	const String& (*_CustomDataTagClassInterface_GetResourceId) (const maxon::GenericComponent* this_);
	maxon::Int _CustomDataTagClassInterface_GetResourceId_Offset;
	Int32 (*_CustomDataTagClassInterface_GetTagPluginLevel) (const maxon::GenericComponent* this_);
	maxon::Int _CustomDataTagClassInterface_GetTagPluginLevel_Offset;
	Id (*_CustomDataTagClassInterface_GetDisplayClassId) (const maxon::GenericComponent* this_);
	maxon::Int _CustomDataTagClassInterface_GetDisplayClassId_Offset;
	Bool (*_CustomDataTagClassInterface_IsSdsCompatible) (const maxon::GenericComponent* this_, Int32& floatSize);
	maxon::Int _CustomDataTagClassInterface_IsSdsCompatible_Offset;
	Result<void> (*_CustomDataTagClassInterface_Read) (const maxon::GenericComponent* this_, void* data, HyperFile* hf, Int32 level);
	maxon::Int _CustomDataTagClassInterface_Read_Offset;
	Result<void> (*_CustomDataTagClassInterface_Write) (const maxon::GenericComponent* this_, const void* data, HyperFile* hf);
	maxon::Int _CustomDataTagClassInterface_Write_Offset;
	Int32 (*_CustomDataTagClassInterface_GetIcon) (const maxon::GenericComponent* this_, Bool perPolyVertex);
	maxon::Int _CustomDataTagClassInterface_GetIcon_Offset;
	Int32 (*_CustomDataTagClassInterface_GetTagPluginFlags) (const maxon::GenericComponent* this_);
	maxon::Int _CustomDataTagClassInterface_GetTagPluginFlags_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CustomDataTagClassInterface, GetTagPluginId))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CustomDataTagClassInterface, GetTagPluginId), W, MTable>::type::_CustomDataTagClassInterface_GetTagPluginId;
			_CustomDataTagClassInterface_GetTagPluginId = reinterpret_cast<const decltype(_CustomDataTagClassInterface_GetTagPluginId)&>(ptr);
			_CustomDataTagClassInterface_GetTagPluginId_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CustomDataTagClassInterface, GetTagPluginName))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CustomDataTagClassInterface, GetTagPluginName), W, MTable>::type::_CustomDataTagClassInterface_GetTagPluginName;
			_CustomDataTagClassInterface_GetTagPluginName = reinterpret_cast<const decltype(_CustomDataTagClassInterface_GetTagPluginName)&>(ptr);
			_CustomDataTagClassInterface_GetTagPluginName_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CustomDataTagClassInterface, GetResourceId))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CustomDataTagClassInterface, GetResourceId), W, MTable>::type::_CustomDataTagClassInterface_GetResourceId;
			_CustomDataTagClassInterface_GetResourceId = reinterpret_cast<const decltype(_CustomDataTagClassInterface_GetResourceId)&>(ptr);
			_CustomDataTagClassInterface_GetResourceId_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CustomDataTagClassInterface, GetTagPluginLevel))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CustomDataTagClassInterface, GetTagPluginLevel), W, MTable>::type::_CustomDataTagClassInterface_GetTagPluginLevel;
			_CustomDataTagClassInterface_GetTagPluginLevel = reinterpret_cast<const decltype(_CustomDataTagClassInterface_GetTagPluginLevel)&>(ptr);
			_CustomDataTagClassInterface_GetTagPluginLevel_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CustomDataTagClassInterface, GetDisplayClassId))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CustomDataTagClassInterface, GetDisplayClassId), W, MTable>::type::_CustomDataTagClassInterface_GetDisplayClassId;
			_CustomDataTagClassInterface_GetDisplayClassId = reinterpret_cast<const decltype(_CustomDataTagClassInterface_GetDisplayClassId)&>(ptr);
			_CustomDataTagClassInterface_GetDisplayClassId_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CustomDataTagClassInterface, IsSdsCompatible))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CustomDataTagClassInterface, IsSdsCompatible), W, MTable>::type::_CustomDataTagClassInterface_IsSdsCompatible;
			_CustomDataTagClassInterface_IsSdsCompatible = reinterpret_cast<const decltype(_CustomDataTagClassInterface_IsSdsCompatible)&>(ptr);
			_CustomDataTagClassInterface_IsSdsCompatible_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CustomDataTagClassInterface, Read))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CustomDataTagClassInterface, Read), W, MTable>::type::_CustomDataTagClassInterface_Read;
			_CustomDataTagClassInterface_Read = reinterpret_cast<const decltype(_CustomDataTagClassInterface_Read)&>(ptr);
			_CustomDataTagClassInterface_Read_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CustomDataTagClassInterface, Write))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CustomDataTagClassInterface, Write), W, MTable>::type::_CustomDataTagClassInterface_Write;
			_CustomDataTagClassInterface_Write = reinterpret_cast<const decltype(_CustomDataTagClassInterface_Write)&>(ptr);
			_CustomDataTagClassInterface_Write_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CustomDataTagClassInterface, GetIcon))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CustomDataTagClassInterface, GetIcon), W, MTable>::type::_CustomDataTagClassInterface_GetIcon;
			_CustomDataTagClassInterface_GetIcon = reinterpret_cast<const decltype(_CustomDataTagClassInterface_GetIcon)&>(ptr);
			_CustomDataTagClassInterface_GetIcon_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CustomDataTagClassInterface, GetTagPluginFlags))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CustomDataTagClassInterface, GetTagPluginFlags), W, MTable>::type::_CustomDataTagClassInterface_GetTagPluginFlags;
			_CustomDataTagClassInterface_GetTagPluginFlags = reinterpret_cast<const decltype(_CustomDataTagClassInterface_GetTagPluginFlags)&>(ptr);
			_CustomDataTagClassInterface_GetTagPluginFlags_Offset = offset;
		}
	}
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset)
	{
		if (!W::Implementation::PROXY && (!MeshAttributeClassInterface::MTable::template InitWithBases<W>(info, offset))) return false;
		MTable* vt = (MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, _interface); if (!vt) return false;
		vt->Init<W>(offset); return true;
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<CustomDataTagClassInterface, typename MeshAttributeClassInterface::MTable::template CombinedMTable<S>>;
	PRIVATE_MAXON_COMPBASE(CustomDataTagClassInterface);
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct CustomDataTagClassInterface::Hxx2
{
	template <typename S> class Wrapper : public MeshAttributeClassInterface::Hxx2::template Wrapper<S>
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
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(Read);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(Write);
	static Int32 _CustomDataTagClassInterface_GetTagPluginId(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetTagPluginId(); }
	static const String& _CustomDataTagClassInterface_GetTagPluginName(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetTagPluginName(); }
	static const String& _CustomDataTagClassInterface_GetResourceId(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetResourceId(); }
	static Int32 _CustomDataTagClassInterface_GetTagPluginLevel(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetTagPluginLevel(); }
	static Id _CustomDataTagClassInterface_GetDisplayClassId(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetDisplayClassId(); }
	static Bool _CustomDataTagClassInterface_IsSdsCompatible(const maxon::GenericComponent* this_, Int32& floatSize) { return ((const typename S::Implementation*) this_)->IsSdsCompatible(floatSize); }
	static Result<void> _CustomDataTagClassInterface_Read(const maxon::GenericComponent* this_, void* data, HyperFile* hf, Int32 level) { return ((const typename S::Implementation*) this_)->Read(data, hf, level); }
	static Result<void> _CustomDataTagClassInterface_Write(const maxon::GenericComponent* this_, const void* data, HyperFile* hf) { return ((const typename S::Implementation*) this_)->Write(data, hf); }
	static Int32 _CustomDataTagClassInterface_GetIcon(const maxon::GenericComponent* this_, Bool perPolyVertex) { return ((const typename S::Implementation*) this_)->GetIcon(perPolyVertex); }
	static Int32 _CustomDataTagClassInterface_GetTagPluginFlags(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetTagPluginFlags(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto CustomDataTagClassInterface::GetTagPluginId() const -> Int32
{
	const CustomDataTagClassInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(CustomDataTagClassInterface, this); return mt_._CustomDataTagClassInterface_GetTagPluginId((const maxon::GenericComponent*) this + mt_._CustomDataTagClassInterface_GetTagPluginId_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CustomDataTagClassInterface::GetTagPluginName() const -> const String&
{
	const CustomDataTagClassInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(CustomDataTagClassInterface, this); return mt_._CustomDataTagClassInterface_GetTagPluginName((const maxon::GenericComponent*) this + mt_._CustomDataTagClassInterface_GetTagPluginName_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CustomDataTagClassInterface::GetResourceId() const -> const String&
{
	const CustomDataTagClassInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(CustomDataTagClassInterface, this); return mt_._CustomDataTagClassInterface_GetResourceId((const maxon::GenericComponent*) this + mt_._CustomDataTagClassInterface_GetResourceId_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CustomDataTagClassInterface::GetTagPluginLevel() const -> Int32
{
	const CustomDataTagClassInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(CustomDataTagClassInterface, this); return mt_._CustomDataTagClassInterface_GetTagPluginLevel((const maxon::GenericComponent*) this + mt_._CustomDataTagClassInterface_GetTagPluginLevel_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CustomDataTagClassInterface::GetDisplayClassId() const -> Id
{
	const CustomDataTagClassInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(CustomDataTagClassInterface, this); return mt_._CustomDataTagClassInterface_GetDisplayClassId((const maxon::GenericComponent*) this + mt_._CustomDataTagClassInterface_GetDisplayClassId_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CustomDataTagClassInterface::IsSdsCompatible(Int32& floatSize) const -> Bool
{
	const CustomDataTagClassInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(CustomDataTagClassInterface, this); return mt_._CustomDataTagClassInterface_IsSdsCompatible((const maxon::GenericComponent*) this + mt_._CustomDataTagClassInterface_IsSdsCompatible_Offset, floatSize);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CustomDataTagClassInterface::Read(void* data, HyperFile* hf, Int32 level) const -> Result<void>
{
	const CustomDataTagClassInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(CustomDataTagClassInterface, this); return mt_._CustomDataTagClassInterface_Read((const maxon::GenericComponent*) this + mt_._CustomDataTagClassInterface_Read_Offset, data, hf, level);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CustomDataTagClassInterface::Write(const void* data, HyperFile* hf) const -> Result<void>
{
	const CustomDataTagClassInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(CustomDataTagClassInterface, this); return mt_._CustomDataTagClassInterface_Write((const maxon::GenericComponent*) this + mt_._CustomDataTagClassInterface_Write_Offset, data, hf);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CustomDataTagClassInterface::GetIcon(Bool perPolyVertex) const -> Int32
{
	const CustomDataTagClassInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(CustomDataTagClassInterface, this); return mt_._CustomDataTagClassInterface_GetIcon((const maxon::GenericComponent*) this + mt_._CustomDataTagClassInterface_GetIcon_Offset, perPolyVertex);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CustomDataTagClassInterface::GetTagPluginFlags() const -> Int32
{
	const CustomDataTagClassInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(CustomDataTagClassInterface, this); return mt_._CustomDataTagClassInterface_GetTagPluginFlags((const maxon::GenericComponent*) this + mt_._CustomDataTagClassInterface_GetTagPluginFlags_Offset);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CustomDataTagClassInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetTagPluginId() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int32>, Int32>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int32>, Int32>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const CustomDataTagClassInterface* o_ = (const CustomDataTagClassInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = CustomDataTagClassInterface::NullValuePtr(); if (!o_) return 0; } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CustomDataTagClassInterface, o_, CustomDataTagClassInterface_GetTagPluginId) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<CustomDataTagClassInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CustomDataTagClassInterface>() : PRIVATE_MAXON_VTABLE(CustomDataTagClassInterface, o_); 
	return (mt_._CustomDataTagClassInterface_GetTagPluginId(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._CustomDataTagClassInterface_GetTagPluginId_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CustomDataTagClassInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetTagPluginName() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const String&>, const String&>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const String&>, const String&>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const CustomDataTagClassInterface* o_ = (const CustomDataTagClassInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = CustomDataTagClassInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<const String&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CustomDataTagClassInterface, o_, CustomDataTagClassInterface_GetTagPluginName) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<CustomDataTagClassInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CustomDataTagClassInterface>() : PRIVATE_MAXON_VTABLE(CustomDataTagClassInterface, o_); 
	return (mt_._CustomDataTagClassInterface_GetTagPluginName(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._CustomDataTagClassInterface_GetTagPluginName_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CustomDataTagClassInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetResourceId() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const String&>, const String&>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const String&>, const String&>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const CustomDataTagClassInterface* o_ = (const CustomDataTagClassInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = CustomDataTagClassInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<const String&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CustomDataTagClassInterface, o_, CustomDataTagClassInterface_GetResourceId) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<CustomDataTagClassInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CustomDataTagClassInterface>() : PRIVATE_MAXON_VTABLE(CustomDataTagClassInterface, o_); 
	return (mt_._CustomDataTagClassInterface_GetResourceId(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._CustomDataTagClassInterface_GetResourceId_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CustomDataTagClassInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetTagPluginLevel() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int32>, Int32>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int32>, Int32>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const CustomDataTagClassInterface* o_ = (const CustomDataTagClassInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = CustomDataTagClassInterface::NullValuePtr(); if (!o_) return 0; } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CustomDataTagClassInterface, o_, CustomDataTagClassInterface_GetTagPluginLevel) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<CustomDataTagClassInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CustomDataTagClassInterface>() : PRIVATE_MAXON_VTABLE(CustomDataTagClassInterface, o_); 
	return (mt_._CustomDataTagClassInterface_GetTagPluginLevel(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._CustomDataTagClassInterface_GetTagPluginLevel_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CustomDataTagClassInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetDisplayClassId() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Id>, Id>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Id>, Id>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const CustomDataTagClassInterface* o_ = (const CustomDataTagClassInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = CustomDataTagClassInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<Id>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CustomDataTagClassInterface, o_, CustomDataTagClassInterface_GetDisplayClassId) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<CustomDataTagClassInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CustomDataTagClassInterface>() : PRIVATE_MAXON_VTABLE(CustomDataTagClassInterface, o_); 
	return (mt_._CustomDataTagClassInterface_GetDisplayClassId(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._CustomDataTagClassInterface_GetDisplayClassId_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CustomDataTagClassInterface::Hxx1::ConstReferenceFunctionsImpl<S>::IsSdsCompatible(Int32& floatSize) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const CustomDataTagClassInterface* o_ = (const CustomDataTagClassInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = CustomDataTagClassInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CustomDataTagClassInterface, o_, CustomDataTagClassInterface_IsSdsCompatible) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<CustomDataTagClassInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CustomDataTagClassInterface>() : PRIVATE_MAXON_VTABLE(CustomDataTagClassInterface, o_); 
	return (mt_._CustomDataTagClassInterface_IsSdsCompatible(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._CustomDataTagClassInterface_IsSdsCompatible_Offset, floatSize));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CustomDataTagClassInterface::Hxx1::ConstReferenceFunctionsImpl<S>::Read(void* data, HyperFile* hf, Int32 level) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const CustomDataTagClassInterface* o_ = (const CustomDataTagClassInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = CustomDataTagClassInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CustomDataTagClassInterface, o_, CustomDataTagClassInterface_Read) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<CustomDataTagClassInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CustomDataTagClassInterface>() : PRIVATE_MAXON_VTABLE(CustomDataTagClassInterface, o_); 
	return (mt_._CustomDataTagClassInterface_Read(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._CustomDataTagClassInterface_Read_Offset, data, hf, level));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CustomDataTagClassInterface::Hxx1::ConstReferenceFunctionsImpl<S>::Write(const void* data, HyperFile* hf) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const CustomDataTagClassInterface* o_ = (const CustomDataTagClassInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = CustomDataTagClassInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CustomDataTagClassInterface, o_, CustomDataTagClassInterface_Write) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<CustomDataTagClassInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CustomDataTagClassInterface>() : PRIVATE_MAXON_VTABLE(CustomDataTagClassInterface, o_); 
	return (mt_._CustomDataTagClassInterface_Write(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._CustomDataTagClassInterface_Write_Offset, data, hf));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CustomDataTagClassInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetIcon(Bool perPolyVertex) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int32>, Int32>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int32>, Int32>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const CustomDataTagClassInterface* o_ = (const CustomDataTagClassInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = CustomDataTagClassInterface::NullValuePtr(); if (!o_) return 0; } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CustomDataTagClassInterface, o_, CustomDataTagClassInterface_GetIcon) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<CustomDataTagClassInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CustomDataTagClassInterface>() : PRIVATE_MAXON_VTABLE(CustomDataTagClassInterface, o_); 
	return (mt_._CustomDataTagClassInterface_GetIcon(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._CustomDataTagClassInterface_GetIcon_Offset, perPolyVertex));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CustomDataTagClassInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetDefaultResourceId() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const String&>, const String&>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const String&>, const String&>::type>; static_assert(!std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value, "Can't invoke MAXON_FUNCTION CustomDataTagClassInterface::GetDefaultResourceId on super."); if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const CustomDataTagClassInterface* o_ = (const CustomDataTagClassInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = CustomDataTagClassInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<const String&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (o_->GetDefaultResourceId());
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CustomDataTagClassInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetTagPluginFlags() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int32>, Int32>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int32>, Int32>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const CustomDataTagClassInterface* o_ = (const CustomDataTagClassInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = CustomDataTagClassInterface::NullValuePtr(); if (!o_) return 0; } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CustomDataTagClassInterface, o_, CustomDataTagClassInterface_GetTagPluginFlags) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<CustomDataTagClassInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CustomDataTagClassInterface>() : PRIVATE_MAXON_VTABLE(CustomDataTagClassInterface, o_); 
	return (mt_._CustomDataTagClassInterface_GetTagPluginFlags(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._CustomDataTagClassInterface_GetTagPluginFlags_Offset));
}
auto CustomDataTagClassInterface::GetPtr() -> Ptr { return Ptr(this); }
auto CustomDataTagClassInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
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

