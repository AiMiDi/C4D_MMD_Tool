
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
	PRIVATE_MAXON_MF_POINTER(ReadArchiveInterface_Open, Open, true, maxon::GenericComponent,, (Result<void>), const Url& inputFile, const String& password);
	maxon::Int ReadArchiveInterface_Open_Offset;
	PRIVATE_MAXON_MF_POINTER(ReadArchiveInterface_Close, Close, true, maxon::GenericComponent,, (Result<void>));
	maxon::Int ReadArchiveInterface_Close_Offset;
	PRIVATE_MAXON_MF_POINTER(ReadArchiveInterface_ExtractSingleFile, ExtractSingleFile, true, maxon::GenericComponent,, (Result<Url>), const String& archiveFile, const Url& outputDirectory, ThreadRef thread, IOARCHIVEEXTRACTFLAGS flags, const ExtractCallback& extractCallback);
	maxon::Int ReadArchiveInterface_ExtractSingleFile_Offset;
	PRIVATE_MAXON_MF_POINTER(ReadArchiveInterface_Extract, Extract, true, maxon::GenericComponent,, (Result<void>), const Url& outputDirectory, ThreadRef thread, IOARCHIVEEXTRACTFLAGS flags, const ExtractCallback& extractCallback);
	maxon::Int ReadArchiveInterface_Extract_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ReadArchiveInterface, Open))
	{
		maxon::Tie(ReadArchiveInterface_Open, ReadArchiveInterface_Open_Offset) = ReadArchiveInterface_Open_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ReadArchiveInterface, Close))
	{
		maxon::Tie(ReadArchiveInterface_Close, ReadArchiveInterface_Close_Offset) = ReadArchiveInterface_Close_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ReadArchiveInterface, ExtractSingleFile))
	{
		maxon::Tie(ReadArchiveInterface_ExtractSingleFile, ReadArchiveInterface_ExtractSingleFile_Offset) = ReadArchiveInterface_ExtractSingleFile_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ReadArchiveInterface, Extract))
	{
		maxon::Tie(ReadArchiveInterface_Extract, ReadArchiveInterface_Extract_Offset) = ReadArchiveInterface_Extract_GetPtr<W>(offset, true);
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
			if constexpr (!S::Implementation::PROXY)
			{
				if (!(Super0::InitMTablesWithBases(info, offset))) return false;
			}
			auto* vt = (ReadArchiveInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, ReadArchiveInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		PRIVATE_MAXON_MF_WRAPPER(ReadArchiveInterface_Open, maxon::GenericComponent,, (Result<void>), const Url& inputFile, const String& password) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->Open(inputFile, password); }
		PRIVATE_MAXON_MF_WRAPPER(ReadArchiveInterface_Close, maxon::GenericComponent,, (Result<void>)) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->Close(); }
		PRIVATE_MAXON_MF_WRAPPER(ReadArchiveInterface_ExtractSingleFile, maxon::GenericComponent,, (Result<Url>), const String& archiveFile, const Url& outputDirectory, ThreadRef thread, IOARCHIVEEXTRACTFLAGS flags, const ExtractCallback& extractCallback) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->ExtractSingleFile(archiveFile, outputDirectory, std::forward<ThreadRef>(thread), flags, extractCallback); }
		PRIVATE_MAXON_MF_WRAPPER(ReadArchiveInterface_Extract, maxon::GenericComponent,, (Result<void>), const Url& outputDirectory, ThreadRef thread, IOARCHIVEEXTRACTFLAGS flags, const ExtractCallback& extractCallback) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->Extract(outputDirectory, std::forward<ThreadRef>(thread), flags, extractCallback); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto ReadArchiveInterface::Open(const Url& inputFile, const String& password) -> Result<void>
{
	const ReadArchiveInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ReadArchiveInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.ReadArchiveInterface_Open_Offset), mt_.ReadArchiveInterface_Open, inputFile, password);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ReadArchiveInterface::Close() -> Result<void>
{
	const ReadArchiveInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ReadArchiveInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.ReadArchiveInterface_Close_Offset), mt_.ReadArchiveInterface_Close);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ReadArchiveInterface::ExtractSingleFile(const String& archiveFile, const Url& outputDirectory, ThreadRef thread, IOARCHIVEEXTRACTFLAGS flags, const ExtractCallback& extractCallback) -> Result<Url>
{
	const ReadArchiveInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ReadArchiveInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.ReadArchiveInterface_ExtractSingleFile_Offset), mt_.ReadArchiveInterface_ExtractSingleFile, archiveFile, outputDirectory, std::forward<ThreadRef>(thread), flags, extractCallback);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ReadArchiveInterface::Extract(const Url& outputDirectory, ThreadRef thread, IOARCHIVEEXTRACTFLAGS flags, const ExtractCallback& extractCallback) -> Result<void>
{
	const ReadArchiveInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ReadArchiveInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.ReadArchiveInterface_Extract_Offset), mt_.ReadArchiveInterface_Extract, outputDirectory, std::forward<ThreadRef>(thread), flags, extractCallback);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ReadArchiveInterface::Hxx1::Fn<S>::Open(const Url& inputFile, const String& password) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); ReadArchiveInterface* o_ = (ReadArchiveInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ReadArchiveInterface, o_, ReadArchiveInterface_Open) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ReadArchiveInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ReadArchiveInterface>() : PRIVATE_MAXON_VTABLE(ReadArchiveInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ReadArchiveInterface_Open_Offset), mt_.ReadArchiveInterface_Open, inputFile, password));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ReadArchiveInterface::Hxx1::COWFn<S>::Open(const Url& inputFile, const String& password) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); ReadArchiveInterface* o_ = (ReadArchiveInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ReadArchiveInterface, o_, ReadArchiveInterface_Open) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ReadArchiveInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ReadArchiveInterface>() : PRIVATE_MAXON_VTABLE(ReadArchiveInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ReadArchiveInterface_Open_Offset), mt_.ReadArchiveInterface_Open, inputFile, password));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ReadArchiveInterface::Hxx1::Fn<S>::Close() const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); ReadArchiveInterface* o_ = (ReadArchiveInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ReadArchiveInterface, o_, ReadArchiveInterface_Close) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ReadArchiveInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ReadArchiveInterface>() : PRIVATE_MAXON_VTABLE(ReadArchiveInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ReadArchiveInterface_Close_Offset), mt_.ReadArchiveInterface_Close));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ReadArchiveInterface::Hxx1::COWFn<S>::Close() -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); ReadArchiveInterface* o_ = (ReadArchiveInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ReadArchiveInterface, o_, ReadArchiveInterface_Close) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ReadArchiveInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ReadArchiveInterface>() : PRIVATE_MAXON_VTABLE(ReadArchiveInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ReadArchiveInterface_Close_Offset), mt_.ReadArchiveInterface_Close));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ReadArchiveInterface::Hxx1::Fn<S>::ExtractSingleFile(const String& archiveFile, const Url& outputDirectory, ThreadRef thread, IOARCHIVEEXTRACTFLAGS flags, const ExtractCallback& extractCallback) const -> Result<Url>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Url>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); ReadArchiveInterface* o_ = (ReadArchiveInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ReadArchiveInterface, o_, ReadArchiveInterface_ExtractSingleFile) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ReadArchiveInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ReadArchiveInterface>() : PRIVATE_MAXON_VTABLE(ReadArchiveInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ReadArchiveInterface_ExtractSingleFile_Offset), mt_.ReadArchiveInterface_ExtractSingleFile, archiveFile, outputDirectory, std::forward<ThreadRef>(thread), flags, extractCallback));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ReadArchiveInterface::Hxx1::COWFn<S>::ExtractSingleFile(const String& archiveFile, const Url& outputDirectory, ThreadRef thread, IOARCHIVEEXTRACTFLAGS flags, const ExtractCallback& extractCallback) -> Result<Url>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Url>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); ReadArchiveInterface* o_ = (ReadArchiveInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ReadArchiveInterface, o_, ReadArchiveInterface_ExtractSingleFile) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ReadArchiveInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ReadArchiveInterface>() : PRIVATE_MAXON_VTABLE(ReadArchiveInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ReadArchiveInterface_ExtractSingleFile_Offset), mt_.ReadArchiveInterface_ExtractSingleFile, archiveFile, outputDirectory, std::forward<ThreadRef>(thread), flags, extractCallback));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ReadArchiveInterface::Hxx1::Fn<S>::Extract(const Url& outputDirectory, ThreadRef thread, IOARCHIVEEXTRACTFLAGS flags, const ExtractCallback& extractCallback) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); ReadArchiveInterface* o_ = (ReadArchiveInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ReadArchiveInterface, o_, ReadArchiveInterface_Extract) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ReadArchiveInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ReadArchiveInterface>() : PRIVATE_MAXON_VTABLE(ReadArchiveInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ReadArchiveInterface_Extract_Offset), mt_.ReadArchiveInterface_Extract, outputDirectory, std::forward<ThreadRef>(thread), flags, extractCallback));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ReadArchiveInterface::Hxx1::COWFn<S>::Extract(const Url& outputDirectory, ThreadRef thread, IOARCHIVEEXTRACTFLAGS flags, const ExtractCallback& extractCallback) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); ReadArchiveInterface* o_ = (ReadArchiveInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ReadArchiveInterface, o_, ReadArchiveInterface_Extract) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ReadArchiveInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ReadArchiveInterface>() : PRIVATE_MAXON_VTABLE(ReadArchiveInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ReadArchiveInterface_Extract_Offset), mt_.ReadArchiveInterface_Extract, outputDirectory, std::forward<ThreadRef>(thread), flags, extractCallback));
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
	PRIVATE_MAXON_MF_POINTER(WriteArchiveInterface_Open, Open, true, maxon::GenericComponent,, (Result<void>), const Url& inputFile, Bool append, const String& password);
	maxon::Int WriteArchiveInterface_Open_Offset;
	PRIVATE_MAXON_MF_POINTER(WriteArchiveInterface_Close, Close, true, maxon::GenericComponent,, (Result<void>));
	maxon::Int WriteArchiveInterface_Close_Offset;
	PRIVATE_MAXON_MF_POINTER(WriteArchiveInterface_SetCompressionLevel, SetCompressionLevel, true, maxon::GenericComponent,, (Result<void>), Int compressionLevel);
	maxon::Int WriteArchiveInterface_SetCompressionLevel_Offset;
	PRIVATE_MAXON_MF_POINTER(WriteArchiveInterface_GetCompressionLevel, GetCompressionLevel, true, maxon::GenericComponent, const, (Int));
	maxon::Int WriteArchiveInterface_GetCompressionLevel_Offset;
	PRIVATE_MAXON_MF_POINTER(WriteArchiveInterface_CreateDirectory, CreateDirectory, true, maxon::GenericComponent,, (Result<void>), const String& name, const UniversalDateTime& dateTime, IOATTRIBUTES fileAttributes);
	maxon::Int WriteArchiveInterface_CreateDirectory_Offset;
	PRIVATE_MAXON_MF_POINTER(WriteArchiveInterface_CreateFile, CreateFile, true, maxon::GenericComponent,, (Result<void>), const String& name, const UniversalDateTime& dateTime, IOARCHIVESTOREMETHOD method, IOATTRIBUTES fileAttributes, UInt32 cryptCrc);
	maxon::Int WriteArchiveInterface_CreateFile_Offset;
	PRIVATE_MAXON_MF_POINTER(WriteArchiveInterface_WriteFile, WriteFile, true, maxon::GenericComponent,, (Result<void>), const Block<const Byte>& data);
	maxon::Int WriteArchiveInterface_WriteFile_Offset;
	PRIVATE_MAXON_MF_POINTER(WriteArchiveInterface_CloseFile, CloseFile, true, maxon::GenericComponent,, (Result<void>));
	maxon::Int WriteArchiveInterface_CloseFile_Offset;
	PRIVATE_MAXON_MF_POINTER(WriteArchiveInterface_CopyFile, CopyFile, true, maxon::GenericComponent,, (Result<void>), const Url& fn, const String& str, IOATTRIBUTES fileAttributes, IOATTRIBUTES fileAttributesMask);
	maxon::Int WriteArchiveInterface_CopyFile_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, WriteArchiveInterface, Open))
	{
		maxon::Tie(WriteArchiveInterface_Open, WriteArchiveInterface_Open_Offset) = WriteArchiveInterface_Open_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, WriteArchiveInterface, Close))
	{
		maxon::Tie(WriteArchiveInterface_Close, WriteArchiveInterface_Close_Offset) = WriteArchiveInterface_Close_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, WriteArchiveInterface, SetCompressionLevel))
	{
		maxon::Tie(WriteArchiveInterface_SetCompressionLevel, WriteArchiveInterface_SetCompressionLevel_Offset) = WriteArchiveInterface_SetCompressionLevel_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, WriteArchiveInterface, GetCompressionLevel))
	{
		maxon::Tie(WriteArchiveInterface_GetCompressionLevel, WriteArchiveInterface_GetCompressionLevel_Offset) = WriteArchiveInterface_GetCompressionLevel_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, WriteArchiveInterface, CreateDirectory))
	{
		maxon::Tie(WriteArchiveInterface_CreateDirectory, WriteArchiveInterface_CreateDirectory_Offset) = WriteArchiveInterface_CreateDirectory_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, WriteArchiveInterface, CreateFile))
	{
		maxon::Tie(WriteArchiveInterface_CreateFile, WriteArchiveInterface_CreateFile_Offset) = WriteArchiveInterface_CreateFile_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, WriteArchiveInterface, WriteFile))
	{
		maxon::Tie(WriteArchiveInterface_WriteFile, WriteArchiveInterface_WriteFile_Offset) = WriteArchiveInterface_WriteFile_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, WriteArchiveInterface, CloseFile))
	{
		maxon::Tie(WriteArchiveInterface_CloseFile, WriteArchiveInterface_CloseFile_Offset) = WriteArchiveInterface_CloseFile_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, WriteArchiveInterface, CopyFile))
	{
		maxon::Tie(WriteArchiveInterface_CopyFile, WriteArchiveInterface_CopyFile_Offset) = WriteArchiveInterface_CopyFile_GetPtr<W>(offset, true);
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
			if constexpr (!S::Implementation::PROXY)
			{
				if (!(Super0::InitMTablesWithBases(info, offset))) return false;
			}
			auto* vt = (WriteArchiveInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, WriteArchiveInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		PRIVATE_MAXON_MF_WRAPPER(WriteArchiveInterface_Open, maxon::GenericComponent,, (Result<void>), const Url& inputFile, Bool append, const String& password) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->Open(inputFile, append, password); }
		PRIVATE_MAXON_MF_WRAPPER(WriteArchiveInterface_Close, maxon::GenericComponent,, (Result<void>)) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->Close(); }
		PRIVATE_MAXON_MF_WRAPPER(WriteArchiveInterface_SetCompressionLevel, maxon::GenericComponent,, (Result<void>), Int compressionLevel) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->SetCompressionLevel(compressionLevel); }
		PRIVATE_MAXON_MF_WRAPPER(WriteArchiveInterface_GetCompressionLevel, maxon::GenericComponent, const, (Int)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetCompressionLevel(); }
		PRIVATE_MAXON_MF_WRAPPER(WriteArchiveInterface_CreateDirectory, maxon::GenericComponent,, (Result<void>), const String& name, const UniversalDateTime& dateTime, IOATTRIBUTES fileAttributes) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->CreateDirectory(name, dateTime, fileAttributes); }
		PRIVATE_MAXON_MF_WRAPPER(WriteArchiveInterface_CreateFile, maxon::GenericComponent,, (Result<void>), const String& name, const UniversalDateTime& dateTime, IOARCHIVESTOREMETHOD method, IOATTRIBUTES fileAttributes, UInt32 cryptCrc) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->CreateFile(name, dateTime, method, fileAttributes, cryptCrc); }
		PRIVATE_MAXON_MF_WRAPPER(WriteArchiveInterface_WriteFile, maxon::GenericComponent,, (Result<void>), const Block<const Byte>& data) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->WriteFile(data); }
		PRIVATE_MAXON_MF_WRAPPER(WriteArchiveInterface_CloseFile, maxon::GenericComponent,, (Result<void>)) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->CloseFile(); }
		PRIVATE_MAXON_MF_WRAPPER(WriteArchiveInterface_CopyFile, maxon::GenericComponent,, (Result<void>), const Url& fn, const String& str, IOATTRIBUTES fileAttributes, IOATTRIBUTES fileAttributesMask) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->CopyFile(fn, str, fileAttributes, fileAttributesMask); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto WriteArchiveInterface::Open(const Url& inputFile, Bool append, const String& password) -> Result<void>
{
	const WriteArchiveInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(WriteArchiveInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.WriteArchiveInterface_Open_Offset), mt_.WriteArchiveInterface_Open, inputFile, append, password);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto WriteArchiveInterface::Close() -> Result<void>
{
	const WriteArchiveInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(WriteArchiveInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.WriteArchiveInterface_Close_Offset), mt_.WriteArchiveInterface_Close);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto WriteArchiveInterface::SetCompressionLevel(Int compressionLevel) -> Result<void>
{
	const WriteArchiveInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(WriteArchiveInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.WriteArchiveInterface_SetCompressionLevel_Offset), mt_.WriteArchiveInterface_SetCompressionLevel, compressionLevel);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto WriteArchiveInterface::GetCompressionLevel() const -> Int
{
	const WriteArchiveInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(WriteArchiveInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.WriteArchiveInterface_GetCompressionLevel_Offset), mt_.WriteArchiveInterface_GetCompressionLevel);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto WriteArchiveInterface::CreateDirectory(const String& name, const UniversalDateTime& dateTime, IOATTRIBUTES fileAttributes) -> Result<void>
{
	const WriteArchiveInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(WriteArchiveInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.WriteArchiveInterface_CreateDirectory_Offset), mt_.WriteArchiveInterface_CreateDirectory, name, dateTime, fileAttributes);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto WriteArchiveInterface::CreateFile(const String& name, const UniversalDateTime& dateTime, IOARCHIVESTOREMETHOD method, IOATTRIBUTES fileAttributes, UInt32 cryptCrc) -> Result<void>
{
	const WriteArchiveInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(WriteArchiveInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.WriteArchiveInterface_CreateFile_Offset), mt_.WriteArchiveInterface_CreateFile, name, dateTime, method, fileAttributes, cryptCrc);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto WriteArchiveInterface::WriteFile(const Block<const Byte>& data) -> Result<void>
{
	const WriteArchiveInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(WriteArchiveInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.WriteArchiveInterface_WriteFile_Offset), mt_.WriteArchiveInterface_WriteFile, data);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto WriteArchiveInterface::CloseFile() -> Result<void>
{
	const WriteArchiveInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(WriteArchiveInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.WriteArchiveInterface_CloseFile_Offset), mt_.WriteArchiveInterface_CloseFile);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto WriteArchiveInterface::CopyFile(const Url& fn, const String& str, IOATTRIBUTES fileAttributes, IOATTRIBUTES fileAttributesMask) -> Result<void>
{
	const WriteArchiveInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(WriteArchiveInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.WriteArchiveInterface_CopyFile_Offset), mt_.WriteArchiveInterface_CopyFile, fn, str, fileAttributes, fileAttributesMask);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto WriteArchiveInterface::Hxx1::Fn<S>::Open(const Url& inputFile, Bool append, const String& password) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); WriteArchiveInterface* o_ = (WriteArchiveInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(WriteArchiveInterface, o_, WriteArchiveInterface_Open) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<WriteArchiveInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<WriteArchiveInterface>() : PRIVATE_MAXON_VTABLE(WriteArchiveInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.WriteArchiveInterface_Open_Offset), mt_.WriteArchiveInterface_Open, inputFile, append, password));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto WriteArchiveInterface::Hxx1::COWFn<S>::Open(const Url& inputFile, Bool append, const String& password) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); WriteArchiveInterface* o_ = (WriteArchiveInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(WriteArchiveInterface, o_, WriteArchiveInterface_Open) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<WriteArchiveInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<WriteArchiveInterface>() : PRIVATE_MAXON_VTABLE(WriteArchiveInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.WriteArchiveInterface_Open_Offset), mt_.WriteArchiveInterface_Open, inputFile, append, password));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto WriteArchiveInterface::Hxx1::Fn<S>::Close() const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); WriteArchiveInterface* o_ = (WriteArchiveInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(WriteArchiveInterface, o_, WriteArchiveInterface_Close) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<WriteArchiveInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<WriteArchiveInterface>() : PRIVATE_MAXON_VTABLE(WriteArchiveInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.WriteArchiveInterface_Close_Offset), mt_.WriteArchiveInterface_Close));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto WriteArchiveInterface::Hxx1::COWFn<S>::Close() -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); WriteArchiveInterface* o_ = (WriteArchiveInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(WriteArchiveInterface, o_, WriteArchiveInterface_Close) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<WriteArchiveInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<WriteArchiveInterface>() : PRIVATE_MAXON_VTABLE(WriteArchiveInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.WriteArchiveInterface_Close_Offset), mt_.WriteArchiveInterface_Close));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto WriteArchiveInterface::Hxx1::Fn<S>::SetCompressionLevel(Int compressionLevel) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); WriteArchiveInterface* o_ = (WriteArchiveInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(WriteArchiveInterface, o_, WriteArchiveInterface_SetCompressionLevel) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<WriteArchiveInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<WriteArchiveInterface>() : PRIVATE_MAXON_VTABLE(WriteArchiveInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.WriteArchiveInterface_SetCompressionLevel_Offset), mt_.WriteArchiveInterface_SetCompressionLevel, compressionLevel));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto WriteArchiveInterface::Hxx1::COWFn<S>::SetCompressionLevel(Int compressionLevel) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); WriteArchiveInterface* o_ = (WriteArchiveInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(WriteArchiveInterface, o_, WriteArchiveInterface_SetCompressionLevel) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<WriteArchiveInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<WriteArchiveInterface>() : PRIVATE_MAXON_VTABLE(WriteArchiveInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.WriteArchiveInterface_SetCompressionLevel_Offset), mt_.WriteArchiveInterface_SetCompressionLevel, compressionLevel));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto WriteArchiveInterface::Hxx1::ConstFn<S>::GetCompressionLevel() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const WriteArchiveInterface* o_ = (const WriteArchiveInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = WriteArchiveInterface::NullValuePtr(); if (!o_) return 0; } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(WriteArchiveInterface, o_, WriteArchiveInterface_GetCompressionLevel) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<WriteArchiveInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<WriteArchiveInterface>() : PRIVATE_MAXON_VTABLE(WriteArchiveInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.WriteArchiveInterface_GetCompressionLevel_Offset), mt_.WriteArchiveInterface_GetCompressionLevel));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto WriteArchiveInterface::Hxx1::Fn<S>::CreateDirectory(const String& name, const UniversalDateTime& dateTime, IOATTRIBUTES fileAttributes) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); WriteArchiveInterface* o_ = (WriteArchiveInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(WriteArchiveInterface, o_, WriteArchiveInterface_CreateDirectory) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<WriteArchiveInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<WriteArchiveInterface>() : PRIVATE_MAXON_VTABLE(WriteArchiveInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.WriteArchiveInterface_CreateDirectory_Offset), mt_.WriteArchiveInterface_CreateDirectory, name, dateTime, fileAttributes));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto WriteArchiveInterface::Hxx1::COWFn<S>::CreateDirectory(const String& name, const UniversalDateTime& dateTime, IOATTRIBUTES fileAttributes) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); WriteArchiveInterface* o_ = (WriteArchiveInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(WriteArchiveInterface, o_, WriteArchiveInterface_CreateDirectory) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<WriteArchiveInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<WriteArchiveInterface>() : PRIVATE_MAXON_VTABLE(WriteArchiveInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.WriteArchiveInterface_CreateDirectory_Offset), mt_.WriteArchiveInterface_CreateDirectory, name, dateTime, fileAttributes));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto WriteArchiveInterface::Hxx1::Fn<S>::CreateFile(const String& name, const UniversalDateTime& dateTime, IOARCHIVESTOREMETHOD method, IOATTRIBUTES fileAttributes, UInt32 cryptCrc) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); WriteArchiveInterface* o_ = (WriteArchiveInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(WriteArchiveInterface, o_, WriteArchiveInterface_CreateFile) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<WriteArchiveInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<WriteArchiveInterface>() : PRIVATE_MAXON_VTABLE(WriteArchiveInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.WriteArchiveInterface_CreateFile_Offset), mt_.WriteArchiveInterface_CreateFile, name, dateTime, method, fileAttributes, cryptCrc));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto WriteArchiveInterface::Hxx1::COWFn<S>::CreateFile(const String& name, const UniversalDateTime& dateTime, IOARCHIVESTOREMETHOD method, IOATTRIBUTES fileAttributes, UInt32 cryptCrc) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); WriteArchiveInterface* o_ = (WriteArchiveInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(WriteArchiveInterface, o_, WriteArchiveInterface_CreateFile) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<WriteArchiveInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<WriteArchiveInterface>() : PRIVATE_MAXON_VTABLE(WriteArchiveInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.WriteArchiveInterface_CreateFile_Offset), mt_.WriteArchiveInterface_CreateFile, name, dateTime, method, fileAttributes, cryptCrc));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto WriteArchiveInterface::Hxx1::Fn<S>::WriteFile(const Block<const Byte>& data) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); WriteArchiveInterface* o_ = (WriteArchiveInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(WriteArchiveInterface, o_, WriteArchiveInterface_WriteFile) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<WriteArchiveInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<WriteArchiveInterface>() : PRIVATE_MAXON_VTABLE(WriteArchiveInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.WriteArchiveInterface_WriteFile_Offset), mt_.WriteArchiveInterface_WriteFile, data));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto WriteArchiveInterface::Hxx1::COWFn<S>::WriteFile(const Block<const Byte>& data) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); WriteArchiveInterface* o_ = (WriteArchiveInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(WriteArchiveInterface, o_, WriteArchiveInterface_WriteFile) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<WriteArchiveInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<WriteArchiveInterface>() : PRIVATE_MAXON_VTABLE(WriteArchiveInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.WriteArchiveInterface_WriteFile_Offset), mt_.WriteArchiveInterface_WriteFile, data));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto WriteArchiveInterface::Hxx1::Fn<S>::CloseFile() const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); WriteArchiveInterface* o_ = (WriteArchiveInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(WriteArchiveInterface, o_, WriteArchiveInterface_CloseFile) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<WriteArchiveInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<WriteArchiveInterface>() : PRIVATE_MAXON_VTABLE(WriteArchiveInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.WriteArchiveInterface_CloseFile_Offset), mt_.WriteArchiveInterface_CloseFile));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto WriteArchiveInterface::Hxx1::COWFn<S>::CloseFile() -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); WriteArchiveInterface* o_ = (WriteArchiveInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(WriteArchiveInterface, o_, WriteArchiveInterface_CloseFile) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<WriteArchiveInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<WriteArchiveInterface>() : PRIVATE_MAXON_VTABLE(WriteArchiveInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.WriteArchiveInterface_CloseFile_Offset), mt_.WriteArchiveInterface_CloseFile));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto WriteArchiveInterface::Hxx1::Fn<S>::CopyFile(const Url& fn, const String& str, IOATTRIBUTES fileAttributes, IOATTRIBUTES fileAttributesMask) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); WriteArchiveInterface* o_ = (WriteArchiveInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(WriteArchiveInterface, o_, WriteArchiveInterface_CopyFile) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<WriteArchiveInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<WriteArchiveInterface>() : PRIVATE_MAXON_VTABLE(WriteArchiveInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.WriteArchiveInterface_CopyFile_Offset), mt_.WriteArchiveInterface_CopyFile, fn, str, fileAttributes, fileAttributesMask));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto WriteArchiveInterface::Hxx1::COWFn<S>::CopyFile(const Url& fn, const String& str, IOATTRIBUTES fileAttributes, IOATTRIBUTES fileAttributesMask) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); WriteArchiveInterface* o_ = (WriteArchiveInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(WriteArchiveInterface, o_, WriteArchiveInterface_CopyFile) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<WriteArchiveInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<WriteArchiveInterface>() : PRIVATE_MAXON_VTABLE(WriteArchiveInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.WriteArchiveInterface_CopyFile_Offset), mt_.WriteArchiveInterface_CopyFile, fn, str, fileAttributes, fileAttributesMask));
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

