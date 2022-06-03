#ifndef ERRORTYPES_H__
#define ERRORTYPES_H__

#include "maxon/errorbase.h"

namespace maxon
{

/// @addtogroup SYSTEM
/// @{

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
/// An UnresolvedError indicates that an interface or declaration was accessed for which
/// there is no definition.
//----------------------------------------------------------------------------------------
class UnresolvedErrorInterface : MAXON_INTERFACE_BASES(ErrorInterface)
{
	MAXON_INTERFACE(UnresolvedErrorInterface, MAXON_REFERENCE_COPY_ON_WRITE, "net.maxon.interface.unresolvederror");
};

//----------------------------------------------------------------------------------------
/// An UnknownError is returned in places where no specific error was defined.
//----------------------------------------------------------------------------------------
class UnknownErrorInterface : MAXON_INTERFACE_BASES(ErrorInterface)
{
	MAXON_INTERFACE(UnknownErrorInterface, MAXON_REFERENCE_COPY_ON_WRITE, "net.maxon.interface.unknownerror");
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
/// A ShutdownError is returned when errors are being used while the object system is being shut down.
//----------------------------------------------------------------------------------------
class ShutdownErrorInterface : MAXON_INTERFACE_BASES(ErrorInterface)
{
	MAXON_INTERFACE(ShutdownErrorInterface, MAXON_REFERENCE_COPY_ON_WRITE, "net.maxon.interface.shutdownerror");
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

#include "errortypes1.hxx"
#include "errortypes2.hxx"

/// @}

} // namespace maxon

#endif // ERRORTYPES_H__
