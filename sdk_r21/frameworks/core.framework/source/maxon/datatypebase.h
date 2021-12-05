#ifndef DATATYPEBASE_H__
#define DATATYPEBASE_H__

#include "maxon/collection.h"
#include "maxon/baseref.h"

// enable to test also the code without move constructor!
// #undef _HAS_MOVE_CONSTRUCTOR

namespace maxon
{

/// @addtogroup DATATYPE
/// @{

class DataSerializeReaderRef;
class DataSerializeWriterRef;
class DataSerializeInterface;

//----------------------------------------------------------------------------------------
/// DataMemBlock is the placeholder for values stored in a generic Data object.
/// If the actual value fits into the memory block it is stored directly in the block,
/// otherwise memory has to be allocated, and just the pointer is stored in the block.
//----------------------------------------------------------------------------------------
struct DataMemBlock
{
	Int64 dummy;	///< memory block to reserve memory. Has to be big enough to hold a pointer. Its alignment also has to match the alignment of a pointer.
};

class String;

class TupleDataType;
class FunctionDataType;
class DelegateDataType;

class InterfaceReference;
class InterfaceDefinition;
class NonvirtualInterfaceImplementation;


struct Member;
struct NamedTupleMembers;
struct TypeArguments;
class ParametricTypeInterface;

class ConstDataPtr;
class DataPtr;
class MoveDataPtr;
struct ForwardingDataPtr;

struct SimdInfo;


//----------------------------------------------------------------------------------------
/// This enum defines flags for a DataType conversion.
/// @see AddConversion
/// @see Convert
//----------------------------------------------------------------------------------------
enum class CONVERSION_FLAGS
{
	NONE = 0,																							///< When no other flags are set, the conversion is a one-to-one correspondence (such as from Float to TimeValue and back).
	NARROWING = 1,																				///< The conversion contains a narrowing conversion. The conversion may not always be possible (such as converting a negative Int to a UInt), then it returns an error.
	WIDENING_LOSSY = 2,																		///< The conversion contains a widening conversion which is always possible, but it might result in loss of precision (a Float64 can't represent all bits of an Int64).
	WIDENING_LOSSLESS = 4,																///< The conversion contains a lossless widening conversion.
	REDUCING = 8,																					///< The conversion contains a reducing conversion such as from a vector to a scalar (or a higher-dimensional vector to a lower-dimensional vector).
	EXPANDING = 16,																				///< The conversion contains an expanding conversion such as from a scalar to a vector (or a lower-dimensional vector to a higher-dimensional vector).
	STRUCT_CAST = 32,																			///< The conversion contains a cast between layout-compatible structs (such as from Vector to Color).
	INCONVERTIBLE = 1024,																	///< No conversion possible.
	WIDENING_MASK = WIDENING_LOSSY | WIDENING_LOSSLESS,		///< Mask to check for a widening conversion (combination of WIDENING_LOSSY and WIDENING_LOSSLESS).
	NARROWING_REDUCING_MASK = NARROWING | REDUCING				///< Mask to check for a narrowing or reducing conversion (combination of NARROWING and REDUCING).
} MAXON_ENUM_FLAGS(CONVERSION_FLAGS);



class DataTypeImpl;

class DataTypePtr
{
public:
	DataTypePtr() = default;

	MAXON_IMPLICIT DataTypePtr(const DataType& type);

	explicit DataTypePtr(const DataTypeImpl* type) : _ptr(type)
	{
	}

	operator const DataType&() const
	{
		return *reinterpret_cast<const DataType*>(this);
	}

	const DataType& Get() const
	{
		return *reinterpret_cast<const DataType*>(this);
	}

	const DataTypeImpl* operator ->() const
	{
		return _ptr;
	}

	explicit operator Bool() const
	{
		return _ptr != nullptr;
	}

	Bool operator ==(const DataTypePtr& other) const
	{
		return _ptr == other._ptr;
	}

	Bool operator !=(const DataTypePtr& other) const
	{
		return _ptr != other._ptr;
	}

	UInt GetHashCode() const
	{
		return DefaultCompare::GetHashCode(_ptr);
	}

	void Reset()
	{
		_ptr = nullptr;
	}

private:
	const DataTypeImpl* _ptr = nullptr;
};


class DataTypeImpl
{
public:
	//----------------------------------------------------------------------------------------
	/// Constructs a DataTypeImpl for T and sets the functions pointers to the implementations found in C.
	/// @tparam T											Type which this DataType shall represent.
	/// @tparam C											Class which implements the DataType functions as static functions.
	/// @param[in] type								Unique id of the data type.
	/// @param[in] underlying					The underlying, layout-compatible type, may be nullptr.
	/// @param[in] element						The element type (used e.g. for arrays or pointers), may be nullptr.
	/// @param[in] dummy1							Dummy variable to determine T.
	/// @param[in] dummy2							Dummy variable to determine C.
	/// @param[in] flags							Extra flags for the VALUEKIND of the datatype.
	/// @param[in] impl								Pointer to the implementation if the datatype stands for a non-virtual interface, otherwise nullptr.
	/// @param[in] kind								The VALUEKIND of the datatype, by default set to the value determined by ValueKindHelper.
	//----------------------------------------------------------------------------------------
	template <typename T, typename C> DataTypeImpl(const Id& type, const DataTypeImpl* underlying, const DataTypeImpl* element, const T* dummy1, const C* dummy2,
																								 VALUEKIND flags = VALUEKIND::NONE, const NonvirtualInterfaceImplementation* impl = nullptr,
																								 VALUEKIND kind = ValueKindHelper<T, GetDirectlyReferencedType<T>::value>::KIND, const ParametricTypeInterface* pt = nullptr)
		: _id(type), _size(SIZEOF(T)), _alignment(alignof(T)), _valueKind(kind | flags | ((SIZEOF(T) <= SIZEOF(Int)) ? VALUEKIND::INT_SIZE_OR_LESS : VALUEKIND::NONE) | C::CAPABILITY_FLAGS),
		_underlying(underlying), _elementType(element), _parametricType(pt), _implementation(impl), _conversions(),
		_construct(&C::Construct), _destruct(&C::Destruct), _moveConstruct(&C::MoveConstruct), _moveFrom(&C::MoveFrom), _copyFrom(&C::CopyFrom), _updateFrom(&C::UpdateFrom),
		_addReference(&C::AddReference), _removeReference(&C::RemoveReference),
		_toString(&C::ToStringImpl), _isEqual(&C::IsEqual), _compare(&C::Compare), _getHashCode(&C::GetHashCode),
		_describeIO(&C::DescribeIO), _newInstance(&C::Create),
		_initData(&C::InitData), _freeData(&C::FreeData), _copyData(&C::CopyData), _initCopyData(&C::InitCopyData), _moveData(&C::MoveData), _initMoveData(&C::InitMoveData),
		_getPtr(&C::GetPtr),
		_isEqualData(&C::IsEqualData)
	{
		static_assert(!std::is_const<T>::value, "Can't create const primary data type.");
		DebugAssert(Bool(_valueKind & VALUEKIND::INT_SIZE_OR_LESS) == (_size <= SIZEOF(Int)));
		DebugAssert(!underlying || underlying->_size == _size);
	}

	//----------------------------------------------------------------------------------------
	/// Constructs a DataTypeImpl and sets the functions pointers to the implementations found in C.
	/// @tparam C											Class which implements the DataType functions as static functions.
	/// @param[in] type								Unique id of the data type.
	/// @param[in] underlying					The underlying, layout-compatible type, may be nullptr.
	/// @param[in] element						The element type (used e.g. for arrays or pointers), may be nullptr.
	/// @param[in] size								The size of the type.
	/// @param[in] alignment					The alignment of the type.
	/// @param[in] dummy2							Dummy variable to determine C.
	/// @param[in] kind								The complete VALUEKIND of the datatype.
	/// @param[in] pt									The parametric type which instantiates the DataType, may be nullptr.
	//----------------------------------------------------------------------------------------
	template <typename C> DataTypeImpl(const Id& type, const DataTypeImpl* underlying, const DataTypeImpl* element, Int size, Int alignment, const C* dummy2, VALUEKIND kind, const ParametricTypeInterface* pt = nullptr)
		: _id(type), _size(size), _alignment(alignment), _valueKind((size <= SIZEOF(Int)) ? kind | VALUEKIND::INT_SIZE_OR_LESS : kind),
		_underlying(underlying), _elementType(element), _parametricType(pt), _typeArgs(nullptr), _conversions(),
		_construct(&C::Construct), _destruct(&C::Destruct), _moveConstruct(&C::MoveConstruct), _moveFrom(&C::MoveFrom), _copyFrom(&C::CopyFrom), _updateFrom(&C::UpdateFrom),
		_addReference(&C::AddReference), _removeReference(&C::RemoveReference),
		_toString(&C::ToStringImpl), _isEqual(&C::IsEqual), _compare(&C::Compare), _getHashCode(&C::GetHashCode),
		_describeIO(&C::DescribeIO), _newInstance(&C::Create),
		_initData(&C::InitData), _freeData(&C::FreeData), _copyData(&C::CopyData), _initCopyData(&C::InitCopyData), _moveData(&C::MoveData), _initMoveData(&C::InitMoveData),
		_getPtr(&C::GetPtr),
		_isEqualData(&C::IsEqualData)
	{
		DebugAssert(Bool(_valueKind & VALUEKIND::INT_SIZE_OR_LESS) == (_size <= SIZEOF(Int)));
		DebugAssert(!underlying || underlying->_size == _size);
	}

	DataTypeImpl() : _id("uninitialized"), _size(0), _alignment(0), _valueKind(VALUEKIND::NONE), _underlying(), _elementType(), _parametricType(nullptr), _typeArgs(nullptr), _conversions(),
		_construct(nullptr), _destruct(nullptr),
		_moveConstruct(nullptr), _moveFrom(nullptr), _copyFrom(nullptr), _updateFrom(nullptr), _addReference(nullptr), _removeReference(nullptr),
		_toString(nullptr), _isEqual(nullptr), _compare(nullptr), _getHashCode(nullptr),
		_describeIO(nullptr), _newInstance(nullptr),
		_initData(nullptr), _freeData(nullptr),
		_copyData(nullptr), _initCopyData(nullptr), _moveData(nullptr), _initMoveData(nullptr),
		_getPtr(nullptr), _isEqualData(nullptr)
	{
	}

	// constructor for qualified version of base
	DataTypeImpl(const DataTypeImpl& src, const Id& typeId, VALUEKIND qualification, const ParametricTypeInterface* pt, VALUEKIND remove = VALUEKIND::NONE) : _id(typeId),
		MAXON_COPY_MEMBERS(_size, _alignment), _valueKind((src._valueKind & ~remove) | qualification),
		_underlying(&src), MAXON_COPY_MEMBERS(_elementType), _parametricType(pt), MAXON_COPY_MEMBERS(_typeArgs), _conversions(),
		MAXON_COPY_MEMBERS(_construct, _destruct, _moveConstruct, _moveFrom, _copyFrom, _updateFrom, _addReference, _removeReference, _toString, _isEqual, _compare, _getHashCode,
											 _describeIO, _newInstance, _initData, _freeData, _copyData, _initCopyData, _moveData, _initMoveData,
											 _getPtr, _isEqualData)
	{
		if (HasTypeArguments())
		{
			StrongReferenceCounter::Get(_typeArgs).Inc();
		}
		DebugAssert(!(qualification & ~(VALUEKIND::QUALIFIER_MASK | VALUEKIND::FUNCTION | VALUEKIND::ENUM | VALUEKIND::ENUM_LIST | VALUEKIND::ENUM_FLAGS | VALUEKIND::DELEGATE)));
	}

	//----------------------------------------------------------------------------------------
	/// Returns the identifier of this data type. Data type identifiers of primary types
	/// look like @c int32, pointer types are identified by a * suffix
	/// as in @c{float64*}, tuple types by a parenthesized list of its member types as in @c{(int32,float64*)}.
	/// @return												Unique identifier of this type.
	//----------------------------------------------------------------------------------------
	const Id& GetId() const { return _id; }

	/// @copydoc DefaultDoc::ToString
	String ToString(const FormatStatement* formatStatement) const;

	//----------------------------------------------------------------------------------------
	/// Returns the size of values of this data type.
	/// @return												Size of values.
	//----------------------------------------------------------------------------------------
	Int GetSize() const { return _size; }

	//----------------------------------------------------------------------------------------
	/// Returns the alignment of values of this data type. This might by an extended alignment.
	/// @return												Alignment of values.
	//----------------------------------------------------------------------------------------
	Int GetAlignment() const { return _alignment; }

	//----------------------------------------------------------------------------------------
	/// Returns the kind of values of this data type. This is a coarse classification
	/// to distinguish between e.g. value types, pointers, references, arrays and tuples.
	/// @return												Kind of values.
	//----------------------------------------------------------------------------------------
	VALUEKIND GetValueKind() const { return _valueKind; }

	//----------------------------------------------------------------------------------------
	/// Tests the value kind of this data type for the given flags (by using the bitwise and).
	/// @param[in] test								The flags to test.
	/// @return												True if the value kind of this data type has one of the given flags, false otherwise.
	//----------------------------------------------------------------------------------------
	Bool CheckValueKind(VALUEKIND test) const { return (Bool)(_valueKind & test); }

	//----------------------------------------------------------------------------------------
	/// Returns the unqualified type of this data type. Currently the only possible qualification
	/// is a const qualification. So when this data type represents const T, the returned data type
	/// represents T. If the type is already an unqualified type, this functions returns the type
	/// itself.
	/// @return												This type with any qualifications removed (or this type itself if it is already unqualified).
	//----------------------------------------------------------------------------------------
	const DataTypeImpl* GetUnqualifiedType() const
	{
		const DataTypeImpl* t = this;
		while (t->_valueKind & VALUEKIND::QUALIFIER_MASK)
		{
			t = t->_underlying;
		}
		return t;
	}

	//----------------------------------------------------------------------------------------
	/// Returns the underlying type of this data type. The underlying data type is a layout-compatible
	/// more fundamental type, such as the unqualified version T for const T, or the tuple type
	/// Tuple<T, T, T> for Vec3<T>.
	/// @return												The underlying type of this type, or nullptr.
	//----------------------------------------------------------------------------------------
	const DataType& GetUnderlyingType() const
	{
		return reinterpret_cast<const DataType&>(_underlying);
	}

	//----------------------------------------------------------------------------------------
	/// Returns the element type of this data type. The element type is used for some parametric
	/// types such as pointers or references, so for example the element type of
	/// @c{T*} or @c{StrongRef<T>} is @c T.
	/// @return												The element type of this type, or nullptr.
	//----------------------------------------------------------------------------------------
	const DataType& GetElementType() const
	{
		return reinterpret_cast<const DataType&>(_elementType);
	}

	//----------------------------------------------------------------------------------------
	/// Returns the decayed type of this data type (in the sense of std::decay). I.e., at first this
	/// removes any l- or r-value-reference-qualification, and then it returns the unqualified
	/// type of the result.
	/// @return												The decayed type of this type, maybe this type itself.
	//----------------------------------------------------------------------------------------
	const DataTypeImpl* GetDecayedType() const
	{
		const DataTypeImpl* t = (_valueKind & VALUEKIND::REFERENCE_MASK) ? _elementType.GetPointer() : this;
		return t->GetUnqualifiedType();
	}

	//----------------------------------------------------------------------------------------
	/// Returns true if this data type has valid type arguments, so that it is legal to call GetTypeArguments().
	/// @return												True if this type has valid type arguments, false otherwise.
	//----------------------------------------------------------------------------------------
	Bool HasTypeArguments() const
	{
		return _typeArgs && !(_valueKind & (VALUEKIND::VIRTUAL_INTERFACE | VALUEKIND::NONVIRTUAL_INTERFACE));
	}

	//----------------------------------------------------------------------------------------
	/// Returns the type arguments of this data type. Type arguments are set for some instantiations
	/// of parametric types. For example, the 3-dimensional Vector is an instantiation of the parametric type
	/// Vec with the arguments (Float, 3).
	/// @return												The type arguments of this type.
	//----------------------------------------------------------------------------------------
	const TypeArguments& GetTypeArguments() const
	{
		DebugAssert(HasTypeArguments());
		return *_typeArgs;
	}

	//----------------------------------------------------------------------------------------
	/// Returns the parametric type which instantiated this type. For example if this type is
	/// Vector, the function returns the parametric type Vec.
	/// @return												The parametric type which instantiated this type, or nullptr.
	//----------------------------------------------------------------------------------------
	const ParametricTypeInterface* GetParametricType() const
	{
		return _parametricType;
	}

	//----------------------------------------------------------------------------------------
	/// Returns the SimdInfo of this type. This type has to be a SIMD type (or a qualified version thereof),
	/// otherwise the behavior is undefined.
	/// @return												SimdInfo of this type.
	//----------------------------------------------------------------------------------------
	const SimdInfo& GetSimdInfo() const
	{
		DebugAssert(_valueKind & VALUEKIND::SIMD);
		const DataTypeImpl* t = GetUnqualifiedType();
		return reinterpret_cast<const SimdInfo&>(t[1]);
	}

	//----------------------------------------------------------------------------------------
	/// Returns the interface implementation of this type as nullptr-terminated array. This function
	/// may only be invoked if this type is an interface type.
	/// @return												The interface implementation of this interface type.
	//----------------------------------------------------------------------------------------
	const NonvirtualInterfaceImplementation* GetImplementation() const
	{
		DebugAssert(_valueKind & VALUEKIND::NONVIRTUAL_INTERFACE);
		return _implementation;
	}

	//----------------------------------------------------------------------------------------
	/// Returns the interfaces of this object type as nullptr-terminated array. This function
	/// may only be invoked if this type is an object type.
	/// @return												The interfaces of this object type.
	//----------------------------------------------------------------------------------------
	const InterfaceDefinition* const* GetInterfaces() const
	{
		DebugAssert(_valueKind & VALUEKIND::VIRTUAL_INTERFACE);
		return _interfaces;
	}

	
	//----------------------------------------------------------------------------------------
	/// Creates a new instance of this type.
	/// - If this type is a non-virtual interface, the new instance will be created by NewObj.
	/// - If this type is an array type TODO: (Ole) implement
	/// - If this type is a virtual interface type, an error is returned because only classes can be instantiated, not interfaces.
	/// - Otherwise, the new instance will be initialized by the default constructor. For reference types,
	///   this means that the reference will point to nullptr.
	/// @return												New instance of this data type. The caller owns the new instance.
	//----------------------------------------------------------------------------------------
	Result<void*> Create() const { return _newInstance(this); }

	//----------------------------------------------------------------------------------------
	/// Constructs @p count values of this type starting at @p dest. Each value will be
	/// constructed using its default constructor.
	/// @param[in,out] dest						Pointer to the destination array.
	/// @param[in] count							Number of values to construct in the destination array.
	//----------------------------------------------------------------------------------------
	void Construct(void* dest, Int count) const { return _construct(this, dest, count); }

	//----------------------------------------------------------------------------------------
	/// Destructs @p count values of this type starting at @p dest.
	/// @param[in,out] dest						Pointer to the destination array.
	/// @param[in] count							Number of values to destruct in the destination array.
	//----------------------------------------------------------------------------------------
	void Destruct(const void* dest, Int count) const { return _destruct(this, dest, count); }

	//----------------------------------------------------------------------------------------
	/// Move-constructs @p count values of this type starting at @p dest using source values
	/// starting at @p src. This will be done by the move constructor of the underlying
	/// type which might modify @p src.
	/// @param[in,out] dest						Pointer to the destination array.
	/// @param[in,out] src						Pointer to the source array.
	/// @param[in] count							Number of values to move-construct in the destination array.
	//----------------------------------------------------------------------------------------
	void MoveConstruct(void* dest, void* src, Int count) const { return _moveConstruct(this, dest, src, count); }

	//----------------------------------------------------------------------------------------
	/// Moves @p count values of this type starting at @p dest from source values
	/// starting at @p src. This will be done by the move assignment operator of the underlying
	/// type which might modify @p src. The blocks must not overlap.
	/// @param[in,out] dest						Pointer to the destination array.
	/// @param[in,out] src						Pointer to the source array.
	/// @param[in] count							Number of values to move to the destination array.
	/// @warning The blocks pointed to by #dest and #src must not overlap.
	//----------------------------------------------------------------------------------------
	void MoveFrom(void* dest, void* src, Int count) const { return _moveFrom(this, dest, src, count); }

	//----------------------------------------------------------------------------------------
	/// Copies @p count values of this type starting at @p dest using source values
	/// starting at @p src. This will be done by the CopyFrom function of the underlying
	/// type if available, otherwise by the assignment operator.
	/// @param[in,out] dest						Pointer to the destination array.
	/// @param[in] src								Pointer to the source array.
	/// @param[in] count							Number of values to copy to the destination array.
	/// @return												True if all values could be copied successfully.
	//----------------------------------------------------------------------------------------
	Result<void> CopyFrom(void* dest, const void* src, Int count) const { return _copyFrom(this, dest, src, count); }

	//----------------------------------------------------------------------------------------
	/// Updates the the values of the type at @p dest if it is not equal to the source values
	/// starting at @p src.
	/// @param[in,out] dest						Pointer to the destination array.
	/// @param[in] src								Pointer to the source array.
	/// @return												True if all values could be copied successfully.
	//----------------------------------------------------------------------------------------
	Result<Bool> UpdateFrom(void* dest, const void* src) const { return _updateFrom(this, dest, src); }

	//----------------------------------------------------------------------------------------
	/// Adds a reference to the given object. This increments the reference counter by one.
	/// @param[in] obj								Pointer to an object of this data type.
	//----------------------------------------------------------------------------------------
	void AddReference(const void* obj) const { return _addReference(this, obj); }

	//----------------------------------------------------------------------------------------
	/// Removes a reference from the given object and frees the object if necessary.
	/// This decrements the reference counter by one. If the counter reaches zero,
	/// the object is freed.
	/// @param[in] obj								Pointer to an object of this data type.
	//----------------------------------------------------------------------------------------
	void RemoveReference(const void* obj) const { return _removeReference(this, obj); }

	//----------------------------------------------------------------------------------------
	/// Returns a readable string from a value of this data type.
	/// @param[in] s									Pointer to the native data.
	/// @param[in] formatStatement		The formatting instruction.
	/// @return												Readable string for the data value.
	//----------------------------------------------------------------------------------------
	String ToString(const void* s, const FormatStatement* formatStatement) const;

	//----------------------------------------------------------------------------------------
	/// Compares two values of this data type for equality.
	/// @param[in] s1									Pointer to the native data of argument 1.
	/// @param[in] s2									Pointer to the native data of argument 2.
	/// @param[in] equality						Mode of comparison.
	/// @return												Returns if both values are equal.
	//----------------------------------------------------------------------------------------
	Bool IsEqual(const void* s1, const void* s2, EQUALITY equality) const { return _isEqual(this, s1, s2, equality); }

	//----------------------------------------------------------------------------------------
	/// Compares two values of this data type.
	/// @param[in] s1									Pointer to the native data of argument 1.
	/// @param[in] s2									Pointer to the native data of argument 2.
	/// @return												Result of the comparison.
	//----------------------------------------------------------------------------------------
	COMPARERESULT Compare(const void* s1, const void* s2) const { return _compare(this, s1, s2); }

	//----------------------------------------------------------------------------------------
	/// Get the HashCode of the value of this data type.
	/// @param[in] s1									Pointer to the native data of argument.
	/// @return												Returns 0 if no hascode could be calculated for this datatype, otherwise the hash code.
	//----------------------------------------------------------------------------------------
	UInt GetHashCode(const void* s1) const { return _getHashCode(this, s1); }

	//----------------------------------------------------------------------------------------
	/// Describe all elements of this datatype for I/O operations.
	/// @param[in] stream							The stream that is used to register the class members.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	Result<void> DescribeIO(const DataSerializeInterface& stream) const
	{
		return _describeIO(this, stream);
	}

	Result<void> PrivateRegister() const;

	// Used internally.
	// @param[in] tupleType						The underlying tuple type.
	// @param[in] offsets							The member offsets of @c tupleType as an array. This is only used for safety checks.
	void PrivateSetStructType(const TupleDataType& tupleType, const Int* offsets);

	void PrivateSetTypeArgs(StrongRef<const TypeArguments>&& args)
	{
		DebugAssert(!_typeArgs);
		new (&_typeArgs) StrongRef<const TypeArguments>(std::move(args));
	}

	class Primary;
	class Instantiated;

protected:
	~DataTypeImpl();

	void ResetRefs();

	MAXON_DISALLOW_COPY_AND_ASSIGN(DataTypeImpl);

	void AddReference() const;

	void RemoveReference() const;

	friend class Data;
	friend class DataType;
	friend class DataTypeLibImpl;
	friend class ObjectModel;
	friend class StrongRefHandler;

	const Id _id; ///< name of the data type.
	const Int _size;	///< size of the data type.
	const Int _alignment;	///< alignment of the data type.
	VALUEKIND _valueKind; ///< value kind.
	StrongRef<const DataTypeImpl> _underlying; ///< underlying data type (a layout-compatible more fundamental type, such as the unqualified version or an underlying tuple type)
	StrongRef<const DataTypeImpl> _elementType; ///< The element type, used for parametric types which have exactly one type parameter (such as Block<T>, Result<T>, BaseArray<T>).
	const ParametricTypeInterface* _parametricType; ///< Used for instantiations of parametric types.
	union
	{
		const NonvirtualInterfaceImplementation* _implementation; ///< The interface implementation. Only valid for kind NONVIRTUAL_INTERFACE.
		const InterfaceDefinition* const* _interfaces; ///< nullptr-terminated array of virtual interfaces (excluding ObjectInterface), owned by this DataType. Only valid for kind VIRTUAL_INTERFACE.
		const TypeArguments* _typeArgs; ///< Pointer to the type arguments, uses a strong reference
	};
	const void* _conversions[3]; ///< this storage is used for a BaseArray<Tuple<DataType, Conversion>> which contains the registered conversion functions

	// pointers to the DataType function implementations
	void (* const _construct)(const DataTypeImpl* type, void* dest, Int count);
	void (* const _destruct)(const DataTypeImpl* type, const void* dest, Int count);
	void (* const _moveConstruct)(const DataTypeImpl* type, void* dest, void* src, Int count);
	void (* const _moveFrom)(const DataTypeImpl* type, void* dest, void* src, Int count);
	Result<void> (* const _copyFrom)(const DataTypeImpl* type, void* dest, const void* src, Int count);
	Result<Bool> (* const _updateFrom)(const DataTypeImpl* type, void* dest, const void* src);
	void (* const _addReference)(const DataTypeImpl* type, const void* obj);
	void (* const _removeReference)(const DataTypeImpl* type, const void* obj);
	String (* const _toString)(const DataTypeImpl* type, const void* s, const FormatStatement* formatStatement);
	Bool (* const _isEqual)(const DataTypeImpl* type, const void* s1, const void* s2, EQUALITY equality);
	COMPARERESULT (* const _compare)(const DataTypeImpl* type, const void* s1, const void* s2);
	UInt (* const _getHashCode)(const DataTypeImpl* type, const void* s1);
	Result<void> (* const _describeIO)(const DataTypeImpl* type, const DataSerializeInterface& stream);
	Result<void*> (* const _newInstance)(const DataTypeImpl* type);
	Result<void> (* const _initData)(const DataTypeImpl* type, DataMemBlock* mem);
	void (* const _freeData)(const DataTypeImpl* type, DataMemBlock* mem);
	Result<void> (* const _copyData)(const DataTypeImpl* type, DataMemBlock* d, const DataMemBlock* s);
	Result<void> (* const _initCopyData)(const DataTypeImpl* type, DataMemBlock* d, const DataMemBlock* s);
	void (* const _moveData)(const DataTypeImpl* type, DataMemBlock* d, DataMemBlock* s);
	void (* const _initMoveData)(const DataTypeImpl* type, DataMemBlock* d, DataMemBlock* s);
	const void* (* const _getPtr)(const DataTypeImpl* type, const DataMemBlock* s);
	Bool (* const _isEqualData)(const DataTypeImpl* type, const DataMemBlock* s1, const DataMemBlock* s2, EQUALITY equality);

	// The following functions are only needed for Data, make them private and Data a friend of DataType.
private:
	//----------------------------------------------------------------------------------------
	/// Constructs a memory block. If the value fits in a DataMemBlock, you can use the DataMemBlock memory directly with a placement new.
	/// Otherwise you need to allocate your own memory and store its pointer in the DataMemBlock.
	/// @param[out] mem								Pointer to the memory block.
	/// @return												True if the initialization succeeded.
	//----------------------------------------------------------------------------------------
	Result<void> InitData(DataMemBlock* mem) const { return _initData(this, mem); }

	//----------------------------------------------------------------------------------------
	/// Destructs and frees a memory block. If the value fits in a DataMemBlock, you can use the DataMemBlock memory directly with a placement delete.
	/// Otherwise you need to delete your own memory which has been allocated previously by one of the Init functions.
	/// @param[in,out] mem						Pointer to the memory block.
	//----------------------------------------------------------------------------------------
	void FreeData(DataMemBlock* mem) const { return _freeData(this, mem); }

	//----------------------------------------------------------------------------------------
	/// Copies a Data memory block to another (existing and initialized) memory block.
	/// @param[in] s									Source pointer to the memory block.
	/// @param[in,out] d							Destination pointer to the memory block.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	Result<void> CopyData(DataMemBlock* d, const DataMemBlock* s) const { return _copyData(this, d, s); }

	//----------------------------------------------------------------------------------------
	/// Copies a Data memory block into a new memory block.
	/// @param[in] s									Source pointer to the memory block.
	/// @param[in,out] d							Destination pointer to the memory block.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	Result<void> InitCopyData(DataMemBlock* d, const DataMemBlock* s) const { return _initCopyData(this, d, s); }

	//----------------------------------------------------------------------------------------
	/// Moves a Data memory block to another (existing and initialized) memory block.
	/// @param[in] s									Source pointer to the memory block. The value will be moved into the destination, the source will be reset to empty data.
	/// @param[in,out] d							Destination pointer to the memory block.
	//----------------------------------------------------------------------------------------
	void MoveData(DataMemBlock* d, DataMemBlock* s) const { return _moveData(this, d, s); }

	//----------------------------------------------------------------------------------------
	/// Move constructs a Data memory block from another block.
	/// @param[in] s									Source pointer to the memory block. The value will be moved into the destination, the source will be reset to empty data.
	/// @param[in,out] d							Destination pointer to the memory block.
	//----------------------------------------------------------------------------------------
	void InitMoveData(DataMemBlock* d, DataMemBlock* s) const { return _initMoveData(this, d, s); }

	//----------------------------------------------------------------------------------------
	/// Compares two values of this data type for equality.
	/// @param[in] s1									Pointer to the native data of argument 1.
	/// @param[in] s2									Pointer to the native data of argument 2.
	/// @return												Returns if both values are equal.
	//----------------------------------------------------------------------------------------
	Bool IsEqualData(const DataMemBlock* s1, const DataMemBlock* s2, EQUALITY equality) const { return _isEqualData(this, s1, s2, equality); }

	//----------------------------------------------------------------------------------------
	/// Extracts the pointer to the native data from a memory block.
	/// @param[in] s									Pointer to the memory block.
	/// @return												Pointer to the native data.
	//----------------------------------------------------------------------------------------
	const void* GetPtr(const DataMemBlock* s) const { return _getPtr(this, s); }
};

class DataTypeImpl::Primary
{
public:
	template <typename... ARGS> explicit Primary(ARGS&&... args) : type(std::forward<ARGS>(args)...) { }

	StrongReferenceCounter refCount;
	DataTypeImpl type;
};

class DataTypeImpl::Instantiated : public DataTypeImpl
{
public:
	using DataTypeImpl::DataTypeImpl;
};

class DataType
{
public:
	DataType() = default;

	explicit DataType(const DataTypeImpl* ptr) : _ptr(ptr)
	{
	}

	explicit DataType(std::nullptr_t) = delete;

	static const DataType& NullValue()
	{
		return GetPtrSizedZeroRef<DataType>();
	}

	explicit operator Bool() const
	{
		return _ptr != nullptr;
	}

	Bool operator ==(const DataType& other) const
	{
		return _ptr == other._ptr;
	}

	Bool operator !=(const DataType& other) const
	{
		return _ptr != other._ptr;
	}

	UInt GetHashCode() const
	{
		return DefaultCompare::GetHashCode(_ptr);
	}

	const DataTypeImpl* operator ->() const
	{
		DebugAssert(_ptr);
		return _ptr;
	}

	//----------------------------------------------------------------------------------------
	/// Returns the identifier of this data type. Data type identifiers of primary types
	/// look like @c int32, pointer types are identified by a * suffix
	/// as in @c{float64*}, tuple types by a parenthesized list of its member types as in @c{(int32,float64*)}.
	/// @return												Unique identifier of this type.
	//----------------------------------------------------------------------------------------
	const Id& GetId() const { return _ptr ? _ptr->_id : Id::NullValue(); }

	/// @copydoc DefaultDoc::ToString
	String ToString(const FormatStatement* formatStatement) const;

	//----------------------------------------------------------------------------------------
	/// Returns the size of values of this data type.
	/// @return												Size of values.
	//----------------------------------------------------------------------------------------
	Int GetSize() const { return _ptr ? _ptr->_size : 0; }

	//----------------------------------------------------------------------------------------
	/// Returns the alignment of values of this data type. This might by an extended alignment.
	/// @return												Alignment of values.
	//----------------------------------------------------------------------------------------
	Int GetAlignment() const { return _ptr ? _ptr->_alignment : 0; }

	//----------------------------------------------------------------------------------------
	/// Returns the kind of values of this data type. This is a coarse classification
	/// to distinguish between e.g. value types, pointers, references, arrays and tuples.
	/// @return												Kind of values.
	//----------------------------------------------------------------------------------------
	VALUEKIND GetValueKind() const { return _ptr ? _ptr->_valueKind : VALUEKIND::NONE; }

	//----------------------------------------------------------------------------------------
	/// Tests the value kind of this data type for the given flags (by using the bitwise and).
	/// @param[in] test								The flags to test.
	/// @return												True if the value kind of this data type has one of the given flags, false otherwise.
	//----------------------------------------------------------------------------------------
	Bool CheckValueKind(VALUEKIND test) const { return _ptr && (_ptr->_valueKind & test); }

	//----------------------------------------------------------------------------------------
	/// Returns the unqualified type of this data type. Currently the only possible qualification
	/// is a const qualification. So when this data type represents const T, the returned data type
	/// represents T. If the type is already an unqualified type, this functions returns the type
	/// itself.
	/// @return												This type with any qualifications removed (or this type itself if it is already unqualified).
	//----------------------------------------------------------------------------------------
	const DataType& GetUnqualifiedType() const
	{
		const DataType* t = this;
		while (t->_ptr && t->_ptr->_valueKind & VALUEKIND::QUALIFIER_MASK)
		{
			t = &reinterpret_cast<const DataType&>(t->_ptr->_underlying);
		}
		return *t;
	}

	//----------------------------------------------------------------------------------------
	/// Returns the underlying type of this data type. The underlying data type is a layout-compatible
	/// more fundamental type, such as the unqualified version T for const T, or the tuple type
	/// Tuple<T, T, T> for Vec3<T>.
	/// @return												The underlying type of this type, or nullptr.
	//----------------------------------------------------------------------------------------
	const DataType& GetUnderlyingType() const
	{
		return _ptr ? _ptr->GetUnderlyingType() : *this;
	}

	//----------------------------------------------------------------------------------------
	/// Returns the element type of this data type. The element type is used for some parametric
	/// types such as pointers or references, so for example the element type of
	/// @c{T*} or @c{StrongRef<T>} is @c T.
	/// @return												The element type of this type, or nullptr.
	//----------------------------------------------------------------------------------------
	const DataType& GetElementType() const
	{
		return _ptr ? _ptr->GetElementType() : *this;
	}

	//----------------------------------------------------------------------------------------
	/// Returns the decayed type of this data type (in the sense of std::decay). I.e., at first this
	/// removes any l- or r-value-reference-qualification, and then it returns the unqualified
	/// type of the result.
	/// @return												The decayed type of this type, maybe this type itself.
	//----------------------------------------------------------------------------------------
	const DataType& GetDecayedType() const
	{
		const DataType& t = (_ptr && _ptr->_valueKind & VALUEKIND::REFERENCE_MASK) ? _ptr->GetElementType() : *this;
		return t.GetUnqualifiedType();
	}

	//----------------------------------------------------------------------------------------
	/// Returns true if this data type has valid type arguments, so that it is legal to call GetTypeArguments().
	/// @return												True if this type has valid type arguments, false otherwise.
	//----------------------------------------------------------------------------------------
	Bool HasTypeArguments() const
	{
		return _ptr && _ptr->HasTypeArguments();
	}

	//----------------------------------------------------------------------------------------
	/// Returns the type arguments of this data type. Type arguments are set for some instantiations
	/// of parametric types. For example, the 3-dimensional Vector is an instantiation of the parametric type
	/// Vec with the arguments (Float, 3).
	/// @return												The type arguments of this type.
	//----------------------------------------------------------------------------------------
	const TypeArguments& GetTypeArguments() const
	{
		DebugAssert(HasTypeArguments());
		return _ptr->GetTypeArguments();
	}

	//----------------------------------------------------------------------------------------
	/// Returns the parametric type which instantiated this type. For example if this type is
	/// Vector, the function returns the parametric type Vec.
	/// @return												The parametric type which instantiated this type, or nullptr.
	//----------------------------------------------------------------------------------------
	const ParametricTypeInterface* GetParametricType() const
	{
		return _ptr ? _ptr->_parametricType : nullptr;
	}

	//----------------------------------------------------------------------------------------
	/// Returns the DataType identified by @p typeId. This supports primary data types as well as
	/// compound data types which are based on other types.
	/// E.g., the id "(int64,net.maxon.parametrictype.vec<3,float64>,{net.maxon.interface.functionsignature,net.maxon.interface.genericfunction})[]" identifies an array of tuples
	/// with Int64, Vector64 and object members where the object has to implement FunctionSignatureInterface
	/// and GenericFunctionInterface.
	///
	/// This function just forwards to DataTypeLib::GetDataType.
	/// @param[in] typeId							Type identifier.
	/// @return												DataType for the given id.
	//----------------------------------------------------------------------------------------
	static Result<DataType> Get(const Id& typeId);

	//----------------------------------------------------------------------------------------
	/// Returns the underlying tuple type of this type (if it exists). It exists for value types
	/// like @c Vector whose underlying tuple type is composed of the members (@c x, @c y, @c z for @c Vector).
	/// @return												Underlying tuple type of this type, or @c nullptr if this doesn't exist.
	//----------------------------------------------------------------------------------------
	const TupleDataType& GetTupleType() const
	{
		const DataTypeImpl* t = GetUnqualifiedType()._ptr;
		return (t && t->_valueKind & VALUEKIND::STRUCT) ? reinterpret_cast<const TupleDataType&>(t->_underlying) : reinterpret_cast<const TupleDataType&>(NullValue());
	}

	//----------------------------------------------------------------------------------------
	/// A Conversion delegate defines a conversion from a source type to a destination type
	/// (such as from Int to Float). You can register Conversion delegates from a source type
	/// at the DataType object of the destination type.
	/// @see AddConversion
	//----------------------------------------------------------------------------------------
	using Conversion = Delegate<Result<void>(const DataPtr& dest, const ConstDataPtr& src)>;

	//----------------------------------------------------------------------------------------
	/// Registers a Conversion delegate #func from the source type #src at this DataType. The Conversion
	/// delegate has to convert values of type #src to values of this DataType.
	/// @param[in] src								The source type of the conversion function.
	/// @param[in] kind								The kind of the conversion.
	/// @param[in] func								The conversion delegate.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	Result<void> AddConversion(const DataType& src, CONVERSION_FLAGS kind, Conversion&& func) const;

	//----------------------------------------------------------------------------------------
	/// Registers a conversion function @p conversion from type @p SRC to type @p DEST at
	/// the DataType of @p SRC.
	/// @param[in] conversion					The conversion function.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	template <typename DEST, typename SRC> static Result<void> AddConversion(CONVERSION_FLAGS kind, Result<void> (*conversion) (DEST& dest, const SRC& src));

	//----------------------------------------------------------------------------------------
	/// Converts the value #src to the value #dest (the type of which has to match this DataType).
	/// This uses the conversion delegates which have been registered with AddConversion,
	/// or ParametricTypeInterface::Convert if this DataType is an instance of a parametric type.
	/// @param[in] dest								The destination value.
	/// @param[in] src								The source value.
	/// @param[in] ignore							Only those conversions are taken into account whose conversion flags aren't also set in #ignore.
	/// @return												OK on success. If there is no conversion from the source type at all,
	/// 															an UnsupportedArgumentError is returned. For narrowing conversions other errors may occur,
	/// 															such as when the representable range is exceeded.
	//----------------------------------------------------------------------------------------
	Result<void> Convert(Generic& dest, const ConstDataPtr& src, CONVERSION_FLAGS ignore = CONVERSION_FLAGS::NONE) const;

	//----------------------------------------------------------------------------------------
	/// In debug configuration, checks if this type is the same as #T and writes warnings to the console
	/// if not. This functions does nothing in release configuration.
	/// @tparam T											Type to compare.
	//----------------------------------------------------------------------------------------
	template <typename T> void AssertType() const;

	//----------------------------------------------------------------------------------------
	/// Returns true if this type is the same as #T. @c{t.Is<T>()} is a shorthand for @c{t == GetDataType<T>()}.
	/// @tparam T											Type to compare.
	/// @return												True if this type is #T, false otherwise.
	//----------------------------------------------------------------------------------------
	template <typename T> Bool Is() const;

	//----------------------------------------------------------------------------------------
	/// Checks if a value of the @p other type can be cast safely to a value of this type.
	/// This holds if either both types are the same, or this type is Generic, or both types are reference or pointer types
	/// and the type to which this type points is a base type of the type to which the @p other type points
	/// (see IsBaseOfOrSame).
	///
	/// @param[in] other							Another data type.
	/// @return												True if a value of this data type can be safely cast from a value of the  @p other type.
	//----------------------------------------------------------------------------------------
	Bool IsCastableFrom(const DataType& other) const;

	//----------------------------------------------------------------------------------------
	/// Checks if a value of type @p T can be cast safely to a value of this type.
	/// This holds if either both types are the same, have the same underlying type,
	/// or this type is Generic, or both types are reference or pointer types
	/// and the type to which this type points is a base type of the type to which @p T points
	/// (see IsBaseOfOrSame).
	///
	/// @tparam T											Another data type.
	/// @return												True if a value of this data type can be safely cast from a value of type @p T.
	//----------------------------------------------------------------------------------------
	template <typename T> Bool IsCastableFrom() const;

	//----------------------------------------------------------------------------------------
	/// Checks if a value of this type can safely be cast to a value of type @p T.
	/// @see IsBaseOfOrSame.
	///
	/// @tparam T											Another data type.
	/// @return												True if a value of this data type can be safely cast from a value of type @p T.
	//----------------------------------------------------------------------------------------
	template <typename T> Bool IsCastableTo() const;

	//----------------------------------------------------------------------------------------
	/// Match mode for IsBaseOfOrSame.
	//----------------------------------------------------------------------------------------
	enum class MEMBER_MATCH_MODE
	{
		ORDERED_EXACT,			///< Members have to match in name and type in their order.
		ORDERED_TYPE_ONLY,	///< Members have to match only in type.
		UNORDERED_BY_NAME		///< Members are matched by name, so their order is ignored.
	} MAXON_ENUM_LIST_CLASS(MEMBER_MATCH_MODE);

	//----------------------------------------------------------------------------------------
	/// Checks if this type is a base type of the @p other type (or the same).
	/// This takes into account
	/// - the hierarchy of virtual interfaces
	/// - const qualification
	/// - and the element types of Result, ArrayInterface, Block, pointers and references.
	///
	/// For example, const Int is a base type of Int, but not vice versa. const Result<ObjectRef>*
	/// is a base type of Result<IoHandler>*.
	///
	/// @param[in] other							Another data type.
	/// @param[in] mode								For types with members this controls how they are compared (either based on the member order, or based on the member names).
	/// @return												True if this type is a base type of the @p other type.
	//----------------------------------------------------------------------------------------
	Bool IsBaseOfOrSame(const DataType& other, MEMBER_MATCH_MODE mode = MEMBER_MATCH_MODE::ORDERED_EXACT) const
	{
		return (_ptr == other._ptr) || IsBaseOfOrSameImpl(other, mode);
	}

	//----------------------------------------------------------------------------------------
	/// Checks if this type is similar to the other type. Two types are similar if they are the same
	/// except for differences in const qualifiers. For example, Result<Block<const Int>>* is
	/// similar to const Result<Block<Int>>*.
	///
	/// @param[in] other							Another data type.
	/// @return												True if both types are similar.
	//----------------------------------------------------------------------------------------
	Bool IsSimilar(const DataType& other) const;

	/// @copydoc DefaultDoc::Reset
	void Reset();

	const DataTypeImpl* PrivateGetPointer() const
	{
		return _ptr;
	}

	class Primary;

private:
	void AddReference() const
	{
	}

	void RemoveReference() const
	{
	}

	friend class Data;
	friend class DataTypeImpl;
	friend class DataTypePtr;
	friend class StrongRefHandler;

#ifdef MAXON_TARGET_DEBUG
	//----------------------------------------------------------------------------------------
	/// In debug configuration, checks if this type is the same as #other and writes warnings to the console
	/// if not. This function does nothing in release configuration.
	/// @param[in] other							Type to compare.
	//----------------------------------------------------------------------------------------
	void AssertTypeImpl(const DataType& other) const;
#endif

	Bool IsBaseOfOrSameImpl(const DataType& other, MEMBER_MATCH_MODE mode) const;


	Bool IsBaseOfOrSameImpl(const DataType* other, MEMBER_MATCH_MODE mode) const;

	StrongRef<const DataTypeImpl> _ptr; ///< the data type
};

inline DataTypePtr::DataTypePtr(const DataType& type) : _ptr(type._ptr)
{
}

class DataType::Primary : public DataType
{
public:
	using DataType::DataType;
};

//----------------------------------------------------------------------------------------
/// GET_DATATYPE_POLICY controls the behavior of GetDataType for special cases.
//----------------------------------------------------------------------------------------
enum class GET_DATATYPE_POLICY
{
	NONE = 0,

	/// Set this flag if the datatype of Generic shall be returned for a type which hasn't been registered (otherwise a compile-time error happens unless ERROR_FOR_UNKNOWN is set).
	GENERIC_FOR_UNKNOWN = 1,

	/// Set this flag if a runtime error shall be returned by CheckedGetDataType for a type which hasn't been registered (otherwise a compile-time error happens unless GENERIC_FOR_UNKNOWN is set).
	ERROR_FOR_UNKNOWN = 2,

	/// Set this flag if the template argument T of GetDataType shall not be decayed (by default the type is decayed so that T&, T&&, const T, const T&, const T&& all return the same as GetDataType<T>()).
	NO_DECAY = 4,

	ALLOW_BASEARRAY = 8,

	RESULT_FOR_UNKNOWN_MASK = GENERIC_FOR_UNKNOWN | ERROR_FOR_UNKNOWN
} MAXON_ENUM_FLAGS(GET_DATATYPE_POLICY);


//----------------------------------------------------------------------------------------
/// Returns the DataType for the given C++ type.
/// @code
/// const DataType& type = GetDataType<T>();
/// const DataType& type = GetDataType<Tuple<Int, String>>();
/// @endcode
/// @tparam T											Type of which the DataType representation shall be obtained.
/// @tparam POLICY								Optional parameter to modify the data type resolution.
/// @return												DataType for T.
//----------------------------------------------------------------------------------------
template <typename T, GET_DATATYPE_POLICY POLICY = GET_DATATYPE_POLICY::NONE> inline const DataType& GetDataType();



class TupleValue;

//----------------------------------------------------------------------------------------
/// General Data class. An object of this class can store every type of data as long as that
/// type has been registered (see DataType).
/// @see @$ref datatype_data
//----------------------------------------------------------------------------------------
class Data
{
	MAXON_DISALLOW_COPY_AND_ASSIGN(Data);
public:
	/// constructor initializes the data with an nullptr type.
	Data() = default;

	//----------------------------------------------------------------------------------------
	/// Initializes this data to the given type. If this data already has the given type,
	/// nothing happens, i.e., the value is not reset. Otherwise, the current value is freed,
	/// and the data is initialized with a new default value of the given type.
	/// @param[in] type								Type to which this data shall be set.
	/// @return												False if the initialization failed.
	//----------------------------------------------------------------------------------------
	Result<void> Init(const DataType& type)
	{
		if (type == _typeInfo)
			return OK;
		if (_typeInfo)
		{
			_typeInfo->FreeData(&_memBlock);
			_typeInfo.Reset();
		}
		if (type.GetValueKind() & VALUEKIND::DATA)
		{
			return OK;
		}
		Result<void> r = type->InitData(&_memBlock);
		if (MAXON_UNLIKELY(r == FAILED))
		{
			return r;
		}
		_typeInfo = type;
		return OK;
	}

	//----------------------------------------------------------------------------------------
	/// Creates a Data and initializes it with the given type.
	/// @tparam T											Type of data which shall be created.
	/// @return												Data initialized to the given type on success.
	//----------------------------------------------------------------------------------------
	template <typename T> static Result<Data> Create();
	
	~Data()
	{
		if (_typeInfo)
		{
			_typeInfo->FreeData(&_memBlock);
		}
	}

	//----------------------------------------------------------------------------------------
	/// Checks if a Data is empty.
	/// @return												True if it doesn't contain any data.
	//----------------------------------------------------------------------------------------
	Bool IsEmpty() const
	{
		return !_typeInfo;
	}

	//----------------------------------------------------------------------------------------
	/// Checks if a Data contains anything.
	/// @return												True if it contains data.
	//----------------------------------------------------------------------------------------
	Bool IsPopulated() const
	{
		return Bool(_typeInfo);
	}

	//----------------------------------------------------------------------------------------
	/// Returns the DataType of the Data. you can compare this value to GetDataType<Int32>() or GetDataType<String>().
	/// @return												DataType pointer of this.
	//----------------------------------------------------------------------------------------
	const DataType&	GetType() const { return _typeInfo; }

	//----------------------------------------------------------------------------------------
	/// Frees the wrapped data and resetd the Data object to its initial state.
	//----------------------------------------------------------------------------------------
	void Reset()
	{
		if (_typeInfo)
		{
			// free data;
			_typeInfo->FreeData(&_memBlock);
			_typeInfo.Reset();
		}
	}

	//----------------------------------------------------------------------------------------
	/// Template class to construct a Data object from a value. The value has to fit in DataMemBlock,
	/// i.e., this constructor can only be used when SIZEOF(T) <= SIZEOF(DataMemBlock). Otherwise,
	/// you have to use Set which might return an error.
	/// @tparam T											Type of data. This constructor only works if SIZEOF(T) <= SIZEOF(DataMemBlock).
	/// @param[in] data								Data to copy into the Data.
	//----------------------------------------------------------------------------------------
	template <typename T> explicit Data(T&& data, typename std::enable_if</*(SIZEOF(typename std::decay<T>::type) <= SIZEOF(DataMemBlock)) &&*/ !std::is_same<typename std::decay<T>::type, Data>::value, DummyParamType*>::type = (DummyParamType*)nullptr)
	{
		InitSet(std::forward<T>(data));
	}

	//----------------------------------------------------------------------------------------
	/// Template class to move Data from every specialized data type. e.g. Int32, Url etc.
	/// @param[in,out] src						Data to move to this.
	//----------------------------------------------------------------------------------------
	Data(Data&& src)
	{
		if (src._typeInfo)
		{
			src._typeInfo->InitMoveData(&_memBlock, &src._memBlock);
			_typeInfo = std::move(src._typeInfo);
		}
	}

	//----------------------------------------------------------------------------------------
	/// Assignment move operator to move Data, (e.g. Swap uses this)
	/// @param[in] src								Data to move to this.
	//----------------------------------------------------------------------------------------
	Data& operator =(Data&& src)
	{
		if (_typeInfo != src._typeInfo)
		{
			Reset();
			if (src._typeInfo)
			{
				src._typeInfo->InitMoveData(&_memBlock, &src._memBlock);
				_typeInfo = std::move(src._typeInfo);
			}
		}
		else if (_typeInfo)
		{
			_typeInfo->MoveData(&_memBlock, &src._memBlock);
			src._typeInfo.Reset();
		}
		return *this;
	}

	//----------------------------------------------------------------------------------------
	/// Returns a copy of the data.
	//----------------------------------------------------------------------------------------
	Result<Data> GetCopy() const;

	/// @copydoc DefaultDoc::CopyFrom
	Result<void> CopyFrom(const Data& src)
	{
		if (_typeInfo != src._typeInfo)
		{
			Reset();
			if (src._typeInfo)
			{
				Result<void> r = src._typeInfo->InitCopyData(&_memBlock, &src._memBlock);
				if (MAXON_UNLIKELY(r == FAILED))
				{
					return r;
				}
				_typeInfo = src._typeInfo;
			}
		}
		else if (_typeInfo)
		{
			Result<void> r = _typeInfo->CopyData(&_memBlock, &src._memBlock);
			if (MAXON_UNLIKELY(r == FAILED))
			{
				Reset();
				return r;
			}
		}
		return OK;
	}

	//----------------------------------------------------------------------------------------
	/// Copies data described by a ConstDataPtr.
	/// @param[in] src								ConstDataPtr to copy data from.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	Result<void> CopyFrom(const ConstDataPtr& src);

	//----------------------------------------------------------------------------------------
	/// Moves data described by a MoveDataPtr.
	/// @param[in] src								MoveDataPtr to move data from.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	Result<void> MoveFrom(MoveDataPtr&& src);

	//----------------------------------------------------------------------------------------
	/// Copies or moves data described by a ForwardingDataPtr.
	/// @param[in] src								ForwardingDataPtr to copy or move data from.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	Result<void> CopyFrom(ForwardingDataPtr&& src);

	//----------------------------------------------------------------------------------------
	/// Set or move a value into a Data.
	/// @param[in] data								New value for this Data object.
	//----------------------------------------------------------------------------------------
	template <typename T> Result<void> Set(T&& data)
	{
		return SetImpl(std::forward<T>(data), OVERLOAD_MAX_RANK);
	}


	//----------------------------------------------------------------------------------------
	/// Returns the value of type T of this Data.
	/// @tparam T											The expected type of the value.
	/// @return												The value stored in this Data, or an error if this Data doesn't store a value of type T.
	//----------------------------------------------------------------------------------------
	template <typename T> Result<typename std::conditional<GetCollectionKind<T>::value == COLLECTION_KIND::ARRAY, T, typename ByValueParam<T>::type>::type> Get() const
	{
		return GetImpl<T>(OVERLOAD_MAX_RANK);
	}

	template <typename T> Result<typename std::conditional<std::is_void<T>::value || (GetCollectionKind<T>::value == COLLECTION_KIND::ARRAY), T, T&>::type> Get()
	{
		return GetImpl<T>(OVERLOAD_MAX_RANK);
	}

	//----------------------------------------------------------------------------------------
	/// Returns the value of type T of this Data.
	/// @tparam T											The expected type of the value.
	/// @return												The value stored in this Data, or a null value if this Data doesn't store a value of type T.
	//----------------------------------------------------------------------------------------
	template <typename T> typename ByValueParam<T>::type GetOrNull() const
	{
		auto res = Get<T>();
		if (res.GetError())
			return maxon::NullValue<typename ByValueParam<T>::type>();
		return res.GetValue();
	}

	//----------------------------------------------------------------------------------------
	/// Returns the value of type T of this Data.
	/// @param[in] defaultValue				If this Data doesn't store a value of type T, the default value will be returned.
	/// @tparam T											The expected type of the value.
	/// @return												The value stored in this Data, or defaultValue if this Data doesn't store a value of type T.
	//----------------------------------------------------------------------------------------
	template <typename T> T Get(const T& defaultValue) const
	{
		const T* ptr = GetPtr<T>();
		return ptr ? *ptr : defaultValue;
	}


	//----------------------------------------------------------------------------------------
	/// Returns the value of this Data, converted to T.
	/// @tparam T											The type to convert to.
	/// @return												The value stored in this Data, converted to T, or an error if this Data doesn't store a value or the value cannot be converted to T.
	/// @see DataType::Convert
	//----------------------------------------------------------------------------------------
	template <typename T> Result<T> Convert() const
	{
		if (IsObjectReferenceClass<T>::value)
		{
			return Get<T>();
		}
		T result;
		Result<void> res = GetDataType<T>().Convert(reinterpret_cast<Generic&>(result), typename SFINAEHelper<ConstDataPtr, T>::type(*this));
		return Result<T>(std::move(result), res);
	}

	//----------------------------------------------------------------------------------------
	/// Returns the value of this Data, converted to T.
	/// @tparam T											The type to convert to.
	/// @return												The value stored in this Data, converted to T, or T() if this Data doesn't store a value or the value cannot be converted to T.
	/// @see DataType::Convert
	//----------------------------------------------------------------------------------------
	template <typename T> T ConvertOrNull() const
	{
		if (IsObjectReferenceClass<T>::value)
		{
			return GetOrNull<T>();
		}
		T result{};
		GetDataType<T>().Convert(reinterpret_cast<Generic&>(result), *this) iferr_ignore("Ignore failure to convert");
		return result;
	}

	//----------------------------------------------------------------------------------------
	/// Returns the value of this Data, converted to T.
	/// @param[in] defaultValue				If this Data doesn't store a value or the value cannot converted to T, the default value will be returned.
	/// @tparam T											The type to convert to.
	/// @return												The value stored in this Data, converted to T, or defaultValue if this Data doesn't store a value or the value cannot be converted to T.
	/// @see DataType::Convert
	//----------------------------------------------------------------------------------------
	template <typename T> T Convert(const T& defaultValue) const
	{
		if (IsObjectReferenceClass<T>::value)
		{
			return Get<T>(defaultValue);
		}
		T result = defaultValue;
		GetDataType<T>().Convert(reinterpret_cast<Generic&>(result), typename SFINAEHelper<ConstDataPtr, T>::type(*this))  iferr_ignore("Ignore failure to convert");
		return result;
	}

	//----------------------------------------------------------------------------------------
	/// Returns the value of this Data, converted to destType.
	/// @param[in] destType						The type to convert to.
	/// @return												The value stored in this Data, converted to destType, or an error if this Data doesn't store a value or the value cannot be converted to dataType.
	/// @see DataType::Convert
	//----------------------------------------------------------------------------------------
	Result<Data> ConvertData(const DataType& destType) const;

	//----------------------------------------------------------------------------------------
	/// Returns the pointer of the native data if its type matches the given type T, otherwise nullptr.
	/// @tparam T											The desired type.
	/// @return												Pointer to the data in native format.
	//----------------------------------------------------------------------------------------
	template <typename T> T* GetPtr();

	/// @copydoc GetPtr()
	template <typename T> const T* GetPtr() const
	{
		return const_cast<Data*>(this)->GetPtr<T>();
	}

	//----------------------------------------------------------------------------------------
	/// Returns the pointer of the native data if its type matches the given #type, otherwise nullptr.
	/// @param[in] type								The desired type.
	/// @return												Pointer to the data in native format.
	//----------------------------------------------------------------------------------------
	Generic* GetPtr(const DataType& type)
	{
		if (!type)
			return nullptr;
		if (type->GetValueKind() & VALUEKIND::DATA)
			return (Generic*) this;
		if (!_typeInfo)
			return nullptr;
		if (type == _typeInfo)
			return (Generic*) type->GetPtr(&_memBlock);
		if (type->GetValueKind() & _typeInfo->GetValueKind() & VALUEKIND::OBJECT_REF)
			return (Generic*) CheckInstanceOf(reinterpret_cast<const ObjectRef*>(&_memBlock), type);
		if (type.IsCastableFrom(_typeInfo))
			return (Generic*) type->GetPtr(&_memBlock);
		return nullptr;
	}

	/// @copydoc GetPtr(DataType)
	const Generic* GetPtr(const DataType& type) const
	{
		return const_cast<Data*>(this)->GetPtr(type);
	}

	//----------------------------------------------------------------------------------------
	/// Returns the pointer to the native data.
	/// @return												Pointer to the data in native format.
	//----------------------------------------------------------------------------------------
	const Generic* PrivateGetPtr() const
	{
		return MAXON_LIKELY(_typeInfo) ? (const Generic*) _typeInfo->GetPtr(&_memBlock) : nullptr;
	}

	//----------------------------------------------------------------------------------------
	/// Returns the pointer to the native data. It is not checked if its type matches the given #type,
	/// the only purpose of the parameter is to enable a special behavior when #type is the type Data:
	/// Then a pointer to this Data object itself is returned.
	/// @param[in] type								The desired type.
	/// @return												Pointer to the data in native format.
	//----------------------------------------------------------------------------------------
	const Generic* PrivateGetPtr(const DataType& type) const
	{
		if (type && (type->GetValueKind() & VALUEKIND::DATA))
			return (const Generic*) this;
		return MAXON_LIKELY(_typeInfo) ? (const Generic*) _typeInfo->GetPtr(&_memBlock) : nullptr;
	}

	//----------------------------------------------------------------------------------------
	/// Returns the value of this Data object as a TupleValue. If this object doesn't hold a
	/// tuple value, nullptr is returned.
	/// @return												Pointer to the TupleValue stored in this object, or nullptr if no tuple value is stored.
	//----------------------------------------------------------------------------------------
	TupleValue* GetTuple()
	{
		return (_typeInfo && (_typeInfo->GetValueKind() & VALUEKIND::TUPLE_MASK)) ? (TupleValue*) _typeInfo->GetPtr(&_memBlock) : nullptr;
	}

	//----------------------------------------------------------------------------------------
	/// Returns the value of this Data object as a TupleValue. If this object doesn't hold a
	/// tuple value, nullptr is returned.
	/// @return												Pointer to the TupleValue stored in this object, or nullptr if no tuple value is stored.
	//----------------------------------------------------------------------------------------
	const TupleValue* GetTuple() const
	{
		return const_cast<Data*>(this)->GetTuple();
	}

	//----------------------------------------------------------------------------------------
	/// Returns a readable string of the content.
	/// @param[in] formatStatement		Nullptr or additional formatting instruction. See also @ref format_mixed.
	/// @return												The converted result.
	//----------------------------------------------------------------------------------------
	String ToString(const FormatStatement* formatStatement) const;

	//----------------------------------------------------------------------------------------
	/// Returns a readable string of the content.
	/// @return												String that represents the content of Data.
	//----------------------------------------------------------------------------------------
	COMPARERESULT Compare(const Data& c) const
	{
		if (_typeInfo && c._typeInfo)
		{
			if ((_typeInfo == c._typeInfo) || (_typeInfo->GetValueKind() & c._typeInfo->GetValueKind() & VALUEKIND::OBJECT_REF) || _typeInfo.IsSimilar(c._typeInfo))
			{
				const void* ptr1 = _typeInfo->GetPtr(&_memBlock);
				const void* ptr2 = _typeInfo->GetPtr(&c._memBlock);
				return _typeInfo->Compare(ptr1, ptr2);
			}
			// support mixed use of data types
			if (_typeInfo->GetValueKind() & VALUEKIND::OBJECT_REF)
				return COMPARERESULT::GREATER; // object types are sorted above other types
			if (c._typeInfo->GetValueKind() & VALUEKIND::OBJECT_REF)
				return COMPARERESULT::LESS; // ..
			// both types are non-object types, sort by type id
			return _typeInfo->GetId().Compare(c._typeInfo->GetId());
		}
		else if (c._typeInfo)
		{
			return COMPARERESULT::LESS;
		}
		else if (_typeInfo)
		{
			return COMPARERESULT::GREATER;
		}
		return COMPARERESULT::EQUAL;
	}

	//----------------------------------------------------------------------------------------
	/// Returns the hash code of the wrapped object. If the object's type doesn't provide a hash code
	/// function, this function returns 0.
	/// @return												Hash code of this Data.
	//----------------------------------------------------------------------------------------
	UInt GetHashCode() const
	{
		if (!_typeInfo)
			return 0;
		return _typeInfo->GetHashCode(_typeInfo->GetPtr(&_memBlock));
	}

	//----------------------------------------------------------------------------------------
	/// Returns true if the wrapped object of this Data equals that of the #other Data.
	/// @param[in] other							Another Data object to compare.
	/// @param[in] equality						The equality mode, by default EQUALITY::DEEP.
	/// @return												True if both Data objects are equal, false otherwise.
	//----------------------------------------------------------------------------------------
	Bool IsEqual(const Data& other, EQUALITY equality = EQUALITY::DEEP) const
	{
		if (!_typeInfo)
		{
			return !other._typeInfo;
		}
		else if ((_typeInfo == other._typeInfo)
						 || (other._typeInfo && (_typeInfo->GetValueKind() & other._typeInfo->GetValueKind() & VALUEKIND::OBJECT_REF))
						 || _typeInfo.IsSimilar(other._typeInfo))
		{
			return _typeInfo->IsEqualData(&_memBlock, &other._memBlock, equality);
		}
		else
		{
			return false;
		}
	}

	/// @copydoc DefaultDoc::operator ==
	Bool operator ==(const Data& other) const { return IsEqual(other, EQUALITY::SHALLOW); }
	/// @copydoc DefaultDoc::operator !=
	Bool operator !=(const Data& other) const { return !IsEqual(other, EQUALITY::SHALLOW); }

	// to allow types with partial order, we cannot use MAXON_OPERATOR_COMPARISON here

	/// @copydoc DefaultDoc::operator <
	Bool operator <(const Data& other) const { return Compare(other) == COMPARERESULT::LESS; }
	/// @copydoc DefaultDoc::operator <=
	Bool operator <=(const Data& other) const { COMPARERESULT r = Compare(other); return (r == COMPARERESULT::LESS) || (r == COMPARERESULT::EQUAL); }
	/// @copydoc DefaultDoc::operator >
	Bool operator >(const Data& other) const { return Compare(other) == COMPARERESULT::GREATER; }
	/// @copydoc DefaultDoc::operator >=
	Bool operator >=(const Data& other) const { COMPARERESULT r = Compare(other); return (r == COMPARERESULT::GREATER) || (r == COMPARERESULT::EQUAL); }

	ConstDataPtr ToConstDataPtr(const DataType& expectedType) const;

private:
	static const ObjectInterface* CheckInstanceOf(const ObjectInterface* obj, const DataType& type);

	static const ObjectRef* CheckInstanceOf(const ObjectRef* obj, const DataType& type);

	template <typename T> Result<void> SetImpl(T&& data, OverloadRank0);

	template <typename T> typename std::enable_if<GetCollectionKind<T>::value == COLLECTION_KIND::ARRAY, Result<void>>::type SetImpl(T&& data, OverloadRank1);

	template <typename T> Result<typename ByValueParam<T>::type> GetImpl(OverloadRank0) const
	{
		const T* ptr = GetPtr<T>();
		if (!ptr)
			return CreateError(MAXON_SOURCE_LOCATION, ERROR_TYPE::ILLEGAL_STATE);
		return *ptr;
	}

	template <typename T> typename std::enable_if<GetCollectionKind<T>::value == COLLECTION_KIND::ARRAY, Result<T>>::type GetImpl(OverloadRank1) const;

	template <typename T> Result<typename std::conditional<std::is_void<T>::value, void, T&>::type> GetImpl(OverloadRank0)
	{
		T* ptr = GetPtr<T>();
		if (!ptr)
			return CreateError(MAXON_SOURCE_LOCATION, ERROR_TYPE::ILLEGAL_STATE);
		return *ptr;
	}

	template <typename T> typename std::enable_if<GetCollectionKind<T>::value == COLLECTION_KIND::ARRAY, Result<T>>::type GetImpl(OverloadRank1);

	template <typename T> typename SFINAEHelper<Result<T>, typename T::IsBlock>::type GetImpl(OverloadRank2)
	{
		T* ptr = GetPtr<T>();
		if (!ptr)
			return CreateError(MAXON_SOURCE_LOCATION, ERROR_TYPE::ILLEGAL_STATE);
		return *ptr;
	}
	template <typename T> typename SFINAEHelper<Result<T>, typename T::IsBlock>::type GetImpl(OverloadRank2) const
	{
		const T* ptr = GetPtr<T>();
		if (!ptr)
			return CreateError(MAXON_SOURCE_LOCATION, ERROR_TYPE::ILLEGAL_STATE);
		return *ptr;
	}

	//----------------------------------------------------------------------------------------
	/// Private: Copy or move specific data into a Data from the constructur.
	/// @param[in] data								Data to copy or move to this.
	//----------------------------------------------------------------------------------------
	template <typename T> void InitSet(T&& data);

	//----------------------------------------------------------------------------------------
	/// pointer to the DataType structure
	//----------------------------------------------------------------------------------------
	DataType _typeInfo;

	//----------------------------------------------------------------------------------------
	/// placeholder for embedded data. this size must stay for compatibility reasons.
	//----------------------------------------------------------------------------------------
	DataMemBlock _memBlock;

	// TODO: (Anybody) what happens if a value with extended alignment requirements is stored in _memBlock? Could happen e.g. if SIZEOF(DataMemBlock) >= 16 and we store an SSE value in _memBlock

	static_assert(SIZEOF(DataMemBlock) >= SIZEOF(void*), "DataMemBlock too small for a pointer!");
	static_assert(alignof(DataMemBlock) >= alignof(void*), "DataMemBlock alignment smaller than that of a pointer!");

	friend class ConstDataPtr;
};

template <> struct IsZeroInitialized<Data> : public std::true_type
{
};


// specialization of void case
template <> inline Result<void> Data::Get<void>() const
{
	return OK;
}

template <> inline Result<void> Data::Set<const Data&>(const Data& value)
{
	return CopyFrom(value);
}

template <> inline Result<void> Data::Set<Data&>(Data& value)
{
	return CopyFrom(value);
}

template <> inline Result<void> Data::Set<Data>(Data&& value)
{
	*this = std::move(value);
	return OK;
}


//----------------------------------------------------------------------------------------
/// ConstDataPtr contains type info and a pointer to an arbitrary generic const object.
/// The type of the object is only known at run-time.
//----------------------------------------------------------------------------------------
class ConstDataPtr
{
public:
	ConstDataPtr() = default;

	explicit ConstDataPtr(const Data& value)
	{
		_typeInfo = value.GetType();
		_dataPtr = value.PrivateGetPtr();
	}

	ConstDataPtr(const DataType& typeInfo, const Generic* dataPtr)
	{
		_typeInfo = typeInfo;
		_dataPtr = dataPtr;
	}

	template <typename T> explicit ConstDataPtr(const T& value)
	{
		Set<T>(value);
	}

	Bool IsEmpty() const
	{
		return !_typeInfo;
	}

	Bool IsPopulated() const
	{
		return Bool(_typeInfo);
	}

	const DataType&	GetType() const
	{
		return _typeInfo;
	}

	const Generic* PrivateGetPtr() const
	{
		return _dataPtr;
	}

	void Set(const DataType& typeInfo, const Generic* dataPtr)
	{
		_typeInfo = typeInfo;
		_dataPtr = dataPtr;
	}

	template <typename T> void Set(const T& value);

	void Set(const Data& value)
	{
		_typeInfo = value.GetType();
		_dataPtr = value.PrivateGetPtr();
	}

	void Set(Data& value)
	{
		_typeInfo = value.GetType();
		_dataPtr = value.PrivateGetPtr();
	}

	void Set(Data&& value)
	{
		_typeInfo = value.GetType();
		_dataPtr = value.PrivateGetPtr();
	}

	const Generic* GetPtr(const DataType& type) const
	{
		if (!type || !_typeInfo)
			return nullptr;
		if (type == _typeInfo)
			return _dataPtr;
		if (type->GetValueKind() & _typeInfo->GetValueKind() & VALUEKIND::OBJECT_REF)
			return (const Generic*) Data::CheckInstanceOf(reinterpret_cast<const ObjectRef*>(_dataPtr), type);
		if (type->GetValueKind() & _typeInfo->GetValueKind() & VALUEKIND::VIRTUAL_INTERFACE)
			return (const Generic*) Data::CheckInstanceOf(reinterpret_cast<const ObjectInterface*>(_dataPtr), type);
		if (type.IsCastableFrom(_typeInfo))
			return _dataPtr;
		return nullptr;
	}

	template <typename T> const T* GetPtr() const
	{
		return (const T*) GetPtr(GetDataType<T, GET_DATATYPE_POLICY::GENERIC_FOR_UNKNOWN>());
	}

	//----------------------------------------------------------------------------------------
	/// Returns the value of type T of this Data.
	/// if <void> or <Data> is given the result value is not a reference.
	/// @tparam T											The expected type of the value.
	/// @return												The value stored in this Data, or an error if this Data doesn't store a value of type T.
	//----------------------------------------------------------------------------------------
	template <typename T> Result<typename std::conditional<std::is_same<T, Data>::value || (GetCollectionKind<T>::value == COLLECTION_KIND::ARRAY), T, typename ByValueParam<T>::type>::type> Get() const
	{
		return GetImpl<T>(OVERLOAD_MAX_RANK);
	}

	template <typename T> typename ByValueParam<T>::type GetOrNull() const
	{
		const T* ptr = GetPtr<T>();
		return ptr ? *ptr : maxon::NullValue<typename ByValueParam<T>::type>();
	}

	template <typename T> typename ByValueParam<T>::type Get(const T& defaultValue) const
	{
		const T* ptr = GetPtr<T>();
		return ptr ? *ptr : defaultValue;
	}

	//----------------------------------------------------------------------------------------
	/// Compares this object to a ConstDataPtr.
	/// @param[in] c									Other object.
	/// @return												See COMPARERESULT.
	//----------------------------------------------------------------------------------------
	COMPARERESULT Compare(const ConstDataPtr& c) const
	{
		if (_typeInfo && c._typeInfo)
		{
			if ((_typeInfo == c._typeInfo) || (_typeInfo->GetValueKind() & c._typeInfo->GetValueKind() & VALUEKIND::OBJECT_REF) || _typeInfo.IsSimilar(c._typeInfo))
			{
				return _typeInfo->Compare(_dataPtr, c._dataPtr);
			}
			// support mixed use of data types
			if (_typeInfo->GetValueKind() & VALUEKIND::OBJECT_REF)
				return COMPARERESULT::GREATER; // object types are sorted above other types
			if (c._typeInfo->GetValueKind() & VALUEKIND::OBJECT_REF)
				return COMPARERESULT::LESS; // ..
			// both types are non-object types, sort by type id
			return _typeInfo->GetId().Compare(c._typeInfo->GetId());
		}
		else if (c._typeInfo)
		{
			return COMPARERESULT::LESS;
		}
		else if (_typeInfo)
		{
			return COMPARERESULT::GREATER;
		}
		return COMPARERESULT::EQUAL;
	}

	//----------------------------------------------------------------------------------------
	/// Compares this object to a Data.
	/// @param[in] c									Other object.
	/// @return												See COMPARERESULT.
	//----------------------------------------------------------------------------------------
	COMPARERESULT Compare(const Data& c) const
	{
		if (_typeInfo && c.GetType())
		{
			if ((_typeInfo == c.GetType()) || (_typeInfo->GetValueKind() & c.GetType()->GetValueKind() & VALUEKIND::OBJECT_REF) || _typeInfo.IsSimilar(c.GetType()))
			{
				return _typeInfo->Compare(_dataPtr, c.PrivateGetPtr());
			}
			// support mixed use of data types
			if (_typeInfo->GetValueKind() & VALUEKIND::OBJECT_REF)
				return COMPARERESULT::GREATER; // object types are sorted above other types
			if (c.GetType()->GetValueKind() & VALUEKIND::OBJECT_REF)
				return COMPARERESULT::LESS; // ..
			// both types are non-object types, sort by type id
			return _typeInfo->GetId().Compare(c.GetType()->GetId());
		}
		else if (c.GetType())
		{
			return COMPARERESULT::LESS;
		}
		else if (_typeInfo)
		{
			return COMPARERESULT::GREATER;
		}
		return COMPARERESULT::EQUAL;
	}

	//----------------------------------------------------------------------------------------
	/// Returns the hash code of the data elements. If no hash code could be calculated the value is 0.
	//----------------------------------------------------------------------------------------
	UInt GetHashCode() const
	{
		if (!this->_typeInfo)
			return 0;
		return this->_typeInfo->GetHashCode(this->_dataPtr);
	}

	Bool operator ==(const ConstDataPtr& c) const
	{
		if (!_typeInfo)
		{
			return !c._typeInfo;
		}
		else if ((_typeInfo == c._typeInfo)
						 || (c._typeInfo && (_typeInfo->GetValueKind() & c._typeInfo->GetValueKind() & VALUEKIND::OBJECT_REF))
						 || _typeInfo.IsSimilar(c._typeInfo))
		{
			return _typeInfo->IsEqual(_dataPtr, c._dataPtr, EQUALITY::SHALLOW);
		}
		else
		{
			return false;
		}
	}

	Bool operator !=(const ConstDataPtr& c) const { return !this->operator ==(c); }

	// to allow types with partial order, we cannot use MAXON_OPERATOR_COMPARISON here
	Bool operator <(const ConstDataPtr& c) const { return Compare(c) == COMPARERESULT::LESS; }
	Bool operator <=(const ConstDataPtr& c) const { COMPARERESULT r = Compare(c); return (r == COMPARERESULT::LESS) || (r == COMPARERESULT::EQUAL); }
	Bool operator >(const ConstDataPtr& c) const { return Compare(c) == COMPARERESULT::GREATER; }
	Bool operator >=(const ConstDataPtr& c) const { COMPARERESULT r = Compare(c); return (r == COMPARERESULT::GREATER) || (r == COMPARERESULT::EQUAL); }

	static const ConstDataPtr& NullValue() { return GetZeroRef<ConstDataPtr>(); }

	String ToString(const FormatStatement* formatStatement) const;

	template <typename T, typename CHECK = void> class Wrapper;

protected:
	template <typename T> Result<typename ByValueParam<T>::type> GetImpl(OverloadRank0) const
	{
		const T* ptr = GetPtr<T>();
		if (!ptr)
			return CreateError(MAXON_SOURCE_LOCATION, ERROR_TYPE::ILLEGAL_STATE);

		// The type can be an Error as well. Therefore use this special constructor.
		return Result<typename ByValueParam<T>::type>(*ptr, typename SFINAEHelper<Error, T>::type());
	}

	template <typename T> typename std::enable_if<GetCollectionKind<T>::value == COLLECTION_KIND::ARRAY, Result<T>>::type GetImpl(OverloadRank1) const;

	DataType _typeInfo;
	const Generic* _dataPtr = nullptr;

	friend struct ViewIteratorMember;
	friend class ContainerViewTypeImpl;
};

template <typename T, typename CHECK> class ConstDataPtr::Wrapper : public ConstDataPtr
{
public:
	ResultOk<void> Init(const T& value)
	{
		this->Set(value);
		return OK;
	}
};

//----------------------------------------------------------------------------------------
/// DataPtr contains type info and a pointer to an arbitrary generic non-const object.
/// The type of the object is only known at run-time.
//----------------------------------------------------------------------------------------
class DataPtr : public ConstDataPtr
{
public:
	DataPtr() = default;

	explicit DataPtr(Data& value) : ConstDataPtr(value)
	{
	}

	DataPtr(const DataType& typeInfo, Generic* dataPtr) : ConstDataPtr(typeInfo, dataPtr)
	{
	}

	template <typename T> explicit DataPtr(T& value) : ConstDataPtr(value)
	{
		static_assert(!std::is_const<T>::value, "Can't initialize a DataPtr with a const value.");
	}

	using ConstDataPtr::GetPtr;

	Generic* PrivateGetPtr() const
	{
		return const_cast<Generic*>(_dataPtr);
	}

	Generic* GetPtr(const DataType& type)
	{
		return const_cast<Generic*>(ConstDataPtr::GetPtr(type));
	}

	template <typename T> T* GetPtr()
	{
		return const_cast<Generic*>(ConstDataPtr::GetPtr(GetDataType<T, GET_DATATYPE_POLICY::GENERIC_FOR_UNKNOWN>()));
	}

	static const DataPtr& NullValue() { return GetZeroRef<DataPtr>(); }
	
	//----------------------------------------------------------------------------------------
	/// Moves from another Data.
	/// @param[in] src								Data to move from.
	/// @return												OK on success (will fail if this DataPtr has a non-matching type).
	//----------------------------------------------------------------------------------------
	Result<void> MoveFrom(Data&& src)
	{
		if (!_typeInfo)
			return CreateError(MAXON_SOURCE_LOCATION, ERROR_TYPE::ILLEGAL_ARGUMENT);

		if (_typeInfo->GetValueKind() & VALUEKIND::DATA)
		{
			*reinterpret_cast<Data*>(PrivateGetPtr()) = std::move(src);
			return OK;
		}

		if (_typeInfo != src.GetType())
			return CreateError(MAXON_SOURCE_LOCATION, ERROR_TYPE::ILLEGAL_STATE);

		_typeInfo->MoveFrom(PrivateGetPtr(), (void*) src.PrivateGetPtr(_typeInfo), 1);
		return OK;
	}

	//----------------------------------------------------------------------------------------
	/// Copies from another Data.
	/// @param[in] src								Data to copy from.
	/// @return												OK on success (will fail if this DataPtr has a non-matching type).
	//----------------------------------------------------------------------------------------
	Result<void> CopyFrom(const Data& src)
	{
		if (!_typeInfo)
			return CreateError(MAXON_SOURCE_LOCATION, ERROR_TYPE::ILLEGAL_ARGUMENT);

		if (_typeInfo->GetValueKind() & VALUEKIND::DATA)
			return reinterpret_cast<Data*>(PrivateGetPtr())->CopyFrom(src);

		if (_typeInfo != src.GetType())
			return CreateError(MAXON_SOURCE_LOCATION, ERROR_TYPE::ILLEGAL_STATE);

		return _typeInfo->CopyFrom(PrivateGetPtr(), (const void*) src.PrivateGetPtr(_typeInfo), 1);
	}
};

//----------------------------------------------------------------------------------------
/// MoveDataPtr contains type info and a pointer to an arbitrary generic object.
/// The type of the object is only known at run-time.
/// MoveDataPtr is typically used as parameter type of a generic function which accepts any
/// type of object and moves the object to some other location.
//----------------------------------------------------------------------------------------
class MoveDataPtr : public DataPtr
{
public:
	MoveDataPtr() = default;

	MoveDataPtr(const DataType& typeInfo, Generic* dataPtr) : DataPtr(typeInfo, dataPtr)
	{
	}

	explicit MoveDataPtr(Data&& value) : DataPtr(value)
	{
	}

	template <typename T> explicit MoveDataPtr(T&& value) : DataPtr(value)
	{
		static_assert(!std::is_reference<T>::value && !std::is_const<T>::value, "Can't initialize a MoveDataPtr with a const value or non-rvalue.");
	}

	using ConstDataPtr::Get;

	template <typename T> Result<typename std::conditional<std::is_void<T>::value, void, typename std::conditional<std::is_same<T, Data>::value, Data, T&&>::type>::type> Get()
	{
		T* ptr = GetPtr<T>();
		if (!ptr)
			return CreateError(MAXON_SOURCE_LOCATION, ERROR_TYPE::ILLEGAL_STATE);
		return std::move(*ptr);
	}

	static const MoveDataPtr& NullValue() { return GetZeroRef<MoveDataPtr>(); }
};

// specialization of void case
template <> inline Result<void> ConstDataPtr::Get<void>() const
{
	return OK;
}

template <> inline Result<Data> ConstDataPtr::Get<Data>() const
{
	iferr_scope;
	Data copy;
	copy.CopyFrom(*this) iferr_return;
	return std::move(copy);
}

template <> inline Result<Data> MoveDataPtr::Get<Data>()
{
	iferr_scope;
	Data copy;
	copy.MoveFrom(MoveDataPtr(this->_typeInfo, const_cast<Generic*>(this->_dataPtr))) iferr_return;
	return std::move(copy);
}

//----------------------------------------------------------------------------------------
/// ForwardingDataPtr contains type info and a pointer to an arbitrary generic object
/// plus the information if the object shall be moved or not.
/// ForwardingDataPtr is typically used as parameter type of a generic function which accepts any
/// type of object and moves or copies the object to some other location.
//----------------------------------------------------------------------------------------
struct ForwardingDataPtr
{
	ForwardingDataPtr()
	{
	}

	MAXON_IMPLICIT ForwardingDataPtr(const ConstDataPtr& ptr) : data(ptr), move(false) { }
	MAXON_IMPLICIT ForwardingDataPtr(MoveDataPtr&& ptr) : data(static_cast<const ConstDataPtr&>(ptr)), move(true) { }

	Result<Data> GetData()
	{
		if (move)
			return static_cast<MoveDataPtr&>(data).Get<Data>();
		else
			return data.Get<Data>();
	}

	ConstDataPtr data; // This has to be the first member so that a ForwardingDataPtr can be cast to a ConstDataPtr.
	Bool move;
};


//----------------------------------------------------------------------------------------
/// AbstractDataTypeFunctions can be used as base class of a class which implements the DataType functions
/// for a type. AbstractDataTypeFunctions implements all DataType functions, either by returning an
/// error, showing a CriticalStop or forwarding to other functions. For example the MoveFrom function is implemented
/// by at first calling Destruct and then MoveConstruct, while Destruct and MoveConstruct show a
/// CriticalStop(). At least the functions Construct, Destruct, MoveConstruct, CopyFrom
/// have to be implemented for a working DataType and IsEqual, Compare, GetHashCode to support comparisons.
/// The other functions can be implemented to improve the performance.
//----------------------------------------------------------------------------------------
class AbstractDataTypeFunctions
{
public:
	static const VALUEKIND CAPABILITY_FLAGS = VALUEKIND::NONE;

	static void AddReference(const DataTypeImpl* type, const void* obj);

	static void RemoveReference(const DataTypeImpl* type, const void* obj);

	static Result<void*> Create(const DataTypeImpl* type);

	static Result<void> DescribeIO(const DataTypeImpl* type, const DataSerializeInterface& dsi);

	static void Construct(const DataTypeImpl* type, void* dest, Int count);

	static void Destruct(const DataTypeImpl* type, const void* dest, Int count);

	static void MoveConstruct(const DataTypeImpl* type, void* dest, void* src, Int count);

	static void MoveFrom(const DataTypeImpl* type, void* dest, void* src, Int count);

	static Result<void> CopyFrom(const DataTypeImpl* type, void* dest, const void* src, Int count);

	static Result<Bool> UpdateFrom(const DataTypeImpl* type, void* dest, const void* src);

	static Result<void> InitData(const DataTypeImpl* type, DataMemBlock* mem);

	static void FreeData(const DataTypeImpl* type, DataMemBlock* mem);

	static const void* GetPtr(const DataTypeImpl* type, const DataMemBlock* s);

	static Result<void> CopyData(const DataTypeImpl* type, DataMemBlock* d, const DataMemBlock* s);

	static Result<void> InitCopyData(const DataTypeImpl* type, DataMemBlock* d, const DataMemBlock* s);

	static void MoveData(const DataTypeImpl* type, DataMemBlock* d, DataMemBlock* s);

	static void InitMoveData(const DataTypeImpl* type, DataMemBlock* d, DataMemBlock* s);

	static Bool IsEqualData(const DataTypeImpl* type, const DataMemBlock* a, const DataMemBlock* b, EQUALITY equality);

	static Bool IsEqual(const DataTypeImpl* type, const void* a, const void* b, EQUALITY equality);

	static COMPARERESULT Compare(const DataTypeImpl* type, const void* a, const void* b);

	static UInt GetHashCode(const DataTypeImpl* type, const void* a);

	static String ToStringImpl(const DataTypeImpl* type, const void* a, const FormatStatement* formatStatement);
};


/// @}

} // namespace maxon

#endif // DATATYPEBASE_H__
