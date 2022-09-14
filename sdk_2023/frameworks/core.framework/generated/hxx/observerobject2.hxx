
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1
/// @cond INTERNAL

/// @endcond


struct ObserverObjectInterface::MTable
{
	PRIVATE_MAXON_IMPLEMENTS_CHECK(AddSenderSignal);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetName);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(ObserverConnectNotify);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(ObserverDestroyed);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(ObserverDisconnectNotify);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(RemoveSenderSignal);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(SetName);
	static const maxon::Char* const _ids;
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
/// @cond INTERNAL

	PRIVATE_MAXON_MF_POINTER(ObserverObjectInterface_AddSenderSignal, AddSenderSignal, true, maxon::GenericComponent,, (Result<void>), ObservableBaseInterface* observable);
	maxon::Int ObserverObjectInterface_AddSenderSignal_Offset;
	PRIVATE_MAXON_MF_POINTER(ObserverObjectInterface_RemoveSenderSignal, RemoveSenderSignal, true, maxon::GenericComponent,, (void), ObservableBaseInterface* observable);
	maxon::Int ObserverObjectInterface_RemoveSenderSignal_Offset;
/// @endcond

	PRIVATE_MAXON_MF_POINTER(ObserverObjectInterface_GetName, GetName, true, maxon::GenericComponent, const, (String));
	maxon::Int ObserverObjectInterface_GetName_Offset;
	PRIVATE_MAXON_MF_POINTER(ObserverObjectInterface_SetName, SetName, true, maxon::GenericComponent,, (void), const String& name);
	maxon::Int ObserverObjectInterface_SetName_Offset;
	PRIVATE_MAXON_MF_POINTER(ObserverObjectInterface_ObserverDestroyed, ObserverDestroyed, true, maxon::GenericComponent, const, (maxon::ObservableRef<ObserverDestroyedDelegate>));
	maxon::Int ObserverObjectInterface_ObserverDestroyed_Offset;
	PRIVATE_MAXON_MF_POINTER(ObserverObjectInterface_ObserverDisconnectNotify, ObserverDisconnectNotify, true, maxon::GenericComponent, const, (maxon::ObservableRef<ObserverDisconnectNotifyDelegate>));
	maxon::Int ObserverObjectInterface_ObserverDisconnectNotify_Offset;
	PRIVATE_MAXON_MF_POINTER(ObserverObjectInterface_ObserverConnectNotify, ObserverConnectNotify, true, maxon::GenericComponent, const, (maxon::ObservableRef<ObserverConnectNotifyDelegate>));
	maxon::Int ObserverObjectInterface_ObserverConnectNotify_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
/// @cond INTERNAL

	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ObserverObjectInterface, AddSenderSignal))
	{
		maxon::Tie(ObserverObjectInterface_AddSenderSignal, ObserverObjectInterface_AddSenderSignal_Offset) = ObserverObjectInterface_AddSenderSignal_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ObserverObjectInterface, RemoveSenderSignal))
	{
		maxon::Tie(ObserverObjectInterface_RemoveSenderSignal, ObserverObjectInterface_RemoveSenderSignal_Offset) = ObserverObjectInterface_RemoveSenderSignal_GetPtr<W>(offset, true);
	}
/// @endcond

	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ObserverObjectInterface, GetName))
	{
		maxon::Tie(ObserverObjectInterface_GetName, ObserverObjectInterface_GetName_Offset) = ObserverObjectInterface_GetName_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ObserverObjectInterface, SetName))
	{
		maxon::Tie(ObserverObjectInterface_SetName, ObserverObjectInterface_SetName_Offset) = ObserverObjectInterface_SetName_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ObserverObjectInterface, ObserverDestroyed))
	{
		maxon::Tie(ObserverObjectInterface_ObserverDestroyed, ObserverObjectInterface_ObserverDestroyed_Offset) = ObserverObjectInterface_ObserverDestroyed_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ObserverObjectInterface, ObserverDisconnectNotify))
	{
		maxon::Tie(ObserverObjectInterface_ObserverDisconnectNotify, ObserverObjectInterface_ObserverDisconnectNotify_Offset) = ObserverObjectInterface_ObserverDisconnectNotify_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ObserverObjectInterface, ObserverConnectNotify))
	{
		maxon::Tie(ObserverObjectInterface_ObserverConnectNotify, ObserverObjectInterface_ObserverConnectNotify_Offset) = ObserverObjectInterface_ObserverConnectNotify_GetPtr<W>(offset, true);
	}
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<ObserverObjectInterface, typename ObjectInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<ObserverObjectInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct ObserverObjectInterface::Hxx2
{
	template <typename S> class CWrapper : public ObjectInterface::Hxx2::template CWrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(AddSenderSignal);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetName);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(ObserverConnectNotify);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(ObserverDestroyed);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(ObserverDisconnectNotify);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(RemoveSenderSignal);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(SetName);
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename ObjectInterface::Hxx2::template CWrapper<S>;
			if constexpr (!S::Implementation::PROXY)
			{
				if (!(Super0::InitMTablesWithBases(info, offset))) return false;
			}
			auto* vt = (ObserverObjectInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, ObserverObjectInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
/// @cond INTERNAL

		PRIVATE_MAXON_MF_WRAPPER(ObserverObjectInterface_AddSenderSignal, maxon::GenericComponent,, (Result<void>), ObservableBaseInterface* observable) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->AddSenderSignal(observable); }
		PRIVATE_MAXON_MF_WRAPPER(ObserverObjectInterface_RemoveSenderSignal, maxon::GenericComponent,, (void), ObservableBaseInterface* observable) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->RemoveSenderSignal(observable); }
/// @endcond

		PRIVATE_MAXON_MF_WRAPPER(ObserverObjectInterface_GetName, maxon::GenericComponent, const, (String)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetName(); }
		PRIVATE_MAXON_MF_WRAPPER(ObserverObjectInterface_SetName, maxon::GenericComponent,, (void), const String& name) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->SetName(name); }
		PRIVATE_MAXON_MF_WRAPPER(ObserverObjectInterface_ObserverDestroyed, maxon::GenericComponent, const, (maxon::ObservableRef<ObserverDestroyedDelegate>)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->ObserverDestroyed(); }
		PRIVATE_MAXON_MF_WRAPPER(ObserverObjectInterface_ObserverDisconnectNotify, maxon::GenericComponent, const, (maxon::ObservableRef<ObserverDisconnectNotifyDelegate>)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->ObserverDisconnectNotify(); }
		PRIVATE_MAXON_MF_WRAPPER(ObserverObjectInterface_ObserverConnectNotify, maxon::GenericComponent, const, (maxon::ObservableRef<ObserverConnectNotifyDelegate>)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->ObserverConnectNotify(); }
	};

};
/// @cond INTERNAL

MAXON_ATTRIBUTE_FORCE_INLINE auto ObserverObjectInterface::AddSenderSignal(ObservableBaseInterface* observable) -> Result<void>
{
	const ObserverObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ObserverObjectInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.ObserverObjectInterface_AddSenderSignal_Offset), mt_.ObserverObjectInterface_AddSenderSignal, observable);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ObserverObjectInterface::RemoveSenderSignal(ObservableBaseInterface* observable) -> void
{
	const ObserverObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ObserverObjectInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.ObserverObjectInterface_RemoveSenderSignal_Offset), mt_.ObserverObjectInterface_RemoveSenderSignal, observable);
}
/// @endcond

MAXON_ATTRIBUTE_FORCE_INLINE auto ObserverObjectInterface::GetName() const -> String
{
	const ObserverObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ObserverObjectInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.ObserverObjectInterface_GetName_Offset), mt_.ObserverObjectInterface_GetName);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ObserverObjectInterface::SetName(const String& name) -> void
{
	const ObserverObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ObserverObjectInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.ObserverObjectInterface_SetName_Offset), mt_.ObserverObjectInterface_SetName, name);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ObserverObjectInterface::ObserverDestroyed() const -> maxon::ObservableRef<ObserverDestroyedDelegate>
{
	const ObserverObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ObserverObjectInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.ObserverObjectInterface_ObserverDestroyed_Offset), mt_.ObserverObjectInterface_ObserverDestroyed);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ObserverObjectInterface::ObserverDisconnectNotify() const -> maxon::ObservableRef<ObserverDisconnectNotifyDelegate>
{
	const ObserverObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ObserverObjectInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.ObserverObjectInterface_ObserverDisconnectNotify_Offset), mt_.ObserverObjectInterface_ObserverDisconnectNotify);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ObserverObjectInterface::ObserverConnectNotify() const -> maxon::ObservableRef<ObserverConnectNotifyDelegate>
{
	const ObserverObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ObserverObjectInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.ObserverObjectInterface_ObserverConnectNotify_Offset), mt_.ObserverObjectInterface_ObserverConnectNotify);
}

/// @cond INTERNAL

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ObserverObjectInterface::Hxx1::Fn<S>::AddSenderSignal(ObservableBaseInterface* observable) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); ObserverObjectInterface* o_ = (ObserverObjectInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ObserverObjectInterface, o_, ObserverObjectInterface_AddSenderSignal) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ObserverObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ObserverObjectInterface>() : PRIVATE_MAXON_VTABLE(ObserverObjectInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ObserverObjectInterface_AddSenderSignal_Offset), mt_.ObserverObjectInterface_AddSenderSignal, observable));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ObserverObjectInterface::Hxx1::COWFn<S>::AddSenderSignal(ObservableBaseInterface* observable) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); ObserverObjectInterface* o_ = (ObserverObjectInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ObserverObjectInterface, o_, ObserverObjectInterface_AddSenderSignal) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ObserverObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ObserverObjectInterface>() : PRIVATE_MAXON_VTABLE(ObserverObjectInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ObserverObjectInterface_AddSenderSignal_Offset), mt_.ObserverObjectInterface_AddSenderSignal, observable));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ObserverObjectInterface::Hxx1::Fn<S>::RemoveSenderSignal(ObservableBaseInterface* observable) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); ObserverObjectInterface* o_ = (ObserverObjectInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { DebugStop(); return maxon::PrivateLogNullptrError(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ObserverObjectInterface, o_, ObserverObjectInterface_RemoveSenderSignal) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ObserverObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ObserverObjectInterface>() : PRIVATE_MAXON_VTABLE(ObserverObjectInterface, o_); 
	PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ObserverObjectInterface_RemoveSenderSignal_Offset), mt_.ObserverObjectInterface_RemoveSenderSignal, observable);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ObserverObjectInterface::Hxx1::COWFn<S>::RemoveSenderSignal(ObservableBaseInterface* observable) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); ObserverObjectInterface* o_ = (ObserverObjectInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ObserverObjectInterface, o_, ObserverObjectInterface_RemoveSenderSignal) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ObserverObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ObserverObjectInterface>() : PRIVATE_MAXON_VTABLE(ObserverObjectInterface, o_); 
	PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ObserverObjectInterface_RemoveSenderSignal_Offset), mt_.ObserverObjectInterface_RemoveSenderSignal, observable);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
/// @endcond

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ObserverObjectInterface::Hxx1::ConstFn<S>::GetName() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const ObserverObjectInterface* o_ = (const ObserverObjectInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = ObserverObjectInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ObserverObjectInterface, o_, ObserverObjectInterface_GetName) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ObserverObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ObserverObjectInterface>() : PRIVATE_MAXON_VTABLE(ObserverObjectInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.ObserverObjectInterface_GetName_Offset), mt_.ObserverObjectInterface_GetName));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ObserverObjectInterface::Hxx1::Fn<S>::SetName(const String& name) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); ObserverObjectInterface* o_ = (ObserverObjectInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { DebugStop(); return maxon::PrivateLogNullptrError(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ObserverObjectInterface, o_, ObserverObjectInterface_SetName) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ObserverObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ObserverObjectInterface>() : PRIVATE_MAXON_VTABLE(ObserverObjectInterface, o_); 
	PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ObserverObjectInterface_SetName_Offset), mt_.ObserverObjectInterface_SetName, name);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ObserverObjectInterface::Hxx1::COWFn<S>::SetName(const String& name) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); ObserverObjectInterface* o_ = (ObserverObjectInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ObserverObjectInterface, o_, ObserverObjectInterface_SetName) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ObserverObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ObserverObjectInterface>() : PRIVATE_MAXON_VTABLE(ObserverObjectInterface, o_); 
	PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ObserverObjectInterface_SetName_Offset), mt_.ObserverObjectInterface_SetName, name);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ObserverObjectInterface::Hxx1::ConstFn<S>::ObserverDestroyed() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<maxon::ObservableRef<ObserverDestroyedDelegate>>, maxon::ObservableRef<ObserverDestroyedDelegate>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<maxon::ObservableRef<ObserverDestroyedDelegate>>, maxon::ObservableRef<ObserverDestroyedDelegate>>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const ObserverObjectInterface* o_ = (const ObserverObjectInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = ObserverObjectInterface::NullValuePtr(); if (!o_) return maxon::ObservableRef<ObserverDestroyedDelegate>::NullValue(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ObserverObjectInterface, o_, ObserverObjectInterface_ObserverDestroyed) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ObserverObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ObserverObjectInterface>() : PRIVATE_MAXON_VTABLE(ObserverObjectInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.ObserverObjectInterface_ObserverDestroyed_Offset), mt_.ObserverObjectInterface_ObserverDestroyed));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ObserverObjectInterface::Hxx1::ConstFn<S>::ObserverDisconnectNotify() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<maxon::ObservableRef<ObserverDisconnectNotifyDelegate>>, maxon::ObservableRef<ObserverDisconnectNotifyDelegate>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<maxon::ObservableRef<ObserverDisconnectNotifyDelegate>>, maxon::ObservableRef<ObserverDisconnectNotifyDelegate>>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const ObserverObjectInterface* o_ = (const ObserverObjectInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = ObserverObjectInterface::NullValuePtr(); if (!o_) return maxon::ObservableRef<ObserverDisconnectNotifyDelegate>::NullValue(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ObserverObjectInterface, o_, ObserverObjectInterface_ObserverDisconnectNotify) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ObserverObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ObserverObjectInterface>() : PRIVATE_MAXON_VTABLE(ObserverObjectInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.ObserverObjectInterface_ObserverDisconnectNotify_Offset), mt_.ObserverObjectInterface_ObserverDisconnectNotify));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ObserverObjectInterface::Hxx1::ConstFn<S>::ObserverConnectNotify() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<maxon::ObservableRef<ObserverConnectNotifyDelegate>>, maxon::ObservableRef<ObserverConnectNotifyDelegate>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<maxon::ObservableRef<ObserverConnectNotifyDelegate>>, maxon::ObservableRef<ObserverConnectNotifyDelegate>>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const ObserverObjectInterface* o_ = (const ObserverObjectInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = ObserverObjectInterface::NullValuePtr(); if (!o_) return maxon::ObservableRef<ObserverConnectNotifyDelegate>::NullValue(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ObserverObjectInterface, o_, ObserverObjectInterface_ObserverConnectNotify) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ObserverObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ObserverObjectInterface>() : PRIVATE_MAXON_VTABLE(ObserverObjectInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.ObserverObjectInterface_ObserverConnectNotify_Offset), mt_.ObserverObjectInterface_ObserverConnectNotify));
}
auto ObserverObjectInterface::GetPtr() -> Ptr { return Ptr(this); }
auto ObserverObjectInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_observerobject)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_ObserverObjectInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_ObserverObjectInterface() { new (s_ui_maxon_ObserverObjectInterface) maxon::EntityUse(ObserverObjectInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/observerobject.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_ObserverObjectInterface(ObserverObjectInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/observerobject.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

