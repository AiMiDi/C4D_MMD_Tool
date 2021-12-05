#if 1
class PixelFormatIndexedColor;

struct PixelFormatIndexedColorInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, PixelFormatIndexedColorInterface>::value || PixelFormatInterface::HasBase::template Check<I>::value; static I* Cast(PixelFormatIndexedColorInterface* ptr) { return reinterpret_cast<I*>(ptr); } }; };
struct PixelFormatIndexedColorInterface::Hxx1
{
	class Reference;
	class NonConstRef;
	using ReferenceClass = PixelFormatIndexedColor;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<PixelFormatInterface>;
	/// Intermediate helper class for PixelFormatIndexedColorInterface.
	template <typename S> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
	{
	public:
		ConstReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
/// Returns the pixel format of the color table.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<PixelFormat>, PixelFormat>::type GetColorTablePixelFormat() const;
/// Returns the number of color entries.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type GetColorTableSize() const;
/// Returns a single color entry from the color table.
/// @param[in] idx								Index of the entry to get.
/// @param[in] dstPixelData				Destination color pointer. The color will be automatically converted into the color format provided in the dstPixelData.
/// @return												OK on success.
		inline Result<void> GetIndex(Int idx, const ImageMutableBuffer& dstPixelData) const;
	};
	/// Intermediate helper class for PixelFormatIndexedColorInterface.
	template <typename S> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
/// Initialize the pixel format with a specific number of color entries and a given pixel format for the color entries.
/// @param[in] count							Number of color entries in the table.
/// @param[in] srcFormatPtr				Pixel format of the color entries.
/// @return												OK on success.
		inline Result<void> InitColorTable(Int count, const PixelFormat& srcFormatPtr) const;
/// Sets a specific color entry.
/// @param[in] idx								Index of the entry to set.
/// @param[in] srcPixelData				Source color data. The color will be automatically converted into the color format provided in the Init function.
/// @return												OK on success.
		inline Result<void> SetIndex(Int idx, const ImageConstBuffer& srcPixelData) const;
	};
	/// Intermediate helper class for PixelFormatIndexedColorInterface.
	template <typename S> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, PixelFormatIndexedColor, false>::type&() const { return reinterpret_cast<const PixelFormatIndexedColor&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, PixelFormatIndexedColor, false>::type&() { return reinterpret_cast<const PixelFormatIndexedColor&>(this->GetBaseRef()); }
/// Initialize the pixel format with a specific number of color entries and a given pixel format for the color entries.
/// @param[in] count							Number of color entries in the table.
/// @param[in] srcFormatPtr				Pixel format of the color entries.
/// @return												OK on success.
		inline Result<void> InitColorTable(Int count, const PixelFormat& srcFormatPtr);
/// Sets a specific color entry.
/// @param[in] idx								Index of the entry to set.
/// @param[in] srcPixelData				Source color data. The color will be automatically converted into the color format provided in the Init function.
/// @return												OK on success.
		inline Result<void> SetIndex(Int idx, const ImageConstBuffer& srcPixelData);
	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename PixelFormatInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename PixelFormatInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, ReferenceFunctionsImpl<typename PixelFormatInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>>::type> { };
};
class PixelFormatIndexedColorInterface::Hxx1::Reference :
#ifdef DOXYGEN
public COWReferenceFunctionsImplDoxy<PixelFormatIndexedColor>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const PixelFormatIndexedColorInterface, maxon::StrongCOWRefHandler, PixelFormatIndexedColor>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const PixelFormatIndexedColorInterface, maxon::StrongCOWRefHandler, PixelFormatIndexedColor>>>>);
	using NonConst = Hxx1::NonConstRef;
};

class PixelFormatIndexedColorInterface::Hxx1::NonConstRef :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<NonConstRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<PixelFormatIndexedColorInterface, maxon::StrongRefHandler, NonConstRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<PixelFormatIndexedColorInterface, maxon::StrongRefHandler, NonConstRef>>>>);
};

/// PixelFormatIndexedColor is the reference class of PixelFormatIndexedColorInterface.
///
/// PixelFormatIndexedColorInterface extends the PixelFormatInterface with the ability to handle color palettes/tables.
class PixelFormatIndexedColor : public PixelFormatIndexedColorInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(PixelFormatIndexedColor, typename PixelFormatIndexedColorInterface::Hxx1::Reference);
};

#endif
