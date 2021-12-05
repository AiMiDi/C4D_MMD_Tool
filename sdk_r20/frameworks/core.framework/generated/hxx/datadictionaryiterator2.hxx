
#ifndef DOXYGEN

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#pragma GCC diagnostic ignored "-Wmisleading-indentation"
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
	template <typename IMPL> static void Init(MTable* tbl)
	{
		tbl->_DataDictionaryIteratorInterface_Destruct = &IMPL::_DataDictionaryIteratorInterface_Destruct;
		tbl->_DataDictionaryIteratorInterface_MoveConstruct = &IMPL::_DataDictionaryIteratorInterface_MoveConstruct;
		tbl->_DataDictionaryIteratorInterface_HasValue = &IMPL::_DataDictionaryIteratorInterface_HasValue;
		tbl->_DataDictionaryIteratorInterface_IsEqual = &IMPL::_DataDictionaryIteratorInterface_IsEqual;
		tbl->_DataDictionaryIteratorInterface_MoveToNext = &IMPL::_DataDictionaryIteratorInterface_MoveToNext;
		tbl->_DataDictionaryIteratorInterface_GetKeyAndData = &IMPL::_DataDictionaryIteratorInterface_GetKeyAndData;
	}
};

template <typename C> class DataDictionaryIteratorInterface::Wrapper
{
public:
	static void _DataDictionaryIteratorInterface_Destruct(DataDictionaryIteratorInterface* this_) { return ((C*) this_)->Destruct(); }
	static void _DataDictionaryIteratorInterface_MoveConstruct(DataDictionaryIteratorInterface* this_, DataDictionaryIteratorInterface* src) { return ((C*) this_)->MoveConstruct(src); }
	static Bool _DataDictionaryIteratorInterface_HasValue(const DataDictionaryIteratorInterface* this_) { return ((const C*) this_)->HasValue(); }
	static Bool _DataDictionaryIteratorInterface_IsEqual(const DataDictionaryIteratorInterface* this_, const DataDictionaryIteratorInterface* other) { return ((const C*) this_)->IsEqual(other); }
	static void _DataDictionaryIteratorInterface_MoveToNext(DataDictionaryIteratorInterface* this_) { return ((C*) this_)->MoveToNext(); }
	static void _DataDictionaryIteratorInterface_GetKeyAndData(const DataDictionaryIteratorInterface* this_, Tuple<const Data&, const Data&>& res) { return ((const C*) this_)->GetKeyAndData(res); }
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
static maxon::EntityUse s_ui_maxon_DataDictionaryIteratorInterface(DataDictionaryIteratorInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/datadictionaryiterator.h", false);
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

