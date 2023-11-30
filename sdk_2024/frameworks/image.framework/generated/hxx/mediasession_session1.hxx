#if 1
class MediaSessionRef;

struct MediaSessionInterface::HasBaseDetector { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, MediaSessionInterface>::value || ObserverObjectInterface::HasBaseDetector::template Check<I>::value; static I* Cast(MediaSessionInterface* ptr) { return reinterpret_cast<I*>(ptr); } }; };
struct MediaSessionInterface::Hxx1
{
	class Reference;
	using ReferenceClass = MediaSessionRef;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<ObserverObjectInterface>;
	/// Intermediate helper class for MediaSessionInterface.
	template <typename S> class ConstFn DOXYGEN_SWITCH_REVERSED(, : public S)
	{
	public:
		ConstFn() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateInterface = MediaSessionInterface;
		using PrivateBaseClass::PrivateLookupFn;
		static ConstFn PrivateLookupFn(MediaSessionInterface**);
/// Returns the progress object to set/get progress for implementors.
		inline HXXADDRET2(ProgressRef) GetProgress() const;
	};
	/// Intermediate helper class for MediaSessionInterface.
	template <typename S> class Fn : public ConstFn<S>
	{
	public:
		Fn() = default;
		using PrivateBaseClass = ConstFn<S>;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateInterface = MediaSessionInterface;
		using PrivateBaseClass::PrivateLookupFn;
		static Fn PrivateLookupFn(MediaSessionInterface**);
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, MediaSessionRef, true>::type&() const { return reinterpret_cast<const MediaSessionRef&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, MediaSessionRef, false>::type&() { return reinterpret_cast<const MediaSessionRef&>(this->GetBaseRef()); }
/// Connects two MediaConverterRefs within a Media Session. Both converters must not be attached to another session.
		inline Result<void> ConnectMediaConverter(const MediaConverterRef& input, const MediaConverterRef& output) const;
/// Triggers the session to read the next frame from the stream.
/// @param[in] targetTime					Target time to receive the media samples from.
/// @param[in] flags							See MEDIASESSIONFLAGS for details.
		inline Result<void> Convert(const TimeValue& targetTime, MEDIASESSIONFLAGS flags) const;
/// Closes the session, finalizes all write operations and closes all handles.
		inline Result<void> Close() const;
	};
	/// Intermediate helper class for MediaSessionInterface.
	template <typename S> class COWFn : public ConstFn<S>
	{
	public:
		COWFn() = default;
		using PrivateBaseClass = ConstFn<S>;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateInterface = MediaSessionInterface;
		using PrivateBaseClass::PrivateLookupFn;
		static COWFn PrivateLookupFn(MediaSessionInterface**);
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, MediaSessionRef, false>::type&() { return reinterpret_cast<const MediaSessionRef&>(this->GetBaseRef()); }
/// Connects two MediaConverterRefs within a Media Session. Both converters must not be attached to another session.
		inline Result<void> ConnectMediaConverter(const MediaConverterRef& input, const MediaConverterRef& output);
/// Triggers the session to read the next frame from the stream.
/// @param[in] targetTime					Target time to receive the media samples from.
/// @param[in] flags							See MEDIASESSIONFLAGS for details.
		inline Result<void> Convert(const TimeValue& targetTime, MEDIASESSIONFLAGS flags);
/// Closes the session, finalizes all write operations and closes all handles.
		inline Result<void> Close();
	};
	template <typename ST> struct FnHelper : public std::conditional<
	maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)),
	COWFn<typename ObserverObjectInterface::Hxx1::template FnHelper<ST>::type>,
	typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstFn<typename ObserverObjectInterface::Hxx1::template FnHelper<ST>::type>, Fn<typename ObserverObjectInterface::Hxx1::template FnHelper<ST>::type>>::type
	> { };
};
class MediaSessionInterface::Hxx1::Reference :
#ifdef DOXYGEN
public FnDoxy<MediaSessionRef>
#else
public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<MediaSessionInterface, maxon::StrongRefHandler, MediaSessionRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<MediaSessionInterface, maxon::StrongRefHandler, MediaSessionRef>>>>);
	using NonConst = typename Super::ReferenceClass;
};

/// MediaSessionRef is the reference class of MediaSessionInterface.
///
/// The media session interface connects media inputs with media outputs.
/// For each output a MediaConnectionRef is handled.
class MediaSessionRef : public MediaSessionInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(MediaSessionRef, typename MediaSessionInterface::Hxx1::Reference);
	using ConstPtr = typename MediaSessionInterface::ConstPtr;
};

#endif
