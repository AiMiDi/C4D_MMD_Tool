#include "maxon/timer.h"

namespace maxon
{


const TimeValue::CurrentTime TimeValue::NOW { };

TimeValue::TimeValue(CurrentTime) : _value(System::GetCustomTimer())
{
}

TimeValue TimeValue::GetTime()
{
	return TimeValue(NOW);
}

const TimeValue& TimeValue::Stop()
{
	*this = TimeValue(NOW) - *this;
	return *this;
}

} // namespace maxon
