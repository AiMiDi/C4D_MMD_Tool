#include "maxon/datadescription_data.h"

namespace maxon
{

ConstDataPtr GetDefaultValueKey()
{
	return ConstDataPtr(DESCRIPTION::DATA::BASE::DEFAULTVALUE.Get());
}

}
