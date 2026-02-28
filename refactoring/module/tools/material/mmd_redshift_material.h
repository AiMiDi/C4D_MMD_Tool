#pragma once

#include <c4d.h>
#include "module/tools/material/mmd_material.h"

BaseMaterial* CreateRedShiftMaterialFromPMX(const libmmd::PMXMaterial& pmx_material,
	const maxon::BaseArray<Filename>& texture_paths, const maxon::String& material_name);

BaseMaterial* CreateRedShiftMaterialFromData(const MMDMaterialData& data);

void SyncToRedShiftMaterial(const MMDMaterialData& data, BaseMaterial* material);

void ReadFromRedShiftMaterial(const BaseMaterial* material, MMDMaterialData& data);
