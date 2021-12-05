
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1

struct DataDictionaryIteratorInterface::MTable
{
	static MTable _instance;
	static MTable _unresolvedInstance;
	static const maxon::Char* const _ids;
	static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl);
	static const maxon::NULL_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = true;
	void (*_DataDictionaryIteratorInterface_Destruct) (DataDictionaryIteratorInterface* this_);
	void (*_DataDictionaryIteratorInterface_MoveConstruct) (DataDictionaryIteratorInterface* this_, DataDictionaryIteratorInterface* src);
	Bool (*_DataDictionaryIteratorInterface_HasValue) (const DataDictionaryIteratorInterface* this_);
	Bool (*_DataDictionaryIteratorInterface_IsEqual) (const DataDictionaryIteratorInterface* this_, const DataDictionaryIteratorInterface* other);
	void (*_DataDictionaryIteratorInterface_MoveToNext) (DataDictionaryIteratorInterface* this_);
	void (*_DataDictionaryIteratorInterface_GetKeyAndData) (const DataDictionaryIteratorInterface* this_, Tuple<const Data&, const Data&>& res);
	template <typename IMPL> void Init()
	{
		_DataDictionaryIteratorInterface_Destruct = &IMPL::_DataDictionaryIteratorInterface_Destruct;
		_DataDictionaryIteratorInterface_MoveConstruct = &IMPL::_DataDictionaryIteratorInterface_MoveConstruct;
		_DataDictionaryIteratorInterface_HasValue = &IMPL::_DataDictionaryIteratorInterface_HasValue;
		_DataDictionaryIteratorInterface_IsEqual = &IMPL::_DataDictionaryIteratorInterface_IsEqual;
		_DataDictionaryIteratorInterface_MoveToNext = &IMPL::_DataDictionaryIteratorInterface_MoveToNext;
		_DataDictionaryIteratorInterface_GetKeyAndData = &IMPL::_DataDictionaryIteratorInterface_GetKeyAndData;
	}
};

struct DataDictionaryIteratorInterface::Hxx2
{
	class Unresolved;
	template <typename C> class Wrapper
	{
	public:
	static void _DataDictionaryIteratorInterface_Destruct(DataDictionaryIteratorInterface* this_) { return ((C*) this_)->Destruct(); }
	static void _DataDictionaryIteratorInterface_MoveConstruct(DataDictionaryIteratorInterface* this_, DataDictionaryIteratorInterface* src) { return ((C*) this_)->MoveConstruct(src); }
	static Bool _DataDictionaryIteratorInterface_HasValue(const DataDictionaryIteratorInterface* this_) { return ((const C*) this_)->HasValue(); }
	static Bool _DataDictionaryIteratorInterface_IsEqual(const DataDictionaryIteratorInterface* this_, const DataDictionaryIteratorInterface* other) { return ((const C*) this_)->IsEqual(other); }
	static void _DataDictionaryIteratorInterface_MoveToNext(DataDictionaryIteratorInterface* this_) { return ((C*) this_)->MoveToNext(); }
	static void _DataDictionaryIteratorInterface_GetKeyAndData(const DataDictionaryIteratorInterface* this_, Tuple<const Data&, const Data&>& res) { return ((const C*) this_)->GetKeyAndData(res); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryIteratorInterface::Destruct() -> void
{
	return MTable::_instance._DataDictionaryIteratorInterface_Destruct(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryIteratorInterface::MoveConstruct(DataDictionaryIteratorInterface* src) -> void
{
	return MTable::_instance._DataDictionaryIteratorInterface_MoveConstruct(this, src);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryIteratorInterface::HasValue() const -> Bool
{
	return MTable::_instance._DataDictionaryIteratorInterface_HasValue(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryIteratorInterface::IsEqual(const DataDictionaryIteratorInterface* other) const -> Bool
{
	return MTable::_instance._DataDictionaryIteratorInterface_IsEqual(this, other);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryIteratorInterface::MoveToNext() -> void
{
	return MTable::_instance._DataDictionaryIteratorInterface_MoveToNext(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryIteratorInterface::GetKeyAndData(Tuple<const Data&, const Data&>& res) const -> void
{
	return MTable::_instance._DataDictionaryIteratorInterface_GetKeyAndData(this, res);
}

#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
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

