#ifndef POLYNOMSOLVER_H__
#define POLYNOMSOLVER_H__

#include "maxon/complex.h"

// enable warnings
#ifdef _WIN32
	#pragma warning(push)
	#pragma warning(default:4244)
	#pragma warning(default:4305)
#endif

#define MAXN 7

// to fix an evil intel compiler optimization bug
#ifdef MAXON_TARGET_WINDOWS
	#define NOINLINE __declspec(noinline)
#else
	#define NOINLINE
#endif

namespace maxon
{
/// @addtogroup MATH
/// @{

/// Each function uses the followig format: a*x^(n) + b*x^(n-1) + ... = 0
/// Return value is the number of real solutions.
/// All results are stored in x. This array must have at least n elements.
/// If the imaginary part of a complex number is between -epsilon and epsilon the number is treated as a real number.

// T should be Float or Float64
template <typename T> class PolynomSolver
{
public:
	PolynomSolver();
	Int32 SolveLinear(T a, T b, T* x);
	Int32 Solve2(T a, T b, T c, T* x, T epsilon = 1e-5);
	Int32 Solve2(T a, T b, T c, Complex<T>* x);
	Int32 Solve3(T a, T b, T c, T d, T* x, T epsilon = 1e-5);
	Int32 Solve3(T a, T b, T c, T d, Complex<T>* x);
	Int32 Solve4(T a, T b, T c, T d, T e, T* x, T epsilon = 1e-5);
	Int32 Solve4(T a, T b, T c, T d, T e, Complex<T>* x);

	// n must be < MAXN, coeff[n] = a
	Int32 SolveN(Int32 n, Complex<T>* coeff, Complex<T>* x, Bool polish = true, Int32 maxiter = 80);
	static T GetComplexAbs(const Complex<T>& c);
	static Bool ComplexIsReal(const Complex<T>& c, T eps = 1e-4);

private:
	inline T Sqr(T d) { return d * d; }
	inline T Cub(T d) { return d * d * d; }
	inline T Sqrt3(T x) { return (x <= 0) ? -Pow(-x, T(1.0) / T(3.0)) : Pow(x, T(1.0) / T(3.0)); }

	NOINLINE void Laguer(Complex64 a[], Int32 m, Complex64& x, Int32& its);

	Complex<T> rho1, rho2;
};

/// @}

template <typename T> PolynomSolver<T>::PolynomSolver() :
rho1(-0.5, 0.86602540378443864676372317075294), // -1/2 + 1/2*sqrt(3)*i
rho2(-0.5, -0.86602540378443864676372317075294) // -1/2 - 1/2*sqrt(3)*i
{
}

template <typename T> T PolynomSolver<T>::GetComplexAbs(const Complex<T>& c)
{
	T x, y, ans, temp;
	x = Abs(c.real);
	y = Abs(c.imag);
	if (x == 0)
	{
		ans = y;
	}
	else if (y == 0)
	{
		ans = x;
	}
	else if (x > y)
	{
		temp = y / x;
		ans	 = x * Sqrt(T(1.0) + temp * temp);
	}
	else
	{
		temp = x / y;
		ans	 = y * Sqrt(T(1.0) + temp * temp);
	}
	return ans;
}

template <typename T> Bool PolynomSolver<T>::ComplexIsReal(const Complex<T>& c, T eps)
{
	return -eps < c.imag && c.imag < eps;
}

template <typename T> Int32 PolynomSolver<T>::SolveLinear(T a, T b, T* x)
{
	if (a == 0)
		return 0;
	x[0] = -b / a;
	return 1;
}

template <typename T> Int32 PolynomSolver<T>::Solve2(T a, T b, T c, Complex<T>* x)
{
	if (a == 0)
	{
		if (b != 0.0)
			x[0] = -c / b;
		else
			x[0] = 0.0;
		return 1;
	}
	T p = b / a;
	T q = c / a;
	T D = Sqr(p) / 4.0 - q;
	if (D > 0.0)
	{
		D = Sqrt(D);
		p = -p / 2.0;
		x[0] = p + D;
		x[1] = p - D;
		return 2;
	}
	else if (D == 0)
	{
		x[0] = -p / 2.0;
		return 1;
	}
	else
	{
		Complex<T> cd = sqrt(Complex<T>(D));
		p = -p / 2.0;
		x[0] = p + cd;
		x[1] = p - cd;
		return 2;
	}
	return 0;
}

template <typename T> Int32 PolynomSolver<T>::Solve2(T a, T b, T c, T* x, T epsilon)
{
	if (Abs(a) < 1e-10)
	{
		if (b != 0.0)
			x[0] = -c / b;
		else
			x[0] = 0.0;
		return 1;
	}

	T p = b / a;
	T q = c / a;
	T D = Sqr(p) / 4.0 - q;
	if (D > 0.0)
	{
		D = Sqrt(D);
		p = -p / T(2.0);
		x[0] = p + D;
		x[1] = p - D;
		return 2;
	}
	else if (D == 0)
	{
		x[0] = -p / 2.0;
		return 1;
	}

	// no real solution
	return 0;
}



template <typename T> Int32 PolynomSolver<T>::Solve3(T a, T b, T c, T d, T* x, T epsilon)
{
	if (Abs(a) < 1e-10)
		return Solve2(b, c, d, x, epsilon);

	T r = b / a;
	T s = c / a;
	T t = d / a;

	T p = (3 * s - Sqr(r)) / 3.0;
	T q = 2 * Cub(r) / 27.0 - r * s / 3.0 + t;
	T D = Cub(p / 3.0) + Sqr(q / 2.0);
	T phi;
	if (D < 0)
	{
		// 3 pairs of different real solutions
		t = Sqrt(-Cub(p / T(3.0)));
		phi = ACos(-q / (T(2.0) * t)) / 3.0;
		t = 2 * Sqrt3(t);
		r = r / 3.0;
		x[0] = t * Cos(phi) - r;
		x[1] = t * Cos(phi + T(2.0) * T(PI) / T(3.0)) - r;
		x[2] = t * Cos(phi + T(4.0) * T(PI) / T(3.0)) - r;
		return 3;
	}

	T u = Sqrt3(-.5 * q + Sqrt(D));
	T v = Sqrt3(-.5 * q - Sqrt(D));
	r = r / 3.0;
	Int32 n = 1;
	x[0] = u + v - r;
	Complex<T> xd(rho1 * u + rho2 * v);
	if (ComplexIsReal(xd))
	{
		x[1] = xd.real - r;
		return 2;
	}

	return n;
}

template <typename T> Int32 PolynomSolver<T>::Solve3(T a, T b, T c, T d, Complex<T>* x)
{
	if (a == 0)
		return Solve2(b, c, d, x);

	T r = b / a;
	T s = c / a;
	T t = d / a;

	T p = (3 * s - Sqr(r)) / 3.0;
	T q = 2 * Cub(r) / 27.0 - r * s / 3.0 + t;
	T D = Cub(p / 3.0) + Sqr(q / 2.0);
	T phi;
	if (D < 0)
	{
		// 3 pairs of different real solutions
		t = Sqrt(-Cub(p / T(3.0)));
		phi = ACos(-q / (T(2.0) * t)) / 3.0;
		t = 2 * Sqrt3(t);
		r = r / 3.0;
		x[0] = t * Cos(phi) - r;
		x[1] = t * Cos(phi + T(2.0) * T(PI) / T(3.0)) - r;
		x[2] = t * Cos(phi + T(4.0) * T(PI) / T(3.0)) - r;
		return 3;
	}
	else
	{
		T u = Sqrt3(-.5 * q + Sqrt(D));
		T v = Sqrt3(-.5 * q - Sqrt(D));
		r = r / 3.0;
		x[0] = u + v - r;
		x[1] = u * rho1 + v * rho2 - r;
		x[2] = u * rho2 + v * rho1 - r;
		return 3;
	}
	return 0;
}

template <typename T> Int32 PolynomSolver<T>::Solve4(T a, T b, T c, T d, T e, T* x, T epsilon)
{
	if (a == 0)
		return Solve3(b, c, d, e, x, epsilon);

	T u = b / a;
	T v = c / a;
	T w = d / a;
	T y = e / a;
	T p = v - 3.0 / 8.0 * Sqr(u);
	T q = w - u * v * .5 + Cub(u) * .125;
	T r = y - u * w * .25 + u * u * v / 16.0 - 3.0 * u * u * u * u / 256.0;
	Complex<T> z[3];
	Int32					n = Solve3(1.0, 2.0 * p, p * p - 4.0 * r, -q * q, z);
	DebugAssert(n == 3);
	Complex<T> w1 = pow(z[0], .5);
	Complex<T> w2 = pow(z[1], .5);
	Complex<T> w3 = pow(z[2], .5);

	n = 0;
	u = u * .25;
	Complex<T> cw((w1 + w2 + w3) * .5 - u);
	if (ComplexIsReal(cw, epsilon))
		x[n++] = cw.r;
	cw = (w1 - w2 - w3) * .5 - u;
	if (ComplexIsReal(cw, epsilon))
		x[n++] = cw.r;
	cw = (-w1 + w2 - w3) * .5 - u;
	if (ComplexIsReal(cw, epsilon))
		x[n++] = cw.r;
	cw = (-w1 - w2 + w3) * .5 - u;
	if (ComplexIsReal(cw, epsilon))
		x[n++] = cw.r;
	return n;
}

template <typename T> Int32 PolynomSolver<T>::Solve4(T a, T b, T c, T d, T e, Complex<T>* x)
{
	if (a == 0)
		return Solve3(b, c, d, e, x);
	T u = b / a;
	T v = c / a;
	T w = d / a;
	T y = e / a;
	T p = v - 3.0 / 8.0 * Sqr(u);
	T q = w - u * v * .5 + Cub(u) * .125;
	T r = y - u * w * .25 + u * u * v / 16.0 - 3.0 * u * u * u * u / 256.0;
	Complex<T> z[3];
	DebugAssert(Solve3(1.0, 2.0 * p, p * p - 4.0 * r, -q * q, z) == 3);
	Complex<T> w1 = pow(z[0], .5);
	Complex<T> w2 = pow(z[1], .5);
	Complex<T> w3 = pow(z[2], .5);

	u = u * .25;
	x[0] = (w1 + w2 + w3) * .5 - u;
	x[1] = (w1 - w2 - w3) * .5 - u;
	x[2] = (-w1 + w2 - w3) * .5 - u;
	x[3] = (-w1 - w2 + w3) * .5 - u;
	return 4;
}


static const Float EPSS = 1.0e-7_f;
static const Int MR = 8;
static const Int MT = 10;
static const Int MAXIT = (MR * MT);

static const Float EPS = 2.0e-6_f;


template <typename T> NOINLINE void PolynomSolver<T>::Laguer(Complex64 a[], Int32 m, Complex64& x, Int32& its)
{
	Int32					iter, j;
	T					abx, abp, abm, err;
	Complex<T> dx, x1, b, d, f, g, h, sq, gp, gm, g2;
	static T		frac[MR + 1] = { 0.0, 0.5, 0.25, 0.75, 0.13, 0.38, 0.62, 0.88, 1.0 };

	for (iter = 1; iter <= MAXIT; iter++)
	{
		its = iter;
		b = a[m];
		err = GetComplexAbs(b);
		d = f = Complex64(0, 0);
		abx = GetComplexAbs(x);

		for (j = m - 1; j >= 0; j--)
		{
			f = (x * f) + d;
			d = (x * d) + b;
			b = (x * b) + a[j];
			err = GetComplexAbs(b) + abx * err;
		}
		err *= EPSS;

		if (GetComplexAbs(b) <= err)
			return;

		g		= d / b;
		g2	= g * g;
		h		= g2 - (f * 2 / b);
		sq	= sqrt(((h * Float64(m)) - g2) * Float64(m - 1));
		gp	= g + sq;
		gm	= g - sq;
		abp = GetComplexAbs(gp);
		abm = GetComplexAbs(gm);
		if (abp < abm)
			gp = gm;
		dx = FMax(abp, abm) > 0.0 ? (Complex<T>((Float64)m, 0) / gp) : Complex<T>(Cos(T(iter)), Sin(T(iter))) * (1.0 + abx);
		x1 = x - dx;
		if (x.real == x1.r && x.imag == x1.imag)
			return;
		if (iter % MT)
			x = x1;
		else
			x = x - (dx * frac[iter / MT]);
	}
	return;
}

template <typename T> Int32 PolynomSolver<T>::SolveN(Int32 m, Complex<T>* coeff, Complex<T>* roots, Bool polish, Int32 maxiter)
{
	// m must be < MAXN
	DebugAssert(m < MAXN);

	Int32		 its, j, jj;
	Complex64 x, b, c, ad[MAXN];

	for (j = 0; j <= m; j++)
		ad[j] = coeff[j];
	for (j = m; j >= 1; j--)
	{
		x = Complex64(0, 0);
		Laguer(ad, j, x, its);
		if (Abs(x.imag) <= 2.0 * EPS * Abs(x.real))
			x.imag = 0.0;
		roots[j - 1] = x;
		b = ad[j];
		for (jj = j - 1; jj >= 0; jj--)
		{
			c = ad[jj];
			ad[jj] = b;
			b = (x * b) + c;
		}
	}
	if (polish)
	{
		for (j = 1; j <= m; j++)
			Laguer(coeff, m, roots[j - 1], its);
	}

	return m;
}

} // namespace maxon

// restore warnings to original state
#ifdef _WIN32
#pragma warning(pop)
#endif


#endif	// POLYNOMSOLVER_H__
