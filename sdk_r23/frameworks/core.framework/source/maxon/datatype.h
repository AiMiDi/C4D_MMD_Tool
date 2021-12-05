#ifndef DATATYPE_H__
#define DATATYPE_H__

#include "maxon/parametric_type.h"
#include "maxon/datatypefunctions.h"

namespace maxon
{

/// @addtogroup DATATYPE
/// @{

//----------------------------------------------------------------------------------------
/// An UnregisteredDataTypeError is returned by GetDataType<T>() when there is no data type
/// registration for T (or a part of T as in Block<X>).
//----------------------------------------------------------------------------------------
class UnregisteredDataTypeErrorInterface : MAXON_INTERFACE_BASES(ErrorInterface)
{
	MAXON_INTERFACE(UnregisteredDataTypeErrorInterface, MAXON_REFERENCE_COPY_ON_WRITE, "net.maxon.interface.unregistereddatatypeerror");
};

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
	// Needed by ViewIteratorMember
	struct Compact
	{
		UChar alignmentMask; // for the non-SIMD case this should be LIMIT<UChar>::MAX as this reduces the number of extra stride steps to a minimum
		UChar logMultiplicity;
		UInt16 extraStrideFlags;

		static constexpr UInt16 FLAGS_MASK = 15;

		Bool IsSimd() const
		{
			return logMultiplicity != 0;
		}

		Int GetMultiplicity() const
		{
			return Int(1) << logMultiplicity;
		}

		Int GetComponentSize() const
		{
			return Int(alignmentMask + 1) >> logMultiplicity;
		}

		Int GetExtraStride() const
		{
			return extraStrideFlags & ~FLAGS_MASK;
		}

		Int32 GetFlags() const
		{
			return extraStrideFlags & FLAGS_MASK;
		}
	};

	static_assert(SIZEOF(Compact) == SIZEOF(Int32), "Wrong size of Compact.");

	DataType componentType;	///< The component type such as Float.
	Int dimension;
	Int multiplicity;
	Int alignmentMask;			///< Size of a SIMD value minus one (i.e., the same as multiplicity * component size - 1, such as 15 for a 128-bit SSE value).
	Int multiplicityMask;		///< Number of components per SIMD value minus one. Zero for the non-SIMD case.
	Int logComponentSize;		///< Log2 of the size of a SIMD component (such as 3 for double precision float).
	Int componentSize;
	Int extraStride;				///< The extra stride to apply when a complete SIMD vector has been handled. This is (dimension-1) * size of SIMD value
	Compact compact;
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
		Int mmask = GetMultiplicityMask();
		return *(T*) ((Char*) _ptr + (index & ~mmask) * _stride + ((index & mmask) << _logComponentSize));
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
		return _simd.logMultiplicity ? (Int(1) << _logComponentSize) : _stride;
	}

	Int GetMultiplicityMask() const
	{
		DebugAssert(SIMD || (_simd.logMultiplicity == 0));
		return SIMD ? _simd.GetMultiplicity() - 1 : 0;
	}

	Int GetAlignmentMask() const
	{
		return _simd.alignmentMask;
	}

	Int GetExtraStride() const
	{
		return _simd.GetExtraStride();
	}

	void ResetSimdIndexing()
	{
		_simd = {LIMIT<UChar>::MAX, 0, 0};
		_logComponentSize = 0;
	}

	void SetSimdIndexing(const SimdInfo::Compact& simd, Int logComponentSize)
	{
		_simd = simd;
		_logComponentSize = logComponentSize;
	}

	const SimdInfo::Compact& GetInfo() const
	{
		return _simd;
	}

private:
	// Important: Ensure that the beginning of SimdBlock (its first three members _ptr, _size, _stride) is layout-compatible with StridedBlock<T>
	T* _ptr; ///< Pointer to first element.
	Int _size; ///< Number of elements.
	Int _stride; ///< Stride in bytes between elements. In the SIMD case, this is the size of a hypothetical non-SIMD vector (having dimension components). E.g., 24 for a double precision Vec3.

	SimdInfo::Compact _simd = {LIMIT<UChar>::MAX, 0, 0};
	Int _logComponentSize;
};


#include "datatype1.hxx"


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


template <GET_DATATYPE_POLICY POLICY> inline ResultOk<const DataType&> PrivateGetDataType(GenericArithmetic**, OverloadRank0)
{
	return DataTypeLib::GetGenericArithmeticType();
}

template <GET_DATATYPE_POLICY POLICY> inline ResultOk<const DataType&> PrivateGetDataType(void**, OverloadRank0)
{
	return DataTypeLib::GetVoidType();
}

template <GET_DATATYPE_POLICY POLICY> inline ResultOk<const DataType&> PrivateGetDataType(std::nullptr_t**, OverloadRank0)
{
	return DataTypeLib::GetNullptrType();
}

template <GET_DATATYPE_POLICY POLICY, typename T> inline typename SFINAEHelper<Result<const DataType&>, typename T::NonvirtualInterfaceMarker>::type PrivateGetDataType(T**, OverloadRank0)
{
	const DataType& t = T::Interface::_interface.GetDataType();
	return t ? Result<const DataType&>(t) : UnregisteredDataTypeErrorObject();
}

template <GET_DATATYPE_POLICY POLICY, typename T> inline typename SFINAEHelper<Result<const DataType&>, typename T::InterfaceMarker>::type PrivateGetDataType(T**, OverloadRank1)
{
	const DataType& t = T::_interface.GetDataType();
	return t ? Result<const DataType&>(t) : UnregisteredDataTypeErrorObject();
}

template <GET_DATATYPE_POLICY POLICY> inline Result<const DataType&> PrivateGetDataType(void*, OverloadRank0)
{
	static_assert(Bool(POLICY & GET_DATATYPE_POLICY::RESULT_FOR_UNKNOWN_MASK), "Missing data type registration.");
	return (POLICY & GET_DATATYPE_POLICY::GENERIC_FOR_UNKNOWN) ? Result<const DataType&>(DataTypeLib::GetGenericType()) : UnregisteredDataTypeErrorObject();
}


template <GET_DATATYPE_POLICY POLICY> inline ResultOk<const DataType&> PrivateGetDataType(DataType**, OverloadRank0)
{
	return DataTypeLib::GetDataTypeType();
}

template <GET_DATATYPE_POLICY POLICY> inline ResultOk<const DataType&> PrivateGetDataType(DataType::Primary**, OverloadRank0)
{
	return DataTypeLib::PrivateGetPrimaryDataTypeType();
}

template <GET_DATATYPE_POLICY POLICY> inline ResultOk<const DataType&> PrivateGetDataType(TupleDataType**, OverloadRank0)
{
	return DataTypeLib::GetDataTypeType();
}


template <typename T> void PrivateDataTypeMarker(T*);

//----------------------------------------------------------------------------------------
/// This registry is used to register all primary data types (those which are declared by MAXON_DATATYPE, and
/// interfaces). It does not include compound data types such as array, tuple or reference types.
/// Use DataType::Get() to obtain a DataType for a data type identifier, whether it is primary or compound.
//----------------------------------------------------------------------------------------
MAXON_REGISTRY(DataType, DataTypes, "net.maxon.registry.datatypes");

#define PRIVATE_MAXON_DATATYPE_A(type, id) \
	void* PrivateDataTypeMarker(type*); \
	MAXON_DECLARATION(maxon::DataType, DT_##type, id); \
	template <maxon::GET_DATATYPE_POLICY> inline maxon::ResultOk<const maxon::DataType&> PrivateGetDataType(type**, maxon::OverloadRank2) { return DT_##type(); }

// Used internally for scalar types for which no declaration of PrivateConstRefNullValue is needed.
#define MAXON_DATATYPE_SCALAR(type, id) PRIVATE_MAXON_DATATYPE_A(type, id)

#define PRIVATE_MAXON_DATATYPE(type, id) PRIVATE_MAXON_DATATYPE_A(type, id)

//----------------------------------------------------------------------------------------
/// MAXON_DATATYPE declares a primary DataType for the given @p type. Use this in a header
/// file to be able to use values of @p type for the DataType system.
/// There has to be a matching DataType definition via MAXON_DATATYPE_REGISTER in a cpp file.
/// @code
///	MAXON_DATATYPE(TimeValue, "net.maxon.datatype.timevalue");
/// @endcode
/// You don't have to declare data types for interfaces, this is done automatically.
/// Also you don't have to declare data types for template instantiations if there is a
/// ParametricType for the class template. For example there is a ParametricType for StrongRef<T>,
/// so for any T for which a DataType is declared the DataType for StrongRef<T> needn't be
/// declared because the ParametricType automatically derives it from the DataType for T.
/// @param[in] type								Type for which a DataType shall be implemented.
/// @param[in] id									Unique identifier of the data type.
//----------------------------------------------------------------------------------------
#define MAXON_DATATYPE(type, id) PRIVATE_MAXON_DATATYPE(type, id) MAXON_ASSERT_LEGAL_LAYOUT(type)


#define PRIVATE_MAXON_DATATYPE_REGISTER(T, ret, flags) \
	PRIVATE_MAXON_REGISTER_CHECK("MAXON_DATATYPE_REGISTER"); \
	namespace \
	{ \
		static maxon::DataTypeImpl::Primary g_dataType_##T(DT_##T##_CppName(), &PRIVATE_MAXON_MODULE, DT_##T.GetId(), nullptr, nullptr, (T*) nullptr, (maxon::DataTypeFunctions<T>*) nullptr, flags); \
		static maxon::Result<maxon::DataType::Primary> InitDataType##T(MAXON_SOURCE_LOCATION_DECLARATION, maxon::Id&) { maxon::DataTypeImpl* dt = &g_dataType_##T.type; return ret; } \
		static maxon::ObjectDefinition g_dataTypeDef_##T(DT_##T.GetId(), &InitDataType##T, (maxon::DataTypes::Registry*) nullptr, &maxon::g_translationUnit, __FILE__, maxon::EntityBase::FLAGS::NONE); \
	}

#define PRIVATE_MAXON_DATATYPE_REGISTER_ENUM(enumtype, cppname, id, size, flags, names, ...) \
	namespace \
	{ \
		static maxon::DataTypeImpl::Primary g_dataType_##enumtype(cppname, &PRIVATE_MAXON_MODULE); \
		static maxon::Result<maxon::DataType::Primary> InitDataType##enumtype(MAXON_SOURCE_LOCATION_DECLARATION, maxon::Id& objectId) { iferr_scope; __VA_ARGS__; maxon::DataTypeLib::RegisterEnumType(g_dataType_##enumtype.type, objectId, size, STD_IS_REPLACEMENT(signed, std::underlying_type<enumtype>::type), flags, values, names) iferr_return; return maxon::DataType::Primary(&g_dataType_##enumtype.type); } \
		static maxon::ObjectDefinition g_dataTypeRef_##enumtype(maxon::LiteralId(id), &InitDataType##enumtype, (maxon::DataTypes::Registry*) nullptr, &maxon::g_translationUnit, __FILE__, maxon::EntityBase::FLAGS::NONE); \
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
#define MAXON_DATATYPE_REGISTER(type) PRIVATE_MAXON_DATATYPE_REGISTER(type, maxon::DataType::Primary(dt), maxon::VALUEKIND::NONE)

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
#define MAXON_DATATYPE_LOCAL(type, id) \
	constexpr inline const maxon::Char* DT_##type##_CppName() { return nullptr; } \
	PRIVATE_MAXON_DATATYPE_LOCAL_STATIC PRIVATE_MAXON_DATATYPE(type, id); \
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(DT_##type,, id); \
	MAXON_DATATYPE_REGISTER(type)


#define PRIVATE_MAXON_DATATYPE_REGISTER_STRUCT_INIT(x, i, a) {maxon::GetDataType<decltype(std::declval<a>().x)>(), #x}
#define PRIVATE_MAXON_DATATYPE_REGISTER_STRUCT_OFFSETS(x, i, a) (maxon::Int) offsetof(a, x)

#define PRIVATE_MAXON_DATATYPE_REGISTER_STRUCT_B(Type, line, count, ...) \
	static maxon::Result<maxon::DataType::Primary> PrivateSetStructType##line##Type(maxon::DataTypeImpl* dt) \
	{ \
		iferr_scope; \
		maxon::Tuple<maxon::DataType, const maxon::Char*> array[] = {MAXON_MAKE_COMMA_LIST(PRIVATE_MAXON_DATATYPE_REGISTER_STRUCT_INIT, Type, , __VA_ARGS__)}; \
		maxon::Member members[std::extent<decltype(array)>::value]; \
		maxon::Member* mb = members; \
		for (const auto& m : array) \
		{ \
			mb->type = m.first; \
			mb->name.Init(m.second) iferr_return; \
			++mb; \
		} \
		maxon::TupleDataType s = maxon::ParametricTypes::Tuple().Instantiate(members) iferr_return; \
		maxon::Int offsets[] = {MAXON_MAKE_COMMA_LIST(PRIVATE_MAXON_DATATYPE_REGISTER_STRUCT_OFFSETS, Type, , __VA_ARGS__)}; \
		dt->PrivateSetStructType(s, offsets); \
		return maxon::DataType::Primary(dt); \
	} \
	PRIVATE_MAXON_DATATYPE_REGISTER(Type, PrivateSetStructType##line##Type(dt), maxon::VALUEKIND::STRUCT)


#define PRIVATE_MAXON_DATATYPE_REGISTER_STRUCT_A(type, line, count, ...) PRIVATE_MAXON_DATATYPE_REGISTER_STRUCT_B(type, line, count, __VA_ARGS__)

//----------------------------------------------------------------------------------------
/// MAXON_DATATYPE_REGISTER_STRUCT defines the implementation of a DataType for the given #type,
/// and it also sets up an underlying tuple type which is composed of the members given by ... .
/// You can use this instead of MAXON_DATATYPE_REGISTER for a struct type consisting of public member variables,
/// then the members of your type are accessible to the DataType system. Also there's no need to
/// implement the DescribeIO function because the one from the underlying type is used.
///
/// This macro has to be used in a cpp file, and there has to be a corresponding
/// MAXON_DATATYPE in a header file.
/// @code
/// // header file
/// struct Member
/// {
/// 	const DataTypeImpl* type;
/// 	Id name;
/// };
///
///	MAXON_DATATYPE(Member, "net.maxon.datatype.member");
///
/// // cpp file
/// MAXON_DATATYPE_REGISTER_STRUCT(Member, type, name);
/// @endcode
/// @param[in] type								Type for which a DataType shall be implemented.
/// @param[in] ...								List of the names of the member variables of #type.
//----------------------------------------------------------------------------------------
#define MAXON_DATATYPE_REGISTER_STRUCT(type, ...) PRIVATE_MAXON_DATATYPE_REGISTER_STRUCT_A(type, __LINE__, MAXON_VA_NARGS(__VA_ARGS__), __VA_ARGS__)

// predefine the basic types, all the other types need to be declared where they are made public

// stylecheck.domains=

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

// stylecheck.domains=net.maxon

MAXON_DATATYPE_SCALAR(HashValue, "net.maxon.datatype.hash");
MAXON_DATATYPE_SCALAR(Id, "net.maxon.datatype.id");
MAXON_DATATYPE_SCALAR(LiteralId, "net.maxon.datatype.literalid");
MAXON_DATATYPE_SCALAR(InternedId, "net.maxon.datatype.internedid");
MAXON_DATATYPE_SCALAR(Data, "net.maxon.datatype.data");
MAXON_DATATYPE_SCALAR(UnitType, "net.maxon.datatype.unittype");

MAXON_DATATYPE(SourceLocation, "net.maxon.datatype.sourcelocation");
MAXON_DATATYPE(DelegateBase, "net.maxon.datatype.delegatebase");


template <Bool, typename T> inline ResultOk<const DataType&> PrivateGetEnumDataType(T*, OverloadRank0)
{
	return PrivateGetDataType<GET_DATATYPE_POLICY::NONE>((typename UIntType<sizeof(T)>::type**) nullptr, OVERLOAD_MAX_RANK);
}

template <GET_DATATYPE_POLICY POLICY, typename T> inline typename std::enable_if<STD_IS_REPLACEMENT(enum, T), ResultOk<const DataType&>>::type PrivateGetDataType(T**, OverloadRank0)
{
	return PrivateGetEnumDataType<false>((T*) nullptr, OVERLOAD_MAX_RANK);
}


// this is only needed when long is not one of Int32 or Int64, but due to the low overload rank it doesn't harm when unneeded
template <GET_DATATYPE_POLICY POLICY> inline ResultOk<const DataType&> PrivateGetDataType(long**, OverloadRank0)
{
	return PrivateGetDataType<GET_DATATYPE_POLICY::NONE>((typename IntType<sizeof(long)>::type**) nullptr, OVERLOAD_MAX_RANK);
}

// same for the unsigned case
template <GET_DATATYPE_POLICY POLICY> inline ResultOk<const DataType&> PrivateGetDataType(unsigned long**, OverloadRank0)
{
	return PrivateGetDataType<GET_DATATYPE_POLICY::NONE>((typename UIntType<sizeof(unsigned long)>::type**) nullptr, OVERLOAD_MAX_RANK);
}

template <GET_DATATYPE_POLICY POLICY> inline ResultOk<const DataType&> PrivateGetDataType(ParametricType**, OverloadRank0)
{
	return DataTypeLib::GetParametricTypeType();
}

template <GET_DATATYPE_POLICY POLICY> inline ResultOk<const DataType&> PrivateGetDataType(ComponentDescriptor**, OverloadRank0)
{
	return DataTypeLib::GetComponentDescriptorType();
}

// The declaration of CheckedGetDataType has to be after the MAXON_DATATYPE_SCALAR macros because for scalar types
// only function declarations from the template definition context are considered.
// So CheckedGetDataType could not see PrivateGetDataType for scalar types if MAXON_DATATYPE_SCALAR followed CheckedGetDataType.

template <typename T, GET_DATATYPE_POLICY POLICY, Bool NO_DECAY = (POLICY & GET_DATATYPE_POLICY::NO_DECAY) && (STD_IS_REPLACEMENT(reference, T) || STD_IS_REPLACEMENT(const, T))> struct CheckedGetDataType
{
	using ST = typename StandardType<typename std::decay<T>::type>::type;
	using type = DataType;

	static Result<DataType> Get()
	{
		iferr_scope;
		// This uses argument-dependent lookup, so PrivateGetDataType is searched for also in the namespace of T.
		DataType t = PrivateGetDataType<POLICY>((ST**) nullptr, OVERLOAD_MAX_RANK) iferr_return;
		if (MAXON_UNLIKELY(!t))
		{
			return UnregisteredDataTypeErrorObject();
		}
		if (STD_IS_REPLACEMENT(const, typename std::remove_reference<T>::type))
		{
			t = ParametricTypes::Const().Instantiate(t) iferr_return;
		}
		if (STD_IS_REPLACEMENT(lvalue_reference, T))
		{
			t = ParametricTypes::LVReference().Instantiate(t) iferr_return;
		}
		else if (STD_IS_REPLACEMENT(rvalue_reference, T))
		{
			t = ParametricTypes::RVReference().Instantiate(t) iferr_return;
		}
		return t;
	}
};
	
template <GET_DATATYPE_POLICY POLICY, typename T> inline typename std::enable_if<GetDirectlyReferencedType<T>::value, Result<DataType>>::type PrivateGetDataType(T**, OverloadRank0)
{
	iferr_scope;
	DataType t = (CheckedGetDataType<typename T::DirectlyReferencedType, (MAXON_IS_COW_KIND(T::Handler::KIND) ? POLICY & ~GET_DATATYPE_POLICY::NO_DECAY : POLICY | GET_DATATYPE_POLICY::NO_DECAY) | GET_DATATYPE_POLICY::ALLOW_BASEARRAY>::Get()) iferr_return;
	switch (T::Handler::KIND & VALUEKIND::PTR_MASK)
	{
		case VALUEKIND::POINTER:
			return ParametricTypes::Pointer().Instantiate(t);
		case VALUEKIND::UNIQUE_REFERENCE:
			return ParametricTypes::UniqueReference().Instantiate(t);
		case VALUEKIND::STRONG_REFERENCE:
			return ParametricTypes::StrongReference().Instantiate(t);
		case VALUEKIND::COW_REFERENCE:
			return ParametricTypes::COWReference().Instantiate(t);
		case VALUEKIND::ACOW_REFERENCE:
			return ParametricTypes::ACOWReference().Instantiate(t);
		default:
			return IllegalArgumentError(MAXON_SOURCE_LOCATION);
	}
}

template <GET_DATATYPE_POLICY POLICY, typename T> inline Result<DataType> PrivateGetDataType(T***, OverloadRank0)
{
	return ParametricTypes::Pointer().GetPointer()->Instantiate(CheckedGetDataType<typename std::conditional<STD_IS_REPLACEMENT(function, T), Generic, T>::type, Or<GET_DATATYPE_POLICY, POLICY, GET_DATATYPE_POLICY::NO_DECAY, GET_DATATYPE_POLICY::ALLOW_BASEARRAY>::value>::Get());
}

template <GET_DATATYPE_POLICY POLICY, typename T> inline Result<DataType> PrivateGetDataType(Block<T>**, OverloadRank0)
{
	return ParametricTypes::Block().GetPointer()->Instantiate(CheckedGetDataType<T, Or<GET_DATATYPE_POLICY, POLICY, GET_DATATYPE_POLICY::NO_DECAY, GET_DATATYPE_POLICY::ALLOW_BASEARRAY>::value>::Get());
}

template <GET_DATATYPE_POLICY POLICY, typename T> inline Result<DataType> PrivateGetDataType(StridedBlock<T>**, OverloadRank0)
{
	return ParametricTypes::StridedBlock().GetPointer()->Instantiate(CheckedGetDataType<T, Or<GET_DATATYPE_POLICY, POLICY, GET_DATATYPE_POLICY::NO_DECAY, GET_DATATYPE_POLICY::ALLOW_BASEARRAY>::value>::Get());
}

template <GET_DATATYPE_POLICY POLICY, typename T> inline typename SFINAEHelper<Result<DataType>, typename T::VectorStrideType>::type PrivateGetDataType(T**, OverloadRank0)
{
	using Simd = IsSimdElementType<T>;
	return ParametricTypes::Simd().GetPointer()->Instantiate(CheckedGetDataType<typename Simd::ValueType, Or<GET_DATATYPE_POLICY, POLICY, GET_DATATYPE_POLICY::NO_DECAY, GET_DATATYPE_POLICY::ALLOW_BASEARRAY>::value>::Get(), {Simd::STRIDE, SIZEOF(typename Simd::type) / (Simd::STRIDE * SIZEOF(typename Simd::ValueType))});
}

template <typename T> class Opt;

template <GET_DATATYPE_POLICY POLICY, typename T> inline Result<DataType> PrivateGetDataType(Opt<T>**, OverloadRank0)
{
	return ParametricTypes::Optional().GetPointer()->Instantiate(CheckedGetDataType<T, Or<GET_DATATYPE_POLICY, POLICY, GET_DATATYPE_POLICY::NO_DECAY, GET_DATATYPE_POLICY::ALLOW_BASEARRAY>::value>::Get());
}

template <GET_DATATYPE_POLICY POLICY, typename T> inline Result<DataType> PrivateGetDataType(Result<T>**, OverloadRank0)
{
	return ParametricTypes::Result().GetPointer()->Instantiate(CheckedGetDataType<T, Or<GET_DATATYPE_POLICY, POLICY, GET_DATATYPE_POLICY::NO_DECAY, GET_DATATYPE_POLICY::ALLOW_BASEARRAY>::value>::Get());
}

template <GET_DATATYPE_POLICY POLICY, typename T> inline Result<DataType> PrivateGetDataType(OpaquePtr<T>**, OverloadRank0)
{
	return ParametricTypes::Opaque().GetPointer()->Instantiate(CheckedGetDataType<T, Or<GET_DATATYPE_POLICY, POLICY, GET_DATATYPE_POLICY::NO_DECAY, GET_DATATYPE_POLICY::ALLOW_BASEARRAY>::value>::Get());
}

template <GET_DATATYPE_POLICY POLICY, typename T> inline typename std::enable_if<(Int(POLICY) & Int(GET_DATATYPE_POLICY::ALLOW_BASEARRAY)) != 0, Result<DataType>>::type PrivateGetDataType(BaseArray<T>**, OverloadRank0)
{
	return ParametricTypes::BaseArray().GetPointer()->Instantiate(CheckedGetDataType<T, Or<GET_DATATYPE_POLICY, POLICY, GET_DATATYPE_POLICY::NO_DECAY>::value>::Get());
}

template <GET_DATATYPE_POLICY POLICY, typename... T> inline Result<TupleDataType> PrivateGetDataType(Tuple<T...>**, OverloadRank0)
{
	iferr_scope;
	// We assume that the compilers will use the same layout for a class with a member of type A& as for a class with a corresponding member of type A*.
	// Then we can allow references for the tuple members.
	static_assert(And<(STD_IS_REPLACEMENT(standard_layout, T) || STD_IS_REPLACEMENT(reference, T))...>::value, "The DataType of a tuple with non-standard-layout members can't be constructed automatically.");
	Result<DataType> types[] = {CheckedGetDataType<T, Or<GET_DATATYPE_POLICY, POLICY, GET_DATATYPE_POLICY::NO_DECAY, GET_DATATYPE_POLICY::ALLOW_BASEARRAY>::value>::Get()...};
	DataType tupleType = ParametricTypes::Tuple().GetPointer()->PrivateInstantiate(ToBlock(types)) iferr_return;
	DebugAssert(tupleType->GetSize() == SIZEOF(Tuple<T...>));
	return std::move(reinterpret_cast<TupleDataType&>(tupleType));
}

template <GET_DATATYPE_POLICY POLICY, typename T, typename = typename T::StructTupleType> inline Result<TupleDataType> PrivateGetDataType(T**, OverloadRank0)
{
	return PrivateGetDataType<POLICY>((typename T::StructTupleType**) nullptr, OVERLOAD_MAX_RANK);
}

template <GET_DATATYPE_POLICY POLICY, typename R, typename... ARGS> inline Result<DelegateDataType> PrivateGetDataType(Delegate<R(ARGS...)>**, OverloadRank2)
{
#ifdef MAXON_COMPILER_INTEL
#pragma warning disable 177
#endif
	Result<DataType> types[] = {CheckedGetDataType<ARGS, Or<GET_DATATYPE_POLICY, POLICY, GET_DATATYPE_POLICY::NO_DECAY, GET_DATATYPE_POLICY::ALLOW_BASEARRAY>::value>::Get()..., {}};
	return DataTypeLib::GetDelegateType(CheckedGetDataType<R, Or<GET_DATATYPE_POLICY, POLICY, GET_DATATYPE_POLICY::NO_DECAY, GET_DATATYPE_POLICY::ALLOW_BASEARRAY>::value>::Get(), {types, sizeof...(ARGS)},
																			&reflection::Invocation<R, ARGS...>::InvokeDelegate, (void*) &reflection::DelegateHandlerHelper<R, ARGS...>::Invoke);
#ifdef MAXON_COMPILER_INTEL
#pragma warning disable 177
#endif
}

/// @private
class DataTypeCache
{
public:
	const DataType& Get() const
	{
		if (MAXON_UNLIKELY(!_type))
		{
			Init(true) iferr_ignore("Error message written by Init.");
		}
		return _type;
	}

	using InitFunction = Result<DataType>();

	Result<void> Init(Bool showMsg) const;

	DataTypeCache(InitFunction* init, ModuleInfo* module);

	template <typename T> DataTypeCache(Result<T>(*init)(), ModuleInfo* module) : DataTypeCache((InitFunction*) init, module)
	{
		static_assert(STD_IS_REPLACEMENT(base_of, DataType, T), "T has to be derived from DataType.");
	}

	Bool IsInitialized() const
	{
		return Bool(_type);
	}

private:
	mutable DataType _type; // This is set up during initialization in single-threaded context, no synchronization needed.
	const DataTypeCache* const _next;
	InitFunction* const _init;

	friend class ObjectModel;
};

/// @private
template <typename T, GET_DATATYPE_POLICY POLICY, Bool ELEMENTARY> class DataTypeCacheInstance
{
public:
	static const typename CheckedGetDataType<T, POLICY>::type& Get()
	{
		return static_cast<const typename CheckedGetDataType<T, POLICY>::type&>(_instance.Get());
	}

private:
	static const DataTypeCache _instance;
};

template <typename T, GET_DATATYPE_POLICY POLICY, Bool ELEMENTARY> const DataTypeCache DataTypeCacheInstance<T, POLICY, ELEMENTARY>::_instance(&CheckedGetDataType<T, POLICY>::Get, &PRIVATE_MAXON_MODULE);

template <typename T, GET_DATATYPE_POLICY POLICY> class DataTypeCacheInstance<T, POLICY, true>
{
public:
	static const DataType& Get()
	{
		return PrivateGetDataType<POLICY>((T**) nullptr, OVERLOAD_MAX_RANK);
	}
};

template <GET_DATATYPE_POLICY POLICY> class DataTypeCacheInstance<void, POLICY, true>
{
public:
	static const DataType& Get()
	{
		return DataTypeLib::GetVoidType();
	}
};

template <GET_DATATYPE_POLICY POLICY> class DataTypeCacheInstance<std::nullptr_t, POLICY, true>
{
public:
	static const DataType& Get()
	{
		return DataTypeLib::GetNullptrType();
	}
};

//----------------------------------------------------------------------------------------
/// Returns the DataType representation of T. This covers not only primary datatypes
/// which have been registered directly with MAXON_DATATYPE_REGISTER, but also compound types
/// which are derived from other types (such as arrays, pointers, references, tuples).
/// @tparam T											Type for which the DataType shall be obtained.
/// @tparam POLICY								An optional policy for the operation.
/// @return												The DataType representation for T.
//----------------------------------------------------------------------------------------
template <typename T, GET_DATATYPE_POLICY POLICY> inline const auto& GetDataType()
{
	using TT = typename std::conditional<Bool(POLICY & GET_DATATYPE_POLICY::NO_DECAY), T, typename std::decay<T>::type>::type;
	using DT = typename std::decay<TT>::type;
	const Bool ELEMENTARY = STD_IS_REPLACEMENT(fundamental, DT) || STD_IS_REPLACEMENT(enum, DT) || STD_IS_REPLACEMENT(same, DT, DataType) || STD_IS_REPLACEMENT(pointer, decltype(PrivateDataTypeMarker((DT*) nullptr)));
	return DataTypeCacheInstance<TT, POLICY, STD_IS_REPLACEMENT(same, TT, DT) && ELEMENTARY>::Get();
}

template <GET_DATATYPE_POLICY POLICY> inline ResultOk<const DataType&> PrivateGetDataType(Generic**, OverloadRank0)
{
	return DataTypeLib::GetGenericType();
}


MAXON_DATATYPE(ConstDataPtr, "net.maxon.datatype.constdataptr");
MAXON_DATATYPE(DataPtr, "net.maxon.datatype.dataptr");
MAXON_DATATYPE(MoveDataPtr, "net.maxon.datatype.movedataptr");
MAXON_DATATYPE(ForwardingDataPtr, "net.maxon.datatype.forwardingdataptr");

MAXON_DATATYPE(Member, "net.maxon.datatype.member");

namespace details
{

template <typename T, typename = void> struct MemberTypeBase
{
	using OrigType = T;
	using BaseType = T;
	static const Bool NAMED = false;

	static const InternedId& GetId()
	{
		return GetPtrSizedZeroRef<InternedId>();
	}
};

template <typename T> struct MemberTypeBase<T, typename std::enable_if<maxon::details::HasBaseHelper<T, InternedId, 0>::value, typename SFINAEHelper<void, typename T::ValueType>::type>::type>
{
	using OrigType = T;
	using BaseType = typename InheritConst<typename T::ValueType, T>::type;
	static const Bool NAMED = true;

	static const InternedId& GetId()
	{
		return T::GetInstance();
	}
};

template <typename T, Bool GENERIC_FOR_UNKNOWN_TYPE = false> struct MemberType : public MemberTypeBase<T>
{
	using type = typename MemberTypeBase<T>::BaseType;

	static Member GetMember()
	{
		return Member(GetDataType<type, GET_DATATYPE_POLICY::NO_DECAY | GET_DATATYPE_POLICY::ALLOW_BASEARRAY | ConditionalFlag(GENERIC_FOR_UNKNOWN_TYPE, GET_DATATYPE_POLICY::GENERIC_FOR_UNKNOWN)>(), MemberTypeBase<T>::GetId());
	}

	using GetType = typename std::add_lvalue_reference<type>::type;

	static const GetType Get(const Generic* ptr)
	{
		return *reinterpret_cast<const type*>(ptr);
	}

	static GetType Get(Generic* ptr)
	{
		return *reinterpret_cast<type*>(ptr);
	}
};

template <typename T, Bool GENERIC_FOR_UNKNOWN_TYPE> struct MemberType<T&, GENERIC_FOR_UNKNOWN_TYPE> : public MemberTypeBase<T>
{
	using type = typename MemberTypeBase<T>::BaseType&;

	static Member GetMember()
	{
		return Member(GetDataType<type, GET_DATATYPE_POLICY::NO_DECAY | GET_DATATYPE_POLICY::ALLOW_BASEARRAY | ConditionalFlag(GENERIC_FOR_UNKNOWN_TYPE, GET_DATATYPE_POLICY::GENERIC_FOR_UNKNOWN)>(), MemberTypeBase<T>::GetId());
	}

	using GetType = type;

	static GetType Get(Generic* ptr)
	{
		return **reinterpret_cast<typename MemberTypeBase<T>::BaseType* const*>(ptr);
	}
};

template <typename T, Bool GENERIC_FOR_UNKNOWN_TYPE> struct MemberType<T&&, GENERIC_FOR_UNKNOWN_TYPE> : public MemberTypeBase<T>
{
	using type = typename MemberTypeBase<T>::BaseType&&;

	static Member GetMember()
	{
		return Member(GetDataType<type, GET_DATATYPE_POLICY::NO_DECAY | GET_DATATYPE_POLICY::ALLOW_BASEARRAY | ConditionalFlag(GENERIC_FOR_UNKNOWN_TYPE, GET_DATATYPE_POLICY::GENERIC_FOR_UNKNOWN)>(), MemberTypeBase<T>::GetId());
	}

	using GetType = type;

	static GetType Get(Generic* ptr)
	{
		return std::move(**reinterpret_cast<typename MemberTypeBase<T>::BaseType* const*>(ptr));
	}
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

}

struct NamedTupleMembers
{
	Block<const Member> block;
	TupleDataType type;
	ContainerDataType<> containerType;
	Int state;
	NamedTupleMembers* nextOfBinary;
};


template <typename... T> class NamedTuple : public ParameterPack<T...>
{
public:
	using TupleType = Tuple<typename maxon::details::MemberType<T>::type...>;
	using TupleTypeWithPtrsForRefs = Tuple<typename maxon::details::SubstituteReferenceByPointer<typename maxon::details::MemberType<T>::type>::type...>;

	static const Bool ALL_NAMED = And<maxon::details::MemberType<T>::NAMED...>::value;

	using Pack = ParameterPack<T...>;
	using ContainerType = ContainerDataType<T...>;

	static const Block<const Member>& GetMembers()
	{
		return DataTypeLib::PrivateGetNamedTupleMembers(g_maxon, &_helper.members, &Helper::Construct);
	}

	static const TupleDataType& GetDataType()
	{
		AtomicInt& state = reinterpret_cast<AtomicInt&>(_helper.members.state);
		if (MAXON_UNLIKELY(state.LoadConsume() != 2))
		{
			GetMembers();
		}
		return _helper.members.type;
	}

	static const ContainerType& GetContainerType()
	{
		AtomicInt& state = reinterpret_cast<AtomicInt&>(_helper.members.state);
		if (MAXON_UNLIKELY(state.LoadConsume() != 2))
		{
			GetMembers();
		}
		return reinterpret_cast<const ContainerType&>(_helper.members.containerType);
	}

	template <typename OTHER> using ContainsAll = typename Pack::template ContainsAll<typename OTHER::Pack>;

	static Int FindIndex(const InternedId& name)
	{
		return FindIndexImpl<0>(name.GetPointer());
	}

	static Int FindOffset(const InternedId& name)
	{
		return FindOffsetImpl<0>(name.GetPointer());
	}

private:
	template <UInt32 I> static typename std::enable_if<(I < sizeof...(T)), Int>::type FindIndexImpl(const Id* name)
	{
		if (name == maxon::details::MemberType<typename Pack::template At<I>::type>::GetId().GetPointer())
			return I;
		else
			return FindIndexImpl<I+1>(name);
	}

	template <UInt32 I> static Int FindIndexImpl(...)
	{
		static_assert(I == sizeof...(T), "Instantiation error");
		return -1;
	}

	template <UInt32 I> static typename std::enable_if<(I < sizeof...(T)), Int>::type FindOffsetImpl(const Id* name)
	{
		if (name == maxon::details::MemberType<typename Pack::template At<I>::type>::GetId().GetPointer())
			return TupleType::GetOffset((typename std::integral_constant<UInt32, I>::type*) nullptr);
		else
			return FindOffsetImpl<I+1>(name);
	}

	template <UInt32 I> static Int FindOffsetImpl(...)
	{
		static_assert(I == sizeof...(T), "Instantiation error");
		return -1;
	}

	struct Helper
	{
		Member members[sizeof...(T) > 0 ? sizeof...(T) : 1];

		Helper() : members{maxon::details::MemberType<T, true>::GetMember()...}
		{
		}

		static Int Construct(void* mem)
		{
			new (mem) Helper();
			return sizeof...(T);
		}
	};

	// We can't use Helper directly because this would require the DataType system at DLL load.
	// Therefore use lazy initialization.
	struct HelperStorage
	{
		NamedTupleMembers members;
		typename std::aligned_storage<SIZEOF(Helper), alignof(Helper)>::type storage;
	};

	static HelperStorage _helper;
};

template <typename... T> typename NamedTuple<T...>::HelperStorage NamedTuple<T...>::_helper;

template <GET_DATATYPE_POLICY POLICY, typename... T> inline Result<TupleDataType> PrivateGetDataType(NamedTuple<T...>**, OverloadRank0)
{
	return NamedTuple<T...>::GetDataType();
}



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
	template <typename T> const T& Get(Int index, const TupleDataType& type) const
	{
		DebugAssert((type->GetTypeArguments()[index].type == GetDataType<T, GET_DATATYPE_POLICY::GENERIC_FOR_UNKNOWN>()) ||
								(DataTypeLib::GetGenericType() == GetDataType<T, GET_DATATYPE_POLICY::GENERIC_FOR_UNKNOWN>()));
		return *(const T*) ((const Char*) this + DataTypeLib::GetTupleMemberOffsets(type)[index]);
	}

	//----------------------------------------------------------------------------------------
	/// Returns a reference to the value of the tuple member at @p index.
	/// @tparam T											Type of the member.
	/// @param[in] index							Index of the member.
	/// @param[in] type								Tuple data type of this TupleValue.
	/// @return												Reference to the member value.
	//----------------------------------------------------------------------------------------
	template <typename T> T& Get(Int index, const TupleDataType& type)
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
	const TupleValue& GetTuple(Int index, const TupleDataType& type) const
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
	TupleValue& GetTuple(Int index, const TupleDataType& type)
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
	const TupleDataType& GetOutputs() const
	{
		return static_cast<const TupleDataType&>(PrivateGetPointer()->GetTypeArguments()[0].type);
	}

	//----------------------------------------------------------------------------------------
	/// Returns the input types (of the parameters) of a function.
	//----------------------------------------------------------------------------------------
	const TupleDataType& GetInputs() const
	{
		return static_cast<const TupleDataType&>(PrivateGetPointer()->GetTypeArguments()[1].type);
	}
};


template <typename T> inline void DataType::AssertType() const
{
#ifdef MAXON_TARGET_DEBUG
	AssertTypeImpl(GetDataType<T>());
#endif
}

template <typename T> inline Bool DataType::Is() const
{
	return _ptr == GetDataType<T>()._ptr;
}

template <typename DEST, typename SRC> inline Result<void> DataType::AddConversion(CONVERSION_FLAGS kind, Result<void> (*conversion) (DEST&, const SRC&))
{
	return GetDataType<DEST>().AddConversion(GetDataType<SRC>(), kind, [conversion] (const DataPtr& dest, const ConstDataPtr& src) -> Result<void>
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
	return GetDataType<T, GET_DATATYPE_POLICY::GENERIC_FOR_UNKNOWN>().IsCastableFrom(*this);
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
	static_assert(!STD_IS_REPLACEMENT(same, T, const Data&), "const Data& not allowed with Data::InitSet()");
	static_assert(!STD_IS_REPLACEMENT(same, T, Data&), "Data& not allowed with Data::InitSet()");

	using Functions = DataTypeFunctions<typename std::decay<T>::type>;
//	static_assert(Functions::FITS_IN_MEMBLOCK, "Data constructor only available for types which fit in a DataMemBlock.");
	const DataType& ti = maxon::GetDataType<T>();
	if (ti)
	{
		Result<void> r = Functions::Init(ti.PrivateGetPointer(), &_memBlock, std::forward<T>(data));
		if (MAXON_UNLIKELY(r == FAILED))
		{
			_typeInfo.Reset();
			return;
		}
	}
	_typeInfo = ti;
}

template <> inline void Data::InitSet(Data&& data)
{
	*this = std::move(data);
}

template <typename DEST, typename SRC> inline Result<void> Data::SetImpl(SRC&& data, OverloadRank0)
{
	using DESTX = typename std::conditional<std::is_void<DEST>::value, SRC, DEST>::type;
	using Functions = DataTypeFunctions<typename std::decay<DESTX>::type>;
	const DataType& ti = maxon::GetDataType<DESTX>();
	if (_typeInfo != ti)
	{
		Reset();
		if (ti)
		{
			Result<void> r = Functions::Init(ti.PrivateGetPointer(), &_memBlock, std::forward<SRC>(data));
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
		return Functions::Set(ti.PrivateGetPointer(), &_memBlock, std::forward<SRC>(data));
	}
	return CreateError(MAXON_SOURCE_LOCATION, ERROR_TYPE::ILLEGAL_ARGUMENT);
}

template <typename DEST> inline Result<void> Data::SetImpl(Data&& data, OverloadRank1)
{
	*this = std::move(data);
	return OK;
}

template <typename DEST> inline Result<void> Data::SetImpl(const Data& data, OverloadRank1)
{
	return CopyFrom(data);
}

template <typename DEST> inline Result<void> Data::SetImpl(Data& data, OverloadRank1)
{
	return CopyFrom(data);
}

template <typename T> inline T* Data::GetPtr()
{
	const DataType& t = GetDataType<T>();
	if (STD_IS_REPLACEMENT(scalar, T) && t == _typeInfo)
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
	_typeInfo = GetDataType<T, GET_DATATYPE_POLICY::ALLOW_BASEARRAY>();
	_dataPtr = reinterpret_cast<const Generic*>(&value);
}

template <typename T> String ToStringHelper2<T, false>::ToString(const T* object, const FormatStatement* formatStatement, Bool checkDataType)
{
	DataType ti = checkDataType ? PrivateGetDataType<GET_DATATYPE_POLICY::GENERIC_FOR_UNKNOWN>((T**) nullptr, OVERLOAD_MAX_RANK) iferr_ignore("Error correctly handled by nullptr.") : DataType::NullValue();

	if (ti)
		return ti->ToString(object, formatStatement);

	return String::PointerToString(object);
}

template <GET_DATATYPE_POLICY POLICY, typename T, T C> inline Result<DataType> PrivateGetDataType(std::integral_constant<T, C>**, OverloadRank0)
{
	iferr_scope;
	DataType t = CheckedGetDataType<T, Or<GET_DATATYPE_POLICY, POLICY, GET_DATATYPE_POLICY::NO_DECAY, GET_DATATYPE_POLICY::ALLOW_BASEARRAY>::value>::Get() iferr_return;
	return ParametricTypes::IntegralConstant().Instantiate(t, ToSingletonBlock(Int64(C)));
}

/// @}

MAXON_DATATYPE_EARLY_ENUM(WRITEMETA, "net.maxon.datatype.enum.writemeta");
MAXON_DATATYPE_EARLY_ENUM(TARGETAUDIENCE, "net.maxon.datatype.enum.targetaudience");
MAXON_DATATYPE_EARLY_ENUM(OUTPUT, "net.maxon.datatype.enum.output");
MAXON_DATATYPE_EARLY_ENUM(VALUEKIND, "net.maxon.datatype.enum.valuekind");
MAXON_DATATYPE_EARLY_ENUM(COMPARERESULT, "net.maxon.datatype.enum.compareresult");
MAXON_DATATYPE_EARLY_ENUM(EQUALITY, "net.maxon.datatype.enum.equality");
MAXON_DATATYPE_EARLY_ENUM(COLLECTION_RESIZE_FLAGS, "net.maxon.datatype.enum.collection_resize_flags");

template <typename T, GET_DATATYPE_POLICY POLICY> struct CheckedGetDataType<T, POLICY, false>
{
	using ST = typename StandardType<typename std::decay<T>::type>::type;
	using type = typename std::decay<typename RemoveResult<decltype(PrivateGetDataType<POLICY>((ST**) nullptr, OVERLOAD_MAX_RANK))>::type>::type;

	static Result<type> Get()
	{
		// This uses argument-dependent lookup, so PrivateGetDataType is searched for also in the namespace of T.
		Result<type> res = PrivateGetDataType<POLICY>((ST**) nullptr, OVERLOAD_MAX_RANK);
		if (MAXON_LIKELY(res == OK) && MAXON_UNLIKELY(!res.GetValue()))
		{
			return UnregisteredDataTypeErrorObject();
		}
		return res;
	}
};

#include "datatype2.hxx"

} // namespace maxon

#include "maxon/registry.h"

#endif // DATATYPE_H__
