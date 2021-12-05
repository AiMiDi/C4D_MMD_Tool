/////////////////////////////////////////////////////////////
// CINEMA 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef C4D_LIBRARY_H__
#define C4D_LIBRARY_H__

#include "operatingsystem.h"

//----------------------------------------------------------------------------------------
/// Returns the offset of member @formatParam{m} within the struct @formatParam{s}.
/// @param[in] s									The struct name, for example @c MyLib.
/// @param[in] m									The member name, for example @c MyFunction.
//----------------------------------------------------------------------------------------
#define LIBOFFSET(s, m) (Int32)((UInt)(&(((s*)0)->m)))

//----------------------------------------------------------------------------------------
/// The base class for libraries.
/// @see Creating Libraries.
//----------------------------------------------------------------------------------------
struct C4DLibrary
{
	Int32 version;			///< Library version.
	Int32 size;					///< @c sizeof() the whole library structure, i.e. including the derived struct.
};

//----------------------------------------------------------------------------------------
/// Registers a library with @C4D.
/// @param[in] id									@uniquePluginID
/// @param[in] lib								The library structure to register. @callerOwnsPointed{structure}
/// @param[in] version						The library version.
/// @param[in] size								The size of the structure passed to @formatParam{lib}.
/// @return												@trueIfOtherwiseFalse{the library was registered}
//----------------------------------------------------------------------------------------
Bool InstallLibrary(Int32 id, C4DLibrary* lib, Int32 version, Int32 size);

//----------------------------------------------------------------------------------------
/// Unregisters a library with @C4D.
/// @param[in] lib								The library structure to unregister. @callerOwnsPointed{structure}
/// @param[in] version						The library version.
/// @param[in] size								The size of the structure passed to @formatParam{lib}.
/// @return												@trueIfOtherwiseFalse{the library was unregistered}
//----------------------------------------------------------------------------------------
Bool UninstallLibrary(C4DLibrary* lib, Int32 version, Int32 size);

//----------------------------------------------------------------------------------------
/// Retrieves a pointer to a library if it is installed.
/// @param[in] id									The library plugin ID.
/// @param[in] offset							Pass LIBOFFSET(LIBRARY_CLASS, MEMBER_NAME), where @c LIBRARY_CLASS is a struct derived from C4DLibrary and @c MEMBER_NAME is a member to access.\n
/// 															Example: @c LIBOFFSET(MyLib, MyFunction)
/// @param[in] store							Pass a pointer to a global pointer that can be used as cache for the library address.\n
/// 															CheckLib() will then use this address instead of looking it up each time.
/// @return												The library, or @formatConstant{nullptr} if the requested @formatParam{offset} is not valid.
//----------------------------------------------------------------------------------------
C4DLibrary* CheckLib(Int32 id, Int offset, C4DLibrary** store);

//----------------------------------------------------------------------------------------
/// Checks if a library is installed.
/// @param[in] id									The plugin ID of the library to check.
/// @return												@trueIfOtherwiseFalse{the library is installed}
//----------------------------------------------------------------------------------------
Bool IsLibraryInstalled(Int32 id);

#endif // C4D_LIBRARY_H__
