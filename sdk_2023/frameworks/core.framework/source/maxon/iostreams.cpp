#include "maxon/iostreams.h"
#include "maxon/url.h"

namespace maxon
{

Result<void> InputStreamInterface::Read(const Block<Byte>& data)
{
	iferr (auto read = ReadEOS(data))
		return err;
	if (read != data.GetCount())
		return IoError(MAXON_SOURCE_LOCATION, Url(), FormatString("The requested number of bytes could not be read (@ of @).", read, data.GetCount()));
	return OK;
}

}
