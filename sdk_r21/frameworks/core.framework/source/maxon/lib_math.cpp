#include "maxon/lib_math.h"

namespace maxon
{

// if this seed ever gets changed, it must be changed in the corresponding Python stubs
static const int GLOBAL_SEED = 69069;

// PseudoRandom is only left in for compatibility.
template <typename FLOAT> void PseudoRandom<FLOAT>::Init(UInt32 s)
{
	// make sure the first random number will be different to s/2^31 (to avoid that the first random number is close to 0)
	seed = ((s + 1) * GLOBAL_SEED) & 0x7FFFFFFF;
}

template <typename FLOAT> FLOAT PseudoRandom<FLOAT>::Get01()
{
	const FLOAT inv = FLOAT(1.0 / (2147483648.0 + 1.0));	// +1.0 in case of imprecision

	seed = ((seed + 1) * GLOBAL_SEED) & 0x7FFFFFFF;
	return FLOAT(seed) * inv;
}

// create instantiation for Float32 and Float64
template class PseudoRandom<Float32>;
template class PseudoRandom<Float64>;

template <typename FLOAT> void LinearCongruentialRandom<FLOAT>::Init(UInt32 seed)
{
	// The seed initially is advanced to avoid clustering close to 0 for typical user-adjusted values.
	_seed = seed * GLOBAL_SEED + 1;
}

template <typename FLOAT> FLOAT LinearCongruentialRandom<FLOAT>::Get01()
{
	_seed = _seed * GLOBAL_SEED + 1;

	// Divide by MAX + 1 to make sure the largest possible UInt32 number will result in 1.0.
	return FLOAT(_seed) * FLOAT(1.0 / FLOAT((Int)LIMIT<UInt32>::MAX + 1));
}

template <typename FLOAT> UInt32 LinearCongruentialRandom<FLOAT>::GetUInt32()
{
	_seed = _seed * GLOBAL_SEED + 1;
	return _seed;
}

// create instantiation for Float32 and Float64
template class LinearCongruentialRandom<Float32>;
template class LinearCongruentialRandom<Float64>;

template <typename FLOAT> MATH_VECTOR ReflectRay(const MATH_VECTOR& direction, const MATH_VECTOR& normal)
{
	return direction - normal * (FLOAT(2.0) * Dot(normal, direction));
}

// create instantiation for Float32 and Float64
template Vector32 ReflectRay(const Vector32&, const Vector32&);
template Vector64 ReflectRay(const Vector64&, const Vector64&);


template <typename FLOAT> MATH_VECTOR RGBToHSV(const MATH_COLOR& color)
{
	FLOAT r, g, b, h, s, v, delta, max, min;

	r = color.r;
	g = color.g;
	b = color.b;

	max = r;
	if (g > max)
		max = g;
	if (b > max)
		max = b;
	min = r;
	if (g < min)
		min = g;
	if (b < min)
		min = b;

	v = max;
	if (max > 0.0)
	{
		s = FLOAT(1.0) - min / max;

		if (s < FLOAT(0.001))
		{
			return MATH_VECTOR(0.0, 0.0, min);
		}
	}
	else
	{
		return MATH_VECTOR(0.0);
	}

	delta = max - min;
	if (r == max)
		h = (g - b) / delta;
	else if (g == max)
		h = FLOAT(2.0) + (b - r) / delta;
	else
		h = FLOAT(4.0) + (r - g) / delta;

	h /= FLOAT(6.0);
	if (h < 0.0)
		h += FLOAT(1.0);
	return MATH_VECTOR(h, s, v);
}

// create instantiation for Float32 and Float64
template Vector32 RGBToHSV(const Color32&);
template Vector64 RGBToHSV(const Color64&);

template <typename FLOAT> MATH_COLOR HSVToRGB(const MATH_VECTOR& color)
{
	FLOAT r = 0.0, g = 0.0, b = 0.0, h, s, v, f, p, q, t, i;
	Int		j;

	h = color.x;
	s = color.y;
	v = color.z;

	if (s < FLOAT(0.001))
	{
		r = g = b = v;
	}
	else
	{
		if (h == FLOAT(1.0))
			h = 0.0;

		h *= FLOAT(6.0);
		i	 = Floor(h);
		f	 = h - i;
		p	 = v * (FLOAT(1.0) - s);
		q	 = v * (FLOAT(1.0) - s * f);
		t	 = v * (FLOAT(1.0) - s * (FLOAT(1.0) - f));
		j	 = Int(i);

		switch (j)
		{
			default:
			case 0: r = v; g = t; b = p; break;
			case 1: r = q; g = v; b = p; break;
			case 2: r = p; g = v; b = t; break;
			case 3: r = p; g = q; b = v; break;
			case 4: r = t; g = p; b = v; break;
			case 5: r = v; g = p; b = q; break;
		}
	}
	return MATH_COLOR(r, g, b);
}

// create instantiation for Float32 and Float64
template Color32 HSVToRGB(const Vector32&);
template Color64 HSVToRGB(const Vector64&);

template <typename FLOAT> static FLOAT GetNear(FLOAT oldValue, FLOAT& newValue)
{
	FLOAT diff = (newValue - oldValue) / FLOAT(PI2);
	diff = (diff - Floor(diff)) * FLOAT(PI2);

	if (diff > FLOAT(PI))
		diff -= FLOAT(PI2);

	newValue = diff + oldValue;
	return diff;
}

template <typename FLOAT> MATH_VECTOR GetOptimumRotation(const MATH_VECTOR& oldRotation, const MATH_VECTOR& newRotation, ROTATIONORDER rotationOrder)
{
	MATH_VECTOR d1, d2, n2, n1 = newRotation;

	switch (rotationOrder)
	{
		case ROTATIONORDER::XYZGLOBAL:
		case ROTATIONORDER::ZYXGLOBAL:
			n2 = MATH_VECTOR(FLOAT(PI) + newRotation.x, FLOAT(PI) - newRotation.y, FLOAT(PI) + newRotation.z);
			break;

		case ROTATIONORDER::YZXGLOBAL:
		case ROTATIONORDER::XZYGLOBAL:
			n2 = MATH_VECTOR(FLOAT(PI) + newRotation.x, FLOAT(PI) + newRotation.y, FLOAT(PI) - newRotation.z);
			break;

		default:
		case ROTATIONORDER::YXZGLOBAL:
		case ROTATIONORDER::ZXYGLOBAL:
			n2 = MATH_VECTOR(FLOAT(PI) - newRotation.x, FLOAT(PI) + newRotation.y, FLOAT(PI) + newRotation.z);
			break;
	}

	d1.x = GetNear(oldRotation.x, n1.x);
	d1.y = GetNear(oldRotation.y, n1.y);
	d1.z = GetNear(oldRotation.z, n1.z);

	d2.x = GetNear(oldRotation.x, n2.x);
	d2.y = GetNear(oldRotation.y, n2.y);
	d2.z = GetNear(oldRotation.z, n2.z);

	if (Abs(d2.x) + Abs(d2.y) + Abs(d2.z) < Abs(d1.x) + Abs(d1.y) + Abs(d1.z))
		return n2;
	else
		return n1;
}

// create instantiation for Float32 and Float64
template Vector32 GetOptimumRotation(const Vector32&, const Vector32&, ROTATIONORDER);
template Vector64 GetOptimumRotation(const Vector64&, const Vector64&, ROTATIONORDER);


template <typename FLOAT> MATH_VECTOR GetClosestPointOnLine(const MATH_VECTOR& lineOrigin, const MATH_VECTOR& lineDirection, const MATH_VECTOR& point)
{
	FLOAT vsquare = lineDirection.GetSquaredLength();
	if (vsquare == 0.0)
		return lineOrigin;

	return lineOrigin + (Dot(point - lineOrigin, lineDirection) / vsquare) * lineDirection;
}

// create instantiation for Float32 and Float64
template Vector32 GetClosestPointOnLine(const Vector32&, const Vector32&, const Vector32&);
template Vector64 GetClosestPointOnLine(const Vector64&, const Vector64&, const Vector64&);


template <typename FLOAT> FLOAT GetPointLineDistance(const MATH_VECTOR& lineOrigin, const MATH_VECTOR& lineDirection, const MATH_VECTOR& point)
{
	FLOAT vsquare = lineDirection.GetSquaredLength();
	if (vsquare == 0.0)
		return 0.0;

	return (lineOrigin + (Dot(point - lineOrigin, lineDirection) / vsquare) * lineDirection - point).GetLength();
}

// create instantiation for Float32 and Float64
template Float32 GetPointLineDistance(const Vector32&, const Vector32&, const Vector32&);
template Float64 GetPointLineDistance(const Vector64&, const Vector64&, const Vector64&);


template <typename FLOAT> MATH_MATRIX GetTranslationMatrix(const MATH_VECTOR& translation)
{
	MATH_MATRIX erg;
	erg.off = translation;
	return erg;
}

// create instantiation for Float32 and Float64
template Matrix32 GetTranslationMatrix(const Vector32& translation);
template Matrix64 GetTranslationMatrix(const Vector64& translation);


template <typename FLOAT> MATH_MATRIX2 GetTranslationMatrix(const MATH_VECTOR2& translation)
{
	MATH_MATRIX2 erg;
	erg.off = translation;
	return erg;
}

// create instantiation for Float32 and Float64
template Matrix2d32 GetTranslationMatrix(const Vector2d32& translation);
template Matrix2d64 GetTranslationMatrix(const Vector2d64& translation);

template <typename FLOAT> MATH_SQUAREMATRIX GetScaleMatrix(const MATH_VECTOR& scale)
{
	MATH_SQUAREMATRIX erg;
	erg.v1.x = scale.x;
	erg.v2.y = scale.y;
	erg.v3.z = scale.z;
	return erg;
}

// create instantiation for Float32 and Float64
template SquareMatrix32 GetScaleMatrix(const Vector32&);
template SquareMatrix64 GetScaleMatrix(const Vector64&);

template <typename FLOAT> MATH_SQUAREMATRIX2 GetScaleMatrix(const MATH_VECTOR2& scale)
{
	MATH_SQUAREMATRIX2 erg;
	erg.v1.x = scale.x;
	erg.v2.y = scale.y;
	return erg;
}

// create instantiation for Float32 and Float64
template SquareMatrix2d32 GetScaleMatrix(const Vector2d32&);
template SquareMatrix2d64 GetScaleMatrix(const Vector2d64&);

template <typename FLOAT> MATH_SQUAREMATRIX GetRotationMatrixX(FLOAT rotation)
{
	MATH_SQUAREMATRIX erg;
	FLOAT cs = Cos(rotation), sn = Sin(rotation);

#ifdef COORDINATESYSTEM_RIGHT_HANDED
	sn = -sn;
#endif

	erg.v2.y =  cs;
	erg.v2.z = -sn;

	erg.v3.y =  sn;
	erg.v3.z =  cs;
	return erg;
}

// create instantiation for Float32 and Float64
template SquareMatrix32 GetRotationMatrixX(Float32);
template SquareMatrix64 GetRotationMatrixX(Float64);


template <typename FLOAT> MATH_SQUAREMATRIX GetRotationMatrixY(FLOAT rotation)
{
	MATH_SQUAREMATRIX erg;
	FLOAT cs = Cos(rotation), sn = Sin(rotation);

#ifdef COORDINATESYSTEM_RIGHT_HANDED
	sn = -sn;
#endif

	erg.v1.x =  cs;
	erg.v1.z =  sn;

	erg.v3.x = -sn;
	erg.v3.z =  cs;
	return erg;
}

// create instantiation for Float32 and Float64
template SquareMatrix32 GetRotationMatrixY(Float32);
template SquareMatrix64 GetRotationMatrixY(Float64);


template <typename FLOAT> MATH_SQUAREMATRIX GetRotationMatrixZ(FLOAT rotation)
{
	MATH_SQUAREMATRIX erg;
	FLOAT cs = Cos(rotation), sn = Sin(rotation);

#ifdef COORDINATESYSTEM_RIGHT_HANDED
	sn = -sn;
#endif

	erg.v1.x =  cs;
	erg.v1.y = -sn;

	erg.v2.x =  sn;
	erg.v2.y =  cs;
	return erg;
}

// create instantiation for Float32 and Float64
template SquareMatrix32 GetRotationMatrixZ(Float32);
template SquareMatrix64 GetRotationMatrixZ(Float64);

template <typename FLOAT> MATH_SQUAREMATRIX2 GetRotationMatrix(FLOAT rotation)
{
	MATH_SQUAREMATRIX2 erg;
	FLOAT cs = Cos(rotation), sn = Sin(rotation);

	erg.v1.x =  cs;
	erg.v1.y =  sn;

	erg.v2.x = -sn;
	erg.v2.y =  cs;
	return erg;
}

// create instantiation for Float32 and Float64
template SquareMatrix2d32 GetRotationMatrix(Float32);
template SquareMatrix2d64 GetRotationMatrix(Float64);

template <typename FLOAT> void GetRotationAxis(const MATH_SQUAREMATRIX& m, MATH_VECTOR& axisVector, FLOAT& axisRotation)
{
	// matrix vectors need to be normalized
	MATH_VECTOR v1 = m.v1.GetNormalized(), v2 = m.v2.GetNormalized(), v3 = m.v3.GetNormalized();

	// calculate angle
	axisRotation = ACos((v1.x + v2.y + v3.z - FLOAT(1.0)) * FLOAT(0.5));

	// calculate axis
	axisVector.x = v2.z - v3.y;
	axisVector.y = v3.x - v1.z;
	axisVector.z = v1.y - v2.x;

	if (!axisVector.IsZero())
	{
		axisVector = axisVector.GetNormalized();
#ifdef COORDINATESYSTEM_LEFT_HANDED
		axisVector = -axisVector;
#endif
	}
	else
	{
		axisVector = MATH_VECTOR(0.0, FLOAT(1.0), 0.0);
		axisRotation = 0.0;
	}
}

// create instantiation for Float32 and Float64
template void GetRotationAxis(const SquareMatrix32&, Vector32&, Float32&);
template void GetRotationAxis(const SquareMatrix64&, Vector64&, Float64&);


template <typename FLOAT> MATH_SQUAREMATRIX GetRotationMatrixFromAxis(const MATH_VECTOR& axisVector, FLOAT axisRotation)
{
	MATH_SQUAREMATRIX m;

	if (axisVector.IsZero() || axisRotation == 0.0)
		return m;

	FLOAT sin = Sin(FLOAT(0.5) * axisRotation);
	FLOAT cos = Cos(FLOAT(0.5) * axisRotation);

#ifdef COORDINATESYSTEM_RIGHT_HANDED
	sin = -sin;
#endif

	MATH_VECTOR vn = axisVector.GetNormalized() * sin;

	MATH_VECTOR fT = FLOAT(2.0) * vn;
	MATH_VECTOR fTw = fT * cos;
	FLOAT fTxx = fT.x * vn.x;
	FLOAT fTxy = fT.y * vn.x;
	FLOAT fTxz = fT.z * vn.x;
	FLOAT fTyy = fT.y * vn.y;
	FLOAT fTyz = fT.z * vn.y;
	FLOAT fTzz = fT.z * vn.z;

	m.v1 = MATH_VECTOR(FLOAT(1.0) - (fTyy + fTzz), fTxy - fTw.z, fTxz + fTw.y);
	m.v2 = MATH_VECTOR(fTxy + fTw.z, FLOAT(1.0) - (fTxx + fTzz), fTyz - fTw.x);
	m.v3 = MATH_VECTOR(fTxz - fTw.y, fTyz + fTw.x, FLOAT(1.0) - (fTxx + fTyy));

	return m;
}

// create instantiation for Float32 and Float64
template SquareMatrix32 GetRotationMatrixFromAxis(const Vector32&, Float32);
template SquareMatrix64 GetRotationMatrixFromAxis(const Vector64&, Float64);

template <typename FLOAT> MATH_MATRIX GetPSRMatrix(const MATH_VECTOR& position, const MATH_VECTOR& scale, const MATH_VECTOR& rotation, ROTATIONORDER rotationOrder)
{
	MATH_MATRIX m = GetRotationMatrix(rotation, rotationOrder);

	m.sqmat *= scale;
	m.off = position;

	return m;
}

template <typename FLOAT> MATH_SQUAREMATRIX GetRotationMatrix(const MATH_VECTOR& rotation, ROTATIONORDER rotationOrder)
{
	if (rotation.IsZero())
		return MATH_SQUAREMATRIX();	// speedup

	FLOAT tmp2, tmp1;
	MATH_VECTOR cosRot, sinRot;

	SinCos(rotation.x, sinRot.x, cosRot.x);
	SinCos(rotation.y, sinRot.y, cosRot.y);
	SinCos(rotation.z, sinRot.z, cosRot.z);

#ifdef COORDINATESYSTEM_LEFT_HANDED
	sinRot = -sinRot;
#endif

	switch (rotationOrder)
	{
		case ROTATIONORDER::YXZGLOBAL:
		{
			tmp1 = sinRot.y * sinRot.x;
			tmp2 = cosRot.y * sinRot.x;

			return MATH_SQUAREMATRIX(MATH_VECTOR(cosRot.y * cosRot.z - tmp1 * sinRot.z, cosRot.y * sinRot.z + tmp1 * cosRot.z, -sinRot.y * cosRot.x),
															 MATH_VECTOR(-cosRot.x * sinRot.z, cosRot.x * cosRot.z, sinRot.x),
															 MATH_VECTOR(sinRot.y * cosRot.z + tmp2 * sinRot.z, sinRot.y * sinRot.z - tmp2 * cosRot.z, cosRot.y * cosRot.x));
		}

		case ROTATIONORDER::YZXGLOBAL:
		{
			tmp1 = cosRot.y * sinRot.z;
			tmp2 = sinRot.y * sinRot.z;

			return MATH_SQUAREMATRIX(MATH_VECTOR(cosRot.y * cosRot.z, tmp1 * cosRot.x + sinRot.y * sinRot.x, tmp1 * sinRot.x - sinRot.y * cosRot.x),
															 MATH_VECTOR(-sinRot.z, cosRot.z * cosRot.x, cosRot.z * sinRot.x),
															 MATH_VECTOR(sinRot.y * cosRot.z, tmp2 * cosRot.x - cosRot.y * sinRot.x, tmp2 * sinRot.x + cosRot.y * cosRot.x));
		}

		case ROTATIONORDER::ZYXGLOBAL:
		{
			tmp1 = cosRot.z * sinRot.y;
			tmp2 = sinRot.z * sinRot.y;

			return MATH_SQUAREMATRIX(MATH_VECTOR(cosRot.z * cosRot.y, sinRot.z * cosRot.x + tmp1 * sinRot.x, sinRot.z * sinRot.x - tmp1 * cosRot.x),
															 MATH_VECTOR(-sinRot.z * cosRot.y, cosRot.z * cosRot.x - tmp2 * sinRot.x, cosRot.z * sinRot.x + tmp2 * cosRot.x),
															 MATH_VECTOR(sinRot.y, -cosRot.y * sinRot.x, cosRot.y * cosRot.x));
		}

		case ROTATIONORDER::XZYGLOBAL:
		{
			tmp1 = cosRot.x * sinRot.z;
			tmp2 = sinRot.x * sinRot.z;

			return MATH_SQUAREMATRIX(MATH_VECTOR(cosRot.z * cosRot.y, sinRot.z, -cosRot.z * sinRot.y),
															 MATH_VECTOR(-tmp1 * cosRot.y + sinRot.x * sinRot.y, cosRot.x * cosRot.z, tmp1 * sinRot.y + sinRot.x * cosRot.y),
															 MATH_VECTOR(tmp2 * cosRot.y + cosRot.x * sinRot.y, -sinRot.x * cosRot.z, -tmp2 * sinRot.y + cosRot.x * cosRot.y));
		}

		case ROTATIONORDER::XYZGLOBAL:
		{
			tmp1 = sinRot.x * sinRot.y;
			tmp2 = cosRot.x * sinRot.y;

			return MATH_SQUAREMATRIX(MATH_VECTOR(cosRot.y * cosRot.z, cosRot.y * sinRot.z, -sinRot.y),
															 MATH_VECTOR(tmp1 * cosRot.z - cosRot.x * sinRot.z, tmp1 * sinRot.z + cosRot.x * cosRot.z, sinRot.x * cosRot.y),
															 MATH_VECTOR(tmp2 * cosRot.z + sinRot.x * sinRot.z, tmp2 * sinRot.z - sinRot.x * cosRot.z, cosRot.x * cosRot.y));
		}

		default:
		case ROTATIONORDER::ZXYGLOBAL:
		{
			tmp1 = sinRot.z * sinRot.x;
			tmp2 = cosRot.z * sinRot.x;

			return MATH_SQUAREMATRIX(MATH_VECTOR(cosRot.z * cosRot.y + tmp1 * sinRot.y, sinRot.z * cosRot.x, -cosRot.z * sinRot.y + tmp1 * cosRot.y),
															 MATH_VECTOR(-sinRot.z * cosRot.y + tmp2 * sinRot.y, cosRot.z * cosRot.x, sinRot.z * sinRot.y + tmp2 * cosRot.y),
															 MATH_VECTOR(cosRot.x * sinRot.y, -sinRot.x, cosRot.x * cosRot.y));
		}
	}
}

// create instantiation for Float32 and Float64
template SquareMatrix32 GetRotationMatrix(const Vector32&, ROTATIONORDER);
template SquareMatrix64 GetRotationMatrix(const Vector64&, ROTATIONORDER);
template Matrix32 GetPSRMatrix(const Vector32& position, const Vector32& scale, const Vector32& rotation, ROTATIONORDER rotationOrder);
template Matrix64 GetPSRMatrix(const Vector64& position, const Vector64& scale, const Vector64& rotation, ROTATIONORDER rotationOrder);

template <typename FLOAT> MATH_VECTOR GetRotationAngles(const MATH_VECTOR& direction, ROTATIONORDER rotationOrder)
{
	MATH_VECTOR v1 = !direction;

	// to allow for the same naming as in the other GetRotationAngles routine
	MATH_VECTOR& v2 = v1;
	MATH_VECTOR& v3 = v1;

	MATH_VECTOR res(DONT_INITIALIZE);
	switch (rotationOrder)
	{
		case ROTATIONORDER::YXZGLOBAL:
			res = MATH_VECTOR(-ASin(v2.z), 0.0, ATan2(v2.x, v2.y));
			break;

		case ROTATIONORDER::YZXGLOBAL:
			res = MATH_VECTOR(ATan2(-v2.z, v2.y), 0.0, ASin(v2.x));
			break;

		case ROTATIONORDER::ZYXGLOBAL:
			res = MATH_VECTOR(ATan2(v3.y, v3.z), -ASin(v3.x), 0.0);
			break;

		case ROTATIONORDER::XZYGLOBAL:
			res = MATH_VECTOR(0.0, ATan2(v1.z, v1.x), -ASin(v1.y));
			break;

		case ROTATIONORDER::XYZGLOBAL:
			res = MATH_VECTOR(0.0, ASin(v1.z), ATan2(-v1.y, v1.x));
			break;

		default:
		case ROTATIONORDER::ZXYGLOBAL:
			res = MATH_VECTOR(ASin(v3.y), ATan2(-v3.x, v3.z), 0.0);
			break;
	}

#ifdef COORDINATESYSTEM_RIGHT_HANDED
	return -res;
#else
	return res;
#endif
}

// create instantiation for Float32 and Float64
template Vector32 GetRotationAngles(const Vector32&, ROTATIONORDER);
template Vector64 GetRotationAngles(const Vector64&, ROTATIONORDER);


template <typename FLOAT> MATH_VECTOR GetRotationAngles(const MATH_SQUAREMATRIX& m, ROTATIONORDER rotationOrder)
{
	// always needs to use 64bit due to precision issues
	Vector64 rot, v1 = !((Vector64) m.v1), v2 = !((Vector64) m.v2), v3 = !((Vector64) m.v3);

	if (v1.IsZero())
	{
		// matrix is incomplete, let's try to fix it
		v1 = !Cross(v2, v3);

		// matrix cannot be fixed
		if (v1.IsZero())
			return MATH_VECTOR(0.0);
	}
	else if (v2.IsZero())
	{
		// matrix is incomplete, let's try to fix it
		v2 = !Cross(v3, v1);

		// matrix cannot be fixed
		if (v2.IsZero())
			return MATH_VECTOR(0.0);
	}
	else if (v3.IsZero())
	{
		// matrix is incomplete, let's try to fix it
		v3 = !Cross(v1, v2);

		// matrix cannot be fixed
		if (v3.IsZero())
			return MATH_VECTOR(0.0);
	}

	MATH_VECTOR res(DONT_INITIALIZE);
	switch (rotationOrder)
	{
		case ROTATIONORDER::YXZGLOBAL:
			res = (MATH_VECTOR)Vector64(-ASin(v2.z), ATan2(v1.z, v3.z), ATan2(v2.x, v2.y));
			break;

		case ROTATIONORDER::YZXGLOBAL:
			res = (MATH_VECTOR)Vector64(ATan2(-v2.z, v2.y), ATan2(-v3.x, v1.x), ASin(v2.x));
			break;

		case ROTATIONORDER::ZYXGLOBAL:
			res = (MATH_VECTOR)Vector64(ATan2(v3.y, v3.z), -ASin(v3.x), ATan2(v2.x, v1.x));
			break;

		case ROTATIONORDER::XZYGLOBAL:
			res = (MATH_VECTOR)Vector64(ATan2(v3.y, v2.y), ATan2(v1.z, v1.x), -ASin(v1.y));
			break;

		case ROTATIONORDER::XYZGLOBAL:
			res = (MATH_VECTOR)Vector64(ATan2(-v2.z, v3.z), ASin(v1.z), ATan2(-v1.y, v1.x));
			break;

		default:
		case ROTATIONORDER::ZXYGLOBAL:
			res = (MATH_VECTOR)Vector64(ASin(v3.y), ATan2(-v3.x, v3.z), ATan2(-v1.y, v2.y));
			break;
	}

#ifdef COORDINATESYSTEM_RIGHT_HANDED
	return -res;
#else
	return res;
#endif
}

// create instantiation for Float32 and Float64
template Vector32 GetRotationAngles(const SquareMatrix32&, ROTATIONORDER);
template Vector64 GetRotationAngles(const SquareMatrix64&, ROTATIONORDER);

} // namespace maxon
