#if 1
namespace IMAGEPROPERTIES
{
#ifndef PRIVATE_MAXON_GUARD_maxon_IMAGEPROPERTIES
#define PRIVATE_MAXON_GUARD_maxon_IMAGEPROPERTIES
	class RESTRICT : public maxon::RESTRICT { }; template <typename T> RESTRICT TestRestriction(T y, maxon::OverloadRank1);
#endif
	namespace TEXTURE
	{
	#ifndef PRIVATE_MAXON_GUARD_maxon_IMAGEPROPERTIES_TEXTURE
	#define PRIVATE_MAXON_GUARD_maxon_IMAGEPROPERTIES_TEXTURE
		class RESTRICT : public IMAGEPROPERTIES::RESTRICT { }; template <typename T> RESTRICT TestRestriction(T y, maxon::OverloadRank1);
	#endif
	}
	namespace IMAGE
	{
	#ifndef PRIVATE_MAXON_GUARD_maxon_IMAGEPROPERTIES_IMAGE
	#define PRIVATE_MAXON_GUARD_maxon_IMAGEPROPERTIES_IMAGE
		class RESTRICT : public IMAGEPROPERTIES::RESTRICT { }; template <typename T> RESTRICT TestRestriction(T y, maxon::OverloadRank1);
	#endif
	}
	namespace LAYER
	{
	#ifndef PRIVATE_MAXON_GUARD_maxon_IMAGEPROPERTIES_LAYER
	#define PRIVATE_MAXON_GUARD_maxon_IMAGEPROPERTIES_LAYER
		class RESTRICT : public IMAGEPROPERTIES::RESTRICT { }; template <typename T> RESTRICT TestRestriction(T y, maxon::OverloadRank1);
	#endif
		namespace FOLDER
		{
		#ifndef PRIVATE_MAXON_GUARD_maxon_IMAGEPROPERTIES_LAYER_FOLDER
		#define PRIVATE_MAXON_GUARD_maxon_IMAGEPROPERTIES_LAYER_FOLDER
			class RESTRICT : public LAYER::RESTRICT { }; template <typename T> RESTRICT TestRestriction(T y, maxon::OverloadRank1);
		#endif
		}
		namespace ADJUSTMENT
		{
		#ifndef PRIVATE_MAXON_GUARD_maxon_IMAGEPROPERTIES_LAYER_ADJUSTMENT
		#define PRIVATE_MAXON_GUARD_maxon_IMAGEPROPERTIES_LAYER_ADJUSTMENT
			class RESTRICT : public LAYER::RESTRICT { }; template <typename T> RESTRICT TestRestriction(T y, maxon::OverloadRank1);
		#endif
		}
	}
}
class ImageBaseRef;

/// @cond INTERNAL

/// @endcond

struct ImageBaseInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, ImageBaseInterface>::value || DataDictionaryObjectInterface::HasBase::template Check<I>::value || HierarchyObjectInterface::HasBase::template Check<I>::value; static I* Cast(ImageBaseInterface* ptr) { return static_cast<I*>(static_cast<maxon::ObjectInterface*>(ptr)); } }; };
struct ImageBaseInterface::Hxx1
{
	class Reference;
	using ReferenceClass = ImageBaseRef;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<DataDictionaryObjectInterface, HierarchyObjectInterface>;
	/// Intermediate helper class for ImageBaseInterface.
	template <typename S> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
	{
	public:
		ConstReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
/// Returns the width of the bitmap.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type GetWidth() const;
/// Returns the height of the bitmap.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type GetHeight() const;
/// Returns the channel count of the bitmap.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type GetChannelCount() const;
/// Returns the pixel format connected to this bitmap.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<PixelFormat>, PixelFormat>::type GetPixelFormat() const;
/// To access pixel data a GetPixelHandlerStruct is needed. This optimizes the access to the pixel data see GetPixelHandlerStruct.
/// @param[in] dstFormat					Destination pixel format that should be read with this pixel handler.
/// @param[in] channelOffsets			Destination channel offsets in bits.
/// @param[in] dstColorProfile		Optional parameter which is only necessary if the color spaces of the given pixel formats doesn't match.
/// 															In that case the conversion will be performed using the correct color conversion.
/// @param[in] flags							Flags for the GetPixel operation.
/// @param[in] layerSet						Optional LayerSet or nullptr.
/// @return												A valid GetPixelHandlerStruct struct if successful.
		inline Result<GetPixelHandlerStruct> GetPixelHandler(const PixelFormat& dstFormat, const ChannelOffsets& channelOffsets, const ColorProfile& dstColorProfile, GETPIXELHANDLERFLAGS flags, const LayerSetInterface* layerSet) const;
/// @cond INTERNAL

/// Private.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type FreePixelHandler(GetPixelHandlerStruct& pixel) const;
/// Private.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type FreePixelHandler(SetPixelHandlerStruct& pixel) const;
/// @endcond

/// Access single components of the image.
/// @param[in] component					Index of the component.
/// @param[in] pos								ImagePos of the data to read.
/// @param[in] data								Destination buffer.
/// @param[in] inc								Distance between 2 pixels in the destination buffer.
/// @param[in] flags							Flags to control the read operation.
/// @return												OK on success.
		inline Result<void> GetComponent(Int component, const ImagePos& pos, Pix* data, Int inc, GETPIXELFLAGS flags) const;
/// Create a new ImageBaseRef as a sub image of the given image with the given rectangle.
/// The image will not be copied! It generates only a reference to the original image with the rectangle set to the portion of the image.
/// @param[in] rect								Part of the image.
/// @return												New Image as part of the given image.
		inline Result<ImageBaseRef> CreateSubImagePart(const DrawRectInt& rect) const;
/// Observable: This observable is fired as soon as anybody modifies the pixel data of this object.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<maxon::ObservableRef<ObservableRegionChangedDelegate>>, maxon::ObservableRef<ObservableRegionChangedDelegate>>::type ObservableRegionChanged() const;
	};
	/// Intermediate helper class for ImageBaseInterface.
	template <typename S> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, ImageBaseRef, true>::type&() const { return reinterpret_cast<const ImageBaseRef&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, ImageBaseRef, false>::type&() { return reinterpret_cast<const ImageBaseRef&>(this->GetBaseRef()); }
/// Initializes the bitmap with a given size/height.
/// The bitmap content is cleared with 0 bytes.
/// @param[in] width							Image width.
/// @param[in] height							Image height.
/// @param[in] pixelFormat				Image PixelFormat.
/// @param[in] type								Image type set into IMAGEPROPERTIES::TYPE. You can query this with image.Get(IMAGEPROPERTIES::TYPE).
/// @return												OK on success.
		inline Result<void> InitBase(Int width, Int height, const PixelFormat& pixelFormat, IMAGEPROPERTIES::ITYPE type) const;
/// @param[in] hierarchy					Defines the hierarchy to which the children belongs to.
/// @param[in] newChildren				New children to add under this object.
/// @param[in] insertBefore				Insert the children before this object. nullptr will append the object at the end.
/// @return												OK on success.
		inline Result<void> AddChildren(IMAGEHIERARCHY hierarchy, const ImageBaseRef& newChildren, const ImageBaseRef& insertBefore) const;
/// To access pixel data a SetPixelHandlerStruct is needed. This optimizes the access to the pixel data see SetPixelHandlerStruct.
/// @param[in] srcFormat					Source pixel format that should be written with this pixel handler.
/// @param[in] channelOffsets			Source channel offsets in bits.
/// @param[in] srcColorProfile		Optional parameter which is only necessary if the color spaces of the given pixel formats doesn't match.
/// 															In that case the conversion will be performed using the correct color conversion.
/// @param[in] flags							Flags for the SetPixel operation.
/// @return												A valid SetPixelHandlerStruct struct if successful.
		inline Result<SetPixelHandlerStruct> SetPixelHandler(const PixelFormat& srcFormat, const ChannelOffsets& channelOffsets, const ColorProfile& srcColorProfile, SETPIXELHANDLERFLAGS flags) const;
/// @cond INTERNAL

/// @endcond

/// Access single components of the image.
/// @param[in] component					Index of the component.
/// @param[in] pos								ImagePos of the data to write.
/// @param[in] data								Source buffer.
/// @param[in] inc								Distance between 2 pixels in the source buffer.
/// @param[in] flags							Flags to control the write operation.
/// @return												OK on success.
		inline Result<void> SetComponent(Int component, const ImagePos& pos, const Pix* data, Int inc, SETPIXELFLAGS flags) const;
	};
	/// Intermediate helper class for ImageBaseInterface.
	template <typename S> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, ImageBaseRef, false>::type&() { return reinterpret_cast<const ImageBaseRef&>(this->GetBaseRef()); }
/// Initializes the bitmap with a given size/height.
/// The bitmap content is cleared with 0 bytes.
/// @param[in] width							Image width.
/// @param[in] height							Image height.
/// @param[in] pixelFormat				Image PixelFormat.
/// @param[in] type								Image type set into IMAGEPROPERTIES::TYPE. You can query this with image.Get(IMAGEPROPERTIES::TYPE).
/// @return												OK on success.
		inline Result<void> InitBase(Int width, Int height, const PixelFormat& pixelFormat, IMAGEPROPERTIES::ITYPE type);
/// @param[in] hierarchy					Defines the hierarchy to which the children belongs to.
/// @param[in] newChildren				New children to add under this object.
/// @param[in] insertBefore				Insert the children before this object. nullptr will append the object at the end.
/// @return												OK on success.
		inline Result<void> AddChildren(IMAGEHIERARCHY hierarchy, const ImageBaseRef& newChildren, const ImageBaseRef& insertBefore);
/// To access pixel data a SetPixelHandlerStruct is needed. This optimizes the access to the pixel data see SetPixelHandlerStruct.
/// @param[in] srcFormat					Source pixel format that should be written with this pixel handler.
/// @param[in] channelOffsets			Source channel offsets in bits.
/// @param[in] srcColorProfile		Optional parameter which is only necessary if the color spaces of the given pixel formats doesn't match.
/// 															In that case the conversion will be performed using the correct color conversion.
/// @param[in] flags							Flags for the SetPixel operation.
/// @return												A valid SetPixelHandlerStruct struct if successful.
		inline Result<SetPixelHandlerStruct> SetPixelHandler(const PixelFormat& srcFormat, const ChannelOffsets& channelOffsets, const ColorProfile& srcColorProfile, SETPIXELHANDLERFLAGS flags);
/// @cond INTERNAL

/// @endcond

/// Access single components of the image.
/// @param[in] component					Index of the component.
/// @param[in] pos								ImagePos of the data to write.
/// @param[in] data								Source buffer.
/// @param[in] inc								Distance between 2 pixels in the source buffer.
/// @param[in] flags							Flags to control the write operation.
/// @return												OK on success.
		inline Result<void> SetComponent(Int component, const ImagePos& pos, const Pix* data, Int inc, SETPIXELFLAGS flags);
	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename HierarchyObjectInterface::Hxx1::template ReferenceFunctionsHelper<typename DataDictionaryObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>, ImageHierarchy>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename HierarchyObjectInterface::Hxx1::template ReferenceFunctionsHelper<typename DataDictionaryObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>, ImageHierarchy>::type>, ReferenceFunctionsImpl<typename HierarchyObjectInterface::Hxx1::template ReferenceFunctionsHelper<typename DataDictionaryObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>, ImageHierarchy>::type>>::type> { };
};
class ImageBaseInterface::Hxx1::Reference :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<ImageBaseRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<ImageBaseInterface, maxon::StrongRefHandler, ImageBaseRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<ImageBaseInterface, maxon::StrongRefHandler, ImageBaseRef>>>>);
	using NonConst = typename Super::ReferenceClass;
};

/// ImageBaseRef is the reference class of ImageBaseInterface.
///
/// Base class of all image classes. E.g. ImageLayerInterface, ImageTextureInterface inherits all this functions.
/// This base class is able to handle layers in hierarchical order.
class ImageBaseRef : public ImageBaseInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(ImageBaseRef, typename ImageBaseInterface::Hxx1::Reference);
	using ConstPtr = typename ImageBaseInterface::ConstPtr;
};

class ImageBaseInterface::ObservableRegionChangedDelegate : public maxon::Delegate<void(const ObserverObjectRef&,const UpdateRegion&)>
{
public:
	using Super = maxon::Delegate<void(const ObserverObjectRef&,const UpdateRegion&)>;
	MAXON_MEMBERFUNCTION_DETECTOR(HandleRegionChanged);
	ObservableRegionChangedDelegate() = default;
	template <typename FN> static maxon::ResultOk<Super> Create(FN&& src, typename std::enable_if<HasHandleRegionChanged<typename maxon::Dereference<typename std::decay<FN>::type, false>::type>::value, void>::type* = nullptr) { return Super::CreateByReference(std::forward<FN>(src), &maxon::Dereference<typename std::decay<FN>::type, false>::type::HandleRegionChanged); }
	template <typename FN> static maxon::Result<Super> Create(FN&& src, typename std::enable_if<!HasHandleRegionChanged<typename maxon::Dereference<typename std::decay<FN>::type, false>::type>::value, void>::type* = nullptr){ return Super::Create(std::forward<FN>(src)); }
	using OBSERVABLECOMBINER = ObservableCombinerRunAllComponentPrivateHelper;
};

class ImageTextureRef;

struct ImageTextureInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, ImageTextureInterface>::value || ImageBaseInterface::HasBase::template Check<I>::value; static I* Cast(ImageTextureInterface* ptr) { return static_cast<I*>(static_cast<maxon::ObjectInterface*>(ptr)); } }; };
struct ImageTextureInterface::Hxx1
{
	class Reference;
	using ReferenceClass = ImageTextureRef;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<ImageBaseInterface>;
	/// Intermediate helper class for ImageTextureInterface.
	template <typename S> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
	{
	public:
		ConstReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
/// Creates a new texture and loads the given url into this texture.
/// @param[in] name								Url to load.
/// @param[in] targetTime					Target time to receive the media samples from.
/// @param[in] flags							See MEDIASESSIONFLAGS for details.
/// @param[in] pixelStorageClass	Defines the storage class for all layers of the texture. See ImagePixelStorageClasses::
/// @param[in] layerSet						Optional LayerSet or nullptr.
/// @return												Return an instance to a MediaSessionRef for further reading if necessary.
		static inline Result<ImageTextureRef> LoadTexture(const Url& name, const TimeValue& targetTime = TimeValue(), MEDIASESSIONFLAGS flags = MEDIASESSIONFLAGS::NONE, const Class<ImagePixelStorage>& pixelStorageClass = GetNormalPixelStorageClass(), const LayerSetInterface* layerSet = nullptr);
/// Saves this texture using the media session interface.
/// @param[in] fileFormat					A ready to use MediaOutputRef which will be used as output node of the media session.
/// @param[in] flags							See MEDIASESSIONFLAGS for details.
/// @param[in] returnOpenSession	If nullptr the session will be closed directly. If a pointer to a MediaSessionRef is given the session will stay open. Don't forget session.Close() in that case.
/// @return												OK on success.
		inline Result<void> Save(const MediaOutputRef& fileFormat, MEDIASESSIONFLAGS flags, MediaSessionRef* returnOpenSession = nullptr) const;
/// Saves this texture using the media session interface.
/// This function simplifies the use of registered ImageSaverClasses from their registry.
/// The usage is simple:
/// @code
/// imageTexture.Save(url, ImageSaverClasses::Bmp) iferr_return;
/// @endcode
/// @param[in] fileName						Url to write to.
/// @param[in] fileFormat					A MediaOutputUrlRef which will be used as output node of the media session. MediaOutputUrlRef::SetOutputUrl will be called in this function to set the url.
/// @param[in] flags							See MEDIASESSIONFLAGS for details.
/// @param[in] returnOpenSession	If nullptr the session will be closed directly. If a pointer to a MediaSessionRef is given the session will stay open. Don't forget session.Close() in that case.
/// @return												OK on success.
		inline Result<void> Save(const Url& fileName, const MediaOutputUrlRef& fileFormat, MEDIASESSIONFLAGS flags, MediaSessionRef* returnOpenSession = nullptr) const;
	};
	/// Intermediate helper class for ImageTextureInterface.
	template <typename S> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, ImageTextureRef, true>::type&() const { return reinterpret_cast<const ImageTextureRef&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, ImageTextureRef, false>::type&() { return reinterpret_cast<const ImageTextureRef&>(this->GetBaseRef()); }
/// Loads a media into this texture.
/// @param[in] url								Url to the media to load.
/// @param[in] targetTime					Target time to receive the media samples from.
/// @param[in] flags							See MEDIASESSIONFLAGS for details.
/// @param[in] pixelStorageClass	Defines the storage class for all layers of the texture. See ImagePixelStorageClasses::
/// @param[in] layerSet						Optional LayerSet or nullptr.
/// @return												Return an instance to a MediaSessionRef for further reading if necessary.
		inline Result<MediaSessionRef> Load(const Url& url, const TimeValue& targetTime, MEDIASESSIONFLAGS flags, const Class<ImagePixelStorage>& pixelStorageClass = GetZeroRef<Class<ImagePixelStorage>>(), const LayerSetInterface* layerSet = nullptr) const;
	};
	/// Intermediate helper class for ImageTextureInterface.
	template <typename S> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, ImageTextureRef, false>::type&() { return reinterpret_cast<const ImageTextureRef&>(this->GetBaseRef()); }
/// Loads a media into this texture.
/// @param[in] url								Url to the media to load.
/// @param[in] targetTime					Target time to receive the media samples from.
/// @param[in] flags							See MEDIASESSIONFLAGS for details.
/// @param[in] pixelStorageClass	Defines the storage class for all layers of the texture. See ImagePixelStorageClasses::
/// @param[in] layerSet						Optional LayerSet or nullptr.
/// @return												Return an instance to a MediaSessionRef for further reading if necessary.
		inline Result<MediaSessionRef> Load(const Url& url, const TimeValue& targetTime, MEDIASESSIONFLAGS flags, const Class<ImagePixelStorage>& pixelStorageClass = GetZeroRef<Class<ImagePixelStorage>>(), const LayerSetInterface* layerSet = nullptr);
	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename ImageBaseInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename ImageBaseInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, ReferenceFunctionsImpl<typename ImageBaseInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>>::type> { };
};
class ImageTextureInterface::Hxx1::Reference :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<ImageTextureRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<ImageTextureInterface, maxon::StrongRefHandler, ImageTextureRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<ImageTextureInterface, maxon::StrongRefHandler, ImageTextureRef>>>>);
	using NonConst = typename Super::ReferenceClass;
};

/// ImageTextureRef is the reference class of ImageTextureInterface.
///
/// A Image texture represents a texture object with layers.
class ImageTextureRef : public ImageTextureInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(ImageTextureRef, typename ImageTextureInterface::Hxx1::Reference);
	using ConstPtr = typename ImageTextureInterface::ConstPtr;
};

class ImageRef;

struct ImageInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, ImageInterface>::value || ImageBaseInterface::HasBase::template Check<I>::value; static I* Cast(ImageInterface* ptr) { return static_cast<I*>(static_cast<maxon::ObjectInterface*>(ptr)); } }; };
struct ImageInterface::Hxx1
{
	class Reference;
	using ReferenceClass = ImageRef;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<ImageBaseInterface>;
	/// Intermediate helper class for ImageInterface.
	template <typename S> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
	{
	public:
		ConstReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
	};
	/// Intermediate helper class for ImageInterface.
	template <typename S> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, ImageRef, true>::type&() const { return reinterpret_cast<const ImageRef&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, ImageRef, false>::type&() { return reinterpret_cast<const ImageRef&>(this->GetBaseRef()); }
/// Initializes the pixel storage.
/// @param[in] width							Width of the image data.
/// @param[in] height							Height of the image data.
/// @param[in] storageFormat			Storage format of the pixel data.
/// @param[in] pixelFormat				Pixel format of the pixel storage.
/// @param[in] defaultColor				Optional default color to return if no image data is present. Must be in the given PixelFormat. Can be nullptr.
/// @return												OK on success.
		inline Result<void> Init(Int width, Int height, const Class<ImagePixelStorage>& storageFormat, const PixelFormat& pixelFormat, const Block<Pix>* defaultColor = nullptr) const;
	};
	/// Intermediate helper class for ImageInterface.
	template <typename S> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, ImageRef, false>::type&() { return reinterpret_cast<const ImageRef&>(this->GetBaseRef()); }
/// Initializes the pixel storage.
/// @param[in] width							Width of the image data.
/// @param[in] height							Height of the image data.
/// @param[in] storageFormat			Storage format of the pixel data.
/// @param[in] pixelFormat				Pixel format of the pixel storage.
/// @param[in] defaultColor				Optional default color to return if no image data is present. Must be in the given PixelFormat. Can be nullptr.
/// @return												OK on success.
		inline Result<void> Init(Int width, Int height, const Class<ImagePixelStorage>& storageFormat, const PixelFormat& pixelFormat, const Block<Pix>* defaultColor = nullptr);
	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename ImageBaseInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename ImageBaseInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, ReferenceFunctionsImpl<typename ImageBaseInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>>::type> { };
};
class ImageInterface::Hxx1::Reference :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<ImageRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<ImageInterface, maxon::StrongRefHandler, ImageRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<ImageInterface, maxon::StrongRefHandler, ImageRef>>>>);
	using NonConst = typename Super::ReferenceClass;
};

/// ImageRef is the reference class of ImageInterface.
///
/// The ImageInterface represents a single image with a ImageTextureRef.
/// one or more Images can be part of a ImageTextureRef.
class ImageRef : public ImageInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(ImageRef, typename ImageInterface::Hxx1::Reference);
	using ConstPtr = typename ImageInterface::ConstPtr;
};

class ImageLayerRef;

struct ImageLayerInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, ImageLayerInterface>::value || ImageInterface::HasBase::template Check<I>::value; static I* Cast(ImageLayerInterface* ptr) { return static_cast<I*>(static_cast<maxon::ObjectInterface*>(ptr)); } }; };
struct ImageLayerInterface::Hxx1
{
	class Reference;
	using ReferenceClass = ImageLayerRef;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<ImageInterface>;
	/// Intermediate helper class for ImageLayerInterface.
	template <typename S> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
	{
	public:
		ConstReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
	};
	/// Intermediate helper class for ImageLayerInterface.
	template <typename S> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, ImageLayerRef, true>::type&() const { return reinterpret_cast<const ImageLayerRef&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, ImageLayerRef, false>::type&() { return reinterpret_cast<const ImageLayerRef&>(this->GetBaseRef()); }
	};
	/// Intermediate helper class for ImageLayerInterface.
	template <typename S> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, ImageLayerRef, false>::type&() { return reinterpret_cast<const ImageLayerRef&>(this->GetBaseRef()); }
	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename ImageInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename ImageInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, ReferenceFunctionsImpl<typename ImageInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>>::type> { };
};
class ImageLayerInterface::Hxx1::Reference :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<ImageLayerRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<ImageLayerInterface, maxon::StrongRefHandler, ImageLayerRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<ImageLayerInterface, maxon::StrongRefHandler, ImageLayerRef>>>>);
	using NonConst = typename Super::ReferenceClass;
};

/// ImageLayerRef is the reference class of ImageLayerInterface.
///
/// A Image layer represents a single layer within a image texture.
class ImageLayerRef : public ImageLayerInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(ImageLayerRef, typename ImageLayerInterface::Hxx1::Reference);
	using ConstPtr = typename ImageLayerInterface::ConstPtr;
};

#endif
