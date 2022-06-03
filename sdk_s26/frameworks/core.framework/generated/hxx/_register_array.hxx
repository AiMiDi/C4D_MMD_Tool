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
		"NewBaseArray@d117f81dde00a060\0" // Result<ArrayInterface<Generic>*> NewBaseArray(const DataType& elementType, const Generic* src, Bool move)
		"NewBaseArrayFromContainerType@e200fcca9a3e7acb\0" // Result<ArrayInterface<Generic>*> NewBaseArrayFromContainerType(const ContainerDataType<>& containerType, const Generic* src, Bool move)
		"NewBlockArray@d117f81dde00a060\0" // Result<ArrayInterface<Generic>*> NewBlockArray(const DataType& elementType, const Generic* src, Bool move)
		"NewPagedArray@930fa09bcd5bac87\0" // Result<Array<Generic>> NewPagedArray(const DataType& elementType, const Generic* defaultValue, Bool useRefCountForDefault)
		"NewPagedArrayFromContainerType@d0889e6478000b3e\0" // Result<Array<Generic>> NewPagedArrayFromContainerType(const ContainerDataType<>& containerType, const Generic* defaultValue, Bool useRefCountForDefault)
		"Slice@d3676c05402e88b5\0" // Result<Array<Generic>> Slice(const Array<Generic>& base, Int start, Int end, Bool cycle, const Generic* defaultValue, Bool useRefCountForDefault)
		"NewSingleValueArray@2bc23f38a93f4607\0" // Result<Array<Generic>> NewSingleValueArray(const ConstDataPtr& value, Int count, const ContainerDataType<>& containerType)
		"ExtractMember@ddf04432a1a93604\0" // Result<Array<Generic>> ExtractMember(const Array<Generic>& base, Int offset, const ContainerDataType<>& containerType)
		"Reinterpret@2cf9033e0f198a31\0" // Result<Array<Generic>> Reinterpret(const Array<Generic>& base, const ContainerDataType<>& containerType)
		"PrivateNewPagedArrayFromBase@8178b3cb5d1fa285\0" // Result<Array<Generic>> PrivateNewPagedArrayFromBase(const Array<Generic>& base, const Generic* defaultValue, Bool useRefCountForDefault)
	"";
	MAXON_WARNING_PUSH
	MAXON_WARNING_DISABLE_DEPRECATED
	class ArrayFactory::Hxx2::Unresolved : public ArrayFactory
	{
	public:
		static const Unresolved* Get(const ArrayFactory* o) { return (const Unresolved*) o; }
		static Unresolved* Get(ArrayFactory* o) { return (Unresolved*) o; }
		static Result<ArrayInterface<Generic>*> NewBaseArray(const DataType& elementType, const Generic* src, Bool move) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ArrayFactory::NewBaseArray(elementType, src, move); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static Result<ArrayInterface<Generic>*> NewBaseArrayFromContainerType(const ContainerDataType<>& containerType, const Generic* src, Bool move) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ArrayFactory::NewBaseArrayFromContainerType(containerType, src, move); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static Result<ArrayInterface<Generic>*> NewBlockArray(const DataType& elementType, const Generic* src, Bool move) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ArrayFactory::NewBlockArray(elementType, src, move); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static Result<Array<Generic>> NewPagedArray(const DataType& elementType, const Generic* defaultValue, Bool useRefCountForDefault) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ArrayFactory::NewPagedArray(elementType, defaultValue, useRefCountForDefault); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static Result<Array<Generic>> NewPagedArrayFromContainerType(const ContainerDataType<>& containerType, const Generic* defaultValue, Bool useRefCountForDefault) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ArrayFactory::NewPagedArrayFromContainerType(containerType, defaultValue, useRefCountForDefault); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static Result<Array<Generic>> Slice(const Array<Generic>& base, Int start, Int end, Bool cycle, const Generic* defaultValue, Bool useRefCountForDefault) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ArrayFactory::Slice(base, start, end, cycle, defaultValue, useRefCountForDefault); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static Result<Array<Generic>> NewSingleValueArray(const ConstDataPtr& value, Int count, const ContainerDataType<>& containerType) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ArrayFactory::NewSingleValueArray(value, count, containerType); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static Result<Array<Generic>> ExtractMember(const Array<Generic>& base, Int offset, const ContainerDataType<>& containerType) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ArrayFactory::ExtractMember(base, offset, containerType); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static Result<Array<Generic>> Reinterpret(const Array<Generic>& base, const ContainerDataType<>& containerType) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ArrayFactory::Reinterpret(base, containerType); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static Result<Array<Generic>> PrivateNewPagedArrayFromBase(const Array<Generic>& base, const Generic* defaultValue, Bool useRefCountForDefault) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ArrayFactory::PrivateNewPagedArrayFromBase(base, defaultValue, useRefCountForDefault); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
	};
	MAXON_WARNING_POP
#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
	const maxon::NULL_RETURN_TYPE ArrayFactory::MTable::_returnTypes[] = 
	{
		maxon::details::NullReturnType<Result<ArrayInterface<Generic>*>>::value,
		maxon::details::NullReturnType<Result<ArrayInterface<Generic>*>>::value,
		maxon::details::NullReturnType<Result<ArrayInterface<Generic>*>>::value,
		maxon::details::NullReturnType<Result<Array<Generic>>>::value,
		maxon::details::NullReturnType<Result<Array<Generic>>>::value,
		maxon::details::NullReturnType<Result<Array<Generic>>>::value,
		maxon::details::NullReturnType<Result<Array<Generic>>>::value,
		maxon::details::NullReturnType<Result<Array<Generic>>>::value,
		maxon::details::NullReturnType<Result<Array<Generic>>>::value,
		maxon::details::NullReturnType<Result<Array<Generic>>>::value,
		maxon::NULL_RETURN_TYPE::OTHER
	};
#endif
	maxon::Bool ArrayFactory::MTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl)
	{
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<ArrayInterface<Generic>*>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->ArrayFactory_NewBaseArray = &Hxx2::Wrapper<Hxx2::Unresolved>::ArrayFactory_NewBaseArray;
		#else
		tbl->ArrayFactory_NewBaseArray = &Hxx2::Wrapper<Hxx2::Unresolved>::ArrayFactory_NewBaseArray;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<ArrayInterface<Generic>*>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->ArrayFactory_NewBaseArrayFromContainerType = &Hxx2::Wrapper<Hxx2::Unresolved>::ArrayFactory_NewBaseArrayFromContainerType;
		#else
		tbl->ArrayFactory_NewBaseArrayFromContainerType = &Hxx2::Wrapper<Hxx2::Unresolved>::ArrayFactory_NewBaseArrayFromContainerType;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<ArrayInterface<Generic>*>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->ArrayFactory_NewBlockArray = &Hxx2::Wrapper<Hxx2::Unresolved>::ArrayFactory_NewBlockArray;
		#else
		tbl->ArrayFactory_NewBlockArray = &Hxx2::Wrapper<Hxx2::Unresolved>::ArrayFactory_NewBlockArray;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<Array<Generic>>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->ArrayFactory_NewPagedArray = &Hxx2::Wrapper<Hxx2::Unresolved>::ArrayFactory_NewPagedArray;
		#else
		tbl->ArrayFactory_NewPagedArray = &Hxx2::Wrapper<Hxx2::Unresolved>::ArrayFactory_NewPagedArray;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<Array<Generic>>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->ArrayFactory_NewPagedArrayFromContainerType = &Hxx2::Wrapper<Hxx2::Unresolved>::ArrayFactory_NewPagedArrayFromContainerType;
		#else
		tbl->ArrayFactory_NewPagedArrayFromContainerType = &Hxx2::Wrapper<Hxx2::Unresolved>::ArrayFactory_NewPagedArrayFromContainerType;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<Array<Generic>>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->ArrayFactory_Slice = &Hxx2::Wrapper<Hxx2::Unresolved>::ArrayFactory_Slice;
		#else
		tbl->ArrayFactory_Slice = &Hxx2::Wrapper<Hxx2::Unresolved>::ArrayFactory_Slice;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<Array<Generic>>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->ArrayFactory_NewSingleValueArray = &Hxx2::Wrapper<Hxx2::Unresolved>::ArrayFactory_NewSingleValueArray;
		#else
		tbl->ArrayFactory_NewSingleValueArray = &Hxx2::Wrapper<Hxx2::Unresolved>::ArrayFactory_NewSingleValueArray;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<Array<Generic>>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->ArrayFactory_ExtractMember = &Hxx2::Wrapper<Hxx2::Unresolved>::ArrayFactory_ExtractMember;
		#else
		tbl->ArrayFactory_ExtractMember = &Hxx2::Wrapper<Hxx2::Unresolved>::ArrayFactory_ExtractMember;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<Array<Generic>>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->ArrayFactory_Reinterpret = &Hxx2::Wrapper<Hxx2::Unresolved>::ArrayFactory_Reinterpret;
		#else
		tbl->ArrayFactory_Reinterpret = &Hxx2::Wrapper<Hxx2::Unresolved>::ArrayFactory_Reinterpret;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<Array<Generic>>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->ArrayFactory_PrivateNewPagedArrayFromBase = &Hxx2::Wrapper<Hxx2::Unresolved>::ArrayFactory_PrivateNewPagedArrayFromBase;
		#else
		tbl->ArrayFactory_PrivateNewPagedArrayFromBase = &Hxx2::Wrapper<Hxx2::Unresolved>::ArrayFactory_PrivateNewPagedArrayFromBase;
		#endif
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_interface, (maxon::Char*) tbl, _returnTypes, SIZEOF(MTable) / SIZEOF(void*));
	#else
		return true;
	#endif
	}
	MAXON_INTERFACE_REGISTER(ArrayFactory, "net.maxon.interface.arrayfactory", nullptr);
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
