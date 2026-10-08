#include "utils/cmt_control_role.hpp"
#include <iostream>

int main()
{
	using namespace cmt::controls;
	struct Case { const char* name; Role role; Side side; };
	const Case cases[] = {
		{"左足", Role::Leg, Side::Left}, {"右ひざ", Role::Knee, Side::Right},
		{"左足首", Role::Ankle, Side::Left}, {"右足先EX", Role::Toe, Side::Right},
		{"左足IK親", Role::IkParent, Side::Left}, {"右足ＩＫ", Role::IkGoal, Side::Right},
		{"左つま先ＩＫ", Role::ToeIk, Side::Left}, {"LEG IKP_L", Role::IkParent, Side::Left},
		{"Right Knee", Role::Knee, Side::Right}, {"foot.R", Role::Ankle, Side::Right},
		{"toe2_L", Role::Toe, Side::Left}, {"upper_leg_L", Role::Leg, Side::Left},
		{"左足D", Role::None, Side::Left}, {"右足首D", Role::None, Side::Right},
		{"left_leg_accessory", Role::None, Side::Left}, {"hair", Role::None, Side::Right},
		{"", Role::None, Side::Center}
	};
	for (const auto& item : cases)
	{
		const auto actual = ClassifyName(item.name);
		if (actual.role != item.role || (item.role != Role::None && actual.side != item.side))
		{
			std::cerr << "Unexpected control role: " << item.name << '\n';
			return 1;
		}
	}
	return 0;
}
