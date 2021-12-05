
#ifndef DOXYGEN

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#pragma GCC diagnostic ignored "-Wmisleading-indentation"
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
	Result<void> (*_ClassInterface_AddComponents) (ClassInterface* this_, const GenericClass& cls);
	Result<void> (*_ClassInterface_Finalize) (ClassInterface* this_);
	Bool (*_ClassInterface_IsFinalized) (const ClassInterface* this_);
	const Block<const InterfaceReference* const>& (*_ClassInterface_GetImplementedInterfaces) (const ClassInterface* this_);
	const DataType* (*_ClassInterface_GetDataType) (const ClassInterface* this_);
	Result<ObjectRef> (*_ClassInterface_CreateRef) (const ClassInterface* this_);
	Result<Object*> (*_ClassInterface_CreatePointer) (const ClassInterface* this_);
	String (*_ClassInterface_ToString) (const ClassInterface* this_, const FormatStatement* formatStatement);
	void (*_ClassInterface_DeleteInstance) (const Object* object);
	void (*_ClassInterface_DestructInstance) (const Object* object);
	Result<void> (*_ClassInterface_CopyInstance) (const Object* src, Object* dest);
	const ClassInfo* (*_ClassInterface_GetInfo) (const ClassInterface* this_);
	void* (*_ClassInterface_GetOrCreateMTable) (ClassInfo* info, const InterfaceReference& i);
	Result<Int> (*_ClassInterface_AddProxyComponent) (ClassInterface* this_, const ComponentDescriptor& component, Bool shared);
	template <typename IMPL> static void Init(MTable* tbl)
	{
		tbl->_ClassInterface_Free = &IMPL::_ClassInterface_Free;
		tbl->_ClassInterface_Alloc = &IMPL::_ClassInterface_Alloc;
		tbl->_ClassInterface_GetId = &IMPL::_ClassInterface_GetId;
		tbl->_ClassInterface_GetKind = &IMPL::_ClassInterface_GetKind;
		tbl->_ClassInterface_GetComponents = &IMPL::_ClassInterface_GetComponents;
		tbl->_ClassInterface_AddComponent = &IMPL::_ClassInterface_AddComponent;
		tbl->_ClassInterface_RemoveLastComponent = &IMPL::_ClassInterface_RemoveLastComponent;
		tbl->_ClassInterface_AddComponents = &IMPL::_ClassInterface_AddComponents;
		tbl->_ClassInterface_Finalize = &IMPL::_ClassInterface_Finalize;
		tbl->_ClassInterface_IsFinalized = &IMPL::_ClassInterface_IsFinalized;
		tbl->_ClassInterface_GetImplementedInterfaces = &IMPL::_ClassInterface_GetImplementedInterfaces;
		tbl->_ClassInterface_GetDataType = &IMPL::_ClassInterface_GetDataType;
		tbl->_ClassInterface_CreateRef = &IMPL::_ClassInterface_CreateRef;
		tbl->_ClassInterface_CreatePointer = &IMPL::_ClassInterface_CreatePointer;
		tbl->_ClassInterface_ToString = &IMPL::_ClassInterface_ToString;
		tbl->_ClassInterface_DeleteInstance = &IMPL::_ClassInterface_DeleteInstance;
		tbl->_ClassInterface_DestructInstance = &IMPL::_ClassInterface_DestructInstance;
		tbl->_ClassInterface_CopyInstance = &IMPL::_ClassInterface_CopyInstance;
		tbl->_ClassInterface_GetInfo = &IMPL::_ClassInterface_GetInfo;
		tbl->_ClassInterface_GetOrCreateMTable = &IMPL::_ClassInterface_GetOrCreateMTable;
		tbl->_ClassInterface_AddProxyComponent = &IMPL::_ClassInterface_AddProxyComponent;
	}
};

template <typename C> class ClassInterface::Wrapper
{
public:
	static void _ClassInterface_Free(const ClassInterface* object) { return C::Free(object); }
	static ClassInterface* _ClassInterface_Alloc(const maxon::SourceLocation& allocLocation, const Id& cid, KIND kind) { return C::Alloc(allocLocation, cid, kind); }
	static const Id& _ClassInterface_GetId(const ClassInterface* this_) { return ((const C*) this_)->GetId(); }
	static KIND _ClassInterface_GetKind(const ClassInterface* this_) { return ((const C*) this_)->GetKind(); }
	static Block<const ComponentInfo* const> _ClassInterface_GetComponents(const ClassInterface* this_) { return ((const C*) this_)->GetComponents(); }
	static Result<void> _ClassInterface_AddComponent(ClassInterface* this_, const ComponentDescriptor& component) { return ((C*) this_)->AddComponent(component); }
	static void _ClassInterface_RemoveLastComponent(ClassInterface* this_) { return ((C*) this_)->RemoveLastComponent(); }
	static Result<void> _ClassInterface_AddComponents(ClassInterface* this_, const GenericClass& cls) { return ((C*) this_)->AddComponents(cls); }
	static Result<void> _ClassInterface_Finalize(ClassInterface* this_) { return ((C*) this_)->Finalize(); }
	static Bool _ClassInterface_IsFinalized(const ClassInterface* this_) { return ((const C*) this_)->IsFinalized(); }
	static const Block<const InterfaceReference* const>& _ClassInterface_GetImplementedInterfaces(const ClassInterface* this_) { return ((const C*) this_)->GetImplementedInterfaces(); }
	static const DataType* _ClassInterface_GetDataType(const ClassInterface* this_) { return ((const C*) this_)->GetDataType(); }
	static Result<ObjectRef> _ClassInterface_CreateRef(const ClassInterface* this_) { return ((const C*) this_)->CreateRef(); }
	static Result<Object*> _ClassInterface_CreatePointer(const ClassInterface* this_) { return ((const C*) this_)->CreatePointer(); }
	static String _ClassInterface_ToString(const ClassInterface* this_, const FormatStatement* formatStatement) { return ((const C*) this_)->ToString(formatStatement); }
	static void _ClassInterface_DeleteInstance(const Object* object) { return C::DeleteInstance(object); }
	static void _ClassInterface_DestructInstance(const Object* object) { return C::DestructInstance(object); }
	static Result<void> _ClassInterface_CopyInstance(const Object* src, Object* dest) { return C::CopyInstance(src, dest); }
	static const ClassInfo* _ClassInterface_GetInfo(const ClassInterface* this_) { return ((const C*) this_)->GetInfo(); }
	static void* _ClassInterface_GetOrCreateMTable(ClassInfo* info, const InterfaceReference& i) { return C::GetOrCreateMTable(info, i); }
	static Result<Int> _ClassInterface_AddProxyComponent(ClassInterface* this_, const ComponentDescriptor& component, Bool shared) { return ((C*) this_)->AddProxyComponent(component, shared); }
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
MAXON_ATTRIBUTE_FORCE_INLINE auto ClassInterface::AddComponents(const GenericClass& cls) -> Result<void>
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
MAXON_ATTRIBUTE_FORCE_INLINE auto ClassInterface::GetDataType() const -> const DataType*
{
	return MTable::_instance._ClassInterface_GetDataType(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ClassInterface::CreateRef() const -> Result<ObjectRef>
{
	return MTable::_instance._ClassInterface_CreateRef(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ClassInterface::CreatePointer() const -> Result<Object*>
{
	return MTable::_instance._ClassInterface_CreatePointer(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ClassInterface::ToString(const FormatStatement* formatStatement) const -> String
{
	return MTable::_instance._ClassInterface_ToString(this, formatStatement);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ClassInterface::DeleteInstance(const Object* object) -> void
{
	return MTable::_instance._ClassInterface_DeleteInstance(object);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ClassInterface::DestructInstance(const Object* object) -> void
{
	return MTable::_instance._ClassInterface_DestructInstance(object);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ClassInterface::CopyInstance(const Object* src, Object* dest) -> Result<void>
{
	return MTable::_instance._ClassInterface_CopyInstance(src, dest);
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

auto ClassInterface::Reference::Create(const Id& cid, KIND kind) -> maxon::ResultMemT<GenericClass>
{
	ClassInterface* res_ = ClassInterface::Alloc(MAXON_SOURCE_LOCATION, cid, kind);
	return GenericClass(maxon::ForwardResultPtr<ClassInterface>(res_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ClassInterface::ConstReferenceFunctionsImpl<S>::GetId() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const Id&>, const Id&>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<const Id&>, const Id&>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ClassInterface* o_ = (const ClassInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = ClassInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<const Id&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (MTable::_instance._ClassInterface_GetId(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ClassInterface::ConstReferenceFunctionsImpl<S>::GetKind() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<KIND>, KIND>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<KIND>, KIND>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ClassInterface* o_ = (const ClassInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = ClassInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<KIND>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (MTable::_instance._ClassInterface_GetKind(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ClassInterface::ConstReferenceFunctionsImpl<S>::GetComponents() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Block<const ComponentInfo* const>>, Block<const ComponentInfo* const>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<Block<const ComponentInfo* const>>, Block<const ComponentInfo* const>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ClassInterface* o_ = (const ClassInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = ClassInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<Block<const ComponentInfo* const>>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (MTable::_instance._ClassInterface_GetComponents(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ClassInterface::ReferenceFunctionsImpl<S>::AddComponent(const ComponentDescriptor& component) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ClassInterface* o_ = (ClassInterface*) this->GetPointer(); if (MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); 
	return (MTable::_instance._ClassInterface_AddComponent(o_, component));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ClassInterface::ReferenceFunctionsImpl<S>::AddComponents(const GenericClass& cls) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ClassInterface* o_ = (ClassInterface*) this->GetPointer(); if (MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); 
	return (MTable::_instance._ClassInterface_AddComponents(o_, cls));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ClassInterface::ReferenceFunctionsImpl<S>::Finalize() const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ClassInterface* o_ = (ClassInterface*) this->GetPointer(); if (MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); 
	return (MTable::_instance._ClassInterface_Finalize(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ClassInterface::ConstReferenceFunctionsImpl<S>::IsFinalized() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ClassInterface* o_ = (const ClassInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = ClassInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (MTable::_instance._ClassInterface_IsFinalized(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ClassInterface::ConstReferenceFunctionsImpl<S>::GetImplementedInterfaces() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const Block<const InterfaceReference* const>&>, const Block<const InterfaceReference* const>&>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<const Block<const InterfaceReference* const>&>, const Block<const InterfaceReference* const>&>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ClassInterface* o_ = (const ClassInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = ClassInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<const Block<const InterfaceReference* const>&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (MTable::_instance._ClassInterface_GetImplementedInterfaces(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ClassInterface::ConstReferenceFunctionsImpl<S>::GetDataType() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const DataType*>, const DataType*>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<const DataType*>, const DataType*>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ClassInterface* o_ = (const ClassInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = ClassInterface::NullValuePtr(); if (!o_) return nullptr; } 
	return (MTable::_instance._ClassInterface_GetDataType(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ClassInterface::ConstReferenceFunctionsImpl<S>::CreateRef() const -> Result<ObjectRef>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<ObjectRef>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ClassInterface* o_ = (const ClassInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = ClassInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance._ClassInterface_CreateRef(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ClassInterface::ConstReferenceFunctionsImpl<S>::Create() const -> Result<typename maxon::details::ClassCreateType<typename S::ReferenceClass>::type>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<typename maxon::details::ClassCreateType<typename S::ReferenceClass>::type>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ClassInterface* o_ = (const ClassInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = ClassInterface::NullValuePtr(); if (!o_) return maxon::PrivateNullReturnValue<Result<typename maxon::details::ClassCreateType<typename S::ReferenceClass>::type>>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (o_->Create<typename S::ReferenceClass>());
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ClassInterface::ConstReferenceFunctionsImpl<S>::Implements(const InterfaceReference& iref) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ClassInterface* o_ = (const ClassInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = ClassInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (o_->Implements(iref));
}
template <typename S> template <typename I> MAXON_ATTRIBUTE_FORCE_INLINE auto ClassInterface::ConstReferenceFunctionsImpl<S>::Implements() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ClassInterface* o_ = (const ClassInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = ClassInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (o_->Implements<I>());
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ClassInterface::ConstReferenceFunctionsImpl<S>::ToString(const FormatStatement* formatStatement) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ClassInterface* o_ = (const ClassInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = ClassInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (MTable::_instance._ClassInterface_ToString(o_, formatStatement));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ClassInterface::ConstReferenceFunctionsImpl<S>::DeleteInstance(const Object* object) -> void { return (MTable::_instance._ClassInterface_DeleteInstance(object)); }
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ClassInterface::ConstReferenceFunctionsImpl<S>::DestructInstance(const Object* object) -> void { return (MTable::_instance._ClassInterface_DestructInstance(object)); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
static maxon::EntityUse s_ui_maxon_ClassInterface(ClassInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/objectbase.h", false);
#endif
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


struct Object::MTable
{
	PRIVATE_MAXON_IMPLEMENTS_CHECK(Compare);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetHashCodeImpl);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(InitObject);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(IsEqual);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(ToString);
	static const maxon::Char* const _ids;
	static const maxon::Bool HAS_NONSTATIC = false;
	String (*_Object_ToString) (const maxon::GenericComponent* this_, const FormatStatement* formatStatement);
	maxon::Int _Object_ToString_Offset;
	Result<void> (*_Object_InitObject) (maxon::GenericComponent* this_);
	maxon::Int _Object_InitObject_Offset;
	Bool (*_Object_IsEqual) (const maxon::GenericComponent* this_, const maxon::Object* other);
	maxon::Int _Object_IsEqual_Offset;
	COMPARERESULT (*_Object_Compare) (const maxon::GenericComponent* this_, const maxon::Object* other);
	maxon::Int _Object_Compare_Offset;
	UInt (*_Object_GetHashCodeImpl) (const maxon::GenericComponent* this_);
	maxon::Int _Object_GetHashCodeImpl_Offset;
/// @cond INTERNAL

/// @endcond

	template <typename W> void Init(maxon::Int offset)
	{
		if (PRIVATE_MAXON_IMPLEMENTS(W::Implementation, Object, ToString))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(W::Implementation, Object, ToString), W, MTable>::type::_Object_ToString;
			_Object_ToString = reinterpret_cast<const decltype(_Object_ToString)&>(ptr);
			_Object_ToString_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(W::Implementation, Object, InitObject))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(W::Implementation, Object, InitObject), W, MTable>::type::_Object_InitObject;
			_Object_InitObject = reinterpret_cast<const decltype(_Object_InitObject)&>(ptr);
			_Object_InitObject_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(W::Implementation, Object, IsEqual))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(W::Implementation, Object, IsEqual), W, MTable>::type::_Object_IsEqual;
			_Object_IsEqual = reinterpret_cast<const decltype(_Object_IsEqual)&>(ptr);
			_Object_IsEqual_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(W::Implementation, Object, Compare))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(W::Implementation, Object, Compare), W, MTable>::type::_Object_Compare;
			_Object_Compare = reinterpret_cast<const decltype(_Object_Compare)&>(ptr);
			_Object_Compare_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(W::Implementation, Object, GetHashCodeImpl))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(W::Implementation, Object, GetHashCodeImpl), W, MTable>::type::_Object_GetHashCodeImpl;
			_Object_GetHashCodeImpl = reinterpret_cast<const decltype(_Object_GetHashCodeImpl)&>(ptr);
			_Object_GetHashCodeImpl_Offset = offset;
		}
/// @cond INTERNAL

/// @endcond

	}
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset)
	{
		MTable* vt = (MTable*) maxon::Object::PrivateGetOrCreateMTable(info, _interface); if (!vt) return false;
		vt->Init<W>(offset); return true;
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<Object, S>;
	PRIVATE_MAXON_COMPBASE(Object);
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

template <typename S> class Object::Wrapper : public S
{
public:
	PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(Compare);
	PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetHashCodeImpl);
	PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(InitObject);
	PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(IsEqual);
	PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(ToString);
	static String _Object_ToString(const maxon::GenericComponent* this_, const FormatStatement* formatStatement) { return ((const typename S::Implementation*) this_)->ToString(formatStatement); }
	static Result<void> _Object_InitObject(maxon::GenericComponent* this_) { return ((typename S::Implementation*) this_)->InitObject(); }
	static Bool _Object_IsEqual(const maxon::GenericComponent* this_, const maxon::Object* other) { return ((const typename S::Implementation*) this_)->IsEqual(other); }
	static COMPARERESULT _Object_Compare(const maxon::GenericComponent* this_, const maxon::Object* other) { return ((const typename S::Implementation*) this_)->Compare(other); }
	static UInt _Object_GetHashCodeImpl(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetHashCodeImpl(); }
/// @cond INTERNAL

/// @endcond

};

MAXON_ATTRIBUTE_FORCE_INLINE auto Object::ToString(const FormatStatement* formatStatement) const -> String
{
	const Object::MTable& mt_ = PRIVATE_MAXON_VTABLE(Object, this); return mt_._Object_ToString((const maxon::GenericComponent*) this + mt_._Object_ToString_Offset, formatStatement);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Object::InitObject() -> Result<void>
{
	const Object::MTable& mt_ = PRIVATE_MAXON_VTABLE(Object, this); return mt_._Object_InitObject((maxon::GenericComponent*) this + mt_._Object_InitObject_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Object::IsEqual(const maxon::Object* other) const -> Bool
{
	const Object::MTable& mt_ = PRIVATE_MAXON_VTABLE(Object, this); return mt_._Object_IsEqual((const maxon::GenericComponent*) this + mt_._Object_IsEqual_Offset, other);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Object::Compare(const maxon::Object* other) const -> COMPARERESULT
{
	const Object::MTable& mt_ = PRIVATE_MAXON_VTABLE(Object, this); return mt_._Object_Compare((const maxon::GenericComponent*) this + mt_._Object_Compare_Offset, other);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Object::GetHashCodeImpl() const -> UInt
{
	const Object::MTable& mt_ = PRIVATE_MAXON_VTABLE(Object, this); return mt_._Object_GetHashCodeImpl((const maxon::GenericComponent*) this + mt_._Object_GetHashCodeImpl_Offset);
}
/// @cond INTERNAL

/// @endcond


template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto Object::ConstReferenceFunctionsImpl<S>::GetClass() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const maxon::Class<typename S::PrivateReferencedType::ReferenceClassHelper::type>&>, const maxon::Class<typename S::PrivateReferencedType::ReferenceClassHelper::type>&>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<const maxon::Class<typename S::PrivateReferencedType::ReferenceClassHelper::type>&>, const maxon::Class<typename S::PrivateReferencedType::ReferenceClassHelper::type>&>::type>; static_assert(!std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value, "Can't invoke MAXON_FUNCTION Object::GetClass on super."); if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const Object* o_ = (const Object*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = Object::NullValuePtr(); if (!o_) return maxon::PrivateNullReturnValue<const maxon::Class<typename S::PrivateReferencedType::ReferenceClassHelper::type>&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (o_->GetClass<typename S::PrivateReferencedType>());
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto Object::ConstReferenceFunctionsImpl<S>::GetClassInfo() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const ClassInfo*>, const ClassInfo*>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<const ClassInfo*>, const ClassInfo*>::type>; static_assert(!std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value, "Can't invoke MAXON_FUNCTION Object::GetClassInfo on super."); if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const Object* o_ = (const Object*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = Object::NullValuePtr(); if (!o_) return nullptr; } 
	return (o_->GetClassInfo());
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto Object::ConstReferenceFunctionsImpl<S>::HasSameClass(const Object* obj) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; static_assert(!std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value, "Can't invoke MAXON_FUNCTION Object::HasSameClass on super."); if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const Object* o_ = (const Object*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = Object::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (o_->HasSameClass(obj));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto Object::ConstReferenceFunctionsImpl<S>::Clone() const -> Result<typename S::ReferenceClass>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<typename S::ReferenceClass>>; static_assert(!std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value, "Can't invoke MAXON_FUNCTION Object::Clone on super."); if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const Object* o_ = (const Object*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = Object::NullValuePtr(); if (!o_) return maxon::PrivateNullReturnValue<Result<typename S::ReferenceClass>>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (o_->Clone<typename S::ReferenceClass>());
}
template <typename S> template <typename I> MAXON_ATTRIBUTE_FORCE_INLINE auto Object::ConstReferenceFunctionsImpl<S>::IsInstanceOf() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; static_assert(!std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value, "Can't invoke MAXON_FUNCTION Object::IsInstanceOf on super."); if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const Object* o_ = (const Object*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = Object::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (o_->IsInstanceOf<I>());
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto Object::ConstReferenceFunctionsImpl<S>::IsInstanceOf(const DataType* type) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; static_assert(!std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value, "Can't invoke MAXON_FUNCTION Object::IsInstanceOf on super."); if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const Object* o_ = (const Object*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = Object::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (o_->IsInstanceOf(type));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto Object::ConstReferenceFunctionsImpl<S>::ToString(const FormatStatement* formatStatement) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const Object* o_ = (const Object*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = Object::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(Object, o_, Object_ToString) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<Object>::value) ? S::PrivateReferencedType::MTable::template GetMTable<Object>() : PRIVATE_MAXON_VTABLE(Object, o_); 
	return (mt_._Object_ToString(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._Object_ToString_Offset, formatStatement));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto Object::ReferenceFunctionsImpl<S>::InitObject() const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); Object* o_ = (Object*) this->GetPointer(); if (MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(Object, o_, Object_InitObject) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<Object>::value) ? S::PrivateReferencedType::MTable::template GetMTable<Object>() : PRIVATE_MAXON_VTABLE(Object, o_); 
	return (mt_._Object_InitObject(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._Object_InitObject_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto Object::COWReferenceFunctionsImpl<S>::InitObject() -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); Object* o_ = (Object*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(Object, o_, Object_InitObject) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<Object>::value) ? S::PrivateReferencedType::MTable::template GetMTable<Object>() : PRIVATE_MAXON_VTABLE(Object, o_); 
	return (mt_._Object_InitObject(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._Object_InitObject_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto Object::ConstReferenceFunctionsImpl<S>::IsEqual(const maxon::Object* other) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const Object* o_ = (const Object*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = Object::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(Object, o_, Object_IsEqual) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<Object>::value) ? S::PrivateReferencedType::MTable::template GetMTable<Object>() : PRIVATE_MAXON_VTABLE(Object, o_); 
	return (mt_._Object_IsEqual(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._Object_IsEqual_Offset, other));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto Object::ConstReferenceFunctionsImpl<S>::Compare(const maxon::Object* other) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<COMPARERESULT>, COMPARERESULT>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<COMPARERESULT>, COMPARERESULT>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const Object* o_ = (const Object*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = Object::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<COMPARERESULT>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(Object, o_, Object_Compare) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<Object>::value) ? S::PrivateReferencedType::MTable::template GetMTable<Object>() : PRIVATE_MAXON_VTABLE(Object, o_); 
	return (mt_._Object_Compare(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._Object_Compare_Offset, other));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto Object::ConstReferenceFunctionsImpl<S>::GetHashCodeImpl() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<UInt>, UInt>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<UInt>, UInt>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const Object* o_ = (const Object*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = Object::NullValuePtr(); if (!o_) return 0; } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(Object, o_, Object_GetHashCodeImpl) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<Object>::value) ? S::PrivateReferencedType::MTable::template GetMTable<Object>() : PRIVATE_MAXON_VTABLE(Object, o_); 
	return (mt_._Object_GetHashCodeImpl(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._Object_GetHashCodeImpl_Offset));
}
/// @cond INTERNAL

/// @endcond

auto Object::GetPtr() -> Ptr { return Ptr(this); }
auto Object::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
static maxon::EntityUse s_ui_maxon_Object(Object::_interface.GetReference(), &maxon::g_translationUnit, "maxon/objectbase.h", false);
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
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetCause);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetLocation);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetMachine);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetMessage);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetStackTrace);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(PrivateGetCode);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(PrivateSetCode);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(SetCause);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(SetLocation);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(SetMachine);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(SetMessage);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(SetStackTrace);
	static const maxon::Char* const _ids;
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
	template <typename W> void Init(maxon::Int offset)
	{
		if (PRIVATE_MAXON_IMPLEMENTS(W::Implementation, ErrorInterface, GetLocation))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(W::Implementation, ErrorInterface, GetLocation), W, MTable>::type::_ErrorInterface_GetLocation;
			_ErrorInterface_GetLocation = reinterpret_cast<const decltype(_ErrorInterface_GetLocation)&>(ptr);
			_ErrorInterface_GetLocation_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(W::Implementation, ErrorInterface, SetLocation))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(W::Implementation, ErrorInterface, SetLocation), W, MTable>::type::_ErrorInterface_SetLocation;
			_ErrorInterface_SetLocation = reinterpret_cast<const decltype(_ErrorInterface_SetLocation)&>(ptr);
			_ErrorInterface_SetLocation_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(W::Implementation, ErrorInterface, GetStackTrace))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(W::Implementation, ErrorInterface, GetStackTrace), W, MTable>::type::_ErrorInterface_GetStackTrace;
			_ErrorInterface_GetStackTrace = reinterpret_cast<const decltype(_ErrorInterface_GetStackTrace)&>(ptr);
			_ErrorInterface_GetStackTrace_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(W::Implementation, ErrorInterface, SetStackTrace))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(W::Implementation, ErrorInterface, SetStackTrace), W, MTable>::type::_ErrorInterface_SetStackTrace;
			_ErrorInterface_SetStackTrace = reinterpret_cast<const decltype(_ErrorInterface_SetStackTrace)&>(ptr);
			_ErrorInterface_SetStackTrace_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(W::Implementation, ErrorInterface, GetMessage))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(W::Implementation, ErrorInterface, GetMessage), W, MTable>::type::_ErrorInterface_GetMessage;
			_ErrorInterface_GetMessage = reinterpret_cast<const decltype(_ErrorInterface_GetMessage)&>(ptr);
			_ErrorInterface_GetMessage_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(W::Implementation, ErrorInterface, SetMessage))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(W::Implementation, ErrorInterface, SetMessage), W, MTable>::type::_ErrorInterface_SetMessage;
			_ErrorInterface_SetMessage = reinterpret_cast<const decltype(_ErrorInterface_SetMessage)&>(ptr);
			_ErrorInterface_SetMessage_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(W::Implementation, ErrorInterface, GetCause))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(W::Implementation, ErrorInterface, GetCause), W, MTable>::type::_ErrorInterface_GetCause;
			_ErrorInterface_GetCause = reinterpret_cast<const decltype(_ErrorInterface_GetCause)&>(ptr);
			_ErrorInterface_GetCause_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(W::Implementation, ErrorInterface, SetCause))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(W::Implementation, ErrorInterface, SetCause), W, MTable>::type::_ErrorInterface_SetCause;
			_ErrorInterface_SetCause = reinterpret_cast<const decltype(_ErrorInterface_SetCause)&>(ptr);
			_ErrorInterface_SetCause_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(W::Implementation, ErrorInterface, GetMachine))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(W::Implementation, ErrorInterface, GetMachine), W, MTable>::type::_ErrorInterface_GetMachine;
			_ErrorInterface_GetMachine = reinterpret_cast<const decltype(_ErrorInterface_GetMachine)&>(ptr);
			_ErrorInterface_GetMachine_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(W::Implementation, ErrorInterface, SetMachine))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(W::Implementation, ErrorInterface, SetMachine), W, MTable>::type::_ErrorInterface_SetMachine;
			_ErrorInterface_SetMachine = reinterpret_cast<const decltype(_ErrorInterface_SetMachine)&>(ptr);
			_ErrorInterface_SetMachine_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(W::Implementation, ErrorInterface, PrivateGetCode))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(W::Implementation, ErrorInterface, PrivateGetCode), W, MTable>::type::_ErrorInterface_PrivateGetCode;
			_ErrorInterface_PrivateGetCode = reinterpret_cast<const decltype(_ErrorInterface_PrivateGetCode)&>(ptr);
			_ErrorInterface_PrivateGetCode_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(W::Implementation, ErrorInterface, PrivateSetCode))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(W::Implementation, ErrorInterface, PrivateSetCode), W, MTable>::type::_ErrorInterface_PrivateSetCode;
			_ErrorInterface_PrivateSetCode = reinterpret_cast<const decltype(_ErrorInterface_PrivateSetCode)&>(ptr);
			_ErrorInterface_PrivateSetCode_Offset = offset;
		}
	}
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset)
	{
		if (!W::Implementation::PROXY && (!Object::MTable::InitWithBases<W>(info, offset))) return false;
		MTable* vt = (MTable*) maxon::Object::PrivateGetOrCreateMTable(info, _interface); if (!vt) return false;
		vt->Init<W>(offset); return true;
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<ErrorInterface, Object::MTable::CombinedMTable<S>>;
	PRIVATE_MAXON_COMPBASE(ErrorInterface);
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

template <typename S> class ErrorInterface::Wrapper : public Object::Wrapper<S>
{
public:
	PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetCause);
	PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetLocation);
	PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetMachine);
	PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetMessage);
	PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetStackTrace);
	PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(PrivateGetCode);
	PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(PrivateSetCode);
	PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(SetCause);
	PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(SetLocation);
	PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(SetMachine);
	PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(SetMessage);
	PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(SetStackTrace);
	static const SourceLocation& _ErrorInterface_GetLocation(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetLocation(); }
	static void _ErrorInterface_SetLocation(maxon::GenericComponent* this_, const maxon::SourceLocation& allocLocation) { return ((typename S::Implementation*) this_)->SetLocation(allocLocation); }
	static Block<void* const> _ErrorInterface_GetStackTrace(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetStackTrace(); }
	static void _ErrorInterface_SetStackTrace(maxon::GenericComponent* this_, const Block<void* const>& trace) { return ((typename S::Implementation*) this_)->SetStackTrace(trace); }
	static String _ErrorInterface_GetMessage(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetMessage(); }
	static void _ErrorInterface_SetMessage(maxon::GenericComponent* this_, const String& message) { return ((typename S::Implementation*) this_)->SetMessage(message); }
	static const Error& _ErrorInterface_GetCause(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetCause(); }
	static void _ErrorInterface_SetCause(maxon::GenericComponent* this_, const Error& cause) { return ((typename S::Implementation*) this_)->SetCause(cause); }
	static void _ErrorInterface_GetMachine(const maxon::GenericComponent* this_, MachineRef& machine) { return ((const typename S::Implementation*) this_)->GetMachine(machine); }
	static void _ErrorInterface_SetMachine(maxon::GenericComponent* this_, const MachineRef& machine) { return ((typename S::Implementation*) this_)->SetMachine(machine); }
	static Int _ErrorInterface_PrivateGetCode(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->PrivateGetCode(); }
	static void _ErrorInterface_PrivateSetCode(maxon::GenericComponent* this_, Int code) { return ((typename S::Implementation*) this_)->PrivateSetCode(code); }
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

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::ConstReferenceFunctionsImpl<S>::GetLocation() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const SourceLocation&>, const SourceLocation&>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<const SourceLocation&>, const SourceLocation&>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ErrorInterface* o_ = (const ErrorInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = ErrorInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<const SourceLocation&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ErrorInterface, o_, ErrorInterface_GetLocation) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<ErrorInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ErrorInterface>() : PRIVATE_MAXON_VTABLE(ErrorInterface, o_); 
	return (mt_._ErrorInterface_GetLocation(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._ErrorInterface_GetLocation_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::ReferenceFunctionsImpl<S>::SetLocation(const maxon::SourceLocation& allocLocation) const -> DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S)
{
	static_assert(!S::HAS_ERROR, "ErrorInterface::SetLocation can't be used on a Result object because it does not return a Result object itself."); ErrorInterface* o_ = (ErrorInterface*) this->GetPointer(); if (MAXON_UNLIKELY(!o_)) return this->PrivateGetRefMember(); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ErrorInterface, o_, ErrorInterface_SetLocation) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<ErrorInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ErrorInterface>() : PRIVATE_MAXON_VTABLE(ErrorInterface, o_); 
	mt_._ErrorInterface_SetLocation(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._ErrorInterface_SetLocation_Offset, allocLocation);
	return this->PrivateGetRefMember();
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::COWReferenceFunctionsImpl<S>::SetLocation(const maxon::SourceLocation& allocLocation) -> DOXYGEN_SWITCH(maxon::RefMemberType<S>, S)
{
	static_assert(!S::HAS_ERROR, "ErrorInterface::SetLocation can't be used on a Result object because it does not return a Result object itself."); ErrorInterface* o_ = (ErrorInterface*) this->MakeWritable(false).GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) return this->PrivateGetRefMember(); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ErrorInterface, o_, ErrorInterface_SetLocation) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<ErrorInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ErrorInterface>() : PRIVATE_MAXON_VTABLE(ErrorInterface, o_); 
	mt_._ErrorInterface_SetLocation(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._ErrorInterface_SetLocation_Offset, allocLocation);
	return this->PrivateGetRefMember();
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::ConstReferenceFunctionsImpl<S>::GetStackTrace() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Block<void* const>>, Block<void* const>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<Block<void* const>>, Block<void* const>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ErrorInterface* o_ = (const ErrorInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = ErrorInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<Block<void* const>>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ErrorInterface, o_, ErrorInterface_GetStackTrace) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<ErrorInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ErrorInterface>() : PRIVATE_MAXON_VTABLE(ErrorInterface, o_); 
	return (mt_._ErrorInterface_GetStackTrace(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._ErrorInterface_GetStackTrace_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::ReferenceFunctionsImpl<S>::SetStackTrace(const Block<void* const>& trace) const -> DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S)
{
	static_assert(!S::HAS_ERROR, "ErrorInterface::SetStackTrace can't be used on a Result object because it does not return a Result object itself."); ErrorInterface* o_ = (ErrorInterface*) this->GetPointer(); if (MAXON_UNLIKELY(!o_)) return this->PrivateGetRefMember(); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ErrorInterface, o_, ErrorInterface_SetStackTrace) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<ErrorInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ErrorInterface>() : PRIVATE_MAXON_VTABLE(ErrorInterface, o_); 
	mt_._ErrorInterface_SetStackTrace(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._ErrorInterface_SetStackTrace_Offset, trace);
	return this->PrivateGetRefMember();
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::COWReferenceFunctionsImpl<S>::SetStackTrace(const Block<void* const>& trace) -> DOXYGEN_SWITCH(maxon::RefMemberType<S>, S)
{
	static_assert(!S::HAS_ERROR, "ErrorInterface::SetStackTrace can't be used on a Result object because it does not return a Result object itself."); ErrorInterface* o_ = (ErrorInterface*) this->MakeWritable(false).GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) return this->PrivateGetRefMember(); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ErrorInterface, o_, ErrorInterface_SetStackTrace) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<ErrorInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ErrorInterface>() : PRIVATE_MAXON_VTABLE(ErrorInterface, o_); 
	mt_._ErrorInterface_SetStackTrace(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._ErrorInterface_SetStackTrace_Offset, trace);
	return this->PrivateGetRefMember();
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::ReferenceFunctionsImpl<S>::SetStackTrace(Int skip) const -> DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S)
{
	static_assert(!S::HAS_ERROR, "ErrorInterface::SetStackTrace can't be used on a Result object because it does not return a Result object itself."); ErrorInterface* o_ = (ErrorInterface*) this->GetPointer(); if (MAXON_UNLIKELY(!o_)) return this->PrivateGetRefMember(); 
	o_->SetStackTrace(skip);
	return this->PrivateGetRefMember();
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::COWReferenceFunctionsImpl<S>::SetStackTrace(Int skip) -> DOXYGEN_SWITCH(maxon::RefMemberType<S>, S)
{
	static_assert(!std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value, "Can't invoke MAXON_FUNCTION ErrorInterface::SetStackTrace on super."); static_assert(!S::HAS_ERROR, "ErrorInterface::SetStackTrace can't be used on a Result object because it does not return a Result object itself."); ErrorInterface* o_ = (ErrorInterface*) this->MakeWritable(false).GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) return this->PrivateGetRefMember(); 
	o_->SetStackTrace(skip);
	return this->PrivateGetRefMember();
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::ConstReferenceFunctionsImpl<S>::GetMessage() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ErrorInterface* o_ = (const ErrorInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = ErrorInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ErrorInterface, o_, ErrorInterface_GetMessage) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<ErrorInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ErrorInterface>() : PRIVATE_MAXON_VTABLE(ErrorInterface, o_); 
	return (mt_._ErrorInterface_GetMessage(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._ErrorInterface_GetMessage_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::ReferenceFunctionsImpl<S>::SetMessage(const String& message) const -> DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S)
{
	static_assert(!S::HAS_ERROR, "ErrorInterface::SetMessage can't be used on a Result object because it does not return a Result object itself."); ErrorInterface* o_ = (ErrorInterface*) this->GetPointer(); if (MAXON_UNLIKELY(!o_)) return this->PrivateGetRefMember(); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ErrorInterface, o_, ErrorInterface_SetMessage) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<ErrorInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ErrorInterface>() : PRIVATE_MAXON_VTABLE(ErrorInterface, o_); 
	mt_._ErrorInterface_SetMessage(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._ErrorInterface_SetMessage_Offset, message);
	return this->PrivateGetRefMember();
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::COWReferenceFunctionsImpl<S>::SetMessage(const String& message) -> DOXYGEN_SWITCH(maxon::RefMemberType<S>, S)
{
	static_assert(!S::HAS_ERROR, "ErrorInterface::SetMessage can't be used on a Result object because it does not return a Result object itself."); ErrorInterface* o_ = (ErrorInterface*) this->MakeWritable(false).GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) return this->PrivateGetRefMember(); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ErrorInterface, o_, ErrorInterface_SetMessage) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<ErrorInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ErrorInterface>() : PRIVATE_MAXON_VTABLE(ErrorInterface, o_); 
	mt_._ErrorInterface_SetMessage(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._ErrorInterface_SetMessage_Offset, message);
	return this->PrivateGetRefMember();
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::ConstReferenceFunctionsImpl<S>::GetCause() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const Error&>, const Error&>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<const Error&>, const Error&>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ErrorInterface* o_ = (const ErrorInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = ErrorInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<const Error&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ErrorInterface, o_, ErrorInterface_GetCause) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<ErrorInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ErrorInterface>() : PRIVATE_MAXON_VTABLE(ErrorInterface, o_); 
	return (mt_._ErrorInterface_GetCause(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._ErrorInterface_GetCause_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::ReferenceFunctionsImpl<S>::SetCause(const Error& cause) const -> DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S)
{
	static_assert(!S::HAS_ERROR, "ErrorInterface::SetCause can't be used on a Result object because it does not return a Result object itself."); ErrorInterface* o_ = (ErrorInterface*) this->GetPointer(); if (MAXON_UNLIKELY(!o_)) return this->PrivateGetRefMember(); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ErrorInterface, o_, ErrorInterface_SetCause) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<ErrorInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ErrorInterface>() : PRIVATE_MAXON_VTABLE(ErrorInterface, o_); 
	mt_._ErrorInterface_SetCause(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._ErrorInterface_SetCause_Offset, cause);
	return this->PrivateGetRefMember();
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::COWReferenceFunctionsImpl<S>::SetCause(const Error& cause) -> DOXYGEN_SWITCH(maxon::RefMemberType<S>, S)
{
	static_assert(!S::HAS_ERROR, "ErrorInterface::SetCause can't be used on a Result object because it does not return a Result object itself."); ErrorInterface* o_ = (ErrorInterface*) this->MakeWritable(false).GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) return this->PrivateGetRefMember(); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ErrorInterface, o_, ErrorInterface_SetCause) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<ErrorInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ErrorInterface>() : PRIVATE_MAXON_VTABLE(ErrorInterface, o_); 
	mt_._ErrorInterface_SetCause(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._ErrorInterface_SetCause_Offset, cause);
	return this->PrivateGetRefMember();
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::ConstReferenceFunctionsImpl<S>::GetMachine(MachineRef& machine) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ErrorInterface* o_ = (const ErrorInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = ErrorInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ErrorInterface, o_, ErrorInterface_GetMachine) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<ErrorInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ErrorInterface>() : PRIVATE_MAXON_VTABLE(ErrorInterface, o_); 
	mt_._ErrorInterface_GetMachine(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._ErrorInterface_GetMachine_Offset, machine);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::ReferenceFunctionsImpl<S>::SetMachine(const MachineRef& machine) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ErrorInterface* o_ = (ErrorInterface*) this->GetPointer(); if (MAXON_UNLIKELY(!o_)) return maxon::PrivateLogNullptrError(); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ErrorInterface, o_, ErrorInterface_SetMachine) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<ErrorInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ErrorInterface>() : PRIVATE_MAXON_VTABLE(ErrorInterface, o_); 
	mt_._ErrorInterface_SetMachine(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._ErrorInterface_SetMachine_Offset, machine);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::COWReferenceFunctionsImpl<S>::SetMachine(const MachineRef& machine) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ErrorInterface* o_ = (ErrorInterface*) this->MakeWritable(false).GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ErrorInterface, o_, ErrorInterface_SetMachine) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<ErrorInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ErrorInterface>() : PRIVATE_MAXON_VTABLE(ErrorInterface, o_); 
	mt_._ErrorInterface_SetMachine(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._ErrorInterface_SetMachine_Offset, machine);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::ConstReferenceFunctionsImpl<S>::PrivateGetCode() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ErrorInterface* o_ = (const ErrorInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = ErrorInterface::NullValuePtr(); if (!o_) return 0; } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ErrorInterface, o_, ErrorInterface_PrivateGetCode) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<ErrorInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ErrorInterface>() : PRIVATE_MAXON_VTABLE(ErrorInterface, o_); 
	return (mt_._ErrorInterface_PrivateGetCode(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._ErrorInterface_PrivateGetCode_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::ReferenceFunctionsImpl<S>::PrivateSetCode(Int code) const -> DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S)
{
	static_assert(!S::HAS_ERROR, "ErrorInterface::PrivateSetCode can't be used on a Result object because it does not return a Result object itself."); ErrorInterface* o_ = (ErrorInterface*) this->GetPointer(); if (MAXON_UNLIKELY(!o_)) return this->PrivateGetRefMember(); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ErrorInterface, o_, ErrorInterface_PrivateSetCode) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<ErrorInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ErrorInterface>() : PRIVATE_MAXON_VTABLE(ErrorInterface, o_); 
	mt_._ErrorInterface_PrivateSetCode(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._ErrorInterface_PrivateSetCode_Offset, code);
	return this->PrivateGetRefMember();
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ErrorInterface::COWReferenceFunctionsImpl<S>::PrivateSetCode(Int code) -> DOXYGEN_SWITCH(maxon::RefMemberType<S>, S)
{
	static_assert(!S::HAS_ERROR, "ErrorInterface::PrivateSetCode can't be used on a Result object because it does not return a Result object itself."); ErrorInterface* o_ = (ErrorInterface*) this->MakeWritable(false).GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) return this->PrivateGetRefMember(); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ErrorInterface, o_, ErrorInterface_PrivateSetCode) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<ErrorInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ErrorInterface>() : PRIVATE_MAXON_VTABLE(ErrorInterface, o_); 
	mt_._ErrorInterface_PrivateSetCode(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._ErrorInterface_PrivateSetCode_Offset, code);
	return this->PrivateGetRefMember();
}
auto ErrorInterface::GetPtr() -> Ptr { return Ptr(this); }
auto ErrorInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
static maxon::EntityUse s_ui_maxon_ErrorInterface(ErrorInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/objectbase.h", false);
#endif
/// @cond INTERNAL

/// @endcond

#if !defined(MAXON_API) || defined(DOXYGEN)
#endif
#ifdef MAXON_COMPILER_INTEL
#else
#endif
#ifndef MAXON_COMPILER_INTEL
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

