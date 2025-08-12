#ifndef GFX_IMAGE_FUNCTIONS_COLOR_CONVERSIONS_H__
#define GFX_IMAGE_FUNCTIONS_COLOR_CONVERSIONS_H__

#include "maxon/general_math.h"
#include "maxon/lib_math.h"



namespace maxon
{

//----------------------------------------------------------------------------------------------------
// Color Conversions
//----------------------------------------------------------------------------------------------------

// Color conversion used to get RGB values that can be output to the screen
MAXON_ATTRIBUTE_FORCE_INLINE Color XyzToRgb(const Color& xyz)
{
	Color rgb(DONT_INITIALIZE);
	rgb.r = (3.240479f	* xyz.r) - (1.537150f * xyz.g) - (0.498535f * xyz.b);
	rgb.g = (-0.969256f	* xyz.r) + (1.875991f * xyz.g) + (0.041556f * xyz.b);
	rgb.b = (0.055648f	* xyz.r) - (0.204043f * xyz.g) + (1.057311f * xyz.b);
	return rgb;
}

// Color conversion used to get XYZ values from RGB when doing calculations with images (environment maps)
MAXON_ATTRIBUTE_FORCE_INLINE Color RgbToXyz(const Color& rgb)
{
	Color xyz(DONT_INITIALIZE);
	xyz.r = (0.412453f * rgb.r) + (0.357580f * rgb.g) + (0.180423f * rgb.b);
	xyz.g = (0.212671f * rgb.r) + (0.715160f * rgb.g) + (0.072169f * rgb.b);
	xyz.b = (0.019334f * rgb.r) + (0.119193f * rgb.g) + (0.950227f * rgb.b);
	return xyz;
}

MAXON_ATTRIBUTE_FORCE_INLINE Color RgbToCmy(const Color rgb)
{
	return Color(1.0 - rgb.r, 1.0 - rgb.g, 1.0 - rgb.b);
}

MAXON_ATTRIBUTE_FORCE_INLINE Color CmyToRgb(const Color cmy)
{
	return Color(1.0 - cmy.r, 1.0 - cmy.g, 1.0 - cmy.b);
}

template <typename COLORTYPE> MAXON_ATTRIBUTE_FORCE_INLINE COLORTYPE RgbToHsv(const COLORTYPE& rgb)
{
	return maxon::RGBToHSV(rgb).GetColor();
}

template <typename COLORTYPE> MAXON_ATTRIBUTE_FORCE_INLINE COLORTYPE HsvToRgb(const COLORTYPE& hsv)
{
	return maxon::HSVToRGB(hsv.GetVector());
}


// HSL conversions ported from SLA module in order to stay consistent with legacy blend modes
template <typename COLORTYPE> MAXON_ATTRIBUTE_FORCE_INLINE COLORTYPE RgbToHsl(const COLORTYPE& rgb)
{
	COLORTYPE result;
	using FLOATTYPE = typename COLORTYPE::ValueType;
	FLOATTYPE v, m, vm, r2, g2, b2;

	v = Max(rgb.r, rgb.g);
	v = Max(v, rgb.b);
	m = Min(rgb.r, rgb.g);
	m = Min(m, rgb.b);

	result.b = (m + v) / FLOATTYPE(2.0);

	if (result.b <= FLOATTYPE(0.0))
	{
		result.g = FLOATTYPE(0);
		result.r = FLOATTYPE(0);
	}
	else
	{
		result.g = vm = v - m;
		if (result.g <= FLOATTYPE(0.0))
		{
			result.r = result.g = FLOATTYPE(0.0);
			return result;
		}

		FLOATTYPE div = (result.b <= FLOATTYPE(0.5)) ? (v + m) : (FLOATTYPE(2.0) - v - m);
		if (div != FLOATTYPE(0.0)) 
			result.g /= div;

		if (vm != FLOATTYPE(0.0))
		{
			r2 = (v - rgb.r) / vm;
			g2 = (v - rgb.g) / vm;
			b2 = (v - rgb.b) / vm;
		}
		else
		{
			r2 = FLOATTYPE(0.0);
			g2 = FLOATTYPE(0.0);
			b2 = FLOATTYPE(0.0);
		}

		if (rgb.r == v)
			result.r = (rgb.g == m ? FLOATTYPE(5.0) + b2 : FLOATTYPE(1.0) - g2);
		else if (rgb.g == v)
			result.r = (rgb.b == m ? FLOATTYPE(1.0) + r2 : FLOATTYPE(3.0) - b2);
		else
			result.r = (rgb.r == m ? FLOATTYPE(3.0) + g2 : FLOATTYPE(5.0) - r2);

		result.r *= FLOATTYPE(60.0);
		if (result.r < FLOATTYPE(0.0))
			result.r += FLOATTYPE(360.0);
	}
	
	result.r /= FLOATTYPE(360.0);

	return result;
}

template <typename FLOATTYPE> MAXON_ATTRIBUTE_FORCE_INLINE FLOATTYPE Value(FLOATTYPE nl, FLOATTYPE n2, FLOATTYPE hue)
{
	if (hue > FLOATTYPE(1.0))
		hue -= FLOATTYPE(1.0);
	else if (hue < FLOATTYPE(0.0))
		hue += FLOATTYPE(1.0);
	if (hue < FLOATTYPE(60.0 / 360.0))
		return nl + (n2 - nl) * hue / FLOATTYPE(60.0 / 360.0);
	if (hue < FLOATTYPE(180.0 / 360.0))
		return n2;
	if (hue < FLOATTYPE(240.0 / 360.0))
		return nl + (n2 - nl) * (FLOATTYPE(240.0 / 360.0) - hue) / FLOATTYPE(60.0 / 360.0);
	return nl;
}

template <typename COLORTYPE> MAXON_ATTRIBUTE_FORCE_INLINE COLORTYPE HslToRgb(const COLORTYPE& hsl)
{
	COLORTYPE result;
	using FLOATTYPE = typename COLORTYPE::ValueType;
	FLOATTYPE m1, m2;
	if (hsl.b <= FLOATTYPE(0.5))
		m2 = hsl.b * (FLOATTYPE(1.0) + hsl.g);
	else
		m2 = hsl.b + hsl.g - hsl.b * hsl.g;
	m1 = FLOATTYPE(2.0) * hsl.b - m2;
	if (hsl.g == FLOATTYPE(0.0) || hsl.r == FLOATTYPE(-1.0))
	{
		result.r = result.g = result.b = hsl.b;
	}
	else
	{
		result.r = Value(m1, m2, hsl.r + (FLOATTYPE(1.0) / FLOATTYPE(3.0)));
		result.g = Value(m1, m2, hsl.r);
		result.b = Value(m1, m2, hsl.r - (FLOATTYPE(1.0) / FLOATTYPE(3.0)));
	}
	return result;
}

//----------------------------------------------------------------------------------------
/// Returns the color of an ideal black-body radiator at the given temperature.
/// https://en.wikipedia.org/wiki/Color_temperature
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE_FORCE_INLINE Color ColorTemperatureToRGB(Float temperature)
{
	// http://www.physics.sfasu.edu/astro/color/blackbodyc.txt
	// http://www.adnex.de/data/strahlungsmessung/
	Float X = 0, Y = 0, Z = 0, weight, lambda, L, m;
	Int32 band;
	
	// CIE Color Matching Functions (x_bar,y_bar,z_bar) for wavelenghts in 5 nm increments from 380 nm to 780 nm.
	Float prColorMatch[][3] =
	{
		{0.0014, 0.0000, 0.0065},
		{0.0022, 0.0001, 0.0105},
		{0.0042, 0.0001, 0.0201},
		{0.0076, 0.0002, 0.0362},
		{0.0143, 0.0004, 0.0679},
		{0.0232, 0.0006, 0.1102},
		{0.0435, 0.0012, 0.2074},
		{0.0776, 0.0022, 0.3713},
		{0.1344, 0.0040, 0.6456},
		{0.2148, 0.0073, 1.0391},
		{0.2839, 0.0116, 1.3856},
		{0.3285, 0.0168, 1.6230},
		{0.3483, 0.0230, 1.7471},
		{0.3481, 0.0298, 1.7826},
		{0.3362, 0.0380, 1.7721},
		{0.3187, 0.0480, 1.7441},
		{0.2908, 0.0600, 1.6692},
		{0.2511, 0.0739, 1.5281},
		{0.1954, 0.0910, 1.2876},
		{0.1421, 0.1126, 1.0419},
		{0.0956, 0.1390, 0.8130},
		{0.0580, 0.1693, 0.6162},
		{0.0320, 0.2080, 0.4652},
		{0.0147, 0.2586, 0.3533},
		{0.0049, 0.3230, 0.2720},
		{0.0024, 0.4073, 0.2123},
		{0.0093, 0.5030, 0.1582},
		{0.0291, 0.6082, 0.1117},
		{0.0633, 0.7100, 0.0782},
		{0.1096, 0.7932, 0.0573},
		{0.1655, 0.8620, 0.0422},
		{0.2257, 0.9149, 0.0298},
		{0.2904, 0.9540, 0.0203},
		{0.3597, 0.9803, 0.0134},
		{0.4334, 0.9950, 0.0087},
		{0.5121, 1.0000, 0.0057},
		{0.5945, 0.9950, 0.0039},
		{0.6784, 0.9786, 0.0027},
		{0.7621, 0.9520, 0.0021},
		{0.8425, 0.9154, 0.0018},
		{0.9163, 0.8700, 0.0017},
		{0.9786, 0.8163, 0.0014},
		{1.0263, 0.7570, 0.0011},
		{1.0567, 0.6949, 0.0010},
		{1.0622, 0.6310, 0.0008},
		{1.0456, 0.5668, 0.0006},
		{1.0026, 0.5030, 0.0003},
		{0.9384, 0.4412, 0.0002},
		{0.8544, 0.3810, 0.0002},
		{0.7514, 0.3210, 0.0001},
		{0.6424, 0.2650, 0.0000},
		{0.5419, 0.2170, 0.0000},
		{0.4479, 0.1750, 0.0000},
		{0.3608, 0.1382, 0.0000},
		{0.2835, 0.1070, 0.0000},
		{0.2187, 0.0816, 0.0000},
		{0.1649, 0.0610, 0.0000},
		{0.1212, 0.0446, 0.0000},
		{0.0874, 0.0320, 0.0000},
		{0.0636, 0.0232, 0.0000},
		{0.0468, 0.0170, 0.0000},
		{0.0329, 0.0119, 0.0000},
		{0.0227, 0.0082, 0.0000},
		{0.0158, 0.0057, 0.0000},
		{0.0114, 0.0041, 0.0000},
		{0.0081, 0.0029, 0.0000},
		{0.0058, 0.0021, 0.0000},
		{0.0041, 0.0015, 0.0000},
		{0.0029, 0.0010, 0.0000},
		{0.0020, 0.0007, 0.0000},
		{0.0014, 0.0005, 0.0000},
		{0.0010, 0.0004, 0.0000},
		{0.0007, 0.0002, 0.0000},
		{0.0005, 0.0002, 0.0000},
		{0.0003, 0.0001, 0.0000},
		{0.0002, 0.0001, 0.0000},
		{0.0002, 0.0001, 0.0000},
		{0.0001, 0.0000, 0.0000},
		{0.0001, 0.0000, 0.0000},
		{0.0001, 0.0000, 0.0000},
		{0.0000, 0.0000, 0.0000}
	};
	
	for (band = 0; band < 81; band++)
	{
		weight = (band == 0 || band == 80) ? .5 : 1.0;
		lambda = 380 + Float(band) * 5.0;
		const Float c1 = PI * 1.191043936e+29;	// = 2c^2result.r * PI / (nm^5)
		const Float c2 = 14387686.6;						// = h*c/k/nm
		L = c1 / Pow(lambda, 5.0_f) / Exp(c2 / (lambda * temperature) - 1.0_f);
		X += weight * L * prColorMatch[band][0];
		Y += weight * L * prColorMatch[band][1];
		Z += weight * L * prColorMatch[band][2];
	}
	m = X;
	
	if (Y > m) 
		m = Y;
	if (Z > m) 
		m = Z;
	
	X /= m;
	Y /= m;
	Z /= m;
	
	return XyzToRgb(Color(X, Y, Z));
}

}	// namespace maxon

#endif // GFX_IMAGE_FUNCTIONS_COLOR_CONVERSIONS_H__
