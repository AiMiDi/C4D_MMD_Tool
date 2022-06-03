#if 1
namespace maxon
{
	const maxon::Char* const MediaConverterInterface::MTable::_ids = 
		"SupportImportStrategy@12e73654e6d65520\0" // Bool SupportImportStrategy() const
		"SupportExportStrategy@12e73654e6d65520\0" // Bool SupportExportStrategy() const
		"GetInputConverter@a1964a56b8d27eda\0" // Result<BaseArray<MediaConverterRef>> GetInputConverter() const
		"AddOutputStream@1881b5747c44f3c1\0" // Result<void> AddOutputStream(const MediaStreamRef& stream)
		"RemoveOutputStream@1881b5747c44f3c1\0" // Result<void> RemoveOutputStream(const MediaStreamRef& stream)
		"GetOutputStreams@6c1ede8cc577a952\0" // Result<BaseArray<MediaStreamRef>> GetOutputStreams(Bool flattenChildren) const
		"Analyze@b27a138c14b6c51b\0" // Result<void> Analyze(const Block<const MediaConverterRef>& inputs, const TimeValue& targetTime, MEDIASESSIONFLAGS flags)
		"PrepareExecute@b27a138c14b6c51b\0" // Result<void> PrepareExecute(const Block<const MediaConverterRef>& inputs, const TimeValue& targetTime, MEDIASESSIONFLAGS flags)
		"Execute@b27a138c14b6c51b\0" // Result<void> Execute(const Block<const MediaConverterRef>& inputs, const TimeValue& targetTime, MEDIASESSIONFLAGS flags)
		"Close@3b7e778705474a33\0" // Result<void> Close(const Block<const MediaConverterRef>& inputs)
	"";
	const maxon::METHOD_FLAGS MediaConverterInterface::MTable::_flags[] = 
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
		maxon::METHOD_FLAGS::NONE
	};
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(MediaConverterInterface, , "net.maxon.image.interface.mediaconverter", "maxon.MediaConverterInterface", (MediaBaseInterface::PrivateGetInterface()));
	const maxon::Char* const MediaConverterErrorInterface::MTable::_ids = 
	"";
	const maxon::METHOD_FLAGS MediaConverterErrorInterface::MTable::_flags[] = 
	{
		maxon::METHOD_FLAGS::NONE
	};
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(MediaConverterErrorInterface, , "net.maxon.image.interface.mediaconvertererror", "maxon.MediaConverterErrorInterface", (ErrorInterface::PrivateGetInterface()));
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(MediaConverterErrorObject, , "net.maxon.image.error.mediaconverter");
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(MediaConverterBaseClass, , "net.maxon.image.class.mediaconverterbase");
}
#endif
