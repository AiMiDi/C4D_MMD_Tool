#pragma once

#include "module/tools/material/mmd_material.h"

/**
 * Redshift node 材质适配器：Texture Sampler 应用完整 diffuse RGBA，
 * Color Splitter 的 A 输出用于 opacity；运行时只更新本 adapter 创建的节点。
 * 普通材质创建/同步也应用高光颜色与 Power→Roughness；无连接的输入可反向读取。
 * 普通 Sphere Multiply/Add 使用相机法线 Matcap，在 PBR Base Color 前组合。
 * Sphere RGBA Morph 使用独立绑定；Toon、Ambient、edge 仍保留 PMX 元数据。
 * SubTexture/Additional UV 未映射，不宣称完整 MMD 渲染。
 */
class MMDRedShiftMaterialAdapter final : public MMDMaterialAdapter
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
private:
	Bool BuildMorphBinding(const MMDMaterialData& data, BaseMaterial* material,
		BaseObject* model, BaseObject* mesh, Bool repair, String& diagnostic);
};
