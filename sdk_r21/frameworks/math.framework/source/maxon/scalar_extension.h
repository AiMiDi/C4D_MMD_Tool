#ifndef SCALAR_EXTENSION_H__
#define SCALAR_EXTENSION_H__

#include "maxon/apibase.h"
#include "maxon/general_math.h"

namespace maxon
{
//----------------------------------------------------------------------------------------------------
/// Helpers for shorter function names.
//----------------------------------------------------------------------------------------------------
template <typename T> using enable_if_scalar				= typename std::enable_if<std::is_scalar<T>::value, T>::type;
template <typename T> using enable_if_not_scalar		= typename std::enable_if<!std::is_scalar<T>::value, T>::type;
template <typename T> using enable_if_float					= typename std::enable_if<std::is_floating_point<T>::value, T>::type;
template <typename T> using enable_if_not_float			= typename std::enable_if<!std::is_floating_point<T>::value, T>::type;
template <typename T> using enable_if_integral			= typename std::enable_if<std::is_integral<T>::value, T>::type;
template <typename T> using enable_if_not_integral	= typename std::enable_if<!std::is_integral<T>::value, T>::type;

//----------------------------------------------------------------------------------------------------
/// Helper to vectorize common functions like Cos, Sin, Ceil, Abs, etc.
/// Specialization for Vec2<T>, Vec3<T>, Vec4<T>, Col3<T> and Col4<T> are available.
//----------------------------------------------------------------------------------------------------
template <typename T, typename FUNC> struct MathFuncHelper;

template <typename T, typename FUNC> struct MathFuncHelper<Vec2<T>, FUNC>
{
	template <typename... ARGS> static Vec2<T> Calculate(ARGS&&... args) 
	{
		return Vec2<T>(FUNC::Compute(std::forward<ARGS>(args).x...), FUNC::Compute(std::forward<ARGS>(args).y...));
	}
};

template <typename T, typename FUNC> struct MathFuncHelper<Vec3<T>, FUNC>
{
	template <typename... ARGS> static Vec3<T> Calculate(ARGS&&... args) 
	{
		return Vec3<T>(FUNC::Compute(std::forward<ARGS>(args).x...), FUNC::Compute(std::forward<ARGS>(args).y...), FUNC::Compute(std::forward<ARGS>(args).z...));
	}
};

template <typename T, typename FUNC> struct MathFuncHelper<Vec4<T>, FUNC>
{
	template <typename... ARGS> static Vec4<T> Calculate(ARGS&&... args) 
	{
		return Vec4<T>(FUNC::Compute(std::forward<ARGS>(args).x...), FUNC::Compute(std::forward<ARGS>(args).y...), FUNC::Compute(std::forward<ARGS>(args).z...), FUNC::Compute(std::forward<ARGS>(args).w...));
	}
};

template <typename T, typename FUNC> struct MathFuncHelper<Col3<T>, FUNC>
{
	template <typename... ARGS> static Col3<T> Calculate(ARGS&&... args) 
	{
		return Col3<T>(FUNC::Compute(std::forward<ARGS>(args).r...), FUNC::Compute(std::forward<ARGS>(args).g...), FUNC::Compute(std::forward<ARGS>(args).b...));
	}
};

template <typename T, typename FUNC> struct MathFuncHelper<Col4<T>, FUNC>
{
	template <typename... ARGS> static Col4<T> Calculate(ARGS&&... args) 
	{
		return Col4<T>(FUNC::Compute(std::forward<ARGS>(args).r...), FUNC::Compute(std::forward<ARGS>(args).g...), FUNC::Compute(std::forward<ARGS>(args).b...), FUNC::Compute(std::forward<ARGS>(args).a...));
	}
};

//----------------------------------------------------------------------------------------------------
/// If you want to use your scalar function with any of the MathFuncHelper specializations:
/// MATH_HELPER_INSTANTIATE(YourFunc);
/// This will create a Function of the same name as the provided function "YourFunc" and can be used like e.g.
/// @code
/// MATH_HELPER_INSTANTIATE(SmoothStep);
/// template <typename T> class MyClass
/// {
///		Result<T> SomeFunc(const T& value, const T& lowerLimit, const T& upperLimit)
///		{
///			return SmoothStep(lowerLimit, upperLimit, value); // Note that T can be of any type we specialized for.
///		}
/// };
/// @endcode
//----------------------------------------------------------------------------------------------------
#define MATH_HELPER_INSTANTIATE(Func) \
	struct Func##Helper \
	{ \
		template <typename... ARGS> static auto Compute(ARGS&&... args) -> decltype(Func(std::forward<ARGS>(args)...)) \
		{ \
			return Func(std::forward<ARGS>(args)...); \
		} \
	}; \
	template <typename T, typename... ARGS> static MAXON_ATTRIBUTE_FORCE_INLINE T Func(const T& first, ARGS&&... args) \
	{ \
		return MathFuncHelper<T, Func##Helper>::Calculate(first, std::forward<ARGS>(args)...); \
	}

} // namespace maxon

#endif // SCALAR_EXTENSION_H__
