#ifndef SERIALIZER_H__
#define SERIALIZER_H__

#include "maxon/apibase.h"
#include "maxon/lockservices.h"

namespace maxon
{

/// @cond INTERNAL

#ifndef CORESERIALIZER_H__
	class CoreSerializerJob;

	struct CoreSerializerPOD
	{
		AtomicPtr<CoreSerializerJob> _head;
		AtomicPtr<CoreSerializerJob> _switchHead;
	};
#endif

template <typename FN> class SerializerJobWrapper
{
public:
	explicit SerializerJobWrapper(FN src) : _obj(std::forward<FN>(src)) {}

	//----------------------------------------------------------------------------------------
	/// @param[in] buf								Pointer to buffer for SerializerJobWrapper (guaranteed to be valid).
	//----------------------------------------------------------------------------------------
	static void* ConstructWrapper(void* buf, void* fn, CoreSerializerCallback& callback)
	{
		callback = InvokeAndDestruct;
		return new (buf) SerializerJobWrapper<FN>(*(FN*)fn);
	}

	//----------------------------------------------------------------------------------------
	/// @param[in] param							Pointer to this SerializerJobWrapper (guaranteed to be valid).
	//----------------------------------------------------------------------------------------
	static void Invoke(void* param)
	{
		SerializerJobWrapper& self = *(SerializerJobWrapper*) param;

		// Use void cast because theGCC maxon::PrivateMuteUnusedHelper may not work for functions which return void.
		(void) self._obj();
	}

	//----------------------------------------------------------------------------------------
	/// @param[in] param							Pointer to this SerializerJobWrapper (guaranteed to be valid).
	//----------------------------------------------------------------------------------------
	static void InvokeAndDestruct(void* param)
	{
		SerializerJobWrapper& self = *(SerializerJobWrapper*) param;

		self._obj();
		self.~SerializerJobWrapper();
	}
private:
	typename std::remove_reference<FN>::type _obj;
};

/// @endcond

//----------------------------------------------------------------------------------------
/// A Serializer is similar to a mutex (e.g. Spinlock) and guarantees mutually exclusive
/// access to a shared resource. It has the benefit of better cache utilization because
/// requests from different threads can be combined/aggregated and executed by the thread
/// which first accessed the shared resource. Furthermore the code for your critical
/// section can be executed asynchronously if you don't have to wait for it to finish.
///
/// Suppose you have a shared resource you can safely access it in the following way:
/// @code
/// Serializer s;	// Serializer to protect your shared resource
///
/// s.EnqueueAndWait(
/// 	()[]
/// 	{
/// 		... access shared resource ...
/// 	});
/// @endcode
///
/// The equivalent code for a Spinlock/ScopedLock looks like this:
/// @code
/// Spinlock s;	// Spinlock to protect your shared resource
///
/// {
/// 	ScopedLock lock(s);
/// 		... access shared resource ...
/// }
/// @endcode
///
/// The code for critical sections is executed in order of the enqueues: If lambda A was
/// enqueued before lambda B it will be executed before it, the order of execution will
/// never be changed.
//----------------------------------------------------------------------------------------
struct Serializer : private CoreSerializerPOD
{
	//----------------------------------------------------------------------------------------
	/// Enqueues a lambda or object with operator () and waits until it has finished.
	/// The callable must not return a value, the Serializer is low level and does not support error handling via Result<>.
	/// @param[in] fn									Callable object.
	//----------------------------------------------------------------------------------------
	template <typename FN> void EnqueueAndWait(FN fn)
	{
		auto wrap = SerializerJobWrapper<decltype(fn)>(fn);

		LockServices::Serialize(*this, wrap.Invoke, &wrap);
	}

	//----------------------------------------------------------------------------------------
	/// Enqueues a lambda or object with operator (). This means the lambda might be asynchronously
	/// executed by a different thread and this method most likely returns before the lambda has
	/// been executed.
	/// The callable must not return a value, the Serializer is low level and does not support error handling via Result<>.
	/// @param[in] fn									Callable object.
	//----------------------------------------------------------------------------------------
	template <typename FN> void Enqueue(FN fn)
	{
		// make sure lambda isn't too big
		if (MAXCORESERIALIZERJOBSIZE >= SIZEOF(SerializerJobWrapper<decltype(fn)>))
		{
			LockServices::SerializeAsync(*this, SerializerJobWrapper<decltype(fn)>::ConstructWrapper, &fn);
		}
		else
		{
			WarningOutput("Lambda is too big to be executed asynchronously");
			EnqueueAndWait(std::forward<FN>(fn));
		}
	}
};

} // namespace maxon

#endif // SERIALIZER_H__

