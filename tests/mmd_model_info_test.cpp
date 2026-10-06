#include "utils/mmd_model_info_animation.h"

#include <cstdlib>
#include <iostream>
#include <limits>
#include <vector>

namespace
{
	void Require(const bool condition, const char* message)
	{
		if (!condition)
		{
			std::cerr << message << '\n';
			std::exit(EXIT_FAILURE);
		}
	}
}

int main()
{
	using mmd_model_info::AnimationSlot;
	using mmd_model_info::Evaluate;
	using mmd_model_info::EvaluateIK;
	using mmd_model_info::StepKeys;

	const StepKeys empty;
	Require(Evaluate(empty, 0, true), "empty visibility must respect enabled fallback");
	Require(!Evaluate(empty, 0, false), "empty visibility must respect disabled fallback");
	const StepKeys show{ {10, false}, {20, true}, {30, false} };
	Require(Evaluate(show, -1, true), "negative seek before first visibility key must use fallback");
	Require(Evaluate(show, 9, true), "visibility must not clamp to later first key");
	Require(!Evaluate(show, 10, true), "first hidden key takes effect exactly at its frame");
	Require(!Evaluate(show, 19, true), "visibility stays hidden between step keys");
	Require(Evaluate(show, 20, false), "shown key overrides disabled fallback at its frame");
	Require(!Evaluate(show, std::numeric_limits<std::int32_t>::max(), true), "visibility must hold last key after clip end");

	std::vector<AnimationSlot> slots(2);
	slots[0].visibility = show;
	slots[0].ik_defaults["right_leg"] = true;
	slots[0].ik_defaults["left_leg"] = false;
	slots[0].ik_channels["right_leg"] = { {10, false}, {20, true} };
	slots[0].ik_channels["unknown_source_ik"] = { {5, false}, {25, true} };
	slots[1].ik_defaults["right_leg"] = false;
	slots[1].ik_channels["right_leg"] = { {10, true}, {20, false} };

	Require(EvaluateIK(slots[0], "right_leg", 0, false), "named slot default must override global default before first key");
	Require(!EvaluateIK(slots[0], "left_leg", 100, true), "unkeyed named default must hold for whole clip");
	Require(!EvaluateIK(slots[0], "right_leg", 10, true), "keyed IK disable must take effect at exact frame");
	Require(EvaluateIK(slots[0], "right_leg", 20, false), "keyed IK reenable must override fallback");
	Require(EvaluateIK(slots[1], "right_leg", 10, false), "second slot must maintain its independent opposite IK keys");
	Require(!EvaluateIK(slots[1], "right_leg", 20, true), "same IK name must not share first slot terminal state");
	Require(Evaluate(slots[1].visibility, 10, true), "new slot must not inherit first slot hidden visibility");
	Require(!EvaluateIK(slots[0], "missing_solver", 15, false), "missing named channel must use caller fallback");
	Require(EvaluateIK(slots[0], "missing_solver", 15, true), "missing channel enabled fallback must remain enabled");
	Require(!EvaluateIK(slots[0], "unknown_source_ik", 15, true), "unknown source IK channel must remain available by name");

	const AnimationSlot saved = slots[0];
	slots[0].ik_channels["right_leg"][10] = true;
	slots[0].visibility[10] = true;
	Require(!EvaluateIK(saved, "right_leg", 10, true), "copy used for persistence/clone snapshots must not share mutable IK storage");
	Require(!Evaluate(saved.visibility, 10, true), "copied visibility must not share mutable key storage");
	Require(saved.ik_channels.count("unknown_source_ik") == 1, "unknown names must survive copy even without runtime solver");
	Require(EvaluateIK(saved, "unknown_source_ik", 25, false), "unknown channel copied terminal enable must be intact");

	slots.erase(slots.begin());
	Require(slots.size() == 1 && !EvaluateIK(slots[0], "right_leg", 20, true), "deleting earlier slot must preserve remaining named channels");
	Require(Evaluate(slots[0].visibility, 10, true), "deleting earlier slot must not transfer its hidden visibility");
	std::cout << "model info step channels and slot isolation regression passed\n";
	return EXIT_SUCCESS;
}
