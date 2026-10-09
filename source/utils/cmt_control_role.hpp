#pragma once

#include <string>
#include <string_view>

namespace cmt::controls
{
	enum class Role { None, Leg, Knee, Ankle, Toe, IkParent, IkGoal, ToeIk, Root, Center, Groove, Waist, Spine, Pelvis, Neck, Head };
	enum class Side { Center, Left, Right };
	struct NamedRole { Role role = Role::None; Side side = Side::Center; };

	// Presentation purpose is independent of eligibility: recognizing a helper
	// must never create a new control or change the bone's transform semantics.
	enum class Purpose { Unknown, Shoulder, Arm, Elbow, Wrist, Eye, Eyes, Auxiliary, Twist, Accessory };

	inline bool IsAsciiLetter(unsigned char ch)
	{
		return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
	}

	inline bool ContainsWord(std::string_view name, std::string_view word)
	{
		for (auto start = name.find(word); start != std::string_view::npos; start = name.find(word, start + 1))
		{
			const auto end = start + word.size();
			if ((start == 0 || !IsAsciiLetter(name[start - 1])) &&
				(end == name.size() || !IsAsciiLetter(name[end])))
				return true;
		}
		return false;
	}

	inline Purpose ClassifyPurpose(std::string_view name)
	{
		std::string lower(name);
		for (char& ch : lower)
			if (ch >= 'A' && ch <= 'Z') ch += 'a' - 'A';
		if (lower.find("補助") != std::string::npos || lower.find("辅助") != std::string::npos ||
			ContainsWord(lower, "helper") || ContainsWord(lower, "aux") || ContainsWord(lower, "auxiliary"))
			return Purpose::Auxiliary;
		if (lower.find("捩") != std::string::npos || lower.find("捻") != std::string::npos ||
			lower.find("扭转") != std::string::npos || ContainsWord(lower, "twist"))
			return Purpose::Twist;

		std::string key;
		for (const char ch : lower)
			if (ch != ' ' && ch != '_' && ch != '-' && ch != '.' && ch != '\0') key += ch;
		if (key == "メガネ" || key == "眼鏡" || key == "眼镜" || key == "glasses") return Purpose::Accessory;
		if (key == "両目" || key == "eyes") return Purpose::Eyes;
		if (key.compare(0, 3, "左") == 0 || key.compare(0, 3, "右") == 0) key.erase(0, 3);
		else if (key.compare(0, 4, "left") == 0) key.erase(0, 4);
		else if (key.compare(0, 5, "right") == 0) key.erase(0, 5);
		else if (!key.empty() && (key.back() == 'l' || key.back() == 'r')) key.pop_back();
		else return Purpose::Unknown;

		if (key == "目" || key == "eye") return Purpose::Eye;
		if (key == "肩" || key == "shoulder" || key == "clavicle") return Purpose::Shoulder;
		if (key == "腕" || key == "arm" || key == "upperarm") return Purpose::Arm;
		if (key == "ひじ" || key == "肘" || key == "elbow" || key == "forearm" || key == "lowerarm") return Purpose::Elbow;
		if (key == "手首" || key == "wrist" || key == "hand") return Purpose::Wrist;
		return Purpose::Unknown;
	}

	inline bool IsSecondaryPurpose(Purpose purpose)
	{
		return purpose == Purpose::Auxiliary || purpose == Purpose::Twist || purpose == Purpose::Accessory;
	}

	inline double PurposeRadiusScale(Purpose purpose)
	{
		switch (purpose)
		{
		case Purpose::Shoulder: return 0.90;
		case Purpose::Arm: return 0.85;
		case Purpose::Elbow: return 0.70;
		case Purpose::Wrist: return 0.60;
		case Purpose::Eye: return 0.25;
		case Purpose::Eyes: return 0.65;
		case Purpose::Auxiliary: return 0.22;
		case Purpose::Accessory: return 0.35;
		case Purpose::Twist: return 0.32;
		default: return 1.0;
		}
	}

	// Match complete anatomical names, never substrings: e.g. leg deformation
	// duplicates (D), clothing and accessories must not acquire extra controls.
	inline NamedRole ClassifyName(std::string_view name)
	{
		std::string key;
		for (const unsigned char ch : name)
		{
			if (ch == ' ' || ch == '_' || ch == '-' || ch == '.' || ch == '\0') continue;
			key += static_cast<char>(ch >= 'A' && ch <= 'Z' ? ch + ('a' - 'A') : ch);
		}
		// Central MMD controls use exact names too; decorations and numbered
		// helper chains must not become animation controls accidentally.
		if (key == "全ての親" || key == "master" || key == "root") return { Role::Root, Side::Center };
		if (key == "センター" || key == "center") return { Role::Center, Side::Center };
		if (key == "グルーブ" || key == "groove") return { Role::Groove, Side::Center };
		if (key == "腰" || key == "waist") return { Role::Waist, Side::Center };
		if (key == "上半身" || key == "上半身2" || key == "上半身２" ||
			key == "upperbody" || key == "upperbody2" || key == "spine" || key == "chest")
			return { Role::Spine, Side::Center };
		if (key == "下半身" || key == "lowerbody" || key == "pelvis") return { Role::Pelvis, Side::Center };
		if (key == "首" || key == "neck") return { Role::Neck, Side::Center };
		if (key == "頭" || key == "head") return { Role::Head, Side::Center };
		Side side = Side::Center;
		if (key.compare(0, 3, "左") == 0) { side = Side::Left; key.erase(0, 3); }
		else if (key.compare(0, 3, "右") == 0) { side = Side::Right; key.erase(0, 3); }
		else if (key.compare(0, 4, "left") == 0) { side = Side::Left; key.erase(0, 4); }
		else if (key.compare(0, 5, "right") == 0) { side = Side::Right; key.erase(0, 5); }
		else if (!key.empty() && (key.back() == 'l' || key.back() == 'r'))
		{
			side = key.back() == 'l' ? Side::Left : Side::Right;
			key.pop_back();
		}
		else return {};

		Role role = Role::None;
		if (key == "足" || key == "leg" || key == "upperleg" || key == "thigh") role = Role::Leg;
		else if (key == "ひざ" || key == "膝" || key == "knee" || key == "lowerleg" || key == "shin") role = Role::Knee;
		else if (key == "足首" || key == "ankle" || key == "foot") role = Role::Ankle;
		else if (key == "つま先" || key == "足先ex" || key == "toe" || key == "toes" || key == "toe2") role = Role::Toe;
		else if (key == "足ik親" || key == "足ＩＫ親" || key == "legikp" || key == "legikparent" || key == "footikparent") role = Role::IkParent;
		else if (key == "足ik" || key == "足ＩＫ" || key == "legik" || key == "footik") role = Role::IkGoal;
		else if (key == "つま先ik" || key == "つま先ＩＫ" || key == "toeik") role = Role::ToeIk;
		return role == Role::None ? NamedRole{} : NamedRole{role, side};
	}
}
