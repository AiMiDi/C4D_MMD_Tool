#include "maxon/apibase.h"

namespace maxon
{

const Int64 LIMIT<Int64>::MIN;
const Int64 LIMIT<Int64>::MAX;

const UInt64 LIMIT<UInt64>::MIN;
const UInt64 LIMIT<UInt64>::MAX;

const Int32 LIMIT<Int32>::MIN;
const Int32 LIMIT<Int32>::MAX;

const UInt32 LIMIT<UInt32>::MIN;
const UInt32 LIMIT<UInt32>::MAX;

const Int16 LIMIT<Int16>::MIN;
const Int16 LIMIT<Int16>::MAX;

const UInt16 LIMIT<UInt16>::MIN;
const UInt16 LIMIT<UInt16>::MAX;

const Char LIMIT<Char>::MIN;
const Char LIMIT<Char>::MAX;

const UChar LIMIT<UChar>::MIN;
const UChar LIMIT<UChar>::MAX;

#ifdef MAXON_TARGET_WINDOWS
Bool g_dummyMathGlobal; // avoids that the MSVC linker shows a warning
#endif

} // namespace maxon
