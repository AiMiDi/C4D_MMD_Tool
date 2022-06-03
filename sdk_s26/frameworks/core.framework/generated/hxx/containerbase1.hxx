#if 1
template <typename... T_> class Container;

struct GenericContainerInterface::Hxx1
{
	template <typename T_> class Reference;
	template <typename T_> class NonConstRef;
	using ReferenceClass = Container<>;
	/// Intermediate helper class for GenericContainerInterface.
	template <typename S, typename T_> class ConstFn DOXYGEN_SWITCH_REVERSED(, : public S)
	{
	public:
		ConstFn() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateBaseClass::PrivateLookupFn;
		static ConstFn PrivateLookupFn(GenericContainerInterface**);
		using T = T_;
		using GenericContainerInterfaceMarker = GenericContainerInterface::GenericContainerInterfaceMarker;
		using INTERFACES = GenericContainerInterface::INTERFACES;
		using S::GenericVarianceCheck;
		template <typename _S, typename _T> static typename std::integral_constant<bool, true && ContainerVariance<_T, T_>::value>::type GenericVarianceCheck(const ConstFn<_S, _T>*);
		template <typename _S> static typename std::true_type GenericVarianceCheck(ConstFn<_S, NamedTuple<>>*);
		template <typename DERIVED> struct IsGenericBaseOf { static const Bool value = S::template IsGenericBaseOf<DERIVED>::value && decltype(DERIVED::GenericVarianceCheck((ConstFn*) nullptr))::value; };
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<const ContainerDataType<>&>, const ContainerDataType<>&>::type GetContainerType() const;
/// Returns INTERFACES flags corresponding to the interfaces implemented by this container.
/// You can safely cast the container to these interfaces.
/// @return												INTERFACES flags for this container.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<INTERFACES>, INTERFACES>::type GetInterfaces() const;
		[[deprecated]] inline Result<GenericContainerInterface*> Clone(Bool copyContent = true) const;
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type ToString(const FormatStatement* formatStatement = nullptr) const;
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<HashValue>, HashValue>::type GetHashValue() const;
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type IsEqual(const GenericContainerInterface* other, EQUALITY equality) const;
/// Finds the member index of the member with the given #name in this. If no such member
/// can be found, -1 is returned.
/// @param[in] name								Name of the member to find.
/// @return												Index of the member, or -1 if it doesn't exist.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type FindMemberIndex(const InternedId& name) const;
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type FindMemberIndex(const Member& member) const;
		inline Result<Int> GetCount() const;

	using Iterator = maxon::details::ContainerIterator<T, false>;
	using ConstIterator = maxon::details::ContainerIterator<T, true>;
	
		public:
	};
	/// Intermediate helper class for GenericContainerInterface.
	template <typename S, typename T_> class Fn : public ConstFn<S, T_>
	{
	public:
		Fn() = default;
		using PrivateBaseClass = ConstFn<S, T_>;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateBaseClass::PrivateLookupFn;
		static Fn PrivateLookupFn(GenericContainerInterface**);
		using T = T_;
	};
	/// Intermediate helper class for GenericContainerInterface.
	template <typename S, typename T_> class COWFn : public ConstFn<S, T_>
	{
	public:
		COWFn() = default;
		using PrivateBaseClass = ConstFn<S, T_>;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateBaseClass::PrivateLookupFn;
		static COWFn PrivateLookupFn(GenericContainerInterface**);
		using T = T_;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, typename T_::template Apply<Container>, false>::type&() const { return reinterpret_cast<const typename T_::template Apply<Container>&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, typename T_::template Apply<Container>, false>::type&() { return reinterpret_cast<const typename T_::template Apply<Container>&>(this->GetBaseRef()); }

	//----------------------------------------------------------------------------------------
	/// Makes the container object of this copy-on-write reference writable, where the content of the
	/// resulting container object is unspecified (see GenericContainerInterface::MakeWritable).
	/// You can use this function instead of MakeWritable()
	/// or prior to non-const method calls when you are going to overwrite the complete content of the
	/// container (so that a copy of the original content is needless and wasteful).
	/// @code
	/// Array<Int> someArray;
	/// ...
	/// // We will overwrite the content afterwards, so we don't care about the current content.
	/// someArray.MakeWritableDontCopyContent() iferr_return;
	/// someArray.Resize(100) iferr_return;
	/// for (Int i = 0; i < 100; ++i)
	/// {
	/// 	someArray.Set(i, i) iferr_return;
	/// }
	/// @endcode
	/// @return												Reference to the writable container object.
	//----------------------------------------------------------------------------------------
	ResultRef<typename std::remove_const<typename S::PrivateReferencedType>::type> MakeWritableDontCopyContent()
	{
		return StrongCOWRefHandler::MakeWritableHelper<typename std::remove_const<typename S::PrivateReferencedType>::type>::MakeWritable(this->GetBaseRef(), false, false);
	}
	
		public:
	};
	template <typename ST, typename T_ = NamedTuple<>> struct FnHelper : public std::conditional<
	maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)),
	COWFn<typename ST::type, T_>,
	typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstFn<typename ST::type, T_>, Fn<typename ST::type, T_>>::type
	> { };
};
template <typename... T_> class ContainerInterface : public GenericContainerInterface::Hxx1::template FnHelper<maxon::details::DirectInstance<ContainerInterface<T_...>, GenericContainerInterface>, NamedTuple<T_...>>::type
{
public:
	using ErasedType = GenericContainerInterface;
	struct Instantiation
	{
		template <template <typename> class MAP> using Map = ContainerInterface<typename MAP<T_>::type...>;
	};
};
template <typename T_> class GenericContainerInterface::Hxx1::Reference :
#ifdef DOXYGEN
public COWFnDoxy<typename T_::template Apply<Container>>
#else
public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<const typename T_::template Apply<ContainerInterface>, maxon::StrongCOWRefHandler, typename T_::template Apply<Container>>>, T_>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<const typename T_::template Apply<ContainerInterface>, maxon::StrongCOWRefHandler, typename T_::template Apply<Container>>>, T_>>);
	using NonConst = Hxx1::NonConstRef<T_>;
};

template <typename T_> class GenericContainerInterface::Hxx1::NonConstRef :
#ifdef DOXYGEN
public FnDoxy<NonConstRef<T_>>
#else
public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<typename T_::template Apply<ContainerInterface>, maxon::StrongRefHandler, NonConstRef<T_>>>, T_>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<typename T_::template Apply<ContainerInterface>, maxon::StrongRefHandler, NonConstRef<T_>>>, T_>>);
};

/// Container is the reference class of GenericContainerInterface.
template <typename... T_> class Container : public GenericContainerInterface::Hxx1::template Reference<NamedTuple<T_...>>
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Container, typename GenericContainerInterface::Hxx1::template Reference<NamedTuple<T_...>>);
	struct Instantiation
	{
		template <template <typename> class MAP> using Map = Container<typename MAP<T_>::type...>;
	};
};

template <typename... T_> class IndexableContainer;

struct GenericIndexableContainerInterface::Hxx1
{
	template <typename T_> class Reference;
	template <typename T_> class NonConstRef;
	using ReferenceClass = IndexableContainer<>;
	/// Intermediate helper class for GenericIndexableContainerInterface.
	template <typename S, typename T_> class ConstFn DOXYGEN_SWITCH_REVERSED(, : public S)
	{
	public:
		ConstFn() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateBaseClass::PrivateLookupFn;
		static ConstFn PrivateLookupFn(GenericIndexableContainerInterface**);
		using T = T_;
		using S::GenericVarianceCheck;
		template <typename _S, typename _T> static typename std::integral_constant<bool, true && ContainerVariance<_T, T_>::value>::type GenericVarianceCheck(const ConstFn<_S, _T>*);
		template <typename _S> static typename std::true_type GenericVarianceCheck(ConstFn<_S, NamedTuple<>>*);
		template <typename DERIVED> struct IsGenericBaseOf { static const Bool value = S::template IsGenericBaseOf<DERIVED>::value && decltype(DERIVED::GenericVarianceCheck((ConstFn*) nullptr))::value; };
	};
	/// Intermediate helper class for GenericIndexableContainerInterface.
	template <typename S, typename T_> class Fn : public ConstFn<S, T_>
	{
	public:
		Fn() = default;
		using PrivateBaseClass = ConstFn<S, T_>;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateBaseClass::PrivateLookupFn;
		static Fn PrivateLookupFn(GenericIndexableContainerInterface**);
		using T = T_;
	};
	/// Intermediate helper class for GenericIndexableContainerInterface.
	template <typename S, typename T_> class COWFn : public ConstFn<S, T_>
	{
	public:
		COWFn() = default;
		using PrivateBaseClass = ConstFn<S, T_>;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateBaseClass::PrivateLookupFn;
		static COWFn PrivateLookupFn(GenericIndexableContainerInterface**);
		using T = T_;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, typename T_::template Apply<IndexableContainer>, false>::type&() const { return reinterpret_cast<const typename T_::template Apply<IndexableContainer>&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, typename T_::template Apply<IndexableContainer>, false>::type&() { return reinterpret_cast<const typename T_::template Apply<IndexableContainer>&>(this->GetBaseRef()); }
	};
	template <typename ST, typename T_ = NamedTuple<>> struct FnHelper : public std::conditional<
	maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)),
	COWFn<typename GenericContainerInterface::Hxx1::template FnHelper<ST, T_>::type, T_>,
	typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstFn<typename GenericContainerInterface::Hxx1::template FnHelper<ST, T_>::type, T_>, Fn<typename GenericContainerInterface::Hxx1::template FnHelper<ST, T_>::type, T_>>::type
	> { };
};
template <typename... T_> class IndexableContainerInterface : public GenericIndexableContainerInterface::Hxx1::template FnHelper<maxon::details::DirectInstance<IndexableContainerInterface<T_...>, GenericIndexableContainerInterface>, NamedTuple<T_...>>::type
{
public:
	using ErasedType = GenericIndexableContainerInterface;
	struct Instantiation
	{
		template <template <typename> class MAP> using Map = IndexableContainerInterface<typename MAP<T_>::type...>;
	};
};
template <typename T_> class GenericIndexableContainerInterface::Hxx1::Reference :
#ifdef DOXYGEN
public COWFnDoxy<typename T_::template Apply<IndexableContainer>>
#else
public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<const typename T_::template Apply<IndexableContainerInterface>, maxon::StrongCOWRefHandler, typename T_::template Apply<IndexableContainer>>>, T_>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<const typename T_::template Apply<IndexableContainerInterface>, maxon::StrongCOWRefHandler, typename T_::template Apply<IndexableContainer>>>, T_>>);
	using NonConst = Hxx1::NonConstRef<T_>;
};

template <typename T_> class GenericIndexableContainerInterface::Hxx1::NonConstRef :
#ifdef DOXYGEN
public FnDoxy<NonConstRef<T_>>
#else
public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<typename T_::template Apply<IndexableContainerInterface>, maxon::StrongRefHandler, NonConstRef<T_>>>, T_>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<typename T_::template Apply<IndexableContainerInterface>, maxon::StrongRefHandler, NonConstRef<T_>>>, T_>>);
};

/// IndexableContainer is the reference class of GenericIndexableContainerInterface.
///
/// This is the base interface of all indexable containers such as arrays or array containers.
template <typename... T_> class IndexableContainer : public GenericIndexableContainerInterface::Hxx1::template Reference<NamedTuple<T_...>>
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(IndexableContainer, typename GenericIndexableContainerInterface::Hxx1::template Reference<NamedTuple<T_...>>);
	struct Instantiation
	{
		template <template <typename> class MAP> using Map = IndexableContainer<typename MAP<T_>::type...>;
	};
};

#endif
