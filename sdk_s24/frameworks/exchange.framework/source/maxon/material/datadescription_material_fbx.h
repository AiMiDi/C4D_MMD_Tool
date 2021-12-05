#ifndef DATADESCRIPTION_MATERIAL_FBX_H__
#define DATADESCRIPTION_MATERIAL_FBX_H__

#include "maxon/fid.h"
#include "maxon/vector.h"
#include "maxon/vector4d.h"
#include "maxon/idandversion.h"

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
		/// http://help.autodesk.com/cloudhelp/2019/ENU/FBX-Developer-Help/cpp_ref/class_fbx_surface_lambert.html
		/// 
		/// Default values were extracted from 2019.5 runtime.
		//----------------------------------------------------------------------------------------
		namespace FBXSURFACELAMBERT
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.material.portbundle.fbxsurfacelambert");

			/// Emissive color property.
			MAXON_ATTRIBUTE(Color, EMISSIVE, "emissive");

			/// Emissive factor property. This factor is used to attenuate the emissive color.
			MAXON_ATTRIBUTE(Float, EMISSIVEFACTOR, "emissiveFactor");

			/// Ambient color property.
			MAXON_ATTRIBUTE(Color, AMBIENT, "ambient");

			/// Ambient factor property. This factor is used to attenuate the ambient color.
			MAXON_ATTRIBUTE(Float, AMBIENTFACTOR, "ambientFactor");

			/// Diffuse color property.
			MAXON_ATTRIBUTE(Color, DIFFUSE, "diffuse");

			/// Diffuse factor property. This factor is used to attenuate the diffuse color.
			MAXON_ATTRIBUTE(Float, DIFFUSEFACTOR, "diffuseFactor");

			/// NormalMap property. This property can be used to specify the distortion of the surface normals and create the illusion of a bumpy surface.
			MAXON_ATTRIBUTE(Vector, NORMALMAP, "normalMap");

			/// Bump property. This property is used to distort the surface normal and create the illusion of a bumpy surface.
			MAXON_ATTRIBUTE(Vector, BUMP, "bump");

			/// Bump factor property. This factor is used to make a surface more or less bumpy.
			MAXON_ATTRIBUTE(Float, BUMPFACTOR, "bumpFactor");

			/// Transparent color property.
			MAXON_ATTRIBUTE(Color, TRANSPARENTCOLOR, "transparentColor");

			/// Transparency factor property.  This property is used to make a surface more or less opaque (0 = opaque, 1 = transparent).
			MAXON_ATTRIBUTE(Float, TRANSPARENCYFACTOR, "transparencyFactor");

			/// Displacement color property.
			MAXON_ATTRIBUTE(Color, DISPLACEMENTCOLOR, "displacementColor");

			/// Displacement factor property.
			MAXON_ATTRIBUTE(Float, DISPLACEMENTFACTOR, "displacementFactor");

			/// Vector displacement color property.
			MAXON_ATTRIBUTE(Color, VECTORDISPLACEMENTCOLOR, "vectorDisplacementColor");

			/// Vector displacement factor property.
			MAXON_ATTRIBUTE(Float, VECTORDISPLACEMENTFACTOR, "vectorDisplacementFactor");
		}

		//----------------------------------------------------------------------------------------
		/// http://help.autodesk.com/cloudhelp/2019/ENU/FBX-Developer-Help/cpp_ref/class_fbx_surface_phong.html
		/// 
		/// Default values were extracted from 2019.5 runtime.
		//----------------------------------------------------------------------------------------
		namespace FBXSURFACEPHONG
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.material.portbundle.fbxsurfacephong");

			// supports MAXON::MATERIAL::PORTBUNDLE::FBXSURFACELAMBERT::EMISSIVE
			// supports MAXON::MATERIAL::PORTBUNDLE::FBXSURFACELAMBERT::EMISSIVEFACTOR
			// supports MAXON::MATERIAL::PORTBUNDLE::FBXSURFACELAMBERT::AMBIENT
			// supports MAXON::MATERIAL::PORTBUNDLE::FBXSURFACELAMBERT::AMBIENTFACTOR
			// supports MAXON::MATERIAL::PORTBUNDLE::FBXSURFACELAMBERT::DIFFUSE
			// supports MAXON::MATERIAL::PORTBUNDLE::FBXSURFACELAMBERT::DIFFUSEFACTOR
			// supports MAXON::MATERIAL::PORTBUNDLE::FBXSURFACELAMBERT::NORMALMAP
			// supports MAXON::MATERIAL::PORTBUNDLE::FBXSURFACELAMBERT::BUMP
			// supports MAXON::MATERIAL::PORTBUNDLE::FBXSURFACELAMBERT::BUMPFACTOR
			// supports MAXON::MATERIAL::PORTBUNDLE::FBXSURFACELAMBERT::TRANSPARENTCOLOR
			// supports MAXON::MATERIAL::PORTBUNDLE::FBXSURFACELAMBERT::TRANSPARENCYFACTOR
			// supports MAXON::MATERIAL::PORTBUNDLE::FBXSURFACELAMBERT::DISPLACEMENTCOLOR
			// supports MAXON::MATERIAL::PORTBUNDLE::FBXSURFACELAMBERT::DISPLACEMENTFACTOR
			// supports MAXON::MATERIAL::PORTBUNDLE::FBXSURFACELAMBERT::VECTORDISPLACEMENTCOLOR
			// supports MAXON::MATERIAL::PORTBUNDLE::FBXSURFACELAMBERT::VECTORDISPLACEMENTFACTOR

			/// Specular property.
			MAXON_ATTRIBUTE(Color, SPECULAR, "specular");

			/// Specular factor property. This factor is used to attenuate the specular color.
			MAXON_ATTRIBUTE(Float, SPECULARFACTOR, "specularFactor");

			/// Shininess property. This property controls the aspect of the shiny spot. It is the specular exponent in the Phong illumination model.
			/// We recommend the following mappings between roughness and shininess:
			/// Float shininess = Pow(2, (1.0 - Clamp01(roughness)) * 10.0);
			/// Float roughness = Clamp01(1.0 - ((Log2(shininess) / 10.0)));
			MAXON_ATTRIBUTE(Float, SHININESS, "shininess");

			/// Reflection color property. This property is used to implement reflection mapping.
			MAXON_ATTRIBUTE(Color, REFLECTION, "reflection");

			/// Reflection factor property. This property is used to attenuate the reflection color.
			MAXON_ATTRIBUTE(Float, REFLECTIONFACTOR, "reflectionFactor");
		}
	}
}
}
//----------------------------------------------------------------------------------------
// END - auto generated code, do not edit
//----------------------------------------------------------------------------------------

namespace maxon
{

#include "datadescription_material_fbx1.hxx"
#include "datadescription_material_fbx2.hxx"

} // namespace maxon

#endif // DATADESCRIPTION_MATERIAL_FBX_H__
