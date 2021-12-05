#if 1
class CommandObserverRef;

struct CommandObserverInterface::HasBaseDetector { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, CommandObserverInterface>::value || ObserverObjectInterface::HasBaseDetector::template Check<I>::value; static I* Cast(CommandObserverInterface* ptr) { return reinterpret_cast<I*>(ptr); } }; };
struct CommandObserverInterface::Hxx1
{
	class Reference;
	using ReferenceClass = CommandObserverRef;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<ObserverObjectInterface>;
	/// Intermediate helper class for CommandObserverInterface.
	template <typename S> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
	{
	public:
		ConstReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<maxon::ObservableRef<ObservableCommandStatusDelegate>>, maxon::ObservableRef<ObservableCommandStatusDelegate>>::type ObservableCommandStatus() const;
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<maxon::ObservableRef<ObservableCommandInvokedDelegate>>, maxon::ObservableRef<ObservableCommandInvokedDelegate>>::type ObservableCommandInvoked() const;
	};
	/// Intermediate helper class for CommandObserverInterface.
	template <typename S> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, CommandObserverRef, true>::type&() const { return reinterpret_cast<const CommandObserverRef&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, CommandObserverRef, false>::type&() { return reinterpret_cast<const CommandObserverRef&>(this->GetBaseRef()); }
	};
	/// Intermediate helper class for CommandObserverInterface.
	template <typename S> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, CommandObserverRef, false>::type&() { return reinterpret_cast<const CommandObserverRef&>(this->GetBaseRef()); }
	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<
	maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)),
	COWReferenceFunctionsImpl<typename ObserverObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>,
	typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename ObserverObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, ReferenceFunctionsImpl<typename ObserverObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>>::type
	> { };
};
class CommandObserverInterface::Hxx1::Reference :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<CommandObserverRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<CommandObserverInterface, maxon::StrongRefHandler, CommandObserverRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<CommandObserverInterface, maxon::StrongRefHandler, CommandObserverRef>>>>);
	using NonConst = typename Super::ReferenceClass;
};

/// CommandObserverRef is the reference class of CommandObserverInterface.
///
/// Implements Observable for commands.
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

#endif
