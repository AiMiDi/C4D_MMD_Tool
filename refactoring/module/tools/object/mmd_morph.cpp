#include <c4d.h>
#include <c4d_symbols.h>
#include "module/core/cmt_marco.h"
#include "mmd_morph.h"
#include "mmd_model_manager.h"
#include "mmd_mesh_manager.h"
#include "mmd_bone_manager.h"
#include "description/OMMDModelManager.h"

inline Bool IMorph::Read(HyperFile* hf)
{
	IOReadField(m_strength_id);
	IOReadField(m_name);
	return true;
}

inline Bool IMorph::Write(HyperFile* hf) SDK2024_Const
{
	IOWriteField(m_strength_id);
	IOWriteField(m_name);
	return true;
}

inline Bool IMorph::CopyTo(IMorph* dest) const
{
	dest->m_strength_id = m_strength_id;
	dest->m_name = m_name;
	return true;
}

inline Bool GroupMorph::Read(HyperFile* hf)
{
	if (!IMorph::Read(hf))
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

inline Bool GroupMorph::Write(HyperFile* hf) SDK2024_Const
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

inline Bool GroupMorph::CopyTo(IMorph* dest) const
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

inline Bool FlipMorph::Read(HyperFile* hf)
{
	if (IMorph::Read(hf) == false)
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

inline Bool FlipMorph::Write(HyperFile* hf) SDK2024_Const
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

inline Bool FlipMorph::CopyTo(IMorph* dest) const
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

inline Float IMorph::GetStrength(SDK2024_Const GeListNode* node) const
{
	GeData ge_data;
	if (!node->GetParameter(m_strength_id, ge_data, DESCFLAGS_GET::NONE))
	{
		return 0.0;
	}
	return ge_data.GetFloat();
}

inline Bool IMorph::SetStrength(GeListNode* node, const Float& strength) const
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

inline void GroupMorph::RenameSubMorph(const Int old_id, const Int new_id)
{
	if (auto* data_ptr = m_data.Find(old_id); data_ptr)
	{
		iferr(m_data.Insert(new_id, data_ptr->GetValue()))
			return;
		std::ignore = m_data.Erase(data_ptr);
	}
}

inline void FlipMorph::RenameSubMorph(const Int old_id, const Int new_id)
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

inline void GroupMorph::UpdateMorph(MMDModelManagerObject& model)
{
	GeListNode* node = model.Get();
	auto& morph_arr = model.GetMorphData();
	for (auto& data : m_data)
	{
		auto& morph = morph_arr[data.GetKey()];
		morph.SetStrength(node, GetStrength(node) * data.GetValue());
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

inline void FlipMorph::UpdateMorph(MMDModelManagerObject& model)
{
	GeListNode* node = model.Get();
	auto& morph_arr = model.GetMorphData();
	for (auto& data : m_data) {
		auto& morph_id = data.GetKey();
		auto& morph = morph_arr[morph_id];
		morph.SetStrength(node, GetStrength(node) >= 0.5 ? data.GetValue() : 0.0);
	}
}

inline void MeshMorph::UpdateMorph(MMDModelManagerObject& model)
{
	if (BaseObject* mesh_manager = model.GetMeshManagerObject())
	{
		mesh_manager->GetNodeData<MMDMeshManagerObject>()->SetMorphStrength(m_name, GetStrength(model.Get()));
	}

}

inline void BoneMorph::UpdateMorph(MMDModelManagerObject& model)
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

inline void GroupMorph::AddMorphUI(MMDModelManagerObject& model, Int morph_id)
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

inline void FlipMorph::AddMorphUI(MMDModelManagerObject& model, Int morph_id)
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

inline void MeshMorph::AddMorphUI(MMDModelManagerObject& model, Int morph_id)
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

inline void UVMorph::UpdateMorph(MMDModelManagerObject& model)
{
	if (BaseObject* mesh_manager = model.GetMeshManagerObject())
	{
		mesh_manager->GetNodeData<MMDMeshManagerObject>()->SetMorphStrength(m_name, GetStrength(model.Get()));
	}
}

inline void UVMorph::AddMorphUI(MMDModelManagerObject& model, Int morph_id)
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

inline void UVMorph::DeleteMorphUI(MMDModelManagerObject& model)
{
	DeletePanelUI(model);
	model.DeleteDynamicDescription(m_strength_id);

	::SendCoreMessage(COREMSG_CINEMA, BaseContainer(COREMSG_CINEMA_FORCE_AM_UPDATE));
	if (::GeIsMainThread())
	{
		::EventAdd();
	}
}

inline void BoneMorph::AddMorphUI(MMDModelManagerObject& model, Int morph_id)
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

inline void GroupMorph::DeleteMorphUI(MMDModelManagerObject& model)
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

inline void FlipMorph::DeleteMorphUI(MMDModelManagerObject& model)
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

inline void MeshMorph::DeleteMorphUI(MMDModelManagerObject& model)
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

inline void BoneMorph::DeleteMorphUI(MMDModelManagerObject& model)
{
	DeletePanelUI(model);
	model.DeleteDynamicDescription(m_strength_id);

	::SendCoreMessage(COREMSG_CINEMA, BaseContainer(COREMSG_CINEMA_FORCE_AM_UPDATE));
	if (::GeIsMainThread())
	{
		::EventAdd();
	}
}

inline void GroupMorph::AddSubMorph(MMDModelManagerObject* model, Int id, const Float weight)
{
	if (model->GetMorphNum() > id)
	{
		 std::ignore = m_data.Insert(id, weight);
	}
}

inline void FlipMorph::AddSubMorph(MMDModelManagerObject* model, Int id, const Float weight)
{
	if (model->GetMorphNum() > id) {
		std::ignore = m_data.Insert(id, weight);
	}
}

inline void GroupMorph::AddSubMorphNoCheck(Int id, const Float weight)
{
	std::ignore = m_data.Insert(id, weight);
}

inline auto FlipMorph::AddSubMorphNoCheck(Int id, const Float weight) -> void
{
	std::ignore = m_data.Insert(id, weight);
}

MaterialMorph::MaterialMorph(String name, DescID strength_id) : IMorph(std::move(name), std::move(strength_id))
{}

MaterialMorph::MaterialMorph(MaterialMorph&& other) noexcept : IMorph(std::move(other))
{}

inline void MaterialMorph::UpdateMorph(MMDModelManagerObject& model)
{}

inline void MaterialMorph::AddMorphUI(MMDModelManagerObject& model, Int morph_id)
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

inline void MaterialMorph::DeleteMorphUI(MMDModelManagerObject& model)
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

inline void ImpulseMorph::UpdateMorph(MMDModelManagerObject& model)
{}

inline void ImpulseMorph::AddMorphUI(MMDModelManagerObject& model, Int morph_id)
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

inline void ImpulseMorph::DeleteMorphUI(MMDModelManagerObject& model)
{
	DeletePanelUI(model);
	model.DeleteDynamicDescription(m_strength_id);
	::SendCoreMessage(COREMSG_CINEMA, BaseContainer(COREMSG_CINEMA_FORCE_AM_UPDATE));
	if (::GeIsMainThread())
	{
		::EventAdd();
	}
}
