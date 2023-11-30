#if 1
class MachineRef;

struct MachineInterface::HasBaseDetector { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, MachineInterface>::value || ObserverObjectInterface::HasBaseDetector::template Check<I>::value; static I* Cast(MachineInterface* ptr) { return reinterpret_cast<I*>(ptr); } }; };
struct MachineInterface::Hxx1
{
	class Reference;
	using ReferenceClass = MachineRef;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<ObserverObjectInterface>;
	/// Intermediate helper class for MachineInterface.
	template <typename S> class ConstFn DOXYGEN_SWITCH_REVERSED(, : public S)
	{
	public:
		ConstFn() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateInterface = MachineInterface;
		using PrivateBaseClass::PrivateLookupFn;
		static ConstFn PrivateLookupFn(MachineInterface**);
/// Returns the service name of the local machine.
/// This name is a unique name which allows to identify the machine.
		inline HXXADDRET2(String) GetUniqueId() const;
/// Returns information about the system and processor.
/// See maxon::MACHINEINFO for DataDictionary properties.
		inline Result<DataDictionary> GetMachineInfo() const;
/// Returns the machine state of the given machine. See MACHINEINFO for details.
		inline HXXADDRET2(MACHINESTATE) GetState() const;
/// Returns a readable string of the content.
/// @param[in] formatStatement		Nullptr or additional formatting instruction. Use "{N}" for nive formatting of the name only. Otherwise the unique id is printed together with the name.
/// @return												The converted result.
		inline HXXADDRET2(String) ToString(const FormatStatement* formatStatement = nullptr) const;
		inline HXXADDRET2(maxon::ObservableRef<ObservablePrivateSplashMessageReceivedDelegate>) ObservablePrivateSplashMessageReceived(Bool create) const;
/// The activation status of the machine changed e.g. the user clicked onto another application
/// When the app is becoming inactive you can e.g. idle some computations
		inline HXXADDRET2(maxon::ObservableRef<ObservableActivationChangedDelegate>) ObservableActivationChanged(Bool create) const;
	};
	/// Intermediate helper class for MachineInterface.
	template <typename S> class Fn : public ConstFn<S>
	{
	public:
		Fn() = default;
		using PrivateBaseClass = ConstFn<S>;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateInterface = MachineInterface;
		using PrivateBaseClass::PrivateLookupFn;
		static Fn PrivateLookupFn(MachineInterface**);
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
		inline HXXADDRET2(Bool) SetState(MACHINESTATE stateMask, MACHINESTATE stateFlags) const;
	};
	/// Intermediate helper class for MachineInterface.
	template <typename S> class COWFn : public ConstFn<S>
	{
	public:
		COWFn() = default;
		using PrivateBaseClass = ConstFn<S>;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateInterface = MachineInterface;
		using PrivateBaseClass::PrivateLookupFn;
		static COWFn PrivateLookupFn(MachineInterface**);
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
		inline HXXADDRET1(Bool) SetState(MACHINESTATE stateMask, MACHINESTATE stateFlags);
	};
	template <typename ST> struct FnHelper : public std::conditional<
	maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)),
	COWFn<typename ObserverObjectInterface::Hxx1::template FnHelper<ST>::type>,
	typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstFn<typename ObserverObjectInterface::Hxx1::template FnHelper<ST>::type>, Fn<typename ObserverObjectInterface::Hxx1::template FnHelper<ST>::type>>::type
	> { };
};
class MachineInterface::Hxx1::Reference :
#ifdef DOXYGEN
public FnDoxy<MachineRef>
#else
public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<MachineInterface, maxon::StrongRefHandler, MachineRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<MachineInterface, maxon::StrongRefHandler, MachineRef>>>>);
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
	using ConstPtr = typename MachineInterface::ConstPtr;
};

class MachineInterface::ObservablePrivateSplashMessageReceivedDelegate : public maxon::Delegate<void(const MachineRef&,const DataDictionary&)>
{
public:
	using Super = maxon::Delegate<void(const MachineRef&,const DataDictionary&)>;
	MAXON_MEMBERFUNCTION_DETECTOR(HandlePrivateSplashMessageReceived);
	ObservablePrivateSplashMessageReceivedDelegate() = default;
	template <typename FN> static maxon::ResultOk<Super> Create(FN&& src, typename std::enable_if<HasHandlePrivateSplashMessageReceived<typename maxon::Dereference<typename std::decay<FN>::type, false>::type>::value, void>::type* = nullptr) { return Super::CreateByReference(std::forward<FN>(src), &maxon::Dereference<typename std::decay<FN>::type, false>::type::HandlePrivateSplashMessageReceived); }
	template <typename FN> static maxon::Result<Super> Create(FN&& src, typename std::enable_if<!HasHandlePrivateSplashMessageReceived<typename maxon::Dereference<typename std::decay<FN>::type, false>::type>::value, void>::type* = nullptr){ return Super::Create(std::forward<FN>(src)); }
	using OBSERVABLECOMBINER = ObservableCombinerRunAllComponent_PrivateHelper;
};

class MachineInterface::ObservableActivationChangedDelegate : public maxon::Delegate<void(const MachineRef&,Bool)>
{
public:
	using Super = maxon::Delegate<void(const MachineRef&,Bool)>;
	MAXON_MEMBERFUNCTION_DETECTOR(HandleActivationChanged);
	ObservableActivationChangedDelegate() = default;
	template <typename FN> static maxon::ResultOk<Super> Create(FN&& src, typename std::enable_if<HasHandleActivationChanged<typename maxon::Dereference<typename std::decay<FN>::type, false>::type>::value, void>::type* = nullptr) { return Super::CreateByReference(std::forward<FN>(src), &maxon::Dereference<typename std::decay<FN>::type, false>::type::HandleActivationChanged); }
	template <typename FN> static maxon::Result<Super> Create(FN&& src, typename std::enable_if<!HasHandleActivationChanged<typename maxon::Dereference<typename std::decay<FN>::type, false>::type>::value, void>::type* = nullptr){ return Super::Create(std::forward<FN>(src)); }
	using OBSERVABLECOMBINER = ObservableCombinerRunAllComponent_PrivateHelper;
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
	using OBSERVABLECOMBINER = ObservableCombinerRunAllComponent_PrivateHelper;
};

namespace MACHINE_MESSAGE
{
#ifndef PRIVATE_MAXON_GUARD_maxon_MACHINE_MESSAGE
#define PRIVATE_MAXON_GUARD_maxon_MACHINE_MESSAGE
	class RESTRICT : public maxon::RESTRICT { }; template <typename T> RESTRICT TestRestriction(T y, maxon::OverloadRank1);
#endif
	namespace MSG_INITIALIZATION_FINISHED
	{
	#ifndef PRIVATE_MAXON_GUARD_maxon_MACHINE_MESSAGE_MSG_INITIALIZATION_FINISHED
	#define PRIVATE_MAXON_GUARD_maxon_MACHINE_MESSAGE_MSG_INITIALIZATION_FINISHED
		class RESTRICT : public MACHINE_MESSAGE::RESTRICT { }; template <typename T> RESTRICT TestRestriction(T y, maxon::OverloadRank1);
	#endif
	}
}
#ifndef MAXON_COMPILER_CLANG
#endif
constexpr inline const maxon::Char* DT_CreateObjectRefFunc_CppName() { return "maxon::CreateObjectRefFunc"; }
#endif
