#ifndef PARAMETERTYPE_H__
#define PARAMETERTYPE_H__

#include "maxon/datatype.h"
#include "maxon/blockarray.h"
#include "maxon/array.h"

namespace maxon
{

namespace reflection
{

class ParameterType
{
public:
	enum class FLAGS
	{
		NONE = 0,
		INPUT = 1,
		OUTPUT = 2,
		EXPLICIT_INPUT_OUTPUT = 4
	} MAXON_ENUM_FLAGS_CLASS(FLAGS);

	explicit ParameterType(const DataType& t = DataType::NullValue(), FLAGS f = FLAGS::NONE) : _type(t), _typeForData(DataTypeLib::GetDataTypeForData(t) iferr_ignore("TODO")), _flags(f)
	{
	}

	const DataType& GetType() const
	{
		return _type;
	}

	//----------------------------------------------------------------------------------------
	/// Returns the DataType which is suitable to store a value for the parameter in a Data object.
	/// The exact parameter type is not always directly usable for a Data object. For example,
	/// the parameter type could be StringInterface* or BaseArray<Int>, but Data only works
	/// with String and Array<Int>. Therefore, a suitable DataType is derived from the parameter type as follows:
	/// - At first, pointer or reference classes are removed from the type as often as possible.
	/// - Then, if the resulting type is a BaseArray or Block type, replace it by the corresponding ArrayInterface type.
	/// - ConstDataPtr, DataPtr or an ArrayInterface thereof is replaced by Data or ArrayInterface<Data>, respectively.
	/// - Finally, if the resulting type is an interface type, use the reference class of that interface.
	///
	/// So StringInterface, StringInterface*, StringInterface**, String or String* are all mapped to String,
	/// and BaseArray<Int>, BaseArray<Int>* or Block<Int> are mapped to Array<Int>.
	/// @return												A DataType which can be used for a Data object to store values for the parameter.
	//----------------------------------------------------------------------------------------
	const DataType& GetTypeForData() const
	{
		return _typeForData;
	}

	FLAGS GetFlags() const
	{
		return _flags;
	}

	String ToString(const FormatStatement* fmt) const;

	template <typename T> static ParameterType Get()
	{
		const DataType& dt = maxon::GetDataType<T, Or<GET_DATATYPE_POLICY, GET_DATATYPE_POLICY::ERROR_FOR_UNKNOWN, GET_DATATYPE_POLICY::ALLOW_BASEARRAY, GET_DATATYPE_POLICY::NO_DECAY>::value>();
		FLAGS flags = FLAGS::INPUT;
		using X = typename std::conditional<std::is_reference<T>::value, typename std::remove_reference<T>::type*, T>::type;
		if (std::is_pointer<X>::value && !std::is_const<typename std::remove_pointer<X>::type>::value && !std::is_rvalue_reference<T>::value)
		{
			flags |= FLAGS::OUTPUT;
		}
		return ParameterType(dt, flags);
	};

	Result<Data> ToData(const Generic& value) const
	{
		iferr_scope;
		Data result;
		DataTypeLib::ConvertToData(result, _typeForData, _type, value) iferr_return;
		return std::move(result);
	}

	Result<void> MoveFromData(Generic& value, Data& data, BaseArray<Data>& storage) const
	{
		iferr_scope;
		CheckArgument((_typeForData == data.GetType()) || (_typeForData->GetValueKind() & VALUEKIND::DATA) || data.IsEmpty() ||
									data.GetType() == GetDataType<std::nullptr_t>());
		return DataTypeLib::MoveFromData(_type, value, data.GetType() != GetDataType<std::nullptr_t>() && !(_flags & FLAGS::INPUT), data, storage);
	}

private:
	DataType _type;
	DataType _typeForData;
	FLAGS _flags;
};

using Parameter = Tuple<ParameterType, Id>;

}

} // namespace maxon

#endif // PARAMETERTYPE_H__
