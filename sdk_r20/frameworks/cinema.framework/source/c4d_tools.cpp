#include "ge_math.h"
#include "c4d_tools.h"
#include "c4d_general.h"

#ifndef __API_INTERN__
#include "c4d_basedocument.h"

Vector TransformColor(const Vector& v, COLORSPACETRANSFORMATION colortransformation)
{
	return C4DOS.Sh->TransformColor(v, colortransformation);
}

maxon::Color TransformColor(const maxon::Color& v, COLORSPACETRANSFORMATION colortransformation)
{
	return C4DOS.Sh->TransformColor(v.GetVector(), colortransformation).GetColor();
}
#endif

Vector32 s_empty;
Vector64 l_empty;

Matrix MatrixMove(const Vector& t)
{
	Matrix erg;
	erg.off = t;
	return erg;
}

Matrix MatrixScale(const Vector& s)
{
	Matrix erg;

	erg.sqmat.v1.x = s.x;
	erg.sqmat.v2.y = s.y;
	erg.sqmat.v3.z = s.z;
	return erg;
}

Matrix MatrixRotX(Float w)
{
	Matrix erg;
	Float	 cs = Cos(w), sn = Sin(w);

	erg.sqmat.v3.z = cs;
	erg.sqmat.v2.z = -sn;
	erg.sqmat.v3.y = sn;
	erg.sqmat.v2.y = cs;

	return erg;
}

Matrix MatrixRotY(Float w)
{
	Matrix erg;
	Float	 cs = Cos(w), sn = Sin(w);

	erg.sqmat.v1.x = cs;
	erg.sqmat.v3.x = -sn;
	erg.sqmat.v1.z = sn;
	erg.sqmat.v3.z = cs;

	return erg;
}

Matrix MatrixRotZ(Float w)
{
	Matrix erg;
	Float	 cs = Cos(w), sn = Sin(w);

	erg.sqmat.v1.x = cs;
	erg.sqmat.v2.x = sn;
	erg.sqmat.v1.y = -sn;
	erg.sqmat.v2.y = cs;

	return erg;
}

static Float GetNear(Float alt, Float* neu)
{
	Float diff = (*neu - alt) / (Float) PI2;
	diff = (diff - Floor(diff)) * (Float) PI2;
	*neu = diff + alt;

	if (diff >= (Float) PI)
	{
		diff -= (Float) PI2;
		*neu -= (Float) PI2;
	}

	return diff;
}

Vector GetOptimalAngle(const Vector& orot, const Vector& nrot, ROTATIONORDER order)
{
	Vector d1, d2, n2, n1 = nrot;

	switch (order)
	{
		case ROTATIONORDER::XYZGLOBAL:
		case ROTATIONORDER::ZYXGLOBAL:					n2 = Vector((Float) PI + nrot.x, (Float) PI - nrot.y, (Float) PI + nrot.z);	break;
		case ROTATIONORDER::YZXGLOBAL:
		case ROTATIONORDER::XZYGLOBAL:					n2 = Vector((Float) PI + nrot.x, (Float) PI + nrot.y, (Float) PI - nrot.z);	break;

		case ROTATIONORDER::YXZGLOBAL:
		case ROTATIONORDER::ZXYGLOBAL:					n2 = Vector((Float) PI - nrot.x, (Float) PI + nrot.y, (Float) PI + nrot.z);	break;

		default:
		case ROTATIONORDER::HPB:								n2 = Vector((Float) PI + nrot.x, (Float) PI - nrot.y, (Float) PI + nrot.z);	break;
	}

	d1.x = GetNear(orot.x, &n1.x);
	d1.y = GetNear(orot.y, &n1.y);
	d1.z = GetNear(orot.z, &n1.z);

	d2.x = GetNear(orot.x, &n2.x);
	d2.y = GetNear(orot.y, &n2.y);
	d2.z = GetNear(orot.z, &n2.z);

	if (Abs(d2.x) + Abs(d2.y) + Abs(d2.z) < Abs(d1.x) + Abs(d1.y) + Abs(d1.z))
		return n2;
	else
		return n1;
}

// Winkel eines Punkts bestimmen
Vector VectorToHPB(const Vector& p)
{
	Float	 l;
	Vector rot;

	l = Sqrt(p.x * p.x + p.z * p.z);

	if (l < 0.00001)
	{
		if (p.y > 0.0)
			rot = Vector(0.0, (Float) PI05, 0.0);
		else
			rot = Vector(0.0, -(Float) PI05, 0.0);
	}
	else
	{
		if (p.z > 0.0)
			rot.x = -ASin(p.x / l);
		else
			rot.x = (Float) PI + ASin(p.x / l);
		rot.y = ATan(p.y / l);
		rot.z = 0.0;
	}
	return rot;
}

Vector MatrixToHPB(const Matrix& m, ROTATIONORDER rot_order)
{
	static const Float CUTOFF = 1.0e-7; // ITEM#126925 Alembic Export: Animation Glitch

	Vector64 rot, v1 = !((Vector64)m.sqmat.v1), v2 = !((Vector64)m.sqmat.v2), v3 = !((Vector64)m.sqmat.v3);	// v1 has to be normalized

	Float64	 tsin = 0.0, tcos = 0.0;

	switch (rot_order)
	{
		case ROTATIONORDER::YXZGLOBAL:
		{
			rot.x = ASin(-v2.z);	// h
			Float64 a = -Cos(rot.x);
			if (Abs(a) > CUTOFF)
			{
				tsin	= v1.z;								// / a;
				tcos	= v3.z;								// / a;
				rot.y = ATan2(tsin, tcos);	// p
				tsin	= v2.x;								// / a;
				tcos	= v2.y;								// / a;
				rot.z = ATan2(tsin, tcos);	// b
			}
			else
			{
				rot.z = 0.0_f;
				tsin	= v1.y;	// V
				tcos	= v1.x;	// W
				rot.y = ATan2(tsin, tcos);
				if (v2.z > 0)
					rot.y = PI2 - rot.y;
			}
			break;
		}

		case ROTATIONORDER::YZXGLOBAL:
		{
			rot.z = ASin(v2.x);
			Float64 e = Cos(rot.z);
			if (Abs(e) > CUTOFF)
			{
				tsin	= -v2.z;	// / e;
				tcos	= v2.y;		// / e;
				rot.x = ATan2(tsin, tcos);
				tsin	= -v3.x;	// / e;
				tcos	= v1.x;		// / e;
				rot.y = ATan2(tsin, tcos);
			}
			else
			{
				rot.x = 0.0_f;
				tsin	= v1.z;		// V
				tcos	= -v1.y;	// W
				rot.y = ATan2(tsin, tcos);
				if (v2.x < 0)
					rot.y = PI - rot.y;
			}
			break;
		}

		case ROTATIONORDER::ZYXGLOBAL:
		{
			rot.y = ASin(-v3.x);
			Float64 c = Cos(rot.y);
			if (Abs(c) > CUTOFF)
			{
				tsin	= v2.x;	// / c; //f
				tcos	= v1.x;	// / c; //e
				rot.z = ATan2(tsin, tcos);
				tsin	= v3.y;	// / c; //b
				tcos	= v3.z;	// / c; //a
				rot.x = ATan2(tsin, tcos);
			}
			else
			{
				rot.z = 0.0_f;
				tsin	= -v1.y;	// V
				tcos	= v2.y;		// W
				rot.x = ATan2(tsin, tcos);
				if (v3.x < 0)
					rot.x = -rot.x;
			}
			break;
		}

		case ROTATIONORDER::XZYGLOBAL:
		{
			rot.z = ASin(-v1.y);
			Float64 e = -Cos(rot.z);
			if (Abs(e) > CUTOFF)
			{
				tsin	= v1.z;	// / e; //d
				tcos	= v1.x;	// / e; //c
				rot.y = ATan2(tsin, tcos);
				tsin	= v3.y;	// / e; //b
				tcos	= v2.y;	// / e; //a
				rot.x = ATan2(tsin, tcos);
			}
			else
			{
				rot.y = 0.0_f;
				tsin	= v3.x;	// V
				tcos	= v2.x;	// W
				rot.x = ATan2(tsin, tcos);
				if (v1.y > 0)
					rot.x += PI;
			}
			break;
		}

		case ROTATIONORDER::XYZGLOBAL:
		{
			rot.y = ASin(v1.z);
			Float64 c = Cos(rot.y);
			if (Abs(c) > CUTOFF)
			{
				tsin	= -v1.y;	// / c; //f
				tcos	= v1.x;		// / c; //e
				rot.z = ATan2(tsin, tcos);
				tsin	= -v2.z;	// / c; //b
				tcos	= v3.z;		// / c; //a
				rot.x = ATan2(tsin, tcos);
			}
			else
			{
				rot.z = 0.0_f;
				tsin	= v2.x;		// V
				tcos	= -v3.x;	// W
				rot.x = ATan2(tsin, tcos);
				if (v1.z < 0.0)
					rot.x -= PI;
			}
			break;
		}

		case ROTATIONORDER::ZXYGLOBAL:
		{
			rot.x = ASin(v3.y);
			Float64 a = Cos(rot.x);
			if (Abs(a) > CUTOFF)
			{
				tsin	= -v3.x;	// / a; //d
				tcos	= v3.z;		// / a; //c
				rot.y = ATan2(tsin, tcos);
				tsin	= -v1.y;	// / a; //f
				tcos	= v2.y;		// / a; //e
				rot.z = ATan2(tsin, tcos);
			}
			else
			{
				rot.z = 0.0_f;
				tsin	= v2.x;	// V
				tcos	= v1.x;	// W
				rot.y = ATan2(tsin, tcos);
				if (v3.y < 0.0)
					rot.y = -rot.y;
			}
			break;
		}

		case ROTATIONORDER::HPB:
		default:
		{
			Float64 l = Sqrt(v3.x * v3.x + v3.z * v3.z);

			if (l < 0.00001)
			{
				rot.x = 0.0;
				rot.z = ACos(Dot(Vector64(1.0, 0.0, 0.0), v1));

				if (v3.y > 0.0)
				{
					rot.y = PI05;
					if (v1.z < 0.0)
						rot.z = PI2 - rot.z;
				}
				else
				{
					rot.y = -PI05;
					if (v1.z > 0.0)
						rot.z = PI2 - rot.z;
				}
			}
			else
			{
				if (v3.z > 0.0)
					rot.x = -ASin(v3.x / l);
				else
					rot.x = PI + ASin(v3.x / l);

				if (rot.x < 0.0)
					rot.x += PI2;
				rot.y = ATan((Float64)v3.y / l);
				rot.z = ACos(Dot(Vector64(Cos(rot.x), 0.0, Sin(rot.x)), v1));

				if (v1.y > 0.0)
					rot.z = PI2 - rot.z;
			}
			break;
		}
	}

	return (Vector)rot;
}

// angles in DegToRad-/Euler system
Matrix HPBToMatrix(const Vector& w, ROTATIONORDER rot_order)
{
	if (w.IsZero())
		return Matrix();	// speedup

	Float a, b, c, d, e, f, cosksinn, sinksinn;

	if (rot_order == ROTATIONORDER::DEFAULT)
	{
		SinCos(w.x, d, c);	// y = h
		SinCos(w.y, b, a);	// x = p
	}
	else
	{
		SinCos(w.x, b, a);	// y = y
		SinCos(w.y, d, c);	// x = x
	}
	SinCos(w.z, f, e);		// z = b

	switch (rot_order)
	{
		case ROTATIONORDER::YXZGLOBAL:
		{
			sinksinn = d * b;
			cosksinn = c * b;

			return Matrix(Vector(0.0),
							 Vector(c * e + sinksinn * f, -c * f + sinksinn * e, d * a),
							 Vector(a * f, a * e, -b),
							 Vector(-d * e + cosksinn * f, d * f + cosksinn * e, c * a));
			break;
		}

		case ROTATIONORDER::YZXGLOBAL:
		{
			sinksinn = c * f;
			cosksinn = d * f;

			return Matrix(Vector(0.0),
							 Vector(c * e, -sinksinn * a + d * b, sinksinn * b + d * a),
							 Vector(f, e * a, -e * b),
							 Vector(-d * e, cosksinn * a + c * b, -cosksinn * b + c * a));
			break;
		}

		case ROTATIONORDER::ZYXGLOBAL:
		{
			sinksinn = e * d;
			cosksinn = f * d;

			return Matrix(Vector(0.0),
							 Vector(e * c, -f * a + sinksinn * b, f * b + sinksinn * a),
							 Vector(f * c, e * a + cosksinn * b, -e * b + cosksinn * a),
							 Vector(-d, c * b, c * a));
			break;
		}

		case ROTATIONORDER::XZYGLOBAL:
		{
			sinksinn = a * f;
			cosksinn = b * f;

			return Matrix(Vector(0.0),
							 Vector(e * c, -f, e * d),
							 Vector(sinksinn * c + b * d, a * e, sinksinn * d - b * c),
							 Vector(cosksinn * c - a * d, b * e, cosksinn * d + a * c));
			break;
		}

		case ROTATIONORDER::XYZGLOBAL:
		{
			sinksinn = b * d;
			cosksinn = a * d;

			return Matrix(Vector(0.0),
							 Vector(c * e, -c * f, d),
							 Vector(sinksinn * e + a * f, -sinksinn * f + a * e, -b * c),
							 Vector(-cosksinn * e + b * f, cosksinn * f + b * e, a * c));
			break;
		}

		default:
			// make the compiler happy
			break;
	}

	// ROTATIONORDER::DEFAULT / ROTATIONORDER::HPB / ROTATIONORDER::YXZLOCAL / ROTATIONORDER::ZXYGLOBAL
	cosksinn = e * b;
	sinksinn = f * b;

	return Matrix(Vector(0.0),
					 Vector(e * c - sinksinn * d, -f * a, e * d + sinksinn * c),
					 Vector(f * c + cosksinn * d, e * a, f * d - cosksinn * c),
					 Vector(-a * d, b, a * c));
}

static const Vector& GetAxis(const Matrix& m, Int axis)
{
	switch (axis)
	{
		case 0: return m.sqmat.v1;
		case 1: return m.sqmat.v2;
		default: return m.sqmat.v3;
	}
}

Matrix RebuildMatrix(const Matrix& mg)
{
	Matrix m = mg;

	Bool	collapsed[3] = { m.sqmat.v1.IsZero(), m.sqmat.v2.IsZero(), m.sqmat.v3.IsZero() };

	Int32 ccnt = collapsed[0] + collapsed[1] + collapsed[2], i = 0;

	switch (ccnt)
	{
		default:
		case 0:
			return m;
			break;

		case 3:
			m = Matrix();
			break;

		case 2:
		{
			for (i = 0; i < 3; i++)
			{
				if (!collapsed[i])
				{
					m = RotAxisToMatrix(GetAxis(m, i), 0.0);
					break;
				}
			}
			break;
		}

		case 1:
		{
			m.sqmat.Normalize();
			if (collapsed[0])
			{
				m.sqmat.v1 = Cross(m.sqmat.v3, m.sqmat.v2);
				if (m.sqmat.v1.IsZero())
					m.sqmat.v1.x = 1.0;
			}
			if (collapsed[1])
			{
				m.sqmat.v2 = Cross(m.sqmat.v3, m.sqmat.v1);
				if (m.sqmat.v2.IsZero())
					m.sqmat.v2.y = 1.0;
			}
			if (collapsed[2])
			{
				m.sqmat.v3 = Cross(m.sqmat.v1, m.sqmat.v2);
				if (m.sqmat.v3.IsZero())
					m.sqmat.v3.z = 1.0;
			}
			m = m.sqmat.GetTensorMatrix();
			break;
		}
	}

	for (i = 0; i < 3; i++)
	{
		if (!collapsed[i])
			const_cast<Vector&>(GetAxis(m, i)) *= GetAxis(mg, i).GetLength();
	}

	m.off = mg.off;

	return m;
}


void MatrixToRotAxis(const Matrix& mm, Vector* v, Float* w)
{
	Matrix m = mm;

	// Matrix axes must be normalized!
	m.sqmat.Normalize();

	// Calculate angle
	*w = ACos((m.sqmat.v1.x + m.sqmat.v2.y + m.sqmat.v3.z - 1.0_f) / 2.0_f);

	// Calculate axis
	v->x = m.sqmat.v2.z - m.sqmat.v3.y;
	v->y = m.sqmat.v3.x - m.sqmat.v1.z;
	v->z = m.sqmat.v1.y - m.sqmat.v2.x;

	*v = !(*v);
	if (v->IsZero())
	{
		*v = Vector(0.0, 1.0, 0.0);
		*w = 0.0;
	}
}

Matrix RotAxisToMatrix(const Vector& v, Float w)
{
	Matrix m;

	if ((v.x == 0.0 && v.y == 0.0 && v.z == 0.0) || w == 0.0)
		return m;

	//	// zuerst mal den Vector normieren ...
	//	m.sqmat.v2 = !v;
	//
	//	// jetzt ein rechtes KS basteln
	//	m.sqmat.v1 = m.sqmat.v2%Vector(0.0,0.0,1.0);
	//
	//	if (Len(m.sqmat.v1)>MIN_EPSILON)
	//	{
	//		m.sqmat.v3 = m.sqmat.v1%m.sqmat.v2;
	//	}
	//	else
	//	{
	//		m.sqmat.v3 = Vector(1.0,0.0,0.0)%m.sqmat.v2;
	//		m.sqmat.v1 = m.sqmat.v2%m.sqmat.v3;
	//	}
	//
	//	// Rotationsmatrix im Pleft- und Rechtssystem um Y ist gleich
	//	m = (m*MatrixRotY(w)) * !m;

	// faster version:
	Float whalf = 0.5 * w;
	Float hsin	= Sin(whalf);
	Float hcos	= Cos(whalf);

	Vector vn = !v * hsin;

	Float fTx	 = 2.0 * vn.x;
	Float fTy	 = 2.0 * vn.y;
	Float fTz	 = 2.0 * vn.z;
	Float fTwx = fTx * hcos;
	Float fTwy = fTy * hcos;
	Float fTwz = fTz * hcos;
	Float fTxx = fTx * vn.x;
	Float fTxy = fTy * vn.x;
	Float fTxz = fTz * vn.x;
	Float fTyy = fTy * vn.y;
	Float fTyz = fTz * vn.y;
	Float fTzz = fTz * vn.z;

	m.sqmat.v1 = Vector(1.0 - (fTyy + fTzz), fTxy - fTwz, fTxz + fTwy);
	m.sqmat.v2 = Vector(fTxy + fTwz, 1.0 - (fTxx + fTzz), fTyz - fTwx);
	m.sqmat.v3 = Vector(fTxz - fTwy, fTyz + fTwx, 1.0 - (fTxx + fTyy));

	return m;
}

Random::Random(void)
{
	Init(100);
	gset = 0.0;
}

void Random::Init(UInt32 s)
{
	iset = 0;
	seed = s;
}

Float Random::Get01(void)
{
	const Float inv = Float(1.0 / (2147483648.0 + 1.0));	// +1.0 in case of imprecision

	seed = ((seed + 1) * 69069) & 0x7FFFFFFF;
	return Float(seed) * inv;
}

Float Random::Get11(void)
{
	return Get01() * 2.0_f - 1.0_f;
}

Float Random::GetG01(void)
{
	Float fac, rsq, v1, v2;

	if (iset == 0)
	{
		do
		{
			v1	= Get11();
			v2	= Get11();
			rsq = v1 * v1 + v2 * v2;
		}	while (rsq >= 1.0 || rsq == 0.0);

		fac	 = Sqrt(- 2.0_f * Ln(rsq) / rsq);
		gset = v1 * fac;
		iset = 1;
		return v2 * fac * 0.09_f + 0.5_f;
	}
	else
	{
		iset = 0;
		return gset * 0.09_f + 0.5_f;
	}
}

Float Random::GetG11(void)
{
	Float fac, rsq, v1, v2;

	if (iset == 0)
	{
		do
		{
			v1	= Get11();
			v2	= Get11();
			rsq = v1 * v1 + v2 * v2;
		}	while (rsq >= 1.0 || rsq == 0.0);

		fac	 = Sqrt(- 2.0_f * Ln(rsq) / rsq);
		gset = v1 * fac;
		iset = 1;
		return v2 * fac * 0.18_f;
	}
	else
	{
		iset = 0;
		return gset * 0.18_f;
	}
}

Vector64 ReflectRay(const Vector64& v, const Vector64& n)
{
	return v - n * (2.0 * Dot(n, v));
}

Vector RGBToHSV(const Vector& col)
{
	Float r, g, b, h, s, v, delta, max, min;

	r = col.x;
	g = col.y;
	b = col.z;

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
		s = 1.0_f - min / max;

		if (s < MIN_EPSILON)
		{
			return Vector(0.0, 0.0, min);
		}
	}
	else
	{
		return Vector(0.0);
	}

	delta = Inverse(max - min);
	if (r == max)
		h = (g - b) * delta;
	else if (g == max)
		h = 2.0_f + (b - r) * delta;
	else
		h = 4.0_f + (r - g) * delta;

	h /= 6.0;
	if (h < 0.0)
		h += 1.0;
	return Vector(h, s, v);
}

Vector HSVToRGB(const Vector& col)
{
	Float r = 0.0, g = 0.0, b = 0.0, h, s, v, f, p, q, t, i;
	Int32 j;

	h = col.x;
	s = col.y;
	v = col.z;

	if (s < MIN_EPSILON)
	{
		r = g = b = v;
	}
	else
	{
		if (h == 1.0)
			h = 0.0;

		h *= 6.0_f;
		i	 = Floor(h);
		f	 = h - i;
		p	 = v * (1.0_f - s);
		q	 = v * (1.0_f - s * f);
		t	 = v * (1.0_f - s * (1.0_f - f));
		j	 = (Int32)i;
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
	return Vector(r, g, b);
}

Vector RGBToHSL(const Vector& col)
{
	Float r, g, b, v, m, vm, r2, g2, b2, h, s, l;

	r = col.x;
	g = col.y;
	b = col.z;

	v = FMax(r, g);
	v = FMax(v, b);
	m = FMin(r, g);
	m = FMin(m, b);

	l = (m + v) * 0.5_f;

	if (l <= 0.0_f)
	{
		s = 0.0_f;
		h = 0.0_f;
	}
	else
	{
		s = vm = v - m;
		if (s <= 0.0_f)
			return Vector(0.0_f);

		Float div = (l <= 0.5_f) ? (v + m) : (2.0_f - v - m);
		if (div != 0.0_f)
			s /= div;

		if (vm != 0.0_f)
		{
			r2 = (v - r) / vm;
			g2 = (v - g) / vm;
			b2 = (v - b) / vm;
		}
		else
		{
			r2 = 0.0_f;
			g2 = 0.0_f;
			b2 = 0.0_f;
		}

		if (r == v)
			h = (g == m ? 5.0_f + b2 : 1.0_f - g2);
		else if (g == v)
			h = (b == m ? 1.0_f + r2 : 3.0_f - b2);
		else
			h = (r == m ? 3.0_f + g2 : 5.0_f - r2);

		h /= 6.0_f;	// Convert hue to 0.0 ... 1.0
	}

	return Vector(h, s, l);
}

inline Float HSLtoRGB_value(Float nl, Float n2, Float hue)
{
	if (hue > 360.0_f)
		hue -= 360.0_f;
	else if (hue < 0.0_f)
		hue += 360.0_f;
	if (hue < 60.0_f)
		return nl + (n2 - nl) * hue / 60.0_f;
	if (hue < 180.0_f)
		return n2;
	if (hue < 240.0_f)
		return nl + (n2 - nl) * (240.0_f - hue) / 60.0_f;
	return nl;
}

Vector HSLtoRGB(const Vector& col)
{
	Float h, s, l, m1, m2, r, g, b;

	h = col.x * 360.0_f;
	s = col.y;
	l = col.z;

	if (l <= 0.5_f)
		m2 = l * (1.0_f + s);
	else
		m2 = l + s - l * s;
	m1 = 2.0_f * l - m2;
	if (s == 0.0_f || h == - 1.0_f)
	{
		r = g = b = l;
	}
	else
	{
		r = HSLtoRGB_value(m1, m2, h + 120.0_f);
		g = HSLtoRGB_value(m1, m2, h);
		b = HSLtoRGB_value(m1, m2, h - 120.0_f);
	}

	return Vector(r, g, b);
}

Vector PointLineDistance(const Vector& p0, const Vector& v, const Vector& p)
{
	Float vsquare = Dot(v, v);
	if (vsquare == 0.0)
		return Vector(0.0);
	return p - (p0 + Dot(p - p0, v) / vsquare * v);
}

Bool SphereLineIntersection(const Vector &linePoint1, const Vector &linePoint2, const Vector &sphereCenter, Float sphereRadius, Float *intersection1, Float *intersection2, Vector *hitPoint1, Vector *hitPoint2)
{
	Vector	e = linePoint2 - linePoint1,
					f = linePoint1 - sphereCenter;

	Float		a = Dot(e, e);
	Float		b = 2.0 * Dot(f, e);
	Float		c = Dot(f, f) - sphereRadius * sphereRadius;

	Float		d = b * b - 4 * a * c;

	if (d < 0.0 || a == 0.0)
		return false;							// No intersection

	d = Sqrt(d);
	a *= 2.0;

	Float t1 = (-b - d) / a;
	Float t2 = (-b + d) / a;

	if (intersection1)
		*intersection1 = t1;

	if (intersection2)
		*intersection2 = t2;

	if (hitPoint1)
		*hitPoint1 = linePoint1 + e * t1;

	if (hitPoint2)
		*hitPoint2 = linePoint1 + e * t2;

	return true;
}

Bool CircleLineIntersection(const Vector &linePoint1, const Vector &linePoint2, const Vector &circleCenter, Float circleRadius, Float *intersection1, Float *intersection2, Vector *hitPoint1, Vector *hitPoint2)
{
	Float offset1, offset2;
	Bool result = SphereLineIntersection(Vector(linePoint1.x, linePoint1.y, 0.0), Vector(linePoint2.x, linePoint2.y, 0.0), Vector(circleCenter.x, circleCenter.y, 0.0), circleRadius, &offset1, &offset2, nullptr, nullptr);

	if (!intersection1 && !intersection2 && !hitPoint1 && !hitPoint2)
		return result;

	Vector e = linePoint2 - linePoint1;

	if (intersection1)
		*intersection1 = offset1;

	if (intersection2)
		*intersection2 = offset2;

	if (hitPoint1)
		*hitPoint1 = linePoint1 + offset1 * e;

	if (hitPoint2)
		*hitPoint2 = linePoint1 + offset2 * e;

	return result;
}

Bool SphereSegmentIntersection(const Vector &linePoint1, const Vector &linePoint2, const Vector &sphereCenter, Float sphereRadius, maxon::BaseArray<SegmentSphereIntersectionData> &intersections)
{
	Float offset1, offset2;
	Vector hitPoint1, hitPoint2;
	if (!SphereLineIntersection(linePoint1, linePoint2, sphereCenter, sphereRadius, &offset1, &offset2, &hitPoint1, &hitPoint2))
		return false;

	if (offset1 >= 0.0 && offset1 <= 1.0 && intersections.Append(SegmentSphereIntersectionData(offset1, hitPoint1)) == maxon::FAILED)
		return false;
	if (offset2 >= 0.0 && offset2 <= 1.0 && intersections.Append(SegmentSphereIntersectionData(offset2, hitPoint2)) == maxon::FAILED)
		return false;

	return (offset1 >= 0.0 && offset1 <= 1.0) || (offset2 >= 0.0 && offset2 <= 1.0);
}

Bool CircleSegmentIntersection(const Vector &linePoint1, const Vector &linePoint2, const Vector &circleCenter, Float circleRadius, maxon::BaseArray<SegmentSphereIntersectionData> &intersections)
{
	Float offset1, offset2;
	if (!SphereLineIntersection(Vector(linePoint1.x, linePoint1.y, 0.0), Vector(linePoint2.x, linePoint2.y, 0.0), Vector(circleCenter.x, circleCenter.y, 0.0), circleRadius, &offset1, &offset2, nullptr, nullptr))
		return false;

	Vector hitPoint1, hitPoint2;
	Vector e = linePoint2 - linePoint1;

	hitPoint1 = linePoint1 + offset1 * e;
	hitPoint2 = linePoint1 + offset2 * e;

	if (offset1 >= 0.0 && offset1 <= 1.0 && intersections.Append(SegmentSphereIntersectionData(offset1, hitPoint1)) == maxon::FAILED)
		return false;
	if (offset2 >= 0.0 && offset2 <= 1.0 && intersections.Append(SegmentSphereIntersectionData(offset2, hitPoint2)) == maxon::FAILED)
		return false;

	return (offset1 >= 0.0 && offset1 <= 1.0) || (offset2 >= 0.0 && offset2 <= 1.0);
}

#ifndef __API_INTERN__

Vector	CalcSplinePoint(Float offset, SPLINETYPE type, Bool closed, Int32 pcnt, const Vector *padr, const Tangent *tadr /*= nullptr*/)
{
	return C4DOS.Bo->SpCalcSplinePoint(offset, type, closed, pcnt, padr, tadr);
}

Vector	CalcSplineTangent(Float offset, SPLINETYPE type, Bool closed, Int32 pcnt, const Vector *padr, const Tangent *tadr /*= nullptr*/)
{
	return C4DOS.Bo->SpCalcSplineTangent(offset, type, closed, pcnt, padr, tadr);
}

void CalcSplineInsert(Float offset, SPLINETYPE type, Bool closed, Int32 pcnt, const Vector *padr, const Tangent *tadr, Int32 &pointIndex, Vector &resultPoint, Tangent &resultTangent, Vector &leftTangent, Vector &rightTangent)
{
	C4DOS.Bo->SpCalcSplineInsert(offset, type, closed, pcnt, padr, tadr, pointIndex, resultPoint, resultTangent, leftTangent, rightTangent);
}

Tangent TransformTangent(const Vector& newPos, const Vector& planeNormal, const Vector& position, const Tangent& tangent, TANGENTSIDE tangentSide, TANGENTTRANSFORMFLAG flags)
{
	return C4DOS.Bo->SpTransformTangent(newPos, planeNormal, position, tangent, tangentSide, flags);
}

void CalcSplineMovement(const Vector& newPos, Float offset, SPLINETYPE type, const Matrix& splineMg, BaseDraw* bd, const Vector& planeNormal, Bool closed, Bool lockTangentAngle, Bool lockTangentLength, BREAKTANGENTS breakTangents, Int32 pcnt, Vector* padr, Tangent* tadr)
{
	C4DOS.Bo->SpCalcSplineMovement(newPos, offset, type, splineMg, bd, planeNormal, closed, lockTangentAngle, lockTangentLength, breakTangents, pcnt, padr, tadr);
}

SplineObject* BooleanSplines(SplineObject* initialSpline, AtomArray* booleanObjects, BaseDocument *doc, BaseDraw* bd, SPLINEBOOL_AXIS projectionAxis, SPLINEBOOL_MODE booleanMode)
{
	return C4DOS.Bo->SpBooleanSplines(initialSpline, booleanObjects, doc, bd, projectionAxis, booleanMode);
}

Bool CalcSplineDefaultTangents(SPLINETYPE type, Bool closed, Int32 pcnt, const Vector* padr, Tangent* tadr)
{
	return C4DOS.Bo->SpCalcSplineDefaultTangents(type, closed, pcnt, padr, tadr);
}

VolumeData* VolumeData::Alloc(void)
{
	return C4DOS.Sh->AllocVolumeData();
}

void VolumeData::Free(VolumeData*& vd)
{
	C4DOS.Sh->FreeVolumeData(vd);
	vd = nullptr;
}

TexData* TexData::Alloc(void)
{
	return C4DOS.Sh->AllocTexData();
}

void TexData::Free(TexData*& vd)
{
	C4DOS.Sh->FreeTexData(vd);
	vd = nullptr;
}

void TexData::Init(void)
{
	C4DOS.Sh->InitTexData(this);
}

Int32 VPBuffer::GetInfo(VPGETINFO type) const
{
	return C4DOS.Sh->VPGetInfo(this, type);
}

Bool VPBuffer::GetLine(Int32 x, Int32 y, Int32 cnt, void* data, Int32 bitdepth, Bool dithering) const
{
	return C4DOS.Sh->VPGetLine(this, x, y, cnt, data, bitdepth, dithering);
}

Bool VPBuffer::SetLine(Int32 x, Int32 y, Int32 cnt, void* data, Int32 bitdepth, Bool dithering) const
{
	return C4DOS.Sh->VPSetLine(this, x, y, cnt, data, bitdepth, dithering);
}

Bool Render::AllocateBuffer(Int32 id, Int32 subid, Int32 bitdepth, Bool visible)
{
	return C4DOS.Sh->VPAllocateBuffer(this, id, subid, bitdepth, visible);
}

Int32 Render::AllocateBufferFX(Int32 id, const maxon::String& name, Int32 bitdepth, Bool visible)
{
	return C4DOS.Sh->VPAllocateBufferFX(this, id, name, bitdepth, visible);
}

void Render::IccConvert(void* data, Int32 xcnt, Int32 components, Bool inverse)
{
	C4DOS.Sh->VPIccConvert(this, data, xcnt, components, inverse);
}

VPBuffer* Render::GetBuffer(Int32 id, Int32 subid) const
{
	return C4DOS.Sh->VPGetBuffer(this, id, subid);
}

BaseContainer Render::GetRenderData() const
{
	BaseContainer bc;
	C4DOS.Sh->VPGetRenderData(this, &bc);
	return bc;
}

void Render::SetRenderData(const BaseContainer& ct)
{
	C4DOS.Sh->VPSetRenderData(this, &ct);
}

VolumeData* Render::GetInitialVolumeData(Int32 cpu) const
{
	return C4DOS.Sh->VPGetInitialVolumeData(this, cpu);
}

BaseDraw* Render::GetBaseDraw() const
{
	return C4DOS.Sh->VPGetBaseDraw(this);
}

Bool Render::SetRenderProperty(Int32 id, const GeData& dat)
{
	return C4DOS.Sh->SetRenderProperty(this, id, dat);
}

RayObject* AllocRayObject(Int32 tex_cnt)
{
	return C4DOS.Sh->AllocRayObject(tex_cnt, nullptr);
}

void FreeRayObject(RayObject*& op)
{
	C4DOS.Sh->FreeRayObject(op);
	op = nullptr;
}

RayLight* AllocRayLight(BaseDocument* doc, BaseObject* op)
{
	return C4DOS.Sh->AllocRayLight(doc, op);
}

void FreeRayLight(RayLight*& lgt)
{
	C4DOS.Sh->FreeRayLight(lgt);
	lgt = nullptr;
}

Bool IlluminateRayLight(RayLight* rl, Vector* color, Vector64* light_vector, const Vector64& p, const Vector64& n)
{
	return C4DOS.Sh->Illuminate(nullptr, rl, color, light_vector, p, n, n, n, Vector64(0.0), ILLUMINATEFLAGS::NONE, RayHitID(), RAYBIT::NONE, false, nullptr);
}

void CalcRestrictionInc(const ObjectRestriction* lr, const RayObject* op, Bool& nodif, Bool& nospec)
{
	if (!op || !op->link || op->restriction_index >= lr->object_cnt)
		return;
	if (lr->object[op->restriction_index] & LIGHTRESTRICTION_NODIFFUSE)
		nodif = true;
	if (lr->object[op->restriction_index] & LIGHTRESTRICTION_NOSPECULAR)
		nospec = true;
}

BAKE_TEX_ERR BakeTexture(BaseDocument* doc, const BaseContainer& data, BaseBitmap* bmp, BaseThread* th, BakeProgressHook* hook, BakeProgressInfo* info)
{
	return C4DOS.Sh->BakeTexture(doc, data, bmp, th, hook, info);
}

BaseDocument* InitBakeTexture(BaseDocument* doc, TextureTag* textag, UVWTag* texuvw, UVWTag* destuvw, const BaseContainer& bc, BAKE_TEX_ERR* err, BaseThread* th)
{
	return C4DOS.Sh->InitBakeTexture(doc, textag, texuvw, destuvw, bc, err, th);
}

BaseDocument* InitBakeTexture(BaseDocument* doc, TextureTag** textags, UVWTag** texuvws, UVWTag** destuvws, Int32 cnt, const BaseContainer& bc, BAKE_TEX_ERR* err, BaseThread* th)
{
	return C4DOS.Sh->InitBakeTextureA(doc, textags, texuvws, destuvws, cnt, bc, err, th);
}

Float PointLineSegmentDistance(const Vector &segmentPoint1, const Vector &segmentPoint2, const Vector &pos, Vector *intersectionPoint, Float *lineOffset)
{
	Vector v = segmentPoint2 - segmentPoint1;

	Float vl = v.GetLength();
	if (vl == 0.0)
	{
		if (intersectionPoint)
			*intersectionPoint = segmentPoint1;
		if (lineOffset)
			*lineOffset = 0.0;
		return (pos - segmentPoint1).GetLength();
	}

	v = v / vl;

	Float d = Dot(pos - segmentPoint1, v);

	if (d <= 0.0)
	{
		if (intersectionPoint)
			*intersectionPoint = segmentPoint1;
		if (lineOffset)
			*lineOffset = 0.0;
		return (pos - segmentPoint1).GetLength();
	}
	else if (d >= vl)
	{
		if (intersectionPoint)
			*intersectionPoint = segmentPoint2;
		if (lineOffset)
			*lineOffset = 1.0;
		return (pos - segmentPoint2).GetLength();
	}

	Vector pp = segmentPoint1 + v*d;

	if (intersectionPoint)
		*intersectionPoint = pp;
	if (lineOffset)
		*lineOffset = d / vl;

	return (pp - pos).GetLength();
}

Float PointLineSegmentDistance2D(const Vector &segmentPoint1, const Vector &segmentPoint2, const Vector &pos, Vector *intersectionPoint, Float *lineOffset)
{
	Vector v = Vector(segmentPoint2.x, segmentPoint2.y, 0.0) - Vector(segmentPoint1.x, segmentPoint1.y, 0.0);

	Float vl = v.GetLength();
	if (vl == 0.0)
	{
		if (intersectionPoint)
			*intersectionPoint = segmentPoint1;
		if (lineOffset)
			*lineOffset = 0.0;
		return (pos - segmentPoint1).GetLength();
	}

	v = v / vl;

	Float d = Dot(Vector(pos.x - segmentPoint1.x, pos.y - segmentPoint1.y, 0.0), v);

	if (d <= 0.0)
	{
		if (intersectionPoint)
			*intersectionPoint = segmentPoint1;
		if (lineOffset)
			*lineOffset = 0.0;
		return (Vector(pos.x - segmentPoint1.x, pos.y - segmentPoint1.y, 0.0)).GetLength();
	}
	else if (d >= vl)
	{
		if (intersectionPoint)
			*intersectionPoint = segmentPoint2;
		if (lineOffset)
			*lineOffset = 1.0;
		return (Vector(pos.x - segmentPoint2.x, pos.y - segmentPoint2.y, 0.0)).GetLength();
	}

	Vector pp = segmentPoint1 + ((segmentPoint2 - segmentPoint1) / vl) * d;

	if (intersectionPoint)
		*intersectionPoint = pp;
	if (lineOffset)
		*lineOffset = d / vl;

	return (Vector(pp.x - pos.x, pp.y - pos.y, 0.0)).GetLength();
}

GeCipher256::GeCipher256()
{
	hnd = nullptr;
}

GeCipher256::~GeCipher256()
{
	if (hnd)
		Close();
}

Bool GeCipher256::Open(const void* key, Int32 klength, Bool stream)
{
	if (hnd)
		Close();
	hnd = C4DOS.Ge->GeCipher256Open((const UChar*)key, klength, stream);
	return hnd != nullptr;
}

void GeCipher256::Close()
{
	if (hnd)
	{
		C4DOS.Ge->GeCipher256Close(hnd);
		hnd = nullptr;
	}
}

void GeCipher256::Encrypt(void* mem, Int32 bytes)
{
	if (hnd)
		C4DOS.Ge->GeCipher256Encrypt(hnd, (UChar*)mem, bytes);
}

void GeCipher256::Decrypt(void* mem, Int32 bytes)
{
	if (hnd)
		C4DOS.Ge->GeCipher256Decrypt(hnd, (UChar*)mem, bytes);
}

Int32 InitRenderStruct::GetThreadCount() const
{
	return vd ? vd->GetCPUCount() : 1;
}

void InitRenderStruct::Init(BaseDocument* t_doc)
{
	version = GetC4DVersion();
	doc = t_doc;
	errorlist = nullptr;
	matname = nullptr;
	vd = nullptr;
	thread = nullptr;
	flags	 = INITRENDERFLAG::TEXTURES;
	linear_workflow = false;
	document_colorprofile = DOCUMENT_COLORPROFILE_SRGB;

	if (t_doc)
	{
		docpath = t_doc->GetDocumentPath();
		fps	 = t_doc->GetFps();
		time = t_doc->GetTime();

		BaseContainer* bc = t_doc->GetDataInstance();
		if (bc)
		{
			linear_workflow = bc->GetBool(DOCUMENT_LINEARWORKFLOW);
			document_colorprofile = bc->GetInt32(DOCUMENT_COLORPROFILE);
		}
	}
	else
	{
		fps = 30;
	}
}
#endif
