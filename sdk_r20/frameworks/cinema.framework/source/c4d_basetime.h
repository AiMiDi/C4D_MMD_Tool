/////////////////////////////////////////////////////////////
// CINEMA 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef C4D_BASETIME_H__
#define C4D_BASETIME_H__

#include "ge_math.h"

//-------------------------------------------------------------------------------------------------
/// @C4D uses a sophisticated system for specifying time values.\n
/// If only frame numbers were used, changing the frame rate would cause keys either to overlap or disappear.\n
/// If only float values (seconds) were used instead, there would be problems because of the limited data precision. For instance when using @em 30 fps the frame @em 29 = @em 29/30 could easily be misinterpreted as frame @em 28.
///
/// BaseTime internally stores the time values as exact fractions independent of the frame rate. For example frame @em 29 is stored as fraction with nominator @em 29 and denominator @em 30.\n
/// The class always tries to keep the nominator and denominator as small as possible. Hence @em 15/@em 30 is stored as @em 1/2, so if using @em 30 fps GetFrame() would return @em 15, but if using @em 24 fps it would return frame @em 12.
//-------------------------------------------------------------------------------------------------
class BaseTime
{
	friend class BaseFile;
	friend class AESFile;

private:
	Float numerator;
	Float denominator;
	void Reduce(void);

public:
	/// @name Constructor/Destructor
	/// @{

	//-------------------------------------------------------------------------------------------------
	/// Default constructor.
	//-------------------------------------------------------------------------------------------------
	BaseTime() { numerator = 0.0; denominator = 1.0; }

	//----------------------------------------------------------------------------------------
	/// Initializes the internal time value from a float value in seconds.\n
	/// Constructor will multiply the seconds by 1000.0 and store it as a fraction with @em 1000.0 as denominator; after this the fraction will be reduced to its lowest form.
	/// @param[in] r									The time in seconds.
	//----------------------------------------------------------------------------------------
	explicit BaseTime(Float r);

	//----------------------------------------------------------------------------------------
	/// Initializes the internal time value to the given fraction of @formatParam{z}/@formatParam{n}.
	/// @param[in] z									The nominator.
	/// @param[in] n									The denominator.
	//----------------------------------------------------------------------------------------
	explicit BaseTime(Float z, Float n);

	/// @}

	/// @name Numerator/Denominator
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets the time in seconds.
	/// @return												The time in seconds.
	//----------------------------------------------------------------------------------------
	Float Get(void) const
	{
		if (denominator == 0.0)
			return 0.0;
		return numerator / denominator;
	}

	//----------------------------------------------------------------------------------------
	/// Gets the numerator part of the internally stored time.
	/// @return												The numerator.
	//----------------------------------------------------------------------------------------
	Float GetNumerator(void) const { return numerator; }

	//----------------------------------------------------------------------------------------
	/// Gets the denominator part of the internally stored time.
	/// @return												The denominator.
	//----------------------------------------------------------------------------------------
	Float GetDenominator(void) const { return denominator; }

	//----------------------------------------------------------------------------------------
	/// Sets the numerator part of the internally stored time.
	/// @param[in] r									The numerator.
	//----------------------------------------------------------------------------------------
	void SetNumerator(Float r) { numerator = r; }

	//----------------------------------------------------------------------------------------
	/// Sets the denominator part of the internally stored time.
	/// @param[in] r									The denominator.
	//----------------------------------------------------------------------------------------
	void SetDenominator(Float r);

	/// @}

	/// @name Frames
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets the number of frames equivalent to the time for the given number of Frames per Second.
	/// @param[in] fps								The Frames per Second to use to calculate the frame number for the time.
	/// @return												The frame number for the time.
	//----------------------------------------------------------------------------------------
	Int32 GetFrame(Float fps) const { return Int32(Floor(numerator * fps) / Floor(denominator)); }

	//----------------------------------------------------------------------------------------
	/// Quantizes the internally stored value so that it is a multiple of the given number of Frames per Second.
	/// @param[in] fps								The number of Frames per Second to make the time a multiple of.
	//----------------------------------------------------------------------------------------
	void Quantize(Float fps);

	/// @}

	/// @name Math Operators
	/// @{

	//----------------------------------------------------------------------------------------
	/// Multiplies @formatParam{t1} and @formatParam{t2}.
	/// @param[in] t1									Left-operand time.
	/// @param[in] t2									Right-operand time.
	/// @return												Result of the multiplication.
	//----------------------------------------------------------------------------------------
	friend const BaseTime operator * (const BaseTime& t1, const BaseTime& t2);

	//----------------------------------------------------------------------------------------
	/// Divides @formatParam{t1} and @formatParam{t2}.
	/// @param[in] t1									Left-operand time.
	/// @param[in] t2									Right-operand time.
	/// @return												Result of the division.
	//----------------------------------------------------------------------------------------
	friend const BaseTime operator / (const BaseTime& t1, const BaseTime& t2);

	//----------------------------------------------------------------------------------------
	/// Adds @formatParam{t1} and @formatParam{t2}.
	/// @param[in] t1									Left-operand time.
	/// @param[in] t2									Right-operand time.
	/// @return												Result of the addition.
	//----------------------------------------------------------------------------------------
	friend const BaseTime operator + (const BaseTime& t1, const BaseTime& t2);

	//----------------------------------------------------------------------------------------
	/// Subtracts @formatParam{t1} and @formatParam{t2}.
	/// @param[in] t1									Left-operand time.
	/// @param[in] t2									Right-operand time.
	/// @return												Result of the subtraction.
	//----------------------------------------------------------------------------------------
	friend const BaseTime operator - (const BaseTime& t1, const BaseTime& t2);

	/// @name Comparison Operators
	/// @{

	//----------------------------------------------------------------------------------------
	/// Equality operator. Checks if @formatParam{t1} and @formatParam{t2} are equal.
	/// @param[in] t1									Left-operand time.
	/// @param[in] t2									Right-operand time.
	/// @return												Result of the comparison.
	//----------------------------------------------------------------------------------------
	friend Bool operator == (const BaseTime& t1, const BaseTime& t2);

	//----------------------------------------------------------------------------------------
	/// Less than operator. Checks if @formatParam{t1} is less than @formatParam{t2}.
	/// @param[in] t1									Left-operand time.
	/// @param[in] t2									Right-operand time.
	/// @return												Result of the comparison.
	//----------------------------------------------------------------------------------------
	friend Bool operator < (const BaseTime& t1, const BaseTime& t2);

	//----------------------------------------------------------------------------------------
	/// Inequality operator. Checks if @formatParam{t1} and @formatParam{t2} are not equal.
	/// @param[in] t1									Left-operand time.
	/// @param[in] t2									Right-operand time.
	/// @return												Result of the comparison.
	//----------------------------------------------------------------------------------------
	friend Bool operator != (const BaseTime& t1, const BaseTime& t2);

	//----------------------------------------------------------------------------------------
	/// Less than or equal operator. Checks if @formatParam{t1} is less than or equal to @formatParam{t2}.
	/// @param[in] t1									Left-operand time.
	/// @param[in] t2									Right-operand time.
	/// @return												Result of the comparison.
	//----------------------------------------------------------------------------------------
	friend Bool operator <= (const BaseTime& t1, const BaseTime& t2);

	//----------------------------------------------------------------------------------------
	/// Greater than or equal operator. Checks if @formatParam{t1} is greater than or equal to @formatParam{t2}.
	/// @param[in] t1									Left-operand time.
	/// @param[in] t2									Right-operand time.
	/// @return												Result of the comparison.
	//----------------------------------------------------------------------------------------
	friend Bool operator >= (const BaseTime& t1, const BaseTime& t2);

	//----------------------------------------------------------------------------------------
	/// Greater than operator. Checks if @formatParam{t1} is greater than @formatParam{t2}.
	/// @param[in] t1									Left-operand time.
	/// @param[in] t2									Right-operand time.
	/// @return												Result of the comparison.
	//----------------------------------------------------------------------------------------
	friend Bool operator > (const BaseTime& t1, const BaseTime& t2);

	/// @}

	/// @name Miscellaneous
	/// @{

	//----------------------------------------------------------------------------------------
	/// Check which is the largest between the time and @formatParam{t2}.
	/// @param[in] t2									The time to compare with.
	/// @return												@em -1 if the time is < @formatParam{t2}, @em 0 if they are equal and @em 1 if the time is > @formatParam{t2}.
	//----------------------------------------------------------------------------------------
	Int32 TimeDif(const BaseTime& t2) const
	{
		Float n1 = GetNumerator();
		Float n2 = t2.GetNumerator();
		Float d1 = GetDenominator();
		Float d2 = t2.GetDenominator();
		if (n1 == n2 && d1 == d2)
			return 0;

		Float nd1 = Floor(n1 * d2);
		Float nd2 = Floor(n2 * d1);
		if (nd1 < nd2)
			return -1;
		else if (nd1 > nd2)
			return 1;
		return 0;
	}

	/// @}
};

inline const BaseTime operator * (const BaseTime& t1, const BaseTime& t2)
{
	return BaseTime(t1.numerator * t2.numerator, t1.denominator * t2.denominator);
}

inline const BaseTime operator / (const BaseTime& t1, const BaseTime& t2)
{
	return BaseTime(t1.numerator * t2.denominator, t1.denominator * t2.numerator);
}

inline const BaseTime operator + (const BaseTime& t1, const BaseTime& t2)
{
	return BaseTime(t1.numerator * t2.denominator + t2.numerator * t1.denominator, t1.denominator * t2.denominator);
}

inline const BaseTime operator - (const BaseTime& t1, const BaseTime& t2)
{
	return BaseTime(t1.numerator * t2.denominator - t2.numerator * t1.denominator, t1.denominator * t2.denominator);
}

inline Bool operator == (const BaseTime& t1, const BaseTime& t2)
{
	if (t1.numerator == t2.numerator && t1.denominator == t2.denominator)
		return true;	// massive problems otherwise (compiler miscalculating floor)
	return Floor(t1.numerator * t2.denominator) == Floor(t2.numerator * t1.denominator);
}

inline Bool operator < (const BaseTime& t1, const BaseTime& t2)
{
	if (t1.numerator == t2.numerator && t1.denominator == t2.denominator)
		return false;		// massive problems otherwise (compiler miscalculating floor)
	return Floor(t1.numerator * t2.denominator) < Floor(t2.numerator * t1.denominator);
}

inline Bool operator != (const BaseTime& t1, const BaseTime& t2)
{
	if (t1.numerator == t2.numerator && t1.denominator == t2.denominator)
		return false;		// massive problems otherwise (compiler miscalculating floor)
	return Floor(t1.numerator * t2.denominator) != Floor(t2.numerator * t1.denominator);
}

inline Bool operator <= (const BaseTime& t1, const BaseTime& t2)
{
	if (t1.numerator == t2.numerator && t1.denominator == t2.denominator)
		return true;	// massive problems otherwise (compiler miscalculating floor)
	return Floor(t1.numerator * t2.denominator) <= Floor(t2.numerator * t1.denominator);
}

inline Bool operator >= (const BaseTime& t1, const BaseTime& t2)
{
	if (t1.numerator == t2.numerator && t1.denominator == t2.denominator)
		return true;	// massive problems otherwise (compiler miscalculating floor)
	return Floor(t1.numerator * t2.denominator) >= Floor(t2.numerator * t1.denominator);
}

inline Bool operator > (const BaseTime& t1, const BaseTime& t2)
{
	if (t1.numerator == t2.numerator && t1.denominator == t2.denominator)
		return false;		// massive problems otherwise (compiler miscalculating floor)
	return Floor(t1.numerator * t2.denominator) > Floor(t2.numerator * t1.denominator);
}

#endif // C4D_BASETIME_H__
