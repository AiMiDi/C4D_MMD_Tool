#ifndef FRACTION_H__
#define FRACTION_H__

#include "maxon/apibase.h"


/// @file
/// Fraction math definitions.

namespace maxon
{

class Fraction
{
public:
	Fraction() = default;

	explicit Fraction(Float r)
	{
		if (r > 1.0e15_f)
			r = 1.0e15_f;
		if (r < -1.0e15_f)
			r = -1.0e15_f;
		numerator = Floor(r * 1000.0_f + 0.5_f);
		denominator = 1000.0_f;
		Reduce();
	}

	void Reduce()
	{
		Float z, n, m;

		z = Abs(numerator);
		n = Abs(denominator);

		if (z < 0.001 || n < 0.001)
		{
			numerator = 0.0;
			denominator = 1.0;
		}
		else if (z < MAXVALUE_INT32_FLOAT32 && n < MAXVALUE_INT32_FLOAT32)
		{
			Int32 iz = (Int32)z, in = (Int32)n, im;

			if (in == 0) // failsafe
			{
				numerator = 0.0;
				denominator = 1.0;
			}
			else
			{
				do
				{
					im = iz % in;
					iz = in;
					in = im;
				} while (im);

				numerator /= Float(iz);
				denominator /= Float(iz);
			}
		}
		else
		{
			Float64 div = 1.0e18 / Max(Float64(z), Float64(n));
			if (div < 1.0)
			{
				z *= div;
				n *= div;
				numerator *= div;
				denominator *= div;
			}
			if (n < 1.0)
			{
				n = 1.0;
				denominator = 1.0;
			}

			do
			{
				m = FMod(z, n);
				z = n;
				n = m;
			} while (m >= 0.5);

			numerator /= z;
			denominator /= z;
		}
	}

	Float GetNumerator() const
	{
		return numerator;
	}

	Float GetDenominator() const
	{
		return denominator;
	}

private:
	Float numerator = 0.0;
	Float denominator = 1.0;
};

} // namespace maxon

#endif // FRACTION_H__
