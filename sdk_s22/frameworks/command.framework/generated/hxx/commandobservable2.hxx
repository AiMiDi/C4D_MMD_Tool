
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
	PRIVATE_MAXON_IMPLEMENTS_CHECK(ObservableCommandStatus);
	static const maxon::Char* const _ids;
	static const maxon::Bool HAS_NONSTATIC = false;
	maxon::ObservableRef<ObservableCommandStatusDelegate> (*_CommandObserverInterface_ObservableCommandStatus) (const maxon::GenericComponent* this_);
	maxon::Int _CommandObserverInterface_ObservableCommandStatus_Offset;
	maxon::ObservableRef<ObservableCommandInvokedDelegate> (*_CommandObserverInterface_ObservableCommandInvoked) (const maxon::GenericComponent* this_);
	maxon::Int _CommandObserverInterface_ObservableCommandInvoked_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CommandObserverInterface, ObservableCommandStatus))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CommandObserverInterface, ObservableCommandStatus), W, MTable>::type::_CommandObserverInterface_ObservableCommandStatus;
			_CommandObserverInterface_ObservableCommandStatus = reinterpret_cast<const decltype(_CommandObserverInterface_ObservableCommandStatus)&>(ptr);
			_CommandObserverInterface_ObservableCommandStatus_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CommandObserverInterface, ObservableCommandInvoked))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CommandObserverInterface, ObservableCommandInvoked), W, MTable>::type::_CommandObserverInterface_ObservableCommandInvoked;
			_CommandObserverInterface_ObservableCommandInvoked = reinterpret_cast<const decltype(_CommandObserverInterface_ObservableCommandInvoked)&>(ptr);
			_CommandObserverInterface_ObservableCommandInvoked_Offset = offset;
		}
	}
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset)
	{
		if (!W::Implementation::PROXY && (!ObserverObjectInterface::MTable::template InitWithBases<W>(info, offset))) return false;
		MTable* vt = (MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, _interface); if (!vt) return false;
		vt->Init<W>(offset); return true;
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<CommandObserverInterface, typename ObserverObjectInterface::MTable::template CombinedMTable<S>>;
	PRIVATE_MAXON_COMPBASE(CommandObserverInterface);
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct CommandObserverInterface::Hxx2
{
	template <typename S> class Wrapper : public ObserverObjectInterface::Hxx2::template Wrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(ObservableCommandInvoked);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(ObservableCommandStatus);
	static maxon::ObservableRef<ObservableCommandStatusDelegate> _CommandObserverInterface_ObservableCommandStatus(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->ObservableCommandStatus(); }
	static maxon::ObservableRef<ObservableCommandInvokedDelegate> _CommandObserverInterface_ObservableCommandInvoked(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->ObservableCommandInvoked(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto CommandObserverInterface::ObservableCommandStatus() const -> maxon::ObservableRef<ObservableCommandStatusDelegate>
{
	const CommandObserverInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(CommandObserverInterface, this); return mt_._CommandObserverInterface_ObservableCommandStatus((const maxon::GenericComponent*) this + mt_._CommandObserverInterface_ObservableCommandStatus_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CommandObserverInterface::ObservableCommandInvoked() const -> maxon::ObservableRef<ObservableCommandInvokedDelegate>
{
	const CommandObserverInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(CommandObserverInterface, this); return mt_._CommandObserverInterface_ObservableCommandInvoked((const maxon::GenericComponent*) this + mt_._CommandObserverInterface_ObservableCommandInvoked_Offset);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CommandObserverInterface::Hxx1::ConstReferenceFunctionsImpl<S>::ObservableCommandStatus() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<maxon::ObservableRef<ObservableCommandStatusDelegate>>, maxon::ObservableRef<ObservableCommandStatusDelegate>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<maxon::ObservableRef<ObservableCommandStatusDelegate>>, maxon::ObservableRef<ObservableCommandStatusDelegate>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const CommandObserverInterface* o_ = (const CommandObserverInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = CommandObserverInterface::NullValuePtr(); if (!o_) return maxon::ObservableRef<ObservableCommandStatusDelegate>::NullValue(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CommandObserverInterface, o_, CommandObserverInterface_ObservableCommandStatus) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<CommandObserverInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CommandObserverInterface>() : PRIVATE_MAXON_VTABLE(CommandObserverInterface, o_); 
	return (mt_._CommandObserverInterface_ObservableCommandStatus(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._CommandObserverInterface_ObservableCommandStatus_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CommandObserverInterface::Hxx1::ConstReferenceFunctionsImpl<S>::ObservableCommandInvoked() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<maxon::ObservableRef<ObservableCommandInvokedDelegate>>, maxon::ObservableRef<ObservableCommandInvokedDelegate>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<maxon::ObservableRef<ObservableCommandInvokedDelegate>>, maxon::ObservableRef<ObservableCommandInvokedDelegate>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const CommandObserverInterface* o_ = (const CommandObserverInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = CommandObserverInterface::NullValuePtr(); if (!o_) return maxon::ObservableRef<ObservableCommandInvokedDelegate>::NullValue(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CommandObserverInterface, o_, CommandObserverInterface_ObservableCommandInvoked) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<CommandObserverInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CommandObserverInterface>() : PRIVATE_MAXON_VTABLE(CommandObserverInterface, o_); 
	return (mt_._CommandObserverInterface_ObservableCommandInvoked(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._CommandObserverInterface_ObservableCommandInvoked_Offset));
}
auto CommandObserverInterface::GetPtr() -> Ptr { return Ptr(this); }
auto CommandObserverInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
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

