#if 1
struct DataDescriptionObjectInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, DataDescriptionObjectInterface>::value || Object::HasBase::Check<I>::value; static I* Cast(DataDescriptionObjectInterface* ptr) { return static_cast<I*>(static_cast<maxon::Object*>(ptr)); } }; };
class DataDescriptionObjectRef;

struct DataDescriptionObjectInterface::ReferenceClassHelper { using type = DataDescriptionObjectRef; };

/// Intermediate helper class for DataDescriptionObjectInterface.
template <typename S> class DataDescriptionObjectInterface::ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
{
public:
	ConstReferenceFunctionsImpl() = default;
	using PrivateBaseClass = S;
	using PrivateBaseClass::PrivateBaseClass;
/// GetObjectDescription returns the description of the object.
/// @param[in] category						Description category to load (DATADESCRIPTION_CATEGORY_DATA/DATADESCRIPTION_CATEGORY_UI).
/// @param[in] language						Language (only valid for category DATADESCRIPTION_CATEGORY_STRING).
/// @param[in] objectData					Data of the object to use for evaluation.
/// @return												DataDescription on success. If the Description could not be found an empty description is returned but no error.
	inline Result<DataDescription> GetObjectDescription(const Id& category, const LanguageRef& language, const DataDictionaryObjectRef& objectData) const;
};
#ifdef DOXYGEN
template <typename REF> class DataDescriptionObjectInterface::ConstReferenceFunctionsImplDoxy : public DataDescriptionObjectInterface::ConstReferenceFunctionsImpl<REF>, public Object::ConstReferenceFunctionsImplDoxy<REF> { };
#endif

/// Intermediate helper class for DataDescriptionObjectInterface.
template <typename S> class DataDescriptionObjectInterface::ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
{
public:
	ReferenceFunctionsImpl() = default;
	using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
	using PrivateBaseClass::PrivateBaseClass;
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, DataDescriptionObjectRef, true>::type&() const { return reinterpret_cast<const DataDescriptionObjectRef&>(this->GetBaseRef()); }
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, DataDescriptionObjectRef, false>::type&() { return reinterpret_cast<const DataDescriptionObjectRef&>(this->GetBaseRef()); }
};
#ifdef DOXYGEN
template <typename REF> class DataDescriptionObjectInterface::ReferenceFunctionsImplDoxy : public DataDescriptionObjectInterface::ReferenceFunctionsImpl<REF>, public Object::ReferenceFunctionsImplDoxy<REF> { };
#endif

/// Intermediate helper class for DataDescriptionObjectInterface.
template <typename S> class DataDescriptionObjectInterface::COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
{
public:
	COWReferenceFunctionsImpl() = default;
	using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
	using PrivateBaseClass::PrivateBaseClass;
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, DataDescriptionObjectRef, false>::type&() { return reinterpret_cast<const DataDescriptionObjectRef&>(this->GetBaseRef()); }
};
#ifdef DOXYGEN
template <typename REF> class DataDescriptionObjectInterface::COWReferenceFunctionsImplDoxy : public DataDescriptionObjectInterface::COWReferenceFunctionsImpl<REF>, public Object::COWReferenceFunctionsImplDoxy<REF> { };
#endif

template <typename ST> struct DataDescriptionObjectInterface::ReferenceFunctions { using type = typename std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename Object::ReferenceFunctions<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename Object::ReferenceFunctions<ST>::type>, ReferenceFunctionsImpl<typename Object::ReferenceFunctions<ST>::type>>::type>::type; };
class DataDescriptionObjectInterface::Reference :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<DataDescriptionObjectRef>
#else
public maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<DataDescriptionObjectInterface, maxon::StrongRefHandler, DataDescriptionObjectRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<DataDescriptionObjectInterface, maxon::StrongRefHandler, DataDescriptionObjectRef>>>>);
	using NonConst = Super::ReferenceClass;
};

/// DataDescriptionObjectRef is the reference class of DataDescriptionObjectInterface.
///
/// Interface and base implementation to allow objects to access descriptions. The base implementation automatically loads resources from
/// the data description data bases.
class DataDescriptionObjectRef : public DataDescriptionObjectInterface::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(DataDescriptionObjectRef, Reference);
};

#endif
