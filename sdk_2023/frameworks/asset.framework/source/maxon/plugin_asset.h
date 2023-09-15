#ifndef PLUGIN_ASSET_H__
#define PLUGIN_ASSET_H__


#include "maxon/assets.h"



namespace maxon
{

class PluginAsset;
class LanguageRef;


//----------------------------------------------------------------------------------------
/// Implements the PluginAsset type
//----------------------------------------------------------------------------------------
class PluginAssetInterface : MAXON_INTERFACE_BASES(AssetInterface)
{
	MAXON_INTERFACE(PluginAssetInterface, MAXON_REFERENCE_COPY_ON_WRITE, "net.maxon.interface.pluginasset");

public:
	//----------------------------------------------------------------------------------------
	/// Create creates a new plugin asset.
	/// @return                       OK on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<PluginAsset> Create();
};

namespace ASSETMETADATA
{
	MAXON_ATTRIBUTE(Id, Plugin, "net.maxon.node.plugin");

	MAXON_ATTRIBUTE(void, SubType_ENUM_InternalModule, "net.maxon.asset.plugin.internalmodule");
	MAXON_ATTRIBUTE(void, SubType_ENUM_ExternalPlugin, "net.maxon.asset.plugin.externalplugin");
}

namespace AssetTypes
{
	/// AssetTypes::Plugin allows to store categories within in a repository
	MAXON_DECLARATION(AssetType, Plugin, "net.maxon.assettype.plugin");
};

static const LiteralId ID_MISSINGPLUGIN{"net.maxon.asset.plugin.missing"};

#include "plugin_asset1.hxx"
#include "plugin_asset2.hxx"

#define PLUGIN_ASSET_PREFIX "builtin_plugin_"

}


#endif // PLUGIN_ASSET_H__
