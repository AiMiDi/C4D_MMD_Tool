#if 1
#ifdef MAXON_TARGET_LINUX
#endif
namespace maxon
{
	namespace enum32
	{
		enum class COLORPROFILEINFO
		{
			DESCRIPTION				= 0,	///< Description of the color profile.
			MANUFACTURER			= 1,	///< Manufacturer of the color profile.
			MODEL							= 2,	///< Model of the color profile.
			COPYRIGHT					= 3,	///< Copyright information of the color profile.
			NAME							= 4,  ///< Name of the color profile.
			OCIO_CONFIG_PATH	= 5		///< Full path to the OCIO config file (empty if this is not an OCIO colorspace)
		} ;
		static const maxon::UInt64 COLORPROFILEINFO_values[] = {maxon::UInt64(enum32::COLORPROFILEINFO::DESCRIPTION), maxon::UInt64(enum32::COLORPROFILEINFO::MANUFACTURER), maxon::UInt64(enum32::COLORPROFILEINFO::MODEL), maxon::UInt64(enum32::COLORPROFILEINFO::COPYRIGHT), maxon::UInt64(enum32::COLORPROFILEINFO::NAME), maxon::UInt64(enum32::COLORPROFILEINFO::OCIO_CONFIG_PATH)};
		static const maxon::EnumInfo COLORPROFILEINFO_info{"COLORPROFILEINFO", SIZEOF(COLORPROFILEINFO), false, "DESCRIPTION\0MANUFACTURER\0MODEL\0COPYRIGHT\0NAME\0OCIO_CONFIG_PATH\0", COLORPROFILEINFO_values, std::extent<decltype(COLORPROFILEINFO_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_COLORPROFILEINFO32(){ return enum32::COLORPROFILEINFO_info; }
	namespace enum62
	{
		enum class COLORCONVERSIONINTENT
		{
			/// Hue hopefully maintained (but not required), lightness and saturation sacrificed to
			/// maintain the perceived color. White point changed to result in neutral grays.
			/// Intended for images.
			PERCEPTUAL						= 0,
		
			/// Within and outside gamut; same as Absolute Colorimetric. White point changed to
			/// result in neutral grays.
			RELATIVE_COLORIMETRIC	= 1,
		
			/// Hue and saturation maintained with lightnesssacrificed to maintain saturation.
			/// White point changed to result in neutral grays. Intended for business graphics
			/// (make it colorful charts, graphs, overheads, ...)
			SATURATION						= 2,
		
			/// Within the destination device gamut; hue, lightness and saturation are
			/// maintained. Outside the gamut; hue and lightness are maintained, saturation is
			/// sacrificed. White point for source and destination; unchanged. Intended for spot
			/// colors (Pantone, TruMatch, logo colors, ...)
			ABSOLUTE_COLORIMETRIC = 3
		} ;
		static const maxon::UInt64 COLORCONVERSIONINTENT_values[] = {maxon::UInt64(enum62::COLORCONVERSIONINTENT::PERCEPTUAL), maxon::UInt64(enum62::COLORCONVERSIONINTENT::RELATIVE_COLORIMETRIC), maxon::UInt64(enum62::COLORCONVERSIONINTENT::SATURATION), maxon::UInt64(enum62::COLORCONVERSIONINTENT::ABSOLUTE_COLORIMETRIC)};
		static const maxon::EnumInfo COLORCONVERSIONINTENT_info{"COLORCONVERSIONINTENT", SIZEOF(COLORCONVERSIONINTENT), false, "PERCEPTUAL\0RELATIVE_COLORIMETRIC\0SATURATION\0ABSOLUTE_COLORIMETRIC\0", COLORCONVERSIONINTENT_values, std::extent<decltype(COLORCONVERSIONINTENT_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_COLORCONVERSIONINTENT62(){ return enum62::COLORCONVERSIONINTENT_info; }
	namespace enum82
	{
		enum class COLORCONVERSIONFLAGS
		{
			NONE = 0,
		
			/// Black Point Compensation (BPC) controls whether to adjust for differences in black points when
			/// converting colors between color spaces. When Black Point Compensation is enabled, color
			/// transforms map white to white and luminance of black to luminance of black. The black point
			/// compensation feature does work better in conjunction with relative colorimetric intent.
			/// Perceptual intent should make no difference, although it may affect some (wrong) profiles.
			BLACKPOINTCOMPENSATION	= 1 << 0,
		
			INVERSE_DIRECTION				= 1 << 1
		
		} ;
		static const maxon::UInt64 COLORCONVERSIONFLAGS_values[] = {maxon::UInt64(enum82::COLORCONVERSIONFLAGS::NONE), maxon::UInt64(enum82::COLORCONVERSIONFLAGS::BLACKPOINTCOMPENSATION), maxon::UInt64(enum82::COLORCONVERSIONFLAGS::INVERSE_DIRECTION)};
		static const maxon::EnumInfo COLORCONVERSIONFLAGS_info{"COLORCONVERSIONFLAGS", SIZEOF(COLORCONVERSIONFLAGS), true, "NONE\0BLACKPOINTCOMPENSATION\0INVERSE_DIRECTION\0", COLORCONVERSIONFLAGS_values, std::extent<decltype(COLORCONVERSIONFLAGS_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_COLORCONVERSIONFLAGS82(){ return enum82::COLORCONVERSIONFLAGS_info; }
/// @cond INTERNAL

/// @endcond

	const maxon::Char* const ColorProfileInterface::MTable::_ids = 
		"Free@f904fa9575be0d6f\0" // void Free(const ColorProfileInterface* object)
		"Alloc@5589876ac8fc80d4\0" // ColorProfileInterface* Alloc(const maxon::SourceLocation& allocLocation)
		"Alloc@c1fe96b92e1dafd4\0" // ColorProfileInterface* Alloc(const maxon::SourceLocation& allocLocation, const ColorProfileInterface& object)
		"IsEqual@a28c6689016eafb2\0" // Bool IsEqual(const ColorProfileInterface* other) const
		"OpenProfileFromFile@f7a49a223715226c\0" // Result<ColorProfile> OpenProfileFromFile(const Url& fn)
		"OpenProfileFromMemory@526f836738915427\0" // Result<ColorProfile> OpenProfileFromMemory(const Block<const Byte>& mem)
		"CreateProfile@5f1bffd398e4ab64\0" // Result<ColorProfile> CreateProfile(const OcioConfig& config, const CString& name)
		"CreateProfile@468edeba775e269\0" // Result<ColorProfile> CreateProfile(const OcioConfig& config, const Url& iccPath)
		"CreateProfile@c093b00329265b87\0" // Result<ColorProfile> CreateProfile(const OcioConfig& config, const CString& viewTransform, const CString& displayColorSpace)
		"CreateProfile@fa423955e70b3e2e\0" // Result<ColorProfile> CreateProfile(const ColorProfile& viewTransform, const ColorProfile& displayColorSpace)
		"WriteProfileToMemory@8807b53575e0723f\0" // Result<void> WriteProfileToMemory(WritableArrayInterface<Char>& mem) const
		"WriteProfileToFile@683e18fe00110d39\0" // Result<void> WriteProfileToFile(const Url& fn) const
		"GetInfo@b4f97c9b67510dc9\0" // String GetInfo(COLORPROFILEINFO info) const
		"GetCrc@34c6756cf1200a25\0" // UInt32 GetCrc() const
		"HasProfile@12e73654e6d65520\0" // Bool HasProfile() const
		"CheckCompatiblePixelFormat@ce9751adc2456d36\0" // Bool CheckCompatiblePixelFormat(const PixelFormat& pixelFormat) const
		"IsMonitorProfileMode@12e73654e6d65520\0" // Bool IsMonitorProfileMode() const
		"GetHashCode@b22918402154097b\0" // HashInt GetHashCode() const
		"GetUniqueHashCode@c78267ca5e388263\0" // UniqueHash GetUniqueHashCode() const
		"GetColorSpace@38fcf0c8f66c1007\0" // ColorSpace GetColorSpace() const
		"ToString@a73a45c584c879d4\0" // String ToString(const FormatStatement* formatStatement) const
		"GetOcioConfig@c0332ee2ab460208\0" // void GetOcioConfig(OcioConfig& config) const
		"IsOcioDisplayViewTransform@12e73654e6d65520\0" // Bool IsOcioDisplayViewTransform() const
/// @cond INTERNAL

		"SetMonitorProfileMode@5a83dc71a2001316\0" // Bool SetMonitorProfileMode(Bool on)
		"DescribeIO@fe3f1bd5a495cc32\0" // Result<void> DescribeIO(const DataSerializeInterface& stream)
/// @endcond

	"";
	MAXON_WARNING_PUSH
	MAXON_WARNING_DISABLE_DEPRECATED
	class ColorProfileInterface::Hxx2::Unresolved : public ColorProfileInterface
	{
	public:
		static const Unresolved* Get(const ColorProfileInterface* o) { return (const Unresolved*) o; }
		static Unresolved* Get(ColorProfileInterface* o) { return (Unresolved*) o; }
		static void Free(const ColorProfileInterface* object) { if (object && maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ColorProfileInterface::Free(object); return maxon::PrivateLogNullptrError();}
		static ColorProfileInterface* Alloc(const maxon::SourceLocation& allocLocation) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ColorProfileInterface::Alloc(allocLocation); return nullptr;}
		static ColorProfileInterface* Alloc(const maxon::SourceLocation& allocLocation, const ColorProfileInterface& object) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ColorProfileInterface::Alloc(allocLocation, object); return nullptr;}
		Bool IsEqual(const ColorProfileInterface* other) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const ColorProfileInterface*) this)->IsEqual(other); return maxon::PrivateLogNullptrError(false);}
		static Result<ColorProfile> OpenProfileFromFile(const Url& fn) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ColorProfileInterface::OpenProfileFromFile(fn); return HXXRET1(UNRESOLVED);}
		static Result<ColorProfile> OpenProfileFromMemory(const Block<const Byte>& mem) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ColorProfileInterface::OpenProfileFromMemory(mem); return HXXRET1(UNRESOLVED);}
		static Result<ColorProfile> CreateProfile(const OcioConfig& config, const CString& name) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ColorProfileInterface::CreateProfile(config, name); return HXXRET1(UNRESOLVED);}
		static Result<ColorProfile> CreateProfile(const OcioConfig& config, const Url& iccPath) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ColorProfileInterface::CreateProfile(config, iccPath); return HXXRET1(UNRESOLVED);}
		static Result<ColorProfile> CreateProfile(const OcioConfig& config, const CString& viewTransform, const CString& displayColorSpace) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ColorProfileInterface::CreateProfile(config, viewTransform, displayColorSpace); return HXXRET1(UNRESOLVED);}
		static Result<ColorProfile> CreateProfile(const ColorProfile& viewTransform, const ColorProfile& displayColorSpace) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ColorProfileInterface::CreateProfile(viewTransform, displayColorSpace); return HXXRET1(UNRESOLVED);}
		Result<void> WriteProfileToMemory(WritableArrayInterface<Char>& mem) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((const ColorProfileInterface*) this)->WriteProfileToMemory(mem); return HXXRET1(UNRESOLVED);}
		Result<void> WriteProfileToFile(const Url& fn) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((const ColorProfileInterface*) this)->WriteProfileToFile(fn); return HXXRET1(UNRESOLVED);}
		String GetInfo(COLORPROFILEINFO info) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const ColorProfileInterface*) this)->GetInfo(info); return HXXRET3(UNRESOLVED, String);}
		UInt32 GetCrc() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const ColorProfileInterface*) this)->GetCrc(); return 0;}
		Bool HasProfile() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const ColorProfileInterface*) this)->HasProfile(); return maxon::PrivateLogNullptrError(false);}
		Bool CheckCompatiblePixelFormat(const PixelFormat& pixelFormat) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const ColorProfileInterface*) this)->CheckCompatiblePixelFormat(pixelFormat); return maxon::PrivateLogNullptrError(false);}
		Bool IsMonitorProfileMode() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const ColorProfileInterface*) this)->IsMonitorProfileMode(); return maxon::PrivateLogNullptrError(false);}
		HashInt GetHashCode() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const ColorProfileInterface*) this)->GetHashCode(); return HXXRET3(UNRESOLVED, HashInt);}
		UniqueHash GetUniqueHashCode() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const ColorProfileInterface*) this)->GetUniqueHashCode(); return HXXRET3(UNRESOLVED, UniqueHash);}
		ColorSpace GetColorSpace() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const ColorProfileInterface*) this)->GetColorSpace(); return HXXRET3(UNRESOLVED, ColorSpace);}
		String ToString(const FormatStatement* formatStatement) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const ColorProfileInterface*) this)->ToString(formatStatement); return HXXRET3(UNRESOLVED, String);}
		void GetOcioConfig(OcioConfig& config) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const ColorProfileInterface*) this)->GetOcioConfig(config); return maxon::PrivateLogNullptrError();}
		Bool IsOcioDisplayViewTransform() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const ColorProfileInterface*) this)->IsOcioDisplayViewTransform(); return maxon::PrivateLogNullptrError(false);}
/// @cond INTERNAL

		Bool SetMonitorProfileMode(Bool on) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((ColorProfileInterface*) this)->SetMonitorProfileMode(on); return maxon::PrivateLogNullptrError(false);}
		static Result<void> DescribeIO(const DataSerializeInterface& stream) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ColorProfileInterface::DescribeIO(stream); return HXXRET1(UNRESOLVED);}
/// @endcond

	};
	MAXON_WARNING_POP
#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
	const maxon::UNRESOLVED_RETURN_TYPE ColorProfileInterface::MTable::_returnTypes[] = 
	{
		maxon::UNRESOLVED_RETURN_TYPE::VOID_ZERO_FREE_FUNCTION,
		maxon::details::UnresolvedReturnType<ColorProfileInterface*>::value,
		maxon::details::UnresolvedReturnType<ColorProfileInterface*>::value,
		maxon::details::UnresolvedReturnType<Bool>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<Result<ColorProfile>>::value,
		maxon::details::UnresolvedReturnType<Result<ColorProfile>>::value,
		maxon::details::UnresolvedReturnType<Result<ColorProfile>>::value,
		maxon::details::UnresolvedReturnType<Result<ColorProfile>>::value,
		maxon::details::UnresolvedReturnType<Result<ColorProfile>>::value,
		maxon::details::UnresolvedReturnType<Result<ColorProfile>>::value,
		maxon::details::UnresolvedReturnType<Result<void>>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<Result<void>>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<String>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<UInt32>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<Bool>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<Bool>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<Bool>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<HashInt>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<UniqueHash>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<ColorSpace>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<String>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<void>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<Bool>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
/// @cond INTERNAL

		maxon::details::UnresolvedReturnType<Bool>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<Result<void>>::value,
/// @endcond

		maxon::UNRESOLVED_RETURN_TYPE::OTHER
	};
#endif
	maxon::Bool ColorProfileInterface::MTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl)
	{
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->ColorProfileInterface_Free = PRIVATE_MAXON_MF_CAST(decltype(ColorProfileInterface_Free), &Hxx2::Wrapper<Hxx2::Unresolved>::ColorProfileInterface_Free);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->ColorProfileInterface_Alloc = PRIVATE_MAXON_MF_CAST(decltype(ColorProfileInterface_Alloc), &Hxx2::Wrapper<Hxx2::Unresolved>::ColorProfileInterface_Alloc);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->ColorProfileInterface_Alloc_1 = PRIVATE_MAXON_MF_CAST(decltype(ColorProfileInterface_Alloc_1), &Hxx2::Wrapper<Hxx2::Unresolved>::ColorProfileInterface_Alloc_1);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->ColorProfileInterface_IsEqual = PRIVATE_MAXON_MF_CAST(decltype(ColorProfileInterface_IsEqual), &Hxx2::Wrapper<Hxx2::Unresolved>::ColorProfileInterface_IsEqual);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<ColorProfile>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->ColorProfileInterface_OpenProfileFromFile = PRIVATE_MAXON_MF_CAST(decltype(ColorProfileInterface_OpenProfileFromFile), &Hxx2::Wrapper<Hxx2::Unresolved>::ColorProfileInterface_OpenProfileFromFile);
		#else
		tbl->ColorProfileInterface_OpenProfileFromFile = PRIVATE_MAXON_MF_CAST(decltype(ColorProfileInterface_OpenProfileFromFile), &Hxx2::Wrapper<Hxx2::Unresolved>::ColorProfileInterface_OpenProfileFromFile);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<ColorProfile>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->ColorProfileInterface_OpenProfileFromMemory = PRIVATE_MAXON_MF_CAST(decltype(ColorProfileInterface_OpenProfileFromMemory), &Hxx2::Wrapper<Hxx2::Unresolved>::ColorProfileInterface_OpenProfileFromMemory);
		#else
		tbl->ColorProfileInterface_OpenProfileFromMemory = PRIVATE_MAXON_MF_CAST(decltype(ColorProfileInterface_OpenProfileFromMemory), &Hxx2::Wrapper<Hxx2::Unresolved>::ColorProfileInterface_OpenProfileFromMemory);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<ColorProfile>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->ColorProfileInterface_CreateProfile = PRIVATE_MAXON_MF_CAST(decltype(ColorProfileInterface_CreateProfile), &Hxx2::Wrapper<Hxx2::Unresolved>::ColorProfileInterface_CreateProfile);
		#else
		tbl->ColorProfileInterface_CreateProfile = PRIVATE_MAXON_MF_CAST(decltype(ColorProfileInterface_CreateProfile), &Hxx2::Wrapper<Hxx2::Unresolved>::ColorProfileInterface_CreateProfile);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<ColorProfile>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->ColorProfileInterface_CreateProfile_1 = PRIVATE_MAXON_MF_CAST(decltype(ColorProfileInterface_CreateProfile_1), &Hxx2::Wrapper<Hxx2::Unresolved>::ColorProfileInterface_CreateProfile_1);
		#else
		tbl->ColorProfileInterface_CreateProfile_1 = PRIVATE_MAXON_MF_CAST(decltype(ColorProfileInterface_CreateProfile_1), &Hxx2::Wrapper<Hxx2::Unresolved>::ColorProfileInterface_CreateProfile_1);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<ColorProfile>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->ColorProfileInterface_CreateProfile_2 = PRIVATE_MAXON_MF_CAST(decltype(ColorProfileInterface_CreateProfile_2), &Hxx2::Wrapper<Hxx2::Unresolved>::ColorProfileInterface_CreateProfile_2);
		#else
		tbl->ColorProfileInterface_CreateProfile_2 = PRIVATE_MAXON_MF_CAST(decltype(ColorProfileInterface_CreateProfile_2), &Hxx2::Wrapper<Hxx2::Unresolved>::ColorProfileInterface_CreateProfile_2);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<ColorProfile>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->ColorProfileInterface_CreateProfile_3 = PRIVATE_MAXON_MF_CAST(decltype(ColorProfileInterface_CreateProfile_3), &Hxx2::Wrapper<Hxx2::Unresolved>::ColorProfileInterface_CreateProfile_3);
		#else
		tbl->ColorProfileInterface_CreateProfile_3 = PRIVATE_MAXON_MF_CAST(decltype(ColorProfileInterface_CreateProfile_3), &Hxx2::Wrapper<Hxx2::Unresolved>::ColorProfileInterface_CreateProfile_3);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<void>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->ColorProfileInterface_WriteProfileToMemory = PRIVATE_MAXON_MF_CAST(decltype(ColorProfileInterface_WriteProfileToMemory), &Hxx2::Wrapper<Hxx2::Unresolved>::ColorProfileInterface_WriteProfileToMemory);
		#else
		tbl->ColorProfileInterface_WriteProfileToMemory = PRIVATE_MAXON_MF_CAST(decltype(ColorProfileInterface_WriteProfileToMemory), &Hxx2::Wrapper<Hxx2::Unresolved>::ColorProfileInterface_WriteProfileToMemory);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<void>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->ColorProfileInterface_WriteProfileToFile = PRIVATE_MAXON_MF_CAST(decltype(ColorProfileInterface_WriteProfileToFile), &Hxx2::Wrapper<Hxx2::Unresolved>::ColorProfileInterface_WriteProfileToFile);
		#else
		tbl->ColorProfileInterface_WriteProfileToFile = PRIVATE_MAXON_MF_CAST(decltype(ColorProfileInterface_WriteProfileToFile), &Hxx2::Wrapper<Hxx2::Unresolved>::ColorProfileInterface_WriteProfileToFile);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<String>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->ColorProfileInterface_GetInfo = PRIVATE_MAXON_MF_CAST(decltype(ColorProfileInterface_GetInfo), &Hxx2::Wrapper<Hxx2::Unresolved>::ColorProfileInterface_GetInfo);
		#else
		tbl->ColorProfileInterface_GetInfo = PRIVATE_MAXON_MF_CAST(decltype(ColorProfileInterface_GetInfo), &Hxx2::Wrapper<Hxx2::Unresolved>::ColorProfileInterface_GetInfo);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->ColorProfileInterface_GetCrc = PRIVATE_MAXON_MF_CAST(decltype(ColorProfileInterface_GetCrc), &Hxx2::Wrapper<Hxx2::Unresolved>::ColorProfileInterface_GetCrc);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->ColorProfileInterface_HasProfile = PRIVATE_MAXON_MF_CAST(decltype(ColorProfileInterface_HasProfile), &Hxx2::Wrapper<Hxx2::Unresolved>::ColorProfileInterface_HasProfile);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->ColorProfileInterface_CheckCompatiblePixelFormat = PRIVATE_MAXON_MF_CAST(decltype(ColorProfileInterface_CheckCompatiblePixelFormat), &Hxx2::Wrapper<Hxx2::Unresolved>::ColorProfileInterface_CheckCompatiblePixelFormat);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->ColorProfileInterface_IsMonitorProfileMode = PRIVATE_MAXON_MF_CAST(decltype(ColorProfileInterface_IsMonitorProfileMode), &Hxx2::Wrapper<Hxx2::Unresolved>::ColorProfileInterface_IsMonitorProfileMode);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<HashInt>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->ColorProfileInterface_GetHashCode = PRIVATE_MAXON_MF_CAST(decltype(ColorProfileInterface_GetHashCode), &Hxx2::Wrapper<Hxx2::Unresolved>::ColorProfileInterface_GetHashCode);
		#else
		tbl->ColorProfileInterface_GetHashCode = PRIVATE_MAXON_MF_CAST(decltype(ColorProfileInterface_GetHashCode), &Hxx2::Wrapper<Hxx2::Unresolved>::ColorProfileInterface_GetHashCode);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<UniqueHash>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->ColorProfileInterface_GetUniqueHashCode = PRIVATE_MAXON_MF_CAST(decltype(ColorProfileInterface_GetUniqueHashCode), &Hxx2::Wrapper<Hxx2::Unresolved>::ColorProfileInterface_GetUniqueHashCode);
		#else
		tbl->ColorProfileInterface_GetUniqueHashCode = PRIVATE_MAXON_MF_CAST(decltype(ColorProfileInterface_GetUniqueHashCode), &Hxx2::Wrapper<Hxx2::Unresolved>::ColorProfileInterface_GetUniqueHashCode);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<ColorSpace>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->ColorProfileInterface_GetColorSpace = PRIVATE_MAXON_MF_CAST(decltype(ColorProfileInterface_GetColorSpace), &Hxx2::Wrapper<Hxx2::Unresolved>::ColorProfileInterface_GetColorSpace);
		#else
		tbl->ColorProfileInterface_GetColorSpace = PRIVATE_MAXON_MF_CAST(decltype(ColorProfileInterface_GetColorSpace), &Hxx2::Wrapper<Hxx2::Unresolved>::ColorProfileInterface_GetColorSpace);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<String>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->ColorProfileInterface_ToString = PRIVATE_MAXON_MF_CAST(decltype(ColorProfileInterface_ToString), &Hxx2::Wrapper<Hxx2::Unresolved>::ColorProfileInterface_ToString);
		#else
		tbl->ColorProfileInterface_ToString = PRIVATE_MAXON_MF_CAST(decltype(ColorProfileInterface_ToString), &Hxx2::Wrapper<Hxx2::Unresolved>::ColorProfileInterface_ToString);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->ColorProfileInterface_GetOcioConfig = PRIVATE_MAXON_MF_CAST(decltype(ColorProfileInterface_GetOcioConfig), &Hxx2::Wrapper<Hxx2::Unresolved>::ColorProfileInterface_GetOcioConfig);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->ColorProfileInterface_IsOcioDisplayViewTransform = PRIVATE_MAXON_MF_CAST(decltype(ColorProfileInterface_IsOcioDisplayViewTransform), &Hxx2::Wrapper<Hxx2::Unresolved>::ColorProfileInterface_IsOcioDisplayViewTransform);
		#endif
/// @cond INTERNAL

		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->ColorProfileInterface_SetMonitorProfileMode = PRIVATE_MAXON_MF_CAST(decltype(ColorProfileInterface_SetMonitorProfileMode), &Hxx2::Wrapper<Hxx2::Unresolved>::ColorProfileInterface_SetMonitorProfileMode);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<void>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->ColorProfileInterface_DescribeIO = PRIVATE_MAXON_MF_CAST(decltype(ColorProfileInterface_DescribeIO), &Hxx2::Wrapper<Hxx2::Unresolved>::ColorProfileInterface_DescribeIO);
		#else
		tbl->ColorProfileInterface_DescribeIO = PRIVATE_MAXON_MF_CAST(decltype(ColorProfileInterface_DescribeIO), &Hxx2::Wrapper<Hxx2::Unresolved>::ColorProfileInterface_DescribeIO);
		#endif
/// @endcond

	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_interface, (const void**) tbl, _returnTypes, SIZEOF(MTable) / SIZEOF(void*));
	#else
		return true;
	#endif
	}
	MAXON_INTERFACE_REGISTER(ColorProfileInterface, "net.maxon.image.interface.colorprofile", nullptr, maxon::EntityBase::FLAGS::NONE);
	template <typename DUMMY> maxon::Int ColorProfileInterface::PrivateInstantiateDefaultValueHelper()
	{
		return 0
		| maxon::details::InstantiateDefaultReturnValue<ColorSpace>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateDefaultReturnValue<HashInt>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateDefaultReturnValue<String>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateDefaultReturnValue<UniqueHash>(OVERLOAD_MAX_RANK)
		;
	}
	const maxon::Char* const ColorProfileConvertInterface::MTable::_ids = 
		"Free@663499d5dad7b898\0" // void Free(const ColorProfileConvertInterface* object)
		"Init@cc8aa3688cbcf0\0" // Result<ColorProfileConvert> Init(const PixelFormat& srcPixelFormat, const ColorProfile& srcProfile, const PixelFormat& dstPixelFormat, const ColorProfile& dstProfile, COLORCONVERSIONINTENT intent, COLORCONVERSIONFLAGS flags)
		"Convert@3a4e15d3a46d6181\0" // Result<void> Convert(const ImageConstBuffer& src, const ImageMutableBuffer& dst, Int cnt) const
		"GetHashCode@b22918402154097b\0" // HashInt GetHashCode() const
		"GetNearestNativeFormat@d32de2525ddc6b6b\0" // Result<PixelFormat> GetNearestNativeFormat(const PixelFormat& format)
		"InitGPU@634209eadef407f6\0" // Result<ColorProfileConvert> InitGPU(const ColorProfile& srcProfile, const ColorProfile& dstProfile, COLORCONVERSIONFLAGS_GPU flags, COLORCONVERSION_OPTIMIZATION_GPU_FLAGS optimization)
		"GetGpuHandler@81c28057faef0b6f\0" // ForwardRef<ColorProfileGpuHandlerRef> GetGpuHandler() const
	"";
	MAXON_WARNING_PUSH
	MAXON_WARNING_DISABLE_DEPRECATED
	class ColorProfileConvertInterface::Hxx2::Unresolved : public ColorProfileConvertInterface
	{
	public:
		static const Unresolved* Get(const ColorProfileConvertInterface* o) { return (const Unresolved*) o; }
		static Unresolved* Get(ColorProfileConvertInterface* o) { return (Unresolved*) o; }
		static void Free(const ColorProfileConvertInterface* object) { if (object && maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ColorProfileConvertInterface::Free(object); return maxon::PrivateLogNullptrError();}
		static Result<ColorProfileConvert> Init(const PixelFormat& srcPixelFormat, const ColorProfile& srcProfile, const PixelFormat& dstPixelFormat, const ColorProfile& dstProfile, COLORCONVERSIONINTENT intent, COLORCONVERSIONFLAGS flags) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ColorProfileConvertInterface::Init(srcPixelFormat, srcProfile, dstPixelFormat, dstProfile, intent, flags); return HXXRET1(UNRESOLVED);}
		Result<void> Convert(const ImageConstBuffer& src, const ImageMutableBuffer& dst, Int cnt) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((const ColorProfileConvertInterface*) this)->Convert(src, dst, cnt); return HXXRET1(UNRESOLVED);}
		HashInt GetHashCode() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const ColorProfileConvertInterface*) this)->GetHashCode(); return HXXRET3(UNRESOLVED, HashInt);}
		static Result<PixelFormat> GetNearestNativeFormat(const PixelFormat& format) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ColorProfileConvertInterface::GetNearestNativeFormat(format); return HXXRET1(UNRESOLVED);}
		static Result<ColorProfileConvert> InitGPU(const ColorProfile& srcProfile, const ColorProfile& dstProfile, COLORCONVERSIONFLAGS_GPU flags, COLORCONVERSION_OPTIMIZATION_GPU_FLAGS optimization) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ColorProfileConvertInterface::InitGPU(srcProfile, dstProfile, flags, optimization); return HXXRET1(UNRESOLVED);}
		ForwardRef<ColorProfileGpuHandlerRef> GetGpuHandler() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const ColorProfileConvertInterface*) this)->GetGpuHandler(); return HXXRET3(UNRESOLVED, ForwardRef<ColorProfileGpuHandlerRef>);}
	};
	MAXON_WARNING_POP
#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
	const maxon::UNRESOLVED_RETURN_TYPE ColorProfileConvertInterface::MTable::_returnTypes[] = 
	{
		maxon::UNRESOLVED_RETURN_TYPE::VOID_ZERO_FREE_FUNCTION,
		maxon::details::UnresolvedReturnType<Result<ColorProfileConvert>>::value,
		maxon::details::UnresolvedReturnType<Result<void>>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<HashInt>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<Result<PixelFormat>>::value,
		maxon::details::UnresolvedReturnType<Result<ColorProfileConvert>>::value,
		maxon::details::UnresolvedReturnType<ForwardRef<ColorProfileGpuHandlerRef>>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::UNRESOLVED_RETURN_TYPE::OTHER
	};
#endif
	maxon::Bool ColorProfileConvertInterface::MTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl)
	{
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->ColorProfileConvertInterface_Free = PRIVATE_MAXON_MF_CAST(decltype(ColorProfileConvertInterface_Free), &Hxx2::Wrapper<Hxx2::Unresolved>::ColorProfileConvertInterface_Free);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<ColorProfileConvert>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->ColorProfileConvertInterface_Init = PRIVATE_MAXON_MF_CAST(decltype(ColorProfileConvertInterface_Init), &Hxx2::Wrapper<Hxx2::Unresolved>::ColorProfileConvertInterface_Init);
		#else
		tbl->ColorProfileConvertInterface_Init = PRIVATE_MAXON_MF_CAST(decltype(ColorProfileConvertInterface_Init), &Hxx2::Wrapper<Hxx2::Unresolved>::ColorProfileConvertInterface_Init);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<void>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->ColorProfileConvertInterface_Convert = PRIVATE_MAXON_MF_CAST(decltype(ColorProfileConvertInterface_Convert), &Hxx2::Wrapper<Hxx2::Unresolved>::ColorProfileConvertInterface_Convert);
		#else
		tbl->ColorProfileConvertInterface_Convert = PRIVATE_MAXON_MF_CAST(decltype(ColorProfileConvertInterface_Convert), &Hxx2::Wrapper<Hxx2::Unresolved>::ColorProfileConvertInterface_Convert);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<HashInt>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->ColorProfileConvertInterface_GetHashCode = PRIVATE_MAXON_MF_CAST(decltype(ColorProfileConvertInterface_GetHashCode), &Hxx2::Wrapper<Hxx2::Unresolved>::ColorProfileConvertInterface_GetHashCode);
		#else
		tbl->ColorProfileConvertInterface_GetHashCode = PRIVATE_MAXON_MF_CAST(decltype(ColorProfileConvertInterface_GetHashCode), &Hxx2::Wrapper<Hxx2::Unresolved>::ColorProfileConvertInterface_GetHashCode);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<PixelFormat>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->ColorProfileConvertInterface_GetNearestNativeFormat = PRIVATE_MAXON_MF_CAST(decltype(ColorProfileConvertInterface_GetNearestNativeFormat), &Hxx2::Wrapper<Hxx2::Unresolved>::ColorProfileConvertInterface_GetNearestNativeFormat);
		#else
		tbl->ColorProfileConvertInterface_GetNearestNativeFormat = PRIVATE_MAXON_MF_CAST(decltype(ColorProfileConvertInterface_GetNearestNativeFormat), &Hxx2::Wrapper<Hxx2::Unresolved>::ColorProfileConvertInterface_GetNearestNativeFormat);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<ColorProfileConvert>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->ColorProfileConvertInterface_InitGPU = PRIVATE_MAXON_MF_CAST(decltype(ColorProfileConvertInterface_InitGPU), &Hxx2::Wrapper<Hxx2::Unresolved>::ColorProfileConvertInterface_InitGPU);
		#else
		tbl->ColorProfileConvertInterface_InitGPU = PRIVATE_MAXON_MF_CAST(decltype(ColorProfileConvertInterface_InitGPU), &Hxx2::Wrapper<Hxx2::Unresolved>::ColorProfileConvertInterface_InitGPU);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<ForwardRef<ColorProfileGpuHandlerRef>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->ColorProfileConvertInterface_GetGpuHandler = PRIVATE_MAXON_MF_CAST(decltype(ColorProfileConvertInterface_GetGpuHandler), &Hxx2::Wrapper<Hxx2::Unresolved>::ColorProfileConvertInterface_GetGpuHandler);
		#else
		tbl->ColorProfileConvertInterface_GetGpuHandler = PRIVATE_MAXON_MF_CAST(decltype(ColorProfileConvertInterface_GetGpuHandler), &Hxx2::Wrapper<Hxx2::Unresolved>::ColorProfileConvertInterface_GetGpuHandler);
		#endif
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_interface, (const void**) tbl, _returnTypes, SIZEOF(MTable) / SIZEOF(void*));
	#else
		return true;
	#endif
	}
	MAXON_INTERFACE_REGISTER(ColorProfileConvertInterface, "net.maxon.image.interface.colorprofileconvert", nullptr, maxon::EntityBase::FLAGS::NONE);
	template <typename DUMMY> maxon::Int ColorProfileConvertInterface::PrivateInstantiateDefaultValueHelper()
	{
		return 0
		| maxon::details::InstantiateDefaultReturnValue<ForwardRef<ColorProfileGpuHandlerRef>>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateDefaultReturnValue<HashInt>(OVERLOAD_MAX_RANK)
		;
	}
	MAXON_REGISTRY_REGISTER(ColorProfiles);
	namespace ColorProfiles
	{
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(NONE, , "net.maxon.image.colorprofile.none");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(SRGB, , "net.maxon.image.colorprofile.srgb");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(SGREY, , "net.maxon.image.colorprofile.sgrey");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(CMYKdefault, , "net.maxon.image.colorprofile.cmykdefault");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(YUVdefault, , "net.maxon.image.colorprofile.yuvdefault");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(LINEAR_RGB, , "net.maxon.image.colorprofile.linear_rgb");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(LINEAR_GREY, , "net.maxon.image.colorprofile.linear_grey");
	}
}
#endif
static maxon::details::ForceEvaluation s_forceEval_gfx_image_colorprofile(0
	| maxon::ColorProfileInterface::PrivateInstantiateDefaultValueHelper<maxon::Int>()
	| maxon::ColorProfileConvertInterface::PrivateInstantiateDefaultValueHelper<maxon::Int>()
);
