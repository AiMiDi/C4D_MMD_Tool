
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1

struct PixelFormatGroupInterface::MTable
{
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetEntries);
	static const maxon::Char* const _ids;
	static const maxon::Bool HAS_NONSTATIC = false;
	PixelFormatIterator (*_PixelFormatGroupInterface_GetEntries) (const maxon::GenericComponent* this_);
	maxon::Int _PixelFormatGroupInterface_GetEntries_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, PixelFormatGroupInterface, GetEntries))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, PixelFormatGroupInterface, GetEntries), W, MTable>::type::_PixelFormatGroupInterface_GetEntries;
			_PixelFormatGroupInterface_GetEntries = reinterpret_cast<const decltype(_PixelFormatGroupInterface_GetEntries)&>(ptr);
			_PixelFormatGroupInterface_GetEntries_Offset = offset;
		}
	}
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset)
	{
		if (!W::Implementation::PROXY && (!ObjectInterface::MTable::template InitWithBases<W>(info, offset))) return false;
		MTable* vt = (MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, _interface); if (!vt) return false;
		vt->Init<W>(offset); return true;
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<PixelFormatGroupInterface, typename ObjectInterface::MTable::template CombinedMTable<S>>;
	PRIVATE_MAXON_COMPBASE(PixelFormatGroupInterface);
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct PixelFormatGroupInterface::Hxx2
{
	template <typename S> class Wrapper : public ObjectInterface::Hxx2::template Wrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetEntries);
	static PixelFormatIterator _PixelFormatGroupInterface_GetEntries(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetEntries(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatGroupInterface::GetEntries() const -> PixelFormatIterator
{
	const PixelFormatGroupInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(PixelFormatGroupInterface, this); return mt_._PixelFormatGroupInterface_GetEntries((const maxon::GenericComponent*) this + mt_._PixelFormatGroupInterface_GetEntries_Offset);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatGroupInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetEntries() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<PixelFormatIterator>, PixelFormatIterator>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<PixelFormatIterator>, PixelFormatIterator>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const PixelFormatGroupInterface* o_ = (const PixelFormatGroupInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = PixelFormatGroupInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<PixelFormatIterator>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(PixelFormatGroupInterface, o_, PixelFormatGroupInterface_GetEntries) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<PixelFormatGroupInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<PixelFormatGroupInterface>() : PRIVATE_MAXON_VTABLE(PixelFormatGroupInterface, o_); 
	return (mt_._PixelFormatGroupInterface_GetEntries(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._PixelFormatGroupInterface_GetEntries_Offset));
}
auto PixelFormatGroupInterface::GetPtr() -> Ptr { return Ptr(this); }
auto PixelFormatGroupInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_PixelFormatGroupInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_PixelFormatGroupInterface() { new (s_ui_maxon_PixelFormatGroupInterface) maxon::EntityUse(PixelFormatGroupInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/gfx_image_pixelformat.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_PixelFormatGroupInterface(PixelFormatGroupInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/gfx_image_pixelformat.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif

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
	static const maxon::Bool HAS_NONSTATIC = false;
	Result<void> (*_PixelFormatInterface_Init) (maxon::GenericComponent* this_, const PixelFormatGroup& group, const Char* shortName);
	maxon::Int _PixelFormatInterface_Init_Offset;
	Block<const ImageChannel> (*_PixelFormatInterface_GetChannels) (const maxon::GenericComponent* this_);
	maxon::Int _PixelFormatInterface_GetChannels_Offset;
	const PixelFormatGroup& (*_PixelFormatInterface_GetPixelFormatGroup) (const maxon::GenericComponent* this_);
	maxon::Int _PixelFormatInterface_GetPixelFormatGroup_Offset;
	Result<Pix*> (*_PixelFormatInterface_CreatePix) (const maxon::GenericComponent* this_, Int width, Int height, Int lineAlignment);
	maxon::Int _PixelFormatInterface_CreatePix_Offset;
	Int (*_PixelFormatInterface_GetChannelCount) (const maxon::GenericComponent* this_);
	maxon::Int _PixelFormatInterface_GetChannelCount_Offset;
	const ChannelOffsets& (*_PixelFormatInterface_GetChannelOffsets) (const maxon::GenericComponent* this_);
	maxon::Int _PixelFormatInterface_GetChannelOffsets_Offset;
	BITS (*_PixelFormatInterface_GetBitsPerPixel) (const maxon::GenericComponent* this_);
	maxon::Int _PixelFormatInterface_GetBitsPerPixel_Offset;
	Int (*_PixelFormatInterface_GetBytesPerLine) (const maxon::GenericComponent* this_, Int width, Int lineAlignment);
	maxon::Int _PixelFormatInterface_GetBytesPerLine_Offset;
	Int (*_PixelFormatInterface_GetPackedPixelCount) (const maxon::GenericComponent* this_);
	maxon::Int _PixelFormatInterface_GetPackedPixelCount_Offset;
	Bool (*_PixelFormatInterface_HasAlpha) (const maxon::GenericComponent* this_);
	maxon::Int _PixelFormatInterface_HasAlpha_Offset;
	Result<Tuple<PixelFormat, Int>> (*_PixelFormatInterface_GetAlphaPixelFormat) (const maxon::GenericComponent* this_);
	maxon::Int _PixelFormatInterface_GetAlphaPixelFormat_Offset;
	ColorSpace (*_PixelFormatInterface_GetColorSpace) (const maxon::GenericComponent* this_);
	maxon::Int _PixelFormatInterface_GetColorSpace_Offset;
	const ColorProfile& (*_PixelFormatInterface_GetDefaultColorProfile) (const maxon::GenericComponent* this_);
	maxon::Int _PixelFormatInterface_GetDefaultColorProfile_Offset;
	Result<CONVERTPIXELFUNC> (*_PixelFormatInterface_GetConvertPixelFunc) (const maxon::GenericComponent* this_, const PixelFormat& srcFormatPtr, const ChannelOffsets& srcChannelOffset, const ChannelOffsets& dstChannelOffset, const ColorProfile& srcColorProfile, ColorProfile* dstColorProfile, Bool forceColorProfileConversion, Bool& disableCaching);
	maxon::Int _PixelFormatInterface_GetConvertPixelFunc_Offset;
	Result<void> (*_PixelFormatInterface_ConvertPixelFromSlow) (const maxon::GenericComponent* this_, const ImageMutableBuffer& dst, Int count, const ImageConstBuffer& src, const ColorProfile& srcColorProfile, ColorProfile* dstColorProfile, CONVERTPIXELFLAGS cflags, GETPIXELFLAGS flags);
	maxon::Int _PixelFormatInterface_ConvertPixelFromSlow_Offset;
	Bool (*_PixelFormatInterface_IsIdenticalPixel) (const maxon::GenericComponent* this_, const ImageConstBuffer& a, const ImageConstBuffer& b, Int oneTolerance);
	maxon::Int _PixelFormatInterface_IsIdenticalPixel_Offset;
	String (*_PixelFormatInterface_PixToString) (const maxon::GenericComponent* this_, const Pix* src);
	maxon::Int _PixelFormatInterface_PixToString_Offset;
	Result<CONVERTPIXELFUNC> (*_PixelFormatInterface_GetConvertPixelFromFunc) (const maxon::GenericComponent* this_, const PixelFormat& srcFormatPtr, const ChannelOffsets& srcChannelOffset, const ChannelOffsets& dstChannelOffset, Bool fastSize, Bool& disableCaching);
	maxon::Int _PixelFormatInterface_GetConvertPixelFromFunc_Offset;
	Result<CONVERTPIXELFUNC> (*_PixelFormatInterface_GetConvertPixelToFunc) (const maxon::GenericComponent* this_, const PixelFormat& dstFormatPtr, const ChannelOffsets& dstChannelOffset, const ChannelOffsets& srcChannelOffset, Bool fastSize, Bool& disableCaching);
	maxon::Int _PixelFormatInterface_GetConvertPixelToFunc_Offset;
	const Char* (*_PixelFormatInterface_GetShortName) (const maxon::GenericComponent* this_);
	maxon::Int _PixelFormatInterface_GetShortName_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, PixelFormatInterface, Init))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, PixelFormatInterface, Init), W, MTable>::type::_PixelFormatInterface_Init;
			_PixelFormatInterface_Init = reinterpret_cast<const decltype(_PixelFormatInterface_Init)&>(ptr);
			_PixelFormatInterface_Init_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, PixelFormatInterface, GetChannels))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, PixelFormatInterface, GetChannels), W, MTable>::type::_PixelFormatInterface_GetChannels;
			_PixelFormatInterface_GetChannels = reinterpret_cast<const decltype(_PixelFormatInterface_GetChannels)&>(ptr);
			_PixelFormatInterface_GetChannels_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, PixelFormatInterface, GetPixelFormatGroup))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, PixelFormatInterface, GetPixelFormatGroup), W, MTable>::type::_PixelFormatInterface_GetPixelFormatGroup;
			_PixelFormatInterface_GetPixelFormatGroup = reinterpret_cast<const decltype(_PixelFormatInterface_GetPixelFormatGroup)&>(ptr);
			_PixelFormatInterface_GetPixelFormatGroup_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, PixelFormatInterface, CreatePix))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, PixelFormatInterface, CreatePix), W, MTable>::type::_PixelFormatInterface_CreatePix;
			_PixelFormatInterface_CreatePix = reinterpret_cast<const decltype(_PixelFormatInterface_CreatePix)&>(ptr);
			_PixelFormatInterface_CreatePix_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, PixelFormatInterface, GetChannelCount))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, PixelFormatInterface, GetChannelCount), W, MTable>::type::_PixelFormatInterface_GetChannelCount;
			_PixelFormatInterface_GetChannelCount = reinterpret_cast<const decltype(_PixelFormatInterface_GetChannelCount)&>(ptr);
			_PixelFormatInterface_GetChannelCount_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, PixelFormatInterface, GetChannelOffsets))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, PixelFormatInterface, GetChannelOffsets), W, MTable>::type::_PixelFormatInterface_GetChannelOffsets;
			_PixelFormatInterface_GetChannelOffsets = reinterpret_cast<const decltype(_PixelFormatInterface_GetChannelOffsets)&>(ptr);
			_PixelFormatInterface_GetChannelOffsets_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, PixelFormatInterface, GetBitsPerPixel))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, PixelFormatInterface, GetBitsPerPixel), W, MTable>::type::_PixelFormatInterface_GetBitsPerPixel;
			_PixelFormatInterface_GetBitsPerPixel = reinterpret_cast<const decltype(_PixelFormatInterface_GetBitsPerPixel)&>(ptr);
			_PixelFormatInterface_GetBitsPerPixel_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, PixelFormatInterface, GetBytesPerLine))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, PixelFormatInterface, GetBytesPerLine), W, MTable>::type::_PixelFormatInterface_GetBytesPerLine;
			_PixelFormatInterface_GetBytesPerLine = reinterpret_cast<const decltype(_PixelFormatInterface_GetBytesPerLine)&>(ptr);
			_PixelFormatInterface_GetBytesPerLine_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, PixelFormatInterface, GetPackedPixelCount))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, PixelFormatInterface, GetPackedPixelCount), W, MTable>::type::_PixelFormatInterface_GetPackedPixelCount;
			_PixelFormatInterface_GetPackedPixelCount = reinterpret_cast<const decltype(_PixelFormatInterface_GetPackedPixelCount)&>(ptr);
			_PixelFormatInterface_GetPackedPixelCount_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, PixelFormatInterface, HasAlpha))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, PixelFormatInterface, HasAlpha), W, MTable>::type::_PixelFormatInterface_HasAlpha;
			_PixelFormatInterface_HasAlpha = reinterpret_cast<const decltype(_PixelFormatInterface_HasAlpha)&>(ptr);
			_PixelFormatInterface_HasAlpha_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, PixelFormatInterface, GetAlphaPixelFormat))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, PixelFormatInterface, GetAlphaPixelFormat), W, MTable>::type::_PixelFormatInterface_GetAlphaPixelFormat;
			_PixelFormatInterface_GetAlphaPixelFormat = reinterpret_cast<const decltype(_PixelFormatInterface_GetAlphaPixelFormat)&>(ptr);
			_PixelFormatInterface_GetAlphaPixelFormat_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, PixelFormatInterface, GetColorSpace))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, PixelFormatInterface, GetColorSpace), W, MTable>::type::_PixelFormatInterface_GetColorSpace;
			_PixelFormatInterface_GetColorSpace = reinterpret_cast<const decltype(_PixelFormatInterface_GetColorSpace)&>(ptr);
			_PixelFormatInterface_GetColorSpace_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, PixelFormatInterface, GetDefaultColorProfile))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, PixelFormatInterface, GetDefaultColorProfile), W, MTable>::type::_PixelFormatInterface_GetDefaultColorProfile;
			_PixelFormatInterface_GetDefaultColorProfile = reinterpret_cast<const decltype(_PixelFormatInterface_GetDefaultColorProfile)&>(ptr);
			_PixelFormatInterface_GetDefaultColorProfile_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, PixelFormatInterface, GetConvertPixelFunc))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, PixelFormatInterface, GetConvertPixelFunc), W, MTable>::type::_PixelFormatInterface_GetConvertPixelFunc;
			_PixelFormatInterface_GetConvertPixelFunc = reinterpret_cast<const decltype(_PixelFormatInterface_GetConvertPixelFunc)&>(ptr);
			_PixelFormatInterface_GetConvertPixelFunc_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, PixelFormatInterface, ConvertPixelFromSlow))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, PixelFormatInterface, ConvertPixelFromSlow), W, MTable>::type::_PixelFormatInterface_ConvertPixelFromSlow;
			_PixelFormatInterface_ConvertPixelFromSlow = reinterpret_cast<const decltype(_PixelFormatInterface_ConvertPixelFromSlow)&>(ptr);
			_PixelFormatInterface_ConvertPixelFromSlow_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, PixelFormatInterface, IsIdenticalPixel))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, PixelFormatInterface, IsIdenticalPixel), W, MTable>::type::_PixelFormatInterface_IsIdenticalPixel;
			_PixelFormatInterface_IsIdenticalPixel = reinterpret_cast<const decltype(_PixelFormatInterface_IsIdenticalPixel)&>(ptr);
			_PixelFormatInterface_IsIdenticalPixel_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, PixelFormatInterface, PixToString))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, PixelFormatInterface, PixToString), W, MTable>::type::_PixelFormatInterface_PixToString;
			_PixelFormatInterface_PixToString = reinterpret_cast<const decltype(_PixelFormatInterface_PixToString)&>(ptr);
			_PixelFormatInterface_PixToString_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, PixelFormatInterface, GetConvertPixelFromFunc))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, PixelFormatInterface, GetConvertPixelFromFunc), W, MTable>::type::_PixelFormatInterface_GetConvertPixelFromFunc;
			_PixelFormatInterface_GetConvertPixelFromFunc = reinterpret_cast<const decltype(_PixelFormatInterface_GetConvertPixelFromFunc)&>(ptr);
			_PixelFormatInterface_GetConvertPixelFromFunc_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, PixelFormatInterface, GetConvertPixelToFunc))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, PixelFormatInterface, GetConvertPixelToFunc), W, MTable>::type::_PixelFormatInterface_GetConvertPixelToFunc;
			_PixelFormatInterface_GetConvertPixelToFunc = reinterpret_cast<const decltype(_PixelFormatInterface_GetConvertPixelToFunc)&>(ptr);
			_PixelFormatInterface_GetConvertPixelToFunc_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, PixelFormatInterface, GetShortName))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, PixelFormatInterface, GetShortName), W, MTable>::type::_PixelFormatInterface_GetShortName;
			_PixelFormatInterface_GetShortName = reinterpret_cast<const decltype(_PixelFormatInterface_GetShortName)&>(ptr);
			_PixelFormatInterface_GetShortName_Offset = offset;
		}
	}
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset)
	{
		if (!W::Implementation::PROXY && (!ObjectInterface::MTable::template InitWithBases<W>(info, offset))) return false;
		MTable* vt = (MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, _interface); if (!vt) return false;
		vt->Init<W>(offset); return true;
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<PixelFormatInterface, typename ObjectInterface::MTable::template CombinedMTable<S>>;
	PRIVATE_MAXON_COMPBASE(PixelFormatInterface);
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct PixelFormatInterface::Hxx2
{
	template <typename S> class Wrapper : public ObjectInterface::Hxx2::template Wrapper<S>
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
	static Result<void> _PixelFormatInterface_Init(maxon::GenericComponent* this_, const PixelFormatGroup& group, const Char* shortName) { return ((typename S::Implementation*) this_)->Init(group, shortName); }
	static Block<const ImageChannel> _PixelFormatInterface_GetChannels(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetChannels(); }
	static const PixelFormatGroup& _PixelFormatInterface_GetPixelFormatGroup(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetPixelFormatGroup(); }
	static Result<Pix*> _PixelFormatInterface_CreatePix(const maxon::GenericComponent* this_, Int width, Int height, Int lineAlignment) { return ((const typename S::Implementation*) this_)->CreatePix(width, height, lineAlignment); }
	static Int _PixelFormatInterface_GetChannelCount(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetChannelCount(); }
	static const ChannelOffsets& _PixelFormatInterface_GetChannelOffsets(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetChannelOffsets(); }
	static BITS _PixelFormatInterface_GetBitsPerPixel(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetBitsPerPixel(); }
	static Int _PixelFormatInterface_GetBytesPerLine(const maxon::GenericComponent* this_, Int width, Int lineAlignment) { return ((const typename S::Implementation*) this_)->GetBytesPerLine(width, lineAlignment); }
	static Int _PixelFormatInterface_GetPackedPixelCount(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetPackedPixelCount(); }
	static Bool _PixelFormatInterface_HasAlpha(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->HasAlpha(); }
	static Result<Tuple<PixelFormat, Int>> _PixelFormatInterface_GetAlphaPixelFormat(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetAlphaPixelFormat(); }
	static ColorSpace _PixelFormatInterface_GetColorSpace(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetColorSpace(); }
	static const ColorProfile& _PixelFormatInterface_GetDefaultColorProfile(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetDefaultColorProfile(); }
	static Result<CONVERTPIXELFUNC> _PixelFormatInterface_GetConvertPixelFunc(const maxon::GenericComponent* this_, const PixelFormat& srcFormatPtr, const ChannelOffsets& srcChannelOffset, const ChannelOffsets& dstChannelOffset, const ColorProfile& srcColorProfile, ColorProfile* dstColorProfile, Bool forceColorProfileConversion, Bool& disableCaching) { return ((const typename S::Implementation*) this_)->GetConvertPixelFunc(srcFormatPtr, srcChannelOffset, dstChannelOffset, srcColorProfile, dstColorProfile, forceColorProfileConversion, disableCaching); }
	static Result<void> _PixelFormatInterface_ConvertPixelFromSlow(const maxon::GenericComponent* this_, const ImageMutableBuffer& dst, Int count, const ImageConstBuffer& src, const ColorProfile& srcColorProfile, ColorProfile* dstColorProfile, CONVERTPIXELFLAGS cflags, GETPIXELFLAGS flags) { return ((const typename S::Implementation*) this_)->ConvertPixelFromSlow(dst, count, src, srcColorProfile, dstColorProfile, cflags, flags); }
	static Bool _PixelFormatInterface_IsIdenticalPixel(const maxon::GenericComponent* this_, const ImageConstBuffer& a, const ImageConstBuffer& b, Int oneTolerance) { return ((const typename S::Implementation*) this_)->IsIdenticalPixel(a, b, oneTolerance); }
	static String _PixelFormatInterface_PixToString(const maxon::GenericComponent* this_, const Pix* src) { return ((const typename S::Implementation*) this_)->PixToString(src); }
	static Result<CONVERTPIXELFUNC> _PixelFormatInterface_GetConvertPixelFromFunc(const maxon::GenericComponent* this_, const PixelFormat& srcFormatPtr, const ChannelOffsets& srcChannelOffset, const ChannelOffsets& dstChannelOffset, Bool fastSize, Bool& disableCaching) { return ((const typename S::Implementation*) this_)->GetConvertPixelFromFunc(srcFormatPtr, srcChannelOffset, dstChannelOffset, fastSize, disableCaching); }
	static Result<CONVERTPIXELFUNC> _PixelFormatInterface_GetConvertPixelToFunc(const maxon::GenericComponent* this_, const PixelFormat& dstFormatPtr, const ChannelOffsets& dstChannelOffset, const ChannelOffsets& srcChannelOffset, Bool fastSize, Bool& disableCaching) { return ((const typename S::Implementation*) this_)->GetConvertPixelToFunc(dstFormatPtr, dstChannelOffset, srcChannelOffset, fastSize, disableCaching); }
	static const Char* _PixelFormatInterface_GetShortName(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetShortName(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatInterface::Init(const PixelFormatGroup& group, const Char* shortName) -> Result<void>
{
	const PixelFormatInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(PixelFormatInterface, this); return mt_._PixelFormatInterface_Init((maxon::GenericComponent*) this + mt_._PixelFormatInterface_Init_Offset, group, shortName);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatInterface::GetChannels() const -> Block<const ImageChannel>
{
	const PixelFormatInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(PixelFormatInterface, this); return mt_._PixelFormatInterface_GetChannels((const maxon::GenericComponent*) this + mt_._PixelFormatInterface_GetChannels_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatInterface::GetPixelFormatGroup() const -> const PixelFormatGroup&
{
	const PixelFormatInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(PixelFormatInterface, this); return mt_._PixelFormatInterface_GetPixelFormatGroup((const maxon::GenericComponent*) this + mt_._PixelFormatInterface_GetPixelFormatGroup_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatInterface::CreatePix(Int width, Int height, Int lineAlignment) const -> Result<Pix*>
{
	const PixelFormatInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(PixelFormatInterface, this); return mt_._PixelFormatInterface_CreatePix((const maxon::GenericComponent*) this + mt_._PixelFormatInterface_CreatePix_Offset, width, height, lineAlignment);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatInterface::GetChannelCount() const -> Int
{
	const PixelFormatInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(PixelFormatInterface, this); return mt_._PixelFormatInterface_GetChannelCount((const maxon::GenericComponent*) this + mt_._PixelFormatInterface_GetChannelCount_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatInterface::GetChannelOffsets() const -> const ChannelOffsets&
{
	const PixelFormatInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(PixelFormatInterface, this); return mt_._PixelFormatInterface_GetChannelOffsets((const maxon::GenericComponent*) this + mt_._PixelFormatInterface_GetChannelOffsets_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatInterface::GetBitsPerPixel() const -> BITS
{
	const PixelFormatInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(PixelFormatInterface, this); return mt_._PixelFormatInterface_GetBitsPerPixel((const maxon::GenericComponent*) this + mt_._PixelFormatInterface_GetBitsPerPixel_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatInterface::GetBytesPerLine(Int width, Int lineAlignment) const -> Int
{
	const PixelFormatInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(PixelFormatInterface, this); return mt_._PixelFormatInterface_GetBytesPerLine((const maxon::GenericComponent*) this + mt_._PixelFormatInterface_GetBytesPerLine_Offset, width, lineAlignment);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatInterface::GetPackedPixelCount() const -> Int
{
	const PixelFormatInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(PixelFormatInterface, this); return mt_._PixelFormatInterface_GetPackedPixelCount((const maxon::GenericComponent*) this + mt_._PixelFormatInterface_GetPackedPixelCount_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatInterface::HasAlpha() const -> Bool
{
	const PixelFormatInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(PixelFormatInterface, this); return mt_._PixelFormatInterface_HasAlpha((const maxon::GenericComponent*) this + mt_._PixelFormatInterface_HasAlpha_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatInterface::GetAlphaPixelFormat() const -> Result<Tuple<PixelFormat, Int>>
{
	const PixelFormatInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(PixelFormatInterface, this); return mt_._PixelFormatInterface_GetAlphaPixelFormat((const maxon::GenericComponent*) this + mt_._PixelFormatInterface_GetAlphaPixelFormat_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatInterface::GetColorSpace() const -> ColorSpace
{
	const PixelFormatInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(PixelFormatInterface, this); return mt_._PixelFormatInterface_GetColorSpace((const maxon::GenericComponent*) this + mt_._PixelFormatInterface_GetColorSpace_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatInterface::GetDefaultColorProfile() const -> const ColorProfile&
{
	const PixelFormatInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(PixelFormatInterface, this); return mt_._PixelFormatInterface_GetDefaultColorProfile((const maxon::GenericComponent*) this + mt_._PixelFormatInterface_GetDefaultColorProfile_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatInterface::GetConvertPixelFunc(const PixelFormat& srcFormatPtr, const ChannelOffsets& srcChannelOffset, const ChannelOffsets& dstChannelOffset, const ColorProfile& srcColorProfile, ColorProfile* dstColorProfile, Bool forceColorProfileConversion, Bool& disableCaching) const -> Result<CONVERTPIXELFUNC>
{
	const PixelFormatInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(PixelFormatInterface, this); return mt_._PixelFormatInterface_GetConvertPixelFunc((const maxon::GenericComponent*) this + mt_._PixelFormatInterface_GetConvertPixelFunc_Offset, srcFormatPtr, srcChannelOffset, dstChannelOffset, srcColorProfile, dstColorProfile, forceColorProfileConversion, disableCaching);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatInterface::ConvertPixelFromSlow(const ImageMutableBuffer& dst, Int count, const ImageConstBuffer& src, const ColorProfile& srcColorProfile, ColorProfile* dstColorProfile, CONVERTPIXELFLAGS cflags, GETPIXELFLAGS flags) const -> Result<void>
{
	const PixelFormatInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(PixelFormatInterface, this); return mt_._PixelFormatInterface_ConvertPixelFromSlow((const maxon::GenericComponent*) this + mt_._PixelFormatInterface_ConvertPixelFromSlow_Offset, dst, count, src, srcColorProfile, dstColorProfile, cflags, flags);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatInterface::IsIdenticalPixel(const ImageConstBuffer& a, const ImageConstBuffer& b, Int oneTolerance) const -> Bool
{
	const PixelFormatInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(PixelFormatInterface, this); return mt_._PixelFormatInterface_IsIdenticalPixel((const maxon::GenericComponent*) this + mt_._PixelFormatInterface_IsIdenticalPixel_Offset, a, b, oneTolerance);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatInterface::PixToString(const Pix* src) const -> String
{
	const PixelFormatInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(PixelFormatInterface, this); return mt_._PixelFormatInterface_PixToString((const maxon::GenericComponent*) this + mt_._PixelFormatInterface_PixToString_Offset, src);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatInterface::GetConvertPixelFromFunc(const PixelFormat& srcFormatPtr, const ChannelOffsets& srcChannelOffset, const ChannelOffsets& dstChannelOffset, Bool fastSize, Bool& disableCaching) const -> Result<CONVERTPIXELFUNC>
{
	const PixelFormatInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(PixelFormatInterface, this); return mt_._PixelFormatInterface_GetConvertPixelFromFunc((const maxon::GenericComponent*) this + mt_._PixelFormatInterface_GetConvertPixelFromFunc_Offset, srcFormatPtr, srcChannelOffset, dstChannelOffset, fastSize, disableCaching);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatInterface::GetConvertPixelToFunc(const PixelFormat& dstFormatPtr, const ChannelOffsets& dstChannelOffset, const ChannelOffsets& srcChannelOffset, Bool fastSize, Bool& disableCaching) const -> Result<CONVERTPIXELFUNC>
{
	const PixelFormatInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(PixelFormatInterface, this); return mt_._PixelFormatInterface_GetConvertPixelToFunc((const maxon::GenericComponent*) this + mt_._PixelFormatInterface_GetConvertPixelToFunc_Offset, dstFormatPtr, dstChannelOffset, srcChannelOffset, fastSize, disableCaching);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatInterface::GetShortName() const -> const Char*
{
	const PixelFormatInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(PixelFormatInterface, this); return mt_._PixelFormatInterface_GetShortName((const maxon::GenericComponent*) this + mt_._PixelFormatInterface_GetShortName_Offset);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatInterface::Hxx1::ReferenceFunctionsImpl<S>::Init(const PixelFormatGroup& group, const Char* shortName) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); PixelFormatInterface* o_ = (PixelFormatInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(PixelFormatInterface, o_, PixelFormatInterface_Init) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<PixelFormatInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<PixelFormatInterface>() : PRIVATE_MAXON_VTABLE(PixelFormatInterface, o_); 
	return (mt_._PixelFormatInterface_Init(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._PixelFormatInterface_Init_Offset, group, shortName));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatInterface::Hxx1::COWReferenceFunctionsImpl<S>::Init(const PixelFormatGroup& group, const Char* shortName) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); PixelFormatInterface* o_ = (PixelFormatInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(PixelFormatInterface, o_, PixelFormatInterface_Init) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<PixelFormatInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<PixelFormatInterface>() : PRIVATE_MAXON_VTABLE(PixelFormatInterface, o_); 
	return (mt_._PixelFormatInterface_Init(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._PixelFormatInterface_Init_Offset, group, shortName));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetChannels() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Block<const ImageChannel>>, Block<const ImageChannel>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Block<const ImageChannel>>, Block<const ImageChannel>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const PixelFormatInterface* o_ = (const PixelFormatInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = PixelFormatInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<Block<const ImageChannel>>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(PixelFormatInterface, o_, PixelFormatInterface_GetChannels) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<PixelFormatInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<PixelFormatInterface>() : PRIVATE_MAXON_VTABLE(PixelFormatInterface, o_); 
	return (mt_._PixelFormatInterface_GetChannels(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._PixelFormatInterface_GetChannels_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetPixelFormatGroup() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const PixelFormatGroup&>, const PixelFormatGroup&>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const PixelFormatGroup&>, const PixelFormatGroup&>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const PixelFormatInterface* o_ = (const PixelFormatInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = PixelFormatInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<const PixelFormatGroup&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(PixelFormatInterface, o_, PixelFormatInterface_GetPixelFormatGroup) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<PixelFormatInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<PixelFormatInterface>() : PRIVATE_MAXON_VTABLE(PixelFormatInterface, o_); 
	return (mt_._PixelFormatInterface_GetPixelFormatGroup(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._PixelFormatInterface_GetPixelFormatGroup_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatInterface::Hxx1::ConstReferenceFunctionsImpl<S>::CreatePix(Int width, Int height, Int lineAlignment) const -> Result<Pix*>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Pix*>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const PixelFormatInterface* o_ = (const PixelFormatInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = PixelFormatInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(PixelFormatInterface, o_, PixelFormatInterface_CreatePix) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<PixelFormatInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<PixelFormatInterface>() : PRIVATE_MAXON_VTABLE(PixelFormatInterface, o_); 
	return (mt_._PixelFormatInterface_CreatePix(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._PixelFormatInterface_CreatePix_Offset, width, height, lineAlignment));
}
template <typename S> template <typename TYPE> MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatInterface::Hxx1::ConstReferenceFunctionsImpl<S>::CreatePix(Int width, Int height, Int lineAlignment) const -> Result<TYPE*>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<TYPE*>>; static_assert(!std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value, "Can't invoke MAXON_FUNCTION PixelFormatInterface::CreatePix on super."); if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const PixelFormatInterface* o_ = (const PixelFormatInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = PixelFormatInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->CreatePix<TYPE>(width, height, lineAlignment));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetChannelCount() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const PixelFormatInterface* o_ = (const PixelFormatInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = PixelFormatInterface::NullValuePtr(); if (!o_) return 0; } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(PixelFormatInterface, o_, PixelFormatInterface_GetChannelCount) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<PixelFormatInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<PixelFormatInterface>() : PRIVATE_MAXON_VTABLE(PixelFormatInterface, o_); 
	return (mt_._PixelFormatInterface_GetChannelCount(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._PixelFormatInterface_GetChannelCount_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetChannelOffsets() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const ChannelOffsets&>, const ChannelOffsets&>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const ChannelOffsets&>, const ChannelOffsets&>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const PixelFormatInterface* o_ = (const PixelFormatInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = PixelFormatInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<const ChannelOffsets&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(PixelFormatInterface, o_, PixelFormatInterface_GetChannelOffsets) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<PixelFormatInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<PixelFormatInterface>() : PRIVATE_MAXON_VTABLE(PixelFormatInterface, o_); 
	return (mt_._PixelFormatInterface_GetChannelOffsets(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._PixelFormatInterface_GetChannelOffsets_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetBitsPerPixel() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<BITS>, BITS>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<BITS>, BITS>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const PixelFormatInterface* o_ = (const PixelFormatInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = PixelFormatInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<BITS>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(PixelFormatInterface, o_, PixelFormatInterface_GetBitsPerPixel) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<PixelFormatInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<PixelFormatInterface>() : PRIVATE_MAXON_VTABLE(PixelFormatInterface, o_); 
	return (mt_._PixelFormatInterface_GetBitsPerPixel(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._PixelFormatInterface_GetBitsPerPixel_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetBytesPerLine(Int width, Int lineAlignment) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const PixelFormatInterface* o_ = (const PixelFormatInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = PixelFormatInterface::NullValuePtr(); if (!o_) return 0; } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(PixelFormatInterface, o_, PixelFormatInterface_GetBytesPerLine) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<PixelFormatInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<PixelFormatInterface>() : PRIVATE_MAXON_VTABLE(PixelFormatInterface, o_); 
	return (mt_._PixelFormatInterface_GetBytesPerLine(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._PixelFormatInterface_GetBytesPerLine_Offset, width, lineAlignment));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetPackedPixelCount() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const PixelFormatInterface* o_ = (const PixelFormatInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = PixelFormatInterface::NullValuePtr(); if (!o_) return 0; } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(PixelFormatInterface, o_, PixelFormatInterface_GetPackedPixelCount) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<PixelFormatInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<PixelFormatInterface>() : PRIVATE_MAXON_VTABLE(PixelFormatInterface, o_); 
	return (mt_._PixelFormatInterface_GetPackedPixelCount(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._PixelFormatInterface_GetPackedPixelCount_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatInterface::Hxx1::ConstReferenceFunctionsImpl<S>::HasAlpha() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const PixelFormatInterface* o_ = (const PixelFormatInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = PixelFormatInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(PixelFormatInterface, o_, PixelFormatInterface_HasAlpha) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<PixelFormatInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<PixelFormatInterface>() : PRIVATE_MAXON_VTABLE(PixelFormatInterface, o_); 
	return (mt_._PixelFormatInterface_HasAlpha(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._PixelFormatInterface_HasAlpha_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetAlphaPixelFormat() const -> Result<Tuple<PixelFormat, Int>>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Tuple<PixelFormat, Int>>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const PixelFormatInterface* o_ = (const PixelFormatInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = PixelFormatInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(PixelFormatInterface, o_, PixelFormatInterface_GetAlphaPixelFormat) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<PixelFormatInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<PixelFormatInterface>() : PRIVATE_MAXON_VTABLE(PixelFormatInterface, o_); 
	return (mt_._PixelFormatInterface_GetAlphaPixelFormat(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._PixelFormatInterface_GetAlphaPixelFormat_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetColorSpace() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<ColorSpace>, ColorSpace>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<ColorSpace>, ColorSpace>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const PixelFormatInterface* o_ = (const PixelFormatInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = PixelFormatInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<ColorSpace>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(PixelFormatInterface, o_, PixelFormatInterface_GetColorSpace) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<PixelFormatInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<PixelFormatInterface>() : PRIVATE_MAXON_VTABLE(PixelFormatInterface, o_); 
	return (mt_._PixelFormatInterface_GetColorSpace(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._PixelFormatInterface_GetColorSpace_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetDefaultColorProfile() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const ColorProfile&>, const ColorProfile&>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const ColorProfile&>, const ColorProfile&>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const PixelFormatInterface* o_ = (const PixelFormatInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = PixelFormatInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<const ColorProfile&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(PixelFormatInterface, o_, PixelFormatInterface_GetDefaultColorProfile) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<PixelFormatInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<PixelFormatInterface>() : PRIVATE_MAXON_VTABLE(PixelFormatInterface, o_); 
	return (mt_._PixelFormatInterface_GetDefaultColorProfile(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._PixelFormatInterface_GetDefaultColorProfile_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetConvertPixelFunc(const PixelFormat& srcFormatPtr, const ChannelOffsets& srcChannelOffset, const ChannelOffsets& dstChannelOffset, const ColorProfile& srcColorProfile, ColorProfile* dstColorProfile, Bool forceColorProfileConversion, Bool& disableCaching) const -> Result<CONVERTPIXELFUNC>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<CONVERTPIXELFUNC>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const PixelFormatInterface* o_ = (const PixelFormatInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = PixelFormatInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(PixelFormatInterface, o_, PixelFormatInterface_GetConvertPixelFunc) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<PixelFormatInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<PixelFormatInterface>() : PRIVATE_MAXON_VTABLE(PixelFormatInterface, o_); 
	return (mt_._PixelFormatInterface_GetConvertPixelFunc(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._PixelFormatInterface_GetConvertPixelFunc_Offset, srcFormatPtr, srcChannelOffset, dstChannelOffset, srcColorProfile, dstColorProfile, forceColorProfileConversion, disableCaching));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatInterface::Hxx1::ConstReferenceFunctionsImpl<S>::ConvertPixelFromSlow(const ImageMutableBuffer& dst, Int count, const ImageConstBuffer& src, const ColorProfile& srcColorProfile, ColorProfile* dstColorProfile, CONVERTPIXELFLAGS cflags, GETPIXELFLAGS flags) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const PixelFormatInterface* o_ = (const PixelFormatInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = PixelFormatInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(PixelFormatInterface, o_, PixelFormatInterface_ConvertPixelFromSlow) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<PixelFormatInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<PixelFormatInterface>() : PRIVATE_MAXON_VTABLE(PixelFormatInterface, o_); 
	return (mt_._PixelFormatInterface_ConvertPixelFromSlow(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._PixelFormatInterface_ConvertPixelFromSlow_Offset, dst, count, src, srcColorProfile, dstColorProfile, cflags, flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatInterface::Hxx1::ConstReferenceFunctionsImpl<S>::IsIdenticalPixel(const ImageConstBuffer& a, const ImageConstBuffer& b, Int oneTolerance) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const PixelFormatInterface* o_ = (const PixelFormatInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = PixelFormatInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(PixelFormatInterface, o_, PixelFormatInterface_IsIdenticalPixel) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<PixelFormatInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<PixelFormatInterface>() : PRIVATE_MAXON_VTABLE(PixelFormatInterface, o_); 
	return (mt_._PixelFormatInterface_IsIdenticalPixel(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._PixelFormatInterface_IsIdenticalPixel_Offset, a, b, oneTolerance));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatInterface::Hxx1::ConstReferenceFunctionsImpl<S>::PixToString(const Pix* src) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const PixelFormatInterface* o_ = (const PixelFormatInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = PixelFormatInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(PixelFormatInterface, o_, PixelFormatInterface_PixToString) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<PixelFormatInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<PixelFormatInterface>() : PRIVATE_MAXON_VTABLE(PixelFormatInterface, o_); 
	return (mt_._PixelFormatInterface_PixToString(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._PixelFormatInterface_PixToString_Offset, src));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetConvertPixelFromFunc(const PixelFormat& srcFormatPtr, const ChannelOffsets& srcChannelOffset, const ChannelOffsets& dstChannelOffset, Bool fastSize, Bool& disableCaching) const -> Result<CONVERTPIXELFUNC>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<CONVERTPIXELFUNC>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const PixelFormatInterface* o_ = (const PixelFormatInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = PixelFormatInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(PixelFormatInterface, o_, PixelFormatInterface_GetConvertPixelFromFunc) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<PixelFormatInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<PixelFormatInterface>() : PRIVATE_MAXON_VTABLE(PixelFormatInterface, o_); 
	return (mt_._PixelFormatInterface_GetConvertPixelFromFunc(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._PixelFormatInterface_GetConvertPixelFromFunc_Offset, srcFormatPtr, srcChannelOffset, dstChannelOffset, fastSize, disableCaching));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetConvertPixelToFunc(const PixelFormat& dstFormatPtr, const ChannelOffsets& dstChannelOffset, const ChannelOffsets& srcChannelOffset, Bool fastSize, Bool& disableCaching) const -> Result<CONVERTPIXELFUNC>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<CONVERTPIXELFUNC>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const PixelFormatInterface* o_ = (const PixelFormatInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = PixelFormatInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(PixelFormatInterface, o_, PixelFormatInterface_GetConvertPixelToFunc) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<PixelFormatInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<PixelFormatInterface>() : PRIVATE_MAXON_VTABLE(PixelFormatInterface, o_); 
	return (mt_._PixelFormatInterface_GetConvertPixelToFunc(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._PixelFormatInterface_GetConvertPixelToFunc_Offset, dstFormatPtr, dstChannelOffset, srcChannelOffset, fastSize, disableCaching));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetShortName() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const Char*>, const Char*>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const Char*>, const Char*>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const PixelFormatInterface* o_ = (const PixelFormatInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = PixelFormatInterface::NullValuePtr(); if (!o_) return nullptr; } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(PixelFormatInterface, o_, PixelFormatInterface_GetShortName) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<PixelFormatInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<PixelFormatInterface>() : PRIVATE_MAXON_VTABLE(PixelFormatInterface, o_); 
	return (mt_._PixelFormatInterface_GetShortName(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._PixelFormatInterface_GetShortName_Offset));
}
auto PixelFormatInterface::GetPtr() -> Ptr { return Ptr(this); }
auto PixelFormatInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_PixelFormatInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_PixelFormatInterface() { new (s_ui_maxon_PixelFormatInterface) maxon::EntityUse(PixelFormatInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/gfx_image_pixelformat.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_PixelFormatInterface(PixelFormatInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/gfx_image_pixelformat.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif

struct PixelFormatIndexedColorInterface::MTable
{
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetColorTablePixelFormat);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetColorTableSize);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetIndex);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(InitColorTable);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(SetIndex);
	static const maxon::Char* const _ids;
	static const maxon::Bool HAS_NONSTATIC = false;
	Result<void> (*_PixelFormatIndexedColorInterface_InitColorTable) (maxon::GenericComponent* this_, Int count, const PixelFormat& srcFormatPtr);
	maxon::Int _PixelFormatIndexedColorInterface_InitColorTable_Offset;
	PixelFormat (*_PixelFormatIndexedColorInterface_GetColorTablePixelFormat) (const maxon::GenericComponent* this_);
	maxon::Int _PixelFormatIndexedColorInterface_GetColorTablePixelFormat_Offset;
	Int (*_PixelFormatIndexedColorInterface_GetColorTableSize) (const maxon::GenericComponent* this_);
	maxon::Int _PixelFormatIndexedColorInterface_GetColorTableSize_Offset;
	Result<void> (*_PixelFormatIndexedColorInterface_SetIndex) (maxon::GenericComponent* this_, Int idx, const ImageConstBuffer& srcPixelData);
	maxon::Int _PixelFormatIndexedColorInterface_SetIndex_Offset;
	Result<void> (*_PixelFormatIndexedColorInterface_GetIndex) (const maxon::GenericComponent* this_, Int idx, const ImageMutableBuffer& dstPixelData);
	maxon::Int _PixelFormatIndexedColorInterface_GetIndex_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, PixelFormatIndexedColorInterface, InitColorTable))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, PixelFormatIndexedColorInterface, InitColorTable), W, MTable>::type::_PixelFormatIndexedColorInterface_InitColorTable;
			_PixelFormatIndexedColorInterface_InitColorTable = reinterpret_cast<const decltype(_PixelFormatIndexedColorInterface_InitColorTable)&>(ptr);
			_PixelFormatIndexedColorInterface_InitColorTable_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, PixelFormatIndexedColorInterface, GetColorTablePixelFormat))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, PixelFormatIndexedColorInterface, GetColorTablePixelFormat), W, MTable>::type::_PixelFormatIndexedColorInterface_GetColorTablePixelFormat;
			_PixelFormatIndexedColorInterface_GetColorTablePixelFormat = reinterpret_cast<const decltype(_PixelFormatIndexedColorInterface_GetColorTablePixelFormat)&>(ptr);
			_PixelFormatIndexedColorInterface_GetColorTablePixelFormat_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, PixelFormatIndexedColorInterface, GetColorTableSize))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, PixelFormatIndexedColorInterface, GetColorTableSize), W, MTable>::type::_PixelFormatIndexedColorInterface_GetColorTableSize;
			_PixelFormatIndexedColorInterface_GetColorTableSize = reinterpret_cast<const decltype(_PixelFormatIndexedColorInterface_GetColorTableSize)&>(ptr);
			_PixelFormatIndexedColorInterface_GetColorTableSize_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, PixelFormatIndexedColorInterface, SetIndex))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, PixelFormatIndexedColorInterface, SetIndex), W, MTable>::type::_PixelFormatIndexedColorInterface_SetIndex;
			_PixelFormatIndexedColorInterface_SetIndex = reinterpret_cast<const decltype(_PixelFormatIndexedColorInterface_SetIndex)&>(ptr);
			_PixelFormatIndexedColorInterface_SetIndex_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, PixelFormatIndexedColorInterface, GetIndex))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, PixelFormatIndexedColorInterface, GetIndex), W, MTable>::type::_PixelFormatIndexedColorInterface_GetIndex;
			_PixelFormatIndexedColorInterface_GetIndex = reinterpret_cast<const decltype(_PixelFormatIndexedColorInterface_GetIndex)&>(ptr);
			_PixelFormatIndexedColorInterface_GetIndex_Offset = offset;
		}
	}
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset)
	{
		if (!W::Implementation::PROXY && (!PixelFormatInterface::MTable::template InitWithBases<W>(info, offset))) return false;
		MTable* vt = (MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, _interface); if (!vt) return false;
		vt->Init<W>(offset); return true;
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<PixelFormatIndexedColorInterface, typename PixelFormatInterface::MTable::template CombinedMTable<S>>;
	PRIVATE_MAXON_COMPBASE(PixelFormatIndexedColorInterface);
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct PixelFormatIndexedColorInterface::Hxx2
{
	template <typename S> class Wrapper : public PixelFormatInterface::Hxx2::template Wrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetColorTablePixelFormat);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetColorTableSize);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetIndex);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(InitColorTable);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(SetIndex);
	static Result<void> _PixelFormatIndexedColorInterface_InitColorTable(maxon::GenericComponent* this_, Int count, const PixelFormat& srcFormatPtr) { return ((typename S::Implementation*) this_)->InitColorTable(count, srcFormatPtr); }
	static PixelFormat _PixelFormatIndexedColorInterface_GetColorTablePixelFormat(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetColorTablePixelFormat(); }
	static Int _PixelFormatIndexedColorInterface_GetColorTableSize(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetColorTableSize(); }
	static Result<void> _PixelFormatIndexedColorInterface_SetIndex(maxon::GenericComponent* this_, Int idx, const ImageConstBuffer& srcPixelData) { return ((typename S::Implementation*) this_)->SetIndex(idx, srcPixelData); }
	static Result<void> _PixelFormatIndexedColorInterface_GetIndex(const maxon::GenericComponent* this_, Int idx, const ImageMutableBuffer& dstPixelData) { return ((const typename S::Implementation*) this_)->GetIndex(idx, dstPixelData); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatIndexedColorInterface::InitColorTable(Int count, const PixelFormat& srcFormatPtr) -> Result<void>
{
	const PixelFormatIndexedColorInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(PixelFormatIndexedColorInterface, this); return mt_._PixelFormatIndexedColorInterface_InitColorTable((maxon::GenericComponent*) this + mt_._PixelFormatIndexedColorInterface_InitColorTable_Offset, count, srcFormatPtr);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatIndexedColorInterface::GetColorTablePixelFormat() const -> PixelFormat
{
	const PixelFormatIndexedColorInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(PixelFormatIndexedColorInterface, this); return mt_._PixelFormatIndexedColorInterface_GetColorTablePixelFormat((const maxon::GenericComponent*) this + mt_._PixelFormatIndexedColorInterface_GetColorTablePixelFormat_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatIndexedColorInterface::GetColorTableSize() const -> Int
{
	const PixelFormatIndexedColorInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(PixelFormatIndexedColorInterface, this); return mt_._PixelFormatIndexedColorInterface_GetColorTableSize((const maxon::GenericComponent*) this + mt_._PixelFormatIndexedColorInterface_GetColorTableSize_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatIndexedColorInterface::SetIndex(Int idx, const ImageConstBuffer& srcPixelData) -> Result<void>
{
	const PixelFormatIndexedColorInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(PixelFormatIndexedColorInterface, this); return mt_._PixelFormatIndexedColorInterface_SetIndex((maxon::GenericComponent*) this + mt_._PixelFormatIndexedColorInterface_SetIndex_Offset, idx, srcPixelData);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatIndexedColorInterface::GetIndex(Int idx, const ImageMutableBuffer& dstPixelData) const -> Result<void>
{
	const PixelFormatIndexedColorInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(PixelFormatIndexedColorInterface, this); return mt_._PixelFormatIndexedColorInterface_GetIndex((const maxon::GenericComponent*) this + mt_._PixelFormatIndexedColorInterface_GetIndex_Offset, idx, dstPixelData);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatIndexedColorInterface::Hxx1::ReferenceFunctionsImpl<S>::InitColorTable(Int count, const PixelFormat& srcFormatPtr) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); PixelFormatIndexedColorInterface* o_ = (PixelFormatIndexedColorInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(PixelFormatIndexedColorInterface, o_, PixelFormatIndexedColorInterface_InitColorTable) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<PixelFormatIndexedColorInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<PixelFormatIndexedColorInterface>() : PRIVATE_MAXON_VTABLE(PixelFormatIndexedColorInterface, o_); 
	return (mt_._PixelFormatIndexedColorInterface_InitColorTable(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._PixelFormatIndexedColorInterface_InitColorTable_Offset, count, srcFormatPtr));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatIndexedColorInterface::Hxx1::COWReferenceFunctionsImpl<S>::InitColorTable(Int count, const PixelFormat& srcFormatPtr) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); PixelFormatIndexedColorInterface* o_ = (PixelFormatIndexedColorInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(PixelFormatIndexedColorInterface, o_, PixelFormatIndexedColorInterface_InitColorTable) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<PixelFormatIndexedColorInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<PixelFormatIndexedColorInterface>() : PRIVATE_MAXON_VTABLE(PixelFormatIndexedColorInterface, o_); 
	return (mt_._PixelFormatIndexedColorInterface_InitColorTable(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._PixelFormatIndexedColorInterface_InitColorTable_Offset, count, srcFormatPtr));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatIndexedColorInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetColorTablePixelFormat() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<PixelFormat>, PixelFormat>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<PixelFormat>, PixelFormat>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const PixelFormatIndexedColorInterface* o_ = (const PixelFormatIndexedColorInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = PixelFormatIndexedColorInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<PixelFormat>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(PixelFormatIndexedColorInterface, o_, PixelFormatIndexedColorInterface_GetColorTablePixelFormat) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<PixelFormatIndexedColorInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<PixelFormatIndexedColorInterface>() : PRIVATE_MAXON_VTABLE(PixelFormatIndexedColorInterface, o_); 
	return (mt_._PixelFormatIndexedColorInterface_GetColorTablePixelFormat(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._PixelFormatIndexedColorInterface_GetColorTablePixelFormat_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatIndexedColorInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetColorTableSize() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const PixelFormatIndexedColorInterface* o_ = (const PixelFormatIndexedColorInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = PixelFormatIndexedColorInterface::NullValuePtr(); if (!o_) return 0; } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(PixelFormatIndexedColorInterface, o_, PixelFormatIndexedColorInterface_GetColorTableSize) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<PixelFormatIndexedColorInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<PixelFormatIndexedColorInterface>() : PRIVATE_MAXON_VTABLE(PixelFormatIndexedColorInterface, o_); 
	return (mt_._PixelFormatIndexedColorInterface_GetColorTableSize(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._PixelFormatIndexedColorInterface_GetColorTableSize_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatIndexedColorInterface::Hxx1::ReferenceFunctionsImpl<S>::SetIndex(Int idx, const ImageConstBuffer& srcPixelData) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); PixelFormatIndexedColorInterface* o_ = (PixelFormatIndexedColorInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(PixelFormatIndexedColorInterface, o_, PixelFormatIndexedColorInterface_SetIndex) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<PixelFormatIndexedColorInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<PixelFormatIndexedColorInterface>() : PRIVATE_MAXON_VTABLE(PixelFormatIndexedColorInterface, o_); 
	return (mt_._PixelFormatIndexedColorInterface_SetIndex(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._PixelFormatIndexedColorInterface_SetIndex_Offset, idx, srcPixelData));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatIndexedColorInterface::Hxx1::COWReferenceFunctionsImpl<S>::SetIndex(Int idx, const ImageConstBuffer& srcPixelData) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); PixelFormatIndexedColorInterface* o_ = (PixelFormatIndexedColorInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(PixelFormatIndexedColorInterface, o_, PixelFormatIndexedColorInterface_SetIndex) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<PixelFormatIndexedColorInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<PixelFormatIndexedColorInterface>() : PRIVATE_MAXON_VTABLE(PixelFormatIndexedColorInterface, o_); 
	return (mt_._PixelFormatIndexedColorInterface_SetIndex(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._PixelFormatIndexedColorInterface_SetIndex_Offset, idx, srcPixelData));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatIndexedColorInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetIndex(Int idx, const ImageMutableBuffer& dstPixelData) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const PixelFormatIndexedColorInterface* o_ = (const PixelFormatIndexedColorInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = PixelFormatIndexedColorInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(PixelFormatIndexedColorInterface, o_, PixelFormatIndexedColorInterface_GetIndex) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<PixelFormatIndexedColorInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<PixelFormatIndexedColorInterface>() : PRIVATE_MAXON_VTABLE(PixelFormatIndexedColorInterface, o_); 
	return (mt_._PixelFormatIndexedColorInterface_GetIndex(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._PixelFormatIndexedColorInterface_GetIndex_Offset, idx, dstPixelData));
}
auto PixelFormatIndexedColorInterface::GetPtr() -> Ptr { return Ptr(this); }
auto PixelFormatIndexedColorInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_PixelFormatIndexedColorInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_PixelFormatIndexedColorInterface() { new (s_ui_maxon_PixelFormatIndexedColorInterface) maxon::EntityUse(PixelFormatIndexedColorInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/gfx_image_pixelformat.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_PixelFormatIndexedColorInterface(PixelFormatIndexedColorInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/gfx_image_pixelformat.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif

struct PixelFormatsInterface::MTable
{
	static MTable _instance;
	static MTable _unresolvedInstance;
	static const maxon::Char* const _ids;
	static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl);
	static const maxon::NULL_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = false;
	Result<PixelFormat> (*_PixelFormatsInterface_FindOrCreatePixelFormat) (const Block<const ImageChannel>& channels);
	template <typename IMPL> void Init()
	{
		_PixelFormatsInterface_FindOrCreatePixelFormat = &IMPL::_PixelFormatsInterface_FindOrCreatePixelFormat;
	}
};

struct PixelFormatsInterface::Hxx2
{
	class Unresolved;
	template <typename C> class Wrapper
	{
	public:
	static Result<PixelFormat> _PixelFormatsInterface_FindOrCreatePixelFormat(const Block<const ImageChannel>& channels) { return C::FindOrCreatePixelFormat(channels); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatsInterface::FindOrCreatePixelFormat(const Block<const ImageChannel>& channels) -> Result<PixelFormat>
{
	return MTable::_instance._PixelFormatsInterface_FindOrCreatePixelFormat(channels);
}

#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
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

