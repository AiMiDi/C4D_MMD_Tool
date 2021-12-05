#ifndef KDTREE_H__
#define KDTREE_H__

#include "maxon/lib_math.h"
#include "maxon/basearray.h"
#include "maxon/pointerarray.h"

namespace maxon
{

/// @addtogroup STRUCTURES
/// @{

//----------------------------------------------------------------------------------------
/// Extension to BaseArray.
/// PerformanceBaseArray is identical to BaseArray, but has the additional member UnsafeAppend.
/// For a description of basic functionality see the description of BaseArray
//----------------------------------------------------------------------------------------
template <typename T, Int MINCHUNKSIZE = BASEARRAY_DEFAULT_CHUNK_SIZE, BASEARRAYFLAGS MEMFLAGS = BASEARRAYFLAGS::NONE, typename Allocator = DefaultAllocator> class PerformanceBaseArray : public BaseArray<T, MINCHUNKSIZE, MEMFLAGS, Allocator>
{
	using BaseArray<T, MINCHUNKSIZE, MEMFLAGS, Allocator>::_ptr;
	using BaseArray<T, MINCHUNKSIZE, MEMFLAGS, Allocator>::_cnt;
	using BaseArray<T, MINCHUNKSIZE, MEMFLAGS, Allocator>::_capacity;

	MAXON_DISALLOW_COPY_AND_ASSIGN(PerformanceBaseArray);

public:
	PerformanceBaseArray()
	{
	}

	//----------------------------------------------------------------------------------------
	/// Add a new element at the end of the array without checking its capacity.
	/// You must have called EnsureCapacity() to make sure that the array can hold the data
	/// before calling this method. Only use this when it is absolutely performance critical
	/// and you REALLY know what you are doing.
	/// @return												Element pointer.
	//----------------------------------------------------------------------------------------
	T* UnsafeAppend()
	{
#ifdef MAXON_TARGET_DEBUG
		if (_cnt >= _capacity)
			DebugStop();
#endif

		return new (_ptr + _cnt++) T;
	}

	//----------------------------------------------------------------------------------------
	/// Add a new element at the end of the array without checking its capacity.
	/// You must have called EnsureCapacity() to make sure that the array can hold the data
	/// before calling this method. Only use this when it is absolutely performance critical
	/// and you REALLY know what you are doing.
	/// @param[in] x									Value to be copied.
	/// @return												Element pointer.
	//----------------------------------------------------------------------------------------
	T* UnsafeAppend(const T& x)
	{
#ifdef MAXON_TARGET_DEBUG
		if (_cnt >= _capacity)
			DebugStop();
#endif

		return new (_ptr + _cnt++) T(x);
	}

	T* UnsafeAppend(T&& x)
	{
#ifdef MAXON_TARGET_DEBUG
		if (_cnt >= _capacity)
			DebugStop();
#endif

		return new (_ptr + _cnt++) T(std::move(x));
	}
};

struct KDTreeNode
{
	KDTreeNode* child[2];	// left and right child node
	Vector			point;
	Int					idValue;
	Char				axis;
};

struct KDTreeNearest
{
	KDTreeNode*	node;
	Float				dist;
};

struct KDStackArray : public PerformanceBaseArray<KDTreeNode*>
{
	Char avoidMpCachelineInterference[64];
};

/// class to find closest points in space for a given point cloud
class KDTree
{
	MAXON_DISALLOW_COPY_AND_ASSIGN(KDTree);

public:
	KDTree();

	//----------------------------------------------------------------------------------------
	/// Initialize the kd-tree.
	/// @param[in] maxThreads					Maximum number of threads using the tree at the same time. set to 1 if no MP is used.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	Result<void> Init(Int maxThreads);

	//----------------------------------------------------------------------------------------
	/// free the kd-tree and helper arrays
	//----------------------------------------------------------------------------------------
	void Free();

	//----------------------------------------------------------------------------------------
	/// Insert a node into the kd-tree.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	Result<void> Insert(const Vector& point, Int idValue);

	//----------------------------------------------------------------------------------------
	/// balance the kd-tree. This needs to be done once after all nodes have been inserted calling 'Insert'
	//----------------------------------------------------------------------------------------
	void Balance();

	//----------------------------------------------------------------------------------------
	/// Find the nearest node in the kd-tree.
	/// @param[in] threadIndex				Index of thread using the tree, set to 0 if no MP is used.
	/// @param[in] point							Point in space that is searched for.
	/// @param[out] nearest						Optional, can be nullptr. If provided the structure will be filled with information about the nearest node.
	/// @return												Returns the index of the nearest node or NOTOK if there is no nearest node.
	//----------------------------------------------------------------------------------------
	Int FindNearest(Int threadIndex, const Vector& point, KDTreeNearest* nearest);

	//----------------------------------------------------------------------------------------
	/// Find the nearest nodes in the kd-tree
	/// note: for performance reasons this routine should only be called if the maximum number of searched nodes is sufficiently small (<100), otherwise FindRange is the better choice.
	/// @param[in] threadIndex				Index of thread using the tree, set to 0 if no MP is used.
	/// @param[in] point							Point in space that is searched for.
	/// @param[in] maxDistance				Optional, can be MAXVALUE_FLOAT. If provided only nodes within this distance are searched.
	/// @param[out] list							Array that will be filled with search results. the array doesn't have to be initialized before, this will be done inside the routine. for performance reasons try to re-use the array, so that memory doesn't have to be allocated each time.
	/// @param[in] maxElements				Maximum number of elements that shall be searched for.
	/// @param[in] sortResults				If true the resulting array will be sorted by distance, starting with the closest point.
	/// @return												Returns the number of found nodes or 0 if there was not enough memory.
	//----------------------------------------------------------------------------------------
	Int FindNearest(Int threadIndex, const Vector& point, Float maxDistance, BaseArray<KDTreeNearest>& list, Int maxElements, Bool sortResults);

	//----------------------------------------------------------------------------------------
	/// Find all nodes within a radius in the kd-tree
	/// note depending on the structure of the tree there can be a lot of search results (in an extreme case as many as there are nodes in the tree, which costs SIZEOF(KDTreeNearest)*nodes bytes memory.
	/// @param[in] threadIndex				Index of thread using the tree, set to 0 if no MP is used.
	/// @param[in] point							Point in space that is searched for.
	/// @param[in] maxDistance				Distance that nodes are searched within.
	/// @param[out] list							Array that will be filled with search results. the array doesn't have to be initialized before, this will be done inside the routine. for performance reasons try to re-use the array, so that memory doesn't have to be allocated each time.
	/// @param[in] sortResults				If true the resulting array will be sorted by distance, starting with the closest point.
	/// @return												Returns the number of found nodes or 0 if there was not enough memory.
	//----------------------------------------------------------------------------------------
	Int FindRange(Int threadIndex, const Vector& point, Float maxDistance, BaseArray<KDTreeNearest>& list, Bool sortResults);

private:
	KDTreeNode* Balance(Int index, Int count);
	void InsertElement(BaseArray<KDTreeNearest>& list, Int& count, Float& maxRangeSquare, Int maxElements, KDTreeNode* node, Float distanceSquare);
	Bool AppendElement(BaseArray<KDTreeNearest>& list, KDTreeNode* node, Float distance);

	KDTreeNode*								 _root;
	BaseArray<KDTreeNode>			 _nodelist;
	PointerArray<KDStackArray> _stack;
};

/// @}

} // namespace maxon

#endif // KDTREE_H__
