#include "maxon/kdtree.h"
#include "maxon/parallelsort.h"

namespace maxon
{

KDTree::KDTree()
{
	_root	= nullptr;
}

Result<void> KDTree::Init(Int maxThreads)
{
	iferr (_stack.Resize(maxThreads))
		return err;
	return OK;
}

Result<void> KDTree::Insert(const Vector& point, Int idValue)
{
	iferr (KDTreeNode* node = _nodelist.Append(Block<KDTreeNode>(nullptr, 1)))
		return err;

	node->idValue   = idValue;
	node->axis			= 0;
	node->point     = point;
	node->child[0]  = nullptr;
	node->child[1]  = nullptr;

	return OK;
}

void KDTree::Free()
{
	_root = nullptr;
	MAXON_WARN_MUTE_UNUSED _nodelist.Resize(0);
	MAXON_WARN_MUTE_UNUSED _stack.Resize(0);
}

class KDNearestSort : public BaseSort<KDNearestSort, BASESORTFLAGS::MOVEANDCOPYOBJECTS>
{
public:
	static inline Bool LessThan(const KDTreeNearest& a, const KDTreeNearest& b)
	{
		return a.dist < b.dist;
	}
};

class KDSort : public ParallelSort<KDSort, BASESORTFLAGS::MOVEANDCOPYOBJECTS, 10000>
{
	Int _axis;

public:
	inline Bool LessThan(const KDTreeNode& a, const KDTreeNode& b) const
	{
		return a.point[_axis] < b.point[_axis];
	}

	explicit KDSort(Int axis) : _axis(axis) { }
};

KDTreeNode* KDTree::Balance(Int index, Int count)
{
	if (count <= 0)
		return nullptr;
	else if (count == 1)
		return &_nodelist[index];

	// calculate axis with biggest variance to get a better tree
	Int		 i, axis;
	Vector average, variance, diff;

	for (i = index; i < index + count; i++)
		average += _nodelist[i].point;
	average /= (Float)count;

	for (i = index; i < index + count; i++)
	{
		diff = _nodelist[i].point - average;
		variance.x += Sqr(diff.x);
		variance.y += Sqr(diff.y);
		variance.z += Sqr(diff.z);
	}

	if (variance.x >= variance.y && variance.x >= variance.z)
		axis = 0;
	else if (variance.y >= variance.x && variance.y >= variance.z)
		axis = 1;
	else
		axis = 2;

	KDSort sort(axis);
	sort.Sort(&_nodelist[index], count);

	Int median = count / 2;

	KDTreeNode* node = &_nodelist[index + median];

	node->axis     = (Char)axis;
	node->child[0] = Balance(index, median);
	node->child[1] = Balance(index + median + 1, count - median - 1);

	return node;
}

void KDTree::Balance()
{
	_root = Balance(0, _nodelist.GetCount());
}

void KDTree::InsertElement(BaseArray<KDTreeNearest>& list, Int& count, Float& maxRangeSquare, Int maxElements, KDTreeNode* node, Float distanceSquare)
{
#if 1

	if (count < maxElements)
	{
		// element can just be appended as there is enough space
		list[count].node = node;
		list[count].dist = distanceSquare;
		count++;

		if (count == maxElements)
		{
			if (count > 1)	// speedup for FindNearest element
			{
				KDNearestSort sort;
				sort.Sort(&list[0], &list[0] + count);
			}

			maxRangeSquare = list[count - 1].dist;
		}
	}
	else
	{
#if 0
		Int i;
		for (i = count - 1; i > 0; i--)
			if (distanceSquare >= list[i - 1].dist)
				break;

		memmove(&list[i + 1], &list[i], SIZEOF(KDTreeNearest) * (count - i - 1));
#else
		Int i;
		for (i = count - 1; i > 0; i--)
		{
			if (distanceSquare >= list[i - 1].dist)
				break;

			list[i] = list[i - 1];
		}
#endif

		list[i].node = node;
		list[i].dist = distanceSquare;

		maxRangeSquare = list[count - 1].dist;
	}

#else

	if (count < maxElements)
	{
		// element can just be appended as there is enough space
		list[count].node = node;
		list[count].dist = distanceSquare;
		count++;
	}
	else
	{
		// array is full, so element that is the furthest away needs to be replaced

		Float biggestDist = list[0].dist;
		Int		i, biggest = 0;

		// adjust maxRangeSquare as array is already full and we don't need to search for the full radius anymore
		maxRangeSquare = MINVALUE_FLOAT;

		for (i = 1; i < count; i++)
		{
			if (list[i].dist > biggestDist)
			{
				if (biggestDist > maxRangeSquare)
					maxRangeSquare = biggestDist;

				biggestDist = list[i].dist;
				biggest = i;
			}
			else if (list[i].dist > maxRangeSquare)
			{
				maxRangeSquare = list[i].dist;
			}
		}

		list[biggest].node = node;
		list[biggest].dist = distanceSquare;

		if (distanceSquare > maxRangeSquare)
			maxRangeSquare = distanceSquare;

#ifdef MAXON_TARGET_DEBUG
		{
			biggestDist = MINVALUE_FLOAT;
			for (i = 0; i < count; i++)
			{
				if (list[i].dist > biggestDist)
					biggestDist = list[i].dist;
			}

			if (biggestDist != maxRangeSquare)
				CriticalStop();
		}
#endif
	}

#endif
}

Bool KDTree::AppendElement(BaseArray<KDTreeNearest>& list, KDTreeNode* node, Float distance)
{
	iferr (KDTreeNearest* element = list.Append(Block<KDTreeNearest>(nullptr, 1)))
		return false;

	element->node = node;
	element->dist = distance;

	return true;
}

Int	KDTree::FindNearest(Int threadIndex, const Vector& point, KDTreeNearest* nearest)
{
	BaseArray<KDTreeNearest> arr;
	if (!FindNearest(threadIndex, point, LIMIT<Float>::Max(), arr, 1, false))
		return NOTOK;

	if (nearest)
		*nearest = arr[0];

	return arr[0].node->idValue;
}

Int	KDTree::FindNearest(Int threadIndex, const Vector& point, Float maxRange, BaseArray<KDTreeNearest>& list, Int maxElements, Bool sortResults)
{
	KDTreeNode* node = nullptr;
	Float				distance, distanceSquare, maxRangeSquare;
	Int					i, smaller, count = 0;

	if (!_root)
		return 0;

	// retrieve stack array for current thread
	if (!_stack.IsValidIndex(threadIndex))
		return 0;

	PerformanceBaseArray<KDTreeNode*>& localStack = _stack[threadIndex];
	localStack.Flush();	// clear stack

	list.Flush();				// clear list
	if (list.Resize(maxElements) == FAILED)
		return 0;					// make sure list has space for maxElements

	// avoid Float overflow
	if (maxRange > MAXRANGE_FLOAT)
		maxRange = MAXRANGE_FLOAT;

	// calculate square to avoid Sqrt() calculations
	maxRangeSquare = Sqr(maxRange);

	// add root node if within maxRange
	distanceSquare = (_root->point - point).GetSquaredLength();
	if (distanceSquare <= maxRangeSquare)
	{
		InsertElement(list, count, maxRangeSquare, maxElements, _root, distanceSquare);
	}

	distance = point[_root->axis] - _root->point[_root->axis];
	smaller	 = (Int)(distance < 0.0);

	// walk through side that is further away from the point only if it is still within range
	if (_root->child[smaller] && Sqr(distance) <= maxRangeSquare)
	{
		MAXON_WARN_MUTE_UNUSED localStack.Append(_root->child[smaller]);	// no check is necessary as capacity is guaranteed
	}

	// always walk through other side
	if (_root->child[1 - smaller])
	{
		MAXON_WARN_MUTE_UNUSED localStack.Append(_root->child[1 - smaller]);	// no check is necessary as capacity is guaranteed
	}

	while (localStack.Pop(&node))
	{
		distance = point[node->axis] - node->point[node->axis];
		smaller	 = (Int)(distance < 0.0);
		distanceSquare = Sqr(distance);

		if (localStack.GetCount() + 2 >= localStack.GetCapacityCount())
		{
			if (localStack.EnsureCapacity(Max((Int)500, 2 * localStack.GetCapacityCount())) == FAILED)
				return 0;		// out of memory
		}

		if (distanceSquare <= maxRangeSquare)
		{
			if (node->child[smaller])
				localStack.UnsafeAppend(node->child[smaller]);

			distanceSquare = (node->point - point).GetSquaredLength();
			if (distanceSquare <= maxRangeSquare)
			{
				InsertElement(list, count, maxRangeSquare, maxElements, node, distanceSquare);
			}
		}
		if (node->child[1 - smaller])
			localStack.UnsafeAppend(node->child[1 - smaller]);
	}

	if (sortResults && count > 1 && count < maxElements)	// sorting is not necessary if maxElements was reached (as it already was sorted before)
	{
		KDNearestSort sort;
		sort.Sort(&list[0], &list[0] + count);
	}

	for (i = 0; i < count; i++)
		list[i].dist = Sqrt(list[i].dist);

	return count;
}

Int	KDTree::FindRange(Int threadIndex, const Vector& point, Float maxRange, BaseArray<KDTreeNearest>& list, Bool sortResults)
{
	// retrieve stack array for current thread
	if (!_stack.IsValidIndex(threadIndex))
		return 0;

	PerformanceBaseArray<KDTreeNode*>& localStack = _stack[threadIndex];
	localStack.Flush();

	KDTreeNode* node = nullptr;
	Float				distance, distanceSquare, maxRangeSquare;
	Int					i, smaller;

	MAXON_WARN_MUTE_UNUSED list.Resize(0);

	if (!_root)
		return 0;

	// avoid Float overflow
	if (maxRange > MAXRANGE_FLOAT)
		maxRange = MAXRANGE_FLOAT;

	// calculate square to avoid Sqrt() calculations
	maxRangeSquare = Sqr(maxRange);

	// add root node if within maxRange
	distanceSquare = (_root->point - point).GetSquaredLength();
	if (distanceSquare <= maxRangeSquare)
	{
		if (!AppendElement(list, _root, distanceSquare))
			return 0;		// out of memory
	}

	distance = point[_root->axis] - _root->point[_root->axis];
	smaller	 = (Int)(distance < 0.0);

	// walk through side that is further away from the point only if it is still within range
	if (_root->child[smaller] && Sqr(distance) <= maxRangeSquare)
	{
		if (localStack.Append(_root->child[smaller]) == FAILED)
			return 0;		// out of memory
	}

	// always walk through other side
	if (_root->child[1 - smaller])
	{
		if (localStack.Append(_root->child[1 - smaller]) == FAILED)
			return 0;		// out of memory
	}

	while (localStack.Pop(&node))
	{
		distance = point[node->axis] - node->point[node->axis];
		smaller	 = (Int)(distance < 0.0);
		distanceSquare = Sqr(distance);

		if (distanceSquare <= maxRangeSquare)
		{
			if (node->child[smaller])
			{
				if (localStack.Append(node->child[smaller]) == FAILED)
					return 0;		// out of memory
			}

			distanceSquare = (node->point - point).GetSquaredLength();
			if (distanceSquare <= maxRangeSquare)
			{
				if (!AppendElement(list, node, distanceSquare))
					return 0;		// out of memory
			}
		}

		if (node->child[1 - smaller])
		{
			if (localStack.Append(node->child[1 - smaller]) == FAILED)
				return 0;		// out of memory
		}
	}

	Int count = list.GetCount();
	if (sortResults && count > 0)
	{
		KDNearestSort sort;
		sort.Sort(&list[0], &list[0] + count);
	}

	for (i = 0; i < count; i++)
		list[i].dist = Sqrt(list[i].dist);

	return count;
}

} // namespace maxon
