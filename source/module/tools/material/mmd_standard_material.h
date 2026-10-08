#pragma once

#include "module/tools/material/mmd_material.h"

/**
 * 标准材质近似：基础纹理使用 Color/Alpha，创建即应用 PMX diffuse RGBA。
 * 同一贴图系数 wrapper 接收运行时完整有效系数，避免基础值和表情重复相乘。
 * 新建材质的 Sphere Multiply/Add 通过颜色 Shader 的相机法线 Matcap 组合。
 * None/SubTexture 绕过 Sphere；SubTexture 的 additional UV1 数据只保留。
 * 旧 Environment 近似场景不自动升级，新建独立材质使用新配方。
 * PMX toon 阴影 ramp 仅保留在模型材质元数据中，不转换为自发光。
 * SyncTo 对旧导入器生成且未被编辑的 toon 自发光执行一次保守迁移。
 */
class MMDStandardMaterialAdapter final : public MMDMaterialAdapter
{
public:
	BaseMaterial* CreateFromPMX(const libmmd::PMXMaterial& pmx_material,
		const maxon::BaseArray<Filename>& texture_paths, const maxon::String& material_name) override;
	BaseMaterial* CreateFromData(const MMDMaterialData& data) override;
	void SyncTo(const MMDMaterialData& data, BaseMaterial* material) override;
	void ReadFrom(const BaseMaterial* material, MMDMaterialData& data) override;
	void SyncRuntimeState(const MMDMaterialRuntimeState& state, BaseMaterial* material) override;
	Bool PrepareMorphBinding(const MMDMaterialData& data, BaseMaterial* material,
		BaseObject* model, BaseObject* mesh, String& diagnostic) override;
	Bool ValidateMorphBinding(BaseMaterial* material, String& diagnostic) const override;
	Bool RepairMorphBinding(const MMDMaterialData& data, BaseMaterial* material,
		BaseObject* model, BaseObject* mesh, String& diagnostic) override;
	Bool UpdateMorphTexture(const MMDMaterialData& previous, const String& path,
		BaseMaterial* material, String& diagnostic) override;
	Bool UpdateSphereTexture(const MMDMaterialData& previous, const String& path, Int32 mode,
		BaseMaterial* material, String& diagnostic) override;
};

