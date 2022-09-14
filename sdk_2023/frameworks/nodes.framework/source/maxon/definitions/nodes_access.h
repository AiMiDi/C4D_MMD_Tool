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
		namespace COMPOSECOLOR32
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.access.composecolor32");

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

			MAXON_ATTRIBUTE(Color32, COLORIN, "colorin");

			MAXON_ATTRIBUTE(Float32, RIN, "rin");

			MAXON_ATTRIBUTE(Float32, GIN, "gin");

			MAXON_ATTRIBUTE(Float32, BIN, "bin");

			MAXON_ATTRIBUTE(Color32, COLOROUT, "colorout");
		}

		//----------------------------------------------------------------------------------------
		/// TO DO NODE IS TO BE HIDDEN FROM USER.
		/// Used for component access.
		//----------------------------------------------------------------------------------------
		namespace COMPOSECOLOR64
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.access.composecolor64");

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

			MAXON_ATTRIBUTE(Color64, COLORIN, "colorin");

			MAXON_ATTRIBUTE(Float64, RIN, "rin");

			MAXON_ATTRIBUTE(Float64, GIN, "gin");

			MAXON_ATTRIBUTE(Float64, BIN, "bin");

			MAXON_ATTRIBUTE(Color64, COLOROUT, "colorout");
		}

		//----------------------------------------------------------------------------------------
		/// TO DO NODE IS TO BE HIDDEN FROM USER.
		/// Used for component access.
		//----------------------------------------------------------------------------------------
		namespace COMPOSECOLORA32
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.access.composecolora32");

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

			MAXON_ATTRIBUTE(ColorA32, COLORIN, "colorin");

			MAXON_ATTRIBUTE(Float32, RIN, "rin");

			MAXON_ATTRIBUTE(Float32, GIN, "gin");

			MAXON_ATTRIBUTE(Float32, BIN, "bin");

			MAXON_ATTRIBUTE(Float32, ALPHAIN, "alphain");

			MAXON_ATTRIBUTE(ColorA32, COLOROUT, "colorout");
		}

		//----------------------------------------------------------------------------------------
		/// TO DO NODE IS TO BE HIDDEN FROM USER.
		/// Used for component access.
		//----------------------------------------------------------------------------------------
		namespace COMPOSECOLORA64
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.access.composecolora64");

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

			MAXON_ATTRIBUTE(ColorA64, COLORIN, "colorin");

			MAXON_ATTRIBUTE(Float64, RIN, "rin");

			MAXON_ATTRIBUTE(Float64, GIN, "gin");

			MAXON_ATTRIBUTE(Float64, BIN, "bin");

			MAXON_ATTRIBUTE(Float64, ALPHAIN, "alphain");

			MAXON_ATTRIBUTE(ColorA64, COLOROUT, "colorout");
		}

		//----------------------------------------------------------------------------------------
		/// TO DO NODE IS TO BE HIDDEN FROM USER.
		/// Used for component access.
		//----------------------------------------------------------------------------------------
		namespace COMPOSEMATRIX32
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.access.composematrix32");

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

			MAXON_ATTRIBUTE(Matrix32, MATRIXIN, "matrixin");

			MAXON_ATTRIBUTE(Vector32, TRANSLATIONIN, "translationin");

			MAXON_ATTRIBUTE(Vector32, ROTATIONIN, "rotationin");

			MAXON_ATTRIBUTE(Vector32, SCALEIN, "scalein");

			MAXON_ATTRIBUTE(Vector32, SHEARIN, "shearin");

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

			MAXON_ATTRIBUTE(Matrix32, MATRIXOUT, "matrixout");
		}

		//----------------------------------------------------------------------------------------
		/// TO DO NODE IS TO BE HIDDEN FROM USER.
		/// Used for component access.
		//----------------------------------------------------------------------------------------
		namespace COMPOSEMATRIX64
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.access.composematrix64");

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

			MAXON_ATTRIBUTE(Matrix64, MATRIXIN, "matrixin");

			MAXON_ATTRIBUTE(Vector64, TRANSLATIONIN, "translationin");

			MAXON_ATTRIBUTE(Vector64, ROTATIONIN, "rotationin");

			MAXON_ATTRIBUTE(Vector64, SCALEIN, "scalein");

			MAXON_ATTRIBUTE(Vector64, SHEARIN, "shearin");

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

			MAXON_ATTRIBUTE(Matrix64, MATRIXOUT, "matrixout");
		}

		//----------------------------------------------------------------------------------------
		/// TO DO NODE IS TO BE HIDDEN FROM USER.
		/// Used for component access.
		//----------------------------------------------------------------------------------------
		namespace COMPOSEVECTOR2D32
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.access.composevector2d32");

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

			MAXON_ATTRIBUTE(Vector2d32, VECTORIN, "vectorin");

			MAXON_ATTRIBUTE(Float32, XIN, "xin");

			MAXON_ATTRIBUTE(Float32, YIN, "yin");

			MAXON_ATTRIBUTE(Vector2d32, VECTOROUT, "vectorout");
		}

		//----------------------------------------------------------------------------------------
		/// TO DO NODE IS TO BE HIDDEN FROM USER.
		/// Used for component access.
		//----------------------------------------------------------------------------------------
		namespace COMPOSEVECTOR2D64
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.access.composevector2d64");

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

			MAXON_ATTRIBUTE(Vector2d64, VECTORIN, "vectorin");

			MAXON_ATTRIBUTE(Float64, XIN, "xin");

			MAXON_ATTRIBUTE(Float64, YIN, "yin");

			MAXON_ATTRIBUTE(Vector2d64, VECTOROUT, "vectorout");
		}

		//----------------------------------------------------------------------------------------
		/// TO DO NODE IS TO BE HIDDEN FROM USER.
		/// Used for component access.
		//----------------------------------------------------------------------------------------
		namespace COMPOSEVECTOR3D32
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.access.composevector3d32");

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

			MAXON_ATTRIBUTE(Vector32, VECTORIN, "vectorin");

			MAXON_ATTRIBUTE(Float32, XIN, "xin");

			MAXON_ATTRIBUTE(Float32, YIN, "yin");

			MAXON_ATTRIBUTE(Float32, ZIN, "zin");

			MAXON_ATTRIBUTE(Vector32, VECTOROUT, "vectorout");
		}

		//----------------------------------------------------------------------------------------
		/// TO DO NODE IS TO BE HIDDEN FROM USER.
		/// Used for component access.
		//----------------------------------------------------------------------------------------
		namespace COMPOSEVECTOR3D64
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.access.composevector3d64");

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

			MAXON_ATTRIBUTE(Vector64, VECTORIN, "vectorin");

			MAXON_ATTRIBUTE(Float64, XIN, "xin");

			MAXON_ATTRIBUTE(Float64, YIN, "yin");

			MAXON_ATTRIBUTE(Float64, ZIN, "zin");

			MAXON_ATTRIBUTE(Vector64, VECTOROUT, "vectorout");
		}

		//----------------------------------------------------------------------------------------
		/// TO DO NODE IS TO BE HIDDEN FROM USER.
		/// Used for component access.
		//----------------------------------------------------------------------------------------
		namespace COMPOSEVECTOR4D32
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.access.composevector4d32");

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

			MAXON_ATTRIBUTE(Vector4d32, VECTORIN, "vectorin");

			MAXON_ATTRIBUTE(Float32, XIN, "xin");

			MAXON_ATTRIBUTE(Float32, YIN, "yin");

			MAXON_ATTRIBUTE(Float32, ZIN, "zin");

			MAXON_ATTRIBUTE(Float32, WIN, "win");

			MAXON_ATTRIBUTE(Vector4d32, VECTOROUT, "vectorout");
		}

		//----------------------------------------------------------------------------------------
		/// TO DO NODE IS TO BE HIDDEN FROM USER.
		/// Used for component access.
		//----------------------------------------------------------------------------------------
		namespace COMPOSEVECTOR4D64
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.access.composevector4d64");

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

			MAXON_ATTRIBUTE(Vector4d64, VECTORIN, "vectorin");

			MAXON_ATTRIBUTE(Float64, XIN, "xin");

			MAXON_ATTRIBUTE(Float64, YIN, "yin");

			MAXON_ATTRIBUTE(Float64, ZIN, "zin");

			MAXON_ATTRIBUTE(Float64, WIN, "win");

			MAXON_ATTRIBUTE(Vector4d64, VECTOROUT, "vectorout");
		}

		//----------------------------------------------------------------------------------------
		/// TO DO NODE IS TO BE HIDDEN FROM USER.
		/// Used for component access.
		//----------------------------------------------------------------------------------------
		namespace DECOMPOSECOLOR32
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.access.decomposecolor32");

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

			MAXON_ATTRIBUTE(Color32, COLORIN, "colorin");

			MAXON_ATTRIBUTE(Float32, ROUT, "rout");

			MAXON_ATTRIBUTE(Float32, GOUT, "gout");

			MAXON_ATTRIBUTE(Float32, BOUT, "bout");
		}

		//----------------------------------------------------------------------------------------
		/// TO DO NODE IS TO BE HIDDEN FROM USER.
		/// Used for component access.
		//----------------------------------------------------------------------------------------
		namespace DECOMPOSECOLOR64
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.access.decomposecolor64");

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

			MAXON_ATTRIBUTE(Color64, COLORIN, "colorin");

			MAXON_ATTRIBUTE(Float64, ROUT, "rout");

			MAXON_ATTRIBUTE(Float64, GOUT, "gout");

			MAXON_ATTRIBUTE(Float64, BOUT, "bout");
		}

		//----------------------------------------------------------------------------------------
		/// TO DO NODE IS TO BE HIDDEN FROM USER.
		/// Used for component access.
		//----------------------------------------------------------------------------------------
		namespace DECOMPOSECOLORA32
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.access.decomposecolora32");

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

			MAXON_ATTRIBUTE(ColorA32, COLORIN, "colorin");

			MAXON_ATTRIBUTE(Float32, ROUT, "rout");

			MAXON_ATTRIBUTE(Float32, GOUT, "gout");

			MAXON_ATTRIBUTE(Float32, BOUT, "bout");

			MAXON_ATTRIBUTE(Float32, ALPHAOUT, "alphaout");
		}

		//----------------------------------------------------------------------------------------
		/// TO DO NODE IS TO BE HIDDEN FROM USER.
		/// Used for component access.
		//----------------------------------------------------------------------------------------
		namespace DECOMPOSECOLORA64
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.access.decomposecolora64");

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

			MAXON_ATTRIBUTE(ColorA64, COLORIN, "colorin");

			MAXON_ATTRIBUTE(Float64, ROUT, "rout");

			MAXON_ATTRIBUTE(Float64, GOUT, "gout");

			MAXON_ATTRIBUTE(Float64, BOUT, "bout");

			MAXON_ATTRIBUTE(Float64, ALPHAOUT, "alphaout");
		}

		//----------------------------------------------------------------------------------------
		/// TO DO NODE IS TO BE HIDDEN FROM USER.
		/// Used for component access.
		//----------------------------------------------------------------------------------------
		namespace DECOMPOSEMATRIX32
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.access.decomposematrix32");

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

			MAXON_ATTRIBUTE(Matrix32, MATRIXIN, "matrixin");

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

			MAXON_ATTRIBUTE(Vector32, TRANSLATIONOUT, "translationout");

			MAXON_ATTRIBUTE(Vector32, ROTATIONOUT, "rotationout");

			MAXON_ATTRIBUTE(Vector32, SCALEOUT, "scaleout");

			MAXON_ATTRIBUTE(Vector32, SHEAROUT, "shearout");
		}

		//----------------------------------------------------------------------------------------
		/// TO DO NODE IS TO BE HIDDEN FROM USER.
		/// Used for component access.
		//----------------------------------------------------------------------------------------
		namespace DECOMPOSEMATRIX64
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.access.decomposematrix64");

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

			MAXON_ATTRIBUTE(Matrix64, MATRIXIN, "matrixin");

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

			MAXON_ATTRIBUTE(Vector64, TRANSLATIONOUT, "translationout");

			MAXON_ATTRIBUTE(Vector64, ROTATIONOUT, "rotationout");

			MAXON_ATTRIBUTE(Vector64, SCALEOUT, "scaleout");

			MAXON_ATTRIBUTE(Vector64, SHEAROUT, "shearout");
		}

		//----------------------------------------------------------------------------------------
		/// TO DO NODE IS TO BE HIDDEN FROM USER.
		/// Used for component access.
		//----------------------------------------------------------------------------------------
		namespace DECOMPOSEVECTOR2D32
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.access.decomposevector2d32");

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

			MAXON_ATTRIBUTE(Vector2d32, VECTORIN, "vectorin");

			MAXON_ATTRIBUTE(Float32, XOUT, "xout");

			MAXON_ATTRIBUTE(Float32, YOUT, "yout");
		}

		//----------------------------------------------------------------------------------------
		/// TO DO NODE IS TO BE HIDDEN FROM USER.
		/// Used for component access.
		//----------------------------------------------------------------------------------------
		namespace DECOMPOSEVECTOR2D64
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.access.decomposevector2d64");

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

			MAXON_ATTRIBUTE(Vector2d64, VECTORIN, "vectorin");

			MAXON_ATTRIBUTE(Float64, XOUT, "xout");

			MAXON_ATTRIBUTE(Float64, YOUT, "yout");
		}

		//----------------------------------------------------------------------------------------
		/// TO DO NODE IS TO BE HIDDEN FROM USER.
		/// Used for component access.
		//----------------------------------------------------------------------------------------
		namespace DECOMPOSEVECTOR3D32
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.access.decomposevector3d32");

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

			MAXON_ATTRIBUTE(Vector32, VECTORIN, "vectorin");

			MAXON_ATTRIBUTE(Float32, XOUT, "xout");

			MAXON_ATTRIBUTE(Float32, YOUT, "yout");

			MAXON_ATTRIBUTE(Float32, ZOUT, "zout");
		}

		//----------------------------------------------------------------------------------------
		/// TO DO NODE IS TO BE HIDDEN FROM USER.
		/// Used for component access.
		//----------------------------------------------------------------------------------------
		namespace DECOMPOSEVECTOR3D64
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.access.decomposevector3d64");

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

			MAXON_ATTRIBUTE(Vector64, VECTORIN, "vectorin");

			MAXON_ATTRIBUTE(Float64, XOUT, "xout");

			MAXON_ATTRIBUTE(Float64, YOUT, "yout");

			MAXON_ATTRIBUTE(Float64, ZOUT, "zout");
		}

		//----------------------------------------------------------------------------------------
		/// TO DO NODE IS TO BE HIDDEN FROM USER.
		/// Used for component access.
		//----------------------------------------------------------------------------------------
		namespace DECOMPOSEVECTOR4D32
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.access.decomposevector4d32");

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

			MAXON_ATTRIBUTE(Vector4d32, VECTORIN, "vectorin");

			MAXON_ATTRIBUTE(Float32, XOUT, "xout");

			MAXON_ATTRIBUTE(Float32, YOUT, "yout");

			MAXON_ATTRIBUTE(Float32, ZOUT, "zout");

			MAXON_ATTRIBUTE(Float32, WOUT, "wout");
		}

		//----------------------------------------------------------------------------------------
		/// TO DO NODE IS TO BE HIDDEN FROM USER.
		/// Used for component access.
		//----------------------------------------------------------------------------------------
		namespace DECOMPOSEVECTOR4D64
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.access.decomposevector4d64");

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

			MAXON_ATTRIBUTE(Vector4d64, VECTORIN, "vectorin");

			MAXON_ATTRIBUTE(Float64, XOUT, "xout");

			MAXON_ATTRIBUTE(Float64, YOUT, "yout");

			MAXON_ATTRIBUTE(Float64, ZOUT, "zout");

			MAXON_ATTRIBUTE(Float64, WOUT, "wout");
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
