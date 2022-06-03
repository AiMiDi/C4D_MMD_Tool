#if 1
namespace maxon
{
	namespace enum26
	{
		enum class FILEFORMAT_PRIORITY
		{
			SHIFT_ONE = 1,					///< Add/Sub this value to in/decrease the priority by 1.
			SHIFT_TEN = 10,					///< Add/sub this value to in/decrease the priority by 10.
		
			FALLBACKFORMAT = 10000, ///< Specifies the lowest priority of a file format.
			GENERALFORMAT = 20000,	///< Specifies the medium priority of a file format. This should be used for general loaders which handle many formats through other APIS (e.g. ffmpeg)
			NATIVEFORMAT = 30000,		///< Specifies the highest priority of a file format. This should be used for native implementations (e.g. image formats like jpg, tif done by us).
		
		} ;
		static const maxon::UInt64 FILEFORMAT_PRIORITY_values[] = {maxon::UInt64(enum26::FILEFORMAT_PRIORITY::SHIFT_ONE), maxon::UInt64(enum26::FILEFORMAT_PRIORITY::SHIFT_TEN), maxon::UInt64(enum26::FILEFORMAT_PRIORITY::FALLBACKFORMAT), maxon::UInt64(enum26::FILEFORMAT_PRIORITY::GENERALFORMAT), maxon::UInt64(enum26::FILEFORMAT_PRIORITY::NATIVEFORMAT)};
		static const maxon::EnumInfo FILEFORMAT_PRIORITY_info{"FILEFORMAT_PRIORITY", SIZEOF(FILEFORMAT_PRIORITY), false, "SHIFT_ONE\0SHIFT_TEN\0FALLBACKFORMAT\0GENERALFORMAT\0NATIVEFORMAT\0", FILEFORMAT_PRIORITY_values, std::extent<decltype(FILEFORMAT_PRIORITY_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_FILEFORMAT_PRIORITY26(){ return enum26::FILEFORMAT_PRIORITY_info; }
	const maxon::Char* const FileFormatHandlerInterface::MTable::_ids = 
		"GetFileFormat@fbd152031b99bea0\0" // const FileFormat& GetFileFormat() const
		"GetHandlerType@9d0c586c24b2457b\0" // Result<DataType> GetHandlerType() const
		"CreateHandler@4a39243cf1a82ba7\0" // Result<ObjectRef> CreateHandler(const Url& url) const
		"GetDependends@366b37dd74f3f8f0\0" // FILEFORMAT_PRIORITY GetDependends() const
	"";
	const maxon::METHOD_FLAGS FileFormatHandlerInterface::MTable::_flags[] = 
	{
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE
	};
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(FileFormatHandlerInterface, , "net.maxon.interface.fileformathandler", "maxon.FileFormatHandlerInterface", (ObjectInterface::PrivateGetInterface()));
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
		"DetectAll@1401acb3fb42c408\0" // Result<BaseArray<FileFormatHandler>> DetectAll(const Url& url, const Block<const DataType>& limitDetection, const DetectedCallback& detectedCallback)
	"";
	MAXON_WARNING_PUSH
	MAXON_WARNING_DISABLE_DEPRECATED
	class FileFormatDetectionInterface::Hxx2::Unresolved : public FileFormatDetectionInterface
	{
	public:
		static const Unresolved* Get(const FileFormatDetectionInterface* o) { return (const Unresolved*) o; }
		static Unresolved* Get(FileFormatDetectionInterface* o) { return (Unresolved*) o; }
#ifndef MAXON_COMPILER_CLANG
#endif
		static Result<BaseArray<FileFormatHandler>> DetectAll(const Url& url, const Block<const DataType>& limitDetection, const DetectedCallback& detectedCallback) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return FileFormatDetectionInterface::DetectAll(url, limitDetection, detectedCallback); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
	};
	MAXON_WARNING_POP
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
		if (maxon::details::NullReturnType<Result<BaseArray<FileFormatHandler>>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->FileFormatDetectionInterface_DetectAll = &Hxx2::Wrapper<Hxx2::Unresolved>::FileFormatDetectionInterface_DetectAll;
		#else
		tbl->FileFormatDetectionInterface_DetectAll = &Hxx2::Wrapper<Hxx2::Unresolved>::FileFormatDetectionInterface_DetectAll;
		#endif
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_interface, (maxon::Char*) tbl, _returnTypes, SIZEOF(MTable) / SIZEOF(void*));
	#else
		return true;
	#endif
	}
	MAXON_INTERFACE_REGISTER(FileFormatDetectionInterface, "net.maxon.interface.fileformatdetection", nullptr);
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
);
