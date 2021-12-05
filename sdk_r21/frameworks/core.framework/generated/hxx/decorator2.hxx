
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1

struct DecoratorInterface::MTable
{
	PRIVATE_MAXON_IMPLEMENTS_CHECK(PrivateGetDecoratedObject);
	static const maxon::Char* const _ids;
	static const maxon::Bool HAS_NONSTATIC = false;
	ObjectRef (*_DecoratorInterface_PrivateGetDecoratedObject) (const maxon::GenericComponent* this_);
	maxon::Int _DecoratorInterface_PrivateGetDecoratedObject_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DecoratorInterface, PrivateGetDecoratedObject))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DecoratorInterface, PrivateGetDecoratedObject), W, MTable>::type::_DecoratorInterface_PrivateGetDecoratedObject;
			_DecoratorInterface_PrivateGetDecoratedObject = reinterpret_cast<const decltype(_DecoratorInterface_PrivateGetDecoratedObject)&>(ptr);
			_DecoratorInterface_PrivateGetDecoratedObject_Offset = offset;
		}
	}
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset)
	{
		if (!W::Implementation::PROXY && (!ObjectInterface::MTable::template InitWithBases<W>(info, offset))) return false;
		MTable* vt = (MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, _interface); if (!vt) return false;
		vt->Init<W>(offset); return true;
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<DecoratorInterface, typename ObjectInterface::MTable::template CombinedMTable<S>>;
	PRIVATE_MAXON_COMPBASE(DecoratorInterface);
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct DecoratorInterface::Hxx2
{
	template <typename S> class Wrapper : public ObjectInterface::Hxx2::template Wrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(PrivateGetDecoratedObject);
	static ObjectRef _DecoratorInterface_PrivateGetDecoratedObject(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->PrivateGetDecoratedObject(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto DecoratorInterface::PrivateGetDecoratedObject() const -> ObjectRef
{
	const DecoratorInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DecoratorInterface, this); return mt_._DecoratorInterface_PrivateGetDecoratedObject((const maxon::GenericComponent*) this + mt_._DecoratorInterface_PrivateGetDecoratedObject_Offset);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DecoratorInterface::Hxx1::ConstReferenceFunctionsImpl<S>::PrivateGetDecoratedObject() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<ObjectRef>, ObjectRef>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<ObjectRef>, ObjectRef>::type>; static_assert(std::is_base_of<maxon::SelfPointerHandler, typename S::Handler>::value, "Method DecoratorInterface::PrivateGetDecoratedObject with refclass=false can only be invoked on self or super."); if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const DecoratorInterface* o_ = (const DecoratorInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = DecoratorInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<ObjectRef>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DecoratorInterface, o_, DecoratorInterface_PrivateGetDecoratedObject) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<DecoratorInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DecoratorInterface>() : PRIVATE_MAXON_VTABLE(DecoratorInterface, o_); 
	return (mt_._DecoratorInterface_PrivateGetDecoratedObject(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._DecoratorInterface_PrivateGetDecoratedObject_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DecoratorInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetDecoratedObject() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<ObjectBaseRef<maxon::details::GetPrivateReferencedType<S>>>, ObjectBaseRef<maxon::details::GetPrivateReferencedType<S>>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<ObjectBaseRef<maxon::details::GetPrivateReferencedType<S>>>, ObjectBaseRef<maxon::details::GetPrivateReferencedType<S>>>::type>; static_assert(!std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value, "Can't invoke MAXON_FUNCTION DecoratorInterface::GetDecoratedObject on super."); if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const DecoratorInterface* o_ = (const DecoratorInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = DecoratorInterface::NullValuePtr(); if (!o_) return maxon::PrivateNullReturnValue<ObjectBaseRef<maxon::details::GetPrivateReferencedType<S>>>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (o_->GetDecoratedObject<maxon::details::GetPrivateReferencedType<S>>());
}
auto DecoratorInterface::GetPtr() -> Ptr { return Ptr(this); }
auto DecoratorInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_DecoratorInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_DecoratorInterface() { new (s_ui_maxon_DecoratorInterface) maxon::EntityUse(DecoratorInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/decorator.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_DecoratorInterface(DecoratorInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/decorator.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
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
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, EagerDecoratorInterface, PrivateSetDecoratedObject))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, EagerDecoratorInterface, PrivateSetDecoratedObject), W, MTable>::type::_EagerDecoratorInterface_PrivateSetDecoratedObject;
			_EagerDecoratorInterface_PrivateSetDecoratedObject = reinterpret_cast<const decltype(_EagerDecoratorInterface_PrivateSetDecoratedObject)&>(ptr);
			_EagerDecoratorInterface_PrivateSetDecoratedObject_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, EagerDecoratorInterface, PrivateSetDecoratedObject))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, EagerDecoratorInterface, PrivateSetDecoratedObject), W, MTable>::type::_EagerDecoratorInterface_PrivateSetDecoratedObject_1;
			_EagerDecoratorInterface_PrivateSetDecoratedObject_1 = reinterpret_cast<const decltype(_EagerDecoratorInterface_PrivateSetDecoratedObject_1)&>(ptr);
			_EagerDecoratorInterface_PrivateSetDecoratedObject_1_Offset = offset;
		}
	}
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset)
	{
		if (!W::Implementation::PROXY && (!DecoratorInterface::MTable::template InitWithBases<W>(info, offset))) return false;
		MTable* vt = (MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, _interface); if (!vt) return false;
		vt->Init<W>(offset); return true;
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<EagerDecoratorInterface, typename DecoratorInterface::MTable::template CombinedMTable<S>>;
	PRIVATE_MAXON_COMPBASE(EagerDecoratorInterface);
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct EagerDecoratorInterface::Hxx2
{
	template <typename S> class Wrapper : public DecoratorInterface::Hxx2::template Wrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(PrivateSetDecoratedObject);
	static void _EagerDecoratorInterface_PrivateSetDecoratedObject(maxon::GenericComponent* this_, const ObjectRef& object) { return ((typename S::Implementation*) this_)->PrivateSetDecoratedObject(object); }
	static void _EagerDecoratorInterface_PrivateSetDecoratedObject_1(maxon::GenericComponent* this_, ObjectRef&& object) { return ((typename S::Implementation*) this_)->PrivateSetDecoratedObject(std::forward<ObjectRef>(object)); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto EagerDecoratorInterface::PrivateSetDecoratedObject(const ObjectRef& object) -> void
{
	const EagerDecoratorInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(EagerDecoratorInterface, this); return mt_._EagerDecoratorInterface_PrivateSetDecoratedObject((maxon::GenericComponent*) this + mt_._EagerDecoratorInterface_PrivateSetDecoratedObject_Offset, object);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto EagerDecoratorInterface::PrivateSetDecoratedObject(ObjectRef&& object) -> void
{
	const EagerDecoratorInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(EagerDecoratorInterface, this); return mt_._EagerDecoratorInterface_PrivateSetDecoratedObject_1((maxon::GenericComponent*) this + mt_._EagerDecoratorInterface_PrivateSetDecoratedObject_1_Offset, std::forward<ObjectRef>(object));
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto EagerDecoratorInterface::Hxx1::ReferenceFunctionsImpl<S>::PrivateSetDecoratedObject(const ObjectRef& object) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; static_assert(std::is_base_of<maxon::SelfPointerHandler, typename S::Handler>::value, "Method EagerDecoratorInterface::PrivateSetDecoratedObject with refclass=false can only be invoked on self or super."); if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); EagerDecoratorInterface* o_ = (EagerDecoratorInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateLogNullptrError(); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(EagerDecoratorInterface, o_, EagerDecoratorInterface_PrivateSetDecoratedObject) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<EagerDecoratorInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<EagerDecoratorInterface>() : PRIVATE_MAXON_VTABLE(EagerDecoratorInterface, o_); 
	mt_._EagerDecoratorInterface_PrivateSetDecoratedObject(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._EagerDecoratorInterface_PrivateSetDecoratedObject_Offset, object);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto EagerDecoratorInterface::Hxx1::COWReferenceFunctionsImpl<S>::PrivateSetDecoratedObject(const ObjectRef& object) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; static_assert(std::is_base_of<maxon::SelfPointerHandler, typename S::Handler>::value, "Method EagerDecoratorInterface::PrivateSetDecoratedObject with refclass=false can only be invoked on self or super."); if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); EagerDecoratorInterface* o_ = (EagerDecoratorInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(EagerDecoratorInterface, o_, EagerDecoratorInterface_PrivateSetDecoratedObject) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<EagerDecoratorInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<EagerDecoratorInterface>() : PRIVATE_MAXON_VTABLE(EagerDecoratorInterface, o_); 
	mt_._EagerDecoratorInterface_PrivateSetDecoratedObject(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._EagerDecoratorInterface_PrivateSetDecoratedObject_Offset, object);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto EagerDecoratorInterface::Hxx1::ReferenceFunctionsImpl<S>::SetDecoratedObject(const ObjectBaseRef<maxon::details::GetPrivateReferencedType<S>>& object) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); EagerDecoratorInterface* o_ = (EagerDecoratorInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateLogNullptrError(); 
	o_->SetDecoratedObject<maxon::details::GetPrivateReferencedType<S>>(object);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto EagerDecoratorInterface::Hxx1::COWReferenceFunctionsImpl<S>::SetDecoratedObject(const ObjectBaseRef<maxon::details::GetPrivateReferencedType<S>>& object) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; static_assert(!std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value, "Can't invoke MAXON_FUNCTION EagerDecoratorInterface::SetDecoratedObject on super."); if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); EagerDecoratorInterface* o_ = (EagerDecoratorInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	o_->SetDecoratedObject<maxon::details::GetPrivateReferencedType<S>>(object);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto EagerDecoratorInterface::Hxx1::ReferenceFunctionsImpl<S>::PrivateSetDecoratedObject(ObjectRef&& object) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; static_assert(std::is_base_of<maxon::SelfPointerHandler, typename S::Handler>::value, "Method EagerDecoratorInterface::PrivateSetDecoratedObject with refclass=false can only be invoked on self or super."); if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); EagerDecoratorInterface* o_ = (EagerDecoratorInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateLogNullptrError(); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(EagerDecoratorInterface, o_, EagerDecoratorInterface_PrivateSetDecoratedObject_1) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<EagerDecoratorInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<EagerDecoratorInterface>() : PRIVATE_MAXON_VTABLE(EagerDecoratorInterface, o_); 
	mt_._EagerDecoratorInterface_PrivateSetDecoratedObject_1(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._EagerDecoratorInterface_PrivateSetDecoratedObject_1_Offset, std::forward<ObjectRef>(object));
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto EagerDecoratorInterface::Hxx1::COWReferenceFunctionsImpl<S>::PrivateSetDecoratedObject(ObjectRef&& object) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; static_assert(std::is_base_of<maxon::SelfPointerHandler, typename S::Handler>::value, "Method EagerDecoratorInterface::PrivateSetDecoratedObject with refclass=false can only be invoked on self or super."); if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); EagerDecoratorInterface* o_ = (EagerDecoratorInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(EagerDecoratorInterface, o_, EagerDecoratorInterface_PrivateSetDecoratedObject_1) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<EagerDecoratorInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<EagerDecoratorInterface>() : PRIVATE_MAXON_VTABLE(EagerDecoratorInterface, o_); 
	mt_._EagerDecoratorInterface_PrivateSetDecoratedObject_1(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._EagerDecoratorInterface_PrivateSetDecoratedObject_1_Offset, std::forward<ObjectRef>(object));
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto EagerDecoratorInterface::Hxx1::ReferenceFunctionsImpl<S>::SetDecoratedObject(ObjectBaseRef<maxon::details::GetPrivateReferencedType<S>>&& object) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); EagerDecoratorInterface* o_ = (EagerDecoratorInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateLogNullptrError(); 
	o_->SetDecoratedObject<maxon::details::GetPrivateReferencedType<S>>(std::forward<ObjectBaseRef<maxon::details::GetPrivateReferencedType<S>>>(object));
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto EagerDecoratorInterface::Hxx1::COWReferenceFunctionsImpl<S>::SetDecoratedObject(ObjectBaseRef<maxon::details::GetPrivateReferencedType<S>>&& object) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; static_assert(!std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value, "Can't invoke MAXON_FUNCTION EagerDecoratorInterface::SetDecoratedObject on super."); if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); EagerDecoratorInterface* o_ = (EagerDecoratorInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	o_->SetDecoratedObject<maxon::details::GetPrivateReferencedType<S>>(std::forward<ObjectBaseRef<maxon::details::GetPrivateReferencedType<S>>>(object));
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
auto EagerDecoratorInterface::GetPtr() -> Ptr { return Ptr(this); }
auto EagerDecoratorInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_EagerDecoratorInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_EagerDecoratorInterface() { new (s_ui_maxon_EagerDecoratorInterface) maxon::EntityUse(EagerDecoratorInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/decorator.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_EagerDecoratorInterface(EagerDecoratorInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/decorator.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif

struct WeakDecoratorInterface::MTable
{
	PRIVATE_MAXON_IMPLEMENTS_CHECK(PrivateSetDecoratedObject);
	static const maxon::Char* const _ids;
	static const maxon::Bool HAS_NONSTATIC = false;
	void (*_WeakDecoratorInterface_PrivateSetDecoratedObject) (maxon::GenericComponent* this_, const ObjectRef& object);
	maxon::Int _WeakDecoratorInterface_PrivateSetDecoratedObject_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, WeakDecoratorInterface, PrivateSetDecoratedObject))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, WeakDecoratorInterface, PrivateSetDecoratedObject), W, MTable>::type::_WeakDecoratorInterface_PrivateSetDecoratedObject;
			_WeakDecoratorInterface_PrivateSetDecoratedObject = reinterpret_cast<const decltype(_WeakDecoratorInterface_PrivateSetDecoratedObject)&>(ptr);
			_WeakDecoratorInterface_PrivateSetDecoratedObject_Offset = offset;
		}
	}
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset)
	{
		if (!W::Implementation::PROXY && (!DecoratorInterface::MTable::template InitWithBases<W>(info, offset))) return false;
		MTable* vt = (MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, _interface); if (!vt) return false;
		vt->Init<W>(offset); return true;
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<WeakDecoratorInterface, typename DecoratorInterface::MTable::template CombinedMTable<S>>;
	PRIVATE_MAXON_COMPBASE(WeakDecoratorInterface);
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct WeakDecoratorInterface::Hxx2
{
	template <typename S> class Wrapper : public DecoratorInterface::Hxx2::template Wrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(PrivateSetDecoratedObject);
	static void _WeakDecoratorInterface_PrivateSetDecoratedObject(maxon::GenericComponent* this_, const ObjectRef& object) { return ((typename S::Implementation*) this_)->PrivateSetDecoratedObject(object); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto WeakDecoratorInterface::PrivateSetDecoratedObject(const ObjectRef& object) -> void
{
	const WeakDecoratorInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(WeakDecoratorInterface, this); return mt_._WeakDecoratorInterface_PrivateSetDecoratedObject((maxon::GenericComponent*) this + mt_._WeakDecoratorInterface_PrivateSetDecoratedObject_Offset, object);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto WeakDecoratorInterface::Hxx1::ReferenceFunctionsImpl<S>::PrivateSetDecoratedObject(const ObjectRef& object) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; static_assert(std::is_base_of<maxon::SelfPointerHandler, typename S::Handler>::value, "Method WeakDecoratorInterface::PrivateSetDecoratedObject with refclass=false can only be invoked on self or super."); if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); WeakDecoratorInterface* o_ = (WeakDecoratorInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateLogNullptrError(); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(WeakDecoratorInterface, o_, WeakDecoratorInterface_PrivateSetDecoratedObject) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<WeakDecoratorInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<WeakDecoratorInterface>() : PRIVATE_MAXON_VTABLE(WeakDecoratorInterface, o_); 
	mt_._WeakDecoratorInterface_PrivateSetDecoratedObject(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._WeakDecoratorInterface_PrivateSetDecoratedObject_Offset, object);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto WeakDecoratorInterface::Hxx1::COWReferenceFunctionsImpl<S>::PrivateSetDecoratedObject(const ObjectRef& object) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; static_assert(std::is_base_of<maxon::SelfPointerHandler, typename S::Handler>::value, "Method WeakDecoratorInterface::PrivateSetDecoratedObject with refclass=false can only be invoked on self or super."); if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); WeakDecoratorInterface* o_ = (WeakDecoratorInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(WeakDecoratorInterface, o_, WeakDecoratorInterface_PrivateSetDecoratedObject) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<WeakDecoratorInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<WeakDecoratorInterface>() : PRIVATE_MAXON_VTABLE(WeakDecoratorInterface, o_); 
	mt_._WeakDecoratorInterface_PrivateSetDecoratedObject(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._WeakDecoratorInterface_PrivateSetDecoratedObject_Offset, object);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto WeakDecoratorInterface::Hxx1::ReferenceFunctionsImpl<S>::SetDecoratedObject(const ObjectBaseRef<maxon::details::GetPrivateReferencedType<S>>& object) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); WeakDecoratorInterface* o_ = (WeakDecoratorInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateLogNullptrError(); 
	o_->SetDecoratedObject<maxon::details::GetPrivateReferencedType<S>>(object);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto WeakDecoratorInterface::Hxx1::COWReferenceFunctionsImpl<S>::SetDecoratedObject(const ObjectBaseRef<maxon::details::GetPrivateReferencedType<S>>& object) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; static_assert(!std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value, "Can't invoke MAXON_FUNCTION WeakDecoratorInterface::SetDecoratedObject on super."); if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); WeakDecoratorInterface* o_ = (WeakDecoratorInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	o_->SetDecoratedObject<maxon::details::GetPrivateReferencedType<S>>(object);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
auto WeakDecoratorInterface::GetPtr() -> Ptr { return Ptr(this); }
auto WeakDecoratorInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_WeakDecoratorInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_WeakDecoratorInterface() { new (s_ui_maxon_WeakDecoratorInterface) maxon::EntityUse(WeakDecoratorInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/decorator.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_WeakDecoratorInterface(WeakDecoratorInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/decorator.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

