#ifndef NODES_META_H__
#define NODES_META_H__

#include "maxon/fid.h"

//----------------------------------------------------------------------------------------
// BEGIN - auto generated code, do not edit
//----------------------------------------------------------------------------------------
namespace maxon
{
namespace NODE
{
	namespace META
	{
		namespace GETPORTID
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.meta.getportid");

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

			MAXON_ATTRIBUTE(void, PORTIN, "portin");

			MAXON_ATTRIBUTE(NodePath, PATHOUT, "pathout");

			MAXON_ATTRIBUTE(InternedId, IDOUT, "idout");
		}

		namespace HASVALUE
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.meta.hasvalue");

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

			MAXON_ATTRIBUTE(void, PORTIN, "portin");

			MAXON_ATTRIBUTE(Bool, HASVALUEOUT, "hasvalueout");
		}
	}

	//----------------------------------------------------------------------------------------
	/// This node allows to instantiate an arbitrary node using its asset identifier.
	//----------------------------------------------------------------------------------------
	namespace NODEASSET
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.nodeasset");

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

		MAXON_ATTRIBUTE(CString, ASSET, "net.maxon.node.nodeasset.asset");

		MAXON_ATTRIBUTE(Id, VERSION, "net.maxon.node.nodeasset.version");
	}

	namespace TYPEOF
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.typeof");

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

		MAXON_ATTRIBUTE(void, IN, "in");

		MAXON_ATTRIBUTE(DataType, OUT, "out");
	}

	namespace VARIADICCOUNT
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.variadiccount");

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

		MAXON_ATTRIBUTE(void, IN, "in");

		MAXON_ATTRIBUTE(Int, OUT, "out");
	}
}
}
//----------------------------------------------------------------------------------------
// END - auto generated code, do not edit
//----------------------------------------------------------------------------------------


#include "nodes_meta1.hxx"
#include "nodes_meta2.hxx"

#endif // NODES_META_H__
