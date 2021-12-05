#if 1
class LibraryRef;

#ifdef MAXON_TARGET_WINDOWS
#endif
struct LibraryInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, LibraryInterface>::value || ObjectInterface::HasBase::template Check<I>::value; static I* Cast(LibraryInterface* ptr) { return static_cast<I*>(static_cast<maxon::ObjectInterface*>(ptr)); } }; };
struct LibraryInterface::Hxx1
{
	class Reference;
	using ReferenceClass = LibraryRef;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<ObjectInterface>;
	/// Intermediate helper class for LibraryInterface.
	template <typename S> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
	{
	public:
		ConstReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
/// Checks if a console is attached to the current process
/// @return												True if a console is attached, otherwise False.
		static inline Bool ConsoleIsAvailable();
#ifdef MAXON_TARGET_WINDOWS
/// Returns the Visual Studio version of a given MSC compiler version.
/// @param[in] compilerVersion		Compiler version, e, g. MSC 1310.
/// @return												Visual Studio version number or returns an UnknownError, if the version is unknown.
		static inline Result<Int32> GetVsVersion(Int32 compilerVersion);
/// Returns the path to a runtime redistributable library by giving a Visual Studio version number and a flag if you need the release- or debug version.
/// This function does not look for known paths, or browses the disk. The path is only determined by browsing through all libraries which are already attached
/// to the current process. If the version number and the flag matches, the absolute path is returned.
/// E.g. version=2015, and release=True returns C:\Windows\System32\ucrtbase.dll on a 64-bit system.
/// E.g. version=2008, and release=True returns C:\Windows\System32\msvcr90.dll on a 64-bit system.
/// E.g. version=2010, and release=True returns C:\Windows\System32\msvcr100.dll on a 64-bit system.
/// @return												Absolute path to the given library, or an error is returned.
		static inline Result<Url> GetVsRuntimeLibrary(Int32 version, Bool release);
#endif
/// Returns the content of a given file in a string. The file is expected to be encoded in UTF-8.
/// @param[in] filepath						Path of the file.
/// @return												Content of the file in a string, or returns an error if reading failed.
		static inline Result<String> GetFileContent(const Url& filepath);
/// Writes the content of a string to a given file. The content will be encoded in UTF-8.
/// @param[in] filepath						Path of the file.
/// @param[in] str								Content to write.
/// @param[in] append							True to append the content to the file, or False to overwrite the entire content with the new string.
/// @return												Returns OK if the operation succeeded.
		static inline Result<void> SetFileContent(const Url& filepath, const String& str, Bool append);
	};
	/// Intermediate helper class for LibraryInterface.
	template <typename S> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, LibraryRef, true>::type&() const { return reinterpret_cast<const LibraryRef&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, LibraryRef, false>::type&() { return reinterpret_cast<const LibraryRef&>(this->GetBaseRef()); }
#ifdef MAXON_TARGET_WINDOWS
#endif
	};
	/// Intermediate helper class for LibraryInterface.
	template <typename S> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, LibraryRef, false>::type&() { return reinterpret_cast<const LibraryRef&>(this->GetBaseRef()); }
#ifdef MAXON_TARGET_WINDOWS
#endif
	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename ObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename ObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, ReferenceFunctionsImpl<typename ObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>>::type> { };
};
class LibraryInterface::Hxx1::Reference :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<LibraryRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<LibraryInterface, maxon::StrongRefHandler, LibraryRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<LibraryInterface, maxon::StrongRefHandler, LibraryRef>>>>);
	using NonConst = typename Super::ReferenceClass;
};

/// LibraryRef is the reference class of LibraryInterface.
///
/// A helper interface with convenient functions, which are needed when dealing with other
/// interfaces in this framework
class LibraryRef : public LibraryInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(LibraryRef, typename LibraryInterface::Hxx1::Reference);
	using ConstPtr = typename LibraryInterface::ConstPtr;
};

class VmDebuggerConnectionRef;

#ifdef MAXON_COMPILER_GCC
#endif
#ifdef MAXON_COMPILER_GCC
#endif
struct VmDebuggerConnectionInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, VmDebuggerConnectionInterface>::value || ObjectInterface::HasBase::template Check<I>::value; static I* Cast(VmDebuggerConnectionInterface* ptr) { return static_cast<I*>(static_cast<maxon::ObjectInterface*>(ptr)); } }; };
struct VmDebuggerConnectionInterface::Hxx1
{
	class Reference;
	using ReferenceClass = VmDebuggerConnectionRef;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<ObjectInterface>;
	/// Intermediate helper class for VmDebuggerConnectionInterface.
	template <typename S> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
	{
	public:
		ConstReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
/// Returns the name of the debugger connection.
/// @return												Name, e.g. PyDev
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type GetName() const;
/// Returns the path of the debugger. 
/// @return												Path to the debugger, allowed to be empty.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Url>, Url>::type GetPath() const;
#ifdef MAXON_COMPILER_GCC
#endif
/// The debugger shutdown code which gets executed in the target language, before the original script gets executed.
/// If the code fails executing, the error is printed to sys.stderr and the actual script will be executed regardless.
/// E.g. For Python:
/// @code
/// MAXON_METHOD String GetStartupScript() const
/// {
/// 	return String("try:\n"
/// 	             	"    import mydebugger\n"
/// 		            "    ptvsd.enable_attach(None)\n"
/// 		            "except:\n"
/// 		            "    mydebugger = None\n"  // before reraising the error, set ptvsd to None,
///                                            // so a check can be performed in the shutdown script
/// 		            "    raise\n"); // reraise only in case the current error should be printed to sys.stderr
/// }
/// @endcode
/// @return			Startup script, including \\n and 4-spaces. Can return an empty string.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type GetStartupScript() const;
/// The debugger shutdown code which gets executed in the target language, which gets executed after the actual script got executed.
/// If the code fails executing, the error is printed to sys.stderr.
/// E.g. For Python:
/// @code
/// MAXON_METHOD String GetShutdownScript() const
/// {
/// 	return String("if mydebugger:\n"
/// 		            "    mydebugger.shutdown()\n")
/// }
/// @endcode
/// @return			Shutdown script, including \\n and 4-spaces. Can return an empty string.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type GetShutdownScript() const;
#ifdef MAXON_COMPILER_GCC
#endif
	};
	/// Intermediate helper class for VmDebuggerConnectionInterface.
	template <typename S> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, VmDebuggerConnectionRef, true>::type&() const { return reinterpret_cast<const VmDebuggerConnectionRef&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, VmDebuggerConnectionRef, false>::type&() { return reinterpret_cast<const VmDebuggerConnectionRef&>(this->GetBaseRef()); }
#ifdef MAXON_COMPILER_GCC
#endif
#ifdef MAXON_COMPILER_GCC
#endif
	};
	/// Intermediate helper class for VmDebuggerConnectionInterface.
	template <typename S> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, VmDebuggerConnectionRef, false>::type&() { return reinterpret_cast<const VmDebuggerConnectionRef&>(this->GetBaseRef()); }
#ifdef MAXON_COMPILER_GCC
#endif
#ifdef MAXON_COMPILER_GCC
#endif
	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename ObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename ObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, ReferenceFunctionsImpl<typename ObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>>::type> { };
};
class VmDebuggerConnectionInterface::Hxx1::Reference :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<VmDebuggerConnectionRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<VmDebuggerConnectionInterface, maxon::StrongRefHandler, VmDebuggerConnectionRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<VmDebuggerConnectionInterface, maxon::StrongRefHandler, VmDebuggerConnectionRef>>>>);
	using NonConst = typename Super::ReferenceClass;
};

/// VmDebuggerConnectionRef is the reference class of VmDebuggerConnectionInterface.
class VmDebuggerConnectionRef : public VmDebuggerConnectionInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(VmDebuggerConnectionRef, typename VmDebuggerConnectionInterface::Hxx1::Reference);
	using ConstPtr = typename VmDebuggerConnectionInterface::ConstPtr;
};

class VirtualMachineScopeRef;

struct VirtualMachineScopeInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, VirtualMachineScopeInterface>::value || ObjectInterface::HasBase::template Check<I>::value; static I* Cast(VirtualMachineScopeInterface* ptr) { return static_cast<I*>(static_cast<maxon::ObjectInterface*>(ptr)); } }; };
struct VirtualMachineScopeInterface::Hxx1
{
	class Reference;
	using ReferenceClass = VirtualMachineScopeRef;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<ObjectInterface>;
	/// Intermediate helper class for VirtualMachineScopeInterface.
	template <typename S> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
	{
	public:
		ConstReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
	};
	/// Intermediate helper class for VirtualMachineScopeInterface.
	template <typename S> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, VirtualMachineScopeRef, true>::type&() const { return reinterpret_cast<const VirtualMachineScopeRef&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, VirtualMachineScopeRef, false>::type&() { return reinterpret_cast<const VirtualMachineScopeRef&>(this->GetBaseRef()); }
/// Initialized the virtual machine scope. Needs to be executed before any other function of the interface is used.
/// @param[in] identifier					Human readable unique identifier. Depending on the engine, some exception handlers might print this into their exception to
/// 															make it easier to understand where the exception comes from.
/// @param[in] code								Code to be executed.
/// @param[in] errorHandling			Adjust how the virtual machine should treat an exception.
/// @param[in] debug							Optional virtual machine debugger connection, to debug the code.
		inline Result<void> Init(const String& identifier, const String& code, ERRORHANDLING errorHandling, const VmDebuggerConnectionRef* debug = nullptr) const;
/// Add an object to the scope. The Data object will be converted through the underlying library implementation. So the Data object must be representable in the target virtual machine.
/// @param[in] name								Variable name of the object in the scope.
/// @param[in] data								Object that will be added to the scope.
/// @return												Return state, depending on VirtualMachineScopeInterface::Init(errorHandling).
		inline Result<void> Add(const String& name, const Data& data) const;
/// Returns an object from the scope.
/// @param[in] name								Variable name of the object in the scope.
/// @return												Requested object or error.
		inline Result<Data> Get(const String& name) const;
/// Execute the virtual machine scope. Before, and after executing the code, the optionally given debugger code from the VmDebuggerConnection will be executed.
/// @return												Return state, depending on VirtualMachineScopeInterface::Init(errorHandling).
		inline Result<void> Execute() const;
/// Executes a callable object from the scope. Must only be called after VirtualMachineScopeInterface.Execute.
/// @param[in] name								Name of the callable object, e.g a function name
/// @param[in] helperStack				A temporary helper stack for the return value.
/// @param[in] expected						(Optional) Datatype of the returned object, otherwise the type of the object will be chosen automatically.
/// @param[in] arguments					(Optional) Arguments which will be passed to the callable object.
		inline Result<Data*> PrivateInvoke(const String& name, BlockArray<Data>& helperStack, const DataType& expected = DataType::NullValue(), const Block<Data*>* arguments = nullptr) const;
/// Normally to reset the error state of the internal virtual machine. E.g. In Python PyErr_Print is executed.
/// Normally used after VirtualMachineScopeInterface.Execute or VirtualMachineScopeInterface.PrivateInvoke failed, but only if scope is initialized with ERRORHANDLING.REDIRECT.
/// @return												OK if the error was handled, otherwise an exception is returned.
		inline Result<void> ErrorHandling() const;
/// Private.
		inline Result<void> _PrivateInit(const LibraryRef& lib) const;
	};
	/// Intermediate helper class for VirtualMachineScopeInterface.
	template <typename S> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, VirtualMachineScopeRef, false>::type&() { return reinterpret_cast<const VirtualMachineScopeRef&>(this->GetBaseRef()); }
/// Initialized the virtual machine scope. Needs to be executed before any other function of the interface is used.
/// @param[in] identifier					Human readable unique identifier. Depending on the engine, some exception handlers might print this into their exception to
/// 															make it easier to understand where the exception comes from.
/// @param[in] code								Code to be executed.
/// @param[in] errorHandling			Adjust how the virtual machine should treat an exception.
/// @param[in] debug							Optional virtual machine debugger connection, to debug the code.
		inline Result<void> Init(const String& identifier, const String& code, ERRORHANDLING errorHandling, const VmDebuggerConnectionRef* debug = nullptr);
/// Add an object to the scope. The Data object will be converted through the underlying library implementation. So the Data object must be representable in the target virtual machine.
/// @param[in] name								Variable name of the object in the scope.
/// @param[in] data								Object that will be added to the scope.
/// @return												Return state, depending on VirtualMachineScopeInterface::Init(errorHandling).
		inline Result<void> Add(const String& name, const Data& data);
/// Returns an object from the scope.
/// @param[in] name								Variable name of the object in the scope.
/// @return												Requested object or error.
		inline Result<Data> Get(const String& name);
/// Execute the virtual machine scope. Before, and after executing the code, the optionally given debugger code from the VmDebuggerConnection will be executed.
/// @return												Return state, depending on VirtualMachineScopeInterface::Init(errorHandling).
		inline Result<void> Execute();
/// Executes a callable object from the scope. Must only be called after VirtualMachineScopeInterface.Execute.
/// @param[in] name								Name of the callable object, e.g a function name
/// @param[in] helperStack				A temporary helper stack for the return value.
/// @param[in] expected						(Optional) Datatype of the returned object, otherwise the type of the object will be chosen automatically.
/// @param[in] arguments					(Optional) Arguments which will be passed to the callable object.
		inline Result<Data*> PrivateInvoke(const String& name, BlockArray<Data>& helperStack, const DataType& expected = DataType::NullValue(), const Block<Data*>* arguments = nullptr);
/// Normally to reset the error state of the internal virtual machine. E.g. In Python PyErr_Print is executed.
/// Normally used after VirtualMachineScopeInterface.Execute or VirtualMachineScopeInterface.PrivateInvoke failed, but only if scope is initialized with ERRORHANDLING.REDIRECT.
/// @return												OK if the error was handled, otherwise an exception is returned.
		inline Result<void> ErrorHandling();
/// Private.
		inline Result<void> _PrivateInit(const LibraryRef& lib);
	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename ObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename ObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, ReferenceFunctionsImpl<typename ObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>>::type> { };
};
class VirtualMachineScopeInterface::Hxx1::Reference :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<VirtualMachineScopeRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<VirtualMachineScopeInterface, maxon::StrongRefHandler, VirtualMachineScopeRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<VirtualMachineScopeInterface, maxon::StrongRefHandler, VirtualMachineScopeRef>>>>);
	using NonConst = typename Super::ReferenceClass;
};

/// VirtualMachineScopeRef is the reference class of VirtualMachineScopeInterface.
class VirtualMachineScopeRef : public VirtualMachineScopeInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(VirtualMachineScopeRef, typename VirtualMachineScopeInterface::Hxx1::Reference);
	using ConstPtr = typename VirtualMachineScopeInterface::ConstPtr;
};

class VirtualMachineRef;

struct VirtualMachineInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, VirtualMachineInterface>::value || ObjectInterface::HasBase::template Check<I>::value; static I* Cast(VirtualMachineInterface* ptr) { return static_cast<I*>(static_cast<maxon::ObjectInterface*>(ptr)); } }; };
struct VirtualMachineInterface::Hxx1
{
	class Reference;
	using ReferenceClass = VirtualMachineRef;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<ObjectInterface>;
	/// Intermediate helper class for VirtualMachineInterface.
	template <typename S> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
	{
	public:
		ConstReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
/// Returns all available virtual machine libraries.
/// @return												An array of available virtual machines libraries.
		inline Result<BaseArray<Runtime>> GetAllAvailableVirtualMachineLibraries() const;
	};
	/// Intermediate helper class for VirtualMachineInterface.
	template <typename S> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, VirtualMachineRef, true>::type&() const { return reinterpret_cast<const VirtualMachineRef&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, VirtualMachineRef, false>::type&() { return reinterpret_cast<const VirtualMachineRef&>(this->GetBaseRef()); }
/// @param[in] runtimeInfo				Information about the virtual machine, how to start it up.
/// @param[in] settings						Optional settings which might be needed by the virtual machine.
/// @return												OK on success.
		inline Result<void> Init(const LoadRuntime& runtimeInfo, const DataDictionary& settings = DataDictionary::NullValue()) const;
/// Frees and shuts down the virtual machine. Should never be called on virtual machines which are owned by the system.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type Free() const;
/// Creates a virtual machine scope. The scope must be deleted before the virtual machine will be shutdown.
/// @return												New virtual machine scope.
		inline Result<VirtualMachineScopeRef> CreateScope() const;
/// Returns the name of the underlying library, e.g. "Python".
/// @return												Name of the virtual machine.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type GetName() const;
/// Returns the human readable version string of the underlying library.
/// @return												Version details.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type GetVersion() const;
/// Returns the human readable copyright information of the underlying library.
/// @return												Copyright text.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type GetCopyright() const;
/// Returns a human readable compiler info text.
/// @return												Compiler which got used to compile the underlying library.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type GetCompiler() const;
/// Returns a human readable build information.
/// @return												Build info with information about the build.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type GetBuildInfo() const;
/// Enters the interactive mode of the virtual machine.
/// @return												OK after the interactive mode was left, or FunctionNotImplementedError
		inline Result<void> EnterInteractiveMode() const;
/// Executes a given code in the global scope of the virtual machine.
/// @param[in] code								Code to execute.
/// @return												Returns an error if an error occurred. Virtual machine clears all error states when function returns.
		inline Result<void> Execute(const String& code) const;
/// Executes a given file in the global scope of the virtual machine.
/// @param[in] filepath						Path of file to execute.
/// @return												Returns an error if an error occurred. Virtual machine clears all error states when function returns.
		inline Result<void> Execute(const Url& filepath) const;
/// Executes a given module in the virtual machine.
/// @param[in] name								Name of the module.
/// @return												Returns an error if an error occurred. Virtual machine clears all error states when function returns.
		inline Result<void> ExecuteModule(const String& name) const;
/// Returns docstrings of a given code.
/// @param[in] code								String code.
/// @param[out] meta							Returns the docstrings.
/// @return												Returns OK if the extraction succeeded, otherwise None.
		inline Result<void> GetDocumentString(const String& code, DocStringMeta& meta) const;
/// Returns the underlying library.
/// @return												Underlying virtual machine library.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<LibraryRef>, LibraryRef>::type GetLibraryRef() const;
	};
	/// Intermediate helper class for VirtualMachineInterface.
	template <typename S> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, VirtualMachineRef, false>::type&() { return reinterpret_cast<const VirtualMachineRef&>(this->GetBaseRef()); }
/// @param[in] runtimeInfo				Information about the virtual machine, how to start it up.
/// @param[in] settings						Optional settings which might be needed by the virtual machine.
/// @return												OK on success.
		inline Result<void> Init(const LoadRuntime& runtimeInfo, const DataDictionary& settings = DataDictionary::NullValue());
/// Frees and shuts down the virtual machine. Should never be called on virtual machines which are owned by the system.
		inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type Free();
/// Creates a virtual machine scope. The scope must be deleted before the virtual machine will be shutdown.
/// @return												New virtual machine scope.
		inline Result<VirtualMachineScopeRef> CreateScope();
/// Returns the name of the underlying library, e.g. "Python".
/// @return												Name of the virtual machine.
		inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), String, maxon::Result<String>>::type GetName();
/// Returns the human readable version string of the underlying library.
/// @return												Version details.
		inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), String, maxon::Result<String>>::type GetVersion();
/// Returns the human readable copyright information of the underlying library.
/// @return												Copyright text.
		inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), String, maxon::Result<String>>::type GetCopyright();
/// Returns a human readable compiler info text.
/// @return												Compiler which got used to compile the underlying library.
		inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), String, maxon::Result<String>>::type GetCompiler();
/// Returns a human readable build information.
/// @return												Build info with information about the build.
		inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), String, maxon::Result<String>>::type GetBuildInfo();
/// Enters the interactive mode of the virtual machine.
/// @return												OK after the interactive mode was left, or FunctionNotImplementedError
		inline Result<void> EnterInteractiveMode();
/// Executes a given code in the global scope of the virtual machine.
/// @param[in] code								Code to execute.
/// @return												Returns an error if an error occurred. Virtual machine clears all error states when function returns.
		inline Result<void> Execute(const String& code);
/// Executes a given file in the global scope of the virtual machine.
/// @param[in] filepath						Path of file to execute.
/// @return												Returns an error if an error occurred. Virtual machine clears all error states when function returns.
		inline Result<void> Execute(const Url& filepath);
/// Executes a given module in the virtual machine.
/// @param[in] name								Name of the module.
/// @return												Returns an error if an error occurred. Virtual machine clears all error states when function returns.
		inline Result<void> ExecuteModule(const String& name);
/// Returns docstrings of a given code.
/// @param[in] code								String code.
/// @param[out] meta							Returns the docstrings.
/// @return												Returns OK if the extraction succeeded, otherwise None.
		inline Result<void> GetDocumentString(const String& code, DocStringMeta& meta);
/// Returns the underlying library.
/// @return												Underlying virtual machine library.
		inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), LibraryRef, maxon::Result<LibraryRef>>::type GetLibraryRef();
	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename ObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename ObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, ReferenceFunctionsImpl<typename ObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>>::type> { };
};
class VirtualMachineInterface::Hxx1::Reference :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<VirtualMachineRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<VirtualMachineInterface, maxon::StrongRefHandler, VirtualMachineRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<VirtualMachineInterface, maxon::StrongRefHandler, VirtualMachineRef>>>>);
	using NonConst = typename Super::ReferenceClass;
};

/// VirtualMachineRef is the reference class of VirtualMachineInterface.
class VirtualMachineRef : public VirtualMachineInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(VirtualMachineRef, typename VirtualMachineInterface::Hxx1::Reference);
	using ConstPtr = typename VirtualMachineInterface::ConstPtr;
};

#endif
