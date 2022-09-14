#if 1
namespace maxon
{
/// @cond INTERNAL

#ifdef MAXON_LARGE_VTABLE
#else
#endif
#ifndef MAXON_TARGET_DEBUG
#endif
#ifdef MAXON_COMPONENT_HASHTABLE
#endif
	namespace enum203
	{
		enum class METHOD_FLAGS : UChar
		{
			NONE = 0,
			FORCE_SUPERCALL = 1
		} ;
		static const maxon::UInt64 METHOD_FLAGS_values[] = {maxon::UInt64(enum203::METHOD_FLAGS::NONE), maxon::UInt64(enum203::METHOD_FLAGS::FORCE_SUPERCALL)};
		static const maxon::EnumInfo METHOD_FLAGS_info{"METHOD_FLAGS", SIZEOF(METHOD_FLAGS), true, "NONE\0FORCE_SUPERCALL\0", METHOD_FLAGS_values, std::extent<decltype(METHOD_FLAGS_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_METHOD_FLAGS203(){ return enum203::METHOD_FLAGS_info; }
#ifndef MAXON_TARGET_DEBUG
#endif
#ifndef MAXON_TARGET_DEBUG
#endif
/// @endcond

#ifdef MAXON_TARGET_DEBUG
#endif
	namespace details
	{
#ifndef _HAS_CPP20_COMPARISONS
#endif
	}
	namespace enum760
	{
		enum class KIND
			{
				NORMAL,				///< A normal object class.
				SINGLETON,		///< A singleton object class, i.e., a class with exactly one instance. The instance can be obtained with Create().
				ABSTRACT			///< An abstract object class. Create() will return an UnsupportedOperationError.
			} ;
		static const maxon::UInt64 KIND_values[] = {maxon::UInt64(enum760::KIND::NORMAL), maxon::UInt64(enum760::KIND::SINGLETON), maxon::UInt64(enum760::KIND::ABSTRACT)};
		static const maxon::EnumInfo KIND_info{"ClassInterface::KIND", SIZEOF(KIND), false, "NORMAL\0SINGLETON\0ABSTRACT\0", KIND_values, std::extent<decltype(KIND_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_KIND760(void*){ return enum760::KIND_info; }
	const maxon::Char* const ClassInterface::MTable::_ids = 
		"Free@535fa27316b0e82d\0" // void Free(const ClassInterface* object)
		"Alloc@97338857717114ec\0" // ClassInterface* Alloc(const maxon::SourceLocation& allocLocation, const Id& cid, KIND kind)
		"GetId@daec66e7da84a648\0" // const Id& GetId() const
		"GetKind@978744d15f2fd32e\0" // KIND GetKind() const
		"GetSize@7d0e6f3d29c239e7\0" // Int GetSize() const
		"GetComponents@78f046bd07d3fbd6\0" // Block<const ComponentInfo* const> GetComponents() const
		"AddComponent@9c60b503a29da924\0" // Result<void> AddComponent(const ComponentDescriptor& component)
		"RemoveLastComponent@780cdac8f1a33934\0" // void RemoveLastComponent()
		"AddComponents@e497a707cb53065c\0" // Result<void> AddComponents(const Class<>& cls)
		"Finalize@3008090429c5a175\0" // Result<void> Finalize()
		"IsFinalized@12e73654e6d65520\0" // Bool IsFinalized() const
		"GetImplementedInterfaces@374abe1a8b32640a\0" // const Block<const InterfaceReference* const>& GetImplementedInterfaces() const
		"GetDataType@a6c0b400f1ac4207\0" // const DataType& GetDataType() const
		"Create@7c798d6933e86980\0" // Result<typename maxon::details::ClassGetNonConst<REF>::type> Create() const
		"CreatePointer@1760f28ad6de3b3e\0" // Result<ObjectInterface*> CreatePointer(Int size) const
		"IsSubclassOf@f7d6dadaaf705b83\0" // Bool IsSubclassOf(const Class<>& other) const
		"ToString@a73a45c584c879d4\0" // String ToString(const FormatStatement* formatStatement) const
		"GetMetaData@45764542c49e9ee3\0" // const DataDictionary& GetMetaData() const
		"InitMetaData@812129e5163467cc\0" // void InitMetaData(DataDictionary&& data)
		"DeleteInstance@a0e3617845eeb716\0" // void DeleteInstance(const ObjectInterface* object)
		"DestructInstance@a0e3617845eeb716\0" // void DestructInstance(const ObjectInterface* object)
		"CopyInstance@9eb65db2b5629957\0" // Result<void> CopyInstance(ObjectInterface* dest, const ObjectInterface* src)
		"GetInfo@e243f1db5331a46f\0" // const ClassInfo* GetInfo() const
		"GetOrCreateMTable@5922c8199e72ba24\0" // void* GetOrCreateMTable(ClassInfo* info, const InterfaceReference& i)
		"AddProxyComponent@25529f081db2bbe1\0" // Result<Int> AddProxyComponent(const ComponentDescriptor& component, Bool shared)
	"";
	MAXON_WARNING_PUSH
	MAXON_WARNING_DISABLE_DEPRECATED
	class ClassInterface::Hxx2::Unresolved : public ClassInterface
	{
	public:
		static const Unresolved* Get(const ClassInterface* o) { return (const Unresolved*) o; }
		static Unresolved* Get(ClassInterface* o) { return (Unresolved*) o; }
		static void Free(const ClassInterface* object) { if (object && maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ClassInterface::Free(object); return maxon::PrivateLogNullptrError();}
		static ClassInterface* Alloc(const maxon::SourceLocation& allocLocation, const Id& cid, KIND kind) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ClassInterface::Alloc(allocLocation, cid, kind); return nullptr;}
		const Id& GetId() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const ClassInterface*) this)->GetId(); return maxon::PrivateNullReturnValue<const Id&>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		KIND GetKind() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const ClassInterface*) this)->GetKind(); return maxon::PrivateNullReturnValue<KIND>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		Int GetSize() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const ClassInterface*) this)->GetSize(); return 0;}
		Block<const ComponentInfo* const> GetComponents() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const ClassInterface*) this)->GetComponents(); return maxon::PrivateNullReturnValue<Block<const ComponentInfo* const>>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		Result<void> AddComponent(const ComponentDescriptor& component) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((ClassInterface*) this)->AddComponent(component); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		void RemoveLastComponent() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((ClassInterface*) this)->RemoveLastComponent(); return maxon::PrivateLogNullptrError();}
		Result<void> AddComponents(const Class<>& cls) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((ClassInterface*) this)->AddComponents(cls); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<void> Finalize() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((ClassInterface*) this)->Finalize(); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Bool IsFinalized() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const ClassInterface*) this)->IsFinalized(); return maxon::PrivateLogNullptrError(false);}
		const Block<const InterfaceReference* const>& GetImplementedInterfaces() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const ClassInterface*) this)->GetImplementedInterfaces(); return maxon::PrivateNullReturnValue<const Block<const InterfaceReference* const>&>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		const DataType& GetDataType() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const ClassInterface*) this)->GetDataType(); return maxon::PrivateNullReturnValue<const DataType&>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		Result<typename maxon::details::ClassGetNonConst<REF>::type> Create() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((const ClassInterface*) this)->Create(); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<ObjectInterface*> CreatePointer(Int size) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((const ClassInterface*) this)->CreatePointer(size); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Bool IsSubclassOf(const Class<>& other) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const ClassInterface*) this)->IsSubclassOf(other); return maxon::PrivateLogNullptrError(false);}
		String ToString(const FormatStatement* formatStatement) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const ClassInterface*) this)->ToString(formatStatement); return maxon::PrivateNullReturnValue<String>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		const DataDictionary& GetMetaData() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const ClassInterface*) this)->GetMetaData(); return maxon::PrivateNullReturnValue<const DataDictionary&>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		void InitMetaData(DataDictionary&& data) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((ClassInterface*) this)->InitMetaData(std::forward<DataDictionary>(data)); return maxon::PrivateLogNullptrError();}
		static void DeleteInstance(const ObjectInterface* object) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ClassInterface::DeleteInstance(object); return maxon::PrivateLogNullptrError();}
		static void DestructInstance(const ObjectInterface* object) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ClassInterface::DestructInstance(object); return maxon::PrivateLogNullptrError();}
		static Result<void> CopyInstance(ObjectInterface* dest, const ObjectInterface* src) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ClassInterface::CopyInstance(dest, src); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		const ClassInfo* GetInfo() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const ClassInterface*) this)->GetInfo(); return nullptr;}
		static void* GetOrCreateMTable(ClassInfo* info, const InterfaceReference& i) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ClassInterface::GetOrCreateMTable(info, i); return nullptr;}
		Result<Int> AddProxyComponent(const ComponentDescriptor& component, Bool shared) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((ClassInterface*) this)->AddProxyComponent(component, shared); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
	};
	MAXON_WARNING_POP
#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
	const maxon::NULL_RETURN_TYPE ClassInterface::MTable::_returnTypes[] = 
	{
		maxon::NULL_RETURN_TYPE::VOID_ZERO_FREE_FUNCTION,
		maxon::details::NullReturnType<ClassInterface*>::value,
		maxon::details::NullReturnType<const Id&>::value,
		maxon::details::NullReturnType<KIND>::value,
		maxon::details::NullReturnType<Int>::value,
		maxon::details::NullReturnType<Block<const ComponentInfo* const>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<void>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Bool>::value,
		maxon::details::NullReturnType<const Block<const InterfaceReference* const>&>::value,
		maxon::details::NullReturnType<const DataType&>::value,
		maxon::details::NullReturnType<Result<typename maxon::details::ClassGetNonConst<REF>::type>>::value,
		maxon::details::NullReturnType<Result<ObjectInterface*>>::value,
		maxon::details::NullReturnType<Bool>::value,
		maxon::details::NullReturnType<String>::value,
		maxon::details::NullReturnType<const DataDictionary&>::value,
		maxon::details::NullReturnType<void>::value,
		maxon::details::NullReturnType<void>::value,
		maxon::details::NullReturnType<void>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<const ClassInfo*>::value,
		maxon::details::NullReturnType<void*>::value,
		maxon::details::NullReturnType<Result<Int>>::value,
		maxon::NULL_RETURN_TYPE::OTHER
	};
#endif
	maxon::Bool ClassInterface::MTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl)
	{
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->ClassInterface_Free = PRIVATE_MAXON_MF_CAST(decltype(ClassInterface_Free), &Hxx2::Wrapper<Hxx2::Unresolved>::ClassInterface_Free);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->ClassInterface_Alloc = PRIVATE_MAXON_MF_CAST(decltype(ClassInterface_Alloc), &Hxx2::Wrapper<Hxx2::Unresolved>::ClassInterface_Alloc);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<const Id&>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->ClassInterface_GetId = PRIVATE_MAXON_MF_CAST(decltype(ClassInterface_GetId), &Hxx2::Wrapper<Hxx2::Unresolved>::ClassInterface_GetId);
		#else
		tbl->ClassInterface_GetId = PRIVATE_MAXON_MF_CAST(decltype(ClassInterface_GetId), &Hxx2::Wrapper<Hxx2::Unresolved>::ClassInterface_GetId);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<KIND>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->ClassInterface_GetKind = PRIVATE_MAXON_MF_CAST(decltype(ClassInterface_GetKind), &Hxx2::Wrapper<Hxx2::Unresolved>::ClassInterface_GetKind);
		#else
		tbl->ClassInterface_GetKind = PRIVATE_MAXON_MF_CAST(decltype(ClassInterface_GetKind), &Hxx2::Wrapper<Hxx2::Unresolved>::ClassInterface_GetKind);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->ClassInterface_GetSize = PRIVATE_MAXON_MF_CAST(decltype(ClassInterface_GetSize), &Hxx2::Wrapper<Hxx2::Unresolved>::ClassInterface_GetSize);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Block<const ComponentInfo* const>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->ClassInterface_GetComponents = PRIVATE_MAXON_MF_CAST(decltype(ClassInterface_GetComponents), &Hxx2::Wrapper<Hxx2::Unresolved>::ClassInterface_GetComponents);
		#else
		tbl->ClassInterface_GetComponents = PRIVATE_MAXON_MF_CAST(decltype(ClassInterface_GetComponents), &Hxx2::Wrapper<Hxx2::Unresolved>::ClassInterface_GetComponents);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->ClassInterface_AddComponent = PRIVATE_MAXON_MF_CAST(decltype(ClassInterface_AddComponent), &Hxx2::Wrapper<Hxx2::Unresolved>::ClassInterface_AddComponent);
		#else
		tbl->ClassInterface_AddComponent = PRIVATE_MAXON_MF_CAST(decltype(ClassInterface_AddComponent), &Hxx2::Wrapper<Hxx2::Unresolved>::ClassInterface_AddComponent);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->ClassInterface_RemoveLastComponent = PRIVATE_MAXON_MF_CAST(decltype(ClassInterface_RemoveLastComponent), &Hxx2::Wrapper<Hxx2::Unresolved>::ClassInterface_RemoveLastComponent);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->ClassInterface_AddComponents = PRIVATE_MAXON_MF_CAST(decltype(ClassInterface_AddComponents), &Hxx2::Wrapper<Hxx2::Unresolved>::ClassInterface_AddComponents);
		#else
		tbl->ClassInterface_AddComponents = PRIVATE_MAXON_MF_CAST(decltype(ClassInterface_AddComponents), &Hxx2::Wrapper<Hxx2::Unresolved>::ClassInterface_AddComponents);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->ClassInterface_Finalize = PRIVATE_MAXON_MF_CAST(decltype(ClassInterface_Finalize), &Hxx2::Wrapper<Hxx2::Unresolved>::ClassInterface_Finalize);
		#else
		tbl->ClassInterface_Finalize = PRIVATE_MAXON_MF_CAST(decltype(ClassInterface_Finalize), &Hxx2::Wrapper<Hxx2::Unresolved>::ClassInterface_Finalize);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->ClassInterface_IsFinalized = PRIVATE_MAXON_MF_CAST(decltype(ClassInterface_IsFinalized), &Hxx2::Wrapper<Hxx2::Unresolved>::ClassInterface_IsFinalized);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<const Block<const InterfaceReference* const>&>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->ClassInterface_GetImplementedInterfaces = PRIVATE_MAXON_MF_CAST(decltype(ClassInterface_GetImplementedInterfaces), &Hxx2::Wrapper<Hxx2::Unresolved>::ClassInterface_GetImplementedInterfaces);
		#else
		tbl->ClassInterface_GetImplementedInterfaces = PRIVATE_MAXON_MF_CAST(decltype(ClassInterface_GetImplementedInterfaces), &Hxx2::Wrapper<Hxx2::Unresolved>::ClassInterface_GetImplementedInterfaces);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<const DataType&>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->ClassInterface_GetDataType = PRIVATE_MAXON_MF_CAST(decltype(ClassInterface_GetDataType), &Hxx2::Wrapper<Hxx2::Unresolved>::ClassInterface_GetDataType);
		#else
		tbl->ClassInterface_GetDataType = PRIVATE_MAXON_MF_CAST(decltype(ClassInterface_GetDataType), &Hxx2::Wrapper<Hxx2::Unresolved>::ClassInterface_GetDataType);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<typename maxon::details::ClassGetNonConst<REF>::type>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->ClassInterface_Create = PRIVATE_MAXON_MF_CAST(decltype(ClassInterface_Create), &Hxx2::Wrapper<Hxx2::Unresolved>::ClassInterface_Create);
		#else
		tbl->ClassInterface_Create = PRIVATE_MAXON_MF_CAST(decltype(ClassInterface_Create), &Hxx2::Wrapper<Hxx2::Unresolved>::ClassInterface_Create);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<ObjectInterface*>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->ClassInterface_CreatePointer = PRIVATE_MAXON_MF_CAST(decltype(ClassInterface_CreatePointer), &Hxx2::Wrapper<Hxx2::Unresolved>::ClassInterface_CreatePointer);
		#else
		tbl->ClassInterface_CreatePointer = PRIVATE_MAXON_MF_CAST(decltype(ClassInterface_CreatePointer), &Hxx2::Wrapper<Hxx2::Unresolved>::ClassInterface_CreatePointer);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->ClassInterface_IsSubclassOf = PRIVATE_MAXON_MF_CAST(decltype(ClassInterface_IsSubclassOf), &Hxx2::Wrapper<Hxx2::Unresolved>::ClassInterface_IsSubclassOf);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<String>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->ClassInterface_ToString = PRIVATE_MAXON_MF_CAST(decltype(ClassInterface_ToString), &Hxx2::Wrapper<Hxx2::Unresolved>::ClassInterface_ToString);
		#else
		tbl->ClassInterface_ToString = PRIVATE_MAXON_MF_CAST(decltype(ClassInterface_ToString), &Hxx2::Wrapper<Hxx2::Unresolved>::ClassInterface_ToString);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<const DataDictionary&>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->ClassInterface_GetMetaData = PRIVATE_MAXON_MF_CAST(decltype(ClassInterface_GetMetaData), &Hxx2::Wrapper<Hxx2::Unresolved>::ClassInterface_GetMetaData);
		#else
		tbl->ClassInterface_GetMetaData = PRIVATE_MAXON_MF_CAST(decltype(ClassInterface_GetMetaData), &Hxx2::Wrapper<Hxx2::Unresolved>::ClassInterface_GetMetaData);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->ClassInterface_InitMetaData = PRIVATE_MAXON_MF_CAST(decltype(ClassInterface_InitMetaData), &Hxx2::Wrapper<Hxx2::Unresolved>::ClassInterface_InitMetaData);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->ClassInterface_DeleteInstance = PRIVATE_MAXON_MF_CAST(decltype(ClassInterface_DeleteInstance), &Hxx2::Wrapper<Hxx2::Unresolved>::ClassInterface_DeleteInstance);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->ClassInterface_DestructInstance = PRIVATE_MAXON_MF_CAST(decltype(ClassInterface_DestructInstance), &Hxx2::Wrapper<Hxx2::Unresolved>::ClassInterface_DestructInstance);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->ClassInterface_CopyInstance = PRIVATE_MAXON_MF_CAST(decltype(ClassInterface_CopyInstance), &Hxx2::Wrapper<Hxx2::Unresolved>::ClassInterface_CopyInstance);
		#else
		tbl->ClassInterface_CopyInstance = PRIVATE_MAXON_MF_CAST(decltype(ClassInterface_CopyInstance), &Hxx2::Wrapper<Hxx2::Unresolved>::ClassInterface_CopyInstance);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->ClassInterface_GetInfo = PRIVATE_MAXON_MF_CAST(decltype(ClassInterface_GetInfo), &Hxx2::Wrapper<Hxx2::Unresolved>::ClassInterface_GetInfo);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->ClassInterface_GetOrCreateMTable = PRIVATE_MAXON_MF_CAST(decltype(ClassInterface_GetOrCreateMTable), &Hxx2::Wrapper<Hxx2::Unresolved>::ClassInterface_GetOrCreateMTable);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<Int>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->ClassInterface_AddProxyComponent = PRIVATE_MAXON_MF_CAST(decltype(ClassInterface_AddProxyComponent), &Hxx2::Wrapper<Hxx2::Unresolved>::ClassInterface_AddProxyComponent);
		#else
		tbl->ClassInterface_AddProxyComponent = PRIVATE_MAXON_MF_CAST(decltype(ClassInterface_AddProxyComponent), &Hxx2::Wrapper<Hxx2::Unresolved>::ClassInterface_AddProxyComponent);
		#endif
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_interface, (maxon::Char*) tbl, _returnTypes, SIZEOF(MTable) / SIZEOF(void*));
	#else
		return true;
	#endif
	}
	MAXON_INTERFACE_REGISTER(ClassInterface, "net.maxon.interface.class", nullptr);
/// @cond INTERNAL

#ifdef MAXON_COMPILER_MSVC
#else
#endif
/// @endcond

#ifndef _HAS_CPP20_COMPARISONS
#endif
/// @cond INTERNAL

/// @endcond

	const maxon::Char* const ObjectInterface::MTable::_ids = 
		"ToString@a73a45c584c879d4\0" // String ToString(const FormatStatement* formatStatement) const
		"InitObject@7dc5a05672be487c\0" // Result<void> InitObject(const void* argument)
		"HandleMessage@bd1c6e91dc0d33f6\0" // Result<void> HandleMessage(const InternedId& message, void* argument)
		"HandleConstMessage@459e1cd134c88a24\0" // Result<void> HandleConstMessage(const InternedId& message, void* argument) const
		"IsEqual@f4098a6fe857dc18\0" // Bool IsEqual(const maxon::ObjectInterface* other) const
		"Compare@f29ba8ecb7052548\0" // COMPARERESULT Compare(const maxon::ObjectInterface* other) const
		"GetHashCodeImpl@b22918402154097b\0" // HashInt GetHashCodeImpl() const
		"GetUniqueHashCodeImpl@c78267ca5e388263\0" // UniqueHash GetUniqueHashCodeImpl() const
#ifndef _HAS_CPP20_COMPARISONS
#endif
/// @cond INTERNAL

/// @endcond

	"";
	const maxon::METHOD_FLAGS ObjectInterface::MTable::_flags[] = 
	{
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
#ifndef _HAS_CPP20_COMPARISONS
#endif
/// @cond INTERNAL

/// @endcond

		maxon::METHOD_FLAGS::NONE
	};
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL(ObjectInterface, ObjectInterface, , , "net.maxon.interface.object", "maxon.ObjectInterface", nullptr);
	template <typename DUMMY> maxon::Int ObjectInterface::PrivateInstantiateNullValueHelper()
	{
		return 0
		| maxon::details::InstantiateNullReturnValue<COMPARERESULT>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateNullReturnValue<HashInt>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateNullReturnValue<String>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateNullReturnValue<UniqueHash>(OVERLOAD_MAX_RANK)
		;
	}
/// @cond INTERNAL

#ifdef MAXON_TARGET_DEBUG
#else
#endif
#ifndef MAXON_COMPONENT_HASHTABLE
#elif defined(MAXON_TARGET_DEBUG)
#else
#endif
/// @endcond

	const maxon::Char* const ErrorInterface::MTable::_ids = 
		"GetLocation@947950a432ce1615\0" // const SourceLocation& GetLocation() const
		"SetLocation@406b5fb832b83700\0" // void SetLocation(const maxon::SourceLocation& allocLocation)
		"GetStackTrace@2b6d45bcfc281d64\0" // Block<void* const> GetStackTrace() const
		"SetStackTrace@bc9e649c404d9fb5\0" // void SetStackTrace(const Block<void* const>& trace)
		"GetMessage@b8f12dfa16054f01\0" // String GetMessage() const
		"SetMessage@cc63eccfe460c07a\0" // void SetMessage(const String& message)
		"FormatMessage@29b73c91ea3eb451\0" // String FormatMessage(const LanguageRef& language, const PartFormatter& partFormatter) const
		"SetMessageDelegate@b38c7aa86c124ebb\0" // void SetMessageDelegate(Delegate<String(const LanguageRef&language,const ErrorInterface::PartFormatter&fmt)>&& message)
		"GetCause@53dc09360072ce8d\0" // const Error& GetCause() const
		"SetCause@73ea1403e4ac5995\0" // void SetCause(const Error& cause)
		"GetMachine@b82ebbea607b1146\0" // void GetMachine(MachineRef& machine) const
		"SetMachine@9493e8cf172dd71b\0" // void SetMachine(const MachineRef& machine)
		"PrivateGetCode@7d0e6f3d29c239e7\0" // Int PrivateGetCode() const
		"PrivateSetCode@1f5c923ad8089ced\0" // void PrivateSetCode(Int code)
		"PrivateSetPreallocation@fad0643859a0ec8f\0" // void PrivateSetPreallocation(ThreadReferencedError preallocation) const
		"PrivateGetPreallocation@d5eea19beb81b471\0" // ThreadReferencedError PrivateGetPreallocation() const
		"PrivateSetDebugError@7d622e7aaa512e7d\0" // void PrivateSetDebugError(const Error& cause) const
	"";
	const maxon::METHOD_FLAGS ErrorInterface::MTable::_flags[] = 
	{
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE
	};
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(ErrorInterface, , "net.maxon.interface.error", "maxon.ErrorInterface", (ObjectInterface::PrivateGetInterface()));
	template <typename DUMMY> maxon::Int ErrorInterface::PrivateInstantiateNullValueHelper()
	{
		return 0
		| maxon::details::InstantiateNullReturnValue<Block<void* const>>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateNullReturnValue<String>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateNullReturnValue<ThreadReferencedError>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateNullReturnValue<const Error&>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateNullReturnValue<const SourceLocation&>(OVERLOAD_MAX_RANK)
		;
	}
	MAXON_REGISTRY_REGISTER(Classes);
	MAXON_REGISTRY_REGISTER(ClassTransformers);
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(ObjectBaseClass, , "net.maxon.class.object");
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_NO_OBJECT_IMPL_DEPENDENCY)
#endif
/// @cond INTERNAL

/// @endcond

	namespace details
	{
#ifdef MAXON_TARGET_MACOS
#endif
	}
}
#endif
static maxon::details::ForceEvaluation s_forceEval_objectbase(0
	| maxon::ObjectInterface::PrivateInstantiateNullValueHelper<maxon::Int>()
	| maxon::ErrorInterface::PrivateInstantiateNullValueHelper<maxon::Int>()
);
