#if 1
namespace maxon
{
/// @cond INTERNAL

#ifndef MAXON_COMPILER_CLANG
#endif
#ifndef OPTIONAL
	namespace enum310
	{
		enum class DEPENDENCY
			{
				STRONG,		///< A strong dependency. This is given in the Modules list of projectdefinition.txt.
				WEAK,			///< A weak dependency. This is given in the ModulesWeak list of projectdefinition.txt.
				OPTIONAL	///< An optional dependency (no warning will be issued when no such dependency is detected at run-time). This is given in the ModulesOptional list of projectdefinition.txt.
			} ;
		static const maxon::UInt64 DEPENDENCY_values[] = {maxon::UInt64(enum310::DEPENDENCY::STRONG), maxon::UInt64(enum310::DEPENDENCY::WEAK), maxon::UInt64(enum310::DEPENDENCY::OPTIONAL)};
		static const maxon::EnumInfo DEPENDENCY_info{"ModuleInfo::DEPENDENCY", SIZEOF(DEPENDENCY), false, "STRONG\0WEAK\0OPTIONAL\0", DEPENDENCY_values, std::extent<decltype(DEPENDENCY_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_DEPENDENCY310(void*){ return enum310::DEPENDENCY_info; }
#endif
#ifdef MAXON_TARGET_WINDOWS
#else
#endif
/// @endcond

#ifdef MAXON_DEPENDENCY_ENABLE
#else
#endif
#if defined(MAXON_TARGET_LINUX) && defined(MAXON_COMPILER_GCC)
#else
#endif
#ifdef MAXON_DEPENDENCY_ENABLE
#endif
#ifndef PRIVATE_MAXON_REGISTRATION_FRAMEWORK
#else
#endif
#ifdef MAXON_DEPENDENCY_ENABLE
#endif
}
#endif
