/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef C4D_FILE_H__
#define C4D_FILE_H__

#include "maxon/url.h"

#include "ge_math.h"

#ifdef __API_INTERN__
	#include "ge_file.h"
#else

#include "c4d_memory.h"
#include "c4d_string.h"

namespace maxon
{
class String;
class Url;
class FormatStatement;
}

#ifdef CINEWARE_NAMESPACE_ENABLE
	CINEWARE_NAMESPACE_BEGIN
#endif

class Filename;
class HyperFile;
class BaseContainer;
class BaseDocument;
class BaseBitmap;
class BaseChannel;

//----------------------------------------------------------------------------------------
/// Used with Filename::SetMemoryWriteMode() to make a BaseFile write to a memory buffer instead of a file.
/// @addAllocFreeAutoAllocNote
//----------------------------------------------------------------------------------------
class MemoryFileStruct
{
private:
	MemoryFileStruct();
	~MemoryFileStruct();

public:
	/// @name Alloc/Free
	/// @{

	//----------------------------------------------------------------------------------------
	/// @allocatesA{memory file}
	/// @return												@allocReturn{memory file}
	//----------------------------------------------------------------------------------------
	static MemoryFileStruct* Alloc();

	//----------------------------------------------------------------------------------------
	/// @destructsAlloc{memory files}
	/// @param[in,out] mfs						@theToDestruct{memory file}
	//----------------------------------------------------------------------------------------
	static void Free(MemoryFileStruct*& mfs);

	/// @}

	/// @name Get Data
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets the data written to the memory file.
	/// @since R16
	/// @param[out] data							Assigned a pointer to the data written.
	/// @param[out] size							Assigned the size of the data written.
	//----------------------------------------------------------------------------------------
	void GetData(void*& data, Int& size) const;

	//----------------------------------------------------------------------------------------
	/// Gets the data written to the memory file.
	/// @param[out] data							Assigned a pointer to the data written.
	/// @param[out] size							Assigned the size of the data written.
	/// @param[in] release						If @formatConstant{true} the ownership of the memory block is transfered to the caller, who then needs to free the memory with DeleteMem.\n
	/// 															Otherwise the memory block will be freed when the MemoryFileStruct is destructed.
	//----------------------------------------------------------------------------------------
	void GetData(void*& data, Int& size, Bool release = false);

	/// @}
};

//---------------------------------------------------------------------------------------
/// Manages file and path names.
//---------------------------------------------------------------------------------------
class Filename
{
private:
	C4D_RESERVE_PRIVATE_TYPE(maxon::Url, dummy1);

public:
	/// @name Constructors/Destructors
	/// @{

	//---------------------------------------------------------------------------------------
	/// Default constructor.
	//---------------------------------------------------------------------------------------
	Filename(void);

	//----------------------------------------------------------------------------------------
	/// Constructs the filename from a character array.
	/// @param[in] string							The filename character array.
	//----------------------------------------------------------------------------------------
	Filename(const Char* string);

	//----------------------------------------------------------------------------------------
	/// Constructs the filename from a string.
	/// @param[in] string							The filename string.
	//----------------------------------------------------------------------------------------
	Filename(const maxon::String& string);

	//----------------------------------------------------------------------------------------
	/// Copy constructor. Creates a filename from another filename.
	/// @param[in] src								The source filename.
	//----------------------------------------------------------------------------------------
	Filename(const Filename& src);

	//---------------------------------------------------------------------------------------
	/// Default destructor.
	//---------------------------------------------------------------------------------------
	~Filename(void);

	/// @}

	/// @name String Content
	/// @{

	//----------------------------------------------------------------------------------------
	/// Checks if the filename has been set.
	/// @return												@trueIfOtherwiseFalse{filename was set}
	//----------------------------------------------------------------------------------------
	Bool IsPopulated() const;

	//----------------------------------------------------------------------------------------
	/// Gets the String of the filename.
	/// @return												The string with the full filename.
	//----------------------------------------------------------------------------------------
	String GetString(void) const;

	//----------------------------------------------------------------------------------------
	/// Sets the filename to the passed string.
	/// @param[in] str								The string to use to set the filename.
	//----------------------------------------------------------------------------------------
	void SetString(const maxon::String& str);

	/// @}

	/// @name Directory/File Parts
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets the directory that the file is located.
	/// @return												The directory part for the filename.
	//----------------------------------------------------------------------------------------
	const Filename GetDirectory(void) const;

	//----------------------------------------------------------------------------------------
	/// Sets the directory for the filename. The file part remains unchanged.
	/// @param[in] str								The directory to set for the filename.
	//----------------------------------------------------------------------------------------
	void SetDirectory(const Filename& str);

	//----------------------------------------------------------------------------------------
	/// Gets the file part of the filename only, without the path.
	/// @return												The file part of the filename.
	//----------------------------------------------------------------------------------------
	const Filename GetFile(void) const;

	//----------------------------------------------------------------------------------------
	/// Sets the file part for the filename. The directory part remains unchanged.
	/// @param[in] str								The file part to set for the filename.
	//----------------------------------------------------------------------------------------
	void SetFile(const Filename& str);

	//----------------------------------------------------------------------------------------
	/// Convenience function to directly get the file part string. Identical to GetFile().GetString().
	/// @return												The file part of the filename as a string.
	//----------------------------------------------------------------------------------------
	String GetFileString(void) const;

	/// @}

	/// @name Suffix Part
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets the suffix of the filename.
	/// @note Suffix strings do not contain the dot character @em '.'.
	/// @return												The suffix. Only contains the suffix part without dot (e.g. @em "TIF").
	//----------------------------------------------------------------------------------------
	String GetSuffix(void) const;

	//----------------------------------------------------------------------------------------
	/// Sets the suffix part of the filename.
	/// @note Suffix strings do not contain the dot character @em '.'.
	/// @param[in] str								A string with the suffix for the file. Only contains the suffix part and no dot (e.g. @em "TIF").
	//----------------------------------------------------------------------------------------
	void SetSuffix(const maxon::String& str);

	//---------------------------------------------------------------------------------------
	/// Clears the suffix part of the filename.
	//---------------------------------------------------------------------------------------
	void ClearSuffix(void);

	//---------------------------------------------------------------------------------------
	/// Same as ClearSuffix() only that it also clears suffixes longer than seven characters.
	//---------------------------------------------------------------------------------------
	void ClearSuffixComplete(void);

	//----------------------------------------------------------------------------------------
	/// Checks if the suffix of the filename is the same as its string.
	/// @param[in] str								The suffix to check against.
	/// @return												@trueIfOtherwiseFalse{the suffix was checked successfully}
	//----------------------------------------------------------------------------------------
	Bool CheckSuffix(const maxon::String& str) const;

	/// @}

	/// @name Read/Write Memory
	/// @{

	//----------------------------------------------------------------------------------------
	/// Sets the filename to read from a memory block instead of from a file.
	/// @param[in] adr								The memory to read from. @callerOwnsPointed{memory block}
	/// @param[in] size								The size of memory block starting at @formatParam{adr}, or @em -1 if the buffer is "big enough".
	/// @param[in] transferOwnership	If @formatConstant{true} the ownership of the memory block is transfered to the caller, who then needs to free the memory with DeleteMem().\n
	/// 															Otherwise (@formatConstant{false} by default) the memory block will be freed when the MemoryFileStruct is destructed.
	//----------------------------------------------------------------------------------------
	void SetMemoryReadMode(void* adr, Int size = -1, Bool transferOwnership = false);

	//----------------------------------------------------------------------------------------
	/// Sets the filename to write to a memory block instead of to a file.
	/// @param[in] mfs								The memory file to write to. @callerOwnsPointed{memory file}
	//----------------------------------------------------------------------------------------
	void SetMemoryWriteMode(MemoryFileStruct* mfs);

	/// @}

	/// @name Operators
	/// @{

	//----------------------------------------------------------------------------------------
	/// Assignment operator. Assigns the right-operand filename to the left-operand filename.
	/// @param[in] fname							The right-operand filename.
	/// @return												The left-operand filename.
	//----------------------------------------------------------------------------------------
	const Filename& operator = (const Filename& fname);

	//----------------------------------------------------------------------------------------
	/// Concatenates the two filenames. It will join directories and files parts.
	/// @param[in] fname1							The left-operand filename.
	/// @param[in] fname2							The right-operand filename.
	/// @return												The result of the concatenation of the 2 filenames.
	//----------------------------------------------------------------------------------------
	friend const Filename operator + (const Filename& fname1, const Filename& fname2);

	//----------------------------------------------------------------------------------------
	/// Concatenates the filenames and set the left-hand operand to the result.
	/// @param[in] fname							The right-operand filename.
	/// @return												The left-operand filename.
	//----------------------------------------------------------------------------------------
	const Filename& operator += (const Filename& fname);

	//----------------------------------------------------------------------------------------
	/// Checks if two filenames are equal.
	/// @param[in] fname							The right-operand filename.
	/// @return												@trueIfOtherwiseFalse{filenames are equal}
	//----------------------------------------------------------------------------------------
	Bool operator == (const Filename& fname) const;

	//----------------------------------------------------------------------------------------
	/// Check if two filenames are different.
	/// @param[in] fname							The right-operand filename.
	/// @return												@trueIfOtherwiseFalse{filenames are different}
	//----------------------------------------------------------------------------------------
	Bool operator != (const Filename& fname) const;

	/// @}

	/// @name Operators
	/// @{

	//----------------------------------------------------------------------------------------
	/// Copies the filename to @formatParam{dst}.
	/// @param[out] dst								The destination filename. @callerOwnsPointed{filename}
	//----------------------------------------------------------------------------------------
	void CopyTo(Filename* dst) const;

	//----------------------------------------------------------------------------------------
	/// Checks if the filename is a content browser url.
	/// @return												@trueIfOtherwiseFalse{the filename is a browser url}
	//----------------------------------------------------------------------------------------
	Bool IsBrowserUrl() const;

	//----------------------------------------------------------------------------------------
	/// Opens a file selector dialog.
	/// @b Example: To load a file:
	/// @code
	/// Bool ok = fn.FileSelect(FILESELECTTYPE::ANYTHING, FILESELECT::LOAD, "Load");
	/// @endcode
	/// To save a @em bmp file:
	/// @code
	/// Bool ok = fn.FileSelect(FILESELECTTYPE::IMAGES, FILESELECT::SAVE, "Save", "bmp");
	/// @endcode
	/// @param[in] type								The type of file to show in the file selector: @enumerateEnum{FILESELECTTYPE}
	/// @param[in] flags							The file selector flags: @enumerateEnum{FILESELECT}
	/// @param[in] title							The title for the file selector dialog.
	/// @param[in] force_suffix				Set this to suffix to force a filename suffix when in save mode.
	/// @return												@trueIfOtherwiseFalse{the user selected a file}
	//----------------------------------------------------------------------------------------
	Bool FileSelect(FILESELECTTYPE type, FILESELECT flags, const maxon::String& title, const maxon::String& force_suffix = maxon::String());

	/// @}
};

/// Filename path is relative.
typedef Filename RelativeFilename;

//---------------------------------------------------------------------------------------
/// Represents a file for reading and writing.
/// @addAllocFreeAutoAllocNote
//---------------------------------------------------------------------------------------
class BaseFile
{
private:
	BaseFile();
	~BaseFile();

public:
	/// @name Alloc/Free
	/// @{

	//----------------------------------------------------------------------------------------
	/// @allocatesA{file}
	/// @return												@allocReturn{file}
	//----------------------------------------------------------------------------------------
	static BaseFile* Alloc(void);

	//----------------------------------------------------------------------------------------
	/// @destructsAlloc{files}
	/// @param[in,out] fl							@theToDestruct{file}
	//----------------------------------------------------------------------------------------
	static void Free(BaseFile*& fl);

	/// @}

	/// @name Open/Close
	/// @{

	//----------------------------------------------------------------------------------------
	/// Opens a file.
	/// @note If a plugin has to be cross platform from a PC to a Mac (generally advised) then it must correctly fill in the @formatParam{type} and @formatParam{creator} parameters which are needed on a Mac.
	/// @param[in] name								The name of the file to open.
	/// @param[in] mode								The file access mode: @enumerateEnum{FILEOPEN}
	/// @param[in] error_dialog				Set the type of error reporting that should happen while opening the file: @enumerateEnum{FILEDIALOG}
	/// @param[in] order							The type of byte order in the file: @enumerateEnum{BYTEORDER}
	/// @param[in] type								The type of file, only applies to Mac: @ref MACTYPE_CINEMA.
	/// @param[in] creator						The application that wrote the file, for example 'ttxt' (SimpleText) or 'C4D1' for @C4D, Only relevant to Mac: @ref MACCREATOR_CINEMA.
	/// @return												@trueIfOtherwiseFalse{the file was opened without any problem}
	//----------------------------------------------------------------------------------------
	Bool Open(const Filename& name, FILEOPEN mode = FILEOPEN::READ, FILEDIALOG error_dialog = FILEDIALOG::IGNOREOPEN, BYTEORDER order = BYTEORDER::V_MOTOROLA, Int32 type = MACTYPE_CINEMA, Int32 creator = MACCREATOR_CINEMA);

	//----------------------------------------------------------------------------------------
	/// Closes the file.\n
	/// Automatically called when a BaseFile object is destroyed.
	/// @return												@trueIfOtherwiseFalse{the file was successfully closed}
	//----------------------------------------------------------------------------------------
	Bool Close();

	/// @}

	/// @name Read/Write Bytes
	/// @{

	//----------------------------------------------------------------------------------------
	/// Reads a block of bytes from the file.
	/// @warning Only use this when really needed. Be aware that the byte sequences will not be platform independent.
	/// @param[in] data								The memory buffer to fill with the bytes from the file. @callerOwnsPointed{buffer}
	/// @param[in] len								The number of bytes to read from the file.
	/// @param[in] just_try_it				If @formatConstant{true} and the data retrieved from the file is less than requested, no error will be generated.
	/// @return												The number of bytes read.
	//----------------------------------------------------------------------------------------
	Int ReadBytes(void* data, Int len, Bool just_try_it = false);

	//----------------------------------------------------------------------------------------
	/// Reads a block of bytes from the file.\n
	/// If the end of the file is reached then only the remaining bytes will be read.
	/// @note Same as calling ReadBytes(data, len, true)
	/// @param[out] data							The memory buffer to fill with the bytes from the file. @callerOwnsPointed{buffer}
	/// @param[in] len								The number of bytes to try and read from the file.
	/// @return												The number of bytes read.
	//----------------------------------------------------------------------------------------
	Int TryReadBytes(void* data, Int len);

	//----------------------------------------------------------------------------------------
	/// Writes a block of bytes to the file.
	/// @warning Only use this when really needed. Be aware that the byte sequences will not be platform independent.
	/// @param[in] data								The memory buffer with the data to write to the file. @callerOwnsPointed{buffer}
	/// @param[in] len								The number of bytes to write to the file.
	/// @return												@trueIfOtherwiseFalse{the bytes were successfully written to the file}
	//----------------------------------------------------------------------------------------
	Bool WriteBytes(const void* data, Int len);

	/// @}

	/// @name File Pointer/Information/Error
	/// @{

	//----------------------------------------------------------------------------------------
	/// Sets the file pointer within the file.
	/// @param[in] pos								The position within the file to place the file pointer.
	/// @param[in] mode								Sets how the position relates to the file.
	/// @return												@trueIfOtherwiseFalse{the file pointer position was successfully changed}
	//----------------------------------------------------------------------------------------
	Bool Seek(Int64 pos, FILESEEK mode = FILESEEK::RELATIVE_);

	//----------------------------------------------------------------------------------------
	/// Gets the file pointer.
	/// @return												The position of the file pointer.
	//----------------------------------------------------------------------------------------
	Int64 GetPosition();

	//----------------------------------------------------------------------------------------
	/// Gets the length of the file in bytes.
	/// @return												The byte length of the file.
	//----------------------------------------------------------------------------------------
	Int64 GetLength();

	//----------------------------------------------------------------------------------------
	/// Gets the file location.
	/// @return												The file location: @enumerateEnum{LOCATION}
	//----------------------------------------------------------------------------------------
	LOCATION GetLocation() const;

	//----------------------------------------------------------------------------------------
	/// Gets the last error during read or write.
	/// @return												The last error: @enumerateEnum{FILEERROR}
	//----------------------------------------------------------------------------------------
	FILEERROR GetError() const;

	//----------------------------------------------------------------------------------------
	/// Sets the error manually.
	/// @param[in] error							The error: @enumerateEnum{FILEERROR}
	//----------------------------------------------------------------------------------------
	void SetError(FILEERROR error);

	//----------------------------------------------------------------------------------------
	/// Sets the byte order of the data in the file.
	/// @param[in] order							The byte order: @enumerateEnum{BYTEORDER}
	//----------------------------------------------------------------------------------------
	void SetOrder(BYTEORDER order);

	/// @}

	/// @name Read
	/// @{

	//----------------------------------------------------------------------------------------
	/// Reads a ::Char from the file.
	/// @param[out] v									Assigned the read value. @callerOwnsPointed{::Char}
	/// @return												@trueIfOtherwiseFalse{the value was read successfully}
	//----------------------------------------------------------------------------------------
	Bool ReadChar(Char* v);

	//----------------------------------------------------------------------------------------
	/// Reads a ::UChar from the file.
	/// @param[out] v									Assigned the read value. @callerOwnsPointed{::UChar}
	/// @return												@trueIfOtherwiseFalse{the value was read successfully}
	//----------------------------------------------------------------------------------------
	Bool ReadUChar(UChar* v);

	//----------------------------------------------------------------------------------------
	/// Reads a ::Int16 from the file.
	/// @param[out] v									Assigned the read value. @callerOwnsPointed{::Int16}
	/// @return												@trueIfOtherwiseFalse{the value was read successfully}
	//----------------------------------------------------------------------------------------
	Bool ReadInt16(Int16* v);

	//----------------------------------------------------------------------------------------
	/// Reads a ::UInt16 from the file.
	/// @param[out] v									Assigned the read value. @callerOwnsPointed{::UInt16}
	/// @return												@trueIfOtherwiseFalse{the value was read successfully}
	//----------------------------------------------------------------------------------------
	Bool ReadUInt16(UInt16* v);

	//----------------------------------------------------------------------------------------
	/// Reads a ::Int32 from the file.
	/// @param[out] v									Assigned the read value. @callerOwnsPointed{::Int32}
	/// @return												@trueIfOtherwiseFalse{the value was read successfully}
	//----------------------------------------------------------------------------------------
	Bool ReadInt32(Int32* v);

	//----------------------------------------------------------------------------------------
	/// Reads a ::UInt32 from the file.
	/// @param[out] v									Assigned the read value. @callerOwnsPointed{::UInt32}
	/// @return												@trueIfOtherwiseFalse{the value was read successfully}
	//----------------------------------------------------------------------------------------
	Bool ReadUInt32(UInt32* v);

	//----------------------------------------------------------------------------------------
	/// Reads a ::Float32 from the file.
	/// @param[out] v									Assigned the read value. @callerOwnsPointed{::Float32}
	/// @return												@trueIfOtherwiseFalse{the value was read successfully}
	//----------------------------------------------------------------------------------------
	Bool ReadFloat32(Float32* v);

	//----------------------------------------------------------------------------------------
	/// Reads a ::Float64 from the file.
	/// @param[out] v									Assigned the read value. @callerOwnsPointed{::Float64}
	/// @return												@trueIfOtherwiseFalse{the value was read successfully}
	//----------------------------------------------------------------------------------------
	Bool ReadFloat64(Float64* v);

	//----------------------------------------------------------------------------------------
	/// Reads a ::Int64 from the file.
	/// @param[out] v									Assigned the read value. @callerOwnsPointed{::Int64}
	/// @return												@trueIfOtherwiseFalse{the value was read successfully}
	//----------------------------------------------------------------------------------------
	Bool ReadInt64(Int64* v);

	//----------------------------------------------------------------------------------------
	/// Reads a ::UInt64 from the file.
	/// @param[out] v									Assigned the read value. @callerOwnsPointed{::UInt64}
	/// @return												@trueIfOtherwiseFalse{the value was read successfully}
	//----------------------------------------------------------------------------------------
	Bool ReadUInt64(UInt64* v);

	//----------------------------------------------------------------------------------------
	/// Reads a Filename from the file.
	/// @param[out] v									Assigned the read value. @callerOwnsPointed{Filename}
	/// @return												@trueIfOtherwiseFalse{the value was read successfully}
	//----------------------------------------------------------------------------------------
	Bool ReadFilename(Filename* v);

	//----------------------------------------------------------------------------------------
	/// Reads a ::Bool from the file.
	/// @param[out] v									Assigned the read value. @callerOwnsPointed{::Bool}
	/// @return												@trueIfOtherwiseFalse{the value was read successfully}
	//----------------------------------------------------------------------------------------
	Bool ReadBool(Bool* v);

	//----------------------------------------------------------------------------------------
	/// Reads a String from the file.
	/// @param[out] v									Assigned the read value. @callerOwnsPointed{String}
	/// @return												@trueIfOtherwiseFalse{the value was read successfully}
	//----------------------------------------------------------------------------------------
	Bool ReadString(maxon::String* v);

	//----------------------------------------------------------------------------------------
	/// Reads a Vector32 from the file.
	/// @param[out] v									Assigned the read value. @callerOwnsPointed{Vector32}
	/// @return												@trueIfOtherwiseFalse{the value was read successfully}
	//----------------------------------------------------------------------------------------
	Bool ReadVector32(Vector32* v);

	//----------------------------------------------------------------------------------------
	/// Reads a Vector64 from the file.
	/// @param[out] v									Assigned the read value. @callerOwnsPointed{Vector64}
	/// @return												@trueIfOtherwiseFalse{the value was read successfully}
	//----------------------------------------------------------------------------------------
	Bool ReadVector64(Vector64* v);

	//----------------------------------------------------------------------------------------
	/// Reads a Matrix32 from the file.
	/// @param[out] v									Assigned the read value. @callerOwnsPointed{Matrix32}
	/// @return												@trueIfOtherwiseFalse{the value was read successfully}
	//----------------------------------------------------------------------------------------
	Bool ReadMatrix32(Matrix32* v);

	//----------------------------------------------------------------------------------------
	/// Reads a Matrix64 from the file.
	/// @param[out] v									Assigned the read value. @callerOwnsPointed{Matrix64}
	/// @return												@trueIfOtherwiseFalse{the value was read successfully}
	//----------------------------------------------------------------------------------------
	Bool ReadMatrix64(Matrix64* v);

	/// @}

	/// @name Write
	/// @{

	//----------------------------------------------------------------------------------------
	/// Writes a ::Char to the file.
	/// @param[in] v									The value to write to the file.
	/// @return												@trueIfOtherwiseFalse{the value was written successfully}
	//----------------------------------------------------------------------------------------
	Bool WriteChar(Char v);

	//----------------------------------------------------------------------------------------
	/// Writes a ::UChar to the file.
	/// @param[in] v									The value to write to the file.
	/// @return												@trueIfOtherwiseFalse{the value was written successfully}
	//----------------------------------------------------------------------------------------
	Bool WriteUChar(UChar v);

	//----------------------------------------------------------------------------------------
	/// Writes a ::Int16 to the file.
	/// @param[in] v									The value to write to the file.
	/// @return												@trueIfOtherwiseFalse{the value was written successfully}
	//----------------------------------------------------------------------------------------
	Bool WriteInt16(Int16 v);

	//----------------------------------------------------------------------------------------
	/// Writes a ::UInt16 to the file.
	/// @param[in] v									The value to write to the file.
	/// @return												@trueIfOtherwiseFalse{the value was written successfully}
	//----------------------------------------------------------------------------------------
	Bool WriteUInt16(UInt16 v);

	//----------------------------------------------------------------------------------------
	/// Writes a ::Int32 to the file.
	/// @param[in] v									The value to write to the file.
	/// @return												@trueIfOtherwiseFalse{the value was written successfully}
	//----------------------------------------------------------------------------------------
	Bool WriteInt32(Int32 v);

	//----------------------------------------------------------------------------------------
	/// Writes a ::UInt32 to the file.
	/// @param[in] v									The value to write to the file.
	/// @return												@trueIfOtherwiseFalse{the value was written successfully}
	//----------------------------------------------------------------------------------------
	Bool WriteUInt32(UInt32 v);

	//----------------------------------------------------------------------------------------
	/// Writes a ::Float32 to the file.
	/// @param[in] v									The value to write to the file.
	/// @return												@trueIfOtherwiseFalse{the value was written successfully}
	//----------------------------------------------------------------------------------------
	Bool WriteFloat32(Float32 v);

	//----------------------------------------------------------------------------------------
	/// Writes a ::Float64 to the file.
	/// @param[in] v									The value to write to the file.
	/// @return												@trueIfOtherwiseFalse{the value was written successfully}
	//----------------------------------------------------------------------------------------
	Bool WriteFloat64(Float64 v);

	//----------------------------------------------------------------------------------------
	/// Writes a ::Int64 to the file.
	/// @param[in] v									The value to write to the file.
	/// @return												@trueIfOtherwiseFalse{the value was written successfully}
	//----------------------------------------------------------------------------------------
	Bool WriteInt64(Int64 v);

	//----------------------------------------------------------------------------------------
	/// Writes a ::UInt64 to the file.
	/// @param[in] v									The value to write to the file.
	/// @return												@trueIfOtherwiseFalse{the value was written successfully}
	//----------------------------------------------------------------------------------------
	Bool WriteUInt64(UInt64 v);

	//----------------------------------------------------------------------------------------
	/// Writes a Filename to the file.
	/// @param[in] v									The value to write to the file.
	/// @return												@trueIfOtherwiseFalse{the value was written successfully}
	//----------------------------------------------------------------------------------------
	Bool WriteFilename(const Filename& v);

	//----------------------------------------------------------------------------------------
	/// Writes a ::Bool to the file.
	/// @param[in] v									The value to write to the file.
	/// @return												@trueIfOtherwiseFalse{the value was written successfully}
	//----------------------------------------------------------------------------------------
	Bool WriteBool(Bool v);

	//----------------------------------------------------------------------------------------
	/// Writes a String to the file.
	/// @param[in] v									The value to write to the file.
	/// @return												@trueIfOtherwiseFalse{the value was written successfully}
	//----------------------------------------------------------------------------------------
	Bool WriteString(const maxon::String& v);

	//----------------------------------------------------------------------------------------
	/// Writes a Vector32 to the file.
	/// @param[in] v									The value to write to the file.
	/// @return												@trueIfOtherwiseFalse{the value was written successfully}
	//----------------------------------------------------------------------------------------
	Bool WriteVector32(const Vector32& v);

	//----------------------------------------------------------------------------------------
	/// Writes a Vector64 to the file.
	/// @param[in] v									The value to write to the file.
	/// @return												@trueIfOtherwiseFalse{the value was written successfully}
	//----------------------------------------------------------------------------------------
	Bool WriteVector64(const Vector64& v);

	//----------------------------------------------------------------------------------------
	/// Writes a Matrix32 to the file.
	/// @param[in] v									The value to write to the file.
	/// @return												@trueIfOtherwiseFalse{the value was written successfully}
	//----------------------------------------------------------------------------------------
	Bool WriteMatrix32(const Matrix32& v);

	//----------------------------------------------------------------------------------------
	/// Writes a Matrix64 to the file.
	/// @param[in] v									The value to write to the file.
	/// @return												@trueIfOtherwiseFalse{the value was written successfully}
	//----------------------------------------------------------------------------------------
	Bool WriteMatrix64(const Matrix64& v);

	/// @}
};

//----------------------------------------------------------------------------------------
/// File operations for AES encrypted files.
/// @addAllocFreeAutoAllocNote
//----------------------------------------------------------------------------------------
class AESFile : public BaseFile
{
private:
	AESFile();
	~AESFile();

public:
	/// @name Alloc/Free
	/// @{

	//----------------------------------------------------------------------------------------
	/// @allocatesA{AES file}
	/// @return												@allocReturn{AES file}
	//----------------------------------------------------------------------------------------
	static AESFile* Alloc(void);

	//----------------------------------------------------------------------------------------
	/// @destructsAlloc{AES files}
	/// @param[in,out] fl							@theToDestruct{AES file}
	//----------------------------------------------------------------------------------------
	static void Free(AESFile*& fl);

	/// @}

	//----------------------------------------------------------------------------------------
	/// Opens a AES encrypted file.
	/// @warning For a plugin to be cross platform then the type and creator parameters must be correctly filled for Mac.
	/// @param[in] name								The name of the file to open.
	/// @param[in] key								The decryption key. @callerOwnsPointed{buffer}
	/// @param[in] keylen							The key length. Must be @em 128, @em 192 or @em 256 (bits).
	/// @param[in] blocksize					The block size. Must be @em 128, @em 192 or @em 256 (bits).
	/// @param[in] aes_flags					Reserved for later use. Must be set to @em 0.
	/// @param[in] mode								The file access mode: @enumerateEnum{FILEOPEN}
	/// @param[in] error_dialog				Sets the type of error reporting that should happen during the file opening: @enumerateEnum{FILEDIALOG}
	/// @param[in] order							The type of byte order in the AES file: @enumerateEnum{BYTEORDER}
	/// @param[in] type								The type of file, only applies to Mac: @ref MACTYPE_CINEMA.
	/// @param[in] creator						The application that wrote the file, for example 'ttxt' (SimpleText) or 'C4D1' for @C4D, only relevant to Mac: @ref MACCREATOR_CINEMA.
	/// @return												@trueIfOtherwiseFalse{the file was opened without any problem}
	//----------------------------------------------------------------------------------------
	Bool Open(const Filename& name, const char* key, Int32 keylen, Int32 blocksize, UInt32 aes_flags, FILEOPEN mode = FILEOPEN::READ, FILEDIALOG error_dialog = FILEDIALOG::IGNOREOPEN, BYTEORDER order = BYTEORDER::V_MOTOROLA, Int32 type = MACTYPE_CINEMA, Int32 creator = MACCREATOR_CINEMA);

	// checks if encrypt is the encrypted version of decrypt
	//----------------------------------------------------------------------------------------
	/// Checks if the encrypted file is the encrypted version of the decrypted file.
	/// @param[in] encrypt						The filename of the encrypted file.
	/// @param[in] decrypt						The filename of the decrypted file.
	/// @param[in] key								The decryption key. @callerOwnsPointed{buffer}
	/// @param[in] keylen							The key length. Must be @em 128, @em 192 or @em 256 (bits).
	/// @param[in] blocksize					The block size. Must be @em 128, @em 192 or @em 256 (bits).
	/// @return												@trueIfOtherwiseFalse{the encrypted file is the encrypted version of the decrypted file}
	//----------------------------------------------------------------------------------------
	static Bool CheckEncryption(const Filename& encrypt, const Filename& decrypt, const char* key, Int32 keylen, Int32 blocksize);

};

//----------------------------------------------------------------------------------------
/// Represents a date time.
//----------------------------------------------------------------------------------------
class LocalFileTime
{
public:
	UInt16 year;				///< Year. (Actual year, e.g. @em 2005 A.D. = @em 2005.)
	UInt16 month;				///< Month. (Actual month, e.g. September = @em 9.)
	UInt16 day;					///< Day. (Actual day, e.g. @em 30 = @em 30.)
	UInt16 hour;				///< Actual hour. (Between 0 and 23. @em 4 pm = @em 16.)
	UInt16 minute;			///< Actual minute. (Between @em 0 and @em 59.)
	UInt16 second;			///< Actual second. (Between @em 0 and @em 59.)

	//---------------------------------------------------------------------------------------
	/// Initializes the file time to a possibly invalid but deterministic state (0000-00-00 00:00:00).
	//---------------------------------------------------------------------------------------
	void Init(void)
	{
		year = month = day = hour = minute = second = 0;
	}

	// > 0: t0 > t1
	// = 0: t0 == t1
	// < 0: t0 < t1

	//----------------------------------------------------------------------------------------
	/// Compare the two file times @formatParam{t0} and @formatParam{t1}.
	/// @param[in] t0									The first file time to compare.
	/// @param[in] t1									The second file time to compare.
	/// @return												@em 0 if the times are identical. < @em 0 if @formatParam{t0} is before @formatParam{t1}, or > @em 0 if @formatParam{t0} is after @formatParam{t1}.
	//----------------------------------------------------------------------------------------
	Int32 Compare(const LocalFileTime& t0, const LocalFileTime& t1)
	{
		Int32 result;

		result = t0.year - t1.year;
		if (result == 0)
		{
			result = t0.month - t1.month;
			if (result == 0)
			{
				result = t0.day - t1.day;
				if (result == 0)
				{
					result = t0.hour - t1.hour;
					if (result == 0)
					{
						result = t0.minute - t1.minute;
						if (result == 0)
							result = t0.second - t1.second;
					}
				}
			}
		}
		return result;
	}

	//----------------------------------------------------------------------------------------
	/// Equality operator.
	/// @param[in] x									The file time to compare with.
	/// @return												The result of the comparison.
	//----------------------------------------------------------------------------------------
	Bool operator == (const LocalFileTime& x)
	{
		return year == x.year && month == x.month && day == x.day && hour == x.hour && minute == x.minute && second == x.second;
	}

	//----------------------------------------------------------------------------------------
	/// Inequality operator.
	/// @param[in] x									The file time to compare with.
	/// @return												The result of the comparison.
	//----------------------------------------------------------------------------------------
	Bool operator != (const LocalFileTime& x)
	{
		return year != x.year || month != x.month || day != x.day || hour != x.hour || minute != x.minute || second != x.second;
	}

	//----------------------------------------------------------------------------------------
	/// Greater than operator.
	/// @param[in] x									The file time to compare with.
	/// @return												The result of the comparison.
	//----------------------------------------------------------------------------------------
	Bool operator > (const LocalFileTime& x)
	{
		return Compare(*this, x) > 0;
	}

	//----------------------------------------------------------------------------------------
	/// Less than operator.
	/// @param[in] x									The file time to compare with.
	/// @return												The result of the comparison.
	//----------------------------------------------------------------------------------------
	Bool operator < (const LocalFileTime& x)
	{
		return Compare(*this, x) < 0;
	}

	//----------------------------------------------------------------------------------------
	/// Greater than or equal operator.
	/// @param[in] x									The file time to compare with.
	/// @return												The result of the comparison.
	//----------------------------------------------------------------------------------------
	Bool operator >= (const LocalFileTime& x)
	{
		return Compare(*this, x) >= 0;
	}

	//----------------------------------------------------------------------------------------
	/// Less than or equal operator.
	/// @param[in] x									The file time to compare with.
	/// @return												The result of the comparison.
	//----------------------------------------------------------------------------------------
	Bool operator <= (const LocalFileTime& x)
	{
		return Compare(*this, x) <= 0;
	}
};

/// @addtogroup GE_FILETIME
/// @ingroup group_enumeration
/// @{
/// @see GeGetFileTime()
#define GE_FILETIME_CREATED	 0			///< File time created.
#define GE_FILETIME_MODIFIED 1			///< File time modified.
#define GE_FILETIME_ACCESS	 2			///< File time accessed.
/// @}

/// @addtogroup BROWSEFILES
/// @ingroup group_enumeration
/// @{
#define BROWSEFILES_CALCSIZE				(1 << 0)			///< Specifies if BrowseFiles::GetSize() can be called later on. Only works for files, not for folders.
#define BROWSEFILES_SUPPRESSCACHING	(1 << 1)			///< Suppress caching.
/// @}

//----------------------------------------------------------------------------------------
/// Helper to browse through files.
/// @addAllocFreeAutoAllocNote
//----------------------------------------------------------------------------------------
class BrowseFiles
{
private:
	BrowseFiles();
	~BrowseFiles();

public:
	/// @name Alloc/Free
	/// @{

	//----------------------------------------------------------------------------------------
	/// @allocatesA{file browser}
	/// @return												@allocReturn{file browser}
	//----------------------------------------------------------------------------------------
	static BrowseFiles* Alloc();

	//----------------------------------------------------------------------------------------
	/// @destructsAlloc{file browsers}
	/// @param[in,out] bf							@theToDestruct{file browser}
	//----------------------------------------------------------------------------------------
	static void Free(BrowseFiles*& bf);

	/// @}

	//----------------------------------------------------------------------------------------
	/// Initializes the class to browse a certain directory.
	/// @param[in] directory					The directory to browse.
	/// @param[in] flags							The browser files flags: @enumerateEnum{BROWSEFILES}
	//----------------------------------------------------------------------------------------
	void Init(const Filename& directory, Int32 flags);

	//----------------------------------------------------------------------------------------
	/// Gets the next file or subdirectory in the browsed directory.
	/// @note To retrieve the first file call GetNext() once.
	/// Example:
	/// @code
	/// AutoAlloc<BrowseFiles> bf;
	/// if (bf == nullptr)
	///   return;
	///
	/// bf->Init(dir, BROWSEFILES_CALCSIZE);
	/// while (bf->GetNext())
	/// {
	///   GePrint(bf->GetFilename().GetString());
	/// }
	/// @endcode
	/// @return												@trueIfOtherwiseFalse{another file was found}
	//----------------------------------------------------------------------------------------
	Bool GetNext(void);

	//----------------------------------------------------------------------------------------
	/// Gets the size for the current file.
	/// @return												The byte size of the file.
	/// @warning											Not valid for directories.
	//----------------------------------------------------------------------------------------
	Int64 GetSize(void);

	//----------------------------------------------------------------------------------------
	/// Checks if the current element is a directory.
	/// @return												@trueIfOtherwiseFalse{the current element is a directory}
	//----------------------------------------------------------------------------------------
	Bool IsDir(void);

	//----------------------------------------------------------------------------------------
	/// Checks if the current file or directory is hidden.
	/// @return												@trueIfOtherwiseFalse{the current file is hidden}
	//----------------------------------------------------------------------------------------
	Bool IsHidden(void);

	//----------------------------------------------------------------------------------------
	/// Checks if the current file or directory is a bundle.
	/// @return												@trueIfOtherwiseFalse{the current file is a bundle}
	//----------------------------------------------------------------------------------------
	Bool IsBundle(void);

	//----------------------------------------------------------------------------------------
	/// Checks if the current file or directory is read-only.
	/// @return												@trueIfOtherwiseFalse{the current file is read-only}
	//----------------------------------------------------------------------------------------
	Bool IsReadOnly(void);

	//----------------------------------------------------------------------------------------
	/// Gets a time for the current file or directory.
	/// @param[in] mode								The file time mode: @enumerateEnum{GE_FILETIME}
	/// @param[out] out								Filled with the retrieved file time. @callerOwnsPointed{file time}
	//----------------------------------------------------------------------------------------
	void GetFileTime(Int32 mode, LocalFileTime* out);

	//----------------------------------------------------------------------------------------
	/// Gets the name of the current file or directory.
	/// @return												The name of the current file or directory.
	//----------------------------------------------------------------------------------------
	Filename GetFilename(void);
};

/// @addtogroup BROWSEVOLUMES
/// @ingroup group_enumeration
/// @{
#define BROWSEVOLUMES_VOLUME_NOT_AVAILABLE (1 << 7)			///< Volume not available.
/// @}

//----------------------------------------------------------------------------------------
/// Helper to browse through volumes.
/// @addAllocFreeAutoAllocNote
//----------------------------------------------------------------------------------------
class BrowseVolumes
{
private:
	BrowseVolumes();
	~BrowseVolumes();

public:

	/// @name Alloc/Free
	/// @{

	//----------------------------------------------------------------------------------------
	/// @allocatesA{volume browser}
	/// @return												@allocReturn{volume browser}
	//----------------------------------------------------------------------------------------
	static BrowseVolumes* Alloc();

	//----------------------------------------------------------------------------------------
	/// @destructsAlloc{volume browsers}
	/// @param[in,out] bf							@theToDestruct{volume browser}
	//----------------------------------------------------------------------------------------
	static void Free(BrowseVolumes*& bf);

	/// @}

	//----------------------------------------------------------------------------------------
	/// Initializes the class to browse volumes.
	//----------------------------------------------------------------------------------------
	void Init(void);

	//----------------------------------------------------------------------------------------
	/// Gets the next volume.
	/// @return												@trueIfOtherwiseFalse{another volume was found}
	//----------------------------------------------------------------------------------------
	Bool GetNext(void);

	//----------------------------------------------------------------------------------------
	/// Gets the filename of the current volume, retrieved with GetNext().
	/// @return												The filename of the current volume.
	//----------------------------------------------------------------------------------------
	Filename GetFilename(void);

	//----------------------------------------------------------------------------------------
	/// Gets the current volume name.
	/// @param[out] out_flags					The flags to check: @enumerateEnum{BROWSEVOLUMES}
	/// @return												The current volume name.
	//----------------------------------------------------------------------------------------
	String GetVolumeName(Int32* out_flags);
};

//---------------------------------------------------------------------------------------
/// Hyper files are used to save plugin data that cannot be stored in a BaseContainer.\n
/// @C4D creates it and pass it to dedicated Load and Save overrides when needed (see NodeData and CustomDataTypeClass).\n
/// Access to the hyper file's data is like a @em FIFO (first in, first out) buffer; the values must be written and read in the same order.
/// @addAllocFreeAutoAllocNote
//---------------------------------------------------------------------------------------
class HyperFile
{
private:
	HyperFile();
	~HyperFile();

public:
	/// @name Alloc/Free
	/// @{

	//----------------------------------------------------------------------------------------
	/// @allocatesA{hyper file}
	/// @return												@allocReturn{hyper file}
	//----------------------------------------------------------------------------------------
	static HyperFile* Alloc(void);

	//----------------------------------------------------------------------------------------
	/// @destructsAlloc{hyper files}
	/// @param[in,out] fl							@theToDestruct{hyper file}
	//----------------------------------------------------------------------------------------
	static void Free(HyperFile*& fl);

	/// @}

	/// @name Open/Close
	/// @{

	//----------------------------------------------------------------------------------------
	/// Opens the hyper file.
	/// @param[in] ident							The file identification.
	/// @param[in] filename						The name of the file to open.
	/// @param[in] mode								The file mode: @enumerateEnum{FILEOPEN}
	/// @param[in] error_dialog				The file error dialog: @enumerateEnum{FILEDIALOG}
	/// @return												@trueIfOtherwiseFalse{the hyper file could be opened}
	//----------------------------------------------------------------------------------------
	Bool Open(Int32 ident, const Filename& filename, FILEOPEN mode, FILEDIALOG error_dialog);

	//----------------------------------------------------------------------------------------
	/// Closes the hyper file.
	/// @return												@trueIfOtherwiseFalse{the hyper file could be closed}
	//----------------------------------------------------------------------------------------
	Bool Close();

	/// @}

	/// @name Read
	/// @{

	//----------------------------------------------------------------------------------------
	/// Reads a ::Char value from the hyper file.
	/// @param[out] v									Assigned the value read from the hyper file.
	/// @return												Success of reading the value.
	//----------------------------------------------------------------------------------------
	Bool ReadChar(Char* v);

	//----------------------------------------------------------------------------------------
	/// Reads a ::UChar value from the hyper file.
	/// @param[out] v									Assigned the value read from the hyper file.
	/// @return												Success of reading the value.
	//----------------------------------------------------------------------------------------
	Bool ReadUChar(UChar* v);

	//----------------------------------------------------------------------------------------
	/// Reads a ::Int16 value from the hyper file.
	/// @param[out] v									Assigned the value read from the hyper file.
	/// @return												Success of reading the value.
	//----------------------------------------------------------------------------------------
	Bool ReadInt16(Int16* v);

	//----------------------------------------------------------------------------------------
	/// Reads a ::UInt16 value from the hyper file.
	/// @param[out] v									Assigned the value read from the hyper file.
	/// @return												Success of reading the value.
	//----------------------------------------------------------------------------------------
	Bool ReadUInt16(UInt16* v);

	//----------------------------------------------------------------------------------------
	/// Reads a ::Int32 value from the hyper file.
	/// @param[out] v									Assigned the value read from the hyper file.
	/// @return												Success of reading the value.
	//----------------------------------------------------------------------------------------
	Bool ReadInt32(Int32* v);

	//----------------------------------------------------------------------------------------
	/// Reads a ::UInt32 value from the hyper file.
	/// @param[out] v									Assigned the value read from the hyper file.
	/// @return												Success of reading the value.
	//----------------------------------------------------------------------------------------
	Bool ReadUInt32(UInt32* v);

	//----------------------------------------------------------------------------------------
	/// Reads a ::Int64 value from the hyper file.
	/// @param[out] v									Assigned the value read from the hyper file.
	/// @return												Success of reading the value.
	//----------------------------------------------------------------------------------------
	Bool ReadInt64(Int64* v);

	//----------------------------------------------------------------------------------------
	/// Reads a ::UInt64 value from the hyper file.
	/// @param[out] v									Assigned the value read from the hyper file.
	/// @return												Success of reading the value.
	//----------------------------------------------------------------------------------------
	Bool ReadUInt64(UInt64* v);

	//----------------------------------------------------------------------------------------
	/// Reads a ::Float value from the hyper file.
	/// @param[out] v									Assigned the value read from the hyper file.
	/// @return												Success of reading the value.
	//----------------------------------------------------------------------------------------
	Bool ReadFloat(Float* v);

	//----------------------------------------------------------------------------------------
	/// Reads a ::Float32 value from the hyper file.
	/// @param[out] v									Assigned the value read from the hyper file.
	/// @return												Success of reading the value.
	//----------------------------------------------------------------------------------------
	Bool ReadFloat32(Float32* v);

	//----------------------------------------------------------------------------------------
	/// Reads a ::Float64 value from the hyper file.
	/// @param[out] v									Assigned the value read from the hyper file.
	/// @return												Success of reading the value.
	//----------------------------------------------------------------------------------------
	Bool ReadFloat64(Float64* v);

	//----------------------------------------------------------------------------------------
	/// Reads a ::Bool value from the hyper file.
	/// @param[out] v									Assigned the value read from the hyper file.
	/// @return												Success of reading the value.
	//----------------------------------------------------------------------------------------
	Bool ReadBool(Bool* v);

	//----------------------------------------------------------------------------------------
	/// Reads a BaseTime value from the hyper file.
	/// @param[out] v									Assigned the value read from the hyper file.
	/// @return												Success of reading the value.
	//----------------------------------------------------------------------------------------
	Bool ReadTime(BaseTime* v);

	//----------------------------------------------------------------------------------------
	/// Reads a ::Vector value from the hyper file.
	/// @param[out] v									Assigned the value read from the hyper file.
	/// @return												Success of reading the value.
	//----------------------------------------------------------------------------------------
	Bool ReadVector(Vector* v);

	//----------------------------------------------------------------------------------------
	/// Reads a ::Vector32 value from the hyper file.
	/// @param[out] v									Assigned the value read from the hyper file.
	/// @return												Success of reading the value.
	//----------------------------------------------------------------------------------------
	Bool ReadVector32(Vector32* v);

	//----------------------------------------------------------------------------------------
	/// Reads a ::Vector64 value from the hyper file.
	/// @param[out] v									Assigned the value read from the hyper file.
	/// @return												Success of reading the value.
	//----------------------------------------------------------------------------------------
	Bool ReadVector64(Vector64* v);

	//----------------------------------------------------------------------------------------
	/// Reads a ::Matrix value from the hyper file.
	/// @param[out] v									Assigned the value read from the hyper file.
	/// @return												Success of reading the value.
	//----------------------------------------------------------------------------------------
	Bool ReadMatrix(Matrix* v);

	//----------------------------------------------------------------------------------------
	/// Reads a ::Matrix32 value from the hyper file.
	/// @param[out] v									Assigned the value read from the hyper file.
	/// @return												Success of reading the value.
	//----------------------------------------------------------------------------------------
	Bool ReadMatrix32(Matrix32* v);

	//----------------------------------------------------------------------------------------
	/// Reads a ::Matrix64 value from the hyper file.
	/// @param[out] v									Assigned the value read from the hyper file.
	/// @return												Success of reading the value.
	//----------------------------------------------------------------------------------------
	Bool ReadMatrix64(Matrix64* v);

	//----------------------------------------------------------------------------------------
	/// Reads a String value from the hyper file.
	/// @param[out] v									Assigned the value read from the hyper file.
	/// @return												Success of reading the value.
	//----------------------------------------------------------------------------------------
	Bool ReadString(maxon::String* v);

	//----------------------------------------------------------------------------------------
	/// Reads a Filename value from the hyper file.
	/// @param[out] v									Assigned the value read from the hyper file.
	/// @return												Success of reading the value.
	//----------------------------------------------------------------------------------------
	Bool ReadFilename(Filename* v);

	//----------------------------------------------------------------------------------------
	/// Reads a BaseBitmap value from the hyper file.
	/// @param[out] v									Assigned the value read from the hyper file.
	/// @return												Success of reading the value.
	//----------------------------------------------------------------------------------------
	Bool ReadImage(BaseBitmap* v);

	//----------------------------------------------------------------------------------------
	/// Reads a GeData value from the hyper file.
	/// @param[out] v									Assigned the value read from the hyper file.
	/// @return												Success of reading the value.
	//----------------------------------------------------------------------------------------
	Bool ReadGeData(GeData* v);

	//----------------------------------------------------------------------------------------
	/// Reads a container from the hyper file.
	/// @param[out] v									Assigned the value read from the hyper file.
	/// @param[in] flush							Specify if the container should be cleared before reading the new values.\n
	/// 															Passing @formatConstant{false} will merge the container with the one read from the file.
	/// @return												Success of reading the container.
	//----------------------------------------------------------------------------------------
	Bool ReadContainer(BaseContainer* v, Bool flush);

	//----------------------------------------------------------------------------------------
	/// Reads a block of memory from the hyper file.\n
	/// @note Only use when really needed. Be aware that the byte sequences will not be platform independent.
	/// @b Example:
	/// @code
	/// Int32 size;
	/// void* data = nullptr;
	/// Bool ok = ReadMemory(&data, &size);
	/// DeleteMem(data);
	/// @endcode
	/// @param[out] data							A pointer to the start of the memory block to read.
	/// @param[out] size							Assigned the byte size of the memory data read.
	/// @return												Success of reading the memory block.
	//----------------------------------------------------------------------------------------
	Bool ReadMemory(void** data, Int* size);

	//----------------------------------------------------------------------------------------
	/// @markDeprecated
	//----------------------------------------------------------------------------------------
	Bool ReadChannelConvert(GeListNode* node, Int32 link_id);

	//----------------------------------------------------------------------------------------
	/// Reads an array of the specified @formatParam{type} from the hyper file.
	/// @param[out] data							A pointer to an array to be filled. @callerOwnsPointed{array}
	/// @param[in] type								The data type: @enumerateEnum{HYPERFILEARRAY}
	/// @param[in] structure_increment	The size of the data type (<i>sizeof()</i>).
	/// @param[in] count							The umber of elements in @formatParam{data}.
	/// @return												Success of reading the array.
	//----------------------------------------------------------------------------------------
	Bool ReadArray(void* data, HYPERFILEARRAY type, Int32 structure_increment, Int32 count);

	//----------------------------------------------------------------------------------------
	/// Reads a C4DUuid value from the hyper file.
	/// @param[out] v									Assigned the value read from the hyper file.
	/// @return												Success of reading the value.
	//----------------------------------------------------------------------------------------
	Bool ReadUuid(C4DUuid* v);

	/// @}

	/// @name Write
	/// @{

	//----------------------------------------------------------------------------------------
	/// Writes a ::Char value to the hyper file.
	/// @param[in] v									The value to write to the hyper file.
	/// @return												Success of writing the value.
	//----------------------------------------------------------------------------------------
	Bool WriteChar(Char v);

	//----------------------------------------------------------------------------------------
	/// Writes a ::UChar value to the hyper file.
	/// @param[in] v									The value to write to the hyper file.
	/// @return												Success of writing the value.
	//----------------------------------------------------------------------------------------
	Bool WriteUChar(UChar v);

	//----------------------------------------------------------------------------------------
	/// Writes a ::Int16 value to the hyper file.
	/// @param[in] v									The value to write to the hyper file.
	/// @return												Success of writing the value.
	//----------------------------------------------------------------------------------------
	Bool WriteInt16(Int16 v);

	//----------------------------------------------------------------------------------------
	/// Writes a ::UInt16 value to the hyper file.
	/// @param[in] v									The value to write to the hyper file.
	/// @return												Success of writing the value.
	//----------------------------------------------------------------------------------------
	Bool WriteUInt16(UInt16 v);

	//----------------------------------------------------------------------------------------
	/// Writes a ::Int32 value to the hyper file.
	/// @param[in] v									The value to write to the hyper file.
	/// @return												Success of writing the value.
	//----------------------------------------------------------------------------------------
	Bool WriteInt32(Int32 v);

	//----------------------------------------------------------------------------------------
	/// Writes a ::UInt32 value to the hyper file.
	/// @param[in] v									The value to write to the hyper file.
	/// @return												Success of writing the value.
	//----------------------------------------------------------------------------------------
	Bool WriteUInt32(UInt32 v);

	//----------------------------------------------------------------------------------------
	/// Writes a ::Int64 value to the hyper file.
	/// @param[in] v									The value to write to the hyper file.
	/// @return												Success of writing the value.
	//----------------------------------------------------------------------------------------
	Bool WriteInt64(Int64 v);

	//----------------------------------------------------------------------------------------
	/// Writes a ::UInt64 value to the hyper file.
	/// @param[in] v									The value to write to the hyper file.
	/// @return												Success of writing the value.
	//----------------------------------------------------------------------------------------
	Bool WriteUInt64(UInt64 v);

	//----------------------------------------------------------------------------------------
	/// Writes a ::Float value to the hyper file.
	/// @param[in] v									The value to write to the hyper file.
	/// @return												Success of writing the value.
	//----------------------------------------------------------------------------------------
	Bool WriteFloat(Float v);

	//----------------------------------------------------------------------------------------
	/// Writes a ::Float32 value to the hyper file.
	/// @param[in] v									The value to write to the hyper file.
	/// @return												Success of writing the value.
	//----------------------------------------------------------------------------------------
	Bool WriteFloat32(Float32 v);

	//----------------------------------------------------------------------------------------
	/// Writes a ::Float64 value to the hyper file.
	/// @param[in] v									The value to write to the hyper file.
	/// @return												Success of writing the value.
	//----------------------------------------------------------------------------------------
	Bool WriteFloat64(Float64 v);

	//----------------------------------------------------------------------------------------
	/// Writes a ::Bool value to the hyper file.
	/// @param[in] v									The value to write to the hyper file.
	/// @return												Success of writing the value.
	//----------------------------------------------------------------------------------------
	Bool WriteBool(Bool v);

	//----------------------------------------------------------------------------------------
	/// Writes a BaseTime value to the hyper file.
	/// @param[in] v									The value to write to the hyper file.
	/// @return												Success of writing the value.
	//----------------------------------------------------------------------------------------
	Bool WriteTime(const BaseTime& v);

	//----------------------------------------------------------------------------------------
	/// Writes a ::Vector value to the hyper file.
	/// @param[in] v									The value to write to the hyper file.
	/// @return												Success of writing the value.
	//----------------------------------------------------------------------------------------
	Bool WriteVector(const Vector& v);

	//----------------------------------------------------------------------------------------
	/// Writes a ::Vector32 value to the hyper file.
	/// @param[in] v									The value to write to the hyper file.
	/// @return												Success of writing the value.
	//----------------------------------------------------------------------------------------
	Bool WriteVector32(const Vector32& v);

	//----------------------------------------------------------------------------------------
	/// Writes a ::Vector64 value to the hyper file.
	/// @param[in] v									The value to write to the hyper file.
	/// @return												Success of writing the value.
	//----------------------------------------------------------------------------------------
	Bool WriteVector64(const Vector64& v);

	//----------------------------------------------------------------------------------------
	/// Writes a ::Matrix value to the hyper file.
	/// @param[in] v									The value to write to the hyper file.
	/// @return												Success of writing the value.
	//----------------------------------------------------------------------------------------
	Bool WriteMatrix(const Matrix& v);

	//----------------------------------------------------------------------------------------
	/// Writes a ::Matrix32 value to the hyper file.
	/// @param[in] v									The value to write to the hyper file.
	/// @return												Success of writing the value.
	//----------------------------------------------------------------------------------------
	Bool WriteMatrix32(const Matrix32& v);

	//----------------------------------------------------------------------------------------
	/// Writes a ::Matrix64 value to the hyper file.
	/// @param[in] v									The value to write to the hyper file.
	/// @return												Success of writing the value.
	//----------------------------------------------------------------------------------------
	Bool WriteMatrix64(const Matrix64& v);

	//----------------------------------------------------------------------------------------
	/// Writes a String value to the hyper file.
	/// @param[in] v									The value to write to the hyper file.
	/// @return												Success of writing the value.
	//----------------------------------------------------------------------------------------
	Bool WriteString(const maxon::String& v);

	//----------------------------------------------------------------------------------------
	/// Writes a Filename value to the hyper file.
	/// @param[in] v									The value to write to the hyper file.
	/// @return												Success of writing the value.
	//----------------------------------------------------------------------------------------
	Bool WriteFilename(const Filename& v);

	//----------------------------------------------------------------------------------------
	/// Writes an image to the hyper file.
	/// @param[in] bmp								The bitmap to write to the hyperfile. @callerOwnsPointed{bitmap}
	/// @param[in] format							The image format: @enumerateEnum{FILTER}
	/// @param[in] data								A container with additional format settings, or @formatConstant{nullptr}.
	/// @param[in] savebits						The save bits: @enumerateEnum{SAVEBIT}
	/// @return												Success of writing the image.
	//----------------------------------------------------------------------------------------
	Bool WriteImage(BaseBitmap* bmp, Int32 format, BaseContainer* data, SAVEBIT savebits = SAVEBIT::ALPHA);

	//----------------------------------------------------------------------------------------
	/// Writes a ::Char value to the hyper file.
	/// @param[in] v									The value to write to the hyper file.
	/// @return												Success of writing the value.
	//----------------------------------------------------------------------------------------
	Bool WriteGeData(const GeData& v);

	//----------------------------------------------------------------------------------------
	/// Writes a container to the hyper file.
	/// @param[in] v									The container to write to the hyper file.
	/// @return												Success of writing the container.
	//----------------------------------------------------------------------------------------
	Bool WriteContainer(const BaseContainer& v);

	//----------------------------------------------------------------------------------------
	/// Writes a block of memory to the hyper file.
	/// @note Only use when really needed. Be aware that the byte sequences will not be platform independent.
	/// @param[in] data								The start of the memory block to write to the hyper file.
	/// @param[in] count							The size in bytes of the memory data to write.
	/// @return												Success of writing the memory block.
	//----------------------------------------------------------------------------------------
	Bool WriteMemory(const void* data, Int count);

	//----------------------------------------------------------------------------------------
	/// Writes an array of the specified @formatParam{datatype} to the hyper file.
	/// @param[in] data								The pointer to the array. @callerOwnsPointed{array}
	/// @param[in] datatype						The array data type: @enumerateEnum{HYPERFILEARRAY}
	/// @param[in] structure_increment	Size of the data type (<i>sizeof()</i>).
	/// @param[in] count							The number of elements in @formatParam{data}.
	/// @return												Success of writing the array.
	//----------------------------------------------------------------------------------------
	Bool WriteArray(const void* data, HYPERFILEARRAY datatype, Int32 structure_increment, Int32 count);

	//----------------------------------------------------------------------------------------
	/// Writes a C4DUuid value to the hyper file.
	/// @param[in] v									The value to write to the hyper file.
	/// @return												Success of writing the value.
	//----------------------------------------------------------------------------------------
	Bool WriteUuid(const C4DUuid& v);

	/// @}

	/// @name Error
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets the error from the last hyper file operation.
	/// @return												The error: @enumerateEnum{FILEERROR}
	//----------------------------------------------------------------------------------------
	FILEERROR GetError() const;

	//----------------------------------------------------------------------------------------
	/// Sets the error for the hyper file.
	/// @param[in] err								The error to set: @enumerateEnum{FILEERROR}
	//----------------------------------------------------------------------------------------
	void SetError(FILEERROR err);

	/// @}

	/// @name HyperFile Value
	/// @{

	//----------------------------------------------------------------------------------------
	/// Reads the value header from the hyper file.\n
	/// This is only necessary in combination with loops.\n
	/// For example:
	/// @code
	/// static Bool ReadSettings(BaseObject *op, HyperFile *hf, Int32 level)
	/// {
	/// 	Int32 id, level, v;
	/// 	String test;
	/// 	HYPERFILEVALUE h;
	/// 	while (hf->ReadValueHeader(&h) && h==HYPERFILEVALUE::START)
	/// 	{
	/// 		if (!hf->ReadChunkStart(&id, &level))
	/// 			return false;
	///
	/// 		if (id==2)
	/// 		{
	/// 			hf->ReadInt32(&v);
	/// 			hf->ReadInt32(&v);
	/// 		}
	/// 		else if (id==3)
	/// 		{
	/// 			hf->ReadInt32(&v);
	/// 			hf->ReadInt32(&v);
	/// 			hf->ReadInt32(&v);
	/// 		}
	/// 		hf->SkipToEndChunk(); // Never forget this at the end
	/// 		if (id==0)
	/// 			break; // Chunk ID 0 is end chunk
	/// 	}
	///
	/// 	hf->ReadString(test);
	///
	/// 	return true;
	/// }
	/// @endcode
	/// @param[in] h									A pointer to a HYPERFILEVALUE to take the header value: @enumerateEnum{HYPERFILEVALUE}
	/// @return												@trueIfOtherwiseFalse{the header was read successfully}
	//----------------------------------------------------------------------------------------
	Bool ReadValueHeader(HYPERFILEVALUE* h);

	//----------------------------------------------------------------------------------------
	/// Skips a given type of value.
	/// @param[in] h									The hyper file value to skip: @enumerateEnum{HYPERFILEVALUE}
	/// @return												@trueIfOtherwiseFalse{the value was of the given header type and it was skipped}
	//----------------------------------------------------------------------------------------
	Bool SkipValue(HYPERFILEVALUE h);

	/// @}

	/// @name Chunk Start/End
	/// @{

	//----------------------------------------------------------------------------------------
	/// Writes a chunk marker into the file indicating the beginning of a new chunk of data.
	/// @param[in] id									The ID for the chunk.
	/// @param[in] level							To write additional information, increase this level to save/read new values.
	/// @return												@trueIfOtherwiseFalse{the chunk identification was written successfully}
	//----------------------------------------------------------------------------------------
	Bool WriteChunkStart(Int32 id, Int32 level);

	//----------------------------------------------------------------------------------------
	/// Writes a chunk ending marker into the hyper file.
	/// @return												@trueIfOtherwiseFalse{the chunk end was written successfully}
	//----------------------------------------------------------------------------------------
	Bool WriteChunkEnd(void);

	//----------------------------------------------------------------------------------------
	/// Reads a chunks identification from the hyper file.
	/// @param[out] id								Assigned the chunk ID.
	/// @param[out] level							Assigned the chunk level.
	/// @return												@trueIfOtherwiseFalse{the chunk start was read successfully}
	//----------------------------------------------------------------------------------------
	Bool ReadChunkStart(Int32* id, Int32* level);

	//----------------------------------------------------------------------------------------
	/// Reads a chunk end marker from the hyper file.
	/// @return												@trueIfOtherwiseFalse{the chunk end was read successfully}
	//----------------------------------------------------------------------------------------
	Bool ReadChunkEnd(void);

	//----------------------------------------------------------------------------------------
	/// Moves the file pointer to the end of the chunk.
	/// @note Should always be called after having finished reading values from the current chunk.
	/// @return												@trueIfOtherwiseFalse{the end of the chunk was found and skipped to}
	//----------------------------------------------------------------------------------------
	Bool SkipToEndChunk(void);

	/// @}

	/// @name File Version
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets the version of @C4D that wrote the file. (Only valid while reading a @C4D scene, object, material etc.)
	/// @return												The file version.
	//----------------------------------------------------------------------------------------
	Int32 GetFileVersion() const;

	//----------------------------------------------------------------------------------------
	/// @markPrivate
	//----------------------------------------------------------------------------------------
	void SetFileVersion(Int32 val);

	/// @}

	/// @name Miscellaneous
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets the active document for the hyper file operation.\n
	/// Can be @formatConstant{nullptr}, for instance when saving layouts.
	/// @return												The document for the hyper file operation. @cinemaOwnsPointed{document}
	//----------------------------------------------------------------------------------------
	BaseDocument* GetDocument() const;

	//----------------------------------------------------------------------------------------
	/// Gets the hyper file location.
	/// @return												The hyper file location: @enumerateEnum{LOCATION}
	//----------------------------------------------------------------------------------------
	LOCATION GetLocation(void) const;

	//----------------------------------------------------------------------------------------
	/// Gets the filter flags, the value is valid only during a Load or a Merge.
	/// @return												The filter flags: @enumerateEnum{SCENEFILTER}
	//----------------------------------------------------------------------------------------
	SCENEFILTER GetFilterFlags() const;
	/// @}
};

/// @addtogroup group_c4d_file_hyperfile HyperFile
/// @ingroup group_function
/// @{

//----------------------------------------------------------------------------------------
/// Reads a single list node from a hyper file on disk.\n
/// The read data replaces the data in @formatParam{node}.\n
/// @note To dynamically read/write many objects, just pass a GeListHead as @formatParam{node}.
/// @param[in] doc								The document of @formatParam{node}. @callerOwnsPointed{document}
/// @param[out] node							The node to read to. Must be allocated before the call. @callerOwnsPointed{node}
/// @param[in] filename						A valid filename to read from.
/// @param[in] ident							A unique file identification.
/// @param[in] warning_string			Assigned additional error information if passed. @callerOwnsPointed{string}
/// @return												The file result: @enumerateEnum{FILEERROR}
//----------------------------------------------------------------------------------------
FILEERROR ReadHyperFile(BaseDocument* doc, GeListNode* node, const Filename& filename, Int32 ident, maxon::String* warning_string);

//----------------------------------------------------------------------------------------
/// Writes a single list node to disk as a hyper file.
/// @param[in] doc								The document of @formatParam{node}. @callerOwnsPointed{document}
/// @param[in] node								The node to write. @callerOwnsPointed{node}
/// @param[in] filename						A valid filename to write to.
/// @param[in] ident							A unique file identification.
/// @return												The file result: @enumerateEnum{FILEERROR}
//----------------------------------------------------------------------------------------
FILEERROR WriteHyperFile(BaseDocument* doc, GeListNode* node, const Filename& filename, Int32 ident);

/// @}

/// @addtogroup group_c4d_file_gefile GeFile
/// @ingroup group_function
/// @{

/// @addtogroup GE_FKILL
/// @ingroup group_enumeration
/// @{
#define GE_FKILL_DIRECTORY 1			///< Delete directories.
#define GE_FKILL_RECURSIVE 2			///< Delete the children of a directory.
#define GE_FKILL_FORCE		 4			///< Delete write-protected files.
/// @}

/// @addtogroup GE_FCOPY
/// @ingroup group_enumeration
/// @{
#define GE_FCOPY_OVERWRITE				1			///< Force a file overwrite, even if a file already exists under that name.
#define GE_FCOPY_DONTCOPYREADONLY	2			///< Do not copy an existing read-only flag.
/// @}

/// @addtogroup GE_FILE_ATTRIBUTE
/// @ingroup group_enumeration
/// @{
#define GE_FILE_ATTRIBUTE_READONLY	0x00000001			///< File is read-only.
#define GE_FILE_ATTRIBUTE_HIDDEN		0x00000002			///< File is hidden.
#define GE_FILE_ATTRIBUTE_LOCKED		0x00000010			///< File is locked (Mac only).
#define GE_FILE_ATTRIBUTE_OWNER_R		0x00000100			///< Owner read file permission.
#define GE_FILE_ATTRIBUTE_OWNER_W		0x00000200			///< Owner write file permission.
#define GE_FILE_ATTRIBUTE_OWNER_X		0x00000400			///< Owner execute file permission.
#define GE_FILE_ATTRIBUTE_GROUP_R		0x00000800			///< Group read file permission.
#define GE_FILE_ATTRIBUTE_GROUP_W		0x00001000			///< Group write file permission.
#define GE_FILE_ATTRIBUTE_GROUP_X		0x00002000			///< Group execute file permission.
#define GE_FILE_ATTRIBUTE_PUBLIC_R	0x00004000			///< Public read file permission.
#define GE_FILE_ATTRIBUTE_PUBLIC_W	0x00008000			///< Public write file permission.
#define GE_FILE_ATTRIBUTE_PUBLIC_X	0x00010000			///< Public execute file permission.
#define GE_FILE_ATTRIBUTS_UNIX_MASK	0x0001ff00			///< UNIX file attributes mask.
/// @}

//----------------------------------------------------------------------------------------
/// Checks if a file or directory exists.
/// @param[in] name								The name of the file or directory to check for.
/// @param[in] isdir							@formatConstant{true} if checking a directory.
/// @return												@trueIfOtherwiseFalse{the file or directory exists}
//----------------------------------------------------------------------------------------
Bool GeFExist(const Filename& name, Bool isdir = false);

//----------------------------------------------------------------------------------------
/// Recursively searches for a file in a given directory.
/// @param[in] directory					The directory to search for the file.
/// @param[in] name								The name of the file to find.
/// @param[out] found							A pointer to a Filename to take the filename of the actual file found. @callerOwnsPointed{filename}
/// @return												@trueIfOtherwiseFalse{the file was found}
//----------------------------------------------------------------------------------------
Bool GeSearchFile(const Filename& directory, const Filename& name, Filename* found);

//----------------------------------------------------------------------------------------
/// Deletes a file or directory.
/// @param[in] name								The name of the file or directory to delete.
/// @param[in] flags							The delete flags: @enumerateEnum{GE_FKILL}
/// @return												@trueIfOtherwiseFalse{the file or directory was deleted}
//----------------------------------------------------------------------------------------
Bool GeFKill(const Filename& name, Int32 flags = 0);

//----------------------------------------------------------------------------------------
/// Copies a file.
/// @param[in] source							The name of the file to copy.
/// @param[in] dest								The name of the file to create from the source file.
/// @param[in] flags							The copy flags: @enumerateEnum{GE_FCOPY}
/// @return												@trueIfOtherwiseFalse{the file was copied}
//----------------------------------------------------------------------------------------
Bool GeFCopyFile(const Filename& source, const Filename& dest, Int32 flags);

//----------------------------------------------------------------------------------------
/// Renames a file.
/// @warning Files can only be renamed on the same directory level, i.e. they cannot be moved through this function.
/// @param[in] source							The name of the file to rename.
/// @param[in] dest								The new name of the file.
/// @return												@trueIfOtherwiseFalse{the file was renamed}
//----------------------------------------------------------------------------------------
Bool GeFRename(const Filename& source, const Filename& dest);

//----------------------------------------------------------------------------------------
/// Moves a file.
/// @param[in] source							The source path.
/// @param[in] dest								The destination path.
/// @return												@trueIfOtherwiseFalse{the file was moved}
//----------------------------------------------------------------------------------------
Bool GeFMove(const Filename& source, const Filename& dest);

//----------------------------------------------------------------------------------------
/// Creates a directory.
/// @warning Only one directory level is created. If more than one directory in the path specified by @formatParam{name} does not exist then this function will fail to create them.
/// @see GeFCreateDirRec()
/// @param[in] name								The name of the directory to create.
/// @return												@trueIfOtherwiseFalse{the directory was created}
//----------------------------------------------------------------------------------------
Bool GeFCreateDir(const Filename& name);

//----------------------------------------------------------------------------------------
/// Creates a directory even if the directories in the path do not exist.
/// @param[in] name								The name of the directory to create.
/// @return												@trueIfOtherwiseFalse{the directory was created}
//----------------------------------------------------------------------------------------
Bool GeFCreateDirRec(const Filename& name);

//----------------------------------------------------------------------------------------
/// Retrieves information about the amount of space that is available on a disk volume.
/// @param[in] vol								The name of the disk volume.
/// @param[out] freecaller				Assigned the number of bytes on the volume available to the calling application.
/// @param[out] total							Assigned the total number of bytes on a disk.
/// @param[out] freespace					Assigned the number of bytes of free space on the volume.
/// @return												@trueIfOtherwiseFalse{disk free space information was retrieved}
//----------------------------------------------------------------------------------------
Bool GeFGetDiskFreeSpace(const Filename& vol, UInt64& freecaller, UInt64& total, UInt64& freespace);

//----------------------------------------------------------------------------------------
/// Gets the attributes of a file.
/// @param[in] name								The file name.
/// @return												The attribute flags: @enumerateEnum{GE_FILE_ATTRIBUTE}
//----------------------------------------------------------------------------------------
UInt32 GeFGetAttributes(const Filename& name);

//----------------------------------------------------------------------------------------
/// Sets the attributes for a file.
/// @param[in] name								The file name.
/// @param[in] flags							The attribute flags: @enumerateEnum{GE_FILE_ATTRIBUTE}
/// @param[in] mask								An attribute mask to protect already set flags: @enumerateEnum{GE_FILE_ATTRIBUTE}
/// @return												@trueIfOtherwiseFalse{the attributes could be set}
//----------------------------------------------------------------------------------------
Bool GeFSetAttributes(const Filename& name, UInt32 flags, UInt32 mask = (UInt32) - 1);

/// @}

/// @addtogroup group_c4d_file_gef GeExecute
/// @ingroup group_function
/// @{

//----------------------------------------------------------------------------------------
/// Executes a file.\n
/// Open the file as if the user double-clicked it; the default application for this file will open.
/// @param[in] path								The name of the file to execute.
/// @return												@trueIfOtherwiseFalse{the file was executed}
//----------------------------------------------------------------------------------------
Bool GeExecuteFile(const Filename& path);

//----------------------------------------------------------------------------------------
/// Executes an application.
/// @note The application will be started asynchronously.
/// @param[in] program						The name of the application to execute.
/// @param[in] file								The name of an optional file to open using the application.
/// @return												@trueIfOtherwiseFalse{the application was executed}
//----------------------------------------------------------------------------------------
Bool GeExecuteProgram(const Filename& program, const Filename& file);

/// @}

/// @addtogroup group_c4d_file_cinemapaths Cinema 4D Paths
/// @ingroup group_function
/// @{

//----------------------------------------------------------------------------------------
/// Gets the path for the main folder of @C4D.
/// @return												The main path of @C4D application.
//----------------------------------------------------------------------------------------
const Filename GeGetStartupPath(void);

//----------------------------------------------------------------------------------------
/// Gets the complete path of the host application (@C4D, @BP3D, @em NET).
/// @return												The complete path to the host application.
//----------------------------------------------------------------------------------------
const Filename GeGetStartupApplication(void);

//----------------------------------------------------------------------------------------
/// Gets the @b writable startup directory.\n
/// This is the directory where all user data (preferences, libraries etc.) are stored.
/// @note Use this for instance to store plugin preferences because Windows and Apple do not allow to write files into the application folder.
/// @return												The @b writable startup directory.
//----------------------------------------------------------------------------------------
const Filename GeGetStartupWritePath(void);

//----------------------------------------------------------------------------------------
/// Gets the path for a plugin's main folder.
/// @return												The path for the plugin that called this function.
//----------------------------------------------------------------------------------------
const Filename GeGetPluginPath(void);

//----------------------------------------------------------------------------------------
/// Gets the resource path for a plugin's main folder.
/// @since R16
/// @return												The resource path for the plugin that called this function.
//----------------------------------------------------------------------------------------
Filename GeGetPluginResourcePath();

/// @addtogroup C4D_PATH
/// @ingroup group_enumeration
/// @{
#define C4D_PATH_PREFS				1				///< @C4D preferences directory.
#define C4D_PATH_RESOURCE			2				///< @C4D resource directory.
#define C4D_PATH_LIBRARY			3				///< @C4D library directory. (Built-in.)
#define C4D_PATH_LIBRARY_USER	4				///< @C4D library path. (Different if multi-user mode is enabled.)
#define C4D_PATH_ONLINE_HELP	5				///< @C4D online help directory.
#define C4D_PATH_DESKTOP			6				///< OS desktop directory.
#define C4D_PATH_HOME					7				///< OS home directory.
#define C4D_PATH_STARTUPWRITE	8				///< Writable startup directory.
#define C4D_PATH_MYDOCUMENTS	9				///< The user's documents directory.
#define C4D_PATH_APPLICATION	10			///< OS application directory.
/// @}

//----------------------------------------------------------------------------------------
/// Gets one of the @C4D paths.
/// @param[in] whichpath					The path to get: @enumerateEnum{C4D_PATH}
/// @return												The retrieved @C4D path.
//----------------------------------------------------------------------------------------
const Filename GeGetC4DPath(Int32 whichpath);

/// @}

/// @addtogroup group_c4d_file_filetime FileTime
/// @ingroup group_function
/// @{

//----------------------------------------------------------------------------------------
/// Gets a file time for the given @formatParam{mode}.
/// @param[in] name								The filename to get the time for.
/// @param[in] mode								The file time mode: @enumerateEnum{GE_FILETIME}
/// @param[out] out								Filled with the file time. @callerOwnsPointed{file time}
/// @return												@trueIfOtherwiseFalse{the file time could be retrieved}
//----------------------------------------------------------------------------------------
Bool GeGetFileTime(const Filename& name, Int32 mode, LocalFileTime* out);

//----------------------------------------------------------------------------------------
/// Sets the file time for the given @formatParam{mode}.
/// @param[in] name								The filename to set the time for.
/// @param[in] mode								The file time mode: @enumerateEnum{GE_FILETIME}
/// @param[in] in									The file time to set. @callerOwnsPointed{file time}
/// @return												@trueIfOtherwiseFalse{the file time could be set}
//----------------------------------------------------------------------------------------
Bool GeSetFileTime(const Filename& name, Int32 mode, const LocalFileTime* in);

/// @}

//----------------------------------------------------------------------------------------
/// Gets the current time.
/// @param[out] out								Filled with the current time. @callerOwnsPointed{file time}
//----------------------------------------------------------------------------------------
void GeGetCurrentTime(LocalFileTime* out);

//----------------------------------------------------------------------------------------
/// Converts the value of a LocalFileTime into a string.
/// @note The format of the returned string depends on the current OS date and time settings.
/// @param[in] t									The file time to convert.
/// @param[in] date_only					If @formatConstant{true} only the date part will be converted.
/// @return												A String representing the LocalFileTime value.
//----------------------------------------------------------------------------------------
String DateToString(const LocalFileTime& t, Bool date_only);

//----------------------------------------------------------------------------------------
/// Shows the file/path in the Finder (@em Mac) or Explorer (@em Windows).
/// @param[in] fn									The file/path to show.
/// @param[in] open								If @formatConstant{true} the file will be opened by the assigned application.
/// @return												@trueIfOtherwiseFalse{the path/file exists}
//----------------------------------------------------------------------------------------
Bool ShowInFinder(const Filename& fn, Bool open);

//----------------------------------------------------------------------------------------
/// @markPrivate
//----------------------------------------------------------------------------------------
Bool RequestFileFromServer(const Filename& fn, Filename& res);

maxon::String ToString(const Filename& val, const maxon::FormatStatement* formatStatement, maxon::Bool checkDatatype = false);

enum class MAXONCONVERTMODE
{
	NONE,			///< No check if file exists under case-sensitive drives.
	READ,			///< Check for file read operation.
	WRITE			///< Check for file write operation.
};

maxon::Url MaxonConvert(const Filename& fn, MAXONCONVERTMODE convertMode);
Filename MaxonConvert(const maxon::Url& fn);

#ifdef CINEWARE_NAMESPACE_ENABLE
	CINEWARE_NAMESPACE_END
#endif

#endif

#endif // C4D_FILE_H__
