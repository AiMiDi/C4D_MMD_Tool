
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1

struct ReadArchiveInterface::MTable
{
	PRIVATE_MAXON_IMPLEMENTS_CHECK(Close);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(Extract);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(ExtractSingleFile);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(Open);
	static const maxon::Char* const _ids;
	static const maxon::Bool HAS_NONSTATIC = false;
	Result<void> (*_ReadArchiveInterface_Open) (maxon::GenericComponent* this_, const Url& inputFile, const String& password);
	maxon::Int _ReadArchiveInterface_Open_Offset;
	Result<void> (*_ReadArchiveInterface_Close) (maxon::GenericComponent* this_);
	maxon::Int _ReadArchiveInterface_Close_Offset;
	Result<Url> (*_ReadArchiveInterface_ExtractSingleFile) (maxon::GenericComponent* this_, const String& archiveFile, const Url& outputDirectory, ThreadRef thread, IOARCHIVEEXTRACTFLAGS flags, const ExtractCallback& extractCallback);
	maxon::Int _ReadArchiveInterface_ExtractSingleFile_Offset;
	Result<void> (*_ReadArchiveInterface_Extract) (maxon::GenericComponent* this_, const Url& outputDirectory, ThreadRef thread, IOARCHIVEEXTRACTFLAGS flags, const ExtractCallback& extractCallback);
	maxon::Int _ReadArchiveInterface_Extract_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ReadArchiveInterface, Open))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ReadArchiveInterface, Open), W, MTable>::type::_ReadArchiveInterface_Open;
			_ReadArchiveInterface_Open = reinterpret_cast<const decltype(_ReadArchiveInterface_Open)&>(ptr);
			_ReadArchiveInterface_Open_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ReadArchiveInterface, Close))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ReadArchiveInterface, Close), W, MTable>::type::_ReadArchiveInterface_Close;
			_ReadArchiveInterface_Close = reinterpret_cast<const decltype(_ReadArchiveInterface_Close)&>(ptr);
			_ReadArchiveInterface_Close_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ReadArchiveInterface, ExtractSingleFile))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ReadArchiveInterface, ExtractSingleFile), W, MTable>::type::_ReadArchiveInterface_ExtractSingleFile;
			_ReadArchiveInterface_ExtractSingleFile = reinterpret_cast<const decltype(_ReadArchiveInterface_ExtractSingleFile)&>(ptr);
			_ReadArchiveInterface_ExtractSingleFile_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ReadArchiveInterface, Extract))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ReadArchiveInterface, Extract), W, MTable>::type::_ReadArchiveInterface_Extract;
			_ReadArchiveInterface_Extract = reinterpret_cast<const decltype(_ReadArchiveInterface_Extract)&>(ptr);
			_ReadArchiveInterface_Extract_Offset = offset;
		}
	}
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset)
	{
		if (!W::Implementation::PROXY && (!ObjectInterface::MTable::template InitWithBases<W>(info, offset))) return false;
		MTable* vt = (MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, _interface); if (!vt) return false;
		vt->Init<W>(offset); return true;
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<ReadArchiveInterface, typename ObjectInterface::MTable::template CombinedMTable<S>>;
	PRIVATE_MAXON_COMPBASE(ReadArchiveInterface);
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct ReadArchiveInterface::Hxx2
{
	template <typename S> class Wrapper : public ObjectInterface::Hxx2::template Wrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(Close);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(Extract);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(ExtractSingleFile);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(Open);
	static Result<void> _ReadArchiveInterface_Open(maxon::GenericComponent* this_, const Url& inputFile, const String& password) { return ((typename S::Implementation*) this_)->Open(inputFile, password); }
	static Result<void> _ReadArchiveInterface_Close(maxon::GenericComponent* this_) { return ((typename S::Implementation*) this_)->Close(); }
	static Result<Url> _ReadArchiveInterface_ExtractSingleFile(maxon::GenericComponent* this_, const String& archiveFile, const Url& outputDirectory, ThreadRef thread, IOARCHIVEEXTRACTFLAGS flags, const ExtractCallback& extractCallback) { return ((typename S::Implementation*) this_)->ExtractSingleFile(archiveFile, outputDirectory, std::forward<ThreadRef>(thread), flags, extractCallback); }
	static Result<void> _ReadArchiveInterface_Extract(maxon::GenericComponent* this_, const Url& outputDirectory, ThreadRef thread, IOARCHIVEEXTRACTFLAGS flags, const ExtractCallback& extractCallback) { return ((typename S::Implementation*) this_)->Extract(outputDirectory, std::forward<ThreadRef>(thread), flags, extractCallback); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto ReadArchiveInterface::Open(const Url& inputFile, const String& password) -> Result<void>
{
	const ReadArchiveInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ReadArchiveInterface, this); return mt_._ReadArchiveInterface_Open((maxon::GenericComponent*) this + mt_._ReadArchiveInterface_Open_Offset, inputFile, password);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ReadArchiveInterface::Close() -> Result<void>
{
	const ReadArchiveInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ReadArchiveInterface, this); return mt_._ReadArchiveInterface_Close((maxon::GenericComponent*) this + mt_._ReadArchiveInterface_Close_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ReadArchiveInterface::ExtractSingleFile(const String& archiveFile, const Url& outputDirectory, ThreadRef thread, IOARCHIVEEXTRACTFLAGS flags, const ExtractCallback& extractCallback) -> Result<Url>
{
	const ReadArchiveInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ReadArchiveInterface, this); return mt_._ReadArchiveInterface_ExtractSingleFile((maxon::GenericComponent*) this + mt_._ReadArchiveInterface_ExtractSingleFile_Offset, archiveFile, outputDirectory, std::forward<ThreadRef>(thread), flags, extractCallback);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ReadArchiveInterface::Extract(const Url& outputDirectory, ThreadRef thread, IOARCHIVEEXTRACTFLAGS flags, const ExtractCallback& extractCallback) -> Result<void>
{
	const ReadArchiveInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ReadArchiveInterface, this); return mt_._ReadArchiveInterface_Extract((maxon::GenericComponent*) this + mt_._ReadArchiveInterface_Extract_Offset, outputDirectory, std::forward<ThreadRef>(thread), flags, extractCallback);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ReadArchiveInterface::Hxx1::ReferenceFunctionsImpl<S>::Open(const Url& inputFile, const String& password) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ReadArchiveInterface* o_ = (ReadArchiveInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ReadArchiveInterface, o_, ReadArchiveInterface_Open) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<ReadArchiveInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ReadArchiveInterface>() : PRIVATE_MAXON_VTABLE(ReadArchiveInterface, o_); 
	return (mt_._ReadArchiveInterface_Open(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._ReadArchiveInterface_Open_Offset, inputFile, password));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ReadArchiveInterface::Hxx1::COWReferenceFunctionsImpl<S>::Open(const Url& inputFile, const String& password) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ReadArchiveInterface* o_ = (ReadArchiveInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ReadArchiveInterface, o_, ReadArchiveInterface_Open) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<ReadArchiveInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ReadArchiveInterface>() : PRIVATE_MAXON_VTABLE(ReadArchiveInterface, o_); 
	return (mt_._ReadArchiveInterface_Open(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._ReadArchiveInterface_Open_Offset, inputFile, password));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ReadArchiveInterface::Hxx1::ReferenceFunctionsImpl<S>::Close() const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ReadArchiveInterface* o_ = (ReadArchiveInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ReadArchiveInterface, o_, ReadArchiveInterface_Close) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<ReadArchiveInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ReadArchiveInterface>() : PRIVATE_MAXON_VTABLE(ReadArchiveInterface, o_); 
	return (mt_._ReadArchiveInterface_Close(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._ReadArchiveInterface_Close_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ReadArchiveInterface::Hxx1::COWReferenceFunctionsImpl<S>::Close() -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ReadArchiveInterface* o_ = (ReadArchiveInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ReadArchiveInterface, o_, ReadArchiveInterface_Close) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<ReadArchiveInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ReadArchiveInterface>() : PRIVATE_MAXON_VTABLE(ReadArchiveInterface, o_); 
	return (mt_._ReadArchiveInterface_Close(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._ReadArchiveInterface_Close_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ReadArchiveInterface::Hxx1::ReferenceFunctionsImpl<S>::ExtractSingleFile(const String& archiveFile, const Url& outputDirectory, ThreadRef thread, IOARCHIVEEXTRACTFLAGS flags, const ExtractCallback& extractCallback) const -> Result<Url>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Url>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ReadArchiveInterface* o_ = (ReadArchiveInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ReadArchiveInterface, o_, ReadArchiveInterface_ExtractSingleFile) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<ReadArchiveInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ReadArchiveInterface>() : PRIVATE_MAXON_VTABLE(ReadArchiveInterface, o_); 
	return (mt_._ReadArchiveInterface_ExtractSingleFile(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._ReadArchiveInterface_ExtractSingleFile_Offset, archiveFile, outputDirectory, std::forward<ThreadRef>(thread), flags, extractCallback));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ReadArchiveInterface::Hxx1::COWReferenceFunctionsImpl<S>::ExtractSingleFile(const String& archiveFile, const Url& outputDirectory, ThreadRef thread, IOARCHIVEEXTRACTFLAGS flags, const ExtractCallback& extractCallback) -> Result<Url>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Url>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ReadArchiveInterface* o_ = (ReadArchiveInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ReadArchiveInterface, o_, ReadArchiveInterface_ExtractSingleFile) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<ReadArchiveInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ReadArchiveInterface>() : PRIVATE_MAXON_VTABLE(ReadArchiveInterface, o_); 
	return (mt_._ReadArchiveInterface_ExtractSingleFile(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._ReadArchiveInterface_ExtractSingleFile_Offset, archiveFile, outputDirectory, std::forward<ThreadRef>(thread), flags, extractCallback));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ReadArchiveInterface::Hxx1::ReferenceFunctionsImpl<S>::Extract(const Url& outputDirectory, ThreadRef thread, IOARCHIVEEXTRACTFLAGS flags, const ExtractCallback& extractCallback) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ReadArchiveInterface* o_ = (ReadArchiveInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ReadArchiveInterface, o_, ReadArchiveInterface_Extract) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<ReadArchiveInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ReadArchiveInterface>() : PRIVATE_MAXON_VTABLE(ReadArchiveInterface, o_); 
	return (mt_._ReadArchiveInterface_Extract(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._ReadArchiveInterface_Extract_Offset, outputDirectory, std::forward<ThreadRef>(thread), flags, extractCallback));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ReadArchiveInterface::Hxx1::COWReferenceFunctionsImpl<S>::Extract(const Url& outputDirectory, ThreadRef thread, IOARCHIVEEXTRACTFLAGS flags, const ExtractCallback& extractCallback) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ReadArchiveInterface* o_ = (ReadArchiveInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ReadArchiveInterface, o_, ReadArchiveInterface_Extract) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<ReadArchiveInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ReadArchiveInterface>() : PRIVATE_MAXON_VTABLE(ReadArchiveInterface, o_); 
	return (mt_._ReadArchiveInterface_Extract(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._ReadArchiveInterface_Extract_Offset, outputDirectory, std::forward<ThreadRef>(thread), flags, extractCallback));
}
auto ReadArchiveInterface::GetPtr() -> Ptr { return Ptr(this); }
auto ReadArchiveInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_ReadArchiveInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_ReadArchiveInterface() { new (s_ui_maxon_ReadArchiveInterface) maxon::EntityUse(ReadArchiveInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/ioarchivehandler.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_ReadArchiveInterface(ReadArchiveInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/ioarchivehandler.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif

struct WriteArchiveInterface::MTable
{
	PRIVATE_MAXON_IMPLEMENTS_CHECK(Close);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(CloseFile);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(CopyFile);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(CreateDirectory);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(CreateFile);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetCompressionLevel);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(Open);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(SetCompressionLevel);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(WriteFile);
	static const maxon::Char* const _ids;
	static const maxon::Bool HAS_NONSTATIC = false;
	Result<void> (*_WriteArchiveInterface_Open) (maxon::GenericComponent* this_, const Url& inputFile, Bool append, const String& password);
	maxon::Int _WriteArchiveInterface_Open_Offset;
	Result<void> (*_WriteArchiveInterface_Close) (maxon::GenericComponent* this_);
	maxon::Int _WriteArchiveInterface_Close_Offset;
	Result<void> (*_WriteArchiveInterface_SetCompressionLevel) (maxon::GenericComponent* this_, Int compressionLevel);
	maxon::Int _WriteArchiveInterface_SetCompressionLevel_Offset;
	Int (*_WriteArchiveInterface_GetCompressionLevel) (const maxon::GenericComponent* this_);
	maxon::Int _WriteArchiveInterface_GetCompressionLevel_Offset;
	Result<void> (*_WriteArchiveInterface_CreateDirectory) (maxon::GenericComponent* this_, const String& name, const UniversalDateTime& dateTime, IOATTRIBUTES fileAttributes);
	maxon::Int _WriteArchiveInterface_CreateDirectory_Offset;
	Result<void> (*_WriteArchiveInterface_CreateFile) (maxon::GenericComponent* this_, const String& name, const UniversalDateTime& dateTime, IOARCHIVESTOREMETHOD method, IOATTRIBUTES fileAttributes, UInt32 cryptCrc);
	maxon::Int _WriteArchiveInterface_CreateFile_Offset;
	Result<void> (*_WriteArchiveInterface_WriteFile) (maxon::GenericComponent* this_, const Block<const Byte>& data);
	maxon::Int _WriteArchiveInterface_WriteFile_Offset;
	Result<void> (*_WriteArchiveInterface_CloseFile) (maxon::GenericComponent* this_);
	maxon::Int _WriteArchiveInterface_CloseFile_Offset;
	Result<void> (*_WriteArchiveInterface_CopyFile) (maxon::GenericComponent* this_, const Url& fn, const String& str, IOATTRIBUTES fileAttributes, IOATTRIBUTES fileAttributesMask);
	maxon::Int _WriteArchiveInterface_CopyFile_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, WriteArchiveInterface, Open))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, WriteArchiveInterface, Open), W, MTable>::type::_WriteArchiveInterface_Open;
			_WriteArchiveInterface_Open = reinterpret_cast<const decltype(_WriteArchiveInterface_Open)&>(ptr);
			_WriteArchiveInterface_Open_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, WriteArchiveInterface, Close))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, WriteArchiveInterface, Close), W, MTable>::type::_WriteArchiveInterface_Close;
			_WriteArchiveInterface_Close = reinterpret_cast<const decltype(_WriteArchiveInterface_Close)&>(ptr);
			_WriteArchiveInterface_Close_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, WriteArchiveInterface, SetCompressionLevel))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, WriteArchiveInterface, SetCompressionLevel), W, MTable>::type::_WriteArchiveInterface_SetCompressionLevel;
			_WriteArchiveInterface_SetCompressionLevel = reinterpret_cast<const decltype(_WriteArchiveInterface_SetCompressionLevel)&>(ptr);
			_WriteArchiveInterface_SetCompressionLevel_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, WriteArchiveInterface, GetCompressionLevel))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, WriteArchiveInterface, GetCompressionLevel), W, MTable>::type::_WriteArchiveInterface_GetCompressionLevel;
			_WriteArchiveInterface_GetCompressionLevel = reinterpret_cast<const decltype(_WriteArchiveInterface_GetCompressionLevel)&>(ptr);
			_WriteArchiveInterface_GetCompressionLevel_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, WriteArchiveInterface, CreateDirectory))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, WriteArchiveInterface, CreateDirectory), W, MTable>::type::_WriteArchiveInterface_CreateDirectory;
			_WriteArchiveInterface_CreateDirectory = reinterpret_cast<const decltype(_WriteArchiveInterface_CreateDirectory)&>(ptr);
			_WriteArchiveInterface_CreateDirectory_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, WriteArchiveInterface, CreateFile))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, WriteArchiveInterface, CreateFile), W, MTable>::type::_WriteArchiveInterface_CreateFile;
			_WriteArchiveInterface_CreateFile = reinterpret_cast<const decltype(_WriteArchiveInterface_CreateFile)&>(ptr);
			_WriteArchiveInterface_CreateFile_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, WriteArchiveInterface, WriteFile))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, WriteArchiveInterface, WriteFile), W, MTable>::type::_WriteArchiveInterface_WriteFile;
			_WriteArchiveInterface_WriteFile = reinterpret_cast<const decltype(_WriteArchiveInterface_WriteFile)&>(ptr);
			_WriteArchiveInterface_WriteFile_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, WriteArchiveInterface, CloseFile))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, WriteArchiveInterface, CloseFile), W, MTable>::type::_WriteArchiveInterface_CloseFile;
			_WriteArchiveInterface_CloseFile = reinterpret_cast<const decltype(_WriteArchiveInterface_CloseFile)&>(ptr);
			_WriteArchiveInterface_CloseFile_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, WriteArchiveInterface, CopyFile))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, WriteArchiveInterface, CopyFile), W, MTable>::type::_WriteArchiveInterface_CopyFile;
			_WriteArchiveInterface_CopyFile = reinterpret_cast<const decltype(_WriteArchiveInterface_CopyFile)&>(ptr);
			_WriteArchiveInterface_CopyFile_Offset = offset;
		}
	}
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset)
	{
		if (!W::Implementation::PROXY && (!ObjectInterface::MTable::template InitWithBases<W>(info, offset))) return false;
		MTable* vt = (MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, _interface); if (!vt) return false;
		vt->Init<W>(offset); return true;
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<WriteArchiveInterface, typename ObjectInterface::MTable::template CombinedMTable<S>>;
	PRIVATE_MAXON_COMPBASE(WriteArchiveInterface);
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct WriteArchiveInterface::Hxx2
{
	template <typename S> class Wrapper : public ObjectInterface::Hxx2::template Wrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(Close);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(CloseFile);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(CopyFile);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(CreateDirectory);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(CreateFile);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetCompressionLevel);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(Open);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(SetCompressionLevel);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(WriteFile);
	static Result<void> _WriteArchiveInterface_Open(maxon::GenericComponent* this_, const Url& inputFile, Bool append, const String& password) { return ((typename S::Implementation*) this_)->Open(inputFile, append, password); }
	static Result<void> _WriteArchiveInterface_Close(maxon::GenericComponent* this_) { return ((typename S::Implementation*) this_)->Close(); }
	static Result<void> _WriteArchiveInterface_SetCompressionLevel(maxon::GenericComponent* this_, Int compressionLevel) { return ((typename S::Implementation*) this_)->SetCompressionLevel(compressionLevel); }
	static Int _WriteArchiveInterface_GetCompressionLevel(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetCompressionLevel(); }
	static Result<void> _WriteArchiveInterface_CreateDirectory(maxon::GenericComponent* this_, const String& name, const UniversalDateTime& dateTime, IOATTRIBUTES fileAttributes) { return ((typename S::Implementation*) this_)->CreateDirectory(name, dateTime, fileAttributes); }
	static Result<void> _WriteArchiveInterface_CreateFile(maxon::GenericComponent* this_, const String& name, const UniversalDateTime& dateTime, IOARCHIVESTOREMETHOD method, IOATTRIBUTES fileAttributes, UInt32 cryptCrc) { return ((typename S::Implementation*) this_)->CreateFile(name, dateTime, method, fileAttributes, cryptCrc); }
	static Result<void> _WriteArchiveInterface_WriteFile(maxon::GenericComponent* this_, const Block<const Byte>& data) { return ((typename S::Implementation*) this_)->WriteFile(data); }
	static Result<void> _WriteArchiveInterface_CloseFile(maxon::GenericComponent* this_) { return ((typename S::Implementation*) this_)->CloseFile(); }
	static Result<void> _WriteArchiveInterface_CopyFile(maxon::GenericComponent* this_, const Url& fn, const String& str, IOATTRIBUTES fileAttributes, IOATTRIBUTES fileAttributesMask) { return ((typename S::Implementation*) this_)->CopyFile(fn, str, fileAttributes, fileAttributesMask); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto WriteArchiveInterface::Open(const Url& inputFile, Bool append, const String& password) -> Result<void>
{
	const WriteArchiveInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(WriteArchiveInterface, this); return mt_._WriteArchiveInterface_Open((maxon::GenericComponent*) this + mt_._WriteArchiveInterface_Open_Offset, inputFile, append, password);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto WriteArchiveInterface::Close() -> Result<void>
{
	const WriteArchiveInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(WriteArchiveInterface, this); return mt_._WriteArchiveInterface_Close((maxon::GenericComponent*) this + mt_._WriteArchiveInterface_Close_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto WriteArchiveInterface::SetCompressionLevel(Int compressionLevel) -> Result<void>
{
	const WriteArchiveInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(WriteArchiveInterface, this); return mt_._WriteArchiveInterface_SetCompressionLevel((maxon::GenericComponent*) this + mt_._WriteArchiveInterface_SetCompressionLevel_Offset, compressionLevel);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto WriteArchiveInterface::GetCompressionLevel() const -> Int
{
	const WriteArchiveInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(WriteArchiveInterface, this); return mt_._WriteArchiveInterface_GetCompressionLevel((const maxon::GenericComponent*) this + mt_._WriteArchiveInterface_GetCompressionLevel_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto WriteArchiveInterface::CreateDirectory(const String& name, const UniversalDateTime& dateTime, IOATTRIBUTES fileAttributes) -> Result<void>
{
	const WriteArchiveInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(WriteArchiveInterface, this); return mt_._WriteArchiveInterface_CreateDirectory((maxon::GenericComponent*) this + mt_._WriteArchiveInterface_CreateDirectory_Offset, name, dateTime, fileAttributes);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto WriteArchiveInterface::CreateFile(const String& name, const UniversalDateTime& dateTime, IOARCHIVESTOREMETHOD method, IOATTRIBUTES fileAttributes, UInt32 cryptCrc) -> Result<void>
{
	const WriteArchiveInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(WriteArchiveInterface, this); return mt_._WriteArchiveInterface_CreateFile((maxon::GenericComponent*) this + mt_._WriteArchiveInterface_CreateFile_Offset, name, dateTime, method, fileAttributes, cryptCrc);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto WriteArchiveInterface::WriteFile(const Block<const Byte>& data) -> Result<void>
{
	const WriteArchiveInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(WriteArchiveInterface, this); return mt_._WriteArchiveInterface_WriteFile((maxon::GenericComponent*) this + mt_._WriteArchiveInterface_WriteFile_Offset, data);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto WriteArchiveInterface::CloseFile() -> Result<void>
{
	const WriteArchiveInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(WriteArchiveInterface, this); return mt_._WriteArchiveInterface_CloseFile((maxon::GenericComponent*) this + mt_._WriteArchiveInterface_CloseFile_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto WriteArchiveInterface::CopyFile(const Url& fn, const String& str, IOATTRIBUTES fileAttributes, IOATTRIBUTES fileAttributesMask) -> Result<void>
{
	const WriteArchiveInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(WriteArchiveInterface, this); return mt_._WriteArchiveInterface_CopyFile((maxon::GenericComponent*) this + mt_._WriteArchiveInterface_CopyFile_Offset, fn, str, fileAttributes, fileAttributesMask);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto WriteArchiveInterface::Hxx1::ReferenceFunctionsImpl<S>::Open(const Url& inputFile, Bool append, const String& password) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); WriteArchiveInterface* o_ = (WriteArchiveInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(WriteArchiveInterface, o_, WriteArchiveInterface_Open) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<WriteArchiveInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<WriteArchiveInterface>() : PRIVATE_MAXON_VTABLE(WriteArchiveInterface, o_); 
	return (mt_._WriteArchiveInterface_Open(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._WriteArchiveInterface_Open_Offset, inputFile, append, password));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto WriteArchiveInterface::Hxx1::COWReferenceFunctionsImpl<S>::Open(const Url& inputFile, Bool append, const String& password) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); WriteArchiveInterface* o_ = (WriteArchiveInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(WriteArchiveInterface, o_, WriteArchiveInterface_Open) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<WriteArchiveInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<WriteArchiveInterface>() : PRIVATE_MAXON_VTABLE(WriteArchiveInterface, o_); 
	return (mt_._WriteArchiveInterface_Open(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._WriteArchiveInterface_Open_Offset, inputFile, append, password));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto WriteArchiveInterface::Hxx1::ReferenceFunctionsImpl<S>::Close() const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); WriteArchiveInterface* o_ = (WriteArchiveInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(WriteArchiveInterface, o_, WriteArchiveInterface_Close) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<WriteArchiveInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<WriteArchiveInterface>() : PRIVATE_MAXON_VTABLE(WriteArchiveInterface, o_); 
	return (mt_._WriteArchiveInterface_Close(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._WriteArchiveInterface_Close_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto WriteArchiveInterface::Hxx1::COWReferenceFunctionsImpl<S>::Close() -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); WriteArchiveInterface* o_ = (WriteArchiveInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(WriteArchiveInterface, o_, WriteArchiveInterface_Close) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<WriteArchiveInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<WriteArchiveInterface>() : PRIVATE_MAXON_VTABLE(WriteArchiveInterface, o_); 
	return (mt_._WriteArchiveInterface_Close(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._WriteArchiveInterface_Close_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto WriteArchiveInterface::Hxx1::ReferenceFunctionsImpl<S>::SetCompressionLevel(Int compressionLevel) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); WriteArchiveInterface* o_ = (WriteArchiveInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(WriteArchiveInterface, o_, WriteArchiveInterface_SetCompressionLevel) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<WriteArchiveInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<WriteArchiveInterface>() : PRIVATE_MAXON_VTABLE(WriteArchiveInterface, o_); 
	return (mt_._WriteArchiveInterface_SetCompressionLevel(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._WriteArchiveInterface_SetCompressionLevel_Offset, compressionLevel));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto WriteArchiveInterface::Hxx1::COWReferenceFunctionsImpl<S>::SetCompressionLevel(Int compressionLevel) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); WriteArchiveInterface* o_ = (WriteArchiveInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(WriteArchiveInterface, o_, WriteArchiveInterface_SetCompressionLevel) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<WriteArchiveInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<WriteArchiveInterface>() : PRIVATE_MAXON_VTABLE(WriteArchiveInterface, o_); 
	return (mt_._WriteArchiveInterface_SetCompressionLevel(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._WriteArchiveInterface_SetCompressionLevel_Offset, compressionLevel));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto WriteArchiveInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetCompressionLevel() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const WriteArchiveInterface* o_ = (const WriteArchiveInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = WriteArchiveInterface::NullValuePtr(); if (!o_) return 0; } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(WriteArchiveInterface, o_, WriteArchiveInterface_GetCompressionLevel) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<WriteArchiveInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<WriteArchiveInterface>() : PRIVATE_MAXON_VTABLE(WriteArchiveInterface, o_); 
	return (mt_._WriteArchiveInterface_GetCompressionLevel(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._WriteArchiveInterface_GetCompressionLevel_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto WriteArchiveInterface::Hxx1::ReferenceFunctionsImpl<S>::CreateDirectory(const String& name, const UniversalDateTime& dateTime, IOATTRIBUTES fileAttributes) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); WriteArchiveInterface* o_ = (WriteArchiveInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(WriteArchiveInterface, o_, WriteArchiveInterface_CreateDirectory) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<WriteArchiveInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<WriteArchiveInterface>() : PRIVATE_MAXON_VTABLE(WriteArchiveInterface, o_); 
	return (mt_._WriteArchiveInterface_CreateDirectory(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._WriteArchiveInterface_CreateDirectory_Offset, name, dateTime, fileAttributes));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto WriteArchiveInterface::Hxx1::COWReferenceFunctionsImpl<S>::CreateDirectory(const String& name, const UniversalDateTime& dateTime, IOATTRIBUTES fileAttributes) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); WriteArchiveInterface* o_ = (WriteArchiveInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(WriteArchiveInterface, o_, WriteArchiveInterface_CreateDirectory) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<WriteArchiveInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<WriteArchiveInterface>() : PRIVATE_MAXON_VTABLE(WriteArchiveInterface, o_); 
	return (mt_._WriteArchiveInterface_CreateDirectory(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._WriteArchiveInterface_CreateDirectory_Offset, name, dateTime, fileAttributes));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto WriteArchiveInterface::Hxx1::ReferenceFunctionsImpl<S>::CreateFile(const String& name, const UniversalDateTime& dateTime, IOARCHIVESTOREMETHOD method, IOATTRIBUTES fileAttributes, UInt32 cryptCrc) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); WriteArchiveInterface* o_ = (WriteArchiveInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(WriteArchiveInterface, o_, WriteArchiveInterface_CreateFile) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<WriteArchiveInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<WriteArchiveInterface>() : PRIVATE_MAXON_VTABLE(WriteArchiveInterface, o_); 
	return (mt_._WriteArchiveInterface_CreateFile(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._WriteArchiveInterface_CreateFile_Offset, name, dateTime, method, fileAttributes, cryptCrc));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto WriteArchiveInterface::Hxx1::COWReferenceFunctionsImpl<S>::CreateFile(const String& name, const UniversalDateTime& dateTime, IOARCHIVESTOREMETHOD method, IOATTRIBUTES fileAttributes, UInt32 cryptCrc) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); WriteArchiveInterface* o_ = (WriteArchiveInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(WriteArchiveInterface, o_, WriteArchiveInterface_CreateFile) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<WriteArchiveInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<WriteArchiveInterface>() : PRIVATE_MAXON_VTABLE(WriteArchiveInterface, o_); 
	return (mt_._WriteArchiveInterface_CreateFile(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._WriteArchiveInterface_CreateFile_Offset, name, dateTime, method, fileAttributes, cryptCrc));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto WriteArchiveInterface::Hxx1::ReferenceFunctionsImpl<S>::WriteFile(const Block<const Byte>& data) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); WriteArchiveInterface* o_ = (WriteArchiveInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(WriteArchiveInterface, o_, WriteArchiveInterface_WriteFile) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<WriteArchiveInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<WriteArchiveInterface>() : PRIVATE_MAXON_VTABLE(WriteArchiveInterface, o_); 
	return (mt_._WriteArchiveInterface_WriteFile(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._WriteArchiveInterface_WriteFile_Offset, data));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto WriteArchiveInterface::Hxx1::COWReferenceFunctionsImpl<S>::WriteFile(const Block<const Byte>& data) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); WriteArchiveInterface* o_ = (WriteArchiveInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(WriteArchiveInterface, o_, WriteArchiveInterface_WriteFile) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<WriteArchiveInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<WriteArchiveInterface>() : PRIVATE_MAXON_VTABLE(WriteArchiveInterface, o_); 
	return (mt_._WriteArchiveInterface_WriteFile(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._WriteArchiveInterface_WriteFile_Offset, data));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto WriteArchiveInterface::Hxx1::ReferenceFunctionsImpl<S>::CloseFile() const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); WriteArchiveInterface* o_ = (WriteArchiveInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(WriteArchiveInterface, o_, WriteArchiveInterface_CloseFile) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<WriteArchiveInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<WriteArchiveInterface>() : PRIVATE_MAXON_VTABLE(WriteArchiveInterface, o_); 
	return (mt_._WriteArchiveInterface_CloseFile(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._WriteArchiveInterface_CloseFile_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto WriteArchiveInterface::Hxx1::COWReferenceFunctionsImpl<S>::CloseFile() -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); WriteArchiveInterface* o_ = (WriteArchiveInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(WriteArchiveInterface, o_, WriteArchiveInterface_CloseFile) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<WriteArchiveInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<WriteArchiveInterface>() : PRIVATE_MAXON_VTABLE(WriteArchiveInterface, o_); 
	return (mt_._WriteArchiveInterface_CloseFile(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._WriteArchiveInterface_CloseFile_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto WriteArchiveInterface::Hxx1::ReferenceFunctionsImpl<S>::CopyFile(const Url& fn, const String& str, IOATTRIBUTES fileAttributes, IOATTRIBUTES fileAttributesMask) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); WriteArchiveInterface* o_ = (WriteArchiveInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(WriteArchiveInterface, o_, WriteArchiveInterface_CopyFile) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<WriteArchiveInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<WriteArchiveInterface>() : PRIVATE_MAXON_VTABLE(WriteArchiveInterface, o_); 
	return (mt_._WriteArchiveInterface_CopyFile(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._WriteArchiveInterface_CopyFile_Offset, fn, str, fileAttributes, fileAttributesMask));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto WriteArchiveInterface::Hxx1::COWReferenceFunctionsImpl<S>::CopyFile(const Url& fn, const String& str, IOATTRIBUTES fileAttributes, IOATTRIBUTES fileAttributesMask) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); WriteArchiveInterface* o_ = (WriteArchiveInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(WriteArchiveInterface, o_, WriteArchiveInterface_CopyFile) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<WriteArchiveInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<WriteArchiveInterface>() : PRIVATE_MAXON_VTABLE(WriteArchiveInterface, o_); 
	return (mt_._WriteArchiveInterface_CopyFile(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._WriteArchiveInterface_CopyFile_Offset, fn, str, fileAttributes, fileAttributesMask));
}
auto WriteArchiveInterface::GetPtr() -> Ptr { return Ptr(this); }
auto WriteArchiveInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_WriteArchiveInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_WriteArchiveInterface() { new (s_ui_maxon_WriteArchiveInterface) maxon::EntityUse(WriteArchiveInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/ioarchivehandler.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_WriteArchiveInterface(WriteArchiveInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/ioarchivehandler.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

