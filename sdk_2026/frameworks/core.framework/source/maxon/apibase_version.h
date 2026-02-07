#ifndef APIBASE_VERSION_H__
#define APIBASE_VERSION_H__

//----------------------------------------------------------------------------------------
/// The ABI version (Application Binary Interface) of the Maxon API. Only modules compiled
/// with the same ABI version are binary-compatible and can be loaded together.
//----------------------------------------------------------------------------------------
#define MAXON_API_ABI_VERSION 2026000

//----------------------------------------------------------------------------------------
/// The core framework version is increased at least with every major application version.
//----------------------------------------------------------------------------------------
#define MAXON_CORE_FRAMEWORK_VERSION 2026100

#endif // APIBASE_VERSION_H__
