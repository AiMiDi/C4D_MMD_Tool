#include "maxon/splinemapper.h"
#include "maxon/dataserialize.h"

namespace maxon
{

Result<void> SplineMapperKnot::DescribeIO(const DataSerializeInterface& stream)
{
	iferr_scope;

	PrepareDescribe(stream, SplineMapperKnot);

	Describe("position", position, Vector2d, DESCRIBEFLAGS::NONE) iferr_return;
	Describe("interpolation", interpolation, SPLINEMAPPER_KNOT_INTERPOLATION_TYPE, DESCRIBEFLAGS::NONE) iferr_return;
	Describe("tangentLeft", tangentLeft, Vector2d, DESCRIBEFLAGS::NONE) iferr_return;
	Describe("tangentRight", tangentRight, Vector2d, DESCRIBEFLAGS::NONE) iferr_return;
	Describe("flags", flags, SPLINEMAPPER_KNOT_FLAGS, DESCRIBEFLAGS::NONE) iferr_return;

	return OK;
}

}