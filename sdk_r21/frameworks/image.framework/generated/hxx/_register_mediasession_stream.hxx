#if 1
namespace maxon
{
	const maxon::Char* const MediaStreamInterface::MTable::_ids = 
		"GetFormats@d4a21ac11ff84834\0" // Result<BaseArray<Data>> GetFormats() const
		"GetFormat@6a63b7d3097bcb83\0" // MediaStreamFormat GetFormat(const Data& formatId) const
		"GetSelectedFormat@629b06512e59e356\0" // const Data& GetSelectedFormat() const
		"SetSelectedFormat@5b3e46c91f9c1707\0" // Result<void> SetSelectedFormat(const Data& formatId)
		"AddFormat@b1ac28ca17dd20ed\0" // Result<void> AddFormat(const Data& formatId, const MediaStreamFormat& ref)
		"SubscribeStream@5b3e46c91f9c1707\0" // Result<void> SubscribeStream(const Data& formatId)
		"UnsubscribeStream@a54f4799cbe1a498\0" // Result<void> UnsubscribeStream()
		"IsSubscribed@76f01901\0" // Bool IsSubscribed() const
	"";
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL(MediaStreamInterface, MediaStreamInterface, , , "net.maxon.image.interface.mediastream", "maxon.MediaStreamInterface", (&MediaBaseInterface::_interface), (&HierarchyObjectInterface::_interface), nullptr);
	template <typename DUMMY> maxon::Int MediaStreamInterface::PrivateInstantiateNullValueHelper()
	{
		return 0
		| maxon::details::InstantiateNullReturnValue<MediaStreamFormat>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateNullReturnValue<const Data&>(OVERLOAD_MAX_RANK)
		;
	}
	const maxon::Char* const MediaStreamExifDataInterface::MTable::_ids = 
		"SetCallbackHandler@30e953498f9352eb\0" // Result<void> SetCallbackHandler(const ExifDataHandler& handleExifData)
		"HandleExifData@142f67008b82e5f8\0" // Result<void> HandleExifData(const ExifRef& exifData)
		"FinishStream@7d86195c0d162444\0" // Result<void> FinishStream(const MediaStreamProperties& props)
	"";
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(MediaStreamExifDataInterface, , "net.maxon.image.interface.mediastreamexifdata", "maxon.MediaStreamExifDataInterface", (&MediaStreamInterface::_interface));
	const maxon::Char* const MediaStreamImageBaseInterface::MTable::_ids = 
	"";
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(MediaStreamImageBaseInterface, , "net.maxon.image.interface.mediastreamimagebase", "maxon.MediaStreamImageBaseInterface", (&MediaStreamInterface::_interface));
	const maxon::Char* const MediaStreamImageDataImportInterface::MTable::_ids = 
		"SetCallbackHandler@8ff98326e8208e50\0" // Result<void> SetCallbackHandler(const InitHandler& initHandler, const SetPixelHandler& setPixelHandler, const FinishHandler& finishHandler)
		"InitStream@7d86195c0d162444\0" // Result<void> InitStream(const MediaStreamProperties& props)
		"SetPixelStream@fd0e659e2b8e8d20\0" // Result<SetPixelHandlerStruct> SetPixelStream(const MediaStreamProperties& props, const ChannelOffsets& srcChannelOffsets, SETPIXELHANDLERFLAGS setPixelFlags)
		"FinishStream@7d86195c0d162444\0" // Result<void> FinishStream(const MediaStreamProperties& props)
	"";
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(MediaStreamImageDataImportInterface, , "net.maxon.image.interface.mediastreamimagedataimport", "maxon.MediaStreamImageDataImportInterface", (&MediaStreamImageBaseInterface::_interface));
	const maxon::Char* const MediaStreamImageDataExportInterface::MTable::_ids = 
		"SetCallbackHandler@fbd77ed9fc42a444\0" // Result<void> SetCallbackHandler(const InitHandler& initHandler, const GetPixelHandler& getPixelHandler, const FinishHandler& finishHandler)
		"InitStream@1b7d4cd9a8ac24e7\0" // Result<void> InitStream(MediaStreamProperties& props)
		"GetPixelStream@95e1322f0ec72551\0" // Result<GetPixelHandlerStruct> GetPixelStream(const MediaStreamProperties& props, const PixelFormat& dstFormat, const ChannelOffsets& channelOffsets, const ColorProfile& dstColorProfile, GETPIXELHANDLERFLAGS flags)
		"FinishStream@7d86195c0d162444\0" // Result<void> FinishStream(const MediaStreamProperties& props)
	"";
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(MediaStreamImageDataExportInterface, , "net.maxon.image.interface.mediastreamimagedataexport", "maxon.MediaStreamImageDataExportInterface", (&MediaStreamImageBaseInterface::_interface));
	const maxon::Char* const MediaStreamImageDataForwardImportInterface::MTable::_ids = 
		"SetSourceStream@ce034047b8c5aaae\0" // Result<void> SetSourceStream(const MediaStreamImageDataImportRef& sourceStream)
	"";
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(MediaStreamImageDataForwardImportInterface, , "net.maxon.image.interface.mediastreamimagedataforwardimport", "maxon.MediaStreamImageDataForwardImportInterface", (&MediaStreamImageDataImportInterface::_interface));
	const maxon::Char* const MediaStreamAudioDataImportInterface::MTable::_ids = 
		"SetCallbackHandler@ecd79ac67827ad76\0" // Result<void> SetCallbackHandler(const InitHandler& initHandler, const SetAudioDataHandler& getAudioDataHandler, const FinishHandler& finishHandler)
		"InitStream@1b7d4cd9a8ac24e7\0" // Result<void> InitStream(MediaStreamProperties& props)
		"SetAudioDataCallback@698f816366dd0d90\0" // Result<SetAudioDataCallbackType> SetAudioDataCallback(MediaStreamProperties& props)
		"FinishStream@7d86195c0d162444\0" // Result<void> FinishStream(const MediaStreamProperties& props)
	"";
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(MediaStreamAudioDataImportInterface, , "net.maxon.image.interface.mediastreamaudiodataimport", "maxon.MediaStreamAudioDataImportInterface", (&MediaStreamInterface::_interface));
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
