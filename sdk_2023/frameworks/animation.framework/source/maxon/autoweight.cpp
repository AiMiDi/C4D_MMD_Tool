#include "maxon/autoweight.h"

namespace maxon
{


//----------------------------------------------------------------------------------------
/// Call all the step components of the autoweight algo
/// @param[out] weights												The resulting autoweight array.
/// @param[in] oldWeights											The previous weight inside the weight tag.
/// @param[in] autoWeightPointJointSelections	Structure with usefull points and bones data.
/// @param[in] bones													The bones object.
/// @param[in] doc														The base document.
/// @param[in] op															The polygon object.
/// @return																		Error code if fail else OK.
//----------------------------------------------------------------------------------------
Result<void> AutoWeightInterface::RunAutoWeight(BaseArray<BaseArray<Float>>& weights, BaseArray<BaseArray<Float>>& oldWeights, AutoWeightPointJointSelections& autoWeightPointJointSelections, const BaseArray<Bone>& bones, BaseDocument* doc, PolygonObject* op)
{
	iferr_scope;
	CalculateWeights(weights, doc, op, bones, autoWeightPointJointSelections) iferr_return;
	SmoothWeights(weights, op, oldWeights, autoWeightPointJointSelections) iferr_return;
	NormalizeWeights(weights, oldWeights, autoWeightPointJointSelections) iferr_return;

	return OK;
}

} // namespace maxon
