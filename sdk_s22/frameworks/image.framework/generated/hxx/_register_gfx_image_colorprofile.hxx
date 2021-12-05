#if 1
namespace maxon
{
	namespace enum26 { enum class COLORPROFILEINFO
	{
		DESCRIPTION		= 0,	///< Description of the color profile.
		MANUFACTURER	= 1,	///< Manufacturer of the color profile.
		MODEL					= 2,	///< Model of the color profile.
		COPYRIGHT			= 3		///< Copyright informations of the color profile.
	} ; }
	maxon::String PrivateToString_COLORPROFILEINFO26(std::underlying_type<enum26::COLORPROFILEINFO>::type x, const maxon::FormatStatement* fmt)
	{
		const maxon::UInt64 values[] = {(maxon::UInt64) enum26::COLORPROFILEINFO::DESCRIPTION, (maxon::UInt64) enum26::COLORPROFILEINFO::MANUFACTURER, (maxon::UInt64) enum26::COLORPROFILEINFO::MODEL, (maxon::UInt64) enum26::COLORPROFILEINFO::COPYRIGHT};
		return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "COLORPROFILEINFO", SIZEOF(x), false, values, "DESCRIPTION\0MANUFACTURER\0MODEL\0COPYRIGHT\0", fmt);
	}
	namespace enum56 { enum class COLORCONVERSIONINTENT
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
	} ; }
	maxon::String PrivateToString_COLORCONVERSIONINTENT56(std::underlying_type<enum56::COLORCONVERSIONINTENT>::type x, const maxon::FormatStatement* fmt)
	{
		const maxon::UInt64 values[] = {(maxon::UInt64) enum56::COLORCONVERSIONINTENT::PERCEPTUAL, (maxon::UInt64) enum56::COLORCONVERSIONINTENT::RELATIVE_COLORIMETRIC, (maxon::UInt64) enum56::COLORCONVERSIONINTENT::SATURATION, (maxon::UInt64) enum56::COLORCONVERSIONINTENT::ABSOLUTE_COLORIMETRIC};
		return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "COLORCONVERSIONINTENT", SIZEOF(x), false, values, "PERCEPTUAL\0RELATIVE_COLORIMETRIC\0SATURATION\0ABSOLUTE_COLORIMETRIC\0", fmt);
	}
	namespace enum74 { enum class COLORCONVERSIONFLAGS
	{
		NONE = 0,
	
		/// Black Point Compensation (BPC) controls whether to adjust for differences in black points when
		/// converting colors between color spaces. When Black Point Compensation is enabled, color
		/// transforms map white to white and luminance of black to luminance of black. The black point
		/// compensation feature does work better in conjunction with relative colorimetric intent.
		/// Perceptual intent should make no difference, although it may affect some (wrong) profiles.
		BLACKPOINTCOMPENSATION = (1 << 0)
	
	} ; }
	maxon::String PrivateToString_COLORCONVERSIONFLAGS74(std::underlying_type<enum74::COLORCONVERSIONFLAGS>::type x, const maxon::FormatStatement* fmt)
	{
		const maxon::UInt64 values[] = {(maxon::UInt64) enum74::COLORCONVERSIONFLAGS::NONE, (maxon::UInt64) enum74::COLORCONVERSIONFLAGS::BLACKPOINTCOMPENSATION};
		return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "COLORCONVERSIONFLAGS", SIZEOF(x), true, values, "NONE\0BLACKPOINTCOMPENSATION\0", fmt);
	}
/// @cond INTERNAL

/// @endcond

	const maxon::Char* const ColorProfileInterface::MTable::_ids = 
		"Free@f25f06284b132b00\0" // void Free(const ColorProfileInterface* object)
		"Alloc@dbf30b3cb73112e7\0" // ColorProfileInterface* Alloc(const maxon::SourceLocation& allocLocation)
		"Alloc@df28a3beb7f17043\0" // ColorProfileInterface* Alloc(const maxon::SourceLocation& allocLocation, const ColorProfileInterface& object)
		"IsEqual@67d23f9db907160d\0" // Bool IsEqual(const ColorProfileInterface* other) const
		"OpenProfileFromFile@3ca7157bee86f0a5\0" // Result<ColorProfile> OpenProfileFromFile(const Url& fn)
		"OpenProfileFromMemory@1fcf01b89ff26120\0" // Result<ColorProfile> OpenProfileFromMemory(const Block<const Byte>& mem)
		"WriteProfileToMemory@cf9ff16a6c561bf8\0" // Result<void> WriteProfileToMemory(WritableArrayInterface<Char>& mem) const
		"WriteProfileToFile@5b3e46c920933bce\0" // Result<void> WriteProfileToFile(const Url& fn) const
		"GetInfo@56a93fa2deef8854\0" // String GetInfo(COLORPROFILEINFO info) const
		"GetCrc@230559a7570\0" // UInt32 GetCrc() const
		"HasProfile@76f01901\0" // Bool HasProfile() const
		"CheckCompatiblePixelFormat@084541bdb251b29b\0" // Bool CheckCompatiblePixelFormat(const PixelFormat& pixelFormat) const
		"IsMonitorProfileMode@76f01901\0" // Bool IsMonitorProfileMode() const
		"GetHashCode@95445951\0" // UInt GetHashCode() const
		"GetColorSpace@18edbd6218df033a\0" // ColorSpace GetColorSpace() const
		"ToString@7de9f6f51c89c899\0" // String ToString(const FormatStatement* formatStatement) const
/// @cond INTERNAL

		"SetMonitorProfileMode@3610ee730ce3\0" // Bool SetMonitorProfileMode(Bool on)
		"DescribeIO@0c0a05550eef0455\0" // Result<void> DescribeIO(const DataSerializeInterface& stream)
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
		UInt GetHashCode() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const ColorProfileInterface*) this)->GetHashCode(); return 0;}
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
		maxon::details::NullReturnType<UInt>::value,
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
		| maxon::details::InstantiateNullReturnValue<String>(OVERLOAD_MAX_RANK)
		;
	}
	const maxon::Char* const ColorProfileConvertInterface::MTable::_ids = 
		"Free@6ead4f4c84d6cdf1\0" // void Free(const ColorProfileConvertInterface* object)
		"Init@2ef1465da385b4ab\0" // Result<ColorProfileConvert> Init(const PixelFormat& srcPixelFormat, const ColorProfile& srcProfile, const PixelFormat& dstPixelFormat, const ColorProfile& dstProfile, COLORCONVERSIONINTENT intent, COLORCONVERSIONFLAGS flags)
		"Convert@c57452225070f4bc\0" // Result<void> Convert(const ImageConstBuffer& src, const ImageMutableBuffer& dst, Int cnt) const
		"GetHashCode@95445951\0" // UInt GetHashCode() const
		"GetNearestNativeFormat@a6fe5f8755af277a\0" // Result<PixelFormat> GetNearestNativeFormat(const PixelFormat& format)
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
		UInt GetHashCode() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const ColorProfileConvertInterface*) this)->GetHashCode(); return 0;}
		static Result<PixelFormat> GetNearestNativeFormat(const PixelFormat& format) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ColorProfileConvertInterface::GetNearestNativeFormat(format); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
	};
	MAXON_WARNING_POP
#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
	const maxon::NULL_RETURN_TYPE ColorProfileConvertInterface::MTable::_returnTypes[] = 
	{
		maxon::NULL_RETURN_TYPE::VOID_ZERO_FREE_FUNCTION,
		maxon::details::NullReturnType<Result<ColorProfileConvert>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<UInt>::value,
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
);
