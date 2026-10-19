#include "maxon/utilities/undef_win_macros.h"

#ifdef PRIVATE_MAXON_DEPENDENCY_ENABLE_ORIGINAL
	#if MAXON_DEPENDENCY_ENABLE + 0 != PRIVATE_MAXON_DEPENDENCY_ENABLE_ORIGINAL
		static int MAXON_CONCAT(dummy, __COUNTER__) = PRIVATE_MAXON_UNITY_BUILD_ID();
		#error Files which modify MAXON_DEPENDENCY_ENABLE must be excluded from unity builds.
	#endif
#elif defined(MAXON_DEPENDENCY_ENABLE)
	static int MAXON_CONCAT(dummy, __COUNTER__) = PRIVATE_MAXON_UNITY_BUILD_ID();
	#error Files which modify MAXON_DEPENDENCY_ENABLE must be excluded from unity builds.
#endif
