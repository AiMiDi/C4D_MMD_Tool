#if 1
namespace maxon
{
	const maxon::Char* const MediaStreamInterface::MTable::_ids = 
		"GetFormats@5b59c990d540e1b\0" // Result<BaseArray<Data>> GetFormats() const
		"GetFormat@4ace19091f0e66a4\0" // MediaStreamFormat GetFormat(const Data& formatId) const
		"GetSelectedFormat@8a21123e0bcb147f\0" // const Data& GetSelectedFormat() const
		"SetSelectedFormat@6517ddb76f613bd6\0" // Result<void> SetSelectedFormat(const Data& formatId)
		"AddFormat@7f2e38aa6dc42d10\0" // Result<void> AddFormat(const Data& formatId, const MediaStreamFormat& ref)
		"SubscribeStream@6517ddb76f613bd6\0" // Result<void> SubscribeStream(const Data& formatId)
		"UnsubscribeStream@3008090429c5a175\0" // Result<void> UnsubscribeStream()
		"IsSubscribed@12e73654e6d65520\0" // Bool IsSubscribed() const
	"";
	const maxon::METHOD_FLAGS MediaStreamInterface::MTable::_flags[] = 
	{
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
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL(MediaStreamInterface, MediaStreamInterface, , , "net.maxon.image.interface.mediastream", "maxon.MediaStreamInterface", (MediaBaseInterface::PrivateGetInterface()), (HierarchyObjectInterface::PrivateGetInterface()), nullptr);
	template <typename DUMMY> maxon::Int MediaStreamInterface::PrivateInstantiateNullValueHelper()
	{
		return 0
		| maxon::details::InstantiateNullReturnValue<MediaStreamFormat>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateNullReturnValue<const Data&>(OVERLOAD_MAX_RANK)
		;
	}
	const maxon::Char* const MediaStreamExifDataInterface::MTable::_ids = 
		"SetCallbackHandler@6f0544fca754e764\0" // Result<void> SetCallbackHandler(const ExifDataHandler& handleExifData)
		"HandleExifData@137aa59d6ba02747\0" // Result<void> HandleExifData(const ExifRef& exifData)
		"FinishStream@d0b0f978b6e63019\0" // Result<void> FinishStream(const MediaStreamProperties& props)
	"";
	const maxon::METHOD_FLAGS MediaStreamExifDataInterface::MTable::_flags[] = 
	{
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE
	};
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(MediaStreamExifDataInterface, , "net.maxon.image.interface.mediastreamexifdata", "maxon.MediaStreamExifDataInterface", (MediaStreamInterface::PrivateGetInterface()));
	const maxon::Char* const MediaStreamImageBaseInterface::MTable::_ids = 
	"";
	const maxon::METHOD_FLAGS MediaStreamImageBaseInterface::MTable::_flags[] = 
	{
		maxon::METHOD_FLAGS::NONE
	};
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(MediaStreamImageBaseInterface, , "net.maxon.image.interface.mediastreamimagebase", "maxon.MediaStreamImageBaseInterface", (MediaStreamInterface::PrivateGetInterface()));
	const maxon::Char* const MediaStreamImageDataImportInterface::MTable::_ids = 
		"SetCallbackHandler@824af7f7002d1411\0" // Result<void> SetCallbackHandler(const InitHandler& initHandler, const SetPixelHandler& setPixelHandler, const FinishHandler& finishHandler)
		"InitStream@d0b0f978b6e63019\0" // Result<void> InitStream(const MediaStreamProperties& props)
		"SetPixelStream@1cf1c86d78da78af\0" // Result<SetPixelHandlerStruct> SetPixelStream(const MediaStreamProperties& props, const ChannelOffsets& srcChannelOffsets, SETPIXELHANDLERFLAGS setPixelFlags)
		"FinishStream@d0b0f978b6e63019\0" // Result<void> FinishStream(const MediaStreamProperties& props)
	"";
	const maxon::METHOD_FLAGS MediaStreamImageDataImportInterface::MTable::_flags[] = 
	{
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE
	};
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(MediaStreamImageDataImportInterface, , "net.maxon.image.interface.mediastreamimagedataimport", "maxon.MediaStreamImageDataImportInterface", (MediaStreamImageBaseInterface::PrivateGetInterface()));
	const maxon::Char* const MediaStreamImageDataExportInterface::MTable::_ids = 
		"SetCallbackHandler@f54c3e36530f8e05\0" // Result<void> SetCallbackHandler(const InitHandler& initHandler, const GetPixelHandler& getPixelHandler, const FinishHandler& finishHandler)
		"InitStream@7cfad6976c5d929c\0" // Result<void> InitStream(MediaStreamProperties& props)
		"GetPixelStream@f7521c47c56fdbba\0" // Result<GetPixelHandlerStruct> GetPixelStream(const MediaStreamProperties& props, const PixelFormat& dstFormat, const ChannelOffsets& channelOffsets, const ColorProfile& dstColorProfile, GETPIXELHANDLERFLAGS flags)
		"FinishStream@d0b0f978b6e63019\0" // Result<void> FinishStream(const MediaStreamProperties& props)
	"";
	const maxon::METHOD_FLAGS MediaStreamImageDataExportInterface::MTable::_flags[] = 
	{
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE
	};
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(MediaStreamImageDataExportInterface, , "net.maxon.image.interface.mediastreamimagedataexport", "maxon.MediaStreamImageDataExportInterface", (MediaStreamImageBaseInterface::PrivateGetInterface()));
	const maxon::Char* const MediaStreamImageDataForwardImportInterface::MTable::_ids = 
		"SetSourceStream@3f8a85894ccd4905\0" // Result<void> SetSourceStream(const MediaStreamImageDataImportRef& sourceStream)
	"";
	const maxon::METHOD_FLAGS MediaStreamImageDataForwardImportInterface::MTable::_flags[] = 
	{
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE
	};
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(MediaStreamImageDataForwardImportInterface, , "net.maxon.image.interface.mediastreamimagedataforwardimport", "maxon.MediaStreamImageDataForwardImportInterface", (MediaStreamImageDataImportInterface::PrivateGetInterface()));
	const maxon::Char* const MediaStreamAudioDataImportInterface::MTable::_ids = 
		"SetCallbackHandler@123df3b881ddcb8f\0" // Result<void> SetCallbackHandler(const InitHandler& initHandler, const SetAudioDataHandler& getAudioDataHandler, const FinishHandler& finishHandler)
		"InitStream@7cfad6976c5d929c\0" // Result<void> InitStream(MediaStreamProperties& props)
		"SetAudioDataCallback@cf779e794dfbeec7\0" // Result<SetAudioDataCallbackType> SetAudioDataCallback(MediaStreamProperties& props)
		"FinishStream@d0b0f978b6e63019\0" // Result<void> FinishStream(const MediaStreamProperties& props)
	"";
	const maxon::METHOD_FLAGS MediaStreamAudioDataImportInterface::MTable::_flags[] = 
	{
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE
	};
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(MediaStreamAudioDataImportInterface, , "net.maxon.image.interface.mediastreamaudiodataimport", "maxon.MediaStreamAudioDataImportInterface", (MediaStreamInterface::PrivateGetInterface()));
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(MediaStreamBaseClass, , "net.maxon.image.class.mediastreambase");
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(MediaStreamExifDataClass, , "net.maxon.image.class.mediastreamexifdata");
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(MediaStreamImageBaseClass, , "net.maxon.image.class.mediastreamimagebase");
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(MediaStreamImageDataImportClass, , "net.maxon.image.class.mediastreamimagedataimport");
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(MediaStreamImageDataExportClass, , "net.maxon.image.class.mediastreamimagedataexport");
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(MediaStreamAudioDataImportClass, , "net.maxon.image.class.mediastreamaudiodataimport");
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(MediaStreamForwardImageDataStreamsImportClass, , "net.maxon.image.class.mediastreamforwardimagedatastreamsimport");
}
#endif
static maxon::details::ForceEvaluation s_forceEval_mediasession_stream(0
	| maxon::MediaStreamInterface::PrivateInstantiateNullValueHelper<maxon::Int>()
);
