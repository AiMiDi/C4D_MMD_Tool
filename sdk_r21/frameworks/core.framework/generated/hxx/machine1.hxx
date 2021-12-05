#if 1
class MachineRef;

struct MachineInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, MachineInterface>::value || ObserverObjectInterface::HasBase::template Check<I>::value; static I* Cast(MachineInterface* ptr) { return static_cast<I*>(static_cast<maxon::ObjectInterface*>(ptr)); } }; };
struct MachineInterface::Hxx1
{
	class Reference;
	using ReferenceClass = MachineRef;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<ObserverObjectInterface>;
	/// Intermediate helper class for MachineInterface.
	template <typename S> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
	{
	public:
		ConstReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
/// Returns the service name of the local machine.
/// This name is a unique name which allows to identify the machine.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type GetUniqueId() const;
/// Returns information about the system and processor.
/// See maxon::MACHINEINFO for DataDictionary properties.
		inline Result<DataDictionary> GetMachineInfo() const;
/// Returns the machine state of the given machine. See MACHINEINFO for details.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<MACHINESTATE>, MACHINESTATE>::type GetState() const;
/// Returns a readable string of the content.
/// @param[in] formatStatement		Nullptr or additional formatting instruction. Use "{N}" for nive formatting of the name only. Otherwise the unique id is printed together with the name.
/// @return												The converted result.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type ToString(const FormatStatement* formatStatement) const;
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<maxon::ObservableRef<ObservableMessageReceivedDelegate>>, maxon::ObservableRef<ObservableMessageReceivedDelegate>>::type ObservableMessageReceived() const;
	};
	/// Intermediate helper class for MachineInterface.
	template <typename S> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, MachineRef, true>::type&() const { return reinterpret_cast<const MachineRef&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, MachineRef, false>::type&() { return reinterpret_cast<const MachineRef&>(this->GetBaseRef()); }
/// Returns a interface of this machine. E.g. write OSClipboardRef clipboard = machine.GetInterface<OSClipboardRef>(); to get the clipboard interface handle.
/// Don't use the Interface function but the overloaded NetworkRPCMachine::GetInterface<>() template instead.
/// THREADSAFE.
/// It automatically detects the interfaceName and casts the type.
/// @param[in] interfaceName			INTERFACE::_interface.GetId().
/// @return												If successful the handle to the interface is returned.
		inline Result<ObjectRef> GetInterface(const Id& interfaceName) const;
/// Returns a interface of a machine. e.g. write OSClipboardRef clipboard = machine.GetInterface<OSClipboardRef>(); to get the clipboard interface handle.
/// At the moment supported are: OSGuiRef, OSClipboardRef, GameServerRef, CaptureDeviceListRef, UpdaterRef.
/// @return												If the function is successful the handle to the interface is returned.
		template <typename INTERFACE> inline Result<INTERFACE> GetInterface() const;
/// ** private ** Sets the machine state of the given machine. This function should not be called by users. It's private for internal functions.
/// @param[in] stateMask					Mask of flags that should be changed.
/// @param[in] stateFlags					Values of flags that be set.
/// @return												True if the function succeeded.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type SetState(MACHINESTATE stateMask, MACHINESTATE stateFlags) const;
	};
	/// Intermediate helper class for MachineInterface.
	template <typename S> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, MachineRef, false>::type&() { return reinterpret_cast<const MachineRef&>(this->GetBaseRef()); }
/// Returns a interface of this machine. E.g. write OSClipboardRef clipboard = machine.GetInterface<OSClipboardRef>(); to get the clipboard interface handle.
/// Don't use the Interface function but the overloaded NetworkRPCMachine::GetInterface<>() template instead.
/// THREADSAFE.
/// It automatically detects the interfaceName and casts the type.
/// @param[in] interfaceName			INTERFACE::_interface.GetId().
/// @return												If successful the handle to the interface is returned.
		inline Result<ObjectRef> GetInterface(const Id& interfaceName);
/// Returns a interface of a machine. e.g. write OSClipboardRef clipboard = machine.GetInterface<OSClipboardRef>(); to get the clipboard interface handle.
/// At the moment supported are: OSGuiRef, OSClipboardRef, GameServerRef, CaptureDeviceListRef, UpdaterRef.
/// @return												If the function is successful the handle to the interface is returned.
		template <typename INTERFACE> inline Result<INTERFACE> GetInterface();
/// ** private ** Sets the machine state of the given machine. This function should not be called by users. It's private for internal functions.
/// @param[in] stateMask					Mask of flags that should be changed.
/// @param[in] stateFlags					Values of flags that be set.
/// @return												True if the function succeeded.
		inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Bool, maxon::Result<Bool>>::type SetState(MACHINESTATE stateMask, MACHINESTATE stateFlags);
	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename ObserverObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename ObserverObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, ReferenceFunctionsImpl<typename ObserverObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>>::type> { };
};
class MachineInterface::Hxx1::Reference :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<MachineRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<MachineInterface, maxon::StrongRefHandler, MachineRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<MachineInterface, maxon::StrongRefHandler, MachineRef>>>>);
	using NonConst = typename Super::ReferenceClass;
};

/// MachineRef is the reference class of MachineInterface.
///
/// This class is the entry point to access machine interfaces.
/// So there is no difference if the machine is running local or remote via rpc.
class MachineRef : public MachineInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(MachineRef, typename MachineInterface::Hxx1::Reference);
};

class MachineInterface::ObservableMessageReceivedDelegate : public maxon::Delegate<void(const MachineRef&,const DataDictionary&)>
{
public:
	using Super = maxon::Delegate<void(const MachineRef&,const DataDictionary&)>;
	MAXON_MEMBERFUNCTION_DETECTOR(HandleMessageReceived);
	ObservableMessageReceivedDelegate() = default;
	template <typename FN> static maxon::ResultOk<Super> Create(FN&& src, typename std::enable_if<HasHandleMessageReceived<typename maxon::Dereference<typename std::decay<FN>::type, false>::type>::value, void>::type* = nullptr) { return Super::CreateByReference(std::forward<FN>(src), &maxon::Dereference<typename std::decay<FN>::type, false>::type::HandleMessageReceived); }
	template <typename FN> static maxon::Result<Super> Create(FN&& src, typename std::enable_if<!HasHandleMessageReceived<typename maxon::Dereference<typename std::decay<FN>::type, false>::type>::value, void>::type* = nullptr){ return Super::Create(std::forward<FN>(src)); }
	using OBSERVABLECOMBINER = ObservableCombinerRunAllComponentPrivateHelper;
};

/// @cond INTERNAL

/// @endcond

/// @cond INTERNAL

/// @endcond

/// @cond INTERNAL

/// @endcond

class MachinesInterface::ObservableMachineStateChangedDelegate : public maxon::Delegate<void(const MachineRef&,MACHINESTATE,MACHINESTATE)>
{
public:
	using Super = maxon::Delegate<void(const MachineRef&,MACHINESTATE,MACHINESTATE)>;
	MAXON_MEMBERFUNCTION_DETECTOR(HandleMachineStateChanged);
	ObservableMachineStateChangedDelegate() = default;
	template <typename FN> static maxon::ResultOk<Super> Create(FN&& src, typename std::enable_if<HasHandleMachineStateChanged<typename maxon::Dereference<typename std::decay<FN>::type, false>::type>::value, void>::type* = nullptr) { return Super::CreateByReference(std::forward<FN>(src), &maxon::Dereference<typename std::decay<FN>::type, false>::type::HandleMachineStateChanged); }
	template <typename FN> static maxon::Result<Super> Create(FN&& src, typename std::enable_if<!HasHandleMachineStateChanged<typename maxon::Dereference<typename std::decay<FN>::type, false>::type>::value, void>::type* = nullptr){ return Super::Create(std::forward<FN>(src)); }
	using OBSERVABLECOMBINER = ObservableCombinerRunAllComponentPrivateHelper;
};

#ifndef MAXON_COMPILER_CLANG
#endif
#endif
