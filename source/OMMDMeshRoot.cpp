#include "OMMDMeshRoot.h"
#include "description/OMMDMeshRoot.h"

Bool mmd::OMMDMeshRoot::Init(GeListNode* node)
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
		BaseTag* DisplayTag = static_cast<BaseObject*>(node)->MakeTag(Tdisplay);
		if (DisplayTag != nullptr)
		{
			DisplayTag->SetParameter(DISPLAYTAG_AFFECT_DISPLAYMODE, true, DESCFLAGS_SET::NONE);
			DisplayTag->ChangeNBit(NBIT::OHIDE, NBITCONTROL::SET);
			DisplayTag->ChangeNBit(NBIT::AHIDE_FOR_HOST, NBITCONTROL::SET);
		}
	}
	return true;
}

Bool mmd::OMMDMeshRoot::SetDParameter(GeListNode* node, const DescID& id, const GeData& t_data, DESCFLAGS_SET& flags)
{
	BaseObject* op = static_cast<BaseObject*>(node);
	if (id[0].id == MESH_DISPLAY_TYPE)
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
			if (op->GetTag(Tdisplay) != nullptr)
				op->GetTag(Tdisplay)->SetParameter(DISPLAYTAG_SDISPLAYMODE, DISPLAYTAG_SDISPLAY_GOURAUD, DESCFLAGS_SET::NONE);
			break;
		}
		case MESH_DISPLAY_TYPE_ON_WIRE:
		{
			op->SetEditorMode(MODE_UNDEF);
			op->SetRenderMode(MODE_UNDEF);
			if (op->GetTag(Tdisplay) != nullptr)
				op->GetTag(Tdisplay)->SetParameter(DISPLAYTAG_SDISPLAYMODE, DISPLAYTAG_SDISPLAY_GOURAUD_WIRE, DESCFLAGS_SET::NONE);
			break;
		}
		case MESH_DISPLAY_TYPE_QUICK:
		{
			op->SetEditorMode(MODE_UNDEF);
			op->SetRenderMode(MODE_UNDEF);
			if (op->GetTag(Tdisplay) != nullptr)
				op->GetTag(Tdisplay)->SetParameter(DISPLAYTAG_SDISPLAYMODE, DISPLAYTAG_SDISPLAY_QUICK, DESCFLAGS_SET::NONE);
			break;
		}
		case MESH_DISPLAY_TYPE_QUICK_WIRE:
		{
			op->SetEditorMode(MODE_UNDEF);
			op->SetRenderMode(MODE_UNDEF);
			if (op->GetTag(Tdisplay) != nullptr)
				op->GetTag(Tdisplay)->SetParameter(DISPLAYTAG_SDISPLAYMODE, DISPLAYTAG_SDISPLAY_QUICK_WIRE, DESCFLAGS_SET::NONE);
			break;
		}
		case MESH_DISPLAY_TYPE_HIDDENLINE:
		{
			op->SetEditorMode(MODE_UNDEF);
			op->SetRenderMode(MODE_UNDEF);
			if (op->GetTag(Tdisplay) != nullptr)
				op->GetTag(Tdisplay)->SetParameter(DISPLAYTAG_SDISPLAYMODE, DISPLAYTAG_SDISPLAY_HIDDENLINE, DESCFLAGS_SET::NONE);
			break;
		}
		case MESH_DISPLAY_TYPE_WIRE:
		{
			op->SetEditorMode(MODE_UNDEF);
			op->SetRenderMode(MODE_UNDEF);
			if (op->GetTag(Tdisplay) != nullptr)
				op->GetTag(Tdisplay)->SetParameter(DISPLAYTAG_SDISPLAYMODE, DISPLAYTAG_SDISPLAY_NOSHADING, DESCFLAGS_SET::NONE);
			break;
		}
		default:
			break;
		}
	}
	return SUPER::SetDParameter(node, id, t_data, flags);
}

EXECUTIONRESULT mmd::OMMDMeshRoot::Execute(BaseObject* op, BaseDocument* doc, BaseThread* bt, Int32 priority, EXECUTIONFLAGS flags) {
	iferr_scope_handler{ return EXECUTIONRESULT::OK; };
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
						auto& morph_data = m_mesh_morph_map.InsertMultiEntry(morph->GetName()).GetValue().GetValue();
						morph_data.morph_tag = pose_morph_tag;
						morph_data.morph = morph;
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
	return EXECUTIONRESULT::OK;
}

Bool mmd::OMMDMeshRoot::AddToExecution(BaseObject* op, PriorityList* list) {
	if (list == nullptr || op == nullptr)
	{
		return(true);
	}
	list->Add(op, EXECUTIONPRIORITY_EXPRESSION, EXECUTIONFLAGS::NONE);
	return(true);
}