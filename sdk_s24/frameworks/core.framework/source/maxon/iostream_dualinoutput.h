#ifndef IOSTREAM_DUALINOUTPUT_H__
#define IOSTREAM_DUALINOUTPUT_H__


#include "maxon/iostreams.h"

namespace maxon
{

/// @addtogroup IO
/// @{

//----------------------------------------------------------------------------------------
/// Advanced Interface of InOutputStreamInterface which allows to create an InOutputStreamInterface where the read and write has two different stream handles.
/// One stream is for reading, the other for writing data.<br>
/// - GetError() returns the error code of the input stream and if this has no error, of the output stream.<br>
/// - SetError() sets the error code in both streams.<br>
/// - GetPosition(), GetLength(), SeekSupported(), Seek() are not allowed to call because it's not defined which stream is meant. Use GetInputStream().function() instead.<br>
/// - Close() closes both streams.<br>
//----------------------------------------------------------------------------------------
class IoDualInOutputStreamInterface : MAXON_INTERFACE_BASES(InOutputStreamInterface)
{
	MAXON_INTERFACE(IoDualInOutputStreamInterface, MAXON_REFERENCE_NORMAL, "net.maxon.interface.iodualinoutputstream");

public:
	//----------------------------------------------------------------------------------------
	/// Sets the handle for the input stream used for reading.
	/// @param[in] inputStream				Reference to the stream used for read.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> SetInputStream(const InputStreamRef& inputStream);

	//----------------------------------------------------------------------------------------
	/// Sets the handle for the output stream used for writing.
	/// @param[in] outputStream				Reference to the stream used for write.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> SetOutputStream(const OutputStreamRef& outputStream);

	//----------------------------------------------------------------------------------------
	/// Returns the handle used for reading.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD InputStreamRef GetInputStream() const;

	//----------------------------------------------------------------------------------------
	/// Returns the handle used for writing.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD OutputStreamRef GetOutputStream() const;
};


#include "iostream_dualinoutput1.hxx"

MAXON_DECLARATION(Class<IoDualInOutputStreamRef>, InOutputStreamDualClass, "net.maxon.class.inoutputstreamdual");

#include "iostream_dualinoutput2.hxx"

/// @}

} // namespace maxon


#endif // IOSTREAM_DUALINOUTPUT_H__
