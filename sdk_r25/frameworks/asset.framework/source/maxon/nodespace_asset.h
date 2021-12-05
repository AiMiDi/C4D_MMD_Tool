#ifndef NODESPACE_ASSET_H__
#define NODESPACE_ASSET_H__


#include "maxon/assets.h"



namespace maxon
{

class NodeSpaceAsset;
class LanguageRef;



class NodeSpaceAssetInterface : MAXON_INTERFACE_BASES(AssetInterface)
{
	MAXON_INTERFACE(NodeSpaceAssetInterface, MAXON_REFERENCE_COPY_ON_WRITE, "net.maxon.interface.nodespaceasset");

public:
	static MAXON_METHOD Result<NodeSpaceAsset> Create();
};

namespace ASSETMETADATA
{
	MAXON_ATTRIBUTE(Id, NodeSpace, "net.maxon.node.nodespace");
}

namespace AssetTypes
{
	/// AssetTypes::NodeSpace allows to store categories within in a repository
	MAXON_DECLARATION(AssetType, NodeSpace, "net.maxon.assettype.nodespace");
};

static const LiteralId ID_MISSINGNODESPACE{"net.maxon.asset.nodespace.missing"};

#include "nodespace_asset1.hxx"
#include "nodespace_asset2.hxx"

}


#endif // NODESPACE_ASSET_H__
