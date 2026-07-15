#pragma once

#include <memory>
#include "libMMD/Model/MMD/PMXFile.h"
#include <c4d.h>
#include "module/core/cmt_marco.h"

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
	maxon::StrongRef<AutoAlloc<BaseLink>> mesh_link;
	String selection_name;

	void FromPMX(const libmmd::PMXMaterial& pmx_material);
	void ToPMX(libmmd::PMXMaterial& pmx_material, Int32 texture_index = -1, Int32 sphere_texture_index = -1,
	           Int32 resolved_toon_texture_index = -1) const;
	Bool Read(HyperFile* hf);
	Bool Write(HyperFile* hf) const;
	Bool CopyTo(MMDMaterialData& dest) const;
};

/**
 * @brief 材质表情运行时合成状态。
 *
 * 由基础 `MMDMaterialData` 加上所有激活 material morph 的有效贡献合成而来。
 * 每帧从基础值重新计算，不回写基础数据，避免强度累积漂移。
 * texture/sphere/toon factor 以 1.0 为基准（无表情时不改变贴图采样），供后续 shader 应用使用。
 */
struct MMDMaterialRuntimeState
{
	Vector diffuse_rgb = Vector(0.0);
	Float diffuse_alpha = 1.0;
	Vector specular = Vector(0.0);
	Float specular_power = 0.0;
	Vector ambient = Vector(0.0);
	Vector edge_color_rgb = Vector(0.0);
	Float edge_color_alpha = 1.0;
	Float edge_size = 0.0;
	Vector texture_factor_rgb = Vector(1.0);
	Float texture_factor_alpha = 1.0;
	Vector sphere_texture_factor_rgb = Vector(1.0);
	Float sphere_texture_factor_alpha = 1.0;
	Vector toon_texture_factor_rgb = Vector(1.0);
	Float toon_texture_factor_alpha = 1.0;

	/** 从基础材质数据初始化运行时状态（factor 字段保持 1.0 基准）。 */
	static MMDMaterialRuntimeState FromBase(const MMDMaterialData& base);

	/** 将当前材质系统已承载的字段（diffuse/alpha/specular/power/ambient/edge）写入 MMDMaterialData 副本。 */
	void WriteSupportedFieldsTo(MMDMaterialData& data) const;

	/** 计算用于 dirty 判定的校验和；有效状态不变时跳过 C4D 材质同步。 */
	UInt64 Checksum() const;
};

enum class MMDRendererMaterialType { Unknown, Standard, RedShift, Octane, Corona };

/** MMD 材质适配器基类：统一各渲染器材质的创建、同步、读取接口。 */
class MMDMaterialAdapter
{
public:
	virtual ~MMDMaterialAdapter() = default;

	virtual BaseMaterial* CreateFromPMX(const libmmd::PMXMaterial& pmx_material,
		const maxon::BaseArray<Filename>& texture_paths, const maxon::String& material_name) = 0;
	virtual BaseMaterial* CreateFromData(const MMDMaterialData& data) = 0;
	virtual void SyncTo(const MMDMaterialData& data, BaseMaterial* material) = 0;
	virtual void ReadFrom(const BaseMaterial* material, MMDMaterialData& data) = 0;

	/**
	 * @brief 将材质表情运行时状态中无法由 SyncTo 表达的部分（贴图系数 wrapper shader）同步到 C4D 材质。
	 *
	 * 默认无操作；Standard adapter 覆盖以按需安装/更新贴图系数 wrapper shader。
	 * 简单颜色/浮点字段仍走 SyncTo 路径。
	 */
	virtual void SyncRuntimeState(const MMDMaterialRuntimeState& state, BaseMaterial* material) {}

	static std::unique_ptr<MMDMaterialAdapter> Create(MMDRendererMaterialType type);
	static std::unique_ptr<MMDMaterialAdapter> CreateFor(const BaseMaterial* material);
	static MMDRendererMaterialType DetectType(const BaseMaterial* material);

protected:
	struct TextureInfo
	{
		bool has_texture = false;
		bool has_alpha = false;
	};
	static TextureInfo DetectTextureFromPMX(
		const libmmd::PMXMaterial& pmx_material, const maxon::BaseArray<Filename>& texture_paths);
	static TextureInfo DetectTextureFromData(const MMDMaterialData& data);
};

/** 便捷封装：根据材质类型自动分发，将 MMD 数据同步到 C4D 材质。 */
void SyncToMaterial(const MMDMaterialData& data, BaseMaterial* material);

/** 便捷封装：根据材质类型自动分发，从 C4D 材质反向读取属性到 MMD 数据。 */
void ReadFromMaterial(const BaseMaterial* material, MMDMaterialData& data);

/** 便捷封装：根据渲染器类型创建 C4D 材质。 */
BaseMaterial* CreateMaterialFromData(const MMDMaterialData& data, MMDRendererMaterialType type);

/** 便捷封装：根据材质类型自动分发，将材质表情运行时状态（贴图系数等）同步到 C4D 材质。 */
void SyncRuntimeStateToMaterial(const MMDMaterialRuntimeState& state, BaseMaterial* material);

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
