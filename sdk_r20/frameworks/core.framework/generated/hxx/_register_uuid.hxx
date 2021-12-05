#if 1
namespace maxon
{
	const maxon::Char* const UuidInterface::MTable::_ids = 
		"Free@6dd8c6c060c1dceb\0" // Free(const UuidInterface* object)
		"Alloc@b4bcd05ac327e0dc\0" // Alloc(const maxon::SourceLocation& allocLocation)
		"Alloc@c8d545255d7c3e59\0" // Alloc(const maxon::SourceLocation& allocLocation, const UuidInterface& object)
		"Alloc@fbf7d89aae793cf0\0" // Alloc(const maxon::SourceLocation& allocLocation, const String& uuid)
		"Alloc@cf20a91c78882bff\0" // Alloc(const maxon::SourceLocation& allocLocation, const UChar* uuid, Int uuidSize)
		"IsEmpty@76f01901\0" // IsEmpty() const
		"CreateId@a54f4799cbe1a498\0" // CreateId()
		"Set@84c7b902e2c48cc0\0" // Set(const String& uuid)
		"Set@c5f300a70baee657\0" // Set(const UChar* uuid, Int uuidSize)
		"Get@5b115b5bdcf1ec00\0" // Get(UChar* uuid, Int uuidSize) const
		"ToString@7de9f6f51c89c899\0" // ToString(const FormatStatement* formatStatement) const
		"Compare@aa95f8def31c6a10\0" // Compare(const UuidInterface* uuid) const
		"GetHashCode@95445951\0" // GetHashCode() const
		"DescribeIO@0c0a05550eef0455\0" // DescribeIO(const DataSerializeInterface& stream)
		"CreateUuidString@44dd277090c0368e\0" // CreateUuidString()
	"";
	class UuidInterface::Unresolved : public UuidInterface
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
		UInt GetHashCode() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const UuidInterface*) this)->GetHashCode(); return 0;}
		static Result<void> DescribeIO(const DataSerializeInterface& stream) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return UuidInterface::DescribeIO(stream); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static Result<String> CreateUuidString() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return UuidInterface::CreateUuidString(); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
	};
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
		maxon::details::NullReturnType<UInt>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<String>>::value,
		maxon::NULL_RETURN_TYPE::OTHER
	};
#endif
	maxon::Bool UuidInterface::MTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl)
	{
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_UuidInterface_Free = &Wrapper<Unresolved>::_UuidInterface_Free;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_UuidInterface_Alloc = &Wrapper<Unresolved>::_UuidInterface_Alloc;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_UuidInterface_Alloc_1 = &Wrapper<Unresolved>::_UuidInterface_Alloc_1;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_UuidInterface_Alloc_2 = &Wrapper<Unresolved>::_UuidInterface_Alloc_2;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_UuidInterface_Alloc_3 = &Wrapper<Unresolved>::_UuidInterface_Alloc_3;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_UuidInterface_IsEmpty = &Wrapper<Unresolved>::_UuidInterface_IsEmpty;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_UuidInterface_CreateId = &Wrapper<Unresolved>::_UuidInterface_CreateId;
	#else
		tbl->_UuidInterface_CreateId = &Wrapper<Unresolved>::_UuidInterface_CreateId;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_UuidInterface_Set = &Wrapper<Unresolved>::_UuidInterface_Set;
	#else
		tbl->_UuidInterface_Set = &Wrapper<Unresolved>::_UuidInterface_Set;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_UuidInterface_Set_1 = &Wrapper<Unresolved>::_UuidInterface_Set_1;
	#else
		tbl->_UuidInterface_Set_1 = &Wrapper<Unresolved>::_UuidInterface_Set_1;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_UuidInterface_Get = &Wrapper<Unresolved>::_UuidInterface_Get;
	#else
		tbl->_UuidInterface_Get = &Wrapper<Unresolved>::_UuidInterface_Get;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<String>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_UuidInterface_ToString = &Wrapper<Unresolved>::_UuidInterface_ToString;
	#else
		tbl->_UuidInterface_ToString = &Wrapper<Unresolved>::_UuidInterface_ToString;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<COMPARERESULT>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_UuidInterface_Compare = &Wrapper<Unresolved>::_UuidInterface_Compare;
	#else
		tbl->_UuidInterface_Compare = &Wrapper<Unresolved>::_UuidInterface_Compare;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_UuidInterface_GetHashCode = &Wrapper<Unresolved>::_UuidInterface_GetHashCode;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_UuidInterface_DescribeIO = &Wrapper<Unresolved>::_UuidInterface_DescribeIO;
	#else
		tbl->_UuidInterface_DescribeIO = &Wrapper<Unresolved>::_UuidInterface_DescribeIO;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<String>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_UuidInterface_CreateUuidString = &Wrapper<Unresolved>::_UuidInterface_CreateUuidString;
	#else
		tbl->_UuidInterface_CreateUuidString = &Wrapper<Unresolved>::_UuidInterface_CreateUuidString;
	#endif
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_interface, (maxon::Char*) tbl, _returnTypes, SIZEOF(_returnTypes) - 1);
	#else
		return true;
	#endif
	}
	MAXON_INTERFACE_REGISTER(UuidInterface, "net.maxon.interface.uuid", nullptr);
	template <typename DUMMY> maxon::Int UuidInterface::PrivateInstantiateNullValueHelper()
	{
		return 0
		| maxon::details::InstantiateNullReturnValue<COMPARERESULT>(OVERLOAD_MAX_RANK)
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
