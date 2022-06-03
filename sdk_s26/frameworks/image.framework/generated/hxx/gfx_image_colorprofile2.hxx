
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1
#ifdef MAXON_TARGET_LINUX
#endif
constexpr const maxon::Char* ColorProfileInterface::PrivateGetCppName() { return "maxon::ColorProfile"; }
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
	void (*ColorProfileInterface_Free) (const ColorProfileInterface* object);
	ColorProfileInterface* (*ColorProfileInterface_Alloc) (const maxon::SourceLocation& allocLocation);
	ColorProfileInterface* (*ColorProfileInterface_Alloc_1) (const maxon::SourceLocation& allocLocation, const ColorProfileInterface& object);
	Bool (*ColorProfileInterface_IsEqual) (const ColorProfileInterface* this_, const ColorProfileInterface* other);
	Result<ColorProfile> (*ColorProfileInterface_OpenProfileFromFile) (const Url& fn);
	Result<ColorProfile> (*ColorProfileInterface_OpenProfileFromMemory) (const Block<const Byte>& mem);
	Result<ColorProfile> (*ColorProfileInterface_CreateProfile) (const OcioConfig& config, const CString& name);
	Result<ColorProfile> (*ColorProfileInterface_CreateProfile_1) (const OcioConfig& config, const CString& viewTransform, const CString& displayColorSpace);
	Result<void> (*ColorProfileInterface_WriteProfileToMemory) (const ColorProfileInterface* this_, WritableArrayInterface<Char>& mem);
	Result<void> (*ColorProfileInterface_WriteProfileToFile) (const ColorProfileInterface* this_, const Url& fn);
	String (*ColorProfileInterface_GetInfo) (const ColorProfileInterface* this_, COLORPROFILEINFO info);
	UInt32 (*ColorProfileInterface_GetCrc) (const ColorProfileInterface* this_);
	Bool (*ColorProfileInterface_HasProfile) (const ColorProfileInterface* this_);
	Bool (*ColorProfileInterface_CheckCompatiblePixelFormat) (const ColorProfileInterface* this_, const PixelFormat& pixelFormat);
	Bool (*ColorProfileInterface_IsMonitorProfileMode) (const ColorProfileInterface* this_);
	HashInt (*ColorProfileInterface_GetHashCode) (const ColorProfileInterface* this_);
	ColorSpace (*ColorProfileInterface_GetColorSpace) (const ColorProfileInterface* this_);
	String (*ColorProfileInterface_ToString) (const ColorProfileInterface* this_, const FormatStatement* formatStatement);
/// @cond INTERNAL

	Bool (*ColorProfileInterface_SetMonitorProfileMode) (ColorProfileInterface* this_, Bool on);
	Result<void> (*ColorProfileInterface_DescribeIO) (const DataSerializeInterface& stream);
/// @endcond

	template <typename IMPL> void Init()
	{
		ColorProfileInterface_Free = &IMPL::ColorProfileInterface_Free;
		ColorProfileInterface_Alloc = &IMPL::ColorProfileInterface_Alloc;
		ColorProfileInterface_Alloc_1 = &IMPL::ColorProfileInterface_Alloc_1;
		ColorProfileInterface_IsEqual = &IMPL::ColorProfileInterface_IsEqual;
		ColorProfileInterface_OpenProfileFromFile = &IMPL::ColorProfileInterface_OpenProfileFromFile;
		ColorProfileInterface_OpenProfileFromMemory = &IMPL::ColorProfileInterface_OpenProfileFromMemory;
		ColorProfileInterface_CreateProfile = &IMPL::ColorProfileInterface_CreateProfile;
		ColorProfileInterface_CreateProfile_1 = &IMPL::ColorProfileInterface_CreateProfile_1;
		ColorProfileInterface_WriteProfileToMemory = &IMPL::ColorProfileInterface_WriteProfileToMemory;
		ColorProfileInterface_WriteProfileToFile = &IMPL::ColorProfileInterface_WriteProfileToFile;
		ColorProfileInterface_GetInfo = &IMPL::ColorProfileInterface_GetInfo;
		ColorProfileInterface_GetCrc = &IMPL::ColorProfileInterface_GetCrc;
		ColorProfileInterface_HasProfile = &IMPL::ColorProfileInterface_HasProfile;
		ColorProfileInterface_CheckCompatiblePixelFormat = &IMPL::ColorProfileInterface_CheckCompatiblePixelFormat;
		ColorProfileInterface_IsMonitorProfileMode = &IMPL::ColorProfileInterface_IsMonitorProfileMode;
		ColorProfileInterface_GetHashCode = &IMPL::ColorProfileInterface_GetHashCode;
		ColorProfileInterface_GetColorSpace = &IMPL::ColorProfileInterface_GetColorSpace;
		ColorProfileInterface_ToString = &IMPL::ColorProfileInterface_ToString;
/// @cond INTERNAL

		ColorProfileInterface_SetMonitorProfileMode = &IMPL::ColorProfileInterface_SetMonitorProfileMode;
		ColorProfileInterface_DescribeIO = &IMPL::ColorProfileInterface_DescribeIO;
/// @endcond

	}
};

struct ColorProfileInterface::Hxx2
{
	class Unresolved;
	template <typename C> class Wrapper
	{
	public:
		static void ColorProfileInterface_Free(const ColorProfileInterface* object) { return C::Free(object); }
		static ColorProfileInterface* ColorProfileInterface_Alloc(const maxon::SourceLocation& allocLocation) { return C::Alloc(allocLocation); }
		static ColorProfileInterface* ColorProfileInterface_Alloc_1(const maxon::SourceLocation& allocLocation, const ColorProfileInterface& object) { return C::Alloc(allocLocation, ((const C&) object)); }
		static Bool ColorProfileInterface_IsEqual(const ColorProfileInterface* this_, const ColorProfileInterface* other) { return C::Get(this_)->IsEqual(other); }
		static Result<ColorProfile> ColorProfileInterface_OpenProfileFromFile(const Url& fn) { return C::OpenProfileFromFile(fn); }
		static Result<ColorProfile> ColorProfileInterface_OpenProfileFromMemory(const Block<const Byte>& mem) { return C::OpenProfileFromMemory(mem); }
		static Result<ColorProfile> ColorProfileInterface_CreateProfile(const OcioConfig& config, const CString& name) { return C::CreateProfile(config, name); }
		static Result<ColorProfile> ColorProfileInterface_CreateProfile_1(const OcioConfig& config, const CString& viewTransform, const CString& displayColorSpace) { return C::CreateProfile(config, viewTransform, displayColorSpace); }
		static Result<void> ColorProfileInterface_WriteProfileToMemory(const ColorProfileInterface* this_, WritableArrayInterface<Char>& mem) { return C::Get(this_)->WriteProfileToMemory(mem); }
		static Result<void> ColorProfileInterface_WriteProfileToFile(const ColorProfileInterface* this_, const Url& fn) { return C::Get(this_)->WriteProfileToFile(fn); }
		static String ColorProfileInterface_GetInfo(const ColorProfileInterface* this_, COLORPROFILEINFO info) { return C::Get(this_)->GetInfo(info); }
		static UInt32 ColorProfileInterface_GetCrc(const ColorProfileInterface* this_) { return C::Get(this_)->GetCrc(); }
		static Bool ColorProfileInterface_HasProfile(const ColorProfileInterface* this_) { return C::Get(this_)->HasProfile(); }
		static Bool ColorProfileInterface_CheckCompatiblePixelFormat(const ColorProfileInterface* this_, const PixelFormat& pixelFormat) { return C::Get(this_)->CheckCompatiblePixelFormat(pixelFormat); }
		static Bool ColorProfileInterface_IsMonitorProfileMode(const ColorProfileInterface* this_) { return C::Get(this_)->IsMonitorProfileMode(); }
		static HashInt ColorProfileInterface_GetHashCode(const ColorProfileInterface* this_) { return C::Get(this_)->GetHashCode(); }
		static ColorSpace ColorProfileInterface_GetColorSpace(const ColorProfileInterface* this_) { return C::Get(this_)->GetColorSpace(); }
		static String ColorProfileInterface_ToString(const ColorProfileInterface* this_, const FormatStatement* formatStatement) { return C::Get(this_)->ToString(formatStatement); }
/// @cond INTERNAL

		static Bool ColorProfileInterface_SetMonitorProfileMode(ColorProfileInterface* this_, Bool on) { return C::Get(this_)->SetMonitorProfileMode(on); }
		static Result<void> ColorProfileInterface_DescribeIO(const DataSerializeInterface& stream) { return C::DescribeIO(stream); }
/// @endcond

	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto ColorProfileInterface::Free(const ColorProfileInterface* object) -> void
{
	return MTable::_instance.ColorProfileInterface_Free(object);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ColorProfileInterface::Alloc(const maxon::SourceLocation& allocLocation) -> ColorProfileInterface*
{
	return MTable::_instance.ColorProfileInterface_Alloc(allocLocation);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ColorProfileInterface::Alloc(const maxon::SourceLocation& allocLocation, const ColorProfileInterface& object) -> ColorProfileInterface*
{
	return MTable::_instance.ColorProfileInterface_Alloc_1(allocLocation, object);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ColorProfileInterface::IsEqual(const ColorProfileInterface* other) const -> Bool
{
	return MTable::_instance.ColorProfileInterface_IsEqual(this, other);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ColorProfileInterface::OpenProfileFromFile(const Url& fn) -> Result<ColorProfile>
{
	return MTable::_instance.ColorProfileInterface_OpenProfileFromFile(fn);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ColorProfileInterface::OpenProfileFromMemory(const Block<const Byte>& mem) -> Result<ColorProfile>
{
	return MTable::_instance.ColorProfileInterface_OpenProfileFromMemory(mem);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ColorProfileInterface::CreateProfile(const OcioConfig& config, const CString& name) -> Result<ColorProfile>
{
	return MTable::_instance.ColorProfileInterface_CreateProfile(config, name);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ColorProfileInterface::CreateProfile(const OcioConfig& config, const CString& viewTransform, const CString& displayColorSpace) -> Result<ColorProfile>
{
	return MTable::_instance.ColorProfileInterface_CreateProfile_1(config, viewTransform, displayColorSpace);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ColorProfileInterface::WriteProfileToMemory(WritableArrayInterface<Char>& mem) const -> Result<void>
{
	return MTable::_instance.ColorProfileInterface_WriteProfileToMemory(this, mem);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ColorProfileInterface::WriteProfileToFile(const Url& fn) const -> Result<void>
{
	return MTable::_instance.ColorProfileInterface_WriteProfileToFile(this, fn);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ColorProfileInterface::GetInfo(COLORPROFILEINFO info) const -> String
{
	return MTable::_instance.ColorProfileInterface_GetInfo(this, info);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ColorProfileInterface::GetCrc() const -> UInt32
{
	return MTable::_instance.ColorProfileInterface_GetCrc(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ColorProfileInterface::HasProfile() const -> Bool
{
	return MTable::_instance.ColorProfileInterface_HasProfile(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ColorProfileInterface::CheckCompatiblePixelFormat(const PixelFormat& pixelFormat) const -> Bool
{
	return MTable::_instance.ColorProfileInterface_CheckCompatiblePixelFormat(this, pixelFormat);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ColorProfileInterface::IsMonitorProfileMode() const -> Bool
{
	return MTable::_instance.ColorProfileInterface_IsMonitorProfileMode(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ColorProfileInterface::GetHashCode() const -> HashInt
{
	return MTable::_instance.ColorProfileInterface_GetHashCode(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ColorProfileInterface::GetColorSpace() const -> ColorSpace
{
	return MTable::_instance.ColorProfileInterface_GetColorSpace(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ColorProfileInterface::ToString(const FormatStatement* formatStatement) const -> String
{
	return MTable::_instance.ColorProfileInterface_ToString(this, formatStatement);
}
/// @cond INTERNAL

MAXON_ATTRIBUTE_FORCE_INLINE auto ColorProfileInterface::SetMonitorProfileMode(Bool on) -> Bool
{
	return MTable::_instance.ColorProfileInterface_SetMonitorProfileMode(this, on);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ColorProfileInterface::DescribeIO(const DataSerializeInterface& stream) -> Result<void>
{
	return MTable::_instance.ColorProfileInterface_DescribeIO(stream);
}
/// @endcond


auto ColorProfileInterface::Hxx1::Reference::Create() -> maxon::ResultMemT<ColorProfile>
{
	ColorProfileInterface* res_ = ColorProfileInterface::Alloc(MAXON_SOURCE_LOCATION);
	return ColorProfile(maxon::ForwardResultPtr<ColorProfileInterface>(res_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ColorProfileInterface::Hxx1::ConstFn<S>::IsEqual(const ColorProfileInterface* other) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ColorProfileInterface* o_ = (const ColorProfileInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ColorProfileInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (MTable::_instance.ColorProfileInterface_IsEqual(o_, other));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ColorProfileInterface::Hxx1::ConstFn<S>::OpenProfileFromFile(const Url& fn) -> Result<ColorProfile>
{
	return (MTable::_instance.ColorProfileInterface_OpenProfileFromFile(fn));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ColorProfileInterface::Hxx1::ConstFn<S>::OpenProfileFromMemory(const Block<const Byte>& mem) -> Result<ColorProfile>
{
	return (MTable::_instance.ColorProfileInterface_OpenProfileFromMemory(mem));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ColorProfileInterface::Hxx1::ConstFn<S>::CreateProfile(const OcioConfig& config, const CString& name) -> Result<ColorProfile>
{
	return (MTable::_instance.ColorProfileInterface_CreateProfile(config, name));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ColorProfileInterface::Hxx1::ConstFn<S>::CreateProfile(const OcioConfig& config, const CString& viewTransform, const CString& displayColorSpace) -> Result<ColorProfile>
{
	return (MTable::_instance.ColorProfileInterface_CreateProfile_1(config, viewTransform, displayColorSpace));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ColorProfileInterface::Hxx1::ConstFn<S>::WriteProfileToMemory(WritableArrayInterface<Char>& mem) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ColorProfileInterface* o_ = (const ColorProfileInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ColorProfileInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.ColorProfileInterface_WriteProfileToMemory(o_, mem));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ColorProfileInterface::Hxx1::ConstFn<S>::WriteProfileToFile(const Url& fn) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ColorProfileInterface* o_ = (const ColorProfileInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ColorProfileInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.ColorProfileInterface_WriteProfileToFile(o_, fn));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ColorProfileInterface::Hxx1::ConstFn<S>::GetInfo(COLORPROFILEINFO info) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ColorProfileInterface* o_ = (const ColorProfileInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ColorProfileInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (MTable::_instance.ColorProfileInterface_GetInfo(o_, info));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ColorProfileInterface::Hxx1::ConstFn<S>::GetCrc() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<UInt32>, UInt32>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<UInt32>, UInt32>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ColorProfileInterface* o_ = (const ColorProfileInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ColorProfileInterface::NullValuePtr(); if (!o_) return 0; } 
	return (MTable::_instance.ColorProfileInterface_GetCrc(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ColorProfileInterface::Hxx1::ConstFn<S>::HasProfile() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ColorProfileInterface* o_ = (const ColorProfileInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ColorProfileInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (MTable::_instance.ColorProfileInterface_HasProfile(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ColorProfileInterface::Hxx1::ConstFn<S>::CheckCompatiblePixelFormat(const PixelFormat& pixelFormat) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ColorProfileInterface* o_ = (const ColorProfileInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ColorProfileInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (MTable::_instance.ColorProfileInterface_CheckCompatiblePixelFormat(o_, pixelFormat));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ColorProfileInterface::Hxx1::ConstFn<S>::IsMonitorProfileMode() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ColorProfileInterface* o_ = (const ColorProfileInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ColorProfileInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (MTable::_instance.ColorProfileInterface_IsMonitorProfileMode(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ColorProfileInterface::Hxx1::ConstFn<S>::GetColorSpace() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<ColorSpace>, ColorSpace>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<ColorSpace>, ColorSpace>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ColorProfileInterface* o_ = (const ColorProfileInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ColorProfileInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<ColorSpace>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (MTable::_instance.ColorProfileInterface_GetColorSpace(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ColorProfileInterface::Hxx1::ConstFn<S>::ToString(const FormatStatement* formatStatement) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ColorProfileInterface* o_ = (const ColorProfileInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ColorProfileInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (MTable::_instance.ColorProfileInterface_ToString(o_, formatStatement));
}
/// @cond INTERNAL

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ColorProfileInterface::Hxx1::Fn<S>::SetMonitorProfileMode(Bool on) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ColorProfileInterface* o_ = (ColorProfileInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateLogNullptrError(false); } 
	return (MTable::_instance.ColorProfileInterface_SetMonitorProfileMode(o_, on));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ColorProfileInterface::Hxx1::COWFn<S>::SetMonitorProfileMode(Bool on) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Bool, maxon::Result<Bool>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Bool, maxon::Result<Bool>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ColorProfileInterface* o_ = (ColorProfileInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (MTable::_instance.ColorProfileInterface_SetMonitorProfileMode(o_, on));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ColorProfileInterface::Hxx1::ConstFn<S>::DescribeIO(const DataSerializeInterface& stream) -> Result<void>
{
	return (MTable::_instance.ColorProfileInterface_DescribeIO(stream));
}
/// @endcond

#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_gfx_image_colorprofile)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_ColorProfileInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_ColorProfileInterface() { new (s_ui_maxon_ColorProfileInterface) maxon::EntityUse(ColorProfileInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/gfx_image_colorprofile.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_ColorProfileInterface(ColorProfileInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/gfx_image_colorprofile.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
constexpr const maxon::Char* ColorProfileConvertInterface::PrivateGetCppName() { return "maxon::ColorProfileConvert"; }

struct ColorProfileConvertInterface::MTable
{
	static MTable _instance;
	static MTable _unresolvedInstance;
	static const maxon::Char* const _ids;
	static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl);
	static const maxon::NULL_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = true;
	void (*ColorProfileConvertInterface_Free) (const ColorProfileConvertInterface* object);
	Result<ColorProfileConvert> (*ColorProfileConvertInterface_Init) (const PixelFormat& srcPixelFormat, const ColorProfile& srcProfile, const PixelFormat& dstPixelFormat, const ColorProfile& dstProfile, COLORCONVERSIONINTENT intent, COLORCONVERSIONFLAGS flags);
	Result<void> (*ColorProfileConvertInterface_Convert) (const ColorProfileConvertInterface* this_, const ImageConstBuffer& src, const ImageMutableBuffer& dst, Int cnt);
	HashInt (*ColorProfileConvertInterface_GetHashCode) (const ColorProfileConvertInterface* this_);
	Result<PixelFormat> (*ColorProfileConvertInterface_GetNearestNativeFormat) (const PixelFormat& format);
	Result<ColorProfileConvert> (*ColorProfileConvertInterface_InitGPU) (const ColorProfile& srcProfile, const ColorProfile& dstProfile, COLORCONVERSIONFLAGS_GPU flags, COLORCONVERSION_OPTIMIZATION_GPU_FLAGS optimization);
	ForwardRef<ColorProfileGpuHandlerRef> (*ColorProfileConvertInterface_GetGpuHandler) (const ColorProfileConvertInterface* this_);
	template <typename IMPL> void Init()
	{
		ColorProfileConvertInterface_Free = &IMPL::ColorProfileConvertInterface_Free;
		ColorProfileConvertInterface_Init = &IMPL::ColorProfileConvertInterface_Init;
		ColorProfileConvertInterface_Convert = &IMPL::ColorProfileConvertInterface_Convert;
		ColorProfileConvertInterface_GetHashCode = &IMPL::ColorProfileConvertInterface_GetHashCode;
		ColorProfileConvertInterface_GetNearestNativeFormat = &IMPL::ColorProfileConvertInterface_GetNearestNativeFormat;
		ColorProfileConvertInterface_InitGPU = &IMPL::ColorProfileConvertInterface_InitGPU;
		ColorProfileConvertInterface_GetGpuHandler = &IMPL::ColorProfileConvertInterface_GetGpuHandler;
	}
};

struct ColorProfileConvertInterface::Hxx2
{
	class Unresolved;
	template <typename C> class Wrapper
	{
	public:
		static void ColorProfileConvertInterface_Free(const ColorProfileConvertInterface* object) { return C::Free(object); }
		static Result<ColorProfileConvert> ColorProfileConvertInterface_Init(const PixelFormat& srcPixelFormat, const ColorProfile& srcProfile, const PixelFormat& dstPixelFormat, const ColorProfile& dstProfile, COLORCONVERSIONINTENT intent, COLORCONVERSIONFLAGS flags) { return C::Init(srcPixelFormat, srcProfile, dstPixelFormat, dstProfile, intent, flags); }
		static Result<void> ColorProfileConvertInterface_Convert(const ColorProfileConvertInterface* this_, const ImageConstBuffer& src, const ImageMutableBuffer& dst, Int cnt) { return C::Get(this_)->Convert(src, dst, cnt); }
		static HashInt ColorProfileConvertInterface_GetHashCode(const ColorProfileConvertInterface* this_) { return C::Get(this_)->GetHashCode(); }
		static Result<PixelFormat> ColorProfileConvertInterface_GetNearestNativeFormat(const PixelFormat& format) { return C::GetNearestNativeFormat(format); }
		static Result<ColorProfileConvert> ColorProfileConvertInterface_InitGPU(const ColorProfile& srcProfile, const ColorProfile& dstProfile, COLORCONVERSIONFLAGS_GPU flags, COLORCONVERSION_OPTIMIZATION_GPU_FLAGS optimization) { return C::InitGPU(srcProfile, dstProfile, flags, optimization); }
		static ForwardRef<ColorProfileGpuHandlerRef> ColorProfileConvertInterface_GetGpuHandler(const ColorProfileConvertInterface* this_) { return C::Get(this_)->GetGpuHandler(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto ColorProfileConvertInterface::Free(const ColorProfileConvertInterface* object) -> void
{
	return MTable::_instance.ColorProfileConvertInterface_Free(object);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ColorProfileConvertInterface::Init(const PixelFormat& srcPixelFormat, const ColorProfile& srcProfile, const PixelFormat& dstPixelFormat, const ColorProfile& dstProfile, COLORCONVERSIONINTENT intent, COLORCONVERSIONFLAGS flags) -> Result<ColorProfileConvert>
{
	return MTable::_instance.ColorProfileConvertInterface_Init(srcPixelFormat, srcProfile, dstPixelFormat, dstProfile, intent, flags);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ColorProfileConvertInterface::Convert(const ImageConstBuffer& src, const ImageMutableBuffer& dst, Int cnt) const -> Result<void>
{
	return MTable::_instance.ColorProfileConvertInterface_Convert(this, src, dst, cnt);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ColorProfileConvertInterface::GetHashCode() const -> HashInt
{
	return MTable::_instance.ColorProfileConvertInterface_GetHashCode(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ColorProfileConvertInterface::GetNearestNativeFormat(const PixelFormat& format) -> Result<PixelFormat>
{
	return MTable::_instance.ColorProfileConvertInterface_GetNearestNativeFormat(format);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ColorProfileConvertInterface::InitGPU(const ColorProfile& srcProfile, const ColorProfile& dstProfile, COLORCONVERSIONFLAGS_GPU flags, COLORCONVERSION_OPTIMIZATION_GPU_FLAGS optimization) -> Result<ColorProfileConvert>
{
	return MTable::_instance.ColorProfileConvertInterface_InitGPU(srcProfile, dstProfile, flags, optimization);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ColorProfileConvertInterface::GetGpuHandler() const -> ForwardRef<ColorProfileGpuHandlerRef>
{
	return MTable::_instance.ColorProfileConvertInterface_GetGpuHandler(this);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ColorProfileConvertInterface::Hxx1::ConstFn<S>::Init(const PixelFormat& srcPixelFormat, const ColorProfile& srcProfile, const PixelFormat& dstPixelFormat, const ColorProfile& dstProfile, COLORCONVERSIONINTENT intent, COLORCONVERSIONFLAGS flags) -> Result<ColorProfileConvert>
{
	return (MTable::_instance.ColorProfileConvertInterface_Init(srcPixelFormat, srcProfile, dstPixelFormat, dstProfile, intent, flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ColorProfileConvertInterface::Hxx1::ConstFn<S>::Convert(const ImageConstBuffer& src, const ImageMutableBuffer& dst, Int cnt) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ColorProfileConvertInterface* o_ = (const ColorProfileConvertInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ColorProfileConvertInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.ColorProfileConvertInterface_Convert(o_, src, dst, cnt));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ColorProfileConvertInterface::Hxx1::ConstFn<S>::GetNearestNativeFormat(const PixelFormat& format) -> Result<PixelFormat>
{
	return (MTable::_instance.ColorProfileConvertInterface_GetNearestNativeFormat(format));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ColorProfileConvertInterface::Hxx1::ConstFn<S>::InitGPU(const ColorProfile& srcProfile, const ColorProfile& dstProfile, COLORCONVERSIONFLAGS_GPU flags, COLORCONVERSION_OPTIMIZATION_GPU_FLAGS optimization) -> Result<ColorProfileConvert>
{
	return (MTable::_instance.ColorProfileConvertInterface_InitGPU(srcProfile, dstProfile, flags, optimization));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ColorProfileConvertInterface::Hxx1::ConstFn<S>::GetGpuHandler() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<ForwardRef<ColorProfileGpuHandlerRef>>, ForwardRef<ColorProfileGpuHandlerRef>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<ForwardRef<ColorProfileGpuHandlerRef>>, ForwardRef<ColorProfileGpuHandlerRef>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ColorProfileConvertInterface* o_ = (const ColorProfileConvertInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ColorProfileConvertInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<ForwardRef<ColorProfileGpuHandlerRef>>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (MTable::_instance.ColorProfileConvertInterface_GetGpuHandler(o_));
}
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_gfx_image_colorprofile)
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

