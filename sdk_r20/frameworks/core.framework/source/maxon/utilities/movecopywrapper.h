#ifndef MOVECOPYWRAPPER_H__
#define MOVECOPYWRAPPER_H__

#include "maxon/apibase.h"
#include "maxon/errorbase.h"

namespace maxon
{


//----------------------------------------------------------------------------------------
/// This wrapper helps to capture objects which require CopyFrom() in a lambda.
/// The get method will return an error if copying the object into the wrapper failed.
/// Of course move construction and assignment are supported too.
/// @tparam T											Type of object to wrapped.
/// @code
/// JobRef EnqueueSendJob(const BaseArray<Char>& jobdata)
/// {
/// 	return JobRef::Enqueue(
/// 		[this, copy = CopyWrapper<BaseArray<Char>>(jobdata)]() -> Result<void>
/// 		{
///				iferr_scope;
///				const BaseArray<Char>& array = copy.Get() iferr_return;
/// 			return _stream.Write(array.GetFirst(), array.GetCount());
/// 		},
/// 		_queue);
/// }
/// @endcode
//----------------------------------------------------------------------------------------
template <typename T> class CopyWrapper
{
	mutable T _value;
	T* _ptr = nullptr;

public:
	CopyWrapper()
	{
	}

	//----------------------------------------------------------------------------------------
	/// Copies the source object into the wrapper. Get() will return an error if the copy failed.
	/// @param[in] src								Object to be copied into the wrapper.
	//----------------------------------------------------------------------------------------
	explicit CopyWrapper(const T& src)
	{
		_ptr = _value.CopyFrom(src) == OK ? &_value : nullptr;
	}

	//----------------------------------------------------------------------------------------
	/// Moves the source object into the wrapper. Following Get()s will succeed because the move can't fail.
	/// @param[in] src								Object to be moved into the wrapper.
	//----------------------------------------------------------------------------------------
	explicit CopyWrapper(T&& src) : _value(std::move(src)), _ptr(&_value)
	{
	}

	//----------------------------------------------------------------------------------------
	/// Copies the source wrapper. Get() will return an error if the copy failed.
	/// @param[in] src								Wrapper to be copied.
	//----------------------------------------------------------------------------------------
	CopyWrapper(const CopyWrapper& src)
	{
		_ptr = _value.CopyFrom(src._value) == OK ? &_value : nullptr;
	}

	//----------------------------------------------------------------------------------------
	/// Moves the source wrapper. Following Get()s will succeed because the move can't fail.
	/// @param[in] src								Wrapper to be moved.
	//----------------------------------------------------------------------------------------
	CopyWrapper(CopyWrapper&& src) : _value(std::move(src._value)), _ptr(src._ptr ? &_value : nullptr)
	{
		src._ptr = nullptr;
	}
	
	//----------------------------------------------------------------------------------------
	/// Copy assigns the source wrapper. Get() will return an error if the copy failed.
	/// @param[in] src								Wrapper to be copied.
	//----------------------------------------------------------------------------------------
	CopyWrapper& operator = (const CopyWrapper& src)
	{
		if (this != &src)
			_ptr = _value.CopyFrom(src._value) == OK ? &_value : nullptr;
		
		return *this;
	}

	//----------------------------------------------------------------------------------------
	/// Move assign the source wrapper. Following Get()s will succeed because the move can't fail.
	/// @param[in] src								Wrapper to be moved.
	//----------------------------------------------------------------------------------------
	CopyWrapper& operator = (CopyWrapper&& src)
	{
		if (this != &src)
		{
			_value = std::move(src._value);
			_ptr = src._ptr ? &_value : nullptr;
			src._ptr = nullptr;
		}
		return *this;
	}

	//----------------------------------------------------------------------------------------
	/// Returns a reference to the wrapped object if the assignment or construction of the wrapper was successful.
	/// @return												Reference to wrapped object on success, error on failure.
	//----------------------------------------------------------------------------------------
	ResultRef<const T> Get() const
	{
		return _ptr;
	}

	//----------------------------------------------------------------------------------------
	/// Returns a reference to the wrapped object if the assignment or construction of the wrapper was successful.
	/// @return												Reference to wrapped object on success, error on failure.
	//----------------------------------------------------------------------------------------
	ResultRef<T> Get()
	{
		return _ptr;
	}
};

//----------------------------------------------------------------------------------------
/// Creates a CopyWrapper object based on the source object
/// @code
///	auto wrapped = CreateCopyWrapper(delegate) iferr_return;
/// auto lambda =
///   [callbackWrapper = std::move(wrapped)]() -> Result<void>
/// 	{
///			iferr_scope;
///			...
///			auto& callback = callbackWrapper.Get() iferr_return;
/// 		callback(...);
///			...
/// 	};
/// @endcode
/// @param[in] src								Object to be copied or moved into the wrapper.
/// @tparam T											Type of object to wrapped.
/// @return												Wrapped object on success.
//----------------------------------------------------------------------------------------

template <typename T> inline Result<CopyWrapper<typename std::decay<T>::type>> CreateCopyWrapper(T&& src)
{
	CopyWrapper<typename std::decay<T>::type> wrapper(std::forward<T>(src));
	iferr (wrapper.Get())
		return err;
	return wrapper;
}

} // namespace maxon

#endif // MOVECOPYWRAPPER_H__
