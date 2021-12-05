#ifndef FINALLY_H__
#define FINALLY_H__

#ifndef APIBASE_H__
	#error "Do not include this file directly"
#endif

/// @file
/// The finally macro.

namespace maxon
{

namespace details
{

template <typename T> class FinallyWrapper
{
	MAXON_DISALLOW_COPY_AND_ASSIGN(FinallyWrapper);

public:
	FinallyWrapper(FinallyWrapper&& src) : _lambda(std::move(src._lambda))
	{
	}
	MAXON_IMPLICIT FinallyWrapper(T&& x) : _lambda(std::move(x))
	{
	}

	~FinallyWrapper()
	{
		_lambda();
	}

	MAXON_OPERATOR_MOVE_ASSIGNMENT(FinallyWrapper);

private:
	T _lambda;
};

class FinallyFactory
{
public:
	template <typename T> MAXON_ATTRIBUTE_FORCE_INLINE FinallyWrapper<T> operator %(T&& lambda) const
	{
		return std::move(lambda);
	}

	static const FinallyFactory instance;
};

}

//----------------------------------------------------------------------------------------
/// Use this to specify a code block which shall be executed when the current scope is left.
/// If you want to execute the finally statement manually (or disable it) see #finally_once.
/// @code
/// {
///   finally { _initializing = false; };
///   _initializing = true;
///   ...
///   // _initializing will be reset to false at this point, even if the block is left by a return statement.
/// };
/// @endcode
/// The code block is part of a lambda expression which captures all variables by reference.
//----------------------------------------------------------------------------------------
#define finally auto MAXON_CONCAT(finally_, __LINE__) = maxon::details::FinallyFactory::instance % [&]() mutable -> void


namespace details
{

template <typename T> class FinallyOnce
{
	MAXON_DISALLOW_COPY_AND_ASSIGN(FinallyOnce);

public:
	MAXON_IMPLICIT FinallyOnce(FinallyOnce&& src) : _lambda(std::move(src._lambda)), _isEnabled(src._isEnabled)
	{
		src._isEnabled = false;
	}

	MAXON_IMPLICIT FinallyOnce(T&& lambda) : _lambda(std::move(lambda)), _isEnabled(true)
	{
	}

	~FinallyOnce()
	{
		if (_isEnabled)
		{
			// Invoke the lambda if it wasn't invoked yet but ignore any results.
			// Use void cast because the GCC maxon::PrivateMuteUnusedHelper might not be defined yet.
			(void) _lambda();
		}
	}

	MAXON_OPERATOR_MOVE_ASSIGNMENT(FinallyOnce);

	/// Disables the invocation of the lambda.
	void Disable()
	{
		_isEnabled = false;
	}

	/// Enables the invocation of the lambda.
	void Enable()
	{
		_isEnabled = true;
	}

	typename std::result_of<T()>::type operator ()()
	{
		DebugAssert(_isEnabled == true);
		_isEnabled = false;

		// Invoke the lambda and return its result (possibly an error).
		return _lambda();
	}

private:
	T _lambda;
	Bool _isEnabled;
};

class FinallyOnceFactory
{
public:
	MAXON_IMPLICIT FinallyOnceFactory()
	{
	}

	template <typename T> MAXON_ATTRIBUTE_FORCE_INLINE FinallyOnce<T> operator %(T&& lambda) const
	{
		return FinallyOnce<T>(std::move(lambda));
	}
};

}

//----------------------------------------------------------------------------------------
/// Use finally_once for a code block which shall be executed when the current scope is left
///  or might be invoked manally (to clean up). In any case the block is invoked just once
/// (unless it is manually disabled).
/// @code
/// {
///   auto cleanup = finally_once { return Cleanup(); };
///   if (!YourCheck())
///       return IllegalArgumentError(MAXON_SOURCE_LOCATION);
///
///   if (IsVerySpecialCaseWhichMustNotExecuteCleanup())
///		{
///			cleanup.Disable();
///     return VerySpecialCaseError(MAXON_SOURCE_LOCATION);
///		}
///
/// 	return cleanup();
/// };
/// @endcode
/// The code block is part of a lambda expression which captures all variables by reference.
//----------------------------------------------------------------------------------------
#define finally_once maxon::details::FinallyOnceFactory() % [&]() mutable

// TODO: (Sven) remove when naming has been finalized.
#define finally_opt maxon::details::FinallyOnceFactory() % [&]() mutable



} // namespace maxon

#endif // FINALLY_H__
