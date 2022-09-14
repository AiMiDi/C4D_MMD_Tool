#if 1
class MediaOutputRef;

struct MediaOutputInterface::HasBaseDetector { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, MediaOutputInterface>::value || MediaConverterInterface::HasBaseDetector::template Check<I>::value; static I* Cast(MediaOutputInterface* ptr) { return reinterpret_cast<I*>(ptr); } }; };
struct MediaOutputInterface::Hxx1
{
	class Reference;
	using ReferenceClass = MediaOutputRef;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<MediaConverterInterface>;
	/// Intermediate helper class for MediaOutputInterface.
	template <typename S> class ConstFn DOXYGEN_SWITCH_REVERSED(, : public S)
	{
	public:
		ConstFn() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateBaseClass::PrivateLookupFn;
		static ConstFn PrivateLookupFn(MediaOutputInterface**);
/// Sets a selection handler to be called as soon as a new stream is recognized.
/// @return												OK on success.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<const MediaOutputSelectionHandler&>, const MediaOutputSelectionHandler&>::type GetSelectionHandler() const;
	};
	/// Intermediate helper class for MediaOutputInterface.
	template <typename S> class Fn : public ConstFn<S>
	{
	public:
		Fn() = default;
		using PrivateBaseClass = ConstFn<S>;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateBaseClass::PrivateLookupFn;
		static Fn PrivateLookupFn(MediaOutputInterface**);
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, MediaOutputRef, true>::type&() const { return reinterpret_cast<const MediaOutputRef&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, MediaOutputRef, false>::type&() { return reinterpret_cast<const MediaOutputRef&>(this->GetBaseRef()); }
/// Resets the converter to default state.
/// This function will be called if the converter is reused and needs to be reinitialized.
/// @return												OK on success.
		inline Result<void> ResetConverter() const;
/// Sets a selection handler to be called as soon as a new stream is recognized.
/// @param[in] selectionHandler		Handler to be called.
/// @return												OK on success.
		inline Result<void> SetSelectionHandler(const MediaOutputSelectionHandler& selectionHandler) const;
/// Called by the input media converter implementation before loading a stream.
/// This function triggers the execution of the MediaOutputSelectionHandler set with SetSelectionHandler.
/// @param[in] stream							Stream to check for filtering.
/// @param[in] props							Properties of the stream. This can be used to filter for names or special formats etc.
/// @return												OK on success.
		inline Result<SELECTIONHANDLERRESULT> CallSelectionHandler(const MediaStreamRef& stream, const MediaStreamFormat& props) const;
	};
	/// Intermediate helper class for MediaOutputInterface.
	template <typename S> class COWFn : public ConstFn<S>
	{
	public:
		COWFn() = default;
		using PrivateBaseClass = ConstFn<S>;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateBaseClass::PrivateLookupFn;
		static COWFn PrivateLookupFn(MediaOutputInterface**);
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, MediaOutputRef, false>::type&() { return reinterpret_cast<const MediaOutputRef&>(this->GetBaseRef()); }
/// Resets the converter to default state.
/// This function will be called if the converter is reused and needs to be reinitialized.
/// @return												OK on success.
		inline Result<void> ResetConverter();
/// Sets a selection handler to be called as soon as a new stream is recognized.
/// @param[in] selectionHandler		Handler to be called.
/// @return												OK on success.
		inline Result<void> SetSelectionHandler(const MediaOutputSelectionHandler& selectionHandler);
/// Called by the input media converter implementation before loading a stream.
/// This function triggers the execution of the MediaOutputSelectionHandler set with SetSelectionHandler.
/// @param[in] stream							Stream to check for filtering.
/// @param[in] props							Properties of the stream. This can be used to filter for names or special formats etc.
/// @return												OK on success.
		inline Result<SELECTIONHANDLERRESULT> CallSelectionHandler(const MediaStreamRef& stream, const MediaStreamFormat& props);
	};
	template <typename ST> struct FnHelper : public std::conditional<
	maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)),
	COWFn<typename MediaConverterInterface::Hxx1::template FnHelper<ST>::type>,
	typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstFn<typename MediaConverterInterface::Hxx1::template FnHelper<ST>::type>, Fn<typename MediaConverterInterface::Hxx1::template FnHelper<ST>::type>>::type
	> { };
};
class MediaOutputInterface::Hxx1::Reference :
#ifdef DOXYGEN
public FnDoxy<MediaOutputRef>
#else
public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<MediaOutputInterface, maxon::StrongRefHandler, MediaOutputRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<MediaOutputInterface, maxon::StrongRefHandler, MediaOutputRef>>>>);
	using NonConst = typename Super::ReferenceClass;
};

/// MediaOutputRef is the reference class of MediaOutputInterface.
///
/// The MediaOutputInterface class provides an specific implementation to provide output data to a given destination.
class MediaOutputRef : public MediaOutputInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(MediaOutputRef, typename MediaOutputInterface::Hxx1::Reference);
	using ConstPtr = typename MediaOutputInterface::ConstPtr;
};

class MediaOutputTextureRef;

struct MediaOutputTextureInterface::HasBaseDetector { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, MediaOutputTextureInterface>::value || MediaOutputInterface::HasBaseDetector::template Check<I>::value; static I* Cast(MediaOutputTextureInterface* ptr) { return reinterpret_cast<I*>(ptr); } }; };
struct MediaOutputTextureInterface::Hxx1
{
	class Reference;
	using ReferenceClass = MediaOutputTextureRef;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<MediaOutputInterface>;
	/// Intermediate helper class for MediaOutputTextureInterface.
	template <typename S> class Fn : public S
	{
	public:
		Fn() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateBaseClass::PrivateLookupFn;
		static Fn PrivateLookupFn(MediaOutputTextureInterface**);
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, MediaOutputTextureRef, true>::type&() const { return reinterpret_cast<const MediaOutputTextureRef&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, MediaOutputTextureRef, false>::type&() { return reinterpret_cast<const MediaOutputTextureRef&>(this->GetBaseRef()); }
/// Sets the output texture link.
/// @param[in] textureRef					Target texture to load the media data into.
/// @param[in] pixelStorageClass	Defines the storage class how newly created layers/images should store their pixel data (e.g.
///																ImagePixelStorageClasses::Voxel).
		inline Result<void> SetOutputTexture(const ImageTextureRef& textureRef, const Class<ImagePixelStorage>& pixelStorageClass) const;
	};
	/// Intermediate helper class for MediaOutputTextureInterface.
	template <typename S> class COWFn : public S
	{
	public:
		COWFn() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateBaseClass::PrivateLookupFn;
		static COWFn PrivateLookupFn(MediaOutputTextureInterface**);
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, MediaOutputTextureRef, false>::type&() { return reinterpret_cast<const MediaOutputTextureRef&>(this->GetBaseRef()); }
/// Sets the output texture link.
/// @param[in] textureRef					Target texture to load the media data into.
/// @param[in] pixelStorageClass	Defines the storage class how newly created layers/images should store their pixel data (e.g.
///																ImagePixelStorageClasses::Voxel).
		inline Result<void> SetOutputTexture(const ImageTextureRef& textureRef, const Class<ImagePixelStorage>& pixelStorageClass);
	};
	template <typename ST> struct FnHelper : public std::conditional<
	maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)),
	COWFn<typename MediaOutputInterface::Hxx1::template FnHelper<ST>::type>,
	typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, typename MediaOutputInterface::Hxx1::template FnHelper<ST>::type, Fn<typename MediaOutputInterface::Hxx1::template FnHelper<ST>::type>>::type
	> { };
};
class MediaOutputTextureInterface::Hxx1::Reference :
#ifdef DOXYGEN
public FnDoxy<MediaOutputTextureRef>
#else
public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<MediaOutputTextureInterface, maxon::StrongRefHandler, MediaOutputTextureRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<MediaOutputTextureInterface, maxon::StrongRefHandler, MediaOutputTextureRef>>>>);
	using NonConst = typename Super::ReferenceClass;
};

/// MediaOutputTextureRef is the reference class of MediaOutputTextureInterface.
///
/// The MediaOutputInterface class provides an specific implementation to provide output data to a given destination.
class MediaOutputTextureRef : public MediaOutputTextureInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(MediaOutputTextureRef, typename MediaOutputTextureInterface::Hxx1::Reference);
	using ConstPtr = typename MediaOutputTextureInterface::ConstPtr;
};

namespace MEDIAOUTPUTURLPROPERTIES
{
#ifndef PRIVATE_MAXON_GUARD_maxon_MEDIAOUTPUTURLPROPERTIES
#define PRIVATE_MAXON_GUARD_maxon_MEDIAOUTPUTURLPROPERTIES
	class RESTRICT : public maxon::RESTRICT { }; template <typename T> RESTRICT TestRestriction(T y, maxon::OverloadRank1);
#endif
}
class MediaOutputUrlRef;

struct MediaOutputUrlInterface::HasBaseDetector { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, MediaOutputUrlInterface>::value || MediaOutputInterface::HasBaseDetector::template Check<I>::value; static I* Cast(MediaOutputUrlInterface* ptr) { return reinterpret_cast<I*>(ptr); } }; };
struct MediaOutputUrlInterface::Hxx1
{
	class Reference;
	using ReferenceClass = MediaOutputUrlRef;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<MediaOutputInterface>;
	/// Intermediate helper class for MediaOutputUrlInterface.
	template <typename S> class ConstFn DOXYGEN_SWITCH_REVERSED(, : public S)
	{
	public:
		ConstFn() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateBaseClass::PrivateLookupFn;
		static ConstFn PrivateLookupFn(MediaOutputUrlInterface**);
/// Returns the output url.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Url>, Url>::type GetOutputUrl() const;
/// Returns the corresponding file format.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<const FileFormat&>, const FileFormat&>::type GetFileFormat() const;
/// Verifies the given resolution for the save format (e.g. mp4 quantizes the width to the next 16 boundary).
/// @param[in] settings						Save Settings.
/// @param[in] bitmapSize					Given input bitmap size.
/// @return												Corrected bitmap size if the save cannot handle the given size, otherwise the given size.
		inline Result<DrawDimensionInt> CheckBitmapSize(const DataDictionary& settings, const DrawDimensionInt& bitmapSize) const;
	};
	/// Intermediate helper class for MediaOutputUrlInterface.
	template <typename S> class Fn : public ConstFn<S>
	{
	public:
		Fn() = default;
		using PrivateBaseClass = ConstFn<S>;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateBaseClass::PrivateLookupFn;
		static Fn PrivateLookupFn(MediaOutputUrlInterface**);
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, MediaOutputUrlRef, true>::type&() const { return reinterpret_cast<const MediaOutputUrlRef&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, MediaOutputUrlRef, false>::type&() { return reinterpret_cast<const MediaOutputUrlRef&>(this->GetBaseRef()); }
/// Sets the url to which this output converter should write it's data.
/// @param[in] url								Url to write to.
/// @return												OK on success.
		inline Result<void> SetOutputUrl(const Url& url) const;
/// EditSystemOptions opens a system compressor options dialog to allow the user to choose compressor settings for a specific codec.
/// @param[in,out] settings				Settings to be displayed and modified. After calling the function the DataDictionary contains the new settings.
/// @param[in] getParentwindowHandle	Callback to return the parent window handle. Windows: return the HWND for the parent.
/// @return												True if the user pressed OK, false if the user cancelled the action. FunctionNotImplementedError if the
///																output handler doesn't support a dialog.
		inline Result<Bool> EditSystemOptions(DataDictionary& settings, const Delegate<Result<void*>()>& getParentwindowHandle) const;
	};
	/// Intermediate helper class for MediaOutputUrlInterface.
	template <typename S> class COWFn : public ConstFn<S>
	{
	public:
		COWFn() = default;
		using PrivateBaseClass = ConstFn<S>;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateBaseClass::PrivateLookupFn;
		static COWFn PrivateLookupFn(MediaOutputUrlInterface**);
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, MediaOutputUrlRef, false>::type&() { return reinterpret_cast<const MediaOutputUrlRef&>(this->GetBaseRef()); }
/// Sets the url to which this output converter should write it's data.
/// @param[in] url								Url to write to.
/// @return												OK on success.
		inline Result<void> SetOutputUrl(const Url& url);
/// EditSystemOptions opens a system compressor options dialog to allow the user to choose compressor settings for a specific codec.
/// @param[in,out] settings				Settings to be displayed and modified. After calling the function the DataDictionary contains the new settings.
/// @param[in] getParentwindowHandle	Callback to return the parent window handle. Windows: return the HWND for the parent.
/// @return												True if the user pressed OK, false if the user cancelled the action. FunctionNotImplementedError if the
///																output handler doesn't support a dialog.
		inline Result<Bool> EditSystemOptions(DataDictionary& settings, const Delegate<Result<void*>()>& getParentwindowHandle);
	};
	template <typename ST> struct FnHelper : public std::conditional<
	maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)),
	COWFn<typename MediaOutputInterface::Hxx1::template FnHelper<ST>::type>,
	typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstFn<typename MediaOutputInterface::Hxx1::template FnHelper<ST>::type>, Fn<typename MediaOutputInterface::Hxx1::template FnHelper<ST>::type>>::type
	> { };
};
class MediaOutputUrlInterface::Hxx1::Reference :
#ifdef DOXYGEN
public FnDoxy<MediaOutputUrlRef>
#else
public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<MediaOutputUrlInterface, maxon::StrongRefHandler, MediaOutputUrlRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<MediaOutputUrlInterface, maxon::StrongRefHandler, MediaOutputUrlRef>>>>);
	using NonConst = typename Super::ReferenceClass;
};

/// MediaOutputUrlRef is the reference class of MediaOutputUrlInterface.
///
/// The MediaOutputInterface class provides an specific implementation to provide output data to a given destination.
class MediaOutputUrlRef : public MediaOutputUrlInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(MediaOutputUrlRef, typename MediaOutputUrlInterface::Hxx1::Reference);
	using ConstPtr = typename MediaOutputUrlInterface::ConstPtr;
};

#endif
