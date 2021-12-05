#ifndef ERRORBASE_H__
#define ERRORBASE_H__

#include "maxon/objectbase.h"

namespace maxon
{

/// @addtogroup SYSTEM
/// @{

//----------------------------------------------------------------------------------------
/// An OutOfMemoryError indicates that a memory allocation failed.
//----------------------------------------------------------------------------------------
class OutOfMemoryErrorInterface : MAXON_INTERFACE_BASES(ErrorInterface)
{
	MAXON_INTERFACE(OutOfMemoryErrorInterface, MAXON_REFERENCE_COPY_ON_WRITE, "net.maxon.interface.outofmemoryerror");
};

//----------------------------------------------------------------------------------------
/// A FunctionNotImplementedError indicates that a function has been invoked
/// which did not contain a suitable implementation.
/// This error type creates the full call stack so that you can see where the call came from.
//----------------------------------------------------------------------------------------
class FunctionNotImplementedErrorInterface : MAXON_INTERFACE_BASES(ErrorInterface)
{
	MAXON_INTERFACE(FunctionNotImplementedErrorInterface, MAXON_REFERENCE_COPY_ON_WRITE, "net.maxon.interface.functionnotimplementederror");
};

//----------------------------------------------------------------------------------------
/// An UnresolvedError indicates that an interface or declaration was accessed for which
/// there is no definition.
//----------------------------------------------------------------------------------------
class UnresolvedErrorInterface : MAXON_INTERFACE_BASES(ErrorInterface)
{
	MAXON_INTERFACE(UnresolvedErrorInterface, MAXON_REFERENCE_COPY_ON_WRITE, "net.maxon.interface.unresolvederror");
};

//----------------------------------------------------------------------------------------
/// An UnsupportedOperationError indicates that the intended operation is
/// not supported by the implementation (for example, the attempt to modify a read-only dictionary).
//----------------------------------------------------------------------------------------
class UnsupportedOperationErrorInterface : MAXON_INTERFACE_BASES(ErrorInterface)
{
	MAXON_INTERFACE(UnsupportedOperationErrorInterface, MAXON_REFERENCE_COPY_ON_WRITE, "net.maxon.interface.unsupportedoperationerror");
};

//----------------------------------------------------------------------------------------
/// A ThreadCancelledError is returned if a function terminated because the thread has been stopped from outside.
//----------------------------------------------------------------------------------------
class ThreadCancelledErrorInterface : MAXON_INTERFACE_BASES(ErrorInterface)
{
	MAXON_INTERFACE(ThreadCancelledErrorInterface, MAXON_REFERENCE_COPY_ON_WRITE, "net.maxon.interface.threadcancellederror");
};

//----------------------------------------------------------------------------------------
/// An IllegalArgumentError is returned if an illegal argument was passed to a function parameter.
//----------------------------------------------------------------------------------------
class IllegalArgumentErrorInterface : MAXON_INTERFACE_BASES(ErrorInterface)
{
	MAXON_INTERFACE(IllegalArgumentErrorInterface, MAXON_REFERENCE_COPY_ON_WRITE, "net.maxon.interface.illegalargumenterror");
};

//----------------------------------------------------------------------------------------
/// An UnsupportedArgumentError indicates that a generally valid argument was passed to a function parameter,
/// but the function implementation doesn't support that argument. An example is the
/// conversion of a value to a destination type where the particular combination of value
/// and destination type is not supported by the converter.
//----------------------------------------------------------------------------------------
class UnsupportedArgumentErrorInterface : MAXON_INTERFACE_BASES(ErrorInterface)
{
	MAXON_INTERFACE(UnsupportedArgumentErrorInterface, MAXON_REFERENCE_COPY_ON_WRITE, "net.maxon.interface.unsupportedargumenterror");
};

//----------------------------------------------------------------------------------------
/// A NullptrError is returned if an (illegal) nullptr was passed to a function.
//----------------------------------------------------------------------------------------
class NullptrErrorInterface : MAXON_INTERFACE_BASES(IllegalArgumentErrorInterface)
{
	MAXON_INTERFACE(NullptrErrorInterface, MAXON_REFERENCE_COPY_ON_WRITE, "net.maxon.interface.nullptrerror");
};

//----------------------------------------------------------------------------------------
/// An IllegalStateError indicates that a function has been invoked on an object and the object
/// hasn't been in a state which allows the proper execution of the function.
//----------------------------------------------------------------------------------------
class IllegalStateErrorInterface : MAXON_INTERFACE_BASES(ErrorInterface)
{
	MAXON_INTERFACE(IllegalStateErrorInterface, MAXON_REFERENCE_COPY_ON_WRITE, "net.maxon.interface.illegalstateerror");
};

//----------------------------------------------------------------------------------------
/// An UnknownError is returned in places where no specific error was defined.
//----------------------------------------------------------------------------------------
class UnknownErrorInterface : MAXON_INTERFACE_BASES(ErrorInterface)
{
	MAXON_INTERFACE(UnknownErrorInterface, MAXON_REFERENCE_COPY_ON_WRITE, "net.maxon.interface.unknownerror");
};

//----------------------------------------------------------------------------------------
/// A ShutdownError is returned when errors are being used while the object system is being shut down.
//----------------------------------------------------------------------------------------
class ShutdownErrorInterface : MAXON_INTERFACE_BASES(ErrorInterface)
{
	MAXON_INTERFACE(ShutdownErrorInterface, MAXON_REFERENCE_COPY_ON_WRITE, "net.maxon.interface.shutdownerror");
};

//----------------------------------------------------------------------------------------
/// An UnexpectedError is returned when something unexpected happens within a function.
/// This typically indicates a bug in the function (or in one of the other functions which
/// are invoked by the function).
//----------------------------------------------------------------------------------------
class UnexpectedErrorInterface : MAXON_INTERFACE_BASES(ErrorInterface)
{
	MAXON_INTERFACE(UnexpectedErrorInterface, MAXON_REFERENCE_COPY_ON_WRITE, "net.maxon.interface.unexpectederror");
};

//----------------------------------------------------------------------------------------
/// A DisabledError is returned by a registration function to tell that the registration is disabled.
/// The system won't show a warning message for such an error.
//----------------------------------------------------------------------------------------
class DisabledErrorInterface : MAXON_INTERFACE_BASES(ErrorInterface)
{
	MAXON_INTERFACE(DisabledErrorInterface, MAXON_REFERENCE_COPY_ON_WRITE, "net.maxon.interface.disablederror");
};

//----------------------------------------------------------------------------------------
/// Error that contains a errno error state.
/// This error is returned if the error code contains the value of the 'errno' variable at the point when the error occurred.
/// The GetMessage functions retrieves the error text from the system using strerror().
//----------------------------------------------------------------------------------------
class ErrnoErrorInterface : MAXON_INTERFACE_BASES(ErrorInterface)
{
	MAXON_INTERFACE(ErrnoErrorInterface, MAXON_REFERENCE_COPY_ON_WRITE, "net.maxon.interface.errnoerror");
public:
	MAXON_ADD_TO_COPY_ON_WRITE_REFERENCE_CLASS(
protected:
	void Create(MAXON_SOURCE_LOCATION_DECLARATION, Int errorCode)
	{
		*static_cast<typename S::DirectlyReferencedType::Hxx1::ReferenceClass*>(this) = S::DirectlyReferencedType::Hxx1::ErrObj::GetInstance()();
		// If MakeWritable(false) fails the reference won't be nulled (just e).
		typename S::DirectlyReferencedType::Ptr e = this->MakeWritable(false).GetPointer();
		e.SetLocation(MAXON_SOURCE_LOCATION_FORWARD);
		e.SetErrorCode(errorCode);
	}
	);

	//----------------------------------------------------------------------------------------
	/// Returns the errno error code stored in this error.
	//----------------------------------------------------------------------------------------
	MAXON_FUNCTION Int GetErrorCode() const { return reinterpret_cast<const ErrorInterface*>(this)->PrivateGetCode(); }

	//----------------------------------------------------------------------------------------
	/// Sets the errno error code. This error must be returned from the errno system variable.
	/// The error can output the human readable string of the errno error.
	/// @param[in] errorCode					Error code of errno system variable.
	//----------------------------------------------------------------------------------------
	MAXON_FUNCTION void SetErrorCode(Int errorCode) { return reinterpret_cast<ErrorInterface*>(this)->PrivateSetCode(errorCode); }
};


//----------------------------------------------------------------------------------------
/// An UnregisteredDataTypeError is returned by GetDataType<T>() when there is no data type
/// registration for T (or a part of T as in Block<X>).
//----------------------------------------------------------------------------------------
class UnregisteredDataTypeErrorInterface : MAXON_INTERFACE_BASES(ErrorInterface)
{
	MAXON_INTERFACE(UnregisteredDataTypeErrorInterface, MAXON_REFERENCE_COPY_ON_WRITE, "net.maxon.interface.unregistereddatatypeerror");
};


//----------------------------------------------------------------------------------------
/// Error that contains multiple errors.
/// This error might be returned if multiple jobs of a group return errors.
/// The GetMessage functions retrieves the combined output of all errors.
///
/// @MAXON_ANNOTATION{refclass=false}
//----------------------------------------------------------------------------------------
class AggregatedErrorInterface : MAXON_INTERFACE_BASES(ErrorInterface)
{
	MAXON_INTERFACE(AggregatedErrorInterface, MAXON_REFERENCE_COPY_ON_WRITE, "net.maxon.interface.aggregatederror");

public:
	//----------------------------------------------------------------------------------------
	/// Adds an error to this AggregatedError.
	/// @param[in] error							AggregatedError to add.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Bool AddError(const Error& error);

	//----------------------------------------------------------------------------------------
	/// Adds an error to this AggregatedError.
	/// @param[in] error							AggregatedError to add.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Bool AddError(Error&& error);

	//----------------------------------------------------------------------------------------
	/// Returns the number of errors in this AggregatedError.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Int GetCount() const;

	//----------------------------------------------------------------------------------------
	/// Returns the error at the given index.
	/// @param[in] index							Index of the error. Index must be >= 0 and < GetCount().
	/// @return												Error stored at this index.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD const Error& GetError(Int index) const;
};


#include "errorbase1.hxx"

//----------------------------------------------------------------------------------------
/// Base Error class to inherit from.
//----------------------------------------------------------------------------------------
MAXON_DECLARATION(Class<Error>, ErrorObjectClass, "net.maxon.class.errorobject");

//----------------------------------------------------------------------------------------
/// AggregatedError is the reference class of AggregatedErrorInterface.
///
/// Error that contains multiple errors.
/// This error might be returned if multiple jobs of a group return errors.
/// The GetMessage functions retrieves the combined output of all errors.
//----------------------------------------------------------------------------------------
class AggregatedError : public AggregatedErrorInterface::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(AggregatedError, Reference);
	explicit AggregatedError(MAXON_SOURCE_LOCATION_DECLARATION) { Create(MAXON_SOURCE_LOCATION_FORWARD); }

	template <typename TYPE> class ErrorIterator;
	friend class AggregatedErrorObject;
	friend class ResultBase<AggregatedError>;

	explicit AggregatedError(maxon::ERROR_OK) { }

	using ConstIterator = ErrorIterator<const Error>;
	using ValueType = const Error;

	//----------------------------------------------------------------------------------------
	/// Returns the begin iterator of the DataDictionary. You can use the Iterator to run through all elements of the DataDictionary.
	//----------------------------------------------------------------------------------------
	ConstIterator Begin() const
	{
		return ConstIterator(GetPointer(), 0);
	}

	//----------------------------------------------------------------------------------------
	/// Returns the end iterator of the DataDictionary. You can use the Iterator to run through all elements of the DataDictionary.
	//----------------------------------------------------------------------------------------
	ConstIterator End() const
	{
		return ConstIterator(GetPointer(), GetCount());
	}

	//----------------------------------------------------------------------------------------
	/// Iterator to iterate through all errors of the AggregatedError.
	//----------------------------------------------------------------------------------------
	template <typename TYPE> class ErrorIterator
	{
	public:
		ErrorIterator() : _itf(nullptr), _idx(0) {}
		ErrorIterator(const ErrorIterator& src) : _itf(src._itf), _idx(src._idx) {}
		ErrorIterator(ErrorIterator&& src) : _itf(std::move(src._itf)), _idx(std::move(src._idx)) {}

		ErrorIterator(const AggregatedErrorInterface* itf, Int idx) : _itf(itf), _idx(idx) {}

		MAXON_OPERATOR_COPY_ASSIGNMENT(ErrorIterator);
		MAXON_OPERATOR_MOVE_ASSIGNMENT(ErrorIterator);

		Bool operator ==(const ErrorIterator& cmp) const
		{
			return _itf == cmp._itf && _idx == cmp._idx;
		}

		Bool operator !=(const ErrorIterator& cmp) const
		{
			return !(*this == cmp);
		}

		const ErrorIterator& operator ++()
		{
			_idx++;
			return *this;
		}

		ErrorIterator operator ++(int)
		{
			Int tmp = _idx;
			_idx++;
			return ErrorIterator(_itf, tmp);	// use RVO
		}

		explicit operator Bool() const
		{
			return _itf != nullptr;
		}

		TYPE* operator ->() const
		{
			return &_itf->GetError(_idx);
		}

		TYPE& operator *() const
		{
			return _itf->GetError(_idx);
		}

	private:
		const AggregatedErrorInterface* _itf;
		Int _idx;
	};
};

MAXON_DECLARATION(AggregatedError, AggregatedErrorObject, "net.maxon.object.aggregatederror");


#include "errorbase2.hxx"


// support for ErrorPtr see below

class ErrorIndirectRef
{
public:
	using ReferenceClass = ErrorPtr;
	using ReferencedType = const ErrorInterface;
	using Handler = PointerHandler;
	using Component = const ErrorInterface;
	static const Bool DIRECT_REF = false;
	static const Bool HAS_ERROR = false;
	static std::nullptr_t GetWrapper() { return nullptr; }
	const ErrorInterface* GetPointer() const { return _ptr ? *_ptr : nullptr; }
	const ErrorInterface* const* GetStorage() const { return _ptr; }

	template <typename TO> using HasBase = maxon::HasBase<const ErrorInterface, TO>;

	ErrorPtr& PrivateGetRefMember();

	const ErrorPtr& PrivateGetRefMember() const;

protected:
	void SetPointer(const ErrorInterface* const* ptr) { _ptr = ptr; }

	const ErrorInterface* const* _ptr = nullptr;
};

//----------------------------------------------------------------------------------------
/// Helper class used by iferr for the err variable. This is an indirect reference to an Error
/// and it implements conversion functions to ErrorInterface* (for Cast<> in the error case).
//----------------------------------------------------------------------------------------
class ErrorPtr : public ErrorInterface::ReferenceFunctions<RefBaseFunctions<ErrorIndirectRef>>::type
{
public:
	//----------------------------------------------------------------------------------------
	/// Checks if there is an error.
	/// @return												True if this ErrorPtr contains an error, false otherwise.
	//----------------------------------------------------------------------------------------
	explicit operator Bool() const
	{
		DebugAssert(!GetStorage() || GetPointer());
		return MAXON_UNLIKELY(GetStorage() != nullptr);
	}

	/// @private
	explicit operator Bool()
	{
		DebugAssert(!GetStorage() || GetPointer());
		return MAXON_UNLIKELY(GetStorage() != nullptr);
	}
};

//----------------------------------------------------------------------------------------
/// Helper class used by ifnoerr for the err variable. This uses ErrorPtr as base class,
/// but reverses the logic of the conversion operator to Bool.
//----------------------------------------------------------------------------------------
class NoErrorPtr : public ErrorPtr
{
public:
	//----------------------------------------------------------------------------------------
	/// Checks if there is no error.
	/// @return												True if this NoErrorPtr contains no error, false otherwise.
	//----------------------------------------------------------------------------------------
	explicit operator Bool() const
	{
		return !ErrorPtr::operator Bool();
	}

	/// @private
	explicit operator Bool()
	{
		return !ErrorPtr::operator Bool();
	}
};

inline ErrorPtr& ErrorIndirectRef::PrivateGetRefMember()
{
	return *static_cast<ErrorPtr*>(this);
}

inline const ErrorPtr& ErrorIndirectRef::PrivateGetRefMember() const
{
	return *static_cast<const ErrorPtr*>(this);
}

// support ErrorPtr for iferr
MAXON_ATTRIBUTE_FORCE_INLINE void operator %(ErrorPtr& rv, ThreadReferencedError& err)
{
	err = rv.GetErrorStorage();
}

//----------------------------------------------------------------------------------------
/// Casts an err object to an object reference of another error interface type. If the cast would be invalid
/// because the err object isn't an instance of the other error interface, a null reference is returned.
/// @param[in] ref								Error object to cast.
/// @tparam R											Reference class to cast to. This must be a reference class of a virtual interface.
/// @return												Casted reference.
//----------------------------------------------------------------------------------------
template <typename R> inline R Cast(ErrorPtr& ref)
{
	const ObjectInterface* o = ref.GetPointer();
	return R((o && o->IsInstanceOf<typename R::ReferencedType>()) ? static_cast<const typename R::ReferencedType*>(o) : nullptr);
}



// Error* is equivalent to ThreadReferencedError and must be used to avoid an error like "transfer of control bypasses initialization"
// or "Jump bypasses variable initialization" with gotos or switch statements (Clang and ICC).
// Temporarily disable the shadow warning for the err variable.
#define PRIVATE_MAXON_iferr_(ErrType, LINE, ...) \
	maxon::Error* MAXON_CONCAT(tmperr_, LINE); \
	__VA_ARGS__ % reinterpret_cast<maxon::ThreadReferencedError&>(MAXON_CONCAT(tmperr_, LINE)); \
	MAXON_WARNING_PUSH \
	MAXON_WARNING_DISABLE_VARIABLE_SHADOWING \
	if (maxon::ErrType err = ((void) &err, reinterpret_cast<maxon::ThreadReferencedError&>(MAXON_CONCAT(tmperr_, LINE)))) \
	MAXON_WARNING_POP


#define PRIVATE_MAXON_iferr(...)		PRIVATE_MAXON_iferr_(ErrorPtr, __COUNTER__, __VA_ARGS__)
#define PRIVATE_MAXON_ifnoerr(...)	PRIVATE_MAXON_iferr_(NoErrorPtr, __COUNTER__, __VA_ARGS__)

//----------------------------------------------------------------------------------------
/// The @c iferr macro can be used to simplify error handling.
/// It is a special @c if which declares an error variable named @c err for the if/else scope.
/// This variable is set to the error (if any) of the <tt>iferr</tt>-expression, and the
/// <tt>if</tt>-branch is executed if there is an error.
/// Expressions of several types are supported:
///  - <tt>Result<T></tt> expressions hold a result value and an error. You can use @c iferr
///    just to check their error value, but you can also assign the result value to a variable
///    and even declare the variable in the expression (it will be declared in the outer scope, not just in the @c if scope):
///    @code
///    Result<Int> Func();
///
///    iferr (Func())
///      return err;
///
///    Int res;
///    iferr (res = Func())
///      return err;
///
///    iferr (Int res = Func())
///      return err;
///    // res available here
///    @endcode
///  - Pointer-valued expressions set the @c err variable to an OutOfMemoryError if the expression
///    evaluates to @c nullptr. Other than that, you can use @c iferr as in the previous case.
///    E.g., you can write
///    @code
///    iferr (AutoMem<Char> data = NewMem(Char, size))
///      return err;
///    // data available here
///    @endcode
///  - If the expression returns a reference class, it behaves in a similar way as for a pointer-valued
///    expression.
///  - Finally, if the expression returns a ResultMem, the @c err variable is set to an OutOfMemoryError if
///    the ResultMem is @c false. This only works for the simple case (with no additional result assignment):
///    @code
///    iferr (array.Resize(size))
///      return err;
///    @endcode
///
/// For nested @c iferr statements, you have to use @c iferr etc., otherwise you will get
/// a conflict because two variables of the same name @c err are declared.
///
/// @param[in] ...								Expression which shall be checked for an error condition.
/// @see @ref error_handling_iferr
//----------------------------------------------------------------------------------------
#define iferr(...) PRIVATE_MAXON_iferr(__VA_ARGS__)

//----------------------------------------------------------------------------------------
/// The opposite of @c iferr.
//----------------------------------------------------------------------------------------
#define ifnoerr(...) PRIVATE_MAXON_ifnoerr(__VA_ARGS__)


//----------------------------------------------------------------------------------------
/// This macro simplifies the registration of an error implementation together with its
/// published error object. It assumes that, for an error XyzError, you have a
/// component implementation class XyzErrorImpl.
///
/// Example:
/// @code
/// class ErrnoErrorImpl : public Component<ErrnoErrorImpl, ErrnoErrorInterface>
/// {
///   MAXON_COMPONENT();
///   ...
/// };
/// MAXON_ERROR_REGISTER(ErrnoError, ErrorObjectClass, "net.maxon.error.ErrnoError");
/// @endcode
/// @param[in] error							Name of the error reference class such as OutOfMemoryError. The component implementation
/// 															class has to use this name with an @c Impl suffix.
/// @param[in] baseclass					An expression returning the base object class (e.g., <tt>ErrorObjectClass</tt>).
/// 															This should be an implementation of the base interfaces of the error interface.
/// @param[in] id									The unique identifier for the error class and its component.
//----------------------------------------------------------------------------------------
#define MAXON_ERROR_REGISTERX(error, baseclass, id) \
	MAXON_COMPONENT_ONLY_REGISTER(error##Impl, id) \
	{ \
		return cls.AddComponents(baseclass); \
	} \
	MAXON_DECLARATION_REGISTER(error##Object) \
	{ \
		return error##Impl::GetClass().Create(); \
	}

//----------------------------------------------------------------------------------------
/// This macro simplifies the implementation and registration of an error interface and its
/// published error object. You can use this for error interfaces which don't introduce
/// additional methods, and if the implementation shall not override any of the inherited implementations.
///
/// Example:
/// @code
/// MAXON_ERROR_IMPLEMENT_AND_REGISTER(OutOfMemoryError, ErrorObjectClass);
/// @endcode
/// @param[in] error							Name of the error reference class such as OutOfMemoryError.
/// @param[in] baseclass					An expression returning the base object class (e.g., <tt>ErrorObjectClass</tt>).
/// 															This should be an implementation of the base interfaces of the error interface.
//----------------------------------------------------------------------------------------
#define MAXON_ERROR_IMPLEMENT_AND_REGISTER(error, baseclass) \
	class error##Impl : public maxon::Component<error##Impl, error##Interface> \
	{ \
		MAXON_COMPONENT(); \
	public: \
		static maxon::Result<void> ConfigureClass(maxon::ClassInterface& cls) \
		{ \
			return cls.AddComponents(baseclass()); \
		} \
	}; \
	MAXON_COMPONENT_OBJECT_REGISTER(error##Impl, error##Object)


//----------------------------------------------------------------------------------------
/// This macro preallocates an error for speed critical cases. The error is returned as a
/// ThreadReferencedError which can be directly returned without any further function calls
/// or overhead (which would happen internally when you'd return an Error object).
///
/// The following example preallocates g_myIllegalArgumentError which is assigned an IllegalArgumentError:
/// @code
/// MAXON_ERROR_PREALLOCATE(g_myIllegalArgumentError, []() { return IllegalArgumentError(MAXON_SOURCE_LOCATION); });
/// @endcode
/// @param[in] errorName					The name of a globally visible ThreadReferencedError variable which is to be preallocated.
/// @param[in] init								A lambda or function which returns a preallocated Error.
//----------------------------------------------------------------------------------------
#define MAXON_ERROR_PREALLOCATE(errorName, init) \
	maxon::ThreadReferencedError errorName; \
	static maxon::Error errorName##Storage; \
	MAXON_INITIALIZATION( \
		[]() -> maxon::Result<void> \
		{ \
			errorName##Storage = init(); \
			if (errorName##Storage == nullptr) \
				return maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION); \
			errorName = maxon::ThreadReferencedError::CreateFromReferencedError(&errorName##Storage); \
			errorName##Storage.PrivateSetPreallocation(errorName); \
			return maxon::OK; \
		}, \
		[]() \
		{ \
			errorName##Storage = nullptr; \
		})


#define PRIVATE_MAXON_CHECKERROR0(type, condition, msg) type ": Condition " #condition " not fulfilled. "_s
#define PRIVATE_MAXON_CHECKERROR1(type, condition, msg) maxon::String(FormatString msg)

#define PRIVATE_MAXON_CHECKERROR_C(type, condition, msgPopulated, msg) MAXON_EXPAND(PRIVATE_MAXON_CHECKERROR##msgPopulated(type, condition, msg))
#define PRIVATE_MAXON_CHECKERROR_B(type, condition, msgPopulated, msg) PRIVATE_MAXON_CHECKERROR_C(type, condition, msgPopulated, msg)
#define PRIVATE_MAXON_CHECKERROR_A(type, condition, msgPopulated, ...) MAXON_SOURCE_LOCATION, PRIVATE_MAXON_CHECKERROR_B(type, condition, msgPopulated, (type ": " __VA_ARGS__))

//----------------------------------------------------------------------------------------
/// This macro checks the specified condition, and if this evaluates to false, an
/// IllegalArgumentError is returned from the current function. The condition will be part
/// of the error message (taken over verbatim). The macro can only be used in a function
/// which returns a Result<T>.
///
/// Optionally, you can specify a message which will be used instead of the verbatim condition.
/// The message may use formatting like @ref FormatString.
///
/// Examples:
/// @code
/// // on error, the message is "Illegal argument: Condition (UInt) index < (UInt) _count not fulfilled."
/// CheckArgument((UInt) index < (UInt) _count);
///
/// // on error, the message is "Illegal argument: Framerate too low."
/// CheckArgument(frameRate >= 1.0, "Framerate too low.");
///
/// // on error, the message is "Illegal argument: Name my/file.txt contains forward slash."
/// CheckArgument(!name.FindLast('/', nullptr), "Name @ contains forward slash.", name);
/// @endcode
/// @param[in] condition					The condition to evaluate. If it evaluates to false, an IllegalArgumentError will be returned.
/// @param[in] ...								Optional message and parameters, will be formatted by @ref FormatString.
/// @see CheckState
/// @see CheckAssert
/// @see CheckArgumentDebugStop
//----------------------------------------------------------------------------------------
#define CheckArgument(condition, ...) do { if (MAXON_UNLIKELY(!(condition))) iferr_throw(maxon::IllegalArgumentError(PRIVATE_MAXON_CHECKERROR_A("Illegal argument", condition, MAXON_VA_ARGS_POPULATED(__VA_ARGS__), __VA_ARGS__))); } while (false)

//----------------------------------------------------------------------------------------
/// Like CheckArgument, but an additional DebugStop is executed on error.
//----------------------------------------------------------------------------------------
#define CheckArgumentDebugStop(condition, ...) do { if (MAXON_UNLIKELY(!(condition))) iferr_throw(maxon::IllegalArgumentError(PRIVATE_MAXON_CHECKERROR_A("Illegal argument", condition, MAXON_VA_ARGS_POPULATED(__VA_ARGS__), __VA_ARGS__)).DbgStop()); } while (false)


//----------------------------------------------------------------------------------------
/// This macro checks the specified condition, and if this evaluates to false, an
/// IllegalStateError is returned from the current function. The condition will be part
/// of the error message (taken over verbatim). The macro can only be used in a function
/// which returns a Result<T>.
///
/// Optionally, you can specify a message which will be used instead of the verbatim condition.
/// The message may use formatting like @ref FormatString.
///
/// For examples, see #CheckArgument.
/// @param[in] condition					The condition to evaluate. If it evaluates to false, an IllegalStateError will be returned.
/// @param[in] ...								Optional message and parameters, will be formatted by @ref FormatString.
/// @see CheckArgument
/// @see CheckAssert
/// @see CheckStateDebugStop
//----------------------------------------------------------------------------------------
#define CheckState(condition, ...) do { if (MAXON_UNLIKELY(!(condition))) iferr_throw(maxon::IllegalStateError(PRIVATE_MAXON_CHECKERROR_A("Illegal state", condition, MAXON_VA_ARGS_POPULATED(__VA_ARGS__), __VA_ARGS__))); } while (false)

//----------------------------------------------------------------------------------------
/// Like CheckState, but an additional DebugStop is executed on error.
//----------------------------------------------------------------------------------------
#define CheckStateDebugStop(condition, ...) do { if (MAXON_UNLIKELY(!(condition))) iferr_throw(maxon::IllegalStateError(PRIVATE_MAXON_CHECKERROR_A("Illegal state", condition, MAXON_VA_ARGS_POPULATED(__VA_ARGS__), __VA_ARGS__)).DbgStop()); } while (false)

//----------------------------------------------------------------------------------------
/// This macro checks the specified condition, and if this evaluates to false, an
/// UnexpectedError is returned from the current function. The condition will be part
/// of the error message (taken over verbatim). The macro can only be used in a function
/// which returns a Result<T>.
///
/// Optionally, you can specify a message which will be used instead of the verbatim condition.
/// The message may use formatting like @ref FormatString.
///
/// For examples, see #CheckArgument.
/// @param[in] condition					The condition to evaluate. If it evaluates to false, an UnexpectedError will be returned.
/// @param[in] ...								Optional message and parameters, will be formatted by @ref FormatString.
/// @see CheckArgument
/// @see CheckState
//----------------------------------------------------------------------------------------
#define CheckAssert(condition, ...) do { if (MAXON_UNLIKELY(!(condition))) iferr_throw(maxon::UnexpectedError(PRIVATE_MAXON_CHECKERROR_A("Assertion failed", condition, MAXON_VA_ARGS_POPULATED(__VA_ARGS__), __VA_ARGS__)).DbgStop()); } while (false)

//----------------------------------------------------------------------------------------
/// Checks if an error is of type ERRORTYPE. If multiple errors have been returned (AggregatedError)
/// this method will return true if one of them is of type ERRORTYPE.
/// @tparam ERRORTYPE							The type of error the caller is interested in.
/// @param[in] err								The returned error to check.
/// @return												True if one of the returned errors is of type ERRORTYPE, false otherwise.
//----------------------------------------------------------------------------------------
template<typename ERRORTYPE> inline Bool IsErrorOfType(const Error& err)
{
	if (err.IsInstanceOf<ERRORTYPE>())
	{
		return true;
	}
	else if (err.IsInstanceOf<AggregatedError>())
	{
		AggregatedError agg = Cast<AggregatedError>(err);
		Bool isError = false;

		for (auto e : agg)
		{
			if (!IsErrorOfType<ERRORTYPE>(e))
				return false;
			isError = true;
		}
		return isError;
	}

	return false;
}
/// @}

} // namespace maxon

#endif // ERRORBASE_H__
