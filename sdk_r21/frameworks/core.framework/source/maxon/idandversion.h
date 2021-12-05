#ifndef IDANDVERSION_H__
#define IDANDVERSION_H__

#include "maxon/tuple.h"
#include "maxon/datatype.h"


namespace maxon
{

//----------------------------------------------------------------------------------------
/// IdAndVersion is used for assets to store the asset id (first) and version (second) in a single tuple.
//----------------------------------------------------------------------------------------
using IdAndVersion = Tuple<Id, Id>;

//----------------------------------------------------------------------------------------
/// ASSET_UPDATE_POLICY controls how the referenced asset of an AssetLink is updated when a
/// newer version of the asset exists.
//----------------------------------------------------------------------------------------
enum class ASSET_UPDATE_POLICY
{
	NEVER = 0,			///< The asset is never updated, so the link always points to the exact version recorded in the link.
	EXPLICIT = 1,		///< The asset isn't updated implicitly, but the user is asked if the link shall point to the latest version if there is a newer version than the one recorded in the link.
	IMPLICIT = 2		///< The asset is updated implicitly whenever a newer version of the asset exists.
} MAXON_ENUM_LIST(ASSET_UPDATE_POLICY, "net.maxon.datatype.enum.asset_update_policy");

}

#endif // IDANDVERSION_H__
