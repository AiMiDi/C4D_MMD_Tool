#if 1
namespace maxon
{
	template <typename DUMMY> maxon::Int ParametricTypeInterface::PrivateInstantiateNullValueHelper()
	{
		return 0
		| maxon::details::InstantiateNullReturnValue<const Id&>(OVERLOAD_MAX_RANK)
		;
	}
	MAXON_REGISTRY_REGISTER(ParametricTypes);
	namespace ParametricTypes
	{
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(Const, , "net.maxon.parametrictype.const");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(Opaque, , "net.maxon.parametrictype.opaque");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(Pointer, , "net.maxon.parametrictype.pointer");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(LVReference, , "net.maxon.parametrictype.lvreference");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(RVReference, , "net.maxon.parametrictype.rvreference");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(UniqueReference, , "net.maxon.parametrictype.uniquereference");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(StrongReference, , "net.maxon.parametrictype.strongreference");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(COWReference, , "net.maxon.parametrictype.cowreference");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(ACOWReference, , "net.maxon.parametrictype.acowreference");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(Block, , "net.maxon.parametrictype.block");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(StridedBlock, , "net.maxon.parametrictype.stridedblock");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(Optional, , "net.maxon.parametrictype.optional");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(Result, , "net.maxon.parametrictype.result");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(Simd, , "net.maxon.parametrictype.simd");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(Tuple, , "net.maxon.parametrictype.tuple");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(IntegralConstant, , "net.maxon.parametrictype.integralconstant");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(BaseArray, , "net.maxon.parametrictype.basearray");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(Container, , "net.maxon.parametrictype.container");
	}
}
#endif
static maxon::details::ForceEvaluation s_forceEval_parametric_type(0
	| maxon::ParametricTypeInterface::PrivateInstantiateNullValueHelper<maxon::Int>()
);
