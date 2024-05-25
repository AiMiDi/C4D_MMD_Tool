#ifndef DATADESCRIPTION_MATERIAL_REDSHIFT_H__
#define DATADESCRIPTION_MATERIAL_REDSHIFT_H__

#include "maxon/fid.h"
#include "maxon/vector.h"
#include "maxon/vector4d.h"
#include "maxon/idandversion.h"
#include "maxon/gradient.h"
#include "maxon/range.h"

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
		/// Describes a Redshift material for exchange purposes such as export, import and viewport preview.
		/// This can be seen as an extension of the viewport material and enables a more precise representation of Redshift base properties.
		/// Naturally, this description may also be used by third party materials.
		/// Please note that not all Redshift base properties are mapped, nor are all of the listed properties actively used by C4D.
		/// For more details, see https://docs.redshift3d.com/display/RSDOCS/Material?product=cinema4d.
		//----------------------------------------------------------------------------------------
		namespace REDSHIFT
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.material.portbundle.redshift");

			/// This defines the color of the surface when reflecting diffuse direct lighting.
			/// When in PBR 'Metalness' mode, this is also the color of the metal.
			MAXON_ATTRIBUTE(Color, DIFFUSE_COLOR, "diffuse_color");

			/// This scales the overall amount of diffuse lighting (0.0 - 1.0).
			MAXON_ATTRIBUTE(Float, DIFFUSE_WEIGHT, "diffuse_weight");

			/// Values > 0.0 imply an Oren-Nayar BRDF to simulate rough surface micro-facets.
			/// A roughness of 0.0 is equivalent to a perfectly smooth surface, or traditional Lambert shading.
			MAXON_ATTRIBUTE(Float, DIFFUSE_ROUGHNESS, "diffuse_roughness");

			/// This is an overall tint for the entire material.
			MAXON_ATTRIBUTE(Color, OVERALL_TINT, "overall_tint");

			/// This color describes the overall opacity of the material, with colors closer to white being more opaque.
			/// An opacity of black means the material will be fully transparent.
			MAXON_ATTRIBUTE(Color, OPACITY, "opacity");

			/// A bump or normal map specifies the distortion of the surface normal(s).
			/// Please make sure your input textures are congruent with the specified NORMAL_SPACE.
			MAXON_ATTRIBUTE(Vector, OVERALL_NORMAL, "overall_normal");

			/// This scales the overall amount of normal distortion (0.0 - 1.0).
			MAXON_ATTRIBUTE(Float, OVERALL_NORMAL_WEIGHT, "overall_normal_weight");

			/// The input space for the OVERALL_NORMAL texture.
			/// For grayscale maps, NORMAL_SPACE_ENUM_SPACE_HEIGHTFIELD should be used.
			/// The default value is NORMAL_SPACE_ENUM_SPACE_RGB_TANGENT.
			MAXON_ATTRIBUTE(InternedId, NORMAL_SPACE, "normal_space");
			MAXON_ATTRIBUTE(void, NORMAL_SPACE_ENUM_SPACE_NONE, "space_none");
			MAXON_ATTRIBUTE(void, NORMAL_SPACE_ENUM_SPACE_RGB_OBJECT, "space_rgb_object");
			MAXON_ATTRIBUTE(void, NORMAL_SPACE_ENUM_SPACE_RGB_TANGENT, "space_rgb_tangent");
			MAXON_ATTRIBUTE(void, NORMAL_SPACE_ENUM_SPACE_RGB_WORLD, "space_rgb_world");
			MAXON_ATTRIBUTE(void, NORMAL_SPACE_ENUM_SPACE_HEIGHTFIELD, "space_heightfield");

			/// This is the emissive color of the material.
			MAXON_ATTRIBUTE(Color, EMISSION_COLOR, "emission_color");

			/// This is a multiplier of the emissive color of the material (0.0 - 1.0).
			MAXON_ATTRIBUTE(Float, EMISSION_WEIGHT, "emission_weight");

			/// This allows you to select between different methods of controlling the reflection Fresnel effect;
			/// "Color+Edge Tint" is an artist friendly mode that allows you to control the facing reflectivity color and metal edge tint.
			///   The 'Metal Edge Tint' should be black for non-metals.
			/// "Metalness" is a special mode designed for 'PBR' workflow compatibility with 'Substance' and 'Unreal' materials.
			/// "IOR" lets you set a single Index of Refraction value to control reflectivity and is ideal for simple dielectric materials.
			///   Dielectric materials typically have an Index of Refraction between 1.0 and 2.0, where 1.0 means no reflectivity and higher values mean stronger reflectivity.
			MAXON_ATTRIBUTE(InternedId, FRESNEL_TYPE, "fresnel_type");
			MAXON_ATTRIBUTE(void, FRESNEL_TYPE_ENUM_IOR, "ior");
			MAXON_ATTRIBUTE(void, FRESNEL_TYPE_ENUM_METALNESS, "metalness");
			MAXON_ATTRIBUTE(void, FRESNEL_TYPE_ENUM_COLOR_EDGE_TINT, "color_edge_tint");

			/// This is the reflection tint.
			MAXON_ATTRIBUTE(Color, REFLECTION_COLOR, "reflection_color");

			/// This is a multiplier of the reflection tint.
			/// Reflections are disabled when this value is 0.0.
			MAXON_ATTRIBUTE(Float, REFLECTION_WEIGHT, "reflection_weight");

			/// This is the roughness of the surface reflection.
			/// A roughness value of 0.0 means perfectly 'polished', or full glossiness.
			/// A roughness value of 1.0 means almost diffuse appearance.
			MAXON_ATTRIBUTE(Float, REFLECTION_ROUGHNESS, "reflection_roughness");

			/// The index of refraction used to calculate the strength of the Fresnel effect.
			MAXON_ATTRIBUTE(Float, REFLECTION_IOR, "reflection_ior");

			/// This value ranges between 0.0 and 1.0, where 0.0 means it is a dielectric material that uses the 'Reflectivity' color to control the reflectance.
			/// 1.0 means it is a fully reflective metal material that uses the diffuse/base color to control the color of the metal.
			/// Values between 0.0 and 1.0 are a blend between the two types of material.
			/// Note: This only has an effect with metalness fresnel type.
			MAXON_ATTRIBUTE(Float, METALNESS, "metalness");

			/// The edge shift tint of the Fresnel effect when using "Color + Edge Tint" Fresnel.
			/// This is primarily for metals and should be black for dielectrics.
			/// Note: This only has an effect with color+edge tint fresnel type.
			MAXON_ATTRIBUTE(Color, METAL_EDGE_TINT, "metal_edge_tint");

			/// The facing reflection color of the Fresnel effect when using "Color + Edge Tint" or "Metalness".
			/// Note: This only has an effect with color+edge tint or metalness fresnel type.
			MAXON_ATTRIBUTE(Color, REFLECTIVITY, "reflectivity");

			/// This allows to you stretch reflections in a particular axis; -1 to 0 for x/u axis and 0 to 1 for y/v axis, with 0.0 meaning isotropic.
			/// Anisotropy is used to emulate materials such as brushed metals where surface roughness is focused in a particular direction.
			MAXON_ATTRIBUTE(Float, REFLECTION_ANISO, "reflection_aniso");

			/// This allows you to rotate the anisotropic effect, which can be used for emulating materials such as beaten metals.
			MAXON_ATTRIBUTE(Float, REFLECTION_ANISO_ROT, "reflection_aniso_rot");

			/// This allows you to select which reflection model to use;
			/// "Beckmann (Cook-Torrance)" is a physically-based industry-standard reflection model that accurately represents a wide variety of materials.
			/// "GGX" is a relatively new model that offers a wide specular tail, making it perfect for difficult to emulate metals such as chrome.
			/// "Ashikhmin-Shirley" is currently unused by any C4D endpoints.
			/// The default value is GGX.
			MAXON_ATTRIBUTE(InternedId, REFLECTION_BRDF, "reflection_brdf");
			MAXON_ATTRIBUTE(void, REFLECTION_BRDF_ENUM_BECKMANN, "beckmann");
			MAXON_ATTRIBUTE(void, REFLECTION_BRDF_ENUM_GGX, "ggx");
			MAXON_ATTRIBUTE(void, REFLECTION_BRDF_ENUM_ASHIKHMIN_SHIRLEY, "ashikhmin-shirley");

			/// The sheen effect can be used to simulate a soft backscatter effect commonly seen on fabrics like velvet or satin.
			/// This is the color tint of the sheen.
			MAXON_ATTRIBUTE(Color, SHEEN_COLOR, "sheen_color");

			/// This is a multipler of the sheen tint. When 0.0 the sheen effect is disabled.
			MAXON_ATTRIBUTE(Float, SHEEN_WEIGHT, "sheen_weight");

			/// This controls the roughness of the sheen reflection.
			/// Higher values result in a softer look.
			MAXON_ATTRIBUTE(Float, SHEEN_ROUGHNESS, "sheen_roughness");

			/// This is the reflection tint of the coating layer on the material.
			/// Coating emulates properties such as varnish, the reflective clear coat of car paint, or slimy and wet surfaces.
			MAXON_ATTRIBUTE(Color, COAT_COLOR, "coat_color");

			/// This is a multiplier of the coating effect.
			/// Reflections are disabled when this value is 0.0.
			MAXON_ATTRIBUTE(Float, COAT_WEIGHT, "coat_weight");

			/// This allows you to select which reflection model to use for coating;
			/// "Color" is an artist friendly mode that allows you to control the facing reflectivity color.
			/// "IOR" lets you set a single Index of Refraction value to control reflectivity and is ideal for simple dielectric materials.
			/// Dielectric materials typically have an Index of Refraction between 1.0 and 2.0, where 1.0 means no reflectivity and higher values mean stronger reflectivity.
			MAXON_ATTRIBUTE(InternedId, COAT_FRESNEL_TYPE, "coat_fresnel_type");
			MAXON_ATTRIBUTE(void, COAT_FRESNEL_TYPE_ENUM_IOR, "ior");
			MAXON_ATTRIBUTE(void, COAT_FRESNEL_TYPE_ENUM_COLOR, "color");

			/// The facing reflectivity color of the Fresnel effect when using "Color" Fresnel Type.
			MAXON_ATTRIBUTE(Color, COAT_REFLECTIVITY, "coat_reflectivity");

			/// This is the roughness of the coating reflection.
			/// Please see REFLECTION_ROUGHNESS for more information.
			MAXON_ATTRIBUTE(Float, COAT_ROUGHNESS, "coat_roughness");

			/// The index of refraction used to calculate the strength of the Fresnel effect on the coating layer.
			MAXON_ATTRIBUTE(Float, COAT_IOR, "coat_ior");

			/// This allows you to select which reflection model to use.
			/// Please see REFLECTION_BRDF for more information.
			MAXON_ATTRIBUTE(InternedId, COAT_BRDF, "coat_brdf");

			/// The coating layer has its own bump map input.
			/// This allows you to define details such as scratches separate from the base of the material.
			/// Please make sure your input textures are congruent with the specified COAT_NORMAL_SPACE.
			MAXON_ATTRIBUTE(Vector, COAT_NORMAL, "coat_normal");

			/// This scales the overall amount of normal distortion on the coating layer (0.0-1.0).
			MAXON_ATTRIBUTE(Float, COAT_NORMAL_WEIGHT, "coat_normal_weight");

			/// The input space for the COAT_NORMAL texture.
			/// Please see NORMAL_SPACE for more information.
			MAXON_ATTRIBUTE(InternedId, COAT_NORMAL_SPACE, "coat_normal_space");

			/// This is the refraction tint.
			MAXON_ATTRIBUTE(Color, TRANSMISSION_COLOR, "transmission_color");

			/// This scales the overall transmissivity (0.0 - 1.0).
			MAXON_ATTRIBUTE(Float, TRANSMISSION_WEIGHT, "transmission_weight");

			/// This is the roughness of the refraction rays.
			MAXON_ATTRIBUTE(Float, TRANSMISSION_ROUGHNESS, "transmission_roughness");

			/// This is the Index of Refraction, which determines how much refractive rays bend when entering a medium.
			/// A value of 1.0 means no ray bending.
			/// Values should typically be between 1.0 and 2.0 for common dielectric materials.
			MAXON_ATTRIBUTE(Float, TRANSMISSION_IOR, "transmission_ior");

			/// This controls how much the red, green and blue light separates for the dispersion rainbow effect.
			/// Values are in units of 'abbe'.
			/// A value of 0.0 is an invalid value for 'abbe' and disables the effect.
			/// Common dielectric materials have values between 20 and 70, with lower values yielding a stronger separation effect.
			MAXON_ATTRIBUTE(Float, TRANSMISSION_DISP, "transmission_disp");

			/// This is the subsurface color.
			MAXON_ATTRIBUTE(Color, SUBSURFACE_COLOR, "subsurface_color");

			/// This scales the overall subsurface effect (0.0 - 1.0).
			MAXON_ATTRIBUTE(Float, SUBSURFACE_WEIGHT, "subsurface_weight");

			/// This can be used to control the average distance that light can travel below the surface before it is reduced by scattering such that it can no longer have a visible effect.
			MAXON_ATTRIBUTE(Color, SUBSURFACE_RADIUS, "subsurface_radius");

			/// This value is multiplied by the RGB components of the radius to determine the distance the light can travel below the surface before it is fully scattered.
			MAXON_ATTRIBUTE(Float, SUBSURFACE_SCALE, "subsurface_scale");

			/// This value can be used to influence the direction in which the light is scattered below the surface.
			MAXON_ATTRIBUTE(Float, SUBSURFACE_ANISOTROPY, "subsurface_anisotropy");

			/// This property is used to specify the vector displacement.
			/// Please make sure your input textures are congruent with the specified DISPLACEMENT_SPACE.
			MAXON_ATTRIBUTE(Color, DISPLACEMENT_RGB, "displacement_rgb");

			/// This property is used to scale the displacement.
			MAXON_ATTRIBUTE(Float, DISPLACEMENT_SCALE, "displacement_scale");

			/// The input space for the DISPLACEMENT_RGB texture.
			/// For grayscale maps, DISPLACEMENT_SPACE_ENUM_SPACE_HEIGHTFIELD should be used.
			/// The default value is DISPLACEMENT_SPACE_ENUM_SPACE_RGB_TANGENT.
			MAXON_ATTRIBUTE(InternedId, DISPLACEMENT_SPACE, "displacement_space");
			MAXON_ATTRIBUTE(void, DISPLACEMENT_SPACE_ENUM_SPACE_NONE, "space_none");
			MAXON_ATTRIBUTE(void, DISPLACEMENT_SPACE_ENUM_SPACE_RGB_OBJECT, "space_rgb_object");
			MAXON_ATTRIBUTE(void, DISPLACEMENT_SPACE_ENUM_SPACE_RGB_TANGENT, "space_rgb_tangent");
			MAXON_ATTRIBUTE(void, DISPLACEMENT_SPACE_ENUM_SPACE_RGB_WORLD, "space_rgb_world");
			MAXON_ATTRIBUTE(void, DISPLACEMENT_SPACE_ENUM_SPACE_HEIGHTFIELD, "space_heightfield");

			/// Internal use.
			MAXON_ATTRIBUTE(DataDictionary, USERDATA, "userdata");

			MAXON_ATTRIBUTE(Bool, ISVOLUME, "isvolume");

			MAXON_ATTRIBUTE(Float, SCATTERING_COEFFICIENT, "scattering.coefficient");

			MAXON_ATTRIBUTE(Float, ABSORPTION_COEFFICIENT, "absorption.coefficient");

			MAXON_ATTRIBUTE(Float, EMISSION_COEFFICIENT, "emission.coefficient");

			MAXON_ATTRIBUTE(Float, EMISSION_TEMPERATURE, "emission.temperature");

			MAXON_ATTRIBUTE(Gradient, SCATTERING_GRADIENT, "scattering.gradient");

			MAXON_ATTRIBUTE(Gradient, ABSORPTION_GRADIENT, "absorption.gradient");

			/// Defines the type of volume emission in the viewport:
			/// - None: default - no emission
			/// - Ramp: requires an emission gradient
			/// - Blackbody: uses the temperature for blackbody radiation
			MAXON_ATTRIBUTE(InternedId, EMISSION_TYPE, "emission.type");
			MAXON_ATTRIBUTE(void, EMISSION_TYPE_ENUM_NONE, "none");
			MAXON_ATTRIBUTE(void, EMISSION_TYPE_ENUM_RAMP, "ramp");
			MAXON_ATTRIBUTE(void, EMISSION_TYPE_ENUM_BLACKBODY, "blackbody");

			MAXON_ATTRIBUTE(Gradient, EMISSION_GRADIENT, "emission.gradient");

			MAXON_ATTRIBUTE(Float, DENSITY_SHADOW_SCALE, "density.shadow_scale");

			MAXON_ATTRIBUTE(Range<Float>, DENSITY_RANGE_OLD, "density.range_old");

			MAXON_ATTRIBUTE(Range<Float>, DENSITY_RANGE_NEW, "density.range_new");

			MAXON_ATTRIBUTE(Range<Float>, EMISSION_RANGE_OLD, "emission.range_old");

			MAXON_ATTRIBUTE(Range<Float>, EMISSION_RANGE_NEW, "emission.range_new");

			MAXON_ATTRIBUTE(Group, DIFFUSE, "diffuse");

			MAXON_ATTRIBUTE(Group, OVERALL, "overall");

			MAXON_ATTRIBUTE(Group, REFLECTION, "reflection");

			MAXON_ATTRIBUTE(Group, SHEEN, "sheen");

			MAXON_ATTRIBUTE(Group, COATING, "coating");

			MAXON_ATTRIBUTE(Group, TRANSMISSION, "transmission");

			MAXON_ATTRIBUTE(Group, SUBSURFACE, "subsurface");

			MAXON_ATTRIBUTE(Group, DISPLACEMENT, "displacement");

			MAXON_ATTRIBUTE(String, OBJECT_BASE_NAME, "net.maxon.object.base.name");
		}
	}
}
}
//----------------------------------------------------------------------------------------
// END - auto generated code, do not edit
//----------------------------------------------------------------------------------------


#include "datadescription_material_redshift1.hxx"
#include "datadescription_material_redshift2.hxx"

#endif // DATADESCRIPTION_MATERIAL_REDSHIFT_H__
