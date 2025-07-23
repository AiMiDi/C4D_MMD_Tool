#if 1
namespace maxon
{
	const maxon::Char* const DataDictionaryIteratorInterface::MTable::_ids = 
		"Destruct@780cdac8f1a33934\0" // void Destruct()
		"MoveConstruct@5dcd2b91f0772e71\0" // void MoveConstruct(DataDictionaryIteratorInterface* src)
		"HasValue@12e73654e6d65520\0" // Bool HasValue() const
		"IsEqual@689446c9ef8bbf60\0" // Bool IsEqual(const DataDictionaryIteratorInterface* other) const
		"MoveToNext@780cdac8f1a33934\0" // void MoveToNext()
		"GetKeyAndData@c89d1302a94bf426\0" // void GetKeyAndData(Tuple<const Data&, const Data&>& res) const
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
	const maxon::UNRESOLVED_RETURN_TYPE DataDictionaryIteratorInterface::MTable::_returnTypes[] = 
	{
		maxon::details::UnresolvedReturnType<void>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<void>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<Bool>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<Bool>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<void>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<void>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::UNRESOLVED_RETURN_TYPE::OTHER
	};
#endif
	maxon::Bool DataDictionaryIteratorInterface::MTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl)
	{
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->DataDictionaryIteratorInterface_Destruct = PRIVATE_MAXON_MF_CAST(decltype(DataDictionaryIteratorInterface_Destruct), &Hxx2::Wrapper<Hxx2::Unresolved>::DataDictionaryIteratorInterface_Destruct);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->DataDictionaryIteratorInterface_MoveConstruct = PRIVATE_MAXON_MF_CAST(decltype(DataDictionaryIteratorInterface_MoveConstruct), &Hxx2::Wrapper<Hxx2::Unresolved>::DataDictionaryIteratorInterface_MoveConstruct);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->DataDictionaryIteratorInterface_HasValue = PRIVATE_MAXON_MF_CAST(decltype(DataDictionaryIteratorInterface_HasValue), &Hxx2::Wrapper<Hxx2::Unresolved>::DataDictionaryIteratorInterface_HasValue);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->DataDictionaryIteratorInterface_IsEqual = PRIVATE_MAXON_MF_CAST(decltype(DataDictionaryIteratorInterface_IsEqual), &Hxx2::Wrapper<Hxx2::Unresolved>::DataDictionaryIteratorInterface_IsEqual);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->DataDictionaryIteratorInterface_MoveToNext = PRIVATE_MAXON_MF_CAST(decltype(DataDictionaryIteratorInterface_MoveToNext), &Hxx2::Wrapper<Hxx2::Unresolved>::DataDictionaryIteratorInterface_MoveToNext);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->DataDictionaryIteratorInterface_GetKeyAndData = PRIVATE_MAXON_MF_CAST(decltype(DataDictionaryIteratorInterface_GetKeyAndData), &Hxx2::Wrapper<Hxx2::Unresolved>::DataDictionaryIteratorInterface_GetKeyAndData);
		#endif
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_interface, (const void**) tbl, _returnTypes, SIZEOF(MTable) / SIZEOF(void*));
	#else
		return true;
	#endif
	}
	MAXON_INTERFACE_REGISTER(DataDictionaryIteratorInterface, "net.maxon.interface.datadictionaryiterator", nullptr, maxon::EntityBase::FLAGS::NONE);
}
#endif
