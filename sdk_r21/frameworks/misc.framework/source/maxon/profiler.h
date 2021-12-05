#ifndef PROFILER_H__
#define PROFILER_H__

#include "maxon/registry.h"
#include "maxon/timer.h"

namespace maxon
{

//----------------------------------------------------------------------------------------
/// @markInternal
/// Defines the type of a profiling point.
//----------------------------------------------------------------------------------------
enum class PROFILER_POINT_TYPE
{
	NONE = 0,							///< Unspecified.
	METHOD_ENTER,					///< Enter Method Scope.
	METHOD_LEAVE,					///< Leave Method Scope.
	SCOPE_ENTER,					///< Enter Scope.
	SCOPE_LEAVE,					///< Leave Scope.
	DELTA									///< Delta From Last Visited Point.
} MAXON_ENUM_LIST(PROFILER_POINT_TYPE);

//----------------------------------------------------------------------------------------
/// @markInternal
/// Defines the profiler state.
//----------------------------------------------------------------------------------------
enum class PROFILER_STATE
{
	DISABLED = 0,					///< Disabled.
	ENABLED_METHOD_SCOPE,	///< Enabled for METHOD_ENTER and METHOD_LEAVE point types.
	ENABLED_ALL						///< Enabled for all point types.
} MAXON_ENUM_LIST(PROFILER_STATE);

//----------------------------------------------------------------------------------------
/// @markInternal
/// Defines the profiler clock mode.
//----------------------------------------------------------------------------------------
enum class PROFILER_CLOCK_MODE
{
	NORMAL = 0,						///< Use the system clock
	SIMULATED							///< Use a simulated clock for profiling purpose
} MAXON_ENUM_LIST(PROFILER_CLOCK_MODE);

//----------------------------------------------------------------------------------------
/// @markInternal
//----------------------------------------------------------------------------------------
class ProfilerConstant
{
public:
	static const UInt32 INVALID = LIMIT<UInt32>::MAX;
};

class ProfilingPoint;

//----------------------------------------------------------------------------------------
/// @markInternal
//----------------------------------------------------------------------------------------
class Profiler
{
	MAXON_INTERFACE_NONVIRTUAL(Profiler, MAXON_REFERENCE_NONE, "net.maxon.interface.profiler");

public:
	static const Profiler& NullValueRef()
	{
		return GetZeroRef<Profiler>();
	}

	//----------------------------------------------------------------------------------------
	/// Gets the count of captured samples.
	/// @return												Captured sample count.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD UInt32 GetSampleCount();

	//----------------------------------------------------------------------------------------
	/// Resets the profiler.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void Reset();

	//----------------------------------------------------------------------------------------
	/// Gets the profiler debug dump enabled state.
	/// @return												True if enabled, false otherwise.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Bool GetDebugDumpEnabled();

	//----------------------------------------------------------------------------------------
	/// Sets the profiler debug dump enabled state.
	/// @param[in] state							True if enabled, false otherwise.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void SetDebugDumpEnabled(Bool state);

	//----------------------------------------------------------------------------------------
	/// Gets the profiler state.
	/// @return												State: DISABLED, ENABLED_METHOD_SCOPE, ENABLED_ALL
	//----------------------------------------------------------------------------------------
	MAXON_METHOD PROFILER_STATE GetEnableState();

	//----------------------------------------------------------------------------------------
	/// Sets the profiler state.
	/// @param[in] state							State: DISABLED, ENABLED_METHOD_SCOPE, ENABLED_ALL
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void SetEnableState(PROFILER_STATE state);

	//----------------------------------------------------------------------------------------
	/// Gets the enabled state of a profiling point.
	/// @return												True if enabled.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Bool GetEnableState(const ProfilingPoint& profilingPoint);

	//----------------------------------------------------------------------------------------
	/// Gets the current time. Used by the calling macro to capture the time before arguments
	/// for the call to AddPointSample or AddSample methods are evaluated.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void GetMacroTime();

	//----------------------------------------------------------------------------------------
	/// Indicates if a profiling point is visited for the first time in the current scope.
	/// @param[in] profilingPoint			ProfilingPoint reference.
	/// @return												True or false.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Bool IsFirstTime(const ProfilingPoint& profilingPoint);

	//----------------------------------------------------------------------------------------
	/// Adds a sample to a profiling point in the current scope.
	///
	/// A profiling point may be visited multiple times during execution, e.g. within a loop.
	/// Every encounter records a time measurement sample, which is added to the scope point,
	/// and is used to calculate the total and average time for all captured samples. Points
	/// of METHOD_ENTER or SCOPE_ENTER types capture the total scope time for every sample,
	/// allowing to report the average scope time as well.
	/// 
	/// @param[in] profilingPoint			ProfilingPoint reference.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void AddSample(const ProfilingPoint& profilingPoint);

	//----------------------------------------------------------------------------------------
	/// Adds a profiling point to the current scope and registers a sample.
	///
	/// A profiling point is declared by using a PROFILER macro with an optional output string
	/// to be printed with the trace report. If present, the string is recorded the first time
	/// a profiling point is visited per scope.
	///
	/// The following example gets the global profiler, configures it to use a simulated clock
	/// (to force the captured time values to be constant) and defines profiling points to run
	/// the following sequence:
	///
	///		ME 5ms SE loop5x{ 10ms D } 5ms SL ML
	///
	/// where:
	/// - ME  = METHOD_ENTER
	/// - #ms = time delta in milliseconds
	/// - SE  = SCOPE_ENTER
	/// - D   = DELTA
	/// - SL  = SCOPE_LEAVE
	/// - ML  = METHOD_LEAVE
	///
	/// @code
	/// static void MyMethod()
	/// {
	/// 	maxon::Profiler& profiler = *maxon::ProfilerInstance();
	///
	/// 	// capture all profiling point types
	/// 	profiler.SetEnableState(maxon::PROFILER_STATE::ENABLED_ALL);
	///
	/// 	// use simulated clock
	/// 	profiler.SetClockMode(maxon::PROFILER_CLOCK_MODE::SIMULATED);
	///
	/// 	// set sample processing simulated time (in milliseconds)
	/// 	profiler.SetClockSampleProcessTime(5);
	///
	/// 	// set the time filtering threshold
	/// 	profiler.SetTimeFilter(0);
	///
	/// 	PROFILER_METHOD();
	///
	/// 	profiler.AddClockMilliseconds(5);
	///
	/// 	PROFILER_SCOPE_ENTER("Number of loops: 5"_s);
	///
	/// 	for (Int32 index = 0; index < 5; index++)
	/// 	{
	/// 		profiler.AddClockMilliseconds(10);
	///
	/// 		PROFILER_DELTA();
	/// 	}
	///
	/// 	profiler.AddClockMilliseconds(5);
	///
	/// 	PROFILER_SCOPE_LEAVE();
	///
	/// 	profiler.OutputStringReport("MyMethod - Profile trace dump"_s);
	/// }
	/// @endcode
	///
	/// Produces the following output:
	///
	///	MyMethod - Profile trace dump (8 samples in 4 points)
	///	[>] 60.0 ms (100.00%), 0.00 ns (0.00% profiler) : METHOD_ENTER: MyMethod (line 304)
	///	[0]  5.0 ms (8.33%)
	///	[0] 55.0 ms (91.67%), 80.00 ms (31.25% profiler): SCOPE_ENTER: MyMethod (line 308) - Number of loops: 5
	///	[1] 50.0 ms (90.91%) avg: 10.0 ms (5 samples): DELTA: MyMethod (line 314)
	///	[1]  5.0 ms (9.09%): SCOPE_LEAVE: MyMethod (line 319)
	///
	/// @param[in] profilingPoint			ProfilingPoint reference.
	/// @param[in] outputString				Optional string to be printed when outputting a report.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void AddPointSample(const ProfilingPoint& profilingPoint, const Char* outputString = nullptr);
	MAXON_METHOD void AddPointSample(const ProfilingPoint& profilingPoint, const String& outputString);

	//----------------------------------------------------------------------------------------
	/// Outputs a string to the debugger output and the C4D console profiler logger.
	/// @param[in] string							String to output.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void OutputString(String& string);

	//----------------------------------------------------------------------------------------
	/// Outputs a profiling trace to the debugger output and the C4D console profiler logger.
	/// @param[in] headerString				Header string to output first.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void OutputStringReport(const String& headerString);

	//----------------------------------------------------------------------------------------
	/// Gets the profiler clock mode.
	/// @return												State: NORMAL, SIMULATED
	//----------------------------------------------------------------------------------------
	MAXON_METHOD PROFILER_CLOCK_MODE GetClockMode();

	//----------------------------------------------------------------------------------------
	/// Sets the profiler clock mode.
	/// @param[in] clockMode					State: NORMAL, SIMULATED
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void SetClockMode(PROFILER_CLOCK_MODE clockMode);

	//----------------------------------------------------------------------------------------
	/// Sets the profiler simulated clock time value.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void SetClock(TimeValue timeValue);

	//----------------------------------------------------------------------------------------
	/// Sets the profiler simulated clock to a time value in milliseconds.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void SetClockMilliseconds(UInt32 milliseconds);

	//----------------------------------------------------------------------------------------
	/// Gets the profiler simulated clock time to process a sample in milliseconds.
	/// @return												Sample process time
	//----------------------------------------------------------------------------------------
	MAXON_METHOD UInt32 GetClockSampleProcessTime();

	//----------------------------------------------------------------------------------------
	/// Sets the profiler simulated clock time to process a sample.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void SetClockSampleProcessTime(UInt32 milliseconds);

	//----------------------------------------------------------------------------------------
	/// Gets the profiler simulated clock automatic time increment.
	/// @return												Clock automatic time increment value
	//----------------------------------------------------------------------------------------
	MAXON_METHOD UInt32 GetClockAutoIncrementTime();

	//----------------------------------------------------------------------------------------
	/// Sets the profiler simulated clock automatic time increment.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void SetClockAutoIncrementTime(UInt32 milliseconds);

	//----------------------------------------------------------------------------------------
	/// Adds a time value to the profiler simulated clock.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void AddClock(TimeValue timeValue);

	//----------------------------------------------------------------------------------------
	/// Adds a time delta in milliseconds to the profiler simulated clock.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void AddClockMilliseconds(UInt32 milliseconds);

	//----------------------------------------------------------------------------------------
	/// Gets the time filter threshold value in milliseconds.
	/// @return												Time filter threshold value.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD UInt32 GetTimeFilter();

	//----------------------------------------------------------------------------------------
	/// Sets the time filter threshold value in milliseconds.
	/// @param[in] threshold					State.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void SetTimeFilter(UInt32 threshold);

	//----------------------------------------------------------------------------------------
	/// Get a lock on the profiler.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void GetLock();

	//----------------------------------------------------------------------------------------
	/// Releases a lock on the profiler.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void ReleaseLock();
};

//----------------------------------------------------------------------------------------
/// @markInternal
//----------------------------------------------------------------------------------------
class ProfileManagerInterface
{
	MAXON_INTERFACE_NONVIRTUAL(ProfileManagerInterface, MAXON_REFERENCE_NONE, "net.maxon.interface.profilemanager");

public:
	//----------------------------------------------------------------------------------------
	/// Registers the profiling points of a framework or module.
	/// @param[in] moduleInfo					ModuleInfo instance.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> RegisterProfilingPoints(const ModuleInfo* moduleInfo);

	//----------------------------------------------------------------------------------------
	/// Dumps error strings collected during the registration of profiling points (if any).
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> DumpProfilerRegistrationErrors();

	//----------------------------------------------------------------------------------------
	/// Dumps the Profile Manager profiling point registry to the debugger console.
	/// The information is generated as a hierarchy of: modules > files > methods > points.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> DumpProfilerRegistry();
};

//----------------------------------------------------------------------------------------
/// @markInternal
//----------------------------------------------------------------------------------------
class ProfilingPoint
{
public:
	explicit ProfilingPoint(const Char* filePath, const Char* method, UInt32 line, maxon::PROFILER_POINT_TYPE type) : _type(type), _filePath(filePath), _method(method), _line(line), _next(PRIVATE_MAXON_MODULE._profilingPoints)
	{
		if (PRIVATE_MAXON_MODULE._profilingPoints)
			PRIVATE_MAXON_MODULE._profilingPoints->_prev = this;

		PRIVATE_MAXON_MODULE._profilingPoints = this;
	}

	// set at compilation-time
	const maxon::PROFILER_POINT_TYPE	_type							= maxon::PROFILER_POINT_TYPE::NONE;
	const Char* const									_filePath					= nullptr;
	const Char* const									_method						= nullptr;
	UInt32 const											_line							= 0;
	const ProfilingPoint* const				_next							= nullptr;

	// set at launch time
	mutable UInt32										_pointIndex				= 0;
	mutable UInt32										_methodIndex			= 0;
	mutable UInt32										_fileIndex				= 0;
	mutable UInt32										_moduleIndex			= 0;
	mutable UInt32										_scopePointIndex	= ProfilerConstant::INVALID;					// index of joined scope point (e.g. ENTER for LEAVE or vice-versa)
	const ProfilingPoint* 						_prev							= nullptr;
	mutable Bool											_valid						= true;

	// set at run time (default ON, user-modifiable)
	mutable Bool											_active						= true;
	mutable Bool											_enabled					= true;
};

template <typename PROFILING_POINT> struct ProfilingPointHelper
{
	static const ProfilingPoint _instance;
};

template <typename PROFILING_POINT> const ProfilingPoint ProfilingPointHelper<PROFILING_POINT>::_instance(PROFILING_POINT::GetFilePath(), PROFILING_POINT::GetFunction(), PROFILING_POINT::GetLine(), PROFILING_POINT::GetType());

MAXON_DECLARATION(maxon::Profiler*, ProfilerInstance, "net.maxon.profiler");

#define PROFILER_POINT(type, ...) PRIVATE_PROFILER_POINT(__COUNTER__, type, ##__VA_ARGS__)
#define PRIVATE_PROFILER_POINT(counter, type, ...) PRIVATE_PROFILER_POINT2(counter, type, ##__VA_ARGS__)

#ifdef MAXON_TARGET_WINDOWS
#define PRIVATE_PROFILER_POINT2(counter, type, ...) \
	{ \
		struct Profiling##counter \
		{ \
			static maxon::Char* GetFilePath() { return (maxon::Char*)__FILE__; } \
			static maxon::Char* GetFunction() { return (maxon::Char*)__FUNCTION__; } \
			static maxon::UInt32 GetLine() { return __LINE__; } \
			static maxon::PROFILER_POINT_TYPE GetType() { return type; } \
		}; \
		maxon::Profiler&	_profiler = *maxon::ProfilerInstance(); \
		maxon::PROFILER_STATE	_state = _profiler.GetEnableState(); \
		if (maxon::ProfilingPointHelper<Profiling##counter>::_instance._valid && maxon::ProfilingPointHelper<Profiling##counter>::_instance._enabled && (_state == maxon::PROFILER_STATE::ENABLED_ALL || (_state == maxon::PROFILER_STATE::ENABLED_METHOD_SCOPE && (maxon::ProfilingPointHelper<Profiling##counter>::_instance._type == maxon::PROFILER_POINT_TYPE::METHOD_ENTER || maxon::ProfilingPointHelper<Profiling##counter>::_instance._type == maxon::PROFILER_POINT_TYPE::METHOD_LEAVE)))) \
		{ \
			_profiler.GetLock(); \
			_profiler.GetMacroTime(); \
			if (_profiler.IsFirstTime(maxon::ProfilingPointHelper<Profiling##counter>::_instance)) \
				_profiler.AddPointSample(maxon::ProfilingPointHelper<Profiling##counter>::_instance, ##__VA_ARGS__); \
			else \
				_profiler.AddSample(maxon::ProfilingPointHelper<Profiling##counter>::_instance); \
			_profiler.ReleaseLock(); \
		} \
	}
#else
#define PRIVATE_PROFILER_POINT2(counter, type, ...) \
	{ \
		struct Profiling##counter \
		{ \
			static maxon::Char* GetFilePath() { return (maxon::Char*)__FILE__; } \
			static maxon::Char* GetFunction() { return (maxon::Char*)__PRETTY_FUNCTION__; } \
			static maxon::UInt32 GetLine() { return __LINE__; } \
			static maxon::PROFILER_POINT_TYPE GetType() { return type; } \
		}; \
		maxon::Profiler&	_profiler = *maxon::ProfilerInstance(); \
		maxon::PROFILER_STATE	_state = _profiler.GetEnableState(); \
		if (maxon::ProfilingPointHelper<Profiling##counter>::_instance._valid && maxon::ProfilingPointHelper<Profiling##counter>::_instance._enabled && (_state == maxon::PROFILER_STATE::ENABLED_ALL || (_state == maxon::PROFILER_STATE::ENABLED_METHOD_SCOPE && (maxon::ProfilingPointHelper<Profiling##counter>::_instance._type == maxon::PROFILER_POINT_TYPE::METHOD_ENTER || maxon::ProfilingPointHelper<Profiling##counter>::_instance._type == maxon::PROFILER_POINT_TYPE::METHOD_LEAVE)))) \
		{ \
			_profiler.GetLock(); \
			_profiler.GetMacroTime(); \
			if (_profiler.IsFirstTime(maxon::ProfilingPointHelper<Profiling##counter>::_instance)) \
				_profiler.AddPointSample(maxon::ProfilingPointHelper<Profiling##counter>::_instance, ##__VA_ARGS__); \
			else \
				_profiler.AddSample(maxon::ProfilingPointHelper<Profiling##counter>::_instance); \
			_profiler.ReleaseLock(); \
		} \
	}
#endif

#define PROFILER_METHOD_ENTER(...)	PROFILER_POINT(maxon::PROFILER_POINT_TYPE::METHOD_ENTER, ##__VA_ARGS__)
#define PROFILER_METHOD_LEAVE(...)	PROFILER_POINT(maxon::PROFILER_POINT_TYPE::METHOD_LEAVE, ##__VA_ARGS__)
#define PROFILER_SCOPE_ENTER(...)		PROFILER_POINT(maxon::PROFILER_POINT_TYPE::SCOPE_ENTER, ##__VA_ARGS__)
#define PROFILER_SCOPE_LEAVE(...)		PROFILER_POINT(maxon::PROFILER_POINT_TYPE::SCOPE_LEAVE, ##__VA_ARGS__)
#define PROFILER_DELTA(...)					PROFILER_POINT(maxon::PROFILER_POINT_TYPE::DELTA, ##__VA_ARGS__)

// convenience macro that registers both METHOD_ENTER and METHOD_LEAVE sampling points with a single call
#define PROFILER_METHOD(...) \
	PROFILER_METHOD_ENTER(__VA_ARGS__); \
	finally \
	{ \
		PROFILER_METHOD_LEAVE(); \
	};

//----------------------------------------------------------------------------------------
/// Allow to enable (or disable) the profiler. All trace points are ignored if profiler is
/// not enabled.
//----------------------------------------------------------------------------------------
#define PROFILER_START(enable) \
	maxon::Profiler &profRef = *maxon::ProfilerInstance(); \
	profRef.SetEnableState(enable ? maxon::PROFILER_STATE::ENABLED_ALL : maxon::PROFILER_STATE::DISABLED);

//----------------------------------------------------------------------------------------
/// Stops a profiling session and dump the results to the maxon console. 
/// After a stop, PROFILER_START must be called again to restart profiling. The macro accepts a string
/// argument which will be part of the profiler trace report header. You can use this to
/// pass a custom formatted string which will contain details about the capture context,
/// for example how many vertices or polygons were processed by the method, etc.
//----------------------------------------------------------------------------------------
#define PROFILER_STOP_AND_REPORT(...) \
	maxon::Profiler &profRef = *maxon::ProfilerInstance(); \
	profRef.OutputStringReport(FormatString(__VA_ARGS__)); \
	profRef.Reset(); \
	profRef.SetEnableState(maxon::PROFILER_STATE::DISABLED);

#include "profiler1.hxx"
#include "profiler2.hxx"

extern Bool g_enableInCodeProfiler; // enable/disable in-code profiler
}

#endif // PROFILER_H__
