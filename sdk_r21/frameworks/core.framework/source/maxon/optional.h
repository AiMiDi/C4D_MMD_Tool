#ifndef OPTIONAL_H__
#define OPTIONAL_H__

#include "maxon/errorbase.h"

namespace maxon
{

//----------------------------------------------------------------------------------------
/// Dummy value to indicate that there is no value.
//----------------------------------------------------------------------------------------
enum class NO_VALUE_TYPE
{
	VALUE = 1
} MAXON_ENUM_LIST(NO_VALUE_TYPE);

static const NO_VALUE_TYPE NO_VALUE = NO_VALUE_TYPE::VALUE;

#ifdef MAXON_COMPILER_MSVC
#pragma warning(disable:4582)
#pragma warning(disable:4583)
#endif

namespace details
{

// Scalar type
template <typename T>
class OptScalarStorage
{
public:
	// Default constructor.
	OptScalarStorage() : _hasValue(false) { }

	// NO_VALUE constructor.
	explicit OptScalarStorage(NO_VALUE_TYPE) : _hasValue(false) { }
	
	// Assignment with NO_VALUE.
	OptScalarStorage& operator =(NO_VALUE_TYPE)
	{
		_hasValue = false;
		return *this;
	}

	// Copy constructor.
	OptScalarStorage(const OptScalarStorage&) = default;
	
	// Copy assignment.
	OptScalarStorage& operator =(const OptScalarStorage&) = default;

	// Value constructor.
	template <typename U>
	explicit OptScalarStorage(U value) : _hasValue(true), _valueStorage(value) { }
	
	// Value assignment.
	template <typename U>
	OptScalarStorage& operator =(U value)
	{
		_hasValue = true;
		_valueStorage = value;
		return *this;
	}

	// In-place constructor.
	template <typename U>
	explicit OptScalarStorage(IN_PLACE_TYPE, U value) : _hasValue(true), _valueStorage(value) { }

	template <typename U> void Emplace(U value)
	{
		_hasValue = true;
		_valueStorage = T(value);
	}

	Result<void> CopyFrom(const OptScalarStorage& src)
	{
		_hasValue = true;
		_valueStorage = src._valueStorage;
		return OK;
	}

	T& GetValueRef()
	{
		return _valueStorage;
	}

	const T& GetValueRef() const
	{
		return _valueStorage;
	}

	Bool HasValue() const
	{
		return _hasValue;
	}

private:
	Bool	_hasValue;
	T			_valueStorage;
};

// Ref type
template <typename T>
class OptRefStorage
{
public:
	// Default constructor.
	OptRefStorage() : _refValue(nullptr) { }

	// NO_VALUE constructor.
	explicit OptRefStorage(NO_VALUE_TYPE) : _refValue(nullptr) { }
	
	// Assignment with NO_VALUE.
	OptRefStorage& operator =(NO_VALUE_TYPE)
	{
		_refValue = nullptr;
		return *this;
	}

	// Copy constructor.
	OptRefStorage(const OptRefStorage& src) : _refValue(src._refValue) { }

	// Converting copy constructor.
	template <typename U>
	OptRefStorage(const OptRefStorage<U>& src) : _refValue(src._refValue) { }

	// Copy assignment.
	OptRefStorage& operator =(const OptRefStorage& src)
	{
		_refValue = src._refValue;
		return *this;
	}
	
	// Converting copy assignment.
	template <typename U>
	OptRefStorage& operator =(const OptRefStorage<U>& src)
	{
		_refValue = src._refValue;
		return *this;
	}

	// Move constructor.
	OptRefStorage(OptRefStorage&& src) : _refValue(std::move(src._refValue)) { }

	// Converting move constructor.
	template <typename U>
	OptRefStorage(OptRefStorage<U>&& src) : _refValue(std::move(src._refValue)) { }
	
	// Move assignment.
	OptRefStorage& operator =(OptRefStorage&& src)
	{
		_refValue = std::move(src._refValue);
		return *this;
	}

	// Converting move assignment.
	template <typename U>
	OptRefStorage& operator =(OptRefStorage<U>&& src)
	{
		_refValue = std::move(src._refValue);
		return *this;
	}

	// Value constructor.
	template <typename U>
	explicit OptRefStorage(const U& refValue) : _refValue(refValue) { }
	
	// Value assignment.
	template <typename U>
	OptRefStorage& operator =(const U& refValue)
	{
		_refValue = refValue;
		return *this;
	}

	// In-place constructor.
	template <typename U>
	explicit OptRefStorage(IN_PLACE_TYPE, U refValue) : _refValue(refValue) { }

	T& GetValueRef()
	{
		return _refValue;
	}

	const T& GetValueRef() const
	{
		return _refValue;
	}

	Bool HasValue() const
	{
		return _refValue != nullptr;
	}

private:
	T			_refValue;
};

// Default class type
template <typename T>
class OptDefaultStorage
{
public:
	// Default constructor.
	OptDefaultStorage() : _hasValue(false) { }

	// NO_VALUE constructor.
	explicit OptDefaultStorage(NO_VALUE_TYPE) : _hasValue(false) { }
	
	// NO_VALUE assignment.
	OptDefaultStorage& operator =(NO_VALUE_TYPE)
	{
		if (_hasValue)
			ClearValue();

		return *this;
	}

	// Copy constructor.
	MAXON_DECLARE_CONDITIONAL_COPY_CONSTRUCTOR(OptDefaultStorage, std::is_copy_constructible<T>::value)
	{
		CopyConstruct(src);
	}

	// Converting copy constructor.
	template
	<
		typename U,
		typename = typename std::enable_if<std::is_constructible<T, const U&>::value>::type
	>
	OptDefaultStorage(const OptDefaultStorage<U>& src)
	{
		CopyConstruct(src);
	}
	
	// Copy assignment.
	MAXON_DECLARE_CONDITIONAL_COPY_ASSIGNMENT(OptDefaultStorage, std::is_copy_assignable<T>::value)
	{
		CopyAssign(src);
		return *this;
	}

	// Converting copy assignment.
	template
	<
		typename U,
		typename = typename std::enable_if<std::is_assignable<T, const U&>::value>::type
	>
	OptDefaultStorage& operator =(const OptDefaultStorage<U>& src)
	{
		CopyAssign(src);
		return *this;
	}

	// Move constructor.
	MAXON_DECLARE_CONDITIONAL_MOVE_CONSTRUCTOR(OptDefaultStorage, std::is_move_constructible<T>::value)
	{
		MoveConstruct(std::move(src));
	}

	// Converting move constructor.
	template
	<
		typename U,
		typename = typename std::enable_if<std::is_constructible<T, U&&>::value>::type
	>
	OptDefaultStorage(OptDefaultStorage<U>&& src)
	{
		MoveConstruct(std::move(src));
	}

	// Move assignment.
	MAXON_DECLARE_CONDITIONAL_MOVE_ASSIGNMENT(OptDefaultStorage, std::is_move_assignable<T>::value)
	{
		MoveAssign(std::move(src));
		return *this;
	}
	
	// Converting move assignment.
	template
	<
		typename U,
		typename = typename std::enable_if<std::is_assignable<T, U&&>::value>::type
	>
	OptDefaultStorage& operator =(OptDefaultStorage<U>&& src)
	{
		MoveAssign(std::move(src));
		return *this;
	}

	// Forward-from-value constructor.
	template <typename U>
	explicit OptDefaultStorage(U&& value) : _hasValue(true)
	{
		new (&_valueStorage) T(std::forward<U>(value));
	}
	
	// Forwarding value assignment.
	template <typename U>
	OptDefaultStorage& operator =(U&& value)
	{
		if (_hasValue)
		{
			GetValueRef() = std::forward<U>(value);
		}
		else
		{
			_hasValue = true;
			new (&_valueStorage) T(std::forward<U>(value));
		}

		return *this;
	}

	// Emplace constructor.
	template <typename ... ARGS>
	explicit OptDefaultStorage(IN_PLACE_TYPE, ARGS&& ... args) : _hasValue(true)
	{
		new (&_valueStorage) T(std::forward<ARGS>(args) ...);
	}

	template <typename ... ARGS>
	void Emplace(ARGS&& ... args)
	{
		if (_hasValue)
			Destruct();
		else
			_hasValue = true;

		new (&_valueStorage) T(std::forward<ARGS>(args) ...);
	}

	Result<void> CopyFrom(const OptDefaultStorage& src)
	{
		if (_hasValue && src._hasValue)
		{
			return AssignCopy<T>(GetValueRef(), src.GetValueRef());
		}
		else if (!_hasValue && src._hasValue)
		{
			Result<void> res = NewCopy<T>(GetValueRef(), src.GetValueRef());
			if (res == FAILED)
				return res;

			_hasValue = true;
			return OK;
		}
		else if (_hasValue && !src._hasValue)
		{
			ClearValue();
			return OK;
		}
		else
		{
			// Both have no value, do nothing
			return OK;
		}
	}
	
	~OptDefaultStorage()
	{
		if (_hasValue)
			Destruct();
	}

	T& GetValueRef()
	{
		return _valueStorage;
	}

	const T& GetValueRef() const
	{
		return _valueStorage;
	}

	Bool HasValue() const
	{
		return _hasValue;
	}

private:
	template <typename U>
	void CopyConstruct(const OptDefaultStorage<U>& src)
	{
		if (src.HasValue())
		{
			_hasValue = true;
			new (&_valueStorage) T(src.GetValueRef());
		}
		else
		{
			_hasValue = false;
		}
	}

	template <typename U>
	void CopyAssign(const OptDefaultStorage<U>& src)
	{
		if (_hasValue && src._hasValue)
		{
			if (this != &src)
				GetValueRef() = src.GetValueRef();
		}
		else if (!_hasValue && src._hasValue)
		{
			if (this != &src)
			{
				_hasValue = true;
				new (&_valueStorage) T(src.GetValueRef());
			}
		}
		else if (_hasValue && !src._hasValue)
		{
			ClearValue();
		}
		else
		{
			// Both have no value, do nothing
		}
	}

	template <typename U>
	void MoveConstruct(OptDefaultStorage<U>&& src)
	{
		if (src._hasValue)
		{
			_hasValue = true;
			new (&_valueStorage) T(std::move(src.GetValueRef()));
			// Note: src still has a value after this, but it has been moved from
		}
		else
		{
			_hasValue = false;
		}
	}

	template <typename U>
	void MoveAssign(OptDefaultStorage<U>&& src)
	{
		if (_hasValue && src._hasValue)
		{
			if (this != &src)
			{
				GetValueRef() = std::move(src.GetValueRef());
			}
		}
		else if (!_hasValue && src._hasValue)
		{
			if (this != &src)
			{
				_hasValue = true;
				new (&_valueStorage) T(std::move(src.GetValueRef()));
			}
		}
		else if (_hasValue && !src._hasValue)
		{
			ClearValue();
		}
		else
		{
			// Both have no value, do nothing
		}
	}

	void ClearValue()
	{
		_hasValue = false;
		Destruct();
	}

	void Destruct()
	{
		_valueStorage.~T();
	}

	Bool				_hasValue;
	union
	{
		T _valueStorage;
	};
};

template <typename T>
using OptStorageType = typename std::conditional<
	std::is_scalar<T>::value,
	maxon::details::OptScalarStorage<T>,
	maxon::details::OptDefaultStorage<T>>::type;

template <typename SUPER> class ResultOptFunctions : public SUPER
{
public:
	using SUPER::SUPER;

	template <typename U>
	Result<typename SUPER::ValueType::ValueType> GetValueOr(U&& defaultValue) const
	{
		if (this->_error.GetReferencedError())
			return this->_error;
		return this->UncheckedGetValue().GetValueOr(std::forward<U>(defaultValue));
	}

	Result<typename SUPER::ValueType::ValueType> GetValueOrNull() const
	{
		if (this->_error.GetReferencedError())
			return this->_error;
		return this->UncheckedGetValue().GetValueOrNull();
	}

	template <typename U>
	Result<typename SUPER::ValueType::ValueType> MoveValueOr(U&& defaultValue)
	{
		if (this->_error.GetReferencedError())
			return this->_error;
		return this->UncheckedGetValue().MoveValueOr(std::forward<U>(defaultValue));
	}

	Result<typename SUPER::ValueType::ValueType> MoveValueOrNull()
	{
		if (this->_error.GetReferencedError())
			return this->_error;
		return this->UncheckedGetValue().MoveValueOrNull();
	}
};

} // namespace details

//----------------------------------------------------------------------------------------
/// An Opt<T> represents an optional value. Either it holds a value of type T, or no value.
/// This is similar to tagging a value with a flag that indicates whether the value is
/// present/valid, e.g. with a Pair<Bool,T>.
/// Opt handles construction/destruction of the contained value, so that constructors and
/// destructors are only called if there is an actual contained value.
/// The value storage is allocated directly within Opt.
///
/// The value of an Optional can be accessed like a pointer:
/// @code
/// Opt<Int> opt;
/// // ...
/// if (opt)
///   Int v = *opt; // Fast, but undefined behaviour like a pointer if opt has no value.
/// @endcode
///
/// Alternatively, the value can be retrieved with GetValue():
/// @code
/// Opt<Int> opt;
/// Int v = opt.GetValue() iferr_return; // Returns IllegalStateError if opt has no value.
/// @endcode
///
/// @tparam T											Type of the contained value.
//----------------------------------------------------------------------------------------
template <typename T>
class Opt
{
public:
	using ValueType = T;
	template <typename SUPER> using ResultFunctions = maxon::details::ResultOptFunctions<SUPER>;

	//----------------------------------------------------------------------------------------
	/// Default constructor. Creates an Opt with no value.
	//----------------------------------------------------------------------------------------
	Opt() = default;

	//----------------------------------------------------------------------------------------
	/// Explicit construction with no value. Has the same effect as the default constructor.
	//----------------------------------------------------------------------------------------
	MAXON_IMPLICIT Opt(NO_VALUE_TYPE) : _storage(NO_VALUE) { }

	//----------------------------------------------------------------------------------------
	/// Assignment with no value.
	/// If this object contains a value, the destructor of the contained value is called.
	/// Afterwards, this object no longer contains a value.
	//----------------------------------------------------------------------------------------
	Opt& operator =(NO_VALUE_TYPE)
	{
		_storage = NO_VALUE;
		return *this;
	}

	//----------------------------------------------------------------------------------------
	/// Copy constructor.
	/// (1) If src contains no value, this object will not contain a value either.
	/// (2) If src contains a value, the value of this object is copy-constructed with the former, i.e. T thisValue(srcValue).
	/// This constructor is enabled only if T is copy constructible.
	//----------------------------------------------------------------------------------------
	MAXON_DECLARE_CONDITIONAL_COPY_CONSTRUCTOR(Opt, std::is_copy_constructible<maxon::details::OptStorageType<T>>::value) : _storage(src._storage) { }

	//----------------------------------------------------------------------------------------
	/// Converting copy constructor. For semantics, see non-converting variant.
	/// This constructor is enabled only if T is constructible from const U&.
	//----------------------------------------------------------------------------------------
	template
	<
		typename U,
		typename = typename std::enable_if<std::is_constructible<maxon::details::OptStorageType<T>, const maxon::details::OptStorageType<U>&>::value>::type
	>
	Opt(const Opt<U>& src) : _storage(src._storage) { }

	//----------------------------------------------------------------------------------------
	/// Copy assignment.
	/// (1) If both this object and src contain no value, this function does nothing.
	/// (2) If only this object contains a value, behavior is identical to assignment with no value.
	/// (3) If only src contains a value, behavior is identical to copy constructor.
	/// (4) If both this object and src contain a value, the contained value is assigned src's value, i.e. thisValue = srcValue.
	/// This operator is enabled only if T is copy assignable.
	//----------------------------------------------------------------------------------------
	MAXON_DECLARE_CONDITIONAL_COPY_ASSIGNMENT(Opt, std::is_copy_assignable<maxon::details::OptStorageType<T>>::value)
	{
		_storage = src._storage;
		return *this;
	}
	
	//----------------------------------------------------------------------------------------
	/// Converting copy assignment. For semantics, see non-converting variant.
	/// This operator is enabled only if T is assignable from const U&.
	//----------------------------------------------------------------------------------------
	template
	<
		typename U,
		typename = typename std::enable_if<std::is_assignable<maxon::details::OptStorageType<T>, const maxon::details::OptStorageType<U>&>::value>::type
	>
	Opt& operator =(const Opt<U>& src)
	{
		_storage = src._storage;
		return *this;
	}

	//----------------------------------------------------------------------------------------
	/// Move constructor.
	/// (1) If src contains no value, this object will not contain a value either.
	/// (2) If src contains a value, the value of this object is move-constructed with the former, i.e. T thisValue(std::move(srcValue)).
	/// Note that afterwards, src will still have a value, which has been moved from.
	/// This constructor is enabled only if T is move constructible.
	//----------------------------------------------------------------------------------------
	MAXON_DECLARE_CONDITIONAL_MOVE_CONSTRUCTOR(Opt, std::is_move_constructible<maxon::details::OptStorageType<T>>::value) : _storage(std::move(src._storage)) { }

	//----------------------------------------------------------------------------------------
	/// Converting move constructor. For semantics, see non-converting variant.
	/// This constructor is enabled only if T is constructible from U&&.
	//----------------------------------------------------------------------------------------
	template
	<
		typename U,
		typename = typename std::enable_if<std::is_constructible<maxon::details::OptStorageType<T>, maxon::details::OptStorageType<U>&&>::value>::type
	>
	Opt(Opt<U>&& src) : _storage(std::move(src._storage)) { }

	//----------------------------------------------------------------------------------------
	/// Move assignment.
	/// (1,2) See copy assignment.
	/// (3) If only src contains a value, behavior is identical to move constructor.
	/// (4) If both this object and src contain a value, the contained value is assigned src's value, i.e. thisValue = std::move(srcValue).
	/// This operator is enabled only if T is move assignable.
	//----------------------------------------------------------------------------------------
	MAXON_DECLARE_CONDITIONAL_MOVE_ASSIGNMENT(Opt, std::is_move_assignable<maxon::details::OptStorageType<T>>::value)
	{
		_storage = std::move(src._storage);
		return *this;
	}
	
	//----------------------------------------------------------------------------------------
	/// Converting move assignment. For semantics, see non-converting variant.
	/// (1,2) See copy assignment.
	/// (3) If only src contains a value, behavior is identical to move constructor.
	/// (4) If both this object and src contain a value, the contained value is assigned src's value, i.e. thisValue = std::move(srcValue).
	/// This operator is enabled only if T is assignable from U&&.
	//----------------------------------------------------------------------------------------
	template
	<
		typename U,
		typename = typename std::enable_if<std::is_assignable<maxon::details::OptStorageType<T>, maxon::details::OptStorageType<U>&&>::value>::type
	>
	Opt& operator =(Opt<U>&& src)
	{
		_storage = std::move(src._storage);
		return *this;
	}

	//----------------------------------------------------------------------------------------
	/// Copy-from-value constructor.
	/// Constructs object as if direct-initializing the contained value with the passed value, i.e. T thisValue(value).
	//----------------------------------------------------------------------------------------
	MAXON_IMPLICIT Opt(const T& value) : _storage(value) { }

	//----------------------------------------------------------------------------------------
	/// Move-from-value constructor.
	/// Constructs object as if direct-initializing the contained value with the passed value, i.e. T thisValue(std::move(value)).
	//----------------------------------------------------------------------------------------
	MAXON_IMPLICIT Opt(T&& value) : _storage(std::move(value)) { }

	//----------------------------------------------------------------------------------------
	/// Constructs from optional const-reference.
	/// (1) If src references no value, this object will not contain a value either.
	/// (2) If src references a value, the value of this object is copy-constructed with the former, i.e. T thisValue(*src).
	/// This constructor is enabled only if T is constructible from const U&.
	//----------------------------------------------------------------------------------------
	template
	<
		typename U,
		typename = typename std::enable_if<std::is_constructible<maxon::details::OptStorageType<T>, const U&>::value>::type
	>
	Opt(Opt<const U&> src) : _storage(NO_VALUE)
	{
		if (src)
			_storage = *src;
	}

	//----------------------------------------------------------------------------------------
	/// Assign from optional const-reference.
	/// (1) If this object contains no value and src references no value, this function does nothing.
	/// (2) If this object contains a value and src references no value, behavior is identical to assignment with no value.
	/// (3) If this object contains no value and src references a value, behavior is identical to copy-from-value constructor.
	/// (4) If this object contains a value and src references a value, the value of this object is assigned from *src.
	/// This operator is enabled only if T is assignable from const U&.
	//----------------------------------------------------------------------------------------
	template
	<
		typename U,
		typename = typename std::enable_if<std::is_assignable<maxon::details::OptStorageType<T>, const U&>::value>::type
	>
	Opt& operator =(Opt<const U&> src)
	{
		if (src)
			_storage = *src;
		else
			_storage = NO_VALUE;
		return *this;
	}

	//----------------------------------------------------------------------------------------
	/// Constructs from optional reference. For semantics, see const-reference variant.
	/// This constructor is enabled only if T is constructible from U&.
	//----------------------------------------------------------------------------------------
	template
	<
		typename U,
		typename = typename std::enable_if<std::is_constructible<maxon::details::OptStorageType<T>, U&>::value>::type
	>
	Opt(Opt<U&> src) : _storage(NO_VALUE)
	{
		if (src)
			_storage = *src;
	}

	//----------------------------------------------------------------------------------------
	/// Assign from optional reference. For semantics, see const-reference variant.
	/// This operator is enabled only if T is assignable from U&.
	//----------------------------------------------------------------------------------------
	template
	<
		typename U,
		typename = typename std::enable_if<std::is_assignable<maxon::details::OptStorageType<T>, U&>::value>::type
	>
	Opt& operator =(Opt<U&> src)
	{
		if (src)
			_storage = *src;
		else
			_storage = NO_VALUE;
		return *this;
	}

	//----------------------------------------------------------------------------------------
	/// Constructs from optional rvalue-reference. For semantics, see const-reference variant, with the following differences:
	/// (2) If src references a value, the value of this object is copy-constructed with the former, i.e. T thisValue(*src).
	/// This constructor is enabled only if T is constructible from U&&.
	//----------------------------------------------------------------------------------------
	template
	<
		typename U,
		typename = typename std::enable_if<std::is_constructible<maxon::details::OptStorageType<T>, U&&>::value>::type
	>
	Opt(Opt<U&&> src) : _storage(NO_VALUE)
	{
		if (src)
			_storage = std::move(*src);
	}

	//----------------------------------------------------------------------------------------
	/// Assign from optional rvalue-reference. For semantics, see const-reference variant, with the following differences:
	/// (3) If this object contains no value and src references a value, behavior is identical to move-from-value constructor.
	/// (4) If this object contains a value and src references a value, the value of this object is assigned from std::move(*src).
	/// This operator is enabled only if T is assignable from U&&.
	//----------------------------------------------------------------------------------------
	template
	<
		typename U,
		typename = typename std::enable_if<std::is_assignable<maxon::details::OptStorageType<T>, U&&>::value>::type
	>
	Opt& operator =(Opt<U&&> src)
	{
		if (src)
			_storage = std::move(*src);
		else
			_storage = NO_VALUE;
		return *this;
	}

	//----------------------------------------------------------------------------------------
	/// Emplace constructor.
	/// Constructs the contained value in-place with given arguments, i.e. T thisValue(std::forward<ARGS>(args) ...).
	//----------------------------------------------------------------------------------------
	template <typename ... ARGS>
	explicit Opt(IN_PLACE_TYPE, ARGS&& ... args) : _storage(std::forward<ARGS>(args) ...) { }

	//----------------------------------------------------------------------------------------
	/// Constructs a new value in-place. Behavior is similar to the in-place constructor,
	/// with the difference that if the object already contained a value, the current value is
	/// destructed first.
	//----------------------------------------------------------------------------------------
	template <typename ... ARGS>
	void Emplace(ARGS&& ... args)
	{
		_storage.Emplace(std::forward<ARGS>(args) ...);
	}
	
	//----------------------------------------------------------------------------------------
	/// Semantically equivalent to copy assignment, but uses CopyFrom() of the contained value.
	/// Use this if copying T may result in an error.
	/// This function is enabled only if T implements CopyFrom().
	//----------------------------------------------------------------------------------------
	template
	<
		Bool ENABLE = true,
		typename = typename std::enable_if<
			ENABLE && TestForCopyFromMember<T>::isSupported>::type
	>
	Result<void> CopyFrom(const Opt& src)
	{
		return _storage.CopyFrom(src._storage);
	}
	
	//----------------------------------------------------------------------------------------
	/// If this Opt contains a value, the latter is destroyed.
	//----------------------------------------------------------------------------------------
	~Opt() = default;

	void Reset()
	{
		_storage = NO_VALUE;
	}

	//----------------------------------------------------------------------------------------
	/// Returns true if this Opt contains a value.
	//----------------------------------------------------------------------------------------
	Bool HasValue() const
	{
		return _storage.HasValue();
	}

	explicit operator Bool() const
	{
		return HasValue();
	}

	//----------------------------------------------------------------------------------------
	/// Returns the contained value, or IllegalState error if Opt contained no value.
	//----------------------------------------------------------------------------------------
	Result<T&> GetValue()
	{
		if (! HasValue())
			return IllegalStateError(MAXON_SOURCE_LOCATION, "Called GetValue() on Opt that contains no value"_s);
		else
			return GetValueRef();
	}

	Result<const T&> GetValue() const
	{
		if (! HasValue())
			return IllegalStateError(MAXON_SOURCE_LOCATION, "Called GetValue() on Opt that contains no value"_s);
		else
			return GetValueRef();
	}

	//----------------------------------------------------------------------------------------
	/// Returns the contained value, or a default value if Opt contained no value.
	//----------------------------------------------------------------------------------------
	template <typename U>
	T GetValueOr(U&& defaultValue) const
	{
		if (! HasValue())
			return static_cast<T>(std::forward<U>(defaultValue));
		else
			return GetValueRef();
	}

	//----------------------------------------------------------------------------------------
	/// Returns the contained value, or a null value if Opt contained no value.
	//----------------------------------------------------------------------------------------
	T GetValueOrNull() const
	{
		if (! HasValue())
			return NullValue<T>();
		else
			return GetValueRef();
	}

	//----------------------------------------------------------------------------------------
	/// Returns the moved contained value, or IllegalState error if object contained no value.
	//----------------------------------------------------------------------------------------
	Result<T> MoveValue()
	{
		if (! HasValue())
			return IllegalStateError(MAXON_SOURCE_LOCATION, "Called MoveValue() on Opt that contains no value"_s);
		else
			return std::move(GetValueRef());
	}

	//----------------------------------------------------------------------------------------
	/// Returns the moved contained value, or a default value if object contained no value.
	//----------------------------------------------------------------------------------------
	template <typename U>
	T MoveValueOr(U&& defaultValue)
	{
		if (! HasValue())
			return static_cast<T>(std::forward<U>(defaultValue));
		else
			return std::move(GetValueRef());
	}

	//----------------------------------------------------------------------------------------
	/// Returns the moved contained value, or a null value if Opt contained no value.
	//----------------------------------------------------------------------------------------
	T MoveValueOrNull()
	{
		if (! HasValue())
			return NullValue<T>();
		else
			return std::move(GetValueRef());
	}

	//----------------------------------------------------------------------------------------
	/// Returns a pointer to the contained value.
	/// Results in undefined behavior if object contained no value.
	//----------------------------------------------------------------------------------------
	const T* operator ->() const
	{
		CheckValue();
		return &GetValueRef();
	}

	T* operator ->()
	{
		CheckValue();
		return &GetValueRef();
	}

	//----------------------------------------------------------------------------------------
	/// Returns a reference to the contained value.
	/// Results in undefined behavior if object contained no value.
	//----------------------------------------------------------------------------------------
	const T& operator *() const
	{
		CheckValue();
		return GetValueRef();
	}

	T& operator *()
	{
		CheckValue();
		return GetValueRef();
	}

	//----------------------------------------------------------------------------------------
	/// Returns a formated string representation of this optional value.
	//----------------------------------------------------------------------------------------
	typename SFINAEHelper<String, T>::type ToString(const FormatStatement* format) const
	{
		if (HasValue())
			return GlobalToString(GetValueRef(), format);
		else
			return "(no value)"_s;
	}

	UInt GetHashCode() const
	{
		return HasValue() ? DefaultCompare::GetHashCode(GetValueRef()) : 0;
	}

private:
	maxon::details::OptStorageType<T> _storage;

	MAXON_ATTRIBUTE_FORCE_INLINE void CheckValue() const
	{
		DebugAssert(HasValue(), "Tried to access Opt with no value.");
	}

	T& GetValueRef()
	{
		return _storage.GetValueRef();
	}

	const T& GetValueRef() const
	{
		return _storage.GetValueRef();
	}
	
	template <typename U>
	friend class Opt;
};

//----------------------------------------------------------------------------------------
/// Specialization to store lvalue references, which only uses a single pointer internally.
/// This can be used to treat pointers that may be null as optional references for more descriptive interfaces.
//----------------------------------------------------------------------------------------
template <typename T>
class Opt<T&>
{
public:
	using ValueType = T&;
	template <typename SUPER> using ResultFunctions = maxon::details::ResultOptFunctions<SUPER>;

	//----------------------------------------------------------------------------------------
	/// Default constructor. Creates an Optional with no value.
	//----------------------------------------------------------------------------------------
	Opt() : _dataPtr(nullptr) { }

	//----------------------------------------------------------------------------------------
	/// Explicit construction with NO_VALUE. Has the same effect as the default constructor.
	//----------------------------------------------------------------------------------------
	MAXON_IMPLICIT Opt(NO_VALUE_TYPE) : _dataPtr(nullptr) { }

	//----------------------------------------------------------------------------------------
	/// Copy constructor.
	//----------------------------------------------------------------------------------------
	Opt(const Opt& src) : _dataPtr(src._dataPtr) { }
	
	//----------------------------------------------------------------------------------------
	/// Copy assignment.
	//----------------------------------------------------------------------------------------
	Opt& operator =(const Opt& src)
	{
		_dataPtr = src._dataPtr;
		return *this;
	}

	//----------------------------------------------------------------------------------------
	/// Constructs from reference.
	//----------------------------------------------------------------------------------------
	MAXON_IMPLICIT Opt(T& value) : _dataPtr(&value) { }

	//----------------------------------------------------------------------------------------
	/// Assign from reference.
	//----------------------------------------------------------------------------------------
	Opt& operator =(T& value)
	{
		_dataPtr = &value;
		return *this;
	}

	//----------------------------------------------------------------------------------------
	/// Constructs from raw pointer.
	//----------------------------------------------------------------------------------------
	MAXON_IMPLICIT Opt(T* valuePtr) : _dataPtr(valuePtr) { }

	//----------------------------------------------------------------------------------------
	/// Assign from raw pointer.
	//----------------------------------------------------------------------------------------
	Opt& operator =(T* valuePtr)
	{
		_dataPtr = valuePtr;
		return *this;
	}

	//----------------------------------------------------------------------------------------
	/// Returns true if this object contains a value.
	//----------------------------------------------------------------------------------------
	Bool HasValue() const
	{
		return _dataPtr != nullptr;
	}

	explicit operator Bool()
	{
		return HasValue();
	}

	explicit operator Bool() const
	{
		return HasValue();
	}

	//----------------------------------------------------------------------------------------
	/// Returns the contained value, or IllegalState error if object contained no value.
	//----------------------------------------------------------------------------------------
	Result<T&> GetValue() const
	{
		if (! HasValue())
			return IllegalStateError(MAXON_SOURCE_LOCATION, "Called GetValue() on Optional that contains no value"_s);
		else
			return *_dataPtr;
	}

	//----------------------------------------------------------------------------------------
	/// Returns the contained value, or a default value if object contained no value.
	//----------------------------------------------------------------------------------------
	T& GetValueOr(T& defaultValue) const
	{
		if (! HasValue())
			return defaultValue;
		else
			return *_dataPtr;
	}

	//----------------------------------------------------------------------------------------
	/// Returns a pointer to the contained value.
	/// Results in undefined behavior if object contained no value.
	//----------------------------------------------------------------------------------------
	const T* operator ->() const
	{
		CheckValue();
		return _dataPtr;
	}

	T* operator ->()
	{
		CheckValue();
		return _dataPtr;
	}

	//----------------------------------------------------------------------------------------
	/// Returns a reference to the contained value.
	/// Results in undefined behavior if object contained no value.
	//----------------------------------------------------------------------------------------
	const T& operator *() const
	{
		CheckValue();
		return *_dataPtr;
	}

	T& operator *()
	{
		CheckValue();
		return *_dataPtr;
	}

	T* ToPointer()
	{
		return _dataPtr;
	}

	const T* ToPointer() const
	{
		return _dataPtr;
	}

	//----------------------------------------------------------------------------------------
	/// Converts the optional reference to a raw pointer.
	/// This is supported for interoperability with legacy code.
	//----------------------------------------------------------------------------------------
	operator T*()
	{
		return ToPointer();
	}

	operator const T*()
	{
		return ToPointer();
	}

private:
	MAXON_ATTRIBUTE_FORCE_INLINE void CheckValue() const
	{
		DebugAssert(_dataPtr != nullptr, "Tried to access Optional reference with no value.");
	}

	T* _dataPtr;
};

//----------------------------------------------------------------------------------------
/// Specialization to store const lvalue references, which only uses a single pointer internally.
/// This can be used to treat pointers that may be null as optional references for more descriptive interfaces.
//----------------------------------------------------------------------------------------
template <typename T>
class Opt<const T&>
{
public:
	using ValueType = const T&;
	template <typename SUPER> using ResultFunctions = maxon::details::ResultOptFunctions<SUPER>;

	//----------------------------------------------------------------------------------------
	/// Default constructor. Creates an Opt with no value.
	//----------------------------------------------------------------------------------------
	Opt() : _dataPtr(nullptr) { }

	//----------------------------------------------------------------------------------------
	/// Explicit construction with NO_VALUE. Has the same effect as the default constructor.
	//----------------------------------------------------------------------------------------
	MAXON_IMPLICIT Opt(NO_VALUE_TYPE) : _dataPtr(nullptr) { }

	//----------------------------------------------------------------------------------------
	/// Copy constructor.
	//----------------------------------------------------------------------------------------
	Opt(const Opt& src) : _dataPtr(src._dataPtr) { }
	
	//----------------------------------------------------------------------------------------
	/// Copy assignment.
	//----------------------------------------------------------------------------------------
	Opt& operator =(const Opt& src)
	{
		_dataPtr = src._dataPtr;
		return *this;
	}

	//----------------------------------------------------------------------------------------
	/// Constructs from const reference.
	//----------------------------------------------------------------------------------------
	MAXON_IMPLICIT Opt(const T& value) : _dataPtr(&value) { }

	//----------------------------------------------------------------------------------------
	/// Constructs from raw pointer.
	//----------------------------------------------------------------------------------------
	MAXON_IMPLICIT Opt(const T* valuePtr) : _dataPtr(valuePtr) { }

	//----------------------------------------------------------------------------------------
	/// Returns true if this object contains a value.
	//----------------------------------------------------------------------------------------
	Bool HasValue() const
	{
		return _dataPtr != nullptr;
	}

	explicit operator Bool()
	{
		return HasValue();
	}

	explicit operator Bool() const
	{
		return HasValue();
	}

	//----------------------------------------------------------------------------------------
	/// Returns the contained value, or IllegalState error if object contained no value.
	//----------------------------------------------------------------------------------------
	Result<const T&> GetValue() const
	{
		if (! HasValue())
			return IllegalStateError(MAXON_SOURCE_LOCATION, "Called GetValue() on Optional that contains no value"_s);
		else
			return *_dataPtr;
	}

	//----------------------------------------------------------------------------------------
	/// Returns the contained value, or a default value if object contained no value.
	//----------------------------------------------------------------------------------------
	const T& GetValueOr(const T& defaultValue) const
	{
		if (! HasValue())
			return defaultValue;
		else
			return *_dataPtr;
	}

	const T& GetValueOr(T&& defaultValue) const = delete;

	//----------------------------------------------------------------------------------------
	/// Returns the contained value, or a null value if object contained no value.
	//----------------------------------------------------------------------------------------
	const T& GetValueOrNull() const
	{
		if (! HasValue())
			return NullValue<const T&>();
		else
			return *_dataPtr;
	}

	//----------------------------------------------------------------------------------------
	/// Returns a pointer to the contained value.
	/// Results in undefined behavior if object contained no value.
	//----------------------------------------------------------------------------------------
	const T* operator ->() const
	{
		CheckValue();
		return _dataPtr;
	}

	//----------------------------------------------------------------------------------------
	/// Returns a reference to the contained value.
	/// Results in undefined behavior if object contained no value.
	//----------------------------------------------------------------------------------------
	const T& operator *() const
	{
		CheckValue();
		return *_dataPtr;
	}

	const T* ToPointer() const
	{
		return _dataPtr;
	}

	//----------------------------------------------------------------------------------------
	/// Converts the optional reference to a raw pointer.
	/// This is supported for interoperability with legacy code.
	//----------------------------------------------------------------------------------------
	operator const T*()
	{
		return ToPointer();
	}

private:
	MAXON_ATTRIBUTE_FORCE_INLINE void CheckValue() const
	{
		DebugAssert(_dataPtr != nullptr, "Tried to access Optional reference with no value.");
	}

	const T* _dataPtr;
};

//----------------------------------------------------------------------------------------
/// Specialization to store rvalue references, which only uses a single pointer internally.
/// This can be used to treat pointers that may be null as optional references for more descriptive interfaces.
//----------------------------------------------------------------------------------------
template <typename T>
class Opt<T&&>
{
public:
	using ValueType = T&&;
	template <typename SUPER> using ResultFunctions = maxon::details::ResultOptFunctions<SUPER>;

	//----------------------------------------------------------------------------------------
	/// Default constructor. Creates an Opt with no value.
	//----------------------------------------------------------------------------------------
	Opt() : _dataPtr(nullptr) { }

	//----------------------------------------------------------------------------------------
	/// Explicit construction with NO_VALUE. Has the same effect as the default constructor.
	//----------------------------------------------------------------------------------------
	MAXON_IMPLICIT Opt(NO_VALUE_TYPE) : _dataPtr(nullptr) { }

	//----------------------------------------------------------------------------------------
	/// Deleted copy constructor.
	//----------------------------------------------------------------------------------------
	Opt(const Opt& src) = delete;
	
	//----------------------------------------------------------------------------------------
	/// Deleted copy assignment.
	//----------------------------------------------------------------------------------------
	Opt& operator =(const Opt&) = delete;

	//----------------------------------------------------------------------------------------
	/// Move constructor.
	//----------------------------------------------------------------------------------------
	Opt(Opt&& src) : _dataPtr(src._dataPtr) { }
	
	//----------------------------------------------------------------------------------------
	/// Move assignment.
	//----------------------------------------------------------------------------------------
	Opt& operator =(Opt&& src)
	{
		_dataPtr = src._dataPtr;
		return *this;
	}

	//----------------------------------------------------------------------------------------
	/// Constructs from rvalue reference.
	//----------------------------------------------------------------------------------------
	MAXON_IMPLICIT Opt(typename std::remove_reference<T>::type&& value) : _dataPtr(&value) { }

	//----------------------------------------------------------------------------------------
	/// Returns true if this object contains a value.
	//----------------------------------------------------------------------------------------
	Bool HasValue() const
	{
		return _dataPtr != nullptr;
	}

	explicit operator Bool()
	{
		return HasValue();
	}

	explicit operator Bool() const
	{
		return HasValue();
	}

	//----------------------------------------------------------------------------------------
	/// Returns the moved out contained value, or IllegalState error if Opt contained no value.
	//----------------------------------------------------------------------------------------
	Result<T> MoveValue()
	{
		if (! HasValue())
			return IllegalStateError(MAXON_SOURCE_LOCATION, "Called MoveValue() on Opt that contains no value"_s);
		else
			return std::move(*_dataPtr);
	}

	//----------------------------------------------------------------------------------------
	/// Returns the contained value, or IllegalState error if object contained no value.
	//----------------------------------------------------------------------------------------
	Result<T&&> GetValue() const
	{
		if (! HasValue())
			return IllegalStateError(MAXON_SOURCE_LOCATION, "Called GetValue() on Optional that contains no value"_s);
		else
			return std::move(*_dataPtr);
	}

	//----------------------------------------------------------------------------------------
	/// Returns the contained value, or a default value if object contained no value.
	//----------------------------------------------------------------------------------------
	T&& GetValueOr(T&& defaultValue) const
	{
		if (! HasValue())
			return std::move(defaultValue);
		else
			return std::move(*_dataPtr);
	}

	//----------------------------------------------------------------------------------------
	/// Returns a rvalue reference to the contained value.
	/// Results in undefined behavior if object contained no value.
	//----------------------------------------------------------------------------------------
	T&& operator *()
	{
		CheckValue();
		return std::move(*_dataPtr);
	}

	//----------------------------------------------------------------------------------------
	/// Converts the optional reference to a raw pointer.
	/// This is supported for interoperability with legacy code.
	//----------------------------------------------------------------------------------------
	operator T*()
	{
		CheckValue();
		return _dataPtr;
	}

	operator const T*()
	{
		CheckValue();
		return _dataPtr;
	}

private:
	MAXON_ATTRIBUTE_FORCE_INLINE void CheckValue() const
	{
		DebugAssert(_dataPtr != nullptr, "Tried to access Opt reference with no value.");
	}

private:
	T* _dataPtr;
};

//----------------------------------------------------------------------------------------
/// Returns true if both Opts have the same value or both have no value.
//----------------------------------------------------------------------------------------
template <typename T>
inline Bool operator ==(const Opt<T>& lhs, const Opt<T>& rhs)
{
	return (!lhs.HasValue() && !rhs.HasValue())
		|| ((lhs.HasValue() && rhs.HasValue()) && *lhs == *rhs);
}

//----------------------------------------------------------------------------------------
/// Returns true, if Opt contains no value.
//----------------------------------------------------------------------------------------
template <typename T>
inline Bool operator ==(const Opt<T>& opt, NO_VALUE_TYPE)
{
	return !opt.HasValue();
}

template <typename T> inline Bool operator ==(NO_VALUE_TYPE, const Opt<T>& opt)
{
	return !opt.HasValue();
}

//----------------------------------------------------------------------------------------
/// Returns true, if Opt contains a value.
//----------------------------------------------------------------------------------------
template <typename T>
inline Bool operator !=(const Opt<T>& opt, NO_VALUE_TYPE)
{
	return opt.HasValue();
}

template <typename T>
inline Bool operator !=(NO_VALUE_TYPE, const Opt<T>& opt)
{
	return opt.HasValue();
}

template <typename T>
using Optional = Opt<T>;

} // namespace maxon

#endif // OPTIONAL_H__
