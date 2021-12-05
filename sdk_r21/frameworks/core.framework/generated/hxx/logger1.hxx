#if 1
namespace LOGGERTYPEFLAGS
{
#ifndef PRIVATE_MAXON_GUARD_maxon_LOGGERTYPEFLAGS
#define PRIVATE_MAXON_GUARD_maxon_LOGGERTYPEFLAGS
	class RESTRICT : public maxon::RESTRICT { }; template <typename T> RESTRICT TestRestriction(T y, maxon::OverloadRank1);
#endif
}
class LoggerTypeRef;

struct LoggerTypeInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, LoggerTypeInterface>::value || ObserverObjectInterface::HasBase::template Check<I>::value || DataDictionaryObjectInterface::HasBase::template Check<I>::value; static I* Cast(LoggerTypeInterface* ptr) { return static_cast<I*>(static_cast<maxon::ObjectInterface*>(ptr)); } }; };
struct LoggerTypeInterface::Hxx1
{
	class Reference;
	using ReferenceClass = LoggerTypeRef;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<ObserverObjectInterface, DataDictionaryObjectInterface>;
	/// Intermediate helper class for LoggerTypeInterface.
	template <typename S> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
	{
	public:
		ConstReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
/// Add observer to get notified once logger type receives a string.
/// -param[in] str								The string to print. Might not contain \n if level is WRITEMETA::NONEWLINE.
/// -param[in] loc								Source location where the string entered the logger system.
/// -param[in] ta									For which audience is the string intended.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<maxon::ObservableRef<ObservableLoggerNotifyDelegate>>, maxon::ObservableRef<ObservableLoggerNotifyDelegate>>::type ObservableLoggerNotify() const;
	};
	/// Intermediate helper class for LoggerTypeInterface.
	template <typename S> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, LoggerTypeRef, true>::type&() const { return reinterpret_cast<const LoggerTypeRef&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, LoggerTypeRef, false>::type&() { return reinterpret_cast<const LoggerTypeRef&>(this->GetBaseRef()); }
/// Implement function to consume string and write to a specified destination.
/// @param[in] str								The string to print. Might not contain \n if level is WRITEMETA::NONEWLINE
/// @param[in] loc								Source location where the string entered the logger system.
/// @param[in] level							Meta flags
		inline Result<void> Write(const String& str, const SourceLocation& loc, WRITEMETA level = WRITEMETA::DEFAULT) const;
/// Implement function to flush output.
		inline Result<void> Flush() const;
	};
	/// Intermediate helper class for LoggerTypeInterface.
	template <typename S> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, LoggerTypeRef, false>::type&() { return reinterpret_cast<const LoggerTypeRef&>(this->GetBaseRef()); }
/// Implement function to consume string and write to a specified destination.
/// @param[in] str								The string to print. Might not contain \n if level is WRITEMETA::NONEWLINE
/// @param[in] loc								Source location where the string entered the logger system.
/// @param[in] level							Meta flags
		inline Result<void> Write(const String& str, const SourceLocation& loc, WRITEMETA level = WRITEMETA::DEFAULT);
/// Implement function to flush output.
		inline Result<void> Flush();
	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename DataDictionaryObjectInterface::Hxx1::template ReferenceFunctionsHelper<typename ObserverObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename DataDictionaryObjectInterface::Hxx1::template ReferenceFunctionsHelper<typename ObserverObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>>::type>, ReferenceFunctionsImpl<typename DataDictionaryObjectInterface::Hxx1::template ReferenceFunctionsHelper<typename ObserverObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>>::type>>::type> { };
};
class LoggerTypeInterface::Hxx1::Reference :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<LoggerTypeRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<LoggerTypeInterface, maxon::StrongRefHandler, LoggerTypeRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<LoggerTypeInterface, maxon::StrongRefHandler, LoggerTypeRef>>>>);
	using NonConst = typename Super::ReferenceClass;
};

/// LoggerTypeRef is the reference class of LoggerTypeInterface.
///
/// Each object of LoggerLine represents an entry in the logger with several meta information. See documentation of members for more information.
class LoggerTypeRef : public LoggerTypeInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(LoggerTypeRef, typename LoggerTypeInterface::Hxx1::Reference);
};

class LoggerTypeInterface::ObservableLoggerNotifyDelegate : public maxon::Delegate<void(const String&,WRITEMETA,TARGETAUDIENCE)>
{
public:
	using Super = maxon::Delegate<void(const String&,WRITEMETA,TARGETAUDIENCE)>;
	MAXON_MEMBERFUNCTION_DETECTOR(HandleLoggerNotify);
	ObservableLoggerNotifyDelegate() = default;
	template <typename FN> static maxon::ResultOk<Super> Create(FN&& src, typename std::enable_if<HasHandleLoggerNotify<typename maxon::Dereference<typename std::decay<FN>::type, false>::type>::value, void>::type* = nullptr) { return Super::CreateByReference(std::forward<FN>(src), &maxon::Dereference<typename std::decay<FN>::type, false>::type::HandleLoggerNotify); }
	template <typename FN> static maxon::Result<Super> Create(FN&& src, typename std::enable_if<!HasHandleLoggerNotify<typename maxon::Dereference<typename std::decay<FN>::type, false>::type>::value, void>::type* = nullptr){ return Super::Create(std::forward<FN>(src)); }
	using OBSERVABLECOMBINER = ObservableCombinerRunAllComponentPrivateHelper;
};

class FileLoggerTypeRef;

struct FileLoggerTypeInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, FileLoggerTypeInterface>::value || LoggerTypeInterface::HasBase::template Check<I>::value; static I* Cast(FileLoggerTypeInterface* ptr) { return static_cast<I*>(static_cast<maxon::ObjectInterface*>(ptr)); } }; };
struct FileLoggerTypeInterface::Hxx1
{
	class Reference;
	using ReferenceClass = FileLoggerTypeRef;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<LoggerTypeInterface>;
	/// Intermediate helper class for FileLoggerTypeInterface.
	template <typename S> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
	{
	public:
		ConstReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
/// Gets the path where the output is written to.
/// @return												The destination path.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Url>, Url>::type GetUrl() const;
	};
	/// Intermediate helper class for FileLoggerTypeInterface.
	template <typename S> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, FileLoggerTypeRef, true>::type&() const { return reinterpret_cast<const FileLoggerTypeRef&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, FileLoggerTypeRef, false>::type&() { return reinterpret_cast<const FileLoggerTypeRef&>(this->GetBaseRef()); }
/// Initialize the file logger type with a destination where it writes the output to.
/// @param[in] url								Destination path.
		inline Result<void> Init(const Url& url) const;
	};
	/// Intermediate helper class for FileLoggerTypeInterface.
	template <typename S> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, FileLoggerTypeRef, false>::type&() { return reinterpret_cast<const FileLoggerTypeRef&>(this->GetBaseRef()); }
/// Initialize the file logger type with a destination where it writes the output to.
/// @param[in] url								Destination path.
		inline Result<void> Init(const Url& url);
	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename LoggerTypeInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename LoggerTypeInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, ReferenceFunctionsImpl<typename LoggerTypeInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>>::type> { };
};
class FileLoggerTypeInterface::Hxx1::Reference :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<FileLoggerTypeRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<FileLoggerTypeInterface, maxon::StrongRefHandler, FileLoggerTypeRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<FileLoggerTypeInterface, maxon::StrongRefHandler, FileLoggerTypeRef>>>>);
	using NonConst = typename Super::ReferenceClass;
};

/// FileLoggerTypeRef is the reference class of FileLoggerTypeInterface.
///
/// Interface of a file logger type.
class FileLoggerTypeRef : public FileLoggerTypeInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(FileLoggerTypeRef, typename FileLoggerTypeInterface::Hxx1::Reference);
};

class UserLoggerTypeRef;

struct UserLoggerTypeInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, UserLoggerTypeInterface>::value || LoggerTypeInterface::HasBase::template Check<I>::value; static I* Cast(UserLoggerTypeInterface* ptr) { return static_cast<I*>(static_cast<maxon::ObjectInterface*>(ptr)); } }; };
struct UserLoggerTypeInterface::Hxx1
{
	class Reference;
	using ReferenceClass = UserLoggerTypeRef;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<LoggerTypeInterface>;
	/// Intermediate helper class for UserLoggerTypeInterface.
	template <typename S> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
	{
	public:
		ConstReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
	};
	/// Intermediate helper class for UserLoggerTypeInterface.
	template <typename S> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, UserLoggerTypeRef, true>::type&() const { return reinterpret_cast<const UserLoggerTypeRef&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, UserLoggerTypeRef, false>::type&() { return reinterpret_cast<const UserLoggerTypeRef&>(this->GetBaseRef()); }
/// Iterates over all caches lines since it got initialized or resetted.
/// @param[in] callback						Delegate which is called for each line.
		inline Result<void> Iterate(const Delegate<Result<void>(LoggerLine&)>& callback) const;
/// Gets the count of entries.
/// @return												Line count.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type GetCount() const;
/// Clears the cache of this logger type.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type Reset() const;
	};
	/// Intermediate helper class for UserLoggerTypeInterface.
	template <typename S> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, UserLoggerTypeRef, false>::type&() { return reinterpret_cast<const UserLoggerTypeRef&>(this->GetBaseRef()); }
/// Iterates over all caches lines since it got initialized or resetted.
/// @param[in] callback						Delegate which is called for each line.
		inline Result<void> Iterate(const Delegate<Result<void>(LoggerLine&)>& callback);
/// Gets the count of entries.
/// @return												Line count.
		inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Int, maxon::Result<Int>>::type GetCount();
/// Clears the cache of this logger type.
		inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type Reset();
	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename LoggerTypeInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename LoggerTypeInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, ReferenceFunctionsImpl<typename LoggerTypeInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>>::type> { };
};
class UserLoggerTypeInterface::Hxx1::Reference :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<UserLoggerTypeRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<UserLoggerTypeInterface, maxon::StrongRefHandler, UserLoggerTypeRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<UserLoggerTypeInterface, maxon::StrongRefHandler, UserLoggerTypeRef>>>>);
	using NonConst = typename Super::ReferenceClass;
};

/// UserLoggerTypeRef is the reference class of UserLoggerTypeInterface.
///
/// Interface of a logger type which prints to the application console. Caches all strings until it gets resetted.
class UserLoggerTypeRef : public UserLoggerTypeInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(UserLoggerTypeRef, typename UserLoggerTypeInterface::Hxx1::Reference);
};

class LoggerRef;

struct LoggerInterface::Hxx1
{
	class Reference;
	using ReferenceClass = LoggerRef;
	/// Intermediate helper class for LoggerInterface.
	template <typename S> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
	{
	public:
		ConstReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		using LOGGERTYPEINITCALLBACK = LoggerInterface::LOGGERTYPEINITCALLBACK;
/// Returns the name of the logger.
/// @return												The name.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type GetName() const;
/// Returns all logger types including their audience.
/// @return												An array of pairs with logger types and the audience.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<BaseArray<Pair<LoggerTypeRef, TARGETAUDIENCE>>>, BaseArray<Pair<LoggerTypeRef, TARGETAUDIENCE>>>::type GetLoggerTypes() const;
/// Add observer to get notified once a new logger got added.
/// -param[in] logger							The new logger
		static inline maxon::ObservableRef<ObservableLoggerNewDelegate> ObservableLoggerNew();
/// Add a new logger to the system. Does the same as Loggers::Insert, but also triggers the observers
/// @param[in] module							The module which initiates the call. When the module is freed, the logger will be freed too.
/// @return												An array of pairs with logger types and the audience.
		static inline Result<void> AddNewLogger(const Id& id, const LoggerRef& logger, const maxon::ModuleInfo* module = &PRIVATE_MAXON_MODULE);
	};
	/// Intermediate helper class for LoggerInterface.
	template <typename S> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, LoggerRef, true>::type&() const { return reinterpret_cast<const LoggerRef&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, LoggerRef, false>::type&() { return reinterpret_cast<const LoggerRef&>(this->GetBaseRef()); }
/// Adds a logger type to the logger.
/// @param[in] ta									Set the audience. The logger type will get the string if the target audience matches when LoggerInterface::Write is used.
/// @param[in] loggerTypeCls			Class object of logger type ref (e.g. maxon::LoggerTypes::Application())
/// @param[in] cb									Optional callback that is executed to initialize a logger type after added to the logger. E.g. the file logger needs to be initialized with a destination path.
		inline Result<void> AddLoggerType(TARGETAUDIENCE ta, const Class<LoggerTypeRef>& loggerTypeCls, const LOGGERTYPEINITCALLBACK& cb = DefaultLoggerTypeInit) const;
/// Removes a logger type from a logger. Also succeeds if the logger type was not part of the logger.
		inline Result<void> RemoveLoggerType(LoggerTypeRef& loggerType) const;
/// Removes all logger types of the passed type.
/// @param[in] loggerTypeCls			All logger types with the passed class type will be removed.
		inline Result<void> RemoveLoggerTypes(const Class<LoggerTypeRef>& loggerTypeCls) const;
/// Sends a string to all added logger types.
/// @param[in] ta									All logger types which match the target audience will receive the string.
/// @param[in] str								String to print.
/// @param[in] loc								Source location where the string was printed from.
/// @param[in] level							Meta information for the current write operation.
		inline Result<void> Write(TARGETAUDIENCE ta, const String& str, const maxon::SourceLocation& loc, WRITEMETA level = WRITEMETA::DEFAULT) const;
/// Sets the name of the logger.
/// @param[in] name								The name.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type SetName(const String& name) const;
/// Enable or disable the logger. If disabled, the logger still consumes strings but discards them.
/// @param[in] enable							True or false to enable or disable the logger.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type Enable(Bool enable) const;
/// Returns if the logger is enabled.
/// @return												True or false.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type IsEnabled() const;
	};
	/// Intermediate helper class for LoggerInterface.
	template <typename S> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, LoggerRef, false>::type&() { return reinterpret_cast<const LoggerRef&>(this->GetBaseRef()); }
	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename ST::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename ST::type>, ReferenceFunctionsImpl<typename ST::type>>::type> { };
};
class LoggerInterface::Hxx1::Reference :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<LoggerRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<LoggerInterface, maxon::StrongRefHandler, LoggerRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<LoggerInterface, maxon::StrongRefHandler, LoggerRef>>>>);
	using NonConst = typename Super::ReferenceClass;
/// Allocates a logger.
	static MAXON_ATTRIBUTE_FORCE_INLINE maxon::ResultMemT<LoggerRef> Create();
};

/// LoggerRef is the reference class of LoggerInterface.
class LoggerRef : public LoggerInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(LoggerRef, typename LoggerInterface::Hxx1::Reference);
};

class LoggerInterface::ObservableLoggerNewDelegate : public maxon::Delegate<void(const LoggerRef&)>
{
public:
	using Super = maxon::Delegate<void(const LoggerRef&)>;
	MAXON_MEMBERFUNCTION_DETECTOR(HandleLoggerNew);
	ObservableLoggerNewDelegate() = default;
	template <typename FN> static maxon::ResultOk<Super> Create(FN&& src, typename std::enable_if<HasHandleLoggerNew<typename maxon::Dereference<typename std::decay<FN>::type, false>::type>::value, void>::type* = nullptr) { return Super::CreateByReference(std::forward<FN>(src), &maxon::Dereference<typename std::decay<FN>::type, false>::type::HandleLoggerNew); }
	template <typename FN> static maxon::Result<Super> Create(FN&& src, typename std::enable_if<!HasHandleLoggerNew<typename maxon::Dereference<typename std::decay<FN>::type, false>::type>::value, void>::type* = nullptr){ return Super::Create(std::forward<FN>(src)); }
	using OBSERVABLECOMBINER = ObservableCombinerRunAllComponentPrivateHelper;
};

#endif
