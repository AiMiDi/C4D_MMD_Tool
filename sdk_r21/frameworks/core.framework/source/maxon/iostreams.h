#ifndef IOSTREAMS_H__
#define IOSTREAMS_H__

#include "maxon/string.h"
#include "maxon/datadictionaryobject.h"
#include "maxon/factory.h"

namespace maxon
{

/// @addtogroup IO
/// @{

class BaseStreamRef;
class InputStreamRef;
class OutputStreamRef;
class NetworkIpAddrPort;
class WrappedInputStreamRef;
template <typename STREAM> class UrlOrStream;
using UrlOrInputStream = UrlOrStream<InputStreamRef>;
using UrlOrOutputStream = UrlOrStream<OutputStreamRef>;

//----------------------------------------------------------------------------------------
/// Error of the category I/O.
//----------------------------------------------------------------------------------------
class IoErrorInterface : MAXON_INTERFACE_BASES(ErrorInterface)
{
	MAXON_INTERFACE(IoErrorInterface, MAXON_REFERENCE_COPY_ON_WRITE, "net.maxon.interface.ioerror");
public:
	MAXON_ADD_TO_COPY_ON_WRITE_REFERENCE_CLASS(
protected:
	//----------------------------------------------------------------------------------------
	/// Constructs a new @CLASS for the given source location. This function succeeds even in an
	/// out-of-memory case: Then it uses a pre-allocated @CLASS, but the location can't be set.
	/// @param[in] allocLocation			Location (file and line) of the error creation.
	//----------------------------------------------------------------------------------------
	void Create(MAXON_SOURCE_LOCATION_DECLARATION)
	{
		*static_cast<typename S::DirectlyReferencedType::Hxx1::ReferenceClass*>(this) = S::DirectlyReferencedType::Hxx1::ErrObj::GetInstance()();
		// If MakeWritable(false) fails the reference won't be nulled (just e).
		typename S::DirectlyReferencedType::Ptr e = this->MakeWritable(false).GetPointer();
		e.SetLocation(MAXON_SOURCE_LOCATION_FORWARD);
	}

	//----------------------------------------------------------------------------------------
	/// Constructs a new @CLASS for the given parameters. This function succeeds even in an
	/// out-of-memory case: Then it uses a pre-allocated @CLASS, but the parameters can't be set.
	/// @param[in] allocLocation			Location (file and line) of the error creation.
	/// @param[in] url								The Url at which the error happened.
	/// @param[in] msg								Error message.
	/// @param[in] cause							Another error which caused the new error.
	//----------------------------------------------------------------------------------------
	void Create(MAXON_SOURCE_LOCATION_DECLARATION, const Url& url, const String& msg, const Error& cause = GetPtrSizedZeroRef<Error>())
	{
		*static_cast<typename S::DirectlyReferencedType::Hxx1::ReferenceClass*>(this) = S::DirectlyReferencedType::Hxx1::ErrObj::GetInstance()();
		typename S::DirectlyReferencedType::Ptr e = this->MakeWritable(false).GetPointer();
		e.SetLocation(MAXON_SOURCE_LOCATION_FORWARD);
		e.SetUrl(url);
		e.SetMessage(msg);
		e.SetCause(cause);
	}

	//----------------------------------------------------------------------------------------
	/// Constructs a new @CLASS for the given parameters. This function succeeds even in an
	/// out-of-memory case: Then it uses a pre-allocated @CLASS, but the parameters can't be set.
	/// @param[in] allocLocation			Location (file and line) of the error creation.
	/// @param[in] url								The Url at which the error happened.
	/// @param[in] cause							Another error which caused the new error.
	//----------------------------------------------------------------------------------------
	void Create(MAXON_SOURCE_LOCATION_DECLARATION, const Url& url, const Error& cause)
	{
		*static_cast<typename S::DirectlyReferencedType::Hxx1::ReferenceClass*>(this) = S::DirectlyReferencedType::Hxx1::ErrObj::GetInstance()();
		typename S::DirectlyReferencedType::Ptr e = this->MakeWritable(false).GetPointer();
		e.SetLocation(MAXON_SOURCE_LOCATION_FORWARD);
		e.SetUrl(url);
		e.SetCause(cause);
	}
	);

	//----------------------------------------------------------------------------------------
	/// SetUrl allows to set the corresponding url.
	/// @param[in] url								Url to set.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void SetUrl(const Url& url);

	//----------------------------------------------------------------------------------------
	/// Returns the corresponding url.
	/// @return												The url stored in the Error.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD const Url& GetUrl() const;
};

//----------------------------------------------------------------------------------------
/// An FileFormatError indicates a file format structural error.
/// It can be returned if reading a file format detects unexpected tokens or identifiers.
/// It indicates that the url that was read is corrupted.
//----------------------------------------------------------------------------------------
class FileFormatErrorInterface : MAXON_INTERFACE_BASES(IoErrorInterface)
{
	MAXON_INTERFACE(FileFormatErrorInterface, MAXON_REFERENCE_COPY_ON_WRITE, "net.maxon.interface.fileformaterror");
};


//----------------------------------------------------------------------------------------
/// Parameters for BaseStream::SetData, BaseStream::GetData.
//----------------------------------------------------------------------------------------
namespace STREAMFLAGS
{
	MAXON_ATTRIBUTE(NetworkIpAddrPort, HTTP_REMOTEADDRESS, "net.maxon.stream.http_remoteaddress");	///< [readonly] Returns the remote server address for the current http stream.
	MAXON_ATTRIBUTE(DataDictionary, HTTP_HEADER, "net.maxon.stream.http_header");		///< [readonly] Returns the complete header information from the http request.
}

//----------------------------------------------------------------------------------------
/// A UnknownFileSizeError indicates that the file size is unknown (not available). This might
/// happen for example when using a pipe.
//----------------------------------------------------------------------------------------
class UnknownFileSizeErrorInterface : MAXON_INTERFACE_BASES(ErrorInterface)
{
	MAXON_INTERFACE(UnknownFileSizeErrorInterface, MAXON_REFERENCE_COPY_ON_WRITE, "net.maxon.interface.unknownfilesizeerror");
};

//----------------------------------------------------------------------------------------
/// Interface is the base interface for all stream interfaces.
/// It contains the general functions to work with streams (e.g. error handling).
//----------------------------------------------------------------------------------------
class BaseStreamInterface : MAXON_INTERFACE_BASES(DataDictionaryObjectInterface)
{
	MAXON_INTERFACE(BaseStreamInterface, MAXON_REFERENCE_NORMAL, "net.maxon.interface.basestream");

public:
	//----------------------------------------------------------------------------------------
	/// Returns the length of the stream/file. Be aware that some streams cannot return the file size (e.g. http streams with gzip+chunked transfer encoding).
	/// With this example code you can handle both cases correctly. In most cases it's better to not use GetStreamLength() and better use ReadEOS() to read as much as available.
	/// @code
	/// iferr (Int size = stream.GetStreamLength())
	/// {
	///   if (!err.IsInstanceOf<UnknownFileSizeError>())
	///     return err;
	///   ... handle unknown size case ...
	/// }
	/// else
	/// {
	///   ... handle known size case ...
	/// }
	/// @endcode
	/// @return												Returns the length in bytes. UnknownFileSizeError is returned if the size is unknown.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Int64> GetStreamLength() const;

	//----------------------------------------------------------------------------------------
	/// Returns the current stream position. This is the position where the next bytes will be read to or written from.
	/// @return												The current stream position.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Int64> GetPosition() const;

	//----------------------------------------------------------------------------------------
	/// Closes the stream.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Close();

	MAXON_ADD_TO_REFERENCE_CLASS(
	//----------------------------------------------------------------------------------------
	/// Resets this reference to nullptr and closes the stream if this is the last reference to the stream.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	Result<void> ResetMaybeClose()
	{
		Result<void> res = OK;
		if (this->GetPointer())
		{
			if (System::GetReferenceCounter(this->GetPointer()) == 1)
				res = this->Close();
			this->ResetPointer();
		}
		return res;
	}
	);

	//----------------------------------------------------------------------------------------
	/// Returns if the stream supports Seek(). Please note that seeking in stream may effect performance because the caches will be flushed.
	/// @return												True if the output stream supports Seek().
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Bool SeekSupported() const;

	//----------------------------------------------------------------------------------------
	/// Sets the read/write position to this absolute position from the beginning of the stream.
	/// For InputStreamInterface: If you want to Seek() forward Skip() is the preferred method to call from the performance perspective.
	/// @param[in] position						Position to jump to within the stream.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Seek(Int64 position);

	//----------------------------------------------------------------------------------------
	/// The stream may disable buffering when this routine is called (if it supports it).
	/// This method is typically used when the buffering is done from the outside.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void DisableBuffering();
};


//----------------------------------------------------------------------------------------
/// Interface for input streams. It allows to read data from streams.
/// This interface needs to be implemented for each protocol.
//----------------------------------------------------------------------------------------
class InputStreamInterface : MAXON_INTERFACE_BASES(BaseStreamInterface)
{
	MAXON_INTERFACE(InputStreamInterface, MAXON_REFERENCE_NORMAL, "net.maxon.interface.inputstream");

public:
	//----------------------------------------------------------------------------------------
	/// Returns an estimate of the number of bytes that can be read (or skipped over) from
	/// this input stream without blocking by the next invocation of a method for this input stream.
	/// @return												Available number of bytes to read/skip.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Int64> BytesAvailable() const;

	//----------------------------------------------------------------------------------------
	/// Reads all bytes up to len bytes of data from the input stream into an array of bytes.
	/// 'bytes' and the result are of type Int (not Int64) as 'buffer' can never hold more bytes on a 32-bit system.
	/// @param[out] data							Buffer which receives the read bytes.
	/// @return												OK if all bytes could be read.
	//----------------------------------------------------------------------------------------
	MAXON_FUNCTION Result<void> Read(const Block<Byte>& data);

	//----------------------------------------------------------------------------------------
	/// Reads up to len bytes of data from the input stream into an array of bytes.
	/// 'bytes' and the result are of type Int (not Int64) as 'buffer' can never hold more bytes on a 32-bit system.
	/// @param[out] data							Buffer which receives the read bytes.
	/// @return												Number of bytes that has been read. If less bytes read than requested the end of the stream has been reached.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Int> ReadEOS(const Block<Byte>& data);

	//----------------------------------------------------------------------------------------
	/// Skips over and discards n bytes of data from this input stream. If you want to Seek() forward Skip is the preferred method to call from the performance perspective.
	/// @param[in] bytes							Number of bytes to skip from the current position.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Skip(Int64 bytes);

	MAXON_DECLARATION_CLASS(Factory<InputStreamRef(const Block<const Char>&, Bool)>, FromBlock, "net.maxon.inputstreaminterface.fromblock");
};


//----------------------------------------------------------------------------------------
/// Creates an OutputStreamInterface class to write bytes into streams
//----------------------------------------------------------------------------------------
class OutputStreamInterface : MAXON_INTERFACE_BASES(BaseStreamInterface)
{
	MAXON_INTERFACE(OutputStreamInterface, MAXON_REFERENCE_NORMAL, "net.maxon.interface.outputstream");

public:
	//----------------------------------------------------------------------------------------
	/// Write bytes to the stream.
	/// 'bytes' is of type Int (not Int64) as 'buffer' can never hold more bytes on a 32-bit system.
	/// @param[in] data								Data that should be written to the stream.
	/// @return												True if all bytes are written to the stream.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Write(const Block<const Byte>& data);

	//----------------------------------------------------------------------------------------
	/// Flushes the output stream and forces any buffered output bytes to be written.
	/// @return												True is the operation succeeded.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Flush();
};

//----------------------------------------------------------------------------------------
/// Creates an InOutputStreamInterface class to read/write bytes from/into streams.
/// This interface combines both InputStreamInterface and OutputStreamInterface.
//----------------------------------------------------------------------------------------
class InOutputStreamInterface : MAXON_INTERFACE_BASES(InputStreamInterface, OutputStreamInterface)
{
	MAXON_INTERFACE(InOutputStreamInterface, MAXON_REFERENCE_NORMAL, "net.maxon.interface.inoutputstream");

public:
};


// include autogenerated headerfile here
#include "iostreams1.hxx"

MAXON_DECLARATION(Class<IoError>, IoErrorObjectClass, "net.maxon.class.ioerrorobject");

MAXON_DECLARATION(Class<InputStreamRef>, InputStreamBaseClass, "net.maxon.class.inputstreambase");
MAXON_DECLARATION(Class<OutputStreamRef>, OutputStreamBaseClass, "net.maxon.class.outputstreambase");
MAXON_DECLARATION(Class<InOutputStreamRef>, InOutputStreamBaseClass, "net.maxon.class.inoutputstreambase");

MAXON_DECLARATION(Class<InputStreamRef>, InputStreamDecoratorBaseClass, "net.maxon.class.inputstreamdecorator");
MAXON_DECLARATION(Class<OutputStreamRef>, OutputStreamDecoratorBaseClass, "net.maxon.class.outputstreamdecorator");
MAXON_DECLARATION(Class<InOutputStreamRef>, InOutputStreamDecoratorBaseClass, "net.maxon.class.inoutputstreamdecorator");


#include "iostreams2.hxx"

//----------------------------------------------------------------------------------------
/// This function is often useful when getting a file length and need to check if the size is convertable into a memory size.
/// depending on the platform 32 or 64 bit this might fail.
/// @param[in] value							Value to cast to an Int.
/// @return												A valid Int or an error.
/// @code
/// Int64 fileSize = fileStream.GetLength()) iferr_return;
/// Int   memSize  = Int64ToInt(fileSize) iferr_return;
/// if (!arr.Resize(memSize))
/// 	return OutOfMemoryError(MAXON_SOURCE_LOCATION);
/// @endcode
//----------------------------------------------------------------------------------------
inline Result<Int> Int64ToInt(Int64 value)
{
	if ((Int)value == value)
		return (Int)value;
	return IllegalStateError(MAXON_SOURCE_LOCATION, FormatString("int overflow: @", value));
}

/// @}

} // namespace maxon


#endif // IOSTREAMS_H__
