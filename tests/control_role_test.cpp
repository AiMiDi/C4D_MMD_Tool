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
		{"全ての親", Role::Root, Side::Center}, {"センター", Role::Center, Side::Center},
        {"グルーブ", Role::Groove, Side::Center}, {"上半身２", Role::Spine, Side::Center},
        {"lower body", Role::Pelvis, Side::Center}, {"首", Role::Neck, Side::Center},
        {"head", Role::Head, Side::Center}, {"head_accessory", Role::None, Side::Center},
        {"上半身補助", Role::None, Side::Center}, {"", Role::None, Side::Center}
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
	struct PurposeCase { const char* name; Purpose purpose; };
	const PurposeCase purposes[] = {
		{"+左ひじ補助", Purpose::Auxiliary}, {"右ひじ補助", Purpose::Auxiliary},
		{"左肘辅助", Purpose::Auxiliary}, {"elbow_helper_L", Purpose::Auxiliary},
		{"Right Elbow AUX", Purpose::Auxiliary}, {"Auxiliary_Arm_L", Purpose::Auxiliary},
		{"左腕捩", Purpose::Twist}, {"右手捻2", Purpose::Twist}, {"手腕扭转", Purpose::Twist},
		{"arm twist_L", Purpose::Twist}, {"wrist_twist2_R", Purpose::Twist},
		{"左肩", Purpose::Shoulder}, {"shoulder_R", Purpose::Shoulder},
		{"右腕", Purpose::Arm}, {"upper_arm_L", Purpose::Arm},
		{"左ひじ", Purpose::Elbow}, {"Left Forearm", Purpose::Elbow},
		{"メガネ", Purpose::Accessory}, {"glasses", Purpose::Accessory},
		{"両目", Purpose::Eyes}, {"eye_L", Purpose::Eye}, {"左目", Purpose::Eye},
		{"右手首", Purpose::Wrist}, {"hand.R", Purpose::Wrist},
		{"右腕D", Purpose::Unknown}, {"left_arm_accessory", Purpose::Unknown},
		{"+左ひじ", Purpose::Unknown}, {"untwisted_R", Purpose::Unknown},
		{"Auxin_L", Purpose::Unknown}, {"helperless_arm_L", Purpose::Unknown},
		{"", Purpose::Unknown}
	};
	for (const auto& item : purposes)
	{
		if (ClassifyPurpose(item.name) != item.purpose)
		{
			std::cerr << "Unexpected presentation purpose: " << item.name << '\n';
			return 1;
		}
	}
	// The near-coincident helper must leave a generous gap from the main elbow
	// even after the existing hierarchy depth adjustment (0.65 .. 1.0).
	if (PurposeRadiusScale(Purpose::Auxiliary) >= PurposeRadiusScale(Purpose::Elbow) * 0.65 * 0.5 ||
		PurposeRadiusScale(Purpose::Twist) >= PurposeRadiusScale(Purpose::Arm) * 0.65 * 0.6 ||
		!IsSecondaryPurpose(Purpose::Auxiliary) || !IsSecondaryPurpose(Purpose::Twist) ||
		IsSecondaryPurpose(Purpose::Elbow))
	{
		std::cerr << "Secondary controls compete with primary joint controls\n";
		return 1;
	}
	return 0;
}
