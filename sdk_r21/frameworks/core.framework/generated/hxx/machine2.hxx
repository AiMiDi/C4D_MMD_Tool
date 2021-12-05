
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1

struct MachineInterface::MTable
{
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetInterface);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetMachineInfo);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetState);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetUniqueId);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(ObservableMessageReceived);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(SetState);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(ToString);
	static const maxon::Char* const _ids;
	static const maxon::Bool HAS_NONSTATIC = false;
	String (*_MachineInterface_GetUniqueId) (const maxon::GenericComponent* this_);
	maxon::Int _MachineInterface_GetUniqueId_Offset;
	Result<DataDictionary> (*_MachineInterface_GetMachineInfo) (const maxon::GenericComponent* this_);
	maxon::Int _MachineInterface_GetMachineInfo_Offset;
	Result<ObjectRef> (*_MachineInterface_GetInterface) (maxon::GenericComponent* this_, const Id& interfaceName);
	maxon::Int _MachineInterface_GetInterface_Offset;
	MACHINESTATE (*_MachineInterface_GetState) (const maxon::GenericComponent* this_);
	maxon::Int _MachineInterface_GetState_Offset;
	Bool (*_MachineInterface_SetState) (maxon::GenericComponent* this_, MACHINESTATE stateMask, MACHINESTATE stateFlags);
	maxon::Int _MachineInterface_SetState_Offset;
	String (*_MachineInterface_ToString) (const maxon::GenericComponent* this_, const FormatStatement* formatStatement);
	maxon::Int _MachineInterface_ToString_Offset;
	maxon::ObservableRef<ObservableMessageReceivedDelegate> (*_MachineInterface_ObservableMessageReceived) (const maxon::GenericComponent* this_);
	maxon::Int _MachineInterface_ObservableMessageReceived_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MachineInterface, GetUniqueId))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MachineInterface, GetUniqueId), W, MTable>::type::_MachineInterface_GetUniqueId;
			_MachineInterface_GetUniqueId = reinterpret_cast<const decltype(_MachineInterface_GetUniqueId)&>(ptr);
			_MachineInterface_GetUniqueId_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MachineInterface, GetMachineInfo))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MachineInterface, GetMachineInfo), W, MTable>::type::_MachineInterface_GetMachineInfo;
			_MachineInterface_GetMachineInfo = reinterpret_cast<const decltype(_MachineInterface_GetMachineInfo)&>(ptr);
			_MachineInterface_GetMachineInfo_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MachineInterface, GetInterface))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MachineInterface, GetInterface), W, MTable>::type::_MachineInterface_GetInterface;
			_MachineInterface_GetInterface = reinterpret_cast<const decltype(_MachineInterface_GetInterface)&>(ptr);
			_MachineInterface_GetInterface_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MachineInterface, GetState))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MachineInterface, GetState), W, MTable>::type::_MachineInterface_GetState;
			_MachineInterface_GetState = reinterpret_cast<const decltype(_MachineInterface_GetState)&>(ptr);
			_MachineInterface_GetState_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MachineInterface, SetState))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MachineInterface, SetState), W, MTable>::type::_MachineInterface_SetState;
			_MachineInterface_SetState = reinterpret_cast<const decltype(_MachineInterface_SetState)&>(ptr);
			_MachineInterface_SetState_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MachineInterface, ToString))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MachineInterface, ToString), W, MTable>::type::_MachineInterface_ToString;
			_MachineInterface_ToString = reinterpret_cast<const decltype(_MachineInterface_ToString)&>(ptr);
			_MachineInterface_ToString_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MachineInterface, ObservableMessageReceived))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MachineInterface, ObservableMessageReceived), W, MTable>::type::_MachineInterface_ObservableMessageReceived;
			_MachineInterface_ObservableMessageReceived = reinterpret_cast<const decltype(_MachineInterface_ObservableMessageReceived)&>(ptr);
			_MachineInterface_ObservableMessageReceived_Offset = offset;
		}
	}
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset)
	{
		if (!W::Implementation::PROXY && (!ObserverObjectInterface::MTable::template InitWithBases<W>(info, offset))) return false;
		MTable* vt = (MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, _interface); if (!vt) return false;
		vt->Init<W>(offset); return true;
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<MachineInterface, typename ObserverObjectInterface::MTable::template CombinedMTable<S>>;
	PRIVATE_MAXON_COMPBASE(MachineInterface);
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct MachineInterface::Hxx2
{
	template <typename S> class Wrapper : public ObserverObjectInterface::Hxx2::template Wrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetInterface);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetMachineInfo);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetState);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetUniqueId);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(ObservableMessageReceived);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(SetState);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(ToString);
	static String _MachineInterface_GetUniqueId(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetUniqueId(); }
	static Result<DataDictionary> _MachineInterface_GetMachineInfo(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetMachineInfo(); }
	static Result<ObjectRef> _MachineInterface_GetInterface(maxon::GenericComponent* this_, const Id& interfaceName) { return ((typename S::Implementation*) this_)->GetInterface(interfaceName); }
	static MACHINESTATE _MachineInterface_GetState(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetState(); }
	static Bool _MachineInterface_SetState(maxon::GenericComponent* this_, MACHINESTATE stateMask, MACHINESTATE stateFlags) { return ((typename S::Implementation*) this_)->SetState(stateMask, stateFlags); }
	static String _MachineInterface_ToString(const maxon::GenericComponent* this_, const FormatStatement* formatStatement) { return ((const typename S::Implementation*) this_)->ToString(formatStatement); }
	static maxon::ObservableRef<ObservableMessageReceivedDelegate> _MachineInterface_ObservableMessageReceived(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->ObservableMessageReceived(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto MachineInterface::GetUniqueId() const -> String
{
	const MachineInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MachineInterface, this); return mt_._MachineInterface_GetUniqueId((const maxon::GenericComponent*) this + mt_._MachineInterface_GetUniqueId_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MachineInterface::GetMachineInfo() const -> Result<DataDictionary>
{
	const MachineInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MachineInterface, this); return mt_._MachineInterface_GetMachineInfo((const maxon::GenericComponent*) this + mt_._MachineInterface_GetMachineInfo_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MachineInterface::GetInterface(const Id& interfaceName) -> Result<ObjectRef>
{
	const MachineInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MachineInterface, this); return mt_._MachineInterface_GetInterface((maxon::GenericComponent*) this + mt_._MachineInterface_GetInterface_Offset, interfaceName);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MachineInterface::GetState() const -> MACHINESTATE
{
	const MachineInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MachineInterface, this); return mt_._MachineInterface_GetState((const maxon::GenericComponent*) this + mt_._MachineInterface_GetState_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MachineInterface::SetState(MACHINESTATE stateMask, MACHINESTATE stateFlags) -> Bool
{
	const MachineInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MachineInterface, this); return mt_._MachineInterface_SetState((maxon::GenericComponent*) this + mt_._MachineInterface_SetState_Offset, stateMask, stateFlags);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MachineInterface::ToString(const FormatStatement* formatStatement) const -> String
{
	const MachineInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MachineInterface, this); return mt_._MachineInterface_ToString((const maxon::GenericComponent*) this + mt_._MachineInterface_ToString_Offset, formatStatement);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MachineInterface::ObservableMessageReceived() const -> maxon::ObservableRef<ObservableMessageReceivedDelegate>
{
	const MachineInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MachineInterface, this); return mt_._MachineInterface_ObservableMessageReceived((const maxon::GenericComponent*) this + mt_._MachineInterface_ObservableMessageReceived_Offset);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MachineInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetUniqueId() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const MachineInterface* o_ = (const MachineInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = MachineInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MachineInterface, o_, MachineInterface_GetUniqueId) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<MachineInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MachineInterface>() : PRIVATE_MAXON_VTABLE(MachineInterface, o_); 
	return (mt_._MachineInterface_GetUniqueId(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._MachineInterface_GetUniqueId_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MachineInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetMachineInfo() const -> Result<DataDictionary>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<DataDictionary>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const MachineInterface* o_ = (const MachineInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = MachineInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MachineInterface, o_, MachineInterface_GetMachineInfo) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<MachineInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MachineInterface>() : PRIVATE_MAXON_VTABLE(MachineInterface, o_); 
	return (mt_._MachineInterface_GetMachineInfo(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._MachineInterface_GetMachineInfo_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MachineInterface::Hxx1::ReferenceFunctionsImpl<S>::GetInterface(const Id& interfaceName) const -> Result<ObjectRef>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<ObjectRef>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); MachineInterface* o_ = (MachineInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MachineInterface, o_, MachineInterface_GetInterface) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<MachineInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MachineInterface>() : PRIVATE_MAXON_VTABLE(MachineInterface, o_); 
	return (mt_._MachineInterface_GetInterface(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._MachineInterface_GetInterface_Offset, interfaceName));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MachineInterface::Hxx1::COWReferenceFunctionsImpl<S>::GetInterface(const Id& interfaceName) -> Result<ObjectRef>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<ObjectRef>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); MachineInterface* o_ = (MachineInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MachineInterface, o_, MachineInterface_GetInterface) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<MachineInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MachineInterface>() : PRIVATE_MAXON_VTABLE(MachineInterface, o_); 
	return (mt_._MachineInterface_GetInterface(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._MachineInterface_GetInterface_Offset, interfaceName));
}
template <typename S> template <typename INTERFACE> MAXON_ATTRIBUTE_FORCE_INLINE auto MachineInterface::Hxx1::ReferenceFunctionsImpl<S>::GetInterface() const -> Result<INTERFACE>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<INTERFACE>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); MachineInterface* o_ = (MachineInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); 
	return (o_->GetInterface<INTERFACE>());
}
template <typename S> template <typename INTERFACE> MAXON_ATTRIBUTE_FORCE_INLINE auto MachineInterface::Hxx1::COWReferenceFunctionsImpl<S>::GetInterface() -> Result<INTERFACE>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<INTERFACE>>; static_assert(!std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value, "Can't invoke MAXON_FUNCTION MachineInterface::GetInterface on super."); if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); MachineInterface* o_ = (MachineInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	return (o_->GetInterface<INTERFACE>());
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MachineInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetState() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<MACHINESTATE>, MACHINESTATE>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<MACHINESTATE>, MACHINESTATE>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const MachineInterface* o_ = (const MachineInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = MachineInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<MACHINESTATE>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MachineInterface, o_, MachineInterface_GetState) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<MachineInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MachineInterface>() : PRIVATE_MAXON_VTABLE(MachineInterface, o_); 
	return (mt_._MachineInterface_GetState(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._MachineInterface_GetState_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MachineInterface::Hxx1::ReferenceFunctionsImpl<S>::SetState(MACHINESTATE stateMask, MACHINESTATE stateFlags) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); MachineInterface* o_ = (MachineInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateLogNullptrError(false); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MachineInterface, o_, MachineInterface_SetState) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<MachineInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MachineInterface>() : PRIVATE_MAXON_VTABLE(MachineInterface, o_); 
	return (mt_._MachineInterface_SetState(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._MachineInterface_SetState_Offset, stateMask, stateFlags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MachineInterface::Hxx1::COWReferenceFunctionsImpl<S>::SetState(MACHINESTATE stateMask, MACHINESTATE stateFlags) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Bool, maxon::Result<Bool>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Bool, maxon::Result<Bool>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); MachineInterface* o_ = (MachineInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MachineInterface, o_, MachineInterface_SetState) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<MachineInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MachineInterface>() : PRIVATE_MAXON_VTABLE(MachineInterface, o_); 
	return (mt_._MachineInterface_SetState(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._MachineInterface_SetState_Offset, stateMask, stateFlags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MachineInterface::Hxx1::ConstReferenceFunctionsImpl<S>::ToString(const FormatStatement* formatStatement) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const MachineInterface* o_ = (const MachineInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = MachineInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MachineInterface, o_, MachineInterface_ToString) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<MachineInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MachineInterface>() : PRIVATE_MAXON_VTABLE(MachineInterface, o_); 
	return (mt_._MachineInterface_ToString(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._MachineInterface_ToString_Offset, formatStatement));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MachineInterface::Hxx1::ConstReferenceFunctionsImpl<S>::ObservableMessageReceived() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<maxon::ObservableRef<ObservableMessageReceivedDelegate>>, maxon::ObservableRef<ObservableMessageReceivedDelegate>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<maxon::ObservableRef<ObservableMessageReceivedDelegate>>, maxon::ObservableRef<ObservableMessageReceivedDelegate>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const MachineInterface* o_ = (const MachineInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = MachineInterface::NullValuePtr(); if (!o_) return maxon::ObservableRef<ObservableMessageReceivedDelegate>::NullValue(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MachineInterface, o_, MachineInterface_ObservableMessageReceived) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<MachineInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MachineInterface>() : PRIVATE_MAXON_VTABLE(MachineInterface, o_); 
	return (mt_._MachineInterface_ObservableMessageReceived(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._MachineInterface_ObservableMessageReceived_Offset));
}
auto MachineInterface::GetPtr() -> Ptr { return Ptr(this); }
auto MachineInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_MachineInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_MachineInterface() { new (s_ui_maxon_MachineInterface) maxon::EntityUse(MachineInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/machine.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_MachineInterface(MachineInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/machine.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
/// @cond INTERNAL

/// @endcond

/// @cond INTERNAL

/// @endcond

/// @cond INTERNAL

/// @endcond


struct MachinesInterface::MTable
{
	static MTable _instance;
	static MTable _unresolvedInstance;
	static const maxon::Char* const _ids;
	static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl);
	static const maxon::NULL_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = false;
	MachineRef (*_MachinesInterface_GetLocal) ();
	Result<void> (*_MachinesInterface_GetRPCMachines) (WritableArrayInterface<MachineRef>& machines);
/// @cond INTERNAL

/// @endcond

	Result<MachineRef> (*_MachinesInterface_FindRPCMachine) (const String& machineUuid);
/// @cond INTERNAL

/// @endcond

	Result<MachineRef> (*_MachinesInterface_FindOrAddRPCMachine) (const String& machineUuid, MACHINESTATE state, const CreateNewMachineCallback& newMachineCallback, const CheckExistingMachineCallback& existingCallback);
/// @cond INTERNAL

/// @endcond

	Result<void> (*_MachinesInterface_RemoveRPCMachine) (const MachineRef& machine);
	maxon::ObservableRef<ObservableMachineStateChangedDelegate> (*_MachinesInterface_ObservableMachineStateChanged) ();
	template <typename IMPL> void Init()
	{
		_MachinesInterface_GetLocal = &IMPL::_MachinesInterface_GetLocal;
		_MachinesInterface_GetRPCMachines = &IMPL::_MachinesInterface_GetRPCMachines;
/// @cond INTERNAL

/// @endcond

		_MachinesInterface_FindRPCMachine = &IMPL::_MachinesInterface_FindRPCMachine;
/// @cond INTERNAL

/// @endcond

		_MachinesInterface_FindOrAddRPCMachine = &IMPL::_MachinesInterface_FindOrAddRPCMachine;
/// @cond INTERNAL

/// @endcond

		_MachinesInterface_RemoveRPCMachine = &IMPL::_MachinesInterface_RemoveRPCMachine;
		_MachinesInterface_ObservableMachineStateChanged = &IMPL::_MachinesInterface_ObservableMachineStateChanged;
	}
};

struct MachinesInterface::Hxx2
{
	class Unresolved;
	template <typename C> class Wrapper
	{
	public:
	static MachineRef _MachinesInterface_GetLocal() { return C::GetLocal(); }
	static Result<void> _MachinesInterface_GetRPCMachines(WritableArrayInterface<MachineRef>& machines) { return C::GetRPCMachines(machines); }
/// @cond INTERNAL

/// @endcond

	static Result<MachineRef> _MachinesInterface_FindRPCMachine(const String& machineUuid) { return C::FindRPCMachine(machineUuid); }
/// @cond INTERNAL

/// @endcond

	static Result<MachineRef> _MachinesInterface_FindOrAddRPCMachine(const String& machineUuid, MACHINESTATE state, const CreateNewMachineCallback& newMachineCallback, const CheckExistingMachineCallback& existingCallback) { return C::FindOrAddRPCMachine(machineUuid, state, newMachineCallback, existingCallback); }
/// @cond INTERNAL

/// @endcond

	static Result<void> _MachinesInterface_RemoveRPCMachine(const MachineRef& machine) { return C::RemoveRPCMachine(machine); }
	static maxon::ObservableRef<ObservableMachineStateChangedDelegate> _MachinesInterface_ObservableMachineStateChanged() { return C::ObservableMachineStateChanged(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto MachinesInterface::GetLocal() -> MachineRef
{
	return MTable::_instance._MachinesInterface_GetLocal();
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MachinesInterface::GetRPCMachines(WritableArrayInterface<MachineRef>& machines) -> Result<void>
{
	return MTable::_instance._MachinesInterface_GetRPCMachines(machines);
}
/// @cond INTERNAL

/// @endcond

MAXON_ATTRIBUTE_FORCE_INLINE auto MachinesInterface::FindRPCMachine(const String& machineUuid) -> Result<MachineRef>
{
	return MTable::_instance._MachinesInterface_FindRPCMachine(machineUuid);
}
/// @cond INTERNAL

/// @endcond

MAXON_ATTRIBUTE_FORCE_INLINE auto MachinesInterface::FindOrAddRPCMachine(const String& machineUuid, MACHINESTATE state, const CreateNewMachineCallback& newMachineCallback, const CheckExistingMachineCallback& existingCallback) -> Result<MachineRef>
{
	return MTable::_instance._MachinesInterface_FindOrAddRPCMachine(machineUuid, state, newMachineCallback, existingCallback);
}
/// @cond INTERNAL

/// @endcond

MAXON_ATTRIBUTE_FORCE_INLINE auto MachinesInterface::RemoveRPCMachine(const MachineRef& machine) -> Result<void>
{
	return MTable::_instance._MachinesInterface_RemoveRPCMachine(machine);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MachinesInterface::ObservableMachineStateChanged() -> maxon::ObservableRef<ObservableMachineStateChangedDelegate>
{
	return MTable::_instance._MachinesInterface_ObservableMachineStateChanged();
}

#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_MachinesInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_MachinesInterface() { new (s_ui_maxon_MachinesInterface) maxon::EntityUse(MachinesInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/machine.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_MachinesInterface(MachinesInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/machine.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#ifndef MAXON_COMPILER_CLANG
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

