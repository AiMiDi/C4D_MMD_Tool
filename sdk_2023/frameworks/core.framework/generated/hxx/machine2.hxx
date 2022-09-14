
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
	PRIVATE_MAXON_MF_POINTER(MachineInterface_GetUniqueId, GetUniqueId, true, maxon::GenericComponent, const, (String));
	maxon::Int MachineInterface_GetUniqueId_Offset;
	PRIVATE_MAXON_MF_POINTER(MachineInterface_GetMachineInfo, GetMachineInfo, true, maxon::GenericComponent, const, (Result<DataDictionary>));
	maxon::Int MachineInterface_GetMachineInfo_Offset;
	PRIVATE_MAXON_MF_POINTER(MachineInterface_GetInterface, GetInterface, true, maxon::GenericComponent,, (Result<ObjectRef>), const Id& interfaceName);
	maxon::Int MachineInterface_GetInterface_Offset;
	PRIVATE_MAXON_MF_POINTER(MachineInterface_GetState, GetState, true, maxon::GenericComponent, const, (MACHINESTATE));
	maxon::Int MachineInterface_GetState_Offset;
	PRIVATE_MAXON_MF_POINTER(MachineInterface_SetState, SetState, true, maxon::GenericComponent,, (Bool), MACHINESTATE stateMask, MACHINESTATE stateFlags);
	maxon::Int MachineInterface_SetState_Offset;
	PRIVATE_MAXON_MF_POINTER(MachineInterface_ToString, ToString, true, maxon::GenericComponent, const, (String), const FormatStatement* formatStatement);
	maxon::Int MachineInterface_ToString_Offset;
	PRIVATE_MAXON_MF_POINTER(MachineInterface_ObservablePrivateSplashMessageReceived, ObservablePrivateSplashMessageReceived, true, maxon::GenericComponent, const, (maxon::ObservableRef<ObservablePrivateSplashMessageReceivedDelegate>));
	maxon::Int MachineInterface_ObservablePrivateSplashMessageReceived_Offset;
	PRIVATE_MAXON_MF_POINTER(MachineInterface_ObservableActivationChanged, ObservableActivationChanged, true, maxon::GenericComponent, const, (maxon::ObservableRef<ObservableActivationChangedDelegate>));
	maxon::Int MachineInterface_ObservableActivationChanged_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MachineInterface, GetUniqueId))
	{
		maxon::Tie(MachineInterface_GetUniqueId, MachineInterface_GetUniqueId_Offset) = MachineInterface_GetUniqueId_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MachineInterface, GetMachineInfo))
	{
		maxon::Tie(MachineInterface_GetMachineInfo, MachineInterface_GetMachineInfo_Offset) = MachineInterface_GetMachineInfo_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MachineInterface, GetInterface))
	{
		maxon::Tie(MachineInterface_GetInterface, MachineInterface_GetInterface_Offset) = MachineInterface_GetInterface_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MachineInterface, GetState))
	{
		maxon::Tie(MachineInterface_GetState, MachineInterface_GetState_Offset) = MachineInterface_GetState_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MachineInterface, SetState))
	{
		maxon::Tie(MachineInterface_SetState, MachineInterface_SetState_Offset) = MachineInterface_SetState_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MachineInterface, ToString))
	{
		maxon::Tie(MachineInterface_ToString, MachineInterface_ToString_Offset) = MachineInterface_ToString_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MachineInterface, ObservablePrivateSplashMessageReceived))
	{
		maxon::Tie(MachineInterface_ObservablePrivateSplashMessageReceived, MachineInterface_ObservablePrivateSplashMessageReceived_Offset) = MachineInterface_ObservablePrivateSplashMessageReceived_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MachineInterface, ObservableActivationChanged))
	{
		maxon::Tie(MachineInterface_ObservableActivationChanged, MachineInterface_ObservableActivationChanged_Offset) = MachineInterface_ObservableActivationChanged_GetPtr<W>(offset, true);
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
			if constexpr (!S::Implementation::PROXY)
			{
				if (!(Super0::InitMTablesWithBases(info, offset))) return false;
			}
			auto* vt = (MachineInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, MachineInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		PRIVATE_MAXON_MF_WRAPPER(MachineInterface_GetUniqueId, maxon::GenericComponent, const, (String)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetUniqueId(); }
		PRIVATE_MAXON_MF_WRAPPER(MachineInterface_GetMachineInfo, maxon::GenericComponent, const, (Result<DataDictionary>)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetMachineInfo(); }
		PRIVATE_MAXON_MF_WRAPPER(MachineInterface_GetInterface, maxon::GenericComponent,, (Result<ObjectRef>), const Id& interfaceName) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->GetInterface(interfaceName); }
		PRIVATE_MAXON_MF_WRAPPER(MachineInterface_GetState, maxon::GenericComponent, const, (MACHINESTATE)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetState(); }
		PRIVATE_MAXON_MF_WRAPPER(MachineInterface_SetState, maxon::GenericComponent,, (Bool), MACHINESTATE stateMask, MACHINESTATE stateFlags) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->SetState(stateMask, stateFlags); }
		PRIVATE_MAXON_MF_WRAPPER(MachineInterface_ToString, maxon::GenericComponent, const, (String), const FormatStatement* formatStatement) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->ToString(formatStatement); }
		PRIVATE_MAXON_MF_WRAPPER(MachineInterface_ObservablePrivateSplashMessageReceived, maxon::GenericComponent, const, (maxon::ObservableRef<ObservablePrivateSplashMessageReceivedDelegate>)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->ObservablePrivateSplashMessageReceived(); }
		PRIVATE_MAXON_MF_WRAPPER(MachineInterface_ObservableActivationChanged, maxon::GenericComponent, const, (maxon::ObservableRef<ObservableActivationChangedDelegate>)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->ObservableActivationChanged(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto MachineInterface::GetUniqueId() const -> String
{
	const MachineInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MachineInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.MachineInterface_GetUniqueId_Offset), mt_.MachineInterface_GetUniqueId);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MachineInterface::GetMachineInfo() const -> Result<DataDictionary>
{
	const MachineInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MachineInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.MachineInterface_GetMachineInfo_Offset), mt_.MachineInterface_GetMachineInfo);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MachineInterface::GetInterface(const Id& interfaceName) -> Result<ObjectRef>
{
	const MachineInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MachineInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.MachineInterface_GetInterface_Offset), mt_.MachineInterface_GetInterface, interfaceName);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MachineInterface::GetState() const -> MACHINESTATE
{
	const MachineInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MachineInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.MachineInterface_GetState_Offset), mt_.MachineInterface_GetState);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MachineInterface::SetState(MACHINESTATE stateMask, MACHINESTATE stateFlags) -> Bool
{
	const MachineInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MachineInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.MachineInterface_SetState_Offset), mt_.MachineInterface_SetState, stateMask, stateFlags);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MachineInterface::ToString(const FormatStatement* formatStatement) const -> String
{
	const MachineInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MachineInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.MachineInterface_ToString_Offset), mt_.MachineInterface_ToString, formatStatement);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MachineInterface::ObservablePrivateSplashMessageReceived() const -> maxon::ObservableRef<ObservablePrivateSplashMessageReceivedDelegate>
{
	const MachineInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MachineInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.MachineInterface_ObservablePrivateSplashMessageReceived_Offset), mt_.MachineInterface_ObservablePrivateSplashMessageReceived);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MachineInterface::ObservableActivationChanged() const -> maxon::ObservableRef<ObservableActivationChangedDelegate>
{
	const MachineInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MachineInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.MachineInterface_ObservableActivationChanged_Offset), mt_.MachineInterface_ObservableActivationChanged);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MachineInterface::Hxx1::ConstFn<S>::GetUniqueId() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const MachineInterface* o_ = (const MachineInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = MachineInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MachineInterface, o_, MachineInterface_GetUniqueId) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<MachineInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MachineInterface>() : PRIVATE_MAXON_VTABLE(MachineInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.MachineInterface_GetUniqueId_Offset), mt_.MachineInterface_GetUniqueId));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MachineInterface::Hxx1::ConstFn<S>::GetMachineInfo() const -> Result<DataDictionary>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<DataDictionary>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const MachineInterface* o_ = (const MachineInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = MachineInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MachineInterface, o_, MachineInterface_GetMachineInfo) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<MachineInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MachineInterface>() : PRIVATE_MAXON_VTABLE(MachineInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.MachineInterface_GetMachineInfo_Offset), mt_.MachineInterface_GetMachineInfo));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MachineInterface::Hxx1::Fn<S>::GetInterface(const Id& interfaceName) const -> Result<ObjectRef>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<ObjectRef>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); MachineInterface* o_ = (MachineInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MachineInterface, o_, MachineInterface_GetInterface) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<MachineInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MachineInterface>() : PRIVATE_MAXON_VTABLE(MachineInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MachineInterface_GetInterface_Offset), mt_.MachineInterface_GetInterface, interfaceName));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MachineInterface::Hxx1::COWFn<S>::GetInterface(const Id& interfaceName) -> Result<ObjectRef>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<ObjectRef>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); MachineInterface* o_ = (MachineInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MachineInterface, o_, MachineInterface_GetInterface) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<MachineInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MachineInterface>() : PRIVATE_MAXON_VTABLE(MachineInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MachineInterface_GetInterface_Offset), mt_.MachineInterface_GetInterface, interfaceName));
}
template <typename S> template <typename INTERFACE> MAXON_ATTRIBUTE_FORCE_INLINE auto MachineInterface::Hxx1::Fn<S>::GetInterface() const -> Result<INTERFACE>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<INTERFACE>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); MachineInterface* o_ = (MachineInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->GetInterface<INTERFACE>());
}
template <typename S> template <typename INTERFACE> MAXON_ATTRIBUTE_FORCE_INLINE auto MachineInterface::Hxx1::COWFn<S>::GetInterface() -> Result<INTERFACE>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<INTERFACE>>; static_assert(!std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value, "Can't invoke MAXON_FUNCTION MachineInterface::GetInterface on super."); if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); MachineInterface* o_ = (MachineInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (o_->GetInterface<INTERFACE>());
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MachineInterface::Hxx1::ConstFn<S>::GetState() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<MACHINESTATE>, MACHINESTATE>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<MACHINESTATE>, MACHINESTATE>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const MachineInterface* o_ = (const MachineInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = MachineInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<MACHINESTATE>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MachineInterface, o_, MachineInterface_GetState) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<MachineInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MachineInterface>() : PRIVATE_MAXON_VTABLE(MachineInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.MachineInterface_GetState_Offset), mt_.MachineInterface_GetState));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MachineInterface::Hxx1::Fn<S>::SetState(MACHINESTATE stateMask, MACHINESTATE stateFlags) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); MachineInterface* o_ = (MachineInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateLogNullptrError(false); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MachineInterface, o_, MachineInterface_SetState) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<MachineInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MachineInterface>() : PRIVATE_MAXON_VTABLE(MachineInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MachineInterface_SetState_Offset), mt_.MachineInterface_SetState, stateMask, stateFlags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MachineInterface::Hxx1::COWFn<S>::SetState(MACHINESTATE stateMask, MACHINESTATE stateFlags) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Bool, maxon::Result<Bool>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Bool, maxon::Result<Bool>>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); MachineInterface* o_ = (MachineInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MachineInterface, o_, MachineInterface_SetState) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<MachineInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MachineInterface>() : PRIVATE_MAXON_VTABLE(MachineInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MachineInterface_SetState_Offset), mt_.MachineInterface_SetState, stateMask, stateFlags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MachineInterface::Hxx1::ConstFn<S>::ToString(const FormatStatement* formatStatement) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const MachineInterface* o_ = (const MachineInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = MachineInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MachineInterface, o_, MachineInterface_ToString) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<MachineInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MachineInterface>() : PRIVATE_MAXON_VTABLE(MachineInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.MachineInterface_ToString_Offset), mt_.MachineInterface_ToString, formatStatement));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MachineInterface::Hxx1::ConstFn<S>::ObservablePrivateSplashMessageReceived() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<maxon::ObservableRef<ObservablePrivateSplashMessageReceivedDelegate>>, maxon::ObservableRef<ObservablePrivateSplashMessageReceivedDelegate>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<maxon::ObservableRef<ObservablePrivateSplashMessageReceivedDelegate>>, maxon::ObservableRef<ObservablePrivateSplashMessageReceivedDelegate>>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const MachineInterface* o_ = (const MachineInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = MachineInterface::NullValuePtr(); if (!o_) return maxon::ObservableRef<ObservablePrivateSplashMessageReceivedDelegate>::NullValue(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MachineInterface, o_, MachineInterface_ObservablePrivateSplashMessageReceived) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<MachineInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MachineInterface>() : PRIVATE_MAXON_VTABLE(MachineInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.MachineInterface_ObservablePrivateSplashMessageReceived_Offset), mt_.MachineInterface_ObservablePrivateSplashMessageReceived));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MachineInterface::Hxx1::ConstFn<S>::ObservableActivationChanged() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<maxon::ObservableRef<ObservableActivationChangedDelegate>>, maxon::ObservableRef<ObservableActivationChangedDelegate>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<maxon::ObservableRef<ObservableActivationChangedDelegate>>, maxon::ObservableRef<ObservableActivationChangedDelegate>>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const MachineInterface* o_ = (const MachineInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = MachineInterface::NullValuePtr(); if (!o_) return maxon::ObservableRef<ObservableActivationChangedDelegate>::NullValue(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MachineInterface, o_, MachineInterface_ObservableActivationChanged) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<MachineInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MachineInterface>() : PRIVATE_MAXON_VTABLE(MachineInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.MachineInterface_ObservableActivationChanged_Offset), mt_.MachineInterface_ObservableActivationChanged));
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
	PRIVATE_MAXON_SF_POINTER(MachinesInterface_GetLocal, GetLocal, MAXON_EXPAND_VA_ARGS, (MachineRef));
	PRIVATE_MAXON_SF_POINTER(MachinesInterface_GetRPCMachines, GetRPCMachines, MAXON_EXPAND_VA_ARGS, (Result<void>), WritableArrayInterface<MachineRef>& machines);
/// @cond INTERNAL

/// @endcond

	PRIVATE_MAXON_SF_POINTER(MachinesInterface_FindRPCMachine, FindRPCMachine, MAXON_EXPAND_VA_ARGS, (Result<MachineRef>), const String& machineUuid);
/// @cond INTERNAL

/// @endcond

	PRIVATE_MAXON_SF_POINTER(MachinesInterface_FindOrAddRPCMachine, FindOrAddRPCMachine, MAXON_EXPAND_VA_ARGS, (Result<MachineRef>), const String& machineUuid, MACHINESTATE state, const CreateNewMachineCallback& newMachineCallback, const CheckExistingMachineCallback& existingCallback);
/// @cond INTERNAL

/// @endcond

	PRIVATE_MAXON_SF_POINTER(MachinesInterface_RemoveRPCMachine, RemoveRPCMachine, MAXON_EXPAND_VA_ARGS, (Result<void>), const MachineRef& machine);
	PRIVATE_MAXON_SF_POINTER(MachinesInterface_ObservableMachineStateChanged, ObservableMachineStateChanged, MAXON_EXPAND_VA_ARGS, (maxon::ObservableRef<ObservableMachineStateChangedDelegate>));
	template <typename IMPL> void Init()
	{
		MachinesInterface_GetLocal = MachinesInterface_GetLocal_GetPtr<IMPL>(true);
		MachinesInterface_GetRPCMachines = MachinesInterface_GetRPCMachines_GetPtr<IMPL>(true);
/// @cond INTERNAL

/// @endcond

		MachinesInterface_FindRPCMachine = MachinesInterface_FindRPCMachine_GetPtr<IMPL>(true);
/// @cond INTERNAL

/// @endcond

		MachinesInterface_FindOrAddRPCMachine = MachinesInterface_FindOrAddRPCMachine_GetPtr<IMPL>(true);
/// @cond INTERNAL

/// @endcond

		MachinesInterface_RemoveRPCMachine = MachinesInterface_RemoveRPCMachine_GetPtr<IMPL>(true);
		MachinesInterface_ObservableMachineStateChanged = MachinesInterface_ObservableMachineStateChanged_GetPtr<IMPL>(true);
	}
};

struct MachinesInterface::Hxx2
{
	class Unresolved;
	template <typename C> class Wrapper
	{
	public:
		using Implementation = C;
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

