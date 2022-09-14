
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
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	PRIVATE_MAXON_MF_POINTER(DecoratorInterface_PrivateGetDecoratedObject, PrivateGetDecoratedObject, true, maxon::GenericComponent, const, (ObjectRef));
	maxon::Int DecoratorInterface_PrivateGetDecoratedObject_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DecoratorInterface, PrivateGetDecoratedObject))
	{
		maxon::Tie(DecoratorInterface_PrivateGetDecoratedObject, DecoratorInterface_PrivateGetDecoratedObject_Offset) = DecoratorInterface_PrivateGetDecoratedObject_GetPtr<W>(offset, true);
	}
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<DecoratorInterface, typename ObjectInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<DecoratorInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct DecoratorInterface::Hxx2
{
	template <typename S> class CWrapper : public ObjectInterface::Hxx2::template CWrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(PrivateGetDecoratedObject);
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename ObjectInterface::Hxx2::template CWrapper<S>;
			if constexpr (!S::Implementation::PROXY)
			{
				if (!(Super0::InitMTablesWithBases(info, offset))) return false;
			}
			auto* vt = (DecoratorInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, DecoratorInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		PRIVATE_MAXON_MF_WRAPPER(DecoratorInterface_PrivateGetDecoratedObject, maxon::GenericComponent, const, (ObjectRef)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->PrivateGetDecoratedObject(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto DecoratorInterface::PrivateGetDecoratedObject() const -> ObjectRef
{
	const DecoratorInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DecoratorInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.DecoratorInterface_PrivateGetDecoratedObject_Offset), mt_.DecoratorInterface_PrivateGetDecoratedObject);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DecoratorInterface::Hxx1::ConstFn<S>::PrivateGetDecoratedObject() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<ObjectRef>, ObjectRef>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<ObjectRef>, ObjectRef>::type>; static_assert(std::is_base_of<maxon::SelfPointerHandler, typename S::Handler>::value, "Method DecoratorInterface::PrivateGetDecoratedObject with refclass=false can only be invoked on self or super."); if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const DecoratorInterface* o_ = (const DecoratorInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = DecoratorInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<ObjectRef>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DecoratorInterface, o_, DecoratorInterface_PrivateGetDecoratedObject) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<DecoratorInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DecoratorInterface>() : PRIVATE_MAXON_VTABLE(DecoratorInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.DecoratorInterface_PrivateGetDecoratedObject_Offset), mt_.DecoratorInterface_PrivateGetDecoratedObject));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DecoratorInterface::Hxx1::ConstFn<S>::GetDecoratedObject() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<ObjectBaseRef<maxon::details::GetPrivateReferencedType<S>>>, ObjectBaseRef<maxon::details::GetPrivateReferencedType<S>>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<ObjectBaseRef<maxon::details::GetPrivateReferencedType<S>>>, ObjectBaseRef<maxon::details::GetPrivateReferencedType<S>>>::type>; static_assert(!std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value, "Can't invoke MAXON_FUNCTION DecoratorInterface::GetDecoratedObject on super."); if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const DecoratorInterface* o_ = (const DecoratorInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = DecoratorInterface::NullValuePtr(); if (!o_) return maxon::PrivateNullReturnValue<ObjectBaseRef<maxon::details::GetPrivateReferencedType<S>>>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (o_->GetDecoratedObject<maxon::details::GetPrivateReferencedType<S>>());
}
auto DecoratorInterface::GetPtr() -> Ptr { return Ptr(this); }
auto DecoratorInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_decorator)
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
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	PRIVATE_MAXON_MF_POINTER(EagerDecoratorInterface_PrivateSetDecoratedObject, PrivateSetDecoratedObject, true, maxon::GenericComponent,, (void), const ObjectRef& object);
	maxon::Int EagerDecoratorInterface_PrivateSetDecoratedObject_Offset;
	PRIVATE_MAXON_MF_POINTER(EagerDecoratorInterface_PrivateSetDecoratedObject_1, PrivateSetDecoratedObject, true, maxon::GenericComponent,, (void), ObjectRef&& object);
	maxon::Int EagerDecoratorInterface_PrivateSetDecoratedObject_1_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, EagerDecoratorInterface, PrivateSetDecoratedObject))
	{
		maxon::Tie(EagerDecoratorInterface_PrivateSetDecoratedObject, EagerDecoratorInterface_PrivateSetDecoratedObject_Offset) = EagerDecoratorInterface_PrivateSetDecoratedObject_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, EagerDecoratorInterface, PrivateSetDecoratedObject))
	{
		maxon::Tie(EagerDecoratorInterface_PrivateSetDecoratedObject_1, EagerDecoratorInterface_PrivateSetDecoratedObject_1_Offset) = EagerDecoratorInterface_PrivateSetDecoratedObject_1_GetPtr<W>(offset, true);
	}
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<EagerDecoratorInterface, typename DecoratorInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<EagerDecoratorInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct EagerDecoratorInterface::Hxx2
{
	template <typename S> class CWrapper : public DecoratorInterface::Hxx2::template CWrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(PrivateSetDecoratedObject);
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename DecoratorInterface::Hxx2::template CWrapper<S>;
			if constexpr (!S::Implementation::PROXY)
			{
				if (!(Super0::InitMTablesWithBases(info, offset))) return false;
			}
			auto* vt = (EagerDecoratorInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, EagerDecoratorInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		PRIVATE_MAXON_MF_WRAPPER(EagerDecoratorInterface_PrivateSetDecoratedObject, maxon::GenericComponent,, (void), const ObjectRef& object) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->PrivateSetDecoratedObject(object); }
		PRIVATE_MAXON_MF_WRAPPER(EagerDecoratorInterface_PrivateSetDecoratedObject_1, maxon::GenericComponent,, (void), ObjectRef&& object) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->PrivateSetDecoratedObject(std::forward<ObjectRef>(object)); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto EagerDecoratorInterface::PrivateSetDecoratedObject(const ObjectRef& object) -> void
{
	const EagerDecoratorInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(EagerDecoratorInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.EagerDecoratorInterface_PrivateSetDecoratedObject_Offset), mt_.EagerDecoratorInterface_PrivateSetDecoratedObject, object);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto EagerDecoratorInterface::PrivateSetDecoratedObject(ObjectRef&& object) -> void
{
	const EagerDecoratorInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(EagerDecoratorInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.EagerDecoratorInterface_PrivateSetDecoratedObject_1_Offset), mt_.EagerDecoratorInterface_PrivateSetDecoratedObject_1, std::forward<ObjectRef>(object));
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto EagerDecoratorInterface::Hxx1::Fn<S>::PrivateSetDecoratedObject(const ObjectRef& object) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; static_assert(std::is_base_of<maxon::SelfPointerHandler, typename S::Handler>::value, "Method EagerDecoratorInterface::PrivateSetDecoratedObject with refclass=false can only be invoked on self or super."); if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); EagerDecoratorInterface* o_ = (EagerDecoratorInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { DebugStop(); return maxon::PrivateLogNullptrError(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(EagerDecoratorInterface, o_, EagerDecoratorInterface_PrivateSetDecoratedObject) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<EagerDecoratorInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<EagerDecoratorInterface>() : PRIVATE_MAXON_VTABLE(EagerDecoratorInterface, o_); 
	PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.EagerDecoratorInterface_PrivateSetDecoratedObject_Offset), mt_.EagerDecoratorInterface_PrivateSetDecoratedObject, object);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto EagerDecoratorInterface::Hxx1::COWFn<S>::PrivateSetDecoratedObject(const ObjectRef& object) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; static_assert(std::is_base_of<maxon::SelfPointerHandler, typename S::Handler>::value, "Method EagerDecoratorInterface::PrivateSetDecoratedObject with refclass=false can only be invoked on self or super."); if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); EagerDecoratorInterface* o_ = (EagerDecoratorInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(EagerDecoratorInterface, o_, EagerDecoratorInterface_PrivateSetDecoratedObject) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<EagerDecoratorInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<EagerDecoratorInterface>() : PRIVATE_MAXON_VTABLE(EagerDecoratorInterface, o_); 
	PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.EagerDecoratorInterface_PrivateSetDecoratedObject_Offset), mt_.EagerDecoratorInterface_PrivateSetDecoratedObject, object);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto EagerDecoratorInterface::Hxx1::Fn<S>::SetDecoratedObject(const ObjectBaseRef<maxon::details::GetPrivateReferencedType<S>>& object) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); EagerDecoratorInterface* o_ = (EagerDecoratorInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { DebugStop(); return maxon::PrivateLogNullptrError(); } 
	o_->SetDecoratedObject<maxon::details::GetPrivateReferencedType<S>>(object);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto EagerDecoratorInterface::Hxx1::COWFn<S>::SetDecoratedObject(const ObjectBaseRef<maxon::details::GetPrivateReferencedType<S>>& object) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; static_assert(!std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value, "Can't invoke MAXON_FUNCTION EagerDecoratorInterface::SetDecoratedObject on super."); if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); EagerDecoratorInterface* o_ = (EagerDecoratorInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	o_->SetDecoratedObject<maxon::details::GetPrivateReferencedType<S>>(object);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto EagerDecoratorInterface::Hxx1::Fn<S>::PrivateSetDecoratedObject(ObjectRef&& object) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; static_assert(std::is_base_of<maxon::SelfPointerHandler, typename S::Handler>::value, "Method EagerDecoratorInterface::PrivateSetDecoratedObject with refclass=false can only be invoked on self or super."); if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); EagerDecoratorInterface* o_ = (EagerDecoratorInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { DebugStop(); return maxon::PrivateLogNullptrError(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(EagerDecoratorInterface, o_, EagerDecoratorInterface_PrivateSetDecoratedObject_1) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<EagerDecoratorInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<EagerDecoratorInterface>() : PRIVATE_MAXON_VTABLE(EagerDecoratorInterface, o_); 
	PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.EagerDecoratorInterface_PrivateSetDecoratedObject_1_Offset), mt_.EagerDecoratorInterface_PrivateSetDecoratedObject_1, std::forward<ObjectRef>(object));
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto EagerDecoratorInterface::Hxx1::COWFn<S>::PrivateSetDecoratedObject(ObjectRef&& object) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; static_assert(std::is_base_of<maxon::SelfPointerHandler, typename S::Handler>::value, "Method EagerDecoratorInterface::PrivateSetDecoratedObject with refclass=false can only be invoked on self or super."); if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); EagerDecoratorInterface* o_ = (EagerDecoratorInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(EagerDecoratorInterface, o_, EagerDecoratorInterface_PrivateSetDecoratedObject_1) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<EagerDecoratorInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<EagerDecoratorInterface>() : PRIVATE_MAXON_VTABLE(EagerDecoratorInterface, o_); 
	PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.EagerDecoratorInterface_PrivateSetDecoratedObject_1_Offset), mt_.EagerDecoratorInterface_PrivateSetDecoratedObject_1, std::forward<ObjectRef>(object));
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto EagerDecoratorInterface::Hxx1::Fn<S>::SetDecoratedObject(ObjectBaseRef<maxon::details::GetPrivateReferencedType<S>>&& object) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); EagerDecoratorInterface* o_ = (EagerDecoratorInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { DebugStop(); return maxon::PrivateLogNullptrError(); } 
	o_->SetDecoratedObject<maxon::details::GetPrivateReferencedType<S>>(std::forward<ObjectBaseRef<maxon::details::GetPrivateReferencedType<S>>>(object));
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto EagerDecoratorInterface::Hxx1::COWFn<S>::SetDecoratedObject(ObjectBaseRef<maxon::details::GetPrivateReferencedType<S>>&& object) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; static_assert(!std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value, "Can't invoke MAXON_FUNCTION EagerDecoratorInterface::SetDecoratedObject on super."); if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); EagerDecoratorInterface* o_ = (EagerDecoratorInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	o_->SetDecoratedObject<maxon::details::GetPrivateReferencedType<S>>(std::forward<ObjectBaseRef<maxon::details::GetPrivateReferencedType<S>>>(object));
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
auto EagerDecoratorInterface::GetPtr() -> Ptr { return Ptr(this); }
auto EagerDecoratorInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_decorator)
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
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	PRIVATE_MAXON_MF_POINTER(WeakDecoratorInterface_PrivateSetDecoratedObject, PrivateSetDecoratedObject, true, maxon::GenericComponent,, (void), const ObjectRef& object);
	maxon::Int WeakDecoratorInterface_PrivateSetDecoratedObject_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, WeakDecoratorInterface, PrivateSetDecoratedObject))
	{
		maxon::Tie(WeakDecoratorInterface_PrivateSetDecoratedObject, WeakDecoratorInterface_PrivateSetDecoratedObject_Offset) = WeakDecoratorInterface_PrivateSetDecoratedObject_GetPtr<W>(offset, true);
	}
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<WeakDecoratorInterface, typename DecoratorInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<WeakDecoratorInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct WeakDecoratorInterface::Hxx2
{
	template <typename S> class CWrapper : public DecoratorInterface::Hxx2::template CWrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(PrivateSetDecoratedObject);
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename DecoratorInterface::Hxx2::template CWrapper<S>;
			if constexpr (!S::Implementation::PROXY)
			{
				if (!(Super0::InitMTablesWithBases(info, offset))) return false;
			}
			auto* vt = (WeakDecoratorInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, WeakDecoratorInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		PRIVATE_MAXON_MF_WRAPPER(WeakDecoratorInterface_PrivateSetDecoratedObject, maxon::GenericComponent,, (void), const ObjectRef& object) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->PrivateSetDecoratedObject(object); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto WeakDecoratorInterface::PrivateSetDecoratedObject(const ObjectRef& object) -> void
{
	const WeakDecoratorInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(WeakDecoratorInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.WeakDecoratorInterface_PrivateSetDecoratedObject_Offset), mt_.WeakDecoratorInterface_PrivateSetDecoratedObject, object);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto WeakDecoratorInterface::Hxx1::Fn<S>::PrivateSetDecoratedObject(const ObjectRef& object) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; static_assert(std::is_base_of<maxon::SelfPointerHandler, typename S::Handler>::value, "Method WeakDecoratorInterface::PrivateSetDecoratedObject with refclass=false can only be invoked on self or super."); if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); WeakDecoratorInterface* o_ = (WeakDecoratorInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { DebugStop(); return maxon::PrivateLogNullptrError(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(WeakDecoratorInterface, o_, WeakDecoratorInterface_PrivateSetDecoratedObject) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<WeakDecoratorInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<WeakDecoratorInterface>() : PRIVATE_MAXON_VTABLE(WeakDecoratorInterface, o_); 
	PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.WeakDecoratorInterface_PrivateSetDecoratedObject_Offset), mt_.WeakDecoratorInterface_PrivateSetDecoratedObject, object);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto WeakDecoratorInterface::Hxx1::COWFn<S>::PrivateSetDecoratedObject(const ObjectRef& object) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; static_assert(std::is_base_of<maxon::SelfPointerHandler, typename S::Handler>::value, "Method WeakDecoratorInterface::PrivateSetDecoratedObject with refclass=false can only be invoked on self or super."); if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); WeakDecoratorInterface* o_ = (WeakDecoratorInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(WeakDecoratorInterface, o_, WeakDecoratorInterface_PrivateSetDecoratedObject) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<WeakDecoratorInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<WeakDecoratorInterface>() : PRIVATE_MAXON_VTABLE(WeakDecoratorInterface, o_); 
	PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.WeakDecoratorInterface_PrivateSetDecoratedObject_Offset), mt_.WeakDecoratorInterface_PrivateSetDecoratedObject, object);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto WeakDecoratorInterface::Hxx1::Fn<S>::SetDecoratedObject(const ObjectBaseRef<maxon::details::GetPrivateReferencedType<S>>& object) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); WeakDecoratorInterface* o_ = (WeakDecoratorInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { DebugStop(); return maxon::PrivateLogNullptrError(); } 
	o_->SetDecoratedObject<maxon::details::GetPrivateReferencedType<S>>(object);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto WeakDecoratorInterface::Hxx1::COWFn<S>::SetDecoratedObject(const ObjectBaseRef<maxon::details::GetPrivateReferencedType<S>>& object) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; static_assert(!std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value, "Can't invoke MAXON_FUNCTION WeakDecoratorInterface::SetDecoratedObject on super."); if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); WeakDecoratorInterface* o_ = (WeakDecoratorInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	o_->SetDecoratedObject<maxon::details::GetPrivateReferencedType<S>>(object);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
auto WeakDecoratorInterface::GetPtr() -> Ptr { return Ptr(this); }
auto WeakDecoratorInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_decorator)
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

