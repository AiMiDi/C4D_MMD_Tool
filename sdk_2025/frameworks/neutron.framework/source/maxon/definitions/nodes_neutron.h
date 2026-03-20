#ifndef NODES_NEUTRON_H__
#define NODES_NEUTRON_H__

#include "maxon/neutron_base.h"
#include "maxon/node_or_template.h"

#ifdef DOMAIN
	#undef DOMAIN // normally defined by math.h to indicate a domain error which can be reported by matherr()
#endif

//----------------------------------------------------------------------------------------
// BEGIN - auto generated code, do not edit
//----------------------------------------------------------------------------------------
namespace maxon
{
namespace ATTRIBUTE
{
	namespace CHILDREN
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.attribute.children");

	}

	namespace COLOR
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.attribute.color");

	}

	namespace ENABLED
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.attribute.enabled");

	}

	namespace FLAGS
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.attribute.flags");

	}

	namespace GEOMETRY
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.attribute.geometry");

	}

	namespace GLOBALMATRIX
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.attribute.globalmatrix");

	}

	namespace INDEX
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.attribute.index");

	}

	namespace LIFETIME
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.attribute.lifetime");

	}

	namespace MATERIAL
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.attribute.material");

	}

	namespace MATRIX
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.attribute.matrix");

	}

	namespace NODEPATH
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.attribute.nodepath");

	}

	namespace OBJECTNAME
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.attribute.objectname");

	}

	namespace OBJECTS
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.attribute.objects");

	}

	namespace OBJECTTYPE
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.attribute.objecttype");

	}

	namespace OBJECTTYPENAME
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.attribute.objecttypename");

	}

	namespace RATIO
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.attribute.ratio");

	}

	namespace SOURCEINDEX
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.attribute.sourceindex");

	}

	namespace SQRMATRIX
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.attribute.sqrmatrix");

	}

	namespace TRANSLATION
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.attribute.translation");

	}

	namespace VELOCITY
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.attribute.velocity");

	}
}

namespace NEUTRON
{
	namespace DATATYPE
	{
		namespace ENUM
		{
			namespace ALIGNAXIS
			{
				MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.neutron.datatype.enum.alignaxis");

				MAXON_ATTRIBUTE(Id, ALIGNAXIS, "alignaxis",
					RESOURCE_DEFINE(ENUM_NONE, LiteralId("none"))
					RESOURCE_DEFINE(ENUM_XPOS, LiteralId("xpos"))
					RESOURCE_DEFINE(ENUM_XNEG, LiteralId("xneg"))
					RESOURCE_DEFINE(ENUM_YPOS, LiteralId("ypos"))
					RESOURCE_DEFINE(ENUM_YNEG, LiteralId("yneg"))
					RESOURCE_DEFINE(ENUM_ZPOS, LiteralId("zpos"))
					RESOURCE_DEFINE(ENUM_ZNEG, LiteralId("zneg")));
			}
		}
	}

	namespace INDEXARRAYFROMSTRING
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.neutron.indexarrayfromstring");

		// supports MAXON::NODE::BASE::FILTERTAGS
		// supports MAXON::NODE::BASE::NODEPREVIEWIMAGE
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

		MAXON_ATTRIBUTE(InternedId, MODE, "mode");
		MAXON_ATTRIBUTE(void, MODE_ENUM_INDEX, "index");
		MAXON_ATTRIBUTE(void, MODE_ENUM_PAIR, "pair");

		MAXON_ATTRIBUTE(String, STRINGIN, "stringin");

		MAXON_ATTRIBUTE(void, ARRAY, "array");
	}

	namespace NODE
	{
		namespace ALIGN
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.neutron.node.align");

			// supports MAXON::NODE::BASE::FILTERTAGS
			// supports MAXON::NODE::BASE::NODEPREVIEWIMAGE
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

			MAXON_ATTRIBUTE(InternedId, AXIS, "axis");
			MAXON_ATTRIBUTE(void, AXIS_ENUM_X, "x");
			MAXON_ATTRIBUTE(void, AXIS_ENUM_Y, "y");
			MAXON_ATTRIBUTE(void, AXIS_ENUM_Z, "z");

			MAXON_ATTRIBUTE(Vector, DIRECTION, "direction");

			MAXON_ATTRIBUTE(Vector, SECONDARY, "secondary");
		}

		namespace FIELDEVALUATOR
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.neutron.node.fieldevaluator");

			// supports MAXON::NODE::BASE::FILTERTAGS
			// supports MAXON::NODE::BASE::NODEPREVIEWIMAGE
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

			MAXON_ATTRIBUTE(void, FIELD, "field");

			MAXON_ATTRIBUTE(void, DOMAIN, "domain");

			MAXON_ATTRIBUTE(void, MATRIX, "matrix");

			MAXON_ATTRIBUTE(Vector, POSITION, "position");

			MAXON_ATTRIBUTE(Float, RESULT, "result");
		}

		namespace OBJECTCONTAINER
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.neutron.node.objectcontainer");

			// supports MAXON::NODE::BASE::FILTERTAGS
			// supports MAXON::NODE::BASE::NODEPREVIEWIMAGE
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
			// supports MAXON::NODE::CONTAINER::DATATYPE
			// supports MAXON::NODE::CONTAINER::IN
			// supports MAXON::NODE::CONTAINER::FILTER
			// supports MAXON::NODE::CONTAINER::OUT

			MAXON_ATTRIBUTE(void, NODEPATH, "nodepath");

			MAXON_ATTRIBUTE(void, RESULT, "result");
		}
	}

	namespace OP
	{
		namespace ADDPACKAGE
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.neutron.op.addpackage");

			// supports MAXON::NODE::BASE::FILTERTAGS
			// supports MAXON::NODE::BASE::NODEPREVIEWIMAGE
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
			// supports MAXON::NODE::BYPASSABLE::BYPASS
			// supports MAXON::NEUTRON::OP::BASE::SHOWTAG
			// supports MAXON::NEUTRON::OP::BASE::INPUT
			// supports MAXON::NEUTRON::OP::BASE::OUTPUT

			MAXON_ATTRIBUTE(void, PACKAGE, "package");
		}

		namespace ADDPACKAGES
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.neutron.op.addpackages");

			// supports MAXON::NODE::BASE::FILTERTAGS
			// supports MAXON::NODE::BASE::NODEPREVIEWIMAGE
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
			// supports MAXON::NODE::BYPASSABLE::BYPASS
			// supports MAXON::NEUTRON::OP::BASE::SHOWTAG
			// supports MAXON::NEUTRON::OP::BASE::INPUT
			// supports MAXON::NEUTRON::OP::BASE::OUTPUT

			MAXON_ATTRIBUTE(void, PACKAGES, "packages");
		}

		namespace BASE
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.neutron.op.base");

			// supports MAXON::NODE::BASE::FILTERTAGS
			// supports MAXON::NODE::BASE::NODEPREVIEWIMAGE
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
			// supports MAXON::NODE::BYPASSABLE::BYPASS

			/// Show the modifier in the object's tag list..
			MAXON_ATTRIBUTE(Bool, SHOWTAG, "net.maxon.neutron.showtag");

			/// This is the default template port for user inports.
			MAXON_ATTRIBUTE(void, INPUT, "net.maxon.neutron.op.input");

			/// This is the default template port for user outports.
			MAXON_ATTRIBUTE(void, OUTPUT, "net.maxon.neutron.op.output");
		}

		namespace CHILDREN
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.neutron.op.children");

			// supports MAXON::NODE::BASE::FILTERTAGS
			// supports MAXON::NODE::BASE::NODEPREVIEWIMAGE
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
			// supports MAXON::NODE::BYPASSABLE::BYPASS
			// supports MAXON::NEUTRON::OP::BASE::SHOWTAG
			// supports MAXON::NEUTRON::OP::BASE::INPUT
			// supports MAXON::NEUTRON::OP::BASE::OUTPUT

			MAXON_ATTRIBUTE(void, ARRAY, "array");

			MAXON_ATTRIBUTE(void, PACKAGES, "packages");

			MAXON_ATTRIBUTE(void, CHILDREN, "children");
		}

		namespace COLOR
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.neutron.op.color");

			// supports MAXON::NODE::BASE::FILTERTAGS
			// supports MAXON::NODE::BASE::NODEPREVIEWIMAGE
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
			// supports MAXON::NODE::BYPASSABLE::BYPASS
			// supports MAXON::NEUTRON::OP::BASE::SHOWTAG
			// supports MAXON::NEUTRON::OP::BASE::INPUT
			// supports MAXON::NEUTRON::OP::BASE::OUTPUT

			MAXON_ATTRIBUTE(Color, COLOR, "color");
		}

		namespace FILTER
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.neutron.op.filter");

			// supports MAXON::NODE::BASE::FILTERTAGS
			// supports MAXON::NODE::BASE::NODEPREVIEWIMAGE
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
			// supports MAXON::NODE::BYPASSABLE::BYPASS
			// supports MAXON::NEUTRON::OP::BASE::SHOWTAG
			// supports MAXON::NEUTRON::OP::BASE::INPUT
			// supports MAXON::NEUTRON::OP::BASE::OUTPUT

			MAXON_ATTRIBUTE(Bool, FILTER, "filter");
		}

		namespace INSTANCE
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.neutron.op.instance");

			// supports MAXON::NODE::BASE::FILTERTAGS
			// supports MAXON::NODE::BASE::NODEPREVIEWIMAGE
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
			// supports MAXON::NODE::BYPASSABLE::BYPASS
			// supports MAXON::NEUTRON::OP::BASE::SHOWTAG
			// supports MAXON::NEUTRON::OP::BASE::INPUT
			// supports MAXON::NEUTRON::OP::BASE::OUTPUT

			MAXON_ATTRIBUTE(void, MATRIX, "matrix");

			MAXON_ATTRIBUTE(void, LINK, "link");

			MAXON_ATTRIBUTE(neutron::INSTANCE_MATRIX_MODE, MATRIXMODE, "matrixmode");
		}

		namespace LOOKAT
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.neutron.op.lookat");

			// supports MAXON::NODE::BASE::FILTERTAGS
			// supports MAXON::NODE::BASE::NODEPREVIEWIMAGE
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
			// supports MAXON::NODE::BYPASSABLE::BYPASS
			// supports MAXON::NEUTRON::OP::BASE::SHOWTAG
			// supports MAXON::NEUTRON::OP::BASE::INPUT
			// supports MAXON::NEUTRON::OP::BASE::OUTPUT

			MAXON_ATTRIBUTE(void, TARGET, "target");
		}

		namespace MATRIX
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.neutron.op.matrix");

			// supports MAXON::NODE::BASE::FILTERTAGS
			// supports MAXON::NODE::BASE::NODEPREVIEWIMAGE
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
			// supports MAXON::NODE::BYPASSABLE::BYPASS
			// supports MAXON::NEUTRON::OP::BASE::SHOWTAG
			// supports MAXON::NEUTRON::OP::BASE::INPUT
			// supports MAXON::NEUTRON::OP::BASE::OUTPUT

			MAXON_ATTRIBUTE(void, MATRIX, "matrix");

			MAXON_ATTRIBUTE(Bool, LOCAL, "local");
		}

		namespace NULL_
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.neutron.op.null");

			// supports MAXON::NODE::BASE::FILTERTAGS
			// supports MAXON::NODE::BASE::NODEPREVIEWIMAGE
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
			// supports MAXON::NODE::BYPASSABLE::BYPASS
			// supports MAXON::NEUTRON::OP::BASE::SHOWTAG
			// supports MAXON::NEUTRON::OP::BASE::INPUT
			// supports MAXON::NEUTRON::OP::BASE::OUTPUT
			// supports MAXON::NEUTRON::OP::OBJECTBASE::CHILDREN
			// supports MAXON::NEUTRON::OP::OBJECTBASE::MATRIX
		}

		namespace OBJECTBASE
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.neutron.op.objectbase");

			// supports MAXON::NODE::BASE::FILTERTAGS
			// supports MAXON::NODE::BASE::NODEPREVIEWIMAGE
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
			// supports MAXON::NODE::BYPASSABLE::BYPASS
			// supports MAXON::NEUTRON::OP::BASE::SHOWTAG
			// supports MAXON::NEUTRON::OP::BASE::INPUT
			// supports MAXON::NEUTRON::OP::BASE::OUTPUT

			MAXON_ATTRIBUTE(void, CHILDREN, "net.maxon.neutron.op.objectbase.children");

			MAXON_ATTRIBUTE(void, MATRIX, "net.maxon.neutron.op.objectbase.matrix");
		}

		namespace OBJECTGROUP
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.neutron.op.objectgroup");

			// supports MAXON::NODE::BASE::FILTERTAGS
			// supports MAXON::NODE::BASE::NODEPREVIEWIMAGE
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
			// supports MAXON::NODE::BYPASSABLE::BYPASS
			// supports MAXON::NEUTRON::OP::BASE::SHOWTAG
			// supports MAXON::NEUTRON::OP::BASE::INPUT
			// supports MAXON::NEUTRON::OP::BASE::OUTPUT
			// supports MAXON::NEUTRON::OP::OBJECTBASE::CHILDREN
			// supports MAXON::NEUTRON::OP::OBJECTBASE::MATRIX

			MAXON_ATTRIBUTE(void, OBJECTINPUT, "objectinput");
		}

		namespace ROOT
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.neutron.op.root");

			// supports MAXON::NODE::BASE::FILTERTAGS
			// supports MAXON::NODE::BASE::NODEPREVIEWIMAGE
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
			// supports MAXON::NODE::BYPASSABLE::BYPASS
			// supports MAXON::NEUTRON::OP::BASE::SHOWTAG
			// supports MAXON::NEUTRON::OP::BASE::INPUT
			// supports MAXON::NEUTRON::OP::BASE::OUTPUT
			// supports MAXON::NEUTRON::OP::OBJECTBASE::CHILDREN
			// supports MAXON::NEUTRON::OP::OBJECTBASE::MATRIX
		}

		namespace STACK
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.neutron.op.stack");

			// supports MAXON::NODE::BASE::FILTERTAGS
			// supports MAXON::NODE::BASE::NODEPREVIEWIMAGE
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
			// supports MAXON::NODE::BYPASSABLE::BYPASS
			// supports MAXON::NEUTRON::OP::BASE::SHOWTAG
			// supports MAXON::NEUTRON::OP::BASE::INPUT
			// supports MAXON::NEUTRON::OP::BASE::OUTPUT

			MAXON_ATTRIBUTE(void, STACK, "stack");
		}
	}

	namespace PORTBUNDLE
	{
		namespace EXTRA
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.neutron.portbundle.extra");

			MAXON_ATTRIBUTE(void, RESULT, "net.maxon.neutron.result");
		}

		namespace OBJECT
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.neutron.portbundle.object");

			MAXON_ATTRIBUTE(Matrix, MATRIX, "matrix");

			MAXON_ATTRIBUTE(void, GEOMETRY, "geometry");

			MAXON_ATTRIBUTE(Color, COLOR, "color");


			MAXON_ATTRIBUTE(void, SQRMATRIX, "sqrmatrix");

			MAXON_ATTRIBUTE(void, TRANSLATION, "translation");

			MAXON_ATTRIBUTE(void, PARENTMATRIX, "parentmatrix");

			MAXON_ATTRIBUTE(DataDictionary, MATERIAL, "material");

			MAXON_ATTRIBUTE(void, CHILDREN, "children");

			MAXON_ATTRIBUTE(Bool, FILTER, "filter");

			MAXON_ATTRIBUTE(void, DOMAIN, "domain");

			MAXON_ATTRIBUTE(Float, EFFECTOR_EFFECTSTRENGTH, "net.maxon.neutron.effector.effectstrength");

			MAXON_ATTRIBUTE(Float, EFFECTOR_FIELDSTRENGTH, "net.maxon.neutron.effector.fieldstrength");
		}
	}

	namespace UNITTESTSCENE
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.neutron.unittestscene");

		// supports MAXON::NODE::BASE::FILTERTAGS
		// supports MAXON::NODE::BASE::NODEPREVIEWIMAGE
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

		/// The unit test identifier.
		MAXON_ATTRIBUTE(Id, IDENTIFIER, "identifier");

		/// The expected unit test result.
		MAXON_ATTRIBUTE(String, REFERENCE, "reference");

		/// The expected unit test result.
		MAXON_ATTRIBUTE(String, SUGGESTEDREFERENCE, "suggestedreference");

		/// The unit test asset's SubType.
		/// Only 'net.maxon.asset.neutron.unittest.testscene' get executed in build process.
		MAXON_ATTRIBUTE(Id, TESTASSETSUBTYPE, "testassetsubtype",
			RESOURCE_DEFINE(ENUM_NET_MAXON_ASSET_NEUTRON_UNITTEST_UTILITYASSET, LiteralId("net.maxon.asset.neutron.unittest.utilityasset"))
			RESOURCE_DEFINE(ENUM_NET_MAXON_ASSET_NEUTRON_UNITTEST_TESTSCENE, LiteralId("net.maxon.asset.neutron.unittest.testscene")));

		/// Set to enable the unit test's execution in the build process.
		/// Save the asset for the change to be permanent.
		MAXON_ATTRIBUTE(Bool, ENABLETEST, "enabletest");

		MAXON_ATTRIBUTE(Bool, ENABLEHEATMAP, "enableheatmap");

		/// This is the port which receives the unit test result.
		MAXON_ATTRIBUTE(void, RESULT, "result");

		MAXON_ATTRIBUTE(Group, BUTTONGROUP, "buttongroup");

		MAXON_ATTRIBUTE(void, LOAD, "load");

		MAXON_ATTRIBUTE(void, WRITE, "write");

		MAXON_ATTRIBUTE(void, OVERWRITE, "overwrite");

		MAXON_ATTRIBUTE(void, RUN, "run");

		MAXON_ATTRIBUTE(void, RUNCURRENT, "runcurrent");

		MAXON_ATTRIBUTE(void, FORCEREFRESH, "forcerefresh");
	}
}

namespace NODE
{
	namespace INSTANTIATION
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.instantiation");

		// supports MAXON::NODE::BASE::FILTERTAGS
		// supports MAXON::NODE::BASE::NODEPREVIEWIMAGE
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

		MAXON_ATTRIBUTE(nodes::NodeOrTemplate, NODE, "net.maxon.node.instantiation.node");

		/// Enable Instantiation
		MAXON_ATTRIBUTE(Bool, ENABLE, "net.maxon.node.instantiation.enable");
	}

	namespace LCVBASE
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.lcvbase");

		// supports MAXON::NODE::BASE::FILTERTAGS
		// supports MAXON::NODE::BASE::NODEPREVIEWIMAGE
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

		MAXON_ATTRIBUTE(DataType, TYPES, "types");

		MAXON_ATTRIBUTE(Group, INITIAL, "net.maxon.node.lcvbase.initial");

		MAXON_ATTRIBUTE(Group, PREVIOUS, "net.maxon.node.lcvbase.previous");

		MAXON_ATTRIBUTE(Group, NEXT, "net.maxon.node.lcvbase.next");

		MAXON_ATTRIBUTE(Group, FINAL, "net.maxon.node.lcvbase.final");
	}

	namespace LOOPCARRIEDVALUE
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.loopcarriedvalue");

		// supports MAXON::NODE::BASE::FILTERTAGS
		// supports MAXON::NODE::BASE::NODEPREVIEWIMAGE
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
		// supports MAXON::NODE::LCVBASE::TYPES

		MAXON_ATTRIBUTE(void, OUTERDOMAIN, "outerdomain");

		MAXON_ATTRIBUTE(void, INNERDOMAIN, "innerdomain");

		MAXON_ATTRIBUTE(void, DOMAIN, "domain");
	}

	namespace MEMORY
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.memory");

		// supports MAXON::NODE::BASE::FILTERTAGS
		// supports MAXON::NODE::BASE::NODEPREVIEWIMAGE
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
		// supports MAXON::NODE::LCVBASE::TYPES

		MAXON_ATTRIBUTE(void, DOMAIN, "domain");

		MAXON_ATTRIBUTE(void, LIFETIME, "lifetime");
	}

	namespace SUM
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.sum");

		// supports MAXON::NODE::BASE::FILTERTAGS
		// supports MAXON::NODE::BASE::NODEPREVIEWIMAGE
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

		MAXON_ATTRIBUTE(Id, DATATYPE, "datatype");

		MAXON_ATTRIBUTE(Data, VALUES, "values");

		MAXON_ATTRIBUTE(void, OUT, "out");
	}
}
}
//----------------------------------------------------------------------------------------
// END - auto generated code, do not edit
//----------------------------------------------------------------------------------------


#include "nodes_neutron1.hxx"
#include "nodes_neutron2.hxx"

#endif // NODES_NEUTRON_H__
