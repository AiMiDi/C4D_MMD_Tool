
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1
/// @cond INTERNAL

/// @endcond


struct ColorProfileInterface::MTable
{
	static MTable _instance;
	static MTable _unresolvedInstance;
	static const maxon::Char* const _ids;
	static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl);
	static const maxon::NULL_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = true;
	void (*_ColorProfileInterface_Free) (const ColorProfileInterface* object);
	ColorProfileInterface* (*_ColorProfileInterface_Alloc) (const maxon::SourceLocation& allocLocation);
	ColorProfileInterface* (*_ColorProfileInterface_Alloc_1) (const maxon::SourceLocation& allocLocation, const ColorProfileInterface& object);
	Bool (*_ColorProfileInterface_IsEqual) (const ColorProfileInterface* this_, const ColorProfileInterface* other);
	Result<ColorProfile> (*_ColorProfileInterface_OpenProfileFromFile) (const Url& fn);
	Result<ColorProfile> (*_ColorProfileInterface_OpenProfileFromMemory) (const Block<const Byte>& mem);
	Result<void> (*_ColorProfileInterface_WriteProfileToMemory) (const ColorProfileInterface* this_, WritableArrayInterface<Char>& mem);
	Result<void> (*_ColorProfileInterface_WriteProfileToFile) (const ColorProfileInterface* this_, const Url& fn);
	String (*_ColorProfileInterface_GetInfo) (const ColorProfileInterface* this_, COLORPROFILEINFO info);
	UInt32 (*_ColorProfileInterface_GetCrc) (const ColorProfileInterface* this_);
	Bool (*_ColorProfileInterface_HasProfile) (const ColorProfileInterface* this_);
	Bool (*_ColorProfileInterface_CheckCompatiblePixelFormat) (const ColorProfileInterface* this_, const PixelFormat& pixelFormat);
	Bool (*_ColorProfileInterface_IsMonitorProfileMode) (const ColorProfileInterface* this_);
	UInt (*_ColorProfileInterface_GetHashCode) (const ColorProfileInterface* this_);
	ColorSpace (*_ColorProfileInterface_GetColorSpace) (const ColorProfileInterface* this_);
	String (*_ColorProfileInterface_ToString) (const ColorProfileInterface* this_, const FormatStatement* formatStatement);
/// @cond INTERNAL

	Bool (*_ColorProfileInterface_SetMonitorProfileMode) (ColorProfileInterface* this_, Bool on);
	Result<void> (*_ColorProfileInterface_DescribeIO) (const DataSerializeInterface& stream);
/// @endcond

	template <typename IMPL> void Init()
	{
		_ColorProfileInterface_Free = &IMPL::_ColorProfileInterface_Free;
		_ColorProfileInterface_Alloc = &IMPL::_ColorProfileInterface_Alloc;
		_ColorProfileInterface_Alloc_1 = &IMPL::_ColorProfileInterface_Alloc_1;
		_ColorProfileInterface_IsEqual = &IMPL::_ColorProfileInterface_IsEqual;
		_ColorProfileInterface_OpenProfileFromFile = &IMPL::_ColorProfileInterface_OpenProfileFromFile;
		_ColorProfileInterface_OpenProfileFromMemory = &IMPL::_ColorProfileInterface_OpenProfileFromMemory;
		_ColorProfileInterface_WriteProfileToMemory = &IMPL::_ColorProfileInterface_WriteProfileToMemory;
		_ColorProfileInterface_WriteProfileToFile = &IMPL::_ColorProfileInterface_WriteProfileToFile;
		_ColorProfileInterface_GetInfo = &IMPL::_ColorProfileInterface_GetInfo;
		_ColorProfileInterface_GetCrc = &IMPL::_ColorProfileInterface_GetCrc;
		_ColorProfileInterface_HasProfile = &IMPL::_ColorProfileInterface_HasProfile;
		_ColorProfileInterface_CheckCompatiblePixelFormat = &IMPL::_ColorProfileInterface_CheckCompatiblePixelFormat;
		_ColorProfileInterface_IsMonitorProfileMode = &IMPL::_ColorProfileInterface_IsMonitorProfileMode;
		_ColorProfileInterface_GetHashCode = &IMPL::_ColorProfileInterface_GetHashCode;
		_ColorProfileInterface_GetColorSpace = &IMPL::_ColorProfileInterface_GetColorSpace;
		_ColorProfileInterface_ToString = &IMPL::_ColorProfileInterface_ToString;
/// @cond INTERNAL

		_ColorProfileInterface_SetMonitorProfileMode = &IMPL::_ColorProfileInterface_SetMonitorProfileMode;
		_ColorProfileInterface_DescribeIO = &IMPL::_ColorProfileInterface_DescribeIO;
/// @endcond

	}
};

struct ColorProfileInterface::Hxx2
{
	class Unresolved;
	template <typename C> class Wrapper
	{
	public:
	static void _ColorProfileInterface_Free(const ColorProfileInterface* object) { return C::Free(object); }
	static ColorProfileInterface* _ColorProfileInterface_Alloc(const maxon::SourceLocation& allocLocation) { return C::Alloc(allocLocation); }
	static ColorProfileInterface* _ColorProfileInterface_Alloc_1(const maxon::SourceLocation& allocLocation, const ColorProfileInterface& object) { return C::Alloc(allocLocation, ((const C&) object)); }
	static Bool _ColorProfileInterface_IsEqual(const ColorProfileInterface* this_, const ColorProfileInterface* other) { return ((const C*) this_)->IsEqual(other); }
	static Result<ColorProfile> _ColorProfileInterface_OpenProfileFromFile(const Url& fn) { return C::OpenProfileFromFile(fn); }
	static Result<ColorProfile> _ColorProfileInterface_OpenProfileFromMemory(const Block<const Byte>& mem) { return C::OpenProfileFromMemory(mem); }
	static Result<void> _ColorProfileInterface_WriteProfileToMemory(const ColorProfileInterface* this_, WritableArrayInterface<Char>& mem) { return ((const C*) this_)->WriteProfileToMemory(mem); }
	static Result<void> _ColorProfileInterface_WriteProfileToFile(const ColorProfileInterface* this_, const Url& fn) { return ((const C*) this_)->WriteProfileToFile(fn); }
	static String _ColorProfileInterface_GetInfo(const ColorProfileInterface* this_, COLORPROFILEINFO info) { return ((const C*) this_)->GetInfo(info); }
	static UInt32 _ColorProfileInterface_GetCrc(const ColorProfileInterface* this_) { return ((const C*) this_)->GetCrc(); }
	static Bool _ColorProfileInterface_HasProfile(const ColorProfileInterface* this_) { return ((const C*) this_)->HasProfile(); }
	static Bool _ColorProfileInterface_CheckCompatiblePixelFormat(const ColorProfileInterface* this_, const PixelFormat& pixelFormat) { return ((const C*) this_)->CheckCompatiblePixelFormat(pixelFormat); }
	static Bool _ColorProfileInterface_IsMonitorProfileMode(const ColorProfileInterface* this_) { return ((const C*) this_)->IsMonitorProfileMode(); }
	static UInt _ColorProfileInterface_GetHashCode(const ColorProfileInterface* this_) { return ((const C*) this_)->GetHashCode(); }
	static ColorSpace _ColorProfileInterface_GetColorSpace(const ColorProfileInterface* this_) { return ((const C*) this_)->GetColorSpace(); }
	static String _ColorProfileInterface_ToString(const ColorProfileInterface* this_, const FormatStatement* formatStatement) { return ((const C*) this_)->ToString(formatStatement); }
/// @cond INTERNAL

	static Bool _ColorProfileInterface_SetMonitorProfileMode(ColorProfileInterface* this_, Bool on) { return ((C*) this_)->SetMonitorProfileMode(on); }
	static Result<void> _ColorProfileInterface_DescribeIO(const DataSerializeInterface& stream) { return C::DescribeIO(stream); }
/// @endcond

	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto ColorProfileInterface::Free(const ColorProfileInterface* object) -> void
{
	return MTable::_instance._ColorProfileInterface_Free(object);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ColorProfileInterface::Alloc(const maxon::SourceLocation& allocLocation) -> ColorProfileInterface*
{
	return MTable::_instance._ColorProfileInterface_Alloc(allocLocation);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ColorProfileInterface::Alloc(const maxon::SourceLocation& allocLocation, const ColorProfileInterface& object) -> ColorProfileInterface*
{
	return MTable::_instance._ColorProfileInterface_Alloc_1(allocLocation, object);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ColorProfileInterface::IsEqual(const ColorProfileInterface* other) const -> Bool
{
	return MTable::_instance._ColorProfileInterface_IsEqual(this, other);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ColorProfileInterface::OpenProfileFromFile(const Url& fn) -> Result<ColorProfile>
{
	return MTable::_instance._ColorProfileInterface_OpenProfileFromFile(fn);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ColorProfileInterface::OpenProfileFromMemory(const Block<const Byte>& mem) -> Result<ColorProfile>
{
	return MTable::_instance._ColorProfileInterface_OpenProfileFromMemory(mem);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ColorProfileInterface::WriteProfileToMemory(WritableArrayInterface<Char>& mem) const -> Result<void>
{
	return MTable::_instance._ColorProfileInterface_WriteProfileToMemory(this, mem);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ColorProfileInterface::WriteProfileToFile(const Url& fn) const -> Result<void>
{
	return MTable::_instance._ColorProfileInterface_WriteProfileToFile(this, fn);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ColorProfileInterface::GetInfo(COLORPROFILEINFO info) const -> String
{
	return MTable::_instance._ColorProfileInterface_GetInfo(this, info);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ColorProfileInterface::GetCrc() const -> UInt32
{
	return MTable::_instance._ColorProfileInterface_GetCrc(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ColorProfileInterface::HasProfile() const -> Bool
{
	return MTable::_instance._ColorProfileInterface_HasProfile(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ColorProfileInterface::CheckCompatiblePixelFormat(const PixelFormat& pixelFormat) const -> Bool
{
	return MTable::_instance._ColorProfileInterface_CheckCompatiblePixelFormat(this, pixelFormat);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ColorProfileInterface::IsMonitorProfileMode() const -> Bool
{
	return MTable::_instance._ColorProfileInterface_IsMonitorProfileMode(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ColorProfileInterface::GetHashCode() const -> UInt
{
	return MTable::_instance._ColorProfileInterface_GetHashCode(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ColorProfileInterface::GetColorSpace() const -> ColorSpace
{
	return MTable::_instance._ColorProfileInterface_GetColorSpace(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ColorProfileInterface::ToString(const FormatStatement* formatStatement) const -> String
{
	return MTable::_instance._ColorProfileInterface_ToString(this, formatStatement);
}
/// @cond INTERNAL

MAXON_ATTRIBUTE_FORCE_INLINE auto ColorProfileInterface::SetMonitorProfileMode(Bool on) -> Bool
{
	return MTable::_instance._ColorProfileInterface_SetMonitorProfileMode(this, on);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ColorProfileInterface::DescribeIO(const DataSerializeInterface& stream) -> Result<void>
{
	return MTable::_instance._ColorProfileInterface_DescribeIO(stream);
}
/// @endcond


auto ColorProfileInterface::Hxx1::Reference::Create() -> maxon::ResultMemT<ColorProfile>
{
	ColorProfileInterface* res_ = ColorProfileInterface::Alloc(MAXON_SOURCE_LOCATION);
	return ColorProfile(maxon::ForwardResultPtr<ColorProfileInterface>(res_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ColorProfileInterface::Hxx1::ConstReferenceFunctionsImpl<S>::IsEqual(const ColorProfileInterface* other) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ColorProfileInterface* o_ = (const ColorProfileInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ColorProfileInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (MTable::_instance._ColorProfileInterface_IsEqual(o_, other));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ColorProfileInterface::Hxx1::ConstReferenceFunctionsImpl<S>::OpenProfileFromFile(const Url& fn) -> Result<ColorProfile> { return (MTable::_instance._ColorProfileInterface_OpenProfileFromFile(fn)); }
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ColorProfileInterface::Hxx1::ConstReferenceFunctionsImpl<S>::OpenProfileFromMemory(const Block<const Byte>& mem) -> Result<ColorProfile> { return (MTable::_instance._ColorProfileInterface_OpenProfileFromMemory(mem)); }
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ColorProfileInterface::Hxx1::ConstReferenceFunctionsImpl<S>::WriteProfileToMemory(WritableArrayInterface<Char>& mem) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ColorProfileInterface* o_ = (const ColorProfileInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ColorProfileInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance._ColorProfileInterface_WriteProfileToMemory(o_, mem));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ColorProfileInterface::Hxx1::ConstReferenceFunctionsImpl<S>::WriteProfileToFile(const Url& fn) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ColorProfileInterface* o_ = (const ColorProfileInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ColorProfileInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance._ColorProfileInterface_WriteProfileToFile(o_, fn));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ColorProfileInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetInfo(COLORPROFILEINFO info) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ColorProfileInterface* o_ = (const ColorProfileInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ColorProfileInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (MTable::_instance._ColorProfileInterface_GetInfo(o_, info));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ColorProfileInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetCrc() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<UInt32>, UInt32>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<UInt32>, UInt32>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ColorProfileInterface* o_ = (const ColorProfileInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ColorProfileInterface::NullValuePtr(); if (!o_) return 0; } 
	return (MTable::_instance._ColorProfileInterface_GetCrc(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ColorProfileInterface::Hxx1::ConstReferenceFunctionsImpl<S>::HasProfile() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ColorProfileInterface* o_ = (const ColorProfileInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ColorProfileInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (MTable::_instance._ColorProfileInterface_HasProfile(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ColorProfileInterface::Hxx1::ConstReferenceFunctionsImpl<S>::CheckCompatiblePixelFormat(const PixelFormat& pixelFormat) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ColorProfileInterface* o_ = (const ColorProfileInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ColorProfileInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (MTable::_instance._ColorProfileInterface_CheckCompatiblePixelFormat(o_, pixelFormat));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ColorProfileInterface::Hxx1::ConstReferenceFunctionsImpl<S>::IsMonitorProfileMode() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ColorProfileInterface* o_ = (const ColorProfileInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ColorProfileInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (MTable::_instance._ColorProfileInterface_IsMonitorProfileMode(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ColorProfileInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetColorSpace() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<ColorSpace>, ColorSpace>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<ColorSpace>, ColorSpace>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ColorProfileInterface* o_ = (const ColorProfileInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ColorProfileInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<ColorSpace>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (MTable::_instance._ColorProfileInterface_GetColorSpace(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ColorProfileInterface::Hxx1::ConstReferenceFunctionsImpl<S>::ToString(const FormatStatement* formatStatement) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ColorProfileInterface* o_ = (const ColorProfileInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ColorProfileInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (MTable::_instance._ColorProfileInterface_ToString(o_, formatStatement));
}
/// @cond INTERNAL

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ColorProfileInterface::Hxx1::ReferenceFunctionsImpl<S>::SetMonitorProfileMode(Bool on) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ColorProfileInterface* o_ = (ColorProfileInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateLogNullptrError(false); } 
	return (MTable::_instance._ColorProfileInterface_SetMonitorProfileMode(o_, on));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ColorProfileInterface::Hxx1::COWReferenceFunctionsImpl<S>::SetMonitorProfileMode(Bool on) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Bool, maxon::Result<Bool>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Bool, maxon::Result<Bool>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ColorProfileInterface* o_ = (ColorProfileInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (MTable::_instance._ColorProfileInterface_SetMonitorProfileMode(o_, on));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ColorProfileInterface::Hxx1::ConstReferenceFunctionsImpl<S>::DescribeIO(const DataSerializeInterface& stream) -> Result<void> { return (MTable::_instance._ColorProfileInterface_DescribeIO(stream)); }
/// @endcond

#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_ColorProfileInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_ColorProfileInterface() { new (s_ui_maxon_ColorProfileInterface) maxon::EntityUse(ColorProfileInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/gfx_image_colorprofile.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_ColorProfileInterface(ColorProfileInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/gfx_image_colorprofile.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif

struct ColorProfileConvertInterface::MTable
{
	static MTable _instance;
	static MTable _unresolvedInstance;
	static const maxon::Char* const _ids;
	static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl);
	static const maxon::NULL_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = true;
	void (*_ColorProfileConvertInterface_Free) (const ColorProfileConvertInterface* object);
	Result<ColorProfileConvert> (*_ColorProfileConvertInterface_Init) (const PixelFormat& srcPixelFormat, const ColorProfile& srcProfile, const PixelFormat& dstPixelFormat, const ColorProfile& dstProfile, COLORCONVERSIONINTENT intent, COLORCONVERSIONFLAGS flags);
	Result<void> (*_ColorProfileConvertInterface_Convert) (const ColorProfileConvertInterface* this_, const ImageConstBuffer& src, const ImageMutableBuffer& dst, Int cnt);
	UInt (*_ColorProfileConvertInterface_GetHashCode) (const ColorProfileConvertInterface* this_);
	Result<PixelFormat> (*_ColorProfileConvertInterface_GetNearestNativeFormat) (const PixelFormat& format);
	template <typename IMPL> void Init()
	{
		_ColorProfileConvertInterface_Free = &IMPL::_ColorProfileConvertInterface_Free;
		_ColorProfileConvertInterface_Init = &IMPL::_ColorProfileConvertInterface_Init;
		_ColorProfileConvertInterface_Convert = &IMPL::_ColorProfileConvertInterface_Convert;
		_ColorProfileConvertInterface_GetHashCode = &IMPL::_ColorProfileConvertInterface_GetHashCode;
		_ColorProfileConvertInterface_GetNearestNativeFormat = &IMPL::_ColorProfileConvertInterface_GetNearestNativeFormat;
	}
};

struct ColorProfileConvertInterface::Hxx2
{
	class Unresolved;
	template <typename C> class Wrapper
	{
	public:
	static void _ColorProfileConvertInterface_Free(const ColorProfileConvertInterface* object) { return C::Free(object); }
	static Result<ColorProfileConvert> _ColorProfileConvertInterface_Init(const PixelFormat& srcPixelFormat, const ColorProfile& srcProfile, const PixelFormat& dstPixelFormat, const ColorProfile& dstProfile, COLORCONVERSIONINTENT intent, COLORCONVERSIONFLAGS flags) { return C::Init(srcPixelFormat, srcProfile, dstPixelFormat, dstProfile, intent, flags); }
	static Result<void> _ColorProfileConvertInterface_Convert(const ColorProfileConvertInterface* this_, const ImageConstBuffer& src, const ImageMutableBuffer& dst, Int cnt) { return ((const C*) this_)->Convert(src, dst, cnt); }
	static UInt _ColorProfileConvertInterface_GetHashCode(const ColorProfileConvertInterface* this_) { return ((const C*) this_)->GetHashCode(); }
	static Result<PixelFormat> _ColorProfileConvertInterface_GetNearestNativeFormat(const PixelFormat& format) { return C::GetNearestNativeFormat(format); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto ColorProfileConvertInterface::Free(const ColorProfileConvertInterface* object) -> void
{
	return MTable::_instance._ColorProfileConvertInterface_Free(object);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ColorProfileConvertInterface::Init(const PixelFormat& srcPixelFormat, const ColorProfile& srcProfile, const PixelFormat& dstPixelFormat, const ColorProfile& dstProfile, COLORCONVERSIONINTENT intent, COLORCONVERSIONFLAGS flags) -> Result<ColorProfileConvert>
{
	return MTable::_instance._ColorProfileConvertInterface_Init(srcPixelFormat, srcProfile, dstPixelFormat, dstProfile, intent, flags);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ColorProfileConvertInterface::Convert(const ImageConstBuffer& src, const ImageMutableBuffer& dst, Int cnt) const -> Result<void>
{
	return MTable::_instance._ColorProfileConvertInterface_Convert(this, src, dst, cnt);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ColorProfileConvertInterface::GetHashCode() const -> UInt
{
	return MTable::_instance._ColorProfileConvertInterface_GetHashCode(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ColorProfileConvertInterface::GetNearestNativeFormat(const PixelFormat& format) -> Result<PixelFormat>
{
	return MTable::_instance._ColorProfileConvertInterface_GetNearestNativeFormat(format);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ColorProfileConvertInterface::Hxx1::ConstReferenceFunctionsImpl<S>::Init(const PixelFormat& srcPixelFormat, const ColorProfile& srcProfile, const PixelFormat& dstPixelFormat, const ColorProfile& dstProfile, COLORCONVERSIONINTENT intent, COLORCONVERSIONFLAGS flags) -> Result<ColorProfileConvert> { return (MTable::_instance._ColorProfileConvertInterface_Init(srcPixelFormat, srcProfile, dstPixelFormat, dstProfile, intent, flags)); }
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ColorProfileConvertInterface::Hxx1::ConstReferenceFunctionsImpl<S>::Convert(const ImageConstBuffer& src, const ImageMutableBuffer& dst, Int cnt) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ColorProfileConvertInterface* o_ = (const ColorProfileConvertInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ColorProfileConvertInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance._ColorProfileConvertInterface_Convert(o_, src, dst, cnt));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ColorProfileConvertInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetNearestNativeFormat(const PixelFormat& format) -> Result<PixelFormat> { return (MTable::_instance._ColorProfileConvertInterface_GetNearestNativeFormat(format)); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_ColorProfileConvertInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_ColorProfileConvertInterface() { new (s_ui_maxon_ColorProfileConvertInterface) maxon::EntityUse(ColorProfileConvertInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/gfx_image_colorprofile.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_ColorProfileConvertInterface(ColorProfileConvertInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/gfx_image_colorprofile.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

