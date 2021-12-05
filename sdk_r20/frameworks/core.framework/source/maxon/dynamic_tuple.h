#ifndef DYNAMIC_TUPLE_H__
#define DYNAMIC_TUPLE_H__

#include "maxon/interfacebase.h"
#include "maxon/optional.h"

namespace maxon
{

//----------------------------------------------------------------------------------------
/// @MAXON_ANNOTATION{refprefix=Generic}
//----------------------------------------------------------------------------------------
class DynamicTupleInterface
{
	MAXON_INTERFACE_SIMPLE_VIRTUAL(DynamicTupleInterface, MAXON_REFERENCE_NORMAL);
public:
	MAXON_METHOD void GetMemberPointers(const Generic** pointers, const TupleDataType* members) const;

	MAXON_FUNCTION void GetMemberPointers(Generic** pointers, const TupleDataType* members)
	{
		return GetMemberPointers((const Generic**) pointers, members);
	}
	
	MAXON_METHOD const Generic* GetMemberPointer(InternedId name, const DataType* type) const;

	MAXON_FUNCTION Generic* GetMemberPointer(InternedId name, const DataType* type)
	{
		return MAXON_NONCONST_COUNTERPART(GetMemberPointer(name, type));
	}

	MAXON_FUNCTION const Generic* GetMemberPointer(const Member& member) const
	{
		return GetMemberPointer(member.name, member.type);
	}

	MAXON_FUNCTION Generic* GetMemberPointer(const Member& member)
	{
		return MAXON_NONCONST_COUNTERPART(GetMemberPointer(member));
	}

	MAXON_METHOD const TupleDataType* GetType() const;
	
	//----------------------------------------------------------------------------------------
	/// Finds the index of the function input having the given name. If no such input
	/// can be found, -1 is returned.
	/// @param[in] name								Name of the function input to find.
	/// @return												Index of the function input, or -1 if it doesn't exist.
	/// @MAXON_ANNOTATION{default=-1}
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Int FindMemberIndex(InternedId name, const DataType* type) const;

	MAXON_FUNCTION Int FindMemberIndex(const Member& member) const
	{
		return FindMemberIndex(member.name, member.type);
	}

	MAXON_METHOD const Generic* GetAllMemberPointers(const Generic** pointers, Bool skipPointersIfTupleLayout) const;

	MAXON_METHOD const Generic* GetMemberPointer(Int index) const;

	MAXON_FUNCTION Generic* GetMemberPointer(Int index)
	{
		return MAXON_NONCONST_COUNTERPART(GetMemberPointer(index));
	}

	template <typename MEMBER> MAXON_FUNCTION Opt<const typename MEMBER::Type&> Get() const
	{
		return GetMemberPointer(MEMBER::GetId(), GetDataType<typename MEMBER::Type>());
	}

	MAXON_FUNCTION const Generic* Get(const Member& member) const
	{
		return GetMemberPointer(member.name, member.type);
	}
};


#include "dynamic_tuple1.hxx"

#include "dynamic_tuple2.hxx"

template <typename NAMED_TUPLE, Bool PTR_FOR_REF = false> class DynamicTupleImpl : private DynamicTupleInterface
{
	MAXON_IMPLEMENTATION_SIMPLE(DynamicTupleImpl, typename);

public:
	template <typename... ARGS> explicit DynamicTupleImpl(ARGS&&... args) : DynamicTupleInterface(_clsMTable), _value(std::forward<ARGS>(args)...)
	{
	}
	
	const TupleDataType* GetType() const
	{
		return _type;
	}
	
	void GetMemberPointers(const Generic** pointers, const TupleDataType* members) const
	{
		if (members == _type)
		{
			GetAllMemberPointers(pointers, false);
		}
		else
		{
			for (const Member& mb : members->GetTypeArguments())
			{
				*(pointers++) = GetMemberPointer(mb.name, mb.type);
			}
		}
	}

	const Generic* GetMemberPointer(InternedId name, const DataType* type) const
	{
		Int idx = FindMemberIndex(name, type);
		return idx >= 0 ? GetMemberPointer(idx) : nullptr;
	}

	Int FindMemberIndex(InternedId name, const DataType* type) const
	{
		return name.IsPopulated() ? NAMED_TUPLE::GetMembers().FindIndex(Member(type, name)) : -1;
	}

	const Generic* GetAllMemberPointers(const Generic** pointers, Bool skipPointersIfTupleLayout) const
	{
		if (!skipPointersIfTupleLayout)
		{
			if (NAMED_TUPLE::TupleType::COUNT == 1)
			{
				*pointers = reinterpret_cast<const Generic*>(&_value);
			}
			else
			{
				for (Int ofs : DataTypeLib::GetTupleMemberOffsets(_type))
				{
					*(pointers++) = reinterpret_cast<const Generic*>(reinterpret_cast<const Char*>(&_value) + ofs);
				}
			}
		}
		return reinterpret_cast<const Generic*>(&_value);
	}

	const Generic* GetMemberPointer(Int index) const
	{
		return reinterpret_cast<const Generic*>(reinterpret_cast<const Char*>(&_value) + _type->GetMemberOffset(index));
	}

	const TupleDataType* _type = NAMED_TUPLE::GetDataType();
	typename std::conditional<PTR_FOR_REF, typename NAMED_TUPLE::TupleTypeWithPtrsForRefs, typename NAMED_TUPLE::TupleType>::type _value;
};

template <typename NAMED_TUPLE, Bool PTR_FOR_REF> MAXON_IMPLEMENTATION_REGISTER_SIMPLE(DynamicTupleImpl<NAMED_TUPLE MAXON_COMMA PTR_FOR_REF>, typename);


}

#endif // DYNAMIC_TUPLE_H__
