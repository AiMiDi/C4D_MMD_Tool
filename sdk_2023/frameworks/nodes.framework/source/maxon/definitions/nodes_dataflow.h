#ifndef NODES_DATAFLOW_H__
#define NODES_DATAFLOW_H__

#include "maxon/fid.h"

#ifdef DOMAIN
	#undef DOMAIN // normally defined by math.h to indicate a domain error which can be reported by matherr()
#endif

//----------------------------------------------------------------------------------------
// BEGIN - auto generated code, do not edit
//----------------------------------------------------------------------------------------
namespace maxon
{
namespace NEUTRON
{
	namespace NODE
	{
		namespace RANGE
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.neutron.node.range");

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
			// supports MAXON::NODE::ITERATION::DOMAIN
			// supports MAXON::NODE::ITERATION::OUTERDOMAIN
			// supports MAXON::NODE::ITERATION::INNERDOMAIN

			MAXON_ATTRIBUTE(Int, START, "start");

			MAXON_ATTRIBUTE(Int, END, "end");

			MAXON_ATTRIBUTE(Int, OUT, "out");

			MAXON_ATTRIBUTE(Int, COUNT, "count");
		}
	}
}

namespace NODE
{
	namespace IF
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.if");

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

		MAXON_ATTRIBUTE(Id, DATATYPE, "datatype");

		MAXON_ATTRIBUTE(Bool, IN1, "in1");

		MAXON_ATTRIBUTE(Data, IN2, "in2");

		MAXON_ATTRIBUTE(Data, IN3, "in3");

		MAXON_ATTRIBUTE(Data, OUT, "out");
	}

	namespace ITERATION
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.iteration");

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

		MAXON_ATTRIBUTE(void, DOMAIN, "domain");

		MAXON_ATTRIBUTE(void, OUTERDOMAIN, "outerdomain");

		MAXON_ATTRIBUTE(void, INNERDOMAIN, "innerdomain");
	}

	namespace SWITCH
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.switch");

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

		MAXON_ATTRIBUTE(Id, DATATYPE, "datatype");

		MAXON_ATTRIBUTE(Int, INDEX, "index");

		MAXON_ATTRIBUTE(Bool, CYCLE, "cycle");

		MAXON_ATTRIBUTE(Data, IN, "in");

		MAXON_ATTRIBUTE(Data, OUT, "out");
	}
}
}
//----------------------------------------------------------------------------------------
// END - auto generated code, do not edit
//----------------------------------------------------------------------------------------


#include "nodes_dataflow1.hxx"
#include "nodes_dataflow2.hxx"

#endif // NODES_DATAFLOW_H__
