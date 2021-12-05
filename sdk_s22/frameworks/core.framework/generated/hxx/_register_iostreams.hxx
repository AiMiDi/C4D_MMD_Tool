#if 1
namespace maxon
{
	const maxon::Char* const IoErrorInterface::MTable::_ids = 
		"SetUrl@908beb5b7ad255a3\0" // void SetUrl(const Url& url)
		"GetUrl@24368c97617cbacb\0" // const Url& GetUrl() const
	"";
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(IoErrorInterface, , "net.maxon.interface.ioerror", "maxon.IoErrorInterface", (&ErrorInterface::_interface));
	template <typename DUMMY> maxon::Int IoErrorInterface::PrivateInstantiateNullValueHelper()
	{
		return 0
		| maxon::details::InstantiateNullReturnValue<const Url&>(OVERLOAD_MAX_RANK)
		;
	}
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(IoErrorObject, , "net.maxon.error.io");
	const maxon::Char* const FileFormatErrorInterface::MTable::_ids = 
	"";
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(FileFormatErrorInterface, , "net.maxon.interface.fileformaterror", "maxon.FileFormatErrorInterface", (&IoErrorInterface::_interface));
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(FileFormatErrorObject, , "net.maxon.error.fileformat");
	namespace STREAMFLAGS
	{
		HTTP_REMOTEADDRESS_PrivateAttribute HTTP_REMOTEADDRESS;
		HTTP_HEADER_PrivateAttribute HTTP_HEADER;
	}
	const maxon::Char* const UnknownFileSizeErrorInterface::MTable::_ids = 
	"";
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(UnknownFileSizeErrorInterface, , "net.maxon.interface.unknownfilesizeerror", "maxon.UnknownFileSizeErrorInterface", (&ErrorInterface::_interface));
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(UnknownFileSizeErrorObject, , "net.maxon.error.unknownfilesize");
	const maxon::Char* const BaseStreamInterface::MTable::_ids = 
		"GetStreamLength@8e9bc735f2c8b3e7\0" // Result<Int64> GetStreamLength() const
		"GetPosition@8e9bc735f2c8b3e7\0" // Result<Int64> GetPosition() const
		"Close@a54f4799cbe1a498\0" // Result<void> Close()
		"SeekSupported@76f01901\0" // Bool SeekSupported() const
		"Seek@829678d85b1de935\0" // Result<void> Seek(Int64 position)
		"DisableBuffering@6b2e10f\0" // void DisableBuffering()
	"";
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(BaseStreamInterface, , "net.maxon.interface.basestream", "maxon.BaseStreamInterface", (&DataDictionaryObjectInterface::_interface));
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(FromBlock, InputStreamInterface::, "net.maxon.inputstreaminterface.fromblock");
	const maxon::Char* const InputStreamInterface::MTable::_ids = 
		"BytesAvailable@8e9bc735f2c8b3e7\0" // Result<Int64> BytesAvailable() const
		"ReadEOS@5e8101ec4c77c2d1\0" // Result<Int> ReadEOS(const Block<Byte>& data)
		"Skip@829678d85b1de935\0" // Result<void> Skip(Int64 bytes)
	"";
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(InputStreamInterface, , "net.maxon.interface.inputstream", "maxon.InputStreamInterface", (&BaseStreamInterface::_interface));
	const maxon::Char* const OutputStreamInterface::MTable::_ids = 
		"Write@c6fd6f387b0ccd91\0" // Result<void> Write(const Block<const Byte>& data)
		"Flush@a54f4799cbe1a498\0" // Result<void> Flush()
	"";
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(OutputStreamInterface, , "net.maxon.interface.outputstream", "maxon.OutputStreamInterface", (&BaseStreamInterface::_interface));
	const maxon::Char* const InOutputStreamInterface::MTable::_ids = 
	"";
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL(InOutputStreamInterface, InOutputStreamInterface, , , "net.maxon.interface.inoutputstream", "maxon.InOutputStreamInterface", (&InputStreamInterface::_interface), (&OutputStreamInterface::_interface), nullptr);
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
