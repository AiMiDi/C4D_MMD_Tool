#if 1
namespace maxon
{
	const maxon::Char* const ResolveInterface::MTable::_ids = 
		"Free@596277e032c800f1\0" // void Free(const ResolveInterface* object)
		"RemoveDotSegments@f5d52a42bb053487\0" // Result<Url> RemoveDotSegments(const Url& url)
	"";
	MAXON_WARNING_PUSH
	MAXON_WARNING_DISABLE_DEPRECATED
	class ResolveInterface::Hxx2::Unresolved : public ResolveInterface
	{
	public:
		static const Unresolved* Get(const ResolveInterface* o) { return (const Unresolved*) o; }
		static Unresolved* Get(ResolveInterface* o) { return (Unresolved*) o; }
		static void Free(const ResolveInterface* object) { if (object && maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ResolveInterface::Free(object); return maxon::PrivateLogNullptrError();}
		static Result<Url> RemoveDotSegments(const Url& url) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ResolveInterface::RemoveDotSegments(url); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
	};
	MAXON_WARNING_POP
#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
	const maxon::NULL_RETURN_TYPE ResolveInterface::MTable::_returnTypes[] = 
	{
		maxon::NULL_RETURN_TYPE::VOID_ZERO_FREE_FUNCTION,
		maxon::details::NullReturnType<Result<Url>>::value,
		maxon::NULL_RETURN_TYPE::OTHER
	};
#endif
	maxon::Bool ResolveInterface::MTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl)
	{
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->ResolveInterface_Free = PRIVATE_MAXON_MF_CAST(decltype(ResolveInterface_Free), &Hxx2::Wrapper<Hxx2::Unresolved>::ResolveInterface_Free);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<Url>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->ResolveInterface_RemoveDotSegments = PRIVATE_MAXON_MF_CAST(decltype(ResolveInterface_RemoveDotSegments), &Hxx2::Wrapper<Hxx2::Unresolved>::ResolveInterface_RemoveDotSegments);
		#else
		tbl->ResolveInterface_RemoveDotSegments = PRIVATE_MAXON_MF_CAST(decltype(ResolveInterface_RemoveDotSegments), &Hxx2::Wrapper<Hxx2::Unresolved>::ResolveInterface_RemoveDotSegments);
		#endif
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_interface, (maxon::Char*) tbl, _returnTypes, SIZEOF(MTable) / SIZEOF(void*));
	#else
		return true;
	#endif
	}
	MAXON_INTERFACE_REGISTER(ResolveInterface, "net.maxon.interface.resolve", nullptr);
	MAXON_WARNING_PUSH
	MAXON_WARNING_DISABLE_DEPRECATED
	class IoConnectionInterface::Hxx2::Unresolved : public IoConnectionInterface
	{
	public:
		static maxon::ObservableRef<ObservableErrorOpenFileDelegate> ObservableErrorOpenFile() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_staticInterface, true)) return IoConnectionInterface::ObservableErrorOpenFile(); return maxon::ObservableRef<ObservableErrorOpenFileDelegate>::NullValue();}
	};
	MAXON_WARNING_POP
#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
	const maxon::NULL_RETURN_TYPE IoConnectionInterface::Hxx2::StaticMTable::_returnTypes[] = 
	{
		maxon::details::NullReturnType<maxon::ObservableRef<ObservableErrorOpenFileDelegate>>::value,
		maxon::NULL_RETURN_TYPE::OTHER
	};
#endif
	maxon::Bool IoConnectionInterface::Hxx2::StaticMTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, Hxx2::StaticMTable* tbl)
	{
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<maxon::ObservableRef<ObservableErrorOpenFileDelegate>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->IoConnectionInterface_ObservableErrorOpenFile = PRIVATE_MAXON_MF_CAST(decltype(IoConnectionInterface_ObservableErrorOpenFile), &Hxx2::CWrapper<maxon::StaticHelper<Hxx2::Unresolved>>::IoConnectionInterface_ObservableErrorOpenFile);
		#else
		tbl->IoConnectionInterface_ObservableErrorOpenFile = PRIVATE_MAXON_MF_CAST(decltype(IoConnectionInterface_ObservableErrorOpenFile), &Hxx2::CWrapper<maxon::StaticHelper<Hxx2::Unresolved>>::IoConnectionInterface_ObservableErrorOpenFile);
		#endif
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_staticInterface, (maxon::Char*) tbl, _returnTypes, SIZEOF(StaticMTable) / SIZEOF(void*));
	#else
		return true;
	#endif
	}
	const maxon::Char* const IoConnectionInterface::MTable::_ids = 
		"GetUrl@dd23129f046419ec\0" // const Url& GetUrl() const
		"GetBrowseIterator@5badf00bd865d38f\0" // Result<IoBrowseRef> GetBrowseIterator(GETBROWSEITERATORFLAGS flags)
		"OpenInputStream@2e537ec45fbe3dd\0" // Result<InputStreamRef> OpenInputStream(OPENSTREAMFLAGS flags)
		"OpenOutputStream@757efee960d697b8\0" // Result<OutputStreamRef> OpenOutputStream(OPENSTREAMFLAGS flags)
		"OpenInOutputStream@bf604a61681e719f\0" // Result<InOutputStreamRef> OpenInOutputStream(OPENSTREAMFLAGS flags)
		"GetContentLength@4c62527c80f67b74\0" // Result<Int64> GetContentLength()
		"IoDetect@168ff9f01cbbf20f\0" // IODETECT IoDetect() const
		"IoGetAttributes@48f6114bedbf9314\0" // Result<IOATTRIBUTES> IoGetAttributes() const
		"IoSetAttributes@29a30af210055a89\0" // Result<void> IoSetAttributes(IOATTRIBUTES flags, IOATTRIBUTES mask)
		"IoGetTime@3554f01be48bac5\0" // Result<UniversalDateTime> IoGetTime(IOTIMEMODE mode) const
		"IoSetTime@fa7d757aa0b845a2\0" // Result<void> IoSetTime(IOTIMEMODE mode, const UniversalDateTime& dateTime)
		"IoDelete@a64a76259e12ef8d\0" // Result<void> IoDelete(Bool force)
		"IoCreateDirectory@c6d7500b8f0abdca\0" // Result<void> IoCreateDirectory(Bool createParents, BaseArray<Url>* createdDirs)
		"IoCopyFile@dd6e21f619f630dd\0" // Result<void> IoCopyFile(const Url& destName, Bool overwrite, Bool removeReadOnly)
		"IoCopyFileProgress@181382741443507c\0" // Result<void> IoCopyFileProgress(const Url& destName, Bool overwrite, Bool removeReadOnly, const IoProgressDelegate& progress)
		"IoMove@1db4eca46d9225b9\0" // Result<void> IoMove(const Url& destName)
		"IoRename@1db4eca46d9225b9\0" // Result<void> IoRename(const Url& newName)
		"IoGetFreeVolumeSpace@58294fc4f8caee31\0" // Result<void> IoGetFreeVolumeSpace(Int64& availableBytes, Int64& totalBytes) const
		"IoShowInOS@d8dc6b0a70bf9176\0" // Result<void> IoShowInOS(IOSHOWINOSFLAGS flags) const
	"";
	const maxon::METHOD_FLAGS IoConnectionInterface::MTable::_flags[] = 
	{
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE
	};
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(IoConnectionInterface, , "net.maxon.interface.ioconnection", "maxon.IoConnectionInterface", (DataDictionaryObjectInterface::PrivateGetInterface()));
	const maxon::Char* const IoConnectionInterface::Hxx2::StaticMTable::_ids = 
		"ObservableErrorOpenFile@2c5c8c70549d4a62\0" // maxon::ObservableRef<ObservableErrorOpenFileDelegate> ObservableErrorOpenFile()
	"";
	PRIVATE_MAXON_INTERFACE_REGISTER_STATIC(IoConnectionInterface, , "net.maxon.interface.ioconnection");
	template <typename DUMMY> maxon::Int IoConnectionInterface::PrivateInstantiateNullValueHelper()
	{
		return 0
		| maxon::details::InstantiateNullReturnValue<IODETECT>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateNullReturnValue<const Url&>(OVERLOAD_MAX_RANK)
		;
	}
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(IoConnectionBaseClass, , "net.maxon.class.ioconnectionbase");
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(IoConnectionFileClass, , "net.maxon.class.ioconnectionfile");
}
#endif
static maxon::details::ForceEvaluation s_forceEval_ioconnection(0
	| maxon::IoConnectionInterface::PrivateInstantiateNullValueHelper<maxon::Int>()
);
