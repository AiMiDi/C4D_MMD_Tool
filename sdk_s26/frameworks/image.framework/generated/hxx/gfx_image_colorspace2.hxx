
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1

struct ColorSpaceInterface::MTable
{
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetDefaultLinearColorProfile);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetDefaultNonlinearColorProfile);
	static const maxon::Char* const _ids;
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	const ColorProfile& (*ColorSpaceInterface_GetDefaultNonlinearColorProfile) (const maxon::GenericComponent* this_);
	maxon::Int ColorSpaceInterface_GetDefaultNonlinearColorProfile_Offset;
	const ColorProfile& (*ColorSpaceInterface_GetDefaultLinearColorProfile) (const maxon::GenericComponent* this_);
	maxon::Int ColorSpaceInterface_GetDefaultLinearColorProfile_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ColorSpaceInterface, GetDefaultNonlinearColorProfile))
	{
		ColorSpaceInterface_GetDefaultNonlinearColorProfile = &W::ColorSpaceInterface_GetDefaultNonlinearColorProfile;
		ColorSpaceInterface_GetDefaultNonlinearColorProfile_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ColorSpaceInterface, GetDefaultLinearColorProfile))
	{
		ColorSpaceInterface_GetDefaultLinearColorProfile = &W::ColorSpaceInterface_GetDefaultLinearColorProfile;
		ColorSpaceInterface_GetDefaultLinearColorProfile_Offset = offset;
	}
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<ColorSpaceInterface, typename ObjectInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<ColorSpaceInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct ColorSpaceInterface::Hxx2
{
	template <typename S> class CWrapper : public ObjectInterface::Hxx2::template CWrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetDefaultLinearColorProfile);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetDefaultNonlinearColorProfile);
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename ObjectInterface::Hxx2::template CWrapper<S>;
			if (!S::Implementation::PROXY && !(Super0::InitMTablesWithBases(info, offset))) return false;
			auto* vt = (ColorSpaceInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, ColorSpaceInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		static const ColorProfile& ColorSpaceInterface_GetDefaultNonlinearColorProfile(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetDefaultNonlinearColorProfile(); }
		static const ColorProfile& ColorSpaceInterface_GetDefaultLinearColorProfile(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetDefaultLinearColorProfile(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto ColorSpaceInterface::GetDefaultNonlinearColorProfile() const -> const ColorProfile&
{
	const ColorSpaceInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ColorSpaceInterface, this); return mt_.ColorSpaceInterface_GetDefaultNonlinearColorProfile((const maxon::GenericComponent*) this + mt_.ColorSpaceInterface_GetDefaultNonlinearColorProfile_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ColorSpaceInterface::GetDefaultLinearColorProfile() const -> const ColorProfile&
{
	const ColorSpaceInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ColorSpaceInterface, this); return mt_.ColorSpaceInterface_GetDefaultLinearColorProfile((const maxon::GenericComponent*) this + mt_.ColorSpaceInterface_GetDefaultLinearColorProfile_Offset);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ColorSpaceInterface::Hxx1::ConstFn<S>::GetDefaultNonlinearColorProfile() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const ColorProfile&>, const ColorProfile&>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const ColorProfile&>, const ColorProfile&>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ColorSpaceInterface* o_ = (const ColorSpaceInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ColorSpaceInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<const ColorProfile&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ColorSpaceInterface, o_, ColorSpaceInterface_GetDefaultNonlinearColorProfile) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ColorSpaceInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ColorSpaceInterface>() : PRIVATE_MAXON_VTABLE(ColorSpaceInterface, o_); 
	return (mt_.ColorSpaceInterface_GetDefaultNonlinearColorProfile(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.ColorSpaceInterface_GetDefaultNonlinearColorProfile_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ColorSpaceInterface::Hxx1::ConstFn<S>::GetDefaultLinearColorProfile() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const ColorProfile&>, const ColorProfile&>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const ColorProfile&>, const ColorProfile&>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ColorSpaceInterface* o_ = (const ColorSpaceInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ColorSpaceInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<const ColorProfile&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ColorSpaceInterface, o_, ColorSpaceInterface_GetDefaultLinearColorProfile) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ColorSpaceInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ColorSpaceInterface>() : PRIVATE_MAXON_VTABLE(ColorSpaceInterface, o_); 
	return (mt_.ColorSpaceInterface_GetDefaultLinearColorProfile(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.ColorSpaceInterface_GetDefaultLinearColorProfile_Offset));
}
auto ColorSpaceInterface::GetPtr() -> Ptr { return Ptr(this); }
auto ColorSpaceInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_gfx_image_colorspace)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_ColorSpaceInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_ColorSpaceInterface() { new (s_ui_maxon_ColorSpaceInterface) maxon::EntityUse(ColorSpaceInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/gfx_image_colorspace.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_ColorSpaceInterface(ColorSpaceInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/gfx_image_colorspace.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

