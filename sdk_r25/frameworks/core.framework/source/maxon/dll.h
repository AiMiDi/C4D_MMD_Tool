#ifndef DLL_H__
#define DLL_H__

#include "maxon/interfacebase.h"
#include "maxon/url.h"
#include "maxon/datatype.h"
#include "maxon/basearray.h"

namespace maxon
{

class DllRef;

//----------------------------------------------------------------------------------------
/// Interface for managing dynamic libraries (load, query symbols, ...).
//----------------------------------------------------------------------------------------
class DllInterface
{
	MAXON_INTERFACE_NONVIRTUAL(DllInterface, MAXON_REFERENCE_NORMAL, "net.maxon.interface.dll");

public:
	//----------------------------------------------------------------------------------------
	/// Loads the dll into memory. When the last reference disappears the dll will be unloaded automatically.
	/// @param[in] fileName						Filename of the dll to load.
	/// @param[in] registerDll				If true the library will automatically be unloaded before the current module is unloaded.
	///																Make sure not to store the reference permanently (otherwise this can't work).
	/// @param[in] requireCoreModule	Set this to false to load foreign libraries. Otherwise C4D specific symbols must be present.
	/// @param[in] systemDependentFlags	Flags passed to the underlying OS function which opens the library. LoadLibrary on Windows, and dlopen on macOS and Linux.
	/// @return												Returns the dll reference or an error.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<DllRef> LoadDll(const Url& fileName, Bool registerDll, Bool requireCoreModule, Int systemDependentFlags = -1);

	//----------------------------------------------------------------------------------------
	/// Creates a DllRef from an already loaded module. The dll will not be unloaded when the reference is deleted.
	/// @param[in] handle							Handle to the module. This is a HMODULE on Windows and a void* on Linux and OSX.
	/// @param[in] processId					Id of the process that owns the dll.
	/// @return												Returns the dll reference or an error.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<DllRef> GetModule(const void* handle, UInt processId);

	//----------------------------------------------------------------------------------------
	/// Adds a directory to the search path used to locate DLLs for the application (Windows only).
	/// @param[in] dllDirectory				The directory to be added to the search path.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> AddDllPath(const Url& dllDirectory);

	//----------------------------------------------------------------------------------------
	/// Removes a directory from the library search path (Windows only).
	/// @param[in] dllDirectory				The directory to be removed from the search path.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> RemoveDllPath(const Url& dllDirectory);

	//----------------------------------------------------------------------------------------
	/// Returns all loaded dlls which were loaded through DllInterface.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> GetLoadedDlls(const ValueReceiver<const DllRef&>& dlls);

	//----------------------------------------------------------------------------------------
	/// Unloads the dll from memory.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Unload();

	//----------------------------------------------------------------------------------------
	/// Detaches this object from the system handle so that the dll will be unloaded when the application quits.
	/// @return												OK on success.
	/// @MAXON_ANNOTATION{default=OK}
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Release();

	//----------------------------------------------------------------------------------------
	/// Looks for a symbol and returns a generic pointer to it.
	/// @param[in] symbol							Symbol to find in the dll.
	/// @return												Returns pointer to the symbol in the dll.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void*> FindSymbolPointer(const CString& symbol) const;

	//----------------------------------------------------------------------------------------
	/// Looks for a symbol and returns the requested type (via cast).
	/// @param[in] symbol							Symbol to find in the dll.
	/// @return												Returns pointer to the symbol in the dll and casts it to the expected type.
	//----------------------------------------------------------------------------------------
	template <typename T> MAXON_FUNCTION Result<T> FindSymbol(const CString& symbol) const
	{
		iferr (void* ptr = FindSymbolPointer(symbol))
			return err;
		return (T)ptr;
	}

	//------------------------------------------------------------
	// Get information for a library.
	// @return	  										The Binary object in case of a C4D native module.
	//------------------------------------------------------------
	MAXON_METHOD Result<Binary*> GetBinary() const;

	//----------------------------------------------------------------------------------------
	/// Loads or updates symbol data for dynamic libraries. Depending on the OS (Windows)
	/// this has to be triggered manually after all modules have been loaded. 
	// @return	  										OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> UpdateSymbolData();

	//----------------------------------------------------------------------------------------
	/// Returns the location (Url) of the dll.
	/// @return												Url of the loaded dll.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Url> GetPath() const;
};

using QueryStartupOrder = void (*)(BaseArray<Url>& dllsToLoad);

#include "dll1.hxx"
#include "dll2.hxx"

}

#endif // DLL_H__
