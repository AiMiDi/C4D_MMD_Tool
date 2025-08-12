#ifndef IOSTREAMS_HELPER_H__
#define IOSTREAMS_HELPER_H__


#include "maxon/iostreams.h"
#include "maxon/byteorder.h"
#include "maxon/url.h"

namespace maxon
{

/// @addtogroup IO
/// @{

class IoFileOutputHelper : public OutputStreamRef
{
public:
	Result<void> Init(const Url& url, BYTEORDER byteOrder);
	Result<void> Init(const OutputStreamRef& stream, BYTEORDER byteOrder);

	BYTEORDER GetByteOrder() const;
	Url GetUrl() const;

	Result<void> WriteBytes(const Block<const Byte>& data);
	Result<void> WriteChar(Char v);
	Result<void> WriteUChar(UChar v);
	Result<void> WriteInt16(Int16 v);
	Result<void> WriteUInt16(UInt16 v);
	Result<void> WriteInt32(Int32 v);
	Result<void> WriteUInt32(UInt32 v);
	Result<void> WriteInt64(Int64 v);
	Result<void> WriteUInt64(UInt64 v);
	Result<void> WriteFloat32(Float32 v);
	Result<void> WriteFloat64(Float64 v);

private:
	BYTEORDER _byteOrder = BYTEORDER::LITTLE;
	Url				_url;
};

class IoFileInputHelper : public InputStreamRef
{
public:
	Result<void> Init(const Url& url, BYTEORDER byteOrder);
	Result<void> Init(const InputStreamRef& stream, BYTEORDER byteOrder);
	void SetByteOrder(BYTEORDER byteOrder);

	BYTEORDER GetByteOrder() const;
	Url GetUrl() const;

	Result<void> ReadChar(Char* v);
	Result<void> ReadUChar(UChar* v);
	Result<void> ReadInt16(Int16* v);
	Result<void> ReadUInt16(UInt16* v);
	Result<void> ReadInt32(Int32* v);
	Result<void> ReadUInt32(UInt32* v);
	Result<void> ReadInt64(Int64* v);
	Result<void> ReadUInt64(UInt64* v);
	Result<void> ReadFloat32(Float32* v);
	Result<void> ReadFloat64(Float64* v);

	Result<Char> ReadChar();
	Result<UChar> ReadUChar();
	Result<Int16> ReadInt16();
	Result<UInt16> ReadUInt16();
	Result<Int32> ReadInt32();
	Result<UInt32> ReadUInt32();
	Result<Int64> ReadInt64();
	Result<UInt64> ReadUInt64();
	Result<Float32> ReadFloat32();
	Result<Float64> ReadFloat64();

private:
	BYTEORDER _byteOrder = BYTEORDER::LITTLE;
	Url				_url;
};


/// @}

} // namespace maxon


#endif // IOSTREAMS_HELPER_H__
