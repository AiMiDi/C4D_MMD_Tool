
#ifndef DOXYGEN

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#pragma GCC diagnostic ignored "-Wmisleading-indentation"
#endif

#if 1

struct DecoratorInterface::MTable
{
	PRIVATE_MAXON_IMPLEMENTS_CHECK(PrivateGetDecoratedObject);
	static const maxon::Char* const _ids;
	static const maxon::Bool HAS_NONSTATIC = false;
	const ObjectRef& (*_DecoratorInterface_PrivateGetDecoratedObject) (const maxon::GenericComponent* this_);
	maxon::Int _DecoratorInterface_PrivateGetDecoratedObject_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
		if (PRIVATE_MAXON_IMPLEMENTS(W::Implementation, DecoratorInterface, PrivateGetDecoratedObject))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(W::Implementation, DecoratorInterface, PrivateGetDecoratedObject), W, MTable>::type::_DecoratorInterface_PrivateGetDecoratedObject;
			_DecoratorInterface_PrivateGetDecoratedObject = reinterpret_cast<const decltype(_DecoratorInterface_PrivateGetDecoratedObject)&>(ptr);
			_DecoratorInterface_PrivateGetDecoratedObject_Offset = offset;
		}
	}
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset)
	{
		if (!W::Implementation::PROXY && (!Object::MTable::InitWithBases<W>(info, offset))) return false;
		MTable* vt = (MTable*) maxon::Object::PrivateGetOrCreateMTable(info, _interface); if (!vt) return false;
		vt->Init<W>(offset); return true;
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<DecoratorInterface, Object::MTable::CombinedMTable<S>>;
	PRIVATE_MAXON_COMPBASE(DecoratorInterface);
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

template <typename S> class DecoratorInterface::Wrapper : public Object::Wrapper<S>
{
public:
	PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(PrivateGetDecoratedObject);
	static const ObjectRef& _DecoratorInterface_PrivateGetDecoratedObject(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->PrivateGetDecoratedObject(); }
};

MAXON_ATTRIBUTE_FORCE_INLINE auto DecoratorInterface::PrivateGetDecoratedObject() const -> const ObjectRef&
{
	const DecoratorInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DecoratorInterface, this); return mt_._DecoratorInterface_PrivateGetDecoratedObject((const maxon::GenericComponent*) this + mt_._DecoratorInterface_PrivateGetDecoratedObject_Offset);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DecoratorInterface::ConstReferenceFunctionsImpl<S>::GetDecoratedObject() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const ObjectBaseRef<typename S::PrivateReferencedType>&>, const ObjectBaseRef<typename S::PrivateReferencedType>&>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<const ObjectBaseRef<typename S::PrivateReferencedType>&>, const ObjectBaseRef<typename S::PrivateReferencedType>&>::type>; static_assert(!std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value, "Can't invoke MAXON_FUNCTION DecoratorInterface::GetDecoratedObject on super."); if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const DecoratorInterface* o_ = (const DecoratorInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = DecoratorInterface::NullValuePtr(); if (!o_) return maxon::PrivateNullReturnValue<const ObjectBaseRef<typename S::PrivateReferencedType>&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (o_->GetDecoratedObject<typename S::PrivateReferencedType>());
}
auto DecoratorInterface::GetPtr() -> Ptr { return Ptr(this); }
auto DecoratorInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
static maxon::EntityUse s_ui_maxon_DecoratorInterface(DecoratorInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/decorator.h", false);
#endif

struct EagerDecoratorInterface::MTable
{
	PRIVATE_MAXON_IMPLEMENTS_CHECK(PrivateSetDecoratedObject);
	static const maxon::Char* const _ids;
	static const maxon::Bool HAS_NONSTATIC = false;
	void (*_EagerDecoratorInterface_PrivateSetDecoratedObject) (maxon::GenericComponent* this_, const ObjectRef& object);
	maxon::Int _EagerDecoratorInterface_PrivateSetDecoratedObject_Offset;
	void (*_EagerDecoratorInterface_PrivateSetDecoratedObject_1) (maxon::GenericComponent* this_, ObjectRef&& object);
	maxon::Int _EagerDecoratorInterface_PrivateSetDecoratedObject_1_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
		if (PRIVATE_MAXON_IMPLEMENTS(W::Implementation, EagerDecoratorInterface, PrivateSetDecoratedObject))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(W::Implementation, EagerDecoratorInterface, PrivateSetDecoratedObject), W, MTable>::type::_EagerDecoratorInterface_PrivateSetDecoratedObject;
			_EagerDecoratorInterface_PrivateSetDecoratedObject = reinterpret_cast<const decltype(_EagerDecoratorInterface_PrivateSetDecoratedObject)&>(ptr);
			_EagerDecoratorInterface_PrivateSetDecoratedObject_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(W::Implementation, EagerDecoratorInterface, PrivateSetDecoratedObject))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(W::Implementation, EagerDecoratorInterface, PrivateSetDecoratedObject), W, MTable>::type::_EagerDecoratorInterface_PrivateSetDecoratedObject_1;
			_EagerDecoratorInterface_PrivateSetDecoratedObject_1 = reinterpret_cast<const decltype(_EagerDecoratorInterface_PrivateSetDecoratedObject_1)&>(ptr);
			_EagerDecoratorInterface_PrivateSetDecoratedObject_1_Offset = offset;
		}
	}
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset)
	{
		if (!W::Implementation::PROXY && (!DecoratorInterface::MTable::InitWithBases<W>(info, offset))) return false;
		MTable* vt = (MTable*) maxon::Object::PrivateGetOrCreateMTable(info, _interface); if (!vt) return false;
		vt->Init<W>(offset); return true;
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<EagerDecoratorInterface, DecoratorInterface::MTable::CombinedMTable<S>>;
	PRIVATE_MAXON_COMPBASE(EagerDecoratorInterface);
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

template <typename S> class EagerDecoratorInterface::Wrapper : public DecoratorInterface::Wrapper<S>
{
public:
	PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(PrivateSetDecoratedObject);
	static void _EagerDecoratorInterface_PrivateSetDecoratedObject(maxon::GenericComponent* this_, const ObjectRef& object) { return ((typename S::Implementation*) this_)->PrivateSetDecoratedObject(object); }
	static void _EagerDecoratorInterface_PrivateSetDecoratedObject_1(maxon::GenericComponent* this_, ObjectRef&& object) { return ((typename S::Implementation*) this_)->PrivateSetDecoratedObject(std::forward<ObjectRef>(object)); }
};

MAXON_ATTRIBUTE_FORCE_INLINE auto EagerDecoratorInterface::PrivateSetDecoratedObject(const ObjectRef& object) -> void
{
	const EagerDecoratorInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(EagerDecoratorInterface, this); return mt_._EagerDecoratorInterface_PrivateSetDecoratedObject((maxon::GenericComponent*) this + mt_._EagerDecoratorInterface_PrivateSetDecoratedObject_Offset, object);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto EagerDecoratorInterface::PrivateSetDecoratedObject(ObjectRef&& object) -> void
{
	const EagerDecoratorInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(EagerDecoratorInterface, this); return mt_._EagerDecoratorInterface_PrivateSetDecoratedObject_1((maxon::GenericComponent*) this + mt_._EagerDecoratorInterface_PrivateSetDecoratedObject_1_Offset, std::forward<ObjectRef>(object));
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto EagerDecoratorInterface::ReferenceFunctionsImpl<S>::SetDecoratedObject(const ObjectBaseRef<typename S::PrivateReferencedType>& object) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); EagerDecoratorInterface* o_ = (EagerDecoratorInterface*) this->GetPointer(); if (MAXON_UNLIKELY(!o_)) return maxon::PrivateLogNullptrError(); 
	o_->SetDecoratedObject<typename S::PrivateReferencedType>(object);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto EagerDecoratorInterface::COWReferenceFunctionsImpl<S>::SetDecoratedObject(const ObjectBaseRef<typename S::PrivateReferencedType>& object) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; static_assert(!std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value, "Can't invoke MAXON_FUNCTION EagerDecoratorInterface::SetDecoratedObject on super."); if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); EagerDecoratorInterface* o_ = (EagerDecoratorInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	o_->SetDecoratedObject<typename S::PrivateReferencedType>(object);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto EagerDecoratorInterface::ReferenceFunctionsImpl<S>::SetDecoratedObject(ObjectBaseRef<typename S::PrivateReferencedType>&& object) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); EagerDecoratorInterface* o_ = (EagerDecoratorInterface*) this->GetPointer(); if (MAXON_UNLIKELY(!o_)) return maxon::PrivateLogNullptrError(); 
	o_->SetDecoratedObject<typename S::PrivateReferencedType>(std::forward<ObjectBaseRef<typename S::PrivateReferencedType>>(object));
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto EagerDecoratorInterface::COWReferenceFunctionsImpl<S>::SetDecoratedObject(ObjectBaseRef<typename S::PrivateReferencedType>&& object) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; static_assert(!std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value, "Can't invoke MAXON_FUNCTION EagerDecoratorInterface::SetDecoratedObject on super."); if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); EagerDecoratorInterface* o_ = (EagerDecoratorInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	o_->SetDecoratedObject<typename S::PrivateReferencedType>(std::forward<ObjectBaseRef<typename S::PrivateReferencedType>>(object));
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
auto EagerDecoratorInterface::GetPtr() -> Ptr { return Ptr(this); }
auto EagerDecoratorInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
static maxon::EntityUse s_ui_maxon_EagerDecoratorInterface(EagerDecoratorInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/decorator.h", false);
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

