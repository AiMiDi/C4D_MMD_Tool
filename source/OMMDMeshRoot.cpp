#include "OMMDMeshRoot.h"
#include "description/OMMDMeshRoot.h"

namespace tool {
	Bool OMMDMeshRoot::Init(GeListNode* node)
	{
		node->ChangeNBit(NBIT::NO_DD, NBITCONTROL::SET);
		if (node != nullptr)
		{
			BaseTag* ProtectionTag = static_cast<BaseObject*>(node)->MakeTag(Tprotection);
			if (ProtectionTag != nullptr)
			{
				ProtectionTag->ChangeNBit(NBIT::OHIDE, NBITCONTROL::SET);
				ProtectionTag->ChangeNBit(NBIT::AHIDE_FOR_HOST, NBITCONTROL::SET);
			}
			m_displayTag = static_cast<BaseObject*>(node)->MakeTag(Tdisplay);
			if (m_displayTag != nullptr)
			{
				m_displayTag->SetParameter(DISPLAYTAG_AFFECT_DISPLAYMODE, true, DESCFLAGS_SET::NONE);
				m_displayTag->ChangeNBit(NBIT::OHIDE, NBITCONTROL::SET);
				m_displayTag->ChangeNBit(NBIT::AHIDE_FOR_HOST, NBITCONTROL::SET);
			}
		}
		return true;
	}
	Bool OMMDMeshRoot::Read(GeListNode* node, HyperFile* hf, Int32 level)
	{
		if (level >= 2) {
			AutoAlloc<BaseLink> Model_link;
			if (!Model_link->Read(hf))
				return false;
			if (Model_link == nullptr)
				return false;
			this->m_Model_ptr = static_cast<BaseObject*>(Model_link->ForceGetLink());
			Int64 data_countA = 0;
			if (!hf->ReadInt64(&data_countA))
				return false;
			for (Int64 i = 0; i < data_countA; ++i)
			{
				String name;
				if (!hf->ReadString(&name))
					return false;
				auto& data = m_MorphData_map.InsertKey(std::move(name)).GetValue();
				Int64 data_countB = 0;
				if (!hf->ReadInt64(&data_countB))
					return false;
				for (Int64 j = 0; j < data_countB; ++j)
				{
					mesh_morph_hub_data& mesh_morph_data = data.Append().GetValue();
					if (!mesh_morph_data.Read(hf))
						return false;
				}
			}
		}
		return true;
	}
	Bool OMMDMeshRoot::Write(GeListNode* node, HyperFile* hf)
	{
		// level >= 2
		AutoAlloc<BaseLink> Model_link;
		if (Model_link == nullptr)
			return false;
		Model_link->SetLink(this->m_Model_ptr);
		if (!Model_link->Write(hf))
			return false;
		if (!hf->WriteInt64(this->m_MorphData_map.GetCount()))
			return false;
		for (auto& i : m_MorphData_map)
		{
			if (!hf->WriteString(i.GetKey()))
				return false;
			auto& data = i.GetValue();
			if (!hf->WriteInt64(data.GetCount()))
				return false;
			for (auto& j : data)
			{
				if (!j.Write(hf))
					return false;
			}
		}
		return true;
	}
	Bool OMMDMeshRoot::CopyTo(NodeData* dest, GeListNode* snode, GeListNode* dnode, COPYFLAGS flags, AliasTrans* trn)
	{
		OMMDMeshRoot* dest_object = static_cast<OMMDMeshRoot*>(dest);
		dest_object->m_Model_ptr = m_Model_ptr;
		for (auto& i : m_MorphData_map)
		{
			iferr(dest_object->m_MorphData_map.InsertKey(i.GetKey()).GetValue().CopyFrom(i.GetValue()))
				return false;
		}
		return true;
	}
	Bool OMMDMeshRoot::SetDParameter(GeListNode* node, const DescID& id, const GeData& t_data, DESCFLAGS_SET& flags)
	{
		BaseObject* op = static_cast<BaseObject*>(node);
		if (id[0].id == MESH_DISPLAY_TYPE && m_displayTag != nullptr)
		{
			switch (t_data.GetInt32())
			{
			case MESH_DISPLAY_TYPE_OFF:
			{
				op->SetEditorMode(MODE_OFF);
				op->SetRenderMode(MODE_OFF);
				break;
			}
			case MESH_DISPLAY_TYPE_ON:
			{
				op->SetEditorMode(MODE_UNDEF);
				op->SetRenderMode(MODE_UNDEF);
				m_displayTag->SetParameter(DISPLAYTAG_SDISPLAYMODE, DISPLAYTAG_SDISPLAY_GOURAUD, DESCFLAGS_SET::NONE);
				break;
			}
			case MESH_DISPLAY_TYPE_ON_WIRE:
			{
				op->SetEditorMode(MODE_UNDEF);
				op->SetRenderMode(MODE_UNDEF);
				m_displayTag->SetParameter(DISPLAYTAG_SDISPLAYMODE, DISPLAYTAG_SDISPLAY_GOURAUD_WIRE, DESCFLAGS_SET::NONE);
				break;
			}
			case MESH_DISPLAY_TYPE_QUICK:
			{
				op->SetEditorMode(MODE_UNDEF);
				op->SetRenderMode(MODE_UNDEF);
				m_displayTag->SetParameter(DISPLAYTAG_SDISPLAYMODE, DISPLAYTAG_SDISPLAY_QUICK, DESCFLAGS_SET::NONE);
				break;
			}
			case MESH_DISPLAY_TYPE_QUICK_WIRE:
			{
				op->SetEditorMode(MODE_UNDEF);
				op->SetRenderMode(MODE_UNDEF);
				m_displayTag->SetParameter(DISPLAYTAG_SDISPLAYMODE, DISPLAYTAG_SDISPLAY_QUICK_WIRE, DESCFLAGS_SET::NONE);
				break;
			}
			case MESH_DISPLAY_TYPE_HIDDENLINE:
			{
				op->SetEditorMode(MODE_UNDEF);
				op->SetRenderMode(MODE_UNDEF);
				m_displayTag->SetParameter(DISPLAYTAG_SDISPLAYMODE, DISPLAYTAG_SDISPLAY_HIDDENLINE, DESCFLAGS_SET::NONE);
				break;
			}
			case MESH_DISPLAY_TYPE_WIRE:
			{
				op->SetEditorMode(MODE_UNDEF);
				op->SetRenderMode(MODE_UNDEF);
				m_displayTag->SetParameter(DISPLAYTAG_SDISPLAYMODE, DISPLAYTAG_SDISPLAY_NOSHADING, DESCFLAGS_SET::NONE);
				break;
			}
			default:
				break;
			}
		}
		return SUPER::SetDParameter(node, id, t_data, flags);
	}

	Bool OMMDMeshRoot::Message(GeListNode* node, Int32 type, void* data)
	{
		iferr_scope_handler{
		return SUPER::Message(node, type, data);
		};
		switch (type)
		{
		case ID_O_MMD_MODEL:
		{
			auto* msg = static_cast<OMMDModel_MSG*>(data);
			if (msg != nullptr)
			{
				if (msg->msg_type == OMMDModel_MSG_Type::TOOL_OBJECT_UPDATA) {
					switch (msg->object_type)
					{
					case ToolObjectType::Model:
					{
						this->m_Model_ptr = msg->object;
						break;
					}
					case ToolObjectType::DEFAULT: break;
					case ToolObjectType::MeshRoot: break;
					case ToolObjectType::BoneRoot: break;
					case ToolObjectType::RigidRoot: break;
					case ToolObjectType::JointRoot: break;
					default:
						break;
					}
				}
			}
			break;
		}
		default:
			break;
		}
		return SUPER::Message(node, type, data);
	}
	inline void OMMDMeshRoot::RefreshMorphMap(BaseObject* op)
	{
		iferr_scope_handler{ return; };
		Bool need_update_morph = false;
		maxon::Queue<BaseObject*> nodes;
		maxon::HashSet<String> morph_name_list;
		nodes.Push(op)iferr_return;
		while (!nodes.IsEmpty())
		{
			BaseObject* node = *(nodes.Pop());
			while (node != nullptr)
			{
				if (node->GetType() == Opolygon)
				{
					BaseTag* const node_morph_tag = node->GetTag(Tposemorph);
					if (node_morph_tag != nullptr)
					{
						const auto pose_morph_tag = static_cast<CAPoseMorphTag*>(node_morph_tag);
						const Int32 morph_mode = pose_morph_tag->GetMode();
						const Int32 morph_count = pose_morph_tag->GetMorphCount();
						for (Int32 index = 1; index < morph_count; index++)
						{
							morph_name_list.Insert(pose_morph_tag->GetMorph(index)->GetName())iferr_return;
						}
						const auto morph_previous_model_ptr = m_tag_mode_map.Find(pose_morph_tag);
						if(morph_previous_model_ptr!=nullptr)
						{
							if(morph_mode == morph_previous_model_ptr->GetValue() || morph_mode == ID_CA_POSE_MODE_EDIT)
							{
								morph_previous_model_ptr->SetValue(morph_mode);
								goto NEXT_MORPH_TAG;
							}
							morph_previous_model_ptr->SetValue(morph_mode);
						}
						else
						{
							m_tag_mode_map.Insert(node_morph_tag, morph_mode)iferr_return;
						}
						for (Int32 index = 1; index < morph_count; index++)
						{
							auto* morph = pose_morph_tag->GetMorph(index);
							String morph_name = morph->GetName();
							DescID morph_id = pose_morph_tag->GetMorphID(index);
							maxon::BaseList<mesh_morph_hub_data>* mesh_morph_list;
							const auto mesh_morph_map_ptr = m_MorphData_map.Find(morph_name);
							if (mesh_morph_map_ptr != nullptr)
							{
								mesh_morph_list = &mesh_morph_map_ptr->GetValue();
								for (auto& morph_data : *mesh_morph_list) {
									if (morph_data.morph_tag->ForceGetLink() == pose_morph_tag && morph_data.strength_id == morph_id)
										goto NEXT_MORPH;
								}
							}
							else {
								mesh_morph_list = &m_MorphData_map.InsertEntry(morph_name).GetValue().GetValue();
							}
							need_update_morph = true;
							mesh_morph_list->Append(mesh_morph_hub_data{ pose_morph_tag, morph_id })iferr_return;
						NEXT_MORPH:;
						}
					}
				}
				NEXT_MORPH_TAG:
				nodes.Push(node->GetDown()) iferr_return;
				if (node != op)
				{
					node = node->GetNext();
				}
				else {
					break;
				}
			}
		}
		// 移除已删除的表情
		if (m_MorphData_map.GetCount() > morph_name_list.GetCount()) {
			for (auto name_it = m_MorphData_map.GetKeys().begin(); name_it != m_MorphData_map.GetKeys().end(); ++name_it)
			{
				auto& name = *name_it;
				if (morph_name_list.Find(name) == nullptr) {
					m_MorphData_map.Erase(name)iferr_return;
					need_update_morph = true;
				}
			}
		}
		if (need_update_morph == true) {
			if (m_Model_ptr != nullptr) {
				const maxon::StrongRef<OMMDMeshRoot_MSG> Model_msg(
					NewObj(OMMDMeshRoot_MSG, OMMDMeshRoot_MSG_Type::MESH_MORPH_CHANGE).GetValue());
				m_Model_ptr->Message(ID_O_MMD_MESH_ROOT, Model_msg);
			}
		}
	}
	EXECUTIONRESULT OMMDMeshRoot::Execute(BaseObject* op, BaseDocument* doc, BaseThread* bt, Int32 priority, EXECUTIONFLAGS flags) {
		// Temp
		if (m_Model_ptr == nullptr) 
		{
			BaseObject* up_object = op->GetUp();
			if (up_object->IsInstanceOf(ID_O_MMD_MODEL))
			{
				m_Model_ptr = up_object;
			}
		}
		RefreshMorphMap(op);
		return EXECUTIONRESULT::OK;
	}

	Bool OMMDMeshRoot::AddToExecution(BaseObject* op, PriorityList* list) {
		if (list == nullptr || op == nullptr)
		{
			return(true);
		}
		list->Add(op, EXECUTIONPRIORITY_EXPRESSION - 2, EXECUTIONFLAGS::NONE);
		return(true);
	}
}