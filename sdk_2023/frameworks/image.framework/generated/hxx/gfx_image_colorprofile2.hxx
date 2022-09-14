
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
	PRIVATE_MAXON_SF_POINTER(ColorProfileInterface_Free, Free, MAXON_EXPAND_VA_ARGS, (void), const ColorProfileInterface* object);
	PRIVATE_MAXON_SF_POINTER(ColorProfileInterface_Alloc, Alloc, MAXON_IGNORE_VA_ARGS, (ColorProfileInterface*), const maxon::SourceLocation& allocLocation);
	PRIVATE_MAXON_SF_POINTER(ColorProfileInterface_Alloc_1, Alloc, MAXON_IGNORE_VA_ARGS, (ColorProfileInterface*), const maxon::SourceLocation& allocLocation, const ColorProfileInterface& object);
	PRIVATE_MAXON_MF_POINTER(ColorProfileInterface_IsEqual, IsEqual, false, ColorProfileInterface, const, (Bool), const ColorProfileInterface* other);
	PRIVATE_MAXON_SF_POINTER(ColorProfileInterface_OpenProfileFromFile, OpenProfileFromFile, MAXON_EXPAND_VA_ARGS, (Result<ColorProfile>), const Url& fn);
	PRIVATE_MAXON_SF_POINTER(ColorProfileInterface_OpenProfileFromMemory, OpenProfileFromMemory, MAXON_EXPAND_VA_ARGS, (Result<ColorProfile>), const Block<const Byte>& mem);
	PRIVATE_MAXON_SF_POINTER(ColorProfileInterface_CreateProfile, CreateProfile, MAXON_EXPAND_VA_ARGS, (Result<ColorProfile>), const OcioConfig& config, const CString& name);
	PRIVATE_MAXON_SF_POINTER(ColorProfileInterface_CreateProfile_1, CreateProfile, MAXON_EXPAND_VA_ARGS, (Result<ColorProfile>), const OcioConfig& config, const Url& iccPath);
	PRIVATE_MAXON_SF_POINTER(ColorProfileInterface_CreateProfile_2, CreateProfile, MAXON_EXPAND_VA_ARGS, (Result<ColorProfile>), const OcioConfig& config, const CString& viewTransform, const CString& displayColorSpace);
	PRIVATE_MAXON_SF_POINTER(ColorProfileInterface_CreateProfile_3, CreateProfile, MAXON_EXPAND_VA_ARGS, (Result<ColorProfile>), const ColorProfile& viewTransform, const ColorProfile& displayColorSpace);
	PRIVATE_MAXON_MF_POINTER(ColorProfileInterface_WriteProfileToMemory, WriteProfileToMemory, false, ColorProfileInterface, const, (Result<void>), WritableArrayInterface<Char>& mem);
	PRIVATE_MAXON_MF_POINTER(ColorProfileInterface_WriteProfileToFile, WriteProfileToFile, false, ColorProfileInterface, const, (Result<void>), const Url& fn);
	PRIVATE_MAXON_MF_POINTER(ColorProfileInterface_GetInfo, GetInfo, false, ColorProfileInterface, const, (String), COLORPROFILEINFO info);
	PRIVATE_MAXON_MF_POINTER(ColorProfileInterface_GetCrc, GetCrc, false, ColorProfileInterface, const, (UInt32));
	PRIVATE_MAXON_MF_POINTER(ColorProfileInterface_HasProfile, HasProfile, false, ColorProfileInterface, const, (Bool));
	PRIVATE_MAXON_MF_POINTER(ColorProfileInterface_CheckCompatiblePixelFormat, CheckCompatiblePixelFormat, false, ColorProfileInterface, const, (Bool), const PixelFormat& pixelFormat);
	PRIVATE_MAXON_MF_POINTER(ColorProfileInterface_IsMonitorProfileMode, IsMonitorProfileMode, false, ColorProfileInterface, const, (Bool));
	PRIVATE_MAXON_MF_POINTER(ColorProfileInterface_GetHashCode, GetHashCode, false, ColorProfileInterface, const, (HashInt));
	PRIVATE_MAXON_MF_POINTER(ColorProfileInterface_GetUniqueHashCode, GetUniqueHashCode, false, ColorProfileInterface, const, (UniqueHash));
	PRIVATE_MAXON_MF_POINTER(ColorProfileInterface_GetColorSpace, GetColorSpace, false, ColorProfileInterface, const, (ColorSpace));
	PRIVATE_MAXON_MF_POINTER(ColorProfileInterface_ToString, ToString, false, ColorProfileInterface, const, (String), const FormatStatement* formatStatement);
	PRIVATE_MAXON_MF_POINTER(ColorProfileInterface_GetOcioConfig, GetOcioConfig, false, ColorProfileInterface, const, (void), OcioConfig& config);
/// @cond INTERNAL

	PRIVATE_MAXON_MF_POINTER(ColorProfileInterface_SetMonitorProfileMode, SetMonitorProfileMode, false, ColorProfileInterface,, (Bool), Bool on);
	PRIVATE_MAXON_SF_POINTER(ColorProfileInterface_DescribeIO, DescribeIO, MAXON_EXPAND_VA_ARGS, (Result<void>), const DataSerializeInterface& stream);
/// @endcond

	template <typename IMPL> void Init()
	{
		ColorProfileInterface_Free = ColorProfileInterface_Free_GetPtr<IMPL>(true);
		ColorProfileInterface_Alloc = ColorProfileInterface_Alloc_GetPtr<IMPL>(true);
		ColorProfileInterface_Alloc_1 = ColorProfileInterface_Alloc_1_GetPtr<IMPL>(true);
		ColorProfileInterface_IsEqual = ColorProfileInterface_IsEqual_GetPtr<IMPL>(0, true).first;
		ColorProfileInterface_OpenProfileFromFile = ColorProfileInterface_OpenProfileFromFile_GetPtr<IMPL>(true);
		ColorProfileInterface_OpenProfileFromMemory = ColorProfileInterface_OpenProfileFromMemory_GetPtr<IMPL>(true);
		ColorProfileInterface_CreateProfile = ColorProfileInterface_CreateProfile_GetPtr<IMPL>(true);
		ColorProfileInterface_CreateProfile_1 = ColorProfileInterface_CreateProfile_1_GetPtr<IMPL>(true);
		ColorProfileInterface_CreateProfile_2 = ColorProfileInterface_CreateProfile_2_GetPtr<IMPL>(true);
		ColorProfileInterface_CreateProfile_3 = ColorProfileInterface_CreateProfile_3_GetPtr<IMPL>(true);
		ColorProfileInterface_WriteProfileToMemory = ColorProfileInterface_WriteProfileToMemory_GetPtr<IMPL>(0, true).first;
		ColorProfileInterface_WriteProfileToFile = ColorProfileInterface_WriteProfileToFile_GetPtr<IMPL>(0, true).first;
		ColorProfileInterface_GetInfo = ColorProfileInterface_GetInfo_GetPtr<IMPL>(0, true).first;
		ColorProfileInterface_GetCrc = ColorProfileInterface_GetCrc_GetPtr<IMPL>(0, true).first;
		ColorProfileInterface_HasProfile = ColorProfileInterface_HasProfile_GetPtr<IMPL>(0, true).first;
		ColorProfileInterface_CheckCompatiblePixelFormat = ColorProfileInterface_CheckCompatiblePixelFormat_GetPtr<IMPL>(0, true).first;
		ColorProfileInterface_IsMonitorProfileMode = ColorProfileInterface_IsMonitorProfileMode_GetPtr<IMPL>(0, true).first;
		ColorProfileInterface_GetHashCode = ColorProfileInterface_GetHashCode_GetPtr<IMPL>(0, true).first;
		ColorProfileInterface_GetUniqueHashCode = ColorProfileInterface_GetUniqueHashCode_GetPtr<IMPL>(0, true).first;
		ColorProfileInterface_GetColorSpace = ColorProfileInterface_GetColorSpace_GetPtr<IMPL>(0, true).first;
		ColorProfileInterface_ToString = ColorProfileInterface_ToString_GetPtr<IMPL>(0, true).first;
		ColorProfileInterface_GetOcioConfig = ColorProfileInterface_GetOcioConfig_GetPtr<IMPL>(0, true).first;
/// @cond INTERNAL

		ColorProfileInterface_SetMonitorProfileMode = ColorProfileInterface_SetMonitorProfileMode_GetPtr<IMPL>(0, true).first;
		ColorProfileInterface_DescribeIO = ColorProfileInterface_DescribeIO_GetPtr<IMPL>(true);
/// @endcond

	}
};

struct ColorProfileInterface::Hxx2
{
	class Unresolved;
	template <typename C> class Wrapper
	{
	public:
		using Implementation = C;
		static void ColorProfileInterface_Free(const ColorProfileInterface* object) { return C::Free(object); }
		static ColorProfileInterface* ColorProfileInterface_Alloc(const maxon::SourceLocation& allocLocation) { return C::Alloc(allocLocation); }
		static ColorProfileInterface* ColorProfileInterface_Alloc_1(const maxon::SourceLocation& allocLocation, const ColorProfileInterface& object) { return C::Alloc(allocLocation, ((const C&) object)); }
		PRIVATE_MAXON_MF_WRAPPER(ColorProfileInterface_IsEqual, ColorProfileInterface, const, (Bool), const ColorProfileInterface* other) { return C::Get(PRIVATE_MAXON_MF_THIS(const ColorProfileInterface))->IsEqual(other); }
		static Result<ColorProfile> ColorProfileInterface_OpenProfileFromFile(const Url& fn) { return C::OpenProfileFromFile(fn); }
		static Result<ColorProfile> ColorProfileInterface_OpenProfileFromMemory(const Block<const Byte>& mem) { return C::OpenProfileFromMemory(mem); }
		static Result<ColorProfile> ColorProfileInterface_CreateProfile(const OcioConfig& config, const CString& name) { return C::CreateProfile(config, name); }
		static Result<ColorProfile> ColorProfileInterface_CreateProfile_1(const OcioConfig& config, const Url& iccPath) { return C::CreateProfile(config, iccPath); }
		static Result<ColorProfile> ColorProfileInterface_CreateProfile_2(const OcioConfig& config, const CString& viewTransform, const CString& displayColorSpace) { return C::CreateProfile(config, viewTransform, displayColorSpace); }
		static Result<ColorProfile> ColorProfileInterface_CreateProfile_3(const ColorProfile& viewTransform, const ColorProfile& displayColorSpace) { return C::CreateProfile(viewTransform, displayColorSpace); }
		PRIVATE_MAXON_MF_WRAPPER(ColorProfileInterface_WriteProfileToMemory, ColorProfileInterface, const, (Result<void>), WritableArrayInterface<Char>& mem) { return C::Get(PRIVATE_MAXON_MF_THIS(const ColorProfileInterface))->WriteProfileToMemory(mem); }
		PRIVATE_MAXON_MF_WRAPPER(ColorProfileInterface_WriteProfileToFile, ColorProfileInterface, const, (Result<void>), const Url& fn) { return C::Get(PRIVATE_MAXON_MF_THIS(const ColorProfileInterface))->WriteProfileToFile(fn); }
		PRIVATE_MAXON_MF_WRAPPER(ColorProfileInterface_GetInfo, ColorProfileInterface, const, (String), COLORPROFILEINFO info) { return C::Get(PRIVATE_MAXON_MF_THIS(const ColorProfileInterface))->GetInfo(info); }
		PRIVATE_MAXON_MF_WRAPPER(ColorProfileInterface_GetCrc, ColorProfileInterface, const, (UInt32)) { return C::Get(PRIVATE_MAXON_MF_THIS(const ColorProfileInterface))->GetCrc(); }
		PRIVATE_MAXON_MF_WRAPPER(ColorProfileInterface_HasProfile, ColorProfileInterface, const, (Bool)) { return C::Get(PRIVATE_MAXON_MF_THIS(const ColorProfileInterface))->HasProfile(); }
		PRIVATE_MAXON_MF_WRAPPER(ColorProfileInterface_CheckCompatiblePixelFormat, ColorProfileInterface, const, (Bool), const PixelFormat& pixelFormat) { return C::Get(PRIVATE_MAXON_MF_THIS(const ColorProfileInterface))->CheckCompatiblePixelFormat(pixelFormat); }
		PRIVATE_MAXON_MF_WRAPPER(ColorProfileInterface_IsMonitorProfileMode, ColorProfileInterface, const, (Bool)) { return C::Get(PRIVATE_MAXON_MF_THIS(const ColorProfileInterface))->IsMonitorProfileMode(); }
		PRIVATE_MAXON_MF_WRAPPER(ColorProfileInterface_GetHashCode, ColorProfileInterface, const, (HashInt)) { return C::Get(PRIVATE_MAXON_MF_THIS(const ColorProfileInterface))->GetHashCode(); }
		PRIVATE_MAXON_MF_WRAPPER(ColorProfileInterface_GetUniqueHashCode, ColorProfileInterface, const, (UniqueHash)) { return C::Get(PRIVATE_MAXON_MF_THIS(const ColorProfileInterface))->GetUniqueHashCode(); }
		PRIVATE_MAXON_MF_WRAPPER(ColorProfileInterface_GetColorSpace, ColorProfileInterface, const, (ColorSpace)) { return C::Get(PRIVATE_MAXON_MF_THIS(const ColorProfileInterface))->GetColorSpace(); }
		PRIVATE_MAXON_MF_WRAPPER(ColorProfileInterface_ToString, ColorProfileInterface, const, (String), const FormatStatement* formatStatement) { return C::Get(PRIVATE_MAXON_MF_THIS(const ColorProfileInterface))->ToString(formatStatement); }
		PRIVATE_MAXON_MF_WRAPPER(ColorProfileInterface_GetOcioConfig, ColorProfileInterface, const, (void), OcioConfig& config) { return C::Get(PRIVATE_MAXON_MF_THIS(const ColorProfileInterface))->GetOcioConfig(config); }
/// @cond INTERNAL

		PRIVATE_MAXON_MF_WRAPPER(ColorProfileInterface_SetMonitorProfileMode, ColorProfileInterface,, (Bool), Bool on) { return C::Get(PRIVATE_MAXON_MF_THIS(ColorProfileInterface))->SetMonitorProfileMode(on); }
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
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.ColorProfileInterface_IsEqual, other);
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
MAXON_ATTRIBUTE_FORCE_INLINE auto ColorProfileInterface::CreateProfile(const OcioConfig& config, const Url& iccPath) -> Result<ColorProfile>
{
	return MTable::_instance.ColorProfileInterface_CreateProfile_1(config, iccPath);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ColorProfileInterface::CreateProfile(const OcioConfig& config, const CString& viewTransform, const CString& displayColorSpace) -> Result<ColorProfile>
{
	return MTable::_instance.ColorProfileInterface_CreateProfile_2(config, viewTransform, displayColorSpace);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ColorProfileInterface::CreateProfile(const ColorProfile& viewTransform, const ColorProfile& displayColorSpace) -> Result<ColorProfile>
{
	return MTable::_instance.ColorProfileInterface_CreateProfile_3(viewTransform, displayColorSpace);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ColorProfileInterface::WriteProfileToMemory(WritableArrayInterface<Char>& mem) const -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.ColorProfileInterface_WriteProfileToMemory, mem);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ColorProfileInterface::WriteProfileToFile(const Url& fn) const -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.ColorProfileInterface_WriteProfileToFile, fn);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ColorProfileInterface::GetInfo(COLORPROFILEINFO info) const -> String
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.ColorProfileInterface_GetInfo, info);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ColorProfileInterface::GetCrc() const -> UInt32
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.ColorProfileInterface_GetCrc);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ColorProfileInterface::HasProfile() const -> Bool
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.ColorProfileInterface_HasProfile);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ColorProfileInterface::CheckCompatiblePixelFormat(const PixelFormat& pixelFormat) const -> Bool
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.ColorProfileInterface_CheckCompatiblePixelFormat, pixelFormat);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ColorProfileInterface::IsMonitorProfileMode() const -> Bool
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.ColorProfileInterface_IsMonitorProfileMode);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ColorProfileInterface::GetHashCode() const -> HashInt
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.ColorProfileInterface_GetHashCode);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ColorProfileInterface::GetUniqueHashCode() const -> UniqueHash
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.ColorProfileInterface_GetUniqueHashCode);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ColorProfileInterface::GetColorSpace() const -> ColorSpace
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.ColorProfileInterface_GetColorSpace);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ColorProfileInterface::ToString(const FormatStatement* formatStatement) const -> String
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.ColorProfileInterface_ToString, formatStatement);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ColorProfileInterface::GetOcioConfig(OcioConfig& config) const -> void
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.ColorProfileInterface_GetOcioConfig, config);
}
/// @cond INTERNAL

MAXON_ATTRIBUTE_FORCE_INLINE auto ColorProfileInterface::SetMonitorProfileMode(Bool on) -> Bool
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.ColorProfileInterface_SetMonitorProfileMode, on);
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
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const ColorProfileInterface* o_ = (const ColorProfileInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = ColorProfileInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.ColorProfileInterface_IsEqual, other));
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
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ColorProfileInterface::Hxx1::ConstFn<S>::CreateProfile(const OcioConfig& config, const Url& iccPath) -> Result<ColorProfile>
{
	return (MTable::_instance.ColorProfileInterface_CreateProfile_1(config, iccPath));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ColorProfileInterface::Hxx1::ConstFn<S>::CreateProfile(const OcioConfig& config, const CString& viewTransform, const CString& displayColorSpace) -> Result<ColorProfile>
{
	return (MTable::_instance.ColorProfileInterface_CreateProfile_2(config, viewTransform, displayColorSpace));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ColorProfileInterface::Hxx1::ConstFn<S>::CreateProfile(const ColorProfile& viewTransform, const ColorProfile& displayColorSpace) -> Result<ColorProfile>
{
	return (MTable::_instance.ColorProfileInterface_CreateProfile_3(viewTransform, displayColorSpace));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ColorProfileInterface::Hxx1::ConstFn<S>::WriteProfileToMemory(WritableArrayInterface<Char>& mem) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const ColorProfileInterface* o_ = (const ColorProfileInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = ColorProfileInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.ColorProfileInterface_WriteProfileToMemory, mem));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ColorProfileInterface::Hxx1::ConstFn<S>::WriteProfileToFile(const Url& fn) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const ColorProfileInterface* o_ = (const ColorProfileInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = ColorProfileInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.ColorProfileInterface_WriteProfileToFile, fn));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ColorProfileInterface::Hxx1::ConstFn<S>::GetInfo(COLORPROFILEINFO info) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const ColorProfileInterface* o_ = (const ColorProfileInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = ColorProfileInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.ColorProfileInterface_GetInfo, info));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ColorProfileInterface::Hxx1::ConstFn<S>::GetCrc() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<UInt32>, UInt32>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<UInt32>, UInt32>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const ColorProfileInterface* o_ = (const ColorProfileInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = ColorProfileInterface::NullValuePtr(); if (!o_) return 0; } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.ColorProfileInterface_GetCrc));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ColorProfileInterface::Hxx1::ConstFn<S>::HasProfile() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const ColorProfileInterface* o_ = (const ColorProfileInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = ColorProfileInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.ColorProfileInterface_HasProfile));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ColorProfileInterface::Hxx1::ConstFn<S>::CheckCompatiblePixelFormat(const PixelFormat& pixelFormat) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const ColorProfileInterface* o_ = (const ColorProfileInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = ColorProfileInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.ColorProfileInterface_CheckCompatiblePixelFormat, pixelFormat));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ColorProfileInterface::Hxx1::ConstFn<S>::IsMonitorProfileMode() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const ColorProfileInterface* o_ = (const ColorProfileInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = ColorProfileInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.ColorProfileInterface_IsMonitorProfileMode));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ColorProfileInterface::Hxx1::ConstFn<S>::GetColorSpace() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<ColorSpace>, ColorSpace>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<ColorSpace>, ColorSpace>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const ColorProfileInterface* o_ = (const ColorProfileInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = ColorProfileInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<ColorSpace>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.ColorProfileInterface_GetColorSpace));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ColorProfileInterface::Hxx1::ConstFn<S>::ToString(const FormatStatement* formatStatement) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const ColorProfileInterface* o_ = (const ColorProfileInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = ColorProfileInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.ColorProfileInterface_ToString, formatStatement));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ColorProfileInterface::Hxx1::ConstFn<S>::GetOcioConfig(OcioConfig& config) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const ColorProfileInterface* o_ = (const ColorProfileInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = ColorProfileInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(); } 
	PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.ColorProfileInterface_GetOcioConfig, config);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
/// @cond INTERNAL

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ColorProfileInterface::Hxx1::Fn<S>::SetMonitorProfileMode(Bool on) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); ColorProfileInterface* o_ = (ColorProfileInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateLogNullptrError(false); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.ColorProfileInterface_SetMonitorProfileMode, on));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ColorProfileInterface::Hxx1::COWFn<S>::SetMonitorProfileMode(Bool on) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Bool, maxon::Result<Bool>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Bool, maxon::Result<Bool>>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); ColorProfileInterface* o_ = (ColorProfileInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.ColorProfileInterface_SetMonitorProfileMode, on));
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
	PRIVATE_MAXON_SF_POINTER(ColorProfileConvertInterface_Free, Free, MAXON_EXPAND_VA_ARGS, (void), const ColorProfileConvertInterface* object);
	PRIVATE_MAXON_SF_POINTER(ColorProfileConvertInterface_Init, Init, MAXON_EXPAND_VA_ARGS, (Result<ColorProfileConvert>), const PixelFormat& srcPixelFormat, const ColorProfile& srcProfile, const PixelFormat& dstPixelFormat, const ColorProfile& dstProfile, COLORCONVERSIONINTENT intent, COLORCONVERSIONFLAGS flags);
	PRIVATE_MAXON_MF_POINTER(ColorProfileConvertInterface_Convert, Convert, false, ColorProfileConvertInterface, const, (Result<void>), const ImageConstBuffer& src, const ImageMutableBuffer& dst, Int cnt);
	PRIVATE_MAXON_MF_POINTER(ColorProfileConvertInterface_GetHashCode, GetHashCode, false, ColorProfileConvertInterface, const, (HashInt));
	PRIVATE_MAXON_SF_POINTER(ColorProfileConvertInterface_GetNearestNativeFormat, GetNearestNativeFormat, MAXON_EXPAND_VA_ARGS, (Result<PixelFormat>), const PixelFormat& format);
	PRIVATE_MAXON_SF_POINTER(ColorProfileConvertInterface_InitGPU, InitGPU, MAXON_EXPAND_VA_ARGS, (Result<ColorProfileConvert>), const ColorProfile& srcProfile, const ColorProfile& dstProfile, COLORCONVERSIONFLAGS_GPU flags, COLORCONVERSION_OPTIMIZATION_GPU_FLAGS optimization);
	PRIVATE_MAXON_MF_POINTER(ColorProfileConvertInterface_GetGpuHandler, GetGpuHandler, false, ColorProfileConvertInterface, const, (ForwardRef<ColorProfileGpuHandlerRef>));
	template <typename IMPL> void Init()
	{
		ColorProfileConvertInterface_Free = ColorProfileConvertInterface_Free_GetPtr<IMPL>(true);
		ColorProfileConvertInterface_Init = ColorProfileConvertInterface_Init_GetPtr<IMPL>(true);
		ColorProfileConvertInterface_Convert = ColorProfileConvertInterface_Convert_GetPtr<IMPL>(0, true).first;
		ColorProfileConvertInterface_GetHashCode = ColorProfileConvertInterface_GetHashCode_GetPtr<IMPL>(0, true).first;
		ColorProfileConvertInterface_GetNearestNativeFormat = ColorProfileConvertInterface_GetNearestNativeFormat_GetPtr<IMPL>(true);
		ColorProfileConvertInterface_InitGPU = ColorProfileConvertInterface_InitGPU_GetPtr<IMPL>(true);
		ColorProfileConvertInterface_GetGpuHandler = ColorProfileConvertInterface_GetGpuHandler_GetPtr<IMPL>(0, true).first;
	}
};

struct ColorProfileConvertInterface::Hxx2
{
	class Unresolved;
	template <typename C> class Wrapper
	{
	public:
		using Implementation = C;
		static void ColorProfileConvertInterface_Free(const ColorProfileConvertInterface* object) { return C::Free(object); }
		static Result<ColorProfileConvert> ColorProfileConvertInterface_Init(const PixelFormat& srcPixelFormat, const ColorProfile& srcProfile, const PixelFormat& dstPixelFormat, const ColorProfile& dstProfile, COLORCONVERSIONINTENT intent, COLORCONVERSIONFLAGS flags) { return C::Init(srcPixelFormat, srcProfile, dstPixelFormat, dstProfile, intent, flags); }
		PRIVATE_MAXON_MF_WRAPPER(ColorProfileConvertInterface_Convert, ColorProfileConvertInterface, const, (Result<void>), const ImageConstBuffer& src, const ImageMutableBuffer& dst, Int cnt) { return C::Get(PRIVATE_MAXON_MF_THIS(const ColorProfileConvertInterface))->Convert(src, dst, cnt); }
		PRIVATE_MAXON_MF_WRAPPER(ColorProfileConvertInterface_GetHashCode, ColorProfileConvertInterface, const, (HashInt)) { return C::Get(PRIVATE_MAXON_MF_THIS(const ColorProfileConvertInterface))->GetHashCode(); }
		static Result<PixelFormat> ColorProfileConvertInterface_GetNearestNativeFormat(const PixelFormat& format) { return C::GetNearestNativeFormat(format); }
		static Result<ColorProfileConvert> ColorProfileConvertInterface_InitGPU(const ColorProfile& srcProfile, const ColorProfile& dstProfile, COLORCONVERSIONFLAGS_GPU flags, COLORCONVERSION_OPTIMIZATION_GPU_FLAGS optimization) { return C::InitGPU(srcProfile, dstProfile, flags, optimization); }
		PRIVATE_MAXON_MF_WRAPPER(ColorProfileConvertInterface_GetGpuHandler, ColorProfileConvertInterface, const, (ForwardRef<ColorProfileGpuHandlerRef>)) { return C::Get(PRIVATE_MAXON_MF_THIS(const ColorProfileConvertInterface))->GetGpuHandler(); }
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
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.ColorProfileConvertInterface_Convert, src, dst, cnt);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ColorProfileConvertInterface::GetHashCode() const -> HashInt
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.ColorProfileConvertInterface_GetHashCode);
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
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.ColorProfileConvertInterface_GetGpuHandler);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ColorProfileConvertInterface::Hxx1::ConstFn<S>::Init(const PixelFormat& srcPixelFormat, const ColorProfile& srcProfile, const PixelFormat& dstPixelFormat, const ColorProfile& dstProfile, COLORCONVERSIONINTENT intent, COLORCONVERSIONFLAGS flags) -> Result<ColorProfileConvert>
{
	return (MTable::_instance.ColorProfileConvertInterface_Init(srcPixelFormat, srcProfile, dstPixelFormat, dstProfile, intent, flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ColorProfileConvertInterface::Hxx1::ConstFn<S>::Convert(const ImageConstBuffer& src, const ImageMutableBuffer& dst, Int cnt) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const ColorProfileConvertInterface* o_ = (const ColorProfileConvertInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = ColorProfileConvertInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.ColorProfileConvertInterface_Convert, src, dst, cnt));
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
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<ForwardRef<ColorProfileGpuHandlerRef>>, ForwardRef<ColorProfileGpuHandlerRef>>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const ColorProfileConvertInterface* o_ = (const ColorProfileConvertInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = ColorProfileConvertInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<ForwardRef<ColorProfileGpuHandlerRef>>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.ColorProfileConvertInterface_GetGpuHandler));
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

