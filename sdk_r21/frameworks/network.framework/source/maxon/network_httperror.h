#ifndef NETWORK_HTTPERROR_H__
#define NETWORK_HTTPERROR_H__


#include "maxon/iostreams.h"


namespace maxon
{


//----------------------------------------------------------------------------------------
/// Return codes for http functions.
//----------------------------------------------------------------------------------------
enum class HTTPCODE
{
	CLOSED						= -1,		///< the connection has been closed.
	FINISHED					= -2,		///< the request has been completed.
	CALL_NEXT_HANDLER	= -3,   ///< the request was not processed by this message handler, continue with the next one.

	OK						= 200,	///< return a http okay.
	POST					= 201,	///< return a http post.

	MOVED					= 301,	///< "301 Moved Permanently". the requested file has been moved. check the header "location" entry to get the new location.

	SYNTAX				= 400,	///< return a http syntax error.
	AUTH					= 401,	///< return a http authentication error.
	ACCESS				= 403,	///< return a http access error.
	NOTFOUND			= 404,	///< return a http file not found error.
	INTERNAL			= 500,	///< return a http internal error.
	UNKNOWN				= 501,	///< return a http unknown error.
} MAXON_ENUM_LIST(HTTPCODE);

//----------------------------------------------------------------------------------------
/// Http Error.
/// This error is returned from functions of the NetworkHttpHandlerInterface.
//----------------------------------------------------------------------------------------
class HttpCodeErrorInterface : MAXON_INTERFACE_BASES(IoErrorInterface)
{
	MAXON_INTERFACE(HttpCodeErrorInterface, MAXON_REFERENCE_COPY_ON_WRITE, "net.maxon.interface.httpcodeerror");
public:
	MAXON_ADD_TO_COPY_ON_WRITE_REFERENCE_CLASS(
protected:
	void Create(MAXON_SOURCE_LOCATION_DECLARATION, HTTPCODE errorCode)
	{
		*static_cast<typename S::DirectlyReferencedType::Hxx1::ReferenceClass*>(this) = S::DirectlyReferencedType::Hxx1::ErrObj::GetInstance()();
		// If MakeWritable(false) fails the reference won't be nulled (just e).
		typename S::DirectlyReferencedType::Ptr e = this->MakeWritable(false).GetPointer();
		e.SetLocation(MAXON_SOURCE_LOCATION_FORWARD);
		e.SetHttpCode(errorCode);
	}
	void Create(MAXON_SOURCE_LOCATION_DECLARATION, HTTPCODE errorCode, const Error& causeError)
	{
		*static_cast<typename S::DirectlyReferencedType::Hxx1::ReferenceClass*>(this) = S::DirectlyReferencedType::Hxx1::ErrObj::GetInstance()();
		typename S::DirectlyReferencedType::Ptr e = this->MakeWritable(false).GetPointer();
		e.SetLocation(MAXON_SOURCE_LOCATION_FORWARD);
		e.SetHttpCode(errorCode);
		e.SetCause(causeError);
	}
	);

	MAXON_FUNCTION HTTPCODE GetHttpCode() const { return (HTTPCODE) reinterpret_cast<const ErrorInterface*>(this)->PrivateGetCode(); }

	MAXON_FUNCTION void SetHttpCode(HTTPCODE errorCode) { reinterpret_cast<ErrorInterface*>(this)->PrivateSetCode((Int)errorCode); }
};



#include "network_httperror1.hxx"

#include "network_httperror2.hxx"


}


#endif // NETWORK_HTTPERROR_H__
