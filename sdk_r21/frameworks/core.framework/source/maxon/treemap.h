#ifndef TREEMAP_H__
#define TREEMAP_H__

#include "maxon/hashmap.h"
#include "maxon/basearray.h"
#include "maxon/string.h"
#include "maxon/indexiterator.h"
#include "maxon/optional.h"

namespace maxon
{


template <typename PARENT, Bool COW> class TreeMapParent
{
public:
	const PARENT* GetParent() const
	{
		return _parent;
	}

	PARENT* GetParent()
	{
		return _parent;
	}

protected:
	void SetParent(PARENT* p)
	{
		_parent = p;
	}

	Pointer<PARENT> _parent; // we use Pointer for default initialization and move semantics
};

template <typename PARENT> class TreeMapParent<PARENT, true>
{
protected:
	void SetParent(PARENT* p) const
	{
		// the COW case doesn't allow parent pointers
	}
};

template <typename K, typename V, typename MAP = HashMapSelector<>, Bool COW = false> class TreeMap : public TreeMapParent<TreeMap<K, V, MAP, COW>, COW>
{
public:
	using KeyType = K;
	using ValueType = V;
	using Super = TreeMapParent<TreeMap<K, V, MAP, COW>, COW>;
	using Child = typename std::conditional<COW, StrongCOWRef<TreeMap>, TreeMap>::type;
	using Ref = typename std::conditional<COW, StrongCOWRef<TreeMap>, void>::type;
	using ChildrenMap = typename MAP::template Type<K, Child>;

	TreeMap() = default;

	TreeMap(TreeMap&& src) : Super(std::move(src)), MAXON_MOVE_MEMBERS(_value, _children)
	{
		for (TreeMap& c : _children.GetValues())
			c.SetParent(this);
	}

	MAXON_OPERATOR_MOVE_ASSIGNMENT(TreeMap);

	Result<void> CopyFrom(const TreeMap& src)
	{
		iferr_scope;
		this->SetParent(nullptr);
		AssignCopy(_value, src._value) iferr_return;
		_children.CopyFrom(src._children) iferr_return;
		if (!COW)
		{
			for (const Child& c : _children.GetValues())
				c->SetParent(this);
		}
		return OK;
	}

	void Flush()
	{
		_value = NO_VALUE;
		_children.Flush();
	}

	void Reset()
	{
		_value = NO_VALUE;
		_children.Reset();
	}

	Result<TreeMap&> InsertChild(const K& key, Bool withValue = true)
	{
		iferr_scope;
		Child& e = _children.InsertKey(key) iferr_return;
		e.SetParent(this);
		if (withValue && !e._value)
			e._value = V();
		return e;
	}

	static ResultRef<TreeMap> MakeWritable(StrongCOWRef<TreeMap>& ref)
	{
		return ref.MakeWritable();
	}

	static ResultOk<TreeMap&> MakeWritable(TreeMap& ref)
	{
		return ref;
	}

	template <typename PATH, typename = typename std::enable_if<!std::is_base_of<K, typename std::decay<PATH>::type>::value>::type> Result<TreeMap&> InsertEntry(PATH&& key, Bool withValue = true)
	{
		iferr_scope;
		TreeMap* e = this;
		for (const K& i : key)
		{
			Child& child = e->_children.InsertKey(i) iferr_return;
			TreeMap& c = MakeWritable(child) iferr_return;
			c.SetParent(e);
			e = &c;
		}
		if (withValue && !e->_value)
			e->_value = V();
		return *e;
	}

	template <typename PATH, typename = typename std::enable_if<!std::is_base_of<K, typename std::decay<PATH>::type>::value>::type> Result<TreeMap&> Insert(PATH&& key, const V& value)
	{
		iferr_scope;
		TreeMap& e = InsertEntry<PATH>(std::forward<PATH>(key), true) iferr_return;
		AssignCopy(*e._value, value) iferr_return;
		return e;
	}

	template <typename PATH, typename = typename std::enable_if<!std::is_base_of<K, typename std::decay<PATH>::type>::value>::type> Result<TreeMap&> Insert(PATH&& key, V&& value)
	{
		iferr_scope;
		TreeMap& e = InsertEntry<PATH>(std::forward<PATH>(key), false) iferr_return;
		e._value = std::move(value);
		return e;
	}

	template <typename PATH> Result<V&> InsertKey(PATH&& key, Bool& created = BoolLValue())
	{
		iferr_scope;
		TreeMap& e = InsertEntry<PATH>(std::forward<PATH>(key), false) iferr_return;
		if (e._value)
		{
			created = false;
		}
		else
		{
			e._value = V();
			created = true;
		}
		return *e._value;
	}

	static const TreeMap* GetTreeMap(const TreeMap* child)
	{
		return child;
	}

	static const TreeMap* GetTreeMap(const StrongCOWRef<TreeMap>* child)
	{
		return child ? child->GetPointer() : nullptr;
	}

	const TreeMap* FindChild(const K& key) const
	{
		return GetTreeMap(_children.FindValue(key));
	}

	TreeMap* FindChild(const K& key)
	{
		return MAXON_NONCONST_COUNTERPART(FindChild(key));
	}

	template <typename PATH> const TreeMap* FindEntry(PATH&& key) const
	{
		const TreeMap* e = this;
		for (const K& i : key)
		{
			e = GetTreeMap(e->_children.FindValue(i));
			if (!e)
				return nullptr;
		}
		return e;
	}

	template <typename PATH, typename = typename std::enable_if<!COW || AlwaysFalse<PATH>::value>::type> TreeMap* FindEntry(PATH&& key)
	{
		return MAXON_NONCONST_COUNTERPART(template FindEntry<PATH>(std::forward<PATH>(key)));
	}

	template <typename PATH> const TreeMap* FindFirstEntryWithValue(PATH&& key) const
	{
		if (_value)
			return this;
		const TreeMap* e = this;
		for (const K& i : key)
		{
			e = e->_children.FindValue(i);
			if (!e)
				return nullptr;
			if (e->_value)
				return e;
		}
		return nullptr;
	}

	template <typename PATH> const TreeMap* FindClosestEntryWithValue(PATH&& key) const
	{
		const TreeMap* result = nullptr;
		const TreeMap* e = this;
		if (e->_value)
			result = e;
		for (const K& i : key)
		{
			e = e->_children.FindValue(i);
			if (!e)
				break;
			if (e->_value)
				result = e;
		}
		return result;
	}

	template <typename PATH> const V* FindValue(PATH&& key) const
	{
		const TreeMap* e = FindEntry<PATH>(std::forward<PATH>(key));
		return (e && e->_value) ? &*e->_value : nullptr;
	}

	template <typename PATH, typename = typename std::enable_if<!COW || AlwaysFalse<PATH>::value>::type> V* FindValue(PATH&& key)
	{
		return MAXON_NONCONST_COUNTERPART(template FindValue<PATH>(std::forward<PATH>(key)));
	}

	template <typename PATH> Bool Contains(PATH&& key) const
	{
		const TreeMap* e = FindEntry<PATH>(std::forward<PATH>(key));
		return e && e->_value;
	}

	template <typename PATH> typename std::conditional<COW, Result<void>, ResultOk<void>>::type Erase(PATH&& key)
	{
		auto beginIt = begin(key);
		auto endIt = end(key);
		return EraseImpl(beginIt, endIt);
	}

	String ToString(const FormatStatement* fs) const
	{
		String s;
		BufferedBaseArray<K, 10> path;
		ToStringImpl(s, path, fs);
		s.AppendChar('}') iferr_ignore("Ignore errors for ToString");
		return "{"_s + s;
	}

	const Opt<V>& Get() const
	{
		return _value;
	}

	Opt<V>& Get()
	{
		return _value;
	}

	V& MakeValid()
	{
		if (!_value)
			_value = V();
		return *_value;
	}

	void SetValue(const V& value)
	{
		_value = value;
	}

	void SetValue(V&& value)
	{
		_value = std::move(value);
	}

	Bool IsRoot() const
	{
		return this->_parent == nullptr;
	}

	Bool IsLeaf() const
	{
		return _children.IsEmpty();
	}

	const ChildrenMap& GetChildren() const
	{
		return _children;
	}

	ChildrenMap& GetChildren()
	{
		return _children;
	}

	const K* GetKey() const
	{
		return this->_parent ? &ChildrenMap::Entry::Get(this)->GetKey() : nullptr;
	}

	Bool operator ==(const TreeMap& other) const
	{
		return _value == other._value && _children == other._children;
	}

	Bool operator !=(const TreeMap& other) const
	{
		return !this->operator ==(other);
	}

	Bool IsPopulated() const
	{
		return _value || _children.IsPopulated();
	}

	Bool IsEmpty() const
	{
		return !IsPopulated();
	}

	Bool HasSameStructure(const TreeMap& other) const
	{
		if (_children.GetCount() != other._children.GetCount())
			return false;
		for (const auto& c : _children)
		{
			const TreeMap* oc = other._children.FindValue(c.GetKey());
			if (!oc || !c.GetValue().HasSameStructure(*oc))
				return false;
		}
		return true;
	}

	template <typename OP> Result<Bool> ForEachPreOrder(OP&& callback) const
	{
		yield_scope;
		std::forward<OP>(callback)(*this) yield_return;
		for (const auto& c : _children)
		{
			c.GetValue().ForEachPreOrder(std::forward<OP>(callback)) yield_return;
		}
		return true;
	}

	template <typename PATH, typename OP> Result<Bool> ForEachPreOrder(OP&& callback, PATH&& path = PATH()) const
	{
		yield_scope;
		iferr_scope;
		std::forward<OP>(callback)(*this, path) yield_return;
		for (const auto& c : _children)
		{
			path.Append(c.GetKey()) iferr_return;
			finally
			{
				path.Pop();
			};
			c.GetValue().template ForEachPreOrder<PATH, OP>(std::forward<OP>(callback), std::forward<PATH>(path)) yield_return;
		}
		return true;
	}

	template <typename OP> Result<Bool> ForEachPreOrder(OP&& callback)
	{
		yield_scope;
		std::forward<OP>(callback)(*this) yield_return;
		for (auto& c : _children)
		{
			c.GetValue().ForEachPreOrder(std::forward<OP>(callback)) yield_return;
		}
		return true;
	}

	template <typename PATH, typename OP> Result<Bool> ForEachPreOrder(OP&& callback, PATH&& path = PATH())
	{
		yield_scope;
		iferr_scope;
		std::forward<OP>(callback)(*this, path) yield_return;
		for (auto& c : _children)
		{
			path.Append(c.GetKey()) iferr_return;
			finally
			{
				path.Pop();
			};
			c.GetValue().template ForEachPreOrder<PATH, OP>(std::forward<OP>(callback), std::forward<PATH>(path)) yield_return;
		}
		return true;
	}

	template <typename PATH, typename OP> Result<void> ForEachPreOrderX(OP&& callback, PATH&& path = PATH())
	{
		iferr_scope;
		Bool enter = std::forward<OP>(callback)(*this, path) iferr_return;
		if (enter)
		{
			for (auto& c : _children)
			{
				path.Append(c.GetKey()) iferr_return;
				finally
				{
					path.Pop();
				};
				c.GetValue().template ForEachPreOrderX<PATH, OP>(std::forward<OP>(callback), std::forward<PATH>(path)) iferr_return;
			}
		}
		return OK;
	}

	template <typename OP> Result<Bool> ForEachPostOrder(OP&& callback) const
	{
		yield_scope;
		for (const auto& c : _children)
		{
			c.GetValue().ForEachPostOrder(std::forward<OP>(callback)) yield_return;
		}
		std::forward<OP>(callback)(*this) yield_return;
		return true;
	}

	template <typename PATH, typename OP> Result<Bool> ForEachPostOrder(OP&& callback, PATH&& path = PATH()) const
	{
		yield_scope;
		iferr_scope;
		for (const auto& c : _children)
		{
			path.Append(c.GetKey()) iferr_return;
			finally
			{
				path.Pop();
			};
			c.GetValue().template ForEachPostOrder<PATH, OP>(std::forward<OP>(callback), std::forward<PATH>(path)) yield_return;
		}
		std::forward<OP>(callback)(*this, path) yield_return;
		return true;
	}

	template <typename OP> Result<Bool> ForEachPostOrder(OP&& callback)
	{
		yield_scope;
		for (auto& c : _children)
		{
			c.GetValue().ForEachPostOrder(std::forward<OP>(callback)) yield_return;
		}
		std::forward<OP>(callback)(*this) yield_return;
		return true;
	}

	template <typename PATH, typename OP> Result<Bool> ForEachPostOrder(OP&& callback, PATH&& path = PATH())
	{
		iferr_scope;
		yield_scope;
		for (auto& c : _children)
		{
			path.Append(c.GetKey()) iferr_return;
			finally
			{
				path.Pop();
			};
			c.GetValue().template ForEachPostOrder<PATH, OP>(std::forward<OP>(callback), std::forward<PATH>(path)) yield_return;
		}
		std::forward<OP>(callback)(*this, path) yield_return;
		return true;
	}

	template <typename PATH> Result<void> GetPath(PATH& path) const
	{
		iferr_scope;
		const TreeMap* t = this;
		while (t)
		{
			if (t->GetKey())
			{
				path.Insert(0, *t->GetKey()) iferr_return;
			}
			t = t->_parent;
		}
		return OK;
	}

	Int GetDepth() const
	{
		Int depth = 0;
		const TreeMap* t = this;
		while (true)
		{
			t = t->_parent;
			if (!t)
				return depth;
			++depth;
		}
	}

	IndexIterator<const K&, const TreeMap, TreeMap> GetPath() const
	{
		return {*this, -GetDepth(), 0};
	}

	static const K& Get(const TreeMap& map, Int index)
	{
		const TreeMap* t = &map;
		while (++index < 0)
		{
			t = t->_parent;
		}
		DebugAssert(t->_parent);
		return *t->GetKey();
	}

private:
	void ToStringImpl(String& s, BufferedBaseArray<K, 10>& path, const FormatStatement* fs) const
	{
		if (_value)
		{
			if (s.IsPopulated())
				s.AppendChar(',') iferr_ignore("Ignore errors for ToString");
			s += path.ToString(fs);
			s += "->"_s;
			s += GlobalToString(*_value, fs);
		}
		for (const auto& c : _children)
		{
			path.Append(c.GetKey()) iferr_ignore("Ignore errors for ToString");
			GetTreeMap(&c.GetValue())->ToStringImpl(s, path, fs);
			path.Pop();
		}
	}

#define iferr_scope_t(...) PRIVATE_MAXON_iferr_scope(typename maxon::details::TmpErrType<MAXON_MACROARG_TYPE(__VA_ARGS__)>::type)

	template <typename IT> typename std::conditional<COW, Result<Bool>, ResultOk<Bool>>::type EraseImpl(IT& beginIt, const IT& endIt)
	{
		iferr_scope_t(typename std::conditional<COW, Result<Bool>, ResultOk<Bool>>::type);
		if (beginIt == endIt)
		{
			_value = NO_VALUE;
			return _children.IsEmpty();
		}
		else
		{
			auto e = _children.Find(*beginIt);
			if (e)
			{
				TreeMap& t = MakeWritable(e->GetValue()) iferr_return;
				Bool childNotNeeded = t.EraseImpl(++beginIt, endIt) iferr_return;
				if (childNotNeeded)
				{
					_children.Erase(e);
					return !_value && _children.IsEmpty();
				}
			}
		}
		return false;
	}

	Opt<V> _value;
	ChildrenMap _children;
};

}

#endif // TREEMAP_H__
