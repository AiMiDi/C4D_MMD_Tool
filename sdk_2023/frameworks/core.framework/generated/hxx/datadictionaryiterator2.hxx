
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1
constexpr const maxon::Char* DataDictionaryIteratorInterface::PrivateGetCppName() { return nullptr; }

struct DataDictionaryIteratorInterface::MTable
{
	static MTable _instance;
	static MTable _unresolvedInstance;
	static const maxon::Char* const _ids;
	static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl);
	static const maxon::NULL_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = true;
	PRIVATE_MAXON_MF_POINTER(DataDictionaryIteratorInterface_Destruct, Destruct, false, DataDictionaryIteratorInterface,, (void));
	PRIVATE_MAXON_MF_POINTER(DataDictionaryIteratorInterface_MoveConstruct, MoveConstruct, false, DataDictionaryIteratorInterface,, (void), DataDictionaryIteratorInterface* src);
	PRIVATE_MAXON_MF_POINTER(DataDictionaryIteratorInterface_HasValue, HasValue, false, DataDictionaryIteratorInterface, const, (Bool));
	PRIVATE_MAXON_MF_POINTER(DataDictionaryIteratorInterface_IsEqual, IsEqual, false, DataDictionaryIteratorInterface, const, (Bool), const DataDictionaryIteratorInterface* other);
	PRIVATE_MAXON_MF_POINTER(DataDictionaryIteratorInterface_MoveToNext, MoveToNext, false, DataDictionaryIteratorInterface,, (void));
	PRIVATE_MAXON_MF_POINTER(DataDictionaryIteratorInterface_GetKeyAndData, GetKeyAndData, false, DataDictionaryIteratorInterface, const, (void), Tuple<const Data&, const Data&>& res);
	template <typename IMPL> void Init()
	{
		DataDictionaryIteratorInterface_Destruct = DataDictionaryIteratorInterface_Destruct_GetPtr<IMPL>(0, true).first;
		DataDictionaryIteratorInterface_MoveConstruct = DataDictionaryIteratorInterface_MoveConstruct_GetPtr<IMPL>(0, true).first;
		DataDictionaryIteratorInterface_HasValue = DataDictionaryIteratorInterface_HasValue_GetPtr<IMPL>(0, true).first;
		DataDictionaryIteratorInterface_IsEqual = DataDictionaryIteratorInterface_IsEqual_GetPtr<IMPL>(0, true).first;
		DataDictionaryIteratorInterface_MoveToNext = DataDictionaryIteratorInterface_MoveToNext_GetPtr<IMPL>(0, true).first;
		DataDictionaryIteratorInterface_GetKeyAndData = DataDictionaryIteratorInterface_GetKeyAndData_GetPtr<IMPL>(0, true).first;
	}
};

struct DataDictionaryIteratorInterface::Hxx2
{
	class Unresolved;
	template <typename C> class Wrapper
	{
	public:
		using Implementation = C;
		PRIVATE_MAXON_MF_WRAPPER(DataDictionaryIteratorInterface_Destruct, DataDictionaryIteratorInterface,, (void)) { return C::Get(PRIVATE_MAXON_MF_THIS(DataDictionaryIteratorInterface))->Destruct(); }
		PRIVATE_MAXON_MF_WRAPPER(DataDictionaryIteratorInterface_MoveConstruct, DataDictionaryIteratorInterface,, (void), DataDictionaryIteratorInterface* src) { return C::Get(PRIVATE_MAXON_MF_THIS(DataDictionaryIteratorInterface))->MoveConstruct(src); }
		PRIVATE_MAXON_MF_WRAPPER(DataDictionaryIteratorInterface_HasValue, DataDictionaryIteratorInterface, const, (Bool)) { return C::Get(PRIVATE_MAXON_MF_THIS(const DataDictionaryIteratorInterface))->HasValue(); }
		PRIVATE_MAXON_MF_WRAPPER(DataDictionaryIteratorInterface_IsEqual, DataDictionaryIteratorInterface, const, (Bool), const DataDictionaryIteratorInterface* other) { return C::Get(PRIVATE_MAXON_MF_THIS(const DataDictionaryIteratorInterface))->IsEqual(other); }
		PRIVATE_MAXON_MF_WRAPPER(DataDictionaryIteratorInterface_MoveToNext, DataDictionaryIteratorInterface,, (void)) { return C::Get(PRIVATE_MAXON_MF_THIS(DataDictionaryIteratorInterface))->MoveToNext(); }
		PRIVATE_MAXON_MF_WRAPPER(DataDictionaryIteratorInterface_GetKeyAndData, DataDictionaryIteratorInterface, const, (void), Tuple<const Data&, const Data&>& res) { return C::Get(PRIVATE_MAXON_MF_THIS(const DataDictionaryIteratorInterface))->GetKeyAndData(res); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryIteratorInterface::Destruct() -> void
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.DataDictionaryIteratorInterface_Destruct);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryIteratorInterface::MoveConstruct(DataDictionaryIteratorInterface* src) -> void
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.DataDictionaryIteratorInterface_MoveConstruct, src);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryIteratorInterface::HasValue() const -> Bool
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.DataDictionaryIteratorInterface_HasValue);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryIteratorInterface::IsEqual(const DataDictionaryIteratorInterface* other) const -> Bool
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.DataDictionaryIteratorInterface_IsEqual, other);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryIteratorInterface::MoveToNext() -> void
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.DataDictionaryIteratorInterface_MoveToNext);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryIteratorInterface::GetKeyAndData(Tuple<const Data&, const Data&>& res) const -> void
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.DataDictionaryIteratorInterface_GetKeyAndData, res);
}

#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_datadictionaryiterator)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_DataDictionaryIteratorInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_DataDictionaryIteratorInterface() { new (s_ui_maxon_DataDictionaryIteratorInterface) maxon::EntityUse(DataDictionaryIteratorInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/datadictionaryiterator.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_DataDictionaryIteratorInterface(DataDictionaryIteratorInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/datadictionaryiterator.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

