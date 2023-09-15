#ifndef RELEASE_TITLE_H__
#define RELEASE_TITLE_H__

#include "../../../../config/_release_title.h"

#if BRANCH_RELEASE_TYPE_VALUE == 0				// 0 - RC ; 1 - "Beta" ; 2 - "Alpha", 3 - "Concept"
	#define BRANCH_RELEASE_TYPE						"RC"
#elif BRANCH_RELEASE_TYPE_VALUE == 1
	#define BRANCH_RELEASE_TYPE						"Beta"
#elif BRANCH_RELEASE_TYPE_VALUE == 2
	#define BRANCH_RELEASE_TYPE						"Alpha"
#elif BRANCH_RELEASE_TYPE_VALUE == 3
	#define BRANCH_RELEASE_TYPE						"Concept"
#else
	#error "illegal BRANCH_RELEASE_TYPE_INT"
#endif

//----------------------------------------------------------------------------------------
/// LicenseNeedBetaGrants returns true if this application needs beta grants.
/// @return												True if beta. False for release.
//----------------------------------------------------------------------------------------
constexpr inline bool LicenseNeedBetaGrants()
{
	return BRANCH_RELEASE_TYPE_VALUE > 0;
}

#endif // RELEASE_TITLE_H__
