#ifndef HIERARCHYITERATOR_H__
#define HIERARCHYITERATOR_H__

#include "maxon/errorbase.h"
#include "maxon/basearray.h"

namespace maxon
{

template <typename NODE, typename HIERARCHY, typename CONTEXT, typename ARRAY = BaseArraySelector<>> class HierarchyIterator
{
public:
	using StackType = typename ARRAY::template Type<NODE>;

	Result<void> Init(typename ByValueParam<NODE>::type start, Bool includeSelf, CONTEXT* context)
	{
		iferr_scope;
		_stack.Flush();
		_skip = false;
		_context = context;
		if (includeSelf)
		{
			_stack.Append(start) iferr_return;
		}
		else
		{
			HIERARCHY::AddChildren(start, _stack, _context) iferr_return;
		}
		return OK;
	}

	Result<void> MoveToNext()
	{
		iferr_scope;
		NODE last;
		_stack.Pop(&last);
		if (_skip)
		{
			_skip = false;
		}
		else
		{
			HIERARCHY::AddChildren(last, _stack, _context) iferr_return;
		}
		return OK;
	}

	explicit operator Bool() const
	{
		return _stack.IsPopulated();
	}

	const NODE& operator *() const
	{
		return *_stack.GetLast();
	}

	NODE* operator ->() const
	{
		return const_cast<NODE*>(_stack.GetLast());
	}

	void SkipBranches()
	{
		_skip = true;
	}

	StackType& GetStack()
	{
		return _stack;
	}

private:
	StackType _stack;
	Bool _skip = false;
	CONTEXT* _context = nullptr;
};

}

#endif // HIERARCHYITERATOR_H__
