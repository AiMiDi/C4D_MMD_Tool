#ifndef DATADESCRIPTION_MATERIAL_GLTF_H__
#define DATADESCRIPTION_MATERIAL_GLTF_H__

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
		/// glTF defines materials using a common set of parameters that are based on widely used material representations from Physically-Based Rendering (PBR).
		/// Specifically, glTF uses the metallic-roughness material model.
		/// Using this declarative representation of materials enables a glTF file to be rendered consistently across platforms.
		//----------------------------------------------------------------------------------------
		namespace GLTF
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.material.portbundle.gltf");

			/// The base color of the material. Default: [1,1,1,1]
			MAXON_ATTRIBUTE(ColorA, BASECOLORFACTOR, "baseColorFactor");

			/// The base color texture in sRGB space.
			MAXON_ATTRIBUTE(ColorA, BASECOLORTEXTURE, "baseColorTexture");

			/// The metalness of the material. Default: 1
			MAXON_ATTRIBUTE(Float, METALLICFACTOR, "metallicFactor");

			/// The roughness of the material. Default: 1
			MAXON_ATTRIBUTE(Float, ROUGHNESSFACTOR, "roughnessFactor");

			/// A single map for metalness and roughness!
			/// The metalness values are in the "b" and the roughness in the "g" color channels.
			/// Values must not be encoded, i.e. in linear space.
			MAXON_ATTRIBUTE(Color, METALLICROUGHNESSTEXTURE, "metallicRoughnessTexture");

			/// The scale for X and Y components of normal map. Default: 1
			MAXON_ATTRIBUTE(Float, NORMALSCALE, "normalScale");

			/// The tangent space normal map.
			/// Values must not be encoded, i.e. in linear space.
			/// R [0 .. 1] -> X [-1 .. 1]
			/// G [0 .. 1] -> Y [-1 .. 1]
			/// B (.5 .. 1] -> Z (0 .. 1]
			MAXON_ATTRIBUTE(Color, NORMALTEXTURE, "normalTexture");

			/// The emissive color of the material. Default: [0,0,0]
			MAXON_ATTRIBUTE(Color, EMISSIVEFACTOR, "emissiveFactor");

			/// The emissive map controls the color and intensity of the light being emitted by the material.
			/// Values in sRGB space are expected.
			MAXON_ATTRIBUTE(Color, EMISSIVETEXTURE, "emissiveTexture");

			/// Amount of occlusion from the occlusion map. Default: 1
			/// Strength formula: <final_occlusion_value> = 1.0 + strength * (<occlusion_texture_value> - 1.0)
			MAXON_ATTRIBUTE(Float, OCCLUSIONSTRENGTH, "occlusionStrength");

			/// The occlusion map indicating areas of indirect lighting.
			/// Values are sampled only from R channel of the texture.
			/// Values must not be encoded, i.e. in linear space.
			MAXON_ATTRIBUTE(Color, OCCLUSIONTEXTURE, "occlusionTexture");

			/// The alphaMpde defines how the alpha value of the main factor and texture should be interpreted. Default: "OPAQUE"
			/// Can be:
			/// "OPAQUE" - alpha values are ignored
			/// "MASK" - fully opaque if alpha >= alphaCutoff, fully transparent otherwise
			/// "BLEND" - the actual alpha value is used
			MAXON_ATTRIBUTE(Id, ALPHAMODE, "alphaMode",
				RESOURCE_DEFINE(ENUM_OPAQUE, LiteralId("OPAQUE"))
				RESOURCE_DEFINE(ENUM_MASK, LiteralId("MASK"))
				RESOURCE_DEFINE(ENUM_BLEND, LiteralId("BLEND")));

			/// The cutoff threshold. This value is only used with alpha mode "MASK". Default: 0.5
			MAXON_ATTRIBUTE(Float, ALPHACUTOFF, "alphaCutoff");

			/// Specifies whether the material is double sided. Default: false
			MAXON_ATTRIBUTE(Bool, DOUBLESIDED, "doubleSided");

			MAXON_ATTRIBUTE(Group, GROUP_BASIC, "group.basic");

			MAXON_ATTRIBUTE(Group, GROUP_PBR_METALLIC_ROUGHNESS, "group.pbr_metallic_roughness");
		}
	}
}
}
//----------------------------------------------------------------------------------------
// END - auto generated code, do not edit
//----------------------------------------------------------------------------------------

namespace maxon
{

#include "datadescription_material_gltf1.hxx"
#include "datadescription_material_gltf2.hxx"

} // namespace maxon

#endif // DATADESCRIPTION_MATERIAL_GLTF_H__
