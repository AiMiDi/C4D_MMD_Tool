#if 1
template <typename TYPE> class Set;

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
template <typename TYPE> struct SetInterface<TYPE>::Hxx1
{
	class Reference;
	class NonConstRef;
	using ReferenceClass = Set<TYPE>;
	/// Intermediate helper class for SetInterface.
	template <typename S> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
	{
	public:
		ConstReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
/// Gets the number of set elements.
/// @return												Number of set elements.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type GetCount() const;
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type IsEmpty() const;
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type IsPopulated() const;
/// Checks if this set contains @p value.
/// @param[in] value							The value to check.
/// @return												True if this set contains @p value.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type Contains(const TYPE& value) const;
/// Returns a clone of this set.
/// @param[in] cloneElements			True if also the elements shall be cloned, false otherwise (then just a new object sharing the same SetInterface implementation is created).
/// @return												Pointer to the new set object, nullptr if allocation or copying failed.
		inline Result<SetInterface*> Clone(Bool cloneElements = true) const;
/// Returns the data type of this set's elements. This may be nullptr if there is no
/// DataType for the template parameter TYPE.
/// @return												DataType of the elements or nullptr.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<const DataType&>, const DataType&>::type GetValueDataType() const;
/// @param[in] formatStatement		Nullptr or additional formatting instruction. Currently no additional formatting instructions are supported.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type ToString(const FormatStatement* formatStatement) const;
/// Calculates the memory usage for this set.
/// @return												Memory size in bytes.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type GetMemorySize() const;
UInt GetHashCode() const { CriticalStop("Not implemented."); return 0; };
		public:
		template <typename T> inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type HasType() const;
/// Issues a failed DebugAssert if the DataType of this set doesn't match T. If T is Generic,
/// no check happens.
/// @tparam T											Type to check.
		template <typename T> inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type AssertType() const;
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
	/// Intermediate helper class for SetInterface.
	template <typename S> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
/// Adds @p value to this set. If @p value is already contained in this set, nothing happens,
/// and @p added is set to @c false.
/// @param[in] value							Value to add to this set.
/// @param[out] added							This will be set to true if the element didn't exist before in the set and it could be added successfully, otherwise it will be set to false.
/// @return												OK on success.
		inline Result<void> Insert(const TYPE& value, Bool& added = BoolLValue()) const;
/// Adds @p value to this set. If @p value is already contained in this set, nothing happens,
/// and @p added is set to @c false.
/// @param[in] value							Value to add to this set. When a new element has to be added, @p value will be moved into the new element.
/// @param[out] added							This will be set to true if the element didn't exist before in the set and it could be added successfully, otherwise it will be set to false.
/// @return												OK on success.
		inline Result<void> Insert(TYPE&& value, Bool& added = BoolLValue()) const;
/// Remove @p value from this set. If @p value isn't contained in this set, nothing happens.
/// @param[in] value							Value to remove from this set.
/// @return												True if an entry was found and removed for #value, otherwise false or an error if a memory allocation failed.
		inline Result<Bool> Erase(const TYPE& value) const;
/// Removes the element at @p iterator from this set.
/// The returned iterator will point to the element behind the last removed element.
/// @param[in] iterator						Iterator pointing to the element to be removed.
/// @return												Iterator pointing to the element behind the removed element.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Iterator>, Iterator>::type Erase(const Iterator& iterator) const;
/// Deletes all elements (calls destructors and frees memory).
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type Reset() const;
/// Deletes all elements, but doesn't free memory (calls destructors though).
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type Flush() const;
/// Sets this set to a copy of the given other set.
/// @param[in] other							Source set.
/// @return												Success of operation.
		inline Result<void> CopyFrom(const SetInterface& other) const;
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
	/// Intermediate helper class for SetInterface.
	template <typename S> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, Set<TYPE>, false>::type&() const { return reinterpret_cast<const Set<TYPE>&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, Set<TYPE>, false>::type&() { return reinterpret_cast<const Set<TYPE>&>(this->GetBaseRef()); }
/// Adds @p value to this set. If @p value is already contained in this set, nothing happens,
/// and @p added is set to @c false.
/// @param[in] value							Value to add to this set.
/// @param[out] added							This will be set to true if the element didn't exist before in the set and it could be added successfully, otherwise it will be set to false.
/// @return												OK on success.
		inline Result<void> Insert(const TYPE& value, Bool& added = BoolLValue());
/// Adds @p value to this set. If @p value is already contained in this set, nothing happens,
/// and @p added is set to @c false.
/// @param[in] value							Value to add to this set. When a new element has to be added, @p value will be moved into the new element.
/// @param[out] added							This will be set to true if the element didn't exist before in the set and it could be added successfully, otherwise it will be set to false.
/// @return												OK on success.
		inline Result<void> Insert(TYPE&& value, Bool& added = BoolLValue());
/// Remove @p value from this set. If @p value isn't contained in this set, nothing happens.
/// @param[in] value							Value to remove from this set.
/// @return												True if an entry was found and removed for #value, otherwise false or an error if a memory allocation failed.
		inline Result<Bool> Erase(const TYPE& value);
/// Removes the element at @p iterator from this set.
/// The returned iterator will point to the element behind the last removed element.
/// @param[in] iterator						Iterator pointing to the element to be removed.
/// @return												Iterator pointing to the element behind the removed element.
		inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Iterator, maxon::Result<Iterator>>::type Erase(const Iterator& iterator);
/// Deletes all elements (calls destructors and frees memory).
		inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type Reset();
/// Deletes all elements, but doesn't free memory (calls destructors though).
		inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type Flush();
/// Sets this set to a copy of the given other set.
/// @param[in] other							Source set.
/// @return												Success of operation.
		inline Result<void> CopyFrom(const SetInterface& other);
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
template <typename TYPE> class SetInterface<TYPE>::Hxx1::Reference :
#ifdef DOXYGEN
public COWReferenceFunctionsImplDoxy<Set<TYPE>>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const SetInterface<TYPE>, maxon::StrongCOWRefHandler, Set<TYPE>>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const SetInterface<TYPE>, maxon::StrongCOWRefHandler, Set<TYPE>>>>>);
	using NonConst = Hxx1::NonConstRef;
};

/// Set is the reference class of SetInterface.
///
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
template <typename TYPE> class Set : public SetInterface<TYPE>::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Set, typename SetInterface<TYPE>::Hxx1::Reference);
	struct Instantiation
	{
		template <template <typename> class MAP> using Map = Set<typename MAP<TYPE>::type>;
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
