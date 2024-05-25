#ifdef __API_INTERN__
	#error "Not in the kernel"
#endif

#include "ge_math.h"
#include "c4d_file.h"

#ifdef CINEWARE_NAMESPACE_ENABLE
	CINEWARE_NAMESPACE_BEGIN
#endif

#define FnCall(fnc) (this->*C4DOS_Fn->fnc)
#define FlCall(fnc) (this->*C4DOS_Fl->fnc)
#define HfCall(fnc) (this->*C4DOS_Hf->fnc)

Filename::Filename()
{
	C4DOS_Fn->Init(this);
}

Filename::Filename(const Char* string)
{
	C4DOS_Fn->Init(this);
	C4DOS_Fn->SetCString(this, string);
}

Filename::Filename(const maxon::String& string)
{
	C4DOS_Fn->Init(this);
	C4DOS_Fn->SetString(this, string);
}

Filename::Filename(const Filename& src)
{
	C4DOS_Fn->Init(this);
	C4DOS_Fn->CopyTo(&src, this);
}

Filename::~Filename()
{
	C4DOS_Fn->Flush(this);
}

void Filename::CopyTo(Filename* dst) const
{
	C4DOS_Fn->CopyTo(this, dst);
}

Bool Filename::FileSelect(FILESELECTTYPE type, FILESELECT flags, const maxon::String& title, const maxon::String& force_suffix)
{
	return FnCall(FileSelect) (type, flags, title, force_suffix);
}

maxon::Result<Bool> Filename::FileSelectMultiple(FILESELECT flags, const maxon::String& title, const maxon::Url& startUrl, const maxon::Id& settingsIdentifier, const maxon::Block<maxon::Tuple<maxon::String, maxon::String>>& filterStrings, const maxon::ValueReceiver<const maxon::Url&>& selectedUrls)
{
	return C4DOS_Fn->FileSelectMultiple(flags, title, startUrl, settingsIdentifier, filterStrings, selectedUrls);
}


Bool Filename::IsPopulated() const
{
	return C4DOS_Fn->IsPopulated(this);
}

String Filename::GetString() const
{
	return C4DOS_Fn->GetString(this);
}

void Filename::SetString(const maxon::String& str)
{
	C4DOS_Fn->SetString(this, str);
}

const Filename Filename::GetDirectory() const
{
	return C4DOS_Fn->GetDirectory(this);
}

const Filename Filename::GetFile() const
{
	return C4DOS_Fn->GetFile(this);
}

String Filename::GetFileString() const
{
	return GetFile().GetString();
}

void Filename::ClearSuffix()
{
	C4DOS_Fn->ClearSuffix(this);
}

void Filename::ClearSuffixComplete()
{
	C4DOS_Fn->ClearSuffixComplete(this);
}

void Filename::SetSuffix(const maxon::String& str)
{
	C4DOS_Fn->SetSuffix(this, str);
}

Bool Filename::CheckSuffix(const maxon::String& str) const
{
	return C4DOS_Fn->CheckSuffix(this, str);
}

String Filename::GetSuffix() const
{
	return C4DOS_Fn->GetSuffix(this);
}

Bool Filename::IsBrowserUrl() const
{
	return FnCall(IsBrowserUrl)();
}

void Filename::SetDirectory(const Filename& str)
{
	C4DOS_Fn->SetDirectory(this, &str);
}

void Filename::SetFile(const Filename& str)
{
	C4DOS_Fn->SetFile(this, &str);
}

const Filename& Filename::operator = (const Filename& cs)
{
	C4DOS_Fn->CopyTo(&cs, this);
	return *this;
}

const Filename operator + (const Filename& Str1, const Filename& Str2)
{
	Filename fn = Str1;
	C4DOS_Fn->Add(&fn, &Str2);
	return fn;
}

const Filename& Filename::operator += (const Filename& Str)
{
	C4DOS_Fn->Add(this, &Str);
	return *this;
}

Bool Filename::operator == (const Filename& Str) const
{
	return C4DOS_Fn->Compare(this, &Str);
}

Bool Filename::operator != (const Filename& Str) const
{
	return !C4DOS_Fn->Compare(this, &Str);
}

void Filename::SetMemoryReadMode(void* adr, Int size, Bool transferOwnership)
{
	C4DOS_Fn->SetMemoryReadMode(this, adr, size, transferOwnership);
}

void Filename::SetMemoryWriteMode(MemoryFileStruct* mfs)
{
	C4DOS_Fn->SetMemoryWriteMode(this, mfs);
}

MemoryFileStruct* MemoryFileStruct::Alloc()
{
	return C4DOS_Fn->MemoryFileStructAlloc();
}

void MemoryFileStruct::Free(MemoryFileStruct*& mfs)
{
	C4DOS_Fn->MemoryFileStructFree(mfs);
}

void MemoryFileStruct::GetData(void*& data, Int& size) const
{
	C4DOS_Fn->MemoryFileStructGetData((MemoryFileStruct*)this, data, size, false);
}

void MemoryFileStruct::GetData(void*& data, Int& size, Bool release)
{
	C4DOS_Fn->MemoryFileStructGetData(this, data, size, release);
}


BaseFile* BaseFile::Alloc()
{
	return C4DOS_Fl->Alloc();
}

void BaseFile::Free(BaseFile*& fl)
{
	C4DOS_Fl->Free(fl);
	fl = nullptr;
}

Bool BaseFile::Open(const Filename& name, FILEOPEN mode, FILEDIALOG error_dialog, BYTEORDER order, Int32 type, Int32 creator)
{
	return FlCall(Open) (name, mode, error_dialog, order, type, creator);
}

Bool BaseFile::Close()
{
	return FlCall(Close) ();
}

void BaseFile::SetOrder(BYTEORDER order)
{
	FlCall(SetOrder) (order);
}

Int BaseFile::ReadBytes(void* data, Int len, Bool just_try_it)
{
	return FlCall(ReadBytes) (data, len, just_try_it);
}

Bool BaseFile::WriteBytes(const void* data, Int len)
{
	return FlCall(WriteBytes) (data, len);
}

Int BaseFile::TryReadBytes(void* data, Int len)
{
	return FlCall(ReadBytes) (data, len, true);
}

Bool BaseFile::Seek(Int64 pos, FILESEEK mode)
{
	return FlCall(Seek) (pos, mode);
}

Int64 BaseFile::GetPosition()
{
	return FlCall(GetPosition) ();
}

Int64 BaseFile::GetLength()
{
	return FlCall(GetLength) ();
}

LOCATION BaseFile::GetLocation() const
{
	return FlCall(GetLocation) ();
}

FILEERROR BaseFile::GetError() const
{
	return FlCall(GetError) ();
}

void BaseFile::SetError(FILEERROR error)
{
	FlCall(SetError) (error);
}

Bool BaseFile::ReadChar (Char* v)
{
	return FlCall(ReadChar) (v);
}

Bool BaseFile::ReadUChar(UChar* v)
{
	return FlCall(ReadUChar) (v);
}

Bool BaseFile::ReadInt16 (Int16* v)
{
	return FlCall(ReadInt16) (v);
}

Bool BaseFile::ReadUInt16(UInt16* v)
{
	return FlCall(ReadUInt16) (v);
}

Bool BaseFile::ReadInt32 (Int32* v)
{
	return FlCall(ReadInt32) (v);
}

Bool BaseFile::ReadUInt32(UInt32* v)
{
	return FlCall(ReadUInt32) (v);
}

Bool BaseFile::ReadInt64(Int64* v)
{
	return FlCall(ReadInt64) (v);
}

Bool BaseFile::ReadUInt64(UInt64* v)
{
	return FlCall(ReadUInt64) (v);
}

Bool BaseFile::ReadFloat64(Float64* v)
{
	return FlCall(ReadFloat64) (v);
}

Bool BaseFile::ReadFloat32(Float32* v)
{
	return FlCall(ReadFloat32) (v);
}

Bool BaseFile::ReadVector32(Vector32* v)
{
	return ReadFloat32(&v->x) && ReadFloat32(&v->y) && ReadFloat32(&v->z);
}

Bool BaseFile::WriteVector32(const Vector32& v)
{
	return WriteFloat32(v.x) && WriteFloat32(v.y) && WriteFloat32(v.z);
}

Bool BaseFile::ReadVector64(Vector64* v)
{
	return ReadFloat64(&v->x) && ReadFloat64(&v->y) && ReadFloat64(&v->z);
}

Bool BaseFile::WriteVector64(const Vector64& v)
{
	return WriteFloat64(v.x) && WriteFloat64(v.y) && WriteFloat64(v.z);
}

Bool BaseFile::ReadMatrix32(Matrix32* v)
{
	return ReadVector32(&v->off) && ReadVector32(&v->sqmat.v1) && ReadVector32(&v->sqmat.v2) && ReadVector32(&v->sqmat.v3);
}

Bool BaseFile::WriteMatrix32(const Matrix32& v)
{
	return WriteVector32(v.off) && WriteVector32(v.sqmat.v1) && WriteVector32(v.sqmat.v2) && WriteVector32(v.sqmat.v3);
}

Bool BaseFile::ReadMatrix64(Matrix64* v)
{
	return ReadVector64(&v->off) && ReadVector64(&v->sqmat.v1) && ReadVector64(&v->sqmat.v2) && ReadVector64(&v->sqmat.v3);
}

Bool BaseFile::WriteMatrix64(const Matrix64& v)
{
	return WriteVector64(v.off) && WriteVector64(v.sqmat.v1) && WriteVector64(v.sqmat.v2) && WriteVector64(v.sqmat.v3);
}

Bool BaseFile::ReadString(maxon::String* v)
{
	Int32 len = 0;

	if (!ReadInt32(&len))
		return false;
	if (!len)
	{
		*v = String();
		return true;
	}

	maxon::BaseArray<Char> buf;
	
	iferr (buf.Resize(len, maxon::COLLECTION_RESIZE_FLAGS::ON_GROW_UNINITIALIZED))
	{
		SetError(FILEERROR::OUTOFMEMORY);
		return false;
	}
	if (!ReadBytes(buf.GetFirst(), len))
		return false;

	iferr (v->SetCString(buf.GetFirst(), len - 1))
		return false;

	return true;
}

Bool BaseFile::ReadFilename(Filename* v)
{
	String str;
	if (!ReadString(&str))
		return false;
	v->SetString(str);
	return true;
}

Bool BaseFile::ReadBool(Bool* v)
{
	Char c;
	if (!ReadChar(&c))
		return false;
	*v = c != 0;
	return true;
}

Bool BaseFile::WriteBool(Bool v)
{
	return WriteChar(Char(v != 0));
}

Bool BaseFile::WriteString(const maxon::String& v)
{
	iferr (maxon::BaseArray<Char> buf = v.GetCString())
	{
		SetError(FILEERROR::OUTOFMEMORY);
		return false;
	}

	// The BaseArray returned by GetCString() has a terminating null byte after GetCount() bytes.
	Int32 lenIncludingTerminator = Int32(buf.GetCount()) + 1;
	Bool ok = WriteInt32(lenIncludingTerminator) && WriteBytes(buf.GetFirst(), lenIncludingTerminator);

	return ok;
}

Bool BaseFile::WriteFilename(const Filename& v)
{
	return WriteString(v.GetString());
}

Bool BaseFile::WriteChar (Char v)
{
	return FlCall(WriteChar) (v);
}

Bool BaseFile::WriteUChar(UChar v)
{
	return FlCall(WriteUChar) (v);
}

Bool BaseFile::WriteInt16 (Int16 v)
{
	return FlCall(WriteInt16) (v);
}

Bool BaseFile::WriteUInt16(UInt16 v)
{
	return FlCall(WriteUInt16) (v);
}

Bool BaseFile::WriteInt32 (Int32 v)
{
	return FlCall(WriteInt32) (v);
}

Bool BaseFile::WriteInt64(Int64 v)
{
	return FlCall(WriteInt64) (v);
}

Bool BaseFile::WriteUInt32(UInt32 v)
{
	return FlCall(WriteUInt32) (v);
}

Bool BaseFile::WriteUInt64(UInt64 v)
{
	return FlCall(WriteUInt64) (v);
}

Bool BaseFile::WriteFloat64(Float64 v)
{
	return FlCall(WriteFloat64) (v);
}

Bool BaseFile::WriteFloat32(Float32 v)
{
	return FlCall(WriteFloat32) (v);
}


AESFile* AESFile::Alloc()
{
	return C4DOS_Fl->AESAlloc();
}

void AESFile::Free(AESFile*& fl)
{
	C4DOS_Fl->Free(static_cast<BaseFile*>(fl));
	fl = nullptr;
}

Bool AESFile::Open(const Filename& name, const char* key, Int32 keylen, Int32 blocksize, UInt32 aes_flags, FILEOPEN mode, FILEDIALOG error_dialog, BYTEORDER order, Int32 type, Int32 creator)
{
	return FlCall(AESOpen) (name, key, keylen, blocksize, aes_flags, mode, error_dialog, order, type, creator);
}

Bool AESFile::CheckEncryption(const Filename& encrypt, const Filename& decrypt, const char* key, Int32 keylen, Int32 blocksize)
{
	return C4DOS_Fl->AESCheckEncryption(encrypt, decrypt, key, keylen, blocksize);
}

BrowseVolumes* BrowseVolumes::Alloc()
{
	return C4DOS_Bf->BvAlloc();
}

void BrowseVolumes::Init()
{
	(this->*C4DOS_Bf->BvInit)();
}

void BrowseVolumes::Free(BrowseVolumes*& bf)
{
	C4DOS_Bf->BvFree(bf);
	bf = nullptr;
}

Bool BrowseVolumes::GetNext()
{
	return (this->*C4DOS_Bf->BvGetNext)();
}

Filename BrowseVolumes::GetFilename()
{
	return (this->*C4DOS_Bf->BvGetFilename)();
}

String BrowseVolumes::GetVolumeName(Int32* out_flags)
{
	return (this->*C4DOS_Bf->BvGetVolumeName)(out_flags);
}

BrowseFiles* BrowseFiles::Alloc()
{
	return C4DOS_Bf->Alloc(nullptr, 0);
}

void BrowseFiles::Init(const Filename& directory, Int32 flags)
{
	C4DOS_Bf->Init(this, &directory, flags);
}

void BrowseFiles::Free(BrowseFiles*& bf)
{
	C4DOS_Bf->Free(bf);
	bf = nullptr;
}

Bool BrowseFiles::GetNext()
{
	return (this->*C4DOS_Bf->GetNext)();
}

Int64 BrowseFiles::GetSize()
{
	return (this->*C4DOS_Bf->GetSize)();
}

Bool BrowseFiles::IsDir()
{
	return (this->*C4DOS_Bf->IsDir)();
}

Bool BrowseFiles::IsHidden()
{
	return (this->*C4DOS_Bf->IsHidden)();
}

Bool BrowseFiles::IsReadOnly()
{
	return (this->*C4DOS_Bf->IsReadOnly)();
}

Bool BrowseFiles::IsBundle()
{
	return (this->*C4DOS_Bf->IsBundle)();
}

void BrowseFiles::GetFileTime(Int32 mode, LocalFileTime* out)
{
	(this->*C4DOS_Bf->GetFileTime)(mode, out);
}

Filename BrowseFiles::GetFilename()
{
	return (this->*C4DOS_Bf->GetFilename)();
}

Bool GeGetFileTime(const Filename& name, Int32 mode, LocalFileTime* out)
{
	return C4DOS_Ge->GetFileTime(name, mode, out);
}

Bool GeSetFileTime(const Filename& name, Int32 mode, const LocalFileTime* in)
{
	return C4DOS_Ge->SetFileTime(name, mode, in);
}

void GeGetCurrentTime(LocalFileTime* out)
{
	C4DOS_Ge->GetCurrentTime(out);
}

Bool GeFExist(const Filename& name, Bool isdir)
{
	return C4DOS_Ge->FExist(&name, isdir);
}

Bool GeSearchFile(const Filename& directory, const Filename& name, Filename* found)
{
	return C4DOS_Ge->SearchFile(&directory, &name, found);
}

Bool GeFKill(const Filename& name, Int32 flags)
{
	return C4DOS_Ge->FKill(&name, flags);
}

Bool GeFCopyFile(const Filename& source, const Filename& dest, Int32 flags)
{
	return C4DOS_Ge->FCopyFile(&source, &dest, flags);
}

Bool GeFRename(const Filename& source, const Filename& dest)
{
	return C4DOS_Ge->FRename(&source, &dest);
}

Bool GeFMove(const Filename& source, const Filename& dest)
{
	return C4DOS_Ge->FMove(source, dest);
}

Bool GeFCreateDir(const Filename& name)
{
	return C4DOS_Ge->FCreateDir(&name);
}

Bool GeFCreateDirRec(const Filename& fn)
{
	Filename parent = fn.GetDirectory();

	if (!parent.IsPopulated())
		return false;

	if (!GeFExist(parent, true))
	{
		if (!GeFCreateDirRec(parent))
			return false;
	}

	if (!GeFExist(fn, true))
	{
		if (!GeFCreateDir(fn))
		{
			return false;
		}
	}
	return true;
}

Bool GeExecuteFile(const Filename& path)
{
	return C4DOS_Ge->ExecuteFile(&path);
}

Bool GeExecuteProgram(const Filename& program, const Filename& img)
{
	return C4DOS_Ge->ExecuteProgram(&program, &img);
}

Bool GeFGetDiskFreeSpace(const Filename& vol, UInt64& freecaller, UInt64& total, UInt64& freespace)
{
	return C4DOS_Ge->GeFGetDiskFreeSpace(vol, freecaller, total, freespace);
}

UInt32 GeFGetAttributes(const Filename& name)
{
	return C4DOS_Ge->GeFGetAttributes(&name);
}

Bool GeFSetAttributes(const Filename& name, UInt32 flags, UInt32 mask)
{
	return C4DOS_Ge->GeFSetAttributes(&name, flags, mask);
}

const Filename GeGetStartupPath()
{
	return C4DOS_Ge->GetStartupPath();
}

const Filename GeGetStartupApplication()
{
	return C4DOS_Ge->GetStartupApplication();
}

Bool RequestFileFromServer(const Filename& fn, Filename& res)
{
	return C4DOS_Ge->RequestFileFromServer(fn, res);
}

const Filename GeGetPluginPath()
{
	extern Filename* path_storage;

	return path_storage ? path_storage->GetDirectory() : Filename();
}

const Filename GeGetC4DPath(Int32 whichpath)
{
	return C4DOS_Ge->GetC4DPath(whichpath);
}

const Filename GeGetStartupWritePath()
{
	return GeGetC4DPath(C4D_PATH_STARTUPWRITE);
}

HyperFile* HyperFile::Alloc()
{
	return C4DOS_Hf->AllocHF();
}

void HyperFile::Free(HyperFile*& fl)
{
	C4DOS_Hf->FreeHF(fl);
	fl = nullptr;
}

Bool HyperFile::Open(Int32 ident, const Filename& filename, FILEOPEN mode, FILEDIALOG error_mode)
{
	return HfCall(Open) (ident, filename, mode, error_mode);
}

Bool HyperFile::Close()
{
	return HfCall(Close) ();
}

BaseDocument* HyperFile::GetDocument() const
{
	return HfCall(GetDocument) ();
}

Bool HyperFile::ReadChar (Char* v)
{
	return HfCall(ReadChar) (v);
}

Bool HyperFile::ReadUChar(UChar* v)
{
	return HfCall(ReadUChar) (v);
}

Bool HyperFile::ReadInt16 (Int16* v)
{
	return HfCall(ReadInt16) (v);
}

Bool HyperFile::ReadUInt16(UInt16* v)
{
	return HfCall(ReadUInt16) (v);
}

Bool HyperFile::ReadInt32 (Int32* v)
{
	return HfCall(ReadInt32) (v);
}

Bool HyperFile::ReadUInt32(UInt32* v)
{
	return HfCall(ReadUInt32) (v);
}

Bool HyperFile::ReadInt64(Int64* v)
{
	return HfCall(ReadInt64) (v);
}

Bool HyperFile::ReadUInt64(UInt64* v)
{
	return HfCall(ReadUInt64) (v);
}

Bool HyperFile::ReadFloat (Float* v)
{
	return HfCall(ReadFloat) (v);
}

Bool HyperFile::ReadFloat64(Float64* v)
{
	return HfCall(ReadFloat64) (v);
}

Bool HyperFile::ReadFloat32(Float32* v)
{
	return HfCall(ReadFloat32) (v);
}

Bool HyperFile::ReadBool(Bool* v)
{
	return HfCall(ReadBool) (v);
}

Bool HyperFile::ReadTime(BaseTime* v)
{
	return HfCall(ReadTime) (v);
}

Bool HyperFile::ReadVector(Vector* v)
{
	return HfCall(ReadVector) (v);
}

Bool HyperFile::ReadVector64(Vector64* v)
{
	return HfCall(ReadVector64) (v);
}

Bool HyperFile::ReadVector32(Vector32* v)
{
	return HfCall(ReadVector32) (v);
}

Bool HyperFile::ReadMatrix(Matrix* v)
{
	return HfCall(ReadMatrix) (v);
}

Bool HyperFile::ReadMatrix64(Matrix64* v)
{
	return HfCall(ReadMatrix64) (v);
}

Bool HyperFile::ReadMatrix32(Matrix32* v)
{
	return HfCall(ReadMatrix32) (v);
}

Bool HyperFile::ReadString(maxon::String* v)
{
	return HfCall(ReadString) (v);
}

Bool HyperFile::ReadFilename(Filename* v)
{
	return HfCall(ReadFilename) (v);
}

Bool HyperFile::ReadGeData(GeData* v)
{
	return C4DOS_Hf->ReadGeData(this, *v);
}

Bool HyperFile::ReadUuid(C4DUuid* v)
{
	return HfCall(ReadUuid) (v);
}

Bool HyperFile::ReadContainer(BaseContainer* v, Bool flush)
{
	return HfCall(ReadContainer) (v, flush);
}

Bool HyperFile::ReadMemory(void** data, Int* size)
{
	return HfCall(ReadMemory) (data, size);
}

Bool HyperFile::ReadImage(BaseBitmap* v)
{
	return HfCall(ReadImage) (v);
}

Bool HyperFile::ReadChannelConvert(GeListNode* node, Int32 link_id)
{
	return C4DOS_Ba->ReadDataConvert(node, link_id, this);
}

Bool HyperFile::WriteChar (Char v)
{
	return HfCall(WriteChar) (v);
}

Bool HyperFile::WriteUChar(UChar v)
{
	return HfCall(WriteUChar) (v);
}

Bool HyperFile::WriteInt16 (Int16 v)
{
	return HfCall(WriteInt16) (v);
}

Bool HyperFile::WriteUInt16(UInt16 v)
{
	return HfCall(WriteUInt16) (v);
}

Bool HyperFile::WriteInt32 (Int32 v)
{
	return HfCall(WriteInt32) (v);
}

Bool HyperFile::WriteUInt32(UInt32 v)
{
	return HfCall(WriteUInt32) (v);
}

Bool HyperFile::WriteInt64(Int64 v)
{
	return HfCall(WriteInt64) (v);
}

Bool HyperFile::WriteUInt64(UInt64 v)
{
	return HfCall(WriteUInt64) (v);
}

Bool HyperFile::WriteFloat(Float v)
{
	return HfCall(WriteFloat) (v);
}

Bool HyperFile::WriteFloat32(Float32 v)
{
	return HfCall(WriteFloat32) (v);
}

Bool HyperFile::WriteFloat64(Float64 v)
{
	return HfCall(WriteFloat64) (v);
}

Bool HyperFile::WriteBool(Bool v)
{
	return HfCall(WriteBool) (v);
}

Bool HyperFile::WriteTime(const BaseTime& v)
{
	return HfCall(WriteTime) (v);
}

Bool HyperFile::WriteVector(const Vector& v)
{
	return HfCall(WriteVector) (v);
}

Bool HyperFile::WriteVector32(const Vector32& v)
{
	return HfCall(WriteVector32) (v);
}

Bool HyperFile::WriteVector64(const Vector64& v)
{
	return HfCall(WriteVector64) (v);
}

Bool HyperFile::WriteMatrix(const Matrix& v)
{
	return HfCall(WriteMatrix) (v);
}

Bool HyperFile::WriteMatrix32(const Matrix32& v)
{
	return HfCall(WriteMatrix32) (v);
}

Bool HyperFile::WriteMatrix64(const Matrix64& v)
{
	return HfCall(WriteMatrix64) (v);
}

Bool HyperFile::WriteString(const maxon::String& v)
{
	return HfCall(WriteString) (v);
}

Bool HyperFile::WriteFilename(const Filename& v)
{
	return HfCall(WriteFilename) (v);
}

Bool HyperFile::WriteImage(const BaseBitmap* v, Int32 format, BaseContainer* data, SAVEBIT savebits)
{
	return HfCall(WriteImage) (v, format, data, savebits);
}

Bool HyperFile::WriteContainer(const BaseContainer& v)
{
	return HfCall(WriteContainer) (v);
}

Bool HyperFile::WriteGeData(const GeData& v)
{
	return C4DOS_Hf->WriteGeData(this, v);
}

Bool HyperFile::WriteUuid(const C4DUuid& v)
{
	return HfCall(WriteUuid) (v);
}

Bool HyperFile::WriteArray(const void* data, HYPERFILEARRAY datatype, Int32 structure_increment, Int32 count)
{
	return HfCall(WriteArray) (data, datatype, structure_increment, count);
}

Bool HyperFile::ReadArray(void* data, HYPERFILEARRAY datatype, Int32 structure_increment, Int32 count)
{
	return HfCall(ReadArray) (data, datatype, structure_increment, count);
}

Bool HyperFile::WriteMemory(const void* data, Int count)
{
	return HfCall(WriteMemory) (data, count);
}

FILEERROR HyperFile::GetError() const
{
	return HfCall(GetError) ();
}

void HyperFile::SetError(FILEERROR err)
{
	HfCall(SetError) (err);
}

Bool HyperFile::ReadValueHeader(HYPERFILEVALUE* h)
{
	return HfCall(ReadValueHeader) (h);
}

Bool HyperFile::SkipValue(HYPERFILEVALUE h)
{
	return HfCall(SkipValue) (h);
}

Bool HyperFile::WriteChunkStart(Int32 id, Int32 level)
{
	return HfCall(WriteChunkStart) (id, level);
}

Bool HyperFile::WriteChunkEnd()
{
	return HfCall(WriteChunkEnd) ();
}

Bool HyperFile::ReadChunkStart(Int32* id, Int32* level)
{
	return HfCall(ReadChunkStart) (id, level);
}

Bool HyperFile::ReadChunkEnd()
{
	return HfCall(ReadChunkEnd) ();
}

LOCATION HyperFile::GetLocation() const
{
	return HfCall(GetLocation) ();
}

Bool HyperFile::SkipToEndChunk()
{
	return HfCall(SkipToEndChunk) ();
}

Int32 HyperFile::GetFileVersion() const
{
	return HfCall(GetFileVersion) ();
}

void HyperFile::SetFileVersion(Int32 val)
{
	return HfCall(SetFileVersion) (val);
}

SCENEFILTER HyperFile::GetFilterFlags() const
{
	return HfCall(GetFilterFlags) ();
}

FILEERROR ReadHyperFile(BaseDocument* doc, GeListNode* node, const Filename& filename, Int32 ident, maxon::String* warning_string)
{
	return C4DOS_Hf->ReadFile(doc, node, filename, ident, warning_string);
}

FILEERROR WriteHyperFile(BaseDocument* doc, GeListNode* node, const Filename& filename, Int32 ident)
{
	return C4DOS_Hf->WriteFile(doc, node, filename, ident);
}

String DateToString(const LocalFileTime& t, Bool date_only)
{
	return C4DOS_Ge->DateToString(t, date_only);
}

Bool ShowInFinder(const Filename& fn, Bool open)
{
	return C4DOS_Ge->ShowInFinder(fn, open);
}

maxon::String ToString(const Filename& val, const maxon::FormatStatement* formatStatement, maxon::Bool checkDatatype)
{
	return MaxonConvert(val.GetString());
}

Filename MaxonConvert(const maxon::Url& val)
{
	Filename url;
	*(maxon::Url*)&url = val;
	return url;
}

#ifdef MAXON_TARGET_LINUX

#include "maxon/iobrowse.h"
#include "maxon/iostreams.h"

maxon::Result<maxon::Url> CheckRealFilenameIgnoringCase(const maxon::Url& url, Bool onlyDir)
{
	iferr_scope;

	if (url.IsPopulated() && url.GetScheme() == maxon::URLSCHEME_FILESYSTEM)
	{
		maxon::IODETECT detect = url.IoDetect();
		if (detect == maxon::IODETECT::DIRECTORY || (!onlyDir && detect == maxon::IODETECT::FILE))
			return url;

		maxon::Url dir = url.GetDirectory();
		maxon::String file = url.GetName();

		if (dir.IsPopulated())
		{
			dir = CheckRealFilenameIgnoringCase(dir, true) iferr_return;
		}

		for (const auto& it : dir.GetBrowseIterator(maxon::GETBROWSEITERATORFLAGS::NONE))
		{
			maxon::Url current = it.GetCurrentPath() iferr_return;
			if (current.GetName().Compare(file, maxon::STRINGCOMPARISON::CASEINSENSITIVE) == maxon::COMPARERESULT::EQUAL)
			{
				return current;
			}
		}
	}
	return maxon::IoError(MAXON_SOURCE_LOCATION, url, "url not found"_s);
}
#endif

maxon::Url MaxonConvert(const Filename& val, MAXONCONVERTMODE mode)
{
	maxon::Url url = *(maxon::Url*)&val;
#ifdef MAXON_TARGET_LINUX
	if (mode == MAXONCONVERTMODE::READ)
	{
		ifnoerr (maxon::Url converted = CheckRealFilenameIgnoringCase(url, false))
			return converted;
	}
	else if (mode == MAXONCONVERTMODE::WRITE)
	{
		maxon::Url dir = url.GetDirectory();
		maxon::String name = url.GetName();
		ifnoerr (maxon::Url converted = CheckRealFilenameIgnoringCase(dir, true))
		{
			ifnoerr (converted.Append(name))
			{
				return converted;
			}
		}
	}
	return url;
#else
	// no std::move to use RVO
	return url;
#endif
}

#ifdef CINEWARE_NAMESPACE_ENABLE
	CINEWARE_NAMESPACE_END
#endif
