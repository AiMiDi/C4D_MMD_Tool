/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & CMT contributors.
Author:			Aimidi
Date:			2023/09/12
File:			mmd_manager.hpp
Description:	MMD manager object

**************************************************************************/

#pragma once

#include <c4d.h>
#include <utils/io_util.hpp>
#include "module/core/cmt_marco.h"

class MMDManagerObject : public ObjectData
{
public:
	MMDManagerObject(const MMDManagerObject&) = delete; void operator =(const MMDManagerObject&) = delete;
	MMDManagerObject(MMDManagerObject&& other) noexcept : ObjectData(other) {} MMDManagerObject& operator =(MMDManagerObject&&) noexcept = default;
	typedef ObjectData SUPER;
protected:
	MMDManagerObject() = default;
	~MMDManagerObject() override = default;

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

	SDK2024_InitOverride
	{
		if (!node)
			return false;
		node->ChangeNBit(NBIT::NO_DD, NBITCONTROL::SET);
		CreateLockTag(node);
		CreateDisplayTag(node);
		return SDK2024_SuperInit;
	}

	Bool Read(GeListNode* node, HyperFile* hf, Int32 level) override
	{
		IOReadField(m_display_tag);
		IOReadField(m_protection_tag);
		return SUPER::Read(node, hf, level);
	}

	SDK2024_WriteOverride
	{
		IOWriteField(m_display_tag);
		IOWriteField(m_protection_tag);
		return SUPER::Write(node, hf);
	}
};
