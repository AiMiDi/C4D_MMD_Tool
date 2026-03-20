/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & CMT contributors.
Author:			Aimidi
Date:			2023/9/12
File:			mmd_model.h
Description:	MMD model object

**************************************************************************/

#include <c4d.h>
#include <c4d_symbols.h>
#include "plugin_resource.h"
#include "module/core/cmt_marco.h"
#include "mmd_model_manager.h"
#include "cmt_tools_manager.h"
#include "mmd_morph.h"
#include "module/tools/material/mmd_material.h"
#include "mmd_bone_manager.h"
#include "mmd_joint_manager.h"
#include "mmd_mesh_manager.h"
#include "mmd_rigid_manager.h"
#include "maxon/queue.h"
#include "utils/filename_util.hpp"
#include "utils/string_util.hpp"
#include "libMMD/Model/MMD/MMDPhysics.h"

#define COL_NAME 'name'

Bool EditorSubMorphDialog::CreateLayout()
{
	iferr_scope_handler{
		return false;
	};

	SetTitle(GeLoadString(IDS_MORPH_EDITOR));
	m_images = ImagesUserAreaRef::Create("mmd_tool_title.png"_s, 300, 95) iferr_return;
	if (C4DGadget* user_area_gadget = AddUserArea(999, BFH_SCALE, SizePix(300), SizePix(95));
		user_area_gadget != nullptr)
		AttachUserArea(*m_images, user_area_gadget);
	GroupBegin(1000, BFH_CENTER, 3, 1, ""_s, 0, 0, 150);
		AddListView(10004, BFH_LEFT, 350, 150);
		m_listview.AttachListView(this, 10004);
		AddButton(10005, BFH_LEFT, 30, 10, ">>"_s);
		m_id = 20000;
		auto* sub_morph_data = m_morph->GetSubMorphDataWritable();
		if (sub_morph_data == nullptr) {
			Close();
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
					iferr(m_delete_button_id.Insert(m_id++))
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
			Close();
			return false;
		}
		sub_morph_data->Reset();
		for (auto& delete_button_id : m_delete_button_id)
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
	case 10005:
	{
		BaseSelect* select = BaseSelect::Alloc();
		m_listview.GetSelection(select);
		BaseContainer bc;
		Int32 seg = 0, a, b;
		maxon::BaseList<maxon::Pair<String, Float>> tmp;
		for (auto& delete_button_id : m_delete_button_id)
		{
			auto& tmp_data = tmp.Append().GetValue();
			GetString(delete_button_id - 2, tmp_data.first);
			GetFloat(delete_button_id - 1, tmp_data.second);
		}
		m_delete_button_id.Reset();
		// begin layout change and store data
		UpdateDialogHelper update_dialog = BeginLayoutChange(1003, true);
		for (auto& tmp_data : tmp)
		{
			GroupBegin(m_id++, BFH_LEFT, 3, 1, ""_s, 0, 350, 10);
			AddStaticText(m_id++, BFH_LEFT, 150, 10, tmp_data.first, BORDER_NONE);
			AddEditNumber(m_id, BFH_LEFT, 150, 10);
			SetFloat(m_id++, tmp_data.second);
			AddButton(m_id, BFH_LEFT, 32, 10, GeLoadString(IDS_DELETE));
			iferr(m_delete_button_id.Insert(m_id++))
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
				iferr(m_delete_button_id.Insert(m_id++))
					return false;
				GroupEnd();
			}
		}
		// update group
		update_dialog.CommitChanges();
		//LayoutChanged(1003);
		m_listview.DataChanged();
		break;
	}
	default:
		if (m_delete_button_id.Find(id) != nullptr)
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
			m_delete_button_id.Erase(id);
		}
		break;
	}
	return true;
}

MMDModelManagerObject::AddMorphHelper::AddMorphHelper(MMDModelManagerObject* model):m_model(model)
{
	*m_model->update_morph_.Write() = false;
	*m_model->is_morph_initialized_.Write() = false;
}

MMDModelManagerObject::AddMorphHelper::~AddMorphHelper()
{
	*m_model->update_morph_.Write() = true;
}

SDK2024_Init(MMDModelManagerObject)
{
	if (node == nullptr)
		return false;
	BaseContainer* bc = reinterpret_cast<BaseList2D*>(node)->GetDataInstance();
	if (bc == nullptr)
		return false;
	bc->SetString(ID_BASELIST_NAME, GeLoadString(IDS_O_MMD_MODEL_MANAGER));
	bc->SetFloat(PMX_VERSION, 2.0);
	bc->SetString(MODEL_NAME_LOCAL, "model"_s);
	bc->SetString(MODEL_NAME_UNIVERSAL, "model"_s);
	bc->SetString(COMMENTS_LOCAL, "description"_s);
	bc->SetString(COMMENTS_UNIVERSAL, "description"_s);
	bc->SetFloat(MODEL_POSITION_MULTIPLE, 8.5);
	bc->SetInt32(MODEL_ANIM_LIST, -1);
	bc->SetInt32(MODEL_MATERIAL_LIST, MODEL_MATERIAL_NONE);
	animation_items_.SetString(-1, GeLoadString(IDS_CMT_VMD_ANIM_NONE));
	return true;
}

template<>
bool inline io_util::ReadData<maxon::Pair<MMDModelRootDynamicDescriptionType, Int>>(HyperFile* hf, maxon::Pair<MMDModelRootDynamicDescriptionType, Int>& data)
{
	UChar type = 0;
	if (!ReadData(hf, type))
		return false;
	data.first = static_cast<MMDModelRootDynamicDescriptionType>(type);

	if (!ReadData(hf, data.second))
		return false;
	return true;
}

template<>
bool inline io_util::WriteData<maxon::Pair<MMDModelRootDynamicDescriptionType, Int>>(HyperFile* hf, const maxon::Pair<MMDModelRootDynamicDescriptionType, Int>& data)
{
	if (!WriteData(hf, static_cast<UChar>(data.first)))
		return false;
	if (!WriteData(hf, data.second))
		return false;
	return true;
}

Bool MMDModelManagerObject::Read(GeListNode* node, HyperFile* hf, Int32 level) {
	iferr_scope_handler
	{
		return false;
	};
	IOReadField(bone_manager_);
	IOReadField(mesh_manager_);
	IOReadField(rigid_manager_);
	IOReadField(joint_manager_);

	*is_manager_read_.Write() = true;

	IOReadField(morph_named_number_);

	if (!io_util::ReadHashMap(hf, desc_id_map_))
	{
		DebugOutput(maxon::OUTPUT::DIAGNOSTIC, "[CMT] Read: FAILED at desc_id_map_");
		return false;
	}

	if (!io_util::ReadHashMap(hf, morph_name_))
	{
		DebugOutput(maxon::OUTPUT::DIAGNOSTIC, "[CMT] Read: FAILED at morph_name_");
		return false;
	}

	if (!ReadMorph(hf))
	{
		DebugOutput(maxon::OUTPUT::DIAGNOSTIC, "[CMT] Read: FAILED at ReadMorph");
		return false;
	}
	Int64 mat_count = 0;
	if (hf->ReadInt64(&mat_count) && mat_count >= 0 && mat_count <= 10000)
	{
		iferr(material_list_.Resize(0))
			return false;
		for (Int64 i = 0; i < mat_count; ++i)
		{
			MMDMaterialData mat;
			if (!mat.Read(hf))
			{
				DebugOutput(maxon::OUTPUT::DIAGNOSTIC, "[CMT] Read: FAILED at material @", i);
				return false;
			}
			iferr(material_list_.Append(std::move(mat)))
				return false;
		}
	}
	else
	{
		DebugOutput(maxon::OUTPUT::DIAGNOSTIC, "[CMT] Read: mat_count read failed or invalid (@)", mat_count);
	}

	Int64 df_count = 0;
	if (hf->ReadInt64(&df_count) && df_count >= 0 && df_count <= 10000)
	{
		iferr(display_frame_list_.Resize(0))
			return false;
		for (Int64 i = 0; i < df_count; ++i)
		{
			DisplayFrameData df;
			if (!df.Read(hf))
			{
				DebugOutput(maxon::OUTPUT::DIAGNOSTIC, "[CMT] Read: FAILED at display frame @", i);
				return false;
			}
			iferr(display_frame_list_.Append(std::move(df)))
				return false;
		}
	}
	else
	{
		DebugOutput(maxon::OUTPUT::DIAGNOSTIC, "[CMT] Read: df_count read failed or invalid (@)", df_count);
	}

	if (!io_util::ReadHashMap(hf, ik_solver_enable_states_))
	{
		DebugOutput(maxon::OUTPUT::DIAGNOSTIC, "[CMT] Read: FAILED at ik_solver_enable_states_");
		return false;
	}

	animation_items_.FlushAll();
	animation_items_.SetString(-1, GeLoadString(IDS_CMT_VMD_ANIM_NONE));
	animation_index_ = -1;
	iferr(pending_vmd_data_.Resize(0))
		return false;

	Int32 anim_idx = -1;
	if (hf->ReadInt32(&anim_idx))
	{
		Int64 anim_count = 0;
		if (hf->ReadInt64(&anim_count) && anim_count > 0 && anim_count <= 10000)
		{
			if (anim_idx >= static_cast<Int32>(anim_count))
				anim_idx = -1;
			animation_index_ = anim_idx;

			for (Int64 i = 0; i < anim_count; ++i)
			{
				String name;
				if (!hf->ReadString(&name))
				{
					DebugOutput(maxon::OUTPUT::DIAGNOSTIC, "[CMT] Read: failed to read name at index @", i);
					break;
				}

				Int64 size = 0;
				if (!hf->ReadInt64(&size))
				{
					DebugOutput(maxon::OUTPUT::DIAGNOSTIC, "[CMT] Read: failed to read size at index @", i);
					break;
				}

				std::vector<uint8_t> data;
				if (size > 0)
				{
					void* mem = nullptr;
					Int mem_size = 0;
					if (!hf->ReadMemory(&mem, &mem_size))
					{
						DebugOutput(maxon::OUTPUT::DIAGNOSTIC, "[CMT] Read: failed to read memory at index @, expected size=@", i, size);
						break;
					}
					data.resize(static_cast<size_t>(mem_size));
					CopyMem(mem, data.data(), mem_size);
					DeleteMem(mem);
				}

			iferr(pending_vmd_data_.Append(std::make_pair(name, std::move(data))))
					break;
				animation_items_.SetString(static_cast<Int32>(i), name);
			}
		}
	}

	*is_morph_initialized_.Write() = true;
	return true;
}
SDK2024_Write(MMDModelManagerObject) {

	IOWriteField(bone_manager_);
	IOWriteField(mesh_manager_);
	IOWriteField(rigid_manager_);
	IOWriteField(joint_manager_);
	IOWriteField(morph_named_number_);

	if (!io_util::WriteHashMap(hf, desc_id_map_))
		return false;

	if (!io_util::WriteHashMap(hf, morph_name_))
		return false;

	if (!WriteMorph(hf))
		return false;
	if (!hf->WriteInt64(material_list_.GetCount()))
		return false;
	for (Int32 i = 0; i < material_list_.GetCount(); ++i)
		if (!material_list_[i].Write(hf))
			return false;
	if (!hf->WriteInt64(display_frame_list_.GetCount()))
		return false;
	for (Int32 i = 0; i < display_frame_list_.GetCount(); ++i)
		if (!display_frame_list_[i].Write(hf))
			return false;

	if (!io_util::WriteHashMap(hf, ik_solver_enable_states_))
		return false;

	if (!hf->WriteInt32(animation_index_))
		return false;

	if (animations_.GetCount() > 0)
	{
		const auto anim_count = static_cast<Int64>(animations_.GetCount());
		if (!hf->WriteInt64(anim_count))
			return false;
		for (Int64 i = 0; i < anim_count; ++i)
		{
			const auto& [name, animation] = animations_[i];
			if (!hf->WriteString(name))
				return false;
			libmmd::VMDFile vmd_file;
			std::vector<uint8_t> vmd_data;
			if (animation && animation->Save(vmd_file) && libmmd::WriteVMDFile(&vmd_file, vmd_data))
			{
				if (!hf->WriteInt64(static_cast<Int64>(vmd_data.size())))
					return false;
				if (!hf->WriteMemory(vmd_data.data(), static_cast<Int>(vmd_data.size())))
					return false;
			}
			else
			{
				DebugOutput(maxon::OUTPUT::DIAGNOSTIC, "[CMT] Write: anim[@] name='@' SERIALIZE FAILED, writing size=0", i, name);
				if (!hf->WriteInt64(0))
					return false;
			}
		}
	}
	else if (pending_vmd_data_.GetCount() > 0)
	{
		if (!hf->WriteInt64(static_cast<Int64>(pending_vmd_data_.GetCount())))
			return false;
		for (const auto& [name, vmd_data] : pending_vmd_data_)
		{
			if (!hf->WriteString(name))
				return false;
			if (!hf->WriteInt64(static_cast<Int64>(vmd_data.size())))
				return false;
			if (!vmd_data.empty())
			{
				if (!hf->WriteMemory(vmd_data.data(), static_cast<Int>(vmd_data.size())))
					return false;
			}
		}
	}
	else
	{
		if (!hf->WriteInt64(0))
			return false;
	}

	return true;
}
SDK2024_CopyTo(MMDModelManagerObject)
{
	const auto destObject = reinterpret_cast<MMDModelManagerObject*>(dest);
	destObject->model_mode_ = model_mode_;
	if (bone_manager_)
		bone_manager_->CopyTo(destObject->bone_manager_, flags, trn);
	if (joint_manager_)
		joint_manager_->CopyTo(destObject->joint_manager_, flags, trn);
	if (rigid_manager_)
		rigid_manager_->CopyTo(destObject->rigid_manager_, flags, trn);
	if (mesh_manager_)
		mesh_manager_->CopyTo(destObject->mesh_manager_, flags, trn);
	iferr(destObject->desc_id_map_.CopyFrom(desc_id_map_))
		return false;
	iferr(destObject->morph_name_.CopyFrom(morph_name_))
		return false;
	if (!CopyMorph(destObject))
		return false;
	iferr(destObject->material_list_.Resize(0))
		return false;
	destObject->material_selection_index_ = material_selection_index_;
	for (Int32 i = 0; i < material_list_.GetCount(); ++i)
	{
		MMDMaterialData copy;
		if (!material_list_[i].CopyTo(copy))
			return false;
		iferr(destObject->material_list_.Append(std::move(copy)))
			return false;
	}
	iferr(destObject->display_frame_list_.Resize(0))
		return false;
	destObject->display_frame_selection_index_ = display_frame_selection_index_;
	for (Int32 i = 0; i < display_frame_list_.GetCount(); ++i)
	{
		DisplayFrameData copy;
		if (!display_frame_list_[i].CopyTo(copy))
			return false;
		iferr(destObject->display_frame_list_.Append(std::move(copy)))
			return false;
	}

	iferr(destObject->ik_solver_enable_states_.CopyFrom(ik_solver_enable_states_))
		return false;

	destObject->animation_index_ = animation_index_;
	destObject->animation_items_ = animation_items_;
	iferr(destObject->pending_vmd_data_.Resize(0))
		return false;
	if (animations_.GetCount() > 0)
	{
		for (Int32 i = 0; i < animations_.GetCount(); ++i)
		{
			const auto& [name, animation] = animations_[i];
			std::vector<uint8_t> vmd_data;
			if (animation)
			{
				libmmd::VMDFile vmd_file;
				if (animation->Save(vmd_file))
					libmmd::WriteVMDFile(&vmd_file, vmd_data);
			}
		iferr(destObject->pending_vmd_data_.Append(std::make_pair(name, std::move(vmd_data))))
				return false;
		}
	}
	else if (pending_vmd_data_.GetCount() > 0)
	{
		for (const auto& [name, vmd_data] : pending_vmd_data_)
		{
			std::vector<uint8_t> data_copy(vmd_data);
			iferr(destObject->pending_vmd_data_.Append(std::make_pair(name, std::move(data_copy))))
				return false;
		}
	}
	return true;
}
Bool MMDModelManagerObject::ReadMorph(HyperFile* hf)
{
	iferr_scope_handler{ return false; };
	auto morph_change_helper = BeginMorphChange();
	Int data_count = 0;
	if (!hf->ReadInt64(&data_count))
		return false;
	for (Int i = 0; i < data_count; ++i)
	{
		MMDMorphType type;
		if (!hf->ReadUChar(reinterpret_cast<UChar*>(&type)))
			return false;

		IMorph* morph = nullptr;
		switch (type)
		{
		case MMDMorphType::GROUP:    morph = NewObj(GroupMorph) iferr_return; break;
		case MMDMorphType::FLIP:     morph = NewObj(FlipMorph) iferr_return; break;
		case MMDMorphType::MESH:     morph = NewObj(MeshMorph) iferr_return; break;
		case MMDMorphType::UV:       morph = NewObj(UVMorph) iferr_return; break;
		case MMDMorphType::BONE:     morph = NewObj(BoneMorph) iferr_return; break;
		case MMDMorphType::MATERIAL: morph = NewObj(MaterialMorph) iferr_return; break;
		case MMDMorphType::IMPULSE:  morph = NewObj(ImpulseMorph) iferr_return; break;
		default: return false;
		}
		morph_data_.AppendPtr(morph) iferr_return;
		morph->Read(hf);
	}

	return true;
}
Bool MMDModelManagerObject::WriteMorph(HyperFile* hf) SDK2024_Const
{
	if (!hf->WriteInt64(morph_data_.GetCount()))
		return false;
	if(!std::all_of(morph_data_.Begin(), morph_data_.End(), [&](SDK2024_Const IMorph& i)
	{
			// Write morph type
		return hf->WriteUChar(static_cast<UChar>(i.GetType()))
			// Write morph data
			&& i.Write(hf);
	}))
		return false;

	return true;
}
Bool MMDModelManagerObject::CopyMorph(MMDModelManagerObject* dst) const
{
	if(!dst)
		return false;
	iferr_scope_handler{ return false; };
	for (const auto& morph : morph_data_)
	{
		const auto& new_morph_name = morph.GetName();
		const auto new_morph_index = dst->AddMorph(morph.GetType(), new_morph_name, false);
		const auto new_morph = &dst->morph_data_[new_morph_index];
		if (!morph.CopyTo(new_morph))
			return true;
		new_morph->AddMorphUI(*dst, new_morph_index);
		if (GeListNode* const dst_node = dst->Get())
		{
			Float src_strength = 0.0;
			if (GeListNode* const src_node = const_cast<MMDModelManagerObject*>(this)->Get())
				src_strength = morph.GetStrength(src_node);
			new_morph->SetStrength(dst_node, src_strength);
		}
	}
	return true;
}

MMDModelManagerObject::AddMorphHelper MMDModelManagerObject::BeginMorphChange()
{
	return AddMorphHelper{this};
}

MMDModelManagerObject::MMDModelManagerObject() : update_morph_(true), is_morph_initialized_(false), is_manager_read_(false), is_runtime_initialized_(false)
{
}

void MMDModelManagerObject::RefreshMorph()
{
	for (auto it = maxon::Iterable::EraseIterator(morph_data_); it; ++it)
	{
		DeleteMorph(it);
	}
	auto* mesh_mgr = io_util::ResolveObjectLink(mesh_manager_);
	if (!mesh_mgr) return;
	auto* mesh_manager_data = mesh_mgr->GetNodeData<MMDMeshManagerObject>();
	auto& mesh_morph_map = mesh_manager_data->GetMeshMorphData();
	const auto& uv_morph_names = mesh_manager_data->GetUVMorphNames();
	for (auto& name : mesh_morph_map.GetKeys())
	{
		const auto morph_type = uv_morph_names.Find(name) ? MMDMorphType::UV : MMDMorphType::MESH;
		AddMorph(morph_type, name);
	}
	if (auto* bone_mgr = io_util::ResolveObjectLink(bone_manager_))
	{
		auto& bone_morph_map = bone_mgr->GetNodeData<MMDBoneManagerObject>()->GetBoneMorphMap();
		for (auto& name : bone_morph_map.GetKeys())
		{
			AddMorph(MMDMorphType::BONE, name);
		}
	}
}

void MMDModelManagerObject::SyncMorphSlidersFromTags()
{
	if (!mesh_manager_data_)
		return;
	GeListNode* node = Get();
	if (!node)
		return;
	for (auto& morph : morph_data_)
	{
		const auto type = morph.GetType();
		if (type != MMDMorphType::MESH && type != MMDMorphType::UV)
			continue;
		Float tag_strength = 0.0;
		if (mesh_manager_data_->GetMorphStrength(morph.GetName(), tag_strength))
			morph.SetStrength(node, tag_strength);
	}
}

static void SendObjectUpdateMessage(BaseObject* dst, BaseObject* obj)
{
	MMDModelManagerObjectMsg msg(MMDModelManagerObjectMsgType::MANAGER_OBJECT_UPDATE, obj);
	dst->Message(g_mmd_model_manager_object_id, &msg);
}

Bool MMDModelManagerObject::UpdateManagers(BaseObject* op)
{
	if (!op)
		op = reinterpret_cast<BaseObject*>(Get());
	BaseObject* mesh_manager = nullptr;
	BaseObject* bone_manager = nullptr;
	BaseObject* rigid_manager = nullptr;
	BaseObject* joint_manager = nullptr;
	maxon::Queue<BaseObject*> nodes;
	iferr(nodes.Push(op->GetDown())) return false;
	while (!nodes.IsEmpty())
	{
		BaseObject* node = *nodes.Pop();
		if (node != nullptr)
		{
			if (node->IsInstanceOf(g_mmd_joint_manager_object_id))
				joint_manager = node;
			else if (node->IsInstanceOf(g_mmd_rigid_manager_object_id))
				rigid_manager = node;
			else if (node->IsInstanceOf(g_mmd_bone_manager_object_id))
				bone_manager = node;
			else if (node->IsInstanceOf(g_mmd_mesh_manager_object_id))
				mesh_manager = node;
			iferr(nodes.Push(node->GetNext())) return false;
		}
	}
	nodes.Reset();
	Bool send_message = false;
	if (!io_util::ResolveObjectLink(bone_manager_)) {
		if (!bone_manager)
		{
			BaseObject* tmp = BaseObject::Alloc(g_mmd_bone_manager_object_id);
			tmp->InsertUnder(op);
			bone_manager_->SetLink(tmp);
		}
		else {
			bone_manager_->SetLink(bone_manager);
		}
		send_message = true;
	}
	if (!io_util::ResolveObjectLink(mesh_manager_)) {
		if (!mesh_manager)
		{
			BaseObject* tmp = BaseObject::Alloc(g_mmd_mesh_manager_object_id);
			tmp->InsertUnder(op);
			mesh_manager_->SetLink(tmp);
		}
		else {
			mesh_manager_->SetLink(mesh_manager);
		}
		send_message = true;
	}
	if (!io_util::ResolveObjectLink(rigid_manager_)) {
		if (!rigid_manager)
		{
			BaseObject* tmp = BaseObject::Alloc(g_mmd_rigid_manager_object_id);
			tmp->InsertUnder(op);
			rigid_manager_->SetLink(tmp);
		}
		else {
			rigid_manager_->SetLink(rigid_manager);
		}
		send_message = true;
	}
	if (!io_util::ResolveObjectLink(joint_manager_)) {
		if (!joint_manager)
		{
			BaseObject* tmp = BaseObject::Alloc(g_mmd_joint_manager_object_id);
			tmp->InsertUnder(op);
			joint_manager_->SetLink(tmp);
		}
		else {
			joint_manager_->SetLink(joint_manager);
		}
		send_message = true;
	}
	auto* bone_mgr_obj = io_util::ResolveObjectLink(bone_manager_);
	auto* mesh_mgr_obj = io_util::ResolveObjectLink(mesh_manager_);
	auto* rigid_mgr_obj = io_util::ResolveObjectLink(rigid_manager_);
	auto* joint_mgr_obj = io_util::ResolveObjectLink(joint_manager_);
	bone_manager_data_ = bone_mgr_obj ? bone_mgr_obj->GetNodeData<MMDBoneManagerObject>() : nullptr;
	mesh_manager_data_ = mesh_mgr_obj ? mesh_mgr_obj->GetNodeData<MMDMeshManagerObject>() : nullptr;
	rigid_manager_data_ = rigid_mgr_obj ? rigid_mgr_obj->GetNodeData<MMDRigidManagerObject>() : nullptr;
	joint_manager_data_ = joint_mgr_obj ? joint_mgr_obj->GetNodeData<MMDJointManagerObject>() : nullptr;
	if (send_message)
	{
		if (bone_mgr_obj) SendObjectUpdateMessage(bone_mgr_obj, op);
		if (mesh_mgr_obj) SendObjectUpdateMessage(mesh_mgr_obj, op);
	}
	if (rigid_manager_data_)
	{
		rigid_manager_data_->bone_manager_data_ = bone_manager_data_;
		if (bone_mgr_obj)
			rigid_manager_data_->bone_manager_link_->SetLink(bone_mgr_obj);
	}
	if (joint_manager_data_)
	{
		joint_manager_data_->bone_manager_data_ = bone_manager_data_;
		joint_manager_data_->rigid_manager_data_ = rigid_manager_data_;
		if (bone_mgr_obj)
			joint_manager_data_->bone_manager_link_->SetLink(bone_mgr_obj);
		if (auto* rigid_obj = io_util::ResolveObjectLink(rigid_manager_))
			joint_manager_data_->rigid_manager_link_->SetLink(rigid_obj);
	}
	return true;
}

EXECUTIONRESULT MMDModelManagerObject::Execute(BaseObject* op, BaseDocument* doc, BaseThread* bt, Int32 priority, EXECUTIONFLAGS flags)
{
	iferr_scope_handler
	{
		return EXECUTIONRESULT::OK;
	};

	if (op == nullptr || doc == nullptr)
	{
		return EXECUTIONRESULT::OK;
	}

	const auto manager_read = *is_manager_read_.Read();

	if (!UpdateManagers(op))
		return EXECUTIONRESULT::OK;

	if (!*is_runtime_initialized_.Read() && !mmd_model_)
	{
		if (!RebuildRuntime())
		{
			DebugOutput(maxon::OUTPUT::DIAGNOSTIC, "[CMT] Execute: RebuildRuntime FAILED");
			StatusSetText(GeLoadString(IDS_CMT_VMD_REBUILD_FAILED));
		}
		*is_runtime_initialized_.Write() = true;

		if (manager_read)
		{
			if (bone_manager_data_)
				bone_manager_data_->HandleBoneIndexChangeMessage(io_util::ResolveObjectLink(bone_manager_));
			*is_manager_read_.Write() = false;
		}
	}
	else if(manager_read)
	{
		if (bone_manager_data_)
			bone_manager_data_->HandleBoneIndexChangeMessage(io_util::ResolveObjectLink(bone_manager_));
		*is_manager_read_.Write() = false;
	}

	if (!*is_morph_initialized_.Read())
	{
		if (mesh_manager_data_)
		{
			if (auto* mesh_mgr_obj = io_util::ResolveObjectLink(mesh_manager_))
				mesh_manager_data_->ForceRefreshMorphData(mesh_mgr_obj);
		}
		RefreshMorph();
		SyncMorphSlidersFromTags();
		*is_morph_initialized_.Write() = true;
	}

	if (*update_morph_.Read())
	{
		for (auto& morph : morph_data_)
		{
			UpdateMorph(morph);
		}
	}

	if (model_mode_ == MODEL_MODE_VMD && mmd_model_)
	{
		if (const auto now_time = doc->GetTime(); prev_time_ != now_time)
		{
			fps_ = static_cast<Float32>(doc->GetFps());

			const Float64 time_diff = now_time.Get() - prev_time_.Get();
			const Float64 frame_time = 1.0 / static_cast<Float64>(fps_);
			const Bool needs_physics_reset = !is_animation_initialized_ || now_time == doc->GetMinTime()
				|| (time_diff < frame_time * 0.5 || time_diff > frame_time * 1.5);

			if (animation_index_ != -1 && animation_index_ < animations_.GetCount())
			{
				const auto& [_, animation]  = animations_[animation_index_];
				constexpr Float32 vmd_fps = 30.0f;
				const auto vmd_frame = static_cast<Float32>(now_time.Get() * vmd_fps);
				if (!animation->GetApplyIKEnable())
				{
					auto* ik_manager = mmd_model_->GetIKManager();
					if (ik_manager)
					{
						for (const auto& entry : desc_id_map_)
						{
							const auto& pair = entry.GetValue();
							if (pair.first == MMDModelRootDynamicDescriptionType::IK_SOLVER_ENABLE)
							{
								GeData value;
								if (op->GetParameter(entry.GetKey(), value, DESCFLAGS_GET::NONE))
								{
									if (auto* solver = ik_manager->GetMMDIKSolver(static_cast<size_t>(pair.second)))
										solver->Enable(value.GetBool());
								}
							}
						}
					}
				}
				if (needs_physics_reset)
				{
					mmd_model_->InitializeAnimation();
					animation->SyncPhysics(vmd_frame, 10, 1.f / fps_);
					is_animation_initialized_ = true;
				}
				mmd_model_->BeginAnimation();
				mmd_model_->UpdateAllAnimation(animation.get(), vmd_frame, 1.f / fps_);
				mmd_model_->EndAnimation();
			}
			else
			{
				if (needs_physics_reset)
				{
					mmd_model_->InitializeAnimation();
					is_animation_initialized_ = true;
				}
				mmd_model_->BeginAnimation();
				mmd_model_->UpdateNodeAnimation(false);
				mmd_model_->UpdatePhysicsAnimation(1.f / fps_);
				mmd_model_->UpdateNodeAnimation(true);
				mmd_model_->EndAnimation();
			}
			prev_time_ = now_time;
		}
	}
	return EXECUTIONRESULT::OK;
}

Int MMDModelManagerObject::ImportGroupAndFlipMorph(const libmmd::PMXFileMorph& pmx_morph, Int32 panel)
{
	Int morph_id = -1;
	iferr_scope_handler{ return morph_id; };
	switch (pmx_morph.m_morphType)
	{
	case libmmd::PMXMorphType::Group:
	{
		morph_id = AddMorph(MMDMorphType::GROUP, String(pmx_morph.m_name.c_str()), true, panel);
		auto& morph = morph_data_[morph_id];
		for (const auto& [morph_index, weight] : pmx_morph.m_groupMorph)
		{
			morph.AddSubMorphNoCheck(morph_index, weight);
		}
		break;
	}
	case libmmd::PMXMorphType::Flip:
	{
		morph_id = AddMorph(MMDMorphType::FLIP, String(pmx_morph.m_name.c_str()), true, panel);
		auto& morph = morph_data_[morph_id];
		for (const auto& [morph_index, weight] : pmx_morph.m_flipMorph)
		{
			morph.AddSubMorphNoCheck(morph_index, weight);
		}
		break;
	}
	default:
		break;
	}
	return morph_id;
}

DescID MMDModelManagerObject::AddDynamicDescription(const BaseContainer& bc, const MMDModelRootDynamicDescriptionType& type, Int index)
{
	DescID id{};
	DynamicDescription* const dynamic_description = Get()->GetDynamicDescriptionWritable();
	if (!dynamic_description)
		return id;
	id = dynamic_description->Alloc(bc);
	iferr(desc_id_map_.Insert(id, { type, index }))
		return id;
	return id;
}

void MMDModelManagerObject::DeleteDynamicDescription(const DescID& id)
{
	DynamicDescription* const dynamic_description = Get()->GetDynamicDescriptionWritable();
	if (!dynamic_description)
		return;
	dynamic_description->Remove(id);
	std::ignore = desc_id_map_.Erase(id);
}

void MMDModelManagerObject::BuildIKSolverUI()
{
	if (!mmd_model_)
		return;
	auto* ik_manager = mmd_model_->GetIKManager();
	if (!ik_manager)
		return;
	const auto solver_count = ik_manager->GetIKSolverCount();
	for (size_t i = 0; i < solver_count; ++i)
	{
		auto* solver = ik_manager->GetMMDIKSolver(i);
		if (!solver)
			continue;
		const String solver_name(solver->GetName().c_str());
		BaseContainer bc = GetCustomDataTypeDefault(DTYPE_BOOL);
		bc.SetString(DESC_NAME, solver_name);
		bc.SetData(DESC_PARENTGROUP, MakeDescIDGeData(ConstDescID(DescLevel(MODEL_IK_GRP))));
		auto id = AddDynamicDescription(bc, MMDModelRootDynamicDescriptionType::IK_SOLVER_ENABLE, static_cast<Int>(i));
		Get()->SetParameter(id, GeData(true), DESCFLAGS_SET::NONE);
	}
	ApplyIKSolverStates();
}

void MMDModelManagerObject::ApplyIKSolverStates()
{
	if (!mmd_model_)
		return;
	auto* ik_manager = mmd_model_->GetIKManager();
	if (!ik_manager)
		return;
	auto* node = Get();
	for (const auto& entry : desc_id_map_)
	{
		const auto& pair = entry.GetValue();
		if (pair.first != MMDModelRootDynamicDescriptionType::IK_SOLVER_ENABLE)
			continue;
		auto* solver = ik_manager->GetMMDIKSolver(static_cast<size_t>(pair.second));
		if (!solver)
			continue;
		const auto* state_entry = ik_solver_enable_states_.Find(String(solver->GetName().c_str()));
		if (!state_entry)
			continue;
		const Bool enabled = state_entry->GetValue();
		solver->Enable(enabled);
		if (node)
			node->SetParameter(entry.GetKey(), GeData(enabled), DESCFLAGS_SET::NONE);
	}
}

void MMDModelManagerObject::ImportVMDIKKeyframes(const libmmd::VMDFile& vmd_file, const CMTToolsSetting::MotionImport& setting)
{
	if (!mmd_model_ || vmd_file.m_iks.empty())
		return;
	auto* ik_manager = mmd_model_->GetIKManager();
	if (!ik_manager)
		return;
	auto* op = static_cast<BaseObject*>(Get());
	if (!op)
		return;

	maxon::HashMap<String, DescID> ik_name_to_desc_id;
	for (const auto& entry : desc_id_map_)
	{
		const auto& pair = entry.GetValue();
		if (pair.first == MMDModelRootDynamicDescriptionType::IK_SOLVER_ENABLE)
		{
			if (auto* solver = ik_manager->GetMMDIKSolver(static_cast<size_t>(pair.second)))
			{
				iferr(ik_name_to_desc_id.Insert(String(solver->GetName().c_str()), entry.GetKey())) {}
			}
		}
	}

	for (const auto& ik : vmd_file.m_iks)
	{
		for (const auto& ik_info : ik.m_ikInfos)
		{
			const String ik_name(ik_info.m_name.ToUtf8String().c_str());
			const auto* entry = ik_name_to_desc_id.Find(ik_name);
			if (!entry)
				continue;
			const DescID& desc_id = entry->GetValue();

			CTrack* track = op->FindCTrack(desc_id);
			if (!track)
			{
				track = CTrack::Alloc(op, desc_id);
				if (!track)
					continue;
				op->InsertTrackSorted(track);
			}
			CCurve* curve = track->GetCurve();
			if (!curve)
				continue;

			const BaseTime frame_time(static_cast<Float>(ik.m_frame) + setting.time_offset, 30.0);
			CKey* key = curve->AddKey(frame_time);
			if (!key)
				continue;
			key->SetValue(curve, ik_info.m_enable ? 1.0 : 0.0);
			key->SetInterpolation(curve, CINTERPOLATION::STEP);
		}
	}
}

Int MMDModelManagerObject::GetMorphNum() const
{
	return morph_data_.GetCount();
}

const maxon::PointerArray<IMorph>& MMDModelManagerObject::GetMorphData()
{
	return morph_data_;
}

const maxon::HashMap<String, Int>& MMDModelManagerObject::GetMorphNameMap()
{
	return morph_name_;
}

void MMDModelManagerObject::SetMMDModel(const MMDModelPtr& model)
{
	mmd_model_ = model;
	if (bone_manager_data_)
	{
		bone_manager_data_->mmd_node_manager_ = mmd_model_->GetNodeManager();
		bone_manager_data_->mmd_morph_manager_ = mmd_model_->GetMorphManager();
	}

	if (mesh_manager_data_)
	{
		mesh_manager_data_->mmd_morph_manager_ = mmd_model_->GetMorphManager();
	}

	if (rigid_manager_data_)
	{
		rigid_manager_data_->mmd_physics_manager_ = mmd_model_->GetPhysicsManager();
	}

	if (joint_manager_data_)
	{
		joint_manager_data_->mmd_physics_manager_ = mmd_model_->GetPhysicsManager();
	}
}

void MMDModelManagerObject::SyncSubManagerScale(const Float pm)
{
	if (auto* op = reinterpret_cast<BaseObject*>(Get()))
		op->SetAbsScale(Vector(pm, pm, pm));
}

Bool MMDModelManagerObject::CreateManagers()
{
	const BaseDocument* doc = GetActiveDocument();
	if (const auto op = reinterpret_cast<BaseObject*>(Get()); op != nullptr && doc != nullptr)
	{
		if (!io_util::ResolveObjectLink(bone_manager_))
		{
			BaseObject* bone_root_object = BaseObject::Alloc(g_mmd_bone_manager_object_id);
			bone_root_object->InsertUnder(op);
			bone_manager_->SetLink(bone_root_object);
			bone_manager_data_ = bone_root_object->GetNodeData<MMDBoneManagerObject>();
			bone_manager_data_->model_manager_->SetLink(op);
		}
		if (!io_util::ResolveObjectLink(mesh_manager_))
		{
			BaseObject* mesh_root_object = BaseObject::Alloc(g_mmd_mesh_manager_object_id);
			mesh_root_object->InsertUnder(op);
			mesh_manager_->SetLink(mesh_root_object);
			mesh_manager_data_ = mesh_root_object->GetNodeData<MMDMeshManagerObject>();
			mesh_manager_data_->model_manager_->SetLink(op);
		}
		if (!io_util::ResolveObjectLink(rigid_manager_))
		{
			BaseObject* rigid_root_object = BaseObject::Alloc(g_mmd_rigid_manager_object_id);
			rigid_root_object->InsertUnder(op);
			rigid_manager_->SetLink(rigid_root_object);
			rigid_manager_data_ = rigid_root_object->GetNodeData<MMDRigidManagerObject>();
			rigid_manager_data_->bone_manager_data_ = bone_manager_data_;
			if (auto* bone_obj = io_util::ResolveObjectLink(bone_manager_))
				rigid_manager_data_->bone_manager_link_->SetLink(bone_obj);
		}
		if (!io_util::ResolveObjectLink(joint_manager_))
		{
			BaseObject* joint_root_object = BaseObject::Alloc(g_mmd_joint_manager_object_id);
			joint_root_object->InsertUnder(op);
			joint_manager_->SetLink(joint_root_object);
			joint_manager_data_ = joint_root_object->GetNodeData<MMDJointManagerObject>();
			joint_manager_data_->bone_manager_data_ = bone_manager_data_;
			joint_manager_data_->rigid_manager_data_ = rigid_manager_data_;
			if (auto* bone_obj = io_util::ResolveObjectLink(bone_manager_))
				joint_manager_data_->bone_manager_link_->SetLink(bone_obj);
			if (auto* rigid_obj = io_util::ResolveObjectLink(rigid_manager_))
				joint_manager_data_->rigid_manager_link_->SetLink(rigid_obj);
		}
		return true;
	}
	return false;
}

void MMDModelManagerObject::ImportDisplayFrames(const libmmd::PMXFile& pmx_file)
{
	iferr(display_frame_list_.Resize(0)) return;
	for (const auto& frame : pmx_file.m_displayFrames)
	{
		DisplayFrameData df;
		df.FromPMX(frame);
		iferr(display_frame_list_.Append(std::move(df))) return;
	}
	display_frame_selection_index_ = display_frame_list_.GetCount() > 0 ? 0 : -1;
	RebuildDisplayFrameUI();
}

void MMDModelManagerObject::RebuildDisplayFrameUI()
{
	DynamicDescription* const dd = Get()->GetDynamicDescriptionWritable();
	if (!dd) return;

	const DescID entries_grp_id = ConstDescID(DescLevel(MODEL_DISPLAY_FRAME_ENTRIES_GRP));

	for (auto it = desc_id_map_.Begin(); it != desc_id_map_.End();)
	{
		const auto& dtype = it->GetValue().first;
		if (dtype == MMDModelRootDynamicDescriptionType::DISPLAY_FRAME_DELETE_BUTTON ||
			dtype == MMDModelRootDynamicDescriptionType::DISPLAY_FRAME_MOVE_UP_BUTTON ||
			dtype == MMDModelRootDynamicDescriptionType::DISPLAY_FRAME_MOVE_DOWN_BUTTON)
		{
			dd->Remove(it->GetKey());
			it = desc_id_map_.Erase(it);
		}
		else
			++it;
	}

	{
		void* handle = dd->BrowseInit();
		DescID browse_id;
		const BaseContainer* browse_bc = nullptr;
		maxon::BaseArray<DescID> to_remove;
		while (dd->BrowseGetNext(handle, &browse_id, &browse_bc))
		{
			if (!browse_bc) continue;
			const DescID* parent_id_ptr = GetContainerCustomDataType<DescID>(*browse_bc, DESC_PARENTGROUP, CUSTOMDATATYPE_DESCID);
			if (parent_id_ptr && *parent_id_ptr == entries_grp_id)
				to_remove.Append(browse_id) iferr_ignore("append failed"_s);
		}
		dd->BrowseFree(handle);
		for (const auto& rid : to_remove)
		{
			maxon::BaseArray<DescID> children;
			handle = dd->BrowseInit();
			while (dd->BrowseGetNext(handle, &browse_id, &browse_bc))
			{
				if (!browse_bc) continue;
				const DescID* pid = GetContainerCustomDataType<DescID>(*browse_bc, DESC_PARENTGROUP, CUSTOMDATATYPE_DESCID);
				if (pid && *pid == rid)
					children.Append(browse_id) iferr_ignore("append failed"_s);
			}
			dd->BrowseFree(handle);
			for (const auto& cid : children)
				dd->Remove(cid);
			dd->Remove(rid);
		}
	}

	const Int32 sel = display_frame_selection_index_;
	if (sel < 0 || sel >= display_frame_list_.GetCount())
		return;

	const auto& frame = display_frame_list_[sel];
	BaseContainer bc;

	for (Int32 i = 0; i < frame.targets.GetCount(); ++i)
	{
		const auto& target = frame.targets[i];
		const String type_label = (target.type == DisplayFrameTargetType::Bone)
			? "[Bone] "_s : "[Morph] "_s;
		String target_name = String::IntToString(target.index);
		const MMDBoneManagerObject* bmd_ui = bone_manager_data_;
		if (!bmd_ui)
		{
			if (auto* bone_mgr = io_util::ResolveObjectLink(bone_manager_))
				bmd_ui = bone_mgr->GetNodeData<MMDBoneManagerObject>();
			if (!bmd_ui)
			{
				auto* op = static_cast<BaseObject*>(Get());
				for (BaseObject* child = op->GetDown(); child; child = child->GetNext())
				{
					if (child->IsInstanceOf(g_mmd_bone_manager_object_id))
					{
						bmd_ui = child->GetNodeData<MMDBoneManagerObject>();
						break;
					}
				}
			}
		}
		if (target.type == DisplayFrameTargetType::Bone && bmd_ui)
		{
			target_name = bmd_ui->GetBoneItems().GetString(target.index, target_name);
		}
		else if (target.type == DisplayFrameTargetType::Morph)
		{
			for (const auto& entry : morph_name_)
			{
				if (entry.GetValue() == static_cast<Int>(target.index))
				{
					target_name = entry.GetKey();
					break;
				}
			}
		}

		bc = GetCustomDataTypeDefault(DTYPE_GROUP);
		bc.SetInt32(DESC_COLUMNS, 4);
		bc.SetData(DESC_PARENTGROUP, MakeDescIDGeData(entries_grp_id));
		const auto row_grp = dd->Alloc(bc);

		bc = GetCustomDataTypeDefault(DTYPE_STATICTEXT);
		bc.SetString(DESC_NAME, type_label + target_name);
		bc.SetBool(DESC_SCALEH, true);
		bc.SetData(DESC_PARENTGROUP, MakeDescIDGeData(row_grp));
		dd->Alloc(bc);

		bc = GetCustomDataTypeDefault(DTYPE_BUTTON);
		bc.SetString(DESC_NAME, "\u2191"_s);
		bc.SetInt32(DESC_CUSTOMGUI, CUSTOMGUI_BUTTON);
		bc.SetBool(DESC_FITH, true);
		bc.SetData(DESC_PARENTGROUP, MakeDescIDGeData(row_grp));
		const DescID up_id = dd->Alloc(bc);
		iferr(desc_id_map_.Insert(up_id, {MMDModelRootDynamicDescriptionType::DISPLAY_FRAME_MOVE_UP_BUTTON, i})) {}

		bc = GetCustomDataTypeDefault(DTYPE_BUTTON);
		bc.SetString(DESC_NAME, "\u2193"_s);
		bc.SetInt32(DESC_CUSTOMGUI, CUSTOMGUI_BUTTON);
		bc.SetBool(DESC_FITH, true);
		bc.SetData(DESC_PARENTGROUP, MakeDescIDGeData(row_grp));
		const DescID down_id = dd->Alloc(bc);
		iferr(desc_id_map_.Insert(down_id, {MMDModelRootDynamicDescriptionType::DISPLAY_FRAME_MOVE_DOWN_BUTTON, i})) {}

		bc = GetCustomDataTypeDefault(DTYPE_BUTTON);
		bc.SetString(DESC_NAME, "-"_s);
		bc.SetInt32(DESC_CUSTOMGUI, CUSTOMGUI_BUTTON);
		bc.SetBool(DESC_FITH, true);
		bc.SetData(DESC_PARENTGROUP, MakeDescIDGeData(row_grp));
		const DescID del_id = dd->Alloc(bc);
		iferr(desc_id_map_.Insert(del_id, {MMDModelRootDynamicDescriptionType::DISPLAY_FRAME_DELETE_BUTTON, i})) {}
	}

	Get()->SetDirty(DIRTYFLAGS::DESCRIPTION);
	::SendCoreMessage(COREMSG_CINEMA, BaseContainer(COREMSG_CINEMA_FORCE_AM_UPDATE));
	if (::GeIsMainThread())
		::EventAdd();
}

Bool MMDModelManagerObject::LoadPMX(const libmmd::PMXFile& pmx_file, const MMDModelPtr& pmx_model, const CMTToolsSetting::ModelImport& setting)
{
	SetMMDModel(pmx_model);
	iferr(material_list_.Resize(0))
		return false;
	material_selection_index_ = -1;

	if (BaseContainer* bc = reinterpret_cast<BaseList2D*>(Get())->GetDataInstance())
	{
		bc->SetString(MODEL_NAME_LOCAL, maxon::String{ pmx_file.m_info.m_modelName.c_str() });
		bc->SetString(MODEL_NAME_UNIVERSAL, maxon::String{ pmx_file.m_info.m_englishModelName.c_str() });
		bc->SetString(COMMENTS_LOCAL, maxon::String{ pmx_file.m_info.m_comment.c_str() });
		bc->SetString(COMMENTS_UNIVERSAL, maxon::String{ pmx_file.m_info.m_englishComment.c_str() });
		bc->SetFloat(PMX_VERSION, pmx_file.m_header.m_version);
		bc->SetFloat(MODEL_POSITION_MULTIPLE, setting.position_multiple);
		bc->SetInt32(MODEL_MATERIAL_CREATE_TYPE, static_cast<Int32>(setting.import_material_type));
	}

	SyncSubManagerScale(setting.position_multiple);

	maxon::BaseArray<BaseObject*> bone_list;
	auto morph_change_helper = BeginMorphChange();

	if (setting.import_bone)
		if(!bone_manager_data_ || !bone_manager_data_->LoadPMX(pmx_file, bone_list, setting))
			return false;

	if (setting.import_polygon)
		if(!mesh_manager_data_ || !mesh_manager_data_->LoadPMX(pmx_file, bone_list, setting))
			return false;

	if(!rigid_manager_data_ || !rigid_manager_data_->LoadPMX(pmx_file, setting))
		return false;

	if(!joint_manager_data_ || !joint_manager_data_->LoadPMX(pmx_file, setting))
		return false;

	BuildIKSolverUI();

	ImportDisplayFrames(pmx_file);

	if (setting.import_expression)
	{
		const auto& pmx_morph_array = pmx_file.m_morphs;
		const auto pmx_morph_num = pmx_morph_array.size();
		for (auto morph_index = decltype(pmx_morph_num){}; morph_index < pmx_morph_num; ++morph_index)
		{
			const auto& pmx_morph = pmx_morph_array[morph_index];
			const auto& morph_offset_type = pmx_morph.m_morphType;
			const auto panel = static_cast<Int32>(pmx_morph.m_controlPanel);
			if (morph_offset_type == libmmd::PMXMorphType::Group || morph_offset_type == libmmd::PMXMorphType::Flip)
			{
				ImportGroupAndFlipMorph(pmx_morph, panel);
			}
			else if (morph_offset_type == libmmd::PMXMorphType::Material)
			{
				AddMorph(MMDMorphType::MATERIAL, String(pmx_morph.m_name.c_str()), true, panel);
			}
			else if (morph_offset_type == libmmd::PMXMorphType::Impluse)
			{
				AddMorph(MMDMorphType::IMPULSE, String(pmx_morph.m_name.c_str()), true, panel);
			}
		}
	}
	return true;
}

Bool MMDModelManagerObject::AddMaterial(const libmmd::PMXMaterial& pmx_material, BaseMaterial* c4d_material,
                                        BaseObject* mesh_object, const String& selection_name,
                                        const maxon::BaseArray<Filename>& texture_paths)
{
	iferr_scope_handler { return false; };
	MMDMaterialData mat;
	mat.FromPMX(pmx_material);
	const auto tex_idx = pmx_material.m_textureIndex;
	if (tex_idx >= 0 && tex_idx < texture_paths.GetCount())
		mat.texture_path = texture_paths[tex_idx].GetString();
	const auto sphere_idx = pmx_material.m_sphereTextureIndex;
	if (sphere_idx >= 0 && sphere_idx < texture_paths.GetCount())
		mat.sphere_texture_path = texture_paths[sphere_idx].GetString();
	if (mat.toon_texture_index >= 0)
	{
		if (mat.toon_mode == 1)
		{
			Char buf[20];
			snprintf(buf, sizeof(buf), "toon%02d.bmp", static_cast<int>(mat.toon_texture_index + 1));
			mat.toon_texture_path = (GeGetPluginResourcePath() + Filename("mikumikudance_data") + Filename(buf)).GetString();
		}
		else if (mat.toon_texture_index < texture_paths.GetCount())
			mat.toon_texture_path = texture_paths[mat.toon_texture_index].GetString();
	}
	if (c4d_material)
	{
		auto link_result = maxon::StrongRef<AutoAlloc<BaseLink>>::Create();
		if (link_result == maxon::FAILED)
			return false;
		mat.material_link = link_result.GetValue();
		if (mat.material_link && *mat.material_link)
			(*mat.material_link)->SetLink(c4d_material);
	}
	if (mesh_object)
	{
		auto link_result = maxon::StrongRef<AutoAlloc<BaseLink>>::Create();
		if (link_result == maxon::FAILED)
			return false;
		mat.mesh_link = link_result.GetValue();
		if (mat.mesh_link && *mat.mesh_link)
			(*mat.mesh_link)->SetLink(mesh_object);
	}
	mat.selection_name = selection_name;
	material_list_.Append(std::move(mat)) iferr_return;
	return true;
}

Bool MMDModelManagerObject::SavePMX(libmmd::PMXFile& pmx_file, const CMTToolsSetting::ModelExport& setting) const
{
	if (setting.export_bone)
		if (auto* bone_mgr = io_util::ResolveObjectLink(bone_manager_))
			if (const auto bmd = bone_mgr->GetNodeData<MMDBoneManagerObject>(); bmd && !bmd->SavePMX(pmx_file, setting))
				return false;

	if (setting.export_polygon)
		if (auto* mesh_mgr = io_util::ResolveObjectLink(mesh_manager_))
			if (const auto mmd = mesh_mgr->GetNodeData<MMDMeshManagerObject>(); mmd && !mmd->SavePMX(pmx_file, setting))
				return false;

	const Int32 mat_count = material_list_.GetCount();
	if (mat_count > 0)
	{
		pmx_file.m_materials.resize(static_cast<size_t>(mat_count));
		for (Int32 i = 0; i < mat_count; ++i)
			material_list_[i].ToPMX(pmx_file.m_materials[static_cast<size_t>(i)]);
	}

	const Int32 df_count = display_frame_list_.GetCount();
	if (df_count > 0)
	{
		pmx_file.m_displayFrames.resize(static_cast<size_t>(df_count));
		for (Int32 i = 0; i < df_count; ++i)
			display_frame_list_[i].ToPMX(pmx_file.m_displayFrames[static_cast<size_t>(i)]);
	}
	return true;
}

Bool MMDModelManagerObject::LoadVMDMotion(const libmmd::VMDFile& vmd_file, const CMTToolsSetting::MotionImport& setting, LoadVmdMotionLog& log, const Bool merge)
{
	iferr_scope_handler
	{
		return false;
	};
	const auto animation_name = setting.fn.GetFileString();
	libmmd::VMDAnimation* vmd_animation;
	if (!merge)
	{
		auto new_vmd_animation = std::make_unique<libmmd::VMDAnimation>();
		if (!new_vmd_animation)
		{
			LoadVmdMotionLog::LogOutMem();
			return false;
		}
		if (!new_vmd_animation->Create(mmd_model_))
		{
			LoadVmdMotionLog::LogOutMem();
			return false;
		}
		vmd_animation = new_vmd_animation.get();
		animations_.Append(std::make_pair(animation_name, std::move(new_vmd_animation)))iferr_return;
	}else
	{
		vmd_animation = animations_[animation_index_].second.get();
	}

	if (!vmd_animation)
	{
		LoadVmdMotionLog::LogOutMem();
		return false;
	}

	if (!vmd_animation->Add(vmd_file))
	{
		LoadVmdMotionLog::LogReadFileErr();
		return false;
	}

	if (!vmd_file.m_iks.empty())
	{
		ImportVMDIKKeyframes(vmd_file, setting);
		vmd_animation->SetApplyIKEnable(false);
	}

	log.imported_bone_count = vmd_file.m_motions.size();
	log.imported_morph_count = vmd_file.m_morphs.size();
	log.imported_motion_count = vmd_file.m_iks.size();

	const BaseTime max_time(vmd_animation->GetMaxKeyTime() ,30.);

	animation_index_ = static_cast<Int32>(animations_.GetCount()) - 1;
	animation_items_.SetString(animation_index_, animation_name);
	const auto node = Get();
	node->SetParameter(ConstDescID(DescLevel(MODEL_ANIM_LIST)), animation_index_, DESCFLAGS_SET::NONE);
	node->SetParameter(ConstDescID(DescLevel(MODEL_MODE)), MODEL_MODE_VMD, DESCFLAGS_SET::NONE);
	node->SetDirty(DIRTYFLAGS::DESCRIPTION);

	setting.doc->SetMaxTime(max_time);
	setting.doc->SetLoopMaxTime(max_time);

	EventAdd();
	return true;
}

Bool MMDModelManagerObject::SaveVMDMotion(libmmd::VMDFile& vmd_motion, const CMTToolsSetting::MotionExport& setting) const
{
	if (animation_index_ < 0 || animation_index_ >= animations_.GetCount())
		return false;
	const auto& [_, animation] = animations_[animation_index_];
	if (!animation)
		return false;
	return animation->Save(vmd_motion);
}

//Bool MMDModelManagerObject::SetMeshMorphAnimation(const libmmd::vmd_morph_key_frame& data,
//	const CMTToolsSetting::MotionImport& setting)
//{
//	const auto object = reinterpret_cast<BaseObject*>(Get());
//	const auto& morph_name = String(data.get_morph_name().c_str());
//	const auto frame_at_time = BaseTime{ data.get_frame_at() + setting.time_offset, 30.0 };
//	const auto morph_ptr = morph_map_.Find(morph_name);
//	if (!morph_ptr)
//	{
//		return false;
//	}
//	const auto& morph_id = morph_ptr->GetValue();
//	const auto& track_id = m_morph_arr[morph_id].GetStrengthDescID();
//	CTrack* track = object->FindCTrack(track_id);
//	if (!track)
//	{
//		track = CTrack::Alloc(object, track_id);
//		if (!track)
//		{
//			return false;
//		}
//		object->InsertTrackSorted(track);
//	}
//
//	const auto curve = track->GetCurve();
//	if (!curve)
//	{
//		return false;
//	}
//
//	CKey* key = curve->AddKey(frame_at_time);
//	if (!key)
//	{
//		return false;
//	}
//	key->SetValue(curve, data.get_weight());
//
//	return true;
//}
//
//bool MMDModelManagerObject::SetModelControllerAnimation(const libmmd::vmd_model_controller_key_frame& data,
//                                                     const CMTToolsSetting::MotionImport& setting)
//{
//	const auto frame_at_time = BaseTime{ data.get_frame_at() + setting.time_offset, 30.0 };
//	const auto object = reinterpret_cast<BaseObject*>(Get());
//
//	// set model visibility
//	const DescID track_desc_ids[] = { ConstDescID(DescLevel(ID_BASEOBJECT_VISIBILITY_EDITOR)),
//									  ConstDescID(DescLevel(ID_BASEOBJECT_VISIBILITY_RENDER)) };
//
//	for (auto track_index = int{}; track_index < 2; ++track_index)
//	{
//		auto& track_id = track_desc_ids[track_index];
//		CTrack* track = object->FindCTrack(track_id);
//		if (!track)
//		{
//			track = CTrack::Alloc(object, track_id);
//			if (!track)
//			{
//				return false;
//			}
//			object->InsertTrackSorted(track);
//		}
//
//		CCurve* curve = track->GetCurve();
//		if (!curve)
//		{
//			return false;
//		}
//
//		CKey* key = curve->AddKey(frame_at_time);
//		if (!key)
//		{
//			return false;
//		}
//
//		key->SetValue(curve, data.is_mode_show());
//	}
//
//	// set IK enable
//	const auto& ik_controller_data = data.get_vmd_IK_controller_array();
//	const auto ik_controller_data_count = ik_controller_data.size();
//	for (auto ik_controller_data_index = decltype(ik_controller_data_count){}; ik_controller_data_index < ik_controller_data_count; ++ik_controller_data_index)
//	{
//		const auto& ik_controller = ik_controller_data[ik_controller_data_index];
//		const auto& ik_bone_name = String(ik_controller.get_bone_name().c_str());
//		const auto& ik_enable = ik_controller.is_IK_enable();
//		auto add_key_func = [&frame_at_time, &ik_enable](BaseTag* ik_tag)
//			{
//				const auto track_id = ConstDescID(DescLevel(ID_CA_IK_TAG_ENABLE));
//				CTrack* track = ik_tag->FindCTrack(track_id);
//				if (!track)
//				{
//					track = CTrack::Alloc(ik_tag, track_id);
//					if (!track)
//					{
//						return false;
//					}
//					ik_tag->InsertTrackSorted(track);
//				}
//
//				CCurve* curve = track->GetCurve();
//				if (!curve)
//				{
//					return false;
//				}
//
//				CKey* key = curve->AddKey(frame_at_time);
//				if (!key)
//				{
//					return false;
//				}
//				key->SetValue(curve, ik_enable);
//				return true;
//			};
//		if (setting.import_by_local_name)
//		{
//			if (const auto ik_entry = ik_map_.Find(ik_bone_name); ik_entry)
//			{
//				if (const auto& ik_tag = ik_entry->GetValue(); !add_key_func(ik_tag))
//					return false;
//
//			}
//		}
//		else
//		{
//			for (const auto& ik_tag : ik_map_.GetValues())
//			{
//				if (ik_tag->GetName().IsEqual(ik_bone_name) && !add_key_func(ik_tag))
//					return false;
//			}
//		}
//	}
//
//	return true;
//}

Bool MMDModelManagerObject::DeleteVMDAnimation()
{
	iferr_scope_handler{ return false; };
	animation_items_.FlushAll();
	animation_items_.SetString(-1, GeLoadString(IDS_CMT_VMD_ANIM_NONE));
	maxon::BaseArray<std::pair<String, std::unique_ptr<libmmd::VMDAnimation>>> new_animations;
	const auto animation_count = animations_.GetCount();
	for (int i = 0, j = 0; i < animation_count; ++i)
	{
		if (i != animation_index_)
		{
			const auto& [animation_name, _] = new_animations.Append(std::move(animations_[i]))iferr_return;
			animation_items_.SetString(j++, animation_name);
		}
	}
	std::swap(new_animations, animations_);
	animation_index_ = -1;
	const auto node = Get();
	node->SetDirty(DIRTYFLAGS::DESCRIPTION);
	node->SetParameter(ConstDescID(DescLevel(MODEL_ANIM_LIST)), animation_index_, DESCFLAGS_SET::NONE);
	return true;
}

Bool MMDModelManagerObject::RebuildRuntime()
{
	iferr_scope_handler{ return false; };

	auto pmx_model = std::make_shared<PMXModel>();

	if (bone_manager_data_)
	{
		if (!bone_manager_data_->RebuildNodes(pmx_model.get()))
		{
			DebugOutput(maxon::OUTPUT::DIAGNOSTIC, "[CMT] RebuildRuntime: RebuildNodes FAILED");
			return false;
		}
	}

	auto* physics_manager = pmx_model->GetPhysicsManager();
	if (!physics_manager->Create())
	{
		DebugOutput(maxon::OUTPUT::DIAGNOSTIC, "[CMT] RebuildRuntime: PhysicsManager::Create FAILED");
		return false;
	}

	{
		const auto* bc = reinterpret_cast<BaseList2D*>(Get())->GetDataInstance();
		const Float pm = bc ? bc->GetFloat(MODEL_POSITION_MULTIPLE, 8.5) : 8.5;
		SyncSubManagerScale(pm);
	}

	if (rigid_manager_data_)
	{
		if (!rigid_manager_data_->RebuildRigidBodies(pmx_model.get()))
		{
			DebugOutput(maxon::OUTPUT::DIAGNOSTIC, "[CMT] RebuildRuntime: RebuildRigidBodies FAILED");
			return false;
		}

		auto* physics = physics_manager->GetMMDPhysics();
		auto* rigid_bodies = physics_manager->GetRigidBodys();
		if (physics && rigid_bodies)
		{
			for (const auto& rb : *rigid_bodies)
				physics->AddRigidBody(rb.get());
		}
	}

	if (joint_manager_data_)
	{
		if (!joint_manager_data_->RebuildJoints(physics_manager))
		{
			DebugOutput(maxon::OUTPUT::DIAGNOSTIC, "[CMT] RebuildRuntime: RebuildJoints FAILED");
			return false;
		}

		auto* physics = physics_manager->GetMMDPhysics();
		auto* joints = physics_manager->GetJoints();
		if (physics && joints)
		{
			for (const auto& jt : *joints)
				physics->AddJoint(jt.get());
		}
	}

	for (const auto& morph : morph_data_)
	{
		auto* pmx_morph = pmx_model->AddMorph();
		pmx_morph->SetName(string_util::GetStdString(morph.GetName()));
	}

	SetMMDModel(pmx_model);
	for (const auto& [name, vmd_data] : pending_vmd_data_)
	{
		if (vmd_data.empty())
			continue;

		libmmd::VMDFile vmd_file;
		if (!libmmd::ReadVMDFile(&vmd_file, vmd_data.data(), vmd_data.size()))
		{
			DebugOutput(maxon::OUTPUT::DIAGNOSTIC, "[CMT] RebuildRuntime: ReadVMDFile FAILED for '@' (size=@)", name, vmd_data.size());
			continue;
		}

		auto vmd_animation = std::make_unique<libmmd::VMDAnimation>();
		if (!vmd_animation->Create(pmx_model))
		{
			DebugOutput(maxon::OUTPUT::DIAGNOSTIC, "[CMT] RebuildRuntime: VMDAnimation::Create FAILED for '@'", name);
			continue;
		}
		if (!vmd_animation->Add(vmd_file))
		{
			DebugOutput(maxon::OUTPUT::DIAGNOSTIC, "[CMT] RebuildRuntime: VMDAnimation::Add FAILED for '@'", name);
			continue;
		}

		animations_.Append(std::make_pair(name, std::move(vmd_animation)))iferr_return;
	}
	iferr(pending_vmd_data_.Resize(0)) {}

	for (Int32 i = 0; i < animations_.GetCount(); ++i)
		animation_items_.SetString(i, animations_[i].first);

	if (animation_index_ >= 0 && animation_index_ < animations_.GetCount())
	{
		const auto& animation = animations_[animation_index_].second;
		if (animation)
		{
			if (auto* doc = Get()->GetDocument())
			{
				const BaseTime max_time(animation->GetMaxKeyTime(), 30.);
				doc->SetMaxTime(max_time);
				doc->SetLoopMaxTime(max_time);
			}
		}

		Get()->SetParameter(ConstDescID(DescLevel(MODEL_MODE)), MODEL_MODE_VMD, DESCFLAGS_SET::NONE);
	}

	ApplyIKSolverStates();

	if (bone_manager_data_)
	{
		bone_manager_data_->ReconnectNodePointers(pmx_model->GetNodeManager(), pmx_model->GetIKManager());
		if (animation_index_ >= 0 && animation_index_ < animations_.GetCount())
			bone_manager_data_->SetAllBoneMode(BONE_MODE_VMD);
	}
	if (rigid_manager_data_)
		rigid_manager_data_->ReconnectRigidBodyPointers(physics_manager);
	if (joint_manager_data_)
		joint_manager_data_->ReconnectJointPointers(physics_manager);

	pmx_model->ResetPhysics();
	*is_runtime_initialized_.Write() = true;
	is_animation_initialized_ = false;

	DebugOutput(maxon::OUTPUT::DIAGNOSTIC, "[CMT] RebuildRuntime: complete. animations=@, mmd_model=@", animations_.GetCount(), mmd_model_ != nullptr);
	return true;
}

Int32 MMDModelManagerObject::GetMorphNamedNumber()
{
	return morph_named_number_++;
}

MMDBoneManagerObject* MMDModelManagerObject::GetBoneManagerData()
{
	if (!bone_manager_data_)
		if (auto* obj = io_util::ResolveObjectLink(bone_manager_))
			bone_manager_data_ = obj->GetNodeData<MMDBoneManagerObject>();
	return bone_manager_data_;
}

MMDMeshManagerObject* MMDModelManagerObject::GetMeshManagerData()
{
	if (!mesh_manager_data_)
		if (auto* obj = io_util::ResolveObjectLink(mesh_manager_))
			mesh_manager_data_ = obj->GetNodeData<MMDMeshManagerObject>();
	return mesh_manager_data_;
}

MMDRigidManagerObject* MMDModelManagerObject::GetRigidManagerData()
{
	if (!rigid_manager_data_)
		if (auto* obj = io_util::ResolveObjectLink(rigid_manager_))
			rigid_manager_data_ = obj->GetNodeData<MMDRigidManagerObject>();
	return rigid_manager_data_;
}

MMDJointManagerObject* MMDModelManagerObject::GetJointManagerData()
{
	if (!joint_manager_data_)
		if (auto* obj = io_util::ResolveObjectLink(joint_manager_))
			joint_manager_data_ = obj->GetNodeData<MMDJointManagerObject>();
	return joint_manager_data_;
}

NodeData* MMDModelManagerObject::Alloc()
{
	return NewObjClear(MMDModelManagerObject);
}

Bool MMDModelManagerObject::AddToExecution(BaseObject* op, PriorityList* list)
{
	if (list == nullptr || op == nullptr)
	{
		return true;
	}
	list->Add(op, EXECUTIONPRIORITY_EXPRESSION - 1, EXECUTIONFLAGS::EXPRESSION);
	return true;
}
SDK2024_GetDDescription(MMDModelManagerObject)
{
	if (!description->LoadDescription(node->GetType()))
		return false;
	if (BaseContainer* settings = description->GetParameterI(ConstDescID(DescLevel(MODEL_ANIM_LIST)), nullptr))
		settings->SetContainer(DESC_CYCLE, animation_items_);
	material_list_items_.FlushAll();
	material_list_items_.SetString(MODEL_MATERIAL_NONE, GeLoadString(IDS_MODEL_MATERIAL_NONE));
	for (Int32 i = 0; i < material_list_.GetCount(); ++i)
		material_list_items_.SetString(i, FormatString("@: @", i, material_list_[i].name_local));
	if (BaseContainer* mat_settings = description->GetParameterI(ConstDescID(DescLevel(MODEL_MATERIAL_LIST)), nullptr))
		mat_settings->SetContainer(DESC_CYCLE, material_list_items_);

	display_frame_items_.FlushAll();
	display_frame_items_.SetString(MODEL_DISPLAY_FRAME_NONE, GeLoadString(IDS_MODEL_DISPLAY_FRAME_NONE));
	for (Int32 i = 0; i < display_frame_list_.GetCount(); ++i)
		display_frame_items_.SetString(i, FormatString("@: @", i, display_frame_list_[i].name));
	if (BaseContainer* df_settings = description->GetParameterI(ConstDescID(DescLevel(MODEL_DISPLAY_FRAME_LIST)), nullptr))
		df_settings->SetContainer(DESC_CYCLE, display_frame_items_);

	if (BaseContainer* add_target_settings = description->GetParameterI(ConstDescID(DescLevel(MODEL_DISPLAY_FRAME_ADD_TARGET)), nullptr))
	{
		BaseContainer target_cycle;
		const Int32 add_type = display_frame_add_type_;
		BaseContainer used_bones;
		BaseContainer used_morphs;
		for (const auto& frame : display_frame_list_)
		{
			for (const auto& t : frame.targets)
			{
				if (t.type == DisplayFrameTargetType::Bone)
					used_bones.SetBool(t.index, true);
				else
					used_morphs.SetBool(t.index, true);
			}
		}
		const MMDBoneManagerObject* bmd = bone_manager_data_;
		if (!bmd)
		{
			if (auto* bone_mgr = io_util::ResolveObjectLink(bone_manager_))
				bmd = bone_mgr->GetNodeData<MMDBoneManagerObject>();
			if (!bmd)
			{
				for (SDK2024_Const BaseObject* child = reinterpret_cast<SDK2024_Const BaseObject*>(node)->GetDown(); child; child = child->GetNext())
				{
					if (child->IsInstanceOf(g_mmd_bone_manager_object_id))
					{
						bmd = child->GetNodeData<MMDBoneManagerObject>();
						break;
					}
				}
			}
		}
		if (add_type == MODEL_DISPLAY_FRAME_ADD_TYPE_BONE && bmd)
		{
			SDK2024_Const BaseDocument* bone_doc = bmd->Get()->GetDocument();
			if (!bone_doc) bone_doc = reinterpret_cast<SDK2024_Const BaseObject*>(node)->GetDocument();
			for (const auto& entry : bmd->bone_list_)
			{
				const Int32 bone_index = static_cast<Int32>(entry.GetKey());
				if (bone_index >= 0 && !used_bones.GetBool(bone_index))
				{
					String bone_name = String::IntToString(bone_index);
					if (entry.GetValue() && *entry.GetValue())
					{
						if (const BaseTag* tag = static_cast<const BaseTag*>((*entry.GetValue())->GetLink(bone_doc)))
							if (const BaseObject* obj = const_cast<BaseTag*>(tag)->GetObject())
								bone_name = obj->GetName();
					}
					target_cycle.SetString(bone_index, bone_name);
				}
			}
		}
		else if (add_type == MODEL_DISPLAY_FRAME_ADD_TYPE_MORPH)
		{
			for (const auto& entry : morph_name_)
			{
				const Int32 morph_index = static_cast<Int32>(entry.GetValue());
				if (!used_morphs.GetBool(morph_index))
					target_cycle.SetString(morph_index, entry.GetKey());
			}
		}
		const Int32 first_id = target_cycle.GetIndexId(0);
		display_frame_add_target_empty_ = (first_id == NOTOK);
		if (!display_frame_add_target_empty_)
		{
			Bool found = false;
			for (Int32 idx = 0; ; ++idx)
			{
				const Int32 cid = target_cycle.GetIndexId(idx);
				if (cid == NOTOK) break;
				if (cid == display_frame_add_target_) { found = true; break; }
			}
			if (!found)
				display_frame_add_target_ = first_id;
		}
		add_target_settings->SetContainer(DESC_CYCLE, target_cycle);
	}

	if (model_mode_ == MODEL_MODE_VMD)
	{
		if (BaseContainer* settings = description->GetParameterI(ConstDescID(DescLevel(MODEL_MORPH_GRP)), nullptr))
			settings->SetBool(DESC_HIDE, true);
	}
	else if (model_mode_ != MODEL_MODE_EDIT)
	{
		constexpr Int32 morph_add_ids[] = {
			MODEL_MORPH_GROUP_ADD_NAME, MODEL_MORPH_GROUP_ADD_BUTTON,
			MODEL_MORPH_FLIP_ADD_NAME, MODEL_MORPH_FLIP_ADD_BUTTON,
			MODEL_MORPH_MATERIAL_ADD_NAME, MODEL_MORPH_MATERIAL_ADD_BUTTON,
			MODEL_MORPH_IMPULSE_ADD_NAME, MODEL_MORPH_IMPULSE_ADD_BUTTON
		};
		for (const auto desc_id : morph_add_ids)
		{
			if (BaseContainer* settings = description->GetParameterI(CreateDescID(DescLevel(desc_id)), nullptr))
				settings->SetBool(DESC_HIDE, true);
		}
	}

	const DescID* single_id = description->GetSingleDescID();
	if (const auto cid = ConstDescID(DescLevel(MODEL_INFO_GRP)); single_id == nullptr || cid.IsPartOf(*single_id, nullptr))
	{
		if (BaseContainer* settings = description->GetParameterI(cid, nullptr))
			settings->SetBool(DESC_GROUPSCALEV, true);
	}
	flags |= DESCFLAGS_DESC::LOADED;

	return SUPER::GetDDescription(node, description, flags);
}
Bool MMDModelManagerObject::Message(GeListNode* node, Int32 type, void* data)
{
	iferr_scope_handler{ return SUPER::Message(node,type,data); };
	switch (type)
	{
	case g_mmd_mesh_manager_object_id:
	{
		if (static_cast<MMDMeshManagerObjectMsg*>(data)->type == MMDMeshManagerObjectMsgType::MESH_MORPH_CHANGE)
		{
			*is_morph_initialized_.Write() = false;
		}
		break;
	}
	case g_mmd_bone_manager_object_id:
	{
		if (static_cast<MMDBoneManagerObjectMsg*>(data)->type == MMDBoneManagerObjectMsgType::BONE_MORPH_CHANGE)
		{
			*is_morph_initialized_.Write() = false;
		}
		break;
	}
	case MSG_DESCRIPTION_COMMAND:
	{
		/* check if it is a user data button */
		if (const auto* dc = static_cast<DescriptionCommand*>(data); dc->_descId[0].id == ID_USERDATA)
		{
			if (const auto desc_id_ptr = desc_id_map_.Find(dc->_descId); desc_id_ptr != nullptr)
			{
				const auto& [desc_type, morph_index] = desc_id_ptr->GetValue();
				auto& morph = morph_data_[morph_index];
				switch (desc_type)
				{
				case MMDModelRootDynamicDescriptionType::MORPH_EDITOR_BUTTON:
				{
					EditorSubMorphDialog dlg(this, &morph);
					dlg.Open(DLG_TYPE::MODAL, 100000, -1, -1, 0, 0);
					break;
				}
				case  MMDModelRootDynamicDescriptionType::MORPH_DELETE_BUTTON:
				{
					if (QuestionDialog(IDS_MES_BONE_MORPH_DELETE, morph.GetName()))
					{
						DeleteMorph(morph_index);
					}
					break;
				}
				case MMDModelRootDynamicDescriptionType::MORPH_RENAME_BUTTON:
				{
					auto new_name = morph.GetName();
					if (RenameDialog(&new_name))
					{
						RenameMorph(new_name);
					}
					break;
				}
				case MMDModelRootDynamicDescriptionType::MORPH_STRENGTH:
				case MMDModelRootDynamicDescriptionType::MORPH_GRP:
				case MMDModelRootDynamicDescriptionType::IK_BONE_LINK:
				case MMDModelRootDynamicDescriptionType::IK_SOLVER_ENABLE:
					break;
				case MMDModelRootDynamicDescriptionType::DISPLAY_FRAME_DELETE_BUTTON:
				{
					const Int entry_index = desc_id_ptr->GetValue().second;
					if (display_frame_selection_index_ >= 0 && display_frame_selection_index_ < display_frame_list_.GetCount())
					{
						auto& targets = display_frame_list_[display_frame_selection_index_].targets;
						if (entry_index >= 0 && entry_index < static_cast<Int>(targets.GetCount()))
						{
							targets.Erase(entry_index)iferr_ignore("erase failed");
							RebuildDisplayFrameUI();
						}
					}
					break;
				}
				case MMDModelRootDynamicDescriptionType::DISPLAY_FRAME_MOVE_UP_BUTTON:
				{
					const Int entry_index = desc_id_ptr->GetValue().second;
					if (display_frame_selection_index_ >= 0 && display_frame_selection_index_ < display_frame_list_.GetCount())
					{
						auto& targets = display_frame_list_[display_frame_selection_index_].targets;
						if (entry_index > 0 && entry_index < static_cast<Int>(targets.GetCount()))
						{
							std::swap(targets[entry_index], targets[entry_index - 1]);
							RebuildDisplayFrameUI();
						}
					}
					break;
				}
				case MMDModelRootDynamicDescriptionType::DISPLAY_FRAME_MOVE_DOWN_BUTTON:
				{
					const Int entry_index = desc_id_ptr->GetValue().second;
					if (display_frame_selection_index_ >= 0 && display_frame_selection_index_ < display_frame_list_.GetCount())
					{
						auto& targets = display_frame_list_[display_frame_selection_index_].targets;
						if (entry_index >= 0 && entry_index < static_cast<Int>(targets.GetCount()) - 1)
						{
							std::swap(targets[entry_index], targets[entry_index + 1]);
							RebuildDisplayFrameUI();
						}
					}
					break;
				}
				}
			}
		}
		else {
			switch (const auto id = dc->_descId[0].id)
			{
			case MODEL_MORPH_GROUP_ADD_BUTTON:
			{
				GeData ge_data;
				node->GetParameter(ConstDescID(DescLevel(MODEL_MORPH_GROUP_ADD_NAME)), ge_data, DESCFLAGS_GET::NONE);
				AddMorph(MMDMorphType::GROUP, ge_data.GetString());
				break;
			}
			case MODEL_MORPH_FLIP_ADD_BUTTON:
			{
				GeData ge_data;
				node->GetParameter(ConstDescID(DescLevel(MODEL_MORPH_FLIP_ADD_NAME)), ge_data, DESCFLAGS_GET::NONE);
				AddMorph(MMDMorphType::FLIP, ge_data.GetString());
				break;
			}
			case MODEL_MORPH_MATERIAL_ADD_BUTTON:
			{
				GeData ge_data;
				node->GetParameter(ConstDescID(DescLevel(MODEL_MORPH_MATERIAL_ADD_NAME)), ge_data, DESCFLAGS_GET::NONE);
				AddMorph(MMDMorphType::MATERIAL, ge_data.GetString());
				break;
			}
			case MODEL_MORPH_IMPULSE_ADD_BUTTON:
			{
				GeData ge_data;
				node->GetParameter(ConstDescID(DescLevel(MODEL_MORPH_IMPULSE_ADD_NAME)), ge_data, DESCFLAGS_GET::NONE);
				AddMorph(MMDMorphType::IMPULSE, ge_data.GetString());
				break;
			}
			case MODEL_DISPLAY_FRAME_ADD_BUTTON:
			{
				if (display_frame_selection_index_ >= 0 && display_frame_selection_index_ < display_frame_list_.GetCount()
				&& !display_frame_add_target_empty_)
				{
				DisplayFrameTargetData td;
				td.type = (display_frame_add_type_ == MODEL_DISPLAY_FRAME_ADD_TYPE_BONE)
					? DisplayFrameTargetType::Bone : DisplayFrameTargetType::Morph;
				td.index = display_frame_add_target_;
				iferr(display_frame_list_[display_frame_selection_index_].targets.Append(td)) break;
					RebuildDisplayFrameUI();
				}
				break;
			}
			case MODEL_DISPLAY_FRAME_NEW_BUTTON:
			{
				GeData name_data;
				node->GetParameter(ConstDescID(DescLevel(MODEL_DISPLAY_FRAME_NEW_NAME)), name_data, DESCFLAGS_GET::NONE);
				DisplayFrameData df;
				df.name = name_data.GetString();
				if (df.name.IsEmpty())
					df.name = FormatString("Frame @", display_frame_list_.GetCount());
				iferr(display_frame_list_.Append(std::move(df))) break;
				display_frame_selection_index_ = static_cast<Int32>(display_frame_list_.GetCount()) - 1;
				RebuildDisplayFrameUI();
				break;
			}
			case MODEL_DISPLAY_FRAME_DELETE_BUTTON:
			{
				if (display_frame_selection_index_ >= 0 && display_frame_selection_index_ < display_frame_list_.GetCount())
				{
					display_frame_list_.Erase(display_frame_selection_index_)iferr_ignore("erase failed");
					if (display_frame_selection_index_ >= display_frame_list_.GetCount())
						display_frame_selection_index_ = static_cast<Int32>(display_frame_list_.GetCount()) - 1;
					RebuildDisplayFrameUI();
				}
				break;
			}
			case MODEL_ANIM_MERGE_VMD_BUTTON: [[fallthrough]];
			case MODEL_ANIM_LOAD_VMD_BUTTON:
			{
			CMTToolsSetting::MotionImport setting(GetActiveDocument());
			if(!filename_util::SelectSuffixImportFile(setting.fn, "vmd"_s))
			{
				break;
			}
			{
				const auto* bc = reinterpret_cast<BaseList2D*>(Get())->GetDataInstance();
				if (bc)
					setting.position_multiple = bc->GetFloat(MODEL_POSITION_MULTIPLE, 8.5);
			}
				LoadVmdMotionLog logger;
				std::vector<uint8_t> file_data;
				if (!filename_util::ReadFileData(setting.fn, file_data))
				{
					LoadVmdMotionLog::LogReadFileErr();
					break;
				}
				libmmd::VMDFile vmd_file;
				if (!ReadVMDFile(&vmd_file, file_data.data(), file_data.size()))
				{
					LoadVmdMotionLog::LogReadFileErr();
					break;
				}
				if (!LoadVMDMotion(vmd_file, setting, logger, id == MODEL_ANIM_MERGE_VMD_BUTTON))
				{
					break;
				}
				setting.doc->SetTime(BaseTime(1, 30.));
				setting.doc->SetTime(BaseTime(0, 30.));
				EventAdd();
				logger.LogOK(setting.detail_report);
				break;
			}
			case MODEL_ANIM_DElETE_BUTTON:
			{
				DeleteVMDAnimation();
				break;
			}
			case MODEL_MATERIAL_CREATE_BUTTON:
			{
				if (material_selection_index_ >= 0 && material_selection_index_ < material_list_.GetCount())
				{
					auto& mat = material_list_[material_selection_index_];
					GeData type_data;
					node->GetParameter(ConstDescID(DescLevel(MODEL_MATERIAL_CREATE_TYPE)), type_data, DESCFLAGS_GET::NONE);
					constexpr MMDRendererMaterialType type_map[] = {
						MMDRendererMaterialType::Standard, MMDRendererMaterialType::RedShift,
						MMDRendererMaterialType::Octane,   MMDRendererMaterialType::Corona
					};
					const Int32 type_idx = type_data.GetInt32();
					const MMDRendererMaterialType rt = (type_idx >= 0 && type_idx < 4) ? type_map[type_idx] : MMDRendererMaterialType::Standard;
					BaseMaterial* new_mat = CreateMaterialFromData(mat, rt);
					if (new_mat)
					{
						BaseDocument* doc = node->GetDocument();
						if (doc)
						{
							doc->InsertMaterial(new_mat);
							if (!mat.material_link)
								mat.material_link = NewObj(AutoAlloc<BaseLink>).GetValue();
							if (mat.material_link && *mat.material_link)
								(*mat.material_link)->SetLink(new_mat);
							EventAdd();
						}
					}
				}
				break;
			}
			case MODEL_MATERIAL_SYNC_BUTTON:
			{
				if (material_selection_index_ >= 0 && material_selection_index_ < material_list_.GetCount())
				{
					auto& mat = material_list_[material_selection_index_];
					BaseDocument* doc = node->GetDocument();
					if (doc && mat.material_link && *mat.material_link)
					{
						BaseMaterial* linked_mat = static_cast<BaseMaterial*>((*mat.material_link)->GetLink(doc));
						if (linked_mat)
							SyncToMaterial(mat, linked_mat);
						EventAdd();
					}
				}
				break;
			}
			case MODEL_MATERIAL_REVERSE_SYNC_BUTTON:
			{
				if (material_selection_index_ >= 0 && material_selection_index_ < material_list_.GetCount())
				{
					auto& mat = material_list_[material_selection_index_];
					BaseDocument* doc = node->GetDocument();
					if (doc && mat.material_link && *mat.material_link)
					{
						BaseMaterial* linked_mat = static_cast<BaseMaterial*>((*mat.material_link)->GetLink(doc));
						if (linked_mat)
							ReadFromMaterial(linked_mat, mat);
						EventAdd();
					}
				}
				break;
			}
			case MODEL_MATERIAL_MOVE_UP_BUTTON:
			{
				if (material_selection_index_ > 0 && material_selection_index_ < material_list_.GetCount())
				{
					std::swap(material_list_[material_selection_index_], material_list_[material_selection_index_ - 1]);
					material_selection_index_--;
					::SendCoreMessage(COREMSG_CINEMA, BaseContainer(COREMSG_CINEMA_FORCE_AM_UPDATE));
					EventAdd();
				}
				break;
			}
			case MODEL_MATERIAL_MOVE_DOWN_BUTTON:
			{
				if (material_selection_index_ >= 0 && material_selection_index_ < material_list_.GetCount() - 1)
				{
					std::swap(material_list_[material_selection_index_], material_list_[material_selection_index_ + 1]);
					material_selection_index_++;
					::SendCoreMessage(COREMSG_CINEMA, BaseContainer(COREMSG_CINEMA_FORCE_AM_UPDATE));
					EventAdd();
				}
				break;
			}
			case MODEL_MATERIAL_DELETE_BUTTON:
			{
				if (material_selection_index_ >= 0 && material_selection_index_ < material_list_.GetCount())
				{
					if (!QuestionDialog(IDS_MES_MATERIAL_DELETE_CONFIRM))
						break;
					auto& mat = material_list_[material_selection_index_];
					BaseDocument* doc = node->GetDocument();
					if (doc)
					{
						doc->StartUndo();
						doc->AddUndo(UNDOTYPE::CHANGE, node);
						if (mat.mesh_link && *mat.mesh_link)
						{
							BaseObject* mesh_obj = static_cast<BaseObject*>((*mat.mesh_link)->GetLink(doc));
							if (mesh_obj)
							{
								if (mat.selection_name.IsPopulated())
								{
									SelectionTag* sel_tag = nullptr;
									for (BaseTag* tag = mesh_obj->GetFirstTag(); tag; tag = tag->GetNext())
									{
										if (tag->GetType() == Tpolygonselection && tag->GetName() == mat.selection_name)
										{
											sel_tag = static_cast<SelectionTag*>(tag);
											break;
										}
									}
									if (sel_tag)
									{
										PolygonObject* poly_obj = ToPoly(mesh_obj);
										if (poly_obj)
										{
											doc->AddUndo(UNDOTYPE::CHANGE, mesh_obj);
											const BaseSelect* poly_sel_const = poly_obj->GetPolygonS();
											BaseSelect* poly_sel = const_cast<BaseSelect*>(poly_sel_const);
											if (poly_sel)
											{
												poly_sel->DeselectAll();
												const_cast<BaseSelect*>(sel_tag->GetBaseSelect())->CopyTo(poly_sel);
												ModelingCommandData mcd;
												mcd.doc = doc;
												mcd.op = mesh_obj;
												mcd.mode = MODELINGCOMMANDMODE::POLYGONSELECTION;
												if (SendModelingCommand(MCOMMAND_DELETE, mcd))
												{
													BaseContainer opt;
													opt.SetBool(MDATA_OPTIMIZE_UNUSEDPOINTS, true);
													mcd.bc = &opt;
													mcd.mode = MODELINGCOMMANDMODE::ALL;
													SendModelingCommand(MCOMMAND_OPTIMIZE, mcd);
												}
											}
										}
										doc->AddUndo(UNDOTYPE::DELETEOBJ, sel_tag);
										sel_tag->Remove();
										BaseTag* tmp_sel_tag = sel_tag;
										BaseTag::Free(tmp_sel_tag);
									}
									for (BaseTag* tag = mesh_obj->GetFirstTag(); tag; tag = tag->GetNext())
									{
										if (tag->GetType() == Ttexture)
										{
											GeData sel_data;
											tag->GetParameter(ConstDescID(DescLevel(TEXTURETAG_RESTRICTION)), sel_data, DESCFLAGS_GET::NONE);
											if (sel_data.GetString() == mat.selection_name)
											{
												doc->AddUndo(UNDOTYPE::DELETEOBJ, tag);
												tag->Remove();
												BaseTag::Free(tag);
												break;
											}
										}
									}
								}
								else
								{
									doc->AddUndo(UNDOTYPE::DELETEOBJ, mesh_obj);
									mesh_obj->Remove();
									BaseObject::Free(mesh_obj);
								}
							}
						}
					}
					material_list_.Erase(material_selection_index_) iferr_ignore("erase failed"_s);
					if (material_selection_index_ >= material_list_.GetCount())
						material_selection_index_ = static_cast<Int32>(material_list_.GetCount()) - 1;
					if (mesh_manager_data_)
					{
						mesh_manager_data_->RequestMorphDataRefresh();
						*is_morph_initialized_.Write() = false;
					}
					::SendCoreMessage(COREMSG_CINEMA, BaseContainer(COREMSG_CINEMA_FORCE_AM_UPDATE));
					EventAdd();
					if (doc)
						doc->EndUndo();
				}
				break;
			}
			case MODEL_MATERIAL_ADD_BUTTON:
			{
				BaseDocument* doc = node->GetDocument();
				BaseObject* mesh_mgr_obj = GetMeshManagerObject();
				if (!doc || !mesh_mgr_obj)
					break;
				auto HasMaterialEntry = [this, doc](BaseObject* mesh_obj, const String& sel_name) -> Bool
				{
					for (const auto& m : material_list_)
					{
						if (!m.mesh_link || !*m.mesh_link)
							continue;
						if (static_cast<BaseObject*>((*m.mesh_link)->GetLink(doc)) != mesh_obj)
							continue;
						if ((sel_name.IsEmpty() && m.selection_name.IsEmpty()) ||
							(sel_name.IsPopulated() && m.selection_name == sel_name))
							return true;
					}
					return false;
				};
				auto FindExistingMaterial = [doc](BaseObject* mesh_obj, const String& sel_name) -> BaseMaterial*
				{
					for (BaseTag* tag = mesh_obj->GetFirstTag(); tag; tag = tag->GetNext())
					{
						if (tag->GetType() != Ttexture)
							continue;
						GeData sel_data;
						tag->GetParameter(ConstDescID(DescLevel(TEXTURETAG_RESTRICTION)), sel_data, DESCFLAGS_GET::NONE);
						if (sel_data.GetString() != sel_name)
							continue;
						GeData mat_data;
						tag->GetParameter(ConstDescID(DescLevel(TEXTURETAG_MATERIAL)), mat_data, DESCFLAGS_GET::NONE);
						BaseMaterial* mat = static_cast<BaseMaterial*>(mat_data.GetLink(doc));
						if (mat)
							return mat;
					}
					return nullptr;
				};
				GeData type_data;
				node->GetParameter(ConstDescID(DescLevel(MODEL_MATERIAL_CREATE_TYPE)), type_data, DESCFLAGS_GET::NONE);
				constexpr MMDRendererMaterialType type_map[] = {
					MMDRendererMaterialType::Standard, MMDRendererMaterialType::RedShift,
					MMDRendererMaterialType::Octane,   MMDRendererMaterialType::Corona
				};
				const Int32 type_idx = type_data.GetInt32();
				const MMDRendererMaterialType create_type = (type_idx >= 0 && type_idx < 4) ? type_map[type_idx] : MMDRendererMaterialType::Standard;
				auto AddMaterialEntry = [&](BaseObject* child, const String& sel_name, const String& display_name) -> Bool
				{
					MMDMaterialData new_mat;
					new_mat.name_local = new_mat.name_universal = display_name;
					new_mat.mesh_link = maxon::StrongRef<AutoAlloc<BaseLink>>::Create().GetValue();
					if (new_mat.mesh_link && *new_mat.mesh_link)
						(*new_mat.mesh_link)->SetLink(child);
					new_mat.selection_name = sel_name;
					BaseMaterial* existing_mat = FindExistingMaterial(child, sel_name);
					if (existing_mat)
					{
						ReadFromMaterial(existing_mat, new_mat);
						new_mat.material_link = maxon::StrongRef<AutoAlloc<BaseLink>>::Create().GetValue();
						if (new_mat.material_link && *new_mat.material_link)
							(*new_mat.material_link)->SetLink(existing_mat);
					}
					else
					{
						BaseMaterial* c4d_mat = CreateMaterialFromData(new_mat, create_type);
						if (c4d_mat)
						{
							doc->InsertMaterial(c4d_mat);
							doc->AddUndo(UNDOTYPE::NEWOBJ, c4d_mat);
							new_mat.material_link = maxon::StrongRef<AutoAlloc<BaseLink>>::Create().GetValue();
							if (new_mat.material_link && *new_mat.material_link)
								(*new_mat.material_link)->SetLink(c4d_mat);
							TextureTag* tex_tag = TextureTag::Alloc();
							if (tex_tag)
							{
								tex_tag->SetName(display_name);
								tex_tag->SetMaterial(c4d_mat);
								tex_tag->SetParameter(ConstDescID(DescLevel(TEXTURETAG_PROJECTION)), TEXTURETAG_PROJECTION_UVW, DESCFLAGS_SET::NONE);
								if (sel_name.IsPopulated())
									tex_tag->SetParameter(ConstDescID(DescLevel(TEXTURETAG_RESTRICTION)), sel_name, DESCFLAGS_SET::NONE);
								child->InsertTag(tex_tag);
								doc->AddUndo(UNDOTYPE::NEWOBJ, tex_tag);
							}
						}
					}
					iferr(material_list_.Append(std::move(new_mat)))
						return false;
					return true;
				};
				Bool added = false;
				doc->StartUndo();
				doc->AddUndo(UNDOTYPE::CHANGE, node);
				for (BaseObject* child = mesh_mgr_obj->GetDown(); child; child = child->GetNext())
				{
					if (child->GetType() != Opolygon)
						continue;
					Bool has_sel_tags = false;
					for (BaseTag* tag = child->GetFirstTag(); tag; tag = tag->GetNext())
					{
						if (tag->GetType() == Tpolygonselection)
						{
							has_sel_tags = true;
							const String tag_name = tag->GetName();
							if (!HasMaterialEntry(child, tag_name))
							{
								if (AddMaterialEntry(child, tag_name, tag_name))
									added = true;
							}
						}
					}
					if (!has_sel_tags && !HasMaterialEntry(child, ""_s))
					{
						if (AddMaterialEntry(child, ""_s, child->GetName()))
							added = true;
					}
				}
				if (added)
				{
					material_selection_index_ = static_cast<Int32>(material_list_.GetCount()) - 1;
					::SendCoreMessage(COREMSG_CINEMA, BaseContainer(COREMSG_CINEMA_FORCE_AM_UPDATE));
					EventAdd();
				}
				doc->EndUndo();
				break;
			}
			default:
				break;
			}
		}
		break;
	}
	case MSG_MENUPREPARE:
	{
		CreateManagers();
		SetMMDModel(std::make_shared<PMXModel>());
		break;
	}
	default:
		break;
	}
	return SUPER::Message(node, type, data);
}

SDK2024_GetDParameter(MMDModelManagerObject)
{
#if API_VERSION < 2024000
	GeListNode* paramNode = node;
#else
	const GeListNode* paramNode = node;
#endif

	switch (id[0].id)
	{
	case MODEL_MODE:
		t_data.SetInt32(model_mode_);
		flags |= DESCFLAGS_GET::PARAM_GET;
		return true;
	case MODEL_ANIM_LIST:
		t_data.SetInt32(animation_index_);
		flags |= DESCFLAGS_GET::PARAM_GET;
		return true;
	case MODEL_MATERIAL_LIST:
		t_data.SetInt32(material_selection_index_);
		flags |= DESCFLAGS_GET::PARAM_GET;
		return true;
	case MODEL_DISPLAY_FRAME_LIST:
		t_data.SetInt32(display_frame_selection_index_);
		flags |= DESCFLAGS_GET::PARAM_GET;
		return true;
	case MODEL_DISPLAY_FRAME_NAME_LOCAL:
		if (display_frame_selection_index_ >= 0 && display_frame_selection_index_ < display_frame_list_.GetCount())
			t_data.SetString(display_frame_list_[display_frame_selection_index_].name);
		else
			t_data.SetString(""_s);
		flags |= DESCFLAGS_GET::PARAM_GET;
		return true;
	case MODEL_DISPLAY_FRAME_NAME_UNIVERSAL:
		if (display_frame_selection_index_ >= 0 && display_frame_selection_index_ < display_frame_list_.GetCount())
			t_data.SetString(display_frame_list_[display_frame_selection_index_].name_universal);
		else
			t_data.SetString(""_s);
		flags |= DESCFLAGS_GET::PARAM_GET;
		return true;
	case MODEL_DISPLAY_FRAME_ADD_TYPE:
		t_data.SetInt32(display_frame_add_type_);
		flags |= DESCFLAGS_GET::PARAM_GET;
		return true;
	case MODEL_DISPLAY_FRAME_ADD_TARGET:
		t_data.SetInt32(display_frame_add_target_);
		flags |= DESCFLAGS_GET::PARAM_GET;
		return true;
	default:
		break;
	}

	const Int32 sel = material_selection_index_;
	if (sel < 0 || sel >= material_list_.GetCount())
	{
		return SUPER::GetDParameter(paramNode, id, t_data, flags);
	}
	const MMDMaterialData& m = material_list_[sel];
	switch (id[0].id)
	{
	case MODEL_MATERIAL_LINK:
		if (m.material_link && *m.material_link)
		{
			const BaseDocument* doc = paramNode->GetDocument();
			t_data.SetBaseList2D(const_cast<BaseList2D*>(doc ? (*m.material_link)->GetLink(doc) : nullptr));
		}
		else
			t_data.SetBaseList2D(nullptr);
		flags |= DESCFLAGS_GET::PARAM_GET;
		return SUPER::GetDParameter(paramNode, id, t_data, flags);
	case MODEL_MATERIAL_NAME_LOCAL: t_data.SetString(m.name_local); flags |= DESCFLAGS_GET::PARAM_GET; return true;
	case MODEL_MATERIAL_NAME_UNIVERSAL: t_data.SetString(m.name_universal); flags |= DESCFLAGS_GET::PARAM_GET; return true;
	case MODEL_MATERIAL_DIFFUSE_COLOR: HandleDescGetVector(id, m.diffuse_rgb, t_data, flags); return true;
	case MODEL_MATERIAL_DIFFUSE_ALPHA: t_data.SetFloat(m.diffuse_alpha); flags |= DESCFLAGS_GET::PARAM_GET; return true;
	case MODEL_MATERIAL_SPECULAR_COLOR: HandleDescGetVector(id, m.specular, t_data, flags); return true;
	case MODEL_MATERIAL_SPECULAR_POWER: t_data.SetFloat(m.specular_power); flags |= DESCFLAGS_GET::PARAM_GET; return true;
	case MODEL_MATERIAL_AMBIENT_COLOR: HandleDescGetVector(id, m.ambient, t_data, flags); return true;
	case MODEL_MATERIAL_DRAW_BOTH_FACE: t_data.SetInt32(m.draw_both_face ? 1 : 0); flags |= DESCFLAGS_GET::PARAM_GET; return true;
	case MODEL_MATERIAL_DRAW_GROUND_SHADOW: t_data.SetInt32(m.draw_ground_shadow ? 1 : 0); flags |= DESCFLAGS_GET::PARAM_GET; return true;
	case MODEL_MATERIAL_DRAW_CAST_SELF_SHADOW: t_data.SetInt32(m.draw_cast_self_shadow ? 1 : 0); flags |= DESCFLAGS_GET::PARAM_GET; return true;
	case MODEL_MATERIAL_DRAW_RECEIVE_SELF_SHADOW: t_data.SetInt32(m.draw_receive_self_shadow ? 1 : 0); flags |= DESCFLAGS_GET::PARAM_GET; return true;
	case MODEL_MATERIAL_DRAW_VERTEX_COLOR: t_data.SetInt32(m.draw_vertex_color ? 1 : 0); flags |= DESCFLAGS_GET::PARAM_GET; return true;
	case MODEL_MATERIAL_EDGE_ENABLED: t_data.SetInt32(m.edge_enabled ? 1 : 0); flags |= DESCFLAGS_GET::PARAM_GET; return true;
	case MODEL_MATERIAL_EDGE_SIZE: t_data.SetFloat(m.edge_size); flags |= DESCFLAGS_GET::PARAM_GET; return true;
	case MODEL_MATERIAL_EDGE_COLOR: HandleDescGetVector(id, m.edge_color_rgb, t_data, flags); return true;
	case MODEL_MATERIAL_EDGE_ALPHA: t_data.SetFloat(m.edge_color_alpha); flags |= DESCFLAGS_GET::PARAM_GET; return true;
	case MODEL_MATERIAL_TEXTURE_PATH: t_data.SetString(m.texture_path); flags |= DESCFLAGS_GET::PARAM_GET; return true;
	case MODEL_MATERIAL_SPHERE_TEXTURE_PATH: t_data.SetString(m.sphere_texture_path); flags |= DESCFLAGS_GET::PARAM_GET; return true;
	case MODEL_MATERIAL_SPHERE_MODE: t_data.SetInt32(m.sphere_mode); flags |= DESCFLAGS_GET::PARAM_GET; return true;
	case MODEL_MATERIAL_TOON_MODE: t_data.SetInt32(m.toon_mode); flags |= DESCFLAGS_GET::PARAM_GET; return true;
	case MODEL_MATERIAL_TOON_TEXTURE_INDEX: t_data.SetInt32(m.toon_texture_index); flags |= DESCFLAGS_GET::PARAM_GET; return true;
	case MODEL_MATERIAL_TOON_TEXTURE_PATH:
		if (m.toon_texture_index >= 0 && m.toon_texture_path.IsEmpty())
		{
			Char buf[20];
			snprintf(buf, sizeof(buf), "toon%02d.bmp", static_cast<int>(m.toon_texture_index + 1));
			t_data.SetString((GeGetPluginResourcePath() + Filename("mikumikudance_data") + Filename(buf)).GetString());
		}
		else
			t_data.SetString(m.toon_texture_path);
		flags |= DESCFLAGS_GET::PARAM_GET;
		return true;
	case MODEL_MATERIAL_MEMO: t_data.SetString(m.memo); flags |= DESCFLAGS_GET::PARAM_GET; return true;
	case MODEL_MATERIAL_FACE_COUNT: t_data.SetString(String::IntToString(m.num_face_vertices / 3)); flags |= DESCFLAGS_GET::PARAM_GET; return true;
	case MODEL_MATERIAL_MESH_LINK:
		if (m.mesh_link && *m.mesh_link)
		{
			const BaseDocument* doc = paramNode->GetDocument();
			t_data.SetBaseList2D(const_cast<BaseList2D*>(doc ? (*m.mesh_link)->GetLink(doc) : nullptr));
		}
		else
			t_data.SetBaseList2D(nullptr);
		flags |= DESCFLAGS_GET::PARAM_GET;
		return SUPER::GetDParameter(paramNode, id, t_data, flags);
	case MODEL_MATERIAL_SELECTION: t_data.SetString(m.selection_name); flags |= DESCFLAGS_GET::PARAM_GET; return true;
	default:
		break;
	}
	return SUPER::GetDParameter(paramNode, id, t_data, flags);
}

Bool MMDModelManagerObject::SetDParameter(GeListNode* node, const DescID& id, const GeData& t_data, DESCFLAGS_SET& flags)
{
	switch (id[0].id)
	{
		case MODEL_POSITION_MULTIPLE:
		{
			SyncSubManagerScale(t_data.GetFloat());
			break;
		}
		case MODEL_MODE:
		{
			model_mode_ = t_data.GetInt32();
			is_animation_initialized_ = false;
			prev_time_ = BaseTime(-1.);
			MMDModelManagerObjectMsg msg(MMDModelManagerObjectMsgType::MODEL_MODE_CHANGE, nullptr, model_mode_);
			node->MultiMessage(MULTIMSG_ROUTE::DOWN, g_mmd_model_manager_object_id, &msg);
			break;
		}
		case MODEL_ANIM_LIST:
		{
			animation_index_ = t_data.GetInt32();
			is_animation_initialized_ = false;
			prev_time_ = BaseTime(-1.);
			const auto doc = node->GetDocument();
			doc->SetTime({});
			if (animation_index_ != -1 && animation_index_ < animations_.GetCount())
			{
				const auto& animation = animations_[animation_index_].second;
				const BaseTime max_time(animation->GetMaxKeyTime() ,30.);
				doc->SetMaxTime(max_time);
				doc->SetLoopMaxTime(max_time);
			}
			break;
		}
		case MODEL_MATERIAL_LIST:
			material_selection_index_ = t_data.GetInt32();
			break;
		case MODEL_DISPLAY_FRAME_LIST:
			display_frame_selection_index_ = t_data.GetInt32();
			RebuildDisplayFrameUI();
			break;
		case MODEL_DISPLAY_FRAME_NAME_LOCAL:
			if (display_frame_selection_index_ >= 0 && display_frame_selection_index_ < display_frame_list_.GetCount())
			{
				display_frame_list_[display_frame_selection_index_].name = t_data.GetString();
				flags |= DESCFLAGS_SET::PARAM_SET;
				return true;
			}
			break;
		case MODEL_DISPLAY_FRAME_NAME_UNIVERSAL:
			if (display_frame_selection_index_ >= 0 && display_frame_selection_index_ < display_frame_list_.GetCount())
			{
				display_frame_list_[display_frame_selection_index_].name_universal = t_data.GetString();
				flags |= DESCFLAGS_SET::PARAM_SET;
				return true;
			}
			break;
		case MODEL_DISPLAY_FRAME_ADD_TYPE:
			display_frame_add_type_ = t_data.GetInt32();
			node->SetDirty(DIRTYFLAGS::DESCRIPTION);
			::SendCoreMessage(COREMSG_CINEMA, BaseContainer(COREMSG_CINEMA_FORCE_AM_UPDATE));
			EventAdd();
			break;
		case MODEL_DISPLAY_FRAME_ADD_TARGET:
			display_frame_add_target_ = t_data.GetInt32();
			break;
		default:
		{
			if (id[0].id == ID_USERDATA)
			{
				if (const auto* entry = desc_id_map_.Find(id))
				{
					const auto& [type, solver_index] = entry->GetValue();
					if (type == MMDModelRootDynamicDescriptionType::IK_SOLVER_ENABLE)
					{
						const Bool enabled = t_data.GetBool();
						if (mmd_model_)
						{
							if (auto* solver = mmd_model_->GetIKManager()->GetMMDIKSolver(static_cast<size_t>(solver_index)))
							{
								solver->Enable(enabled);
								iferr(ik_solver_enable_states_.Insert(String(solver->GetName().c_str()), enabled)) {}
							}
						}
						return SUPER::SetDParameter(node, id, t_data, flags);
					}
				}
			}

			Bool material_handled = false;
			if (material_selection_index_ >= 0 && material_selection_index_ < material_list_.GetCount())
			{
				MMDMaterialData& mat = material_list_[material_selection_index_];
				switch (id[0].id)
				{
				case MODEL_MATERIAL_LINK:
				{
					BaseDocument* doc = node->GetDocument();
					BaseMaterial* link_mat = static_cast<BaseMaterial*>(t_data.GetLink(doc));
					if (!mat.material_link || !*mat.material_link)
					{
						auto link_result = maxon::StrongRef<AutoAlloc<BaseLink>>::Create();
						if (link_result == maxon::FAILED)
							break;
						mat.material_link = link_result.GetValue();
						if (mat.material_link && *mat.material_link)
							(*mat.material_link)->SetLink(link_mat);
					}
					else
						(*mat.material_link)->SetLink(link_mat);
					material_handled = true;
					break;
				}
				case MODEL_MATERIAL_NAME_LOCAL: mat.name_local = t_data.GetString(); material_handled = true; break;
				case MODEL_MATERIAL_NAME_UNIVERSAL: mat.name_universal = t_data.GetString(); material_handled = true; break;
				case MODEL_MATERIAL_DIFFUSE_COLOR: mat.diffuse_rgb = t_data.GetVector(); material_handled = true; break;
				case MODEL_MATERIAL_DIFFUSE_ALPHA: mat.diffuse_alpha = t_data.GetFloat(); material_handled = true; break;
				case MODEL_MATERIAL_SPECULAR_COLOR: mat.specular = t_data.GetVector(); material_handled = true; break;
				case MODEL_MATERIAL_SPECULAR_POWER: mat.specular_power = t_data.GetFloat(); material_handled = true; break;
				case MODEL_MATERIAL_AMBIENT_COLOR: mat.ambient = t_data.GetVector(); material_handled = true; break;
				case MODEL_MATERIAL_DRAW_BOTH_FACE: mat.draw_both_face = t_data.GetBool(); material_handled = true; break;
				case MODEL_MATERIAL_DRAW_GROUND_SHADOW: mat.draw_ground_shadow = t_data.GetBool(); material_handled = true; break;
				case MODEL_MATERIAL_DRAW_CAST_SELF_SHADOW: mat.draw_cast_self_shadow = t_data.GetBool(); material_handled = true; break;
				case MODEL_MATERIAL_DRAW_RECEIVE_SELF_SHADOW: mat.draw_receive_self_shadow = t_data.GetBool(); material_handled = true; break;
				case MODEL_MATERIAL_DRAW_VERTEX_COLOR: mat.draw_vertex_color = t_data.GetBool(); material_handled = true; break;
				case MODEL_MATERIAL_EDGE_ENABLED: mat.edge_enabled = t_data.GetBool(); material_handled = true; break;
				case MODEL_MATERIAL_EDGE_SIZE: mat.edge_size = t_data.GetFloat(); material_handled = true; break;
				case MODEL_MATERIAL_EDGE_COLOR: mat.edge_color_rgb = t_data.GetVector(); material_handled = true; break;
				case MODEL_MATERIAL_EDGE_ALPHA: mat.edge_color_alpha = t_data.GetFloat(); material_handled = true; break;
				case MODEL_MATERIAL_TEXTURE_PATH: mat.texture_path = t_data.GetString(); material_handled = true; break;
				case MODEL_MATERIAL_SPHERE_TEXTURE_PATH: mat.sphere_texture_path = t_data.GetString(); material_handled = true; break;
				case MODEL_MATERIAL_SPHERE_MODE: mat.sphere_mode = t_data.GetInt32(); material_handled = true; break;
				case MODEL_MATERIAL_TOON_MODE:
				{
					mat.toon_mode = t_data.GetInt32();
					if (mat.toon_mode == 1 && mat.toon_texture_index >= 0)
					{
						Char buf[20];
						snprintf(buf, sizeof(buf), "toon%02d.bmp", static_cast<int>(mat.toon_texture_index + 1));
						mat.toon_texture_path = (GeGetPluginResourcePath() + Filename("mikumikudance_data") + Filename(buf)).GetString();
					}
					material_handled = true;
					break;
				}
				case MODEL_MATERIAL_TOON_TEXTURE_INDEX:
				{
					mat.toon_texture_index = t_data.GetInt32();
					if (mat.toon_mode == 1 && mat.toon_texture_index >= 0)
					{
						Char buf[20];
						snprintf(buf, sizeof(buf), "toon%02d.bmp", static_cast<int>(mat.toon_texture_index + 1));
						mat.toon_texture_path = (GeGetPluginResourcePath() + Filename("mikumikudance_data") + Filename(buf)).GetString();
					}
					material_handled = true;
					break;
				}
				case MODEL_MATERIAL_TOON_TEXTURE_PATH:
					if (mat.toon_texture_index == -1)
						mat.toon_texture_path = t_data.GetString();
					material_handled = true;
					break;
				case MODEL_MATERIAL_MEMO: mat.memo = t_data.GetString(); material_handled = true; break;
				case MODEL_MATERIAL_MESH_LINK:
				{
					BaseDocument* doc = node->GetDocument();
					BaseObject* link_obj = static_cast<BaseObject*>(t_data.GetLink(doc));
					if (!mat.mesh_link || !*mat.mesh_link)
					{
						auto link_result = maxon::StrongRef<AutoAlloc<BaseLink>>::Create();
						if (link_result == maxon::FAILED)
							break;
						mat.mesh_link = link_result.GetValue();
						if (mat.mesh_link && *mat.mesh_link)
							(*mat.mesh_link)->SetLink(link_obj);
					}
					else
						(*mat.mesh_link)->SetLink(link_obj);
					material_handled = true;
					break;
				}
				case MODEL_MATERIAL_SELECTION: mat.selection_name = t_data.GetString(); material_handled = true; break;
				default: break;
				}
				if (material_handled)
				{
					BaseDocument* doc = node->GetDocument();
					BaseMaterial* linked_mat = doc && mat.material_link && *mat.material_link
						? static_cast<BaseMaterial*>((*mat.material_link)->GetLink(doc))
						: nullptr;
					if (linked_mat)
						SyncToMaterial(mat, linked_mat);
					flags |= DESCFLAGS_SET::PARAM_SET;
					return true;
				}
			}
			if (material_handled)
				return true;
			break;
		}
	}
	return ObjectData::SetDParameter(node, id, t_data, flags);
}

SDK2024_GetDEnabling(MMDModelManagerObject)
{
	if (id[0].id == ID_USERDATA)
	{
		if (const auto* entry = desc_id_map_.Find(id))
		{
			if (entry->GetValue().first == MMDModelRootDynamicDescriptionType::IK_SOLVER_ENABLE)
				return true;
		}
	}
	if (id[0].id >= MODEL_MATERIAL_NAME_LOCAL && id[0].id < MODEL_MATERIAL_ADD_BUTTON)
	{
		return material_selection_index_ >= 0 && material_selection_index_ < material_list_.GetCount();
	}
	switch (id[0].id)
	{
	case MODEL_DISPLAY_FRAME_NAME_LOCAL:
	case MODEL_DISPLAY_FRAME_NAME_UNIVERSAL:
	case MODEL_DISPLAY_FRAME_ADD_TYPE:
	case MODEL_DISPLAY_FRAME_ADD_TARGET:
	case MODEL_DISPLAY_FRAME_DELETE_BUTTON:
		return display_frame_selection_index_ >= 0 && display_frame_selection_index_ < display_frame_list_.GetCount();
	case MODEL_DISPLAY_FRAME_ADD_BUTTON:
		return display_frame_selection_index_ >= 0 && display_frame_selection_index_ < display_frame_list_.GetCount()
			&& !display_frame_add_target_empty_;
	case MODEL_MATERIAL_EDGE_SIZE:
	case MODEL_MATERIAL_EDGE_COLOR:
	case MODEL_MATERIAL_EDGE_ALPHA:
		if (material_selection_index_ >= 0 && material_selection_index_ < material_list_.GetCount())
			return material_list_[material_selection_index_].edge_enabled;
		return false;
	case MODEL_MATERIAL_TOON_TEXTURE_INDEX:
		if (material_selection_index_ >= 0 && material_selection_index_ < material_list_.GetCount())
			return material_list_[material_selection_index_].toon_mode == 1;
		return false;
	case MODEL_MATERIAL_CREATE_BUTTON:
	case MODEL_MATERIAL_CREATE_TYPE:
		return material_selection_index_ >= 0 && material_selection_index_ < material_list_.GetCount();
	case MODEL_MATERIAL_MOVE_UP_BUTTON:
		return material_selection_index_ > 0;
	case MODEL_MATERIAL_MOVE_DOWN_BUTTON:
		return material_selection_index_ >= 0 && material_selection_index_ < static_cast<Int32>(material_list_.GetCount()) - 1;
	case MODEL_MATERIAL_DELETE_BUTTON:
		return material_selection_index_ >= 0 && material_selection_index_ < material_list_.GetCount();
	case MODEL_MATERIAL_SYNC_BUTTON:
	case MODEL_MATERIAL_REVERSE_SYNC_BUTTON:
		if (material_selection_index_ >= 0 && material_selection_index_ < material_list_.GetCount())
		{
			const auto& mat = material_list_[material_selection_index_];
			if (mat.material_link && *mat.material_link)
			{
				SDK2024_Const BaseDocument* doc = node->GetDocument();
				return doc && (*mat.material_link)->GetLink(doc) != nullptr;
			}
		}
		return false;
	default:
		break;
	}
	return SUPER::GetDEnabling(node, id, t_data, flags, itemdesc);
}

Int MMDModelManagerObject::AddMorph(const MMDMorphType& morph_type, String morph_name, bool is_add_morph_ui, Int32 panel)
{
	Int index = -1;
	iferr_scope_handler{ return index; };
	IMorph* morph = nullptr;
	switch (morph_type)
	{
	case MMDMorphType::GROUP:
		if (morph_name.IsEmpty())
		{
			morph_name = FormatString("Group morph @", GetMorphNamedNumber());
		}
		morph = NewObj(GroupMorph, morph_name)iferr_return;
		break;
	case MMDMorphType::FLIP:
		if (morph_name.IsEmpty())
		{
			morph_name = FormatString("Flip morph @", GetMorphNamedNumber());
		}
		morph = NewObj(FlipMorph, morph_name)iferr_return;
		break;
	case MMDMorphType::MESH:
		if (morph_name.IsEmpty())
		{
			morph_name = FormatString("Mesh morph @", GetMorphNamedNumber());
		}
		morph = NewObj(MeshMorph, morph_name)iferr_return;
		break;
	case MMDMorphType::UV:
		if (morph_name.IsEmpty())
		{
			morph_name = FormatString("UV morph @", GetMorphNamedNumber());
		}
		morph = NewObj(UVMorph, morph_name)iferr_return;
		break;
	case MMDMorphType::BONE:
		if (morph_name.IsEmpty())
		{
			morph_name = FormatString("Bone morph @", GetMorphNamedNumber());
		}
		morph = NewObj(BoneMorph, morph_name)iferr_return;
		break;
	case MMDMorphType::MATERIAL:
		if (morph_name.IsEmpty())
		{
			morph_name = FormatString("Material morph @", GetMorphNamedNumber());
		}
		morph = NewObj(MaterialMorph, morph_name)iferr_return;
		break;
	case MMDMorphType::IMPULSE:
		if (morph_name.IsEmpty())
		{
			morph_name = FormatString("Impulse morph @", GetMorphNamedNumber());
		}
		morph = NewObj(ImpulseMorph, morph_name)iferr_return;
		break;
	case MMDMorphType::DEFAULT:
		break;
	}
	if(!morph)
		return index;
	morph->SetPanel(panel);
	morph_data_.AppendPtr(morph)iferr_return;
	index = morph_data_.GetIndex(*morph);
	iferr(morph_name_.Insert(morph_name, index))
	{
		morph_data_.Erase(index)iferr_return;
		index = -1;
		return index;
	}
	if (is_add_morph_ui)
	{
		morph->AddMorphUI(*this, index);
		// Dynamic DTYPE_REAL defaults to 1.0; MMD morph weight is 0 until posed.
		if (GeListNode* const self = Get())
			morph->SetStrength(self, 0.0);
	}
	return index;
}

void MMDModelManagerObject::RenameMorph(const String& name)
{
	DynamicDescription* const dynamic_description = Get()->GetDynamicDescriptionWritable();
	if (dynamic_description == nullptr)
		return;
	if(const auto morph_id_ptr = morph_name_.Find(name); morph_id_ptr)
	{
		if (const auto& index = morph_id_ptr->GetValue(); index < GetMorphNum())
		{
			iferr(morph_name_.Insert(name, index))
				return;
			iferr(morph_name_.Erase(morph_id_ptr))
				return;
			auto& morph = morph_data_[index];
			const DescID& strength_id = morph.GetStrengthDescID();
			BaseContainer description_bc = *dynamic_description->Find(strength_id);
			description_bc.SetString(DESC_NAME, name);
			dynamic_description->Set(strength_id, description_bc, nullptr);
			morph.RenameMorph(name);
		}
	}

	::SendCoreMessage(COREMSG_CINEMA, BaseContainer(COREMSG_CINEMA_FORCE_AM_UPDATE));
	if (::GeIsMainThread())
	{
		::EventAdd();
	}
}

void MMDModelManagerObject::UpdateMorph(IMorph& morph)
{
	morph.UpdateMorph(*this);
}

void MMDModelManagerObject::DeleteMorph(const Int morph_index)
{
	if (auto& morph = morph_data_[morph_index]; !DeleteMorphImpl(morph, morph_index))
		return;
	std::ignore = morph_data_.Erase(morph_index);
}

bool MMDModelManagerObject::DeleteMorphImpl(IMorph& morph, const Int morph_index)
{
	iferr_scope_handler{ return false; };
	morph.DeleteMorphUI(*this);
	for (auto& i : desc_id_map_.GetKeys())
	{
		if (auto* index = &desc_id_map_.FindValue(i)->second; *index > morph_index)
		{
			(*index)--;
		}
	}
	morph_name_.Erase(morph.GetName())iferr_return;
	for (auto& i : morph_name_.GetKeys())
	{
#if API_VERSION >= 24000
		if (auto* index = morph_name_.FindValue(i).ToPointer(); *index > morph_index)
#else
		if (auto* index = morph_name_.FindValue(i); index && *index > morph_index)
#endif
		{
			(*index)--;
		}
	}
	return true;
}

void MMDModelManagerObject::DeleteMorph(maxon::EraseIterator<maxon::PointerArray<IMorph>, false>& it)
{
	auto& morph = *it;
	if (const Int morph_index = it.FindIndex(morph); !DeleteMorphImpl(morph, morph_index))
		return;
	it.Erase();
}

void MMDModelManagerObject::SyncMaterialsList()
{
	BaseObject* mesh_mgr = GetMeshManagerObject();
	if (!mesh_mgr) return;

	BaseDocument* doc = mesh_mgr->GetDocument();
	if (!doc) return;

	struct MatRef {
		BaseMaterial* mat = nullptr;
		BaseObject* mesh = nullptr;
		String selection;
	};
	maxon::BaseArray<MatRef> active_refs;

	for (BaseObject* child = mesh_mgr->GetDown(); child; child = child->GetNext())
	{
		if (!child->IsInstanceOf(Opolygon))
			continue;
		for (BaseTag* tag = child->GetFirstTag(); tag; tag = tag->GetNext())
		{
			if (tag->GetType() == Ttexture)
			{
				GeData mat_data;
				tag->GetParameter(ConstDescID(DescLevel(TEXTURETAG_MATERIAL)), mat_data, DESCFLAGS_GET::NONE);
				BaseMaterial* mat = static_cast<BaseMaterial*>(mat_data.GetLink(doc));
				if (mat)
				{
					GeData sel_data;
					tag->GetParameter(ConstDescID(DescLevel(TEXTURETAG_RESTRICTION)), sel_data, DESCFLAGS_GET::NONE);
					MatRef ref;
					ref.mat = mat;
					ref.mesh = child;
					ref.selection = sel_data.GetString();
					active_refs.Append(ref) iferr_ignore("append failed");
				}
			}
		}
	}

	Bool changed = false;

	// Remove unreferenced materials
	for (Int32 i = static_cast<Int32>(material_list_.GetCount()) - 1; i >= 0; --i)
	{
		auto& mmd_mat = material_list_[i];
		BaseMaterial* linked_mat = (mmd_mat.material_link && *mmd_mat.material_link) ? static_cast<BaseMaterial*>((*mmd_mat.material_link)->GetLink(doc)) : nullptr;
		BaseObject* linked_mesh = (mmd_mat.mesh_link && *mmd_mat.mesh_link) ? static_cast<BaseObject*>((*mmd_mat.mesh_link)->GetLink(doc)) : nullptr;
		
		Bool found = false;
		for (const auto& ref : active_refs)
		{
			if (ref.mat == linked_mat && ref.mesh == linked_mesh && ref.selection == mmd_mat.selection_name)
			{
				found = true;
				break;
			}
		}

		if (!found)
		{
			material_list_.Erase(i) iferr_ignore("erase failed");
			changed = true;
		}
	}

	// Add new materials
	for (const auto& ref : active_refs)
	{
		Bool found = false;
		for (Int32 i = 0; i < material_list_.GetCount(); ++i)
		{
			auto& mmd_mat = material_list_[i];
			BaseMaterial* linked_mat = (mmd_mat.material_link && *mmd_mat.material_link) ? static_cast<BaseMaterial*>((*mmd_mat.material_link)->GetLink(doc)) : nullptr;
			BaseObject* linked_mesh = (mmd_mat.mesh_link && *mmd_mat.mesh_link) ? static_cast<BaseObject*>((*mmd_mat.mesh_link)->GetLink(doc)) : nullptr;
			
			if (ref.mat == linked_mat && ref.mesh == linked_mesh && ref.selection == mmd_mat.selection_name)
			{
				found = true;
				break;
			}
		}

		if (!found)
		{
			MMDMaterialData new_mat;
			new_mat.name_local = ref.mat->GetName();
			new_mat.name_universal = ref.mat->GetName();
			
			auto mat_link_result = maxon::StrongRef<AutoAlloc<BaseLink>>::Create();
			if (mat_link_result == maxon::OK)
			{
				new_mat.material_link = mat_link_result.GetValue();
				if (new_mat.material_link && *new_mat.material_link)
					(*new_mat.material_link)->SetLink(ref.mat);
			}

			auto mesh_link_result = maxon::StrongRef<AutoAlloc<BaseLink>>::Create();
			if (mesh_link_result == maxon::OK)
			{
				new_mat.mesh_link = mesh_link_result.GetValue();
				if (new_mat.mesh_link && *new_mat.mesh_link)
					(*new_mat.mesh_link)->SetLink(ref.mesh);
			}
			
			new_mat.selection_name = ref.selection;
			
			new_mat.diffuse_rgb = Vector(1, 1, 1);
			new_mat.diffuse_alpha = 1.0;
			new_mat.ambient = Vector(0.5, 0.5, 0.5);
			new_mat.specular = Vector(0, 0, 0);
			new_mat.specular_power = 5.0;

			material_list_.Append(std::move(new_mat)) iferr_ignore("append failed");
			changed = true;
		}
	}

	if (changed)
	{
		if (material_selection_index_ >= material_list_.GetCount())
			material_selection_index_ = static_cast<Int32>(material_list_.GetCount()) - 1;
		if (material_selection_index_ < 0 && material_list_.GetCount() > 0)
			material_selection_index_ = 0;
			
		Get()->SetDirty(DIRTYFLAGS::DESCRIPTION);
		::SendCoreMessage(COREMSG_CINEMA, BaseContainer(COREMSG_CINEMA_FORCE_AM_UPDATE));
		if (::GeIsMainThread())
			::EventAdd();
	}
}
