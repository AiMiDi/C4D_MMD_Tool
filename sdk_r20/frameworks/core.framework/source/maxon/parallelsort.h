#ifndef PARALLELSORT_H__
#define PARALLELSORT_H__

#include "maxon/sort.h"
#include "maxon/parallelfor.h"
#include "maxon/thread.h"

/// @file

namespace maxon
{

// helper class for parallel sort
template <typename SOURCEITERATOR, typename DESTITERATOR, typename CONTENT, Bool MOVE_AND_COPY_MEMORY, Int ONEBLOCK> class MoveHelper
{
};

// CONTENT can be copied using memcpy
template <typename SOURCEITERATOR, typename DESTITERATOR, typename CONTENT> class MoveHelper<SOURCEITERATOR, DESTITERATOR, CONTENT, true, true>
{
public:
	static void MoveFrom(SOURCEITERATOR src, DESTITERATOR dst, Int moveCnt)
	{
		memcpy(&(*dst), &(*src), size_t(moveCnt * SIZEOF(CONTENT)));
	}
};

// CONTENT can be copied using memcpy
template <typename SOURCEITERATOR, typename DESTITERATOR, typename CONTENT> class MoveHelper<SOURCEITERATOR, DESTITERATOR, CONTENT, true, false>
{
public:
	static void MoveFrom(SOURCEITERATOR src, DESTITERATOR dst, Int moveCnt)
	{
		while (moveCnt-- > 0)
			memcpy(&*dst++, &*src++, (size_t) SIZEOF(CONTENT));
	}
};

// CONTENT must be moved using move constructors
template <typename SOURCEITERATOR, typename DESTITERATOR, typename CONTENT> class MoveHelper<SOURCEITERATOR, DESTITERATOR, CONTENT, false, false>
{
public:
	static void MoveFrom(SOURCEITERATOR src, DESTITERATOR dst, Int moveCnt)
	{
		while (moveCnt-- > 0)
			*dst++ = std::move(*src++);
	}
};

// CONTENT must be moved using move constructors
template <typename SOURCEITERATOR, typename DESTITERATOR, typename CONTENT> class MoveHelper<SOURCEITERATOR, DESTITERATOR, CONTENT, false, true>
{
public:
	static void MoveFrom(SOURCEITERATOR src, DESTITERATOR dst, Int moveCnt)
	{
		while (moveCnt-- > 0)
			*dst++ = std::move(*src++);
	}
};

// helper class for parallel sort (merges two segments into one)
class MergeSegment
{
public:
	struct Span
	{
		Int from, to;
	};

	Span	_a, _b;
	Int		_destOffset;

	static const Int maximumSplits = 16; // create a maximum of 16 splits per original segment
	static const Int maximumSegmentsPerSplit = maximumSplits + 1; // one segment more if b-segment is not complete after all a-segments have been split off

	// merge two segments, defined by spans _a and _b into one at _destOffset
	template <typename SORTCLASS, typename SOURCEITERATOR, typename DESTITERATOR, typename HELPER> void ExecuteMerge(const SORTCLASS& sort, SOURCEITERATOR source, DESTITERATOR destination, const HELPER& helper) const;

	// split the current segment into smaller ones that can be better merged in parallel
	template <typename SORTCLASS, typename ITERATOR> void Split(const SORTCLASS& sort, ITERATOR arr, BaseArray<MergeSegment>& seg, Int& segments) const;

	Bool Init(Int block, Int chunksize, Int count)
	{
		_a.from = block * chunksize;
		if (_a.from >= count)
			return false;		// first segment is out of bounds

		_a.to = _a.from + chunksize - 1;
		if (_a.to >= count)
			_a.to = count - 1;

		_b.from = _a.from + chunksize;
		_b.to = _b.from + chunksize - 1;
		if (_b.to >= count)
			_b.to = count - 1;

		_destOffset = _a.from;

		return true;
	}

private:
	// mostly same as ParallelSort::FindInsertionIndex, but operates without using an implementation of IsEqual
	template <typename SORTCLASS, typename TYPE, typename ITERATOR> TYPE* FindMergeInsertionIndex(const SORTCLASS& sort, const TYPE& key, ITERATOR arr, Int count, Int& insertionIndex) const;
};

template <typename SORTCLASS, typename SOURCEITERATOR, typename DESTITERATOR, typename HELPER> void MergeSegment::ExecuteMerge(const SORTCLASS& sort, SOURCEITERATOR source, DESTITERATOR destination, const HELPER& helper) const
{
	SOURCEITERATOR pA		 = source + _a.from;
	SOURCEITERATOR pB		 = source + _b.from;
	SOURCEITERATOR pEndA = source + _a.to;
	SOURCEITERATOR pEndB = source + _b.to;
	DESTITERATOR   pDest = destination + _destOffset;

	// speedup: if both blocks contain at least one element and one of the blocks that are merged
	// only contains elements that are smaller than the other block a simple copy operation is sufficient
	if (_a.from <= _a.to && _b.from <= _b.to)
	{
		if (!sort.LessThan(*pB, *pEndA))
		{
			Int lenA = _a.to - _a.from + 1;
			Int lenB = _b.to - _b.from + 1;
			helper.MoveFrom(pA, pDest, lenA);
			helper.MoveFrom(pB, pDest + lenA, lenB);
			return;
		}
		else if (!sort.LessThan(*pA, *pEndB))
		{
			Int lenA = _a.to - _a.from + 1;
			Int lenB = _b.to - _b.from + 1;
			helper.MoveFrom(pB, pDest, lenB);
			helper.MoveFrom(pA, pDest + lenB, lenA);
			return;
		}
	}

	while (pA <= pEndA && pB <= pEndB)
	{
		*pDest++ = std::move(sort.LessThan(*pA, *pB) ? *pA++ : *pB++);
	}

	if (pA <= pEndA)
	{
		helper.MoveFrom(pA, pDest, pEndA - pA + 1);
	}
	else if (pB <= pEndB)
	{
		helper.MoveFrom(pB, pDest, pEndB - pB + 1);
	}
}

template <typename SORTCLASS, typename TYPE, typename ITERATOR> TYPE* MergeSegment::FindMergeInsertionIndex(const SORTCLASS& sort, const TYPE& key, ITERATOR base, Int count, Int& insertionIndex) const
{
	Int l, r, mp;
	insertionIndex = 0;

	if (count < 1)
		return nullptr;

	ITERATOR dat;
	if (sort.LessThan(key, *base))				// value is smaller than anything in the array
		return nullptr;
	else if (!sort.LessThan(*base, key))	// value is identical
		return &(*base);

	l = 1;
	r = count - 1;

	insertionIndex = 1;	// necessary if c > 0 and r < l

	while (l <= r)
	{
		mp	= (l + r) >> 1;
		dat = base + mp;

		if (sort.LessThan(key, *dat))
		{
			insertionIndex = mp;
			r = mp - 1;
		}
		else if (sort.LessThan(*dat, key))
		{
			l = mp + 1;
			insertionIndex = l;
		}
		else
		{
			insertionIndex = mp;
			return &(*dat);
		}
	}

	return nullptr;
}

template <typename SORTCLASS, typename ITERATOR> void MergeSegment::Split(const SORTCLASS& sort, ITERATOR arr, BaseArray<MergeSegment>& seg, Int& segments) const
{
	// create no more than maximumSplits blocks and don't allow too small blocks, otherwise the threading overhead will be too high
	Int blockWidth = (_a.to - _a.from + maximumSplits) / maximumSplits;
	if (blockWidth < 1024)
	{
		seg[segments] = *this;
		segments++;
	}
	else
	{
		Int insertionIndex, offset = _destOffset;

		for (Int block = 0; block < maximumSegmentsPerSplit; block++)
		{
			seg[segments]._a.from = block > 0 ? seg[segments - 1]._a.to + 1 : _a.from;
			seg[segments]._a.to = seg[segments]._a.from + blockWidth;
			if (seg[segments]._a.to > _a.to)
				seg[segments]._a.to = _a.to;

			seg[segments]._b.from = block > 0 ? seg[segments - 1]._b.to + 1 : _b.from;
			seg[segments]._b.to = _b.to;

			seg[segments]._destOffset = offset;

			Bool aOutOfBounds = seg[segments]._a.from > _a.to;
			Bool bOutOfBounds = seg[segments]._b.from > _b.to;

			if (aOutOfBounds)
			{
				if (bOutOfBounds)
					break;
			}
			else if (bOutOfBounds)
			{
				seg[segments]._a.to = _a.to;
			}
			else
			{
				// both sequences are still active
				FindMergeInsertionIndex(sort, *(arr + seg[segments]._a.to), arr + seg[segments]._b.from, _b.to - seg[segments]._b.from + 1, insertionIndex);
				seg[segments]._b.to = seg[segments]._b.from + insertionIndex - 1;
			}

			offset += seg[segments]._a.to - seg[segments]._a.from + 1;
			offset += seg[segments]._b.to - seg[segments]._b.from + 1;
			segments++;
		}
		DebugAssert(offset == _destOffset + (_a.to - _a.from + 1) + (_b.to - _b.from + 1));
	}
}

/// @addtogroup STRUCTURES
/// @{

//----------------------------------------------------------------------------------------
/// Template for sorting arrays and searching in sorted arrays
///
/// To use this template derive a class from it and define the member 'LessThan' that implements an element comparison.
/// If you do searching the member 'IsEqual' needs to be implemented that does an element comparison with the search key as the first argument.
/// If the search key is different from the element type a second LessThan routine is needed (comparing SEARCHKEY to an element).
///
/// @tparam SORTCLASS							The class itself. This has to be a derived class of BaseSort.
/// @tparam FLAGS									See BASESORTFLAGS.
/// @tparam PARALLELIZATION_THRESHOLD	The minimum number of elements to start parallel sorting. if less elements are sorted a regular BaseSort will be used.
///
/// @note Note that the classes that will be sorted have special requirements regarding @link movecopy copy and move constructors @endlink.
///
/// Example for traditional C-style arrays:
///
/// @code
/// class Sort1 : public ParallelSort<Sort1>
/// {
/// public:
///   static inline Bool LessThan(Int a, Int b)
///   {
///     return a < b;
///   }
/// };
///
/// ...
///
/// Int array1[100];
///
/// ...
///
/// Sort1 sort1;
/// sort1.Sort(&array1[0], &array1[100]); // note that the 'end' iterator is the last element + 1 and not the last element!
/// sort1.Sort(array1, 100); // even easier
/// @endcode
///
/// @note LessThan can be a member of the sort class itself (not static), but needs to be const in that case.
///
/// Example for arrays:
///
/// @code
/// class Sort2 : public ParallelSort<Sort2>
/// {
/// public:
///   static inline Bool LessThan(Int a, Int b)
///   {
///     return a < b;
///   }
/// };
///
/// ...
///
/// BlockArray<Int> array2;
///
/// ...
///
/// Sort2  sort2;
/// sort2.Sort(array2.Begin(), array2.End()); // do not write Sort(&array2[0], &array2[array2.GetCount()]) as this will create a debug assert (the second array access is illegal)
/// sort2.Sort(array2); // any arrays derived from BaseArray can be passed directly
/// @endcode
///
/// Example for arbitrary structures with multiple sort criteria:
///
/// @code
/// class MyStruct
/// {
/// public:
///   String _str;
///   Int    _index;
///   Float  _weight;
/// };
///
/// class Sort3 : public ParallelSort<Sort3>
/// {
/// public:
///   static inline Bool LessThan(const MyStruct& a, const MyStruct& b)
///   {
///     if (a._weight < b._weight) return true;
///     if (a._weight > b._weight) return false;
///     return a._index < b._index; // if weights are identical sort by index
///   }
/// };
///
/// ...
///
/// BlockArray<MyStruct> array3;
///
/// ...
///
/// Sort3  sort3;
/// sort3.Sort(array3);
/// @endcode
///
///
/// Searching Example:
///
/// @code
/// class MyStruct
/// {
/// public:
///   String _str;
///   Int    _index;
///   Float  _weight;
/// };
///
/// class MySearch : public ParallelSort<MySearch>
/// {
/// public:
///   // for sorting: compare array element to array element
///   static inline Bool LessThan(const MyStruct& a, const MyStruct& b)
///   {
///     if (a._weight < b._weight) return true;
///     if (a._weight > b._weight) return false;
///     return a._index < b._index; // if weights are identical sort by index
///   }
///
///   // for searching: compare search key to array element
///   static inline Bool LessThan(Float weight, const MyStruct& b)
///   {
///     return weight < b._weight;
///   }
///
///   // for searching: compare search key to array element
///   static inline Bool IsEqual(Float weight, const MyStruct& b)
///   {
///     return weight == b._weight;
///   }
/// };
///
/// ...
///
/// BlockArray<MyStruct> array4;
///
/// ...
///
/// MySearch search;
/// search.Sort(array4);
///
/// ...
///
/// // array is now sorted, we can search it
/// MyStruct* result = search.Find(5.0, array4);
/// @endcode
///
//----------------------------------------------------------------------------------------
template <typename SORTCLASS, BASESORTFLAGS FLAGS = BASESORTFLAGS::NONE, Int PARALLELIZATION_THRESHOLD = 10000> class ParallelSort : public BaseSort<SORTCLASS, FLAGS>
{
public:
	using Super = BaseSort<SORTCLASS, FLAGS>;

	//----------------------------------------------------------------------------------------
	/// Sort elements of an array, so that the smallest element comes first.
	/// Note that the sorting is not guaranteed to be stable (elements with the same sort value may change their order).
	/// The time for sorting is O(n * log(n)).
	/// Depending on the available number of threads and initial element distribution you can get speedups of 1 to 8 times compared to BaseSort.
	/// If the number of elements is too small less threads will be used or ultimately non-parallel sorting will be used (<1024 elements).
	/// Parallel sorting temporarily needs the same amount of memory as the sorted elements take up. If memory isn't available the algorithm will still succeed, but be slightly slower than the non-Threaded version.
	/// @param[in] start							The start iterator of an array.
	/// @param[in] end								The end iterator of an array. Note that this is not the last element! It needs to be the boundary (which is last element + 1). See in the BaseSort class description for examples.
	/// @param[in] queue							Optional queue on which the parallel sort will run.
	//----------------------------------------------------------------------------------------
	template <typename ITERATOR> void Sort(ITERATOR start, ITERATOR end, JobQueueInterface* queue = JOBQUEUE_CURRENT) const
	{
		Int count = end - start;
		if (count > 1)
		{
			if (count >= PARALLELIZATION_THRESHOLD)
				ISort(start, count, *start, queue);
			else
				Super::Sort(start, end);
		}
	}

	//----------------------------------------------------------------------------------------
	/// Sort elements of an array, so that the smallest element comes first.
	/// Note that the sorting is not guaranteed to be stable (elements with the same sort value may change their order).
	/// The time for sorting is O(n * log(n))
	/// Depending on the available number of threads and initial element distribution you can get speedups of 1 to 8 times compared to BaseSort.
	/// If the number of elements is too small less threads will be used or ultimately non-parallel sorting will be used (<1024 elements).
	/// Parallel sorting temporarily needs the same amount of memory as the sorted elements take up. If memory isn't available the algorithm will still succeed, but be slightly slower than the non-Threaded version.
	/// @param[in] start							The start iterator of an array.
	/// @param[in] count							The number of elements to be sorted.
	/// @param[in] queue							Optional queue on which the parallel sort will run.
	//----------------------------------------------------------------------------------------
	template <typename ITERATOR> void Sort(ITERATOR start, Int count, JobQueueInterface* queue = JOBQUEUE_CURRENT) const
	{
		if (count > 1)
		{
			if (count >= PARALLELIZATION_THRESHOLD)
				ISort(start, count, *start, queue);
			else
				Super::Sort(start, count);
		}
	}

	//----------------------------------------------------------------------------------------
	/// Sort elements of an array, so that the smallest element comes first.
	/// Note that the sorting is not guaranteed to be stable (elements with the same sort value may change their order).
	/// The time for sorting is O(n * log(n))
	/// Depending on the available number of threads and initial element distribution you can get speedups of 1 to 8 times compared to BaseSort.
	/// If the number of elements is too small less threads will be used or ultimately non-parallel sorting will be used (<1024 elements).
	/// Parallel sorting temporarily needs the same amount of memory as the sorted elements take up. If memory isn't available the algorithm will still succeed, but be slightly slower than the non-Threaded version.
	/// @param[in] arr								The array to be sorted.
	/// @param[in] queue							Optional queue on which the parallel sort will run.
	//----------------------------------------------------------------------------------------
	template <typename ARRAY> void Sort(ARRAY& arr, JobQueueInterface* queue = JOBQUEUE_CURRENT) const
	{
		Int count = arr.GetCount();
		if (count > 1)
		{
			if (count >= PARALLELIZATION_THRESHOLD)
				ISort(arr.Begin(), count, *arr.Begin(), queue);
			else
				Super::Sort(arr);
		}
	}

private:
	template <typename ITERATOR, typename CONTENT> inline void ISort(ITERATOR start, Int count, const CONTENT& valType, JobQueueInterface* queue) const
	{
		MoveHelper<ITERATOR, CONTENT*, CONTENT, ((Int)FLAGS | (std::is_pod<CONTENT>::value ? (Int)BASESORTFLAGS::MOVEANDCOPYOBJECTS : 0)) == (Int)BASESORTFLAGS::MOVEANDCOPYOBJECTS, ITERATOR::isLinearIterator> moveHelperForward;
		MoveHelper<CONTENT*, ITERATOR, CONTENT, ((Int)FLAGS | (std::is_pod<CONTENT>::value ? (Int)BASESORTFLAGS::MOVEANDCOPYOBJECTS : 0)) == (Int)BASESORTFLAGS::MOVEANDCOPYOBJECTS, ITERATOR::isLinearIterator> moveHelperBackward;
		ParallelSortAlgorithm(start, count, valType, queue, moveHelperForward, moveHelperBackward);
	}

	template <typename CONTENT> inline void ISort(CONTENT* start, Int count, const CONTENT& valType, JobQueueInterface* queue) const
	{
		MoveHelper<CONTENT*, CONTENT*, CONTENT, ((Int)FLAGS | (std::is_pod<CONTENT>::value ? (Int)BASESORTFLAGS::MOVEANDCOPYOBJECTS : 0)) == (Int)BASESORTFLAGS::MOVEANDCOPYOBJECTS, true> moveHelper;
		ParallelSortAlgorithm(start, count, valType, queue, moveHelper, moveHelper);
	}

	template <typename ITERATOR, typename CONTENT, typename MOVEHELPERFORWARD, typename MOVEHELPERBACKWARD> inline void ParallelSortAlgorithm(ITERATOR start, Int count, const CONTENT& valType, JobQueueInterface* queue, const MOVEHELPERFORWARD& moveHelperForward, const MOVEHELPERBACKWARD& moveHelperBackward) const
	{
		// reduce number of segments to be sorted/merged to a power of 2, otherwise the merge operation will be imbalanced
		Int threadCnt = JobQueueInterface::GetThreadCount(queue);
		threadCnt = PowerOfTwo(threadCnt);

		// limit the minimum chunk size, otherwise the threading overhead slows the operation down
		Int chunksize = (count + threadCnt - 1) / threadCnt;
		if (chunksize < 1024)
			chunksize = 1024;

		ParallelFor::Dynamic(0, (count - 1) / chunksize + 1,
			[=, &start](Int block)
			{
				Int from = block * chunksize;
				Int to   = from + chunksize - 1;
				if (to >= count)
					to = count - 1;

				// sort segment
				this->Super::Sort(start + from, to - from + 1);
			},
			PARALLELFOR_USEMAXIMUMTHREADS, PARALLELFOR_DEFAULTGRANULARITY, queue);

		ReduceRedundantBlocks(chunksize, count, start);
		if (count <= chunksize)	// array is already completely sorted
			return;

		BaseArray<MergeSegment> segmentArray;
		BaseArray<CONTENT, 1, ((FLAGS | ConditionalFlag(std::is_pod<CONTENT>::value, BASESORTFLAGS::MOVEANDCOPYOBJECTS)) == BASESORTFLAGS::MOVEANDCOPYOBJECTS) ? BASEARRAYFLAGS::MOVEANDCOPYOBJECTS : BASEARRAYFLAGS::NONE> mirrorArray;

		Int splitRegions = ((count + 2 * chunksize - 1) / (2 * chunksize));

		// POD data doesn't need to be constructed.
		Bool dontInitialize = ((FLAGS | ConditionalFlag(std::is_pod<CONTENT>::value, BASESORTFLAGS::MOVEANDCOPYOBJECTS)) == BASESORTFLAGS::MOVEANDCOPYOBJECTS);
		COLLECTION_RESIZE_FLAGS resizeFlags = dontInitialize ? COLLECTION_RESIZE_FLAGS::POD_UNINITIALIZED : COLLECTION_RESIZE_FLAGS::DEFAULT;

		if (mirrorArray.Resize(count, resizeFlags) == FAILED || segmentArray.Resize(MergeSegment::maximumSegmentsPerSplit * splitRegions) == FAILED)
		{
			// if not enough memory is available make sure Sort still succeeds
			Super::Sort(start, count);
			return;
		}

		CONTENT*			temp = mirrorArray.GetFirst();

		Bool sourceToDest = true;
		while (chunksize < count)
		{
			Int segments = 0;
			MergeSegment outer;

			if (sourceToDest)
			{
				for (Int block = 0; true; block++)
				{
					if (!outer.Init(2 * block, chunksize, count))
						break;
					outer.Split(*static_cast<const SORTCLASS*>(this), start, segmentArray, segments);
				}

				ParallelFor::Dynamic(0, segments,
					[=, &segmentArray, &moveHelperForward](Int span)
					{
						segmentArray[span].ExecuteMerge(*((const SORTCLASS *)this), start, temp, moveHelperForward);
					},
					PARALLELFOR_USEMAXIMUMTHREADS, PARALLELFOR_MINIMUMGRANULARITY, queue);
			}
			else
			{
				for (Int block = 0; true; block++)
				{
					if (!outer.Init(2 * block, chunksize, count))
						break;
					outer.Split(*static_cast<const SORTCLASS*>(this), temp, segmentArray, segments);
				}

				ParallelFor::Dynamic(0, segments,
					[=, &segmentArray, &moveHelperBackward](Int span)
					{
						segmentArray[span].ExecuteMerge(*((const SORTCLASS *)this), temp, start, moveHelperBackward);
					},
					PARALLELFOR_USEMAXIMUMTHREADS, PARALLELFOR_MINIMUMGRANULARITY, queue);
			}

			sourceToDest = !sourceToDest;
			chunksize *= 2;
		}

		// if results are in wrong 'temp' space
		if (!sourceToDest)
			moveHelperBackward.MoveFrom(temp, start, count);
	}

	template <typename ITERATOR> void ReduceRedundantBlocks(Int chunksize, Int& cnt, ITERATOR& arr) const
	{
		// special optimization for already mostly sorted arrays

		// as long as there are at least two blocks
		while (cnt > chunksize)
		{
			// remove block at the beginning if it is smaller than all following blocks

			Int endOfThisBlock = chunksize - 1;

			Bool blockIsSmallerThanNextBlock = true;
			for (Int block = 1; (block < (cnt - 1) / chunksize + 1) && blockIsSmallerThanNextBlock; block++)
				blockIsSmallerThanNextBlock = static_cast<const SORTCLASS*>(this)->LessThan(*(arr + endOfThisBlock), *(arr + (block * chunksize))) != false;

			if (!blockIsSmallerThanNextBlock)
				break;

			arr += chunksize;
			cnt -= chunksize;
		}

		// as long as there are at least two blocks
		while (cnt > chunksize)
		{
			// remove block at the end if it is smaller than all previous blocks

			Int startOfThisBlock = ((cnt - 1) / chunksize) * chunksize;

			Bool blockIsBiggerThanPreviousBlock = true;
			for (Int block = 0; (block < (cnt - 1) / chunksize) && blockIsBiggerThanPreviousBlock; block++)
				blockIsBiggerThanPreviousBlock = static_cast<const SORTCLASS*>(this)->LessThan(*(arr + (block * chunksize + chunksize - 1)), *(arr + startOfThisBlock)) != false;

			if (!blockIsBiggerThanPreviousBlock)
				break;

			cnt = startOfThisBlock;
		}
	}

	Int PowerOfTwo(Int count) const
	{
		Int powerOfTwo = 1;
		while (powerOfTwo * 2 <= count)
			powerOfTwo *= 2;
		return powerOfTwo;
	}
};

//----------------------------------------------------------------------------------------
/// Specialized BaseSort template for simple datatypes.
///
/// @tparam COMPARE								Class that offers the methods IsEqual and LessThan.
/// @tparam FLAGS									See BASESORTFLAGS.
///
///
/// Example:
///
/// @code
/// BaseArray<Int> array;
/// SimpleParallelSort<> test;
/// test.Sort(array);
/// @endcode
///
/// or
///
/// @code
/// BaseArray<Int> array2;
/// SimpleParallelSort<> test2;
/// test2.Sort(&array2[0], array2.GetCount());
/// @endcode
//----------------------------------------------------------------------------------------
template <typename COMPARE = DefaultCompare, BASESORTFLAGS FLAGS = BASESORTFLAGS::NONE> class SimpleParallelSort : public ParallelSort<SimpleParallelSort<COMPARE, FLAGS>, FLAGS>
{
public:
	template <typename T1, typename T2> static Bool LessThan(const T1& a, const T2& b)
	{
		return COMPARE::LessThan(a, b);
	}

	template <typename T1, typename T2> static Bool IsEqual(const T1& a, const T2& b)
	{
		return COMPARE::IsEqual(a, b);
	}
};

/// @}

} // namespace maxon

#endif // PARALLELSORT_H__
