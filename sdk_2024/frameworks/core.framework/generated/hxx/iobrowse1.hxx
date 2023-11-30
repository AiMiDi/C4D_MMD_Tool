#if 1
class IoBrowseRef;

/// @cond INTERNAL

/// @endcond

struct IoBrowseInterface::HasBaseDetector { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, IoBrowseInterface>::value || ObjectInterface::HasBaseDetector::template Check<I>::value; static I* Cast(IoBrowseInterface* ptr) { return reinterpret_cast<I*>(ptr); } }; };
struct IoBrowseInterface::Hxx1
{
	class Reference;
	using ReferenceClass = IoBrowseRef;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<ObjectInterface>;
	/// Intermediate helper class for IoBrowseInterface.
	template <typename S> class ConstFn DOXYGEN_SWITCH_REVERSED(, : public S)
	{
	public:
		ConstFn() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateInterface = IoBrowseInterface;
		using PrivateBaseClass::PrivateLookupFn;
		static ConstFn PrivateLookupFn(IoBrowseInterface**);
/// @cond INTERNAL

/// @endcond

/// Returns corresponding Url.
/// @return												Name of the connection.
		inline HXXADDRET2(const Url&) GetBasePath() const;
		inline HXXADDRET2(Bool) HasEntry() const;
/// Returns the current Url.
		inline HXXADDRET2(Url) GetCurrentPath() const;
/// Returns the flags (IOBROWSEFLAGS) of the children.
		inline HXXADDRET2(IOBROWSEFLAGS) IoGetFlags() const;
/// Returns the flags (IOATTRIBUTES) of the children.
		inline Result<IOATTRIBUTES> IoGetAttributes() const;
/// Returns the DateTime of the current file. The time is in local time.
/// @param[in] mode								IOTIMEMODE of the requested time.
/// @return												Returns the DateTime or an error.
		inline Result<UniversalDateTime> IoGetTime(IOTIMEMODE mode) const;
/// Returns the size of the current file.
/// @return												Size in bytes. -1 means unknown size.
		inline HXXADDRET2(Int64) GetSize() const;
/// Returns some extra data.
/// @return												The return value depends on the handler what it returns.
/// 															URLSCHEME_VOLUME: returns the human readable drive name.
		inline HXXADDRET2(String) GetExtraData() const;
	};
	/// Intermediate helper class for IoBrowseInterface.
	template <typename S> class Fn : public ConstFn<S>
	{
	public:
		Fn() = default;
		using PrivateBaseClass = ConstFn<S>;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateInterface = IoBrowseInterface;
		using PrivateBaseClass::PrivateLookupFn;
		static Fn PrivateLookupFn(IoBrowseInterface**);
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, IoBrowseRef, true>::type&() const { return reinterpret_cast<const IoBrowseRef&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, IoBrowseRef, false>::type&() { return reinterpret_cast<const IoBrowseRef&>(this->GetBaseRef()); }
/// @cond INTERNAL

/// Private.
/// TODO: (Tilo) Please describe.
/// @param[in] connection					IoConnectionRef connected to this IoBrowseRef.
/// @param[in] flags							See GETBROWSEITERATORFLAGS.
		inline maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S)> Init(IoConnectionInterface* connection, GETBROWSEITERATORFLAGS flags) const;
/// @endcond

/// Restart browsing of the directory.
/// @return												OK on success.
		inline Result<void> Reset() const;
/// Browses to the next object in the list.
/// You need to call GetNext() before you get the first object.
/// A typical use is: while (browse->GetNext()) { n = browse->GetCurrentPath(); }
/// @return												OK on success.
		inline Result<void> GetNext() const;

		const IoBrowseRef& operator *()
		{
			return *(IoBrowseRef*)((char*) this + (S::HAS_ERROR ? SIZEOF(void*) : 0));
		}
		Result<void> operator ++()	// prefix operator++ (increment and fetch)
		{
			return GetNext();
		}

		template <typename SUPER> using ResultFunctions = ResultIteratorFunctions<ObjectRef::ResultFunctions<SUPER>>;
		
		public:
	};
	/// Intermediate helper class for IoBrowseInterface.
	template <typename S> class COWFn : public ConstFn<S>
	{
	public:
		COWFn() = default;
		using PrivateBaseClass = ConstFn<S>;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateInterface = IoBrowseInterface;
		using PrivateBaseClass::PrivateLookupFn;
		static COWFn PrivateLookupFn(IoBrowseInterface**);
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, IoBrowseRef, false>::type&() { return reinterpret_cast<const IoBrowseRef&>(this->GetBaseRef()); }
/// @cond INTERNAL

/// Private.
/// TODO: (Tilo) Please describe.
/// @param[in] connection					IoConnectionRef connected to this IoBrowseRef.
/// @param[in] flags							See GETBROWSEITERATORFLAGS.
		inline maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S>, S)> Init(IoConnectionInterface* connection, GETBROWSEITERATORFLAGS flags);
/// @endcond

/// Restart browsing of the directory.
/// @return												OK on success.
		inline Result<void> Reset();
/// Browses to the next object in the list.
/// You need to call GetNext() before you get the first object.
/// A typical use is: while (browse->GetNext()) { n = browse->GetCurrentPath(); }
/// @return												OK on success.
		inline Result<void> GetNext();
	};
	template <typename ST> struct FnHelper : public std::conditional<
	maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)),
	COWFn<typename ObjectInterface::Hxx1::template FnHelper<ST>::type>,
	typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstFn<typename ObjectInterface::Hxx1::template FnHelper<ST>::type>, Fn<typename ObjectInterface::Hxx1::template FnHelper<ST>::type>>::type
	> { };
};
class IoBrowseInterface::Hxx1::Reference :
#ifdef DOXYGEN
public FnDoxy<IoBrowseRef>
#else
public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<IoBrowseInterface, maxon::StrongRefHandler, IoBrowseRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<IoBrowseInterface, maxon::StrongRefHandler, IoBrowseRef>>>>);
	using NonConst = typename Super::ReferenceClass;
};

/// IoBrowseRef is the reference class of IoBrowseInterface.
///
/// The IoBrowserIterator interface for a given Url.
/// This IoBrowserIterator needs to be implemented for each protocol that support kind of directories. (e.g. "file", "zip")
class IoBrowseRef : public IoBrowseInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(IoBrowseRef, typename IoBrowseInterface::Hxx1::Reference);
	using ConstPtr = typename IoBrowseInterface::ConstPtr;
};

#endif
