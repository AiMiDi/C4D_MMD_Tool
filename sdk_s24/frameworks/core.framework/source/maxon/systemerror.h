#ifndef SYSTEMERROR_H__
#define SYSTEMERROR_H__

#include "maxon/error.h"

#if defined(MAXON_TARGET_MACOS) || defined(MAXON_TARGET_IOS)
	#include <CoreFoundation/CFError.h>

	#ifdef __OBJC__
		@class NSError;
	#else
		struct NSError;
	#endif
#else
	struct NSError;
	struct CFError;
	using CFErrorRef = CFError*;	
#endif

namespace maxon
{

/// @addtogroup SYSTEM
/// @{

//----------------------------------------------------------------------------------------
/// System dependent error (Win only).
/// This error is returned if the error code contains the value of GetLastError() at the point when the error occured.
/// The GetMessage functions retrieves the error text from the windows system using FormatMessage.
//----------------------------------------------------------------------------------------
class SystemErrorInterface : MAXON_INTERFACE_BASES(ErrorInterface)
{
	MAXON_INTERFACE(SystemErrorInterface, MAXON_REFERENCE_COPY_ON_WRITE, "net.maxon.interface.systemerror");
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
	/// Returns the system error code stored in this error.
	//----------------------------------------------------------------------------------------
	MAXON_FUNCTION Int GetErrorCode() const { return reinterpret_cast<const ErrorInterface*>(this)->PrivateGetCode(); }

	//----------------------------------------------------------------------------------------
	/// Sets the system error code. This error must be returned from the Windows GetLastError().
	/// The error can output the human readable string of the Windows GetLastError() error.
	/// @param[in] errorCode					Error code of the system variable.
	//----------------------------------------------------------------------------------------
	MAXON_FUNCTION void SetErrorCode(Int errorCode) { return reinterpret_cast<ErrorInterface*>(this)->PrivateSetCode(errorCode); }
};

//----------------------------------------------------------------------------------------
/// System dependent error (macOS and iOS only).
/// This error is returned if the OS returned an NSError.
//----------------------------------------------------------------------------------------
class NSSystemErrorInterface : MAXON_INTERFACE_BASES(ErrorInterface)
{
	MAXON_INTERFACE(NSSystemErrorInterface, MAXON_REFERENCE_COPY_ON_WRITE, "net.maxon.interface.nsystemerror");

public:
	MAXON_ADD_TO_COPY_ON_WRITE_REFERENCE_CLASS(
protected:
	void Create(MAXON_SOURCE_LOCATION_DECLARATION, NSError* osError)
	{
		*static_cast<typename S::DirectlyReferencedType::Hxx1::ReferenceClass*>(this) = S::DirectlyReferencedType::Hxx1::ErrObj::GetInstance()();
		// If MakeWritable(false) fails the reference won't be nulled (just e).
		typename S::DirectlyReferencedType::Ptr e = this->MakeWritable(false).GetPointer();
		e.SetLocation(MAXON_SOURCE_LOCATION_FORWARD);
		e.SetNSError(osError);
	}

	void Create(MAXON_SOURCE_LOCATION_DECLARATION, NSError* osError, const String& message)
	{
		*static_cast<typename S::DirectlyReferencedType::Hxx1::ReferenceClass*>(this) = S::DirectlyReferencedType::Hxx1::ErrObj::GetInstance()();
		// If MakeWritable(false) fails the reference won't be nulled (just e).
		typename S::DirectlyReferencedType::Ptr e = this->MakeWritable(false).GetPointer();
		e.SetLocation(MAXON_SOURCE_LOCATION_FORWARD);
		e.SetNSError(osError);
		e.SetMessage(message);
	}

	void Create(MAXON_SOURCE_LOCATION_DECLARATION, CFErrorRef osError)
	{
		*static_cast<typename S::DirectlyReferencedType::Hxx1::ReferenceClass*>(this) = S::DirectlyReferencedType::Hxx1::ErrObj::GetInstance()();
		// If MakeWritable(false) fails the reference won't be nulled (just e).
		typename S::DirectlyReferencedType::Ptr e = this->MakeWritable(false).GetPointer();
		e.SetLocation(MAXON_SOURCE_LOCATION_FORWARD);
		e.SetNSError((NSError*) osError);
	}

	void Create(MAXON_SOURCE_LOCATION_DECLARATION, CFErrorRef osError, const String& message)
	{
		*static_cast<typename S::DirectlyReferencedType::Hxx1::ReferenceClass*>(this) = S::DirectlyReferencedType::Hxx1::ErrObj::GetInstance()();
		// If MakeWritable(false) fails the reference won't be nulled (just e).
		typename S::DirectlyReferencedType::Ptr e = this->MakeWritable(false).GetPointer();
		e.SetLocation(MAXON_SOURCE_LOCATION_FORWARD);
		e.SetNSError((NSError*) osError);
		e.SetMessage(message);
	}
	);

	//----------------------------------------------------------------------------------------
	/// Sets the encapsulated NSError.
	/// @param[in] osError						NSError to set.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void SetNSError(NSError* osError);

	//----------------------------------------------------------------------------------------
	/// Returns the encapsulated NSError.
	/// @return												NSError pointer.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD NSError* GetNSError() const;
};

#include "systemerror1.hxx"
#include "systemerror2.hxx"

/// @}

} // namespace maxon

#endif // SYSTEMERROR_H__
