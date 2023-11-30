#ifndef PROFILER_DISABLED_H__
#define PROFILER_DISABLED_H__

namespace maxon
{

/// Helper for disabling some profiler macros outside of thew profile code.
/// Don't define when profiler enabled!
#define PROFILER_DISABLED

#define PROFILER_METHOD_ENTER(...)
#define PROFILER_METHOD_LEAVE(...)
#define PROFILER_SCOPE_ENTER(...)
#define PROFILER_SCOPE_LEAVE(...)
#define PROFILER_DELTA(...)
#define PROFILER_METHOD(...)
#define PROFILER_START(...)
#define PROFILER_STOP_AND_REPORT(...)

}

#endif // PROFILER_DISABLED_H__
