#if 1
#ifndef MAXON_COMPILER_CLANG
#endif
#ifndef MAXON_COMPILER_CLANG
#endif
struct DataSerializeInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, DataSerializeInterface>::value || Object::HasBase::Check<I>::value; static I* Cast(DataSerializeInterface* ptr) { return static_cast<I*>(static_cast<maxon::Object*>(ptr)); } }; };
class DataSerializeRef;

struct DataSerializeInterface::ReferenceClassHelper { using type = DataSerializeRef; };

/// Intermediate helper class for DataSerializeInterface.
template <typename S> class DataSerializeInterface::ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
{
public:
	ConstReferenceFunctionsImpl() = default;
	using PrivateBaseClass = S;
	using PrivateBaseClass::PrivateBaseClass;
/// Describes an element for I/O operations.
/// Usually this routine is not directly called. Instead the helper-defines @c Describe, @c DescribeHelper, @c DescribeIf etc. are used.
/// @param[in] name								The clear-text name of an element in the file format. It can be arbitrarily chosen, but usually matches the respective member name. Once it has been used in files
///																the identifier needs to stay the same to remain compatible (unless some conversion code is added). The name must only contain (latin) alphanumeric characters
///																or '_' and it must not start with a numeric character.
///																'name' must be permanently available (and not only during the time of this call).
/// @param[in] dt									The data type of the member (a registered data type must exist).
/// @param[in] objectOffset				The offset position of the member in the class (or the helper class).
/// @param[in] func								A conversion function that translates an address into the appropriate accessor interface (e.g. MapInterface or ArrayInterface).
/// @param[in] flags							Properties of the element.
/// @param[in] mask								Conditional mask for DESCRIBEFLAGS::CONDITION_IF and DESCRIBEFLAGS::CONDITION_ELSE.
/// @param[in] value							Conditional value for DESCRIBEFLAGS::CONDITION_IF and DESCRIBEFLAGS::CONDITION_ELSE.
/// @return												OK on success.
	inline Result<void> DescribeElement(const Char* name, const DataType* dt, Int objectOffset, KeyValueConversionFunc* func, DESCRIBEFLAGS flags, UInt64 mask, UInt64 value) const;
/// Declares and prepares a helper class. This can only be done once within DescribeIO. The helper class is used to convert I/O data and initialize temporary values.
/// Usually this routine is not directly called. Instead the helper-define @ PrepareHelper is used.
/// @param[in] createFunc					The function to create the helper class.
/// @param[in] deleteFunc					The function to delete the helper class.
/// @param[in] readFunc						The function pointing to the helper's ReadAction member function.
/// @param[in] writeFunc					The function pointing to the helper's WriteAction member function.
/// @param[in] flags							Properties of the helper.
/// @return												OK on success.
	inline Result<void> PrepareHelperClass(CreateIoHelperFunc* createFunc, DeleteIoHelperFunc* deleteFunc, ReadIoHelperFunc* readFunc, WriteIoHelperFunc* writeFunc, PREPAREHELPERFLAGS flags) const;
/// Registers a class to support a later default value comparison. If the writer supports this
/// feature an allocated class (using the createFunc) will be returned. Otherwise a nullptr is
/// returned, which is no error state.
/// @param[in] createFunc					The function to create the class.
/// @param[in] deleteFunc					The function to delete the class.
/// @return												The allocated class or a nullptr.
	inline Result<void*> RegisterDefaults(CreateIoHelperFunc* createFunc, DeleteIoHelperFunc* deleteFunc) const;
};
#ifdef DOXYGEN
template <typename REF> class DataSerializeInterface::ConstReferenceFunctionsImplDoxy : public DataSerializeInterface::ConstReferenceFunctionsImpl<REF>, public Object::ConstReferenceFunctionsImplDoxy<REF> { };
#endif

/// Intermediate helper class for DataSerializeInterface.
template <typename S> class DataSerializeInterface::ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
{
public:
	ReferenceFunctionsImpl() = default;
	using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
	using PrivateBaseClass::PrivateBaseClass;
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, DataSerializeRef, true>::type&() const { return reinterpret_cast<const DataSerializeRef&>(this->GetBaseRef()); }
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, DataSerializeRef, false>::type&() { return reinterpret_cast<const DataSerializeRef&>(this->GetBaseRef()); }
/// Registers a substitution function to replace virtual objects (objects with virtual interfaces) during the I/O process.
/// The registration must happen before the main Read/Write call.
/// The substitution will be able to write a different object than the one that exists in memory - or restore a different object than what is written into the stream.
/// An example is e.g. RPC: instead of writing a WindowRef object only an object containing an Id is written to the file. On the other side then the object with the Id
/// is read and a RPC WindowRef created.
/// Substitutions fully support the referencing system, so all StrongReferences and WeakReferences will remain valid.
/// @param[in] func								The substitution function (used for both reading and writing).
/// @return												OK on success.
	inline Result<void> RegisterObjectSubstitution(ReferenceSubstitutionFunction&& func) const;
};
#ifdef DOXYGEN
template <typename REF> class DataSerializeInterface::ReferenceFunctionsImplDoxy : public DataSerializeInterface::ReferenceFunctionsImpl<REF>, public Object::ReferenceFunctionsImplDoxy<REF> { };
#endif

/// Intermediate helper class for DataSerializeInterface.
template <typename S> class DataSerializeInterface::COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
{
public:
	COWReferenceFunctionsImpl() = default;
	using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
	using PrivateBaseClass::PrivateBaseClass;
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, DataSerializeRef, false>::type&() { return reinterpret_cast<const DataSerializeRef&>(this->GetBaseRef()); }
/// Registers a substitution function to replace virtual objects (objects with virtual interfaces) during the I/O process.
/// The registration must happen before the main Read/Write call.
/// The substitution will be able to write a different object than the one that exists in memory - or restore a different object than what is written into the stream.
/// An example is e.g. RPC: instead of writing a WindowRef object only an object containing an Id is written to the file. On the other side then the object with the Id
/// is read and a RPC WindowRef created.
/// Substitutions fully support the referencing system, so all StrongReferences and WeakReferences will remain valid.
/// @param[in] func								The substitution function (used for both reading and writing).
/// @return												OK on success.
	inline Result<void> RegisterObjectSubstitution(ReferenceSubstitutionFunction&& func);
};
#ifdef DOXYGEN
template <typename REF> class DataSerializeInterface::COWReferenceFunctionsImplDoxy : public DataSerializeInterface::COWReferenceFunctionsImpl<REF>, public Object::COWReferenceFunctionsImplDoxy<REF> { };
#endif

template <typename ST> struct DataSerializeInterface::ReferenceFunctions { using type = typename std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename Object::ReferenceFunctions<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename Object::ReferenceFunctions<ST>::type>, ReferenceFunctionsImpl<typename Object::ReferenceFunctions<ST>::type>>::type>::type; };
class DataSerializeInterface::Reference :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<DataSerializeRef>
#else
public maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<DataSerializeInterface, maxon::StrongRefHandler, DataSerializeRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<DataSerializeInterface, maxon::StrongRefHandler, DataSerializeRef>>>>);
	using NonConst = Super::ReferenceClass;
};

/// DataSerializeRef is the reference class of DataSerializeInterface.
///
/// This is the base class for generic serialization of any data type.
/// For reading and writing the interfaces are split into DataSerializeReaderInterface and DataSerializeWriterInterface.
/// The DataFormatReaderInterface and DataFormatWriterInterface can add specific serialization for data types.
/// The DataSerializeReaderClasses and DataSerializeWriterClasses registry lists all possible formats.
/// @link io_overview_describeio @endlink
class DataSerializeRef : public DataSerializeInterface::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(DataSerializeRef, Reference);
};

struct DataSerializeWriterInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, DataSerializeWriterInterface>::value || DataSerializeInterface::HasBase::Check<I>::value; static I* Cast(DataSerializeWriterInterface* ptr) { return static_cast<I*>(static_cast<maxon::Object*>(ptr)); } }; };
class DataSerializeWriterRef;

struct DataSerializeWriterInterface::ReferenceClassHelper { using type = DataSerializeWriterRef; };

/// Intermediate helper class for DataSerializeWriterInterface.
template <typename S> class DataSerializeWriterInterface::ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
{
public:
	ConstReferenceFunctionsImpl() = default;
	using PrivateBaseClass = S;
	using PrivateBaseClass::PrivateBaseClass;
};
#ifdef DOXYGEN
template <typename REF> class DataSerializeWriterInterface::ConstReferenceFunctionsImplDoxy : public DataSerializeWriterInterface::ConstReferenceFunctionsImpl<REF>, public DataSerializeInterface::ConstReferenceFunctionsImplDoxy<REF> { };
#endif

/// Intermediate helper class for DataSerializeWriterInterface.
template <typename S> class DataSerializeWriterInterface::ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
{
public:
	ReferenceFunctionsImpl() = default;
	using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
	using PrivateBaseClass::PrivateBaseClass;
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, DataSerializeWriterRef, true>::type&() const { return reinterpret_cast<const DataSerializeWriterRef&>(this->GetBaseRef()); }
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, DataSerializeWriterRef, false>::type&() { return reinterpret_cast<const DataSerializeWriterRef&>(this->GetBaseRef()); }
/// Writes the given object into a serialized stream.
/// @param[in] id									The identifier of the file.
/// @param[in] data								The object's datatype and address.
/// @return												OK on success.
	inline Result<void> WriteDocument(const Id& id, const ConstDataPtr& data) const;
};
#ifdef DOXYGEN
template <typename REF> class DataSerializeWriterInterface::ReferenceFunctionsImplDoxy : public DataSerializeWriterInterface::ReferenceFunctionsImpl<REF>, public DataSerializeInterface::ReferenceFunctionsImplDoxy<REF> { };
#endif

/// Intermediate helper class for DataSerializeWriterInterface.
template <typename S> class DataSerializeWriterInterface::COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
{
public:
	COWReferenceFunctionsImpl() = default;
	using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
	using PrivateBaseClass::PrivateBaseClass;
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, DataSerializeWriterRef, false>::type&() { return reinterpret_cast<const DataSerializeWriterRef&>(this->GetBaseRef()); }
/// Writes the given object into a serialized stream.
/// @param[in] id									The identifier of the file.
/// @param[in] data								The object's datatype and address.
/// @return												OK on success.
	inline Result<void> WriteDocument(const Id& id, const ConstDataPtr& data);
};
#ifdef DOXYGEN
template <typename REF> class DataSerializeWriterInterface::COWReferenceFunctionsImplDoxy : public DataSerializeWriterInterface::COWReferenceFunctionsImpl<REF>, public DataSerializeInterface::COWReferenceFunctionsImplDoxy<REF> { };
#endif

template <typename ST> struct DataSerializeWriterInterface::ReferenceFunctions { using type = typename std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename DataSerializeInterface::ReferenceFunctions<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename DataSerializeInterface::ReferenceFunctions<ST>::type>, ReferenceFunctionsImpl<typename DataSerializeInterface::ReferenceFunctions<ST>::type>>::type>::type; };
class DataSerializeWriterInterface::Reference :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<DataSerializeWriterRef>
#else
public maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<DataSerializeWriterInterface, maxon::StrongRefHandler, DataSerializeWriterRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<DataSerializeWriterInterface, maxon::StrongRefHandler, DataSerializeWriterRef>>>>);
	using NonConst = Super::ReferenceClass;
};

/// DataSerializeWriterRef is the reference class of DataSerializeWriterInterface.
///
/// This class serializes data into a specific file format.
class DataSerializeWriterRef : public DataSerializeWriterInterface::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(DataSerializeWriterRef, Reference);
};

struct DataSerializeReaderInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, DataSerializeReaderInterface>::value || DataSerializeInterface::HasBase::Check<I>::value; static I* Cast(DataSerializeReaderInterface* ptr) { return static_cast<I*>(static_cast<maxon::Object*>(ptr)); } }; };
class DataSerializeReaderRef;

struct DataSerializeReaderInterface::ReferenceClassHelper { using type = DataSerializeReaderRef; };

/// Intermediate helper class for DataSerializeReaderInterface.
template <typename S> class DataSerializeReaderInterface::ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
{
public:
	ConstReferenceFunctionsImpl() = default;
	using PrivateBaseClass = S;
	using PrivateBaseClass::PrivateBaseClass;
};
#ifdef DOXYGEN
template <typename REF> class DataSerializeReaderInterface::ConstReferenceFunctionsImplDoxy : public DataSerializeReaderInterface::ConstReferenceFunctionsImpl<REF>, public DataSerializeInterface::ConstReferenceFunctionsImplDoxy<REF> { };
#endif

/// Intermediate helper class for DataSerializeReaderInterface.
template <typename S> class DataSerializeReaderInterface::ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
{
public:
	ReferenceFunctionsImpl() = default;
	using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
	using PrivateBaseClass::PrivateBaseClass;
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, DataSerializeReaderRef, true>::type&() const { return reinterpret_cast<const DataSerializeReaderRef&>(this->GetBaseRef()); }
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, DataSerializeReaderRef, false>::type&() { return reinterpret_cast<const DataSerializeReaderRef&>(this->GetBaseRef()); }
/// Reads the given object from a serialized stream.
/// @param[in] id									The identifier of the file.
/// @param[in] data								The object's datatype and address.
/// @return												OK on success.
	inline Result<void> ReadDocument(const Id& id, const DataPtr& data) const;
};
#ifdef DOXYGEN
template <typename REF> class DataSerializeReaderInterface::ReferenceFunctionsImplDoxy : public DataSerializeReaderInterface::ReferenceFunctionsImpl<REF>, public DataSerializeInterface::ReferenceFunctionsImplDoxy<REF> { };
#endif

/// Intermediate helper class for DataSerializeReaderInterface.
template <typename S> class DataSerializeReaderInterface::COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
{
public:
	COWReferenceFunctionsImpl() = default;
	using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
	using PrivateBaseClass::PrivateBaseClass;
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, DataSerializeReaderRef, false>::type&() { return reinterpret_cast<const DataSerializeReaderRef&>(this->GetBaseRef()); }
/// Reads the given object from a serialized stream.
/// @param[in] id									The identifier of the file.
/// @param[in] data								The object's datatype and address.
/// @return												OK on success.
	inline Result<void> ReadDocument(const Id& id, const DataPtr& data);
};
#ifdef DOXYGEN
template <typename REF> class DataSerializeReaderInterface::COWReferenceFunctionsImplDoxy : public DataSerializeReaderInterface::COWReferenceFunctionsImpl<REF>, public DataSerializeInterface::COWReferenceFunctionsImplDoxy<REF> { };
#endif

template <typename ST> struct DataSerializeReaderInterface::ReferenceFunctions { using type = typename std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename DataSerializeInterface::ReferenceFunctions<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename DataSerializeInterface::ReferenceFunctions<ST>::type>, ReferenceFunctionsImpl<typename DataSerializeInterface::ReferenceFunctions<ST>::type>>::type>::type; };
class DataSerializeReaderInterface::Reference :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<DataSerializeReaderRef>
#else
public maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<DataSerializeReaderInterface, maxon::StrongRefHandler, DataSerializeReaderRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<DataSerializeReaderInterface, maxon::StrongRefHandler, DataSerializeReaderRef>>>>);
	using NonConst = Super::ReferenceClass;
};

/// DataSerializeReaderRef is the reference class of DataSerializeReaderInterface.
///
/// This class serializes data from a specific file format.
class DataSerializeReaderRef : public DataSerializeReaderInterface::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(DataSerializeReaderRef, Reference);
};

#endif
