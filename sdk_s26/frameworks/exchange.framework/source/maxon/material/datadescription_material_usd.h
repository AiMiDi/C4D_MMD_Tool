#ifndef DATADESCRIPTION_MATERIAL_USD_H__
#define DATADESCRIPTION_MATERIAL_USD_H__

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
		/// Describes a USD PreviewSurface material as of October 2019 found here:
		/// https://graphics.pixar.com/usd/docs/UsdPreviewSurface-Proposal.html
		//----------------------------------------------------------------------------------------
		namespace USDPREVIEWSURFACE
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.material.portbundle.usdpreviewsurface");

			/// When using metallic workflow this is interpreted as albedo.
			MAXON_ATTRIBUTE(Color, DIFFUSECOLOR, "diffuseColor");

			/// Emissive component.
			MAXON_ATTRIBUTE(Color, EMISSIVECOLOR, "emissiveColor");

			/// This node can fundamentally operate in two modes : Specular workflow where you provide a texture/value to the "specularColor" input.
			/// Or, Metallic workflow where you provide a texture/value to the "metallic" input.
			/// 
			/// Specular Workflow:
			/// Specular color to be used. This is the color at 0 incidence. Edge color is assumed white.
			/// Transition between the two colors according to Schlick fresnel approximation.
			/// 
			/// Metalness Workflow:
			/// Use 1 for metallic surfaces and 0 for non-metallic.
			/// - If metallic is 1.0, then F0 (reflectivity at 0 degree incidence)
			/// will be derived from ior ( (1-ior)/(1+ior) )^2, then multiplied
			/// by Albedo; while edge F90 reflectivity will simply be the Albedo.
			/// (As an option, you can set ior to 0 such that F0 becomes equal
			/// to F90 and thus the Albedo).
			/// 
			/// - If metallic is 0.0, then Albedo is ignored; F0 is derived from
			/// ior and F90 is white. In between, we interpolate.
			MAXON_ATTRIBUTE(InternedId, WORKFLOW, "workflow");
			MAXON_ATTRIBUTE(void, WORKFLOW_ENUM_SPECULAR, "specular");
			MAXON_ATTRIBUTE(void, WORKFLOW_ENUM_METALNESS, "metalness");

			/// Specular color to be used. This is the color at 0 incidence. Edge color is assumed white. 
			/// Transition between the two colors according to Schlick fresnel approximation.
			MAXON_ATTRIBUTE(Color, SPECULARCOLOR, "specularColor");

			/// Use 1 for metallic surfaces and 0 for non-metallic.
			/// - If metallic is 1.0, then F0 (reflectivity at 0 degree incidence) will be derived from ior ( (1-ior)/(1+ior) )^2, then multiplied by Albedo; while edge F90 reflectivity will simply be the Albedo.
			/// (As an option, you can set ior to 0 such that F0 becomes equal to F90 and thus the Albedo).
			/// - If metallic is 0.0, then Albedo is ignored; F0 is derived from ior and F90 is white. In between, we interpolate.
			MAXON_ATTRIBUTE(Float, METALLIC, "metallic");

			/// Roughness for the specular lobe. The value ranges from 0 to 1,
			/// which goes from a perfectly specular surface at 0.0 to maximum roughness
			/// of the specular lobe. This value is usually squared before use with a GGX or Beckmann lobe.
			MAXON_ATTRIBUTE(Float, ROUGHNESS, "roughness");

			/// Second specular lobe amount. The color is white.
			MAXON_ATTRIBUTE(Float, CLEARCOAT, "clearcoat");

			/// Roughness for the second specular lobe.
			MAXON_ATTRIBUTE(Float, CLEARCOATROUGHNESS, "clearcoatRoughness");

			/// When opacity is 1.0 then the gprim is fully opaque,
			/// if it is smaller than 1.0 then the prim is translucent,
			/// when it is 0 the gprim is transparent.
			/// Note that even a fully transparent object still receives
			/// lighting as, for example, perfectly clear glass still has a specular response.
			MAXON_ATTRIBUTE(Float, OPACITY, "opacity");

			/// The opacityThreshold input is useful for creating geometric cut-outs based
			/// on the opacity input. A value of 0.0 indicates that no masking is applied
			/// to the opacity input, while a value greater than 0.0 indicates that rendering
			/// of the surface is limited to the areas where the opacity is greater than that
			/// value. A classic use of opacityThreshold is to create a leaf from an opacity
			/// input texture, in that case the threshold determines the parts of the opacity
			/// texture that will be fully transparent and not receive lighting. Note that when
			/// opacityThreshold is greater than zero, then opacity modulates the presence of
			/// the surface, rather than its transparency - pathtracers might implement this as
			/// allowing ((1 - opacity) * 100) % of the rays that do intersect the object to
			/// instead pass through it unhindered, and rasterizers may interpret opacity as
			/// pixel coverage.  Thus, opacityThreshold serves as a switch for how the opacity
			/// input is interpreted; this "translucent or masked" behavior is common in engines
			/// and renderers, and makes the UsdPreviewSurface easier to interchange.  It does imply,
			/// however, that it is not possible to faithfully recreate a glassy/translucent material
			/// that also provides an opacity-based mask... so no single-polygon glass leaves.
			MAXON_ATTRIBUTE(Float, OPACITYTHRESHOLD, "opacityThreshold");

			/// Index of Refraction to be used for translucent objects.
			MAXON_ATTRIBUTE(Float, IOR, "ior");

			/// Expects normal in tangent space [(-1,-1,-1), (1,1,1)] This means
			/// your texture reader implementation should provide data to this
			/// node that is properly scaled and ready to be consumed as a tangent space normal.
			MAXON_ATTRIBUTE(Vector, NORMAL, "normal");

			/// Displacement in the direction of the normal.
			MAXON_ATTRIBUTE(Float, DISPLACEMENT, "displacement");

			/// Extra information about the occlusion of different parts of the
			/// mesh that this material is applied to.  Occlusion only makes
			/// sense as a surface-varying signal, and pathtracers will likely
			/// choose to ignore it.  An occlusion value of 0.0 means the surface
			/// point is fully occluded by other parts of the surface, and a value
			/// of 1.0 means the surface point is completely unoccluded by other parts of the surface.
			MAXON_ATTRIBUTE(Float, OCCLUSION, "occlusion");
		}
	}
}
}
//----------------------------------------------------------------------------------------
// END - auto generated code, do not edit
//----------------------------------------------------------------------------------------

namespace maxon
{

#include "datadescription_material_usd1.hxx"
#include "datadescription_material_usd2.hxx"

} // namespace maxon

#endif
