#ifndef NODES_GROUP_H__
#define NODES_GROUP_H__

#include "maxon/fid.h"

//----------------------------------------------------------------------------------------
// BEGIN - auto generated code, do not edit
//----------------------------------------------------------------------------------------
namespace maxon
{
namespace NODE
{
	namespace GROUP
	{
		namespace MISSINGASSET
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.group.missingasset");

			// supports MAXON::NODE::BASE::FILTERTAGS
			// supports MAXON::NODE::BASE::NODEPREVIEWIMAGE
			// supports MAXON::NODE::BASE::NAME
			// supports MAXON::NODE::BASE::ASSETVERSION
			// supports MAXON::NODE::BASE::COLOR
			// supports MAXON::NODE::BASE::PORTDISPLAY
			// supports MAXON::NODE::BASE::DISPLAYPREVIEW
			// supports MAXON::NODE::BASE::DISPLAYCOMMENT
			// supports MAXON::NODE::BASE::COMMENT
			// supports MAXON::NODE::BASE::CATEGORY
			// supports MAXON::NODE::BASE::ICON
			// supports MAXON::NODE::BASE::UPDATEPOLICY
			// supports MAXON::ASSET::BASE::PROTECTED

			/// Identifier of the missing asset. A NODE::GROUP::MISSING asset was
			/// used to replace the missing asset to preserve graph.
			/// DEPRECATED, use NODE::GROUP::ASSETLINK instead.
			MAXON_ATTRIBUTE(Id, ASSETIDATTR, "assetidattr");

			/// Version of the missing asset. Could be empty if node was using the
			/// "Latest" version update policy.
			/// DEPRECATED, use NODE::GROUP::ASSETLINK instead.
			MAXON_ATTRIBUTE(Id, ASSETVERSIONATTR, "assetversionattr");

			/// Unresolved asset link. Should contain the asset's identifier and origin informations.
			/// Origin can be used to resolve missing asset issues,
			MAXON_ATTRIBUTE(AssetLink, ASSETLINKATTR, "assetlinkattr");

			MAXON_ATTRIBUTE(String, MISSINGINPUTSTR, "net.maxon.node.group.missingasset.missinginputstr");

			MAXON_ATTRIBUTE(String, MISSINGOUTPUTSTR, "net.maxon.node.group.missingasset.missingoutputstr");
		}
	}
}
}
//----------------------------------------------------------------------------------------
// END - auto generated code, do not edit
//----------------------------------------------------------------------------------------


#include "nodes_group1.hxx"
#include "nodes_group2.hxx"

#endif // NODES_GROUP_H__
