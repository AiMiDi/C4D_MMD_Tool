
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
	PRIVATE_MAXON_MF_POINTER(PixelFormatInterface_Init, Init, true, maxon::GenericComponent,, (Result<void>), const PixelFormatGroup& group, const Char* shortName);
	maxon::Int PixelFormatInterface_Init_Offset;
	PRIVATE_MAXON_MF_POINTER(PixelFormatInterface_GetChannels, GetChannels, true, maxon::GenericComponent, const, (Block<const ImageChannel>));
	maxon::Int PixelFormatInterface_GetChannels_Offset;
	PRIVATE_MAXON_MF_POINTER(PixelFormatInterface_GetPixelFormatGroup, GetPixelFormatGroup, true, maxon::GenericComponent, const, (const PixelFormatGroup&));
	maxon::Int PixelFormatInterface_GetPixelFormatGroup_Offset;
	PRIVATE_MAXON_MF_POINTER(PixelFormatInterface_CreatePix, CreatePix, true, maxon::GenericComponent, const, (Result<Pix*>), Int width, Int height, Int lineAlignment);
	maxon::Int PixelFormatInterface_CreatePix_Offset;
	PRIVATE_MAXON_MF_POINTER(PixelFormatInterface_GetChannelCount, GetChannelCount, true, maxon::GenericComponent, const, (Int));
	maxon::Int PixelFormatInterface_GetChannelCount_Offset;
	PRIVATE_MAXON_MF_POINTER(PixelFormatInterface_GetChannelOffsets, GetChannelOffsets, true, maxon::GenericComponent, const, (const ChannelOffsets&));
	maxon::Int PixelFormatInterface_GetChannelOffsets_Offset;
	PRIVATE_MAXON_MF_POINTER(PixelFormatInterface_GetBitsPerPixel, GetBitsPerPixel, true, maxon::GenericComponent, const, (BITS));
	maxon::Int PixelFormatInterface_GetBitsPerPixel_Offset;
	PRIVATE_MAXON_MF_POINTER(PixelFormatInterface_GetBytesPerLine, GetBytesPerLine, true, maxon::GenericComponent, const, (Int), Int width, Int lineAlignment);
	maxon::Int PixelFormatInterface_GetBytesPerLine_Offset;
	PRIVATE_MAXON_MF_POINTER(PixelFormatInterface_GetPackedPixelCount, GetPackedPixelCount, true, maxon::GenericComponent, const, (Int));
	maxon::Int PixelFormatInterface_GetPackedPixelCount_Offset;
	PRIVATE_MAXON_MF_POINTER(PixelFormatInterface_HasAlpha, HasAlpha, true, maxon::GenericComponent, const, (Bool));
	maxon::Int PixelFormatInterface_HasAlpha_Offset;
	PRIVATE_MAXON_MF_POINTER(PixelFormatInterface_GetAlphaPixelFormat, GetAlphaPixelFormat, true, maxon::GenericComponent, const, (Result<Tuple<PixelFormat, Int>>));
	maxon::Int PixelFormatInterface_GetAlphaPixelFormat_Offset;
	PRIVATE_MAXON_MF_POINTER(PixelFormatInterface_GetColorSpace, GetColorSpace, true, maxon::GenericComponent, const, (ColorSpace));
	maxon::Int PixelFormatInterface_GetColorSpace_Offset;
	PRIVATE_MAXON_MF_POINTER(PixelFormatInterface_GetDefaultColorProfile, GetDefaultColorProfile, true, maxon::GenericComponent, const, (const ColorProfile&));
	maxon::Int PixelFormatInterface_GetDefaultColorProfile_Offset;
	PRIVATE_MAXON_MF_POINTER(PixelFormatInterface_GetConvertPixelFunc, GetConvertPixelFunc, true, maxon::GenericComponent, const, (Result<CONVERTPIXELFUNC>), const PixelFormat& srcFormatPtr, const ChannelOffsets& srcChannelOffset, const ChannelOffsets& dstChannelOffset, const ColorProfile& srcColorProfile, ColorProfile* dstColorProfile, Bool forceColorProfileConversion, Bool& disableCaching);
	maxon::Int PixelFormatInterface_GetConvertPixelFunc_Offset;
	PRIVATE_MAXON_MF_POINTER(PixelFormatInterface_GetConvertPixelFunc_1, GetConvertPixelFunc, true, maxon::GenericComponent, const, (Result<CONVERTPIXELFUNC>), const PixelFormat& srcFormatPtr, const ChannelOffsets& srcChannelOffset, const ChannelOffsets& dstChannelOffset, const ColorProfile& srcColorProfile, ColorProfile* dstColorProfile, Bool forceColorProfileConversion, COLORCONVERSIONFLAGS colorConversionFlags, Bool& disableCaching);
	maxon::Int PixelFormatInterface_GetConvertPixelFunc_1_Offset;
	PRIVATE_MAXON_MF_POINTER(PixelFormatInterface_ConvertPixelFromSlow, ConvertPixelFromSlow, true, maxon::GenericComponent, const, (Result<void>), const ImageMutableBuffer& dst, Int count, const ImageConstBuffer& src, const ColorProfile& srcColorProfile, ColorProfile* dstColorProfile, CONVERTPIXELFLAGS cflags, GETPIXELFLAGS flags);
	maxon::Int PixelFormatInterface_ConvertPixelFromSlow_Offset;
	PRIVATE_MAXON_MF_POINTER(PixelFormatInterface_IsIdenticalPixel, IsIdenticalPixel, true, maxon::GenericComponent, const, (Bool), const ImageConstBuffer& a, const ImageConstBuffer& b, Int oneTolerance);
	maxon::Int PixelFormatInterface_IsIdenticalPixel_Offset;
	PRIVATE_MAXON_MF_POINTER(PixelFormatInterface_PixToString, PixToString, true, maxon::GenericComponent, const, (String), const Pix* src);
	maxon::Int PixelFormatInterface_PixToString_Offset;
	PRIVATE_MAXON_MF_POINTER(PixelFormatInterface_GetConvertPixelFromFunc, GetConvertPixelFromFunc, true, maxon::GenericComponent, const, (Result<CONVERTPIXELFUNC>), const PixelFormat& srcFormatPtr, const ChannelOffsets& srcChannelOffset, const ChannelOffsets& dstChannelOffset, Bool fastSize, Bool& disableCaching);
	maxon::Int PixelFormatInterface_GetConvertPixelFromFunc_Offset;
	PRIVATE_MAXON_MF_POINTER(PixelFormatInterface_GetConvertPixelToFunc, GetConvertPixelToFunc, true, maxon::GenericComponent, const, (Result<CONVERTPIXELFUNC>), const PixelFormat& dstFormatPtr, const ChannelOffsets& dstChannelOffset, const ChannelOffsets& srcChannelOffset, Bool fastSize, Bool& disableCaching);
	maxon::Int PixelFormatInterface_GetConvertPixelToFunc_Offset;
	PRIVATE_MAXON_MF_POINTER(PixelFormatInterface_GetShortName, GetShortName, true, maxon::GenericComponent, const, (const Char*));
	maxon::Int PixelFormatInterface_GetShortName_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, PixelFormatInterface, Init))
	{
		maxon::Tie(PixelFormatInterface_Init, PixelFormatInterface_Init_Offset) = PixelFormatInterface_Init_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, PixelFormatInterface, GetChannels))
	{
		maxon::Tie(PixelFormatInterface_GetChannels, PixelFormatInterface_GetChannels_Offset) = PixelFormatInterface_GetChannels_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, PixelFormatInterface, GetPixelFormatGroup))
	{
		maxon::Tie(PixelFormatInterface_GetPixelFormatGroup, PixelFormatInterface_GetPixelFormatGroup_Offset) = PixelFormatInterface_GetPixelFormatGroup_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, PixelFormatInterface, CreatePix))
	{
		maxon::Tie(PixelFormatInterface_CreatePix, PixelFormatInterface_CreatePix_Offset) = PixelFormatInterface_CreatePix_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, PixelFormatInterface, GetChannelCount))
	{
		maxon::Tie(PixelFormatInterface_GetChannelCount, PixelFormatInterface_GetChannelCount_Offset) = PixelFormatInterface_GetChannelCount_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, PixelFormatInterface, GetChannelOffsets))
	{
		maxon::Tie(PixelFormatInterface_GetChannelOffsets, PixelFormatInterface_GetChannelOffsets_Offset) = PixelFormatInterface_GetChannelOffsets_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, PixelFormatInterface, GetBitsPerPixel))
	{
		maxon::Tie(PixelFormatInterface_GetBitsPerPixel, PixelFormatInterface_GetBitsPerPixel_Offset) = PixelFormatInterface_GetBitsPerPixel_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, PixelFormatInterface, GetBytesPerLine))
	{
		maxon::Tie(PixelFormatInterface_GetBytesPerLine, PixelFormatInterface_GetBytesPerLine_Offset) = PixelFormatInterface_GetBytesPerLine_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, PixelFormatInterface, GetPackedPixelCount))
	{
		maxon::Tie(PixelFormatInterface_GetPackedPixelCount, PixelFormatInterface_GetPackedPixelCount_Offset) = PixelFormatInterface_GetPackedPixelCount_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, PixelFormatInterface, HasAlpha))
	{
		maxon::Tie(PixelFormatInterface_HasAlpha, PixelFormatInterface_HasAlpha_Offset) = PixelFormatInterface_HasAlpha_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, PixelFormatInterface, GetAlphaPixelFormat))
	{
		maxon::Tie(PixelFormatInterface_GetAlphaPixelFormat, PixelFormatInterface_GetAlphaPixelFormat_Offset) = PixelFormatInterface_GetAlphaPixelFormat_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, PixelFormatInterface, GetColorSpace))
	{
		maxon::Tie(PixelFormatInterface_GetColorSpace, PixelFormatInterface_GetColorSpace_Offset) = PixelFormatInterface_GetColorSpace_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, PixelFormatInterface, GetDefaultColorProfile))
	{
		maxon::Tie(PixelFormatInterface_GetDefaultColorProfile, PixelFormatInterface_GetDefaultColorProfile_Offset) = PixelFormatInterface_GetDefaultColorProfile_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, PixelFormatInterface, GetConvertPixelFunc))
	{
		maxon::Tie(PixelFormatInterface_GetConvertPixelFunc, PixelFormatInterface_GetConvertPixelFunc_Offset) = PixelFormatInterface_GetConvertPixelFunc_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, PixelFormatInterface, GetConvertPixelFunc))
	{
		maxon::Tie(PixelFormatInterface_GetConvertPixelFunc_1, PixelFormatInterface_GetConvertPixelFunc_1_Offset) = PixelFormatInterface_GetConvertPixelFunc_1_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, PixelFormatInterface, ConvertPixelFromSlow))
	{
		maxon::Tie(PixelFormatInterface_ConvertPixelFromSlow, PixelFormatInterface_ConvertPixelFromSlow_Offset) = PixelFormatInterface_ConvertPixelFromSlow_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, PixelFormatInterface, IsIdenticalPixel))
	{
		maxon::Tie(PixelFormatInterface_IsIdenticalPixel, PixelFormatInterface_IsIdenticalPixel_Offset) = PixelFormatInterface_IsIdenticalPixel_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, PixelFormatInterface, PixToString))
	{
		maxon::Tie(PixelFormatInterface_PixToString, PixelFormatInterface_PixToString_Offset) = PixelFormatInterface_PixToString_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, PixelFormatInterface, GetConvertPixelFromFunc))
	{
		maxon::Tie(PixelFormatInterface_GetConvertPixelFromFunc, PixelFormatInterface_GetConvertPixelFromFunc_Offset) = PixelFormatInterface_GetConvertPixelFromFunc_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, PixelFormatInterface, GetConvertPixelToFunc))
	{
		maxon::Tie(PixelFormatInterface_GetConvertPixelToFunc, PixelFormatInterface_GetConvertPixelToFunc_Offset) = PixelFormatInterface_GetConvertPixelToFunc_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, PixelFormatInterface, GetShortName))
	{
		maxon::Tie(PixelFormatInterface_GetShortName, PixelFormatInterface_GetShortName_Offset) = PixelFormatInterface_GetShortName_GetPtr<W>(offset, true);
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
			if constexpr (!S::Implementation::PROXY)
			{
				if (!(Super0::InitMTablesWithBases(info, offset))) return false;
			}
			auto* vt = (PixelFormatInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, PixelFormatInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		PRIVATE_MAXON_MF_WRAPPER(PixelFormatInterface_Init, maxon::GenericComponent,, (Result<void>), const PixelFormatGroup& group, const Char* shortName) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->Init(group, shortName); }
		PRIVATE_MAXON_MF_WRAPPER(PixelFormatInterface_GetChannels, maxon::GenericComponent, const, (Block<const ImageChannel>)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetChannels(); }
		PRIVATE_MAXON_MF_WRAPPER(PixelFormatInterface_GetPixelFormatGroup, maxon::GenericComponent, const, (const PixelFormatGroup&)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetPixelFormatGroup(); }
		PRIVATE_MAXON_MF_WRAPPER(PixelFormatInterface_CreatePix, maxon::GenericComponent, const, (Result<Pix*>), Int width, Int height, Int lineAlignment) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->CreatePix(width, height, lineAlignment); }
		PRIVATE_MAXON_MF_WRAPPER(PixelFormatInterface_GetChannelCount, maxon::GenericComponent, const, (Int)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetChannelCount(); }
		PRIVATE_MAXON_MF_WRAPPER(PixelFormatInterface_GetChannelOffsets, maxon::GenericComponent, const, (const ChannelOffsets&)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetChannelOffsets(); }
		PRIVATE_MAXON_MF_WRAPPER(PixelFormatInterface_GetBitsPerPixel, maxon::GenericComponent, const, (BITS)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetBitsPerPixel(); }
		PRIVATE_MAXON_MF_WRAPPER(PixelFormatInterface_GetBytesPerLine, maxon::GenericComponent, const, (Int), Int width, Int lineAlignment) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetBytesPerLine(width, lineAlignment); }
		PRIVATE_MAXON_MF_WRAPPER(PixelFormatInterface_GetPackedPixelCount, maxon::GenericComponent, const, (Int)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetPackedPixelCount(); }
		PRIVATE_MAXON_MF_WRAPPER(PixelFormatInterface_HasAlpha, maxon::GenericComponent, const, (Bool)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->HasAlpha(); }
		PRIVATE_MAXON_MF_WRAPPER(PixelFormatInterface_GetAlphaPixelFormat, maxon::GenericComponent, const, (Result<Tuple<PixelFormat, Int>>)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetAlphaPixelFormat(); }
		PRIVATE_MAXON_MF_WRAPPER(PixelFormatInterface_GetColorSpace, maxon::GenericComponent, const, (ColorSpace)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetColorSpace(); }
		PRIVATE_MAXON_MF_WRAPPER(PixelFormatInterface_GetDefaultColorProfile, maxon::GenericComponent, const, (const ColorProfile&)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetDefaultColorProfile(); }
		PRIVATE_MAXON_MF_WRAPPER(PixelFormatInterface_GetConvertPixelFunc, maxon::GenericComponent, const, (Result<CONVERTPIXELFUNC>), const PixelFormat& srcFormatPtr, const ChannelOffsets& srcChannelOffset, const ChannelOffsets& dstChannelOffset, const ColorProfile& srcColorProfile, ColorProfile* dstColorProfile, Bool forceColorProfileConversion, Bool& disableCaching) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetConvertPixelFunc(srcFormatPtr, srcChannelOffset, dstChannelOffset, srcColorProfile, dstColorProfile, forceColorProfileConversion, disableCaching); }
		PRIVATE_MAXON_MF_WRAPPER(PixelFormatInterface_GetConvertPixelFunc_1, maxon::GenericComponent, const, (Result<CONVERTPIXELFUNC>), const PixelFormat& srcFormatPtr, const ChannelOffsets& srcChannelOffset, const ChannelOffsets& dstChannelOffset, const ColorProfile& srcColorProfile, ColorProfile* dstColorProfile, Bool forceColorProfileConversion, COLORCONVERSIONFLAGS colorConversionFlags, Bool& disableCaching) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetConvertPixelFunc(srcFormatPtr, srcChannelOffset, dstChannelOffset, srcColorProfile, dstColorProfile, forceColorProfileConversion, colorConversionFlags, disableCaching); }
		PRIVATE_MAXON_MF_WRAPPER(PixelFormatInterface_ConvertPixelFromSlow, maxon::GenericComponent, const, (Result<void>), const ImageMutableBuffer& dst, Int count, const ImageConstBuffer& src, const ColorProfile& srcColorProfile, ColorProfile* dstColorProfile, CONVERTPIXELFLAGS cflags, GETPIXELFLAGS flags) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->ConvertPixelFromSlow(dst, count, src, srcColorProfile, dstColorProfile, cflags, flags); }
		PRIVATE_MAXON_MF_WRAPPER(PixelFormatInterface_IsIdenticalPixel, maxon::GenericComponent, const, (Bool), const ImageConstBuffer& a, const ImageConstBuffer& b, Int oneTolerance) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->IsIdenticalPixel(a, b, oneTolerance); }
		PRIVATE_MAXON_MF_WRAPPER(PixelFormatInterface_PixToString, maxon::GenericComponent, const, (String), const Pix* src) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->PixToString(src); }
		PRIVATE_MAXON_MF_WRAPPER(PixelFormatInterface_GetConvertPixelFromFunc, maxon::GenericComponent, const, (Result<CONVERTPIXELFUNC>), const PixelFormat& srcFormatPtr, const ChannelOffsets& srcChannelOffset, const ChannelOffsets& dstChannelOffset, Bool fastSize, Bool& disableCaching) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetConvertPixelFromFunc(srcFormatPtr, srcChannelOffset, dstChannelOffset, fastSize, disableCaching); }
		PRIVATE_MAXON_MF_WRAPPER(PixelFormatInterface_GetConvertPixelToFunc, maxon::GenericComponent, const, (Result<CONVERTPIXELFUNC>), const PixelFormat& dstFormatPtr, const ChannelOffsets& dstChannelOffset, const ChannelOffsets& srcChannelOffset, Bool fastSize, Bool& disableCaching) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetConvertPixelToFunc(dstFormatPtr, dstChannelOffset, srcChannelOffset, fastSize, disableCaching); }
		PRIVATE_MAXON_MF_WRAPPER(PixelFormatInterface_GetShortName, maxon::GenericComponent, const, (const Char*)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetShortName(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatInterface::Init(const PixelFormatGroup& group, const Char* shortName) -> Result<void>
{
	const PixelFormatInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(PixelFormatInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.PixelFormatInterface_Init_Offset), mt_.PixelFormatInterface_Init, group, shortName);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatInterface::GetChannels() const -> Block<const ImageChannel>
{
	const PixelFormatInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(PixelFormatInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.PixelFormatInterface_GetChannels_Offset), mt_.PixelFormatInterface_GetChannels);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatInterface::GetPixelFormatGroup() const -> const PixelFormatGroup&
{
	const PixelFormatInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(PixelFormatInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.PixelFormatInterface_GetPixelFormatGroup_Offset), mt_.PixelFormatInterface_GetPixelFormatGroup);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatInterface::CreatePix(Int width, Int height, Int lineAlignment) const -> Result<Pix*>
{
	const PixelFormatInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(PixelFormatInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.PixelFormatInterface_CreatePix_Offset), mt_.PixelFormatInterface_CreatePix, width, height, lineAlignment);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatInterface::GetChannelCount() const -> Int
{
	const PixelFormatInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(PixelFormatInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.PixelFormatInterface_GetChannelCount_Offset), mt_.PixelFormatInterface_GetChannelCount);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatInterface::GetChannelOffsets() const -> const ChannelOffsets&
{
	const PixelFormatInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(PixelFormatInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.PixelFormatInterface_GetChannelOffsets_Offset), mt_.PixelFormatInterface_GetChannelOffsets);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatInterface::GetBitsPerPixel() const -> BITS
{
	const PixelFormatInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(PixelFormatInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.PixelFormatInterface_GetBitsPerPixel_Offset), mt_.PixelFormatInterface_GetBitsPerPixel);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatInterface::GetBytesPerLine(Int width, Int lineAlignment) const -> Int
{
	const PixelFormatInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(PixelFormatInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.PixelFormatInterface_GetBytesPerLine_Offset), mt_.PixelFormatInterface_GetBytesPerLine, width, lineAlignment);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatInterface::GetPackedPixelCount() const -> Int
{
	const PixelFormatInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(PixelFormatInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.PixelFormatInterface_GetPackedPixelCount_Offset), mt_.PixelFormatInterface_GetPackedPixelCount);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatInterface::HasAlpha() const -> Bool
{
	const PixelFormatInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(PixelFormatInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.PixelFormatInterface_HasAlpha_Offset), mt_.PixelFormatInterface_HasAlpha);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatInterface::GetAlphaPixelFormat() const -> Result<Tuple<PixelFormat, Int>>
{
	const PixelFormatInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(PixelFormatInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.PixelFormatInterface_GetAlphaPixelFormat_Offset), mt_.PixelFormatInterface_GetAlphaPixelFormat);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatInterface::GetColorSpace() const -> ColorSpace
{
	const PixelFormatInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(PixelFormatInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.PixelFormatInterface_GetColorSpace_Offset), mt_.PixelFormatInterface_GetColorSpace);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatInterface::GetDefaultColorProfile() const -> const ColorProfile&
{
	const PixelFormatInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(PixelFormatInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.PixelFormatInterface_GetDefaultColorProfile_Offset), mt_.PixelFormatInterface_GetDefaultColorProfile);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatInterface::GetConvertPixelFunc(const PixelFormat& srcFormatPtr, const ChannelOffsets& srcChannelOffset, const ChannelOffsets& dstChannelOffset, const ColorProfile& srcColorProfile, ColorProfile* dstColorProfile, Bool forceColorProfileConversion, Bool& disableCaching) const -> Result<CONVERTPIXELFUNC>
{
	const PixelFormatInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(PixelFormatInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.PixelFormatInterface_GetConvertPixelFunc_Offset), mt_.PixelFormatInterface_GetConvertPixelFunc, srcFormatPtr, srcChannelOffset, dstChannelOffset, srcColorProfile, dstColorProfile, forceColorProfileConversion, disableCaching);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatInterface::GetConvertPixelFunc(const PixelFormat& srcFormatPtr, const ChannelOffsets& srcChannelOffset, const ChannelOffsets& dstChannelOffset, const ColorProfile& srcColorProfile, ColorProfile* dstColorProfile, Bool forceColorProfileConversion, COLORCONVERSIONFLAGS colorConversionFlags, Bool& disableCaching) const -> Result<CONVERTPIXELFUNC>
{
	const PixelFormatInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(PixelFormatInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.PixelFormatInterface_GetConvertPixelFunc_1_Offset), mt_.PixelFormatInterface_GetConvertPixelFunc_1, srcFormatPtr, srcChannelOffset, dstChannelOffset, srcColorProfile, dstColorProfile, forceColorProfileConversion, colorConversionFlags, disableCaching);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatInterface::ConvertPixelFromSlow(const ImageMutableBuffer& dst, Int count, const ImageConstBuffer& src, const ColorProfile& srcColorProfile, ColorProfile* dstColorProfile, CONVERTPIXELFLAGS cflags, GETPIXELFLAGS flags) const -> Result<void>
{
	const PixelFormatInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(PixelFormatInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.PixelFormatInterface_ConvertPixelFromSlow_Offset), mt_.PixelFormatInterface_ConvertPixelFromSlow, dst, count, src, srcColorProfile, dstColorProfile, cflags, flags);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatInterface::IsIdenticalPixel(const ImageConstBuffer& a, const ImageConstBuffer& b, Int oneTolerance) const -> Bool
{
	const PixelFormatInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(PixelFormatInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.PixelFormatInterface_IsIdenticalPixel_Offset), mt_.PixelFormatInterface_IsIdenticalPixel, a, b, oneTolerance);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatInterface::PixToString(const Pix* src) const -> String
{
	const PixelFormatInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(PixelFormatInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.PixelFormatInterface_PixToString_Offset), mt_.PixelFormatInterface_PixToString, src);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatInterface::GetConvertPixelFromFunc(const PixelFormat& srcFormatPtr, const ChannelOffsets& srcChannelOffset, const ChannelOffsets& dstChannelOffset, Bool fastSize, Bool& disableCaching) const -> Result<CONVERTPIXELFUNC>
{
	const PixelFormatInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(PixelFormatInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.PixelFormatInterface_GetConvertPixelFromFunc_Offset), mt_.PixelFormatInterface_GetConvertPixelFromFunc, srcFormatPtr, srcChannelOffset, dstChannelOffset, fastSize, disableCaching);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatInterface::GetConvertPixelToFunc(const PixelFormat& dstFormatPtr, const ChannelOffsets& dstChannelOffset, const ChannelOffsets& srcChannelOffset, Bool fastSize, Bool& disableCaching) const -> Result<CONVERTPIXELFUNC>
{
	const PixelFormatInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(PixelFormatInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.PixelFormatInterface_GetConvertPixelToFunc_Offset), mt_.PixelFormatInterface_GetConvertPixelToFunc, dstFormatPtr, dstChannelOffset, srcChannelOffset, fastSize, disableCaching);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatInterface::GetShortName() const -> const Char*
{
	const PixelFormatInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(PixelFormatInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.PixelFormatInterface_GetShortName_Offset), mt_.PixelFormatInterface_GetShortName);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatInterface::Hxx1::Fn<S>::Init(const PixelFormatGroup& group, const Char* shortName) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); PixelFormatInterface* o_ = (PixelFormatInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(PixelFormatInterface, o_, PixelFormatInterface_Init) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<PixelFormatInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<PixelFormatInterface>() : PRIVATE_MAXON_VTABLE(PixelFormatInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.PixelFormatInterface_Init_Offset), mt_.PixelFormatInterface_Init, group, shortName));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatInterface::Hxx1::COWFn<S>::Init(const PixelFormatGroup& group, const Char* shortName) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); PixelFormatInterface* o_ = (PixelFormatInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(PixelFormatInterface, o_, PixelFormatInterface_Init) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<PixelFormatInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<PixelFormatInterface>() : PRIVATE_MAXON_VTABLE(PixelFormatInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.PixelFormatInterface_Init_Offset), mt_.PixelFormatInterface_Init, group, shortName));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatInterface::Hxx1::ConstFn<S>::GetChannels() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Block<const ImageChannel>>, Block<const ImageChannel>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Block<const ImageChannel>>, Block<const ImageChannel>>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const PixelFormatInterface* o_ = (const PixelFormatInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = PixelFormatInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<Block<const ImageChannel>>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(PixelFormatInterface, o_, PixelFormatInterface_GetChannels) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<PixelFormatInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<PixelFormatInterface>() : PRIVATE_MAXON_VTABLE(PixelFormatInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.PixelFormatInterface_GetChannels_Offset), mt_.PixelFormatInterface_GetChannels));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatInterface::Hxx1::ConstFn<S>::GetPixelFormatGroup() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const PixelFormatGroup&>, const PixelFormatGroup&>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const PixelFormatGroup&>, const PixelFormatGroup&>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const PixelFormatInterface* o_ = (const PixelFormatInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = PixelFormatInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<const PixelFormatGroup&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(PixelFormatInterface, o_, PixelFormatInterface_GetPixelFormatGroup) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<PixelFormatInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<PixelFormatInterface>() : PRIVATE_MAXON_VTABLE(PixelFormatInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.PixelFormatInterface_GetPixelFormatGroup_Offset), mt_.PixelFormatInterface_GetPixelFormatGroup));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatInterface::Hxx1::ConstFn<S>::CreatePix(Int width, Int height, Int lineAlignment) const -> Result<Pix*>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Pix*>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const PixelFormatInterface* o_ = (const PixelFormatInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = PixelFormatInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(PixelFormatInterface, o_, PixelFormatInterface_CreatePix) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<PixelFormatInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<PixelFormatInterface>() : PRIVATE_MAXON_VTABLE(PixelFormatInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.PixelFormatInterface_CreatePix_Offset), mt_.PixelFormatInterface_CreatePix, width, height, lineAlignment));
}
template <typename S> template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatInterface::Hxx1::ConstFn<S>::CreatePix(Int width, Int height, Int lineAlignment) const -> Result<TYPE*>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<TYPE*>>; static_assert(!std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value, "Can't invoke MAXON_FUNCTION PixelFormatInterface::CreatePix on super."); if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const PixelFormatInterface* o_ = (const PixelFormatInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = PixelFormatInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->CreatePix<TYPE>(width, height, lineAlignment));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatInterface::Hxx1::ConstFn<S>::GetChannelCount() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const PixelFormatInterface* o_ = (const PixelFormatInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = PixelFormatInterface::NullValuePtr(); if (!o_) return 0; } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(PixelFormatInterface, o_, PixelFormatInterface_GetChannelCount) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<PixelFormatInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<PixelFormatInterface>() : PRIVATE_MAXON_VTABLE(PixelFormatInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.PixelFormatInterface_GetChannelCount_Offset), mt_.PixelFormatInterface_GetChannelCount));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatInterface::Hxx1::ConstFn<S>::GetChannelOffsets() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const ChannelOffsets&>, const ChannelOffsets&>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const ChannelOffsets&>, const ChannelOffsets&>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const PixelFormatInterface* o_ = (const PixelFormatInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = PixelFormatInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<const ChannelOffsets&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(PixelFormatInterface, o_, PixelFormatInterface_GetChannelOffsets) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<PixelFormatInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<PixelFormatInterface>() : PRIVATE_MAXON_VTABLE(PixelFormatInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.PixelFormatInterface_GetChannelOffsets_Offset), mt_.PixelFormatInterface_GetChannelOffsets));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatInterface::Hxx1::ConstFn<S>::GetBitsPerPixel() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<BITS>, BITS>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<BITS>, BITS>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const PixelFormatInterface* o_ = (const PixelFormatInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = PixelFormatInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<BITS>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(PixelFormatInterface, o_, PixelFormatInterface_GetBitsPerPixel) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<PixelFormatInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<PixelFormatInterface>() : PRIVATE_MAXON_VTABLE(PixelFormatInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.PixelFormatInterface_GetBitsPerPixel_Offset), mt_.PixelFormatInterface_GetBitsPerPixel));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatInterface::Hxx1::ConstFn<S>::GetBytesPerLine(Int width, Int lineAlignment) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const PixelFormatInterface* o_ = (const PixelFormatInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = PixelFormatInterface::NullValuePtr(); if (!o_) return 0; } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(PixelFormatInterface, o_, PixelFormatInterface_GetBytesPerLine) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<PixelFormatInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<PixelFormatInterface>() : PRIVATE_MAXON_VTABLE(PixelFormatInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.PixelFormatInterface_GetBytesPerLine_Offset), mt_.PixelFormatInterface_GetBytesPerLine, width, lineAlignment));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatInterface::Hxx1::ConstFn<S>::GetPackedPixelCount() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const PixelFormatInterface* o_ = (const PixelFormatInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = PixelFormatInterface::NullValuePtr(); if (!o_) return 0; } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(PixelFormatInterface, o_, PixelFormatInterface_GetPackedPixelCount) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<PixelFormatInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<PixelFormatInterface>() : PRIVATE_MAXON_VTABLE(PixelFormatInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.PixelFormatInterface_GetPackedPixelCount_Offset), mt_.PixelFormatInterface_GetPackedPixelCount));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatInterface::Hxx1::ConstFn<S>::HasAlpha() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const PixelFormatInterface* o_ = (const PixelFormatInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = PixelFormatInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(PixelFormatInterface, o_, PixelFormatInterface_HasAlpha) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<PixelFormatInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<PixelFormatInterface>() : PRIVATE_MAXON_VTABLE(PixelFormatInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.PixelFormatInterface_HasAlpha_Offset), mt_.PixelFormatInterface_HasAlpha));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatInterface::Hxx1::ConstFn<S>::GetAlphaPixelFormat() const -> Result<Tuple<PixelFormat, Int>>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Tuple<PixelFormat, Int>>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const PixelFormatInterface* o_ = (const PixelFormatInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = PixelFormatInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(PixelFormatInterface, o_, PixelFormatInterface_GetAlphaPixelFormat) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<PixelFormatInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<PixelFormatInterface>() : PRIVATE_MAXON_VTABLE(PixelFormatInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.PixelFormatInterface_GetAlphaPixelFormat_Offset), mt_.PixelFormatInterface_GetAlphaPixelFormat));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatInterface::Hxx1::ConstFn<S>::GetColorSpace() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<ColorSpace>, ColorSpace>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<ColorSpace>, ColorSpace>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const PixelFormatInterface* o_ = (const PixelFormatInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = PixelFormatInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<ColorSpace>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(PixelFormatInterface, o_, PixelFormatInterface_GetColorSpace) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<PixelFormatInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<PixelFormatInterface>() : PRIVATE_MAXON_VTABLE(PixelFormatInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.PixelFormatInterface_GetColorSpace_Offset), mt_.PixelFormatInterface_GetColorSpace));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatInterface::Hxx1::ConstFn<S>::GetDefaultColorProfile() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const ColorProfile&>, const ColorProfile&>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const ColorProfile&>, const ColorProfile&>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const PixelFormatInterface* o_ = (const PixelFormatInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = PixelFormatInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<const ColorProfile&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(PixelFormatInterface, o_, PixelFormatInterface_GetDefaultColorProfile) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<PixelFormatInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<PixelFormatInterface>() : PRIVATE_MAXON_VTABLE(PixelFormatInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.PixelFormatInterface_GetDefaultColorProfile_Offset), mt_.PixelFormatInterface_GetDefaultColorProfile));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatInterface::Hxx1::ConstFn<S>::GetConvertPixelFunc(const PixelFormat& srcFormatPtr, const ChannelOffsets& srcChannelOffset, const ChannelOffsets& dstChannelOffset, const ColorProfile& srcColorProfile, ColorProfile* dstColorProfile, Bool forceColorProfileConversion, Bool& disableCaching) const -> Result<CONVERTPIXELFUNC>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<CONVERTPIXELFUNC>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const PixelFormatInterface* o_ = (const PixelFormatInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = PixelFormatInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(PixelFormatInterface, o_, PixelFormatInterface_GetConvertPixelFunc) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<PixelFormatInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<PixelFormatInterface>() : PRIVATE_MAXON_VTABLE(PixelFormatInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.PixelFormatInterface_GetConvertPixelFunc_Offset), mt_.PixelFormatInterface_GetConvertPixelFunc, srcFormatPtr, srcChannelOffset, dstChannelOffset, srcColorProfile, dstColorProfile, forceColorProfileConversion, disableCaching));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatInterface::Hxx1::ConstFn<S>::GetConvertPixelFunc(const PixelFormat& srcFormatPtr, const ChannelOffsets& srcChannelOffset, const ChannelOffsets& dstChannelOffset, const ColorProfile& srcColorProfile, ColorProfile* dstColorProfile, Bool forceColorProfileConversion, COLORCONVERSIONFLAGS colorConversionFlags, Bool& disableCaching) const -> Result<CONVERTPIXELFUNC>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<CONVERTPIXELFUNC>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const PixelFormatInterface* o_ = (const PixelFormatInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = PixelFormatInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(PixelFormatInterface, o_, PixelFormatInterface_GetConvertPixelFunc_1) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<PixelFormatInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<PixelFormatInterface>() : PRIVATE_MAXON_VTABLE(PixelFormatInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.PixelFormatInterface_GetConvertPixelFunc_1_Offset), mt_.PixelFormatInterface_GetConvertPixelFunc_1, srcFormatPtr, srcChannelOffset, dstChannelOffset, srcColorProfile, dstColorProfile, forceColorProfileConversion, colorConversionFlags, disableCaching));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatInterface::Hxx1::ConstFn<S>::ConvertPixelFromSlow(const ImageMutableBuffer& dst, Int count, const ImageConstBuffer& src, const ColorProfile& srcColorProfile, ColorProfile* dstColorProfile, CONVERTPIXELFLAGS cflags, GETPIXELFLAGS flags) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const PixelFormatInterface* o_ = (const PixelFormatInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = PixelFormatInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(PixelFormatInterface, o_, PixelFormatInterface_ConvertPixelFromSlow) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<PixelFormatInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<PixelFormatInterface>() : PRIVATE_MAXON_VTABLE(PixelFormatInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.PixelFormatInterface_ConvertPixelFromSlow_Offset), mt_.PixelFormatInterface_ConvertPixelFromSlow, dst, count, src, srcColorProfile, dstColorProfile, cflags, flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatInterface::Hxx1::ConstFn<S>::IsIdenticalPixel(const ImageConstBuffer& a, const ImageConstBuffer& b, Int oneTolerance) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const PixelFormatInterface* o_ = (const PixelFormatInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = PixelFormatInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(PixelFormatInterface, o_, PixelFormatInterface_IsIdenticalPixel) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<PixelFormatInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<PixelFormatInterface>() : PRIVATE_MAXON_VTABLE(PixelFormatInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.PixelFormatInterface_IsIdenticalPixel_Offset), mt_.PixelFormatInterface_IsIdenticalPixel, a, b, oneTolerance));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatInterface::Hxx1::ConstFn<S>::PixToString(const Pix* src) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const PixelFormatInterface* o_ = (const PixelFormatInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = PixelFormatInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(PixelFormatInterface, o_, PixelFormatInterface_PixToString) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<PixelFormatInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<PixelFormatInterface>() : PRIVATE_MAXON_VTABLE(PixelFormatInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.PixelFormatInterface_PixToString_Offset), mt_.PixelFormatInterface_PixToString, src));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatInterface::Hxx1::ConstFn<S>::GetConvertPixelFromFunc(const PixelFormat& srcFormatPtr, const ChannelOffsets& srcChannelOffset, const ChannelOffsets& dstChannelOffset, Bool fastSize, Bool& disableCaching) const -> Result<CONVERTPIXELFUNC>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<CONVERTPIXELFUNC>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const PixelFormatInterface* o_ = (const PixelFormatInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = PixelFormatInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(PixelFormatInterface, o_, PixelFormatInterface_GetConvertPixelFromFunc) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<PixelFormatInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<PixelFormatInterface>() : PRIVATE_MAXON_VTABLE(PixelFormatInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.PixelFormatInterface_GetConvertPixelFromFunc_Offset), mt_.PixelFormatInterface_GetConvertPixelFromFunc, srcFormatPtr, srcChannelOffset, dstChannelOffset, fastSize, disableCaching));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatInterface::Hxx1::ConstFn<S>::GetConvertPixelToFunc(const PixelFormat& dstFormatPtr, const ChannelOffsets& dstChannelOffset, const ChannelOffsets& srcChannelOffset, Bool fastSize, Bool& disableCaching) const -> Result<CONVERTPIXELFUNC>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<CONVERTPIXELFUNC>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const PixelFormatInterface* o_ = (const PixelFormatInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = PixelFormatInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(PixelFormatInterface, o_, PixelFormatInterface_GetConvertPixelToFunc) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<PixelFormatInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<PixelFormatInterface>() : PRIVATE_MAXON_VTABLE(PixelFormatInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.PixelFormatInterface_GetConvertPixelToFunc_Offset), mt_.PixelFormatInterface_GetConvertPixelToFunc, dstFormatPtr, dstChannelOffset, srcChannelOffset, fastSize, disableCaching));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatInterface::Hxx1::ConstFn<S>::GetShortName() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const Char*>, const Char*>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const Char*>, const Char*>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const PixelFormatInterface* o_ = (const PixelFormatInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = PixelFormatInterface::NullValuePtr(); if (!o_) return nullptr; } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(PixelFormatInterface, o_, PixelFormatInterface_GetShortName) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<PixelFormatInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<PixelFormatInterface>() : PRIVATE_MAXON_VTABLE(PixelFormatInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.PixelFormatInterface_GetShortName_Offset), mt_.PixelFormatInterface_GetShortName));
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
	PRIVATE_MAXON_SF_POINTER(PixelFormatsInterface_FindOrCreatePixelFormat, FindOrCreatePixelFormat, MAXON_EXPAND_VA_ARGS, (Result<PixelFormat>), const Block<const ImageChannel>& channels);
	template <typename IMPL> void Init()
	{
		PixelFormatsInterface_FindOrCreatePixelFormat = PixelFormatsInterface_FindOrCreatePixelFormat_GetPtr<IMPL>(true);
	}
};

struct PixelFormatsInterface::Hxx2
{
	class Unresolved;
	template <typename C> class Wrapper
	{
	public:
		using Implementation = C;
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

