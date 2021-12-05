#if 1
#ifdef MAXON_TARGET_LINUX
#endif
namespace maxon
{
	namespace enum30
	{
		enum class COLORPROFILEINFO
		{
			DESCRIPTION		= 0,	///< Description of the color profile.
			MANUFACTURER	= 1,	///< Manufacturer of the color profile.
			MODEL					= 2,	///< Model of the color profile.
			COPYRIGHT			= 3		///< Copyright informations of the color profile.
		} ;
		static const maxon::UInt64 COLORPROFILEINFO_values[] = {maxon::UInt64(enum30::COLORPROFILEINFO::DESCRIPTION), maxon::UInt64(enum30::COLORPROFILEINFO::MANUFACTURER), maxon::UInt64(enum30::COLORPROFILEINFO::MODEL), maxon::UInt64(enum30::COLORPROFILEINFO::COPYRIGHT)};
		static const maxon::EnumInfo COLORPROFILEINFO_info{"COLORPROFILEINFO", SIZEOF(COLORPROFILEINFO), false, "DESCRIPTION\0MANUFACTURER\0MODEL\0COPYRIGHT\0", COLORPROFILEINFO_values, std::extent<decltype(COLORPROFILEINFO_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_COLORPROFILEINFO30(){ return enum30::COLORPROFILEINFO_info; }
	namespace enum60
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
		static const maxon::UInt64 COLORCONVERSIONINTENT_values[] = {maxon::UInt64(enum60::COLORCONVERSIONINTENT::PERCEPTUAL), maxon::UInt64(enum60::COLORCONVERSIONINTENT::RELATIVE_COLORIMETRIC), maxon::UInt64(enum60::COLORCONVERSIONINTENT::SATURATION), maxon::UInt64(enum60::COLORCONVERSIONINTENT::ABSOLUTE_COLORIMETRIC)};
		static const maxon::EnumInfo COLORCONVERSIONINTENT_info{"COLORCONVERSIONINTENT", SIZEOF(COLORCONVERSIONINTENT), false, "PERCEPTUAL\0RELATIVE_COLORIMETRIC\0SATURATION\0ABSOLUTE_COLORIMETRIC\0", COLORCONVERSIONINTENT_values, std::extent<decltype(COLORCONVERSIONINTENT_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_COLORCONVERSIONINTENT60(){ return enum60::COLORCONVERSIONINTENT_info; }
	namespace enum78
	{
		enum class COLORCONVERSIONFLAGS
		{
			NONE = 0,
		
			/// Black Point Compensation (BPC) controls whether to adjust for differences in black points when
			/// converting colors between color spaces. When Black Point Compensation is enabled, color
			/// transforms map white to white and luminance of black to luminance of black. The black point
			/// compensation feature does work better in conjunction with relative colorimetric intent.
			/// Perceptual intent should make no difference, although it may affect some (wrong) profiles.
			BLACKPOINTCOMPENSATION = (1 << 0)
		
		} ;
		static const maxon::UInt64 COLORCONVERSIONFLAGS_values[] = {maxon::UInt64(enum78::COLORCONVERSIONFLAGS::NONE), maxon::UInt64(enum78::COLORCONVERSIONFLAGS::BLACKPOINTCOMPENSATION)};
		static const maxon::EnumInfo COLORCONVERSIONFLAGS_info{"COLORCONVERSIONFLAGS", SIZEOF(COLORCONVERSIONFLAGS), true, "NONE\0BLACKPOINTCOMPENSATION\0", COLORCONVERSIONFLAGS_values, std::extent<decltype(COLORCONVERSIONFLAGS_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_COLORCONVERSIONFLAGS78(){ return enum78::COLORCONVERSIONFLAGS_info; }
/// @cond INTERNAL

/// @endcond

	const maxon::Char* const ColorProfileInterface::MTable::_ids = 
		"Free@f904fa9575be0d6f\0" // void Free(const ColorProfileInterface* object)
		"Alloc@5589876ac8fc80d4\0" // ColorProfileInterface* Alloc(const maxon::SourceLocation& allocLocation)
		"Alloc@c1fe96b92e1dafd4\0" // ColorProfileInterface* Alloc(const maxon::SourceLocation& allocLocation, const ColorProfileInterface& object)
		"IsEqual@a28c6689016eafb2\0" // Bool IsEqual(const ColorProfileInterface* other) const
		"OpenProfileFromFile@f7a49a223715226c\0" // Result<ColorProfile> OpenProfileFromFile(const Url& fn)
		"OpenProfileFromMemory@526f836738915427\0" // Result<ColorProfile> OpenProfileFromMemory(const Block<const Byte>& mem)
		"WriteProfileToMemory@8807b53575e0723f\0" // Result<void> WriteProfileToMemory(WritableArrayInterface<Char>& mem) const
		"WriteProfileToFile@683e18fe00110d39\0" // Result<void> WriteProfileToFile(const Url& fn) const
		"GetInfo@b4f97c9b67510dc9\0" // String GetInfo(COLORPROFILEINFO info) const
		"GetCrc@34c6756cf1200a25\0" // UInt32 GetCrc() const
		"HasProfile@12e73654e6d65520\0" // Bool HasProfile() const
		"CheckCompatiblePixelFormat@ce9751adc2456d36\0" // Bool CheckCompatiblePixelFormat(const PixelFormat& pixelFormat) const
		"IsMonitorProfileMode@12e73654e6d65520\0" // Bool IsMonitorProfileMode() const
		"GetHashCode@b22918402154097b\0" // HashInt GetHashCode() const
		"GetColorSpace@38fcf0c8f66c1007\0" // ColorSpace GetColorSpace() const
		"ToString@a73a45c584c879d4\0" // String ToString(const FormatStatement* formatStatement) const
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
		static Result<ColorProfile> OpenProfileFromFile(const Url& fn) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ColorProfileInterface::OpenProfileFromFile(fn); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static Result<ColorProfile> OpenProfileFromMemory(const Block<const Byte>& mem) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ColorProfileInterface::OpenProfileFromMemory(mem); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<void> WriteProfileToMemory(WritableArrayInterface<Char>& mem) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((const ColorProfileInterface*) this)->WriteProfileToMemory(mem); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<void> WriteProfileToFile(const Url& fn) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((const ColorProfileInterface*) this)->WriteProfileToFile(fn); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		String GetInfo(COLORPROFILEINFO info) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const ColorProfileInterface*) this)->GetInfo(info); return maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		UInt32 GetCrc() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const ColorProfileInterface*) this)->GetCrc(); return 0;}
		Bool HasProfile() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const ColorProfileInterface*) this)->HasProfile(); return maxon::PrivateLogNullptrError(false);}
		Bool CheckCompatiblePixelFormat(const PixelFormat& pixelFormat) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const ColorProfileInterface*) this)->CheckCompatiblePixelFormat(pixelFormat); return maxon::PrivateLogNullptrError(false);}
		Bool IsMonitorProfileMode() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const ColorProfileInterface*) this)->IsMonitorProfileMode(); return maxon::PrivateLogNullptrError(false);}
		HashInt GetHashCode() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const ColorProfileInterface*) this)->GetHashCode(); return maxon::PrivateIncompleteNullReturnValue<HashInt>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		ColorSpace GetColorSpace() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const ColorProfileInterface*) this)->GetColorSpace(); return maxon::PrivateIncompleteNullReturnValue<ColorSpace>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		String ToString(const FormatStatement* formatStatement) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const ColorProfileInterface*) this)->ToString(formatStatement); return maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
/// @cond INTERNAL

		Bool SetMonitorProfileMode(Bool on) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((ColorProfileInterface*) this)->SetMonitorProfileMode(on); return maxon::PrivateLogNullptrError(false);}
		static Result<void> DescribeIO(const DataSerializeInterface& stream) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ColorProfileInterface::DescribeIO(stream); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
/// @endcond

	};
	MAXON_WARNING_POP
#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
	const maxon::NULL_RETURN_TYPE ColorProfileInterface::MTable::_returnTypes[] = 
	{
		maxon::NULL_RETURN_TYPE::VOID_ZERO_FREE_FUNCTION,
		maxon::details::NullReturnType<ColorProfileInterface*>::value,
		maxon::details::NullReturnType<ColorProfileInterface*>::value,
		maxon::details::NullReturnType<Bool>::value,
		maxon::details::NullReturnType<Result<ColorProfile>>::value,
		maxon::details::NullReturnType<Result<ColorProfile>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<String>::value,
		maxon::details::NullReturnType<UInt32>::value,
		maxon::details::NullReturnType<Bool>::value,
		maxon::details::NullReturnType<Bool>::value,
		maxon::details::NullReturnType<Bool>::value,
		maxon::details::NullReturnType<HashInt>::value,
		maxon::details::NullReturnType<ColorSpace>::value,
		maxon::details::NullReturnType<String>::value,
/// @cond INTERNAL

		maxon::details::NullReturnType<Bool>::value,
		maxon::details::NullReturnType<Result<void>>::value,
/// @endcond

		maxon::NULL_RETURN_TYPE::OTHER
	};
#endif
	maxon::Bool ColorProfileInterface::MTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl)
	{
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_ColorProfileInterface_Free = &Hxx2::Wrapper<Hxx2::Unresolved>::_ColorProfileInterface_Free;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_ColorProfileInterface_Alloc = &Hxx2::Wrapper<Hxx2::Unresolved>::_ColorProfileInterface_Alloc;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_ColorProfileInterface_Alloc_1 = &Hxx2::Wrapper<Hxx2::Unresolved>::_ColorProfileInterface_Alloc_1;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_ColorProfileInterface_IsEqual = &Hxx2::Wrapper<Hxx2::Unresolved>::_ColorProfileInterface_IsEqual;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<ColorProfile>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_ColorProfileInterface_OpenProfileFromFile = &Hxx2::Wrapper<Hxx2::Unresolved>::_ColorProfileInterface_OpenProfileFromFile;
		#else
		tbl->_ColorProfileInterface_OpenProfileFromFile = &Hxx2::Wrapper<Hxx2::Unresolved>::_ColorProfileInterface_OpenProfileFromFile;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<ColorProfile>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_ColorProfileInterface_OpenProfileFromMemory = &Hxx2::Wrapper<Hxx2::Unresolved>::_ColorProfileInterface_OpenProfileFromMemory;
		#else
		tbl->_ColorProfileInterface_OpenProfileFromMemory = &Hxx2::Wrapper<Hxx2::Unresolved>::_ColorProfileInterface_OpenProfileFromMemory;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_ColorProfileInterface_WriteProfileToMemory = &Hxx2::Wrapper<Hxx2::Unresolved>::_ColorProfileInterface_WriteProfileToMemory;
		#else
		tbl->_ColorProfileInterface_WriteProfileToMemory = &Hxx2::Wrapper<Hxx2::Unresolved>::_ColorProfileInterface_WriteProfileToMemory;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_ColorProfileInterface_WriteProfileToFile = &Hxx2::Wrapper<Hxx2::Unresolved>::_ColorProfileInterface_WriteProfileToFile;
		#else
		tbl->_ColorProfileInterface_WriteProfileToFile = &Hxx2::Wrapper<Hxx2::Unresolved>::_ColorProfileInterface_WriteProfileToFile;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<String>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_ColorProfileInterface_GetInfo = &Hxx2::Wrapper<Hxx2::Unresolved>::_ColorProfileInterface_GetInfo;
		#else
		tbl->_ColorProfileInterface_GetInfo = &Hxx2::Wrapper<Hxx2::Unresolved>::_ColorProfileInterface_GetInfo;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_ColorProfileInterface_GetCrc = &Hxx2::Wrapper<Hxx2::Unresolved>::_ColorProfileInterface_GetCrc;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_ColorProfileInterface_HasProfile = &Hxx2::Wrapper<Hxx2::Unresolved>::_ColorProfileInterface_HasProfile;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_ColorProfileInterface_CheckCompatiblePixelFormat = &Hxx2::Wrapper<Hxx2::Unresolved>::_ColorProfileInterface_CheckCompatiblePixelFormat;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_ColorProfileInterface_IsMonitorProfileMode = &Hxx2::Wrapper<Hxx2::Unresolved>::_ColorProfileInterface_IsMonitorProfileMode;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<HashInt>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_ColorProfileInterface_GetHashCode = &Hxx2::Wrapper<Hxx2::Unresolved>::_ColorProfileInterface_GetHashCode;
		#else
		tbl->_ColorProfileInterface_GetHashCode = &Hxx2::Wrapper<Hxx2::Unresolved>::_ColorProfileInterface_GetHashCode;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<ColorSpace>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_ColorProfileInterface_GetColorSpace = &Hxx2::Wrapper<Hxx2::Unresolved>::_ColorProfileInterface_GetColorSpace;
		#else
		tbl->_ColorProfileInterface_GetColorSpace = &Hxx2::Wrapper<Hxx2::Unresolved>::_ColorProfileInterface_GetColorSpace;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<String>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_ColorProfileInterface_ToString = &Hxx2::Wrapper<Hxx2::Unresolved>::_ColorProfileInterface_ToString;
		#else
		tbl->_ColorProfileInterface_ToString = &Hxx2::Wrapper<Hxx2::Unresolved>::_ColorProfileInterface_ToString;
		#endif
/// @cond INTERNAL

		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_ColorProfileInterface_SetMonitorProfileMode = &Hxx2::Wrapper<Hxx2::Unresolved>::_ColorProfileInterface_SetMonitorProfileMode;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_ColorProfileInterface_DescribeIO = &Hxx2::Wrapper<Hxx2::Unresolved>::_ColorProfileInterface_DescribeIO;
		#else
		tbl->_ColorProfileInterface_DescribeIO = &Hxx2::Wrapper<Hxx2::Unresolved>::_ColorProfileInterface_DescribeIO;
		#endif
/// @endcond

	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_interface, (maxon::Char*) tbl, _returnTypes, SIZEOF(MTable) / SIZEOF(void*));
	#else
		return true;
	#endif
	}
	MAXON_INTERFACE_REGISTER(ColorProfileInterface, "net.maxon.image.interface.colorprofile", nullptr);
	template <typename DUMMY> maxon::Int ColorProfileInterface::PrivateInstantiateNullValueHelper()
	{
		return 0
		| maxon::details::InstantiateNullReturnValue<ColorSpace>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateNullReturnValue<HashInt>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateNullReturnValue<String>(OVERLOAD_MAX_RANK)
		;
	}
	const maxon::Char* const ColorProfileConvertInterface::MTable::_ids = 
		"Free@663499d5dad7b898\0" // void Free(const ColorProfileConvertInterface* object)
		"Init@cc8aa3688cbcf0\0" // Result<ColorProfileConvert> Init(const PixelFormat& srcPixelFormat, const ColorProfile& srcProfile, const PixelFormat& dstPixelFormat, const ColorProfile& dstProfile, COLORCONVERSIONINTENT intent, COLORCONVERSIONFLAGS flags)
		"Convert@3a4e15d3a46d6181\0" // Result<void> Convert(const ImageConstBuffer& src, const ImageMutableBuffer& dst, Int cnt) const
		"GetHashCode@b22918402154097b\0" // HashInt GetHashCode() const
		"GetNearestNativeFormat@d32de2525ddc6b6b\0" // Result<PixelFormat> GetNearestNativeFormat(const PixelFormat& format)
	"";
	MAXON_WARNING_PUSH
	MAXON_WARNING_DISABLE_DEPRECATED
	class ColorProfileConvertInterface::Hxx2::Unresolved : public ColorProfileConvertInterface
	{
	public:
		static const Unresolved* Get(const ColorProfileConvertInterface* o) { return (const Unresolved*) o; }
		static Unresolved* Get(ColorProfileConvertInterface* o) { return (Unresolved*) o; }
		static void Free(const ColorProfileConvertInterface* object) { if (object && maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ColorProfileConvertInterface::Free(object); return maxon::PrivateLogNullptrError();}
		static Result<ColorProfileConvert> Init(const PixelFormat& srcPixelFormat, const ColorProfile& srcProfile, const PixelFormat& dstPixelFormat, const ColorProfile& dstProfile, COLORCONVERSIONINTENT intent, COLORCONVERSIONFLAGS flags) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ColorProfileConvertInterface::Init(srcPixelFormat, srcProfile, dstPixelFormat, dstProfile, intent, flags); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<void> Convert(const ImageConstBuffer& src, const ImageMutableBuffer& dst, Int cnt) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((const ColorProfileConvertInterface*) this)->Convert(src, dst, cnt); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		HashInt GetHashCode() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const ColorProfileConvertInterface*) this)->GetHashCode(); return maxon::PrivateIncompleteNullReturnValue<HashInt>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		static Result<PixelFormat> GetNearestNativeFormat(const PixelFormat& format) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ColorProfileConvertInterface::GetNearestNativeFormat(format); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
	};
	MAXON_WARNING_POP
#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
	const maxon::NULL_RETURN_TYPE ColorProfileConvertInterface::MTable::_returnTypes[] = 
	{
		maxon::NULL_RETURN_TYPE::VOID_ZERO_FREE_FUNCTION,
		maxon::details::NullReturnType<Result<ColorProfileConvert>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<HashInt>::value,
		maxon::details::NullReturnType<Result<PixelFormat>>::value,
		maxon::NULL_RETURN_TYPE::OTHER
	};
#endif
	maxon::Bool ColorProfileConvertInterface::MTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl)
	{
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_ColorProfileConvertInterface_Free = &Hxx2::Wrapper<Hxx2::Unresolved>::_ColorProfileConvertInterface_Free;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<ColorProfileConvert>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_ColorProfileConvertInterface_Init = &Hxx2::Wrapper<Hxx2::Unresolved>::_ColorProfileConvertInterface_Init;
		#else
		tbl->_ColorProfileConvertInterface_Init = &Hxx2::Wrapper<Hxx2::Unresolved>::_ColorProfileConvertInterface_Init;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_ColorProfileConvertInterface_Convert = &Hxx2::Wrapper<Hxx2::Unresolved>::_ColorProfileConvertInterface_Convert;
		#else
		tbl->_ColorProfileConvertInterface_Convert = &Hxx2::Wrapper<Hxx2::Unresolved>::_ColorProfileConvertInterface_Convert;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<HashInt>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_ColorProfileConvertInterface_GetHashCode = &Hxx2::Wrapper<Hxx2::Unresolved>::_ColorProfileConvertInterface_GetHashCode;
		#else
		tbl->_ColorProfileConvertInterface_GetHashCode = &Hxx2::Wrapper<Hxx2::Unresolved>::_ColorProfileConvertInterface_GetHashCode;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<PixelFormat>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_ColorProfileConvertInterface_GetNearestNativeFormat = &Hxx2::Wrapper<Hxx2::Unresolved>::_ColorProfileConvertInterface_GetNearestNativeFormat;
		#else
		tbl->_ColorProfileConvertInterface_GetNearestNativeFormat = &Hxx2::Wrapper<Hxx2::Unresolved>::_ColorProfileConvertInterface_GetNearestNativeFormat;
		#endif
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_interface, (maxon::Char*) tbl, _returnTypes, SIZEOF(MTable) / SIZEOF(void*));
	#else
		return true;
	#endif
	}
	MAXON_INTERFACE_REGISTER(ColorProfileConvertInterface, "net.maxon.image.interface.colorprofileconvert", nullptr);
	template <typename DUMMY> maxon::Int ColorProfileConvertInterface::PrivateInstantiateNullValueHelper()
	{
		return 0
		| maxon::details::InstantiateNullReturnValue<HashInt>(OVERLOAD_MAX_RANK)
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
	| maxon::ColorProfileInterface::PrivateInstantiateNullValueHelper<maxon::Int>()
	| maxon::ColorProfileConvertInterface::PrivateInstantiateNullValueHelper<maxon::Int>()
);
