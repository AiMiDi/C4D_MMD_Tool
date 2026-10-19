#include "maxon/utilities/iostreams_helper.h"
#include "maxon/url.h"

namespace maxon
{

Result<void> IoFileOutputHelper::Init(const Url& url, BYTEORDER byteOrder)
{
	iferr_scope;
	OutputStreamRef stream = url.OpenOutputStream(OPENSTREAMFLAGS::NONE) iferr_return;
	_url = url;
	return Init(stream, byteOrder);
}

Result<void> IoFileOutputHelper::Init(const OutputStreamRef& stream, BYTEORDER byteOrder)
{
	*static_cast<OutputStreamRef*>(this) = stream;
	_byteOrder = byteOrder;
	return OK;
}

BYTEORDER IoFileOutputHelper::GetByteOrder() const
{
	return _byteOrder;
}

Url IoFileOutputHelper::GetUrl() const
{
	return _url;
}

Result<void> IoFileOutputHelper::WriteBytes(const Block<const Byte>& data)
{
	return Write(data);
}

Result<void> IoFileOutputHelper::WriteChar(Char v)
{
	return Write(ToSingletonBlock(v));
}

Result<void> IoFileOutputHelper::WriteUChar(UChar v)
{
	return Write(ToSingletonBlock(v));
}

Result<void> IoFileOutputHelper::WriteInt16(Int16 v)
{
	if (_byteOrder == BYTEORDER::BIG)
		ByteOrder_Int16<BYTEORDER::BIG>(&v, 1);
	else
		ByteOrder_Int16<BYTEORDER::LITTLE>(&v, 1);
	return Write(ToSingletonBlock(v));
}

Result<void> IoFileOutputHelper::WriteUInt16(UInt16 v)
{
	if (_byteOrder == BYTEORDER::BIG)
		ByteOrder_UInt16<BYTEORDER::BIG>(&v, 1);
	else
		ByteOrder_UInt16<BYTEORDER::LITTLE>(&v, 1);
	return Write(ToSingletonBlock(v));
}

Result<void> IoFileOutputHelper::WriteInt32(Int32 v)
{
	if (_byteOrder == BYTEORDER::BIG)
		ByteOrder_Int32<BYTEORDER::BIG>(&v, 1);
	else
		ByteOrder_Int32<BYTEORDER::LITTLE>(&v, 1);
	return Write(ToSingletonBlock(v));
}

Result<void> IoFileOutputHelper::WriteUInt32(UInt32 v)
{
	if (_byteOrder == BYTEORDER::BIG)
		ByteOrder_UInt32<BYTEORDER::BIG>(&v, 1);
	else
		ByteOrder_UInt32<BYTEORDER::LITTLE>(&v, 1);
	return Write(ToSingletonBlock(v));
}

Result<void> IoFileOutputHelper::WriteInt64(Int64 v)
{
	if (_byteOrder == BYTEORDER::BIG)
		ByteOrder_Int64<BYTEORDER::BIG>(&v, 1);
	else
		ByteOrder_Int64<BYTEORDER::LITTLE>(&v, 1);
	return Write(ToSingletonBlock(v));
}

Result<void> IoFileOutputHelper::WriteUInt64(UInt64 v)
{
	if (_byteOrder == BYTEORDER::BIG)
		ByteOrder_UInt64<BYTEORDER::BIG>(&v, 1);
	else
		ByteOrder_UInt64<BYTEORDER::LITTLE>(&v, 1);
	return Write(ToSingletonBlock(v));
}

Result<void> IoFileOutputHelper::WriteFloat32(Float32 v)
{
	if (_byteOrder == BYTEORDER::BIG)
		ByteOrder_UInt32<BYTEORDER::BIG>((UInt32*)&v, 1);
	else
		ByteOrder_UInt32<BYTEORDER::LITTLE>((UInt32*)&v, 1);
	return Write(ToSingletonBlock(v));
}

Result<void> IoFileOutputHelper::WriteFloat64(Float64 v)
{
	if (_byteOrder == BYTEORDER::BIG)
		ByteOrder_UInt64<BYTEORDER::BIG>((UInt64*)&v, 1);
	else
		ByteOrder_UInt64<BYTEORDER::LITTLE>((UInt64*)&v, 1);
	return Write(ToSingletonBlock(v));
}



Result<void> IoFileInputHelper::Init(const Url& url, BYTEORDER byteOrder)
{
	iferr_scope;
	InputStreamRef stream = url.OpenInputStream(OPENSTREAMFLAGS::NONE) iferr_return;
	_url = url;
	return Init(stream, byteOrder);
}

Result<void> IoFileInputHelper::Init(const InputStreamRef& stream, BYTEORDER byteOrder)
{
	*static_cast<InputStreamRef*>(this) = stream;
	SetByteOrder(byteOrder);
	return OK;
}

void IoFileInputHelper::SetByteOrder(BYTEORDER byteOrder)
{
	_byteOrder = byteOrder;
}

BYTEORDER IoFileInputHelper::GetByteOrder() const
{
	return _byteOrder;
}

Url IoFileInputHelper::GetUrl() const
{
	return _url;
}

Result<void> IoFileInputHelper::ReadChar(Char* v)
{
	return Read(ToBlock(v, 1));
}

Result<Char> IoFileInputHelper::ReadChar()
{
	iferr_scope;
	Char v;
	ReadChar(&v) iferr_return;
	return v;
}

Result<void> IoFileInputHelper::ReadUChar(UChar* v)
{
	return Read(ToBlock(v, 1));
}

Result<UChar> IoFileInputHelper::ReadUChar()
{
	iferr_scope;
	UChar v;
	ReadUChar(&v) iferr_return;
	return v;
}

Result<void> IoFileInputHelper::ReadInt16(Int16* v)
{
	iferr (Read(ToBlock(v, 1)))
		return err;
	if (_byteOrder == BYTEORDER::BIG)
		ByteOrder_Int16<BYTEORDER::BIG>(v, 1);
	else
		ByteOrder_Int16<BYTEORDER::LITTLE>(v, 1);
	return OK;
}

Result<Int16> IoFileInputHelper::ReadInt16()
{
	iferr_scope;
	Int16 v;
	ReadInt16(&v) iferr_return;
	return v;
}

Result<void> IoFileInputHelper::ReadUInt16(UInt16* v)
{
	iferr (Read(ToBlock(v, 1)))
		return err;
	if (_byteOrder == BYTEORDER::BIG)
		ByteOrder_UInt16<BYTEORDER::BIG>(v, 1);
	else
		ByteOrder_UInt16<BYTEORDER::LITTLE>(v, 1);
	return OK;
}

Result<UInt16> IoFileInputHelper::ReadUInt16()
{
	iferr_scope;
	UInt16 v;
	ReadUInt16(&v) iferr_return;
	return v;
}

Result<void> IoFileInputHelper::ReadInt32(Int32* v)
{
	iferr (Read(ToBlock(v, 1)))
		return err;
	if (_byteOrder == BYTEORDER::BIG)
		ByteOrder_Int32<BYTEORDER::BIG>(v, 1);
	else
		ByteOrder_Int32<BYTEORDER::LITTLE>(v, 1);
	return OK;
}

Result<Int32> IoFileInputHelper::ReadInt32()
{
	iferr_scope;
	Int32 v;
	ReadInt32(&v) iferr_return;
	return v;
}

Result<void> IoFileInputHelper::ReadUInt32(UInt32* v)
{
	iferr (Read(ToBlock(v, 1)))
		return err;
	if (_byteOrder == BYTEORDER::BIG)
		ByteOrder_UInt32<BYTEORDER::BIG>(v, 1);
	else
		ByteOrder_UInt32<BYTEORDER::LITTLE>(v, 1);
	return OK;
}

Result<UInt32> IoFileInputHelper::ReadUInt32()
{
	iferr_scope;
	UInt32 v;
	ReadUInt32(&v) iferr_return;
	return v;
}

Result<void> IoFileInputHelper::ReadInt64(Int64* v)
{
	iferr (Read(ToBlock(v, 1)))
		return err;
	if (_byteOrder == BYTEORDER::BIG)
		ByteOrder_Int64<BYTEORDER::BIG>(v, 1);
	else
		ByteOrder_Int64<BYTEORDER::LITTLE>(v, 1);
	return OK;
}

Result<Int64> IoFileInputHelper::ReadInt64()
{
	iferr_scope;
	Int64 v;
	ReadInt64(&v) iferr_return;
	return v;
}

Result<void> IoFileInputHelper::ReadUInt64(UInt64* v)
{
	iferr (Read(ToBlock(v, 1)))
		return err;
	if (_byteOrder == BYTEORDER::BIG)
		ByteOrder_UInt64<BYTEORDER::BIG>(v, 1);
	else
		ByteOrder_UInt64<BYTEORDER::LITTLE>(v, 1);
	return OK;
}

Result<UInt64> IoFileInputHelper::ReadUInt64()
{
	iferr_scope;
	UInt64 v;
	ReadUInt64(&v) iferr_return;
	return v;
}

Result<void> IoFileInputHelper::ReadFloat32(Float32* v)
{
	iferr (Read(ToBlock(v, 1)))
		return err;
	if (_byteOrder == BYTEORDER::BIG)
		ByteOrder_UInt32<BYTEORDER::BIG>((UInt32*)v, 1);
	else
		ByteOrder_UInt32<BYTEORDER::LITTLE>((UInt32*)v, 1);
	return OK;
}

Result<Float32> IoFileInputHelper::ReadFloat32()
{
	iferr_scope;
	Float32 v;
	ReadFloat32(&v) iferr_return;
	return v;
}

Result<void> IoFileInputHelper::ReadFloat64(Float64* v)
{
	iferr (Read(ToBlock(v, 1)))
		return err;
	if (_byteOrder == BYTEORDER::BIG)
		ByteOrder_UInt64<BYTEORDER::BIG>((UInt64*)v, 1);
	else
		ByteOrder_UInt64<BYTEORDER::LITTLE>((UInt64*)v, 1);
	return OK;
}

Result<Float64> IoFileInputHelper::ReadFloat64()
{
	iferr_scope;
	Float64 v;
	ReadFloat64(&v) iferr_return;
	return v;
}

} // namespace maxon
