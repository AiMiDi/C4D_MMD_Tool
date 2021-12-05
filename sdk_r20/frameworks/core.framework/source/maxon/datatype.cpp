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

Result<const DataType*> ParametricTypeInterface::Instantiate(const DataType* type, const Block<const Int64>& iargs) const
{
	if (type == nullptr)
		return CreateError(MAXON_SOURCE_LOCATION, ERROR_TYPE::NULLPTR);
	return Instantiate(ToSingletonBlock(Member{type}), iargs);
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


#define INITTYPE(NAME) \
	ResultMemT<const DataType*> DataType::PrivateInit##NAME() const \
	{ \
		return ParametricTypes::NAME().Instantiate(this) iferr_ignore("nullptr indicates error for ResultMemT"); \
	}

INITTYPE(Const);
INITTYPE(Opaque);
INITTYPE(Pointer);
INITTYPE(LVReference);
INITTYPE(RVReference);
INITTYPE(UniqueReference);
INITTYPE(StrongReference);
INITTYPE(COWReference);
INITTYPE(ACOWReference);
INITTYPE(Block);
INITTYPE(StridedBlock);
INITTYPE(Optional);
INITTYPE(Result);

String DataType::ToString(const FormatStatement* formatStatement) const
{
	return _id.ToString(formatStatement);
}

String DataType::ToString(const void* s, const FormatStatement* formatStatement) const
{
	return _toString(this, s, formatStatement);
}

Result<const DataType*> DataType::Get(const Id& typeId)
{
	return DataTypeLib::GetDataType(typeId);
}

Result<void> DataType::PrivateRegister() const
{
	return DataTypes::Insert(GetId(), this, nullptr);
}

void DataType::PrivateSetStructType(const TupleDataType* tupleType, const TypeArguments* members, const Int* offsets)
{
	_underlying = tupleType;
	_typeArgs = members;
	if (tupleType)
	{
		DebugAssert(_valueKind & VALUEKIND::STRUCT);
		for (Int i = 0, n = members->count; i < n; ++i)
		{
			if (tupleType->GetMemberOffset(i) != offsets[i])
			{
				CriticalOutput("Offset mismatch of member @ of @.", members->args[i].name, GetId());
				CriticalStop();
			}
			if (tupleType->GetTypeArguments()[i].type != members->args[i].type)
			{
				CriticalOutput("Type mismatch of member @ of @.", members->args[i].name, GetId());
				CriticalStop();
			}
		}
	}
}

using ConversionArray = BaseArray<Tuple<const DataType*, CONVERSION_FLAGS, DataType::Conversion>>;

void DataType::Reset()
{
	if (!(_valueKind & VALUEKIND::QUALIFIER_MASK))
	{
		if (_valueKind & VALUEKIND::OWNS_TYPE_ARGUMENTS)
		{
			TypeArguments::Free(_typeArgs);
			PrivateSetStructType(nullptr, nullptr, nullptr);
		}
		else if (_valueKind & VALUEKIND::VIRTUAL_INTERFACE)
		{
			DeleteMem(_interfaces);
		}
	}
	static_assert(SIZEOF(ConversionArray) == SIZEOF(_conversions), "Size of _conversions doesn't match BaseArray size.");
	ConversionArray& cv = reinterpret_cast<ConversionArray&>(_conversions);
	cv.Reset();
	for (AtomicPtr<const DataType>* start = &_const, *end = &_result + 1; start != end; ++start)
	{
		const DataType* x = start->LoadAcquire();
		DeleteObj(x);
		start->StoreRelease(nullptr);
	}
}

Result<void> DataType::AddConversion(const DataType* destType, CONVERSION_FLAGS kind, Conversion&& func) const
{
	const ConversionArray& cv = reinterpret_cast<const ConversionArray&>(_conversions);
	return const_cast<ConversionArray&>(cv).Append(Tuple<const DataType*, CONVERSION_FLAGS, Conversion>(destType, kind, std::move(func)));
}

Result<void> DataType::Convert(Generic& dest, const ConstDataPtr& src, CONVERSION_FLAGS ignore) const
{
	iferr_scope;
	const DataType* t = GetUnqualifiedType();
	const DataType* srcType = src.GetType();
	CheckArgument(srcType != nullptr);
#if !defined MAXON_COMPILER_CLANG && !defined MAXON_COMPILER_GCC
	CheckArgument(&dest != nullptr);
#endif

	if (t->IsCastableFrom(srcType))
	{
		return t->_copyFrom(t, &dest, src.PrivateGetPtr(), 1);
	}
	const ConversionArray& cv = reinterpret_cast<const ConversionArray&>(t->_conversions);
	for (const auto& c : cv)
	{
		if (srcType == c.Get<0>() && !(c.Get<1>() & ignore))
		{
			return c.Get<2>()(DataPtr(t, &dest), src);
		}
	}
	if (t->_parametricType)
		return t->_parametricType->Convert(DataPtr(t, &dest), src, ignore);
	return UnsupportedArgumentError(MAXON_SOURCE_LOCATION, FormatString("No known conversion from @ to @.", srcType, t));
}

Bool DataType::IsSimilar(const DataType* other) const
{
	const DataType* t = this;
	while (true)
	{
		if (!t || !other)
			return false;
		t = t->GetUnqualifiedType();
		other = other->GetUnqualifiedType();
		if (t == other)
			return true;
		if (t->_valueKind & other->_valueKind & (VALUEKIND::REF_OR_POINTER | VALUEKIND::ARRAY | VALUEKIND::BLOCK | VALUEKIND::STRIDED_BLOCK | VALUEKIND::RESULT))
		{
			t = t->_elementType;
			other = other->_elementType;
		}
		else
		{
			return false;
		}
	}
}

Bool DataType::IsCastableFrom(const DataType* other) const
{
	if (this == other)
		return true;
	if (!other)
		return false;
	if (_valueKind & VALUEKIND::GENERIC)
		return true;
	const DataType* t = this;
	while (t->_underlying)
		t = t->_underlying;
	while (other->_underlying)
		other = other->_underlying;
	return t == other
		|| ((t->_valueKind & other->_valueKind & VALUEKIND::INTEGRAL) && t->_size == other->_size)
		|| ((t->_valueKind & other->_valueKind & VALUEKIND::REF_OR_POINTER) && t->GetElementType()->IsBaseOfOrSame(other->GetElementType()));
}

Bool DataType::IsBaseOfOrSameImpl(const DataType* other, MEMBER_MATCH_MODE mode) const
{
	return DataTypeLib::IsBaseOfOrSame(this, other, mode);
}

String Data::ToString(const FormatStatement* formatStatement) const
{
	const void* ptr = nullptr;
	if (_typeInfo && ((ptr = _typeInfo->GetPtr(&_memBlock)) != nullptr))
		return _typeInfo->ToString(ptr, formatStatement);
	return "nulldata"_s;
}

const ObjectRef* Data::CheckInstanceOf(const ObjectRef* ref, const DataType* type)
{
	const Object* o = ref->GetPointer();
	return (o && o->PrivateIsInstanceOf(type->GetElementType())) ? ref : nullptr;
}

const Object* Data::CheckInstanceOf(const Object* o, const DataType* type)
{
	return (o && o->PrivateIsInstanceOf(type)) ? o : nullptr;
}

Result<void> Data::CopyFrom(const ConstDataPtr& src)
{
	const DataType* type = src.GetType();
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
	const DataType* type = src.GetType();
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

Result<Data> Data::ConvertData(const DataType* destType) const
{
	iferr_scope;
	Data dest;
	dest.Init(destType) iferr_return;
	destType->Convert(const_cast<Generic&>(*dest.PrivateGetPtr()), ConstDataPtr(*this)) iferr_return;
	return std::move(dest);
}

String ConstDataPtr::ToString(const FormatStatement* formatStatement) const
{
	if (this->_typeInfo && this->_dataPtr)
		return this->_typeInfo->ToString(this->_dataPtr, formatStatement);
	return "nulldata"_s;
}

Result<void> DataType::DescribeIO(const DataSerializeInterface& dsi) const
{
	return _describeIO(this, dsi);
}

Result<void*> DataType::Create() const
{
	return _newInstance(this);
}


void AbstractDataTypeFunctions::AddReference(const DataType* type, const void* obj)
{
	maxon::details::PrivateGetReferenceCounter(obj).Inc();
}

void AbstractDataTypeFunctions::RemoveReference(const DataType* type, const void* obj)
{
	if (maxon::details::PrivateGetReferenceCounter(obj).Dec())
	{
		type->Destruct(obj, 1);
		System::Free(obj);
	}
}

Result<void> AbstractDataTypeFunctions::DescribeIO(const DataType* type, const DataSerializeInterface& dsi)
{
	return FunctionNotImplementedError(MAXON_SOURCE_LOCATION, FormatString("Function DescribeIO not implemented by @.", type)).DbgStop();
}

void AbstractDataTypeFunctions::Construct(const DataType* type, void* dest, Int count)
{
	CriticalStop("Function Construct not implemented by @.", type);
}

void AbstractDataTypeFunctions::Destruct(const DataType* type, const void* dest, Int count)
{
	CriticalStop("Function Destruct not implemented by @.", type);
}

void AbstractDataTypeFunctions::MoveConstruct(const DataType* type, void* dest, void* src, Int count)
{
	CriticalStop("Function MoveConstruct not implemented by @.", type);
}

void AbstractDataTypeFunctions::MoveFrom(const DataType* type, void* dest, void* src, Int count)
{
	type->Destruct(dest, count);
	type->MoveConstruct(dest, src, count);
}

Result<void> AbstractDataTypeFunctions::CopyFrom(const DataType* type, void* dest, const void* src, Int count)
{
	return FunctionNotImplementedError(MAXON_SOURCE_LOCATION, FormatString("Function CopyFrom not implemented by @.", type)).DbgStop();
}

Result<Bool> AbstractDataTypeFunctions::UpdateFrom(const DataType* type, void* dest, const void* src)
{
	iferr_scope;
	if (type->IsEqual(dest, src, EQUALITY::SHALLOW))
		return false;
	type->CopyFrom(dest, src, 1) iferr_return;
	return true;
}

Bool AbstractDataTypeFunctions::IsEqual(const DataType* type, const void* a, const void* b, EQUALITY equality)
{
	CriticalStop("Function IsEqual not implemented by @.", type);
	return false;
}

COMPARERESULT AbstractDataTypeFunctions::Compare(const DataType* type, const void* a, const void* b)
{
	CriticalStop("Function Compare not implemented by @.", type);
	return COMPARERESULT::INCOMPARABLE;
}

UInt AbstractDataTypeFunctions::GetHashCode(const DataType* type, const void* a)
{
	CriticalStop("Function GetHashCode not implemented by @.", type);
	return 0;
}

String AbstractDataTypeFunctions::ToStringImpl(const DataType* type, const void* a, const FormatStatement* formatStatement)
{
	return FormatString("@(@)", type->GetId(), a);
}

Result<void*> AbstractDataTypeFunctions::Create(const DataType* type)
{
	iferr_scope;
	Char* ptr = NewMem(Char, type->GetSize()) iferr_return;
	type->Construct(ptr, 1);
	return ptr;
}

Result<void> AbstractDataTypeFunctions::InitData(const DataType* type, DataMemBlock* mem)
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

void AbstractDataTypeFunctions::FreeData(const DataType* type, DataMemBlock* mem)
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

const void* AbstractDataTypeFunctions::GetPtr(const DataType* type, const DataMemBlock* s)
{
	return (type->GetSize() <= SIZEOF(DataMemBlock)) ? (const void*) s : *(const void**) s;
}

Result<void> AbstractDataTypeFunctions::CopyData(const DataType* type, DataMemBlock* d, const DataMemBlock* s)
{
	return type->CopyFrom((void*) GetPtr(type, d), GetPtr(type, s), 1);
}

Result<void> AbstractDataTypeFunctions::InitCopyData(const DataType* type, DataMemBlock* d, const DataMemBlock* s)
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

void AbstractDataTypeFunctions::MoveData(const DataType* type, DataMemBlock* d, DataMemBlock* s)
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

void AbstractDataTypeFunctions::InitMoveData(const DataType* type, DataMemBlock* d, DataMemBlock* s)
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

Bool AbstractDataTypeFunctions::IsEqualData(const DataType* type, const DataMemBlock* a, const DataMemBlock* b, EQUALITY equality)
{
	const void* aa = GetPtr(type, a);
	const void* bb = GetPtr(type, b);
	return type->IsEqual(aa, bb, equality);
}

}
