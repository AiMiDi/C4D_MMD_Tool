#if 1
namespace maxon
{
#ifdef MAXON_COMPILER_MSVC
#else
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	PRIVATE_MAXON_REGISTRY_DEFINE(DataTypes);
#endif
#if !defined(MAXON_API) || defined(DOXYGEN)
#ifdef MAXON_COMPILER_INTEL
#else
#endif
#endif
}
#endif
