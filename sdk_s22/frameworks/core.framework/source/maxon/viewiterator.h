#ifndef VIEWITERATOR_H__
#define VIEWITERATOR_H__

#include "maxon/datatype.h"

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

	void SetIndexing(Int str)
	{
		stride = Int32(str);
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
};

static_assert(STD_IS_REPLACEMENT(trivial, ViewIteratorMember), "ViewIteratorMember not trivial.");
static_assert(SIZEOF(ViewIteratorMember) == 16, "Unexpected size of ViewIteratorMember.");

struct MemberMap
{
	const Int count;
	Int members[];

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

} // namespace maxon

#endif // VIEWITERATOR_H__
