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
	return TRUE;
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

Bool mmd::PMX_Bone_Tag::Init(GeListNode* node)
{
	node->SetParameter(DescID(ID_BASELIST_NAME), GeLoadString(IDS_PMX_MODEL_TAG), DESCFLAGS_SET::NONE);
	node->SetParameter(DescID(BONE_NAME_LOCAL), "bone"_s, DESCFLAGS_SET::NONE);
	node->SetParameter(DescID(BONE_NAME_UNIVERSAL), "bone"_s, DESCFLAGS_SET::NONE);
	node->SetParameter(DescID(POSITION), Vector(0,0,0), DESCFLAGS_SET::NONE);
	node->SetParameter(DescID(PARENT_BONE_INDEX), -1, DESCFLAGS_SET::NONE);
	node->SetParameter(DescID(ROTATABLE), 1, DESCFLAGS_SET::NONE);
	node->SetParameter(DescID(TRANSLATABLE), 0, DESCFLAGS_SET::NONE);
	node->SetParameter(DescID(VISIBLE), 1, DESCFLAGS_SET::NONE);
	node->SetParameter(DescID(ENABLED), 1, DESCFLAGS_SET::NONE);
	node->SetParameter(DescID(IS_IK), 0, DESCFLAGS_SET::NONE);
	node->SetParameter(DescID(LAYER), 0, DESCFLAGS_SET::NONE);
	node->SetParameter(DescID(PHYSICS_AFTER_DEFORM), 0, DESCFLAGS_SET::NONE);
	node->SetParameter(DescID(INDEXED_TAIL_POSITION), 0, DESCFLAGS_SET::NONE);
	node->SetParameter(DescID(TAIL_INDEX),-1, DESCFLAGS_SET::NONE);
	node->SetParameter(DescID(TAIL_POSITION), Vector(0, 0, 0), DESCFLAGS_SET::NONE);
	return TRUE;
}

Bool mmd::PMX_Bone_Tag::GetDDescription(GeListNode* node, Description* description, DESCFLAGS_DESC& flags)
{
	if (!description->LoadDescription("PMX_Bone_Tag"_s))
		return false;
	const DescID* singleid = description->GetSingleDescID();

	GeData Ge_data;
	node->GetParameter(DescID(INDEXED_TAIL_POSITION), Ge_data, DESCFLAGS_GET::NONE);
	Int32 indexed_tail_position = Ge_data.GetInt32();
	if (indexed_tail_position == 1) {
		MAXON_SCOPE
		{
			DescID cid = DescID(TAIL_POSITION);
			if (singleid == nullptr || cid.IsPartOf(*singleid, nullptr))
			{
				BaseContainer* settings = description->GetParameterI(cid, nullptr);
				if (settings)settings->SetBool(DESC_EDITABLE, false);
			}
		}
		MAXON_SCOPE
		{
			DescID cid = DescID(TAIL_INDEX);
			if (singleid == nullptr || cid.IsPartOf(*singleid, nullptr))
			{
				BaseContainer* settings = description->GetParameterI(cid, nullptr);
				if (settings)settings->SetBool(DESC_EDITABLE, true);
			}
		}
	}
	else if(indexed_tail_position == 0){
		MAXON_SCOPE
		{
			DescID cid = DescID(TAIL_POSITION);
			if (singleid == nullptr || cid.IsPartOf(*singleid, nullptr))
			{
				BaseContainer* settings = description->GetParameterI(cid, nullptr);
				if (settings)settings->SetBool(DESC_EDITABLE, true);
			}
		}
		MAXON_SCOPE
		{
			DescID cid = DescID(TAIL_INDEX);
			if (singleid == nullptr || cid.IsPartOf(*singleid, nullptr))
			{
				BaseContainer* settings = description->GetParameterI(cid, nullptr);
				if (settings)settings->SetBool(DESC_EDITABLE, false);
			}
		}
	}
	
	flags |= DESCFLAGS_DESC::LOADED;

	return true;
}

Bool mmd::PMX_Bone_Tag::Message(GeListNode* node, Int32 type, void* data)
{
	switch (type)
	{
		case(MSG_DESCRIPTION_CHECKUPDATE):
		{
			BaseTag* tag = (BaseTag*)node;
			BaseObject* obj = tag->GetObject();
			GeData Ge_data;

			tag->GetParameter(DescID(ROTATABLE), Ge_data, DESCFLAGS_GET::NONE);
			Bool Is_rotatable = Ge_data.GetBool();
			if (Is_rotatable == 1) {
				BaseTag* protection_tag = obj->GetTag(Tprotection);
				if (protection_tag == nullptr) {
					protection_tag = obj->MakeTag(Tprotection);
				}
				obj->SetParameter(DescID(ID_BASEOBJECT_USECOLOR), ID_BASEOBJECT_USECOLOR_ALWAYS, DESCFLAGS_SET::NONE);
				obj->SetParameter(DescID(ID_BASEOBJECT_COLOR), Vector(0.56640625, 0.78125, 1), DESCFLAGS_SET::NONE);
				protection_tag->SetParameter(DescID(PROTECTION_R_X), FALSE, DESCFLAGS_SET::NONE);
				protection_tag->SetParameter(DescID(PROTECTION_R_Y), FALSE, DESCFLAGS_SET::NONE);
				protection_tag->SetParameter(DescID(PROTECTION_R_Z), FALSE, DESCFLAGS_SET::NONE);
			}
			else {
				BaseTag* protection_tag = obj->GetTag(Tprotection);
				if (protection_tag == nullptr) {
					protection_tag = obj->MakeTag(Tprotection);
				}
				obj->SetParameter(DescID(ID_BASEOBJECT_USECOLOR), ID_BASEOBJECT_USECOLOR_ALWAYS, DESCFLAGS_SET::NONE);
				obj->SetParameter(DescID(ID_BASEOBJECT_COLOR), Vector(0.56640625, 0.78125, 1), DESCFLAGS_SET::NONE);
				protection_tag->SetParameter(DescID(PROTECTION_R_X), TRUE, DESCFLAGS_SET::NONE);
				protection_tag->SetParameter(DescID(PROTECTION_R_Y), TRUE, DESCFLAGS_SET::NONE);
				protection_tag->SetParameter(DescID(PROTECTION_R_Z), TRUE, DESCFLAGS_SET::NONE);
			}

			tag->GetParameter(DescID(TRANSLATABLE), Ge_data, DESCFLAGS_GET::NONE);
			Bool Is_translatable = Ge_data.GetBool();
			if (Is_translatable == 1) {
				BaseTag* protection_tag = obj->GetTag(Tprotection);
				if (protection_tag == nullptr) {
					protection_tag = obj->MakeTag(Tprotection);
				}
				obj->SetParameter(DescID(ID_BASEOBJECT_USECOLOR), ID_BASEOBJECT_USECOLOR_ALWAYS, DESCFLAGS_SET::NONE);
				obj->SetParameter(DescID(ID_BASEOBJECT_COLOR), Vector(0.703125, 1, 0.546875), DESCFLAGS_SET::NONE);
				protection_tag->SetParameter(DescID(PROTECTION_P_X), FALSE, DESCFLAGS_SET::NONE);
				protection_tag->SetParameter(DescID(PROTECTION_P_Y), FALSE, DESCFLAGS_SET::NONE);
				protection_tag->SetParameter(DescID(PROTECTION_P_Z), FALSE, DESCFLAGS_SET::NONE);
			}
			else {
				BaseTag* protection_tag = obj->GetTag(Tprotection);
				if (protection_tag == nullptr) {
					protection_tag = obj->MakeTag(Tprotection);
				}
				protection_tag->SetParameter(DescID(PROTECTION_P_X), TRUE, DESCFLAGS_SET::NONE);
				protection_tag->SetParameter(DescID(PROTECTION_P_Y), TRUE, DESCFLAGS_SET::NONE);
				protection_tag->SetParameter(DescID(PROTECTION_P_Z), TRUE, DESCFLAGS_SET::NONE);
			}

			tag->GetParameter(DescID(IS_IK), Ge_data, DESCFLAGS_GET::NONE);
			Bool Is_IK = Ge_data.GetBool();
			if (Is_IK == 1) {
				obj->SetParameter(DescID(ID_BASEOBJECT_USECOLOR), ID_BASEOBJECT_USECOLOR_ALWAYS, DESCFLAGS_SET::NONE);
				obj->SetParameter(DescID(ID_BASEOBJECT_COLOR), Vector(0.984375, 0.375, 0), DESCFLAGS_SET::NONE);
			}

			tag->GetParameter(DescID(VISIBLE), Ge_data, DESCFLAGS_GET::NONE);
			Bool Is_visible = Ge_data.GetBool();
			if (Is_visible == 0) {
				obj->SetParameter(DescID(ID_CA_JOINT_OBJECT_JOINT_DISPLAY), ID_CA_JOINT_OBJECT_JOINT_DISPLAY_NONE, DESCFLAGS_SET::NONE);
			}
			else {
				obj->SetParameter(DescID(ID_CA_JOINT_OBJECT_JOINT_DISPLAY), ID_CA_JOINT_OBJECT_JOINT_DISPLAY_AXIS, DESCFLAGS_SET::NONE);
			}
			break;
		}
	}	
	return TRUE;
}