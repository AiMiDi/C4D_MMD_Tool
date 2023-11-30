#if 1
namespace maxon
{
/// @cond INTERNAL

	const maxon::Char* const RegistryEntryIteratorInterface::MTable::_ids = 
		"Free@fb5f39717b3040f4\0" // void Free(const RegistryEntryIteratorInterface* iterator)
		"HasValue@12e73654e6d65520\0" // Bool HasValue() const
		"MoveToNext@780cdac8f1a33934\0" // void MoveToNext()
		"GetId@daec66e7da84a648\0" // const Id& GetId() const
		"GetEntry@68a84da1826b8e5f\0" // ConstDataPtr GetEntry() const
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
		const Id& GetId() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const RegistryEntryIteratorInterface*) this)->GetId(); return HXXRET3(UNRESOLVED, const Id&);}
		ConstDataPtr GetEntry() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const RegistryEntryIteratorInterface*) this)->GetEntry(); return HXXRET3(UNRESOLVED, ConstDataPtr);}
	};
	MAXON_WARNING_POP
#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
	const maxon::UNRESOLVED_RETURN_TYPE RegistryEntryIteratorInterface::MTable::_returnTypes[] = 
	{
		maxon::details::UnresolvedReturnType<void>::value,
		maxon::details::UnresolvedReturnType<Bool>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<void>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<const Id&>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<ConstDataPtr>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::UNRESOLVED_RETURN_TYPE::OTHER
	};
#endif
	maxon::Bool RegistryEntryIteratorInterface::MTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl)
	{
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->RegistryEntryIteratorInterface_Free = PRIVATE_MAXON_MF_CAST(decltype(RegistryEntryIteratorInterface_Free), &Hxx2::Wrapper<Hxx2::Unresolved>::RegistryEntryIteratorInterface_Free);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->RegistryEntryIteratorInterface_HasValue = PRIVATE_MAXON_MF_CAST(decltype(RegistryEntryIteratorInterface_HasValue), &Hxx2::Wrapper<Hxx2::Unresolved>::RegistryEntryIteratorInterface_HasValue);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->RegistryEntryIteratorInterface_MoveToNext = PRIVATE_MAXON_MF_CAST(decltype(RegistryEntryIteratorInterface_MoveToNext), &Hxx2::Wrapper<Hxx2::Unresolved>::RegistryEntryIteratorInterface_MoveToNext);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<const Id&>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->RegistryEntryIteratorInterface_GetId = PRIVATE_MAXON_MF_CAST(decltype(RegistryEntryIteratorInterface_GetId), &Hxx2::Wrapper<Hxx2::Unresolved>::RegistryEntryIteratorInterface_GetId);
		#else
		tbl->RegistryEntryIteratorInterface_GetId = PRIVATE_MAXON_MF_CAST(decltype(RegistryEntryIteratorInterface_GetId), &Hxx2::Wrapper<Hxx2::Unresolved>::RegistryEntryIteratorInterface_GetId);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<ConstDataPtr>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->RegistryEntryIteratorInterface_GetEntry = PRIVATE_MAXON_MF_CAST(decltype(RegistryEntryIteratorInterface_GetEntry), &Hxx2::Wrapper<Hxx2::Unresolved>::RegistryEntryIteratorInterface_GetEntry);
		#else
		tbl->RegistryEntryIteratorInterface_GetEntry = PRIVATE_MAXON_MF_CAST(decltype(RegistryEntryIteratorInterface_GetEntry), &Hxx2::Wrapper<Hxx2::Unresolved>::RegistryEntryIteratorInterface_GetEntry);
		#endif
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_interface, (const void**) tbl, _returnTypes, SIZEOF(MTable) / SIZEOF(void*));
	#else
		return true;
	#endif
	}
	MAXON_INTERFACE_REGISTER(RegistryEntryIteratorInterface, "net.maxon.interface.registryentryiterator", nullptr, maxon::EntityBase::FLAGS::NONE);
	template <typename DUMMY> maxon::Int RegistryEntryIteratorInterface::PrivateInstantiateDefaultValueHelper()
	{
		return 0
		| maxon::details::InstantiateDefaultReturnValue<ConstDataPtr>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateDefaultReturnValue<const Id&>(OVERLOAD_MAX_RANK)
		;
	}
	const maxon::Char* const RegistryInterface::MTable::_ids = 
		"GetId@daec66e7da84a648\0" // const Id& GetId() const
		"GetStamp@90d1992f5ac44814\0" // UInt GetStamp() const
		"GetDataType@a6c0b400f1ac4207\0" // const DataType& GetDataType() const
		"AddObserver@71f799ede540361\0" // Result<GenericData> AddObserver(Delegate<void(const Id&eid,const ConstDataPtr&value,Bool inserted)>&& observer, Bool notifyDuringRegistration) const
		"Find@25e9ef9f9b3390fe\0" // const RegistryInterface* Find(const Id& registry)
		"InsertEntry@e8d6d235a6f83645\0" // Result<void> InsertEntry(const RegistryInterface* registry, const Id& eid, ForwardingDataPtr&& value, const ModuleInfo* module)
		"EraseEntry@c0093b9596db32a1\0" // Result<Bool> EraseEntry(const RegistryInterface* registry, const Id& eid)
		"Register@803b8606b85602cf\0" // Result<GenericData> Register(const RegistryInterface* registry, const Id& eid, ForwardingDataPtr&& value)
		"FindEntryValue@4c5752d2047f82bd\0" // ConstDataPtr FindEntryValue(const RegistryInterface* registry, const Id& eid)
		"PrivateCreateIterator@34305b17847a7f3a\0" // RegistryEntryIteratorInterface* PrivateCreateIterator(const RegistryInterface* registry)
	"";
	MAXON_WARNING_PUSH
	MAXON_WARNING_DISABLE_DEPRECATED
	class RegistryInterface::Hxx2::Unresolved : public RegistryInterface
	{
	public:
		static const Unresolved* Get(const RegistryInterface* o) { return (const Unresolved*) o; }
		static Unresolved* Get(RegistryInterface* o) { return (Unresolved*) o; }
		const Id& GetId() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const RegistryInterface*) this)->GetId(); return HXXRET3(UNRESOLVED, const Id&);}
		UInt GetStamp() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const RegistryInterface*) this)->GetStamp(); return 0;}
		const DataType& GetDataType() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const RegistryInterface*) this)->GetDataType(); return HXXRET3(UNRESOLVED, const DataType&);}
		Result<GenericData> AddObserver(Delegate<void(const Id&eid,const ConstDataPtr&value,Bool inserted)>&& observer, Bool notifyDuringRegistration) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((const RegistryInterface*) this)->AddObserver(std::forward<Delegate<void(const Id&eid,const ConstDataPtr&value,Bool inserted)>>(observer), notifyDuringRegistration); return HXXRET1(UNRESOLVED);}
		static const RegistryInterface* Find(const Id& registry) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return RegistryInterface::Find(registry); return nullptr;}
		static Result<void> InsertEntry(const RegistryInterface* registry, const Id& eid, ForwardingDataPtr&& value, const ModuleInfo* module) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return RegistryInterface::InsertEntry(registry, eid, std::forward<ForwardingDataPtr>(value), module); return HXXRET1(UNRESOLVED);}
		static Result<Bool> EraseEntry(const RegistryInterface* registry, const Id& eid) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return RegistryInterface::EraseEntry(registry, eid); return HXXRET1(UNRESOLVED);}
		static Result<GenericData> Register(const RegistryInterface* registry, const Id& eid, ForwardingDataPtr&& value) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return RegistryInterface::Register(registry, eid, std::forward<ForwardingDataPtr>(value)); return HXXRET1(UNRESOLVED);}
		static ConstDataPtr FindEntryValue(const RegistryInterface* registry, const Id& eid) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return RegistryInterface::FindEntryValue(registry, eid); return HXXRET3(UNRESOLVED, ConstDataPtr);}
		static RegistryEntryIteratorInterface* PrivateCreateIterator(const RegistryInterface* registry) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return RegistryInterface::PrivateCreateIterator(registry); return nullptr;}
	};
	MAXON_WARNING_POP
#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
	const maxon::UNRESOLVED_RETURN_TYPE RegistryInterface::MTable::_returnTypes[] = 
	{
		maxon::details::UnresolvedReturnType<const Id&>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<UInt>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<const DataType&>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<Result<GenericData>>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<const RegistryInterface*>::value,
		maxon::details::UnresolvedReturnType<Result<void>>::value,
		maxon::details::UnresolvedReturnType<Result<Bool>>::value,
		maxon::details::UnresolvedReturnType<Result<GenericData>>::value,
		maxon::details::UnresolvedReturnType<ConstDataPtr>::value,
		maxon::details::UnresolvedReturnType<RegistryEntryIteratorInterface*>::value,
		maxon::UNRESOLVED_RETURN_TYPE::OTHER
	};
#endif
	maxon::Bool RegistryInterface::MTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl)
	{
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<const Id&>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->RegistryInterface_GetId = PRIVATE_MAXON_MF_CAST(decltype(RegistryInterface_GetId), &Hxx2::Wrapper<Hxx2::Unresolved>::RegistryInterface_GetId);
		#else
		tbl->RegistryInterface_GetId = PRIVATE_MAXON_MF_CAST(decltype(RegistryInterface_GetId), &Hxx2::Wrapper<Hxx2::Unresolved>::RegistryInterface_GetId);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->RegistryInterface_GetStamp = PRIVATE_MAXON_MF_CAST(decltype(RegistryInterface_GetStamp), &Hxx2::Wrapper<Hxx2::Unresolved>::RegistryInterface_GetStamp);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<const DataType&>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->RegistryInterface_GetDataType = PRIVATE_MAXON_MF_CAST(decltype(RegistryInterface_GetDataType), &Hxx2::Wrapper<Hxx2::Unresolved>::RegistryInterface_GetDataType);
		#else
		tbl->RegistryInterface_GetDataType = PRIVATE_MAXON_MF_CAST(decltype(RegistryInterface_GetDataType), &Hxx2::Wrapper<Hxx2::Unresolved>::RegistryInterface_GetDataType);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<GenericData>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->RegistryInterface_AddObserver = PRIVATE_MAXON_MF_CAST(decltype(RegistryInterface_AddObserver), &Hxx2::Wrapper<Hxx2::Unresolved>::RegistryInterface_AddObserver);
		#else
		tbl->RegistryInterface_AddObserver = PRIVATE_MAXON_MF_CAST(decltype(RegistryInterface_AddObserver), &Hxx2::Wrapper<Hxx2::Unresolved>::RegistryInterface_AddObserver);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->RegistryInterface_Find = PRIVATE_MAXON_MF_CAST(decltype(RegistryInterface_Find), &Hxx2::Wrapper<Hxx2::Unresolved>::RegistryInterface_Find);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<void>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->RegistryInterface_InsertEntry = PRIVATE_MAXON_MF_CAST(decltype(RegistryInterface_InsertEntry), &Hxx2::Wrapper<Hxx2::Unresolved>::RegistryInterface_InsertEntry);
		#else
		tbl->RegistryInterface_InsertEntry = PRIVATE_MAXON_MF_CAST(decltype(RegistryInterface_InsertEntry), &Hxx2::Wrapper<Hxx2::Unresolved>::RegistryInterface_InsertEntry);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<Bool>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->RegistryInterface_EraseEntry = PRIVATE_MAXON_MF_CAST(decltype(RegistryInterface_EraseEntry), &Hxx2::Wrapper<Hxx2::Unresolved>::RegistryInterface_EraseEntry);
		#else
		tbl->RegistryInterface_EraseEntry = PRIVATE_MAXON_MF_CAST(decltype(RegistryInterface_EraseEntry), &Hxx2::Wrapper<Hxx2::Unresolved>::RegistryInterface_EraseEntry);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<GenericData>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->RegistryInterface_Register = PRIVATE_MAXON_MF_CAST(decltype(RegistryInterface_Register), &Hxx2::Wrapper<Hxx2::Unresolved>::RegistryInterface_Register);
		#else
		tbl->RegistryInterface_Register = PRIVATE_MAXON_MF_CAST(decltype(RegistryInterface_Register), &Hxx2::Wrapper<Hxx2::Unresolved>::RegistryInterface_Register);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<ConstDataPtr>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->RegistryInterface_FindEntryValue = PRIVATE_MAXON_MF_CAST(decltype(RegistryInterface_FindEntryValue), &Hxx2::Wrapper<Hxx2::Unresolved>::RegistryInterface_FindEntryValue);
		#else
		tbl->RegistryInterface_FindEntryValue = PRIVATE_MAXON_MF_CAST(decltype(RegistryInterface_FindEntryValue), &Hxx2::Wrapper<Hxx2::Unresolved>::RegistryInterface_FindEntryValue);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->RegistryInterface_PrivateCreateIterator = PRIVATE_MAXON_MF_CAST(decltype(RegistryInterface_PrivateCreateIterator), &Hxx2::Wrapper<Hxx2::Unresolved>::RegistryInterface_PrivateCreateIterator);
		#endif
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_interface, (const void**) tbl, _returnTypes, SIZEOF(MTable) / SIZEOF(void*));
	#else
		return true;
	#endif
	}
	MAXON_INTERFACE_REGISTER(RegistryInterface, "net.maxon.interface.registry", nullptr, maxon::EntityBase::FLAGS::NONE);
	template <typename DUMMY> maxon::Int RegistryInterface::PrivateInstantiateDefaultValueHelper()
	{
		return 0
		| maxon::details::InstantiateDefaultReturnValue<ConstDataPtr>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateDefaultReturnValue<ResultPtr<RegistryEntryIteratorInterface>>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateDefaultReturnValue<const DataType&>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateDefaultReturnValue<const Id&>(OVERLOAD_MAX_RANK)
		;
	}
/// @endcond

}
#endif
static maxon::details::ForceEvaluation s_forceEval_registrybase(0
	| maxon::RegistryEntryIteratorInterface::PrivateInstantiateDefaultValueHelper<maxon::Int>()
	| maxon::RegistryInterface::PrivateInstantiateDefaultValueHelper<maxon::Int>()
);
