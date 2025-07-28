/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & CMT contributors.
Author:			Aimidi
Date:			2023/9/12
File:			mmd_model.h
Description:	MMD model object

**************************************************************************/

#include "pch.h"
#include "mmd_model.h"

#include "cmt_tools_manager.h"
#include "mmd_morph.h"
#include "mmd_bone_manager.h"
#include "mmd_mesh_manager.h"
#include "mmd_rigid_manager.h"
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
	// >>
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
		UpdateDialogHelper updateDialog = BeginLayoutChange(1003, true);
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
		updateDialog.CommitChanges();
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
	*m_model->m_is_need_update.Write() = false;
	*m_model->m_is_morph_initialized.Write() = false;
}

MMDModelManagerObject::AddMorphHelper::~AddMorphHelper()
{
	*m_model->m_is_need_update.Write() = true;
}

Bool MMDModelManagerObject::Init(GeListNode* node SDK2024_InitParaName)
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
	animation_items.SetString(-1, "-"_s);
	return true;
}
Bool MMDModelManagerObject::Read(GeListNode* node, HyperFile* hf, Int32 level) {
	iferr_scope_handler
	{
		return false;
	};

	mesh_manager_link = BaseLink::Alloc();
	if (mesh_manager_link == nullptr)
		return false;
	rigid_manager_link = BaseLink::Alloc();
	if (rigid_manager_link == nullptr)
		return false;
	joint_manager_link = BaseLink::Alloc();
	if (joint_manager_link == nullptr)
		return false;
	bone_manager_link = BaseLink::Alloc();
	if (bone_manager_link == nullptr)
		return false;
	if (!mesh_manager_link->Read(hf))
		return false;
	if (!rigid_manager_link->Read(hf))
		return false;
	if (!joint_manager_link->Read(hf))
		return false;
	if (!bone_manager_link->Read(hf))
		return false;
	*is_manager_read.Write() = true;

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
		auto& val = m_desc_id_map.InsertKey(id).GetValue();

		if (UChar type = 0; hf->ReadUChar(&type))
			val.first = static_cast<MMDModelRootDynamicDescriptionType>(type);
		else
			return false;

		if (!hf->ReadInt64(&val.second))
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
		if (!hf->ReadInt64(&val))
			return false;
	}

	if (!hf->ReadInt64(&data_count))
		return false;
	m_ik_link_name_map.SetCapacityHint(data_count)iferr_return;
	for (Int i = 0; i < data_count; ++i)
	{
		String name;
		if (!hf->ReadString(&name))
			return false;
		auto& val = m_ik_link_name_map.InsertKey(std::move(name))iferr_return;
		if (!val->Read(hf))
			return false;
	}
	*m_is_ik_map_read.Write() = true;

	if (!ReadMorph(hf))
		return false;
	*m_is_morph_initialized.Write() = true;
	return true;
}
Bool MMDModelManagerObject::Write(SDK2024_Const GeListNode* node, HyperFile* hf) SDK2024_Const {
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
	mesh_root_link->SetLink(mesh_manager);
	rigid_root_link->SetLink(rigid_manager);
	joint_root_link->SetLink(joint_manager);
	bone_root_link->SetLink(bone_manager);
	if (!mesh_root_link->Write(hf))
		return false;
	if (!rigid_root_link->Write(hf))
		return false;
	if (!joint_root_link->Write(hf))
		return false;
	if (!bone_root_link->Write(hf))
		return false;
	if (!hf->WriteInt32(m_morph_named_number))
		return false;

	if (!hf->WriteInt64(m_desc_id_map.GetCount()))
		return false;
	for (auto& i : m_desc_id_map)
	{
		if (!const_cast<DescID&>(i.GetKey()).Write(hf))
			return false;
		auto& val = i.GetValue();
		if (!hf->WriteUChar(static_cast<uint8_t>(val.first)))
			return false;
		if (!hf->WriteInt64(val.second))
			return false;
	}

	if (!hf->WriteInt64(m_morph_name_map.GetCount()))
		return false;
	for (auto& i : m_morph_name_map)
	{
		if (!hf->WriteString(i.GetKey()))
			return false;
		if (!hf->WriteInt64(i.GetValue()))
			return false;
	}

	if (!hf->WriteInt64(m_ik_name_map.GetCount()))
		return false;
	{
		AutoAlloc<BaseLink> ik_link;
		if (ik_link == nullptr)
			return false;
		for (auto& i : m_ik_name_map)
		{
			if (!hf->WriteString(i.GetKey()))
				return false;
			ik_link->SetLink(i.GetValue());
			if (!ik_link->Write(hf))
				return false;
		}
	}

	if (!WriteMorph(hf))
		return false;
	return true;
}
Bool MMDModelManagerObject::CopyTo(NodeData* dest, SDK2024_Const GeListNode* snode, GeListNode* dnode, COPYFLAGS flags, AliasTrans* trn) SDK2024_Const
{
	const auto destObject = reinterpret_cast<MMDModelManagerObject*>(dest);
	destObject->bone_manager = bone_manager;
	destObject->joint_manager = joint_manager;
	destObject->rigid_manager = rigid_manager;
	destObject->mesh_manager = mesh_manager;
	iferr(destObject->m_desc_id_map.CopyFrom(m_desc_id_map))
		return false;
	iferr(destObject->m_morph_name_map.CopyFrom(m_morph_name_map))
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
		auto& morph = m_morph_arr[morph_index];

		// Read morph data
		morph.Read(hf);
	}


	return true;
}
Bool MMDModelManagerObject::WriteMorph(HyperFile* hf) SDK2024_Const
{
	if (!hf->WriteInt64(m_morph_arr.GetCount()))
		return false;
	if(!std::all_of(m_morph_arr.Begin(), m_morph_arr.End(), [&](SDK2024_Const IMorph& i)
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
	for (const auto& morph : m_morph_arr)
	{
		const auto& new_morph_name = morph.GetName();
		const auto new_morph_index = dst->AddMorph(morph.GetType(), new_morph_name, false);
		const auto new_morph = &dst->m_morph_arr[new_morph_index];
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
	*m_is_need_update.Write() = true;
	*m_is_morph_initialized.Write() = false;
}

void MMDModelManagerObject::RefreshMorph()
{
	for (auto it = maxon::Iterable::EraseIterator(m_morph_arr); it; ++it)
	{
		DeleteMorph(it);
	}
	auto& mesh_morph_map = mesh_manager->GetNodeData<MMDMeshManagerObject>()->GetMeshMorphData();
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

Bool MMDModelManagerObject::UpdateRoot(BaseObject* op)
{
	if (!op)
		op = reinterpret_cast<BaseObject*>(Get());
	BaseObject* MeshRoot_ = nullptr;
	BaseObject* BoneRoot_ = nullptr;
	BaseObject* RigidRoot_ = nullptr;
	BaseObject* JointRoot_ = nullptr;
	maxon::Queue<BaseObject*> nodes;
	iferr(nodes.Push(op->GetDown())) return false;
	while (!nodes.IsEmpty())
	{
		BaseObject* node = *nodes.Pop();
		if (node != nullptr)
		{
			if (node->IsInstanceOf(ID_O_MMD_JOINT_MANAGER))
				JointRoot_ = node;
			else if (node->IsInstanceOf(ID_O_MMD_RIGID_MANAGER))
				RigidRoot_ = node;
			else if (node->IsInstanceOf(ID_O_MMD_BONE_MANAGER))
				BoneRoot_ = node;
			else if (node->IsInstanceOf(ID_O_MMD_MESH_MANAGER))
				MeshRoot_ = node;
			iferr(nodes.Push(node->GetNext())) return false;
		}
	}
	nodes.Reset();
	if (joint_manager == nullptr) {
		if (JointRoot_ == nullptr)
		{
			BaseObject* tmp = BaseObject::Alloc(ID_O_MMD_JOINT_MANAGER);
			tmp->InsertUnder(op);
			joint_manager = tmp;
		}
		else {
			joint_manager = JointRoot_;
		}
		m_is_root_initialized = false;
	}
	if (rigid_manager == nullptr) {
		if (RigidRoot_ == nullptr)
		{
			BaseObject* tmp = BaseObject::Alloc(ID_O_MMD_RIGID_MANAGER);
			tmp->InsertUnder(op);
			rigid_manager = tmp;
		}
		else {
			rigid_manager = RigidRoot_;
		}
		m_is_root_initialized = false;
	}
	if (bone_manager == nullptr) {
		if (BoneRoot_ == nullptr)
		{
			BaseObject* tmp = BaseObject::Alloc(ID_O_MMD_BONE_MANAGER);
			tmp->InsertUnder(op);
			bone_manager = tmp;
		}
		else {
			bone_manager = BoneRoot_;
		}
		m_is_root_initialized = false;
	}
	if (mesh_manager == nullptr) {
		if (MeshRoot_ == nullptr)
		{
			BaseObject* tmp = BaseObject::Alloc(ID_O_MMD_MESH_MANAGER);
			tmp->InsertUnder(op);
			mesh_manager = tmp;
		}
		else {
			mesh_manager = MeshRoot_;
		}
		m_is_root_initialized = false;
	}
	if (m_is_root_initialized == false) {
		MMDModelRootObjectMsg MeshRoot_msg(MMDModelRootObjectMsgType::MANAGER_OBJECT_UPDATE, ManagerObjectType::MODEL_MANAGER, op);
		mesh_manager->Message(ID_O_MMD_MODEL, &MeshRoot_msg);
		MMDModelRootObjectMsg BoneRoot_msgA(MMDModelRootObjectMsgType::MANAGER_OBJECT_UPDATE, ManagerObjectType::RIGID_MANAGER, rigid_manager);
		bone_manager->Message(ID_O_MMD_MODEL, &BoneRoot_msgA);
		MMDModelRootObjectMsg BoneRoot_msgB(MMDModelRootObjectMsgType::MANAGER_OBJECT_UPDATE, ManagerObjectType::JOINT_MANAGER, joint_manager);
		bone_manager->Message(ID_O_MMD_MODEL, &BoneRoot_msgB);
		MMDModelRootObjectMsg BoneRoot_msgC(MMDModelRootObjectMsgType::MANAGER_OBJECT_UPDATE, ManagerObjectType::MODEL_MANAGER, op);
		bone_manager->Message(ID_O_MMD_MODEL, &BoneRoot_msgC);
		MMDModelRootObjectMsg RigidRoot_msgA(MMDModelRootObjectMsgType::MANAGER_OBJECT_UPDATE, ManagerObjectType::BONE_MANAGER, bone_manager);
		rigid_manager->Message(ID_O_MMD_MODEL, &RigidRoot_msgA);
		MMDModelRootObjectMsg RigidRoot_msgB(MMDModelRootObjectMsgType::MANAGER_OBJECT_UPDATE, ManagerObjectType::JOINT_MANAGER, joint_manager);
		rigid_manager->Message(ID_O_MMD_MODEL, &RigidRoot_msgB);
		MMDModelRootObjectMsg JointRoot_msgA(MMDModelRootObjectMsgType::MANAGER_OBJECT_UPDATE, ManagerObjectType::BONE_MANAGER, bone_manager);
		joint_manager->Message(ID_O_MMD_MODEL, &JointRoot_msgA);
		MMDModelRootObjectMsg JointRoot_msgB(MMDModelRootObjectMsgType::MANAGER_OBJECT_UPDATE, ManagerObjectType::RIGID_MANAGER, rigid_manager);
		joint_manager->Message(ID_O_MMD_MODEL, &JointRoot_msgB);
		m_is_root_initialized = true;
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

	if(*is_manager_read.Read())
	{
		mesh_manager = reinterpret_cast<BaseObject*>(mesh_manager_link->GetLink(doc));
		rigid_manager = reinterpret_cast<BaseObject*>(rigid_manager_link->GetLink(doc));
		joint_manager = reinterpret_cast<BaseObject*>(joint_manager_link->GetLink(doc));
		bone_manager = reinterpret_cast<BaseObject*>(bone_manager_link->GetLink(doc));
		BaseLink::Free(mesh_manager_link);
		BaseLink::Free(rigid_manager_link);
		BaseLink::Free(joint_manager_link);
		BaseLink::Free(bone_manager_link);
		*is_manager_read.Write() = false;
	}

	if(*m_is_ik_map_read.Read())
	{
		m_ik_name_map.SetCapacityHint(m_ik_link_name_map.GetCount())iferr_return;
		for (const auto& entry : m_ik_link_name_map)
		{
			m_ik_name_map.Insert(entry.GetKey(), reinterpret_cast<BaseTag*>(entry.GetSecond()->GetLink(doc)))iferr_return;
		}
		m_ik_link_name_map.Reset();
		*m_is_ik_map_read.Write() = false;
	}

	if (UpdateRoot(op) == false)
		return EXECUTIONRESULT::OK;

	if (!*m_is_morph_initialized.Read())
	{
		RefreshMorph();
		*m_is_morph_initialized.Write() = true;
	}

	if (*m_is_need_update.Read())
	{
		for (auto& morph : m_morph_arr)
		{
			UpdateMorph(morph);
		}
	}

	if (model_mode == MODEL_MODE_ANIM && m_model)
	{
		if (const auto now_time = doc->GetTime(); prev_time != now_time)
		{
			if (animation_index != -1 && animation_index < animations.GetCount())
			{
				const auto& [_, animation]  = animations[animation_index];
				const auto time = maxon::SafeConvert<Float32>(now_time.Get() * 30.);
				if (now_time == doc->GetMinTime())
				{
					const auto fps = doc->GetFps();
					delta_time = maxon::SafeConvert<Float32>(1. / fps);
					m_model->GetMMDPhysics()->SetFPS(static_cast<float>(fps * 2));
					m_model->InitializeAnimation();
					animation->SyncPhysics(0.f);
				}
				m_model->BeginAnimation();
				m_model->UpdateAllAnimation(animation.get(), time, delta_time);
				m_model->EndAnimation();
			}
			else
			{
				if (now_time == doc->GetMinTime())
				{
					const auto fps = doc->GetFps();
					delta_time = maxon::SafeConvert<Float32>(1. / fps);
					m_model->GetMMDPhysics()->SetFPS(static_cast<float>(fps * 2));
					m_model->InitializeAnimation();
				}
				m_model->BeginAnimation();
				m_model->UpdateNodeAnimation(false);
				m_model->UpdatePhysicsAnimation(delta_time);
				m_model->UpdateNodeAnimation(true);
				m_model->EndAnimation();
			}
			prev_time = now_time;
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
		auto& morph = m_morph_arr[morph_id];
		for (const auto& [morph_index, weight] : pmx_morph.m_groupMorph)
		{
			morph.AddSubMorphNoCheck(morph_index, weight);
		}
		break;
	}
	case libmmd::PMXMorphType::Flip:
	{
		morph_id = AddMorph(MMDMorphType::FLIP, String(pmx_morph.m_name.c_str()));
		auto& morph = m_morph_arr[morph_id];
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
	iferr(m_desc_id_map.Insert(id, { type, index }))
		return id;
	return id;
}

void MMDModelManagerObject::DeleteDynamicDescription(const DescID& id)
{
	DynamicDescription* const dynamic_description = Get()->GetDynamicDescriptionWritable();
	if (!dynamic_description)
		return;
	dynamic_description->Remove(id);
	std::ignore = m_desc_id_map.Erase(id);
}

Int MMDModelManagerObject::GetMorphNum() const
{
	return m_morph_arr.GetCount();
}

const maxon::PointerArray<IMorph>& MMDModelManagerObject::GetMorphData()
{
	return m_morph_arr;
}

const maxon::HashMap<String, Int>& MMDModelManagerObject::GetMorphNameMap()
{
	return m_morph_name_map;
}

Bool MMDModelManagerObject::CreateRoot()
{
	const BaseDocument* doc = GetActiveDocument();
	if (const auto op = reinterpret_cast<BaseObject*>(Get()); op != nullptr && doc != nullptr)
	{
		if (joint_manager == nullptr)
		{
			BaseObject* joint_root_object = BaseObject::Alloc(ID_O_MMD_JOINT_MANAGER);
			joint_root_object->InsertUnder(op);
			joint_manager = joint_root_object;
		}
		if (rigid_manager == nullptr)
		{
			BaseObject* rigid_root_object = BaseObject::Alloc(ID_O_MMD_RIGID_MANAGER);
			rigid_root_object->InsertUnder(op);
			rigid_manager = rigid_root_object;
		}
		if (bone_manager == nullptr)
		{
			BaseObject* bone_root_object = BaseObject::Alloc(ID_O_MMD_BONE_MANAGER);
			bone_root_object->InsertUnder(op);
			bone_manager = bone_root_object;
		}
		if (mesh_manager == nullptr)
		{
			BaseObject* mesh_root_object = BaseObject::Alloc(ID_O_MMD_MESH_MANAGER);
			mesh_root_object->InsertUnder(op);
			mesh_manager = mesh_root_object;
		}
		return true;
	}
	return false;
}

BaseObject* MMDModelManagerObject::GetRootObject(const ManagerObjectType type) const
{
	switch (type)
	{
	case ManagerObjectType::MESH_MANAGER:
		return mesh_manager;
	case ManagerObjectType::BONE_MANAGER:
		return bone_manager;
	case ManagerObjectType::RIGID_MANAGER:
		return rigid_manager;
	case ManagerObjectType::JOINT_MANAGER:
		return joint_manager;

	case ManagerObjectType::DEFAULT:
	case ManagerObjectType::MODEL_MANAGER:;
	}
	return nullptr;
}

Bool MMDModelManagerObject::AddIKBoneDescription(const maxon::String& bone_name_local, BaseTag* ik_tag)
{
	iferr_scope_handler{ return false; };

	m_ik_name_map.Insert(bone_name_local, ik_tag)iferr_return;

	BaseContainer bc = GetCustomDataTypeDefault(DTYPE_BASELISTLINK);
	bc.SetString(DESC_NAME, bone_name_local);
	bc.SetData(DESC_PARENTGROUP, DescIDGeData(ConstDescID(DescLevel(MODEL_IK_GRP))));
	const auto ik_link_id = AddDynamicDescription(bc, MMDModelRootDynamicDescriptionType::IK_BONE_LINK, 0);
	const auto ik_link = BaseLink::Alloc();
	ik_link->SetLink(ik_tag);
	Get()->SetParameter(ik_link_id, ik_link, DESCFLAGS_SET::NONE);
	return true;
}

Bool MMDModelManagerObject::LoadPMX(const libmmd::PMXFile& pmx_file, const MMDModelPtr& pmx_model, const CMTToolsSetting::ModelImport& setting)
{
	m_model = pmx_model;
	maxon::BaseArray<BaseObject*> bone_list;
	auto morph_change_helper = BeginMorphChange();

	if (setting.import_bone && bone_manager)
		if(const auto bone_manager_data = bone_manager->GetNodeData<MMDBoneManagerObject>(); bone_manager_data && !bone_manager_data->LoadPMX(pmx_file, pmx_model, bone_list, setting))
			return false;

	if (setting.import_polygon && mesh_manager)
		if(const auto mesh_manager_data = mesh_manager->GetNodeData<MMDMeshManagerObject>(); mesh_manager_data && !mesh_manager_data->LoadPMX(pmx_file, bone_list, setting))
			return false;

	if (rigid_manager)
		if(const auto rigid_manager_data = rigid_manager->GetNodeData<MMDRigidManagerObject>(); rigid_manager_data && !rigid_manager_data->LoadPMX(pmx_file, pmx_model, setting))
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

	if (setting.export_bone && bone_manager)
		if (const auto bone_manager_data = bone_manager->GetNodeData<MMDBoneManagerObject>(); bone_manager_data && !bone_manager_data->SavePMX(pmx_file, setting))
			return false;

	if (setting.export_polygon && mesh_manager)
		if (const auto mesh_manager_data = mesh_manager->GetNodeData<MMDMeshManagerObject>(); mesh_manager_data && !mesh_manager_data->SavePMX(pmx_file, setting))
			return false;
	return true;
}

Bool MMDModelManagerObject::LoadVMDMotion(const libmmd::VMDFile& vmd_file, const CMTToolsSetting::MotionImport& setting, LoadVmdMotionLog& log)
{
	iferr_scope_handler
	{
		return false;
	};

	auto vmd_animation = std::make_unique<libmmd::VMDAnimation>();
	if (!vmd_animation)
	{
		LoadVmdMotionLog::LogOutMem();
		return false;
	}

	if (!vmd_animation->Create(m_model))
	{
		LoadVmdMotionLog::LogOutMem();
		return false;
	}

	if (!vmd_animation->Add(vmd_file))
	{
		LoadVmdMotionLog::LogReadFileErr();
		return false;
	}

	log.imported_bone_count = vmd_animation->GetNodeKeyNum();
	log.imported_morph_count = vmd_animation->GetMorphKeyNum();
	log.imported_motion_count = vmd_animation->GetIKKeyNum();

	const BaseTime max_time(vmd_animation->GetMaxKeyTime() ,30.);

	const auto& [animation_name, _] = animations.Append(setting.fn.GetFileString(), std::move(vmd_animation))iferr_return;
	animation_index = static_cast<Int32>(animations.GetCount()) - 1;
	animation_items.SetString(animation_index, animation_name);
	const auto node = Get();
	node->SetDirty(DIRTYFLAGS::DESCRIPTION);
	node->SetParameter(ConstDescID(DescLevel(MODEL_ANIM_LIST)), animation_index, DESCFLAGS_SET::NONE);

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
//	const auto morph_ptr = m_morph_name_map.Find(morph_name);
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
//			if (const auto ik_entry = m_ik_name_map.Find(ik_bone_name); ik_entry)
//			{
//				if (const auto& ik_tag = ik_entry->GetValue(); !add_key_func(ik_tag))
//					return false;
//
//			}
//		}
//		else
//		{
//			for (const auto& ik_tag : m_ik_name_map.GetValues())
//			{
//				if (ik_tag->GetName().IsEqual(ik_bone_name) && !add_key_func(ik_tag))
//					return false;
//			}
//		}
//	}
//
//	return true;
//}

Bool MMDModelManagerObject::DeleteAnimation()
{
	iferr_scope_handler{ return false; };
	animation_items.FlushAll();
	animation_items.SetString(-1, "-"_s);
	maxon::BaseArray<std::pair<String, std::unique_ptr<libmmd::VMDAnimation>>> new_animations;
	const auto animation_count = animations.GetCount();
	for (int i = 0, j = 0; i < animation_count; ++i)
	{
		if (i != animation_index)
		{
			const auto& [animation_name, _] = new_animations.Append(std::move(animations[i]))iferr_return;
			animation_items.SetString(j++, animation_name);
		}
	}
	std::swap(new_animations, animations);
	animation_index = -1;
	const auto node = Get();
	node->SetDirty(DIRTYFLAGS::DESCRIPTION);
	node->SetParameter(ConstDescID(DescLevel(MODEL_ANIM_LIST)), animation_index, DESCFLAGS_SET::NONE);
	return true;
}

Int32 MMDModelManagerObject::GetMorphNamedNumber()
{
	return m_morph_named_number++;
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
	list->Add(op, EXECUTIONPRIORITY_ANIMATION_NLA + 1, EXECUTIONFLAGS::NONE);
	return true;
}
Bool MMDModelManagerObject::GetDDescription(SDK2024_Const GeListNode* node, Description* description, DESCFLAGS_DESC& flags) SDK2024_Const
{
	if (!description->LoadDescription(node->GetType()))
		return false;
	if (BaseContainer* settings = description->GetParameterI(ConstDescID(DescLevel(MODEL_ANIM_LIST)), nullptr))
		settings->SetContainer(DESC_CYCLE, animation_items);
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
	case ID_O_MMD_MESH_MANAGER:
	{
		if (static_cast<MMDMeshManagerObjectMsg*>(data)->type == MMDMeshManagerObjectMsgType::MESH_MORPH_CHANGE)
		{
			*m_is_morph_initialized.Write() = false;
		}
		break;
	}
	case ID_O_MMD_BONE_MANAGER:
	{
		if (static_cast<MMDBoneManagerObjectMsg*>(data)->type == MMDBoneManagerObjectMsgType::BONE_MORPH_CHANGE)
		{
			*m_is_morph_initialized.Write() = false;
		}
		break;
	}
	case MSG_DESCRIPTION_COMMAND:
	{
		/* check if it is a user data button */
		if (const auto* dc = static_cast<DescriptionCommand*>(data); dc->_descId[0].id == ID_USERDATA)
		{
			if (const auto desc_id_ptr = m_desc_id_map.Find(dc->_descId); desc_id_ptr != nullptr)
			{
				const auto& [desc_type, morph_index] = desc_id_ptr->GetValue();
				auto& morph = m_morph_arr[morph_index];
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
			switch (dc->_descId[0].id)
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
			case MODEL_ANIM_LOAD_VMD_BUTTON:
			{
				CMTToolsSetting::MotionImport setting(GetActiveDocument());
				if(!filename_util::SelectSuffixImportFile(setting.fn, "vmd"_s))
				{
					break;
				}
				if (bone_manager)
					if (const auto bone_manager_data = bone_manager->GetNodeData<MMDBoneManagerObject>(); bone_manager_data)
					{
						setting.position_multiple = bone_manager_data->GetPositionMultiple();
					}
				CMTToolsManager::ImportVMDMotion(setting, reinterpret_cast<BaseObject*>(Get()));
				break;
			}
			case MODEL_ANIM_DElETE_BUTTON:
			{
				DeleteAnimation();
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

Bool MMDModelManagerObject::SetDParameter(GeListNode* node, const DescID& id, const GeData& t_data, DESCFLAGS_SET& flags)
{
	switch (id[0].id)
	{
		case MODEL_MODE:
		{
			model_mode = t_data.GetInt32();
			MMDModelRootObjectMsg msg(MMDModelRootObjectMsgType::MODEL_MODE_CHANGE, ManagerObjectType::DEFAULT, nullptr, model_mode);
			node->MultiMessage(MULTIMSG_ROUTE::DOWN, ID_O_MMD_MODEL, &msg);
			break;
		}
		case MODEL_ANIM_LIST:
		{
			animation_index = t_data.GetInt32();
			prev_time = BaseTime(-1.);
			const auto doc = node->GetDocument();
			doc->SetTime({});
			if (animation_index != -1 && animation_index < animations.GetCount())
			{
				const auto& animation = animations[animation_index].second;
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
	m_morph_arr.AppendPtr(morph)iferr_return;
	index = m_morph_arr.GetIndex(*morph);
	iferr(m_morph_name_map.Insert(morph_name, index))
	{
		m_morph_arr.Erase(index)iferr_return;
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
	if(const auto morph_id_ptr = m_morph_name_map.Find(name); morph_id_ptr)
	{
		if (const auto& index = morph_id_ptr->GetValue(); index < GetMorphNum())
		{
			iferr(m_morph_name_map.Insert(name, index))
				return;
			iferr(m_morph_name_map.Erase(morph_id_ptr))
				return;
			auto& morph = m_morph_arr[index];
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
	if (auto& morph = m_morph_arr[morph_index]; !DeleteMorphImpl(morph, morph_index))
		return;
	std::ignore = m_morph_arr.Erase(morph_index);
}

bool MMDModelManagerObject::DeleteMorphImpl(IMorph& morph, const Int morph_index)
{
	iferr_scope_handler{ return false; };
	morph.DeleteMorphUI(*this);
	for (auto& i : m_desc_id_map.GetKeys())
	{
		if (auto* index = &m_desc_id_map.FindValue(i)->second; *index > morph_index)
		{
			(*index)--;
		}
	}
	m_morph_name_map.Erase(morph.GetName())iferr_return;
	for (auto& i : m_morph_name_map.GetKeys())
	{
		if (auto* index = m_morph_name_map.FindValue(i)SDK2024_ToPointer; *index > morph_index)
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
