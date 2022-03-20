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
			OMMDModel_MSG* msg = static_cast<OMMDModel_MSG*>(data);
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

	EXECUTIONRESULT OMMDMeshRoot::Execute(BaseObject* op, BaseDocument* doc, BaseThread* bt, Int32 priority, EXECUTIONFLAGS flags) {
		iferr_scope_handler{ return EXECUTIONRESULT::OK; };
		Bool need_update_morph = false;
		maxon::Queue<BaseObject*> nodes;
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
						CAPoseMorphTag* const	pose_morph_tag = static_cast<CAPoseMorphTag*>(node_morph_tag);
						const Int morph_count = pose_morph_tag->GetMorphCount();
						for (Int32 index = 1; index < morph_count; index++)
						{
							auto* morph = pose_morph_tag->GetMorph(index);
							String morph_name = morph->GetName();
							DescID morph_id = pose_morph_tag->GetMorphID(index);
							auto mesh_morph_map_ptr = m_mesh_morph_map.Find(morph_name);
							while (mesh_morph_map_ptr != nullptr)
							{
								if (mesh_morph_map_ptr->GetValue().morph_strength_id == morph_id)
									goto NEXT_MORPH;
								mesh_morph_map_ptr = mesh_morph_map_ptr->GetNextWithSameKey();
							}
							need_update_morph = true;
							auto& morph_data = m_mesh_morph_map.InsertMultiEntry(morph_name).GetValue().GetValue();
							morph_data.morph_tag = pose_morph_tag;
							morph_data.morph_strength_id = morph_id;
						NEXT_MORPH:
							continue;
						}
					}
				}
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
		if (need_update_morph == true) {
			if (m_Model_ptr != nullptr) {
				m_Model_ptr->Message(ID_O_MMD_MESH_ROOT, NewObj(OMMDMeshRoot_MSG, OMMDMeshRoot_MSG_Type::MESH_MORPH_CHANGE).GetValue());
			}
		}
		return EXECUTIONRESULT::OK;
	}

	Bool OMMDMeshRoot::AddToExecution(BaseObject* op, PriorityList* list) {
		if (list == nullptr || op == nullptr)
		{
			return(true);
		}
		list->Add(op, EXECUTIONPRIORITY_EXPRESSION, EXECUTIONFLAGS::NONE);
		return(true);
	}
}