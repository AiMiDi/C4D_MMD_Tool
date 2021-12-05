#if 1
constexpr inline const maxon::Char* DT_BlendPixelHandlerRef_CppName() { return "maxon::BlendPixelHandlerRef"; }
class ImagePixelBlend;

struct ImagePixelBlendInterface::HasBaseDetector { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, ImagePixelBlendInterface>::value || ObjectInterface::HasBaseDetector::template Check<I>::value; static I* Cast(ImagePixelBlendInterface* ptr) { return reinterpret_cast<I*>(ptr); } }; };
struct ImagePixelBlendInterface::Hxx1
{
	class Reference;
	class NonConstRef;
	using ReferenceClass = ImagePixelBlend;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<ObjectInterface>;
	/// Intermediate helper class for ImagePixelBlendInterface.
	template <typename S> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
	{
	public:
		ConstReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, ImagePixelBlend, false>::type&() const { return reinterpret_cast<const ImagePixelBlend&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, ImagePixelBlend, false>::type&() { return reinterpret_cast<const ImagePixelBlend&>(this->GetBaseRef()); }
/// GetOptimalPixelFormat returns the optimal blending PixelFormat.
/// @param[in] formats						Input formats to respect. Depending on that formats the result might change.
/// @return												Optimal blending pixel format to deliver to GetBlendPixel() function.
		static inline Result<PixelFormat> GetOptimalPixelFormat(const Block<PixelFormat>& formats);
/// GetBlendPixelHandler create a handler object to be used when conversion pixel data.
/// @param[in] bgFormat						PixelFormat for the background layer.
/// @param[in] bgChannelOffsets		Channel offsets for the background layer.
/// @param[in] fgFormat						PixelFormat for the foreground layer.
/// @param[in] fgChannelOffsets		Channel offsets for the foreground layer.
/// @param[in] opacity						Blend opacity to use.
/// @return												BlendPixelHandlerStruct on success. On that object BlendPixel() can be called to use the optimized
///																blending function for a line of pixels.
		inline Result<BlendPixelHandlerStruct> GetBlendPixelHandler(const PixelFormat& bgFormat, const ChannelOffsets& bgChannelOffsets, const PixelFormat& fgFormat, const ChannelOffsets& fgChannelOffsets, Float opacity) const;
	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<
	false, void,
	ConstReferenceFunctionsImpl<typename ObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>
	> { };
};
class ImagePixelBlendInterface::Hxx1::Reference :
#ifdef DOXYGEN
public ConstReferenceFunctionsImplDoxy<ImagePixelBlend>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const ImagePixelBlendInterface, maxon::StrongRefHandler, ImagePixelBlend>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const ImagePixelBlendInterface, maxon::StrongRefHandler, ImagePixelBlend>>>>);
	using NonConst = Hxx1::NonConstRef;
};

class ImagePixelBlendInterface::Hxx1::NonConstRef :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<NonConstRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<ImagePixelBlendInterface, maxon::StrongRefHandler, NonConstRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<ImagePixelBlendInterface, maxon::StrongRefHandler, NonConstRef>>>>);
};

/// ImagePixelBlend is the reference class of ImagePixelBlendInterface.
///
/// This class allows to implement and use pixel blending methods.
/// Each pixel blending should has it's own implementation.
/// A enumeration of all available blending methods can be found under ImagePixelBlends registry.
class ImagePixelBlend : public ImagePixelBlendInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(ImagePixelBlend, typename ImagePixelBlendInterface::Hxx1::Reference);
};

#endif
