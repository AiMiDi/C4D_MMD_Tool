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
#ifndef MAXON_TARGET_DEBUG
#endif
#ifndef MAXON_TARGET_DEBUG
#endif
/// @endcond

#ifdef MAXON_TARGET_DEBUG
#endif
	namespace enum728 { enum class KIND
		{
			NORMAL,				///< A normal object class.
			SINGLETON,		///< A singleton object class, i.e., a class with exactly one instance. The instance can be obtained with Create().
			ABSTRACT			///< An abstract object class. Create() will return an UnsupportedOperationError.
		} ; }
	maxon::String PrivateToString_KIND728(std::underlying_type<enum728::KIND>::type x, const maxon::FormatStatement* fmt, void*)
	{
		const maxon::UInt64 values[] = {(maxon::UInt64) enum728::KIND::NORMAL, (maxon::UInt64) enum728::KIND::SINGLETON, (maxon::UInt64) enum728::KIND::ABSTRACT};
		return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "ClassInterface::KIND", SIZEOF(x), false, values, "NORMAL\0SINGLETON\0ABSTRACT\0", fmt);
	}
	const maxon::Char* const ClassInterface::MTable::_ids = 
		"Free@1fa98f9e8e6926a6\0" // void Free(const ClassInterface* object)
		"Alloc@2c81924a5448ce4f\0" // ClassInterface* Alloc(const maxon::SourceLocation& allocLocation, const Id& cid, KIND kind)
		"GetId@12b0ccb12f8b105\0" // const Id& GetId() const
		"GetKind@8424a30b\0" // KIND GetKind() const
		"GetComponents@92a934753b2296c7\0" // Block<const ComponentInfo* const> GetComponents() const
		"AddComponent@cf7ffd3d2d41e4af\0" // Result<void> AddComponent(const ComponentDescriptor& component)
		"RemoveLastComponent@6b2e10f\0" // void RemoveLastComponent()
		"AddComponents@047f2bbac2b714b0\0" // Result<void> AddComponents(const Class<>& cls)
		"Finalize@a54f4799cbe1a498\0" // Result<void> Finalize()
		"IsFinalized@76f01901\0" // Bool IsFinalized() const
		"GetImplementedInterfaces@519dcabde93df9d1\0" // const Block<const InterfaceReference* const>& GetImplementedInterfaces() const
		"GetDataType@f6200306f4b3253c\0" // const DataType& GetDataType() const
		"CreateRef@c2526310a4ba9d20\0" // Result<typename maxon::details::ClassGetNonConst<REF>::type> Create() const
		"CreatePointer@b00abc101ea77266\0" // Result<ObjectInterface*> CreatePointer() const
		"IsSubclassOf@cf4281341635ed38\0" // Bool IsSubclassOf(const Class<>& other) const
		"ToString@7de9f6f51c89c899\0" // String ToString(const FormatStatement* formatStatement) const
		"DeleteInstance@ad2c8853163f05e7\0" // void DeleteInstance(const ObjectInterface* object)
		"DestructInstance@ad2c8853163f05e7\0" // void DestructInstance(const ObjectInterface* object)
		"CopyInstance@f8f71226e26b2d92\0" // Result<void> CopyInstance(ObjectInterface* dest, const ObjectInterface* src)
		"GetInfo@cda466b3f10ef3d8\0" // const ClassInfo* GetInfo() const
		"GetOrCreateMTable@f693baf65bfdb547\0" // void* GetOrCreateMTable(ClassInfo* info, const InterfaceReference& i)
		"AddProxyComponent@5a7db0536e01eb6a\0" // Result<Int> AddProxyComponent(const ComponentDescriptor& component, Bool shared)
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
		Block<const ComponentInfo* const> GetComponents() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const ClassInterface*) this)->GetComponents(); return maxon::PrivateNullReturnValue<Block<const ComponentInfo* const>>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		Result<void> AddComponent(const ComponentDescriptor& component) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((ClassInterface*) this)->AddComponent(component); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		void RemoveLastComponent() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((ClassInterface*) this)->RemoveLastComponent(); return maxon::PrivateLogNullptrError();}
		Result<void> AddComponents(const Class<>& cls) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((ClassInterface*) this)->AddComponents(cls); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<void> Finalize() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((ClassInterface*) this)->Finalize(); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Bool IsFinalized() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const ClassInterface*) this)->IsFinalized(); return maxon::PrivateLogNullptrError(false);}
		const Block<const InterfaceReference* const>& GetImplementedInterfaces() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const ClassInterface*) this)->GetImplementedInterfaces(); return maxon::PrivateNullReturnValue<const Block<const InterfaceReference* const>&>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		const DataType& GetDataType() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const ClassInterface*) this)->GetDataType(); return maxon::PrivateNullReturnValue<const DataType&>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		Result<typename maxon::details::ClassGetNonConst<REF>::type> Create() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((const ClassInterface*) this)->Create(); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<ObjectInterface*> CreatePointer() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((const ClassInterface*) this)->CreatePointer(); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Bool IsSubclassOf(const Class<>& other) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const ClassInterface*) this)->IsSubclassOf(other); return maxon::PrivateLogNullptrError(false);}
		String ToString(const FormatStatement* formatStatement) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const ClassInterface*) this)->ToString(formatStatement); return maxon::PrivateNullReturnValue<String>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
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
		tbl->_ClassInterface_Free = &Hxx2::Wrapper<Hxx2::Unresolved>::_ClassInterface_Free;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_ClassInterface_Alloc = &Hxx2::Wrapper<Hxx2::Unresolved>::_ClassInterface_Alloc;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<const Id&>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_ClassInterface_GetId = &Hxx2::Wrapper<Hxx2::Unresolved>::_ClassInterface_GetId;
		#else
		tbl->_ClassInterface_GetId = &Hxx2::Wrapper<Hxx2::Unresolved>::_ClassInterface_GetId;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<KIND>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_ClassInterface_GetKind = &Hxx2::Wrapper<Hxx2::Unresolved>::_ClassInterface_GetKind;
		#else
		tbl->_ClassInterface_GetKind = &Hxx2::Wrapper<Hxx2::Unresolved>::_ClassInterface_GetKind;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Block<const ComponentInfo* const>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_ClassInterface_GetComponents = &Hxx2::Wrapper<Hxx2::Unresolved>::_ClassInterface_GetComponents;
		#else
		tbl->_ClassInterface_GetComponents = &Hxx2::Wrapper<Hxx2::Unresolved>::_ClassInterface_GetComponents;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_ClassInterface_AddComponent = &Hxx2::Wrapper<Hxx2::Unresolved>::_ClassInterface_AddComponent;
		#else
		tbl->_ClassInterface_AddComponent = &Hxx2::Wrapper<Hxx2::Unresolved>::_ClassInterface_AddComponent;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_ClassInterface_RemoveLastComponent = &Hxx2::Wrapper<Hxx2::Unresolved>::_ClassInterface_RemoveLastComponent;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_ClassInterface_AddComponents = &Hxx2::Wrapper<Hxx2::Unresolved>::_ClassInterface_AddComponents;
		#else
		tbl->_ClassInterface_AddComponents = &Hxx2::Wrapper<Hxx2::Unresolved>::_ClassInterface_AddComponents;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_ClassInterface_Finalize = &Hxx2::Wrapper<Hxx2::Unresolved>::_ClassInterface_Finalize;
		#else
		tbl->_ClassInterface_Finalize = &Hxx2::Wrapper<Hxx2::Unresolved>::_ClassInterface_Finalize;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_ClassInterface_IsFinalized = &Hxx2::Wrapper<Hxx2::Unresolved>::_ClassInterface_IsFinalized;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<const Block<const InterfaceReference* const>&>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_ClassInterface_GetImplementedInterfaces = &Hxx2::Wrapper<Hxx2::Unresolved>::_ClassInterface_GetImplementedInterfaces;
		#else
		tbl->_ClassInterface_GetImplementedInterfaces = &Hxx2::Wrapper<Hxx2::Unresolved>::_ClassInterface_GetImplementedInterfaces;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<const DataType&>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_ClassInterface_GetDataType = &Hxx2::Wrapper<Hxx2::Unresolved>::_ClassInterface_GetDataType;
		#else
		tbl->_ClassInterface_GetDataType = &Hxx2::Wrapper<Hxx2::Unresolved>::_ClassInterface_GetDataType;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<typename maxon::details::ClassGetNonConst<REF>::type>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_ClassInterface_Create = &Hxx2::Wrapper<Hxx2::Unresolved>::_ClassInterface_Create;
		#else
		tbl->_ClassInterface_Create = &Hxx2::Wrapper<Hxx2::Unresolved>::_ClassInterface_Create;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<ObjectInterface*>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_ClassInterface_CreatePointer = &Hxx2::Wrapper<Hxx2::Unresolved>::_ClassInterface_CreatePointer;
		#else
		tbl->_ClassInterface_CreatePointer = &Hxx2::Wrapper<Hxx2::Unresolved>::_ClassInterface_CreatePointer;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_ClassInterface_IsSubclassOf = &Hxx2::Wrapper<Hxx2::Unresolved>::_ClassInterface_IsSubclassOf;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<String>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_ClassInterface_ToString = &Hxx2::Wrapper<Hxx2::Unresolved>::_ClassInterface_ToString;
		#else
		tbl->_ClassInterface_ToString = &Hxx2::Wrapper<Hxx2::Unresolved>::_ClassInterface_ToString;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_ClassInterface_DeleteInstance = &Hxx2::Wrapper<Hxx2::Unresolved>::_ClassInterface_DeleteInstance;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_ClassInterface_DestructInstance = &Hxx2::Wrapper<Hxx2::Unresolved>::_ClassInterface_DestructInstance;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_ClassInterface_CopyInstance = &Hxx2::Wrapper<Hxx2::Unresolved>::_ClassInterface_CopyInstance;
		#else
		tbl->_ClassInterface_CopyInstance = &Hxx2::Wrapper<Hxx2::Unresolved>::_ClassInterface_CopyInstance;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_ClassInterface_GetInfo = &Hxx2::Wrapper<Hxx2::Unresolved>::_ClassInterface_GetInfo;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_ClassInterface_GetOrCreateMTable = &Hxx2::Wrapper<Hxx2::Unresolved>::_ClassInterface_GetOrCreateMTable;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<Int>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_ClassInterface_AddProxyComponent = &Hxx2::Wrapper<Hxx2::Unresolved>::_ClassInterface_AddProxyComponent;
		#else
		tbl->_ClassInterface_AddProxyComponent = &Hxx2::Wrapper<Hxx2::Unresolved>::_ClassInterface_AddProxyComponent;
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

/// @cond INTERNAL

/// @endcond

	const maxon::Char* const ObjectInterface::MTable::_ids = 
		"ToString@7de9f6f51c89c899\0" // String ToString(const FormatStatement* formatStatement) const
		"InitObject@a54f4799cbe1a498\0" // Result<void> InitObject()
		"IsEqual@461edd3261b22fbd\0" // Bool IsEqual(const maxon::ObjectInterface* other) const
		"Compare@2086e2255360fea5\0" // COMPARERESULT Compare(const maxon::ObjectInterface* other) const
		"GetHashCodeImpl@95445951\0" // UInt GetHashCodeImpl() const
/// @cond INTERNAL

/// @endcond

	"";
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL(ObjectInterface, ObjectInterface, , , "net.maxon.interface.object", "maxon.ObjectInterface", nullptr);
	template <typename DUMMY> maxon::Int ObjectInterface::PrivateInstantiateNullValueHelper()
	{
		return 0
		| maxon::details::InstantiateNullReturnValue<COMPARERESULT>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateNullReturnValue<String>(OVERLOAD_MAX_RANK)
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
		"GetLocation@35913ec5a57b5490\0" // const SourceLocation& GetLocation() const
		"SetLocation@1775b50675d4dfdf\0" // void SetLocation(const maxon::SourceLocation& allocLocation)
		"GetStackTrace@7e31c5b192f039eb\0" // Block<void* const> GetStackTrace() const
		"SetStackTrace@80a0ecb2f3d8ddc6\0" // void SetStackTrace(const Block<void* const>& trace)
		"GetMessage@22c6ed80868\0" // String GetMessage() const
		"SetMessage@0a91ca997ced89a9\0" // void SetMessage(const String& message)
		"GetCause@f0c5c3de858bd052\0" // const Error& GetCause() const
		"SetCause@9d3e8267f449c92a\0" // void SetCause(const Error& cause)
		"GetMachine@9552c1a124b65b4f\0" // void GetMachine(MachineRef& machine) const
		"SetMachine@80fc695222aca44e\0" // void SetMachine(const MachineRef& machine)
		"PrivateGetCode@4386c86\0" // Int PrivateGetCode() const
		"PrivateSetCode@30b8a5d7060\0" // void PrivateSetCode(Int code)
		"PrivateSetPreallocation@8edd87eef7724d24\0" // void PrivateSetPreallocation(ThreadReferencedError preallocation) const
		"PrivateGetPreallocation@d186871c431ff6bc\0" // ThreadReferencedError PrivateGetPreallocation() const
		"PrivateSetDebugError@0a91ca9694ef5c50\0" // void PrivateSetDebugError(const Error& cause) const
	"";
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(ErrorInterface, , "net.maxon.interface.error", "maxon.ErrorInterface", (&ObjectInterface::_interface));
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
/// @cond INTERNAL

/// @endcond

#ifdef MAXON_API
#else
#endif
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
