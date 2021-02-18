#include "MMD_PMX_tag.h"

Bool mmd::PMX_Model_Tag::Init(GeListNode* node)
{
	node->SetParameter(DescLevel(ID_BASELIST_NAME), GeLoadString(IDS_PMX_MODEL_TAG), DESCFLAGS_SET::NONE);
	node->SetParameter(DescLevel(PMX_VERSION), 2.1, DESCFLAGS_SET::NONE);
	node->SetParameter(DescLevel(MODEL_NAME_LOCAL), "name"_s, DESCFLAGS_SET::NONE);
	node->SetParameter(DescLevel(MODEL_NAME_UNIVERSAL), "name"_s, DESCFLAGS_SET::NONE);
	node->SetParameter(DescLevel(COMMENTS_LOCAL), "description"_s, DESCFLAGS_SET::NONE);
	node->SetParameter(DescLevel(COMMENTS_UNIVERSAL), "description"_s, DESCFLAGS_SET::NONE);
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