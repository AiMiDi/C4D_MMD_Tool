#ifndef RESULTBASE_H__
#define RESULTBASE_H__

#ifndef APIBASE_H__
	#error "Do not include this file directly"
#endif

namespace maxon
{

//----------------------------------------------------------------------------------------
/// A single-valued enum to indicate success of an operation. This is used for comparisons
/// with Result, and for an Error constructor.
//----------------------------------------------------------------------------------------
enum class ERROR_OK
{
	VALUE = 1			///< The single value of this enum.
	// = 1: workaround for MSVC bug, otherwise MSVC allows X* = OK for arbitrary X
} MAXON_ENUM_LIST(ERROR_OK);

//----------------------------------------------------------------------------------------
/// OK can be used for comparison with a Result value and as a return value of a function
/// returning <tt>Result<void></tt>. It indicates the success of an operation:
/// @code
/// Result<void> Func()
/// {
///   if (...)
///     return OutOfMemoryError(MAXON_SOURCE_LOCATION);
///   return OK;
/// }
///
/// if (Func() == OK)
/// {
///    ...
/// }
/// @endcode
/// It can also be used where an Error is expected, then it constructs a null Error reference
/// which actually means that no error occurred.
//----------------------------------------------------------------------------------------
static const ERROR_OK OK = ERROR_OK::VALUE;

//----------------------------------------------------------------------------------------
/// A single-valued enum to indicate failure of an operation. This is used for comparisons
/// with Result.
//----------------------------------------------------------------------------------------
enum class ERROR_FAILED
{
	VALUE = 1,			///< The single value of this enum.
	// = 1: workaround for MSVC bug, otherwise MSVC allows X* = OK for arbitrary X
} MAXON_ENUM_LIST(ERROR_FAILED);

//----------------------------------------------------------------------------------------
/// FAILED can be used for comparison with a Result value. It indicates the failure of an operation:
/// @code
/// Result<void> Func()
/// {
///   if (...)
///     return OutOfMemoryError(MAXON_SOURCE_LOCATION);
///   return OK;
/// }
///
/// if (Func() == FAILED)
/// {
///    ...
/// }
/// @endcode
//----------------------------------------------------------------------------------------
static const ERROR_FAILED FAILED = ERROR_FAILED::VALUE;

namespace details
{

struct ResultOkError
{
	const Generic* GetReferencedError()
	{
		return nullptr;
	}

	template <typename T> operator ResultOk<T>()
	{
		return {};
	}
};

template <typename T> struct TmpErrType
{
	using type = ThreadReferencedError;
};

template <typename T> struct TmpErrType<ResultOk<T>>
{
	using type = ResultOkError;
};

#ifdef _HAS_RANGE_BASED_FOR_DIFFERING_TYPES
class RangeBasedForSentinel
{
};
#define PRIVATE_MAXON_RBF_SENTINEL(...) maxon::details::RangeBasedForSentinel
#else
#define PRIVATE_MAXON_RBF_SENTINEL(...) __VA_ARGS__
#endif

}

//----------------------------------------------------------------------------------------
/// Use ResultOk<T> instead of Result<T> as return type of a function which cannot fail,
/// but whose return value will be checked for errors nevertheless.
/// For example, this can happen if the function is overloaded and the other overload
/// may return an error. Now if within a template function the overload in a call is chosen
/// depending on the template arguments, the result has to be checked for an error,
/// so also the function which cannot fail has to return a value which is understood
/// by the error handling.
//----------------------------------------------------------------------------------------
template <typename T> class ResultOk
{
public:
	//----------------------------------------------------------------------------------------
	/// Constructs a new ResultOk with a default-constructed value.
	//----------------------------------------------------------------------------------------
	ResultOk() : _value() { }

	//----------------------------------------------------------------------------------------
	/// Constructs a new ResultOk with the given #value.
	/// @param[in] value							The value to use for the ResultOk.
	//----------------------------------------------------------------------------------------
	MAXON_IMPLICIT ResultOk(const T& value) : _value(value) { }

	//----------------------------------------------------------------------------------------
	/// Constructs a new ResultOk with the given #value.
	/// @param[in] value							The value to use for the ResultOk.
	//----------------------------------------------------------------------------------------
	MAXON_IMPLICIT ResultOk(T&& value) : _value(std::move(value)) { }

	//----------------------------------------------------------------------------------------
	/// Returns the result value.
	/// @return												Result value.
	//----------------------------------------------------------------------------------------
	const T& GetValue() const & { return _value; }

	/// @copydoc GetValue
	const T& UncheckedGetValue() const & { return _value; }

	MAXON_MEMBER_ACCESSORS(T, GetValue);

	MAXON_MEMBER_ACCESSORS(T, UncheckedGetValue);

	//----------------------------------------------------------------------------------------
	/// Returns always true because a ResultOk never contains an error.
	/// @param[in] ok									Use the global constant OK.
	/// @return												Always true.
	//----------------------------------------------------------------------------------------
	Bool operator ==(ERROR_OK ok) const { return true; }

	//----------------------------------------------------------------------------------------
	/// Returns always false because a ResultOk never contains an error.
	/// @param[in] failed							Use the global constant FAILED.
	/// @return												Always false.
	//----------------------------------------------------------------------------------------
	Bool operator ==(ERROR_FAILED failed) const { return false; }

	/// @private
	const ThreadReferencedError& GetErrorStorage() const { return GetZeroRef<ThreadReferencedError>(); }

protected:
	T _value;
};

template <typename T> class ResultOk<T&>
{
public:
	ResultOk() : _value(std::addressof(DefaultValue<T&>())) { }

	MAXON_IMPLICIT ResultOk(T& value) : _value(std::addressof(value)) { }

	T& GetValue() const { return *_value; }
	T& UncheckedGetValue() const { return *_value; }

	operator T&() const {return *_value; }

	Bool operator ==(ERROR_OK) const { return true; }

	Bool operator ==(ERROR_FAILED) const { return false; }

	const ThreadReferencedError& GetErrorStorage() const { return GetZeroRef<ThreadReferencedError>(); }

protected:
	T* _value;
};

template <> class ResultOk<void>
{
public:
	ResultOk() { }

	MAXON_IMPLICIT ResultOk(ERROR_OK) { }

	template <typename T2> MAXON_IMPLICIT ResultOk(const ResultOk<T2>& value) { }

	void GetValue() const { }
	void GetValue() { }

	void UncheckedGetValue() const { }
	void UncheckedGetValue() { }

	Bool operator ==(ERROR_OK) const { return true; }

	Bool operator ==(ERROR_FAILED) const { return false; }

	const ThreadReferencedError& GetErrorStorage() const { return GetZeroRef<ThreadReferencedError>(); }
};



template <typename T> class ResultRef;

//----------------------------------------------------------------------------------------
/// ResultMemT can be used as return type of functions which normally return a T, but might
/// fail only due to an out-of-memory situation and indicate this by the default value of T.
/// The typical use-case is for pointers or strong/unique references. You can't use ResultMemT when the default value of T
/// shall be a legal return value of the function, in that case you have to use Result.
/// @see ResultMem
/// @see ResultPtr
//----------------------------------------------------------------------------------------
template <typename T> class MAXON_WARN_UNUSED_CLASS ResultMemT
{
public:
	ResultMemT() : _value() { }

	MAXON_IMPLICIT ResultMemT(ERROR_FAILED) : _value() { }

	MAXON_IMPLICIT ResultMemT(const T& value) : _value(value) { }

	MAXON_IMPLICIT ResultMemT(T&& value) : _value(std::move(value)) { }

	MAXON_IMPLICIT ResultMemT(ERROR_OK) : _value(true) { static_assert(STD_IS_REPLACEMENT(same, T, Bool), "Constructor only allowed for ResultMemT<Bool>."); }

	MAXON_IMPLICIT ResultMemT(ResultOk<void>) : _value(true) { static_assert(STD_IS_REPLACEMENT(same, T, Bool), "Constructor only allowed for ResultMemT<Bool>."); }

	ResultMemT(const ResultMemT&) = default;
	ResultMemT& operator =(const ResultMemT&) = default;

	ResultMemT(ResultMemT&&) = default;
	ResultMemT& operator =(ResultMemT&&) = default;

	// Enables conversion of compatible types, e.g. from ResultMemT<StringInterface*> to ResultMemT<const StringInterface*>
	// or from pointer to reference like ResultMemT<StringInterface*> to ResultMemT<String>.
	template <typename T2, typename = typename std::enable_if<STD_IS_REPLACEMENT(constructible, T, T2*) && STD_IS_REPLACEMENT(pointer, T)>::type> MAXON_IMPLICIT ResultMemT(const ResultMemT<T2*>& result) : _value(result.GetValue()) { }
	template <typename T2, typename = typename std::enable_if<STD_IS_REPLACEMENT(constructible, T, T2*) && STD_IS_REPLACEMENT(pointer, T)>::type> MAXON_IMPLICIT ResultMemT(ResultMemT<T2*>&& result) : _value(std::move(result.GetValue())) { }

	// Enables conversion of inherited types, e.g. from ResultMemT<ArrayMap::Iterator> to ResultMemT<HybridMap::Iterator>.
	template <typename T2, typename = typename std::enable_if<STD_IS_REPLACEMENT(constructible, T, T2) && STD_IS_REPLACEMENT(pointer, T) == STD_IS_REPLACEMENT(pointer, T2)>::type> MAXON_IMPLICIT ResultMemT(const ResultMemT<T2>& result) : _value(result.GetValue()) { }
	template <typename T2, typename = typename std::enable_if<STD_IS_REPLACEMENT(constructible, T, T2) && STD_IS_REPLACEMENT(pointer, T) == STD_IS_REPLACEMENT(pointer, T2)>::type> MAXON_IMPLICIT ResultMemT(ResultMemT<T2>&& result) : _value(std::move(result.GetValue())) { }

	template <typename T2> MAXON_IMPLICIT ResultMemT(const ResultRef<T2>& result) : _value(result == OK) { static_assert(STD_IS_REPLACEMENT(same, T, Bool), "Constructor only allowed for Bool."); }

	/// @copydoc Result::operator ==(ERROR_OK)
	Bool operator ==(ERROR_OK ok) const { return IsOK(static_cast<const typename GetDirectlyReferencedType<T>::type*>(nullptr)); }

	/// @copydoc Result::operator ==(ERROR_FAILED)
	Bool operator ==(ERROR_FAILED failed) const { return !IsOK(static_cast<const typename GetDirectlyReferencedType<T>::type*>(nullptr)); }

	//----------------------------------------------------------------------------------------
	/// Returns the result value. This function must not be called when there is no value because an out-of-memory error occurred.
	/// @return												Result value.
	//----------------------------------------------------------------------------------------
	const T& GetValue() const & { DebugAssert(_value); return _value; }

	//----------------------------------------------------------------------------------------
	/// Returns the result value, or a default value in case of an out-of-memory error.
	/// @return												Result value (default value in case of an error).
	//----------------------------------------------------------------------------------------
	const T& UncheckedGetValue() const & { return _value; }

	MAXON_MEMBER_ACCESSORS(T, GetValue);

	MAXON_MEMBER_ACCESSORS(T, UncheckedGetValue);

	//----------------------------------------------------------------------------------------
	/// Returns the result value. This function is only supported if T is a pointer type.
	/// @return												Result value.
	//----------------------------------------------------------------------------------------
	T GetPointer() const { static_assert(STD_IS_REPLACEMENT(pointer, T), "Must be a pointer type"); return _value; }

private:
	// General case: Use Bool conversion of _value to check if memory allocation succeeded.
	Bool IsOK(const std::false_type*) const
	{
		return Bool(_value);
	}

	// Special case for reference classes: Use GetPointer() for the check as the Bool conversion isn't available for COW reference classes with IsEmpty() function.
	Bool IsOK(const void*) const
	{
		return _value.GetPointer() != nullptr;
	}

	T _value;
};

template <typename T> struct ForwardResultPtr : public ResultMemT<T*>
{
	using PTR = T*;
	using Super = ResultMemT<PTR>;
	MAXON_IMPLICIT ForwardResultPtr(const PTR& value) : Super(value) { }
	MAXON_IMPLICIT ForwardResultPtr(PTR&& value) : Super(std::move(value)) { }
	explicit ForwardResultPtr(const Super& src) : Super(src) { }
	explicit ForwardResultPtr(Super&& src) : Super(std::move(src)) { }
};

//----------------------------------------------------------------------------------------
/// Use this class as result type of functions that can fail in out-of-memory situations.
/// This allows to use the result in combination with iferr or Result<void> return values.
/// ResultMem accepts Bool, ResultPtr, ResultRef, pointers and strong/unique references in its constructors.
///
/// ResultMem is just a type alias for ResultMemT<Bool>.
//----------------------------------------------------------------------------------------
using ResultMem = ResultMemT<Bool>;


//----------------------------------------------------------------------------------------
/// ResultPtr<T> wraps a pointer. When the pointer is nullptr, this has to be interpreted
/// as an out-of-memory error condition.
///
/// ResultPtr<T> can be used instead of the more general
/// Result<T*> when only out-of-memory conditions can occur in a function. It will lead to
/// more efficient code.
///
/// All error handling features of the MAXON API
/// (such as iferr, iferr_return and Result) support ResultPtr.
///
/// ResultPtr<T> is just a type alias for ResultMemT<T*>.
//----------------------------------------------------------------------------------------
template <typename T> using ResultPtr = ResultMemT<T*>;


//----------------------------------------------------------------------------------------
/// ResultRef<T> wraps a pointer. When the pointer is nullptr, this has to be interpreted
/// as an out-of-memory error condition, otherwise GetValue() returns the pointer as a
/// C++ reference.
///
/// ResultRef<T> can be used instead of the more general
/// Result<T&> when only out-of-memory conditions can occur in a function. It will lead to
/// more efficient code.
///
/// Sometimes it is necessary to convert a ResultRef<T> to a ResultPtr<T>, for example
/// if the variable to which the result shall be assigned already exists:
/// @code
/// BaseArray<Int> array;
/// Int& ref = array.Append() iferr_return;
/// Int* ptr = ...;
/// if (some condition)
/// {
///   ptr = &array.Append() iferr_return;
/// }
/// @endcode
/// The result of the second call to Append has to be converted from ResultRef<Int> to ResultPtr<Int> so that (in the
/// successful case) #ptr can be set to a pointer to the new array element. For this purpose
/// the address-of operator & is overloaded at ResultRef to do exactly this conversion.
///
/// All error handling features of the MAXON API
/// (such as iferr, iferr_return and Result) support ResultRef.
//----------------------------------------------------------------------------------------
template <typename T> class MAXON_WARN_UNUSED_CLASS ResultRef
{
public:
	MAXON_IMPLICIT ResultRef(T* value = nullptr) : _value(value) { }

	MAXON_IMPLICIT ResultRef(T& value) : _value(std::addressof(value)) { }

	MAXON_IMPLICIT ResultRef(ERROR_FAILED) : _value(nullptr) { }

	// This avoids cases like "Func() = value;" where the writer expected Func() to return a T&, but it returns a ResultRef<T>.
	void operator =(T&) = delete;

	template <typename T2, typename = typename std::enable_if<(STD_IS_REPLACEMENT(same, const T, const T2) || STD_IS_REPLACEMENT(base_of, T, T2)) && (STD_IS_REPLACEMENT(const, T) >= STD_IS_REPLACEMENT(const, T2))>::type>
	MAXON_IMPLICIT ResultRef(const ResultRef<T2>& src) : _value(src.GetPointer()) { }

	template <typename T2, typename = typename std::enable_if<(STD_IS_REPLACEMENT(same, const T, const T2) || STD_IS_REPLACEMENT(base_of, T, T2)) && (STD_IS_REPLACEMENT(const, T) >= STD_IS_REPLACEMENT(const, T2))>::type>
	MAXON_IMPLICIT ResultRef(const ResultPtr<T2>& src) : _value(src.GetValue()) { }

	/// @copydoc Result::operator ==(ERROR_OK)
	Bool operator ==(ERROR_OK) const { return _value != nullptr; }

	/// @copydoc Result::operator ==(ERROR_FAILED)
	Bool operator ==(ERROR_FAILED) const { return _value == nullptr; }

	//----------------------------------------------------------------------------------------
	/// Returns the result value. This function must not be called when there is no value because an out-of-memory error occurred.
	/// @return												Result value.
	//----------------------------------------------------------------------------------------
	T& GetValue() const { DebugAssert(_value != nullptr); return *_value; }

	//----------------------------------------------------------------------------------------
	/// Returns the result value. The result of this function must not be used when there is no value (then it's an invalid C++ reference).
	/// @return												Result value.
	//----------------------------------------------------------------------------------------
	T& UncheckedGetValue() const { return *_value; }

	//----------------------------------------------------------------------------------------
	/// Returns the result pointer.
	/// @return												Result pointer.
	//----------------------------------------------------------------------------------------
	T* GetPointer() const { return _value; }

	//----------------------------------------------------------------------------------------
	/// Converts from a ResultRef<T> to a ResultPtr<T>.
	/// @note Usually it is a really bad idea to overload the address-of operator. But in this
	/// case it can't do any harm because ResultRef isn't used in contexts where the normal
	/// address-of operator is used. And if & was applied to a ResultRef with the expectation
	/// of returning a pointer, the compiler would complain because ResultPtr doesn't mimic
	/// pointers at all.
	/// @return												This ResultRef, cast to a ResultPtr.
	//----------------------------------------------------------------------------------------
	const ResultPtr<T>& operator &() const { return *reinterpret_cast<const ResultPtr<T>*>(this); }

private:
	T* _value;
};


//----------------------------------------------------------------------------------------
/// This enum is used for CreateError() to indicate the desired error class.
//----------------------------------------------------------------------------------------
enum class ERROR_TYPE
{
	OUT_OF_MEMORY,		///< Create an OutOfMemoryError.
	NULLPTR,					///< Create a NullptrError.
	ILLEGAL_ARGUMENT,	///< Create an IllegalArgumentError.
	ILLEGAL_STATE,		///< Create an IllegalStateError.
	NOT_IMPLEMENTED,	///< Create a FunctionNotImplementedError.
	UNRESOLVED,				///< Create an UnresolvedError.
	UNKNOWN						///< Create an UnknownError.
} MAXON_ENUM_LIST(ERROR_TYPE);


//----------------------------------------------------------------------------------------
/// CreateErrorPtr is declared as a pure function to allow the compiler to eliminate the call if the error isn't used anywhere. This might
/// happen when iferr is used for error detection only (and the ThreadReferencedError isn't used anywhere).
/// @code
/// iferr (Int* ptr = array.Append(42))
///   return false;
/// obj._valueIsAt = ptr;
/// @endcode
/// @private
//----------------------------------------------------------------------------------------
#ifdef MAXON_COMPILER_MSVC
	const Error* CreateErrorPtr(MAXON_SOURCE_LOCATION_DECLARATION, ERROR_TYPE type);
#elif (defined MAXON_COMPILER_INTEL)
	// The ICC knows pure, but at least V15 is not able to omit CreateErrorPtr.
	__declspec(pure) const Error* CreateErrorPtr(MAXON_SOURCE_LOCATION_DECLARATION, ERROR_TYPE type);
#else
	// returns_nonnull requires at least GCC 4.9  or Clang 3.5
	#if !defined(MAXON_COMPILER_GCC) || (MAXON_COMPILER_GCC >= 490)
		const Error* CreateErrorPtr(MAXON_SOURCE_LOCATION_DECLARATION, ERROR_TYPE type) __attribute__((pure, returns_nonnull));
	#else
		const Error* CreateErrorPtr(MAXON_SOURCE_LOCATION_DECLARATION, ERROR_TYPE type) __attribute__((pure));
	#endif
#endif

//----------------------------------------------------------------------------------------
/// This function can be used in low-level header files which cannot include error.h, but
/// have to create errors. It can and should only be used in a return statement of a function
/// returning a Result value.
///
/// Example:
/// @code
/// return CreateError(MAXON_SOURCE_LOCATION, ERROR_TYPE::ILLEGAL_ARGUMENT);
/// @endcode
/// is equivalent to
/// @code
/// return IllegalArgumentError(MAXON_SOURCE_LOCATION);
/// @endcode
/// but the former doesn't require to include error.h.
///
/// The returned error will be referenced by the current thread.
/// @param[in] allocLocation			Use MAXON_SOURCE_LOCATION as argument so that file and line information is set for the error.
/// @param[in] type								The desired error class.
/// @return												Error object of the given class.
//----------------------------------------------------------------------------------------
inline ThreadReferencedError CreateError(MAXON_SOURCE_LOCATION_DECLARATION, ERROR_TYPE type)
{
	return ThreadReferencedError::CreateFromReferencedError(CreateErrorPtr(MAXON_SOURCE_LOCATION_FORWARD, type));
}


const Error* PrivateSystemSetCurrentError(const Error& error);
const Error* PrivateSystemSetCurrentError(Error&& error);
void PrivateSetError(Error& dest, const Error* src);


//----------------------------------------------------------------------------------------
/// Base class for Result.
//----------------------------------------------------------------------------------------
template <typename T> class ResultBase
{
public:
	//----------------------------------------------------------------------------------------
	/// The type of the value of the Result.
	//----------------------------------------------------------------------------------------
	using ValueType = T;

protected:
	using CopyType = typename ByValueParam<T>::type;
	using MoveType = typename std::conditional<STD_IS_REPLACEMENT(reference, CopyType), T&&, DummyParamType&>::type;
	using DeleteType = const DummyParamType&&;
	template <typename T2> using ConstructibleFrom = std::enable_if<STD_IS_REPLACEMENT(constructible, T, T2)>;

public:
	static constexpr Bool HAS_ERROR = true;

	ResultBase() : _value() { _error._error = nullptr; }

	//----------------------------------------------------------------------------------------
	/// Constructs a new ResultBase with the given value and no error.
	/// @param[in] value							Result value.
	//----------------------------------------------------------------------------------------
	explicit ResultBase(CopyType value) : _value(value) { _error._error = nullptr; }

	//----------------------------------------------------------------------------------------
	/// Constructs a new ResultBase with the given value and no error.
	/// @param[in] value							Result value.
	//----------------------------------------------------------------------------------------
	explicit ResultBase(MoveType value) : _value(std::move(value)) { _error._error = nullptr; }

	//----------------------------------------------------------------------------------------
	/// Returns the result value. A DebugAssert will trigger if this is invoked when there is an error.
	/// @return												Result value.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE const T& GetValue() const & { DebugAssert(!_error._error); return _value; }

	//----------------------------------------------------------------------------------------
	/// Returns the result value. In case of an error there is no value, then this function returns a default value.
	/// @return												Result value (or a default value in case of an error).
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE const T& UncheckedGetValue() const & { return _value; }

	MAXON_MEMBER_ACCESSORS(T, GetValue);

	MAXON_MEMBER_ACCESSORS(T, UncheckedGetValue);

	//----------------------------------------------------------------------------------------
	/// Returns the result value and error. If there is an error, the parameter #error will be set to the
	/// error and a default value is returned.
	/// @param[out] error							This parameter receives the error (or a nullptr if there is no error).
	/// @return												Result value (or a default value in case of an error).
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE const T& GetValueAndError(ThreadReferencedError& error) const & { error = _error; return _value; }

	/// @copydoc GetValueAndError
	MAXON_ATTRIBUTE_FORCE_INLINE T GetValueAndError(ThreadReferencedError& error) && { error = _error; return std::move(_value); }

	/// @copydoc GetValueAndError
	MAXON_ATTRIBUTE_FORCE_INLINE const T& GetValueAndError(Error& error) const & { PrivateSetError(error, _error._error); return _value; }

	/// @copydoc GetValueAndError
	MAXON_ATTRIBUTE_FORCE_INLINE T GetValueAndError(Error& error) && { PrivateSetError(error, _error._error); return std::move(_value); }

	//----------------------------------------------------------------------------------------
	/// Returns a reference to the ThreadReferencedError storage in which the Result stores its error.
	/// @return												The ThreadReferencedError where the error (if any) is stored.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE const ThreadReferencedError& GetErrorStorage() const { return _error; }

	/// @copydoc GetErrorStorage
	MAXON_ATTRIBUTE_FORCE_INLINE ThreadReferencedError& GetErrorStorage() { return _error; }

protected:
	ThreadReferencedError _error;
	T _value;
};

template <typename T> class ResultBase<T&>
{
public:
	using ValueType = T&;
	using CopyType = T&;
	using MoveType = DummyParamType&;
	using DeleteType = typename std::decay<T>::type&&; // for Result<const T&> we have to delete constructor from T&& (otherwise constructor from const T& would be chosen for T temporaries and we'd end up with a reference to a temporary object).
	template <typename T2> using ConstructibleFrom = std::enable_if<STD_IS_REPLACEMENT(same, T&, T2) || STD_IS_REPLACEMENT(same, typename std::remove_const<T>::type&, T2)>;
	static constexpr Bool HAS_ERROR = true;

	ResultBase() : _value(const_cast<T*>(STD_IS_REPLACEMENT(const, T) ? reinterpret_cast<const T*>(std::addressof(DefaultValue<typename std::conditional<STD_IS_REPLACEMENT(const, T), T&, const Int&>::type>())) : std::addressof(GetZeroRef<T>()))) { _error._error = nullptr; }

	MAXON_IMPLICIT ResultBase(CopyType value) : _value(std::addressof(value)) { _error._error = nullptr; }

	MAXON_ATTRIBUTE_FORCE_INLINE T& GetValue() const { DebugAssert(!_error._error); return *_value; }

	MAXON_ATTRIBUTE_FORCE_INLINE T& GetValueAndError(ThreadReferencedError& error) const { error = _error; return *_value; }

	MAXON_ATTRIBUTE_FORCE_INLINE T& GetValueAndError(Error& error) const { PrivateSetError(error, _error._error); return *_value; }

	MAXON_ATTRIBUTE_FORCE_INLINE const ThreadReferencedError& GetErrorStorage() const { return _error; }

	MAXON_ATTRIBUTE_FORCE_INLINE ThreadReferencedError& GetErrorStorage() { return _error; }

	MAXON_ATTRIBUTE_FORCE_INLINE T& UncheckedGetValue() const { return *_value; }

	//----------------------------------------------------------------------------------------
	/// Converts from a Result<T&> to a Result<T*>.
	/// @note Usually it is a really bad idea to overload the address-of operator. But in this
	/// case it can't do any harm because ResultRef isn't used in contexts where the normal
	/// address-of operator is used. And if & was applied to a Result with the expectation
	/// of returning a pointer, the compiler would complain because Result doesn't mimic
	/// pointers at all.
	/// @return												This Result, cast to a Result<T*>.
	//----------------------------------------------------------------------------------------
	const Result<T*>& operator &() const { return *reinterpret_cast<const Result<T*>*>(static_cast<const Result<T&>*>(this)); }

protected:
	ThreadReferencedError _error;
	T* _value;
};

template <> class ResultBase<void>
{
public:
	using ValueType = void;
	using CopyType = const DummyParamType&;
	using MoveType = DummyParamType&;
	using DeleteType = const DummyParamType&&;
	template <typename T2> using ConstructibleFrom = std::enable_if<AlwaysFalse<T2>::value>;
	static constexpr Bool HAS_ERROR = true;

	ResultBase() { _error._error = nullptr; }

	MAXON_ATTRIBUTE_FORCE_INLINE void GetValue() const { DebugAssert(!_error._error); }

	MAXON_ATTRIBUTE_FORCE_INLINE void GetValueAndError(ThreadReferencedError& error) const { error = _error; }

	MAXON_ATTRIBUTE_FORCE_INLINE void UncheckedGetValue() const { }

	MAXON_ATTRIBUTE_FORCE_INLINE const ThreadReferencedError& GetErrorStorage() const { return _error; }

	MAXON_ATTRIBUTE_FORCE_INLINE ThreadReferencedError& GetErrorStorage() { return _error; }

protected:
	explicit ResultBase(const Error* error) { _error._error = error; }

	ThreadReferencedError _error;
};

template <typename T, Bool IS_OBJECT_REF> class PrivateIsErrorClassHelper : public std::false_type
{
};

template <typename T> class PrivateIsErrorClassHelper<T, true> : public std::remove_reference<T>::type::DirectlyReferencedType::HasBaseDetector::template Check<ErrorInterface>
{
};

template <typename T> class IsErrorClass : public PrivateIsErrorClassHelper<T, IsObjectReferenceClass<T>::value>
{
};

template <typename T> class ForwardRef;

template <typename T> class IsErrorClass<ForwardRef<T>> : public std::false_type
{
};

template <typename RESULT_TYPE, typename ENABLE> class ResultSuper
{
public:
	using type = ResultBase<RESULT_TYPE>;
};

template <typename RESULT_TYPE> class ResultSuper<RESULT_TYPE, typename SFINAEHelper<void, typename RESULT_TYPE::template ResultFunctions<ResultBase<RESULT_TYPE>>>::type>
	: public RESULT_TYPE::template ResultFunctions<ResultBase<RESULT_TYPE>>
{
public:
	using type = ResultSuper;
	using Base = typename RESULT_TYPE::template ResultFunctions<ResultBase<RESULT_TYPE>>;

	ResultSuper() = default;
	explicit ResultSuper(const RESULT_TYPE& value) : Base(value) { }
	explicit ResultSuper(RESULT_TYPE&& value) : Base(std::move(value)) { }

	// redeclare GetValue in case we inherit a function with that name from RESULT_TYPE::ResultSuper
	const RESULT_TYPE& GetValue() const & { DebugAssert(!this->_error.GetReferencedError()); return this->_value; }
	RESULT_TYPE& GetValue() & { DebugAssert(!this->_error.GetReferencedError()); return this->_value; }
	RESULT_TYPE GetValue() && { DebugAssert(!this->_error.GetReferencedError()); return std::move(this->_value); }
};

template <typename RESULT_TYPE> class ResultSuper<RESULT_TYPE&, typename SFINAEHelper<void, typename RESULT_TYPE::template ResultFunctions<ResultBase<RESULT_TYPE&>>>::type>
	: public RESULT_TYPE::template ResultFunctions<ResultBase<RESULT_TYPE&>>
{
public:
	using type = ResultSuper;
	using Base = typename RESULT_TYPE::template ResultFunctions<ResultBase<RESULT_TYPE&>>;

	ResultSuper() = default;
	explicit ResultSuper(RESULT_TYPE& value) : Base(value) { }

	RESULT_TYPE& GetValue() const { DebugAssert(!this->_error.GetReferencedError()); return *this->_value; }
};

MAXON_MEMBERTYPE_DETECTOR(IsForwardRef, IsForwardRef, std::false_type);

//----------------------------------------------------------------------------------------
/// The Result class wraps a result value and may also hold an error value.
/// It has to be used for functions or methods which have to indicate that an error
/// happened during their execution so that no normal result value could be computed:
/// @code
/// Result<Int> Func()
/// {
///   if (everything ok)
///     return 123;
///   else
///     return IllegalStateError(MAXON_SOURCE_LOCATION, "Illegal state in Func."_s);
/// }
/// @endcode
/// Functions which don't return a value on success use <tt>Result<void></tt> as result type and
/// <tt>return OK;</tt> as return statement for the successful case. Those functions can also use
/// a ResultMem value in the return statement, this will set an OutOfMemoryError if the
/// ResultMem is false:
/// @code
/// Result<void> Func(MyObj*& ptr)
/// {
///   if (some condition)
///     return OK;
///   ptr = NewObj(MyObj);
///   return ResultMem(ptr != nullptr);
/// }
/// @endcode
/// The result value and error can be obtained via GetValue() and GetError(), respectively.
/// To check if there was an error, you can simply write <tt>result == OK</tt> or <tt>result == FAILED</tt>.
/// There are also the macros #iferr and #iferr_return which help to write error handling code.
///
/// @warning This class is not thread-safe. The Result object just contains a pointer to an Error object and
/// does not increment the reference counter. Instead of storing the result somewhere, use the direct Error class.
///
/// In the following example the Result is a member of a class. The Result will keep the pointer to the Error object,
/// but it does not keep it alive.
/// @code
/// class Foo
/// {
/// private:
///   Result<void> _result; // BAD!
/// public:
///   Result<void> GetResult()
///   {
///     return _result;
///   }
/// }
/// @endcode
/// The alternative is to store the error object. The Error object is reference counted and your object of Foo will keep a
/// reference to it, until the object itself is freed. As long as no error is set (GetResult() == OK) will return true.
/// @code
/// class Foo
/// {
/// private:
///   Error _err; // FINE!
/// public:
///   Result<void> GetResult()
///   {
///     return _err;
///   }
/// }
/// @endcode
///
/// @tparam RESULT_TYPE						Type of result value.
/// @see @$ref error_result
//----------------------------------------------------------------------------------------
template <typename RESULT_TYPE> class MAXON_WARN_UNUSED_CLASS Result : public ResultSuper<RESULT_TYPE, void>::type
{
public:
	static_assert(!STD_IS_REPLACEMENT(rvalue_reference, RESULT_TYPE), "Can't instantiate Result template with an r-value reference type.");
	using Super = typename ResultSuper<RESULT_TYPE, void>::type;
	static const Bool T_IS_ERROR = IsErrorClass<RESULT_TYPE>::value; // if RESULT_TYPE itself is an error class, we have to disable some constructors to avoid the ambiguity between an error as a valid result or as an error indication

	//----------------------------------------------------------------------------------------
	/// The type to use for copy construction from a RESULT_TYPE.
	//----------------------------------------------------------------------------------------
	using typename Super::CopyType;

	//----------------------------------------------------------------------------------------
	/// The type to use for move construction from a RESULT_TYPE.
	//----------------------------------------------------------------------------------------
	using typename Super::MoveType;

	using typename Super::DeleteType;

#if defined(MAXON_COMPILER_INTEL) // Intel bug (MAXON_IS_COW_KIND doesn't work)
	//----------------------------------------------------------------------------------------
	/// Constructs a Result object with the given error. The result value will be initialized
	/// as a default value.
	/// @param[in] error							Error object to use for the Result.
	//----------------------------------------------------------------------------------------
	MAXON_IMPLICIT Result(const Error& error) : Super() { this->_error._error = PrivateSystemSetCurrentError(error); }

	//----------------------------------------------------------------------------------------
	/// Constructs a Result object with the given error. The result value will be initialized
	/// as a default value.
	/// @param[in] error							Error object to use for the Result.
	//----------------------------------------------------------------------------------------
	MAXON_IMPLICIT Result(Error&& error) : Super() { this->_error._error = PrivateSystemSetCurrentError(std::move(error)); }
	#define PRIVATE_MAXON_ENABLE_IF_ERROR(TYPE) typename std::enable_if<std::remove_reference<E>::type::DirectlyReferencedType::HasBaseDetector::template Check<ErrorInterface>::value, TYPE>::type
#else
	#define PRIVATE_MAXON_ENABLE_IF_ERROR(TYPE) typename std::enable_if<std::remove_reference<E>::type::DirectlyReferencedType::HasBaseDetector::template Check<ErrorInterface>::value && MAXON_IS_COW_KIND(std::remove_reference<E>::type::Handler::KIND), TYPE>::type
#endif

#if defined(MAXON_COMPILER_GCC)
	// MSVC seems to only generate copy constructor
	// Intel seems to always generate implicit copy constructor (also if this is not explicitly needed, this causes an error if RESULT_TYPE has no copy constructor)

	// the warn_unused_result attribute only works with a copy constructor on gcc
	// See https://gcc.gnu.org/bugzilla/show_bug.cgi?id=38172
	// TODO: (Ole) This leads to bad performance as it prohibits the use of registers for Result<void>

	Result(Result&& src) : Super(std::move(src)) { }
	MAXON_OPERATOR_MOVE_ASSIGNMENT(Result);

	Result(const Result& src) : Super(src) { }
	MAXON_OPERATOR_COPY_ASSIGNMENT(Result);
#endif

#define PRIVATE_MAXON_ENABLE_IF_ERROR_DUMMY PRIVATE_MAXON_ENABLE_IF_ERROR(DummyParamType*) = (DummyParamType*) nullptr

	//----------------------------------------------------------------------------------------
	/// Constructs a Result object with a default value and no error.
	//----------------------------------------------------------------------------------------
	Result() : Super() { }

	//----------------------------------------------------------------------------------------
	/// Constructs a Result object with the given error. The result value will be initialized
	/// as a default value. This constructor is needed for <tt>return err;</tt> statements
	/// within an #iferr block.
	/// The extra constructors are required as workaround for MSVC.
	/// @param[in] error							Error object to use for the Result.
	//----------------------------------------------------------------------------------------
	MAXON_IMPLICIT Result(ErrorPtr& error) : Super() { this->_error = error; }
	MAXON_IMPLICIT Result(ErrorPtr&& error) : Super() { this->_error = error; }
	MAXON_IMPLICIT Result(const ErrorPtr& error) : Super() { this->_error = error; }

	// needed in combination with CreateError
	MAXON_IMPLICIT Result(const ThreadReferencedError& error) : Super() { this->_error = error; }

	//----------------------------------------------------------------------------------------
	/// Constructs a <tt>Result<void></tt> object, indicating an OutOfMemoryError if @p value
	/// is @c false. This constructor is only available for <tt>Result<void></tt> and not
	/// for a general <tt>Result<T></tt>.
	/// @param[in] value							If false, set the error object to an OutOfMemoryError.
	//----------------------------------------------------------------------------------------
	MAXON_IMPLICIT Result(typename std::conditional<STD_IS_REPLACEMENT(void, RESULT_TYPE), ResultMem, const volatile DummyParamType&>::type value) : Super()
	{
		if (value == FAILED)
			this->_error = CreateErrorPtr(MAXON_SOURCE_LOCATION, ERROR_TYPE::OUT_OF_MEMORY);
	}

	//----------------------------------------------------------------------------------------
	/// Constructs a Result object without error from a ResultOk object.
	/// @param[in] value							The ResultOk from which the value is taken.
	//----------------------------------------------------------------------------------------
	template <typename T2, typename = typename Super::template ConstructibleFrom<typename std::add_const<T2>::type>::type> MAXON_IMPLICIT Result(const ResultOk<T2>& value) : Super(value.GetValue())
	{
	}

	//----------------------------------------------------------------------------------------
	/// Constructs a Result object without error from a ResultOk object.
	/// @param[in] value							The ResultOk from which the value is taken.
	//----------------------------------------------------------------------------------------
	template <typename T2, typename = typename Super::template ConstructibleFrom<T2>::type> MAXON_IMPLICIT Result(ResultOk<T2>&& value) : Super(std::forward<T2>(value.GetValue()))
	{
	}

	//----------------------------------------------------------------------------------------
	/// Constructs a Result object without error from a ResultOk object.
	/// @param[in] value							The ResultOk from which the value is taken.
	//----------------------------------------------------------------------------------------
	MAXON_IMPLICIT Result(typename std::conditional<STD_IS_REPLACEMENT(void, RESULT_TYPE), ResultOk<RESULT_TYPE>, DummyParamType&&>::type value) : Super()
	{
	}

	//----------------------------------------------------------------------------------------
	/// Constructs a <tt>Result<void></tt> object, indicating an OutOfMemoryError if @p value
	/// is @c nullptr. This constructor is only available for <tt>Result<void></tt> and not
	/// for a general <tt>Result<T></tt>.
	/// @param[in] value							If nullptr, set the error object to an OutOfMemoryError.
	//----------------------------------------------------------------------------------------
	template <typename T2> MAXON_IMPLICIT Result(const ResultMemT<T2>& value, typename std::enable_if<STD_IS_REPLACEMENT(void, typename SFINAEHelper<RESULT_TYPE, T2>::type), DummyParamType*>::type = (DummyParamType*) nullptr) : Super()
	{
		if (MAXON_UNLIKELY(value == FAILED))
			this->_error = CreateErrorPtr(MAXON_SOURCE_LOCATION, ERROR_TYPE::OUT_OF_MEMORY);
	}

	//----------------------------------------------------------------------------------------
	/// Constructs a <tt>Result</tt> object with a pointer value from a ResultPtr.
	/// @param[in] value							The ResultPtr value to use.
	//----------------------------------------------------------------------------------------
	template <typename T2, typename = typename Super::template ConstructibleFrom<typename std::add_const<T2>::type>::type> MAXON_IMPLICIT Result(const ResultMemT<T2>& value) : Super(value.GetValue())
	{
		if (MAXON_UNLIKELY(value == FAILED))
			this->_error = CreateErrorPtr(MAXON_SOURCE_LOCATION, ERROR_TYPE::OUT_OF_MEMORY);
	}

	//----------------------------------------------------------------------------------------
	/// Constructs a <tt>Result</tt> object with a pointer value from a ResultPtr.
	/// @param[in] value							The ResultPtr value to use.
	//----------------------------------------------------------------------------------------
	template <typename T2, typename = typename Super::template ConstructibleFrom<T2>::type> MAXON_IMPLICIT Result(ResultMemT<T2>&& value)
	{
		if (MAXON_UNLIKELY(value == FAILED))
			this->_error = CreateErrorPtr(MAXON_SOURCE_LOCATION, ERROR_TYPE::OUT_OF_MEMORY);
		else
			this->_value = std::forward<T2>(value.GetValue());
	}

	//----------------------------------------------------------------------------------------
	/// Constructs a <tt>Result<void></tt> object, indicating an OutOfMemoryError if @p value
	/// is @c nullptr. This constructor is only available for <tt>Result<void></tt> and not
	/// for a general <tt>Result<T></tt>.
	/// @param[in] value							If nullptr, set the error object to an OutOfMemoryError.
	//----------------------------------------------------------------------------------------
	template <typename T2> MAXON_IMPLICIT Result(const ResultRef<T2>& value, typename std::enable_if<STD_IS_REPLACEMENT(void, typename SFINAEHelper<RESULT_TYPE, T2>::type), DummyParamType*>::type = (DummyParamType*) nullptr) : Super()
	{
		if (!value.GetPointer())
			this->_error = CreateErrorPtr(MAXON_SOURCE_LOCATION, ERROR_TYPE::OUT_OF_MEMORY);
	}

	//----------------------------------------------------------------------------------------
	/// Constructs a <tt>Result</tt> object with a C++ reference value from a ResultRef.
	/// @param[in] value							The ResultRef value to use.
	//----------------------------------------------------------------------------------------
	template <typename T2, typename = typename Super::template ConstructibleFrom<T2&>::type> MAXON_IMPLICIT Result(const ResultRef<T2>& value) : Super(value.GetValue())
	{
		if (!value.GetPointer())
			this->_error = CreateErrorPtr(MAXON_SOURCE_LOCATION, ERROR_TYPE::OUT_OF_MEMORY);
	}

	//----------------------------------------------------------------------------------------
	/// Constructs a <tt>Result<void></tt> object without error. This indicates a successful operation,
	/// it is typically used implicitly by a <tt>return OK;</tt> statement.
	/// This constructor is only available for <tt>Result<void></tt> and not
	/// for a general <tt>Result<T></tt>.
	//----------------------------------------------------------------------------------------
	MAXON_IMPLICIT Result(typename std::conditional<STD_IS_REPLACEMENT(void, RESULT_TYPE), ERROR_OK, volatile DummyParamType&>::type) : Super() { }

	//----------------------------------------------------------------------------------------
	/// Constructs a Result object with the given result value and without error.
	/// @param[in] value							The result value.
	//----------------------------------------------------------------------------------------
	MAXON_IMPLICIT Result(typename std::conditional<T_IS_ERROR, const DummyParamType&, CopyType>::type value) : Super(value) { }

	//----------------------------------------------------------------------------------------
	/// Constructs a Result object with the given result value and without error.
	/// @param[in] value							The result value.
	//----------------------------------------------------------------------------------------
	MAXON_IMPLICIT Result(typename std::conditional<T_IS_ERROR, DummyParamType&, MoveType>::type value) : Super(std::move(value)) { }

	MAXON_IMPLICIT Result(typename std::conditional<T_IS_ERROR, const DummyParamType&&, DeleteType>::type value) = delete;

	//----------------------------------------------------------------------------------------
	/// Constructs a Result object with the given result value and without error.
	/// This constructor is only available for reference classes.
	/// @param[in] value							The result value.
	//----------------------------------------------------------------------------------------
	template <typename T2, typename = typename std::enable_if<!maxon::HasBaseDetector<typename std::decay<T2>::type::ReferencedType, ErrorInterface>::value, RESULT_TYPE>::type::ReferencedType, typename = typename Super::template ConstructibleFrom<T2>::type>
	MAXON_IMPLICIT Result(T2&& value) : Super(std::forward<T2>(value)) { }

	//----------------------------------------------------------------------------------------
	/// Constructs a <tt>Result<void></tt> object from an existing <tt>Result<T2></tt> object @p src by
	/// using the error of @p src, if any.
	/// This constructor is only available for <tt>Result<void></tt> and not
	/// for a general <tt>Result<T></tt>.
	//----------------------------------------------------------------------------------------
	template <typename T2> Result(const Result<T2>& src, typename std::enable_if<STD_IS_REPLACEMENT(void, typename SFINAEHelper<RESULT_TYPE, T2>::type), DummyParamType*>::type = (DummyParamType*) nullptr) : Super() { this->_error = src.GetErrorStorage(); }

	//----------------------------------------------------------------------------------------
	/// Constructs a <tt>Result</tt> object from an existing <tt>Result</tt> object @p src by
	/// using the value and/or error of @p src.
	//----------------------------------------------------------------------------------------
	template <typename T2, typename = typename Super::template ConstructibleFrom<typename std::add_const<T2>::type>::type> MAXON_IMPLICIT Result(const Result<T2>& src) : Super(src.UncheckedGetValue()) { this->_error = src.GetErrorStorage(); }

	//----------------------------------------------------------------------------------------
	/// Constructs a <tt>Result</tt> object from an existing <tt>Result</tt> object @p src by
	/// using the value and/or error of @p src.
	//----------------------------------------------------------------------------------------
	template <typename T2, typename = typename Super::template ConstructibleFrom<T2>::type> MAXON_IMPLICIT Result(Result<T2>&& src) : Super(std::forward<T2>(src.UncheckedGetValue())) { this->_error = src.GetErrorStorage(); }

	//----------------------------------------------------------------------------------------
	/// Constructs a Result object with the given error. The result value will be initialized
	/// as a default value.
	/// @param[in] error							Error object to use for the Result.
	//----------------------------------------------------------------------------------------
	template <typename E> MAXON_IMPLICIT Result(E&& error, typename std::enable_if<!T_IS_ERROR, PRIVATE_MAXON_ENABLE_IF_ERROR(DummyParamType*)>::type = (DummyParamType*) nullptr) : Super() { InitError(reinterpret_cast<typename Substitute<E&&, Error>::type>(error)); }

	//----------------------------------------------------------------------------------------
	/// Constructs a Result object with both a value and an error taken from a Result.
	/// @param[in] value							Result value.
	/// @param[in] result							Result object (from which the error is copied).
	//----------------------------------------------------------------------------------------
	template <typename T2> Result(CopyType value, const Result<T2>& result) : Super(value) { this->_error = result.GetErrorStorage(); }

	//----------------------------------------------------------------------------------------
	/// Constructs a Result object with both a value and an error taken from a Result.
	/// @param[in] value							Result value.
	/// @param[in] result							Result object (from which the error is copied).
	//----------------------------------------------------------------------------------------
	template <typename T2> Result(MoveType value, const Result<T2>& result) : Super(std::move(value)) { this->_error = result.GetErrorStorage(); }

	template <typename T2> Result(DeleteType value, const Result<T2>& result) = delete;

	//----------------------------------------------------------------------------------------
	/// Constructs a Result object with both a result value and an error.
	/// @param[in] value							Result value.
	/// @param[in] error							Error object.
	//----------------------------------------------------------------------------------------
	template <typename E> Result(CopyType value, E&& error, PRIVATE_MAXON_ENABLE_IF_ERROR_DUMMY) : Super(value) { InitError(reinterpret_cast<typename Substitute<E&&, Error>::type>(error)); }

	//----------------------------------------------------------------------------------------
	/// Constructs a Result object with both a result value and an error.
	/// @param[in] value							Result value.
	/// @param[in] error							Error object.
	//----------------------------------------------------------------------------------------
	template <typename E> Result(MoveType value, E&& error, PRIVATE_MAXON_ENABLE_IF_ERROR_DUMMY) : Super(std::move(value)) { InitError(reinterpret_cast<typename Substitute<E&&, Error>::type>(error)); }

	template <typename E> Result(DeleteType value, E&& error, PRIVATE_MAXON_ENABLE_IF_ERROR_DUMMY) = delete;

#if defined(MAXON_COMPILER_MSVC) || defined(MAXON_COMPILER_INTEL)
	// prevent Bool -> Result<void> conversion for MSVC
	explicit Result(typename std::conditional<STD_IS_REPLACEMENT(same, typename std::decay<RESULT_TYPE>::type, Bool) || STD_IS_REPLACEMENT(void, RESULT_TYPE), volatile DummyParamType&&, Bool>::type) = delete;
	MAXON_IMPLICIT Result(typename std::conditional<STD_IS_REPLACEMENT(void, RESULT_TYPE), Bool, const volatile DummyParamType&&>::type) = delete;
#else
	explicit Result(typename std::conditional<STD_IS_REPLACEMENT(same, typename std::decay<RESULT_TYPE>::type, Bool), volatile DummyParamType&&, Bool>::type) = delete;
#endif

	//----------------------------------------------------------------------------------------
	/// Returns the error object. If there is no error, this will be a null reference.
	/// @return												Error object, may be a null reference.
	//----------------------------------------------------------------------------------------
	typename SFINAEHelper<Error, RESULT_TYPE>::type GetError() const
	{
		// Note: This doesn't return "const Error&" because that would be a reference to the internal thread-local storage
		// which can change its contents when a new error is set.
		return this->_error._error ? *this->_error._error : GetPtrSizedZeroRef<Error>();
	}

	//----------------------------------------------------------------------------------------
	/// Returns the error object pointer. If there is no error, this will be nullptr.
	/// @return												Error object pointer, may be nullptr.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE const ErrorInterface* GetErrorPointer() const
	{
		return this->_error._error ? this->_error._error->GetPointer() : nullptr;
	}

	//----------------------------------------------------------------------------------------
	/// Returns the error object if it is of type E. If there is no error or the error is not an instance of E, a null reference is returned.
	/// This function can be used for handling of specific errors as in the following example:
	/// @code
	/// Result<void> result = MyFunc();
	/// if (IllegalArgumentError e = result.GetError<IllegalArgumentError>())
	/// {
	///   // handle IllegalArgumentError
	/// }
	/// else
	/// {
	///   // all other errors (if any) are returned to the caller
	///   result iferr_return;
	/// }
	/// @endcode
	/// If you don't need the E reference, you can use the HasError() function.
	/// @tparam E											The error reference class to check for.
	/// @return												Error object of type E, may be a null reference.
	//----------------------------------------------------------------------------------------
	template <typename E> PRIVATE_MAXON_ENABLE_IF_ERROR(E) GetError() const
	{
		return (this->_error._error && this->_error._error->GetPointer()->template IsInstanceOf<typename E::DirectlyReferencedType>()) ? *reinterpret_cast<const E*>(this->_error._error) : GetPtrSizedZeroRef<E>();
	}

	//----------------------------------------------------------------------------------------
	/// Checks if the error object is of type E.
	/// @tparam E											The error reference class to check for.
	/// @return												True if this Result holds an Error object of type E, false otherwise.
	//----------------------------------------------------------------------------------------
	template <typename E> PRIVATE_MAXON_ENABLE_IF_ERROR(Bool) HasError() const
	{
		return this->_error._error && this->_error._error->GetPointer()->template IsInstanceOf<typename E::DirectlyReferencedType>();
	}

	//----------------------------------------------------------------------------------------
	/// Checks if this @CLASS indicates a successful operation. Use this operator as in <tt>result == OK</tt>.
	/// To check for a failed operation, you have to use <tt>result == FAILED</tt> (<tt>!=</tt> is not supported).
	/// @param[in] ok									Use the global constant OK.
	/// @return												True if this @CLASS has no error.
	//----------------------------------------------------------------------------------------
	Bool operator ==(ERROR_OK ok) const { return MAXON_LIKELY(this->_error._error == nullptr); }

	//----------------------------------------------------------------------------------------
	/// Checks if this @CLASS indicates a %failed operation. Use this operator as in <tt>result == FAILED</tt>.
	/// To check for a successful operation, you have to use <tt>result == OK</tt> (<tt>!=</tt> is not supported).
	/// @param[in] failed							Use the global constant FAILED.
	/// @return												True if this @CLASS has an error.
	//----------------------------------------------------------------------------------------
	Bool operator ==(ERROR_FAILED failed) const { return MAXON_UNLIKELY(this->_error._error != nullptr); }

	// This avoids cases like "Func() = value;" where the writer expected Func() to return a RESULT_TYPE&, but it returns a Result<RESULT_TYPE&>.
	void operator =(typename std::conditional<STD_IS_REPLACEMENT(reference, RESULT_TYPE), RESULT_TYPE, const DummyParamType&>::type) = delete;

private:
	void InitError(const Error& error)
	{
		if (reinterpret_cast<void* const&>(error))
			this->_error._error = PrivateSystemSetCurrentError(error);
	}

	void InitError(Error&& error)
	{
		if (reinterpret_cast<void* const&>(error))
			this->_error._error = PrivateSystemSetCurrentError(std::move(error));
	}
};

template <typename T> struct RemoveResult
{
	using type = T;
};

template <typename T> struct RemoveResult<Result<T>>
{
	using type = T;
};

template <typename T> struct RemoveResult<ResultOk<T>>
{
	using type = T;
};

template <typename TO, typename FROM, Bool SAFE> struct GenericCastMemberTrait<Result<TO>, Result<FROM>, SAFE> : public GenericCastMemberTrait<TO, FROM, SAFE>
{
};

template <typename TO, typename FROM, Bool SAFE> struct GenericCastTrait<Result<TO>, FROM, SAFE> : public GenericCastMemberTrait<TO, FROM, SAFE>
{
	using CastType = TO&&;
	using ReturnType = Result<TO>;
};

template <typename TO, typename FROM, Bool SAFE> struct GenericCastTrait<Result<TO>, Result<FROM>, SAFE> : public GenericCastMemberTrait<Result<TO>, Result<FROM>, SAFE>
{
	using CastType = Result<TO>&&;
	using ReturnType = Result<TO>;
};

#undef PRIVATE_MAXON_ENABLE_IF_ERROR_DUMMY
#undef PRIVATE_MAXON_ENABLE_IF_ERROR

#ifdef MAXON_COMPILER_GCC

struct PrivateMuteUnusedHelper
{
	template <typename T> MAXON_IMPLICIT PrivateMuteUnusedHelper(T&&) { }
};

#endif


//----------------------------------------------------------------------------------------
// The following operators are required by iferr and iferr_scope.
//----------------------------------------------------------------------------------------

// support ResultOk for iferr
template <typename T> MAXON_ATTRIBUTE_FORCE_INLINE auto operator %(const ResultOk<T>& rv, ThreadReferencedError& err) -> decltype(rv.GetValue())
{
	err = nullptr;
	return rv.GetValue();
}

// support ResultOk for iferr
template <typename T> MAXON_ATTRIBUTE_FORCE_INLINE T operator %(ResultOk<T>&& rv, ThreadReferencedError& err)
{
	err = nullptr;
	return std::move(rv).GetValue();
}

// support ResultOk for iferr
template <typename T> MAXON_ATTRIBUTE_FORCE_INLINE T& operator %(ResultOk<T&>&& rv, ThreadReferencedError& err)
{
	err = nullptr;
	return rv.GetValue();
}

// support ResultOk for iferr
MAXON_ATTRIBUTE_FORCE_INLINE void operator %(ResultOk<void>&& rv, ThreadReferencedError& err)
{
	err = nullptr;
}

// support ResultOk for iferr
template <typename T> MAXON_ATTRIBUTE_FORCE_INLINE auto operator %(const ResultOk<T>& rv, maxon::details::ResultOkError& err) -> decltype(rv.GetValue())
{
	return rv.GetValue();
}

// support ResultOk for iferr
template <typename T> MAXON_ATTRIBUTE_FORCE_INLINE T operator %(ResultOk<T>&& rv, maxon::details::ResultOkError& err)
{
	return std::move(rv).GetValue();
}

// support ResultOk for iferr
template <typename T> MAXON_ATTRIBUTE_FORCE_INLINE T& operator %(ResultOk<T&>&& rv, maxon::details::ResultOkError& err)
{
	return rv.GetValue();
}

// support ResultOk for iferr
MAXON_ATTRIBUTE_FORCE_INLINE void operator %(ResultOk<void>&& rv, maxon::details::ResultOkError& err)
{
}

// support Result for iferr
template <typename T> MAXON_ATTRIBUTE_FORCE_INLINE auto operator %(const Result<T>& rv, ThreadReferencedError& err) -> decltype(rv.GetValue())
{
	return rv.GetValueAndError(err);
}

// support Result for iferr
template <typename T> MAXON_ATTRIBUTE_FORCE_INLINE T operator %(Result<T>&& rv, ThreadReferencedError& err)
{
	return std::move(rv).GetValueAndError(err);
}

// support Result for iferr
template <typename T> MAXON_ATTRIBUTE_FORCE_INLINE T& operator %(const Result<T&>& rv, ThreadReferencedError& err)
{
	return rv.GetValueAndError(err);
}

// support Result for iferr
template <typename T> MAXON_ATTRIBUTE_FORCE_INLINE T& operator %(Result<T&>&& rv, ThreadReferencedError& err)
{
	return rv.GetValueAndError(err);
}

// support Result<void> for iferr
MAXON_ATTRIBUTE_FORCE_INLINE void operator %(const Result<void>& rv, ThreadReferencedError& err)
{
	return rv.GetValueAndError(err);
}

// support Result<void> for iferr
MAXON_ATTRIBUTE_FORCE_INLINE void operator %(Result<void>&& rv, ThreadReferencedError& err)
{
	return rv.GetValueAndError(err);
}

// support ResultMemT for iferr
template <typename T> MAXON_ATTRIBUTE_FORCE_INLINE T&& operator %(ResultMemT<T>&& ptr, ThreadReferencedError& err)
{
	if (MAXON_LIKELY(ptr == OK))
	{
		err = nullptr;
	}
	else
	{
		// Use CreateErrorPtr() because the compiler can omit the call if the err isn't used.
		err = CreateErrorPtr(MAXON_SOURCE_LOCATION, ERROR_TYPE::OUT_OF_MEMORY);
	}
	return std::move(ptr.UncheckedGetValue());
}

// support ResultMemT for iferr
template <typename T> MAXON_ATTRIBUTE_FORCE_INLINE const T& operator %(const ResultMemT<T>& ptr, ThreadReferencedError& err)
{
	if (MAXON_LIKELY(ptr == OK))
	{
		err = nullptr;
	}
	else
	{
		// Use CreateErrorPtr() because the compiler can omit the call if the err isn't used.
		err = CreateErrorPtr(MAXON_SOURCE_LOCATION, ERROR_TYPE::OUT_OF_MEMORY);
	}
	return ptr.UncheckedGetValue();
}

// support ResultRef for iferr
template <typename T> MAXON_ATTRIBUTE_FORCE_INLINE T& operator %(ResultRef<T> ptr, ThreadReferencedError& err)
{
	if (MAXON_LIKELY(ptr.GetPointer() != nullptr))
	{
		err = nullptr;
		return ptr.GetValue();
	}
	else
	{
		// Use CreateErrorPtr() because the compiler can omit the call if the err isn't used.
		err = CreateErrorPtr(MAXON_SOURCE_LOCATION, ERROR_TYPE::OUT_OF_MEMORY);
		return const_cast<T&>(STD_IS_REPLACEMENT(const, T) ? reinterpret_cast<const T&>(DefaultValue<typename std::conditional<STD_IS_REPLACEMENT(const, T), T&, const Int&>::type>()) : GetZeroRef<T>());
	}
}


#ifndef MAXON_COMPILER_GCC
	// For most compilers (void) xyz is enough to imply that a variable is not unused. No need to
	// temporarily disable the unused variable warning.
	#define PRIVATE_MAXON_iferr_scope(T) \
		MAXON_WARNING_PUSH \
		MAXON_WARNING_DISABLE_VARIABLE_SHADOWING \
		MAXON_WARNING_DISABLE_UNUSED_LOCAL_TYPEDEF \
		using ErrorScopeHandler = T; \
		ErrorScopeHandler tmperr_ies; \
		(void) tmperr_ies \
		MAXON_WARNING_POP

	#define PRIVATE_MAXON_iferr_scope_handler() \
		MAXON_WARNING_PUSH \
		MAXON_WARNING_DISABLE_VARIABLE_SHADOWING \
		MAXON_WARNING_DISABLE_UNUSED_VARIABLES \
		maxon::ThreadReferencedError tmperr_ies; \
		auto ErrorScopeHandler = [&](maxon::ErrorPtr& err) mutable \
		MAXON_WARNING_POP
#else
	// GCC does not accept extended asm on the top level. Therefore, instead of using asm volatile
	// in the iferr_scope macro this method has to be called and simulates usage of tmperr_ies.
	template <typename T> inline void PrivateGccUseError(T& err)
	{
		asm volatile ("" : "=m" (err) : "m" (err) : "memory");
	}

	// For GCC the unused variable warning doesn't work temporarily and using (void) xyz doesn't work either.
	// Therefore use an inline assembly block which does nothing but referencing the variable.
#ifdef __CDT_PARSER__ // Eclipse does not understand the GCC __attribute__ and reports an error for every iferr_scope
	#define PRIVATE_MAXON_iferr_scope(T) \
		MAXON_WARNING_PUSH \
		MAXON_WARNING_DISABLE_VARIABLE_SHADOWING \
		MAXON_WARNING_DISABLE_UNUSED_LOCAL_TYPEDEF \
		using ErrorScopeHandler = T; \
		ErrorScopeHandler tmperr_ies; \
		PrivateGccUseError(tmperr_ies); \
		MAXON_WARNING_POP
#else
	#define PRIVATE_MAXON_iferr_scope(T) \
		MAXON_WARNING_PUSH \
		MAXON_WARNING_DISABLE_VARIABLE_SHADOWING \
		MAXON_WARNING_DISABLE_UNUSED_LOCAL_TYPEDEF \
		using ErrorScopeHandler __attribute__((unused)) = T; \
		ErrorScopeHandler tmperr_ies; \
		PrivateGccUseError(tmperr_ies); \
		MAXON_WARNING_POP
#endif

	#define PRIVATE_MAXON_iferr_scope_handler() \
		MAXON_WARNING_PUSH \
		MAXON_WARNING_DISABLE_VARIABLE_SHADOWING \
		maxon::ThreadReferencedError tmperr_ies; \
		PrivateGccUseError(tmperr_ies); \
		MAXON_WARNING_POP \
		auto ErrorScopeHandler __attribute__((unused)) = [&](maxon::ErrorPtr& err) mutable
#endif

// No variadic args version. Called by concatenation of "PRIVATE_MAXON_iferr_diag_handler" and vaArgsPopulated=0 (no variadic arguments).
// Don't use error(@) in the output since it breaks unit tests. Add NoLocation as well since the pattern is detected by unit test processor.
// If the error is unhandled, in will end up on the console with location anyway. iferr_diag_handler is just for adding additional debugging traces.
#define PRIVATE_MAXON_iferr_diag_handler0(errResult, formatString, ...) iferr_scope_handler { DiagnosticOutput((formatString "\nresult(@{NoLocation})"), err); return errResult; }
// Some variadic args version. Called by concatenation of "PRIVATE_MAXON_iferr_diag_handler" and vaArgsPopulated=1.
#define PRIVATE_MAXON_iferr_diag_handler1(errResult, formatString, ...) iferr_scope_handler { DiagnosticOutput((formatString "\nresult(@{NoLocation})"), __VA_ARGS__, err); return errResult; }

// A b c trick for expanding MAXON_VA_ARGS_POPULATED
#define PRIVATE_MAXON_iferr_diag_handlerc(vaArgsPopulated, errResult, formatString, ...) PRIVATE_MAXON_iferr_diag_handler##vaArgsPopulated(errResult, formatString, ##__VA_ARGS__)
#define PRIVATE_MAXON_iferr_diag_handlerb(vaArgsPopulated, errResult, formatString, ...) PRIVATE_MAXON_iferr_diag_handlerc(vaArgsPopulated, errResult, formatString, ##__VA_ARGS__)
#define PRIVATE_MAXON_iferr_diag_handlera(vaArgsPopulated, errResult, formatString, ...) PRIVATE_MAXON_iferr_diag_handlerb(vaArgsPopulated, errResult, formatString, ##__VA_ARGS__)

#define PRIVATE_MAXON_iferr_return()		% tmperr_ies; if (MAXON_UNLIKELY(tmperr_ies.GetReferencedError() != nullptr)) return ErrorScopeHandler(tmperr_ies); else do {} while(false)

// GetValue() will cause a DebugAssert if there was an error.
#define PRIVATE_MAXON_iferr_cannot_fail(str)		.GetValue()

// iferr_ignore uses UncheckedGetValue(), but if there's a second parameter (debug) then GetValue() will be called and cause a DebugAssert if there is an error.
#define PRIVATE_MAXON_iferr_ignore_method(str, optionalArg, method, ...) method
#define PRIVATE_MAXON_iferr_ignore(...)		PRIVATE_MAXON_iferr_ignore_method(__VA_ARGS__, .GetValue(), .UncheckedGetValue())

//----------------------------------------------------------------------------------------
/// Instead of using @c iferr you can define an @c iferr_scope and within this scope call
/// methods which might return an error (and decorate them with the @c iferr_return
/// attribute). If a method returns with an error @c iferr_return will forward it.
/// @code
/// iferr_scope;
///
/// FuncA() iferr_return;
/// FuncB() iferr_return;
/// @endcode
//----------------------------------------------------------------------------------------
#define iferr_scope									PRIVATE_MAXON_iferr_scope(maxon::ThreadReferencedError)

//----------------------------------------------------------------------------------------
/// To perform a specific action in case of an error (additional logging, or just to set a
/// breakpoint for debugging) you can replace @c iferr_scope by an @c iferr_scope_handler:
/// @code
/// iferr_scope_handler
/// {
///   DebugStop("special message");
///   return err;
/// };
///
/// FuncA() iferr_return;
/// FuncB() iferr_return;
/// @endcode
///
/// iferr_scope_handler implicitely defines the error variable 'err'.
//----------------------------------------------------------------------------------------
#define iferr_scope_handler					PRIVATE_MAXON_iferr_scope_handler()

//----------------------------------------------------------------------------------------
/// Condensed version of iferr_scope_handler. Allows to add some local context to error coming
/// from inner calls (lower level code). The nested error and local context are printed to the console based on g_diagnostic configuration.
/// Can be used on legacy code side of Maxon API code side since the handler's return value is defined by the first argument #errResult.
/// See iferr_scope for details. One per scope only.
/// @code
/// auto SomeFuncA()
/// {
/// 	iferr_diag_handler(localVariable, "Error occurred: CSV data invalid file(@)"_s, filePath);
///		...
/// }
///
/// Int SomeFuncB()
/// {
/// 	iferr_diag_handler(Int{-1}, "Invalid node argument. Value=@ Attrib=@"_s, attribValue, attribId);
///		...
/// }
///
/// Result<void> SomeFuncC()
/// {
/// 	iferr_diag_handler(OK, "Function Name: context(@)"_s, ctx);
///		...
/// }
///
/// Result<Array<Int>> SomeFuncD()
/// {
/// 	iferr_diag_handler(err, "My simple context"_s);
///		...
/// }
///
/// void SomeFuncE()
/// {
/// 	iferr_diag_handler(, "Function E with no return value."_s);
///		...
/// }
/// @endcode
/// @param[in] errResult					Value to return in case of error.
/// @param[in] formatString				Format for the DiagnosticOutput embedded call. Variadic arguments should match the number of '@' in #formatString.
///																err.ToString() will be added automatically at the end of the string.
/// @return												#errResult. Can be "err" or maxon::OK if function return type is Result<T>.
///																Or any default value or variable which has a compatible type.
//----------------------------------------------------------------------------------------
#define iferr_diag_handler(errResult, formatString, ...) PRIVATE_MAXON_iferr_diag_handlera(MAXON_VA_ARGS_POPULATED(__VA_ARGS__), errResult, formatString, ##__VA_ARGS__)

//----------------------------------------------------------------------------------------
/// If an error cannot occur (because you've ensured this by preallocating resources or the
/// algorithm was designed in such a way, etc.) you might use @c iferr_cannot_fail with a
/// comment which explans why it can't fail.
/// In debug this will check for errors and invoke DebugStop() to notify you that your code
/// is broken, but in release there are no error checks.
/// @code
/// iferr_scope;
/// BaseArray<Int> array;
///
///	array.EnsureCapacity(42) iferr_return;
/// for (Int i = 0; i < GetCapacityCount(); i++)
///	  array.Append(i) iferr_cannot_fail("Capacity was ensured.");
/// @endcode
//----------------------------------------------------------------------------------------
#define iferr_cannot_fail(str)			PRIVATE_MAXON_iferr_cannot_fail(str)

//----------------------------------------------------------------------------------------
/// If for perfomance reasons a piece of code has been very carefully designed in a way that
/// error checking is performed at the very end and that no checks are necessary inbetween
/// you may qualify calls with @c iferr_ignore and a comment which describes why the error
/// can be ignored.
/// @note This should only be used for performance critical code which has been profiled
/// properly and has been reviewed thoroughly.
/// @note You might supply an optional second parameter (debug) to cause a DebugStop on error. 
/// @code
/// BaseArray<Int> array;
///	const Int CNT = 42;
///
/// for (Int i = 0; i < CNT; i++)
///	  array.Append(i) iferr_ignore("Errors are handled after append");
///
///	if (array.GetCount() != CNT)
///	  return OutOfMemoryError(MAXON_SOURCE_LOCATION);
/// @endcode
//----------------------------------------------------------------------------------------
#define iferr_ignore(...)						PRIVATE_MAXON_iferr_ignore(__VA_ARGS__)

//----------------------------------------------------------------------------------------
/// Use iferr_scope_result in finally blocks to deallocate resources based on the error state.
/// @code
///	finally
///	{
///	  if (iferr_scope_result == FAILED)
///     destructSecond = true;
/// };
/// @endcode
//----------------------------------------------------------------------------------------
#define iferr_scope_result					maxon::Result<void>(tmperr_ies)

//----------------------------------------------------------------------------------------
/// The #iferr_return macro is the easiest way to introduce error handling. It quickly allows you leave a function
/// as soon as an error occurs. iferr_return requires you to define #iferr_scope or #iferr_scope_handler once
/// beforehand (preferably at the beginning of your function)
///
/// @code
/// iferr_scope;
/// ...
/// for (Int i = 0; i < 5; i++)
/// {
/// 	array.Append(5) iferr_return;
/// }
/// UniqueRef<MyClass> obj = UniqueRef<MyClass>::Create() iferr_return;
/// MyRef ref = MyRef::Create() iferr_return;
/// @endcode
///
/// iferr_return forwards the error to the calling function. To do this your function must either
/// return Result<T> or use an #iferr_scope_handler.<br>
/// When iferr_return is used within 'for', 'if', 'else' or 'while' those statements must use
/// brackets around their scope, otherwise iferr_return will not be properly executed.
//----------------------------------------------------------------------------------------
#define iferr_return								PRIVATE_MAXON_iferr_return()

//----------------------------------------------------------------------------------------
/// Manually throw an error. Especially useful in combination with iferr_scope_handler to cleanup things in case of errors.
/// Usually you just create error messages and return them in case of a problem like in this example:
/// @code
/// static Result<void> DoSomething()
/// {
///   Char* mem = NewMem(Char, 200) iferr_return;
///
///   while (true)
///   {
///     // do something
///     ...
///     if (FuncA() != 2)
///       return IllegalStateError(MAXON_SOURCE_LOCATION, "Invalid return value"_s);
///     ...
///     if (FuncB() != 40)
///       return IllegalStateError(MAXON_SOURCE_LOCATION, "Invalid return value"_s);
///     ...
///     if (FuncC() != -3)
///       return IllegalStateError(MAXON_SOURCE_LOCATION, "Invalid return value"_s);
///   }
///
///   DeleteMem(mem);
///   return OK;
/// }
/// @endcode
///
/// The big problem is that in case of an error the allocated chars are nevers freed. Instead of deleting the mem at each possible error point in the algo
/// you can throw the error instead of returning them and then catch the error with iferr_scope_handler and handle the cleanup at a single place like in this example:
/// @code
/// static Result<void> DoSomething()
/// {
///   Char* mem = nullptr;
///
///   iferr_scope_handler
///   {
///     DeleteMem(mem); // always guarantee cleanup even in error case
///     return err;
///   };
///
///   mem = NewMem(Char, 200) iferr_return;
///
///   while (true)
///   {
///     // do something
///     ...
///     if (FuncA() != 2)
///       iferr_throw(IllegalStateError(MAXON_SOURCE_LOCATION, "Invalid return value"_s));
///     ...
///     if (FuncB() != 40)
///       iferr_throw(IllegalStateError(MAXON_SOURCE_LOCATION, "Invalid return value"_s));
///     ...
///     if (FuncC() != -3)
///       iferr_throw(IllegalStateError(MAXON_SOURCE_LOCATION, "Invalid return value"_s));
///   }
///
///   DeleteMem(mem);
///   return OK;
/// }
/// @endcode
//----------------------------------------------------------------------------------------
#define iferr_throw(ERR)						do { maxon::Result<void> throw_##__LINE__ = ERR; throw_##__LINE__ iferr_return; } while(false)

//----------------------------------------------------------------------------------------
/// TODO: (Ole) please document.
//----------------------------------------------------------------------------------------
template <typename SUPER> class ResultIteratorFunctions : public SUPER
{
public:
	using SUPER::SUPER;

	class Wrapper
	{
	public:
		explicit Wrapper(ResultIteratorFunctions* it = nullptr) : _it(it) { }

		Bool operator !=(const PRIVATE_MAXON_RBF_SENTINEL(Wrapper)&) const
		{
			return _it && (_it->_error.GetReferencedError() || _it->GetValue().HasEntry());
		}

		void operator ++()
		{
			if (_it->_error.GetReferencedError())
			{
				// DebugStop() indicates missing error handling in foreach loop
				DebugStop();
				_it = nullptr;
			}
			else
			{
				_it->_error = (++_it->GetValue()).GetErrorStorage();
			}
		}

		Result<decltype(*std::declval<typename SUPER::ValueType>())> operator *() const
		{
			return{ *std::move(_it->UncheckedGetValue()), reinterpret_cast<const Result<void>&>(_it->_error) };
		}

	private:
		ResultIteratorFunctions* _it;
	};

	Wrapper begin()
	{
		return Wrapper(this);
	}

	PRIVATE_MAXON_RBF_SENTINEL(Wrapper) end()
	{
		return PRIVATE_MAXON_RBF_SENTINEL(Wrapper)();
	}
};

}

#endif // RESULTBASE_H__
