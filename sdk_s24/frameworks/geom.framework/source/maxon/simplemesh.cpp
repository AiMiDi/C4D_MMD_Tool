#include "maxon/simplemesh.h"
#include "maxon/dataserialize.h"

namespace maxon
{

template <typename T> Result<void> Poly<T>::DescribeIO(const DataSerializeInterface& stream)
{
	iferr_scope;

	PrepareDescribe(stream, Poly<T>);

	Describe("a", a, T, DESCRIBEFLAGS::NONE) iferr_return;
	Describe("b", b, T, DESCRIBEFLAGS::NONE) iferr_return;
	Describe("c", c, T, DESCRIBEFLAGS::NONE) iferr_return;
	Describe("d", d, T, DESCRIBEFLAGS::NONE) iferr_return;

	return OK;
}

template Result<void> SimplePolygon::DescribeIO(const DataSerializeInterface &stream);
template Result<void> UVWPolygon::DescribeIO(const DataSerializeInterface &stream);

Int SimpleMeshObject::GetMemorySize() const
{
	return _vertex.GetMemorySize() + _polygon.GetMemorySize() + _uvw.GetMemorySize();
}

} // namespace maxon
