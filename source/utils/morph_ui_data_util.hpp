/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & CMT contributors.
Author:			Aimidi
Date:			2023/12/17
File:			morph_ui_data_util.hpp
Description:	morph UI data util

**************************************************************************/


#pragma once

#include <c4d.h>
#include <utils/io_util.hpp>
#include "module/core/cmt_marco.h"

class MorphUIData final
{
	DescID strength_id;
	// Undo may replace a mesh and its tags without replacing this cache owner.
	// A BaseLink invalidates safely; a cached BaseTag* can become freed memory.
	maxon::StrongRef<AutoAlloc<BaseLink>> morph_tag;
public:
	MorphUIData(BaseTag* tag = nullptr, DescID id = {}) : strength_id(std::move(id))
	{
		iferr (morph_tag = maxon::StrongRef<AutoAlloc<BaseLink>>::Create()) { return; }
		if (morph_tag && *morph_tag) (*morph_tag)->SetLink(tag);
	}

	~MorphUIData() = default;
	MorphUIData(const MorphUIData& other) = default;
	MorphUIData& operator=(const MorphUIData& other) = default;
	MorphUIData(MorphUIData&& other) noexcept = default;
	MorphUIData& operator=(MorphUIData&& other) noexcept = default;

	Bool Write(HyperFile* hf) SDK2024_Const
	{
		IOWriteField(morph_tag);
		IOWriteField(strength_id);
		return true;
	}

	Bool Read(HyperFile* hf)
	{
		IOReadField(morph_tag);
		IOReadField(strength_id);
		return true;
	}
	[[nodiscard]] Bool Compare(BaseTag* const tag, const DescID& id) const
	{
		return ResolveTag() == tag && strength_id == id;
	}
	[[nodiscard]] BaseTag* ResolveTag() const
	{
		return morph_tag && *morph_tag ? static_cast<BaseTag*>((*morph_tag)->ForceGetLink()) : nullptr;
	}

	void SetStrength(const Float& strength) const
	{
		BaseTag* tag = ResolveTag();
		if (!tag)
			return;
		tag->SetParameter(strength_id, strength, DESCFLAGS_SET::NONE);
	}

	[[nodiscard]] Float GetStrength() const
	{
		BaseTag* tag = ResolveTag();
		if (!tag)
			return 0.0;
		GeData ge_data;
		if (!tag->GetParameter(strength_id, ge_data, DESCFLAGS_GET::NONE))
			return 0.0;
		return ge_data.GetFloat();
	}
};

