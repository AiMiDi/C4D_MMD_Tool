#if 1
class CommandDataRef;

struct CommandDataInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, CommandDataInterface>::value || DataDictionaryObjectInterface::HasBase::template Check<I>::value; static I* Cast(CommandDataInterface* ptr) { return reinterpret_cast<I*>(ptr); } }; };
struct CommandDataInterface::Hxx1
{
	class Reference;
	using ReferenceClass = CommandDataRef;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<DataDictionaryObjectInterface>;
	/// Intermediate helper class for CommandDataInterface.
	template <typename S> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
	{
	public:
		ConstReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		using SetParameters = CommandDataInterface::SetParameters;
		using SetFunctor = CommandDataInterface::SetFunctor;
	};
	/// Intermediate helper class for CommandDataInterface.
	template <typename S> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
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
	template <typename S> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
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
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename DataDictionaryObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename DataDictionaryObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, ReferenceFunctionsImpl<typename DataDictionaryObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>>::type> { };
};
class CommandDataInterface::Hxx1::Reference :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<CommandDataRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<CommandDataInterface, maxon::StrongRefHandler, CommandDataRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<CommandDataInterface, maxon::StrongRefHandler, CommandDataRef>>>>);
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

struct LegacyCommandDataInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, LegacyCommandDataInterface>::value || CommandDataInterface::HasBase::template Check<I>::value; static I* Cast(LegacyCommandDataInterface* ptr) { return reinterpret_cast<I*>(ptr); } }; };
struct LegacyCommandDataInterface::Hxx1
{
	class Reference;
	using ReferenceClass = LegacyCommandDataRef;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<CommandDataInterface>;
	/// Intermediate helper class for LegacyCommandDataInterface.
	template <typename S> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
	{
	public:
		ConstReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
/// Count of legacy data entries.
/// @return												Reference to the legacy data at index.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type GetLegacyDataCount() const;
	};
	/// Intermediate helper class for LegacyCommandDataInterface.
	template <typename S> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
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
	template <typename S> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
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
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename CommandDataInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename CommandDataInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, ReferenceFunctionsImpl<typename CommandDataInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>>::type> { };
};
class LegacyCommandDataInterface::Hxx1::Reference :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<LegacyCommandDataRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<LegacyCommandDataInterface, maxon::StrongRefHandler, LegacyCommandDataRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<LegacyCommandDataInterface, maxon::StrongRefHandler, LegacyCommandDataRef>>>>);
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

struct CommandClassInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, CommandClassInterface>::value || ObjectInterface::HasBase::template Check<I>::value; static I* Cast(CommandClassInterface* ptr) { return reinterpret_cast<I*>(ptr); } }; };
struct CommandClassInterface::Hxx1
{
	class Reference;
	class NonConstRef;
	using ReferenceClass = CommandClass;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<ObjectInterface>;
	/// Intermediate helper class for CommandClassInterface.
	template <typename S> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
	{
	public:
		ConstReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
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
	/// Intermediate helper class for CommandClassInterface.
	template <typename S> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
	};
	/// Intermediate helper class for CommandClassInterface.
	template <typename S> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename ObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename ObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, ReferenceFunctionsImpl<typename ObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>>::type> { };
};
class CommandClassInterface::Hxx1::Reference :
#ifdef DOXYGEN
public ConstReferenceFunctionsImplDoxy<CommandClass>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const CommandClassInterface, maxon::StrongRefHandler, CommandClass>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const CommandClassInterface, maxon::StrongRefHandler, CommandClass>>>>);
	using NonConst = Hxx1::NonConstRef;
};

class CommandClassInterface::Hxx1::NonConstRef :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<NonConstRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<CommandClassInterface, maxon::StrongRefHandler, NonConstRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<CommandClassInterface, maxon::StrongRefHandler, NonConstRef>>>>);
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

struct CommandInteractionClassInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, CommandInteractionClassInterface>::value || ObjectInterface::HasBase::template Check<I>::value; static I* Cast(CommandInteractionClassInterface* ptr) { return reinterpret_cast<I*>(ptr); } }; };
struct CommandInteractionClassInterface::Hxx1
{
	class Reference;
	class NonConstRef;
	using ReferenceClass = CommandInteractionClass;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<ObjectInterface>;
	/// Intermediate helper class for CommandInteractionClassInterface.
	template <typename S> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
	{
	public:
		ConstReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, CommandInteractionClass, false>::type&() const { return reinterpret_cast<const CommandInteractionClass&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, CommandInteractionClass, false>::type&() { return reinterpret_cast<const CommandInteractionClass&>(this->GetBaseRef()); }
/// Executes the command interaction.
/// @param[in,out] data						The command data.
/// @param[in] interactionType		The interaction type.
/// @return												The command result or an error.
		inline Result<COMMANDRESULT> Interact(CommandDataRef& data, INTERACTIONTYPE interactionType) const;
	};
	/// Intermediate helper class for CommandInteractionClassInterface.
	template <typename S> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
	};
	/// Intermediate helper class for CommandInteractionClassInterface.
	template <typename S> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename ObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename ObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, ReferenceFunctionsImpl<typename ObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>>::type> { };
};
class CommandInteractionClassInterface::Hxx1::Reference :
#ifdef DOXYGEN
public ConstReferenceFunctionsImplDoxy<CommandInteractionClass>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const CommandInteractionClassInterface, maxon::StrongRefHandler, CommandInteractionClass>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const CommandInteractionClassInterface, maxon::StrongRefHandler, CommandInteractionClass>>>>);
	using NonConst = Hxx1::NonConstRef;
};

class CommandInteractionClassInterface::Hxx1::NonConstRef :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<NonConstRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<CommandInteractionClassInterface, maxon::StrongRefHandler, NonConstRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<CommandInteractionClassInterface, maxon::StrongRefHandler, NonConstRef>>>>);
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

struct CommandDescriptionClassInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, CommandDescriptionClassInterface>::value || DataDictionaryReferenceObjectInterface::HasBase::template Check<I>::value || DataDescriptionObjectInterface::HasBase::template Check<I>::value; static I* Cast(CommandDescriptionClassInterface* ptr) { return reinterpret_cast<I*>(ptr); } }; };
struct CommandDescriptionClassInterface::Hxx1
{
	class Reference;
	class NonConstRef;
	using ReferenceClass = CommandDescriptionClass;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<DataDictionaryReferenceObjectInterface, DataDescriptionObjectInterface>;
	/// Intermediate helper class for CommandDescriptionClassInterface.
	template <typename S> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
	{
	public:
		ConstReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, CommandDescriptionClass, false>::type&() const { return reinterpret_cast<const CommandDescriptionClass&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, CommandDescriptionClass, false>::type&() { return reinterpret_cast<const CommandDescriptionClass&>(this->GetBaseRef()); }
		inline Result<void> SetContext(CommandDataRef& data) const;
	};
	/// Intermediate helper class for CommandDescriptionClassInterface.
	template <typename S> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
	};
	/// Intermediate helper class for CommandDescriptionClassInterface.
	template <typename S> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename DataDescriptionObjectInterface::Hxx1::template ReferenceFunctionsHelper<typename DataDictionaryReferenceObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename DataDescriptionObjectInterface::Hxx1::template ReferenceFunctionsHelper<typename DataDictionaryReferenceObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>>::type>, ReferenceFunctionsImpl<typename DataDescriptionObjectInterface::Hxx1::template ReferenceFunctionsHelper<typename DataDictionaryReferenceObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>>::type>>::type> { };
};
class CommandDescriptionClassInterface::Hxx1::Reference :
#ifdef DOXYGEN
public ConstReferenceFunctionsImplDoxy<CommandDescriptionClass>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const CommandDescriptionClassInterface, maxon::StrongRefHandler, CommandDescriptionClass>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const CommandDescriptionClassInterface, maxon::StrongRefHandler, CommandDescriptionClass>>>>);
	using NonConst = Hxx1::NonConstRef;
};

class CommandDescriptionClassInterface::Hxx1::NonConstRef :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<NonConstRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<CommandDescriptionClassInterface, maxon::StrongRefHandler, NonConstRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<CommandDescriptionClassInterface, maxon::StrongRefHandler, NonConstRef>>>>);
};

/// CommandDescriptionClass is the reference class of CommandDescriptionClassInterface.
class CommandDescriptionClass : public CommandDescriptionClassInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(CommandDescriptionClass, typename CommandDescriptionClassInterface::Hxx1::Reference);
};

class LegacyCommandClass;

struct LegacyCommandClassInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, LegacyCommandClassInterface>::value || CommandClassInterface::HasBase::template Check<I>::value; static I* Cast(LegacyCommandClassInterface* ptr) { return reinterpret_cast<I*>(ptr); } }; };
struct LegacyCommandClassInterface::Hxx1
{
	class Reference;
	class NonConstRef;
	using ReferenceClass = LegacyCommandClass;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<CommandClassInterface>;
	/// Intermediate helper class for LegacyCommandClassInterface.
	template <typename S> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
	{
	public:
		ConstReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, LegacyCommandClass, false>::type&() const { return reinterpret_cast<const LegacyCommandClass&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, LegacyCommandClass, false>::type&() { return reinterpret_cast<const LegacyCommandClass&>(this->GetBaseRef()); }
/// Converts legacy settings (e.g. from a BaseContainer) to regular data parameters.
/// @param[in,out] data						The command data.
/// @return												OK on success.
		inline Result<void> ConvertSettings(LegacyCommandDataRef& data) const;
	};
	/// Intermediate helper class for LegacyCommandClassInterface.
	template <typename S> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
	};
	/// Intermediate helper class for LegacyCommandClassInterface.
	template <typename S> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename CommandClassInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename CommandClassInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, ReferenceFunctionsImpl<typename CommandClassInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>>::type> { };
};
class LegacyCommandClassInterface::Hxx1::Reference :
#ifdef DOXYGEN
public ConstReferenceFunctionsImplDoxy<LegacyCommandClass>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const LegacyCommandClassInterface, maxon::StrongRefHandler, LegacyCommandClass>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const LegacyCommandClassInterface, maxon::StrongRefHandler, LegacyCommandClass>>>>);
	using NonConst = Hxx1::NonConstRef;
};

class LegacyCommandClassInterface::Hxx1::NonConstRef :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<NonConstRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<LegacyCommandClassInterface, maxon::StrongRefHandler, NonConstRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<LegacyCommandClassInterface, maxon::StrongRefHandler, NonConstRef>>>>);
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

struct MigratedCommandClassInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, MigratedCommandClassInterface>::value || LegacyCommandClassInterface::HasBase::template Check<I>::value; static I* Cast(MigratedCommandClassInterface* ptr) { return reinterpret_cast<I*>(ptr); } }; };
struct MigratedCommandClassInterface::Hxx1
{
	class Reference;
	class NonConstRef;
	using ReferenceClass = MigratedCommandClass;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<LegacyCommandClassInterface>;
	/// Intermediate helper class for MigratedCommandClassInterface.
	template <typename S> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
	{
	public:
		ConstReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, MigratedCommandClass, false>::type&() const { return reinterpret_cast<const MigratedCommandClass&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, MigratedCommandClass, false>::type&() { return reinterpret_cast<const MigratedCommandClass&>(this->GetBaseRef()); }
/// Returns the legacy migrated command id. Used for the global command table registration.
/// @return												The command plugin id.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Int32>, Int32>::type GetMigratedCommandId() const;
	};
	/// Intermediate helper class for MigratedCommandClassInterface.
	template <typename S> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
	};
	/// Intermediate helper class for MigratedCommandClassInterface.
	template <typename S> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename LegacyCommandClassInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename LegacyCommandClassInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, ReferenceFunctionsImpl<typename LegacyCommandClassInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>>::type> { };
};
class MigratedCommandClassInterface::Hxx1::Reference :
#ifdef DOXYGEN
public ConstReferenceFunctionsImplDoxy<MigratedCommandClass>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const MigratedCommandClassInterface, maxon::StrongRefHandler, MigratedCommandClass>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const MigratedCommandClassInterface, maxon::StrongRefHandler, MigratedCommandClass>>>>);
	using NonConst = Hxx1::NonConstRef;
};

class MigratedCommandClassInterface::Hxx1::NonConstRef :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<NonConstRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<MigratedCommandClassInterface, maxon::StrongRefHandler, NonConstRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<MigratedCommandClassInterface, maxon::StrongRefHandler, NonConstRef>>>>);
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

struct CommandConversionClassInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, CommandConversionClassInterface>::value || ObjectInterface::HasBase::template Check<I>::value; static I* Cast(CommandConversionClassInterface* ptr) { return reinterpret_cast<I*>(ptr); } }; };
struct CommandConversionClassInterface::Hxx1
{
	class Reference;
	class NonConstRef;
	using ReferenceClass = CommandConversionClass;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<ObjectInterface>;
	/// Intermediate helper class for CommandConversionClassInterface.
	template <typename S> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
	{
	public:
		ConstReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, CommandConversionClass, false>::type&() const { return reinterpret_cast<const CommandConversionClass&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, CommandConversionClass, false>::type&() { return reinterpret_cast<const CommandConversionClass&>(this->GetBaseRef()); }
		inline Result<void> ConvertInput(LegacyCommandDataRef& data) const;
		inline Result<void> ExecuteCustomActions(LegacyCommandDataRef& data, Int actionId, Int flags) const;
		inline Result<void> ConvertOutput(LegacyCommandDataRef& data) const;
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Int32>, Int32>::type GetLegacyCommandId() const;
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Id>, Id>::type GetCommandId() const;
	};
	/// Intermediate helper class for CommandConversionClassInterface.
	template <typename S> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
	};
	/// Intermediate helper class for CommandConversionClassInterface.
	template <typename S> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename ObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename ObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, ReferenceFunctionsImpl<typename ObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>>::type> { };
};
class CommandConversionClassInterface::Hxx1::Reference :
#ifdef DOXYGEN
public ConstReferenceFunctionsImplDoxy<CommandConversionClass>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const CommandConversionClassInterface, maxon::StrongRefHandler, CommandConversionClass>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const CommandConversionClassInterface, maxon::StrongRefHandler, CommandConversionClass>>>>);
	using NonConst = Hxx1::NonConstRef;
};

class CommandConversionClassInterface::Hxx1::NonConstRef :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<NonConstRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<CommandConversionClassInterface, maxon::StrongRefHandler, NonConstRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<CommandConversionClassInterface, maxon::StrongRefHandler, NonConstRef>>>>);
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

struct CommandCacheInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, CommandCacheInterface>::value || ObjectInterface::HasBase::template Check<I>::value; static I* Cast(CommandCacheInterface* ptr) { return reinterpret_cast<I*>(ptr); } }; };
struct CommandCacheInterface::Hxx1
{
	class Reference;
	using ReferenceClass = CommandCacheRef;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<ObjectInterface>;
	/// Intermediate helper class for CommandCacheInterface.
	template <typename S> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
	{
	public:
		ConstReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
	};
	/// Intermediate helper class for CommandCacheInterface.
	template <typename S> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, CommandCacheRef, true>::type&() const { return reinterpret_cast<const CommandCacheRef&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, CommandCacheRef, false>::type&() { return reinterpret_cast<const CommandCacheRef&>(this->GetBaseRef()); }
		inline Result<void> Init(CommandDataRef& data) const;
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type Reset() const;
	};
	/// Intermediate helper class for CommandCacheInterface.
	template <typename S> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, CommandCacheRef, false>::type&() { return reinterpret_cast<const CommandCacheRef&>(this->GetBaseRef()); }
		inline Result<void> Init(CommandDataRef& data);
		inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type Reset();
	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename ObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename ObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, ReferenceFunctionsImpl<typename ObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>>::type> { };
};
class CommandCacheInterface::Hxx1::Reference :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<CommandCacheRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<CommandCacheInterface, maxon::StrongRefHandler, CommandCacheRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<CommandCacheInterface, maxon::StrongRefHandler, CommandCacheRef>>>>);
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
