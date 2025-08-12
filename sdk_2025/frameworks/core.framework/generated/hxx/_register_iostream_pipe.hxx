#if 1
namespace maxon
{
#ifdef MAXON_TARGET_WINDOWS
#else
#endif
	const maxon::Char* const IoPipeInOutputStreamInterface::MTable::_ids = 
		"GetReadHandle@810585202581d1b2\0" // PIPEHANDLE GetReadHandle() const
		"GetWriteHandle@810585202581d1b2\0" // PIPEHANDLE GetWriteHandle() const
	"";
	const maxon::METHOD_FLAGS IoPipeInOutputStreamInterface::MTable::_flags[] = 
	{
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE
	};
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(IoPipeInOutputStreamInterface, , "net.maxon.interface.iopipeinoutputstream", (InOutputStreamInterface::PrivateGetInterface()));
	template <typename DUMMY> maxon::Int IoPipeInOutputStreamInterface::PrivateInstantiateDefaultValueHelper()
	{
		return 0
		| maxon::details::InstantiateDefaultReturnValue<PIPEHANDLE>(OVERLOAD_MAX_RANK)
		;
	}
}
#endif
static maxon::details::ForceEvaluation s_forceEval_iostream_pipe(0
	| maxon::IoPipeInOutputStreamInterface::PrivateInstantiateDefaultValueHelper<maxon::Int>()
);
