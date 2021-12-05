#if 1
class SystemProcessKilledError;

struct SystemProcessKilledErrorInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, SystemProcessKilledErrorInterface>::value || ErrorInterface::HasBase::template Check<I>::value; static I* Cast(SystemProcessKilledErrorInterface* ptr) { return static_cast<I*>(static_cast<maxon::ObjectInterface*>(ptr)); } }; };
struct SystemProcessKilledErrorObjectPrivateHelper;
struct SystemProcessKilledErrorInterface::Hxx1
{
	class Reference;
	class NonConstRef;
	using ErrObj = SystemProcessKilledErrorObjectPrivateHelper;
	using ReferenceClass = SystemProcessKilledError;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<ErrorInterface>;
	/// Intermediate helper class for SystemProcessKilledErrorInterface.
	template <typename S> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
	{
	public:
		ConstReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
	};
	/// Intermediate helper class for SystemProcessKilledErrorInterface.
	template <typename S> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
	};
	/// Intermediate helper class for SystemProcessKilledErrorInterface.
	template <typename S> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, SystemProcessKilledError, false>::type&() const { return reinterpret_cast<const SystemProcessKilledError&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, SystemProcessKilledError, false>::type&() { return reinterpret_cast<const SystemProcessKilledError&>(this->GetBaseRef()); }
	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename ErrorInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename ErrorInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, ReferenceFunctionsImpl<typename ErrorInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>>::type> { };
};
class SystemProcessKilledErrorInterface::Hxx1::Reference :
#ifdef DOXYGEN
public COWReferenceFunctionsImplDoxy<SystemProcessKilledError>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const SystemProcessKilledErrorInterface, maxon::StrongCOWRefHandler, SystemProcessKilledError>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const SystemProcessKilledErrorInterface, maxon::StrongCOWRefHandler, SystemProcessKilledError>>>>);
	using NonConst = Hxx1::NonConstRef;
};

class SystemProcessKilledErrorInterface::Hxx1::NonConstRef :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<NonConstRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<SystemProcessKilledErrorInterface, maxon::StrongRefHandler, NonConstRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<SystemProcessKilledErrorInterface, maxon::StrongRefHandler, NonConstRef>>>>);
};

/// SystemProcessKilledError is the reference class of SystemProcessKilledErrorInterface.
///
/// System Process has been killed by a signal. E.g. process crashed or killed by user.
class SystemProcessKilledError : public SystemProcessKilledErrorInterface::Hxx1::Reference
{
public:
	friend class SystemProcessKilledErrorObject;
	friend class maxon::ResultBase<SystemProcessKilledError>;
	SystemProcessKilledError(maxon::ERROR_OK) { }
	PRIVATE_MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(SystemProcessKilledError, typename SystemProcessKilledErrorInterface::Hxx1::Reference);
	template <typename D> SystemProcessKilledError(const D& allocLocation, typename D::SourceLocationMarker* dummy = nullptr) { maxon::SFINAEHelper<SystemProcessKilledError, D>::type::Create(MAXON_SOURCE_LOCATION_FORWARD); }
	template <typename ARG1, typename... ARGS> SystemProcessKilledError(MAXON_SOURCE_LOCATION_DECLARATION, ARG1&& arg1, ARGS&&... args) { maxon::SFINAEHelper<SystemProcessKilledError, ARG1>::type::Create(MAXON_SOURCE_LOCATION_FORWARD, std::forward<ARG1>(arg1), std::forward<ARGS>(args)...); }
private:
	SystemProcessKilledError() = default;
};

MAXON_DECLARATION(SystemProcessKilledError, SystemProcessKilledErrorObject, "net.maxon.error.systemprocesskilled");
class SystemProcessOperationError;

struct SystemProcessOperationErrorInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, SystemProcessOperationErrorInterface>::value || ErrorInterface::HasBase::template Check<I>::value; static I* Cast(SystemProcessOperationErrorInterface* ptr) { return static_cast<I*>(static_cast<maxon::ObjectInterface*>(ptr)); } }; };
struct SystemProcessOperationErrorObjectPrivateHelper;
struct SystemProcessOperationErrorInterface::Hxx1
{
	class Reference;
	class NonConstRef;
	using ErrObj = SystemProcessOperationErrorObjectPrivateHelper;
	using ReferenceClass = SystemProcessOperationError;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<ErrorInterface>;
	/// Intermediate helper class for SystemProcessOperationErrorInterface.
	template <typename S> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
	{
	public:
		ConstReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
	};
	/// Intermediate helper class for SystemProcessOperationErrorInterface.
	template <typename S> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
	};
	/// Intermediate helper class for SystemProcessOperationErrorInterface.
	template <typename S> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, SystemProcessOperationError, false>::type&() const { return reinterpret_cast<const SystemProcessOperationError&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, SystemProcessOperationError, false>::type&() { return reinterpret_cast<const SystemProcessOperationError&>(this->GetBaseRef()); }
	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename ErrorInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename ErrorInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, ReferenceFunctionsImpl<typename ErrorInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>>::type> { };
};
class SystemProcessOperationErrorInterface::Hxx1::Reference :
#ifdef DOXYGEN
public COWReferenceFunctionsImplDoxy<SystemProcessOperationError>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const SystemProcessOperationErrorInterface, maxon::StrongCOWRefHandler, SystemProcessOperationError>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const SystemProcessOperationErrorInterface, maxon::StrongCOWRefHandler, SystemProcessOperationError>>>>);
	using NonConst = Hxx1::NonConstRef;
};

class SystemProcessOperationErrorInterface::Hxx1::NonConstRef :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<NonConstRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<SystemProcessOperationErrorInterface, maxon::StrongRefHandler, NonConstRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<SystemProcessOperationErrorInterface, maxon::StrongRefHandler, NonConstRef>>>>);
};

/// SystemProcessOperationError is the reference class of SystemProcessOperationErrorInterface.
///
/// System process operation failed.
class SystemProcessOperationError : public SystemProcessOperationErrorInterface::Hxx1::Reference
{
public:
	friend class SystemProcessOperationErrorObject;
	friend class maxon::ResultBase<SystemProcessOperationError>;
	SystemProcessOperationError(maxon::ERROR_OK) { }
	PRIVATE_MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(SystemProcessOperationError, typename SystemProcessOperationErrorInterface::Hxx1::Reference);
	template <typename D> SystemProcessOperationError(const D& allocLocation, typename D::SourceLocationMarker* dummy = nullptr) { maxon::SFINAEHelper<SystemProcessOperationError, D>::type::Create(MAXON_SOURCE_LOCATION_FORWARD); }
	template <typename ARG1, typename... ARGS> SystemProcessOperationError(MAXON_SOURCE_LOCATION_DECLARATION, ARG1&& arg1, ARGS&&... args) { maxon::SFINAEHelper<SystemProcessOperationError, ARG1>::type::Create(MAXON_SOURCE_LOCATION_FORWARD, std::forward<ARG1>(arg1), std::forward<ARGS>(args)...); }
private:
	SystemProcessOperationError() = default;
};

MAXON_DECLARATION(SystemProcessOperationError, SystemProcessOperationErrorObject, "net.maxon.error.systemprocessoperation");
class SystemProcessObjectRef;

struct SystemProcessObjectInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, SystemProcessObjectInterface>::value || ObserverObjectInterface::HasBase::template Check<I>::value; static I* Cast(SystemProcessObjectInterface* ptr) { return static_cast<I*>(static_cast<maxon::ObjectInterface*>(ptr)); } }; };
struct SystemProcessObjectInterface::Hxx1
{
	class Reference;
	using ReferenceClass = SystemProcessObjectRef;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<ObserverObjectInterface>;
	/// Intermediate helper class for SystemProcessObjectInterface.
	template <typename S> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
	{
	public:
		ConstReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
/// Returns the exit code of the execution. This is possible as soon as the process finished.
/// Note: The exit code under OS X only works for own child processes.
/// Under Windows the exit code is available for all processes.
/// @return												Returns the exit code of the process or (UInt)NOTOK if the process is still running.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type GetExitCode() const;
/// Returns whether the process is running or not.
/// @return												True if the process is running.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type IsRunning() const;
/// Returns the System Process Id.
/// @return												The system process id (pid).
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<UInt>, UInt>::type GetProcessId() const;
/// Returns the pointer to the windows process handle.
/// @return												Windows: HANDLE of the windows process. OS X: pid of the process.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<void*>, void*>::type GetProcessHandle() const;
/// Returns the file path to the executable.
/// Notes: Under windows the full path is only returned for processes that the user owns. System processes are only given by name.
/// Under OS X the name is limited to the first 10 characters at the moment.
/// @return												File name of the executable.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Url>, Url>::type GetProcessUrl() const;
/// Returns the path of the captured logfile.
/// @return												Return the log file path. If the process was not created using EXECUTEPROGRAMFLAGS::CAPTURELOGFILE an empty name is returned.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Url>, Url>::type GetLogFile() const;
/// Returns the user data connected to this process. See SystemProcessInterface::CreateProcess().
/// @return												Return the pointer to the user data of this process.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<void*>, void*>::type GetUserData() const;
/// Gets an array of all loaded dlls for this process.
/// @return												OK on success.
		inline Result<void> GetLoadedDlls(const ValueReceiver<const DllRef&>& dlls) const;
/// Signal that the process finished execution. Make sure that you add this notification before you
/// start the process, otherwise it could be too late if the process already ended.
/// -param[in] sender							Reference to the SystemProcessObjectRef which has been finished.
/// @return												ObservableRef to operate on.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<maxon::ObservableRef<ObservableProcessFinishedDelegate>>, maxon::ObservableRef<ObservableProcessFinishedDelegate>>::type ObservableProcessFinished() const;
	};
	/// Intermediate helper class for SystemProcessObjectInterface.
	template <typename S> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, SystemProcessObjectRef, true>::type&() const { return reinterpret_cast<const SystemProcessObjectRef&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, SystemProcessObjectRef, false>::type&() { return reinterpret_cast<const SystemProcessObjectRef&>(this->GetBaseRef()); }
/// Executes the prepared process. This only works once. To start the same executable again you need to allocate another instance with the same settings.
/// @return												OK on success.
		inline Result<void> StartProcess() const;
/// Kills the process if it is still running. All child processes are also killed.
/// @return												OK on success. If the process was not running SystemProcessOperationError is returned.
		inline Result<void> KillProcess() const;
	};
	/// Intermediate helper class for SystemProcessObjectInterface.
	template <typename S> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, SystemProcessObjectRef, false>::type&() { return reinterpret_cast<const SystemProcessObjectRef&>(this->GetBaseRef()); }
/// Executes the prepared process. This only works once. To start the same executable again you need to allocate another instance with the same settings.
/// @return												OK on success.
		inline Result<void> StartProcess();
/// Kills the process if it is still running. All child processes are also killed.
/// @return												OK on success. If the process was not running SystemProcessOperationError is returned.
		inline Result<void> KillProcess();
	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename ObserverObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename ObserverObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, ReferenceFunctionsImpl<typename ObserverObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>>::type> { };
};
class SystemProcessObjectInterface::Hxx1::Reference :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<SystemProcessObjectRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<SystemProcessObjectInterface, maxon::StrongRefHandler, SystemProcessObjectRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<SystemProcessObjectInterface, maxon::StrongRefHandler, SystemProcessObjectRef>>>>);
	using NonConst = typename Super::ReferenceClass;
};

/// SystemProcessObjectRef is the reference class of SystemProcessObjectInterface.
///
/// SystemProcessObjectInterface
class SystemProcessObjectRef : public SystemProcessObjectInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(SystemProcessObjectRef, typename SystemProcessObjectInterface::Hxx1::Reference);
};

class SystemProcessObjectInterface::ObservableProcessFinishedDelegate : public maxon::Delegate<void(const SystemProcessObjectRef&)>
{
public:
	using Super = maxon::Delegate<void(const SystemProcessObjectRef&)>;
	MAXON_MEMBERFUNCTION_DETECTOR(HandleProcessFinished);
	ObservableProcessFinishedDelegate() = default;
	template <typename FN> static maxon::ResultOk<Super> Create(FN&& src, typename std::enable_if<HasHandleProcessFinished<typename maxon::Dereference<typename std::decay<FN>::type, false>::type>::value, void>::type* = nullptr) { return Super::CreateByReference(std::forward<FN>(src), &maxon::Dereference<typename std::decay<FN>::type, false>::type::HandleProcessFinished); }
	template <typename FN> static maxon::Result<Super> Create(FN&& src, typename std::enable_if<!HasHandleProcessFinished<typename maxon::Dereference<typename std::decay<FN>::type, false>::type>::value, void>::type* = nullptr){ return Super::Create(std::forward<FN>(src)); }
	using OBSERVABLECOMBINER = ObservableCombinerRunAllComponentPrivateHelper;
};

#endif
