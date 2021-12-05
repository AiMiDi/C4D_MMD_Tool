#if 1
namespace maxon
{
/// @cond INTERNAL

	const maxon::Char* const RegistryEntryIteratorInterface::MTable::_ids = 
		"Free@eba2768f46d33d7b\0" // void Free(const RegistryEntryIteratorInterface* iterator)
		"HasValue@76f01901\0" // Bool HasValue() const
		"MoveToNext@6b2e10f\0" // void MoveToNext()
		"GetId@12b0ccb12f8b105\0" // const Id& GetId() const
		"GetEntry@953440e2cb2a6258\0" // ConstDataPtr GetEntry() const
	"";
	MAXON_WARNING_PUSH
	MAXON_WARNING_DISABLE_DEPRECATED
	class RegistryEntryIteratorInterface::Hxx2::Unresolved : public RegistryEntryIteratorInterface
	{
	public:
		static const Unresolved* Get(const RegistryEntryIteratorInterface* o) { return (const Unresolved*) o; }
		static Unresolved* Get(RegistryEntryIteratorInterface* o) { return (Unresolved*) o; }
		static void Free(const RegistryEntryIteratorInterface* iterator) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return RegistryEntryIteratorInterface::Free(iterator); return maxon::PrivateLogNullptrError();}
		Bool HasValue() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const RegistryEntryIteratorInterface*) this)->HasValue(); return maxon::PrivateLogNullptrError(false);}
		void MoveToNext() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((RegistryEntryIteratorInterface*) this)->MoveToNext(); return maxon::PrivateLogNullptrError();}
		const Id& GetId() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const RegistryEntryIteratorInterface*) this)->GetId(); return maxon::PrivateIncompleteNullReturnValue<const Id&>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		ConstDataPtr GetEntry() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const RegistryEntryIteratorInterface*) this)->GetEntry(); return maxon::PrivateIncompleteNullReturnValue<ConstDataPtr>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
	};
	MAXON_WARNING_POP
#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
	const maxon::NULL_RETURN_TYPE RegistryEntryIteratorInterface::MTable::_returnTypes[] = 
	{
		maxon::details::NullReturnType<void>::value,
		maxon::details::NullReturnType<Bool>::value,
		maxon::details::NullReturnType<void>::value,
		maxon::details::NullReturnType<const Id&>::value,
		maxon::details::NullReturnType<ConstDataPtr>::value,
		maxon::NULL_RETURN_TYPE::OTHER
	};
#endif
	maxon::Bool RegistryEntryIteratorInterface::MTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl)
	{
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_RegistryEntryIteratorInterface_Free = &Hxx2::Wrapper<Hxx2::Unresolved>::_RegistryEntryIteratorInterface_Free;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_RegistryEntryIteratorInterface_HasValue = &Hxx2::Wrapper<Hxx2::Unresolved>::_RegistryEntryIteratorInterface_HasValue;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_RegistryEntryIteratorInterface_MoveToNext = &Hxx2::Wrapper<Hxx2::Unresolved>::_RegistryEntryIteratorInterface_MoveToNext;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<const Id&>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_RegistryEntryIteratorInterface_GetId = &Hxx2::Wrapper<Hxx2::Unresolved>::_RegistryEntryIteratorInterface_GetId;
		#else
		tbl->_RegistryEntryIteratorInterface_GetId = &Hxx2::Wrapper<Hxx2::Unresolved>::_RegistryEntryIteratorInterface_GetId;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<ConstDataPtr>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_RegistryEntryIteratorInterface_GetEntry = &Hxx2::Wrapper<Hxx2::Unresolved>::_RegistryEntryIteratorInterface_GetEntry;
		#else
		tbl->_RegistryEntryIteratorInterface_GetEntry = &Hxx2::Wrapper<Hxx2::Unresolved>::_RegistryEntryIteratorInterface_GetEntry;
		#endif
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_interface, (maxon::Char*) tbl, _returnTypes, SIZEOF(MTable) / SIZEOF(void*));
	#else
		return true;
	#endif
	}
	MAXON_INTERFACE_REGISTER(RegistryEntryIteratorInterface, "net.maxon.interface.registryentryiterator", nullptr);
	template <typename DUMMY> maxon::Int RegistryEntryIteratorInterface::PrivateInstantiateNullValueHelper()
	{
		return 0
		| maxon::details::InstantiateNullReturnValue<ConstDataPtr>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateNullReturnValue<const Id&>(OVERLOAD_MAX_RANK)
		;
	}
	const maxon::Char* const RegistryInterface::MTable::_ids = 
		"GetId@12b0ccb12f8b105\0" // const Id& GetId() const
		"GetStamp@95445951\0" // UInt GetStamp() const
		"GetDataType@f6200306f4b3253c\0" // const DataType& GetDataType() const
		"AddObserver@63e63677a894679a\0" // Result<GenericData> AddObserver(Delegate<void(const Id&eid,const ConstDataPtr&value,Bool inserted)>&& observer, Bool notifyDuringRegistration) const
		"Find@37d19f880e545f2d\0" // const RegistryInterface* Find(const Id& registry)
		"InsertEntry@e73f9c6bd300be9c\0" // Result<void> InsertEntry(const RegistryInterface* registry, const Id& eid, ForwardingDataPtr&& value, const ModuleInfo* module)
		"EraseEntry@f617fd6ee095f0a8\0" // Result<Bool> EraseEntry(const RegistryInterface* registry, const Id& eid)
		"Register@4e258ef1dab5ff74\0" // Result<GenericData> Register(const RegistryInterface* registry, const Id& eid, ForwardingDataPtr&& value)
		"FindEntryValue@1c7217fbd1d70294\0" // ConstDataPtr FindEntryValue(const RegistryInterface* registry, const Id& eid)
		"PrivateCreateIterator@36b795bdc47ab3a9\0" // RegistryEntryIteratorInterface* PrivateCreateIterator(const RegistryInterface* registry)
	"";
	MAXON_WARNING_PUSH
	MAXON_WARNING_DISABLE_DEPRECATED
	class RegistryInterface::Hxx2::Unresolved : public RegistryInterface
	{
	public:
		static const Unresolved* Get(const RegistryInterface* o) { return (const Unresolved*) o; }
		static Unresolved* Get(RegistryInterface* o) { return (Unresolved*) o; }
		const Id& GetId() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const RegistryInterface*) this)->GetId(); return maxon::PrivateIncompleteNullReturnValue<const Id&>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		UInt GetStamp() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const RegistryInterface*) this)->GetStamp(); return 0;}
		const DataType& GetDataType() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const RegistryInterface*) this)->GetDataType(); return maxon::PrivateIncompleteNullReturnValue<const DataType&>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		Result<GenericData> AddObserver(Delegate<void(const Id&eid,const ConstDataPtr&value,Bool inserted)>&& observer, Bool notifyDuringRegistration) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((const RegistryInterface*) this)->AddObserver(std::forward<Delegate<void(const Id&eid,const ConstDataPtr&value,Bool inserted)>>(observer), notifyDuringRegistration); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static const RegistryInterface* Find(const Id& registry) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return RegistryInterface::Find(registry); return nullptr;}
		static Result<void> InsertEntry(const RegistryInterface* registry, const Id& eid, ForwardingDataPtr&& value, const ModuleInfo* module) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return RegistryInterface::InsertEntry(registry, eid, std::forward<ForwardingDataPtr>(value), module); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static Result<Bool> EraseEntry(const RegistryInterface* registry, const Id& eid) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return RegistryInterface::EraseEntry(registry, eid); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static Result<GenericData> Register(const RegistryInterface* registry, const Id& eid, ForwardingDataPtr&& value) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return RegistryInterface::Register(registry, eid, std::forward<ForwardingDataPtr>(value)); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static ConstDataPtr FindEntryValue(const RegistryInterface* registry, const Id& eid) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return RegistryInterface::FindEntryValue(registry, eid); return maxon::PrivateIncompleteNullReturnValue<ConstDataPtr>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		static RegistryEntryIteratorInterface* PrivateCreateIterator(const RegistryInterface* registry) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return RegistryInterface::PrivateCreateIterator(registry); return nullptr;}
	};
	MAXON_WARNING_POP
#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
	const maxon::NULL_RETURN_TYPE RegistryInterface::MTable::_returnTypes[] = 
	{
		maxon::details::NullReturnType<const Id&>::value,
		maxon::details::NullReturnType<UInt>::value,
		maxon::details::NullReturnType<const DataType&>::value,
		maxon::details::NullReturnType<Result<GenericData>>::value,
		maxon::details::NullReturnType<const RegistryInterface*>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<Bool>>::value,
		maxon::details::NullReturnType<Result<GenericData>>::value,
		maxon::details::NullReturnType<ConstDataPtr>::value,
		maxon::details::NullReturnType<RegistryEntryIteratorInterface*>::value,
		maxon::NULL_RETURN_TYPE::OTHER
	};
#endif
	maxon::Bool RegistryInterface::MTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl)
	{
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<const Id&>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_RegistryInterface_GetId = &Hxx2::Wrapper<Hxx2::Unresolved>::_RegistryInterface_GetId;
		#else
		tbl->_RegistryInterface_GetId = &Hxx2::Wrapper<Hxx2::Unresolved>::_RegistryInterface_GetId;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_RegistryInterface_GetStamp = &Hxx2::Wrapper<Hxx2::Unresolved>::_RegistryInterface_GetStamp;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<const DataType&>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_RegistryInterface_GetDataType = &Hxx2::Wrapper<Hxx2::Unresolved>::_RegistryInterface_GetDataType;
		#else
		tbl->_RegistryInterface_GetDataType = &Hxx2::Wrapper<Hxx2::Unresolved>::_RegistryInterface_GetDataType;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<GenericData>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_RegistryInterface_AddObserver = &Hxx2::Wrapper<Hxx2::Unresolved>::_RegistryInterface_AddObserver;
		#else
		tbl->_RegistryInterface_AddObserver = &Hxx2::Wrapper<Hxx2::Unresolved>::_RegistryInterface_AddObserver;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_RegistryInterface_Find = &Hxx2::Wrapper<Hxx2::Unresolved>::_RegistryInterface_Find;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_RegistryInterface_InsertEntry = &Hxx2::Wrapper<Hxx2::Unresolved>::_RegistryInterface_InsertEntry;
		#else
		tbl->_RegistryInterface_InsertEntry = &Hxx2::Wrapper<Hxx2::Unresolved>::_RegistryInterface_InsertEntry;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<Bool>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_RegistryInterface_EraseEntry = &Hxx2::Wrapper<Hxx2::Unresolved>::_RegistryInterface_EraseEntry;
		#else
		tbl->_RegistryInterface_EraseEntry = &Hxx2::Wrapper<Hxx2::Unresolved>::_RegistryInterface_EraseEntry;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<GenericData>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_RegistryInterface_Register = &Hxx2::Wrapper<Hxx2::Unresolved>::_RegistryInterface_Register;
		#else
		tbl->_RegistryInterface_Register = &Hxx2::Wrapper<Hxx2::Unresolved>::_RegistryInterface_Register;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<ConstDataPtr>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_RegistryInterface_FindEntryValue = &Hxx2::Wrapper<Hxx2::Unresolved>::_RegistryInterface_FindEntryValue;
		#else
		tbl->_RegistryInterface_FindEntryValue = &Hxx2::Wrapper<Hxx2::Unresolved>::_RegistryInterface_FindEntryValue;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_RegistryInterface_PrivateCreateIterator = &Hxx2::Wrapper<Hxx2::Unresolved>::_RegistryInterface_PrivateCreateIterator;
		#endif
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_interface, (maxon::Char*) tbl, _returnTypes, SIZEOF(MTable) / SIZEOF(void*));
	#else
		return true;
	#endif
	}
	MAXON_INTERFACE_REGISTER(RegistryInterface, "net.maxon.interface.registry", nullptr);
	template <typename DUMMY> maxon::Int RegistryInterface::PrivateInstantiateNullValueHelper()
	{
		return 0
		| maxon::details::InstantiateNullReturnValue<ConstDataPtr>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateNullReturnValue<ResultPtr<RegistryEntryIteratorInterface>>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateNullReturnValue<const DataType&>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateNullReturnValue<const Id&>(OVERLOAD_MAX_RANK)
		;
	}
/// @endcond

}
#endif
static maxon::details::ForceEvaluation s_forceEval_registrybase(0
	| maxon::RegistryEntryIteratorInterface::PrivateInstantiateNullValueHelper<maxon::Int>()
	| maxon::RegistryInterface::PrivateInstantiateNullValueHelper<maxon::Int>()
);
