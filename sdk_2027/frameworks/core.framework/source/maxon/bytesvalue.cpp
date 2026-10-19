#include "maxon/bytesvalue.h"
#include "maxon/dataserialize.h"
#include "maxon/stringconversion.h"

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

void ScanParameter(BytesValue& res, const Block<const Utf32Char>& str, Int& processed, const String& formatStatement, Bool& error)
{
	Float64 result = 0.0;
	error = false;
	
	iferr (result = StringConversion::StringToFloat(str, processed))
		error = true;
	
	if (!error)
	{
		if (str.GetCount() == processed)
		{
			res = Bytes(Int64(result));
		}
		else if (str.GetCount() > processed)
		{
			if (str[processed] == 'K')
				res = Kibibytes(result);
			else if (str[processed] == 'M')
				res = Mebibytes(result);
			else if (str[processed] == 'G')
				res = Gibibytes(result);
			else if (str[processed] == 'T')
				res = Tebibytes(result);
			else
				error = true;
		}
	}
}

} // namespace maxon
