#ifndef VALUERECEIVER_H__
#define VALUERECEIVER_H__

#include "maxon/delegate.h"
#include "maxon/optional.h"
#include "maxon/errorbase.h"

namespace maxon
{

//----------------------------------------------------------------------------------------
/// ValueReceiver type that will verify if one value was received from the caller.
/// No information about the actual value collected will be retained, just found/not found.
/// Useful for calls such as GetConnections when we are interested if there is at least one/any of connection
/// of the given type. Iterations stop after a value is found.
/// @code
///	String myString;
/// ...
/// HasValueReceiver<const String&> recv;
/// myString.Split('a', false, recv) iferr_return;
/// if (recv.IsPopulated())
///		DiagnosticOutput("At least one value was found");
/// @endcode
//----------------------------------------------------------------------------------------
template <typename T> class HasValueReceiver
{
public:
	operator ValueReceiver<T>()
	{
		return [this](T v) -> Result<Bool>
		{
			// Flag value found (ignore the actual value), stop remaining iterations.
			_hasValue = true;
			return false;
		};
	}

	Bool IsPopulated() const
	{
		return _hasValue;
	}

	Bool IsEmpty() const
	{
		return !_hasValue;
	}

	void Reset()
	{
		_hasValue = false;
	}

private:
	Bool _hasValue = false;
};

//----------------------------------------------------------------------------------------
/// ValueReceiver type that will copy the first found value for later access.
/// Useful for calls such as GetConnections when we are interested in getting details 
/// about the first connection found. Iterations stop after a value is found.
/// of the given type.
/// @code
///	String myString;
/// ...
/// FirstValueReceiver<const String&> recv;
/// myString.Split('a', false, recv) iferr_return;
/// if (recv.IsPopulated())
///		DiagnosticOutput("Found first value");
/// @endcode
//----------------------------------------------------------------------------------------
template <typename T> class FirstValueReceiver
{
public:
	operator ValueReceiver<T>()
	{
		return [this](T v) -> Result<Bool>
		{
			iferr_scope;
			// Assign first value found and stop iterations.
			_value = typename std::decay<T>::type();
			AssignCopy(*_value, std::forward<T>(v)) iferr_return;
			return false;
		};
	}

	const Opt<typename std::decay<T>::type>& Get() const
	{
		return _value;
	}

	Bool IsPopulated() const
	{
		return Bool(_value);
	}

	Bool IsEmpty() const
	{
		return !_value;
	}

	void Reset()
	{
		_value = NO_VALUE;
	}

private:
	Opt<typename std::decay<T>::type> _value;
};

//----------------------------------------------------------------------------------------
/// ValueReceiver type that will copy the first found value for later access and keep iterating
/// for counting values or validating uniqueness.
/// Useful for calls such as GetConnections when we are interested in enforcing that there is a single
/// connection on a port. Iterations continue until the end is reached, or when non uniqueness is detected.
/// of the given type.
/// @code
///	String myString;
/// ...
/// UniqueValueReceiver<const String&, false> recv;
/// myString.Split('a', false, recv) iferr_return;
/// if (recv.IsPopulated())
///		DiagnosticOutput("Found a unique value");
/// @endcode
//----------------------------------------------------------------------------------------
template <typename T, Bool ERROR_WHEN_AMBIGUOUS = true> class UniqueValueReceiver
{
public:
	operator ValueReceiver<T>()
	{
		return [this](T v) -> Result<Bool>
		{
			iferr_scope;
			if (!_value)
			{
				// Assign first value found keep iterating for uniqueness validation.
				_value = typename std::decay<T>::type();
				AssignCopy(*_value, std::forward<T>(v)) iferr_return;
			}
			else if (ERROR_WHEN_AMBIGUOUS)
			{
				return IllegalStateError(MAXON_SOURCE_LOCATION, "Expected a single value, but received a second one."_s);
			}
			++_count;
			return true;
		};
	}

	const Opt<typename std::decay<T>::type>& Get() const
	{
		return _value;
	}

	Bool IsPopulated() const
	{
		return Bool(_value);
	}

	Bool IsEmpty() const
	{
		return !_value;
	}

	Int GetCount() const
	{
		return _count;
	}

	void Reset()
	{
		_value = NO_VALUE;
		_count = 0;
	}

private:
	Opt<typename std::decay<T>::type> _value;
	Int _count = 0;
};

/// SingleValueReceiver will get deprecated.
template <typename T, Bool ERROR_WHEN_AMBIGUOUS = true>
using SingleValueReceiver = UniqueValueReceiver<T, ERROR_WHEN_AMBIGUOUS>;

}
#endif // VALUERECEIVER_H__
