#ifndef INTERSECTION_UNION_TYPE_H__
#define INTERSECTION_UNION_TYPE_H__

#include "maxon/datatype.h"

namespace maxon
{

namespace ParametricTypes
{
	MAXON_DECLARATION(ParametricType, Intersection, "net.maxon.parametrictype.intersection");

	MAXON_DECLARATION(ParametricType, Union, "net.maxon.parametrictype.union");
};

template <typename... T> class IntersectionType
{
};

template <GET_DATATYPE_POLICY POLICY, typename... T> inline Result<DataType> PrivateGetDataType(IntersectionType<T...>**, OverloadRank0)
{
	Result<DataType> types[] = {CheckedGetDataType<T, POLICY>::Get()...};
	return ParametricTypes::Intersection().GetPointer()->PrivateInstantiate(ToBlock(types));
}

template <typename... T> class UnionType
{
};

template <GET_DATATYPE_POLICY POLICY, typename... T> inline Result<DataType> PrivateGetDataType(UnionType<T...>**, OverloadRank0)
{
	Result<DataType> types[] = {CheckedGetDataType<T, POLICY>::Get()...};
	return ParametricTypes::Union().GetPointer()->PrivateInstantiate(ToBlock(types));
}

}

#endif
