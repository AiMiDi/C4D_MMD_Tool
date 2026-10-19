#ifndef SERIALIZER_H__
#define SERIALIZER_H__

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

namespace details
{

template <typename RET> class SerializerJobWrapperBase
{
public:
	RET&& GetResult()
	{
		return std::move(_result);
	}

protected:
	RET _result;
};

template <> class SerializerJobWrapperBase<void>
{
public:
	void GetResult()
	{
	}
};

template <typename FN, typename RET> class SerializerJobWrapper : public SerializerJobWrapperBase<RET>
{
public:
	explicit SerializerJobWrapper(FN&& src) : _obj(std::forward<FN>(src)) {}

	//----------------------------------------------------------------------------------------
	/// @param[in] buf								Pointer to buffer for SerializerJobWrapper (guaranteed to be valid).
	//----------------------------------------------------------------------------------------
	static void* ConstructWrapper(void* buf, void* fn, CoreSerializerCallback& callback)
	{
		callback = InvokeAndDestruct;
		return new (buf) SerializerJobWrapper<FN, RET>(std::move(*static_cast<typename std::remove_reference<FN>::type*>(fn)));
	}

	//----------------------------------------------------------------------------------------
	/// @param[in] param							Pointer to this SerializerJobWrapper (guaranteed to be valid).
	//----------------------------------------------------------------------------------------
	static void Invoke(void* param)
	{
		SerializerJobWrapper& self = *(SerializerJobWrapper*) param;

		if constexpr (std::is_void<RET>::value)
		{
			// Use void cast because the GCC maxon::PrivateMuteUnusedHelper may not work for functions which return void.
			(void) self._obj();
		}
		else
		{
			self._result = self._obj();
		}
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
	FN _obj;
};

}

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
class Serializer : private CoreSerializerPOD
{
public:
	//----------------------------------------------------------------------------------------
	/// Enqueues a lambda or object with operator () and waits until it has finished.
	/// @param[in] fn									Callable object.
	/// @return												Result of callable invocation.
	//----------------------------------------------------------------------------------------
	template <typename FN> auto EnqueueAndWait(FN&& fn) -> decltype(fn())
	{
		auto wrap = maxon::details::SerializerJobWrapper<FN, decltype(fn())>(std::forward<FN>(fn));

		LockServices::Serialize(*this, wrap.Invoke, &wrap);

		return wrap.GetResult();
	}

	//----------------------------------------------------------------------------------------
	/// Enqueues a lambda or object with operator (). This means the lambda might be asynchronously
	/// executed by a different thread and this method most likely returns before the lambda has
	/// been executed.
	/// The callable must not return a value, the Serializer is low level and does not support error handling via Result<>.
	/// @param[in] fn									Callable object.
	//----------------------------------------------------------------------------------------
	template <typename FN> void Enqueue(FN&& fn)
	{
		// make sure lambda isn't too big
		if (MAXCORESERIALIZERJOBSIZE >= SIZEOF(maxon::details::SerializerJobWrapper<FN, void>))
		{
			LockServices::SerializeAsync(*this, maxon::details::SerializerJobWrapper<FN, void>::ConstructWrapper, &fn);
		}
		else
		{
			WarningOutput("Lambda is too big to be executed asynchronously");
			EnqueueAndWait<FN>(std::forward<FN>(fn));
		}
	}
};

} // namespace maxon

#endif // SERIALIZER_H__

