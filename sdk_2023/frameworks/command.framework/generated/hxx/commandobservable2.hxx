
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1

struct CommandObserverInterface::MTable
{
	PRIVATE_MAXON_IMPLEMENTS_CHECK(ObservableCommandInvoked);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(ObservableCommandInvokedInfo);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(ObservableCommandPrepareInfo);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(ObservableCommandStatus);
	static const maxon::Char* const _ids;
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	PRIVATE_MAXON_MF_POINTER(CommandObserverInterface_ObservableCommandStatus, ObservableCommandStatus, true, maxon::GenericComponent, const, (maxon::ObservableRef<ObservableCommandStatusDelegate>));
	maxon::Int CommandObserverInterface_ObservableCommandStatus_Offset;
	PRIVATE_MAXON_MF_POINTER(CommandObserverInterface_ObservableCommandInvoked, ObservableCommandInvoked, true, maxon::GenericComponent, const, (maxon::ObservableRef<ObservableCommandInvokedDelegate>));
	maxon::Int CommandObserverInterface_ObservableCommandInvoked_Offset;
	PRIVATE_MAXON_MF_POINTER(CommandObserverInterface_ObservableCommandPrepareInfo, ObservableCommandPrepareInfo, true, maxon::GenericComponent, const, (maxon::ObservableRef<ObservableCommandPrepareInfoDelegate>));
	maxon::Int CommandObserverInterface_ObservableCommandPrepareInfo_Offset;
	PRIVATE_MAXON_MF_POINTER(CommandObserverInterface_ObservableCommandInvokedInfo, ObservableCommandInvokedInfo, true, maxon::GenericComponent, const, (maxon::ObservableRef<ObservableCommandInvokedInfoDelegate>));
	maxon::Int CommandObserverInterface_ObservableCommandInvokedInfo_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CommandObserverInterface, ObservableCommandStatus))
	{
		maxon::Tie(CommandObserverInterface_ObservableCommandStatus, CommandObserverInterface_ObservableCommandStatus_Offset) = CommandObserverInterface_ObservableCommandStatus_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CommandObserverInterface, ObservableCommandInvoked))
	{
		maxon::Tie(CommandObserverInterface_ObservableCommandInvoked, CommandObserverInterface_ObservableCommandInvoked_Offset) = CommandObserverInterface_ObservableCommandInvoked_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CommandObserverInterface, ObservableCommandPrepareInfo))
	{
		maxon::Tie(CommandObserverInterface_ObservableCommandPrepareInfo, CommandObserverInterface_ObservableCommandPrepareInfo_Offset) = CommandObserverInterface_ObservableCommandPrepareInfo_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CommandObserverInterface, ObservableCommandInvokedInfo))
	{
		maxon::Tie(CommandObserverInterface_ObservableCommandInvokedInfo, CommandObserverInterface_ObservableCommandInvokedInfo_Offset) = CommandObserverInterface_ObservableCommandInvokedInfo_GetPtr<W>(offset, true);
	}
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<CommandObserverInterface, typename ObserverObjectInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<CommandObserverInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct CommandObserverInterface::Hxx2
{
	template <typename S> class CWrapper : public ObserverObjectInterface::Hxx2::template CWrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(ObservableCommandInvoked);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(ObservableCommandInvokedInfo);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(ObservableCommandPrepareInfo);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(ObservableCommandStatus);
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename ObserverObjectInterface::Hxx2::template CWrapper<S>;
			if constexpr (!S::Implementation::PROXY)
			{
				if (!(Super0::InitMTablesWithBases(info, offset))) return false;
			}
			auto* vt = (CommandObserverInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, CommandObserverInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		PRIVATE_MAXON_MF_WRAPPER(CommandObserverInterface_ObservableCommandStatus, maxon::GenericComponent, const, (maxon::ObservableRef<ObservableCommandStatusDelegate>)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->ObservableCommandStatus(); }
		PRIVATE_MAXON_MF_WRAPPER(CommandObserverInterface_ObservableCommandInvoked, maxon::GenericComponent, const, (maxon::ObservableRef<ObservableCommandInvokedDelegate>)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->ObservableCommandInvoked(); }
		PRIVATE_MAXON_MF_WRAPPER(CommandObserverInterface_ObservableCommandPrepareInfo, maxon::GenericComponent, const, (maxon::ObservableRef<ObservableCommandPrepareInfoDelegate>)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->ObservableCommandPrepareInfo(); }
		PRIVATE_MAXON_MF_WRAPPER(CommandObserverInterface_ObservableCommandInvokedInfo, maxon::GenericComponent, const, (maxon::ObservableRef<ObservableCommandInvokedInfoDelegate>)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->ObservableCommandInvokedInfo(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto CommandObserverInterface::ObservableCommandStatus() const -> maxon::ObservableRef<ObservableCommandStatusDelegate>
{
	const CommandObserverInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(CommandObserverInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.CommandObserverInterface_ObservableCommandStatus_Offset), mt_.CommandObserverInterface_ObservableCommandStatus);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CommandObserverInterface::ObservableCommandInvoked() const -> maxon::ObservableRef<ObservableCommandInvokedDelegate>
{
	const CommandObserverInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(CommandObserverInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.CommandObserverInterface_ObservableCommandInvoked_Offset), mt_.CommandObserverInterface_ObservableCommandInvoked);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CommandObserverInterface::ObservableCommandPrepareInfo() const -> maxon::ObservableRef<ObservableCommandPrepareInfoDelegate>
{
	const CommandObserverInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(CommandObserverInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.CommandObserverInterface_ObservableCommandPrepareInfo_Offset), mt_.CommandObserverInterface_ObservableCommandPrepareInfo);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CommandObserverInterface::ObservableCommandInvokedInfo() const -> maxon::ObservableRef<ObservableCommandInvokedInfoDelegate>
{
	const CommandObserverInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(CommandObserverInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.CommandObserverInterface_ObservableCommandInvokedInfo_Offset), mt_.CommandObserverInterface_ObservableCommandInvokedInfo);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CommandObserverInterface::Hxx1::ConstFn<S>::ObservableCommandStatus() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<maxon::ObservableRef<ObservableCommandStatusDelegate>>, maxon::ObservableRef<ObservableCommandStatusDelegate>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<maxon::ObservableRef<ObservableCommandStatusDelegate>>, maxon::ObservableRef<ObservableCommandStatusDelegate>>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const CommandObserverInterface* o_ = (const CommandObserverInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = CommandObserverInterface::NullValuePtr(); if (!o_) return maxon::ObservableRef<ObservableCommandStatusDelegate>::NullValue(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CommandObserverInterface, o_, CommandObserverInterface_ObservableCommandStatus) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<CommandObserverInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CommandObserverInterface>() : PRIVATE_MAXON_VTABLE(CommandObserverInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.CommandObserverInterface_ObservableCommandStatus_Offset), mt_.CommandObserverInterface_ObservableCommandStatus));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CommandObserverInterface::Hxx1::ConstFn<S>::ObservableCommandInvoked() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<maxon::ObservableRef<ObservableCommandInvokedDelegate>>, maxon::ObservableRef<ObservableCommandInvokedDelegate>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<maxon::ObservableRef<ObservableCommandInvokedDelegate>>, maxon::ObservableRef<ObservableCommandInvokedDelegate>>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const CommandObserverInterface* o_ = (const CommandObserverInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = CommandObserverInterface::NullValuePtr(); if (!o_) return maxon::ObservableRef<ObservableCommandInvokedDelegate>::NullValue(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CommandObserverInterface, o_, CommandObserverInterface_ObservableCommandInvoked) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<CommandObserverInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CommandObserverInterface>() : PRIVATE_MAXON_VTABLE(CommandObserverInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.CommandObserverInterface_ObservableCommandInvoked_Offset), mt_.CommandObserverInterface_ObservableCommandInvoked));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CommandObserverInterface::Hxx1::ConstFn<S>::ObservableCommandPrepareInfo() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<maxon::ObservableRef<ObservableCommandPrepareInfoDelegate>>, maxon::ObservableRef<ObservableCommandPrepareInfoDelegate>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<maxon::ObservableRef<ObservableCommandPrepareInfoDelegate>>, maxon::ObservableRef<ObservableCommandPrepareInfoDelegate>>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const CommandObserverInterface* o_ = (const CommandObserverInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = CommandObserverInterface::NullValuePtr(); if (!o_) return maxon::ObservableRef<ObservableCommandPrepareInfoDelegate>::NullValue(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CommandObserverInterface, o_, CommandObserverInterface_ObservableCommandPrepareInfo) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<CommandObserverInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CommandObserverInterface>() : PRIVATE_MAXON_VTABLE(CommandObserverInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.CommandObserverInterface_ObservableCommandPrepareInfo_Offset), mt_.CommandObserverInterface_ObservableCommandPrepareInfo));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CommandObserverInterface::Hxx1::ConstFn<S>::ObservableCommandInvokedInfo() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<maxon::ObservableRef<ObservableCommandInvokedInfoDelegate>>, maxon::ObservableRef<ObservableCommandInvokedInfoDelegate>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<maxon::ObservableRef<ObservableCommandInvokedInfoDelegate>>, maxon::ObservableRef<ObservableCommandInvokedInfoDelegate>>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const CommandObserverInterface* o_ = (const CommandObserverInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = CommandObserverInterface::NullValuePtr(); if (!o_) return maxon::ObservableRef<ObservableCommandInvokedInfoDelegate>::NullValue(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CommandObserverInterface, o_, CommandObserverInterface_ObservableCommandInvokedInfo) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<CommandObserverInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CommandObserverInterface>() : PRIVATE_MAXON_VTABLE(CommandObserverInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.CommandObserverInterface_ObservableCommandInvokedInfo_Offset), mt_.CommandObserverInterface_ObservableCommandInvokedInfo));
}
auto CommandObserverInterface::GetPtr() -> Ptr { return Ptr(this); }
auto CommandObserverInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_commandobservable)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_CommandObserverInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_CommandObserverInterface() { new (s_ui_maxon_CommandObserverInterface) maxon::EntityUse(CommandObserverInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/commandobservable.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_CommandObserverInterface(CommandObserverInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/commandobservable.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

