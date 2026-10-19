#ifndef DATADESCRIPTION_MATERIAL_OBJ_H__
#define DATADESCRIPTION_MATERIAL_OBJ_H__

#include "maxon/fid.h"
#include "maxon/vector.h"

//----------------------------------------------------------------------------------------
// BEGIN - auto generated code, do not edit
//----------------------------------------------------------------------------------------
namespace maxon
{
namespace MATERIAL
{
	namespace PORTBUNDLE
	{
		//----------------------------------------------------------------------------------------
		/// OBJ material description with extended PBR properties.
		//----------------------------------------------------------------------------------------
		namespace OBJ
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.material.portbundle.obj");

			/// Diffuse color multiplied with optional texture (Kd * map_Kd)
			MAXON_ATTRIBUTE(Color, DIFFUSE_COLOR, "diffuse_color");

			/// Specular color multiplied with optional texture (Ks * map_Ks)
			MAXON_ATTRIBUTE(Color, SPECULAR_COLOR, "specular_color");

			/// Normal texture only, no value (bump / norm)
			MAXON_ATTRIBUTE(Vector, NORMAL_MAP, "normal_map");

			/// Opacity multiplied with optional texture, 1.0 is fully opaque (d * map_d or (1-Tr) * map_d)
			MAXON_ATTRIBUTE(Float, OPACITY, "opacity");

			/// Transmission filter color, no texture (Tf)
			MAXON_ATTRIBUTE(Color, TRANSMISSION_COLOR, "transmission_color");

			/// Optical density or IOR, no texture (Ni)
			MAXON_ATTRIBUTE(Float, IOR, "ior");

			/// PBR Roughness value or texture (Pr/map_Pr)
			MAXON_ATTRIBUTE(Float, ROUGHNESS, "roughness");

			/// PBR Metallic value or texture (Pm/map_Pm)
			MAXON_ATTRIBUTE(Float, METALLIC, "metallic");

			/// PBR Emmisive color multiplied with optional texture (Ke * map_Ke)
			MAXON_ATTRIBUTE(Color, EMISSIVE_COLOR, "emissive_color");

			/// Anisotropy 0-1, no texture (aniso)
			MAXON_ATTRIBUTE(Float, ANISOTROPY, "anisotropy");

			/// Anisotropy angle 0-1 (1 means 360), no texture (anisor)
			MAXON_ATTRIBUTE(Float, ANISOTROPY_ROTATION, "anisotropy_rotation");
		}
	}
}
}
//----------------------------------------------------------------------------------------
// END - auto generated code, do not edit
//----------------------------------------------------------------------------------------


#include "datadescription_material_obj1.hxx"
#include "datadescription_material_obj2.hxx"

#endif // DATADESCRIPTION_MATERIAL_OBJ_H__
