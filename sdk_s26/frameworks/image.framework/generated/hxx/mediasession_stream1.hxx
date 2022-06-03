#if 1
class MediaStreamRef;

struct MediaStreamInterface::HasBaseDetector { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, MediaStreamInterface>::value || MediaBaseInterface::HasBaseDetector::template Check<I>::value || HierarchyObjectInterface::HasBaseDetector::template Check<I>::value; static I* Cast(MediaStreamInterface* ptr) { return reinterpret_cast<I*>(ptr); } }; };
struct MediaStreamInterface::Hxx1
{
	class Reference;
	using ReferenceClass = MediaStreamRef;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<MediaBaseInterface, HierarchyObjectInterface>;
	/// Intermediate helper class for MediaStreamInterface.
	template <typename S> class ConstFn DOXYGEN_SWITCH_REVERSED(, : public S)
	{
	public:
		ConstFn() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateBaseClass::PrivateLookupFn;
		static ConstFn PrivateLookupFn(MediaStreamInterface**);
		using RESTRICT_DICTIONARY_PROPS = MediaStreamInterface::RESTRICT_DICTIONARY_PROPS;
/// returns the formatId of all available formats.
		inline Result<BaseArray<Data>> GetFormats() const;
/// returns the format of the given id.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<MediaStreamFormat>, MediaStreamFormat>::type GetFormat(const Data& formatId) const;
/// returns the selected format.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<const Data&>, const Data&>::type GetSelectedFormat() const;
/// Returns true if the stream is subscribed by a media converter.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type IsSubscribed() const;
	};
	/// Intermediate helper class for MediaStreamInterface.
	template <typename S> class Fn : public ConstFn<S>
	{
	public:
		Fn() = default;
		using PrivateBaseClass = ConstFn<S>;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateBaseClass::PrivateLookupFn;
		static Fn PrivateLookupFn(MediaStreamInterface**);
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, MediaStreamRef, true>::type&() const { return reinterpret_cast<const MediaStreamRef&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, MediaStreamRef, false>::type&() { return reinterpret_cast<const MediaStreamRef&>(this->GetBaseRef()); }
/// used by reader implementations to set the selected format of the stream. this must not be called from outside.
		inline Result<void> SetSelectedFormat(const Data& formatId) const;
/// used by reader implementations to add formats to the stream. this must not be called from outside.
		inline Result<void> AddFormat(const Data& formatId, const MediaStreamFormat& ref) const;
/// Subscribes to the stream. So if the media converter finds the data in the stream it triggers the specific callbacks defined by the inherited specialized interface.
/// this allows to read data directly to the place where it needs to by without additional memory copy.
/// @param[in] formatId						The selected format to subscribe.
/// @return												OK on success.
		inline Result<void> SubscribeStream(const Data& formatId) const;
/// Unsubscribes from the stream.
/// @return												OK on success.
		inline Result<void> UnsubscribeStream() const;
	};
	/// Intermediate helper class for MediaStreamInterface.
	template <typename S> class COWFn : public ConstFn<S>
	{
	public:
		COWFn() = default;
		using PrivateBaseClass = ConstFn<S>;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateBaseClass::PrivateLookupFn;
		static COWFn PrivateLookupFn(MediaStreamInterface**);
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, MediaStreamRef, false>::type&() { return reinterpret_cast<const MediaStreamRef&>(this->GetBaseRef()); }
/// used by reader implementations to set the selected format of the stream. this must not be called from outside.
		inline Result<void> SetSelectedFormat(const Data& formatId);
/// used by reader implementations to add formats to the stream. this must not be called from outside.
		inline Result<void> AddFormat(const Data& formatId, const MediaStreamFormat& ref);
/// Subscribes to the stream. So if the media converter finds the data in the stream it triggers the specific callbacks defined by the inherited specialized interface.
/// this allows to read data directly to the place where it needs to by without additional memory copy.
/// @param[in] formatId						The selected format to subscribe.
/// @return												OK on success.
		inline Result<void> SubscribeStream(const Data& formatId);
/// Unsubscribes from the stream.
/// @return												OK on success.
		inline Result<void> UnsubscribeStream();
	};
	template <typename ST> struct FnHelper : public std::conditional<
	maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)),
	COWFn<typename HierarchyObjectInterface::Hxx1::template FnHelper<typename MediaBaseInterface::Hxx1::template FnHelper<ST>, DefaultHierarchy<MediaStreamRef>>::type>,
	typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstFn<typename HierarchyObjectInterface::Hxx1::template FnHelper<typename MediaBaseInterface::Hxx1::template FnHelper<ST>, DefaultHierarchy<MediaStreamRef>>::type>, Fn<typename HierarchyObjectInterface::Hxx1::template FnHelper<typename MediaBaseInterface::Hxx1::template FnHelper<ST>, DefaultHierarchy<MediaStreamRef>>::type>>::type
	> { };
};
class MediaStreamInterface::Hxx1::Reference :
#ifdef DOXYGEN
public FnDoxy<MediaStreamRef>
#else
public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<MediaStreamInterface, maxon::StrongRefHandler, MediaStreamRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<MediaStreamInterface, maxon::StrongRefHandler, MediaStreamRef>>>>);
	using NonConst = typename Super::ReferenceClass;
};

/// MediaStreamRef is the reference class of MediaStreamInterface.
///
/// Single Stream within a MediaConverterInterface.
/// Streams might have sub streams as children (see HierarchyObjectInterface).
class MediaStreamRef : public MediaStreamInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(MediaStreamRef, typename MediaStreamInterface::Hxx1::Reference);
	using ConstPtr = typename MediaStreamInterface::ConstPtr;
};

class MediaStreamExifDataRef;

struct MediaStreamExifDataInterface::HasBaseDetector { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, MediaStreamExifDataInterface>::value || MediaStreamInterface::HasBaseDetector::template Check<I>::value; static I* Cast(MediaStreamExifDataInterface* ptr) { return reinterpret_cast<I*>(ptr); } }; };
struct MediaStreamExifDataInterface::Hxx1
{
	class Reference;
	using ReferenceClass = MediaStreamExifDataRef;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<MediaStreamInterface>;
	/// Intermediate helper class for MediaStreamExifDataInterface.
	template <typename S> class Fn : public S
	{
	public:
		Fn() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateBaseClass::PrivateLookupFn;
		static Fn PrivateLookupFn(MediaStreamExifDataInterface**);
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, MediaStreamExifDataRef, true>::type&() const { return reinterpret_cast<const MediaStreamExifDataRef&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, MediaStreamExifDataRef, false>::type&() { return reinterpret_cast<const MediaStreamExifDataRef&>(this->GetBaseRef()); }
/// Subscribes to the Exif data stream. So if the media converter triggers the callback as soon as the exif data is available.
/// @param[in] handleExifData			A handler which is called from the input media converter to signal that the exif data is
/// 															available for this stream.
/// @return												OK on success.
		inline Result<void> SetCallbackHandler(const ExifDataHandler& handleExifData) const;
		inline Result<void> HandleExifData(const ExifRef& exifData) const;
		inline Result<void> FinishStream(const MediaStreamProperties& props) const;
	};
	/// Intermediate helper class for MediaStreamExifDataInterface.
	template <typename S> class COWFn : public S
	{
	public:
		COWFn() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateBaseClass::PrivateLookupFn;
		static COWFn PrivateLookupFn(MediaStreamExifDataInterface**);
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, MediaStreamExifDataRef, false>::type&() { return reinterpret_cast<const MediaStreamExifDataRef&>(this->GetBaseRef()); }
/// Subscribes to the Exif data stream. So if the media converter triggers the callback as soon as the exif data is available.
/// @param[in] handleExifData			A handler which is called from the input media converter to signal that the exif data is
/// 															available for this stream.
/// @return												OK on success.
		inline Result<void> SetCallbackHandler(const ExifDataHandler& handleExifData);
		inline Result<void> HandleExifData(const ExifRef& exifData);
		inline Result<void> FinishStream(const MediaStreamProperties& props);
	};
	template <typename ST> struct FnHelper : public std::conditional<
	maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)),
	COWFn<typename MediaStreamInterface::Hxx1::template FnHelper<ST>::type>,
	typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, typename MediaStreamInterface::Hxx1::template FnHelper<ST>::type, Fn<typename MediaStreamInterface::Hxx1::template FnHelper<ST>::type>>::type
	> { };
};
class MediaStreamExifDataInterface::Hxx1::Reference :
#ifdef DOXYGEN
public FnDoxy<MediaStreamExifDataRef>
#else
public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<MediaStreamExifDataInterface, maxon::StrongRefHandler, MediaStreamExifDataRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<MediaStreamExifDataInterface, maxon::StrongRefHandler, MediaStreamExifDataRef>>>>);
	using NonConst = typename Super::ReferenceClass;
};

/// MediaStreamExifDataRef is the reference class of MediaStreamExifDataInterface.
///
/// Stream which delivers EXIF data.
class MediaStreamExifDataRef : public MediaStreamExifDataInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(MediaStreamExifDataRef, typename MediaStreamExifDataInterface::Hxx1::Reference);
	using ConstPtr = typename MediaStreamExifDataInterface::ConstPtr;
};

class MediaStreamImageBaseRef;

struct MediaStreamImageBaseInterface::HasBaseDetector { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, MediaStreamImageBaseInterface>::value || MediaStreamInterface::HasBaseDetector::template Check<I>::value; static I* Cast(MediaStreamImageBaseInterface* ptr) { return reinterpret_cast<I*>(ptr); } }; };
struct MediaStreamImageBaseInterface::Hxx1
{
	class Reference;
	using ReferenceClass = MediaStreamImageBaseRef;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<MediaStreamInterface>;
	/// Intermediate helper class for MediaStreamImageBaseInterface.
	template <typename S> class Fn : public S
	{
	public:
		Fn() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateBaseClass::PrivateLookupFn;
		static Fn PrivateLookupFn(MediaStreamImageBaseInterface**);
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, MediaStreamImageBaseRef, true>::type&() const { return reinterpret_cast<const MediaStreamImageBaseRef&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, MediaStreamImageBaseRef, false>::type&() { return reinterpret_cast<const MediaStreamImageBaseRef&>(this->GetBaseRef()); }
	};
	/// Intermediate helper class for MediaStreamImageBaseInterface.
	template <typename S> class COWFn : public S
	{
	public:
		COWFn() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateBaseClass::PrivateLookupFn;
		static COWFn PrivateLookupFn(MediaStreamImageBaseInterface**);
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, MediaStreamImageBaseRef, false>::type&() { return reinterpret_cast<const MediaStreamImageBaseRef&>(this->GetBaseRef()); }
	};
	template <typename ST> struct FnHelper : public std::conditional<
	maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)),
	COWFn<typename MediaStreamInterface::Hxx1::template FnHelper<ST>::type>,
	typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, typename MediaStreamInterface::Hxx1::template FnHelper<ST>::type, Fn<typename MediaStreamInterface::Hxx1::template FnHelper<ST>::type>>::type
	> { };
};
class MediaStreamImageBaseInterface::Hxx1::Reference :
#ifdef DOXYGEN
public FnDoxy<MediaStreamImageBaseRef>
#else
public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<MediaStreamImageBaseInterface, maxon::StrongRefHandler, MediaStreamImageBaseRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<MediaStreamImageBaseInterface, maxon::StrongRefHandler, MediaStreamImageBaseRef>>>>);
	using NonConst = typename Super::ReferenceClass;
};

/// MediaStreamImageBaseRef is the reference class of MediaStreamImageBaseInterface.
///
/// Base class for stream which delivers image data.
class MediaStreamImageBaseRef : public MediaStreamImageBaseInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(MediaStreamImageBaseRef, typename MediaStreamImageBaseInterface::Hxx1::Reference);
	using ConstPtr = typename MediaStreamImageBaseInterface::ConstPtr;
};

class MediaStreamImageDataImportRef;

struct MediaStreamImageDataImportInterface::HasBaseDetector { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, MediaStreamImageDataImportInterface>::value || MediaStreamImageBaseInterface::HasBaseDetector::template Check<I>::value; static I* Cast(MediaStreamImageDataImportInterface* ptr) { return reinterpret_cast<I*>(ptr); } }; };
struct MediaStreamImageDataImportInterface::Hxx1
{
	class Reference;
	using ReferenceClass = MediaStreamImageDataImportRef;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<MediaStreamImageBaseInterface>;
	/// Intermediate helper class for MediaStreamImageDataImportInterface.
	template <typename S> class Fn : public S
	{
	public:
		Fn() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateBaseClass::PrivateLookupFn;
		static Fn PrivateLookupFn(MediaStreamImageDataImportInterface**);
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, MediaStreamImageDataImportRef, true>::type&() const { return reinterpret_cast<const MediaStreamImageDataImportRef&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, MediaStreamImageDataImportRef, false>::type&() { return reinterpret_cast<const MediaStreamImageDataImportRef&>(this->GetBaseRef()); }
/// Subscribes to the stream. So if the media converter loads the stream the setPixelHandler callback is triggered.
/// this allows to read data directly to the place where it needs to by without additional memory copy.
/// @param[in] initHandler				A handler which is called from the input media converter to signal that data is
/// 															available for this frame of the stream.
/// @param[in] setPixelHandler		A handler which is called for each thread that needs a valid SetPixelHandlerStruct
/// 															which will be used by the input converter to set the pixel data.
/// @param[in] finishHandler			A handler which is called from the input media converter to signal that data loading
/// 															the data from this stream is finished for this frame of the stream.
/// @return												OK on success.
		inline Result<void> SetCallbackHandler(const InitHandler& initHandler, const SetPixelHandler& setPixelHandler, const FinishHandler& finishHandler) const;
/// called by the input media converter implementation before loading a stream.
/// @param[in] props							Properties of the source image stream.
/// @return												OK on success.
		inline Result<void> InitStream(const MediaStreamProperties& props) const;
/// called by the input media converter implementation before loading a stream.
/// @param[in] props							Properties of the source image stream.
/// @param[in] srcChannelOffsets	Source channel offsets of the data that will be set using this set pixel handler.
/// @param[in] setPixelFlags			Flags which control the set pixel operation. See also SETPIXELHANDLERFLAGS.
/// @return												OK on success.
		inline Result<SetPixelHandlerStruct> SetPixelStream(const MediaStreamProperties& props, const ChannelOffsets& srcChannelOffsets, SETPIXELHANDLERFLAGS setPixelFlags) const;
/// called by the input media converter implementation when loading the stream is completed.
/// @param[in] props							Properties of the source image stream.
/// @return												OK on success.
		inline Result<void> FinishStream(const MediaStreamProperties& props) const;
	};
	/// Intermediate helper class for MediaStreamImageDataImportInterface.
	template <typename S> class COWFn : public S
	{
	public:
		COWFn() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateBaseClass::PrivateLookupFn;
		static COWFn PrivateLookupFn(MediaStreamImageDataImportInterface**);
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, MediaStreamImageDataImportRef, false>::type&() { return reinterpret_cast<const MediaStreamImageDataImportRef&>(this->GetBaseRef()); }
/// Subscribes to the stream. So if the media converter loads the stream the setPixelHandler callback is triggered.
/// this allows to read data directly to the place where it needs to by without additional memory copy.
/// @param[in] initHandler				A handler which is called from the input media converter to signal that data is
/// 															available for this frame of the stream.
/// @param[in] setPixelHandler		A handler which is called for each thread that needs a valid SetPixelHandlerStruct
/// 															which will be used by the input converter to set the pixel data.
/// @param[in] finishHandler			A handler which is called from the input media converter to signal that data loading
/// 															the data from this stream is finished for this frame of the stream.
/// @return												OK on success.
		inline Result<void> SetCallbackHandler(const InitHandler& initHandler, const SetPixelHandler& setPixelHandler, const FinishHandler& finishHandler);
/// called by the input media converter implementation before loading a stream.
/// @param[in] props							Properties of the source image stream.
/// @return												OK on success.
		inline Result<void> InitStream(const MediaStreamProperties& props);
/// called by the input media converter implementation before loading a stream.
/// @param[in] props							Properties of the source image stream.
/// @param[in] srcChannelOffsets	Source channel offsets of the data that will be set using this set pixel handler.
/// @param[in] setPixelFlags			Flags which control the set pixel operation. See also SETPIXELHANDLERFLAGS.
/// @return												OK on success.
		inline Result<SetPixelHandlerStruct> SetPixelStream(const MediaStreamProperties& props, const ChannelOffsets& srcChannelOffsets, SETPIXELHANDLERFLAGS setPixelFlags);
/// called by the input media converter implementation when loading the stream is completed.
/// @param[in] props							Properties of the source image stream.
/// @return												OK on success.
		inline Result<void> FinishStream(const MediaStreamProperties& props);
	};
	template <typename ST> struct FnHelper : public std::conditional<
	maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)),
	COWFn<typename MediaStreamImageBaseInterface::Hxx1::template FnHelper<ST>::type>,
	typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, typename MediaStreamImageBaseInterface::Hxx1::template FnHelper<ST>::type, Fn<typename MediaStreamImageBaseInterface::Hxx1::template FnHelper<ST>::type>>::type
	> { };
};
class MediaStreamImageDataImportInterface::Hxx1::Reference :
#ifdef DOXYGEN
public FnDoxy<MediaStreamImageDataImportRef>
#else
public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<MediaStreamImageDataImportInterface, maxon::StrongRefHandler, MediaStreamImageDataImportRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<MediaStreamImageDataImportInterface, maxon::StrongRefHandler, MediaStreamImageDataImportRef>>>>);
	using NonConst = typename Super::ReferenceClass;
};

/// MediaStreamImageDataImportRef is the reference class of MediaStreamImageDataImportInterface.
///
/// Stream which represents full image data.
class MediaStreamImageDataImportRef : public MediaStreamImageDataImportInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(MediaStreamImageDataImportRef, typename MediaStreamImageDataImportInterface::Hxx1::Reference);
	using ConstPtr = typename MediaStreamImageDataImportInterface::ConstPtr;
};

class MediaStreamImageDataExportRef;

struct MediaStreamImageDataExportInterface::HasBaseDetector { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, MediaStreamImageDataExportInterface>::value || MediaStreamImageBaseInterface::HasBaseDetector::template Check<I>::value; static I* Cast(MediaStreamImageDataExportInterface* ptr) { return reinterpret_cast<I*>(ptr); } }; };
struct MediaStreamImageDataExportInterface::Hxx1
{
	class Reference;
	using ReferenceClass = MediaStreamImageDataExportRef;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<MediaStreamImageBaseInterface>;
	/// Intermediate helper class for MediaStreamImageDataExportInterface.
	template <typename S> class Fn : public S
	{
	public:
		Fn() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateBaseClass::PrivateLookupFn;
		static Fn PrivateLookupFn(MediaStreamImageDataExportInterface**);
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, MediaStreamImageDataExportRef, true>::type&() const { return reinterpret_cast<const MediaStreamImageDataExportRef&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, MediaStreamImageDataExportRef, false>::type&() { return reinterpret_cast<const MediaStreamImageDataExportRef&>(this->GetBaseRef()); }
/// Subscribes to the stream. So if the media converter loads the stream the setPixelHandler callback is triggered.
/// this allows to read data directly to the place where it needs to by without additional memory copy.
/// @param[in] initHandler				A handler which is called from the output media converter to signal that data is
/// 															required for this frame of the stream.
/// @param[in] getPixelHandler		A handler which is called for each thread that needs a valid GetPixelHandlerStruct
/// 															which will be used by the output converter to get the pixel data.
/// @param[in] finishHandler			A handler which is called from the output media converter to signal that data writing
/// 															the data from this stream is finished for this frame of the stream.
/// @return												OK on success.
		inline Result<void> SetCallbackHandler(const InitHandler& initHandler, const GetPixelHandler& getPixelHandler, const FinishHandler& finishHandler) const;
/// called by the input media converter implementation before loading a stream.
/// @param[in] props							Properties of the image stream.
/// @return												OK on success.
		inline Result<void> InitStream(MediaStreamProperties& props) const;
/// called by the input media converter implementation before loading a stream.
/// @param[in] props							Properties of the image stream.
/// @param[in] dstFormat					Destination pixel format.
/// @param[in] channelOffsets			Channel offset that is needed in the destination.
/// @param[in] dstColorProfile		Destination color profile.
/// @param[in] flags							See GETPIXELHANDLERFLAGS flags.
/// @return												OK on success.
		inline Result<GetPixelHandlerStruct> GetPixelStream(const MediaStreamProperties& props, const PixelFormat& dstFormat, const ChannelOffsets& channelOffsets, const ColorProfile& dstColorProfile, GETPIXELHANDLERFLAGS flags) const;
/// called by the input media converter implementation when loading the stream is completed.
/// @param[in] props							Properties of the image stream.
/// @return												OK on success.
		inline Result<void> FinishStream(const MediaStreamProperties& props) const;
	};
	/// Intermediate helper class for MediaStreamImageDataExportInterface.
	template <typename S> class COWFn : public S
	{
	public:
		COWFn() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateBaseClass::PrivateLookupFn;
		static COWFn PrivateLookupFn(MediaStreamImageDataExportInterface**);
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, MediaStreamImageDataExportRef, false>::type&() { return reinterpret_cast<const MediaStreamImageDataExportRef&>(this->GetBaseRef()); }
/// Subscribes to the stream. So if the media converter loads the stream the setPixelHandler callback is triggered.
/// this allows to read data directly to the place where it needs to by without additional memory copy.
/// @param[in] initHandler				A handler which is called from the output media converter to signal that data is
/// 															required for this frame of the stream.
/// @param[in] getPixelHandler		A handler which is called for each thread that needs a valid GetPixelHandlerStruct
/// 															which will be used by the output converter to get the pixel data.
/// @param[in] finishHandler			A handler which is called from the output media converter to signal that data writing
/// 															the data from this stream is finished for this frame of the stream.
/// @return												OK on success.
		inline Result<void> SetCallbackHandler(const InitHandler& initHandler, const GetPixelHandler& getPixelHandler, const FinishHandler& finishHandler);
/// called by the input media converter implementation before loading a stream.
/// @param[in] props							Properties of the image stream.
/// @return												OK on success.
		inline Result<void> InitStream(MediaStreamProperties& props);
/// called by the input media converter implementation before loading a stream.
/// @param[in] props							Properties of the image stream.
/// @param[in] dstFormat					Destination pixel format.
/// @param[in] channelOffsets			Channel offset that is needed in the destination.
/// @param[in] dstColorProfile		Destination color profile.
/// @param[in] flags							See GETPIXELHANDLERFLAGS flags.
/// @return												OK on success.
		inline Result<GetPixelHandlerStruct> GetPixelStream(const MediaStreamProperties& props, const PixelFormat& dstFormat, const ChannelOffsets& channelOffsets, const ColorProfile& dstColorProfile, GETPIXELHANDLERFLAGS flags);
/// called by the input media converter implementation when loading the stream is completed.
/// @param[in] props							Properties of the image stream.
/// @return												OK on success.
		inline Result<void> FinishStream(const MediaStreamProperties& props);
	};
	template <typename ST> struct FnHelper : public std::conditional<
	maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)),
	COWFn<typename MediaStreamImageBaseInterface::Hxx1::template FnHelper<ST>::type>,
	typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, typename MediaStreamImageBaseInterface::Hxx1::template FnHelper<ST>::type, Fn<typename MediaStreamImageBaseInterface::Hxx1::template FnHelper<ST>::type>>::type
	> { };
};
class MediaStreamImageDataExportInterface::Hxx1::Reference :
#ifdef DOXYGEN
public FnDoxy<MediaStreamImageDataExportRef>
#else
public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<MediaStreamImageDataExportInterface, maxon::StrongRefHandler, MediaStreamImageDataExportRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<MediaStreamImageDataExportInterface, maxon::StrongRefHandler, MediaStreamImageDataExportRef>>>>);
	using NonConst = typename Super::ReferenceClass;
};

/// MediaStreamImageDataExportRef is the reference class of MediaStreamImageDataExportInterface.
///
/// Stream which represents full image data.
class MediaStreamImageDataExportRef : public MediaStreamImageDataExportInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(MediaStreamImageDataExportRef, typename MediaStreamImageDataExportInterface::Hxx1::Reference);
	using ConstPtr = typename MediaStreamImageDataExportInterface::ConstPtr;
};

class MediaStreamImageDataForwardImportRef;

struct MediaStreamImageDataForwardImportInterface::HasBaseDetector { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, MediaStreamImageDataForwardImportInterface>::value || MediaStreamImageDataImportInterface::HasBaseDetector::template Check<I>::value; static I* Cast(MediaStreamImageDataForwardImportInterface* ptr) { return reinterpret_cast<I*>(ptr); } }; };
struct MediaStreamImageDataForwardImportInterface::Hxx1
{
	class Reference;
	using ReferenceClass = MediaStreamImageDataForwardImportRef;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<MediaStreamImageDataImportInterface>;
	/// Intermediate helper class for MediaStreamImageDataForwardImportInterface.
	template <typename S> class Fn : public S
	{
	public:
		Fn() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateBaseClass::PrivateLookupFn;
		static Fn PrivateLookupFn(MediaStreamImageDataForwardImportInterface**);
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, MediaStreamImageDataForwardImportRef, true>::type&() const { return reinterpret_cast<const MediaStreamImageDataForwardImportRef&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, MediaStreamImageDataForwardImportRef, false>::type&() { return reinterpret_cast<const MediaStreamImageDataForwardImportRef&>(this->GetBaseRef()); }
/// @param[in] sourceStream				Stream that should be forwarded.
		inline Result<void> SetSourceStream(const MediaStreamImageDataImportRef& sourceStream) const;
	};
	/// Intermediate helper class for MediaStreamImageDataForwardImportInterface.
	template <typename S> class COWFn : public S
	{
	public:
		COWFn() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateBaseClass::PrivateLookupFn;
		static COWFn PrivateLookupFn(MediaStreamImageDataForwardImportInterface**);
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, MediaStreamImageDataForwardImportRef, false>::type&() { return reinterpret_cast<const MediaStreamImageDataForwardImportRef&>(this->GetBaseRef()); }
/// @param[in] sourceStream				Stream that should be forwarded.
		inline Result<void> SetSourceStream(const MediaStreamImageDataImportRef& sourceStream);
	};
	template <typename ST> struct FnHelper : public std::conditional<
	maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)),
	COWFn<typename MediaStreamImageDataImportInterface::Hxx1::template FnHelper<ST>::type>,
	typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, typename MediaStreamImageDataImportInterface::Hxx1::template FnHelper<ST>::type, Fn<typename MediaStreamImageDataImportInterface::Hxx1::template FnHelper<ST>::type>>::type
	> { };
};
class MediaStreamImageDataForwardImportInterface::Hxx1::Reference :
#ifdef DOXYGEN
public FnDoxy<MediaStreamImageDataForwardImportRef>
#else
public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<MediaStreamImageDataForwardImportInterface, maxon::StrongRefHandler, MediaStreamImageDataForwardImportRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<MediaStreamImageDataForwardImportInterface, maxon::StrongRefHandler, MediaStreamImageDataForwardImportRef>>>>);
	using NonConst = typename Super::ReferenceClass;
};

/// MediaStreamImageDataForwardImportRef is the reference class of MediaStreamImageDataForwardImportInterface.
class MediaStreamImageDataForwardImportRef : public MediaStreamImageDataForwardImportInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(MediaStreamImageDataForwardImportRef, typename MediaStreamImageDataForwardImportInterface::Hxx1::Reference);
	using ConstPtr = typename MediaStreamImageDataForwardImportInterface::ConstPtr;
};

class MediaStreamAudioDataImportRef;

struct MediaStreamAudioDataImportInterface::HasBaseDetector { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, MediaStreamAudioDataImportInterface>::value || MediaStreamInterface::HasBaseDetector::template Check<I>::value; static I* Cast(MediaStreamAudioDataImportInterface* ptr) { return reinterpret_cast<I*>(ptr); } }; };
struct MediaStreamAudioDataImportInterface::Hxx1
{
	class Reference;
	using ReferenceClass = MediaStreamAudioDataImportRef;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<MediaStreamInterface>;
	/// Intermediate helper class for MediaStreamAudioDataImportInterface.
	template <typename S> class Fn : public S
	{
	public:
		Fn() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateBaseClass::PrivateLookupFn;
		static Fn PrivateLookupFn(MediaStreamAudioDataImportInterface**);
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, MediaStreamAudioDataImportRef, true>::type&() const { return reinterpret_cast<const MediaStreamAudioDataImportRef&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, MediaStreamAudioDataImportRef, false>::type&() { return reinterpret_cast<const MediaStreamAudioDataImportRef&>(this->GetBaseRef()); }
/// SetCallbackHandler description.
/// @param[in] initHandler				A handler which is called from the output media converter to signal that data is
/// 															required for this frame of the stream.
/// @param[in] getAudioDataHandler	A handler which is called for each thread that needs a valid SetAudioHandlerDataCallback.
/// @param[in] finishHandler			A handler which is called from the output media converter to signal that data writing
/// 															the data from this stream is finished for this frame of the stream.
/// @return												OK on success.
		inline Result<void> SetCallbackHandler(const InitHandler& initHandler, const SetAudioDataHandler& getAudioDataHandler, const FinishHandler& finishHandler) const;
/// called by the input media converter implementation before loading a stream.
/// @param[in] props							Properties of the image stream.
/// @return												OK on success.
		inline Result<void> InitStream(MediaStreamProperties& props) const;
/// SetAudioDataCallback description.
/// @param[in] props							Properties of the audio stream.
/// @return												OK on success.
		inline Result<SetAudioDataCallbackType> SetAudioDataCallback(MediaStreamProperties& props) const;
/// called by the input media converter implementation when loading the stream is completed.
/// @param[in] props							Properties of the audio stream.
/// @return												OK on success.
		inline Result<void> FinishStream(const MediaStreamProperties& props) const;
	};
	/// Intermediate helper class for MediaStreamAudioDataImportInterface.
	template <typename S> class COWFn : public S
	{
	public:
		COWFn() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateBaseClass::PrivateLookupFn;
		static COWFn PrivateLookupFn(MediaStreamAudioDataImportInterface**);
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, MediaStreamAudioDataImportRef, false>::type&() { return reinterpret_cast<const MediaStreamAudioDataImportRef&>(this->GetBaseRef()); }
/// SetCallbackHandler description.
/// @param[in] initHandler				A handler which is called from the output media converter to signal that data is
/// 															required for this frame of the stream.
/// @param[in] getAudioDataHandler	A handler which is called for each thread that needs a valid SetAudioHandlerDataCallback.
/// @param[in] finishHandler			A handler which is called from the output media converter to signal that data writing
/// 															the data from this stream is finished for this frame of the stream.
/// @return												OK on success.
		inline Result<void> SetCallbackHandler(const InitHandler& initHandler, const SetAudioDataHandler& getAudioDataHandler, const FinishHandler& finishHandler);
/// called by the input media converter implementation before loading a stream.
/// @param[in] props							Properties of the image stream.
/// @return												OK on success.
		inline Result<void> InitStream(MediaStreamProperties& props);
/// SetAudioDataCallback description.
/// @param[in] props							Properties of the audio stream.
/// @return												OK on success.
		inline Result<SetAudioDataCallbackType> SetAudioDataCallback(MediaStreamProperties& props);
/// called by the input media converter implementation when loading the stream is completed.
/// @param[in] props							Properties of the audio stream.
/// @return												OK on success.
		inline Result<void> FinishStream(const MediaStreamProperties& props);
	};
	template <typename ST> struct FnHelper : public std::conditional<
	maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)),
	COWFn<typename MediaStreamInterface::Hxx1::template FnHelper<ST>::type>,
	typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, typename MediaStreamInterface::Hxx1::template FnHelper<ST>::type, Fn<typename MediaStreamInterface::Hxx1::template FnHelper<ST>::type>>::type
	> { };
};
class MediaStreamAudioDataImportInterface::Hxx1::Reference :
#ifdef DOXYGEN
public FnDoxy<MediaStreamAudioDataImportRef>
#else
public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<MediaStreamAudioDataImportInterface, maxon::StrongRefHandler, MediaStreamAudioDataImportRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<MediaStreamAudioDataImportInterface, maxon::StrongRefHandler, MediaStreamAudioDataImportRef>>>>);
	using NonConst = typename Super::ReferenceClass;
};

/// MediaStreamAudioDataImportRef is the reference class of MediaStreamAudioDataImportInterface.
///
/// Stream which represents full image data.
class MediaStreamAudioDataImportRef : public MediaStreamAudioDataImportInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(MediaStreamAudioDataImportRef, typename MediaStreamAudioDataImportInterface::Hxx1::Reference);
	using ConstPtr = typename MediaStreamAudioDataImportInterface::ConstPtr;
};

#endif
