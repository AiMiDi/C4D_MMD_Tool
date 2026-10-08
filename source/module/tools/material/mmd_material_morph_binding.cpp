#include "module/core/cmt_old_sdk_stl_preload.h"
#include "mmd_material_morph_binding.h"
#include "plugin_resource.h"
#include "utils/cmt_morph_evaluation.hpp"

namespace mmd_material_binding
{
BaseContainer Metadata(const BaseMaterial* material)
{
	return material ? material->GetDataInstance()->GetContainer(g_mmd_material_texture_morph_shader_id) : BaseContainer();
}

Bool IsBound(const BaseMaterial* material)
{
	// Recognize older owned bindings too: never send them down the unbound
	// legacy write path. Adapters enforce the current version or explicit upgrade.
	return Metadata(material).GetInt32(Version) > 0;
}

Bool IsOwner(const BaseMaterial* material, BaseObject* model, BaseDocument* doc)
{
	return IsBound(material) && Metadata(material).GetLink(Model, doc) == model;
}

String AttributeName(const String& token, const Field field)
{
	return String("cmt_morph_") + token + String("_") + String::IntToString(static_cast<Int32>(field));
}

Vector Color(const MMDMaterialRuntimeState& state, const Field field, const Bool textured)
{
	if (field == Field::Specular) return state.specular;
	if (field == Field::TextureScale) return state.texture.SampleScale();
	if (field == Field::TextureBias) return state.texture.SampleBias();
	if (field == Field::TextureAdd) return state.texture.add_rgb;
	if (field == Field::ToonScale) return state.toon_texture.SampleScale();
	if (field == Field::ToonBias) return state.toon_texture.SampleBias();
	if (field == Field::ToonAdd) return state.toon_texture.add_rgb;
	if (field == Field::EdgeColor) return state.edge_color_rgb;
	if (field == Field::SphereScale) return state.sphere_texture.SampleScale();
	if (field == Field::SphereBias) return state.sphere_texture.SampleBias();
	if (field == Field::SphereAdd) return state.sphere_texture.add_rgb;
	return state.diffuse_rgb;
}

Float Scalar(const MMDMaterialRuntimeState& state, const Field field, const Bool textured)
{
	if (field == Field::Roughness) return cmt_runtime::MaterialRoughness(state.specular_power);
	if (field == Field::EdgeAlpha) return maxon::Clamp01(state.edge_color_alpha);
	// Contour's Thickness accepts a constant; animate its shader-compatible
	// modifier instead. 1024px maximum times size*3/1024 gives 3px per PMX unit.
	if (field == Field::EdgeWidth) return maxon::Clamp01(state.edge_size * (3.0 / 1024.0));
	// Texture-factor Alpha controls RGB in the reference operation. It is not
	// image opacity; only sampled image Alpha and diffuse Alpha affect opacity.
	return state.diffuse_alpha;
}

Bool PrepareUserData(BaseObject* mesh, BaseMaterial* material, const MMDMaterialRuntimeState& state)
{
	if (!mesh || !material || !GeIsMainThread()) return false;
	DynamicDescription* const description = mesh->GetDynamicDescriptionWritable();
	if (!description) return false;
	BaseContainer metadata = Metadata(material);
	BaseContainer allocated;
	allocated.SetInt32(Profile, metadata.GetInt32(Profile));
	allocated.SetInt32(GraphRevision, metadata.GetInt32(GraphRevision));
	for (Int32 index = 0; index < ProfileFieldCount(metadata); ++index)
	{
		const Int32 field = ProfileFieldAt(metadata, index);
		const Bool color = IsColorField(field);
		BaseContainer entry = GetCustomDataTypeDefault(color ? DTYPE_VECTOR : DTYPE_REAL);
		entry.SetString(DESC_NAME, AttributeName(metadata.GetString(Token), static_cast<Field>(field)));
		if (color) entry.SetInt32(DESC_CUSTOMGUI, CUSTOMGUI_COLOR);
		entry.SetInt32(DESC_ANIMATE, DESC_ANIMATE_OFF);
		entry.SetBool(DESC_HIDE, true);
		const DescID id = description->Alloc(entry);
		if (id.GetDepth() != 2)
		{
			RemoveUserData(mesh, allocated);
			return false;
		}
		metadata.SetInt32(UserDataKey(metadata, field), id[1].id);
		allocated.SetInt32(UserDataKey(allocated, field), id[1].id);
	}
	const BaseContainer previous = Metadata(material);
	material->GetDataInstance()->SetContainer(g_mmd_material_texture_morph_shader_id, metadata);
	if (PublishUserData(mesh, material, state)) return true;
	RemoveUserData(mesh, allocated);
	material->GetDataInstance()->SetContainer(g_mmd_material_texture_morph_shader_id, previous);
	return false;
}

void RemoveUserData(BaseObject* mesh, const BaseContainer& metadata)
{
	if (!mesh) return;
	DynamicDescription* description = mesh->GetDynamicDescriptionWritable();
	if (!description) return;
	for (Int32 index = 0; index < ProfileFieldCount(metadata); ++index)
	{
		const Int32 field = ProfileFieldAt(metadata, index);
		const Int32 parameter = metadata.GetInt32(UserDataKey(metadata, field));
		if (parameter > 0)
		{
			const DescID id = CreateDescID(DescLevel(ID_USERDATA), DescLevel(parameter));
			const BaseContainer* entry = description->Find(id);
			if (entry && (metadata.GetString(Token).IsEmpty()
				|| entry->GetString(DESC_NAME) == AttributeName(metadata.GetString(Token), static_cast<Field>(field))))
				description->Remove(id);
		}
	}
}

Bool PublishUserData(BaseObject* mesh, BaseMaterial* material, const MMDMaterialRuntimeState& state)
{
	if (!mesh || !material) return false;
	const BaseContainer metadata = Metadata(material);
	const Bool textured = metadata.GetBool(Texture);
	for (Int32 index = 0; index < ProfileFieldCount(metadata); ++index)
	{
		const Int32 field = ProfileFieldAt(metadata, index);
		const Int32 parameter = metadata.GetInt32(UserDataKey(metadata, field));
		if (parameter <= 0) return false;
		const Bool color = IsColorField(field);
		const DescID id = CreateDescID(DescLevel(ID_USERDATA, DTYPE_SUBCONTAINER, 0), DescLevel(parameter, color ? DTYPE_VECTOR : DTYPE_REAL, 0));
		const DynamicDescription* description = mesh->GetDynamicDescription();
		// Find is a read operation but lacks a const qualifier in older SDKs.
		const BaseContainer* entry = description ? const_cast<DynamicDescription*>(description)->Find(id) : nullptr;
		if (!entry || entry->GetString(DESC_NAME) != AttributeName(metadata.GetString(Token), static_cast<Field>(field)))
			return false;
		GeData current;
		if (!mesh->GetParameter(id, current, DESCFLAGS_GET::NONE)) return false;
		const GeData value = color ? GeData(Color(state, static_cast<Field>(field), textured))
			: GeData(Scalar(state, static_cast<Field>(field), textured));
		if (current != value && !mesh->SetParameter(id, value, DESCFLAGS_SET::NONE)) return false;
	}
	return true;
}
}
