#if 1
namespace maxon
{
	const maxon::Char* const UuidInterface::MTable::_ids = 
		"Free@62bdce627b0a9d6e\0" // void Free(const UuidInterface* object)
		"Alloc@d7b47574339c8827\0" // UuidInterface* Alloc(const maxon::SourceLocation& allocLocation)
		"Alloc@13d0493b3524a408\0" // UuidInterface* Alloc(const maxon::SourceLocation& allocLocation, const UuidInterface& object)
		"Alloc@207c095f1c7399ad\0" // UuidInterface* Alloc(const maxon::SourceLocation& allocLocation, const String& uuid)
		"Alloc@59f5edd92e99936a\0" // UuidInterface* Alloc(const maxon::SourceLocation& allocLocation, const UChar* uuid, Int uuidSize)
		"IsEmpty@12e73654e6d65520\0" // Bool IsEmpty() const
		"CreateId@3008090429c5a175\0" // Result<void> CreateId()
		"Set@d85d74e087a2f051\0" // Result<void> Set(const String& uuid)
		"Set@a95ff2b66d42d90e\0" // Result<void> Set(const UChar* uuid, Int uuidSize)
		"Get@240d84b581a0344b\0" // Result<void> Get(UChar* uuid, Int uuidSize) const
		"ToString@a73a45c584c879d4\0" // String ToString(const FormatStatement* formatStatement) const
		"Compare@957d2b088df502c3\0" // COMPARERESULT Compare(const UuidInterface* uuid) const
		"GetHashCode@b22918402154097b\0" // HashInt GetHashCode() const
		"DescribeIO@fe3f1bd5a495cc32\0" // Result<void> DescribeIO(const DataSerializeInterface& stream)
		"CreateUuidString@74a82a5719c5c3bb\0" // Result<String> CreateUuidString()
	"";
	MAXON_WARNING_PUSH
	MAXON_WARNING_DISABLE_DEPRECATED
	class UuidInterface::Hxx2::Unresolved : public UuidInterface
	{
	public:
		static const Unresolved* Get(const UuidInterface* o) { return (const Unresolved*) o; }
		static Unresolved* Get(UuidInterface* o) { return (Unresolved*) o; }
		static void Free(const UuidInterface* object) { if (object && maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return UuidInterface::Free(object); return maxon::PrivateLogNullptrError();}
		static UuidInterface* Alloc(const maxon::SourceLocation& allocLocation) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return UuidInterface::Alloc(allocLocation); return nullptr;}
		static UuidInterface* Alloc(const maxon::SourceLocation& allocLocation, const UuidInterface& object) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return UuidInterface::Alloc(allocLocation, object); return nullptr;}
		static UuidInterface* Alloc(const maxon::SourceLocation& allocLocation, const String& uuid) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return UuidInterface::Alloc(allocLocation, uuid); return nullptr;}
		static UuidInterface* Alloc(const maxon::SourceLocation& allocLocation, const UChar* uuid, Int uuidSize) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return UuidInterface::Alloc(allocLocation, uuid, uuidSize); return nullptr;}
		Bool IsEmpty() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const UuidInterface*) this)->IsEmpty(); return maxon::PrivateLogNullptrError(false);}
		Result<void> CreateId() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((UuidInterface*) this)->CreateId(); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<void> Set(const String& uuid) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((UuidInterface*) this)->Set(uuid); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<void> Set(const UChar* uuid, Int uuidSize) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((UuidInterface*) this)->Set(uuid, uuidSize); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<void> Get(UChar* uuid, Int uuidSize) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((const UuidInterface*) this)->Get(uuid, uuidSize); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		String ToString(const FormatStatement* formatStatement) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const UuidInterface*) this)->ToString(formatStatement); return maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		COMPARERESULT Compare(const UuidInterface* uuid) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const UuidInterface*) this)->Compare(uuid); return maxon::PrivateIncompleteNullReturnValue<COMPARERESULT>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		HashInt GetHashCode() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const UuidInterface*) this)->GetHashCode(); return maxon::PrivateIncompleteNullReturnValue<HashInt>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		static Result<void> DescribeIO(const DataSerializeInterface& stream) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return UuidInterface::DescribeIO(stream); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static Result<String> CreateUuidString() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return UuidInterface::CreateUuidString(); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
	};
	MAXON_WARNING_POP
#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
	const maxon::NULL_RETURN_TYPE UuidInterface::MTable::_returnTypes[] = 
	{
		maxon::NULL_RETURN_TYPE::VOID_ZERO_FREE_FUNCTION,
		maxon::details::NullReturnType<UuidInterface*>::value,
		maxon::details::NullReturnType<UuidInterface*>::value,
		maxon::details::NullReturnType<UuidInterface*>::value,
		maxon::details::NullReturnType<UuidInterface*>::value,
		maxon::details::NullReturnType<Bool>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<String>::value,
		maxon::details::NullReturnType<COMPARERESULT>::value,
		maxon::details::NullReturnType<HashInt>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<String>>::value,
		maxon::NULL_RETURN_TYPE::OTHER
	};
#endif
	maxon::Bool UuidInterface::MTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl)
	{
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_UuidInterface_Free = &Hxx2::Wrapper<Hxx2::Unresolved>::_UuidInterface_Free;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_UuidInterface_Alloc = &Hxx2::Wrapper<Hxx2::Unresolved>::_UuidInterface_Alloc;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_UuidInterface_Alloc_1 = &Hxx2::Wrapper<Hxx2::Unresolved>::_UuidInterface_Alloc_1;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_UuidInterface_Alloc_2 = &Hxx2::Wrapper<Hxx2::Unresolved>::_UuidInterface_Alloc_2;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_UuidInterface_Alloc_3 = &Hxx2::Wrapper<Hxx2::Unresolved>::_UuidInterface_Alloc_3;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_UuidInterface_IsEmpty = &Hxx2::Wrapper<Hxx2::Unresolved>::_UuidInterface_IsEmpty;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_UuidInterface_CreateId = &Hxx2::Wrapper<Hxx2::Unresolved>::_UuidInterface_CreateId;
		#else
		tbl->_UuidInterface_CreateId = &Hxx2::Wrapper<Hxx2::Unresolved>::_UuidInterface_CreateId;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_UuidInterface_Set = &Hxx2::Wrapper<Hxx2::Unresolved>::_UuidInterface_Set;
		#else
		tbl->_UuidInterface_Set = &Hxx2::Wrapper<Hxx2::Unresolved>::_UuidInterface_Set;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_UuidInterface_Set_1 = &Hxx2::Wrapper<Hxx2::Unresolved>::_UuidInterface_Set_1;
		#else
		tbl->_UuidInterface_Set_1 = &Hxx2::Wrapper<Hxx2::Unresolved>::_UuidInterface_Set_1;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_UuidInterface_Get = &Hxx2::Wrapper<Hxx2::Unresolved>::_UuidInterface_Get;
		#else
		tbl->_UuidInterface_Get = &Hxx2::Wrapper<Hxx2::Unresolved>::_UuidInterface_Get;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<String>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_UuidInterface_ToString = &Hxx2::Wrapper<Hxx2::Unresolved>::_UuidInterface_ToString;
		#else
		tbl->_UuidInterface_ToString = &Hxx2::Wrapper<Hxx2::Unresolved>::_UuidInterface_ToString;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<COMPARERESULT>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_UuidInterface_Compare = &Hxx2::Wrapper<Hxx2::Unresolved>::_UuidInterface_Compare;
		#else
		tbl->_UuidInterface_Compare = &Hxx2::Wrapper<Hxx2::Unresolved>::_UuidInterface_Compare;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<HashInt>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_UuidInterface_GetHashCode = &Hxx2::Wrapper<Hxx2::Unresolved>::_UuidInterface_GetHashCode;
		#else
		tbl->_UuidInterface_GetHashCode = &Hxx2::Wrapper<Hxx2::Unresolved>::_UuidInterface_GetHashCode;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_UuidInterface_DescribeIO = &Hxx2::Wrapper<Hxx2::Unresolved>::_UuidInterface_DescribeIO;
		#else
		tbl->_UuidInterface_DescribeIO = &Hxx2::Wrapper<Hxx2::Unresolved>::_UuidInterface_DescribeIO;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<String>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_UuidInterface_CreateUuidString = &Hxx2::Wrapper<Hxx2::Unresolved>::_UuidInterface_CreateUuidString;
		#else
		tbl->_UuidInterface_CreateUuidString = &Hxx2::Wrapper<Hxx2::Unresolved>::_UuidInterface_CreateUuidString;
		#endif
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_interface, (maxon::Char*) tbl, _returnTypes, SIZEOF(MTable) / SIZEOF(void*));
	#else
		return true;
	#endif
	}
	MAXON_INTERFACE_REGISTER(UuidInterface, "net.maxon.interface.uuid", nullptr);
	template <typename DUMMY> maxon::Int UuidInterface::PrivateInstantiateNullValueHelper()
	{
		return 0
		| maxon::details::InstantiateNullReturnValue<COMPARERESULT>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateNullReturnValue<HashInt>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateNullReturnValue<String>(OVERLOAD_MAX_RANK)
		;
	}
#if (defined MAXON_TARGET_WINDOWS) && (defined MAXON_TARGET_DEBUG)
#endif
}
#endif
static maxon::details::ForceEvaluation s_forceEval_uuid(0
	| maxon::UuidInterface::PrivateInstantiateNullValueHelper<maxon::Int>()
);
