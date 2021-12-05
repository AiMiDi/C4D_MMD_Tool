
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1

struct VectorImageInterface::MTable
{
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetVectorIcon);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(Init);
	static const maxon::Char* const _ids;
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	Result<void> (*_VectorImageInterface_Init) (maxon::GenericComponent* this_, const Url& vectorIconUrl);
	maxon::Int _VectorImageInterface_Init_Offset;
	Result<void> (*_VectorImageInterface_Init_1) (maxon::GenericComponent* this_, const SVGDocument& vectorIcon);
	maxon::Int _VectorImageInterface_Init_1_Offset;
	Result<ForwardRef<SVGDocument>> (*_VectorImageInterface_GetVectorIcon) (const maxon::GenericComponent* this_);
	maxon::Int _VectorImageInterface_GetVectorIcon_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, VectorImageInterface, Init))
	{
		auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, VectorImageInterface, Init), W, MTable>::type::_VectorImageInterface_Init;
		_VectorImageInterface_Init = reinterpret_cast<const decltype(_VectorImageInterface_Init)&>(ptr);
		_VectorImageInterface_Init_Offset = offset;
	}
	if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, VectorImageInterface, Init))
	{
		auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, VectorImageInterface, Init), W, MTable>::type::_VectorImageInterface_Init_1;
		_VectorImageInterface_Init_1 = reinterpret_cast<const decltype(_VectorImageInterface_Init_1)&>(ptr);
		_VectorImageInterface_Init_1_Offset = offset;
	}
	if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, VectorImageInterface, GetVectorIcon))
	{
		auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, VectorImageInterface, GetVectorIcon), W, MTable>::type::_VectorImageInterface_GetVectorIcon;
		_VectorImageInterface_GetVectorIcon = reinterpret_cast<const decltype(_VectorImageInterface_GetVectorIcon)&>(ptr);
		_VectorImageInterface_GetVectorIcon_Offset = offset;
	}
	}
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset)
	{
		if (!W::Implementation::PROXY && (!ImageBaseInterface::MTable::template InitWithBases<W>(info, offset))) return false;
		MTable* vt = (MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, _interface); if (!vt) return false;
		vt->Init<W>(offset);
		return true;
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<VectorImageInterface, typename ImageBaseInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<VectorImageInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct VectorImageInterface::Hxx2
{
	template <typename S> class CWrapper : public ImageBaseInterface::Hxx2::template CWrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetVectorIcon);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(Init);
		static Result<void> _VectorImageInterface_Init(maxon::GenericComponent* this_, const Url& vectorIconUrl) { return ((typename S::Implementation*) this_)->Init(vectorIconUrl); }
		static Result<void> _VectorImageInterface_Init_1(maxon::GenericComponent* this_, const SVGDocument& vectorIcon) { return ((typename S::Implementation*) this_)->Init(vectorIcon); }
		static Result<ForwardRef<SVGDocument>> _VectorImageInterface_GetVectorIcon(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetVectorIcon(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto VectorImageInterface::Init(const Url& vectorIconUrl) -> Result<void>
{
	const VectorImageInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(VectorImageInterface, this); return mt_._VectorImageInterface_Init((maxon::GenericComponent*) this + mt_._VectorImageInterface_Init_Offset, vectorIconUrl);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto VectorImageInterface::Init(const SVGDocument& vectorIcon) -> Result<void>
{
	const VectorImageInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(VectorImageInterface, this); return mt_._VectorImageInterface_Init_1((maxon::GenericComponent*) this + mt_._VectorImageInterface_Init_1_Offset, vectorIcon);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto VectorImageInterface::GetVectorIcon() const -> Result<ForwardRef<SVGDocument>>
{
	const VectorImageInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(VectorImageInterface, this); return mt_._VectorImageInterface_GetVectorIcon((const maxon::GenericComponent*) this + mt_._VectorImageInterface_GetVectorIcon_Offset);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VectorImageInterface::Hxx1::ReferenceFunctionsImpl<S>::Init(const Url& vectorIconUrl) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); VectorImageInterface* o_ = (VectorImageInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VectorImageInterface, o_, VectorImageInterface_Init) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<VectorImageInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VectorImageInterface>() : PRIVATE_MAXON_VTABLE(VectorImageInterface, o_); 
	return (mt_._VectorImageInterface_Init(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._VectorImageInterface_Init_Offset, vectorIconUrl));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VectorImageInterface::Hxx1::COWReferenceFunctionsImpl<S>::Init(const Url& vectorIconUrl) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); VectorImageInterface* o_ = (VectorImageInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VectorImageInterface, o_, VectorImageInterface_Init) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<VectorImageInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VectorImageInterface>() : PRIVATE_MAXON_VTABLE(VectorImageInterface, o_); 
	return (mt_._VectorImageInterface_Init(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._VectorImageInterface_Init_Offset, vectorIconUrl));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VectorImageInterface::Hxx1::ReferenceFunctionsImpl<S>::Init(const SVGDocument& vectorIcon) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); VectorImageInterface* o_ = (VectorImageInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VectorImageInterface, o_, VectorImageInterface_Init_1) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<VectorImageInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VectorImageInterface>() : PRIVATE_MAXON_VTABLE(VectorImageInterface, o_); 
	return (mt_._VectorImageInterface_Init_1(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._VectorImageInterface_Init_1_Offset, vectorIcon));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VectorImageInterface::Hxx1::COWReferenceFunctionsImpl<S>::Init(const SVGDocument& vectorIcon) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); VectorImageInterface* o_ = (VectorImageInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VectorImageInterface, o_, VectorImageInterface_Init_1) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<VectorImageInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VectorImageInterface>() : PRIVATE_MAXON_VTABLE(VectorImageInterface, o_); 
	return (mt_._VectorImageInterface_Init_1(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._VectorImageInterface_Init_1_Offset, vectorIcon));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VectorImageInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetVectorIcon() const -> Result<ForwardRef<SVGDocument>>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<ForwardRef<SVGDocument>>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const VectorImageInterface* o_ = (const VectorImageInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = VectorImageInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VectorImageInterface, o_, VectorImageInterface_GetVectorIcon) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<VectorImageInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VectorImageInterface>() : PRIVATE_MAXON_VTABLE(VectorImageInterface, o_); 
	return (mt_._VectorImageInterface_GetVectorIcon(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._VectorImageInterface_GetVectorIcon_Offset));
}
auto VectorImageInterface::GetPtr() -> Ptr { return Ptr(this); }
auto VectorImageInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_VectorImageInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_VectorImageInterface() { new (s_ui_maxon_VectorImageInterface) maxon::EntityUse(VectorImageInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/gfx_image_vector.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_VectorImageInterface(VectorImageInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/gfx_image_vector.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

