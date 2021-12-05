#ifndef SUBDATA_H__
#define SUBDATA_H__

#include "maxon/object.h"

namespace maxon
{

using SubDataPath = BaseArray<Data>;
using SubDataPathBlock = Block<const Data>;

class SubDataInterface : MAXON_INTERFACE_BASES(ObjectInterface)
{
	MAXON_INTERFACE(SubDataInterface, MAXON_REFERENCE_CONST, "net.maxon.interface.subdata");
public:
	MAXON_METHOD Result<void> Get(const ConstDataPtr& data, const SubDataPathBlock& path, Data& subvalue) const;

	MAXON_METHOD Result<Bool> Set(Data& data, const SubDataPathBlock& path, ForwardingDataPtr&& subvalue) const;
};

class SubData;

class SubDataOperationInterface : MAXON_INTERFACE_BASES(ObjectInterface)
{
	MAXON_INTERFACE(SubDataOperationInterface, MAXON_REFERENCE_CONST, "net.maxon.interface.subdataoperation");
public:
	MAXON_METHOD Result<Bool> Do(Data& data, const SubDataPathBlock& path, ForwardingDataPtr&& subvalue, Data* prevSubvalue = nullptr) const;

	MAXON_METHOD Result<Bool> Undo(Data& data, const SubDataPathBlock& path, ForwardingDataPtr&& subvalue, Data* prevSubvalue = nullptr) const;

	MAXON_METHOD const SubData& GetSubData() const;
};

#include "subdata1.hxx"

MAXON_REGISTRY(SubData, SubDatas, "net.maxon.registry.subdatas");

namespace SubDatas
{
	MAXON_DECLARATION(SubData, Default, "net.maxon.subdata.default");
}

MAXON_REGISTRY(SubDataOperation, SubDataOperations, "net.maxon.registry.subdataoperations");

namespace SubDataOperations
{
	MAXON_DECLARATION(SubDataOperation, DefaultSet, "net.maxon.subdataoperation.defaultset");
}

#include "subdata2.hxx"

}

#endif // SUBDATA_H__
