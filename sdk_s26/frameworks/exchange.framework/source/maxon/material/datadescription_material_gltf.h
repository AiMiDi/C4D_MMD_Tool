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

			/// The emissive color of the material. Default: [0,0,0]
			MAXON_ATTRIBUTE(Color, EMISSIVEFACTOR, "emissiveFactor");

			/// The tangent space normal map.
			MAXON_ATTRIBUTE(Color, NORMALTEXTURE, "normalTexture");

			/// The occlusion map indicating areas of indirect lighting.
			MAXON_ATTRIBUTE(Color, OCCLUSIONTEXTURE, "occlusionTexture");

			/// The emissive map controls the color and intensity of the light being emitted by the material.
			MAXON_ATTRIBUTE(Color, EMISSIVETEXTURE, "emissiveTexture");

			/// The alphaMpde defines how the alpha value of the main factor and texture should be interpreted map indicating areas of indirect lighting.
			/// Can be OPAQUE, MASK or BLEND. Default: "OPAQUE"
			MAXON_ATTRIBUTE(Id, ALPHAMODE, "alphaMode",
				RESOURCE_DEFINE(ENUM_OPAQUE, Id("OPAQUE"))
				RESOURCE_DEFINE(ENUM_MASK, Id("MASK"))
				RESOURCE_DEFINE(ENUM_BLEND, Id("BLEND")));

			/// The cutoff threshold. This value is only used for alpha mode MASK. Default: 0.5
			MAXON_ATTRIBUTE(Float, ALPHACUTOFF, "alphaCutoff");

			/// Specifies whether the material is double sided. Default: false
			MAXON_ATTRIBUTE(Bool, DOUBLESIDED, "doubleSided");

			/// The base color of the material. Default: [1,1,1,1]
			MAXON_ATTRIBUTE(ColorA, BASECOLORFACTOR, "baseColorFactor");

			/// The base color texture.
			MAXON_ATTRIBUTE(Color, BASECOLORTEXTURE, "baseColorTexture");

			/// The metalness of the material. Default: 1
			MAXON_ATTRIBUTE(Float, METALLICFACTOR, "metallicFactor");

			/// The roughness of the material. Default: 1
			MAXON_ATTRIBUTE(Float, ROUGHNESSFACTOR, "roughnessFactor");

			/// A single map for metalness and roughness! The metalness values is in the "b" and the roughness in the "g" color channel.
			MAXON_ATTRIBUTE(Color, METALLICROUGHNESSTEXTURE, "metallicRoughnessTexture");

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
