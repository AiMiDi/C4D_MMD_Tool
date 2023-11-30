#ifndef NODES_STRUCTURE_H__
#define NODES_STRUCTURE_H__

#include "maxon/array.h"

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

		namespace INDEX
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.neutron.node.index");

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

			MAXON_ATTRIBUTE(void, IN, "in");

			MAXON_ATTRIBUTE(Int, INDEX, "index");

			MAXON_ATTRIBUTE(Int, COUNT, "count");
		}
	}
}

namespace NODE
{
	namespace ARRAY
	{
		namespace APPEND
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.array.append");

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
			// supports MAXON::NODE::ARRAY::READBASE::DATATYPE
			// supports MAXON::NODE::ARRAY::READBASE::ARRAYIN
			// supports MAXON::NODE::ARRAY::READBASE::ARRAYOUT

			MAXON_ATTRIBUTE(Int, COUNTIN, "countin");

			MAXON_ATTRIBUTE(void, VALUEIN, "valuein");
		}

		namespace ARITHMETIC
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.array.arithmetic");

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

		namespace BLEND
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.array.blend");

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
			// supports MAXON::NODE::ARRAY::READBASE::DATATYPE
			// supports MAXON::NODE::ARRAY::READBASE::ARRAYIN
			// supports MAXON::NODE::ARRAY::READBASE::ARRAYOUT

			MAXON_ATTRIBUTE(void, TARGETARRAYIN, "targetarrayin");

			MAXON_ATTRIBUTE(Id, BLENDMODEIN, "blendmodein",
				RESOURCE_DEFINE(ENUM_LINEAR, LiteralId("linear"))
				RESOURCE_DEFINE(ENUM_SQUARE_EASE_IN, LiteralId("sqeasein"))
				RESOURCE_DEFINE(ENUM_SQUARE_EASE_OUT, LiteralId("sqeaseout"))
				RESOURCE_DEFINE(ENUM_SQUARE_EASE_IN_OUT, LiteralId("sqeaseinout"))
				RESOURCE_DEFINE(ENUM_CUBIC_EASE_IN, LiteralId("cubiceasein"))
				RESOURCE_DEFINE(ENUM_CUBIC_EASE_OUT, LiteralId("cubiceaseout"))
				RESOURCE_DEFINE(ENUM_CUBIC_EASE_IN_OUT, LiteralId("cubiceaseinout"))
				RESOURCE_DEFINE(ENUM_SIN_EASE_IN, LiteralId("sineasein"))
				RESOURCE_DEFINE(ENUM_SIN_EASE_OUT, LiteralId("sineaseout"))
				RESOURCE_DEFINE(ENUM_SIN_EASE_IN_OUT, LiteralId("sineaseinout"))
				RESOURCE_DEFINE(ENUM_ELASTIC_EASE_IN, LiteralId("elasticeasein"))
				RESOURCE_DEFINE(ENUM_ELASTIC_EASE_OUT, LiteralId("elasticeaseout"))
				RESOURCE_DEFINE(ENUM_ELASTIC_EASE_IN_OUT, LiteralId("elasticeaseinout")));

			MAXON_ATTRIBUTE(Float, FACTORIN, "factorin");
		}

		namespace BUILDFROMSINGLEVALUE
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.array.buildfromsinglevalue");

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

			MAXON_ATTRIBUTE(void, FILLVALUEIN, "fillvaluein");

			MAXON_ATTRIBUTE(DataType, EXPLICITDATATYPEIN, "explicitdatatypein");

			MAXON_ATTRIBUTE(Int, ARRAYLENGTHIN, "arraylengthin");

			MAXON_ATTRIBUTE(void, ARRAYOUT, "arrayout");

			MAXON_ATTRIBUTE(Int, ARRAYLENGTHOUT, "arraylengthout");
		}

		namespace BUILDFROMVALUE
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.array.buildfromvalue");

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

			MAXON_ATTRIBUTE(DataType, DATATYPEIN, "datatypein");

			MAXON_ATTRIBUTE(Data, IN, "in");

			MAXON_ATTRIBUTE(void, ARRAYOUT, "arrayout");

			MAXON_ATTRIBUTE(Int, ARRAYLENGTHOUT, "arraylengthout");
		}

		namespace CONCAT
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.array.concat");

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

			MAXON_ATTRIBUTE(DataType, DATATYPE, "datatype");

			MAXON_ATTRIBUTE(void, ARRAYBASEIN, "arraybasein");

			MAXON_ATTRIBUTE(Data, IN, "in");

			MAXON_ATTRIBUTE(void, ARRAYOUT, "arrayout");

			MAXON_ATTRIBUTE(Int, ARRAYLENGTHOUT, "arraylengthout");
		}

		namespace ERASE
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.array.erase");

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
			// supports MAXON::NODE::ARRAY::READBASE::DATATYPE
			// supports MAXON::NODE::ARRAY::READBASE::ARRAYIN
			// supports MAXON::NODE::ARRAY::READBASE::ARRAYOUT

			MAXON_ATTRIBUTE(Int, INDEXIN, "indexin");

			MAXON_ATTRIBUTE(Int, COUNTIN, "countin");

			MAXON_ATTRIBUTE(Bool, MAINTAINORDERIN, "maintainorderin");
		}

		namespace ERASEALL
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.array.eraseall");

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
			// supports MAXON::NODE::ARRAY::READBASE::DATATYPE
			// supports MAXON::NODE::ARRAY::READBASE::ARRAYIN
			// supports MAXON::NODE::ARRAY::READBASE::ARRAYOUT

			MAXON_ATTRIBUTE(void, VALUEIN, "valuein");
		}

		namespace GETCOUNT
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.array.getcount");

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
			// supports MAXON::NODE::ARRAY::READBASE::DATATYPE
			// supports MAXON::NODE::ARRAY::READBASE::ARRAYIN
			// supports MAXON::NODE::ARRAY::READBASE::ARRAYOUT

			MAXON_ATTRIBUTE(Int, COUNTOUT, "countout");
		}

		namespace GETFROMARRAYCONTAINER
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.array.getfromarraycontainer");

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

			MAXON_ATTRIBUTE(void, CONTAINERIN, "containerin");

			MAXON_ATTRIBUTE(void, CONTAINEROUT, "containerout");

			/// Re-route input hack.
			MAXON_ATTRIBUTE(void, IN2, "in2");
		}

		namespace GETSINGLEARRAYFROMCONTAINER
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.array.getsinglearrayfromcontainer");

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

			MAXON_ATTRIBUTE(void, CONTAINERIN, "containerin");

			MAXON_ATTRIBUTE(Id, MODEIN, "modein",
				RESOURCE_DEFINE(ENUM_INDEXSELECTION, LiteralId("indexselection"))
				RESOURCE_DEFINE(ENUM_IDSELECTION, LiteralId("idselection")));

			MAXON_ATTRIBUTE(InternedId, MEMBERIDIN, "memberidin");

			MAXON_ATTRIBUTE(Int, MEMBERINDEXIN, "memberindexin");

			MAXON_ATTRIBUTE(Bool, CASESENSITIVEIN, "casesensitivein");

			MAXON_ATTRIBUTE(DataType, DATATYPE, "datatype");

			MAXON_ATTRIBUTE(DataType, DATATYPEIN, "datatypein");

			MAXON_ATTRIBUTE(void, CONTAINEROUT, "containerout");

			MAXON_ATTRIBUTE(void, ARRAYOUT, "arrayout");
		}

		namespace INSERT
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.array.insert");

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
			// supports MAXON::NODE::ARRAY::READBASE::DATATYPE
			// supports MAXON::NODE::ARRAY::READBASE::ARRAYIN
			// supports MAXON::NODE::ARRAY::READBASE::ARRAYOUT

			MAXON_ATTRIBUTE(Int, INDEXIN, "indexin");

			MAXON_ATTRIBUTE(Int, COUNTIN, "countin");

			MAXON_ATTRIBUTE(void, VALUEIN, "valuein");
		}

		namespace ISINCLUDED
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.array.isincluded");

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
			// supports MAXON::NODE::ARRAY::READBASE::DATATYPE
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

			MAXON_ATTRIBUTE(DataType, DATATYPE, "datatype");

			MAXON_ATTRIBUTE(void, ARRAYIN, "arrayin");

			MAXON_ATTRIBUTE(void, ARRAYOUT, "arrayout");

			MAXON_ATTRIBUTE(String, A_0, "_0");
		}

		namespace READVALUEATINDEX
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.array.readvalueatindex");

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
			// supports MAXON::NODE::ARRAY::READBASE::DATATYPE
			// supports MAXON::NODE::ARRAY::READBASE::ARRAYIN
			// supports MAXON::NODE::ARRAY::READBASE::ARRAYOUT

			MAXON_ATTRIBUTE(Int, INDEXIN, "indexin");

			MAXON_ATTRIBUTE(Bool, CYCLEIN, "cyclein");

			MAXON_ATTRIBUTE(void, VALUEOUT, "valueout");
		}

		namespace REVERSE
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.array.reverse");

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
			// supports MAXON::NODE::ARRAY::READBASE::DATATYPE
			// supports MAXON::NODE::ARRAY::READBASE::ARRAYIN
			// supports MAXON::NODE::ARRAY::READBASE::ARRAYOUT
		}

		namespace SCALARARITHMETIC
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.array.scalararithmetic");

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

			MAXON_ATTRIBUTE(void, ARRAYIN, "arrayin");

			MAXON_ATTRIBUTE(Id, OPERATIONIN, "operationin");

			MAXON_ATTRIBUTE(Id, DATATYPE, "datatype");

			MAXON_ATTRIBUTE(void, SCALARIN, "scalarin");

			MAXON_ATTRIBUTE(void, ARRAYOUT, "arrayout");
		}

		namespace SETINARRAYCONTAINER
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.array.setinarraycontainer");

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

			MAXON_ATTRIBUTE(void, CONTAINERIN, "containerin");

			/// Re-route input hack.
			MAXON_ATTRIBUTE(void, IN2, "in2");

			MAXON_ATTRIBUTE(void, CONTAINEROUT, "containerout");
		}

		namespace SORT
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.array.sort");

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
			// supports MAXON::NODE::ARRAY::READBASE::DATATYPE
			// supports MAXON::NODE::ARRAY::READBASE::ARRAYIN
			// supports MAXON::NODE::ARRAY::READBASE::ARRAYOUT

			MAXON_ATTRIBUTE(Id, MODEIN, "modein",
				RESOURCE_DEFINE(ENUM_ASCENDING, LiteralId("asc"))
				RESOURCE_DEFINE(ENUM_DESCENDING, LiteralId("des")));
		}

		namespace SORTCONTAINER
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.array.sortcontainer");

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

			MAXON_ATTRIBUTE(void, CONTAINERIN, "containerin");

			MAXON_ATTRIBUTE(Id, SELECTIONMODEIN, "selectionmodein",
				RESOURCE_DEFINE(ENUM_INDEXSELECTION, LiteralId("indexselection"))
				RESOURCE_DEFINE(ENUM_IDSELECTION, LiteralId("idselection")));

			MAXON_ATTRIBUTE(InternedId, MEMBERIDIN, "memberidin");

			MAXON_ATTRIBUTE(Int, MEMBERINDEXIN, "memberindexin");

			MAXON_ATTRIBUTE(Bool, CASESENSITIVEIN, "casesensitivein");

			MAXON_ATTRIBUTE(Id, MODEIN, "modein",
				RESOURCE_DEFINE(ENUM_ASCENDING, LiteralId("asc"))
				RESOURCE_DEFINE(ENUM_DESCENDING, LiteralId("des")));

			MAXON_ATTRIBUTE(Bool, APPLYTOALLIN, "applytoallin");

			MAXON_ATTRIBUTE(DataType, DATATYPE, "datatype");

			MAXON_ATTRIBUTE(void, CONTAINEROUT, "containerout");

			MAXON_ATTRIBUTE(void, ARRAYOUT, "arrayout");

			MAXON_ATTRIBUTE(void, UNSORTEDARRAYOUT, "unsortedarrayout");
		}

		namespace SWAPERASE
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.array.swaperase");

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
			// supports MAXON::NODE::ARRAY::READBASE::DATATYPE
			// supports MAXON::NODE::ARRAY::READBASE::ARRAYIN
			// supports MAXON::NODE::ARRAY::READBASE::ARRAYOUT

			MAXON_ATTRIBUTE(Int, INDEXIN, "indexin");

			MAXON_ATTRIBUTE(Int, COUNTIN, "countin");
		}

		namespace TRUNCATE
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.array.truncate");

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
			// supports MAXON::NODE::ARRAY::READBASE::DATATYPE
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
			// supports MAXON::NODE::ARRAY::READBASE::DATATYPE
			// supports MAXON::NODE::ARRAY::READBASE::ARRAYIN
			// supports MAXON::NODE::ARRAY::READBASE::ARRAYOUT
		}

		namespace WRITEVALUEATINDEX
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.array.writevalueatindex");

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
			// supports MAXON::NODE::ARRAY::READBASE::DATATYPE
			// supports MAXON::NODE::ARRAY::READBASE::ARRAYIN
			// supports MAXON::NODE::ARRAY::READBASE::ARRAYOUT

			MAXON_ATTRIBUTE(Int, INDEXIN, "indexin");

			MAXON_ATTRIBUTE(void, VALUEIN, "valuein");
		}
	}

	namespace COMPOSECONTAINER
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.composecontainer");

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
		// supports MAXON::NODE::CONTAINERBASE::DATATYPE
		// supports MAXON::NODE::CONTAINERBASE::IN
		// supports MAXON::NODE::CONTAINERBASE::OUT
	}

	namespace CONTAINER
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.container");

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

		MAXON_ATTRIBUTE(DataType, DATATYPE, "datatype");

		MAXON_ATTRIBUTE(void, IN, "in");

		MAXON_ATTRIBUTE(Bool, FILTER, "filter");

		MAXON_ATTRIBUTE(void, OUT, "out");
	}

	namespace CONTAINERBASE
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.containerbase");

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

		MAXON_ATTRIBUTE(DataType, DATATYPE, "datatype");

		MAXON_ATTRIBUTE(void, IN, "in");

		MAXON_ATTRIBUTE(void, OUT, "out");
	}

	namespace CONTAINERITERATION
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.containeriteration");

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
		// supports MAXON::NODE::ITERATION::DOMAIN
		// supports MAXON::NODE::ITERATION::OUTERDOMAIN
		// supports MAXON::NODE::ITERATION::INNERDOMAIN

		MAXON_ATTRIBUTE(DataType, DATATYPE, "datatype");

		MAXON_ATTRIBUTE(Container<>, IN, "in");

		MAXON_ATTRIBUTE(Bool, INDEPENDENT, "independent");

		MAXON_ATTRIBUTE(Int, COUNT, "count");

		MAXON_ATTRIBUTE(Int, INDEX, "index");

		MAXON_ATTRIBUTE(void, OUT, "out");
	}

	namespace DECOMPOSECONTAINER
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.decomposecontainer");

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
		// supports MAXON::NODE::CONTAINERBASE::DATATYPE
		// supports MAXON::NODE::CONTAINERBASE::IN
		// supports MAXON::NODE::CONTAINERBASE::OUT
	}

	namespace GETMEMBERINFO
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.getmemberinfo");

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

		MAXON_ATTRIBUTE(DataType, DATATYPEIN, "datatypein");

		MAXON_ATTRIBUTE(void, MEMBERSOUT, "membersout");

		MAXON_ATTRIBUTE(void, MEMBERTYPESOUT, "membertypesout");

		MAXON_ATTRIBUTE(Int, MEMBERCOUNTOUT, "membercountout");
	}
}
}
//----------------------------------------------------------------------------------------
// END - auto generated code, do not edit
//----------------------------------------------------------------------------------------


#include "nodes_structure1.hxx"
#include "nodes_structure2.hxx"

#endif // NODES_STRUCTURE_H__
