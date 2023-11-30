#ifndef DATADESCRIPTION_MATERIAL_ZBRUSH_H__
#define DATADESCRIPTION_MATERIAL_ZBRUSH_H__

#include "maxon/fid.h"

//----------------------------------------------------------------------------------------
// BEGIN - auto generated code, do not edit
//----------------------------------------------------------------------------------------
namespace maxon
{
namespace MATERIAL
{
	namespace PORTBUNDLE
	{
		namespace ZBRUSH
		{
			namespace GOZ
			{
				//----------------------------------------------------------------------------------------
				/// ZBrush Standard GoZ material. This Material contains the information that a standard goz export can carry before the acquisition by Maxon.
				//----------------------------------------------------------------------------------------
				namespace STANDARD
				{
					MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.material.portbundle.zbrush.goz.standard");

					/// Link to a texture or the polypaint if any have been imported
					MAXON_ATTRIBUTE(Color64, DIFFUSE, "diffuse");

					/// normal map texture
					MAXON_ATTRIBUTE(ColorA64, NORMAL, "normal");

					/// Displacement hieght parameter.
					MAXON_ATTRIBUTE(Float, DISPLACEMENT_HEIGHT, "displacement.height");

					/// Number of subdivision for the displacement
					MAXON_ATTRIBUTE(Int, DIPLACEMENT_SUBDIVISIONLEVEL, "diplacement.subdivisionlevel");

					/// Displacement map
					MAXON_ATTRIBUTE(ColorA64, DISPLACEMENT, "displacement");

					MAXON_ATTRIBUTE(Group, BASIC, "basic");

					MAXON_ATTRIBUTE(String, OBJECT_BASE_NAME, "net.maxon.object.base.name");
				}
			}
		}
	}
}
}
//----------------------------------------------------------------------------------------
// END - auto generated code, do not edit
//----------------------------------------------------------------------------------------


#include "datadescription_material_zbrush1.hxx"
#include "datadescription_material_zbrush2.hxx"

#endif // DATADESCRIPTION_MATERIAL_ZBRUSH_H__
