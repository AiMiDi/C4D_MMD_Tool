
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1
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
namespace details
{
#ifndef _HAS_CPP20_COMPARISONS
#endif
}
constexpr const maxon::Char* ClassInterface::PrivateGetCppName() { return "maxon::Class"; }

struct ClassInterface::MTable
{
	static MTable _instance;
	static MTable _unresolvedInstance;
	static const maxon::Char* const _ids;
	static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl);
	static const maxon::UNRESOLVED_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = true;
	PRIVATE_MAXON_SF_POINTER(ClassInterface_Free, Free, MAXON_EXPAND_VA_ARGS, (void), const ClassInterface* object);
	PRIVATE_MAXON_SF_POINTER(ClassInterface_Alloc, Alloc, MAXON_IGNORE_VA_ARGS, (ClassInterface*), const maxon::SourceLocation& allocLocation, const Id& cid, KIND kind);
	PRIVATE_MAXON_MF_POINTER(ClassInterface_GetId, GetId, false, ClassInterface, const, (const Id&));
	PRIVATE_MAXON_MF_POINTER(ClassInterface_GetKind, GetKind, false, ClassInterface, const, (KIND));
	PRIVATE_MAXON_MF_POINTER(ClassInterface_GetSize, GetSize, false, ClassInterface, const, (Int));
	PRIVATE_MAXON_MF_POINTER(ClassInterface_GetComponents, GetComponents, false, ClassInterface, const, (Block<const ComponentInfo* const>));
	PRIVATE_MAXON_MF_POINTER(ClassInterface_AddComponent, AddComponent, false, ClassInterface,, (Result<void>), const ComponentDescriptor& component);
	PRIVATE_MAXON_MF_POINTER(ClassInterface_RemoveLastComponent, RemoveLastComponent, false, ClassInterface,, (void));
	PRIVATE_MAXON_MF_POINTER(ClassInterface_AddComponents, AddComponents, false, ClassInterface,, (Result<void>), const Class<>& cls);
	PRIVATE_MAXON_MF_POINTER(ClassInterface_Finalize, Finalize, false, ClassInterface,, (Result<void>));
	PRIVATE_MAXON_MF_POINTER(ClassInterface_IsFinalized, IsFinalized, false, ClassInterface, const, (Bool));
	PRIVATE_MAXON_MF_POINTER(ClassInterface_GetImplementedInterfaces, GetImplementedInterfaces, false, ClassInterface, const, (const Block<const InterfaceReference* const>&));
	PRIVATE_MAXON_MF_POINTER(ClassInterface_GetDataType, GetDataType, false, ClassInterface, const, (const DataType&));
	PRIVATE_MAXON_MF_POINTER(ClassInterface_Create, Create, false, ClassInterface, const, (Result<typename maxon::details::ClassGetNonConst<REF>::type>));
	PRIVATE_MAXON_MF_POINTER(ClassInterface_CreatePointer, CreatePointer, false, ClassInterface, const, (Result<ObjectInterface*>), Int size);
	PRIVATE_MAXON_MF_POINTER(ClassInterface_IsSubclassOf, IsSubclassOf, false, ClassInterface, const, (Bool), const Class<>& other);
	PRIVATE_MAXON_MF_POINTER(ClassInterface_ToString, ToString, false, ClassInterface, const, (String), const FormatStatement* formatStatement);
	PRIVATE_MAXON_MF_POINTER(ClassInterface_GetMetaData, GetMetaData, false, ClassInterface, const, (const DataDictionary&));
	PRIVATE_MAXON_MF_POINTER(ClassInterface_InitMetaData, InitMetaData, false, ClassInterface,, (void), DataDictionary&& data);
	PRIVATE_MAXON_SF_POINTER(ClassInterface_DeleteInstance, DeleteInstance, MAXON_EXPAND_VA_ARGS, (void), const ObjectInterface* object);
	PRIVATE_MAXON_SF_POINTER(ClassInterface_DestructInstance, DestructInstance, MAXON_EXPAND_VA_ARGS, (void), const ObjectInterface* object);
	PRIVATE_MAXON_SF_POINTER(ClassInterface_CopyInstance, CopyInstance, MAXON_EXPAND_VA_ARGS, (Result<void>), ObjectInterface* dest, const ObjectInterface* src);
	PRIVATE_MAXON_MF_POINTER(ClassInterface_GetInfo, GetInfo, false, ClassInterface, const, (const ClassInfo*));
	PRIVATE_MAXON_SF_POINTER(ClassInterface_GetOrCreateMTable, GetOrCreateMTable, MAXON_EXPAND_VA_ARGS, (void*), ClassInfo* info, const InterfaceReference& i);
	PRIVATE_MAXON_MF_POINTER(ClassInterface_AddProxyComponent, AddProxyComponent, false, ClassInterface,, (Result<Int>), const ComponentDescriptor& component, Bool shared);
	template <typename IMPL> void Init()
	{
		ClassInterface_Free = ClassInterface_Free_GetPtr<IMPL>(true);
		ClassInterface_Alloc = ClassInterface_Alloc_GetPtr<IMPL>(true);
		ClassInterface_GetId = ClassInterface_GetId_GetPtr<IMPL>(0, true).first;
		ClassInterface_GetKind = ClassInterface_GetKind_GetPtr<IMPL>(0, true).first;
		ClassInterface_GetSize = ClassInterface_GetSize_GetPtr<IMPL>(0, true).first;
		ClassInterface_GetComponents = ClassInterface_GetComponents_GetPtr<IMPL>(0, true).first;
		ClassInterface_AddComponent = ClassInterface_AddComponent_GetPtr<IMPL>(0, true).first;
		ClassInterface_RemoveLastComponent = ClassInterface_RemoveLastComponent_GetPtr<IMPL>(0, true).first;
		ClassInterface_AddComponents = ClassInterface_AddComponents_GetPtr<IMPL>(0, true).first;
		ClassInterface_Finalize = ClassInterface_Finalize_GetPtr<IMPL>(0, true).first;
		ClassInterface_IsFinalized = ClassInterface_IsFinalized_GetPtr<IMPL>(0, true).first;
		ClassInterface_GetImplementedInterfaces = ClassInterface_GetImplementedInterfaces_GetPtr<IMPL>(0, true).first;
		ClassInterface_GetDataType = ClassInterface_GetDataType_GetPtr<IMPL>(0, true).first;
		ClassInterface_Create = ClassInterface_Create_GetPtr<IMPL>(0, true).first;
		ClassInterface_CreatePointer = ClassInterface_CreatePointer_GetPtr<IMPL>(0, true).first;
		ClassInterface_IsSubclassOf = ClassInterface_IsSubclassOf_GetPtr<IMPL>(0, true).first;
		ClassInterface_ToString = ClassInterface_ToString_GetPtr<IMPL>(0, true).first;
		ClassInterface_GetMetaData = ClassInterface_GetMetaData_GetPtr<IMPL>(0, true).first;
		ClassInterface_InitMetaData = ClassInterface_InitMetaData_GetPtr<IMPL>(0, true).first;
		ClassInterface_DeleteInstance = ClassInterface_DeleteInstance_GetPtr<IMPL>(true);
		ClassInterface_DestructInstance = ClassInterface_DestructInstance_GetPtr<IMPL>(true);
		ClassInterface_CopyInstance = ClassInterface_CopyInstance_GetPtr<IMPL>(true);
		ClassInterface_GetInfo = ClassInterface_GetInfo_GetPtr<IMPL>(0, true).first;
		ClassInterface_GetOrCreateMTable = ClassInterface_GetOrCreateMTable_GetPtr<IMPL>(true);
		ClassInterface_AddProxyComponent = ClassInterface_AddProxyComponent_GetPtr<IMPL>(0, true).first;
	}
};

struct ClassInterface::Hxx2
{
	class Unresolved;
	template <typename S> class Wrapper
	{
	public:
		using Implementation = S;
		static void ClassInterface_Free(const ClassInterface* object) { return S::Free(object); }
		static ClassInterface* ClassInterface_Alloc(const maxon::SourceLocation& allocLocation, const Id& cid, KIND kind) { return S::Alloc(allocLocation, cid, kind); }
		PRIVATE_MAXON_MF_WRAPPER(ClassInterface_GetId, ClassInterface, const, (const Id&)) { return S::Get(PRIVATE_MAXON_MF_THIS(const ClassInterface))->GetId(); }
		PRIVATE_MAXON_MF_WRAPPER(ClassInterface_GetKind, ClassInterface, const, (KIND)) { return S::Get(PRIVATE_MAXON_MF_THIS(const ClassInterface))->GetKind(); }
		PRIVATE_MAXON_MF_WRAPPER(ClassInterface_GetSize, ClassInterface, const, (Int)) { return S::Get(PRIVATE_MAXON_MF_THIS(const ClassInterface))->GetSize(); }
		PRIVATE_MAXON_MF_WRAPPER(ClassInterface_GetComponents, ClassInterface, const, (Block<const ComponentInfo* const>)) { return S::Get(PRIVATE_MAXON_MF_THIS(const ClassInterface))->GetComponents(); }
		PRIVATE_MAXON_MF_WRAPPER(ClassInterface_AddComponent, ClassInterface,, (Result<void>), const ComponentDescriptor& component) { return S::Get(PRIVATE_MAXON_MF_THIS(ClassInterface))->AddComponent(component); }
		PRIVATE_MAXON_MF_WRAPPER(ClassInterface_RemoveLastComponent, ClassInterface,, (void)) { return S::Get(PRIVATE_MAXON_MF_THIS(ClassInterface))->RemoveLastComponent(); }
		PRIVATE_MAXON_MF_WRAPPER(ClassInterface_AddComponents, ClassInterface,, (Result<void>), const Class<>& cls) { return S::Get(PRIVATE_MAXON_MF_THIS(ClassInterface))->AddComponents(cls); }
		PRIVATE_MAXON_MF_WRAPPER(ClassInterface_Finalize, ClassInterface,, (Result<void>)) { return S::Get(PRIVATE_MAXON_MF_THIS(ClassInterface))->Finalize(); }
		PRIVATE_MAXON_MF_WRAPPER(ClassInterface_IsFinalized, ClassInterface, const, (Bool)) { return S::Get(PRIVATE_MAXON_MF_THIS(const ClassInterface))->IsFinalized(); }
		PRIVATE_MAXON_MF_WRAPPER(ClassInterface_GetImplementedInterfaces, ClassInterface, const, (const Block<const InterfaceReference* const>&)) { return S::Get(PRIVATE_MAXON_MF_THIS(const ClassInterface))->GetImplementedInterfaces(); }
		PRIVATE_MAXON_MF_WRAPPER(ClassInterface_GetDataType, ClassInterface, const, (const DataType&)) { return S::Get(PRIVATE_MAXON_MF_THIS(const ClassInterface))->GetDataType(); }
		PRIVATE_MAXON_MF_WRAPPER(ClassInterface_Create, ClassInterface, const, (Result<typename maxon::details::ClassGetNonConst<REF>::type>)) { return S::Get(PRIVATE_MAXON_MF_THIS(const ClassInterface))->Create(); }
		PRIVATE_MAXON_MF_WRAPPER(ClassInterface_CreatePointer, ClassInterface, const, (Result<ObjectInterface*>), Int size) { return S::Get(PRIVATE_MAXON_MF_THIS(const ClassInterface))->CreatePointer(size); }
		PRIVATE_MAXON_MF_WRAPPER(ClassInterface_IsSubclassOf, ClassInterface, const, (Bool), const Class<>& other) { return S::Get(PRIVATE_MAXON_MF_THIS(const ClassInterface))->IsSubclassOf(other); }
		PRIVATE_MAXON_MF_WRAPPER(ClassInterface_ToString, ClassInterface, const, (String), const FormatStatement* formatStatement) { return S::Get(PRIVATE_MAXON_MF_THIS(const ClassInterface))->ToString(formatStatement); }
		PRIVATE_MAXON_MF_WRAPPER(ClassInterface_GetMetaData, ClassInterface, const, (const DataDictionary&)) { return S::Get(PRIVATE_MAXON_MF_THIS(const ClassInterface))->GetMetaData(); }
		PRIVATE_MAXON_MF_WRAPPER(ClassInterface_InitMetaData, ClassInterface,, (void), DataDictionary&& data) { return S::Get(PRIVATE_MAXON_MF_THIS(ClassInterface))->InitMetaData(std::forward<DataDictionary>(data)); }
		static void ClassInterface_DeleteInstance(const ObjectInterface* object) { return S::DeleteInstance(object); }
		static void ClassInterface_DestructInstance(const ObjectInterface* object) { return S::DestructInstance(object); }
		static Result<void> ClassInterface_CopyInstance(ObjectInterface* dest, const ObjectInterface* src) { return S::CopyInstance(dest, src); }
		PRIVATE_MAXON_MF_WRAPPER(ClassInterface_GetInfo, ClassInterface, const, (const ClassInfo*)) { return S::Get(PRIVATE_MAXON_MF_THIS(const ClassInterface))->GetInfo(); }
		static void* ClassInterface_GetOrCreateMTable(ClassInfo* info, const InterfaceReference& i) { return S::GetOrCreateMTable(info, i); }
		PRIVATE_MAXON_MF_WRAPPER(ClassInterface_AddProxyComponent, ClassInterface,, (Result<Int>), const ComponentDescriptor& component, Bool shared) { return S::Get(PRIVATE_MAXON_MF_THIS(ClassInterface))->AddProxyComponent(component, shared); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto ClassInterface::Free(const ClassInterface* object) -> void
{
	return MTable::_instance.ClassInterface_Free(object);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ClassInterface::Alloc(const maxon::SourceLocation& allocLocation, const Id& cid, KIND kind) -> ClassInterface*
{
	return MTable::_instance.ClassInterface_Alloc(allocLocation, cid, kind);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ClassInterface::GetId() const -> const Id&
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.ClassInterface_GetId);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ClassInterface::GetKind() const -> KIND
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.ClassInterface_GetKind);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ClassInterface::GetSize() const -> Int
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.ClassInterface_GetSize);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ClassInterface::GetComponents() const -> Block<const ComponentInfo* const>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.ClassInterface_GetComponents);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ClassInterface::AddComponent(const ComponentDescriptor& component) -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.ClassInterface_AddComponent, component);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ClassInterface::RemoveLastComponent() -> void
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.ClassInterface_RemoveLastComponent);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ClassInterface::AddComponents(const Class<>& cls) -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.ClassInterface_AddComponents, cls);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ClassInterface::Finalize() -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.ClassInterface_Finalize);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ClassInterface::IsFinalized() const -> Bool
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.ClassInterface_IsFinalized);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ClassInterface::GetImplementedInterfaces() const -> const Block<const InterfaceReference* const>&
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.ClassInterface_GetImplementedInterfaces);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ClassInterface::GetDataType() const -> const DataType&
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.ClassInterface_GetDataType);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ClassInterface::Create() const -> Result<typename maxon::details::ClassGetNonConst<REF>::type>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.ClassInterface_Create);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ClassInterface::CreatePointer(Int size) const -> Result<ObjectInterface*>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.ClassInterface_CreatePointer, size);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ClassInterface::IsSubclassOf(const Class<>& other) const -> Bool
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.ClassInterface_IsSubclassOf, other);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ClassInterface::ToString(const FormatStatement* formatStatement) const -> String
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.ClassInterface_ToString, formatStatement);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ClassInterface::GetMetaData() const -> const DataDictionary&
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.ClassInterface_GetMetaData);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ClassInterface::InitMetaData(DataDictionary&& data) -> void
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.ClassInterface_InitMetaData, std::forward<DataDictionary>(data));
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ClassInterface::DeleteInstance(const ObjectInterface* object) -> void
{
	return MTable::_instance.ClassInterface_DeleteInstance(object);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ClassInterface::DestructInstance(const ObjectInterface* object) -> void
{
	return MTable::_instance.ClassInterface_DestructInstance(object);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ClassInterface::CopyInstance(ObjectInterface* dest, const ObjectInterface* src) -> Result<void>
{
	return MTable::_instance.ClassInterface_CopyInstance(dest, src);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ClassInterface::GetInfo() const -> const ClassInfo*
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.ClassInterface_GetInfo);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ClassInterface::GetOrCreateMTable(ClassInfo* info, const InterfaceReference& i) -> void*
{
	return MTable::_instance.ClassInterface_GetOrCreateMTable(info, i);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ClassInterface::AddProxyComponent(const ComponentDescriptor& component, Bool shared) -> Result<Int>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.ClassInterface_AddProxyComponent, component, shared);
}

template <typename REF_> auto ClassInterface::Hxx1::Reference<REF_>::Create(const Id& cid, KIND kind) -> maxon::ResultMemT<Class<REF_>>
{
	ClassInterface* res_ = ClassInterface::Alloc(MAXON_SOURCE_LOCATION, cid, kind);
	return Class<REF_>(maxon::ForwardResultPtr<ClassInterface>(res_));
}
template <typename S, typename REF_> MAXON_ATTRIBUTE_FORCE_INLINE auto ClassInterface::Hxx1::ConstFn<S, REF_>::GetId() const -> HXXADDRET2(const Id&)
{
	HXXRETURN0(HXXADDRET2(const Id&)); HXXRES; HXXCONST(maxon::PrivateDefaultReturnValue<const Id&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.ClassInterface_GetId));
}
template <typename S, typename REF_> MAXON_ATTRIBUTE_FORCE_INLINE auto ClassInterface::Hxx1::ConstFn<S, REF_>::GetKind() const -> HXXADDRET2(KIND)
{
	HXXRETURN0(HXXADDRET2(KIND)); HXXRES; HXXCONST(maxon::PrivateDefaultReturnValue<KIND>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.ClassInterface_GetKind));
}
template <typename S, typename REF_> MAXON_ATTRIBUTE_FORCE_INLINE auto ClassInterface::Hxx1::ConstFn<S, REF_>::GetSize() const -> HXXADDRET2(Int)
{
	HXXRETURN0(HXXADDRET2(Int)); HXXRES; HXXCONST(0) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.ClassInterface_GetSize));
}
template <typename S, typename REF_> MAXON_ATTRIBUTE_FORCE_INLINE auto ClassInterface::Hxx1::ConstFn<S, REF_>::GetComponents() const -> HXXADDRET2(Block<const ComponentInfo* const>)
{
	HXXRETURN0(HXXADDRET2(Block<const ComponentInfo* const>)); HXXRES; HXXCONST(maxon::PrivateDefaultReturnValue<Block<const ComponentInfo* const>>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.ClassInterface_GetComponents));
}
template <typename S, typename REF_> MAXON_ATTRIBUTE_FORCE_INLINE auto ClassInterface::Hxx1::Fn<S, REF_>::AddComponent(const ComponentDescriptor& component) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.ClassInterface_AddComponent, component));
}
template <typename S, typename REF_> MAXON_ATTRIBUTE_FORCE_INLINE auto ClassInterface::Hxx1::Fn<S, REF_>::AddComponents(const Class<>& cls) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.ClassInterface_AddComponents, cls));
}
template <typename S, typename REF_> MAXON_ATTRIBUTE_FORCE_INLINE auto ClassInterface::Hxx1::Fn<S, REF_>::Finalize() const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.ClassInterface_Finalize));
}
template <typename S, typename REF_> MAXON_ATTRIBUTE_FORCE_INLINE auto ClassInterface::Hxx1::ConstFn<S, REF_>::IsFinalized() const -> HXXADDRET2(Bool)
{
	HXXRETURN0(HXXADDRET2(Bool)); HXXRES; HXXCONST(maxon::PrivateLogNullptrError(false)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.ClassInterface_IsFinalized));
}
template <typename S, typename REF_> MAXON_ATTRIBUTE_FORCE_INLINE auto ClassInterface::Hxx1::ConstFn<S, REF_>::GetImplementedInterfaces() const -> HXXADDRET2(const Block<const InterfaceReference* const>&)
{
	HXXRETURN0(HXXADDRET2(const Block<const InterfaceReference* const>&)); HXXRES; HXXCONST(maxon::PrivateDefaultReturnValue<const Block<const InterfaceReference* const>&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.ClassInterface_GetImplementedInterfaces));
}
template <typename S, typename REF_> MAXON_ATTRIBUTE_FORCE_INLINE auto ClassInterface::Hxx1::ConstFn<S, REF_>::GetDataType() const -> HXXADDRET2(const DataType&)
{
	HXXRETURN0(HXXADDRET2(const DataType&)); HXXRES; HXXCONST(maxon::PrivateDefaultReturnValue<const DataType&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.ClassInterface_GetDataType));
}
template <typename S, typename REF_> MAXON_ATTRIBUTE_FORCE_INLINE auto ClassInterface::Hxx1::ConstFn<S, REF_>::Create() const -> Result<typename maxon::details::ClassGetNonConst<REF_>::type>
{
	HXXRETURN0(Result<typename maxon::details::ClassGetNonConst<REF_>::type>); HXXRES; HXXCONST(HXXRET1(NULLPTR)) 
	return maxon::GenericReinterpretCast<typename ReturnHelper::ReturnType>(PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.ClassInterface_Create));
}
template <typename S, typename REF_> MAXON_ATTRIBUTE_FORCE_INLINE auto ClassInterface::Hxx1::ConstFn<S, REF_>::Implements(const InterfaceReference& iref) const -> HXXADDRET2(Bool)
{
	HXXRETURN0(HXXADDRET2(Bool)); HXXRES; HXXCONST(maxon::PrivateLogNullptrError(false)) 
	return (o_->Implements(iref));
}
template <typename S, typename REF_> template <typename I> MAXON_ATTRIBUTE_FORCE_INLINE auto ClassInterface::Hxx1::ConstFn<S, REF_>::Implements() const -> HXXADDRET2(Bool)
{
	HXXRETURN0(HXXADDRET2(Bool)); HXXRES; HXXCONST(maxon::PrivateLogNullptrError(false)) 
	return (o_->Implements<I>());
}
template <typename S, typename REF_> MAXON_ATTRIBUTE_FORCE_INLINE auto ClassInterface::Hxx1::ConstFn<S, REF_>::IsSubclassOf(const Class<>& other) const -> HXXADDRET2(Bool)
{
	HXXRETURN0(HXXADDRET2(Bool)); HXXRES; HXXCONST(maxon::PrivateLogNullptrError(false)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.ClassInterface_IsSubclassOf, other));
}
template <typename S, typename REF_> MAXON_ATTRIBUTE_FORCE_INLINE auto ClassInterface::Hxx1::ConstFn<S, REF_>::ToString(const FormatStatement* formatStatement) const -> HXXADDRET2(String)
{
	HXXRETURN0(HXXADDRET2(String)); HXXRES; HXXCONST(maxon::PrivateDefaultReturnValue<String>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.ClassInterface_ToString, formatStatement));
}
template <typename S, typename REF_> MAXON_ATTRIBUTE_FORCE_INLINE auto ClassInterface::Hxx1::ConstFn<S, REF_>::GetMetaData() const -> HXXADDRET2(const DataDictionary&)
{
	HXXRETURN0(HXXADDRET2(const DataDictionary&)); HXXRES; HXXCONST(maxon::PrivateDefaultReturnValue<const DataDictionary&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.ClassInterface_GetMetaData));
}
template <typename S, typename REF_> MAXON_ATTRIBUTE_FORCE_INLINE auto ClassInterface::Hxx1::Fn<S, REF_>::InitMetaData(DataDictionary&& data) const -> HXXADDRET2(void)
{
	HXXRETURN0(HXXADDRET2(void)); HXXRES; HXXNONCONST(DebugStop(), , false, maxon::PrivateLogNullptrError()) 
	PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.ClassInterface_InitMetaData, std::forward<DataDictionary>(data));
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S, typename REF_> MAXON_ATTRIBUTE_FORCE_INLINE auto ClassInterface::Hxx1::ConstFn<S, REF_>::DeleteInstance(const ObjectInterface* object) -> void
{
	return (MTable::_instance.ClassInterface_DeleteInstance(object));
}
template <typename S, typename REF_> MAXON_ATTRIBUTE_FORCE_INLINE auto ClassInterface::Hxx1::ConstFn<S, REF_>::DestructInstance(const ObjectInterface* object) -> void
{
	return (MTable::_instance.ClassInterface_DestructInstance(object));
}
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_objectbase)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_ClassInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_ClassInterface() { new (s_ui_maxon_ClassInterface) maxon::EntityUse(ClassInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/objectbase.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_ClassInterface(ClassInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/objectbase.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
/// @cond INTERNAL

#ifdef MAXON_COMPILER_MSVC
#else
#endif
/// @endcond

#ifndef _HAS_CPP20_COMPARISONS
#endif
/// @cond INTERNAL

/// @endcond


struct ObjectInterface::MTable
{
	PRIVATE_MAXON_IMPLEMENTS_CHECK(Compare);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetHashCodeImpl);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetUniqueHashCodeImpl);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(HandleConstMessage);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(HandleMessage);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(InitObject);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(IsEqual);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(ToString);
	static const maxon::Char* const _ids;
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	PRIVATE_MAXON_MF_POINTER(ObjectInterface_ToString, ToString, true, maxon::GenericComponent, const, (String), const FormatStatement* formatStatement);
	maxon::Int ObjectInterface_ToString_Offset;
	PRIVATE_MAXON_MF_POINTER(ObjectInterface_InitObject, InitObject, true, maxon::GenericComponent,, (Result<void>), const void* argument);
	maxon::Int ObjectInterface_InitObject_Offset;
	PRIVATE_MAXON_MF_POINTER(ObjectInterface_HandleMessage, HandleMessage, true, maxon::GenericComponent,, (Result<void>), const InternedId& message, void* argument);
	maxon::Int ObjectInterface_HandleMessage_Offset;
	PRIVATE_MAXON_MF_POINTER(ObjectInterface_HandleConstMessage, HandleConstMessage, true, maxon::GenericComponent, const, (Result<void>), const InternedId& message, void* argument);
	maxon::Int ObjectInterface_HandleConstMessage_Offset;
	PRIVATE_MAXON_MF_POINTER(ObjectInterface_IsEqual, IsEqual, true, maxon::GenericComponent, const, (Bool), const maxon::ObjectInterface* other);
	maxon::Int ObjectInterface_IsEqual_Offset;
	PRIVATE_MAXON_MF_POINTER(ObjectInterface_Compare, Compare, true, maxon::GenericComponent, const, (COMPARERESULT), const maxon::ObjectInterface* other);
	maxon::Int ObjectInterface_Compare_Offset;
	PRIVATE_MAXON_MF_POINTER(ObjectInterface_GetHashCodeImpl, GetHashCodeImpl, true, maxon::GenericComponent, const, (HashInt));
	maxon::Int ObjectInterface_GetHashCodeImpl_Offset;
	PRIVATE_MAXON_MF_POINTER(ObjectInterface_GetUniqueHashCodeImpl, GetUniqueHashCodeImpl, true, maxon::GenericComponent, const, (UniqueHash));
	maxon::Int ObjectInterface_GetUniqueHashCodeImpl_Offset;
#ifndef _HAS_CPP20_COMPARISONS
#endif
/// @cond INTERNAL

/// @endcond

	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ObjectInterface, ToString))
	{
		maxon::Tie(ObjectInterface_ToString, ObjectInterface_ToString_Offset) = ObjectInterface_ToString_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ObjectInterface, InitObject))
	{
		maxon::Tie(ObjectInterface_InitObject, ObjectInterface_InitObject_Offset) = ObjectInterface_InitObject_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ObjectInterface, HandleMessage))
	{
		maxon::Tie(ObjectInterface_HandleMessage, ObjectInterface_HandleMessage_Offset) = ObjectInterface_HandleMessage_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ObjectInterface, HandleConstMessage))
	{
		maxon::Tie(ObjectInterface_HandleConstMessage, ObjectInterface_HandleConstMessage_Offset) = ObjectInterface_HandleConstMessage_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ObjectInterface, IsEqual))
	{
		maxon::Tie(ObjectInterface_IsEqual, ObjectInterface_IsEqual_Offset) = ObjectInterface_IsEqual_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ObjectInterface, Compare))
	{
		maxon::Tie(ObjectInterface_Compare, ObjectInterface_Compare_Offset) = ObjectInterface_Compare_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ObjectInterface, GetHashCodeImpl))
	{
		maxon::Tie(ObjectInterface_GetHashCodeImpl, ObjectInterface_GetHashCodeImpl_Offset) = ObjectInterface_GetHashCodeImpl_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ObjectInterface, GetUniqueHashCodeImpl))
	{
		maxon::Tie(ObjectInterface_GetUniqueHashCodeImpl, ObjectInterface_GetUniqueHashCodeImpl_Offset) = ObjectInterface_GetUniqueHashCodeImpl_GetPtr<W>(offset, true);
	}
#ifndef _HAS_CPP20_COMPARISONS
#endif
/// @cond INTERNAL

/// @endcond

	}
	template <typename S> using CombinedMTable = maxon::PrivateCombinedMTable<ObjectInterface, S>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<ObjectInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct ObjectInterface::Hxx2
{
	template <typename S> class CWrapper : public S
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(Compare);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetHashCodeImpl);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetUniqueHashCodeImpl);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(HandleConstMessage);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(HandleMessage);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(InitObject);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(IsEqual);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(ToString);
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			auto* vt = (ObjectInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, ObjectInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		PRIVATE_MAXON_MF_WRAPPER(ObjectInterface_ToString, maxon::GenericComponent, const, (String), const FormatStatement* formatStatement) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->ToString(formatStatement); }
		PRIVATE_MAXON_MF_WRAPPER(ObjectInterface_InitObject, maxon::GenericComponent,, (Result<void>), const void* argument) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->InitObject(argument); }
		PRIVATE_MAXON_MF_WRAPPER(ObjectInterface_HandleMessage, maxon::GenericComponent,, (Result<void>), const InternedId& message, void* argument) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->HandleMessage(message, argument); }
		PRIVATE_MAXON_MF_WRAPPER(ObjectInterface_HandleConstMessage, maxon::GenericComponent, const, (Result<void>), const InternedId& message, void* argument) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->HandleConstMessage(message, argument); }
		PRIVATE_MAXON_MF_WRAPPER(ObjectInterface_IsEqual, maxon::GenericComponent, const, (Bool), const maxon::ObjectInterface* other) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->IsEqual(other); }
		PRIVATE_MAXON_MF_WRAPPER(ObjectInterface_Compare, maxon::GenericComponent, const, (COMPARERESULT), const maxon::ObjectInterface* other) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->Compare(other); }
		PRIVATE_MAXON_MF_WRAPPER(ObjectInterface_GetHashCodeImpl, maxon::GenericComponent, const, (HashInt)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetHashCodeImpl(); }
		PRIVATE_MAXON_MF_WRAPPER(ObjectInterface_GetUniqueHashCodeImpl, maxon::GenericComponent, const, (UniqueHash)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetUniqueHashCodeImpl(); }
#ifndef _HAS_CPP20_COMPARISONS
#endif
/// @cond INTERNAL

/// @endcond

	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto ObjectInterface::ToString(const FormatStatement* formatStatement) const -> String
{
	const ObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ObjectInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.ObjectInterface_ToString_Offset), mt_.ObjectInterface_ToString, formatStatement);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ObjectInterface::InitObject(const void* argument) -> Result<void>
{
	const ObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ObjectInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.ObjectInterface_InitObject_Offset), mt_.ObjectInterface_InitObject, argument);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ObjectInterface::HandleMessage(const InternedId& message, void* argument) -> Result<void>
{
	const ObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ObjectInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.ObjectInterface_HandleMessage_Offset), mt_.ObjectInterface_HandleMessage, message, argument);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ObjectInterface::HandleConstMessage(const InternedId& message, void* argument) const -> Result<void>
{
	const ObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ObjectInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.ObjectInterface_HandleConstMessage_Offset), mt_.ObjectInterface_HandleConstMessage, message, argument);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ObjectInterface::IsEqual(const maxon::ObjectInterface* other) const -> Bool
{
	const ObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ObjectInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.ObjectInterface_IsEqual_Offset), mt_.ObjectInterface_IsEqual, other);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ObjectInterface::Compare(const maxon::ObjectInterface* other) const -> COMPARERESULT
{
	const ObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ObjectInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.ObjectInterface_Compare_Offset), mt_.ObjectInterface_Compare, other);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ObjectInterface::GetHashCodeImpl() const -> HashInt
{
	const ObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ObjectInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.ObjectInterface_GetHashCodeImpl_Offset), mt_.ObjectInterface_GetHashCodeImpl);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ObjectInterface::GetUniqueHashCodeImpl() const -> UniqueHash
{
	const ObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ObjectInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.ObjectInterface_GetUniqueHashCodeImpl_Offset), mt_.ObjectInterface_GetUniqueHashCodeImpl);
}
#ifndef _HAS_CPP20_COMPARISONS
#endif
/// @cond INTERNAL

/// @endcond


template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ObjectInterface::Hxx1::ConstFn<S>::GetClass() const -> HXXADDRET2(const maxon::Class<typename S::PrivateErasedReferencedType::Hxx1::ReferenceClass>&)
{
	HXXRETURN0(HXXADDRET2(const maxon::Class<typename S::PrivateErasedReferencedType::Hxx1::ReferenceClass>&)); HXXSUPER("ObjectInterface::GetClass"); HXXRES; HXXCONST(maxon::PrivateDefaultReturnValue<const maxon::Class<typename S::PrivateErasedReferencedType::Hxx1::ReferenceClass>&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK)) 
	return (o_->GetClass<S>());
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ObjectInterface::Hxx1::ConstFn<S>::GetClassInfo() const -> HXXADDRET2(const ClassInfo*)
{
	HXXRETURN0(HXXADDRET2(const ClassInfo*)); HXXSUPER("ObjectInterface::GetClassInfo"); HXXRES; HXXCONST(nullptr) 
	return (o_->GetClassInfo());
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ObjectInterface::Hxx1::ConstFn<S>::HasSameClass(const ObjectInterface* obj) const -> HXXADDRET2(Bool)
{
	HXXRETURN0(HXXADDRET2(Bool)); HXXSUPER("ObjectInterface::HasSameClass"); HXXRES; HXXCONST(maxon::PrivateLogNullptrError(false)) 
	return (o_->HasSameClass(obj));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ObjectInterface::Hxx1::ConstFn<S>::Clone() const -> Result<maxon::details::GetReferenceClass<S>>
{
	HXXRETURN0(Result<maxon::details::GetReferenceClass<S>>); HXXSUPER("ObjectInterface::Clone"); HXXRES; HXXCONST(HXXRET1(NULLPTR)) 
	return (o_->Clone<maxon::details::GetReferenceClass<S>>());
}
template <typename S> template <typename I> MAXON_ATTRIBUTE_FORCE_INLINE auto ObjectInterface::Hxx1::ConstFn<S>::IsInstanceOf() const -> HXXADDRET2(Bool)
{
	HXXRETURN0(HXXADDRET2(Bool)); HXXSUPER("ObjectInterface::IsInstanceOf"); HXXRES; HXXCONST(maxon::PrivateLogNullptrError(false)) 
	return (o_->IsInstanceOf<I>());
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ObjectInterface::Hxx1::ConstFn<S>::IsInstanceOf(const DataType& type) const -> HXXADDRET2(Bool)
{
	HXXRETURN0(HXXADDRET2(Bool)); HXXSUPER("ObjectInterface::IsInstanceOf"); HXXRES; HXXCONST(maxon::PrivateLogNullptrError(false)) 
	return (o_->IsInstanceOf(type));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ObjectInterface::Hxx1::ConstFn<S>::ToString(const FormatStatement* formatStatement) const -> HXXADDRET2(String)
{
	HXXRETURN0(HXXADDRET2(String)); HXXRES; HXXCONST(HXXRET3(NULLPTR, String)) HXXTABLE(ObjectInterface_ToString); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.ObjectInterface_ToString_Offset), mt_.ObjectInterface_ToString, formatStatement));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ObjectInterface::Hxx1::Fn<S>::InitObject(const void* argument) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) HXXTABLE(ObjectInterface_InitObject); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ObjectInterface_InitObject_Offset), mt_.ObjectInterface_InitObject, argument));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ObjectInterface::Hxx1::COWFn<S>::InitObject(const void* argument) -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(ObjectInterface_InitObject); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ObjectInterface_InitObject_Offset), mt_.ObjectInterface_InitObject, argument));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ObjectInterface::Hxx1::Fn<S>::HandleMessage(const InternedId& message, void* argument) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) HXXTABLE(ObjectInterface_HandleMessage); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ObjectInterface_HandleMessage_Offset), mt_.ObjectInterface_HandleMessage, message, argument));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ObjectInterface::Hxx1::COWFn<S>::HandleMessage(const InternedId& message, void* argument) -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(ObjectInterface_HandleMessage); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ObjectInterface_HandleMessage_Offset), mt_.ObjectInterface_HandleMessage, message, argument));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ObjectInterface::Hxx1::ConstFn<S>::HandleConstMessage(const InternedId& message, void* argument) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXCONST(HXXRET1(NULLPTR)) HXXTABLE(ObjectInterface_HandleConstMessage); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.ObjectInterface_HandleConstMessage_Offset), mt_.ObjectInterface_HandleConstMessage, message, argument));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ObjectInterface::Hxx1::ConstFn<S>::IsEqual(const maxon::ObjectInterface* other) const -> HXXADDRET2(Bool)
{
	HXXRETURN0(HXXADDRET2(Bool)); HXXRES; HXXCONST(maxon::PrivateLogNullptrError(false)) HXXTABLE(ObjectInterface_IsEqual); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.ObjectInterface_IsEqual_Offset), mt_.ObjectInterface_IsEqual, other));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ObjectInterface::Hxx1::ConstFn<S>::Compare(const maxon::ObjectInterface* other) const -> HXXADDRET2(COMPARERESULT)
{
	HXXRETURN0(HXXADDRET2(COMPARERESULT)); HXXRES; HXXCONST(HXXRET3(NULLPTR, COMPARERESULT)) HXXTABLE(ObjectInterface_Compare); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.ObjectInterface_Compare_Offset), mt_.ObjectInterface_Compare, other));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ObjectInterface::Hxx1::ConstFn<S>::GetHashCodeImpl() const -> HXXADDRET2(HashInt)
{
	HXXRETURN0(HXXADDRET2(HashInt)); HXXRES; HXXCONST(HXXRET3(NULLPTR, HashInt)) HXXTABLE(ObjectInterface_GetHashCodeImpl); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.ObjectInterface_GetHashCodeImpl_Offset), mt_.ObjectInterface_GetHashCodeImpl));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ObjectInterface::Hxx1::ConstFn<S>::GetUniqueHashCodeImpl() const -> HXXADDRET2(UniqueHash)
{
	HXXRETURN0(HXXADDRET2(UniqueHash)); HXXRES; HXXCONST(HXXRET3(NULLPTR, UniqueHash)) HXXTABLE(ObjectInterface_GetUniqueHashCodeImpl); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.ObjectInterface_GetUniqueHashCodeImpl_Offset), mt_.ObjectInterface_GetUniqueHashCodeImpl));
}
#ifndef _HAS_CPP20_COMPARISONS
#endif
/// @cond INTERNAL

/// @endcond

auto ObjectInterface::GetPtr() -> Ptr { return Ptr(this); }
auto ObjectInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_objectbase)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_ObjectInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_ObjectInterface() { new (s_ui_maxon_ObjectInterface) maxon::EntityUse(ObjectInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/objectbase.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_ObjectInterface(ObjectInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/objectbase.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
/// @cond INTERNAL

#ifdef MAXON_TARGET_DEBUG
#else
#endif
#ifndef MAXON_COMPONENT_HASHTABLE
#elif defined(MAXON_TARGET_DEBUG)
#else
#endif
/// @endcond


struct ErrorInterface::MTable
{
	PRIVATE_MAXON_IMPLEMENTS_CHECK(FormatMessage);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetCause);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetLocation);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetMachine);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetMessage);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetStackTrace);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(PrivateGetCode);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(PrivateGetPreallocation);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(PrivateSetCode);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(PrivateSetDebugError);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(PrivateSetPreallocation);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(SetCause);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(SetLocation);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(SetMachine);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(SetMessage);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(SetMessageDelegate);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(SetStackTrace);
	static const maxon::Char* const _ids;
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	PRIVATE_MAXON_MF_POINTER(ErrorInterface_GetLocation, GetLocation, true, maxon::GenericComponent, const, (const SourceLocation&));
	maxon::Int ErrorInterface_GetLocation_Offset;
	PRIVATE_MAXON_MF_POINTER(ErrorInterface_SetLocation, SetLocation, true, maxon::GenericComponent,, (void), const maxon::SourceLocation& allocLocation);
	maxon::Int ErrorInterface_SetLocation_Offset;
	PRIVATE_MAXON_MF_POINTER(ErrorInterface_GetStackTrace, GetStackTrace, true, maxon::GenericComponent, const, (Block<void* const>));
	maxon::Int ErrorInterface_GetStackTrace_Offset;
	PRIVATE_MAXON_MF_POINTER(ErrorInterface_SetStackTrace, SetStackTrace, true, maxon::GenericComponent,, (void), const Block<void* const>& trace);
	maxon::Int ErrorInterface_SetStackTrace_Offset;
	PRIVATE_MAXON_MF_POINTER(ErrorInterface_GetMessage, GetMessage, true, maxon::GenericComponent, const, (String));
	maxon::Int ErrorInterface_GetMessage_Offset;
	PRIVATE_MAXON_MF_POINTER(ErrorInterface_SetMessage, SetMessage, true, maxon::GenericComponent,, (void), const String& message);
	maxon::Int ErrorInterface_SetMessage_Offset;
	PRIVATE_MAXON_MF_POINTER(ErrorInterface_FormatMessage, FormatMessage, true, maxon::GenericComponent, const, (String), const LanguageRef& language, const PartFormatter& partFormatter);
	maxon::Int ErrorInterface_FormatMessage_Offset;
	PRIVATE_MAXON_MF_POINTER(ErrorInterface_SetMessageDelegate, SetMessageDelegate, true, maxon::GenericComponent,, (void), Delegate<String(const LanguageRef&language,const ErrorInterface::PartFormatter&fmt)>&& message);
	maxon::Int ErrorInterface_SetMessageDelegate_Offset;
	PRIVATE_MAXON_MF_POINTER(ErrorInterface_GetCause, GetCause, true, maxon::GenericComponent, const, (const Error&));
	maxon::Int ErrorInterface_GetCause_Offset;
	PRIVATE_MAXON_MF_POINTER(ErrorInterface_SetCause, SetCause, true, maxon::GenericComponent,, (void), const Error& cause);
	maxon::Int ErrorInterface_SetCause_Offset;
	PRIVATE_MAXON_MF_POINTER(ErrorInterface_GetMachine, GetMachine, true, maxon::GenericComponent, const, (void), MachineRef& machine);
	maxon::Int ErrorInterface_GetMachine_Offset;
	PRIVATE_MAXON_MF_POINTER(ErrorInterface_SetMachine, SetMachine, true, maxon::GenericComponent,, (void), const MachineRef& machine);
	maxon::Int ErrorInterface_SetMachine_Offset;
	PRIVATE_MAXON_MF_POINTER(ErrorInterface_PrivateGetCode, PrivateGetCode, true, maxon::GenericComponent, const, (Int));
	maxon::Int ErrorInterface_PrivateGetCode_Offset;
	PRIVATE_MAXON_MF_POINTER(ErrorInterface_PrivateSetCode, PrivateSetCode, true, maxon::GenericComponent,, (void), Int code);
	maxon::Int ErrorInterface_PrivateSetCode_Offset;
	PRIVATE_MAXON_MF_POINTER(ErrorInterface_PrivateSetPreallocation, PrivateSetPreallocation, true, maxon::GenericComponent, const, (void), ThreadReferencedError preallocation);
	maxon::Int ErrorInterface_PrivateSetPreallocation_Offset;
	PRIVATE_MAXON_MF_POINTER(ErrorInterface_PrivateGetPreallocation, PrivateGetPreallocation, true, maxon::GenericComponent, const, (ThreadReferencedError));
	maxon::Int ErrorInterface_PrivateGetPreallocation_Offset;
	PRIVATE_MAXON_MF_POINTER(ErrorInterface_PrivateSetDebugError, PrivateSetDebugError, true, maxon::GenericComponent, const, (void), const Error& cause);
	maxon::Int ErrorInterface_PrivateSetDebugError_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ErrorInterface, GetLocation))
	{
		maxon::Tie(ErrorInterface_GetLocation, ErrorInterface_GetLocation_Offset) = ErrorInterface_GetLocation_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ErrorInterface, SetLocation))
	{
		maxon::Tie(ErrorInterface_SetLocation, ErrorInterface_SetLocation_Offset) = ErrorInterface_SetLocation_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ErrorInterface, GetStackTrace))
	{
		maxon::Tie(ErrorInterface_GetStackTrace, ErrorInterface_GetStackTrace_Offset) = ErrorInterface_GetStackTrace_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ErrorInterface, SetStackTrace))
	{
		maxon::Tie(ErrorInterface_SetStackTrace, ErrorInterface_SetStackTrace_Offset) = ErrorInterface_SetStackTrace_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ErrorInterface, GetMessage))
	{
		maxon::Tie(ErrorInterface_GetMessage, ErrorInterface_GetMessage_Offset) = ErrorInterface_GetMessage_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ErrorInterface, SetMessage))
	{
		maxon::Tie(ErrorInterface_SetMessage, ErrorInterface_SetMessage_Offset) = ErrorInterface_SetMessage_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ErrorInterface, FormatMessage))
	{
		maxon::Tie(ErrorInterface_FormatMessage, ErrorInterface_FormatMessage_Offset) = ErrorInterface_FormatMessage_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ErrorInterface, SetMessageDelegate))
	{
		maxon::Tie(ErrorInterface_SetMessageDelegate, ErrorInterface_SetMessageDelegate_Offset) = ErrorInterface_SetMessageDelegate_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ErrorInterface, GetCause))
	{
		maxon::Tie(ErrorInterface_GetCause, ErrorInterface_GetCause_Offset) = ErrorInterface_GetCause_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ErrorInterface, SetCause))
	{
		maxon::Tie(ErrorInterface_SetCause, ErrorInterface_SetCause_Offset) = ErrorInterface_SetCause_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ErrorInterface, GetMachine))
	{
		maxon::Tie(ErrorInterface_GetMachine, ErrorInterface_GetMachine_Offset) = ErrorInterface_GetMachine_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ErrorInterface, SetMachine))
	{
		maxon::Tie(ErrorInterface_SetMachine, ErrorInterface_SetMachine_Offset) = ErrorInterface_SetMachine_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ErrorInterface, PrivateGetCode))
	{
		maxon::Tie(ErrorInterface_PrivateGetCode, ErrorInterface_PrivateGetCode_Offset) = ErrorInterface_PrivateGetCode_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ErrorInterface, PrivateSetCode))
	{
		maxon::Tie(ErrorInterface_PrivateSetCode, ErrorInterface_PrivateSetCode_Offset) = ErrorInterface_PrivateSetCode_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ErrorInterface, PrivateSetPreallocation))
	{
		maxon::Tie(ErrorInterface_PrivateSetPreallocation, ErrorInterface_PrivateSetPreallocation_Offset) = ErrorInterface_PrivateSetPreallocation_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ErrorInterface, PrivateGetPreallocation))
	{
		maxon::Tie(ErrorInterface_PrivateGetPreallocation, ErrorInterface_PrivateGetPreallocation_Offset) = ErrorInterface_PrivateGetPreallocation_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ErrorInterface, PrivateSetDebugError))
	{
		maxon::Tie(ErrorInterface_PrivateSetDebugError, ErrorInterface_PrivateSetDebugError_Offset) = ErrorInterface_PrivateSetDebugError_GetPtr<W>(offset, true);
	}
	}
	template <typename S> using CombinedMTable = maxon::PrivateCombinedMTable<ErrorInterface, typename ObjectInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<ErrorInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct ErrorInterface::Hxx2
{
	template <typename S> class CWrapper : public ObjectInterface::Hxx2::template CWrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(FormatMessage);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetCause);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetLocation);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetMachine);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetMessage);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetStackTrace);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(PrivateGetCode);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(PrivateGetPreallocation);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(PrivateSetCode);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(PrivateSetDebugError);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(PrivateSetPreallocation);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(SetCause);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(SetLocation);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(SetMachine);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(SetMessage);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(SetMessageDelegate);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(SetStackTrace);
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename ObjectInterface::Hxx2::template CWrapper<S>;
			if constexpr (!S::Implementation::PROXY)
			{
				if (!(Super0::InitMTablesWithBases(info, offset))) return false;
			}
			auto* vt = (ErrorInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, ErrorInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		PRIVATE_MAXON_MF_WRAPPER(ErrorInterface_GetLocation, maxon::GenericComponent, const, (const SourceLocation&)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetLocation(); }
		PRIVATE_MAXON_MF_WRAPPER(ErrorInterface_SetLocation, maxon::GenericComponent,, (void), const maxon::SourceLocation& allocLocation) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->SetLocation(allocLocation); }
		PRIVATE_MAXON_MF_WRAPPER(ErrorInterface_GetStackTrace, maxon::GenericComponent, const, (Block<void* const>)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetStackTrace(); }
		PRIVATE_MAXON_MF_WRAPPER(ErrorInterface_SetStackTrace, maxon::GenericComponent,, (void), const Block<void* const>& trace) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->SetStackTrace(trace); }
		PRIVATE_MAXON_MF_WRAPPER(ErrorInterface_GetMessage, maxon::GenericComponent, const, (String)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetMessage(); }
		PRIVATE_MAXON_MF_WRAPPER(ErrorInterface_SetMessage, maxon::GenericComponent,, (void), const String& message) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->SetMessage(message); }
		PRIVATE_MAXON_MF_WRAPPER(ErrorInterface_FormatMessage, maxon::GenericComponent, const, (String), const LanguageRef& language, const PartFormatter& partFormatter) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->FormatMessage(language, partFormatter); }
		PRIVATE_MAXON_MF_WRAPPER(ErrorInterface_SetMessageDelegate, maxon::GenericComponent,, (void), Delegate<String(const LanguageRef&language,const ErrorInterface::PartFormatter&fmt)>&& message) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->SetMessageDelegate(std::forward<Delegate<String(const LanguageRef&language,const ErrorInterface::PartFormatter&fmt)>>(message)); }
		PRIVATE_MAXON_MF_WRAPPER(ErrorInterface_GetCause, maxon::GenericComponent, const, (const Error&)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetCause(); }
		PRIVATE_MAXON_MF_WRAPPER(ErrorInterface_SetCause, maxon::GenericComponent,, (void), const Error& cause) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->SetCause(cause); }
		PRIVATE_MAXON_MF_WRAPPER(ErrorInterface_GetMachine, maxon::GenericComponent, const, (void), MachineRef& machine) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetMachine(machine); }
		PRIVATE_MAXON_MF_WRAPPER(ErrorInterface_SetMachine, maxon::GenericComponent,, (void), const MachineRef& machine) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->SetMachine(machine); }
		PRIVATE_MAXON_MF_WRAPPER(ErrorInterface_PrivateGetCode, maxon::GenericComponent, const, (Int)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->PrivateGetCode(); }
		PRIVATE_MAXON_MF_WRAPPER(ErrorInterface_PrivateSetCode, maxon::GenericComponent,, (void), Int code) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->PrivateSetCode(code); }
		PRIVATE_MAXON_MF_WRAPPER(ErrorInterface_PrivateSetPreallocation, maxon::GenericComponent, const, (void), ThreadReferencedError preallocation) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->PrivateSetPreallocation(std::forward<ThreadReferencedError>(preallocation)); }
		PRIVATE_MAXON_MF_WRAPPER(ErrorInterface_PrivateGetPreallocation, maxon::GenericComponent, const, (ThreadReferencedError)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->PrivateGetPreallocation(); }
		PRIVATE_MAXON_MF_WRAPPER(ErrorInterface_PrivateSetDebugError, maxon::GenericComponent, const, (void), const Error& cause) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->PrivateSetDebugError(cause); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::GetLocation() const -> const SourceLocation&
{
	const ErrorInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ErrorInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.ErrorInterface_GetLocation_Offset), mt_.ErrorInterface_GetLocation);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::SetLocation(const maxon::SourceLocation& allocLocation) -> void
{
	const ErrorInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ErrorInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.ErrorInterface_SetLocation_Offset), mt_.ErrorInterface_SetLocation, allocLocation);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::GetStackTrace() const -> Block<void* const>
{
	const ErrorInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ErrorInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.ErrorInterface_GetStackTrace_Offset), mt_.ErrorInterface_GetStackTrace);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::SetStackTrace(const Block<void* const>& trace) -> void
{
	const ErrorInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ErrorInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.ErrorInterface_SetStackTrace_Offset), mt_.ErrorInterface_SetStackTrace, trace);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::GetMessage() const -> String
{
	const ErrorInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ErrorInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.ErrorInterface_GetMessage_Offset), mt_.ErrorInterface_GetMessage);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::SetMessage(const String& message) -> void
{
	const ErrorInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ErrorInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.ErrorInterface_SetMessage_Offset), mt_.ErrorInterface_SetMessage, message);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::FormatMessage(const LanguageRef& language, const PartFormatter& partFormatter) const -> String
{
	const ErrorInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ErrorInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.ErrorInterface_FormatMessage_Offset), mt_.ErrorInterface_FormatMessage, language, partFormatter);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::SetMessageDelegate(Delegate<String(const LanguageRef&language,const ErrorInterface::PartFormatter&fmt)>&& message) -> void
{
	const ErrorInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ErrorInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.ErrorInterface_SetMessageDelegate_Offset), mt_.ErrorInterface_SetMessageDelegate, std::forward<Delegate<String(const LanguageRef&language,const ErrorInterface::PartFormatter&fmt)>>(message));
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::GetCause() const -> const Error&
{
	const ErrorInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ErrorInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.ErrorInterface_GetCause_Offset), mt_.ErrorInterface_GetCause);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::SetCause(const Error& cause) -> void
{
	const ErrorInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ErrorInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.ErrorInterface_SetCause_Offset), mt_.ErrorInterface_SetCause, cause);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::GetMachine(MachineRef& machine) const -> void
{
	const ErrorInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ErrorInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.ErrorInterface_GetMachine_Offset), mt_.ErrorInterface_GetMachine, machine);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::SetMachine(const MachineRef& machine) -> void
{
	const ErrorInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ErrorInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.ErrorInterface_SetMachine_Offset), mt_.ErrorInterface_SetMachine, machine);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::PrivateGetCode() const -> Int
{
	const ErrorInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ErrorInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.ErrorInterface_PrivateGetCode_Offset), mt_.ErrorInterface_PrivateGetCode);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::PrivateSetCode(Int code) -> void
{
	const ErrorInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ErrorInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.ErrorInterface_PrivateSetCode_Offset), mt_.ErrorInterface_PrivateSetCode, code);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::PrivateSetPreallocation(ThreadReferencedError preallocation) const -> void
{
	const ErrorInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ErrorInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.ErrorInterface_PrivateSetPreallocation_Offset), mt_.ErrorInterface_PrivateSetPreallocation, std::forward<ThreadReferencedError>(preallocation));
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::PrivateGetPreallocation() const -> ThreadReferencedError
{
	const ErrorInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ErrorInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.ErrorInterface_PrivateGetPreallocation_Offset), mt_.ErrorInterface_PrivateGetPreallocation);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::PrivateSetDebugError(const Error& cause) const -> void
{
	const ErrorInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ErrorInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.ErrorInterface_PrivateSetDebugError_Offset), mt_.ErrorInterface_PrivateSetDebugError, cause);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::Hxx1::ConstFn<S>::GetLocation() const -> HXXADDRET2(const SourceLocation&)
{
	HXXRETURN0(HXXADDRET2(const SourceLocation&)); HXXRES; HXXCONST(HXXRET3(NULLPTR, const SourceLocation&)) HXXTABLE(ErrorInterface_GetLocation); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.ErrorInterface_GetLocation_Offset), mt_.ErrorInterface_GetLocation));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::Hxx1::Fn<S>::SetLocation(const maxon::SourceLocation& allocLocation) const -> DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S)
{
	HXXNORES("ErrorInterface::SetLocation"); HXXNONCONST(DebugStop(), , false, this->PrivateGetRefMember()) HXXTABLE(ErrorInterface_SetLocation); 
	PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ErrorInterface_SetLocation_Offset), mt_.ErrorInterface_SetLocation, allocLocation);
	return this->PrivateGetRefMember();
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::Hxx1::COWFn<S>::SetLocation(const maxon::SourceLocation& allocLocation) -> DOXYGEN_SWITCH(maxon::RefMemberType<S>, S)
{
	HXXNORES("ErrorInterface::SetLocation"); HXXNONCONST(, MakeWritable(false)., true, this->PrivateGetRefMember()) HXXTABLE(ErrorInterface_SetLocation); 
	PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ErrorInterface_SetLocation_Offset), mt_.ErrorInterface_SetLocation, allocLocation);
	return this->PrivateGetRefMember();
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::Hxx1::ConstFn<S>::GetStackTrace() const -> HXXADDRET2(Block<void* const>)
{
	HXXRETURN0(HXXADDRET2(Block<void* const>)); HXXRES; HXXCONST(HXXRET3(NULLPTR, Block<void* const>)) HXXTABLE(ErrorInterface_GetStackTrace); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.ErrorInterface_GetStackTrace_Offset), mt_.ErrorInterface_GetStackTrace));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::Hxx1::Fn<S>::SetStackTrace(const Block<void* const>& trace) const -> DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S)
{
	HXXNORES("ErrorInterface::SetStackTrace"); HXXNONCONST(DebugStop(), , false, this->PrivateGetRefMember()) HXXTABLE(ErrorInterface_SetStackTrace); 
	PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ErrorInterface_SetStackTrace_Offset), mt_.ErrorInterface_SetStackTrace, trace);
	return this->PrivateGetRefMember();
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::Hxx1::COWFn<S>::SetStackTrace(const Block<void* const>& trace) -> DOXYGEN_SWITCH(maxon::RefMemberType<S>, S)
{
	HXXNORES("ErrorInterface::SetStackTrace"); HXXNONCONST(, MakeWritable(false)., true, this->PrivateGetRefMember()) HXXTABLE(ErrorInterface_SetStackTrace); 
	PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ErrorInterface_SetStackTrace_Offset), mt_.ErrorInterface_SetStackTrace, trace);
	return this->PrivateGetRefMember();
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::Hxx1::Fn<S>::SetStackTrace(Int skip) const -> DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S)
{
	HXXNORES("ErrorInterface::SetStackTrace"); HXXNONCONST(DebugStop(), , false, this->PrivateGetRefMember()) 
	o_->SetStackTrace(skip);
	return this->PrivateGetRefMember();
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::Hxx1::COWFn<S>::SetStackTrace(Int skip) -> DOXYGEN_SWITCH(maxon::RefMemberType<S>, S)
{
	HXXSUPER("ErrorInterface::SetStackTrace"); HXXNORES("ErrorInterface::SetStackTrace"); HXXNONCONST(, MakeWritable(false)., true, this->PrivateGetRefMember()) 
	o_->SetStackTrace(skip);
	return this->PrivateGetRefMember();
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::Hxx1::ConstFn<S>::IsCancellation() const -> HXXADDRET2(Bool)
{
	HXXRETURN0(HXXADDRET2(Bool)); HXXSUPER("ErrorInterface::IsCancellation"); HXXRES; HXXCONST(maxon::PrivateLogNullptrError(false)) 
	return (o_->IsCancellation());
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::Hxx1::ConstFn<S>::GetMessage() const -> HXXADDRET2(String)
{
	HXXRETURN0(HXXADDRET2(String)); HXXRES; HXXCONST(HXXRET3(NULLPTR, String)) HXXTABLE(ErrorInterface_GetMessage); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.ErrorInterface_GetMessage_Offset), mt_.ErrorInterface_GetMessage));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::Hxx1::Fn<S>::SetMessage(const String& message) const -> DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S)
{
	HXXNORES("ErrorInterface::SetMessage"); HXXNONCONST(DebugStop(), , false, this->PrivateGetRefMember()) HXXTABLE(ErrorInterface_SetMessage); 
	PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ErrorInterface_SetMessage_Offset), mt_.ErrorInterface_SetMessage, message);
	return this->PrivateGetRefMember();
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::Hxx1::COWFn<S>::SetMessage(const String& message) -> DOXYGEN_SWITCH(maxon::RefMemberType<S>, S)
{
	HXXNORES("ErrorInterface::SetMessage"); HXXNONCONST(, MakeWritable(false)., true, this->PrivateGetRefMember()) HXXTABLE(ErrorInterface_SetMessage); 
	PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ErrorInterface_SetMessage_Offset), mt_.ErrorInterface_SetMessage, message);
	return this->PrivateGetRefMember();
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::Hxx1::ConstFn<S>::FormatMessage(const LanguageRef& language, const PartFormatter& partFormatter) const -> HXXADDRET2(String)
{
	HXXRETURN0(HXXADDRET2(String)); HXXRES; HXXCONST(HXXRET3(NULLPTR, String)) HXXTABLE(ErrorInterface_FormatMessage); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.ErrorInterface_FormatMessage_Offset), mt_.ErrorInterface_FormatMessage, language, partFormatter));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::Hxx1::Fn<S>::SetMessageDelegate(Delegate<String(const LanguageRef&language,const ErrorInterface::PartFormatter&fmt)>&& message) const -> DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S)
{
	HXXNORES("ErrorInterface::SetMessageDelegate"); HXXNONCONST(DebugStop(), , false, this->PrivateGetRefMember()) HXXTABLE(ErrorInterface_SetMessageDelegate); 
	PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ErrorInterface_SetMessageDelegate_Offset), mt_.ErrorInterface_SetMessageDelegate, std::forward<Delegate<String(const LanguageRef&language,const ErrorInterface::PartFormatter&fmt)>>(message));
	return this->PrivateGetRefMember();
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::Hxx1::COWFn<S>::SetMessageDelegate(Delegate<String(const LanguageRef&language,const ErrorInterface::PartFormatter&fmt)>&& message) -> DOXYGEN_SWITCH(maxon::RefMemberType<S>, S)
{
	HXXNORES("ErrorInterface::SetMessageDelegate"); HXXNONCONST(, MakeWritable(false)., true, this->PrivateGetRefMember()) HXXTABLE(ErrorInterface_SetMessageDelegate); 
	PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ErrorInterface_SetMessageDelegate_Offset), mt_.ErrorInterface_SetMessageDelegate, std::forward<Delegate<String(const LanguageRef&language,const ErrorInterface::PartFormatter&fmt)>>(message));
	return this->PrivateGetRefMember();
}
template <typename S> template <typename T> MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::Hxx1::ConstFn<S>::FormatPart(const LanguageRef& language, const ErrorInterface::PartFormatter& fmt, const T& part) -> String
{
	return (ErrorInterface::template FormatPart<T>(language, fmt, part));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::Hxx1::ConstFn<S>::GetCause() const -> HXXADDRET2(const Error&)
{
	HXXRETURN0(HXXADDRET2(const Error&)); HXXRES; HXXCONST(HXXRET3(NULLPTR, const Error&)) HXXTABLE(ErrorInterface_GetCause); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.ErrorInterface_GetCause_Offset), mt_.ErrorInterface_GetCause));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::Hxx1::Fn<S>::SetCause(const Error& cause) const -> DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S)
{
	HXXNORES("ErrorInterface::SetCause"); HXXNONCONST(DebugStop(), , false, this->PrivateGetRefMember()) HXXTABLE(ErrorInterface_SetCause); 
	PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ErrorInterface_SetCause_Offset), mt_.ErrorInterface_SetCause, cause);
	return this->PrivateGetRefMember();
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::Hxx1::COWFn<S>::SetCause(const Error& cause) -> DOXYGEN_SWITCH(maxon::RefMemberType<S>, S)
{
	HXXNORES("ErrorInterface::SetCause"); HXXNONCONST(, MakeWritable(false)., true, this->PrivateGetRefMember()) HXXTABLE(ErrorInterface_SetCause); 
	PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ErrorInterface_SetCause_Offset), mt_.ErrorInterface_SetCause, cause);
	return this->PrivateGetRefMember();
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::Hxx1::ConstFn<S>::GetMachine(MachineRef& machine) const -> HXXADDRET2(void)
{
	HXXRETURN0(HXXADDRET2(void)); HXXRES; HXXCONST(maxon::PrivateLogNullptrError()) HXXTABLE(ErrorInterface_GetMachine); 
	PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.ErrorInterface_GetMachine_Offset), mt_.ErrorInterface_GetMachine, machine);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::Hxx1::Fn<S>::SetMachine(const MachineRef& machine) const -> HXXADDRET2(void)
{
	HXXRETURN0(HXXADDRET2(void)); HXXRES; HXXNONCONST(DebugStop(), , false, maxon::PrivateLogNullptrError()) HXXTABLE(ErrorInterface_SetMachine); 
	PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ErrorInterface_SetMachine_Offset), mt_.ErrorInterface_SetMachine, machine);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::Hxx1::COWFn<S>::SetMachine(const MachineRef& machine) -> HXXADDRET1(void)
{
	HXXRETURN0(HXXADDRET1(void)); HXXRES; HXXNONCONST(, MakeWritable(false)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(ErrorInterface_SetMachine); 
	PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ErrorInterface_SetMachine_Offset), mt_.ErrorInterface_SetMachine, machine);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::Hxx1::ConstFn<S>::PrivateGetCode() const -> HXXADDRET2(Int)
{
	HXXRETURN0(HXXADDRET2(Int)); HXXRES; HXXCONST(0) HXXTABLE(ErrorInterface_PrivateGetCode); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.ErrorInterface_PrivateGetCode_Offset), mt_.ErrorInterface_PrivateGetCode));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::Hxx1::Fn<S>::PrivateSetCode(Int code) const -> DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S)
{
	HXXNORES("ErrorInterface::PrivateSetCode"); HXXNONCONST(DebugStop(), , false, this->PrivateGetRefMember()) HXXTABLE(ErrorInterface_PrivateSetCode); 
	PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ErrorInterface_PrivateSetCode_Offset), mt_.ErrorInterface_PrivateSetCode, code);
	return this->PrivateGetRefMember();
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::Hxx1::COWFn<S>::PrivateSetCode(Int code) -> DOXYGEN_SWITCH(maxon::RefMemberType<S>, S)
{
	HXXNORES("ErrorInterface::PrivateSetCode"); HXXNONCONST(, MakeWritable(false)., true, this->PrivateGetRefMember()) HXXTABLE(ErrorInterface_PrivateSetCode); 
	PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ErrorInterface_PrivateSetCode_Offset), mt_.ErrorInterface_PrivateSetCode, code);
	return this->PrivateGetRefMember();
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::Hxx1::ConstFn<S>::PrivateSetPreallocation(ThreadReferencedError preallocation) const -> HXXADDRET2(void)
{
	HXXRETURN0(HXXADDRET2(void)); HXXRES; HXXCONST(maxon::PrivateLogNullptrError()) HXXTABLE(ErrorInterface_PrivateSetPreallocation); 
	PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.ErrorInterface_PrivateSetPreallocation_Offset), mt_.ErrorInterface_PrivateSetPreallocation, std::forward<ThreadReferencedError>(preallocation));
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::Hxx1::ConstFn<S>::PrivateGetPreallocation() const -> HXXADDRET2(ThreadReferencedError)
{
	HXXRETURN0(HXXADDRET2(ThreadReferencedError)); HXXRES; HXXCONST(HXXRET3(NULLPTR, ThreadReferencedError)) HXXTABLE(ErrorInterface_PrivateGetPreallocation); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.ErrorInterface_PrivateGetPreallocation_Offset), mt_.ErrorInterface_PrivateGetPreallocation));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::Hxx1::ConstFn<S>::PrivateSetDebugError(const Error& cause) const -> HXXADDRET2(void)
{
	HXXRETURN0(HXXADDRET2(void)); HXXRES; HXXCONST(maxon::PrivateLogNullptrError()) HXXTABLE(ErrorInterface_PrivateSetDebugError); 
	PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.ErrorInterface_PrivateSetDebugError_Offset), mt_.ErrorInterface_PrivateSetDebugError, cause);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
auto ErrorInterface::GetPtr() -> Ptr { return Ptr(this); }
auto ErrorInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_objectbase)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_ErrorInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_ErrorInterface() { new (s_ui_maxon_ErrorInterface) maxon::EntityUse(ErrorInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/objectbase.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_ErrorInterface(ErrorInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/objectbase.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_NO_OBJECT_IMPL_DEPENDENCY)
#endif
/// @cond INTERNAL

/// @endcond

namespace details
{
#ifdef MAXON_TARGET_MACOS
#endif
}
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

