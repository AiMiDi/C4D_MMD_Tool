
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1

struct SettingsInterface::MTable
{
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetAccessLevel);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetParentSettings);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetSettingsCopy);
	static const maxon::Char* const _ids;
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	PRIVATE_MAXON_MF_POINTER(SettingsInterface_GetAccessLevel, GetAccessLevel, true, maxon::GenericComponent, const, (ACCESSLEVEL));
	maxon::Int SettingsInterface_GetAccessLevel_Offset;
	PRIVATE_MAXON_MF_POINTER(SettingsInterface_GetParentSettings, GetParentSettings, true, maxon::GenericComponent, const, (SettingsRef));
	maxon::Int SettingsInterface_GetParentSettings_Offset;
	PRIVATE_MAXON_MF_POINTER(SettingsInterface_GetSettingsCopy, GetSettingsCopy, true, maxon::GenericComponent, const, (Result<DataDictionary>), const HashSet<Id>& optionalList, ACCESSLEVEL accessLevel);
	maxon::Int SettingsInterface_GetSettingsCopy_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, SettingsInterface, GetAccessLevel))
	{
		maxon::Tie(SettingsInterface_GetAccessLevel, SettingsInterface_GetAccessLevel_Offset) = SettingsInterface_GetAccessLevel_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, SettingsInterface, GetParentSettings))
	{
		maxon::Tie(SettingsInterface_GetParentSettings, SettingsInterface_GetParentSettings_Offset) = SettingsInterface_GetParentSettings_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, SettingsInterface, GetSettingsCopy))
	{
		maxon::Tie(SettingsInterface_GetSettingsCopy, SettingsInterface_GetSettingsCopy_Offset) = SettingsInterface_GetSettingsCopy_GetPtr<W>(offset, true);
	}
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<SettingsInterface, typename DataDictionaryObjectInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<SettingsInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct SettingsInterface::Hxx2
{
	class Unresolved;
	struct StaticMTable
	{
		static StaticMTable _instance;
		static StaticMTable _unresolvedInstance;
		static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, StaticMTable* tbl);
		static const maxon::Char* const _ids;
		static const maxon::NULL_RETURN_TYPE _returnTypes[];
	PRIVATE_MAXON_SF_POINTER(SettingsInterface_GetSettings, GetSettings, MAXON_EXPAND_VA_ARGS, (SettingsRef), ACCESSLEVEL accessLevel);
	PRIVATE_MAXON_SF_POINTER(SettingsInterface_ObservableSettingsChanged, ObservableSettingsChanged, MAXON_EXPAND_VA_ARGS, (maxon::ObservableRef<ObservableSettingsChangedDelegate>));
		StaticMTable() = default;
		template <typename IMPL> static void Init(StaticMTable* tbl)
		{
		tbl->SettingsInterface_GetSettings = SettingsInterface_GetSettings_GetPtr<IMPL>(true);
		tbl->SettingsInterface_ObservableSettingsChanged = SettingsInterface_ObservableSettingsChanged_GetPtr<IMPL>(true);
		}
	};
	template <typename S> class CWrapper : public DataDictionaryObjectInterface::Hxx2::template CWrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetAccessLevel);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetParentSettings);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetSettingsCopy);
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename DataDictionaryObjectInterface::Hxx2::template CWrapper<S>;
			if constexpr (!S::Implementation::PROXY)
			{
				if (!(Super0::InitMTablesWithBases(info, offset))) return false;
			}
			auto* vt = (SettingsInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, SettingsInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		PRIVATE_MAXON_MF_WRAPPER(SettingsInterface_GetAccessLevel, maxon::GenericComponent, const, (ACCESSLEVEL)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetAccessLevel(); }
		PRIVATE_MAXON_MF_WRAPPER(SettingsInterface_GetParentSettings, maxon::GenericComponent, const, (SettingsRef)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetParentSettings(); }
		PRIVATE_MAXON_MF_WRAPPER(SettingsInterface_GetSettingsCopy, maxon::GenericComponent, const, (Result<DataDictionary>), const HashSet<Id>& optionalList, ACCESSLEVEL accessLevel) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetSettingsCopy(optionalList, accessLevel); }
		static SettingsRef SettingsInterface_GetSettings(ACCESSLEVEL accessLevel) { return S::Implementation::GetSettings(accessLevel); }
		static maxon::ObservableRef<ObservableSettingsChangedDelegate> SettingsInterface_ObservableSettingsChanged() { return S::Implementation::ObservableSettingsChanged(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto SettingsInterface::GetAccessLevel() const -> ACCESSLEVEL
{
	const SettingsInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(SettingsInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.SettingsInterface_GetAccessLevel_Offset), mt_.SettingsInterface_GetAccessLevel);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SettingsInterface::GetParentSettings() const -> SettingsRef
{
	const SettingsInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(SettingsInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.SettingsInterface_GetParentSettings_Offset), mt_.SettingsInterface_GetParentSettings);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SettingsInterface::GetSettingsCopy(const HashSet<Id>& optionalList, ACCESSLEVEL accessLevel) const -> Result<DataDictionary>
{
	const SettingsInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(SettingsInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.SettingsInterface_GetSettingsCopy_Offset), mt_.SettingsInterface_GetSettingsCopy, optionalList, accessLevel);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SettingsInterface::GetSettings(ACCESSLEVEL accessLevel) -> SettingsRef
{
	return Hxx2::StaticMTable::_instance.SettingsInterface_GetSettings(accessLevel);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SettingsInterface::ObservableSettingsChanged() -> maxon::ObservableRef<ObservableSettingsChangedDelegate>
{
	return Hxx2::StaticMTable::_instance.SettingsInterface_ObservableSettingsChanged();
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SettingsInterface::Hxx1::ConstFn<S>::GetAccessLevel() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<ACCESSLEVEL>, ACCESSLEVEL>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<ACCESSLEVEL>, ACCESSLEVEL>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const SettingsInterface* o_ = (const SettingsInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = SettingsInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<ACCESSLEVEL>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(SettingsInterface, o_, SettingsInterface_GetAccessLevel) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<SettingsInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<SettingsInterface>() : PRIVATE_MAXON_VTABLE(SettingsInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.SettingsInterface_GetAccessLevel_Offset), mt_.SettingsInterface_GetAccessLevel));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SettingsInterface::Hxx1::ConstFn<S>::GetParentSettings() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<SettingsRef>, SettingsRef>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<SettingsRef>, SettingsRef>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const SettingsInterface* o_ = (const SettingsInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = SettingsInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<SettingsRef>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(SettingsInterface, o_, SettingsInterface_GetParentSettings) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<SettingsInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<SettingsInterface>() : PRIVATE_MAXON_VTABLE(SettingsInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.SettingsInterface_GetParentSettings_Offset), mt_.SettingsInterface_GetParentSettings));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SettingsInterface::Hxx1::ConstFn<S>::GetSettingsCopy(const HashSet<Id>& optionalList, ACCESSLEVEL accessLevel) const -> Result<DataDictionary>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<DataDictionary>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const SettingsInterface* o_ = (const SettingsInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = SettingsInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(SettingsInterface, o_, SettingsInterface_GetSettingsCopy) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<SettingsInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<SettingsInterface>() : PRIVATE_MAXON_VTABLE(SettingsInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.SettingsInterface_GetSettingsCopy_Offset), mt_.SettingsInterface_GetSettingsCopy, optionalList, accessLevel));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SettingsInterface::Hxx1::ConstFn<S>::GetSettings(ACCESSLEVEL accessLevel) -> SettingsRef
{
	return (Hxx2::StaticMTable::_instance.SettingsInterface_GetSettings(accessLevel));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SettingsInterface::Hxx1::ConstFn<S>::ObservableSettingsChanged() -> maxon::ObservableRef<ObservableSettingsChangedDelegate>
{
	return (Hxx2::StaticMTable::_instance.SettingsInterface_ObservableSettingsChanged());
}
auto SettingsInterface::GetPtr() -> Ptr { return Ptr(this); }
auto SettingsInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_settingsinterface)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_SettingsInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_SettingsInterface() { new (s_ui_maxon_SettingsInterface) maxon::EntityUse(SettingsInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/settingsinterface.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_SettingsInterface(SettingsInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/settingsinterface.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_settingsinterface)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_usi_maxon_SettingsInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_usi_maxon_SettingsInterface() { new (s_usi_maxon_SettingsInterface) maxon::EntityUse(SettingsInterface::_staticInterface.GetReference(), &maxon::g_translationUnit, "maxon/settingsinterface.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_usi_maxon_SettingsInterface(SettingsInterface::_staticInterface.GetReference(), &maxon::g_translationUnit, "maxon/settingsinterface.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

