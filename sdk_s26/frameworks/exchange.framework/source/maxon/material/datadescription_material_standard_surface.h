#ifndef DATADESCRIPTION_MATERIAL_STANDARD_SURFACE_H__
#define DATADESCRIPTION_MATERIAL_STANDARD_SURFACE_H__

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
		/// This bundle is modeled after the open standard Autodesk Standard Surface version 1.0.1, see
		/// https://autodesk.github.io/standard-surface/ .
		//----------------------------------------------------------------------------------------
		namespace STANDARDSURFACE
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.material.portbundle.standardsurface");

			/// reflection weight of diffuse_brdf
			MAXON_ATTRIBUTE(Float, BASE, "base");

			/// reflection color of diffuse_brdf
			MAXON_ATTRIBUTE(Color, BASE_COLOR, "base_color");

			/// reflection roughness of diffuse_brdf
			MAXON_ATTRIBUTE(Float, DIFFUSE_ROUGHNESS, "diffuse_roughness");

			MAXON_ATTRIBUTE(Float, METALNESS, "metalness");

			/// specular reflection weight
			MAXON_ATTRIBUTE(Float, SPECULAR, "specular");

			/// specular reflection color
			MAXON_ATTRIBUTE(Color, SPECULAR_COLOR, "specular_color");

			/// reflection roughness; squared internally before passed to the BSDF to achieve a more uniform roughness look over the parameter range
			MAXON_ATTRIBUTE(Float, SPECULAR_ROUGHNESS, "specular_roughness");

			/// refractive index of specular_brdf
			MAXON_ATTRIBUTE(Float, SPECULAR_IOR, "specular_IOR");

			/// reflection anisotropy of specular_brdf; range [0,1]
			MAXON_ATTRIBUTE(Float, SPECULAR_ANISOTROPY, "specular_anisotropy");

			/// orientation of anisotropy; range [0,1] (1 means 180 degrees)
			MAXON_ATTRIBUTE(Float, SPECULAR_ROTATION, "specular_rotation");

			/// transmission weight
			MAXON_ATTRIBUTE(Float, TRANSMISSION, "transmission");

			/// transmission color, i.e. tint
			MAXON_ATTRIBUTE(Color, TRANSMISSION_COLOR, "transmission_color");

			/// the distance travelled inside the material by white light before its color becomes exactly transmission_color by Beer's law, determining the extinction coefficient of the interior medium; if zero, transmission_color acts as a constant (on-surface) transmission tint; range [0,infinity)
			MAXON_ATTRIBUTE(Float, TRANSMISSION_DEPTH, "transmission_depth");

			/// scattering coefficient of the interior medium
			MAXON_ATTRIBUTE(Color, TRANSMISSION_SCATTER, "transmission_scatter");

			/// the anisotropy of the Henyey-Greenstein phase function of the interior medium; range [-1,1]
			MAXON_ATTRIBUTE(Float, TRANSMISSION_SCATTER_ANISOTROPY, "transmission_scatter_anisotropy");

			/// dispersion Abbe number, describing how much the index of refraction varies across wavelengths
			MAXON_ATTRIBUTE(Float, TRANSMISSION_DISPERSION, "transmission_dispersion");

			/// additional (positive or negative) roughness on top of specular_roughness
			MAXON_ATTRIBUTE(Float, TRANSMISSION_EXTRA_ROUGHNESS, "transmission_extra_roughness");

			/// subsurface scattering weight
			MAXON_ATTRIBUTE(Float, SUBSURFACE, "subsurface");

			/// subsurface color, used by subsurface(...) closure
			MAXON_ATTRIBUTE(Color, SUBSURFACE_COLOR, "subsurface_color");

			/// subsurface radii (i.e. mean free paths) of the red, green, and blue channels
			MAXON_ATTRIBUTE(Color, SUBSURFACE_RADIUS, "subsurface_radius");

			/// scalar scale for subsurface_radius
			MAXON_ATTRIBUTE(Float, SUBSURFACE_SCALE, "subsurface_scale");

			/// anisotropy of the subsurface medium phase function; range [-1,1]
			MAXON_ATTRIBUTE(Float, SUBSURFACE_ANISOTROPY, "subsurface_anisotropy");

			/// reflection weight (reflection color is fixed to white)
			MAXON_ATTRIBUTE(Float, COAT, "coat");

			/// tint color for the light coming from all layers below
			MAXON_ATTRIBUTE(Color, COAT_COLOR, "coat_color");

			/// coat reflection roughness; squared internally before passed to the BSDF to achieve a more linear perceptual response [Burley2012]
			MAXON_ATTRIBUTE(Float, COAT_ROUGHNESS, "coat_roughness");

			/// reflection anisotropy of coat_brdf; range [0,1]
			MAXON_ATTRIBUTE(Float, COAT_ANISOTROPY, "coat_anisotropy");

			/// orientation of anisotropy; range [0,1] (where 1 means 180 degrees)
			MAXON_ATTRIBUTE(Float, COAT_ROTATION, "coat_rotation");

			/// refractive index of coat_brdf
			MAXON_ATTRIBUTE(Float, COAT_IOR, "coat_IOR");

			/// shading normal for the coating reflections; optional, overrides the default shading normal; has no effect on the closure combination weights
			MAXON_ATTRIBUTE(Vector, COAT_NORMAL, "coat_normal");

			/// how much to additionally modulate diffuse reflection and subsurface scattering saturation; range [0,1]
			MAXON_ATTRIBUTE(Float, COAT_AFFECT_COLOR, "coat_affect_color");

			/// how much to affect the roughness of the specular reflection layers below; range [0,1]
			MAXON_ATTRIBUTE(Float, COAT_AFFECT_ROUGHNESS, "coat_affect_roughness");

			/// reflection weight of sheen_brdf
			MAXON_ATTRIBUTE(Float, SHEEN, "sheen");

			/// reflection color of sheen_brdf
			MAXON_ATTRIBUTE(Color, SHEEN_COLOR, "sheen_color");

			/// reflection roughness of sheen_brdf; range [0,1]
			MAXON_ATTRIBUTE(Float, SHEEN_ROUGHNESS, "sheen_roughness");

			/// emission color multiplier
			MAXON_ATTRIBUTE(Float, EMISSION, "emission");

			/// emission color
			MAXON_ATTRIBUTE(Color, EMISSION_COLOR, "emission_color");

			/// thickness of the film (in nanometres)
			MAXON_ATTRIBUTE(Float, THIN_FILM_THICKNESS, "thin_film_thickness");

			/// refractive index of the film
			MAXON_ATTRIBUTE(Float, THIN_FILM_IOR, "thin_film_IOR");

			/// if true, the object is considered infinitely thin and the surface double-sided
			MAXON_ATTRIBUTE(Bool, THIN_WALLED, "thin_walled");

			/// the (colored) opacity of the surface (fully opaque by default)
			MAXON_ATTRIBUTE(Color, OPACITY, "opacity");

			/// (not subject to standard) 
			/// Data is expected to be in [0,1] range with the geometric normal = [0.5, 0.5, 1.0].
			/// The tangent frame is oriented in accordance with OpenGL and Unity.
			MAXON_ATTRIBUTE(Vector, SURFACE_NORMAL, "surface_normal");

			/// (not subject to standard)
			MAXON_ATTRIBUTE(Float, SURFACE_NORMAL_WEIGHT, "surface_normal_weight");

			MAXON_ATTRIBUTE(Group, GROUP_BASE, "group.base");

			MAXON_ATTRIBUTE(Group, GROUP_SPECULAR, "group.specular");

			MAXON_ATTRIBUTE(Group, GROUP_TRANSMISSION, "group.transmission");

			MAXON_ATTRIBUTE(Group, GROUP_SUBSURFACE, "group.subsurface");

			MAXON_ATTRIBUTE(Group, GROUP_COATING, "group.coating");

			MAXON_ATTRIBUTE(Group, GROUP_SHEEN, "group.sheen");

			MAXON_ATTRIBUTE(Group, GROUP_EMISSION, "group.emission");

			MAXON_ATTRIBUTE(Group, GROUP_THIN_FILM, "group.thin_film");

			MAXON_ATTRIBUTE(Group, GROUP_SURFACE, "group.surface");
		}
	}
}
}
//----------------------------------------------------------------------------------------
// END - auto generated code, do not edit
//----------------------------------------------------------------------------------------

namespace maxon
{

#include "datadescription_material_standard_surface1.hxx"
#include "datadescription_material_standard_surface2.hxx"

} // namespace maxon

#endif // DATADESCRIPTION_MATERIAL_STANDARD_SURFACE_H__
