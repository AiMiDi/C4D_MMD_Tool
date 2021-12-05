#if 1
namespace maxon
{
	namespace enum313
	{
		enum class INNERMOST_MEMBER : Int32
		{
		} ;
		static const maxon::EnumInfo INNERMOST_MEMBER_info{"INNERMOST_MEMBER", SIZEOF(INNERMOST_MEMBER), false, "", nullptr, 0};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_INNERMOST_MEMBER313(){ return enum313::INNERMOST_MEMBER_info; }
	const maxon::Char* const DataTypeLib::MTable::_ids = 
		"GetDataTypeType@a6c0b400d8ac1aac\0" // const DataType& GetDataTypeType()
		"GetVoidType@a6c0b400d8ac1aac\0" // const DataType& GetVoidType()
		"GetNullptrType@a6c0b400d8ac1aac\0" // const DataType& GetNullptrType()
		"GetGenericType@a6c0b400d8ac1aac\0" // const DataType& GetGenericType()
		"GetGenericArithmeticType@a6c0b400d8ac1aac\0" // const DataType& GetGenericArithmeticType()
		"GetParametricTypeType@a6c0b400d8ac1aac\0" // const DataType& GetParametricTypeType()
		"GetComponentDescriptorType@a6c0b400d8ac1aac\0" // const DataType& GetComponentDescriptorType()
		"GetEllipsisType@a6c0b400d8ac1aac\0" // const DataType& GetEllipsisType()
		"GetInvalidType@a6c0b400d8ac1aac\0" // const DataType& GetInvalidType()
		"Substitute@277c649fa4927ad0\0" // Result<DataType> Substitute(const DataType& orig, const Delegate<Result<DataType>(const DataType&)>& replace)
		"GetRuntimeDataType@44141c477a3beef5\0" // Result<DataType> GetRuntimeDataType(const DataType& orig)
		"GetTupleMemberOffsets@13be251587b9e676\0" // const Block<const Int>& GetTupleMemberOffsets(const TupleDataType& type)
		"GetDelegateType@120db764a61d1838\0" // Result<DelegateDataType> GetDelegateType(const DataType& returnType, const Block<const DataType>& paramTypes, reflection::DelegateFunctionPointer function, void* handlerStub)
		"GetDelegateType@2db8b96ca2e026ac\0" // Result<DelegateDataType> GetDelegateType(const Result<DataType>& returnType, const Block<const Result<DataType>>& paramTypes, reflection::DelegateFunctionPointer function, void* handlerStub)
		"InvokeDelegate@479daa2e29e9f0f5\0" // Result<void> InvokeDelegate(const DelegateDataType& delegateType, const DelegateBase& delegate, void* result, const Block<reflection::Argument>& arguments)
		"CreateDelegate@195e06c2410dba8a\0" // Result<DelegateBase> CreateDelegate(const DelegateDataType& delegateType, reflection::DelegateHandler&& handler)
		"GetDelegateReturnType@9f5d84a77bb3968a\0" // const DataType& GetDelegateReturnType(const DelegateDataType& delegateType)
		"GetDelegateParameterTypes@44fc52599a8dd302\0" // const Block<const DataType>& GetDelegateParameterTypes(const DelegateDataType& delegateType)
		"GetEnumType@27f20718795a247a\0" // Result<EnumDataType> GetEnumType(const DataType& underlyingType, const Block<const Tuple<Id, Data>>& enumerators)
		"GetEnumerators@60d7adc858e7c144\0" // const Block<const Tuple<Id, Data>>& GetEnumerators(const DataType& enumType)
		"RegisterEnumType@2bee4d9573888913\0" // Result<void> RegisterEnumType(DataTypeImpl& type, const Id& typeId, Int size, Bool isSigned, Bool flags, const UInt64* enumValues, const Char* enumValueNames)
		"GetDataTypeOfInterfaces@ba11926a8f2bcd76\0" // Result<DataType> GetDataTypeOfInterfaces(const Block<const InterfaceReference* const>& interfaces)
		"GetReferenceType@3c6381ca3244325a\0" // Result<DataType> GetReferenceType(const DataType& type, EntityBase::FLAGS refFlags)
		"ParseDataType@38b7f6057ee736ee\0" // Result<Tuple<DataType, const Char*>> ParseDataType(const Char* str)
		"ParseMember@982a9afd155a9818\0" // Result<Tuple<Member, const Char*>> ParseMember(const Char* str)
		"ParseInt@93e79709a9a79d9\0" // Result<Tuple<Int64, const Char*>> ParseInt(const Char* str)
		"GetDataType@ba7c0600706041b0\0" // Result<DataType> GetDataType(const Id& typeId)
		"GetNumberedId@5681990457124c48\0" // const Id& GetNumberedId(Int number)
		"GetMemberMap@560262950a966298\0" // Result<const MemberMap*> GetMemberMap(Block<const Int> block)
		"GetIdentityMemberMap@de88c3db0db59466\0" // Result<const MemberMap*> GetIdentityMemberMap(Int length)
		"ConcatMemberMap@e0ecb52d4d45c313\0" // Result<const MemberMap*> ConcatMemberMap(const MemberMap* first, const MemberMap* second)
		"GetMemberMap@ec04c37c55558c79\0" // Result<const MemberMap*> GetMemberMap(const DataTypeImpl* containerType, const DataTypeImpl* runtimeType)
		"GetConstant@d07d3cba13583172\0" // ConstDataPtr GetConstant(const DataType& type, Int value)
		"GetDataTypeForData@44141c477a3beef5\0" // Result<DataType> GetDataTypeForData(const DataType& valueType)
		"ConvertToData@9e5429fdead6ab28\0" // Result<void> ConvertToData(Data& result, const DataType& dataType, const DataType& valueType, const Generic& value)
		"MoveFromData@ce3c76dda0af44cc\0" // Result<void> MoveFromData(const DataType& valueType, Generic& value, Bool createDefaultPointees, Data& data, BaseArray<Data>& storage)
		"PrivateIsBaseOfOrSame@213ba7842c3bed06\0" // Bool PrivateIsBaseOfOrSame(const DataTypeImpl* type, const DataTypeImpl* other, DataType::BASE_OF_MODE mode)
		"CreateTypeArguments@6b9ffb0683c89817\0" // Result<StrongRef<TypeArguments>> CreateTypeArguments(Int cnt)
		"CreateTypeArguments@186ad8df7a1966b9\0" // Result<StrongRef<TypeArguments>> CreateTypeArguments(const Block<const Member>& args)
		"FinalizeTypeArguments@3b3c32728e99d1a5\0" // ResultMem FinalizeTypeArguments(TypeArguments& args)
		"PrivateHandleUnreferencedType@852138fc3d484eb1\0" // void PrivateHandleUnreferencedType(DataTypeImpl* type)
		"PrivateGetPrimaryDataTypeType@a6c0b400d8ac1aac\0" // const DataType& PrivateGetPrimaryDataTypeType()
		"AddLeakingInstantiatedType@852138fc3d484eb1\0" // void AddLeakingInstantiatedType(DataTypeImpl* type)
		"PrivateGetNamedTupleMembers@f9866d8bdd8459e9\0" // const Block<const Member>& PrivateGetNamedTupleMembers(Binary& binary, NamedTupleMembers* mem, std::add_pointer<Int(void*)>::type constructor)
	"";
	MAXON_WARNING_PUSH
	MAXON_WARNING_DISABLE_DEPRECATED
	class DataTypeLib::Hxx2::Unresolved : public DataTypeLib
	{
	public:
		static const Unresolved* Get(const DataTypeLib* o) { return (const Unresolved*) o; }
		static Unresolved* Get(DataTypeLib* o) { return (Unresolved*) o; }
		static const DataType& GetDataTypeType() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return DataTypeLib::GetDataTypeType(); return maxon::PrivateIncompleteNullReturnValue<const DataType&>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		static const DataType& GetVoidType() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return DataTypeLib::GetVoidType(); return maxon::PrivateIncompleteNullReturnValue<const DataType&>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		static const DataType& GetNullptrType() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return DataTypeLib::GetNullptrType(); return maxon::PrivateIncompleteNullReturnValue<const DataType&>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		static const DataType& GetGenericType() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return DataTypeLib::GetGenericType(); return maxon::PrivateIncompleteNullReturnValue<const DataType&>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		static const DataType& GetGenericArithmeticType() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return DataTypeLib::GetGenericArithmeticType(); return maxon::PrivateIncompleteNullReturnValue<const DataType&>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		static const DataType& GetParametricTypeType() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return DataTypeLib::GetParametricTypeType(); return maxon::PrivateIncompleteNullReturnValue<const DataType&>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		static const DataType& GetComponentDescriptorType() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return DataTypeLib::GetComponentDescriptorType(); return maxon::PrivateIncompleteNullReturnValue<const DataType&>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		static const DataType& GetEllipsisType() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return DataTypeLib::GetEllipsisType(); return maxon::PrivateIncompleteNullReturnValue<const DataType&>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		static const DataType& GetInvalidType() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return DataTypeLib::GetInvalidType(); return maxon::PrivateIncompleteNullReturnValue<const DataType&>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		static Result<DataType> Substitute(const DataType& orig, const Delegate<Result<DataType>(const DataType&)>& replace) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return DataTypeLib::Substitute(orig, replace); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static Result<DataType> GetRuntimeDataType(const DataType& orig) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return DataTypeLib::GetRuntimeDataType(orig); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static const Block<const Int>& GetTupleMemberOffsets(const TupleDataType& type) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return DataTypeLib::GetTupleMemberOffsets(type); return maxon::PrivateIncompleteNullReturnValue<const Block<const Int>&>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		static Result<DelegateDataType> GetDelegateType(const DataType& returnType, const Block<const DataType>& paramTypes, reflection::DelegateFunctionPointer function, void* handlerStub) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return DataTypeLib::GetDelegateType(returnType, paramTypes, std::forward<reflection::DelegateFunctionPointer>(function), handlerStub); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static Result<DelegateDataType> GetDelegateType(const Result<DataType>& returnType, const Block<const Result<DataType>>& paramTypes, reflection::DelegateFunctionPointer function, void* handlerStub) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return DataTypeLib::GetDelegateType(returnType, paramTypes, std::forward<reflection::DelegateFunctionPointer>(function), handlerStub); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static Result<void> InvokeDelegate(const DelegateDataType& delegateType, const DelegateBase& delegate, void* result, const Block<reflection::Argument>& arguments) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return DataTypeLib::InvokeDelegate(delegateType, delegate, result, arguments); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static Result<DelegateBase> CreateDelegate(const DelegateDataType& delegateType, reflection::DelegateHandler&& handler) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return DataTypeLib::CreateDelegate(delegateType, std::forward<reflection::DelegateHandler>(handler)); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static const DataType& GetDelegateReturnType(const DelegateDataType& delegateType) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return DataTypeLib::GetDelegateReturnType(delegateType); return maxon::PrivateIncompleteNullReturnValue<const DataType&>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		static const Block<const DataType>& GetDelegateParameterTypes(const DelegateDataType& delegateType) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return DataTypeLib::GetDelegateParameterTypes(delegateType); return maxon::PrivateIncompleteNullReturnValue<const Block<const DataType>&>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		static Result<EnumDataType> GetEnumType(const DataType& underlyingType, const Block<const Tuple<Id, Data>>& enumerators) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return DataTypeLib::GetEnumType(underlyingType, enumerators); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static const Block<const Tuple<Id, Data>>& GetEnumerators(const DataType& enumType) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return DataTypeLib::GetEnumerators(enumType); return maxon::PrivateIncompleteNullReturnValue<const Block<const Tuple<Id, Data>>&>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		static Result<void> RegisterEnumType(DataTypeImpl& type, const Id& typeId, Int size, Bool isSigned, Bool flags, const UInt64* enumValues, const Char* enumValueNames) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return DataTypeLib::RegisterEnumType(type, typeId, size, isSigned, flags, enumValues, enumValueNames); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static Result<DataType> GetDataTypeOfInterfaces(const Block<const InterfaceReference* const>& interfaces) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return DataTypeLib::GetDataTypeOfInterfaces(interfaces); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static Result<DataType> GetReferenceType(const DataType& type, EntityBase::FLAGS refFlags) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return DataTypeLib::GetReferenceType(type, refFlags); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static Result<Tuple<DataType, const Char*>> ParseDataType(const Char* str) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return DataTypeLib::ParseDataType(str); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static Result<Tuple<Member, const Char*>> ParseMember(const Char* str) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return DataTypeLib::ParseMember(str); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static Result<Tuple<Int64, const Char*>> ParseInt(const Char* str) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return DataTypeLib::ParseInt(str); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static Result<DataType> GetDataType(const Id& typeId) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return DataTypeLib::GetDataType(typeId); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static const Id& GetNumberedId(Int number) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return DataTypeLib::GetNumberedId(number); return maxon::PrivateIncompleteNullReturnValue<const Id&>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		static Result<const MemberMap*> GetMemberMap(Block<const Int> block) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return DataTypeLib::GetMemberMap(std::forward<Block<const Int>>(block)); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static Result<const MemberMap*> GetIdentityMemberMap(Int length) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return DataTypeLib::GetIdentityMemberMap(length); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static Result<const MemberMap*> ConcatMemberMap(const MemberMap* first, const MemberMap* second) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return DataTypeLib::ConcatMemberMap(first, second); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static Result<const MemberMap*> GetMemberMap(const DataTypeImpl* containerType, const DataTypeImpl* runtimeType) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return DataTypeLib::GetMemberMap(containerType, runtimeType); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static ConstDataPtr GetConstant(const DataType& type, Int value) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return DataTypeLib::GetConstant(type, value); return maxon::PrivateIncompleteNullReturnValue<ConstDataPtr>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		static Result<DataType> GetDataTypeForData(const DataType& valueType) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return DataTypeLib::GetDataTypeForData(valueType); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static Result<void> ConvertToData(Data& result, const DataType& dataType, const DataType& valueType, const Generic& value) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return DataTypeLib::ConvertToData(result, dataType, valueType, value); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static Result<void> MoveFromData(const DataType& valueType, Generic& value, Bool createDefaultPointees, Data& data, BaseArray<Data>& storage) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return DataTypeLib::MoveFromData(valueType, value, createDefaultPointees, data, storage); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static Bool PrivateIsBaseOfOrSame(const DataTypeImpl* type, const DataTypeImpl* other, DataType::BASE_OF_MODE mode) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return DataTypeLib::PrivateIsBaseOfOrSame(type, other, mode); return maxon::PrivateLogNullptrError(false);}
		static Result<StrongRef<TypeArguments>> CreateTypeArguments(Int cnt) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return DataTypeLib::CreateTypeArguments(cnt); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static Result<StrongRef<TypeArguments>> CreateTypeArguments(const Block<const Member>& args) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return DataTypeLib::CreateTypeArguments(args); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static ResultMem FinalizeTypeArguments(TypeArguments& args) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return DataTypeLib::FinalizeTypeArguments(args); return maxon::PrivateIncompleteNullReturnValue<ResultMem>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		static void PrivateHandleUnreferencedType(DataTypeImpl* type) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return DataTypeLib::PrivateHandleUnreferencedType(type); return maxon::PrivateLogNullptrError();}
		static const DataType& PrivateGetPrimaryDataTypeType() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return DataTypeLib::PrivateGetPrimaryDataTypeType(); return maxon::PrivateIncompleteNullReturnValue<const DataType&>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		static void AddLeakingInstantiatedType(DataTypeImpl* type) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return DataTypeLib::AddLeakingInstantiatedType(type); return maxon::PrivateLogNullptrError();}
		static const Block<const Member>& PrivateGetNamedTupleMembers(Binary& binary, NamedTupleMembers* mem, std::add_pointer<Int(void*)>::type constructor) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return DataTypeLib::PrivateGetNamedTupleMembers(binary, mem, std::forward<std::add_pointer<Int(void*)>::type>(constructor)); return maxon::PrivateIncompleteNullReturnValue<const Block<const Member>&>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
	};
	MAXON_WARNING_POP
#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
	const maxon::NULL_RETURN_TYPE DataTypeLib::MTable::_returnTypes[] = 
	{
		maxon::details::NullReturnType<const DataType&>::value,
		maxon::details::NullReturnType<const DataType&>::value,
		maxon::details::NullReturnType<const DataType&>::value,
		maxon::details::NullReturnType<const DataType&>::value,
		maxon::details::NullReturnType<const DataType&>::value,
		maxon::details::NullReturnType<const DataType&>::value,
		maxon::details::NullReturnType<const DataType&>::value,
		maxon::details::NullReturnType<const DataType&>::value,
		maxon::details::NullReturnType<const DataType&>::value,
		maxon::details::NullReturnType<Result<DataType>>::value,
		maxon::details::NullReturnType<Result<DataType>>::value,
		maxon::details::NullReturnType<const Block<const Int>&>::value,
		maxon::details::NullReturnType<Result<DelegateDataType>>::value,
		maxon::details::NullReturnType<Result<DelegateDataType>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<DelegateBase>>::value,
		maxon::details::NullReturnType<const DataType&>::value,
		maxon::details::NullReturnType<const Block<const DataType>&>::value,
		maxon::details::NullReturnType<Result<EnumDataType>>::value,
		maxon::details::NullReturnType<const Block<const Tuple<Id, Data>>&>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<DataType>>::value,
		maxon::details::NullReturnType<Result<DataType>>::value,
		maxon::details::NullReturnType<Result<Tuple<DataType, const Char*>>>::value,
		maxon::details::NullReturnType<Result<Tuple<Member, const Char*>>>::value,
		maxon::details::NullReturnType<Result<Tuple<Int64, const Char*>>>::value,
		maxon::details::NullReturnType<Result<DataType>>::value,
		maxon::details::NullReturnType<const Id&>::value,
		maxon::details::NullReturnType<Result<const MemberMap*>>::value,
		maxon::details::NullReturnType<Result<const MemberMap*>>::value,
		maxon::details::NullReturnType<Result<const MemberMap*>>::value,
		maxon::details::NullReturnType<Result<const MemberMap*>>::value,
		maxon::details::NullReturnType<ConstDataPtr>::value,
		maxon::details::NullReturnType<Result<DataType>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Bool>::value,
		maxon::details::NullReturnType<Result<StrongRef<TypeArguments>>>::value,
		maxon::details::NullReturnType<Result<StrongRef<TypeArguments>>>::value,
		maxon::details::NullReturnType<ResultMem>::value,
		maxon::details::NullReturnType<void>::value,
		maxon::details::NullReturnType<const DataType&>::value,
		maxon::details::NullReturnType<void>::value,
		maxon::details::NullReturnType<const Block<const Member>&>::value,
		maxon::NULL_RETURN_TYPE::OTHER
	};
#endif
	maxon::Bool DataTypeLib::MTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl)
	{
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<const DataType&>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_DataTypeLib_GetDataTypeType = &Hxx2::Wrapper<Hxx2::Unresolved>::_DataTypeLib_GetDataTypeType;
		#else
		tbl->_DataTypeLib_GetDataTypeType = &Hxx2::Wrapper<Hxx2::Unresolved>::_DataTypeLib_GetDataTypeType;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<const DataType&>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_DataTypeLib_GetVoidType = &Hxx2::Wrapper<Hxx2::Unresolved>::_DataTypeLib_GetVoidType;
		#else
		tbl->_DataTypeLib_GetVoidType = &Hxx2::Wrapper<Hxx2::Unresolved>::_DataTypeLib_GetVoidType;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<const DataType&>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_DataTypeLib_GetNullptrType = &Hxx2::Wrapper<Hxx2::Unresolved>::_DataTypeLib_GetNullptrType;
		#else
		tbl->_DataTypeLib_GetNullptrType = &Hxx2::Wrapper<Hxx2::Unresolved>::_DataTypeLib_GetNullptrType;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<const DataType&>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_DataTypeLib_GetGenericType = &Hxx2::Wrapper<Hxx2::Unresolved>::_DataTypeLib_GetGenericType;
		#else
		tbl->_DataTypeLib_GetGenericType = &Hxx2::Wrapper<Hxx2::Unresolved>::_DataTypeLib_GetGenericType;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<const DataType&>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_DataTypeLib_GetGenericArithmeticType = &Hxx2::Wrapper<Hxx2::Unresolved>::_DataTypeLib_GetGenericArithmeticType;
		#else
		tbl->_DataTypeLib_GetGenericArithmeticType = &Hxx2::Wrapper<Hxx2::Unresolved>::_DataTypeLib_GetGenericArithmeticType;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<const DataType&>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_DataTypeLib_GetParametricTypeType = &Hxx2::Wrapper<Hxx2::Unresolved>::_DataTypeLib_GetParametricTypeType;
		#else
		tbl->_DataTypeLib_GetParametricTypeType = &Hxx2::Wrapper<Hxx2::Unresolved>::_DataTypeLib_GetParametricTypeType;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<const DataType&>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_DataTypeLib_GetComponentDescriptorType = &Hxx2::Wrapper<Hxx2::Unresolved>::_DataTypeLib_GetComponentDescriptorType;
		#else
		tbl->_DataTypeLib_GetComponentDescriptorType = &Hxx2::Wrapper<Hxx2::Unresolved>::_DataTypeLib_GetComponentDescriptorType;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<const DataType&>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_DataTypeLib_GetEllipsisType = &Hxx2::Wrapper<Hxx2::Unresolved>::_DataTypeLib_GetEllipsisType;
		#else
		tbl->_DataTypeLib_GetEllipsisType = &Hxx2::Wrapper<Hxx2::Unresolved>::_DataTypeLib_GetEllipsisType;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<const DataType&>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_DataTypeLib_GetInvalidType = &Hxx2::Wrapper<Hxx2::Unresolved>::_DataTypeLib_GetInvalidType;
		#else
		tbl->_DataTypeLib_GetInvalidType = &Hxx2::Wrapper<Hxx2::Unresolved>::_DataTypeLib_GetInvalidType;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<DataType>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_DataTypeLib_Substitute = &Hxx2::Wrapper<Hxx2::Unresolved>::_DataTypeLib_Substitute;
		#else
		tbl->_DataTypeLib_Substitute = &Hxx2::Wrapper<Hxx2::Unresolved>::_DataTypeLib_Substitute;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<DataType>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_DataTypeLib_GetRuntimeDataType = &Hxx2::Wrapper<Hxx2::Unresolved>::_DataTypeLib_GetRuntimeDataType;
		#else
		tbl->_DataTypeLib_GetRuntimeDataType = &Hxx2::Wrapper<Hxx2::Unresolved>::_DataTypeLib_GetRuntimeDataType;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<const Block<const Int>&>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_DataTypeLib_GetTupleMemberOffsets = &Hxx2::Wrapper<Hxx2::Unresolved>::_DataTypeLib_GetTupleMemberOffsets;
		#else
		tbl->_DataTypeLib_GetTupleMemberOffsets = &Hxx2::Wrapper<Hxx2::Unresolved>::_DataTypeLib_GetTupleMemberOffsets;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<DelegateDataType>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_DataTypeLib_GetDelegateType = &Hxx2::Wrapper<Hxx2::Unresolved>::_DataTypeLib_GetDelegateType;
		#else
		tbl->_DataTypeLib_GetDelegateType = &Hxx2::Wrapper<Hxx2::Unresolved>::_DataTypeLib_GetDelegateType;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<DelegateDataType>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_DataTypeLib_GetDelegateType_1 = &Hxx2::Wrapper<Hxx2::Unresolved>::_DataTypeLib_GetDelegateType_1;
		#else
		tbl->_DataTypeLib_GetDelegateType_1 = &Hxx2::Wrapper<Hxx2::Unresolved>::_DataTypeLib_GetDelegateType_1;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_DataTypeLib_InvokeDelegate = &Hxx2::Wrapper<Hxx2::Unresolved>::_DataTypeLib_InvokeDelegate;
		#else
		tbl->_DataTypeLib_InvokeDelegate = &Hxx2::Wrapper<Hxx2::Unresolved>::_DataTypeLib_InvokeDelegate;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<DelegateBase>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_DataTypeLib_CreateDelegate = &Hxx2::Wrapper<Hxx2::Unresolved>::_DataTypeLib_CreateDelegate;
		#else
		tbl->_DataTypeLib_CreateDelegate = &Hxx2::Wrapper<Hxx2::Unresolved>::_DataTypeLib_CreateDelegate;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<const DataType&>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_DataTypeLib_GetDelegateReturnType = &Hxx2::Wrapper<Hxx2::Unresolved>::_DataTypeLib_GetDelegateReturnType;
		#else
		tbl->_DataTypeLib_GetDelegateReturnType = &Hxx2::Wrapper<Hxx2::Unresolved>::_DataTypeLib_GetDelegateReturnType;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<const Block<const DataType>&>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_DataTypeLib_GetDelegateParameterTypes = &Hxx2::Wrapper<Hxx2::Unresolved>::_DataTypeLib_GetDelegateParameterTypes;
		#else
		tbl->_DataTypeLib_GetDelegateParameterTypes = &Hxx2::Wrapper<Hxx2::Unresolved>::_DataTypeLib_GetDelegateParameterTypes;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<EnumDataType>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_DataTypeLib_GetEnumType = &Hxx2::Wrapper<Hxx2::Unresolved>::_DataTypeLib_GetEnumType;
		#else
		tbl->_DataTypeLib_GetEnumType = &Hxx2::Wrapper<Hxx2::Unresolved>::_DataTypeLib_GetEnumType;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<const Block<const Tuple<Id, Data>>&>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_DataTypeLib_GetEnumerators = &Hxx2::Wrapper<Hxx2::Unresolved>::_DataTypeLib_GetEnumerators;
		#else
		tbl->_DataTypeLib_GetEnumerators = &Hxx2::Wrapper<Hxx2::Unresolved>::_DataTypeLib_GetEnumerators;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_DataTypeLib_RegisterEnumType = &Hxx2::Wrapper<Hxx2::Unresolved>::_DataTypeLib_RegisterEnumType;
		#else
		tbl->_DataTypeLib_RegisterEnumType = &Hxx2::Wrapper<Hxx2::Unresolved>::_DataTypeLib_RegisterEnumType;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<DataType>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_DataTypeLib_GetDataTypeOfInterfaces = &Hxx2::Wrapper<Hxx2::Unresolved>::_DataTypeLib_GetDataTypeOfInterfaces;
		#else
		tbl->_DataTypeLib_GetDataTypeOfInterfaces = &Hxx2::Wrapper<Hxx2::Unresolved>::_DataTypeLib_GetDataTypeOfInterfaces;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<DataType>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_DataTypeLib_GetReferenceType = &Hxx2::Wrapper<Hxx2::Unresolved>::_DataTypeLib_GetReferenceType;
		#else
		tbl->_DataTypeLib_GetReferenceType = &Hxx2::Wrapper<Hxx2::Unresolved>::_DataTypeLib_GetReferenceType;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<Tuple<DataType, const Char*>>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_DataTypeLib_ParseDataType = &Hxx2::Wrapper<Hxx2::Unresolved>::_DataTypeLib_ParseDataType;
		#else
		tbl->_DataTypeLib_ParseDataType = &Hxx2::Wrapper<Hxx2::Unresolved>::_DataTypeLib_ParseDataType;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<Tuple<Member, const Char*>>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_DataTypeLib_ParseMember = &Hxx2::Wrapper<Hxx2::Unresolved>::_DataTypeLib_ParseMember;
		#else
		tbl->_DataTypeLib_ParseMember = &Hxx2::Wrapper<Hxx2::Unresolved>::_DataTypeLib_ParseMember;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<Tuple<Int64, const Char*>>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_DataTypeLib_ParseInt = &Hxx2::Wrapper<Hxx2::Unresolved>::_DataTypeLib_ParseInt;
		#else
		tbl->_DataTypeLib_ParseInt = &Hxx2::Wrapper<Hxx2::Unresolved>::_DataTypeLib_ParseInt;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<DataType>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_DataTypeLib_GetDataType = &Hxx2::Wrapper<Hxx2::Unresolved>::_DataTypeLib_GetDataType;
		#else
		tbl->_DataTypeLib_GetDataType = &Hxx2::Wrapper<Hxx2::Unresolved>::_DataTypeLib_GetDataType;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<const Id&>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_DataTypeLib_GetNumberedId = &Hxx2::Wrapper<Hxx2::Unresolved>::_DataTypeLib_GetNumberedId;
		#else
		tbl->_DataTypeLib_GetNumberedId = &Hxx2::Wrapper<Hxx2::Unresolved>::_DataTypeLib_GetNumberedId;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<const MemberMap*>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_DataTypeLib_GetMemberMap = &Hxx2::Wrapper<Hxx2::Unresolved>::_DataTypeLib_GetMemberMap;
		#else
		tbl->_DataTypeLib_GetMemberMap = &Hxx2::Wrapper<Hxx2::Unresolved>::_DataTypeLib_GetMemberMap;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<const MemberMap*>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_DataTypeLib_GetIdentityMemberMap = &Hxx2::Wrapper<Hxx2::Unresolved>::_DataTypeLib_GetIdentityMemberMap;
		#else
		tbl->_DataTypeLib_GetIdentityMemberMap = &Hxx2::Wrapper<Hxx2::Unresolved>::_DataTypeLib_GetIdentityMemberMap;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<const MemberMap*>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_DataTypeLib_ConcatMemberMap = &Hxx2::Wrapper<Hxx2::Unresolved>::_DataTypeLib_ConcatMemberMap;
		#else
		tbl->_DataTypeLib_ConcatMemberMap = &Hxx2::Wrapper<Hxx2::Unresolved>::_DataTypeLib_ConcatMemberMap;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<const MemberMap*>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_DataTypeLib_GetMemberMap_1 = &Hxx2::Wrapper<Hxx2::Unresolved>::_DataTypeLib_GetMemberMap_1;
		#else
		tbl->_DataTypeLib_GetMemberMap_1 = &Hxx2::Wrapper<Hxx2::Unresolved>::_DataTypeLib_GetMemberMap_1;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<ConstDataPtr>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_DataTypeLib_GetConstant = &Hxx2::Wrapper<Hxx2::Unresolved>::_DataTypeLib_GetConstant;
		#else
		tbl->_DataTypeLib_GetConstant = &Hxx2::Wrapper<Hxx2::Unresolved>::_DataTypeLib_GetConstant;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<DataType>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_DataTypeLib_GetDataTypeForData = &Hxx2::Wrapper<Hxx2::Unresolved>::_DataTypeLib_GetDataTypeForData;
		#else
		tbl->_DataTypeLib_GetDataTypeForData = &Hxx2::Wrapper<Hxx2::Unresolved>::_DataTypeLib_GetDataTypeForData;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_DataTypeLib_ConvertToData = &Hxx2::Wrapper<Hxx2::Unresolved>::_DataTypeLib_ConvertToData;
		#else
		tbl->_DataTypeLib_ConvertToData = &Hxx2::Wrapper<Hxx2::Unresolved>::_DataTypeLib_ConvertToData;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_DataTypeLib_MoveFromData = &Hxx2::Wrapper<Hxx2::Unresolved>::_DataTypeLib_MoveFromData;
		#else
		tbl->_DataTypeLib_MoveFromData = &Hxx2::Wrapper<Hxx2::Unresolved>::_DataTypeLib_MoveFromData;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_DataTypeLib_PrivateIsBaseOfOrSame = &Hxx2::Wrapper<Hxx2::Unresolved>::_DataTypeLib_PrivateIsBaseOfOrSame;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<StrongRef<TypeArguments>>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_DataTypeLib_CreateTypeArguments = &Hxx2::Wrapper<Hxx2::Unresolved>::_DataTypeLib_CreateTypeArguments;
		#else
		tbl->_DataTypeLib_CreateTypeArguments = &Hxx2::Wrapper<Hxx2::Unresolved>::_DataTypeLib_CreateTypeArguments;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<StrongRef<TypeArguments>>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_DataTypeLib_CreateTypeArguments_1 = &Hxx2::Wrapper<Hxx2::Unresolved>::_DataTypeLib_CreateTypeArguments_1;
		#else
		tbl->_DataTypeLib_CreateTypeArguments_1 = &Hxx2::Wrapper<Hxx2::Unresolved>::_DataTypeLib_CreateTypeArguments_1;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<ResultMem>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_DataTypeLib_FinalizeTypeArguments = &Hxx2::Wrapper<Hxx2::Unresolved>::_DataTypeLib_FinalizeTypeArguments;
		#else
		tbl->_DataTypeLib_FinalizeTypeArguments = &Hxx2::Wrapper<Hxx2::Unresolved>::_DataTypeLib_FinalizeTypeArguments;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_DataTypeLib_PrivateHandleUnreferencedType = &Hxx2::Wrapper<Hxx2::Unresolved>::_DataTypeLib_PrivateHandleUnreferencedType;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<const DataType&>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_DataTypeLib_PrivateGetPrimaryDataTypeType = &Hxx2::Wrapper<Hxx2::Unresolved>::_DataTypeLib_PrivateGetPrimaryDataTypeType;
		#else
		tbl->_DataTypeLib_PrivateGetPrimaryDataTypeType = &Hxx2::Wrapper<Hxx2::Unresolved>::_DataTypeLib_PrivateGetPrimaryDataTypeType;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_DataTypeLib_AddLeakingInstantiatedType = &Hxx2::Wrapper<Hxx2::Unresolved>::_DataTypeLib_AddLeakingInstantiatedType;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<const Block<const Member>&>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_DataTypeLib_PrivateGetNamedTupleMembers = &Hxx2::Wrapper<Hxx2::Unresolved>::_DataTypeLib_PrivateGetNamedTupleMembers;
		#else
		tbl->_DataTypeLib_PrivateGetNamedTupleMembers = &Hxx2::Wrapper<Hxx2::Unresolved>::_DataTypeLib_PrivateGetNamedTupleMembers;
		#endif
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_interface, (maxon::Char*) tbl, _returnTypes, SIZEOF(MTable) / SIZEOF(void*));
	#else
		return true;
	#endif
	}
	MAXON_INTERFACE_REGISTER(DataTypeLib, "net.maxon.interface.datatypelib", nullptr);
	template <typename DUMMY> maxon::Int DataTypeLib::PrivateInstantiateNullValueHelper()
	{
		return 0
		| maxon::details::InstantiateNullReturnValue<ConstDataPtr>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateNullReturnValue<ResultMem>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateNullReturnValue<const Block<const DataType>&>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateNullReturnValue<const Block<const Int>&>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateNullReturnValue<const Block<const Member>&>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateNullReturnValue<const Block<const Tuple<Id, Data>>&>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateNullReturnValue<const DataType&>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateNullReturnValue<const Id&>(OVERLOAD_MAX_RANK)
		;
	}
}
#endif
static maxon::details::ForceEvaluation s_forceEval_datatypelib(0
	| maxon::DataTypeLib::PrivateInstantiateNullValueHelper<maxon::Int>()
);
