#ifndef FILTER_IMAGE_H__
#define FILTER_IMAGE_H__

#include "maxon/vector.h"
#include "maxon/vector4d.h"
#include "maxon/url.h"

namespace maxon
{
namespace FilterImageDescriptionParameters
{
	MAXON_ATTRIBUTE(UInt32, WIDTH, "net.maxon.renderfilter.filterimage.description.width");
	MAXON_ATTRIBUTE(UInt32, HEIGHT, "net.maxon.renderfilter.filterimage.description.height");
} // FilterImageDescriptionParameters
	
//----------------------------------------------------------------------------------------
/// FilterImageInterface contains the image.
//----------------------------------------------------------------------------------------
class FilterImageInterface : MAXON_INTERFACE_BASES(ObjectInterface)
{
	MAXON_INTERFACE(FilterImageInterface, MAXON_REFERENCE_NORMAL, "net.maxon.renderfilter.filterimage.interface");
public:	
	//----------------------------------------------------------------------------------------
	/// Writes the contents out into a buffer
	/// @param[out] buffer				The output buffer
	//----------------------------------------------------------------------------------------
	MAXON_METHOD	Result<void> WriteToBuffer(BaseArray<Vector4d32>& buffer);
	
	//----------------------------------------------------------------------------------------
	/// Copies contents from CPU memory block
	/// @param[in] data					Data to read.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD	Result<void> ReadFromCPUMemory(const BaseArray<Vector4d32>& data);
	
	//----------------------------------------------------------------------------------------
	/// Writes the contents out into a file
	/// @param[in] url 						The url to write to
	//----------------------------------------------------------------------------------------
	MAXON_METHOD	Result<void> WriteToFile(const Url& url);
};

#include "filter_image1.hxx"
MAXON_REGISTRY(Class<FilterImageRef>, FilterImageClasses, "net.maxon.renderfilter.registry.filterimageclasses");
	
namespace FilterImageClasses
{
	MAXON_DECLARATION(FilterImageClasses::EntryType, OIDNFILTERIMAGE, "net.maxon.renderfilter.filterimageclass.oidnfilterimage");
}
#include "filter_image2.hxx"
}

MAXON_DEPENDENCY_WEAK("maxon/filter_image.h"); // This is an optional component

#endif // FILTER_IMAGE_H__
