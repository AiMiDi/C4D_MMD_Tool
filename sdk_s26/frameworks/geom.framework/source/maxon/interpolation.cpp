#include "interpolation.h"

namespace maxon
{

MAXON_FUNCTION void InterpolateTypeInterface::InterpolateBilinear(const DataTypePtr dataType, void* data1, const void* data2, const void* data3, const void* data4, Float blendS, Float blendT) const
{
	if (MAXON_UNLIKELY(!dataType))
		return;
	
	InterpolateLinear(data1, data2, blendS);
	
	ifnoerr (void* value = dataType->Create())
	{
		MemCopy(value, data4, dataType->GetSize());
		
		InterpolateLinear(value, data3, blendS);
		InterpolateLinear(data1, value, blendT);
		
		dataType->Destruct(value);
		DeleteMem(value);
	}
}

} // namespace maxon
