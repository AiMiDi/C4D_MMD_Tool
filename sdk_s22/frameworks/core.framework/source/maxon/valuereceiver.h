#ifndef VALUERECEIVER_H__
#define VALUERECEIVER_H__

#include "maxon/delegate.h"
#include "maxon/optional.h"

namespace maxon
{

template <typename T> class HasValueReceiver
{
public:
	operator ValueReceiver<T>()
	{
		return [this](T v) -> Result<Bool>
		{
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

template <typename T, Bool ERROR_WHEN_AMBIGUOUS = true> class SingleValueReceiver
{
public:
	operator ValueReceiver<T>()
	{
		return [this](T v) -> Result<Bool>
		{
			iferr_scope;
			if (!_value)
			{
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

}
#endif // VALUERECEIVER_H__
