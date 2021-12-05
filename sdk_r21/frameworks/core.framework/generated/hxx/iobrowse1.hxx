#if 1
class IoBrowseRef;

/// @cond INTERNAL

/// @endcond

struct IoBrowseInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, IoBrowseInterface>::value || ObjectInterface::HasBase::template Check<I>::value; static I* Cast(IoBrowseInterface* ptr) { return static_cast<I*>(static_cast<maxon::ObjectInterface*>(ptr)); } }; };
struct IoBrowseInterface::Hxx1
{
	class Reference;
	using ReferenceClass = IoBrowseRef;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<ObjectInterface>;
	/// Intermediate helper class for IoBrowseInterface.
	template <typename S> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
	{
	public:
		ConstReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
/// @cond INTERNAL

/// @endcond

/// Returns corresponding Url.
/// @return												Name of the connection.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<const Url&>, const Url&>::type GetBasePath() const;
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type HasEntry() const;
/// Returns the current Url.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Url>, Url>::type GetCurrentPath() const;
/// Returns the flags (IOBROWSEFLAGS) of the children.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<IOBROWSEFLAGS>, IOBROWSEFLAGS>::type IoGetFlags() const;
/// Returns the flags (IOATTRIBUTES) of the children.
		inline Result<IOATTRIBUTES> IoGetAttributes() const;
/// Returns the DateTime of the current file. The time is in local time.
/// @param[in] mode								IOTIMEMODE of the requested time.
/// @return												Returns the DateTime or an error.
		inline Result<UniversalDateTime> IoGetTime(IOTIMEMODE mode) const;
/// Returns the size of the current file.
/// @return												Size in bytes. -1 means unknown size.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Int64>, Int64>::type GetSize() const;
/// Returns some extra data.
/// @return												The return value depends on the handler what it returns.
/// 															URLSCHEME_VOLUME: returns the human readable drive name.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type GetExtraData() const;
	};
	/// Intermediate helper class for IoBrowseInterface.
	template <typename S> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
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
	template <typename S> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
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
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename ObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename ObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, ReferenceFunctionsImpl<typename ObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>>::type> { };
};
class IoBrowseInterface::Hxx1::Reference :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<IoBrowseRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<IoBrowseInterface, maxon::StrongRefHandler, IoBrowseRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<IoBrowseInterface, maxon::StrongRefHandler, IoBrowseRef>>>>);
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
};

#endif
