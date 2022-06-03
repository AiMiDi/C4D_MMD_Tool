
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1
constexpr const maxon::Char* ResolveInterface::PrivateGetCppName() { return "maxon::ResolveRef"; }

struct ResolveInterface::MTable
{
	static MTable _instance;
	static MTable _unresolvedInstance;
	static const maxon::Char* const _ids;
	static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl);
	static const maxon::NULL_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = false;
	void (*ResolveInterface_Free) (const ResolveInterface* object);
	Result<Url> (*ResolveInterface_RemoveDotSegments) (const Url& url);
	template <typename IMPL> void Init()
	{
		ResolveInterface_Free = &IMPL::ResolveInterface_Free;
		ResolveInterface_RemoveDotSegments = &IMPL::ResolveInterface_RemoveDotSegments;
	}
};

struct ResolveInterface::Hxx2
{
	class Unresolved;
	template <typename C> class Wrapper
	{
	public:
		static void ResolveInterface_Free(const ResolveInterface* object) { return C::Free(object); }
		static Result<Url> ResolveInterface_RemoveDotSegments(const Url& url) { return C::RemoveDotSegments(url); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto ResolveInterface::Free(const ResolveInterface* object) -> void
{
	return MTable::_instance.ResolveInterface_Free(object);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ResolveInterface::RemoveDotSegments(const Url& url) -> Result<Url>
{
	return MTable::_instance.ResolveInterface_RemoveDotSegments(url);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ResolveInterface::Hxx1::ConstFn<S>::RemoveDotSegments(const Url& url) -> Result<Url>
{
	return (MTable::_instance.ResolveInterface_RemoveDotSegments(url));
}
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_ioconnection)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_ResolveInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_ResolveInterface() { new (s_ui_maxon_ResolveInterface) maxon::EntityUse(ResolveInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/ioconnection.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_ResolveInterface(ResolveInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/ioconnection.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif

struct IoConnectionInterface::MTable
{
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetBrowseIterator);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetContentLength);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetUrl);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(IoCopyFile);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(IoCopyFileProgress);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(IoCreateDirectory);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(IoDelete);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(IoDetect);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(IoGetAttributes);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(IoGetFreeVolumeSpace);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(IoGetTime);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(IoMove);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(IoRename);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(IoSetAttributes);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(IoSetTime);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(IoShowInOS);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(OpenInOutputStream);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(OpenInputStream);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(OpenOutputStream);
	static const maxon::Char* const _ids;
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	const Url& (*IoConnectionInterface_GetUrl) (const maxon::GenericComponent* this_);
	maxon::Int IoConnectionInterface_GetUrl_Offset;
	Result<IoBrowseRef> (*IoConnectionInterface_GetBrowseIterator) (maxon::GenericComponent* this_, GETBROWSEITERATORFLAGS flags);
	maxon::Int IoConnectionInterface_GetBrowseIterator_Offset;
	Result<InputStreamRef> (*IoConnectionInterface_OpenInputStream) (maxon::GenericComponent* this_, OPENSTREAMFLAGS flags);
	maxon::Int IoConnectionInterface_OpenInputStream_Offset;
	Result<OutputStreamRef> (*IoConnectionInterface_OpenOutputStream) (maxon::GenericComponent* this_, OPENSTREAMFLAGS flags);
	maxon::Int IoConnectionInterface_OpenOutputStream_Offset;
	Result<InOutputStreamRef> (*IoConnectionInterface_OpenInOutputStream) (maxon::GenericComponent* this_, OPENSTREAMFLAGS flags);
	maxon::Int IoConnectionInterface_OpenInOutputStream_Offset;
	Result<Int64> (*IoConnectionInterface_GetContentLength) (maxon::GenericComponent* this_);
	maxon::Int IoConnectionInterface_GetContentLength_Offset;
	IODETECT (*IoConnectionInterface_IoDetect) (const maxon::GenericComponent* this_);
	maxon::Int IoConnectionInterface_IoDetect_Offset;
	Result<IOATTRIBUTES> (*IoConnectionInterface_IoGetAttributes) (const maxon::GenericComponent* this_);
	maxon::Int IoConnectionInterface_IoGetAttributes_Offset;
	Result<void> (*IoConnectionInterface_IoSetAttributes) (maxon::GenericComponent* this_, IOATTRIBUTES flags, IOATTRIBUTES mask);
	maxon::Int IoConnectionInterface_IoSetAttributes_Offset;
	Result<UniversalDateTime> (*IoConnectionInterface_IoGetTime) (const maxon::GenericComponent* this_, IOTIMEMODE mode);
	maxon::Int IoConnectionInterface_IoGetTime_Offset;
	Result<void> (*IoConnectionInterface_IoSetTime) (maxon::GenericComponent* this_, IOTIMEMODE mode, const UniversalDateTime& dateTime);
	maxon::Int IoConnectionInterface_IoSetTime_Offset;
	Result<void> (*IoConnectionInterface_IoDelete) (maxon::GenericComponent* this_, Bool force);
	maxon::Int IoConnectionInterface_IoDelete_Offset;
	Result<void> (*IoConnectionInterface_IoCreateDirectory) (maxon::GenericComponent* this_, Bool createParents, BaseArray<Url>* createdDirs);
	maxon::Int IoConnectionInterface_IoCreateDirectory_Offset;
	Result<void> (*IoConnectionInterface_IoCopyFile) (maxon::GenericComponent* this_, const Url& destName, Bool overwrite, Bool removeReadOnly);
	maxon::Int IoConnectionInterface_IoCopyFile_Offset;
	Result<void> (*IoConnectionInterface_IoCopyFileProgress) (maxon::GenericComponent* this_, const Url& destName, Bool overwrite, Bool removeReadOnly, const IoProgressDelegate& progress);
	maxon::Int IoConnectionInterface_IoCopyFileProgress_Offset;
	Result<void> (*IoConnectionInterface_IoMove) (maxon::GenericComponent* this_, const Url& destName);
	maxon::Int IoConnectionInterface_IoMove_Offset;
	Result<void> (*IoConnectionInterface_IoRename) (maxon::GenericComponent* this_, const Url& newName);
	maxon::Int IoConnectionInterface_IoRename_Offset;
	Result<void> (*IoConnectionInterface_IoGetFreeVolumeSpace) (const maxon::GenericComponent* this_, Int64& availableBytes, Int64& totalBytes);
	maxon::Int IoConnectionInterface_IoGetFreeVolumeSpace_Offset;
	Result<void> (*IoConnectionInterface_IoShowInOS) (const maxon::GenericComponent* this_, IOSHOWINOSFLAGS flags);
	maxon::Int IoConnectionInterface_IoShowInOS_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, IoConnectionInterface, GetUrl))
	{
		IoConnectionInterface_GetUrl = &W::IoConnectionInterface_GetUrl;
		IoConnectionInterface_GetUrl_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, IoConnectionInterface, GetBrowseIterator))
	{
		IoConnectionInterface_GetBrowseIterator = &W::IoConnectionInterface_GetBrowseIterator;
		IoConnectionInterface_GetBrowseIterator_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, IoConnectionInterface, OpenInputStream))
	{
		IoConnectionInterface_OpenInputStream = &W::IoConnectionInterface_OpenInputStream;
		IoConnectionInterface_OpenInputStream_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, IoConnectionInterface, OpenOutputStream))
	{
		IoConnectionInterface_OpenOutputStream = &W::IoConnectionInterface_OpenOutputStream;
		IoConnectionInterface_OpenOutputStream_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, IoConnectionInterface, OpenInOutputStream))
	{
		IoConnectionInterface_OpenInOutputStream = &W::IoConnectionInterface_OpenInOutputStream;
		IoConnectionInterface_OpenInOutputStream_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, IoConnectionInterface, GetContentLength))
	{
		IoConnectionInterface_GetContentLength = &W::IoConnectionInterface_GetContentLength;
		IoConnectionInterface_GetContentLength_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, IoConnectionInterface, IoDetect))
	{
		IoConnectionInterface_IoDetect = &W::IoConnectionInterface_IoDetect;
		IoConnectionInterface_IoDetect_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, IoConnectionInterface, IoGetAttributes))
	{
		IoConnectionInterface_IoGetAttributes = &W::IoConnectionInterface_IoGetAttributes;
		IoConnectionInterface_IoGetAttributes_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, IoConnectionInterface, IoSetAttributes))
	{
		IoConnectionInterface_IoSetAttributes = &W::IoConnectionInterface_IoSetAttributes;
		IoConnectionInterface_IoSetAttributes_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, IoConnectionInterface, IoGetTime))
	{
		IoConnectionInterface_IoGetTime = &W::IoConnectionInterface_IoGetTime;
		IoConnectionInterface_IoGetTime_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, IoConnectionInterface, IoSetTime))
	{
		IoConnectionInterface_IoSetTime = &W::IoConnectionInterface_IoSetTime;
		IoConnectionInterface_IoSetTime_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, IoConnectionInterface, IoDelete))
	{
		IoConnectionInterface_IoDelete = &W::IoConnectionInterface_IoDelete;
		IoConnectionInterface_IoDelete_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, IoConnectionInterface, IoCreateDirectory))
	{
		IoConnectionInterface_IoCreateDirectory = &W::IoConnectionInterface_IoCreateDirectory;
		IoConnectionInterface_IoCreateDirectory_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, IoConnectionInterface, IoCopyFile))
	{
		IoConnectionInterface_IoCopyFile = &W::IoConnectionInterface_IoCopyFile;
		IoConnectionInterface_IoCopyFile_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, IoConnectionInterface, IoCopyFileProgress))
	{
		IoConnectionInterface_IoCopyFileProgress = &W::IoConnectionInterface_IoCopyFileProgress;
		IoConnectionInterface_IoCopyFileProgress_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, IoConnectionInterface, IoMove))
	{
		IoConnectionInterface_IoMove = &W::IoConnectionInterface_IoMove;
		IoConnectionInterface_IoMove_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, IoConnectionInterface, IoRename))
	{
		IoConnectionInterface_IoRename = &W::IoConnectionInterface_IoRename;
		IoConnectionInterface_IoRename_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, IoConnectionInterface, IoGetFreeVolumeSpace))
	{
		IoConnectionInterface_IoGetFreeVolumeSpace = &W::IoConnectionInterface_IoGetFreeVolumeSpace;
		IoConnectionInterface_IoGetFreeVolumeSpace_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, IoConnectionInterface, IoShowInOS))
	{
		IoConnectionInterface_IoShowInOS = &W::IoConnectionInterface_IoShowInOS;
		IoConnectionInterface_IoShowInOS_Offset = offset;
	}
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<IoConnectionInterface, typename DataDictionaryObjectInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<IoConnectionInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct IoConnectionInterface::Hxx2
{
	class Unresolved;
	struct StaticMTable
	{
		static StaticMTable _instance;
		static StaticMTable _unresolvedInstance;
		static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, StaticMTable* tbl);
		static const maxon::Char* const _ids;
		static const maxon::NULL_RETURN_TYPE _returnTypes[];
	maxon::ObservableRef<ObservableErrorOpenFileDelegate> (*IoConnectionInterface_ObservableErrorOpenFile) ();
		StaticMTable() = default;
		template <typename IMPL> static void Init(StaticMTable* tbl)
		{
		tbl->IoConnectionInterface_ObservableErrorOpenFile = &IMPL::IoConnectionInterface_ObservableErrorOpenFile;
		}
	};
	template <typename S> class CWrapper : public DataDictionaryObjectInterface::Hxx2::template CWrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetBrowseIterator);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetContentLength);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetUrl);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(IoCopyFile);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(IoCopyFileProgress);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(IoCreateDirectory);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(IoDelete);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(IoDetect);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(IoGetAttributes);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(IoGetFreeVolumeSpace);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(IoGetTime);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(IoMove);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(IoRename);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(IoSetAttributes);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(IoSetTime);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(IoShowInOS);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(OpenInOutputStream);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(OpenInputStream);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(OpenOutputStream);
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename DataDictionaryObjectInterface::Hxx2::template CWrapper<S>;
			if (!S::Implementation::PROXY && !(Super0::InitMTablesWithBases(info, offset))) return false;
			auto* vt = (IoConnectionInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, IoConnectionInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		static const Url& IoConnectionInterface_GetUrl(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetUrl(); }
		static Result<IoBrowseRef> IoConnectionInterface_GetBrowseIterator(maxon::GenericComponent* this_, GETBROWSEITERATORFLAGS flags) { return ((typename S::Implementation*) this_)->GetBrowseIterator(flags); }
		static Result<InputStreamRef> IoConnectionInterface_OpenInputStream(maxon::GenericComponent* this_, OPENSTREAMFLAGS flags) { return ((typename S::Implementation*) this_)->OpenInputStream(flags); }
		static Result<OutputStreamRef> IoConnectionInterface_OpenOutputStream(maxon::GenericComponent* this_, OPENSTREAMFLAGS flags) { return ((typename S::Implementation*) this_)->OpenOutputStream(flags); }
		static Result<InOutputStreamRef> IoConnectionInterface_OpenInOutputStream(maxon::GenericComponent* this_, OPENSTREAMFLAGS flags) { return ((typename S::Implementation*) this_)->OpenInOutputStream(flags); }
		static Result<Int64> IoConnectionInterface_GetContentLength(maxon::GenericComponent* this_) { return ((typename S::Implementation*) this_)->GetContentLength(); }
		static IODETECT IoConnectionInterface_IoDetect(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->IoDetect(); }
		static Result<IOATTRIBUTES> IoConnectionInterface_IoGetAttributes(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->IoGetAttributes(); }
		static Result<void> IoConnectionInterface_IoSetAttributes(maxon::GenericComponent* this_, IOATTRIBUTES flags, IOATTRIBUTES mask) { return ((typename S::Implementation*) this_)->IoSetAttributes(flags, mask); }
		static Result<UniversalDateTime> IoConnectionInterface_IoGetTime(const maxon::GenericComponent* this_, IOTIMEMODE mode) { return ((const typename S::Implementation*) this_)->IoGetTime(mode); }
		static Result<void> IoConnectionInterface_IoSetTime(maxon::GenericComponent* this_, IOTIMEMODE mode, const UniversalDateTime& dateTime) { return ((typename S::Implementation*) this_)->IoSetTime(mode, dateTime); }
		static Result<void> IoConnectionInterface_IoDelete(maxon::GenericComponent* this_, Bool force) { return ((typename S::Implementation*) this_)->IoDelete(force); }
		static Result<void> IoConnectionInterface_IoCreateDirectory(maxon::GenericComponent* this_, Bool createParents, BaseArray<Url>* createdDirs) { return ((typename S::Implementation*) this_)->IoCreateDirectory(createParents, createdDirs); }
		static Result<void> IoConnectionInterface_IoCopyFile(maxon::GenericComponent* this_, const Url& destName, Bool overwrite, Bool removeReadOnly) { return ((typename S::Implementation*) this_)->IoCopyFile(destName, overwrite, removeReadOnly); }
		static Result<void> IoConnectionInterface_IoCopyFileProgress(maxon::GenericComponent* this_, const Url& destName, Bool overwrite, Bool removeReadOnly, const IoProgressDelegate& progress) { return ((typename S::Implementation*) this_)->IoCopyFileProgress(destName, overwrite, removeReadOnly, progress); }
		static Result<void> IoConnectionInterface_IoMove(maxon::GenericComponent* this_, const Url& destName) { return ((typename S::Implementation*) this_)->IoMove(destName); }
		static Result<void> IoConnectionInterface_IoRename(maxon::GenericComponent* this_, const Url& newName) { return ((typename S::Implementation*) this_)->IoRename(newName); }
		static Result<void> IoConnectionInterface_IoGetFreeVolumeSpace(const maxon::GenericComponent* this_, Int64& availableBytes, Int64& totalBytes) { return ((const typename S::Implementation*) this_)->IoGetFreeVolumeSpace(availableBytes, totalBytes); }
		static Result<void> IoConnectionInterface_IoShowInOS(const maxon::GenericComponent* this_, IOSHOWINOSFLAGS flags) { return ((const typename S::Implementation*) this_)->IoShowInOS(flags); }
		static maxon::ObservableRef<ObservableErrorOpenFileDelegate> IoConnectionInterface_ObservableErrorOpenFile() { return S::Implementation::ObservableErrorOpenFile(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto IoConnectionInterface::GetUrl() const -> const Url&
{
	const IoConnectionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(IoConnectionInterface, this); return mt_.IoConnectionInterface_GetUrl((const maxon::GenericComponent*) this + mt_.IoConnectionInterface_GetUrl_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto IoConnectionInterface::GetBrowseIterator(GETBROWSEITERATORFLAGS flags) -> Result<IoBrowseRef>
{
	const IoConnectionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(IoConnectionInterface, this); return mt_.IoConnectionInterface_GetBrowseIterator((maxon::GenericComponent*) this + mt_.IoConnectionInterface_GetBrowseIterator_Offset, flags);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto IoConnectionInterface::OpenInputStream(OPENSTREAMFLAGS flags) -> Result<InputStreamRef>
{
	const IoConnectionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(IoConnectionInterface, this); return mt_.IoConnectionInterface_OpenInputStream((maxon::GenericComponent*) this + mt_.IoConnectionInterface_OpenInputStream_Offset, flags);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto IoConnectionInterface::OpenOutputStream(OPENSTREAMFLAGS flags) -> Result<OutputStreamRef>
{
	const IoConnectionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(IoConnectionInterface, this); return mt_.IoConnectionInterface_OpenOutputStream((maxon::GenericComponent*) this + mt_.IoConnectionInterface_OpenOutputStream_Offset, flags);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto IoConnectionInterface::OpenInOutputStream(OPENSTREAMFLAGS flags) -> Result<InOutputStreamRef>
{
	const IoConnectionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(IoConnectionInterface, this); return mt_.IoConnectionInterface_OpenInOutputStream((maxon::GenericComponent*) this + mt_.IoConnectionInterface_OpenInOutputStream_Offset, flags);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto IoConnectionInterface::GetContentLength() -> Result<Int64>
{
	const IoConnectionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(IoConnectionInterface, this); return mt_.IoConnectionInterface_GetContentLength((maxon::GenericComponent*) this + mt_.IoConnectionInterface_GetContentLength_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto IoConnectionInterface::IoDetect() const -> IODETECT
{
	const IoConnectionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(IoConnectionInterface, this); return mt_.IoConnectionInterface_IoDetect((const maxon::GenericComponent*) this + mt_.IoConnectionInterface_IoDetect_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto IoConnectionInterface::IoGetAttributes() const -> Result<IOATTRIBUTES>
{
	const IoConnectionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(IoConnectionInterface, this); return mt_.IoConnectionInterface_IoGetAttributes((const maxon::GenericComponent*) this + mt_.IoConnectionInterface_IoGetAttributes_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto IoConnectionInterface::IoSetAttributes(IOATTRIBUTES flags, IOATTRIBUTES mask) -> Result<void>
{
	const IoConnectionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(IoConnectionInterface, this); return mt_.IoConnectionInterface_IoSetAttributes((maxon::GenericComponent*) this + mt_.IoConnectionInterface_IoSetAttributes_Offset, flags, mask);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto IoConnectionInterface::IoGetTime(IOTIMEMODE mode) const -> Result<UniversalDateTime>
{
	const IoConnectionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(IoConnectionInterface, this); return mt_.IoConnectionInterface_IoGetTime((const maxon::GenericComponent*) this + mt_.IoConnectionInterface_IoGetTime_Offset, mode);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto IoConnectionInterface::IoSetTime(IOTIMEMODE mode, const UniversalDateTime& dateTime) -> Result<void>
{
	const IoConnectionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(IoConnectionInterface, this); return mt_.IoConnectionInterface_IoSetTime((maxon::GenericComponent*) this + mt_.IoConnectionInterface_IoSetTime_Offset, mode, dateTime);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto IoConnectionInterface::IoDelete(Bool force) -> Result<void>
{
	const IoConnectionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(IoConnectionInterface, this); return mt_.IoConnectionInterface_IoDelete((maxon::GenericComponent*) this + mt_.IoConnectionInterface_IoDelete_Offset, force);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto IoConnectionInterface::IoCreateDirectory(Bool createParents, BaseArray<Url>* createdDirs) -> Result<void>
{
	const IoConnectionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(IoConnectionInterface, this); return mt_.IoConnectionInterface_IoCreateDirectory((maxon::GenericComponent*) this + mt_.IoConnectionInterface_IoCreateDirectory_Offset, createParents, createdDirs);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto IoConnectionInterface::IoCopyFile(const Url& destName, Bool overwrite, Bool removeReadOnly) -> Result<void>
{
	const IoConnectionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(IoConnectionInterface, this); return mt_.IoConnectionInterface_IoCopyFile((maxon::GenericComponent*) this + mt_.IoConnectionInterface_IoCopyFile_Offset, destName, overwrite, removeReadOnly);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto IoConnectionInterface::IoCopyFileProgress(const Url& destName, Bool overwrite, Bool removeReadOnly, const IoProgressDelegate& progress) -> Result<void>
{
	const IoConnectionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(IoConnectionInterface, this); return mt_.IoConnectionInterface_IoCopyFileProgress((maxon::GenericComponent*) this + mt_.IoConnectionInterface_IoCopyFileProgress_Offset, destName, overwrite, removeReadOnly, progress);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto IoConnectionInterface::IoMove(const Url& destName) -> Result<void>
{
	const IoConnectionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(IoConnectionInterface, this); return mt_.IoConnectionInterface_IoMove((maxon::GenericComponent*) this + mt_.IoConnectionInterface_IoMove_Offset, destName);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto IoConnectionInterface::IoRename(const Url& newName) -> Result<void>
{
	const IoConnectionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(IoConnectionInterface, this); return mt_.IoConnectionInterface_IoRename((maxon::GenericComponent*) this + mt_.IoConnectionInterface_IoRename_Offset, newName);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto IoConnectionInterface::IoGetFreeVolumeSpace(Int64& availableBytes, Int64& totalBytes) const -> Result<void>
{
	const IoConnectionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(IoConnectionInterface, this); return mt_.IoConnectionInterface_IoGetFreeVolumeSpace((const maxon::GenericComponent*) this + mt_.IoConnectionInterface_IoGetFreeVolumeSpace_Offset, availableBytes, totalBytes);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto IoConnectionInterface::IoShowInOS(IOSHOWINOSFLAGS flags) const -> Result<void>
{
	const IoConnectionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(IoConnectionInterface, this); return mt_.IoConnectionInterface_IoShowInOS((const maxon::GenericComponent*) this + mt_.IoConnectionInterface_IoShowInOS_Offset, flags);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto IoConnectionInterface::ObservableErrorOpenFile() -> maxon::ObservableRef<ObservableErrorOpenFileDelegate>
{
	return Hxx2::StaticMTable::_instance.IoConnectionInterface_ObservableErrorOpenFile();
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoConnectionInterface::Hxx1::ConstFn<S>::GetUrl() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const Url&>, const Url&>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const Url&>, const Url&>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const IoConnectionInterface* o_ = (const IoConnectionInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = IoConnectionInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<const Url&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(IoConnectionInterface, o_, IoConnectionInterface_GetUrl) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<IoConnectionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<IoConnectionInterface>() : PRIVATE_MAXON_VTABLE(IoConnectionInterface, o_); 
	return (mt_.IoConnectionInterface_GetUrl(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.IoConnectionInterface_GetUrl_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoConnectionInterface::Hxx1::Fn<S>::GetBrowseIterator(GETBROWSEITERATORFLAGS flags) const -> Result<IoBrowseRef>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<IoBrowseRef>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); IoConnectionInterface* o_ = (IoConnectionInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(IoConnectionInterface, o_, IoConnectionInterface_GetBrowseIterator) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<IoConnectionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<IoConnectionInterface>() : PRIVATE_MAXON_VTABLE(IoConnectionInterface, o_); 
	return (mt_.IoConnectionInterface_GetBrowseIterator(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.IoConnectionInterface_GetBrowseIterator_Offset, flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoConnectionInterface::Hxx1::COWFn<S>::GetBrowseIterator(GETBROWSEITERATORFLAGS flags) -> Result<IoBrowseRef>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<IoBrowseRef>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); IoConnectionInterface* o_ = (IoConnectionInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(IoConnectionInterface, o_, IoConnectionInterface_GetBrowseIterator) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<IoConnectionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<IoConnectionInterface>() : PRIVATE_MAXON_VTABLE(IoConnectionInterface, o_); 
	return (mt_.IoConnectionInterface_GetBrowseIterator(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.IoConnectionInterface_GetBrowseIterator_Offset, flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoConnectionInterface::Hxx1::Fn<S>::OpenInputStream(OPENSTREAMFLAGS flags) const -> Result<InputStreamRef>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<InputStreamRef>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); IoConnectionInterface* o_ = (IoConnectionInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(IoConnectionInterface, o_, IoConnectionInterface_OpenInputStream) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<IoConnectionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<IoConnectionInterface>() : PRIVATE_MAXON_VTABLE(IoConnectionInterface, o_); 
	return (mt_.IoConnectionInterface_OpenInputStream(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.IoConnectionInterface_OpenInputStream_Offset, flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoConnectionInterface::Hxx1::COWFn<S>::OpenInputStream(OPENSTREAMFLAGS flags) -> Result<InputStreamRef>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<InputStreamRef>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); IoConnectionInterface* o_ = (IoConnectionInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(IoConnectionInterface, o_, IoConnectionInterface_OpenInputStream) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<IoConnectionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<IoConnectionInterface>() : PRIVATE_MAXON_VTABLE(IoConnectionInterface, o_); 
	return (mt_.IoConnectionInterface_OpenInputStream(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.IoConnectionInterface_OpenInputStream_Offset, flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoConnectionInterface::Hxx1::Fn<S>::OpenOutputStream(OPENSTREAMFLAGS flags) const -> Result<OutputStreamRef>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<OutputStreamRef>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); IoConnectionInterface* o_ = (IoConnectionInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(IoConnectionInterface, o_, IoConnectionInterface_OpenOutputStream) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<IoConnectionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<IoConnectionInterface>() : PRIVATE_MAXON_VTABLE(IoConnectionInterface, o_); 
	return (mt_.IoConnectionInterface_OpenOutputStream(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.IoConnectionInterface_OpenOutputStream_Offset, flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoConnectionInterface::Hxx1::COWFn<S>::OpenOutputStream(OPENSTREAMFLAGS flags) -> Result<OutputStreamRef>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<OutputStreamRef>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); IoConnectionInterface* o_ = (IoConnectionInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(IoConnectionInterface, o_, IoConnectionInterface_OpenOutputStream) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<IoConnectionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<IoConnectionInterface>() : PRIVATE_MAXON_VTABLE(IoConnectionInterface, o_); 
	return (mt_.IoConnectionInterface_OpenOutputStream(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.IoConnectionInterface_OpenOutputStream_Offset, flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoConnectionInterface::Hxx1::Fn<S>::OpenInOutputStream(OPENSTREAMFLAGS flags) const -> Result<InOutputStreamRef>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<InOutputStreamRef>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); IoConnectionInterface* o_ = (IoConnectionInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(IoConnectionInterface, o_, IoConnectionInterface_OpenInOutputStream) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<IoConnectionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<IoConnectionInterface>() : PRIVATE_MAXON_VTABLE(IoConnectionInterface, o_); 
	return (mt_.IoConnectionInterface_OpenInOutputStream(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.IoConnectionInterface_OpenInOutputStream_Offset, flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoConnectionInterface::Hxx1::COWFn<S>::OpenInOutputStream(OPENSTREAMFLAGS flags) -> Result<InOutputStreamRef>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<InOutputStreamRef>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); IoConnectionInterface* o_ = (IoConnectionInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(IoConnectionInterface, o_, IoConnectionInterface_OpenInOutputStream) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<IoConnectionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<IoConnectionInterface>() : PRIVATE_MAXON_VTABLE(IoConnectionInterface, o_); 
	return (mt_.IoConnectionInterface_OpenInOutputStream(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.IoConnectionInterface_OpenInOutputStream_Offset, flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoConnectionInterface::Hxx1::Fn<S>::GetContentLength() const -> Result<Int64>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Int64>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); IoConnectionInterface* o_ = (IoConnectionInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(IoConnectionInterface, o_, IoConnectionInterface_GetContentLength) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<IoConnectionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<IoConnectionInterface>() : PRIVATE_MAXON_VTABLE(IoConnectionInterface, o_); 
	return (mt_.IoConnectionInterface_GetContentLength(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.IoConnectionInterface_GetContentLength_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoConnectionInterface::Hxx1::COWFn<S>::GetContentLength() -> Result<Int64>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Int64>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); IoConnectionInterface* o_ = (IoConnectionInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(IoConnectionInterface, o_, IoConnectionInterface_GetContentLength) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<IoConnectionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<IoConnectionInterface>() : PRIVATE_MAXON_VTABLE(IoConnectionInterface, o_); 
	return (mt_.IoConnectionInterface_GetContentLength(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.IoConnectionInterface_GetContentLength_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoConnectionInterface::Hxx1::ConstFn<S>::IoDetect() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<IODETECT>, IODETECT>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<IODETECT>, IODETECT>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const IoConnectionInterface* o_ = (const IoConnectionInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = IoConnectionInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<IODETECT>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(IoConnectionInterface, o_, IoConnectionInterface_IoDetect) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<IoConnectionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<IoConnectionInterface>() : PRIVATE_MAXON_VTABLE(IoConnectionInterface, o_); 
	return (mt_.IoConnectionInterface_IoDetect(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.IoConnectionInterface_IoDetect_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoConnectionInterface::Hxx1::ConstFn<S>::IoGetAttributes() const -> Result<IOATTRIBUTES>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<IOATTRIBUTES>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const IoConnectionInterface* o_ = (const IoConnectionInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = IoConnectionInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(IoConnectionInterface, o_, IoConnectionInterface_IoGetAttributes) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<IoConnectionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<IoConnectionInterface>() : PRIVATE_MAXON_VTABLE(IoConnectionInterface, o_); 
	return (mt_.IoConnectionInterface_IoGetAttributes(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.IoConnectionInterface_IoGetAttributes_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoConnectionInterface::Hxx1::Fn<S>::IoSetAttributes(IOATTRIBUTES flags, IOATTRIBUTES mask) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); IoConnectionInterface* o_ = (IoConnectionInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(IoConnectionInterface, o_, IoConnectionInterface_IoSetAttributes) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<IoConnectionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<IoConnectionInterface>() : PRIVATE_MAXON_VTABLE(IoConnectionInterface, o_); 
	return (mt_.IoConnectionInterface_IoSetAttributes(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.IoConnectionInterface_IoSetAttributes_Offset, flags, mask));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoConnectionInterface::Hxx1::COWFn<S>::IoSetAttributes(IOATTRIBUTES flags, IOATTRIBUTES mask) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); IoConnectionInterface* o_ = (IoConnectionInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(IoConnectionInterface, o_, IoConnectionInterface_IoSetAttributes) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<IoConnectionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<IoConnectionInterface>() : PRIVATE_MAXON_VTABLE(IoConnectionInterface, o_); 
	return (mt_.IoConnectionInterface_IoSetAttributes(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.IoConnectionInterface_IoSetAttributes_Offset, flags, mask));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoConnectionInterface::Hxx1::ConstFn<S>::IoGetTime(IOTIMEMODE mode) const -> Result<UniversalDateTime>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<UniversalDateTime>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const IoConnectionInterface* o_ = (const IoConnectionInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = IoConnectionInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(IoConnectionInterface, o_, IoConnectionInterface_IoGetTime) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<IoConnectionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<IoConnectionInterface>() : PRIVATE_MAXON_VTABLE(IoConnectionInterface, o_); 
	return (mt_.IoConnectionInterface_IoGetTime(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.IoConnectionInterface_IoGetTime_Offset, mode));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoConnectionInterface::Hxx1::Fn<S>::IoSetTime(IOTIMEMODE mode, const UniversalDateTime& dateTime) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); IoConnectionInterface* o_ = (IoConnectionInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(IoConnectionInterface, o_, IoConnectionInterface_IoSetTime) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<IoConnectionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<IoConnectionInterface>() : PRIVATE_MAXON_VTABLE(IoConnectionInterface, o_); 
	return (mt_.IoConnectionInterface_IoSetTime(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.IoConnectionInterface_IoSetTime_Offset, mode, dateTime));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoConnectionInterface::Hxx1::COWFn<S>::IoSetTime(IOTIMEMODE mode, const UniversalDateTime& dateTime) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); IoConnectionInterface* o_ = (IoConnectionInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(IoConnectionInterface, o_, IoConnectionInterface_IoSetTime) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<IoConnectionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<IoConnectionInterface>() : PRIVATE_MAXON_VTABLE(IoConnectionInterface, o_); 
	return (mt_.IoConnectionInterface_IoSetTime(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.IoConnectionInterface_IoSetTime_Offset, mode, dateTime));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoConnectionInterface::Hxx1::Fn<S>::IoDelete(Bool force) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); IoConnectionInterface* o_ = (IoConnectionInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(IoConnectionInterface, o_, IoConnectionInterface_IoDelete) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<IoConnectionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<IoConnectionInterface>() : PRIVATE_MAXON_VTABLE(IoConnectionInterface, o_); 
	return (mt_.IoConnectionInterface_IoDelete(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.IoConnectionInterface_IoDelete_Offset, force));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoConnectionInterface::Hxx1::COWFn<S>::IoDelete(Bool force) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); IoConnectionInterface* o_ = (IoConnectionInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(IoConnectionInterface, o_, IoConnectionInterface_IoDelete) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<IoConnectionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<IoConnectionInterface>() : PRIVATE_MAXON_VTABLE(IoConnectionInterface, o_); 
	return (mt_.IoConnectionInterface_IoDelete(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.IoConnectionInterface_IoDelete_Offset, force));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoConnectionInterface::Hxx1::Fn<S>::IoCreateDirectory(Bool createParents, BaseArray<Url>* createdDirs) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); IoConnectionInterface* o_ = (IoConnectionInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(IoConnectionInterface, o_, IoConnectionInterface_IoCreateDirectory) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<IoConnectionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<IoConnectionInterface>() : PRIVATE_MAXON_VTABLE(IoConnectionInterface, o_); 
	return (mt_.IoConnectionInterface_IoCreateDirectory(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.IoConnectionInterface_IoCreateDirectory_Offset, createParents, createdDirs));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoConnectionInterface::Hxx1::COWFn<S>::IoCreateDirectory(Bool createParents, BaseArray<Url>* createdDirs) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); IoConnectionInterface* o_ = (IoConnectionInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(IoConnectionInterface, o_, IoConnectionInterface_IoCreateDirectory) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<IoConnectionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<IoConnectionInterface>() : PRIVATE_MAXON_VTABLE(IoConnectionInterface, o_); 
	return (mt_.IoConnectionInterface_IoCreateDirectory(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.IoConnectionInterface_IoCreateDirectory_Offset, createParents, createdDirs));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoConnectionInterface::Hxx1::Fn<S>::IoCopyFile(const Url& destName, Bool overwrite, Bool removeReadOnly) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); IoConnectionInterface* o_ = (IoConnectionInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(IoConnectionInterface, o_, IoConnectionInterface_IoCopyFile) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<IoConnectionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<IoConnectionInterface>() : PRIVATE_MAXON_VTABLE(IoConnectionInterface, o_); 
	return (mt_.IoConnectionInterface_IoCopyFile(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.IoConnectionInterface_IoCopyFile_Offset, destName, overwrite, removeReadOnly));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoConnectionInterface::Hxx1::COWFn<S>::IoCopyFile(const Url& destName, Bool overwrite, Bool removeReadOnly) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); IoConnectionInterface* o_ = (IoConnectionInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(IoConnectionInterface, o_, IoConnectionInterface_IoCopyFile) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<IoConnectionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<IoConnectionInterface>() : PRIVATE_MAXON_VTABLE(IoConnectionInterface, o_); 
	return (mt_.IoConnectionInterface_IoCopyFile(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.IoConnectionInterface_IoCopyFile_Offset, destName, overwrite, removeReadOnly));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoConnectionInterface::Hxx1::Fn<S>::IoCopyFileProgress(const Url& destName, Bool overwrite, Bool removeReadOnly, const IoProgressDelegate& progress) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); IoConnectionInterface* o_ = (IoConnectionInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(IoConnectionInterface, o_, IoConnectionInterface_IoCopyFileProgress) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<IoConnectionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<IoConnectionInterface>() : PRIVATE_MAXON_VTABLE(IoConnectionInterface, o_); 
	return (mt_.IoConnectionInterface_IoCopyFileProgress(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.IoConnectionInterface_IoCopyFileProgress_Offset, destName, overwrite, removeReadOnly, progress));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoConnectionInterface::Hxx1::COWFn<S>::IoCopyFileProgress(const Url& destName, Bool overwrite, Bool removeReadOnly, const IoProgressDelegate& progress) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); IoConnectionInterface* o_ = (IoConnectionInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(IoConnectionInterface, o_, IoConnectionInterface_IoCopyFileProgress) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<IoConnectionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<IoConnectionInterface>() : PRIVATE_MAXON_VTABLE(IoConnectionInterface, o_); 
	return (mt_.IoConnectionInterface_IoCopyFileProgress(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.IoConnectionInterface_IoCopyFileProgress_Offset, destName, overwrite, removeReadOnly, progress));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoConnectionInterface::Hxx1::Fn<S>::IoMove(const Url& destName) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); IoConnectionInterface* o_ = (IoConnectionInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(IoConnectionInterface, o_, IoConnectionInterface_IoMove) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<IoConnectionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<IoConnectionInterface>() : PRIVATE_MAXON_VTABLE(IoConnectionInterface, o_); 
	return (mt_.IoConnectionInterface_IoMove(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.IoConnectionInterface_IoMove_Offset, destName));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoConnectionInterface::Hxx1::COWFn<S>::IoMove(const Url& destName) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); IoConnectionInterface* o_ = (IoConnectionInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(IoConnectionInterface, o_, IoConnectionInterface_IoMove) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<IoConnectionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<IoConnectionInterface>() : PRIVATE_MAXON_VTABLE(IoConnectionInterface, o_); 
	return (mt_.IoConnectionInterface_IoMove(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.IoConnectionInterface_IoMove_Offset, destName));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoConnectionInterface::Hxx1::Fn<S>::IoRename(const Url& newName) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); IoConnectionInterface* o_ = (IoConnectionInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(IoConnectionInterface, o_, IoConnectionInterface_IoRename) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<IoConnectionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<IoConnectionInterface>() : PRIVATE_MAXON_VTABLE(IoConnectionInterface, o_); 
	return (mt_.IoConnectionInterface_IoRename(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.IoConnectionInterface_IoRename_Offset, newName));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoConnectionInterface::Hxx1::COWFn<S>::IoRename(const Url& newName) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); IoConnectionInterface* o_ = (IoConnectionInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(IoConnectionInterface, o_, IoConnectionInterface_IoRename) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<IoConnectionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<IoConnectionInterface>() : PRIVATE_MAXON_VTABLE(IoConnectionInterface, o_); 
	return (mt_.IoConnectionInterface_IoRename(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.IoConnectionInterface_IoRename_Offset, newName));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoConnectionInterface::Hxx1::ConstFn<S>::IoGetFreeVolumeSpace(Int64& availableBytes, Int64& totalBytes) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const IoConnectionInterface* o_ = (const IoConnectionInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = IoConnectionInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(IoConnectionInterface, o_, IoConnectionInterface_IoGetFreeVolumeSpace) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<IoConnectionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<IoConnectionInterface>() : PRIVATE_MAXON_VTABLE(IoConnectionInterface, o_); 
	return (mt_.IoConnectionInterface_IoGetFreeVolumeSpace(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.IoConnectionInterface_IoGetFreeVolumeSpace_Offset, availableBytes, totalBytes));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoConnectionInterface::Hxx1::ConstFn<S>::IoShowInOS(IOSHOWINOSFLAGS flags) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const IoConnectionInterface* o_ = (const IoConnectionInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = IoConnectionInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(IoConnectionInterface, o_, IoConnectionInterface_IoShowInOS) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<IoConnectionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<IoConnectionInterface>() : PRIVATE_MAXON_VTABLE(IoConnectionInterface, o_); 
	return (mt_.IoConnectionInterface_IoShowInOS(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.IoConnectionInterface_IoShowInOS_Offset, flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoConnectionInterface::Hxx1::ConstFn<S>::ObservableErrorOpenFile() -> maxon::ObservableRef<ObservableErrorOpenFileDelegate>
{
	return (Hxx2::StaticMTable::_instance.IoConnectionInterface_ObservableErrorOpenFile());
}
auto IoConnectionInterface::GetPtr() -> Ptr { return Ptr(this); }
auto IoConnectionInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_ioconnection)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_IoConnectionInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_IoConnectionInterface() { new (s_ui_maxon_IoConnectionInterface) maxon::EntityUse(IoConnectionInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/ioconnection.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_IoConnectionInterface(IoConnectionInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/ioconnection.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_ioconnection)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_usi_maxon_IoConnectionInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_usi_maxon_IoConnectionInterface() { new (s_usi_maxon_IoConnectionInterface) maxon::EntityUse(IoConnectionInterface::_staticInterface.GetReference(), &maxon::g_translationUnit, "maxon/ioconnection.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_usi_maxon_IoConnectionInterface(IoConnectionInterface::_staticInterface.GetReference(), &maxon::g_translationUnit, "maxon/ioconnection.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

