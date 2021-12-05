#if 1
namespace maxon
{
	const maxon::Char* const DataDictionaryIteratorInterface::MTable::_ids = 
		"Destruct@6b2e10f\0" // void Destruct()
		"MoveConstruct@f8042f43579d8a4e\0" // void MoveConstruct(DataDictionaryIteratorInterface* src)
		"HasValue@76f01901\0" // Bool HasValue() const
		"IsEqual@75255716f50c70e5\0" // Bool IsEqual(const DataDictionaryIteratorInterface* other) const
		"MoveToNext@6b2e10f\0" // void MoveToNext()
		"GetKeyAndData@679e6b0b1514c463\0" // void GetKeyAndData(Tuple<const Data&, const Data&>& res) const
	"";
	MAXON_WARNING_PUSH
	MAXON_WARNING_DISABLE_DEPRECATED
	class DataDictionaryIteratorInterface::Hxx2::Unresolved : public DataDictionaryIteratorInterface
	{
	public:
		static const Unresolved* Get(const DataDictionaryIteratorInterface* o) { return (const Unresolved*) o; }
		static Unresolved* Get(DataDictionaryIteratorInterface* o) { return (Unresolved*) o; }
		void Destruct() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((DataDictionaryIteratorInterface*) this)->Destruct(); return maxon::PrivateLogNullptrError();}
		void MoveConstruct(DataDictionaryIteratorInterface* src) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((DataDictionaryIteratorInterface*) this)->MoveConstruct(src); return maxon::PrivateLogNullptrError();}
		Bool HasValue() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const DataDictionaryIteratorInterface*) this)->HasValue(); return maxon::PrivateLogNullptrError(false);}
		Bool IsEqual(const DataDictionaryIteratorInterface* other) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const DataDictionaryIteratorInterface*) this)->IsEqual(other); return maxon::PrivateLogNullptrError(false);}
		void MoveToNext() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((DataDictionaryIteratorInterface*) this)->MoveToNext(); return maxon::PrivateLogNullptrError();}
		void GetKeyAndData(Tuple<const Data&, const Data&>& res) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const DataDictionaryIteratorInterface*) this)->GetKeyAndData(res); return maxon::PrivateLogNullptrError();}
	};
	MAXON_WARNING_POP
#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
	const maxon::NULL_RETURN_TYPE DataDictionaryIteratorInterface::MTable::_returnTypes[] = 
	{
		maxon::details::NullReturnType<void>::value,
		maxon::details::NullReturnType<void>::value,
		maxon::details::NullReturnType<Bool>::value,
		maxon::details::NullReturnType<Bool>::value,
		maxon::details::NullReturnType<void>::value,
		maxon::details::NullReturnType<void>::value,
		maxon::NULL_RETURN_TYPE::OTHER
	};
#endif
	maxon::Bool DataDictionaryIteratorInterface::MTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl)
	{
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_DataDictionaryIteratorInterface_Destruct = &Hxx2::Wrapper<Hxx2::Unresolved>::_DataDictionaryIteratorInterface_Destruct;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_DataDictionaryIteratorInterface_MoveConstruct = &Hxx2::Wrapper<Hxx2::Unresolved>::_DataDictionaryIteratorInterface_MoveConstruct;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_DataDictionaryIteratorInterface_HasValue = &Hxx2::Wrapper<Hxx2::Unresolved>::_DataDictionaryIteratorInterface_HasValue;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_DataDictionaryIteratorInterface_IsEqual = &Hxx2::Wrapper<Hxx2::Unresolved>::_DataDictionaryIteratorInterface_IsEqual;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_DataDictionaryIteratorInterface_MoveToNext = &Hxx2::Wrapper<Hxx2::Unresolved>::_DataDictionaryIteratorInterface_MoveToNext;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_DataDictionaryIteratorInterface_GetKeyAndData = &Hxx2::Wrapper<Hxx2::Unresolved>::_DataDictionaryIteratorInterface_GetKeyAndData;
		#endif
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_interface, (maxon::Char*) tbl, _returnTypes, SIZEOF(MTable) / SIZEOF(void*));
	#else
		return true;
	#endif
	}
	MAXON_INTERFACE_REGISTER(DataDictionaryIteratorInterface, "net.maxon.interface.datadictionaryiterator", nullptr);
}
#endif
