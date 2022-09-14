#if 1
namespace CodeExchangeLanguageId
{
#ifndef PRIVATE_MAXON_GUARD_maxon_CodeExchangeLanguageId
#define PRIVATE_MAXON_GUARD_maxon_CodeExchangeLanguageId
	class RESTRICT : public maxon::RESTRICT { }; template <typename T> RESTRICT TestRestriction(T y, maxon::OverloadRank1);
#endif
}
class CodeExchangeRef;

struct CodeExchangeInterface::HasBaseDetector { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, CodeExchangeInterface>::value || ObjectInterface::HasBaseDetector::template Check<I>::value; static I* Cast(CodeExchangeInterface* ptr) { return reinterpret_cast<I*>(ptr); } }; };
struct CodeExchangeInterface::Hxx1
{
	class Reference;
	using ReferenceClass = CodeExchangeRef;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<ObjectInterface>;
	/// Intermediate helper class for CodeExchangeInterface.
	template <typename S> class ConstFn DOXYGEN_SWITCH_REVERSED(, : public S)
	{
	public:
		ConstFn() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateBaseClass::PrivateLookupFn;
		static ConstFn PrivateLookupFn(CodeExchangeInterface**);
/// Defines which language the code exchange should be used
/// @return The ID representing the used language, see maxon::CodeExchangeLanguageId
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<InternedId>, InternedId>::type GetLanguage() const;
/// Names of the Code Exchange, this will be used in the Cinema 4D preference under the extension entry.
/// @return The name of the current implementation
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type GetName() const;
	};
	/// Intermediate helper class for CodeExchangeInterface.
	template <typename S> class Fn : public ConstFn<S>
	{
	public:
		Fn() = default;
		using PrivateBaseClass = ConstFn<S>;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateBaseClass::PrivateLookupFn;
		static Fn PrivateLookupFn(CodeExchangeInterface**);
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, CodeExchangeRef, true>::type&() const { return reinterpret_cast<const CodeExchangeRef&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, CodeExchangeRef, false>::type&() { return reinterpret_cast<const CodeExchangeRef&>(this->GetBaseRef()); }
/// Called when the Code Exchange is enabled in the preference or during the startup of Cinema 4D
		inline Result<void> Start() const;
/// Called when the Code Exchange is disabled in the preference or during the ending of Cinema 4D
		inline Result<void> Stop() const;
/// Send the given Python Script to all IDE
/// @param[in] script						The Python script to send
		inline Result<void> SendScriptToIDE(const PythonElementScriptRef& script) const;
/// Send the Python Console to all IDE
/// @param[in] content						The new line in the Python logger
		inline Result<void> SendConsoleOutput(const String& content) const;
	};
	/// Intermediate helper class for CodeExchangeInterface.
	template <typename S> class COWFn : public ConstFn<S>
	{
	public:
		COWFn() = default;
		using PrivateBaseClass = ConstFn<S>;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateBaseClass::PrivateLookupFn;
		static COWFn PrivateLookupFn(CodeExchangeInterface**);
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, CodeExchangeRef, false>::type&() { return reinterpret_cast<const CodeExchangeRef&>(this->GetBaseRef()); }
/// Called when the Code Exchange is enabled in the preference or during the startup of Cinema 4D
		inline Result<void> Start();
/// Called when the Code Exchange is disabled in the preference or during the ending of Cinema 4D
		inline Result<void> Stop();
/// Send the given Python Script to all IDE
/// @param[in] script						The Python script to send
		inline Result<void> SendScriptToIDE(const PythonElementScriptRef& script);
/// Send the Python Console to all IDE
/// @param[in] content						The new line in the Python logger
		inline Result<void> SendConsoleOutput(const String& content);
	};
	template <typename ST> struct FnHelper : public std::conditional<
	maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)),
	COWFn<typename ObjectInterface::Hxx1::template FnHelper<ST>::type>,
	typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstFn<typename ObjectInterface::Hxx1::template FnHelper<ST>::type>, Fn<typename ObjectInterface::Hxx1::template FnHelper<ST>::type>>::type
	> { };
};
class CodeExchangeInterface::Hxx1::Reference :
#ifdef DOXYGEN
public FnDoxy<CodeExchangeRef>
#else
public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<CodeExchangeInterface, maxon::StrongRefHandler, CodeExchangeRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<CodeExchangeInterface, maxon::StrongRefHandler, CodeExchangeRef>>>>);
	using NonConst = typename Super::ReferenceClass;
};

/// CodeExchangeRef is the reference class of CodeExchangeInterface.
///
/// Manages communication to exchange code from Cinema 4D to IDE
class CodeExchangeRef : public CodeExchangeInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(CodeExchangeRef, typename CodeExchangeInterface::Hxx1::Reference);
	using ConstPtr = typename CodeExchangeInterface::ConstPtr;
};

#endif
