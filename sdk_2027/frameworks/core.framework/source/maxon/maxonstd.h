#ifndef MAXONSTD_H__
#define MAXONSTD_H__

#include "maxon/basearray.h"
#include "maxon/hashmap.h"
#include "maxon/errorbase.h"

// stylecheck.naming=false

//----------------------------------------------------------------------------------------
/// This namespace contains std-compatible replacements for C++ standard library containers which
/// are based on the corresponding containers of Maxon core library.
//----------------------------------------------------------------------------------------
namespace maxonstd
{

struct ErrorHandlerMarker
{
};

template <typename T> decltype(auto) operator %(T&& result, ErrorHandlerMarker)
{
	maxon::ThreadReferencedError err;
	using ReturnType = decltype(std::forward<T>(result) % err);
	if constexpr (std::is_void_v<ReturnType>)
	{
		std::forward<T>(result) % err;
		if (err.GetReferencedError())
		{
			// TODO: (Ole) Here we should throw an exception if exceptions are enabled.
			DebugStop();
		}
		return;
	}
	else
	{
		ReturnType value = std::forward<T>(result) % err;
		if (err.GetReferencedError())
		{
			DebugStop();
		}
		return value;
	}
}

#define maxonstd_iferr_throw % maxonstd::ErrorHandlerMarker{}

// Base class which adapts common functions, there's no need to use this class directly.
template <typename COLLECTION> class container : public COLLECTION
{
public:
	container() = default;
	container(container&&) = default;
	container& operator =(container&&) = default;
	using COLLECTION::COLLECTION;

	container(const container& src)
	{
		COLLECTION::CopyFrom(src) maxonstd_iferr_throw;
	}

	container& operator =(const container& src)
	{
		COLLECTION::CopyFrom(src) maxonstd_iferr_throw;
		return *this;
	}

	maxon::Result<void> CopyFrom(const container&) = delete;

	using iterator = typename COLLECTION::Iterator;
	using const_iterator = typename COLLECTION::ConstIterator;

	using reverse_iterator = maxon::ReverseIterator<iterator>;
	using const_reverse_iterator = maxon::ReverseIterator<const_iterator>;

	auto begin() { return COLLECTION::Begin(); }
	auto end() { return COLLECTION::End(); }
	auto begin() const { return COLLECTION::Begin(); }
	auto end() const { return COLLECTION::End(); }
	auto cbegin() const { return COLLECTION::Begin(); }
	auto cend() const { return COLLECTION::End(); }

	reverse_iterator rbegin() { return reverse_iterator{COLLECTION::End()}; }
	reverse_iterator rend() { return reverse_iterator{COLLECTION::Begin()}; }
	const_reverse_iterator rbegin() const { return const_reverse_iterator{COLLECTION::End()}; }
	const_reverse_iterator rend() const { return const_reverse_iterator{COLLECTION::Begin()}; }
	const_reverse_iterator rcbegin() const { return const_reverse_iterator{COLLECTION::End()}; }
	const_reverse_iterator rcend() const { return const_reverse_iterator{COLLECTION::Begin()}; }

	void clear() { COLLECTION::Flush(); }

	bool empty() const { return COLLECTION::IsEmpty(); }
	std::size_t size() const { return COLLECTION::GetCount(); }
};

//----------------------------------------------------------------------------------------
/// maxonstd::vector adapts a Maxon core array to look like a std::vector, so that it can be used as a substitute thereof.
/// By default, it uses an underlying BaseArray with default settings, but you can choose any of the array implementations of Maxon core
/// via the SELECTOR template parameter.
///
/// @tparam T											Type of elements.
/// @tparam SELECTOR							To choose a BaseArray with non-default template parameters, or a different array implementation such as BlockArray,
///																you have to provide an array selector with the desired configuration.
/// @see BaseArray
//----------------------------------------------------------------------------------------
template <typename T, typename SELECTOR = maxon::BaseArraySelector<>> class vector : public container<typename SELECTOR::template Type<T>>
{
public:
	using Array = typename SELECTOR::template Type<T>;
	using Super = container<Array>;
	using typename Super::iterator;
	using typename Super::const_iterator;

	using value_type = T;
	using reference = T&;
	using const_reference = const T&;
	using size_type = std::size_t;
	using difference_type = std::ptrdiff_t;

	using Super::Super;

	vector() = default;

	explicit vector(size_type count)
	{
		resize(count);
	}

	vector(size_type count, const T& value)
	{
		this->Resize(count, maxon::COLLECTION_RESIZE_FLAGS::ON_GROW_UNINITIALIZED) maxonstd_iferr_throw;
		for (T& t : *this)
		{
			iferr (maxon::NewCopy(t, value))
			{
				new (&t) T();
			}
		}
	}

	MAXON_IMPLICIT vector(const std::initializer_list<T>& init)
	{
		this->Append(init) maxonstd_iferr_throw;
	}

	T* data()
	{
		static_assert(Array::IsBaseArray::value, "data() can only be used for BaseArray.");
		return this->GetFirst();
	}

	const T* data() const
	{
		static_assert(Array::IsBaseArray::value, "data() can only be used for BaseArray.");
		return this->GetFirst();
	}

	T& front()
	{
		return (*this)[0];
	}

	const T& front() const
	{
		return (*this)[0];
	}

	T& back()
	{
		return *(this->End() - 1);
	}

	const T& back() const
	{
		return *(this->End() - 1);
	}

	T& at(size_type index)
	{
		return (*this)[index];
	}

	const T& at(size_type index) const
	{
		return (*this)[index];
	}

	void shrink_to_fit()
	{
		this->Resize(this->GetCount(), maxon::COLLECTION_RESIZE_FLAGS::ON_SHRINK_FIT_TO_SIZE);
	}

	void resize(size_type count)
	{
		this->Resize(count);
	}

	void resize(size_type count, const T& value)
	{
		const size_type prevCnt = this->size();
		this->Resize(count, maxon::COLLECTION_RESIZE_FLAGS::ON_GROW_UNINITIALIZED) maxonstd_iferr_throw;
		if (count > prevCnt)
		{
			for (iterator it = this->begin() + prevCnt, end = this->end(); it != end; ++it)
			{
				iferr (maxon::NewCopy(*it, value))
				{
					new (&*it) T();
				}
			}
		}
	}

	void reserve(size_type capacity)
	{
		this->EnsureCapacity(capacity);
	}

	size_type capacity() const
	{
		return this->GetCapacityCount();
	}

	void push_back(const T& value)
	{
		this->Append(value) maxonstd_iferr_throw;
	}

	void push_back(T&& value)
	{
		this->Append(std::move(value)) maxonstd_iferr_throw;
	}

	template <typename... ARGS> T& emplace_back(ARGS&&... args)
	{
		return this->Append(std::forward<ARGS>(args)...) maxonstd_iferr_throw;
	}

	void pop_back()
	{
		this->Pop();
	}

	iterator insert(const iterator& pos, const T& value)
	{
		return this->Insert(pos, value) maxonstd_iferr_throw;
	}

	iterator insert(const iterator& pos, T&& value)
	{
		return this->Insert(pos, std::move(value)) maxonstd_iferr_throw;
	}

	template <typename IT> iterator insert(const iterator& pos, IT&& first, IT&& last)
	{
		if constexpr (std::is_void_v<decltype(IsBaseIterator(&first))>)
		{
			if constexpr ((sizeof(std::decay_t<IT>) == sizeof(void*)) && std::is_same_v<const typename std::decay_t<IT>::ValueType, const T>)
			{
				return this->InsertBlock(pos, maxon::ToBlock(first.GetPtr(), last - first)) maxonstd_iferr_throw;
			}
			else
			{
				iterator result = this->InsertBlock(pos, maxon::ToBlock<const T>(nullptr, last - first)) maxonstd_iferr_throw;
				iterator dst = result;
				for (std::decay_t<IT> src = first; src != last; ++src, ++dst)
				{
					iferr (maxon::NewCopy(*dst, *src))
					{
						new (&*dst) T();
					}
				}
				return result;
			}
		}
		else
		{
			// TODO: (Ole) Handle iterators which don't support "last - first".
			iterator result = this->InsertBlock(pos, maxon::ToBlock<const T>(nullptr, last - first)) maxonstd_iferr_throw;
			iterator dst = result;
			for (std::decay_t<IT> src = first; src != last; ++src, ++dst)
			{
				iferr (maxon::NewCopy(*dst, *src))
				{
					new (&*dst) T();
				}
			}
			return result;
		}
	}

	iterator insert(const const_iterator& pos, const T& value)
	{
		return insert(reinterpret_cast<const iterator&>(pos), value);
	}

	iterator insert(const const_iterator& pos, T&& value)
	{
		return insert(reinterpret_cast<const iterator&>(pos), std::move(value));
	}

	template <typename IT> iterator insert(const const_iterator& pos, IT&& first, IT&& last)
	{
		return insert<IT>(reinterpret_cast<const iterator&>(pos), std::forward<IT>(first), std::forward<IT>(last));
	}

	iterator erase(const iterator& pos)
	{
		return this->Erase(pos);
	}

	iterator erase(const iterator& first, const iterator& last)
	{
		return this->Erase(first, last - first);
	}

	iterator erase(const const_iterator& pos)
	{
		return erase(reinterpret_cast<const iterator&>(pos));
	}

	iterator erase(const const_iterator& first, const const_iterator& last)
	{
		return erase(reinterpret_cast<const iterator&>(first), reinterpret_cast<const iterator&>(last));
	}

private:
	static bool IsBaseIterator(const void*);
	template <typename C, maxon::Bool STRIDED> static void IsBaseIterator(const maxon::BaseIterator<C, STRIDED>*);
};

// Base class for unordered_map and unordered_set, there's no need to use this class directly.
template <typename MAP, bool FIND_RETURNS_ITERATOR> class unordered_map_base : public container<MAP>
{
public:
	using Super = container<MAP>;
	using typename Super::iterator;
	using typename Super::const_iterator;
	using typename Super::Entry;
	using typename Super::KeyType;

	using value_type = Entry;

	using Super::Super;

	// An EntryWrapper is used instead of an iterator when FIND_RETURNS_ITERATOR is false.
	// This is more efficient (just a pointer), but it can't iterate.
	template <bool CONSTITERATOR> class EntryWrapper
	{
	public:
		using iterator_type = std::conditional_t<CONSTITERATOR, const_iterator, iterator>;
		using entry_type = typename maxon::ConstIf<Entry, CONSTITERATOR>::type;

		explicit EntryWrapper(entry_type* e) : _entry(e)
		{
		}

		entry_type& operator *() const
		{
			return *_entry;
		}

		entry_type* operator ->() const
		{
			return _entry;
		}

		friend bool operator ==(const EntryWrapper& w, const iterator_type& i)
		{
			return w._entry ? (w._entry == i.operator ->()) : !i;
		}

		friend bool operator !=(const EntryWrapper& w, const iterator_type& i)
		{
			return !(w == i);
		}

		friend bool operator ==(const iterator_type& i, const EntryWrapper& w)
		{
			return w == i;
		}

		friend bool operator !=(const iterator_type& i, const EntryWrapper& w)
		{
			return !(w == i);
		}

		explicit operator bool() const
		{
			return _entry != nullptr;
		}

	private:
		entry_type* const _entry;
	};

	using FindResult = std::conditional_t<FIND_RETURNS_ITERATOR, iterator, EntryWrapper<false>>;
	using ConstFindResult = std::conditional_t<FIND_RETURNS_ITERATOR, const_iterator, EntryWrapper<true>>;

	ConstFindResult find(const KeyType& key) const
	{
		return ToFindResult(this->Find(key));
	}

	FindResult find(const KeyType& key)
	{
		return ToFindResult(this->Find(key));
	}

	iterator erase(const iterator& it)
	{
		return this->Erase(it);
	}

	void erase(const EntryWrapper<false>& e)
	{
		this->Erase(*e);
	}

protected:
	MAXON_ATTRIBUTE_FORCE_INLINE FindResult ToFindResult(Entry* e)
	{
		if constexpr (FIND_RETURNS_ITERATOR)
			return this->GetIterator(e);
		else
			return EntryWrapper<false>{e};
	}

	MAXON_ATTRIBUTE_FORCE_INLINE ConstFindResult ToFindResult(const Entry* e) const
	{
		if constexpr (FIND_RETURNS_ITERATOR)
			return this->GetIterator(e);
		else
			return EntryWrapper<true>{e};
	}
};

//----------------------------------------------------------------------------------------
/// maxonstd::unordered_map adapts a Maxon core HashMap to look like a std::unordered_map, so that it can be used as a substitute thereof.
/// To change the settings of the underlying HashMap, you have to provide a HashMapSelector or BlockHashMapSelector
/// via the SELECTOR template parameter.
///
/// FIND_RETURNS_ITERATOR controls the return type of the find functions. With the default of true, these functions return an iterator
/// to be compatible with std::unordered_map. However, for an unordered map you almost never need the iterator capability of find's return value,
/// because usually it makes no sense to proceed from there (an unordered map has unspecified order, neighboring elements have no relationship).
/// You only need the iterator comparison function to detect if find was successful at all:
/// @code
/// maxonstd::unordered_map<void*, String> map;
/// ...
/// maxonstd::unordered_map<void*, String>::iterator it = map.find(ptr);
/// if (it != map.end())
/// {
///   // map contains entry for ptr
/// }
/// @endcode
/// You can use false for FIND_RETURNS_ITERATOR which makes the find functions return a more lightweight wrapper around HashMap::Entry
/// without iterator capabilities. It can still be compared to an iterator, so the above code remains valid if you adapt it to the new type:
/// @code
/// maxonstd::unordered_map<void*, String, false> map;
/// ...
/// auto it = map.find(ptr); // return type is no longer an iterator
/// if (it != map.end())     // but it can be compared with an iterator
/// {
///   // map contains entry for ptr
/// }
/// @endcode
/// But there's a conversion to Bool, so you can directly test for validity without the need of `map.end()`:
/// @code
/// maxonstd::unordered_map<void*, String, false> map;
/// ...
/// auto it = map.find(ptr);
/// if (it) // the returned entry wrapper has a conversion to Bool to tell if an entry was found
/// {
///   // map contains entry for ptr
/// }
/// @endcode
///
/// Note that maxonstd::unordered_map doesn't support std::unordered_map's additional template parameters for hash, comparison and allocator directly.
/// However, you can achieve the same effect with corresponding template parameters of the HashMapSelector.
///
/// @tparam K											Type of keys.
/// @tparam V											Type of values.
/// @tparam FIND_RETURNS_ITERATOR	By default (true), the find functions return an iterator compatible with std library. With false, a more efficient wrapper around HashMap::Entry is returned without iterator capabilities.
/// @tparam SELECTOR							To choose a HashMap with non-default template parameters, you have to provide a HashMapSelector with the desired configuration.
/// @see HashMap, BlockHashMap
//----------------------------------------------------------------------------------------
template <typename K, typename V, bool FIND_RETURNS_ITERATOR = true, typename SELECTOR = maxon::HashMapSelector<>> class unordered_map : public unordered_map_base<typename SELECTOR::template Type<K, V>, FIND_RETURNS_ITERATOR>
{
public:
	using Super = unordered_map_base<typename SELECTOR::template Type<K, V>, FIND_RETURNS_ITERATOR>;
	using typename Super::FindResult;
	using typename Super::Entry;
	using value_type = Entry;

	using Super::Super;

	std::pair<FindResult, bool> insert(const std::pair<const K, V>& value)
	{
		return insert_pair(value);
	}

	std::pair<FindResult, bool> insert(std::pair<const K, V>&& value)
	{
		return insert_pair(std::move(value));
	}

	template <typename PAIR> std::pair<FindResult, bool> insert(PAIR&& value)
	{
		return insert_pair(std::forward<PAIR>(value));
	}

	V& operator [](const K& key)
	{
		return this->InsertKey(key) maxonstd_iferr_throw;
	}

private:
	template <typename PAIR> std::pair<FindResult, bool> insert_pair(PAIR&& value)
	{
		using KEY = typename maxon::Substitute<PAIR, std::remove_const_t<decltype(value.first)>>::type;
		using VALUE = typename maxon::Substitute<PAIR, decltype(value.second)>::type;
		bool created = false;
		// Use InsertCtor instead of Insert because maxon Insert overwrites value when entry already exists, while std insert doesn't.
		Entry* e = this->template InsertCtor<typename Super::HashType, KEY>(std::forward<KEY>(value.first), *(typename Entry::EntryHandler::template KeyValueConstructor<Entry, KEY, VALUE>*) & value.second, created) maxonstd_iferr_throw;
		return {this->ToFindResult(e), created};
	}
};

//----------------------------------------------------------------------------------------
/// maxonstd::unordered_set adapts a Maxon core HashSet to look like a std::unordered_set, so that it can be used as a substitute thereof.
/// To change the settings of the underlying HashSet, you have to provide a HashSetSelector or BlockHashSetSelector
/// via the SELECTOR template parameter.
///
/// FIND_RETURNS_ITERATOR controls the return type of the find functions. With the default of true, these functions return an iterator
/// to be compatible with std::unordered_set. However, for an unordered set you almost never need the iterator capability of find's return value,
/// because usually it makes no sense to proceed from there (an unordered set has unspecified order, neighboring elements have no relationship).
/// You only need the iterator comparison function to detect if find was successful at all:
/// @code
/// maxonstd::unordered_set<String> set;
/// ...
/// maxonstd::unordered_set<String>::iterator it = set.find(s);
/// if (it != set.end())
/// {
///   // set contains entry for s
/// }
/// @endcode
/// You can use false for FIND_RETURNS_ITERATOR which makes the find functions return a more lightweight wrapper around HashSet::Entry
/// without iterator capabilities. It can still be compared to an iterator, so the above code remains valid if you adapt it to the new type:
/// @code
/// maxonstd::unordered_set<String, false> set;
/// ...
/// auto it = set.find(s); // return type is no longer an iterator
/// if (it != set.end())   // but it can be compared with an iterator
/// {
///   // set contains entry for s
/// }
/// @endcode
/// But there's a conversion to Bool, so you can directly test for validity without the need of `set.end()`:
/// @code
/// maxonstd::unordered_set<String, false> set;
/// ...
/// auto it = set.find(s);
/// if (it) // the returned entry wrapper has a conversion to Bool to tell if an entry was found
/// {
///   // set contains entry for s
/// }
/// @endcode
///
/// Note that maxonstd::unordered_set doesn't support std::unordered_set's additional template parameters for hash, comparison and allocator directly.
/// However, you can achieve the same effect with corresponding template parameters of the HashSetSelector.
///
/// @tparam T											Type of values.
/// @tparam FIND_RETURNS_ITERATOR	By default (true), the find functions return an iterator compatible with std library. With false, a more efficient wrapper around HashSet::Entry is returned without iterator capabilities.
/// @tparam SELECTOR							To choose a HashSet with non-default template parameters, you have to provide a HashSetSelector with the desired configuration.
/// @see HashSet, BlockHashSet
//----------------------------------------------------------------------------------------
template <typename T, bool FIND_RETURNS_ITERATOR = true, typename SELECTOR = maxon::HashSetSelector<>> class unordered_set : public unordered_map_base<typename SELECTOR::template Type<T>, FIND_RETURNS_ITERATOR>
{
public:
	using Super = unordered_map_base<typename SELECTOR::template Type<T>, FIND_RETURNS_ITERATOR>;
	using typename Super::FindResult;
	using typename Super::Entry;

	using Super::Super;

	std::pair<FindResult, bool> insert(const T& value)
	{
		Bool created = false;
		Entry& e = this->Insert(value, created) maxonstd_iferr_throw;
		return {this->ToFindResult(&e), created};
	}

	std::pair<FindResult, bool> insert(T&& value)
	{
		Bool created = false;
		Entry& e = this->Insert(std::move(value), created) maxonstd_iferr_throw;
		return {this->ToFindResult(&e), created};
	}

	using Super::erase;

	size_t erase(const T& key)
	{
		return this->Erase(key).GetValue();
	}
};

}

#endif
