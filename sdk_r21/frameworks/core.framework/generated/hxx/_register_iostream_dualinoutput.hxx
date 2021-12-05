#if 1
namespace maxon
{
	const maxon::Char* const IoDualInOutputStreamInterface::MTable::_ids = 
		"SetInputStream@f8130eb391960c88\0" // Result<void> SetInputStream(const InputStreamRef& inputStream)
		"SetOutputStream@b053972c29be8749\0" // Result<void> SetOutputStream(const OutputStreamRef& outputStream)
		"GetInputStream@1fc545ea01f606a0\0" // InputStreamRef GetInputStream() const
		"GetOutputStream@f3789599c69828c9\0" // OutputStreamRef GetOutputStream() const
	"";
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(IoDualInOutputStreamInterface, , "net.maxon.interface.iodualinoutputstream", "maxon.IoDualInOutputStreamInterface", (&InOutputStreamInterface::_interface));
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
