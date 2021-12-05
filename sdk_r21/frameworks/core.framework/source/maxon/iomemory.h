#ifndef IOMEMORY_H__
#define IOMEMORY_H__

#include "maxon/url.h"
#include "maxon/iostreams.h"
#include "maxon/ioenums.h"


namespace maxon
{

/// @addtogroup IO
/// @{

class IoMemoryRef;


//----------------------------------------------------------------------------------------
/// Helper class for Url of type maxon::URLSCHEME_MEMORY.
/// It turns memory blocks into InputStreams or OutputStreams.
/// This way a memory block can be handled like a real file. The following example shows how to write into a memory file.
/// @code
/// IoMemoryRef mfh = IoMemoryRef::Create() iferr_return;
/// Url writemem = mfh.GetUrl();
/// OutputStreamRef outmem = writemem.OpenOutputStream() iferr_return;
/// outmem.Write("ABCDE", 5);
/// outmem.Write("FGHIJ", 5);
/// outmem.Close();
///
/// for (Int i = 0; i < mfh.GetSize(); i++)
/// {
/// 	OutputWithFlags(OUTPUT::DIAGNOSTIC | OUTPUT::NOLINEBREAK, "@{c}", mfh[i]);
/// }
/// @endcode
/// @code
/// IoMemoryRef mem = IoMemoryRef::Create() iferr_return;
/// Char*	buffer = NewMem(Char, size) iferr_return;
/// mem.PrepareReadBuffer(ToBlock(buffer, size),
/// 	[](const Char*& buffer)
/// 	{
/// 		DeleteMem(buffer);
/// 	}) iferr_return;
/// @endcode
//----------------------------------------------------------------------------------------
class IoMemoryInterface
{
	MAXON_INTERFACE_NONVIRTUAL(IoMemoryInterface, MAXON_REFERENCE_NORMAL, "net.maxon.interface.iomemory");

public:
	//----------------------------------------------------------------------------------------
	/// Allocators for common use.
	/// @param[in] allocLocation			Source location.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD IoMemoryInterface* Alloc(MAXON_SOURCE_LOCATION_DECLARATION);

	static MAXON_METHOD IoMemoryInterface* Alloc(MAXON_SOURCE_LOCATION_DECLARATION, const IoMemoryInterface& src);

	//----------------------------------------------------------------------------------------
	/// Argument type of PrepareReadBuffer().
	//----------------------------------------------------------------------------------------
	using FreeBufferCallback = Delegate<void(const Char*& buffer)>;

	//----------------------------------------------------------------------------------------
	/// Prepares a given memory block for reading. The ownership of the memory can be transfered to the object. The memory will be freed by calling DeleteMem().
	/// @param[in] buffer							Block with the available data to read from.
	/// @param[in] freeBufferCallback	If a callback/lambda is given the memory should be owned by the object and will be freed by calling the callback. Within the callback the memory should be freed and the pointer must be set to nullptr!
	/// 															If "nullptr" the memory needs to be freed by yourself and needs to be kept until this class is not used anymore.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> PrepareReadBuffer(const Block<const Char>& buffer, const FreeBufferCallback& freeBufferCallback);

	//----------------------------------------------------------------------------------------
	/// Resets the class and preallocate a given size of bytes. In read mode the memory can e.g. be filled with WriteBytes. Write mode only needs size 0 as the data grows dynamically.
	/// @param[in] size								Requested size of bytes in the buffer. This memory can be accessed via operator[] or ReadBytes/WriteBytes.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Reset(Int size);

	//----------------------------------------------------------------------------------------
	/// Accesses operator to the buffer.
	/// @param[in] idx								Index of the data to read.
	/// @return												Value of the position in the buffer.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD const Char& operator[](Int idx);

	//----------------------------------------------------------------------------------------
	/// Gets the current buffer size.
	/// @return												Size of the internal buffer.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Int GetSize() const;

	//----------------------------------------------------------------------------------------
	/// Returns whether the object is writable (true) or not (false)
	/// @return												The current mode.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Bool IsWritable() const;

	//----------------------------------------------------------------------------------------
	/// Creates an Url for this IoMemoryRef class. This name can be used to call InputStreamRef and OutputStreamRef functions with memory files.
	/// The Url can be passed to any function that accepts Urls for reading/writing files. E.g. reading/writing images from a memory block etc.
	/// InOutputStreamRef is not supported.
	/// @return												Url for further operations.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Url> GetUrl() const;

	//----------------------------------------------------------------------------------------
	/// Copies the classes buffer from position to destData with the given length.
	/// @param[in] position						Start copying memory from this offset. The position is the offset in the classes buffer, not the destination buffer.
	/// @param[in] data								Destination buffer.
	/// @return												Number of bytes copied.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> ReadBytes(Int position, const Block<Byte>& data) const;

	//----------------------------------------------------------------------------------------
	/// Copies the classes buffer from position to destData with the given length.
	/// @param[in] position						Start copying memory from this offset. The position is the offset in the classes buffer, not the destination buffer.
	/// @param[in] data								Destination buffer.
	/// @return												Number of bytes copied.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Int> ReadBytesEOS(Int position, const Block<Byte>& data) const;

	//----------------------------------------------------------------------------------------
	/// Writes the given sourceData at position in the classes buffer with the given length.
	/// @param[in] position						Start copying memory to this offset. The position is the offset in the classes buffer, not the source data buffer.
	/// @param[in] data								Source data buffer.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> WriteBytes(Int position, const Block<const Byte>& data);

	MAXON_METHOD Result<InputStreamRef> OpenInputStream(OPENSTREAMFLAGS flags) const;

	MAXON_METHOD Result<OutputStreamRef> OpenOutputStream(OPENSTREAMFLAGS flags);

	MAXON_METHOD Result<InOutputStreamRef> OpenInOutputStream(OPENSTREAMFLAGS flags);
};

// include autogenerated headerfile here
#include "iomemory1.hxx"

// include autogenerated headerfile here
#include "iomemory2.hxx"

/// @}

} // namespace maxon


#endif // IOMEMORY_H__
