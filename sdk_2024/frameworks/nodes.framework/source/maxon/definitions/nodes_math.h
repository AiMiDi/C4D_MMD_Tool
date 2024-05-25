#ifndef MATH_NODES_H__
#define MATH_NODES_H__

#include "maxon/fid.h"
#include "maxon/vector.h"
#include "maxon/vector2d.h"
#include "maxon/vector4d.h"

#ifdef DOMAIN
	#undef DOMAIN // normally defined by math.h to indicate a domain error which can be reported by matherr()
#endif

//----------------------------------------------------------------------------------------
// BEGIN - auto generated code, do not edit
//----------------------------------------------------------------------------------------
namespace maxon
{
namespace NODE
{
	namespace ABS
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.abs");

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

	namespace AGGREGATE
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.aggregate");

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
		// supports MAXON::NODE::AGGREGATION::OUTERDOMAIN
		// supports MAXON::NODE::AGGREGATION::INNERDOMAIN
		// supports MAXON::NODE::AGGREGATION::DOMAIN

		MAXON_ATTRIBUTE(Id, OPERATION, "operation");

		MAXON_ATTRIBUTE(Bool, STREAMMODE, "streammode");

		MAXON_ATTRIBUTE(Id, DATATYPE, "datatype");

		MAXON_ATTRIBUTE(Data, STREAM, "stream");

		MAXON_ATTRIBUTE(Data, IN, "in");

		MAXON_ATTRIBUTE(Data, OUT, "out");
	}

	namespace AGGREGATION
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.aggregation");

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

		MAXON_ATTRIBUTE(void, OUTERDOMAIN, "outerdomain");

		MAXON_ATTRIBUTE(void, INNERDOMAIN, "innerdomain");

		MAXON_ATTRIBUTE(void, DOMAIN, "domain");
	}

	namespace ANGLE
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.angle");

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

		MAXON_ATTRIBUTE(Id, OPERATION, "operation");

		MAXON_ATTRIBUTE(Id, DATATYPE, "datatype");

		MAXON_ATTRIBUTE(Data, IN1, "in1");

		MAXON_ATTRIBUTE(Data, IN2, "in2");

		MAXON_ATTRIBUTE(Data, OUT, "out");
	}

	namespace ANYANDALL
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.anyandall");

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

		MAXON_ATTRIBUTE(Id, OPERATION, "operation");

		MAXON_ATTRIBUTE(Id, DATATYPE, "datatype");

		MAXON_ATTRIBUTE(Data, IN, "in");

		MAXON_ATTRIBUTE(Bool, OUT, "out");
	}

	namespace ARITHMETIC
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.arithmetic");

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

		MAXON_ATTRIBUTE(Id, OPERATION, "operation");

		MAXON_ATTRIBUTE(Id, DATATYPE, "datatype");

		MAXON_ATTRIBUTE(Data, IN1, "in1");

		MAXON_ATTRIBUTE(Data, IN2, "in2");

		MAXON_ATTRIBUTE(Data, OUT, "out");
	}

	namespace ATAN2
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.atan2");

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

		MAXON_ATTRIBUTE(Data, IN1, "in1");

		MAXON_ATTRIBUTE(Data, IN2, "in2");

		MAXON_ATTRIBUTE(Data, OUT, "out");
	}

	namespace BLEND
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.blend");

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

		MAXON_ATTRIBUTE(Float, IN3, "in3");

		MAXON_ATTRIBUTE(Data, IN1, "in1");

		MAXON_ATTRIBUTE(Data, IN2, "in2");

		MAXON_ATTRIBUTE(Data, OUT, "out");
	}

	namespace BOOLEANOPERATOR
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.booleanoperator");

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

		MAXON_ATTRIBUTE(Id, OPERATION, "operation");

		MAXON_ATTRIBUTE(Bool, IN1, "in1");

		MAXON_ATTRIBUTE(Bool, IN2, "in2");

		MAXON_ATTRIBUTE(Bool, OUT, "out");
	}

	namespace BOXSTEP
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.boxstep");

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

		MAXON_ATTRIBUTE(Data, IN1, "in1");

		MAXON_ATTRIBUTE(Data, IN2, "in2");

		MAXON_ATTRIBUTE(Data, IN3, "in3");

		MAXON_ATTRIBUTE(Data, OUT, "out");
	}

	namespace CLAMP
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.clamp");

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

		MAXON_ATTRIBUTE(Data, IN1, "in1");

		MAXON_ATTRIBUTE(Data, IN2, "in2");

		MAXON_ATTRIBUTE(Data, IN3, "in3");

		MAXON_ATTRIBUTE(Data, OUT, "out");
	}

	namespace COMPARE
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.compare");

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

		MAXON_ATTRIBUTE(Id, OPERATION, "operation");

		MAXON_ATTRIBUTE(Id, DATATYPE, "datatype");

		MAXON_ATTRIBUTE(Data, IN1, "in1");

		MAXON_ATTRIBUTE(Data, IN2, "in2");

		MAXON_ATTRIBUTE(Data, OUT, "out");
	}

	namespace COMPOSEMATRIX
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.composematrix");

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

		MAXON_ATTRIBUTE(Vector, TRANSLATION, "translation");

		MAXON_ATTRIBUTE(Vector, SCALE, "scale");

		MAXON_ATTRIBUTE(Vector, ROTATION, "rotation");

		MAXON_ATTRIBUTE(Matrix, OUT, "out");

		MAXON_ATTRIBUTE(Id, ROTATIONORDER, "rotationorder",
			RESOURCE_DEFINE(ENUM_XYZLOCAL, LiteralId("xyzlocal"))
			RESOURCE_DEFINE(ENUM_XZYLOCAL, LiteralId("xzylocal"))
			RESOURCE_DEFINE(ENUM_YXZLOCAL, LiteralId("yxzlocal"))
			RESOURCE_DEFINE(ENUM_YZXLOCAL, LiteralId("yzxlocal"))
			RESOURCE_DEFINE(ENUM_ZXYLOCAL, LiteralId("zxylocal"))
			RESOURCE_DEFINE(ENUM_ZYXLOCAL, LiteralId("zyxlocal"))
			RESOURCE_DEFINE(ENUM_XYZGLOBAL, LiteralId("xyzglobal"))
			RESOURCE_DEFINE(ENUM_XZYGLOBAL, LiteralId("xzyglobal"))
			RESOURCE_DEFINE(ENUM_YXZGLOBAL, LiteralId("yxzglobal"))
			RESOURCE_DEFINE(ENUM_YZXGLOBAL, LiteralId("yzxglobal"))
			RESOURCE_DEFINE(ENUM_ZXYGLOBAL, LiteralId("zxyglobal"))
			RESOURCE_DEFINE(ENUM_ZYXGLOBAL, LiteralId("zyxglobal")));
	}

	namespace CROSS
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.cross");

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

		MAXON_ATTRIBUTE(Data, IN1, "in1");

		MAXON_ATTRIBUTE(Data, IN2, "in2");

		MAXON_ATTRIBUTE(Data, OUT, "out");
	}

	namespace DECOMPOSEMATRIX
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.decomposematrix");

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

		MAXON_ATTRIBUTE(Id, ROTATIONORDER, "rotationorder",
			RESOURCE_DEFINE(ENUM_XYZLOCAL, LiteralId("xyzlocal"))
			RESOURCE_DEFINE(ENUM_XZYLOCAL, LiteralId("xzylocal"))
			RESOURCE_DEFINE(ENUM_YXZLOCAL, LiteralId("yxzlocal"))
			RESOURCE_DEFINE(ENUM_YZXLOCAL, LiteralId("yzxlocal"))
			RESOURCE_DEFINE(ENUM_ZXYLOCAL, LiteralId("zxylocal"))
			RESOURCE_DEFINE(ENUM_ZYXLOCAL, LiteralId("zyxlocal"))
			RESOURCE_DEFINE(ENUM_XYZGLOBAL, LiteralId("xyzglobal"))
			RESOURCE_DEFINE(ENUM_XZYGLOBAL, LiteralId("xzyglobal"))
			RESOURCE_DEFINE(ENUM_YXZGLOBAL, LiteralId("yxzglobal"))
			RESOURCE_DEFINE(ENUM_YZXGLOBAL, LiteralId("yzxglobal"))
			RESOURCE_DEFINE(ENUM_ZXYGLOBAL, LiteralId("zxyglobal"))
			RESOURCE_DEFINE(ENUM_ZYXGLOBAL, LiteralId("zyxglobal")));

		MAXON_ATTRIBUTE(Matrix, MATRIX, "matrix");

		MAXON_ATTRIBUTE(Data, TRANSLATION, "translation");

		MAXON_ATTRIBUTE(Data, SCALE, "scale");

		MAXON_ATTRIBUTE(Data, ROTATION, "rotation");
	}

	namespace DISTANCE
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.distance");

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

		MAXON_ATTRIBUTE(Id, OPERATION, "operation");

		MAXON_ATTRIBUTE(Id, DATATYPE, "datatype");

		MAXON_ATTRIBUTE(Data, IN1, "in1");

		MAXON_ATTRIBUTE(Data, IN2, "in2");

		MAXON_ATTRIBUTE(Data, OUT, "out");
	}

	namespace DOT
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.dot");

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

		MAXON_ATTRIBUTE(Data, IN1, "in1");

		MAXON_ATTRIBUTE(Data, IN2, "in2");

		MAXON_ATTRIBUTE(Data, OUT, "out");
	}

	namespace EXP
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.exp");

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

	namespace EXP2
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.exp2");

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

	namespace FRACTION
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.fraction");

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

	namespace INVERSEMATRIX
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.inversematrix");

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

		MAXON_ATTRIBUTE(Matrix, IN, "in");

		MAXON_ATTRIBUTE(Matrix, OUT, "out");
	}

	namespace INVERT
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.invert");

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

	namespace LENGTH
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.length");

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

		MAXON_ATTRIBUTE(Id, OPERATION, "operation");

		MAXON_ATTRIBUTE(Id, DATATYPE, "datatype");

		MAXON_ATTRIBUTE(Data, IN, "in");

		MAXON_ATTRIBUTE(Data, OUT, "out");
	}

	namespace LOG
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.log");

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

	namespace LOG2
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.log2");

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

	namespace MAPRANGE
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.maprange");

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

		MAXON_ATTRIBUTE(Data, IN1, "in1");

		MAXON_ATTRIBUTE(Data, IN2, "in2");

		MAXON_ATTRIBUTE(Data, IN3, "in3");

		MAXON_ATTRIBUTE(Data, IN4, "in4");

		MAXON_ATTRIBUTE(Data, IN5, "in5");

		MAXON_ATTRIBUTE(Data, OUT, "out");
	}

	namespace MATRIXTOVECTORS
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.matrixtovectors");

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

		MAXON_ATTRIBUTE(Matrix, MATRIX, "matrix");

		MAXON_ATTRIBUTE(Data, V1, "v1");

		MAXON_ATTRIBUTE(Data, V2, "v2");

		MAXON_ATTRIBUTE(Data, V3, "v3");

		MAXON_ATTRIBUTE(Data, OFF, "off");
	}

	namespace MODULO
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.modulo");

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

		MAXON_ATTRIBUTE(Data, IN1, "in1");

		MAXON_ATTRIBUTE(Data, IN2, "in2");

		MAXON_ATTRIBUTE(Data, OUT, "out");
	}

	namespace NEGATE
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.negate");

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

	namespace NOISE
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.noise");

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

		MAXON_ATTRIBUTE(Vector, VALUE, "value");

		MAXON_ATTRIBUTE(Float, TIME, "time");

		MAXON_ATTRIBUTE(Float, SCALE, "scale");

		MAXON_ATTRIBUTE(Bool, TWOD, "twod");

		MAXON_ATTRIBUTE(Id, NOISETYPE, "noisetype");

		MAXON_ATTRIBUTE(Float, OCTAVES, "octaves");

		MAXON_ATTRIBUTE(Bool, ABSOLUTE, "absolute");

		MAXON_ATTRIBUTE(Int, SEED, "seed");

		MAXON_ATTRIBUTE(Float, LACUNARITY, "lacunarity");

		MAXON_ATTRIBUTE(Float, GAIN, "gain");

		MAXON_ATTRIBUTE(Float, EXPONENT, "exponent");

		MAXON_ATTRIBUTE(Float, RESULT, "result");
	}

	namespace NORMALIZE
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.normalize");

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

	namespace POW
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.pow");

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

		MAXON_ATTRIBUTE(Data, IN1, "in1");

		MAXON_ATTRIBUTE(Data, IN2, "in2");

		MAXON_ATTRIBUTE(Data, OUT, "out");
	}

	namespace QUANTIZE
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.quantize");

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

		MAXON_ATTRIBUTE(Data, IN1, "in1");

		MAXON_ATTRIBUTE(Data, IN2, "in2");

		MAXON_ATTRIBUTE(Data, OUT, "out");
	}

	namespace RECIPROCAL
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.reciprocal");

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

	namespace REFLECT
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.reflect");

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

		MAXON_ATTRIBUTE(Data, IN1, "in1");

		MAXON_ATTRIBUTE(Data, IN2, "in2");

		MAXON_ATTRIBUTE(Data, OUT, "out");
	}

	namespace ROOT
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.root");

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

		MAXON_ATTRIBUTE(Id, OPERATION, "operation");

		MAXON_ATTRIBUTE(Id, DATATYPE, "datatype");

		MAXON_ATTRIBUTE(Data, IN, "in");

		MAXON_ATTRIBUTE(Data, OUT, "out");
	}

	namespace ROUND
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.round");

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

		MAXON_ATTRIBUTE(Id, OPERATION, "operation");

		MAXON_ATTRIBUTE(Id, DATATYPE, "datatype");

		MAXON_ATTRIBUTE(Data, IN, "in");

		MAXON_ATTRIBUTE(Data, OUT, "out");
	}

	namespace SCALE
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.scale");

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

		MAXON_ATTRIBUTE(Data, IN1, "in1");

		MAXON_ATTRIBUTE(Data, IN2, "in2");

		MAXON_ATTRIBUTE(Data, OUT, "out");
	}

	namespace SCALEMATRIX
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.scalematrix");

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

		MAXON_ATTRIBUTE(Data, IN, "in");

		MAXON_ATTRIBUTE(Matrix, OUT, "out");
	}

	namespace SIGN
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.sign");

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

	namespace SMOOTHSTEP
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.smoothstep");

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

		MAXON_ATTRIBUTE(Data, IN1, "in1");

		MAXON_ATTRIBUTE(Data, IN2, "in2");

		MAXON_ATTRIBUTE(Data, IN3, "in3");

		MAXON_ATTRIBUTE(Data, OUT, "out");
	}

	namespace SPLINEMAPPER
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.splinemapper");

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

		MAXON_ATTRIBUTE(Data, INPUT, "input");

		/// Spline to use for mapping
		MAXON_ATTRIBUTE(void, SPLINE, "spline");

		MAXON_ATTRIBUTE(Data, OUTPUT, "output");
	}

	namespace STEP
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.step");

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

		MAXON_ATTRIBUTE(Data, IN1, "in1");

		MAXON_ATTRIBUTE(Data, IN2, "in2");

		MAXON_ATTRIBUTE(Data, OUT, "out");
	}

	namespace TRANSFORMMATRIX
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.transformmatrix");

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

		MAXON_ATTRIBUTE(Data, IN, "in");

		MAXON_ATTRIBUTE(Matrix, OUT, "out");
	}

	namespace TRANSFORMVECTOR
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.transformvector");

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

		MAXON_ATTRIBUTE(Id, OPERATION, "operation");

		MAXON_ATTRIBUTE(Matrix, IN1, "in1");

		MAXON_ATTRIBUTE(Vector, IN2, "in2");

		MAXON_ATTRIBUTE(Matrix, OUT, "out");
	}

	namespace TRIGONOMETRY
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.trigonometry");

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

		MAXON_ATTRIBUTE(Id, OPERATION, "operation");

		MAXON_ATTRIBUTE(Id, DATATYPE, "datatype");

		MAXON_ATTRIBUTE(Data, IN, "in");

		MAXON_ATTRIBUTE(Data, OUT, "out");
	}

	namespace VECTORSTOMATRIX
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.vectorstomatrix");

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

		MAXON_ATTRIBUTE(Data, V1, "v1");

		MAXON_ATTRIBUTE(Data, V2, "v2");

		MAXON_ATTRIBUTE(Data, V3, "v3");

		MAXON_ATTRIBUTE(Data, OFF, "off");

		MAXON_ATTRIBUTE(Matrix, MATRIX, "matrix");
	}
}

namespace PATTERN
{
	namespace NODE
	{
		namespace EFFECT
		{
			namespace TRANSFORM2D
			{
				MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.pattern.node.effect.transform2d");

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

				MAXON_ATTRIBUTE(Vector2d, POINT, "point");

				MAXON_ATTRIBUTE(Vector2d, TRANSLATE, "translate");

				MAXON_ATTRIBUTE(Float, ROTATE, "rotate");

				MAXON_ATTRIBUTE(Vector2d, SCALE, "scale");

				MAXON_ATTRIBUTE(Vector2d, PIVOT, "pivot");

				MAXON_ATTRIBUTE(Vector2d, RESULT, "result");
			}
		}
	}
}
}
//----------------------------------------------------------------------------------------
// END - auto generated code, do not edit
//----------------------------------------------------------------------------------------

#include "nodes_math1.hxx"
	
#include "nodes_math2.hxx"

#endif // MATH_NODES_H__
