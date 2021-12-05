#ifndef BASELIST_H__
#define BASELIST_H__

#include "maxon/defaultallocator.h"
#include "maxon/collection.h"

#include <initializer_list>

namespace maxon
{

/// @addtogroup STRUCTURES
/// @{

struct BaseListLinkPOD
{
	void*	_next;
	UInt	_prevFlag;																					// bit0: listheadflag bit>0 ptr
};

//----------------------------------------------------------------------------------------
/// Link field for the pointers of a list node
//----------------------------------------------------------------------------------------
template <typename NODE> class BaseListLink : public BaseListLinkPOD
{
public:
	explicit BaseListLink(NODE* prev = nullptr, NODE* next = nullptr, Bool is_head = false)
	{
		_next = next;
		_prevFlag = ComputePrevFlag(prev, is_head);
	}

#ifdef MAXON_TARGET_DEBUG
	/// <B> NOTE: the destructor is not virtual </B>
	~BaseListLink()
	{
		if (_GetNextChecked() || _GetPrevChecked())
			DebugStop();
	}
#endif

	/// move constructor
	BaseListLink(BaseListLink&& src)
	{
		_next = src._next;
		_prevFlag = src._prevFlag;
		src._next = nullptr;
		src._prevFlag = 0;
	}

	void MoveFrom(NODE* thisNode, BaseListLink& src)
	{
		_next = src._next;
		_prevFlag = src._prevFlag;
		src._next = nullptr;
		src._prevFlag = 0;
		_GetNext()->SetPrev(thisNode);
		_GetPrev()->SetNext(thisNode);
	}

	/// move assignment operator
	MAXON_OPERATOR_MOVE_ASSIGNMENT(BaseListLink);

	//----------------------------------------------------------------------------------------
	/// Gets the next element.
	/// @return												Next element (can never be null, but points to list head if this is the last element)
	//----------------------------------------------------------------------------------------
	NODE* _GetNext() const
	{
		return (NODE*) _next;
	}

	//----------------------------------------------------------------------------------------
	/// Gets the previous element.
	/// @return												Previous element (can never be null, but points to list head if this is the first element)
	//----------------------------------------------------------------------------------------
	NODE* _GetPrev() const
	{
		return (NODE*) (_prevFlag & ADDRESS_MASK);
	}

	//----------------------------------------------------------------------------------------
	/// Removes the element (just removes it from the list, does not delete it).
	//----------------------------------------------------------------------------------------
	static void Remove(NODE* remove)
	{
		NODE*	p = remove->_GetPrev();
		NODE*	n = remove->_GetNext();
		if (p)
			p->SetNext(n);
		if (n)
			n->SetPrev(p);
		remove->SetNext(nullptr);
		remove->SetPrev(nullptr);
	}

	//----------------------------------------------------------------------------------------
	/// Inserts this before next.
	/// @param[in] insert							Node to insert.
	/// @param[in] next								The next object's link.
	//----------------------------------------------------------------------------------------
	static void InsertBefore(NODE* insert, NODE* next)
	{
		NODE* prev = next->_GetPrev();

		insert->SetNext(next);
		insert->SetPrev(prev);
		prev->SetNext(insert);
		next->SetPrev(insert);
	}

	//----------------------------------------------------------------------------------------
	/// Inserts this behind prev.
	/// @param[in] insert							Node to insert.
	/// @param[in] prev								The previous object's link.
	//----------------------------------------------------------------------------------------
	static void InsertAfter(NODE* insert, NODE* prev)
	{
		NODE* next = prev->_GetNext();

		insert->SetNext(next);
		insert->SetPrev(prev);
		prev->SetNext(insert);
		next->SetPrev(insert);
	}

	//----------------------------------------------------------------------------------------
	/// Returns true if this is a list head (_GetNext() would return pointer to the first element of the list, _GetPrev() to the last)
	/// @return												True if this is a list head.
	//----------------------------------------------------------------------------------------
	Bool IsListHead() const
	{
		return (_prevFlag & HEAD_FLAG) != 0;
	}

	//----------------------------------------------------------------------------------------
	/// Returns true if this link is contained in a list, but not a list head (i.e., _GetNext() and _GetPrev() are valid).
	/// @return												True if this is contained in a list.
	//----------------------------------------------------------------------------------------
	Bool IsInList() const
	{
		return _next && (_prevFlag & ADDRESS_MASK) && !(_prevFlag & HEAD_FLAG);
	}

	NODE* _GetNextChecked() const
	{
		NODE* n = _GetNext();
		return n && !n->IsListHead() ? n : nullptr;
	}

	NODE* _GetPrevChecked() const
	{
		NODE* p = _GetPrev();
		return p && !p->IsListHead() ? p : nullptr;
	}

	void SetNext(NODE* val) { _next = (void*) val; }
	void SetPrev(NODE* val) { _prevFlag &= INFO_MASK; _prevFlag |= UInt(val) & ADDRESS_MASK; }

protected:
	void SetListHead(Bool val) { _prevFlag &= ADDRESS_MASK; _prevFlag |= (UInt)val; }

	static UInt ComputePrevFlag(const NODE* prev, Bool head) { return (UInt(prev) & ADDRESS_MASK) | (UInt)head; }

	static const UInt HEAD_FLAG = 1;
	static const UInt INFO_FLAG = 2;
	static const UInt INFO_MASK = 3;
	static const UInt ADDRESS_MASK = ~INFO_MASK;

};

template <typename NODE> class BaseListNodeBase : public BaseListLink<NODE>
{
public:
	~BaseListNodeBase()
	{
		Remove();
	}

	//----------------------------------------------------------------------------------------
	/// Removes element (just removes it from the list, does not delete it).
	//----------------------------------------------------------------------------------------
	void Remove()
	{
		BaseListLink<NODE>::Remove(static_cast<NODE*>(this));
	}

	//----------------------------------------------------------------------------------------
	/// Inserts this before next.
	/// @param[in] next								The next object's link.
	//----------------------------------------------------------------------------------------
	void InsertBefore(NODE* next)
	{
		BaseListLink<NODE>::InsertBefore(static_cast<NODE*>(this), next);
	}

	//----------------------------------------------------------------------------------------
	/// Inserts this after prev.
	/// @param[in] prev								The previous object's link.
	//----------------------------------------------------------------------------------------
	void InsertAfter(NODE* prev)
	{
		BaseListLink<NODE>::InsertAfter(static_cast<NODE*>(this), prev);
	}

	const BaseListLinkPOD* _GetLink() const
	{
		return this;
	}
};

template <typename T, Bool hasCopyFrom = TestForCopyFromMember<T>::isSupported> class BaseListNode;

//----------------------------------------------------------------------------------------
/// Template for list node containing element data of type T (T has a copy constructor that cannot fail).
///
/// If you have to define a custom list node (which should rarely be the case) you can
/// simply use the IMPLEMENT_CUSTOM_BASELISTNODE(YourClass, PointerToBaseListPOD) macro that
/// will implement the required methods.
///
/// @tparam T											Content of the list node.
//----------------------------------------------------------------------------------------
template <typename T> class BaseListNode<T, false> : public BaseListNodeBase<BaseListNode<T, false>>
{
public:
	BaseListNode() : _data()
	{
	}

	explicit BaseListNode(const T& src) : _data(src)
	{
	}

	explicit BaseListNode(T&& src) : _data(std::move(src))
	{
	}

	/// returns element data of the list node
	T* _GetData() const
	{
		return &_data;
	}

protected:
	mutable T	_data;
};

//----------------------------------------------------------------------------------------
/// Template for list node containing element data of type T (to copy T you must use CopyFrom)
///
/// If you have to define a custom list node (which should rarely be the case) you can
/// simply use the IMPLEMENT_CUSTOM_BASELISTNODE(YourClass, PointerToBaseListPOD) macro that
/// will implement the required methods.
///
/// @tparam T											Content of the list node.
//----------------------------------------------------------------------------------------
template <typename T> class BaseListNode<T, true> : public BaseListNodeBase<BaseListNode<T, true>>
{
public:
	BaseListNode() : _data()
	{
	}

	explicit BaseListNode(const T& src)
	{
		DebugStop();																						// this is a dummy, instead _data.CopyFrom() has to be used
	}

	explicit BaseListNode(T&& src) : _data(std::move(src))
	{
	}

	/// returns element data of the list node
	T* _GetData() const
	{
		return &_data;
	}

protected:
	mutable T	_data;
};

template <> class BaseListNode<EmptyClass, false> : public BaseListNodeBase<BaseListNode<EmptyClass, false>>
{
public:
	EmptyClass* _GetData() const
	{
		return (EmptyClass*) g_writableMemory;
	}
};

//----------------------------------------------------------------------------------------
/// Template for list head pointing to elements of T.
/// @tparam T											Content of the list node.
/// @tparam NODE									List node containing T.
//----------------------------------------------------------------------------------------
template <typename T, typename NODE> class BaseListHead : public BaseListLink<NODE>
{
public:
	BaseListHead() : BaseListLink<NODE>(End(), End(), true)
	{
	}
	~BaseListHead()
	{
	}

	/// move constructor
	BaseListHead(BaseListHead&& src)
	{
		if (src.IsPopulated())
		{
			src._GetNext()->SetPrev(this->End());
			src._GetPrev()->SetNext(this->End());
			this->SetNext(src._GetNext());
			this->SetPrev(src._GetPrev());
			this->SetListHead(true);

			src.BaseListLink<NODE>::SetListHead(true);
			src.BaseListLink<NODE>::SetNext(src.End());
			src.BaseListLink<NODE>::SetPrev(src.End());
		}
	}

	/// move assignment operator
	MAXON_OPERATOR_MOVE_ASSIGNMENT(BaseListHead);

	//----------------------------------------------------------------------------------------
	/// Gets the number of elements.
	/// @return												Number of elements.
	//----------------------------------------------------------------------------------------
	Int GetCount() const
	{
		Int cnt = 0;

		for (NODE* e = Begin(); e != End(); e = e->_GetNext())
			cnt++;

		return cnt;
	}

	//----------------------------------------------------------------------------------------
	/// Checks if the list is empty. This is the same as <tt>GetCount() == 0</tt>
	/// @return												True if the list does not contain any elements.
	//----------------------------------------------------------------------------------------
	Bool IsEmpty() const
	{
		return Begin() == End();
	}

	//----------------------------------------------------------------------------------------
	/// Checks if the list contains anything. This is the same as <tt>GetCount() != 0</tt>
	/// @return												True if the list contains any elements.
	//----------------------------------------------------------------------------------------
	Bool IsPopulated() const
	{
		return Begin() != End();
	}

	//----------------------------------------------------------------------------------------
	/// Gets the element by index.
	/// @return												Element or nullptr (not element of this)
	//----------------------------------------------------------------------------------------
	T* GetElement(Int idx) const
	{
		NODE* node = GetNode(idx);
		return node ? node->_GetData() : nullptr;
	}

	NODE* GetNode(Int idx) const
	{
		for (NODE* e = Begin(); e != End(); e = e->_GetNext(), idx--)
		{
			if (idx == 0)
				return e;
		}
		return nullptr;
	}

	NODE* GetInsertEraseNode(Int idx) const
	{
		for (NODE* e = Begin(); e != End(); e = e->_GetNext(), idx--)
		{
			if (idx == 0)
				return e;
		}

		// Insert/Erase at the end?
		if (idx == 0)
			return End();

		return nullptr;
	}

	//----------------------------------------------------------------------------------------
	/// Gets the index of the element. The element must be part of the array, otherwise (e.g.
	/// if x is a copy of an array element) InvalidArrayIndex will be returned.
	/// @return												Index of element or InvalidArrayIndex (not element of this)
	//----------------------------------------------------------------------------------------
	Int GetIndex(const T* x) const
	{
		Int idx = 0;
		for (NODE* e = Begin(); e != End(); e = e->_GetNext(), idx++)
		{
			if (x == e->_GetData())
				return idx;
		}
		return InvalidArrayIndex;
	}

	//----------------------------------------------------------------------------------------
	/// Gets the pointer to the first node.
	/// @return												Pointer to the first element (equal to End() if the list is empty)
	//----------------------------------------------------------------------------------------
	NODE* Begin() const
	{
		return this->_GetNext();
	}

	//----------------------------------------------------------------------------------------
	/// Gets the pointer to the virtual end node (the node after the last node). This is the address
	/// of a virtual (non-existing) node that contains this list head.
	/// @return												Pointer to the end node (the node after the last node)
	//----------------------------------------------------------------------------------------
	NODE* End() const
	{
		// The BaseListLinkPOD might be somewhere in the NODE. Since offsetof() is a nogo and
		// NODE might contain virtual stuff we have to get this offset the hard way. Since
		// some compilers try to be mighty clever the dummy pointer must not be 0.
		const NODE* dummy = (NODE*) ((std::alignment_of<NODE>::value + MAXON_CACHE_LINE_SIZE - 1) & ~(MAXON_CACHE_LINE_SIZE - 1));
		const Int offset = Int(dummy->_GetLink()) - Int(dummy);
		return (NODE*) (Int(this) - offset);
	}
};

//----------------------------------------------------------------------------------------
/// Basic list template (double linked).
///
/// The BaseList implements the same methods as the arrays. Nonetheless it is highly
/// recommended to <B> use the iterator based methods </B> instead of those taking an index
/// or count as parameter because the latter perform poorly due to the nature of a list.
///
/// If you want to control the list nodes themselves or their memory layout you can specify
/// the list node type with NODE instead of using the default template BaseListNode<T>
/// (the same goes for the list head HEAD).
///
/// Performance characteristics:
/// Random access to array elements is linear with the index n: O(n)
/// Append or Pop (erase the last) an element is constant: O(1)
/// Insert or Erase an element is constant: O(1)
/// @note: Do not rely on the characteristics to pick the right type of collection. Always profile to check real life performance!
///
/// @tparam T											Type of the list element content.
/// @tparam NODE									A node that encapsulates the element content T and holds the pointers to the next and previous element (see BaseListNode for details).
/// @tparam HEAD									A list head for nodes of type NODE.
/// @tparam ALLOCATOR							Class for memory allocation.
//----------------------------------------------------------------------------------------
template <typename T, typename NODE = BaseListNode<T>, typename HEAD = BaseListHead<T, NODE>, typename ALLOCATOR = DefaultAllocator> class BaseList : protected ALLOCATOR
{
	MAXON_DISALLOW_COPY_AND_ASSIGN(BaseList);

public:
	using ValueType = T;
	using AllocatorType = ALLOCATOR;

	template <Bool CONSTITERATOR> class IteratorTemplate;
	using Iterator = IteratorTemplate<false>;
	using ConstIterator = IteratorTemplate<true>;

	//----------------------------------------------------------------------------------------
	/// Default constructor. Creates an empty list.
	//----------------------------------------------------------------------------------------
	BaseList()
	{
	}

	//----------------------------------------------------------------------------------------
	/// This constructor has to be used if a list should use a custom allocator with member variables.
	//----------------------------------------------------------------------------------------
	explicit BaseList(const ALLOCATOR& a) : ALLOCATOR(a)
	{
	}

	//----------------------------------------------------------------------------------------
	/// Destructs the list. If there are still elements they will be deleted.
	//----------------------------------------------------------------------------------------
	~BaseList()
	{
		Reset();
	}

	//----------------------------------------------------------------------------------------
	/// Move constructor.
	//----------------------------------------------------------------------------------------
	BaseList(BaseList&& src) : ALLOCATOR(std::move(src)), _head(std::move(src._head))
	{
	}

	//----------------------------------------------------------------------------------------
	/// Move assignment operator.
	//----------------------------------------------------------------------------------------
	MAXON_OPERATOR_MOVE_ASSIGNMENT(BaseList);

	//----------------------------------------------------------------------------------------
	/// Deletes all elements (calls destructors and frees memory).
	//----------------------------------------------------------------------------------------
	void Reset()
	{
		for (Iterator e = End(); e != Begin(); e = End())
		{
			if (Erase(--e) == Iterator())
				DebugStop();
		}
	}

	//----------------------------------------------------------------------------------------
	/// Deletes all elements (same as Reset() for the BaseList).
	//----------------------------------------------------------------------------------------
	void Flush()
	{
		Reset();
	}

	//----------------------------------------------------------------------------------------
	/// Checks if the list is empty. This is the same as <tt>GetCount() == 0</tt>
	/// @return												True if the list does not contain any elements.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE Bool IsEmpty() const
	{
		return _head.IsEmpty();
	}

	//----------------------------------------------------------------------------------------
	/// Checks if the list contains anything. This is the same as <tt>GetCount() != 0</tt>
	/// @return												True if the list contains any elements.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE Bool IsPopulated() const
	{
		return _head.IsEmpty() == false;
	}

	//----------------------------------------------------------------------------------------
	/// Gets the number of list elements.
	/// <B> This has to iterate over all list elements. You may better want to use iterators directly! </B>
	/// @return												Number of list elements.
	//----------------------------------------------------------------------------------------
	Int GetCount() const
	{
		return _head.GetCount();
	}

	//----------------------------------------------------------------------------------------
	/// Array (subscript) operator for const objects.
	/// <B> This is very ineffective on a list - better use iterators! </B>
	/// @param[in] idx								Element index (if it's out of bounds you will get an error in debug code only, otherwise it will crash).
	/// @return												List element.
	//----------------------------------------------------------------------------------------
	const T& operator [](Int idx) const
	{
		return *_head.GetElement(idx);
	}

	//----------------------------------------------------------------------------------------
	/// Array (subscript) operator for non-const objects.
	/// <B> This is very ineffective on a list - better use iterators! </B>
	/// @param[in] idx								Element index (if it's out of bounds you will get an error in debug code only, otherwise it will crash).
	/// @return												List element.
	//----------------------------------------------------------------------------------------
	// this is duplicate code but casting constness away for this case is plain ugly
	T& operator [](Int idx)
	{
		return *_head.GetElement(idx);
	}

	//----------------------------------------------------------------------------------------
	/// Adds a new element at the end of the list.
	/// @return												Element reference or OutOfMemoryError if the allocation failed.
	//----------------------------------------------------------------------------------------
	ResultRef<T> Append()
	{
		NODE* node = AllocNode();

		if (MAXON_UNLIKELY(node == nullptr))
			return nullptr;

		new (node) NODE();
		return InsertNode(End(), node);
	}

	//----------------------------------------------------------------------------------------
	/// Adds a new element at the end of the list and initializes it with a copy of x.
	/// @param[in] x									Value to be copied.
	/// @return												Element reference or OutOfMemoryError if the allocation failed.
	//----------------------------------------------------------------------------------------
	ResultRef<T> Append(const T& x)
	{
		NODE* node = AllocNode();

		if (MAXON_UNLIKELY(node == nullptr))
			return nullptr;

		if (TestForCopyFromMember<T>::isSupported)
		{
			new (node) NODE();
			if (AssignCopy(*node->_GetData(), x) == FAILED)
			{
				DeleteNode(node);
				return nullptr;
			}
		}
		else
		{
			// Use trivial copy constructor.
			new (node) NODE(x);
		}

		return InsertNode(End(), node);
	}

	//----------------------------------------------------------------------------------------
	/// Adds a new element at the end of the list and moves the content of x to it.
	/// @param[in] x									Value to be moved.
	/// @return												Element reference or OutOfMemoryError if the allocation failed.
	//----------------------------------------------------------------------------------------
	ResultRef<T> Append(T&& x)
	{
		NODE* node = AllocNode();

		if (MAXON_UNLIKELY(node == nullptr))
			return nullptr;

		new (node) NODE(std::move(x));
		return InsertNode(End(), node);
	}

	//----------------------------------------------------------------------------------------
	/// Appends new elements at the end of the list.
	/// @param[in] values							Block with values to be copied.
	/// 															If the block points to nullptr, only its count is used, and you have to call the constructor of the new elements manually.
	/// @return												Element pointer or OutOfMemoryError if the allocation failed.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE ResultPtr<T> Append(const Block<const T>& values)
	{
		Iterator position = Insert(End(), values).UncheckedGetValue();
		return position ? position.GetPtr() : nullptr;
	}

	//----------------------------------------------------------------------------------------
	/// Appends new elements at the end of the list.
	/// @param[in] values							Initializer list with values to be copied.
	/// @return												Element pointer or OutOfMemoryError if the allocation failed.
	//----------------------------------------------------------------------------------------
	ResultPtr<T> Append(const std::initializer_list<T>& values)
	{
		Iterator position = Insert(End(), values).UncheckedGetValue();
		return position ? position.GetPtr() : nullptr;
	}

	//----------------------------------------------------------------------------------------
	/// BaseList specific: Adds a new list node at the end of the list.
	/// @param[in] node								Pointer to new list node (BaseList will take ownership of it).
	/// @return												Pointer to the appended node's data.
	//----------------------------------------------------------------------------------------
	T* AppendNode(NODE* node)
	{
		return InsertNode(End(), node);
	}

	//----------------------------------------------------------------------------------------
	/// Inserts a new default element at index position. <B> Use the iterator based Insert() below! </B>
	/// This is compatible to the arrays but slow because Insert() has to iterate over the list
	/// to find the element corresponding to the index position.
	/// @param[in] position						Insert index.
	/// @return												Element reference or OutOfMemoryError if the allocation failed (or position is out of boundaries).
	//----------------------------------------------------------------------------------------
	ResultRef<T> Insert(Int position)
	{
		Iterator it(_head.GetInsertEraseNode(position));
		return it ? Insert(it).UncheckedGetValue().GetPtr() : nullptr;
	}

	//----------------------------------------------------------------------------------------
	/// Inserts a new default element at iterator position.
	/// @param[in] position						Insert position.
	/// @return												Iterator for the new element or OutOfMemoryError if the allocation failed (or position out of boundaries).
	//----------------------------------------------------------------------------------------
	ResultMemT<Iterator> Insert(Iterator position)
	{
		NODE* node = AllocNode();

		if (MAXON_LIKELY(node != nullptr))
		{
			new (node) NODE();
			InsertNode(position, node);
		}

		return Iterator(node);
	}

	//----------------------------------------------------------------------------------------
	/// Inserts a new element at index position and initializes it with a copy of x. <B> Use the
	/// iterator based Insert() below! </B>
	/// This is compatible to the arrays but slow because Insert() has to iterate over the list.
	/// @param[in] position						Insert index.
	/// @param[in] x									Value to be copied.
	/// @return												Element reference or OutOfMemoryError if the allocation failed (or position is out of boundaries).
	//----------------------------------------------------------------------------------------
	ResultRef<T>  Insert(Int position, const T& x)
	{
		Iterator it(_head.GetInsertEraseNode(position));
		return it ? Insert(it, x).UncheckedGetValue().GetPtr() : nullptr;
	}

	//----------------------------------------------------------------------------------------
	/// Inserts a new element at iterator position and initializes it with a copy of x.
	/// @param[in] position						Insert position.
	/// @param[in] x									Value to be copied.
	/// @return												Iterator for the new element or OutOfMemoryError if the allocation failed (or position is out of boundaries).
	//----------------------------------------------------------------------------------------
	ResultMemT<Iterator> Insert(Iterator position, const T& x)
	{
		NODE* node = AllocNode();

		if (MAXON_UNLIKELY(node == nullptr))
			return FAILED;

		if (TestForCopyFromMember<T>::isSupported)
		{
			new (node) NODE();
			if (AssignCopy(*node->_GetData(), x) == FAILED)
			{
				DeleteNode(node);
				return FAILED;
			}
		}
		else
		{
			// Use trivial copy constructor.
			new (node) NODE(x);
		}

		InsertNode(position, node);
		return Iterator(node);
	}

	//----------------------------------------------------------------------------------------
	/// Inserts a new element at index position and moves the content of x to it. <B> Use the
	/// iterator based Insert() below! </B>
	/// This is compatible to the arrays but slow because Insert() has to iterate over the list.
	/// @param[in] position						Insert index.
	/// @param[in] x									Value to be moved.
	/// @return												Element reference or OutOfMemoryError if the allocation failed (or position is out of boundaries).
	//----------------------------------------------------------------------------------------
	ResultRef<T> Insert(Int position, T&& x)
	{
		Iterator it(_head.GetInsertEraseNode(position));
		return it ? Insert(it, std::move(x)).UncheckedGetValue().GetPtr() : nullptr;
	}

	//----------------------------------------------------------------------------------------
	/// Inserts a new element at iterator position and moves the content of x to it.
	/// @param[in] position						Insert position.
	/// @param[in] x									Value to be moved.
	/// @return												Iterator for the new element or OutOfMemoryError if the allocation failed (or position is out of boundaries).
	//----------------------------------------------------------------------------------------
	ResultMemT<Iterator> Insert(Iterator position, T&& x)
	{
		NODE* node = AllocNode();

		if (MAXON_LIKELY(node != nullptr))
		{
			new (node) NODE(std::move(x));
			InsertNode(position, node);
		}

		return Iterator(node);
	}

	//----------------------------------------------------------------------------------------
	/// BaseList specific: Inserts a new list node at iterator position.
	/// @param[in] position						Insert position.
	/// @param[in] node								Pointer to new list node (BaseList will take ownership of it).
	/// @return												Pointer to the inserted node's data.
	//----------------------------------------------------------------------------------------
	T* InsertNode(Iterator position, NODE* node)
	{
		node->InsertBefore(position.GetNode());
		return node->_GetData();
	}

	//----------------------------------------------------------------------------------------
	/// Inserts new elements at index position. <B> Use the iterator based Insert() below! </B>
	/// This is compatible to the arrays but slow because Insert() has to iterate over the list.
	/// @param[in] position						Insert index.
	/// @param[in] values							Block with values to be copied.
	/// 															If the block points to nullptr, only its count is used, and you have to call the constructor of the new elements manually.
	/// @return												Element pointer or OutOfMemoryError if the allocation failed (or position is out of boundaries).
	//----------------------------------------------------------------------------------------
	ResultPtr<T> Insert(Int position, const Block<const T>& values)
	{
		NODE* node = _head.GetInsertEraseNode(position);
		Iterator element = node ? Insert(Iterator(node), values).UncheckedGetValue() : Iterator();
		return element ? element.GetPtr() : nullptr;
	}

	//----------------------------------------------------------------------------------------
	/// Inserts new elements at index position. <B> Use the iterator based Insert() below! </B>
	/// This is compatible to the arrays but slow because Insert() has to iterate over the list.
	/// @param[in] position						Insert index.
	/// @param[in] values							Initializer list with values to be copied.
	/// @return												Element pointer or OutOfMemoryError if the allocation failed (or position is out of boundaries).
	//----------------------------------------------------------------------------------------
	ResultPtr<T> Insert(Int position, const std::initializer_list<T>& values)
	{
		NODE* node = _head.GetInsertEraseNode(position);
		Iterator element = node ? Insert(Iterator(node), values).UncheckedGetValue() : Iterator();
		return element ? element.GetPtr() : nullptr;
	}

	//----------------------------------------------------------------------------------------
	/// Inserts new elements at iterator position (all elements from position on are moved by the the count of @p values).
	/// @param[in] position						Insert position.
	/// @param[in] values							Block with values to be copied.
	/// 															If the block points to nullptr, only its count is used, and you have to call the constructor of the new elements manually.
	/// @return												Iterator for the new element or OutOfMemoryError if the allocation failed (or position is out of boundaries).
	//----------------------------------------------------------------------------------------
	ResultMemT<Iterator> Insert(Iterator position, const Block<const T>& values)
	{
		const T* x = values.GetFirst();
		for (Int i = values.GetCount() - 1; i >= 0; i--)
		{
			Iterator next = position;

			if (x)
				position = Insert(next, x[i]).UncheckedGetValue();
			else
				position = Insert(next).UncheckedGetValue();

			if (!position)																				// insertion failed (not enough memory)?
			{
				for (i = values.GetCount() - 1 - i; i > 0; i--)
					next = Erase(next);																// remove the already inserted elements

				DebugStop();
				break;
			}
		}

		return position;
	}

	//----------------------------------------------------------------------------------------
	/// Inserts new elements at iterator position (all elements from @p position on are moved by the the count of @p values).
	/// @param[in] position						Insert position.
	/// @param[in] values							Initializer list with values to be copied.
	/// @return												Iterator for the new element or OutOfMemoryError if the allocation failed (or position is out of boundaries).
	//----------------------------------------------------------------------------------------
	ResultMemT<Iterator> Insert(Iterator position, const std::initializer_list<T>& values)
	{
		const T* first = values.begin();
		const T* last = values.end();
		Int cnt = last - first;
		return Insert(position, Block<const T>(first, cnt));
	}

	//----------------------------------------------------------------------------------------
	/// Erases (removes and deletes) elements. <B> Use the iterator based Erase() below! </B>
	/// This is compatible to the arrays but slow because Erase() has to iterate over the list.
	/// @param[in] position						Erase index (Erase() will fail if out of bounds and return nullptr).
	/// @param[in] eraseCnt						Number of elements to be erased. If eraseCnt is invalid (higher than allowed or negative) a nullptr will be returned.
	/// @return												Pointer to the element that is now at position. If position equals the number of elements after Erase() a valid pointer is returned but you are not allowed to access it. OutOfMemoryError is only returned on failure (position was out of bounds).
	//----------------------------------------------------------------------------------------
	ResultPtr<T> Erase(Int position, Int eraseCnt = 1)
	{
		NODE* node = _head.GetInsertEraseNode(position);
		Iterator element = node ? Erase(Iterator(node), eraseCnt) : Iterator();
		return element ? element.GetPtr() : nullptr;
	}

	//----------------------------------------------------------------------------------------
	/// Erases (removes and deletes) elements.
	/// @param[in] position						Erase position.
	/// @param[in] eraseCnt						Number of elements to be erased. If eraseCnt is invalid (higher than allowed or negative) an invalid iterator will be returned.
	/// @return												Iterator for the element that is now at position (its operator Bool() will return false if something failed).
	//----------------------------------------------------------------------------------------
	Iterator Erase(Iterator position, Int eraseCnt)
	{
		Int availableCnt = 0;

		// Check the number of available elements.
		for (Iterator tmp = position; availableCnt < eraseCnt; availableCnt++, tmp++)
		{
			if (tmp == End())
			{
				DebugStop("You are trying to erase more elements than available.");
				return Iterator();
			}
		}

		if (eraseCnt < 0)
		{
			DebugStop("Invalid eraseCnt.");
			return Iterator();
		}

		for (Int i = 0; i < eraseCnt; i++)
			position = Erase(position);

		return position;
	}

	//----------------------------------------------------------------------------------------
	/// Erases (removes and deletes) an element.
	/// @param[in] position						Erase position.
	/// @return												Iterator for the element that is now at position (its operator Bool() will return false if something failed).
	//----------------------------------------------------------------------------------------
	Iterator Erase(Iterator position)
	{
		if (MAXON_UNLIKELY(position == End()))
		{
			DebugStop("You are trying to erase more elements than available.");
			return Iterator();
		}

		NODE* node = position.GetNode();
		position++;
		DeleteNode(node);

		return position;
	}

	//----------------------------------------------------------------------------------------
	/// For a list this is exactly the same as Erase().
	/// @param[in] position						Erase index (Erase() will fail if out of bounds and return nullptr).
	/// @param[in] eraseCnt						Number of elements to be erased. If eraseCnt is invalid (higher than allowed or negative) false will be returned.
	/// @return												False if position was out of bounds.
	//----------------------------------------------------------------------------------------
	ResultMem SwapErase(Int position, Int eraseCnt = 1)
	{
		return ResultMem(Erase(position, eraseCnt) == OK);
	}

	//----------------------------------------------------------------------------------------
	/// For a list this is exactly the same as Erase().
	/// @param[in] position						Erase position.
	/// @param[in] eraseCnt						Number of elements to be erased. If eraseCnt is invalid (higher than allowed or negative) an invalid iterator will be returned.
	/// @return												Iterator for the element that is now at position (its operator Bool() will return false if something failed).
	//----------------------------------------------------------------------------------------
	Iterator SwapErase(Iterator position, Int eraseCnt = 1)
	{
		return Erase(position, eraseCnt);
	}

	//----------------------------------------------------------------------------------------
	/// Determines a contiguous block of array elements which contains the element at @p position.
	/// For a BaseArray, this yields the whole array as a block.
	/// @param[in] position						Element position.
	/// @param[out] block							Block which contains the element at @p position.
	/// @return												Start iterator of the block. The requested element can be found within the block at index @p position - start iterator.
	//----------------------------------------------------------------------------------------
	template <Bool STRIDED> MAXON_ATTRIBUTE_FORCE_INLINE Iterator GetBlock(Iterator position, Block<T, STRIDED>& block)
	{
		NODE* node = position.GetNode();

		if (node)
			block.Set(node->_GetData(), 1, SIZEOF(T));
		else
			block.Reset();

		return position;
	}

	//----------------------------------------------------------------------------------------
	/// Determines a contiguous block of array elements which contains the element at @p position.
	/// For a BaseArray, this yields the whole array as a block.
	/// @param[in] position						Element position.
	/// @param[out] block							Block which contains the element at @p position.
	/// @return												Start iterator of the block. The requested element can be found within the block at index @p position - start iterator.
	//----------------------------------------------------------------------------------------
	template <Bool STRIDED> MAXON_ATTRIBUTE_FORCE_INLINE Iterator GetBlock(Iterator position, Block<const T, STRIDED>& block) const
	{
		return const_cast<BaseList*>(this)->GetBlock(position, *(Block<T, STRIDED>*) &block);
	}

	//----------------------------------------------------------------------------------------
	/// Determines a contiguous block of array elements which contains the element at @p position.
	/// For a BaseArray, this yields the whole array as a block.
	/// @param[in] position						Element index.
	/// @param[out] block							Block which contains the element at @p position.
	/// @return												Start index of the block. The requested element can be found within the block at @p position - start index.
	//----------------------------------------------------------------------------------------
	template <Bool STRIDED> MAXON_ATTRIBUTE_FORCE_INLINE Int GetBlock(Int position, Block<T, STRIDED>& block)
	{
		NODE* node = _head.GetNode(position);
		block.Set(node ? node->_GetData() : nullptr, 1, SIZEOF(T));
		return position;
	}

	//----------------------------------------------------------------------------------------
	/// Determines a contiguous block of array elements which contains the element at @p position.
	/// For a BaseArray, this yields the whole array as a block.
	/// @param[in] position						Element index.
	/// @param[out] block							Block which contains the element at @p position.
	/// @return												Start index of the block. The requested element can be found within the block at @p position - start index.
	//----------------------------------------------------------------------------------------
	template <Bool STRIDED> MAXON_ATTRIBUTE_FORCE_INLINE Int GetBlock(Int position, Block<const T, STRIDED>& block) const
	{
		return const_cast<BaseList*>(this)->GetBlock(position, *(Block<T, STRIDED>*) &block);
	}

	//----------------------------------------------------------------------------------------
	/// Resizes the list to contain newCnt elements.
	/// If newCnt is smaller than GetCount() all extra elements are being deleted. If it is
	/// greater the list is expanded and the default constructor is called for new elements.
	/// @param[in] newCnt							New list size.
	/// @param[in] resizeFlags				See COLLECTION_RESIZE_FLAGS (flags other than ON_GROW_UNINITIALIZED/POD_UNINITIALIZED result in default behaviour).
	/// @return												False if allocation failed.
	//----------------------------------------------------------------------------------------
	ResultMem Resize(Int newCnt, COLLECTION_RESIZE_FLAGS resizeFlags = COLLECTION_RESIZE_FLAGS::DEFAULT)
	{
		Int	cnt = GetCount();
		Int	increment = newCnt - cnt;
		Bool	success = false;

		if (increment <= 0)
		{
			// Decrease list size.
			if (newCnt >= 0)
			{
				for (Iterator it = --End(); increment != 0; increment++)
				{
					if (Erase(it--) == Iterator())
						DebugStop();
				}

				success = true;
			}
			else
			{
				DebugStop("Invalid list size specified.");
			}
		}
		else
		{
			// Increase list size.
			if ((resizeFlags & COLLECTION_RESIZE_FLAGS::ON_GROW_UNINITIALIZED) == COLLECTION_RESIZE_FLAGS::NONE)
			{
				// Initialize elements (default behaviour).
				for (; increment > 0; increment--)
				{
					if (Append() == FAILED)
						break;
				}
			}
			else
			{
				// Append uninitialized elements.
				for (; increment > 0; increment--)
				{
					NODE* node = AllocNode();
					if (node == nullptr)
						break;

					// Initialize the link part only (this is like a BaseListNode without _data).
					new (node) BaseListLink<T>();
					InsertNode(End(), node);
				}
			}
			success = increment == 0;
		}

		return ResultMem(success);
	}

	//----------------------------------------------------------------------------------------
	/// Deletes the last element.
	/// @param[out] dst								Nullptr or pointer to return value.
	/// @return												True if there was at least one element.
	//----------------------------------------------------------------------------------------
	Bool Pop(T* dst = nullptr)
	{
		Iterator it = End();
		if (it != Begin())
		{
			--it;
			if (dst)
				*dst = std::move(*it);															// call move constructor if available

			if (Erase(it) == Iterator())
				DebugStop();

			return true;
		}
		return false;
	}

	//----------------------------------------------------------------------------------------
	/// BaseList specific: Removes the last node and returns the pointer to it.
	/// @param[out] dst								Used to return pointer to the last node (must not be null), the caller will take ownership of the node.
	/// @return												True if successful.
	//----------------------------------------------------------------------------------------
	Bool PopNode(NODE** dst)
	{
		Iterator it = End();
		if (it != Begin())
		{
			--it;
			it.GetNode()->Remove();
			*dst = it.GetNode();
			return true;
		}
		*dst = nullptr;
		return false;
	}

	//----------------------------------------------------------------------------------------
	/// Gets the index of element. The element must be part of the list, otherwise (e.g. if x is
	/// a copy of a list element) InvalidArrayIndex will be returned.
	/// This is compatible to the arrays but slow because GetIndex() has to iterate over the list.
	/// @return												Index of element or InvalidArrayIndex (not element of this).
	//----------------------------------------------------------------------------------------
	Int GetIndex(const T& x) const
	{
		return _head.GetIndex(&x);
	}

	//----------------------------------------------------------------------------------------
	/// BaseList specific: Removes the node and returns a pointer to it.
	/// @param[in] position						Position of the element to be removed.
	/// @return												Node pointer or null, the caller will take ownership of it.
	//----------------------------------------------------------------------------------------
	static NODE* RemoveNode(Iterator position)
	{
		NODE* node = nullptr;
		if (position)
		{
			node = position.GetNode();
			node->Remove();
		}
		return node;
	}

	//----------------------------------------------------------------------------------------
	/// BaseList specific: Removes the node and returns a pointer to it.
	/// @param[in] x									The element to be removed.
	/// @return												Node pointer or null, the caller will take ownership of it.
	//----------------------------------------------------------------------------------------
	static NODE* RemoveNode(T* x)
	{
		return RemoveNode(Iterator(x));
	}

	//----------------------------------------------------------------------------------------
	/// Copies an array or list.
	/// @param[in] src								Source list or array.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	template <typename SourceArray> Result<void> CopyFrom(const SourceArray& src)
	{
		// Avoid copying yourself.
		if ((void*) &src != (void*) this)
		{
			Reset();

			typename SourceArray::ConstIterator it(src);
			typename SourceArray::ConstIterator end(src.End());

			for (; it != end; it++)
			{
				if (Append(*it) == FAILED)
				{
					Reset();
					return CreateError(MAXON_SOURCE_LOCATION, ERROR_TYPE::OUT_OF_MEMORY);
				}
			}
		}
		return OK;
	}

	//----------------------------------------------------------------------------------------
	/// Swaps elements a and b (just changes the pointers, more efficient than global Swap(list[a], list[b]).
	/// @param[in] a									Position of element to be swapped.
	/// @param[in] b									Position of element to be swapped.
	//----------------------------------------------------------------------------------------
	void Swap(Iterator a, Iterator b)
	{
		NODE*	aNode = a.GetNode();
		NODE*	bNode = b.GetNode();
		NODE* aNext = aNode->_GetNext();
		NODE* bNext = bNode->_GetNext();

		if (aNext == bNode)																			// b is directly behind a?
		{
			bNode->Remove();
			bNode->InsertBefore(aNode);
		}
		else if (bNext == aNode)																// a is directly behind b?
		{
			aNode->Remove();
			aNode->InsertBefore(bNode);
		}
		else																										// a and b are not directly linked
		{
			aNode->Remove();
			bNode->Remove();

			bNode->InsertBefore(aNext);
			aNode->InsertBefore(bNext);
		}
	}

	//----------------------------------------------------------------------------------------
	/// Calculates the memory usage for this array.
	/// The array element class must have a public member GetMemorySize that returns an element's size.
	/// @return												Memory size in bytes.
	//----------------------------------------------------------------------------------------
	Int GetMemorySize() const
	{
		Int memUsage = 0;

		for (const T& i : *this)
			memUsage += maxon::GetMemorySizeHelper(i) + SIZEOF(NODE) - SIZEOF(T);

		return memUsage + SIZEOF(*this);
	}

	//----------------------------------------------------------------------------------------
	/// Gets an iterator for the first element.
	/// When you modify the list Begin() will change, it is not a constant value.
	/// @return												Iterator for the first element (equal to End() if the list is empty).
	//----------------------------------------------------------------------------------------
	ConstIterator Begin() const
	{
		return ConstIterator(_head.Begin());
	}

	//----------------------------------------------------------------------------------------
	/// Gets an iterator for the first element.
	/// When you modify the list Begin() will change, it is not a constant value.
	/// @return												Iterator for the first element (equal to End() if the list is empty).
	//----------------------------------------------------------------------------------------
	Iterator Begin()
	{
		return Iterator(_head.Begin());
	}

	//----------------------------------------------------------------------------------------
	/// Gets an iterator for the end (End() - 1 is the last element if the list is not empty).
	/// For the BaseList End() is in fact a constant value, it won't change even if you insert
	/// or remove elements. That's different from all arrays (where End() will change when you
	/// modify the array).
	/// @return												Iterator for the list end (this is behind the last element).
	//----------------------------------------------------------------------------------------
	ConstIterator End() const
	{
		return ConstIterator(_head.End());
	}

	//----------------------------------------------------------------------------------------
	/// Gets an iterator for the end (End() - 1 is the last element if the list is not empty).
	/// For the BaseList End() is in fact a constant value, it won't change even if you insert
	/// or remove elements. That's different from all arrays (where End() will change when you
	/// modify the array).
	/// @return												Iterator for the list end (this is behind the last element).
	//----------------------------------------------------------------------------------------
	Iterator End()
	{
		return Iterator(_head.End());
	}

	//----------------------------------------------------------------------------------------
	/// The BaseList iterator internally is a pointer to the NODE containing the data of
	/// type T and using it to iterate over a list or parts of it is as efficient as using a
	/// real pointer to the list nodes (for more ease of use you may want to invoke this via
	/// the C++11 range based for loop).
	///
	/// As already said you can use an Iterator almost like a pointer, e.g.
	/// @code
	/// it++;								// go to the next element
	/// it--;								// go to the previous element
	/// it += 5;						// advance by 5 elements
	/// it -= 3;						// go back 3 elements
	/// cnt = itB - itA;		// number of elements from itA to itB
	/// it = list.Begin();	// iterator to the first element of the list
	/// *it = value;				// assign value to the elements referenced by the iterator
	/// value = *it;				// get value of the element referenced by the iterator
	/// @endcode
	///
	/// Please note that using a postfix operator access (*it++ or *it--) can be slower than
	/// using the prefix form or a separate assignment. E.g.
	/// @code	value = *it++; @endcode is most likely slower than
	/// @code	value = it; ++it; @endcode or @code	value = it; it++; @endcode
	/// because *it++ requires a temporary copy of the iterator that the compiler may not
	/// be able to remove during optimization. As long as you only use the iterator's postfix
	/// operator without assignment it should be fine because the compiler will remove the
	/// temporary copy.
	//----------------------------------------------------------------------------------------
	template <Bool CONSTITERATOR> class IteratorTemplate
	{
	public:
		// For a const iterator, the BaseList, its values and its nodes have to be const within the iterator, otherwise they are non-const.
		// These type aliases have to be used throughout the iterator code instead of just BaseList, NODE or T.
		using CollectionType = typename ConstIf<BaseList, CONSTITERATOR>::type;
		using Type = typename ConstIf<T, CONSTITERATOR>::type;
		using NodeType = typename ConstIf<NODE, CONSTITERATOR>::type;
		static const Bool isLinearIterator = false;

		explicit IteratorTemplate(CollectionType& l) : _node(l._head.Begin())
		{
		}
		// NODE can be the same as T, therefore just one constructor for the iterator
		explicit IteratorTemplate(NodeType* pos = nullptr) : _node(pos)
		{
		}
		IteratorTemplate(const IteratorTemplate& src) : _node(src._node)
		{
		}
		IteratorTemplate& operator =(const IteratorTemplate& src)
		{
			_node = src._node;																		// self assignment is no problem here, therefore no check if (this != &src)
			return *this;
		}

#ifdef MAXON_COMPILER_INTEL
	#pragma warning disable 597
#endif
		operator ConstIterator&()
		{
			return *(ConstIterator*) this;
		}
#ifdef MAXON_COMPILER_INTEL
	#pragma warning enable 597
#endif

		Type* GetPtr() const
		{
			return _node->_GetData();
		}

		//----------------------------------------------------------------------------------------
		/// @return												true if the iterator points to an element.
		//----------------------------------------------------------------------------------------
		explicit operator Bool() const
		{
			return Bool(_node != nullptr);
		}

		Type& operator *() const
		{
			return *_node->_GetData();
		}
		Type* operator ->() const
		{
			return _node->_GetData();
		}

		Bool operator ==(const IteratorTemplate& b) const
		{
			return _node == b._node;
		}
		Bool operator !=(const IteratorTemplate& b) const
		{
			return _node != b._node;
		}

		// prefix operator ++ (increment and fetch)
		IteratorTemplate& operator ++()
		{
			_node = _node->_GetNext();
			return *this;
		}

		// postfix operator ++ (fetch and increment)
		const IteratorTemplate operator ++(int)
		{
			NodeType* tmp = _node;
			_node = _node->_GetNext();

			// use RVO
			return IteratorTemplate(tmp);
		}

		// prefix operator -- (decrement and fetch)
		IteratorTemplate& operator --()
		{
			_node = _node->_GetPrev();
			return *this;
		}

		// postfix operator -- (fetch and decrement)
		const IteratorTemplate operator --(int)
		{
			NodeType* tmp = _node;
			_node = _node->_GetPrev();

			// use RVO
			return IteratorTemplate(tmp);
		}

		// operator +=
		IteratorTemplate& operator +=(Int i)
		{
			*this = this->operator +(i);
			return *this;
		}

		// operator +
		IteratorTemplate operator +(Int i) const
		{
			NodeType* tmp = _node;

			if (i > 0)
			{
				for (; i > 0; i--)
					tmp = tmp->_GetNext();
			}
			else
			{
				for (; i < 0; i++)
					tmp = tmp->_GetPrev();
			}

			// use RVO
			return IteratorTemplate(tmp);
		}

		// operator -=
		IteratorTemplate& operator -=(Int i)
		{
			*this = this->operator -(i);
			return *this;
		}

		IteratorTemplate operator -(Int i) const
		{
			NodeType* tmp = _node;

			if (i > 0)
			{
				for (; i > 0; i--)
					tmp = tmp->_GetPrev();
			}
			else
			{
				for (; i < 0; i++)
					tmp = tmp->_GetNext();
			}

			// use RVO
			return IteratorTemplate(tmp);
		}

		Int operator -(const IteratorTemplate& b) const
		{
			Int cnt = 0;

			for (NodeType* search = b._node; search != nullptr; search = search->_GetNextChecked(), cnt++)
			{
				if (search == _node)
					return cnt;
			}

			cnt = 0;
			for (NodeType* search = b._node; search != nullptr; search = search->_GetPrevChecked(), cnt++)
			{
				if (search == _node)
					return cnt;
			}

			return 0;
		}

		NodeType* GetNode() const
		{
			return _node;
		}
	private:
		NodeType* _node;
	};

	//----------------------------------------------------------------------------------------
	/// Returns the allocator as reference. Typically this is used by the arrays and other
	/// base classes when multiple of them are "stiched" together as one big object all
	/// shall use one main allocator.
	/// @return												Allocator reference.
	//----------------------------------------------------------------------------------------
	ALLOCATOR& GetAllocator()
	{
		return *this;
	}

private:
	NODE*	AllocNode()
	{
		return (NODE*) this->Alloc(SIZEOF(NODE), MAXON_SOURCE_LOCATION_NAME(NODE));
	}
	void	DeleteNode(NODE* node)
	{
		node->~NODE();																						// will implicitely call Remove()
		this->Free(node);
	}

	HEAD	_head;
};


/// This supports c4d style list code that iterates through a list with GetNext()/GetPrev() and stops when null is returned
template <typename T> class BaseListLegacyNode
{
public:
	/// Returns the pointer to the next element or null (this is the last element of the list)
	T*	GetNext() const
	{
		// This type alias has to be moved into the function because T might be an incomplete type when BaseListLegacyNode is instantiated,
		// for example in use cases like "struct ListTestElement : public BaseListLegacyNode<ListTestElement>".
		using NODE = BaseListNode<T>;
		// The data of type T might be somewhere in the NODE. Since offsetof() is a nogo and
		// NODE might contain virtual stuff we have to get this offset the hard way. Since
		// some compilers try to be mighty clever the dummy pointer must not be 0.
		const NODE* dummy = (NODE*) sizeof(void*);
		const Int offset = Int(dummy->_GetData()) - Int(dummy);
		NODE* node = (NODE*) (Int(this) - offset);
		NODE*	next = node->_GetNext();
		return next->IsListHead() ? nullptr : (T*) (Int(next) + offset);
	}

	/// Returns the pointer to the previous element or null (this is the first element of the list)
	T*	GetPrev() const
	{
		using NODE = BaseListNode<T>;
		// The data of type T might be somewhere in the NODE. Since offsetof() is a nogo and
		// NODE might contain virtual stuff we have to get this offset the hard way. Since
		// some compilers try to be mighty clever the dummy pointer must not be 0.
		const NODE* dummy = (NODE*) sizeof(void*);
		const Int offset = Int(dummy->_GetData()) - Int(dummy);
		NODE* node = (NODE*) (Int(this) - offset);
		NODE*	prev = node->_GetPrev();
		return prev->IsListHead() ? nullptr : (T*) (Int(prev) + offset);
	}
};

/// Use this macro to implement custom BaseListNodes where T and NODE are equal.
/// NODE is the name of the class and linkPtr is the address of the BaseListLinkPOD.
/// <B> Don't forget that your custom node must have a destructor which has to call this->Remove(). </B>
/// <B> If you want to implement legacy stile GetNext() or GetPrev() you must check IsListHead() when using _GetNext() or _GetPrev(). </B>
#define IMPLEMENT_CUSTOM_BASELISTNODE(NODE, linkPtr) \
	friend class maxon::BaseList<NODE, NODE>; \
	using Link = maxon::BaseListLink<NODE>;	\
	void	Remove()																	{ Link::Remove((NODE*)this); }	\
	void	InsertBefore(NODE* next)									{ Link::InsertBefore((NODE*)this, next); }		\
	void	InsertAfter(NODE* prev)										{ Link::InsertAfter((NODE*)this, prev); }		\
	NODE*	_GetNext() const													{ return ((Link*)linkPtr)->_GetNext(); }	\
	NODE*	_GetPrev() const													{ return ((Link*)linkPtr)->_GetPrev(); }	\
	void	SetNext(NODE* val)												{ ((Link*)linkPtr)->SetNext(val); }	\
	void	SetPrev(NODE* val)												{ ((Link*)linkPtr)->SetPrev(val); }	\
	Bool	IsListHead() const												{ return ((Link*)linkPtr)->IsListHead(); }	\
	NODE*	_GetData() const													{ return (NODE*) this; }	\
	const maxon::BaseListLinkPOD* _GetLink() const	{ return (Link*) linkPtr; }




/// @}

} // namespace maxon

#endif // BASELIST_H__
