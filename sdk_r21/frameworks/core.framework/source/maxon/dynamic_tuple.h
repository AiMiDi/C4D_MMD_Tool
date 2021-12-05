#ifndef DYNAMIC_TUPLE_H__
#define DYNAMIC_TUPLE_H__

#include "maxon/interfacebase.h"
#include "maxon/optional.h"
#include "maxon/viewiterator.h"

namespace maxon
{


class GenericSingletonContainerInterface : public GenericContainerInterface MAXON_GENERIC_BASE(T)
{
	MAXON_INTERFACE_SIMPLE_VIRTUAL_DERIVED(GenericSingletonContainerInterface, MAXON_REFERENCE_COPY_ON_WRITE);
	MAXON_GENERIC((Out) typename T = ParameterPack<>);
public:
	MAXON_METHOD const TupleDataType& GetTupleType() const;

	MAXON_METHOD void GetMemberPointers(const Block<const Generic*>& pointers, const TupleDataType& members) const;

	MAXON_FUNCTION void GetMemberPointers(const Block<Generic*>& pointers, const TupleDataType& members)
	{
		return GetMemberPointers(reinterpret_cast<const Block<const Generic*>&>(pointers), members);
	}
	
	MAXON_METHOD const Generic* GetMemberPointer(const InternedId& name) const;

	MAXON_FUNCTION Generic* GetMemberPointer(const InternedId& name)
	{
		return MAXON_NONCONST_COUNTERPART(GetMemberPointer(name));
	}

	MAXON_METHOD const Generic* GetAllMemberPointers(const Block<const Generic*>& pointers, Bool skipPointersIfTupleLayout) const;

	MAXON_METHOD const Generic& Get(Int index) const;

	MAXON_FUNCTION Generic& Get(Int index)
	{
		return MAXON_NONCONST_COUNTERPART(Get(index));
	}

	template <typename ATTR> MAXON_FUNCTION Opt<const typename ATTR::ValueType&> Get() const
	{
		return Get(ATTR::GetId());
	}
};


#include "dynamic_tuple1.hxx"

#include "dynamic_tuple2.hxx"

namespace details
{
inline void SingletonContainerImpl_InitIterator(const TupleDataType& type, const Char* tuple, ViewIteratorMember* members, const MemberMap* map)
{
	const Int* ofs = DataTypeLib::GetTupleMemberOffsets(type).GetFirst();
	for (Int m : *map)
	{
		members->SetConstant(reinterpret_cast<const Generic*>(tuple + ofs[m]));
		++members;
	}
}
}

template <typename NAMED_TUPLE, Bool PTR_FOR_REF = false> class SingletonContainerImpl : private GenericSingletonContainerInterface
{
#define ToInterface PrivateToInterface
	MAXON_IMPLEMENTATION_SIMPLE(SingletonContainerImpl, typename);
#undef ToInterface

public:
	template <typename... ARGS> explicit SingletonContainerImpl(ARGS&&... args) : GenericSingletonContainerInterface(_clsMTable), _value(std::forward<ARGS>(args)...)
	{
	}

	using CInterface = typename NAMED_TUPLE::Pack::template Apply<SingletonContainerInterface>;

	const CInterface* ToInterface() const
	{
		return static_cast<const CInterface*>(PrivateToInterface());
	}

	CInterface* ToInterface()
	{
		return static_cast<CInterface*>(PrivateToInterface());
	}

	const ContainerDataType& GetType() const
	{
		return NAMED_TUPLE::GetContainerType();
	}

	const TupleDataType& GetTupleType() const
	{
		return NAMED_TUPLE::GetDataType();
	}
	
	Result<GenericContainerInterface*> Clone() const
	{
		iferr_scope;
		using WithPtrForRefs = SingletonContainerImpl<NAMED_TUPLE, true>;
		UniqueRef<WithPtrForRefs> copy = NewObj(WithPtrForRefs) iferr_return;
		AssignCopy(copy->_value, reinterpret_cast<const typename NAMED_TUPLE::TupleTypeWithPtrsForRefs&>(_value)) iferr_return;
		return reinterpret_cast<SingletonContainerImpl*>(copy.Disconnect());
	}

	String ToString(const FormatStatement* formatStatement) const
	{
		return _value.ToString(formatStatement);
	}

	void GetMemberPointers(const Block<const Generic*>& pointers, const TupleDataType& members) const
	{
		if (members == NAMED_TUPLE::GetDataType())
		{
			GetAllMemberPointers(pointers, false);
		}
		else
		{
			DebugAssert(pointers.GetCount() == members.GetTypeArguments().count);
			auto ptr = pointers.Begin();
			for (const Member& mb : members.GetTypeArguments())
			{
				*(ptr++) = GetMemberPointer(mb.name);
			}
		}
	}

	const Generic* GetMemberPointer(const InternedId& name) const
	{
		Int offset = NAMED_TUPLE::FindOffset(name);
		return (offset >= 0) ? reinterpret_cast<const Generic*>(reinterpret_cast<const Char*>(&_value) + offset) : nullptr;
	}

	Int FindMemberIndex(const InternedId& name) const
	{
		return NAMED_TUPLE::FindIndex(name);
	}

	const Generic* GetAllMemberPointers(const Block<const Generic*>& pointers, Bool skipPointersIfTupleLayout) const
	{
		if (!skipPointersIfTupleLayout)
		{
			DebugAssert(pointers.GetCount() == NAMED_TUPLE::TupleType::COUNT);
			if (NAMED_TUPLE::TupleType::COUNT == 1)
			{
				pointers[0] = reinterpret_cast<const Generic*>(&_value);
			}
			else
			{
				auto ptr = pointers.Begin();
				for (Int ofs : DataTypeLib::GetTupleMemberOffsets(NAMED_TUPLE::GetDataType()))
				{
					*(ptr++) = reinterpret_cast<const Generic*>(reinterpret_cast<const Char*>(&_value) + ofs);
				}
			}
		}
		return reinterpret_cast<const Generic*>(&_value);
	}

	const Generic& Get(Int index) const
	{
		return *reinterpret_cast<const Generic*>(reinterpret_cast<const Char*>(&_value) + NAMED_TUPLE::GetDataType().GetMemberOffset(index));
	}

	Int GetIteratorStateSize(const MemberMap* map) const
	{
		return 0;
	}

	Result<Int> InitIterator(ViewIteratorMember* members, const MemberMap* map, Char* state) const
	{
		maxon::details::SingletonContainerImpl_InitIterator(NAMED_TUPLE::GetDataType(), reinterpret_cast<const Char*>(&_value), members, map);
		return 1;
	}

	Result<Int> ValidateIterator(Int index, ViewIteratorMember* members, const MemberMap* map, Char* state) const
	{
		return -1;
	}

	void FreeIterator(ViewIteratorMember* members, const MemberMap* map, Char* state) const
	{
	}

	Result<Int> MoveIterator(Int index, ViewIteratorMember* members, const MemberMap* map, Char* state) const
	{
		return UnsupportedOperationError(MAXON_SOURCE_LOCATION);
	}

	typename std::conditional<PTR_FOR_REF, typename NAMED_TUPLE::TupleTypeWithPtrsForRefs, typename NAMED_TUPLE::TupleType>::type _value;
};

template <typename NAMED_TUPLE, Bool PTR_FOR_REF> MAXON_IMPLEMENTATION_REGISTER_SIMPLE(SingletonContainerImpl<NAMED_TUPLE MAXON_COMMA PTR_FOR_REF>, typename);


}

#endif // DYNAMIC_TUPLE_H__
