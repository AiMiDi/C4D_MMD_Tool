#if 1
namespace maxon
{
	const maxon::Char* const IoDualInOutputStreamInterface::MTable::_ids = 
		"SetInputStream@219a6e5e63cf3821\0" // Result<void> SetInputStream(const InputStreamRef& inputStream)
		"SetOutputStream@e084635b6c5cdcd8\0" // Result<void> SetOutputStream(const OutputStreamRef& outputStream)
		"GetInputStream@e8d1bf47d9152c85\0" // InputStreamRef GetInputStream() const
		"GetOutputStream@fbcdafe3f53cfb74\0" // OutputStreamRef GetOutputStream() const
	"";
	const maxon::METHOD_FLAGS IoDualInOutputStreamInterface::MTable::_flags[] = 
	{
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE
	};
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(IoDualInOutputStreamInterface, , "net.maxon.interface.iodualinoutputstream", (InOutputStreamInterface::PrivateGetInterface()));
	template <typename DUMMY> maxon::Int IoDualInOutputStreamInterface::PrivateInstantiateDefaultValueHelper()
	{
		return 0
		| maxon::details::InstantiateDefaultReturnValue<InputStreamRef>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateDefaultReturnValue<OutputStreamRef>(OVERLOAD_MAX_RANK)
		;
	}
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(InOutputStreamDualClass, , "net.maxon.class.inoutputstreamdual");
}
#endif
static maxon::details::ForceEvaluation s_forceEval_iostream_dualinoutput(0
	| maxon::IoDualInOutputStreamInterface::PrivateInstantiateDefaultValueHelper<maxon::Int>()
);
