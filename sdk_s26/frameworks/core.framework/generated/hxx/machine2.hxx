
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
	PRIVATE_MAXON_IMPLEMENTS_CHECK(ObservableActivationChanged);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(ObservablePrivateSplashMessageReceived);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(SetState);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(ToString);
	static const maxon::Char* const _ids;
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	String (*MachineInterface_GetUniqueId) (const maxon::GenericComponent* this_);
	maxon::Int MachineInterface_GetUniqueId_Offset;
	Result<DataDictionary> (*MachineInterface_GetMachineInfo) (const maxon::GenericComponent* this_);
	maxon::Int MachineInterface_GetMachineInfo_Offset;
	Result<ObjectRef> (*MachineInterface_GetInterface) (maxon::GenericComponent* this_, const Id& interfaceName);
	maxon::Int MachineInterface_GetInterface_Offset;
	MACHINESTATE (*MachineInterface_GetState) (const maxon::GenericComponent* this_);
	maxon::Int MachineInterface_GetState_Offset;
	Bool (*MachineInterface_SetState) (maxon::GenericComponent* this_, MACHINESTATE stateMask, MACHINESTATE stateFlags);
	maxon::Int MachineInterface_SetState_Offset;
	String (*MachineInterface_ToString) (const maxon::GenericComponent* this_, const FormatStatement* formatStatement);
	maxon::Int MachineInterface_ToString_Offset;
	maxon::ObservableRef<ObservablePrivateSplashMessageReceivedDelegate> (*MachineInterface_ObservablePrivateSplashMessageReceived) (const maxon::GenericComponent* this_);
	maxon::Int MachineInterface_ObservablePrivateSplashMessageReceived_Offset;
	maxon::ObservableRef<ObservableActivationChangedDelegate> (*MachineInterface_ObservableActivationChanged) (const maxon::GenericComponent* this_);
	maxon::Int MachineInterface_ObservableActivationChanged_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MachineInterface, GetUniqueId))
	{
		MachineInterface_GetUniqueId = &W::MachineInterface_GetUniqueId;
		MachineInterface_GetUniqueId_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MachineInterface, GetMachineInfo))
	{
		MachineInterface_GetMachineInfo = &W::MachineInterface_GetMachineInfo;
		MachineInterface_GetMachineInfo_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MachineInterface, GetInterface))
	{
		MachineInterface_GetInterface = &W::MachineInterface_GetInterface;
		MachineInterface_GetInterface_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MachineInterface, GetState))
	{
		MachineInterface_GetState = &W::MachineInterface_GetState;
		MachineInterface_GetState_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MachineInterface, SetState))
	{
		MachineInterface_SetState = &W::MachineInterface_SetState;
		MachineInterface_SetState_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MachineInterface, ToString))
	{
		MachineInterface_ToString = &W::MachineInterface_ToString;
		MachineInterface_ToString_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MachineInterface, ObservablePrivateSplashMessageReceived))
	{
		MachineInterface_ObservablePrivateSplashMessageReceived = &W::MachineInterface_ObservablePrivateSplashMessageReceived;
		MachineInterface_ObservablePrivateSplashMessageReceived_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MachineInterface, ObservableActivationChanged))
	{
		MachineInterface_ObservableActivationChanged = &W::MachineInterface_ObservableActivationChanged;
		MachineInterface_ObservableActivationChanged_Offset = offset;
	}
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<MachineInterface, typename ObserverObjectInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<MachineInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct MachineInterface::Hxx2
{
	template <typename S> class CWrapper : public ObserverObjectInterface::Hxx2::template CWrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetInterface);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetMachineInfo);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetState);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetUniqueId);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(ObservableActivationChanged);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(ObservablePrivateSplashMessageReceived);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(SetState);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(ToString);
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename ObserverObjectInterface::Hxx2::template CWrapper<S>;
			if (!S::Implementation::PROXY && !(Super0::InitMTablesWithBases(info, offset))) return false;
			auto* vt = (MachineInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, MachineInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		static String MachineInterface_GetUniqueId(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetUniqueId(); }
		static Result<DataDictionary> MachineInterface_GetMachineInfo(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetMachineInfo(); }
		static Result<ObjectRef> MachineInterface_GetInterface(maxon::GenericComponent* this_, const Id& interfaceName) { return ((typename S::Implementation*) this_)->GetInterface(interfaceName); }
		static MACHINESTATE MachineInterface_GetState(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetState(); }
		static Bool MachineInterface_SetState(maxon::GenericComponent* this_, MACHINESTATE stateMask, MACHINESTATE stateFlags) { return ((typename S::Implementation*) this_)->SetState(stateMask, stateFlags); }
		static String MachineInterface_ToString(const maxon::GenericComponent* this_, const FormatStatement* formatStatement) { return ((const typename S::Implementation*) this_)->ToString(formatStatement); }
		static maxon::ObservableRef<ObservablePrivateSplashMessageReceivedDelegate> MachineInterface_ObservablePrivateSplashMessageReceived(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->ObservablePrivateSplashMessageReceived(); }
		static maxon::ObservableRef<ObservableActivationChangedDelegate> MachineInterface_ObservableActivationChanged(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->ObservableActivationChanged(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto MachineInterface::GetUniqueId() const -> String
{
	const MachineInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MachineInterface, this); return mt_.MachineInterface_GetUniqueId((const maxon::GenericComponent*) this + mt_.MachineInterface_GetUniqueId_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MachineInterface::GetMachineInfo() const -> Result<DataDictionary>
{
	const MachineInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MachineInterface, this); return mt_.MachineInterface_GetMachineInfo((const maxon::GenericComponent*) this + mt_.MachineInterface_GetMachineInfo_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MachineInterface::GetInterface(const Id& interfaceName) -> Result<ObjectRef>
{
	const MachineInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MachineInterface, this); return mt_.MachineInterface_GetInterface((maxon::GenericComponent*) this + mt_.MachineInterface_GetInterface_Offset, interfaceName);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MachineInterface::GetState() const -> MACHINESTATE
{
	const MachineInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MachineInterface, this); return mt_.MachineInterface_GetState((const maxon::GenericComponent*) this + mt_.MachineInterface_GetState_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MachineInterface::SetState(MACHINESTATE stateMask, MACHINESTATE stateFlags) -> Bool
{
	const MachineInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MachineInterface, this); return mt_.MachineInterface_SetState((maxon::GenericComponent*) this + mt_.MachineInterface_SetState_Offset, stateMask, stateFlags);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MachineInterface::ToString(const FormatStatement* formatStatement) const -> String
{
	const MachineInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MachineInterface, this); return mt_.MachineInterface_ToString((const maxon::GenericComponent*) this + mt_.MachineInterface_ToString_Offset, formatStatement);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MachineInterface::ObservablePrivateSplashMessageReceived() const -> maxon::ObservableRef<ObservablePrivateSplashMessageReceivedDelegate>
{
	const MachineInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MachineInterface, this); return mt_.MachineInterface_ObservablePrivateSplashMessageReceived((const maxon::GenericComponent*) this + mt_.MachineInterface_ObservablePrivateSplashMessageReceived_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MachineInterface::ObservableActivationChanged() const -> maxon::ObservableRef<ObservableActivationChangedDelegate>
{
	const MachineInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MachineInterface, this); return mt_.MachineInterface_ObservableActivationChanged((const maxon::GenericComponent*) this + mt_.MachineInterface_ObservableActivationChanged_Offset);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MachineInterface::Hxx1::ConstFn<S>::GetUniqueId() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const MachineInterface* o_ = (const MachineInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = MachineInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MachineInterface, o_, MachineInterface_GetUniqueId) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<MachineInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MachineInterface>() : PRIVATE_MAXON_VTABLE(MachineInterface, o_); 
	return (mt_.MachineInterface_GetUniqueId(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.MachineInterface_GetUniqueId_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MachineInterface::Hxx1::ConstFn<S>::GetMachineInfo() const -> Result<DataDictionary>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<DataDictionary>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const MachineInterface* o_ = (const MachineInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = MachineInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MachineInterface, o_, MachineInterface_GetMachineInfo) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<MachineInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MachineInterface>() : PRIVATE_MAXON_VTABLE(MachineInterface, o_); 
	return (mt_.MachineInterface_GetMachineInfo(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.MachineInterface_GetMachineInfo_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MachineInterface::Hxx1::Fn<S>::GetInterface(const Id& interfaceName) const -> Result<ObjectRef>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<ObjectRef>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); MachineInterface* o_ = (MachineInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MachineInterface, o_, MachineInterface_GetInterface) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<MachineInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MachineInterface>() : PRIVATE_MAXON_VTABLE(MachineInterface, o_); 
	return (mt_.MachineInterface_GetInterface(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MachineInterface_GetInterface_Offset, interfaceName));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MachineInterface::Hxx1::COWFn<S>::GetInterface(const Id& interfaceName) -> Result<ObjectRef>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<ObjectRef>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); MachineInterface* o_ = (MachineInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MachineInterface, o_, MachineInterface_GetInterface) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<MachineInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MachineInterface>() : PRIVATE_MAXON_VTABLE(MachineInterface, o_); 
	return (mt_.MachineInterface_GetInterface(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MachineInterface_GetInterface_Offset, interfaceName));
}
template <typename S> template <typename INTERFACE> MAXON_ATTRIBUTE_FORCE_INLINE auto MachineInterface::Hxx1::Fn<S>::GetInterface() const -> Result<INTERFACE>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<INTERFACE>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); MachineInterface* o_ = (MachineInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->GetInterface<INTERFACE>());
}
template <typename S> template <typename INTERFACE> MAXON_ATTRIBUTE_FORCE_INLINE auto MachineInterface::Hxx1::COWFn<S>::GetInterface() -> Result<INTERFACE>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<INTERFACE>>; static_assert(!std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value, "Can't invoke MAXON_FUNCTION MachineInterface::GetInterface on super."); if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); MachineInterface* o_ = (MachineInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (o_->GetInterface<INTERFACE>());
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MachineInterface::Hxx1::ConstFn<S>::GetState() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<MACHINESTATE>, MACHINESTATE>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<MACHINESTATE>, MACHINESTATE>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const MachineInterface* o_ = (const MachineInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = MachineInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<MACHINESTATE>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MachineInterface, o_, MachineInterface_GetState) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<MachineInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MachineInterface>() : PRIVATE_MAXON_VTABLE(MachineInterface, o_); 
	return (mt_.MachineInterface_GetState(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.MachineInterface_GetState_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MachineInterface::Hxx1::Fn<S>::SetState(MACHINESTATE stateMask, MACHINESTATE stateFlags) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); MachineInterface* o_ = (MachineInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateLogNullptrError(false); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MachineInterface, o_, MachineInterface_SetState) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<MachineInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MachineInterface>() : PRIVATE_MAXON_VTABLE(MachineInterface, o_); 
	return (mt_.MachineInterface_SetState(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MachineInterface_SetState_Offset, stateMask, stateFlags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MachineInterface::Hxx1::COWFn<S>::SetState(MACHINESTATE stateMask, MACHINESTATE stateFlags) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Bool, maxon::Result<Bool>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Bool, maxon::Result<Bool>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); MachineInterface* o_ = (MachineInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MachineInterface, o_, MachineInterface_SetState) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<MachineInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MachineInterface>() : PRIVATE_MAXON_VTABLE(MachineInterface, o_); 
	return (mt_.MachineInterface_SetState(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MachineInterface_SetState_Offset, stateMask, stateFlags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MachineInterface::Hxx1::ConstFn<S>::ToString(const FormatStatement* formatStatement) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const MachineInterface* o_ = (const MachineInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = MachineInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MachineInterface, o_, MachineInterface_ToString) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<MachineInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MachineInterface>() : PRIVATE_MAXON_VTABLE(MachineInterface, o_); 
	return (mt_.MachineInterface_ToString(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.MachineInterface_ToString_Offset, formatStatement));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MachineInterface::Hxx1::ConstFn<S>::ObservablePrivateSplashMessageReceived() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<maxon::ObservableRef<ObservablePrivateSplashMessageReceivedDelegate>>, maxon::ObservableRef<ObservablePrivateSplashMessageReceivedDelegate>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<maxon::ObservableRef<ObservablePrivateSplashMessageReceivedDelegate>>, maxon::ObservableRef<ObservablePrivateSplashMessageReceivedDelegate>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const MachineInterface* o_ = (const MachineInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = MachineInterface::NullValuePtr(); if (!o_) return maxon::ObservableRef<ObservablePrivateSplashMessageReceivedDelegate>::NullValue(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MachineInterface, o_, MachineInterface_ObservablePrivateSplashMessageReceived) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<MachineInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MachineInterface>() : PRIVATE_MAXON_VTABLE(MachineInterface, o_); 
	return (mt_.MachineInterface_ObservablePrivateSplashMessageReceived(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.MachineInterface_ObservablePrivateSplashMessageReceived_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MachineInterface::Hxx1::ConstFn<S>::ObservableActivationChanged() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<maxon::ObservableRef<ObservableActivationChangedDelegate>>, maxon::ObservableRef<ObservableActivationChangedDelegate>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<maxon::ObservableRef<ObservableActivationChangedDelegate>>, maxon::ObservableRef<ObservableActivationChangedDelegate>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const MachineInterface* o_ = (const MachineInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = MachineInterface::NullValuePtr(); if (!o_) return maxon::ObservableRef<ObservableActivationChangedDelegate>::NullValue(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MachineInterface, o_, MachineInterface_ObservableActivationChanged) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<MachineInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MachineInterface>() : PRIVATE_MAXON_VTABLE(MachineInterface, o_); 
	return (mt_.MachineInterface_ObservableActivationChanged(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.MachineInterface_ObservableActivationChanged_Offset));
}
auto MachineInterface::GetPtr() -> Ptr { return Ptr(this); }
auto MachineInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_machine)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_MachineInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_MachineInterface() { new (s_ui_maxon_MachineInterface) maxon::EntityUse(MachineInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/machine.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_MachineInterface(MachineInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/machine.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
constexpr const maxon::Char* MachinesInterface::PrivateGetCppName() { return nullptr; }
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
	MachineRef (*MachinesInterface_GetLocal) ();
	Result<void> (*MachinesInterface_GetRPCMachines) (WritableArrayInterface<MachineRef>& machines);
/// @cond INTERNAL

/// @endcond

	Result<MachineRef> (*MachinesInterface_FindRPCMachine) (const String& machineUuid);
/// @cond INTERNAL

/// @endcond

	Result<MachineRef> (*MachinesInterface_FindOrAddRPCMachine) (const String& machineUuid, MACHINESTATE state, const CreateNewMachineCallback& newMachineCallback, const CheckExistingMachineCallback& existingCallback);
/// @cond INTERNAL

/// @endcond

	Result<void> (*MachinesInterface_RemoveRPCMachine) (const MachineRef& machine);
	maxon::ObservableRef<ObservableMachineStateChangedDelegate> (*MachinesInterface_ObservableMachineStateChanged) ();
	template <typename IMPL> void Init()
	{
		MachinesInterface_GetLocal = &IMPL::MachinesInterface_GetLocal;
		MachinesInterface_GetRPCMachines = &IMPL::MachinesInterface_GetRPCMachines;
/// @cond INTERNAL

/// @endcond

		MachinesInterface_FindRPCMachine = &IMPL::MachinesInterface_FindRPCMachine;
/// @cond INTERNAL

/// @endcond

		MachinesInterface_FindOrAddRPCMachine = &IMPL::MachinesInterface_FindOrAddRPCMachine;
/// @cond INTERNAL

/// @endcond

		MachinesInterface_RemoveRPCMachine = &IMPL::MachinesInterface_RemoveRPCMachine;
		MachinesInterface_ObservableMachineStateChanged = &IMPL::MachinesInterface_ObservableMachineStateChanged;
	}
};

struct MachinesInterface::Hxx2
{
	class Unresolved;
	template <typename C> class Wrapper
	{
	public:
		static MachineRef MachinesInterface_GetLocal() { return C::GetLocal(); }
		static Result<void> MachinesInterface_GetRPCMachines(WritableArrayInterface<MachineRef>& machines) { return C::GetRPCMachines(machines); }
/// @cond INTERNAL

/// @endcond

		static Result<MachineRef> MachinesInterface_FindRPCMachine(const String& machineUuid) { return C::FindRPCMachine(machineUuid); }
/// @cond INTERNAL

/// @endcond

		static Result<MachineRef> MachinesInterface_FindOrAddRPCMachine(const String& machineUuid, MACHINESTATE state, const CreateNewMachineCallback& newMachineCallback, const CheckExistingMachineCallback& existingCallback) { return C::FindOrAddRPCMachine(machineUuid, state, newMachineCallback, existingCallback); }
/// @cond INTERNAL

/// @endcond

		static Result<void> MachinesInterface_RemoveRPCMachine(const MachineRef& machine) { return C::RemoveRPCMachine(machine); }
		static maxon::ObservableRef<ObservableMachineStateChangedDelegate> MachinesInterface_ObservableMachineStateChanged() { return C::ObservableMachineStateChanged(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto MachinesInterface::GetLocal() -> MachineRef
{
	return MTable::_instance.MachinesInterface_GetLocal();
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MachinesInterface::GetRPCMachines(WritableArrayInterface<MachineRef>& machines) -> Result<void>
{
	return MTable::_instance.MachinesInterface_GetRPCMachines(machines);
}
/// @cond INTERNAL

/// @endcond

MAXON_ATTRIBUTE_FORCE_INLINE auto MachinesInterface::FindRPCMachine(const String& machineUuid) -> Result<MachineRef>
{
	return MTable::_instance.MachinesInterface_FindRPCMachine(machineUuid);
}
/// @cond INTERNAL

/// @endcond

MAXON_ATTRIBUTE_FORCE_INLINE auto MachinesInterface::FindOrAddRPCMachine(const String& machineUuid, MACHINESTATE state, const CreateNewMachineCallback& newMachineCallback, const CheckExistingMachineCallback& existingCallback) -> Result<MachineRef>
{
	return MTable::_instance.MachinesInterface_FindOrAddRPCMachine(machineUuid, state, newMachineCallback, existingCallback);
}
/// @cond INTERNAL

/// @endcond

MAXON_ATTRIBUTE_FORCE_INLINE auto MachinesInterface::RemoveRPCMachine(const MachineRef& machine) -> Result<void>
{
	return MTable::_instance.MachinesInterface_RemoveRPCMachine(machine);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MachinesInterface::ObservableMachineStateChanged() -> maxon::ObservableRef<ObservableMachineStateChangedDelegate>
{
	return MTable::_instance.MachinesInterface_ObservableMachineStateChanged();
}

#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_machine)
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

