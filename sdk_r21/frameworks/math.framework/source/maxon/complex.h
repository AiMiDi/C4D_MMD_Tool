#ifndef COMPLEX_H__
#define COMPLEX_H__

#include "maxon/lib_math.h"
#include "maxon/apibase.h"
#include "maxon/string.h"
#include "maxon/datatype.h"
#include "maxon/dataserialize.h"

namespace maxon
{
/// @addtogroup MATH
/// @{

/// A complex number is a number that can be expressed in the form a + bi, where a and b are real numbers and i is the imaginary unit,
/// that satisfies the equation x2 = -1, that is, i2 = -1.[1] In this expression, a is the real part and b is the imaginary part of the complex number.
///
/// Complex numbers extend the concept of the one-dimensional number line to the two-dimensional complex plane by using the horizontal axis for the real part
/// and the vertical axis for the imaginary part. The complex number a + bi can be identified with the point (a, b) in the complex plane.
/// A complex number whose real part is zero is said to be purely imaginary, whereas a complex number whose imaginary part is zero is a real number.
/// In this way, the complex numbers contain the ordinary real numbers while extending them in order to solve problems that cannot be solved with real numbers alone.
///
/// Examples for using complex numbers are the famous Mandelbrot set or the Fourier Transform of a signal.
/// In the latter case the imaginary part stores the phase information.
template <typename T> class Complex
{
public:
	//-------------------------------------------------------------------------------------------------------------
	//                               constructors
	//-------------------------------------------------------------------------------------------------------------

	/// Creates a Complex initialized with default values (all components 0.0).
	Complex();

	/// Creates a Complex initialized with given real and default ( = 0.0) imaginary values.
	MAXON_IMPLICIT Complex(const T real);

	/// Creates a Complex initialized with given real and imaginary values.
	MAXON_IMPLICIT Complex(const T real, const T imag);


	//-------------------------------------------------------------------------------------------------------------
	//                               operators
	//-------------------------------------------------------------------------------------------------------------

	/// Adds two Complex numbers.
	const Complex& operator +=(const Complex& c);

	/// Subtracts two Complex numbers.
	const Complex& operator -=(const Complex& c);

	/// Multiplies two Complex operations.
	const Complex& operator *=(const Complex& c);

	/// Adds two Complex numbers.
	Complex operator +(const Complex& c) const;

	/// Subtracts two Complex numbers.
	Complex operator -(const Complex& c) const;

	/// Multiplies two Complex numbers.
	Complex operator *(const Complex& c) const;

	/// Scales the Complex.
	Complex operator *(const T s) const;

	/// Scales the components of a Complex.
	friend Complex operator *(const T s, const Complex& c)
	{
		Complex<T> r;
		r.real = c.real * s;
		r.imag = c.imag * s;
		return r;
	}


	//-------------------------------------------------------------------------------------------------------------
	//                               set values
	//-------------------------------------------------------------------------------------------------------------

	/// Set polar length (magnitude) in the Argand plane.
	void SetLength(const T len);

	/// Set polar phase (angle) in the Argand plane.
	void SetPhase(const T phase);

	/// Initialize Complex number by given polar coordinates.
	void SetPolar(const T len, const T phase);

	/// set Complex number according to e^(i*x)
	void SetExp(const T x);


	//-------------------------------------------------------------------------------------------------------------
	//                               get values
	//-------------------------------------------------------------------------------------------------------------

	//----------------------------------------------------------------------------------------
	/// Computes the squared magnitude/length/norm in the Argand plane.
	/// @return												length
	//----------------------------------------------------------------------------------------
	T GetSquaredLength() const;

	//----------------------------------------------------------------------------------------
	/// Computes the magnitude/length/norm in the Argand plane.
	/// @return												length
	//----------------------------------------------------------------------------------------
	T GetLength() const;

	//----------------------------------------------------------------------------------------
	/// Computes the angle of the complex vector in the Argand plane.
	/// @return												phase
	//----------------------------------------------------------------------------------------
	T GetPhase() const;

	//----------------------------------------------------------------------------------------
	/// Get a complex vector with normalized length in the Argand plane.
	/// @return												normalized complex vector
	//----------------------------------------------------------------------------------------
	Complex GetNormalized() const;

	//----------------------------------------------------------------------------------------
	/// Get the complex conjugate of a complex vector
	/// @return												complex conjugate
	//----------------------------------------------------------------------------------------
	Complex GetConjugate() const;

	//----------------------------------------------------------------------------------------
	/// Compute the square root.
	/// @return												square root of vector
	//----------------------------------------------------------------------------------------
	Complex GetSqrt() const;

	//----------------------------------------------------------------------------------------
	/// Compute the natural logarithm.
	/// @return												Log of complex vector. Returns an error if length of vector is zero
	//----------------------------------------------------------------------------------------
	Result<Complex> GetLog() const;

	//----------------------------------------------------------------------------------------
	/// Divides the complex value by another complex value.
	/// @param[in] divisor						divisor
	/// @return												The divided result. Returns an error if divisor is zero.
	//----------------------------------------------------------------------------------------
	Result<Complex> GetDivision(const Complex& divisor) const;

	//----------------------------------------------------------------------------------------
	/// Returns a readable string of the content.
	/// @param[in] formatStatement		Nullptr or additional formatting instruction. See also @ref format_float.
	/// @return												The converted result.
	//----------------------------------------------------------------------------------------
	String ToString(const FormatStatement* formatStatement) const;


	//-------------------------------------------------------------------------------------------------------------
	//                               functions
	//-------------------------------------------------------------------------------------------------------------

	//----------------------------------------------------------------------------------------
	/// Describe all elements of this class for I/O operations.
	/// @param[in] stream							The stream that is used to register the class members.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	static Result<void> DescribeIO(const DataSerializeInterface& stream);

	MAXON_OPERATOR_EQUALITY_HASHCODE(Complex, real, imag);

public:
	T real; ///< real part
	T imag; ///< imaginary part
};

/// @}

// ------------------------------  implementation -----------------------------------
template <typename T> Complex<T>::Complex()
{
	real = T(0.0);
	imag = T(0.0);
}

template <typename T> Complex<T>::Complex(const T _real)
{
	real = _real;
	imag = T(0.0);
}

template <typename T> Complex<T>::Complex(const T _real, const T _imag)
{
	real = _real;
	imag = _imag;
}

template <typename T> const Complex<T>& Complex<T>::operator +=(const Complex& c)
{
	real += c.real;
	imag += c.imag;

	return *this;
}

template <typename T> const Complex<T>& Complex<T>::operator -=(const Complex& c)
{
	real -= c.real;
	imag -= c.imag;

	return *this;
}

template <typename T> const Complex<T>& Complex<T>::operator *=(const Complex& c)
{
	T nr = real * c.real - imag * c.imag;
	T ni = imag * c.real + real * c.imag;

	real = nr;
	imag = ni;

	return *this;
}

template <typename T> Complex<T> Complex<T>::operator +(const Complex& c2) const
{
	Complex<T> r;

	r.real = real + c2.real;
	r.imag = imag + c2.imag;

	return r;
}

template <typename T> Complex<T> Complex<T>::operator -(const Complex& c2) const
{
	Complex<T> r;

	r.real = real - c2.real;
	r.imag = imag - c2.imag;

	return r;
}

template <typename T> Complex<T> Complex<T>::operator *(const Complex& c) const
{
	Complex<T> r;

	r.real = real * c.real - imag * c.imag;
	r.imag = imag * c.real + real * c.imag;

	return r;
}

template <typename T> Complex<T> Complex<T>::operator *(const T s) const
{
	Complex<T> r;

	r.real = real * s;
	r.imag = imag * s;

	return r;
}

template <typename T> void Complex<T>::SetLength(const T len)
{
	T ph = GetPhase();

	SetPolar(len, ph);
}

template <typename T> void Complex<T>::SetPhase(const T phase)
{
	SetPolar(GetLength(), phase);
}

template <typename T> void Complex<T>::SetPolar(const T len, const T phase)
{
	real = len * Cos(phase);
	imag = len * Sin(phase);
}

template <typename T> void Complex<T>::SetExp(const T x)
{
	real = Cos(x);
	imag = Sin(x);
}

template <typename T> T Complex<T>::GetSquaredLength() const
{
	return real * real + imag * imag;
}

template <typename T> T Complex<T>::GetLength() const
{
	return Sqrt(real * real + imag * imag);
}

template <typename T> T Complex<T>::GetPhase() const
{
	return ATan2(imag, real);
}

template <typename T> Complex<T> Complex<T>::GetNormalized() const
{
	Complex<T> cc;
	cc.SetPolar(T(1.0), GetPhase());

	return cc;
}

template <typename T> Complex<T> Complex<T>::GetConjugate() const
{
	return Complex<T>(real, -imag);
}

template <typename T> Complex<T> Complex<T>::GetSqrt() const
{
	T det = GetLength();

	Complex<T> res;
	res.real = Sqrt(0.5 * ( real + det));
	res.imag = Sqrt(0.5 * (-real + det)) * Sign(imag);

	return res;
}

template <typename T> Result<Complex<T>> Complex<T>::GetLog() const
{
	iferr_scope;

	T ph = GetPhase();
	T r  = GetLength();

	if (r <= T(0.0))
		return IllegalStateError(MAXON_SOURCE_LOCATION, "Length of vector in Argand plane is zero."_s);

	Complex<T> res;

	res.real = Ln(r);
	res.imag = ph;

	return res;
}

	template <typename T> Result<Complex<T>> Complex<T>::GetDivision(const Complex& c) const
{
	T div = c.real * c.real + c.imag * c.imag;
	if (div <= T(0.0))
		return IllegalArgumentError(MAXON_SOURCE_LOCATION, "Divisor is zero."_s);

	T nr = (real * c.real + imag * c.imag) / div;
	T ni = (imag * c.real - real * c.imag) / div;

	Complex <T> res;
	
	res.real = nr;
	res.imag = ni;
	
	return res;
}

template <typename T> String Complex<T>::ToString(const FormatStatement* formatStatement) const
{
	return "("_s + maxon::ToString(real, formatStatement) + " + i"_s + maxon::ToString(imag, formatStatement) + ")"_s;
}

template <typename T> Result<void> Complex<T>::DescribeIO(const DataSerializeInterface& stream)
{
	iferr_scope;

	PrepareDescribe(stream, Complex);

	Describe("real", real, T, DESCRIBEFLAGS::NONE) iferr_return;
	Describe("imag", imag, T, DESCRIBEFLAGS::NONE) iferr_return;

	return OK;
}


// ----------------- get real/imag value helper functions --------------------
//----------------------------------------------------------------------------------------
/// Get the real part of a value no matter if this is a Complex or Float value.
/// @param[in] val								input value
/// @return												real value
//----------------------------------------------------------------------------------------
template <typename T> static T ComplexGetReal(const Complex<T>& val) { return val.real; }

//----------------------------------------------------------------------------------------
/// Get the real part of a value no matter if this is a Complex or Float value.
/// @param[in] val								input value
/// @return												real value
//----------------------------------------------------------------------------------------
template <typename T> static T ComplexGetReal(const T& val) { return val; }

//----------------------------------------------------------------------------------------
/// Get the imaginary part of a value no matter if this is a Complex or Float value. In the latter case the function will return 0.0
/// @param[in] val								input value
/// @return												real value
//----------------------------------------------------------------------------------------
template <typename T> static T ComplexGetImag(const Complex<T>& val) {	return val.imag; }

//----------------------------------------------------------------------------------------
/// Get the imaginary part of a value no matter if this is a Complex or Float value. In the latter case the function will return 0.0
/// @param[in] val								input value
/// @return												real value
//----------------------------------------------------------------------------------------
template <typename T> static T ComplexGetImag(const T& val) { return 0.0; }

// ----------------- assign real/imag value to complex value --------------------
//----------------------------------------------------------------------------------------
/// Set the real part of a value no matter if this is a Complex or Float value.
/// @param[in] dst								destination value
/// @param[in] val								real value to be set
//----------------------------------------------------------------------------------------
template <typename T1, typename T2> static void ComplexSetReal(Complex<T1>& dst, const T2& val) { dst.real = (T1) val; }

//----------------------------------------------------------------------------------------
/// Set the real part of a value no matter if this is a Complex or Float value.
/// @param[in] dst								destination value
/// @param[in] val								real value to be set
//----------------------------------------------------------------------------------------
template <typename T1, typename T2> static void ComplexSetReal(T1& dst, const T2& val) { dst = (T1) val; }

//----------------------------------------------------------------------------------------
/// Set the imaginary part of a value no matter if this is a Complex or Float value. In the latter case the function will do nothing
/// @param[in] dst								destination value
/// @param[in] val								imaginary value to be set
//----------------------------------------------------------------------------------------
template <typename T1, typename T2> static void ComplexSetImag(Complex<T1>& dst, const T2& val) { dst.imag = (T1) val; }

//----------------------------------------------------------------------------------------
/// Set the imaginary part of a value no matter if this is a Complex or Float value. In the latter case the function will do nothing
/// @param[in] dst								destination value
/// @param[in] val								imaginary value to be set
//----------------------------------------------------------------------------------------
template <typename T1, typename T2> static void ComplexSetImag(T1& dst, const T2& val) { }



// ---------------------------- data registration ---------------------------------------------------------------------


/// Single-precision complex number.
using Complex32 = Complex<Float32>;

/// Double-precision complex number.
using Complex64 = Complex<Float64>;


MAXON_DATATYPE(Complex32, "net.maxon.datatype.complex32");
MAXON_DATATYPE(Complex64, "net.maxon.datatype.complex64");


} // namespace maxon

#endif // COMPLEX_H__
