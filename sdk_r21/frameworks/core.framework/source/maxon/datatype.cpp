#include "maxon/datatypelib.h"
#include "maxon/dataserialize.h"

namespace maxon
{

namespace details
{
const COMPARERESULT g_compareResultIncomparable = COMPARERESULT::INCOMPARABLE;
}

Result<void> DataTypeCache::Init(Bool showMsg) const
{
	iferr (_type = _init())
	{
		if (showMsg && !err.IsInstanceOf<UnregisteredDataTypeError>())
		{
			DiagnosticOutput("Error while initializing data type: @", err);
		}
		return err;
	}
	return OK;
}

DataTypeCache::DataTypeCache(InitFunction* init, ModuleInfo* module) : _next(module->_dataTypeCaches), _init(init)
{
	module->_dataTypeCaches = this;
}

Result<DataType> ParametricTypeInterface::Instantiate(const DataType& type, const Block<const Int64>& iargs) const
{
	if (!type)
		return CreateError(MAXON_SOURCE_LOCATION, ERROR_TYPE::NULLPTR);
	return Instantiate(ToSingletonBlock(Member{type}), iargs);
}

Result<DataType> ParametricTypeInterface::Instantiate(const Block<const DataType>& types, const Block<const Int64>& iargs) const
{
	Int sz = SIZEOF(Member) * types.GetCount();
	Member* mem = (Member*) alloca(sz);
	ClearMem(mem, sz);
	Member* m = mem;
	for (const DataType& t : types)
	{
		reinterpret_cast<DataTypePtr&>(m->type) = t;
		++m;
	}
	return Instantiate(ToBlock(mem, types.GetCount()), iargs);
}

Result<DataType> ParametricTypeInterface::Instantiate(Result<DataType>&& type, const Block<const Int64>& iargs) const
{
	if (type == FAILED)
		return type.GetErrorStorage();
	return Instantiate(ToSingletonBlock(Member{std::move(type.GetValue())}), iargs);
}

Result<DataType> ParametricTypeInterface::PrivateInstantiate(Block<Result<DataType>>&& types) const
{
	iferr_scope;
	Int sz = SIZEOF(Member) * types.GetCount();
	Member* mem = (Member*) alloca(sz);
	ClearMem(mem, sz);
	Member* m = mem;
	for (const Result<DataType>& t : types)
	{
		reinterpret_cast<DataTypePtr&>(m->type) = t iferr_return;
		++m;
	}
	return Instantiate(ToBlock(mem, types.GetCount()));
}

String Member::ToString(const FormatStatement* fmt) const
{
	if (name.IsPopulated())
		return type->GetId().ToString(fmt) + " "_s + name.ToString(fmt);
	else if (type)
		return type->GetId().ToString(fmt);
	else
		return "null"_s;
}

String DataTypeImpl::ToString(const FormatStatement* formatStatement) const
{
	return _id.ToString(formatStatement);
}

String DataTypeImpl::ToString(const void* s, const FormatStatement* formatStatement) const
{
	return _toString(this, s, formatStatement);
}

String DataType::ToString(const FormatStatement* formatStatement) const
{
	return _ptr->_id.ToString(formatStatement);
}

Result<DataType> DataType::Get(const Id& typeId)
{
	return DataTypeLib::GetDataType(typeId);
}

void DataType::Reset()
{
	_ptr = nullptr;
}

Result<void> DataTypeImpl::PrivateRegister() const
{
	return DataTypes::Insert(_id, DataType(this), nullptr);
}

void DataTypeImpl::PrivateSetStructType(const TupleDataType& tupleType, const Int* offsets)
{
	_underlying = tupleType._ptr;
	PrivateSetTypeArgs(_underlying->_typeArgs);
	DebugAssert(_valueKind & VALUEKIND::STRUCT);
	for (Int i = 0, n = _typeArgs->count; i < n; ++i)
	{
		if (tupleType.GetMemberOffset(i) != offsets[i])
		{
			CriticalOutput("Offset mismatch of member @ of @.", _typeArgs->args[i].name, _id);
			CriticalStop();
		}
		if (tupleType.GetTypeArguments()[i].type != _typeArgs->args[i].type)
		{
			CriticalOutput("Type mismatch of member @ of @.", _typeArgs->args[i].name, _id);
			CriticalStop();
		}
	}
}

// Use DataTypePtr instead of DataType, otherwise we'd introduce circular references.
using ConversionArray = BaseArray<Tuple<DataTypePtr, CONVERSION_FLAGS, DataType::Conversion>>;

DataTypeImpl::~DataTypeImpl()
{
	ResetRefs();
}

void DataTypeImpl::ResetRefs()
{
	_underlying = nullptr;
	_elementType = nullptr;
	if ((_valueKind & (VALUEKIND::QUALIFIER_MASK | VALUEKIND::VIRTUAL_INTERFACE)) == VALUEKIND::VIRTUAL_INTERFACE)
	{
		DeleteMem(_interfaces);
	}
	else if (HasTypeArguments())
	{
		StrongRefHandler::RemoveReference(_typeArgs);
		_typeArgs = nullptr;
	}
	static_assert(SIZEOF(ConversionArray) == SIZEOF(_conversions), "Size of _conversions doesn't match BaseArray size.");
	ConversionArray& cv = reinterpret_cast<ConversionArray&>(_conversions);
	cv.Reset();
}

Result<void> DataType::AddConversion(const DataType& destType, CONVERSION_FLAGS kind, Conversion&& func) const
{
	const ConversionArray& cv = reinterpret_cast<const ConversionArray&>(_ptr->_conversions);
	return const_cast<ConversionArray&>(cv).Append(Tuple<DataTypePtr, CONVERSION_FLAGS, Conversion>(destType, kind, std::move(func)));
}

Result<void> DataType::Convert(Generic& dest, const ConstDataPtr& src, CONVERSION_FLAGS ignore) const
{
	iferr_scope;
	const DataType& t = GetUnqualifiedType();
	const DataType& srcType = src.GetType().GetUnqualifiedType();
	CheckArgument(srcType);
#if !defined MAXON_COMPILER_CLANG && !defined MAXON_COMPILER_GCC
	CheckArgument(&dest != nullptr);
#endif

	if (t.IsCastableFrom(srcType))
	{
		return t._ptr->_copyFrom(t._ptr, &dest, src.PrivateGetPtr(), 1);
	}
	const ConversionArray& cv = reinterpret_cast<const ConversionArray&>(t._ptr->_conversions);
	for (const auto& c : cv)
	{
		if (srcType == c.Get<0>() && !(c.Get<1>() & ignore))
		{
			return c.Get<2>()(DataPtr(t, &dest), src);
		}
	}
	if (t._ptr->_parametricType)
		return t._ptr->_parametricType->Convert(DataPtr(t, &dest), src, ignore);
	return UnsupportedArgumentError(MAXON_SOURCE_LOCATION, FormatString("No known conversion from @ to @.", srcType, t));
}

Bool DataType::IsSimilar(const DataType& other) const
{
	const DataTypeImpl* t = _ptr;
	const DataTypeImpl* o = other._ptr;
	while (true)
	{
		if (!t || !o)
			return false;
		t = reinterpret_cast<const DataType&>(t).GetUnqualifiedType()._ptr;
		o = reinterpret_cast<const DataType&>(o).GetUnqualifiedType()._ptr;
		if (t == o)
			return true;
		if (t->_valueKind & o->_valueKind & (VALUEKIND::REF_OR_POINTER | VALUEKIND::ARRAY | VALUEKIND::BLOCK | VALUEKIND::STRIDED_BLOCK | VALUEKIND::RESULT))
		{
			t = t->_elementType;
			o = o->_elementType;
		}
		else
		{
			return false;
		}
	}
}

Bool DataType::IsCastableFrom(const DataType& other) const
{
	const DataTypeImpl* t = _ptr;
	const DataTypeImpl* o = other._ptr;
	if (t == o)
		return true;
	if (!o)
		return false;
	if (t->_valueKind & VALUEKIND::GENERIC)
		return true;
	while (t->_underlying)
		t = t->_underlying;
	while (o->_underlying)
		o = o->_underlying;
	return t == o
		|| ((t->_valueKind & o->_valueKind & VALUEKIND::INTEGRAL) && t->_size == o->_size)
		|| ((t->_valueKind & o->_valueKind & VALUEKIND::REF_OR_POINTER) && reinterpret_cast<const DataType&>(t->_elementType).IsBaseOfOrSame(reinterpret_cast<const DataType&>(o->_elementType)));
}

Bool DataType::IsBaseOfOrSameImpl(const DataType& other, MEMBER_MATCH_MODE mode) const
{
	return DataTypeLib::PrivateIsBaseOfOrSame(_ptr, other._ptr, mode);
}

String Data::ToString(const FormatStatement* formatStatement) const
{
	const void* ptr = nullptr;
	if (_typeInfo && ((ptr = _typeInfo->GetPtr(&_memBlock)) != nullptr))
		return _typeInfo->ToString(ptr, formatStatement);
	return "nulldata"_s;
}

const ObjectRef* Data::CheckInstanceOf(const ObjectRef* ref, const DataType& type)
{
	const ObjectInterface* o = ref->GetPointer();
	return (o && o->PrivateIsInstanceOf(type.GetElementType())) ? ref : nullptr;
}

const ObjectInterface* Data::CheckInstanceOf(const ObjectInterface* o, const DataType& type)
{
	return (o && o->PrivateIsInstanceOf(type)) ? o : nullptr;
}

Result<void> Data::CopyFrom(const ConstDataPtr& src)
{
	const DataType& type = src.GetType();
	const Generic* value = src.PrivateGetPtr();

	if (type && (type->GetValueKind() & VALUEKIND::DATA))
	{
		return CopyFrom(*reinterpret_cast<const Data*>(value));
	}

	if (_typeInfo != type)
	{
		Reset();
		if (type)
		{
			Result<void> r = type->InitData(&_memBlock);
			if (MAXON_UNLIKELY(r == FAILED))
			{
				return r;
			}
			_typeInfo = type;
		}
	}
	if (type)
	{
		Result<void> r = type->CopyFrom((void*) type->GetPtr(&_memBlock), value, 1);
		if (MAXON_UNLIKELY(r == FAILED))
		{
			Reset();
			return r;
		}
	}
	return OK;
}

Result<void> Data::MoveFrom(MoveDataPtr&& src)
{
	const DataType& type = src.GetType();
	Generic* value = src.PrivateGetPtr();

	if (type && (type->GetValueKind() & VALUEKIND::DATA))
	{
		*this = std::move(*reinterpret_cast<Data*>(value));
		return OK;
	}

	if (_typeInfo != type)
	{
		Reset();
		if (type)
		{
			Result<void> r = type->InitData(&_memBlock);
			if (MAXON_UNLIKELY(r == FAILED))
			{
				return r;
			}
			_typeInfo = type;
		}
	}
	if (type)
	{
		type->MoveFrom((void*) type->GetPtr(&_memBlock), value, 1);
	}
	return OK;
}

Result<void> Data::CopyFrom(ForwardingDataPtr&& src)
{
	iferr_scope;
	Data d = src.GetData() iferr_return;
	*this = std::move(d);
	return OK;
}

Result<Data> Data::ConvertData(const DataType& destType) const
{
	iferr_scope;
	Data dest;
	dest.Init(destType) iferr_return;
	destType.Convert(const_cast<Generic&>(*dest.PrivateGetPtr()), ConstDataPtr(*this)) iferr_return;
	return std::move(dest);
}

ConstDataPtr Data::ToConstDataPtr(const DataType& expectedType) const
{
	if (!expectedType)
		return ConstDataPtr(*this);
	if (expectedType->GetValueKind() & VALUEKIND::DATA)
		return ConstDataPtr(expectedType, reinterpret_cast<const Generic*>(this));
	if (expectedType.IsCastableFrom(_typeInfo))
		return ConstDataPtr(expectedType, PrivateGetPtr());
	return {};
}

String ConstDataPtr::ToString(const FormatStatement* formatStatement) const
{
	if (this->_typeInfo && this->_dataPtr)
		return this->_typeInfo->ToString(this->_dataPtr, formatStatement);
	return "nulldata"_s;
}

#ifdef MAXON_TARGET_DEBUG
void DataType::AssertTypeImpl(const DataType& other) const
{
	if (_ptr != other._ptr)
	{
		DiagnosticOutput("Attempt to access value of type @ as @.", _ptr ? _ptr->_id.GetCString() : nullptr, other._ptr ? other._ptr->_id.GetCString() : nullptr);
	}
}
#endif

void AbstractDataTypeFunctions::AddReference(const DataTypeImpl* type, const void* obj)
{
	maxon::details::PrivateGetReferenceCounter(obj).Inc();
}

void AbstractDataTypeFunctions::RemoveReference(const DataTypeImpl* type, const void* obj)
{
	if (maxon::details::PrivateGetReferenceCounter(obj).Dec())
	{
		type->Destruct(obj, 1);
		System::Free(obj);
	}
}

Result<void> AbstractDataTypeFunctions::DescribeIO(const DataTypeImpl* type, const DataSerializeInterface& dsi)
{
	return FunctionNotImplementedError(MAXON_SOURCE_LOCATION, FormatString("Function DescribeIO not implemented by @.", type)).DbgStop();
}

void AbstractDataTypeFunctions::Construct(const DataTypeImpl* type, void* dest, Int count)
{
	CriticalStop("Function Construct not implemented by @.", type);
}

void AbstractDataTypeFunctions::Destruct(const DataTypeImpl* type, const void* dest, Int count)
{
	CriticalStop("Function Destruct not implemented by @.", type);
}

void AbstractDataTypeFunctions::MoveConstruct(const DataTypeImpl* type, void* dest, void* src, Int count)
{
	CriticalStop("Function MoveConstruct not implemented by @.", type);
}

void AbstractDataTypeFunctions::MoveFrom(const DataTypeImpl* type, void* dest, void* src, Int count)
{
	type->Destruct(dest, count);
	type->MoveConstruct(dest, src, count);
}

Result<void> AbstractDataTypeFunctions::CopyFrom(const DataTypeImpl* type, void* dest, const void* src, Int count)
{
	return FunctionNotImplementedError(MAXON_SOURCE_LOCATION, FormatString("Function CopyFrom not implemented by @.", type)).DbgStop();
}

Result<Bool> AbstractDataTypeFunctions::UpdateFrom(const DataTypeImpl* type, void* dest, const void* src)
{
	iferr_scope;
	if (type->IsEqual(dest, src, EQUALITY::SHALLOW))
		return false;
	type->CopyFrom(dest, src, 1) iferr_return;
	return true;
}

Bool AbstractDataTypeFunctions::IsEqual(const DataTypeImpl* type, const void* a, const void* b, EQUALITY equality)
{
	CriticalStop("Function IsEqual not implemented by @.", type);
	return false;
}

COMPARERESULT AbstractDataTypeFunctions::Compare(const DataTypeImpl* type, const void* a, const void* b)
{
	CriticalStop("Function Compare not implemented by @.", type);
	return COMPARERESULT::INCOMPARABLE;
}

UInt AbstractDataTypeFunctions::GetHashCode(const DataTypeImpl* type, const void* a)
{
	CriticalStop("Function GetHashCode not implemented by @.", type);
	return 0;
}

String AbstractDataTypeFunctions::ToStringImpl(const DataTypeImpl* type, const void* a, const FormatStatement* formatStatement)
{
	return FormatString("@(@)", type->GetId(), a);
}

Result<void*> AbstractDataTypeFunctions::Create(const DataTypeImpl* type)
{
	iferr_scope;
	Char* ptr = NewMem(Char, type->GetSize()) iferr_return;
	type->Construct(ptr, 1);
	return ptr;
}

Result<void> AbstractDataTypeFunctions::InitData(const DataTypeImpl* type, DataMemBlock* mem)
{
	iferr_scope;
	if (type->GetSize() <= SIZEOF(DataMemBlock))
	{
		type->Construct(mem, 1);
	}
	else
	{
		Char* ptr = NewMem(Char, type->GetSize()) iferr_return;
		*(void**) mem = ptr;
		type->Construct(ptr, 1);
	}
	return OK;
}

void AbstractDataTypeFunctions::FreeData(const DataTypeImpl* type, DataMemBlock* mem)
{
	if (type->GetSize() <= SIZEOF(DataMemBlock))
	{
		type->Destruct(mem, 1);
	}
	else
	{
		void*& ptr = *(void**) mem;
		if (ptr)
		{
			type->Destruct(ptr, 1);
			DeleteMem(ptr);
		}
	}
}

const void* AbstractDataTypeFunctions::GetPtr(const DataTypeImpl* type, const DataMemBlock* s)
{
	return (type->GetSize() <= SIZEOF(DataMemBlock)) ? (const void*) s : *(const void**) s;
}

Result<void> AbstractDataTypeFunctions::CopyData(const DataTypeImpl* type, DataMemBlock* d, const DataMemBlock* s)
{
	return type->CopyFrom((void*) GetPtr(type, d), GetPtr(type, s), 1);
}

Result<void> AbstractDataTypeFunctions::InitCopyData(const DataTypeImpl* type, DataMemBlock* d, const DataMemBlock* s)
{
	iferr_scope;
	if (type->GetSize() <= SIZEOF(DataMemBlock))
	{
		type->Construct(d, 1);
		return type->CopyFrom(d, s, 1);
	}
	else
	{
		Char* ptr = NewMem(Char, type->GetSize()) iferr_return;
		*(void**) d = ptr;
		type->Construct(ptr, 1);
		iferr (type->CopyFrom(ptr, *(const void**) s, 1))
		{
			type->Destruct(ptr, 1);
			DeleteMem(ptr);
			*(void**) d = nullptr;
			return err;
		}
		return OK;
	}
}

void AbstractDataTypeFunctions::MoveData(const DataTypeImpl* type, DataMemBlock* d, DataMemBlock* s)
{
	if (type->GetSize() <= SIZEOF(DataMemBlock))
	{
		type->MoveFrom(d, s, 1);
		type->Destruct(s, 1);
	}
	else
	{
		void*& ptr = *(void**) d;
		if (ptr)
		{
			type->Destruct(ptr, 1);
			DeleteMem(ptr);
		}
		*(void**) d = *(void**) s;
		*(void**) s = nullptr;
	}
}

void AbstractDataTypeFunctions::InitMoveData(const DataTypeImpl* type, DataMemBlock* d, DataMemBlock* s)
{
	if (type->GetSize() <= SIZEOF(DataMemBlock))
	{
		type->MoveConstruct(d, s, 1);
		type->Destruct(s, 1);
	}
	else
	{
		*(void**) d = *(void**) s;
		*(void**) s = nullptr;
	}
}

Bool AbstractDataTypeFunctions::IsEqualData(const DataTypeImpl* type, const DataMemBlock* a, const DataMemBlock* b, EQUALITY equality)
{
	const void* aa = GetPtr(type, a);
	const void* bb = GetPtr(type, b);
	return type->IsEqual(aa, bb, equality);
}

void DataTypeImpl::AddReference() const
{
	const_cast<StrongReferenceCounter*>(reinterpret_cast<const StrongReferenceCounter*>(this))[-1].Inc();
}

void DataTypeImpl::RemoveReference() const
{
	if (MAXON_UNLIKELY(const_cast<StrongReferenceCounter*>(reinterpret_cast<const StrongReferenceCounter*>(this))[-1].Dec()))
	{
		DataTypeLib::PrivateHandleUnreferencedType(const_cast<DataTypeImpl*>(this));
	}
}

}
