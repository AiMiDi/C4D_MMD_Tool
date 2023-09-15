#ifndef PARAMETRIC_TYPE_H__
#define PARAMETRIC_TYPE_H__

#include "maxon/registrybase.h"

namespace maxon
{

class ParametricTypeInterface
{
	MAXON_INTERFACE_SIMPLE_VIRTUAL(ParametricTypeInterface, MAXON_REFERENCE_CONST_POINTER);
public:
	MAXON_METHOD const Id& GetId() const;

	MAXON_METHOD Result<DataType> Instantiate(const Block<const Member>& args, const Block<const Int64>& iargs = GetZeroRef<Block<const Int64>>()) const;

	MAXON_FUNCTION Result<DataType> Instantiate(const DataType& type, const Block<const Int64>& iargs = GetZeroRef<Block<const Int64>>()) const;

	MAXON_FUNCTION Result<DataType> Instantiate(const Block<const DataType>& types, const Block<const Int64>& iargs = GetZeroRef<Block<const Int64>>()) const;

	MAXON_FUNCTION Result<DataType> Instantiate(Result<DataType>&& type, const Block<const Int64>& iargs = GetZeroRef<Block<const Int64>>()) const;

	MAXON_FUNCTION Result<DataType> PrivateInstantiate(Block<Result<DataType>>&& types) const;

	MAXON_METHOD Bool IsBaseOfOrSame(const DataType& type, const DataType& other) const;

	MAXON_METHOD Result<void> Convert(const DataPtr& dest, const ConstDataPtr& src, CONVERSION_FLAGS ignore) const;

	MAXON_METHOD Result<Tuple<DataType, const Char*>> Parse(const Char* params) const;

	MAXON_METHOD void ResetInstantiated(DataTypeImpl* type) const;

	MAXON_METHOD DataTypeImpl*& GetLeakingLink(DataTypeImpl* type) const;
};

#include "parametric_type1.hxx"

MAXON_REGISTRY(ParametricType, ParametricTypes, "net.maxon.registry.parametrictypes");

namespace ParametricTypes
{
	MAXON_DECLARATION(ParametricType, Const, "net.maxon.parametrictype.const");
	MAXON_DECLARATION(ParametricType, Pointer, "net.maxon.parametrictype.pointer");
	MAXON_DECLARATION(ParametricType, LVReference, "net.maxon.parametrictype.lvreference");
	MAXON_DECLARATION(ParametricType, RVReference, "net.maxon.parametrictype.rvreference");
	MAXON_DECLARATION(ParametricType, UniqueReference, "net.maxon.parametrictype.uniquereference");
	MAXON_DECLARATION(ParametricType, StrongReference, "net.maxon.parametrictype.strongreference");
	MAXON_DECLARATION(ParametricType, COWReference, "net.maxon.parametrictype.cowreference");
	MAXON_DECLARATION(ParametricType, ACOWReference, "net.maxon.parametrictype.acowreference");
	MAXON_DECLARATION(ParametricType, Block, "net.maxon.parametrictype.block");
	MAXON_DECLARATION(ParametricType, StridedBlock, "net.maxon.parametrictype.stridedblock");
	MAXON_DECLARATION(ParametricType, Optional, "net.maxon.parametrictype.optional");
	MAXON_DECLARATION(ParametricType, Result, "net.maxon.parametrictype.result");
	MAXON_DECLARATION(ParametricType, Atomic, "net.maxon.parametrictype.atomic");

	MAXON_DECLARATION(ParametricType, Simd, "net.maxon.parametrictype.simd");

	class ParametricTupleType : public ParametricType
	{
	public:
		using ParametricType::ParametricType;

		//----------------------------------------------------------------------------------------
		/// Returns a TupleDataType with members of the given @p types. On the first invocation
		/// for a specific @p types array, the data type will be constructed, later invocations
		/// will return the same data type object. The identifier of a tuple data type
		/// is a parenthesized list of the identifiers of the member types.
		/// @param[in] types							Array of member types for the tuple data type.
		/// @return												TupleDataType consisting of the given member types.
		//----------------------------------------------------------------------------------------
		maxon::Result<TupleDataType> Instantiate(const maxon::Block<const DataType>& types) const
		{
			maxon::Result<DataType> r = ParametricType::Instantiate(types);
			return std::move(reinterpret_cast<maxon::Result<TupleDataType>&>(r));
		}

		maxon::Result<TupleDataType> Instantiate(const maxon::Block<const Member>& members) const
		{
			maxon::Result<DataType> r = ParametricType::Instantiate(members);
			return std::move(reinterpret_cast<maxon::Result<TupleDataType>&>(r));
		}
	};

	template <GET_DATATYPE_POLICY POLICY> inline ResultOk<const DataType&> PrivateGetDataType(ParametricTupleType**, OverloadRank0)
	{
		return DataTypeLib::GetParametricTypeType();
	}

	MAXON_DECLARATION(ParametricTupleType, Tuple, "net.maxon.parametrictype.tuple");

	MAXON_DECLARATION(ParametricType, Bundle, "net.maxon.parametrictype.bundle");

	MAXON_DECLARATION(ParametricType, IntegralConstant, "net.maxon.parametrictype.integralconstant");

	MAXON_DECLARATION(ParametricType, BaseArray, "net.maxon.parametrictype.basearray");

	class ParametricContainerType : public ParametricType
	{
	public:
		using ParametricType::ParametricType;

		maxon::Result<ContainerDataType<>> Instantiate(const maxon::Block<const Member>& members) const
		{
			maxon::Result<DataType> r = ParametricType::Instantiate(members);
			return std::move(reinterpret_cast<maxon::Result<ContainerDataType<>>&>(r));
		}

		maxon::Result<ContainerDataType<>> Instantiate(const DataType& elementType) const
		{
			maxon::Result<DataType> r = ParametricType::Instantiate(elementType);
			return std::move(reinterpret_cast<maxon::Result<ContainerDataType<>>&>(r));
		}
	};

	template <GET_DATATYPE_POLICY POLICY> inline ResultOk<const DataType&> PrivateGetDataType(ParametricContainerType**, OverloadRank0)
	{
		return DataTypeLib::GetParametricTypeType();
	}

	MAXON_DECLARATION(ParametricContainerType, ContainerInterface, "net.maxon.parametrictype.container");

	MAXON_DECLARATION(ParametricType, RecursiveContainerInterface, "net.maxon.parametrictype.recursivecontainer");

	MAXON_DECLARATION(ParametricType, GenericInstantiation, "net.maxon.parametrictype.genericinstantiation");
};

	//----------------------------------------------------------------------------------------
	/// Helper to add multiple ParametricType on top of a DataType.
	//----------------------------------------------------------------------------------------
class ParametricTypeDecorator
{
public:

	//----------------------------------------------------------------------------------------
	/// Create a DataType decorated with the requested ParametricType.
	/// @param[in] type								The base type.
	/// @param[in] decoType						The single decoration.
	/// @return												A decorated DataType for Christmas party.
	//----------------------------------------------------------------------------------------
	static Result<DataType> Instantiate(const DataType& type, const ParametricType& decoType)
	{
		return decoType.Instantiate(type);
	}

	//----------------------------------------------------------------------------------------
	/// Create a DataType decorated with the requested ParametricType.
	/// @tparam TYPEDECORATOR1				The first decoration type.
	/// @tparam TYPEDECORATOR					Remaining decoration types to add.
	/// @param[in] type								The base type.
	/// @param[in] decoType						The single decoration.
	/// @param[in] decoTypes					The remaining decorations to apply.
	/// @return												A decorated DataType for Christmas party.
	//----------------------------------------------------------------------------------------
	template <typename TYPEDECORATOR1, typename... TYPEDECORATOR>
	static Result<DataType> Instantiate(const DataType& type, TYPEDECORATOR1 decoType, TYPEDECORATOR... decoTypes)
	{
		iferr_scope;
		// Add first type.
		const DataType newType = Instantiate(type, decoType) iferr_return;
		// Add the rest of the packed types.
		return Instantiate(newType, decoTypes...);
	}
};

#include "parametric_type2.hxx"

} // namespace maxon

#endif // PARAMETRIC_TYPE_H__
