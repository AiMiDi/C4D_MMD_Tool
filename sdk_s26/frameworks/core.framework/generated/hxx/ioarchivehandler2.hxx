
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
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	Result<void> (*ReadArchiveInterface_Open) (maxon::GenericComponent* this_, const Url& inputFile, const String& password);
	maxon::Int ReadArchiveInterface_Open_Offset;
	Result<void> (*ReadArchiveInterface_Close) (maxon::GenericComponent* this_);
	maxon::Int ReadArchiveInterface_Close_Offset;
	Result<Url> (*ReadArchiveInterface_ExtractSingleFile) (maxon::GenericComponent* this_, const String& archiveFile, const Url& outputDirectory, ThreadRef thread, IOARCHIVEEXTRACTFLAGS flags, const ExtractCallback& extractCallback);
	maxon::Int ReadArchiveInterface_ExtractSingleFile_Offset;
	Result<void> (*ReadArchiveInterface_Extract) (maxon::GenericComponent* this_, const Url& outputDirectory, ThreadRef thread, IOARCHIVEEXTRACTFLAGS flags, const ExtractCallback& extractCallback);
	maxon::Int ReadArchiveInterface_Extract_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ReadArchiveInterface, Open))
	{
		ReadArchiveInterface_Open = &W::ReadArchiveInterface_Open;
		ReadArchiveInterface_Open_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ReadArchiveInterface, Close))
	{
		ReadArchiveInterface_Close = &W::ReadArchiveInterface_Close;
		ReadArchiveInterface_Close_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ReadArchiveInterface, ExtractSingleFile))
	{
		ReadArchiveInterface_ExtractSingleFile = &W::ReadArchiveInterface_ExtractSingleFile;
		ReadArchiveInterface_ExtractSingleFile_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ReadArchiveInterface, Extract))
	{
		ReadArchiveInterface_Extract = &W::ReadArchiveInterface_Extract;
		ReadArchiveInterface_Extract_Offset = offset;
	}
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<ReadArchiveInterface, typename ObjectInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<ReadArchiveInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct ReadArchiveInterface::Hxx2
{
	template <typename S> class CWrapper : public ObjectInterface::Hxx2::template CWrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(Close);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(Extract);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(ExtractSingleFile);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(Open);
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename ObjectInterface::Hxx2::template CWrapper<S>;
			if (!S::Implementation::PROXY && !(Super0::InitMTablesWithBases(info, offset))) return false;
			auto* vt = (ReadArchiveInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, ReadArchiveInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		static Result<void> ReadArchiveInterface_Open(maxon::GenericComponent* this_, const Url& inputFile, const String& password) { return ((typename S::Implementation*) this_)->Open(inputFile, password); }
		static Result<void> ReadArchiveInterface_Close(maxon::GenericComponent* this_) { return ((typename S::Implementation*) this_)->Close(); }
		static Result<Url> ReadArchiveInterface_ExtractSingleFile(maxon::GenericComponent* this_, const String& archiveFile, const Url& outputDirectory, ThreadRef thread, IOARCHIVEEXTRACTFLAGS flags, const ExtractCallback& extractCallback) { return ((typename S::Implementation*) this_)->ExtractSingleFile(archiveFile, outputDirectory, std::forward<ThreadRef>(thread), flags, extractCallback); }
		static Result<void> ReadArchiveInterface_Extract(maxon::GenericComponent* this_, const Url& outputDirectory, ThreadRef thread, IOARCHIVEEXTRACTFLAGS flags, const ExtractCallback& extractCallback) { return ((typename S::Implementation*) this_)->Extract(outputDirectory, std::forward<ThreadRef>(thread), flags, extractCallback); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto ReadArchiveInterface::Open(const Url& inputFile, const String& password) -> Result<void>
{
	const ReadArchiveInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ReadArchiveInterface, this); return mt_.ReadArchiveInterface_Open((maxon::GenericComponent*) this + mt_.ReadArchiveInterface_Open_Offset, inputFile, password);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ReadArchiveInterface::Close() -> Result<void>
{
	const ReadArchiveInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ReadArchiveInterface, this); return mt_.ReadArchiveInterface_Close((maxon::GenericComponent*) this + mt_.ReadArchiveInterface_Close_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ReadArchiveInterface::ExtractSingleFile(const String& archiveFile, const Url& outputDirectory, ThreadRef thread, IOARCHIVEEXTRACTFLAGS flags, const ExtractCallback& extractCallback) -> Result<Url>
{
	const ReadArchiveInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ReadArchiveInterface, this); return mt_.ReadArchiveInterface_ExtractSingleFile((maxon::GenericComponent*) this + mt_.ReadArchiveInterface_ExtractSingleFile_Offset, archiveFile, outputDirectory, std::forward<ThreadRef>(thread), flags, extractCallback);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ReadArchiveInterface::Extract(const Url& outputDirectory, ThreadRef thread, IOARCHIVEEXTRACTFLAGS flags, const ExtractCallback& extractCallback) -> Result<void>
{
	const ReadArchiveInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ReadArchiveInterface, this); return mt_.ReadArchiveInterface_Extract((maxon::GenericComponent*) this + mt_.ReadArchiveInterface_Extract_Offset, outputDirectory, std::forward<ThreadRef>(thread), flags, extractCallback);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ReadArchiveInterface::Hxx1::Fn<S>::Open(const Url& inputFile, const String& password) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ReadArchiveInterface* o_ = (ReadArchiveInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ReadArchiveInterface, o_, ReadArchiveInterface_Open) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ReadArchiveInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ReadArchiveInterface>() : PRIVATE_MAXON_VTABLE(ReadArchiveInterface, o_); 
	return (mt_.ReadArchiveInterface_Open(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ReadArchiveInterface_Open_Offset, inputFile, password));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ReadArchiveInterface::Hxx1::COWFn<S>::Open(const Url& inputFile, const String& password) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ReadArchiveInterface* o_ = (ReadArchiveInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ReadArchiveInterface, o_, ReadArchiveInterface_Open) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ReadArchiveInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ReadArchiveInterface>() : PRIVATE_MAXON_VTABLE(ReadArchiveInterface, o_); 
	return (mt_.ReadArchiveInterface_Open(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ReadArchiveInterface_Open_Offset, inputFile, password));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ReadArchiveInterface::Hxx1::Fn<S>::Close() const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ReadArchiveInterface* o_ = (ReadArchiveInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ReadArchiveInterface, o_, ReadArchiveInterface_Close) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ReadArchiveInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ReadArchiveInterface>() : PRIVATE_MAXON_VTABLE(ReadArchiveInterface, o_); 
	return (mt_.ReadArchiveInterface_Close(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ReadArchiveInterface_Close_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ReadArchiveInterface::Hxx1::COWFn<S>::Close() -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ReadArchiveInterface* o_ = (ReadArchiveInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ReadArchiveInterface, o_, ReadArchiveInterface_Close) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ReadArchiveInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ReadArchiveInterface>() : PRIVATE_MAXON_VTABLE(ReadArchiveInterface, o_); 
	return (mt_.ReadArchiveInterface_Close(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ReadArchiveInterface_Close_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ReadArchiveInterface::Hxx1::Fn<S>::ExtractSingleFile(const String& archiveFile, const Url& outputDirectory, ThreadRef thread, IOARCHIVEEXTRACTFLAGS flags, const ExtractCallback& extractCallback) const -> Result<Url>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Url>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ReadArchiveInterface* o_ = (ReadArchiveInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ReadArchiveInterface, o_, ReadArchiveInterface_ExtractSingleFile) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ReadArchiveInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ReadArchiveInterface>() : PRIVATE_MAXON_VTABLE(ReadArchiveInterface, o_); 
	return (mt_.ReadArchiveInterface_ExtractSingleFile(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ReadArchiveInterface_ExtractSingleFile_Offset, archiveFile, outputDirectory, std::forward<ThreadRef>(thread), flags, extractCallback));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ReadArchiveInterface::Hxx1::COWFn<S>::ExtractSingleFile(const String& archiveFile, const Url& outputDirectory, ThreadRef thread, IOARCHIVEEXTRACTFLAGS flags, const ExtractCallback& extractCallback) -> Result<Url>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Url>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ReadArchiveInterface* o_ = (ReadArchiveInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ReadArchiveInterface, o_, ReadArchiveInterface_ExtractSingleFile) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ReadArchiveInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ReadArchiveInterface>() : PRIVATE_MAXON_VTABLE(ReadArchiveInterface, o_); 
	return (mt_.ReadArchiveInterface_ExtractSingleFile(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ReadArchiveInterface_ExtractSingleFile_Offset, archiveFile, outputDirectory, std::forward<ThreadRef>(thread), flags, extractCallback));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ReadArchiveInterface::Hxx1::Fn<S>::Extract(const Url& outputDirectory, ThreadRef thread, IOARCHIVEEXTRACTFLAGS flags, const ExtractCallback& extractCallback) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ReadArchiveInterface* o_ = (ReadArchiveInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ReadArchiveInterface, o_, ReadArchiveInterface_Extract) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ReadArchiveInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ReadArchiveInterface>() : PRIVATE_MAXON_VTABLE(ReadArchiveInterface, o_); 
	return (mt_.ReadArchiveInterface_Extract(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ReadArchiveInterface_Extract_Offset, outputDirectory, std::forward<ThreadRef>(thread), flags, extractCallback));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ReadArchiveInterface::Hxx1::COWFn<S>::Extract(const Url& outputDirectory, ThreadRef thread, IOARCHIVEEXTRACTFLAGS flags, const ExtractCallback& extractCallback) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ReadArchiveInterface* o_ = (ReadArchiveInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ReadArchiveInterface, o_, ReadArchiveInterface_Extract) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ReadArchiveInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ReadArchiveInterface>() : PRIVATE_MAXON_VTABLE(ReadArchiveInterface, o_); 
	return (mt_.ReadArchiveInterface_Extract(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ReadArchiveInterface_Extract_Offset, outputDirectory, std::forward<ThreadRef>(thread), flags, extractCallback));
}
auto ReadArchiveInterface::GetPtr() -> Ptr { return Ptr(this); }
auto ReadArchiveInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_ioarchivehandler)
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
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	Result<void> (*WriteArchiveInterface_Open) (maxon::GenericComponent* this_, const Url& inputFile, Bool append, const String& password);
	maxon::Int WriteArchiveInterface_Open_Offset;
	Result<void> (*WriteArchiveInterface_Close) (maxon::GenericComponent* this_);
	maxon::Int WriteArchiveInterface_Close_Offset;
	Result<void> (*WriteArchiveInterface_SetCompressionLevel) (maxon::GenericComponent* this_, Int compressionLevel);
	maxon::Int WriteArchiveInterface_SetCompressionLevel_Offset;
	Int (*WriteArchiveInterface_GetCompressionLevel) (const maxon::GenericComponent* this_);
	maxon::Int WriteArchiveInterface_GetCompressionLevel_Offset;
	Result<void> (*WriteArchiveInterface_CreateDirectory) (maxon::GenericComponent* this_, const String& name, const UniversalDateTime& dateTime, IOATTRIBUTES fileAttributes);
	maxon::Int WriteArchiveInterface_CreateDirectory_Offset;
	Result<void> (*WriteArchiveInterface_CreateFile) (maxon::GenericComponent* this_, const String& name, const UniversalDateTime& dateTime, IOARCHIVESTOREMETHOD method, IOATTRIBUTES fileAttributes, UInt32 cryptCrc);
	maxon::Int WriteArchiveInterface_CreateFile_Offset;
	Result<void> (*WriteArchiveInterface_WriteFile) (maxon::GenericComponent* this_, const Block<const Byte>& data);
	maxon::Int WriteArchiveInterface_WriteFile_Offset;
	Result<void> (*WriteArchiveInterface_CloseFile) (maxon::GenericComponent* this_);
	maxon::Int WriteArchiveInterface_CloseFile_Offset;
	Result<void> (*WriteArchiveInterface_CopyFile) (maxon::GenericComponent* this_, const Url& fn, const String& str, IOATTRIBUTES fileAttributes, IOATTRIBUTES fileAttributesMask);
	maxon::Int WriteArchiveInterface_CopyFile_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, WriteArchiveInterface, Open))
	{
		WriteArchiveInterface_Open = &W::WriteArchiveInterface_Open;
		WriteArchiveInterface_Open_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, WriteArchiveInterface, Close))
	{
		WriteArchiveInterface_Close = &W::WriteArchiveInterface_Close;
		WriteArchiveInterface_Close_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, WriteArchiveInterface, SetCompressionLevel))
	{
		WriteArchiveInterface_SetCompressionLevel = &W::WriteArchiveInterface_SetCompressionLevel;
		WriteArchiveInterface_SetCompressionLevel_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, WriteArchiveInterface, GetCompressionLevel))
	{
		WriteArchiveInterface_GetCompressionLevel = &W::WriteArchiveInterface_GetCompressionLevel;
		WriteArchiveInterface_GetCompressionLevel_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, WriteArchiveInterface, CreateDirectory))
	{
		WriteArchiveInterface_CreateDirectory = &W::WriteArchiveInterface_CreateDirectory;
		WriteArchiveInterface_CreateDirectory_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, WriteArchiveInterface, CreateFile))
	{
		WriteArchiveInterface_CreateFile = &W::WriteArchiveInterface_CreateFile;
		WriteArchiveInterface_CreateFile_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, WriteArchiveInterface, WriteFile))
	{
		WriteArchiveInterface_WriteFile = &W::WriteArchiveInterface_WriteFile;
		WriteArchiveInterface_WriteFile_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, WriteArchiveInterface, CloseFile))
	{
		WriteArchiveInterface_CloseFile = &W::WriteArchiveInterface_CloseFile;
		WriteArchiveInterface_CloseFile_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, WriteArchiveInterface, CopyFile))
	{
		WriteArchiveInterface_CopyFile = &W::WriteArchiveInterface_CopyFile;
		WriteArchiveInterface_CopyFile_Offset = offset;
	}
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<WriteArchiveInterface, typename ObjectInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<WriteArchiveInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct WriteArchiveInterface::Hxx2
{
	template <typename S> class CWrapper : public ObjectInterface::Hxx2::template CWrapper<S>
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
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename ObjectInterface::Hxx2::template CWrapper<S>;
			if (!S::Implementation::PROXY && !(Super0::InitMTablesWithBases(info, offset))) return false;
			auto* vt = (WriteArchiveInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, WriteArchiveInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		static Result<void> WriteArchiveInterface_Open(maxon::GenericComponent* this_, const Url& inputFile, Bool append, const String& password) { return ((typename S::Implementation*) this_)->Open(inputFile, append, password); }
		static Result<void> WriteArchiveInterface_Close(maxon::GenericComponent* this_) { return ((typename S::Implementation*) this_)->Close(); }
		static Result<void> WriteArchiveInterface_SetCompressionLevel(maxon::GenericComponent* this_, Int compressionLevel) { return ((typename S::Implementation*) this_)->SetCompressionLevel(compressionLevel); }
		static Int WriteArchiveInterface_GetCompressionLevel(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetCompressionLevel(); }
		static Result<void> WriteArchiveInterface_CreateDirectory(maxon::GenericComponent* this_, const String& name, const UniversalDateTime& dateTime, IOATTRIBUTES fileAttributes) { return ((typename S::Implementation*) this_)->CreateDirectory(name, dateTime, fileAttributes); }
		static Result<void> WriteArchiveInterface_CreateFile(maxon::GenericComponent* this_, const String& name, const UniversalDateTime& dateTime, IOARCHIVESTOREMETHOD method, IOATTRIBUTES fileAttributes, UInt32 cryptCrc) { return ((typename S::Implementation*) this_)->CreateFile(name, dateTime, method, fileAttributes, cryptCrc); }
		static Result<void> WriteArchiveInterface_WriteFile(maxon::GenericComponent* this_, const Block<const Byte>& data) { return ((typename S::Implementation*) this_)->WriteFile(data); }
		static Result<void> WriteArchiveInterface_CloseFile(maxon::GenericComponent* this_) { return ((typename S::Implementation*) this_)->CloseFile(); }
		static Result<void> WriteArchiveInterface_CopyFile(maxon::GenericComponent* this_, const Url& fn, const String& str, IOATTRIBUTES fileAttributes, IOATTRIBUTES fileAttributesMask) { return ((typename S::Implementation*) this_)->CopyFile(fn, str, fileAttributes, fileAttributesMask); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto WriteArchiveInterface::Open(const Url& inputFile, Bool append, const String& password) -> Result<void>
{
	const WriteArchiveInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(WriteArchiveInterface, this); return mt_.WriteArchiveInterface_Open((maxon::GenericComponent*) this + mt_.WriteArchiveInterface_Open_Offset, inputFile, append, password);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto WriteArchiveInterface::Close() -> Result<void>
{
	const WriteArchiveInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(WriteArchiveInterface, this); return mt_.WriteArchiveInterface_Close((maxon::GenericComponent*) this + mt_.WriteArchiveInterface_Close_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto WriteArchiveInterface::SetCompressionLevel(Int compressionLevel) -> Result<void>
{
	const WriteArchiveInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(WriteArchiveInterface, this); return mt_.WriteArchiveInterface_SetCompressionLevel((maxon::GenericComponent*) this + mt_.WriteArchiveInterface_SetCompressionLevel_Offset, compressionLevel);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto WriteArchiveInterface::GetCompressionLevel() const -> Int
{
	const WriteArchiveInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(WriteArchiveInterface, this); return mt_.WriteArchiveInterface_GetCompressionLevel((const maxon::GenericComponent*) this + mt_.WriteArchiveInterface_GetCompressionLevel_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto WriteArchiveInterface::CreateDirectory(const String& name, const UniversalDateTime& dateTime, IOATTRIBUTES fileAttributes) -> Result<void>
{
	const WriteArchiveInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(WriteArchiveInterface, this); return mt_.WriteArchiveInterface_CreateDirectory((maxon::GenericComponent*) this + mt_.WriteArchiveInterface_CreateDirectory_Offset, name, dateTime, fileAttributes);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto WriteArchiveInterface::CreateFile(const String& name, const UniversalDateTime& dateTime, IOARCHIVESTOREMETHOD method, IOATTRIBUTES fileAttributes, UInt32 cryptCrc) -> Result<void>
{
	const WriteArchiveInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(WriteArchiveInterface, this); return mt_.WriteArchiveInterface_CreateFile((maxon::GenericComponent*) this + mt_.WriteArchiveInterface_CreateFile_Offset, name, dateTime, method, fileAttributes, cryptCrc);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto WriteArchiveInterface::WriteFile(const Block<const Byte>& data) -> Result<void>
{
	const WriteArchiveInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(WriteArchiveInterface, this); return mt_.WriteArchiveInterface_WriteFile((maxon::GenericComponent*) this + mt_.WriteArchiveInterface_WriteFile_Offset, data);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto WriteArchiveInterface::CloseFile() -> Result<void>
{
	const WriteArchiveInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(WriteArchiveInterface, this); return mt_.WriteArchiveInterface_CloseFile((maxon::GenericComponent*) this + mt_.WriteArchiveInterface_CloseFile_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto WriteArchiveInterface::CopyFile(const Url& fn, const String& str, IOATTRIBUTES fileAttributes, IOATTRIBUTES fileAttributesMask) -> Result<void>
{
	const WriteArchiveInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(WriteArchiveInterface, this); return mt_.WriteArchiveInterface_CopyFile((maxon::GenericComponent*) this + mt_.WriteArchiveInterface_CopyFile_Offset, fn, str, fileAttributes, fileAttributesMask);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto WriteArchiveInterface::Hxx1::Fn<S>::Open(const Url& inputFile, Bool append, const String& password) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); WriteArchiveInterface* o_ = (WriteArchiveInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(WriteArchiveInterface, o_, WriteArchiveInterface_Open) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<WriteArchiveInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<WriteArchiveInterface>() : PRIVATE_MAXON_VTABLE(WriteArchiveInterface, o_); 
	return (mt_.WriteArchiveInterface_Open(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.WriteArchiveInterface_Open_Offset, inputFile, append, password));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto WriteArchiveInterface::Hxx1::COWFn<S>::Open(const Url& inputFile, Bool append, const String& password) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); WriteArchiveInterface* o_ = (WriteArchiveInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(WriteArchiveInterface, o_, WriteArchiveInterface_Open) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<WriteArchiveInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<WriteArchiveInterface>() : PRIVATE_MAXON_VTABLE(WriteArchiveInterface, o_); 
	return (mt_.WriteArchiveInterface_Open(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.WriteArchiveInterface_Open_Offset, inputFile, append, password));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto WriteArchiveInterface::Hxx1::Fn<S>::Close() const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); WriteArchiveInterface* o_ = (WriteArchiveInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(WriteArchiveInterface, o_, WriteArchiveInterface_Close) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<WriteArchiveInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<WriteArchiveInterface>() : PRIVATE_MAXON_VTABLE(WriteArchiveInterface, o_); 
	return (mt_.WriteArchiveInterface_Close(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.WriteArchiveInterface_Close_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto WriteArchiveInterface::Hxx1::COWFn<S>::Close() -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); WriteArchiveInterface* o_ = (WriteArchiveInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(WriteArchiveInterface, o_, WriteArchiveInterface_Close) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<WriteArchiveInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<WriteArchiveInterface>() : PRIVATE_MAXON_VTABLE(WriteArchiveInterface, o_); 
	return (mt_.WriteArchiveInterface_Close(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.WriteArchiveInterface_Close_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto WriteArchiveInterface::Hxx1::Fn<S>::SetCompressionLevel(Int compressionLevel) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); WriteArchiveInterface* o_ = (WriteArchiveInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(WriteArchiveInterface, o_, WriteArchiveInterface_SetCompressionLevel) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<WriteArchiveInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<WriteArchiveInterface>() : PRIVATE_MAXON_VTABLE(WriteArchiveInterface, o_); 
	return (mt_.WriteArchiveInterface_SetCompressionLevel(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.WriteArchiveInterface_SetCompressionLevel_Offset, compressionLevel));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto WriteArchiveInterface::Hxx1::COWFn<S>::SetCompressionLevel(Int compressionLevel) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); WriteArchiveInterface* o_ = (WriteArchiveInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(WriteArchiveInterface, o_, WriteArchiveInterface_SetCompressionLevel) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<WriteArchiveInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<WriteArchiveInterface>() : PRIVATE_MAXON_VTABLE(WriteArchiveInterface, o_); 
	return (mt_.WriteArchiveInterface_SetCompressionLevel(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.WriteArchiveInterface_SetCompressionLevel_Offset, compressionLevel));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto WriteArchiveInterface::Hxx1::ConstFn<S>::GetCompressionLevel() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const WriteArchiveInterface* o_ = (const WriteArchiveInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = WriteArchiveInterface::NullValuePtr(); if (!o_) return 0; } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(WriteArchiveInterface, o_, WriteArchiveInterface_GetCompressionLevel) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<WriteArchiveInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<WriteArchiveInterface>() : PRIVATE_MAXON_VTABLE(WriteArchiveInterface, o_); 
	return (mt_.WriteArchiveInterface_GetCompressionLevel(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.WriteArchiveInterface_GetCompressionLevel_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto WriteArchiveInterface::Hxx1::Fn<S>::CreateDirectory(const String& name, const UniversalDateTime& dateTime, IOATTRIBUTES fileAttributes) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); WriteArchiveInterface* o_ = (WriteArchiveInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(WriteArchiveInterface, o_, WriteArchiveInterface_CreateDirectory) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<WriteArchiveInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<WriteArchiveInterface>() : PRIVATE_MAXON_VTABLE(WriteArchiveInterface, o_); 
	return (mt_.WriteArchiveInterface_CreateDirectory(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.WriteArchiveInterface_CreateDirectory_Offset, name, dateTime, fileAttributes));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto WriteArchiveInterface::Hxx1::COWFn<S>::CreateDirectory(const String& name, const UniversalDateTime& dateTime, IOATTRIBUTES fileAttributes) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); WriteArchiveInterface* o_ = (WriteArchiveInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(WriteArchiveInterface, o_, WriteArchiveInterface_CreateDirectory) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<WriteArchiveInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<WriteArchiveInterface>() : PRIVATE_MAXON_VTABLE(WriteArchiveInterface, o_); 
	return (mt_.WriteArchiveInterface_CreateDirectory(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.WriteArchiveInterface_CreateDirectory_Offset, name, dateTime, fileAttributes));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto WriteArchiveInterface::Hxx1::Fn<S>::CreateFile(const String& name, const UniversalDateTime& dateTime, IOARCHIVESTOREMETHOD method, IOATTRIBUTES fileAttributes, UInt32 cryptCrc) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); WriteArchiveInterface* o_ = (WriteArchiveInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(WriteArchiveInterface, o_, WriteArchiveInterface_CreateFile) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<WriteArchiveInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<WriteArchiveInterface>() : PRIVATE_MAXON_VTABLE(WriteArchiveInterface, o_); 
	return (mt_.WriteArchiveInterface_CreateFile(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.WriteArchiveInterface_CreateFile_Offset, name, dateTime, method, fileAttributes, cryptCrc));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto WriteArchiveInterface::Hxx1::COWFn<S>::CreateFile(const String& name, const UniversalDateTime& dateTime, IOARCHIVESTOREMETHOD method, IOATTRIBUTES fileAttributes, UInt32 cryptCrc) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); WriteArchiveInterface* o_ = (WriteArchiveInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(WriteArchiveInterface, o_, WriteArchiveInterface_CreateFile) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<WriteArchiveInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<WriteArchiveInterface>() : PRIVATE_MAXON_VTABLE(WriteArchiveInterface, o_); 
	return (mt_.WriteArchiveInterface_CreateFile(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.WriteArchiveInterface_CreateFile_Offset, name, dateTime, method, fileAttributes, cryptCrc));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto WriteArchiveInterface::Hxx1::Fn<S>::WriteFile(const Block<const Byte>& data) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); WriteArchiveInterface* o_ = (WriteArchiveInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(WriteArchiveInterface, o_, WriteArchiveInterface_WriteFile) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<WriteArchiveInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<WriteArchiveInterface>() : PRIVATE_MAXON_VTABLE(WriteArchiveInterface, o_); 
	return (mt_.WriteArchiveInterface_WriteFile(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.WriteArchiveInterface_WriteFile_Offset, data));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto WriteArchiveInterface::Hxx1::COWFn<S>::WriteFile(const Block<const Byte>& data) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); WriteArchiveInterface* o_ = (WriteArchiveInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(WriteArchiveInterface, o_, WriteArchiveInterface_WriteFile) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<WriteArchiveInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<WriteArchiveInterface>() : PRIVATE_MAXON_VTABLE(WriteArchiveInterface, o_); 
	return (mt_.WriteArchiveInterface_WriteFile(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.WriteArchiveInterface_WriteFile_Offset, data));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto WriteArchiveInterface::Hxx1::Fn<S>::CloseFile() const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); WriteArchiveInterface* o_ = (WriteArchiveInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(WriteArchiveInterface, o_, WriteArchiveInterface_CloseFile) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<WriteArchiveInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<WriteArchiveInterface>() : PRIVATE_MAXON_VTABLE(WriteArchiveInterface, o_); 
	return (mt_.WriteArchiveInterface_CloseFile(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.WriteArchiveInterface_CloseFile_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto WriteArchiveInterface::Hxx1::COWFn<S>::CloseFile() -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); WriteArchiveInterface* o_ = (WriteArchiveInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(WriteArchiveInterface, o_, WriteArchiveInterface_CloseFile) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<WriteArchiveInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<WriteArchiveInterface>() : PRIVATE_MAXON_VTABLE(WriteArchiveInterface, o_); 
	return (mt_.WriteArchiveInterface_CloseFile(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.WriteArchiveInterface_CloseFile_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto WriteArchiveInterface::Hxx1::Fn<S>::CopyFile(const Url& fn, const String& str, IOATTRIBUTES fileAttributes, IOATTRIBUTES fileAttributesMask) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); WriteArchiveInterface* o_ = (WriteArchiveInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(WriteArchiveInterface, o_, WriteArchiveInterface_CopyFile) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<WriteArchiveInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<WriteArchiveInterface>() : PRIVATE_MAXON_VTABLE(WriteArchiveInterface, o_); 
	return (mt_.WriteArchiveInterface_CopyFile(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.WriteArchiveInterface_CopyFile_Offset, fn, str, fileAttributes, fileAttributesMask));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto WriteArchiveInterface::Hxx1::COWFn<S>::CopyFile(const Url& fn, const String& str, IOATTRIBUTES fileAttributes, IOATTRIBUTES fileAttributesMask) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); WriteArchiveInterface* o_ = (WriteArchiveInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(WriteArchiveInterface, o_, WriteArchiveInterface_CopyFile) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<WriteArchiveInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<WriteArchiveInterface>() : PRIVATE_MAXON_VTABLE(WriteArchiveInterface, o_); 
	return (mt_.WriteArchiveInterface_CopyFile(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.WriteArchiveInterface_CopyFile_Offset, fn, str, fileAttributes, fileAttributesMask));
}
auto WriteArchiveInterface::GetPtr() -> Ptr { return Ptr(this); }
auto WriteArchiveInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_ioarchivehandler)
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

