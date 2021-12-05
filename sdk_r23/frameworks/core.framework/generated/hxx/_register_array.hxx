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
		"NewBaseArray@d117f81dde00a060\0" // Result<ArrayInterface<Generic>*> NewBaseArray(const DataType& type, const Generic* src, Bool move)
		"NewBlockArray@d117f81dde00a060\0" // Result<ArrayInterface<Generic>*> NewBlockArray(const DataType& type, const Generic* src, Bool move)
	"";
	MAXON_WARNING_PUSH
	MAXON_WARNING_DISABLE_DEPRECATED
	class ArrayFactory::Hxx2::Unresolved : public ArrayFactory
	{
	public:
		static const Unresolved* Get(const ArrayFactory* o) { return (const Unresolved*) o; }
		static Unresolved* Get(ArrayFactory* o) { return (Unresolved*) o; }
		static Result<ArrayInterface<Generic>*> NewBaseArray(const DataType& type, const Generic* src, Bool move) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ArrayFactory::NewBaseArray(type, src, move); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static Result<ArrayInterface<Generic>*> NewBlockArray(const DataType& type, const Generic* src, Bool move) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ArrayFactory::NewBlockArray(type, src, move); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
	};
	MAXON_WARNING_POP
#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
	const maxon::NULL_RETURN_TYPE ArrayFactory::MTable::_returnTypes[] = 
	{
		maxon::details::NullReturnType<Result<ArrayInterface<Generic>*>>::value,
		maxon::details::NullReturnType<Result<ArrayInterface<Generic>*>>::value,
		maxon::NULL_RETURN_TYPE::OTHER
	};
#endif
	maxon::Bool ArrayFactory::MTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl)
	{
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<ArrayInterface<Generic>*>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_ArrayFactory_NewBaseArray = &Hxx2::Wrapper<Hxx2::Unresolved>::_ArrayFactory_NewBaseArray;
		#else
		tbl->_ArrayFactory_NewBaseArray = &Hxx2::Wrapper<Hxx2::Unresolved>::_ArrayFactory_NewBaseArray;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<ArrayInterface<Generic>*>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_ArrayFactory_NewBlockArray = &Hxx2::Wrapper<Hxx2::Unresolved>::_ArrayFactory_NewBlockArray;
		#else
		tbl->_ArrayFactory_NewBlockArray = &Hxx2::Wrapper<Hxx2::Unresolved>::_ArrayFactory_NewBlockArray;
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
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(Array, , "net.maxon.parametrictype.array");
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
