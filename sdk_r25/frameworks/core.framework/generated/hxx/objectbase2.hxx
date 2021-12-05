
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
constexpr const maxon::Char* ClassInterface::PrivateGetCppName() { return "maxon::Class"; }

struct ClassInterface::MTable
{
	static MTable _instance;
	static MTable _unresolvedInstance;
	static const maxon::Char* const _ids;
	static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl);
	static const maxon::NULL_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = true;
	void (*_ClassInterface_Free) (const ClassInterface* object);
	ClassInterface* (*_ClassInterface_Alloc) (const maxon::SourceLocation& allocLocation, const Id& cid, KIND kind);
	const Id& (*_ClassInterface_GetId) (const ClassInterface* this_);
	KIND (*_ClassInterface_GetKind) (const ClassInterface* this_);
	Block<const ComponentInfo* const> (*_ClassInterface_GetComponents) (const ClassInterface* this_);
	Result<void> (*_ClassInterface_AddComponent) (ClassInterface* this_, const ComponentDescriptor& component);
	void (*_ClassInterface_RemoveLastComponent) (ClassInterface* this_);
	Result<void> (*_ClassInterface_AddComponents) (ClassInterface* this_, const Class<>& cls);
	Result<void> (*_ClassInterface_Finalize) (ClassInterface* this_);
	Bool (*_ClassInterface_IsFinalized) (const ClassInterface* this_);
	const Block<const InterfaceReference* const>& (*_ClassInterface_GetImplementedInterfaces) (const ClassInterface* this_);
	const DataType& (*_ClassInterface_GetDataType) (const ClassInterface* this_);
	Result<typename maxon::details::ClassGetNonConst<REF>::type> (*_ClassInterface_Create) (const ClassInterface* this_);
	Result<ObjectInterface*> (*_ClassInterface_CreatePointer) (const ClassInterface* this_);
	Bool (*_ClassInterface_IsSubclassOf) (const ClassInterface* this_, const Class<>& other);
	String (*_ClassInterface_ToString) (const ClassInterface* this_, const FormatStatement* formatStatement);
	const DataDictionary& (*_ClassInterface_GetMetaData) (const ClassInterface* this_);
	void (*_ClassInterface_InitMetaData) (ClassInterface* this_, DataDictionary&& data);
	void (*_ClassInterface_DeleteInstance) (const ObjectInterface* object);
	void (*_ClassInterface_DestructInstance) (const ObjectInterface* object);
	Result<void> (*_ClassInterface_CopyInstance) (ObjectInterface* dest, const ObjectInterface* src);
	const ClassInfo* (*_ClassInterface_GetInfo) (const ClassInterface* this_);
	void* (*_ClassInterface_GetOrCreateMTable) (ClassInfo* info, const InterfaceReference& i);
	Result<Int> (*_ClassInterface_AddProxyComponent) (ClassInterface* this_, const ComponentDescriptor& component, Bool shared);
	template <typename IMPL> void Init()
	{
		_ClassInterface_Free = &IMPL::_ClassInterface_Free;
		_ClassInterface_Alloc = &IMPL::_ClassInterface_Alloc;
		_ClassInterface_GetId = &IMPL::_ClassInterface_GetId;
		_ClassInterface_GetKind = &IMPL::_ClassInterface_GetKind;
		_ClassInterface_GetComponents = &IMPL::_ClassInterface_GetComponents;
		_ClassInterface_AddComponent = &IMPL::_ClassInterface_AddComponent;
		_ClassInterface_RemoveLastComponent = &IMPL::_ClassInterface_RemoveLastComponent;
		_ClassInterface_AddComponents = &IMPL::_ClassInterface_AddComponents;
		_ClassInterface_Finalize = &IMPL::_ClassInterface_Finalize;
		_ClassInterface_IsFinalized = &IMPL::_ClassInterface_IsFinalized;
		_ClassInterface_GetImplementedInterfaces = &IMPL::_ClassInterface_GetImplementedInterfaces;
		_ClassInterface_GetDataType = &IMPL::_ClassInterface_GetDataType;
		_ClassInterface_Create = &IMPL::_ClassInterface_Create;
		_ClassInterface_CreatePointer = &IMPL::_ClassInterface_CreatePointer;
		_ClassInterface_IsSubclassOf = &IMPL::_ClassInterface_IsSubclassOf;
		_ClassInterface_ToString = &IMPL::_ClassInterface_ToString;
		_ClassInterface_GetMetaData = &IMPL::_ClassInterface_GetMetaData;
		_ClassInterface_InitMetaData = &IMPL::_ClassInterface_InitMetaData;
		_ClassInterface_DeleteInstance = &IMPL::_ClassInterface_DeleteInstance;
		_ClassInterface_DestructInstance = &IMPL::_ClassInterface_DestructInstance;
		_ClassInterface_CopyInstance = &IMPL::_ClassInterface_CopyInstance;
		_ClassInterface_GetInfo = &IMPL::_ClassInterface_GetInfo;
		_ClassInterface_GetOrCreateMTable = &IMPL::_ClassInterface_GetOrCreateMTable;
		_ClassInterface_AddProxyComponent = &IMPL::_ClassInterface_AddProxyComponent;
	}
};

struct ClassInterface::Hxx2
{
	class Unresolved;
	template <typename C> class Wrapper
	{
	public:
		static void _ClassInterface_Free(const ClassInterface* object) { return C::Free(object); }
		static ClassInterface* _ClassInterface_Alloc(const maxon::SourceLocation& allocLocation, const Id& cid, KIND kind) { return C::Alloc(allocLocation, cid, kind); }
		static const Id& _ClassInterface_GetId(const ClassInterface* this_) { return C::Get(this_)->GetId(); }
		static KIND _ClassInterface_GetKind(const ClassInterface* this_) { return C::Get(this_)->GetKind(); }
		static Block<const ComponentInfo* const> _ClassInterface_GetComponents(const ClassInterface* this_) { return C::Get(this_)->GetComponents(); }
		static Result<void> _ClassInterface_AddComponent(ClassInterface* this_, const ComponentDescriptor& component) { return C::Get(this_)->AddComponent(component); }
		static void _ClassInterface_RemoveLastComponent(ClassInterface* this_) { return C::Get(this_)->RemoveLastComponent(); }
		static Result<void> _ClassInterface_AddComponents(ClassInterface* this_, const Class<>& cls) { return C::Get(this_)->AddComponents(cls); }
		static Result<void> _ClassInterface_Finalize(ClassInterface* this_) { return C::Get(this_)->Finalize(); }
		static Bool _ClassInterface_IsFinalized(const ClassInterface* this_) { return C::Get(this_)->IsFinalized(); }
		static const Block<const InterfaceReference* const>& _ClassInterface_GetImplementedInterfaces(const ClassInterface* this_) { return C::Get(this_)->GetImplementedInterfaces(); }
		static const DataType& _ClassInterface_GetDataType(const ClassInterface* this_) { return C::Get(this_)->GetDataType(); }
		static Result<typename maxon::details::ClassGetNonConst<REF>::type> _ClassInterface_Create(const ClassInterface* this_) { return C::Get(this_)->Create(); }
		static Result<ObjectInterface*> _ClassInterface_CreatePointer(const ClassInterface* this_) { return C::Get(this_)->CreatePointer(); }
		static Bool _ClassInterface_IsSubclassOf(const ClassInterface* this_, const Class<>& other) { return C::Get(this_)->IsSubclassOf(other); }
		static String _ClassInterface_ToString(const ClassInterface* this_, const FormatStatement* formatStatement) { return C::Get(this_)->ToString(formatStatement); }
		static const DataDictionary& _ClassInterface_GetMetaData(const ClassInterface* this_) { return C::Get(this_)->GetMetaData(); }
		static void _ClassInterface_InitMetaData(ClassInterface* this_, DataDictionary&& data) { return C::Get(this_)->InitMetaData(std::forward<DataDictionary>(data)); }
		static void _ClassInterface_DeleteInstance(const ObjectInterface* object) { return C::DeleteInstance(object); }
		static void _ClassInterface_DestructInstance(const ObjectInterface* object) { return C::DestructInstance(object); }
		static Result<void> _ClassInterface_CopyInstance(ObjectInterface* dest, const ObjectInterface* src) { return C::CopyInstance(dest, src); }
		static const ClassInfo* _ClassInterface_GetInfo(const ClassInterface* this_) { return C::Get(this_)->GetInfo(); }
		static void* _ClassInterface_GetOrCreateMTable(ClassInfo* info, const InterfaceReference& i) { return C::GetOrCreateMTable(info, i); }
		static Result<Int> _ClassInterface_AddProxyComponent(ClassInterface* this_, const ComponentDescriptor& component, Bool shared) { return C::Get(this_)->AddProxyComponent(component, shared); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto ClassInterface::Free(const ClassInterface* object) -> void
{
	return MTable::_instance._ClassInterface_Free(object);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ClassInterface::Alloc(const maxon::SourceLocation& allocLocation, const Id& cid, KIND kind) -> ClassInterface*
{
	return MTable::_instance._ClassInterface_Alloc(allocLocation, cid, kind);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ClassInterface::GetId() const -> const Id&
{
	return MTable::_instance._ClassInterface_GetId(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ClassInterface::GetKind() const -> KIND
{
	return MTable::_instance._ClassInterface_GetKind(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ClassInterface::GetComponents() const -> Block<const ComponentInfo* const>
{
	return MTable::_instance._ClassInterface_GetComponents(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ClassInterface::AddComponent(const ComponentDescriptor& component) -> Result<void>
{
	return MTable::_instance._ClassInterface_AddComponent(this, component);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ClassInterface::RemoveLastComponent() -> void
{
	return MTable::_instance._ClassInterface_RemoveLastComponent(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ClassInterface::AddComponents(const Class<>& cls) -> Result<void>
{
	return MTable::_instance._ClassInterface_AddComponents(this, cls);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ClassInterface::Finalize() -> Result<void>
{
	return MTable::_instance._ClassInterface_Finalize(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ClassInterface::IsFinalized() const -> Bool
{
	return MTable::_instance._ClassInterface_IsFinalized(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ClassInterface::GetImplementedInterfaces() const -> const Block<const InterfaceReference* const>&
{
	return MTable::_instance._ClassInterface_GetImplementedInterfaces(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ClassInterface::GetDataType() const -> const DataType&
{
	return MTable::_instance._ClassInterface_GetDataType(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ClassInterface::Create() const -> Result<typename maxon::details::ClassGetNonConst<REF>::type>
{
	return MTable::_instance._ClassInterface_Create(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ClassInterface::CreatePointer() const -> Result<ObjectInterface*>
{
	return MTable::_instance._ClassInterface_CreatePointer(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ClassInterface::IsSubclassOf(const Class<>& other) const -> Bool
{
	return MTable::_instance._ClassInterface_IsSubclassOf(this, other);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ClassInterface::ToString(const FormatStatement* formatStatement) const -> String
{
	return MTable::_instance._ClassInterface_ToString(this, formatStatement);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ClassInterface::GetMetaData() const -> const DataDictionary&
{
	return MTable::_instance._ClassInterface_GetMetaData(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ClassInterface::InitMetaData(DataDictionary&& data) -> void
{
	return MTable::_instance._ClassInterface_InitMetaData(this, std::forward<DataDictionary>(data));
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ClassInterface::DeleteInstance(const ObjectInterface* object) -> void
{
	return MTable::_instance._ClassInterface_DeleteInstance(object);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ClassInterface::DestructInstance(const ObjectInterface* object) -> void
{
	return MTable::_instance._ClassInterface_DestructInstance(object);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ClassInterface::CopyInstance(ObjectInterface* dest, const ObjectInterface* src) -> Result<void>
{
	return MTable::_instance._ClassInterface_CopyInstance(dest, src);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ClassInterface::GetInfo() const -> const ClassInfo*
{
	return MTable::_instance._ClassInterface_GetInfo(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ClassInterface::GetOrCreateMTable(ClassInfo* info, const InterfaceReference& i) -> void*
{
	return MTable::_instance._ClassInterface_GetOrCreateMTable(info, i);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ClassInterface::AddProxyComponent(const ComponentDescriptor& component, Bool shared) -> Result<Int>
{
	return MTable::_instance._ClassInterface_AddProxyComponent(this, component, shared);
}

template <typename REF_> auto ClassInterface::Hxx1::Reference<REF_>::Create(const Id& cid, KIND kind) -> maxon::ResultMemT<Class<REF_>>
{
	ClassInterface* res_ = ClassInterface::Alloc(MAXON_SOURCE_LOCATION, cid, kind);
	return Class<REF_>(maxon::ForwardResultPtr<ClassInterface>(res_));
}
template <typename S, typename REF_> MAXON_ATTRIBUTE_FORCE_INLINE auto ClassInterface::Hxx1::ConstReferenceFunctionsImpl<S, REF_>::GetId() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const Id&>, const Id&>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const Id&>, const Id&>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ClassInterface* o_ = (const ClassInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ClassInterface::NullValuePtr(); if (!o_) return maxon::PrivateNullReturnValue<const Id&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (MTable::_instance._ClassInterface_GetId(o_));
}
template <typename S, typename REF_> MAXON_ATTRIBUTE_FORCE_INLINE auto ClassInterface::Hxx1::ConstReferenceFunctionsImpl<S, REF_>::GetKind() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<KIND>, KIND>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<KIND>, KIND>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ClassInterface* o_ = (const ClassInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ClassInterface::NullValuePtr(); if (!o_) return maxon::PrivateNullReturnValue<KIND>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (MTable::_instance._ClassInterface_GetKind(o_));
}
template <typename S, typename REF_> MAXON_ATTRIBUTE_FORCE_INLINE auto ClassInterface::Hxx1::ConstReferenceFunctionsImpl<S, REF_>::GetComponents() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Block<const ComponentInfo* const>>, Block<const ComponentInfo* const>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Block<const ComponentInfo* const>>, Block<const ComponentInfo* const>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ClassInterface* o_ = (const ClassInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ClassInterface::NullValuePtr(); if (!o_) return maxon::PrivateNullReturnValue<Block<const ComponentInfo* const>>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (MTable::_instance._ClassInterface_GetComponents(o_));
}
template <typename S, typename REF_> MAXON_ATTRIBUTE_FORCE_INLINE auto ClassInterface::Hxx1::ReferenceFunctionsImpl<S, REF_>::AddComponent(const ComponentDescriptor& component) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ClassInterface* o_ = (ClassInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance._ClassInterface_AddComponent(o_, component));
}
template <typename S, typename REF_> MAXON_ATTRIBUTE_FORCE_INLINE auto ClassInterface::Hxx1::ReferenceFunctionsImpl<S, REF_>::AddComponents(const Class<>& cls) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ClassInterface* o_ = (ClassInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance._ClassInterface_AddComponents(o_, cls));
}
template <typename S, typename REF_> MAXON_ATTRIBUTE_FORCE_INLINE auto ClassInterface::Hxx1::ReferenceFunctionsImpl<S, REF_>::Finalize() const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ClassInterface* o_ = (ClassInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance._ClassInterface_Finalize(o_));
}
template <typename S, typename REF_> MAXON_ATTRIBUTE_FORCE_INLINE auto ClassInterface::Hxx1::ConstReferenceFunctionsImpl<S, REF_>::IsFinalized() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ClassInterface* o_ = (const ClassInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ClassInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (MTable::_instance._ClassInterface_IsFinalized(o_));
}
template <typename S, typename REF_> MAXON_ATTRIBUTE_FORCE_INLINE auto ClassInterface::Hxx1::ConstReferenceFunctionsImpl<S, REF_>::GetImplementedInterfaces() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const Block<const InterfaceReference* const>&>, const Block<const InterfaceReference* const>&>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const Block<const InterfaceReference* const>&>, const Block<const InterfaceReference* const>&>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ClassInterface* o_ = (const ClassInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ClassInterface::NullValuePtr(); if (!o_) return maxon::PrivateNullReturnValue<const Block<const InterfaceReference* const>&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (MTable::_instance._ClassInterface_GetImplementedInterfaces(o_));
}
template <typename S, typename REF_> MAXON_ATTRIBUTE_FORCE_INLINE auto ClassInterface::Hxx1::ConstReferenceFunctionsImpl<S, REF_>::GetDataType() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const DataType&>, const DataType&>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const DataType&>, const DataType&>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ClassInterface* o_ = (const ClassInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ClassInterface::NullValuePtr(); if (!o_) return maxon::PrivateNullReturnValue<const DataType&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (MTable::_instance._ClassInterface_GetDataType(o_));
}
template <typename S, typename REF_> MAXON_ATTRIBUTE_FORCE_INLINE auto ClassInterface::Hxx1::ConstReferenceFunctionsImpl<S, REF_>::Create() const -> Result<typename maxon::details::ClassGetNonConst<REF_>::type>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<typename maxon::details::ClassGetNonConst<REF_>::type>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ClassInterface* o_ = (const ClassInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ClassInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return maxon::GenericReinterpretCast<typename ReturnHelper::ReturnType>(MTable::_instance._ClassInterface_Create(o_));
}
template <typename S, typename REF_> MAXON_ATTRIBUTE_FORCE_INLINE auto ClassInterface::Hxx1::ConstReferenceFunctionsImpl<S, REF_>::Implements(const InterfaceReference& iref) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ClassInterface* o_ = (const ClassInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ClassInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (o_->Implements(iref));
}
template <typename S, typename REF_> template <typename I> MAXON_ATTRIBUTE_FORCE_INLINE auto ClassInterface::Hxx1::ConstReferenceFunctionsImpl<S, REF_>::Implements() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ClassInterface* o_ = (const ClassInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ClassInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (o_->Implements<I>());
}
template <typename S, typename REF_> MAXON_ATTRIBUTE_FORCE_INLINE auto ClassInterface::Hxx1::ConstReferenceFunctionsImpl<S, REF_>::IsSubclassOf(const Class<>& other) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ClassInterface* o_ = (const ClassInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ClassInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (MTable::_instance._ClassInterface_IsSubclassOf(o_, other));
}
template <typename S, typename REF_> MAXON_ATTRIBUTE_FORCE_INLINE auto ClassInterface::Hxx1::ConstReferenceFunctionsImpl<S, REF_>::ToString(const FormatStatement* formatStatement) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ClassInterface* o_ = (const ClassInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ClassInterface::NullValuePtr(); if (!o_) return maxon::PrivateNullReturnValue<String>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (MTable::_instance._ClassInterface_ToString(o_, formatStatement));
}
template <typename S, typename REF_> MAXON_ATTRIBUTE_FORCE_INLINE auto ClassInterface::Hxx1::ConstReferenceFunctionsImpl<S, REF_>::GetMetaData() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const DataDictionary&>, const DataDictionary&>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const DataDictionary&>, const DataDictionary&>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ClassInterface* o_ = (const ClassInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ClassInterface::NullValuePtr(); if (!o_) return maxon::PrivateNullReturnValue<const DataDictionary&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (MTable::_instance._ClassInterface_GetMetaData(o_));
}
template <typename S, typename REF_> MAXON_ATTRIBUTE_FORCE_INLINE auto ClassInterface::Hxx1::ReferenceFunctionsImpl<S, REF_>::InitMetaData(DataDictionary&& data) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ClassInterface* o_ = (ClassInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { DebugStop(); return maxon::PrivateLogNullptrError(); } 
	MTable::_instance._ClassInterface_InitMetaData(o_, std::forward<DataDictionary>(data));
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S, typename REF_> MAXON_ATTRIBUTE_FORCE_INLINE auto ClassInterface::Hxx1::ConstReferenceFunctionsImpl<S, REF_>::DeleteInstance(const ObjectInterface* object) -> void
{
	return (MTable::_instance._ClassInterface_DeleteInstance(object));
}
template <typename S, typename REF_> MAXON_ATTRIBUTE_FORCE_INLINE auto ClassInterface::Hxx1::ConstReferenceFunctionsImpl<S, REF_>::DestructInstance(const ObjectInterface* object) -> void
{
	return (MTable::_instance._ClassInterface_DestructInstance(object));
}
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
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
	String (*_ObjectInterface_ToString) (const maxon::GenericComponent* this_, const FormatStatement* formatStatement);
	maxon::Int _ObjectInterface_ToString_Offset;
	Result<void> (*_ObjectInterface_InitObject) (maxon::GenericComponent* this_, const void* argument);
	maxon::Int _ObjectInterface_InitObject_Offset;
	Result<void> (*_ObjectInterface_HandleMessage) (maxon::GenericComponent* this_, const InternedId& message, void* argument);
	maxon::Int _ObjectInterface_HandleMessage_Offset;
	Result<void> (*_ObjectInterface_HandleConstMessage) (const maxon::GenericComponent* this_, const InternedId& message, void* argument);
	maxon::Int _ObjectInterface_HandleConstMessage_Offset;
	Bool (*_ObjectInterface_IsEqual) (const maxon::GenericComponent* this_, const maxon::ObjectInterface* other);
	maxon::Int _ObjectInterface_IsEqual_Offset;
	COMPARERESULT (*_ObjectInterface_Compare) (const maxon::GenericComponent* this_, const maxon::ObjectInterface* other);
	maxon::Int _ObjectInterface_Compare_Offset;
	HashInt (*_ObjectInterface_GetHashCodeImpl) (const maxon::GenericComponent* this_);
	maxon::Int _ObjectInterface_GetHashCodeImpl_Offset;
	HashValue (*_ObjectInterface_GetHashValueImpl) (const maxon::GenericComponent* this_);
	maxon::Int _ObjectInterface_GetHashValueImpl_Offset;
/// @cond INTERNAL

/// @endcond

	template <typename W> void Init(maxon::Int offset)
	{
	if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ObjectInterface, ToString))
	{
		auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ObjectInterface, ToString), W, MTable>::type::_ObjectInterface_ToString;
		_ObjectInterface_ToString = reinterpret_cast<const decltype(_ObjectInterface_ToString)&>(ptr);
		_ObjectInterface_ToString_Offset = offset;
	}
	if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ObjectInterface, InitObject))
	{
		auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ObjectInterface, InitObject), W, MTable>::type::_ObjectInterface_InitObject;
		_ObjectInterface_InitObject = reinterpret_cast<const decltype(_ObjectInterface_InitObject)&>(ptr);
		_ObjectInterface_InitObject_Offset = offset;
	}
	if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ObjectInterface, HandleMessage))
	{
		auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ObjectInterface, HandleMessage), W, MTable>::type::_ObjectInterface_HandleMessage;
		_ObjectInterface_HandleMessage = reinterpret_cast<const decltype(_ObjectInterface_HandleMessage)&>(ptr);
		_ObjectInterface_HandleMessage_Offset = offset;
	}
	if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ObjectInterface, HandleConstMessage))
	{
		auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ObjectInterface, HandleConstMessage), W, MTable>::type::_ObjectInterface_HandleConstMessage;
		_ObjectInterface_HandleConstMessage = reinterpret_cast<const decltype(_ObjectInterface_HandleConstMessage)&>(ptr);
		_ObjectInterface_HandleConstMessage_Offset = offset;
	}
	if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ObjectInterface, IsEqual))
	{
		auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ObjectInterface, IsEqual), W, MTable>::type::_ObjectInterface_IsEqual;
		_ObjectInterface_IsEqual = reinterpret_cast<const decltype(_ObjectInterface_IsEqual)&>(ptr);
		_ObjectInterface_IsEqual_Offset = offset;
	}
	if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ObjectInterface, Compare))
	{
		auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ObjectInterface, Compare), W, MTable>::type::_ObjectInterface_Compare;
		_ObjectInterface_Compare = reinterpret_cast<const decltype(_ObjectInterface_Compare)&>(ptr);
		_ObjectInterface_Compare_Offset = offset;
	}
	if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ObjectInterface, GetHashCodeImpl))
	{
		auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ObjectInterface, GetHashCodeImpl), W, MTable>::type::_ObjectInterface_GetHashCodeImpl;
		_ObjectInterface_GetHashCodeImpl = reinterpret_cast<const decltype(_ObjectInterface_GetHashCodeImpl)&>(ptr);
		_ObjectInterface_GetHashCodeImpl_Offset = offset;
	}
	if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ObjectInterface, GetHashValueImpl))
	{
		auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ObjectInterface, GetHashValueImpl), W, MTable>::type::_ObjectInterface_GetHashValueImpl;
		_ObjectInterface_GetHashValueImpl = reinterpret_cast<const decltype(_ObjectInterface_GetHashValueImpl)&>(ptr);
		_ObjectInterface_GetHashValueImpl_Offset = offset;
	}
/// @cond INTERNAL

/// @endcond

	}
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset)
	{
		MTable* vt = (MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, _interface); if (!vt) return false;
		vt->Init<W>(offset);
		return true;
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
		static String _ObjectInterface_ToString(const maxon::GenericComponent* this_, const FormatStatement* formatStatement) { return ((const typename S::Implementation*) this_)->ToString(formatStatement); }
		static Result<void> _ObjectInterface_InitObject(maxon::GenericComponent* this_, const void* argument) { return ((typename S::Implementation*) this_)->InitObject(argument); }
		static Result<void> _ObjectInterface_HandleMessage(maxon::GenericComponent* this_, const InternedId& message, void* argument) { return ((typename S::Implementation*) this_)->HandleMessage(message, argument); }
		static Result<void> _ObjectInterface_HandleConstMessage(const maxon::GenericComponent* this_, const InternedId& message, void* argument) { return ((const typename S::Implementation*) this_)->HandleConstMessage(message, argument); }
		static Bool _ObjectInterface_IsEqual(const maxon::GenericComponent* this_, const maxon::ObjectInterface* other) { return ((const typename S::Implementation*) this_)->IsEqual(other); }
		static COMPARERESULT _ObjectInterface_Compare(const maxon::GenericComponent* this_, const maxon::ObjectInterface* other) { return ((const typename S::Implementation*) this_)->Compare(other); }
		static HashInt _ObjectInterface_GetHashCodeImpl(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetHashCodeImpl(); }
		static HashValue _ObjectInterface_GetHashValueImpl(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetHashValueImpl(); }
/// @cond INTERNAL

/// @endcond

	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto ObjectInterface::ToString(const FormatStatement* formatStatement) const -> String
{
	const ObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ObjectInterface, this); return mt_._ObjectInterface_ToString((const maxon::GenericComponent*) this + mt_._ObjectInterface_ToString_Offset, formatStatement);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ObjectInterface::InitObject(const void* argument) -> Result<void>
{
	const ObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ObjectInterface, this); return mt_._ObjectInterface_InitObject((maxon::GenericComponent*) this + mt_._ObjectInterface_InitObject_Offset, argument);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ObjectInterface::HandleMessage(const InternedId& message, void* argument) -> Result<void>
{
	const ObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ObjectInterface, this); return mt_._ObjectInterface_HandleMessage((maxon::GenericComponent*) this + mt_._ObjectInterface_HandleMessage_Offset, message, argument);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ObjectInterface::HandleConstMessage(const InternedId& message, void* argument) const -> Result<void>
{
	const ObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ObjectInterface, this); return mt_._ObjectInterface_HandleConstMessage((const maxon::GenericComponent*) this + mt_._ObjectInterface_HandleConstMessage_Offset, message, argument);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ObjectInterface::IsEqual(const maxon::ObjectInterface* other) const -> Bool
{
	const ObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ObjectInterface, this); return mt_._ObjectInterface_IsEqual((const maxon::GenericComponent*) this + mt_._ObjectInterface_IsEqual_Offset, other);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ObjectInterface::Compare(const maxon::ObjectInterface* other) const -> COMPARERESULT
{
	const ObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ObjectInterface, this); return mt_._ObjectInterface_Compare((const maxon::GenericComponent*) this + mt_._ObjectInterface_Compare_Offset, other);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ObjectInterface::GetHashCodeImpl() const -> HashInt
{
	const ObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ObjectInterface, this); return mt_._ObjectInterface_GetHashCodeImpl((const maxon::GenericComponent*) this + mt_._ObjectInterface_GetHashCodeImpl_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ObjectInterface::GetHashValueImpl() const -> HashValue
{
	const ObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ObjectInterface, this); return mt_._ObjectInterface_GetHashValueImpl((const maxon::GenericComponent*) this + mt_._ObjectInterface_GetHashValueImpl_Offset);
}
/// @cond INTERNAL

/// @endcond


template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ObjectInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetClass() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const maxon::Class<typename maxon::details::GetPrivateReferencedType<S>::Hxx1::ReferenceClass>&>, const maxon::Class<typename maxon::details::GetPrivateReferencedType<S>::Hxx1::ReferenceClass>&>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const maxon::Class<typename maxon::details::GetPrivateReferencedType<S>::Hxx1::ReferenceClass>&>, const maxon::Class<typename maxon::details::GetPrivateReferencedType<S>::Hxx1::ReferenceClass>&>::type>; static_assert(!std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value, "Can't invoke MAXON_FUNCTION ObjectInterface::GetClass on super."); if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ObjectInterface* o_ = (const ObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ObjectInterface::NullValuePtr(); if (!o_) return maxon::PrivateNullReturnValue<const maxon::Class<typename maxon::details::GetPrivateReferencedType<S>::Hxx1::ReferenceClass>&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (o_->GetClass<maxon::details::GetPrivateReferencedType<S>>());
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ObjectInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetClassInfo() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const ClassInfo*>, const ClassInfo*>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const ClassInfo*>, const ClassInfo*>::type>; static_assert(!std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value, "Can't invoke MAXON_FUNCTION ObjectInterface::GetClassInfo on super."); if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ObjectInterface* o_ = (const ObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ObjectInterface::NullValuePtr(); if (!o_) return nullptr; } 
	return (o_->GetClassInfo());
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ObjectInterface::Hxx1::ConstReferenceFunctionsImpl<S>::HasSameClass(const ObjectInterface* obj) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; static_assert(!std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value, "Can't invoke MAXON_FUNCTION ObjectInterface::HasSameClass on super."); if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ObjectInterface* o_ = (const ObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ObjectInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (o_->HasSameClass(obj));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ObjectInterface::Hxx1::ConstReferenceFunctionsImpl<S>::Clone() const -> Result<maxon::details::GetReferenceClass<S>>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<maxon::details::GetReferenceClass<S>>>; static_assert(!std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value, "Can't invoke MAXON_FUNCTION ObjectInterface::Clone on super."); if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ObjectInterface* o_ = (const ObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ObjectInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->Clone<maxon::details::GetReferenceClass<S>>());
}
template <typename S> template <typename I> MAXON_ATTRIBUTE_FORCE_INLINE auto ObjectInterface::Hxx1::ConstReferenceFunctionsImpl<S>::IsInstanceOf() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; static_assert(!std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value, "Can't invoke MAXON_FUNCTION ObjectInterface::IsInstanceOf on super."); if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ObjectInterface* o_ = (const ObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ObjectInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (o_->IsInstanceOf<I>());
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ObjectInterface::Hxx1::ConstReferenceFunctionsImpl<S>::IsInstanceOf(const DataType& type) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; static_assert(!std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value, "Can't invoke MAXON_FUNCTION ObjectInterface::IsInstanceOf on super."); if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ObjectInterface* o_ = (const ObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ObjectInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (o_->IsInstanceOf(type));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ObjectInterface::Hxx1::ConstReferenceFunctionsImpl<S>::ToString(const FormatStatement* formatStatement) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ObjectInterface* o_ = (const ObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ObjectInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ObjectInterface, o_, ObjectInterface_ToString) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ObjectInterface>() : PRIVATE_MAXON_VTABLE(ObjectInterface, o_); 
	return (mt_._ObjectInterface_ToString(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._ObjectInterface_ToString_Offset, formatStatement));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ObjectInterface::Hxx1::ReferenceFunctionsImpl<S>::InitObject(const void* argument) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ObjectInterface* o_ = (ObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ObjectInterface, o_, ObjectInterface_InitObject) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ObjectInterface>() : PRIVATE_MAXON_VTABLE(ObjectInterface, o_); 
	return (mt_._ObjectInterface_InitObject(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._ObjectInterface_InitObject_Offset, argument));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ObjectInterface::Hxx1::COWReferenceFunctionsImpl<S>::InitObject(const void* argument) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ObjectInterface* o_ = (ObjectInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ObjectInterface, o_, ObjectInterface_InitObject) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ObjectInterface>() : PRIVATE_MAXON_VTABLE(ObjectInterface, o_); 
	return (mt_._ObjectInterface_InitObject(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._ObjectInterface_InitObject_Offset, argument));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ObjectInterface::Hxx1::ReferenceFunctionsImpl<S>::HandleMessage(const InternedId& message, void* argument) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ObjectInterface* o_ = (ObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ObjectInterface, o_, ObjectInterface_HandleMessage) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ObjectInterface>() : PRIVATE_MAXON_VTABLE(ObjectInterface, o_); 
	return (mt_._ObjectInterface_HandleMessage(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._ObjectInterface_HandleMessage_Offset, message, argument));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ObjectInterface::Hxx1::COWReferenceFunctionsImpl<S>::HandleMessage(const InternedId& message, void* argument) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ObjectInterface* o_ = (ObjectInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ObjectInterface, o_, ObjectInterface_HandleMessage) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ObjectInterface>() : PRIVATE_MAXON_VTABLE(ObjectInterface, o_); 
	return (mt_._ObjectInterface_HandleMessage(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._ObjectInterface_HandleMessage_Offset, message, argument));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ObjectInterface::Hxx1::ConstReferenceFunctionsImpl<S>::HandleConstMessage(const InternedId& message, void* argument) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ObjectInterface* o_ = (const ObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ObjectInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ObjectInterface, o_, ObjectInterface_HandleConstMessage) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ObjectInterface>() : PRIVATE_MAXON_VTABLE(ObjectInterface, o_); 
	return (mt_._ObjectInterface_HandleConstMessage(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._ObjectInterface_HandleConstMessage_Offset, message, argument));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ObjectInterface::Hxx1::ConstReferenceFunctionsImpl<S>::IsEqual(const maxon::ObjectInterface* other) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ObjectInterface* o_ = (const ObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ObjectInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ObjectInterface, o_, ObjectInterface_IsEqual) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ObjectInterface>() : PRIVATE_MAXON_VTABLE(ObjectInterface, o_); 
	return (mt_._ObjectInterface_IsEqual(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._ObjectInterface_IsEqual_Offset, other));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ObjectInterface::Hxx1::ConstReferenceFunctionsImpl<S>::Compare(const maxon::ObjectInterface* other) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<COMPARERESULT>, COMPARERESULT>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<COMPARERESULT>, COMPARERESULT>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ObjectInterface* o_ = (const ObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ObjectInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<COMPARERESULT>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ObjectInterface, o_, ObjectInterface_Compare) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ObjectInterface>() : PRIVATE_MAXON_VTABLE(ObjectInterface, o_); 
	return (mt_._ObjectInterface_Compare(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._ObjectInterface_Compare_Offset, other));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ObjectInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetHashCodeImpl() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<HashInt>, HashInt>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<HashInt>, HashInt>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ObjectInterface* o_ = (const ObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ObjectInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<HashInt>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ObjectInterface, o_, ObjectInterface_GetHashCodeImpl) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ObjectInterface>() : PRIVATE_MAXON_VTABLE(ObjectInterface, o_); 
	return (mt_._ObjectInterface_GetHashCodeImpl(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._ObjectInterface_GetHashCodeImpl_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ObjectInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetHashValueImpl() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<HashValue>, HashValue>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<HashValue>, HashValue>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ObjectInterface* o_ = (const ObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ObjectInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<HashValue>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ObjectInterface, o_, ObjectInterface_GetHashValueImpl) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ObjectInterface>() : PRIVATE_MAXON_VTABLE(ObjectInterface, o_); 
	return (mt_._ObjectInterface_GetHashValueImpl(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._ObjectInterface_GetHashValueImpl_Offset));
}
/// @cond INTERNAL

/// @endcond

auto ObjectInterface::GetPtr() -> Ptr { return Ptr(this); }
auto ObjectInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
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
	const SourceLocation& (*_ErrorInterface_GetLocation) (const maxon::GenericComponent* this_);
	maxon::Int _ErrorInterface_GetLocation_Offset;
	void (*_ErrorInterface_SetLocation) (maxon::GenericComponent* this_, const maxon::SourceLocation& allocLocation);
	maxon::Int _ErrorInterface_SetLocation_Offset;
	Block<void* const> (*_ErrorInterface_GetStackTrace) (const maxon::GenericComponent* this_);
	maxon::Int _ErrorInterface_GetStackTrace_Offset;
	void (*_ErrorInterface_SetStackTrace) (maxon::GenericComponent* this_, const Block<void* const>& trace);
	maxon::Int _ErrorInterface_SetStackTrace_Offset;
	String (*_ErrorInterface_GetMessage) (const maxon::GenericComponent* this_);
	maxon::Int _ErrorInterface_GetMessage_Offset;
	void (*_ErrorInterface_SetMessage) (maxon::GenericComponent* this_, const String& message);
	maxon::Int _ErrorInterface_SetMessage_Offset;
	String (*_ErrorInterface_FormatMessage) (const maxon::GenericComponent* this_, const LanguageRef& language, const PartFormatter& partFormatter);
	maxon::Int _ErrorInterface_FormatMessage_Offset;
	void (*_ErrorInterface_SetMessageDelegate) (maxon::GenericComponent* this_, Delegate<String(const LanguageRef&language,const ErrorInterface::PartFormatter&fmt)>&& message);
	maxon::Int _ErrorInterface_SetMessageDelegate_Offset;
	const Error& (*_ErrorInterface_GetCause) (const maxon::GenericComponent* this_);
	maxon::Int _ErrorInterface_GetCause_Offset;
	void (*_ErrorInterface_SetCause) (maxon::GenericComponent* this_, const Error& cause);
	maxon::Int _ErrorInterface_SetCause_Offset;
	void (*_ErrorInterface_GetMachine) (const maxon::GenericComponent* this_, MachineRef& machine);
	maxon::Int _ErrorInterface_GetMachine_Offset;
	void (*_ErrorInterface_SetMachine) (maxon::GenericComponent* this_, const MachineRef& machine);
	maxon::Int _ErrorInterface_SetMachine_Offset;
	Int (*_ErrorInterface_PrivateGetCode) (const maxon::GenericComponent* this_);
	maxon::Int _ErrorInterface_PrivateGetCode_Offset;
	void (*_ErrorInterface_PrivateSetCode) (maxon::GenericComponent* this_, Int code);
	maxon::Int _ErrorInterface_PrivateSetCode_Offset;
	void (*_ErrorInterface_PrivateSetPreallocation) (const maxon::GenericComponent* this_, ThreadReferencedError preallocation);
	maxon::Int _ErrorInterface_PrivateSetPreallocation_Offset;
	ThreadReferencedError (*_ErrorInterface_PrivateGetPreallocation) (const maxon::GenericComponent* this_);
	maxon::Int _ErrorInterface_PrivateGetPreallocation_Offset;
	void (*_ErrorInterface_PrivateSetDebugError) (const maxon::GenericComponent* this_, const Error& cause);
	maxon::Int _ErrorInterface_PrivateSetDebugError_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ErrorInterface, GetLocation))
	{
		auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ErrorInterface, GetLocation), W, MTable>::type::_ErrorInterface_GetLocation;
		_ErrorInterface_GetLocation = reinterpret_cast<const decltype(_ErrorInterface_GetLocation)&>(ptr);
		_ErrorInterface_GetLocation_Offset = offset;
	}
	if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ErrorInterface, SetLocation))
	{
		auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ErrorInterface, SetLocation), W, MTable>::type::_ErrorInterface_SetLocation;
		_ErrorInterface_SetLocation = reinterpret_cast<const decltype(_ErrorInterface_SetLocation)&>(ptr);
		_ErrorInterface_SetLocation_Offset = offset;
	}
	if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ErrorInterface, GetStackTrace))
	{
		auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ErrorInterface, GetStackTrace), W, MTable>::type::_ErrorInterface_GetStackTrace;
		_ErrorInterface_GetStackTrace = reinterpret_cast<const decltype(_ErrorInterface_GetStackTrace)&>(ptr);
		_ErrorInterface_GetStackTrace_Offset = offset;
	}
	if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ErrorInterface, SetStackTrace))
	{
		auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ErrorInterface, SetStackTrace), W, MTable>::type::_ErrorInterface_SetStackTrace;
		_ErrorInterface_SetStackTrace = reinterpret_cast<const decltype(_ErrorInterface_SetStackTrace)&>(ptr);
		_ErrorInterface_SetStackTrace_Offset = offset;
	}
	if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ErrorInterface, GetMessage))
	{
		auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ErrorInterface, GetMessage), W, MTable>::type::_ErrorInterface_GetMessage;
		_ErrorInterface_GetMessage = reinterpret_cast<const decltype(_ErrorInterface_GetMessage)&>(ptr);
		_ErrorInterface_GetMessage_Offset = offset;
	}
	if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ErrorInterface, SetMessage))
	{
		auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ErrorInterface, SetMessage), W, MTable>::type::_ErrorInterface_SetMessage;
		_ErrorInterface_SetMessage = reinterpret_cast<const decltype(_ErrorInterface_SetMessage)&>(ptr);
		_ErrorInterface_SetMessage_Offset = offset;
	}
	if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ErrorInterface, FormatMessage))
	{
		auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ErrorInterface, FormatMessage), W, MTable>::type::_ErrorInterface_FormatMessage;
		_ErrorInterface_FormatMessage = reinterpret_cast<const decltype(_ErrorInterface_FormatMessage)&>(ptr);
		_ErrorInterface_FormatMessage_Offset = offset;
	}
	if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ErrorInterface, SetMessageDelegate))
	{
		auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ErrorInterface, SetMessageDelegate), W, MTable>::type::_ErrorInterface_SetMessageDelegate;
		_ErrorInterface_SetMessageDelegate = reinterpret_cast<const decltype(_ErrorInterface_SetMessageDelegate)&>(ptr);
		_ErrorInterface_SetMessageDelegate_Offset = offset;
	}
	if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ErrorInterface, GetCause))
	{
		auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ErrorInterface, GetCause), W, MTable>::type::_ErrorInterface_GetCause;
		_ErrorInterface_GetCause = reinterpret_cast<const decltype(_ErrorInterface_GetCause)&>(ptr);
		_ErrorInterface_GetCause_Offset = offset;
	}
	if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ErrorInterface, SetCause))
	{
		auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ErrorInterface, SetCause), W, MTable>::type::_ErrorInterface_SetCause;
		_ErrorInterface_SetCause = reinterpret_cast<const decltype(_ErrorInterface_SetCause)&>(ptr);
		_ErrorInterface_SetCause_Offset = offset;
	}
	if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ErrorInterface, GetMachine))
	{
		auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ErrorInterface, GetMachine), W, MTable>::type::_ErrorInterface_GetMachine;
		_ErrorInterface_GetMachine = reinterpret_cast<const decltype(_ErrorInterface_GetMachine)&>(ptr);
		_ErrorInterface_GetMachine_Offset = offset;
	}
	if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ErrorInterface, SetMachine))
	{
		auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ErrorInterface, SetMachine), W, MTable>::type::_ErrorInterface_SetMachine;
		_ErrorInterface_SetMachine = reinterpret_cast<const decltype(_ErrorInterface_SetMachine)&>(ptr);
		_ErrorInterface_SetMachine_Offset = offset;
	}
	if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ErrorInterface, PrivateGetCode))
	{
		auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ErrorInterface, PrivateGetCode), W, MTable>::type::_ErrorInterface_PrivateGetCode;
		_ErrorInterface_PrivateGetCode = reinterpret_cast<const decltype(_ErrorInterface_PrivateGetCode)&>(ptr);
		_ErrorInterface_PrivateGetCode_Offset = offset;
	}
	if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ErrorInterface, PrivateSetCode))
	{
		auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ErrorInterface, PrivateSetCode), W, MTable>::type::_ErrorInterface_PrivateSetCode;
		_ErrorInterface_PrivateSetCode = reinterpret_cast<const decltype(_ErrorInterface_PrivateSetCode)&>(ptr);
		_ErrorInterface_PrivateSetCode_Offset = offset;
	}
	if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ErrorInterface, PrivateSetPreallocation))
	{
		auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ErrorInterface, PrivateSetPreallocation), W, MTable>::type::_ErrorInterface_PrivateSetPreallocation;
		_ErrorInterface_PrivateSetPreallocation = reinterpret_cast<const decltype(_ErrorInterface_PrivateSetPreallocation)&>(ptr);
		_ErrorInterface_PrivateSetPreallocation_Offset = offset;
	}
	if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ErrorInterface, PrivateGetPreallocation))
	{
		auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ErrorInterface, PrivateGetPreallocation), W, MTable>::type::_ErrorInterface_PrivateGetPreallocation;
		_ErrorInterface_PrivateGetPreallocation = reinterpret_cast<const decltype(_ErrorInterface_PrivateGetPreallocation)&>(ptr);
		_ErrorInterface_PrivateGetPreallocation_Offset = offset;
	}
	if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ErrorInterface, PrivateSetDebugError))
	{
		auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ErrorInterface, PrivateSetDebugError), W, MTable>::type::_ErrorInterface_PrivateSetDebugError;
		_ErrorInterface_PrivateSetDebugError = reinterpret_cast<const decltype(_ErrorInterface_PrivateSetDebugError)&>(ptr);
		_ErrorInterface_PrivateSetDebugError_Offset = offset;
	}
	}
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset)
	{
		if (!W::Implementation::PROXY && (!ObjectInterface::MTable::template InitWithBases<W>(info, offset))) return false;
		MTable* vt = (MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, _interface); if (!vt) return false;
		vt->Init<W>(offset);
		return true;
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
		static const SourceLocation& _ErrorInterface_GetLocation(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetLocation(); }
		static void _ErrorInterface_SetLocation(maxon::GenericComponent* this_, const maxon::SourceLocation& allocLocation) { return ((typename S::Implementation*) this_)->SetLocation(allocLocation); }
		static Block<void* const> _ErrorInterface_GetStackTrace(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetStackTrace(); }
		static void _ErrorInterface_SetStackTrace(maxon::GenericComponent* this_, const Block<void* const>& trace) { return ((typename S::Implementation*) this_)->SetStackTrace(trace); }
		static String _ErrorInterface_GetMessage(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetMessage(); }
		static void _ErrorInterface_SetMessage(maxon::GenericComponent* this_, const String& message) { return ((typename S::Implementation*) this_)->SetMessage(message); }
		static String _ErrorInterface_FormatMessage(const maxon::GenericComponent* this_, const LanguageRef& language, const PartFormatter& partFormatter) { return ((const typename S::Implementation*) this_)->FormatMessage(language, partFormatter); }
		static void _ErrorInterface_SetMessageDelegate(maxon::GenericComponent* this_, Delegate<String(const LanguageRef&language,const ErrorInterface::PartFormatter&fmt)>&& message) { return ((typename S::Implementation*) this_)->SetMessageDelegate(std::forward<Delegate<String(const LanguageRef&language,const ErrorInterface::PartFormatter&fmt)>>(message)); }
		static const Error& _ErrorInterface_GetCause(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetCause(); }
		static void _ErrorInterface_SetCause(maxon::GenericComponent* this_, const Error& cause) { return ((typename S::Implementation*) this_)->SetCause(cause); }
		static void _ErrorInterface_GetMachine(const maxon::GenericComponent* this_, MachineRef& machine) { return ((const typename S::Implementation*) this_)->GetMachine(machine); }
		static void _ErrorInterface_SetMachine(maxon::GenericComponent* this_, const MachineRef& machine) { return ((typename S::Implementation*) this_)->SetMachine(machine); }
		static Int _ErrorInterface_PrivateGetCode(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->PrivateGetCode(); }
		static void _ErrorInterface_PrivateSetCode(maxon::GenericComponent* this_, Int code) { return ((typename S::Implementation*) this_)->PrivateSetCode(code); }
		static void _ErrorInterface_PrivateSetPreallocation(const maxon::GenericComponent* this_, ThreadReferencedError preallocation) { return ((const typename S::Implementation*) this_)->PrivateSetPreallocation(std::forward<ThreadReferencedError>(preallocation)); }
		static ThreadReferencedError _ErrorInterface_PrivateGetPreallocation(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->PrivateGetPreallocation(); }
		static void _ErrorInterface_PrivateSetDebugError(const maxon::GenericComponent* this_, const Error& cause) { return ((const typename S::Implementation*) this_)->PrivateSetDebugError(cause); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::GetLocation() const -> const SourceLocation&
{
	const ErrorInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ErrorInterface, this); return mt_._ErrorInterface_GetLocation((const maxon::GenericComponent*) this + mt_._ErrorInterface_GetLocation_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::SetLocation(const maxon::SourceLocation& allocLocation) -> void
{
	const ErrorInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ErrorInterface, this); return mt_._ErrorInterface_SetLocation((maxon::GenericComponent*) this + mt_._ErrorInterface_SetLocation_Offset, allocLocation);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::GetStackTrace() const -> Block<void* const>
{
	const ErrorInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ErrorInterface, this); return mt_._ErrorInterface_GetStackTrace((const maxon::GenericComponent*) this + mt_._ErrorInterface_GetStackTrace_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::SetStackTrace(const Block<void* const>& trace) -> void
{
	const ErrorInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ErrorInterface, this); return mt_._ErrorInterface_SetStackTrace((maxon::GenericComponent*) this + mt_._ErrorInterface_SetStackTrace_Offset, trace);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::GetMessage() const -> String
{
	const ErrorInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ErrorInterface, this); return mt_._ErrorInterface_GetMessage((const maxon::GenericComponent*) this + mt_._ErrorInterface_GetMessage_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::SetMessage(const String& message) -> void
{
	const ErrorInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ErrorInterface, this); return mt_._ErrorInterface_SetMessage((maxon::GenericComponent*) this + mt_._ErrorInterface_SetMessage_Offset, message);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::FormatMessage(const LanguageRef& language, const PartFormatter& partFormatter) const -> String
{
	const ErrorInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ErrorInterface, this); return mt_._ErrorInterface_FormatMessage((const maxon::GenericComponent*) this + mt_._ErrorInterface_FormatMessage_Offset, language, partFormatter);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::SetMessageDelegate(Delegate<String(const LanguageRef&language,const ErrorInterface::PartFormatter&fmt)>&& message) -> void
{
	const ErrorInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ErrorInterface, this); return mt_._ErrorInterface_SetMessageDelegate((maxon::GenericComponent*) this + mt_._ErrorInterface_SetMessageDelegate_Offset, std::forward<Delegate<String(const LanguageRef&language,const ErrorInterface::PartFormatter&fmt)>>(message));
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::GetCause() const -> const Error&
{
	const ErrorInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ErrorInterface, this); return mt_._ErrorInterface_GetCause((const maxon::GenericComponent*) this + mt_._ErrorInterface_GetCause_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::SetCause(const Error& cause) -> void
{
	const ErrorInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ErrorInterface, this); return mt_._ErrorInterface_SetCause((maxon::GenericComponent*) this + mt_._ErrorInterface_SetCause_Offset, cause);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::GetMachine(MachineRef& machine) const -> void
{
	const ErrorInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ErrorInterface, this); return mt_._ErrorInterface_GetMachine((const maxon::GenericComponent*) this + mt_._ErrorInterface_GetMachine_Offset, machine);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::SetMachine(const MachineRef& machine) -> void
{
	const ErrorInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ErrorInterface, this); return mt_._ErrorInterface_SetMachine((maxon::GenericComponent*) this + mt_._ErrorInterface_SetMachine_Offset, machine);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::PrivateGetCode() const -> Int
{
	const ErrorInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ErrorInterface, this); return mt_._ErrorInterface_PrivateGetCode((const maxon::GenericComponent*) this + mt_._ErrorInterface_PrivateGetCode_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::PrivateSetCode(Int code) -> void
{
	const ErrorInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ErrorInterface, this); return mt_._ErrorInterface_PrivateSetCode((maxon::GenericComponent*) this + mt_._ErrorInterface_PrivateSetCode_Offset, code);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::PrivateSetPreallocation(ThreadReferencedError preallocation) const -> void
{
	const ErrorInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ErrorInterface, this); return mt_._ErrorInterface_PrivateSetPreallocation((const maxon::GenericComponent*) this + mt_._ErrorInterface_PrivateSetPreallocation_Offset, std::forward<ThreadReferencedError>(preallocation));
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::PrivateGetPreallocation() const -> ThreadReferencedError
{
	const ErrorInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ErrorInterface, this); return mt_._ErrorInterface_PrivateGetPreallocation((const maxon::GenericComponent*) this + mt_._ErrorInterface_PrivateGetPreallocation_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::PrivateSetDebugError(const Error& cause) const -> void
{
	const ErrorInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ErrorInterface, this); return mt_._ErrorInterface_PrivateSetDebugError((const maxon::GenericComponent*) this + mt_._ErrorInterface_PrivateSetDebugError_Offset, cause);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetLocation() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const SourceLocation&>, const SourceLocation&>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const SourceLocation&>, const SourceLocation&>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ErrorInterface* o_ = (const ErrorInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ErrorInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<const SourceLocation&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ErrorInterface, o_, ErrorInterface_GetLocation) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ErrorInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ErrorInterface>() : PRIVATE_MAXON_VTABLE(ErrorInterface, o_); 
	return (mt_._ErrorInterface_GetLocation(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._ErrorInterface_GetLocation_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::Hxx1::ReferenceFunctionsImpl<S>::SetLocation(const maxon::SourceLocation& allocLocation) const -> DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S)
{
	static_assert(!S::HAS_ERROR, "ErrorInterface::SetLocation can't be used on a Result object because it does not return a Result object itself."); ErrorInterface* o_ = (ErrorInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { DebugStop(); return this->PrivateGetRefMember(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ErrorInterface, o_, ErrorInterface_SetLocation) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ErrorInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ErrorInterface>() : PRIVATE_MAXON_VTABLE(ErrorInterface, o_); 
	mt_._ErrorInterface_SetLocation(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._ErrorInterface_SetLocation_Offset, allocLocation);
	return this->PrivateGetRefMember();
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::Hxx1::COWReferenceFunctionsImpl<S>::SetLocation(const maxon::SourceLocation& allocLocation) -> DOXYGEN_SWITCH(maxon::RefMemberType<S>, S)
{
	static_assert(!S::HAS_ERROR, "ErrorInterface::SetLocation can't be used on a Result object because it does not return a Result object itself."); ErrorInterface* o_ = (ErrorInterface*) this->MakeWritable(false).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return this->PrivateGetRefMember(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ErrorInterface, o_, ErrorInterface_SetLocation) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ErrorInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ErrorInterface>() : PRIVATE_MAXON_VTABLE(ErrorInterface, o_); 
	mt_._ErrorInterface_SetLocation(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._ErrorInterface_SetLocation_Offset, allocLocation);
	return this->PrivateGetRefMember();
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetStackTrace() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Block<void* const>>, Block<void* const>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Block<void* const>>, Block<void* const>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ErrorInterface* o_ = (const ErrorInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ErrorInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<Block<void* const>>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ErrorInterface, o_, ErrorInterface_GetStackTrace) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ErrorInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ErrorInterface>() : PRIVATE_MAXON_VTABLE(ErrorInterface, o_); 
	return (mt_._ErrorInterface_GetStackTrace(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._ErrorInterface_GetStackTrace_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::Hxx1::ReferenceFunctionsImpl<S>::SetStackTrace(const Block<void* const>& trace) const -> DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S)
{
	static_assert(!S::HAS_ERROR, "ErrorInterface::SetStackTrace can't be used on a Result object because it does not return a Result object itself."); ErrorInterface* o_ = (ErrorInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { DebugStop(); return this->PrivateGetRefMember(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ErrorInterface, o_, ErrorInterface_SetStackTrace) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ErrorInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ErrorInterface>() : PRIVATE_MAXON_VTABLE(ErrorInterface, o_); 
	mt_._ErrorInterface_SetStackTrace(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._ErrorInterface_SetStackTrace_Offset, trace);
	return this->PrivateGetRefMember();
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::Hxx1::COWReferenceFunctionsImpl<S>::SetStackTrace(const Block<void* const>& trace) -> DOXYGEN_SWITCH(maxon::RefMemberType<S>, S)
{
	static_assert(!S::HAS_ERROR, "ErrorInterface::SetStackTrace can't be used on a Result object because it does not return a Result object itself."); ErrorInterface* o_ = (ErrorInterface*) this->MakeWritable(false).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return this->PrivateGetRefMember(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ErrorInterface, o_, ErrorInterface_SetStackTrace) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ErrorInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ErrorInterface>() : PRIVATE_MAXON_VTABLE(ErrorInterface, o_); 
	mt_._ErrorInterface_SetStackTrace(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._ErrorInterface_SetStackTrace_Offset, trace);
	return this->PrivateGetRefMember();
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::Hxx1::ReferenceFunctionsImpl<S>::SetStackTrace(Int skip) const -> DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S)
{
	static_assert(!S::HAS_ERROR, "ErrorInterface::SetStackTrace can't be used on a Result object because it does not return a Result object itself."); ErrorInterface* o_ = (ErrorInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { DebugStop(); return this->PrivateGetRefMember(); } 
	o_->SetStackTrace(skip);
	return this->PrivateGetRefMember();
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::Hxx1::COWReferenceFunctionsImpl<S>::SetStackTrace(Int skip) -> DOXYGEN_SWITCH(maxon::RefMemberType<S>, S)
{
	static_assert(!std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value, "Can't invoke MAXON_FUNCTION ErrorInterface::SetStackTrace on super."); static_assert(!S::HAS_ERROR, "ErrorInterface::SetStackTrace can't be used on a Result object because it does not return a Result object itself."); ErrorInterface* o_ = (ErrorInterface*) this->MakeWritable(false).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return this->PrivateGetRefMember(); } 
	o_->SetStackTrace(skip);
	return this->PrivateGetRefMember();
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetMessage() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ErrorInterface* o_ = (const ErrorInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ErrorInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ErrorInterface, o_, ErrorInterface_GetMessage) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ErrorInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ErrorInterface>() : PRIVATE_MAXON_VTABLE(ErrorInterface, o_); 
	return (mt_._ErrorInterface_GetMessage(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._ErrorInterface_GetMessage_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::Hxx1::ReferenceFunctionsImpl<S>::SetMessage(const String& message) const -> DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S)
{
	static_assert(!S::HAS_ERROR, "ErrorInterface::SetMessage can't be used on a Result object because it does not return a Result object itself."); ErrorInterface* o_ = (ErrorInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { DebugStop(); return this->PrivateGetRefMember(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ErrorInterface, o_, ErrorInterface_SetMessage) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ErrorInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ErrorInterface>() : PRIVATE_MAXON_VTABLE(ErrorInterface, o_); 
	mt_._ErrorInterface_SetMessage(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._ErrorInterface_SetMessage_Offset, message);
	return this->PrivateGetRefMember();
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::Hxx1::COWReferenceFunctionsImpl<S>::SetMessage(const String& message) -> DOXYGEN_SWITCH(maxon::RefMemberType<S>, S)
{
	static_assert(!S::HAS_ERROR, "ErrorInterface::SetMessage can't be used on a Result object because it does not return a Result object itself."); ErrorInterface* o_ = (ErrorInterface*) this->MakeWritable(false).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return this->PrivateGetRefMember(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ErrorInterface, o_, ErrorInterface_SetMessage) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ErrorInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ErrorInterface>() : PRIVATE_MAXON_VTABLE(ErrorInterface, o_); 
	mt_._ErrorInterface_SetMessage(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._ErrorInterface_SetMessage_Offset, message);
	return this->PrivateGetRefMember();
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::Hxx1::ConstReferenceFunctionsImpl<S>::FormatMessage(const LanguageRef& language, const PartFormatter& partFormatter) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ErrorInterface* o_ = (const ErrorInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ErrorInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ErrorInterface, o_, ErrorInterface_FormatMessage) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ErrorInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ErrorInterface>() : PRIVATE_MAXON_VTABLE(ErrorInterface, o_); 
	return (mt_._ErrorInterface_FormatMessage(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._ErrorInterface_FormatMessage_Offset, language, partFormatter));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::Hxx1::ReferenceFunctionsImpl<S>::SetMessageDelegate(Delegate<String(const LanguageRef&language,const ErrorInterface::PartFormatter&fmt)>&& message) const -> DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S)
{
	static_assert(!S::HAS_ERROR, "ErrorInterface::SetMessageDelegate can't be used on a Result object because it does not return a Result object itself."); ErrorInterface* o_ = (ErrorInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { DebugStop(); return this->PrivateGetRefMember(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ErrorInterface, o_, ErrorInterface_SetMessageDelegate) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ErrorInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ErrorInterface>() : PRIVATE_MAXON_VTABLE(ErrorInterface, o_); 
	mt_._ErrorInterface_SetMessageDelegate(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._ErrorInterface_SetMessageDelegate_Offset, std::forward<Delegate<String(const LanguageRef&language,const ErrorInterface::PartFormatter&fmt)>>(message));
	return this->PrivateGetRefMember();
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::Hxx1::COWReferenceFunctionsImpl<S>::SetMessageDelegate(Delegate<String(const LanguageRef&language,const ErrorInterface::PartFormatter&fmt)>&& message) -> DOXYGEN_SWITCH(maxon::RefMemberType<S>, S)
{
	static_assert(!S::HAS_ERROR, "ErrorInterface::SetMessageDelegate can't be used on a Result object because it does not return a Result object itself."); ErrorInterface* o_ = (ErrorInterface*) this->MakeWritable(false).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return this->PrivateGetRefMember(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ErrorInterface, o_, ErrorInterface_SetMessageDelegate) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ErrorInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ErrorInterface>() : PRIVATE_MAXON_VTABLE(ErrorInterface, o_); 
	mt_._ErrorInterface_SetMessageDelegate(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._ErrorInterface_SetMessageDelegate_Offset, std::forward<Delegate<String(const LanguageRef&language,const ErrorInterface::PartFormatter&fmt)>>(message));
	return this->PrivateGetRefMember();
}
template <typename S> template <typename T> MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::Hxx1::ConstReferenceFunctionsImpl<S>::FormatPart(const LanguageRef& language, const ErrorInterface::PartFormatter& fmt, const T& part) -> String
{
	return (ErrorInterface::template FormatPart<T>(language, fmt, part));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetCause() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const Error&>, const Error&>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const Error&>, const Error&>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ErrorInterface* o_ = (const ErrorInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ErrorInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<const Error&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ErrorInterface, o_, ErrorInterface_GetCause) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ErrorInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ErrorInterface>() : PRIVATE_MAXON_VTABLE(ErrorInterface, o_); 
	return (mt_._ErrorInterface_GetCause(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._ErrorInterface_GetCause_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::Hxx1::ReferenceFunctionsImpl<S>::SetCause(const Error& cause) const -> DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S)
{
	static_assert(!S::HAS_ERROR, "ErrorInterface::SetCause can't be used on a Result object because it does not return a Result object itself."); ErrorInterface* o_ = (ErrorInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { DebugStop(); return this->PrivateGetRefMember(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ErrorInterface, o_, ErrorInterface_SetCause) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ErrorInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ErrorInterface>() : PRIVATE_MAXON_VTABLE(ErrorInterface, o_); 
	mt_._ErrorInterface_SetCause(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._ErrorInterface_SetCause_Offset, cause);
	return this->PrivateGetRefMember();
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::Hxx1::COWReferenceFunctionsImpl<S>::SetCause(const Error& cause) -> DOXYGEN_SWITCH(maxon::RefMemberType<S>, S)
{
	static_assert(!S::HAS_ERROR, "ErrorInterface::SetCause can't be used on a Result object because it does not return a Result object itself."); ErrorInterface* o_ = (ErrorInterface*) this->MakeWritable(false).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return this->PrivateGetRefMember(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ErrorInterface, o_, ErrorInterface_SetCause) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ErrorInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ErrorInterface>() : PRIVATE_MAXON_VTABLE(ErrorInterface, o_); 
	mt_._ErrorInterface_SetCause(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._ErrorInterface_SetCause_Offset, cause);
	return this->PrivateGetRefMember();
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetMachine(MachineRef& machine) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ErrorInterface* o_ = (const ErrorInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ErrorInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ErrorInterface, o_, ErrorInterface_GetMachine) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ErrorInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ErrorInterface>() : PRIVATE_MAXON_VTABLE(ErrorInterface, o_); 
	mt_._ErrorInterface_GetMachine(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._ErrorInterface_GetMachine_Offset, machine);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::Hxx1::ReferenceFunctionsImpl<S>::SetMachine(const MachineRef& machine) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ErrorInterface* o_ = (ErrorInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { DebugStop(); return maxon::PrivateLogNullptrError(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ErrorInterface, o_, ErrorInterface_SetMachine) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ErrorInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ErrorInterface>() : PRIVATE_MAXON_VTABLE(ErrorInterface, o_); 
	mt_._ErrorInterface_SetMachine(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._ErrorInterface_SetMachine_Offset, machine);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::Hxx1::COWReferenceFunctionsImpl<S>::SetMachine(const MachineRef& machine) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ErrorInterface* o_ = (ErrorInterface*) this->MakeWritable(false).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ErrorInterface, o_, ErrorInterface_SetMachine) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ErrorInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ErrorInterface>() : PRIVATE_MAXON_VTABLE(ErrorInterface, o_); 
	mt_._ErrorInterface_SetMachine(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._ErrorInterface_SetMachine_Offset, machine);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::Hxx1::ConstReferenceFunctionsImpl<S>::PrivateGetCode() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ErrorInterface* o_ = (const ErrorInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ErrorInterface::NullValuePtr(); if (!o_) return 0; } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ErrorInterface, o_, ErrorInterface_PrivateGetCode) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ErrorInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ErrorInterface>() : PRIVATE_MAXON_VTABLE(ErrorInterface, o_); 
	return (mt_._ErrorInterface_PrivateGetCode(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._ErrorInterface_PrivateGetCode_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::Hxx1::ReferenceFunctionsImpl<S>::PrivateSetCode(Int code) const -> DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S)
{
	static_assert(!S::HAS_ERROR, "ErrorInterface::PrivateSetCode can't be used on a Result object because it does not return a Result object itself."); ErrorInterface* o_ = (ErrorInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { DebugStop(); return this->PrivateGetRefMember(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ErrorInterface, o_, ErrorInterface_PrivateSetCode) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ErrorInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ErrorInterface>() : PRIVATE_MAXON_VTABLE(ErrorInterface, o_); 
	mt_._ErrorInterface_PrivateSetCode(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._ErrorInterface_PrivateSetCode_Offset, code);
	return this->PrivateGetRefMember();
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::Hxx1::COWReferenceFunctionsImpl<S>::PrivateSetCode(Int code) -> DOXYGEN_SWITCH(maxon::RefMemberType<S>, S)
{
	static_assert(!S::HAS_ERROR, "ErrorInterface::PrivateSetCode can't be used on a Result object because it does not return a Result object itself."); ErrorInterface* o_ = (ErrorInterface*) this->MakeWritable(false).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return this->PrivateGetRefMember(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ErrorInterface, o_, ErrorInterface_PrivateSetCode) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ErrorInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ErrorInterface>() : PRIVATE_MAXON_VTABLE(ErrorInterface, o_); 
	mt_._ErrorInterface_PrivateSetCode(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._ErrorInterface_PrivateSetCode_Offset, code);
	return this->PrivateGetRefMember();
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::Hxx1::ConstReferenceFunctionsImpl<S>::PrivateSetPreallocation(ThreadReferencedError preallocation) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ErrorInterface* o_ = (const ErrorInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ErrorInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ErrorInterface, o_, ErrorInterface_PrivateSetPreallocation) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ErrorInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ErrorInterface>() : PRIVATE_MAXON_VTABLE(ErrorInterface, o_); 
	mt_._ErrorInterface_PrivateSetPreallocation(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._ErrorInterface_PrivateSetPreallocation_Offset, std::forward<ThreadReferencedError>(preallocation));
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::Hxx1::ConstReferenceFunctionsImpl<S>::PrivateGetPreallocation() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<ThreadReferencedError>, ThreadReferencedError>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<ThreadReferencedError>, ThreadReferencedError>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ErrorInterface* o_ = (const ErrorInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ErrorInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<ThreadReferencedError>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ErrorInterface, o_, ErrorInterface_PrivateGetPreallocation) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ErrorInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ErrorInterface>() : PRIVATE_MAXON_VTABLE(ErrorInterface, o_); 
	return (mt_._ErrorInterface_PrivateGetPreallocation(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._ErrorInterface_PrivateGetPreallocation_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::Hxx1::ConstReferenceFunctionsImpl<S>::PrivateSetDebugError(const Error& cause) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ErrorInterface* o_ = (const ErrorInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ErrorInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ErrorInterface, o_, ErrorInterface_PrivateSetDebugError) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ErrorInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ErrorInterface>() : PRIVATE_MAXON_VTABLE(ErrorInterface, o_); 
	mt_._ErrorInterface_PrivateSetDebugError(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._ErrorInterface_PrivateSetDebugError_Offset, cause);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
auto ErrorInterface::GetPtr() -> Ptr { return Ptr(this); }
auto ErrorInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
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

