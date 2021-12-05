#ifndef NODES_CORENODES_BASE_H__
#define NODES_CORENODES_BASE_H__

#include "maxon/fid.h"
#include "maxon/matrix.h"
#include "maxon/nodes.h"

namespace maxon
{
template <typename ValueType>
class Quaternion;
using Quaternion64 = Quaternion<Float64>;
}

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
		namespace CONCATCONTAINER
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.neutron.node.concatcontainer");

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
		}

		namespace INDEX
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.neutron.node.index");

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

			MAXON_ATTRIBUTE(void, IN, "in");

			MAXON_ATTRIBUTE(Int, INDEX, "index");

			MAXON_ATTRIBUTE(Int, COUNT, "count");
		}

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
			// supports MAXON::NODE::BASE::HIDDENINEDITOR
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
	namespace ABS
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.abs");

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

		MAXON_ATTRIBUTE(Id, DATATYPE, "datatype");

		MAXON_ATTRIBUTE(Data, IN, "in");

		MAXON_ATTRIBUTE(Data, OUT, "out");
	}

	namespace AGGREGATE
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.aggregate");

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

	namespace ANGLE
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.angle");

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

		MAXON_ATTRIBUTE(Id, OPERATION, "operation");

		MAXON_ATTRIBUTE(Id, DATATYPE, "datatype");

		MAXON_ATTRIBUTE(Data, IN1, "in1");

		MAXON_ATTRIBUTE(Data, IN2, "in2");

		MAXON_ATTRIBUTE(Data, OUT, "out");
	}

	namespace ANYANDALL
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.anyandall");

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

		MAXON_ATTRIBUTE(Id, OPERATION, "operation");

		MAXON_ATTRIBUTE(Id, DATATYPE, "datatype");

		MAXON_ATTRIBUTE(Data, IN, "in");

		MAXON_ATTRIBUTE(Bool, OUT, "out");
	}

	namespace ARITHMETIC
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.arithmetic");

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

		MAXON_ATTRIBUTE(Id, OPERATION, "operation");

		MAXON_ATTRIBUTE(Id, DATATYPE, "datatype");

		MAXON_ATTRIBUTE(Data, IN1, "in1");

		MAXON_ATTRIBUTE(Data, IN2, "in2");

		MAXON_ATTRIBUTE(Data, OUT, "out");
	}

	namespace ARRAY
	{
		namespace APPEND
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.array.append");

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
			// supports MAXON::NODE::ITERATION::DOMAIN
			// supports MAXON::NODE::ITERATION::OUTERDOMAIN
			// supports MAXON::NODE::ITERATION::INNERDOMAIN
			// supports MAXON::NODE::ARRAY::READBASE::ARRAYIN
			// supports MAXON::NODE::ARRAY::READBASE::ARRAYOUT

			MAXON_ATTRIBUTE(Int, COUNTIN, "countin");

			MAXON_ATTRIBUTE(void, VALUEIN, "valuein");
		}

		namespace ARITHMETIC
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.array.arithmetic");

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

			MAXON_ATTRIBUTE(void, ARRAYIN, "arrayin");

			MAXON_ATTRIBUTE(Id, OPERATIONIN, "operationin");

			MAXON_ATTRIBUTE(Id, DATATYPE, "datatype");

			MAXON_ATTRIBUTE(void, ARRAYOUT, "arrayout");

			MAXON_ATTRIBUTE(void, OUT, "out");

			MAXON_ATTRIBUTE(void, INDEXOUT, "indexout");

			MAXON_ATTRIBUTE(Bool, VALIDOUT, "validout");
		}

		//----------------------------------------------------------------------------------------
		/// Base resource for array nodes.
		//----------------------------------------------------------------------------------------
		namespace BASE
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.array.base");

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
		}

		namespace BLEND
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.array.blend");

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
			// supports MAXON::NODE::ARRAY::READBASE::ARRAYIN
			// supports MAXON::NODE::ARRAY::READBASE::ARRAYOUT

			MAXON_ATTRIBUTE(Id, BLENDMODEIN, "blendmodein",
				RESOURCE_DEFINE(ENUM_LINEAR, Id("linear"))
				RESOURCE_DEFINE(ENUM_SQUARE_EASE_IN, Id("sqeasein"))
				RESOURCE_DEFINE(ENUM_SQUARE_EASE_OUT, Id("sqeaseout"))
				RESOURCE_DEFINE(ENUM_SQUARE_EASE_IN_OUT, Id("sqeaseinout"))
				RESOURCE_DEFINE(ENUM_CUBIC_EASE_IN, Id("cubiceasein"))
				RESOURCE_DEFINE(ENUM_CUBIC_EASE_OUT, Id("cubiceaseout"))
				RESOURCE_DEFINE(ENUM_CUBIC_EASE_IN_OUT, Id("cubiceaseinout"))
				RESOURCE_DEFINE(ENUM_SIN_EASE_IN, Id("sineasein"))
				RESOURCE_DEFINE(ENUM_SIN_EASE_OUT, Id("sineaseout"))
				RESOURCE_DEFINE(ENUM_SIN_EASE_IN_OUT, Id("sineaseinout"))
				RESOURCE_DEFINE(ENUM_ELASTIC_EASE_IN, Id("elasticeasein"))
				RESOURCE_DEFINE(ENUM_ELASTIC_EASE_OUT, Id("elasticeaseout"))
				RESOURCE_DEFINE(ENUM_ELASTIC_EASE_IN_OUT, Id("elasticeaseinout")));

			MAXON_ATTRIBUTE(Float, FACTORIN, "factorin");

			MAXON_ATTRIBUTE(void, TARGETARRAYIN, "targetarrayin");
		}

		namespace BUILDFROMSINGLEVALUE
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.array.buildfromsinglevalue");

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

			MAXON_ATTRIBUTE(void, FILLVALUEIN, "fillvaluein");

			MAXON_ATTRIBUTE(DataType, EXPLICITDATATYPEIN, "explicitdatatypein");

			MAXON_ATTRIBUTE(Int, ARRAYLENGTHIN, "arraylengthin");

			MAXON_ATTRIBUTE(void, ARRAYOUT, "arrayout");

			MAXON_ATTRIBUTE(Int, ARRAYLENGTHOUT, "arraylengthout");
		}

		namespace BUILDFROMVALUE
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.array.buildfromvalue");

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

			MAXON_ATTRIBUTE(DataType, DATATYPEIN, "datatypein");

			MAXON_ATTRIBUTE(Data, IN, "in");

			MAXON_ATTRIBUTE(void, ARRAYOUT, "arrayout");

			MAXON_ATTRIBUTE(Int, ARRAYLENGTHOUT, "arraylengthout");
		}

		namespace CONCAT
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.array.concat");

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

			MAXON_ATTRIBUTE(void, ARRAYBASEIN, "arraybasein");

			MAXON_ATTRIBUTE(Data, IN, "in");

			MAXON_ATTRIBUTE(void, ARRAYOUT, "arrayout");

			MAXON_ATTRIBUTE(Int, ARRAYLENGTHOUT, "arraylengthout");
		}

		namespace ERASE
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.array.erase");

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
			// supports MAXON::NODE::ITERATION::DOMAIN
			// supports MAXON::NODE::ITERATION::OUTERDOMAIN
			// supports MAXON::NODE::ITERATION::INNERDOMAIN
			// supports MAXON::NODE::ARRAY::READBASE::ARRAYIN
			// supports MAXON::NODE::ARRAY::READBASE::ARRAYOUT

			MAXON_ATTRIBUTE(Int, INDEXIN, "indexin");

			MAXON_ATTRIBUTE(Int, COUNTIN, "countin");
		}

		namespace ERASEALL
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.array.eraseall");

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
			// supports MAXON::NODE::ITERATION::DOMAIN
			// supports MAXON::NODE::ITERATION::OUTERDOMAIN
			// supports MAXON::NODE::ITERATION::INNERDOMAIN
			// supports MAXON::NODE::ARRAY::READBASE::ARRAYIN
			// supports MAXON::NODE::ARRAY::READBASE::ARRAYOUT

			MAXON_ATTRIBUTE(void, VALUEIN, "valuein");
		}

		namespace GETCOUNT
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.array.getcount");

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

			MAXON_ATTRIBUTE(void, ARRAYIN, "arrayin");

			MAXON_ATTRIBUTE(Int, COUNTOUT, "countout");

			/// Hack for typetemplate default parameter bug. Input propagated to arrayinuser.
			MAXON_ATTRIBUTE(void, ARRAYININTERNAL, "arrayininternal");

			MAXON_ATTRIBUTE(void, ARRAYOUT, "arrayout");
		}

		namespace GETFROMARRAYCONTAINER
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.array.getfromarraycontainer");

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

			MAXON_ATTRIBUTE(void, CONTAINERIN, "containerin");

			MAXON_ATTRIBUTE(void, CONTAINEROUT, "containerout");

			/// Re-route input hack.
			MAXON_ATTRIBUTE(void, IN2, "in2");
		}

		namespace INSERT
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.array.insert");

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
			// supports MAXON::NODE::ITERATION::DOMAIN
			// supports MAXON::NODE::ITERATION::OUTERDOMAIN
			// supports MAXON::NODE::ITERATION::INNERDOMAIN
			// supports MAXON::NODE::ARRAY::READBASE::ARRAYIN
			// supports MAXON::NODE::ARRAY::READBASE::ARRAYOUT

			MAXON_ATTRIBUTE(Int, INDEXIN, "indexin");

			MAXON_ATTRIBUTE(Int, COUNTIN, "countin");

			MAXON_ATTRIBUTE(void, VALUEIN, "valuein");
		}

		namespace ISINCLUDED
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.array.isincluded");

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
			// supports MAXON::NODE::ARRAY::READBASE::ARRAYIN
			// supports MAXON::NODE::ARRAY::READBASE::ARRAYOUT

			MAXON_ATTRIBUTE(Bool, FOUNDOUT, "foundout");

			MAXON_ATTRIBUTE(Int, FIRSTINDEXOUT, "firstindexout");

			MAXON_ATTRIBUTE(Array<Int>, INDEXOUT, "indexout");
		}

		//----------------------------------------------------------------------------------------
		/// Base resource for reading from array/arraycontainer structures (depending on port types allowed by core node).
		//----------------------------------------------------------------------------------------
		namespace READBASE
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.array.readbase");

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

			MAXON_ATTRIBUTE(void, ARRAYIN, "arrayin");

			MAXON_ATTRIBUTE(void, ARRAYOUT, "arrayout");

			MAXON_ATTRIBUTE(String, A_0, "_0");
		}

		namespace READVALUEATINDEX
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.array.readvalueatindex");

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
			// supports MAXON::NODE::ARRAY::READBASE::ARRAYIN
			// supports MAXON::NODE::ARRAY::READBASE::ARRAYOUT

			MAXON_ATTRIBUTE(Int, INDEXIN, "indexin");

			MAXON_ATTRIBUTE(Bool, CYCLEIN, "cyclein");

			MAXON_ATTRIBUTE(void, VALUEOUT, "valueout");
		}

		namespace REVERSE
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.array.reverse");

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
			// supports MAXON::NODE::ARRAY::READBASE::ARRAYIN
			// supports MAXON::NODE::ARRAY::READBASE::ARRAYOUT
		}

		namespace SCALARARITHMETIC
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.array.scalararithmetic");

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

			MAXON_ATTRIBUTE(void, ARRAYIN, "arrayin");

			MAXON_ATTRIBUTE(Id, OPERATIONIN, "operationin");

			MAXON_ATTRIBUTE(Id, DATATYPE, "datatype");

			MAXON_ATTRIBUTE(void, SCALARIN, "scalarin");

			MAXON_ATTRIBUTE(void, ARRAYOUT, "arrayout");
		}

		namespace SETINARRAYCONTAINER
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.array.setinarraycontainer");

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

			MAXON_ATTRIBUTE(void, CONTAINERIN, "containerin");

			/// Re-route input hack.
			MAXON_ATTRIBUTE(void, IN2, "in2");

			MAXON_ATTRIBUTE(void, CONTAINEROUT, "containerout");
		}

		namespace SORT
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.array.sort");

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
			// supports MAXON::NODE::ARRAY::READBASE::ARRAYIN
			// supports MAXON::NODE::ARRAY::READBASE::ARRAYOUT

			MAXON_ATTRIBUTE(Id, DATATYPE, "datatype");

			MAXON_ATTRIBUTE(Id, MODEIN, "modein",
				RESOURCE_DEFINE(ENUM_ASCENDING, Id("asc"))
				RESOURCE_DEFINE(ENUM_DESCENDING, Id("des")));
		}

		namespace TRUNCATE
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.array.truncate");

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
			// supports MAXON::NODE::ITERATION::DOMAIN
			// supports MAXON::NODE::ITERATION::OUTERDOMAIN
			// supports MAXON::NODE::ITERATION::INNERDOMAIN
			// supports MAXON::NODE::ARRAY::READBASE::ARRAYIN
			// supports MAXON::NODE::ARRAY::READBASE::ARRAYOUT

			MAXON_ATTRIBUTE(Int, COUNTIN, "countin");
		}

		//----------------------------------------------------------------------------------------
		/// Base resource for writing to array/arraycontainer structures (depending on port types allowed by core node).
		/// Scope ports included on top of readbase resource..
		//----------------------------------------------------------------------------------------
		namespace WRITEBASE
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.array.writebase");

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
			// supports MAXON::NODE::ITERATION::DOMAIN
			// supports MAXON::NODE::ITERATION::OUTERDOMAIN
			// supports MAXON::NODE::ITERATION::INNERDOMAIN
			// supports MAXON::NODE::ARRAY::READBASE::ARRAYIN
			// supports MAXON::NODE::ARRAY::READBASE::ARRAYOUT
		}

		namespace WRITEVALUEATINDEX
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.array.writevalueatindex");

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
			// supports MAXON::NODE::ITERATION::DOMAIN
			// supports MAXON::NODE::ITERATION::OUTERDOMAIN
			// supports MAXON::NODE::ITERATION::INNERDOMAIN
			// supports MAXON::NODE::ARRAY::READBASE::ARRAYIN
			// supports MAXON::NODE::ARRAY::READBASE::ARRAYOUT

			MAXON_ATTRIBUTE(Int, INDEXIN, "indexin");

			MAXON_ATTRIBUTE(void, VALUEIN, "valuein");
		}
	}

	namespace ATAN2
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.atan2");

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

		MAXON_ATTRIBUTE(Id, DATATYPE, "datatype");

		MAXON_ATTRIBUTE(Data, IN1, "in1");

		MAXON_ATTRIBUTE(Data, IN2, "in2");

		MAXON_ATTRIBUTE(Data, OUT, "out");
	}

	namespace BLEND
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.blend");

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

		MAXON_ATTRIBUTE(Id, DATATYPE, "datatype");

		MAXON_ATTRIBUTE(Data, IN1, "in1");

		MAXON_ATTRIBUTE(Data, IN2, "in2");

		MAXON_ATTRIBUTE(Float, IN3, "in3");

		MAXON_ATTRIBUTE(Data, OUT, "out");
	}

	namespace BOOLEANOPERATOR
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.booleanoperator");

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

		MAXON_ATTRIBUTE(Id, OPERATION, "operation");

		MAXON_ATTRIBUTE(Bool, IN1, "in1");

		MAXON_ATTRIBUTE(Bool, IN2, "in2");

		MAXON_ATTRIBUTE(Bool, OUT, "out");
	}

	namespace BOXSTEP
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.boxstep");

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

		MAXON_ATTRIBUTE(Id, DATATYPE, "datatype");

		MAXON_ATTRIBUTE(Data, IN1, "in1");

		MAXON_ATTRIBUTE(Data, IN2, "in2");

		MAXON_ATTRIBUTE(Data, IN3, "in3");

		MAXON_ATTRIBUTE(Data, OUT, "out");
	}

	namespace CLAMP
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.clamp");

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

		MAXON_ATTRIBUTE(Id, DATATYPE, "datatype");

		MAXON_ATTRIBUTE(Data, IN1, "in1");

		MAXON_ATTRIBUTE(Data, IN2, "in2");

		MAXON_ATTRIBUTE(Data, IN3, "in3");

		MAXON_ATTRIBUTE(Data, OUT, "out");
	}

	namespace COMPARE
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.compare");

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

		MAXON_ATTRIBUTE(Id, OPERATION, "operation");

		MAXON_ATTRIBUTE(Id, DATATYPE, "datatype");

		MAXON_ATTRIBUTE(Data, IN1, "in1");

		MAXON_ATTRIBUTE(Data, IN2, "in2");

		MAXON_ATTRIBUTE(Data, OUT, "out");
	}

	namespace COMPOSEMATRIX
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.composematrix");

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

		MAXON_ATTRIBUTE(Vector, TRANSLATION, "translation");

		MAXON_ATTRIBUTE(Vector, SCALE, "scale");

		MAXON_ATTRIBUTE(Vector, ROTATION, "rotation");

		MAXON_ATTRIBUTE(Matrix, OUT, "out");

		MAXON_ATTRIBUTE(Id, ROTATIONORDER, "rotationorder",
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
	}

	namespace CONTAINER
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.container");

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
		// supports MAXON::NODE::AGGREGATION::OUTERDOMAIN
		// supports MAXON::NODE::AGGREGATION::INNERDOMAIN
		// supports MAXON::NODE::AGGREGATION::DOMAIN

		MAXON_ATTRIBUTE(DataType, DATATYPE, "datatype");

		MAXON_ATTRIBUTE(void, IN, "in");

		MAXON_ATTRIBUTE(Bool, FILTER, "filter");

		MAXON_ATTRIBUTE(void, OUT, "out");
	}

	namespace CONTAINERITERATION
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.containeriteration");

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
		// supports MAXON::NODE::ITERATION::DOMAIN
		// supports MAXON::NODE::ITERATION::OUTERDOMAIN
		// supports MAXON::NODE::ITERATION::INNERDOMAIN

		MAXON_ATTRIBUTE(Container<>, IN, "in");

		MAXON_ATTRIBUTE(Bool, INDEPENDENT, "independent");
	}

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
			// supports MAXON::NODE::BASE::HIDDENINEDITOR
			// supports MAXON::NODE::BASE::CATEGORY
			// supports MAXON::NODE::BASE::ICON
			// supports MAXON::NODE::BASE::UPDATEPOLICY
			// supports MAXON::ASSET::BASE::PROTECTED

			MAXON_ATTRIBUTE(MAXON_MACROARG_TYPE(Tuple<InternedId, DataType>), FORCEDCONTEXTIN, "forcedcontextin");

			MAXON_ATTRIBUTE(Id, NODECONTEXTIN, "nodecontextin",
				RESOURCE_DEFINE(ENUM_NONE, Id("none"))
				RESOURCE_DEFINE(ENUM_NODECONTEXT, Id("nodecontext#")));

			MAXON_ATTRIBUTE(void, CONTEXTVALUEOUT, "contextvalueout");
		}
	}

	namespace CROSS
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.cross");

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

		MAXON_ATTRIBUTE(Data, IN1, "in1");

		MAXON_ATTRIBUTE(Data, IN2, "in2");

		MAXON_ATTRIBUTE(Data, OUT, "out");
	}

	namespace DECOMPOSEMATRIX
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.decomposematrix");

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

		MAXON_ATTRIBUTE(Id, ROTATIONORDER, "rotationorder",
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

		MAXON_ATTRIBUTE(Matrix, MATRIX, "matrix");

		MAXON_ATTRIBUTE(Data, TRANSLATION, "translation");

		MAXON_ATTRIBUTE(Data, SCALE, "scale");

		MAXON_ATTRIBUTE(Data, ROTATION, "rotation");
	}

	namespace DISTANCE
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.distance");

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

		MAXON_ATTRIBUTE(Id, OPERATION, "operation");

		MAXON_ATTRIBUTE(Id, DATATYPE, "datatype");

		MAXON_ATTRIBUTE(Data, IN1, "in1");

		MAXON_ATTRIBUTE(Data, IN2, "in2");

		MAXON_ATTRIBUTE(Data, OUT, "out");
	}

	namespace DOT
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.dot");

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

		MAXON_ATTRIBUTE(Id, DATATYPE, "datatype");

		MAXON_ATTRIBUTE(Data, IN1, "in1");

		MAXON_ATTRIBUTE(Data, IN2, "in2");

		MAXON_ATTRIBUTE(Data, OUT, "out");
	}

	namespace EXP
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.exp");

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

		MAXON_ATTRIBUTE(Id, DATATYPE, "datatype");

		MAXON_ATTRIBUTE(Data, IN, "in");

		MAXON_ATTRIBUTE(Data, OUT, "out");
	}

	namespace EXP2
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.exp2");

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

		MAXON_ATTRIBUTE(Id, DATATYPE, "datatype");

		MAXON_ATTRIBUTE(Data, IN, "in");

		MAXON_ATTRIBUTE(Data, OUT, "out");
	}

	namespace FRACTION
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.fraction");

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

		MAXON_ATTRIBUTE(Id, DATATYPE, "datatype");

		MAXON_ATTRIBUTE(Data, IN, "in");

		MAXON_ATTRIBUTE(Data, OUT, "out");
	}

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
		// supports MAXON::NODE::BASE::HIDDENINEDITOR
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

	namespace INVERSEMATRIX
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.inversematrix");

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

		MAXON_ATTRIBUTE(Matrix, IN, "in");

		MAXON_ATTRIBUTE(Matrix, OUT, "out");
	}

	namespace INVERT
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.invert");

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

		MAXON_ATTRIBUTE(Id, DATATYPE, "datatype");

		MAXON_ATTRIBUTE(Data, IN, "in");

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
		// supports MAXON::NODE::BASE::HIDDENINEDITOR
		// supports MAXON::NODE::BASE::CATEGORY
		// supports MAXON::NODE::BASE::ICON
		// supports MAXON::NODE::BASE::UPDATEPOLICY
		// supports MAXON::ASSET::BASE::PROTECTED

		MAXON_ATTRIBUTE(void, DOMAIN, "domain");

		MAXON_ATTRIBUTE(void, OUTERDOMAIN, "outerdomain");

		MAXON_ATTRIBUTE(void, INNERDOMAIN, "innerdomain");
	}

	namespace LENGTH
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.length");

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

		MAXON_ATTRIBUTE(Id, OPERATION, "operation");

		MAXON_ATTRIBUTE(Id, DATATYPE, "datatype");

		MAXON_ATTRIBUTE(Data, IN, "in");

		MAXON_ATTRIBUTE(Data, OUT, "out");
	}

	namespace LOG
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.log");

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

		MAXON_ATTRIBUTE(Id, DATATYPE, "datatype");

		MAXON_ATTRIBUTE(Data, IN, "in");

		MAXON_ATTRIBUTE(Data, OUT, "out");
	}

	namespace LOG2
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.log2");

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

		MAXON_ATTRIBUTE(Id, DATATYPE, "datatype");

		MAXON_ATTRIBUTE(Data, IN, "in");

		MAXON_ATTRIBUTE(Data, OUT, "out");
	}

	namespace MAPRANGE
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.maprange");

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

		MAXON_ATTRIBUTE(Matrix, MATRIX, "matrix");

		MAXON_ATTRIBUTE(Data, V1, "v1");

		MAXON_ATTRIBUTE(Data, V2, "v2");

		MAXON_ATTRIBUTE(Data, V3, "v3");

		MAXON_ATTRIBUTE(Data, OFF, "off");
	}

	namespace MODULO
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.modulo");

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

		MAXON_ATTRIBUTE(Id, DATATYPE, "datatype");

		MAXON_ATTRIBUTE(Data, IN1, "in1");

		MAXON_ATTRIBUTE(Data, IN2, "in2");

		MAXON_ATTRIBUTE(Data, OUT, "out");
	}

	namespace NEGATE
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.negate");

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

		MAXON_ATTRIBUTE(Id, DATATYPE, "datatype");

		MAXON_ATTRIBUTE(Data, IN, "in");

		MAXON_ATTRIBUTE(Data, OUT, "out");
	}

	namespace NORMALIZE
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.normalize");

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

		MAXON_ATTRIBUTE(Id, DATATYPE, "datatype");

		MAXON_ATTRIBUTE(Data, IN, "in");

		MAXON_ATTRIBUTE(Data, OUT, "out");
	}

	namespace POW
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.pow");

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

		MAXON_ATTRIBUTE(Id, DATATYPE, "datatype");

		MAXON_ATTRIBUTE(Data, IN1, "in1");

		MAXON_ATTRIBUTE(Data, IN2, "in2");

		MAXON_ATTRIBUTE(Data, OUT, "out");
	}

	namespace QUANTIZE
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.quantize");

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

		MAXON_ATTRIBUTE(Id, DATATYPE, "datatype");

		MAXON_ATTRIBUTE(Data, IN1, "in1");

		MAXON_ATTRIBUTE(Data, IN2, "in2");

		MAXON_ATTRIBUTE(Data, OUT, "out");
	}

	namespace RECIPROCAL
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.reciprocal");

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

		MAXON_ATTRIBUTE(Id, DATATYPE, "datatype");

		MAXON_ATTRIBUTE(Data, IN, "in");

		MAXON_ATTRIBUTE(Data, OUT, "out");
	}

	namespace REFLECT
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.reflect");

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

		MAXON_ATTRIBUTE(Data, IN1, "in1");

		MAXON_ATTRIBUTE(Data, IN2, "in2");

		MAXON_ATTRIBUTE(Data, OUT, "out");
	}

	namespace ROOT
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.root");

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

		MAXON_ATTRIBUTE(Id, OPERATION, "operation");

		MAXON_ATTRIBUTE(Id, DATATYPE, "datatype");

		MAXON_ATTRIBUTE(Data, IN, "in");

		MAXON_ATTRIBUTE(Data, OUT, "out");
	}

	namespace ROUND
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.round");

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

		MAXON_ATTRIBUTE(Id, OPERATION, "operation");

		MAXON_ATTRIBUTE(Id, DATATYPE, "datatype");

		MAXON_ATTRIBUTE(Data, IN, "in");

		MAXON_ATTRIBUTE(Data, OUT, "out");
	}

	namespace SCALE
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.scale");

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

		MAXON_ATTRIBUTE(Id, DATATYPE, "datatype");

		MAXON_ATTRIBUTE(Data, IN1, "in1");

		MAXON_ATTRIBUTE(Data, IN2, "in2");

		MAXON_ATTRIBUTE(Data, OUT, "out");
	}

	namespace SCALEMATRIX
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.scalematrix");

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

		MAXON_ATTRIBUTE(Data, IN, "in");

		MAXON_ATTRIBUTE(Matrix, OUT, "out");
	}

	namespace SIGN
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.sign");

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

		MAXON_ATTRIBUTE(Id, DATATYPE, "datatype");

		MAXON_ATTRIBUTE(Data, IN, "in");

		MAXON_ATTRIBUTE(Data, OUT, "out");
	}

	namespace SMOOTHSTEP
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.smoothstep");

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

		MAXON_ATTRIBUTE(Id, DATATYPE, "datatype");

		MAXON_ATTRIBUTE(Data, IN1, "in1");

		MAXON_ATTRIBUTE(Data, IN2, "in2");

		MAXON_ATTRIBUTE(Data, IN3, "in3");

		MAXON_ATTRIBUTE(Data, OUT, "out");
	}

	namespace STEP
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.step");

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

		MAXON_ATTRIBUTE(Id, DATATYPE, "datatype");

		MAXON_ATTRIBUTE(Data, IN1, "in1");

		MAXON_ATTRIBUTE(Data, IN2, "in2");

		MAXON_ATTRIBUTE(Data, OUT, "out");
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
		// supports MAXON::NODE::BASE::HIDDENINEDITOR
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

	namespace TRANSFORMMATRIX
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.transformmatrix");

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

		MAXON_ATTRIBUTE(Data, IN, "in");

		MAXON_ATTRIBUTE(Matrix, OUT, "out");
	}

	namespace TRANSFORMVECTOR
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.transformvector");

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

		MAXON_ATTRIBUTE(Id, OPERATION, "operation");

		MAXON_ATTRIBUTE(Matrix, IN1, "in1");

		MAXON_ATTRIBUTE(Vector, IN2, "in2");

		MAXON_ATTRIBUTE(Matrix, OUT, "out");
	}

	namespace TRIGONOMETRY
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.trigonometry");

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

		MAXON_ATTRIBUTE(Id, OPERATION, "operation");

		MAXON_ATTRIBUTE(Id, DATATYPE, "datatype");

		MAXON_ATTRIBUTE(Data, IN, "in");

		MAXON_ATTRIBUTE(Data, OUT, "out");
	}

	namespace VECTORSTOMATRIX
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.vectorstomatrix");

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

		MAXON_ATTRIBUTE(Data, V1, "v1");

		MAXON_ATTRIBUTE(Data, V2, "v2");

		MAXON_ATTRIBUTE(Data, V3, "v3");

		MAXON_ATTRIBUTE(Data, OFF, "off");

		MAXON_ATTRIBUTE(Matrix, MATRIX, "matrix");
	}
}
}
//----------------------------------------------------------------------------------------
// END - auto generated code, do not edit
//----------------------------------------------------------------------------------------


namespace maxon::nodes
{

//----------------------------------------------------------------------------------------
/// This is the base class of node systems which are aware of core nodes. You can inherit
/// from this class to implement your own node space which shall use core nodes
/// to do constant evaluation during validation.
//----------------------------------------------------------------------------------------
MAXON_DECLARATION(NodeSystemClass, BaseCoreNodesNodeSystemClass, "net.maxon.corenode.basenodesystemclass");

//----------------------------------------------------------------------------------------
/// This is the base class of true core-node-based node systems. While BaseCoreNodesNodeSystemClass
/// uses core nodes only to do constant evaluation, a node system based on CoreNodesNodeSystemClass
/// can be compiled into a core node system.
//----------------------------------------------------------------------------------------
MAXON_DECLARATION(NodeSystemClass, CoreNodesNodeSystemClass, "net.maxon.corenode.nodesystemclass");

//----------------------------------------------------------------------------------------
/// This factory can be used to create a DescriptionProcessor which builds core-node-based
/// nodes from descriptions. The method NodeTemplateInterface::SupportsImpl of the built
/// node template is implemented by the delegate passed to the factory, so you can easily
/// set up a filter which enables the node only for a specific node system class:
/// @code{nodes_corenodesdescriptionprocessor}
//! MAXON_DECLARATION_REGISTER(maxon::DescriptionProcessors, "net.maxonsdk.nodespace.corenodedescriptionprocessor")
//! {
//! 	return maxon::nodes::CoreNodesDescriptionProcessor().Create(
//! 		[] (const maxon::nodes::NodeSystemClass& cls) -> maxon::Result<maxon::Bool>
//! 		{
//! 			return cls.GetClass() == NodeSystemClassExample::GetClass();
//! 		});
//! }
/// @endcode
//----------------------------------------------------------------------------------------
MAXON_DECLARATION(Factory<DescriptionProcessor(Delegate<Result<Bool>(const NodeSystemClass& cls)>&& support)>, CoreNodesDescriptionProcessor, "net.maxon.corenode.factory.descriptionprocessor");

using ConstantOptimizer = Delegate<Result<Data>(const ConstDataPtr& value)>;

MAXON_REGISTRY(ConstantOptimizer, ConstantOptimizers, "net.maxon.nodes.registry.constantoptimizers");

MAXON_ATTRIBUTE(Bool, FunctionResult, "functionresult");

}

#include "nodes_corenodes_base1.hxx"
#include "nodes_corenodes_base2.hxx"

#endif // NODES_CORENODES_BASE_H__
