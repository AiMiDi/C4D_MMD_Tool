#if 1
class PixelFormatGroup;

struct PixelFormatGroupInterface::HasBaseDetector { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, PixelFormatGroupInterface>::value || ObjectInterface::HasBaseDetector::template Check<I>::value; static I* Cast(PixelFormatGroupInterface* ptr) { return reinterpret_cast<I*>(ptr); } }; };
struct PixelFormatGroupInterface::Hxx1
{
	class Reference;
	class NonConstRef;
	using ReferenceClass = PixelFormatGroup;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<ObjectInterface>;
	/// Intermediate helper class for PixelFormatGroupInterface.
	template <typename S> class ConstFn DOXYGEN_SWITCH_REVERSED(, : public S)
	{
	public:
		ConstFn() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateInterface = PixelFormatGroupInterface;
		using PrivateBaseClass::PrivateLookupFn;
		static ConstFn PrivateLookupFn(PixelFormatGroupInterface**);
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, PixelFormatGroup, false>::type&() const { return reinterpret_cast<const PixelFormatGroup&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, PixelFormatGroup, false>::type&() { return reinterpret_cast<const PixelFormatGroup&>(this->GetBaseRef()); }
		inline HXXADDRET2(PixelFormatIterator) GetEntries() const;
	};
	template <typename ST> struct FnHelper : public std::conditional<
	false, void,
	ConstFn<typename ObjectInterface::Hxx1::template FnHelper<ST>::type>
	> { };
};
class PixelFormatGroupInterface::Hxx1::Reference :
#ifdef DOXYGEN
public ConstFnDoxy<PixelFormatGroup>
#else
public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<const PixelFormatGroupInterface, maxon::StrongRefHandler, PixelFormatGroup>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<const PixelFormatGroupInterface, maxon::StrongRefHandler, PixelFormatGroup>>>>);
	using NonConst = Hxx1::NonConstRef;
};

class PixelFormatGroupInterface::Hxx1::NonConstRef :
#ifdef DOXYGEN
public FnDoxy<NonConstRef>
#else
public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<PixelFormatGroupInterface, maxon::StrongRefHandler, NonConstRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<PixelFormatGroupInterface, maxon::StrongRefHandler, NonConstRef>>>>);
};

/// PixelFormatGroup is the reference class of PixelFormatGroupInterface.
///
/// Every pixel format belongs to a specific group. This interface define this group.
/// The group should define a general pixel format, e.g. RGB or BGRA etc. All the different implementations for different bit depths should
/// be grouped under that group.
class PixelFormatGroup : public PixelFormatGroupInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(PixelFormatGroup, typename PixelFormatGroupInterface::Hxx1::Reference);
};

#endif
