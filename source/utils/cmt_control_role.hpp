#pragma once

#include <string>
#include <string_view>

namespace cmt::controls
{
	enum class Role { None, Leg, Knee, Ankle, Toe, IkParent, IkGoal, ToeIk };
	enum class Side { Center, Left, Right };
	struct NamedRole { Role role = Role::None; Side side = Side::Center; };

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
