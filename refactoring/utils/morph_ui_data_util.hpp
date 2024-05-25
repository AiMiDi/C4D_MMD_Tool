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
	maxon::StrongRef<AutoAlloc<BaseLink>> morph_tag_link;
public:
	MorphUIData(SDK2024_Const BaseTag* bone_tag = nullptr, DescID strength_id = {}) : strength_id(std::move(strength_id)), morph_tag_link(maxon::StrongRef<AutoAlloc<BaseLink>>::Create()iferr_ignore())
	{
		(*morph_tag_link)->SetLink(bone_tag);
	}

	~MorphUIData() = default;
	MorphUIData(const MorphUIData& other) = default;
	MorphUIData& operator=(const MorphUIData& other) = default;
	MorphUIData(MorphUIData&& other) noexcept = default;
	MorphUIData& operator=(MorphUIData&& other) noexcept = default;

	Bool Write(HyperFile* hf) SDK2024_Const
	{
		if (!(*morph_tag_link)->Write(hf))
			return false;
		if (!strength_id.Write(hf))
			return false;
		return true;
	}

	Bool Read(HyperFile* hf)
	{
		if (!(*morph_tag_link)->Read(hf))
			return false;
		if (!strength_id.Read(hf))
			return false;
		return true;
	}

	[[nodiscard]] Bool Compare(const MorphUIData& other) const
	{
		return (*morph_tag_link)->ForceGetLink() == (*other.morph_tag_link)->ForceGetLink() && strength_id == other.strength_id;
	}

	[[nodiscard]] BaseTag* GetMorphTag() const
	{
		return reinterpret_cast<BaseTag*>((*morph_tag_link)->ForceGetLink());
	}

	[[nodiscard]] const DescID& GetStrengthID() const
	{
		return strength_id;
	}
};

#endif // !MORPH_UI_DATA_UTIL_H__
