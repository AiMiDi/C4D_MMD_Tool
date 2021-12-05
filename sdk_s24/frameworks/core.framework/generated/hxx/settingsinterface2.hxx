
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
	ACCESSLEVEL (*_SettingsInterface_GetAccessLevel) (const maxon::GenericComponent* this_);
	maxon::Int _SettingsInterface_GetAccessLevel_Offset;
	SettingsRef (*_SettingsInterface_GetParentSettings) (const maxon::GenericComponent* this_);
	maxon::Int _SettingsInterface_GetParentSettings_Offset;
	Result<DataDictionary> (*_SettingsInterface_GetSettingsCopy) (const maxon::GenericComponent* this_, const HashSet<Id>& optionalList, ACCESSLEVEL accessLevel);
	maxon::Int _SettingsInterface_GetSettingsCopy_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, SettingsInterface, GetAccessLevel))
	{
		auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, SettingsInterface, GetAccessLevel), W, MTable>::type::_SettingsInterface_GetAccessLevel;
		_SettingsInterface_GetAccessLevel = reinterpret_cast<const decltype(_SettingsInterface_GetAccessLevel)&>(ptr);
		_SettingsInterface_GetAccessLevel_Offset = offset;
	}
	if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, SettingsInterface, GetParentSettings))
	{
		auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, SettingsInterface, GetParentSettings), W, MTable>::type::_SettingsInterface_GetParentSettings;
		_SettingsInterface_GetParentSettings = reinterpret_cast<const decltype(_SettingsInterface_GetParentSettings)&>(ptr);
		_SettingsInterface_GetParentSettings_Offset = offset;
	}
	if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, SettingsInterface, GetSettingsCopy))
	{
		auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, SettingsInterface, GetSettingsCopy), W, MTable>::type::_SettingsInterface_GetSettingsCopy;
		_SettingsInterface_GetSettingsCopy = reinterpret_cast<const decltype(_SettingsInterface_GetSettingsCopy)&>(ptr);
		_SettingsInterface_GetSettingsCopy_Offset = offset;
	}
	}
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset)
	{
		if (!W::Implementation::PROXY && (!DataDictionaryObjectInterface::MTable::template InitWithBases<W>(info, offset))) return false;
		MTable* vt = (MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, _interface); if (!vt) return false;
		vt->Init<W>(offset);
		return true;
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
	SettingsRef (*_SettingsInterface_GetSettings) (ACCESSLEVEL accessLevel);
	maxon::ObservableRef<ObservableSettingsChangedDelegate> (*_SettingsInterface_ObservableSettingsChanged) ();
		StaticMTable() = default;
		template <typename IMPL> static void Init(StaticMTable* tbl)
		{
		tbl->_SettingsInterface_GetSettings = &IMPL::_SettingsInterface_GetSettings;
		tbl->_SettingsInterface_ObservableSettingsChanged = &IMPL::_SettingsInterface_ObservableSettingsChanged;
		}
	};
	template <typename S> class CWrapper : public DataDictionaryObjectInterface::Hxx2::template CWrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetAccessLevel);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetParentSettings);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetSettingsCopy);
		static ACCESSLEVEL _SettingsInterface_GetAccessLevel(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetAccessLevel(); }
		static SettingsRef _SettingsInterface_GetParentSettings(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetParentSettings(); }
		static Result<DataDictionary> _SettingsInterface_GetSettingsCopy(const maxon::GenericComponent* this_, const HashSet<Id>& optionalList, ACCESSLEVEL accessLevel) { return ((const typename S::Implementation*) this_)->GetSettingsCopy(optionalList, accessLevel); }
		static SettingsRef _SettingsInterface_GetSettings(ACCESSLEVEL accessLevel) { return S::Implementation::GetSettings(accessLevel); }
		static maxon::ObservableRef<ObservableSettingsChangedDelegate> _SettingsInterface_ObservableSettingsChanged() { return S::Implementation::ObservableSettingsChanged(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto SettingsInterface::GetAccessLevel() const -> ACCESSLEVEL
{
	const SettingsInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(SettingsInterface, this); return mt_._SettingsInterface_GetAccessLevel((const maxon::GenericComponent*) this + mt_._SettingsInterface_GetAccessLevel_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SettingsInterface::GetParentSettings() const -> SettingsRef
{
	const SettingsInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(SettingsInterface, this); return mt_._SettingsInterface_GetParentSettings((const maxon::GenericComponent*) this + mt_._SettingsInterface_GetParentSettings_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SettingsInterface::GetSettingsCopy(const HashSet<Id>& optionalList, ACCESSLEVEL accessLevel) const -> Result<DataDictionary>
{
	const SettingsInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(SettingsInterface, this); return mt_._SettingsInterface_GetSettingsCopy((const maxon::GenericComponent*) this + mt_._SettingsInterface_GetSettingsCopy_Offset, optionalList, accessLevel);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SettingsInterface::GetSettings(ACCESSLEVEL accessLevel) -> SettingsRef
{
	return Hxx2::StaticMTable::_instance._SettingsInterface_GetSettings(accessLevel);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SettingsInterface::ObservableSettingsChanged() -> maxon::ObservableRef<ObservableSettingsChangedDelegate>
{
	return Hxx2::StaticMTable::_instance._SettingsInterface_ObservableSettingsChanged();
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SettingsInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetAccessLevel() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<ACCESSLEVEL>, ACCESSLEVEL>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<ACCESSLEVEL>, ACCESSLEVEL>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const SettingsInterface* o_ = (const SettingsInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = SettingsInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<ACCESSLEVEL>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(SettingsInterface, o_, SettingsInterface_GetAccessLevel) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<SettingsInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<SettingsInterface>() : PRIVATE_MAXON_VTABLE(SettingsInterface, o_); 
	return (mt_._SettingsInterface_GetAccessLevel(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._SettingsInterface_GetAccessLevel_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SettingsInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetParentSettings() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<SettingsRef>, SettingsRef>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<SettingsRef>, SettingsRef>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const SettingsInterface* o_ = (const SettingsInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = SettingsInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<SettingsRef>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(SettingsInterface, o_, SettingsInterface_GetParentSettings) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<SettingsInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<SettingsInterface>() : PRIVATE_MAXON_VTABLE(SettingsInterface, o_); 
	return (mt_._SettingsInterface_GetParentSettings(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._SettingsInterface_GetParentSettings_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SettingsInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetSettingsCopy(const HashSet<Id>& optionalList, ACCESSLEVEL accessLevel) const -> Result<DataDictionary>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<DataDictionary>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const SettingsInterface* o_ = (const SettingsInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = SettingsInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(SettingsInterface, o_, SettingsInterface_GetSettingsCopy) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<SettingsInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<SettingsInterface>() : PRIVATE_MAXON_VTABLE(SettingsInterface, o_); 
	return (mt_._SettingsInterface_GetSettingsCopy(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._SettingsInterface_GetSettingsCopy_Offset, optionalList, accessLevel));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SettingsInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetSettings(ACCESSLEVEL accessLevel) -> SettingsRef { return (Hxx2::StaticMTable::_instance._SettingsInterface_GetSettings(accessLevel)); }
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SettingsInterface::Hxx1::ConstReferenceFunctionsImpl<S>::ObservableSettingsChanged() -> maxon::ObservableRef<ObservableSettingsChangedDelegate> { return (Hxx2::StaticMTable::_instance._SettingsInterface_ObservableSettingsChanged()); }
auto SettingsInterface::GetPtr() -> Ptr { return Ptr(this); }
auto SettingsInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_SettingsInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_SettingsInterface() { new (s_ui_maxon_SettingsInterface) maxon::EntityUse(SettingsInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/settingsinterface.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_SettingsInterface(SettingsInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/settingsinterface.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
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

