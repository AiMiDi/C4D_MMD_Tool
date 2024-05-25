#ifndef THREADLOCALPOINTER_H__
#define THREADLOCALPOINTER_H__

/// @file
/// Thread local data access.

/// @addtogroup THREADING
/// @{

#include "maxon/debugglobals.h"

#ifdef MAXON_TARGET_WINDOWS
	#include "maxon/win_include.h"
#else
	#include <pthread.h>
#endif

namespace maxon
{

//----------------------------------------------------------------------------------------
/// Thread local pointer (to a data structure).
/// Different threads may use this class to store different (local) values to it. These
/// values are typically pointers to data which is to be used by the calling thread only.
///
/// @note <B>Thread local pointers are a scarce resource.</B> Only a limited number of
/// them can be allocated: On Windows about 1000 and on OS X about 500.
/// You should only use them if they are the last and only resort to solve a problem.
/// Furthemore for performance reasons it is best to avoid thread local pointers at all and
/// instead use some sort of local context (for a group's jobs or with ParallelFor).
/// @note A thread local pointer is bound to a OS thread and the pointer is stored
/// for the lifetime of the thread.
//----------------------------------------------------------------------------------------
template <typename P> class	ThreadLocalPointer
{
#ifdef MAXON_TARGET_WINDOWS
	static const DWORD INVALID_KEY = TLS_OUT_OF_INDEXES;
#else
	static const pthread_key_t INVALID_KEY = ((pthread_key_t)-1);
#endif
public:

	~ThreadLocalPointer() { Reset(); }

	//----------------------------------------------------------------------------------------
	/// Allocates and initializes a thread local pointer.
	/// @note If you Init() an already initialized thread local pointer, a new one will be
	/// created and you cannot access the old one anymore. This behaviour is intended.
	/// @return												False if thread local pointer cannot be created.
	//----------------------------------------------------------------------------------------
	Bool Init()
	{
#ifdef MAXON_TARGET_WINDOWS
		_key = TlsAlloc();
		return _key != INVALID_KEY;
#else
		return pthread_key_create(&_key, nullptr) == 0;
#endif
	}

	//----------------------------------------------------------------------------------------
	/// Returns a thread local pointer value.
	/// @note If no value has been set yet, this function returns nullptr.
	/// THREADSAFE.
	/// @return												Thread local pointer value.
	//----------------------------------------------------------------------------------------
	inline P* Get() const
	{
		DebugAssert(IsValid(), "ThreadLocalPointer is uninitialized.");

#ifdef MAXON_TARGET_WINDOWS
		return (P*) TlsGetValue(_key);
#else
		return (P*) pthread_getspecific(_key);
#endif
	}

	operator P*() const
	{
		DebugAssert(IsValid(), "ThreadLocalPointer is uninitialized.");

#ifdef MAXON_TARGET_WINDOWS
		return (P*) TlsGetValue(_key);
#else
		return (P*) pthread_getspecific(_key);
#endif
	}


	//----------------------------------------------------------------------------------------
	/// Sets a thread local pointer value.
	/// @param[in] value							Thread local pointer value.
	/// THREADSAFE.
	/// @return												True unless an initial memory allocation failed or the initialization was missing.
	//----------------------------------------------------------------------------------------
	inline Bool Set(P* value)
	{
		DebugAssert(IsValid(), "ThreadLocalPointer is uninitialized.");

#ifdef MAXON_TARGET_WINDOWS
		return TlsSetValue(_key, (void*)value) != 0;
#else
		return pthread_setspecific(_key, (void*)value) == 0;
#endif
	}

	ThreadLocalPointer& operator =(P* value)
	{
		DebugAssert(IsValid(), "ThreadLocalPointer is uninitialized.");

#ifdef MAXON_TARGET_WINDOWS
		TlsSetValue(_key, (void*)value);
#else
		pthread_setspecific(_key, (void*)value);
#endif

		return *this;
	}

	//----------------------------------------------------------------------------------------
	/// Resets a thread local pointer to the uninitialized state.
	/// @return												False if previously uninitialized.
	//----------------------------------------------------------------------------------------
	Bool Reset()
	{
		Bool success = false;

		if (_key != INVALID_KEY)
		{
#ifdef MAXON_TARGET_WINDOWS
			success = TlsFree(_key) != 0;
#else
			success = pthread_key_delete(_key) == 0;
#endif
		}
		_key = INVALID_KEY;

		return success;
	}

	//----------------------------------------------------------------------------------------
	/// For debugging purposes.
	/// @return												True if initialized.
	//----------------------------------------------------------------------------------------
	Bool IsValid() const
	{
		return _key != INVALID_KEY;
	}

protected:
#ifdef MAXON_TARGET_WINDOWS
	DWORD	_key = INVALID_KEY;
#else
	pthread_key_t	_key = INVALID_KEY;
#endif
};

//----------------------------------------------------------------------------------------
/// Thread local pointer with notification upon destruction.
/// This is similar to ThreadLocalPointer but when a thread exits or the object is
/// destructed a per-thread notification is invoked which can be used to free resources.
///
/// @note <B>Thread local pointers are a scarce resource.</B> Only a limited number of
/// them can be allocated: On Windows about 100 (there are less FLS than TLS entries)
/// and on OS X about 500.
/// You should only use them if they are the last and only resort to solve a problem.
/// Furthemore for performance reasons it is best to avoid thread local variables at all and
/// instead use some sort of local context (for a group's jobs or with ParallelFor).
/// @note A thread local pointer is bound to a OS thread and the pointer is stored
/// for the lifetime of the thread. <B>If you create and use thread local variables in a
/// module you must ensure that they are destructed properly before the module is unloaded.</B>
/// @note On Windows this is 50 % slower than ThreadLocalPointer. Furthermore the code must
/// not use the (deprecated) fiber calls (ConvertThreadToFiber, CreateFiber etc.).
//----------------------------------------------------------------------------------------
#ifdef MAXON_TARGET_WINDOWS
template <typename P> class	ThreadLocalDestructiblePointer
{
	static const DWORD INVALID_KEY = FLS_OUT_OF_INDEXES;
public:
	~ThreadLocalDestructiblePointer()
	{
		Reset();
	}

	//----------------------------------------------------------------------------------------
	/// Allocates and initializes a thread local pointer.
	/// @note If you Init() an already initialized thread local variable, a new one will be
	/// created and you cannot access the old one anymore. This behaviour is intended.
	/// @note The notification will only be invoked if the pointer value is not a nullptr.
	/// @param[in] destructionNotification	To be called when a thread exits or the thread local pointer is destructed.
	/// @return												False if thread local variable cannot be created.
	//----------------------------------------------------------------------------------------
	Bool Init(void (*destructionNotification)(void*))
	{
		_key = FlsAlloc((PFLS_CALLBACK_FUNCTION)destructionNotification);
		return _key != INVALID_KEY;
	}

	//----------------------------------------------------------------------------------------
	/// Returns a thread local pointer value.
	/// @note If no value has been set yet, this function returns nullptr.
	/// THREADSAFE.
	/// @return												Thread local pointer value.
	//----------------------------------------------------------------------------------------
	inline P* Get() const
	{
		DebugAssert(IsValid(), "ThreadLocalDestructiblePointer is uninitialized.");

		return (P*) FlsGetValue(_key);
	}

	//----------------------------------------------------------------------------------------
	/// Sets a thread local pointer value.
	/// @param[in] value							Thread local pointer value.
	/// THREADSAFE.
	/// @return												True unless an initial memory allocation failed or the initialization was missing.
	//----------------------------------------------------------------------------------------
	inline Bool Set(P* value)
	{
		DebugAssert(IsValid(), "ThreadLocalDestructiblePointer is uninitialized.");

		return FlsSetValue(_key, (void*)value) != 0;
	}

	ThreadLocalDestructiblePointer& operator =(P* value)
	{
		DebugAssert(IsValid(), "ThreadLocalPointer is uninitialized.");

		Set(value);

		return *this;
	}

	//----------------------------------------------------------------------------------------
	/// Resets a thread local pointer to the uninitialized state.
	/// @note This will invoke the destruction notification.
	/// @return												False if previously uninitialized.
	//----------------------------------------------------------------------------------------
	Bool Reset()
	{
		Bool success = false;

		if (_key != INVALID_KEY)
			success = FlsFree(_key) != 0;
		_key = INVALID_KEY;

		return success;
	}

	//----------------------------------------------------------------------------------------
	/// For debugging purposes.
	/// @return												True if initialized.
	//----------------------------------------------------------------------------------------
	Bool IsValid() const
	{
		return _key != INVALID_KEY;
	}

private:
	DWORD	_key = INVALID_KEY;
};

#else
template <typename P> class	ThreadLocalDestructiblePointer : public ThreadLocalPointer<P>
{
public:
	//----------------------------------------------------------------------------------------
	/// Allocates and initializes a thread local pointer.
	/// @note If you Init() an already initialized thread local pointer, a new one will be
	/// created and you cannot access the old one anymore. This behaviour is intended.
	/// @note The notification will only be invoked if the pointer value is not a nullptr.
	/// @param[in] destructionNotification	To be called when a thread exits or the thread local pointer is destructed.
	/// @return												False if thread local pointer cannot be created.
	//----------------------------------------------------------------------------------------
	Bool Init(void (*destructionNotification)(void*))
	{
		return pthread_key_create(&this->_key, destructionNotification) == 0;
	}

	ThreadLocalDestructiblePointer& operator =(P* value)
	{
		pthread_setspecific(this->_key, (void*)value);
		return *this;
	}

private:
	Bool Init();
};
#endif

} // namespace maxon

/// @}

#endif // THREADLOCALPOINTER_H__
