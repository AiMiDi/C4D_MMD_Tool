#include "module/core/cmt_old_sdk_stl_preload.h"
#include "mmd_standard_material.h"
#include "mmd_material.h"
#include "mmd_material_morph_shader.h"
#include "plugin_resource.h"
#include "description/Xmmdmaterialmorphshader.h"
#include "xcolor.h"
#include "xbitmap.h"
#include "c4d_reflection.h"
#include "mmd_material_morph_binding.h"
#include "maxon/uuid.h"

namespace
{
// Use the registered shader plugin ID as a BaseContainer namespace. These local
// keys do not collide with the host's material description parameters.
constexpr Int32 k_standard_material_schema_key = 1;
constexpr Int32 k_standard_material_schema_without_toon_emission = 1;

Bool IsIdentityFactor(const Vector& factor, const Float factor_alpha)
{
	return factor.x == 1.0 && factor.y == 1.0 && factor.z == 1.0 && factor_alpha == 1.0;
}

Vector ComponentMultiply(const Vector& lhs, const Vector& rhs)
{
	return Vector(lhs.x * rhs.x, lhs.y * rhs.y, lhs.z * rhs.z);
}

Bool HasStandardSphereApproximation(const Int32 sphere_mode, const String& texture_path)
{
	// SubTexture uses PMX additional UV1, which this Standard adapter cannot
	// supply. Never silently reinterpret it as an environment reflection.
	return texture_path.IsPopulated()
		&& (sphere_mode == static_cast<Int32>(libmmd::PMXSphereMode::Mul)
			|| sphere_mode == static_cast<Int32>(libmmd::PMXSphereMode::Add));
}

void MarkStandardMaterialSchema(Material* const material)
{
	BaseContainer* const data = material ? material->GetDataInstance() : nullptr;
	if (!data)
		return;
	BaseContainer metadata = data->GetContainer(g_mmd_material_texture_morph_shader_id);
	metadata.SetInt32(k_standard_material_schema_key, k_standard_material_schema_without_toon_emission);
	data->SetContainer(g_mmd_material_texture_morph_shader_id, metadata);
}

void SetChannelTexture(Material* const material, const Int32 channel_id, const String& texture_path)
{
	if (!material || texture_path.IsEmpty())
		return;
	material->SetChannelState(channel_id, true);
	if (BaseChannel* const channel = material->GetChannel(channel_id))
	{
		BaseContainer data = channel->GetData();
		data.SetString(BASECHANNEL_TEXTURE, texture_path);
		channel->SetData(data);
	}
}

BaseShader* GetMaterialShader(Material* const material, BaseDocument* const doc, const Int32 shader_param_id)
{
	if (!material)
		return nullptr;
	GeData gd;
	if (!GetAtomParameter(material, CreateDescID(DescLevel(shader_param_id)), gd, DESCFLAGS_GET::NONE))
		return nullptr;
	return static_cast<BaseShader*>(gd.GetLink(doc));
}

Bool IsUneditedLegacyToonLuminance(Material* const material, BaseDocument* const doc,
	const String& toon_texture_path)
{
	if (!material || toon_texture_path.IsEmpty())
		return false;

	GeData color;
	GeData brightness;
	GeData texture_strength;
	GeData texture_mixing;
	if (!GetAtomParameter(material, ConstDescID(DescLevel(MATERIAL_LUMINANCE_COLOR)), color, DESCFLAGS_GET::NONE)
		|| !GetAtomParameter(material, ConstDescID(DescLevel(MATERIAL_LUMINANCE_BRIGHTNESS)), brightness, DESCFLAGS_GET::NONE)
		|| !GetAtomParameter(material, ConstDescID(DescLevel(MATERIAL_LUMINANCE_TEXTURESTRENGTH)), texture_strength, DESCFLAGS_GET::NONE)
		|| !GetAtomParameter(material, ConstDescID(DescLevel(MATERIAL_LUMINANCE_TEXTUREMIXING)), texture_mixing, DESCFLAGS_GET::NONE))
	{
		return false;
	}
	// The old importer left all these settings at their defaults. Treat modified
	// emission settings as artist-owned, even when they happen to use a toon file.
	if (color.GetVector() != Vector(1.0) || brightness.GetFloat() != 1.0
		|| texture_strength.GetFloat() != 1.0 || texture_mixing.GetInt32() != MATERIAL_TEXTUREMIXING_NORMAL)
	{
		return false;
	}

	BaseShader* shader = GetMaterialShader(material, doc, MATERIAL_LUMINANCE_SHADER);
	if (shader && shader->IsInstanceOf(g_mmd_material_texture_morph_shader_id))
	{
		// Material morphs may have wrapped the original bitmap. Only recognize
		// that exact one-child shape, never arbitrary artist-created shader graphs.
		shader = shader->GetDown();
		if (!shader || shader->GetNext())
			return false;
	}
	if (shader)
	{
		if (!shader->IsInstanceOf(Xbitmap) || shader->GetDown())
			return false;
		GeData filename;
		return GetAtomParameter(shader, ConstDescID(DescLevel(BITMAPSHADER_FILENAME)), filename, DESCFLAGS_GET::NONE)
			&& filename.GetFilename().GetString() == toon_texture_path;
	}

	// Some older SDK scenes still store a channel texture path before C4D has
	// materialized the corresponding bitmap shader.
	BaseChannel* const channel = material->GetChannel(CHANNEL_LUMINANCE);
	return channel && channel->GetData().GetString(BASECHANNEL_TEXTURE) == toon_texture_path;
}

void MigrateLegacyToonLuminance(Material* const material, BaseDocument* const doc,
	const String& toon_texture_path)
{
	BaseContainer* const data = material ? material->GetDataInstance() : nullptr;
	if (!data)
		return;
	const BaseContainer metadata = data->GetContainer(g_mmd_material_texture_morph_shader_id);
	if (metadata.GetInt32(k_standard_material_schema_key) >= k_standard_material_schema_without_toon_emission)
		return;

	if (IsUneditedLegacyToonLuminance(material, doc, toon_texture_path))
		material->SetChannelState(CHANNEL_LUMINANCE, false);
	// Keep the old shader intact and perform this check only once. Artists can
	// subsequently reuse or re-enable it without material-morph synchronization
	// repeatedly disabling their chosen emission.
	MarkStandardMaterialSchema(material);
}

void SetChannelTextureIfUnwrapped(Material* const material, BaseDocument* const doc,
	const Int32 channel_id, const Int32 shader_param_id, const String& texture_path)
{
	BaseShader* const shader = GetMaterialShader(material, doc, shader_param_id);
	if (shader && shader->IsInstanceOf(g_mmd_material_texture_morph_shader_id))
		return;
	SetChannelTexture(material, channel_id, texture_path);
}

void SetTextureMorphShaderFactor(BaseShader* const shader, const Vector& factor, const Float factor_alpha)
{
	if (!shader)
		return;
	shader->SetParameter(ConstDescID(DescLevel(MMDMATERIALMORPHSHADER_FACTOR_COLOR)), factor, DESCFLAGS_SET::NONE);
	shader->SetParameter(ConstDescID(DescLevel(MMDMATERIALMORPHSHADER_FACTOR_ALPHA)), factor_alpha, DESCFLAGS_SET::NONE);
}

void SyncTextureMorphChannel(Material* const material, BaseDocument* const doc, const Int32 channel_id,
	const Int32 shader_param_id, const Vector& factor, const Float factor_alpha)
{
	if (!material)
		return;
	BaseChannel* const channel = material->GetChannel(channel_id);
	if (!channel)
		return;

	BaseShader* current_shader = GetMaterialShader(material, doc, shader_param_id);
	if (current_shader && current_shader->IsInstanceOf(g_mmd_material_texture_morph_shader_id))
	{
		SetTextureMorphShaderFactor(current_shader, factor, factor_alpha);
		return;
	}
	// Pure-color channels are updated directly by SyncTo(). Wrapping Xcolor would
	// apply diffuse/alpha twice and would incorrectly make texture factors affect
	// a material that has no texture sample.
	if (current_shader && current_shader->IsInstanceOf(Xcolor))
		return;

	if (IsIdentityFactor(factor, factor_alpha))
		return;

	BaseContainer channel_data = channel->GetData();
	const String tex_path = channel_data.GetString(BASECHANNEL_TEXTURE);

	BaseShader* child = current_shader;
	Bool child_is_new = false;
	if (!child)
	{
		if (tex_path.IsEmpty())
			return;
		child = BaseShader::Alloc(Xbitmap);
		if (!child)
			return;
		child->SetParameter(ConstDescID(DescLevel(BITMAPSHADER_FILENAME)), Filename(tex_path), DESCFLAGS_SET::NONE);
		child_is_new = true;
	}

	BaseShader* const wrapper = BaseShader::Alloc(g_mmd_material_texture_morph_shader_id);
	if (!wrapper)
	{
		if (child_is_new)
			BaseShader::Free(child);
		return;
	}
	SetTextureMorphShaderFactor(wrapper, factor, factor_alpha);

	if (!child_is_new)
		child->Remove();

	material->InsertShader(wrapper);
	child->InsertUnder(wrapper);
	material->SetParameter(CreateDescID(DescLevel(shader_param_id)), wrapper, DESCFLAGS_SET::NONE);
	material->SetChannelState(channel_id, true);

	if (child_is_new && tex_path.IsPopulated())
	{
		channel_data.SetString(BASECHANNEL_TEXTURE, ""_s);
		channel->SetData(channel_data);
	}
}

Bool SetInitialBitmapChannel(Material* const material, const Int32 shader_param_id,
	const String& texture_path, const Vector& factor, const Float factor_alpha)
{
	BaseShader* bitmap = BaseShader::Alloc(Xbitmap);
	if (!bitmap)
		return false;
	bitmap->SetParameter(ConstDescID(DescLevel(BITMAPSHADER_FILENAME)), Filename(texture_path), DESCFLAGS_SET::NONE);

	BaseShader* shader = bitmap;
	if (!IsIdentityFactor(factor, factor_alpha))
	{
		shader = BaseShader::Alloc(g_mmd_material_texture_morph_shader_id);
		if (!shader)
		{
			BaseShader::Free(bitmap);
			return false;
		}
		SetTextureMorphShaderFactor(shader, factor, factor_alpha);
		bitmap->InsertUnder(shader);
	}
	material->InsertShader(shader);
	return material->SetParameter(CreateDescID(DescLevel(shader_param_id)), shader, DESCFLAGS_SET::NONE);
}

Bool SetInitialColorChannel(Material* const material, const Int32 shader_param_id,
	const Vector& color, const Float brightness)
{
	BaseShader* const shader = BaseShader::Alloc(Xcolor);
	if (!shader)
		return false;
	shader->SetParameter(ConstDescID(DescLevel(COLORSHADER_COLOR)), color, DESCFLAGS_SET::NONE);
	shader->SetParameter(ConstDescID(DescLevel(COLORSHADER_BRIGHTNESS)), brightness, DESCFLAGS_SET::NONE);
	material->InsertShader(shader);
	return material->SetParameter(CreateDescID(DescLevel(shader_param_id)), shader, DESCFLAGS_SET::NONE);
}

Bool SetInitialDiffuseChannels(Material* const material, const Bool has_texture,
	const Bool has_alpha_channel, const String& texture_path,
	const Vector& diffuse_rgb, const Float diffuse_alpha)
{
	// The PMX diffuse value multiplies the texture even when no material morph
	// exists. Keep the host's channel mix neutral and store that complete factor
	// in the same wrapper later updated by SyncRuntimeState(), so it is applied once.
	material->SetChannelState(CHANNEL_COLOR, true);
	material->SetParameter(ConstDescID(DescLevel(MATERIAL_COLOR_COLOR)), Vector(1.0), DESCFLAGS_SET::NONE);
	material->SetParameter(ConstDescID(DescLevel(MATERIAL_COLOR_BRIGHTNESS)), 1.0, DESCFLAGS_SET::NONE);
	material->SetParameter(ConstDescID(DescLevel(MATERIAL_COLOR_TEXTUREMIXING)), MATERIAL_TEXTUREMIXING_NORMAL, DESCFLAGS_SET::NONE);
	material->SetParameter(ConstDescID(DescLevel(MATERIAL_COLOR_TEXTURESTRENGTH)), 1.0, DESCFLAGS_SET::NONE);

	const Bool color_ok = has_texture
		? SetInitialBitmapChannel(material, MATERIAL_COLOR_SHADER, texture_path, diffuse_rgb, 1.0)
		: SetInitialColorChannel(material, MATERIAL_COLOR_SHADER, diffuse_rgb, 1.0);
	if (!color_ok)
		return false;

	material->SetChannelState(CHANNEL_ALPHA, true);
	material->SetParameter(ConstDescID(DescLevel(MATERIAL_ALPHA_IMAGEALPHA)), true, DESCFLAGS_SET::NONE);
	return has_alpha_channel
		? SetInitialBitmapChannel(material, MATERIAL_ALPHA_SHADER, texture_path, Vector(1.0), diffuse_alpha)
		: SetInitialColorChannel(material, MATERIAL_ALPHA_SHADER, Vector(1.0), diffuse_alpha);
}

Bool InstallStandardSphere(Material* material, const MMDMaterialData& data)
{
	using namespace mmd_material_binding;
	BaseShader* output = GetMaterialShader(material, material->GetDocument(), MATERIAL_COLOR_SHADER);
	if (!output) return false;
	if (!output->IsInstanceOf(g_mmd_material_texture_morph_shader_id))
	{
		BaseShader* wrapper = BaseShader::Alloc(g_mmd_material_texture_morph_shader_id);
		if (!wrapper) return false;
		output->Remove();
		output->InsertUnder(wrapper);
		material->InsertShader(wrapper);
		material->SetParameter(ConstDescID(DescLevel(MATERIAL_COLOR_SHADER)), wrapper, DESCFLAGS_SET::NONE);
		output = wrapper;
	}
	BaseShader* sphere = BaseShader::Alloc(Xbitmap);
	if (!sphere) return false;
	sphere->SetParameter(ConstDescID(DescLevel(BITMAPSHADER_FILENAME)), Filename(data.sphere_texture_path), DESCFLAGS_SET::NONE);
	sphere->InsertUnderLast(output);
	BaseContainer* shader = output->GetDataInstance();
	shader->SetLink(MMDMATERIALMORPHSHADER_SPHERE_SHADER, sphere);
	const Bool active = HasStandardSphereApproximation(data.sphere_mode, data.sphere_texture_path)
		&& GeFExist(Filename(data.sphere_texture_path));
	shader->SetInt32(MMDMATERIALMORPHSHADER_SPHERE_MODE, active ? data.sphere_mode : 0);
	BaseContainer metadata = Metadata(material);
	metadata.SetInt32(StandardMatcapRevision, 1);
	metadata.SetString(SphereTexturePath, data.sphere_texture_path);
	metadata.SetInt32(SphereMode, data.sphere_mode);
	metadata.SetBool(SphereHasTexture, active);
	metadata.SetLink(SphereShader, sphere);
	material->GetDataInstance()->SetContainer(g_mmd_material_texture_morph_shader_id, metadata);
	return true;
}

}

BaseMaterial* MMDStandardMaterialAdapter::CreateFromPMX(const libmmd::PMXMaterial& pmx_material,
	const maxon::BaseArray<Filename>& texture_paths, const maxon::String& material_name)
{
	MMDMaterialData data;
	data.FromPMX(pmx_material);
	const Int32 texture_index = pmx_material.m_textureIndex;
	if (texture_index >= 0 && texture_index < texture_paths.GetCount())
		data.texture_path = texture_paths[texture_index].GetString();
	const Int32 sphere_index = pmx_material.m_sphereTextureIndex;
	if (sphere_index >= 0 && sphere_index < texture_paths.GetCount())
		data.sphere_texture_path = texture_paths[sphere_index].GetString();
	BaseMaterial* const material = CreateFromData(data);
	if (material)
		material->SetName(material_name);
	return material;
}

BaseMaterial* MMDStandardMaterialAdapter::CreateFromData(const MMDMaterialData& data)
{
	Material* material = Material::Alloc();
	if (!material)
		return nullptr;
	material->SetChannelState(CHANNEL_LUMINANCE, false);
	MarkStandardMaterialSchema(material);

	const auto tex_info = MMDMaterialAdapter::DetectTextureFromData(data);
	const bool has_texture = tex_info.has_texture;
	const bool has_alpha_channel = tex_info.has_alpha;
	const Filename texture_path(data.texture_path);

	if (!SetInitialDiffuseChannels(material, has_texture, has_alpha_channel, texture_path.GetString(),
		data.diffuse_rgb, data.diffuse_alpha))
	{
		BaseMaterial* base_material = material;
		BaseMaterial::Free(base_material);
		return nullptr;
	}

	material->SetChannelState(CHANNEL_SPECULAR, true);
	material->SetParameter(ConstDescID(DescLevel(MATERIAL_SPECULAR_COLOR)), data.specular, DESCFLAGS_SET::NONE);
	Float specular_width = maxon::Clamp01(data.specular_power / 100.0);
	material->SetParameter(ConstDescID(DescLevel(MATERIAL_SPECULAR_WIDTH)), specular_width, DESCFLAGS_SET::NONE);
	if (ReflectionLayer* imported = material->GetReflectionLayerIndex(0))
	{
		BaseContainer metadata = mmd_material_binding::Metadata(material);
		metadata.SetInt32(mmd_material_binding::ImportedReflectanceLayer, imported->GetLayerID());
		material->GetDataInstance()->SetContainer(g_mmd_material_texture_morph_shader_id, metadata);
	}

	material->SetChannelState(CHANNEL_ENVIRONMENT, false);
	if (!InstallStandardSphere(material, data))
	{
		BaseMaterial* failed = material;
		BaseMaterial::Free(failed);
		return nullptr;
	}
	material->SetName(data.name_local);
	return material;
}

Bool MMDStandardMaterialAdapter::PrepareMorphBinding(const MMDMaterialData& data, BaseMaterial* material,
	BaseObject* model, BaseObject* mesh, String& diagnostic)
{
	using namespace mmd_material_binding;
	if (!material || !model || !GeIsMainThread() || !material->IsInstanceOf(Mmaterial)) return false;
	if (IsBound(material)) return ValidateMorphBinding(material, diagnostic);
	BaseContainer metadata = Metadata(material);
	if (metadata.GetInt32(k_standard_material_schema_key) != k_standard_material_schema_without_toon_emission)
	{ diagnostic = "Standard material has no recognized importer ownership"_s; return false; }
	Material* const mat = static_cast<Material*>(material);
	BaseDocument* const doc = mat->GetDocument();
	const TextureInfo texture = DetectTextureFromData(data);
	ReflectionLayer* imported_layer = mat->GetReflectionLayerID(metadata.GetInt32(ImportedReflectanceLayer));
	if (!imported_layer && mat->GetReflectionLayerCount() == 1)
		imported_layer = mat->GetReflectionLayerIndex(0);
	if (!imported_layer)
	{ diagnostic = "Cannot identify imported reflectance layer; create an independent material"_s; return false; }
	GeData distribution;
	mat->GetParameter(CreateDescID(DescLevel(imported_layer->GetDataID() + REFLECTION_LAYER_MAIN_DISTRIBUTION)), distribution, DESCFLAGS_GET::NONE);
	if (distribution.GetInt32() != REFLECTION_DISTRIBUTION_SPECULAR_BLINN
		&& distribution.GetInt32() != REFLECTION_DISTRIBUTION_SPECULAR_PHONG)
	{ diagnostic = "Imported reflectance layer was modified; create an independent material"_s; return false; }
	// Do not replace a user's custom color/alpha network. Recognized wrappers
	// keep their child, including the original bitmap sampling configuration.
	for (const Int32 parameter : {MATERIAL_COLOR_SHADER, MATERIAL_ALPHA_SHADER})
	{
		BaseShader* shader = GetMaterialShader(mat, doc, parameter);
		if (shader && !shader->IsInstanceOf(g_mmd_material_texture_morph_shader_id)
			&& !shader->IsInstanceOf(Xcolor) && !shader->IsInstanceOf(Xbitmap))
		{ diagnostic = "Custom Standard shader requires an independent material"_s; return false; }
	}
	BaseShader* outputs[4] = {};
	for (Int32 field = 0; field < 4; ++field)
	{
		outputs[field] = BaseShader::Alloc(g_mmd_material_texture_morph_shader_id);
		if (!outputs[field])
		{
			for (auto*& output : outputs) if (output) BaseShader::Free(output);
			diagnostic = "Could not allocate material output shaders"_s;
			return false;
		}
	}
	ReflectionLayer* layer = mat->AddReflectionLayer();
	if (!layer)
	{
		for (auto*& output : outputs) BaseShader::Free(output);
		return false;
	}
	layer->SetName("MMD Morph Specular"_s);
	const Int32 layer_id = layer->GetDataID();
	metadata.SetInt32(Layer, layer->GetLayerID());
	const Int32 parameters[] = {MATERIAL_COLOR_SHADER, MATERIAL_ALPHA_SHADER,
		layer_id + REFLECTION_LAYER_COLOR_TEXTURE, layer_id + REFLECTION_LAYER_MAIN_SHADER_ROUGHNESS};
	for (Int32 field = 0; field < 4; ++field)
	{
		BaseShader* const shader = outputs[field];
		BaseContainer* const shader_data = shader->GetDataInstance();
		const Int32 mode = field == 0 ? (texture.has_texture ? 3 : 1) : field == 1 ? (texture.has_alpha ? 4 : 2) : field == 2 ? 1 : 2;
		shader_data->SetInt32(MMDMATERIALMORPHSHADER_OUTPUT, mode);
		shader_data->SetInt32(MMDMATERIALMORPHSHADER_FIELD, field);
		shader_data->SetLink(MMDMATERIALMORPHSHADER_MODEL, model);
		shader_data->SetLink(MMDMATERIALMORPHSHADER_MATERIAL, material);
		shader_data->SetBool(MMDMATERIALMORPHSHADER_TEXTURED, texture.has_texture);
		BaseShader* child = field < 2 ? GetMaterialShader(mat, doc, parameters[field]) : nullptr;
		if (child && child->IsInstanceOf(g_mmd_material_texture_morph_shader_id))
		{
			BaseShader* wrapper = child;
			// Preserve the separate Matcap bitmap when replacing the legacy
			// coefficient wrapper with a model-driven render snapshot.
			BaseShader* sphere = static_cast<BaseShader*>(wrapper->GetDataInstance()->GetLink(
				MMDMATERIALMORPHSHADER_SPHERE_SHADER, doc, Xbitmap));
			if (sphere && sphere->GetUp() == wrapper)
			{
				sphere->Remove();
				sphere->InsertUnderLast(shader);
				shader_data->SetLink(MMDMATERIALMORPHSHADER_SPHERE_SHADER, sphere);
				shader_data->SetInt32(MMDMATERIALMORPHSHADER_SPHERE_MODE,
					wrapper->GetDataInstance()->GetInt32(MMDMATERIALMORPHSHADER_SPHERE_MODE));
			}
			child = wrapper->GetDown();
			if (child) child->Remove();
			wrapper->Remove();
			BaseShader::Free(wrapper);
		}
		if (child) { child->Remove(); child->InsertUnder(shader); }
		mat->InsertShader(shader);
		mat->SetParameter(CreateDescID(DescLevel(parameters[field])), shader, DESCFLAGS_SET::NONE);
		metadata.SetLink(DiffuseShader + field, shader);
		metadata.SetLink(ChildShaderFirst + field, shader->GetDown());
		metadata.SetInt32(OutputModeFirst + field, mode);
	}
	// Keep custom reflectance layers intact. The imported legacy primary layer
	// is disabled by its strength; the new owned layer carries animated specular.
	mat->SetParameter(CreateDescID(DescLevel(imported_layer->GetDataID() + REFLECTION_LAYER_MAIN_VALUE_SPECULAR)), 0.0, DESCFLAGS_SET::NONE);
	mat->SetParameter(CreateDescID(DescLevel(layer_id + REFLECTION_LAYER_MAIN_DISTRIBUTION)), REFLECTION_DISTRIBUTION_GGX, DESCFLAGS_SET::NONE);
	mat->SetParameter(CreateDescID(DescLevel(layer_id + REFLECTION_LAYER_MAIN_VALUE_REFLECTION)), 0.0, DESCFLAGS_SET::NONE);
	mat->SetParameter(CreateDescID(DescLevel(layer_id + REFLECTION_LAYER_MAIN_VALUE_SPECULAR)), 1.0, DESCFLAGS_SET::NONE);
	// The roughness texture multiplies this value. Leave its range at 100%
	// so the scalar shader's PMX approximation is the actual layer roughness.
	mat->SetParameter(CreateDescID(DescLevel(layer_id + REFLECTION_LAYER_MAIN_VALUE_ROUGHNESS)), 1.0, DESCFLAGS_SET::NONE);
	mat->SetParameter(CreateDescID(DescLevel(layer_id + REFLECTION_LAYER_COLOR_COLOR)), Vector(1.0), DESCFLAGS_SET::NONE);
	mat->SetParameter(CreateDescID(DescLevel(layer_id + REFLECTION_LAYER_COLOR_MIX_STRENGTH)), 1.0, DESCFLAGS_SET::NONE);
	metadata.SetInt32(Version, CurrentVersion);
	metadata.SetLink(Model, model);
	metadata.SetBool(Texture, texture.has_texture);
	mat->GetDataInstance()->SetContainer(g_mmd_material_texture_morph_shader_id, metadata);
	diagnostic = "Shader binding ready; Matcap Sphere supported, toon/ambient/edge remain metadata"_s;
	return true;
}

Bool MMDStandardMaterialAdapter::ValidateMorphBinding(BaseMaterial* material, String& diagnostic) const
{
	using namespace mmd_material_binding;
	if (!IsBound(material) || !material->IsInstanceOf(Mmaterial)) return false;
	Material* mat = static_cast<Material*>(material);
	const BaseContainer metadata = Metadata(material);
	if (metadata.GetInt32(Version) != CurrentVersion)
	{ diagnostic = "Texture Morph semantics changed; explicitly upgrade material Morph"_s; return false; }
	ReflectionLayer* layer = mat->GetReflectionLayerID(metadata.GetInt32(Layer));
	if (!layer) { diagnostic = "MMD reflectance layer is missing"_s; return false; }
	GeData roughness_scale;
	if (!mat->GetParameter(CreateDescID(DescLevel(layer->GetDataID() + REFLECTION_LAYER_MAIN_VALUE_ROUGHNESS)), roughness_scale, DESCFLAGS_GET::NONE)
		|| roughness_scale.GetFloat() != 1.0)
	{ diagnostic = "MMD roughness range was changed; explicit repair is required"_s; return false; }
	const Int32 parameters[] = {MATERIAL_COLOR_SHADER, MATERIAL_ALPHA_SHADER,
		layer->GetDataID() + REFLECTION_LAYER_COLOR_TEXTURE, layer->GetDataID() + REFLECTION_LAYER_MAIN_SHADER_ROUGHNESS};
	for (Int32 field = 0; field < 4; ++field)
	{
		BaseShader* shader = GetMaterialShader(mat, mat->GetDocument(), parameters[field]);
		if (!shader || shader != metadata.GetLink(DiffuseShader + field, mat->GetDocument())
			|| !shader->IsInstanceOf(g_mmd_material_texture_morph_shader_id))
		{ diagnostic = "MMD shader connection was changed; explicit repair is required"_s; return false; }
		const BaseContainer* binding = shader->GetDataInstance();
		const Int32 output = binding->GetInt32(MMDMATERIALMORPHSHADER_OUTPUT);
		if ((output == 3 || output == 4) && !shader->GetDown())
		{ diagnostic = "MMD texture child is missing; explicit repair is required"_s; return false; }
		if (binding->GetLink(MMDMATERIALMORPHSHADER_MODEL, mat->GetDocument()) != metadata.GetLink(Model, mat->GetDocument())
			|| binding->GetLink(MMDMATERIALMORPHSHADER_MATERIAL, mat->GetDocument()) != material
			|| binding->GetInt32(MMDMATERIALMORPHSHADER_FIELD) != field
			|| binding->GetBool(MMDMATERIALMORPHSHADER_TEXTURED) != metadata.GetBool(Texture)
			|| binding->GetInt32(MMDMATERIALMORPHSHADER_OUTPUT) != metadata.GetInt32(OutputModeFirst + field)
			|| shader->GetDown() != metadata.GetLink(ChildShaderFirst + field, mat->GetDocument()))
		{ diagnostic = "MMD shader binding was changed; explicit repair is required"_s; return false; }
	}
	if (metadata.GetInt32(StandardMatcapRevision) == 1)
	{
		auto* output = static_cast<BaseShader*>(metadata.GetLink(DiffuseShader, mat->GetDocument()));
		auto* sphere = static_cast<BaseShader*>(output->GetDataInstance()->GetLink(
			MMDMATERIALMORPHSHADER_SPHERE_SHADER, mat->GetDocument(), Xbitmap));
		GeData path;
		if (!sphere || sphere != metadata.GetLink(SphereShader, mat->GetDocument()) || sphere->GetUp() != output
			|| !sphere->GetParameter(ConstDescID(DescLevel(BITMAPSHADER_FILENAME)), path, DESCFLAGS_GET::NONE)
			|| path.GetFilename() != Filename(metadata.GetString(SphereTexturePath))
			|| output->GetDataInstance()->GetInt32(MMDMATERIALMORPHSHADER_SPHERE_MODE)
				!= (metadata.GetBool(SphereHasTexture) ? metadata.GetInt32(SphereMode) : 0))
		{ diagnostic = "Standard Matcap binding was edited; create an independent material"_s; return false; }
	}
	return true;
}

Bool MMDStandardMaterialAdapter::RepairMorphBinding(const MMDMaterialData& data, BaseMaterial* material,
	BaseObject* model, BaseObject* mesh, String& diagnostic)
{
	using namespace mmd_material_binding;
	if (!GeIsMainThread() || !material || !IsOwner(material, model, material->GetDocument())) return false;
	Material* mat = static_cast<Material*>(material);
	BaseDocument* doc = mat->GetDocument();
	BaseContainer metadata = Metadata(material);
	ReflectionLayer* layer = mat->GetReflectionLayerID(metadata.GetInt32(Layer));
	BaseShader* shaders[4] = {};
	BaseShader* bitmaps[4] = {};
	Bool allocated[4] = {};
	const TextureInfo texture = DetectTextureFromData(data);
	// A missing connection can be restored, but an occupied artist channel is
	// never replaced. The separate-material command is the explicit alternative.
	for (Int32 field = 0; field < 4; ++field)
	{
		shaders[field] = static_cast<BaseShader*>(metadata.GetLink(DiffuseShader + field, doc, g_mmd_material_texture_morph_shader_id));
		if (field < 2 || layer)
		{
			const Int32 parameter = field == 0 ? MATERIAL_COLOR_SHADER : field == 1 ? MATERIAL_ALPHA_SHADER
				: layer->GetDataID() + (field == 2 ? REFLECTION_LAYER_COLOR_TEXTURE : REFLECTION_LAYER_MAIN_SHADER_ROUGHNESS);
			BaseShader* current = GetMaterialShader(mat, doc, parameter);
			if (current && current != shaders[field])
			{ diagnostic = "Channel contains another shader; create an independent material"_s; return false; }
		}
	}
	for (Int32 field = 0; field < 4; ++field)
	{
		if (shaders[field]) continue;
		shaders[field] = BaseShader::Alloc(g_mmd_material_texture_morph_shader_id);
		allocated[field] = true;
		if (!shaders[field])
		{
			for (Int32 i = 0; i < 4; ++i) if (allocated[i] && shaders[i]) BaseShader::Free(shaders[i]);
			return false;
		}
	}
	for (Int32 field = 0; field < 2; ++field)
	{
		const Bool needs_bitmap = field == 0 ? texture.has_texture : texture.has_alpha;
		if (!needs_bitmap || shaders[field]->GetDown()) continue;
		bitmaps[field] = BaseShader::Alloc(Xbitmap);
		if (!bitmaps[field])
		{
			for (Int32 i = 0; i < 4; ++i)
			{
				if (allocated[i]) BaseShader::Free(shaders[i]);
				if (bitmaps[i]) BaseShader::Free(bitmaps[i]);
			}
			return false;
		}
		bitmaps[field]->SetParameter(ConstDescID(DescLevel(BITMAPSHADER_FILENAME)), Filename(data.texture_path), DESCFLAGS_SET::NONE);
	}
	if (!layer) layer = mat->AddReflectionLayer();
	if (!layer)
	{
		for (Int32 i = 0; i < 4; ++i)
		{
			if (allocated[i]) BaseShader::Free(shaders[i]);
			if (bitmaps[i]) BaseShader::Free(bitmaps[i]);
		}
		return false;
	}
	layer->SetName("MMD Morph Specular"_s);
	metadata.SetInt32(Layer, layer->GetLayerID());
	metadata.SetBool(Texture, texture.has_texture);
	metadata.SetInt32(Version, CurrentVersion);
	for (Int32 field = 0; field < 4; ++field)
	{
		BaseShader* shader = shaders[field];
		if (allocated[field]) mat->InsertShader(shader);
		if (bitmaps[field]) bitmaps[field]->InsertUnder(shader);
		BaseContainer* binding = shader->GetDataInstance();
		binding->SetInt32(MMDMATERIALMORPHSHADER_OUTPUT, field == 0 ? (texture.has_texture ? 3 : 1) : field == 1 ? (texture.has_alpha ? 4 : 2) : field == 2 ? 1 : 2);
		binding->SetInt32(MMDMATERIALMORPHSHADER_FIELD, field);
		binding->SetLink(MMDMATERIALMORPHSHADER_MODEL, model);
		binding->SetLink(MMDMATERIALMORPHSHADER_MATERIAL, material);
		binding->SetBool(MMDMATERIALMORPHSHADER_TEXTURED, texture.has_texture);
		const Int32 parameter = field == 0 ? MATERIAL_COLOR_SHADER : field == 1 ? MATERIAL_ALPHA_SHADER
			: layer->GetDataID() + (field == 2 ? REFLECTION_LAYER_COLOR_TEXTURE : REFLECTION_LAYER_MAIN_SHADER_ROUGHNESS);
		mat->SetParameter(CreateDescID(DescLevel(parameter)), shader, DESCFLAGS_SET::NONE);
		metadata.SetLink(DiffuseShader + field, shader);
		metadata.SetLink(ChildShaderFirst + field, shader->GetDown());
		metadata.SetInt32(OutputModeFirst + field, binding->GetInt32(MMDMATERIALMORPHSHADER_OUTPUT));
	}
	const Int32 id = layer->GetDataID();
	mat->SetParameter(CreateDescID(DescLevel(id + REFLECTION_LAYER_MAIN_DISTRIBUTION)), REFLECTION_DISTRIBUTION_GGX, DESCFLAGS_SET::NONE);
	mat->SetParameter(CreateDescID(DescLevel(id + REFLECTION_LAYER_MAIN_VALUE_REFLECTION)), 0.0, DESCFLAGS_SET::NONE);
	mat->SetParameter(CreateDescID(DescLevel(id + REFLECTION_LAYER_MAIN_VALUE_SPECULAR)), 1.0, DESCFLAGS_SET::NONE);
	mat->SetParameter(CreateDescID(DescLevel(id + REFLECTION_LAYER_MAIN_VALUE_ROUGHNESS)), 1.0, DESCFLAGS_SET::NONE);
	mat->SetParameter(CreateDescID(DescLevel(id + REFLECTION_LAYER_COLOR_COLOR)), Vector(1.0), DESCFLAGS_SET::NONE);
	mat->SetParameter(CreateDescID(DescLevel(id + REFLECTION_LAYER_COLOR_MIX_STRENGTH)), 1.0, DESCFLAGS_SET::NONE);
	mat->GetDataInstance()->SetContainer(g_mmd_material_texture_morph_shader_id, metadata);
	diagnostic = "Material binding repaired"_s;
	return ValidateMorphBinding(material, diagnostic);
}

Bool MMDStandardMaterialAdapter::UpdateMorphTexture(const MMDMaterialData& previous,
	const String& path, BaseMaterial* material, String& diagnostic)
{
	using namespace mmd_material_binding;
	if (!GeIsMainThread() || !ValidateMorphBinding(material, diagnostic)) return false;
	MMDMaterialData candidate;
	candidate.texture_path = path;
	const TextureInfo texture = DetectTextureFromData(candidate);
	if (path.IsPopulated() && !texture.has_texture)
	{ diagnostic = "Texture file does not exist; the current binding was preserved"_s; return false; }
	BaseContainer metadata = Metadata(material);
	BaseShader* outputs[2] = {};
	BaseShader* bitmaps[2] = {};
	Bool allocated[2] = {};
	const String installed_path = metadata.GetString(TexturePath, previous.texture_path);
	// Validate all retained children before allocating or changing either channel.
	for (Int32 field = 0; field < 2; ++field)
	{
		outputs[field] = static_cast<BaseShader*>(metadata.GetLink(DiffuseShader + field, material->GetDocument()));
		BaseShader* child = outputs[field]->GetDown();
		if (child && child->IsInstanceOf(Xbitmap))
		{
			GeData filename;
			child->GetParameter(ConstDescID(DescLevel(BITMAPSHADER_FILENAME)), filename, DESCFLAGS_GET::NONE);
			if (filename.GetFilename().GetString() != installed_path)
			{ diagnostic = "Bitmap path was edited directly; create an independent material"_s; return false; }
			bitmaps[field] = child;
		}
		else if (child && !child->IsInstanceOf(Xcolor))
		{ diagnostic = "Texture child contains an artist shader; create an independent material"_s; return false; }
	}
	for (Int32 field = 0; field < 2; ++field)
	{
		const Bool needed = field == 0 ? texture.has_texture : texture.has_alpha;
		if (!needed || bitmaps[field]) continue;
		bitmaps[field] = BaseShader::Alloc(Xbitmap);
		allocated[field] = true;
		if (!bitmaps[field])
		{
			for (Int32 i = 0; i < 2; ++i) if (allocated[i] && bitmaps[i]) BaseShader::Free(bitmaps[i]);
			diagnostic = "Could not allocate texture shaders"_s;
			return false;
		}
	}
	for (Int32 field = 0; field < 2; ++field)
	{
		// Reuse existing bitmaps, including their filtering/UV settings. Retain
		// the original plain-color child as an inactive sibling when adding one.
		if (allocated[field]) bitmaps[field]->InsertUnder(outputs[field]);
		if (texture.has_texture && bitmaps[field])
			bitmaps[field]->SetParameter(ConstDescID(DescLevel(BITMAPSHADER_FILENAME)), Filename(path), DESCFLAGS_SET::NONE);
		const Int32 mode = field == 0 ? (texture.has_texture ? 3 : 1) : (texture.has_alpha ? 4 : 2);
		outputs[field]->GetDataInstance()->SetInt32(MMDMATERIALMORPHSHADER_OUTPUT, mode);
		metadata.SetInt32(OutputModeFirst + field, mode);
		metadata.SetLink(ChildShaderFirst + field, outputs[field]->GetDown());
	}
	// All four outputs carry the same texture-presence contract, even though
	// only diffuse and opacity use texture factors.
	for (Int32 field = 0; field < 4; ++field)
	{
		auto* shader = static_cast<BaseShader*>(metadata.GetLink(DiffuseShader + field, material->GetDocument()));
		shader->GetDataInstance()->SetBool(MMDMATERIALMORPHSHADER_TEXTURED, texture.has_texture);
	}
	metadata.SetBool(Texture, texture.has_texture);
	metadata.SetString(TexturePath, texture.has_texture ? path : installed_path);
	material->GetDataInstance()->SetContainer(g_mmd_material_texture_morph_shader_id, metadata);
	diagnostic = "Material texture updated"_s;
	return true;
}

Bool MMDStandardMaterialAdapter::UpdateSphereTexture(const MMDMaterialData& previous,
	const String& path, const Int32 mode, BaseMaterial* material, String& diagnostic)
{
	using namespace mmd_material_binding;
	if (!GeIsMainThread() || mode < 0 || mode > 3 || !ValidateMorphBinding(material, diagnostic)) return false;
	BaseContainer metadata = Metadata(material);
	if (metadata.GetInt32(StandardMatcapRevision) != 1)
	{ diagnostic = "Legacy Environment Sphere requires an independent material conversion"_s; return false; }
	if (path.IsPopulated())
	{
		AutoAlloc<BaseBitmap> bitmap;
		if (!bitmap || bitmap->Init(Filename(path)) != IMAGERESULT::OK)
		{ diagnostic = "Sphere texture cannot be decoded; Standard binding was preserved"_s; return false; }
	}
	auto* output = static_cast<BaseShader*>(metadata.GetLink(DiffuseShader, material->GetDocument()));
	auto* sphere = static_cast<BaseShader*>(output->GetDataInstance()->GetLink(
		MMDMATERIALMORPHSHADER_SPHERE_SHADER, material->GetDocument(), Xbitmap));
	const Bool active = path.IsPopulated() && (mode == 1 || mode == 2);
	if (!sphere->SetParameter(ConstDescID(DescLevel(BITMAPSHADER_FILENAME)), Filename(path), DESCFLAGS_SET::NONE)) return false;
	output->GetDataInstance()->SetInt32(MMDMATERIALMORPHSHADER_SPHERE_MODE, active ? mode : 0);
	metadata.SetString(SphereTexturePath, path);
	metadata.SetInt32(SphereMode, mode);
	metadata.SetBool(SphereHasTexture, active);
	metadata.SetString(ProfileDiagnostic, mode == 3 ? "Sphere SubTexture (Additional UV) is not mapped"_s : "Matcap Sphere Multiply/Add supported"_s);
	material->GetDataInstance()->SetContainer(g_mmd_material_texture_morph_shader_id, metadata);
	material->SetDirty(DIRTYFLAGS::DATA);
	material->Message(MSG_UPDATE);
	diagnostic = metadata.GetString(ProfileDiagnostic);
	return true;
}

void MMDStandardMaterialAdapter::SyncTo(const MMDMaterialData& data, BaseMaterial* material)
{
	if (!material || !material->IsInstanceOf(Mmaterial))
		return;
	if (mmd_material_binding::IsBound(material))
	{
		String diagnostic;
		if (!GeIsMainThread() || !ValidateMorphBinding(material, diagnostic)) return;
		// Bound shaders read the current base plus Morph snapshot in InitRender.
		// Keep the channel multipliers neutral; writing the tint there as well
		// would apply it twice. Only authoring metadata needs an explicit write.
		material->SetName(data.name_local);
		material->SetDirty(DIRTYFLAGS::DATA);
		material->Message(MSG_UPDATE);
		return;
	}
	Material* mat = static_cast<Material*>(material);
	mat->SetName(data.name_local);
	BaseDocument* doc = mat->GetDocument();
	MigrateLegacyToonLuminance(mat, doc, data.toon_texture_path);
	// SyncTo is also used by explicit material editing without a material morph.
	// Updating an existing wrapper replaces its factor instead of nesting wrappers.
	BaseShader* const color_output = GetMaterialShader(mat, doc, MATERIAL_COLOR_SHADER);
	BaseShader* const primary = color_output && color_output->IsInstanceOf(g_mmd_material_texture_morph_shader_id)
		? color_output->GetDown() : nullptr;
	const Bool plain_matcap = mmd_material_binding::Metadata(mat).GetInt32(mmd_material_binding::StandardMatcapRevision) == 1
		&& primary && primary->IsInstanceOf(Xcolor);
	if (plain_matcap)
	{
		// The original Xcolor already carries Diffuse. Applying that value to
		// the Matcap wrapper too would square the plain material's tint.
		SetTextureMorphShaderFactor(color_output, Vector(1.0), 1.0);
		primary->SetParameter(ConstDescID(DescLevel(COLORSHADER_COLOR)), data.diffuse_rgb, DESCFLAGS_SET::NONE);
	}
	else
		SyncTextureMorphChannel(mat, doc, CHANNEL_COLOR, MATERIAL_COLOR_SHADER, data.diffuse_rgb, 1.0);
	SyncTextureMorphChannel(mat, doc, CHANNEL_ALPHA, MATERIAL_ALPHA_SHADER, Vector(1.0), data.diffuse_alpha);
	BaseChannel* color_ch = mat->GetChannel(CHANNEL_COLOR);
	if (color_ch)
	{
		BaseContainer bc = color_ch->GetData();
		if (bc.GetString(BASECHANNEL_TEXTURE).IsEmpty())
		{
			GeData gd;
			if (GetAtomParameter(mat, ConstDescID(DescLevel(MATERIAL_COLOR_SHADER)), gd, DESCFLAGS_GET::NONE))
			{
				BaseShader* sh = static_cast<BaseShader*>(gd.GetLink(doc));
				if (sh && sh->IsInstanceOf(Xcolor))
					sh->SetParameter(ConstDescID(DescLevel(COLORSHADER_COLOR)), data.diffuse_rgb, DESCFLAGS_SET::NONE);
			}
		}
	}
	BaseChannel* alpha_ch = mat->GetChannel(CHANNEL_ALPHA);
	if (alpha_ch)
	{
		BaseContainer ac = alpha_ch->GetData();
		if (ac.GetString(BASECHANNEL_TEXTURE).IsEmpty())
		{
			GeData gd;
			if (GetAtomParameter(mat, ConstDescID(DescLevel(MATERIAL_ALPHA_SHADER)), gd, DESCFLAGS_GET::NONE))
			{
				BaseShader* ash = static_cast<BaseShader*>(gd.GetLink(doc));
				if (ash && ash->IsInstanceOf(Xcolor))
					ash->SetParameter(ConstDescID(DescLevel(COLORSHADER_BRIGHTNESS)), data.diffuse_alpha, DESCFLAGS_SET::NONE);
			}
		}
	}
	mat->SetChannelState(CHANNEL_SPECULAR, true);
	mat->SetParameter(ConstDescID(DescLevel(MATERIAL_SPECULAR_COLOR)), data.specular, DESCFLAGS_SET::NONE);
	Float specular_width = maxon::Clamp01(data.specular_power / 100.0);
	mat->SetParameter(ConstDescID(DescLevel(MATERIAL_SPECULAR_WIDTH)), specular_width, DESCFLAGS_SET::NONE);

	const Bool has_sphere = mmd_material_binding::Metadata(mat).GetInt32(mmd_material_binding::StandardMatcapRevision) == 0
		&& HasStandardSphereApproximation(data.sphere_mode, data.sphere_texture_path);
	mat->SetChannelState(CHANNEL_ENVIRONMENT, has_sphere);
	if (has_sphere)
	{
		mat->SetParameter(ConstDescID(DescLevel(MATERIAL_ENVIRONMENT_COLOR)), data.ambient, DESCFLAGS_SET::NONE);
		SetChannelTextureIfUnwrapped(mat, doc, CHANNEL_ENVIRONMENT, MATERIAL_ENVIRONMENT_SHADER, data.sphere_texture_path);
	}
}

void MMDStandardMaterialAdapter::ReadFrom(const BaseMaterial* material, MMDMaterialData& data)
{
	// Managed outputs do not have independent base values to reverse-sync.
	if (mmd_material_binding::IsBound(material)) return;
	if (!material || !material->IsInstanceOf(Mmaterial))
		return;
	Material* mat = const_cast<Material*>(static_cast<const Material*>(material));
	data.name_local = mat->GetName();
	BaseDocument* doc = mat->GetDocument();
	BaseChannel* color_ch = mat->GetChannel(CHANNEL_COLOR);
	if (color_ch)
	{
		BaseContainer bc = color_ch->GetData();
		String tex_path = bc.GetString(BASECHANNEL_TEXTURE);
		if (tex_path.IsPopulated())
		{
			data.texture_path = tex_path;
		}
		else
		{
			GeData gd;
			if (GetAtomParameter(mat, ConstDescID(DescLevel(MATERIAL_COLOR_SHADER)), gd, DESCFLAGS_GET::NONE))
			{
				BaseShader* sh = static_cast<BaseShader*>(gd.GetLink(doc));
				if (sh && sh->IsInstanceOf(Xcolor))
				{
					GeData color_data;
					if (GetAtomParameter(sh, ConstDescID(DescLevel(COLORSHADER_COLOR)), color_data, DESCFLAGS_GET::NONE))
						data.diffuse_rgb = color_data.GetVector();
				}
			}
		}
	}
	BaseChannel* alpha_ch = mat->GetChannel(CHANNEL_ALPHA);
	if (alpha_ch)
	{
		BaseContainer ac = alpha_ch->GetData();
		if (ac.GetString(BASECHANNEL_TEXTURE).IsEmpty())
		{
			GeData gd;
			if (GetAtomParameter(mat, ConstDescID(DescLevel(MATERIAL_ALPHA_SHADER)), gd, DESCFLAGS_GET::NONE))
			{
				BaseShader* ash = static_cast<BaseShader*>(gd.GetLink(doc));
				if (ash && ash->IsInstanceOf(Xcolor))
				{
					GeData brightness_data;
					if (GetAtomParameter(ash, ConstDescID(DescLevel(COLORSHADER_BRIGHTNESS)), brightness_data, DESCFLAGS_GET::NONE))
						data.diffuse_alpha = brightness_data.GetFloat();
				}
			}
		}
	}
	GeData spec_color;
	if (GetAtomParameter(mat, ConstDescID(DescLevel(MATERIAL_SPECULAR_COLOR)), spec_color, DESCFLAGS_GET::NONE))
		data.specular = spec_color.GetVector();
	GeData spec_width;
	if (GetAtomParameter(mat, ConstDescID(DescLevel(MATERIAL_SPECULAR_WIDTH)), spec_width, DESCFLAGS_GET::NONE))
		data.specular_power = spec_width.GetFloat() * 100.0;
	GeData amb_color;
	if (GetAtomParameter(mat, ConstDescID(DescLevel(MATERIAL_ENVIRONMENT_COLOR)), amb_color, DESCFLAGS_GET::NONE))
		data.ambient = amb_color.GetVector();
}

void MMDStandardMaterialAdapter::SyncRuntimeState(const MMDMaterialRuntimeState& state, BaseMaterial* material)
{
	if (mmd_material_binding::IsBound(material)) return;
	if (!material || !material->IsInstanceOf(Mmaterial))
		return;
	Material* const mat = static_cast<Material*>(material);
	BaseDocument* const doc = mat->GetDocument();

	// PMX textured materials are shaded by both the effective diffuse value and
	// the effective texture factor. Pure Xcolor channels are handled by SyncTo().
	SyncTextureMorphChannel(mat, doc, CHANNEL_COLOR, MATERIAL_COLOR_SHADER,
		ComponentMultiply(state.diffuse_rgb, state.texture.LegacyColor()), 1.0);
	SyncTextureMorphChannel(mat, doc, CHANNEL_ALPHA, MATERIAL_ALPHA_SHADER,
		Vector(1.0), state.diffuse_alpha * state.texture.LegacyAlpha());
	BaseShader* const color_shader = GetMaterialShader(mat, doc, MATERIAL_COLOR_SHADER);
	BaseShader* const alpha_shader = GetMaterialShader(mat, doc, MATERIAL_ALPHA_SHADER);
	BaseShader* const color_bitmap = color_shader && color_shader->IsInstanceOf(g_mmd_material_texture_morph_shader_id)
		? color_shader->GetDown() : color_shader;
	// An opaque image still has a texture factor. Its constant white alpha
	// channel has no bitmap wrapper, so apply the complete alpha coefficient
	// directly. A genuinely untextured Xcolor material keeps texture factors out.
	if (color_bitmap && color_bitmap->IsInstanceOf(Xbitmap)
		&& alpha_shader && alpha_shader->IsInstanceOf(Xcolor))
	{
		alpha_shader->SetParameter(ConstDescID(DescLevel(COLORSHADER_BRIGHTNESS)),
			state.diffuse_alpha * state.texture.LegacyAlpha(), DESCFLAGS_SET::NONE);
	}
	if (mat->GetChannelState(CHANNEL_ENVIRONMENT))
		SyncTextureMorphChannel(mat, doc, CHANNEL_ENVIRONMENT, MATERIAL_ENVIRONMENT_SHADER,
			state.sphere_texture.LegacyColor(), state.sphere_texture.LegacyAlpha());
	// Toon factors remain in the PMX/runtime data. Applying them to an artist's
	// Luminance channel would reintroduce the old toon-as-emission approximation.
}
