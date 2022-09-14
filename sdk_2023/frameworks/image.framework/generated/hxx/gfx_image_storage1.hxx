#if 1
class ImagePixelStorage;

/// @cond INTERNAL

/// @endcond

struct ImagePixelStorageInterface::HasBaseDetector { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, ImagePixelStorageInterface>::value || ObjectInterface::HasBaseDetector::template Check<I>::value; static I* Cast(ImagePixelStorageInterface* ptr) { return reinterpret_cast<I*>(ptr); } }; };
struct ImagePixelStorageInterface::Hxx1
{
	class Reference;
	class NonConstRef;
	using ReferenceClass = ImagePixelStorage;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<ObjectInterface>;
	/// Intermediate helper class for ImagePixelStorageInterface.
	template <typename S> class ConstFn DOXYGEN_SWITCH_REVERSED(, : public S)
	{
	public:
		ConstFn() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateBaseClass::PrivateLookupFn;
		static ConstFn PrivateLookupFn(ImagePixelStorageInterface**);
/// Returns the width of the pixel storage.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type GetWidth() const;
/// Returns the height of the pixel storage.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type GetHeight() const;
/// Returns the total number of channels of the pixel storage.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type GetChannelCount() const;
/// Returns the pixel format connected to this pixel storage.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<PixelFormat>, PixelFormat>::type GetPixelFormat() const;
/// To access pixel data a GetPixelHandlerStruct is needed. This optimizes the access to the pixel data see GetPixelHandlerStruct.
/// @param[in] dstFormat					Destination pixel format that should be read with this pixel handler.
/// @param[in] channelOffsets			Destination channel offset in bits.
/// @param[in] srcColorProfile		Optional parameter which is only necessary if the color spaces of the given pixel formats doesn't match. In that case the conversion will be performed using the correct color conversion.
/// @param[in] dstColorProfile		Optional parameter which is only necessary if the color spaces of the given pixel formats doesn't match. In that case the conversion will be performed using the correct color conversion.
/// @param[in] flags							Flags for the GetPixel operation.
/// @return												A valid GetPixelHandlerStruct struct if successful.
		inline Result<GetPixelHandlerStruct> GetPixelHandler(const PixelFormat& dstFormat, const ChannelOffsets& channelOffsets, const ColorProfile& srcColorProfile, const ColorProfile& dstColorProfile, GETPIXELHANDLERFLAGS flags) const;
/// @cond INTERNAL

/// Private.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type FreePixelHandler(GetPixelHandlerStruct& pixel) const;
/// Private.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type FreePixelHandler(SetPixelHandlerStruct& pixel, const Delegate<void(const UpdateRegion&)>& updateRegionNotification) const;
/// @endcond

/// Access single components of the image.
/// @param[in] component					Index of the component.
/// @param[in] pos								ImagePos of the data to read.
/// @param[in] data								Destination buffer.
/// @param[in] inc								Distance between 2 pixels in the destination buffer.
/// @param[in] flags							Flags to control the read operation.
/// @return												OK on success.
		inline Result<void> GetComponent(Int component, const ImagePos& pos, Pix* data, Int inc, GETPIXELFLAGS flags) const;
	};
	/// Intermediate helper class for ImagePixelStorageInterface.
	template <typename S> class Fn : public ConstFn<S>
	{
	public:
		Fn() = default;
		using PrivateBaseClass = ConstFn<S>;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateBaseClass::PrivateLookupFn;
		static Fn PrivateLookupFn(ImagePixelStorageInterface**);
/// Initializes the pixel storage.
/// @param[in] width							Width of the image data.
/// @param[in] height							Height of the image data.
/// @param[in] format							Pixel format of the pixel storage, e.g. ImagePixelStorageClasses::Normal.
/// @param[in] defaultColor				Optional default color to return if no image data is present. Must be in the given PixelFormat. Can be nullptr.
/// @return												OK on success.
		inline Result<void> Init(Int width, Int height, const PixelFormat& format, const Block<Pix>* defaultColor) const;
/// To access pixel data a SetPixelHandlerStruct is needed. This optimizes the access to the pixel data see SetPixelHandlerStruct.
/// @param[in] srcFormat					Source pixel format that should be written with this pixel handler.
/// @param[in] channelOffsets			Source channel offsets in bits.
/// @param[in] srcColorProfile		Optional parameter which is only necessary if the color spaces of the given pixel formats doesn't match. In that case the conversion will be performed using the correct color conversion.
/// @param[in] dstColorProfile		Optional parameter which is only necessary if the color spaces of the given pixel formats doesn't match. In that case the conversion will be performed using the correct color conversion.
/// @param[in] flags							Flags for the SetPixel operation.
/// @return												A valid SetPixelHandlerStruct struct if successful.
		inline Result<SetPixelHandlerStruct> SetPixelHandler(const PixelFormat& srcFormat, const ChannelOffsets& channelOffsets, const ColorProfile& srcColorProfile, const ColorProfile& dstColorProfile, SETPIXELHANDLERFLAGS flags, const Delegate<void(const UpdateRegion&)>& updateRegionNotification) const;
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
	/// Intermediate helper class for ImagePixelStorageInterface.
	template <typename S> class COWFn : public ConstFn<S>
	{
	public:
		COWFn() = default;
		using PrivateBaseClass = ConstFn<S>;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateBaseClass::PrivateLookupFn;
		static COWFn PrivateLookupFn(ImagePixelStorageInterface**);
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, ImagePixelStorage, false>::type&() const { return reinterpret_cast<const ImagePixelStorage&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, ImagePixelStorage, false>::type&() { return reinterpret_cast<const ImagePixelStorage&>(this->GetBaseRef()); }
/// Initializes the pixel storage.
/// @param[in] width							Width of the image data.
/// @param[in] height							Height of the image data.
/// @param[in] format							Pixel format of the pixel storage, e.g. ImagePixelStorageClasses::Normal.
/// @param[in] defaultColor				Optional default color to return if no image data is present. Must be in the given PixelFormat. Can be nullptr.
/// @return												OK on success.
		inline Result<void> Init(Int width, Int height, const PixelFormat& format, const Block<Pix>* defaultColor);
/// To access pixel data a SetPixelHandlerStruct is needed. This optimizes the access to the pixel data see SetPixelHandlerStruct.
/// @param[in] srcFormat					Source pixel format that should be written with this pixel handler.
/// @param[in] channelOffsets			Source channel offsets in bits.
/// @param[in] srcColorProfile		Optional parameter which is only necessary if the color spaces of the given pixel formats doesn't match. In that case the conversion will be performed using the correct color conversion.
/// @param[in] dstColorProfile		Optional parameter which is only necessary if the color spaces of the given pixel formats doesn't match. In that case the conversion will be performed using the correct color conversion.
/// @param[in] flags							Flags for the SetPixel operation.
/// @return												A valid SetPixelHandlerStruct struct if successful.
		inline Result<SetPixelHandlerStruct> SetPixelHandler(const PixelFormat& srcFormat, const ChannelOffsets& channelOffsets, const ColorProfile& srcColorProfile, const ColorProfile& dstColorProfile, SETPIXELHANDLERFLAGS flags, const Delegate<void(const UpdateRegion&)>& updateRegionNotification);
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
	template <typename ST> struct FnHelper : public std::conditional<
	maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)),
	COWFn<typename ObjectInterface::Hxx1::template FnHelper<ST>::type>,
	typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstFn<typename ObjectInterface::Hxx1::template FnHelper<ST>::type>, Fn<typename ObjectInterface::Hxx1::template FnHelper<ST>::type>>::type
	> { };
};
class ImagePixelStorageInterface::Hxx1::Reference :
#ifdef DOXYGEN
public COWFnDoxy<ImagePixelStorage>
#else
public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<const ImagePixelStorageInterface, maxon::StrongCOWRefHandler, ImagePixelStorage>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<const ImagePixelStorageInterface, maxon::StrongCOWRefHandler, ImagePixelStorage>>>>);
	using NonConst = Hxx1::NonConstRef;
};

class ImagePixelStorageInterface::Hxx1::NonConstRef :
#ifdef DOXYGEN
public FnDoxy<NonConstRef>
#else
public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<ImagePixelStorageInterface, maxon::StrongRefHandler, NonConstRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<ImagePixelStorageInterface, maxon::StrongRefHandler, NonConstRef>>>>);
};

/// ImagePixelStorage is the reference class of ImagePixelStorageInterface.
///
/// Object that can store pixel data in a special layout (e.g. compact, plain, or tiles).
class ImagePixelStorage : public ImagePixelStorageInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(ImagePixelStorage, typename ImagePixelStorageInterface::Hxx1::Reference);
};

#endif
