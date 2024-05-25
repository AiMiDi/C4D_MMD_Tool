#ifndef UTILITY_NODES_H__
#define UTILITY_NODES_H__

#include "maxon/fid.h"
#include "maxon/vector.h"

//----------------------------------------------------------------------------------------
// BEGIN - auto generated code, do not edit
//----------------------------------------------------------------------------------------
namespace maxon
{
namespace NODE
{
	namespace ANNOTATION
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.annotation");

		// supports MAXON::NODE::BASE::FILTERTAGS
		// supports MAXON::NODE::BASE::NODEPREVIEWIMAGE
		// supports MAXON::NODE::BASE::MATERIALPREVIEWIMAGE
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

		MAXON_ATTRIBUTE(Id, FONTSIZE, "net.maxon.node.annotation.fontsize",
			RESOURCE_DEFINE(ENUM_SMALL, LiteralId("small"))
			RESOURCE_DEFINE(ENUM_MEDIUM, LiteralId("medium"))
			RESOURCE_DEFINE(ENUM_LARGE, LiteralId("large"))
			RESOURCE_DEFINE(ENUM_EXTRA_LARGE, LiteralId("extra_large"))
			RESOURCE_DEFINE(ENUM_HUGE, LiteralId("huge")));

		MAXON_ATTRIBUTE(Bool, TRANSPARENTBACKGROUND, "net.maxon.node.annotation.transparentbackground");

		MAXON_ATTRIBUTE(String, PLACEHOLDERTEXT, "net.maxon.node.annotation.placeholdertext");
	}

	namespace BYPASSABLE
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.bypassable");

		// supports MAXON::NODE::BASE::FILTERTAGS
		// supports MAXON::NODE::BASE::NODEPREVIEWIMAGE
		// supports MAXON::NODE::BASE::MATERIALPREVIEWIMAGE
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

		MAXON_ATTRIBUTE(Bool, BYPASS, "net.maxon.node.bypassable.bypass");
	}

	//----------------------------------------------------------------------------------------
	/// INTERNAL.
	/// Node used to hold floating input and output ports.
	//----------------------------------------------------------------------------------------
	namespace FLOATINGIO
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.floatingio");

		// supports MAXON::NODE::BASE::FILTERTAGS
		// supports MAXON::NODE::BASE::NODEPREVIEWIMAGE
		// supports MAXON::NODE::BASE::MATERIALPREVIEWIMAGE
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

		/// True to define this floating I/O node for output ports.
		/// False (default) to use it for input ports.
		/// This is a node attribute, not a port attribute.
		MAXON_ATTRIBUTE(Bool, ATTRIBUTE_DIRECTION, "net.maxon.node.floatingio.attribute.direction");

		/// Template input that defines the list of inputs or outputs handled by this floating I/O node.
		MAXON_ATTRIBUTE(void, PORTLIST, "net.maxon.node.floatingio.portlist");
	}

	namespace GROUP
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.group");

		// supports MAXON::NODE::BASE::FILTERTAGS
		// supports MAXON::NODE::BASE::NODEPREVIEWIMAGE
		// supports MAXON::NODE::BASE::MATERIALPREVIEWIMAGE
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
	}

	namespace GROUPWITHPORTS
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.groupwithports");

		// supports MAXON::NODE::BASE::FILTERTAGS
		// supports MAXON::NODE::BASE::NODEPREVIEWIMAGE
		// supports MAXON::NODE::BASE::MATERIALPREVIEWIMAGE
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

		/// This is the default template port for user inports.
		MAXON_ATTRIBUTE(void, INPUT, "net.maxon.node.groupwithports.input");

		/// This is the default template port for user outports.
		MAXON_ATTRIBUTE(void, OUTPUT, "net.maxon.node.groupwithports.output");
	}

	namespace REROUTE
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.reroute");

		// supports MAXON::NODE::BASE::FILTERTAGS
		// supports MAXON::NODE::BASE::NODEPREVIEWIMAGE
		// supports MAXON::NODE::BASE::MATERIALPREVIEWIMAGE
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

		/// The input port of a reroute node.
		MAXON_ATTRIBUTE(void, IN, "in");

		/// The output port of a reroute node.
		MAXON_ATTRIBUTE(void, OUT, "out");
	}

	namespace SCAFFOLD
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.scaffold");

		// supports MAXON::NODE::BASE::FILTERTAGS
		// supports MAXON::NODE::BASE::NODEPREVIEWIMAGE
		// supports MAXON::NODE::BASE::MATERIALPREVIEWIMAGE
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

		MAXON_ATTRIBUTE(void, CONVERTTOGROUP, "net.maxon.node.scaffold.converttogroup");

		MAXON_ATTRIBUTE(void, DELETESCAFFOLDANDCONTENTS, "net.maxon.node.scaffold.deletescaffoldandcontents");
	}

	namespace STRENGTH
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.strength");

		// supports MAXON::NODE::BASE::FILTERTAGS
		// supports MAXON::NODE::BASE::NODEPREVIEWIMAGE
		// supports MAXON::NODE::BASE::MATERIALPREVIEWIMAGE
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

		MAXON_ATTRIBUTE(ColorA, INPUT, "input");

		MAXON_ATTRIBUTE(Float, STRENGTH, "strength");

		MAXON_ATTRIBUTE(ColorA, OUTPUT, "output");
	}

	namespace TYPE
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.type");

		// supports MAXON::NODE::BASE::FILTERTAGS
		// supports MAXON::NODE::BASE::NODEPREVIEWIMAGE
		// supports MAXON::NODE::BASE::MATERIALPREVIEWIMAGE
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

		MAXON_ATTRIBUTE(Id, DATATYPE, "datatype");

		MAXON_ATTRIBUTE(Data, IN, "in");

		MAXON_ATTRIBUTE(Data, OUT, "out");
	}

	namespace WITHPARAMETERS
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.withparameters");

		// supports MAXON::NODE::BASE::FILTERTAGS
		// supports MAXON::NODE::BASE::NODEPREVIEWIMAGE
		// supports MAXON::NODE::BASE::MATERIALPREVIEWIMAGE
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

		MAXON_ATTRIBUTE(void, PARAMETERSIN, "parametersin");
	}
}
}
//----------------------------------------------------------------------------------------
// END - auto generated code, do not edit
//----------------------------------------------------------------------------------------

#include "nodes_utility1.hxx"
	
#include "nodes_utility2.hxx"

#endif // UTILITY_NODES_H__
