#ifndef NODES_ACCESS_H__
#define NODES_ACCESS_H__

#include "maxon/fid.h"
#include "maxon/vector4d.h"

//----------------------------------------------------------------------------------------
// BEGIN - auto generated code, do not edit
//----------------------------------------------------------------------------------------
namespace maxon
{
namespace NODE
{
	namespace ACCESS
	{
		//----------------------------------------------------------------------------------------
		/// TO DO NODE IS TO BE HIDDEN FROM USER.
		/// Used for component access.
		//----------------------------------------------------------------------------------------
		namespace COMPOSECOLOR
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.access.composecolor");

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

			MAXON_ATTRIBUTE(Color, COLORIN, "colorin");

			MAXON_ATTRIBUTE(Float, RIN, "rin");

			MAXON_ATTRIBUTE(Float, GIN, "gin");

			MAXON_ATTRIBUTE(Float, BIN, "bin");

			MAXON_ATTRIBUTE(Color, COLOROUT, "colorout");
		}

		//----------------------------------------------------------------------------------------
		/// TO DO NODE IS TO BE HIDDEN FROM USER.
		/// Used for component access.
		//----------------------------------------------------------------------------------------
		namespace COMPOSECOLORA
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.access.composecolora");

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

			MAXON_ATTRIBUTE(ColorA, COLORIN, "colorin");

			MAXON_ATTRIBUTE(Float, RIN, "rin");

			MAXON_ATTRIBUTE(Float, GIN, "gin");

			MAXON_ATTRIBUTE(Float, BIN, "bin");

			MAXON_ATTRIBUTE(Float, ALPHAIN, "alphain");

			MAXON_ATTRIBUTE(ColorA, COLOROUT, "colorout");
		}

		//----------------------------------------------------------------------------------------
		/// TO DO NODE IS TO BE HIDDEN FROM USER.
		/// Used for component access.
		//----------------------------------------------------------------------------------------
		namespace COMPOSEMATRIX
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.access.composematrix");

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

			MAXON_ATTRIBUTE(Matrix, MATRIXIN, "matrixin");

			MAXON_ATTRIBUTE(Vector, TRANSLATIONIN, "translationin");

			MAXON_ATTRIBUTE(Vector, ROTATIONIN, "rotationin");

			MAXON_ATTRIBUTE(Vector, SCALEIN, "scalein");

			MAXON_ATTRIBUTE(Id, ROTATIONORDERIN, "rotationorderin",
				RESOURCE_DEFINE(ENUM_XYZLOCAL, Id("xyzlocal"))
				RESOURCE_DEFINE(ENUM_XZYLOCAL, Id("xzylocal"))
				RESOURCE_DEFINE(ENUM_YXZLOCAL, Id("yxzlocal"))
				RESOURCE_DEFINE(ENUM_YZXLOCAL, Id("yzxlocal"))
				RESOURCE_DEFINE(ENUM_ZXYLOCAL, Id("zxylocal"))
				RESOURCE_DEFINE(ENUM_ZYXLOCAL, Id("zyxlocal"))
				RESOURCE_DEFINE(ENUM_XYZGLOBAL, Id("xyzglobal"))
				RESOURCE_DEFINE(ENUM_XZYGLOBAL, Id("xzyglobal"))
				RESOURCE_DEFINE(ENUM_YXZGLOBAL, Id("yxzglobal"))
				RESOURCE_DEFINE(ENUM_YZXGLOBAL, Id("yzxglobal"))
				RESOURCE_DEFINE(ENUM_ZXYGLOBAL, Id("zxyglobal"))
				RESOURCE_DEFINE(ENUM_ZYXGLOBAL, Id("zyxglobal")));

			MAXON_ATTRIBUTE(Matrix, MATRIXOUT, "matrixout");
		}

		//----------------------------------------------------------------------------------------
		/// TO DO NODE IS TO BE HIDDEN FROM USER.
		/// Used for component access.
		//----------------------------------------------------------------------------------------
		namespace COMPOSEVECTOR
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.access.composevector");

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

			MAXON_ATTRIBUTE(Vector, VECTORIN, "vectorin");

			MAXON_ATTRIBUTE(Float, XIN, "xin");

			MAXON_ATTRIBUTE(Float, YIN, "yin");

			MAXON_ATTRIBUTE(Float, ZIN, "zin");

			MAXON_ATTRIBUTE(Vector, VECTOROUT, "vectorout");
		}

		//----------------------------------------------------------------------------------------
		/// TO DO NODE IS TO BE HIDDEN FROM USER.
		/// Used for component access.
		//----------------------------------------------------------------------------------------
		namespace DECOMPOSECOLOR
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.access.decomposecolor");

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

			MAXON_ATTRIBUTE(Color, COLORIN, "colorin");

			MAXON_ATTRIBUTE(Float, ROUT, "rout");

			MAXON_ATTRIBUTE(Float, GOUT, "gout");

			MAXON_ATTRIBUTE(Float, BOUT, "bout");
		}

		//----------------------------------------------------------------------------------------
		/// TO DO NODE IS TO BE HIDDEN FROM USER.
		/// Used for component access.
		//----------------------------------------------------------------------------------------
		namespace DECOMPOSECOLORA
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.access.decomposecolora");

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

			MAXON_ATTRIBUTE(ColorA, COLORIN, "colorin");

			MAXON_ATTRIBUTE(Float, ROUT, "rout");

			MAXON_ATTRIBUTE(Float, GOUT, "gout");

			MAXON_ATTRIBUTE(Float, BOUT, "bout");

			MAXON_ATTRIBUTE(Float, ALPHAOUT, "alphaout");
		}

		//----------------------------------------------------------------------------------------
		/// TO DO NODE IS TO BE HIDDEN FROM USER.
		/// Used for component access.
		//----------------------------------------------------------------------------------------
		namespace DECOMPOSEMATRIX
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.access.decomposematrix");

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

			MAXON_ATTRIBUTE(Matrix, MATRIXIN, "matrixin");

			MAXON_ATTRIBUTE(Id, ROTATIONORDERIN, "rotationorderin",
				RESOURCE_DEFINE(ENUM_XYZLOCAL, Id("xyzlocal"))
				RESOURCE_DEFINE(ENUM_XZYLOCAL, Id("xzylocal"))
				RESOURCE_DEFINE(ENUM_YXZLOCAL, Id("yxzlocal"))
				RESOURCE_DEFINE(ENUM_YZXLOCAL, Id("yzxlocal"))
				RESOURCE_DEFINE(ENUM_ZXYLOCAL, Id("zxylocal"))
				RESOURCE_DEFINE(ENUM_ZYXLOCAL, Id("zyxlocal"))
				RESOURCE_DEFINE(ENUM_XYZGLOBAL, Id("xyzglobal"))
				RESOURCE_DEFINE(ENUM_XZYGLOBAL, Id("xzyglobal"))
				RESOURCE_DEFINE(ENUM_YXZGLOBAL, Id("yxzglobal"))
				RESOURCE_DEFINE(ENUM_YZXGLOBAL, Id("yzxglobal"))
				RESOURCE_DEFINE(ENUM_ZXYGLOBAL, Id("zxyglobal"))
				RESOURCE_DEFINE(ENUM_ZYXGLOBAL, Id("zyxglobal")));

			MAXON_ATTRIBUTE(Vector, TRANSLATIONOUT, "translationout");

			MAXON_ATTRIBUTE(Vector, ROTATIONOUT, "rotationout");

			MAXON_ATTRIBUTE(Vector, SCALEOUT, "scaleout");
		}

		//----------------------------------------------------------------------------------------
		/// TO DO NODE IS TO BE HIDDEN FROM USER.
		/// Used for component access.
		//----------------------------------------------------------------------------------------
		namespace DECOMPOSEVECTOR
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.access.decomposevector");

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

			MAXON_ATTRIBUTE(Vector, VECTORIN, "vectorin");

			MAXON_ATTRIBUTE(Float, XOUT, "xout");

			MAXON_ATTRIBUTE(Float, YOUT, "yout");

			MAXON_ATTRIBUTE(Float, ZOUT, "zout");
		}
	}
}
}
//----------------------------------------------------------------------------------------
// END - auto generated code, do not edit
//----------------------------------------------------------------------------------------


#include "nodes_access1.hxx"
#include "nodes_access2.hxx"

#endif // NODES_ACCESS_H__
