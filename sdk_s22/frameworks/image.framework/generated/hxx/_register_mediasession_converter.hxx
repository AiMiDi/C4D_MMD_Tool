#if 1
namespace maxon
{
	const maxon::Char* const MediaConverterInterface::MTable::_ids = 
		"SupportImportStrategy@76f01901\0" // Bool SupportImportStrategy() const
		"SupportExportStrategy@76f01901\0" // Bool SupportExportStrategy() const
		"GetInputConverter@79115fd18990971b\0" // Result<BaseArray<MediaConverterRef>> GetInputConverter() const
		"AddOutputStream@a987c0c070c64c22\0" // Result<void> AddOutputStream(const MediaStreamRef& stream)
		"RemoveOutputStream@a987c0c070c64c22\0" // Result<void> RemoveOutputStream(const MediaStreamRef& stream)
		"GetOutputStreams@5eba919f49e40e6f\0" // Result<BaseArray<MediaStreamRef>> GetOutputStreams(Bool flattenChildren) const
		"Analyze@f7feec5620faa4f6\0" // Result<void> Analyze(const Block<const MediaConverterRef>& inputs, const TimeValue& targetTime, MEDIASESSIONFLAGS flags)
		"PrepareExecute@f7feec5620faa4f6\0" // Result<void> PrepareExecute(const Block<const MediaConverterRef>& inputs, const TimeValue& targetTime, MEDIASESSIONFLAGS flags)
		"Execute@f7feec5620faa4f6\0" // Result<void> Execute(const Block<const MediaConverterRef>& inputs, const TimeValue& targetTime, MEDIASESSIONFLAGS flags)
		"Close@fed3d54db1587d7e\0" // Result<void> Close(const Block<const MediaConverterRef>& inputs)
	"";
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(MediaConverterInterface, , "net.maxon.image.interface.mediaconverter", "maxon.MediaConverterInterface", (&MediaBaseInterface::_interface));
	const maxon::Char* const MediaConverterErrorInterface::MTable::_ids = 
	"";
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(MediaConverterErrorInterface, , "net.maxon.image.interface.mediaconvertererror", "maxon.MediaConverterErrorInterface", (&ErrorInterface::_interface));
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(MediaConverterErrorObject, , "net.maxon.image.error.mediaconverter");
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(MediaConverterBaseClass, , "net.maxon.image.class.mediaconverterbase");
}
#endif
