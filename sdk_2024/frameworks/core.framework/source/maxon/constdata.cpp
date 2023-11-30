#include "constdata.h"

namespace maxon
{

ConstData::ConstData()
{
}

ConstData::ConstData(ConstData&& src)
{
	if (src._dataPtr == src._ownedData.PrivateGetPtr())
	{
		_ownedData = std::move(src._ownedData);
		Set(_ownedData);
	}
	else
	{
		_typeInfo = std::move(src._typeInfo);
		_dataPtr = src._dataPtr;
	}
}

ConstData::ConstData(const Data& src) : ConstDataPtr(src)
{
}

ConstData::ConstData(ConstDataPtr&& src) : ConstDataPtr(src)
{
}

ConstData::ConstData(const ConstDataPtr& src) : ConstDataPtr(src)
{
}

ConstData::ConstData(const DataType& typeInfo, const Generic* dataPtr) : ConstDataPtr(typeInfo, dataPtr)
{
}

ConstData& ConstData::operator=(ConstData&& src)
{
	if (_dataPtr == src._ownedData.PrivateGetPtr())
	{
		_ownedData = std::move(src._ownedData);
		Set(_ownedData);
	}
	else
	{
		_typeInfo = std::move(src._typeInfo);
		_dataPtr = src._dataPtr;
	}
	return *this;
}

Result<void> ConstData::CopyFrom(const Data& src)
{
	iferr_scope;

	_ownedData.CopyFrom(src) iferr_return;
	Set(_ownedData);

	return OK;
}

Result<void> ConstData::CopyFrom(const ConstData& src)
{
	iferr_scope;

	_ownedData.CopyFrom(src) iferr_return;
	Set(_ownedData);

	return OK;
}

Result<void> ConstData::MoveFrom(Data& src)
{
	_ownedData = std::move(src);
	Set(_ownedData);

	return OK;
}

} // namespace maxon
