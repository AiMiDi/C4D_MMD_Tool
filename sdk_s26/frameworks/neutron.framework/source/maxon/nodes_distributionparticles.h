#ifndef NODES_DISTRIBUTIONPARTICLES_H__
#define NODES_DISTRIBUTIONPARTICLES_H__

#include "maxon/fid.h"

//----------------------------------------------------------------------------------------
// BEGIN - auto generated code, do not edit
//----------------------------------------------------------------------------------------
namespace maxon
{
namespace NEUTRON
{
	namespace NODE
	{
		namespace DISTRIBUTION
		{
			namespace PARTICLE
			{
				namespace BASE
				{
					MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.neutron.node.distribution.particle.base");

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

					MAXON_ATTRIBUTE(Bool, ALIGNIN, "alignin");

					MAXON_ATTRIBUTE(Id, ALIGNAXISIN, "alignaxisin",
						RESOURCE_DEFINE(ENUM_ENUM_NET_MAXON_NEUTRON_DATATYPE_ENUM_ALIGNAXIS, Id("enum#net.maxon.neutron.datatype.enum.alignaxis"))
						RESOURCE_DEFINE(ENUM_PARTICLE, Id("particle")));

					MAXON_ATTRIBUTE(void, DISTDATAOUT, "distdataout");

					MAXON_ATTRIBUTE(Group, MATRIXGROUP, "matrixgroup");

					MAXON_ATTRIBUTE(Group, PARTICLEGROUP, "particlegroup");
				}
			}
		}
	}
}
}
//----------------------------------------------------------------------------------------
// END - auto generated code, do not edit
//----------------------------------------------------------------------------------------


#include "nodes_distributionparticles1.hxx"
#include "nodes_distributionparticles2.hxx"

#endif // NODES_DISTRIBUTIONPARTICLES_H__
