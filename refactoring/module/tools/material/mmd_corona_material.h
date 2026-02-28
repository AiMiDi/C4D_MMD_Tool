#pragma once

#include <c4d.h>
#include "module/tools/material/mmd_material.h"

BaseMaterial* CreateCoronaMaterialFromPMX(const libmmd::PMXMaterial& pmx_material,
	const maxon::BaseArray<Filename>& texture_paths, const maxon::String& material_name);

BaseMaterial* CreateCoronaMaterialFromData(const MMDMaterialData& data);

void SyncToCoronaMaterial(const MMDMaterialData& data, BaseMaterial* material);

void ReadFromCoronaMaterial(const BaseMaterial* material, MMDMaterialData& data);
