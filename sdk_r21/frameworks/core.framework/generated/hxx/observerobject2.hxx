
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
	static const maxon::Bool HAS_NONSTATIC = false;
/// @cond INTERNAL

	Result<void> (*_ObserverObjectInterface_AddSenderSignal) (maxon::GenericComponent* this_, ObservableBaseInterface* observable);
	maxon::Int _ObserverObjectInterface_AddSenderSignal_Offset;
	void (*_ObserverObjectInterface_RemoveSenderSignal) (maxon::GenericComponent* this_, ObservableBaseInterface* observable);
	maxon::Int _ObserverObjectInterface_RemoveSenderSignal_Offset;
/// @endcond

	String (*_ObserverObjectInterface_GetName) (const maxon::GenericComponent* this_);
	maxon::Int _ObserverObjectInterface_GetName_Offset;
	void (*_ObserverObjectInterface_SetName) (maxon::GenericComponent* this_, const String& name);
	maxon::Int _ObserverObjectInterface_SetName_Offset;
	maxon::ObservableRef<ObserverDestroyedDelegate> (*_ObserverObjectInterface_ObserverDestroyed) (const maxon::GenericComponent* this_);
	maxon::Int _ObserverObjectInterface_ObserverDestroyed_Offset;
	maxon::ObservableRef<ObserverDisconnectNotifyDelegate> (*_ObserverObjectInterface_ObserverDisconnectNotify) (const maxon::GenericComponent* this_);
	maxon::Int _ObserverObjectInterface_ObserverDisconnectNotify_Offset;
	maxon::ObservableRef<ObserverConnectNotifyDelegate> (*_ObserverObjectInterface_ObserverConnectNotify) (const maxon::GenericComponent* this_);
	maxon::Int _ObserverObjectInterface_ObserverConnectNotify_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
/// @cond INTERNAL

		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ObserverObjectInterface, AddSenderSignal))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ObserverObjectInterface, AddSenderSignal), W, MTable>::type::_ObserverObjectInterface_AddSenderSignal;
			_ObserverObjectInterface_AddSenderSignal = reinterpret_cast<const decltype(_ObserverObjectInterface_AddSenderSignal)&>(ptr);
			_ObserverObjectInterface_AddSenderSignal_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ObserverObjectInterface, RemoveSenderSignal))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ObserverObjectInterface, RemoveSenderSignal), W, MTable>::type::_ObserverObjectInterface_RemoveSenderSignal;
			_ObserverObjectInterface_RemoveSenderSignal = reinterpret_cast<const decltype(_ObserverObjectInterface_RemoveSenderSignal)&>(ptr);
			_ObserverObjectInterface_RemoveSenderSignal_Offset = offset;
		}
/// @endcond

		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ObserverObjectInterface, GetName))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ObserverObjectInterface, GetName), W, MTable>::type::_ObserverObjectInterface_GetName;
			_ObserverObjectInterface_GetName = reinterpret_cast<const decltype(_ObserverObjectInterface_GetName)&>(ptr);
			_ObserverObjectInterface_GetName_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ObserverObjectInterface, SetName))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ObserverObjectInterface, SetName), W, MTable>::type::_ObserverObjectInterface_SetName;
			_ObserverObjectInterface_SetName = reinterpret_cast<const decltype(_ObserverObjectInterface_SetName)&>(ptr);
			_ObserverObjectInterface_SetName_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ObserverObjectInterface, ObserverDestroyed))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ObserverObjectInterface, ObserverDestroyed), W, MTable>::type::_ObserverObjectInterface_ObserverDestroyed;
			_ObserverObjectInterface_ObserverDestroyed = reinterpret_cast<const decltype(_ObserverObjectInterface_ObserverDestroyed)&>(ptr);
			_ObserverObjectInterface_ObserverDestroyed_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ObserverObjectInterface, ObserverDisconnectNotify))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ObserverObjectInterface, ObserverDisconnectNotify), W, MTable>::type::_ObserverObjectInterface_ObserverDisconnectNotify;
			_ObserverObjectInterface_ObserverDisconnectNotify = reinterpret_cast<const decltype(_ObserverObjectInterface_ObserverDisconnectNotify)&>(ptr);
			_ObserverObjectInterface_ObserverDisconnectNotify_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ObserverObjectInterface, ObserverConnectNotify))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ObserverObjectInterface, ObserverConnectNotify), W, MTable>::type::_ObserverObjectInterface_ObserverConnectNotify;
			_ObserverObjectInterface_ObserverConnectNotify = reinterpret_cast<const decltype(_ObserverObjectInterface_ObserverConnectNotify)&>(ptr);
			_ObserverObjectInterface_ObserverConnectNotify_Offset = offset;
		}
	}
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset)
	{
		if (!W::Implementation::PROXY && (!ObjectInterface::MTable::template InitWithBases<W>(info, offset))) return false;
		MTable* vt = (MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, _interface); if (!vt) return false;
		vt->Init<W>(offset); return true;
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<ObserverObjectInterface, typename ObjectInterface::MTable::template CombinedMTable<S>>;
	PRIVATE_MAXON_COMPBASE(ObserverObjectInterface);
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct ObserverObjectInterface::Hxx2
{
	template <typename S> class Wrapper : public ObjectInterface::Hxx2::template Wrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(AddSenderSignal);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetName);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(ObserverConnectNotify);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(ObserverDestroyed);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(ObserverDisconnectNotify);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(RemoveSenderSignal);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(SetName);
/// @cond INTERNAL

	static Result<void> _ObserverObjectInterface_AddSenderSignal(maxon::GenericComponent* this_, ObservableBaseInterface* observable) { return ((typename S::Implementation*) this_)->AddSenderSignal(observable); }
	static void _ObserverObjectInterface_RemoveSenderSignal(maxon::GenericComponent* this_, ObservableBaseInterface* observable) { return ((typename S::Implementation*) this_)->RemoveSenderSignal(observable); }
/// @endcond

	static String _ObserverObjectInterface_GetName(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetName(); }
	static void _ObserverObjectInterface_SetName(maxon::GenericComponent* this_, const String& name) { return ((typename S::Implementation*) this_)->SetName(name); }
	static maxon::ObservableRef<ObserverDestroyedDelegate> _ObserverObjectInterface_ObserverDestroyed(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->ObserverDestroyed(); }
	static maxon::ObservableRef<ObserverDisconnectNotifyDelegate> _ObserverObjectInterface_ObserverDisconnectNotify(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->ObserverDisconnectNotify(); }
	static maxon::ObservableRef<ObserverConnectNotifyDelegate> _ObserverObjectInterface_ObserverConnectNotify(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->ObserverConnectNotify(); }
	};

};
/// @cond INTERNAL

MAXON_ATTRIBUTE_FORCE_INLINE auto ObserverObjectInterface::AddSenderSignal(ObservableBaseInterface* observable) -> Result<void>
{
	const ObserverObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ObserverObjectInterface, this); return mt_._ObserverObjectInterface_AddSenderSignal((maxon::GenericComponent*) this + mt_._ObserverObjectInterface_AddSenderSignal_Offset, observable);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ObserverObjectInterface::RemoveSenderSignal(ObservableBaseInterface* observable) -> void
{
	const ObserverObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ObserverObjectInterface, this); return mt_._ObserverObjectInterface_RemoveSenderSignal((maxon::GenericComponent*) this + mt_._ObserverObjectInterface_RemoveSenderSignal_Offset, observable);
}
/// @endcond

MAXON_ATTRIBUTE_FORCE_INLINE auto ObserverObjectInterface::GetName() const -> String
{
	const ObserverObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ObserverObjectInterface, this); return mt_._ObserverObjectInterface_GetName((const maxon::GenericComponent*) this + mt_._ObserverObjectInterface_GetName_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ObserverObjectInterface::SetName(const String& name) -> void
{
	const ObserverObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ObserverObjectInterface, this); return mt_._ObserverObjectInterface_SetName((maxon::GenericComponent*) this + mt_._ObserverObjectInterface_SetName_Offset, name);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ObserverObjectInterface::ObserverDestroyed() const -> maxon::ObservableRef<ObserverDestroyedDelegate>
{
	const ObserverObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ObserverObjectInterface, this); return mt_._ObserverObjectInterface_ObserverDestroyed((const maxon::GenericComponent*) this + mt_._ObserverObjectInterface_ObserverDestroyed_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ObserverObjectInterface::ObserverDisconnectNotify() const -> maxon::ObservableRef<ObserverDisconnectNotifyDelegate>
{
	const ObserverObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ObserverObjectInterface, this); return mt_._ObserverObjectInterface_ObserverDisconnectNotify((const maxon::GenericComponent*) this + mt_._ObserverObjectInterface_ObserverDisconnectNotify_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ObserverObjectInterface::ObserverConnectNotify() const -> maxon::ObservableRef<ObserverConnectNotifyDelegate>
{
	const ObserverObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ObserverObjectInterface, this); return mt_._ObserverObjectInterface_ObserverConnectNotify((const maxon::GenericComponent*) this + mt_._ObserverObjectInterface_ObserverConnectNotify_Offset);
}

/// @cond INTERNAL

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ObserverObjectInterface::Hxx1::ReferenceFunctionsImpl<S>::AddSenderSignal(ObservableBaseInterface* observable) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ObserverObjectInterface* o_ = (ObserverObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ObserverObjectInterface, o_, ObserverObjectInterface_AddSenderSignal) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<ObserverObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ObserverObjectInterface>() : PRIVATE_MAXON_VTABLE(ObserverObjectInterface, o_); 
	return (mt_._ObserverObjectInterface_AddSenderSignal(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._ObserverObjectInterface_AddSenderSignal_Offset, observable));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ObserverObjectInterface::Hxx1::COWReferenceFunctionsImpl<S>::AddSenderSignal(ObservableBaseInterface* observable) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ObserverObjectInterface* o_ = (ObserverObjectInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ObserverObjectInterface, o_, ObserverObjectInterface_AddSenderSignal) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<ObserverObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ObserverObjectInterface>() : PRIVATE_MAXON_VTABLE(ObserverObjectInterface, o_); 
	return (mt_._ObserverObjectInterface_AddSenderSignal(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._ObserverObjectInterface_AddSenderSignal_Offset, observable));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ObserverObjectInterface::Hxx1::ReferenceFunctionsImpl<S>::RemoveSenderSignal(ObservableBaseInterface* observable) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ObserverObjectInterface* o_ = (ObserverObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateLogNullptrError(); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ObserverObjectInterface, o_, ObserverObjectInterface_RemoveSenderSignal) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<ObserverObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ObserverObjectInterface>() : PRIVATE_MAXON_VTABLE(ObserverObjectInterface, o_); 
	mt_._ObserverObjectInterface_RemoveSenderSignal(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._ObserverObjectInterface_RemoveSenderSignal_Offset, observable);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ObserverObjectInterface::Hxx1::COWReferenceFunctionsImpl<S>::RemoveSenderSignal(ObservableBaseInterface* observable) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ObserverObjectInterface* o_ = (ObserverObjectInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ObserverObjectInterface, o_, ObserverObjectInterface_RemoveSenderSignal) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<ObserverObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ObserverObjectInterface>() : PRIVATE_MAXON_VTABLE(ObserverObjectInterface, o_); 
	mt_._ObserverObjectInterface_RemoveSenderSignal(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._ObserverObjectInterface_RemoveSenderSignal_Offset, observable);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
/// @endcond

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ObserverObjectInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetName() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ObserverObjectInterface* o_ = (const ObserverObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ObserverObjectInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ObserverObjectInterface, o_, ObserverObjectInterface_GetName) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<ObserverObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ObserverObjectInterface>() : PRIVATE_MAXON_VTABLE(ObserverObjectInterface, o_); 
	return (mt_._ObserverObjectInterface_GetName(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._ObserverObjectInterface_GetName_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ObserverObjectInterface::Hxx1::ReferenceFunctionsImpl<S>::SetName(const String& name) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ObserverObjectInterface* o_ = (ObserverObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateLogNullptrError(); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ObserverObjectInterface, o_, ObserverObjectInterface_SetName) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<ObserverObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ObserverObjectInterface>() : PRIVATE_MAXON_VTABLE(ObserverObjectInterface, o_); 
	mt_._ObserverObjectInterface_SetName(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._ObserverObjectInterface_SetName_Offset, name);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ObserverObjectInterface::Hxx1::COWReferenceFunctionsImpl<S>::SetName(const String& name) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ObserverObjectInterface* o_ = (ObserverObjectInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ObserverObjectInterface, o_, ObserverObjectInterface_SetName) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<ObserverObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ObserverObjectInterface>() : PRIVATE_MAXON_VTABLE(ObserverObjectInterface, o_); 
	mt_._ObserverObjectInterface_SetName(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._ObserverObjectInterface_SetName_Offset, name);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ObserverObjectInterface::Hxx1::ConstReferenceFunctionsImpl<S>::ObserverDestroyed() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<maxon::ObservableRef<ObserverDestroyedDelegate>>, maxon::ObservableRef<ObserverDestroyedDelegate>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<maxon::ObservableRef<ObserverDestroyedDelegate>>, maxon::ObservableRef<ObserverDestroyedDelegate>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ObserverObjectInterface* o_ = (const ObserverObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ObserverObjectInterface::NullValuePtr(); if (!o_) return maxon::ObservableRef<ObserverDestroyedDelegate>::NullValue(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ObserverObjectInterface, o_, ObserverObjectInterface_ObserverDestroyed) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<ObserverObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ObserverObjectInterface>() : PRIVATE_MAXON_VTABLE(ObserverObjectInterface, o_); 
	return (mt_._ObserverObjectInterface_ObserverDestroyed(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._ObserverObjectInterface_ObserverDestroyed_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ObserverObjectInterface::Hxx1::ConstReferenceFunctionsImpl<S>::ObserverDisconnectNotify() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<maxon::ObservableRef<ObserverDisconnectNotifyDelegate>>, maxon::ObservableRef<ObserverDisconnectNotifyDelegate>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<maxon::ObservableRef<ObserverDisconnectNotifyDelegate>>, maxon::ObservableRef<ObserverDisconnectNotifyDelegate>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ObserverObjectInterface* o_ = (const ObserverObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ObserverObjectInterface::NullValuePtr(); if (!o_) return maxon::ObservableRef<ObserverDisconnectNotifyDelegate>::NullValue(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ObserverObjectInterface, o_, ObserverObjectInterface_ObserverDisconnectNotify) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<ObserverObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ObserverObjectInterface>() : PRIVATE_MAXON_VTABLE(ObserverObjectInterface, o_); 
	return (mt_._ObserverObjectInterface_ObserverDisconnectNotify(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._ObserverObjectInterface_ObserverDisconnectNotify_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ObserverObjectInterface::Hxx1::ConstReferenceFunctionsImpl<S>::ObserverConnectNotify() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<maxon::ObservableRef<ObserverConnectNotifyDelegate>>, maxon::ObservableRef<ObserverConnectNotifyDelegate>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<maxon::ObservableRef<ObserverConnectNotifyDelegate>>, maxon::ObservableRef<ObserverConnectNotifyDelegate>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ObserverObjectInterface* o_ = (const ObserverObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ObserverObjectInterface::NullValuePtr(); if (!o_) return maxon::ObservableRef<ObserverConnectNotifyDelegate>::NullValue(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ObserverObjectInterface, o_, ObserverObjectInterface_ObserverConnectNotify) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<ObserverObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ObserverObjectInterface>() : PRIVATE_MAXON_VTABLE(ObserverObjectInterface, o_); 
	return (mt_._ObserverObjectInterface_ObserverConnectNotify(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._ObserverObjectInterface_ObserverConnectNotify_Offset));
}
auto ObserverObjectInterface::GetPtr() -> Ptr { return Ptr(this); }
auto ObserverObjectInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
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

