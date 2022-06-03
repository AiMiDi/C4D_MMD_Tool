
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
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetSVGDocument);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetUrl);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(Init);
	static const maxon::Char* const _ids;
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	Result<void> (*VectorImageInterface_Init) (maxon::GenericComponent* this_, const Url& url);
	maxon::Int VectorImageInterface_Init_Offset;
	Result<void> (*VectorImageInterface_Init_1) (maxon::GenericComponent* this_, const SVGDocument& svgDocument);
	maxon::Int VectorImageInterface_Init_1_Offset;
	const Url& (*VectorImageInterface_GetUrl) (const maxon::GenericComponent* this_);
	maxon::Int VectorImageInterface_GetUrl_Offset;
	Result<ForwardRef<SVGDocument>> (*VectorImageInterface_GetSVGDocument) (const maxon::GenericComponent* this_);
	maxon::Int VectorImageInterface_GetSVGDocument_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, VectorImageInterface, Init))
	{
		VectorImageInterface_Init = &W::VectorImageInterface_Init;
		VectorImageInterface_Init_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, VectorImageInterface, Init))
	{
		VectorImageInterface_Init_1 = &W::VectorImageInterface_Init_1;
		VectorImageInterface_Init_1_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, VectorImageInterface, GetUrl))
	{
		VectorImageInterface_GetUrl = &W::VectorImageInterface_GetUrl;
		VectorImageInterface_GetUrl_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, VectorImageInterface, GetSVGDocument))
	{
		VectorImageInterface_GetSVGDocument = &W::VectorImageInterface_GetSVGDocument;
		VectorImageInterface_GetSVGDocument_Offset = offset;
	}
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
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetSVGDocument);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetUrl);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(Init);
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename ImageBaseInterface::Hxx2::template CWrapper<S>;
			if (!S::Implementation::PROXY && !(Super0::InitMTablesWithBases(info, offset))) return false;
			auto* vt = (VectorImageInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, VectorImageInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		static Result<void> VectorImageInterface_Init(maxon::GenericComponent* this_, const Url& url) { return ((typename S::Implementation*) this_)->Init(url); }
		static Result<void> VectorImageInterface_Init_1(maxon::GenericComponent* this_, const SVGDocument& svgDocument) { return ((typename S::Implementation*) this_)->Init(svgDocument); }
		static const Url& VectorImageInterface_GetUrl(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetUrl(); }
		static Result<ForwardRef<SVGDocument>> VectorImageInterface_GetSVGDocument(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetSVGDocument(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto VectorImageInterface::Init(const Url& url) -> Result<void>
{
	const VectorImageInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(VectorImageInterface, this); return mt_.VectorImageInterface_Init((maxon::GenericComponent*) this + mt_.VectorImageInterface_Init_Offset, url);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto VectorImageInterface::Init(const SVGDocument& svgDocument) -> Result<void>
{
	const VectorImageInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(VectorImageInterface, this); return mt_.VectorImageInterface_Init_1((maxon::GenericComponent*) this + mt_.VectorImageInterface_Init_1_Offset, svgDocument);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto VectorImageInterface::GetUrl() const -> const Url&
{
	const VectorImageInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(VectorImageInterface, this); return mt_.VectorImageInterface_GetUrl((const maxon::GenericComponent*) this + mt_.VectorImageInterface_GetUrl_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto VectorImageInterface::GetSVGDocument() const -> Result<ForwardRef<SVGDocument>>
{
	const VectorImageInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(VectorImageInterface, this); return mt_.VectorImageInterface_GetSVGDocument((const maxon::GenericComponent*) this + mt_.VectorImageInterface_GetSVGDocument_Offset);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VectorImageInterface::Hxx1::Fn<S>::Init(const Url& url) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); VectorImageInterface* o_ = (VectorImageInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VectorImageInterface, o_, VectorImageInterface_Init) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<VectorImageInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VectorImageInterface>() : PRIVATE_MAXON_VTABLE(VectorImageInterface, o_); 
	return (mt_.VectorImageInterface_Init(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.VectorImageInterface_Init_Offset, url));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VectorImageInterface::Hxx1::COWFn<S>::Init(const Url& url) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); VectorImageInterface* o_ = (VectorImageInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VectorImageInterface, o_, VectorImageInterface_Init) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<VectorImageInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VectorImageInterface>() : PRIVATE_MAXON_VTABLE(VectorImageInterface, o_); 
	return (mt_.VectorImageInterface_Init(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.VectorImageInterface_Init_Offset, url));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VectorImageInterface::Hxx1::Fn<S>::Init(const SVGDocument& svgDocument) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); VectorImageInterface* o_ = (VectorImageInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VectorImageInterface, o_, VectorImageInterface_Init_1) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<VectorImageInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VectorImageInterface>() : PRIVATE_MAXON_VTABLE(VectorImageInterface, o_); 
	return (mt_.VectorImageInterface_Init_1(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.VectorImageInterface_Init_1_Offset, svgDocument));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VectorImageInterface::Hxx1::COWFn<S>::Init(const SVGDocument& svgDocument) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); VectorImageInterface* o_ = (VectorImageInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VectorImageInterface, o_, VectorImageInterface_Init_1) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<VectorImageInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VectorImageInterface>() : PRIVATE_MAXON_VTABLE(VectorImageInterface, o_); 
	return (mt_.VectorImageInterface_Init_1(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.VectorImageInterface_Init_1_Offset, svgDocument));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VectorImageInterface::Hxx1::ConstFn<S>::GetUrl() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const Url&>, const Url&>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const Url&>, const Url&>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const VectorImageInterface* o_ = (const VectorImageInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = VectorImageInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<const Url&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VectorImageInterface, o_, VectorImageInterface_GetUrl) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<VectorImageInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VectorImageInterface>() : PRIVATE_MAXON_VTABLE(VectorImageInterface, o_); 
	return (mt_.VectorImageInterface_GetUrl(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.VectorImageInterface_GetUrl_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VectorImageInterface::Hxx1::ConstFn<S>::GetSVGDocument() const -> Result<ForwardRef<SVGDocument>>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<ForwardRef<SVGDocument>>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const VectorImageInterface* o_ = (const VectorImageInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = VectorImageInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VectorImageInterface, o_, VectorImageInterface_GetSVGDocument) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<VectorImageInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VectorImageInterface>() : PRIVATE_MAXON_VTABLE(VectorImageInterface, o_); 
	return (mt_.VectorImageInterface_GetSVGDocument(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.VectorImageInterface_GetSVGDocument_Offset));
}
auto VectorImageInterface::GetPtr() -> Ptr { return Ptr(this); }
auto VectorImageInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_gfx_image_vector)
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

