/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & CMT contributors.
Author:			Aimidi
Date:			2023/9/12
File:			mmd_model.h
Description:	MMD model object 

**************************************************************************/

#include "pch.h"
#include "mmd_model.h"
#include "description/OMMDModel.h"

#define COL_NAME 'name'

Bool EditorSubMorphDialog::CreateLayout()
{
	SetTitle(GeLoadString(IDS_MORPH_EDITOR));
	m_images = std::make_unique<ImagesUserArea>("mmd_tool_title.png"_s, 300, 95);
	if (C4DGadget* userAreaGadget = this->AddUserArea(999, BFH_SCALE, SizePix(300), SizePix(95));
		userAreaGadget != nullptr)
		this->AttachUserArea(*m_images, userAreaGadget);
	GroupBegin(1000, BFH_CENTER, 3, 1, ""_s, 0, 0, 150);
	AddListView(10004, BFH_LEFT, 350, 150);
	m_listview.AttachListView(this, 10004);
	AddButton(10005, BFH_LEFT, 30, 10, ">>"_s);
	m_id = 20000;
	auto* sub_morph_data = m_morph->GetSubMorphDataWritable();
	if (sub_morph_data == nullptr) {
		this->Close();
		return false;
	}
	ScrollGroupBegin(1002, BFH_SCALEFIT, SCROLLGROUP_VERT | SCROLLGROUP_BORDERIN, 350, 150);
	GroupBegin(1003, BFH_CENTER, 1, 0, ""_s, 0, 350, 150);
	for (auto& data : *sub_morph_data)
	{
		const auto sub_morph_id = data.GetKey();
		if(const auto morph_count = m_model->GetMorphNum(); morph_count >= sub_morph_id)
			continue;
		GroupBegin(m_id++, BFH_LEFT, 3, 1, ""_s, 0, 350, 10);
		AddStaticText(m_id++, BFH_LEFT, 150, 10, m_model->GetMorphData()[sub_morph_id].GetName(), BORDER_NONE);
		AddEditNumber(m_id, BFH_LEFT, 150, 10);
		SetFloat(m_id++, data.GetValue());
		AddButton(m_id, BFH_LEFT, 32, 10, GeLoadString(IDS_DELETE));
		iferr(m_delete_button_id_set.Insert(m_id++))
			return false;
		GroupEnd();

	}
	GroupEnd();
	GroupEnd();
	GroupEnd();
	GroupBegin(1004, BFH_CENTER, 2, 1, ""_s, 0, 0, 20);
	GroupSpace(50, 0);
	AddButton(10002, BFH_LEFT, 80, 20, GeLoadString(IDS_MSG_RENAME_OK));
	AddButton(10003, BFH_RIGHT, 80, 20, GeLoadString(IDS_MSG_RENAME_CANCEL));
	GroupEnd();
	return true;
}

Bool EditorSubMorphDialog::InitValues()
{
	BaseContainer layout;
	layout.SetInt32(COL_NAME, LV_COLUMN_TEXT);
	m_listview.SetLayout(1, layout);
	m_listview.SetProperty(SLV_MULTIPLESELECTION, true);
	Int32 line = 0;
	const auto& morph_data = m_model->GetMorphData();
	for (const auto& data : morph_data)
	{
		if (const String& name = data.GetName(); name != m_morph->GetName()) {
			BaseContainer bc;
			bc.SetString(COL_NAME, name);
			m_listview.SetItem(line++, bc);
		}
	}
	m_listview.DataChanged();
	return true;
}
Bool EditorSubMorphDialog::Command(Int32 id, const BaseContainer& msg)
{
	switch (id)
	{
	// RENAME_OK
	case 10002:
	{
		auto* sub_morph_data = m_morph->GetSubMorphDataWritable();
		if (sub_morph_data == nullptr) {
			this->Close();
			return false;
		}
		sub_morph_data->Reset();
		for (auto& delete_button_id : m_delete_button_id_set)
		{
			String name;
			Float weight = 0;
			GetString(delete_button_id - 2, name);
			GetFloat(delete_button_id - 1, weight);
			if(const auto id_ptr = m_model->GetMorphNameMap().Find(name); id_ptr)
				m_morph->AddSubMorph(m_model, id_ptr->GetValue(), weight);
		}
		Close();
		break;
	}
	// RENAME_CANCEL
	case 10003:
	{
		Close();
		break;
	}
	// >>
	case 10005:
	{
		BaseSelect* select = BaseSelect::Alloc();
		m_listview.GetSelection(select);
		BaseContainer bc;
		Int32 seg = 0, a, b;
		maxon::BaseList<maxon::Pair<String, Float>> tmp;
		for (auto& delete_button_id : m_delete_button_id_set)
		{
			auto& tmp_data = tmp.Append().GetValue();
			GetString(delete_button_id - 2, tmp_data.first);
			GetFloat(delete_button_id - 1, tmp_data.second);
		}
		m_delete_button_id_set.Reset();
		// begin layout change and store data
		UpdateDialogHelper updateDialog = BeginLayoutChange(1003, true);
		for (auto& tmp_data : tmp)
		{
			GroupBegin(m_id++, BFH_LEFT, 3, 1, ""_s, 0, 350, 10);
			AddStaticText(m_id++, BFH_LEFT, 150, 10, tmp_data.first, BORDER_NONE);
			AddEditNumber(m_id, BFH_LEFT, 150, 10);
			SetFloat(m_id++, tmp_data.second);
			AddButton(m_id, BFH_LEFT, 32, 10, GeLoadString(IDS_DELETE));
			iferr(m_delete_button_id_set.Insert(m_id++))
			{
				GroupEnd();
				return false;
			}
			GroupEnd();
		}
		while (select->GetRange(seg++, LIMIT<Int32>::MAX, &a, &b))
		{
			for (Int32 item = a; item <= b; ++item)
			{
				if (m_listview.GetItem(item, &bc) == false)
					continue;
				GroupBegin(m_id++, BFH_LEFT, 3, 1, ""_s, 0, 350, 10);
				AddStaticText(m_id++, BFH_LEFT, 150, 10, bc.GetString(COL_NAME), BORDER_NONE);
				AddEditNumber(m_id, BFH_LEFT, 150, 10);
				SetFloat(m_id++, 1.0);
				AddButton(m_id, BFH_LEFT, 32, 10, GeLoadString(IDS_DELETE));
				if (m_listview.RemoveItem(item) == false)
				{
					GroupEnd();
					continue;
				}
				iferr(m_delete_button_id_set.Insert(m_id++))
					return false;
				GroupEnd();
			}
		}
		// update group
		updateDialog.CommitChanges();
		//LayoutChanged(1003);
		m_listview.DataChanged();
		break;
	}
	default:
		if (m_delete_button_id_set.Find(id) != nullptr)
		{
			String name;
			RemoveElement(id);
			RemoveElement(id - 1);
			GetString(id - 2, name);
			RemoveElement(id - 2);
			RemoveElement(id - 3);
			BaseContainer data;
			data.SetString(10000, name);
			m_listview.SetItem(m_listview.GetItemCount(), data);
			m_listview.DataChanged();
			LayoutChanged(1003);
			m_delete_button_id_set.Erase(id);
		}
		break;
	}
	return true;
}

inline Bool IMorph::Read(HyperFile* hf)
{
	if (m_strength_id.Read(hf) == false)
		return false;
	if (hf->ReadString(&m_name) == false)
		return false;
	if (UChar type = 0;hf->ReadUChar(&type))
	{
		m_type = static_cast<MorphType>(type);
	}
	else
	{
		return false;
	}
	return true;
}
inline Bool IMorph::Write(HyperFile* hf) const
{
	if (m_strength_id.Write(hf) == false)
		return false;
	if (hf->WriteString(m_name) == false)
		return false;
	if (!hf->WriteUChar(static_cast<uint8_t>(m_type)))
		return false;
	return true;
}
inline Bool IMorph::CopyTo(IMorph* dest) const
{
	dest->m_strength_id = m_strength_id;
	dest->m_name = m_name;
	dest->m_type = m_type;
	return true;
}
inline Bool GroupMorph::Read(HyperFile* hf)
{
	if (this->IMorph::Read(hf) == false)
		return false;
	if (m_grp_id.Read(hf) == false)
		return false;
	if (m_button_grp_id.Read(hf) == false)
		return false;
	if (m_button_editor_id.Read(hf) == false)
		return false;
	if (m_button_delete_id.Read(hf) == false)
		return false;
	if (m_button_rename_id.Read(hf) == false)
		return false;
	m_data.Reset();
	Int64 data_const = 0;
	if (hf->ReadInt64(&data_const) == false)
		return false;
	for (Int64 i = 0; i < data_const; ++i)
	{
		Int32 id;
		Float influence;
		if (hf->ReadInt32(&id) == false)
			return false;
		if (hf->ReadFloat(&influence) == false)
			return false;
		iferr(m_data.Insert(id, influence))
			return false;
	}
	return true;
}
inline Bool GroupMorph::Write(HyperFile* hf) const
{
	if (this->IMorph::Write(hf) == false)
		return false;
	if (m_grp_id.Write(hf) == false)
		return false;
	if (m_button_grp_id.Write(hf) == false)
		return false;
	if (m_button_editor_id.Write(hf) == false)
		return false;
	if (m_button_delete_id.Write(hf) == false)
		return false;
	if (m_button_rename_id.Write(hf) == false)
		return false;
	if (hf->WriteInt64(m_data.GetCount()) == false)
		return false;
	for (auto& data : m_data)
	{
		if (hf->WriteInt32(data.GetKey()) == false)
			return false;
		if (hf->WriteFloat(data.GetValue()) == false)
			return false;
	}
	return true;
}
inline Bool GroupMorph::CopyTo(IMorph* dest) const
{
	if (this->IMorph::CopyTo(dest) == false)
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
	if (this->IMorph::Read(hf) == false)
		return false;
	if (m_grp_id.Read(hf) == false)
		return false;
	if (m_button_grp_id.Read(hf) == false)
		return false;
	if (m_button_editor_id.Read(hf) == false)
		return false;
	if (m_button_delete_id.Read(hf) == false)
		return false;
	if (m_button_rename_id.Read(hf) == false)
		return false;
	m_data.Reset();
	Int64 data_const = 0;
	if (hf->ReadInt64(&data_const) == false)
		return false;
	for (Int64 i = 0; i < data_const; ++i)
	{
		Int32 id;
		Float influence;
		if (hf->ReadInt32(&id) == false)
			return false;
		if (hf->ReadFloat(&influence) == false)
			return false;
		iferr(m_data.Insert(id, influence))
			return false;
	}
	return true;
}
inline Bool FlipMorph::Write(HyperFile* hf) const
{
	if (this->IMorph::Write(hf) == false)
		return false;
	if (m_grp_id.Write(hf) == false)
		return false;
	if (m_button_grp_id.Write(hf) == false)
		return false;
	if (m_button_editor_id.Write(hf) == false)
		return false;
	if (m_button_delete_id.Write(hf) == false)
		return false;
	if (m_button_rename_id.Write(hf) == false)
		return false;
	if (hf->WriteInt64(m_data.GetCount()) == false)
		return false;
	for (auto& data : m_data)
	{
		if (hf->WriteInt32(data.GetKey()) == false)
			return false;
		if (hf->WriteFloat(data.GetValue()) == false)
			return false;
	}
	return true;
}
inline Bool FlipMorph::CopyTo(IMorph* dest) const
{
	if (this->IMorph::CopyTo(dest) == false)
		return false;
	for (auto& data : m_data)
	{
		iferr(dest->GetSubMorphDataWritable()->Insert(data.GetKey(), data.GetValue()))
			return false;
	}
	return true;
}
inline Float IMorph::GetStrength(GeListNode* node) const
{
	GeData ge_data;
	if (node->GetParameter(m_strength_id, ge_data, DESCFLAGS_GET::NONE) == false) {
		return 0.0;
	}
	return ge_data.GetFloat();
}
inline Bool IMorph::SetStrength(GeListNode* node, const Float& strength) const
{
	return node->SetParameter(m_strength_id, strength, DESCFLAGS_SET::NONE);
}
inline void IMorph::RenameMorph(MMDModelObject* model, const String& name)
{
	DynamicDescription* const ddesc = model->Get()->GetDynamicDescriptionWritable();
	if (ddesc == nullptr)
		return;
	BaseContainer descbc = *ddesc->Find(m_strength_id);
	descbc.SetString(DESC_NAME, name);
	ddesc->Set(m_strength_id, descbc, nullptr);
	auto& morph_name_map = model->GetMorphNameMapWritable();
	auto* morph_name_ptr = morph_name_map.Find(name);
	if (morph_name_ptr != nullptr) {
		const Int32& index = morph_name_ptr->GetValue();
		iferr(morph_name_map.Insert(name, index))
			return;
		iferr(morph_name_map.Erase(morph_name_ptr))
			return;
	}
	auto& morph_arr = model->GetMorphDataWritable();
	for (auto& morph : morph_arr)
	{
		if (morph.IsMeshMorph() || morph.IsBoneMorph()) {
			morph.RenameSubMorph(m_name, name);
		}
	}
	m_name = name;
	::SendCoreMessage(COREMSG_CINEMA, BaseContainer(COREMSG_CINEMA_FORCE_AM_UPDATE)); /* Refresh the AM to see the changes in real time */
	if (::GeIsMainThread())
	{
		::EventAdd();
	}
}
inline void GroupMorph::RenameMorph(MMDModelObject* model, const String& name)
{
	DynamicDescription* const ddesc = model->Get()->GetDynamicDescriptionWritable();
	if (ddesc == nullptr)
		return;
	BaseContainer descbc = *ddesc->Find(m_grp_id);
	descbc.SetString(DESC_NAME, name);
	ddesc->Set(m_grp_id, descbc, nullptr);
	this->IMorph::RenameMorph(model, name);
}
inline void FlipMorph::RenameMorph(MMDModelObject* model, const String& name)
{
	DynamicDescription* const ddesc = model->Get()->GetDynamicDescriptionWritable();
	if (ddesc == nullptr)
		return;
	BaseContainer descbc = *ddesc->Find(m_grp_id);
	descbc.SetString(DESC_NAME, name);
	ddesc->Set(m_grp_id, descbc, nullptr);
	this->IMorph::RenameMorph(model, name);
}
inline void GroupMorph::RenameSubMorph(const String& old_name, const String& new_name)
{
	if (auto* data_ptr = m_data.Find(old_name); data_ptr != nullptr) {
		iferr(m_data.Insert(new_name, data_ptr->GetValue()))
			return;
		std::ignore = m_data.Erase(data_ptr);
			return;
	}
}
inline void FlipMorph::RenameSubMorph(const String& old_name, const String& new_name)
{
	if (auto* data_ptr = m_data.Find(old_name); data_ptr != nullptr) {
		iferr(m_data.Insert(new_name, data_ptr->GetValue()))
			return;
		std::ignore = m_data.Erase(data_ptr);
	}
}
inline void GroupMorph::UpdateMorphOfModel(MMDModelObject* model) {
	if (model == nullptr)
		return;
	GeListNode* node = model->Get();
	const auto morph_num = model->GetMorphNum();
	auto& morph_arr = model->GetMorphDataWritable();
	for (auto& data : m_data) {
		auto& morph_index = data.GetKey();
		if (morph_index >= morph_num)
		{
			for (auto& morph : morph_arr) {
				morph.DeleteSubMorph(morph_index);
			}
			return;
		}
		auto& morph = morph_arr[morph_index];
		morph.SetStrength(node, this->GetStrength(node) * data.GetValue());
	}
}
inline void FlipMorph::UpdateMorphOfModel(MMDModelObject* model) {
	if (model == nullptr)
		return;
	GeListNode* node = model->Get();
	auto& morph_name_map = model->GetMorphNameMap();
	auto& morph_arr = model->GetMorphDataWritable();
	for (auto& data : m_data) {
		auto& morph_name = data.GetKey();
		auto* morph_ptr = morph_name_map.Find(morph_name);
		if (morph_ptr == nullptr) {
			for (auto& morph : morph_arr) {
				morph.DeleteSubMorph(morph_name);
			}
			return;
		}
		IMorph& morph = morph_arr[morph_ptr->GetValue()];
		morph.SetStrength(node, this->GetStrength(node) >= 0.5 ? data.GetValue() : 0.0);
	}
}
inline void MeshMorph::UpdateMorphOfModel(MMDModelObject* model)
{
	if (model == nullptr)
		return;
	BaseObject* MeshRoot_ptr = model->GetRootObject(ToolObjectType::MeshRoot);
	if (MeshRoot_ptr == nullptr)
		return;
	auto& mesh_morph_map = MeshRoot_ptr->GetNodeData<MMDMeshRootObject>()->GetMeshMorphMap();
	auto* mesh_morph_ptr = mesh_morph_map.Find(m_name);
	if (mesh_morph_ptr == nullptr)
		return;
	auto& mesh_morph_list = mesh_morph_ptr->GetValue();
	for (auto& mesh_morph : mesh_morph_list) {
		mesh_morph.SetStrength(this->GetStrength(model->Get()));
	}
}
inline void BoneMorph::UpdateMorphOfModel(MMDModelObject* model)
{
	if (model == nullptr)
		return;
	BaseObject* BoneRoot_ptr = model->GetRootObject(ToolObjectType::BoneRoot);
	if (BoneRoot_ptr == nullptr)
		return;
	auto& bone_morph_map = BoneRoot_ptr->GetNodeData<OMMDBoneRoot>()->GetBoneMorphMap();
	auto* bone_morph_ptr = bone_morph_map.Find(m_name);
	if (bone_morph_ptr == nullptr)
		return;
	auto& mesh_morph_list = bone_morph_ptr->GetValue();
	for (auto& bone_morph : mesh_morph_list) {
		bone_morph.SetStrength(this->GetStrength(model->Get()));
	}
}
inline Int32 GroupMorph::AddMorphToModel(MMDModelObject* model, String morph_name)
{
	if (morph_name.IsEmpty())
	{
		morph_name = "[Group morph]" + model->GetMorphNamedNumber();
	}
	DynamicDescription* const ddesc = model->Get()->GetDynamicDescriptionWritable();
	if (ddesc == nullptr)
		return-1;
	BaseContainer bc = GetCustomDataTypeDefault(DTYPE_GROUP);
	bc.SetString(DESC_NAME, morph_name);
	bc.SetData(DESC_PARENTGROUP, GeData_DescID(ConstDescID(DescLevel(MODEL_MORPH_GROUP_GRP))));
	m_grp_id = ddesc->Alloc(bc);
	bc = GetCustomDataTypeDefault(DTYPE_REAL);
	bc.SetString(DESC_NAME, morph_name);
	bc.SetFloat(DESC_MAX, 1.);
	bc.SetFloat(DESC_MIN, 0.);
	bc.SetInt32(DESC_CUSTOMGUI, CUSTOMGUI_REALSLIDER);
	bc.SetFloat(DESC_MAXSLIDER, 1.);
	bc.SetFloat(DESC_MINSLIDER, 0.);
	bc.SetFloat(DESC_STEP, 0.01);
	bc.SetInt32(DESC_UNIT, DESC_UNIT_PERCENT);
	bc.SetData(DESC_PARENTGROUP, GeData_DescID(m_grp_id));
	m_strength_id = ddesc->Alloc(bc);
	bc = GetCustomDataTypeDefault(DTYPE_GROUP);
	bc.SetInt32(DESC_COLUMNS, 3);
	bc.SetData(DESC_PARENTGROUP, GeData_DescID(m_grp_id));
	m_button_grp_id = ddesc->Alloc(bc);
	bc = GetCustomDataTypeDefault(DTYPE_BUTTON);
	bc.SetString(DESC_NAME, GeLoadString(IDS_MORPH_EDITOR));
	bc.SetInt32(DESC_CUSTOMGUI, CUSTOMGUI_BUTTON);
	bc.SetData(DESC_PARENTGROUP, GeData_DescID(m_button_grp_id));
	m_button_editor_id = ddesc->Alloc(bc);
	bc = GetCustomDataTypeDefault(DTYPE_BUTTON);
	bc.SetString(DESC_NAME, GeLoadString(IDS_MORPH_DELETE));
	bc.SetInt32(DESC_CUSTOMGUI, CUSTOMGUI_BUTTON);
	bc.SetData(DESC_PARENTGROUP, GeData_DescID(m_button_grp_id));
	m_button_delete_id = ddesc->Alloc(bc);
	bc = GetCustomDataTypeDefault(DTYPE_BUTTON);
	bc.SetString(DESC_NAME, GeLoadString(IDS_MORPH_RENAME));
	bc.SetInt32(DESC_CUSTOMGUI, CUSTOMGUI_BUTTON);
	bc.SetData(DESC_PARENTGROUP, GeData_DescID(m_button_grp_id));
	m_button_rename_id = ddesc->Alloc(bc);
	auto& morph_arr = model->GetMorphDataWritable();
	auto& morph_name_map = model->GetMorphNameMapWritable();
	auto& DescID_map = model->GetDescIDMap();
	const auto& res = morph_arr.AppendPtr(this);
	iferr(res)
		return -1;
	auto index = static_cast<Int32>(morph_arr.GetIndex(*res.GetValue()));
	iferr(morph_name_map.Insert(morph_name, index))
		return-1;
	m_name = std::move(morph_name);
	iferr(DescID_map.Insert(m_strength_id, { DescType::REAL_STRENGTH, index }))
		return-1;
	iferr(DescID_map.Insert(m_button_editor_id, { DescType::BUTTON_EDITOR, index }))
		return-1;
	iferr(DescID_map.Insert(m_button_delete_id, { DescType::BUTTON_DELETE, index }))
		return-1;
	iferr(DescID_map.Insert(m_button_rename_id, { DescType::BUTTON_RENAME,  index }))
		return-1;
	SendCoreMessage(COREMSG_CINEMA, BaseContainer(COREMSG_CINEMA_FORCE_AM_UPDATE)); /* Refresh the AM to see the changes in real time */
	return index;
}
inline Int32 FlipMorph::AddMorphToModel(MMDModelObject* model, String morph_name)
{
	if (morph_name.IsEmpty())
	{
		morph_name = "[Flip morph]" + model->GetMorphNamedNumber();
	}
	DynamicDescription* const ddesc = model->Get()->GetDynamicDescriptionWritable();
	if (ddesc == nullptr)
		return -1;
	BaseContainer bc = GetCustomDataTypeDefault(DTYPE_GROUP);
	bc.SetString(DESC_NAME, morph_name);
	bc.SetData(DESC_PARENTGROUP, GeData_DescID(ConstDescID(DescLevel(MODEL_MORPH_FLIP_GRP))));
	m_grp_id = ddesc->Alloc(bc);
	bc = GetCustomDataTypeDefault(DTYPE_REAL);
	bc.SetString(DESC_NAME, morph_name);
	bc.SetFloat(DESC_MAX, 1.);
	bc.SetFloat(DESC_MIN, 0.);
	bc.SetInt32(DESC_CUSTOMGUI, CUSTOMGUI_REALSLIDER);
	bc.SetFloat(DESC_MAXSLIDER, 1.);
	bc.SetFloat(DESC_MINSLIDER, 0.);
	bc.SetFloat(DESC_STEP, 0.01);
	bc.SetInt32(DESC_UNIT, DESC_UNIT_PERCENT);
	bc.SetData(DESC_PARENTGROUP, GeData_DescID(m_grp_id));
	m_strength_id = ddesc->Alloc(bc);
	bc = GetCustomDataTypeDefault(DTYPE_GROUP);
	bc.SetInt32(DESC_COLUMNS, 3);
	bc.SetData(DESC_PARENTGROUP, GeData_DescID(m_grp_id));
	m_button_grp_id = ddesc->Alloc(bc);
	bc = GetCustomDataTypeDefault(DTYPE_BUTTON);
	bc.SetString(DESC_NAME, GeLoadString(IDS_MORPH_EDITOR));
	bc.SetInt32(DESC_CUSTOMGUI, CUSTOMGUI_BUTTON);
	bc.SetData(DESC_PARENTGROUP, GeData_DescID(m_button_grp_id));
	m_button_editor_id = ddesc->Alloc(bc);
	bc = GetCustomDataTypeDefault(DTYPE_BUTTON);
	bc.SetString(DESC_NAME, GeLoadString(IDS_MORPH_DELETE));
	bc.SetInt32(DESC_CUSTOMGUI, CUSTOMGUI_BUTTON);
	bc.SetData(DESC_PARENTGROUP, GeData_DescID(m_button_grp_id));
	m_button_delete_id = ddesc->Alloc(bc);
	bc = GetCustomDataTypeDefault(DTYPE_BUTTON);
	bc.SetString(DESC_NAME, GeLoadString(IDS_MORPH_RENAME));
	bc.SetInt32(DESC_CUSTOMGUI, CUSTOMGUI_BUTTON);
	bc.SetData(DESC_PARENTGROUP, GeData_DescID(m_button_grp_id));
	m_button_rename_id = ddesc->Alloc(bc);
	auto& morph_arr = model->GetMorphDataWritable();
	auto& morph_name_map = model->GetMorphNameMapWritable();
	auto& DescID_map = model->GetDescIDMap();
	const auto& res = morph_arr.AppendPtr(this);
	iferr(res)
		return -1;
	auto index = static_cast<Int32>(morph_arr.GetIndex(*res.GetValue()));
	iferr(morph_name_map.Insert(morph_name, index))
		return -1;
	m_name = std::move(morph_name);
	iferr(DescID_map.Insert(m_strength_id, { DescType::REAL_STRENGTH, index }))
		return -1;
	iferr(DescID_map.Insert(m_button_editor_id, { DescType::BUTTON_EDITOR, index }))
		return -1;
	iferr(DescID_map.Insert(m_button_delete_id, { DescType::BUTTON_DELETE, index }))
		return -1;
	iferr(DescID_map.Insert(m_button_rename_id, { DescType::BUTTON_RENAME,  index }))
		return -1;
	SendCoreMessage(COREMSG_CINEMA, BaseContainer(COREMSG_CINEMA_FORCE_AM_UPDATE)); /* Refresh the AM to see the changes in real time */
	return index;
}
inline Int32 MeshMorph::AddMorphToModel(MMDModelObject* model, String morph_name)
{
	if (morph_name.IsEmpty())
	{
		morph_name = "[Mesh morph]" + model->GetMorphNamedNumber();
	}
	DynamicDescription* const ddesc = model->Get()->GetDynamicDescriptionWritable();
	if (ddesc == nullptr)
		return-1;
	BaseContainer bc = GetCustomDataTypeDefault(DTYPE_REAL);
	bc.SetString(DESC_NAME, morph_name);
	bc.SetFloat(DESC_MAX, 1.);
	bc.SetFloat(DESC_MIN, 0.);
	bc.SetInt32(DESC_CUSTOMGUI, CUSTOMGUI_REALSLIDER);
	bc.SetFloat(DESC_MAXSLIDER, 1.);
	bc.SetFloat(DESC_MINSLIDER, 0.);
	bc.SetFloat(DESC_STEP, 0.01);
	bc.SetInt32(DESC_UNIT, DESC_UNIT_PERCENT);
	bc.SetData(DESC_PARENTGROUP, GeData_DescID(ConstDescID(DescLevel(MODEL_MORPH_MESH_GRP))));
	auto& morph_arr = model->GetMorphDataWritable();
	auto& morph_name_map = model->GetMorphNameMapWritable();
	auto& DescID_map = model->GetDescIDMap();
	const auto& res = morph_arr.AppendPtr(this);
	iferr(res)
		return -1;
	auto index = static_cast<Int32>(morph_arr.GetIndex(*res.GetValue()));
	iferr(morph_name_map.Insert(morph_name, index))
		return -1;
	m_name = std::move(morph_name);
	iferr(DescID_map.Insert(m_strength_id, { DescType::REAL_STRENGTH, index }))
		return -1;
	SendCoreMessage(COREMSG_CINEMA, BaseContainer(COREMSG_CINEMA_FORCE_AM_UPDATE)); /* Refresh the AM to see the changes in real time */
	return index;
}
inline Int32 BoneMorph::AddMorphToModel(MMDModelObject* model, String morph_name)
{
	if (morph_name.IsEmpty())
	{
		morph_name = "[Bone morph]" + model->GetMorphNamedNumber();
	}
	DynamicDescription* const ddesc = model->Get()->GetDynamicDescriptionWritable();
	if (ddesc == nullptr)
		return-1;
	BaseContainer bc = GetCustomDataTypeDefault(DTYPE_REAL);
	bc.SetString(DESC_NAME, morph_name);
	bc.SetFloat(DESC_MAX, 1.);
	bc.SetFloat(DESC_MIN, 0.);
	bc.SetInt32(DESC_CUSTOMGUI, CUSTOMGUI_REALSLIDER);
	bc.SetFloat(DESC_MAXSLIDER, 1.);
	bc.SetFloat(DESC_MINSLIDER, 0.);
	bc.SetFloat(DESC_STEP, 0.01);
	bc.SetInt32(DESC_UNIT, DESC_UNIT_PERCENT);
	bc.SetData(DESC_PARENTGROUP, GeData_DescID(ConstDescID(DescLevel(MODEL_MORPH_BONE_GRP))));
	m_strength_id = ddesc->Alloc(bc);
	auto& morph_arr = model->GetMorphDataWritable();
	auto& morph_name_map = model->GetMorphNameMapWritable();
	auto& DescID_map = model->GetDescIDMap();
	const auto& res = morph_arr.AppendPtr(this);
	iferr(res)
		return -1;
	auto index = static_cast<Int32>(morph_arr.GetIndex(*res.GetValue()));
	iferr(morph_name_map.Insert(morph_name, index))
		return -1;
	m_name = std::move(morph_name);
	iferr(DescID_map.Insert(m_strength_id, { DescType::REAL_STRENGTH, index }))
		return -1;
	SendCoreMessage(COREMSG_CINEMA, BaseContainer(COREMSG_CINEMA_FORCE_AM_UPDATE)); /* Refresh the AM to see the changes in real time */
	return index;
}
inline void GroupMorph::DeleteMorphOfModel(MMDModelObject* model)
{
	auto& morph_arr = model->GetMorphDataWritable();
	auto& morph_name_map = model->GetMorphNameMapWritable();
	auto& DescID_map = model->GetDescIDMap();
	const auto index = morph_arr.FindIndex(*this);
	if (index == -1)
		return;
	DynamicDescription* const ddesc = model->Get()->GetDynamicDescriptionWritable();
	if (ddesc == nullptr)
		return;
	ddesc->Remove(this->m_button_editor_id);
	ddesc->Remove(this->m_button_delete_id);
	ddesc->Remove(this->m_button_rename_id);
	ddesc->Remove(this->m_button_grp_id);
	ddesc->Remove(this->m_strength_id);
	ddesc->Remove(this->m_grp_id);
	iferr(DescID_map.Erase(this->m_strength_id))
		return;
	iferr(DescID_map.Erase(this->m_button_editor_id))
		return;
	iferr(DescID_map.Erase(this->m_button_delete_id))
		return;
	iferr(DescID_map.Erase(this->m_button_rename_id))
		return;
	for (auto& i : DescID_map.GetKeys())
	{
		if (Int32* map_index = &DescID_map.FindValue(i)->second; *map_index > index)
		{
			(*map_index)--;
		}
	}
	iferr(morph_name_map.Erase(this->m_name))
		return;
	for (auto& i : morph_name_map.GetKeys())
	{
		if (Int32* map_index = morph_name_map.FindValue(i); *map_index > index)
		{
			(*map_index)--;
		}
	}
	iferr(morph_arr.Erase(index))
		return;
	/* Refresh the AM to see the changes in real time */
	::SendCoreMessage(COREMSG_CINEMA, BaseContainer(COREMSG_CINEMA_FORCE_AM_UPDATE));
	if (::GeIsMainThread())
	{
		::EventAdd();
	}
}
inline void FlipMorph::DeleteMorphOfModel(MMDModelObject* model)
{
	auto& morph_arr = model->GetMorphDataWritable();
	auto& morph_name_map = model->GetMorphNameMapWritable();
	auto& DescID_map = model->GetDescIDMap();
	const Int32 index = morph_arr.FindIndex(*this);
	if (index == -1)
		return;
	DynamicDescription* const ddesc = model->Get()->GetDynamicDescriptionWritable();
	if (ddesc == nullptr)
		return;
	ddesc->Remove(this->m_button_editor_id);
	ddesc->Remove(this->m_button_delete_id);
	ddesc->Remove(this->m_button_rename_id);
	ddesc->Remove(this->m_button_grp_id);
	ddesc->Remove(this->m_strength_id);
	ddesc->Remove(this->m_grp_id);
	iferr(DescID_map.Erase(this->m_strength_id))
		return;
	iferr(DescID_map.Erase(this->m_button_editor_id))
		return;
	iferr(DescID_map.Erase(this->m_button_delete_id))
		return;
	iferr(DescID_map.Erase(this->m_button_rename_id))
		return;
	for (auto& i : DescID_map.GetKeys())
	{
		if (Int32* map_index = &DescID_map.FindValue(i)->second; *map_index > index)
		{
			(*map_index)--;
		}
	}
	iferr(morph_name_map.Erase(this->m_name))
		return;
	for (auto& i : morph_name_map.GetKeys())
	{
		if (Int32* map_index = morph_name_map.FindValue(i); *map_index > index)
		{
			(*map_index)--;
		}
	}
	iferr(morph_arr.Erase(index))
		return;
	/* Refresh the AM to see the changes in real time */
	::SendCoreMessage(COREMSG_CINEMA, BaseContainer(COREMSG_CINEMA_FORCE_AM_UPDATE));
	if (::GeIsMainThread())
	{
		::EventAdd();
	}
}
inline void MeshMorph::DeleteMorphOfModel(MMDModelObject* model)
{
	auto& morph_arr = model->GetMorphDataWritable();
	auto& morph_name_map = model->GetMorphNameMapWritable();
	auto& DescID_map = model->GetDescIDMap();
	const auto index = morph_arr.FindIndex(*this);
	if (index == -1)
		return;
	DynamicDescription* const ddesc = model->Get()->GetDynamicDescriptionWritable();
	if (ddesc == nullptr)
		return;
	ddesc->Remove(this->m_strength_id);
	iferr(DescID_map.Erase(this->m_strength_id))
		return;
	iferr(morph_name_map.Erase(this->m_name))
		return;
	for (auto& i : morph_name_map.GetKeys())
	{
		if (Int32* map_index = morph_name_map.FindValue(i); *map_index > index)
		{
			(*map_index)--;
		}
	}
	iferr(morph_arr.Erase(index))
		return;
	/* Refresh the AM to see the changes in real time */
	::SendCoreMessage(COREMSG_CINEMA, BaseContainer(COREMSG_CINEMA_FORCE_AM_UPDATE));
	if (::GeIsMainThread())
	{
		::EventAdd();
	}
}
inline void BoneMorph::DeleteMorphOfModel(MMDModelObject* model)
{
	auto& morph_arr = model->GetMorphDataWritable();
	auto& morph_name_map = model->GetMorphNameMapWritable();
	auto& DescID_map = model->GetDescIDMap();
	const auto index = morph_arr.FindIndex(*this);
	if (index == -1)
		return;
	DynamicDescription* const ddesc = model->Get()->GetDynamicDescriptionWritable();
	if (ddesc == nullptr)
		return;
	ddesc->Remove(this->m_strength_id);
	iferr(DescID_map.Erase(this->m_strength_id))
		return;
	iferr(morph_name_map.Erase(this->m_name))
		return;
	for (auto& i : morph_name_map.GetKeys())
	{
		if (Int32* map_index = morph_name_map.FindValue(i); *map_index > index)
		{
			(*map_index)--;
		}
	}
	iferr(morph_arr.Erase(index))
		return;
	/* Refresh the AM to see the changes in real time */
	::SendCoreMessage(COREMSG_CINEMA, BaseContainer(COREMSG_CINEMA_FORCE_AM_UPDATE));
	if (::GeIsMainThread())
	{
		::EventAdd();
	}
}
inline void GroupMorph::AddSubMorph(MMDModelObject* model, Int32 id, const Float weight)
{
	if (model->GetMorphNameMap().Find(id) != nullptr) {
		 std::ignore = m_data.Insert(id, weight);
	}
}
inline void FlipMorph::AddSubMorph(MMDModelObject* model, Int32 id, const Float weight)
{
	if (model->GetMorphNameMap().Find(id) != nullptr) {
		std::ignore = m_data.Insert(id, weight);
	}
}
inline void GroupMorph::AddSubMorphNoCheck(Int32 id, const Float weight)
{
	std::ignore = m_data.Insert(id, weight);
}
inline auto FlipMorph::AddSubMorphNoCheck(Int32 id, const Float weight) -> void
{
	std::ignore = m_data.Insert(id, weight);
}
Bool MMDModelObject::Init(GeListNode* node SDK2024_InitPara)
{
	if (node == nullptr)
		return false;
	BaseContainer* bc = reinterpret_cast<BaseList2D*>(node)->GetDataInstance();
	if (bc == nullptr)
		return false;
	bc->SetString(ID_BASELIST_NAME, GeLoadString(IDS_O_MMD_MODEL));
	bc->SetFloat(PMX_VERSION, 2.0);
	bc->SetString(MODEL_NAME_LOCAL, "model"_s);
	bc->SetString(MODEL_NAME_UNIVERSAL, "model"_s);
	bc->SetString(COMMENTS_LOCAL, "description"_s);
	bc->SetString(COMMENTS_UNIVERSAL, "description"_s);
	return true;
}
Bool MMDModelObject::Read(GeListNode* node, HyperFile* hf, Int32 level) {
	if (level >= 1) {
		AutoAlloc<BaseLink> mesh_root_link;
		if (mesh_root_link == nullptr)
			return false;
		AutoAlloc<BaseLink> rigid_root_link;
		if (rigid_root_link == nullptr)
			return false;
		AutoAlloc<BaseLink> joint_root_link;
		if (joint_root_link == nullptr)
			return false;
		AutoAlloc<BaseLink> bone_root_link;
		if (bone_root_link == nullptr)
			return false;
		if (!mesh_root_link->Read(hf))
			return false;
		if (!rigid_root_link->Read(hf))
			return false;
		if (!joint_root_link->Read(hf))
			return false;
		if (!bone_root_link->Read(hf))
			return false;
		this->m_MeshRoot_ptr = reinterpret_cast<BaseObject*>(mesh_root_link->ForceGetLink());
		this->m_RigidRoot_ptr = reinterpret_cast<BaseObject*>(rigid_root_link->ForceGetLink());
		this->m_JointRoot_ptr = reinterpret_cast<BaseObject*>(joint_root_link->ForceGetLink());
		this->m_BoneRoot_ptr = reinterpret_cast<BaseObject*>(bone_root_link->ForceGetLink());
	}
	if (level >= 2) {
		if (!hf->ReadInt32(&m_morph_named_number))
			return false;
		Int data_count = 0;
		if (!hf->ReadInt64(&data_count))
			return false;
		for (Int i = 0; i < data_count; ++i)
		{
			DescID id;
			if (!id.Read(hf))
				return false;
			auto& val = m_DescID_map.InsertKey(id).GetValue();
			
			if (UChar type = 0; !hf->ReadUChar(&type))
			{
				val.first = static_cast<DescType>(type);
			}
			else
			{
				return false;
			}
			if (!hf->ReadInt32(&val.second))
				return false;
		}
		if (!hf->ReadInt64(&data_count))
			return false;
		for (Int i = 0; i < data_count; ++i)
		{
			String name;
			if (!hf->ReadString(&name))
				return false;
			auto& val = m_morph_name_map.InsertKey(std::move(name)).GetValue();
			if (!hf->ReadInt32(&val))
				return false;
		}
		if (!ReadMorph(hf))
			return false;
		*m_is_morph_initialized.Write() = true;
	}
	return true;
}
Bool MMDModelObject::Write(SDK2024_Const GeListNode* node, HyperFile* hf) SDK2024_Const {
	// level >= 1
	AutoAlloc<BaseLink> mesh_root_link;
	if (mesh_root_link == nullptr)
		return false;
	AutoAlloc<BaseLink> rigid_root_link;
	if (rigid_root_link == nullptr)
		return false;
	AutoAlloc<BaseLink> joint_root_link;
	if (joint_root_link == nullptr)
		return false;
	AutoAlloc<BaseLink> bone_root_link;
	if (bone_root_link == nullptr)
		return false;
	mesh_root_link->SetLink(this->m_MeshRoot_ptr);
	rigid_root_link->SetLink(this->m_RigidRoot_ptr);
	joint_root_link->SetLink(this->m_JointRoot_ptr);
	bone_root_link->SetLink(this->m_BoneRoot_ptr);
	if (!mesh_root_link->Write(hf))
		return false;
	if (!rigid_root_link->Write(hf))
		return false;
	if (!joint_root_link->Write(hf))
		return false;
	if (!bone_root_link->Write(hf))
		return false;
	// level >=  2
	if (!hf->WriteInt32(m_morph_named_number))
		return false;
	if (!hf->WriteInt64(m_DescID_map.GetCount()))
		return false;
	for (auto& i : m_DescID_map)
	{
		if (!i.GetKey().Write(hf))
			return false;
		auto& val = i.GetValue();
		if (!hf->WriteUChar(static_cast<uint8_t>(val.first)))
			return false;
		if (!hf->WriteInt32(val.second))
			return false;
	}
	if (!hf->WriteInt64(m_morph_name_map.GetCount()))
		return false;
	for (auto& i : m_morph_name_map)
	{
		if (!hf->WriteString(i.GetKey()))
			return false;
		if (!hf->WriteInt32(i.GetValue()))
			return false;
	}
	if (!WriteMorph(hf))
		return false;
	return true;
}
Bool MMDModelObject::CopyTo(NodeData* dest, SDK2024_Const GeListNode* snode, GeListNode* dnode, COPYFLAGS flags, AliasTrans* trn) SDK2024_Const
{
	MMDModelObject* const destObject = static_cast<MMDModelObject*>(dest);
	destObject->m_BoneRoot_ptr = this->m_BoneRoot_ptr;
	destObject->m_JointRoot_ptr = this->m_JointRoot_ptr;
	destObject->m_RigidRoot_ptr = this->m_RigidRoot_ptr;
	destObject->m_MeshRoot_ptr = this->m_MeshRoot_ptr;
	iferr(destObject->m_DescID_map.CopyFrom(this->m_DescID_map))
		return false;
	iferr(destObject->m_morph_name_map.CopyFrom(this->m_morph_name_map))
		return false;
	if (!CopyMorph(destObject))
		return false;
	return true;
}
Bool MMDModelObject::ReadMorph(HyperFile* hf)
{
	iferr_scope_handler{ return nullptr; };
	AddMorphHelper add_helper = BeginMorphChange();
	Int data_count = 0;
	if (!hf->ReadInt64(&data_count))
		return false;
	for (Int i = 0; i < data_count; ++i)
	{

		Int64 data = 0;
		if (!hf->ReadInt64(&data))
			return false;
		MorphType type = static_cast<MorphType>(data);
		IMorph* res = nullptr;
		switch (type)
		{
		case MorphType::GROUP:
		{
			res = NewObj(GroupMorph).GetValue();
			break;
		}
		case MorphType::FLIP:
		{
			res = NewObj(FlipMorph).GetValue();
			break;
		}
		case MorphType::MESH:
		{
			res = NewObj(MeshMorph).GetValue();
			break;
		}
		case MorphType::BONE:
		{
			res = NewObj(BoneMorph).GetValue();
			break;
		}
		case MorphType::DEFAULT:
		default:
			break;
		}
		res->Read(hf);
		GetMorphData().AppendPtr(res)iferr_return;
	}
	return true;
}
Bool MMDModelObject::WriteMorph(HyperFile* hf) const
{
	if (!hf->WriteInt64(m_morph_arr.GetCount()))
		return false;
	for (const auto& i : m_morph_arr)
	{
		if (!i.Write(hf))
			return false;
	}
	return true;
}
Bool MMDModelObject::CopyMorph(MMDModelObject* dst) const
{
	iferr_scope_handler{ return false; };
	for (const auto& morph : m_morph_arr)
	{
		IMorph* new_morph = nullptr;
		switch (morph.GetType())
		{
		case MorphType::GROUP:
		{
			new_morph = NewObj(GroupMorph)iferr_return;

			break;
		}
		case MorphType::FLIP:
		{
			new_morph = NewObj(FlipMorph)iferr_return;
			break;
		}
		case MorphType::MESH:
		{
			new_morph = NewObj(MeshMorph)iferr_return;
			break;
		}
		case MorphType::BONE:
		{
			new_morph = NewObj(BoneMorph)iferr_return;
			break;
		}
		case MorphType::DEFAULT:
		default:
			break;
		}
		if (!morph.CopyTo(new_morph))
			return true;
		dst->GetMorphDataWritable().AppendPtr(new_morph)iferr_return;
	}
	return true;
}
void MMDModelObject::RefreshMorph()
{
	iferr_scope_handler{ return; };
	Int64 morph_count = m_morph_arr.GetCount();
	for (Int64 morph_index = 0; morph_index < morph_count; ++morph_index)
	{
		auto& morph = m_morph_arr[morph_index];
		if (morph.IsMeshMorph() || morph.IsBoneMorph()) {
			morph.DeleteMorphOfModel(this);
			morph_index--;
			morph_count = m_morph_arr.GetCount();
		}
	}
	auto& mesh_morph_map = m_MeshRoot_ptr->GetNodeData<MMDMeshRootObject>()->GetMeshMorphMap();
	for (auto& name : mesh_morph_map.GetKeys())
	{
		auto* morph = NewObj(MeshMorph)iferr_return;
		morph->AddMorphToModel(this, name);
	}
	auto& bone_morph_map = m_BoneRoot_ptr->GetNodeData<OMMDBoneRoot>()->GetBoneMorphMap();
	for (auto& name : bone_morph_map.GetKeys())
	{
		auto* morph = NewObj(BoneMorph)iferr_return;
		morph->AddMorphToModel(this, name);
	}
}
Bool MMDModelObject::UpdateRoot(BaseObject* op)
{
	if (op == nullptr)
		op = static_cast<BaseObject*>(Get());
	BaseObject* MeshRoot_ = nullptr;
	BaseObject* BoneRoot_ = nullptr;
	BaseObject* RigidRoot_ = nullptr;
	BaseObject* JointRoot_ = nullptr;
	maxon::Queue<BaseObject*>	nodes;
	iferr(nodes.Push(op->GetDown())) return false;
	while (!nodes.IsEmpty())
	{
		BaseObject* node = *nodes.Pop();
		if (node != nullptr)
		{
			if (node->IsInstanceOf(ID_O_MMD_JOINT_ROOT))
				JointRoot_ = node;
			else if (node->IsInstanceOf(ID_O_MMD_RIGID_ROOT))
				RigidRoot_ = node;
			else if (node->IsInstanceOf(ID_O_MMD_BONE_ROOT))
				BoneRoot_ = node;
			else if (node->IsInstanceOf(ID_O_MMD_MESH_ROOT))
				MeshRoot_ = node;
			iferr(nodes.Push(node->GetNext())) return false;
		}
	}
	nodes.Reset();
	if (m_JointRoot_ptr == nullptr) {
		if (JointRoot_ == nullptr)
		{
			BaseObject* tmp = BaseObject::Alloc(ID_O_MMD_JOINT_ROOT);
			tmp->InsertUnder(op);
			this->m_JointRoot_ptr = tmp;
		}
		else {
			this->m_JointRoot_ptr = JointRoot_;
		}
		m_is_root_initialized = false;
	}
	if (m_RigidRoot_ptr == nullptr) {
		if (RigidRoot_ == nullptr)
		{
			BaseObject* tmp = BaseObject::Alloc(ID_O_MMD_RIGID_ROOT);
			tmp->InsertUnder(op);
			this->m_RigidRoot_ptr = tmp;
		}
		else {
			this->m_RigidRoot_ptr = RigidRoot_;
		}
		m_is_root_initialized = false;
	}
	if (m_BoneRoot_ptr == nullptr) {
		if (BoneRoot_ == nullptr)
		{
			BaseObject* tmp = BaseObject::Alloc(ID_O_MMD_BONE_ROOT);
			tmp->InsertUnder(op);
			this->m_BoneRoot_ptr = tmp;
		}
		else {
			this->m_BoneRoot_ptr = BoneRoot_;
		}
		m_is_root_initialized = false;
	}
	if (m_MeshRoot_ptr == nullptr) {
		if (MeshRoot_ == nullptr)
		{
			BaseObject* tmp = BaseObject::Alloc(ID_O_MMD_MESH_ROOT);
			tmp->InsertUnder(op);
			this->m_MeshRoot_ptr = tmp;
		}
		else {
			this->m_MeshRoot_ptr = MeshRoot_;
		}
		m_is_root_initialized = false;
	}
	if (m_is_root_initialized == false) {
		const maxon::StrongRef<OMMDModel_MSG> MeshRoot_msg(
			NewObj(OMMDModel_MSG, OMMDModel_MSG_Type::TOOL_OBJECT_UPDATA, ToolObjectType::Model, op).GetValue());
		this->m_MeshRoot_ptr->Message(ID_O_MMD_MODEL, MeshRoot_msg);
		const maxon::StrongRef<OMMDModel_MSG> BoneRoot_msgA(
			NewObj(OMMDModel_MSG, OMMDModel_MSG_Type::TOOL_OBJECT_UPDATA, ToolObjectType::RigidRoot, this->m_RigidRoot_ptr).GetValue());
		this->m_BoneRoot_ptr->Message(ID_O_MMD_MODEL, BoneRoot_msgA);
		const maxon::StrongRef<OMMDModel_MSG> BoneRoot_msgB(
			NewObj(OMMDModel_MSG, OMMDModel_MSG_Type::TOOL_OBJECT_UPDATA, ToolObjectType::JointRoot, this->m_JointRoot_ptr).GetValue());
		this->m_BoneRoot_ptr->Message(ID_O_MMD_MODEL, BoneRoot_msgB);
		const maxon::StrongRef<OMMDModel_MSG> BoneRoot_msgC(
			NewObj(OMMDModel_MSG, OMMDModel_MSG_Type::TOOL_OBJECT_UPDATA, ToolObjectType::Model, op).GetValue());
		this->m_BoneRoot_ptr->Message(ID_O_MMD_MODEL, BoneRoot_msgC);
		const maxon::StrongRef<OMMDModel_MSG> RigidRoot_msgA(
			NewObj(OMMDModel_MSG, OMMDModel_MSG_Type::TOOL_OBJECT_UPDATA, ToolObjectType::BoneRoot, this->m_BoneRoot_ptr).GetValue());
		this->m_RigidRoot_ptr->Message(ID_O_MMD_MODEL, RigidRoot_msgA);
		const maxon::StrongRef<OMMDModel_MSG> RigidRoot_msgB(
			NewObj(OMMDModel_MSG, OMMDModel_MSG_Type::TOOL_OBJECT_UPDATA, ToolObjectType::JointRoot, this->m_JointRoot_ptr).GetValue());
		this->m_RigidRoot_ptr->Message(ID_O_MMD_MODEL, RigidRoot_msgB);
		const maxon::StrongRef<OMMDModel_MSG> JointRoot_msgA(
			NewObj(OMMDModel_MSG, OMMDModel_MSG_Type::TOOL_OBJECT_UPDATA, ToolObjectType::BoneRoot, this->m_BoneRoot_ptr).GetValue());
		this->m_JointRoot_ptr->Message(ID_O_MMD_MODEL, JointRoot_msgA);
		const maxon::StrongRef<OMMDModel_MSG> JointRoot_msgB(
			NewObj(OMMDModel_MSG, OMMDModel_MSG_Type::TOOL_OBJECT_UPDATA, ToolObjectType::RigidRoot, this->m_RigidRoot_ptr).GetValue());
		this->m_JointRoot_ptr->Message(ID_O_MMD_MODEL, JointRoot_msgB);
		m_is_root_initialized = true;
	}
	return true;
}
EXECUTIONRESULT MMDModelObject::Execute(BaseObject* op, BaseDocument* doc, BaseThread* bt, Int32 priority, EXECUTIONFLAGS flags)
{
	if (op == nullptr || doc == nullptr)
	{
		return EXECUTIONRESULT::OK;
	}
	if (UpdateRoot(op) == false)
		return EXECUTIONRESULT::OK;
	if (*m_is_morph_initialized.Read() == false)
	{
		this->RefreshMorph();
		*m_is_morph_initialized.Write() = true;
	}
	if (*m_is_need_update.Read() == true)
	{
		for (auto& morph : m_morph_arr)
		{
			morph.UpdateMorphOfModel(this);
		}
	}
	return EXECUTIONRESULT::OK;
}
Int32 MMDModelObject::ImportGroupAndFlipMorph(const PMXModel* pmx_model, libmmd::pmx_morph& pmx_morph)
{
	iferr_scope_handler{ return -1; };
	switch (pmx_morph.get_morph_offset_type())
	{
	case libmmd::pmx_morph::morph_type::GROUP:
	{
		const auto morph = NewObj(GroupMorph)iferr_return;
		const auto& morph_offset_array = pmx_morph.get_morph_offset_array();
		const auto morph_offset_array_num = morph_offset_array.size();
		for (size_t morph_offset_index = 0; morph_offset_index < morph_offset_array_num; ++morph_offset_index)
		{
			auto& morph_offset = dynamic_cast<const libmmd::pmx_group_morph_offset&>(morph_offset_array[morph_offset_index]);
			morph->AddSubMorphNoCheck(morph_offset.get_morph_index(), morph_offset.get_morph_weight());
		}
		return morph->AddMorphToModel(this, String(pmx_morph.get_morph_name_local().c_str()));
	}
	case libmmd::pmx_morph::morph_type::FLIP:
	{
		const auto morph = NewObj(FlipMorph)iferr_return;
		const auto& morph_offset_array = pmx_morph.get_morph_offset_array();
		const auto morph_offset_array_num = morph_offset_array.size();
		for (size_t morph_offset_index = 0; morph_offset_index < morph_offset_array_num; ++morph_offset_index)
		{
			auto& morph_offset = dynamic_cast<const libmmd::pmx_flip_morph_offset&>(morph_offset_array[morph_offset_index]);
			morph->AddSubMorphNoCheck(morph_offset.get_morph_index(), morph_offset.get_morph_weight());
		}
		return morph->AddMorphToModel(this, String(pmx_morph.get_morph_name_local().c_str()));
	}
	default:
		return -1;
	}
}
Bool MMDModelObject::CreateRoot()
{
	const BaseDocument* doc = GetActiveDocument();
	if (const auto op = reinterpret_cast<BaseObject*>(Get()); op != nullptr && doc != nullptr)
	{
		if (this->m_JointRoot_ptr == nullptr)
		{
			BaseObject* joint_root_object = BaseObject::Alloc(ID_O_MMD_JOINT_ROOT);
			joint_root_object->InsertUnder(op);
			this->m_JointRoot_ptr = joint_root_object;
		}
		if (this->m_RigidRoot_ptr == nullptr)
		{
			BaseObject* rigid_root_object = BaseObject::Alloc(ID_O_MMD_RIGID_ROOT);
			rigid_root_object->InsertUnder(op);
			this->m_RigidRoot_ptr = rigid_root_object;
		}
		if (this->m_BoneRoot_ptr == nullptr)
		{
			BaseObject* bone_root_object = BaseObject::Alloc(ID_O_MMD_BONE_ROOT);
			bone_root_object->InsertUnder(op);
			this->m_BoneRoot_ptr = bone_root_object;
		}
		if (this->m_MeshRoot_ptr == nullptr)
		{
			BaseObject* mesh_root_object = BaseObject::Alloc(ID_O_MMD_MESH_ROOT);
			mesh_root_object->InsertUnder(op);
			this->m_MeshRoot_ptr = mesh_root_object;
		}
		return true;
	}
	return false;
}
Bool MMDModelObject::AddToExecution(BaseObject* op, PriorityList* list)
{
	if (list == nullptr || op == nullptr)
	{
		return true;
	}
	list->Add(op, EXECUTIONPRIORITY_EXPRESSION - 1, EXECUTIONFLAGS::NONE);
	return true;
}
Bool MMDModelObject::GetDDescription(SDK2024_Const GeListNode* node, Description* description, DESCFLAGS_DESC& flags) SDK2024_Const
{
	if (!description->LoadDescription("MMDModelObject"_s))
		return false;
	const DescID* singleid = description->GetSingleDescID();
	if (singleid == nullptr)
	{
		return SUPER::GetDDescription(node, description, flags);
	}
	MAXON_SCOPE
	{
		if (const auto cid = ConstDescID(DescLevel(MODEL_INFO_GRP)); singleid == nullptr || cid.IsPartOf(*singleid, nullptr))
		{
			if (BaseContainer* settings = description->GetParameterI(cid, nullptr))
				settings->SetBool(DESC_GROUPSCALEV, true);
		}
	}
	flags |= DESCFLAGS_DESC::LOADED;

	return SUPER::GetDDescription(node, description, flags);
}
Bool MMDModelObject::Message(GeListNode* node, Int32 type, void* data)
{
	iferr_scope_handler{ return SUPER::Message(node,type,data); };
	switch (type)
	{
	case ID_O_MMD_MESH_ROOT:
	{
		OMMDMeshRoot_MSG* msg = static_cast<OMMDMeshRoot_MSG*>(data);
		if (msg->type == OMMDMeshRoot_MSG_Type::MESH_MORPH_CHANGE) {
			*m_is_morph_initialized.Write() = false;
		}
		break;
	}
	case ID_O_MMD_BONE_ROOT:
	{
		OMMDBoneRoot_MSG* msg = static_cast<OMMDBoneRoot_MSG*>(data);
		if (msg->type == OMMDBoneRoot_MSG_Type::BONE_MORPH_CHANGE) {
			*m_is_morph_initialized.Write() = false;
		}
		break;
	}
	case MSG_DESCRIPTION_COMMAND:
	{
		/* check if it is a user data button */
		if (auto* dc = static_cast<DescriptionCommand*>(data); dc->_descId[0].id == ID_USERDATA)
		{
			if (auto DescID_ptr = m_DescID_map.Find(dc->_descId); DescID_ptr != nullptr)
			{
				auto& descid_data = DescID_ptr->GetValue();
				auto& morph = m_morph_arr[descid_data.second];
				switch (descid_data.first)
				{
				case DescType::BUTTON_EDITOR:
				{
					EditorSubMorphDialog dlg(this, &morph);
					dlg.Open(DLG_TYPE::MODAL, 100000, -1, -1, 0, 0);
					break;
				}
				case  DescType::BUTTON_DELETE:
				{
					if (QuestionDialog(IDS_MES_BONE_MORPH_DELETE, morph.GetName())) {
						morph.DeleteMorphOfModel(this);
					}
					break;
				}
				case DescType::BUTTON_RENAME:
				{
					utility::RenameDialog dlg;
					dlg.Open(DLG_TYPE::MODAL, 100001, -1, -1, 0, 0);
					if (!dlg.Rename.IsEmpty())
					{
						morph.RenameMorph(this, dlg.Rename);
					}
					break;
				}
				case DescType::REAL_STRENGTH:
					break;
				default:
					break;
				}
			}
		}
		else {
			switch (dc->_descId[0].id)
			{
			case MODEL_MORPH_GROUP_ADD_BUTTON:
			{
				GeData Ge_data;
				node->GetParameter(ConstDescID(DescLevel(MODEL_MORPH_GROUP_ADD_NAME)), Ge_data, DESCFLAGS_GET::NONE);
				String morph_name = Ge_data.GetString();
				IMorph* morph = NewObj(GroupMorph)iferr_return;
				morph->AddMorphToModel(this, morph_name);
				break;
			}
			case MODEL_MORPH_FLIP_ADD_BUTTON:
			{
				GeData Ge_data;
				node->GetParameter(ConstDescID(DescLevel(MODEL_MORPH_FLIP_ADD_NAME)), Ge_data, DESCFLAGS_GET::NONE);
				String morph_name = Ge_data.GetString();
				IMorph* morph = NewObj(FlipMorph)iferr_return;
				morph->AddMorphToModel(this, morph_name);
				break;
			}
			case MODEL_DEL_BONE_ANIM_BUTTON:
			{
				BaseDocument* doc = GetActiveDocument();
				if (doc == nullptr)
				{
					GePrint("error"_s);
					MessageDialog("error"_s);
					return true;
				}
				auto* op = static_cast<BaseObject*>(node);
				if (op == nullptr)
				{
					GePrint(GeLoadString(IDS_MES_SELECT_ERR));
					MessageDialog(GeLoadString(IDS_MES_SELECT_ERR));
					return true;
				}
				CTrack* ModelEditorDisplayTrack = op->FindCTrack(ConstDescID(DescLevel(ID_BASEOBJECT_VISIBILITY_EDITOR)));
				CTrack::Free(ModelEditorDisplayTrack);
				op->SetParameter(ConstDescID(DescLevel(ID_BASEOBJECT_VISIBILITY_EDITOR)), 2, DESCFLAGS_SET::NONE);
				CTrack* ModelRenderDisplayTrack = op->FindCTrack(ConstDescID(DescLevel(ID_BASEOBJECT_VISIBILITY_RENDER)));
				op->SetParameter(ConstDescID(DescLevel(ID_BASEOBJECT_VISIBILITY_RENDER)), 2, DESCFLAGS_SET::NONE);
				CTrack::Free(ModelRenderDisplayTrack);
				if (QuestionDialog(IDS_MES_DELETE_BONE_ANIM))
				{
					maxon::Queue<BaseObject*> nodes;
					iferr(nodes.Push(op)) return true;
					while (!nodes.IsEmpty())
					{
						BaseObject* node_ = *nodes.Pop();
						while (node_ != nullptr)
						{
							if (node_->GetType() == Ojoint)
							{
								BaseTag* const node_bone_tag = node_->GetTag(ID_T_MMD_BONE);
								if (node_bone_tag != nullptr)
								{
									TMMDBone* pmx_bone_tag_data = node_bone_tag->GetNodeData<TMMDBone>();
									const Int32	BoneMorphCount = (Int32)pmx_bone_tag_data->GetMorphCount();
									for (Int32 index = 0; index < BoneMorphCount; index++)
									{
										auto* bone_morph = pmx_bone_tag_data->GetMorph(index);
										if (bone_morph == nullptr)
											break;
										CTrack* morph_track = node_bone_tag->FindCTrack(bone_morph->strength_id);
										CTrack::Free(morph_track);
										node_bone_tag->SetParameter(bone_morph->strength_id, 0, DESCFLAGS_SET::NONE);
									}
									pmx_bone_tag_data->DeleteAllKeyFrame();
								}
								else {
									CTrack* BoneTrack_position_x = node_->FindCTrack(ConstDescID(DescLevel(ID_BASEOBJECT_REL_POSITION), DescLevel(VECTOR_X)));
									CTrack::Free(BoneTrack_position_x);
									CTrack* BoneTrack_position_y = node_->FindCTrack(ConstDescID(DescLevel(ID_BASEOBJECT_REL_POSITION), DescLevel(VECTOR_Y)));
									CTrack::Free(BoneTrack_position_y);
									CTrack* BoneTrack_position_z = node_->FindCTrack(ConstDescID(DescLevel(ID_BASEOBJECT_REL_POSITION), DescLevel(VECTOR_Z)));
									CTrack::Free(BoneTrack_position_z);
									CTrack* BoneTrack_rotation_x = node_->FindCTrack(ConstDescID(DescLevel(ID_BASEOBJECT_REL_ROTATION), DescLevel(VECTOR_X)));
									CTrack::Free(BoneTrack_rotation_x);
									CTrack* BoneTrack_rotation_y = node_->FindCTrack(ConstDescID(DescLevel(ID_BASEOBJECT_REL_ROTATION), DescLevel(VECTOR_Y)));
									CTrack::Free(BoneTrack_rotation_y);
									CTrack* BoneTrack_rotation_z = node_->FindCTrack(ConstDescID(DescLevel(ID_BASEOBJECT_REL_ROTATION), DescLevel(VECTOR_Z)));
									CTrack::Free(BoneTrack_rotation_z);
									node_->SetRelPos(Vector{});
									node_->SetRelRot(Vector{});
								}
								BaseTag* const node_ik_tag = node_->GetTag(1019561); /* IK tag */
								if (node_ik_tag != nullptr)
								{
									CTrack* ik_enable_track = node_ik_tag->FindCTrack(ConstDescID(DescLevel(ID_CA_IK_TAG_ENABLE)));
									CTrack::Free(ik_enable_track);
									node_ik_tag->SetParameter(ConstDescID(DescLevel(ID_CA_IK_TAG_ENABLE)), true, DESCFLAGS_SET::NONE);
								}
							}
							iferr(nodes.Push(node_->GetDown())) return true;
							if (node_ != op)
							{
								node_ = node_->GetNext();
							}
							else {
								break;
							}
						}
					}
					nodes.Reset();
					EventAdd();
					doc->SetTime(BaseTime(1, 30));
					doc->SetTime(BaseTime(0, 30));
				}
				break;
			}
			case MODEL_DEL_MORPH_ANIM_BUTTON:
			{
				BaseDocument* doc = GetActiveDocument();
				if (doc == nullptr)
				{
					GePrint("error"_s);
					MessageDialog("error"_s);
					return true;
				}
				BaseObject* op = static_cast<BaseObject*>(node);
				if (op == nullptr)
				{
					GePrint(GeLoadString(IDS_MES_SELECT_ERR));
					MessageDialog(GeLoadString(IDS_MES_SELECT_ERR));
					return true;
				}
				if (QuestionDialog(IDS_MES_DELETE_MORPH_ANIM))
				{
					maxon::Queue<BaseObject*> nodes;
					iferr(nodes.Push(op)) return true;
					while (!nodes.IsEmpty())
					{
						BaseObject* node_ = *nodes.Pop();
						while (node_ != nullptr)
						{
							if (node_->GetType() == Ojoint)
							{
								BaseTag* const node_bone_tag = node_->GetTag(ID_T_MMD_BONE);
								if (node_bone_tag != nullptr)
								{
									TMMDBone* pmx_bone_tag_data = node_bone_tag->GetNodeData<TMMDBone>();
									const Int32	BoneMorphCount = (Int32)pmx_bone_tag_data->GetMorphCount();
									for (Int32 index = 0; index < BoneMorphCount; index++)
									{
										auto* bone_morph = pmx_bone_tag_data->GetMorph(index);
										if (bone_morph == nullptr)
											break;
										CTrack* morph_track = node_bone_tag->FindCTrack(bone_morph->strength_id);
										CTrack::Free(morph_track);
										node_bone_tag->SetParameter(bone_morph->strength_id, 0, DESCFLAGS_SET::NONE);
									}
								}
							}
							BaseTag* const node_morph_tag = node_->GetTag(Tposemorph);
							if (node_morph_tag != nullptr)
							{
								CAPoseMorphTag* const	pose_morph_tag = static_cast<CAPoseMorphTag*>(node_morph_tag);
								const Int32		MorphCount = pose_morph_tag->GetMorphCount();
								for (Int32 index = 0; index < MorphCount; index++)
								{
									CTrack* morph_track = node_morph_tag->FindCTrack(pose_morph_tag->GetMorphID(index));
									CTrack::Free(morph_track);
									pose_morph_tag->GetMorph(index)->SetStrength(0);
								}
							}
							iferr(nodes.Push(node_->GetDown())) return true;
							if (node_ != op)
							{
								node_ = node_->GetNext();
							}
							else {
								break;
							}
						}
					}
					nodes.Reset();
					EventAdd();
					doc->SetTime(BaseTime(1, 30));
					doc->SetTime(BaseTime(0, 30));
				}
				break;
			}
			case MODEL_DEL_ALL_ANIM_BUTTON:
			{
				BaseDocument* doc = GetActiveDocument();
				if (doc == nullptr)
				{
					return true;
				}
				auto op = reinterpret_cast<BaseObject*>(node);
				if (op == nullptr)
				{
					GePrint(GeLoadString(IDS_MES_SELECT_ERR));
					MessageDialog(GeLoadString(IDS_MES_SELECT_ERR));
					return true;
				}
				if (QuestionDialog(IDS_MES_DELETE_ALL_ANIM))
				{
					CTrack* ModelEditorDisplayTrack = op->FindCTrack(ConstDescID(DescLevel(ID_BASEOBJECT_VISIBILITY_EDITOR)));
					CTrack::Free(ModelEditorDisplayTrack);
					op->SetParameter(ConstDescID(DescLevel(ID_BASEOBJECT_VISIBILITY_EDITOR)), 2, DESCFLAGS_SET::NONE);
					CTrack* ModelRenderDisplayTrack = op->FindCTrack(ConstDescID(DescLevel(ID_BASEOBJECT_VISIBILITY_RENDER)));
					op->SetParameter(ConstDescID(DescLevel(ID_BASEOBJECT_VISIBILITY_RENDER)), 2, DESCFLAGS_SET::NONE);
					CTrack::Free(ModelRenderDisplayTrack);
					maxon::Queue<BaseObject*> nodes;
					iferr(nodes.Push(op)) return true;
					while (!nodes.IsEmpty())
					{
						BaseObject* node_ = *nodes.Pop();
						while (node_ != nullptr)
						{
							if (node_->GetType() == Ojoint)
							{
								if (BaseTag* const node_bone_tag = node_->GetTag(ID_T_MMD_BONE); node_bone_tag != nullptr)
								{
									TMMDBone* pmx_bone_tag_data = node_bone_tag->GetNodeData<TMMDBone>();
									const auto BoneMorphCount = static_cast<Int32>(pmx_bone_tag_data->GetMorphCount());
									for (Int32 index = 0; index < BoneMorphCount; index++)
									{
										auto* bone_morph = pmx_bone_tag_data->GetMorph(index);
										if (bone_morph == nullptr)
											break;
										CTrack* morph_track = node_bone_tag->FindCTrack(bone_morph->strength_id);
										CTrack::Free(morph_track);
										node_bone_tag->SetParameter(bone_morph->strength_id, 0, DESCFLAGS_SET::NONE);
									}
									pmx_bone_tag_data->DeleteAllKeyFrame();
								}
								else {
									CTrack* BoneTrack_position_x = node_->FindCTrack(ConstDescID(DescLevel(ID_BASEOBJECT_REL_POSITION), DescLevel(VECTOR_X)));
									CTrack::Free(BoneTrack_position_x);
									CTrack* BoneTrack_position_y = node_->FindCTrack(ConstDescID(DescLevel(ID_BASEOBJECT_REL_POSITION), DescLevel(VECTOR_Y)));
									CTrack::Free(BoneTrack_position_y);
									CTrack* BoneTrack_position_z = node_->FindCTrack(ConstDescID(DescLevel(ID_BASEOBJECT_REL_POSITION), DescLevel(VECTOR_Z)));
									CTrack::Free(BoneTrack_position_z);
									CTrack* BoneTrack_rotation_x = node_->FindCTrack(ConstDescID(DescLevel(ID_BASEOBJECT_REL_ROTATION), DescLevel(VECTOR_X)));
									CTrack::Free(BoneTrack_rotation_x);
									CTrack* BoneTrack_rotation_y = node_->FindCTrack(ConstDescID(DescLevel(ID_BASEOBJECT_REL_ROTATION), DescLevel(VECTOR_Y)));
									CTrack::Free(BoneTrack_rotation_y);
									CTrack* BoneTrack_rotation_z = node_->FindCTrack(ConstDescID(DescLevel(ID_BASEOBJECT_REL_ROTATION), DescLevel(VECTOR_Z)));
									CTrack::Free(BoneTrack_rotation_z);
									node_->SetRelPos(Vector(0));
									node_->SetRelRot(Vector(0));
								}
								if (BaseTag* const node_ik_tag = node_->GetTag(1019561); node_ik_tag != nullptr)
								{
									CTrack* ik_enable_track = node_ik_tag->FindCTrack(ConstDescID(DescLevel(ID_CA_IK_TAG_ENABLE)));
									CTrack::Free(ik_enable_track);
									node_ik_tag->SetParameter(ConstDescID(DescLevel(ID_CA_IK_TAG_ENABLE)), true, DESCFLAGS_SET::NONE);
								}
							}
							else {
								if (BaseTag* const node_morph_tag = node_->GetTag(Tposemorph); node_morph_tag != nullptr)
								{
									auto* const	pose_morph_tag = reinterpret_cast<CAPoseMorphTag*>(node_morph_tag);
									const Int32		MorphCount = pose_morph_tag->GetMorphCount();
									for (Int32 index = 0; index < MorphCount; index++)
									{
										CTrack* morph_track = node_morph_tag->FindCTrack(pose_morph_tag->GetMorphID(index));
										CTrack::Free(morph_track);
										pose_morph_tag->GetMorph(index)->SetStrength(0);
									}
								}
							}
							iferr(nodes.Push(node_->GetDown())) return true;
							if (node_ != op)
							{
								node_ = node_->GetNext();
							}
							else {
								break;
							}
						}
					}
					nodes.Reset();
					EventAdd();
					doc->SetTime(BaseTime(1, 30));
					doc->SetTime(BaseTime(0, 30));
				}
				break;
			}
			default:
				break;
			}
		}
		break;
	}

	default:
		break;
	}
	return SUPER::Message(node, type, data);
}
