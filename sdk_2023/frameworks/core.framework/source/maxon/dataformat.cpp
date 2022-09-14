#include "maxon/dataformat_base.h"
#include "maxon/url.h"

namespace maxon
{


Result<void> DataFormatBaseReaderInterface::ReadData(void* data, Int dataSize, Int elementCount)
{
	iferr (Int readElements = ReadDataEOS(data, dataSize, elementCount))
		return err;
	if (readElements != elementCount)
		return IoError(MAXON_SOURCE_LOCATION, Url(), FormatString("Not enough data @ read, but @ expected.", readElements, elementCount));
	return OK;
}


}
