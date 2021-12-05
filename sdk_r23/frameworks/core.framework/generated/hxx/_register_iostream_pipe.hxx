#if 1
namespace maxon
{
	namespace URLFLAGS
	{
		PIPE_CREATE_PrivateAttribute PIPE_CREATE;
	}
#ifdef MAXON_TARGET_WINDOWS
#else
#endif
	const maxon::Char* const IoPipeInOutputStreamInterface::MTable::_ids = 
		"GetReadHandle@810585202581d1b2\0" // PIPEHANDLE GetReadHandle() const
		"GetWriteHandle@810585202581d1b2\0" // PIPEHANDLE GetWriteHandle() const
	"";
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(IoPipeInOutputStreamInterface, , "net.maxon.interface.iopipeinoutputstream", "maxon.IoPipeInOutputStreamInterface", (InOutputStreamInterface::PrivateGetInterface()));
	template <typename DUMMY> maxon::Int IoPipeInOutputStreamInterface::PrivateInstantiateNullValueHelper()
	{
		return 0
		| maxon::details::InstantiateNullReturnValue<PIPEHANDLE>(OVERLOAD_MAX_RANK)
		;
	}
}
#endif
static maxon::details::ForceEvaluation s_forceEval_iostream_pipe(0
	| maxon::IoPipeInOutputStreamInterface::PrivateInstantiateNullValueHelper<maxon::Int>()
);
