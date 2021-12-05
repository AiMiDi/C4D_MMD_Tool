#include "ge_math.h"

Bool CompareFloatTolerant(Float32 a, Float32 b)
{
	Int32* va = (Int32*) &a;
	Int32* vb = (Int32*) &b;

	// UInt32 is necessary because -x-x is 0x80000000 where abs(0x80000000 is illegal)
	return UInt32(Abs(*va - *vb)) <= 7;
}

Bool CompareFloatTolerant(Float64 a, Float64 b)
{
	Int64* va = (Int64*) &a;
	Int64* vb = (Int64*) &b;

	// UInt32 is necessary because -x-x is 0x80000000 where abs(0x80000000 is illegal)
	return UInt64(Abs(*va - *vb)) <= 7;
}
