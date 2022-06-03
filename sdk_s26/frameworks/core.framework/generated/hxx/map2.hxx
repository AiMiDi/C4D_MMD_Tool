
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
	Int (*MapInterface_GetCount) (const MapInterface* this_);
	ResultRef<V> (*MapInterface_InsertKey) (MapInterface* this_, const K& key, Bool& created);
	ResultRef<V> (*MapInterface_InsertKey_1) (MapInterface* this_, K&& key, Bool& created);
	V* (*MapInterface_FindValue) (MapInterface* this_, const K& key);
	const V* (*MapInterface_FindValue_1) (const MapInterface* this_, const K& key);
	Result<Bool> (*MapInterface_Erase) (MapInterface* this_, const K& key);
	Iterator (*MapInterface_Erase_1) (MapInterface* this_, const Iterator& iterator);
	void (*MapInterface_Reset) (MapInterface* this_);
	void (*MapInterface_Flush) (MapInterface* this_);
	Result<void> (*MapInterface_CopyFrom) (MapInterface* this_, const MapInterface& other);
	Result<MapInterface*> (*MapInterface_Clone) (const MapInterface* this_, Bool copyContent);
	const DataType& (*MapInterface_GetKeyDataType) (const MapInterface* this_);
	const DataType& (*MapInterface_GetValueDataType) (const MapInterface* this_);
	String (*MapInterface_ToString) (const MapInterface* this_, const FormatStatement* formatStatement);
	Int (*MapInterface_GetMemorySize) (const MapInterface* this_);
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
	void (*MapInterface_IteratorInit) (MapInterface* this_, Iterator* it, Bool end);
	void (*MapInterface_IteratorInit_1) (const MapInterface* this_, ConstIterator* it, Bool end);
	void (*MapInterface_IteratorInitMove) (const MapInterface* this_, Iterator* dest, Iterator* src);
	void (*MapInterface_IteratorInitMove_1) (const MapInterface* this_, ConstIterator* dest, ConstIterator* src);
	void (*MapInterface_IteratorFree) (const MapInterface* this_, Iterator* it);
	void (*MapInterface_IteratorFree_1) (const MapInterface* this_, ConstIterator* it);
	Bool (*MapInterface_IteratorIsEqual) (const MapInterface* this_, const Iterator* a, const Iterator* b);
	Bool (*MapInterface_IteratorIsEqual_1) (const MapInterface* this_, const ConstIterator* a, const ConstIterator* b);
	void (*MapInterface_IteratorInc) (const MapInterface* this_, Iterator* it);
	void (*MapInterface_IteratorInc_1) (const MapInterface* this_, ConstIterator* it);
	Pair<const K&, V&> (*MapInterface_IteratorGet) (const MapInterface* this_, const Iterator* it);
	Pair<const K&, const V&> (*MapInterface_IteratorGet_1) (const MapInterface* this_, const ConstIterator* it);
	maxon::ClassInfoBase _info;
	template <typename IMPL> void Init()
	{
		void (*free) (const MapInterface*) = &IMPL::Implementation::Free;
		_info._free = reinterpret_cast<void(*)(const void*)>(free);
		MapInterface_GetCount = &IMPL::MapInterface_GetCount;
		MapInterface_InsertKey = &IMPL::MapInterface_InsertKey;
		MapInterface_InsertKey_1 = &IMPL::MapInterface_InsertKey_1;
		MapInterface_FindValue = &IMPL::MapInterface_FindValue;
		MapInterface_FindValue_1 = &IMPL::MapInterface_FindValue_1;
		MapInterface_Erase = &IMPL::MapInterface_Erase;
		MapInterface_Erase_1 = &IMPL::MapInterface_Erase_1;
		MapInterface_Reset = &IMPL::MapInterface_Reset;
		MapInterface_Flush = &IMPL::MapInterface_Flush;
		MapInterface_CopyFrom = &IMPL::MapInterface_CopyFrom;
		MapInterface_Clone = &IMPL::MapInterface_Clone;
		MapInterface_GetKeyDataType = &IMPL::MapInterface_GetKeyDataType;
		MapInterface_GetValueDataType = &IMPL::MapInterface_GetValueDataType;
		MapInterface_ToString = &IMPL::MapInterface_ToString;
		MapInterface_GetMemorySize = &IMPL::MapInterface_GetMemorySize;
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
		MapInterface_IteratorInit = &IMPL::MapInterface_IteratorInit;
		MapInterface_IteratorInit_1 = &IMPL::MapInterface_IteratorInit_1;
		MapInterface_IteratorInitMove = &IMPL::MapInterface_IteratorInitMove;
		MapInterface_IteratorInitMove_1 = &IMPL::MapInterface_IteratorInitMove_1;
		MapInterface_IteratorFree = &IMPL::MapInterface_IteratorFree;
		MapInterface_IteratorFree_1 = &IMPL::MapInterface_IteratorFree_1;
		MapInterface_IteratorIsEqual = &IMPL::MapInterface_IteratorIsEqual;
		MapInterface_IteratorIsEqual_1 = &IMPL::MapInterface_IteratorIsEqual_1;
		MapInterface_IteratorInc = &IMPL::MapInterface_IteratorInc;
		MapInterface_IteratorInc_1 = &IMPL::MapInterface_IteratorInc_1;
		MapInterface_IteratorGet = &IMPL::MapInterface_IteratorGet;
		MapInterface_IteratorGet_1 = &IMPL::MapInterface_IteratorGet_1;
	}
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset) { return true; }
	template <typename S> using CombinedMTable = S;
};

template <typename K, typename V> struct MapInterface<K, V>::Hxx2
{
	template <typename C> using CWrapper = C;
	template <typename C> class Wrapper
	{
	public:
		using Implementation = C;
		static Int MapInterface_GetCount(const MapInterface* this_) { return C::Get(this_)->GetCount(); }
		static ResultRef<V> MapInterface_InsertKey(MapInterface* this_, const K& key, Bool& created) { return C::Get(this_)->InsertKey(key, created); }
		static ResultRef<V> MapInterface_InsertKey_1(MapInterface* this_, K&& key, Bool& created) { return C::Get(this_)->InsertKey(std::forward<K>(key), created); }
		static V* MapInterface_FindValue(MapInterface* this_, const K& key) { return C::Get(this_)->FindValue(key); }
		static const V* MapInterface_FindValue_1(const MapInterface* this_, const K& key) { return C::Get(this_)->FindValue(key); }
		static Result<Bool> MapInterface_Erase(MapInterface* this_, const K& key) { return C::Get(this_)->Erase(key); }
		static Iterator MapInterface_Erase_1(MapInterface* this_, const Iterator& iterator) { return C::Get(this_)->Erase(iterator); }
		static void MapInterface_Reset(MapInterface* this_) { return C::Get(this_)->Reset(); }
		static void MapInterface_Flush(MapInterface* this_) { return C::Get(this_)->Flush(); }
		static Result<void> MapInterface_CopyFrom(MapInterface* this_, const MapInterface& other) { return C::Get(this_)->CopyFrom(other); }
		static Result<MapInterface*> MapInterface_Clone(const MapInterface* this_, Bool copyContent) { return C::Get(this_)->Clone(copyContent); }
		static const DataType& MapInterface_GetKeyDataType(const MapInterface* this_) { return C::Get(this_)->GetKeyDataType(); }
		static const DataType& MapInterface_GetValueDataType(const MapInterface* this_) { return C::Get(this_)->GetValueDataType(); }
		static String MapInterface_ToString(const MapInterface* this_, const FormatStatement* formatStatement) { return C::Get(this_)->ToString(formatStatement); }
		static Int MapInterface_GetMemorySize(const MapInterface* this_) { return C::Get(this_)->GetMemorySize(); }
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
		static void MapInterface_IteratorInit(MapInterface* this_, Iterator* it, Bool end) { return C::Get(this_)->IteratorInit(it, end); }
		static void MapInterface_IteratorInit_1(const MapInterface* this_, ConstIterator* it, Bool end) { return C::Get(this_)->IteratorInit(it, end); }
		static void MapInterface_IteratorInitMove(const MapInterface* this_, Iterator* dest, Iterator* src) { return C::Get(this_)->IteratorInitMove(dest, src); }
		static void MapInterface_IteratorInitMove_1(const MapInterface* this_, ConstIterator* dest, ConstIterator* src) { return C::Get(this_)->IteratorInitMove(dest, src); }
		static void MapInterface_IteratorFree(const MapInterface* this_, Iterator* it) { return C::Get(this_)->IteratorFree(it); }
		static void MapInterface_IteratorFree_1(const MapInterface* this_, ConstIterator* it) { return C::Get(this_)->IteratorFree(it); }
		static Bool MapInterface_IteratorIsEqual(const MapInterface* this_, const Iterator* a, const Iterator* b) { return C::Get(this_)->IteratorIsEqual(a, b); }
		static Bool MapInterface_IteratorIsEqual_1(const MapInterface* this_, const ConstIterator* a, const ConstIterator* b) { return C::Get(this_)->IteratorIsEqual(a, b); }
		static void MapInterface_IteratorInc(const MapInterface* this_, Iterator* it) { return C::Get(this_)->IteratorInc(it); }
		static void MapInterface_IteratorInc_1(const MapInterface* this_, ConstIterator* it) { return C::Get(this_)->IteratorInc(it); }
		static Pair<const K&, V&> MapInterface_IteratorGet(const MapInterface* this_, const Iterator* it) { return C::Get(this_)->IteratorGet(it); }
		static Pair<const K&, const V&> MapInterface_IteratorGet_1(const MapInterface* this_, const ConstIterator* it) { return C::Get(this_)->IteratorGet(it); }
	};

};
template <typename K, typename V> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::GetCount() const -> Int
{
	return ((MapInterface::MTable*) (this->_vtableCls + 1))[-1].MapInterface_GetCount(this);
}
template <typename K, typename V> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::InsertKey(const K& key, Bool& created) -> ResultRef<V>
{
	return ((MapInterface::MTable*) (this->_vtableCls + 1))[-1].MapInterface_InsertKey(this, key, created);
}
template <typename K, typename V> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::InsertKey(K&& key, Bool& created) -> ResultRef<V>
{
	return ((MapInterface::MTable*) (this->_vtableCls + 1))[-1].MapInterface_InsertKey_1(this, std::forward<K>(key), created);
}
template <typename K, typename V> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::FindValue(const K& key) -> V*
{
	return ((MapInterface::MTable*) (this->_vtableCls + 1))[-1].MapInterface_FindValue(this, key);
}
template <typename K, typename V> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::FindValue(const K& key) const -> const V*
{
	return ((MapInterface::MTable*) (this->_vtableCls + 1))[-1].MapInterface_FindValue_1(this, key);
}
template <typename K, typename V> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::Erase(const K& key) -> Result<Bool>
{
	return ((MapInterface::MTable*) (this->_vtableCls + 1))[-1].MapInterface_Erase(this, key);
}
template <typename K, typename V> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::Erase(const Iterator& iterator) -> Iterator
{
	return ((MapInterface::MTable*) (this->_vtableCls + 1))[-1].MapInterface_Erase_1(this, iterator);
}
template <typename K, typename V> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::Reset() -> void
{
	return ((MapInterface::MTable*) (this->_vtableCls + 1))[-1].MapInterface_Reset(this);
}
template <typename K, typename V> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::Flush() -> void
{
	return ((MapInterface::MTable*) (this->_vtableCls + 1))[-1].MapInterface_Flush(this);
}
template <typename K, typename V> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::CopyFrom(const MapInterface& other) -> Result<void>
{
	return ((MapInterface::MTable*) (this->_vtableCls + 1))[-1].MapInterface_CopyFrom(this, other);
}
template <typename K, typename V> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::Clone(Bool copyContent) const -> Result<MapInterface*>
{
	return ((MapInterface::MTable*) (this->_vtableCls + 1))[-1].MapInterface_Clone(this, copyContent);
}
template <typename K, typename V> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::GetKeyDataType() const -> const DataType&
{
	return ((MapInterface::MTable*) (this->_vtableCls + 1))[-1].MapInterface_GetKeyDataType(this);
}
template <typename K, typename V> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::GetValueDataType() const -> const DataType&
{
	return ((MapInterface::MTable*) (this->_vtableCls + 1))[-1].MapInterface_GetValueDataType(this);
}
template <typename K, typename V> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::ToString(const FormatStatement* formatStatement) const -> String
{
	return ((MapInterface::MTable*) (this->_vtableCls + 1))[-1].MapInterface_ToString(this, formatStatement);
}
template <typename K, typename V> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::GetMemorySize() const -> Int
{
	return ((MapInterface::MTable*) (this->_vtableCls + 1))[-1].MapInterface_GetMemorySize(this);
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
	return ((MapInterface::MTable*) (this->_vtableCls + 1))[-1].MapInterface_IteratorInit(this, it, end);
}
template <typename K, typename V> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::IteratorInit(ConstIterator* it, Bool end) const -> void
{
	return ((MapInterface::MTable*) (this->_vtableCls + 1))[-1].MapInterface_IteratorInit_1(this, it, end);
}
template <typename K, typename V> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::IteratorInitMove(Iterator* dest, Iterator* src) const -> void
{
	return ((MapInterface::MTable*) (this->_vtableCls + 1))[-1].MapInterface_IteratorInitMove(this, dest, src);
}
template <typename K, typename V> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::IteratorInitMove(ConstIterator* dest, ConstIterator* src) const -> void
{
	return ((MapInterface::MTable*) (this->_vtableCls + 1))[-1].MapInterface_IteratorInitMove_1(this, dest, src);
}
template <typename K, typename V> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::IteratorFree(Iterator* it) const -> void
{
	return ((MapInterface::MTable*) (this->_vtableCls + 1))[-1].MapInterface_IteratorFree(this, it);
}
template <typename K, typename V> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::IteratorFree(ConstIterator* it) const -> void
{
	return ((MapInterface::MTable*) (this->_vtableCls + 1))[-1].MapInterface_IteratorFree_1(this, it);
}
template <typename K, typename V> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::IteratorIsEqual(const Iterator* a, const Iterator* b) const -> Bool
{
	return ((MapInterface::MTable*) (this->_vtableCls + 1))[-1].MapInterface_IteratorIsEqual(this, a, b);
}
template <typename K, typename V> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::IteratorIsEqual(const ConstIterator* a, const ConstIterator* b) const -> Bool
{
	return ((MapInterface::MTable*) (this->_vtableCls + 1))[-1].MapInterface_IteratorIsEqual_1(this, a, b);
}
template <typename K, typename V> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::IteratorInc(Iterator* it) const -> void
{
	return ((MapInterface::MTable*) (this->_vtableCls + 1))[-1].MapInterface_IteratorInc(this, it);
}
template <typename K, typename V> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::IteratorInc(ConstIterator* it) const -> void
{
	return ((MapInterface::MTable*) (this->_vtableCls + 1))[-1].MapInterface_IteratorInc_1(this, it);
}
template <typename K, typename V> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::IteratorGet(const Iterator* it) const -> Pair<const K&, V&>
{
	return ((MapInterface::MTable*) (this->_vtableCls + 1))[-1].MapInterface_IteratorGet(this, it);
}
template <typename K, typename V> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::IteratorGet(const ConstIterator* it) const -> Pair<const K&, const V&>
{
	return ((MapInterface::MTable*) (this->_vtableCls + 1))[-1].MapInterface_IteratorGet_1(this, it);
}

template <typename K, typename V> MapInterface<K, V>::MapInterface(const MTable& vtable) : _vtableCls(&vtable._info) { }
template <typename K, typename V> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::Hxx1::ConstFn<S>::GetCount() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const MapInterface* o_ = (const MapInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = MapInterface::NullValuePtr(); if (!o_) return 0; } 
	return (((MapInterface::MTable*) (o_->_vtableCls + 1))[-1].MapInterface_GetCount(o_));
}
template <typename K, typename V> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::Hxx1::ConstFn<S>::IsEmpty() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const MapInterface* o_ = (const MapInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = MapInterface::NullValuePtr(); if (!o_) return true; } 
	return (o_->IsEmpty());
}
template <typename K, typename V> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::Hxx1::ConstFn<S>::IsPopulated() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const MapInterface* o_ = (const MapInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = MapInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (o_->IsPopulated());
}
template <typename K, typename V> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::Hxx1::Fn<S>::InsertKey(const K& key, Bool& created) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<V&>, ResultRef<V>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<V&>, ResultRef<V>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); MapInterface* o_ = (MapInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateNullReturnValue<ResultRef<V>>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (((MapInterface::MTable*) (o_->_vtableCls + 1))[-1].MapInterface_InsertKey(o_, key, created));
}
template <typename K, typename V> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::Hxx1::COWFn<S>::InsertKey(const K& key, Bool& created) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultRef<V>, maxon::Result<V&>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultRef<V>, maxon::Result<V&>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); MapInterface* o_ = (MapInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (((MapInterface::MTable*) (o_->_vtableCls + 1))[-1].MapInterface_InsertKey(o_, key, created));
}
template <typename K, typename V> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::Hxx1::Fn<S>::InsertKey(K&& key, Bool& created) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<V&>, ResultRef<V>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<V&>, ResultRef<V>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); MapInterface* o_ = (MapInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateNullReturnValue<ResultRef<V>>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (((MapInterface::MTable*) (o_->_vtableCls + 1))[-1].MapInterface_InsertKey_1(o_, std::forward<K>(key), created));
}
template <typename K, typename V> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::Hxx1::COWFn<S>::InsertKey(K&& key, Bool& created) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultRef<V>, maxon::Result<V&>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultRef<V>, maxon::Result<V&>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); MapInterface* o_ = (MapInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (((MapInterface::MTable*) (o_->_vtableCls + 1))[-1].MapInterface_InsertKey_1(o_, std::forward<K>(key), created));
}
template <typename K, typename V> template <typename S> template <typename VALUE> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::Hxx1::Fn<S>::Insert(const K& key, VALUE&& value, Bool& created) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<V&>, ResultRef<V>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<V&>, ResultRef<V>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); MapInterface* o_ = (MapInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateNullReturnValue<ResultRef<V>>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (o_->Insert<VALUE>(key, std::forward<VALUE>(value), created));
}
template <typename K, typename V> template <typename S> template <typename VALUE> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::Hxx1::COWFn<S>::Insert(const K& key, VALUE&& value, Bool& created) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultRef<V>, maxon::Result<V&>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultRef<V>, maxon::Result<V&>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); MapInterface* o_ = (MapInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (o_->Insert<VALUE>(key, std::forward<VALUE>(value), created));
}
template <typename K, typename V> template <typename S> template <typename VALUE> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::Hxx1::Fn<S>::Insert(K&& key, VALUE&& value, Bool& created) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<V&>, ResultRef<V>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<V&>, ResultRef<V>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); MapInterface* o_ = (MapInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateNullReturnValue<ResultRef<V>>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (o_->Insert<VALUE>(std::forward<K>(key), std::forward<VALUE>(value), created));
}
template <typename K, typename V> template <typename S> template <typename VALUE> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::Hxx1::COWFn<S>::Insert(K&& key, VALUE&& value, Bool& created) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultRef<V>, maxon::Result<V&>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultRef<V>, maxon::Result<V&>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); MapInterface* o_ = (MapInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (o_->Insert<VALUE>(std::forward<K>(key), std::forward<VALUE>(value), created));
}
template <typename K, typename V> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::Hxx1::Fn<S>::FindValue(const K& key) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<V*>, V*>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<V*>, V*>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); MapInterface* o_ = (MapInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return nullptr; } 
	return (((MapInterface::MTable*) (o_->_vtableCls + 1))[-1].MapInterface_FindValue(o_, key));
}
template <typename K, typename V> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::Hxx1::ConstFn<S>::FindValue(const K& key) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const V*>, const V*>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const V*>, const V*>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const MapInterface* o_ = (const MapInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = MapInterface::NullValuePtr(); if (!o_) return nullptr; } 
	return (((MapInterface::MTable*) (o_->_vtableCls + 1))[-1].MapInterface_FindValue_1(o_, key));
}
template <typename K, typename V> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::Hxx1::Fn<S>::Erase(const K& key) const -> Result<Bool>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Bool>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); MapInterface* o_ = (MapInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (((MapInterface::MTable*) (o_->_vtableCls + 1))[-1].MapInterface_Erase(o_, key));
}
template <typename K, typename V> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::Hxx1::COWFn<S>::Erase(const K& key) -> Result<Bool>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Bool>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); MapInterface* o_ = (MapInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (((MapInterface::MTable*) (o_->_vtableCls + 1))[-1].MapInterface_Erase(o_, key));
}
template <typename K, typename V> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::Hxx1::Fn<S>::Erase(const Iterator& iterator) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Iterator>, Iterator>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Iterator>, Iterator>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); MapInterface* o_ = (MapInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateNullReturnValue<Iterator>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (((MapInterface::MTable*) (o_->_vtableCls + 1))[-1].MapInterface_Erase_1(o_, iterator));
}
template <typename K, typename V> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::Hxx1::COWFn<S>::Erase(const Iterator& iterator) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Iterator, maxon::Result<Iterator>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Iterator, maxon::Result<Iterator>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); MapInterface* o_ = (MapInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (((MapInterface::MTable*) (o_->_vtableCls + 1))[-1].MapInterface_Erase_1(o_, iterator));
}
template <typename K, typename V> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::Hxx1::Fn<S>::Reset() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); MapInterface* o_ = (MapInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { DebugStop(); return maxon::PrivateLogNullptrError(); } 
	((MapInterface::MTable*) (o_->_vtableCls + 1))[-1].MapInterface_Reset(o_);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename K, typename V> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::Hxx1::COWFn<S>::Reset() -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); MapInterface* o_ = (MapInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	((MapInterface::MTable*) (o_->_vtableCls + 1))[-1].MapInterface_Reset(o_);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename K, typename V> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::Hxx1::Fn<S>::Flush() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); MapInterface* o_ = (MapInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { DebugStop(); return maxon::PrivateLogNullptrError(); } 
	((MapInterface::MTable*) (o_->_vtableCls + 1))[-1].MapInterface_Flush(o_);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename K, typename V> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::Hxx1::COWFn<S>::Flush() -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); MapInterface* o_ = (MapInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	((MapInterface::MTable*) (o_->_vtableCls + 1))[-1].MapInterface_Flush(o_);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename K, typename V> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::Hxx1::Fn<S>::CopyFrom(const MapInterface& other) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); MapInterface* o_ = (MapInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (((MapInterface::MTable*) (o_->_vtableCls + 1))[-1].MapInterface_CopyFrom(o_, other));
}
template <typename K, typename V> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::Hxx1::COWFn<S>::CopyFrom(const MapInterface& other) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); MapInterface* o_ = (MapInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (((MapInterface::MTable*) (o_->_vtableCls + 1))[-1].MapInterface_CopyFrom(o_, other));
}
template <typename K, typename V> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::Hxx1::ConstFn<S>::Clone(Bool copyContent) const -> Result<MapInterface*>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<MapInterface*>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const MapInterface* o_ = (const MapInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = MapInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (((MapInterface::MTable*) (o_->_vtableCls + 1))[-1].MapInterface_Clone(o_, copyContent));
}
template <typename K, typename V> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::Hxx1::ConstFn<S>::GetKeyDataType() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const DataType&>, const DataType&>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const DataType&>, const DataType&>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const MapInterface* o_ = (const MapInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = MapInterface::NullValuePtr(); if (!o_) return maxon::PrivateNullReturnValue<const DataType&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (((MapInterface::MTable*) (o_->_vtableCls + 1))[-1].MapInterface_GetKeyDataType(o_));
}
template <typename K, typename V> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::Hxx1::ConstFn<S>::GetValueDataType() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const DataType&>, const DataType&>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const DataType&>, const DataType&>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const MapInterface* o_ = (const MapInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = MapInterface::NullValuePtr(); if (!o_) return maxon::PrivateNullReturnValue<const DataType&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (((MapInterface::MTable*) (o_->_vtableCls + 1))[-1].MapInterface_GetValueDataType(o_));
}
template <typename K, typename V> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::Hxx1::ConstFn<S>::ToString(const FormatStatement* formatStatement) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const MapInterface* o_ = (const MapInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = MapInterface::NullValuePtr(); if (!o_) return maxon::PrivateNullReturnValue<String>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (((MapInterface::MTable*) (o_->_vtableCls + 1))[-1].MapInterface_ToString(o_, formatStatement));
}
template <typename K, typename V> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::Hxx1::ConstFn<S>::GetMemorySize() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const MapInterface* o_ = (const MapInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = MapInterface::NullValuePtr(); if (!o_) return 0; } 
	return (((MapInterface::MTable*) (o_->_vtableCls + 1))[-1].MapInterface_GetMemorySize(o_));
}
template <typename K, typename V> template <typename S> template <typename KT, typename VT> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::Hxx1::ConstFn<S>::HasType() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const MapInterface* o_ = (const MapInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = MapInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (o_->HasType<KT, VT>());
}
template <typename K, typename V> template <typename S> template <typename KT, typename VT> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::Hxx1::ConstFn<S>::AssertType() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
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

