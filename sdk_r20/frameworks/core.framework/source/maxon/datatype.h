#ifndef DATATYPE_H__
#define DATATYPE_H__

#include "maxon/apibase.h"
#include "maxon/parametric_type.h"
#include "maxon/datatypefunctions.h"

namespace maxon
{

/// @addtogroup DATATYPE
/// @{


template <typename T, typename CHECK = void> struct IsSimdElementType : public std::false_type
{
	using type = Int;
	using ValueType = Int;
	static const Int STRIDE = 1;
};

template <typename T> struct IsSimdElementType<T, typename SFINAEHelper<void, typename T::VectorStrideType>::type>
{
	static const Bool value = T::VectorStrideType::value != 1;
	using type = T;
	using ValueType = typename T::ValueType;
	static const Int STRIDE = T::VectorStrideType::value;
};


//----------------------------------------------------------------------------------------
/// SimdInfo stores information about the AOSOA layout of a SimdBlock, see there.
//----------------------------------------------------------------------------------------
struct SimdInfo
{
public:
	const DataType* componentType;	///< The component type such as Float.
	Int dimension;
	Int multiplicity;
	Int alignmentMask;
	Int multiplicityMask;
	Int logComponentSize;
	Int componentSize;
	Int extraStride;
};

//----------------------------------------------------------------------------------------
/// A SimdBlock represents a block of memory which is organized as an array of struct of arrays (AOSOA).
/// For example a normal Block<Vector> is layouted internally as xyzxyzxyzxyz (an array of structures, AOS).
/// If you want to make use of SIMD, it is important to build groups of the x-, y- and z-components.
/// Often this is done by making a structure of arrays (SOA), which for the example means having a structure of
/// an x-array holding all x-components, a y-array and a z-array.
/// But you can combine both to an array of struct of arrays (AOSOA): Only as many
/// components are grouped to a fixed-size array as fit into one SIMD value, and then these small arrays
/// are combined to a struct. This yields (in the case of four components per SIMD value) a memory layout
/// xxxxyyyyzzzzxxxxyyyyzzzz which provides better cache locality than a simple structure of arrays.
//----------------------------------------------------------------------------------------
template <typename T> class SimdBlock
{
public:
	static const Bool SIMD = IsSimdElementType<T>::value;

	T& operator [](Int index) const
	{
		MAXON_ASSERT_STANDARD_LAYOUT(SimdBlock);
		return *(T*) ((Char*) _ptr + (index & ~GetMultiplicityMask()) * _stride + ((index & GetMultiplicityMask()) << _logComponentSize));
	}

	const StridedBlock<T>& ToBlock() const
	{
		return *reinterpret_cast<const StridedBlock<T>*>(this);
	}

	StridedBlock<T>& ToBlock()
	{
		return *reinterpret_cast<StridedBlock<T>*>(this);
	}

	T* GetFirst() const
	{
		return _ptr;
	}

	Int GetCount() const
	{
		return _size;
	}

	Int GetStride() const
	{
		return _stride;
	}

	Int GetComponentStride() const
	{
		return _multiplicityMask ? (Int(1) << _logComponentSize) : _stride;
	}

	Int GetMultiplicityMask() const
	{
		DebugAssert(SIMD || (_multiplicityMask == 0));
		return SIMD ? _multiplicityMask : 0;
	}

	Int GetBaseSizeExponent() const
	{
		return _logComponentSize;
	}

	Int GetAlignmentMask() const
	{
		return _alignmentMask;
	}

	Int GetExtraStride() const
	{
		return _extraStride;
	}

	void SetSimdIndexing(Int multiplicity, Int logComponentSize, Int alignmentMask, Int extraStride)
	{
		DebugAssert(IsPowerOfTwo(UInt32(multiplicity)));
		_multiplicityMask = multiplicity - 1;
		_logComponentSize = logComponentSize;
		_alignmentMask = alignmentMask;
		_extraStride = extraStride;
	}

private:
	// Important: Ensure that the beginning of SimdBlock (its first three members _ptr, _size, _stride) is layout-compatible with StridedBlock<T>
	T* _ptr; ///< Pointer to first element.
	Int _size; ///< Number of elements.
	Int _stride; ///< Stride in bytes between elements. In the SIMD case, this is the size of a hypothetical non-SIMD vector (having dimension components). E.g., 24 for a double precision Vec3.

	Int _multiplicityMask; ///< Number of components per SIMD value minus one. Zero for the non-SIMD case.
	Int _logComponentSize; ///< Log2 of the size of a SIMD component (such as 3 for double precision float).
	Int _alignmentMask; ///< Size of a SIMD value minus one (i.e., the same as multiplicity * component size - 1, such as 15 for a 128-bit SSE value).
	Int _extraStride; ///< The extra stride to apply when a complete SIMD vector has been handled. This is (dimension-1) * size of SIMD value
};



template <typename PTR> class OpaquePtr
{
public:
	typename PTR::ReferencedType* GetPointer() const
	{
		return _ptr.GetPointer();
	}

private:
	PTR _ptr;
};


template <typename T, typename CHECK> class PrivateOpaque
{
public:
	using type = T;
};

template <typename T> class PrivateOpaque<T*, void>
{
public:
	using type = OpaquePtr<BaseRef<T, PointerHandler>>;
};

template <typename T> class PrivateOpaque<T, typename SFINAEHelper<void, typename T::ReferencedType>::type>
{
public:
	using type = OpaquePtr<T>;
};

template <typename T> using Opaque = typename PrivateOpaque<T, void>::type;

template <typename T, GET_DATATYPE_POLICY POLICY> inline Result<const DataType*> CheckedGetDataType();

template <GET_DATATYPE_POLICY POLICY> inline ResultOk<const DataType*> PrivateGetDataType(GenericArithmetic*, OverloadRank0)
{
	return DataTypeLib::GetGenericArithmeticType();
}

template <GET_DATATYPE_POLICY POLICY, typename T> inline typename SFINAEHelper<Result<const DataType*>, typename T::Unresolved>::type PrivateGetDataType(T*, OverloadRank0)
{
	const DataType* t = T::Interface::_interface.GetDataType();
	return t ? Result<const DataType*>(t) : UnregisteredDataTypeErrorObject();
}

template <GET_DATATYPE_POLICY POLICY, typename T> inline typename SFINAEHelper<Result<const DataType*>, typename T::StaticMTable>::type PrivateGetDataType(T*, OverloadRank1)
{
	const DataType* t = T::_interface.GetDataType();
	return t ? Result<const DataType*>(t) : UnregisteredDataTypeErrorObject();
}


template <GET_DATATYPE_POLICY POLICY> inline Result<const DataType*> PrivateGetDataType(void*, OverloadRank0)
{
	static_assert(Bool(POLICY & GET_DATATYPE_POLICY::RESULT_FOR_UNKNOWN_MASK), "Missing data type registration.");
	return (POLICY & GET_DATATYPE_POLICY::GENERIC_FOR_UNKNOWN) ? Result<const DataType*>(DataTypeLib::GetGenericType()) : UnregisteredDataTypeErrorObject();
}

template <GET_DATATYPE_POLICY POLICY, typename T> inline typename std::enable_if<GetDirectlyReferencedType<T>::value, Result<const DataType*>>::type PrivateGetDataType(T*, OverloadRank0)
{
	iferr_scope;
	const DataType* t = (CheckedGetDataType<typename T::DirectlyReferencedType, MAXON_IS_COW_KIND(T::Handler::KIND) ? POLICY & ~GET_DATATYPE_POLICY::NO_DECAY : POLICY | GET_DATATYPE_POLICY::NO_DECAY>()) iferr_return;
	switch (T::Handler::KIND & VALUEKIND::PTR_MASK)
	{
		case VALUEKIND::POINTER:
			return t->GetPointerType();
		case VALUEKIND::UNIQUE_REFERENCE:
			return t->GetUniqueReferenceType();
		case VALUEKIND::STRONG_REFERENCE:
			return t->GetStrongReferenceType();
		case VALUEKIND::COW_REFERENCE:
			return t->GetCOWReferenceType();
		case VALUEKIND::ACOW_REFERENCE:
			return t->GetACOWReferenceType();
		default:
			return IllegalArgumentError(MAXON_SOURCE_LOCATION);
	}
}

template <GET_DATATYPE_POLICY POLICY, typename T> inline Result<const DataType*> PrivateGetDataType(T**, OverloadRank0)
{
	iferr_scope;
	const DataType* t = CheckedGetDataType<typename std::conditional<std::is_function<T>::value, Generic, T>::type, Or<GET_DATATYPE_POLICY, POLICY, GET_DATATYPE_POLICY::NO_DECAY, GET_DATATYPE_POLICY::ALLOW_BASEARRAY>::value>() iferr_return;
	return t->GetPointerType();
}

template <GET_DATATYPE_POLICY POLICY, typename T> inline Result<const DataType*> PrivateGetDataType(Pointer<T>*, OverloadRank0)
{
	iferr_scope;
	const DataType* t = CheckedGetDataType<T, Or<GET_DATATYPE_POLICY, POLICY, GET_DATATYPE_POLICY::NO_DECAY, GET_DATATYPE_POLICY::ALLOW_BASEARRAY>::value>() iferr_return;
	return t->GetPointerType();
}

template <GET_DATATYPE_POLICY POLICY, typename T> inline Result<const DataType*> PrivateGetDataType(StrongRef<T>*, OverloadRank0)
{
	iferr_scope;
	const DataType* t = CheckedGetDataType<T, Or<GET_DATATYPE_POLICY, POLICY, GET_DATATYPE_POLICY::NO_DECAY, GET_DATATYPE_POLICY::ALLOW_BASEARRAY>::value>() iferr_return;
	return t->GetStrongReferenceType();
}

template <GET_DATATYPE_POLICY POLICY, typename T> inline Result<const DataType*> PrivateGetDataType(StrongCOWRef<T>*, OverloadRank0)
{
	iferr_scope;
	const DataType* t = CheckedGetDataType<T, Or<GET_DATATYPE_POLICY, POLICY, GET_DATATYPE_POLICY::NO_DECAY, GET_DATATYPE_POLICY::ALLOW_BASEARRAY>::value>() iferr_return;
	return t->GetCOWReferenceType();
}

template <GET_DATATYPE_POLICY POLICY, typename T> inline Result<const DataType*> PrivateGetDataType(UniqueRef<T>*, OverloadRank0)
{
	iferr_scope;
	const DataType* t = CheckedGetDataType<T, Or<GET_DATATYPE_POLICY, POLICY, GET_DATATYPE_POLICY::NO_DECAY, GET_DATATYPE_POLICY::ALLOW_BASEARRAY>::value>() iferr_return;
	return t->GetUniqueReferenceType();
}

template <GET_DATATYPE_POLICY POLICY, typename T> inline Result<const DataType*> PrivateGetDataType(Block<T>*, OverloadRank0)
{
	iferr_scope;
	const DataType* t = CheckedGetDataType<T, Or<GET_DATATYPE_POLICY, POLICY, GET_DATATYPE_POLICY::NO_DECAY, GET_DATATYPE_POLICY::ALLOW_BASEARRAY>::value>() iferr_return;
	return t->GetBlockType();
}

template <GET_DATATYPE_POLICY POLICY, typename T> inline Result<const DataType*> PrivateGetDataType(StridedBlock<T>*, OverloadRank0)
{
	iferr_scope;
	const DataType* t = CheckedGetDataType<T, Or<GET_DATATYPE_POLICY, POLICY, GET_DATATYPE_POLICY::NO_DECAY, GET_DATATYPE_POLICY::ALLOW_BASEARRAY>::value>() iferr_return;
	return t->GetStridedBlockType();
}

template <typename T> class Opt;

template <GET_DATATYPE_POLICY POLICY, typename T> inline Result<const DataType*> PrivateGetDataType(Opt<T>*, OverloadRank0)
{
	iferr_scope;
	const DataType* t = CheckedGetDataType<T, Or<GET_DATATYPE_POLICY, POLICY, GET_DATATYPE_POLICY::NO_DECAY, GET_DATATYPE_POLICY::ALLOW_BASEARRAY>::value>() iferr_return;
	return t->GetOptionalType();
}

template <GET_DATATYPE_POLICY POLICY, typename T> inline Result<const DataType*> PrivateGetDataType(Result<T>*, OverloadRank0)
{
	iferr_scope;
	const DataType* t = CheckedGetDataType<T, Or<GET_DATATYPE_POLICY, POLICY, GET_DATATYPE_POLICY::NO_DECAY, GET_DATATYPE_POLICY::ALLOW_BASEARRAY>::value>() iferr_return;
	return t->GetResultType();
}

template <GET_DATATYPE_POLICY POLICY, typename T> inline Result<const DataType*> PrivateGetDataType(OpaquePtr<T>*, OverloadRank0)
{
	iferr_scope;
	const DataType* t = CheckedGetDataType<T, Or<GET_DATATYPE_POLICY, POLICY, GET_DATATYPE_POLICY::NO_DECAY, GET_DATATYPE_POLICY::ALLOW_BASEARRAY>::value>() iferr_return;
	return t->GetOpaqueType();
}

#ifdef MAXON_COMPILER_MSVC
template <GET_DATATYPE_POLICY POLICY> struct PrivateMSVCPolicyHack
{
	static const Int value = Int(POLICY);
};

template <GET_DATATYPE_POLICY POLICY, typename T> inline typename std::enable_if<(PrivateMSVCPolicyHack<POLICY>::value & Int(GET_DATATYPE_POLICY::ALLOW_BASEARRAY)) != 0, Result<const DataType*>>::type PrivateGetDataType(BaseArray<T>*, OverloadRank0)
{
	iferr_scope;
	const DataType* t = CheckedGetDataType<T, Or<GET_DATATYPE_POLICY, POLICY, GET_DATATYPE_POLICY::NO_DECAY>::value>() iferr_return;
	return ParametricTypes::BaseArray().Instantiate(t);
}
#else
template <GET_DATATYPE_POLICY POLICY, typename T> inline typename std::enable_if<(Int(POLICY) & Int(GET_DATATYPE_POLICY::ALLOW_BASEARRAY)) != 0, Result<const DataType*>>::type PrivateGetDataType(BaseArray<T>*, OverloadRank0)
{
	iferr_scope;
	const DataType* t = CheckedGetDataType<T, Or<GET_DATATYPE_POLICY, POLICY, GET_DATATYPE_POLICY::NO_DECAY>::value>() iferr_return;
	return ParametricTypes::BaseArray().Instantiate(t);
}
#endif

template <GET_DATATYPE_POLICY POLICY, typename... T> inline Result<const TupleDataType*> PrivateGetDataType(Tuple<T...>*, OverloadRank0)
{
	iferr_scope;
	// We assume that the compilers will use the same layout for a class with a member of type A& as for a class with a corresponding member of type A*.
	// Then we can allow references for the tuple members.
	static_assert(And<(std::is_standard_layout<T>::value || std::is_reference<T>::value)...>::value, "The DataType of a tuple with non-standard-layout members can't be constructed automatically.");
	Result<const DataType*> types[] = {CheckedGetDataType<T, Or<GET_DATATYPE_POLICY, POLICY, GET_DATATYPE_POLICY::NO_DECAY, GET_DATATYPE_POLICY::ALLOW_BASEARRAY>::value>()...};
	const TupleDataType* tupleType = DataTypeLib::GetTupleType(types) iferr_return;
	DebugAssert(!tupleType || tupleType->GetSize() == SIZEOF(Tuple<T...>)); // GetTupleType assumes the layout of a struct with members T..., this may differ from the layout of our Tuple<T...>
	return tupleType;
}

template <GET_DATATYPE_POLICY POLICY, typename R, typename... ARGS> inline Result<const DelegateDataType*> PrivateGetDataType(Delegate<R(ARGS...)>*, OverloadRank2)
{
#ifdef MAXON_COMPILER_INTEL
#pragma warning disable 177
#endif
	Result<const DataType*> types[] = {CheckedGetDataType<ARGS, Or<GET_DATATYPE_POLICY, POLICY, GET_DATATYPE_POLICY::NO_DECAY, GET_DATATYPE_POLICY::ALLOW_BASEARRAY>::value>()..., {}};
	return DataTypeLib::GetDelegateType(CheckedGetDataType<R, Or<GET_DATATYPE_POLICY, POLICY, GET_DATATYPE_POLICY::NO_DECAY, GET_DATATYPE_POLICY::ALLOW_BASEARRAY>::value>(), {types, sizeof...(ARGS)},
																			&reflection::Invocation<R, ARGS...>::InvokeDelegate, (void*) &reflection::DelegateHandlerHelper<R, ARGS...>::Invoke);
#ifdef MAXON_COMPILER_INTEL
#pragma warning disable 177
#endif
}


template <GET_DATATYPE_POLICY POLICY> inline ResultOk<const DataType*> PrivateGetDataType(const DataType**, OverloadRank0)
{
	return DataTypeLib::GetDataTypeType();
}

template <GET_DATATYPE_POLICY POLICY> inline ResultOk<const DataType*> PrivateGetDataType(const TupleDataType**, OverloadRank0)
{
	return DataTypeLib::GetDataTypeType();
}

inline String ToString(const TupleDataType* type, const FormatStatement* formatStatement, Bool = false) { return type ? type->GetId().ToString(formatStatement) : "nullptr"_s; }


template <typename T> void PrivateDataTypeMarker(T*);

//----------------------------------------------------------------------------------------
/// This registry is used to register all primary data types (those which are declared by MAXON_DATATYPE, and
/// interfaces). It does not include compound data types such as array, tuple or reference types.
/// Use DataType::Get() to obtain a DataType for a data type identifier, whether it is primary or compound.
//----------------------------------------------------------------------------------------
MAXON_REGISTRY(const DataType*, DataTypes, "net.maxon.registry.datatypes");

#define PRIVATE_MAXON_DATATYPE_A(type, id, result) \
	void* PrivateDataTypeMarker(type*); \
	MAXON_DECLARATION(const maxon::DataType*, DT_##type, id); \
	template <maxon::GET_DATATYPE_POLICY> inline maxon::result<const maxon::DataType*> PrivateGetDataType(type*, maxon::OverloadRank2) { return DT_##type(); }

// Used internally for scalar types for which no declaration of PrivateConstRefNullValue is needed.
#define MAXON_DATATYPE_SCALAR(type, id) PRIVATE_MAXON_DATATYPE_A(type, id, ResultOk)

#define PRIVATE_MAXON_DATATYPE(type, id) PRIVATE_MAXON_DATATYPE_A(type, id, ResultMemT)

//----------------------------------------------------------------------------------------
/// MAXON_DATATYPE declares a primary DataType for the given @p type. Use this in a header
/// file to be able to use values of @p type for the DataType system.
/// There has to be a matching DataType definition via MAXON_DATATYPE_REGISTER in a cpp file.
/// @code
///	MAXON_DATATYPE(TimeValue, "net.maxon.datatype.timevalue");
/// @endcode
/// You don't have to declare data types for interfaces, this is done automatically.
/// @param[in] type								Type for which a DataType shall be implemented.
/// @param[in] id									Unique identifier of the data type.
//----------------------------------------------------------------------------------------
#define MAXON_DATATYPE(type, id) PRIVATE_MAXON_DATATYPE(type, id) MAXON_ASSERT_LEGAL_LAYOUT(type)


#if !defined(MAXON_API) || defined(DOXYGEN)

#define PRIVATE_MAXON_DATATYPE_REGISTER(type, ret, flags) \
	MAXON_UNIT_REGISTER_CHECK("MAXON_DATATYPE_REGISTER"); \
	namespace \
	{ \
		static maxon::DataType g_dataType_##type(DT_##type.GetId(), nullptr, nullptr, (type*) nullptr, (maxon::DataTypeFunctions<type>*) nullptr, flags); \
		static maxon::Result<const maxon::DataType*> InitDataType##type(MAXON_SOURCE_LOCATION_DECLARATION, maxon::Id&) { const maxon::DataType* dt = &g_dataType_##type; return ret; } \
		static maxon::ObjectDefinition g_dataTypeDef_##type(DT_##type.GetId(), &InitDataType##type, &maxon::DataType::PrivateReset, (maxon::DataTypes::Registry*) nullptr, &maxon::g_translationUnit, __FILE__, maxon::EntityBase::FLAGS::NONE); \
	}

#define PRIVATE_MAXON_DATATYPE_REGISTER_ENUM(enumtype, id, size, flags, names, ...) \
	namespace \
	{ \
		static maxon::DataType g_dataType_##enumtype; \
		static maxon::Result<const maxon::DataType*> InitDataType##enumtype(MAXON_SOURCE_LOCATION_DECLARATION, maxon::Id& objectId) { __VA_ARGS__; return maxon::DataTypeLib::RegisterEnumType(g_dataType_##enumtype, objectId, size, std::is_signed<std::underlying_type<enumtype>::type>::value, flags, values, names); } \
		static maxon::ObjectDefinition g_dataTypeRef_##enumtype(maxon::LiteralId(id), &InitDataType##enumtype, &maxon::DataType::PrivateReset, (maxon::DataTypes::Registry*) nullptr, &maxon::g_translationUnit, __FILE__, maxon::EntityBase::FLAGS::NONE); \
	}

//----------------------------------------------------------------------------------------
/// MAXON_DATATYPE_REGISTER defines the implementation of a maxon::DataType for the given @p type.
/// This macro has to be used in a cpp file, and there has to be a corresponding
/// MAXON_DATATYPE in a header file. For each type, there must be exactly one MAXON_DATATYPE_REGISTER
/// for the whole application. The usage is as easy as
/// @code
/// MAXON_DATATYPE_REGISTER(TimeValue);
/// @endcode
/// However, this assumes that the appropriate functions for comparison, string conversion etc. are
/// available in the current scope.
///
/// If the type is a struct type consisting of public member variables,
/// you can use MAXON_DATATYPE_REGISTER_STRUCT to make the members of your type accessible to the DataType system.
/// @param[in] type								Type for which a DataType shall be implemented.
//----------------------------------------------------------------------------------------
#define MAXON_DATATYPE_REGISTER(type) PRIVATE_MAXON_DATATYPE_REGISTER(type, dt, maxon::VALUEKIND::NONE)

#ifdef MAXON_COMPILER_INTEL
	#define PRIVATE_MAXON_DATATYPE_LOCAL_STATIC static
#else
	#define PRIVATE_MAXON_DATATYPE_LOCAL_STATIC
#endif

//----------------------------------------------------------------------------------------
/// MAXON_DATATYPE_LOCAL can be used for DataType declarations which need not be publicly visible
/// in a header file. It comprises the declaration (which would normally done by MAXON_DATATYPE
/// in a header file) and its implementation (normally done by MAXON_DATATYPE_REGISTER).
/// MAXON_DATATYPE_LOCAL has to be placed in a cpp file. The functions for comparison, string conversion etc. are
/// taken from the current scope.
/// @param[in] type								Type for which a local DataType shall be declared and implemented.
/// @param[in] id									The unique identifier of the local data type.
//----------------------------------------------------------------------------------------
#define MAXON_DATATYPE_LOCAL(type, id) PRIVATE_MAXON_DATATYPE_LOCAL_STATIC PRIVATE_MAXON_DATATYPE(type, id); \
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(DT_##type,, id); \
	MAXON_DATATYPE_REGISTER(type)


#define PRIVATE_MAXON_DATATYPE_REGISTER_STRUCT_INIT(x, i, a) {maxon::GetDataType<decltype(std::declval<a>().x)>(), #x}
#define PRIVATE_MAXON_DATATYPE_REGISTER_STRUCT_OFFSETS(x, i, a) (maxon::Int) offsetof(a, x)

#define PRIVATE_MAXON_DATATYPE_REGISTER_STRUCT_B(Type, line, count, ...) \
	static maxon::Result<const maxon::DataType*> PrivateSetStructType##line##Type(const maxon::DataType* dt) \
	{ \
		iferr_scope; \
		maxon::Tuple<const maxon::DataType*, const maxon::Char*> array[] = {MAXON_MAKE_COMMA_LIST(PRIVATE_MAXON_DATATYPE_REGISTER_STRUCT_INIT, Type, , __VA_ARGS__)}; \
		maxon::Member members[std::extent<decltype(array)>::value]; \
		maxon::Member* mb = members; \
		for (const auto& m : array) \
		{ \
			mb->type = m.first; \
			mb->name.Init(m.second) iferr_return; \
			++mb; \
		} \
		const maxon::TupleDataType* s = maxon::DataTypeLib::GetTupleType(members) iferr_return; \
		maxon::Int offsets[] = {MAXON_MAKE_COMMA_LIST(PRIVATE_MAXON_DATATYPE_REGISTER_STRUCT_OFFSETS, Type, , __VA_ARGS__)}; \
		const_cast<maxon::DataType*>(dt)->PrivateSetStructType(s, &s->GetTypeArguments(), offsets); return dt; \
	} \
	PRIVATE_MAXON_DATATYPE_REGISTER(Type, PrivateSetStructType##line##Type(dt), maxon::VALUEKIND::STRUCT)


#define PRIVATE_MAXON_DATATYPE_REGISTER_STRUCT_A(type, line, count, ...) PRIVATE_MAXON_DATATYPE_REGISTER_STRUCT_B(type, line, count, __VA_ARGS__)

//----------------------------------------------------------------------------------------
/// MAXON_DATATYPE_REGISTER_STRUCT defines the implementation of a DataType for the given #type,
/// and it also sets up an underlying tuple type which is composed of the members given by ... .
/// You can use this instead of MAXON_DATATYPE_REGISTER for a struct type consisting of public member variables,
/// then the members of your type are accessible to the DataType system.
///
/// This macro has to be used in a cpp file, and there has to be a corresponding
/// MAXON_DATATYPE in a header file.
/// @code
/// struct Member
/// {
/// 	const DataType* type;
/// 	Id name;
/// };
///
/// MAXON_DATATYPE_REGISTER_STRUCT(Member, type, name);
/// @endcode
/// @param[in] type								Type for which a DataType shall be implemented.
/// @param[in] ...								List of the names of the member variables of #type.
//----------------------------------------------------------------------------------------
#define MAXON_DATATYPE_REGISTER_STRUCT(type, ...) PRIVATE_MAXON_DATATYPE_REGISTER_STRUCT_A(type, __LINE__, MAXON_VA_NARGS(__VA_ARGS__), __VA_ARGS__)

#endif

// predefine the basic types, all the other types need to be declared where they are made public

MAXON_DATATYPE_SCALAR(Char, "char");
MAXON_DATATYPE_SCALAR(UChar, "uchar");

MAXON_DATATYPE_SCALAR(Int16, "int16");
MAXON_DATATYPE_SCALAR(UInt16, "uint16");

MAXON_DATATYPE_SCALAR(Int32, "int32");
MAXON_DATATYPE_SCALAR(UInt32, "uint32");

MAXON_DATATYPE_SCALAR(Int64, "int64");
MAXON_DATATYPE_SCALAR(UInt64, "uint64");

MAXON_DATATYPE_SCALAR(Utf16Char, "utf16char");
MAXON_DATATYPE_SCALAR(Utf32Char, "utf32char");

MAXON_DATATYPE_SCALAR(Float32, "float32");
MAXON_DATATYPE_SCALAR(Float64, "float64");

MAXON_DATATYPE_SCALAR(Bool, "bool");

MAXON_DATATYPE_SCALAR(Byte, "byte");

MAXON_DATATYPE_SCALAR(Id, "net.maxon.datatype.id");
MAXON_DATATYPE_SCALAR(InternedId, "net.maxon.datatype.internedid");
MAXON_DATATYPE_SCALAR(Data, "net.maxon.datatype.data");
MAXON_DATATYPE_SCALAR(UnitType, "net.maxon.datatype.unittype");

MAXON_DATATYPE(SourceLocation, "net.maxon.datatype.sourcelocation");
MAXON_DATATYPE(DelegateBase, "net.maxon.datatype.delegatebase");

//----------------------------------------------------------------------------------------
/// The main purpose of the type AInt is as template argument for GetDataType:
/// GetDataType<AInt>() returns the architecture-dependent Int type, while
/// GetDataType<Int>() returns either the Int64 or Int32 type, depending on the architecture
/// which is used for the compilation and which sets Int just as an alias for either Int64 or Int32.
///
/// AInt is layout-compatible with Int.
//----------------------------------------------------------------------------------------
struct AInt
{
	Int value;

	operator Int() const
	{
		return value;
	}
};

MAXON_DATATYPE(AInt, "int");

//----------------------------------------------------------------------------------------
/// The main purpose of the type AUInt is as template argument for GetDataType:
/// GetDataType<AUInt>() returns the architecture-dependent UInt type, while
/// GetDataType<UInt>() returns either the UInt64 or UInt32 type, depending on the architecture
/// which is used for the compilation and which sets UInt just as an alias for either UInt64 or UInt32.
///
/// AUInt is layout-compatible with UInt.
//----------------------------------------------------------------------------------------
struct AUInt
{
	UInt value;

	operator UInt() const
	{
		return value;
	}
};

MAXON_DATATYPE(AUInt, "uint");

//----------------------------------------------------------------------------------------
/// The main purpose of the type AFloat is as template argument for GetDataType:
/// GetDataType<AFloat>() returns the architecture-dependent Float type, while
/// GetDataType<Float>() returns either the Float64 or Float32 type, depending on the architecture
/// which is used for the compilation and which sets Float just as an alias for either Float64 or Float32.
///
/// AFloat is layout-compatible with Float.
//----------------------------------------------------------------------------------------
struct AFloat
{
	Float value;

	operator Float() const
	{
		return value;
	}
};

MAXON_DATATYPE(AFloat, "float");


template <Bool, typename T> inline Result<const DataType*> PrivateGetEnumDataType(T*, OverloadRank0)
{
	return PrivateGetDataType<GET_DATATYPE_POLICY::NONE>((typename UIntType<sizeof(T)>::type*) nullptr, OVERLOAD_MAX_RANK);
}

template <GET_DATATYPE_POLICY POLICY, typename T> inline typename std::enable_if<std::is_enum<T>::value, Result<const DataType*>>::type PrivateGetDataType(T*, OverloadRank0)
{
	return PrivateGetEnumDataType<false>((T*) nullptr, OVERLOAD_MAX_RANK);
}


template <GET_DATATYPE_POLICY POLICY> inline ResultOk<const DataType*> PrivateGetDataType(ParametricType*, OverloadRank0)
{
	return DataTypeLib::GetParametricTypeType();
}

template <GET_DATATYPE_POLICY POLICY> inline ResultOk<const DataType*> PrivateGetDataType(ComponentDescriptor*, OverloadRank0)
{
	return DataTypeLib::GetComponentDescriptorType();
}


// The declaration of this function has to be after the MAXON_DATATYPE_SCALAR macros because for scalar types
// only function declarations from the template definition context are considered.
// So CheckedGetDataType could not see PrivateGetDataType for scalar types if MAXON_DATATYPE_SCALAR followed CheckedGetDataType.
template <typename T, GET_DATATYPE_POLICY POLICY> inline Result<const DataType*> CheckedGetDataType()
{
	iferr_scope;
	using Type = typename StandardType<typename std::decay<T>::type>::type;
#ifdef MAXON_COMPILER_MSVC
	const Bool isIncomplete = !IsComplete<Type, __COUNTER__>::value;
#else
	const Bool isIncomplete = false;
#endif
	const Bool isVoid = std::is_void<Type>::value;
	const Bool isNullPtr = std::is_same<Type, std::nullptr_t>::value;
	const Bool isGeneric = std::is_same<Type, Generic>::value;
	using Simd = IsSimdElementType<Type>;
	static_assert(!isIncomplete || isVoid || isNullPtr || isGeneric || (POLICY & GET_DATATYPE_POLICY::RESULT_FOR_UNKNOWN_MASK), "Attempt to get DataType of incomplete type.");
	static_assert(!Simd::value || ((SIZEOF(typename Simd::type) % (Simd::STRIDE * SIZEOF(typename Simd::ValueType))) == 0), "Wrong size.");
	const DataType* t;
	if (isVoid)
	{
		t = DataTypeLib::GetVoidType();
	}
	else if (isNullPtr)
	{
		t = DataTypeLib::GetNullptrType();
	}
	else if (isGeneric || (isIncomplete && (POLICY & GET_DATATYPE_POLICY::GENERIC_FOR_UNKNOWN)))
	{
		t = DataTypeLib::GetGenericType();
	}
	else if (isIncomplete)
	{
		return UnregisteredDataTypeErrorObject();
	}
	else if (Simd::value)
	{
		t = CheckedGetDataType<typename Simd::ValueType, POLICY>() iferr_return;
		t = DataTypeLib::GetSimdElementType(t, SIZEOF(typename Simd::type) / (Simd::STRIDE * SIZEOF(typename Simd::ValueType)), Simd::STRIDE) iferr_return;
	}
	else
	{
		// This uses argument-dependent lookup, so PrivateGetDataType is searched for also in the namespace of T.
		t = PrivateGetDataType<POLICY>((typename std::conditional<isVoid || isGeneric || isNullPtr || isIncomplete || Simd::value, Int, Type>::type*) nullptr, OVERLOAD_MAX_RANK) iferr_return;
	}
	if (POLICY & GET_DATATYPE_POLICY::NO_DECAY)
	{
		if (std::is_const<typename std::remove_reference<T>::type>::value)
			t = t->GetConstType().GetPointer();
		if (std::is_lvalue_reference<T>::value && t)
			t = t->GetLVReferenceType().GetPointer();
		else if (std::is_rvalue_reference<T>::value && t)
			t = t->GetRVReferenceType().GetPointer();
		if (!t)
			return OutOfMemoryError(MAXON_SOURCE_LOCATION);
	}
	return t;
}


/// @private
class DataTypeCache
{
public:
	const DataType* Get() const
	{
		if (MAXON_UNLIKELY(!_type))
		{
			Init(true) iferr_ignore("Error message written by Init.");
		}
		return _type;
	}

	using InitFunction = Result<const DataType*>();

	Result<void> Init(Bool showMsg) const;

	DataTypeCache(InitFunction* init, ModuleInfo* module);

private:
	mutable const DataType* _type = nullptr;
	const DataTypeCache* const _next;
	InitFunction* const _init;

	friend class ObjectModel;
};

/// @private
template <typename T, GET_DATATYPE_POLICY POLICY, Bool ELEMENTARY> class DataTypeCacheInstance
{
public:
	static const DataType* Get()
	{
		return _instance.Get();
	}

private:
	static const DataTypeCache _instance;
};

template <typename T, GET_DATATYPE_POLICY POLICY, Bool ELEMENTARY> const DataTypeCache DataTypeCacheInstance<T, POLICY, ELEMENTARY>::_instance(&CheckedGetDataType<T, POLICY>, &PRIVATE_MAXON_MODULE);

template <typename T, GET_DATATYPE_POLICY POLICY> class DataTypeCacheInstance<T, POLICY, true>
{
public:
	static const DataType* Get()
	{
		return CheckedGetDataType<T, POLICY>() iferr_cannot_fail("For elementary types this can't fail.");
	}
};

//----------------------------------------------------------------------------------------
/// Returns the DataType representation of T. This covers not only primary datatypes
/// which have been registered direcly with MAXON_DATATYPE_REGISTER, but also compound types
/// which are derived from other types (such as arrays, pointers, references, tuples).
/// @tparam T											Type for which the DataType shall be obtained.
/// @tparam POLICY								An optional policy for the operation.
/// @return												The DataType representation for T.
//----------------------------------------------------------------------------------------
template <typename T, GET_DATATYPE_POLICY POLICY> inline const DataType* GetDataType()
{
	using TT = typename std::conditional<Bool(POLICY & GET_DATATYPE_POLICY::NO_DECAY), T, typename std::decay<T>::type>::type;
	using DT = typename std::decay<TT>::type;
	const Bool ELEMENTARY = std::is_fundamental<DT>::value || std::is_enum<DT>::value || std::is_same<DT, const DataType*>::value || std::is_pointer<decltype(PrivateDataTypeMarker((DT*) nullptr))>::value;
	return DataTypeCacheInstance<TT, POLICY, std::is_same<TT, DT>::value && ELEMENTARY>::Get();
}

template <GET_DATATYPE_POLICY POLICY> inline ResultOk<const DataType*> PrivateGetDataType(Generic*, OverloadRank0)
{
	static_assert((Int(POLICY) & Int(GET_DATATYPE_POLICY::RESULT_FOR_UNKNOWN_MASK)) != 0, "Attempt to get DataType of Generic.");
	return DataTypeLib::GetGenericType();
}


MAXON_DATATYPE(ConstDataPtr, "net.maxon.datatype.constdataptr");
MAXON_DATATYPE(DataPtr, "net.maxon.datatype.dataptr");
MAXON_DATATYPE(MoveDataPtr, "net.maxon.datatype.movedataptr");
MAXON_DATATYPE(ForwardingDataPtr, "net.maxon.datatype.forwardingdataptr");


//----------------------------------------------------------------------------------------
/// Member represents a member of struct-like types or function signatures. A member is just a pair of a type and a name.
//----------------------------------------------------------------------------------------
struct Member
{
	MAXON_IMPLICIT Member(const DataType* t = nullptr, const InternedId& n = InternedId()) : type(t), name(n)
	{
	}

	template <typename T> static Member Create(const InternedId& n)
	{
		return {GetDataType<T, GET_DATATYPE_POLICY::NO_DECAY>(), n};
	}

	String ToString(const FormatStatement* fmt) const;

	MAXON_OPERATOR_EQUALITY_HASHCODE(Member, type, name);

	Bool operator <(const Member& other) const
	{
		return LexicographicalLessThan(name, other.name, type ? type->GetId() : NullValue<const Id&>(), other.type ? other.type->GetId() : NullValue<const Id&>());
	}

	MAXON_OPERATOR_INEQUALITY(Member);

	const DataType* type;	///< The type of the member.
	InternedId name;			///< The name of the member, this may be empty where anonymous members are allowed.
};

MAXON_DATATYPE(Member, "net.maxon.datatype.member");

namespace details
{

template <typename T, const InternedId& ID> class MemberTypeBase : public Member
{
public:
	using Type = T;

	static const InternedId& GetId()
	{
		return ID;
	}

	static const Member& GetInstance()
	{
		// We can't use a static class member because this would require the DataType system at DLL load
		static const MemberTypeBase instance;
		return instance;
	}

	MemberTypeBase() : Member(GetDataType<T, GET_DATATYPE_POLICY::NO_DECAY>(), ID)
	{
	}
};

}

template <typename T, const InternedId& ID = InternedId::NULL_VALUE> class MemberType : public maxon::details::MemberTypeBase<T, ID>
{
public:
	using GetType = T&;

	static const T& Get(const Generic* ptr)
	{
		return *reinterpret_cast<const T*>(ptr);
	}

	static T& Get(Generic* ptr)
	{
		return *reinterpret_cast<T*>(ptr);
	}
};

template <typename T, const InternedId& ID> class MemberType<T&, ID> : public maxon::details::MemberTypeBase<T&, ID>
{
public:
	using GetType = T&;

	static T& Get(const Generic* ptr)
	{
		return **reinterpret_cast<T* const*>(ptr);
	}
};

template <typename T, const InternedId& ID> class MemberType<T&&, ID> : public maxon::details::MemberTypeBase<T&&, ID>
{
public:
	using GetType = T&&;

	static T&& Get(const Generic* ptr)
	{
		return std::move(**reinterpret_cast<T* const*>(ptr));
	}
};


template <typename T> struct GetMemberType
{
	using type = MemberType<T>;
	static const Bool NAMED = false;
};

template <typename T, const InternedId& ID> struct GetMemberType<MemberType<T, ID>>
{
	using type = MemberType<T, ID>;
	static const Bool NAMED = true;
};

template <typename T> struct GetMemberType<MemberType<T, InternedId::NULL_VALUE>>
{
	using type = MemberType<T>;
	static const Bool NAMED = false;
};


template <typename T> struct SubstituteReferenceByPointer
{
	using type = T;
};

template <typename T> struct SubstituteReferenceByPointer<T&>
{
	using type = T*;
};

template <typename T> struct SubstituteReferenceByPointer<T&&>
{
	using type = T*;
};


template <typename... T> class NamedTuple
{
public:
	using TupleType = Tuple<typename GetMemberType<T>::type::Type...>;
	using TupleTypeWithPtrsForRefs = Tuple<typename SubstituteReferenceByPointer<typename GetMemberType<T>::type::Type>::type...>;

	static const Bool ALL_NAMED = And<GetMemberType<T>::NAMED...>::value;

	using Pack = ParameterPack<T...>;

	static const Block<const Member>& GetMembers()
	{
		if (sizeof...(T) == 0)
			return maxon::NullValue<const Block<const Member>&>();
		// We can't use a static class member because this would require the DataType system at DLL load.
		// Therefore use lazy initialization.
		static const typename std::conditional<sizeof...(T) == 0, Int, Helper>::type helper{};
		return reinterpret_cast<const Helper&>(helper).block;
	}

	static const TupleDataType* GetDataType()
	{
		return static_cast<const TupleDataType*>(maxon::GetDataType<NamedTuple>());
	}

	template <typename OTHER> using ContainsAll = typename Pack::template ContainsAll<typename OTHER::Pack>;

private:
	struct Helper
	{
		Block<const Member> block;
#ifndef MAXON_COMPILER_INTEL
		Member members[sizeof...(T) > 0 ? sizeof...(T) : 1];
		Helper() :  block(members), members{GetMemberType<T>::type::GetInstance()...}
		{
		}
#else
		// Intel compiler 17 produces wrong code with the code from above
		Helper()
		{
			static const Member members[sizeof...(T)] = {GetMemberType<T>::type::GetInstance()...};
			block = members;
		}
#endif
	};
};


template <GET_DATATYPE_POLICY POLICY, typename... T> inline Result<const TupleDataType*> PrivateGetDataType(NamedTuple<T...>*, OverloadRank0)
{
	return DataTypeLib::GetTupleType(NamedTuple<T...>::GetMembers());
}


enum class INNERMOST_MEMBER : Int32
{
} MAXON_ENUM_ORDERED_LIST(INNERMOST_MEMBER);



//----------------------------------------------------------------------------------------
/// TypeArguments are usually set for a DataType if it is an instantiation of a ParametricType.
/// For example the type @c{Tuple<Int, Bool, String>} is an instantiation of the parametric type
/// Tuple with the type arguments @c{(Int, Bool, String)}, and the type Vector
/// is an instantiation of ParametricTypes::Vec with the type arguments @c{(Float, 3)}.
///
/// There are two kinds of type arguments:
/// - They can be types itself (like for Tuple), these are found in #args.
///   Optionally these arguments can even specify a name together with the type. This is used
///   e.g. for NamedTuple types like @c{NamedTuple<Int count, Bool valid>}.
/// - They can be of integral type (like the dimension for Vec), these are found in #iargs.
//----------------------------------------------------------------------------------------
struct TypeArguments
{
	BaseArray<INNERMOST_MEMBER> toInnermost;

	// This maps from an INNERMOST_MEMBER to a member index at the level of the array. For example, the innermost member with index 4 of an array of type [A, [B, C], [D, E], F]
	// has type E. It is contained in the member [D, E] at index 2 of the array, and within this member it has the innermost member index 1. So _fromInnermost[4] = (2, 1)
	BaseArray<Tuple<Int32, INNERMOST_MEMBER>> fromInnermost;

	/// The integral type arguments.
	BaseArray<Int64> iargs;

	/// The number of type arguments which are types.
	Int count;

	/// The type arguments which are (optionally named) types.
	Member args[MAXON_FLEXIBLE_ARRAY_LENGTH];

	//----------------------------------------------------------------------------------------
	/// Returns the type arguments which are types as a block.
	//----------------------------------------------------------------------------------------
	Block<const Member> ToBlock() const
	{
		return {args, count};
	}

	//----------------------------------------------------------------------------------------
	/// Returns the type argument at the given #index.
	//----------------------------------------------------------------------------------------
	const Member& operator [](Int index) const
	{
		DebugAssert(UInt(index) <= UInt(count));
		return args[index];
	}

	using ValueType = Member;
	using ConstIterator = BaseIterator<const TypeArguments, false>;

	//----------------------------------------------------------------------------------------
	/// Gets an iterator pointing to the first type argument.
	/// @return												Iterator for the first type argument.
	//----------------------------------------------------------------------------------------
	ConstIterator Begin() const
	{
		return ConstIterator(args);
	}

	//----------------------------------------------------------------------------------------
	/// Returns and iterator pointing to the end of the type arguments (one behind last).
	/// @return												Iterator for the end of the type arguments.
	//----------------------------------------------------------------------------------------
	ConstIterator End() const
	{
		return ConstIterator(args + count);
	}

	//----------------------------------------------------------------------------------------
	/// Searches for a named type argument which uses the given #name and returns its index.
	/// If no such argument is found, -1 is returned. The function doesn't check for duplicates.
	/// @param[in] name								Name to search. If this is empty, -1 is returned.
	/// @return												Index of the matching type argument, or -1.
	//----------------------------------------------------------------------------------------
	Int FindIndex(const Id& name) const
	{
		if (name.IsPopulated())
		{
			for (Int i = 0; i < count; ++i)
			{
				if (args[i].name == name)
					return i;
			}
		}
		return -1;
	}

	//----------------------------------------------------------------------------------------
	/// @copydoc FindIndex
	//----------------------------------------------------------------------------------------
	Int FindIndex(const InternedId& name) const
	{
		if (name.IsPopulated())
		{
			for (Int i = 0; i < count; ++i)
			{
				if (args[i].name == name)
					return i;
			}
		}
		return -1;
	}

	Bool operator ==(const TypeArguments& other) const
	{
		return ToBlock() == other.ToBlock();
	}

	Bool operator !=(const TypeArguments& other) const
	{
		return !this->operator ==(other);
	}

	UInt GetHashCode() const
	{
		return ToBlock().GetHashCode();
	}

	static void Free(const TypeArguments*& ptr)
	{
		if (ptr)
		{
			for (Int i = 0; i < ptr->count; ++i)
			{
				ptr->args[i].~Member();
			}
			const_cast<TypeArguments*>(ptr)->iargs.Reset();
			const_cast<TypeArguments*>(ptr)->fromInnermost.Reset();
			const_cast<TypeArguments*>(ptr)->toInnermost.Reset();
			DeleteMem(ptr);
		}
	}

	using IsAllocType = std::true_type;

	~TypeArguments() = delete;
};


//----------------------------------------------------------------------------------------
/// A TupleValue is returned by DataType::GetTuple() if the type represents a tuple data type.
/// The members of the tuple value can be accessed through the functions of this class.
//----------------------------------------------------------------------------------------
class TupleValue
{
public:
	//----------------------------------------------------------------------------------------
	/// Returns a reference to the value of the tuple member at @p index.
	/// @tparam T											Type of the member.
	/// @param[in] index							Index of the member.
	/// @param[in] type								Tuple data type of this TupleValue.
	/// @return												Reference to the member value.
	//----------------------------------------------------------------------------------------
	template <typename T> const T& Get(Int index, const TupleDataType* type) const
	{
		DebugAssert((type->GetTypeArguments()[index].type == GetDataType<T, GET_DATATYPE_POLICY::GENERIC_FOR_UNKNOWN>()));
		return *(const T*) ((const Char*) this + DataTypeLib::GetTupleMemberOffsets(type)[index]);
	}

	//----------------------------------------------------------------------------------------
	/// Returns a reference to the value of the tuple member at @p index.
	/// @tparam T											Type of the member.
	/// @param[in] index							Index of the member.
	/// @param[in] type								Tuple data type of this TupleValue.
	/// @return												Reference to the member value.
	//----------------------------------------------------------------------------------------
	template <typename T> T& Get(Int index, const TupleDataType* type)
	{
		return MAXON_NONCONST_COUNTERPART(Get<T>(index, type));
	}

	//----------------------------------------------------------------------------------------
	/// Returns a reference to the tuple value of the tuple member at @p index.
	/// The corresponding member type has to be a tuple data type.
	/// @param[in] index							Index of the member.
	/// @param[in] type								Tuple data type of this TupleValue.
	/// @return												Reference to the member value.
	//----------------------------------------------------------------------------------------
	const TupleValue& GetTuple(Int index, const TupleDataType* type) const
	{
		DebugAssert(type->GetTypeArguments()[index].type->GetValueKind() & VALUEKIND::TUPLE_MASK);
		return *(const TupleValue*) ((const Char*) this + DataTypeLib::GetTupleMemberOffsets(type)[index]);
	}

	//----------------------------------------------------------------------------------------
	/// Returns a reference to the tuple value of the tuple member at @p index.
	/// The corresponding member type has to be a tuple data type.
	/// @param[in] index							Index of the member.
	/// @param[in] type								Tuple data type of this TupleValue.
	/// @return												Reference to the member value.
	//----------------------------------------------------------------------------------------
	TupleValue& GetTuple(Int index, const TupleDataType* type)
	{
		return MAXON_NONCONST_COUNTERPART(GetTuple(index, type));
	}
};


//----------------------------------------------------------------------------------------
/// FunctionDataType corresponds to the C++ type maxon::Function.
/// Whenever the flag VALUEKIND::FUNCTION is set for a DataType, you can safely cast it to
/// FunctionDataType which gives you access to the input and output types of the function.
//----------------------------------------------------------------------------------------
class FunctionDataType : public DataType
{
public:
	//----------------------------------------------------------------------------------------
	/// Returns the output types (of the result) of a function.
	//----------------------------------------------------------------------------------------
	const TupleDataType* GetOutputs() const
	{
		return static_cast<const TupleDataType*>(GetTypeArguments()[0].type);
	}

	//----------------------------------------------------------------------------------------
	/// Returns the input types (of the parameters) of a function.
	//----------------------------------------------------------------------------------------
	const TupleDataType* GetInputs() const
	{
		return static_cast<const TupleDataType*>(GetTypeArguments()[1].type);
	}
};


template <typename T> inline void DataType::AssertType() const
{
#ifdef MAXON_TARGET_DEBUG
	AssertSame(GetDataType<T>());
#endif
}

template <typename T> inline Bool DataType::Is() const
{
	return this == GetDataType<T>();
}

template <typename DEST, typename SRC> inline Result<void> DataType::AddConversion(CONVERSION_FLAGS kind, Result<void> (*conversion) (DEST&, const SRC&))
{
	return GetDataType<DEST>()->AddConversion(GetDataType<SRC>(), kind, [conversion] (const DataPtr& dest, const ConstDataPtr& src) -> Result<void>
	{
		return conversion(*(DEST*) dest.PrivateGetPtr(), *(const SRC*) src.PrivateGetPtr());
	});
}

template <typename T> Bool DataType::IsCastableFrom() const
{
	return IsCastableFrom(GetDataType<T>());
}

template <typename T> Bool DataType::IsCastableTo() const
{
	return GetDataType<T, GET_DATATYPE_POLICY::GENERIC_FOR_UNKNOWN>()->IsCastableFrom(this);
}

template <typename T> inline Result<Data> Data::Create()
{
	Data d;

	iferr (d.Init(maxon::GetDataType<T>()))
		return err;

	return d;
}

inline Result<Data> Data::GetCopy() const
{
	Data tmp;
	Result<void> r = tmp.Set(*this);
	if (MAXON_UNLIKELY(r == FAILED))
		return r.GetError();
	return std::move(tmp);
}

template <typename T> inline void Data::InitSet(T&& data)
{
	static_assert(!std::is_same<T, const Data&>::value, "const Data& not allowed with Data::InitSet()");
	static_assert(!std::is_same<T, Data&>::value, "Data& not allowed with Data::InitSet()");

	using Functions = DataTypeFunctions<typename std::decay<T>::type>;
//	static_assert(Functions::FITS_IN_MEMBLOCK, "Data constructor only available for types which fit in a DataMemBlock.");
	const DataType* ti = maxon::GetDataType<T>();
	if (ti)
	{
		Result<void> r = Functions::Init(ti, &_memBlock, std::forward<T>(data));
		if (MAXON_UNLIKELY(r == FAILED))
			ti = nullptr;
	}
	_typeInfo = ti;
}

template <> inline void Data::InitSet(Data&& data)
{
	_typeInfo = nullptr;
	*this = std::move(data);
}

template <typename T> inline Result<void> Data::SetImpl(T&& data, OverloadRank0)
{
	using Functions = DataTypeFunctions<typename std::decay<T>::type>;
	const DataType* ti = maxon::GetDataType<T>();
	if (_typeInfo != ti)
	{
		Reset();
		if (ti)
		{
			Result<void> r = Functions::Init(ti, &_memBlock, std::forward<T>(data));
			if (MAXON_UNLIKELY(r == FAILED))
			{
				return r;
			}
			_typeInfo = ti;
		}
		return OK;
	}
	else if (ti)
	{
		return Functions::Set(ti, &_memBlock, std::forward<T>(data));
	}
	return CreateError(MAXON_SOURCE_LOCATION, ERROR_TYPE::ILLEGAL_ARGUMENT);
}

template <typename T> inline T* Data::GetPtr()
{
	const DataType* t = GetDataType<T, GET_DATATYPE_POLICY::GENERIC_FOR_UNKNOWN>();
	if (std::is_scalar<T>::value && t == _typeInfo)
	{
		// Scalar types always use the _memBlock to directly store their value.
		return reinterpret_cast<T*>(&_memBlock);
	}
	else
	{
		return (T*) GetPtr(t);
	}
}

template <> inline Data* Data::GetPtr<Data>()
{
	return this;
}


template <typename T> inline void ConstDataPtr::Set(const T& value)
{
	_typeInfo = GetDataType<T>();
	_dataPtr = reinterpret_cast<const Generic*>(&value);
}

template <typename T> String ToStringHelper2<T, false>::ToString(const T* object, const FormatStatement* formatStatement, Bool checkDataType)
{
	const DataType* ti = checkDataType ? PrivateGetDataType<GET_DATATYPE_POLICY::ERROR_FOR_UNKNOWN>((T*) nullptr, OVERLOAD_MAX_RANK) iferr_ignore("Error correctly handled by nullptr.") : nullptr;

	if (ti)
		return ti->ToString(object, formatStatement);

	return String::PointerToString(object);
}

template <GET_DATATYPE_POLICY POLICY, typename T, T C> inline Result<const DataType*> PrivateGetDataType(std::integral_constant<T, C>*, OverloadRank0)
{
	iferr_scope;
	const DataType* t = CheckedGetDataType<T, Or<GET_DATATYPE_POLICY, POLICY, GET_DATATYPE_POLICY::NO_DECAY, GET_DATATYPE_POLICY::ALLOW_BASEARRAY>::value>() iferr_return;
	return ParametricTypes::IntegralConstant().Instantiate(t, ToSingletonBlock(Int64(C)));
}

/// @}

MAXON_DATATYPE_EARLY_ENUM(WRITEMETA);
MAXON_DATATYPE_EARLY_ENUM(TARGETAUDIENCE);
MAXON_DATATYPE_EARLY_ENUM(OUTPUT);
MAXON_DATATYPE_EARLY_ENUM(VALUEKIND);
MAXON_DATATYPE_EARLY_ENUM(COMPARERESULT);
MAXON_DATATYPE_EARLY_ENUM(EQUALITY);
MAXON_DATATYPE_EARLY_ENUM(COLLECTION_RESIZE_FLAGS);

} // namespace maxon

#include "maxon/registry.h"

#endif // DATATYPE_H__
