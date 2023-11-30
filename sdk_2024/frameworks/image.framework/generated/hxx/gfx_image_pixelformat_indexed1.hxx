#if 1
class PixelFormatIndexedColor;

struct PixelFormatIndexedColorInterface::HasBaseDetector { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, PixelFormatIndexedColorInterface>::value || PixelFormatInterface::HasBaseDetector::template Check<I>::value; static I* Cast(PixelFormatIndexedColorInterface* ptr) { return reinterpret_cast<I*>(ptr); } }; };
struct PixelFormatIndexedColorInterface::Hxx1
{
	class Reference;
	class NonConstRef;
	using ReferenceClass = PixelFormatIndexedColor;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<PixelFormatInterface>;
	/// Intermediate helper class for PixelFormatIndexedColorInterface.
	template <typename S> class ConstFn DOXYGEN_SWITCH_REVERSED(, : public S)
	{
	public:
		ConstFn() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateInterface = PixelFormatIndexedColorInterface;
		using PrivateBaseClass::PrivateLookupFn;
		static ConstFn PrivateLookupFn(PixelFormatIndexedColorInterface**);
/// Returns the pixel format of the color table.
		inline HXXADDRET2(PixelFormat) GetColorTablePixelFormat() const;
/// Returns the number of color entries.
		inline HXXADDRET2(Int) GetColorTableSize() const;
/// Returns a single color entry from the color table.
/// @param[in] idx								Index of the entry to get.
/// @param[in] dstPixelData				Destination color pointer. The color will be automatically converted into the color format provided in the dstPixelData.
/// @return												OK on success.
		inline Result<void> GetIndex(Int idx, const ImageMutableBuffer& dstPixelData) const;
	};
	/// Intermediate helper class for PixelFormatIndexedColorInterface.
	template <typename S> class Fn : public ConstFn<S>
	{
	public:
		Fn() = default;
		using PrivateBaseClass = ConstFn<S>;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateInterface = PixelFormatIndexedColorInterface;
		using PrivateBaseClass::PrivateLookupFn;
		static Fn PrivateLookupFn(PixelFormatIndexedColorInterface**);
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
	template <typename S> class COWFn : public ConstFn<S>
	{
	public:
		COWFn() = default;
		using PrivateBaseClass = ConstFn<S>;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateInterface = PixelFormatIndexedColorInterface;
		using PrivateBaseClass::PrivateLookupFn;
		static COWFn PrivateLookupFn(PixelFormatIndexedColorInterface**);
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
	template <typename ST> struct FnHelper : public std::conditional<
	maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)),
	COWFn<typename PixelFormatInterface::Hxx1::template FnHelper<ST>::type>,
	typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstFn<typename PixelFormatInterface::Hxx1::template FnHelper<ST>::type>, Fn<typename PixelFormatInterface::Hxx1::template FnHelper<ST>::type>>::type
	> { };
};
class PixelFormatIndexedColorInterface::Hxx1::Reference :
#ifdef DOXYGEN
public COWFnDoxy<PixelFormatIndexedColor>
#else
public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<const PixelFormatIndexedColorInterface, maxon::StrongCOWRefHandler, PixelFormatIndexedColor>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<const PixelFormatIndexedColorInterface, maxon::StrongCOWRefHandler, PixelFormatIndexedColor>>>>);
	using NonConst = Hxx1::NonConstRef;
};

class PixelFormatIndexedColorInterface::Hxx1::NonConstRef :
#ifdef DOXYGEN
public FnDoxy<NonConstRef>
#else
public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<PixelFormatIndexedColorInterface, maxon::StrongRefHandler, NonConstRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<PixelFormatIndexedColorInterface, maxon::StrongRefHandler, NonConstRef>>>>);
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
