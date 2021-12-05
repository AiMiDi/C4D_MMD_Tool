#if 1
namespace maxon
{
	const maxon::Char* const FunctionInterface::MTable::_ids = 
		"GetFunctionType@be2afc8840bfaf44\0" // const FunctionDataType& GetFunctionType() const
		"Invoke@106d261ab4f26c02\0" // Result<void> Invoke(GenericSingletonContainerInterface* outputs, GenericSingletonContainerInterface* inputs) const
		"Invoke@fc3ea436d73d4312\0" // Result<void> Invoke(GenericSingletonContainerInterface* outputs, GenericSingletonContainerInterface* inputs, Data& cacheData) const
		"GetConstantValue@14aec3ca93e27bcd\0" // ConstDataPtr GetConstantValue(const Member& output) const
	"";
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(FunctionInterface, , "net.maxon.interface.function", "maxon.FunctionInterface", (&ObjectInterface::_interface));
	template <typename DUMMY> maxon::Int FunctionInterface::PrivateInstantiateNullValueHelper()
	{
		return 0
		| maxon::details::InstantiateNullReturnValue<ConstDataPtr>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateNullReturnValue<const FunctionDataType&>(OVERLOAD_MAX_RANK)
		;
	}
	const maxon::Char* const FunctionLib::MTable::_ids = 
		"CreateConstantFunction@bd724c4b3dc10d86\0" // Result<GenericFunction> CreateConstantFunction(const InternedId& outputId, const DataType& resultType, const ConstDataPtr& value)
		"PrivateCreateWrapper@77a2f36f5f70d869\0" // Result<GenericFunction> PrivateCreateWrapper(void* function, const DataType& type, DestructWrapper destruct, InvokeWrapper invoke)
	"";
	MAXON_WARNING_PUSH
	MAXON_WARNING_DISABLE_DEPRECATED
	class FunctionLib::Hxx2::Unresolved : public FunctionLib
	{
	public:
		static const Unresolved* Get(const FunctionLib* o) { return (const Unresolved*) o; }
		static Unresolved* Get(FunctionLib* o) { return (Unresolved*) o; }
		static Result<GenericFunction> CreateConstantFunction(const InternedId& outputId, const DataType& resultType, const ConstDataPtr& value) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return FunctionLib::CreateConstantFunction(outputId, resultType, value); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static Result<GenericFunction> PrivateCreateWrapper(void* function, const DataType& type, DestructWrapper destruct, InvokeWrapper invoke) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return FunctionLib::PrivateCreateWrapper(function, type, std::forward<DestructWrapper>(destruct), std::forward<InvokeWrapper>(invoke)); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
	};
	MAXON_WARNING_POP
#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
	const maxon::NULL_RETURN_TYPE FunctionLib::MTable::_returnTypes[] = 
	{
		maxon::details::NullReturnType<Result<GenericFunction>>::value,
		maxon::details::NullReturnType<Result<GenericFunction>>::value,
		maxon::NULL_RETURN_TYPE::OTHER
	};
#endif
	maxon::Bool FunctionLib::MTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl)
	{
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<GenericFunction>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_FunctionLib_CreateConstantFunction = &Hxx2::Wrapper<Hxx2::Unresolved>::_FunctionLib_CreateConstantFunction;
		#else
		tbl->_FunctionLib_CreateConstantFunction = &Hxx2::Wrapper<Hxx2::Unresolved>::_FunctionLib_CreateConstantFunction;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<GenericFunction>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_FunctionLib_PrivateCreateWrapper = &Hxx2::Wrapper<Hxx2::Unresolved>::_FunctionLib_PrivateCreateWrapper;
		#else
		tbl->_FunctionLib_PrivateCreateWrapper = &Hxx2::Wrapper<Hxx2::Unresolved>::_FunctionLib_PrivateCreateWrapper;
		#endif
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_interface, (maxon::Char*) tbl, _returnTypes, SIZEOF(MTable) / SIZEOF(void*));
	#else
		return true;
	#endif
	}
	MAXON_INTERFACE_REGISTER(FunctionLib, "net.maxon.interface.functionlib", nullptr);
	namespace ParametricTypes
	{
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(Function, , "net.maxon.parametrictype.function");
	}
}
#endif
static maxon::details::ForceEvaluation s_forceEval_genericfunction(0
	| maxon::FunctionInterface::PrivateInstantiateNullValueHelper<maxon::Int>()
);
