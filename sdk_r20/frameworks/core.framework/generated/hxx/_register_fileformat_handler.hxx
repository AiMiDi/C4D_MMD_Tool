#if 1
namespace maxon
{
	namespace enum26 { enum class FILEFORMAT_PRIORITY
	{
		SHIFT_ONE = 1,					///< Add/Sub this value to in/decrease the priority by 1.
		SHIFT_TEN = 10,					///< Add/sub this value to in/decrease the priority by 10.
	
		FALLBACKFORMAT = 10000, ///< Specifies the lowest priority of a file format.
		GENERALFORMAT = 20000,	///< Specifies the medium priority of a file format. This should be used for general loaders which handle many formats through other APIS (e.g. ffmpeg)
		NATIVEFORMAT = 30000,		///< Specifies the highest priority of a file format. This should be used for native implementations (e.g. image formats like jpg, tif done by us).
	
	} ; }
	maxon::String PrivateToString_FILEFORMAT_PRIORITY26(std::underlying_type<enum26::FILEFORMAT_PRIORITY>::type x, const maxon::FormatStatement* fmt)
	{
		const maxon::UInt64 values[] = {(maxon::UInt64) enum26::FILEFORMAT_PRIORITY::SHIFT_ONE, (maxon::UInt64) enum26::FILEFORMAT_PRIORITY::SHIFT_TEN, (maxon::UInt64) enum26::FILEFORMAT_PRIORITY::FALLBACKFORMAT, (maxon::UInt64) enum26::FILEFORMAT_PRIORITY::GENERALFORMAT, (maxon::UInt64) enum26::FILEFORMAT_PRIORITY::NATIVEFORMAT};
		return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "FILEFORMAT_PRIORITY", SIZEOF(x), false, values, "SHIFT_ONE\0SHIFT_TEN\0FALLBACKFORMAT\0GENERALFORMAT\0NATIVEFORMAT\0", fmt);
	}
	MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(FileFormatHandlerInterface, "net.maxon.interface.fileformathandler", "maxon.FileFormatHandlerInterface", , &Object::_interface);
	const maxon::Char* const FileFormatHandlerInterface::MTable::_ids = 
		"GetFileFormat@06c33bde295f8b8d\0" // GetFileFormat() const
		"GetHandlerType@d264d729aefb806b\0" // GetHandlerType() const
		"CreateHandler@11eb1c35ba4964cc\0" // CreateHandler(const Url& url) const
		"GetDependends@7849c50e98fbe867\0" // GetDependends() const
	"";
	template <typename DUMMY> maxon::Int FileFormatHandlerInterface::PrivateInstantiateNullValueHelper()
	{
		return 0
		| maxon::details::InstantiateNullReturnValue<FILEFORMAT_PRIORITY>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateNullReturnValue<const FileFormat&>(OVERLOAD_MAX_RANK)
		;
	}
#ifndef MAXON_COMPILER_CLANG
#endif
	const maxon::Char* const FileFormatDetectionInterface::MTable::_ids = 
#ifndef MAXON_COMPILER_CLANG
#endif
		"DetectAll@d3ec6fcaa13e8221\0" // DetectAll(const Url& url, const Block<const DataType*>& limitDetection, const DetectedCallback& detectedCallback)
	"";
	class FileFormatDetectionInterface::Unresolved : public FileFormatDetectionInterface
	{
	public:
		static const Unresolved* Get(const FileFormatDetectionInterface* o) { return (const Unresolved*) o; }
		static Unresolved* Get(FileFormatDetectionInterface* o) { return (Unresolved*) o; }
#ifndef MAXON_COMPILER_CLANG
#endif
		static Result<BaseArray<FileFormatHandler>> DetectAll(const Url& url, const Block<const DataType*>& limitDetection, const DetectedCallback& detectedCallback) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return FileFormatDetectionInterface::DetectAll(url, limitDetection, detectedCallback); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
	};
#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
	const maxon::NULL_RETURN_TYPE FileFormatDetectionInterface::MTable::_returnTypes[] = 
	{
#ifndef MAXON_COMPILER_CLANG
#endif
		maxon::details::NullReturnType<Result<BaseArray<FileFormatHandler>>>::value,
		maxon::NULL_RETURN_TYPE::OTHER
	};
#endif
	maxon::Bool FileFormatDetectionInterface::MTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl)
	{
#ifndef MAXON_COMPILER_CLANG
#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<BaseArray<FileFormatHandler>>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_FileFormatDetectionInterface_DetectAll = &Wrapper<Unresolved>::_FileFormatDetectionInterface_DetectAll;
	#else
		tbl->_FileFormatDetectionInterface_DetectAll = &Wrapper<Unresolved>::_FileFormatDetectionInterface_DetectAll;
	#endif
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_interface, (maxon::Char*) tbl, _returnTypes, SIZEOF(_returnTypes) - 1);
	#else
		return true;
	#endif
	}
	MAXON_INTERFACE_REGISTER(FileFormatDetectionInterface, "net.maxon.interface.fileformatdetection", nullptr);
	template <typename DUMMY> maxon::Int FileFormatDetectionInterface::PrivateInstantiateNullValueHelper()
	{
		return 0
		;
	}
	MAXON_REGISTRY_REGISTER(FileFormatHandlers);
	namespace FileFormatHandlers
	{
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(GenericFile, , "net.maxon.fileformathandler.genericfile");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(Browsable, , "net.maxon.fileformathandler.browsable");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(MaxonDocumentBinaryHandler, , "net.maxon.fileformathandler.maxondocumentbinaryhandler");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(MaxonDocumentJsonHandler, , "net.maxon.fileformathandler.maxondocumentjsonhandler");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(MaxonDocumentXmlHandler, , "net.maxon.fileformathandler.maxondocumentxmlhandler");
	}
}
#endif
static maxon::details::ForceEvaluation s_forceEval_fileformat_handler(0
	| maxon::FileFormatHandlerInterface::PrivateInstantiateNullValueHelper<maxon::Int>()
	| maxon::FileFormatDetectionInterface::PrivateInstantiateNullValueHelper<maxon::Int>()
);
