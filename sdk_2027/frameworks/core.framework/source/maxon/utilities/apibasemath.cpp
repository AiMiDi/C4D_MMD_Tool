#include "maxon/apibase.h"

namespace maxon
{

#ifdef MAXON_TARGET_WINDOWS
Bool g_dummyMathGlobal; // avoids that the MSVC linker shows a warning
#endif

} // namespace maxon
