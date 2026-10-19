#ifndef NODES_DISTRIBUTION_H__
#define NODES_DISTRIBUTION_H__

#include "maxon/fid.h"

namespace maxon
{
class GeometryObject;
}

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
			/// Base group that defines which assets are distribution capsules.
			//----------------------------------------------------------------------------------------
			namespace BASE
			{
				MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.neutron.group.distribution.base");

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

				/// Distributiuon collection result port.
				MAXON_ATTRIBUTE(void, DISTDATAOUT, "distdataout");

				MAXON_ATTRIBUTE(String, ASSET_SORT, "net.maxon.asset.sort");
			}

			namespace WITHGEOM
			{
				namespace BASE
				{
					MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.neutron.group.distribution.withgeom.base");

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
					// supports MAXON::NEUTRON::GROUP::DISTRIBUTION::BASE::DISTDATAOUT
					// supports MAXON::NEUTRON::GROUP::DISTRIBUTION::BASE::SORT

					MAXON_ATTRIBUTE(GeometryObject, GEOMETRYIN, "geometryin");
				}
			}
		}
	}
}
}
//----------------------------------------------------------------------------------------
// END - auto generated code, do not edit
//----------------------------------------------------------------------------------------


#include "nodes_distribution1.hxx"
#include "nodes_distribution2.hxx"

#endif // NODES_DISTRIBUTION_H__
