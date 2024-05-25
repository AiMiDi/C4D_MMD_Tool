#if 1
namespace EXIFDATA
{
#ifndef PRIVATE_MAXON_GUARD_maxon_EXIFDATA
#define PRIVATE_MAXON_GUARD_maxon_EXIFDATA
	class RESTRICT : public maxon::RESTRICT { }; template <typename T> RESTRICT TestRestriction(T y, maxon::OverloadRank1);
#endif
	namespace PROPERTIES
	{
	#ifndef PRIVATE_MAXON_GUARD_maxon_EXIFDATA_PROPERTIES
	#define PRIVATE_MAXON_GUARD_maxon_EXIFDATA_PROPERTIES
		class RESTRICT : public EXIFDATA::RESTRICT { }; template <typename T> RESTRICT TestRestriction(T y, maxon::OverloadRank1);
	#endif
	}
	namespace GPS
	{
	#ifndef PRIVATE_MAXON_GUARD_maxon_EXIFDATA_GPS
	#define PRIVATE_MAXON_GUARD_maxon_EXIFDATA_GPS
		class RESTRICT : public EXIFDATA::RESTRICT { }; template <typename T> RESTRICT TestRestriction(T y, maxon::OverloadRank1);
	#endif
	}
}
class ExifRef;

struct ExifInterface::HasBaseDetector { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, ExifInterface>::value || DataDictionaryObjectInterface::HasBaseDetector::template Check<I>::value; static I* Cast(ExifInterface* ptr) { return reinterpret_cast<I*>(ptr); } }; };
struct ExifInterface::Hxx1
{
	class Reference;
	using ReferenceClass = ExifRef;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<DataDictionaryObjectInterface>;
	/// Intermediate helper class for ExifInterface.
	template <typename S> class ConstFn DOXYGEN_SWITCH_REVERSED(, : public S)
	{
	public:
		ConstFn() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateInterface = ExifInterface;
		using PrivateBaseClass::PrivateLookupFn;
		static ConstFn PrivateLookupFn(ExifInterface**);
		using RESTRICT_DICTIONARY_PROPS = ExifInterface::RESTRICT_DICTIONARY_PROPS;
/// Returns the full exif data dictionary.
/// See EXIFDATA for the properties.
		inline Result<DataDictionary> GetExifDictionary() const;
	};
	/// Intermediate helper class for ExifInterface.
	template <typename S> class Fn : public ConstFn<S>
	{
	public:
		Fn() = default;
		using PrivateBaseClass = ConstFn<S>;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateInterface = ExifInterface;
		using PrivateBaseClass::PrivateLookupFn;
		static Fn PrivateLookupFn(ExifInterface**);
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, ExifRef, true>::type&() const { return reinterpret_cast<const ExifRef&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, ExifRef, false>::type&() { return reinterpret_cast<const ExifRef&>(this->GetBaseRef()); }
	};
	/// Intermediate helper class for ExifInterface.
	template <typename S> class COWFn : public ConstFn<S>
	{
	public:
		COWFn() = default;
		using PrivateBaseClass = ConstFn<S>;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateInterface = ExifInterface;
		using PrivateBaseClass::PrivateLookupFn;
		static COWFn PrivateLookupFn(ExifInterface**);
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, ExifRef, false>::type&() { return reinterpret_cast<const ExifRef&>(this->GetBaseRef()); }
	};
	template <typename ST> struct FnHelper : public std::conditional<
	maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)),
	COWFn<typename DataDictionaryObjectInterface::Hxx1::template FnHelper<ST>::type>,
	typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstFn<typename DataDictionaryObjectInterface::Hxx1::template FnHelper<ST>::type>, Fn<typename DataDictionaryObjectInterface::Hxx1::template FnHelper<ST>::type>>::type
	> { };
};
class ExifInterface::Hxx1::Reference :
#ifdef DOXYGEN
public FnDoxy<ExifRef>
#else
public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<ExifInterface, maxon::StrongRefHandler, ExifRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<ExifInterface, maxon::StrongRefHandler, ExifRef>>>>);
	using NonConst = typename Super::ReferenceClass;
};

/// ExifRef is the reference class of ExifInterface.
///
/// This class allows to deal with EXIF chunks in image files.
class ExifRef : public ExifInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(ExifRef, typename ExifInterface::Hxx1::Reference);
	using ConstPtr = typename ExifInterface::ConstPtr;
};

namespace IMAGEBASEPROPERTIES
{
#ifndef PRIVATE_MAXON_GUARD_maxon_IMAGEBASEPROPERTIES
#define PRIVATE_MAXON_GUARD_maxon_IMAGEBASEPROPERTIES
	class RESTRICT : public maxon::RESTRICT { }; template <typename T> RESTRICT TestRestriction(T y, maxon::OverloadRank1);
#endif
}
#endif
