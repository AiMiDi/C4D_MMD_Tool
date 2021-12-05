#ifndef PARAMETRIC_TYPE_H__
#define PARAMETRIC_TYPE_H__

#include "maxon/registrybase.h"

namespace maxon
{

class ParametricTypeInterface
{
	MAXON_INTERFACE_SIMPLE_VIRTUAL(ParametricTypeInterface, MAXON_REFERENCE_CONST);
public:
	MAXON_METHOD const Id& GetId() const;

	MAXON_METHOD Result<const DataType*> Instantiate(const Block<const Member>& args, const Block<const Int64>& iargs) const;

	MAXON_FUNCTION Result<const DataType*> Instantiate(const DataType* type, const Block<const Int64>& iargs = GetZeroRef<Block<const Int64>>()) const;

	MAXON_METHOD Bool IsBaseOfOrSame(const DataType* type, const DataType* other) const;

	MAXON_METHOD Result<void> Convert(const DataPtr& dest, const ConstDataPtr& src, CONVERSION_FLAGS ignore) const;

	MAXON_METHOD Result<Tuple<const DataType*, const Char*>> Parse(const Char* params) const;

	MAXON_METHOD Result<const DataType*> Substitute(const DataType* orig, const Delegate<Result<const DataType*>(const DataType*)>& replace) const;
};

#include "parametric_type1.hxx"

MAXON_REGISTRY(ParametricType, ParametricTypes, "net.maxon.registry.parametrictypes");

namespace ParametricTypes
{
	MAXON_DECLARATION(ParametricType, Const, "net.maxon.parametrictype.const");
	MAXON_DECLARATION(ParametricType, Opaque, "net.maxon.parametrictype.opaque");
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

	MAXON_DECLARATION(ParametricType, IntegralConstant, "net.maxon.parametrictype.integralconstant");

	MAXON_DECLARATION(ParametricType, BaseArray, "net.maxon.parametrictype.basearray");
};

#include "parametric_type2.hxx"

} // namespace maxon

#endif // PARAMETRIC_TYPE_H__
