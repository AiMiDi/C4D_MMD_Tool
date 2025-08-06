/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & CMT contributors.
Author:			Aimidi
Date:			2023/12/17
File:			morph_ui_data_util.hpp
Description:	morph UI data util

**************************************************************************/


#ifndef MORPH_UI_DATA_UTIL_H__
#define MORPH_UI_DATA_UTIL_H__

class MorphUIData final
{
	DescID strength_id;
	BaseTag* morph_tag;
public:
	MorphUIData(BaseTag* tag = nullptr, DescID id = {}) : strength_id(std::move(id)), morph_tag(tag)
	{
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
		return morph_tag == tag && strength_id == id;
	}

	void SetStrength(const Float& strength) const
	{
		if (!morph_tag)
			return;
		morph_tag->SetParameter(strength_id, strength, DESCFLAGS_SET::NONE);
	}
};

#endif // !MORPH_UI_DATA_UTIL_H__
