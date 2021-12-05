#include "maxon/thread.h"

namespace maxon
{

String JobInterface::ToString(const FormatStatement* formatStatement) const
{
	return "JobInterface "_s + String::PointerToString((void*) this) + " (CoreJob: "_s + String::PointerToString((void*)this->_job) + ")"_s;
}

String JobRef::ToString(const FormatStatement* formatStatement) const
{
	const JobInterface* self = GetPointer();
	return self ? self->ToString(formatStatement) : String();
}

String ThreadInterface::ToString(const FormatStatement* formatStatement) const
{
	return "ThreadInterface "_s + String::PointerToString((void*) this) + " (CoreJob: "_s + String::PointerToString((void*)this->_job) + ")"_s;
}

template<> String ThreadRef::ToString(const FormatStatement* formatStatement) const
{
	const ThreadInterface* self = GetPointer();
	return self ? self->ToString(formatStatement) : String();
}

String JobGroupInterface::ToString(const FormatStatement* formatStatement) const
{
	return "JobGroupInterface "_s + String::PointerToString((void*) this);
}

String JobGroupRef::ToString(const FormatStatement* formatStatement) const
{
	const JobGroupInterface* self = GetPointer();
	return self ? self->ToString(formatStatement) : String();
}

} // namespace maxon
