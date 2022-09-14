#if 1
class CommandDataRef;

struct CommandDataInterface::HasBaseDetector { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, CommandDataInterface>::value || DataDictionaryObjectInterface::HasBaseDetector::template Check<I>::value; static I* Cast(CommandDataInterface* ptr) { return reinterpret_cast<I*>(ptr); } }; };
struct CommandDataInterface::Hxx1
{
	class Reference;
	using ReferenceClass = CommandDataRef;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<DataDictionaryObjectInterface>;
	/// Intermediate helper class for CommandDataInterface.
	template <typename S> class Fn : public S
	{
	public:
		Fn() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateBaseClass::PrivateLookupFn;
		static Fn PrivateLookupFn(CommandDataInterface**);
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, CommandDataRef, true>::type&() const { return reinterpret_cast<const CommandDataRef&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, CommandDataRef, false>::type&() { return reinterpret_cast<const CommandDataRef&>(this->GetBaseRef()); }
/// Invokes a command on this data.
/// @param[in] command						The command ID.
/// @param[in] interactive 				If true the command execution will be prepared for interactivity. The executed command must implement CommandInteractionClassInterface.
/// @return 											The command result or an error.
		inline Result<COMMANDRESULT> Invoke(const Id& command, Bool interactive) const;
/// Invokes a command on this data.
/// @param[in] command						The command class.
/// @param[in] interactive				If true the command execution will be prepared for interactivity. The executed command must implement CommandInteractionClassInterface.
/// @return												The command result or an error.
		inline Result<COMMANDRESULT> Invoke(const CommandClass& command, Bool interactive) const;
/// Invokes a command on this data.
/// @param[in] command						The command ID.
/// @param[in] interactive 				If true, the command execution will be prepared for interactivity. The executed command must implement CommandInteractionClassInterface.
/// @param[in] setParameters 			A delegate to fill the CommandData with command parameters.
/// @return 											The command result, or an error.
		inline Result<COMMANDRESULT> Invoke(const Id& command, Bool interactive, const SetParameters& setParameters) const;
/// Invokes a command on this data.
/// @param[in] command						The command class.
/// @param[in] interactive				If true, the command execution will be prepared for interactivity. The executed command must implement CommandInteractionClassInterface.
/// @param[in] setParameters 			A delegate to fill the CommandData with command parameters.
/// @return												The command result, or an error.
		inline Result<COMMANDRESULT> Invoke(const CommandClass& command, Bool interactive, const SetParameters& setParameters) const;
/// Interact with the command result on this data. An interactive command must be called before this method is used.
/// @param[in] interactionType		Define the kind of interaction, see INTERACTIONTYPE.
/// @return												The command result or an error.
		inline Result<COMMANDRESULT> Interact(INTERACTIONTYPE interactionType) const;
		template <typename... ARGS> inline Result<COMMANDRESULT> Invoke(const CommandClass& command, Bool interactive, ARGS&&... args) const;
	};
	/// Intermediate helper class for CommandDataInterface.
	template <typename S> class COWFn : public S
	{
	public:
		COWFn() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateBaseClass::PrivateLookupFn;
		static COWFn PrivateLookupFn(CommandDataInterface**);
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, CommandDataRef, false>::type&() { return reinterpret_cast<const CommandDataRef&>(this->GetBaseRef()); }
/// Invokes a command on this data.
/// @param[in] command						The command ID.
/// @param[in] interactive 				If true the command execution will be prepared for interactivity. The executed command must implement CommandInteractionClassInterface.
/// @return 											The command result or an error.
		inline Result<COMMANDRESULT> Invoke(const Id& command, Bool interactive);
/// Invokes a command on this data.
/// @param[in] command						The command class.
/// @param[in] interactive				If true the command execution will be prepared for interactivity. The executed command must implement CommandInteractionClassInterface.
/// @return												The command result or an error.
		inline Result<COMMANDRESULT> Invoke(const CommandClass& command, Bool interactive);
/// Invokes a command on this data.
/// @param[in] command						The command ID.
/// @param[in] interactive 				If true, the command execution will be prepared for interactivity. The executed command must implement CommandInteractionClassInterface.
/// @param[in] setParameters 			A delegate to fill the CommandData with command parameters.
/// @return 											The command result, or an error.
		inline Result<COMMANDRESULT> Invoke(const Id& command, Bool interactive, const SetParameters& setParameters);
/// Invokes a command on this data.
/// @param[in] command						The command class.
/// @param[in] interactive				If true, the command execution will be prepared for interactivity. The executed command must implement CommandInteractionClassInterface.
/// @param[in] setParameters 			A delegate to fill the CommandData with command parameters.
/// @return												The command result, or an error.
		inline Result<COMMANDRESULT> Invoke(const CommandClass& command, Bool interactive, const SetParameters& setParameters);
/// Interact with the command result on this data. An interactive command must be called before this method is used.
/// @param[in] interactionType		Define the kind of interaction, see INTERACTIONTYPE.
/// @return												The command result or an error.
		inline Result<COMMANDRESULT> Interact(INTERACTIONTYPE interactionType);
		template <typename... ARGS> inline Result<COMMANDRESULT> Invoke(const CommandClass& command, Bool interactive, ARGS&&... args);
	};
	template <typename ST> struct FnHelper : public std::conditional<
	maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)),
	COWFn<typename DataDictionaryObjectInterface::Hxx1::template FnHelper<ST>::type>,
	typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, typename DataDictionaryObjectInterface::Hxx1::template FnHelper<ST>::type, Fn<typename DataDictionaryObjectInterface::Hxx1::template FnHelper<ST>::type>>::type
	> { };
};
class CommandDataInterface::Hxx1::Reference :
#ifdef DOXYGEN
public FnDoxy<CommandDataRef>
#else
public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<CommandDataInterface, maxon::StrongRefHandler, CommandDataRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<CommandDataInterface, maxon::StrongRefHandler, CommandDataRef>>>>);
	using NonConst = typename Super::ReferenceClass;
};

/// CommandDataRef is the reference class of CommandDataInterface.
///
/// Base command data interface as a simple data dictionary.
/// It contains all the data and necessary functions to executed and interact with commands.
class CommandDataRef : public CommandDataInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(CommandDataRef, typename CommandDataInterface::Hxx1::Reference);
	using ConstPtr = typename CommandDataInterface::ConstPtr;
};

class LegacyCommandDataRef;

struct LegacyCommandDataInterface::HasBaseDetector { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, LegacyCommandDataInterface>::value || CommandDataInterface::HasBaseDetector::template Check<I>::value; static I* Cast(LegacyCommandDataInterface* ptr) { return reinterpret_cast<I*>(ptr); } }; };
struct LegacyCommandDataInterface::Hxx1
{
	class Reference;
	using ReferenceClass = LegacyCommandDataRef;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<CommandDataInterface>;
	/// Intermediate helper class for LegacyCommandDataInterface.
	template <typename S> class ConstFn DOXYGEN_SWITCH_REVERSED(, : public S)
	{
	public:
		ConstFn() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateBaseClass::PrivateLookupFn;
		static ConstFn PrivateLookupFn(LegacyCommandDataInterface**);
/// Count of legacy data entries.
/// @return												Reference to the legacy data at index.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type GetLegacyDataCount() const;
	};
	/// Intermediate helper class for LegacyCommandDataInterface.
	template <typename S> class Fn : public ConstFn<S>
	{
	public:
		Fn() = default;
		using PrivateBaseClass = ConstFn<S>;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateBaseClass::PrivateLookupFn;
		static Fn PrivateLookupFn(LegacyCommandDataInterface**);
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, LegacyCommandDataRef, true>::type&() const { return reinterpret_cast<const LegacyCommandDataRef&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, LegacyCommandDataRef, false>::type&() { return reinterpret_cast<const LegacyCommandDataRef&>(this->GetBaseRef()); }
/// Returns a pointer to the legacy data at index.
/// @param[in] index							The data index.
/// @return												A pointer to the legacy data at the specified index. The memory ownership depends on the implementation.
		inline Result<Generic*> GetLegacyData(Int index) const;
/// Sets legacy data from a data pointer at index.
/// @param[in] data								The legacy data pointer. The memory ownership depends on the implementation.
/// @param[in] index							The data index.
/// @return												OK on success at index.
		inline Result<void> SetLegacyData(const Generic* data, Int index) const;
/// Sets legacy data from a data reference at index.
/// @tparam LEGACYDATA						The type of legacy data.
/// @param[in] data								The data.
/// @param[in] index							The data index.
/// #return 											OK on success.
		template <typename LEGACYDATA> inline Result<void> SetLegacyData(const LEGACYDATA& data, Int index) const;
/// Gets a legacy data reference at index.
/// @tparam LEGACYDATA						The data type that will be returned.
/// @param[in] index							The data index.
/// @return												Reference to the legacy data at index.
		template <typename LEGACYDATA> inline Result<LEGACYDATA&> GetLegacyData(Int index) const;
	};
	/// Intermediate helper class for LegacyCommandDataInterface.
	template <typename S> class COWFn : public ConstFn<S>
	{
	public:
		COWFn() = default;
		using PrivateBaseClass = ConstFn<S>;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateBaseClass::PrivateLookupFn;
		static COWFn PrivateLookupFn(LegacyCommandDataInterface**);
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, LegacyCommandDataRef, false>::type&() { return reinterpret_cast<const LegacyCommandDataRef&>(this->GetBaseRef()); }
/// Returns a pointer to the legacy data at index.
/// @param[in] index							The data index.
/// @return												A pointer to the legacy data at the specified index. The memory ownership depends on the implementation.
		inline Result<Generic*> GetLegacyData(Int index);
/// Sets legacy data from a data pointer at index.
/// @param[in] data								The legacy data pointer. The memory ownership depends on the implementation.
/// @param[in] index							The data index.
/// @return												OK on success at index.
		inline Result<void> SetLegacyData(const Generic* data, Int index);
/// Sets legacy data from a data reference at index.
/// @tparam LEGACYDATA						The type of legacy data.
/// @param[in] data								The data.
/// @param[in] index							The data index.
/// #return 											OK on success.
		template <typename LEGACYDATA> inline Result<void> SetLegacyData(const LEGACYDATA& data, Int index);
/// Gets a legacy data reference at index.
/// @tparam LEGACYDATA						The data type that will be returned.
/// @param[in] index							The data index.
/// @return												Reference to the legacy data at index.
		template <typename LEGACYDATA> inline Result<LEGACYDATA&> GetLegacyData(Int index);
	};
	template <typename ST> struct FnHelper : public std::conditional<
	maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)),
	COWFn<typename CommandDataInterface::Hxx1::template FnHelper<ST>::type>,
	typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstFn<typename CommandDataInterface::Hxx1::template FnHelper<ST>::type>, Fn<typename CommandDataInterface::Hxx1::template FnHelper<ST>::type>>::type
	> { };
};
class LegacyCommandDataInterface::Hxx1::Reference :
#ifdef DOXYGEN
public FnDoxy<LegacyCommandDataRef>
#else
public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<LegacyCommandDataInterface, maxon::StrongRefHandler, LegacyCommandDataRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<LegacyCommandDataInterface, maxon::StrongRefHandler, LegacyCommandDataRef>>>>);
	using NonConst = typename Super::ReferenceClass;
};

/// LegacyCommandDataRef is the reference class of LegacyCommandDataInterface.
///
/// Legacy command data interface: a data dictionary which holds one or more pointers to generic data used to store legacy data types.
class LegacyCommandDataRef : public LegacyCommandDataInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(LegacyCommandDataRef, typename LegacyCommandDataInterface::Hxx1::Reference);
	using ConstPtr = typename LegacyCommandDataInterface::ConstPtr;
};

class CommandClass;

struct CommandClassInterface::HasBaseDetector { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, CommandClassInterface>::value || ObjectInterface::HasBaseDetector::template Check<I>::value; static I* Cast(CommandClassInterface* ptr) { return reinterpret_cast<I*>(ptr); } }; };
struct CommandClassInterface::Hxx1
{
	class Reference;
	class NonConstRef;
	using ReferenceClass = CommandClass;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<ObjectInterface>;
	/// Intermediate helper class for CommandClassInterface.
	template <typename S> class ConstFn DOXYGEN_SWITCH_REVERSED(, : public S)
	{
	public:
		ConstFn() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateBaseClass::PrivateLookupFn;
		static ConstFn PrivateLookupFn(CommandClassInterface**);
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, CommandClass, false>::type&() const { return reinterpret_cast<const CommandClass&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, CommandClass, false>::type&() { return reinterpret_cast<const CommandClass&>(this->GetBaseRef()); }
/// Gets the command state, i.e. if it can be executed or not depending on a given data.
/// @param[in,out] data						The command data.
/// @return												The command state or an error.
		inline Result<COMMANDSTATE> GetState(CommandDataRef& data) const;
/// Executes the command.
/// @param[in,out] data						The command data.
/// @return												The command result or an error.
		inline Result<COMMANDRESULT> Execute(CommandDataRef& data) const;
	};
	template <typename ST> struct FnHelper : public std::conditional<
	false, void,
	ConstFn<typename ObjectInterface::Hxx1::template FnHelper<ST>::type>
	> { };
};
class CommandClassInterface::Hxx1::Reference :
#ifdef DOXYGEN
public ConstFnDoxy<CommandClass>
#else
public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<const CommandClassInterface, maxon::StrongRefHandler, CommandClass>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<const CommandClassInterface, maxon::StrongRefHandler, CommandClass>>>>);
	using NonConst = Hxx1::NonConstRef;
};

class CommandClassInterface::Hxx1::NonConstRef :
#ifdef DOXYGEN
public FnDoxy<NonConstRef>
#else
public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<CommandClassInterface, maxon::StrongRefHandler, NonConstRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<CommandClassInterface, maxon::StrongRefHandler, NonConstRef>>>>);
};

/// CommandClass is the reference class of CommandClassInterface.
///
/// Generic command interface.
class CommandClass : public CommandClassInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(CommandClass, typename CommandClassInterface::Hxx1::Reference);
};

class CommandInteractionClass;

struct CommandInteractionClassInterface::HasBaseDetector { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, CommandInteractionClassInterface>::value || ObjectInterface::HasBaseDetector::template Check<I>::value; static I* Cast(CommandInteractionClassInterface* ptr) { return reinterpret_cast<I*>(ptr); } }; };
struct CommandInteractionClassInterface::Hxx1
{
	class Reference;
	class NonConstRef;
	using ReferenceClass = CommandInteractionClass;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<ObjectInterface>;
	/// Intermediate helper class for CommandInteractionClassInterface.
	template <typename S> class ConstFn DOXYGEN_SWITCH_REVERSED(, : public S)
	{
	public:
		ConstFn() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateBaseClass::PrivateLookupFn;
		static ConstFn PrivateLookupFn(CommandInteractionClassInterface**);
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, CommandInteractionClass, false>::type&() const { return reinterpret_cast<const CommandInteractionClass&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, CommandInteractionClass, false>::type&() { return reinterpret_cast<const CommandInteractionClass&>(this->GetBaseRef()); }
/// Executes the command interaction.
/// @param[in,out] data						The command data.
/// @param[in] interactionType		The interaction type.
/// @return												The command result or an error.
		inline Result<COMMANDRESULT> Interact(CommandDataRef& data, INTERACTIONTYPE interactionType) const;
	};
	template <typename ST> struct FnHelper : public std::conditional<
	false, void,
	ConstFn<typename ObjectInterface::Hxx1::template FnHelper<ST>::type>
	> { };
};
class CommandInteractionClassInterface::Hxx1::Reference :
#ifdef DOXYGEN
public ConstFnDoxy<CommandInteractionClass>
#else
public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<const CommandInteractionClassInterface, maxon::StrongRefHandler, CommandInteractionClass>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<const CommandInteractionClassInterface, maxon::StrongRefHandler, CommandInteractionClass>>>>);
	using NonConst = Hxx1::NonConstRef;
};

class CommandInteractionClassInterface::Hxx1::NonConstRef :
#ifdef DOXYGEN
public FnDoxy<NonConstRef>
#else
public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<CommandInteractionClassInterface, maxon::StrongRefHandler, NonConstRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<CommandInteractionClassInterface, maxon::StrongRefHandler, NonConstRef>>>>);
};

/// CommandInteractionClass is the reference class of CommandInteractionClassInterface.
///
/// Implements the command interactivity. Optional.
class CommandInteractionClass : public CommandInteractionClassInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(CommandInteractionClass, typename CommandInteractionClassInterface::Hxx1::Reference);
};

class CommandDescriptionClass;

struct CommandDescriptionClassInterface::HasBaseDetector { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, CommandDescriptionClassInterface>::value || DataDictionaryReferenceObjectInterface::HasBaseDetector::template Check<I>::value || DataDescriptionObjectInterface::HasBaseDetector::template Check<I>::value; static I* Cast(CommandDescriptionClassInterface* ptr) { return reinterpret_cast<I*>(ptr); } }; };
struct CommandDescriptionClassInterface::Hxx1
{
	class Reference;
	class NonConstRef;
	using ReferenceClass = CommandDescriptionClass;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<DataDictionaryReferenceObjectInterface, DataDescriptionObjectInterface>;
	/// Intermediate helper class for CommandDescriptionClassInterface.
	template <typename S> class ConstFn DOXYGEN_SWITCH_REVERSED(, : public S)
	{
	public:
		ConstFn() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateBaseClass::PrivateLookupFn;
		static ConstFn PrivateLookupFn(CommandDescriptionClassInterface**);
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, CommandDescriptionClass, false>::type&() const { return reinterpret_cast<const CommandDescriptionClass&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, CommandDescriptionClass, false>::type&() { return reinterpret_cast<const CommandDescriptionClass&>(this->GetBaseRef()); }
	};
	template <typename ST> struct FnHelper : public std::conditional<
	false, void,
	ConstFn<typename DataDescriptionObjectInterface::Hxx1::template FnHelper<typename DataDictionaryReferenceObjectInterface::Hxx1::template FnHelper<ST>>::type>
	> { };
};
class CommandDescriptionClassInterface::Hxx1::Reference :
#ifdef DOXYGEN
public ConstFnDoxy<CommandDescriptionClass>
#else
public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<const CommandDescriptionClassInterface, maxon::StrongRefHandler, CommandDescriptionClass>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<const CommandDescriptionClassInterface, maxon::StrongRefHandler, CommandDescriptionClass>>>>);
	using NonConst = Hxx1::NonConstRef;
};

class CommandDescriptionClassInterface::Hxx1::NonConstRef :
#ifdef DOXYGEN
public FnDoxy<NonConstRef>
#else
public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<CommandDescriptionClassInterface, maxon::StrongRefHandler, NonConstRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<CommandDescriptionClassInterface, maxon::StrongRefHandler, NonConstRef>>>>);
};

/// CommandDescriptionClass is the reference class of CommandDescriptionClassInterface.
class CommandDescriptionClass : public CommandDescriptionClassInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(CommandDescriptionClass, typename CommandDescriptionClassInterface::Hxx1::Reference);
};

class LegacyCommandClass;

struct LegacyCommandClassInterface::HasBaseDetector { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, LegacyCommandClassInterface>::value || CommandClassInterface::HasBaseDetector::template Check<I>::value; static I* Cast(LegacyCommandClassInterface* ptr) { return reinterpret_cast<I*>(ptr); } }; };
struct LegacyCommandClassInterface::Hxx1
{
	class Reference;
	class NonConstRef;
	using ReferenceClass = LegacyCommandClass;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<CommandClassInterface>;
	/// Intermediate helper class for LegacyCommandClassInterface.
	template <typename S> class ConstFn DOXYGEN_SWITCH_REVERSED(, : public S)
	{
	public:
		ConstFn() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateBaseClass::PrivateLookupFn;
		static ConstFn PrivateLookupFn(LegacyCommandClassInterface**);
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, LegacyCommandClass, false>::type&() const { return reinterpret_cast<const LegacyCommandClass&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, LegacyCommandClass, false>::type&() { return reinterpret_cast<const LegacyCommandClass&>(this->GetBaseRef()); }
/// Converts legacy settings (e.g. from a BaseContainer) to regular data parameters.
/// @param[in,out] data						The command data.
/// @return												OK on success.
		inline Result<void> ConvertSettings(LegacyCommandDataRef& data) const;
	};
	template <typename ST> struct FnHelper : public std::conditional<
	false, void,
	ConstFn<typename CommandClassInterface::Hxx1::template FnHelper<ST>::type>
	> { };
};
class LegacyCommandClassInterface::Hxx1::Reference :
#ifdef DOXYGEN
public ConstFnDoxy<LegacyCommandClass>
#else
public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<const LegacyCommandClassInterface, maxon::StrongRefHandler, LegacyCommandClass>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<const LegacyCommandClassInterface, maxon::StrongRefHandler, LegacyCommandClass>>>>);
	using NonConst = Hxx1::NonConstRef;
};

class LegacyCommandClassInterface::Hxx1::NonConstRef :
#ifdef DOXYGEN
public FnDoxy<NonConstRef>
#else
public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<LegacyCommandClassInterface, maxon::StrongRefHandler, NonConstRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<LegacyCommandClassInterface, maxon::StrongRefHandler, NonConstRef>>>>);
};

/// LegacyCommandClass is the reference class of LegacyCommandClassInterface.
///
/// A legacy command interface that implements the ability to convert legacy data settings to regular settings.
class LegacyCommandClass : public LegacyCommandClassInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(LegacyCommandClass, typename LegacyCommandClassInterface::Hxx1::Reference);
};

class MigratedCommandClass;

struct MigratedCommandClassInterface::HasBaseDetector { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, MigratedCommandClassInterface>::value || LegacyCommandClassInterface::HasBaseDetector::template Check<I>::value; static I* Cast(MigratedCommandClassInterface* ptr) { return reinterpret_cast<I*>(ptr); } }; };
struct MigratedCommandClassInterface::Hxx1
{
	class Reference;
	class NonConstRef;
	using ReferenceClass = MigratedCommandClass;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<LegacyCommandClassInterface>;
	/// Intermediate helper class for MigratedCommandClassInterface.
	template <typename S> class ConstFn DOXYGEN_SWITCH_REVERSED(, : public S)
	{
	public:
		ConstFn() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateBaseClass::PrivateLookupFn;
		static ConstFn PrivateLookupFn(MigratedCommandClassInterface**);
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, MigratedCommandClass, false>::type&() const { return reinterpret_cast<const MigratedCommandClass&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, MigratedCommandClass, false>::type&() { return reinterpret_cast<const MigratedCommandClass&>(this->GetBaseRef()); }
/// Returns the legacy migrated command id. Used for the global command table registration.
/// @return												The command plugin id.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Int32>, Int32>::type GetMigratedCommandId() const;
	};
	template <typename ST> struct FnHelper : public std::conditional<
	false, void,
	ConstFn<typename LegacyCommandClassInterface::Hxx1::template FnHelper<ST>::type>
	> { };
};
class MigratedCommandClassInterface::Hxx1::Reference :
#ifdef DOXYGEN
public ConstFnDoxy<MigratedCommandClass>
#else
public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<const MigratedCommandClassInterface, maxon::StrongRefHandler, MigratedCommandClass>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<const MigratedCommandClassInterface, maxon::StrongRefHandler, MigratedCommandClass>>>>);
	using NonConst = Hxx1::NonConstRef;
};

class MigratedCommandClassInterface::Hxx1::NonConstRef :
#ifdef DOXYGEN
public FnDoxy<NonConstRef>
#else
public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<MigratedCommandClassInterface, maxon::StrongRefHandler, NonConstRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<MigratedCommandClassInterface, maxon::StrongRefHandler, NonConstRef>>>>);
};

/// MigratedCommandClass is the reference class of MigratedCommandClassInterface.
///
/// A specialized legacy command interface for migrated commands.
/// Private.
class MigratedCommandClass : public MigratedCommandClassInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(MigratedCommandClass, typename MigratedCommandClassInterface::Hxx1::Reference);
};

class CommandConversionClass;

struct CommandConversionClassInterface::HasBaseDetector { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, CommandConversionClassInterface>::value || ObjectInterface::HasBaseDetector::template Check<I>::value; static I* Cast(CommandConversionClassInterface* ptr) { return reinterpret_cast<I*>(ptr); } }; };
struct CommandConversionClassInterface::Hxx1
{
	class Reference;
	class NonConstRef;
	using ReferenceClass = CommandConversionClass;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<ObjectInterface>;
	/// Intermediate helper class for CommandConversionClassInterface.
	template <typename S> class ConstFn DOXYGEN_SWITCH_REVERSED(, : public S)
	{
	public:
		ConstFn() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateBaseClass::PrivateLookupFn;
		static ConstFn PrivateLookupFn(CommandConversionClassInterface**);
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, CommandConversionClass, false>::type&() const { return reinterpret_cast<const CommandConversionClass&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, CommandConversionClass, false>::type&() { return reinterpret_cast<const CommandConversionClass&>(this->GetBaseRef()); }
		inline Result<void> ConvertInput(LegacyCommandDataRef& data) const;
		inline Result<void> ExecuteCustomActions(LegacyCommandDataRef& data, Int actionId, Int flags) const;
		inline Result<void> ConvertOutput(LegacyCommandDataRef& data) const;
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Int32>, Int32>::type GetLegacyCommandId() const;
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Id>, Id>::type GetCommandId() const;
	};
	template <typename ST> struct FnHelper : public std::conditional<
	false, void,
	ConstFn<typename ObjectInterface::Hxx1::template FnHelper<ST>::type>
	> { };
};
class CommandConversionClassInterface::Hxx1::Reference :
#ifdef DOXYGEN
public ConstFnDoxy<CommandConversionClass>
#else
public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<const CommandConversionClassInterface, maxon::StrongRefHandler, CommandConversionClass>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<const CommandConversionClassInterface, maxon::StrongRefHandler, CommandConversionClass>>>>);
	using NonConst = Hxx1::NonConstRef;
};

class CommandConversionClassInterface::Hxx1::NonConstRef :
#ifdef DOXYGEN
public FnDoxy<NonConstRef>
#else
public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<CommandConversionClassInterface, maxon::StrongRefHandler, NonConstRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<CommandConversionClassInterface, maxon::StrongRefHandler, NonConstRef>>>>);
};

/// CommandConversionClass is the reference class of CommandConversionClassInterface.
///
/// Implements for command the conversions action.
class CommandConversionClass : public CommandConversionClassInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(CommandConversionClass, typename CommandConversionClassInterface::Hxx1::Reference);
};

constexpr inline const maxon::Char* DT_CommandCacheData_CppName() { return "maxon::CommandCacheData"; }
constexpr inline const maxon::Char* DT_CommandCacheMap_CppName() { return "maxon::CommandCacheMap"; }
class CommandCacheRef;

struct CommandCacheInterface::HasBaseDetector { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, CommandCacheInterface>::value || ObjectInterface::HasBaseDetector::template Check<I>::value; static I* Cast(CommandCacheInterface* ptr) { return reinterpret_cast<I*>(ptr); } }; };
struct CommandCacheInterface::Hxx1
{
	class Reference;
	using ReferenceClass = CommandCacheRef;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<ObjectInterface>;
	/// Intermediate helper class for CommandCacheInterface.
	template <typename S> class Fn : public S
	{
	public:
		Fn() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateBaseClass::PrivateLookupFn;
		static Fn PrivateLookupFn(CommandCacheInterface**);
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, CommandCacheRef, true>::type&() const { return reinterpret_cast<const CommandCacheRef&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, CommandCacheRef, false>::type&() { return reinterpret_cast<const CommandCacheRef&>(this->GetBaseRef()); }
		inline Result<void> Init(CommandDataRef& data) const;
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type Reset() const;
	};
	/// Intermediate helper class for CommandCacheInterface.
	template <typename S> class COWFn : public S
	{
	public:
		COWFn() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateBaseClass::PrivateLookupFn;
		static COWFn PrivateLookupFn(CommandCacheInterface**);
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, CommandCacheRef, false>::type&() { return reinterpret_cast<const CommandCacheRef&>(this->GetBaseRef()); }
		inline Result<void> Init(CommandDataRef& data);
		inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type Reset();
	};
	template <typename ST> struct FnHelper : public std::conditional<
	maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)),
	COWFn<typename ObjectInterface::Hxx1::template FnHelper<ST>::type>,
	typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, typename ObjectInterface::Hxx1::template FnHelper<ST>::type, Fn<typename ObjectInterface::Hxx1::template FnHelper<ST>::type>>::type
	> { };
};
class CommandCacheInterface::Hxx1::Reference :
#ifdef DOXYGEN
public FnDoxy<CommandCacheRef>
#else
public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<CommandCacheInterface, maxon::StrongRefHandler, CommandCacheRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<CommandCacheInterface, maxon::StrongRefHandler, CommandCacheRef>>>>);
	using NonConst = typename Super::ReferenceClass;
};

/// CommandCacheRef is the reference class of CommandCacheInterface.
///
/// Implements cached informations for a command.
/// Private.
class CommandCacheRef : public CommandCacheInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(CommandCacheRef, typename CommandCacheInterface::Hxx1::Reference);
	using ConstPtr = typename CommandCacheInterface::ConstPtr;
};

namespace COMMAND
{
#ifndef PRIVATE_MAXON_GUARD_maxon_COMMAND
#define PRIVATE_MAXON_GUARD_maxon_COMMAND
	class RESTRICT : public maxon::RESTRICT { }; template <typename T> RESTRICT TestRestriction(T y, maxon::OverloadRank1);
#endif
}
#endif
