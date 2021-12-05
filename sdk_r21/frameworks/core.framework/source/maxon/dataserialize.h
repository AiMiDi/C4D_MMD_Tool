#ifndef DATASERIALIZE_H__
#define DATASERIALIZE_H__

#include "maxon/objectbase.h"

#include "maxon/array.h"	// necessary for ArrayConversionHelper
#include "maxon/set.h"		// necessary for SetConversionHelper
#include "maxon/map.h"		// necessary for MapConversionHelper

/// @file

namespace maxon
{

// stylecheck.naming=false

//----------------------------------------------------------------------------------------
/// Helper datatype to write an empty datatype to the stream.
/// This datatype must not be used. It's only for internal use in DataSerializeInterface.
//----------------------------------------------------------------------------------------
struct IDENT_VOID
{
	Bool operator ==(const IDENT_VOID&) const { return true; }
	Bool operator !=(const IDENT_VOID&) const { return false; }
	UInt GetHashCode() const { DebugStop(); return 0; }

	String ToString(const FormatStatement* formatStatement) const
	{
		return "IDENT_VOID"_s;
	}
};
MAXON_DATATYPE_SCALAR(IDENT_VOID, "net.maxon.ident_void");

// stylecheck.naming=true

// internal helper functions for PrepareHelperClass etc.
using KeyValueConversionFunc = void(void*, Char*);
using CreateIoHelperFunc = ResultPtr<void>();
using DeleteIoHelperFunc = void(void*);
using ReadIoHelperFunc = Result<void>(DataSerializeInterface*, void*, void*, UInt);
using WriteIoHelperFunc = Result<void>(DataSerializeInterface*, void*, void*, UInt);

//----------------------------------------------------------------------------------------
/// Conversion function for AddWidthConversion from a source to a destination datatype.
#ifndef MAXON_COMPILER_CLANG	// circumvent clang bug that creates false positives
/// @param[in] source							The address of the source datatype.
/// @param[in] dest								The address of the destination datatype.
/// @return												True if a conversion was possible, false otherwise.
#endif
//----------------------------------------------------------------------------------------
using WidthConversionFunc = Bool(void* source, void* dest);

//----------------------------------------------------------------------------------------
/// Substitution function for RegisterObjectSubstitution.
/// The returned ObjectInterface* can be identical to 'input', in that case no substitution takes place. So e.g. only
/// certain types of objects can be translated.
/// Please note that when you create the substitution objects you need to make sure to hold all references
/// yourself (until the complete I/O operation is finished) as the substitution function
/// only returns a pointer and not a reference.
/// Please also note that the input object during reading has the same pointer address it still
/// may be a different object as it is only a temporary object and thus can be at the same
/// address as a previous object.
#ifndef MAXON_COMPILER_CLANG	// circumvent clang bug that creates false positives
/// @param[in] input							The virtual object created from reading or writing.
/// @return												The substituted object.
#endif
//----------------------------------------------------------------------------------------
using ReferenceSubstitutionFunction = Delegate<Result<const ObjectInterface*>(const ObjectInterface* input)>;

template <typename T> inline ResultPtr<void> CreateHelper()
{
	return NewObj(T);
}

template <typename T> inline void DeleteHelper(void* helper)
{
	T* tmp = (T*)helper;
	DeleteObj(tmp);
}

template <typename MAINCLASS, typename HELPERCLASS> inline Result<void> ReadHelper(DataSerializeInterface* ds, void* classPtr, void* helperPtr, UInt elementHash)
{
	MAINCLASS* mainClassPtr = (MAINCLASS*)classPtr;
	HELPERCLASS* helperClassPtr = (HELPERCLASS*)helperPtr;
	return helperClassPtr->ReadAction(ds, *mainClassPtr, elementHash);
}

template <typename MAINCLASS, typename HELPERCLASS> inline Result<void> WriteHelper(DataSerializeInterface* ds, void* classPtr, void* helperPtr, UInt elementHash)
{
	MAINCLASS* mainClassPtr = (MAINCLASS*)classPtr;
	HELPERCLASS* helperClassPtr = (HELPERCLASS*)helperPtr;
	return helperClassPtr->WriteAction(ds, *mainClassPtr, elementHash);
}

template <typename T> inline void ArrayConversionHelper(void* arrayPtr, Char* memBuffer)
{
	auto tmp = ((T*)arrayPtr)->ToArray();

	static_assert(SIZEOF(tmp) <= 32, "Temp buffer for describe array not large enough");

	// move content into temporary memory buffer as we cannot copy/move the interface directly
	new (memBuffer) decltype(tmp)(std::move(tmp));
}

template <typename T> inline void SetConversionHelper(void* mapPtr, Char* memBuffer)
{
	auto tmp = ((T*)mapPtr)->ToSet();

	static_assert(SIZEOF(tmp) <= 32, "Temp buffer for describe array not large enough");

	// move content into temporary memory buffer as we cannot copy/move the interface directly
	new (memBuffer) decltype(tmp)(std::move(tmp));
}

template <typename T> inline void MapConversionHelper(void* mapPtr, Char* memBuffer)
{
	auto tmp = ((T*)mapPtr)->ToMap();

	static_assert(SIZEOF(tmp) <= 32, "Temp buffer for describe array not large enough");

	// move content into temporary memory buffer as we cannot copy/move the interface directly
	new (memBuffer) decltype(tmp)(std::move(tmp));
}

// stylecheck.naming=false

//----------------------------------------------------------------------------------------
/// Flags to describe the properties of I/O elements.
/// An enum cannot be used here due to the use of templates and static_assert in Describe().
//----------------------------------------------------------------------------------------
class DESCRIBEFLAGS
{
public:
	using ValueType = UInt32;

	static const ValueType NONE									= 0;					///< Default.
	static const ValueType CONDITION_IF					= (1 << 0);		///< If set element additionally describes an if-condition. Can only be done for elementary datatypes.
	static const ValueType CONDITION_ELSE				= (1 << 1);		///< Else/Else If condition, cannot be combined with other flags.
	static const ValueType CONDITION_END				= (1 << 2);		///< End condition, cannot be combined with other flags.
	static const ValueType IS_LEGACY_ELEMENT		= (1 << 3);		///< Mark an element as "legacy". The element will no longer be read/written but also not show up in any warnings.
	static const ValueType DONT_WRITE						= (1 << 4);		///< If set the element will only be read (for conversion purposes), not written.
	static const ValueType ACTION_BEFORE_WRITE	= (1 << 5);		///< If set there will be a call to the helper class WriteAction member function before an element is written.
	static const ValueType ACTION_AFTER_READ		= (1 << 6);		///< If set there will be a call to the helper class ReadAction member function after an element is read.
	static const ValueType REFERS_TO_HELPER			= (1 << 7);		///< If set the description refers to the helper class instead of the base class.
	static const ValueType DELAYED							= (1 << 8);		///< Can only be used for references. Reads/Writes the reference at a later point in time (like WeakRefs), avoiding recursion problems. E.g. this can be used if a node holds its children as StrongRefs.
	static const ValueType TYPE_SET							= (1 << 9);		///< The described element is a Set type.
	static const ValueType TYPE_MAP							= (1 << 10);	///< The described element is a Map type.
	static const ValueType TYPE_ARRAY						= (1 << 11);	///< The described element is an Array type.
	static const ValueType TYPE_UNIQUEREF				= (1 << 12);	///< The described element is an UniqueRef type.
	static const ValueType TYPE_WEAKREF					= (1 << 13);	///< The described element is a WeakRef type.
	static const ValueType TYPE_DATATYPE				= (1 << 14);	///< The described element is a DataTypeImpl*. Only necessary if RECEIVE_DATATYPE is also used.
	static const ValueType RECEIVE_DATATYPE			= (1 << 15);  ///< The described element will receive its datatype from an earlier element of TYPE_DATATYPE.
	static const ValueType APPLY_TO_KEY					= (1 << 16);	///< Can only be used together with TYPE_MAP and RECALL_DATATYPE. If set the map's key will receive the datatype instead of the value.
	static const ValueType WRITE_IF_NOT_EMPTY		= (1 << 17);	///< Only applies to text formats. Can only be used together with TYPE_ARRAY, TYPE_MAP or TYPE_SET. If present the array/set/map will only be written if it contains at least one element. Note that upon read no call to the ReadAction function will happen when the collection hasn't been written. This flag Will automatically be set if DescribeDefaults() is called.

	explicit DESCRIBEFLAGS(ValueType value) : _value(value) { }
	operator ValueType () const { return _value; }

public:
	ValueType _value;
};

// stylecheck.naming=true

// manually created operators for DESCRIBEFLAGS
inline DESCRIBEFLAGS operator |(DESCRIBEFLAGS a, DESCRIBEFLAGS b) { return DESCRIBEFLAGS(DESCRIBEFLAGS::ValueType(a)|DESCRIBEFLAGS::ValueType(b)); }
inline DESCRIBEFLAGS operator &(DESCRIBEFLAGS a, DESCRIBEFLAGS b) { return DESCRIBEFLAGS(DESCRIBEFLAGS::ValueType(a)&DESCRIBEFLAGS::ValueType(b)); }
inline DESCRIBEFLAGS operator ~(DESCRIBEFLAGS a) { return DESCRIBEFLAGS(~DESCRIBEFLAGS::ValueType(a)); }
inline DESCRIBEFLAGS& operator &=(DESCRIBEFLAGS& a, DESCRIBEFLAGS b) { a = DESCRIBEFLAGS(DESCRIBEFLAGS::ValueType(a)&DESCRIBEFLAGS::ValueType(b)); return a; }

static const UInt INITIALIZEHASH = 'init';
static const UInt FINALIZEHASH = 'fina';
static const UInt VALIDATEHASH = 'vali';

//----------------------------------------------------------------------------------------
/// Flags to describe the properties of I/O helper classes.
//----------------------------------------------------------------------------------------
enum class PREPAREHELPERFLAGS
{
	NONE								= 0,

	INITIALIZE_READ			= (1 << 0),	///< The helper's ReadAction will get a call with INITIALIZEHASH before the class has been read.
	INITIALIZE_WRITE		= (1 << 1),	///< The helper's WriteAction will get a call with INITIALIZEHASH before the class has been written.

	FINALIZE_READ				= (1 << 2),	///< The helper's ReadAction will get a call with FINALIZEHASH after the class has been read.
	FINALIZE_WRITE			= (1 << 3),	///< The helper's WriteAction will get a call with FINALIZEHASH after the class has been written.

	VALIDATE_STATE			= (1 << 4)	///< The helper's ReadAction will get a call after all input operations are finished. Objects that interact with others can then update necessary information.
} MAXON_ENUM_FLAGS(PREPAREHELPERFLAGS);

//----------------------------------------------------------------------------------------
/// Expression to calculate the hash code of a member name during compile time.
//----------------------------------------------------------------------------------------
#define CONSTHASH(x) static const maxon::UInt MAXON_CONCAT(x, Hash) = maxon::PrivateGetHashCode(#x, (maxon::Int)sizeof(#x) - 1) // subtract one as sizeof includes the terminating 0C

using StreamSubstitutionFunction = Delegate<Result<ObjectRef>(ObjectRef input, const Id& compressorId)>;

//----------------------------------------------------------------------------------------
/// This is the base class for generic serialization of any data type.
/// For reading and writing the interfaces are split into DataSerializeReaderInterface and DataSerializeWriterInterface.
/// The DataFormatReaderInterface and DataFormatWriterInterface can add specific serialization for data types.
/// The DataSerializeReaderClasses and DataSerializeWriterClasses registry lists all possible formats.
/// @link io_overview_describeio @endlink
//----------------------------------------------------------------------------------------
class DataSerializeInterface : MAXON_INTERFACE_BASES(ObjectInterface)
{
	MAXON_INTERFACE(DataSerializeInterface, MAXON_REFERENCE_NORMAL, "net.maxon.interface.dataserialize");

public:
	//----------------------------------------------------------------------------------------
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
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> DescribeElement(const Char* name, const DataType& dt, Int objectOffset, KeyValueConversionFunc* func, DESCRIBEFLAGS flags, UInt64 mask, UInt64 value) const;

	//----------------------------------------------------------------------------------------
	/// Declares and prepares a helper class. This can only be done once within DescribeIO. The helper class is used to convert I/O data and initialize temporary values.
	/// Usually this routine is not directly called. Instead the helper-define @ PrepareHelper is used.
	/// @param[in] createFunc					The function to create the helper class.
	/// @param[in] deleteFunc					The function to delete the helper class.
	/// @param[in] readFunc						The function pointing to the helper's ReadAction member function.
	/// @param[in] writeFunc					The function pointing to the helper's WriteAction member function.
	/// @param[in] flags							Properties of the helper.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> PrepareHelperClass(CreateIoHelperFunc* createFunc, DeleteIoHelperFunc* deleteFunc, ReadIoHelperFunc* readFunc, WriteIoHelperFunc* writeFunc, PREPAREHELPERFLAGS flags) const;

	//----------------------------------------------------------------------------------------
	/// Registers a substitution function to replace virtual objects (objects with virtual interfaces) during the I/O process.
	/// The registration must happen before the main Read/Write call.
	/// The substitution will be able to write a different object than the one that exists in memory - or restore a different object than what is written into the stream.
	/// An example is e.g. RPC: instead of writing a WindowRef object only an object containing an Id is written to the file. On the other side then the object with the Id
	/// is read and a RPC WindowRef created.
	/// Substitutions fully support the referencing system, so all StrongReferences and WeakReferences will remain valid.
	/// @param[in] func								The substitution function (used for both reading and writing).
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> RegisterObjectSubstitution(ReferenceSubstitutionFunction&& func);

	//----------------------------------------------------------------------------------------
	/// Registers a class to support a later default value comparison. If the writer supports this
	/// feature an allocated class (using the createFunc) will be returned. Otherwise a nullptr is
	/// returned, which is no error state.
	/// @param[in] createFunc					The function to create the class.
	/// @param[in] deleteFunc					The function to delete the class.
	/// @return												The allocated class or a nullptr.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void*> RegisterDefaults(CreateIoHelperFunc* createFunc, DeleteIoHelperFunc* deleteFunc) const;

	//----------------------------------------------------------------------------------------
	/// Starts a description within DescribeIO. This can only be done once and must happen before any Describe calls are made.
	/// @param[in] streamClass				The stream class which has been passed to DescribeIO.
	/// @param[in] className					The name of the current class.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	#define PrepareDescribe(streamClass, className) const maxon::DataSerializeInterface& descriptionStream = streamClass; using DESCRIBECLASS = className

	//----------------------------------------------------------------------------------------
	/// Registers a class to support a later default value comparison. Must be used after PrepareDescribe.
	/// Declares a variable 'defaults' which then can be filled with the defaults to compare to.
	//----------------------------------------------------------------------------------------
	#define DescribeDefaults() \
		maxon::Result<void*> _defaultTemp = descriptionStream.RegisterDefaults([]()->maxon::ResultPtr<void> { maxon::ResultPtr<DESCRIBECLASS> ptr = NewObj(DESCRIBECLASS); return (void*) ptr.GetValue(); } , [](void* ptr) { DESCRIBECLASS* defaults = static_cast<DESCRIBECLASS*>(ptr); DeleteObj(defaults); }); \
		DESCRIBECLASS* defaults = std::move(reinterpret_cast<maxon::Result<DESCRIBECLASS*>&>(_defaultTemp)) iferr_return; \
		maxon::UseVariable(defaults);

	//----------------------------------------------------------------------------------------
	/// Describes a class member for I/O operations within DescribeIO.
	/// It requires a previous call to PrepareDescribe.
	/// @link io_overview_describeio @endlink
	/// @param[in] name								The clear-text name of an element in the file format. It can be arbitrarily chosen, but usually matches the respective member name. Once it has been used in files
	///																the identifier needs to stay the same to remain compatible (unless some conversion code is added). The name must only contain (latin) alphanumeric characters
	///																or '_' and it must not start with a numeric character.
	///																'name' must be permanently available (and not only during the time of this call).
	/// @param[in] memberName					The name of the class member that will be described.
	/// @param[in] type								The DataType of the class member. While this could be automatically determined, this manual specification is necessary so that a change to a member type doesn't go unnoticed
	///																and damages the file integrity.
	/// @param[in] flags							One of the following: DESCRIBEFLAGS::TYPE_SET, DESCRIBEFLAGS::TYPE_MAP, DESCRIBEFLAGS::TYPE_ARRAY, DESCRIBEFLAGS::TYPE_UNIQUEREF, DESCRIBEFLAGS::TYPE_WEAKREF, DESCRIBEFLAGS::NONE.
	///																It can be combined with DESCRIBEFLAGS::DONT_WRITE, DESCRIBEFLAGS::ACTION_BEFORE_WRITE and DESCRIBEFLAGS::ACTION_AFTER_READ.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	#define Describe(name, memberName, type, flags) descriptionStream.DescribeElement<DESCRIBECLASS, type, flags>(name, &(((DESCRIBECLASS*)nullptr)->memberName), maxon::DESCRIBEFLAGS::NONE)

	//----------------------------------------------------------------------------------------
	/// Describes a class member for I/O operations within DescribeIO.
	/// It requires a previous call to PrepareDescribe.
	/// Other than Describe this define allows to cast to a different DataType before the description is made.
	/// Here an example:
	/// @code
	/// const auto& map = ((MYCLASS*)nullptr)->_vertices.GetMap().GetMap();
	/// DescribeOther("_vertices", map, MAXON_MACROARG_TYPE(Tuple<MeshValue, MeshPair>), DESCRIBEFLAGS::TYPE_MAP) iferr_return;
	/// @endcode
	/// It is important that &map is equal to the offset within the described class. This is achieved by casting nullptr to MYCLASS*.
	/// @param[in] name								The clear-text name of an element in the file format. It can be arbitrarily chosen, but usually matches the respective member name. Once it has been used in files
	///																the identifier needs to stay the same to remain compatible (unless some conversion code is added). The name must only contain (latin) alphanumeric characters
	///																or '_' and it must not start with a numeric character.
	///																'name' must be permanently available (and not only during the time of this call).
	/// @param[in] elementName				The element that will be described.
	/// @param[in] type								The DataType of the class member. While this could be automatically determined, this manual specification is necessary so that a change to a member type doesn't go unnoticed
	///																and damages the file integrity.
	/// @param[in] flags							One of the following: DESCRIBEFLAGS::TYPE_SET, DESCRIBEFLAGS::TYPE_MAP, DESCRIBEFLAGS::TYPE_ARRAY, DESCRIBEFLAGS::TYPE_UNIQUEREF, DESCRIBEFLAGS::TYPE_WEAKREF, DESCRIBEFLAGS::NONE.
	///																It can be combined with DESCRIBEFLAGS::DONT_WRITE, DESCRIBEFLAGS::ACTION_BEFORE_WRITE and DESCRIBEFLAGS::ACTION_AFTER_READ.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	#define DescribeOther(name, elementName, type, flags) descriptionStream.DescribeElement<DESCRIBECLASS, type, flags>(name, &elementName, maxon::DESCRIBEFLAGS::NONE)

	//----------------------------------------------------------------------------------------
	/// Describes a legacy element that is no longer needed within DescribeIO.
	/// It requires a previous call to PrepareDescribe.
	/// While generally no extra code is necessary to skip no longer needed elements this call makes sure that no warnings will show up if such an old element is found in a file.
	/// @param[in] name								The clear-text name of an element in the file format.
	///																'name' must be permanently available (and not only during the time of this call).
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	#define DescribeLegacy(name) descriptionStream.DescribeElement(name, maxon::DataType::NullValue(), 0, nullptr, (maxon::DESCRIBEFLAGS)maxon::DESCRIBEFLAGS::IS_LEGACY_ELEMENT, 0, 0)

	//----------------------------------------------------------------------------------------
	/// Describes a class member for I/O operations within DescribeIO.
	/// It requires a previous call to PrepareDescribe and PrepareHelper.
	/// Other than Describe this describes a member of the helper class.
	/// @link io_overview_helper @endlink
	/// @param[in] name								The clear-text name of an element in the file format. It can be arbitrarily chosen, but usually matches the respective member name. Once it has been used in files
	///																the identifier needs to stay the same to remain compatible (unless some conversion code is added). The name must only contain (latin) alphanumeric characters
	///																or '_' and it must not start with a numeric character.
	///																'name' must be permanently available (and not only during the time of this call).
	/// @param[in] memberName					The name of the member in the I/O helper class that will be described.
	/// @param[in] type								The DataType of the class member. While this could be automatically determined, this manual specification is necessary so that a change to a member type doesn't go unnoticed
	///																and damages the file integrity.
	/// @param[in] flags							One of the following: DESCRIBEFLAGS::TYPE_SET, DESCRIBEFLAGS::TYPE_MAP, DESCRIBEFLAGS::TYPE_ARRAY, DESCRIBEFLAGS::TYPE_UNIQUEREF, DESCRIBEFLAGS::TYPE_WEAKREF, DESCRIBEFLAGS::NONE.
	///																It can be combined with DESCRIBEFLAGS::DONT_WRITE, DESCRIBEFLAGS::ACTION_BEFORE_WRITE and DESCRIBEFLAGS::ACTION_AFTER_READ.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	#define DescribeHelper(name, memberName, type, flags) descriptionStream.DescribeElement<IOHELPERCLASS, type, flags>(name, &(((IOHELPERCLASS*)nullptr)->memberName), maxon::DESCRIBEFLAGS::REFERS_TO_HELPER)

	//----------------------------------------------------------------------------------------
	/// Describes a class member with condition for I/O operations within DescribeIO.
	/// It requires a previous call to PrepareDescribe.
	/// Compared to Describe it additionally introduces a condition for following class members.
	/// Every DescribeIf must be paired with exactly one DescribeEndIf.
	/// @link io_overview_conditions @endlink
	/// @param[in] name								The clear-text name of an element in the file format. It can be arbitrarily chosen, but usually matches the respective member name. Once it has been used in files
	///																the identifier needs to stay the same to remain compatible (unless some conversion code is added). The name must only contain (latin) alphanumeric characters
	///																or '_' and it must not start with a numeric character.
	///																'name' must be permanently available (and not only during the time of this call).
	/// @param[in] memberName					The name of the class member that will be described.
	/// @param[in] type								The DataType of the class member. While this could be automatically determined, this manual specification is necessary so that a change to a member type doesn't go unnoticed
	///																and damages the file integrity.
	/// @param[in] flags							One of the following: DESCRIBEFLAGS::TYPE_SET, DESCRIBEFLAGS::TYPE_MAP, DESCRIBEFLAGS::TYPE_ARRAY, DESCRIBEFLAGS::TYPE_UNIQUEREF, DESCRIBEFLAGS::TYPE_WEAKREF, DESCRIBEFLAGS::NONE.
	///																It can be combined with DESCRIBEFLAGS::DONT_WRITE, DESCRIBEFLAGS::ACTION_BEFORE_WRITE and DESCRIBEFLAGS::ACTION_AFTER_READ.
	/// @param[in] mask								The 64-bit unsigned comparison mask.
	/// @param[in] value							The 64-bit comparison value. The condition is met if (read_or_written_value & mask) == value.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	#define DescribeIf(name, memberName, type, flags, mask, value) descriptionStream.DescribeElement<DESCRIBECLASS, type, flags>(name, &(((DESCRIBECLASS*)nullptr)->memberName), maxon::DESCRIBEFLAGS::CONDITION_IF, mask, value)

	//----------------------------------------------------------------------------------------
	/// Describes a class member with condition for I/O operations within DescribeIO.
	/// It requires a previous call to PrepareDescribe and PrepareHelper.
	/// Other than DescribeIf this describes a member of the helper class.
	/// It additionally introduces a condition for following class members.
	/// Every DescribeHelperIf must be paired with exactly one DescribeEndIf.
	/// @link io_overview_conditions @endlink
	/// @link io_overview_helper @endlink
	/// @param[in] name								The clear-text name of an element in the file format. It can be arbitrarily chosen, but usually matches the respective member name. Once it has been used in files
	///																the identifier needs to stay the same to remain compatible (unless some conversion code is added). The name must only contain (latin) alphanumeric characters
	///																or '_' and it must not start with a numeric character.
	///																'name' must be permanently available (and not only during the time of this call).
	/// @param[in] memberName					The name of the class member that will be described.
	/// @param[in] type								The DataType of the class member. While this could be automatically determined, this manual specification is necessary so that a change to a member type doesn't go unnoticed
	///																and damages the file integrity.
	/// @param[in] flags							One of the following: DESCRIBEFLAGS::TYPE_SET, DESCRIBEFLAGS::TYPE_MAP, DESCRIBEFLAGS::TYPE_ARRAY, DESCRIBEFLAGS::TYPE_UNIQUEREF, DESCRIBEFLAGS::TYPE_WEAKREF, DESCRIBEFLAGS::NONE.
	///																It can be combined with DESCRIBEFLAGS::DONT_WRITE, DESCRIBEFLAGS::ACTION_BEFORE_WRITE and DESCRIBEFLAGS::ACTION_AFTER_READ.
	/// @param[in] mask								The 64-bit unsigned comparison mask.
	/// @param[in] value							The 64-bit comparison value. The condition is met if (read_or_written_value & mask) == value.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	#define DescribeHelperIf(name, memberName, type, flags, mask, value) descriptionStream.DescribeElement<IOHELPERCLASS, type, flags>(name, &(((IOHELPERCLASS*)nullptr)->memberName), maxon::DESCRIBEFLAGS::CONDITION_IF | maxon::DESCRIBEFLAGS::REFERS_TO_HELPER, mask, value)

	//----------------------------------------------------------------------------------------
	/// Declares and initializes an I/O helper class within DescribeIO. This can only be done once within DescribeIO and must happen before DescribeHelper or DescribeHelperIf are used.
	/// @link io_overview_helper @endlink
	/// @param[in] helperName					The name of the helper class.
	/// @param[in] flags							PREPAREHELPERFLAGS.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	#define PrepareHelper(helperName, flags) \
		descriptionStream.PrepareHelperClass<helperName, DESCRIBECLASS>(flags) iferr_return; \
		MAXON_WARNING_PUSH \
		MAXON_WARNING_DISABLE_UNUSED_LOCAL_TYPEDEF \
		using IOHELPERCLASS = helperName; \
		MAXON_WARNING_POP

	//----------------------------------------------------------------------------------------
	/// Describes an else condition within DescribeIO.
	/// It requires a previous (and matching) call to DescribeIf or DescribeHelperIf.
	/// @link io_overview_conditions @endlink
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	#define DescribeElse() descriptionStream.DescribeElement(nullptr, maxon::DataType::NullValue(), 0, nullptr, (maxon::DESCRIBEFLAGS)maxon::DESCRIBEFLAGS::CONDITION_ELSE, 0, 0)

	//----------------------------------------------------------------------------------------
	/// Describes an else if condition within DescribeIO.
	/// It requires a previous (and matching) call to DescribeIf or DescribeHelperIf.
	/// The calculation of the condition is based on the read or written value from DescribeIf/DescribeHelperIf.
	/// @link io_overview_conditions @endlink
	/// @param[in] mask								The 64-bit unsigned comparison mask.
	/// @param[in] value							The 64-bit comparison value. The condition is met if (read_or_written_value & mask) == value.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	#define DescribeElseIf(mask, value) descriptionStream.DescribeElement(nullptr, maxon::DataType::NullValue(), 0, nullptr, (maxon::DESCRIBEFLAGS)maxon::DESCRIBEFLAGS::CONDITION_ELSE, mask, value)

	//----------------------------------------------------------------------------------------
	/// Describes the end if an if condition within DescribeIO.
	/// It requires a previous (and matching) call to DescribeIf or DescribeHelperIf.
	/// @link io_overview_conditions @endlink
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	#define DescribeEndIf() descriptionStream.DescribeElement(nullptr, maxon::DataType::NullValue(), 0, nullptr, (maxon::DESCRIBEFLAGS)maxon::DESCRIBEFLAGS::CONDITION_END, 0, 0)


	// private helper templates, use any of the above defines instead
	template <typename HELPERCLASS, typename MAINCLASS> Result<void> PrepareHelperClass(PREPAREHELPERFLAGS flags) const
	{
		return PrepareHelperClass(&CreateHelper<HELPERCLASS>, &DeleteHelper<HELPERCLASS>, &ReadHelper<MAINCLASS, HELPERCLASS>, &WriteHelper<MAINCLASS, HELPERCLASS>, flags);
	}

	template <typename CLASSNAME, typename CMP, decltype(DESCRIBEFLAGS::_value) FLAGS, typename T> Result<void> DescribeElement(const Char* fileName, const UniqueRef<T>* member, decltype(DESCRIBEFLAGS::_value) additional, UInt64 mask = 0, UInt64 value = 0) const
	{
		static_assert(std::is_same<T, CMP>::value, "Describe: class does not match member type");
		static_assert((FLAGS & (DESCRIBEFLAGS::TYPE_ARRAY | DESCRIBEFLAGS::TYPE_MAP | DESCRIBEFLAGS::TYPE_SET | DESCRIBEFLAGS::TYPE_UNIQUEREF)) == DESCRIBEFLAGS::TYPE_UNIQUEREF, "Describe: class is a standard datatype - illegal flags set");
		static_assert((FLAGS & (DESCRIBEFLAGS::APPLY_TO_KEY | DESCRIBEFLAGS::REFERS_TO_HELPER | DESCRIBEFLAGS::CONDITION_IF | DESCRIBEFLAGS::CONDITION_ELSE | DESCRIBEFLAGS::CONDITION_END | DESCRIBEFLAGS::IS_LEGACY_ELEMENT)) == DESCRIBEFLAGS::NONE, "Describe: class is a standard datatype - illegal flags set");
		return DescribeElement(fileName, maxon::GetDataType<T>(), (size_t)member, nullptr, (DESCRIBEFLAGS)(FLAGS | additional), mask, value);
	}

	template <typename CLASSNAME, typename CMP, decltype(DESCRIBEFLAGS::_value) FLAGS, typename T> Result<void> DescribeElement(const Char* fileName, const WeakRef<T>* member, decltype(DESCRIBEFLAGS::_value) additional, UInt64 mask = 0, UInt64 value = 0) const
	{
		static_assert(std::is_same<T, CMP>::value, "Describe: class does not match member type");
		static_assert((FLAGS & (DESCRIBEFLAGS::TYPE_ARRAY | DESCRIBEFLAGS::TYPE_MAP | DESCRIBEFLAGS::TYPE_SET | DESCRIBEFLAGS::TYPE_WEAKREF)) == DESCRIBEFLAGS::TYPE_WEAKREF, "Describe: class is a standard datatype - illegal flags set");
		static_assert((FLAGS & (DESCRIBEFLAGS::APPLY_TO_KEY | DESCRIBEFLAGS::REFERS_TO_HELPER | DESCRIBEFLAGS::CONDITION_IF | DESCRIBEFLAGS::CONDITION_ELSE | DESCRIBEFLAGS::CONDITION_END | DESCRIBEFLAGS::IS_LEGACY_ELEMENT)) == DESCRIBEFLAGS::NONE, "Describe: class is a standard datatype - illegal flags set");
		return DescribeElement(fileName, maxon::GetDataType<T>(), (size_t)member, nullptr, (DESCRIBEFLAGS)(FLAGS | additional), mask, value);
	}

	template <typename CLASSNAME, typename CMP, decltype(DESCRIBEFLAGS::_value) FLAGS, typename T> typename std::enable_if<GetCollectionKind<T>::value == COLLECTION_KIND::NONE, Result<void>>::type DescribeElement(const Char* fileName, const T* member, decltype(DESCRIBEFLAGS::_value) additional, UInt64 mask = 0, UInt64 value = 0) const
	{
		static_assert(std::is_same<T, CMP>::value, "Describe: class does not match member type");
		static_assert((FLAGS & (DESCRIBEFLAGS::TYPE_ARRAY | DESCRIBEFLAGS::TYPE_MAP | DESCRIBEFLAGS::TYPE_SET | DESCRIBEFLAGS::TYPE_UNIQUEREF)) == 0, "Describe: class is a standard datatype - illegal flags set");
		static_assert((FLAGS & (DESCRIBEFLAGS::APPLY_TO_KEY | DESCRIBEFLAGS::REFERS_TO_HELPER | DESCRIBEFLAGS::CONDITION_IF | DESCRIBEFLAGS::CONDITION_ELSE | DESCRIBEFLAGS::CONDITION_END | DESCRIBEFLAGS::TYPE_UNIQUEREF | DESCRIBEFLAGS::IS_LEGACY_ELEMENT)) == DESCRIBEFLAGS::NONE, "Describe: class is a standard datatype - illegal flags set");
		return DescribeElement(fileName, maxon::GetDataType<T>(), (size_t)member, nullptr, (DESCRIBEFLAGS)(FLAGS | additional), mask, value);
	}

	template <typename CLASSNAME, typename CMP, decltype(DESCRIBEFLAGS::_value) FLAGS, typename T> typename std::enable_if<GetCollectionKind<T>::value == COLLECTION_KIND::ARRAY, Result<void>>::type DescribeElement(const Char* fileName, const T* member, decltype(DESCRIBEFLAGS::_value) additional) const
	{
		static_assert(std::is_same<typename T::ValueType, CMP>::value, "Describe: class does not match member value type");
		static_assert((FLAGS & (DESCRIBEFLAGS::TYPE_ARRAY | DESCRIBEFLAGS::TYPE_MAP | DESCRIBEFLAGS::TYPE_SET | DESCRIBEFLAGS::TYPE_UNIQUEREF | DESCRIBEFLAGS::TYPE_WEAKREF)) == DESCRIBEFLAGS::TYPE_ARRAY, "Describe: class is an Array datatype - illegal flags set");
		static_assert((FLAGS & (DESCRIBEFLAGS::APPLY_TO_KEY | DESCRIBEFLAGS::REFERS_TO_HELPER | DESCRIBEFLAGS::CONDITION_IF | DESCRIBEFLAGS::CONDITION_ELSE | DESCRIBEFLAGS::CONDITION_END | DESCRIBEFLAGS::IS_LEGACY_ELEMENT)) == DESCRIBEFLAGS::NONE, "Describe: class is an Array datatype - illegal flags set");
		return DescribeElement(fileName, maxon::GetDataType<typename T::ValueType>(), (size_t)member, &ArrayConversionHelper<T>, (DESCRIBEFLAGS)(FLAGS | additional), 0, 0);
	}

	template <typename CLASSNAME, typename CMP, decltype(DESCRIBEFLAGS::_value) FLAGS, typename T> typename std::enable_if<GetCollectionKind<T>::value == COLLECTION_KIND::SET, Result<void>>::type DescribeElement(const Char* fileName, const T* member, decltype(DESCRIBEFLAGS::_value) additional) const
	{
		static_assert(std::is_same<typename T::ValueType, CMP>::value, "Describe: class does not match member value type");
		static_assert((FLAGS & (DESCRIBEFLAGS::TYPE_ARRAY | DESCRIBEFLAGS::TYPE_MAP | DESCRIBEFLAGS::TYPE_SET | DESCRIBEFLAGS::TYPE_UNIQUEREF | DESCRIBEFLAGS::TYPE_WEAKREF)) == DESCRIBEFLAGS::TYPE_SET, "Describe: class is a Set datatype - illegal flags set");
		static_assert((FLAGS & (DESCRIBEFLAGS::APPLY_TO_KEY | DESCRIBEFLAGS::REFERS_TO_HELPER | DESCRIBEFLAGS::CONDITION_IF | DESCRIBEFLAGS::CONDITION_ELSE | DESCRIBEFLAGS::CONDITION_END | DESCRIBEFLAGS::IS_LEGACY_ELEMENT)) == DESCRIBEFLAGS::NONE, "Describe: class is a Set datatype - illegal flags set");
		return DescribeElement(fileName, maxon::GetDataType<typename T::ValueType>(), (size_t)member, &SetConversionHelper<T>, (DESCRIBEFLAGS)(FLAGS | additional), 0, 0);
	}

	template <typename CLASSNAME, typename CMP, decltype(DESCRIBEFLAGS::_value) FLAGS, typename T> typename std::enable_if<GetCollectionKind<T>::value == COLLECTION_KIND::MAP, Result<void>>::type DescribeElement(const Char* fileName, const T* member, decltype(DESCRIBEFLAGS::_value) additional) const
	{
		static_assert(std::is_same<typename T::KeyType, typename CMP::FirstType>::value, "Describe: Pair::first does not match member key type of Map");
		static_assert(std::is_same<typename T::ValueType, typename CMP::SecondType>::value, "Describe:: Pair::second does not match member value type of Map");
		static_assert((FLAGS & (DESCRIBEFLAGS::TYPE_ARRAY | DESCRIBEFLAGS::TYPE_MAP | DESCRIBEFLAGS::TYPE_SET | DESCRIBEFLAGS::TYPE_UNIQUEREF | DESCRIBEFLAGS::TYPE_WEAKREF)) == DESCRIBEFLAGS::TYPE_MAP, "Describe: class is a Map datatype, but illegal flags set");
		static_assert((FLAGS & (DESCRIBEFLAGS::REFERS_TO_HELPER | DESCRIBEFLAGS::CONDITION_IF | DESCRIBEFLAGS::CONDITION_ELSE | DESCRIBEFLAGS::CONDITION_END | DESCRIBEFLAGS::IS_LEGACY_ELEMENT)) == DESCRIBEFLAGS::NONE, "Describe: class is a Map datatype - illegal flags set");

		decltype(DESCRIBEFLAGS::_value) origFlags = FLAGS | additional;
		decltype(DESCRIBEFLAGS::_value) flags = origFlags;
		if (flags & DESCRIBEFLAGS::APPLY_TO_KEY)
			flags &= ~(DESCRIBEFLAGS::TYPE_DATATYPE | DESCRIBEFLAGS::RECEIVE_DATATYPE);

		iferr (DescribeElement(fileName, maxon::GetDataType<typename T::ValueType>(), (size_t)member, &MapConversionHelper<T>, (DESCRIBEFLAGS)flags, 0, 0))
			return err;

		if (!(origFlags & DESCRIBEFLAGS::APPLY_TO_KEY))
			origFlags &= ~(DESCRIBEFLAGS::TYPE_DATATYPE | DESCRIBEFLAGS::RECEIVE_DATATYPE);

		return DescribeElement(fileName, maxon::GetDataType<typename T::KeyType>(), 0, nullptr, (DESCRIBEFLAGS)origFlags, 0, 0);
	}
};

//----------------------------------------------------------------------------------------
/// This class serializes data into a specific file format.
//----------------------------------------------------------------------------------------
class DataSerializeWriterInterface : MAXON_INTERFACE_BASES(DataSerializeInterface)
{
	MAXON_INTERFACE(DataSerializeWriterInterface, MAXON_REFERENCE_NORMAL, "net.maxon.interface.dataserializewriter");

public:
	//----------------------------------------------------------------------------------------
	/// Writes the given object into a serialized stream.
	/// @param[in] id									The identifier of the file.
	/// @param[in] data								The object's datatype and address.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> WriteDocument(const Id& id, const ConstDataPtr& data);
};


//----------------------------------------------------------------------------------------
/// This class serializes data from a specific file format.
//----------------------------------------------------------------------------------------
class DataSerializeReaderInterface : MAXON_INTERFACE_BASES(DataSerializeInterface)
{
	MAXON_INTERFACE(DataSerializeReaderInterface, MAXON_REFERENCE_NORMAL, "net.maxon.interface.dataserializereader");

public:
	//----------------------------------------------------------------------------------------
	/// Reads the given object from a serialized stream.
	/// @param[in] id									The identifier of the file.
	/// @param[in] data								The object's datatype and address.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> ReadDocument(const Id& id, const DataPtr& data);
};


#include "dataserialize1.hxx"

//----------------------------------------------------------------------------------------
/// Default implementation of DataSerializeInterface.
//----------------------------------------------------------------------------------------
MAXON_DECLARATION(Class<DataSerializeRef>, DataSerializeBaseClass, "net.maxon.class.dataserializebase");

//----------------------------------------------------------------------------------------
/// Default implementation of DataSerializeReaderInterface.
//----------------------------------------------------------------------------------------
MAXON_DECLARATION(Class<DataSerializeReaderRef>, DataSerializeReaderClass, "net.maxon.class.dataserializereader");

//----------------------------------------------------------------------------------------
/// Default implementation of DataSerializeWriterInterface.
//----------------------------------------------------------------------------------------
MAXON_DECLARATION(Class<DataSerializeWriterRef>, DataSerializeWriterClass, "net.maxon.class.dataserializewriter");

#include "dataserialize2.hxx"

}

#endif // DATASERIALIZE_H__
