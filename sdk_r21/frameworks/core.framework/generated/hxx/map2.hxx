
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1
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

template <typename K, typename V> struct MapInterface<K, V>::MTable
{
	MTable() { }
	template <typename C> explicit MTable(C*) { Init<typename maxon::SFINAEHelper<Hxx2, C>::type::template Wrapper<C>>(); }
	template <typename C> MTable(C*, maxon::Bool) { Init<C>(); }
	void (*_MapInterface_Free) (const MapInterface* object);
	Int (*_MapInterface_GetCount) (const MapInterface* this_);
	ResultRef<V> (*_MapInterface_InsertKey) (MapInterface* this_, const K& key, Bool& created);
	ResultRef<V> (*_MapInterface_InsertKey_1) (MapInterface* this_, K&& key, Bool& created);
	V* (*_MapInterface_FindValue) (MapInterface* this_, const K& key);
	const V* (*_MapInterface_FindValue_1) (const MapInterface* this_, const K& key);
	Result<Bool> (*_MapInterface_Erase) (MapInterface* this_, const K& key);
	Iterator (*_MapInterface_Erase_1) (MapInterface* this_, const Iterator& iterator);
	void (*_MapInterface_Reset) (MapInterface* this_);
	void (*_MapInterface_Flush) (MapInterface* this_);
	Result<void> (*_MapInterface_CopyFrom) (MapInterface* this_, const MapInterface& other);
	Result<MapInterface*> (*_MapInterface_Clone) (const MapInterface* this_, Bool cloneElements);
	const DataType& (*_MapInterface_GetKeyDataType) (const MapInterface* this_);
	const DataType& (*_MapInterface_GetValueDataType) (const MapInterface* this_);
	String (*_MapInterface_ToString) (const MapInterface* this_, const FormatStatement* formatStatement);
	Int (*_MapInterface_GetMemorySize) (const MapInterface* this_);
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
	void (*_MapInterface_IteratorInit) (MapInterface* this_, Iterator* it, Bool end);
	void (*_MapInterface_IteratorInit_1) (const MapInterface* this_, ConstIterator* it, Bool end);
	void (*_MapInterface_IteratorInitMove) (const MapInterface* this_, Iterator* dest, Iterator* src);
	void (*_MapInterface_IteratorInitMove_1) (const MapInterface* this_, ConstIterator* dest, ConstIterator* src);
	void (*_MapInterface_IteratorFree) (const MapInterface* this_, Iterator* it);
	void (*_MapInterface_IteratorFree_1) (const MapInterface* this_, ConstIterator* it);
	Bool (*_MapInterface_IteratorIsEqual) (const MapInterface* this_, const Iterator* a, const Iterator* b);
	Bool (*_MapInterface_IteratorIsEqual_1) (const MapInterface* this_, const ConstIterator* a, const ConstIterator* b);
	void (*_MapInterface_IteratorInc) (const MapInterface* this_, Iterator* it);
	void (*_MapInterface_IteratorInc_1) (const MapInterface* this_, ConstIterator* it);
	Pair<const K&, V&> (*_MapInterface_IteratorGet) (const MapInterface* this_, const Iterator* it);
	Pair<const K&, const V&> (*_MapInterface_IteratorGet_1) (const MapInterface* this_, const ConstIterator* it);
	template <typename IMPL> void Init()
	{
		_MapInterface_Free = &IMPL::_MapInterface_Free;
		_MapInterface_GetCount = &IMPL::_MapInterface_GetCount;
		_MapInterface_InsertKey = &IMPL::_MapInterface_InsertKey;
		_MapInterface_InsertKey_1 = &IMPL::_MapInterface_InsertKey_1;
		_MapInterface_FindValue = &IMPL::_MapInterface_FindValue;
		_MapInterface_FindValue_1 = &IMPL::_MapInterface_FindValue_1;
		_MapInterface_Erase = &IMPL::_MapInterface_Erase;
		_MapInterface_Erase_1 = &IMPL::_MapInterface_Erase_1;
		_MapInterface_Reset = &IMPL::_MapInterface_Reset;
		_MapInterface_Flush = &IMPL::_MapInterface_Flush;
		_MapInterface_CopyFrom = &IMPL::_MapInterface_CopyFrom;
		_MapInterface_Clone = &IMPL::_MapInterface_Clone;
		_MapInterface_GetKeyDataType = &IMPL::_MapInterface_GetKeyDataType;
		_MapInterface_GetValueDataType = &IMPL::_MapInterface_GetValueDataType;
		_MapInterface_ToString = &IMPL::_MapInterface_ToString;
		_MapInterface_GetMemorySize = &IMPL::_MapInterface_GetMemorySize;
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
		_MapInterface_IteratorInit = &IMPL::_MapInterface_IteratorInit;
		_MapInterface_IteratorInit_1 = &IMPL::_MapInterface_IteratorInit_1;
		_MapInterface_IteratorInitMove = &IMPL::_MapInterface_IteratorInitMove;
		_MapInterface_IteratorInitMove_1 = &IMPL::_MapInterface_IteratorInitMove_1;
		_MapInterface_IteratorFree = &IMPL::_MapInterface_IteratorFree;
		_MapInterface_IteratorFree_1 = &IMPL::_MapInterface_IteratorFree_1;
		_MapInterface_IteratorIsEqual = &IMPL::_MapInterface_IteratorIsEqual;
		_MapInterface_IteratorIsEqual_1 = &IMPL::_MapInterface_IteratorIsEqual_1;
		_MapInterface_IteratorInc = &IMPL::_MapInterface_IteratorInc;
		_MapInterface_IteratorInc_1 = &IMPL::_MapInterface_IteratorInc_1;
		_MapInterface_IteratorGet = &IMPL::_MapInterface_IteratorGet;
		_MapInterface_IteratorGet_1 = &IMPL::_MapInterface_IteratorGet_1;
	}
};

template <typename K, typename V> struct MapInterface<K, V>::Hxx2
{
	template <typename C> class Wrapper
	{
	public:
	static void _MapInterface_Free(const MapInterface* object) { return C::Free((const C*) object); }
	static Int _MapInterface_GetCount(const MapInterface* this_) { return ((const C*) this_)->GetCount(); }
	static ResultRef<V> _MapInterface_InsertKey(MapInterface* this_, const K& key, Bool& created) { return ((C*) this_)->InsertKey(key, created); }
	static ResultRef<V> _MapInterface_InsertKey_1(MapInterface* this_, K&& key, Bool& created) { return ((C*) this_)->InsertKey(std::forward<K>(key), created); }
	static V* _MapInterface_FindValue(MapInterface* this_, const K& key) { return ((C*) this_)->FindValue(key); }
	static const V* _MapInterface_FindValue_1(const MapInterface* this_, const K& key) { return ((const C*) this_)->FindValue(key); }
	static Result<Bool> _MapInterface_Erase(MapInterface* this_, const K& key) { return ((C*) this_)->Erase(key); }
	static Iterator _MapInterface_Erase_1(MapInterface* this_, const Iterator& iterator) { return ((C*) this_)->Erase(iterator); }
	static void _MapInterface_Reset(MapInterface* this_) { return ((C*) this_)->Reset(); }
	static void _MapInterface_Flush(MapInterface* this_) { return ((C*) this_)->Flush(); }
	static Result<void> _MapInterface_CopyFrom(MapInterface* this_, const MapInterface& other) { return ((C*) this_)->CopyFrom(other); }
	static Result<MapInterface*> _MapInterface_Clone(const MapInterface* this_, Bool cloneElements) { return ((const C*) this_)->Clone(cloneElements); }
	static const DataType& _MapInterface_GetKeyDataType(const MapInterface* this_) { return ((const C*) this_)->GetKeyDataType(); }
	static const DataType& _MapInterface_GetValueDataType(const MapInterface* this_) { return ((const C*) this_)->GetValueDataType(); }
	static String _MapInterface_ToString(const MapInterface* this_, const FormatStatement* formatStatement) { return ((const C*) this_)->ToString(formatStatement); }
	static Int _MapInterface_GetMemorySize(const MapInterface* this_) { return ((const C*) this_)->GetMemorySize(); }
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
	static void _MapInterface_IteratorInit(MapInterface* this_, Iterator* it, Bool end) { return ((C*) this_)->IteratorInit(it, end); }
	static void _MapInterface_IteratorInit_1(const MapInterface* this_, ConstIterator* it, Bool end) { return ((const C*) this_)->IteratorInit(it, end); }
	static void _MapInterface_IteratorInitMove(const MapInterface* this_, Iterator* dest, Iterator* src) { return ((const C*) this_)->IteratorInitMove(dest, src); }
	static void _MapInterface_IteratorInitMove_1(const MapInterface* this_, ConstIterator* dest, ConstIterator* src) { return ((const C*) this_)->IteratorInitMove(dest, src); }
	static void _MapInterface_IteratorFree(const MapInterface* this_, Iterator* it) { return ((const C*) this_)->IteratorFree(it); }
	static void _MapInterface_IteratorFree_1(const MapInterface* this_, ConstIterator* it) { return ((const C*) this_)->IteratorFree(it); }
	static Bool _MapInterface_IteratorIsEqual(const MapInterface* this_, const Iterator* a, const Iterator* b) { return ((const C*) this_)->IteratorIsEqual(a, b); }
	static Bool _MapInterface_IteratorIsEqual_1(const MapInterface* this_, const ConstIterator* a, const ConstIterator* b) { return ((const C*) this_)->IteratorIsEqual(a, b); }
	static void _MapInterface_IteratorInc(const MapInterface* this_, Iterator* it) { return ((const C*) this_)->IteratorInc(it); }
	static void _MapInterface_IteratorInc_1(const MapInterface* this_, ConstIterator* it) { return ((const C*) this_)->IteratorInc(it); }
	static Pair<const K&, V&> _MapInterface_IteratorGet(const MapInterface* this_, const Iterator* it) { return ((const C*) this_)->IteratorGet(it); }
	static Pair<const K&, const V&> _MapInterface_IteratorGet_1(const MapInterface* this_, const ConstIterator* it) { return ((const C*) this_)->IteratorGet(it); }
	};

};
template <typename K, typename V> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::Free(const MapInterface* object) -> void
{
	if (!object)
		return;
	return ((MapInterface::MTable*) object->_vtable)->_MapInterface_Free(object);
}
template <typename K, typename V> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::GetCount() const -> Int
{
	return ((MapInterface::MTable*) this->_vtable)->_MapInterface_GetCount(this);
}
template <typename K, typename V> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::InsertKey(const K& key, Bool& created) -> ResultRef<V>
{
	return ((MapInterface::MTable*) this->_vtable)->_MapInterface_InsertKey(this, key, created);
}
template <typename K, typename V> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::InsertKey(K&& key, Bool& created) -> ResultRef<V>
{
	return ((MapInterface::MTable*) this->_vtable)->_MapInterface_InsertKey_1(this, std::forward<K>(key), created);
}
template <typename K, typename V> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::FindValue(const K& key) -> V*
{
	return ((MapInterface::MTable*) this->_vtable)->_MapInterface_FindValue(this, key);
}
template <typename K, typename V> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::FindValue(const K& key) const -> const V*
{
	return ((MapInterface::MTable*) this->_vtable)->_MapInterface_FindValue_1(this, key);
}
template <typename K, typename V> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::Erase(const K& key) -> Result<Bool>
{
	return ((MapInterface::MTable*) this->_vtable)->_MapInterface_Erase(this, key);
}
template <typename K, typename V> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::Erase(const Iterator& iterator) -> Iterator
{
	return ((MapInterface::MTable*) this->_vtable)->_MapInterface_Erase_1(this, iterator);
}
template <typename K, typename V> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::Reset() -> void
{
	return ((MapInterface::MTable*) this->_vtable)->_MapInterface_Reset(this);
}
template <typename K, typename V> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::Flush() -> void
{
	return ((MapInterface::MTable*) this->_vtable)->_MapInterface_Flush(this);
}
template <typename K, typename V> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::CopyFrom(const MapInterface& other) -> Result<void>
{
	return ((MapInterface::MTable*) this->_vtable)->_MapInterface_CopyFrom(this, other);
}
template <typename K, typename V> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::Clone(Bool cloneElements) const -> Result<MapInterface*>
{
	return ((MapInterface::MTable*) this->_vtable)->_MapInterface_Clone(this, cloneElements);
}
template <typename K, typename V> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::GetKeyDataType() const -> const DataType&
{
	return ((MapInterface::MTable*) this->_vtable)->_MapInterface_GetKeyDataType(this);
}
template <typename K, typename V> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::GetValueDataType() const -> const DataType&
{
	return ((MapInterface::MTable*) this->_vtable)->_MapInterface_GetValueDataType(this);
}
template <typename K, typename V> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::ToString(const FormatStatement* formatStatement) const -> String
{
	return ((MapInterface::MTable*) this->_vtable)->_MapInterface_ToString(this, formatStatement);
}
template <typename K, typename V> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::GetMemorySize() const -> Int
{
	return ((MapInterface::MTable*) this->_vtable)->_MapInterface_GetMemorySize(this);
}
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
template <typename K, typename V> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::IteratorInit(Iterator* it, Bool end) -> void
{
	return ((MapInterface::MTable*) this->_vtable)->_MapInterface_IteratorInit(this, it, end);
}
template <typename K, typename V> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::IteratorInit(ConstIterator* it, Bool end) const -> void
{
	return ((MapInterface::MTable*) this->_vtable)->_MapInterface_IteratorInit_1(this, it, end);
}
template <typename K, typename V> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::IteratorInitMove(Iterator* dest, Iterator* src) const -> void
{
	return ((MapInterface::MTable*) this->_vtable)->_MapInterface_IteratorInitMove(this, dest, src);
}
template <typename K, typename V> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::IteratorInitMove(ConstIterator* dest, ConstIterator* src) const -> void
{
	return ((MapInterface::MTable*) this->_vtable)->_MapInterface_IteratorInitMove_1(this, dest, src);
}
template <typename K, typename V> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::IteratorFree(Iterator* it) const -> void
{
	return ((MapInterface::MTable*) this->_vtable)->_MapInterface_IteratorFree(this, it);
}
template <typename K, typename V> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::IteratorFree(ConstIterator* it) const -> void
{
	return ((MapInterface::MTable*) this->_vtable)->_MapInterface_IteratorFree_1(this, it);
}
template <typename K, typename V> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::IteratorIsEqual(const Iterator* a, const Iterator* b) const -> Bool
{
	return ((MapInterface::MTable*) this->_vtable)->_MapInterface_IteratorIsEqual(this, a, b);
}
template <typename K, typename V> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::IteratorIsEqual(const ConstIterator* a, const ConstIterator* b) const -> Bool
{
	return ((MapInterface::MTable*) this->_vtable)->_MapInterface_IteratorIsEqual_1(this, a, b);
}
template <typename K, typename V> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::IteratorInc(Iterator* it) const -> void
{
	return ((MapInterface::MTable*) this->_vtable)->_MapInterface_IteratorInc(this, it);
}
template <typename K, typename V> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::IteratorInc(ConstIterator* it) const -> void
{
	return ((MapInterface::MTable*) this->_vtable)->_MapInterface_IteratorInc_1(this, it);
}
template <typename K, typename V> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::IteratorGet(const Iterator* it) const -> Pair<const K&, V&>
{
	return ((MapInterface::MTable*) this->_vtable)->_MapInterface_IteratorGet(this, it);
}
template <typename K, typename V> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::IteratorGet(const ConstIterator* it) const -> Pair<const K&, const V&>
{
	return ((MapInterface::MTable*) this->_vtable)->_MapInterface_IteratorGet_1(this, it);
}

template <typename K, typename V> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::Hxx1::ConstReferenceFunctionsImpl<S>::GetCount() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const MapInterface* o_ = (const MapInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = MapInterface::NullValuePtr(); if (!o_) return 0; } 
	return (((MapInterface::MTable*) o_->_vtable)->_MapInterface_GetCount(o_));
}
template <typename K, typename V> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::Hxx1::ConstReferenceFunctionsImpl<S>::IsEmpty() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const MapInterface* o_ = (const MapInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = MapInterface::NullValuePtr(); if (!o_) return true; } 
	return (o_->IsEmpty());
}
template <typename K, typename V> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::Hxx1::ConstReferenceFunctionsImpl<S>::IsPopulated() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const MapInterface* o_ = (const MapInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = MapInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (o_->IsPopulated());
}
template <typename K, typename V> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::Hxx1::ReferenceFunctionsImpl<S>::InsertKey(const K& key, Bool& created) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<V&>, ResultRef<V>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<V&>, ResultRef<V>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); MapInterface* o_ = (MapInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateNullReturnValue<ResultRef<V>>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); 
	return (((MapInterface::MTable*) o_->_vtable)->_MapInterface_InsertKey(o_, key, created));
}
template <typename K, typename V> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::Hxx1::COWReferenceFunctionsImpl<S>::InsertKey(const K& key, Bool& created) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultRef<V>, maxon::Result<V&>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultRef<V>, maxon::Result<V&>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); MapInterface* o_ = (MapInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	return (((MapInterface::MTable*) o_->_vtable)->_MapInterface_InsertKey(o_, key, created));
}
template <typename K, typename V> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::Hxx1::ReferenceFunctionsImpl<S>::InsertKey(K&& key, Bool& created) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<V&>, ResultRef<V>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<V&>, ResultRef<V>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); MapInterface* o_ = (MapInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateNullReturnValue<ResultRef<V>>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); 
	return (((MapInterface::MTable*) o_->_vtable)->_MapInterface_InsertKey_1(o_, std::forward<K>(key), created));
}
template <typename K, typename V> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::Hxx1::COWReferenceFunctionsImpl<S>::InsertKey(K&& key, Bool& created) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultRef<V>, maxon::Result<V&>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultRef<V>, maxon::Result<V&>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); MapInterface* o_ = (MapInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	return (((MapInterface::MTable*) o_->_vtable)->_MapInterface_InsertKey_1(o_, std::forward<K>(key), created));
}
template <typename K, typename V> template <typename S> template <typename VALUE> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::Hxx1::ReferenceFunctionsImpl<S>::Insert(const K& key, VALUE&& value, Bool& created) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<V&>, ResultRef<V>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<V&>, ResultRef<V>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); MapInterface* o_ = (MapInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateNullReturnValue<ResultRef<V>>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); 
	return (o_->Insert<VALUE>(key, std::forward<VALUE>(value), created));
}
template <typename K, typename V> template <typename S> template <typename VALUE> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::Hxx1::COWReferenceFunctionsImpl<S>::Insert(const K& key, VALUE&& value, Bool& created) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultRef<V>, maxon::Result<V&>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultRef<V>, maxon::Result<V&>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); MapInterface* o_ = (MapInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	return (o_->Insert<VALUE>(key, std::forward<VALUE>(value), created));
}
template <typename K, typename V> template <typename S> template <typename VALUE> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::Hxx1::ReferenceFunctionsImpl<S>::Insert(K&& key, VALUE&& value, Bool& created) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<V&>, ResultRef<V>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<V&>, ResultRef<V>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); MapInterface* o_ = (MapInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateNullReturnValue<ResultRef<V>>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); 
	return (o_->Insert<VALUE>(std::forward<K>(key), std::forward<VALUE>(value), created));
}
template <typename K, typename V> template <typename S> template <typename VALUE> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::Hxx1::COWReferenceFunctionsImpl<S>::Insert(K&& key, VALUE&& value, Bool& created) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultRef<V>, maxon::Result<V&>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultRef<V>, maxon::Result<V&>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); MapInterface* o_ = (MapInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	return (o_->Insert<VALUE>(std::forward<K>(key), std::forward<VALUE>(value), created));
}
template <typename K, typename V> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::Hxx1::ReferenceFunctionsImpl<S>::FindValue(const K& key) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<V*>, V*>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<V*>, V*>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); MapInterface* o_ = (MapInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return nullptr; 
	return (((MapInterface::MTable*) o_->_vtable)->_MapInterface_FindValue(o_, key));
}
template <typename K, typename V> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::Hxx1::ConstReferenceFunctionsImpl<S>::FindValue(const K& key) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const V*>, const V*>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const V*>, const V*>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const MapInterface* o_ = (const MapInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = MapInterface::NullValuePtr(); if (!o_) return nullptr; } 
	return (((MapInterface::MTable*) o_->_vtable)->_MapInterface_FindValue_1(o_, key));
}
template <typename K, typename V> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::Hxx1::ReferenceFunctionsImpl<S>::Erase(const K& key) const -> Result<Bool>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Bool>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); MapInterface* o_ = (MapInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); 
	return (((MapInterface::MTable*) o_->_vtable)->_MapInterface_Erase(o_, key));
}
template <typename K, typename V> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::Hxx1::COWReferenceFunctionsImpl<S>::Erase(const K& key) -> Result<Bool>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Bool>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); MapInterface* o_ = (MapInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	return (((MapInterface::MTable*) o_->_vtable)->_MapInterface_Erase(o_, key));
}
template <typename K, typename V> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::Hxx1::ReferenceFunctionsImpl<S>::Erase(const Iterator& iterator) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Iterator>, Iterator>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Iterator>, Iterator>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); MapInterface* o_ = (MapInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateNullReturnValue<Iterator>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); 
	return (((MapInterface::MTable*) o_->_vtable)->_MapInterface_Erase_1(o_, iterator));
}
template <typename K, typename V> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::Hxx1::COWReferenceFunctionsImpl<S>::Erase(const Iterator& iterator) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Iterator, maxon::Result<Iterator>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Iterator, maxon::Result<Iterator>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); MapInterface* o_ = (MapInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	return (((MapInterface::MTable*) o_->_vtable)->_MapInterface_Erase_1(o_, iterator));
}
template <typename K, typename V> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::Hxx1::ReferenceFunctionsImpl<S>::Reset() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); MapInterface* o_ = (MapInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateLogNullptrError(); 
	((MapInterface::MTable*) o_->_vtable)->_MapInterface_Reset(o_);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename K, typename V> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::Hxx1::COWReferenceFunctionsImpl<S>::Reset() -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); MapInterface* o_ = (MapInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	((MapInterface::MTable*) o_->_vtable)->_MapInterface_Reset(o_);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename K, typename V> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::Hxx1::ReferenceFunctionsImpl<S>::Flush() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); MapInterface* o_ = (MapInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateLogNullptrError(); 
	((MapInterface::MTable*) o_->_vtable)->_MapInterface_Flush(o_);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename K, typename V> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::Hxx1::COWReferenceFunctionsImpl<S>::Flush() -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); MapInterface* o_ = (MapInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	((MapInterface::MTable*) o_->_vtable)->_MapInterface_Flush(o_);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename K, typename V> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::Hxx1::ReferenceFunctionsImpl<S>::CopyFrom(const MapInterface& other) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); MapInterface* o_ = (MapInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); 
	return (((MapInterface::MTable*) o_->_vtable)->_MapInterface_CopyFrom(o_, other));
}
template <typename K, typename V> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::Hxx1::COWReferenceFunctionsImpl<S>::CopyFrom(const MapInterface& other) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); MapInterface* o_ = (MapInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	return (((MapInterface::MTable*) o_->_vtable)->_MapInterface_CopyFrom(o_, other));
}
template <typename K, typename V> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::Hxx1::ConstReferenceFunctionsImpl<S>::Clone(Bool cloneElements) const -> Result<MapInterface*>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<MapInterface*>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const MapInterface* o_ = (const MapInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = MapInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (((MapInterface::MTable*) o_->_vtable)->_MapInterface_Clone(o_, cloneElements));
}
template <typename K, typename V> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::Hxx1::ConstReferenceFunctionsImpl<S>::GetKeyDataType() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const DataType&>, const DataType&>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const DataType&>, const DataType&>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const MapInterface* o_ = (const MapInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = MapInterface::NullValuePtr(); if (!o_) return maxon::PrivateNullReturnValue<const DataType&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (((MapInterface::MTable*) o_->_vtable)->_MapInterface_GetKeyDataType(o_));
}
template <typename K, typename V> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::Hxx1::ConstReferenceFunctionsImpl<S>::GetValueDataType() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const DataType&>, const DataType&>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const DataType&>, const DataType&>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const MapInterface* o_ = (const MapInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = MapInterface::NullValuePtr(); if (!o_) return maxon::PrivateNullReturnValue<const DataType&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (((MapInterface::MTable*) o_->_vtable)->_MapInterface_GetValueDataType(o_));
}
template <typename K, typename V> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::Hxx1::ConstReferenceFunctionsImpl<S>::ToString(const FormatStatement* formatStatement) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const MapInterface* o_ = (const MapInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = MapInterface::NullValuePtr(); if (!o_) return maxon::PrivateNullReturnValue<String>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (((MapInterface::MTable*) o_->_vtable)->_MapInterface_ToString(o_, formatStatement));
}
template <typename K, typename V> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::Hxx1::ConstReferenceFunctionsImpl<S>::GetMemorySize() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const MapInterface* o_ = (const MapInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = MapInterface::NullValuePtr(); if (!o_) return 0; } 
	return (((MapInterface::MTable*) o_->_vtable)->_MapInterface_GetMemorySize(o_));
}
template <typename K, typename V> template <typename S> template <typename KT, typename VT> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::Hxx1::ConstReferenceFunctionsImpl<S>::HasType() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const MapInterface* o_ = (const MapInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = MapInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (o_->HasType<KT, VT>());
}
template <typename K, typename V> template <typename S> template <typename KT, typename VT> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::Hxx1::ConstReferenceFunctionsImpl<S>::AssertType() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const MapInterface* o_ = (const MapInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = MapInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(); } 
	o_->AssertType<KT, VT>();
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
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

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

