#ifndef FORMULAPARSER_H__
#define FORMULAPARSER_H__

#include "maxon/string.h"
#include "maxon/objectbase.h"

namespace maxon
{

/// @addtogroup MATH
/// @{

//----------------------------------------------------------------------------------------
/// Formula expression contained invalid elements, e.g. too many brackets or numbers that could not be parsed.
//----------------------------------------------------------------------------------------
class FormulaParseErrorInterface : MAXON_INTERFACE_BASES(ErrorInterface)
{
	MAXON_INTERFACE(FormulaParseErrorInterface, MAXON_REFERENCE_COPY_ON_WRITE, "net.maxon.interface.formulaparseerror");
};

//----------------------------------------------------------------------------------------
/// Formula expression could be parsed, but execution failed, e.g. because of an invalid number of arguments.
//----------------------------------------------------------------------------------------
class FormulaExecutionErrorInterface : MAXON_INTERFACE_BASES(ErrorInterface)
{
	MAXON_INTERFACE(FormulaExecutionErrorInterface, MAXON_REFERENCE_COPY_ON_WRITE, "net.maxon.interface.formulaexecutionerror");
};

//----------------------------------------------------------------------------------------
/// Numbers in expression could not be parsed, e.g. because they were out of range.
//----------------------------------------------------------------------------------------
class FormulaNumberErrorInterface : MAXON_INTERFACE_BASES(ErrorInterface)
{
	MAXON_INTERFACE(FormulaNumberErrorInterface, MAXON_REFERENCE_COPY_ON_WRITE, "net.maxon.interface.formulanumbererror");
};

/// Metric unit.
enum class METRICUNIT
{
	NONE	= 0,	///< No metric unit
	KM		= 1,	///< kilometer
	M			= 2,	///< meter
	CM		= 3,	///< centimeter
	MM		= 4,	///< millimeter
	UM		= 5,	///< micrometer
	NM		= 6,	///< nanometer
	MILE	= 7,	///< mile (1.609344 km)
	YARD	= 8,	///< yard (91.44 cm)
	FEET	= 9,	///< feet (30.48 cm)
	INCH	= 10	///< inch (2.54 cm)
} MAXON_ENUM_LIST(METRICUNIT);

/// Angle unit.
enum class ANGLEUNIT
{
	DEGREE	= 1,	///< trigonometric functions expect degree values
	RADIANS = 2		///< trigonometric functions expect radians values
} MAXON_ENUM_LIST(ANGLEUNIT);

class FormulaParserCacheRef;

/// The formula parser translates a string expression into this intermediate cache structure.
class FormulaParserCacheInterface
{
	MAXON_INTERFACE_NONVIRTUAL(FormulaParserCacheInterface, MAXON_REFERENCE_NORMAL, "net.maxon.interface.formulaparsercache");

public:
	static MAXON_METHOD FormulaParserCacheInterface* Alloc(MAXON_SOURCE_LOCATION_DECLARATION);
};

/// Formula Parser that calculates the value of a string expression.
///
/// the following metric units are supported:
/// km, m, cm, mm, um (also micron-sign-character + m), nm, mi (mile), yd (yard), ft (foot), in (inch)
///
/// the following functions are supported:
/// sin(x), cos(x), acos(x), asin(x), tan(x), atan(x), cosh(x), sinh(x), tanh(x), floor(x), ceil(x), round(x), abs(x), sqr(x),
/// sqrt(x), exp(x), log(x), log10(x), trunc(x) (converts a floating point number to an integer), rnd(x) (random value between 0 and x), rnd(x;y) (y is a seed value),
/// pow(x;y), mod(a;b), clamp(x;lower;upper) (clamps x between interval [lower..upper]), min(x;y), max(x;y), a&lt&ltb, (x)shl(y) (bitwise shift), a>>b, (x)shr(y) (bitwise shift),
/// len(a;b;...) (vector length of two or more components)
///
/// the following operators are supported:
/// +, -, *, /, (, ), =, ==, >, >=, <, <=, !=, ! (bitwise not), ||, or, &&, and, & (bitwise and), | (bitwise or), ^ (bitwise xor), ~ (bitwise not), cond?(x;y) (conditional statement), if (cond;x;y) (conditional statement)
///
/// the following constants are supported:
/// e, pi
///
/// also:
/// any ',' characters will be interpreted like '.' as a decimal comma
///
/// Typical return errors of this interface are FormulaBadStringError, FormulaBadExecutionError, FormulaNumberError and OutOfMemoryError.
class FormulaParserInterface
{
	MAXON_INTERFACE_NONVIRTUAL(FormulaParserInterface, MAXON_REFERENCE_NORMAL, "net.maxon.interface.formulaparser");

public:
	/// allocator for common use.
	static MAXON_METHOD FormulaParserInterface* Alloc(MAXON_SOURCE_LOCATION_DECLARATION);

	//----------------------------------------------------------------------------------------
	/// Adds a floating point variable to the formula parser.
	/// @param[in] name								Name of the variable.
	/// @param[in] val								Pointer to the variable. Note that the pointer must always be valid when Calculate or Evaluate are called.
	/// @param[in] caseSensitive			If false, then the user can write the letters of the variable using any lower/uppercase combinations.
	/// @return												OK on success. IllegalArgumentError is returned if a variable was already present.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> AddFloatVariable(const String& name, Float64* val, Bool caseSensitive);

	//----------------------------------------------------------------------------------------
	/// Adds an integer variable to the formula parser.
	/// @param[in] name								Name of the variable.
	/// @param[in] val								Pointer to the variable. Note that the pointer must always be valid when Calculate or Evaluate are called.
	/// @param[in] caseSensitive			If false, then the user can write the letters of the variable using any lower/uppercase combinations.
	/// @return												OK on success. IllegalArgumentError is returned if a variable was already present.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> AddIntVariable(const String& name, Int64* val, Bool caseSensitive);

	//----------------------------------------------------------------------------------------
	/// Adds a string variable to the formula parser.
	/// @param[in] name								Name of the variable.
	/// @param[in] val								Pointer to the variable. Note that the pointer must always be valid when Calculate or Evaluate are called.
	/// @param[in] caseSensitive			If false, then the user can write the letters of the variable using any lower/uppercase combinations.
	/// @return												OK on success. IllegalArgumentError is returned if a variable was already present.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> AddStringVariable(const String& name, String* val, Bool caseSensitive);

	//----------------------------------------------------------------------------------------
	/// Removes variable from the formula parser.
	/// @param[in] name								Name of the variable.
	/// @param[in] caseSensitive			If false, then any variable that matches any possible lower/uppercase combination will be picked.
	/// @return												OK on success. IllegalArgumentError is returned if a variable was not present.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> RemoveVariable(const String& name, Bool caseSensitive);

	//----------------------------------------------------------------------------------------
	/// Translates a formula expression string into a pre-parsed cache.
	/// @param[out] cache							Cache that will be created.
	/// @param[in] formula						Formula to be parsed.
	/// @param[in] unit								The metric unit format for the result value. If set to METRICUNIT::NONE all metric units will be ignored as if they were not present.
	/// @param[in] angleUnit					The angular unit that trigonometric functions expect as input / produce as output.
	/// @param[in] base								The numerical base for numbers in the range of [2..36], by default 10. If the base is != 10 then any number will be parsed as an integer value.
	/// @param[in] integerMode				Calculate expressions with integer numbers (floating point values cannot accurately represent most of the Int64 values)
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> CalculateParserCache(FormulaParserCacheRef& cache, const String& formula, METRICUNIT unit, ANGLEUNIT angleUnit, Int base, Bool integerMode);

	//----------------------------------------------------------------------------------------
	/// Executes a floating point formula calculation using a pre-parsed cache for better performance.
	/// @param[in,out] cache					Pre-parsed cache generated by CalculateParserCache. The cache might be modified during this call.
	/// @param[out] result						Will be filled with the result of the formula (even if a neglectable error occured) or 0.0.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> CalculateFloat(FormulaParserCacheRef& cache, Float32& result);
	MAXON_METHOD Result<void> CalculateFloat(FormulaParserCacheRef& cache, Float64& result);

	//----------------------------------------------------------------------------------------
	/// Executes an integer formula calculation using a pre-parsed cache for better performance.
	/// @param[in,out] cache					Pre-parsed cache generated by CalculateParserCache. The cache might be modified during this call.
	/// @param[out] result						Will be filled with the result of the formula (even if a neglectable error occured) or 0.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> CalculateInt(FormulaParserCacheRef& cache, Int64& result);

	//----------------------------------------------------------------------------------------
	/// Evaluates a floating point formula. If you need multiple calls to the same formula (e.g. when variables are used) use CalculateParserCache and CalculateFloat for better performance.
	/// @param[in] formula						Formula to be parsed.
	/// @param[out] result						Will be filled with the result of the formula (might even be the case if a neglectable error occured) or 0.0.
	/// @param[in] unit								The metric unit format for the result value. If set to METRICUNIT::NONE all metric units will be ignored as if they were not present.
	/// @param[in] angleUnit					The angular unit that trigonometric functions expect as input / produce as output.
	/// @param[in] base								The numerical base for numbers in the range of [2..36], by default 10. If the base is != 10 then any number will be parsed as an integer value.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> EvaluateFloat(const String& formula, Float64& result, METRICUNIT unit = METRICUNIT::NONE, ANGLEUNIT angleUnit = ANGLEUNIT::RADIANS, Int base = 10);

	//----------------------------------------------------------------------------------------
	/// Evaluates an integer formula. If you need multiple calls to the same formula (e.g. when variables are used) use CalculateParserCache and CalculateInt for better performance.
	/// @param[in] formula						Formula to be parsed.
	/// @param[out] result						Will be filled with the result of the formula (might even be the case if a neglectable error occured) or 0.
	/// @param[in] unit								The metric unit format for the result value. If set to METRICUNIT::NONE all metric units will be ignored as if they were not present.
	/// @param[in] angleUnit					The angular unit that trigonometric functions expect as input / produce as output.
	/// @param[in] base								The numerical base for numbers in the range of [2..36], by default 10.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> EvaluateInt(const String& formula, Int64& result, METRICUNIT unit = METRICUNIT::NONE, ANGLEUNIT angleUnit = ANGLEUNIT::RADIANS, Int base = 10);
};

#include "formulaparser1.hxx"

#include "formulaparser2.hxx"

/// @}

} // namespace maxon

#endif // FORMULAPARSER_H__
