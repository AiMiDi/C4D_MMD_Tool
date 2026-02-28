#pragma once

#include <c4d.h>
#include "module/tools/material/mmd_material.h"

BaseMaterial* CreateOctaneMaterialFromPMX(const libmmd::PMXMaterial& pmx_material,
	const maxon::BaseArray<Filename>& texture_paths, const maxon::String& material_name);

BaseMaterial* CreateOctaneMaterialFromData(const MMDMaterialData& data);

void SyncToOctaneMaterial(const MMDMaterialData& data, BaseMaterial* material);

void ReadFromOctaneMaterial(const BaseMaterial* material, MMDMaterialData& data);
