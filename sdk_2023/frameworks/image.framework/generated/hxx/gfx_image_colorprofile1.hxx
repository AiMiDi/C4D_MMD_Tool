#if 1
#ifdef MAXON_TARGET_LINUX
#endif
class ColorProfile;

/// @cond INTERNAL

/// @endcond

struct ColorProfileInterface::Hxx1
{
	class Reference;
	class NonConstRef;
	using ReferenceClass = ColorProfile;
	/// Intermediate helper class for ColorProfileInterface.
	template <typename S> class ConstFn DOXYGEN_SWITCH_REVERSED(, : public S)
	{
	public:
		ConstFn() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateBaseClass::PrivateLookupFn;
		static ConstFn PrivateLookupFn(ColorProfileInterface**);
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type IsEqual(const ColorProfileInterface* other) const;
/// Create a color profile from a Url.
/// @param[in] fn									Url of the preset. This could be an icc file from the hard drive.
/// @return												A valid color profile if the operation was successful.
		static inline Result<ColorProfile> OpenProfileFromFile(const Url& fn);
/// Create a color profile from a memory block. This can be used to read the color profiles within images.
/// @param[in] mem								Memory block representing the icc color profile.
/// @return												A valid color profile if the operation was successful.
		static inline Result<ColorProfile> OpenProfileFromMemory(const Block<const Byte>& mem);
/// @markPrivate
		static inline Result<ColorProfile> CreateProfile(const OcioConfig& config, const CString& name);
/// @markPrivate, requires a virtual profile in the config.
		static inline Result<ColorProfile> CreateProfile(const OcioConfig& config, const Url& iccPath);
/// @markPrivate
		static inline Result<ColorProfile> CreateProfile(const OcioConfig& config, const CString& viewTransform, const CString& displayColorSpace);
/// @markPrivate, both profiles must be OCIO.
		static inline Result<ColorProfile> CreateProfile(const ColorProfile& viewTransform, const ColorProfile& displayColorSpace);
/// Write the current profile to memory.
/// @param[out] mem								Array which receives the memory.
/// @return												True if the function operates successful.
		inline Result<void> WriteProfileToMemory(WritableArrayInterface<Char>& mem) const;
/// Write the current profile to a file stream.
/// @param[in] fn									Name of the file/stream.
/// @return												True if the function operates successful.
		inline Result<void> WriteProfileToFile(const Url& fn) const;
/// Returns additional informations to the color profile.
/// @param[in] info								Requested information. See COLORPROFILEINFO.
/// @return												String with the information stored in the color profile.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type GetInfo(COLORPROFILEINFO info) const;
/// Returns the crc representing this color profile.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<UInt32>, UInt32>::type GetCrc() const;
/// Returns whether this object contains a valid color profile.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type HasProfile() const;
/// Check the color profile if it's compatible with the given pixel format. (e.g. if gray scale matches)
/// @return												True if the pixel format is compatible with the color profile.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type CheckCompatiblePixelFormat(const PixelFormat& pixelFormat) const;
/// Returns whether the color profile is linked to a color profile of a monitor.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type IsMonitorProfileMode() const;
/// Returns the color space for which the profile is valid.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<ColorSpace>, ColorSpace>::type GetColorSpace() const;
/// Returns a readable string of the content.
/// @param[in] formatStatement		Nullptr or additional formatting instruction. Currently no additional formatting instructions are supported.
/// @return												The converted result. By default, this is the name of the class, followed by \@, followed by the hexadecimal memory address of this object.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type ToString(const FormatStatement* formatStatement = nullptr) const;
/// Get the OCIO config for this color profile. Returns an empty OcioConfig when this is not an OCIO profile.
/// @param[out] config						The OCIO conig.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type GetOcioConfig(OcioConfig& config) const;
/// @cond INTERNAL

/// Describe all elements of this class for I/O operations.
/// @param[in] stream							The stream that is used to register the class members.
/// @return												OK on success.
		static inline Result<void> DescribeIO(const DataSerializeInterface& stream);
/// @endcond

	};
	/// Intermediate helper class for ColorProfileInterface.
	template <typename S> class Fn : public ConstFn<S>
	{
	public:
		Fn() = default;
		using PrivateBaseClass = ConstFn<S>;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateBaseClass::PrivateLookupFn;
		static Fn PrivateLookupFn(ColorProfileInterface**);
/// @cond INTERNAL

/// Private.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type SetMonitorProfileMode(Bool on) const;
/// @endcond

	};
	/// Intermediate helper class for ColorProfileInterface.
	template <typename S> class COWFn : public ConstFn<S>
	{
	public:
		COWFn() = default;
		using PrivateBaseClass = ConstFn<S>;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateBaseClass::PrivateLookupFn;
		static COWFn PrivateLookupFn(ColorProfileInterface**);
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongACOWRefHandler, ColorProfile, false>::type&() const { return reinterpret_cast<const ColorProfile&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongACOWRefHandler, ColorProfile, false>::type&() { return reinterpret_cast<const ColorProfile&>(this->GetBaseRef()); }
/// @cond INTERNAL

/// Private.
		inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Bool, maxon::Result<Bool>>::type SetMonitorProfileMode(Bool on);
/// @endcond

	};
	template <typename ST> struct FnHelper : public std::conditional<
	maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)),
	COWFn<typename ST::type>,
	typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstFn<typename ST::type>, Fn<typename ST::type>>::type
	> { };
};
class ColorProfileInterface::Hxx1::Reference :
#ifdef DOXYGEN
public COWFnDoxy<ColorProfile>
#else
public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<const ColorProfileInterface, maxon::StrongACOWRefHandler, ColorProfile>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<const ColorProfileInterface, maxon::StrongACOWRefHandler, ColorProfile>>>>);
	using NonConst = Hxx1::NonConstRef;
	static MAXON_ATTRIBUTE_FORCE_INLINE maxon::ResultMemT<ColorProfile> Create();
};

class ColorProfileInterface::Hxx1::NonConstRef :
#ifdef DOXYGEN
public COWFnDoxy<NonConstRef>
#else
public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<ColorProfileInterface, maxon::StrongACOWRefHandler, NonConstRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<ColorProfileInterface, maxon::StrongACOWRefHandler, NonConstRef>>>>);
};

/// ColorProfile is the reference class of ColorProfileInterface.
///
/// This class allows to deal with color profiles. Color profiles are used to map colors from a
/// given color space (e.g. image color space) into a destination color space (e.g. calibrated monitor).
class ColorProfile : public ColorProfileInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(ColorProfile, typename ColorProfileInterface::Hxx1::Reference);
};

class ColorProfileConvert;

struct ColorProfileConvertInterface::Hxx1
{
	class Reference;
	class NonConstRef;
	using ReferenceClass = ColorProfileConvert;
	/// Intermediate helper class for ColorProfileConvertInterface.
	template <typename S> class ConstFn DOXYGEN_SWITCH_REVERSED(, : public S)
	{
	public:
		ConstFn() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateBaseClass::PrivateLookupFn;
		static ConstFn PrivateLookupFn(ColorProfileConvertInterface**);
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, ColorProfileConvert, false>::type&() const { return reinterpret_cast<const ColorProfileConvert&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, ColorProfileConvert, false>::type&() { return reinterpret_cast<const ColorProfileConvert&>(this->GetBaseRef()); }
/// Create a new helper class to convert from srcPixelFormat to dstPixelFormat.
/// @param[in] srcPixelFormat			Source color pixel format.
/// @param[in] srcProfile					Source color profile.
/// @param[in] dstPixelFormat			Destination color profile.
/// @param[in] dstProfile					Destination color profile.
/// @param[in] intent							TODO: (Tilo) please describe.
/// @param[in] flags							TODO: (Tilo) please describe.
/// @return												A object to convert pixel data. If nullptr then there is no need to convert pixels because the profiles are identical.
		static inline Result<ColorProfileConvert> Init(const PixelFormat& srcPixelFormat, const ColorProfile& srcProfile, const PixelFormat& dstPixelFormat, const ColorProfile& dstProfile, COLORCONVERSIONINTENT intent, COLORCONVERSIONFLAGS flags);
/// Call to convert pixel data from one profile to another.
/// @param[in] src								Pointer to the memory block with the source pixel data. The pixel data needs to be in the srcPixelFormat and srcProfile (see Init).
/// @param[in] dst								Pointer to the memory block with the dest pixel data. The pixel data will be written with dstPixelFormat and dstProfile (see Init).
/// @param[in] cnt								Number of source pixels to convert.
		inline Result<void> Convert(const ImageConstBuffer& src, const ImageMutableBuffer& dst, Int cnt) const;
/// Returns the closest compatible pixel format for the given format.
/// If the pixel format is supported natively be the color conversion the given format is returned.
		static inline Result<PixelFormat> GetNearestNativeFormat(const PixelFormat& format);
/// Create a new helper class to convert from srcProfile to dstProfile on the GPU.
/// @param[in] srcProfile					Source color profile.
/// @param[in] dstProfile					Destination color profile.
/// @param[in] flags							Conversion flags.
/// @param[in] optimization				Optimization.
/// @return												The GPU converter.
		static inline Result<ColorProfileConvert> InitGPU(const ColorProfile& srcProfile, const ColorProfile& dstProfile, COLORCONVERSIONFLAGS_GPU flags, COLORCONVERSION_OPTIMIZATION_GPU_FLAGS optimization);
/// Gets the GPU handler for this color conversion.
/// @return												GPU handler for this conversion.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<ForwardRef<ColorProfileGpuHandlerRef>>, ForwardRef<ColorProfileGpuHandlerRef>>::type GetGpuHandler() const;
	};
	template <typename ST> struct FnHelper : public std::conditional<
	false, void,
	ConstFn<typename ST::type>
	> { };
};
class ColorProfileConvertInterface::Hxx1::Reference :
#ifdef DOXYGEN
public ConstFnDoxy<ColorProfileConvert>
#else
public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<const ColorProfileConvertInterface, maxon::StrongRefHandler, ColorProfileConvert>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<const ColorProfileConvertInterface, maxon::StrongRefHandler, ColorProfileConvert>>>>);
	using NonConst = Hxx1::NonConstRef;
};

class ColorProfileConvertInterface::Hxx1::NonConstRef :
#ifdef DOXYGEN
public FnDoxy<NonConstRef>
#else
public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<ColorProfileConvertInterface, maxon::StrongRefHandler, NonConstRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<ColorProfileConvertInterface, maxon::StrongRefHandler, NonConstRef>>>>);
};

/// ColorProfileConvert is the reference class of ColorProfileConvertInterface.
///
/// Helper class to convert pixel data from one color profile to another.
class ColorProfileConvert : public ColorProfileConvertInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(ColorProfileConvert, typename ColorProfileConvertInterface::Hxx1::Reference);
};

#endif
