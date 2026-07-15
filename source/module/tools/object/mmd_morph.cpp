#include "module/core/cmt_old_sdk_stl_preload.h"
#include "mmd_model_manager.h"
#include <c4d.h>
#include <c4d_symbols.h>
#include "module/core/cmt_marco.h"
#include "mmd_morph.h"
#include "mmd_mesh_manager.h"
#include "mmd_bone_manager.h"
#include "description/OMMDModelManager.h"

Bool IMorph::Read(HyperFile* hf, Int32 level)
{
	IOReadField(m_strength_id);
	IOReadField(m_name);
	return true;
}

Bool IMorph::Write(HyperFile* hf) SDK2024_Const
{
	IOWriteField(m_strength_id);
	IOWriteField(m_name);
	return true;
}

Bool IMorph::CopyTo(IMorph* dest) const
{
	dest->m_strength_id = m_strength_id;
	dest->m_name = m_name;
	return true;
}

Bool GroupMorph::Read(HyperFile* hf, Int32 level)
{
	if (!IMorph::Read(hf, level))
		return false;
	IOReadField(m_grp_id);
	IOReadField(m_button_grp_id);
	IOReadField(m_button_editor_id);
	IOReadField(m_button_delete_id);
	IOReadField(m_button_rename_id);
	m_data.Reset();
	if (!io_util::ReadHashMap(hf, m_data))
		return false;

	return true;
}

Bool GroupMorph::Write(HyperFile* hf) SDK2024_Const
{
	if (IMorph::Write(hf) == false)
		return false;
	IOWriteField(m_grp_id);
	IOWriteField(m_button_grp_id);
	IOWriteField(m_button_editor_id);
	IOWriteField(m_button_delete_id);
	IOWriteField(m_button_rename_id);
	if (!io_util::WriteHashMap(hf, m_data))
		return false;
	return true;
}

Bool GroupMorph::CopyTo(IMorph* dest) const
{
	if (IMorph::CopyTo(dest) == false)
		return false;
	for (auto& data : m_data)
	{
		iferr(dest->GetSubMorphDataWritable()->Insert(data.GetKey(), data.GetValue()))
			return false;
	}
	return true;
}

Bool FlipMorph::Read(HyperFile* hf, Int32 level)
{
	if (IMorph::Read(hf, level) == false)
		return false;
	IOReadField(m_grp_id);
	IOReadField(m_button_grp_id);
	IOReadField(m_button_editor_id);
	IOReadField(m_button_delete_id);
	IOReadField(m_button_rename_id);
	m_data.Reset();
	if (!io_util::ReadHashMap(hf, m_data))
		return false;
	return true;
}

Bool FlipMorph::Write(HyperFile* hf) SDK2024_Const
{
	if (IMorph::Write(hf) == false)
		return false;
	IOWriteField(m_grp_id);
	IOWriteField(m_button_grp_id);
	IOWriteField(m_button_editor_id);
	IOWriteField(m_button_delete_id);
	IOWriteField(m_button_rename_id);
	if (!io_util::WriteHashMap(hf, m_data))
		return false;
	return true;
}

Bool FlipMorph::CopyTo(IMorph* dest) const
{
	if (IMorph::CopyTo(dest) == false)
		return false;
	for (auto& data : m_data)
	{
		iferr(dest->GetSubMorphDataWritable()->Insert(data.GetKey(), data.GetValue()))
			return false;
	}
	return true;
}

MeshMorph::MeshMorph(String name, DescID strength_id): IMorph(std::move(name), std::move(strength_id))
{}

MeshMorph::MeshMorph(MeshMorph&& other) noexcept: IMorph(std::move(other))
{}

IMorph::IMorph(String name, DescID strength_id):
	m_name(std::move(name)), m_strength_id(std::move(strength_id))
{}

IMorph::IMorph(IMorph&& other) noexcept:
	m_name(std::move(other.m_name)),
	m_strength_id(std::move(other.m_strength_id))
{}

void IMorph::AddPanelUI(MMDModelManagerObject& model, Int morph_id, const DescID& parent_grp)
{
	if (m_panel <= 0)
		return;
	BaseContainer bc = GetCustomDataTypeDefault(DTYPE_LONG);
	bc.SetString(DESC_NAME, "panel"_s);
	bc.SetInt32(DESC_DEFAULT, m_panel);
	bc.SetInt32(DESC_ANIMATE, DESC_ANIMATE_OFF);
	BaseContainer cycle;
	cycle.SetString(1, "眉"_s);
	cycle.SetString(2, "目"_s);
	cycle.SetString(3, "口"_s);
	cycle.SetString(4, "其他"_s);
	bc.SetContainer(DESC_CYCLE, cycle);
	bc.SetData(DESC_PARENTGROUP, MakeDescIDGeData(parent_grp));
	m_panel_id = model.AddDynamicDescription(bc, MMDModelRootDynamicDescriptionType::MORPH_GRP, morph_id);
}

void IMorph::DeletePanelUI(MMDModelManagerObject& model)
{
	if (m_panel_id.GetDepth() > 0)
		model.DeleteDynamicDescription(m_panel_id);
}

Float IMorph::GetStrength(SDK2024_Const GeListNode* node) const
{
	GeData ge_data;
	if (!node->GetParameter(m_strength_id, ge_data, DESCFLAGS_GET::NONE))
	{
		return 0.0;
	}
	return ge_data.GetFloat();
}

Bool IMorph::SetStrength(GeListNode* node, const Float& strength) const
{
	return node->SetParameter(m_strength_id, strength, DESCFLAGS_SET::NONE);
}

DescID IMorph::GetStrengthDescID()
{
	return m_strength_id;
}

bool IMorph::operator==(const IMorph& other) const
{
	return m_name == other.m_name;
}

void IMorph::RenameMorph(const String& name)
{
	m_name = name;
}

void GroupMorph::RenameSubMorph(const Int old_id, const Int new_id)
{
	if (auto* data_ptr = m_data.Find(old_id); data_ptr)
	{
		iferr(m_data.Insert(new_id, data_ptr->GetValue()))
			return;
		std::ignore = m_data.Erase(data_ptr);
	}
}

void FlipMorph::RenameSubMorph(const Int old_id, const Int new_id)
{
	if (auto* data_ptr = m_data.Find(old_id); data_ptr)
	{
		iferr(m_data.Insert(new_id, data_ptr->GetValue()))
			return;
		std::ignore = m_data.Erase(data_ptr);
	}
}

GroupMorph::GroupMorph(String name, DescID grp_id, DescID strength_id, DescID button_grp_id, DescID button_editor_id,
	DescID button_delete_id, DescID button_rename_id):
	IMorph(std::move(name), std::move(strength_id)),
	m_grp_id(std::move(grp_id)),
	m_button_grp_id(std::move(button_grp_id)),
	m_button_editor_id(std::move(button_editor_id)),
	m_button_delete_id(std::move(button_delete_id)),
	m_button_rename_id(std::move(button_rename_id))
{}

GroupMorph::GroupMorph(GroupMorph&& other) noexcept:
	IMorph(std::move(other.m_name), std::move(other.m_strength_id)),
	m_grp_id(std::move(other.m_grp_id)),
	m_button_grp_id(std::move(other.m_button_grp_id)),
	m_button_delete_id(std::move(other.m_button_delete_id)),
	m_button_rename_id(std::move(other.m_button_rename_id)),
	m_data(std::move(other.m_data))
{}

void GroupMorph::UpdateMorph(MMDModelManagerObject& model)
{
	GeListNode* node = model.Get();
	auto& morph_arr = model.GetMorphData();
	const Float self = GetStrength(node);
	for (auto& data : m_data)
	{
		auto& morph = morph_arr[data.GetKey()];
		const Float base = morph.GetStrength(node);
		morph.SetStrength(node, base + self * data.GetValue());
	}
}

FlipMorph::FlipMorph(String name, DescID strength_id, DescID grp_id, DescID button_grp_id, DescID button_editor_id,
	DescID button_delete_id, DescID button_rename_id):
	IMorph(std::move(name), std::move(strength_id)),
	m_grp_id(std::move(grp_id)),
	m_button_grp_id(std::move(button_grp_id)),
	m_button_editor_id(std::move(button_editor_id)),
	m_button_delete_id(std::move(button_delete_id)),
	m_button_rename_id(std::move(button_rename_id))
{}

FlipMorph::FlipMorph(FlipMorph&& other) noexcept:
	IMorph(std::move(other.m_name), std::move(other.m_strength_id)),
	m_grp_id(std::move(other.m_grp_id)),
	m_button_grp_id(std::move(other.m_button_grp_id)),
	m_button_delete_id(std::move(other.m_button_delete_id)),
	m_button_rename_id(std::move(other.m_button_rename_id)),
	m_data(std::move(other.m_data))
{}

void FlipMorph::UpdateMorph(MMDModelManagerObject& model)
{
	GeListNode* node = model.Get();
	auto& morph_arr = model.GetMorphData();
	const Float add = GetStrength(node) >= 0.5 ? 1.0 : 0.0;
	for (auto& data : m_data)
	{
		auto& morph = morph_arr[data.GetKey()];
		const Float base = morph.GetStrength(node);
		morph.SetStrength(node, base + add * data.GetValue());
	}
}

void MeshMorph::UpdateMorph(MMDModelManagerObject& model)
{
	if (BaseObject* mesh_manager = model.GetMeshManagerObject())
	{
		mesh_manager->GetNodeData<MMDMeshManagerObject>()->SetMorphStrength(m_name, GetStrength(model.Get()));
	}

}

void BoneMorph::UpdateMorph(MMDModelManagerObject& model)
{
	if (BaseObject* bone_manager = model.GetBoneManagerObject())
	{
		auto& bone_morph_map = bone_manager->GetNodeData<MMDBoneManagerObject>()->GetBoneMorphMap();
		if (auto* entry = bone_morph_map.Find(m_name))
		{
			for (auto& hub : entry->GetValue())
			{
				hub.SetStrength(GetStrength(model.Get()));
			}
		}
	}
}

void GroupMorph::AddMorphUI(MMDModelManagerObject& model, Int morph_id)
{
	BaseContainer bc = GetCustomDataTypeDefault(DTYPE_GROUP);
	bc.SetString(DESC_NAME, m_name);
	bc.SetData(DESC_PARENTGROUP, MakeDescIDGeData(ConstDescID(DescLevel(MODEL_MORPH_GROUP_GRP))));
	m_grp_id = model.AddDynamicDescription(bc, MMDModelRootDynamicDescriptionType::MORPH_GRP, morph_id);
	bc = GetCustomDataTypeDefault(DTYPE_REAL);
	bc.SetString(DESC_NAME, m_name);
	bc.SetFloat(DESC_MAX, 1.);
	bc.SetFloat(DESC_MIN, 0.);
	bc.SetInt32(DESC_CUSTOMGUI, CUSTOMGUI_REALSLIDER);
	bc.SetFloat(DESC_MAXSLIDER, 1.);
	bc.SetFloat(DESC_MINSLIDER, 0.);
	bc.SetFloat(DESC_STEP, 0.01);
	bc.SetInt32(DESC_UNIT, DESC_UNIT_PERCENT);
	bc.SetData(DESC_PARENTGROUP, MakeDescIDGeData(m_grp_id));
	m_strength_id = model.AddDynamicDescription(bc, MMDModelRootDynamicDescriptionType::MORPH_STRENGTH, morph_id);
	AddPanelUI(model, morph_id, m_grp_id);
	bc = GetCustomDataTypeDefault(DTYPE_GROUP);
	bc.SetInt32(DESC_COLUMNS, 3);
	bc.SetData(DESC_PARENTGROUP, MakeDescIDGeData(m_grp_id));
	m_button_grp_id = model.AddDynamicDescription(bc, MMDModelRootDynamicDescriptionType::MORPH_GRP, morph_id);
	bc = GetCustomDataTypeDefault(DTYPE_BUTTON);
	bc.SetString(DESC_NAME, GeLoadString(IDS_MORPH_EDITOR));
	bc.SetInt32(DESC_CUSTOMGUI, CUSTOMGUI_BUTTON);
	bc.SetData(DESC_PARENTGROUP, MakeDescIDGeData(m_button_grp_id));
	m_button_editor_id = model.AddDynamicDescription(bc, MMDModelRootDynamicDescriptionType::MORPH_EDITOR_BUTTON, morph_id);
	bc = GetCustomDataTypeDefault(DTYPE_BUTTON);
	bc.SetString(DESC_NAME, GeLoadString(IDS_MORPH_DELETE));
	bc.SetInt32(DESC_CUSTOMGUI, CUSTOMGUI_BUTTON);
	bc.SetData(DESC_PARENTGROUP, MakeDescIDGeData(m_button_grp_id));
	m_button_delete_id = model.AddDynamicDescription(bc, MMDModelRootDynamicDescriptionType::MORPH_DELETE_BUTTON, morph_id);
	bc = GetCustomDataTypeDefault(DTYPE_BUTTON);
	bc.SetString(DESC_NAME, GeLoadString(IDS_MORPH_RENAME));
	bc.SetInt32(DESC_CUSTOMGUI, CUSTOMGUI_BUTTON);
	bc.SetData(DESC_PARENTGROUP, MakeDescIDGeData(m_button_grp_id));
	m_button_rename_id = model.AddDynamicDescription(bc, MMDModelRootDynamicDescriptionType::MORPH_RENAME_BUTTON, morph_id);
	SendCoreMessage(COREMSG_CINEMA, BaseContainer(COREMSG_CINEMA_FORCE_AM_UPDATE));
}

void FlipMorph::AddMorphUI(MMDModelManagerObject& model, Int morph_id)
{
	BaseContainer bc = GetCustomDataTypeDefault(DTYPE_GROUP);
	bc.SetString(DESC_NAME, m_name);
	bc.SetData(DESC_PARENTGROUP, MakeDescIDGeData(ConstDescID(DescLevel(MODEL_MORPH_FLIP_GRP))));
	m_grp_id = model.AddDynamicDescription(bc, MMDModelRootDynamicDescriptionType::MORPH_GRP, morph_id);
	bc = GetCustomDataTypeDefault(DTYPE_REAL);
	bc.SetString(DESC_NAME, m_name);
	bc.SetFloat(DESC_MAX, 1.);
	bc.SetFloat(DESC_MIN, 0.);
	bc.SetInt32(DESC_CUSTOMGUI, CUSTOMGUI_REALSLIDER);
	bc.SetFloat(DESC_MAXSLIDER, 1.);
	bc.SetFloat(DESC_MINSLIDER, 0.);
	bc.SetFloat(DESC_STEP, 0.01);
	bc.SetInt32(DESC_UNIT, DESC_UNIT_PERCENT);
	bc.SetData(DESC_PARENTGROUP, MakeDescIDGeData(m_grp_id));
	m_strength_id = model.AddDynamicDescription(bc, MMDModelRootDynamicDescriptionType::MORPH_GRP, morph_id);
	AddPanelUI(model, morph_id, m_grp_id);
	bc = GetCustomDataTypeDefault(DTYPE_GROUP);
	bc.SetInt32(DESC_COLUMNS, 3);
	bc.SetData(DESC_PARENTGROUP, MakeDescIDGeData(m_grp_id));
	m_button_grp_id = model.AddDynamicDescription(bc, MMDModelRootDynamicDescriptionType::MORPH_STRENGTH, morph_id);
	bc = GetCustomDataTypeDefault(DTYPE_BUTTON);
	bc.SetString(DESC_NAME, GeLoadString(IDS_MORPH_EDITOR));
	bc.SetInt32(DESC_CUSTOMGUI, CUSTOMGUI_BUTTON);
	bc.SetData(DESC_PARENTGROUP, MakeDescIDGeData(m_button_grp_id));
	m_button_editor_id = model.AddDynamicDescription(bc, MMDModelRootDynamicDescriptionType::MORPH_EDITOR_BUTTON, morph_id);
	bc = GetCustomDataTypeDefault(DTYPE_BUTTON);
	bc.SetString(DESC_NAME, GeLoadString(IDS_MORPH_DELETE));
	bc.SetInt32(DESC_CUSTOMGUI, CUSTOMGUI_BUTTON);
	bc.SetData(DESC_PARENTGROUP, MakeDescIDGeData(m_button_grp_id));
	m_button_delete_id = model.AddDynamicDescription(bc, MMDModelRootDynamicDescriptionType::MORPH_DELETE_BUTTON, morph_id);
	bc = GetCustomDataTypeDefault(DTYPE_BUTTON);
	bc.SetString(DESC_NAME, GeLoadString(IDS_MORPH_RENAME));
	bc.SetInt32(DESC_CUSTOMGUI, CUSTOMGUI_BUTTON);
	bc.SetData(DESC_PARENTGROUP, MakeDescIDGeData(m_button_grp_id));
	m_button_rename_id = model.AddDynamicDescription(bc, MMDModelRootDynamicDescriptionType::MORPH_RENAME_BUTTON, morph_id);
	SendCoreMessage(COREMSG_CINEMA, BaseContainer(COREMSG_CINEMA_FORCE_AM_UPDATE));
}

void MeshMorph::AddMorphUI(MMDModelManagerObject& model, Int morph_id)
{
	BaseContainer bc = GetCustomDataTypeDefault(DTYPE_REAL);
	bc.SetString(DESC_NAME, m_name);
	bc.SetFloat(DESC_MAX, 1.);
	bc.SetFloat(DESC_MIN, 0.);
	bc.SetInt32(DESC_CUSTOMGUI, CUSTOMGUI_REALSLIDER);
	bc.SetFloat(DESC_MAXSLIDER, 1.);
	bc.SetFloat(DESC_MINSLIDER, 0.);
	bc.SetFloat(DESC_STEP, 0.01);
	bc.SetInt32(DESC_UNIT, DESC_UNIT_PERCENT);
	bc.SetData(DESC_PARENTGROUP, MakeDescIDGeData(ConstDescID(DescLevel(MODEL_MORPH_MESH_GRP))));
	m_strength_id = model.AddDynamicDescription(bc, MMDModelRootDynamicDescriptionType::MORPH_STRENGTH, morph_id);
	AddPanelUI(model, morph_id, ConstDescID(DescLevel(MODEL_MORPH_MESH_GRP)));
	SendCoreMessage(COREMSG_CINEMA, BaseContainer(COREMSG_CINEMA_FORCE_AM_UPDATE));
}

UVMorph::UVMorph(String name, DescID strength_id) : IMorph(std::move(name), std::move(strength_id))
{}

UVMorph::UVMorph(UVMorph&& other) noexcept : IMorph(std::move(other))
{}

void UVMorph::UpdateMorph(MMDModelManagerObject& model)
{
	if (BaseObject* mesh_manager = model.GetMeshManagerObject())
	{
		mesh_manager->GetNodeData<MMDMeshManagerObject>()->SetMorphStrength(m_name, GetStrength(model.Get()));
	}
}

void UVMorph::AddMorphUI(MMDModelManagerObject& model, Int morph_id)
{
	BaseContainer bc = GetCustomDataTypeDefault(DTYPE_REAL);
	bc.SetString(DESC_NAME, m_name);
	bc.SetFloat(DESC_MAX, 1.);
	bc.SetFloat(DESC_MIN, 0.);
	bc.SetInt32(DESC_CUSTOMGUI, CUSTOMGUI_REALSLIDER);
	bc.SetFloat(DESC_MAXSLIDER, 1.);
	bc.SetFloat(DESC_MINSLIDER, 0.);
	bc.SetFloat(DESC_STEP, 0.01);
	bc.SetInt32(DESC_UNIT, DESC_UNIT_PERCENT);
	bc.SetData(DESC_PARENTGROUP, MakeDescIDGeData(ConstDescID(DescLevel(MODEL_MORPH_UV_GRP))));
	m_strength_id = model.AddDynamicDescription(bc, MMDModelRootDynamicDescriptionType::MORPH_STRENGTH, morph_id);
	AddPanelUI(model, morph_id, ConstDescID(DescLevel(MODEL_MORPH_UV_GRP)));
	SendCoreMessage(COREMSG_CINEMA, BaseContainer(COREMSG_CINEMA_FORCE_AM_UPDATE));
}

void UVMorph::DeleteMorphUI(MMDModelManagerObject& model)
{
	DeletePanelUI(model);
	model.DeleteDynamicDescription(m_strength_id);

	::SendCoreMessage(COREMSG_CINEMA, BaseContainer(COREMSG_CINEMA_FORCE_AM_UPDATE));
	if (::GeIsMainThread())
	{
		::EventAdd();
	}
}

void BoneMorph::AddMorphUI(MMDModelManagerObject& model, Int morph_id)
{
	BaseContainer bc = GetCustomDataTypeDefault(DTYPE_REAL);
	bc.SetString(DESC_NAME, m_name);
	bc.SetFloat(DESC_MAX, 1.);
	bc.SetFloat(DESC_MIN, 0.);
	bc.SetInt32(DESC_CUSTOMGUI, CUSTOMGUI_REALSLIDER);
	bc.SetFloat(DESC_MAXSLIDER, 1.);
	bc.SetFloat(DESC_MINSLIDER, 0.);
	bc.SetFloat(DESC_STEP, 0.01);
	bc.SetInt32(DESC_UNIT, DESC_UNIT_PERCENT);
	bc.SetData(DESC_PARENTGROUP, MakeDescIDGeData(ConstDescID(DescLevel(MODEL_MORPH_BONE_GRP))));
	m_strength_id = model.AddDynamicDescription(bc, MMDModelRootDynamicDescriptionType::MORPH_STRENGTH, morph_id);
	AddPanelUI(model, morph_id, ConstDescID(DescLevel(MODEL_MORPH_BONE_GRP)));
	SendCoreMessage(COREMSG_CINEMA, BaseContainer(COREMSG_CINEMA_FORCE_AM_UPDATE));
}

void GroupMorph::DeleteMorphUI(MMDModelManagerObject& model)
{
	model.DeleteDynamicDescription(m_button_editor_id);
	model.DeleteDynamicDescription(m_button_delete_id);
	model.DeleteDynamicDescription(m_button_rename_id);
	model.DeleteDynamicDescription(m_button_grp_id);
	DeletePanelUI(model);
	model.DeleteDynamicDescription(m_strength_id);
	model.DeleteDynamicDescription(m_grp_id);

	::SendCoreMessage(COREMSG_CINEMA, BaseContainer(COREMSG_CINEMA_FORCE_AM_UPDATE));
	if (::GeIsMainThread())
	{
		::EventAdd();
	}
}

void FlipMorph::DeleteMorphUI(MMDModelManagerObject& model)
{
	model.DeleteDynamicDescription(m_button_editor_id);
	model.DeleteDynamicDescription(m_button_delete_id);
	model.DeleteDynamicDescription(m_button_rename_id);
	model.DeleteDynamicDescription(m_button_grp_id);
	DeletePanelUI(model);
	model.DeleteDynamicDescription(m_strength_id);
	model.DeleteDynamicDescription(m_grp_id);

	::SendCoreMessage(COREMSG_CINEMA, BaseContainer(COREMSG_CINEMA_FORCE_AM_UPDATE));
	if (::GeIsMainThread())
	{
		::EventAdd();
	}
}

void MeshMorph::DeleteMorphUI(MMDModelManagerObject& model)
{
	DeletePanelUI(model);
	model.DeleteDynamicDescription(m_strength_id);

	::SendCoreMessage(COREMSG_CINEMA, BaseContainer(COREMSG_CINEMA_FORCE_AM_UPDATE));
	if (::GeIsMainThread())
	{
		::EventAdd();
	}
}

BoneMorph::BoneMorph(String name, DescID strength_id): IMorph(std::move(name), std::move(strength_id))
{}

BoneMorph::BoneMorph(BoneMorph&& other) noexcept: IMorph(std::move(other))
{}

void BoneMorph::DeleteMorphUI(MMDModelManagerObject& model)
{
	DeletePanelUI(model);
	model.DeleteDynamicDescription(m_strength_id);

	::SendCoreMessage(COREMSG_CINEMA, BaseContainer(COREMSG_CINEMA_FORCE_AM_UPDATE));
	if (::GeIsMainThread())
	{
		::EventAdd();
	}
}

void GroupMorph::AddSubMorph(MMDModelManagerObject* model, Int id, const Float weight)
{
	if (model->GetMorphNum() > id)
	{
		 std::ignore = m_data.Insert(id, weight);
	}
}

void FlipMorph::AddSubMorph(MMDModelManagerObject* model, Int id, const Float weight)
{
	if (model->GetMorphNum() > id) {
		std::ignore = m_data.Insert(id, weight);
	}
}

void GroupMorph::AddSubMorphNoCheck(Int id, const Float weight)
{
	std::ignore = m_data.Insert(id, weight);
}

auto FlipMorph::AddSubMorphNoCheck(Int id, const Float weight) -> void
{
	std::ignore = m_data.Insert(id, weight);
}

void MMDMaterialMorphOffset::FromPMX(const libmmd::PMXFileMorph::MaterialMorph& src)
{
	material_index = src.m_materialIndex;
	op_type = src.m_opType == libmmd::PMXFileMorph::MaterialMorph::OpType::Add
		          ? static_cast<Int32>(MMDMaterialMorphOpType::Add)
		          : static_cast<Int32>(MMDMaterialMorphOpType::Multiply);
	diffuse_rgb = Vector(src.m_diffuse[0], src.m_diffuse[1], src.m_diffuse[2]);
	diffuse_alpha = src.m_diffuse[3];
	specular = Vector(src.m_specular[0], src.m_specular[1], src.m_specular[2]);
	specular_power = src.m_specularPower;
	ambient = Vector(src.m_ambient[0], src.m_ambient[1], src.m_ambient[2]);
	edge_color_rgb = Vector(src.m_edgeColor[0], src.m_edgeColor[1], src.m_edgeColor[2]);
	edge_color_alpha = src.m_edgeColor[3];
	edge_size = src.m_edgeSize;
	texture_factor_rgb = Vector(src.m_textureFactor[0], src.m_textureFactor[1], src.m_textureFactor[2]);
	texture_factor_alpha = src.m_textureFactor[3];
	sphere_texture_factor_rgb = Vector(src.m_sphereTextureFactor[0], src.m_sphereTextureFactor[1], src.m_sphereTextureFactor[2]);
	sphere_texture_factor_alpha = src.m_sphereTextureFactor[3];
	toon_texture_factor_rgb = Vector(src.m_toonTextureFactor[0], src.m_toonTextureFactor[1], src.m_toonTextureFactor[2]);
	toon_texture_factor_alpha = src.m_toonTextureFactor[3];
}

void MMDMaterialMorphOffset::ToPMX(libmmd::PMXFileMorph::MaterialMorph& dst) const
{
	dst.m_materialIndex = material_index;
	dst.m_opType = op_type == static_cast<Int32>(MMDMaterialMorphOpType::Add)
		               ? libmmd::PMXFileMorph::MaterialMorph::OpType::Add
		               : libmmd::PMXFileMorph::MaterialMorph::OpType::Mul;
	dst.m_diffuse = Eigen::Vector4f(
		static_cast<float>(diffuse_rgb.x), static_cast<float>(diffuse_rgb.y),
		static_cast<float>(diffuse_rgb.z), static_cast<float>(diffuse_alpha));
	dst.m_specular = Eigen::Vector3f(
		static_cast<float>(specular.x), static_cast<float>(specular.y), static_cast<float>(specular.z));
	dst.m_specularPower = static_cast<float>(specular_power);
	dst.m_ambient = Eigen::Vector3f(
		static_cast<float>(ambient.x), static_cast<float>(ambient.y), static_cast<float>(ambient.z));
	dst.m_edgeColor = Eigen::Vector4f(
		static_cast<float>(edge_color_rgb.x), static_cast<float>(edge_color_rgb.y),
		static_cast<float>(edge_color_rgb.z), static_cast<float>(edge_color_alpha));
	dst.m_edgeSize = static_cast<float>(edge_size);
	dst.m_textureFactor = Eigen::Vector4f(
		static_cast<float>(texture_factor_rgb.x), static_cast<float>(texture_factor_rgb.y),
		static_cast<float>(texture_factor_rgb.z), static_cast<float>(texture_factor_alpha));
	dst.m_sphereTextureFactor = Eigen::Vector4f(
		static_cast<float>(sphere_texture_factor_rgb.x), static_cast<float>(sphere_texture_factor_rgb.y),
		static_cast<float>(sphere_texture_factor_rgb.z), static_cast<float>(sphere_texture_factor_alpha));
	dst.m_toonTextureFactor = Eigen::Vector4f(
		static_cast<float>(toon_texture_factor_rgb.x), static_cast<float>(toon_texture_factor_rgb.y),
		static_cast<float>(toon_texture_factor_rgb.z), static_cast<float>(toon_texture_factor_alpha));
}

Bool MMDMaterialMorphOffset::Read(HyperFile* hf)
{
	IOReadField(material_index);
	IOReadField(op_type);
	IOReadField(diffuse_rgb);
	IOReadField(diffuse_alpha);
	IOReadField(specular);
	IOReadField(specular_power);
	IOReadField(ambient);
	IOReadField(edge_color_rgb);
	IOReadField(edge_color_alpha);
	IOReadField(edge_size);
	IOReadField(texture_factor_rgb);
	IOReadField(texture_factor_alpha);
	IOReadField(sphere_texture_factor_rgb);
	IOReadField(sphere_texture_factor_alpha);
	IOReadField(toon_texture_factor_rgb);
	IOReadField(toon_texture_factor_alpha);
	return true;
}

Bool MMDMaterialMorphOffset::Write(HyperFile* hf) const
{
	IOWriteField(material_index);
	IOWriteField(op_type);
	IOWriteField(diffuse_rgb);
	IOWriteField(diffuse_alpha);
	IOWriteField(specular);
	IOWriteField(specular_power);
	IOWriteField(ambient);
	IOWriteField(edge_color_rgb);
	IOWriteField(edge_color_alpha);
	IOWriteField(edge_size);
	IOWriteField(texture_factor_rgb);
	IOWriteField(texture_factor_alpha);
	IOWriteField(sphere_texture_factor_rgb);
	IOWriteField(sphere_texture_factor_alpha);
	IOWriteField(toon_texture_factor_rgb);
	IOWriteField(toon_texture_factor_alpha);
	return true;
}

MaterialMorph::MaterialMorph(String name, DescID strength_id) : IMorph(std::move(name), std::move(strength_id))
{}

MaterialMorph::MaterialMorph(MaterialMorph&& other) noexcept : IMorph(std::move(other)), m_offsets(std::move(other.m_offsets))
{}

Bool MaterialMorph::Read(HyperFile* hf, Int32 level)
{
	if (!IMorph::Read(hf, level))
		return false;
	m_offsets.Reset();
	// Level 4 起才持久化材质表情 offset；旧场景（level < 4）读取为空列表。
	if (level >= 4)
	{
		if (!io_util::ReadLinearContainer(hf, m_offsets))
			return false;
	}
	return true;
}

Bool MaterialMorph::Write(HyperFile* hf) SDK2024_Const
{
	if (!IMorph::Write(hf))
		return false;
	if (!io_util::WriteLinearContainer(hf, m_offsets))
		return false;
	return true;
}

Bool MaterialMorph::CopyTo(IMorph* dest) const
{
	if (!IMorph::CopyTo(dest))
		return false;
	if (dest->GetType() != MMDMorphType::MATERIAL)
		return true;
	auto* const material_dest = static_cast<MaterialMorph*>(dest);
	auto& dest_offsets = material_dest->m_offsets;
	dest_offsets.Reset();
	iferr(dest_offsets.CopyFrom(m_offsets))
		return false;
	return true;
}

Bool MaterialMorph::ValidateMaterialIndices(const Int material_count, const Bool drop_invalid)
{
	Bool has_invalid = false;
	for (Int i = m_offsets.GetCount() - 1; i >= 0; --i)
	{
		const Int32 index = m_offsets[i].material_index;
		// -1 表示全部材质，永远有效。
		if (index == -1)
			continue;
		if (index >= 0 && index < material_count)
			continue;
		has_invalid = true;
		if (drop_invalid)
			m_offsets.Erase(i) iferr_ignore("erase invalid material morph offset failed"_s);
	}
	return has_invalid;
}

void MaterialMorph::UpdateMorph(MMDModelManagerObject& model)
{}

void MaterialMorph::AddMorphUI(MMDModelManagerObject& model, Int morph_id)
{
	BaseContainer bc = GetCustomDataTypeDefault(DTYPE_REAL);
	bc.SetString(DESC_NAME, m_name);
	bc.SetFloat(DESC_MAX, 1.);
	bc.SetFloat(DESC_MIN, 0.);
	bc.SetInt32(DESC_CUSTOMGUI, CUSTOMGUI_REALSLIDER);
	bc.SetFloat(DESC_MAXSLIDER, 1.);
	bc.SetFloat(DESC_MINSLIDER, 0.);
	bc.SetFloat(DESC_STEP, 0.01);
	bc.SetInt32(DESC_UNIT, DESC_UNIT_PERCENT);
	bc.SetData(DESC_PARENTGROUP, MakeDescIDGeData(ConstDescID(DescLevel(MODEL_MORPH_MATERIAL_GRP))));
	m_strength_id = model.AddDynamicDescription(bc, MMDModelRootDynamicDescriptionType::MORPH_STRENGTH, morph_id);
	AddPanelUI(model, morph_id, ConstDescID(DescLevel(MODEL_MORPH_MATERIAL_GRP)));
	SendCoreMessage(COREMSG_CINEMA, BaseContainer(COREMSG_CINEMA_FORCE_AM_UPDATE));
}

void MaterialMorph::DeleteMorphUI(MMDModelManagerObject& model)
{
	DeletePanelUI(model);
	model.DeleteDynamicDescription(m_strength_id);
	::SendCoreMessage(COREMSG_CINEMA, BaseContainer(COREMSG_CINEMA_FORCE_AM_UPDATE));
	if (::GeIsMainThread())
	{
		::EventAdd();
	}
}

ImpulseMorph::ImpulseMorph(String name, DescID strength_id) : IMorph(std::move(name), std::move(strength_id))
{}

ImpulseMorph::ImpulseMorph(ImpulseMorph&& other) noexcept : IMorph(std::move(other))
{}

void ImpulseMorph::UpdateMorph(MMDModelManagerObject& model)
{}

void ImpulseMorph::AddMorphUI(MMDModelManagerObject& model, Int morph_id)
{
	BaseContainer bc = GetCustomDataTypeDefault(DTYPE_REAL);
	bc.SetString(DESC_NAME, m_name);
	bc.SetFloat(DESC_MAX, 1.);
	bc.SetFloat(DESC_MIN, 0.);
	bc.SetInt32(DESC_CUSTOMGUI, CUSTOMGUI_REALSLIDER);
	bc.SetFloat(DESC_MAXSLIDER, 1.);
	bc.SetFloat(DESC_MINSLIDER, 0.);
	bc.SetFloat(DESC_STEP, 0.01);
	bc.SetInt32(DESC_UNIT, DESC_UNIT_PERCENT);
	bc.SetData(DESC_PARENTGROUP, MakeDescIDGeData(ConstDescID(DescLevel(MODEL_MORPH_IMPULSE_GRP))));
	m_strength_id = model.AddDynamicDescription(bc, MMDModelRootDynamicDescriptionType::MORPH_STRENGTH, morph_id);
	AddPanelUI(model, morph_id, ConstDescID(DescLevel(MODEL_MORPH_IMPULSE_GRP)));
	SendCoreMessage(COREMSG_CINEMA, BaseContainer(COREMSG_CINEMA_FORCE_AM_UPDATE));
}

void ImpulseMorph::DeleteMorphUI(MMDModelManagerObject& model)
{
	DeletePanelUI(model);
	model.DeleteDynamicDescription(m_strength_id);
	::SendCoreMessage(COREMSG_CINEMA, BaseContainer(COREMSG_CINEMA_FORCE_AM_UPDATE));
	if (::GeIsMainThread())
	{
		::EventAdd();
	}
}
