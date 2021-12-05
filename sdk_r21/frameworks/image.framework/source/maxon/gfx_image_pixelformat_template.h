#ifndef GFX_IMAGE_PIXELFORMAT_TEMPLATE_H__
#define GFX_IMAGE_PIXELFORMAT_TEMPLATE_H__

#include "maxon/apibase.h"
#include "maxon/block.h"
#include "maxon/gfx_image_imagechannels.h"
#include "maxon/gfx_image_pixelformat.h"
#include "maxon/gfx_image_pixelhandler.h"
#include "maxon/job.h"
#include "maxon/spinlock.h"

#ifdef MAXON_TARGET_CPU_INTEL
#include "emmintrin.h"
#endif

namespace maxon
{

//----------------------------------------------------------------------------------------
/// Template class offers properties of a pixel depth. The values
/// All Pixel Depths need to define the full set of type aliases and static vars.
//----------------------------------------------------------------------------------------
template <typename PIXELDEPTH> struct PixelDepthInfo
{
	static const PIXELDEPTH DEFAULTALPHA_VALUE = 255;	///< returns the default alpha value for 100% transparency.
	static const PIXELDEPTH MAXPIXEL_VALUE = 0;				///< returns the 100% value of the component.
	static const PIXELDEPTH ZEROPIXEL_VALUE = 0;			///< returns the 0% value of the component.
	static const PIXELDEPTH PIXELTOLERANCE_ZERO = 0;	///< returns the value that represents a zero tolerance of this type
	static const PIXELDEPTH PIXELTOLERANCE_ONE = 1;		///< returns the value that represents a 8 bit digit tolerance of this pixel type.
	using PIXELTOLERANCE_ABSTYPE = Int32;							///< returns the data type if using the absolute type.
	using SUM_TYPE = PIXELDEPTH;											///< returns the data type if pixel values will be added.
};

template <> struct PixelDepthInfo<Pix8u>
{
	using PIXELDEPTH = Pix8u;
	static const PIXELDEPTH DEFAULTALPHA_VALUE = LIMIT<PIXELDEPTH>::MAX;
	static const PIXELDEPTH MAXPIXEL_VALUE = LIMIT<PIXELDEPTH>::MAX;
	static const PIXELDEPTH ZEROPIXEL_VALUE = LIMIT<PIXELDEPTH>::MIN;
	static const PIXELDEPTH PIXELTOLERANCE_ONE = 1, PIXELTOLERANCE_ZERO = 0;
	using PIXELTOLERANCE_ABSTYPE = Int32;
	using SUM_TYPE = UInt64;
};

template <> struct PixelDepthInfo<Pix8s>
{
	using PIXELDEPTH = Pix8s;
	static const PIXELDEPTH DEFAULTALPHA_VALUE = LIMIT<PIXELDEPTH>::MAX;
	static const PIXELDEPTH MAXPIXEL_VALUE = LIMIT<PIXELDEPTH>::MAX;
	static const PIXELDEPTH ZEROPIXEL_VALUE = LIMIT<PIXELDEPTH>::MIN;
	static const PIXELDEPTH PIXELTOLERANCE_ONE = 1, PIXELTOLERANCE_ZERO = 0;
	using PIXELTOLERANCE_ABSTYPE = Int32;
	using SUM_TYPE = Int64;
};

template <> struct PixelDepthInfo<Pix16u>
{
	using PIXELDEPTH = Pix16u;
	static const PIXELDEPTH DEFAULTALPHA_VALUE = LIMIT<PIXELDEPTH>::MAX;
	static const PIXELDEPTH MAXPIXEL_VALUE = LIMIT<PIXELDEPTH>::MAX;
	static const PIXELDEPTH ZEROPIXEL_VALUE = LIMIT<PIXELDEPTH>::MIN;
	static const PIXELDEPTH PIXELTOLERANCE_ONE = 0x0100, PIXELTOLERANCE_ZERO = 0;
	using PIXELTOLERANCE_ABSTYPE = Int32;
	using SUM_TYPE = UInt64;
};

template <> struct PixelDepthInfo<Pix16s>
{
	using PIXELDEPTH = Pix16s;
	static const PIXELDEPTH DEFAULTALPHA_VALUE = LIMIT<PIXELDEPTH>::MAX;
	static const PIXELDEPTH MAXPIXEL_VALUE = LIMIT<PIXELDEPTH>::MAX;
	static const PIXELDEPTH ZEROPIXEL_VALUE = LIMIT<PIXELDEPTH>::MIN;
	static const PIXELDEPTH PIXELTOLERANCE_ONE = 0x0100, PIXELTOLERANCE_ZERO = 0;
	using PIXELTOLERANCE_ABSTYPE = Int32;
	using SUM_TYPE = Int64;
};

template <> struct PixelDepthInfo<Pix32u>
{
	using PIXELDEPTH = Pix32u;
	static const PIXELDEPTH DEFAULTALPHA_VALUE = LIMIT<PIXELDEPTH>::MAX;
	static const PIXELDEPTH MAXPIXEL_VALUE = LIMIT<PIXELDEPTH>::MAX;
	static const PIXELDEPTH ZEROPIXEL_VALUE = LIMIT<PIXELDEPTH>::MIN;
	static const PIXELDEPTH PIXELTOLERANCE_ONE = 0x01000000, PIXELTOLERANCE_ZERO = 0;
	using PIXELTOLERANCE_ABSTYPE = Int64;
	using SUM_TYPE = UInt64;
};

template <> struct PixelDepthInfo<Pix32s>
{
	using PIXELDEPTH = Pix32s;
	static const PIXELDEPTH DEFAULTALPHA_VALUE = LIMIT<PIXELDEPTH>::MAX;
	static const PIXELDEPTH MAXPIXEL_VALUE = LIMIT<PIXELDEPTH>::MAX;
	static const PIXELDEPTH ZEROPIXEL_VALUE = LIMIT<PIXELDEPTH>::MIN;
	static const PIXELDEPTH PIXELTOLERANCE_ONE = 0x01000000, PIXELTOLERANCE_ZERO = 0;
	using PIXELTOLERANCE_ABSTYPE = Int64;
	using SUM_TYPE = Int64;
};

template <> struct PixelDepthInfo<Pix16f>
{
	using PIXELDEPTH = Pix16f;
	static const PIXELDEPTH DEFAULTALPHA_VALUE;
	static const PIXELDEPTH MAXPIXEL_VALUE;
	static const PIXELDEPTH ZEROPIXEL_VALUE;
	static const PIXELDEPTH PIXELTOLERANCE_ONE, PIXELTOLERANCE_ZERO;
	using PIXELTOLERANCE_ABSTYPE = Pix32f;
	using SUM_TYPE = Pix32f;
};

template <> struct PixelDepthInfo<Pix32f>
{
	using PIXELDEPTH = Pix32f;
	static const PIXELDEPTH DEFAULTALPHA_VALUE;
	static const PIXELDEPTH MAXPIXEL_VALUE;
	static const PIXELDEPTH ZEROPIXEL_VALUE;
	static const PIXELDEPTH PIXELTOLERANCE_ONE, PIXELTOLERANCE_ZERO;
	using PIXELTOLERANCE_ABSTYPE = Pix32f;
	using SUM_TYPE = Pix32f;
};

template <> struct PixelDepthInfo<Pix64f>
{
	using PIXELDEPTH = Pix64f;
	static const PIXELDEPTH DEFAULTALPHA_VALUE;
	static const PIXELDEPTH MAXPIXEL_VALUE;
	static const PIXELDEPTH ZEROPIXEL_VALUE;
	static const PIXELDEPTH PIXELTOLERANCE_ONE, PIXELTOLERANCE_ZERO;
	using PIXELTOLERANCE_ABSTYPE = Pix64f;
	using SUM_TYPE = Pix64f;
};


//----------------------------------------------------------------------------------------
/// Converts a single component from one pixel depth to another.
/// Supported Pixel types are: Pix8u, Pix16u, Pix32f.
/// Proper rounding will be performed.
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE_FORCE_INLINE void ConvertPixel(Pix8u& dst, const Pix8u src)   { dst = src; }
MAXON_ATTRIBUTE_FORCE_INLINE void ConvertPixel(Pix8u& dst, const Pix8s src)   { dst = (src - LIMIT<Pix8s>::MIN); }
MAXON_ATTRIBUTE_FORCE_INLINE void ConvertPixel(Pix8u& dst, const Pix16u src)  { dst = src >> 8; }
MAXON_ATTRIBUTE_FORCE_INLINE void ConvertPixel(Pix8u& dst, const Pix16s src)  { dst = (src - LIMIT<Pix16s>::MIN) >> 8; }
MAXON_ATTRIBUTE_FORCE_INLINE void ConvertPixel(Pix8u& dst, const Pix32u src)  { dst = src >> 24; }
MAXON_ATTRIBUTE_FORCE_INLINE void ConvertPixel(Pix8u& dst, const Pix32s src)  { dst = (src - LIMIT<Pix32s>::MIN) >> 24; }
MAXON_ATTRIBUTE_FORCE_INLINE void ConvertPixel(Pix8u& dst, const Pix32f src)  { dst = Pix8u(ClampValue(Pix32f(src * 255.0f + 0.5f), Pix32f(0.0f), Pix32f(255.0f))); }
MAXON_ATTRIBUTE_FORCE_INLINE void ConvertPixel(Pix8u& dst, const Pix64f src)  { dst = Pix8u(ClampValue(Pix64f(src * 255.0 + 0.5), Pix64f(0.0), Pix64f(255.0))); }

MAXON_ATTRIBUTE_FORCE_INLINE void ConvertPixel(Pix16u& dst, const Pix8u src)  { dst = Pix16u(src << 8) | src; }
MAXON_ATTRIBUTE_FORCE_INLINE void ConvertPixel(Pix16u& dst, const Pix8s src)  { Pix8u s = Pix8u(src - LIMIT<Pix8s>::MIN); dst = Pix16u(s << 8) | s; }
MAXON_ATTRIBUTE_FORCE_INLINE void ConvertPixel(Pix16u& dst, const Pix16u src) { dst = src; }
MAXON_ATTRIBUTE_FORCE_INLINE void ConvertPixel(Pix16u& dst, const Pix16s src) { dst = src - LIMIT<Pix16s>::MIN; }
MAXON_ATTRIBUTE_FORCE_INLINE void ConvertPixel(Pix16u& dst, const Pix32u src) { dst = src >> 16; }
MAXON_ATTRIBUTE_FORCE_INLINE void ConvertPixel(Pix16u& dst, const Pix32s src) { dst = (src - LIMIT<Pix32s>::MIN) >> 16; }
MAXON_ATTRIBUTE_FORCE_INLINE void ConvertPixel(Pix16u& dst, const Pix32f src) { dst = Pix16u(ClampValue(Pix32f(src * 65535.0f + 0.5f), Pix32f(0.0f), Pix32f(65535.0f))); }
MAXON_ATTRIBUTE_FORCE_INLINE void ConvertPixel(Pix16u& dst, const Pix64f src) { dst = Pix16u(ClampValue(Pix64f(src * 65535.0 + 0.5), Pix64f(0.0), Pix64f(65535.0))); }

MAXON_ATTRIBUTE_FORCE_INLINE void ConvertPixel(Pix32u& dst, const Pix8u src)  { dst = (Pix32u(src) << 24) | (Pix32u(src) << 16) | (Pix32u(src) << 8) | Pix32u(src); }
MAXON_ATTRIBUTE_FORCE_INLINE void ConvertPixel(Pix32u& dst, const Pix8s src)  { Pix32u s = Pix8u(src - LIMIT<Pix8s>::MIN); dst = (s << 24) | (s << 16) | (s << 8) | s; }
MAXON_ATTRIBUTE_FORCE_INLINE void ConvertPixel(Pix32u& dst, const Pix16u src) { dst = src << 16 | src; }
MAXON_ATTRIBUTE_FORCE_INLINE void ConvertPixel(Pix32u& dst, const Pix16s src) { Pix16u s = Pix16u(src - LIMIT<Pix16s>::MIN); dst = (s << 16) | s; }
MAXON_ATTRIBUTE_FORCE_INLINE void ConvertPixel(Pix32u& dst, const Pix32u src) { dst = src; }
MAXON_ATTRIBUTE_FORCE_INLINE void ConvertPixel(Pix32u& dst, const Pix32s src) { dst = src - LIMIT<Pix32s>::MIN; }
MAXON_ATTRIBUTE_FORCE_INLINE void ConvertPixel(Pix32u& dst, const Pix32f src) { dst = (Pix32u)ClampValue(UInt64(src * 4294967295.0f + 0.5f), UInt64(0), UInt64(4294967295)); }
MAXON_ATTRIBUTE_FORCE_INLINE void ConvertPixel(Pix32u& dst, const Pix64f src) { dst = (Pix32u)ClampValue(UInt64(src * 4294967295.0 + 0.5), UInt64(0), UInt64(4294967295)); }
	
//----------------------------------------------------------------------------------------
/// to signed
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE_FORCE_INLINE void ConvertPixel(Pix8s& dst, const Pix8u src)   { dst = (src + LIMIT<Pix8s>::MIN); }
MAXON_ATTRIBUTE_FORCE_INLINE void ConvertPixel(Pix8s& dst, const Pix8s src)   { dst = src; }
MAXON_ATTRIBUTE_FORCE_INLINE void ConvertPixel(Pix8s& dst, const Pix16u src)  { dst = (src >> 8) + LIMIT<Pix8s>::MIN; }
MAXON_ATTRIBUTE_FORCE_INLINE void ConvertPixel(Pix8s& dst, const Pix16s src)  { dst = src >> 8; }
MAXON_ATTRIBUTE_FORCE_INLINE void ConvertPixel(Pix8s& dst, const Pix32u src)  { dst = (Pix8s)((Pix32s)(src >> 24) + (Pix32s)LIMIT<Pix8s>::MIN); }
MAXON_ATTRIBUTE_FORCE_INLINE void ConvertPixel(Pix8s& dst, const Pix32s src)  { dst = src >> 24; }
MAXON_ATTRIBUTE_FORCE_INLINE void ConvertPixel(Pix8s& dst, const Pix32f src)  { dst = Pix8u(ClampValue(Pix32f(src * 255.0f + 0.5f), Pix32f(0.0f), Pix32f(255.0f))) + LIMIT<Pix8s>::MIN; }
MAXON_ATTRIBUTE_FORCE_INLINE void ConvertPixel(Pix8s& dst, const Pix64f src)  { dst = Pix8u(ClampValue(Pix64f(src * 255.0 + 0.5), Pix64f(0.0), Pix64f(255.0))) + LIMIT<Pix8s>::MIN; }

MAXON_ATTRIBUTE_FORCE_INLINE void ConvertPixel(Pix16s& dst, const Pix8u src)  { dst = (Pix16u(src << 8) + src) + LIMIT<Pix16s>::MIN; }
MAXON_ATTRIBUTE_FORCE_INLINE void ConvertPixel(Pix16s& dst, const Pix8s src)  { dst = Pix16u(src << 8) + src; }
MAXON_ATTRIBUTE_FORCE_INLINE void ConvertPixel(Pix16s& dst, const Pix16u src) { dst = src + LIMIT<Pix16s>::MIN; }
MAXON_ATTRIBUTE_FORCE_INLINE void ConvertPixel(Pix16s& dst, const Pix16s src) { dst = src; }
MAXON_ATTRIBUTE_FORCE_INLINE void ConvertPixel(Pix16s& dst, const Pix32u src) { dst = Pix16s((src >> 16) + LIMIT<Pix32s>::MIN); }
MAXON_ATTRIBUTE_FORCE_INLINE void ConvertPixel(Pix16s& dst, const Pix32s src) { dst = src >> 16; }
MAXON_ATTRIBUTE_FORCE_INLINE void ConvertPixel(Pix16s& dst, const Pix32f src) { dst = Pix16u(ClampValue(Pix32f(src * 65535.0f + 0.5f), Pix32f(0.0f), Pix32f(65535.0f))) + LIMIT<Pix16s>::MIN; }
MAXON_ATTRIBUTE_FORCE_INLINE void ConvertPixel(Pix16s& dst, const Pix64f src) { dst = Pix16u(ClampValue(Pix64f(src * 65535.0 + 0.5), Pix64f(0.0), Pix64f(65535.0))) + LIMIT<Pix16s>::MIN; }

MAXON_ATTRIBUTE_FORCE_INLINE void ConvertPixel(Pix32s& dst, const Pix8u src)  { dst = Pix32s((Pix32u(src) << 24 | Pix32u(src) << 16 | Pix32u(src) << 8 | Pix32u(src)) + Pix32u(LIMIT<Pix32s>::MIN)); }
MAXON_ATTRIBUTE_FORCE_INLINE void ConvertPixel(Pix32s& dst, const Pix8s src)  { dst = (src << 24) + (src << 16) + (src << 8) + src; }
MAXON_ATTRIBUTE_FORCE_INLINE void ConvertPixel(Pix32s& dst, const Pix16u src) { dst = Pix32s((Pix32u(src) << 16 | Pix32u(src)) + Pix32u(LIMIT<Pix32s>::MIN)); }
MAXON_ATTRIBUTE_FORCE_INLINE void ConvertPixel(Pix32s& dst, const Pix16s src) { dst = (src << 16) + src; }
MAXON_ATTRIBUTE_FORCE_INLINE void ConvertPixel(Pix32s& dst, const Pix32u src) { dst = Pix32s(src) + LIMIT<Pix32s>::MIN; }
MAXON_ATTRIBUTE_FORCE_INLINE void ConvertPixel(Pix32s& dst, const Pix32s src) { dst = src; }
MAXON_ATTRIBUTE_FORCE_INLINE void ConvertPixel(Pix32s& dst, const Pix32f src) { dst = Pix32u(ClampValue(UInt64(src * 4294967295.0f + 0.5f), UInt64(0), UInt64(4294967295))) + LIMIT<Pix32s>::MIN; }
MAXON_ATTRIBUTE_FORCE_INLINE void ConvertPixel(Pix32s& dst, const Pix64f src) { dst = Pix32u(ClampValue(UInt64(src * 4294967295.0 + 0.5), UInt64(0), UInt64(4294967295))) + LIMIT<Pix32s>::MIN; }

#ifndef MAXON_TARGET_CPU_INTEL
	MAXON_ATTRIBUTE_FORCE_INLINE void ConvertPixel(Float32& dst, const Pix8u src)  { dst = src * (1.0f / 255.0f); }
	MAXON_ATTRIBUTE_FORCE_INLINE void ConvertPixel(Float64& dst, const Pix8u src)  { dst = src * (1.0 / 255.0); }
#else
	// this code is taken from the result of the msvc2010 release64 bit compiler.
	// the msvc generated 3 times faster code for 8bit int -> float then the intel compiler.
	static const __m128 DIV255ss = { 1.0f / 255.0f };
	MAXON_ATTRIBUTE_FORCE_INLINE void ConvertPixel(Float32& dst, const Pix8u src)
	{
		__m128i i = _mm_cvtsi32_si128(src);
		__m128	f = _mm_cvtepi32_ps(i);
		f = _mm_mul_ss(f, DIV255ss);
		_mm_store_ss(&dst, f);
	}

	// this code is taken from the result of the msvc2010 release64 bit compiler.
	// the msvc generated 3 times faster code for 8bit int -> float then the intel compiler.
	static const __m128d DIV255sd = { 1.0 / 255.0 };
	MAXON_ATTRIBUTE_FORCE_INLINE void ConvertPixel(Float64& dst, const Pix8u src)
	{
		__m128i i = _mm_cvtsi32_si128(src);
		__m128d	f = _mm_cvtepi32_pd(i);
		f = _mm_mul_sd(f, DIV255sd);
		_mm_store_sd(&dst, f);
	}
#endif

MAXON_ATTRIBUTE_FORCE_INLINE void ConvertPixel(Pix32f& dst, const Pix16u src)  { dst = src * (1.0f / 65535.0f); }
MAXON_ATTRIBUTE_FORCE_INLINE void ConvertPixel(Pix32f& dst, const Pix32u src)  { dst = src * (1.0f / 4294967295.0f); }
MAXON_ATTRIBUTE_FORCE_INLINE void ConvertPixel(Pix32f& dst, const Pix32s src)  { dst = Pix32u(src - LIMIT<Pix32s>::MIN) * (1.0f / 4294967295.0f); }
MAXON_ATTRIBUTE_FORCE_INLINE void ConvertPixel(Pix32f& dst, const Pix32f src)  { dst = src; }
MAXON_ATTRIBUTE_FORCE_INLINE void ConvertPixel(Pix32f& dst, const Pix64f src)  { dst = (Pix32f)src; }

MAXON_ATTRIBUTE_FORCE_INLINE void ConvertPixel(Pix64f& dst, const Pix16u src)  { dst = src * (1.0 / 65535.0); }
MAXON_ATTRIBUTE_FORCE_INLINE void ConvertPixel(Pix64f& dst, const Pix32u src)  { dst = src * (1.0 / 4294967295.0); }
MAXON_ATTRIBUTE_FORCE_INLINE void ConvertPixel(Pix64f& dst, const Pix32s src)  { dst = Pix32u(src - LIMIT<Pix32s>::MIN) * (1.0 / 4294967295.0); }
MAXON_ATTRIBUTE_FORCE_INLINE void ConvertPixel(Pix64f& dst, const Pix32f src)  { dst = src; }
MAXON_ATTRIBUTE_FORCE_INLINE void ConvertPixel(Pix64f& dst, const Pix64f src)  { dst = src; }

MAXON_ATTRIBUTE_FORCE_INLINE void ConvertPixel(Pix16f& dst, const Pix8u src)   { Pix32f d; ConvertPixel(d, src); dst = d; }
MAXON_ATTRIBUTE_FORCE_INLINE void ConvertPixel(Pix16f& dst, const Pix16u src)  { Pix32f d; ConvertPixel(d, src); dst = d; }
MAXON_ATTRIBUTE_FORCE_INLINE void ConvertPixel(Pix16f& dst, const Pix32u src)  { Pix32f d; ConvertPixel(d, src); dst = d; }
MAXON_ATTRIBUTE_FORCE_INLINE void ConvertPixel(Pix16f& dst, const Pix32s src) { Pix32f d; ConvertPixel(d, src); dst = d; }
MAXON_ATTRIBUTE_FORCE_INLINE void ConvertPixel(Pix16f& dst, const Pix16f src)  { dst = src; }
MAXON_ATTRIBUTE_FORCE_INLINE void ConvertPixel(Pix16f& dst, const Pix32f src)  { Pix32f d; ConvertPixel(d, src); dst = d; }
MAXON_ATTRIBUTE_FORCE_INLINE void ConvertPixel(Pix16f& dst, const Pix64f src)  { Pix32f d; ConvertPixel(d, src); dst = d; }


//----------------------------------------------------------------------------------------
/// Compares 2 Pixel values with a given tolerance.
/// @param[in] a									Pixel Value 1.
/// @param[in] b									Pixel Value 2.
/// @param[in] oneTolerance				Tolerance of the pixel in the [0..255] range. If the PIXELDEPTH is different to Pix8u it will be
/// 															converted by using the contant defined in PixelDepthInfo<PIXELDEPTH>::PIXELTOLERANCE_ONE.
/// @return												True if the difference is below the given tolerance.
//----------------------------------------------------------------------------------------
template <typename PIXELDEPTH> MAXON_ATTRIBUTE_FORCE_INLINE Bool IsPixelIdentical(PIXELDEPTH a, PIXELDEPTH b, Int oneTolerance)
{
	PIXELDEPTH tolerance = oneTolerance > 0 ? (PIXELDEPTH)((PIXELDEPTH)oneTolerance * PixelDepthInfo<PIXELDEPTH>::PIXELTOLERANCE_ONE)
																				 : (PIXELDEPTH)PixelDepthInfo<PIXELDEPTH>::PIXELTOLERANCE_ZERO;

	PIXELDEPTH diff = (PIXELDEPTH)Abs(
		typename PixelDepthInfo<PIXELDEPTH>::PIXELTOLERANCE_ABSTYPE(a) - typename PixelDepthInfo<PIXELDEPTH>::PIXELTOLERANCE_ABSTYPE(b));

	if (diff > tolerance)
		return false;

	return true;
}


template <Int BITDEPTH, Int COMPONENTS> struct ChannelOffsetHelper
{
	BITS						_offsetArray[COMPONENTS + 1];
	Int							_offsetByteArray[COMPONENTS + 1];
	ChannelOffsets	_offsets;
	Block<Int>			_offsetBytes;

	ChannelOffsetHelper()
	{
		_offsetArray[0] = BITS(0);
		for (Int c = 1; c <= COMPONENTS; c++)
		{
			_offsetArray[c] = _offsetArray[c - 1] + BITS(BITDEPTH);
			_offsetByteArray[c] = _offsetArray[c].GetBytes();
		}
		_offsets = ToBlock(_offsetArray);
		_offsetBytes = ToBlock(_offsetByteArray);
	}
};

//----------------------------------------------------------------------------------------
/// Helper class for implementors of the PixelFormatInterface.
/// e.g. class PixelFormatRGBE : public PixelFormatTemplateBase<PixelFormatRGBE, PixRGBE, 1, ColorSpaces::RGBspace> { MAXON_COMPONENT(); } defines a new pixelformat with the
/// basic functionality defined by this class.
//----------------------------------------------------------------------------------------
template <typename COMP, typename PIXELDEPTH, Int COMPONENTS, typename COLORSPACE, typename PIXELFORMATGROUP>
class PixelFormatTemplateBase : public maxon::Component<COMP, PixelFormatInterface>
{
public:
	static Result<void> ConfigureClass(ClassInterface& cls)
	{
		return cls.AddComponents(PixelFormatBaseClass());
	}

	using PixelDepth = PIXELDEPTH;
	static const Int _channelCount = COMPONENTS;
	static const Int _bytesPerComponent = sizeof(PixelDepth);
	static const ChannelOffsetHelper<8 * SIZEOF(PIXELDEPTH), COMPONENTS> _channelOffsets;

	MAXON_METHOD const PixelFormatGroup& GetPixelFormatGroup() const
	{
		return PIXELFORMATGROUP::GetInstance()();
	}

	MAXON_METHOD Int GetChannelCount() const
	{
		return _channelCount;
	}

	MAXON_METHOD const ChannelOffsets& GetChannelOffsets() const
	{
		return _channelOffsets._offsets;
	}

	MAXON_METHOD ColorSpace GetColorSpace() const
	{
		return COLORSPACE::GetInstance()();
	}

	MAXON_METHOD Bool IsIdenticalPixel(const ImageConstBuffer& a, const ImageConstBuffer& b, Int oneTolerance) const
	{
		Block<const ImageChannel> channels = this->self.GetChannels();

		for (Int c = 0; c < _channelCount; c++)
		{
			if (channels.IsValidIndex(c) && channels[c].GetChannelType() == ImageChannelTypes::Unused())
				continue;

			const Pix* pixA = a._buffer + a._channelOffsets[c].GetBytes();
			const Pix* pixB = b._buffer + b._channelOffsets[c].GetBytes();
			if (!IsPixelIdentical(*(PixelDepth*)pixA, *(PixelDepth*)pixB, oneTolerance))
				return false;
		}
		return true;
	}

	static Result<void> DescribeIO(const DataSerializeInterface& stream)
	{
		return OK;
	}
};

template <typename COMP, typename PIXELDEPTH, Int COMPONENTS, typename COLORSPACE, typename PIXELFORMATGROUP> ChannelOffsetHelper<8 * SIZEOF(PIXELDEPTH), COMPONENTS>
const PixelFormatTemplateBase<COMP, PIXELDEPTH, COMPONENTS, COLORSPACE, PIXELFORMATGROUP>::_channelOffsets = ChannelOffsetHelper<8 * SIZEOF(PIXELDEPTH), COMPONENTS>();

}

#endif // GFX_IMAGE_PIXELFORMAT_TEMPLATE_H__
