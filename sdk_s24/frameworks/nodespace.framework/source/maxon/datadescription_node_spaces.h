#ifndef DATADESCRIPTION_NODE_SPACES_H__
#define DATADESCRIPTION_NODE_SPACES_H__

#include "maxon/datadescription_node_bundles.h"

//----------------------------------------------------------------------------------------
// BEGIN - auto generated code, do not edit
//----------------------------------------------------------------------------------------
namespace maxon
{
namespace NODESPACE
{
	namespace BASE
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.nodespace.base");

		MAXON_ATTRIBUTE(String, DUMMY, "net.maxon.nodespace.base.dummy");
	}

	namespace EXCHANGE
	{
		namespace NODE
		{
			namespace EXCHANGENODE
			{
				MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.nodespace.exchange.node.exchangenode");

				// supports MAXON::NODE::BASE::NODEPREVIEWIMAGE
				// supports MAXON::NODE::BASE::MATERIALPREVIEWIMAGE
				// supports MAXON::NODE::BASE::NAME
				// supports MAXON::NODE::BASE::ASSETVERSION
				// supports MAXON::NODE::BASE::COLOR
				// supports MAXON::NODE::BASE::PORTDISPLAY
				// supports MAXON::NODE::BASE::DISPLAYPREVIEW
				// supports MAXON::NODE::BASE::DISPLAYCOMMENT
				// supports MAXON::NODE::BASE::COMMENT
				// supports MAXON::NODE::BASE::FILTERTAGS
				// supports MAXON::NODE::BASE::HIDDENINEDITOR
				// supports MAXON::NODE::BASE::CATEGORY
				// supports MAXON::NODE::BASE::ICON
				// supports MAXON::NODE::BASE::UPDATEPOLICY
				// supports MAXON::ASSET::BASE::PROTECTED

				MAXON_ATTRIBUTE(Id, TYPE, "type",
					RESOURCE_DEFINE(ENUM_VIEWPORTMATERIAL, Id("viewportmaterial"))
					RESOURCE_DEFINE(ENUM_USDPREVIEWSURFACE, Id("usdpreviewsurface")));

				MAXON_ATTRIBUTE(Int, WIDTH, "width");

				MAXON_ATTRIBUTE(Int, HEIGHT, "height");

				MAXON_ATTRIBUTE(void, VIEWPORTMATERIAL, "viewportmaterial");

				MAXON_ATTRIBUTE(void, USDPREVIEWSURFACE, "usdpreviewsurface");

				MAXON_ATTRIBUTE(void, BAKECOMMAND, "bakecommand");
			}
		}
	}
}
}
//----------------------------------------------------------------------------------------
// END - auto generated code, do not edit
//----------------------------------------------------------------------------------------

namespace maxon
{

#include "datadescription_node_spaces1.hxx"
#include "datadescription_node_spaces2.hxx"

} // namespace maxon

#endif // DATADESCRIPTION_NODES_H__
