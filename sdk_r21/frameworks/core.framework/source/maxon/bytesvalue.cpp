#include "maxon/bytesvalue.h"
#include "maxon/dataserialize.h"

namespace maxon
{

String BytesValue::ToString(const FormatStatement* formatStatement) const
{
	Int64 bytes = GetBytes();

	return String::MemorySizeToString(bytes);
}

Result<void> BytesValue::DescribeIO(const DataSerializeInterface& stream)
{
	iferr_scope;

	PrepareDescribe(stream, BytesValue);
	Describe("_value", _value, Int64, DESCRIBEFLAGS::NONE) iferr_return;

	return OK;
}

} // namespace maxon
