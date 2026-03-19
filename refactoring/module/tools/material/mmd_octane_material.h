#pragma once

#include <c4d.h>
#include "module/tools/material/mmd_material.h"

/** Octane 材质适配器：使用基类共享的 DetectTextureFromPMX/DetectTextureFromData。 */
class MMDOctaneMaterialAdapter final : public MMDMaterialAdapter
{
public:
	BaseMaterial* CreateFromPMX(const libmmd::PMXMaterial& pmx_material,
		const maxon::BaseArray<Filename>& texture_paths, const maxon::String& material_name) override;
	BaseMaterial* CreateFromData(const MMDMaterialData& data) override;
	void SyncTo(const MMDMaterialData& data, BaseMaterial* material) override;
	void ReadFrom(const BaseMaterial* material, MMDMaterialData& data) override;
};
