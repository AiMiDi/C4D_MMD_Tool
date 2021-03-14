#include "MMD_PMX_tag.h"
#undef GetObject

Bool mmd::PMX_Model_Tag::Init(GeListNode* node)
{
	node->SetParameter(DescID(ID_BASELIST_NAME), GeLoadString(IDS_PMX_MODEL_TAG), DESCFLAGS_SET::NONE);
	node->SetParameter(DescID(PMX_VERSION), 2.1, DESCFLAGS_SET::NONE);
	node->SetParameter(DescID(MODEL_NAME_LOCAL), "name"_s, DESCFLAGS_SET::NONE);
	node->SetParameter(DescID(MODEL_NAME_UNIVERSAL), "name"_s, DESCFLAGS_SET::NONE);
	node->SetParameter(DescID(COMMENTS_LOCAL), "description"_s, DESCFLAGS_SET::NONE);
	node->SetParameter(DescID(COMMENTS_UNIVERSAL), "description"_s, DESCFLAGS_SET::NONE);
	return true;
}

Bool mmd::PMX_Model_Tag::GetDDescription(GeListNode* node, Description* description, DESCFLAGS_DESC& flags) 
{
	if (!description->LoadDescription("PMX_Model_Tag"_s))
		return false;
	const DescID* singleid = description->GetSingleDescID();
	MAXON_SCOPE
	{
		DescID cid = DescID(MODEL_INFO_GRP);
		if (singleid == nullptr || cid.IsPartOf(*singleid, nullptr))
		{
			BaseContainer* settings =  description->GetParameterI(cid, nullptr);
			if (settings)settings->SetBool(DESC_GROUPSCALEV, true);
		}
	}
	flags |= DESCFLAGS_DESC::LOADED;

	return true;
}

Bool mmd::PMX_Model_Tag::UpDataBoneList(BaseTag* tag, BaseObject* obj) {
	if (tag == nullptr || obj == nullptr) {
		return false;
	}
	Int index = 0;
	BaseObject* Bones_obj = obj->GetDown();
	while (Bones_obj->GetName() != "Bones" && Bones_obj != nullptr)
	{
		Bones_obj = Bones_obj->GetNext();
	}
	if (Bones_obj == nullptr) {
		return false;
	}else {
		BaseObject* bone = Bones_obj->GetDown();
		if (bone!=nullptr) {

			maxon::Queue<BaseObject*> nodes;
			iferr(nodes.Push(bone))return false;
			while (!nodes.IsEmpty())
			{
				BaseObject* node = *(nodes.Pop());
				while (node != nullptr)
				{
					if (node->GetType() == Ojoint)
					{
							BaseTag* node_tag = node->GetTag(ID_PMX_BONE_TAG);
							if (node_tag != nullptr) {
								node_tag->SetParameter(DescID(BONE_INDEX), String::IntToString(index), DESCFLAGS_SET::NONE);
								index++;
							}				
					}
					iferr(nodes.Push(node->GetDown()))return false;
					if (node != bone) {
						node = node->GetNext();
					}
					else {
						break;
					}
				}
			}
		}
	}
	return true;
}

Bool mmd::PMX_Model_Tag::Message(GeListNode* node, Int32 type, void* data) {
	if (type == MSG_DRAGANDDROP || type == MSG_PMX_BONE_ORDER_CHANGES)
	{
		
	}
	return true;
}

Bool mmd::PMX_Bone_Tag::Init(GeListNode* node)
{
	node->SetParameter(DescID(ID_BASELIST_NAME), GeLoadString(IDS_PMX_MODEL_TAG), DESCFLAGS_SET::NONE);
	node->SetParameter(DescID(BONE_NAME_LOCAL), "bone"_s, DESCFLAGS_SET::NONE);
	node->SetParameter(DescID(NAME_IS_LOCAL), 2, DESCFLAGS_SET::NONE);
	node->SetParameter(DescID(BONE_NAME_UNIVERSAL), "bone"_s, DESCFLAGS_SET::NONE);
	node->SetParameter(DescID(PARENT_BONE_INDEX), -1, DESCFLAGS_SET::NONE);
	node->SetParameter(DescID(ROTATABLE), 1, DESCFLAGS_SET::NONE);
	node->SetParameter(DescID(VISIBLE), 1, DESCFLAGS_SET::NONE);
	node->SetParameter(DescID(ENABLED), 1, DESCFLAGS_SET::NONE);
	node->SetParameter(DescID(TAIL_INDEX),-1, DESCFLAGS_SET::NONE);
	node->SetParameter(DescID(INHERIT_BONE_PARENT_INDEX), -1, DESCFLAGS_SET::NONE);
	node->SetParameter(DescID(INHERIT_BONE_PARENT_INFLUENCE), 1.0 , DESCFLAGS_SET::NONE);
	node->SetParameter(DescID(BONE_LOCAL_X), Vector(1, 0, 0), DESCFLAGS_SET::NONE);
	node->SetParameter(DescID(BONE_LOCAL_Z), Vector(0, 0, 1), DESCFLAGS_SET::NONE);
	return true;
}

Bool mmd::PMX_Bone_Tag::GetDEnabling(GeListNode *node, const DescID &id, const GeData &t_data, DESCFLAGS_ENABLE flags, const BaseContainer *itemdesc)
{
	if (id == DescID(PARENT_BONE_LINK)) {
		GeData Ge_data;
		node->GetParameter(DescID(PARENT_BONE_INDEX), Ge_data, DESCFLAGS_GET::NONE);
		Int32 parent_bone_index = Ge_data.GetInt32();
		if (parent_bone_index == -1) {
			return false;
		}
	}
	if (id == DescID(TAIL_INDEX)) {
		GeData Ge_data;
		node->GetParameter(DescID(INDEXED_TAIL_POSITION), Ge_data, DESCFLAGS_GET::NONE);
		Bool indexed_tail_position = Ge_data.GetBool();
		if (indexed_tail_position == 0) {
			return false;
		}
	}
	if (id == DescID(TAIL_POSITION)) {
		GeData Ge_data;
		node->GetParameter(DescID(INDEXED_TAIL_POSITION), Ge_data, DESCFLAGS_GET::NONE);
		Bool indexed_tail_position = Ge_data.GetBool();
		if (indexed_tail_position == 1) {
			return false;
		}
	}
	if (id == DescID(INHERIT_BONE_PARENT_INDEX)) {
		GeData Ge_data;
		node->GetParameter(DescID(INHERIT_ROTATION), Ge_data, DESCFLAGS_GET::NONE);
		Bool inherit_rotation = Ge_data.GetBool();
		node->GetParameter(DescID(INHERIT_TRANSLATION), Ge_data, DESCFLAGS_GET::NONE);
		Bool inherit_translation = Ge_data.GetBool();
		if (inherit_rotation == 0 && inherit_translation == 0) {
			return false;
		}
	}
	if (id == DescID(INHERIT_BONE_PARENT_INFLUENCE)) {
		GeData Ge_data;
		node->GetParameter(DescID(INHERIT_ROTATION), Ge_data, DESCFLAGS_GET::NONE);
		Bool inherit_rotation = Ge_data.GetBool();
		node->GetParameter(DescID(INHERIT_TRANSLATION), Ge_data, DESCFLAGS_GET::NONE);
		Bool inherit_translation = Ge_data.GetBool();
		if (inherit_rotation == 0 && inherit_translation == 0) {
			return false;
		}
	}
	if (id == DescID(INHERIT_BONE_PARENT_LINK)) {
		GeData Ge_data;
		node->GetParameter(DescID(INHERIT_ROTATION), Ge_data, DESCFLAGS_GET::NONE);
		Bool inherit_rotation = Ge_data.GetBool();
		node->GetParameter(DescID(INHERIT_TRANSLATION), Ge_data, DESCFLAGS_GET::NONE);
		Bool inherit_translation = Ge_data.GetBool();
		if (inherit_rotation == 0 && inherit_translation == 0) {
			return false;
		}
	}
	if (id == DescID(BONE_FIXED_AXIS)) {
		GeData Ge_data;
		node->GetParameter(DescID(FIXED_AXIS), Ge_data, DESCFLAGS_GET::NONE);
		Bool fixed_axis = Ge_data.GetBool();
		if (fixed_axis == 0) {
			return false;
		}
	}
	if (id == DescID(BONE_LOCAL_X)) {
		GeData Ge_data;
		node->GetParameter(DescID(LOCAL_COORDINATE), Ge_data, DESCFLAGS_GET::NONE);
		Bool local_coordinate = Ge_data.GetBool();
		if (local_coordinate == 0) {
			return false;
		}
	}
	if (id == DescID(BONE_LOCAL_Z)) {
		GeData Ge_data;
		node->GetParameter(DescID(LOCAL_COORDINATE), Ge_data, DESCFLAGS_GET::NONE);
		Bool local_coordinate = Ge_data.GetBool();
		if (local_coordinate == 0) {
			return false;
		}
	}
	return true;
}

Bool mmd::PMX_Bone_Tag::Message(GeListNode* node, Int32 type, void* data)
{
	if (type == 1073741828)
	{
		BaseTag* tag = (BaseTag*)node;
		return tagUpData(tag, tag->GetObject()) ? true : false;
	}
	return true;
}

Bool mmd::PMX_Bone_Tag::tagUpData(BaseTag* tag, BaseObject* obj)
{		
		if (tag == nullptr || obj == nullptr) {			
			return false;
		}
		GeData Ge_data;
		BaseObject* up_obj = obj->GetUp();
		if (up_obj != nullptr) {
			if (up_obj->GetName() != "Bones"_s) {
				BaseLink* parent_bone_link = BaseLink::Alloc();
				if (parent_bone_link == nullptr) {
					GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
					MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
					return false;
				}
				parent_bone_link->SetLink(up_obj);
				tag->SetParameter(DescID(PARENT_BONE_LINK), parent_bone_link, DESCFLAGS_SET::NONE);
				BaseTag* up_tag = up_obj->GetTag(ID_PMX_BONE_TAG);
				if (up_tag != nullptr) {
					up_tag->GetParameter(DescID(BONE_INDEX), Ge_data, DESCFLAGS_GET::NONE);
					tag->SetParameter(DescID(PARENT_BONE_INDEX), Ge_data.GetString().ToInt32(nullptr), DESCFLAGS_SET::NONE);
				}
			}
		}
		tag->GetParameter(DescID(BONE_NAME_IS), Ge_data, DESCFLAGS_GET::NONE);
		Int32 bone_name_is = Ge_data.GetInt32();
		if (bone_name_is) {
			tag->GetParameter(DescID(BONE_NAME_UNIVERSAL), Ge_data, DESCFLAGS_GET::NONE);
			obj->SetName(Ge_data.GetString());
		}
		else {
			tag->GetParameter(DescID(BONE_NAME_LOCAL), Ge_data, DESCFLAGS_GET::NONE);
			obj->SetName(Ge_data.GetString());
		}

		tag->GetParameter(DescID(ROTATABLE), Ge_data, DESCFLAGS_GET::NONE);
		Bool Is_rotatable = Ge_data.GetBool();
		if (Is_rotatable == 1) {
			BaseTag* protection_tag = obj->GetTag(Tprotection);
			if (protection_tag == nullptr) {
				protection_tag = obj->MakeTag(Tprotection);
			}
			if (protection_tag == nullptr) {
				GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
				MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
				return false;
			}
			tag->SetParameter(DescID(ID_BASELIST_ICON_COLORIZE_MODE), ID_BASELIST_ICON_COLORIZE_MODE_CUSTOM, DESCFLAGS_SET::NONE);
			tag->SetParameter(DescID(ID_BASELIST_ICON_COLOR), Vector(0.56640625, 0.78125, 1), DESCFLAGS_SET::NONE);
			obj->SetParameter(DescID(ID_BASELIST_ICON_COLORIZE_MODE), ID_BASELIST_ICON_COLORIZE_MODE_CUSTOM, DESCFLAGS_SET::NONE);
			obj->SetParameter(DescID(ID_BASELIST_ICON_COLOR), Vector(0.56640625, 0.78125, 1), DESCFLAGS_SET::NONE);
			obj->SetParameter(DescID(ID_BASEOBJECT_USECOLOR), ID_BASEOBJECT_USECOLOR_ALWAYS, DESCFLAGS_SET::NONE);
			obj->SetParameter(DescID(ID_BASEOBJECT_COLOR), Vector(0.56640625, 0.78125, 1), DESCFLAGS_SET::NONE);
			protection_tag->SetParameter(DescID(PROTECTION_R_X), false, DESCFLAGS_SET::NONE);
			protection_tag->SetParameter(DescID(PROTECTION_R_Y), false, DESCFLAGS_SET::NONE);
			protection_tag->SetParameter(DescID(PROTECTION_R_Z), false, DESCFLAGS_SET::NONE);
		}
		else {
			BaseTag* protection_tag = obj->GetTag(Tprotection);
			if (protection_tag == nullptr) {
				protection_tag = obj->MakeTag(Tprotection);
			}
			if (protection_tag == nullptr) {
				GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
				MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
				return false;
			}
			tag->SetParameter(DescID(ID_BASELIST_ICON_COLORIZE_MODE), ID_BASELIST_ICON_COLORIZE_MODE_CUSTOM, DESCFLAGS_SET::NONE);
			tag->SetParameter(DescID(ID_BASELIST_ICON_COLOR), Vector(0.56640625, 0.78125, 1), DESCFLAGS_SET::NONE);
			obj->SetParameter(DescID(ID_BASELIST_ICON_COLORIZE_MODE), ID_BASELIST_ICON_COLORIZE_MODE_CUSTOM, DESCFLAGS_SET::NONE);
			obj->SetParameter(DescID(ID_BASELIST_ICON_COLOR), Vector(0.56640625, 0.78125, 1), DESCFLAGS_SET::NONE);
			obj->SetParameter(DescID(ID_BASEOBJECT_USECOLOR), ID_BASEOBJECT_USECOLOR_ALWAYS, DESCFLAGS_SET::NONE);
			obj->SetParameter(DescID(ID_BASEOBJECT_COLOR), Vector(0.56640625, 0.78125, 1), DESCFLAGS_SET::NONE);
			protection_tag->SetParameter(DescID(PROTECTION_R_X), true, DESCFLAGS_SET::NONE);
			protection_tag->SetParameter(DescID(PROTECTION_R_Y), true, DESCFLAGS_SET::NONE);
			protection_tag->SetParameter(DescID(PROTECTION_R_Z), true, DESCFLAGS_SET::NONE);
		}

		tag->GetParameter(DescID(TRANSLATABLE), Ge_data, DESCFLAGS_GET::NONE);
		Bool Is_translatable = Ge_data.GetBool();
		if (Is_translatable == 1) {
			BaseTag* protection_tag = obj->GetTag(Tprotection);
			if (protection_tag == nullptr) {
				protection_tag = obj->MakeTag(Tprotection);
			}
			if (protection_tag == nullptr) {
				GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
				MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
				return false;
			}
			tag->SetParameter(DescID(ID_BASELIST_ICON_COLORIZE_MODE), ID_BASELIST_ICON_COLORIZE_MODE_CUSTOM, DESCFLAGS_SET::NONE);
			tag->SetParameter(DescID(ID_BASELIST_ICON_COLOR), Vector(0.703125, 1, 0.546875), DESCFLAGS_SET::NONE);
			obj->SetParameter(DescID(ID_BASELIST_ICON_COLORIZE_MODE), ID_BASELIST_ICON_COLORIZE_MODE_CUSTOM, DESCFLAGS_SET::NONE);
			obj->SetParameter(DescID(ID_BASELIST_ICON_COLOR), Vector(0.703125, 1, 0.546875), DESCFLAGS_SET::NONE);
			obj->SetParameter(DescID(ID_BASEOBJECT_USECOLOR), ID_BASEOBJECT_USECOLOR_ALWAYS, DESCFLAGS_SET::NONE);
			obj->SetParameter(DescID(ID_BASEOBJECT_COLOR), Vector(0.703125, 1, 0.546875), DESCFLAGS_SET::NONE);
			protection_tag->SetParameter(DescID(PROTECTION_P_X), false, DESCFLAGS_SET::NONE);
			protection_tag->SetParameter(DescID(PROTECTION_P_Y), false, DESCFLAGS_SET::NONE);
			protection_tag->SetParameter(DescID(PROTECTION_P_Z), false, DESCFLAGS_SET::NONE);
		}
		else {
			BaseTag* protection_tag = obj->GetTag(Tprotection);
			if (protection_tag == nullptr) {
				protection_tag = obj->MakeTag(Tprotection);
			}
			if (protection_tag == nullptr) {
				GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
				MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
				return false;
			}
			protection_tag->SetParameter(DescID(PROTECTION_P_X), true, DESCFLAGS_SET::NONE);
			protection_tag->SetParameter(DescID(PROTECTION_P_Y), true, DESCFLAGS_SET::NONE);
			protection_tag->SetParameter(DescID(PROTECTION_P_Z), true, DESCFLAGS_SET::NONE);
		}

		tag->GetParameter(DescID(IS_IK), Ge_data, DESCFLAGS_GET::NONE);
		Bool Is_IK = Ge_data.GetBool();
		if (Is_IK == 1) {
			tag->SetParameter(DescID(ID_BASELIST_ICON_COLORIZE_MODE), ID_BASELIST_ICON_COLORIZE_MODE_CUSTOM, DESCFLAGS_SET::NONE);
			tag->SetParameter(DescID(ID_BASELIST_ICON_COLOR), Vector(0.984375, 0.375, 0), DESCFLAGS_SET::NONE);
			obj->SetParameter(DescID(ID_BASELIST_ICON_COLORIZE_MODE), ID_BASELIST_ICON_COLORIZE_MODE_CUSTOM, DESCFLAGS_SET::NONE);
			obj->SetParameter(DescID(ID_BASELIST_ICON_COLOR), Vector(0.984375, 0.375, 0), DESCFLAGS_SET::NONE);
			obj->SetParameter(DescID(ID_BASEOBJECT_USECOLOR), ID_BASEOBJECT_USECOLOR_ALWAYS, DESCFLAGS_SET::NONE);
			obj->SetParameter(DescID(ID_BASEOBJECT_COLOR), Vector(0.984375, 0.375, 0), DESCFLAGS_SET::NONE);
		}

		tag->GetParameter(DescID(VISIBLE), Ge_data, DESCFLAGS_GET::NONE);
		Bool Is_visible = Ge_data.GetBool();
		if (Is_visible == 0) {
			tag->SetParameter(DescID(ID_BASELIST_ICON_COLORIZE_MODE), ID_BASELIST_ICON_COLORIZE_MODE_CUSTOM, DESCFLAGS_SET::NONE);
			tag->SetParameter(DescID(ID_BASELIST_ICON_COLOR), Vector(0.4, 0.4, 0.4), DESCFLAGS_SET::NONE);
			obj->SetParameter(DescID(ID_BASELIST_ICON_COLORIZE_MODE), ID_BASELIST_ICON_COLORIZE_MODE_CUSTOM, DESCFLAGS_SET::NONE);
			obj->SetParameter(DescID(ID_BASELIST_ICON_COLOR), Vector(0.4, 0.4, 0.4), DESCFLAGS_SET::NONE);
			obj->SetParameter(DescID(ID_CA_JOINT_OBJECT_JOINT_DISPLAY), ID_CA_JOINT_OBJECT_JOINT_DISPLAY_NONE, DESCFLAGS_SET::NONE);
			obj->SetParameter(DescID(ID_CA_JOINT_OBJECT_BONE_DISPLAY), ID_CA_JOINT_OBJECT_BONE_DISPLAY_NONE, DESCFLAGS_SET::NONE);
		}
		else {
			obj->SetParameter(DescID(ID_CA_JOINT_OBJECT_JOINT_DISPLAY), ID_CA_JOINT_OBJECT_JOINT_DISPLAY_AXIS, DESCFLAGS_SET::NONE);
			obj->SetParameter(DescID(ID_CA_JOINT_OBJECT_BONE_DISPLAY), ID_CA_JOINT_OBJECT_BONE_DISPLAY_STANDARD, DESCFLAGS_SET::NONE);
		}

		tag->GetParameter(DescID(FIXED_AXIS), Ge_data, DESCFLAGS_GET::NONE);
		Bool Fixed_axis = Ge_data.GetBool();
		if (Fixed_axis == 1) {
			tag->SetParameter(DescID(ID_BASELIST_ICON_COLORIZE_MODE), ID_BASELIST_ICON_COLORIZE_MODE_CUSTOM, DESCFLAGS_SET::NONE);
			tag->SetParameter(DescID(ID_BASELIST_ICON_COLOR), Vector(0.7265625, 0.328125, 1), DESCFLAGS_SET::NONE);
			obj->SetParameter(DescID(ID_BASELIST_ICON_COLORIZE_MODE), ID_BASELIST_ICON_COLORIZE_MODE_CUSTOM, DESCFLAGS_SET::NONE);
			obj->SetParameter(DescID(ID_BASELIST_ICON_COLOR), Vector(0.7265625, 0.328125, 1), DESCFLAGS_SET::NONE);
			obj->SetParameter(DescID(ID_BASEOBJECT_COLOR), Vector(0.7265625, 0.328125, 1), DESCFLAGS_SET::NONE);
		}

		tag->GetParameter(DescID(INHERIT_BONE_PARENT_INFLUENCE), Ge_data, DESCFLAGS_GET::NONE);
		Float Inherit_bone_parent_influence = Ge_data.GetFloat();
		tag->GetParameter(DescID(INHERIT_ROTATION), Ge_data, DESCFLAGS_GET::NONE);
		Bool Inherit_rotation = Ge_data.GetBool();
		tag->GetParameter(DescID(INHERIT_TRANSLATION), Ge_data, DESCFLAGS_GET::NONE);
		Bool Inherit_translation = Ge_data.GetBool();
		if (Inherit_rotation == 1) {
			tag->SetParameter(DescID(ID_BASELIST_ICON_COLORIZE_MODE), ID_BASELIST_ICON_COLORIZE_MODE_CUSTOM, DESCFLAGS_SET::NONE);
			tag->SetParameter(DescID(ID_BASELIST_ICON_COLOR), Vector(0.682353, 0.64453125, 1), DESCFLAGS_SET::NONE);
			obj->SetParameter(DescID(ID_BASELIST_ICON_COLORIZE_MODE), ID_BASELIST_ICON_COLORIZE_MODE_CUSTOM, DESCFLAGS_SET::NONE);
			obj->SetParameter(DescID(ID_BASELIST_ICON_COLOR), Vector(0.682353, 0.64453125, 1), DESCFLAGS_SET::NONE);
			obj->SetParameter(DescID(ID_BASEOBJECT_COLOR), Vector(0.682353, 0.64453125, 1), DESCFLAGS_SET::NONE);
			if (Inherit_bone_parent_influence > 0.0) {
				BaseTag* constraint_tag = obj->GetTag(1019364);
				if (constraint_tag == nullptr) {
					constraint_tag = obj->MakeTag(1019364);//Constraint Tag ID : 1019364	
					constraint_tag->SetName("Pmx bone inherit"_s);
				}
				if (constraint_tag != nullptr && constraint_tag->GetName() != "Pmx bone inherit"_s) {
					constraint_tag = obj->MakeTag(1019364);//Constraint Tag ID : 1019364	
					constraint_tag->SetName("Pmx bone inherit"_s);
				}
				if (constraint_tag == nullptr) {
					GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
					MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
					return false;
				}
				GeData data;
				constraint_tag->GetParameter(DescID(EXPRESSION_PRIORITY), data, DESCFLAGS_GET::NONE);
				CustomDataType* customData = data.GetCustomDataType(CUSTOMGUI_PRIORITY_DATA);
				PriorityData* priorityData = static_cast<PriorityData*>(customData);
				priorityData->SetPriorityValue(PRIORITYVALUE_PRIORITY, 1);
				constraint_tag->SetParameter(DescID(EXPRESSION_PRIORITY), data, DESCFLAGS_SET::NONE);
				constraint_tag->SetParameter(DescID(ID_CA_CONSTRAINT_TAG_PSR), true, DESCFLAGS_SET::NONE);
				constraint_tag->SetParameter(DescID(ID_CA_CONSTRAINT_TAG_FRAMEUPDATE), true, DESCFLAGS_SET::NONE);
				constraint_tag->SetParameter(DescID(ID_CA_CONSTRAINT_TAG_PSR_TWEIGHT), Inherit_bone_parent_influence, DESCFLAGS_SET::NONE);
				constraint_tag->SetParameter(DescID(10006), false, DESCFLAGS_SET::NONE);//ID_CA_CONSTRAINT_TAG_PSR_S
				constraint_tag->SetParameter(DescID(10007), true, DESCFLAGS_SET::NONE);//ID_CA_CONSTRAINT_TAG_PSR_R
				if (Inherit_rotation != 1) {
					constraint_tag->SetParameter(DescID(10005), false, DESCFLAGS_SET::NONE); //ID_CA_CONSTRAINT_TAG_PSR_P
				}
				tag->GetParameter(DescID(INHERIT_BONE_PARENT_LINK), data, DESCFLAGS_GET::NONE);
				BaseLink* inherit_bone_parent_link = data.GetBaseLink();
				if (inherit_bone_parent_link != nullptr) {
					constraint_tag->SetParameter(DescID(10001), inherit_bone_parent_link, DESCFLAGS_SET::NONE);//ID_CA_CONSTRAINT_TAG_PSR_LINK
				}			
			}
		}
		else if (Inherit_translation != 1) {
			BaseTag* constraint_tag = obj->GetTag(1019364);
			if (constraint_tag != nullptr) {
				if (constraint_tag->GetName() == "Pmx bone inherit"_s) {
					constraint_tag->Remove();
					BaseTag::Free(constraint_tag);
				}			
			}
		}
		if (Inherit_translation == 1) {
			tag->SetParameter(DescID(ID_BASELIST_ICON_COLORIZE_MODE), ID_BASELIST_ICON_COLORIZE_MODE_CUSTOM, DESCFLAGS_SET::NONE);
			tag->SetParameter(DescID(ID_BASELIST_ICON_COLOR), Vector(0.682353, 0.64453125, 1), DESCFLAGS_SET::NONE);
			obj->SetParameter(DescID(ID_BASELIST_ICON_COLORIZE_MODE), ID_BASELIST_ICON_COLORIZE_MODE_CUSTOM, DESCFLAGS_SET::NONE);
			obj->SetParameter(DescID(ID_BASELIST_ICON_COLOR), Vector(0.682353, 0.64453125, 1), DESCFLAGS_SET::NONE);
			obj->SetParameter(DescID(ID_BASEOBJECT_COLOR), Vector(0.682353, 0.64453125, 1), DESCFLAGS_SET::NONE);
			if (Inherit_bone_parent_influence > 0.0) {
				BaseTag* constraint_tag = obj->GetTag(1019364);
				if (constraint_tag == nullptr) {
					constraint_tag = obj->MakeTag(1019364);//Constraint Tag ID : 1019364	
					constraint_tag->SetName("Pmx bone inherit"_s);
				}
				if (constraint_tag != nullptr && constraint_tag->GetName() != "Pmx bone inherit"_s) {
					constraint_tag = obj->MakeTag(1019364);//Constraint Tag ID : 1019364	
					constraint_tag->SetName("Pmx bone inherit"_s);
				}
				if (constraint_tag == nullptr) {
					GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
					MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
					return false;
				}
				GeData data;
				constraint_tag->GetParameter(DescID(EXPRESSION_PRIORITY), data, DESCFLAGS_GET::NONE);
				CustomDataType* customData = data.GetCustomDataType(CUSTOMGUI_PRIORITY_DATA);
				PriorityData* priorityData = static_cast<PriorityData*>(customData);
				priorityData->SetPriorityValue(PRIORITYVALUE_PRIORITY, 1);
				constraint_tag->SetParameter(DescID(EXPRESSION_PRIORITY), data, DESCFLAGS_SET::NONE);
				constraint_tag->SetParameter(DescID(ID_CA_CONSTRAINT_TAG_PSR), true, DESCFLAGS_SET::NONE);
				constraint_tag->SetParameter(DescID(ID_CA_CONSTRAINT_TAG_FRAMEUPDATE), true, DESCFLAGS_SET::NONE);
				constraint_tag->SetParameter(DescID(ID_CA_CONSTRAINT_TAG_PSR_TWEIGHT), Inherit_bone_parent_influence, DESCFLAGS_SET::NONE);
				constraint_tag->SetParameter(DescID(10006), false, DESCFLAGS_SET::NONE);//ID_CA_CONSTRAINT_TAG_PSR_S
				constraint_tag->SetParameter(DescID(10005), true, DESCFLAGS_SET::NONE);//ID_CA_CONSTRAINT_TAG_PSR_P
				if (Inherit_rotation != 1) {
					constraint_tag->SetParameter(DescID(10007), false, DESCFLAGS_SET::NONE); //ID_CA_CONSTRAINT_TAG_PSR_R
				}
				tag->GetParameter(DescID(INHERIT_BONE_PARENT_LINK), data, DESCFLAGS_GET::NONE);
				BaseLink* inherit_bone_parent_link = data.GetBaseLink();
				if (inherit_bone_parent_link != nullptr) {
					constraint_tag->SetParameter(DescID(10001), inherit_bone_parent_link, DESCFLAGS_SET::NONE);//ID_CA_CONSTRAINT_TAG_PSR_LINK
				}
			}
		}else if (Inherit_rotation != 1) {
			BaseTag* constraint_tag = obj->GetTag(1019364);
			if (constraint_tag != nullptr) {
				if (constraint_tag->GetName() == "Pmx bone inherit"_s) {
					constraint_tag->Remove();
					BaseTag::Free(constraint_tag);
				}
			}
		}

		tag->GetParameter(DescID(TAIL_INDEX), Ge_data, DESCFLAGS_GET::NONE);
		Int32 Tail_index = Ge_data.GetInt32();
		tag->GetParameter(DescID(INDEXED_TAIL_POSITION), Ge_data, DESCFLAGS_GET::NONE);
		Bool Indexed_tail_position = Ge_data.GetBool();
		if (Indexed_tail_position == 1) {
			if (Tail_index == -1) {
				obj->SetParameter(DescID(ID_CA_JOINT_OBJECT_BONE_ALIGN), ID_CA_JOINT_OBJECT_BONE_ALIGN_NULL, DESCFLAGS_SET::NONE);
			}
			else {
				obj->SetParameter(DescID(ID_CA_JOINT_OBJECT_BONE_ALIGN), ID_CA_JOINT_OBJECT_BONE_ALIGN_TOCHILD, DESCFLAGS_SET::NONE);
			}
		}
	return true;
}