#ifndef MAC_CGHELPERS_H__
#define MAC_CGHELPERS_H__

#include "maxon/error.h"

#include <CoreGraphics/CoreGraphics.h>

namespace maxon
{
CGColorSpaceRef GetSystemColorSpace();
Result<void> CGImageToARGB(CGImageRef image, Int width, Int height, void* buf);
}

#endif // MAC_CGHELPERS_H__
