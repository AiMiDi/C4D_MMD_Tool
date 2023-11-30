#include "maxon/dataserialize.h"
#include "maxon/datatype_builder.h"
#include "maxon/datatypelib.h"
#include "maxon/errortypes.h"

#ifdef MAXON_TARGET_LINUX
	#include <alloca.h>
#endif
#ifdef  MAXON_TARGET_WINDOWS
	#include <malloc.h>
#endif

namespace maxon
{

namespace details
{
const COMPARERESULT g_compareResultIncomparable = COMPARERESULT::INCOMPARABLE;
}

DataType::Primary::Primary(const DataTypeImpl* type) : DataType(type)
{
	DebugAssert(!(type->_flags & DataTypeImpl::FLAGS::GLOBALLY_REFERENCED));
	// Use fast path and avoid reference counting.
	const_cast<DataTypeImpl*>(type)->_flags |= DataTypeImpl::FLAGS::GLOBALLY_REFERENCED;
}

UniqueHash DataType::GetUniqueHashCode() const
{
	return DefaultCompare::GetUniqueHashCode(_ptr);
}

Result<void> DataTypeCache::Init(Bool showMsg) const
{
	iferr (_type = _init())
	{
		if (showMsg && !err.IsInstanceOf<UnregisteredDataTypeError>())
		{
			DiagnosticOutput("Error while initializing data type: @", err);
		}
		_type = DataTypeLib::GetInvalidType();
		return err;
	}

	if (!(_type.PrivateGetPointer()->_flags & DataTypeImpl::FLAGS::GLOBALLY_REFERENCED))
	{
		// Use fast path and avoid reference counting.
		const_cast<DataTypeImpl*>(_type.PrivateGetPointer())->_flags |= DataTypeImpl::FLAGS::GLOBALLY_REFERENCED;
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
	const Int sz = SIZEOF(Member) * types.GetCount();
	Member* const mem = (Member*) alloca(sz);
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
	const Int sz = SIZEOF(Member) * types.GetCount();
	Member* const mem = (Member*) alloca(sz);
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

Result<void> Member::DescribeIO(const DataSerializeInterface& stream)
{
	iferr_scope;
	PrepareDescribe(stream, Member);
	Describe("type", type, decltype(type), DESCRIBEFLAGS::NONE) iferr_return;
	Describe("name", name, decltype(name), DESCRIBEFLAGS::NONE) iferr_return;
	return OK;
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
	if (formatStatement)
	{
		CString n = formatStatement->Get("datatype");
		if (n == "fullname"_cs)
		{
			ifnoerr (String s = DataTypeBuilderInterface::GetDataTypeName(*this, DATATYPEBUILDERNAME::CODE_CPP))
			{
				if (s.IsPopulated())
					return s;
			}
		}
	}

	return _ptr ? _ptr->_id.ToString(formatStatement) : "nullptr"_s;
}

Result<DataType> DataType::Get(const Id& typeId)
{
	return DataTypeLib::GetDataType(typeId);
}

void DataType::Reset()
{
	_ptr = nullptr;
}

ConstDataPtr DataType::GetDefaultValue() const
{
	const Generic* def = _ptr ? _ptr->GetDefaultValue() : nullptr;
	return def ? ConstDataPtr(*this, def) : ConstDataPtr();
}

Result<void> DataTypeImpl::PrivateRegister() const
{
	return DataTypes::Insert(_id, DataType(this), nullptr);
}

void DataTypeImpl::PrivateSetStructType(const TupleDataType& tupleType, const Int* offsets)
{
	_underlying = tupleType._ptr;
	_describeIO = _underlying->_describeIO;
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

void DataTypeImpl::PrivateSetTypeArgs(StrongRef<const TypeArguments>&& args)
{
	DebugAssert(!_typeArgs);
	if (args)
	{
		for (const Member& mb : *args)
		{
			_valueKind |= mb.type.GetValueKind() & VALUEKIND::CONTAINS_MASK;
		}
	}
	new (&_typeArgs) StrongRef<const TypeArguments>(std::move(args));

}

// Use DataTypePtr instead of DataType, otherwise we'd introduce circular references.
using ConversionArray = BaseArray<Tuple<DataTypePtr, CONVERSION_FLAGS, DataType::Conversion>>;

Result<void> DataTypeImpl::InitializeDefaultValue()
{
	iferr_scope;
	CheckState(!_defaultValue && !(_valueKind & VALUEKIND::ABSTRACT));
	if (_valueKind & VALUEKIND::ZERO_INITIALIZED && _size <= ZERO_MEMORY_SIZE)
	{
		_defaultValue = reinterpret_cast<const Generic*>(g_zeroMemory);
	}
	else
	{
		const void* ptr = Create() iferr_return;
		_defaultValue = reinterpret_cast<const Generic*>(ptr);
		_flags |= FLAGS::OWNS_DEFAULT_VALUE;
	}
	return OK;
}

DataTypeImpl::~DataTypeImpl()
{
	ResetRefs();
}

void DataTypeImpl::ResetDefaultValue()
{
	if (_flags & FLAGS::OWNS_DEFAULT_VALUE)
	{
		Destruct(_defaultValue);
		System::Free(_defaultValue);
		_flags &= ~FLAGS::OWNS_DEFAULT_VALUE;
	}
	_defaultValue = nullptr;
}

void DataTypeImpl::ResetRefs()
{
	ResetDefaultValue();
	if (_valueKind & VALUEKIND::RESOLVED_RECURSIVE_CONTAINER)
	{
		reinterpret_cast<const void*&>(_underlying) = nullptr;
	}
	else
	{
		_underlying = nullptr;
	}
	_elementType = nullptr;
	_extraType = nullptr;
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
	CheckArgument(srcType && t);
#if !defined MAXON_COMPILER_CLANG && !defined MAXON_COMPILER_GCC
	CheckArgument(&dest != nullptr);
#endif

	if (t.IsCastableFrom(srcType))
	{
		return t._ptr->_copyFrom(t._ptr, &dest, 0, src.PrivateGetPtr(), 0, 1);
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
		while (t->_underlying)
			t = t->_underlying;
		while (o->_underlying)
			o = o->_underlying;
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
	if (!o || !t)
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

Bool DataType::IsBaseOfOrSameImpl(const DataType& other, BASE_OF_MODE mode) const
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

Result<void> Data::Init(const DataType& type)
{
	if (type == _typeInfo)
		return OK;
	if (_typeInfo)
	{
		_typeInfo->FreeData(&_memBlock);
		_typeInfo.Reset();
	}
	if (!type || type->GetValueKind() & VALUEKIND::DATA)
	{
		return OK;
	}
	Result<void> r = type->InitData(&_memBlock);
	if (MAXON_UNLIKELY(r == FAILED))
	{
		return r;
	}
	_typeInfo = type;
	return OK;
}

Result<void> Data::CopyFrom(const Data& src)
{
	if (_typeInfo != src._typeInfo)
	{
		Reset();
		if (src._typeInfo)
		{
			Result<void> r = src._typeInfo->InitCopyData(&_memBlock, &src._memBlock);
			if (MAXON_UNLIKELY(r == FAILED))
			{
				return r;
			}
			_typeInfo = src._typeInfo;
		}
	}
	else if (_typeInfo)
	{
		Result<void> r = _typeInfo->CopyData(&_memBlock, &src._memBlock);
		if (MAXON_UNLIKELY(r == FAILED))
		{
			Reset();
			return r;
		}
	}
	return OK;
}

Result<void> Data::CopyFrom(const ConstDataPtr& src)
{
	const DataTypePtr type = src.GetType();
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
		Result<void> r = type->CopyFrom((void*) type->GetPtr(&_memBlock), value);
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
	const DataTypePtr type = src.GetType();
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
		type->MoveFrom((void*) type->GetPtr(&_memBlock), value);
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
	CheckArgument(destType);
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

Generic* Data::GetPtr(const DataType& type)
{
	if (!type)
		return nullptr;
	if (type->GetValueKind() & VALUEKIND::DATA)
		return (Generic*) this;
	if (!_typeInfo)
		return nullptr;
	if (type == _typeInfo)
		return (Generic*) type->GetPtr(&_memBlock);
	if (type->GetValueKind() & _typeInfo->GetValueKind() & VALUEKIND::OBJECT_REF)
		return (Generic*) CheckInstanceOf(reinterpret_cast<const ObjectRef*>(&_memBlock), type);
	if (type.IsCastableFrom(_typeInfo))
		return (Generic*) type->GetPtr(&_memBlock);
	return nullptr;
}

COMPARERESULT Data::Compare(const Data& c) const
{
	if (_typeInfo && c._typeInfo)
	{
		if ((_typeInfo == c._typeInfo) || (_typeInfo->GetValueKind() & c._typeInfo->GetValueKind() & VALUEKIND::OBJECT_REF) || _typeInfo.IsSimilar(c._typeInfo))
		{
			const void* ptr1 = _typeInfo->GetPtr(&_memBlock);
			const void* ptr2 = _typeInfo->GetPtr(&c._memBlock);
			return _typeInfo->Compare(ptr1, ptr2);
		}
		// support mixed use of data types
		if (_typeInfo->GetValueKind() & VALUEKIND::OBJECT_REF)
			return COMPARERESULT::GREATER; // object types are sorted above other types
		if (c._typeInfo->GetValueKind() & VALUEKIND::OBJECT_REF)
			return COMPARERESULT::LESS; // ..
		// both types are non-object types, sort by type id
		return _typeInfo->GetId().Compare(c._typeInfo->GetId());
	}
	else if (c._typeInfo)
	{
		return COMPARERESULT::LESS;
	}
	else if (_typeInfo)
	{
		return COMPARERESULT::GREATER;
	}
	return COMPARERESULT::EQUAL;
}

Bool Data::IsEqual(const Data& other, EQUALITY equality) const
{
	if (!_typeInfo)
	{
		return !other._typeInfo;
	}
	else if ((_typeInfo == other._typeInfo)
					 || (other._typeInfo && (_typeInfo->GetValueKind() & other._typeInfo->GetValueKind() & VALUEKIND::OBJECT_REF))
					 || _typeInfo.IsSimilar(other._typeInfo))
	{
		return _typeInfo->IsEqualData(&_memBlock, &other._memBlock, equality);
	}
	else
	{
		return false;
	}
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
		type->Destruct(obj);
		System::Free(obj);
	}
}

Result<void> AbstractDataTypeFunctions::DescribeIO(const DataTypeImpl* type, const DataSerializeInterface& dsi)
{
	return FunctionNotImplementedError(MAXON_SOURCE_LOCATION, FormatString("Function DescribeIO not implemented by @.", type));
}

void AbstractDataTypeFunctions::Construct(const DataTypeImpl* type, void* dest, Int dstride, Int count)
{
	CriticalStop("Function Construct not implemented by @.", type);
}

void AbstractDataTypeFunctions::Destruct(const DataTypeImpl* type, const void* dest, Int dstride, Int count)
{
	CriticalStop("Function Destruct not implemented by @.", type);
}

void AbstractDataTypeFunctions::MoveConstruct(const DataTypeImpl* type, void* dest, Int dstride, void* src, Int sstride, Int count)
{
	CriticalStop("Function MoveConstruct not implemented by @.", type);
}

void AbstractDataTypeFunctions::MoveFrom(const DataTypeImpl* type, void* dest, Int dstride, void* src, Int sstride, Int count)
{
	type->Destruct(dest, dstride, count);
	type->MoveConstruct(dest, dstride, src, sstride, count);
}

Result<void> AbstractDataTypeFunctions::CopyFrom(const DataTypeImpl* type, void* dest, Int dstride, const void* src, Int sstride, Int count)
{
	return FunctionNotImplementedError(MAXON_SOURCE_LOCATION, FormatString("Function CopyFrom not implemented by @.", type)).DbgStop();
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

HashInt AbstractDataTypeFunctions::GetHashCode(const DataTypeImpl* type, const void* a)
{
	CriticalStop("Function GetHashCode not implemented by @.", type);
	return 0;
}

UniqueHash AbstractDataTypeFunctions::GetUniqueHashCode(const DataTypeImpl* type, const void* a)
{
	CriticalStop("Function GetUniqueHashCode not implemented by @.", type);
	return UniqueHash();
}

String AbstractDataTypeFunctions::ToStringImpl(const DataTypeImpl* type, const void* a, const FormatStatement* formatStatement)
{
	return FormatString("@(@)", type->GetId(), a);
}

Result<void*> AbstractDataTypeFunctions::Create(const DataTypeImpl* type)
{
	iferr_scope;
	Char* ptr = NewMem(Char, type->GetSize()) iferr_return;
	type->Construct(ptr);
	return ptr;
}

Result<void> AbstractDataTypeFunctions::InitData(const DataTypeImpl* type, DataMemBlock* mem)
{
	iferr_scope;
	if (MAXON_UNLIKELY(type->GetValueKind() & VALUEKIND::ABSTRACT))
	{
		return IllegalArgumentError(MAXON_SOURCE_LOCATION, FormatString("Can't create a Data object for abstract type @.", type));
	}
	else if (type->GetSize() <= SIZEOF(DataMemBlock))
	{
		type->Construct(mem);
	}
	else
	{
		Char* ptr = NewMem(Char, type->GetSize()) iferr_return;
		*(void**) mem = ptr;
		type->Construct(ptr);
	}
	return OK;
}

void AbstractDataTypeFunctions::FreeData(const DataTypeImpl* type, DataMemBlock* mem)
{
	if (type->GetSize() <= SIZEOF(DataMemBlock))
	{
		type->Destruct(mem);
	}
	else
	{
		void*& ptr = *(void**) mem;
		if (ptr)
		{
			type->Destruct(ptr);
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
	return type->CopyFrom((void*) GetPtr(type, d), GetPtr(type, s));
}

Result<void> AbstractDataTypeFunctions::InitCopyData(const DataTypeImpl* type, DataMemBlock* d, const DataMemBlock* s)
{
	iferr_scope;
	if (type->GetSize() <= SIZEOF(DataMemBlock))
	{
		type->Construct(d);
		return type->CopyFrom(d, s);
	}
	else
	{
		Char* ptr = NewMem(Char, type->GetSize()) iferr_return;
		*(void**) d = ptr;
		type->Construct(ptr);
		iferr (type->CopyFrom(ptr, *(const void**) s))
		{
			type->Destruct(ptr);
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
		type->MoveFrom(d, s);
		type->Destruct(s);
	}
	else
	{
		void*& ptr = *(void**) d;
		if (ptr)
		{
			type->Destruct(ptr);
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
		type->MoveConstruct(d, s);
		type->Destruct(s);
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

void DataTypeImpl::PrivateAddReference() const
{
	const_cast<StrongReferenceCounter*>(reinterpret_cast<const StrongReferenceCounter*>(this))[-1].Inc();
}

void DataTypeImpl::PrivateRemoveReference() const
{
	if (MAXON_UNLIKELY(const_cast<StrongReferenceCounter*>(reinterpret_cast<const StrongReferenceCounter*>(this))[-1].Dec()))
	{
		DataTypeLib::PrivateHandleUnreferencedType(const_cast<DataTypeImpl*>(this));
	}
}

}
