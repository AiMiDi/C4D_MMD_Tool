#ifndef GENERICDATA_H__
#define GENERICDATA_H__

#include "maxon/apibase.h"

namespace maxon
{

//----------------------------------------------------------------------------------------
/// GenericData wraps an object of arbitary type. Therefore it's similar to Data, but it
/// supports less operations:
/// - GenericData can be moved, but it can't be copied.
/// - The destructor of the wrapped object is called properly.
/// - You can obtain the wrapped object with Get, but you have to know it's exact type at compile-time.
/// - You can't query the type at runtime.
///
/// The advantage is that you don't need to register the type of the wrapped object as a DataType.
//----------------------------------------------------------------------------------------
class GenericData
{
public:
	//----------------------------------------------------------------------------------------
	/// Constructs an empty GenericData.
	//----------------------------------------------------------------------------------------
	GenericData() = default;

	//----------------------------------------------------------------------------------------
	/// Constructs a GenericData by moving the contents of src to the new GenericData.
	/// src will be an empty GenericData afterwards.
	/// @param[in,out] src						The source object.
	//----------------------------------------------------------------------------------------
	GenericData(GenericData&& src) : _ptr(src._ptr), _free(src._free)
	{
		src._ptr = nullptr;
		src._free = nullptr;
	}

	MAXON_OPERATOR_MOVE_ASSIGNMENT(GenericData);

	//----------------------------------------------------------------------------------------
	/// Resets this GenericData to an empty object. This frees any previously set value.
	//----------------------------------------------------------------------------------------
	void Reset()
	{
		if (_free)
		{
			_free(this);
		}
	}

	//----------------------------------------------------------------------------------------
	/// Destructs this GenericData. This frees any previously set value.
	//----------------------------------------------------------------------------------------
	~GenericData()
	{
		Reset();
	}

	//----------------------------------------------------------------------------------------
	/// Initializes this GenericData with value. This frees any previously set value at first.
	/// @param[in] value							The value to wrap.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	template <typename T> Result<void> Set(T&& value)
	{
		iferr_scope;
		using TT = typename std::decay<T>::type;
		TT* v = NewObj(TT, std::forward<T>(value)) iferr_return;
		Reset();
		_ptr = v;
		_free = &Free<TT>;
		return OK;
	}

	//----------------------------------------------------------------------------------------
	/// Checks if this GenericData is empty.
	/// @return												True if this GenericData has no wrapped value, false otherwise.
	//----------------------------------------------------------------------------------------
	Bool IsEmpty() const
	{
		return _ptr == nullptr;
	}

	//----------------------------------------------------------------------------------------
	/// Checks if this GenericData has a wrapped value.
	/// @return												True if this GenericData has a wrapped value, false otherwise.
	//----------------------------------------------------------------------------------------
	Bool IsPopulated() const
	{
		return _ptr != nullptr;
	}

	//----------------------------------------------------------------------------------------
	/// Returns the wrapped value. The type T has to match the exact type of the wrapped value,
	/// otherwise the behaviour is undetermined. There is no check that the type matches.
	/// @tparam T											The type of the wrapped value.
	/// @return												The wrapped value of type T.
	//----------------------------------------------------------------------------------------
	template <typename T> const T& Get() const
	{
		DebugAssert(_ptr);
		return *reinterpret_cast<const T*>(_ptr);
	}

	/// @copydoc Get
	template <typename T> T& Get()
	{
		DebugAssert(_ptr);
		return *reinterpret_cast<T*>(_ptr);
	}

	//----------------------------------------------------------------------------------------
	/// Returns a pointer to the wrapped value.
	/// @return												Pointer to the wrapped values.
	//----------------------------------------------------------------------------------------
	const void* GetPointer() const
	{
		return _ptr;
	}

	/// @copydoc GetPointer
	void* GetPointer()
	{
		return _ptr;
	}

private:
	template <typename T> static void Free(GenericData* v)
	{
		DeleteObj(reinterpret_cast<T*&>(v->_ptr));
		v->_free = nullptr;
	}

	void* _ptr = nullptr;
	void (*_free) (GenericData*) = nullptr;
};

}

#endif // GENERICDATA_H__
