#include "maxon/gfx_image_pixelformat_template.h"

namespace maxon
{


const Pix16f PixelDepthInfo<Pix16f>::PIXELTOLERANCE_ONE = 1.0f / 255.0f, PixelDepthInfo<Pix16f>::PIXELTOLERANCE_ZERO = 0.0f;
const Pix32f PixelDepthInfo<Pix32f>::PIXELTOLERANCE_ONE = 1.0f / 255.0f, PixelDepthInfo<Pix32f>::PIXELTOLERANCE_ZERO = 0.0f;
const Pix64f PixelDepthInfo<Pix64f>::PIXELTOLERANCE_ONE = 1.0 / 255.0, PixelDepthInfo<Pix64f>::PIXELTOLERANCE_ZERO = 0.0;

const Pix16f PixelDepthInfo<Pix16f>::DEFAULTALPHA_VALUE = 1.0f;
const Pix32f PixelDepthInfo<Pix32f>::DEFAULTALPHA_VALUE = 1.0f;
const Pix64f PixelDepthInfo<Pix64f>::DEFAULTALPHA_VALUE = 1.0;

const Pix16f PixelDepthInfo<Pix16f>::MAXPIXEL_VALUE = 1.0f;
const Pix32f PixelDepthInfo<Pix32f>::MAXPIXEL_VALUE = 1.0f;
const Pix64f PixelDepthInfo<Pix64f>::MAXPIXEL_VALUE = 1.0;

const Pix16f PixelDepthInfo<Pix16f>::ZEROPIXEL_VALUE = 0.0f;
const Pix32f PixelDepthInfo<Pix32f>::ZEROPIXEL_VALUE = 0.0f;
const Pix64f PixelDepthInfo<Pix64f>::ZEROPIXEL_VALUE = 0.0;

String BITS::ToString(const FormatStatement* formatStatement) const
{
	return FormatString("@", _bits);
}

Result<void> BITS::DescribeIO(const DataSerializeInterface& stream)
{
	iferr_scope;

	PrepareDescribe(stream, BITS);
	Describe("_bits", _bits, Int, DESCRIBEFLAGS::NONE) iferr_return;

	return OK;
}

}
