#if 1
class DebugHardwareBreakPointRef;

struct DebugHardwareBreakPointInterface::ReferenceClassHelper { using type = DebugHardwareBreakPointRef; };

/// Intermediate helper class for DebugHardwareBreakPointInterface.
template <typename S> class DebugHardwareBreakPointInterface::ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
{
public:
	ConstReferenceFunctionsImpl() = default;
	using PrivateBaseClass = S;
	using PrivateBaseClass::PrivateBaseClass;
/// Sets a hardware breakpoint for all running threads. When the program hit the watched memory a single_step exception will be fired and
/// the debugger stops at this point where the memory is accessed.
/// @param[in] type								Trigger type of the breakpoint.
/// @param[in] size								Number of bytes to be watched starting from watchAddress.
/// @param[in] watchAddress				Start address of the watched memory.
/// @return												OK on success.
	static inline Result<DebugHardwareBreakPointRef> SetHardwareBreakpoint(HARDWAREBREAKPOINTTYPE type, HARDWAREBREAKPOINTSIZE size, void* watchAddress);
};
#ifdef DOXYGEN
template <typename REF> class DebugHardwareBreakPointInterface::ConstReferenceFunctionsImplDoxy : public DebugHardwareBreakPointInterface::ConstReferenceFunctionsImpl<REF> { };
#endif

/// Intermediate helper class for DebugHardwareBreakPointInterface.
template <typename S> class DebugHardwareBreakPointInterface::ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
{
public:
	ReferenceFunctionsImpl() = default;
	using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
	using PrivateBaseClass::PrivateBaseClass;
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, DebugHardwareBreakPointRef, true>::type&() const { return reinterpret_cast<const DebugHardwareBreakPointRef&>(this->GetBaseRef()); }
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, DebugHardwareBreakPointRef, false>::type&() { return reinterpret_cast<const DebugHardwareBreakPointRef&>(this->GetBaseRef()); }
/// Removes a hardware breakpoint from all threads.
/// @return												OK on success.
	inline Result<void> RemoveHardwareBreakpoint() const;
};
#ifdef DOXYGEN
template <typename REF> class DebugHardwareBreakPointInterface::ReferenceFunctionsImplDoxy : public DebugHardwareBreakPointInterface::ReferenceFunctionsImpl<REF> { };
#endif

/// Intermediate helper class for DebugHardwareBreakPointInterface.
template <typename S> class DebugHardwareBreakPointInterface::COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
{
public:
	COWReferenceFunctionsImpl() = default;
	using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
	using PrivateBaseClass::PrivateBaseClass;
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, DebugHardwareBreakPointRef, false>::type&() { return reinterpret_cast<const DebugHardwareBreakPointRef&>(this->GetBaseRef()); }
};
#ifdef DOXYGEN
template <typename REF> class DebugHardwareBreakPointInterface::COWReferenceFunctionsImplDoxy : public DebugHardwareBreakPointInterface::COWReferenceFunctionsImpl<REF> { };
#endif

template <typename ST> struct DebugHardwareBreakPointInterface::ReferenceFunctions { using type = typename std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename ST::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename ST::type>, ReferenceFunctionsImpl<typename ST::type>>::type>::type; };
class DebugHardwareBreakPointInterface::Reference :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<DebugHardwareBreakPointRef>
#else
public maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<DebugHardwareBreakPointInterface, maxon::StrongRefHandler, DebugHardwareBreakPointRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<DebugHardwareBreakPointInterface, maxon::StrongRefHandler, DebugHardwareBreakPointRef>>>>);
	using NonConst = Super::ReferenceClass;
};

/// DebugHardwareBreakPointRef is the reference class of DebugHardwareBreakPointInterface.
///
/// WARNING: This functionality must not be used in production code. it's only allowed to use this for debugging purposes and needs to be
/// removed/deactivated before submitting.
/// Windows: Please note that intel cpus support only 4 hardware breakpoints. If you try to set more than 4 breakpoints an error will be returned.
///   A good praxis is to create a Ringbuffer<DebugHardwareBreakPointRef, DebugHardwareBreakPointInterface::MAXHARDWAREBREAKPOINTS> and free the oldest hardware breakpoints before creating new one.
class DebugHardwareBreakPointRef : public DebugHardwareBreakPointInterface::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(DebugHardwareBreakPointRef, Reference);
};

#endif
