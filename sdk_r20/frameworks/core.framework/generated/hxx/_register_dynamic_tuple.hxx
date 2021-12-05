#if 1
namespace maxon
{
	template <typename DUMMY> maxon::Int DynamicTupleInterface::PrivateInstantiateNullValueHelper()
	{
		return 0
		;
	}
}
#endif
static maxon::details::ForceEvaluation s_forceEval_dynamic_tuple(0
	| maxon::DynamicTupleInterface::PrivateInstantiateNullValueHelper<maxon::Int>()
);
