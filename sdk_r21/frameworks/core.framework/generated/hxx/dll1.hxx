#if 1
class DllRef;

struct DllInterface::Hxx1
{
	class Reference;
	using ReferenceClass = DllRef;
	/// Intermediate helper class for DllInterface.
	template <typename S> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
	{
	public:
		ConstReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
/// Loads the dll into memory. When the last reference disappears the dll will be unloaded automatically.
/// @param[in] fileName						Filename of the dll to load.
/// @param[in] registerDll				If true the library will automatically be unloaded before the current module is unloaded.
///																Make sure not to store the reference permanently (otherwise this can't work).
/// @param[in] requireCoreModule	Set this to false to load foreign libraries. Otherwise C4D specific symbols must be present.
/// @param[in] systemDependentFlags	Flags passed to the underlying OS function which opens the library. LoadLibrary on Windows, and dlopen on macOS and Linux.
/// @return												Returns the dll reference or an error.
		static inline Result<DllRef> LoadDll(const Url& fileName, Bool registerDll, Bool requireCoreModule, Int systemDependentFlags = -1);
/// Creates a DllRef from an already loaded module. The dll will not be unloaded when the reference is deleted.
/// @param[in] handle							Handle to the module. This is a HMODULE on Windows and a void* on Linux and OSX.
/// @param[in] processId					Id of the process that owns the dll.
/// @return												Returns the dll reference or an error.
		static inline Result<DllRef> GetModule(const void* handle, UInt processId);
/// Adds a directory to the search path used to locate DLLs for the application (Windows only).
/// @param[in] dllDirectory				The directory to be added to the search path.
/// @return												OK on success.
		static inline Result<void> AddDllPath(const Url& dllDirectory);
/// Removes a directory from the library search path (Windows only).
/// @param[in] dllDirectory				The directory to be removed from the search path.
/// @return												OK on success.
		static inline Result<void> RemoveDllPath(const Url& dllDirectory);
/// Returns all loaded dlls which were loaded through DllInterface.
		static inline Result<void> GetLoadedDlls(const ValueReceiver<const DllRef&>& dlls);
/// Looks for a symbol and returns a generic pointer to it.
/// @param[in] symbol							Symbol to find in the dll.
/// @return												Returns pointer to the symbol in the dll.
		inline Result<void*> FindSymbolPointer(const CString& symbol) const;
/// Looks for a symbol and returns the requested type (via cast).
/// @param[in] symbol							Symbol to find in the dll.
/// @return												Returns pointer to the symbol in the dll and casts it to the expected type.
		template <typename T> inline Result<T> FindSymbol(const CString& symbol) const;
		inline Result<Binary*> GetBinary() const;
/// Returns the location (Url) of the dll.
/// @return												Url of the loaded dll.
		inline Result<Url> GetPath() const;
	};
	/// Intermediate helper class for DllInterface.
	template <typename S> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, DllRef, true>::type&() const { return reinterpret_cast<const DllRef&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, DllRef, false>::type&() { return reinterpret_cast<const DllRef&>(this->GetBaseRef()); }
/// Unloads the dll from memory.
/// @return												OK on success.
		inline Result<void> Unload() const;
/// Detaches this object from the system handle so that the dll will be unloaded when the application quits.
/// @return												OK on success.
		inline Result<void> Release() const;
/// Loads or updates symbol data for dynamic libraries. Depending on the OS (Windows)
/// this has to be triggered manually after all modules have been loaded. 
		inline Result<void> UpdateSymbolData() const;
	};
	/// Intermediate helper class for DllInterface.
	template <typename S> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, DllRef, false>::type&() { return reinterpret_cast<const DllRef&>(this->GetBaseRef()); }
	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename ST::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename ST::type>, ReferenceFunctionsImpl<typename ST::type>>::type> { };
};
class DllInterface::Hxx1::Reference :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<DllRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<DllInterface, maxon::StrongRefHandler, DllRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<DllInterface, maxon::StrongRefHandler, DllRef>>>>);
	using NonConst = typename Super::ReferenceClass;
};

/// DllRef is the reference class of DllInterface.
///
/// Interface for managing dynamic libraries (load, query symbols, ...).
class DllRef : public DllInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(DllRef, typename DllInterface::Hxx1::Reference);
};

#endif
