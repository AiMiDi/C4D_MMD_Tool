#pragma once

#include <c4d.h>
#include "module/core/cmt_marco.h"
#include "libMMD/Model/MMD/PMXFile.h"

namespace CMTToolsSetting
{
	struct ModelImport;
}

/** PMX 材质数据：完整字段 + 关联的 C4D 材质链接，用于持久化与 UI 编辑。 */
struct MMDMaterialData
{
	String name_local;
	String name_universal;
	Vector diffuse_rgb;
	Float diffuse_alpha = 1.f;
	Vector specular;
	Float specular_power = 0.f;
	Vector ambient;
	Bool draw_both_face = false;
	Bool draw_ground_shadow = false;
	Bool draw_cast_self_shadow = false;
	Bool draw_receive_self_shadow = false;
	Bool draw_vertex_color = false;
	Bool edge_enabled = false;
	Vector edge_color_rgb;
	Float edge_color_alpha = 1.f;
	Float edge_size = 0.f;
	String texture_path;
	String sphere_texture_path;
	Int32 sphere_mode = 0; // 0=无效 1=乘算 2=加算 3=子纹理
	Int32 toon_mode = 0;   // 0=独立 1=共用
	Int32 toon_texture_index = -1;
	String toon_texture_path;
	String memo;
	Int32 num_face_vertices = 0;
	maxon::StrongRef<AutoAlloc<BaseLink>> material_link;

	void FromPMX(const libmmd::PMXMaterial& pmx_material);
	void ToPMX(libmmd::PMXMaterial& pmx_material) const;
	Bool Read(HyperFile* hf);
	Bool Write(HyperFile* hf) const;
	Bool CopyTo(MMDMaterialData& dest) const;
};

/** 导入时辅助：纹理路径解析与 PMX 材质转 C4D 材质（标准材质逻辑见 mmd_standard_material）。 */
class MMDMaterialManager final
{
	Filename m_texture_relative_path{};
	maxon::BaseArray<Filename> m_texture_path_array;

	CMT_DISALLOW_COPY_AND_ASSIGN_BODY(MMDMaterialManager)
	CMT_DEFAULT_MOVE_BODY(MMDMaterialManager)
public:
	MMDMaterialManager() = default;
	~MMDMaterialManager() = default;

	void SetTextureRelativePath(const Filename& texture_relative_path);
	Bool LoadPMXTextures(const std::vector<libmmd::PMXTexture>& pmx_textures);
	const maxon::BaseArray<Filename>& GetTexturePaths() const { return m_texture_path_array; }
	BaseMaterial* LoadPMXMaterial(const libmmd::PMXMaterial& pmx_material,
	                             const uint64_t material_index, const maxon::String& material_name, const CMTToolsSetting::ModelImport& setting);
};
