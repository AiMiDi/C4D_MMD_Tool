#ifndef NODES_CONTEXT_H__
#define NODES_CONTEXT_H__

#include "maxon/fid.h"

//----------------------------------------------------------------------------------------
// BEGIN - auto generated code, do not edit
//----------------------------------------------------------------------------------------
namespace maxon
{
namespace NODE
{
	namespace CONTEXT
	{
		namespace GET
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.context.get");

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
			// supports MAXON::NODE::BASE::CATEGORY
			// supports MAXON::NODE::BASE::ICON
			// supports MAXON::NODE::BASE::UPDATEPOLICY
			// supports MAXON::ASSET::BASE::PROTECTED

			MAXON_ATTRIBUTE(Id, NODECONTEXTIN, "nodecontextin",
				RESOURCE_DEFINE(ENUM_NONE, Id("none"))
				RESOURCE_DEFINE(ENUM_NODECONTEXT, Id("nodecontext#")));

			MAXON_ATTRIBUTE(void, CONTEXTVALUEOUT, "contextvalueout");

			MAXON_ATTRIBUTE(MAXON_MACROARG_TYPE(Tuple<InternedId, DataType>), FORCEDCONTEXTIN, "forcedcontextin");
		}
	}
}
}
//----------------------------------------------------------------------------------------
// END - auto generated code, do not edit
//----------------------------------------------------------------------------------------


#include "nodes_context1.hxx"
#include "nodes_context2.hxx"

#endif // NODES_CONTEXT_H__
