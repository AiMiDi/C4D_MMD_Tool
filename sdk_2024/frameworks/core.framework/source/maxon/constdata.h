#ifndef CONSTDATA_H__
#define CONSTDATA_H__

#include "maxon/datatype.h"
#include "maxon/datatypebase.h"
#include "maxon/utilities/classhelpers.h"
#include "maxon/apibase.h"
#include "maxon/utilities/compilerdetection.h"
#include "maxon/utilities/resultbase.h"

namespace maxon
{

//----------------------------------------------------------------------------------------
/// ConstData derives from ConstDataPtr and behaves the same way if it holds no ownership over any data.
/// It also contains a Data object that may be used to hold ownership of generic data.
/// In that case the pointer in ConstDataPtr will target the generic data in the Data member.
/// The type of the object is only known at run-time.
//----------------------------------------------------------------------------------------
class ConstData : public ConstDataPtr
{
	MAXON_DISALLOW_COPY_AND_ASSIGN(ConstData);
public:

	ConstData();

	ConstData(ConstData&& src);

	ConstData(const ConstDataPtr& src);

	ConstData(ConstDataPtr&& src);

	explicit ConstData(const Data& src);

	template<typename T>
	explicit ConstData(T&& value) : ConstDataPtr(), _ownedData(std::forward<T>(value))
	{
		static_assert(!STD_IS_REPLACEMENT(same, T, ConstDataPtr));

		Set(_ownedData);
	}

	ConstData(const DataType& typeInfo, const Generic* dataPtr);

	ConstData& operator =(ConstData&& src);

	Result<void> CopyFrom(const ConstData& src);

	Result<void> CopyFrom(const Data& src);

	template<typename T>
	Result<void> MoveFrom(T&& src)
	{
		iferr_scope;

		_ownedData.Set(std::move(src)) iferr_return;
		Set(_ownedData);

		return OK;
	}

	Result<void> MoveFrom(Data& src);


private:
	Data _ownedData;
};

#include "constdata1.hxx"

MAXON_DATATYPE(ConstData, "net.maxon.datatype.constdata");

#include "constdata2.hxx"

} // namespace maxon

#endif // CONSTDATA_H__
