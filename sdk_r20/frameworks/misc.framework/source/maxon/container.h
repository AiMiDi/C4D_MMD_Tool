#ifndef CONTAINER_H__
#define CONTAINER_H__

#include "maxon/datatype.h"
#include "maxon/timestamp.h"
#include "maxon/contiguousrangemap.h"

namespace maxon
{


struct TimeStampMap
{
	using Map = ContiguousRangeMap<UInt, TimeStamp>;

	TimeStamp stamp;
	Map map;

	TimeStampMap() = default;

	TimeStampMap(TimeStampMap&& src) : MAXON_MOVE_MEMBERS(stamp, map)
	{
	}

	MAXON_OPERATOR_MOVE_ASSIGNMENT(TimeStampMap);

	Result<void> CopyFrom(const TimeStampMap& src)
	{
		stamp.UpdateUnchecked(src.stamp);
		return map.CopyFrom(src.map);
	}

	MAXON_OPERATOR_EQUALITY_HASHCODE(TimeStampMap, stamp, map);

	String ToString(const FormatStatement* fs) const
	{
		return "("_s + String::UIntToString(stamp) + ":"_s + map.ToString(fs) + ")"_s;
	}

	static const TimeStampMap& NullValue()
	{
		return GetZeroRef<TimeStampMap>();
	}
};


struct ViewIteratorMember
{
	static const Int OFFSET_OF_DATAPTR_TYPE = offsetof(TrivialConstDataPtr, _typeInfo);
	static const Int OFFSET_OF_DATAPTR_PTR = offsetof(TrivialConstDataPtr, _dataPtr);

	// Make sure that ViewIteratorMember fits exactly into four words (better performance).
#ifdef MAXON_TARGET_64BIT
	using MaskExtraType = UInt16;
#else
	using MaskExtraType = UChar;
#endif

	enum class FLAGS : ViewIteratorMember::MaskExtraType
	{
		NONE = 0,
		INPUT_WITHOUT_VALUE = 1,
		OUTPUT_UNUSED = 2
	} MAXON_ENUM_FLAGS_CLASS(FLAGS);

	TrivialConstDataPtr value;
	Int stride;
	MaskExtraType alignmentMask;
	MaskExtraType extraStride;
	FLAGS flags;
	MaskExtraType padding;

	void SetNoIndexing()
	{
		stride = 0;
		alignmentMask = LIMIT<MaskExtraType>::MAX;
		extraStride = 0;
		flags = FLAGS::NONE;
		padding = 0;
	}

	void SetIndexing(Int str, Int align, Int extra)
	{
		stride = str;
		alignmentMask = MaskExtraType(align);
		extraStride = MaskExtraType(extra);
		flags = FLAGS::NONE;
		padding = 0;
	}

	void SetIndexing(const SimdBlock<const Generic>& block)
	{
		stride = block.GetComponentStride();
		alignmentMask = MaskExtraType(block.GetAlignmentMask());
		extraStride = MaskExtraType(block.GetExtraStride());
		flags = FLAGS::NONE;
		padding = 0;
	}

	void SetConstant(const ConstDataPtr& ptr)
	{
		value = ptr;
		stride = 0;
		alignmentMask = LIMIT<MaskExtraType>::MAX;
		extraStride = 0;
		flags = FLAGS::NONE;
		padding = 0;
	}

	template <Bool ENABLE_SIMD = true> void Advance()
	{
		const Char*& p = reinterpret_cast<const Char*&>(value._dataPtr);
		p += stride;
		if (ENABLE_SIMD && MAXON_UNLIKELY((UInt(p) & UInt(alignmentMask)) == 0))
		{
			p += extraStride;
		}
	}

	template <Bool ENABLE_SIMD = true> void Advance(Int advanceCount)
	{
		if (!ENABLE_SIMD || MAXON_LIKELY(extraStride == 0))
		{
			(const Char*&) value._dataPtr += stride * advanceCount;
		}
		else
		{
			// In the SIMD case, we cannot just add stride*advanceCount to the pointer.
			// Only the part of advanceCount which is a multiple of the SIMD multiplicity can be used for this, the rest
			// has to take care of the two possible step sizes (stride or stride+extraStride).
			// The value of the alignment mask is component size * multiplicity - 1, and the stride is the component size,
			// so we can compute the multiplicity by dividing the alignment mask by the stride.
			// The stride is one of 1, 2, 4, 8, the following computes the log2 for those values:
			DebugAssert(IsPowerOfTwo(UInt32(stride)) && (stride <= 8));
			UInt log = (stride >> 1) - (stride >> 3);
			Int multiplicityMask = alignmentMask >> log;
			Int multLog = SIZEOF(Int) * 8 - Clz(multiplicityMask);
			// At first advance the pointer by a multiple of the multiplicity. (s.extraStride + s.alignmentMask + 1) is the
			// size of a complete SIMD vector, we have to divide this by the multiplicity to obtain the size of the
			// corresponding (hypothetical) non-SIMD vector. We just shift advanceCount by multLog, this does the division
			// and also masks out the lowest bits of advanceCount.
			(const Char*&) value._dataPtr += (extraStride + alignmentMask + 1) * (advanceCount >> multLog);
			// Then do the remaining steps, those may be either small or large steps.
			for (Int i = advanceCount & multiplicityMask; i; --i)
			{
				Advance<ENABLE_SIMD>();
			}
		}
	}

	void PrivateRestorePointer(const Generic* ptr)
	{
		value._dataPtr = ptr;
	}

private:
	static const MaskExtraType MARK = LIMIT<MaskExtraType>::MAX >> 1;
};

static_assert(std::is_trivial<ViewIteratorMember>::value, "ViewIteratorMember not trivial.");

class IndexableType : public DataType
{
	MAXON_INTERFACE_NONVIRTUAL(IndexableType, MAXON_REFERENCE_NONE, "net.maxon.interface.indexabletype");
public:
	static MAXON_METHOD Result<const IndexableType*> Create(const Block<const Member>& members);

	static MAXON_METHOD const IndexableType* GetGeneric();

	static MAXON_METHOD Int GetCount(const ConstDataPtr& array);

	static MAXON_METHOD Result<void> Resize(const DataPtr& array, Int count, ExecutionTime time, COLLECTION_RESIZE_FLAGS flags);

	static MAXON_METHOD Int GetBlock(const ConstDataPtr& array, Int member, Int index, StridedBlock<const Generic>& block);
};

class Indexable
{
};


class ArrayContainerType : public DataType
{
	MAXON_INTERFACE_NONVIRTUAL(ArrayContainerType, MAXON_REFERENCE_NONE, "net.maxon.interface.arraycontainertype");
public:
	static MAXON_METHOD Result<const ArrayContainerType*> Create(const Block<const Member>& members, Bool timeStamped);

	static MAXON_METHOD const ArrayContainerType* GetGeneric(Bool timeStamped);

	const IndexableType* GetIndexableType() const
	{
		return static_cast<const IndexableType*>(GetUnqualifiedType()->GetElementType());
	}
};


class SetContainerInterface;

/// @MAXON_ANNOTATION{refprefix=Generic}
class ArrayContainerInterface : public Indexable
{
	MAXON_INTERFACE_NONVIRTUAL(ArrayContainerInterface, MAXON_REFERENCE_COPY_ON_WRITE, "net.maxon.interface.arraycontainer");
public:
	static const Int BLOCK_SIZE_LOG = 10;
	static const Int BLOCK_SIZE = 1 << BLOCK_SIZE_LOG;
	static const Int BLOCK_SIZE_MASK = BLOCK_SIZE - 1;

	static MAXON_METHOD ArrayContainerInterface* Alloc(MAXON_SOURCE_LOCATION_DECLARATION, const ArrayContainerType* type);

	MAXON_METHOD Int GetCount() const;

	MAXON_METHOD const ArrayContainerType* GetType() const;

	//----------------------------------------------------------------------------------------
	/// Returns true if the given index is within the array boundaries.
	//----------------------------------------------------------------------------------------
	MAXON_FUNCTION Bool IsValidIndex(Int index) const
	{
		return UInt(index) < UInt(GetCount());
	}

	//----------------------------------------------------------------------------------------
	/// Returns an error if the given index is not within the array boundaries.
	//----------------------------------------------------------------------------------------
	MAXON_FUNCTION Result<void> CheckValidIndex(Int index) const
	{
		if (IsValidIndex(index))
			return OK;
		return CreateError(MAXON_SOURCE_LOCATION, ERROR_TYPE::ILLEGAL_ARGUMENT);
	}

	// member negative: treat ~member as innermost member index
	MAXON_METHOD Int GetBlock(Int member, Int index, StridedBlock<const Generic>& block) const;

	MAXON_FUNCTION Int GetWritableBlock(Int member, Int index, StridedBlock<Generic>& block)
	{
		return GetBlock(member, index, reinterpret_cast<StridedBlock<const Generic>&>(block));
	}

	MAXON_FUNCTION Int GetBlock(INNERMOST_MEMBER member, Int index, StridedBlock<const Generic>& block) const
	{
		return GetBlock(~Int(member), index, block);
	}

	MAXON_METHOD Int GetBlock(Int member, Int index, SimdBlock<const Generic>& block) const;

	MAXON_FUNCTION Int GetWritableBlock(Int member, Int index, SimdBlock<Generic>& block)
	{
		return GetBlock(member, index, reinterpret_cast<SimdBlock<const Generic>&>(block));
	}

	MAXON_FUNCTION Int GetBlock(INNERMOST_MEMBER member, Int index, SimdBlock<const Generic>& block) const
	{
		return GetBlock(~Int(member), index, block);
	}

	MAXON_FUNCTION const Generic& GetElement(Int member, Int index) const
	{
		StridedBlock<const Generic> block;
		Int bs = GetBlock(member, index, block);
		return block[index - bs];
	}

	template <typename T> MAXON_FUNCTION const T& GetElement(Int member, Int index) const
	{
		return reinterpret_cast<const T&>(GetElement(member, index));
	}

	MAXON_FUNCTION Generic& GetWritableElement(Int member, Int index)
	{
		return const_cast<Generic&>(static_cast<const ArrayContainerInterface*>(this)->GetElement(member, index));
	}

	template <typename T> MAXON_FUNCTION T& GetWritableElement(Int member, Int index)
	{
		return reinterpret_cast<T&>(GetWritableElement(member, index));
	}

	MAXON_METHOD const Generic& GetElement(INNERMOST_MEMBER member, Int index, const DataType*& typeOut, INNERMOST_MEMBER& memberOut) const;

	MAXON_METHOD Result<void> Resize(Int count, ExecutionTime time, COLLECTION_RESIZE_FLAGS flags = COLLECTION_RESIZE_FLAGS::DEFAULT);

	MAXON_METHOD Result<void> SwapErase(Int index, Int count, ExecutionTime time);

	MAXON_METHOD Result<void> Synchronize(const SetContainerInterface* base, ExecutionTime time);

	MAXON_METHOD void GetElement(const Block<const Int>& members, Int index, const Block<ViewIteratorMember>& valuesOut) const;

//	MAXON_METHOD Result<void> CopyElementFrom(const ArrayContainerType* type, const MemberMap* map, Int index, const Block<const ContainerConstRefX>& src);

	MAXON_METHOD String ToString(const FormatStatement* formatStatement) const;

	MAXON_METHOD const TimeStampMap& GetTimeStampMap(INNERMOST_MEMBER member) const;

	MAXON_METHOD Result<void> UpdateTimeStamps(INNERMOST_MEMBER member, const Block<const Range<UInt>>& indices, ExecutionTime time);

	MAXON_METHOD Result<void> UpdateTimeStamp(INNERMOST_MEMBER member, ExecutionTime time);
};


using SetContainerKey = UInt64;

class SetContainerType : public ArrayContainerType
{
	MAXON_INTERFACE_NONVIRTUAL(SetContainerType, MAXON_REFERENCE_NONE, "net.maxon.interface.setcontainertype");
public:
	static MAXON_METHOD Result<const SetContainerType*> Create(const Block<const Member>& members, Bool timeStamped);

	static MAXON_METHOD const SetContainerType* GetGeneric(Bool timeStamped);
};


/// @MAXON_ANNOTATION{refprefix=Generic}
class SetContainerInterface : public ArrayContainerInterface
{
	MAXON_INTERFACE_NONVIRTUAL_DERIVED(SetContainerInterface, MAXON_REFERENCE_COPY_ON_WRITE, "net.maxon.interface.setcontainer");
public:
	static MAXON_METHOD SetContainerInterface* Alloc(MAXON_SOURCE_LOCATION_DECLARATION, const SetContainerType* type);

private:
	// workaround to make the compiler happy
	static MAXON_METHOD ArrayContainerInterface* Alloc(MAXON_SOURCE_LOCATION_DECLARATION, const ArrayContainerType* type);
};


#include "container1.hxx"

#include "container2.hxx"


template <GET_DATATYPE_POLICY POLICY> inline ResultOk<const DataType*> PrivateGetDataType(Indexable*, OverloadRank0)
{
	return IndexableType::GetGeneric();
}

} // namespace maxon

#endif // CONTAINER_H__
