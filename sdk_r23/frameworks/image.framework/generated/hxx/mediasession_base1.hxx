#if 1
namespace MEDIASESSION
{
#ifndef PRIVATE_MAXON_GUARD_maxon_MEDIASESSION
#define PRIVATE_MAXON_GUARD_maxon_MEDIASESSION
	class RESTRICT : public maxon::RESTRICT { }; template <typename T> RESTRICT TestRestriction(T y, maxon::OverloadRank1);
#endif
	namespace EXPORT
	{
	#ifndef PRIVATE_MAXON_GUARD_maxon_MEDIASESSION_EXPORT
	#define PRIVATE_MAXON_GUARD_maxon_MEDIASESSION_EXPORT
		class RESTRICT : public MEDIASESSION::RESTRICT { }; template <typename T> RESTRICT TestRestriction(T y, maxon::OverloadRank1);
	#endif
		namespace BASE
		{
		#ifndef PRIVATE_MAXON_GUARD_maxon_MEDIASESSION_EXPORT_BASE
		#define PRIVATE_MAXON_GUARD_maxon_MEDIASESSION_EXPORT_BASE
			class RESTRICT : public EXPORT::RESTRICT { }; template <typename T> RESTRICT TestRestriction(T y, maxon::OverloadRank1);
		#endif
		}
	}
}
namespace MEDIASTREAM
{
#ifndef PRIVATE_MAXON_GUARD_maxon_MEDIASTREAM
#define PRIVATE_MAXON_GUARD_maxon_MEDIASTREAM
	class RESTRICT : public maxon::RESTRICT { }; template <typename T> RESTRICT TestRestriction(T y, maxon::OverloadRank1);
#endif
}
namespace MEDIAFORMAT
{
#ifndef PRIVATE_MAXON_GUARD_maxon_MEDIAFORMAT
#define PRIVATE_MAXON_GUARD_maxon_MEDIAFORMAT
	class RESTRICT : public maxon::RESTRICT { }; template <typename T> RESTRICT TestRestriction(T y, maxon::OverloadRank1);
#endif
	namespace IMAGE
	{
	#ifndef PRIVATE_MAXON_GUARD_maxon_MEDIAFORMAT_IMAGE
	#define PRIVATE_MAXON_GUARD_maxon_MEDIAFORMAT_IMAGE
		class RESTRICT : public MEDIAFORMAT::RESTRICT { }; template <typename T> RESTRICT TestRestriction(T y, maxon::OverloadRank1);
	#endif
	}
	namespace IMAGELAYER
	{
	#ifndef PRIVATE_MAXON_GUARD_maxon_MEDIAFORMAT_IMAGELAYER
	#define PRIVATE_MAXON_GUARD_maxon_MEDIAFORMAT_IMAGELAYER
		class RESTRICT : public MEDIAFORMAT::RESTRICT { }; template <typename T> RESTRICT TestRestriction(T y, maxon::OverloadRank1);
	#endif
		namespace FOLDER
		{
		#ifndef PRIVATE_MAXON_GUARD_maxon_MEDIAFORMAT_IMAGELAYER_FOLDER
		#define PRIVATE_MAXON_GUARD_maxon_MEDIAFORMAT_IMAGELAYER_FOLDER
			class RESTRICT : public IMAGELAYER::RESTRICT { }; template <typename T> RESTRICT TestRestriction(T y, maxon::OverloadRank1);
		#endif
		}
		namespace ADJUSTMENT
		{
		#ifndef PRIVATE_MAXON_GUARD_maxon_MEDIAFORMAT_IMAGELAYER_ADJUSTMENT
		#define PRIVATE_MAXON_GUARD_maxon_MEDIAFORMAT_IMAGELAYER_ADJUSTMENT
			class RESTRICT : public IMAGELAYER::RESTRICT { }; template <typename T> RESTRICT TestRestriction(T y, maxon::OverloadRank1);
		#endif
		}
	}
	namespace VIDEO
	{
	#ifndef PRIVATE_MAXON_GUARD_maxon_MEDIAFORMAT_VIDEO
	#define PRIVATE_MAXON_GUARD_maxon_MEDIAFORMAT_VIDEO
		class RESTRICT : public MEDIAFORMAT::RESTRICT { }; template <typename T> RESTRICT TestRestriction(T y, maxon::OverloadRank1);
	#endif
	}
	namespace AUDIO
	{
	#ifndef PRIVATE_MAXON_GUARD_maxon_MEDIAFORMAT_AUDIO
	#define PRIVATE_MAXON_GUARD_maxon_MEDIAFORMAT_AUDIO
		class RESTRICT : public MEDIAFORMAT::RESTRICT { }; template <typename T> RESTRICT TestRestriction(T y, maxon::OverloadRank1);
	#endif
		namespace MARKER
		{
		#ifndef PRIVATE_MAXON_GUARD_maxon_MEDIAFORMAT_AUDIO_MARKER
		#define PRIVATE_MAXON_GUARD_maxon_MEDIAFORMAT_AUDIO_MARKER
			class RESTRICT : public AUDIO::RESTRICT { }; template <typename T> RESTRICT TestRestriction(T y, maxon::OverloadRank1);
		#endif
		}
	}
}
namespace MEDIAPROPERTIES
{
#ifndef PRIVATE_MAXON_GUARD_maxon_MEDIAPROPERTIES
#define PRIVATE_MAXON_GUARD_maxon_MEDIAPROPERTIES
	class RESTRICT : public maxon::RESTRICT { }; template <typename T> RESTRICT TestRestriction(T y, maxon::OverloadRank1);
#endif
	namespace VIDEO
	{
	#ifndef PRIVATE_MAXON_GUARD_maxon_MEDIAPROPERTIES_VIDEO
	#define PRIVATE_MAXON_GUARD_maxon_MEDIAPROPERTIES_VIDEO
		class RESTRICT : public MEDIAPROPERTIES::RESTRICT { }; template <typename T> RESTRICT TestRestriction(T y, maxon::OverloadRank1);
	#endif
	}
}
class MediaBaseRef;

struct MediaBaseInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, MediaBaseInterface>::value || DataDictionaryObjectInterface::HasBase::template Check<I>::value || DataDescriptionObjectInterface::HasBase::template Check<I>::value; static I* Cast(MediaBaseInterface* ptr) { return reinterpret_cast<I*>(ptr); } }; };
struct MediaBaseInterface::Hxx1
{
	class Reference;
	using ReferenceClass = MediaBaseRef;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<DataDictionaryObjectInterface, DataDescriptionObjectInterface>;
	/// Intermediate helper class for MediaBaseInterface.
	template <typename S> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
	{
	public:
		ConstReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
/// Returns the connected essionRef of this connection.
/// @return												If successful a valid MediaSessionRef will be returned.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<MediaSessionRef>, MediaSessionRef>::type GetSession() const;
	};
	/// Intermediate helper class for MediaBaseInterface.
	template <typename S> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, MediaBaseRef, true>::type&() const { return reinterpret_cast<const MediaBaseRef&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, MediaBaseRef, false>::type&() { return reinterpret_cast<const MediaBaseRef&>(this->GetBaseRef()); }
/// PRIVATE
/// @param[in] session						MediaSession to be used with this connection.
/// @return												OK on success.
		inline Result<void> ConnectToSession(const MediaSessionRef& session) const;
	};
	/// Intermediate helper class for MediaBaseInterface.
	template <typename S> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, MediaBaseRef, false>::type&() { return reinterpret_cast<const MediaBaseRef&>(this->GetBaseRef()); }
/// PRIVATE
/// @param[in] session						MediaSession to be used with this connection.
/// @return												OK on success.
		inline Result<void> ConnectToSession(const MediaSessionRef& session);
	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename DataDescriptionObjectInterface::Hxx1::template ReferenceFunctionsHelper<typename DataDictionaryObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename DataDescriptionObjectInterface::Hxx1::template ReferenceFunctionsHelper<typename DataDictionaryObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>>::type>, ReferenceFunctionsImpl<typename DataDescriptionObjectInterface::Hxx1::template ReferenceFunctionsHelper<typename DataDictionaryObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>>::type>>::type> { };
};
class MediaBaseInterface::Hxx1::Reference :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<MediaBaseRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<MediaBaseInterface, maxon::StrongRefHandler, MediaBaseRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<MediaBaseInterface, maxon::StrongRefHandler, MediaBaseRef>>>>);
	using NonConst = typename Super::ReferenceClass;
};

/// MediaBaseRef is the reference class of MediaBaseInterface.
///
/// MediaSession Base Interface. This interface is the common base for all media converter classes.
class MediaBaseRef : public MediaBaseInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(MediaBaseRef, typename MediaBaseInterface::Hxx1::Reference);
	using ConstPtr = typename MediaBaseInterface::ConstPtr;
};

#endif
