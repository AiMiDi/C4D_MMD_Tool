#pragma once

#include <c4d.h>
#include "module/tools/material/mmd_material.h"

/** 从 PMX 材质与纹理路径列表创建 C4D 标准材质（仅 Standard 类型）。 */
BaseMaterial* CreateStandardMaterialFromPMX(const libmmd::PMXMaterial& pmx_material,
	const maxon::BaseArray<Filename>& texture_paths, const maxon::String& material_name);

/** 从 MMDMaterialData 创建 C4D 标准材质（不含纹理，仅设置颜色属性）。 */
BaseMaterial* CreateStandardMaterialFromData(const MMDMaterialData& data);

/** 将 MMD 材质数据同步到 C4D 标准材质（颜色、Alpha、反射、名称）。 */
void SyncToStandardMaterial(const MMDMaterialData& data, BaseMaterial* material);
