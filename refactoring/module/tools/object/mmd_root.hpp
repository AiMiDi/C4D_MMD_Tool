/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & CMT contributors.
Author:			Aimidi
Date:			2023/09/12
File:			mmd_root.hpp
Description:	MMD root object

**************************************************************************/

#ifndef MMD_ROOT_H__
#define MMD_ROOT_H__

class MMDRootObject : public ObjectData
{
	CMT_DISALLOW_COPY_AND_ASSIGN_BODY(MMDRootObject)
	CMT_DEFAULT_MOVE_BODY(MMDRootObject)
	INSTANCEOF(MMDRootObject, ObjectData)
protected:
	MMDRootObject() = default;
	~MMDRootObject() override = default;

	BaseTag* m_display_tag = nullptr;
	BaseTag* m_protection_tag = nullptr;

	virtual void CreateLockTag(GeListNode* node)
	{
		if (!m_protection_tag)
		{
			m_protection_tag = reinterpret_cast<BaseObject*>(node)->MakeTag(Tprotection);
			m_protection_tag->ChangeNBit(NBIT::OHIDE, NBITCONTROL::SET);
			m_protection_tag->ChangeNBit(NBIT::AHIDE_FOR_HOST, NBITCONTROL::SET);
		}
	}

	virtual void CreateDisplayTag(GeListNode* node)
	{
		if (!m_display_tag)
		{
			m_display_tag = reinterpret_cast<BaseObject*>(node)->MakeTag(Tdisplay);
			m_display_tag->SetParameter(ConstDescID(DescLevel(DISPLAYTAG_AFFECT_DISPLAYMODE)), true, DESCFLAGS_SET::NONE);
			m_display_tag->ChangeNBit(NBIT::OHIDE, NBITCONTROL::SET);
			m_display_tag->ChangeNBit(NBIT::AHIDE_FOR_HOST, NBITCONTROL::SET);
		}
	}

	Bool Init(GeListNode* node SDK2024_InitParaName) override
	{
		if (!node)
			return false;
		node->ChangeNBit(NBIT::NO_DD, NBITCONTROL::SET);
		CreateLockTag(node);
		CreateDisplayTag(node);
		return SUPER::Init(node SDK2024_InitPara);
	}

	Bool Read(GeListNode* node, HyperFile* hf, Int32 level) override
	{
		AutoAlloc<BaseLink> temp_link;
		if (!temp_link)
			return false;
		if (!temp_link->Read(hf))
			return false;
		m_display_tag = reinterpret_cast<BaseTag*>(temp_link->ForceGetLink());
		if (!temp_link->Read(hf))
			return false;
		m_protection_tag = reinterpret_cast<BaseTag*>(temp_link->ForceGetLink());
		return SUPER::Read(node, hf, level);
	}

	Bool Write(SDK2024_Const GeListNode* node, HyperFile* hf) SDK2024_Const override
	{
		AutoAlloc<BaseLink> temp_link;
		if (!temp_link->Write(hf))
			return false;
		temp_link->SetLink(m_display_tag);
		if (!temp_link->Write(hf))
			return false;
		temp_link->SetLink(m_protection_tag);
		if (!temp_link->Write(hf))
			return false;
		return SUPER::Write(node, hf);
	}
};

#endif
