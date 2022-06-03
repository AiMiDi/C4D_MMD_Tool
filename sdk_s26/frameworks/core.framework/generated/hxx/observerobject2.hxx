
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

	Result<void> (*ObserverObjectInterface_AddSenderSignal) (maxon::GenericComponent* this_, ObservableBaseInterface* observable);
	maxon::Int ObserverObjectInterface_AddSenderSignal_Offset;
	void (*ObserverObjectInterface_RemoveSenderSignal) (maxon::GenericComponent* this_, ObservableBaseInterface* observable);
	maxon::Int ObserverObjectInterface_RemoveSenderSignal_Offset;
/// @endcond

	String (*ObserverObjectInterface_GetName) (const maxon::GenericComponent* this_);
	maxon::Int ObserverObjectInterface_GetName_Offset;
	void (*ObserverObjectInterface_SetName) (maxon::GenericComponent* this_, const String& name);
	maxon::Int ObserverObjectInterface_SetName_Offset;
	maxon::ObservableRef<ObserverDestroyedDelegate> (*ObserverObjectInterface_ObserverDestroyed) (const maxon::GenericComponent* this_);
	maxon::Int ObserverObjectInterface_ObserverDestroyed_Offset;
	maxon::ObservableRef<ObserverDisconnectNotifyDelegate> (*ObserverObjectInterface_ObserverDisconnectNotify) (const maxon::GenericComponent* this_);
	maxon::Int ObserverObjectInterface_ObserverDisconnectNotify_Offset;
	maxon::ObservableRef<ObserverConnectNotifyDelegate> (*ObserverObjectInterface_ObserverConnectNotify) (const maxon::GenericComponent* this_);
	maxon::Int ObserverObjectInterface_ObserverConnectNotify_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
/// @cond INTERNAL

	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ObserverObjectInterface, AddSenderSignal))
	{
		ObserverObjectInterface_AddSenderSignal = &W::ObserverObjectInterface_AddSenderSignal;
		ObserverObjectInterface_AddSenderSignal_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ObserverObjectInterface, RemoveSenderSignal))
	{
		ObserverObjectInterface_RemoveSenderSignal = &W::ObserverObjectInterface_RemoveSenderSignal;
		ObserverObjectInterface_RemoveSenderSignal_Offset = offset;
	}
/// @endcond

	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ObserverObjectInterface, GetName))
	{
		ObserverObjectInterface_GetName = &W::ObserverObjectInterface_GetName;
		ObserverObjectInterface_GetName_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ObserverObjectInterface, SetName))
	{
		ObserverObjectInterface_SetName = &W::ObserverObjectInterface_SetName;
		ObserverObjectInterface_SetName_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ObserverObjectInterface, ObserverDestroyed))
	{
		ObserverObjectInterface_ObserverDestroyed = &W::ObserverObjectInterface_ObserverDestroyed;
		ObserverObjectInterface_ObserverDestroyed_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ObserverObjectInterface, ObserverDisconnectNotify))
	{
		ObserverObjectInterface_ObserverDisconnectNotify = &W::ObserverObjectInterface_ObserverDisconnectNotify;
		ObserverObjectInterface_ObserverDisconnectNotify_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ObserverObjectInterface, ObserverConnectNotify))
	{
		ObserverObjectInterface_ObserverConnectNotify = &W::ObserverObjectInterface_ObserverConnectNotify;
		ObserverObjectInterface_ObserverConnectNotify_Offset = offset;
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
			if (!S::Implementation::PROXY && !(Super0::InitMTablesWithBases(info, offset))) return false;
			auto* vt = (ObserverObjectInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, ObserverObjectInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
/// @cond INTERNAL

		static Result<void> ObserverObjectInterface_AddSenderSignal(maxon::GenericComponent* this_, ObservableBaseInterface* observable) { return ((typename S::Implementation*) this_)->AddSenderSignal(observable); }
		static void ObserverObjectInterface_RemoveSenderSignal(maxon::GenericComponent* this_, ObservableBaseInterface* observable) { return ((typename S::Implementation*) this_)->RemoveSenderSignal(observable); }
/// @endcond

		static String ObserverObjectInterface_GetName(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetName(); }
		static void ObserverObjectInterface_SetName(maxon::GenericComponent* this_, const String& name) { return ((typename S::Implementation*) this_)->SetName(name); }
		static maxon::ObservableRef<ObserverDestroyedDelegate> ObserverObjectInterface_ObserverDestroyed(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->ObserverDestroyed(); }
		static maxon::ObservableRef<ObserverDisconnectNotifyDelegate> ObserverObjectInterface_ObserverDisconnectNotify(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->ObserverDisconnectNotify(); }
		static maxon::ObservableRef<ObserverConnectNotifyDelegate> ObserverObjectInterface_ObserverConnectNotify(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->ObserverConnectNotify(); }
	};

};
/// @cond INTERNAL

MAXON_ATTRIBUTE_FORCE_INLINE auto ObserverObjectInterface::AddSenderSignal(ObservableBaseInterface* observable) -> Result<void>
{
	const ObserverObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ObserverObjectInterface, this); return mt_.ObserverObjectInterface_AddSenderSignal((maxon::GenericComponent*) this + mt_.ObserverObjectInterface_AddSenderSignal_Offset, observable);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ObserverObjectInterface::RemoveSenderSignal(ObservableBaseInterface* observable) -> void
{
	const ObserverObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ObserverObjectInterface, this); return mt_.ObserverObjectInterface_RemoveSenderSignal((maxon::GenericComponent*) this + mt_.ObserverObjectInterface_RemoveSenderSignal_Offset, observable);
}
/// @endcond

MAXON_ATTRIBUTE_FORCE_INLINE auto ObserverObjectInterface::GetName() const -> String
{
	const ObserverObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ObserverObjectInterface, this); return mt_.ObserverObjectInterface_GetName((const maxon::GenericComponent*) this + mt_.ObserverObjectInterface_GetName_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ObserverObjectInterface::SetName(const String& name) -> void
{
	const ObserverObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ObserverObjectInterface, this); return mt_.ObserverObjectInterface_SetName((maxon::GenericComponent*) this + mt_.ObserverObjectInterface_SetName_Offset, name);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ObserverObjectInterface::ObserverDestroyed() const -> maxon::ObservableRef<ObserverDestroyedDelegate>
{
	const ObserverObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ObserverObjectInterface, this); return mt_.ObserverObjectInterface_ObserverDestroyed((const maxon::GenericComponent*) this + mt_.ObserverObjectInterface_ObserverDestroyed_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ObserverObjectInterface::ObserverDisconnectNotify() const -> maxon::ObservableRef<ObserverDisconnectNotifyDelegate>
{
	const ObserverObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ObserverObjectInterface, this); return mt_.ObserverObjectInterface_ObserverDisconnectNotify((const maxon::GenericComponent*) this + mt_.ObserverObjectInterface_ObserverDisconnectNotify_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ObserverObjectInterface::ObserverConnectNotify() const -> maxon::ObservableRef<ObserverConnectNotifyDelegate>
{
	const ObserverObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ObserverObjectInterface, this); return mt_.ObserverObjectInterface_ObserverConnectNotify((const maxon::GenericComponent*) this + mt_.ObserverObjectInterface_ObserverConnectNotify_Offset);
}

/// @cond INTERNAL

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ObserverObjectInterface::Hxx1::Fn<S>::AddSenderSignal(ObservableBaseInterface* observable) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ObserverObjectInterface* o_ = (ObserverObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ObserverObjectInterface, o_, ObserverObjectInterface_AddSenderSignal) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ObserverObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ObserverObjectInterface>() : PRIVATE_MAXON_VTABLE(ObserverObjectInterface, o_); 
	return (mt_.ObserverObjectInterface_AddSenderSignal(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ObserverObjectInterface_AddSenderSignal_Offset, observable));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ObserverObjectInterface::Hxx1::COWFn<S>::AddSenderSignal(ObservableBaseInterface* observable) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ObserverObjectInterface* o_ = (ObserverObjectInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ObserverObjectInterface, o_, ObserverObjectInterface_AddSenderSignal) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ObserverObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ObserverObjectInterface>() : PRIVATE_MAXON_VTABLE(ObserverObjectInterface, o_); 
	return (mt_.ObserverObjectInterface_AddSenderSignal(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ObserverObjectInterface_AddSenderSignal_Offset, observable));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ObserverObjectInterface::Hxx1::Fn<S>::RemoveSenderSignal(ObservableBaseInterface* observable) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ObserverObjectInterface* o_ = (ObserverObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { DebugStop(); return maxon::PrivateLogNullptrError(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ObserverObjectInterface, o_, ObserverObjectInterface_RemoveSenderSignal) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ObserverObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ObserverObjectInterface>() : PRIVATE_MAXON_VTABLE(ObserverObjectInterface, o_); 
	mt_.ObserverObjectInterface_RemoveSenderSignal(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ObserverObjectInterface_RemoveSenderSignal_Offset, observable);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ObserverObjectInterface::Hxx1::COWFn<S>::RemoveSenderSignal(ObservableBaseInterface* observable) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ObserverObjectInterface* o_ = (ObserverObjectInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ObserverObjectInterface, o_, ObserverObjectInterface_RemoveSenderSignal) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ObserverObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ObserverObjectInterface>() : PRIVATE_MAXON_VTABLE(ObserverObjectInterface, o_); 
	mt_.ObserverObjectInterface_RemoveSenderSignal(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ObserverObjectInterface_RemoveSenderSignal_Offset, observable);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
/// @endcond

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ObserverObjectInterface::Hxx1::ConstFn<S>::GetName() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ObserverObjectInterface* o_ = (const ObserverObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ObserverObjectInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ObserverObjectInterface, o_, ObserverObjectInterface_GetName) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ObserverObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ObserverObjectInterface>() : PRIVATE_MAXON_VTABLE(ObserverObjectInterface, o_); 
	return (mt_.ObserverObjectInterface_GetName(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.ObserverObjectInterface_GetName_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ObserverObjectInterface::Hxx1::Fn<S>::SetName(const String& name) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ObserverObjectInterface* o_ = (ObserverObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { DebugStop(); return maxon::PrivateLogNullptrError(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ObserverObjectInterface, o_, ObserverObjectInterface_SetName) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ObserverObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ObserverObjectInterface>() : PRIVATE_MAXON_VTABLE(ObserverObjectInterface, o_); 
	mt_.ObserverObjectInterface_SetName(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ObserverObjectInterface_SetName_Offset, name);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ObserverObjectInterface::Hxx1::COWFn<S>::SetName(const String& name) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ObserverObjectInterface* o_ = (ObserverObjectInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ObserverObjectInterface, o_, ObserverObjectInterface_SetName) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ObserverObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ObserverObjectInterface>() : PRIVATE_MAXON_VTABLE(ObserverObjectInterface, o_); 
	mt_.ObserverObjectInterface_SetName(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ObserverObjectInterface_SetName_Offset, name);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ObserverObjectInterface::Hxx1::ConstFn<S>::ObserverDestroyed() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<maxon::ObservableRef<ObserverDestroyedDelegate>>, maxon::ObservableRef<ObserverDestroyedDelegate>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<maxon::ObservableRef<ObserverDestroyedDelegate>>, maxon::ObservableRef<ObserverDestroyedDelegate>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ObserverObjectInterface* o_ = (const ObserverObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ObserverObjectInterface::NullValuePtr(); if (!o_) return maxon::ObservableRef<ObserverDestroyedDelegate>::NullValue(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ObserverObjectInterface, o_, ObserverObjectInterface_ObserverDestroyed) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ObserverObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ObserverObjectInterface>() : PRIVATE_MAXON_VTABLE(ObserverObjectInterface, o_); 
	return (mt_.ObserverObjectInterface_ObserverDestroyed(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.ObserverObjectInterface_ObserverDestroyed_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ObserverObjectInterface::Hxx1::ConstFn<S>::ObserverDisconnectNotify() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<maxon::ObservableRef<ObserverDisconnectNotifyDelegate>>, maxon::ObservableRef<ObserverDisconnectNotifyDelegate>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<maxon::ObservableRef<ObserverDisconnectNotifyDelegate>>, maxon::ObservableRef<ObserverDisconnectNotifyDelegate>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ObserverObjectInterface* o_ = (const ObserverObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ObserverObjectInterface::NullValuePtr(); if (!o_) return maxon::ObservableRef<ObserverDisconnectNotifyDelegate>::NullValue(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ObserverObjectInterface, o_, ObserverObjectInterface_ObserverDisconnectNotify) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ObserverObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ObserverObjectInterface>() : PRIVATE_MAXON_VTABLE(ObserverObjectInterface, o_); 
	return (mt_.ObserverObjectInterface_ObserverDisconnectNotify(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.ObserverObjectInterface_ObserverDisconnectNotify_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ObserverObjectInterface::Hxx1::ConstFn<S>::ObserverConnectNotify() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<maxon::ObservableRef<ObserverConnectNotifyDelegate>>, maxon::ObservableRef<ObserverConnectNotifyDelegate>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<maxon::ObservableRef<ObserverConnectNotifyDelegate>>, maxon::ObservableRef<ObserverConnectNotifyDelegate>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ObserverObjectInterface* o_ = (const ObserverObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ObserverObjectInterface::NullValuePtr(); if (!o_) return maxon::ObservableRef<ObserverConnectNotifyDelegate>::NullValue(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ObserverObjectInterface, o_, ObserverObjectInterface_ObserverConnectNotify) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ObserverObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ObserverObjectInterface>() : PRIVATE_MAXON_VTABLE(ObserverObjectInterface, o_); 
	return (mt_.ObserverObjectInterface_ObserverConnectNotify(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.ObserverObjectInterface_ObserverConnectNotify_Offset));
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

