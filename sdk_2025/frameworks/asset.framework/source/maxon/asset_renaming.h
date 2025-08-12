#ifndef ASSET_RENAMING_H__
#define ASSET_RENAMING_H__

#include "maxon/registry.h"

namespace maxon
{

//----------------------------------------------------------------------------------------
/// @brief		An AssetRenaming represents changes of asset identifiers.
/// @details	Whenever an asset identifier is changed due to clean-up, refactoring or other reasons,
/// existing assets still reference the asset via its old identifier. You have to register an AssetRenaming
/// to reflect the change.
/// @param[in] prevId							An asset identifier.
/// @return												The new asset identifier to use instead of prevId, or an empty Id if the AssetRenaming has no replacement for prevId.
//----------------------------------------------------------------------------------------
using AssetRenaming = Delegate<Result<Id>(const Id& prevId)>;

//----------------------------------------------------------------------------------------
/// @brief		Registry of all AssetRenaming delegates.
/// @details	Asset repositories ask all registered AssetRenaming delegates for identifier changes
/// whenever one of their find functions is called. The result of the first delegate which returns a renaming
/// is used.
//----------------------------------------------------------------------------------------
MAXON_REGISTRY(AssetRenaming, AssetRenamings, "net.maxon.registry.assetrenamings");

}

#endif // ASSET_RENAMING_H__
