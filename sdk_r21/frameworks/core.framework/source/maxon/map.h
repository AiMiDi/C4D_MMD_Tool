#ifndef MAP_H__
#define MAP_H__

#include "maxon/string.h"
#include "maxon/datatype.h"

namespace maxon
{

template <typename K, typename V> class NonConstMap;


//----------------------------------------------------------------------------------------
/// MapInterface is an interface which provides the usual map functions as virtual methods.
/// Each standard map of the MAXON API can be represented as such an interface, so this
/// allows to write non-template functions which nevertheless are able to deal with any kind
/// of map.
///
/// If the function won't modify both the structure and values of the map, you
/// should use a @c const MapInterface with @c const values:
/// @code
/// void Func(const MapInterface<Int, const String>& map);
///
/// HashMap<Int, String> myMap;
/// Func(myMap); // OK
/// ArrayMap<Int, String> myMap2;
/// Func(myMap2); // OK
/// @endcode
/// The access to the set happens via virtual methods, so there is an inevitable performance
/// penalty, but this will be negligible for most use cases.
///
/// For a map which shall be modified, use WritableMapInterface as type of the function parameter instead.
///
/// @tparam K											Type of keys of the map.
/// @tparam V											Type of values of the map.
//----------------------------------------------------------------------------------------
template <typename K, typename V> class MapInterface : public MapBase0<MapInterface<K, V>, K, V, EmptyClass, DefaultCompare>
{
# ifdef CPP_853_HACK // use space after # so that the source processor doesn't recognize those directives
	CPP_853_HACK_MAXON_INTERFACE_SIMPLE_VIRTUAL(MapInterface, MAXON_REFERENCE_COPY_ON_WRITE);
# else
	MAXON_INTERFACE_SIMPLE_VIRTUAL(MapInterface, MAXON_REFERENCE_COPY_ON_WRITE);
# endif

public:
	using KeyType = K;
	using ValueType = V;

	template <Bool CONSTITERATOR> class IteratorTemplate;
	using Iterator = IteratorTemplate<false>;
	using ConstIterator = IteratorTemplate<true>;

	//----------------------------------------------------------------------------------------
	/// Gets the number of map entries.
	/// @return												Number of map entries.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Int GetCount() const;

	/// @MAXON_ANNOTATION{default=true}
	MAXON_FUNCTION Bool IsEmpty() const
	{
		return GetCount() == 0;
	}

	MAXON_FUNCTION Bool IsPopulated() const
	{
		return GetCount() != 0;
	}

	//----------------------------------------------------------------------------------------
	/// Finds the value associated with the given key, or creates a corresponding entry if it doesn't exist yet.
	/// The value of a new entry has to be initialized afterwards (but its default constructor has already been invoked).
	/// @param[in] key								Key of the value to find or create.
	/// @param[out] created						This will be set to true if a new entry has been created successfully, otherwise it will be set to false.
	/// @return												Pointer to value for the given key, or nullptr if an entry didn't exist and allocation of a new entry failed.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD ResultRef<V> InsertKey(const K& key, Bool& created = BoolLValue());

	//----------------------------------------------------------------------------------------
	/// Finds the value associated with the given key, or creates a corresponding entry if it doesn't exist yet.
	/// The value of a new entry has to be initialized afterwards (but its default constructor has already been invoked).
	/// @param[in] key								Key of the entry to find or create. If a new entry is created, its key will be constructed by move-semantics if possible.
	/// @param[out] created						This will be set to true if a new entry has been created successfully, otherwise it will be set to false.
	/// @return												Pointer to value for the given key, or nullptr if an entry didn't exist and allocation of a new entry failed.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD ResultRef<V> InsertKey(K&& key, Bool& created = BoolLValue());

	//----------------------------------------------------------------------------------------
	/// Associates the given value with the given key. This adds a new entry for key if necessary,
	/// and then sets its value to the given value, whether the entry existed before or not.
	/// @param[in] key								Key which shall map to the value.
	/// @param[in] value							Value to which the key shall map.
	/// @param[out] created						This will be set to true if a new entry has been created, otherwise it will be set to false.
	/// @return												Pointer to value for the given key, or nullptr if an entry didn't exist and allocation of a new entry failed.
	//----------------------------------------------------------------------------------------
	template <typename VALUE> MAXON_FUNCTION ResultRef<V> Insert(const K& key, VALUE&& value, Bool& created = BoolLValue())
	{
		ResultRef<V> v = InsertKey(key, created);
		if (v == OK)
			v.GetValue() = std::forward<VALUE>(value);
		return v;
	}

	//----------------------------------------------------------------------------------------
	/// Associates the given value with the given key. This adds a new entry for key if necessary,
	/// and then sets its value to the given value, whether the entry existed before or not.
	/// @param[in] key								Key of the entry to find or create. If a new entry is created, its key will be constructed by move-semantics if possible.
	/// @param[in] value							Value to which the key shall map.
	/// @param[out] created						This will be set to true if a new entry has been created, otherwise it will be set to false.
	/// @return												Pointer to value for the given key, or nullptr if an entry didn't exist and allocation of a new entry failed.
	//----------------------------------------------------------------------------------------
	template <typename VALUE> MAXON_FUNCTION ResultRef<V> Insert(K&& key, VALUE&& value, Bool& created = BoolLValue())
	{
		ResultRef<V> v = InsertKey(std::move(key), created);
		if (v == OK)
			v.GetValue() = std::forward<VALUE>(value);
		return v;
	}

	//----------------------------------------------------------------------------------------
	/// Finds the value associated with the given key in this map.
	/// @param[in] key								Key to search for.
	/// @return												Pointer to value for the given key, or nullptr if no entry exists for the key.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD V* FindValue(const K& key);

	//----------------------------------------------------------------------------------------
	/// Finds the value associated with the given key in this map.
	/// @param[in] key								Key to search for.
	/// @return												Pointer to value for the given key, or nullptr if no entry exists for the key.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD const V* FindValue(const K& key) const;

	//----------------------------------------------------------------------------------------
	/// Removes an entry with the given key from this map (if possible).
	/// @param[in] key								Key of the map entry to be be removed.
	/// @return												True if an entry was found and removed for #key, otherwise false or an error if a memory allocation failed.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Bool> Erase(const K& key);

	//----------------------------------------------------------------------------------------
	/// Removes the element at @p iterator from this set.
	/// The returned iterator will point to the element behind the last removed element.
	/// @param[in] iterator						Iterator pointing to the element to be removed.
	/// @return												Iterator pointing to the element behind the removed element.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Iterator Erase(const Iterator& iterator);

	//----------------------------------------------------------------------------------------
	/// Deletes all elements (calls destructors and frees memory).
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void Reset();

	//----------------------------------------------------------------------------------------
	/// Deletes all elements, but doesn't free memory (calls destructors though).
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void Flush();

	//----------------------------------------------------------------------------------------
	/// Sets this map to a copy of the given other map.
	/// @param[in] other							Source map.
	/// @return												Success of operation.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> CopyFrom(const MapInterface& other);

	//----------------------------------------------------------------------------------------
	/// Returns a clone of this map.
	/// @param[in] cloneElements			True if also the elements shall be cloned, false otherwise (then just a new object sharing the same MapInterface implementation is created).
	/// @return												Pointer to the new map object, nullptr if allocation or copying failed.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<MapInterface*> Clone(Bool cloneElements = true) const;

	//----------------------------------------------------------------------------------------
	/// Returns the data type of this map's keys. This may be nullptr if there is no
	/// DataType for the template parameter K.
	/// @return												DataType of the keys or nullptr.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD const DataType& GetKeyDataType() const;

	//----------------------------------------------------------------------------------------
	/// Returns the data type of this map's values. This may be nullptr if there is no
	/// DataType for the template parameter V.
	/// @return												DataType of the values or nullptr.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD const DataType& GetValueDataType() const;

	//----------------------------------------------------------------------------------------
	/// @param[in] formatStatement		Nullptr or additional formatting instruction. Currently no additional formatting instructions are supported.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD String ToString(const FormatStatement* formatStatement) const;

	//----------------------------------------------------------------------------------------
	/// Calculates the memory usage for this map.
	/// @return												Memory size in bytes.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Int GetMemorySize() const;

	MAXON_ADD_TO_CONST_REFERENCE_CLASS(UInt GetHashCode() const { CriticalStop("Not implemented."); return 0; };);

	template <typename KT, typename VT> MAXON_FUNCTION Bool HasType() const
	{
		return (GetKeyDataType() == maxon::GetDataType<KT>()) && (GetValueDataType() == maxon::GetDataType<VT>());
	}

	//----------------------------------------------------------------------------------------
	/// Issues a failed DebugAssert if the DataTypes of this map doesn't match KT/VT. For Generic,
	/// no check happens.
	/// @tparam KT										Type of keys to check.
	/// @tparam VT										Type of values to check.
	//----------------------------------------------------------------------------------------
	template <typename KT, typename VT> MAXON_FUNCTION void AssertType() const
	{
#ifdef MAXON_TARGET_DEBUG
		if (!std::is_same<Generic, KT>::value)
		{
			GetKeyDataType().template AssertType<typename std::conditional<std::is_same<Generic, KT>::value, Int, KT>::type>();
		}
		if (!std::is_same<Generic, VT>::value)
		{
			GetValueDataType().template AssertType<typename std::conditional<std::is_same<Generic, VT>::value, Int, VT>::type>();
		}
#endif
	}

	//----------------------------------------------------------------------------------------
	/// Casts this map to a map with keys of type KT and values of type VT. If one of they types doesn't match the actual data type of this
	/// map, a failed DebugAssert is issued. This function only makes sense when the original map
	/// uses Generic for at least one of its types.
	/// @tparam KT										Assumed key type of the map.
	/// @tparam VT										Assumed value type of the map.
	/// @return												This map, cast to a MapInterface<KT, VT>.
	//----------------------------------------------------------------------------------------
	template <typename KT, typename VT> MapInterface<KT, VT>& AssertCast()
	{
		AssertType<KT, VT>();
		return *reinterpret_cast<MapInterface<KT, VT>*>(this);
	}

	//----------------------------------------------------------------------------------------
	/// Casts this map to a map with keys of type KT and values of type VT. If one of they types doesn't match the actual data type of this
	/// map, a failed DebugAssert is issued. This function only makes sense when the original map
	/// uses Generic for at least one of its types.
	/// @tparam KT										Assumed key type of the map.
	/// @tparam VT										Assumed value type of the map.
	/// @return												This map, cast to a MapInterface<KT, VT>.
	//----------------------------------------------------------------------------------------
	template <typename KT, typename VT> const MapInterface<KT, VT>& AssertCast() const
	{
		AssertType<KT, VT>();
		return *reinterpret_cast<const MapInterface<KT, VT>*>(this);
	}

#ifdef MAXON_COMPILER_INTEL
#pragma warning disable 597
#endif
	operator const MapInterface<K, const V>&() const
	{
		return *(MapInterface<K, const V>*) this;
	}

	operator const MapInterface<Generic, typename std::conditional<std::is_same<const V, const Generic>::value, const DummyReturnType, const Generic>::type>&() const
	{
		return *(MapInterface<Generic, typename std::conditional<std::is_same<const V, const Generic>::value, const DummyReturnType, const Generic>::type>*) this;
	}

	operator MapInterface<Generic, typename std::conditional<std::is_same<V, Generic>::value, volatile DummyReturnType, Generic>::type>&()
	{
		return *(MapInterface<Generic, typename std::conditional<std::is_same<V, Generic>::value, volatile DummyReturnType, Generic>::type>*) this;
	}
#ifdef MAXON_COMPILER_INTEL
#pragma warning enable 597
#endif

	operator const NonConstMap<K, V>&()
	{
		return *reinterpret_cast<const NonConstMap<K, V>*>(this);
	}

	operator const NonConstMap<Generic, typename std::conditional<std::is_same<V, Generic>::value, DummyReturnType, Generic>::type>&()
	{
		return *reinterpret_cast<const NonConstMap<Generic, typename std::conditional<std::is_same<V, Generic>::value, DummyReturnType, Generic>::type>*>(this);
	}

	template <Bool CONSTITERATOR> class IteratorTemplate
	{
	public:
		using CollectionType = typename ConstIf<MapInterface, CONSTITERATOR>::type;
		using KeyType = const K;
		using ValueType = typename ConstIf<V, CONSTITERATOR>::type;

		IteratorTemplate() : _set(nullptr)
		{
		}

		IteratorTemplate(CollectionType& set, Bool end) : _set(&set)
		{
			set.IteratorInit(this, end);
		}

		IteratorTemplate(IteratorTemplate&& src) : _set(src._set)
		{
			_set->IteratorInitMove(this, &src);
			_set->IteratorFree(&src);
			src._set = nullptr;
		}

		template <typename IT> IteratorTemplate(CollectionType& set, IT&& it) : _set(&set)
		{
			new (_memory) IT(std::forward<IT>(it));
		}

		~IteratorTemplate()
		{
			if (_set)
			{
				_set->IteratorFree(this);
				_set = nullptr;
			}
		}

		MAXON_OPERATOR_MOVE_ASSIGNMENT(IteratorTemplate);

	#ifdef MAXON_COMPILER_INTEL
	#pragma warning disable 597
	#endif
		operator IteratorTemplate<true>&()
		{
			return *(IteratorTemplate<true>*) this;
		}
	#ifdef MAXON_COMPILER_INTEL
	#pragma warning enable 597
	#endif

		KeyType& GetKey() const
		{
			return _set->IteratorGet(this).GetKey();
		}

		ValueType& GetValue() const
		{
			return _set->IteratorGet(this).GetValue();
		}

		Pair<KeyType&, ValueType&> operator *() const
		{
			return _set->IteratorGet(this);
		}

		Bool operator ==(const IteratorTemplate& b) const
		{
			return _set->IteratorIsEqual(this, &b);
		}

		Bool operator !=(const IteratorTemplate& b) const
		{
			return !this->operator ==(b);
		}

		// prefix operator ++ (increment and fetch)
		IteratorTemplate& operator ++()
		{
			_set->IteratorInc(this);
			return *this;
		}

		// postfix operator ++ (fetch and increment)
		void operator ++(int)
		{
			this->operator ++();
		}

		using Memory = Int[200];

		const void* GetMemory() const
		{
			return _memory;
		}

		void* GetMemory()
		{
			return _memory;
		}

	protected:
		void operator ->();

	private:
		MAXON_DISALLOW_COPY_AND_ASSIGN(IteratorTemplate);

		CollectionType* _set;
		Memory _memory;
	};

	//----------------------------------------------------------------------------------------
	/// Returns an iterator pointing to the first map entry.
	/// @return												Iterator for the first map entry (equal to End() if the map is empty).
	//----------------------------------------------------------------------------------------
	ConstIterator Begin() const
	{
		return ConstIterator(*static_cast<const MapInterface*>(this), false);
	}

	//----------------------------------------------------------------------------------------
	/// Returns an iterator pointing to the first map entry.
	/// @return												Iterator for the first map entry (equal to End() if the map is empty).
	//----------------------------------------------------------------------------------------
	Iterator Begin()
	{
		return Iterator(*static_cast<MapInterface*>(this), false);
	}

	//----------------------------------------------------------------------------------------
	/// Returns an iterator pointing one behind the last map entry.
	/// @return												Iterator for the map end, this is one behind the last map entry.
	//----------------------------------------------------------------------------------------
	ConstIterator End() const
	{
		return ConstIterator(*static_cast<const MapInterface*>(this), true);
	}

	//----------------------------------------------------------------------------------------
	/// Returns an iterator pointing one behind the last map entry.
	/// @return												Iterator for the map end, this is one behind the last map entry.
	//----------------------------------------------------------------------------------------
	Iterator End()
	{
		return Iterator(*static_cast<MapInterface*>(this), true);
	}

#ifdef CPP_853_HACK
#ifdef MAXON_COMPILER_GCC
	MapInterface(const MapInterface& src) // GCC constructs from the conversion result, upcasted to MapInterface&
#else
private:
	MapInterface(const MapInterface& src);
public:
	template <typename MAP> MAXON_IMPLICIT MapInterface(const MapImpl<MAP>& src) // MSVC constructs directly from the conversion result, which allows a more type-safe hack
#endif
		: _vtable(src._vtable), _refDummy(src._refDummy)
	{
	}
#endif

protected:
	template <typename MAP> friend class MapImpl;
#ifdef CPP_853_HACK
	const void* _refDummy;
#endif

private:
	MAXON_METHOD void IteratorInit(Iterator* it, Bool end);

	MAXON_METHOD void IteratorInit(ConstIterator* it, Bool end) const;

	MAXON_METHOD void IteratorInitMove(Iterator* dest, Iterator* src) const;

	MAXON_METHOD void IteratorInitMove(ConstIterator* dest, ConstIterator* src) const;

	MAXON_METHOD void IteratorFree(Iterator* it) const;

	MAXON_METHOD void IteratorFree(ConstIterator* it) const;

	MAXON_METHOD Bool IteratorIsEqual(const Iterator* a, const Iterator* b) const;

	MAXON_METHOD Bool IteratorIsEqual(const ConstIterator* a, const ConstIterator* b) const;

	MAXON_METHOD void IteratorInc(Iterator* it) const;

	MAXON_METHOD void IteratorInc(ConstIterator* it) const;

	MAXON_METHOD Pair<const K&, V&> IteratorGet(const Iterator* it) const;

	MAXON_METHOD Pair<const K&, const V&> IteratorGet(const ConstIterator* it) const;

	static MapInterface* Alloc(MAXON_SOURCE_LOCATION_DECLARATION)
	{
		return nullptr;
	}

	static MapInterface* Alloc(MAXON_SOURCE_LOCATION_DECLARATION, const MapInterface& src)
	{
		iferr (MapInterface* a = src.Clone(true))
			return nullptr;
		return a;
	}
};

// Helper class for the WritableMapInterface macro.
// A WritableMapInterface& parameter is actually a const NonConstMap& parameter,
// so temporary objects resulting from a conversion of some map to the NonConstMap interface may be bound to such a parameter
// (this wouldn't be possible if the parameter was non-const).
// To be able to invoke modifying functions on such a parameter, those functions are implemented as const functions in this class.
template <typename K, typename V> class NonConstMap : public MapInterface<K, V>
{
public:
	using Super = MapInterface<K, V>;

	const NonConstMap& ToMap() const
	{
		return *this;
	}
	NonConstMap& ToMap()
	{
		return *this;
	}
	operator const NonConstMap<Generic, typename std::conditional<std::is_same<V, Generic>::value, DummyReturnType, Generic>::type>&() const
	{
		return *reinterpret_cast<const NonConstMap<Generic, typename std::conditional<std::is_same<V, Generic>::value, DummyReturnType, Generic>::type>*>(this);
	}

	using ConstIterator = typename Super::Iterator;

	ResultRef<V> InsertKey(const K& key, Bool& created = BoolLValue()) const { return const_cast<NonConstMap*>(this)->Super::InsertKey(key, created); }
	ResultRef<V> InsertKey(K&& key, Bool& created = BoolLValue()) const { return const_cast<NonConstMap*>(this)->Super::InsertKey(std::move(key), created); }
	template <typename VALUE> ResultRef<V> Insert(const K& key, VALUE&& value, Bool& created = BoolLValue()) const { return const_cast<NonConstMap*>(this)->Super::Insert(key, std::forward<VALUE>(value), created); }
	template <typename VALUE> ResultRef<V> Insert(K&& key, VALUE&& value, Bool& created = BoolLValue()) const { return const_cast<NonConstMap*>(this)->Super::Insert(std::move(key), std::forward<VALUE>(value), created); }
	V* FindValue(const K& key) const { return const_cast<NonConstMap*>(this)->Super::FindValue(key); }
	Result<Bool> Erase(const K& key) const { return const_cast<NonConstMap*>(this)->Super::Erase(key); }
	ConstIterator Erase(const ConstIterator& iterator) const { return const_cast<NonConstMap*>(this)->Super::Erase(iterator); }

	void Reset() const { return const_cast<NonConstMap*>(this)->Super::Reset(); }
	void Flush() const { return const_cast<NonConstMap*>(this)->Super::Flush(); }
	Result<void> CopyFrom(const Super& other) const { return const_cast<NonConstMap*>(this)->Super::CopyFrom(other); }

	ConstIterator Begin() const
	{
		return ConstIterator(*const_cast<NonConstMap*>(this), false);
	}

	ConstIterator End() const
	{
		return ConstIterator(*const_cast<NonConstMap*>(this), true);
	}

#ifdef CPP_853_HACK
#ifdef MAXON_COMPILER_GCC
	NonConstMap(const NonConstMap& src) // GCC constructs from the conversion result, upcasted to NonConstMap&
#else
private:
	NonConstMap(const NonConstMap& src);
public:
	template <typename MAP> MAXON_IMPLICIT NonConstMap(const MapImpl<MAP>& src) // MSVC constructs directly from the conversion result, which allows a more type-safe hack
#endif
		: Super(src)
	{
	}
#endif

protected:
	explicit NonConstMap(const typename Super::MTable& vtable) : Super(vtable) { }

#ifdef CPP_853_HACK

private:
	void operator =(const NonConstMap&);

#else

	~NonConstMap() { }
private:
	MAXON_DISALLOW_COPY_AND_ASSIGN(NonConstMap);

#endif
};

//----------------------------------------------------------------------------------------
/// WritableMapInterface is used for function parameters which shall be able to receive any kind of
/// standard map of the MAXON API via the MapInterface interface mechanism. You have to use WritableMapInterface
/// instead of MapInterface if you want to modify the map within the function. Example:
/// @code
/// void Func(WritableMapInterface<Int, String>& map);
///
/// HashMap<Int, String> myMap;
/// Func(myMap); // OK
/// ArrayMap<Int, String> myMap2;
/// Func(myMap2); // OK
/// @endcode
/// @see MapInterface
//----------------------------------------------------------------------------------------
#ifdef MAXON_COMPILER_BUG_CONST_TYPE_ALIAS
#define WritableMapInterface const NonConstMap
#else
template <typename K, typename V> using WritableMapInterface = const NonConstMap<K, V>;
#endif

#include "map1.hxx"
#include "map2.hxx"

template <typename MAP> class MapCloneHelper;

// This class is used to represent standard maps from the MAXON API by the MapInterface interface. The compiler converts those maps to MapImpl which is an implementation of MapInterface.
template <typename MAP> class MapImpl
	: public std::conditional<std::is_const<typename std::remove_reference<MAP>::type>::value || !std::is_reference<MAP>::value,
														MapInterface<typename std::remove_reference<MAP>::type::KeyType, typename ConstIf<typename std::remove_reference<MAP>::type::ValueType, std::is_const<typename std::remove_reference<MAP>::type>::value>::type>,
														NonConstMap<typename std::remove_reference<MAP>::type::KeyType, typename std::remove_reference<MAP>::type::ValueType>>::type
{
public:
	using MapType = typename std::decay<MAP>::type;
	static const Bool CONSTMAP = std::is_const<typename std::remove_reference<MAP>::type>::value;
	static const Bool REFERENCE = std::is_reference<MAP>::value;
	using KeyType = typename MapType::KeyType;
	using ValueType = typename ConstIf<typename MapType::ValueType, CONSTMAP>::type;
	using NonConstValueType = typename std::remove_const<ValueType>::type;
	using Super = typename std::conditional<CONSTMAP || !REFERENCE, MapInterface<KeyType, ValueType>, NonConstMap<KeyType, ValueType>>::type;
	using Interface = typename Super::Interface;
	using Iterator = typename Interface::Iterator;
	using ConstIterator = typename Interface::ConstIterator;

	MAXON_IMPLEMENTATION_SIMPLE(MapImpl, typename);

	MapImpl() : Super(_clsMTable) { }
#ifndef CPP_853_HACK
	explicit MapImpl(MAP&& map) : Super(_clsMTable), _map(std::forward<MAP>(map))
	{
	}

	MapImpl(MapImpl&& src) : Super(_clsMTable), _map(static_cast<MAP&&>(src._map))
	{
// src might be on the stack
//		DebugAssert(System::GetReferenceCounter(&src) == 0);
	}
#else
	explicit MapImpl(typename std::conditional<!REFERENCE, MAP, DummyParamType>::type&& map) : Super(_clsMTable), _map(std::forward<MAP>(map))
	{
		this->_refDummy = &map;
	}

	// MSVC bug workaround: MSVC 1916 only reserves space on stack for base class MapInterface, but not for MapImpl when the conversion function
	// of collection.h is used. Therefore the additional MapImpl member _map must not be accessed.
	explicit MapImpl(typename std::conditional<REFERENCE, MAP, DummyParamType>::type&& map) : Super(_clsMTable)
	{
		this->_refDummy = &map;
	}
	MapImpl(MapImpl&& src) : Super(_clsMTable)
	{
		this->_refDummy = src._refDummy;
		CopyMapMember(_map, src._map);
	}

	#define _map GetMap()
#endif

	Int GetCount() const { return _map.GetCount(); }

	ResultRef<NonConstValueType> InsertKey(const KeyType& key, Bool& created = BoolLValue())
	{
		if (CONSTMAP)
			return nullptr;
		return ((MapType*) &_map)->InsertKey(key, created);
	}

	ResultRef<NonConstValueType> InsertKey(KeyType&& key, Bool& created = BoolLValue())
	{
		if (CONSTMAP)
			return nullptr;
		return ((MapType*) &_map)->InsertKey(std::move(key), created);
	}

	NonConstValueType* FindValue(const KeyType& key)
	{
		if (CONSTMAP)
			return nullptr;
		return ((MapType*) &_map)->FindValue(key);
	}

	const ValueType* FindValue(const KeyType& key) const
	{
		return _map.FindValue(key);
	}

	Result<Bool> Erase(const KeyType& key)
	{
		if (CONSTMAP)
			return CreateError(MAXON_SOURCE_LOCATION, ERROR_TYPE::NOT_IMPLEMENTED);
		return ((MapType*) &_map)->Erase(key);
	}

	Iterator Erase(const Iterator& iterator)
	{
		if (CONSTMAP)
			return Iterator();
		return Iterator(*this, ((MapType*) &_map)->Erase(GetIterator(&iterator)));
	}

	Result<void> CopyFrom(const Interface& other)
	{
		if (CONSTMAP)
			return CreateError(MAXON_SOURCE_LOCATION, ERROR_TYPE::NOT_IMPLEMENTED);
		return ((MapType*) &_map)->CopyFrom(*((MapType*) &static_cast<const MapImpl&>(other)._map));
	};

	Result<Interface*> Clone(Bool cloneElements) const
	{
		iferr (MapImpl* c = MapCloneHelper<MAP>::New())
			return err;
		if (cloneElements)
		{
			iferr (((MapType*) &c->_map)->CopyFrom(*(MapType*) &_map))
			{
				DeleteObj(c);
				return err;
			}
		}
		return c;
	}

	String ToString(const FormatStatement* formatStatement) const { return GlobalToString(_map, formatStatement); }

	Int GetMemorySize() const { return _map.GetMemorySize() + (SIZEOF(MapImpl) - SIZEOF(MAP)); }

	const DataType& GetKeyDataType() const
	{
		return GetDataType<KeyType, GET_DATATYPE_POLICY::GENERIC_FOR_UNKNOWN>();
	}

	const DataType& GetValueDataType() const
	{
		return GetDataType<ValueType, GET_DATATYPE_POLICY::GENERIC_FOR_UNKNOWN>();
	}

	void Reset()
	{
		if (CONSTMAP)
			return;
		((MapType*) &_map)->Reset();
	}

	void Flush()
	{
		if (CONSTMAP)
			return;
		((MapType*) &_map)->Flush();
	}

	static_assert(SIZEOF(typename MapType::Iterator) <= SIZEOF(typename Iterator::Memory), "Insufficient iterator size.");
	static_assert(SIZEOF(typename MapType::ConstIterator) <= SIZEOF(typename ConstIterator::Memory), "Insufficient iterator size.");

	void IteratorInit(Iterator* it, Bool end)
	{
		if (end)
			new (it->GetMemory()) typename MapType::Iterator(((MapType*) &_map)->End());
		else
			new (it->GetMemory()) typename MapType::Iterator(((MapType*) &_map)->Begin());
	}

	void IteratorInit(ConstIterator* it, Bool end) const
	{
		if (end)
			new (it->GetMemory()) typename MapType::ConstIterator(_map.End());
		else
			new (it->GetMemory()) typename MapType::ConstIterator(_map.Begin());
	}

	void IteratorInitMove(Iterator* dest, Iterator* src) const
	{
		new (dest->GetMemory()) typename MapType::Iterator(std::move(GetIterator(src)));
	}

	void IteratorInitMove(ConstIterator* dest, ConstIterator* src) const
	{
		new (dest->GetMemory()) typename MapType::ConstIterator(std::move(GetIterator(src)));
	}

	void IteratorFree(Iterator* it) const
	{
		Destruct(GetIterator(it));
	}

	void IteratorFree(ConstIterator* it) const
	{
		Destruct(GetIterator(it));
	}

	Bool IteratorIsEqual(const Iterator* a, const Iterator* b) const
	{
		return GetIterator(a) == GetIterator(b);
	}

	Bool IteratorIsEqual(const ConstIterator* a, const ConstIterator* b) const
	{
		return GetIterator(a) == GetIterator(b);
	}

	void IteratorInc(Iterator* it) const
	{
		++GetIterator(it);
	}

	void IteratorInc(ConstIterator* it) const
	{
		++GetIterator(it);
	}

	Pair<const KeyType&, ValueType&> IteratorGet(const Iterator* it) const
	{
		const typename MapType::Iterator& i = GetIterator(it);
		return Pair<const KeyType&, ValueType&>(i.GetKey(), i.GetValue());
	}

	Pair<const KeyType&, const ValueType&> IteratorGet(const ConstIterator* it) const
	{
		const typename MapType::ConstIterator& i = GetIterator(it);
		return Pair<const KeyType&, const ValueType&>(i.GetKey(), i.GetValue());
	}

#ifdef CPP_853_HACK
	#undef _map

	typename std::add_lvalue_reference<MAP>::type GetMap() { return REFERENCE ? *(MapType*) this->_refDummy : GetImpl(_map); }

	const MapType& GetMap() const { return REFERENCE ? *(const MapType*) this->_refDummy : GetImpl(_map); }
#else
	typename std::add_lvalue_reference<MAP>::type GetMap() { return _map; }

	const MapType& GetMap() const { return _map; }
#endif

private:
	template <typename T> static void Destruct(const T& object)
	{
		object.~T();
	}

	static typename MapType::Iterator& GetIterator(Iterator* it)
	{
		return *((typename MapType::Iterator*) it->GetMemory());
	}

	static typename MapType::ConstIterator& GetIterator(ConstIterator* it)
	{
		return *((typename MapType::ConstIterator*) it->GetMemory());
	}

	static const typename MapType::Iterator& GetIterator(const Iterator* it)
	{
		return *((const typename MapType::Iterator*) it->GetMemory());
	}

	static const typename MapType::ConstIterator& GetIterator(const ConstIterator* it)
	{
		return *((const typename MapType::ConstIterator*) it->GetMemory());
	}

	MAXON_DISALLOW_COPY_AND_ASSIGN(MapImpl);

#ifdef CPP_853_HACK
	typename std::conditional<REFERENCE, Bool, MAP>::type _map;

	template <typename T> static T& GetImpl(T& x)
	{
		return x;
	}

	static MapType& GetImpl(Bool)
	{
		return reinterpret_cast<MapType&>(g_writableMemory);
	}

	static void CopyMapMember(MAP& dst, MAP& src)
	{
		dst = static_cast<MAP&&>(src);
	}

	static void CopyMapMember(Bool, Bool)
	{
	}

#else
	MAP _map;
#endif
};


template <typename MAP> class MapCloneHelper
{
public:
	static ResultPtr<MapImpl<MAP>> New()
	{
		return NewObj(MapImpl<MAP>);
	}
};

template <typename MAP> class MapCloneHelper<MAP&>
{
public:
	static ResultPtr<MapImpl<MAP&>> New()
	{
		DebugStop("Can't clone MapImpl when the internal map is a reference!");
		return nullptr;
	}
};


template <typename MAP> MAXON_IMPLEMENTATION_REGISTER_SIMPLE(MapImpl<MAP>, typename);


template <typename COLLECTION, typename KEYTYPE, typename VALUETYPE, typename SUPER, typename HASH> inline MapImpl<COLLECTION&> MapBase<COLLECTION, KEYTYPE, VALUETYPE, SUPER, HASH>::ToMap()
{
	return MapImpl<COLLECTION&>(*static_cast<COLLECTION*>(this));
}

template <typename COLLECTION, typename KEYTYPE, typename VALUETYPE, typename SUPER, typename HASH> inline MapImpl<const COLLECTION&> MapBase<COLLECTION, KEYTYPE, VALUETYPE, SUPER, HASH>::ToMap() const
{
	return MapImpl<const COLLECTION&>(*static_cast<const COLLECTION*>(this));
}

//----------------------------------------------------------------------------------------
/// Returns a pointer to the map reference argument. This function is useful if you have to
/// convert some map to a pointer to a MapInterface:
/// @code
/// void Func(const MapInterface<Int, const String>* map);
///
/// HashMap<Int, String> myMap;
/// Func(ToMapPtr(myMap));
/// @endcode
/// For WritableMapInterface parameters, use ToWritableMapPtr instead.
///
/// @see MapInterface.
///
/// @tparam K											Type of keys of the map, this is deduced by the compiler.
/// @tparam V											Type of values of the map, this is deduced by the compiler.
///
/// @note If the argument is a temporary (which usually is the case), the result will be a
/// pointer to a temporary. Make sure that the pointer is used only within the lifetime
/// of the temporary. For the above example, it suffices that Func uses the map only
/// during its execution.
//----------------------------------------------------------------------------------------
template <typename K, typename V> inline const MapInterface<K, V>* ToMapPtr(const MapInterface<K, V>& map)
{
	return &map;
}

//----------------------------------------------------------------------------------------
/// Returns a pointer to the map reference argument. This function is useful if you have to
/// convert some map to a pointer to a MapInterface:
/// @code
/// void Func(WritableMapInterface<Int, String>* map);
///
/// HashMap<Int, String> myMap;
/// Func(ToWritableMapPtr(myMap));
/// @endcode
/// For non-modifiable map parameters, use ToMapPtr instead.
///
/// @see MapInterface.
///
/// @tparam K											Type of keys of the map, this is deduced by the compiler.
/// @tparam V											Type of values of the map, this is deduced by the compiler.
///
/// @note If the argument is a temporary (which usually is the case), the result will be a
/// pointer to a temporary. Make sure that the pointer is used only within the lifetime
/// of the temporary. For the above example, it suffices that Func uses the map only
/// during its execution.
//----------------------------------------------------------------------------------------
template <typename K, typename V> inline WritableMapInterface<K, V>* ToWritableMapPtr(WritableMapInterface<K, V>& map)
{
	return &map;
}

} // namespace maxon

#endif // MAP_H__
