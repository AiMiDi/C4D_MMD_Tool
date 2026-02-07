#pragma once

#include <c4d.h>
#include <vector>
#include "module/core/cmt_marco.h"
#include "libMMD/Model/MMD/PMXFile.h"

namespace CMTToolsSetting
{
	struct ModelImport;
}

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
	BaseMaterial* LoadPMXMaterial(const libmmd::PMXMaterial& pmx_material,
	                              const uint64_t material_index, const maxon::String& material_name, const CMTToolsSetting::ModelImport& setting);
private:

};
