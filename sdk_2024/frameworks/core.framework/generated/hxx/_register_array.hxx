#if 1
namespace maxon
{
#ifdef MAXON_COMPILER_INTEL
#endif
#ifdef MAXON_COMPILER_INTEL
#endif
#ifdef CPP_853_HACK
#ifdef MAXON_COMPILER_GCC
#else
#endif
#endif
#ifdef CPP_853_HACK
#endif
#ifdef CPP_853_HACK
#ifdef MAXON_COMPILER_GCC
#else
#endif
#endif
#ifdef CPP_853_HACK
#else
#endif
#ifdef MAXON_COMPILER_BUG_CONST_TYPE_ALIAS
#else
#endif
	const maxon::Char* const ArrayFactory::MTable::_ids = 
		"NewBaseArray@8549d0d06e9a0bc5\0" // Result<Array<Generic>::NonConst> NewBaseArray(const DataType& elementType, const Generic* src, Bool move)
		"NewBaseArrayFromContainerType@cf2e65cc1ef02e50\0" // Result<Array<Generic>::NonConst> NewBaseArrayFromContainerType(const ContainerDataType<>& containerType, const Generic* src, Bool move)
		"NewBlockArray@8549d0d06e9a0bc5\0" // Result<Array<Generic>::NonConst> NewBlockArray(const DataType& elementType, const Generic* src, Bool move)
		"NewPagedArray@8549d0d06e9a0bc5\0" // Result<Array<Generic>::NonConst> NewPagedArray(const DataType& elementType, const Generic* defaultValue, Bool useRefCountForDefault)
		"NewPagedArrayFromContainerType@cf2e65cc1ef02e50\0" // Result<Array<Generic>::NonConst> NewPagedArrayFromContainerType(const ContainerDataType<>& containerType, const Generic* defaultValue, Bool useRefCountForDefault)
		"Slice@d3676c05402e88b5\0" // Result<Array<Generic>> Slice(const Array<Generic>& base, Int start, Int end, Bool cycle, const Generic* defaultValue, Bool useRefCountForDefault)
		"NewSingleValueArray@2bc23f38a93f4607\0" // Result<Array<Generic>> NewSingleValueArray(const ConstDataPtr& value, Int count, const ContainerDataType<>& containerType)
		"ExtractMember@ddf04432a1a93604\0" // Result<Array<Generic>> ExtractMember(const Array<Generic>& base, Int offset, const ContainerDataType<>& containerType)
		"Reinterpret@2cf9033e0f198a31\0" // Result<Array<Generic>> Reinterpret(const Array<Generic>& base, const ContainerDataType<>& containerType)
		"PrivateNewPagedArrayFromBase@461d69c8b9ef640f\0" // Result<Array<Generic>::NonConst> PrivateNewPagedArrayFromBase(const Array<Generic>& base, const Generic* defaultValue, Bool useRefCountForDefault)
		"ConvertToSingleBlock@99e22328f97e19f1\0" // Result<Array<Generic>> ConvertToSingleBlock(const Array<Generic>& source)
	"";
	MAXON_WARNING_PUSH
	MAXON_WARNING_DISABLE_DEPRECATED
	class ArrayFactory::Hxx2::Unresolved : public ArrayFactory
	{
	public:
		static const Unresolved* Get(const ArrayFactory* o) { return (const Unresolved*) o; }
		static Unresolved* Get(ArrayFactory* o) { return (Unresolved*) o; }
		static Result<Array<Generic>::NonConst> NewBaseArray(const DataType& elementType, const Generic* src, Bool move) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ArrayFactory::NewBaseArray(elementType, src, move); return HXXRET1(UNRESOLVED);}
		static Result<Array<Generic>::NonConst> NewBaseArrayFromContainerType(const ContainerDataType<>& containerType, const Generic* src, Bool move) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ArrayFactory::NewBaseArrayFromContainerType(containerType, src, move); return HXXRET1(UNRESOLVED);}
		static Result<Array<Generic>::NonConst> NewBlockArray(const DataType& elementType, const Generic* src, Bool move) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ArrayFactory::NewBlockArray(elementType, src, move); return HXXRET1(UNRESOLVED);}
		static Result<Array<Generic>::NonConst> NewPagedArray(const DataType& elementType, const Generic* defaultValue, Bool useRefCountForDefault) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ArrayFactory::NewPagedArray(elementType, defaultValue, useRefCountForDefault); return HXXRET1(UNRESOLVED);}
		static Result<Array<Generic>::NonConst> NewPagedArrayFromContainerType(const ContainerDataType<>& containerType, const Generic* defaultValue, Bool useRefCountForDefault) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ArrayFactory::NewPagedArrayFromContainerType(containerType, defaultValue, useRefCountForDefault); return HXXRET1(UNRESOLVED);}
		static Result<Array<Generic>> Slice(const Array<Generic>& base, Int start, Int end, Bool cycle, const Generic* defaultValue, Bool useRefCountForDefault) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ArrayFactory::Slice(base, start, end, cycle, defaultValue, useRefCountForDefault); return HXXRET1(UNRESOLVED);}
		static Result<Array<Generic>> NewSingleValueArray(const ConstDataPtr& value, Int count, const ContainerDataType<>& containerType) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ArrayFactory::NewSingleValueArray(value, count, containerType); return HXXRET1(UNRESOLVED);}
		static Result<Array<Generic>> ExtractMember(const Array<Generic>& base, Int offset, const ContainerDataType<>& containerType) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ArrayFactory::ExtractMember(base, offset, containerType); return HXXRET1(UNRESOLVED);}
		static Result<Array<Generic>> Reinterpret(const Array<Generic>& base, const ContainerDataType<>& containerType) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ArrayFactory::Reinterpret(base, containerType); return HXXRET1(UNRESOLVED);}
		static Result<Array<Generic>::NonConst> PrivateNewPagedArrayFromBase(const Array<Generic>& base, const Generic* defaultValue, Bool useRefCountForDefault) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ArrayFactory::PrivateNewPagedArrayFromBase(base, defaultValue, useRefCountForDefault); return HXXRET1(UNRESOLVED);}
		static Result<Array<Generic>> ConvertToSingleBlock(const Array<Generic>& source) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ArrayFactory::ConvertToSingleBlock(source); return HXXRET1(UNRESOLVED);}
	};
	MAXON_WARNING_POP
#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
	const maxon::UNRESOLVED_RETURN_TYPE ArrayFactory::MTable::_returnTypes[] = 
	{
		maxon::details::UnresolvedReturnType<Result<Array<Generic>::NonConst>>::value,
		maxon::details::UnresolvedReturnType<Result<Array<Generic>::NonConst>>::value,
		maxon::details::UnresolvedReturnType<Result<Array<Generic>::NonConst>>::value,
		maxon::details::UnresolvedReturnType<Result<Array<Generic>::NonConst>>::value,
		maxon::details::UnresolvedReturnType<Result<Array<Generic>::NonConst>>::value,
		maxon::details::UnresolvedReturnType<Result<Array<Generic>>>::value,
		maxon::details::UnresolvedReturnType<Result<Array<Generic>>>::value,
		maxon::details::UnresolvedReturnType<Result<Array<Generic>>>::value,
		maxon::details::UnresolvedReturnType<Result<Array<Generic>>>::value,
		maxon::details::UnresolvedReturnType<Result<Array<Generic>::NonConst>>::value,
		maxon::details::UnresolvedReturnType<Result<Array<Generic>>>::value,
		maxon::UNRESOLVED_RETURN_TYPE::OTHER
	};
#endif
	maxon::Bool ArrayFactory::MTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl)
	{
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<Array<Generic>::NonConst>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->ArrayFactory_NewBaseArray = PRIVATE_MAXON_MF_CAST(decltype(ArrayFactory_NewBaseArray), &Hxx2::Wrapper<Hxx2::Unresolved>::ArrayFactory_NewBaseArray);
		#else
		tbl->ArrayFactory_NewBaseArray = PRIVATE_MAXON_MF_CAST(decltype(ArrayFactory_NewBaseArray), &Hxx2::Wrapper<Hxx2::Unresolved>::ArrayFactory_NewBaseArray);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<Array<Generic>::NonConst>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->ArrayFactory_NewBaseArrayFromContainerType = PRIVATE_MAXON_MF_CAST(decltype(ArrayFactory_NewBaseArrayFromContainerType), &Hxx2::Wrapper<Hxx2::Unresolved>::ArrayFactory_NewBaseArrayFromContainerType);
		#else
		tbl->ArrayFactory_NewBaseArrayFromContainerType = PRIVATE_MAXON_MF_CAST(decltype(ArrayFactory_NewBaseArrayFromContainerType), &Hxx2::Wrapper<Hxx2::Unresolved>::ArrayFactory_NewBaseArrayFromContainerType);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<Array<Generic>::NonConst>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->ArrayFactory_NewBlockArray = PRIVATE_MAXON_MF_CAST(decltype(ArrayFactory_NewBlockArray), &Hxx2::Wrapper<Hxx2::Unresolved>::ArrayFactory_NewBlockArray);
		#else
		tbl->ArrayFactory_NewBlockArray = PRIVATE_MAXON_MF_CAST(decltype(ArrayFactory_NewBlockArray), &Hxx2::Wrapper<Hxx2::Unresolved>::ArrayFactory_NewBlockArray);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<Array<Generic>::NonConst>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->ArrayFactory_NewPagedArray = PRIVATE_MAXON_MF_CAST(decltype(ArrayFactory_NewPagedArray), &Hxx2::Wrapper<Hxx2::Unresolved>::ArrayFactory_NewPagedArray);
		#else
		tbl->ArrayFactory_NewPagedArray = PRIVATE_MAXON_MF_CAST(decltype(ArrayFactory_NewPagedArray), &Hxx2::Wrapper<Hxx2::Unresolved>::ArrayFactory_NewPagedArray);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<Array<Generic>::NonConst>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->ArrayFactory_NewPagedArrayFromContainerType = PRIVATE_MAXON_MF_CAST(decltype(ArrayFactory_NewPagedArrayFromContainerType), &Hxx2::Wrapper<Hxx2::Unresolved>::ArrayFactory_NewPagedArrayFromContainerType);
		#else
		tbl->ArrayFactory_NewPagedArrayFromContainerType = PRIVATE_MAXON_MF_CAST(decltype(ArrayFactory_NewPagedArrayFromContainerType), &Hxx2::Wrapper<Hxx2::Unresolved>::ArrayFactory_NewPagedArrayFromContainerType);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<Array<Generic>>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->ArrayFactory_Slice = PRIVATE_MAXON_MF_CAST(decltype(ArrayFactory_Slice), &Hxx2::Wrapper<Hxx2::Unresolved>::ArrayFactory_Slice);
		#else
		tbl->ArrayFactory_Slice = PRIVATE_MAXON_MF_CAST(decltype(ArrayFactory_Slice), &Hxx2::Wrapper<Hxx2::Unresolved>::ArrayFactory_Slice);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<Array<Generic>>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->ArrayFactory_NewSingleValueArray = PRIVATE_MAXON_MF_CAST(decltype(ArrayFactory_NewSingleValueArray), &Hxx2::Wrapper<Hxx2::Unresolved>::ArrayFactory_NewSingleValueArray);
		#else
		tbl->ArrayFactory_NewSingleValueArray = PRIVATE_MAXON_MF_CAST(decltype(ArrayFactory_NewSingleValueArray), &Hxx2::Wrapper<Hxx2::Unresolved>::ArrayFactory_NewSingleValueArray);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<Array<Generic>>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->ArrayFactory_ExtractMember = PRIVATE_MAXON_MF_CAST(decltype(ArrayFactory_ExtractMember), &Hxx2::Wrapper<Hxx2::Unresolved>::ArrayFactory_ExtractMember);
		#else
		tbl->ArrayFactory_ExtractMember = PRIVATE_MAXON_MF_CAST(decltype(ArrayFactory_ExtractMember), &Hxx2::Wrapper<Hxx2::Unresolved>::ArrayFactory_ExtractMember);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<Array<Generic>>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->ArrayFactory_Reinterpret = PRIVATE_MAXON_MF_CAST(decltype(ArrayFactory_Reinterpret), &Hxx2::Wrapper<Hxx2::Unresolved>::ArrayFactory_Reinterpret);
		#else
		tbl->ArrayFactory_Reinterpret = PRIVATE_MAXON_MF_CAST(decltype(ArrayFactory_Reinterpret), &Hxx2::Wrapper<Hxx2::Unresolved>::ArrayFactory_Reinterpret);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<Array<Generic>::NonConst>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->ArrayFactory_PrivateNewPagedArrayFromBase = PRIVATE_MAXON_MF_CAST(decltype(ArrayFactory_PrivateNewPagedArrayFromBase), &Hxx2::Wrapper<Hxx2::Unresolved>::ArrayFactory_PrivateNewPagedArrayFromBase);
		#else
		tbl->ArrayFactory_PrivateNewPagedArrayFromBase = PRIVATE_MAXON_MF_CAST(decltype(ArrayFactory_PrivateNewPagedArrayFromBase), &Hxx2::Wrapper<Hxx2::Unresolved>::ArrayFactory_PrivateNewPagedArrayFromBase);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<Array<Generic>>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->ArrayFactory_ConvertToSingleBlock = PRIVATE_MAXON_MF_CAST(decltype(ArrayFactory_ConvertToSingleBlock), &Hxx2::Wrapper<Hxx2::Unresolved>::ArrayFactory_ConvertToSingleBlock);
		#else
		tbl->ArrayFactory_ConvertToSingleBlock = PRIVATE_MAXON_MF_CAST(decltype(ArrayFactory_ConvertToSingleBlock), &Hxx2::Wrapper<Hxx2::Unresolved>::ArrayFactory_ConvertToSingleBlock);
		#endif
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_interface, (const void**) tbl, _returnTypes, SIZEOF(MTable) / SIZEOF(void*));
	#else
		return true;
	#endif
	}
	MAXON_INTERFACE_REGISTER(ArrayFactory, "net.maxon.interface.arrayfactory", nullptr, maxon::EntityBase::FLAGS::NONE);
	namespace ParametricTypes
	{
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(ArrayInterface, , "net.maxon.parametrictype.array");
	}
#ifndef CPP_853_HACK
#else
#endif
#ifdef CPP_853_HACK
#else
#endif
#ifdef CPP_853_HACK
#else
#endif
}
#endif
