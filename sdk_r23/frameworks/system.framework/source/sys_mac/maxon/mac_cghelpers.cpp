#include "mac_cghelpers.h"

namespace maxon
{

// returns the device profile of the main display
CGColorSpaceRef GetSystemColorSpace()
{
	static CGColorSpaceRef g_displayCS = nullptr;

	if (g_displayCS == nullptr)
	{
		// Test code for SRGB - there's no penalty to use SRGB when the color space transformation is done by the GPU
		g_displayCS = CGColorSpaceCreateWithName(kCGColorSpaceSRGB);
		DebugAssert(g_displayCS != nullptr);
	}

	return g_displayCS;
}

// bitmap buffer is allocated via malloc() - use ReleaseCGBitmapRef() to release the context
static CGContextRef	CreateCGBitmapRef(CGColorSpaceRef colorSpace, Int w, Int h, void* buf, Int componentCnt, Int componentSize, Bool hasAlpha)
{
	Int	pad = 0;
	Int bpp = componentCnt * componentSize;
	if (hasAlpha)
		bpp += componentSize;

	if (bpp == 24)
	{
		pad = 8;
		bpp = 32;																								// use 32 bits for efficiency
	}
	else if (bpp == 96)
	{
		pad = 32;
		bpp = 128;																							// CG uses 128 bits for efficiency, 96 are not supported
	}

	Int	bytesPerLine = (((w * bpp) + 127) & ~127) >> 3;					// using a multiple of 16 bytes (127 == (16 * 8) -1) per line for best performance
	CGBitmapInfo bitmapInfo = kCGImageAlphaNone;											// RGB
	if (hasAlpha)
	{
		if (componentSize == 8)
			bitmapInfo = kCGImageAlphaPremultipliedFirst;		// ARGB for 32 bits (premultiplied)
		else
			bitmapInfo = kCGImageAlphaPremultipliedLast;			// RGBA for 128 bits (premultiplied)
	}
	else if (pad == 8)
	{
		bitmapInfo = kCGImageAlphaNoneSkipFirst;						// xRGB for 32 bits
	}
	else if (pad == 32)
	{
		bitmapInfo = kCGImageAlphaNoneSkipLast;						// RGBx for 128 bits
	}
	if (componentSize == 32)
			bitmapInfo |= kCGBitmapFloatComponents;					// float components don't exist in 10.3 - no need for an extra check here

	if (componentCnt == 3)
	{
		if (componentSize == 8)
			bitmapInfo |= kCGBitmapByteOrder32Little;
		else if (componentSize == 5)
			bitmapInfo |= kCGBitmapByteOrder16Little;
	}

	return CGBitmapContextCreate(buf, w, h, componentSize, bytesPerLine, colorSpace, bitmapInfo);
}

Result<void> CGImageToARGB(CGImageRef image, Int width, Int height, void* buf)
{
	CGColorSpaceRef colorSpace = CGImageGetColorSpace(image);
	CGBitmapInfo alphaInfo = CGImageGetAlphaInfo(image);
	Int componentSize = CGImageGetBitsPerComponent(image);
	Int	componentCnt = 1;
	Bool hasAlpha = false;

	if ((width < 0) && (height < 0))
	{
		width = CGImageGetWidth(image);
		height = CGImageGetHeight(image);
	}
	else
	{
		DebugAssert(CGImageGetWidth(image) == size_t(width));
		DebugAssert(CGImageGetHeight(image) == size_t(height));
	}

	if (colorSpace == nullptr)
		return IllegalArgumentError(MAXON_SOURCE_LOCATION, "Image has no color space"_s);

	componentCnt = CGColorSpaceGetNumberOfComponents(colorSpace);	// number of components for the color channels

	if (componentCnt > 3)																	// in the end we use RGB, so limit to 3 components
		componentCnt = 3;

	if (componentSize > 32)
		componentSize = 32;																		// limit to 32 bit float
	if (componentSize < 8)
		componentSize = 8;																			// 8 bit is the minumum component size for CGBitmap

	if (componentCnt == 1)																	// either gray scale or alpha only?
	{
		return IllegalArgumentError(MAXON_SOURCE_LOCATION);	// TODO: (Anybody) ?
	}
	else
	{
	}

	if ((alphaInfo != kCGImageAlphaNone) && (alphaInfo != kCGImageAlphaNoneSkipLast) && (alphaInfo != kCGImageAlphaNoneSkipFirst))
		hasAlpha = true;

	CGContextRef gc = CreateCGBitmapRef(colorSpace, width, height, buf, componentCnt, componentSize, hasAlpha);
	if (gc)
	{
		CGContextDrawImage(gc, CGRectMake(0, 0, width, height), image);
		CGContextRelease(gc);
	}
	else
	{
		return OutOfMemoryError(MAXON_SOURCE_LOCATION);
	}
	return OK;
}

}
