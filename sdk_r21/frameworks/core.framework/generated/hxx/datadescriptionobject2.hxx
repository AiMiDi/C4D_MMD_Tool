
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1

struct DataDescriptionObjectInterface::MTable
{
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetObjectDescription);
	static const maxon::Char* const _ids;
	static const maxon::Bool HAS_NONSTATIC = false;
	Result<DataDescription> (*_DataDescriptionObjectInterface_GetObjectDescription) (const maxon::GenericComponent* this_, const Id& category, const LanguageRef& language, const DataDictionaryObjectRef& objectData);
	maxon::Int _DataDescriptionObjectInterface_GetObjectDescription_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataDescriptionObjectInterface, GetObjectDescription))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataDescriptionObjectInterface, GetObjectDescription), W, MTable>::type::_DataDescriptionObjectInterface_GetObjectDescription;
			_DataDescriptionObjectInterface_GetObjectDescription = reinterpret_cast<const decltype(_DataDescriptionObjectInterface_GetObjectDescription)&>(ptr);
			_DataDescriptionObjectInterface_GetObjectDescription_Offset = offset;
		}
	}
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset)
	{
		if (!W::Implementation::PROXY && (!ObjectInterface::MTable::template InitWithBases<W>(info, offset))) return false;
		MTable* vt = (MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, _interface); if (!vt) return false;
		vt->Init<W>(offset); return true;
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<DataDescriptionObjectInterface, typename ObjectInterface::MTable::template CombinedMTable<S>>;
	PRIVATE_MAXON_COMPBASE(DataDescriptionObjectInterface);
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct DataDescriptionObjectInterface::Hxx2
{
	class Unresolved;
	struct StaticMTable
	{
		static StaticMTable _instance;
		static StaticMTable _unresolvedInstance;
		static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, StaticMTable* tbl);
		static const maxon::Char* const _ids;
		static const maxon::NULL_RETURN_TYPE _returnTypes[];
	Result<String> (*_DataDescriptionObjectInterface_GetObjectName) (const Id& classId, const LanguageRef& language);
		StaticMTable() = default;
		template <typename IMPL> static void Init(StaticMTable* tbl)
		{
		tbl->_DataDescriptionObjectInterface_GetObjectName = &IMPL::_DataDescriptionObjectInterface_GetObjectName;
		}
	};
	template <typename S> class Wrapper : public ObjectInterface::Hxx2::template Wrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetObjectDescription);
	static Result<DataDescription> _DataDescriptionObjectInterface_GetObjectDescription(const maxon::GenericComponent* this_, const Id& category, const LanguageRef& language, const DataDictionaryObjectRef& objectData) { return ((const typename S::Implementation*) this_)->GetObjectDescription(category, language, objectData); }
	static Result<String> _DataDescriptionObjectInterface_GetObjectName(const Id& classId, const LanguageRef& language) { return S::Implementation::GetObjectName(classId, language); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionObjectInterface::GetObjectDescription(const Id& category, const LanguageRef& language, const DataDictionaryObjectRef& objectData) const -> Result<DataDescription>
{
	const DataDescriptionObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DataDescriptionObjectInterface, this); return mt_._DataDescriptionObjectInterface_GetObjectDescription((const maxon::GenericComponent*) this + mt_._DataDescriptionObjectInterface_GetObjectDescription_Offset, category, language, objectData);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionObjectInterface::GetObjectName(const Id& classId, const LanguageRef& language) -> Result<String>
{
	return Hxx2::StaticMTable::_instance._DataDescriptionObjectInterface_GetObjectName(classId, language);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionObjectInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetObjectDescription(const Id& category, const LanguageRef& language, const DataDictionaryObjectRef& objectData) const -> Result<DataDescription>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<DataDescription>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const DataDescriptionObjectInterface* o_ = (const DataDescriptionObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = DataDescriptionObjectInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataDescriptionObjectInterface, o_, DataDescriptionObjectInterface_GetObjectDescription) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<DataDescriptionObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataDescriptionObjectInterface>() : PRIVATE_MAXON_VTABLE(DataDescriptionObjectInterface, o_); 
	return (mt_._DataDescriptionObjectInterface_GetObjectDescription(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._DataDescriptionObjectInterface_GetObjectDescription_Offset, category, language, objectData));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionObjectInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetObjectName(const Id& classId, const LanguageRef& language) -> Result<String> { return (Hxx2::StaticMTable::_instance._DataDescriptionObjectInterface_GetObjectName(classId, language)); }
auto DataDescriptionObjectInterface::GetPtr() -> Ptr { return Ptr(this); }
auto DataDescriptionObjectInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_DataDescriptionObjectInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_DataDescriptionObjectInterface() { new (s_ui_maxon_DataDescriptionObjectInterface) maxon::EntityUse(DataDescriptionObjectInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/datadescriptionobject.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_DataDescriptionObjectInterface(DataDescriptionObjectInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/datadescriptionobject.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_usi_maxon_DataDescriptionObjectInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_usi_maxon_DataDescriptionObjectInterface() { new (s_usi_maxon_DataDescriptionObjectInterface) maxon::EntityUse(DataDescriptionObjectInterface::_staticInterface.GetReference(), &maxon::g_translationUnit, "maxon/datadescriptionobject.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_usi_maxon_DataDescriptionObjectInterface(DataDescriptionObjectInterface::_staticInterface.GetReference(), &maxon::g_translationUnit, "maxon/datadescriptionobject.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

