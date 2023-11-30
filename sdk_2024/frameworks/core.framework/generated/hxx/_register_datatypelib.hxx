#if 1
namespace maxon
{
#ifndef _HAS_CPP20_COMPARISONS
#endif
	namespace enum413
	{
		enum class INNERMOST_MEMBER : Int32
		{
		} ;
		static const maxon::EnumInfo INNERMOST_MEMBER_info{"INNERMOST_MEMBER", SIZEOF(INNERMOST_MEMBER), false, "", nullptr, 0};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_INNERMOST_MEMBER413(){ return enum413::INNERMOST_MEMBER_info; }
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
		"GetMemberOrder@44a2c4eaa9105a2a\0" // const Block<const Int>& GetMemberOrder(const DataType& bundleOrContainerType)
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
		"PrivateGetNamedTupleMembers@a5e0aa42cc90842c\0" // void PrivateGetNamedTupleMembers(Binary& binary, NamedTupleMembers* mem, std::add_pointer<Int(void*)>::type constructor)
	"";
	MAXON_WARNING_PUSH
	MAXON_WARNING_DISABLE_DEPRECATED
	class DataTypeLib::Hxx2::Unresolved : public DataTypeLib
	{
	public:
		static const Unresolved* Get(const DataTypeLib* o) { return (const Unresolved*) o; }
		static Unresolved* Get(DataTypeLib* o) { return (Unresolved*) o; }
		static const DataType& GetDataTypeType() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return DataTypeLib::GetDataTypeType(); return HXXRET3(UNRESOLVED, const DataType&);}
		static const DataType& GetVoidType() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return DataTypeLib::GetVoidType(); return HXXRET3(UNRESOLVED, const DataType&);}
		static const DataType& GetNullptrType() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return DataTypeLib::GetNullptrType(); return HXXRET3(UNRESOLVED, const DataType&);}
		static const DataType& GetGenericType() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return DataTypeLib::GetGenericType(); return HXXRET3(UNRESOLVED, const DataType&);}
		static const DataType& GetGenericArithmeticType() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return DataTypeLib::GetGenericArithmeticType(); return HXXRET3(UNRESOLVED, const DataType&);}
		static const DataType& GetParametricTypeType() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return DataTypeLib::GetParametricTypeType(); return HXXRET3(UNRESOLVED, const DataType&);}
		static const DataType& GetComponentDescriptorType() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return DataTypeLib::GetComponentDescriptorType(); return HXXRET3(UNRESOLVED, const DataType&);}
		static const DataType& GetEllipsisType() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return DataTypeLib::GetEllipsisType(); return HXXRET3(UNRESOLVED, const DataType&);}
		static const DataType& GetInvalidType() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return DataTypeLib::GetInvalidType(); return HXXRET3(UNRESOLVED, const DataType&);}
		static Result<DataType> Substitute(const DataType& orig, const Delegate<Result<DataType>(const DataType&)>& replace) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return DataTypeLib::Substitute(orig, replace); return HXXRET1(UNRESOLVED);}
		static Result<DataType> GetRuntimeDataType(const DataType& orig) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return DataTypeLib::GetRuntimeDataType(orig); return HXXRET1(UNRESOLVED);}
		static const Block<const Int>& GetTupleMemberOffsets(const TupleDataType& type) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return DataTypeLib::GetTupleMemberOffsets(type); return HXXRET3(UNRESOLVED, const Block<const Int>&);}
		static const Block<const Int>& GetMemberOrder(const DataType& bundleOrContainerType) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return DataTypeLib::GetMemberOrder(bundleOrContainerType); return HXXRET3(UNRESOLVED, const Block<const Int>&);}
		static Result<DelegateDataType> GetDelegateType(const DataType& returnType, const Block<const DataType>& paramTypes, reflection::DelegateFunctionPointer function, void* handlerStub) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return DataTypeLib::GetDelegateType(returnType, paramTypes, std::forward<reflection::DelegateFunctionPointer>(function), handlerStub); return HXXRET1(UNRESOLVED);}
		static Result<DelegateDataType> GetDelegateType(const Result<DataType>& returnType, const Block<const Result<DataType>>& paramTypes, reflection::DelegateFunctionPointer function, void* handlerStub) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return DataTypeLib::GetDelegateType(returnType, paramTypes, std::forward<reflection::DelegateFunctionPointer>(function), handlerStub); return HXXRET1(UNRESOLVED);}
		static Result<void> InvokeDelegate(const DelegateDataType& delegateType, const DelegateBase& delegate, void* result, const Block<reflection::Argument>& arguments) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return DataTypeLib::InvokeDelegate(delegateType, delegate, result, arguments); return HXXRET1(UNRESOLVED);}
		static Result<DelegateBase> CreateDelegate(const DelegateDataType& delegateType, reflection::DelegateHandler&& handler) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return DataTypeLib::CreateDelegate(delegateType, std::forward<reflection::DelegateHandler>(handler)); return HXXRET1(UNRESOLVED);}
		static const DataType& GetDelegateReturnType(const DelegateDataType& delegateType) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return DataTypeLib::GetDelegateReturnType(delegateType); return HXXRET3(UNRESOLVED, const DataType&);}
		static const Block<const DataType>& GetDelegateParameterTypes(const DelegateDataType& delegateType) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return DataTypeLib::GetDelegateParameterTypes(delegateType); return HXXRET3(UNRESOLVED, const Block<const DataType>&);}
		static Result<EnumDataType> GetEnumType(const DataType& underlyingType, const Block<const Tuple<Id, Data>>& enumerators) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return DataTypeLib::GetEnumType(underlyingType, enumerators); return HXXRET1(UNRESOLVED);}
		static const Block<const Tuple<Id, Data>>& GetEnumerators(const DataType& enumType) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return DataTypeLib::GetEnumerators(enumType); return HXXRET3(UNRESOLVED, const Block<const Tuple<Id, Data>>&);}
		static Result<void> RegisterEnumType(DataTypeImpl& type, const Id& typeId, Int size, Bool isSigned, Bool flags, const UInt64* enumValues, const Char* enumValueNames) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return DataTypeLib::RegisterEnumType(type, typeId, size, isSigned, flags, enumValues, enumValueNames); return HXXRET1(UNRESOLVED);}
		static Result<DataType> GetDataTypeOfInterfaces(const Block<const InterfaceReference* const>& interfaces) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return DataTypeLib::GetDataTypeOfInterfaces(interfaces); return HXXRET1(UNRESOLVED);}
		static Result<DataType> GetReferenceType(const DataType& type, EntityBase::FLAGS refFlags) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return DataTypeLib::GetReferenceType(type, refFlags); return HXXRET1(UNRESOLVED);}
		static Result<Tuple<DataType, const Char*>> ParseDataType(const Char* str) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return DataTypeLib::ParseDataType(str); return HXXRET1(UNRESOLVED);}
		static Result<Tuple<Member, const Char*>> ParseMember(const Char* str) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return DataTypeLib::ParseMember(str); return HXXRET1(UNRESOLVED);}
		static Result<Tuple<Int64, const Char*>> ParseInt(const Char* str) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return DataTypeLib::ParseInt(str); return HXXRET1(UNRESOLVED);}
		static Result<DataType> GetDataType(const Id& typeId) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return DataTypeLib::GetDataType(typeId); return HXXRET1(UNRESOLVED);}
		static const Id& GetNumberedId(Int number) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return DataTypeLib::GetNumberedId(number); return HXXRET3(UNRESOLVED, const Id&);}
		static Result<const MemberMap*> GetMemberMap(Block<const Int> block) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return DataTypeLib::GetMemberMap(std::forward<Block<const Int>>(block)); return HXXRET1(UNRESOLVED);}
		static Result<const MemberMap*> GetIdentityMemberMap(Int length) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return DataTypeLib::GetIdentityMemberMap(length); return HXXRET1(UNRESOLVED);}
		static Result<const MemberMap*> ConcatMemberMap(const MemberMap* first, const MemberMap* second) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return DataTypeLib::ConcatMemberMap(first, second); return HXXRET1(UNRESOLVED);}
		static Result<const MemberMap*> GetMemberMap(const DataTypeImpl* containerType, const DataTypeImpl* runtimeType) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return DataTypeLib::GetMemberMap(containerType, runtimeType); return HXXRET1(UNRESOLVED);}
		static Result<DataType> GetDataTypeForData(const DataType& valueType) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return DataTypeLib::GetDataTypeForData(valueType); return HXXRET1(UNRESOLVED);}
		static Result<void> ConvertToData(Data& result, const DataType& dataType, const DataType& valueType, const Generic& value) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return DataTypeLib::ConvertToData(result, dataType, valueType, value); return HXXRET1(UNRESOLVED);}
		static Result<void> MoveFromData(const DataType& valueType, Generic& value, Bool createDefaultPointees, Data& data, BaseArray<Data>& storage) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return DataTypeLib::MoveFromData(valueType, value, createDefaultPointees, data, storage); return HXXRET1(UNRESOLVED);}
		static Bool PrivateIsBaseOfOrSame(const DataTypeImpl* type, const DataTypeImpl* other, DataType::BASE_OF_MODE mode) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return DataTypeLib::PrivateIsBaseOfOrSame(type, other, mode); return maxon::PrivateLogNullptrError(false);}
		static Result<StrongRef<TypeArguments>> CreateTypeArguments(Int cnt) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return DataTypeLib::CreateTypeArguments(cnt); return HXXRET1(UNRESOLVED);}
		static Result<StrongRef<TypeArguments>> CreateTypeArguments(const Block<const Member>& args) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return DataTypeLib::CreateTypeArguments(args); return HXXRET1(UNRESOLVED);}
		static ResultMem FinalizeTypeArguments(TypeArguments& args) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return DataTypeLib::FinalizeTypeArguments(args); return HXXRET3(UNRESOLVED, ResultMem);}
		static void PrivateHandleUnreferencedType(DataTypeImpl* type) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return DataTypeLib::PrivateHandleUnreferencedType(type); return maxon::PrivateLogNullptrError();}
		static const DataType& PrivateGetPrimaryDataTypeType() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return DataTypeLib::PrivateGetPrimaryDataTypeType(); return HXXRET3(UNRESOLVED, const DataType&);}
		static void AddLeakingInstantiatedType(DataTypeImpl* type) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return DataTypeLib::AddLeakingInstantiatedType(type); return maxon::PrivateLogNullptrError();}
		static void PrivateGetNamedTupleMembers(Binary& binary, NamedTupleMembers* mem, std::add_pointer<Int(void*)>::type constructor) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return DataTypeLib::PrivateGetNamedTupleMembers(binary, mem, std::forward<std::add_pointer<Int(void*)>::type>(constructor)); return maxon::PrivateLogNullptrError();}
	};
	MAXON_WARNING_POP
#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
	const maxon::UNRESOLVED_RETURN_TYPE DataTypeLib::MTable::_returnTypes[] = 
	{
		maxon::details::UnresolvedReturnType<const DataType&>::value,
		maxon::details::UnresolvedReturnType<const DataType&>::value,
		maxon::details::UnresolvedReturnType<const DataType&>::value,
		maxon::details::UnresolvedReturnType<const DataType&>::value,
		maxon::details::UnresolvedReturnType<const DataType&>::value,
		maxon::details::UnresolvedReturnType<const DataType&>::value,
		maxon::details::UnresolvedReturnType<const DataType&>::value,
		maxon::details::UnresolvedReturnType<const DataType&>::value,
		maxon::details::UnresolvedReturnType<const DataType&>::value,
		maxon::details::UnresolvedReturnType<Result<DataType>>::value,
		maxon::details::UnresolvedReturnType<Result<DataType>>::value,
		maxon::details::UnresolvedReturnType<const Block<const Int>&>::value,
		maxon::details::UnresolvedReturnType<const Block<const Int>&>::value,
		maxon::details::UnresolvedReturnType<Result<DelegateDataType>>::value,
		maxon::details::UnresolvedReturnType<Result<DelegateDataType>>::value,
		maxon::details::UnresolvedReturnType<Result<void>>::value,
		maxon::details::UnresolvedReturnType<Result<DelegateBase>>::value,
		maxon::details::UnresolvedReturnType<const DataType&>::value,
		maxon::details::UnresolvedReturnType<const Block<const DataType>&>::value,
		maxon::details::UnresolvedReturnType<Result<EnumDataType>>::value,
		maxon::details::UnresolvedReturnType<const Block<const Tuple<Id, Data>>&>::value,
		maxon::details::UnresolvedReturnType<Result<void>>::value,
		maxon::details::UnresolvedReturnType<Result<DataType>>::value,
		maxon::details::UnresolvedReturnType<Result<DataType>>::value,
		maxon::details::UnresolvedReturnType<Result<Tuple<DataType, const Char*>>>::value,
		maxon::details::UnresolvedReturnType<Result<Tuple<Member, const Char*>>>::value,
		maxon::details::UnresolvedReturnType<Result<Tuple<Int64, const Char*>>>::value,
		maxon::details::UnresolvedReturnType<Result<DataType>>::value,
		maxon::details::UnresolvedReturnType<const Id&>::value,
		maxon::details::UnresolvedReturnType<Result<const MemberMap*>>::value,
		maxon::details::UnresolvedReturnType<Result<const MemberMap*>>::value,
		maxon::details::UnresolvedReturnType<Result<const MemberMap*>>::value,
		maxon::details::UnresolvedReturnType<Result<const MemberMap*>>::value,
		maxon::details::UnresolvedReturnType<Result<DataType>>::value,
		maxon::details::UnresolvedReturnType<Result<void>>::value,
		maxon::details::UnresolvedReturnType<Result<void>>::value,
		maxon::details::UnresolvedReturnType<Bool>::value,
		maxon::details::UnresolvedReturnType<Result<StrongRef<TypeArguments>>>::value,
		maxon::details::UnresolvedReturnType<Result<StrongRef<TypeArguments>>>::value,
		maxon::details::UnresolvedReturnType<ResultMem>::value,
		maxon::details::UnresolvedReturnType<void>::value,
		maxon::details::UnresolvedReturnType<const DataType&>::value,
		maxon::details::UnresolvedReturnType<void>::value,
		maxon::details::UnresolvedReturnType<void>::value,
		maxon::UNRESOLVED_RETURN_TYPE::OTHER
	};
#endif
	maxon::Bool DataTypeLib::MTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl)
	{
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<const DataType&>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->DataTypeLib_GetDataTypeType = PRIVATE_MAXON_MF_CAST(decltype(DataTypeLib_GetDataTypeType), &Hxx2::Wrapper<Hxx2::Unresolved>::DataTypeLib_GetDataTypeType);
		#else
		tbl->DataTypeLib_GetDataTypeType = PRIVATE_MAXON_MF_CAST(decltype(DataTypeLib_GetDataTypeType), &Hxx2::Wrapper<Hxx2::Unresolved>::DataTypeLib_GetDataTypeType);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<const DataType&>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->DataTypeLib_GetVoidType = PRIVATE_MAXON_MF_CAST(decltype(DataTypeLib_GetVoidType), &Hxx2::Wrapper<Hxx2::Unresolved>::DataTypeLib_GetVoidType);
		#else
		tbl->DataTypeLib_GetVoidType = PRIVATE_MAXON_MF_CAST(decltype(DataTypeLib_GetVoidType), &Hxx2::Wrapper<Hxx2::Unresolved>::DataTypeLib_GetVoidType);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<const DataType&>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->DataTypeLib_GetNullptrType = PRIVATE_MAXON_MF_CAST(decltype(DataTypeLib_GetNullptrType), &Hxx2::Wrapper<Hxx2::Unresolved>::DataTypeLib_GetNullptrType);
		#else
		tbl->DataTypeLib_GetNullptrType = PRIVATE_MAXON_MF_CAST(decltype(DataTypeLib_GetNullptrType), &Hxx2::Wrapper<Hxx2::Unresolved>::DataTypeLib_GetNullptrType);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<const DataType&>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->DataTypeLib_GetGenericType = PRIVATE_MAXON_MF_CAST(decltype(DataTypeLib_GetGenericType), &Hxx2::Wrapper<Hxx2::Unresolved>::DataTypeLib_GetGenericType);
		#else
		tbl->DataTypeLib_GetGenericType = PRIVATE_MAXON_MF_CAST(decltype(DataTypeLib_GetGenericType), &Hxx2::Wrapper<Hxx2::Unresolved>::DataTypeLib_GetGenericType);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<const DataType&>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->DataTypeLib_GetGenericArithmeticType = PRIVATE_MAXON_MF_CAST(decltype(DataTypeLib_GetGenericArithmeticType), &Hxx2::Wrapper<Hxx2::Unresolved>::DataTypeLib_GetGenericArithmeticType);
		#else
		tbl->DataTypeLib_GetGenericArithmeticType = PRIVATE_MAXON_MF_CAST(decltype(DataTypeLib_GetGenericArithmeticType), &Hxx2::Wrapper<Hxx2::Unresolved>::DataTypeLib_GetGenericArithmeticType);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<const DataType&>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->DataTypeLib_GetParametricTypeType = PRIVATE_MAXON_MF_CAST(decltype(DataTypeLib_GetParametricTypeType), &Hxx2::Wrapper<Hxx2::Unresolved>::DataTypeLib_GetParametricTypeType);
		#else
		tbl->DataTypeLib_GetParametricTypeType = PRIVATE_MAXON_MF_CAST(decltype(DataTypeLib_GetParametricTypeType), &Hxx2::Wrapper<Hxx2::Unresolved>::DataTypeLib_GetParametricTypeType);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<const DataType&>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->DataTypeLib_GetComponentDescriptorType = PRIVATE_MAXON_MF_CAST(decltype(DataTypeLib_GetComponentDescriptorType), &Hxx2::Wrapper<Hxx2::Unresolved>::DataTypeLib_GetComponentDescriptorType);
		#else
		tbl->DataTypeLib_GetComponentDescriptorType = PRIVATE_MAXON_MF_CAST(decltype(DataTypeLib_GetComponentDescriptorType), &Hxx2::Wrapper<Hxx2::Unresolved>::DataTypeLib_GetComponentDescriptorType);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<const DataType&>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->DataTypeLib_GetEllipsisType = PRIVATE_MAXON_MF_CAST(decltype(DataTypeLib_GetEllipsisType), &Hxx2::Wrapper<Hxx2::Unresolved>::DataTypeLib_GetEllipsisType);
		#else
		tbl->DataTypeLib_GetEllipsisType = PRIVATE_MAXON_MF_CAST(decltype(DataTypeLib_GetEllipsisType), &Hxx2::Wrapper<Hxx2::Unresolved>::DataTypeLib_GetEllipsisType);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<const DataType&>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->DataTypeLib_GetInvalidType = PRIVATE_MAXON_MF_CAST(decltype(DataTypeLib_GetInvalidType), &Hxx2::Wrapper<Hxx2::Unresolved>::DataTypeLib_GetInvalidType);
		#else
		tbl->DataTypeLib_GetInvalidType = PRIVATE_MAXON_MF_CAST(decltype(DataTypeLib_GetInvalidType), &Hxx2::Wrapper<Hxx2::Unresolved>::DataTypeLib_GetInvalidType);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<DataType>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->DataTypeLib_Substitute = PRIVATE_MAXON_MF_CAST(decltype(DataTypeLib_Substitute), &Hxx2::Wrapper<Hxx2::Unresolved>::DataTypeLib_Substitute);
		#else
		tbl->DataTypeLib_Substitute = PRIVATE_MAXON_MF_CAST(decltype(DataTypeLib_Substitute), &Hxx2::Wrapper<Hxx2::Unresolved>::DataTypeLib_Substitute);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<DataType>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->DataTypeLib_GetRuntimeDataType = PRIVATE_MAXON_MF_CAST(decltype(DataTypeLib_GetRuntimeDataType), &Hxx2::Wrapper<Hxx2::Unresolved>::DataTypeLib_GetRuntimeDataType);
		#else
		tbl->DataTypeLib_GetRuntimeDataType = PRIVATE_MAXON_MF_CAST(decltype(DataTypeLib_GetRuntimeDataType), &Hxx2::Wrapper<Hxx2::Unresolved>::DataTypeLib_GetRuntimeDataType);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<const Block<const Int>&>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->DataTypeLib_GetTupleMemberOffsets = PRIVATE_MAXON_MF_CAST(decltype(DataTypeLib_GetTupleMemberOffsets), &Hxx2::Wrapper<Hxx2::Unresolved>::DataTypeLib_GetTupleMemberOffsets);
		#else
		tbl->DataTypeLib_GetTupleMemberOffsets = PRIVATE_MAXON_MF_CAST(decltype(DataTypeLib_GetTupleMemberOffsets), &Hxx2::Wrapper<Hxx2::Unresolved>::DataTypeLib_GetTupleMemberOffsets);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<const Block<const Int>&>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->DataTypeLib_GetMemberOrder = PRIVATE_MAXON_MF_CAST(decltype(DataTypeLib_GetMemberOrder), &Hxx2::Wrapper<Hxx2::Unresolved>::DataTypeLib_GetMemberOrder);
		#else
		tbl->DataTypeLib_GetMemberOrder = PRIVATE_MAXON_MF_CAST(decltype(DataTypeLib_GetMemberOrder), &Hxx2::Wrapper<Hxx2::Unresolved>::DataTypeLib_GetMemberOrder);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<DelegateDataType>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->DataTypeLib_GetDelegateType = PRIVATE_MAXON_MF_CAST(decltype(DataTypeLib_GetDelegateType), &Hxx2::Wrapper<Hxx2::Unresolved>::DataTypeLib_GetDelegateType);
		#else
		tbl->DataTypeLib_GetDelegateType = PRIVATE_MAXON_MF_CAST(decltype(DataTypeLib_GetDelegateType), &Hxx2::Wrapper<Hxx2::Unresolved>::DataTypeLib_GetDelegateType);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<DelegateDataType>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->DataTypeLib_GetDelegateType_1 = PRIVATE_MAXON_MF_CAST(decltype(DataTypeLib_GetDelegateType_1), &Hxx2::Wrapper<Hxx2::Unresolved>::DataTypeLib_GetDelegateType_1);
		#else
		tbl->DataTypeLib_GetDelegateType_1 = PRIVATE_MAXON_MF_CAST(decltype(DataTypeLib_GetDelegateType_1), &Hxx2::Wrapper<Hxx2::Unresolved>::DataTypeLib_GetDelegateType_1);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<void>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->DataTypeLib_InvokeDelegate = PRIVATE_MAXON_MF_CAST(decltype(DataTypeLib_InvokeDelegate), &Hxx2::Wrapper<Hxx2::Unresolved>::DataTypeLib_InvokeDelegate);
		#else
		tbl->DataTypeLib_InvokeDelegate = PRIVATE_MAXON_MF_CAST(decltype(DataTypeLib_InvokeDelegate), &Hxx2::Wrapper<Hxx2::Unresolved>::DataTypeLib_InvokeDelegate);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<DelegateBase>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->DataTypeLib_CreateDelegate = PRIVATE_MAXON_MF_CAST(decltype(DataTypeLib_CreateDelegate), &Hxx2::Wrapper<Hxx2::Unresolved>::DataTypeLib_CreateDelegate);
		#else
		tbl->DataTypeLib_CreateDelegate = PRIVATE_MAXON_MF_CAST(decltype(DataTypeLib_CreateDelegate), &Hxx2::Wrapper<Hxx2::Unresolved>::DataTypeLib_CreateDelegate);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<const DataType&>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->DataTypeLib_GetDelegateReturnType = PRIVATE_MAXON_MF_CAST(decltype(DataTypeLib_GetDelegateReturnType), &Hxx2::Wrapper<Hxx2::Unresolved>::DataTypeLib_GetDelegateReturnType);
		#else
		tbl->DataTypeLib_GetDelegateReturnType = PRIVATE_MAXON_MF_CAST(decltype(DataTypeLib_GetDelegateReturnType), &Hxx2::Wrapper<Hxx2::Unresolved>::DataTypeLib_GetDelegateReturnType);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<const Block<const DataType>&>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->DataTypeLib_GetDelegateParameterTypes = PRIVATE_MAXON_MF_CAST(decltype(DataTypeLib_GetDelegateParameterTypes), &Hxx2::Wrapper<Hxx2::Unresolved>::DataTypeLib_GetDelegateParameterTypes);
		#else
		tbl->DataTypeLib_GetDelegateParameterTypes = PRIVATE_MAXON_MF_CAST(decltype(DataTypeLib_GetDelegateParameterTypes), &Hxx2::Wrapper<Hxx2::Unresolved>::DataTypeLib_GetDelegateParameterTypes);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<EnumDataType>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->DataTypeLib_GetEnumType = PRIVATE_MAXON_MF_CAST(decltype(DataTypeLib_GetEnumType), &Hxx2::Wrapper<Hxx2::Unresolved>::DataTypeLib_GetEnumType);
		#else
		tbl->DataTypeLib_GetEnumType = PRIVATE_MAXON_MF_CAST(decltype(DataTypeLib_GetEnumType), &Hxx2::Wrapper<Hxx2::Unresolved>::DataTypeLib_GetEnumType);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<const Block<const Tuple<Id, Data>>&>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->DataTypeLib_GetEnumerators = PRIVATE_MAXON_MF_CAST(decltype(DataTypeLib_GetEnumerators), &Hxx2::Wrapper<Hxx2::Unresolved>::DataTypeLib_GetEnumerators);
		#else
		tbl->DataTypeLib_GetEnumerators = PRIVATE_MAXON_MF_CAST(decltype(DataTypeLib_GetEnumerators), &Hxx2::Wrapper<Hxx2::Unresolved>::DataTypeLib_GetEnumerators);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<void>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->DataTypeLib_RegisterEnumType = PRIVATE_MAXON_MF_CAST(decltype(DataTypeLib_RegisterEnumType), &Hxx2::Wrapper<Hxx2::Unresolved>::DataTypeLib_RegisterEnumType);
		#else
		tbl->DataTypeLib_RegisterEnumType = PRIVATE_MAXON_MF_CAST(decltype(DataTypeLib_RegisterEnumType), &Hxx2::Wrapper<Hxx2::Unresolved>::DataTypeLib_RegisterEnumType);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<DataType>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->DataTypeLib_GetDataTypeOfInterfaces = PRIVATE_MAXON_MF_CAST(decltype(DataTypeLib_GetDataTypeOfInterfaces), &Hxx2::Wrapper<Hxx2::Unresolved>::DataTypeLib_GetDataTypeOfInterfaces);
		#else
		tbl->DataTypeLib_GetDataTypeOfInterfaces = PRIVATE_MAXON_MF_CAST(decltype(DataTypeLib_GetDataTypeOfInterfaces), &Hxx2::Wrapper<Hxx2::Unresolved>::DataTypeLib_GetDataTypeOfInterfaces);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<DataType>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->DataTypeLib_GetReferenceType = PRIVATE_MAXON_MF_CAST(decltype(DataTypeLib_GetReferenceType), &Hxx2::Wrapper<Hxx2::Unresolved>::DataTypeLib_GetReferenceType);
		#else
		tbl->DataTypeLib_GetReferenceType = PRIVATE_MAXON_MF_CAST(decltype(DataTypeLib_GetReferenceType), &Hxx2::Wrapper<Hxx2::Unresolved>::DataTypeLib_GetReferenceType);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<Tuple<DataType, const Char*>>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->DataTypeLib_ParseDataType = PRIVATE_MAXON_MF_CAST(decltype(DataTypeLib_ParseDataType), &Hxx2::Wrapper<Hxx2::Unresolved>::DataTypeLib_ParseDataType);
		#else
		tbl->DataTypeLib_ParseDataType = PRIVATE_MAXON_MF_CAST(decltype(DataTypeLib_ParseDataType), &Hxx2::Wrapper<Hxx2::Unresolved>::DataTypeLib_ParseDataType);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<Tuple<Member, const Char*>>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->DataTypeLib_ParseMember = PRIVATE_MAXON_MF_CAST(decltype(DataTypeLib_ParseMember), &Hxx2::Wrapper<Hxx2::Unresolved>::DataTypeLib_ParseMember);
		#else
		tbl->DataTypeLib_ParseMember = PRIVATE_MAXON_MF_CAST(decltype(DataTypeLib_ParseMember), &Hxx2::Wrapper<Hxx2::Unresolved>::DataTypeLib_ParseMember);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<Tuple<Int64, const Char*>>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->DataTypeLib_ParseInt = PRIVATE_MAXON_MF_CAST(decltype(DataTypeLib_ParseInt), &Hxx2::Wrapper<Hxx2::Unresolved>::DataTypeLib_ParseInt);
		#else
		tbl->DataTypeLib_ParseInt = PRIVATE_MAXON_MF_CAST(decltype(DataTypeLib_ParseInt), &Hxx2::Wrapper<Hxx2::Unresolved>::DataTypeLib_ParseInt);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<DataType>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->DataTypeLib_GetDataType = PRIVATE_MAXON_MF_CAST(decltype(DataTypeLib_GetDataType), &Hxx2::Wrapper<Hxx2::Unresolved>::DataTypeLib_GetDataType);
		#else
		tbl->DataTypeLib_GetDataType = PRIVATE_MAXON_MF_CAST(decltype(DataTypeLib_GetDataType), &Hxx2::Wrapper<Hxx2::Unresolved>::DataTypeLib_GetDataType);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<const Id&>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->DataTypeLib_GetNumberedId = PRIVATE_MAXON_MF_CAST(decltype(DataTypeLib_GetNumberedId), &Hxx2::Wrapper<Hxx2::Unresolved>::DataTypeLib_GetNumberedId);
		#else
		tbl->DataTypeLib_GetNumberedId = PRIVATE_MAXON_MF_CAST(decltype(DataTypeLib_GetNumberedId), &Hxx2::Wrapper<Hxx2::Unresolved>::DataTypeLib_GetNumberedId);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<const MemberMap*>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->DataTypeLib_GetMemberMap = PRIVATE_MAXON_MF_CAST(decltype(DataTypeLib_GetMemberMap), &Hxx2::Wrapper<Hxx2::Unresolved>::DataTypeLib_GetMemberMap);
		#else
		tbl->DataTypeLib_GetMemberMap = PRIVATE_MAXON_MF_CAST(decltype(DataTypeLib_GetMemberMap), &Hxx2::Wrapper<Hxx2::Unresolved>::DataTypeLib_GetMemberMap);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<const MemberMap*>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->DataTypeLib_GetIdentityMemberMap = PRIVATE_MAXON_MF_CAST(decltype(DataTypeLib_GetIdentityMemberMap), &Hxx2::Wrapper<Hxx2::Unresolved>::DataTypeLib_GetIdentityMemberMap);
		#else
		tbl->DataTypeLib_GetIdentityMemberMap = PRIVATE_MAXON_MF_CAST(decltype(DataTypeLib_GetIdentityMemberMap), &Hxx2::Wrapper<Hxx2::Unresolved>::DataTypeLib_GetIdentityMemberMap);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<const MemberMap*>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->DataTypeLib_ConcatMemberMap = PRIVATE_MAXON_MF_CAST(decltype(DataTypeLib_ConcatMemberMap), &Hxx2::Wrapper<Hxx2::Unresolved>::DataTypeLib_ConcatMemberMap);
		#else
		tbl->DataTypeLib_ConcatMemberMap = PRIVATE_MAXON_MF_CAST(decltype(DataTypeLib_ConcatMemberMap), &Hxx2::Wrapper<Hxx2::Unresolved>::DataTypeLib_ConcatMemberMap);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<const MemberMap*>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->DataTypeLib_GetMemberMap_1 = PRIVATE_MAXON_MF_CAST(decltype(DataTypeLib_GetMemberMap_1), &Hxx2::Wrapper<Hxx2::Unresolved>::DataTypeLib_GetMemberMap_1);
		#else
		tbl->DataTypeLib_GetMemberMap_1 = PRIVATE_MAXON_MF_CAST(decltype(DataTypeLib_GetMemberMap_1), &Hxx2::Wrapper<Hxx2::Unresolved>::DataTypeLib_GetMemberMap_1);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<DataType>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->DataTypeLib_GetDataTypeForData = PRIVATE_MAXON_MF_CAST(decltype(DataTypeLib_GetDataTypeForData), &Hxx2::Wrapper<Hxx2::Unresolved>::DataTypeLib_GetDataTypeForData);
		#else
		tbl->DataTypeLib_GetDataTypeForData = PRIVATE_MAXON_MF_CAST(decltype(DataTypeLib_GetDataTypeForData), &Hxx2::Wrapper<Hxx2::Unresolved>::DataTypeLib_GetDataTypeForData);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<void>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->DataTypeLib_ConvertToData = PRIVATE_MAXON_MF_CAST(decltype(DataTypeLib_ConvertToData), &Hxx2::Wrapper<Hxx2::Unresolved>::DataTypeLib_ConvertToData);
		#else
		tbl->DataTypeLib_ConvertToData = PRIVATE_MAXON_MF_CAST(decltype(DataTypeLib_ConvertToData), &Hxx2::Wrapper<Hxx2::Unresolved>::DataTypeLib_ConvertToData);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<void>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->DataTypeLib_MoveFromData = PRIVATE_MAXON_MF_CAST(decltype(DataTypeLib_MoveFromData), &Hxx2::Wrapper<Hxx2::Unresolved>::DataTypeLib_MoveFromData);
		#else
		tbl->DataTypeLib_MoveFromData = PRIVATE_MAXON_MF_CAST(decltype(DataTypeLib_MoveFromData), &Hxx2::Wrapper<Hxx2::Unresolved>::DataTypeLib_MoveFromData);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->DataTypeLib_PrivateIsBaseOfOrSame = PRIVATE_MAXON_MF_CAST(decltype(DataTypeLib_PrivateIsBaseOfOrSame), &Hxx2::Wrapper<Hxx2::Unresolved>::DataTypeLib_PrivateIsBaseOfOrSame);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<StrongRef<TypeArguments>>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->DataTypeLib_CreateTypeArguments = PRIVATE_MAXON_MF_CAST(decltype(DataTypeLib_CreateTypeArguments), &Hxx2::Wrapper<Hxx2::Unresolved>::DataTypeLib_CreateTypeArguments);
		#else
		tbl->DataTypeLib_CreateTypeArguments = PRIVATE_MAXON_MF_CAST(decltype(DataTypeLib_CreateTypeArguments), &Hxx2::Wrapper<Hxx2::Unresolved>::DataTypeLib_CreateTypeArguments);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<StrongRef<TypeArguments>>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->DataTypeLib_CreateTypeArguments_1 = PRIVATE_MAXON_MF_CAST(decltype(DataTypeLib_CreateTypeArguments_1), &Hxx2::Wrapper<Hxx2::Unresolved>::DataTypeLib_CreateTypeArguments_1);
		#else
		tbl->DataTypeLib_CreateTypeArguments_1 = PRIVATE_MAXON_MF_CAST(decltype(DataTypeLib_CreateTypeArguments_1), &Hxx2::Wrapper<Hxx2::Unresolved>::DataTypeLib_CreateTypeArguments_1);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<ResultMem>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->DataTypeLib_FinalizeTypeArguments = PRIVATE_MAXON_MF_CAST(decltype(DataTypeLib_FinalizeTypeArguments), &Hxx2::Wrapper<Hxx2::Unresolved>::DataTypeLib_FinalizeTypeArguments);
		#else
		tbl->DataTypeLib_FinalizeTypeArguments = PRIVATE_MAXON_MF_CAST(decltype(DataTypeLib_FinalizeTypeArguments), &Hxx2::Wrapper<Hxx2::Unresolved>::DataTypeLib_FinalizeTypeArguments);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->DataTypeLib_PrivateHandleUnreferencedType = PRIVATE_MAXON_MF_CAST(decltype(DataTypeLib_PrivateHandleUnreferencedType), &Hxx2::Wrapper<Hxx2::Unresolved>::DataTypeLib_PrivateHandleUnreferencedType);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<const DataType&>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->DataTypeLib_PrivateGetPrimaryDataTypeType = PRIVATE_MAXON_MF_CAST(decltype(DataTypeLib_PrivateGetPrimaryDataTypeType), &Hxx2::Wrapper<Hxx2::Unresolved>::DataTypeLib_PrivateGetPrimaryDataTypeType);
		#else
		tbl->DataTypeLib_PrivateGetPrimaryDataTypeType = PRIVATE_MAXON_MF_CAST(decltype(DataTypeLib_PrivateGetPrimaryDataTypeType), &Hxx2::Wrapper<Hxx2::Unresolved>::DataTypeLib_PrivateGetPrimaryDataTypeType);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->DataTypeLib_AddLeakingInstantiatedType = PRIVATE_MAXON_MF_CAST(decltype(DataTypeLib_AddLeakingInstantiatedType), &Hxx2::Wrapper<Hxx2::Unresolved>::DataTypeLib_AddLeakingInstantiatedType);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->DataTypeLib_PrivateGetNamedTupleMembers = PRIVATE_MAXON_MF_CAST(decltype(DataTypeLib_PrivateGetNamedTupleMembers), &Hxx2::Wrapper<Hxx2::Unresolved>::DataTypeLib_PrivateGetNamedTupleMembers);
		#endif
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_interface, (const void**) tbl, _returnTypes, SIZEOF(MTable) / SIZEOF(void*));
	#else
		return true;
	#endif
	}
	MAXON_INTERFACE_REGISTER(DataTypeLib, "net.maxon.interface.datatypelib", nullptr, maxon::EntityBase::FLAGS::NONE);
	template <typename DUMMY> maxon::Int DataTypeLib::PrivateInstantiateDefaultValueHelper()
	{
		return 0
		| maxon::details::InstantiateDefaultReturnValue<ResultMem>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateDefaultReturnValue<const Block<const DataType>&>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateDefaultReturnValue<const Block<const Int>&>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateDefaultReturnValue<const Block<const Tuple<Id, Data>>&>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateDefaultReturnValue<const DataType&>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateDefaultReturnValue<const Id&>(OVERLOAD_MAX_RANK)
		;
	}
}
#endif
static maxon::details::ForceEvaluation s_forceEval_datatypelib(0
	| maxon::DataTypeLib::PrivateInstantiateDefaultValueHelper<maxon::Int>()
);
