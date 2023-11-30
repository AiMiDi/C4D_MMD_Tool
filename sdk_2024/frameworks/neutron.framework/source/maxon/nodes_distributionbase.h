#ifndef NODES_DISTRIBUTIONBASE_H__
#define NODES_DISTRIBUTIONBASE_H__

#include "maxon/fid.h"
#include "maxon/node_or_template.h"

//----------------------------------------------------------------------------------------
// BEGIN - auto generated code, do not edit
//----------------------------------------------------------------------------------------
namespace maxon
{
namespace NEUTRON
{
	namespace GROUP
	{
		namespace DISTRIBUTION
		{
			//----------------------------------------------------------------------------------------
			/// Use this group to create an iterable distribution function. Distribution Op node will handle inserting the function in a loop.
			//----------------------------------------------------------------------------------------
			namespace FUNCTION
			{
				MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.neutron.group.distribution.function");

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

				MAXON_ATTRIBUTE(Int, INDEXIN, "indexin");

				/// Distribution count (size of ArrayContainer). Needed as sometimes original size parameter can be a Vector or other non integer type.
				MAXON_ATTRIBUTE(Int, COUNTOUT, "countout");

				/// Erase the ports which the distribution does not want to have in final container.
				MAXON_ATTRIBUTE(void, DISTCHANNELSOUT, "distchannelsout");
			}

			//----------------------------------------------------------------------------------------
			/// Base resource for other distribution function datatypes.
			//----------------------------------------------------------------------------------------
			namespace FUNCTIONBASE
			{
				MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.neutron.group.distribution.functionbase");

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

			//----------------------------------------------------------------------------------------
			/// Use this group to create a looping distribution function. 
			/// Function must output a complete Distribution (ArrayContainer), hence looping must be handled inside function.
			//----------------------------------------------------------------------------------------
			namespace LOOPINGFUNCTION
			{
				MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.neutron.group.distribution.loopingfunction");

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

				/// Distributiuon ArrayContainer output
				MAXON_ATTRIBUTE(void, DISTDATAOUT, "distdataout");
			}
		}
	}

	namespace NODE
	{
		namespace DISTRIBUTION
		{
			namespace FUNCTION
			{
				//----------------------------------------------------------------------------------------
				/// Looping function mode for Distribution Op.
				/// Just used as an internal port forwarding node in Looping Function mode.
				//----------------------------------------------------------------------------------------
				namespace LOOPINGMODE
				{
					MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.neutron.node.distribution.function.loopingmode");

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
					// supports MAXON::NEUTRON::GROUP::DISTRIBUTION::LOOPINGFUNCTION::DISTDATAOUT
				}

				//----------------------------------------------------------------------------------------
				/// Function mode for Distribution Op.
				/// Just used as an internal port forwarding node in Function mode.
				//----------------------------------------------------------------------------------------
				namespace NONLOOPINGMODE
				{
					MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.neutron.node.distribution.function.nonloopingmode");

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
					// supports MAXON::NEUTRON::GROUP::DISTRIBUTION::FUNCTION::INDEXIN
					// supports MAXON::NEUTRON::GROUP::DISTRIBUTION::FUNCTION::COUNTOUT
					// supports MAXON::NEUTRON::GROUP::DISTRIBUTION::FUNCTION::DISTCHANNELSOUT

					/// Internal use only.
					MAXON_ATTRIBUTE(void, PRIVATEINDEXCTX, "privateindexctx");
				}
			}
		}
	}

	namespace OP
	{
		namespace DISTRIBUTION
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.neutron.op.distribution");

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
			// supports MAXON::NODE::BYPASSABLE::BYPASS
			// supports MAXON::NEUTRON::OP::BASE::SHOWTAG
			// supports MAXON::NEUTRON::OP::BASE::INPUT
			// supports MAXON::NEUTRON::OP::BASE::OUTPUT

			MAXON_ATTRIBUTE(void, PARAMETERSIN, "parametersin");

			MAXON_ATTRIBUTE(nodes::NodeOrTemplate, DISTRIBUTIONTYPE, "distributiontype");
		}
	}

	namespace PORTBUNDLE
	{
		namespace DISTRIBUTIONBASE
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.neutron.portbundle.distributionbase");

			/// Position, scale, rotation.
			MAXON_ATTRIBUTE(void, MATRIX, "matrix");

			/// Linear index.
			MAXON_ATTRIBUTE(void, INDEX, "index");

			/// Geometry component index, voxel index, grid 3d index, ... Depends on what each distribution uses as input. Not mandatory.
			MAXON_ATTRIBUTE(void, SOURCEINDEX, "sourceindex");

			/// UVW ratio.
			MAXON_ATTRIBUTE(void, RATIO, "ratio");

			/// Color.
			MAXON_ATTRIBUTE(void, COLOR, "color");

			/// Elapsed lifetime.
			MAXON_ATTRIBUTE(void, LIFETIME, "lifetime");

			/// Linear velocity.
			MAXON_ATTRIBUTE(void, VELOCITY, "velocity");
		}
	}
}
}
//----------------------------------------------------------------------------------------
// END - auto generated code, do not edit
//----------------------------------------------------------------------------------------


#include "nodes_distributionbase1.hxx"
#include "nodes_distributionbase2.hxx"

#endif // NODES_DISTRIBUTIONBASE_H__
