
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
	PRIVATE_MAXON_SF_POINTER(ResolveInterface_Free, Free, MAXON_EXPAND_VA_ARGS, (void), const ResolveInterface* object);
	PRIVATE_MAXON_SF_POINTER(ResolveInterface_RemoveDotSegments, RemoveDotSegments, MAXON_EXPAND_VA_ARGS, (Result<Url>), const Url& url);
	template <typename IMPL> void Init()
	{
		ResolveInterface_Free = ResolveInterface_Free_GetPtr<IMPL>(true);
		ResolveInterface_RemoveDotSegments = ResolveInterface_RemoveDotSegments_GetPtr<IMPL>(true);
	}
};

struct ResolveInterface::Hxx2
{
	class Unresolved;
	template <typename C> class Wrapper
	{
	public:
		using Implementation = C;
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
	PRIVATE_MAXON_MF_POINTER(IoConnectionInterface_GetUrl, GetUrl, true, maxon::GenericComponent, const, (const Url&));
	maxon::Int IoConnectionInterface_GetUrl_Offset;
	PRIVATE_MAXON_MF_POINTER(IoConnectionInterface_GetBrowseIterator, GetBrowseIterator, true, maxon::GenericComponent,, (Result<IoBrowseRef>), GETBROWSEITERATORFLAGS flags);
	maxon::Int IoConnectionInterface_GetBrowseIterator_Offset;
	PRIVATE_MAXON_MF_POINTER(IoConnectionInterface_OpenInputStream, OpenInputStream, true, maxon::GenericComponent,, (Result<InputStreamRef>), OPENSTREAMFLAGS flags);
	maxon::Int IoConnectionInterface_OpenInputStream_Offset;
	PRIVATE_MAXON_MF_POINTER(IoConnectionInterface_OpenOutputStream, OpenOutputStream, true, maxon::GenericComponent,, (Result<OutputStreamRef>), OPENSTREAMFLAGS flags);
	maxon::Int IoConnectionInterface_OpenOutputStream_Offset;
	PRIVATE_MAXON_MF_POINTER(IoConnectionInterface_OpenInOutputStream, OpenInOutputStream, true, maxon::GenericComponent,, (Result<InOutputStreamRef>), OPENSTREAMFLAGS flags);
	maxon::Int IoConnectionInterface_OpenInOutputStream_Offset;
	PRIVATE_MAXON_MF_POINTER(IoConnectionInterface_GetContentLength, GetContentLength, true, maxon::GenericComponent,, (Result<Int64>));
	maxon::Int IoConnectionInterface_GetContentLength_Offset;
	PRIVATE_MAXON_MF_POINTER(IoConnectionInterface_IoDetect, IoDetect, true, maxon::GenericComponent, const, (IODETECT));
	maxon::Int IoConnectionInterface_IoDetect_Offset;
	PRIVATE_MAXON_MF_POINTER(IoConnectionInterface_IoGetAttributes, IoGetAttributes, true, maxon::GenericComponent, const, (Result<IOATTRIBUTES>));
	maxon::Int IoConnectionInterface_IoGetAttributes_Offset;
	PRIVATE_MAXON_MF_POINTER(IoConnectionInterface_IoSetAttributes, IoSetAttributes, true, maxon::GenericComponent,, (Result<void>), IOATTRIBUTES flags, IOATTRIBUTES mask);
	maxon::Int IoConnectionInterface_IoSetAttributes_Offset;
	PRIVATE_MAXON_MF_POINTER(IoConnectionInterface_IoGetTime, IoGetTime, true, maxon::GenericComponent, const, (Result<UniversalDateTime>), IOTIMEMODE mode);
	maxon::Int IoConnectionInterface_IoGetTime_Offset;
	PRIVATE_MAXON_MF_POINTER(IoConnectionInterface_IoSetTime, IoSetTime, true, maxon::GenericComponent,, (Result<void>), IOTIMEMODE mode, const UniversalDateTime& dateTime);
	maxon::Int IoConnectionInterface_IoSetTime_Offset;
	PRIVATE_MAXON_MF_POINTER(IoConnectionInterface_IoDelete, IoDelete, true, maxon::GenericComponent,, (Result<void>), Bool force);
	maxon::Int IoConnectionInterface_IoDelete_Offset;
	PRIVATE_MAXON_MF_POINTER(IoConnectionInterface_IoCreateDirectory, IoCreateDirectory, true, maxon::GenericComponent,, (Result<void>), Bool createParents, BaseArray<Url>* createdDirs);
	maxon::Int IoConnectionInterface_IoCreateDirectory_Offset;
	PRIVATE_MAXON_MF_POINTER(IoConnectionInterface_IoCopyFile, IoCopyFile, true, maxon::GenericComponent,, (Result<void>), const Url& destName, Bool overwrite, Bool removeReadOnly);
	maxon::Int IoConnectionInterface_IoCopyFile_Offset;
	PRIVATE_MAXON_MF_POINTER(IoConnectionInterface_IoCopyFileProgress, IoCopyFileProgress, true, maxon::GenericComponent,, (Result<void>), const Url& destName, Bool overwrite, Bool removeReadOnly, const IoProgressDelegate& progress);
	maxon::Int IoConnectionInterface_IoCopyFileProgress_Offset;
	PRIVATE_MAXON_MF_POINTER(IoConnectionInterface_IoMove, IoMove, true, maxon::GenericComponent,, (Result<void>), const Url& destName);
	maxon::Int IoConnectionInterface_IoMove_Offset;
	PRIVATE_MAXON_MF_POINTER(IoConnectionInterface_IoRename, IoRename, true, maxon::GenericComponent,, (Result<void>), const Url& newName);
	maxon::Int IoConnectionInterface_IoRename_Offset;
	PRIVATE_MAXON_MF_POINTER(IoConnectionInterface_IoGetFreeVolumeSpace, IoGetFreeVolumeSpace, true, maxon::GenericComponent, const, (Result<void>), Int64& availableBytes, Int64& totalBytes);
	maxon::Int IoConnectionInterface_IoGetFreeVolumeSpace_Offset;
	PRIVATE_MAXON_MF_POINTER(IoConnectionInterface_IoShowInOS, IoShowInOS, true, maxon::GenericComponent, const, (Result<void>), IOSHOWINOSFLAGS flags);
	maxon::Int IoConnectionInterface_IoShowInOS_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, IoConnectionInterface, GetUrl))
	{
		maxon::Tie(IoConnectionInterface_GetUrl, IoConnectionInterface_GetUrl_Offset) = IoConnectionInterface_GetUrl_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, IoConnectionInterface, GetBrowseIterator))
	{
		maxon::Tie(IoConnectionInterface_GetBrowseIterator, IoConnectionInterface_GetBrowseIterator_Offset) = IoConnectionInterface_GetBrowseIterator_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, IoConnectionInterface, OpenInputStream))
	{
		maxon::Tie(IoConnectionInterface_OpenInputStream, IoConnectionInterface_OpenInputStream_Offset) = IoConnectionInterface_OpenInputStream_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, IoConnectionInterface, OpenOutputStream))
	{
		maxon::Tie(IoConnectionInterface_OpenOutputStream, IoConnectionInterface_OpenOutputStream_Offset) = IoConnectionInterface_OpenOutputStream_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, IoConnectionInterface, OpenInOutputStream))
	{
		maxon::Tie(IoConnectionInterface_OpenInOutputStream, IoConnectionInterface_OpenInOutputStream_Offset) = IoConnectionInterface_OpenInOutputStream_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, IoConnectionInterface, GetContentLength))
	{
		maxon::Tie(IoConnectionInterface_GetContentLength, IoConnectionInterface_GetContentLength_Offset) = IoConnectionInterface_GetContentLength_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, IoConnectionInterface, IoDetect))
	{
		maxon::Tie(IoConnectionInterface_IoDetect, IoConnectionInterface_IoDetect_Offset) = IoConnectionInterface_IoDetect_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, IoConnectionInterface, IoGetAttributes))
	{
		maxon::Tie(IoConnectionInterface_IoGetAttributes, IoConnectionInterface_IoGetAttributes_Offset) = IoConnectionInterface_IoGetAttributes_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, IoConnectionInterface, IoSetAttributes))
	{
		maxon::Tie(IoConnectionInterface_IoSetAttributes, IoConnectionInterface_IoSetAttributes_Offset) = IoConnectionInterface_IoSetAttributes_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, IoConnectionInterface, IoGetTime))
	{
		maxon::Tie(IoConnectionInterface_IoGetTime, IoConnectionInterface_IoGetTime_Offset) = IoConnectionInterface_IoGetTime_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, IoConnectionInterface, IoSetTime))
	{
		maxon::Tie(IoConnectionInterface_IoSetTime, IoConnectionInterface_IoSetTime_Offset) = IoConnectionInterface_IoSetTime_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, IoConnectionInterface, IoDelete))
	{
		maxon::Tie(IoConnectionInterface_IoDelete, IoConnectionInterface_IoDelete_Offset) = IoConnectionInterface_IoDelete_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, IoConnectionInterface, IoCreateDirectory))
	{
		maxon::Tie(IoConnectionInterface_IoCreateDirectory, IoConnectionInterface_IoCreateDirectory_Offset) = IoConnectionInterface_IoCreateDirectory_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, IoConnectionInterface, IoCopyFile))
	{
		maxon::Tie(IoConnectionInterface_IoCopyFile, IoConnectionInterface_IoCopyFile_Offset) = IoConnectionInterface_IoCopyFile_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, IoConnectionInterface, IoCopyFileProgress))
	{
		maxon::Tie(IoConnectionInterface_IoCopyFileProgress, IoConnectionInterface_IoCopyFileProgress_Offset) = IoConnectionInterface_IoCopyFileProgress_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, IoConnectionInterface, IoMove))
	{
		maxon::Tie(IoConnectionInterface_IoMove, IoConnectionInterface_IoMove_Offset) = IoConnectionInterface_IoMove_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, IoConnectionInterface, IoRename))
	{
		maxon::Tie(IoConnectionInterface_IoRename, IoConnectionInterface_IoRename_Offset) = IoConnectionInterface_IoRename_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, IoConnectionInterface, IoGetFreeVolumeSpace))
	{
		maxon::Tie(IoConnectionInterface_IoGetFreeVolumeSpace, IoConnectionInterface_IoGetFreeVolumeSpace_Offset) = IoConnectionInterface_IoGetFreeVolumeSpace_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, IoConnectionInterface, IoShowInOS))
	{
		maxon::Tie(IoConnectionInterface_IoShowInOS, IoConnectionInterface_IoShowInOS_Offset) = IoConnectionInterface_IoShowInOS_GetPtr<W>(offset, true);
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
	PRIVATE_MAXON_SF_POINTER(IoConnectionInterface_ObservableErrorOpenFile, ObservableErrorOpenFile, MAXON_EXPAND_VA_ARGS, (maxon::ObservableRef<ObservableErrorOpenFileDelegate>));
		StaticMTable() = default;
		template <typename IMPL> static void Init(StaticMTable* tbl)
		{
		tbl->IoConnectionInterface_ObservableErrorOpenFile = IoConnectionInterface_ObservableErrorOpenFile_GetPtr<IMPL>(true);
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
			if constexpr (!S::Implementation::PROXY)
			{
				if (!(Super0::InitMTablesWithBases(info, offset))) return false;
			}
			auto* vt = (IoConnectionInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, IoConnectionInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		PRIVATE_MAXON_MF_WRAPPER(IoConnectionInterface_GetUrl, maxon::GenericComponent, const, (const Url&)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetUrl(); }
		PRIVATE_MAXON_MF_WRAPPER(IoConnectionInterface_GetBrowseIterator, maxon::GenericComponent,, (Result<IoBrowseRef>), GETBROWSEITERATORFLAGS flags) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->GetBrowseIterator(flags); }
		PRIVATE_MAXON_MF_WRAPPER(IoConnectionInterface_OpenInputStream, maxon::GenericComponent,, (Result<InputStreamRef>), OPENSTREAMFLAGS flags) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->OpenInputStream(flags); }
		PRIVATE_MAXON_MF_WRAPPER(IoConnectionInterface_OpenOutputStream, maxon::GenericComponent,, (Result<OutputStreamRef>), OPENSTREAMFLAGS flags) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->OpenOutputStream(flags); }
		PRIVATE_MAXON_MF_WRAPPER(IoConnectionInterface_OpenInOutputStream, maxon::GenericComponent,, (Result<InOutputStreamRef>), OPENSTREAMFLAGS flags) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->OpenInOutputStream(flags); }
		PRIVATE_MAXON_MF_WRAPPER(IoConnectionInterface_GetContentLength, maxon::GenericComponent,, (Result<Int64>)) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->GetContentLength(); }
		PRIVATE_MAXON_MF_WRAPPER(IoConnectionInterface_IoDetect, maxon::GenericComponent, const, (IODETECT)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->IoDetect(); }
		PRIVATE_MAXON_MF_WRAPPER(IoConnectionInterface_IoGetAttributes, maxon::GenericComponent, const, (Result<IOATTRIBUTES>)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->IoGetAttributes(); }
		PRIVATE_MAXON_MF_WRAPPER(IoConnectionInterface_IoSetAttributes, maxon::GenericComponent,, (Result<void>), IOATTRIBUTES flags, IOATTRIBUTES mask) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->IoSetAttributes(flags, mask); }
		PRIVATE_MAXON_MF_WRAPPER(IoConnectionInterface_IoGetTime, maxon::GenericComponent, const, (Result<UniversalDateTime>), IOTIMEMODE mode) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->IoGetTime(mode); }
		PRIVATE_MAXON_MF_WRAPPER(IoConnectionInterface_IoSetTime, maxon::GenericComponent,, (Result<void>), IOTIMEMODE mode, const UniversalDateTime& dateTime) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->IoSetTime(mode, dateTime); }
		PRIVATE_MAXON_MF_WRAPPER(IoConnectionInterface_IoDelete, maxon::GenericComponent,, (Result<void>), Bool force) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->IoDelete(force); }
		PRIVATE_MAXON_MF_WRAPPER(IoConnectionInterface_IoCreateDirectory, maxon::GenericComponent,, (Result<void>), Bool createParents, BaseArray<Url>* createdDirs) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->IoCreateDirectory(createParents, createdDirs); }
		PRIVATE_MAXON_MF_WRAPPER(IoConnectionInterface_IoCopyFile, maxon::GenericComponent,, (Result<void>), const Url& destName, Bool overwrite, Bool removeReadOnly) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->IoCopyFile(destName, overwrite, removeReadOnly); }
		PRIVATE_MAXON_MF_WRAPPER(IoConnectionInterface_IoCopyFileProgress, maxon::GenericComponent,, (Result<void>), const Url& destName, Bool overwrite, Bool removeReadOnly, const IoProgressDelegate& progress) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->IoCopyFileProgress(destName, overwrite, removeReadOnly, progress); }
		PRIVATE_MAXON_MF_WRAPPER(IoConnectionInterface_IoMove, maxon::GenericComponent,, (Result<void>), const Url& destName) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->IoMove(destName); }
		PRIVATE_MAXON_MF_WRAPPER(IoConnectionInterface_IoRename, maxon::GenericComponent,, (Result<void>), const Url& newName) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->IoRename(newName); }
		PRIVATE_MAXON_MF_WRAPPER(IoConnectionInterface_IoGetFreeVolumeSpace, maxon::GenericComponent, const, (Result<void>), Int64& availableBytes, Int64& totalBytes) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->IoGetFreeVolumeSpace(availableBytes, totalBytes); }
		PRIVATE_MAXON_MF_WRAPPER(IoConnectionInterface_IoShowInOS, maxon::GenericComponent, const, (Result<void>), IOSHOWINOSFLAGS flags) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->IoShowInOS(flags); }
		static maxon::ObservableRef<ObservableErrorOpenFileDelegate> IoConnectionInterface_ObservableErrorOpenFile() { return S::Implementation::ObservableErrorOpenFile(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto IoConnectionInterface::GetUrl() const -> const Url&
{
	const IoConnectionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(IoConnectionInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.IoConnectionInterface_GetUrl_Offset), mt_.IoConnectionInterface_GetUrl);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto IoConnectionInterface::GetBrowseIterator(GETBROWSEITERATORFLAGS flags) -> Result<IoBrowseRef>
{
	const IoConnectionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(IoConnectionInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.IoConnectionInterface_GetBrowseIterator_Offset), mt_.IoConnectionInterface_GetBrowseIterator, flags);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto IoConnectionInterface::OpenInputStream(OPENSTREAMFLAGS flags) -> Result<InputStreamRef>
{
	const IoConnectionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(IoConnectionInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.IoConnectionInterface_OpenInputStream_Offset), mt_.IoConnectionInterface_OpenInputStream, flags);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto IoConnectionInterface::OpenOutputStream(OPENSTREAMFLAGS flags) -> Result<OutputStreamRef>
{
	const IoConnectionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(IoConnectionInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.IoConnectionInterface_OpenOutputStream_Offset), mt_.IoConnectionInterface_OpenOutputStream, flags);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto IoConnectionInterface::OpenInOutputStream(OPENSTREAMFLAGS flags) -> Result<InOutputStreamRef>
{
	const IoConnectionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(IoConnectionInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.IoConnectionInterface_OpenInOutputStream_Offset), mt_.IoConnectionInterface_OpenInOutputStream, flags);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto IoConnectionInterface::GetContentLength() -> Result<Int64>
{
	const IoConnectionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(IoConnectionInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.IoConnectionInterface_GetContentLength_Offset), mt_.IoConnectionInterface_GetContentLength);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto IoConnectionInterface::IoDetect() const -> IODETECT
{
	const IoConnectionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(IoConnectionInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.IoConnectionInterface_IoDetect_Offset), mt_.IoConnectionInterface_IoDetect);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto IoConnectionInterface::IoGetAttributes() const -> Result<IOATTRIBUTES>
{
	const IoConnectionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(IoConnectionInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.IoConnectionInterface_IoGetAttributes_Offset), mt_.IoConnectionInterface_IoGetAttributes);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto IoConnectionInterface::IoSetAttributes(IOATTRIBUTES flags, IOATTRIBUTES mask) -> Result<void>
{
	const IoConnectionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(IoConnectionInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.IoConnectionInterface_IoSetAttributes_Offset), mt_.IoConnectionInterface_IoSetAttributes, flags, mask);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto IoConnectionInterface::IoGetTime(IOTIMEMODE mode) const -> Result<UniversalDateTime>
{
	const IoConnectionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(IoConnectionInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.IoConnectionInterface_IoGetTime_Offset), mt_.IoConnectionInterface_IoGetTime, mode);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto IoConnectionInterface::IoSetTime(IOTIMEMODE mode, const UniversalDateTime& dateTime) -> Result<void>
{
	const IoConnectionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(IoConnectionInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.IoConnectionInterface_IoSetTime_Offset), mt_.IoConnectionInterface_IoSetTime, mode, dateTime);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto IoConnectionInterface::IoDelete(Bool force) -> Result<void>
{
	const IoConnectionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(IoConnectionInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.IoConnectionInterface_IoDelete_Offset), mt_.IoConnectionInterface_IoDelete, force);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto IoConnectionInterface::IoCreateDirectory(Bool createParents, BaseArray<Url>* createdDirs) -> Result<void>
{
	const IoConnectionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(IoConnectionInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.IoConnectionInterface_IoCreateDirectory_Offset), mt_.IoConnectionInterface_IoCreateDirectory, createParents, createdDirs);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto IoConnectionInterface::IoCopyFile(const Url& destName, Bool overwrite, Bool removeReadOnly) -> Result<void>
{
	const IoConnectionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(IoConnectionInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.IoConnectionInterface_IoCopyFile_Offset), mt_.IoConnectionInterface_IoCopyFile, destName, overwrite, removeReadOnly);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto IoConnectionInterface::IoCopyFileProgress(const Url& destName, Bool overwrite, Bool removeReadOnly, const IoProgressDelegate& progress) -> Result<void>
{
	const IoConnectionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(IoConnectionInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.IoConnectionInterface_IoCopyFileProgress_Offset), mt_.IoConnectionInterface_IoCopyFileProgress, destName, overwrite, removeReadOnly, progress);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto IoConnectionInterface::IoMove(const Url& destName) -> Result<void>
{
	const IoConnectionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(IoConnectionInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.IoConnectionInterface_IoMove_Offset), mt_.IoConnectionInterface_IoMove, destName);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto IoConnectionInterface::IoRename(const Url& newName) -> Result<void>
{
	const IoConnectionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(IoConnectionInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.IoConnectionInterface_IoRename_Offset), mt_.IoConnectionInterface_IoRename, newName);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto IoConnectionInterface::IoGetFreeVolumeSpace(Int64& availableBytes, Int64& totalBytes) const -> Result<void>
{
	const IoConnectionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(IoConnectionInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.IoConnectionInterface_IoGetFreeVolumeSpace_Offset), mt_.IoConnectionInterface_IoGetFreeVolumeSpace, availableBytes, totalBytes);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto IoConnectionInterface::IoShowInOS(IOSHOWINOSFLAGS flags) const -> Result<void>
{
	const IoConnectionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(IoConnectionInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.IoConnectionInterface_IoShowInOS_Offset), mt_.IoConnectionInterface_IoShowInOS, flags);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto IoConnectionInterface::ObservableErrorOpenFile() -> maxon::ObservableRef<ObservableErrorOpenFileDelegate>
{
	return Hxx2::StaticMTable::_instance.IoConnectionInterface_ObservableErrorOpenFile();
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoConnectionInterface::Hxx1::ConstFn<S>::GetUrl() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const Url&>, const Url&>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const Url&>, const Url&>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const IoConnectionInterface* o_ = (const IoConnectionInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = IoConnectionInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<const Url&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(IoConnectionInterface, o_, IoConnectionInterface_GetUrl) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<IoConnectionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<IoConnectionInterface>() : PRIVATE_MAXON_VTABLE(IoConnectionInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.IoConnectionInterface_GetUrl_Offset), mt_.IoConnectionInterface_GetUrl));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoConnectionInterface::Hxx1::Fn<S>::GetBrowseIterator(GETBROWSEITERATORFLAGS flags) const -> Result<IoBrowseRef>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<IoBrowseRef>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); IoConnectionInterface* o_ = (IoConnectionInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(IoConnectionInterface, o_, IoConnectionInterface_GetBrowseIterator) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<IoConnectionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<IoConnectionInterface>() : PRIVATE_MAXON_VTABLE(IoConnectionInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.IoConnectionInterface_GetBrowseIterator_Offset), mt_.IoConnectionInterface_GetBrowseIterator, flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoConnectionInterface::Hxx1::COWFn<S>::GetBrowseIterator(GETBROWSEITERATORFLAGS flags) -> Result<IoBrowseRef>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<IoBrowseRef>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); IoConnectionInterface* o_ = (IoConnectionInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(IoConnectionInterface, o_, IoConnectionInterface_GetBrowseIterator) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<IoConnectionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<IoConnectionInterface>() : PRIVATE_MAXON_VTABLE(IoConnectionInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.IoConnectionInterface_GetBrowseIterator_Offset), mt_.IoConnectionInterface_GetBrowseIterator, flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoConnectionInterface::Hxx1::Fn<S>::OpenInputStream(OPENSTREAMFLAGS flags) const -> Result<InputStreamRef>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<InputStreamRef>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); IoConnectionInterface* o_ = (IoConnectionInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(IoConnectionInterface, o_, IoConnectionInterface_OpenInputStream) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<IoConnectionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<IoConnectionInterface>() : PRIVATE_MAXON_VTABLE(IoConnectionInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.IoConnectionInterface_OpenInputStream_Offset), mt_.IoConnectionInterface_OpenInputStream, flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoConnectionInterface::Hxx1::COWFn<S>::OpenInputStream(OPENSTREAMFLAGS flags) -> Result<InputStreamRef>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<InputStreamRef>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); IoConnectionInterface* o_ = (IoConnectionInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(IoConnectionInterface, o_, IoConnectionInterface_OpenInputStream) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<IoConnectionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<IoConnectionInterface>() : PRIVATE_MAXON_VTABLE(IoConnectionInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.IoConnectionInterface_OpenInputStream_Offset), mt_.IoConnectionInterface_OpenInputStream, flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoConnectionInterface::Hxx1::Fn<S>::OpenOutputStream(OPENSTREAMFLAGS flags) const -> Result<OutputStreamRef>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<OutputStreamRef>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); IoConnectionInterface* o_ = (IoConnectionInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(IoConnectionInterface, o_, IoConnectionInterface_OpenOutputStream) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<IoConnectionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<IoConnectionInterface>() : PRIVATE_MAXON_VTABLE(IoConnectionInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.IoConnectionInterface_OpenOutputStream_Offset), mt_.IoConnectionInterface_OpenOutputStream, flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoConnectionInterface::Hxx1::COWFn<S>::OpenOutputStream(OPENSTREAMFLAGS flags) -> Result<OutputStreamRef>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<OutputStreamRef>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); IoConnectionInterface* o_ = (IoConnectionInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(IoConnectionInterface, o_, IoConnectionInterface_OpenOutputStream) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<IoConnectionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<IoConnectionInterface>() : PRIVATE_MAXON_VTABLE(IoConnectionInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.IoConnectionInterface_OpenOutputStream_Offset), mt_.IoConnectionInterface_OpenOutputStream, flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoConnectionInterface::Hxx1::Fn<S>::OpenInOutputStream(OPENSTREAMFLAGS flags) const -> Result<InOutputStreamRef>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<InOutputStreamRef>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); IoConnectionInterface* o_ = (IoConnectionInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(IoConnectionInterface, o_, IoConnectionInterface_OpenInOutputStream) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<IoConnectionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<IoConnectionInterface>() : PRIVATE_MAXON_VTABLE(IoConnectionInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.IoConnectionInterface_OpenInOutputStream_Offset), mt_.IoConnectionInterface_OpenInOutputStream, flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoConnectionInterface::Hxx1::COWFn<S>::OpenInOutputStream(OPENSTREAMFLAGS flags) -> Result<InOutputStreamRef>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<InOutputStreamRef>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); IoConnectionInterface* o_ = (IoConnectionInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(IoConnectionInterface, o_, IoConnectionInterface_OpenInOutputStream) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<IoConnectionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<IoConnectionInterface>() : PRIVATE_MAXON_VTABLE(IoConnectionInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.IoConnectionInterface_OpenInOutputStream_Offset), mt_.IoConnectionInterface_OpenInOutputStream, flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoConnectionInterface::Hxx1::Fn<S>::GetContentLength() const -> Result<Int64>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Int64>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); IoConnectionInterface* o_ = (IoConnectionInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(IoConnectionInterface, o_, IoConnectionInterface_GetContentLength) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<IoConnectionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<IoConnectionInterface>() : PRIVATE_MAXON_VTABLE(IoConnectionInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.IoConnectionInterface_GetContentLength_Offset), mt_.IoConnectionInterface_GetContentLength));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoConnectionInterface::Hxx1::COWFn<S>::GetContentLength() -> Result<Int64>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Int64>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); IoConnectionInterface* o_ = (IoConnectionInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(IoConnectionInterface, o_, IoConnectionInterface_GetContentLength) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<IoConnectionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<IoConnectionInterface>() : PRIVATE_MAXON_VTABLE(IoConnectionInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.IoConnectionInterface_GetContentLength_Offset), mt_.IoConnectionInterface_GetContentLength));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoConnectionInterface::Hxx1::ConstFn<S>::IoDetect() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<IODETECT>, IODETECT>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<IODETECT>, IODETECT>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const IoConnectionInterface* o_ = (const IoConnectionInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = IoConnectionInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<IODETECT>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(IoConnectionInterface, o_, IoConnectionInterface_IoDetect) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<IoConnectionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<IoConnectionInterface>() : PRIVATE_MAXON_VTABLE(IoConnectionInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.IoConnectionInterface_IoDetect_Offset), mt_.IoConnectionInterface_IoDetect));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoConnectionInterface::Hxx1::ConstFn<S>::IoGetAttributes() const -> Result<IOATTRIBUTES>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<IOATTRIBUTES>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const IoConnectionInterface* o_ = (const IoConnectionInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = IoConnectionInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(IoConnectionInterface, o_, IoConnectionInterface_IoGetAttributes) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<IoConnectionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<IoConnectionInterface>() : PRIVATE_MAXON_VTABLE(IoConnectionInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.IoConnectionInterface_IoGetAttributes_Offset), mt_.IoConnectionInterface_IoGetAttributes));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoConnectionInterface::Hxx1::Fn<S>::IoSetAttributes(IOATTRIBUTES flags, IOATTRIBUTES mask) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); IoConnectionInterface* o_ = (IoConnectionInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(IoConnectionInterface, o_, IoConnectionInterface_IoSetAttributes) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<IoConnectionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<IoConnectionInterface>() : PRIVATE_MAXON_VTABLE(IoConnectionInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.IoConnectionInterface_IoSetAttributes_Offset), mt_.IoConnectionInterface_IoSetAttributes, flags, mask));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoConnectionInterface::Hxx1::COWFn<S>::IoSetAttributes(IOATTRIBUTES flags, IOATTRIBUTES mask) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); IoConnectionInterface* o_ = (IoConnectionInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(IoConnectionInterface, o_, IoConnectionInterface_IoSetAttributes) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<IoConnectionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<IoConnectionInterface>() : PRIVATE_MAXON_VTABLE(IoConnectionInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.IoConnectionInterface_IoSetAttributes_Offset), mt_.IoConnectionInterface_IoSetAttributes, flags, mask));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoConnectionInterface::Hxx1::ConstFn<S>::IoGetTime(IOTIMEMODE mode) const -> Result<UniversalDateTime>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<UniversalDateTime>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const IoConnectionInterface* o_ = (const IoConnectionInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = IoConnectionInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(IoConnectionInterface, o_, IoConnectionInterface_IoGetTime) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<IoConnectionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<IoConnectionInterface>() : PRIVATE_MAXON_VTABLE(IoConnectionInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.IoConnectionInterface_IoGetTime_Offset), mt_.IoConnectionInterface_IoGetTime, mode));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoConnectionInterface::Hxx1::Fn<S>::IoSetTime(IOTIMEMODE mode, const UniversalDateTime& dateTime) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); IoConnectionInterface* o_ = (IoConnectionInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(IoConnectionInterface, o_, IoConnectionInterface_IoSetTime) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<IoConnectionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<IoConnectionInterface>() : PRIVATE_MAXON_VTABLE(IoConnectionInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.IoConnectionInterface_IoSetTime_Offset), mt_.IoConnectionInterface_IoSetTime, mode, dateTime));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoConnectionInterface::Hxx1::COWFn<S>::IoSetTime(IOTIMEMODE mode, const UniversalDateTime& dateTime) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); IoConnectionInterface* o_ = (IoConnectionInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(IoConnectionInterface, o_, IoConnectionInterface_IoSetTime) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<IoConnectionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<IoConnectionInterface>() : PRIVATE_MAXON_VTABLE(IoConnectionInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.IoConnectionInterface_IoSetTime_Offset), mt_.IoConnectionInterface_IoSetTime, mode, dateTime));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoConnectionInterface::Hxx1::Fn<S>::IoDelete(Bool force) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); IoConnectionInterface* o_ = (IoConnectionInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(IoConnectionInterface, o_, IoConnectionInterface_IoDelete) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<IoConnectionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<IoConnectionInterface>() : PRIVATE_MAXON_VTABLE(IoConnectionInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.IoConnectionInterface_IoDelete_Offset), mt_.IoConnectionInterface_IoDelete, force));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoConnectionInterface::Hxx1::COWFn<S>::IoDelete(Bool force) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); IoConnectionInterface* o_ = (IoConnectionInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(IoConnectionInterface, o_, IoConnectionInterface_IoDelete) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<IoConnectionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<IoConnectionInterface>() : PRIVATE_MAXON_VTABLE(IoConnectionInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.IoConnectionInterface_IoDelete_Offset), mt_.IoConnectionInterface_IoDelete, force));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoConnectionInterface::Hxx1::Fn<S>::IoCreateDirectory(Bool createParents, BaseArray<Url>* createdDirs) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); IoConnectionInterface* o_ = (IoConnectionInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(IoConnectionInterface, o_, IoConnectionInterface_IoCreateDirectory) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<IoConnectionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<IoConnectionInterface>() : PRIVATE_MAXON_VTABLE(IoConnectionInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.IoConnectionInterface_IoCreateDirectory_Offset), mt_.IoConnectionInterface_IoCreateDirectory, createParents, createdDirs));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoConnectionInterface::Hxx1::COWFn<S>::IoCreateDirectory(Bool createParents, BaseArray<Url>* createdDirs) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); IoConnectionInterface* o_ = (IoConnectionInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(IoConnectionInterface, o_, IoConnectionInterface_IoCreateDirectory) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<IoConnectionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<IoConnectionInterface>() : PRIVATE_MAXON_VTABLE(IoConnectionInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.IoConnectionInterface_IoCreateDirectory_Offset), mt_.IoConnectionInterface_IoCreateDirectory, createParents, createdDirs));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoConnectionInterface::Hxx1::Fn<S>::IoCopyFile(const Url& destName, Bool overwrite, Bool removeReadOnly) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); IoConnectionInterface* o_ = (IoConnectionInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(IoConnectionInterface, o_, IoConnectionInterface_IoCopyFile) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<IoConnectionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<IoConnectionInterface>() : PRIVATE_MAXON_VTABLE(IoConnectionInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.IoConnectionInterface_IoCopyFile_Offset), mt_.IoConnectionInterface_IoCopyFile, destName, overwrite, removeReadOnly));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoConnectionInterface::Hxx1::COWFn<S>::IoCopyFile(const Url& destName, Bool overwrite, Bool removeReadOnly) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); IoConnectionInterface* o_ = (IoConnectionInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(IoConnectionInterface, o_, IoConnectionInterface_IoCopyFile) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<IoConnectionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<IoConnectionInterface>() : PRIVATE_MAXON_VTABLE(IoConnectionInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.IoConnectionInterface_IoCopyFile_Offset), mt_.IoConnectionInterface_IoCopyFile, destName, overwrite, removeReadOnly));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoConnectionInterface::Hxx1::Fn<S>::IoCopyFileProgress(const Url& destName, Bool overwrite, Bool removeReadOnly, const IoProgressDelegate& progress) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); IoConnectionInterface* o_ = (IoConnectionInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(IoConnectionInterface, o_, IoConnectionInterface_IoCopyFileProgress) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<IoConnectionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<IoConnectionInterface>() : PRIVATE_MAXON_VTABLE(IoConnectionInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.IoConnectionInterface_IoCopyFileProgress_Offset), mt_.IoConnectionInterface_IoCopyFileProgress, destName, overwrite, removeReadOnly, progress));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoConnectionInterface::Hxx1::COWFn<S>::IoCopyFileProgress(const Url& destName, Bool overwrite, Bool removeReadOnly, const IoProgressDelegate& progress) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); IoConnectionInterface* o_ = (IoConnectionInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(IoConnectionInterface, o_, IoConnectionInterface_IoCopyFileProgress) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<IoConnectionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<IoConnectionInterface>() : PRIVATE_MAXON_VTABLE(IoConnectionInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.IoConnectionInterface_IoCopyFileProgress_Offset), mt_.IoConnectionInterface_IoCopyFileProgress, destName, overwrite, removeReadOnly, progress));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoConnectionInterface::Hxx1::Fn<S>::IoMove(const Url& destName) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); IoConnectionInterface* o_ = (IoConnectionInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(IoConnectionInterface, o_, IoConnectionInterface_IoMove) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<IoConnectionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<IoConnectionInterface>() : PRIVATE_MAXON_VTABLE(IoConnectionInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.IoConnectionInterface_IoMove_Offset), mt_.IoConnectionInterface_IoMove, destName));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoConnectionInterface::Hxx1::COWFn<S>::IoMove(const Url& destName) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); IoConnectionInterface* o_ = (IoConnectionInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(IoConnectionInterface, o_, IoConnectionInterface_IoMove) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<IoConnectionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<IoConnectionInterface>() : PRIVATE_MAXON_VTABLE(IoConnectionInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.IoConnectionInterface_IoMove_Offset), mt_.IoConnectionInterface_IoMove, destName));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoConnectionInterface::Hxx1::Fn<S>::IoRename(const Url& newName) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); IoConnectionInterface* o_ = (IoConnectionInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(IoConnectionInterface, o_, IoConnectionInterface_IoRename) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<IoConnectionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<IoConnectionInterface>() : PRIVATE_MAXON_VTABLE(IoConnectionInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.IoConnectionInterface_IoRename_Offset), mt_.IoConnectionInterface_IoRename, newName));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoConnectionInterface::Hxx1::COWFn<S>::IoRename(const Url& newName) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); IoConnectionInterface* o_ = (IoConnectionInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(IoConnectionInterface, o_, IoConnectionInterface_IoRename) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<IoConnectionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<IoConnectionInterface>() : PRIVATE_MAXON_VTABLE(IoConnectionInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.IoConnectionInterface_IoRename_Offset), mt_.IoConnectionInterface_IoRename, newName));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoConnectionInterface::Hxx1::ConstFn<S>::IoGetFreeVolumeSpace(Int64& availableBytes, Int64& totalBytes) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const IoConnectionInterface* o_ = (const IoConnectionInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = IoConnectionInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(IoConnectionInterface, o_, IoConnectionInterface_IoGetFreeVolumeSpace) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<IoConnectionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<IoConnectionInterface>() : PRIVATE_MAXON_VTABLE(IoConnectionInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.IoConnectionInterface_IoGetFreeVolumeSpace_Offset), mt_.IoConnectionInterface_IoGetFreeVolumeSpace, availableBytes, totalBytes));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoConnectionInterface::Hxx1::ConstFn<S>::IoShowInOS(IOSHOWINOSFLAGS flags) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const IoConnectionInterface* o_ = (const IoConnectionInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = IoConnectionInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(IoConnectionInterface, o_, IoConnectionInterface_IoShowInOS) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<IoConnectionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<IoConnectionInterface>() : PRIVATE_MAXON_VTABLE(IoConnectionInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.IoConnectionInterface_IoShowInOS_Offset), mt_.IoConnectionInterface_IoShowInOS, flags));
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

