#include "maxon/mac_uxhelpers.h"
#include <sys/sysctl.h>

namespace maxon
{

Bool GetSysCtlString(const char* what, const Block<Char>& out_str)
{
	size_t length = out_str.GetCount() - 1;
	int error	 = sysctlbyname(what, out_str.GetFirst(), &length, NULL, 0);
	if ((error == 0) && (length > 0))
	{
		if (length >= (size_t) out_str.GetCount())
			length = (size_t) out_str.GetCount() - 1;
	}
	else
	{
		length = 0;
	}
	out_str[length] = 0;

	return error == 0;
}

Bool GetSysCtlString(const char* what, Int32& out)
{
	size_t len = sizeof(out);
	int error	 = sysctlbyname(what, &out, &len, NULL, 0);

	return error == 0;
}

Bool GetSysCtlString(const char* what, UInt64& out)
{
	size_t len = sizeof(out);
	int error	 = sysctlbyname(what, &out, &len, NULL, 0);

	return error == 0;
}


}
