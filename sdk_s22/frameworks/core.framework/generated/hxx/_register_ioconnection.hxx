#if 1
namespace maxon
{
	const maxon::Char* const ResolveInterface::MTable::_ids = 
		"Free@bbf68333b54baab2\0" // void Free(const ResolveInterface* object)
		"RemoveDotSegments@80ddfa2d31821f3a\0" // Result<Url> RemoveDotSegments(const Url& url)
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
		tbl->_ResolveInterface_Free = &Hxx2::Wrapper<Hxx2::Unresolved>::_ResolveInterface_Free;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<Url>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_ResolveInterface_RemoveDotSegments = &Hxx2::Wrapper<Hxx2::Unresolved>::_ResolveInterface_RemoveDotSegments;
		#else
		tbl->_ResolveInterface_RemoveDotSegments = &Hxx2::Wrapper<Hxx2::Unresolved>::_ResolveInterface_RemoveDotSegments;
		#endif
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_interface, (maxon::Char*) tbl, _returnTypes, SIZEOF(MTable) / SIZEOF(void*));
	#else
		return true;
	#endif
	}
	MAXON_INTERFACE_REGISTER(ResolveInterface, "net.maxon.interface.resolve", nullptr);
	const maxon::Char* const IoConnectionInterface::MTable::_ids = 
		"GetUrl@24368c97617cbacb\0" // const Url& GetUrl() const
		"GetBrowseIterator@0be802d7a7992d62\0" // Result<IoBrowseRef> GetBrowseIterator(GETBROWSEITERATORFLAGS flags)
		"OpenInputStream@62038ff66c3aab50\0" // Result<InputStreamRef> OpenInputStream(OPENSTREAMFLAGS flags)
		"OpenOutputStream@14e528d17f28f125\0" // Result<OutputStreamRef> OpenOutputStream(OPENSTREAMFLAGS flags)
		"OpenInOutputStream@5df4ab04f0e33aaa\0" // Result<InOutputStreamRef> OpenInOutputStream(OPENSTREAMFLAGS flags)
		"GetContentLength@0499ab9662aba2b3\0" // Result<Int64> GetContentLength()
		"IoDetect@71a72d7308580\0" // IODETECT IoDetect() const
		"IoGetAttributes@507ff8fe2ae3e399\0" // Result<IOATTRIBUTES> IoGetAttributes() const
		"IoSetAttributes@8d98e47fa4a357b4\0" // Result<void> IoSetAttributes(IOATTRIBUTES flags, IOATTRIBUTES mask)
		"IoGetTime@14de2ec95d150358\0" // Result<UniversalDateTime> IoGetTime(IOTIMEMODE mode) const
		"IoSetTime@782f2ff5a663121b\0" // Result<void> IoSetTime(IOTIMEMODE mode, const UniversalDateTime& dateTime)
		"IoDelete@56cb0c2802ed47a2\0" // Result<void> IoDelete(Bool force)
		"IoCreateDirectory@68442a97c946105d\0" // Result<void> IoCreateDirectory(Bool createParents, BaseArray<Url>* createdDirs)
		"IoCopyFile@a01dbffbe7e5dcac\0" // Result<void> IoCopyFile(const Url& destName, Bool overwrite, Bool removeReadOnly)
		"IoMove@e1e93c17010d01ec\0" // Result<void> IoMove(const Url& destName)
		"IoRename@e1e93c17010d01ec\0" // Result<void> IoRename(const Url& newName)
		"IoGetFreeVolumeSpace@a040bc23f560c746\0" // Result<void> IoGetFreeVolumeSpace(Int64& availableBytes, Int64& totalBytes) const
		"IoShowInOS@a57fa4657e3e77b7\0" // Result<void> IoShowInOS(IOSHOWINOSFLAGS flags) const
	"";
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(IoConnectionInterface, , "net.maxon.interface.ioconnection", "maxon.IoConnectionInterface", (&DataDictionaryObjectInterface::_interface));
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
