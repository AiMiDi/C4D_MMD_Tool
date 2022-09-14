
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
	PRIVATE_MAXON_MF_POINTER(MapInterface_GetCount, GetCount, false, MapInterface, const, (Int));
	PRIVATE_MAXON_MF_POINTER(MapInterface_InsertKey, InsertKey, false, MapInterface,, (ResultRef<V>), const K& key, Bool& created);
	PRIVATE_MAXON_MF_POINTER(MapInterface_InsertKey_1, InsertKey, false, MapInterface,, (ResultRef<V>), K&& key, Bool& created);
	PRIVATE_MAXON_MF_POINTER(MapInterface_FindValue, FindValue, false, MapInterface,, (V*), const K& key);
	PRIVATE_MAXON_MF_POINTER(MapInterface_FindValue_1, FindValue, false, MapInterface, const, (const V*), const K& key);
	PRIVATE_MAXON_MF_POINTER(MapInterface_Erase, Erase, false, MapInterface,, (Result<Bool>), const K& key);
	PRIVATE_MAXON_MF_POINTER(MapInterface_Erase_1, Erase, false, MapInterface,, (Iterator), const Iterator& iterator);
	PRIVATE_MAXON_MF_POINTER(MapInterface_Reset, Reset, false, MapInterface,, (void));
	PRIVATE_MAXON_MF_POINTER(MapInterface_Flush, Flush, false, MapInterface,, (void));
	PRIVATE_MAXON_MF_POINTER(MapInterface_CopyFrom, CopyFrom, false, MapInterface,, (Result<void>), const MapInterface& other);
	PRIVATE_MAXON_MF_POINTER(MapInterface_Clone, Clone, false, MapInterface, const, (Result<MapInterface*>), Bool copyContent);
	PRIVATE_MAXON_MF_POINTER(MapInterface_GetKeyDataType, GetKeyDataType, false, MapInterface, const, (const DataType&));
	PRIVATE_MAXON_MF_POINTER(MapInterface_GetValueDataType, GetValueDataType, false, MapInterface, const, (const DataType&));
	PRIVATE_MAXON_MF_POINTER(MapInterface_ToString, ToString, false, MapInterface, const, (String), const FormatStatement* formatStatement);
	PRIVATE_MAXON_MF_POINTER(MapInterface_GetMemorySize, GetMemorySize, false, MapInterface, const, (Int));
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
	PRIVATE_MAXON_MF_POINTER(MapInterface_IteratorInit, IteratorInit, false, MapInterface,, (void), Iterator* it, Bool end);
	PRIVATE_MAXON_MF_POINTER(MapInterface_IteratorInit_1, IteratorInit, false, MapInterface, const, (void), ConstIterator* it, Bool end);
	PRIVATE_MAXON_MF_POINTER(MapInterface_IteratorInitMove, IteratorInitMove, false, MapInterface, const, (void), Iterator* dest, Iterator* src);
	PRIVATE_MAXON_MF_POINTER(MapInterface_IteratorInitMove_1, IteratorInitMove, false, MapInterface, const, (void), ConstIterator* dest, ConstIterator* src);
	PRIVATE_MAXON_MF_POINTER(MapInterface_IteratorFree, IteratorFree, false, MapInterface, const, (void), Iterator* it);
	PRIVATE_MAXON_MF_POINTER(MapInterface_IteratorFree_1, IteratorFree, false, MapInterface, const, (void), ConstIterator* it);
	PRIVATE_MAXON_MF_POINTER(MapInterface_IteratorIsEqual, IteratorIsEqual, false, MapInterface, const, (Bool), const Iterator* a, const Iterator* b);
	PRIVATE_MAXON_MF_POINTER(MapInterface_IteratorIsEqual_1, IteratorIsEqual, false, MapInterface, const, (Bool), const ConstIterator* a, const ConstIterator* b);
	PRIVATE_MAXON_MF_POINTER(MapInterface_IteratorInc, IteratorInc, false, MapInterface, const, (void), Iterator* it);
	PRIVATE_MAXON_MF_POINTER(MapInterface_IteratorInc_1, IteratorInc, false, MapInterface, const, (void), ConstIterator* it);
	PRIVATE_MAXON_MF_POINTER(MapInterface_IteratorGet, IteratorGet, false, MapInterface, const, (Pair<const K&, V&>), const Iterator* it);
	PRIVATE_MAXON_MF_POINTER(MapInterface_IteratorGet_1, IteratorGet, false, MapInterface, const, (Pair<const K&, const V&>), const ConstIterator* it);
	maxon::ClassInfoBase _info;
	template <typename IMPL> void Init()
	{
		void (*free) (const MapInterface*) = &IMPL::Implementation::Free;
		_info._free = reinterpret_cast<void(*)(const void*)>(free);
		_info.PrivateInitName(maxon::details::GetTypeNameHelper<typename IMPL::Implementation>());
		MapInterface_GetCount = MapInterface_GetCount_GetPtr<IMPL>(0, true).first;
		MapInterface_InsertKey = MapInterface_InsertKey_GetPtr<IMPL>(0, true).first;
		MapInterface_InsertKey_1 = MapInterface_InsertKey_1_GetPtr<IMPL>(0, true).first;
		MapInterface_FindValue = MapInterface_FindValue_GetPtr<IMPL>(0, true).first;
		MapInterface_FindValue_1 = MapInterface_FindValue_1_GetPtr<IMPL>(0, true).first;
		MapInterface_Erase = MapInterface_Erase_GetPtr<IMPL>(0, true).first;
		MapInterface_Erase_1 = MapInterface_Erase_1_GetPtr<IMPL>(0, true).first;
		MapInterface_Reset = MapInterface_Reset_GetPtr<IMPL>(0, true).first;
		MapInterface_Flush = MapInterface_Flush_GetPtr<IMPL>(0, true).first;
		MapInterface_CopyFrom = MapInterface_CopyFrom_GetPtr<IMPL>(0, true).first;
		MapInterface_Clone = MapInterface_Clone_GetPtr<IMPL>(0, true).first;
		MapInterface_GetKeyDataType = MapInterface_GetKeyDataType_GetPtr<IMPL>(0, true).first;
		MapInterface_GetValueDataType = MapInterface_GetValueDataType_GetPtr<IMPL>(0, true).first;
		MapInterface_ToString = MapInterface_ToString_GetPtr<IMPL>(0, true).first;
		MapInterface_GetMemorySize = MapInterface_GetMemorySize_GetPtr<IMPL>(0, true).first;
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
		MapInterface_IteratorInit = MapInterface_IteratorInit_GetPtr<IMPL>(0, true).first;
		MapInterface_IteratorInit_1 = MapInterface_IteratorInit_1_GetPtr<IMPL>(0, true).first;
		MapInterface_IteratorInitMove = MapInterface_IteratorInitMove_GetPtr<IMPL>(0, true).first;
		MapInterface_IteratorInitMove_1 = MapInterface_IteratorInitMove_1_GetPtr<IMPL>(0, true).first;
		MapInterface_IteratorFree = MapInterface_IteratorFree_GetPtr<IMPL>(0, true).first;
		MapInterface_IteratorFree_1 = MapInterface_IteratorFree_1_GetPtr<IMPL>(0, true).first;
		MapInterface_IteratorIsEqual = MapInterface_IteratorIsEqual_GetPtr<IMPL>(0, true).first;
		MapInterface_IteratorIsEqual_1 = MapInterface_IteratorIsEqual_1_GetPtr<IMPL>(0, true).first;
		MapInterface_IteratorInc = MapInterface_IteratorInc_GetPtr<IMPL>(0, true).first;
		MapInterface_IteratorInc_1 = MapInterface_IteratorInc_1_GetPtr<IMPL>(0, true).first;
		MapInterface_IteratorGet = MapInterface_IteratorGet_GetPtr<IMPL>(0, true).first;
		MapInterface_IteratorGet_1 = MapInterface_IteratorGet_1_GetPtr<IMPL>(0, true).first;
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
		PRIVATE_MAXON_MF_WRAPPER(MapInterface_GetCount, MapInterface, const, (Int)) { return C::Get(PRIVATE_MAXON_MF_THIS(const MapInterface))->GetCount(); }
		PRIVATE_MAXON_MF_WRAPPER(MapInterface_InsertKey, MapInterface,, (ResultRef<V>), const K& key, Bool& created) { return C::Get(PRIVATE_MAXON_MF_THIS(MapInterface))->InsertKey(key, created); }
		PRIVATE_MAXON_MF_WRAPPER(MapInterface_InsertKey_1, MapInterface,, (ResultRef<V>), K&& key, Bool& created) { return C::Get(PRIVATE_MAXON_MF_THIS(MapInterface))->InsertKey(std::forward<K>(key), created); }
		PRIVATE_MAXON_MF_WRAPPER(MapInterface_FindValue, MapInterface,, (V*), const K& key) { return C::Get(PRIVATE_MAXON_MF_THIS(MapInterface))->FindValue(key); }
		PRIVATE_MAXON_MF_WRAPPER(MapInterface_FindValue_1, MapInterface, const, (const V*), const K& key) { return C::Get(PRIVATE_MAXON_MF_THIS(const MapInterface))->FindValue(key); }
		PRIVATE_MAXON_MF_WRAPPER(MapInterface_Erase, MapInterface,, (Result<Bool>), const K& key) { return C::Get(PRIVATE_MAXON_MF_THIS(MapInterface))->Erase(key); }
		PRIVATE_MAXON_MF_WRAPPER(MapInterface_Erase_1, MapInterface,, (Iterator), const Iterator& iterator) { return C::Get(PRIVATE_MAXON_MF_THIS(MapInterface))->Erase(iterator); }
		PRIVATE_MAXON_MF_WRAPPER(MapInterface_Reset, MapInterface,, (void)) { return C::Get(PRIVATE_MAXON_MF_THIS(MapInterface))->Reset(); }
		PRIVATE_MAXON_MF_WRAPPER(MapInterface_Flush, MapInterface,, (void)) { return C::Get(PRIVATE_MAXON_MF_THIS(MapInterface))->Flush(); }
		PRIVATE_MAXON_MF_WRAPPER(MapInterface_CopyFrom, MapInterface,, (Result<void>), const MapInterface& other) { return C::Get(PRIVATE_MAXON_MF_THIS(MapInterface))->CopyFrom(other); }
		PRIVATE_MAXON_MF_WRAPPER(MapInterface_Clone, MapInterface, const, (Result<MapInterface*>), Bool copyContent) { return C::Get(PRIVATE_MAXON_MF_THIS(const MapInterface))->Clone(copyContent); }
		PRIVATE_MAXON_MF_WRAPPER(MapInterface_GetKeyDataType, MapInterface, const, (const DataType&)) { return C::Get(PRIVATE_MAXON_MF_THIS(const MapInterface))->GetKeyDataType(); }
		PRIVATE_MAXON_MF_WRAPPER(MapInterface_GetValueDataType, MapInterface, const, (const DataType&)) { return C::Get(PRIVATE_MAXON_MF_THIS(const MapInterface))->GetValueDataType(); }
		PRIVATE_MAXON_MF_WRAPPER(MapInterface_ToString, MapInterface, const, (String), const FormatStatement* formatStatement) { return C::Get(PRIVATE_MAXON_MF_THIS(const MapInterface))->ToString(formatStatement); }
		PRIVATE_MAXON_MF_WRAPPER(MapInterface_GetMemorySize, MapInterface, const, (Int)) { return C::Get(PRIVATE_MAXON_MF_THIS(const MapInterface))->GetMemorySize(); }
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
		PRIVATE_MAXON_MF_WRAPPER(MapInterface_IteratorInit, MapInterface,, (void), Iterator* it, Bool end) { return C::Get(PRIVATE_MAXON_MF_THIS(MapInterface))->IteratorInit(it, end); }
		PRIVATE_MAXON_MF_WRAPPER(MapInterface_IteratorInit_1, MapInterface, const, (void), ConstIterator* it, Bool end) { return C::Get(PRIVATE_MAXON_MF_THIS(const MapInterface))->IteratorInit(it, end); }
		PRIVATE_MAXON_MF_WRAPPER(MapInterface_IteratorInitMove, MapInterface, const, (void), Iterator* dest, Iterator* src) { return C::Get(PRIVATE_MAXON_MF_THIS(const MapInterface))->IteratorInitMove(dest, src); }
		PRIVATE_MAXON_MF_WRAPPER(MapInterface_IteratorInitMove_1, MapInterface, const, (void), ConstIterator* dest, ConstIterator* src) { return C::Get(PRIVATE_MAXON_MF_THIS(const MapInterface))->IteratorInitMove(dest, src); }
		PRIVATE_MAXON_MF_WRAPPER(MapInterface_IteratorFree, MapInterface, const, (void), Iterator* it) { return C::Get(PRIVATE_MAXON_MF_THIS(const MapInterface))->IteratorFree(it); }
		PRIVATE_MAXON_MF_WRAPPER(MapInterface_IteratorFree_1, MapInterface, const, (void), ConstIterator* it) { return C::Get(PRIVATE_MAXON_MF_THIS(const MapInterface))->IteratorFree(it); }
		PRIVATE_MAXON_MF_WRAPPER(MapInterface_IteratorIsEqual, MapInterface, const, (Bool), const Iterator* a, const Iterator* b) { return C::Get(PRIVATE_MAXON_MF_THIS(const MapInterface))->IteratorIsEqual(a, b); }
		PRIVATE_MAXON_MF_WRAPPER(MapInterface_IteratorIsEqual_1, MapInterface, const, (Bool), const ConstIterator* a, const ConstIterator* b) { return C::Get(PRIVATE_MAXON_MF_THIS(const MapInterface))->IteratorIsEqual(a, b); }
		PRIVATE_MAXON_MF_WRAPPER(MapInterface_IteratorInc, MapInterface, const, (void), Iterator* it) { return C::Get(PRIVATE_MAXON_MF_THIS(const MapInterface))->IteratorInc(it); }
		PRIVATE_MAXON_MF_WRAPPER(MapInterface_IteratorInc_1, MapInterface, const, (void), ConstIterator* it) { return C::Get(PRIVATE_MAXON_MF_THIS(const MapInterface))->IteratorInc(it); }
		PRIVATE_MAXON_MF_WRAPPER(MapInterface_IteratorGet, MapInterface, const, (Pair<const K&, V&>), const Iterator* it) { return C::Get(PRIVATE_MAXON_MF_THIS(const MapInterface))->IteratorGet(it); }
		PRIVATE_MAXON_MF_WRAPPER(MapInterface_IteratorGet_1, MapInterface, const, (Pair<const K&, const V&>), const ConstIterator* it) { return C::Get(PRIVATE_MAXON_MF_THIS(const MapInterface))->IteratorGet(it); }
	};

};
template <typename K, typename V> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::GetCount() const -> Int
{
	return PRIVATE_MAXON_MF_INVOKE((this), ((MapInterface::MTable*) (this->_vtableCls + 1))[-1].MapInterface_GetCount);
}
template <typename K, typename V> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::InsertKey(const K& key, Bool& created) -> ResultRef<V>
{
	return PRIVATE_MAXON_MF_INVOKE((this), ((MapInterface::MTable*) (this->_vtableCls + 1))[-1].MapInterface_InsertKey, key, created);
}
template <typename K, typename V> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::InsertKey(K&& key, Bool& created) -> ResultRef<V>
{
	return PRIVATE_MAXON_MF_INVOKE((this), ((MapInterface::MTable*) (this->_vtableCls + 1))[-1].MapInterface_InsertKey_1, std::forward<K>(key), created);
}
template <typename K, typename V> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::FindValue(const K& key) -> V*
{
	return PRIVATE_MAXON_MF_INVOKE((this), ((MapInterface::MTable*) (this->_vtableCls + 1))[-1].MapInterface_FindValue, key);
}
template <typename K, typename V> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::FindValue(const K& key) const -> const V*
{
	return PRIVATE_MAXON_MF_INVOKE((this), ((MapInterface::MTable*) (this->_vtableCls + 1))[-1].MapInterface_FindValue_1, key);
}
template <typename K, typename V> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::Erase(const K& key) -> Result<Bool>
{
	return PRIVATE_MAXON_MF_INVOKE((this), ((MapInterface::MTable*) (this->_vtableCls + 1))[-1].MapInterface_Erase, key);
}
template <typename K, typename V> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::Erase(const Iterator& iterator) -> Iterator
{
	return PRIVATE_MAXON_MF_INVOKE((this), ((MapInterface::MTable*) (this->_vtableCls + 1))[-1].MapInterface_Erase_1, iterator);
}
template <typename K, typename V> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::Reset() -> void
{
	return PRIVATE_MAXON_MF_INVOKE((this), ((MapInterface::MTable*) (this->_vtableCls + 1))[-1].MapInterface_Reset);
}
template <typename K, typename V> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::Flush() -> void
{
	return PRIVATE_MAXON_MF_INVOKE((this), ((MapInterface::MTable*) (this->_vtableCls + 1))[-1].MapInterface_Flush);
}
template <typename K, typename V> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::CopyFrom(const MapInterface& other) -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((this), ((MapInterface::MTable*) (this->_vtableCls + 1))[-1].MapInterface_CopyFrom, other);
}
template <typename K, typename V> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::Clone(Bool copyContent) const -> Result<MapInterface*>
{
	return PRIVATE_MAXON_MF_INVOKE((this), ((MapInterface::MTable*) (this->_vtableCls + 1))[-1].MapInterface_Clone, copyContent);
}
template <typename K, typename V> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::GetKeyDataType() const -> const DataType&
{
	return PRIVATE_MAXON_MF_INVOKE((this), ((MapInterface::MTable*) (this->_vtableCls + 1))[-1].MapInterface_GetKeyDataType);
}
template <typename K, typename V> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::GetValueDataType() const -> const DataType&
{
	return PRIVATE_MAXON_MF_INVOKE((this), ((MapInterface::MTable*) (this->_vtableCls + 1))[-1].MapInterface_GetValueDataType);
}
template <typename K, typename V> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::ToString(const FormatStatement* formatStatement) const -> String
{
	return PRIVATE_MAXON_MF_INVOKE((this), ((MapInterface::MTable*) (this->_vtableCls + 1))[-1].MapInterface_ToString, formatStatement);
}
template <typename K, typename V> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::GetMemorySize() const -> Int
{
	return PRIVATE_MAXON_MF_INVOKE((this), ((MapInterface::MTable*) (this->_vtableCls + 1))[-1].MapInterface_GetMemorySize);
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
	return PRIVATE_MAXON_MF_INVOKE((this), ((MapInterface::MTable*) (this->_vtableCls + 1))[-1].MapInterface_IteratorInit, it, end);
}
template <typename K, typename V> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::IteratorInit(ConstIterator* it, Bool end) const -> void
{
	return PRIVATE_MAXON_MF_INVOKE((this), ((MapInterface::MTable*) (this->_vtableCls + 1))[-1].MapInterface_IteratorInit_1, it, end);
}
template <typename K, typename V> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::IteratorInitMove(Iterator* dest, Iterator* src) const -> void
{
	return PRIVATE_MAXON_MF_INVOKE((this), ((MapInterface::MTable*) (this->_vtableCls + 1))[-1].MapInterface_IteratorInitMove, dest, src);
}
template <typename K, typename V> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::IteratorInitMove(ConstIterator* dest, ConstIterator* src) const -> void
{
	return PRIVATE_MAXON_MF_INVOKE((this), ((MapInterface::MTable*) (this->_vtableCls + 1))[-1].MapInterface_IteratorInitMove_1, dest, src);
}
template <typename K, typename V> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::IteratorFree(Iterator* it) const -> void
{
	return PRIVATE_MAXON_MF_INVOKE((this), ((MapInterface::MTable*) (this->_vtableCls + 1))[-1].MapInterface_IteratorFree, it);
}
template <typename K, typename V> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::IteratorFree(ConstIterator* it) const -> void
{
	return PRIVATE_MAXON_MF_INVOKE((this), ((MapInterface::MTable*) (this->_vtableCls + 1))[-1].MapInterface_IteratorFree_1, it);
}
template <typename K, typename V> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::IteratorIsEqual(const Iterator* a, const Iterator* b) const -> Bool
{
	return PRIVATE_MAXON_MF_INVOKE((this), ((MapInterface::MTable*) (this->_vtableCls + 1))[-1].MapInterface_IteratorIsEqual, a, b);
}
template <typename K, typename V> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::IteratorIsEqual(const ConstIterator* a, const ConstIterator* b) const -> Bool
{
	return PRIVATE_MAXON_MF_INVOKE((this), ((MapInterface::MTable*) (this->_vtableCls + 1))[-1].MapInterface_IteratorIsEqual_1, a, b);
}
template <typename K, typename V> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::IteratorInc(Iterator* it) const -> void
{
	return PRIVATE_MAXON_MF_INVOKE((this), ((MapInterface::MTable*) (this->_vtableCls + 1))[-1].MapInterface_IteratorInc, it);
}
template <typename K, typename V> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::IteratorInc(ConstIterator* it) const -> void
{
	return PRIVATE_MAXON_MF_INVOKE((this), ((MapInterface::MTable*) (this->_vtableCls + 1))[-1].MapInterface_IteratorInc_1, it);
}
template <typename K, typename V> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::IteratorGet(const Iterator* it) const -> Pair<const K&, V&>
{
	return PRIVATE_MAXON_MF_INVOKE((this), ((MapInterface::MTable*) (this->_vtableCls + 1))[-1].MapInterface_IteratorGet, it);
}
template <typename K, typename V> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::IteratorGet(const ConstIterator* it) const -> Pair<const K&, const V&>
{
	return PRIVATE_MAXON_MF_INVOKE((this), ((MapInterface::MTable*) (this->_vtableCls + 1))[-1].MapInterface_IteratorGet_1, it);
}

template <typename K, typename V> MapInterface<K, V>::MapInterface(const MTable& vtable) : _vtableCls(&vtable._info) { }
template <typename K, typename V> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::Hxx1::ConstFn<S>::GetCount() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const MapInterface* o_ = (const MapInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = MapInterface::NullValuePtr(); if (!o_) return 0; } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), ((MapInterface::MTable*) (o_->_vtableCls + 1))[-1].MapInterface_GetCount));
}
template <typename K, typename V> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::Hxx1::ConstFn<S>::IsEmpty() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const MapInterface* o_ = (const MapInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = MapInterface::NullValuePtr(); if (!o_) return true; } 
	return (o_->IsEmpty());
}
template <typename K, typename V> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::Hxx1::ConstFn<S>::IsPopulated() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const MapInterface* o_ = (const MapInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = MapInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (o_->IsPopulated());
}
template <typename K, typename V> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::Hxx1::Fn<S>::InsertKey(const K& key, Bool& created) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<V&>, ResultRef<V>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<V&>, ResultRef<V>>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); MapInterface* o_ = (MapInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateNullReturnValue<ResultRef<V>>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), ((MapInterface::MTable*) (o_->_vtableCls + 1))[-1].MapInterface_InsertKey, key, created));
}
template <typename K, typename V> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::Hxx1::COWFn<S>::InsertKey(const K& key, Bool& created) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultRef<V>, maxon::Result<V&>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultRef<V>, maxon::Result<V&>>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); MapInterface* o_ = (MapInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), ((MapInterface::MTable*) (o_->_vtableCls + 1))[-1].MapInterface_InsertKey, key, created));
}
template <typename K, typename V> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::Hxx1::Fn<S>::InsertKey(K&& key, Bool& created) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<V&>, ResultRef<V>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<V&>, ResultRef<V>>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); MapInterface* o_ = (MapInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateNullReturnValue<ResultRef<V>>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), ((MapInterface::MTable*) (o_->_vtableCls + 1))[-1].MapInterface_InsertKey_1, std::forward<K>(key), created));
}
template <typename K, typename V> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::Hxx1::COWFn<S>::InsertKey(K&& key, Bool& created) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultRef<V>, maxon::Result<V&>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultRef<V>, maxon::Result<V&>>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); MapInterface* o_ = (MapInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), ((MapInterface::MTable*) (o_->_vtableCls + 1))[-1].MapInterface_InsertKey_1, std::forward<K>(key), created));
}
template <typename K, typename V> template <typename S> template <typename VALUE> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::Hxx1::Fn<S>::Insert(const K& key, VALUE&& value, Bool& created) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<V&>, ResultRef<V>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<V&>, ResultRef<V>>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); MapInterface* o_ = (MapInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateNullReturnValue<ResultRef<V>>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (o_->Insert<VALUE>(key, std::forward<VALUE>(value), created));
}
template <typename K, typename V> template <typename S> template <typename VALUE> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::Hxx1::COWFn<S>::Insert(const K& key, VALUE&& value, Bool& created) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultRef<V>, maxon::Result<V&>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultRef<V>, maxon::Result<V&>>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); MapInterface* o_ = (MapInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (o_->Insert<VALUE>(key, std::forward<VALUE>(value), created));
}
template <typename K, typename V> template <typename S> template <typename VALUE> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::Hxx1::Fn<S>::Insert(K&& key, VALUE&& value, Bool& created) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<V&>, ResultRef<V>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<V&>, ResultRef<V>>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); MapInterface* o_ = (MapInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateNullReturnValue<ResultRef<V>>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (o_->Insert<VALUE>(std::forward<K>(key), std::forward<VALUE>(value), created));
}
template <typename K, typename V> template <typename S> template <typename VALUE> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::Hxx1::COWFn<S>::Insert(K&& key, VALUE&& value, Bool& created) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultRef<V>, maxon::Result<V&>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultRef<V>, maxon::Result<V&>>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); MapInterface* o_ = (MapInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (o_->Insert<VALUE>(std::forward<K>(key), std::forward<VALUE>(value), created));
}
template <typename K, typename V> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::Hxx1::Fn<S>::FindValue(const K& key) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<V*>, V*>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<V*>, V*>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); MapInterface* o_ = (MapInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return nullptr; } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), ((MapInterface::MTable*) (o_->_vtableCls + 1))[-1].MapInterface_FindValue, key));
}
template <typename K, typename V> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::Hxx1::ConstFn<S>::FindValue(const K& key) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const V*>, const V*>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const V*>, const V*>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const MapInterface* o_ = (const MapInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = MapInterface::NullValuePtr(); if (!o_) return nullptr; } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), ((MapInterface::MTable*) (o_->_vtableCls + 1))[-1].MapInterface_FindValue_1, key));
}
template <typename K, typename V> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::Hxx1::Fn<S>::Erase(const K& key) const -> Result<Bool>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Bool>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); MapInterface* o_ = (MapInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), ((MapInterface::MTable*) (o_->_vtableCls + 1))[-1].MapInterface_Erase, key));
}
template <typename K, typename V> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::Hxx1::COWFn<S>::Erase(const K& key) -> Result<Bool>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Bool>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); MapInterface* o_ = (MapInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), ((MapInterface::MTable*) (o_->_vtableCls + 1))[-1].MapInterface_Erase, key));
}
template <typename K, typename V> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::Hxx1::Fn<S>::Erase(const Iterator& iterator) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Iterator>, Iterator>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Iterator>, Iterator>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); MapInterface* o_ = (MapInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateNullReturnValue<Iterator>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), ((MapInterface::MTable*) (o_->_vtableCls + 1))[-1].MapInterface_Erase_1, iterator));
}
template <typename K, typename V> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::Hxx1::COWFn<S>::Erase(const Iterator& iterator) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Iterator, maxon::Result<Iterator>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Iterator, maxon::Result<Iterator>>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); MapInterface* o_ = (MapInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), ((MapInterface::MTable*) (o_->_vtableCls + 1))[-1].MapInterface_Erase_1, iterator));
}
template <typename K, typename V> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::Hxx1::Fn<S>::Reset() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); MapInterface* o_ = (MapInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { DebugStop(); return maxon::PrivateLogNullptrError(); } 
	PRIVATE_MAXON_MF_INVOKE((o_), ((MapInterface::MTable*) (o_->_vtableCls + 1))[-1].MapInterface_Reset);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename K, typename V> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::Hxx1::COWFn<S>::Reset() -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); MapInterface* o_ = (MapInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	PRIVATE_MAXON_MF_INVOKE((o_), ((MapInterface::MTable*) (o_->_vtableCls + 1))[-1].MapInterface_Reset);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename K, typename V> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::Hxx1::Fn<S>::Flush() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); MapInterface* o_ = (MapInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { DebugStop(); return maxon::PrivateLogNullptrError(); } 
	PRIVATE_MAXON_MF_INVOKE((o_), ((MapInterface::MTable*) (o_->_vtableCls + 1))[-1].MapInterface_Flush);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename K, typename V> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::Hxx1::COWFn<S>::Flush() -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); MapInterface* o_ = (MapInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	PRIVATE_MAXON_MF_INVOKE((o_), ((MapInterface::MTable*) (o_->_vtableCls + 1))[-1].MapInterface_Flush);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename K, typename V> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::Hxx1::Fn<S>::CopyFrom(const MapInterface& other) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); MapInterface* o_ = (MapInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), ((MapInterface::MTable*) (o_->_vtableCls + 1))[-1].MapInterface_CopyFrom, other));
}
template <typename K, typename V> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::Hxx1::COWFn<S>::CopyFrom(const MapInterface& other) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); MapInterface* o_ = (MapInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), ((MapInterface::MTable*) (o_->_vtableCls + 1))[-1].MapInterface_CopyFrom, other));
}
template <typename K, typename V> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::Hxx1::ConstFn<S>::Clone(Bool copyContent) const -> Result<MapInterface*>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<MapInterface*>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const MapInterface* o_ = (const MapInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = MapInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), ((MapInterface::MTable*) (o_->_vtableCls + 1))[-1].MapInterface_Clone, copyContent));
}
template <typename K, typename V> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::Hxx1::ConstFn<S>::GetKeyDataType() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const DataType&>, const DataType&>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const DataType&>, const DataType&>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const MapInterface* o_ = (const MapInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = MapInterface::NullValuePtr(); if (!o_) return maxon::PrivateNullReturnValue<const DataType&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), ((MapInterface::MTable*) (o_->_vtableCls + 1))[-1].MapInterface_GetKeyDataType));
}
template <typename K, typename V> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::Hxx1::ConstFn<S>::GetValueDataType() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const DataType&>, const DataType&>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const DataType&>, const DataType&>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const MapInterface* o_ = (const MapInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = MapInterface::NullValuePtr(); if (!o_) return maxon::PrivateNullReturnValue<const DataType&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), ((MapInterface::MTable*) (o_->_vtableCls + 1))[-1].MapInterface_GetValueDataType));
}
template <typename K, typename V> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::Hxx1::ConstFn<S>::ToString(const FormatStatement* formatStatement) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const MapInterface* o_ = (const MapInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = MapInterface::NullValuePtr(); if (!o_) return maxon::PrivateNullReturnValue<String>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), ((MapInterface::MTable*) (o_->_vtableCls + 1))[-1].MapInterface_ToString, formatStatement));
}
template <typename K, typename V> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::Hxx1::ConstFn<S>::GetMemorySize() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const MapInterface* o_ = (const MapInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = MapInterface::NullValuePtr(); if (!o_) return 0; } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), ((MapInterface::MTable*) (o_->_vtableCls + 1))[-1].MapInterface_GetMemorySize));
}
template <typename K, typename V> template <typename S> template <typename KT, typename VT> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::Hxx1::ConstFn<S>::HasType() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const MapInterface* o_ = (const MapInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = MapInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (o_->HasType<KT, VT>());
}
template <typename K, typename V> template <typename S> template <typename KT, typename VT> MAXON_ATTRIBUTE_FORCE_INLINE auto MapInterface<K, V>::Hxx1::ConstFn<S>::AssertType() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const MapInterface* o_ = (const MapInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = MapInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(); } 
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

