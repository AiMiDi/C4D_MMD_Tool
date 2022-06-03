
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
	static const maxon::NULL_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = true;
	void (*ClassInterface_Free) (const ClassInterface* object);
	ClassInterface* (*ClassInterface_Alloc) (const maxon::SourceLocation& allocLocation, const Id& cid, KIND kind);
	const Id& (*ClassInterface_GetId) (const ClassInterface* this_);
	KIND (*ClassInterface_GetKind) (const ClassInterface* this_);
	Int (*ClassInterface_GetSize) (const ClassInterface* this_);
	Block<const ComponentInfo* const> (*ClassInterface_GetComponents) (const ClassInterface* this_);
	Result<void> (*ClassInterface_AddComponent) (ClassInterface* this_, const ComponentDescriptor& component);
	void (*ClassInterface_RemoveLastComponent) (ClassInterface* this_);
	Result<void> (*ClassInterface_AddComponents) (ClassInterface* this_, const Class<>& cls);
	Result<void> (*ClassInterface_Finalize) (ClassInterface* this_);
	Bool (*ClassInterface_IsFinalized) (const ClassInterface* this_);
	const Block<const InterfaceReference* const>& (*ClassInterface_GetImplementedInterfaces) (const ClassInterface* this_);
	const DataType& (*ClassInterface_GetDataType) (const ClassInterface* this_);
	Result<typename maxon::details::ClassGetNonConst<REF>::type> (*ClassInterface_Create) (const ClassInterface* this_);
	Result<ObjectInterface*> (*ClassInterface_CreatePointer) (const ClassInterface* this_);
	Result<ObjectInterface*> (*ClassInterface_CreatePointer_1) (const ClassInterface* this_, Int size);
	Bool (*ClassInterface_IsSubclassOf) (const ClassInterface* this_, const Class<>& other);
	String (*ClassInterface_ToString) (const ClassInterface* this_, const FormatStatement* formatStatement);
	const DataDictionary& (*ClassInterface_GetMetaData) (const ClassInterface* this_);
	void (*ClassInterface_InitMetaData) (ClassInterface* this_, DataDictionary&& data);
	void (*ClassInterface_DeleteInstance) (const ObjectInterface* object);
	void (*ClassInterface_DestructInstance) (const ObjectInterface* object);
	Result<void> (*ClassInterface_CopyInstance) (ObjectInterface* dest, const ObjectInterface* src);
	const ClassInfo* (*ClassInterface_GetInfo) (const ClassInterface* this_);
	void* (*ClassInterface_GetOrCreateMTable) (ClassInfo* info, const InterfaceReference& i);
	Result<Int> (*ClassInterface_AddProxyComponent) (ClassInterface* this_, const ComponentDescriptor& component, Bool shared);
	template <typename IMPL> void Init()
	{
		ClassInterface_Free = &IMPL::ClassInterface_Free;
		ClassInterface_Alloc = &IMPL::ClassInterface_Alloc;
		ClassInterface_GetId = &IMPL::ClassInterface_GetId;
		ClassInterface_GetKind = &IMPL::ClassInterface_GetKind;
		ClassInterface_GetSize = &IMPL::ClassInterface_GetSize;
		ClassInterface_GetComponents = &IMPL::ClassInterface_GetComponents;
		ClassInterface_AddComponent = &IMPL::ClassInterface_AddComponent;
		ClassInterface_RemoveLastComponent = &IMPL::ClassInterface_RemoveLastComponent;
		ClassInterface_AddComponents = &IMPL::ClassInterface_AddComponents;
		ClassInterface_Finalize = &IMPL::ClassInterface_Finalize;
		ClassInterface_IsFinalized = &IMPL::ClassInterface_IsFinalized;
		ClassInterface_GetImplementedInterfaces = &IMPL::ClassInterface_GetImplementedInterfaces;
		ClassInterface_GetDataType = &IMPL::ClassInterface_GetDataType;
		ClassInterface_Create = &IMPL::ClassInterface_Create;
		ClassInterface_CreatePointer = &IMPL::ClassInterface_CreatePointer;
		ClassInterface_CreatePointer_1 = &IMPL::ClassInterface_CreatePointer_1;
		ClassInterface_IsSubclassOf = &IMPL::ClassInterface_IsSubclassOf;
		ClassInterface_ToString = &IMPL::ClassInterface_ToString;
		ClassInterface_GetMetaData = &IMPL::ClassInterface_GetMetaData;
		ClassInterface_InitMetaData = &IMPL::ClassInterface_InitMetaData;
		ClassInterface_DeleteInstance = &IMPL::ClassInterface_DeleteInstance;
		ClassInterface_DestructInstance = &IMPL::ClassInterface_DestructInstance;
		ClassInterface_CopyInstance = &IMPL::ClassInterface_CopyInstance;
		ClassInterface_GetInfo = &IMPL::ClassInterface_GetInfo;
		ClassInterface_GetOrCreateMTable = &IMPL::ClassInterface_GetOrCreateMTable;
		ClassInterface_AddProxyComponent = &IMPL::ClassInterface_AddProxyComponent;
	}
};

struct ClassInterface::Hxx2
{
	class Unresolved;
	template <typename C> class Wrapper
	{
	public:
		static void ClassInterface_Free(const ClassInterface* object) { return C::Free(object); }
		static ClassInterface* ClassInterface_Alloc(const maxon::SourceLocation& allocLocation, const Id& cid, KIND kind) { return C::Alloc(allocLocation, cid, kind); }
		static const Id& ClassInterface_GetId(const ClassInterface* this_) { return C::Get(this_)->GetId(); }
		static KIND ClassInterface_GetKind(const ClassInterface* this_) { return C::Get(this_)->GetKind(); }
		static Int ClassInterface_GetSize(const ClassInterface* this_) { return C::Get(this_)->GetSize(); }
		static Block<const ComponentInfo* const> ClassInterface_GetComponents(const ClassInterface* this_) { return C::Get(this_)->GetComponents(); }
		static Result<void> ClassInterface_AddComponent(ClassInterface* this_, const ComponentDescriptor& component) { return C::Get(this_)->AddComponent(component); }
		static void ClassInterface_RemoveLastComponent(ClassInterface* this_) { return C::Get(this_)->RemoveLastComponent(); }
		static Result<void> ClassInterface_AddComponents(ClassInterface* this_, const Class<>& cls) { return C::Get(this_)->AddComponents(cls); }
		static Result<void> ClassInterface_Finalize(ClassInterface* this_) { return C::Get(this_)->Finalize(); }
		static Bool ClassInterface_IsFinalized(const ClassInterface* this_) { return C::Get(this_)->IsFinalized(); }
		static const Block<const InterfaceReference* const>& ClassInterface_GetImplementedInterfaces(const ClassInterface* this_) { return C::Get(this_)->GetImplementedInterfaces(); }
		static const DataType& ClassInterface_GetDataType(const ClassInterface* this_) { return C::Get(this_)->GetDataType(); }
		static Result<typename maxon::details::ClassGetNonConst<REF>::type> ClassInterface_Create(const ClassInterface* this_) { return C::Get(this_)->Create(); }
		static Result<ObjectInterface*> ClassInterface_CreatePointer(const ClassInterface* this_) { return C::Get(this_)->CreatePointer(); }
		static Result<ObjectInterface*> ClassInterface_CreatePointer_1(const ClassInterface* this_, Int size) { return C::Get(this_)->CreatePointer(size); }
		static Bool ClassInterface_IsSubclassOf(const ClassInterface* this_, const Class<>& other) { return C::Get(this_)->IsSubclassOf(other); }
		static String ClassInterface_ToString(const ClassInterface* this_, const FormatStatement* formatStatement) { return C::Get(this_)->ToString(formatStatement); }
		static const DataDictionary& ClassInterface_GetMetaData(const ClassInterface* this_) { return C::Get(this_)->GetMetaData(); }
		static void ClassInterface_InitMetaData(ClassInterface* this_, DataDictionary&& data) { return C::Get(this_)->InitMetaData(std::forward<DataDictionary>(data)); }
		static void ClassInterface_DeleteInstance(const ObjectInterface* object) { return C::DeleteInstance(object); }
		static void ClassInterface_DestructInstance(const ObjectInterface* object) { return C::DestructInstance(object); }
		static Result<void> ClassInterface_CopyInstance(ObjectInterface* dest, const ObjectInterface* src) { return C::CopyInstance(dest, src); }
		static const ClassInfo* ClassInterface_GetInfo(const ClassInterface* this_) { return C::Get(this_)->GetInfo(); }
		static void* ClassInterface_GetOrCreateMTable(ClassInfo* info, const InterfaceReference& i) { return C::GetOrCreateMTable(info, i); }
		static Result<Int> ClassInterface_AddProxyComponent(ClassInterface* this_, const ComponentDescriptor& component, Bool shared) { return C::Get(this_)->AddProxyComponent(component, shared); }
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
	return MTable::_instance.ClassInterface_GetId(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ClassInterface::GetKind() const -> KIND
{
	return MTable::_instance.ClassInterface_GetKind(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ClassInterface::GetSize() const -> Int
{
	return MTable::_instance.ClassInterface_GetSize(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ClassInterface::GetComponents() const -> Block<const ComponentInfo* const>
{
	return MTable::_instance.ClassInterface_GetComponents(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ClassInterface::AddComponent(const ComponentDescriptor& component) -> Result<void>
{
	return MTable::_instance.ClassInterface_AddComponent(this, component);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ClassInterface::RemoveLastComponent() -> void
{
	return MTable::_instance.ClassInterface_RemoveLastComponent(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ClassInterface::AddComponents(const Class<>& cls) -> Result<void>
{
	return MTable::_instance.ClassInterface_AddComponents(this, cls);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ClassInterface::Finalize() -> Result<void>
{
	return MTable::_instance.ClassInterface_Finalize(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ClassInterface::IsFinalized() const -> Bool
{
	return MTable::_instance.ClassInterface_IsFinalized(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ClassInterface::GetImplementedInterfaces() const -> const Block<const InterfaceReference* const>&
{
	return MTable::_instance.ClassInterface_GetImplementedInterfaces(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ClassInterface::GetDataType() const -> const DataType&
{
	return MTable::_instance.ClassInterface_GetDataType(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ClassInterface::Create() const -> Result<typename maxon::details::ClassGetNonConst<REF>::type>
{
	return MTable::_instance.ClassInterface_Create(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ClassInterface::CreatePointer() const -> Result<ObjectInterface*>
{
	return MTable::_instance.ClassInterface_CreatePointer(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ClassInterface::CreatePointer(Int size) const -> Result<ObjectInterface*>
{
	return MTable::_instance.ClassInterface_CreatePointer_1(this, size);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ClassInterface::IsSubclassOf(const Class<>& other) const -> Bool
{
	return MTable::_instance.ClassInterface_IsSubclassOf(this, other);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ClassInterface::ToString(const FormatStatement* formatStatement) const -> String
{
	return MTable::_instance.ClassInterface_ToString(this, formatStatement);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ClassInterface::GetMetaData() const -> const DataDictionary&
{
	return MTable::_instance.ClassInterface_GetMetaData(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ClassInterface::InitMetaData(DataDictionary&& data) -> void
{
	return MTable::_instance.ClassInterface_InitMetaData(this, std::forward<DataDictionary>(data));
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
	return MTable::_instance.ClassInterface_GetInfo(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ClassInterface::GetOrCreateMTable(ClassInfo* info, const InterfaceReference& i) -> void*
{
	return MTable::_instance.ClassInterface_GetOrCreateMTable(info, i);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ClassInterface::AddProxyComponent(const ComponentDescriptor& component, Bool shared) -> Result<Int>
{
	return MTable::_instance.ClassInterface_AddProxyComponent(this, component, shared);
}

template <typename REF_> auto ClassInterface::Hxx1::Reference<REF_>::Create(const Id& cid, KIND kind) -> maxon::ResultMemT<Class<REF_>>
{
	ClassInterface* res_ = ClassInterface::Alloc(MAXON_SOURCE_LOCATION, cid, kind);
	return Class<REF_>(maxon::ForwardResultPtr<ClassInterface>(res_));
}
template <typename S, typename REF_> MAXON_ATTRIBUTE_FORCE_INLINE auto ClassInterface::Hxx1::ConstFn<S, REF_>::GetId() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const Id&>, const Id&>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const Id&>, const Id&>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ClassInterface* o_ = (const ClassInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ClassInterface::NullValuePtr(); if (!o_) return maxon::PrivateNullReturnValue<const Id&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (MTable::_instance.ClassInterface_GetId(o_));
}
template <typename S, typename REF_> MAXON_ATTRIBUTE_FORCE_INLINE auto ClassInterface::Hxx1::ConstFn<S, REF_>::GetKind() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<KIND>, KIND>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<KIND>, KIND>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ClassInterface* o_ = (const ClassInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ClassInterface::NullValuePtr(); if (!o_) return maxon::PrivateNullReturnValue<KIND>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (MTable::_instance.ClassInterface_GetKind(o_));
}
template <typename S, typename REF_> MAXON_ATTRIBUTE_FORCE_INLINE auto ClassInterface::Hxx1::ConstFn<S, REF_>::GetSize() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ClassInterface* o_ = (const ClassInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ClassInterface::NullValuePtr(); if (!o_) return 0; } 
	return (MTable::_instance.ClassInterface_GetSize(o_));
}
template <typename S, typename REF_> MAXON_ATTRIBUTE_FORCE_INLINE auto ClassInterface::Hxx1::ConstFn<S, REF_>::GetComponents() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Block<const ComponentInfo* const>>, Block<const ComponentInfo* const>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Block<const ComponentInfo* const>>, Block<const ComponentInfo* const>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ClassInterface* o_ = (const ClassInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ClassInterface::NullValuePtr(); if (!o_) return maxon::PrivateNullReturnValue<Block<const ComponentInfo* const>>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (MTable::_instance.ClassInterface_GetComponents(o_));
}
template <typename S, typename REF_> MAXON_ATTRIBUTE_FORCE_INLINE auto ClassInterface::Hxx1::Fn<S, REF_>::AddComponent(const ComponentDescriptor& component) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ClassInterface* o_ = (ClassInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.ClassInterface_AddComponent(o_, component));
}
template <typename S, typename REF_> MAXON_ATTRIBUTE_FORCE_INLINE auto ClassInterface::Hxx1::Fn<S, REF_>::AddComponents(const Class<>& cls) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ClassInterface* o_ = (ClassInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.ClassInterface_AddComponents(o_, cls));
}
template <typename S, typename REF_> MAXON_ATTRIBUTE_FORCE_INLINE auto ClassInterface::Hxx1::Fn<S, REF_>::Finalize() const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ClassInterface* o_ = (ClassInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.ClassInterface_Finalize(o_));
}
template <typename S, typename REF_> MAXON_ATTRIBUTE_FORCE_INLINE auto ClassInterface::Hxx1::ConstFn<S, REF_>::IsFinalized() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ClassInterface* o_ = (const ClassInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ClassInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (MTable::_instance.ClassInterface_IsFinalized(o_));
}
template <typename S, typename REF_> MAXON_ATTRIBUTE_FORCE_INLINE auto ClassInterface::Hxx1::ConstFn<S, REF_>::GetImplementedInterfaces() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const Block<const InterfaceReference* const>&>, const Block<const InterfaceReference* const>&>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const Block<const InterfaceReference* const>&>, const Block<const InterfaceReference* const>&>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ClassInterface* o_ = (const ClassInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ClassInterface::NullValuePtr(); if (!o_) return maxon::PrivateNullReturnValue<const Block<const InterfaceReference* const>&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (MTable::_instance.ClassInterface_GetImplementedInterfaces(o_));
}
template <typename S, typename REF_> MAXON_ATTRIBUTE_FORCE_INLINE auto ClassInterface::Hxx1::ConstFn<S, REF_>::GetDataType() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const DataType&>, const DataType&>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const DataType&>, const DataType&>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ClassInterface* o_ = (const ClassInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ClassInterface::NullValuePtr(); if (!o_) return maxon::PrivateNullReturnValue<const DataType&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (MTable::_instance.ClassInterface_GetDataType(o_));
}
template <typename S, typename REF_> MAXON_ATTRIBUTE_FORCE_INLINE auto ClassInterface::Hxx1::ConstFn<S, REF_>::Create() const -> Result<typename maxon::details::ClassGetNonConst<REF_>::type>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<typename maxon::details::ClassGetNonConst<REF_>::type>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ClassInterface* o_ = (const ClassInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ClassInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return maxon::GenericReinterpretCast<typename ReturnHelper::ReturnType>(MTable::_instance.ClassInterface_Create(o_));
}
template <typename S, typename REF_> MAXON_ATTRIBUTE_FORCE_INLINE auto ClassInterface::Hxx1::ConstFn<S, REF_>::CreatePointer(Int size) const -> Result<ObjectInterface*>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<ObjectInterface*>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ClassInterface* o_ = (const ClassInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ClassInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.ClassInterface_CreatePointer_1(o_, size));
}
template <typename S, typename REF_> MAXON_ATTRIBUTE_FORCE_INLINE auto ClassInterface::Hxx1::ConstFn<S, REF_>::Implements(const InterfaceReference& iref) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ClassInterface* o_ = (const ClassInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ClassInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (o_->Implements(iref));
}
template <typename S, typename REF_> template <typename I> MAXON_ATTRIBUTE_FORCE_INLINE auto ClassInterface::Hxx1::ConstFn<S, REF_>::Implements() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ClassInterface* o_ = (const ClassInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ClassInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (o_->Implements<I>());
}
template <typename S, typename REF_> MAXON_ATTRIBUTE_FORCE_INLINE auto ClassInterface::Hxx1::ConstFn<S, REF_>::IsSubclassOf(const Class<>& other) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ClassInterface* o_ = (const ClassInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ClassInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (MTable::_instance.ClassInterface_IsSubclassOf(o_, other));
}
template <typename S, typename REF_> MAXON_ATTRIBUTE_FORCE_INLINE auto ClassInterface::Hxx1::ConstFn<S, REF_>::ToString(const FormatStatement* formatStatement) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ClassInterface* o_ = (const ClassInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ClassInterface::NullValuePtr(); if (!o_) return maxon::PrivateNullReturnValue<String>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (MTable::_instance.ClassInterface_ToString(o_, formatStatement));
}
template <typename S, typename REF_> MAXON_ATTRIBUTE_FORCE_INLINE auto ClassInterface::Hxx1::ConstFn<S, REF_>::GetMetaData() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const DataDictionary&>, const DataDictionary&>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const DataDictionary&>, const DataDictionary&>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ClassInterface* o_ = (const ClassInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ClassInterface::NullValuePtr(); if (!o_) return maxon::PrivateNullReturnValue<const DataDictionary&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (MTable::_instance.ClassInterface_GetMetaData(o_));
}
template <typename S, typename REF_> MAXON_ATTRIBUTE_FORCE_INLINE auto ClassInterface::Hxx1::Fn<S, REF_>::InitMetaData(DataDictionary&& data) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ClassInterface* o_ = (ClassInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { DebugStop(); return maxon::PrivateLogNullptrError(); } 
	MTable::_instance.ClassInterface_InitMetaData(o_, std::forward<DataDictionary>(data));
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
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetHashValueImpl);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(HandleConstMessage);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(HandleMessage);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(InitObject);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(IsEqual);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(ToString);
	static const maxon::Char* const _ids;
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	String (*ObjectInterface_ToString) (const maxon::GenericComponent* this_, const FormatStatement* formatStatement);
	maxon::Int ObjectInterface_ToString_Offset;
	Result<void> (*ObjectInterface_InitObject) (maxon::GenericComponent* this_, const void* argument);
	maxon::Int ObjectInterface_InitObject_Offset;
	Result<void> (*ObjectInterface_HandleMessage) (maxon::GenericComponent* this_, const InternedId& message, void* argument);
	maxon::Int ObjectInterface_HandleMessage_Offset;
	Result<void> (*ObjectInterface_HandleConstMessage) (const maxon::GenericComponent* this_, const InternedId& message, void* argument);
	maxon::Int ObjectInterface_HandleConstMessage_Offset;
	Bool (*ObjectInterface_IsEqual) (const maxon::GenericComponent* this_, const maxon::ObjectInterface* other);
	maxon::Int ObjectInterface_IsEqual_Offset;
	COMPARERESULT (*ObjectInterface_Compare) (const maxon::GenericComponent* this_, const maxon::ObjectInterface* other);
	maxon::Int ObjectInterface_Compare_Offset;
	HashInt (*ObjectInterface_GetHashCodeImpl) (const maxon::GenericComponent* this_);
	maxon::Int ObjectInterface_GetHashCodeImpl_Offset;
	HashValue (*ObjectInterface_GetHashValueImpl) (const maxon::GenericComponent* this_);
	maxon::Int ObjectInterface_GetHashValueImpl_Offset;
#ifndef _HAS_CPP20_COMPARISONS
#endif
/// @cond INTERNAL

/// @endcond

	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ObjectInterface, ToString))
	{
		ObjectInterface_ToString = &W::ObjectInterface_ToString;
		ObjectInterface_ToString_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ObjectInterface, InitObject))
	{
		ObjectInterface_InitObject = &W::ObjectInterface_InitObject;
		ObjectInterface_InitObject_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ObjectInterface, HandleMessage))
	{
		ObjectInterface_HandleMessage = &W::ObjectInterface_HandleMessage;
		ObjectInterface_HandleMessage_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ObjectInterface, HandleConstMessage))
	{
		ObjectInterface_HandleConstMessage = &W::ObjectInterface_HandleConstMessage;
		ObjectInterface_HandleConstMessage_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ObjectInterface, IsEqual))
	{
		ObjectInterface_IsEqual = &W::ObjectInterface_IsEqual;
		ObjectInterface_IsEqual_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ObjectInterface, Compare))
	{
		ObjectInterface_Compare = &W::ObjectInterface_Compare;
		ObjectInterface_Compare_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ObjectInterface, GetHashCodeImpl))
	{
		ObjectInterface_GetHashCodeImpl = &W::ObjectInterface_GetHashCodeImpl;
		ObjectInterface_GetHashCodeImpl_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ObjectInterface, GetHashValueImpl))
	{
		ObjectInterface_GetHashValueImpl = &W::ObjectInterface_GetHashValueImpl;
		ObjectInterface_GetHashValueImpl_Offset = offset;
	}
#ifndef _HAS_CPP20_COMPARISONS
#endif
/// @cond INTERNAL

/// @endcond

	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<ObjectInterface, S>;
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
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetHashValueImpl);
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
		static String ObjectInterface_ToString(const maxon::GenericComponent* this_, const FormatStatement* formatStatement) { return ((const typename S::Implementation*) this_)->ToString(formatStatement); }
		static Result<void> ObjectInterface_InitObject(maxon::GenericComponent* this_, const void* argument) { return ((typename S::Implementation*) this_)->InitObject(argument); }
		static Result<void> ObjectInterface_HandleMessage(maxon::GenericComponent* this_, const InternedId& message, void* argument) { return ((typename S::Implementation*) this_)->HandleMessage(message, argument); }
		static Result<void> ObjectInterface_HandleConstMessage(const maxon::GenericComponent* this_, const InternedId& message, void* argument) { return ((const typename S::Implementation*) this_)->HandleConstMessage(message, argument); }
		static Bool ObjectInterface_IsEqual(const maxon::GenericComponent* this_, const maxon::ObjectInterface* other) { return ((const typename S::Implementation*) this_)->IsEqual(other); }
		static COMPARERESULT ObjectInterface_Compare(const maxon::GenericComponent* this_, const maxon::ObjectInterface* other) { return ((const typename S::Implementation*) this_)->Compare(other); }
		static HashInt ObjectInterface_GetHashCodeImpl(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetHashCodeImpl(); }
		static HashValue ObjectInterface_GetHashValueImpl(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetHashValueImpl(); }
#ifndef _HAS_CPP20_COMPARISONS
#endif
/// @cond INTERNAL

/// @endcond

	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto ObjectInterface::ToString(const FormatStatement* formatStatement) const -> String
{
	const ObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ObjectInterface, this); return mt_.ObjectInterface_ToString((const maxon::GenericComponent*) this + mt_.ObjectInterface_ToString_Offset, formatStatement);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ObjectInterface::InitObject(const void* argument) -> Result<void>
{
	const ObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ObjectInterface, this); return mt_.ObjectInterface_InitObject((maxon::GenericComponent*) this + mt_.ObjectInterface_InitObject_Offset, argument);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ObjectInterface::HandleMessage(const InternedId& message, void* argument) -> Result<void>
{
	const ObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ObjectInterface, this); return mt_.ObjectInterface_HandleMessage((maxon::GenericComponent*) this + mt_.ObjectInterface_HandleMessage_Offset, message, argument);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ObjectInterface::HandleConstMessage(const InternedId& message, void* argument) const -> Result<void>
{
	const ObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ObjectInterface, this); return mt_.ObjectInterface_HandleConstMessage((const maxon::GenericComponent*) this + mt_.ObjectInterface_HandleConstMessage_Offset, message, argument);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ObjectInterface::IsEqual(const maxon::ObjectInterface* other) const -> Bool
{
	const ObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ObjectInterface, this); return mt_.ObjectInterface_IsEqual((const maxon::GenericComponent*) this + mt_.ObjectInterface_IsEqual_Offset, other);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ObjectInterface::Compare(const maxon::ObjectInterface* other) const -> COMPARERESULT
{
	const ObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ObjectInterface, this); return mt_.ObjectInterface_Compare((const maxon::GenericComponent*) this + mt_.ObjectInterface_Compare_Offset, other);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ObjectInterface::GetHashCodeImpl() const -> HashInt
{
	const ObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ObjectInterface, this); return mt_.ObjectInterface_GetHashCodeImpl((const maxon::GenericComponent*) this + mt_.ObjectInterface_GetHashCodeImpl_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ObjectInterface::GetHashValueImpl() const -> HashValue
{
	const ObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ObjectInterface, this); return mt_.ObjectInterface_GetHashValueImpl((const maxon::GenericComponent*) this + mt_.ObjectInterface_GetHashValueImpl_Offset);
}
#ifndef _HAS_CPP20_COMPARISONS
#endif
/// @cond INTERNAL

/// @endcond


template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ObjectInterface::Hxx1::ConstFn<S>::GetClass() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const maxon::Class<typename S::PrivateErasedReferencedType::Hxx1::ReferenceClass>&>, const maxon::Class<typename S::PrivateErasedReferencedType::Hxx1::ReferenceClass>&>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const maxon::Class<typename S::PrivateErasedReferencedType::Hxx1::ReferenceClass>&>, const maxon::Class<typename S::PrivateErasedReferencedType::Hxx1::ReferenceClass>&>::type>; static_assert(!std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value, "Can't invoke MAXON_FUNCTION ObjectInterface::GetClass on super."); if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ObjectInterface* o_ = (const ObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ObjectInterface::NullValuePtr(); if (!o_) return maxon::PrivateNullReturnValue<const maxon::Class<typename S::PrivateErasedReferencedType::Hxx1::ReferenceClass>&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (o_->GetClass<S>());
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ObjectInterface::Hxx1::ConstFn<S>::GetClassInfo() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const ClassInfo*>, const ClassInfo*>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const ClassInfo*>, const ClassInfo*>::type>; static_assert(!std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value, "Can't invoke MAXON_FUNCTION ObjectInterface::GetClassInfo on super."); if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ObjectInterface* o_ = (const ObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ObjectInterface::NullValuePtr(); if (!o_) return nullptr; } 
	return (o_->GetClassInfo());
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ObjectInterface::Hxx1::ConstFn<S>::HasSameClass(const ObjectInterface* obj) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; static_assert(!std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value, "Can't invoke MAXON_FUNCTION ObjectInterface::HasSameClass on super."); if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ObjectInterface* o_ = (const ObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ObjectInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (o_->HasSameClass(obj));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ObjectInterface::Hxx1::ConstFn<S>::Clone() const -> Result<maxon::details::GetReferenceClass<S>>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<maxon::details::GetReferenceClass<S>>>; static_assert(!std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value, "Can't invoke MAXON_FUNCTION ObjectInterface::Clone on super."); if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ObjectInterface* o_ = (const ObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ObjectInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->Clone<maxon::details::GetReferenceClass<S>>());
}
template <typename S> template <typename I> MAXON_ATTRIBUTE_FORCE_INLINE auto ObjectInterface::Hxx1::ConstFn<S>::IsInstanceOf() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; static_assert(!std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value, "Can't invoke MAXON_FUNCTION ObjectInterface::IsInstanceOf on super."); if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ObjectInterface* o_ = (const ObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ObjectInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (o_->IsInstanceOf<I>());
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ObjectInterface::Hxx1::ConstFn<S>::IsInstanceOf(const DataType& type) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; static_assert(!std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value, "Can't invoke MAXON_FUNCTION ObjectInterface::IsInstanceOf on super."); if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ObjectInterface* o_ = (const ObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ObjectInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (o_->IsInstanceOf(type));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ObjectInterface::Hxx1::ConstFn<S>::ToString(const FormatStatement* formatStatement) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ObjectInterface* o_ = (const ObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ObjectInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ObjectInterface, o_, ObjectInterface_ToString) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ObjectInterface>() : PRIVATE_MAXON_VTABLE(ObjectInterface, o_); 
	return (mt_.ObjectInterface_ToString(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.ObjectInterface_ToString_Offset, formatStatement));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ObjectInterface::Hxx1::Fn<S>::InitObject(const void* argument) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ObjectInterface* o_ = (ObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ObjectInterface, o_, ObjectInterface_InitObject) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ObjectInterface>() : PRIVATE_MAXON_VTABLE(ObjectInterface, o_); 
	return (mt_.ObjectInterface_InitObject(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ObjectInterface_InitObject_Offset, argument));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ObjectInterface::Hxx1::COWFn<S>::InitObject(const void* argument) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ObjectInterface* o_ = (ObjectInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ObjectInterface, o_, ObjectInterface_InitObject) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ObjectInterface>() : PRIVATE_MAXON_VTABLE(ObjectInterface, o_); 
	return (mt_.ObjectInterface_InitObject(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ObjectInterface_InitObject_Offset, argument));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ObjectInterface::Hxx1::Fn<S>::HandleMessage(const InternedId& message, void* argument) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ObjectInterface* o_ = (ObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ObjectInterface, o_, ObjectInterface_HandleMessage) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ObjectInterface>() : PRIVATE_MAXON_VTABLE(ObjectInterface, o_); 
	return (mt_.ObjectInterface_HandleMessage(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ObjectInterface_HandleMessage_Offset, message, argument));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ObjectInterface::Hxx1::COWFn<S>::HandleMessage(const InternedId& message, void* argument) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ObjectInterface* o_ = (ObjectInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ObjectInterface, o_, ObjectInterface_HandleMessage) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ObjectInterface>() : PRIVATE_MAXON_VTABLE(ObjectInterface, o_); 
	return (mt_.ObjectInterface_HandleMessage(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ObjectInterface_HandleMessage_Offset, message, argument));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ObjectInterface::Hxx1::ConstFn<S>::HandleConstMessage(const InternedId& message, void* argument) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ObjectInterface* o_ = (const ObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ObjectInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ObjectInterface, o_, ObjectInterface_HandleConstMessage) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ObjectInterface>() : PRIVATE_MAXON_VTABLE(ObjectInterface, o_); 
	return (mt_.ObjectInterface_HandleConstMessage(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.ObjectInterface_HandleConstMessage_Offset, message, argument));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ObjectInterface::Hxx1::ConstFn<S>::IsEqual(const maxon::ObjectInterface* other) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ObjectInterface* o_ = (const ObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ObjectInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ObjectInterface, o_, ObjectInterface_IsEqual) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ObjectInterface>() : PRIVATE_MAXON_VTABLE(ObjectInterface, o_); 
	return (mt_.ObjectInterface_IsEqual(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.ObjectInterface_IsEqual_Offset, other));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ObjectInterface::Hxx1::ConstFn<S>::Compare(const maxon::ObjectInterface* other) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<COMPARERESULT>, COMPARERESULT>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<COMPARERESULT>, COMPARERESULT>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ObjectInterface* o_ = (const ObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ObjectInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<COMPARERESULT>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ObjectInterface, o_, ObjectInterface_Compare) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ObjectInterface>() : PRIVATE_MAXON_VTABLE(ObjectInterface, o_); 
	return (mt_.ObjectInterface_Compare(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.ObjectInterface_Compare_Offset, other));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ObjectInterface::Hxx1::ConstFn<S>::GetHashCodeImpl() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<HashInt>, HashInt>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<HashInt>, HashInt>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ObjectInterface* o_ = (const ObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ObjectInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<HashInt>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ObjectInterface, o_, ObjectInterface_GetHashCodeImpl) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ObjectInterface>() : PRIVATE_MAXON_VTABLE(ObjectInterface, o_); 
	return (mt_.ObjectInterface_GetHashCodeImpl(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.ObjectInterface_GetHashCodeImpl_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ObjectInterface::Hxx1::ConstFn<S>::GetHashValueImpl() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<HashValue>, HashValue>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<HashValue>, HashValue>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ObjectInterface* o_ = (const ObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ObjectInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<HashValue>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ObjectInterface, o_, ObjectInterface_GetHashValueImpl) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ObjectInterface>() : PRIVATE_MAXON_VTABLE(ObjectInterface, o_); 
	return (mt_.ObjectInterface_GetHashValueImpl(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.ObjectInterface_GetHashValueImpl_Offset));
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
	const SourceLocation& (*ErrorInterface_GetLocation) (const maxon::GenericComponent* this_);
	maxon::Int ErrorInterface_GetLocation_Offset;
	void (*ErrorInterface_SetLocation) (maxon::GenericComponent* this_, const maxon::SourceLocation& allocLocation);
	maxon::Int ErrorInterface_SetLocation_Offset;
	Block<void* const> (*ErrorInterface_GetStackTrace) (const maxon::GenericComponent* this_);
	maxon::Int ErrorInterface_GetStackTrace_Offset;
	void (*ErrorInterface_SetStackTrace) (maxon::GenericComponent* this_, const Block<void* const>& trace);
	maxon::Int ErrorInterface_SetStackTrace_Offset;
	String (*ErrorInterface_GetMessage) (const maxon::GenericComponent* this_);
	maxon::Int ErrorInterface_GetMessage_Offset;
	void (*ErrorInterface_SetMessage) (maxon::GenericComponent* this_, const String& message);
	maxon::Int ErrorInterface_SetMessage_Offset;
	String (*ErrorInterface_FormatMessage) (const maxon::GenericComponent* this_, const LanguageRef& language, const PartFormatter& partFormatter);
	maxon::Int ErrorInterface_FormatMessage_Offset;
	void (*ErrorInterface_SetMessageDelegate) (maxon::GenericComponent* this_, Delegate<String(const LanguageRef&language,const ErrorInterface::PartFormatter&fmt)>&& message);
	maxon::Int ErrorInterface_SetMessageDelegate_Offset;
	const Error& (*ErrorInterface_GetCause) (const maxon::GenericComponent* this_);
	maxon::Int ErrorInterface_GetCause_Offset;
	void (*ErrorInterface_SetCause) (maxon::GenericComponent* this_, const Error& cause);
	maxon::Int ErrorInterface_SetCause_Offset;
	void (*ErrorInterface_GetMachine) (const maxon::GenericComponent* this_, MachineRef& machine);
	maxon::Int ErrorInterface_GetMachine_Offset;
	void (*ErrorInterface_SetMachine) (maxon::GenericComponent* this_, const MachineRef& machine);
	maxon::Int ErrorInterface_SetMachine_Offset;
	Int (*ErrorInterface_PrivateGetCode) (const maxon::GenericComponent* this_);
	maxon::Int ErrorInterface_PrivateGetCode_Offset;
	void (*ErrorInterface_PrivateSetCode) (maxon::GenericComponent* this_, Int code);
	maxon::Int ErrorInterface_PrivateSetCode_Offset;
	void (*ErrorInterface_PrivateSetPreallocation) (const maxon::GenericComponent* this_, ThreadReferencedError preallocation);
	maxon::Int ErrorInterface_PrivateSetPreallocation_Offset;
	ThreadReferencedError (*ErrorInterface_PrivateGetPreallocation) (const maxon::GenericComponent* this_);
	maxon::Int ErrorInterface_PrivateGetPreallocation_Offset;
	void (*ErrorInterface_PrivateSetDebugError) (const maxon::GenericComponent* this_, const Error& cause);
	maxon::Int ErrorInterface_PrivateSetDebugError_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ErrorInterface, GetLocation))
	{
		ErrorInterface_GetLocation = &W::ErrorInterface_GetLocation;
		ErrorInterface_GetLocation_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ErrorInterface, SetLocation))
	{
		ErrorInterface_SetLocation = &W::ErrorInterface_SetLocation;
		ErrorInterface_SetLocation_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ErrorInterface, GetStackTrace))
	{
		ErrorInterface_GetStackTrace = &W::ErrorInterface_GetStackTrace;
		ErrorInterface_GetStackTrace_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ErrorInterface, SetStackTrace))
	{
		ErrorInterface_SetStackTrace = &W::ErrorInterface_SetStackTrace;
		ErrorInterface_SetStackTrace_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ErrorInterface, GetMessage))
	{
		ErrorInterface_GetMessage = &W::ErrorInterface_GetMessage;
		ErrorInterface_GetMessage_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ErrorInterface, SetMessage))
	{
		ErrorInterface_SetMessage = &W::ErrorInterface_SetMessage;
		ErrorInterface_SetMessage_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ErrorInterface, FormatMessage))
	{
		ErrorInterface_FormatMessage = &W::ErrorInterface_FormatMessage;
		ErrorInterface_FormatMessage_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ErrorInterface, SetMessageDelegate))
	{
		ErrorInterface_SetMessageDelegate = &W::ErrorInterface_SetMessageDelegate;
		ErrorInterface_SetMessageDelegate_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ErrorInterface, GetCause))
	{
		ErrorInterface_GetCause = &W::ErrorInterface_GetCause;
		ErrorInterface_GetCause_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ErrorInterface, SetCause))
	{
		ErrorInterface_SetCause = &W::ErrorInterface_SetCause;
		ErrorInterface_SetCause_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ErrorInterface, GetMachine))
	{
		ErrorInterface_GetMachine = &W::ErrorInterface_GetMachine;
		ErrorInterface_GetMachine_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ErrorInterface, SetMachine))
	{
		ErrorInterface_SetMachine = &W::ErrorInterface_SetMachine;
		ErrorInterface_SetMachine_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ErrorInterface, PrivateGetCode))
	{
		ErrorInterface_PrivateGetCode = &W::ErrorInterface_PrivateGetCode;
		ErrorInterface_PrivateGetCode_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ErrorInterface, PrivateSetCode))
	{
		ErrorInterface_PrivateSetCode = &W::ErrorInterface_PrivateSetCode;
		ErrorInterface_PrivateSetCode_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ErrorInterface, PrivateSetPreallocation))
	{
		ErrorInterface_PrivateSetPreallocation = &W::ErrorInterface_PrivateSetPreallocation;
		ErrorInterface_PrivateSetPreallocation_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ErrorInterface, PrivateGetPreallocation))
	{
		ErrorInterface_PrivateGetPreallocation = &W::ErrorInterface_PrivateGetPreallocation;
		ErrorInterface_PrivateGetPreallocation_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ErrorInterface, PrivateSetDebugError))
	{
		ErrorInterface_PrivateSetDebugError = &W::ErrorInterface_PrivateSetDebugError;
		ErrorInterface_PrivateSetDebugError_Offset = offset;
	}
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<ErrorInterface, typename ObjectInterface::MTable::template CombinedMTable<S>>;
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
			if (!S::Implementation::PROXY && !(Super0::InitMTablesWithBases(info, offset))) return false;
			auto* vt = (ErrorInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, ErrorInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		static const SourceLocation& ErrorInterface_GetLocation(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetLocation(); }
		static void ErrorInterface_SetLocation(maxon::GenericComponent* this_, const maxon::SourceLocation& allocLocation) { return ((typename S::Implementation*) this_)->SetLocation(allocLocation); }
		static Block<void* const> ErrorInterface_GetStackTrace(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetStackTrace(); }
		static void ErrorInterface_SetStackTrace(maxon::GenericComponent* this_, const Block<void* const>& trace) { return ((typename S::Implementation*) this_)->SetStackTrace(trace); }
		static String ErrorInterface_GetMessage(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetMessage(); }
		static void ErrorInterface_SetMessage(maxon::GenericComponent* this_, const String& message) { return ((typename S::Implementation*) this_)->SetMessage(message); }
		static String ErrorInterface_FormatMessage(const maxon::GenericComponent* this_, const LanguageRef& language, const PartFormatter& partFormatter) { return ((const typename S::Implementation*) this_)->FormatMessage(language, partFormatter); }
		static void ErrorInterface_SetMessageDelegate(maxon::GenericComponent* this_, Delegate<String(const LanguageRef&language,const ErrorInterface::PartFormatter&fmt)>&& message) { return ((typename S::Implementation*) this_)->SetMessageDelegate(std::forward<Delegate<String(const LanguageRef&language,const ErrorInterface::PartFormatter&fmt)>>(message)); }
		static const Error& ErrorInterface_GetCause(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetCause(); }
		static void ErrorInterface_SetCause(maxon::GenericComponent* this_, const Error& cause) { return ((typename S::Implementation*) this_)->SetCause(cause); }
		static void ErrorInterface_GetMachine(const maxon::GenericComponent* this_, MachineRef& machine) { return ((const typename S::Implementation*) this_)->GetMachine(machine); }
		static void ErrorInterface_SetMachine(maxon::GenericComponent* this_, const MachineRef& machine) { return ((typename S::Implementation*) this_)->SetMachine(machine); }
		static Int ErrorInterface_PrivateGetCode(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->PrivateGetCode(); }
		static void ErrorInterface_PrivateSetCode(maxon::GenericComponent* this_, Int code) { return ((typename S::Implementation*) this_)->PrivateSetCode(code); }
		static void ErrorInterface_PrivateSetPreallocation(const maxon::GenericComponent* this_, ThreadReferencedError preallocation) { return ((const typename S::Implementation*) this_)->PrivateSetPreallocation(std::forward<ThreadReferencedError>(preallocation)); }
		static ThreadReferencedError ErrorInterface_PrivateGetPreallocation(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->PrivateGetPreallocation(); }
		static void ErrorInterface_PrivateSetDebugError(const maxon::GenericComponent* this_, const Error& cause) { return ((const typename S::Implementation*) this_)->PrivateSetDebugError(cause); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::GetLocation() const -> const SourceLocation&
{
	const ErrorInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ErrorInterface, this); return mt_.ErrorInterface_GetLocation((const maxon::GenericComponent*) this + mt_.ErrorInterface_GetLocation_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::SetLocation(const maxon::SourceLocation& allocLocation) -> void
{
	const ErrorInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ErrorInterface, this); return mt_.ErrorInterface_SetLocation((maxon::GenericComponent*) this + mt_.ErrorInterface_SetLocation_Offset, allocLocation);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::GetStackTrace() const -> Block<void* const>
{
	const ErrorInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ErrorInterface, this); return mt_.ErrorInterface_GetStackTrace((const maxon::GenericComponent*) this + mt_.ErrorInterface_GetStackTrace_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::SetStackTrace(const Block<void* const>& trace) -> void
{
	const ErrorInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ErrorInterface, this); return mt_.ErrorInterface_SetStackTrace((maxon::GenericComponent*) this + mt_.ErrorInterface_SetStackTrace_Offset, trace);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::GetMessage() const -> String
{
	const ErrorInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ErrorInterface, this); return mt_.ErrorInterface_GetMessage((const maxon::GenericComponent*) this + mt_.ErrorInterface_GetMessage_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::SetMessage(const String& message) -> void
{
	const ErrorInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ErrorInterface, this); return mt_.ErrorInterface_SetMessage((maxon::GenericComponent*) this + mt_.ErrorInterface_SetMessage_Offset, message);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::FormatMessage(const LanguageRef& language, const PartFormatter& partFormatter) const -> String
{
	const ErrorInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ErrorInterface, this); return mt_.ErrorInterface_FormatMessage((const maxon::GenericComponent*) this + mt_.ErrorInterface_FormatMessage_Offset, language, partFormatter);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::SetMessageDelegate(Delegate<String(const LanguageRef&language,const ErrorInterface::PartFormatter&fmt)>&& message) -> void
{
	const ErrorInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ErrorInterface, this); return mt_.ErrorInterface_SetMessageDelegate((maxon::GenericComponent*) this + mt_.ErrorInterface_SetMessageDelegate_Offset, std::forward<Delegate<String(const LanguageRef&language,const ErrorInterface::PartFormatter&fmt)>>(message));
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::GetCause() const -> const Error&
{
	const ErrorInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ErrorInterface, this); return mt_.ErrorInterface_GetCause((const maxon::GenericComponent*) this + mt_.ErrorInterface_GetCause_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::SetCause(const Error& cause) -> void
{
	const ErrorInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ErrorInterface, this); return mt_.ErrorInterface_SetCause((maxon::GenericComponent*) this + mt_.ErrorInterface_SetCause_Offset, cause);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::GetMachine(MachineRef& machine) const -> void
{
	const ErrorInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ErrorInterface, this); return mt_.ErrorInterface_GetMachine((const maxon::GenericComponent*) this + mt_.ErrorInterface_GetMachine_Offset, machine);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::SetMachine(const MachineRef& machine) -> void
{
	const ErrorInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ErrorInterface, this); return mt_.ErrorInterface_SetMachine((maxon::GenericComponent*) this + mt_.ErrorInterface_SetMachine_Offset, machine);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::PrivateGetCode() const -> Int
{
	const ErrorInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ErrorInterface, this); return mt_.ErrorInterface_PrivateGetCode((const maxon::GenericComponent*) this + mt_.ErrorInterface_PrivateGetCode_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::PrivateSetCode(Int code) -> void
{
	const ErrorInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ErrorInterface, this); return mt_.ErrorInterface_PrivateSetCode((maxon::GenericComponent*) this + mt_.ErrorInterface_PrivateSetCode_Offset, code);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::PrivateSetPreallocation(ThreadReferencedError preallocation) const -> void
{
	const ErrorInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ErrorInterface, this); return mt_.ErrorInterface_PrivateSetPreallocation((const maxon::GenericComponent*) this + mt_.ErrorInterface_PrivateSetPreallocation_Offset, std::forward<ThreadReferencedError>(preallocation));
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::PrivateGetPreallocation() const -> ThreadReferencedError
{
	const ErrorInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ErrorInterface, this); return mt_.ErrorInterface_PrivateGetPreallocation((const maxon::GenericComponent*) this + mt_.ErrorInterface_PrivateGetPreallocation_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::PrivateSetDebugError(const Error& cause) const -> void
{
	const ErrorInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ErrorInterface, this); return mt_.ErrorInterface_PrivateSetDebugError((const maxon::GenericComponent*) this + mt_.ErrorInterface_PrivateSetDebugError_Offset, cause);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::Hxx1::ConstFn<S>::GetLocation() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const SourceLocation&>, const SourceLocation&>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const SourceLocation&>, const SourceLocation&>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ErrorInterface* o_ = (const ErrorInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ErrorInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<const SourceLocation&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ErrorInterface, o_, ErrorInterface_GetLocation) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ErrorInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ErrorInterface>() : PRIVATE_MAXON_VTABLE(ErrorInterface, o_); 
	return (mt_.ErrorInterface_GetLocation(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.ErrorInterface_GetLocation_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::Hxx1::Fn<S>::SetLocation(const maxon::SourceLocation& allocLocation) const -> DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S)
{
	static_assert(!S::HAS_ERROR, "ErrorInterface::SetLocation can't be used on a Result object because it does not return a Result object itself."); ErrorInterface* o_ = (ErrorInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { DebugStop(); return this->PrivateGetRefMember(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ErrorInterface, o_, ErrorInterface_SetLocation) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ErrorInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ErrorInterface>() : PRIVATE_MAXON_VTABLE(ErrorInterface, o_); 
	mt_.ErrorInterface_SetLocation(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ErrorInterface_SetLocation_Offset, allocLocation);
	return this->PrivateGetRefMember();
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::Hxx1::COWFn<S>::SetLocation(const maxon::SourceLocation& allocLocation) -> DOXYGEN_SWITCH(maxon::RefMemberType<S>, S)
{
	static_assert(!S::HAS_ERROR, "ErrorInterface::SetLocation can't be used on a Result object because it does not return a Result object itself."); ErrorInterface* o_ = (ErrorInterface*) this->MakeWritable(false).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return this->PrivateGetRefMember(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ErrorInterface, o_, ErrorInterface_SetLocation) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ErrorInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ErrorInterface>() : PRIVATE_MAXON_VTABLE(ErrorInterface, o_); 
	mt_.ErrorInterface_SetLocation(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ErrorInterface_SetLocation_Offset, allocLocation);
	return this->PrivateGetRefMember();
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::Hxx1::ConstFn<S>::GetStackTrace() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Block<void* const>>, Block<void* const>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Block<void* const>>, Block<void* const>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ErrorInterface* o_ = (const ErrorInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ErrorInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<Block<void* const>>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ErrorInterface, o_, ErrorInterface_GetStackTrace) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ErrorInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ErrorInterface>() : PRIVATE_MAXON_VTABLE(ErrorInterface, o_); 
	return (mt_.ErrorInterface_GetStackTrace(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.ErrorInterface_GetStackTrace_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::Hxx1::Fn<S>::SetStackTrace(const Block<void* const>& trace) const -> DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S)
{
	static_assert(!S::HAS_ERROR, "ErrorInterface::SetStackTrace can't be used on a Result object because it does not return a Result object itself."); ErrorInterface* o_ = (ErrorInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { DebugStop(); return this->PrivateGetRefMember(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ErrorInterface, o_, ErrorInterface_SetStackTrace) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ErrorInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ErrorInterface>() : PRIVATE_MAXON_VTABLE(ErrorInterface, o_); 
	mt_.ErrorInterface_SetStackTrace(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ErrorInterface_SetStackTrace_Offset, trace);
	return this->PrivateGetRefMember();
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::Hxx1::COWFn<S>::SetStackTrace(const Block<void* const>& trace) -> DOXYGEN_SWITCH(maxon::RefMemberType<S>, S)
{
	static_assert(!S::HAS_ERROR, "ErrorInterface::SetStackTrace can't be used on a Result object because it does not return a Result object itself."); ErrorInterface* o_ = (ErrorInterface*) this->MakeWritable(false).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return this->PrivateGetRefMember(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ErrorInterface, o_, ErrorInterface_SetStackTrace) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ErrorInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ErrorInterface>() : PRIVATE_MAXON_VTABLE(ErrorInterface, o_); 
	mt_.ErrorInterface_SetStackTrace(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ErrorInterface_SetStackTrace_Offset, trace);
	return this->PrivateGetRefMember();
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::Hxx1::Fn<S>::SetStackTrace(Int skip) const -> DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S)
{
	static_assert(!S::HAS_ERROR, "ErrorInterface::SetStackTrace can't be used on a Result object because it does not return a Result object itself."); ErrorInterface* o_ = (ErrorInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { DebugStop(); return this->PrivateGetRefMember(); } 
	o_->SetStackTrace(skip);
	return this->PrivateGetRefMember();
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::Hxx1::COWFn<S>::SetStackTrace(Int skip) -> DOXYGEN_SWITCH(maxon::RefMemberType<S>, S)
{
	static_assert(!std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value, "Can't invoke MAXON_FUNCTION ErrorInterface::SetStackTrace on super."); static_assert(!S::HAS_ERROR, "ErrorInterface::SetStackTrace can't be used on a Result object because it does not return a Result object itself."); ErrorInterface* o_ = (ErrorInterface*) this->MakeWritable(false).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return this->PrivateGetRefMember(); } 
	o_->SetStackTrace(skip);
	return this->PrivateGetRefMember();
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::Hxx1::ConstFn<S>::IsCancellation() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; static_assert(!std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value, "Can't invoke MAXON_FUNCTION ErrorInterface::IsCancellation on super."); if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ErrorInterface* o_ = (const ErrorInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ErrorInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (o_->IsCancellation());
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::Hxx1::ConstFn<S>::GetMessage() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ErrorInterface* o_ = (const ErrorInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ErrorInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ErrorInterface, o_, ErrorInterface_GetMessage) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ErrorInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ErrorInterface>() : PRIVATE_MAXON_VTABLE(ErrorInterface, o_); 
	return (mt_.ErrorInterface_GetMessage(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.ErrorInterface_GetMessage_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::Hxx1::Fn<S>::SetMessage(const String& message) const -> DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S)
{
	static_assert(!S::HAS_ERROR, "ErrorInterface::SetMessage can't be used on a Result object because it does not return a Result object itself."); ErrorInterface* o_ = (ErrorInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { DebugStop(); return this->PrivateGetRefMember(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ErrorInterface, o_, ErrorInterface_SetMessage) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ErrorInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ErrorInterface>() : PRIVATE_MAXON_VTABLE(ErrorInterface, o_); 
	mt_.ErrorInterface_SetMessage(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ErrorInterface_SetMessage_Offset, message);
	return this->PrivateGetRefMember();
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::Hxx1::COWFn<S>::SetMessage(const String& message) -> DOXYGEN_SWITCH(maxon::RefMemberType<S>, S)
{
	static_assert(!S::HAS_ERROR, "ErrorInterface::SetMessage can't be used on a Result object because it does not return a Result object itself."); ErrorInterface* o_ = (ErrorInterface*) this->MakeWritable(false).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return this->PrivateGetRefMember(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ErrorInterface, o_, ErrorInterface_SetMessage) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ErrorInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ErrorInterface>() : PRIVATE_MAXON_VTABLE(ErrorInterface, o_); 
	mt_.ErrorInterface_SetMessage(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ErrorInterface_SetMessage_Offset, message);
	return this->PrivateGetRefMember();
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::Hxx1::ConstFn<S>::FormatMessage(const LanguageRef& language, const PartFormatter& partFormatter) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ErrorInterface* o_ = (const ErrorInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ErrorInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ErrorInterface, o_, ErrorInterface_FormatMessage) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ErrorInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ErrorInterface>() : PRIVATE_MAXON_VTABLE(ErrorInterface, o_); 
	return (mt_.ErrorInterface_FormatMessage(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.ErrorInterface_FormatMessage_Offset, language, partFormatter));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::Hxx1::Fn<S>::SetMessageDelegate(Delegate<String(const LanguageRef&language,const ErrorInterface::PartFormatter&fmt)>&& message) const -> DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S)
{
	static_assert(!S::HAS_ERROR, "ErrorInterface::SetMessageDelegate can't be used on a Result object because it does not return a Result object itself."); ErrorInterface* o_ = (ErrorInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { DebugStop(); return this->PrivateGetRefMember(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ErrorInterface, o_, ErrorInterface_SetMessageDelegate) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ErrorInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ErrorInterface>() : PRIVATE_MAXON_VTABLE(ErrorInterface, o_); 
	mt_.ErrorInterface_SetMessageDelegate(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ErrorInterface_SetMessageDelegate_Offset, std::forward<Delegate<String(const LanguageRef&language,const ErrorInterface::PartFormatter&fmt)>>(message));
	return this->PrivateGetRefMember();
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::Hxx1::COWFn<S>::SetMessageDelegate(Delegate<String(const LanguageRef&language,const ErrorInterface::PartFormatter&fmt)>&& message) -> DOXYGEN_SWITCH(maxon::RefMemberType<S>, S)
{
	static_assert(!S::HAS_ERROR, "ErrorInterface::SetMessageDelegate can't be used on a Result object because it does not return a Result object itself."); ErrorInterface* o_ = (ErrorInterface*) this->MakeWritable(false).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return this->PrivateGetRefMember(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ErrorInterface, o_, ErrorInterface_SetMessageDelegate) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ErrorInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ErrorInterface>() : PRIVATE_MAXON_VTABLE(ErrorInterface, o_); 
	mt_.ErrorInterface_SetMessageDelegate(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ErrorInterface_SetMessageDelegate_Offset, std::forward<Delegate<String(const LanguageRef&language,const ErrorInterface::PartFormatter&fmt)>>(message));
	return this->PrivateGetRefMember();
}
template <typename S> template <typename T> MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::Hxx1::ConstFn<S>::FormatPart(const LanguageRef& language, const ErrorInterface::PartFormatter& fmt, const T& part) -> String
{
	return (ErrorInterface::template FormatPart<T>(language, fmt, part));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::Hxx1::ConstFn<S>::GetCause() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const Error&>, const Error&>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const Error&>, const Error&>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ErrorInterface* o_ = (const ErrorInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ErrorInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<const Error&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ErrorInterface, o_, ErrorInterface_GetCause) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ErrorInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ErrorInterface>() : PRIVATE_MAXON_VTABLE(ErrorInterface, o_); 
	return (mt_.ErrorInterface_GetCause(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.ErrorInterface_GetCause_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::Hxx1::Fn<S>::SetCause(const Error& cause) const -> DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S)
{
	static_assert(!S::HAS_ERROR, "ErrorInterface::SetCause can't be used on a Result object because it does not return a Result object itself."); ErrorInterface* o_ = (ErrorInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { DebugStop(); return this->PrivateGetRefMember(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ErrorInterface, o_, ErrorInterface_SetCause) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ErrorInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ErrorInterface>() : PRIVATE_MAXON_VTABLE(ErrorInterface, o_); 
	mt_.ErrorInterface_SetCause(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ErrorInterface_SetCause_Offset, cause);
	return this->PrivateGetRefMember();
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::Hxx1::COWFn<S>::SetCause(const Error& cause) -> DOXYGEN_SWITCH(maxon::RefMemberType<S>, S)
{
	static_assert(!S::HAS_ERROR, "ErrorInterface::SetCause can't be used on a Result object because it does not return a Result object itself."); ErrorInterface* o_ = (ErrorInterface*) this->MakeWritable(false).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return this->PrivateGetRefMember(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ErrorInterface, o_, ErrorInterface_SetCause) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ErrorInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ErrorInterface>() : PRIVATE_MAXON_VTABLE(ErrorInterface, o_); 
	mt_.ErrorInterface_SetCause(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ErrorInterface_SetCause_Offset, cause);
	return this->PrivateGetRefMember();
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::Hxx1::ConstFn<S>::GetMachine(MachineRef& machine) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ErrorInterface* o_ = (const ErrorInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ErrorInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ErrorInterface, o_, ErrorInterface_GetMachine) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ErrorInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ErrorInterface>() : PRIVATE_MAXON_VTABLE(ErrorInterface, o_); 
	mt_.ErrorInterface_GetMachine(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.ErrorInterface_GetMachine_Offset, machine);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::Hxx1::Fn<S>::SetMachine(const MachineRef& machine) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ErrorInterface* o_ = (ErrorInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { DebugStop(); return maxon::PrivateLogNullptrError(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ErrorInterface, o_, ErrorInterface_SetMachine) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ErrorInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ErrorInterface>() : PRIVATE_MAXON_VTABLE(ErrorInterface, o_); 
	mt_.ErrorInterface_SetMachine(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ErrorInterface_SetMachine_Offset, machine);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::Hxx1::COWFn<S>::SetMachine(const MachineRef& machine) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ErrorInterface* o_ = (ErrorInterface*) this->MakeWritable(false).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ErrorInterface, o_, ErrorInterface_SetMachine) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ErrorInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ErrorInterface>() : PRIVATE_MAXON_VTABLE(ErrorInterface, o_); 
	mt_.ErrorInterface_SetMachine(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ErrorInterface_SetMachine_Offset, machine);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::Hxx1::ConstFn<S>::PrivateGetCode() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ErrorInterface* o_ = (const ErrorInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ErrorInterface::NullValuePtr(); if (!o_) return 0; } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ErrorInterface, o_, ErrorInterface_PrivateGetCode) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ErrorInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ErrorInterface>() : PRIVATE_MAXON_VTABLE(ErrorInterface, o_); 
	return (mt_.ErrorInterface_PrivateGetCode(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.ErrorInterface_PrivateGetCode_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::Hxx1::Fn<S>::PrivateSetCode(Int code) const -> DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S)
{
	static_assert(!S::HAS_ERROR, "ErrorInterface::PrivateSetCode can't be used on a Result object because it does not return a Result object itself."); ErrorInterface* o_ = (ErrorInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { DebugStop(); return this->PrivateGetRefMember(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ErrorInterface, o_, ErrorInterface_PrivateSetCode) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ErrorInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ErrorInterface>() : PRIVATE_MAXON_VTABLE(ErrorInterface, o_); 
	mt_.ErrorInterface_PrivateSetCode(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ErrorInterface_PrivateSetCode_Offset, code);
	return this->PrivateGetRefMember();
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::Hxx1::COWFn<S>::PrivateSetCode(Int code) -> DOXYGEN_SWITCH(maxon::RefMemberType<S>, S)
{
	static_assert(!S::HAS_ERROR, "ErrorInterface::PrivateSetCode can't be used on a Result object because it does not return a Result object itself."); ErrorInterface* o_ = (ErrorInterface*) this->MakeWritable(false).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return this->PrivateGetRefMember(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ErrorInterface, o_, ErrorInterface_PrivateSetCode) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ErrorInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ErrorInterface>() : PRIVATE_MAXON_VTABLE(ErrorInterface, o_); 
	mt_.ErrorInterface_PrivateSetCode(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ErrorInterface_PrivateSetCode_Offset, code);
	return this->PrivateGetRefMember();
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::Hxx1::ConstFn<S>::PrivateSetPreallocation(ThreadReferencedError preallocation) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ErrorInterface* o_ = (const ErrorInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ErrorInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ErrorInterface, o_, ErrorInterface_PrivateSetPreallocation) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ErrorInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ErrorInterface>() : PRIVATE_MAXON_VTABLE(ErrorInterface, o_); 
	mt_.ErrorInterface_PrivateSetPreallocation(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.ErrorInterface_PrivateSetPreallocation_Offset, std::forward<ThreadReferencedError>(preallocation));
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::Hxx1::ConstFn<S>::PrivateGetPreallocation() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<ThreadReferencedError>, ThreadReferencedError>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<ThreadReferencedError>, ThreadReferencedError>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ErrorInterface* o_ = (const ErrorInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ErrorInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<ThreadReferencedError>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ErrorInterface, o_, ErrorInterface_PrivateGetPreallocation) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ErrorInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ErrorInterface>() : PRIVATE_MAXON_VTABLE(ErrorInterface, o_); 
	return (mt_.ErrorInterface_PrivateGetPreallocation(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.ErrorInterface_PrivateGetPreallocation_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::Hxx1::ConstFn<S>::PrivateSetDebugError(const Error& cause) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ErrorInterface* o_ = (const ErrorInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ErrorInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ErrorInterface, o_, ErrorInterface_PrivateSetDebugError) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ErrorInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ErrorInterface>() : PRIVATE_MAXON_VTABLE(ErrorInterface, o_); 
	mt_.ErrorInterface_PrivateSetDebugError(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.ErrorInterface_PrivateSetDebugError_Offset, cause);
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

