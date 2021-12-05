#if 1
constexpr inline const maxon::Char* DT_Pix16f_CppName() { return "maxon::Pix16f"; }
class ImageChannelType;

struct ImageChannelTypeInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, ImageChannelTypeInterface>::value || ObjectInterface::HasBase::template Check<I>::value; static I* Cast(ImageChannelTypeInterface* ptr) { return reinterpret_cast<I*>(ptr); } }; };
struct ImageChannelTypeInterface::Hxx1
{
	class Reference;
	class NonConstRef;
	using ReferenceClass = ImageChannelType;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<ObjectInterface>;
	/// Intermediate helper class for ImageChannelTypeInterface.
	template <typename S> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
	{
	public:
		ConstReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, ImageChannelType, false>::type&() const { return reinterpret_cast<const ImageChannelType&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, ImageChannelType, false>::type&() { return reinterpret_cast<const ImageChannelType&>(this->GetBaseRef()); }
/// Returns the default fill value for this type of channel. (e.g. Alpha returns 255 but other channel types may return 0).
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Pix8u>, Pix8u>::type GetDefaultFillValue() const;
/// Returns the color space to which the channel type belongs to.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<ColorSpace>, ColorSpace>::type GetColorSpace() const;
/// Returns the ImageChannel for the given data type.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<ImageChannel>, ImageChannel>::type GetChannel(const DataType& pixelType) const;
/// Returns the ImageChannel for the given data type.
		template <typename PIXELDEPTH> inline typename std::conditional<S::HAS_ERROR, maxon::Result<ImageChannel>, ImageChannel>::type GetChannel() const;
	};
	/// Intermediate helper class for ImageChannelTypeInterface.
	template <typename S> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
	};
	/// Intermediate helper class for ImageChannelTypeInterface.
	template <typename S> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename ObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename ObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, ReferenceFunctionsImpl<typename ObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>>::type> { };
};
class ImageChannelTypeInterface::Hxx1::Reference :
#ifdef DOXYGEN
public ConstReferenceFunctionsImplDoxy<ImageChannelType>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const ImageChannelTypeInterface, maxon::StrongRefHandler, ImageChannelType>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const ImageChannelTypeInterface, maxon::StrongRefHandler, ImageChannelType>>>>);
	using NonConst = Hxx1::NonConstRef;
};

class ImageChannelTypeInterface::Hxx1::NonConstRef :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<NonConstRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<ImageChannelTypeInterface, maxon::StrongRefHandler, NonConstRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<ImageChannelTypeInterface, maxon::StrongRefHandler, NonConstRef>>>>);
};

/// ImageChannelType is the reference class of ImageChannelTypeInterface.
///
/// ImageChannelTypes define how a pixel channel should be interpreted.
class ImageChannelType : public ImageChannelTypeInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(ImageChannelType, typename ImageChannelTypeInterface::Hxx1::Reference);
};

class ImageChannel;

struct ImageChannelInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, ImageChannelInterface>::value || ObjectInterface::HasBase::template Check<I>::value; static I* Cast(ImageChannelInterface* ptr) { return reinterpret_cast<I*>(ptr); } }; };
struct ImageChannelInterface::Hxx1
{
	class Reference;
	class NonConstRef;
	using ReferenceClass = ImageChannel;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<ObjectInterface>;
	/// Intermediate helper class for ImageChannelInterface.
	template <typename S> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
	{
	public:
		ConstReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, ImageChannel, false>::type&() const { return reinterpret_cast<const ImageChannel&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, ImageChannel, false>::type&() { return reinterpret_cast<const ImageChannel&>(this->GetBaseRef()); }
/// Returns the size in bits of each component.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<BITS>, BITS>::type GetChannelBits() const;
/// Returns true if the channel is a alpha channel.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<ImageChannelType>, ImageChannelType>::type GetChannelType() const;
/// Returns the data type of the pixel format.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<const DataType&>, const DataType&>::type GetDataType() const;
/// Compares two components.
/// @param[in] a									Component buffer 1.
/// @param[in] b									Component buffer 2.
/// @param[in] oneTolerance				Pixel difference related to 0..255 range.
/// @return												Returns true is the pixel is within the given tolerance.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type IsIdenticalComponent(const void* a, const void* b, Int oneTolerance) const;
	};
	/// Intermediate helper class for ImageChannelInterface.
	template <typename S> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
	};
	/// Intermediate helper class for ImageChannelInterface.
	template <typename S> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename ObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename ObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, ReferenceFunctionsImpl<typename ObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>>::type> { };
};
class ImageChannelInterface::Hxx1::Reference :
#ifdef DOXYGEN
public ConstReferenceFunctionsImplDoxy<ImageChannel>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const ImageChannelInterface, maxon::StrongRefHandler, ImageChannel>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const ImageChannelInterface, maxon::StrongRefHandler, ImageChannel>>>>);
	using NonConst = Hxx1::NonConstRef;
};

class ImageChannelInterface::Hxx1::NonConstRef :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<NonConstRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<ImageChannelInterface, maxon::StrongRefHandler, NonConstRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<ImageChannelInterface, maxon::StrongRefHandler, NonConstRef>>>>);
};

/// ImageChannel is the reference class of ImageChannelInterface.
class ImageChannel : public ImageChannelInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(ImageChannel, typename ImageChannelInterface::Hxx1::Reference);
};

#endif
