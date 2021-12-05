#if 1
class NetworkProtocolJSONRef;

struct NetworkProtocolJSONInterface::ReferenceClassHelper { using type = NetworkProtocolJSONRef; };

/// Intermediate helper class for NetworkProtocolJSONInterface.
template <typename S> class NetworkProtocolJSONInterface::ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
{
public:
	ConstReferenceFunctionsImpl() = default;
	using PrivateBaseClass = S;
	using PrivateBaseClass::PrivateBaseClass;
};
#ifdef DOXYGEN
template <typename REF> class NetworkProtocolJSONInterface::ConstReferenceFunctionsImplDoxy : public NetworkProtocolJSONInterface::ConstReferenceFunctionsImpl<REF> { };
#endif

/// Intermediate helper class for NetworkProtocolJSONInterface.
template <typename S> class NetworkProtocolJSONInterface::ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
{
public:
	ReferenceFunctionsImpl() = default;
	using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
	using PrivateBaseClass::PrivateBaseClass;
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, NetworkProtocolJSONRef, true>::type&() const { return reinterpret_cast<const NetworkProtocolJSONRef&>(this->GetBaseRef()); }
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, NetworkProtocolJSONRef, false>::type&() { return reinterpret_cast<const NetworkProtocolJSONRef&>(this->GetBaseRef()); }
	inline Result<void> ConvertToJSON(const DataDictionary& jsonObject, String& jsonString, Bool niceFormatting) const;
	inline Result<void> ConvertFromJSON(const InputStreamRef& stream, NETWORKPROTOCOLJSONFLAGS flags, const StringDecodingRef& stringDecoding, DataDictionary& jsonObject) const;
	inline Result<void> ConvertFromJSON(const String& jsonString, NETWORKPROTOCOLJSONFLAGS flags, DataDictionary& jsonObject) const;
};
#ifdef DOXYGEN
template <typename REF> class NetworkProtocolJSONInterface::ReferenceFunctionsImplDoxy : public NetworkProtocolJSONInterface::ReferenceFunctionsImpl<REF> { };
#endif

/// Intermediate helper class for NetworkProtocolJSONInterface.
template <typename S> class NetworkProtocolJSONInterface::COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
{
public:
	COWReferenceFunctionsImpl() = default;
	using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
	using PrivateBaseClass::PrivateBaseClass;
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, NetworkProtocolJSONRef, false>::type&() { return reinterpret_cast<const NetworkProtocolJSONRef&>(this->GetBaseRef()); }
};
#ifdef DOXYGEN
template <typename REF> class NetworkProtocolJSONInterface::COWReferenceFunctionsImplDoxy : public NetworkProtocolJSONInterface::COWReferenceFunctionsImpl<REF> { };
#endif

template <typename ST> struct NetworkProtocolJSONInterface::ReferenceFunctions { using type = typename std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename ST::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename ST::type>, ReferenceFunctionsImpl<typename ST::type>>::type>::type; };
class NetworkProtocolJSONInterface::Reference :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<NetworkProtocolJSONRef>
#else
public maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<NetworkProtocolJSONInterface, maxon::StrongRefHandler, NetworkProtocolJSONRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<NetworkProtocolJSONInterface, maxon::StrongRefHandler, NetworkProtocolJSONRef>>>>);
	using NonConst = Super::ReferenceClass;
	static MAXON_ATTRIBUTE_FORCE_INLINE maxon::ResultMemT<NetworkProtocolJSONRef> Create();
};

/// NetworkProtocolJSONRef is the reference class of NetworkProtocolJSONInterface.
class NetworkProtocolJSONRef : public NetworkProtocolJSONInterface::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NetworkProtocolJSONRef, Reference);
};

#endif
