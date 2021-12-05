#if 1
class PixelFormatGroup;

struct PixelFormatGroupInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, PixelFormatGroupInterface>::value || ObjectInterface::HasBase::template Check<I>::value; static I* Cast(PixelFormatGroupInterface* ptr) { return static_cast<I*>(static_cast<maxon::ObjectInterface*>(ptr)); } }; };
struct PixelFormatGroupInterface::Hxx1
{
	class Reference;
	class NonConstRef;
	using ReferenceClass = PixelFormatGroup;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<ObjectInterface>;
	/// Intermediate helper class for PixelFormatGroupInterface.
	template <typename S> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
	{
	public:
		ConstReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, PixelFormatGroup, false>::type&() const { return reinterpret_cast<const PixelFormatGroup&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, PixelFormatGroup, false>::type&() { return reinterpret_cast<const PixelFormatGroup&>(this->GetBaseRef()); }
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<PixelFormatIterator>, PixelFormatIterator>::type GetEntries() const;
	};
	/// Intermediate helper class for PixelFormatGroupInterface.
	template <typename S> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
	};
	/// Intermediate helper class for PixelFormatGroupInterface.
	template <typename S> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename ObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename ObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, ReferenceFunctionsImpl<typename ObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>>::type> { };
};
class PixelFormatGroupInterface::Hxx1::Reference :
#ifdef DOXYGEN
public ConstReferenceFunctionsImplDoxy<PixelFormatGroup>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const PixelFormatGroupInterface, maxon::StrongRefHandler, PixelFormatGroup>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const PixelFormatGroupInterface, maxon::StrongRefHandler, PixelFormatGroup>>>>);
	using NonConst = Hxx1::NonConstRef;
};

class PixelFormatGroupInterface::Hxx1::NonConstRef :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<NonConstRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<PixelFormatGroupInterface, maxon::StrongRefHandler, NonConstRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<PixelFormatGroupInterface, maxon::StrongRefHandler, NonConstRef>>>>);
};

/// PixelFormatGroup is the reference class of PixelFormatGroupInterface.
///
/// Every pixel format belongs to a specific group. This interface define this group.
/// The group should define a general pixel format, e.g. RGB or BGRA etc. All the different implementations for different bit depths should
/// be grouped under that group.
class PixelFormatGroup : public PixelFormatGroupInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(PixelFormatGroup, typename PixelFormatGroupInterface::Hxx1::Reference);
};

class PixelFormat;

struct PixelFormatInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, PixelFormatInterface>::value || ObjectInterface::HasBase::template Check<I>::value; static I* Cast(PixelFormatInterface* ptr) { return static_cast<I*>(static_cast<maxon::ObjectInterface*>(ptr)); } }; };
struct PixelFormatInterface::Hxx1
{
	class Reference;
	class NonConstRef;
	using ReferenceClass = PixelFormat;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<ObjectInterface>;
	/// Intermediate helper class for PixelFormatInterface.
	template <typename S> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
	{
	public:
		ConstReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
/// Returns a description of all the channels of this pixel format.
/// @return												Block with the description of all channels.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Block<const ImageChannel>>, Block<const ImageChannel>>::type GetChannels() const;
/// Returns the corresponding PixelFormatGroup
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<const PixelFormatGroup&>, const PixelFormatGroup&>::type GetPixelFormatGroup() const;
/// Allocates a buffer for a rectangle of pixels of this PixelFormat.
/// @param[in] width							Width of the rectangle.
/// @param[in] height							Height of the rectangle.
/// @param[in] lineAlignment			Alignment for each line. E.g. 4 means that each line is aligned to a byte count of 4.
/// @return												Pointer to a memory block with the given size. You must free the memory using DeleteMem.
/// 															You can access the Pixels by (pointer + yPos * GetBytesPerLine(width, lineAlignment) + GetBitsPerPixel().GetOffset(xPos)).
		inline Result<Pix*> CreatePix(Int width, Int height, Int lineAlignment = 1) const;
		template <typename TYPE> inline Result<TYPE*> CreatePix(Int width, Int height, Int lineAlignment = 1) const;
/// Returns the number of channels of the pixel format. E.g. RGB8i returns 3 for the 3 channels R, G and B.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type GetChannelCount() const;
/// Returns the offset in bits of each channel. The block is one element bigger then the channel count. offsets[GetChannelCount()] is
/// identical to GetBitsPerPixel().
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<const ChannelOffsets&>, const ChannelOffsets&>::type GetChannelOffsets() const;
/// Returns the size in bits of each pixel (the sum of all channels).
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<BITS>, BITS>::type GetBitsPerPixel() const;
/// Returns the number of bytes for a line with the given lineAlignment.
/// @param[in] width							Number of Pixels.
/// @param[in] lineAlignment			Value to which a line should be aligned to (e.g. 4 would align the memory to Int32 borders).
/// @return												The number of bytes for the requested number of bytes with the given alignment.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type GetBytesPerLine(Int width, Int lineAlignment) const;
/// Returns the number of pixels that are packed together within this image format.
/// This means that it's not possible to access chunks with smaller pixel counts than this value.
/// e.g. yuv encoding packs 2 pixels into 4 bytes (Y0U0Y1V1) but the u and v value is the same for both pixels.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type GetPackedPixelCount() const;
/// Returns true if the pixel format supports alpha.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type HasAlpha() const;
/// Returns the alpha pixel format (PixelFormats::ALPHA::U8/GREY16I/GREY32F/GREY64F) if a alpha channel is present.
/// The return value contains a Tuple with the alpha pixel format as first and the byteoffset as the 2nd parameter.
		inline Result<Tuple<PixelFormat, Int>> GetAlphaPixelFormat() const;
/// Returns the color space used by the pixel format.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<ColorSpace>, ColorSpace>::type GetColorSpace() const;
/// Returns the default color space
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<const ColorProfile&>, const ColorProfile&>::type GetDefaultColorProfile() const;
/// Creates a CONVERTPIXELFUNC which is able to convert from a given srcFormatPtr to the own pixel format.
/// The function builds dynamic code which converts the 2 pixel formats effectively from one into the other.
/// This function is slow and should be cached. It uses spin locks internally.
/// @param[in] srcFormatPtr				The pixel format to convert from.
/// @param[in] srcChannelOffset		Channel offset in bytes of the src pixel format.
/// @param[in] dstChannelOffset		Channel offset in bytes of the destination (own) pixel format.
/// @param[in] srcColorProfile		Optional parameter which is only necessary if the color spaces of the given pixel formats doesn't match. In that case the conversion will be performed using the correct color conversion.
/// @param[in,out] dstColorProfile	Optional parameter which is only necessary if the color spaces of the given pixel formats doesn't match. In that case the conversion will be performed using the correct color conversion.
/// 															Returns the effective destination color profile after the conversion is applied.
/// 															If the color space of the source and dest pixel format is identical no color profile conversion is performed and the result is srcColorProfile.
/// 															If the color spaces are different the resulting color profile is the same as dstColorProfile.
/// @param[in] forceColorProfileConversion	True to force the color profile conversion even is the color space is identical, false will not perform color profile transformation if the color space is identical.
/// @param[out] disableCaching		Set to true if the conversion must not be cached (e.g. because a color table is used like in the indexed pixel format). Otherwise let the value unchanged!
/// @return												Closure to call directly to convert from one format to the other. This closure is only valid for the given channel offsets of both formats.
		inline Result<CONVERTPIXELFUNC> GetConvertPixelFunc(const PixelFormat& srcFormatPtr, const ChannelOffsets& srcChannelOffset, const ChannelOffsets& dstChannelOffset, const ColorProfile& srcColorProfile, ColorProfile* dstColorProfile, Bool forceColorProfileConversion, Bool& disableCaching) const;
/// Converts Pixels from one format into another. This is a convenience function.
/// This function is not as fast pixelFormat.GetConvertPixelFunc() followed by calls of the returned closure.
/// @param[in] dst								ImageMutableBuffer of the destination data/format.
/// @param[in] count							Number of pixels to convert.
/// @param[in] src								ImageConstBuffer of the source data/format.
/// @param[in] srcColorProfile		Optional parameter which is only necessary if the color spaces of the given pixel formats doesn't match. In that case the conversion will be performed using the correct color conversion.
/// @param[in,out] dstColorProfile	Optional parameter which is only necessary if the color spaces of the given pixel formats doesn't match. In that case the conversion will be performed using the correct color conversion.
/// 															Returns the effective destination color profile after the conversion is applied.
/// 															If the color space of the source and dest pixel format is identical no color profile conversion is performed and the result is srcColorProfile.
/// 															If the color spaces are different the resulting color profile is the same as dstColorProfile.
/// @param[in] cflags							Flags to control the conversion. See CONVERTPIXELFLAGS.
/// @param[in] flags							Flags to control the conversion. See GETPIXELFLAGS;.
/// @return												OK on success.
		inline Result<void> ConvertPixelFromSlow(const ImageMutableBuffer& dst, Int count, const ImageConstBuffer& src, const ColorProfile& srcColorProfile, ColorProfile* dstColorProfile, CONVERTPIXELFLAGS cflags, GETPIXELFLAGS flags) const;
/// Compares 2 pixels. Both pixels must be in the same pixel format!
/// @param[in] a									ImageConstBuffer pointing to the first pixel.
/// @param[in] b									ImageConstBuffer pointing to the second pixel.
/// @param[in] oneTolerance				True if a tolerance of one digit is allowed. Tolerances can happen when converting from formats with different resolutions.
/// @return												True if the pixels are identical.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type IsIdenticalPixel(const ImageConstBuffer& a, const ImageConstBuffer& b, Int oneTolerance) const;
/// Converts a pixel into a readable format.
/// @param[in] src								Pointer to the data of one packed pixel.
/// @return												String representation of the pixel.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type PixToString(const Pix* src) const;
/// for overloading in your own implementation. do not call from outside!
/// @param[in] srcFormatPtr				TODO: (Tilo) please document
/// @param[in] srcChannelOffset		TODO: (Tilo) please document
/// @param[in] dstChannelOffset		TODO: (Tilo) please document
/// @param[in] fastSize						TODO: (Tilo) please document
/// @param[out] disableCaching		Set to true if the conversion must not be cached (e.g. because a color table is used like in the indexed pixel format). Otherwise let the value unchanged!
/// @return												Conversion function or nullptr if no conversion found. An error will only be returned in case of a real error (out of memory etc).
		inline Result<CONVERTPIXELFUNC> GetConvertPixelFromFunc(const PixelFormat& srcFormatPtr, const ChannelOffsets& srcChannelOffset, const ChannelOffsets& dstChannelOffset, Bool fastSize, Bool& disableCaching) const;
/// for overloading in your own implementation. do not call from outside!
/// @param[in] dstFormatPtr				TODO: (Tilo) please document
/// @param[in] dstChannelOffset		TODO: (Tilo) please document
/// @param[in] srcChannelOffset		TODO: (Tilo) please document
/// @param[in] fastSize						TODO: (Tilo) please document
/// @param[out] disableCaching		Set to true if the conversion must not be cached (e.g. because a color table is used like in the indexed pixel format). Otherwise let the value unchanged!
/// @return												Conversion function or nullptr if no conversion found. An error will only be returned in case of a real error (out of memory etc.).
		inline Result<CONVERTPIXELFUNC> GetConvertPixelToFunc(const PixelFormat& dstFormatPtr, const ChannelOffsets& dstChannelOffset, const ChannelOffsets& srcChannelOffset, Bool fastSize, Bool& disableCaching) const;
/// Returns the short name set in the init function.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<const Char*>, const Char*>::type GetShortName() const;
	};
	/// Intermediate helper class for PixelFormatInterface.
	template <typename S> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
/// Private.
/// @param[in] group							TODO: (Tilo) please document
/// @param[in] shortName					Short name of the color format for diagnostic outputs.
/// @return												OK on success.
		inline Result<void> Init(const PixelFormatGroup& group, const Char* shortName) const;
	};
	/// Intermediate helper class for PixelFormatInterface.
	template <typename S> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, PixelFormat, false>::type&() const { return reinterpret_cast<const PixelFormat&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, PixelFormat, false>::type&() { return reinterpret_cast<const PixelFormat&>(this->GetBaseRef()); }
/// Private.
/// @param[in] group							TODO: (Tilo) please document
/// @param[in] shortName					Short name of the color format for diagnostic outputs.
/// @return												OK on success.
		inline Result<void> Init(const PixelFormatGroup& group, const Char* shortName);
	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename ObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename ObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, ReferenceFunctionsImpl<typename ObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>>::type> { };
};
class PixelFormatInterface::Hxx1::Reference :
#ifdef DOXYGEN
public COWReferenceFunctionsImplDoxy<PixelFormat>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const PixelFormatInterface, maxon::StrongCOWRefHandler, PixelFormat>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const PixelFormatInterface, maxon::StrongCOWRefHandler, PixelFormat>>>>);
	using NonConst = Hxx1::NonConstRef;
};

class PixelFormatInterface::Hxx1::NonConstRef :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<NonConstRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<PixelFormatInterface, maxon::StrongRefHandler, NonConstRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<PixelFormatInterface, maxon::StrongRefHandler, NonConstRef>>>>);
};

/// PixelFormat is the reference class of PixelFormatInterface.
///
/// This class handles image pixel formats.
/// Each pixel format should has it's own implementation. The memory layout of different pixels is free.
/// This class offers functions to convert from and to other pixel formats.
///
/// This interface has only const functions and will not change it's pointers.
/// That's why it's possible to compare PixelFormats by comparing the pointers.
/// The PixelFormats registry provides all registered pixel formats.
///
/// One exception is the PixelFormatIndexedColor. It allows to set a color table
/// so this breaks the link and the object is no longer comparable by the pointer.
/// In that case use Cast<PixelFormatIndexedColor>(pixelFormat) to check whether it's this type or not.
class PixelFormat : public PixelFormatInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(PixelFormat, typename PixelFormatInterface::Hxx1::Reference);
};

class PixelFormatIndexedColor;

struct PixelFormatIndexedColorInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, PixelFormatIndexedColorInterface>::value || PixelFormatInterface::HasBase::template Check<I>::value; static I* Cast(PixelFormatIndexedColorInterface* ptr) { return static_cast<I*>(static_cast<maxon::ObjectInterface*>(ptr)); } }; };
struct PixelFormatIndexedColorInterface::Hxx1
{
	class Reference;
	class NonConstRef;
	using ReferenceClass = PixelFormatIndexedColor;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<PixelFormatInterface>;
	/// Intermediate helper class for PixelFormatIndexedColorInterface.
	template <typename S> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
	{
	public:
		ConstReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
/// Returns the pixel format of the color table.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<PixelFormat>, PixelFormat>::type GetColorTablePixelFormat() const;
/// Returns the number of color entries.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type GetColorTableSize() const;
/// Returns a single color entry from the color table.
/// @param[in] idx								Index of the entry to get.
/// @param[in] dstPixelData				Destination color pointer. The color will be automatically converted into the color format provided in the dstPixelData.
/// @return												OK on success.
		inline Result<void> GetIndex(Int idx, const ImageMutableBuffer& dstPixelData) const;
	};
	/// Intermediate helper class for PixelFormatIndexedColorInterface.
	template <typename S> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
/// Initialize the pixel format with a specific number of color entries and a given pixel format for the color entries.
/// @param[in] count							Number of color entries in the table.
/// @param[in] srcFormatPtr				Pixel format of the color entries.
/// @return												OK on success.
		inline Result<void> InitColorTable(Int count, const PixelFormat& srcFormatPtr) const;
/// Sets a specific color entry.
/// @param[in] idx								Index of the entry to set.
/// @param[in] srcPixelData				Source color data. The color will be automatically converted into the color format provided in the Init function.
/// @return												OK on success.
		inline Result<void> SetIndex(Int idx, const ImageConstBuffer& srcPixelData) const;
	};
	/// Intermediate helper class for PixelFormatIndexedColorInterface.
	template <typename S> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, PixelFormatIndexedColor, false>::type&() const { return reinterpret_cast<const PixelFormatIndexedColor&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, PixelFormatIndexedColor, false>::type&() { return reinterpret_cast<const PixelFormatIndexedColor&>(this->GetBaseRef()); }
/// Initialize the pixel format with a specific number of color entries and a given pixel format for the color entries.
/// @param[in] count							Number of color entries in the table.
/// @param[in] srcFormatPtr				Pixel format of the color entries.
/// @return												OK on success.
		inline Result<void> InitColorTable(Int count, const PixelFormat& srcFormatPtr);
/// Sets a specific color entry.
/// @param[in] idx								Index of the entry to set.
/// @param[in] srcPixelData				Source color data. The color will be automatically converted into the color format provided in the Init function.
/// @return												OK on success.
		inline Result<void> SetIndex(Int idx, const ImageConstBuffer& srcPixelData);
	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename PixelFormatInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename PixelFormatInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, ReferenceFunctionsImpl<typename PixelFormatInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>>::type> { };
};
class PixelFormatIndexedColorInterface::Hxx1::Reference :
#ifdef DOXYGEN
public COWReferenceFunctionsImplDoxy<PixelFormatIndexedColor>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const PixelFormatIndexedColorInterface, maxon::StrongCOWRefHandler, PixelFormatIndexedColor>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const PixelFormatIndexedColorInterface, maxon::StrongCOWRefHandler, PixelFormatIndexedColor>>>>);
	using NonConst = Hxx1::NonConstRef;
};

class PixelFormatIndexedColorInterface::Hxx1::NonConstRef :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<NonConstRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<PixelFormatIndexedColorInterface, maxon::StrongRefHandler, NonConstRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<PixelFormatIndexedColorInterface, maxon::StrongRefHandler, NonConstRef>>>>);
};

/// PixelFormatIndexedColor is the reference class of PixelFormatIndexedColorInterface.
///
/// PixelFormatIndexedColorInterface extends the PixelFormatInterface with the ability to handle color palettes/tables.
class PixelFormatIndexedColor : public PixelFormatIndexedColorInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(PixelFormatIndexedColor, typename PixelFormatIndexedColorInterface::Hxx1::Reference);
};

#endif
