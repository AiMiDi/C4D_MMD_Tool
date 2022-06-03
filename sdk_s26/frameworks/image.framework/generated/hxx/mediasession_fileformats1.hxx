#if 1
class MediaSessionFileFormatHandler;

struct MediaSessionFileFormatHandlerInterface::HasBaseDetector { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, MediaSessionFileFormatHandlerInterface>::value || FileFormatHandlerInterface::HasBaseDetector::template Check<I>::value; static I* Cast(MediaSessionFileFormatHandlerInterface* ptr) { return reinterpret_cast<I*>(ptr); } }; };
struct MediaSessionFileFormatHandlerInterface::Hxx1
{
	class Reference;
	class NonConstRef;
	using ReferenceClass = MediaSessionFileFormatHandler;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<FileFormatHandlerInterface>;
	/// Intermediate helper class for MediaSessionFileFormatHandlerInterface.
	template <typename S> class ConstFn DOXYGEN_SWITCH_REVERSED(, : public S)
	{
	public:
		ConstFn() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateBaseClass::PrivateLookupFn;
		static ConstFn PrivateLookupFn(MediaSessionFileFormatHandlerInterface**);
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, MediaSessionFileFormatHandler, false>::type&() const { return reinterpret_cast<const MediaSessionFileFormatHandler&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, MediaSessionFileFormatHandler, false>::type&() { return reinterpret_cast<const MediaSessionFileFormatHandler&>(this->GetBaseRef()); }
	};
	template <typename ST> struct FnHelper : public std::conditional<
	false, void,
	ConstFn<typename FileFormatHandlerInterface::Hxx1::template FnHelper<ST>::type>
	> { };
};
class MediaSessionFileFormatHandlerInterface::Hxx1::Reference :
#ifdef DOXYGEN
public ConstFnDoxy<MediaSessionFileFormatHandler>
#else
public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<const MediaSessionFileFormatHandlerInterface, maxon::StrongRefHandler, MediaSessionFileFormatHandler>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<const MediaSessionFileFormatHandlerInterface, maxon::StrongRefHandler, MediaSessionFileFormatHandler>>>>);
	using NonConst = Hxx1::NonConstRef;
};

class MediaSessionFileFormatHandlerInterface::Hxx1::NonConstRef :
#ifdef DOXYGEN
public FnDoxy<NonConstRef>
#else
public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<MediaSessionFileFormatHandlerInterface, maxon::StrongRefHandler, NonConstRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<MediaSessionFileFormatHandlerInterface, maxon::StrongRefHandler, NonConstRef>>>>);
};

/// MediaSessionFileFormatHandler is the reference class of MediaSessionFileFormatHandlerInterface.
///
/// FileFormatHandlerInterface implements a handler for a specific FileFormat.
/// E.g. two different implementations could offer different loaders for one and the same FileFormat.
/// FileFormat::Zip implements one handler for Directory Browsing (IoBrowseRef) and one for ReadArchiveRef.
class MediaSessionFileFormatHandler : public MediaSessionFileFormatHandlerInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(MediaSessionFileFormatHandler, typename MediaSessionFileFormatHandlerInterface::Hxx1::Reference);
};

namespace URLFLAGS
{
#ifndef PRIVATE_MAXON_GUARD_maxon_URLFLAGS
#define PRIVATE_MAXON_GUARD_maxon_URLFLAGS
	class RESTRICT : public maxon::RESTRICT { }; template <typename T> RESTRICT TestRestriction(T y, maxon::OverloadRank1);
#endif
}
#endif
