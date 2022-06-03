#if 1
class CommandObserverRef;

struct CommandObserverInterface::HasBaseDetector { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, CommandObserverInterface>::value || ObserverObjectInterface::HasBaseDetector::template Check<I>::value; static I* Cast(CommandObserverInterface* ptr) { return reinterpret_cast<I*>(ptr); } }; };
struct CommandObserverInterface::Hxx1
{
	class Reference;
	using ReferenceClass = CommandObserverRef;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<ObserverObjectInterface>;
	/// Intermediate helper class for CommandObserverInterface.
	template <typename S> class ConstFn DOXYGEN_SWITCH_REVERSED(, : public S)
	{
	public:
		ConstFn() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateBaseClass::PrivateLookupFn;
		static ConstFn PrivateLookupFn(CommandObserverInterface**);
/// ObservableCommandStatus can be sent from each command to update the progress of the command execution.
/// Can be subscribed for example to update status bars.
/// -param[in] commandId					The command id.
/// -param[in] statusMessage			A dictionary containing the status messages.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<maxon::ObservableRef<ObservableCommandStatusDelegate>>, maxon::ObservableRef<ObservableCommandStatusDelegate>>::type ObservableCommandStatus() const;
/// ObservableCommandInvoked is sent by the command system whenever a command is invoked.
/// -param[in] commandId					The command id.
/// -param[in] result							The result of the command invocation.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<maxon::ObservableRef<ObservableCommandInvokedDelegate>>, maxon::ObservableRef<ObservableCommandInvokedDelegate>>::type ObservableCommandInvoked() const;
/// ObservableCommandPrepareInfo is sent by the command system between the GetState and the Execute calls.
/// -param[in] commandId					The command id.
/// -param[in] data								The command data.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<maxon::ObservableRef<ObservableCommandPrepareInfoDelegate>>, maxon::ObservableRef<ObservableCommandPrepareInfoDelegate>>::type ObservableCommandPrepareInfo() const;
/// ObservableCommandInvokedInfo is sent by the command system at each stage of the command invokation.
/// -param[in] commandId					The command id.
/// -param[in] result							The result of the command invocation.
/// -param[in] data								The command data.
/// -param[in] interactionState		The stage of interaction.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<maxon::ObservableRef<ObservableCommandInvokedInfoDelegate>>, maxon::ObservableRef<ObservableCommandInvokedInfoDelegate>>::type ObservableCommandInvokedInfo() const;
	};
	/// Intermediate helper class for CommandObserverInterface.
	template <typename S> class Fn : public ConstFn<S>
	{
	public:
		Fn() = default;
		using PrivateBaseClass = ConstFn<S>;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateBaseClass::PrivateLookupFn;
		static Fn PrivateLookupFn(CommandObserverInterface**);
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, CommandObserverRef, true>::type&() const { return reinterpret_cast<const CommandObserverRef&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, CommandObserverRef, false>::type&() { return reinterpret_cast<const CommandObserverRef&>(this->GetBaseRef()); }
	};
	/// Intermediate helper class for CommandObserverInterface.
	template <typename S> class COWFn : public ConstFn<S>
	{
	public:
		COWFn() = default;
		using PrivateBaseClass = ConstFn<S>;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateBaseClass::PrivateLookupFn;
		static COWFn PrivateLookupFn(CommandObserverInterface**);
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, CommandObserverRef, false>::type&() { return reinterpret_cast<const CommandObserverRef&>(this->GetBaseRef()); }
	};
	template <typename ST> struct FnHelper : public std::conditional<
	maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)),
	COWFn<typename ObserverObjectInterface::Hxx1::template FnHelper<ST>::type>,
	typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstFn<typename ObserverObjectInterface::Hxx1::template FnHelper<ST>::type>, Fn<typename ObserverObjectInterface::Hxx1::template FnHelper<ST>::type>>::type
	> { };
};
class CommandObserverInterface::Hxx1::Reference :
#ifdef DOXYGEN
public FnDoxy<CommandObserverRef>
#else
public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<CommandObserverInterface, maxon::StrongRefHandler, CommandObserverRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<CommandObserverInterface, maxon::StrongRefHandler, CommandObserverRef>>>>);
	using NonConst = typename Super::ReferenceClass;
};

/// CommandObserverRef is the reference class of CommandObserverInterface.
///
/// Implements Observables for the command system.
class CommandObserverRef : public CommandObserverInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(CommandObserverRef, typename CommandObserverInterface::Hxx1::Reference);
	using ConstPtr = typename CommandObserverInterface::ConstPtr;
};

class CommandObserverInterface::ObservableCommandStatusDelegate : public maxon::Delegate<Result<void>(const Id&,const DataDictionary&)>
{
public:
	using Super = maxon::Delegate<Result<void>(const Id&,const DataDictionary&)>;
	MAXON_MEMBERFUNCTION_DETECTOR(HandleCommandStatus);
	ObservableCommandStatusDelegate() = default;
	template <typename FN> static maxon::ResultOk<Super> Create(FN&& src, typename std::enable_if<HasHandleCommandStatus<typename maxon::Dereference<typename std::decay<FN>::type, false>::type>::value, void>::type* = nullptr) { return Super::CreateByReference(std::forward<FN>(src), &maxon::Dereference<typename std::decay<FN>::type, false>::type::HandleCommandStatus); }
	template <typename FN> static maxon::Result<Super> Create(FN&& src, typename std::enable_if<!HasHandleCommandStatus<typename maxon::Dereference<typename std::decay<FN>::type, false>::type>::value, void>::type* = nullptr){ return Super::Create(std::forward<FN>(src)); }
	using OBSERVABLECOMBINER = ObservableCombinerRunAllComponentPrivateHelper;
};

class CommandObserverInterface::ObservableCommandInvokedDelegate : public maxon::Delegate<Result<void>(const Id&,const Result<COMMANDRESULT>&)>
{
public:
	using Super = maxon::Delegate<Result<void>(const Id&,const Result<COMMANDRESULT>&)>;
	MAXON_MEMBERFUNCTION_DETECTOR(HandleCommandInvoked);
	ObservableCommandInvokedDelegate() = default;
	template <typename FN> static maxon::ResultOk<Super> Create(FN&& src, typename std::enable_if<HasHandleCommandInvoked<typename maxon::Dereference<typename std::decay<FN>::type, false>::type>::value, void>::type* = nullptr) { return Super::CreateByReference(std::forward<FN>(src), &maxon::Dereference<typename std::decay<FN>::type, false>::type::HandleCommandInvoked); }
	template <typename FN> static maxon::Result<Super> Create(FN&& src, typename std::enable_if<!HasHandleCommandInvoked<typename maxon::Dereference<typename std::decay<FN>::type, false>::type>::value, void>::type* = nullptr){ return Super::Create(std::forward<FN>(src)); }
	using OBSERVABLECOMBINER = ObservableCombinerRunAllComponentPrivateHelper;
};

class CommandObserverInterface::ObservableCommandPrepareInfoDelegate : public maxon::Delegate<Result<void>(const Id&,const CommandDataRef&)>
{
public:
	using Super = maxon::Delegate<Result<void>(const Id&,const CommandDataRef&)>;
	MAXON_MEMBERFUNCTION_DETECTOR(HandleCommandPrepareInfo);
	ObservableCommandPrepareInfoDelegate() = default;
	template <typename FN> static maxon::ResultOk<Super> Create(FN&& src, typename std::enable_if<HasHandleCommandPrepareInfo<typename maxon::Dereference<typename std::decay<FN>::type, false>::type>::value, void>::type* = nullptr) { return Super::CreateByReference(std::forward<FN>(src), &maxon::Dereference<typename std::decay<FN>::type, false>::type::HandleCommandPrepareInfo); }
	template <typename FN> static maxon::Result<Super> Create(FN&& src, typename std::enable_if<!HasHandleCommandPrepareInfo<typename maxon::Dereference<typename std::decay<FN>::type, false>::type>::value, void>::type* = nullptr){ return Super::Create(std::forward<FN>(src)); }
	using OBSERVABLECOMBINER = ObservableCombinerRunAllComponentPrivateHelper;
};

class CommandObserverInterface::ObservableCommandInvokedInfoDelegate : public maxon::Delegate<Result<void>(const Id&,const Result<COMMANDRESULT>&,const CommandDataRef&,const InvocationState&)>
{
public:
	using Super = maxon::Delegate<Result<void>(const Id&,const Result<COMMANDRESULT>&,const CommandDataRef&,const InvocationState&)>;
	MAXON_MEMBERFUNCTION_DETECTOR(HandleCommandInvokedInfo);
	ObservableCommandInvokedInfoDelegate() = default;
	template <typename FN> static maxon::ResultOk<Super> Create(FN&& src, typename std::enable_if<HasHandleCommandInvokedInfo<typename maxon::Dereference<typename std::decay<FN>::type, false>::type>::value, void>::type* = nullptr) { return Super::CreateByReference(std::forward<FN>(src), &maxon::Dereference<typename std::decay<FN>::type, false>::type::HandleCommandInvokedInfo); }
	template <typename FN> static maxon::Result<Super> Create(FN&& src, typename std::enable_if<!HasHandleCommandInvokedInfo<typename maxon::Dereference<typename std::decay<FN>::type, false>::type>::value, void>::type* = nullptr){ return Super::Create(std::forward<FN>(src)); }
	using OBSERVABLECOMBINER = ObservableCombinerRunAllComponentPrivateHelper;
};

constexpr inline const maxon::Char* DT_InvocationState_CppName() { return "maxon::InvocationState"; }
#endif
