#include "maxon/general_math.h"

namespace maxon
{
// the function doesn't catch variance around 0 (positive) and a small negative number ie 0 and -1e-10)
// It's still very useful for big number comparison or numbers with the same sign
Bool CompareFloatTolerant(Float32 a, Float32 b)
{
	Int32* va = (Int32*) &a;
	Int32* vb = (Int32*) &b;

	// UInt32 is necessary because -x-x is 0x80000000 where abs(0x80000000 is illegal)
	UInt32 diff = UInt32(Abs(*va - *vb));
	return (diff <= 7);
}

Bool CompareFloatTolerant(Float64 a, Float64 b)
{
	Int64* va = (Int64*) &a;
	Int64* vb = (Int64*) &b;

	// UInt32 is necessary because -x-x is 0x80000000 where abs(0x80000000 is illegal)
	UInt64 diff = UInt64(Abs(*va - *vb));
	return (diff <= 7);
}

} // namespace maxon
