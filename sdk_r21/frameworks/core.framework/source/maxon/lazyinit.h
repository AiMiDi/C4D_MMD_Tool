#ifndef LAZYINIT_H__
#define LAZYINIT_H__

#include "maxon/atomictypes.h"
#include "maxon/cpuyield.h"
#include "maxon/threadsaferef.h"

namespace maxon
{

/// @addtogroup THREADING Threading
/// @{

//----------------------------------------------------------------------------------------
/// Thread-safe helper class for single-threaded lazy initialization.
///
/// Typical usage case is a method which initializes data on first call, for example
///
/// @code
/// class Sample
/// {
/// public:
/// 	MyObject* GetObject()
/// 	{
/// 		_state.Init(
/// 			[this]() -> Bool
/// 			{
/// 				// Your init code goes here.
/// 				// Return true if initialization was successful and false if it failed.
///					// Using type Result<void> instead of Bool for the return value is supported as well.
/// 				return true;
/// 			});
///
/// 		return _object;
/// 	}
/// private:
/// 	LazyInit _state;
/// 	MyObject* _object;
/// 	SomeMoreData _xyz;
/// };
/// @endcode
///
/// @note The code of the lambda must be single threaded, using multithreaded code will lead
/// to a deadlock! For potentially multithreaded initialization use LazyInitThreaded.
/// Performance note: Declaring a global LazyInit as a static member of a class will
/// degrade its performance because the compiler will guard its access with a slow and
/// unnecessary mutex. To avoid this move the global state outside of the class.
///
/// THREADSAFE.
//----------------------------------------------------------------------------------------
class LazyInit
{
	enum class STATE : Int32
	{
		UNINITIALIZED = 0,
		PENDING = 1,
		INITIALIZED = 2
	} MAXON_ENUM_LIST_CLASS(STATE);

	static void Dummy()
	{
	}

	static Bool ToBool(Bool v) { return v; }
	static Bool ToBool(ResultMem v) { return v == OK; }
	static Bool ToBool(const Result<void>& v) { return v == OK; }

public:
	//----------------------------------------------------------------------------------------
	/// Initializes an object by calling the specified method (and does nothing if the object
	/// has already been initialized).
	/// The method #fn will be executed on the current thread and must be executing quickly.
	/// It is not allowed to perform  multithreaded code as part of the initialization because
	/// this could deadlock and waiting threads would be busy-idling.
	/// @note The code of the lambda must be single threaded! Otherwise use LazyInitThreaded (and review your code thoroughly).
	/// THREADSAFE.
	/// @param[in] fn									Method (usually a lambda) to initialize something, must return a Bool or a Result<void>.
	/// @return												True/OK if initialization was successful or object has already been initialized, otherwise result of failed initialization.
	//----------------------------------------------------------------------------------------
	template <typename FN> MAXON_ATTRIBUTE_FORCE_INLINE auto Init(FN&& fn) -> decltype(fn())
	{
		STATE state = (STATE)_state.LoadAcquire();
		decltype(fn()) success = typename std::conditional<std::is_same<decltype(fn()), Bool>::value, Bool, ResultMem>::type(true);

		if (MAXON_UNLIKELY(state != STATE::INITIALIZED))
		{
			CpuYield wait;

			do
			{
				// change state to pending if is currently uninitialized
				if ((state == STATE::UNINITIALIZED) && _state.TryCompareAndSwap((Int32)STATE::PENDING, (Int32)STATE::UNINITIALIZED))
				{
					// do lazy initialization over here
					success = fn();
					_state.StoreRelease(ToBool(success) ? (Int32)STATE::INITIALIZED : (Int32)STATE::UNINITIALIZED);
					break;
				}

				// idle
				wait.Pause(this);

				// refetch state
				state = (STATE)_state.LoadAcquire();
			} while (state != STATE::INITIALIZED);
		}
		return success;
	}

	//----------------------------------------------------------------------------------------
	/// Resets an object by calling the specified method. Does nothing if the object has already
	/// been reset.
	/// THREADSAFE.
	/// @param[in] fn									Optional method (usually a lambda) to reset something.
	//----------------------------------------------------------------------------------------
	template <typename FN = decltype(Dummy)> void Reset(FN&& fn = Dummy)
	{
		STATE state = (STATE)_state.LoadAcquire();

		if (state != STATE::UNINITIALIZED)
		{
			CpuYield wait;

			do
			{
				// change state to pending if is currently initialized
				if ((state == STATE::INITIALIZED) && _state.TryCompareAndSwap((Int32)STATE::PENDING, (Int32)STATE::INITIALIZED))
				{
					// call optional reset method
					fn();
					_state.StoreRelease((Int32)STATE::UNINITIALIZED);
					break;
				}

				// idle
				wait.Pause(this);

				// refetch state
				state = (STATE)_state.LoadAcquire();
			} while (state != STATE::UNINITIALIZED);
		}
	}

	//----------------------------------------------------------------------------------------
	/// Returns if the object already has been initialized.
	/// THREADSAFE.
	/// @return												True if initialization was successful.
	//----------------------------------------------------------------------------------------
	Bool IsInitialized() const
	{
		return (STATE)_state.LoadAcquire() == STATE::INITIALIZED;
	}

	//----------------------------------------------------------------------------------------
	/// Returns if the object already has been initialized.
	/// THREADSAFE.
	/// @return												True if initialization was successful.
	//----------------------------------------------------------------------------------------
	explicit operator Bool() const
	{
		return IsInitialized();
	}

private:
	AtomicInt32 _state;
};

/// @}

} // namespace maxon

#endif // LAZYINIT_H__
