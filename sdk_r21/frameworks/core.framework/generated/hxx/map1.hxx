#if 1
template <typename K, typename V> class Map;

#ifdef MAXON_COMPILER_INTEL
#endif
#ifdef MAXON_COMPILER_INTEL
#endif
#ifdef CPP_853_HACK
#ifdef MAXON_COMPILER_GCC
#else
#endif
#endif
#ifdef CPP_853_HACK
#endif
template <typename K, typename V> struct MapInterface<K, V>::Hxx1
{
	class Reference;
	class NonConstRef;
	using ReferenceClass = Map<K, V>;
	/// Intermediate helper class for MapInterface.
	template <typename S> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
	{
	public:
		ConstReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
/// Gets the number of map entries.
/// @return												Number of map entries.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type GetCount() const;
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type IsEmpty() const;
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type IsPopulated() const;
/// Finds the value associated with the given key in this map.
/// @param[in] key								Key to search for.
/// @return												Pointer to value for the given key, or nullptr if no entry exists for the key.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<const V*>, const V*>::type FindValue(const K& key) const;
/// Returns a clone of this map.
/// @param[in] cloneElements			True if also the elements shall be cloned, false otherwise (then just a new object sharing the same MapInterface implementation is created).
/// @return												Pointer to the new map object, nullptr if allocation or copying failed.
		inline Result<MapInterface*> Clone(Bool cloneElements = true) const;
/// Returns the data type of this map's keys. This may be nullptr if there is no
/// DataType for the template parameter K.
/// @return												DataType of the keys or nullptr.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<const DataType&>, const DataType&>::type GetKeyDataType() const;
/// Returns the data type of this map's values. This may be nullptr if there is no
/// DataType for the template parameter V.
/// @return												DataType of the values or nullptr.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<const DataType&>, const DataType&>::type GetValueDataType() const;
/// @param[in] formatStatement		Nullptr or additional formatting instruction. Currently no additional formatting instructions are supported.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type ToString(const FormatStatement* formatStatement) const;
/// Calculates the memory usage for this map.
/// @return												Memory size in bytes.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type GetMemorySize() const;
UInt GetHashCode() const { CriticalStop("Not implemented."); return 0; };
		public:
		template <typename KT, typename VT> inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type HasType() const;
/// Issues a failed DebugAssert if the DataTypes of this map doesn't match KT/VT. For Generic,
/// no check happens.
/// @tparam KT										Type of keys to check.
/// @tparam VT										Type of values to check.
		template <typename KT, typename VT> inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type AssertType() const;
#ifdef MAXON_COMPILER_INTEL
#endif
#ifdef MAXON_COMPILER_INTEL
#endif
#ifdef CPP_853_HACK
#ifdef MAXON_COMPILER_GCC
#else
#endif
#endif
#ifdef CPP_853_HACK
#endif
	};
	/// Intermediate helper class for MapInterface.
	template <typename S> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
/// Finds the value associated with the given key, or creates a corresponding entry if it doesn't exist yet.
/// The value of a new entry has to be initialized afterwards (but its default constructor has already been invoked).
/// @param[in] key								Key of the value to find or create.
/// @param[out] created						This will be set to true if a new entry has been created successfully, otherwise it will be set to false.
/// @return												Pointer to value for the given key, or nullptr if an entry didn't exist and allocation of a new entry failed.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<V&>, ResultRef<V>>::type InsertKey(const K& key, Bool& created = BoolLValue()) const;
/// Finds the value associated with the given key, or creates a corresponding entry if it doesn't exist yet.
/// The value of a new entry has to be initialized afterwards (but its default constructor has already been invoked).
/// @param[in] key								Key of the entry to find or create. If a new entry is created, its key will be constructed by move-semantics if possible.
/// @param[out] created						This will be set to true if a new entry has been created successfully, otherwise it will be set to false.
/// @return												Pointer to value for the given key, or nullptr if an entry didn't exist and allocation of a new entry failed.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<V&>, ResultRef<V>>::type InsertKey(K&& key, Bool& created = BoolLValue()) const;
/// Associates the given value with the given key. This adds a new entry for key if necessary,
/// and then sets its value to the given value, whether the entry existed before or not.
/// @param[in] key								Key which shall map to the value.
/// @param[in] value							Value to which the key shall map.
/// @param[out] created						This will be set to true if a new entry has been created, otherwise it will be set to false.
/// @return												Pointer to value for the given key, or nullptr if an entry didn't exist and allocation of a new entry failed.
		template <typename VALUE> inline typename std::conditional<S::HAS_ERROR, maxon::Result<V&>, ResultRef<V>>::type Insert(const K& key, VALUE&& value, Bool& created = BoolLValue()) const;
/// Associates the given value with the given key. This adds a new entry for key if necessary,
/// and then sets its value to the given value, whether the entry existed before or not.
/// @param[in] key								Key of the entry to find or create. If a new entry is created, its key will be constructed by move-semantics if possible.
/// @param[in] value							Value to which the key shall map.
/// @param[out] created						This will be set to true if a new entry has been created, otherwise it will be set to false.
/// @return												Pointer to value for the given key, or nullptr if an entry didn't exist and allocation of a new entry failed.
		template <typename VALUE> inline typename std::conditional<S::HAS_ERROR, maxon::Result<V&>, ResultRef<V>>::type Insert(K&& key, VALUE&& value, Bool& created = BoolLValue()) const;
/// Finds the value associated with the given key in this map.
/// @param[in] key								Key to search for.
/// @return												Pointer to value for the given key, or nullptr if no entry exists for the key.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<V*>, V*>::type FindValue(const K& key) const;
/// Removes an entry with the given key from this map (if possible).
/// @param[in] key								Key of the map entry to be be removed.
/// @return												True if an entry was found and removed for #key, otherwise false or an error if a memory allocation failed.
		inline Result<Bool> Erase(const K& key) const;
/// Removes the element at @p iterator from this set.
/// The returned iterator will point to the element behind the last removed element.
/// @param[in] iterator						Iterator pointing to the element to be removed.
/// @return												Iterator pointing to the element behind the removed element.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Iterator>, Iterator>::type Erase(const Iterator& iterator) const;
/// Deletes all elements (calls destructors and frees memory).
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type Reset() const;
/// Deletes all elements, but doesn't free memory (calls destructors though).
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type Flush() const;
/// Sets this map to a copy of the given other map.
/// @param[in] other							Source map.
/// @return												Success of operation.
		inline Result<void> CopyFrom(const MapInterface& other) const;
#ifdef MAXON_COMPILER_INTEL
#endif
#ifdef MAXON_COMPILER_INTEL
#endif
#ifdef CPP_853_HACK
#ifdef MAXON_COMPILER_GCC
#else
#endif
#endif
#ifdef CPP_853_HACK
#endif
	};
	/// Intermediate helper class for MapInterface.
	template <typename S> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, Map<K, V>, false>::type&() const { return reinterpret_cast<const Map<K, V>&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, Map<K, V>, false>::type&() { return reinterpret_cast<const Map<K, V>&>(this->GetBaseRef()); }
/// Finds the value associated with the given key, or creates a corresponding entry if it doesn't exist yet.
/// The value of a new entry has to be initialized afterwards (but its default constructor has already been invoked).
/// @param[in] key								Key of the value to find or create.
/// @param[out] created						This will be set to true if a new entry has been created successfully, otherwise it will be set to false.
/// @return												Pointer to value for the given key, or nullptr if an entry didn't exist and allocation of a new entry failed.
		inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultRef<V>, maxon::Result<V&>>::type InsertKey(const K& key, Bool& created = BoolLValue());
/// Finds the value associated with the given key, or creates a corresponding entry if it doesn't exist yet.
/// The value of a new entry has to be initialized afterwards (but its default constructor has already been invoked).
/// @param[in] key								Key of the entry to find or create. If a new entry is created, its key will be constructed by move-semantics if possible.
/// @param[out] created						This will be set to true if a new entry has been created successfully, otherwise it will be set to false.
/// @return												Pointer to value for the given key, or nullptr if an entry didn't exist and allocation of a new entry failed.
		inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultRef<V>, maxon::Result<V&>>::type InsertKey(K&& key, Bool& created = BoolLValue());
/// Associates the given value with the given key. This adds a new entry for key if necessary,
/// and then sets its value to the given value, whether the entry existed before or not.
/// @param[in] key								Key which shall map to the value.
/// @param[in] value							Value to which the key shall map.
/// @param[out] created						This will be set to true if a new entry has been created, otherwise it will be set to false.
/// @return												Pointer to value for the given key, or nullptr if an entry didn't exist and allocation of a new entry failed.
		template <typename VALUE> inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultRef<V>, maxon::Result<V&>>::type Insert(const K& key, VALUE&& value, Bool& created = BoolLValue());
/// Associates the given value with the given key. This adds a new entry for key if necessary,
/// and then sets its value to the given value, whether the entry existed before or not.
/// @param[in] key								Key of the entry to find or create. If a new entry is created, its key will be constructed by move-semantics if possible.
/// @param[in] value							Value to which the key shall map.
/// @param[out] created						This will be set to true if a new entry has been created, otherwise it will be set to false.
/// @return												Pointer to value for the given key, or nullptr if an entry didn't exist and allocation of a new entry failed.
		template <typename VALUE> inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultRef<V>, maxon::Result<V&>>::type Insert(K&& key, VALUE&& value, Bool& created = BoolLValue());
/// Removes an entry with the given key from this map (if possible).
/// @param[in] key								Key of the map entry to be be removed.
/// @return												True if an entry was found and removed for #key, otherwise false or an error if a memory allocation failed.
		inline Result<Bool> Erase(const K& key);
/// Removes the element at @p iterator from this set.
/// The returned iterator will point to the element behind the last removed element.
/// @param[in] iterator						Iterator pointing to the element to be removed.
/// @return												Iterator pointing to the element behind the removed element.
		inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Iterator, maxon::Result<Iterator>>::type Erase(const Iterator& iterator);
/// Deletes all elements (calls destructors and frees memory).
		inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type Reset();
/// Deletes all elements, but doesn't free memory (calls destructors though).
		inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type Flush();
/// Sets this map to a copy of the given other map.
/// @param[in] other							Source map.
/// @return												Success of operation.
		inline Result<void> CopyFrom(const MapInterface& other);
#ifdef MAXON_COMPILER_INTEL
#endif
#ifdef MAXON_COMPILER_INTEL
#endif
#ifdef CPP_853_HACK
#ifdef MAXON_COMPILER_GCC
#else
#endif
#endif
#ifdef CPP_853_HACK
#endif
		explicit operator maxon::Bool() const MAXON_WORKAROUND_CLANG_DELETED_FUNCTION(S);
		explicit operator maxon::Bool() MAXON_WORKAROUND_CLANG_DELETED_FUNCTION(S);
	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename ST::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename ST::type>, ReferenceFunctionsImpl<typename ST::type>>::type> { };
};
template <typename K, typename V> class MapInterface<K, V>::Hxx1::Reference :
#ifdef DOXYGEN
public COWReferenceFunctionsImplDoxy<Map<K, V>>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const MapInterface<K, V>, maxon::StrongCOWRefHandler, Map<K, V>>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const MapInterface<K, V>, maxon::StrongCOWRefHandler, Map<K, V>>>>>);
	using NonConst = Hxx1::NonConstRef;
};

/// Map is the reference class of MapInterface.
///
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
template <typename K, typename V> class Map : public MapInterface<K, V>::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Map, typename MapInterface<K, V>::Hxx1::Reference);
	struct Instantiation
	{
		template <template <typename> class MAP> using Map = Map<typename MAP<K>::type, typename MAP<V>::type>;
	};
};

#ifdef CPP_853_HACK
#ifdef MAXON_COMPILER_GCC
#else
#endif
#endif
#ifdef CPP_853_HACK
#else
#endif
#ifdef MAXON_COMPILER_BUG_CONST_TYPE_ALIAS
#else
#endif
#ifndef CPP_853_HACK
#else
#endif
#ifdef CPP_853_HACK
#else
#endif
#ifdef CPP_853_HACK
#else
#endif
#endif
