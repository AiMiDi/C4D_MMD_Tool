#ifndef NODECONTEXT_ASSET_H__
#define NODECONTEXT_ASSET_H__

#include "maxon/assets.h"

namespace maxon
{

class NodeContextAsset;

class NodeContextAssetInterface : MAXON_INTERFACE_BASES(AssetInterface)
{
	MAXON_INTERFACE(NodeContextAssetInterface, MAXON_REFERENCE_COPY_ON_WRITE, "net.maxon.node.interface.contextasset");

public:

	static constexpr LiteralId NONE_CONTEXT_ID{"none"};

	static MAXON_METHOD Result<NodeContextAsset> Create();

	//----------------------------------------------------------------------------------------
	/// Read the context's Id.
	/// @return												The Id read.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD InternedId GetContextId() const;

	//----------------------------------------------------------------------------------------
	/// Set the context's Id.
	/// @param[in] contextId					The type to set (empty type accepted).
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> SetContextId(const Id& contextId);

	//----------------------------------------------------------------------------------------
	/// Read the context's type.
	/// @return												The type read (can be empty DataType).
	//----------------------------------------------------------------------------------------
	MAXON_METHOD DataType GetContextType() const;

	//----------------------------------------------------------------------------------------
	/// Set the context's type.
	/// @param[in] dataType						The type to set (empty type accepted).
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> SetContextType(const DataType& dataType);
};

/// Use this to set category or search by category. 
/// @code
/// CategoryAssetInterface::SetAssetCategory(asset, AssetCategoryNodeContext) iferr_return;
/// @endcode
MAXON_ATTRIBUTE(void, AssetCategoryNodeContext, "net.maxon.asset.category.nodecontext");

namespace AssetTypes
{
	MAXON_DECLARATION(AssetType, NodeContext, "net.maxon.assettype.nodecontext");
};

#include "nodecontext_asset1.hxx"
#include "nodecontext_asset2.hxx"

}

#endif // NODECONTEXT_ASSET_H__
