#ifndef DATATYPEFUNCTIONS_H__
#define DATATYPEFUNCTIONS_H__

#include "maxon/string.h"
#include "maxon/errorbase.h"

namespace maxon
{

/// @addtogroup DATATYPE
/// @{
class DataSerializeReaderRef;
class DataSerializeWriterRef;
class DataSerializeInterface;

#ifndef DOXYGEN // Doxygen produces strange warning
// TODO: (Tilo) please document
MAXON_DETECT_MEMBER_HELPER(DescribeIO, const DataSerializeInterface&);
#endif

template <typename T> inline Result<void> DescribeIO(const T& s, const DataSerializeInterface& dsi)
{
	return FunctionNotImplementedError(MAXON_SOURCE_LOCATION).DbgStop();
}

// TODO: (Ole) Please check ...  d and s should always be types with reference when used from datatypelib_impl
template <typename T, typename SUPER> class DataTypeReferenceFunctions : public SUPER
{
public:
	static void AddReference(const DataType* type, const void* obj)
	{
		StrongRefHandler::AddReference((const T*) obj);
	}

	static void RemoveReference(const DataType* type, const void* obj)
	{
		StrongRefHandler::RemoveReference((const T*) obj);
	}
};

template <typename T> class DefaultDataTypeFunctionsBase : public DataTypeReferenceFunctions<T, EmptyClass>
{
public:
	static void Construct(const DataType*, void* dest, Int count)
	{
		while (--count >= 0)
		{
			new (dest) T();
			dest = (Char*) dest + SIZEOF(T);
		}
	}

	static void Destruct(const DataType*, const void* dest, Int count)
	{
		while (--count >= 0)
		{
			((const T*) dest)->~T();
			dest = (const Char*) dest + SIZEOF(T);
		}
	}

	static void MoveConstruct(const DataType*, void* dest, void* src, Int count)
	{
		while (--count >= 0)
		{
			new (dest) T(std::move(*(T*) src));
			src = (Char*) src + SIZEOF(T);
			dest = (Char*) dest + SIZEOF(T);
		}
	}

	static void MoveFrom(const DataType*, void* dest, void* src, Int count)
	{
		while (--count >= 0)
		{
			*(T*) dest = std::move(*(T*) src);
			src = (Char*) src + SIZEOF(T);
			dest = (Char*) dest + SIZEOF(T);
		}
	}

	static Result<void> CopyFrom(const DataType*, void* dest, const void* src, Int count)
	{
		while (--count >= 0)
		{
			iferr (AssignCopy<T>(*(T*) dest, *(const T*) src))
			{
				return err;
			}
			src = (Char*) src + SIZEOF(T);
			dest = (Char*) dest + SIZEOF(T);
		}
		return OK;
	}

	static Result<Bool> UpdateFrom(const DataType* type, void* dest, const void* src)
	{
		iferr_scope;
		if (CompareTemplate<true>::IsEqual(*(const T*) dest, *(const T*) src))
			return false;
		AssignCopy<T>(*(T*) dest, *(const T*) src) iferr_return;
		return true;
	}

	static Bool IsEqual(const DataType*, const void* a, const void* b, EQUALITY equality)
	{
		return (equality == EQUALITY::DEEP) ? CompareTemplate<true, EQUALITY::DEEP, OverloadRank1>::IsEqual(*(const T*) a, *(const T*) b) : CompareTemplate<true>::IsEqual(*(const T*) a, *(const T*) b);
	}

	static String ToStringImpl(const DataType*, const void* s, const FormatStatement* formatStatement) { return ToString(*(const T*)s, formatStatement, false); }
	static typename SFINAEHelper<Result<void>, T>::type DescribeIO(const DataType* type, const DataSerializeInterface& dsi) { return DescribeIOHelper(*(const T*)type, dsi); }
	static Result<void*> Create(const DataType*)
	{
		iferr (T* value = NewObj(T))
			return err;
		return value;
	}
	static COMPARERESULT Compare(const DataType*, const void* s1, const void* s2) { return CompareTemplate<true>::Compare(*(const T*)s1, *(const T*)s2); }
	static UInt GetHashCode(const DataType*, const void* s1) { return CompareTemplate<true>::GetHashCode(*(const T*)s1); }
};

enum class DATATYPEMODE
{
	SMALLISPOD,
	SMALL,
	BIG,
} MAXON_ENUM_LIST(DATATYPEMODE);

template <typename T, DATATYPEMODE TYPE> class DefaultDataTypeFunctions;

template <typename T> class DefaultDataTypeFunctions<T, DATATYPEMODE::SMALLISPOD> : public DefaultDataTypeFunctionsBase<T>
{
public:
	static const Bool FITS_IN_MEMBLOCK = true;
	static Result<void> InitData(const DataType*, DataMemBlock* mem) { *(T*)mem = T(); return OK; }
	static void FreeData(const DataType*, DataMemBlock* mem) { }
	static Result<void> CopyData(const DataType*, DataMemBlock* d, const DataMemBlock* s) { *(T*)d = *(const T*)s; return OK; }
	static Result<void> InitCopyData(const DataType*, DataMemBlock* d, const DataMemBlock* s) { *(T*)d = *(const T*)s; return OK; }
	static void MoveData(const DataType*, DataMemBlock* d, DataMemBlock* s) { *(T*)d = *(T*)s; }
	static void InitMoveData(const DataType*, DataMemBlock* d, DataMemBlock* s) { *(T*)d = *(T*)s; }
	static const void* GetPtr(const DataType*, const DataMemBlock* s) { return s; }
	static Bool IsEqualData(const DataType*, const DataMemBlock* a, const DataMemBlock* b, EQUALITY equality) { return CompareTemplate<true>::IsEqual(*(const T*) a, *(const T*) b); }

	static Result<void> Set(const DataType*, DataMemBlock* d, const T& s) { *(T*)d = s; return OK; }
	static Result<void> Set(const DataType*, DataMemBlock* d, T&& s) { *(T*) d = std::move(s); return OK; }
	static Result<void> Init(const DataType*, DataMemBlock* d, const T& s) { *(T*)d = s; return OK; }
	static Result<void> Init(const DataType*, DataMemBlock* d, T&& s) { *(T*)d = std::move(s); return OK; }
};

template <typename T> class DefaultDataTypeFunctions<T, DATATYPEMODE::SMALL> : public DefaultDataTypeFunctionsBase<T>
{
public:
	static const Bool FITS_IN_MEMBLOCK = true;
	static Result<void> InitData(const DataType*, DataMemBlock* mem) { new (mem) T(); return OK; }
	static void FreeData(const DataType*, DataMemBlock* mem) { ((T*)mem)->~T(); }
	static Result<void> CopyData(const DataType*, DataMemBlock* d, const DataMemBlock* s) { return AssignCopy(*(T*) d, *(const T*) s); }
	static Result<void> InitCopyData(const DataType*, DataMemBlock* d, const DataMemBlock* s) { new (d) T(); return AssignCopy(*(T*) d, *(const T*) s); }
	static void MoveData(const DataType*, DataMemBlock* d, DataMemBlock* s) { *(T*) d = std::move(*(T*) s); ((T*) s)->~T(); }
	static void InitMoveData(const DataType*, DataMemBlock* d, DataMemBlock* s) { new (d) T(std::move(*(T*) s)); ((T*) s)->~T(); }
	static const void* GetPtr(const DataType*, const DataMemBlock* s) { return s; }
	static Bool IsEqualData(const DataType*, const DataMemBlock* a, const DataMemBlock* b, EQUALITY equality) { return CompareTemplate<true>::IsEqual(*(const T*) a, *(const T*) b); }

	static Result<void> Set(const DataType*, DataMemBlock* d, const T& s) { return AssignCopy(*(T*) d, s); }
	static Result<void> Set(const DataType*, DataMemBlock* d, T&& s) { *(T*) d = std::move(s); return OK; }
	static Result<void> Init(const DataType*, DataMemBlock* d, const T& s) { new (d) T; return AssignCopy(*(T*) d, s); }
	static Result<void> Init(const DataType*, DataMemBlock* d, T&& s) { new (d) T(std::move(s)); return OK; }
};

template <typename T> class DefaultDataTypeFunctions<T, DATATYPEMODE::BIG> : public DefaultDataTypeFunctionsBase<T>
{
public:
	static const Bool FITS_IN_MEMBLOCK = false;
	static Result<void> InitData(const DataType*, DataMemBlock* mem)
	{
		iferr (*(T**)mem = NewObj(T))
			return err;
		return OK;
	}
	static void FreeData(const DataType*, DataMemBlock* mem) { DeleteObj(*(T**)mem); }
	static Result<void> CopyData(const DataType*, DataMemBlock* d, const DataMemBlock* s) { return AssignCopy(**(T**)d, **(T**)s); }
	static Result<void> InitCopyData(const DataType*, DataMemBlock* d, const DataMemBlock* s)
	{
		iferr (*(T**)d = NewObj(T))
			return err;
		Result<void> r = AssignCopy(**(T**)d, **(T**)s);
		if (MAXON_UNLIKELY(r == FAILED))
		{
			DeleteObj(*(T**)d);
			return r;
		}
		return OK;
	}
	static void MoveData(const DataType*, DataMemBlock* d, DataMemBlock* s) { DeleteObj(*(T**)d); *(T**)d = *(T**)s; *(T**)s = nullptr; }
	static void InitMoveData(const DataType*, DataMemBlock* d, DataMemBlock* s) { *(T**)d = *(T**)s; *(T**)s = nullptr; }
	static const void* GetPtr(const DataType*, const DataMemBlock* s) { return *(const T**)s; }
	static Bool IsEqualData(const DataType*, const DataMemBlock* a, const DataMemBlock* b, EQUALITY equality) { return CompareTemplate<true>::IsEqual(**(const T**) a, **(const T**) b); }

	static Result<void> Set(const DataType*, DataMemBlock* d, const T& s) { return AssignCopy(**(T**) d, s); }
	static Result<void> Set(const DataType*, DataMemBlock* d, T&& s) { **(T**) d = std::move(s); return OK; }
	static Result<void> Init(const DataType*, DataMemBlock* d, const T& s)
	{
		iferr (*(T**)d = NewObj(T))
			return err;
		Result<void> r = AssignCopy(**(T**)d, s);
		if (MAXON_UNLIKELY(r == FAILED))
		{
			DeleteObj(*(T**)d);
			return r;
		}
		return OK;
	}
	static Result<void> Init(const DataType*, DataMemBlock* d, T&& s)
	{
		iferr (*(T**)d = NewObj(T, std::move(s)))
			return err;
		return OK;
	}
};


template <typename T> struct DefaultDataTypeFunctionsCapabilityFlags
{
	using UT = UnderlyingType<T>;
	// CompareHelper uses "const COMPARERESULT&" as return type for the incomparable case
	static const VALUEKIND value = (IsPartiallyOrdered<UT>::value || std::is_reference<decltype(CompareTemplate<true>::CompareHelper(std::declval<UT>(), std::declval<UT>(), OVERLOAD_MAX_RANK))>::value) ? VALUEKIND::NONE : VALUEKIND::ORDERED;
};


template <typename T> class DataTypeFunctions : public DefaultDataTypeFunctions<T, (SIZEOF(T) > SIZEOF(DataMemBlock)) ? DATATYPEMODE::BIG : (std::is_pod<T>::value ? DATATYPEMODE::SMALLISPOD : DATATYPEMODE::SMALL)>
{
public:
	using UT = UnderlyingType<T>;
	static const VALUEKIND CAPABILITY_FLAGS = DefaultDataTypeFunctionsCapabilityFlags<T>::value;
};


Result<void*> DecltypeNewInstanceHelper(const void*);

template <typename T> static Result<void*> PrivateNewInterfaceInstance(OverloadRank0)
{
	return CreateError(MAXON_SOURCE_LOCATION, ERROR_TYPE::NOT_IMPLEMENTED);
}

template <typename T> MAXON_WARN_UNUSED static decltype(DecltypeNewInstanceHelper(T::Alloc(maxon::SourceLocation()))) PrivateNewInterfaceInstance(OverloadRank1)
{
	iferr (T* value = NewObj(T))
		return err;
	return value;
}

template <typename T> class InterfaceDataTypeFunctions : public DataTypeReferenceFunctions<T, AbstractDataTypeFunctions>
{
public:
	static Result<void*> Create(const DataType* type)
	{
		return PrivateNewInterfaceInstance<T>(OVERLOAD_MAX_RANK);
	}

	static Bool IsEqual(const DataType* type, const void* a, const void* b, EQUALITY equality)
	{
		return (equality == EQUALITY::DEEP) ? CompareTemplate<true, EQUALITY::DEEP, OverloadRank1>::IsEqual(*(const T*) a, (const T*) b) : CompareTemplate<true>::IsEqual(*(const T*) a, (const T*) b);
	}

	static COMPARERESULT Compare(const DataType* type, const void* a, const void* b)
	{
		return CompareTemplate<true>::Compare(*(const T*) a, (const T*) b);
	}

	static UInt GetHashCode(const DataType* type, const void* a)
	{
		return CompareTemplate<true>::GetHashCode(*(const T*) a);
	}

	static String ToStringImpl(const DataType* type, const void* a, const FormatStatement* formatStatement)
	{
		return GlobalToString(*(const T*) a, formatStatement);
	}

	static Result<void> DescribeIO(const DataType* type, const DataSerializeInterface& dsi)
	{
		return DescribeIOHelper(*(const T*) type, dsi);
	}

	static const VALUEKIND CAPABILITY_FLAGS = (IsPartiallyOrdered<T>::value || std::is_reference<decltype(CompareTemplate<true>::CompareHelper(std::declval<T>(), (const T*) nullptr, OVERLOAD_MAX_RANK))>::value) ? VALUEKIND::NONE : VALUEKIND::ORDERED;
};

/// @}

} // namespace maxon

#endif // DATATYPEFUNCTIONS_H__
