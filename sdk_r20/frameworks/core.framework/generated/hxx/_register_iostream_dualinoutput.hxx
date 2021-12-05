#if 1
namespace maxon
{
	MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(IoDualInOutputStreamInterface, "net.maxon.interface.iodualinoutputstream", "maxon.IoDualInOutputStreamInterface", , &InOutputStreamInterface::_interface);
	const maxon::Char* const IoDualInOutputStreamInterface::MTable::_ids = 
		"SetInputStream@f8130eb391960c88\0" // SetInputStream(const InputStreamRef& inputStream)
		"SetOutputStream@b053972c29be8749\0" // SetOutputStream(const OutputStreamRef& outputStream)
		"GetInputStream@1fc545ea01f606a0\0" // GetInputStream() const
		"GetOutputStream@f3789599c69828c9\0" // GetOutputStream() const
	"";
	template <typename DUMMY> maxon::Int IoDualInOutputStreamInterface::PrivateInstantiateNullValueHelper()
	{
		return 0
		| maxon::details::InstantiateNullReturnValue<InputStreamRef>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateNullReturnValue<OutputStreamRef>(OVERLOAD_MAX_RANK)
		;
	}
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(InOutputStreamDualClass, , "net.maxon.class.inoutputstreamdual");
}
#endif
static maxon::details::ForceEvaluation s_forceEval_iostream_dualinoutput(0
	| maxon::IoDualInOutputStreamInterface::PrivateInstantiateNullValueHelper<maxon::Int>()
);
