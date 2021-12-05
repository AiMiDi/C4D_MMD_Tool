#ifndef __API_INTERN__
	#include "c4d_library.h"
	#include "c4d_memory.h"
	#include "c4d_general.h"
#else
	#include "c4d_library.h"
	#include "ge_registry.h"
#endif




Bool InstallLibrary(Int32 id, C4DLibrary* lib, Int32 version, Int32 size)
{
	lib->version = version;
	lib->size = size;
	return GeRegistryAdd(id, REGISTRYTYPE::LIBRARY, lib);
}

Bool UninstallLibrary(C4DLibrary* lib, Int32 version, Int32 size)
{
	return true;
}

Bool IsLibraryInstalled(Int32 id)
{
	Registry* reg = GeRegistryFind(id, REGISTRYTYPE::LIBRARY);
	if (!reg)
		return false;

#ifndef __API_INTERN__
	C4DLibrary* lib = (C4DLibrary*)reg->GetData();
#else
	C4DLibrary* lib = (C4DLibrary*)reg->data;
#endif
	return lib != nullptr;
}

C4DLibrary* CheckLib(Int32 id, Int offset, C4DLibrary** store)
{
	if (store && *store)
		return *store;
	Registry* reg = GeRegistryFind(id, REGISTRYTYPE::LIBRARY);
	if (!reg)
		return nullptr;
#ifndef __API_INTERN__
	C4DLibrary* lib = (C4DLibrary*)reg->GetData();
#else
	C4DLibrary* lib = (C4DLibrary*)reg->data;
#endif
	if (!lib)
		return nullptr;
	if (store)
		*store = lib;
	// not the right version
	if (offset > lib->size)
		return nullptr;

	return lib;
}




