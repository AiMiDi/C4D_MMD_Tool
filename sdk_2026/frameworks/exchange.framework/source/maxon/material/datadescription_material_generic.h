#ifndef DATADESCRIPTION_MATERIAL_GENERIC_H__
#define DATADESCRIPTION_MATERIAL_GENERIC_H__

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
		/// Generic material description with basic properties.
		//----------------------------------------------------------------------------------------
		namespace GENERIC
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.material.portbundle.generic");

			/// Diffuse color property.
			MAXON_ATTRIBUTE(Color, DIFFUSECOLOR, "diffuseColor");

			/// Diffuse factor property. This factor is used to attenuate the diffuse color.
			MAXON_ATTRIBUTE(Float, DIFFUSEFACTOR, "diffuseFactor");

			/// Ambient color property.
			MAXON_ATTRIBUTE(Color, AMBIENTCOLOR, "ambientColor");

			/// Ambient factor property. This factor is used to attenuate the ambient color.
			MAXON_ATTRIBUTE(Float, AMBIENTFACTOR, "ambientFactor");

			/// Emissive color property.
			MAXON_ATTRIBUTE(Color, EMISSIVECOLOR, "emissiveColor");

			/// Emissive factor property. This factor is used to attenuate the emissive color.
			MAXON_ATTRIBUTE(Float, EMISSIVEFACTOR, "emissiveFactor");

			/// Transparent color property.
			MAXON_ATTRIBUTE(Color, TRANSPARENCYCOLOR, "transparencyColor");

			/// Transparency factor property.  This property is used to make a surface more or less opaque (0 = opaque, 1 = transparent).
			MAXON_ATTRIBUTE(Float, TRANSPARENCYFACTOR, "transparencyFactor");

			/// Specular color property.
			MAXON_ATTRIBUTE(Color, SPECULARCOLOR, "specularColor");

			/// Specular factor property. This factor is used to attenuate the specular color.
			MAXON_ATTRIBUTE(Float, SPECULARFACTOR, "specularFactor");

			/// Opacity color (Alpha) property.
			MAXON_ATTRIBUTE(Color, OPACITYCOLOR, "opacityColor");

			/// Shininess property. This property controls the aspect of the shiny spot.
			MAXON_ATTRIBUTE(Float, SHININESS, "shininess");

			/// Reflection factor property. This property is used to attenuate the reflection color.
			MAXON_ATTRIBUTE(Float, REFLECTIONFACTOR, "reflectionFactor");
		}
	}
}
}
//----------------------------------------------------------------------------------------
// END - auto generated code, do not edit
//----------------------------------------------------------------------------------------


#include "datadescription_material_generic1.hxx"
#include "datadescription_material_generic2.hxx"

#endif // DATADESCRIPTION_MATERIAL_GENERIC_H__
