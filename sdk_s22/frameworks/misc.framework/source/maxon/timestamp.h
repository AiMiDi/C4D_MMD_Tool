#ifndef TIMESTAMP_H__
#define TIMESTAMP_H__

#include "maxon/datatype.h"

namespace maxon
{

//----------------------------------------------------------------------------------------
/// An ExecutionTime holds an integer value to be used for time stamps. As such it is not
/// related to any kind of real time, but just as a value which is incremented by one
/// whenever an event of interest happens. What kind of event this is depends on the
/// context in which the ExecutionTime is used. For example, it might be a modification
/// counter of some data which is incremented whenever the data is changed.
///
/// ExecutionTime has only a single operation, namely ++ to increment the value.
/// TimeStamp objects can then be used to save the value of an ExecutionTime at a certain
/// instant, and to check if the ExecutionTime has changed in the meantime. I.e.,
/// in the use case of a data modification counter, you use a single ExecutionTime for the
/// original data. For each dependent data which has to be re-computed
/// when the original data changes, you use a TimeStamp value which stores the
/// ExecutionTime when the dependent data has been updated the last time.
///
/// One could also use Int values directly for execution times and
/// time stamps, but these wrapper classes make the purpose of the values clearer,
/// and they only allow the meaningful operations which makes them safer.
///
/// @see TimeStamp
//----------------------------------------------------------------------------------------
class ExecutionTime
{
public:
	using ValueType = UInt; // TODO: (Ole) ideally we would use UInt64 to avoid overflows, but then we need support for 64 bit atomic ints on 32 bit platforms, or find some way without atomic access
	using AtomicType = AtomicUInt;

	static_assert(SIZEOF(ValueType) == SIZEOF(AtomicType), "Size mismatch");

	//----------------------------------------------------------------------------------------
	/// Construct a new ExecutionTime. The internal value will be set to 1.
	//----------------------------------------------------------------------------------------
	ExecutionTime() : _value(1) {}

	//----------------------------------------------------------------------------------------
	/// Increments the ExecutionTime by one. Don't mix with BeginNewGlobalTime.
	//----------------------------------------------------------------------------------------
	ExecutionTime& operator ++()
	{
		++_value;
		return *this;
	}

	//----------------------------------------------------------------------------------------
	/// Increments the ExecutionTime by one. Don't mix with BeginNewGlobalTime.
	//----------------------------------------------------------------------------------------
	void operator ++(int)
	{
		++_value;
	}

	//----------------------------------------------------------------------------------------
	/// Returns the internal integer value.
	/// @return												Internal integer value of this ExecutionTime.
	//----------------------------------------------------------------------------------------
	operator ValueType() const
	{
		return _value;
	}

private:
	ValueType _value;

	friend class TimeStamp;
};


//----------------------------------------------------------------------------------------
/// A TimeStamp represents the value of an ExecutionTime at a certain instant.
/// You can compare a TimeStamp with an ExecutionTime to see if the ExecutionTime
/// has changed since the last update of the TimeStamp (in this case the ExecutionTime
/// will be greater than the TimeStamp).
///
/// @see ExecutionTime
//----------------------------------------------------------------------------------------
class TimeStamp
{
public:
	//----------------------------------------------------------------------------------------
	/// Construct a new TimeStamp. The internal value will be set to 0. Because ExecutionTime
	/// starts with 1, this means that an initial TimeStamp will be in the past of any valid ExecutionTime.
	//----------------------------------------------------------------------------------------
	constexpr TimeStamp() : _value(0) { }

	explicit TimeStamp(ExecutionTime time) : _value(time._value) { }

	explicit constexpr TimeStamp(ExecutionTime::ValueType time) : _value(time) { }

	enum class MAX_ENUM { VALUE } MAXON_ENUM_LIST_CLASS(MAX_ENUM);

	static const MAX_ENUM MAX = MAX_ENUM::VALUE;

	//----------------------------------------------------------------------------------------
	/// Construct a new TimeStamp with a maximum value. I.e., the constructed TimeStamp will be
	/// in the future of every valid ExecutionTime.
	//----------------------------------------------------------------------------------------
	MAXON_IMPLICIT TimeStamp(MAX_ENUM) : _value(LIMIT<ExecutionTime::ValueType>::MAX) { }

	void UpdateUnchecked(TimeStamp src)
	{
		_value = src._value;
	}

	//----------------------------------------------------------------------------------------
	/// Updates this TimeStamp to the current value of @p time.
	/// This TimeStamp must not be in the future of @p time.
	/// @param[in] time								Time to which this TimeStamp is set.
	//----------------------------------------------------------------------------------------
	void UpdateUnordered(ExecutionTime time)
	{
		DebugAssert(_value <= time._value);
		_value = time._value;
	}

	//----------------------------------------------------------------------------------------
	/// Atomically updates this TimeStamp to the current value of @p time.
	/// The update is done only if this TimeStamp is currently in the past of @p time.
	/// @param[in] time								Time to which this TimeStamp is set.
	/// @return												True if this TimeStamp has been changed, false otherwise.
	//----------------------------------------------------------------------------------------
	Bool UpdateAtomic(ExecutionTime time)
	{
		ExecutionTime::ValueType v = _value;
		while (v < time._value)
		{
			if (ExecutionTime::AtomicType::TryCompareAndSwap(&_value, time._value, v))
				return true;
			// refetch possibly updated value
			v = _value;
		}
		return false;
	}

	Bool Update(ExecutionTime time)
	{
		DebugAssert(_value <= time._value);
		if (_value < time._value)
		{
			_value = time._value;
			return true;
		}
		return false;
	}

	//----------------------------------------------------------------------------------------
	/// Returns the internal integer value of this TimeStamp. This can be compared with the value
	/// of an ExecutionTime to see if the ExecutionTime has changed since the last update
	/// of the TimeStamp.
	/// @return												Internal integer value of this TimeStamp.
	//----------------------------------------------------------------------------------------
	operator ExecutionTime::ValueType() const
	{
		return _value;
	}

	static const TimeStamp& NullValue()
	{
		return GetZeroRef<TimeStamp>();
	}

	MAXON_OPERATOR_EQUALITY_HASHCODE(TimeStamp, _value);

	String ToString(const FormatStatement* fs) const
	{
		return String::UIntToString(_value);
	}

private:
	ExecutionTime::ValueType _value;
};

MAXON_DATATYPE(TimeStamp, "net.maxon.datatype.timestamp");

} // namespace maxon

#endif // TIMESTAMP_H__
