#if 1
class MediaConverterRef;

struct MediaConverterInterface::HasBaseDetector { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, MediaConverterInterface>::value || MediaBaseInterface::HasBaseDetector::template Check<I>::value; static I* Cast(MediaConverterInterface* ptr) { return reinterpret_cast<I*>(ptr); } }; };
struct MediaConverterInterface::Hxx1
{
	class Reference;
	using ReferenceClass = MediaConverterRef;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<MediaBaseInterface>;
	/// Intermediate helper class for MediaConverterInterface.
	template <typename S> class ConstFn DOXYGEN_SWITCH_REVERSED(, : public S)
	{
	public:
		ConstFn() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateBaseClass::PrivateLookupFn;
		static ConstFn PrivateLookupFn(MediaConverterInterface**);
/// Returns true for media importers: The converter supports the import strategy where the
/// input pushes the read data to the output nodes.
/// The media session can only connect converters which support the same strategies, e.g. MediaStreamImageDataImportInterface.
/// @return												True for supported imported strategy, false otherwise.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type SupportImportStrategy() const;
/// Returns true for media exporters: The converter supports the export strategy where the
/// output pulls the required data from the input nodes.
/// The media session can only connect converters which support the same strategies, e.g. MediaStreamImageDataExportInterface.
/// @return												True for supported export strategy, false otherwise.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type SupportExportStrategy() const;
/// Get the connected MediaConvertRef used as input. An empty array if it's the source/root.
/// @return												Array of inputs.
		inline Result<BaseArray<MediaConverterRef>> GetInputConverter() const;
/// Returns all output streams of this converter.
/// @param[in] flattenChildren		Return also all children streams by running recursively through all streams.
/// @return												Array of output streams.
		inline Result<BaseArray<MediaStreamRef>> GetOutputStreams(Bool flattenChildren) const;
	};
	/// Intermediate helper class for MediaConverterInterface.
	template <typename S> class Fn : public ConstFn<S>
	{
	public:
		Fn() = default;
		using PrivateBaseClass = ConstFn<S>;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateBaseClass::PrivateLookupFn;
		static Fn PrivateLookupFn(MediaConverterInterface**);
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, MediaConverterRef, true>::type&() const { return reinterpret_cast<const MediaConverterRef&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, MediaConverterRef, false>::type&() { return reinterpret_cast<const MediaConverterRef&>(this->GetBaseRef()); }
/// Adds an output stream to the converter.
/// @return												OK on success.
		inline Result<void> AddOutputStream(const MediaStreamRef& stream) const;
/// Removes an output stream from the converter.
/// @return												OK on success.
		inline Result<void> RemoveOutputStream(const MediaStreamRef& stream) const;
/// Analyzes the streams. A converter needs to call the same function for all inputs
/// followed by calling stream.SubscribeStream() to signal the interest for one or more streams.
/// @param[in] inputs							Block of input streams to evaluate.
/// @param[in] targetTime					Target time to load.
/// @param[in] flags							See MEDIASESSIONFLAGS for details.
/// @return												OK on success.
		inline Result<void> Analyze(const Block<const MediaConverterRef>& inputs, const TimeValue& targetTime, MEDIASESSIONFLAGS flags) const;
/// Prepares to execute the streams. Called after Analyze() and before Execute(). At this moment all requested streams are already subscribed.
/// This allows to setup progress hooks to setup correctly with the necessary data.
/// @param[in] inputs							Block of input streams to evaluate.
/// @param[in] targetTime					Target time to load.
/// @param[in] flags							See MEDIASESSIONFLAGS for details.
/// @return												OK on success.
		inline Result<void> PrepareExecute(const Block<const MediaConverterRef>& inputs, const TimeValue& targetTime, MEDIASESSIONFLAGS flags) const;
/// Executes the streams.
/// @param[in] inputs							Block of input streams to evaluate.
/// @param[in] targetTime					Target time to load.
/// @param[in] flags							See MEDIASESSIONFLAGS for details.
/// @return												OK on success.
		inline Result<void> Execute(const Block<const MediaConverterRef>& inputs, const TimeValue& targetTime, MEDIASESSIONFLAGS flags) const;
/// Closes the converter and closes all streams and operations.
/// @param[in] inputs							Block of input streams to close.
/// @return												OK on success.
		inline Result<void> Close(const Block<const MediaConverterRef>& inputs) const;
	};
	/// Intermediate helper class for MediaConverterInterface.
	template <typename S> class COWFn : public ConstFn<S>
	{
	public:
		COWFn() = default;
		using PrivateBaseClass = ConstFn<S>;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateBaseClass::PrivateLookupFn;
		static COWFn PrivateLookupFn(MediaConverterInterface**);
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, MediaConverterRef, false>::type&() { return reinterpret_cast<const MediaConverterRef&>(this->GetBaseRef()); }
/// Adds an output stream to the converter.
/// @return												OK on success.
		inline Result<void> AddOutputStream(const MediaStreamRef& stream);
/// Removes an output stream from the converter.
/// @return												OK on success.
		inline Result<void> RemoveOutputStream(const MediaStreamRef& stream);
/// Analyzes the streams. A converter needs to call the same function for all inputs
/// followed by calling stream.SubscribeStream() to signal the interest for one or more streams.
/// @param[in] inputs							Block of input streams to evaluate.
/// @param[in] targetTime					Target time to load.
/// @param[in] flags							See MEDIASESSIONFLAGS for details.
/// @return												OK on success.
		inline Result<void> Analyze(const Block<const MediaConverterRef>& inputs, const TimeValue& targetTime, MEDIASESSIONFLAGS flags);
/// Prepares to execute the streams. Called after Analyze() and before Execute(). At this moment all requested streams are already subscribed.
/// This allows to setup progress hooks to setup correctly with the necessary data.
/// @param[in] inputs							Block of input streams to evaluate.
/// @param[in] targetTime					Target time to load.
/// @param[in] flags							See MEDIASESSIONFLAGS for details.
/// @return												OK on success.
		inline Result<void> PrepareExecute(const Block<const MediaConverterRef>& inputs, const TimeValue& targetTime, MEDIASESSIONFLAGS flags);
/// Executes the streams.
/// @param[in] inputs							Block of input streams to evaluate.
/// @param[in] targetTime					Target time to load.
/// @param[in] flags							See MEDIASESSIONFLAGS for details.
/// @return												OK on success.
		inline Result<void> Execute(const Block<const MediaConverterRef>& inputs, const TimeValue& targetTime, MEDIASESSIONFLAGS flags);
/// Closes the converter and closes all streams and operations.
/// @param[in] inputs							Block of input streams to close.
/// @return												OK on success.
		inline Result<void> Close(const Block<const MediaConverterRef>& inputs);
	};
	template <typename ST> struct FnHelper : public std::conditional<
	maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)),
	COWFn<typename MediaBaseInterface::Hxx1::template FnHelper<ST>::type>,
	typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstFn<typename MediaBaseInterface::Hxx1::template FnHelper<ST>::type>, Fn<typename MediaBaseInterface::Hxx1::template FnHelper<ST>::type>>::type
	> { };
};
class MediaConverterInterface::Hxx1::Reference :
#ifdef DOXYGEN
public FnDoxy<MediaConverterRef>
#else
public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<MediaConverterInterface, maxon::StrongRefHandler, MediaConverterRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<MediaConverterInterface, maxon::StrongRefHandler, MediaConverterRef>>>>);
	using NonConst = typename Super::ReferenceClass;
};

/// MediaConverterRef is the reference class of MediaConverterInterface.
///
/// MediaConverterInterface is a generic interface to access media conversions.
/// It allows to connect streams and triggers the evaluation of the network.
class MediaConverterRef : public MediaConverterInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(MediaConverterRef, typename MediaConverterInterface::Hxx1::Reference);
	using ConstPtr = typename MediaConverterInterface::ConstPtr;
};

class MediaConverterError;

struct MediaConverterErrorInterface::HasBaseDetector { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, MediaConverterErrorInterface>::value || ErrorInterface::HasBaseDetector::template Check<I>::value; static I* Cast(MediaConverterErrorInterface* ptr) { return reinterpret_cast<I*>(ptr); } }; };
struct MediaConverterErrorObjectPrivateHelper;
struct MediaConverterErrorInterface::Hxx1
{
	class Reference;
	class NonConstRef;
	using ErrObj = MediaConverterErrorObjectPrivateHelper;
	using ReferenceClass = MediaConverterError;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<ErrorInterface>;
	/// Intermediate helper class for MediaConverterErrorInterface.
	template <typename S> class COWFn : public S
	{
	public:
		COWFn() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateBaseClass::PrivateLookupFn;
		static COWFn PrivateLookupFn(MediaConverterErrorInterface**);
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, MediaConverterError, false>::type&() const { return reinterpret_cast<const MediaConverterError&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, MediaConverterError, false>::type&() { return reinterpret_cast<const MediaConverterError&>(this->GetBaseRef()); }
	};
	template <typename ST> struct FnHelper : public std::conditional<
	maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)),
	COWFn<typename ErrorInterface::Hxx1::template FnHelper<ST>::type>,
	typename ErrorInterface::Hxx1::template FnHelper<ST>::type
	> { };
};
class MediaConverterErrorInterface::Hxx1::Reference :
#ifdef DOXYGEN
public COWFnDoxy<MediaConverterError>
#else
public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<const MediaConverterErrorInterface, maxon::StrongCOWRefHandler, MediaConverterError>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<const MediaConverterErrorInterface, maxon::StrongCOWRefHandler, MediaConverterError>>>>);
	using NonConst = Hxx1::NonConstRef;
};

class MediaConverterErrorInterface::Hxx1::NonConstRef :
#ifdef DOXYGEN
public FnDoxy<NonConstRef>
#else
public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<MediaConverterErrorInterface, maxon::StrongRefHandler, NonConstRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<MediaConverterErrorInterface, maxon::StrongRefHandler, NonConstRef>>>>);
};

/// MediaConverterError is the reference class of MediaConverterErrorInterface.
///
/// An MediaConverterError is returned if a media converter want to return an error.
class MediaConverterError : public MediaConverterErrorInterface::Hxx1::Reference
{
public:
	friend class MediaConverterErrorObject;
	friend class maxon::ResultBase<MediaConverterError>;
	MediaConverterError(maxon::ERROR_OK) { }
	PRIVATE_MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(MediaConverterError, typename MediaConverterErrorInterface::Hxx1::Reference);
	template <typename D> MediaConverterError(const D& allocLocation, typename D::SourceLocationMarker* dummy = nullptr) { maxon::SFINAEHelper<MediaConverterError, D>::type::Create(MAXON_SOURCE_LOCATION_FORWARD); }
	template <typename ARG1, typename... ARGS> MediaConverterError(MAXON_SOURCE_LOCATION_DECLARATION, ARG1&& arg1, ARGS&&... args) { maxon::SFINAEHelper<MediaConverterError, ARG1>::type::Create(MAXON_SOURCE_LOCATION_FORWARD, std::forward<ARG1>(arg1), std::forward<ARGS>(args)...); }
private:
	MediaConverterError() = default;
};

MAXON_DECLARATION(MediaConverterError, MediaConverterErrorObject, "net.maxon.image.error.mediaconverter");
#endif
