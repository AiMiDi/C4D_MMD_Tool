#ifndef CPUYIELD_H__
#define CPUYIELD_H__

#include "maxon/apibase.h"

#if defined(MAXON_TARGET_WINDOWS)
	#include <intrin.h>
#elif defined(MAXON_TARGET_CPU_INTEL)
	#include <xmmintrin.h>
#endif

namespace maxon
{


class CpuYieldState
{
	// The pause instruction takes between 8 and 9 cycles on current x86 CPUs and the
	// count values below refer to the number of pause instructions. All times are
	// based on a 3 GHz clock (We could compute the yield and sleep count based
	// on actual cpu frequency, but so far it doesn't seem to be necessary)
	//
	// Windows has no proper sleep, typically 15 ms is as low as it can get and SwitchToThread()
	// is more or less worthless. Therefore we have to use different parameters than on
	// MacOS where you can have a minimum sleep duration of 4 us (older cpus might go up to 10 us)
	//
	// When a CAS instruction fails it makes no sense to immediately retry and check the
	// memory location. Due to cache invalidation it can easily take anywhere between 200
	// and 600 cycles before you can access this memory location again. Trying this before
	// might only increase the penalty. This is reflected by the LOOPS_START_COUNT.
	//
	// The maximum wait time before the memory location is accessed is specified by
	// LOOPS_MAX_GRANULARITY. The wait time increases from LOOPS_START_COUNT to
	// LOOPS_MAX_GRANULARITY by a factor of two with every Pause() call. When the maximum
	// granularity is reached we start again until LOOPS_BEFORE_YIELD is reached.
	// In this case an OS function is called to indicate we make no forward progress
	// and another thread should try. This is being done until LOOPS_BEFORE_SLEEP is
	// reached and we sleep even longer (and reset everything after that)
	//
	// LOOPS_START_COUNT			is an estimate of the minimum wait before retrying a CAS (this can take between 200 - 600 cycles, sometimes even more)
	// LOOPS_MAX_GRANULARITY	maximum number of pause instructions before you can retry
	// LOOPS_BEFORE_YIELD			number of pause instructions before we call an OS function (SwitchToThread or usleep)
	// LOOPS_BEFORE_SLEEP			number of pause instructions before a deeper sleep (Sleep or longer usleep)

public:
	static const Int LOOPS_START_COUNT = 16;								// 48 ns

#ifdef	MAXON_TARGET_WINDOWS

	static const Int LOOPS_MAX_GRANULARITY = 2048;						// 6144 ns: higher on Windows because SwitchToThread() usually is worthless and it makes more sense just to nop
	static const Int LOOPS_BEFORE_YIELD = 262144;						// 786432 ns: that's almost one ms, but necessary due to Windows poor multitasking
	static const Int LOOPS_BEFORE_SLEEP = 4000000;					// 12 ms: about the time the Sleep() function requires

#else

	static const Int LOOPS_MAX_GRANULARITY = 512;						// 1536 ns maximum granularity
	static const Int LOOPS_BEFORE_YIELD = 4096;							// 12288 ns: a little higher than the minimum possible usleep() duration
	static const Int LOOPS_BEFORE_SLEEP = 16384;						// 49152 ns: until we take a longer usleep() and restart all over

#endif

	// Special values for state.
	static const UInt LOCK_ACQUIRE = 1; 
	static const UInt LOCK_SPIN = 2; 
	static const UInt LOCK_RELEASE = 3; 
	static const UInt MAX_STATE_ENUM = 255; 

	// Using no state might indicate a successful acquire or release operation on the resource.
	using SwitchDelegate = void (*)(CpuYieldState* state, const void* resource);

	Int	_count;
	Int	_loopSize;
};

static_assert(sizeof(CpuYieldState) == 2 * sizeof(Int), "wrong CpuYieldState size");

extern "C" MAXON_ATTRIBUTE_DLL_PUBLIC CpuYieldState::SwitchDelegate g_CpuYieldDelegate;

// Class that implements exponential backoff.
class	CpuYield : protected CpuYieldState
{
public:
	CpuYield()
	{
		_count = 0;
		_loopSize = LOOPS_START_COUNT;
	}

	void Reset()
	{
		_count = 0;
		_loopSize = LOOPS_START_COUNT;
	}

	//----------------------------------------------------------------------------------------
	/// Pauses a little while until the contended resource hopefully becomes available again.
	/// Depending on the number of calls this will either just do a light spin loop or it 
	/// might put the thread to sleep. Furthermore offending threads might be logged to diagnose
	/// deadlocks or bad performance.
	/// @param[in] res								The contended resource because of which Pause has to be called. Might be a nullptr.
	//----------------------------------------------------------------------------------------
	void Pause(const void* res = nullptr)
	{
		if (MAXON_LIKELY(_count <= LOOPS_BEFORE_YIELD))
		{
			_count += _loopSize;

			Wait(_loopSize >> 3);

			_loopSize *= 2;

			// Restart again with smaller pause if the maximum granularity has been reached.
			if (_loopSize > LOOPS_MAX_GRANULARITY)
				_loopSize = LOOPS_START_COUNT;
		}
		else
		{
			// Jump into the kernel for more complex handling, e.g. ask the OS to switch to a different thread to decrease contention.
			if (MAXON_LIKELY(g_CpuYieldDelegate != nullptr))
				g_CpuYieldDelegate(this, res);
		}
	}

	static void Wait(Int cnt)
	{
		for (; cnt > 0; cnt--)
		{
			_mm_pause();
			_mm_pause();
			_mm_pause();
			_mm_pause();

			_mm_pause();
			_mm_pause();
			_mm_pause();
			_mm_pause();
		}
	}

private:

#ifndef MAXON_TARGET_CPU_INTEL
	// stylecheck.naming=false

	static inline void	_mm_pause()
	{
		for (Int j = 0; j < 16; j++)
			asm volatile ("nop" : : : "memory");
	}
#endif
};

} // namespace maxon

#endif // CPUYIELD_H__
