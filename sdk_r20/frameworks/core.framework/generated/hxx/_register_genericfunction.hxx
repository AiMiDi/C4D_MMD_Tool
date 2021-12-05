#if 1
namespace maxon
{
	MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(FunctionInterface, "net.maxon.interface.function", "maxon.FunctionInterface", , &Object::_interface);
	const maxon::Char* const FunctionInterface::MTable::_ids = 
		"GetFunctionType@be2afc8840bfbe48\0" // GetFunctionType() const
		"Invoke@70108636f0c0b666\0" // Invoke(DynamicTupleInterface* outputs, DynamicTupleInterface* inputs) const
		"Invoke@01642f9db79b3276\0" // Invoke(DynamicTupleInterface* outputs, DynamicTupleInterface* inputs, Data& cacheData) const
		"GetConstantValue@14aec3ca93e27bcd\0" // GetConstantValue(const Member& output) const
	"";
	template <typename DUMMY> maxon::Int FunctionInterface::PrivateInstantiateNullValueHelper()
	{
		return 0
		| maxon::details::InstantiateNullReturnValue<ConstDataPtr>(OVERLOAD_MAX_RANK)
		;
	}
	const maxon::Char* const FunctionLib::MTable::_ids = 
		"GetConstantFunctionClass@f992aca02daaa8f3\0" // GetConstantFunctionClass()
		"CreateConstantFunction@447cbd6d8288d0a9\0" // CreateConstantFunction(InternedId outputId, const DataType* resultType, const ConstDataPtr& value)
		"PrivateCreateWrapper@75f3f0d58031d7e5\0" // PrivateCreateWrapper(void* function, const DataType* type, DestructWrapper destruct, InvokeWrapper invoke)
	"";
	class FunctionLib::Unresolved : public FunctionLib
	{
	public:
		static const Unresolved* Get(const FunctionLib* o) { return (const Unresolved*) o; }
		static Unresolved* Get(FunctionLib* o) { return (Unresolved*) o; }
		static Class<GenericFunction> GetConstantFunctionClass() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return FunctionLib::GetConstantFunctionClass(); return maxon::PrivateIncompleteNullReturnValue<Class<GenericFunction>>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		static Result<GenericFunction> CreateConstantFunction(InternedId outputId, const DataType* resultType, const ConstDataPtr& value) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return FunctionLib::CreateConstantFunction(std::forward<InternedId>(outputId), resultType, value); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static Result<GenericFunction> PrivateCreateWrapper(void* function, const DataType* type, DestructWrapper destruct, InvokeWrapper invoke) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return FunctionLib::PrivateCreateWrapper(function, type, std::forward<DestructWrapper>(destruct), std::forward<InvokeWrapper>(invoke)); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
	};
#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
	const maxon::NULL_RETURN_TYPE FunctionLib::MTable::_returnTypes[] = 
	{
		maxon::details::NullReturnType<Class<GenericFunction>>::value,
		maxon::details::NullReturnType<Result<GenericFunction>>::value,
		maxon::details::NullReturnType<Result<GenericFunction>>::value,
		maxon::NULL_RETURN_TYPE::OTHER
	};
#endif
	maxon::Bool FunctionLib::MTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl)
	{
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Class<GenericFunction>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_FunctionLib_GetConstantFunctionClass = &Wrapper<Unresolved>::_FunctionLib_GetConstantFunctionClass;
	#else
		tbl->_FunctionLib_GetConstantFunctionClass = &Wrapper<Unresolved>::_FunctionLib_GetConstantFunctionClass;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<GenericFunction>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_FunctionLib_CreateConstantFunction = &Wrapper<Unresolved>::_FunctionLib_CreateConstantFunction;
	#else
		tbl->_FunctionLib_CreateConstantFunction = &Wrapper<Unresolved>::_FunctionLib_CreateConstantFunction;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<GenericFunction>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_FunctionLib_PrivateCreateWrapper = &Wrapper<Unresolved>::_FunctionLib_PrivateCreateWrapper;
	#else
		tbl->_FunctionLib_PrivateCreateWrapper = &Wrapper<Unresolved>::_FunctionLib_PrivateCreateWrapper;
	#endif
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_interface, (maxon::Char*) tbl, _returnTypes, SIZEOF(_returnTypes) - 1);
	#else
		return true;
	#endif
	}
	MAXON_INTERFACE_REGISTER(FunctionLib, "net.maxon.interface.functionlib", nullptr);
	template <typename DUMMY> maxon::Int FunctionLib::PrivateInstantiateNullValueHelper()
	{
		return 0
		| maxon::details::InstantiateNullReturnValue<Class<GenericFunction>>(OVERLOAD_MAX_RANK)
		;
	}
}
#endif
static maxon::details::ForceEvaluation s_forceEval_genericfunction(0
	| maxon::FunctionInterface::PrivateInstantiateNullValueHelper<maxon::Int>()
	| maxon::FunctionLib::PrivateInstantiateNullValueHelper<maxon::Int>()
);
