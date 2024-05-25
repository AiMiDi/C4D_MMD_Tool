#ifndef GENERATOR_NODES_H__
#define GENERATOR_NODES_H__

#include "maxon/fid.h"
#include "maxon/vector.h"
#include "maxon/vector2d.h"
#include "maxon/vector4d.h"

//----------------------------------------------------------------------------------------
// BEGIN - auto generated code, do not edit
//----------------------------------------------------------------------------------------
namespace maxon
{
namespace PATTERN
{
	namespace NODE
	{
		namespace GENERATOR
		{
			namespace BLACKBODY
			{
				MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.pattern.node.generator.blackbody");

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

				MAXON_ATTRIBUTE(Float, TEMPERATURE, "temperature");

				MAXON_ATTRIBUTE(Color, RESULT, "result");
			}

			namespace HASH
			{
				MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.pattern.node.generator.hash");

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

				MAXON_ATTRIBUTE(Int, SEED, "seed");

				MAXON_ATTRIBUTE(Int, SALT, "salt");

				MAXON_ATTRIBUTE(Float, MINIMUM, "minimum");

				MAXON_ATTRIBUTE(Float, MAXIMUM, "maximum");

				MAXON_ATTRIBUTE(ColorA, RESULTCOLORA, "resultcolora");

				MAXON_ATTRIBUTE(Color, RESULTCOLOR, "resultcolor");

				MAXON_ATTRIBUTE(Int, RESULTINT, "resultint");

				MAXON_ATTRIBUTE(Float, RESULTFLOAT, "resultfloat");

				MAXON_ATTRIBUTE(Vector, RESULTVECTOR3, "resultvector3");

				MAXON_ATTRIBUTE(Vector2d, RESULTVECTOR2, "resultvector2");

				MAXON_ATTRIBUTE(Bool, RESULTBOOL, "resultbool");

				MAXON_ATTRIBUTE(Group, GROUPRANGE, "grouprange");
			}
		}
	}
}
}
//----------------------------------------------------------------------------------------
// END - auto generated code, do not edit
//----------------------------------------------------------------------------------------

#include "nodes_generator1.hxx"
	
#include "nodes_generator2.hxx"

#endif // GENERATOR_NODES_H__
