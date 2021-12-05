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
	namespace enum716 { enum class KIND
		{
			NORMAL,				///< A normal object class.
			SINGLETON,		///< A singleton object class, i.e., a class with exactly one instance. The instance can be obtained with Create().
			ABSTRACT			///< An abstract object class. Create() will return an UnsupportedOperationError.
		} ; }
	maxon::String PrivateToString_KIND716(std::underlying_type<enum716::KIND>::type x, const maxon::FormatStatement* fmt, void*)
	{
		const maxon::UInt64 values[] = {(maxon::UInt64) enum716::KIND::NORMAL, (maxon::UInt64) enum716::KIND::SINGLETON, (maxon::UInt64) enum716::KIND::ABSTRACT};
		return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "ClassInterface::KIND", SIZEOF(x), false, values, "NORMAL\0SINGLETON\0ABSTRACT\0", fmt);
	}
	const maxon::Char* const ClassInterface::MTable::_ids = 
		"Free@1fa98f9e8e6926a6\0" // Free(const ClassInterface* object)
		"Alloc@2c81924a5448ce4f\0" // Alloc(const maxon::SourceLocation& allocLocation, const Id& cid, KIND kind)
		"GetId@12b0ccb12f8b105\0" // GetId() const
		"GetKind@8424a30b\0" // GetKind() const
		"GetComponents@92a934753b2296c7\0" // GetComponents() const
		"AddComponent@cf7ffd3d2d41e4af\0" // AddComponent(const ComponentDescriptor& component)
		"RemoveLastComponent@6b2e10f\0" // RemoveLastComponent()
		"AddComponents@047f2bbac2b714b0\0" // AddComponents(const GenericClass& cls)
		"Finalize@a54f4799cbe1a498\0" // Finalize()
		"IsFinalized@76f01901\0" // IsFinalized() const
		"GetImplementedInterfaces@519dcabde93df9d1\0" // GetImplementedInterfaces() const
		"GetDataType@f6200306f4b33440\0" // GetDataType() const
		"CreateRef@c2526310a4ba9d20\0" // CreateRef() const
		"CreatePointer@56c758472497e589\0" // CreatePointer() const
		"ToString@7de9f6f51c89c899\0" // ToString(const FormatStatement* formatStatement) const
		"DeleteInstance@47a78878bb2adbc4\0" // DeleteInstance(const Object* object)
		"DestructInstance@47a78878bb2adbc4\0" // DestructInstance(const Object* object)
		"CopyInstance@4fab0aa84b217e6e\0" // CopyInstance(const Object* src, Object* dest)
		"GetInfo@cda466b3f10ef3d8\0" // GetInfo() const
		"GetOrCreateMTable@f693baf65bfdb547\0" // GetOrCreateMTable(ClassInfo* info, const InterfaceReference& i)
		"AddProxyComponent@5a7db0536e01eb6a\0" // AddProxyComponent(const ComponentDescriptor& component, Bool shared)
	"";
	class ClassInterface::Unresolved : public ClassInterface
	{
	public:
		static const Unresolved* Get(const ClassInterface* o) { return (const Unresolved*) o; }
		static Unresolved* Get(ClassInterface* o) { return (Unresolved*) o; }
		static void Free(const ClassInterface* object) { if (object && maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ClassInterface::Free(object); return maxon::PrivateLogNullptrError();}
		static ClassInterface* Alloc(const maxon::SourceLocation& allocLocation, const Id& cid, KIND kind) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ClassInterface::Alloc(allocLocation, cid, kind); return nullptr;}
		const Id& GetId() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const ClassInterface*) this)->GetId(); return maxon::PrivateIncompleteNullReturnValue<const Id&>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		KIND GetKind() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const ClassInterface*) this)->GetKind(); return maxon::PrivateIncompleteNullReturnValue<KIND>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		Block<const ComponentInfo* const> GetComponents() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const ClassInterface*) this)->GetComponents(); return maxon::PrivateIncompleteNullReturnValue<Block<const ComponentInfo* const>>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		Result<void> AddComponent(const ComponentDescriptor& component) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((ClassInterface*) this)->AddComponent(component); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		void RemoveLastComponent() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((ClassInterface*) this)->RemoveLastComponent(); return maxon::PrivateLogNullptrError();}
		Result<void> AddComponents(const GenericClass& cls) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((ClassInterface*) this)->AddComponents(cls); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<void> Finalize() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((ClassInterface*) this)->Finalize(); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Bool IsFinalized() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const ClassInterface*) this)->IsFinalized(); return maxon::PrivateLogNullptrError(false);}
		const Block<const InterfaceReference* const>& GetImplementedInterfaces() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const ClassInterface*) this)->GetImplementedInterfaces(); return maxon::PrivateIncompleteNullReturnValue<const Block<const InterfaceReference* const>&>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		const DataType* GetDataType() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const ClassInterface*) this)->GetDataType(); return nullptr;}
		Result<ObjectRef> CreateRef() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((const ClassInterface*) this)->CreateRef(); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<Object*> CreatePointer() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((const ClassInterface*) this)->CreatePointer(); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		String ToString(const FormatStatement* formatStatement) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const ClassInterface*) this)->ToString(formatStatement); return maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		static void DeleteInstance(const Object* object) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ClassInterface::DeleteInstance(object); return maxon::PrivateLogNullptrError();}
		static void DestructInstance(const Object* object) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ClassInterface::DestructInstance(object); return maxon::PrivateLogNullptrError();}
		static Result<void> CopyInstance(const Object* src, Object* dest) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ClassInterface::CopyInstance(src, dest); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		const ClassInfo* GetInfo() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const ClassInterface*) this)->GetInfo(); return nullptr;}
		static void* GetOrCreateMTable(ClassInfo* info, const InterfaceReference& i) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ClassInterface::GetOrCreateMTable(info, i); return nullptr;}
		Result<Int> AddProxyComponent(const ComponentDescriptor& component, Bool shared) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((ClassInterface*) this)->AddProxyComponent(component, shared); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
	};
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
		maxon::details::NullReturnType<const DataType*>::value,
		maxon::details::NullReturnType<Result<ObjectRef>>::value,
		maxon::details::NullReturnType<Result<Object*>>::value,
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
		tbl->_ClassInterface_Free = &Wrapper<Unresolved>::_ClassInterface_Free;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_ClassInterface_Alloc = &Wrapper<Unresolved>::_ClassInterface_Alloc;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<const Id&>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_ClassInterface_GetId = &Wrapper<Unresolved>::_ClassInterface_GetId;
	#else
		tbl->_ClassInterface_GetId = &Wrapper<Unresolved>::_ClassInterface_GetId;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<KIND>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_ClassInterface_GetKind = &Wrapper<Unresolved>::_ClassInterface_GetKind;
	#else
		tbl->_ClassInterface_GetKind = &Wrapper<Unresolved>::_ClassInterface_GetKind;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Block<const ComponentInfo* const>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_ClassInterface_GetComponents = &Wrapper<Unresolved>::_ClassInterface_GetComponents;
	#else
		tbl->_ClassInterface_GetComponents = &Wrapper<Unresolved>::_ClassInterface_GetComponents;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_ClassInterface_AddComponent = &Wrapper<Unresolved>::_ClassInterface_AddComponent;
	#else
		tbl->_ClassInterface_AddComponent = &Wrapper<Unresolved>::_ClassInterface_AddComponent;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_ClassInterface_RemoveLastComponent = &Wrapper<Unresolved>::_ClassInterface_RemoveLastComponent;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_ClassInterface_AddComponents = &Wrapper<Unresolved>::_ClassInterface_AddComponents;
	#else
		tbl->_ClassInterface_AddComponents = &Wrapper<Unresolved>::_ClassInterface_AddComponents;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_ClassInterface_Finalize = &Wrapper<Unresolved>::_ClassInterface_Finalize;
	#else
		tbl->_ClassInterface_Finalize = &Wrapper<Unresolved>::_ClassInterface_Finalize;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_ClassInterface_IsFinalized = &Wrapper<Unresolved>::_ClassInterface_IsFinalized;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<const Block<const InterfaceReference* const>&>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_ClassInterface_GetImplementedInterfaces = &Wrapper<Unresolved>::_ClassInterface_GetImplementedInterfaces;
	#else
		tbl->_ClassInterface_GetImplementedInterfaces = &Wrapper<Unresolved>::_ClassInterface_GetImplementedInterfaces;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_ClassInterface_GetDataType = &Wrapper<Unresolved>::_ClassInterface_GetDataType;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<ObjectRef>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_ClassInterface_CreateRef = &Wrapper<Unresolved>::_ClassInterface_CreateRef;
	#else
		tbl->_ClassInterface_CreateRef = &Wrapper<Unresolved>::_ClassInterface_CreateRef;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<Object*>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_ClassInterface_CreatePointer = &Wrapper<Unresolved>::_ClassInterface_CreatePointer;
	#else
		tbl->_ClassInterface_CreatePointer = &Wrapper<Unresolved>::_ClassInterface_CreatePointer;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<String>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_ClassInterface_ToString = &Wrapper<Unresolved>::_ClassInterface_ToString;
	#else
		tbl->_ClassInterface_ToString = &Wrapper<Unresolved>::_ClassInterface_ToString;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_ClassInterface_DeleteInstance = &Wrapper<Unresolved>::_ClassInterface_DeleteInstance;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_ClassInterface_DestructInstance = &Wrapper<Unresolved>::_ClassInterface_DestructInstance;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_ClassInterface_CopyInstance = &Wrapper<Unresolved>::_ClassInterface_CopyInstance;
	#else
		tbl->_ClassInterface_CopyInstance = &Wrapper<Unresolved>::_ClassInterface_CopyInstance;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_ClassInterface_GetInfo = &Wrapper<Unresolved>::_ClassInterface_GetInfo;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_ClassInterface_GetOrCreateMTable = &Wrapper<Unresolved>::_ClassInterface_GetOrCreateMTable;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<Int>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_ClassInterface_AddProxyComponent = &Wrapper<Unresolved>::_ClassInterface_AddProxyComponent;
	#else
		tbl->_ClassInterface_AddProxyComponent = &Wrapper<Unresolved>::_ClassInterface_AddProxyComponent;
	#endif
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_interface, (maxon::Char*) tbl, _returnTypes, SIZEOF(_returnTypes) - 1);
	#else
		return true;
	#endif
	}
	MAXON_INTERFACE_REGISTER(ClassInterface, "net.maxon.interface.class", nullptr);
	template <typename DUMMY> maxon::Int ClassInterface::PrivateInstantiateNullValueHelper()
	{
		return 0
		| maxon::details::InstantiateNullReturnValue<Block<const ComponentInfo* const>>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateNullReturnValue<KIND>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateNullReturnValue<String>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateNullReturnValue<const Block<const InterfaceReference* const>&>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateNullReturnValue<const Id&>(OVERLOAD_MAX_RANK)
		;
	}
/// @cond INTERNAL

#ifdef MAXON_COMPILER_MSVC
#else
#endif
#if defined(MAXON_COMPILER_MSVC) && (MAXON_COMPILER_MSVC < 1910)
#else
#endif
/// @endcond

/// @cond INTERNAL

/// @endcond

	MAXON_INTERFACE_REGISTER_VIRTUAL(Object, "net.maxon.interface.object", "maxon.Object", , nullptr);
	const maxon::Char* const Object::MTable::_ids = 
		"ToString@7de9f6f51c89c899\0" // ToString(const FormatStatement* formatStatement) const
		"InitObject@a54f4799cbe1a498\0" // InitObject()
		"IsEqual@7525b65769b0ef3c\0" // IsEqual(const maxon::Object* other) const
		"Compare@aa937230229a3b54\0" // Compare(const maxon::Object* other) const
		"GetHashCodeImpl@95445951\0" // GetHashCodeImpl() const
/// @cond INTERNAL

/// @endcond

	"";
	template <typename DUMMY> maxon::Int Object::PrivateInstantiateNullValueHelper()
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

	MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(ErrorInterface, "net.maxon.interface.error", "maxon.ErrorInterface", , &Object::_interface);
	const maxon::Char* const ErrorInterface::MTable::_ids = 
		"GetLocation@35913ec5a57b5490\0" // GetLocation() const
		"SetLocation@1775b50675d4dfdf\0" // SetLocation(const maxon::SourceLocation& allocLocation)
		"GetStackTrace@7e31c5b192f039eb\0" // GetStackTrace() const
		"SetStackTrace@80a0ecb2f3d8ddc6\0" // SetStackTrace(const Block<void* const>& trace)
		"GetMessage@22c6ed80868\0" // GetMessage() const
		"SetMessage@0a91ca997ced89a9\0" // SetMessage(const String& message)
		"GetCause@f0c5c3de858bd052\0" // GetCause() const
		"SetCause@9d3e8267f449c92a\0" // SetCause(const Error& cause)
		"GetMachine@9552c1a124b65b4f\0" // GetMachine(MachineRef& machine) const
		"SetMachine@80fc695222aca44e\0" // SetMachine(const MachineRef& machine)
		"PrivateGetCode@4386c86\0" // PrivateGetCode() const
		"PrivateSetCode@30b8a5d7060\0" // PrivateSetCode(Int code)
	"";
	template <typename DUMMY> maxon::Int ErrorInterface::PrivateInstantiateNullValueHelper()
	{
		return 0
		| maxon::details::InstantiateNullReturnValue<Block<void* const>>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateNullReturnValue<String>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateNullReturnValue<const Error&>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateNullReturnValue<const SourceLocation&>(OVERLOAD_MAX_RANK)
		;
	}
	MAXON_REGISTRY_REGISTER(Classes);
	MAXON_REGISTRY_REGISTER(ClassTransformers);
/// @cond INTERNAL

/// @endcond

#if !defined(MAXON_API) || defined(DOXYGEN)
#endif
#ifdef MAXON_COMPILER_INTEL
#else
#endif
#ifndef MAXON_COMPILER_INTEL
#endif
}
#endif
static maxon::details::ForceEvaluation s_forceEval_objectbase(0
	| maxon::ClassInterface::PrivateInstantiateNullValueHelper<maxon::Int>()
	| maxon::Object::PrivateInstantiateNullValueHelper<maxon::Int>()
	| maxon::ErrorInterface::PrivateInstantiateNullValueHelper<maxon::Int>()
);
