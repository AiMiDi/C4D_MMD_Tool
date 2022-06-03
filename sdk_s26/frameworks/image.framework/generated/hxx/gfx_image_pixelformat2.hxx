
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1

struct PixelFormatInterface::MTable
{
	PRIVATE_MAXON_IMPLEMENTS_CHECK(ConvertPixelFromSlow);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(CreatePix);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetAlphaPixelFormat);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetBitsPerPixel);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetBytesPerLine);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetChannelCount);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetChannelOffsets);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetChannels);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetColorSpace);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetConvertPixelFromFunc);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetConvertPixelFunc);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetConvertPixelToFunc);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetDefaultColorProfile);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetPackedPixelCount);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetPixelFormatGroup);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetShortName);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(HasAlpha);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(Init);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(IsIdenticalPixel);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(PixToString);
	static const maxon::Char* const _ids;
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	Result<void> (*PixelFormatInterface_Init) (maxon::GenericComponent* this_, const PixelFormatGroup& group, const Char* shortName);
	maxon::Int PixelFormatInterface_Init_Offset;
	Block<const ImageChannel> (*PixelFormatInterface_GetChannels) (const maxon::GenericComponent* this_);
	maxon::Int PixelFormatInterface_GetChannels_Offset;
	const PixelFormatGroup& (*PixelFormatInterface_GetPixelFormatGroup) (const maxon::GenericComponent* this_);
	maxon::Int PixelFormatInterface_GetPixelFormatGroup_Offset;
	Result<Pix*> (*PixelFormatInterface_CreatePix) (const maxon::GenericComponent* this_, Int width, Int height, Int lineAlignment);
	maxon::Int PixelFormatInterface_CreatePix_Offset;
	Int (*PixelFormatInterface_GetChannelCount) (const maxon::GenericComponent* this_);
	maxon::Int PixelFormatInterface_GetChannelCount_Offset;
	const ChannelOffsets& (*PixelFormatInterface_GetChannelOffsets) (const maxon::GenericComponent* this_);
	maxon::Int PixelFormatInterface_GetChannelOffsets_Offset;
	BITS (*PixelFormatInterface_GetBitsPerPixel) (const maxon::GenericComponent* this_);
	maxon::Int PixelFormatInterface_GetBitsPerPixel_Offset;
	Int (*PixelFormatInterface_GetBytesPerLine) (const maxon::GenericComponent* this_, Int width, Int lineAlignment);
	maxon::Int PixelFormatInterface_GetBytesPerLine_Offset;
	Int (*PixelFormatInterface_GetPackedPixelCount) (const maxon::GenericComponent* this_);
	maxon::Int PixelFormatInterface_GetPackedPixelCount_Offset;
	Bool (*PixelFormatInterface_HasAlpha) (const maxon::GenericComponent* this_);
	maxon::Int PixelFormatInterface_HasAlpha_Offset;
	Result<Tuple<PixelFormat, Int>> (*PixelFormatInterface_GetAlphaPixelFormat) (const maxon::GenericComponent* this_);
	maxon::Int PixelFormatInterface_GetAlphaPixelFormat_Offset;
	ColorSpace (*PixelFormatInterface_GetColorSpace) (const maxon::GenericComponent* this_);
	maxon::Int PixelFormatInterface_GetColorSpace_Offset;
	const ColorProfile& (*PixelFormatInterface_GetDefaultColorProfile) (const maxon::GenericComponent* this_);
	maxon::Int PixelFormatInterface_GetDefaultColorProfile_Offset;
	Result<CONVERTPIXELFUNC> (*PixelFormatInterface_GetConvertPixelFunc) (const maxon::GenericComponent* this_, const PixelFormat& srcFormatPtr, const ChannelOffsets& srcChannelOffset, const ChannelOffsets& dstChannelOffset, const ColorProfile& srcColorProfile, ColorProfile* dstColorProfile, Bool forceColorProfileConversion, Bool& disableCaching);
	maxon::Int PixelFormatInterface_GetConvertPixelFunc_Offset;
	Result<CONVERTPIXELFUNC> (*PixelFormatInterface_GetConvertPixelFunc_1) (const maxon::GenericComponent* this_, const PixelFormat& srcFormatPtr, const ChannelOffsets& srcChannelOffset, const ChannelOffsets& dstChannelOffset, const ColorProfile& srcColorProfile, ColorProfile* dstColorProfile, Bool forceColorProfileConversion, COLORCONVERSIONFLAGS colorConversionFlags, Bool& disableCaching);
	maxon::Int PixelFormatInterface_GetConvertPixelFunc_1_Offset;
	Result<void> (*PixelFormatInterface_ConvertPixelFromSlow) (const maxon::GenericComponent* this_, const ImageMutableBuffer& dst, Int count, const ImageConstBuffer& src, const ColorProfile& srcColorProfile, ColorProfile* dstColorProfile, CONVERTPIXELFLAGS cflags, GETPIXELFLAGS flags);
	maxon::Int PixelFormatInterface_ConvertPixelFromSlow_Offset;
	Bool (*PixelFormatInterface_IsIdenticalPixel) (const maxon::GenericComponent* this_, const ImageConstBuffer& a, const ImageConstBuffer& b, Int oneTolerance);
	maxon::Int PixelFormatInterface_IsIdenticalPixel_Offset;
	String (*PixelFormatInterface_PixToString) (const maxon::GenericComponent* this_, const Pix* src);
	maxon::Int PixelFormatInterface_PixToString_Offset;
	Result<CONVERTPIXELFUNC> (*PixelFormatInterface_GetConvertPixelFromFunc) (const maxon::GenericComponent* this_, const PixelFormat& srcFormatPtr, const ChannelOffsets& srcChannelOffset, const ChannelOffsets& dstChannelOffset, Bool fastSize, Bool& disableCaching);
	maxon::Int PixelFormatInterface_GetConvertPixelFromFunc_Offset;
	Result<CONVERTPIXELFUNC> (*PixelFormatInterface_GetConvertPixelToFunc) (const maxon::GenericComponent* this_, const PixelFormat& dstFormatPtr, const ChannelOffsets& dstChannelOffset, const ChannelOffsets& srcChannelOffset, Bool fastSize, Bool& disableCaching);
	maxon::Int PixelFormatInterface_GetConvertPixelToFunc_Offset;
	const Char* (*PixelFormatInterface_GetShortName) (const maxon::GenericComponent* this_);
	maxon::Int PixelFormatInterface_GetShortName_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, PixelFormatInterface, Init))
	{
		PixelFormatInterface_Init = &W::PixelFormatInterface_Init;
		PixelFormatInterface_Init_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, PixelFormatInterface, GetChannels))
	{
		PixelFormatInterface_GetChannels = &W::PixelFormatInterface_GetChannels;
		PixelFormatInterface_GetChannels_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, PixelFormatInterface, GetPixelFormatGroup))
	{
		PixelFormatInterface_GetPixelFormatGroup = &W::PixelFormatInterface_GetPixelFormatGroup;
		PixelFormatInterface_GetPixelFormatGroup_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, PixelFormatInterface, CreatePix))
	{
		PixelFormatInterface_CreatePix = &W::PixelFormatInterface_CreatePix;
		PixelFormatInterface_CreatePix_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, PixelFormatInterface, GetChannelCount))
	{
		PixelFormatInterface_GetChannelCount = &W::PixelFormatInterface_GetChannelCount;
		PixelFormatInterface_GetChannelCount_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, PixelFormatInterface, GetChannelOffsets))
	{
		PixelFormatInterface_GetChannelOffsets = &W::PixelFormatInterface_GetChannelOffsets;
		PixelFormatInterface_GetChannelOffsets_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, PixelFormatInterface, GetBitsPerPixel))
	{
		PixelFormatInterface_GetBitsPerPixel = &W::PixelFormatInterface_GetBitsPerPixel;
		PixelFormatInterface_GetBitsPerPixel_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, PixelFormatInterface, GetBytesPerLine))
	{
		PixelFormatInterface_GetBytesPerLine = &W::PixelFormatInterface_GetBytesPerLine;
		PixelFormatInterface_GetBytesPerLine_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, PixelFormatInterface, GetPackedPixelCount))
	{
		PixelFormatInterface_GetPackedPixelCount = &W::PixelFormatInterface_GetPackedPixelCount;
		PixelFormatInterface_GetPackedPixelCount_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, PixelFormatInterface, HasAlpha))
	{
		PixelFormatInterface_HasAlpha = &W::PixelFormatInterface_HasAlpha;
		PixelFormatInterface_HasAlpha_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, PixelFormatInterface, GetAlphaPixelFormat))
	{
		PixelFormatInterface_GetAlphaPixelFormat = &W::PixelFormatInterface_GetAlphaPixelFormat;
		PixelFormatInterface_GetAlphaPixelFormat_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, PixelFormatInterface, GetColorSpace))
	{
		PixelFormatInterface_GetColorSpace = &W::PixelFormatInterface_GetColorSpace;
		PixelFormatInterface_GetColorSpace_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, PixelFormatInterface, GetDefaultColorProfile))
	{
		PixelFormatInterface_GetDefaultColorProfile = &W::PixelFormatInterface_GetDefaultColorProfile;
		PixelFormatInterface_GetDefaultColorProfile_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, PixelFormatInterface, GetConvertPixelFunc))
	{
		PixelFormatInterface_GetConvertPixelFunc = &W::PixelFormatInterface_GetConvertPixelFunc;
		PixelFormatInterface_GetConvertPixelFunc_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, PixelFormatInterface, GetConvertPixelFunc))
	{
		PixelFormatInterface_GetConvertPixelFunc_1 = &W::PixelFormatInterface_GetConvertPixelFunc_1;
		PixelFormatInterface_GetConvertPixelFunc_1_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, PixelFormatInterface, ConvertPixelFromSlow))
	{
		PixelFormatInterface_ConvertPixelFromSlow = &W::PixelFormatInterface_ConvertPixelFromSlow;
		PixelFormatInterface_ConvertPixelFromSlow_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, PixelFormatInterface, IsIdenticalPixel))
	{
		PixelFormatInterface_IsIdenticalPixel = &W::PixelFormatInterface_IsIdenticalPixel;
		PixelFormatInterface_IsIdenticalPixel_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, PixelFormatInterface, PixToString))
	{
		PixelFormatInterface_PixToString = &W::PixelFormatInterface_PixToString;
		PixelFormatInterface_PixToString_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, PixelFormatInterface, GetConvertPixelFromFunc))
	{
		PixelFormatInterface_GetConvertPixelFromFunc = &W::PixelFormatInterface_GetConvertPixelFromFunc;
		PixelFormatInterface_GetConvertPixelFromFunc_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, PixelFormatInterface, GetConvertPixelToFunc))
	{
		PixelFormatInterface_GetConvertPixelToFunc = &W::PixelFormatInterface_GetConvertPixelToFunc;
		PixelFormatInterface_GetConvertPixelToFunc_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, PixelFormatInterface, GetShortName))
	{
		PixelFormatInterface_GetShortName = &W::PixelFormatInterface_GetShortName;
		PixelFormatInterface_GetShortName_Offset = offset;
	}
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<PixelFormatInterface, typename ObjectInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<PixelFormatInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct PixelFormatInterface::Hxx2
{
	template <typename S> class CWrapper : public ObjectInterface::Hxx2::template CWrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(ConvertPixelFromSlow);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(CreatePix);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetAlphaPixelFormat);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetBitsPerPixel);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetBytesPerLine);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetChannelCount);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetChannelOffsets);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetChannels);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetColorSpace);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetConvertPixelFromFunc);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetConvertPixelFunc);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetConvertPixelToFunc);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetDefaultColorProfile);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetPackedPixelCount);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetPixelFormatGroup);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetShortName);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(HasAlpha);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(Init);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(IsIdenticalPixel);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(PixToString);
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename ObjectInterface::Hxx2::template CWrapper<S>;
			if (!S::Implementation::PROXY && !(Super0::InitMTablesWithBases(info, offset))) return false;
			auto* vt = (PixelFormatInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, PixelFormatInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		static Result<void> PixelFormatInterface_Init(maxon::GenericComponent* this_, const PixelFormatGroup& group, const Char* shortName) { return ((typename S::Implementation*) this_)->Init(group, shortName); }
		static Block<const ImageChannel> PixelFormatInterface_GetChannels(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetChannels(); }
		static const PixelFormatGroup& PixelFormatInterface_GetPixelFormatGroup(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetPixelFormatGroup(); }
		static Result<Pix*> PixelFormatInterface_CreatePix(const maxon::GenericComponent* this_, Int width, Int height, Int lineAlignment) { return ((const typename S::Implementation*) this_)->CreatePix(width, height, lineAlignment); }
		static Int PixelFormatInterface_GetChannelCount(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetChannelCount(); }
		static const ChannelOffsets& PixelFormatInterface_GetChannelOffsets(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetChannelOffsets(); }
		static BITS PixelFormatInterface_GetBitsPerPixel(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetBitsPerPixel(); }
		static Int PixelFormatInterface_GetBytesPerLine(const maxon::GenericComponent* this_, Int width, Int lineAlignment) { return ((const typename S::Implementation*) this_)->GetBytesPerLine(width, lineAlignment); }
		static Int PixelFormatInterface_GetPackedPixelCount(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetPackedPixelCount(); }
		static Bool PixelFormatInterface_HasAlpha(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->HasAlpha(); }
		static Result<Tuple<PixelFormat, Int>> PixelFormatInterface_GetAlphaPixelFormat(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetAlphaPixelFormat(); }
		static ColorSpace PixelFormatInterface_GetColorSpace(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetColorSpace(); }
		static const ColorProfile& PixelFormatInterface_GetDefaultColorProfile(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetDefaultColorProfile(); }
		static Result<CONVERTPIXELFUNC> PixelFormatInterface_GetConvertPixelFunc(const maxon::GenericComponent* this_, const PixelFormat& srcFormatPtr, const ChannelOffsets& srcChannelOffset, const ChannelOffsets& dstChannelOffset, const ColorProfile& srcColorProfile, ColorProfile* dstColorProfile, Bool forceColorProfileConversion, Bool& disableCaching) { return ((const typename S::Implementation*) this_)->GetConvertPixelFunc(srcFormatPtr, srcChannelOffset, dstChannelOffset, srcColorProfile, dstColorProfile, forceColorProfileConversion, disableCaching); }
		static Result<CONVERTPIXELFUNC> PixelFormatInterface_GetConvertPixelFunc_1(const maxon::GenericComponent* this_, const PixelFormat& srcFormatPtr, const ChannelOffsets& srcChannelOffset, const ChannelOffsets& dstChannelOffset, const ColorProfile& srcColorProfile, ColorProfile* dstColorProfile, Bool forceColorProfileConversion, COLORCONVERSIONFLAGS colorConversionFlags, Bool& disableCaching) { return ((const typename S::Implementation*) this_)->GetConvertPixelFunc(srcFormatPtr, srcChannelOffset, dstChannelOffset, srcColorProfile, dstColorProfile, forceColorProfileConversion, colorConversionFlags, disableCaching); }
		static Result<void> PixelFormatInterface_ConvertPixelFromSlow(const maxon::GenericComponent* this_, const ImageMutableBuffer& dst, Int count, const ImageConstBuffer& src, const ColorProfile& srcColorProfile, ColorProfile* dstColorProfile, CONVERTPIXELFLAGS cflags, GETPIXELFLAGS flags) { return ((const typename S::Implementation*) this_)->ConvertPixelFromSlow(dst, count, src, srcColorProfile, dstColorProfile, cflags, flags); }
		static Bool PixelFormatInterface_IsIdenticalPixel(const maxon::GenericComponent* this_, const ImageConstBuffer& a, const ImageConstBuffer& b, Int oneTolerance) { return ((const typename S::Implementation*) this_)->IsIdenticalPixel(a, b, oneTolerance); }
		static String PixelFormatInterface_PixToString(const maxon::GenericComponent* this_, const Pix* src) { return ((const typename S::Implementation*) this_)->PixToString(src); }
		static Result<CONVERTPIXELFUNC> PixelFormatInterface_GetConvertPixelFromFunc(const maxon::GenericComponent* this_, const PixelFormat& srcFormatPtr, const ChannelOffsets& srcChannelOffset, const ChannelOffsets& dstChannelOffset, Bool fastSize, Bool& disableCaching) { return ((const typename S::Implementation*) this_)->GetConvertPixelFromFunc(srcFormatPtr, srcChannelOffset, dstChannelOffset, fastSize, disableCaching); }
		static Result<CONVERTPIXELFUNC> PixelFormatInterface_GetConvertPixelToFunc(const maxon::GenericComponent* this_, const PixelFormat& dstFormatPtr, const ChannelOffsets& dstChannelOffset, const ChannelOffsets& srcChannelOffset, Bool fastSize, Bool& disableCaching) { return ((const typename S::Implementation*) this_)->GetConvertPixelToFunc(dstFormatPtr, dstChannelOffset, srcChannelOffset, fastSize, disableCaching); }
		static const Char* PixelFormatInterface_GetShortName(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetShortName(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatInterface::Init(const PixelFormatGroup& group, const Char* shortName) -> Result<void>
{
	const PixelFormatInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(PixelFormatInterface, this); return mt_.PixelFormatInterface_Init((maxon::GenericComponent*) this + mt_.PixelFormatInterface_Init_Offset, group, shortName);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatInterface::GetChannels() const -> Block<const ImageChannel>
{
	const PixelFormatInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(PixelFormatInterface, this); return mt_.PixelFormatInterface_GetChannels((const maxon::GenericComponent*) this + mt_.PixelFormatInterface_GetChannels_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatInterface::GetPixelFormatGroup() const -> const PixelFormatGroup&
{
	const PixelFormatInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(PixelFormatInterface, this); return mt_.PixelFormatInterface_GetPixelFormatGroup((const maxon::GenericComponent*) this + mt_.PixelFormatInterface_GetPixelFormatGroup_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatInterface::CreatePix(Int width, Int height, Int lineAlignment) const -> Result<Pix*>
{
	const PixelFormatInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(PixelFormatInterface, this); return mt_.PixelFormatInterface_CreatePix((const maxon::GenericComponent*) this + mt_.PixelFormatInterface_CreatePix_Offset, width, height, lineAlignment);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatInterface::GetChannelCount() const -> Int
{
	const PixelFormatInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(PixelFormatInterface, this); return mt_.PixelFormatInterface_GetChannelCount((const maxon::GenericComponent*) this + mt_.PixelFormatInterface_GetChannelCount_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatInterface::GetChannelOffsets() const -> const ChannelOffsets&
{
	const PixelFormatInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(PixelFormatInterface, this); return mt_.PixelFormatInterface_GetChannelOffsets((const maxon::GenericComponent*) this + mt_.PixelFormatInterface_GetChannelOffsets_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatInterface::GetBitsPerPixel() const -> BITS
{
	const PixelFormatInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(PixelFormatInterface, this); return mt_.PixelFormatInterface_GetBitsPerPixel((const maxon::GenericComponent*) this + mt_.PixelFormatInterface_GetBitsPerPixel_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatInterface::GetBytesPerLine(Int width, Int lineAlignment) const -> Int
{
	const PixelFormatInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(PixelFormatInterface, this); return mt_.PixelFormatInterface_GetBytesPerLine((const maxon::GenericComponent*) this + mt_.PixelFormatInterface_GetBytesPerLine_Offset, width, lineAlignment);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatInterface::GetPackedPixelCount() const -> Int
{
	const PixelFormatInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(PixelFormatInterface, this); return mt_.PixelFormatInterface_GetPackedPixelCount((const maxon::GenericComponent*) this + mt_.PixelFormatInterface_GetPackedPixelCount_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatInterface::HasAlpha() const -> Bool
{
	const PixelFormatInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(PixelFormatInterface, this); return mt_.PixelFormatInterface_HasAlpha((const maxon::GenericComponent*) this + mt_.PixelFormatInterface_HasAlpha_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatInterface::GetAlphaPixelFormat() const -> Result<Tuple<PixelFormat, Int>>
{
	const PixelFormatInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(PixelFormatInterface, this); return mt_.PixelFormatInterface_GetAlphaPixelFormat((const maxon::GenericComponent*) this + mt_.PixelFormatInterface_GetAlphaPixelFormat_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatInterface::GetColorSpace() const -> ColorSpace
{
	const PixelFormatInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(PixelFormatInterface, this); return mt_.PixelFormatInterface_GetColorSpace((const maxon::GenericComponent*) this + mt_.PixelFormatInterface_GetColorSpace_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatInterface::GetDefaultColorProfile() const -> const ColorProfile&
{
	const PixelFormatInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(PixelFormatInterface, this); return mt_.PixelFormatInterface_GetDefaultColorProfile((const maxon::GenericComponent*) this + mt_.PixelFormatInterface_GetDefaultColorProfile_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatInterface::GetConvertPixelFunc(const PixelFormat& srcFormatPtr, const ChannelOffsets& srcChannelOffset, const ChannelOffsets& dstChannelOffset, const ColorProfile& srcColorProfile, ColorProfile* dstColorProfile, Bool forceColorProfileConversion, Bool& disableCaching) const -> Result<CONVERTPIXELFUNC>
{
	const PixelFormatInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(PixelFormatInterface, this); return mt_.PixelFormatInterface_GetConvertPixelFunc((const maxon::GenericComponent*) this + mt_.PixelFormatInterface_GetConvertPixelFunc_Offset, srcFormatPtr, srcChannelOffset, dstChannelOffset, srcColorProfile, dstColorProfile, forceColorProfileConversion, disableCaching);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatInterface::GetConvertPixelFunc(const PixelFormat& srcFormatPtr, const ChannelOffsets& srcChannelOffset, const ChannelOffsets& dstChannelOffset, const ColorProfile& srcColorProfile, ColorProfile* dstColorProfile, Bool forceColorProfileConversion, COLORCONVERSIONFLAGS colorConversionFlags, Bool& disableCaching) const -> Result<CONVERTPIXELFUNC>
{
	const PixelFormatInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(PixelFormatInterface, this); return mt_.PixelFormatInterface_GetConvertPixelFunc_1((const maxon::GenericComponent*) this + mt_.PixelFormatInterface_GetConvertPixelFunc_1_Offset, srcFormatPtr, srcChannelOffset, dstChannelOffset, srcColorProfile, dstColorProfile, forceColorProfileConversion, colorConversionFlags, disableCaching);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatInterface::ConvertPixelFromSlow(const ImageMutableBuffer& dst, Int count, const ImageConstBuffer& src, const ColorProfile& srcColorProfile, ColorProfile* dstColorProfile, CONVERTPIXELFLAGS cflags, GETPIXELFLAGS flags) const -> Result<void>
{
	const PixelFormatInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(PixelFormatInterface, this); return mt_.PixelFormatInterface_ConvertPixelFromSlow((const maxon::GenericComponent*) this + mt_.PixelFormatInterface_ConvertPixelFromSlow_Offset, dst, count, src, srcColorProfile, dstColorProfile, cflags, flags);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatInterface::IsIdenticalPixel(const ImageConstBuffer& a, const ImageConstBuffer& b, Int oneTolerance) const -> Bool
{
	const PixelFormatInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(PixelFormatInterface, this); return mt_.PixelFormatInterface_IsIdenticalPixel((const maxon::GenericComponent*) this + mt_.PixelFormatInterface_IsIdenticalPixel_Offset, a, b, oneTolerance);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatInterface::PixToString(const Pix* src) const -> String
{
	const PixelFormatInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(PixelFormatInterface, this); return mt_.PixelFormatInterface_PixToString((const maxon::GenericComponent*) this + mt_.PixelFormatInterface_PixToString_Offset, src);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatInterface::GetConvertPixelFromFunc(const PixelFormat& srcFormatPtr, const ChannelOffsets& srcChannelOffset, const ChannelOffsets& dstChannelOffset, Bool fastSize, Bool& disableCaching) const -> Result<CONVERTPIXELFUNC>
{
	const PixelFormatInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(PixelFormatInterface, this); return mt_.PixelFormatInterface_GetConvertPixelFromFunc((const maxon::GenericComponent*) this + mt_.PixelFormatInterface_GetConvertPixelFromFunc_Offset, srcFormatPtr, srcChannelOffset, dstChannelOffset, fastSize, disableCaching);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatInterface::GetConvertPixelToFunc(const PixelFormat& dstFormatPtr, const ChannelOffsets& dstChannelOffset, const ChannelOffsets& srcChannelOffset, Bool fastSize, Bool& disableCaching) const -> Result<CONVERTPIXELFUNC>
{
	const PixelFormatInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(PixelFormatInterface, this); return mt_.PixelFormatInterface_GetConvertPixelToFunc((const maxon::GenericComponent*) this + mt_.PixelFormatInterface_GetConvertPixelToFunc_Offset, dstFormatPtr, dstChannelOffset, srcChannelOffset, fastSize, disableCaching);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatInterface::GetShortName() const -> const Char*
{
	const PixelFormatInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(PixelFormatInterface, this); return mt_.PixelFormatInterface_GetShortName((const maxon::GenericComponent*) this + mt_.PixelFormatInterface_GetShortName_Offset);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatInterface::Hxx1::Fn<S>::Init(const PixelFormatGroup& group, const Char* shortName) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); PixelFormatInterface* o_ = (PixelFormatInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(PixelFormatInterface, o_, PixelFormatInterface_Init) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<PixelFormatInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<PixelFormatInterface>() : PRIVATE_MAXON_VTABLE(PixelFormatInterface, o_); 
	return (mt_.PixelFormatInterface_Init(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.PixelFormatInterface_Init_Offset, group, shortName));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatInterface::Hxx1::COWFn<S>::Init(const PixelFormatGroup& group, const Char* shortName) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); PixelFormatInterface* o_ = (PixelFormatInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(PixelFormatInterface, o_, PixelFormatInterface_Init) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<PixelFormatInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<PixelFormatInterface>() : PRIVATE_MAXON_VTABLE(PixelFormatInterface, o_); 
	return (mt_.PixelFormatInterface_Init(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.PixelFormatInterface_Init_Offset, group, shortName));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatInterface::Hxx1::ConstFn<S>::GetChannels() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Block<const ImageChannel>>, Block<const ImageChannel>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Block<const ImageChannel>>, Block<const ImageChannel>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const PixelFormatInterface* o_ = (const PixelFormatInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = PixelFormatInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<Block<const ImageChannel>>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(PixelFormatInterface, o_, PixelFormatInterface_GetChannels) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<PixelFormatInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<PixelFormatInterface>() : PRIVATE_MAXON_VTABLE(PixelFormatInterface, o_); 
	return (mt_.PixelFormatInterface_GetChannels(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.PixelFormatInterface_GetChannels_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatInterface::Hxx1::ConstFn<S>::GetPixelFormatGroup() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const PixelFormatGroup&>, const PixelFormatGroup&>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const PixelFormatGroup&>, const PixelFormatGroup&>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const PixelFormatInterface* o_ = (const PixelFormatInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = PixelFormatInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<const PixelFormatGroup&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(PixelFormatInterface, o_, PixelFormatInterface_GetPixelFormatGroup) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<PixelFormatInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<PixelFormatInterface>() : PRIVATE_MAXON_VTABLE(PixelFormatInterface, o_); 
	return (mt_.PixelFormatInterface_GetPixelFormatGroup(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.PixelFormatInterface_GetPixelFormatGroup_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatInterface::Hxx1::ConstFn<S>::CreatePix(Int width, Int height, Int lineAlignment) const -> Result<Pix*>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Pix*>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const PixelFormatInterface* o_ = (const PixelFormatInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = PixelFormatInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(PixelFormatInterface, o_, PixelFormatInterface_CreatePix) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<PixelFormatInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<PixelFormatInterface>() : PRIVATE_MAXON_VTABLE(PixelFormatInterface, o_); 
	return (mt_.PixelFormatInterface_CreatePix(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.PixelFormatInterface_CreatePix_Offset, width, height, lineAlignment));
}
template <typename S> template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatInterface::Hxx1::ConstFn<S>::CreatePix(Int width, Int height, Int lineAlignment) const -> Result<TYPE*>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<TYPE*>>; static_assert(!std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value, "Can't invoke MAXON_FUNCTION PixelFormatInterface::CreatePix on super."); if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const PixelFormatInterface* o_ = (const PixelFormatInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = PixelFormatInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->CreatePix<TYPE>(width, height, lineAlignment));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatInterface::Hxx1::ConstFn<S>::GetChannelCount() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const PixelFormatInterface* o_ = (const PixelFormatInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = PixelFormatInterface::NullValuePtr(); if (!o_) return 0; } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(PixelFormatInterface, o_, PixelFormatInterface_GetChannelCount) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<PixelFormatInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<PixelFormatInterface>() : PRIVATE_MAXON_VTABLE(PixelFormatInterface, o_); 
	return (mt_.PixelFormatInterface_GetChannelCount(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.PixelFormatInterface_GetChannelCount_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatInterface::Hxx1::ConstFn<S>::GetChannelOffsets() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const ChannelOffsets&>, const ChannelOffsets&>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const ChannelOffsets&>, const ChannelOffsets&>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const PixelFormatInterface* o_ = (const PixelFormatInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = PixelFormatInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<const ChannelOffsets&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(PixelFormatInterface, o_, PixelFormatInterface_GetChannelOffsets) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<PixelFormatInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<PixelFormatInterface>() : PRIVATE_MAXON_VTABLE(PixelFormatInterface, o_); 
	return (mt_.PixelFormatInterface_GetChannelOffsets(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.PixelFormatInterface_GetChannelOffsets_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatInterface::Hxx1::ConstFn<S>::GetBitsPerPixel() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<BITS>, BITS>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<BITS>, BITS>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const PixelFormatInterface* o_ = (const PixelFormatInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = PixelFormatInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<BITS>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(PixelFormatInterface, o_, PixelFormatInterface_GetBitsPerPixel) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<PixelFormatInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<PixelFormatInterface>() : PRIVATE_MAXON_VTABLE(PixelFormatInterface, o_); 
	return (mt_.PixelFormatInterface_GetBitsPerPixel(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.PixelFormatInterface_GetBitsPerPixel_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatInterface::Hxx1::ConstFn<S>::GetBytesPerLine(Int width, Int lineAlignment) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const PixelFormatInterface* o_ = (const PixelFormatInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = PixelFormatInterface::NullValuePtr(); if (!o_) return 0; } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(PixelFormatInterface, o_, PixelFormatInterface_GetBytesPerLine) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<PixelFormatInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<PixelFormatInterface>() : PRIVATE_MAXON_VTABLE(PixelFormatInterface, o_); 
	return (mt_.PixelFormatInterface_GetBytesPerLine(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.PixelFormatInterface_GetBytesPerLine_Offset, width, lineAlignment));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatInterface::Hxx1::ConstFn<S>::GetPackedPixelCount() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const PixelFormatInterface* o_ = (const PixelFormatInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = PixelFormatInterface::NullValuePtr(); if (!o_) return 0; } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(PixelFormatInterface, o_, PixelFormatInterface_GetPackedPixelCount) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<PixelFormatInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<PixelFormatInterface>() : PRIVATE_MAXON_VTABLE(PixelFormatInterface, o_); 
	return (mt_.PixelFormatInterface_GetPackedPixelCount(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.PixelFormatInterface_GetPackedPixelCount_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatInterface::Hxx1::ConstFn<S>::HasAlpha() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const PixelFormatInterface* o_ = (const PixelFormatInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = PixelFormatInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(PixelFormatInterface, o_, PixelFormatInterface_HasAlpha) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<PixelFormatInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<PixelFormatInterface>() : PRIVATE_MAXON_VTABLE(PixelFormatInterface, o_); 
	return (mt_.PixelFormatInterface_HasAlpha(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.PixelFormatInterface_HasAlpha_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatInterface::Hxx1::ConstFn<S>::GetAlphaPixelFormat() const -> Result<Tuple<PixelFormat, Int>>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Tuple<PixelFormat, Int>>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const PixelFormatInterface* o_ = (const PixelFormatInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = PixelFormatInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(PixelFormatInterface, o_, PixelFormatInterface_GetAlphaPixelFormat) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<PixelFormatInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<PixelFormatInterface>() : PRIVATE_MAXON_VTABLE(PixelFormatInterface, o_); 
	return (mt_.PixelFormatInterface_GetAlphaPixelFormat(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.PixelFormatInterface_GetAlphaPixelFormat_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatInterface::Hxx1::ConstFn<S>::GetColorSpace() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<ColorSpace>, ColorSpace>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<ColorSpace>, ColorSpace>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const PixelFormatInterface* o_ = (const PixelFormatInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = PixelFormatInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<ColorSpace>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(PixelFormatInterface, o_, PixelFormatInterface_GetColorSpace) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<PixelFormatInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<PixelFormatInterface>() : PRIVATE_MAXON_VTABLE(PixelFormatInterface, o_); 
	return (mt_.PixelFormatInterface_GetColorSpace(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.PixelFormatInterface_GetColorSpace_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatInterface::Hxx1::ConstFn<S>::GetDefaultColorProfile() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const ColorProfile&>, const ColorProfile&>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const ColorProfile&>, const ColorProfile&>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const PixelFormatInterface* o_ = (const PixelFormatInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = PixelFormatInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<const ColorProfile&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(PixelFormatInterface, o_, PixelFormatInterface_GetDefaultColorProfile) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<PixelFormatInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<PixelFormatInterface>() : PRIVATE_MAXON_VTABLE(PixelFormatInterface, o_); 
	return (mt_.PixelFormatInterface_GetDefaultColorProfile(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.PixelFormatInterface_GetDefaultColorProfile_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatInterface::Hxx1::ConstFn<S>::GetConvertPixelFunc(const PixelFormat& srcFormatPtr, const ChannelOffsets& srcChannelOffset, const ChannelOffsets& dstChannelOffset, const ColorProfile& srcColorProfile, ColorProfile* dstColorProfile, Bool forceColorProfileConversion, Bool& disableCaching) const -> Result<CONVERTPIXELFUNC>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<CONVERTPIXELFUNC>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const PixelFormatInterface* o_ = (const PixelFormatInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = PixelFormatInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(PixelFormatInterface, o_, PixelFormatInterface_GetConvertPixelFunc) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<PixelFormatInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<PixelFormatInterface>() : PRIVATE_MAXON_VTABLE(PixelFormatInterface, o_); 
	return (mt_.PixelFormatInterface_GetConvertPixelFunc(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.PixelFormatInterface_GetConvertPixelFunc_Offset, srcFormatPtr, srcChannelOffset, dstChannelOffset, srcColorProfile, dstColorProfile, forceColorProfileConversion, disableCaching));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatInterface::Hxx1::ConstFn<S>::GetConvertPixelFunc(const PixelFormat& srcFormatPtr, const ChannelOffsets& srcChannelOffset, const ChannelOffsets& dstChannelOffset, const ColorProfile& srcColorProfile, ColorProfile* dstColorProfile, Bool forceColorProfileConversion, COLORCONVERSIONFLAGS colorConversionFlags, Bool& disableCaching) const -> Result<CONVERTPIXELFUNC>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<CONVERTPIXELFUNC>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const PixelFormatInterface* o_ = (const PixelFormatInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = PixelFormatInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(PixelFormatInterface, o_, PixelFormatInterface_GetConvertPixelFunc_1) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<PixelFormatInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<PixelFormatInterface>() : PRIVATE_MAXON_VTABLE(PixelFormatInterface, o_); 
	return (mt_.PixelFormatInterface_GetConvertPixelFunc_1(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.PixelFormatInterface_GetConvertPixelFunc_1_Offset, srcFormatPtr, srcChannelOffset, dstChannelOffset, srcColorProfile, dstColorProfile, forceColorProfileConversion, colorConversionFlags, disableCaching));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatInterface::Hxx1::ConstFn<S>::ConvertPixelFromSlow(const ImageMutableBuffer& dst, Int count, const ImageConstBuffer& src, const ColorProfile& srcColorProfile, ColorProfile* dstColorProfile, CONVERTPIXELFLAGS cflags, GETPIXELFLAGS flags) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const PixelFormatInterface* o_ = (const PixelFormatInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = PixelFormatInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(PixelFormatInterface, o_, PixelFormatInterface_ConvertPixelFromSlow) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<PixelFormatInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<PixelFormatInterface>() : PRIVATE_MAXON_VTABLE(PixelFormatInterface, o_); 
	return (mt_.PixelFormatInterface_ConvertPixelFromSlow(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.PixelFormatInterface_ConvertPixelFromSlow_Offset, dst, count, src, srcColorProfile, dstColorProfile, cflags, flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatInterface::Hxx1::ConstFn<S>::IsIdenticalPixel(const ImageConstBuffer& a, const ImageConstBuffer& b, Int oneTolerance) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const PixelFormatInterface* o_ = (const PixelFormatInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = PixelFormatInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(PixelFormatInterface, o_, PixelFormatInterface_IsIdenticalPixel) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<PixelFormatInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<PixelFormatInterface>() : PRIVATE_MAXON_VTABLE(PixelFormatInterface, o_); 
	return (mt_.PixelFormatInterface_IsIdenticalPixel(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.PixelFormatInterface_IsIdenticalPixel_Offset, a, b, oneTolerance));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatInterface::Hxx1::ConstFn<S>::PixToString(const Pix* src) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const PixelFormatInterface* o_ = (const PixelFormatInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = PixelFormatInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(PixelFormatInterface, o_, PixelFormatInterface_PixToString) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<PixelFormatInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<PixelFormatInterface>() : PRIVATE_MAXON_VTABLE(PixelFormatInterface, o_); 
	return (mt_.PixelFormatInterface_PixToString(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.PixelFormatInterface_PixToString_Offset, src));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatInterface::Hxx1::ConstFn<S>::GetConvertPixelFromFunc(const PixelFormat& srcFormatPtr, const ChannelOffsets& srcChannelOffset, const ChannelOffsets& dstChannelOffset, Bool fastSize, Bool& disableCaching) const -> Result<CONVERTPIXELFUNC>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<CONVERTPIXELFUNC>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const PixelFormatInterface* o_ = (const PixelFormatInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = PixelFormatInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(PixelFormatInterface, o_, PixelFormatInterface_GetConvertPixelFromFunc) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<PixelFormatInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<PixelFormatInterface>() : PRIVATE_MAXON_VTABLE(PixelFormatInterface, o_); 
	return (mt_.PixelFormatInterface_GetConvertPixelFromFunc(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.PixelFormatInterface_GetConvertPixelFromFunc_Offset, srcFormatPtr, srcChannelOffset, dstChannelOffset, fastSize, disableCaching));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatInterface::Hxx1::ConstFn<S>::GetConvertPixelToFunc(const PixelFormat& dstFormatPtr, const ChannelOffsets& dstChannelOffset, const ChannelOffsets& srcChannelOffset, Bool fastSize, Bool& disableCaching) const -> Result<CONVERTPIXELFUNC>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<CONVERTPIXELFUNC>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const PixelFormatInterface* o_ = (const PixelFormatInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = PixelFormatInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(PixelFormatInterface, o_, PixelFormatInterface_GetConvertPixelToFunc) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<PixelFormatInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<PixelFormatInterface>() : PRIVATE_MAXON_VTABLE(PixelFormatInterface, o_); 
	return (mt_.PixelFormatInterface_GetConvertPixelToFunc(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.PixelFormatInterface_GetConvertPixelToFunc_Offset, dstFormatPtr, dstChannelOffset, srcChannelOffset, fastSize, disableCaching));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatInterface::Hxx1::ConstFn<S>::GetShortName() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const Char*>, const Char*>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const Char*>, const Char*>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const PixelFormatInterface* o_ = (const PixelFormatInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = PixelFormatInterface::NullValuePtr(); if (!o_) return nullptr; } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(PixelFormatInterface, o_, PixelFormatInterface_GetShortName) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<PixelFormatInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<PixelFormatInterface>() : PRIVATE_MAXON_VTABLE(PixelFormatInterface, o_); 
	return (mt_.PixelFormatInterface_GetShortName(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.PixelFormatInterface_GetShortName_Offset));
}
auto PixelFormatInterface::GetPtr() -> Ptr { return Ptr(this); }
auto PixelFormatInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_gfx_image_pixelformat)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_PixelFormatInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_PixelFormatInterface() { new (s_ui_maxon_PixelFormatInterface) maxon::EntityUse(PixelFormatInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/gfx_image_pixelformat.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_PixelFormatInterface(PixelFormatInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/gfx_image_pixelformat.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
constexpr const maxon::Char* PixelFormatsInterface::PrivateGetCppName() { return nullptr; }

struct PixelFormatsInterface::MTable
{
	static MTable _instance;
	static MTable _unresolvedInstance;
	static const maxon::Char* const _ids;
	static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl);
	static const maxon::NULL_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = false;
	Result<PixelFormat> (*PixelFormatsInterface_FindOrCreatePixelFormat) (const Block<const ImageChannel>& channels);
	template <typename IMPL> void Init()
	{
		PixelFormatsInterface_FindOrCreatePixelFormat = &IMPL::PixelFormatsInterface_FindOrCreatePixelFormat;
	}
};

struct PixelFormatsInterface::Hxx2
{
	class Unresolved;
	template <typename C> class Wrapper
	{
	public:
		static Result<PixelFormat> PixelFormatsInterface_FindOrCreatePixelFormat(const Block<const ImageChannel>& channels) { return C::FindOrCreatePixelFormat(channels); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatsInterface::FindOrCreatePixelFormat(const Block<const ImageChannel>& channels) -> Result<PixelFormat>
{
	return MTable::_instance.PixelFormatsInterface_FindOrCreatePixelFormat(channels);
}

#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_gfx_image_pixelformat)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_PixelFormatsInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_PixelFormatsInterface() { new (s_ui_maxon_PixelFormatsInterface) maxon::EntityUse(PixelFormatsInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/gfx_image_pixelformat.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_PixelFormatsInterface(PixelFormatsInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/gfx_image_pixelformat.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

