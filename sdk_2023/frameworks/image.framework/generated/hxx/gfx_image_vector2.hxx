
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
	PRIVATE_MAXON_MF_POINTER(VectorImageInterface_Init, Init, true, maxon::GenericComponent,, (Result<void>), const Url& url);
	maxon::Int VectorImageInterface_Init_Offset;
	PRIVATE_MAXON_MF_POINTER(VectorImageInterface_Init_1, Init, true, maxon::GenericComponent,, (Result<void>), const SVGDocument& svgDocument);
	maxon::Int VectorImageInterface_Init_1_Offset;
	PRIVATE_MAXON_MF_POINTER(VectorImageInterface_GetUrl, GetUrl, true, maxon::GenericComponent, const, (const Url&));
	maxon::Int VectorImageInterface_GetUrl_Offset;
	PRIVATE_MAXON_MF_POINTER(VectorImageInterface_GetSVGDocument, GetSVGDocument, true, maxon::GenericComponent, const, (Result<ForwardRef<SVGDocument>>));
	maxon::Int VectorImageInterface_GetSVGDocument_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, VectorImageInterface, Init))
	{
		maxon::Tie(VectorImageInterface_Init, VectorImageInterface_Init_Offset) = VectorImageInterface_Init_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, VectorImageInterface, Init))
	{
		maxon::Tie(VectorImageInterface_Init_1, VectorImageInterface_Init_1_Offset) = VectorImageInterface_Init_1_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, VectorImageInterface, GetUrl))
	{
		maxon::Tie(VectorImageInterface_GetUrl, VectorImageInterface_GetUrl_Offset) = VectorImageInterface_GetUrl_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, VectorImageInterface, GetSVGDocument))
	{
		maxon::Tie(VectorImageInterface_GetSVGDocument, VectorImageInterface_GetSVGDocument_Offset) = VectorImageInterface_GetSVGDocument_GetPtr<W>(offset, true);
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
			if constexpr (!S::Implementation::PROXY)
			{
				if (!(Super0::InitMTablesWithBases(info, offset))) return false;
			}
			auto* vt = (VectorImageInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, VectorImageInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		PRIVATE_MAXON_MF_WRAPPER(VectorImageInterface_Init, maxon::GenericComponent,, (Result<void>), const Url& url) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->Init(url); }
		PRIVATE_MAXON_MF_WRAPPER(VectorImageInterface_Init_1, maxon::GenericComponent,, (Result<void>), const SVGDocument& svgDocument) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->Init(svgDocument); }
		PRIVATE_MAXON_MF_WRAPPER(VectorImageInterface_GetUrl, maxon::GenericComponent, const, (const Url&)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetUrl(); }
		PRIVATE_MAXON_MF_WRAPPER(VectorImageInterface_GetSVGDocument, maxon::GenericComponent, const, (Result<ForwardRef<SVGDocument>>)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetSVGDocument(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto VectorImageInterface::Init(const Url& url) -> Result<void>
{
	const VectorImageInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(VectorImageInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.VectorImageInterface_Init_Offset), mt_.VectorImageInterface_Init, url);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto VectorImageInterface::Init(const SVGDocument& svgDocument) -> Result<void>
{
	const VectorImageInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(VectorImageInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.VectorImageInterface_Init_1_Offset), mt_.VectorImageInterface_Init_1, svgDocument);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto VectorImageInterface::GetUrl() const -> const Url&
{
	const VectorImageInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(VectorImageInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.VectorImageInterface_GetUrl_Offset), mt_.VectorImageInterface_GetUrl);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto VectorImageInterface::GetSVGDocument() const -> Result<ForwardRef<SVGDocument>>
{
	const VectorImageInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(VectorImageInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.VectorImageInterface_GetSVGDocument_Offset), mt_.VectorImageInterface_GetSVGDocument);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VectorImageInterface::Hxx1::Fn<S>::Init(const Url& url) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); VectorImageInterface* o_ = (VectorImageInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VectorImageInterface, o_, VectorImageInterface_Init) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<VectorImageInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VectorImageInterface>() : PRIVATE_MAXON_VTABLE(VectorImageInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.VectorImageInterface_Init_Offset), mt_.VectorImageInterface_Init, url));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VectorImageInterface::Hxx1::COWFn<S>::Init(const Url& url) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); VectorImageInterface* o_ = (VectorImageInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VectorImageInterface, o_, VectorImageInterface_Init) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<VectorImageInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VectorImageInterface>() : PRIVATE_MAXON_VTABLE(VectorImageInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.VectorImageInterface_Init_Offset), mt_.VectorImageInterface_Init, url));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VectorImageInterface::Hxx1::Fn<S>::Init(const SVGDocument& svgDocument) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); VectorImageInterface* o_ = (VectorImageInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VectorImageInterface, o_, VectorImageInterface_Init_1) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<VectorImageInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VectorImageInterface>() : PRIVATE_MAXON_VTABLE(VectorImageInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.VectorImageInterface_Init_1_Offset), mt_.VectorImageInterface_Init_1, svgDocument));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VectorImageInterface::Hxx1::COWFn<S>::Init(const SVGDocument& svgDocument) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); VectorImageInterface* o_ = (VectorImageInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VectorImageInterface, o_, VectorImageInterface_Init_1) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<VectorImageInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VectorImageInterface>() : PRIVATE_MAXON_VTABLE(VectorImageInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.VectorImageInterface_Init_1_Offset), mt_.VectorImageInterface_Init_1, svgDocument));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VectorImageInterface::Hxx1::ConstFn<S>::GetUrl() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const Url&>, const Url&>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const Url&>, const Url&>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const VectorImageInterface* o_ = (const VectorImageInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = VectorImageInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<const Url&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VectorImageInterface, o_, VectorImageInterface_GetUrl) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<VectorImageInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VectorImageInterface>() : PRIVATE_MAXON_VTABLE(VectorImageInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.VectorImageInterface_GetUrl_Offset), mt_.VectorImageInterface_GetUrl));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto VectorImageInterface::Hxx1::ConstFn<S>::GetSVGDocument() const -> Result<ForwardRef<SVGDocument>>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<ForwardRef<SVGDocument>>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const VectorImageInterface* o_ = (const VectorImageInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = VectorImageInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(VectorImageInterface, o_, VectorImageInterface_GetSVGDocument) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<VectorImageInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<VectorImageInterface>() : PRIVATE_MAXON_VTABLE(VectorImageInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.VectorImageInterface_GetSVGDocument_Offset), mt_.VectorImageInterface_GetSVGDocument));
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

