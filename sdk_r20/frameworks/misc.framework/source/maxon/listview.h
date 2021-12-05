#ifndef LISTVIEW_H__
#define LISTVIEW_H__

#include "maxon/container.h"

namespace maxon
{


template <Int N = MAXON_FLEXIBLE_ARRAY_LENGTH> class ViewIterator;

class ListViewType : public DataType
{
	MAXON_INTERFACE_NONVIRTUAL(ListViewType, MAXON_REFERENCE_NONE, "net.maxon.interface.listviewtype");
public:
//	MAXON_METHOD Result<void> SetModified(Container* value, Int memberIndex, const Range<UInt>& range, TimeStamp time) const;

//	MAXON_METHOD Result<void> CopyFrom(Generic* dest, const MemberMap* destMap, const ContainerConstPtr& src, Bool append = false) const;

	static MAXON_METHOD const ListViewType* GetGenericAbstract();

	static MAXON_METHOD Result<const ListViewType*> CreateAbstract(const Block<const Member>& members);

	static MAXON_METHOD Result<const ListViewType*> GetAbstract(const DataType* type);

	static MAXON_METHOD Result<const DataType*> GetViewRefType(const DataType* type);

//	MAXON_METHOD Bool PrivateIsBaseOfOrSame(const MemberMap* map, const ListViewType* other, const MemberMap* otherMap, Bool useNames) const;

//	static MAXON_METHOD String ToStringImpl(const DataType* type, const void* value, const MemberMap* map, const FormatStatement* formatStatement);

	static MAXON_METHOD Block<const Int> GetIdentityBlock(Int length);

	String ToString(const FormatStatement* formatStatement) const
	{
		return GetId().ToString(formatStatement);
	}

private:
	template <Int N> friend class ViewIterator;

	static MAXON_METHOD Result<void> InitIterator(ViewIterator<>& iterator, const ConstDataPtr& value);

	static MAXON_METHOD Result<void> ValidateIterator(ViewIterator<>& iterator);

	static MAXON_METHOD void FreeIterator(ViewIterator<>& iterator);

	static MAXON_METHOD Result<void> MoveIterator(ViewIterator<>& iterator, Int index);

//	static MAXON_METHOD MultiIndex64 GetIteratorMultiIndex(const ViewIterator<>& iterator);
};


class ListView
{
};

class ListViewRef
{
public:
	ListViewRef() = default;

	~ListViewRef()
	{
		Reset();
	}

	void Reset()
	{
		if (_view)
		{
			_type->Destruct(_view, 1);
			DeleteMem(_view);
			_type = nullptr;
		}
	}

	ListViewRef(ListViewRef&& src) : _type(src._type), _view(src._view)
	{
		src._type = nullptr;
		src._view = nullptr;
	}

	MAXON_OPERATOR_MOVE_ASSIGNMENT(ListViewRef);

	Result<void> CopyFrom(const ListViewRef& src)
	{
		iferr_scope;
		Reset();
		if (src._view)
		{
			void* mem = src._type->Create() iferr_return;
			_type = src._type;
			_view = reinterpret_cast<ListView*>(mem);
			_type->CopyFrom(_view, src._view, 1) iferr_return;
		}
		return OK;
	}

	Result<void> Create(const ListViewType* type)
	{
		iferr_scope;
		Reset();
		void* mem = type->Create() iferr_return;
		_type = type;
		_view = reinterpret_cast<ListView*>(mem);
		return OK;
	}

	explicit operator Bool() const
	{
		return _view != nullptr;
	}

	const ListViewType* GetType() const
	{
		return _type;
	}

	ListView* GetValue() const
	{
		return _view;
	}

private:
	const ListViewType* _type = nullptr;
	ListView* _view = nullptr;

	friend class ListViewTypeImpl;
};

template <Bool REFS, Int MEMBER_COUNT> class ArrayViewBase;

using GenericArrayView = ArrayViewBase<false, MAXON_FLEXIBLE_ARRAY_LENGTH>;

class ArrayViewType : public ListViewType
{
	MAXON_INTERFACE_NONVIRTUAL_DERIVED(ArrayViewType, MAXON_REFERENCE_NONE, "net.maxon.interface.arrayviewtype");
public:
	static MAXON_METHOD Result<const ArrayViewType*> Create(Bool refs, const Block<const Member>& members);

	static MAXON_METHOD const ArrayViewType* GetGeneric(Bool refs);

	using ListViewType::ToString;

	static MAXON_METHOD String ToString(const DataType* type, const GenericArrayView* view, const FormatStatement* fs);
};

template <Bool REFS> struct ArrayViewMember
{
	using Array = typename std::conditional<REFS, GenericArrayContainer, ArrayContainerInterface::Ptr>::type;

	void Set(const ConstDataPtr& value, INNERMOST_MEMBER mb)
	{
		const DataType* t = value.GetType();
		if (t->GetValueKind() & VALUEKIND::ARRAY_VIEW)
		{
			*this = reinterpret_cast<const ArrayViewBase<REFS, MAXON_FLEXIBLE_ARRAY_LENGTH>*>(value.PrivateGetPtr())->GetMember(mb);
		}
		else if (!REFS && (t->GetValueKind() & VALUEKIND::ARRAY_CONTAINER_BASE_TEST))
		{
			array = const_cast<ArrayContainerInterface*>(reinterpret_cast<const ArrayContainerInterface*>(value.PrivateGetPtr()));
			member = mb;
		}
		else
		{
			DebugAssert(t->GetValueKind() & VALUEKIND::ARRAY_CONTAINER_REF_BASE_TEST);
			array = *reinterpret_cast<ArrayContainerInterface* const*>(value.PrivateGetPtr());
			member = mb;
		}
	}

	Array array;
	INNERMOST_MEMBER member;
};

template <Bool REFS, Int MEMBER_COUNT> class ArrayViewBase : public ListView, public Indexable
{
public:
	using Member = ArrayViewMember<REFS>;

	Int GetCount() const
	{
		return _members[0].array.GetCount();
	}

	//----------------------------------------------------------------------------------------
	/// Returns true if the given index is within the array boundaries.
	//----------------------------------------------------------------------------------------
	Bool IsValidIndex(Int index) const
	{
		return UInt(index) < UInt(GetCount());
	}

	//----------------------------------------------------------------------------------------
	/// Returns an error if the given index is not within the array boundaries.
	//----------------------------------------------------------------------------------------
	Result<void> CheckValidIndex(Int index) const
	{
		if (IsValidIndex(index))
			return OK;
		return CreateError(MAXON_SOURCE_LOCATION, ERROR_TYPE::ILLEGAL_ARGUMENT);
	}

	Int GetBlock(INNERMOST_MEMBER member, Int index, StridedBlock<const Generic>& block) const
	{
		DebugAssert((UInt(member) < UInt(MEMBER_COUNT)) || (MEMBER_COUNT == MAXON_FLEXIBLE_ARRAY_LENGTH));
		const Member& m = _members[Int(member)];
		return m.array.GetPointer()->GetBlock(m.member, index, block);
	}

	Int GetWritableBlock(INNERMOST_MEMBER member, Int index, StridedBlock<Generic>& block) const
	{
		static_assert(!REFS, "GetWritableBlock can't be invoked for an array container view with references.");
		return GetBlock(member, index, reinterpret_cast<StridedBlock<const Generic>&>(block));
	}

	Int GetBlock(INNERMOST_MEMBER member, Int index, SimdBlock<const Generic>& block) const
	{
		DebugAssert((UInt(member) < UInt(MEMBER_COUNT)) || (MEMBER_COUNT == MAXON_FLEXIBLE_ARRAY_LENGTH));
		const Member& m = _members[Int(member)];
		return m.array.GetPointer()->GetBlock(m.member, index, block);
	}

	Int GetWritableBlock(INNERMOST_MEMBER member, Int index, SimdBlock<Generic>& block) const
	{
		static_assert(!REFS, "GetWritableBlock can't be invoked for an array container view with references.");
		return GetBlock(member, index, reinterpret_cast<SimdBlock<const Generic>&>(block));
	}

	const TimeStampMap& GetTimeStampMap(INNERMOST_MEMBER member) const
	{
		DebugAssert((UInt(member) < UInt(MEMBER_COUNT)) || (MEMBER_COUNT == MAXON_FLEXIBLE_ARRAY_LENGTH));
		const Member& m = _members[Int(member)];
		return m.array.GetPointer()->GetTimeStampMap(m.member);
	}

	ConstDataPtr GetElement(INNERMOST_MEMBER member, Int index) const
	{
		DebugAssert((UInt(member) < UInt(MEMBER_COUNT)) || (MEMBER_COUNT == MAXON_FLEXIBLE_ARRAY_LENGTH));
		const Member& m = _members[Int(member)];
		const DataType* t;
		INNERMOST_MEMBER im;
		const Generic& a = m.array.GetPointer()->GetElement(m.member, index, t, im);
		return ConstDataPtr(t, &a);
	}

	void GetIndexableElement(INNERMOST_MEMBER member, Int index, Member& result) const
	{
		DebugAssert((UInt(member) < UInt(MEMBER_COUNT)) || (MEMBER_COUNT == MAXON_FLEXIBLE_ARRAY_LENGTH));
		const Member& m = _members[Int(member)];
		const DataType* t;
		const Generic& a = m.array.GetPointer()->GetElement(m.member, index, t, result.member);
		if (t->GetValueKind() & VALUEKIND::ARRAY_VIEW)
		{
			result = reinterpret_cast<const ArrayViewBase<REFS, MAXON_FLEXIBLE_ARRAY_LENGTH>&>(a)._members[Int(result.member)];
		}
		else if (!REFS && (t->GetValueKind() & VALUEKIND::ARRAY_CONTAINER_BASE_TEST))
		{
			result.array = const_cast<ArrayContainerInterface*>(reinterpret_cast<const ArrayContainerInterface*>(&a));
		}
		else
		{
			DebugAssert(t->GetValueKind() & VALUEKIND::ARRAY_CONTAINER_REF_BASE_TEST);
			result.array = reinterpret_cast<ArrayContainerInterface* const&>(a);
		}
	}

	void Set(INNERMOST_MEMBER member, const typename Member::Array& array, INNERMOST_MEMBER arrayMember)
	{
		DebugAssert((UInt(member) < UInt(MEMBER_COUNT)) || (MEMBER_COUNT == MAXON_FLEXIBLE_ARRAY_LENGTH));
		Member& m = _members[Int(member)];
		m.array = array;
		m.member = arrayMember;
	}

	ConstDataPtr GetDataPtr(const ArrayViewType* type) const
	{
		return ConstDataPtr(type, reinterpret_cast<const Generic*>(this));
	}

	static Int GetSize(Int memberCount)
	{
		return SIZEOF(ArrayViewBase) + SIZEOF(Member) * (memberCount - MEMBER_COUNT);
	}

	const Member& GetMember(INNERMOST_MEMBER member) const
	{
		return _members[Int(member)];
	}

	Member& GetMember(INNERMOST_MEMBER member)
	{
		return _members[Int(member)];
	}

protected:
	Member _members[MEMBER_COUNT];

	template <Bool, Int> friend class ArrayViewBase;
	friend class IndexableTypeImpl;
	friend class ListViewTypeImpl;
	friend class ArrayViewTypeImpl;
	friend class ArrayViewFunctions;
};

MAXON_ASSERT_STANDARD_LAYOUT(GenericArrayView);

template <Bool REFS, typename... T> class ArrayView : public ArrayViewBase<REFS, sizeof...(T)>
{
public:
	static const ArrayView& NullValue()
	{
		return GetZeroRef<ArrayView>();
	}
};

template <GET_DATATYPE_POLICY POLICY, Bool REFS, typename... T> inline Result<const ArrayViewType*> PrivateGetDataType(ArrayView<REFS, T...>*, OverloadRank0)
{
	Member members[] = {GetDataType<T, Or<GET_DATATYPE_POLICY, POLICY, GET_DATATYPE_POLICY::NO_DECAY>::value>()...};
	return ArrayViewType::Create(REFS, members);
}


class ConcatListView;

class ConcatListViewType : public ListViewType
{
	MAXON_INTERFACE_NONVIRTUAL_DERIVED(ConcatListViewType, MAXON_REFERENCE_NONE, "net.maxon.interface.concatlistviewtype");
public:
	static MAXON_METHOD Result<const ConcatListViewType*> Create(const Block<const Member>& members);

private:
	static MAXON_METHOD ConcatListView* Alloc(const ConcatListViewType* type, MAXON_SOURCE_LOCATION_DECLARATION);

	static MAXON_METHOD void Free(const ConcatListView* view);

	static MAXON_METHOD void Flush(ConcatListView& view);

	static MAXON_METHOD Result<void> Add(ConcatListView& view, MoveDataPtr&& value);

	friend class ConcatListView;
};

class ConcatListView : public ListView
{
public:
	using IsAllocType = std::true_type;

	static ConcatListView* Alloc(MAXON_SOURCE_LOCATION_DECLARATION, const ConcatListViewType* type)
	{
		return ConcatListViewType::Alloc(type, MAXON_SOURCE_LOCATION_FORWARD);
	}

	static void Free(const ConcatListView* view)
	{
		ConcatListViewType::Free(view);
	}

	void Flush()
	{
		ConcatListViewType::Flush(*this);
	}

	Result<void> Add(MoveDataPtr&& value)
	{
		return ConcatListViewType::Add(*this, std::move(value));
	}

protected:
	ConcatListView() = default;
	~ConcatListView() = default;
};

using ConcatListViewRef = UniqueRef<ConcatListView>;


//----------------------------------------------------------------------------------------
/// XformListViewLevels describes how the XformListView shall iterate over its inputs.
/// At the beginning, each of the inputs is available as an iterator member in the order of the inputs.
/// Then you have to add several (nested) iterations levels using BeginLevel(). Each level introduces
/// new iterator members based on the existing ones:
/// - AddMember() iterates over the values of an existing member. You can have several such iterations
///   within the same level, they are done in parallel.
/// - AddIteratorMember() and AdvanceIterator() allow to create and advance an iterator over a member manually.
///   This can be used when a flat container with N*M values has to be matched against a N-iteration with
///   a nested M-iteration: Within an enclosing level use AddIteratorMember(), and within the level
///   of the M-iteration use AdvanceIterator().
/// - LoadElements() indexes into an existing array member using the index of an outer iteration. This can be
///   used to match a MxN array with a NxM iteration: Within the nested M-iteration, an automatic iteration
///   using AddMember() can be done over the outer dimension of the array. Then with LoadElements() the index
///   of the outer N-iteration is used to index the inner dimension of the array.
//----------------------------------------------------------------------------------------
class XformListViewLevels
{
public:
	XformListViewLevels()
	{
	}

	XformListViewLevels(XformListViewLevels&& src) : MAXON_MOVE_MEMBERS(_data)
	{
	}

	MAXON_OPERATOR_MOVE_ASSIGNMENT(XformListViewLevels);

	Result<void> CopyFrom(const XformListViewLevels& src)
	{
		return _data.CopyFrom(src._data);
	}

	enum class ACTION : Int
	{
		LEVEL = -2,
		MEMBER = -3,
		ITERATOR_MEMBER = -4,
		LOAD_ELEMENTS = -5,
		ADVANCE_ITERATOR = -6,
		ADVANCE_ITERATOR_MEMBER = -7,
		ADVANCE_ITERATOR_END = -8,
		END = -9
	} MAXON_ENUM_LIST_CLASS(ACTION);

	Result<void> BeginLevel()
	{
		return _data.Append(Int(ACTION::LEVEL));
	}

	Result<void> AddMember(Int member)
	{
		iferr_scope;
		_data.Append(Int(ACTION::MEMBER)) iferr_return;
		return _data.Append(member);
	}

	Result<void> AddIteratorMember(Int member)
	{
		iferr_scope;
		_data.Append(Int(ACTION::ITERATOR_MEMBER)) iferr_return;
		return _data.Append(member);
	}

	Result<void> LoadElements(Int level, Int member)
	{
		iferr_scope;
		_data.Append(Int(ACTION::LOAD_ELEMENTS)) iferr_return;
		_data.Append(level) iferr_return;
		return _data.Append(member);
	}

	Result<void> AdvanceIterator(Int level)
	{
		iferr_scope;
		_data.Append(Int(ACTION::ADVANCE_ITERATOR)) iferr_return;
		return _data.Append(level);
	}

	Result<void> End()
	{
		return _data.Append(Int(ACTION::END));
	}

	MAXON_OPERATOR_EQUALITY_HASHCODE(XformListViewLevels, _data);

	void Flush()
	{
		_data.Flush();
	}

	const BaseArray<Int>& GetActionData() const
	{
		return _data;
	}

	String ToString(const FormatStatement* fmt) const
	{
		return "{"_s + JoinElements(Iterable::Map(_data, [fmt](Int x) { return (x < -1) ? GlobalToString(ACTION(x), fmt) : String::IntToString(x); }), ","_s, fmt) + "}"_s;
	}

private:
	MAXON_DISALLOW_COPY_AND_ASSIGN(XformListViewLevels);

	BaseArray<Int> _data;
};


class XformListView;

class XformListViewType : public ListViewType
{
	MAXON_INTERFACE_NONVIRTUAL_DERIVED(XformListViewType, MAXON_REFERENCE_NONE, "net.maxon.interface.xformlistviewtype");
public:
	static MAXON_METHOD Result<const XformListViewType*> Create(const Block<const DataType* const>& inputs, const XformListViewLevels& iterations, const Block<const Int>& map);

private:
	static MAXON_METHOD XformListView* Alloc(const XformListViewType* type, MAXON_SOURCE_LOCATION_DECLARATION);

	static MAXON_METHOD void Free(const XformListView* view);

	static MAXON_METHOD void Flush(XformListView& view);

	static MAXON_METHOD Result<void> SetInput(XformListView& view, Int index, const ConstDataPtr& value);

	friend class XformListView;
};

class XformListView : public ListView
{
public:
	using IsAllocType = std::true_type;

	static XformListView* Alloc(MAXON_SOURCE_LOCATION_DECLARATION, const XformListViewType* type)
	{
		return XformListViewType::Alloc(type, MAXON_SOURCE_LOCATION_FORWARD);
	}

	static void Free(const XformListView* view)
	{
		XformListViewType::Free(view);
	}

	void Flush()
	{
		XformListViewType::Flush(*this);
	}

	Result<void> SetInput(Int index, const ConstDataPtr& value)
	{
		return XformListViewType::SetInput(*this, index, value);
	}

protected:
	XformListView() = default;
	~XformListView() = default;
};

using XformListViewRef = UniqueRef<XformListView>;


template <Int N> class ViewIterator
{
public:
	ViewIterator() : _blockEnd(-1)
	{
	}

	ViewIterator(ViewIterator&& src)
	{
		DebugAssert(src._state.IsEmpty());
		MemCopy(this, &src, SIZEOF(ViewIterator));
	}

	void Free()
	{
		if ((_blockEnd >= 0) && _value.GetType())
		{
			ListViewType::FreeIterator(*reinterpret_cast<ViewIterator<>*>(this));
			_blockEnd = -1;
		}
	}

	~ViewIterator()
	{
		Free();
	}

	Result<void> PrivateInit(const ConstDataPtr& value, const Block<const Int>& map)
	{
		if ((_blockEnd >= 0) && _value.GetType())
			ListViewType::FreeIterator(*reinterpret_cast<ViewIterator<>*>(this));
		_map = map;
		if (!value.GetType())
		{
			_index = 0;
			_blockEnd = 1;
			_value = value;
			return OK;
		}
		return ListViewType::InitIterator(*reinterpret_cast<ViewIterator<>*>(this), value);
	}

	Result<void> Init(const ConstDataPtr& value, const Block<const Int>& map = ListViewType::GetIdentityBlock(N))
	{
		DebugAssert(map.GetCount() == N);
		return PrivateInit(value, map);
	}

	template <Bool ENABLE_SIMD = true> Result<void> Advance()
	{
		DebugAssert(_blockEnd >= 0);
		for (ViewIteratorMember& m : _members)
		{
			m.Advance<ENABLE_SIMD>();
		}
		++_index;
		if (MAXON_LIKELY(_index != _blockEnd))
			return OK;
		if (!_value.GetType())
		{
			_blockEnd = -1;
			return OK;
		}
		return ListViewType::ValidateIterator(*reinterpret_cast<ViewIterator<>*>(this));
	}

	template <Bool ENABLE_SIMD = true> Result<void> PrivateAdvance(Int from, Int to)
	{
#ifdef MAXON_TARGET_DEBUG
		DebugAssert(from <= to);
		DebugAssert(to <= _map.GetCount());
		DebugAssert(_blockEnd >= 0);
		DebugAssert(_index < _blockEnd);
		for (Int i = 0; i < _map.GetCount(); ++i)
		{
			if ((i < from) || (i >= to))
			{
				DebugAssert(_members[i].stride == 0);
			}
		}
#endif
		for (ViewIteratorMember* m = _members + from, *end = _members + to; m != end; ++m)
		{
			m->Advance<ENABLE_SIMD>();
		}
		++_index;
		if (MAXON_LIKELY(_index != _blockEnd))
			return OK;
		if (!_value.GetType())
		{
			_blockEnd = -1;
			return OK;
		}
		return ListViewType::ValidateIterator(*reinterpret_cast<ViewIterator<>*>(this));
	}

	template <Bool ENABLE_SIMD = true> Result<void> PrivateAdvance(Int from, Int to, Int advanceCount)
	{
#ifdef MAXON_TARGET_DEBUG
		DebugAssert(from <= to);
		DebugAssert(to <= _map.GetCount());
		DebugAssert(_blockEnd >= 0);
		DebugAssert(_index + advanceCount <= _blockEnd);
		for (Int i = 0; i < _map.GetCount(); ++i)
		{
			if ((i < from) || (i >= to))
			{
				DebugAssert(_members[i].stride == 0);
			}
		}
#endif
		for (ViewIteratorMember* m = _members + from, *end = _members + to; m != end; ++m)
		{
			m->Advance<ENABLE_SIMD>(advanceCount);
		}
		_index += advanceCount;
		if (MAXON_LIKELY(_index != _blockEnd))
			return OK;
		if (!_value.GetType())
		{
			_blockEnd = -1;
			return OK;
		}
		return ListViewType::ValidateIterator(*reinterpret_cast<ViewIterator<>*>(this));
	}

	template <Bool ENABLE_SIMD = true> void PrivateAdvanceWithinBlock(Int from, Int to)
	{
#ifdef MAXON_TARGET_DEBUG
		DebugAssert(from <= to);
		DebugAssert(to <= _map.GetCount());
		DebugAssert(_blockEnd >= 0);
		DebugAssert(_index < _blockEnd);
		for (Int i = 0; i < _map.GetCount(); ++i)
		{
			if ((i < from) || (i >= to))
			{
				DebugAssert(_members[i].stride == 0);
			}
		}
#endif
		for (ViewIteratorMember* m = _members + from, *end = _members + to; m != end; ++m)
		{
			m->Advance<ENABLE_SIMD>();
		}
		++_index;
	}

	void PrivateSetIndex(Int i)
	{
		_index = i;
	}

	Result<void> MoveTo(Int index)
	{
		return ListViewType::MoveIterator(*reinterpret_cast<ViewIterator<>*>(this), index);
	}

	explicit operator Bool() const
	{
		return Bool(MAXON_LIKELY(_blockEnd >= 0));
	}

	Int GetIndex() const
	{
		return _index;
	}

	Int GetBlockEnd() const
	{
		return _blockEnd;
	}

	Int GetMemberCount() const
	{
		return _map.GetCount();
	}

/*
	MultiIndex64 GetMultiIndex() const
	{
		return ContainerType::GetIteratorMultiIndex(*reinterpret_cast<const ViewIterator<>*>(this));
	}

	const Container* GetMemberValue(Int index) const
	{
		DebugAssert((UInt) index < (UInt) N);
		return _members[index].ptr;
	}

	const ContainerType* GetMemberType(Int index) const
	{
		return _members[index].type;
	}
*/
	const ConstDataPtr& GetMember(Int index) const
	{
		DebugAssert((UInt) index < (UInt) N);
		return _members[index].value;
	}

	static Int GetMemberElementOffset(Int index)
	{
		return offsetof(ViewIterator, _members) + index * SIZEOF(ViewIteratorMember);
	}

	ViewIteratorMember* PrivateGetMemberArray()
	{
		return _members;
	}

	const ViewIteratorMember* PrivateGetMemberArray() const
	{
		return _members;
	}

	static Int PrivateGetMemberArrayOffset()
	{
		return offsetof(ViewIterator, _members);
	}
/*
	const Container* GetContainer() const
	{
		return _value;
	}

	const ContainerType* GetContainerType() const
	{
		return _type;
	}
*/
	static Int GetSize(Int memberCount)
	{
		return SIZEOF(ViewIterator) + (memberCount - N) * SIZEOF(ViewIteratorMember);
	}

	static Int GetValueOffset()
	{
		return offsetof(ViewIterator, _value);
	}

private:
	BufferedBaseArray<Char, SIZEOF(Int) * 30> _state;
	ConstDataPtr _value;
	Int _index;
	Int _blockEnd;
	Block<const Int> _map; // maps from iterator member index to the member index of the _value
	ViewIteratorMember _members[N]; // has to be last member as there may be more than N members

	friend class ListViewTypeImpl;
};

MAXON_ASSERT_STANDARD_LAYOUT(ViewIterator<>);


#if 0
template <typename VIEW> class MappedView;
// template <typename BASE> class ContainerRefTemplate;

struct MappedConstValue
{
	using ValueType = const Generic;

	const Generic* _value;
	const MemberMap* _map;

//	String ToString(const FormatStatement* fs) const
//	{
//		return _ptr ? _type->ToString(_ptr, _map, fs) : "nullptr"_s;
//	}

//	template <typename DST> const ContainerRefTemplate<TypedContainerPtr<const DST>>& Cast() const
//	{
//		DebugAssert(_type->GetValueKind() & DST::KIND);
//		return *reinterpret_cast<const ContainerRefTemplate<TypedContainerPtr<const DST>>*>(this);
//	}
};

struct MappedValue : public MappedConstValue
{
	using ValueType = Generic;

	MappedValue() = default;

	MappedValue(Generic* ptr, const MemberMap* map) : MappedConstValue{ptr, map}
	{
	}

//	template <typename DST> const ContainerRefTemplate<TypedContainerPtr<DST>>& Cast() const
//	{
//		DebugAssert(_type->GetValueKind() & DST::KIND);
//		return *reinterpret_cast<const ContainerRefTemplate<TypedContainerPtr<DST>>*>(this);
//	}
};


template <typename VIEW> class MappedView : protected std::conditional<std::is_const<VIEW>::value, MappedConstValue, MappedValue>::type
{
public:
	using Value = typename std::conditional<std::is_const<VIEW>::value, MappedConstValue, MappedValue>::type;
	using View = VIEW;

	MappedView() = default;

	MappedView(VIEW* value, const MemberMap* map) : Value(value, map)
	{
	}

	VIEW* GetView() const
	{
		return (VIEW*) this->_value;
	}

//	template <typename DST, typename = typename std::enable_if<std::is_base_of<DST, C>::value && (std::is_const<DST>::value >= std::is_const<C>::value)>::type> operator const ContainerRefTemplate<TypedContainerPtr<DST>>&() const
//	{
//		return *reinterpret_cast<const ContainerRefTemplate<TypedContainerPtr<DST>>*>(this);
//	}

	const MemberMap* GetMemberMap() const
	{
		return this->_map;
	}
#if 0
	Result<ContainerRefTemplate<TypedContainerPtr>> Map(const MemberMap* map) const
	{
		iferr_scope;
		map = DataTypeLib::Compose(map, _ptr._map) iferr_return;
		return ContainerRefTemplate<TypedContainerPtr>((C*) _ptr._ptr, static_cast<const typename C::CType*>(_ptr._type), map);
	}

	operator const Ptr&() const
	{
		return _ptr;
	}

	operator const typename std::conditional<std::is_const<C>::value, DummyReturnType, ContainerConstPtr>::type&() const
	{
		return _ptr;
	}

	const Ptr& PrivateGet() const
	{
		return _ptr;
	}

	const ContainerRefTemplate<TypedContainerPtr>& GetContainerPtr() const
	{
		return *static_cast<const ContainerRefTemplate<TypedContainerPtr>*>(this);
	}
#endif
};


using ArrayContainerPtr = ContainerRefTemplate<TypedContainerPtr<ArrayContainer>>;
using ArrayContainerConstPtr = ContainerRefTemplate<TypedContainerPtr<const ArrayContainer>>;
using ConcatContainerPtr = ContainerRefTemplate<TypedContainerPtr<ConcatContainer>>;
using ConcatContainerConstPtr = ContainerRefTemplate<TypedContainerPtr<const ConcatContainer>>;
using XformContainerPtr = ContainerRefTemplate<TypedContainerPtr<XformContainer>>;
using XformContainerConstPtr = ContainerRefTemplate<TypedContainerPtr<const XformContainer>>;
using SingletonContainerPtr = ContainerRefTemplate<TypedContainerPtr<SingletonContainer>>;
using SingletonContainerConstPtr = ContainerRefTemplate<TypedContainerPtr<const SingletonContainer>>;
using ValueContainerPtr = ContainerRefTemplate<TypedContainerPtr<ValueContainer>>;
using ValueContainerConstPtr = ContainerRefTemplate<TypedContainerPtr<const ValueContainer>>;

template <typename C> class ContainerRefBase;

using ContainerRef = ContainerRefTemplate<ContainerRefBase<Container>>;
using ContainerConstRef = ContainerRefTemplate<ContainerRefBase<const Container>>;


using ArrayContainerRef = ContainerRefTemplate<ContainerRefBase<ArrayContainer>>;
using ArrayContainerConstRef = ContainerRefTemplate<ContainerRefBase<const ArrayContainer>>;
using ConcatContainerRef = ContainerRefTemplate<ContainerRefBase<ConcatContainer>>;
using ConcatContainerConstRef = ContainerRefTemplate<ContainerRefBase<const ConcatContainer>>;
using XformContainerRef = ContainerRefTemplate<ContainerRefBase<XformContainer>>;
using XformContainerConstRef = ContainerRefTemplate<ContainerRefBase<const XformContainer>>;
using SingletonContainerRef = ContainerRefTemplate<ContainerRefBase<SingletonContainer>>;
using SingletonContainerConstRef = ContainerRefTemplate<ContainerRefBase<const SingletonContainer>>;


template <typename C> class TypedContainerPtr
{
public:
	using Ptr = typename std::conditional<std::is_const<C>::value, ContainerConstPtr, ContainerPtr>::type;
	using ValueType = C;

	TypedContainerPtr()
	{
		_ptr._ptr = nullptr;
		_ptr._type = nullptr;
		_ptr._map = nullptr;
	}

	TypedContainerPtr(C* value, const typename C::CType* type, const MemberMap* map)
	{
		_ptr._ptr = value;
		_ptr._type = type;
		_ptr._map = map;
	}

	C* GetContainer() const
	{
		return (C*) _ptr._ptr;
	}

	const typename C::CType* GetType() const
	{
		return static_cast<const typename C::CType*>(_ptr._type);
	}

	template <typename DST, typename = typename std::enable_if<std::is_base_of<DST, C>::value && (std::is_const<DST>::value >= std::is_const<C>::value)>::type> operator const ContainerRefTemplate<TypedContainerPtr<DST>>&() const
	{
		return *reinterpret_cast<const ContainerRefTemplate<TypedContainerPtr<DST>>*>(this);
	}

	const MemberMap* GetMemberMap() const
	{
		return _ptr._map;
	}

	Result<ContainerRefTemplate<TypedContainerPtr>> Map(const MemberMap* map) const
	{
		iferr_scope;
		map = DataTypeLib::Compose(map, _ptr._map) iferr_return;
		return ContainerRefTemplate<TypedContainerPtr>((C*) _ptr._ptr, static_cast<const typename C::CType*>(_ptr._type), map);
	}

	operator const Ptr&() const
	{
		return _ptr;
	}

	operator const typename std::conditional<std::is_const<C>::value, DummyReturnType, ContainerConstPtr>::type&() const
	{
		return _ptr;
	}

	const Ptr& PrivateGet() const
	{
		return _ptr;
	}

	const ContainerRefTemplate<TypedContainerPtr>& GetContainerPtr() const
	{
		return *static_cast<const ContainerRefTemplate<TypedContainerPtr>*>(this);
	}

protected:
	Ptr _ptr;
};

using ArrayContainerPtr = ContainerRefTemplate<TypedContainerPtr<ArrayContainer>>;
using ArrayContainerConstPtr = ContainerRefTemplate<TypedContainerPtr<const ArrayContainer>>;
using ConcatContainerPtr = ContainerRefTemplate<TypedContainerPtr<ConcatContainer>>;
using ConcatContainerConstPtr = ContainerRefTemplate<TypedContainerPtr<const ConcatContainer>>;
using XformContainerPtr = ContainerRefTemplate<TypedContainerPtr<XformContainer>>;
using XformContainerConstPtr = ContainerRefTemplate<TypedContainerPtr<const XformContainer>>;
using SingletonContainerPtr = ContainerRefTemplate<TypedContainerPtr<SingletonContainer>>;
using SingletonContainerConstPtr = ContainerRefTemplate<TypedContainerPtr<const SingletonContainer>>;
using ValueContainerPtr = ContainerRefTemplate<TypedContainerPtr<ValueContainer>>;
using ValueContainerConstPtr = ContainerRefTemplate<TypedContainerPtr<const ValueContainer>>;


template <GET_DATATYPE_POLICY POLICY> inline ResultOk<const DataType*> PrivateGetDataType(ContainerConstPtr*, OverloadRank0)
{
	return ContainerType::GetGeneric()->GetContainerPtrType();
}

template <GET_DATATYPE_POLICY POLICY, typename T> inline ResultOk<const DataType*> PrivateGetDataType(ContainerRefTemplate<TypedContainerPtr<T>>*, OverloadRank0)
{
	return T::CType::GetGeneric()->GetContainerPtrType();
}


template <typename C> class ContainerRefBase : public TypedContainerPtr<C>
{
public:
	ContainerRefBase() = default;

	ContainerRefBase(ContainerRefBase&& src) : TypedContainerPtr<C>(src)
	{
		src._ptr._type = nullptr;
		src._ptr._ptr = nullptr;
		src._ptr._map = nullptr;
	}

	MAXON_OPERATOR_MOVE_ASSIGNMENT(ContainerRefBase);

	Result<void> CopyFrom(const ContainerRefBase& src)
	{
		return UnsupportedOperationError(MAXON_SOURCE_LOCATION);
	}

	void Reset()
	{
		if (this->_ptr._ptr)
		{
			this->_ptr._type->Destruct(this->_ptr._ptr, 1);
			DeleteMem(this->_ptr._ptr);
			this->_ptr._type = nullptr;
			this->_ptr._ptr = nullptr;
			this->_ptr._map = nullptr;
		}
	}

	~ContainerRefBase()
	{
		Reset();
	}

	Result<void> Create(const typename C::CType* type, const MemberMap* map)
	{
		iferr_scope;
		Reset();
		Char* c = NewMem(Char, type->GetSize()) iferr_return;
		type->Construct(c, 1);
		this->_ptr._type = type;
		this->_ptr._ptr = reinterpret_cast<Generic*>(c);
		this->_ptr._map = map;
		return OK;
	}

	Result<void> Create(const typename C::CType* type)
	{
		return Create(type, type->GetIdentityMap());
	}

private:
	MAXON_DISALLOW_COPY_AND_ASSIGN(ContainerRefBase);
};

template <typename BASE, typename FN> class ContainerRefFn : public BASE
{
public:
	explicit operator Bool() const
	{
		return Bool(this->PrivateGet()._ptr);
	}

	String ToString(const FormatStatement* fs) const
	{
		return this->PrivateGet().ToString(fs);
	}
};

template <typename BASE> class ContainerRefTemplate : public ContainerRefFn<BASE, typename BASE::ValueType>
{
public:
	using Super = ContainerRefFn<BASE, typename BASE::ValueType>;

	ContainerRefTemplate() = default;

	ContainerRefTemplate(typename BASE::ValueType* value, const typename BASE::ValueType::CType* type, const MemberMap* map)
	{
		this->_ptr._ptr = (Generic*) value;
		this->_ptr._type = type;
		this->_ptr._map = map;
	}

#if defined(MAXON_COMPILER_INTEL) || defined(MAXON_COMPILER_MSVC)
	ContainerRefTemplate(ContainerRefTemplate&& src)
	{
		this->_ptr._ptr = src._ptr._ptr;
		this->_ptr._type = src._ptr._type;
		this->_ptr._map = src._ptr._map;
		src._ptr._ptr = nullptr;
		src._ptr._type = nullptr;
		src._ptr._map = nullptr;
	}

	MAXON_OPERATOR_MOVE_ASSIGNMENT(ContainerRefTemplate);

	ContainerRefTemplate(const ContainerRefTemplate& src)
	{
		static_assert(std::is_same<BASE, TypedContainerPtr<typename BASE::ValueType>>::value, "Can't copy non-ptr ContainerRef.");
		this->_ptr._ptr = src._ptr._ptr;
		this->_ptr._type = src._ptr._type;
		this->_ptr._map = src._ptr._map;
	}

	MAXON_OPERATOR_COPY_ASSIGNMENT(ContainerRefTemplate);
#endif

#if 0
	template <typename B, typename = typename B::ViewMarker> MAXON_IMPLICIT ContainerRefTemplateX(const ContainerRefFn<B, const Container>& src)
	{
		this->_type = src.GetType();
		this->_value = src.GetContainer();
		this->_map = src.GetViewMap();
		this->_ownsValue = false;
	}

	void Set(const typename BASE::ValueType::CType* type, typename BASE::ValueType* value, const MemberMap* map)
	{
		this->_type = type;
		this->_value = value;
		this->_map = map;
		this->_ownsValue = false;
	}

	template <typename B, typename = typename B::ViewMarker> ContainerRefTemplateX& operator =(const ContainerRefFn<B, const Container>& src)
	{
		this->_type = src.GetType();
		this->_value = src.GetContainer();
		this->_map = src.GetViewMap();
		this->_ownsValue = false;
		return *this;
	}
#endif
};

template <typename BASE> class ContainerRefFn<BASE, Container> : public ContainerRefFn<BASE, const Container>
{
#if 0
public:
	template <typename B> Result<void> CopyFrom(const ContainerConstPtr& src, Bool append = false) const
	{
		const ContainerConstPtr& ptr = this->PrivateGet();
		return ptr._type->CopyFrom(ptr._ptr, ptr._map, src, append);
	}
#endif
};

template <typename BASE> class ContainerRefFn<BASE, const ValueContainer> : public ContainerRefFn<BASE, typename Substitute<typename BASE::ValueType, Container>::type>
{
public:
	template <typename T> const T& Get() const
	{
		return *(const T*) this->PrivateGet()._ptr;
	}
};

template <typename BASE> class ContainerRefFn<BASE, ValueContainer> : public ContainerRefFn<BASE, const ValueContainer>
{
public:
	template <typename T> T& Get() const
	{
		return *(T*) this->PrivateGet()._ptr;
	}
};

template <typename BASE> class ContainerRefFn<BASE, const ArrayContainer> : public ContainerRefFn<BASE, typename Substitute<typename BASE::ValueType, Container>::type>
{
public:
	Int GetCount() const
	{
		return this->GetContainerPtr().GetContainer()->GetCount();
	}

	ContainerConstPtr GetMemberElement(Int member, Int index) const
	{
		const auto& ptr = this->GetContainerPtr();
		Int m = ptr.GetMemberMap()->memberToContainer[member];
		const auto* t = ptr.GetType();
		StridedBlock<const Generic> block;
		Int bs = ptr.GetContainer()->GetBlock(t, m, index, block);
		return ContainerConstPtr{&block[index - bs], t->GetMemberTypes()[m], ptr.GetMemberMap()->nested[member]};
	}
};

template <typename BASE> class ContainerRefFn<BASE, ArrayContainer> : public ContainerRefFn<BASE, const ArrayContainer>
{
public:
	ContainerPtr GetMemberElement(Int member, Int index) const
	{
		const auto& ptr = this->GetContainerPtr();
		Int m = ptr.GetMemberMap()->memberToContainer[member];
		const auto* t = ptr.GetType();
		StridedBlock<Generic> block;
		Int bs = ptr.GetContainer()->GetBlock(t, m, index, block);
		return ContainerPtr{&block[index - bs], t->GetMembers()[m].type, this->GetMemberMap()->nested[member]};
	}

	Result<void> Erase(Int index, Int eraseCount = 1) const
	{
		const auto& ptr = this->GetContainerPtr();
		return ptr.GetContainer()->Erase(ptr.GetType(), index, eraseCount);
	}

	Result<void> Resize(Int count, Bool expectMore = false) const
	{
		const auto& ptr = this->GetContainerPtr();
		return ptr.GetContainer()->Resize(ptr.GetType(), count, expectMore);
	}

	Result<void> SetArrayMember(Int member, const Array<Generic>& array) const
	{
		const auto& ptr = this->GetContainerPtr();
		Int m = ptr.GetMemberMap()->memberToContainer[member];
		return ptr.GetContainer()->SetMember(ptr.GetType(), m, array);
	}
#if 0
	Result<void> CopyElementFrom(Int index, const Block<const ContainerConstRefX>& src) const
	{
		return this->GetContainer()->CopyElementFrom(this->GetType(), this->GetViewMap(), index, src);
	}
#endif
};

template <typename BASE> class ContainerRefFn<BASE, const SingletonContainer> : public ContainerRefFn<BASE, typename Substitute<typename BASE::ValueType, Container>::type>
{
public:
	ContainerConstPtr GetMember(Int member) const
	{
		const auto& ptr = this->GetContainerPtr();
		Int m = ptr.GetMemberMap()->memberToContainer[member];
		const auto* t = ptr.GetType();
		return ContainerConstPtr{ptr.GetContainer()->GetMember(t, m), t->GetMemberTypes()[m], ptr.GetMemberMap()->nested[member]};
	}
};

template <typename BASE> class ContainerRefFn<BASE, SingletonContainer> : public ContainerRefFn<BASE, const SingletonContainer>
{
public:
	ContainerPtr GetMember(Int member) const
	{
		const auto& ptr = this->GetContainerPtr();
		Int m = ptr.GetMemberMap()->memberToContainer[member];
		const auto* t = ptr.GetType();
		return ContainerPtr{ptr.GetContainer()->GetMember(t, m), t->GetMembers()[m].type, ptr.GetMemberMap()->nested[member]};
	}
};

template <typename BASE> class ContainerRefFn<BASE, ConcatContainer> : public ContainerRefFn<BASE, Container>
{
public:
	Result<void> Add(const ContainerConstPtr& container) const
	{
		const auto& ptr = this->GetContainerPtr();
		return ptr.GetContainer()->Add(ptr.GetType(), container);
	}
};

template <typename BASE> class ContainerRefFn<BASE, XformContainer> : public ContainerRefFn<BASE, Container>
{
public:
	void SetInput(Int index, const ContainerConstPtr& container) const
	{
		const auto& ptr = this->GetContainerPtr();
		DebugAssert(ptr.GetType()->GetMembers()[index].type->IsBaseOfOrSame(container._type, container._map));
		return ptr.GetContainer()->SetInput(index, container);
	}
};

#endif

#include "listview1.hxx"

#include "listview2.hxx"

template <GET_DATATYPE_POLICY POLICY> inline ResultOk<const DataType*> PrivateGetDataType(ListView*, OverloadRank0)
{
	return ListViewType::GetGenericAbstract();
}

} // namespace maxon

#if 0
namespace std
{
template <> struct is_base_of<maxon::Container, maxon::Generic> : public std::false_type { };
}
#endif

#endif // LISTVIEW_H__
