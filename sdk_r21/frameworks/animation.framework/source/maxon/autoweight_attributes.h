#ifndef AUTOWEIGHT_ATTRIBUTES_H__
#define AUTOWEIGHT_ATTRIBUTES_H__

#include "maxon/fid.h"
#include "maxon/vector4d.h"
#include "maxon/url.h"

//----------------------------------------------------------------------------------------
// BEGIN - auto generated code, do not edit
//----------------------------------------------------------------------------------------
namespace maxon
{
namespace ANIMATION
{
	namespace AUTOWEIGHT
	{
		namespace BASE
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.animation.autoweight.base");

			MAXON_ATTRIBUTE(maxon::Bool, SELECTEDPOINTS, "net.maxon.animation.autoweight.base.selectedpoints");

			MAXON_ATTRIBUTE(maxon::Bool, ALLOWZEROLENGTH, "net.maxon.animation.autoweight.base.allowzerolength");

			MAXON_ATTRIBUTE(maxon::Int, JOINTCOUNT, "net.maxon.animation.autoweight.base.jointcount");

			MAXON_ATTRIBUTE(maxon::Float, SMOOTHSTRENGTH, "net.maxon.animation.autoweight.base.smoothstrength");

			MAXON_ATTRIBUTE(maxon::Int, SMOOTHITERATION, "net.maxon.animation.autoweight.base.smoothiteration");

			MAXON_ATTRIBUTE(maxon::Float, STRENGTH, "net.maxon.animation.autoweight.base.strength");

			MAXON_ATTRIBUTE(maxon::Float, FALLOFFDISTANCE, "net.maxon.animation.autoweight.base.falloffdistance");

			MAXON_ATTRIBUTE(Group, GROUP, "net.maxon.animation.autoweight.base.group");

			MAXON_ATTRIBUTE(Group, SMOOTHGROUP, "net.maxon.animation.autoweight.base.smoothgroup");
		}

		namespace BONEGLOW
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.animation.autoweight.boneglow");

			// supports MAXON::ANIMATION::AUTOWEIGHT::BASE::SELECTEDPOINTS
			// supports MAXON::ANIMATION::AUTOWEIGHT::BASE::ALLOWZEROLENGTH
			// supports MAXON::ANIMATION::AUTOWEIGHT::BASE::JOINTCOUNT
			// supports MAXON::ANIMATION::AUTOWEIGHT::BASE::SMOOTHSTRENGTH
			// supports MAXON::ANIMATION::AUTOWEIGHT::BASE::SMOOTHITERATION
			// supports MAXON::ANIMATION::AUTOWEIGHT::BASE::STRENGTH
			// supports MAXON::ANIMATION::AUTOWEIGHT::BASE::FALLOFFDISTANCE

			MAXON_ATTRIBUTE(maxon::Bool, USEVISIBILITY, "net.maxon.animation.autoweight.boneglow.usevisibility");

			MAXON_ATTRIBUTE(maxon::Bool, IGNOREINNERPOLY, "net.maxon.animation.autoweight.boneglow.ignoreinnerpoly");

			MAXON_ATTRIBUTE(maxon::Float, VISIBILITYRATIO, "net.maxon.animation.autoweight.boneglow.visibilityratio");

			MAXON_ATTRIBUTE(Group, GROUP, "net.maxon.animation.autoweight.boneglow.group");
		}

		namespace HEATMAP
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.animation.autoweight.heatmap");

			// supports MAXON::ANIMATION::AUTOWEIGHT::BASE::SELECTEDPOINTS
			// supports MAXON::ANIMATION::AUTOWEIGHT::BASE::ALLOWZEROLENGTH
			// supports MAXON::ANIMATION::AUTOWEIGHT::BASE::JOINTCOUNT
			// supports MAXON::ANIMATION::AUTOWEIGHT::BASE::SMOOTHSTRENGTH
			// supports MAXON::ANIMATION::AUTOWEIGHT::BASE::SMOOTHITERATION
			// supports MAXON::ANIMATION::AUTOWEIGHT::BASE::STRENGTH
			// supports MAXON::ANIMATION::AUTOWEIGHT::BASE::FALLOFFDISTANCE
		}

		namespace VOXELBONEGLOW
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.animation.autoweight.voxelboneglow");

			// supports MAXON::ANIMATION::AUTOWEIGHT::BASE::SELECTEDPOINTS
			// supports MAXON::ANIMATION::AUTOWEIGHT::BASE::ALLOWZEROLENGTH
			// supports MAXON::ANIMATION::AUTOWEIGHT::BASE::JOINTCOUNT
			// supports MAXON::ANIMATION::AUTOWEIGHT::BASE::SMOOTHSTRENGTH
			// supports MAXON::ANIMATION::AUTOWEIGHT::BASE::SMOOTHITERATION
			// supports MAXON::ANIMATION::AUTOWEIGHT::BASE::STRENGTH
			// supports MAXON::ANIMATION::AUTOWEIGHT::BASE::FALLOFFDISTANCE

			MAXON_ATTRIBUTE(maxon::Bool, USEVISIBILITY, "net.maxon.animation.autoweight.voxelboneglow.usevisibility");

			MAXON_ATTRIBUTE(maxon::Bool, IGNOREINNERPOLY, "net.maxon.animation.autoweight.voxelboneglow.ignoreinnerpoly");

			MAXON_ATTRIBUTE(maxon::Float, VISIBILITYRATIO, "net.maxon.animation.autoweight.voxelboneglow.visibilityratio");

			MAXON_ATTRIBUTE(maxon::Bool, USEAUTOVOXELSIZE, "net.maxon.animation.autoweight.voxelboneglow.useautovoxelsize");

			MAXON_ATTRIBUTE(maxon::Float, SIZE, "net.maxon.animation.autoweight.voxelboneglow.size");

			MAXON_ATTRIBUTE(Group, GROUP, "net.maxon.animation.autoweight.voxelboneglow.group");
		}
	}
}
}
//----------------------------------------------------------------------------------------
// END - auto generated code, do not edit
//----------------------------------------------------------------------------------------

#include "autoweight_attributes1.hxx"
#include "autoweight_attributes2.hxx"

#endif // AUTOWEIGHT_ATTRIBUTES_H__
