#ifndef MAC_UXHELPERS_H__
#define MAC_UXHELPERS_H__

#include "maxon/apibase.h"
#include "maxon/block.h"

namespace maxon
{

Bool GetSysCtlString(const char* what, const Block<Char>& out_str);
Bool GetSysCtlString(const char* what, Int32& out);
Bool GetSysCtlString(const char* what, UInt64& out);

} // namespace maxon


#endif // MAC_UXHELPERS_H__
