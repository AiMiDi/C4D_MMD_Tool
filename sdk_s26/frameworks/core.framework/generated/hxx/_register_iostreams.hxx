#if 1
namespace maxon
{
	const maxon::Char* const IoErrorInterface::MTable::_ids = 
		"SetUrl@17f1a32c75c62168\0" // void SetUrl(const Url& url)
		"GetUrl@dd23129f046419ec\0" // const Url& GetUrl() const
	"";
	const maxon::METHOD_FLAGS IoErrorInterface::MTable::_flags[] = 
	{
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE
	};
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(IoErrorInterface, , "net.maxon.interface.ioerror", "maxon.IoErrorInterface", (ErrorInterface::PrivateGetInterface()));
	template <typename DUMMY> maxon::Int IoErrorInterface::PrivateInstantiateNullValueHelper()
	{
		return 0
		| maxon::details::InstantiateNullReturnValue<const Url&>(OVERLOAD_MAX_RANK)
		;
	}
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(IoErrorObject, , "net.maxon.error.io");
	const maxon::Char* const FileFormatErrorInterface::MTable::_ids = 
	"";
	const maxon::METHOD_FLAGS FileFormatErrorInterface::MTable::_flags[] = 
	{
		maxon::METHOD_FLAGS::NONE
	};
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(FileFormatErrorInterface, , "net.maxon.interface.fileformaterror", "maxon.FileFormatErrorInterface", (IoErrorInterface::PrivateGetInterface()));
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(FileFormatErrorObject, , "net.maxon.error.fileformat");
	namespace STREAMFLAGS
	{
		HTTP_REMOTEADDRESS_PrivateAttribute HTTP_REMOTEADDRESS;
		HTTP_HEADER_PrivateAttribute HTTP_HEADER;
	}
	const maxon::Char* const UnknownFileSizeErrorInterface::MTable::_ids = 
	"";
	const maxon::METHOD_FLAGS UnknownFileSizeErrorInterface::MTable::_flags[] = 
	{
		maxon::METHOD_FLAGS::NONE
	};
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(UnknownFileSizeErrorInterface, , "net.maxon.interface.unknownfilesizeerror", "maxon.UnknownFileSizeErrorInterface", (ErrorInterface::PrivateGetInterface()));
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(UnknownFileSizeErrorObject, , "net.maxon.error.unknownfilesize");
	const maxon::Char* const BaseStreamInterface::MTable::_ids = 
		"GetStreamLength@bb48d07a52041bca\0" // Result<Int64> GetStreamLength() const
		"GetPosition@bb48d07a52041bca\0" // Result<Int64> GetPosition() const
		"Close@3008090429c5a175\0" // Result<void> Close()
		"SeekSupported@12e73654e6d65520\0" // Bool SeekSupported() const
		"Seek@7060349c53ee40f4\0" // Result<void> Seek(Int64 position)
		"DisableBuffering@780cdac8f1a33934\0" // void DisableBuffering()
	"";
	const maxon::METHOD_FLAGS BaseStreamInterface::MTable::_flags[] = 
	{
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE
	};
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(BaseStreamInterface, , "net.maxon.interface.basestream", "maxon.BaseStreamInterface", (DataDictionaryObjectInterface::PrivateGetInterface()));
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(FromBlock, InputStreamInterface::, "net.maxon.inputstreaminterface.fromblock");
	const maxon::Char* const InputStreamInterface::MTable::_ids = 
		"BytesAvailable@bb48d07a52041bca\0" // Result<Int64> BytesAvailable() const
		"ReadEOS@ace1093bb90c73a6\0" // Result<Int> ReadEOS(const Block<Byte>& data)
		"Skip@7060349c53ee40f4\0" // Result<void> Skip(Int64 bytes)
	"";
	const maxon::METHOD_FLAGS InputStreamInterface::MTable::_flags[] = 
	{
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE
	};
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(InputStreamInterface, , "net.maxon.interface.inputstream", "maxon.InputStreamInterface", (BaseStreamInterface::PrivateGetInterface()));
	const maxon::Char* const OutputStreamInterface::MTable::_ids = 
		"Write@f8f7b06e2c55bd6c\0" // Result<void> Write(const Block<const Byte>& data)
		"Flush@3008090429c5a175\0" // Result<void> Flush()
	"";
	const maxon::METHOD_FLAGS OutputStreamInterface::MTable::_flags[] = 
	{
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE
	};
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(OutputStreamInterface, , "net.maxon.interface.outputstream", "maxon.OutputStreamInterface", (BaseStreamInterface::PrivateGetInterface()));
	const maxon::Char* const InOutputStreamInterface::MTable::_ids = 
	"";
	const maxon::METHOD_FLAGS InOutputStreamInterface::MTable::_flags[] = 
	{
		maxon::METHOD_FLAGS::NONE
	};
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL(InOutputStreamInterface, InOutputStreamInterface, , , "net.maxon.interface.inoutputstream", "maxon.InOutputStreamInterface", (InputStreamInterface::PrivateGetInterface()), (OutputStreamInterface::PrivateGetInterface()), nullptr);
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(IoErrorObjectClass, , "net.maxon.class.ioerrorobject");
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(InputStreamBaseClass, , "net.maxon.class.inputstreambase");
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(OutputStreamBaseClass, , "net.maxon.class.outputstreambase");
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(InOutputStreamBaseClass, , "net.maxon.class.inoutputstreambase");
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(InputStreamDecoratorBaseClass, , "net.maxon.class.inputstreamdecorator");
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(OutputStreamDecoratorBaseClass, , "net.maxon.class.outputstreamdecorator");
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(InOutputStreamDecoratorBaseClass, , "net.maxon.class.inoutputstreamdecorator");
}
#endif
static maxon::details::ForceEvaluation s_forceEval_iostreams(0
	| maxon::IoErrorInterface::PrivateInstantiateNullValueHelper<maxon::Int>()
);
