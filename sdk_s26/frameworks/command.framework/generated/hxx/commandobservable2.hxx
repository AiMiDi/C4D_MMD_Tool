
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
	maxon::ObservableRef<ObservableCommandStatusDelegate> (*CommandObserverInterface_ObservableCommandStatus) (const maxon::GenericComponent* this_);
	maxon::Int CommandObserverInterface_ObservableCommandStatus_Offset;
	maxon::ObservableRef<ObservableCommandInvokedDelegate> (*CommandObserverInterface_ObservableCommandInvoked) (const maxon::GenericComponent* this_);
	maxon::Int CommandObserverInterface_ObservableCommandInvoked_Offset;
	maxon::ObservableRef<ObservableCommandPrepareInfoDelegate> (*CommandObserverInterface_ObservableCommandPrepareInfo) (const maxon::GenericComponent* this_);
	maxon::Int CommandObserverInterface_ObservableCommandPrepareInfo_Offset;
	maxon::ObservableRef<ObservableCommandInvokedInfoDelegate> (*CommandObserverInterface_ObservableCommandInvokedInfo) (const maxon::GenericComponent* this_);
	maxon::Int CommandObserverInterface_ObservableCommandInvokedInfo_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CommandObserverInterface, ObservableCommandStatus))
	{
		CommandObserverInterface_ObservableCommandStatus = &W::CommandObserverInterface_ObservableCommandStatus;
		CommandObserverInterface_ObservableCommandStatus_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CommandObserverInterface, ObservableCommandInvoked))
	{
		CommandObserverInterface_ObservableCommandInvoked = &W::CommandObserverInterface_ObservableCommandInvoked;
		CommandObserverInterface_ObservableCommandInvoked_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CommandObserverInterface, ObservableCommandPrepareInfo))
	{
		CommandObserverInterface_ObservableCommandPrepareInfo = &W::CommandObserverInterface_ObservableCommandPrepareInfo;
		CommandObserverInterface_ObservableCommandPrepareInfo_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CommandObserverInterface, ObservableCommandInvokedInfo))
	{
		CommandObserverInterface_ObservableCommandInvokedInfo = &W::CommandObserverInterface_ObservableCommandInvokedInfo;
		CommandObserverInterface_ObservableCommandInvokedInfo_Offset = offset;
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
			if (!S::Implementation::PROXY && !(Super0::InitMTablesWithBases(info, offset))) return false;
			auto* vt = (CommandObserverInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, CommandObserverInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		static maxon::ObservableRef<ObservableCommandStatusDelegate> CommandObserverInterface_ObservableCommandStatus(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->ObservableCommandStatus(); }
		static maxon::ObservableRef<ObservableCommandInvokedDelegate> CommandObserverInterface_ObservableCommandInvoked(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->ObservableCommandInvoked(); }
		static maxon::ObservableRef<ObservableCommandPrepareInfoDelegate> CommandObserverInterface_ObservableCommandPrepareInfo(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->ObservableCommandPrepareInfo(); }
		static maxon::ObservableRef<ObservableCommandInvokedInfoDelegate> CommandObserverInterface_ObservableCommandInvokedInfo(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->ObservableCommandInvokedInfo(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto CommandObserverInterface::ObservableCommandStatus() const -> maxon::ObservableRef<ObservableCommandStatusDelegate>
{
	const CommandObserverInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(CommandObserverInterface, this); return mt_.CommandObserverInterface_ObservableCommandStatus((const maxon::GenericComponent*) this + mt_.CommandObserverInterface_ObservableCommandStatus_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CommandObserverInterface::ObservableCommandInvoked() const -> maxon::ObservableRef<ObservableCommandInvokedDelegate>
{
	const CommandObserverInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(CommandObserverInterface, this); return mt_.CommandObserverInterface_ObservableCommandInvoked((const maxon::GenericComponent*) this + mt_.CommandObserverInterface_ObservableCommandInvoked_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CommandObserverInterface::ObservableCommandPrepareInfo() const -> maxon::ObservableRef<ObservableCommandPrepareInfoDelegate>
{
	const CommandObserverInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(CommandObserverInterface, this); return mt_.CommandObserverInterface_ObservableCommandPrepareInfo((const maxon::GenericComponent*) this + mt_.CommandObserverInterface_ObservableCommandPrepareInfo_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CommandObserverInterface::ObservableCommandInvokedInfo() const -> maxon::ObservableRef<ObservableCommandInvokedInfoDelegate>
{
	const CommandObserverInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(CommandObserverInterface, this); return mt_.CommandObserverInterface_ObservableCommandInvokedInfo((const maxon::GenericComponent*) this + mt_.CommandObserverInterface_ObservableCommandInvokedInfo_Offset);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CommandObserverInterface::Hxx1::ConstFn<S>::ObservableCommandStatus() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<maxon::ObservableRef<ObservableCommandStatusDelegate>>, maxon::ObservableRef<ObservableCommandStatusDelegate>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<maxon::ObservableRef<ObservableCommandStatusDelegate>>, maxon::ObservableRef<ObservableCommandStatusDelegate>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const CommandObserverInterface* o_ = (const CommandObserverInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = CommandObserverInterface::NullValuePtr(); if (!o_) return maxon::ObservableRef<ObservableCommandStatusDelegate>::NullValue(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CommandObserverInterface, o_, CommandObserverInterface_ObservableCommandStatus) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<CommandObserverInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CommandObserverInterface>() : PRIVATE_MAXON_VTABLE(CommandObserverInterface, o_); 
	return (mt_.CommandObserverInterface_ObservableCommandStatus(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.CommandObserverInterface_ObservableCommandStatus_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CommandObserverInterface::Hxx1::ConstFn<S>::ObservableCommandInvoked() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<maxon::ObservableRef<ObservableCommandInvokedDelegate>>, maxon::ObservableRef<ObservableCommandInvokedDelegate>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<maxon::ObservableRef<ObservableCommandInvokedDelegate>>, maxon::ObservableRef<ObservableCommandInvokedDelegate>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const CommandObserverInterface* o_ = (const CommandObserverInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = CommandObserverInterface::NullValuePtr(); if (!o_) return maxon::ObservableRef<ObservableCommandInvokedDelegate>::NullValue(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CommandObserverInterface, o_, CommandObserverInterface_ObservableCommandInvoked) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<CommandObserverInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CommandObserverInterface>() : PRIVATE_MAXON_VTABLE(CommandObserverInterface, o_); 
	return (mt_.CommandObserverInterface_ObservableCommandInvoked(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.CommandObserverInterface_ObservableCommandInvoked_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CommandObserverInterface::Hxx1::ConstFn<S>::ObservableCommandPrepareInfo() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<maxon::ObservableRef<ObservableCommandPrepareInfoDelegate>>, maxon::ObservableRef<ObservableCommandPrepareInfoDelegate>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<maxon::ObservableRef<ObservableCommandPrepareInfoDelegate>>, maxon::ObservableRef<ObservableCommandPrepareInfoDelegate>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const CommandObserverInterface* o_ = (const CommandObserverInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = CommandObserverInterface::NullValuePtr(); if (!o_) return maxon::ObservableRef<ObservableCommandPrepareInfoDelegate>::NullValue(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CommandObserverInterface, o_, CommandObserverInterface_ObservableCommandPrepareInfo) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<CommandObserverInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CommandObserverInterface>() : PRIVATE_MAXON_VTABLE(CommandObserverInterface, o_); 
	return (mt_.CommandObserverInterface_ObservableCommandPrepareInfo(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.CommandObserverInterface_ObservableCommandPrepareInfo_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CommandObserverInterface::Hxx1::ConstFn<S>::ObservableCommandInvokedInfo() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<maxon::ObservableRef<ObservableCommandInvokedInfoDelegate>>, maxon::ObservableRef<ObservableCommandInvokedInfoDelegate>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<maxon::ObservableRef<ObservableCommandInvokedInfoDelegate>>, maxon::ObservableRef<ObservableCommandInvokedInfoDelegate>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const CommandObserverInterface* o_ = (const CommandObserverInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = CommandObserverInterface::NullValuePtr(); if (!o_) return maxon::ObservableRef<ObservableCommandInvokedInfoDelegate>::NullValue(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CommandObserverInterface, o_, CommandObserverInterface_ObservableCommandInvokedInfo) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<CommandObserverInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CommandObserverInterface>() : PRIVATE_MAXON_VTABLE(CommandObserverInterface, o_); 
	return (mt_.CommandObserverInterface_ObservableCommandInvokedInfo(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.CommandObserverInterface_ObservableCommandInvokedInfo_Offset));
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

