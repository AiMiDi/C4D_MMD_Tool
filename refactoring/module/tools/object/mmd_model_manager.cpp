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
#include "mmd_bone_manager.h"
#include "mmd_joint_manager.h"
#include "mmd_mesh_manager.h"
#include "mmd_rigid_manager.h"
#include "maxon/queue.h"
#include "utils/filename_util.hpp"
#include "utils/string_util.hpp"

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
	bc->SetInt32(MODEL_ANIM_LIST, -1);
	animation_items_.SetString(-1, GeLoadString(IDS_CMT_VMD_ANIM_NONE));
	return true;
}

template<>
bool inline io_util::ReadData<maxon::Pair<MMDModelRootDynamicDescriptionType, Int>>(HyperFile* hf, maxon::Pair<MMDModelRootDynamicDescriptionType, Int>& data)
{
	if (UChar type = 0; !ReadData(hf, type))
		data.first = static_cast<MMDModelRootDynamicDescriptionType>(type);
	else
		return false;

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
		return false;

	if (!io_util::ReadHashMap(hf, morph_name_))
		return false;

	if (!ReadMorph(hf))
		return false;

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
	return true;
}
SDK2024_CopyTo(MMDModelManagerObject)
{
	const auto destObject = reinterpret_cast<MMDModelManagerObject*>(dest);
	destObject->bone_manager_ = bone_manager_;
	destObject->joint_manager_ = joint_manager_;
	destObject->rigid_manager_ = rigid_manager_;
	destObject->mesh_manager_ = mesh_manager_;
	iferr(destObject->desc_id_map_.CopyFrom(desc_id_map_))
		return false;
	iferr(destObject->morph_name_.CopyFrom(morph_name_))
		return false;
	if (!CopyMorph(destObject))
		return false;
	return true;
}
Bool MMDModelManagerObject::ReadMorph(HyperFile* hf)
{
	iferr_scope_handler{ return nullptr; };
	auto morph_change_helper = BeginMorphChange();
	Int data_count = 0;
	if (!hf->ReadInt64(&data_count))
		return false;
	for (Int i = 0; i < data_count; ++i)
	{
		MMDMorphType type;
		// Read morph type
		if (!hf->ReadUChar(reinterpret_cast<UChar*>(&type)))
			return false;

		// Add morph
		const auto morph_index = AddMorph(type, {}, false);
		auto& morph = morph_data_[morph_index];

		// Read morph data
		morph.Read(hf);
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
	}
	return true;
}

MMDModelManagerObject::AddMorphHelper MMDModelManagerObject::BeginMorphChange()
{
	return AddMorphHelper{this};
}

MMDModelManagerObject::MMDModelManagerObject()
{
	*update_morph_.Write() = true;
	*is_morph_initialized_.Write() = false;
	*is_manager_read_.Write() = false;
}

void MMDModelManagerObject::RefreshMorph()
{
	for (auto it = maxon::Iterable::EraseIterator(morph_data_); it; ++it)
	{
		DeleteMorph(it);
	}
	auto& mesh_morph_map = mesh_manager_->GetNodeData<MMDMeshManagerObject>()->GetMeshMorphData();
	for (auto& name : mesh_morph_map.GetKeys())
	{
		AddMorph(MMDMorphType::MESH, name);
	}
	//auto& bone_morph_map = m_bone_root->GetNodeData<MMDBoneManagerObject>()->GetBoneMorphData();
	//for (auto& name : bone_morph_map.GetKeys())
	//{
	//	AddMorph(MMDMorphType::BONE, name);
	//}
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
	if (!bone_manager_) {
		if (!bone_manager)
		{
			BaseObject* tmp = BaseObject::Alloc(g_mmd_bone_manager_object_id);
			tmp->InsertUnder(op);
			bone_manager_ = tmp;
		}
		else {
			bone_manager_ = bone_manager;
		}
		bone_manager_data_ = bone_manager_->GetNodeData<MMDBoneManagerObject>();
		send_message = true;
	}
	if (!mesh_manager_) {
		if (!mesh_manager)
		{
			BaseObject* tmp = BaseObject::Alloc(g_mmd_mesh_manager_object_id);
			tmp->InsertUnder(op);
			mesh_manager_ = tmp;
		}
		else {
			mesh_manager_ = mesh_manager;
		}
		mesh_manager_data_ = mesh_manager_->GetNodeData<MMDMeshManagerObject>();
		send_message = true;
	}
	if (!rigid_manager_) {
		if (!rigid_manager)
		{
			BaseObject* tmp = BaseObject::Alloc(g_mmd_rigid_manager_object_id);
			tmp->InsertUnder(op);
			rigid_manager_ = tmp;
		}
		else {
			rigid_manager_ = rigid_manager;
		}
		rigid_manager_data_ = rigid_manager_->GetNodeData<MMDRigidManagerObject>();
		send_message = true;
	}
	if (!joint_manager_) {
		if (!joint_manager)
		{
			BaseObject* tmp = BaseObject::Alloc(g_mmd_joint_manager_object_id);
			tmp->InsertUnder(op);
			joint_manager_ = tmp;
		}
		else {
			joint_manager_ = joint_manager;
		}
		joint_manager_data_ = joint_manager_->GetNodeData<MMDJointManagerObject>();
		send_message = true;
	}
	if (send_message)
	{
		SendObjectUpdateMessage(bone_manager_, op);
		SendObjectUpdateMessage(mesh_manager_, op);

		rigid_manager_data_->bone_manager_data_ = bone_manager_data_;
		joint_manager_data_->bone_manager_data_ = bone_manager_data_;
		joint_manager_data_->rigid_manager_data_ = rigid_manager_data_;
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

	if (!manager_read)
		if (!UpdateManagers(op))
			return EXECUTIONRESULT::OK;

	if(manager_read)
	{
		*is_manager_read_.Write() = false;
	}

	if (!*is_morph_initialized_.Read())
	{
		RefreshMorph();
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

			if (animation_index_ != -1 && animation_index_ < animations_.GetCount())
			{
				const auto& [_, animation]  = animations_[animation_index_];
				const auto vmd_frame = static_cast<Float32>(now_time.Get() * fps_);
				if (!is_animation_initialized_ || now_time == doc->GetMinTime())
				{
					mmd_model_->InitializeAnimation();
					animation->SyncPhysics(vmd_frame, 30, 1.f / fps_);
					is_animation_initialized_ = true;
				}
				mmd_model_->BeginAnimation();
				mmd_model_->UpdateAllAnimation(animation.get(), vmd_frame, 1.f / fps_);
				mmd_model_->EndAnimation();
			}
			else
			{
				if (!is_animation_initialized_ || now_time == doc->GetMinTime())
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

Int MMDModelManagerObject::ImportGroupAndFlipMorph(const libmmd::PMXFileMorph& pmx_morph)
{
	Int morph_id = -1;
	iferr_scope_handler{ return morph_id; };
	switch (pmx_morph.m_morphType)
	{
	case libmmd::PMXMorphType::Group:
	{
		morph_id = AddMorph(MMDMorphType::GROUP, String(pmx_morph.m_name.c_str()));
		auto& morph = morph_data_[morph_id];
		for (const auto& [morph_index, weight] : pmx_morph.m_groupMorph)
		{
			morph.AddSubMorphNoCheck(morph_index, weight);
		}
		break;
	}
	case libmmd::PMXMorphType::Flip:
	{
		morph_id = AddMorph(MMDMorphType::FLIP, String(pmx_morph.m_name.c_str()));
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

Bool MMDModelManagerObject::CreateManagers()
{
	const BaseDocument* doc = GetActiveDocument();
	if (const auto op = reinterpret_cast<BaseObject*>(Get()); op != nullptr && doc != nullptr)
	{
		if (bone_manager_ == nullptr)
		{
			BaseObject* bone_root_object = BaseObject::Alloc(g_mmd_bone_manager_object_id);
			bone_root_object->InsertUnder(op);
			bone_manager_ = bone_root_object;
			bone_manager_data_ = bone_manager_->GetNodeData<MMDBoneManagerObject>();
			bone_manager_data_->model_manager_ = reinterpret_cast<BaseObject*>(this);
		}
		if (mesh_manager_ == nullptr)
		{
			BaseObject* mesh_root_object = BaseObject::Alloc(g_mmd_mesh_manager_object_id);
			mesh_root_object->InsertUnder(op);
			mesh_manager_ = mesh_root_object;
			mesh_manager_data_ = mesh_manager_->GetNodeData<MMDMeshManagerObject>();
			mesh_manager_data_->model_manager_ = reinterpret_cast<BaseObject*>(this);
		}
		if (rigid_manager_ == nullptr)
		{
			BaseObject* rigid_root_object = BaseObject::Alloc(g_mmd_rigid_manager_object_id);
			rigid_root_object->InsertUnder(op);
			rigid_manager_ = rigid_root_object;
			rigid_manager_data_ = rigid_manager_->GetNodeData<MMDRigidManagerObject>();
			rigid_manager_data_->bone_manager_data_ = bone_manager_data_;

		}
		if (joint_manager_ == nullptr)
		{
			BaseObject* joint_root_object = BaseObject::Alloc(g_mmd_joint_manager_object_id);
			joint_root_object->InsertUnder(op);
			joint_manager_ = joint_root_object;
			joint_manager_data_ = joint_manager_->GetNodeData<MMDJointManagerObject>();
			joint_manager_data_->bone_manager_data_ = bone_manager_data_;
			joint_manager_data_->rigid_manager_data_ = rigid_manager_data_;
		}
		return true;
	}
	return false;
}

Bool MMDModelManagerObject::LoadPMX(const libmmd::PMXFile& pmx_file, const MMDModelPtr& pmx_model, const CMTToolsSetting::ModelImport& setting)
{
	SetMMDModel(pmx_model);
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

	if (setting.import_expression)
	{
		const auto& pmx_morph_array = pmx_file.m_morphs;
		const auto pmx_morph_num = pmx_morph_array.size();
		for (auto morph_index = decltype(pmx_morph_num){}; morph_index < pmx_morph_num; ++morph_index)
		{
			const auto& pmx_morph = pmx_morph_array[morph_index];
			if (const auto& morph_offset_type = pmx_morph.m_morphType;
				morph_offset_type == libmmd::PMXMorphType::Group || morph_offset_type == libmmd::PMXMorphType::Flip)
				ImportGroupAndFlipMorph(pmx_morph);
		}
	}
	return true;
}

Bool MMDModelManagerObject::SavePMX(libmmd::PMXFile& pmx_file, const CMTToolsSetting::ModelExport& setting) const
{

	if (setting.export_bone && bone_manager_)
		if (const auto bone_manager_data = bone_manager_->GetNodeData<MMDBoneManagerObject>(); bone_manager_data && !bone_manager_data->SavePMX(pmx_file, setting))
			return false;

	if (setting.export_polygon && mesh_manager_)
		if (const auto mesh_manager_data = mesh_manager_->GetNodeData<MMDMeshManagerObject>(); mesh_manager_data && !mesh_manager_data->SavePMX(pmx_file, setting))
			return false;
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
		animations_.Append(animation_name, std::move(new_vmd_animation))iferr_return;
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
	return true;
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

Int32 MMDModelManagerObject::GetMorphNamedNumber()
{
	return morph_named_number_++;
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
					break;
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
			case MODEL_ANIM_MERGE_VMD_BUTTON: [[fallthrough]];
			case MODEL_ANIM_LOAD_VMD_BUTTON:
			{
				CMTToolsSetting::MotionImport setting(GetActiveDocument());
				if(!filename_util::SelectSuffixImportFile(setting.fn, "vmd"_s))
				{
					break;
				}
				if (bone_manager_)
				{
					if (const auto bone_manager_data = bone_manager_->GetNodeData<MMDBoneManagerObject>(); bone_manager_data)
					{
						setting.position_multiple = bone_manager_data->GetPositionMultiple();
					}
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
				if(LoadVMDMotion(vmd_file, setting, logger, id == MODEL_ANIM_MERGE_VMD_BUTTON))
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

Bool MMDModelManagerObject::SetDParameter(GeListNode* node, const DescID& id, const GeData& t_data, DESCFLAGS_SET& flags)
{
	switch (id[0].id)
	{
		case MODEL_MODE:
		{
			model_mode_ = t_data.GetInt32();
			is_animation_initialized_ = false;
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
	}
	return ObjectData::SetDParameter(node, id, t_data, flags);
}

Int MMDModelManagerObject::AddMorph(const MMDMorphType& morph_type, String morph_name, bool is_add_morph_ui)
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
	case MMDMorphType::BONE:

		if (morph_name.IsEmpty())
		{
			morph_name = FormatString("Bone morph @", GetMorphNamedNumber());
		}
		morph = NewObj(BoneMorph, morph_name)iferr_return;
		break;
	case MMDMorphType::DEFAULT:
		break;
	}
	if(!morph)
		return index;
	morph_data_.AppendPtr(morph)iferr_return;
	index = morph_data_.GetIndex(*morph);
	iferr(morph_name_.Insert(morph_name, index))
	{
		morph_data_.Erase(index)iferr_return;
		index = -1;
		return index;
	}
	if(is_add_morph_ui)
		morph->AddMorphUI(*this, index);
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
		if (auto* index = morph_name_.FindValue(i)SDK2024_ToPointer; *index > morph_index)
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
