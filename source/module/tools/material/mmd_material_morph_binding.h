#pragma once

#include "mmd_material.h"

// Metadata lives under the existing registered shader ID. Keep keys separate
// from legacy Standard material schema keys and retain them across save/clone.
namespace mmd_material_binding
{
constexpr Int32 Version = 100;
constexpr Int32 Model = 101;
constexpr Int32 Token = 102;
constexpr Int32 Surface = 103;
constexpr Int32 Texture = 104;
constexpr Int32 DiffuseShader = 105;
constexpr Int32 OpacityShader = 106;
constexpr Int32 SpecularShader = 107;
constexpr Int32 RoughnessShader = 108;
constexpr Int32 Layer = 109;
constexpr Int32 ImportedReflectanceLayer = 110;
constexpr Int32 ImporterOwned = 90;
constexpr Int32 UserDataFirst = 120;
constexpr Int32 ChildShaderFirst = 130;
constexpr Int32 OutputModeFirst = 140;
// Last installed bitmap path, retained while a texture branch is inactive.
constexpr Int32 TexturePath = 150;
constexpr Int32 CurrentVersion = 2;

// RS Toon uses its own attribute range so additional roles never overlap the
// preserved Standard child-shader keys (130+) or the legacy RS field range.
constexpr Int32 Profile = 170;
constexpr Int32 GraphRevision = 171;
constexpr Int32 ToonTexturePath = 172;
constexpr Int32 EdgeEnabled = 173;
constexpr Int32 ToonHasTexture = 174;
constexpr Int32 ProfileDiagnostic = 175;
constexpr Int32 AdditionalUvUsage = 176;
constexpr Int32 ToonBoundaryV = 177;
constexpr Int32 ToonNeutralFallback = 178;
constexpr Int32 SphereTexturePath = 179;
constexpr Int32 SphereMode = 180;
constexpr Int32 SphereHasTexture = 181;
constexpr Int32 StandardMatcapRevision = 182;
constexpr Int32 SphereShader = 183;
constexpr Int32 ToonProfile = 1;
constexpr Int32 ToonGraphRevision = 5;
constexpr Int32 ToonUserDataFirst = 300;
constexpr Int32 StandardSphereProfile = 2;
constexpr Int32 StandardSphereGraphRevision = 1;
constexpr Int32 StandardSphereUserDataFirst = 400;

enum class Field : Int32
{
	Diffuse, Opacity, Specular, Roughness, TextureScale, TextureBias, TextureAdd,
	ToonScale, ToonBias, ToonAdd, EdgeColor, EdgeAlpha, EdgeWidth,
	SphereScale, SphereBias, SphereAdd, Count
};
// Existing Standard/RS Standard adapters retain their original role set.
constexpr Int32 FieldCount = static_cast<Int32>(Field::TextureAdd) + 1;
constexpr Int32 ToonFieldCount = static_cast<Int32>(Field::Count);
inline Bool IsColorField(const Int32 field)
{
	return field != static_cast<Int32>(Field::Opacity) && field != static_cast<Int32>(Field::Roughness)
		&& field != static_cast<Int32>(Field::EdgeAlpha) && field != static_cast<Int32>(Field::EdgeWidth);
}
inline Int32 ProfileFieldCount(const BaseContainer& metadata)
{
	if (metadata.GetInt32(Profile) == StandardSphereProfile) return FieldCount + 3;
	if (metadata.GetInt32(Profile) != ToonProfile) return FieldCount;
	// Preserve the thirteen-role schema when cleaning or copying older Toon
	// bindings. Only an explicit conversion creates the revision 5 attributes.
	return metadata.GetInt32(GraphRevision) >= 5 ? ToonFieldCount
		: static_cast<Int32>(Field::SphereScale);
}
// Iteration positions are not serialized field IDs. The PBR profile skips the
// Toon/Contour fields but retains Sphere's IDs shared with the runtime evaluator.
inline Int32 ProfileFieldAt(const BaseContainer& metadata, const Int32 index)
{
	return metadata.GetInt32(Profile) == StandardSphereProfile && index >= FieldCount
		? static_cast<Int32>(Field::SphereScale) + index - FieldCount : index;
}
inline Int32 UserDataKey(const BaseContainer& metadata, const Int32 field)
{
	const Int32 profile = metadata.GetInt32(Profile);
	return (profile == ToonProfile ? ToonUserDataFirst
		: profile == StandardSphereProfile ? StandardSphereUserDataFirst : UserDataFirst) + field;
}

BaseContainer Metadata(const BaseMaterial* material);
Bool IsBound(const BaseMaterial* material);
Bool IsOwner(const BaseMaterial* material, BaseObject* model, BaseDocument* doc);
String AttributeName(const String& token, Field field);
Vector Color(const MMDMaterialRuntimeState& state, Field field, Bool textured);
Float Scalar(const MMDMaterialRuntimeState& state, Field field, Bool textured);
Bool PrepareUserData(BaseObject* mesh, BaseMaterial* material, const MMDMaterialRuntimeState& state);
void RemoveUserData(BaseObject* mesh, const BaseContainer& metadata);
Bool PublishUserData(BaseObject* mesh, BaseMaterial* material, const MMDMaterialRuntimeState& state);
}
