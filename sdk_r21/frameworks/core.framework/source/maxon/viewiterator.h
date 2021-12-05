#ifndef VIEWITERATOR_H__
#define VIEWITERATOR_H__

#include "maxon/datatype.h"
#include "maxon/bitmanipulation.h"

namespace maxon
{


struct ViewIteratorMember
{
	const Generic* value;
	Int32 stride;
	SimdInfo::Compact simd;
#ifndef MAXON_TARGET_64BIT
	Int32 padding;
#endif

	void SetNoIndexing()
	{
		stride = 0;
		simd.alignmentMask = LIMIT<UChar>::MAX;
		simd.logMultiplicity = 0;
		simd.extraStrideFlags = 0;
	}

	void SetIndexing(Int str, const SimdInfo::Compact& simdInfo)
	{
		stride = Int32(str);
		simd = simdInfo;
	}

	void SetIndexing(const SimdBlock<const Generic>& block)
	{
		stride = Int32(block.GetComponentStride());
		simd = block.GetInfo();
	}

	void SetConstant(const Generic* ptr, Int32 flags = 0)
	{
		value = ptr;
		stride = 0;
		simd.alignmentMask = LIMIT<UChar>::MAX;
		simd.logMultiplicity = 0;
		simd.extraStrideFlags = UInt16(flags);
	}

	template <Bool ENABLE_SIMD = true> void Advance()
	{
		const Char*& p = reinterpret_cast<const Char*&>(value);
		p += stride;
		if (ENABLE_SIMD && MAXON_UNLIKELY((UInt(p) & UInt(simd.alignmentMask)) == 0))
		{
			p += simd.GetExtraStride();
		}
	}

	template <Bool ENABLE_SIMD = true> void Advance(Int advanceCount)
	{
		Int extra = simd.GetExtraStride();
		if (!ENABLE_SIMD || MAXON_LIKELY(extra == 0))
		{
			reinterpret_cast<const Char*&>(value) += stride * advanceCount;
		}
		else
		{
			// In the SIMD case, we cannot just add stride*advanceCount to the pointer.
			// Only the part of advanceCount which is a multiple of the SIMD multiplicity can be used for this, the rest
			// has to take care of the two possible step sizes (stride or stride+extraStride).
			UChar logMult = simd.logMultiplicity;
			// At first advance the pointer by a multiple of the multiplicity. (extraStride + alignmentMask + 1) is the
			// size of a complete SIMD vector, we have to divide this by the multiplicity to obtain the size of the
			// corresponding (hypothetical) non-SIMD vector. We just shift advanceCount by multLog, this does the division
			// and also masks out the lowest bits of advanceCount.
			reinterpret_cast<const Char*&>(value) += (extra + simd.alignmentMask + 1) * (advanceCount >> logMult);
			// Then do the remaining steps, those may be either small or large steps.
			for (Int i = advanceCount & ((Int(1) << logMult) - 1); i; --i)
			{
				Advance<ENABLE_SIMD>();
			}
		}
	}

	void PrivateRestorePointer(const Generic* ptr)
	{
		value = ptr;
	}
};

static_assert(std::is_trivial<ViewIteratorMember>::value, "ViewIteratorMember not trivial.");
static_assert(SIZEOF(ViewIteratorMember) == 16, "Unexpected size of ViewIteratorMember.");


struct MemberMap
{
	const Int count;
	Int members[MAXON_FLEXIBLE_ARRAY_LENGTH];

	Block<const Int> ToBlock() const
	{
		return {members, count};
	}

	Block<Int> ToBlock()
	{
		return {members, count};
	}

	using ValueType = Int;
	using ConstIterator = BaseIterator<const MemberMap, false>;

	//----------------------------------------------------------------------------------------
	/// Gets an iterator pointing to the first member index.
	/// @return												Iterator for the first member index.
	//----------------------------------------------------------------------------------------
	ConstIterator Begin() const
	{
		return ConstIterator(members);
	}

	//----------------------------------------------------------------------------------------
	/// Returns and iterator pointing to the end of the member indices (one behind last).
	/// @return												Iterator for the end of the member indices.
	//----------------------------------------------------------------------------------------
	ConstIterator End() const
	{
		return ConstIterator(members + count);
	}

private:
	explicit MemberMap(Int cnt) : count(cnt)
	{
	}

	friend class DataTypeLibImpl;
};

namespace details
{
template <typename PACK, Bool CONST_ITERATOR> class ContainerIterator;
}

class GenericContainerInterface
{
	MAXON_INTERFACE_SIMPLE_VIRTUAL(GenericContainerInterface, MAXON_REFERENCE_COPY_ON_WRITE);
	MAXON_GENERIC((Out) typename T = ParameterPack<>);
public:
	MAXON_METHOD const ContainerDataType& GetType() const;

	MAXON_METHOD Result<GenericContainerInterface*> Clone() const;

	MAXON_METHOD String ToString(const FormatStatement* formatStatement) const;

	//----------------------------------------------------------------------------------------
	/// Finds the member index of the member with the given #name in this. If no such member
	/// can be found, -1 is returned.
	/// @param[in] name								Name of the member to find.
	/// @return												Index of the member, or -1 if it doesn't exist.
	/// @MAXON_ANNOTATION{default=-1}
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Int FindMemberIndex(const InternedId& name) const;

	MAXON_FUNCTION Int FindMemberIndex(const Member& member) const
	{
		return FindMemberIndex(member.name);
	}

	MAXON_METHOD Int GetIteratorStateSize(const MemberMap* map) const;

	MAXON_METHOD Result<Int> InitIterator(ViewIteratorMember* members, const MemberMap* map, Char* state) const;

	MAXON_METHOD Result<Int> ValidateIterator(Int index, ViewIteratorMember* members, const MemberMap* map, Char* state) const;

	MAXON_METHOD void FreeIterator(ViewIteratorMember* members, const MemberMap* map, Char* state) const;

	MAXON_METHOD Result<Int> MoveIterator(Int index, ViewIteratorMember* members, const MemberMap* map, Char* state) const;

	// MAXON_METHOD Tuple<Int, DataTypePtr, INNERMOST_MEMBER> GetContainingMember(INNERMOST_MEMBER member) const;

	template <typename T> MAXON_FUNCTION maxon::details::ContainerIterator<T, true> Begin() const
	{
		return maxon::details::ContainerIterator<T, true>(this);
	}

	template <typename T> MAXON_FUNCTION PRIVATE_MAXON_RBF_SENTINEL(maxon::details::ContainerIterator<T, true>) End() const
	{
		return PRIVATE_MAXON_RBF_SENTINEL(maxon::details::ContainerIterator<T, true>)();
	}

	template <typename T> MAXON_FUNCTION maxon::details::ContainerIterator<T, false> Begin()
	{
		return maxon::details::ContainerIterator<T, false>(this);
	}

	template <typename T> MAXON_FUNCTION PRIVATE_MAXON_RBF_SENTINEL(maxon::details::ContainerIterator<T, false>) End()
	{
		return PRIVATE_MAXON_RBF_SENTINEL(maxon::details::ContainerIterator<T, false>)();
	}
};


#include "viewiterator1.hxx"
#include "viewiterator2.hxx"


template <GET_DATATYPE_POLICY POLICY, typename... T> inline ResultOk<const ContainerDataType&> PrivateGetDataType(ContainerInterface<T...>**, OverloadRank1)
{
	return NamedTuple<T...>::GetContainerType();
}

} // namespace maxon

#endif // VIEWITERATOR_H__
