#ifndef SET_H__
#define SET_H__

#include "maxon/string.h"
#include "maxon/datatype.h"

namespace maxon
{

template <typename TYPE> class NonConstSet;


//----------------------------------------------------------------------------------------
/// SetInterface is an interface which provides the usual set functions as virtual methods.
/// Each standard set of the MAXON API can be represented as such an interface, so this
/// allows to write non-template functions which nevertheless are able to deal with any kind
/// of set.
///
/// The access to the set happens via virtual methods, so there is an inevitable performance
/// penalty, but this will be negligible for most use cases.
///
/// For a set which shall be modified, use WritableSetInterface as type of the function parameter instead.
///
/// @tparam TYPE									Type of elements of the set.
//----------------------------------------------------------------------------------------
template <typename TYPE> class SetInterface : public SetBase0<SetInterface<TYPE>, TYPE, EmptyClass, DefaultCompare>
{
# ifdef CPP_853_HACK // use space after # so that the source processor doesn't recognize those directives
	CPP_853_HACK_MAXON_INTERFACE_SIMPLE_VIRTUAL(SetInterface, MAXON_REFERENCE_COPY_ON_WRITE);
# else
	MAXON_INTERFACE_SIMPLE_VIRTUAL(SetInterface, MAXON_REFERENCE_COPY_ON_WRITE);
# endif

public:
	using ValueType = TYPE;

	template <Bool CONSTITERATOR> class IteratorTemplate;
	using Iterator = IteratorTemplate<false>;
	using ConstIterator = IteratorTemplate<true>;

	//----------------------------------------------------------------------------------------
	/// Gets the number of set elements.
	/// @return												Number of set elements.
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
	/// Checks if this set contains @p value.
	/// @param[in] value							The value to check.
	/// @return												True if this set contains @p value.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Bool Contains(const TYPE& value) const;

	//----------------------------------------------------------------------------------------
	/// Adds @p value to this set. If @p value is already contained in this set, nothing happens,
	/// and @p added is set to @c false.
	/// @param[in] value							Value to add to this set.
	/// @param[out] added							This will be set to true if the element didn't exist before in the set and it could be added successfully, otherwise it will be set to false.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Insert(const TYPE& value, Bool& added = BoolLValue());

	//----------------------------------------------------------------------------------------
	/// Adds @p value to this set. If @p value is already contained in this set, nothing happens,
	/// and @p added is set to @c false.
	/// @param[in] value							Value to add to this set. When a new element has to be added, @p value will be moved into the new element.
	/// @param[out] added							This will be set to true if the element didn't exist before in the set and it could be added successfully, otherwise it will be set to false.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Insert(TYPE&& value, Bool& added = BoolLValue());

	//----------------------------------------------------------------------------------------
	/// Remove @p value from this set. If @p value isn't contained in this set, nothing happens.
	/// @param[in] value							Value to remove from this set.
	/// @return												True if an entry was found and removed for #value, otherwise false or an error if a memory allocation failed.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Bool> Erase(const TYPE& value);

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
	/// Sets this set to a copy of the given other set.
	/// @param[in] other							Source set.
	/// @return												Success of operation.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> CopyFrom(const SetInterface& other);

	//----------------------------------------------------------------------------------------
	/// Returns a clone of this set.
	/// @param[in] cloneElements			True if also the elements shall be cloned, false otherwise (then just a new object sharing the same SetInterface implementation is created).
	/// @return												Pointer to the new set object, nullptr if allocation or copying failed.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<SetInterface*> Clone(Bool cloneElements = true) const;

	//----------------------------------------------------------------------------------------
	/// Returns the data type of this set's elements. This may be nullptr if there is no
	/// DataType for the template parameter TYPE.
	/// @return												DataType of the elements or nullptr.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD const DataType& GetValueDataType() const;

	//----------------------------------------------------------------------------------------
	/// @param[in] formatStatement		Nullptr or additional formatting instruction. Currently no additional formatting instructions are supported.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD String ToString(const FormatStatement* formatStatement) const;

	//----------------------------------------------------------------------------------------
	/// Calculates the memory usage for this set.
	/// @return												Memory size in bytes.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Int GetMemorySize() const;

	MAXON_ADD_TO_CONST_REFERENCE_CLASS(UInt GetHashCode() const { CriticalStop("Not implemented."); return 0; };);

	template <typename T> MAXON_FUNCTION Bool HasType() const
	{
		return GetValueDataType() == maxon::GetDataType<T>();
	}

	//----------------------------------------------------------------------------------------
	/// Issues a failed DebugAssert if the DataType of this set doesn't match T. If T is Generic,
	/// no check happens.
	/// @tparam T											Type to check.
	//----------------------------------------------------------------------------------------
	template <typename T> MAXON_FUNCTION void AssertType() const
	{
#ifdef MAXON_TARGET_DEBUG
		if (!std::is_same<Generic, T>::value)
		{
			GetValueDataType().template AssertType<typename std::conditional<std::is_same<Generic, T>::value, Int, T>::type>();
		}
#endif
	}

	//----------------------------------------------------------------------------------------
	/// Casts this set to a set with elements of type T. If T doesn't match the actual data type of this
	/// set, a failed DebugAssert is issued. This function only makes sense when the original set
	/// uses Generic as its type.
	/// @tparam T											Element type of the destination set.
	/// @return												This set, cast to a SetInterface of T elements.
	//----------------------------------------------------------------------------------------
	template <typename T> SetInterface<T>& AssertCast()
	{
		AssertType<T>();
		return *reinterpret_cast<SetInterface<T>*>(this);
	}

	//----------------------------------------------------------------------------------------
	/// Casts this set to a set with elements of type T. If T doesn't match the actual data type of this
	/// set, a failed DebugAssert is issued. This function only makes sense when the original set
	/// uses Generic as its type.
	/// @tparam T											Element type of the destination set.
	/// @return												This set, cast to a SetInterface of T elements.
	//----------------------------------------------------------------------------------------
	template <typename T> const SetInterface<T>& AssertCast() const
	{
		AssertType<T>();
		return *reinterpret_cast<const SetInterface<T>*>(this);
	}

#ifdef MAXON_COMPILER_INTEL
#pragma warning disable 597
#endif
	operator const SetInterface<typename std::conditional<std::is_same<const TYPE, const Generic>::value, const DummyReturnType, Generic>::type>&() const
	{
		return *(SetInterface<typename std::conditional<std::is_same<const TYPE, const Generic>::value, const DummyReturnType, Generic>::type>*) this;
	}

	operator SetInterface<typename std::conditional<std::is_same<TYPE, Generic>::value, volatile DummyReturnType, Generic>::type>&()
	{
		return *(SetInterface<typename std::conditional<std::is_same<TYPE, Generic>::value, volatile DummyReturnType, Generic>::type>*) this;
	}
#ifdef MAXON_COMPILER_INTEL
#pragma warning enable 597
#endif

	operator const NonConstSet<TYPE>&()
	{
		return *reinterpret_cast<const NonConstSet<TYPE>*>(this);
	}

	operator const NonConstSet<typename std::conditional<std::is_same<TYPE, Generic>::value, DummyReturnType, Generic>::type>&()
	{
		return *reinterpret_cast<const NonConstSet<typename std::conditional<std::is_same<TYPE, Generic>::value, DummyReturnType, Generic>::type>*>(this);
	}

	template <Bool CONSTITERATOR> class IteratorTemplate
	{
	public:
		using CollectionType = typename ConstIf<SetInterface, CONSTITERATOR>::type;
		using Type = const TYPE;

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

		Type& operator *() const
		{
			return *this->operator ->();
		}

		Type* operator ->() const
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

		using Memory = Int[64];

		const void* GetMemory() const
		{
			return _memory;
		}

		void* GetMemory()
		{
			return _memory;
		}

	private:
		MAXON_DISALLOW_COPY_AND_ASSIGN(IteratorTemplate);

		CollectionType* _set;
		Memory _memory;
	};

	//----------------------------------------------------------------------------------------
	/// Returns an iterator pointing to the first set element.
	/// @return												Iterator for the first element (equal to End() if the set is empty).
	//----------------------------------------------------------------------------------------
	ConstIterator Begin() const
	{
		MAXON_ASSERT_STANDARD_LAYOUT(ConstIterator);
		return ConstIterator(*static_cast<const SetInterface*>(this), false);
	}

	//----------------------------------------------------------------------------------------
	/// Returns an iterator pointing to the first set element.
	/// @return												Iterator for the first element (equal to End() if the set is empty).
	//----------------------------------------------------------------------------------------
	Iterator Begin()
	{
		MAXON_ASSERT_STANDARD_LAYOUT(Iterator);
		return Iterator(*static_cast<SetInterface*>(this), false);
	}

	//----------------------------------------------------------------------------------------
	/// Returns an iterator pointing one behind the last set element.
	/// @return												Iterator for the set end, this is one behind the last element.
	//----------------------------------------------------------------------------------------
	ConstIterator End() const
	{
		return ConstIterator(*static_cast<const SetInterface*>(this), true);
	}

	//----------------------------------------------------------------------------------------
	/// Returns an iterator pointing one behind the last set element.
	/// @return												Iterator for the set end, this is one behind the last element.
	//----------------------------------------------------------------------------------------
	Iterator End()
	{
		return Iterator(*static_cast<SetInterface*>(this), true);
	}

#ifdef CPP_853_HACK
#ifdef MAXON_COMPILER_GCC
	SetInterface(const SetInterface& src) // GCC constructs from the conversion result, upcasted to SetInterface&
#else
private:
	SetInterface(const SetInterface& src);
public:
	template <typename SET> MAXON_IMPLICIT SetInterface(const SetImpl<SET>& src) // MSVC constructs directly from the conversion result, which allows a more type-safe hack
#endif
		: _vtable(src._vtable), _refDummy(src._refDummy)
	{
	}
#endif

protected:
	template <typename SET> friend class SetImpl;
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

	MAXON_METHOD const TYPE* IteratorGet(const Iterator* it) const;

	MAXON_METHOD const TYPE* IteratorGet(const ConstIterator* it) const;

	static SetInterface* Alloc(MAXON_SOURCE_LOCATION_DECLARATION)
	{
		return nullptr;
	}

	static SetInterface* Alloc(MAXON_SOURCE_LOCATION_DECLARATION, const SetInterface& src)
	{
		iferr (SetInterface* a = src.Clone(true))
			return nullptr;
		return a;
	}
};

// Helper class for the WritableSetInterface macro.
// A WritableSetInterface& parameter is actually a const NonConstSet& parameter,
// so temporary objects resulting from a conversion of some set to the NonConstSet interface may be bound to such a parameter
// (this wouldn't be possible if the parameter was non-const).
// To be able to invoke modifying functions on such a parameter, those functions are implemented as const functions in this class.
template <typename TYPE> class NonConstSet : public SetInterface<TYPE>
{
public:
	using Super = SetInterface<TYPE>;

	const NonConstSet& ToSet() const
	{
		return *this;
	}
	NonConstSet& ToSet()
	{
		return *this;
	}
	operator const NonConstSet<typename std::conditional<std::is_same<TYPE, Generic>::value, DummyReturnType, Generic>::type>&() const
	{
		return *reinterpret_cast<const NonConstSet<typename std::conditional<std::is_same<TYPE, Generic>::value, DummyReturnType, Generic>::type>*>(this);
	}

	using ConstIterator = typename Super::Iterator;

	Result<void> Insert(const TYPE& value, Bool& added = BoolLValue()) const { return const_cast<NonConstSet*>(this)->Super::Insert(value, added); }
	Result<void> Insert(TYPE&& value, Bool& added = BoolLValue()) const { return const_cast<NonConstSet*>(this)->Super::Insert(std::move(value), added); }
	Result<Bool> Erase(const TYPE& value) const { return const_cast<NonConstSet*>(this)->Super::Erase(value); }
	ConstIterator Erase(const ConstIterator& iterator) const { return const_cast<NonConstSet*>(this)->Super::Erase(iterator); }

	void Reset() const { return const_cast<NonConstSet*>(this)->Super::Reset(); }
	void Flush() const { return const_cast<NonConstSet*>(this)->Super::Flush(); }
	Result<void> CopyFrom(const Super& other) const { return const_cast<NonConstSet*>(this)->Super::CopyFrom(other); }

	ConstIterator Begin() const
	{
		return ConstIterator(*const_cast<NonConstSet*>(this), false);
	}

	ConstIterator End() const
	{
		return ConstIterator(*const_cast<NonConstSet*>(this), true);
	}

#ifdef CPP_853_HACK
#ifdef MAXON_COMPILER_GCC
	NonConstSet(const NonConstSet& src) // GCC constructs from the conversion result, upcasted to NonConstSet&
#else
private:
	NonConstSet(const NonConstSet& src);
public:
	template <typename SET> MAXON_IMPLICIT NonConstSet(const SetImpl<SET>& src) // MSVC constructs directly from the conversion result, which allows a more type-safe hack
#endif
		: Super(src)
	{
	}
#endif

	template <typename COLLECTION2> Result<void> AppendAll(COLLECTION2&& c2) const
	{
		for (const auto& i : std::forward<COLLECTION2>(c2))
		{
			if (!Insert(i))
			{
				return CreateError(MAXON_SOURCE_LOCATION, ERROR_TYPE::OUT_OF_MEMORY);
			}
		}
		return OK;
	}

	template <typename COLLECTION2> Result<void> CopyFrom(COLLECTION2&& c2) const
	{
		Flush();
		return AppendAll<COLLECTION2>(std::forward<COLLECTION2>(c2));
	}

protected:
	explicit NonConstSet(const typename Super::MTable& vtable) : Super(vtable) { }

#ifdef CPP_853_HACK

private:
	void operator =(const NonConstSet&);

#else

	~NonConstSet() { }
private:
	MAXON_DISALLOW_COPY_AND_ASSIGN(NonConstSet);

#endif
};

//----------------------------------------------------------------------------------------
/// WritableSetInterface is used for function parameters which shall be able to receive any kind of
/// standard set of the MAXON API via the SetInterface interface mechanism. You have to use WritableSetInterface
/// instead of SetInterface if you want to modify the set within the function. Example:
/// @code
/// void Func(WritableSetInterface<Char>& set);
///
/// ArraySet<Char> mySet;
/// Func(mySet); // OK
/// HashSet<Char> mySet2;
/// Func(mySet2); // OK
/// @endcode
/// @see SetInterface
//----------------------------------------------------------------------------------------
#ifdef MAXON_COMPILER_BUG_CONST_TYPE_ALIAS
#define WritableSetInterface const NonConstSet
#else
template <typename T> using WritableSetInterface = const NonConstSet<T>;
#endif

#include "set1.hxx"
#include "set2.hxx"

template <typename SET> class SetCloneHelper;

// This class is used to represent standard sets from the MAXON API by the SetInterface interface. The compiler converts those sets to SetImpl which is an implementation of SetInterface.
template <typename SET> class SetImpl
	: public std::conditional<std::is_const<typename std::remove_reference<SET>::type>::value || !std::is_reference<SET>::value,
														SetInterface<typename std::remove_reference<SET>::type::ValueType>,
														NonConstSet<typename std::remove_reference<SET>::type::ValueType>>::type
{
public:
	using SetType = typename std::decay<SET>::type;
	static const Bool CONSTSET = std::is_const<typename std::remove_reference<SET>::type>::value;
	static const Bool REFERENCE = std::is_reference<SET>::value;
	using ValueType = typename SetType::ValueType;
	using Super = typename std::conditional<CONSTSET || !REFERENCE, SetInterface<ValueType>, NonConstSet<ValueType>>::type;
	using Interface = typename Super::Interface;
	using Iterator = typename Interface::Iterator;
	using ConstIterator = typename Interface::ConstIterator;

	MAXON_IMPLEMENTATION_SIMPLE(SetImpl, typename);

	SetImpl() : Super(_clsMTable) { }
#ifndef CPP_853_HACK
	explicit SetImpl(SET&& set) : Super(_clsMTable), _set(std::forward<SET>(set))
	{
	}

	SetImpl(SetImpl&& src) : Super(_clsMTable), _set(static_cast<SET&&>(src._set))
	{
// src might be on the stack
//		DebugAssert(System::GetReferenceCounter(&src) == 0);
	}
#else
	explicit SetImpl(typename std::conditional<!REFERENCE, SET, DummyParamType>::type&& set) : Super(_clsMTable), _set(std::forward<SET>(set))
	{
		this->_refDummy = &set;
	}

	// MSVC bug workaround: MSVC 1916 only reserves space on stack for base class SetInterface, but not for a SetImpl when the conversion function
	// of collection.h is used. Therefore the additional SetImpl member _set must not be accessed.
	explicit SetImpl(typename std::conditional<REFERENCE, SET, DummyParamType>::type&& set) : Super(_clsMTable)
	{
		this->_refDummy = &set;
	}
	SetImpl(SetImpl&& src) : Super(_clsMTable)
	{
		this->_refDummy = src._refDummy;
		CopySetMember(_set, src._set);
	}

	#define _set GetSet()
#endif

	Int GetCount() const { return _set.GetCount(); }

	Bool Contains(const ValueType& value) const { return _set.Contains(value); }

	Result<void> Insert(const ValueType& value, Bool& added = BoolLValue())
	{
		if (CONSTSET)
			return CreateError(MAXON_SOURCE_LOCATION, ERROR_TYPE::NOT_IMPLEMENTED);
		return ((SetType*) &_set)->Insert(value, added);
	}

	Result<void> Insert(ValueType&& value, Bool& added = BoolLValue())
	{
		if (CONSTSET)
			return CreateError(MAXON_SOURCE_LOCATION, ERROR_TYPE::NOT_IMPLEMENTED);
		return ((SetType*) &_set)->Insert(std::move(value), added);
	}

	Result<Bool> Erase(const ValueType& value)
	{
		if (CONSTSET)
			return CreateError(MAXON_SOURCE_LOCATION, ERROR_TYPE::NOT_IMPLEMENTED);
		return ((SetType*) &_set)->Erase(value);
	}

	Iterator Erase(const Iterator& iterator)
	{
		if (CONSTSET)
			return Iterator();
		return Iterator(*this, ((SetType*) &_set)->Erase(GetIterator(&iterator)));
	}

	Result<void> CopyFrom(const Interface& other)
	{
		if (CONSTSET)
			return CreateError(MAXON_SOURCE_LOCATION, ERROR_TYPE::NOT_IMPLEMENTED);
		return ((SetType*) &_set)->CopyFrom(*((SetType*) &static_cast<const SetImpl&>(other)._set));
	};

	Result<Interface*> Clone(Bool cloneElements) const
	{
		iferr (SetImpl* c = SetCloneHelper<SET>::New())
			return err;
		if (cloneElements)
		{
			iferr (((SetType*) &c->_set)->CopyFrom(*(SetType*) &_set))
			{
				DeleteObj(c);
				return err;
			}
		}
		return c;
	}
	String ToString(const FormatStatement* formatStatement) const { return GlobalToString(_set, formatStatement); }

	Int GetMemorySize() const { return _set.GetMemorySize() + (SIZEOF(SetImpl) - SIZEOF(SET)); }

	const DataType& GetValueDataType() const
	{
		return GetDataType<ValueType, GET_DATATYPE_POLICY::GENERIC_FOR_UNKNOWN>();
	}

	void Reset()
	{
		if (CONSTSET)
			return;
		((SetType*) &_set)->Reset();
	}

	void Flush()
	{
		if (CONSTSET)
			return;
		((SetType*) &_set)->Flush();
	}

	static_assert(SIZEOF(typename SetType::Iterator) <= SIZEOF(typename Iterator::Memory), "Insufficient iterator size.");
	static_assert(SIZEOF(typename SetType::ConstIterator) <= SIZEOF(typename ConstIterator::Memory), "Insufficient iterator size.");

	void IteratorInit(Iterator* it, Bool end)
	{
		if (end)
			new (it->GetMemory()) typename SetType::Iterator(((SetType*) &_set)->End());
		else
			new (it->GetMemory()) typename SetType::Iterator(((SetType*) &_set)->Begin());
	}

	void IteratorInit(ConstIterator* it, Bool end) const
	{
		if (end)
			new (it->GetMemory()) typename SetType::ConstIterator(_set.End());
		else
			new (it->GetMemory()) typename SetType::ConstIterator(_set.Begin());
	}

	void IteratorInitMove(Iterator* dest, Iterator* src) const
	{
		new (dest->GetMemory()) typename SetType::Iterator(std::move(GetIterator(src)));
	}

	void IteratorInitMove(ConstIterator* dest, ConstIterator* src) const
	{
		new (dest->GetMemory()) typename SetType::ConstIterator(std::move(GetIterator(src)));
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

	const ValueType* IteratorGet(const Iterator* it) const
	{
		return GetIterator(it).operator ->();
	}

	const ValueType* IteratorGet(const ConstIterator* it) const
	{
		return GetIterator(it).operator ->();
	}

#ifdef CPP_853_HACK
	#undef _set

	typename std::add_lvalue_reference<SET>::type GetSet() { return REFERENCE ? *(SetType*) this->_refDummy : GetImpl(_set); }

	const SetType& GetSet() const { return REFERENCE ? *(const SetType*) this->_refDummy : GetImpl(_set); }
#else
	typename std::add_lvalue_reference<SET>::type GetSet() { return _set; }

	const SetType& GetSet() const { return _set; }
#endif

private:
	template <typename T> static void Destruct(const T& object)
	{
		object.~T();
	}

	static typename SetType::Iterator& GetIterator(Iterator* it)
	{
		return *((typename SetType::Iterator*) it->GetMemory());
	}

	static typename SetType::ConstIterator& GetIterator(ConstIterator* it)
	{
		return *((typename SetType::ConstIterator*) it->GetMemory());
	}

	static const typename SetType::Iterator& GetIterator(const Iterator* it)
	{
		return *((const typename SetType::Iterator*) it->GetMemory());
	}

	static const typename SetType::ConstIterator& GetIterator(const ConstIterator* it)
	{
		return *((const typename SetType::ConstIterator*) it->GetMemory());
	}

	MAXON_DISALLOW_COPY_AND_ASSIGN(SetImpl);

#ifdef CPP_853_HACK
	typename std::conditional<REFERENCE, Bool, SET>::type _set;

	template <typename T> static T& GetImpl(T& x)
	{
		return x;
	}

	static SetType& GetImpl(Bool)
	{
		return reinterpret_cast<SetType&>(g_writableMemory);
	}

	static void CopySetMember(SET& dst, SET& src)
	{
		dst = static_cast<SET&&>(src);
	}

	static void CopySetMember(Bool, Bool)
	{
	}

#else
	SET _set;
#endif
};


template <typename SET> class SetCloneHelper
{
public:
	static ResultPtr<SetImpl<SET>> New()
	{
		return NewObj(SetImpl<SET>);
	}
};

template <typename SET> class SetCloneHelper<SET&>
{
public:
	static ResultPtr<SetImpl<SET&>> New()
	{
		DebugStop("Can't clone SetImpl when the internal set is a reference!");
		return nullptr;
	}
};


template <typename SET> MAXON_IMPLEMENTATION_REGISTER_SIMPLE(SetImpl<SET>, typename);


template <typename COLLECTION, typename VALUETYPE, typename SUPER, typename HASH> inline SetImpl<COLLECTION&> SetBase<COLLECTION, VALUETYPE, SUPER, HASH>::ToSet()
{
	return SetImpl<COLLECTION&>(*static_cast<COLLECTION*>(this));
}

template <typename COLLECTION, typename VALUETYPE, typename SUPER, typename HASH> inline SetImpl<const COLLECTION&> SetBase<COLLECTION, VALUETYPE, SUPER, HASH>::ToSet() const
{
	return SetImpl<const COLLECTION&>(*static_cast<const COLLECTION*>(this));
}

//----------------------------------------------------------------------------------------
/// Returns a pointer to the set reference argument. This function is useful if you have to
/// convert some set to a pointer to a SetInterface:
/// @code
/// void Func(const SetInterface<const Char>* set);
///
/// HashSet<Char> mySet;
/// Func(ToSetPtr(mySet));
/// @endcode
/// For WritableSetInterface parameters, use ToWritableSetPtr instead.
///
/// @see SetInterface.
///
/// @tparam T											Type of elements of the set, this is deduced by the compiler.
///
/// @note If the argument is a temporary (which usually is the case), the result will be a
/// pointer to a temporary. Make sure that the pointer is used only within the lifetime
/// of the temporary. For the above example, it suffices that Func uses the set only
/// during its execution.
//----------------------------------------------------------------------------------------
template <typename T> inline const SetInterface<T>* ToSetPtr(const SetInterface<T>& set)
{
	return &set;
}

//----------------------------------------------------------------------------------------
/// Returns a pointer to the set reference argument. This function is useful if you have to
/// convert some set to a pointer to a SetInterface:
/// @code
/// void Func(WritableSetInterface<const Char>* set);
///
/// HashSet<Char> mySet;
/// Func(ToWritableSetPtr(mySet));
/// @endcode
/// For non-modifiable set parameters, use ToSetPtr instead.
///
/// @see SetInterface.
///
/// @tparam T											Type of elements of the set, this is deduced by the compiler.
///
/// @note If the argument is a temporary (which usually is the case), the result will be a
/// pointer to a temporary. Make sure that the pointer is used only within the lifetime
/// of the temporary. For the above example, it suffices that Func uses the set only
/// during its execution.
//----------------------------------------------------------------------------------------
template <typename T> inline WritableSetInterface<T>* ToWritableSetPtr(WritableSetInterface<T>& set)
{
	return &set;
}

} // namespace maxon

#endif // SET_H__
