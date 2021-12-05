/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef C4D_BASECONTAINER_H__
#define C4D_BASECONTAINER_H__

#ifdef __API_INTERN__
	#include "basecontainer.h"
#else

	#include "ge_math.h"
	#include "c4d_basetime.h"
	#include "c4d_string.h"
	#include "c4d_file.h"
	#include "c4d_gedata.h"
	#include "c4d_uuid.h"

	#if defined MAXON_TARGET_LINUX
		#include <stddef.h>
	#endif

#ifdef CINEWARE_NAMESPACE_ENABLE
	CINEWARE_NAMESPACE_BEGIN
#endif

class BaseDocument;
class BaseObject;
class BaseMaterial;

//-------------------------------------------------------------------------------------------------
/// A container is a collection of individual values. Each value has its own ID and type. Container can also carry any number of child containers.\n
/// @em 90% of @C4D's internal values are stored in containers and all messages are working with container, so this class is an essential part of the SDK.
///
/// Containers can store any GeData type, including custom data types. Use GetCustomDataType() to access these values in a safe manner.
///
/// It is recommended to use the available containers to store your own values as well. That way they will be automatically saved.\n
/// However, to store values in the top level of for example an object container, use a sub-container with a unique id from http://www.plugincafe.com. Inside this sub-container use whatever ids.\n
///
/// @warning	Keep in mind that there is no guarantee for a value to be in the container. Use default values whenever possible when accessing container's ID data.\n
///						Use the typed access methods (for example GetBool()) whenever possible, instead of the low-level GetData().\n
///						Once a container value has been set using one type you must neither try to access it using another type, nor overwrite it with a value of another type! Using the wrong access will not crash, but it is illegal.
//-------------------------------------------------------------------------------------------------
class BaseContainer
{
	#define BcCall(fnc) (this->*C4DOS.Bc->fnc)

private:
	C4D_RESERVE_PRIVATE_TYPE(void*, dummy1);
	C4D_RESERVE_PRIVATE_TYPE(Int, dummy2);
	C4D_RESERVE_PRIVATE_TYPE(Int32, dummy3);
	C4D_RESERVE_PRIVATE_TYPE(Int32, dummy4);
	C4D_RESERVE_PRIVATE_TYPE(Int32, dummy5);

public:
	/// @name Constructor/Destructor
	/// @{

	//-------------------------------------------------------------------------------------------------
	/// Default constructor. Creates an empty container with ID @em 0.
	//-------------------------------------------------------------------------------------------------
	BaseContainer();

	//----------------------------------------------------------------------------------------
	/// Creates a container with a specific @formatParam{id}.
	/// @param[in] id									The container ID.
	//----------------------------------------------------------------------------------------
	explicit BaseContainer(Int32 id);

	//----------------------------------------------------------------------------------------
	/// Copy constructor. Creates a new container with all the IDs and values from the source one.
	/// @param[in] n									The source container.
	//----------------------------------------------------------------------------------------
	BaseContainer(const BaseContainer& n);

	//----------------------------------------------------------------------------------------
	/// Destructor.
	//----------------------------------------------------------------------------------------
	~BaseContainer(void);

	/// @}

	/// @name Assign/Clone/Copy
	/// @{

	//----------------------------------------------------------------------------------------
	/// Assignment operator. Copies all values from the source container.
	/// @param[in] n									The source container.
	/// @return												The assigned source container to the left-operand container.
	//----------------------------------------------------------------------------------------
	const BaseContainer& operator = (const BaseContainer& n);

	//----------------------------------------------------------------------------------------
	/// Retrieves a copy of the container including all values.
	/// @param[in] flags							The flags for the clone: @enumerateEnum{COPYFLAGS}
	/// @param[in] trans							An alias translator for the operation. Can be @formatConstant{nullptr}. @callerOwnsPointed{alias translator}
	/// @return												The cloned container. @callerOwnsPointed{container}
	//----------------------------------------------------------------------------------------
	BaseContainer* GetClone(COPYFLAGS flags, AliasTrans* trans) const { return BcCall(GetClone) (flags, trans); }

	//----------------------------------------------------------------------------------------
	/// Copies the container values into the destination container @formatParam{dst}.
	/// @param[out] dst								The destination container. @callerOwnsPointed{container}
	/// @param[in] flags							The flags for the clone: @enumerateEnum{COPYFLAGS}
	/// @param[in] trans							An alias translator for the operation. Can be @formatConstant{nullptr}. @callerOwnsPointed{alias translator}
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool CopyTo(BaseContainer* dst, COPYFLAGS flags, AliasTrans* trans) const { return BcCall(CopyTo) (dst, flags, trans); }

	/// @}

	/// @name Flush All
	/// @{

	//----------------------------------------------------------------------------------------
	/// Clears all values in the container. The container ID is not changed.
	//----------------------------------------------------------------------------------------
	void FlushAll(void) { return BcCall(FlushAll) (); }

	/// @}

	/// @name Id
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets the ID of the container.
	/// @return												The container ID.
	//----------------------------------------------------------------------------------------
	Int32 GetId() const { return BcCall(GetId) (); }

	//----------------------------------------------------------------------------------------
	/// Sets the ID of the container.
	/// @param[in] c_id								The container ID.
	//----------------------------------------------------------------------------------------
	void SetId(Int32 c_id){ BcCall(SetId) (c_id); }

	/// @}

	/// @name Dirty
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets the dirty count. It is incremented when the container changes so it can be used to check if the container has changed.
	/// @return												The dirty counter.
	//----------------------------------------------------------------------------------------
	UInt32 GetDirty() const { return BcCall(GetDirty) (); }

	/// @}

	/// @name Remove Data/Index
	/// @{

	//----------------------------------------------------------------------------------------
	/// Removes the first data item with the specified @formatParam{id}.
	/// @param[in] id									The ID of the value to be removed.
	/// @return												@trueIfOtherwiseFalse{any value was removed}
	//----------------------------------------------------------------------------------------
	Bool RemoveData(Int32 id) { return BcCall(RemoveData) (id); }

	//----------------------------------------------------------------------------------------
	/// Removes the data item at the specified index @formatParam{i}.
	/// @param[in] i									The index of the value to be removed.
	/// @return												@trueIfOtherwiseFalse{any value was removed}
	//----------------------------------------------------------------------------------------
	Bool RemoveIndex(Int32 i) { return BcCall(RemoveIndex) (i); }

	/// @}

	/// @name Find Index / Get Index Id
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets the index for the value with the specified @formatParam{id}. @formatParam{ppData} is optionally assigned the data of the specified @formatParam{id}.
	/// @param[in] id									The ID of the value.
	/// @param[out] ppData						Assigned the data of the specified @formatParam{id}, if not @formatConstant{nullptr}.
	/// @return												The index of the value, or @ref NOTOK if such value does not exists.
	//----------------------------------------------------------------------------------------
	Int32 FindIndex(Int32 id, GeData** ppData = nullptr) const { return BcCall(FindIndex) (id, ppData); }

	//----------------------------------------------------------------------------------------
	/// Gets the ID of the element at the specified @formatParam{index}.\n
	/// Can be used to browse through the container:
	/// @code
	/// Int32 i = 0;
	/// while (true)
	/// {
	/// 	id = GetIndexId(i++);
	/// 	if (id==NOTOK) break;
	/// 	...
	/// }
	/// @endcode
	/// @param[in] index							The index of the value.
	/// @return												The ID of the value, or @ref NOTOK if it does not exist.
	//----------------------------------------------------------------------------------------
	Int32 GetIndexId(Int32 index) const { return BcCall(GetIndexId) (index); }

	/// @}

	/// @name Get Data Pointer(s)
	/// @{

	//----------------------------------------------------------------------------------------
	/// Retrieves a pointer to directly access the data (Read-only).
	/// @param[in] id									The ID of the data.
	/// @return												A pointer to the data (Read-only). @theOwnsPointed{container,data}
	//----------------------------------------------------------------------------------------
	const GeData* GetDataPointer(Int32 id) const { return BcCall(GetDataPointer) (id); }

	//----------------------------------------------------------------------------------------
	/// Retrieves an array of pointers to directly access the data (Read-only).
	/// @param[out] ids								Assigned a pointer to the array of data IDs. @theOwnsPointed{container,array}
	/// @param[in] cnt								The number of array elements.
	/// @param[out] data							Assigned a pointer to the data pointer array. @theOwnsPointed{container,array}
	//----------------------------------------------------------------------------------------
	void GetDataPointers(const Int32* ids, Int32 cnt, const GeData** data) const { return BcCall(GetDataPointers) (ids, cnt, data); }

	/// @}

	/// @name Data
	/// @{

	//----------------------------------------------------------------------------------------
	/// Retrieves the data for the element at @formatParam{index}.
	/// @param[in] index							The index of the element.
	/// @return												The data, or @formatConstant{nullptr} if no data was found. @theOwnsPointed{container,data} Must not be changed!
	//----------------------------------------------------------------------------------------
	GeData* GetIndexData(Int32 index) const { return BcCall(GetIndexData) (index); }

	//----------------------------------------------------------------------------------------
	/// Inserts an arbitrary data at the specified @formatParam{id}.
	/// @note Does not check if the ID already exists in the container.
	/// @param[in] id									The ID to insert at.
	/// @param[in] n									The data to insert.
	/// @return												The inserted data. @theOwnsPointed{container,data}
	//----------------------------------------------------------------------------------------
	GeData* InsData(Int32 id, const GeData& n) { return BcCall(InsData) (id, n); }

	//----------------------------------------------------------------------------------------
	/// Inserts an arbitrary data at the specified @formatParam{id} after @formatParam{last}.
	/// @param[in] id									The ID to insert at.
	/// @param[in] n									The data to insert.
	/// @param[in] last								The data to insert after. @theOwnsPointed{container,data}
	/// @return												The inserted data. @theOwnsPointed{container,data}
	//----------------------------------------------------------------------------------------
	GeData* InsDataAfter(Int32 id, const GeData& n, GeData* last) { return BcCall(InsDataAfter) (id, n, last); }

	//----------------------------------------------------------------------------------------
	/// Sets an arbitrary data at the specified @formatParam{id}. If a value exists under the same ID, its content will be changed.
	/// @param[in] id									The ID of the element to set.
	/// @param[in] n									The data to set.
	/// @return												The data set, or a @ref DA_NIL data if it was not found.
	//----------------------------------------------------------------------------------------
	GeData* SetData(Int32 id, const GeData& n) { return BcCall(SetData) (id, n); }

	//----------------------------------------------------------------------------------------
	/// Retrieves the data for an element at the specified @formatParam{id}.
	/// @param[in] id									The ID of the element.
	/// @return												The data, or a @ref DA_NIL data if it was not found.
	//----------------------------------------------------------------------------------------
	const GeData& GetData(Int32 id) const { return BcCall(GetData) (id); }

	/// @}

	/// @name Equal/Not Equal Operators
	/// @{

	//----------------------------------------------------------------------------------------
	/// Equality operator. Checks if the containers have the same IDs, the same values and all values are equal.
	/// @note IDs have to be in the same order.
	/// @param[in] d									The container to compare against.
	/// @return												@trueIfOtherwiseFalse{the containers have the same IDs, the same values and all values are equal}
	//----------------------------------------------------------------------------------------
	Bool operator == (const BaseContainer& d) const;

	//----------------------------------------------------------------------------------------
	/// Not equal operator. Checks if the containers have different IDs, different values or values are different.
	/// @param[in] d									The container to compare against.
	/// @return												@trueIfOtherwiseFalse{the containers have different IDs, different values or values are different}
	//----------------------------------------------------------------------------------------
	Bool operator != (const BaseContainer& d) const;

	/// @}

	/// @name Get Data
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets the ::Bool value at the specified @formatParam{id}.
	/// @param[in] id									The ID of the requested value.
	/// @param[in] preset							Returned if the value is not available.
	/// @return												The value.
	//----------------------------------------------------------------------------------------
	Bool GetBool(Int32 id, Bool preset = false) const { return BcCall(GetBool) (id, preset); }

	//----------------------------------------------------------------------------------------
	/// Gets the ::Int32 value at the specified @formatParam{id}.
	/// @param[in] id									The ID of the requested value.
	/// @param[in] preset							Returned if the value is not available.
	/// @return												The value.
	//----------------------------------------------------------------------------------------
	Int32 GetInt32(Int32 id, Int32 preset = 0) const { return BcCall(GetInt32) (id, preset); }

	//----------------------------------------------------------------------------------------
	/// Gets the ::UInt32 value at the specified @formatParam{id}.
	/// @param[in] id									The ID of the requested value.
	/// @param[in] preset							Returned if the value is not available.
	/// @return												The value.
	//----------------------------------------------------------------------------------------
	UInt32 GetUInt32(Int32 id, UInt32 preset = 0) const { return BcCall(GetUInt32) (id, preset); }

	//----------------------------------------------------------------------------------------
	/// Gets the ::Int64 value at the specified @formatParam{id}.
	/// @param[in] id									The ID of the requested value.
	/// @param[in] preset							Returned if the value is not available.
	/// @return												The value.
	//----------------------------------------------------------------------------------------
	Int64 GetInt64(Int32 id, Int64 preset = 0) const { return BcCall(GetInt64) (id, preset); }

	//----------------------------------------------------------------------------------------
	/// Gets the ::UInt64 value at the specified @formatParam{id}.
	/// @param[in] id									The ID of the requested value.
	/// @param[in] preset							Returned if the value is not available.
	/// @return												The value.
	//----------------------------------------------------------------------------------------
	UInt64 GetUInt64(Int32 id, UInt64 preset = 0) const { return BcCall(GetUInt64) (id, preset); }

	//----------------------------------------------------------------------------------------
	/// Gets the ::Float value at the specified @formatParam{id}.
	/// @param[in] id									The ID of the requested value.
	/// @param[in] preset							Returned if the value is not available.
	/// @return												The value.
	//----------------------------------------------------------------------------------------
	Float GetFloat(Int32 id, Float preset = 0.0) const { return BcCall(GetFloat) (id, preset); }

	//----------------------------------------------------------------------------------------
	/// Gets the @c void* value at the specified @formatParam{id}.
	/// @param[in] id									The ID of the requested value.
	/// @param[in] preset							Returned if the value is not available.
	/// @return												The value, or @formatParam{preset} if it does not exist.
	//----------------------------------------------------------------------------------------
	void* GetVoid(Int32 id, void* preset = nullptr) const { return BcCall(GetVoid) (id, preset); }

	//----------------------------------------------------------------------------------------
	/// Gets the memory buffer at the specified @formatParam{id}.
	/// @note In this version of GetMemory() the caller takes over the ownership of the memory block.\n
	///				The memory block must be allocated with NewMem() and deallocated with DeleteMem().
	/// @param[in] id									The ID of the requested value.
	/// @param[out] count							Assigned the number of bytes in the memory buffer returned.
	/// @param[in] preset							Returned if the value is not available.
	/// @return												The memory buffer, or @formatParam{preset} if it does not exist. The caller takes over the ownership of the memory block.
	//----------------------------------------------------------------------------------------
	void* GetMemoryAndRelease(Int32 id, Int& count, void* preset = nullptr) { return BcCall(GetMemoryAndRelease) (id, count, preset); }

	//----------------------------------------------------------------------------------------
	/// Gets the memory buffer at the specified @formatParam{id}.
	/// @param[in] id									The ID of the requested value.
	/// @param[out] count							Assigned the number of bytes in the memory buffer returned.
	/// @param[in] preset							Returned if the value is not available.
	/// @return												The memory buffer, or @formatParam{preset} if it does not exist. @theOwnsPointed{container,memory block}
	//----------------------------------------------------------------------------------------
	void* GetMemory(Int32 id, Int& count, void* preset = nullptr) const { return BcCall(GetMemory) (id, count, preset); }

	//----------------------------------------------------------------------------------------
	/// Gets the ::Vector value at the specified @formatParam{id}.
	/// @param[in] id									The ID of the requested value.
	/// @param[in] preset							Returned if the value is not available.
	/// @return												The value.
	//----------------------------------------------------------------------------------------
	Vector GetVector(Int32 id, const Vector& preset = Vector()) const { return BcCall(GetVector) (id, preset); }

	//----------------------------------------------------------------------------------------
	/// Gets the ::Matrix value at the specified @formatParam{id}.
	/// @param[in] id									The ID of the requested value.
	/// @param[in] preset							Returned if the value is not available.
	/// @return												The value.
	//----------------------------------------------------------------------------------------
	Matrix GetMatrix(Int32 id, const Matrix& preset = Matrix()) const { return BcCall(GetMatrix) (id, preset); }

	//----------------------------------------------------------------------------------------
	/// Gets the String value at the specified @formatParam{id}.
	/// @param[in] id									The ID of the requested value.
	/// @param[in] preset							Returned if the value is not available.
	/// @return												The value.
	//----------------------------------------------------------------------------------------
	String GetString(Int32 id, const maxon::String& preset = maxon::String()) const { return BcCall(GetString) (id, preset); }

	//----------------------------------------------------------------------------------------
	/// Gets the C4DUuid value at the specified @formatParam{id}.
	/// @param[in] id									The ID of the requested value.
	/// @param[in] preset							Returned if the value is not available.
	/// @return												The value.
	//----------------------------------------------------------------------------------------
	C4DUuid GetUuid(Int32 id, const C4DUuid& preset = C4DUuid(DC)) const { return BcCall(GetUuid) (id, preset); }

	//----------------------------------------------------------------------------------------
	/// Gets the Filename value at the specified @formatParam{id}.
	/// @param[in] id									The ID of the requested value.
	/// @param[in] preset							Returned if the value is not available.
	/// @return												The value.
	//----------------------------------------------------------------------------------------
	Filename GetFilename(Int32 id, const Filename& preset = Filename()) const { return BcCall(GetFilename) (id, preset); }

	//----------------------------------------------------------------------------------------
	/// Gets the BaseTime value at the specified @formatParam{id}.
	/// @param[in] id									The ID of the requested value.
	/// @param[in] preset							Returned if the value is not available.
	/// @return												The value.
	//----------------------------------------------------------------------------------------
	BaseTime GetTime(Int32 id, const BaseTime& preset = BaseTime()) const { return BcCall(GetTime) (id, preset); }

	//----------------------------------------------------------------------------------------
	/// Gets a copy of the sub-container at the specified @formatParam{id}.
	/// @param[in] id									The ID of the requested sub-container.
	/// @return												The sub-container, or an empty container if it does not exist.
	//----------------------------------------------------------------------------------------
	BaseContainer GetContainer(Int32 id) const { return BcCall(GetContainer) (id); }

	//----------------------------------------------------------------------------------------
	/// Gets a pointer to the sub-container at the specified @formatParam{id}. Changes to the pointed container are reflected in the stored sub-container.
	/// @param[in] id									The ID of the requested sub-container ID.
	/// @return												A pointer to the sub-container, or @formatConstant{nullptr} if it does not exist. @theOwnsPointed{container,sub-container}
	//----------------------------------------------------------------------------------------
	BaseContainer* GetContainerInstance(Int32 id) { return BcCall(GetContainerInstance) (id); }

	//----------------------------------------------------------------------------------------
	/// Gets a read-only pointer to the sub-container with the specified @formatParam{id}.
	/// @since R17.032
	/// @param[in] id									The ID of the requested sub-container ID.
	/// @return												A pointer to the sub-container, or @formatConstant{nullptr} if it does not exist. @theOwnsPointed{container,sub-container}
	//----------------------------------------------------------------------------------------
	const BaseContainer* GetContainerInstance(Int32 id) const { return BcCall(GetContainerInstanceConst) (id); }

	//----------------------------------------------------------------------------------------
	/// Gets a linked baselist node at the specified @formatParam{id}. Equivalent to BaseLink::GetLink().\n
	/// If @formatParam{instanceof} is specified, @formatConstant{nullptr} is returned if the node is not of this type.
	/// @param[in] id									The ID of the requested value.
	/// @param[in] doc								The document to evaluate the link in. @callerOwnsPointed{document}
	/// @param[in] instanceof					Set this to a node type to only return the link if it is of this type.
	/// @return												The linked object, or @formatConstant{nullptr} if the link is broken. @theOwnsPointed{document,linked baselist}
	//----------------------------------------------------------------------------------------
	BaseList2D* GetLink(Int32 id, const BaseDocument* doc, Int32 instanceof = 0) const { return BcCall(GetLink) (id, doc, instanceof); }

	//----------------------------------------------------------------------------------------
	/// Gets a linked object at the specified @formatParam{id}.
	/// @param[in] id									The ID of the requested object link.
	/// @param[in] doc								The document to evaluate the object link in. @callerOwnsPointed{document}
	/// @return												The linked object, or @formatConstant{nullptr} if the link is broken. @theOwnsPointed{document,linked object}
	//----------------------------------------------------------------------------------------
	BaseObject* GetObjectLink(Int32 id, const BaseDocument* doc) const;

	//----------------------------------------------------------------------------------------
	/// Gets a linked material at the specified @formatParam{id}.
	/// @param[in] id									The ID of the requested link.
	/// @param[in] doc								The document to evaluate the link in. @callerOwnsPointed{document}
	/// @return												The linked material, or @formatConstant{nullptr} if the link is broken. @theOwnsPointed{document,linked material}
	//----------------------------------------------------------------------------------------
	BaseMaterial* GetMaterialLink(Int32 id, const BaseDocument* doc) const;

	//----------------------------------------------------------------------------------------
	/// Gets the BaseLink at the specified @formatParam{id}.
	/// @param[in] id									The ID of the requested link.
	/// @return												The link, or @formatConstant{nullptr} if there is no link stored. @theOwnsPointed{container,link}
	//----------------------------------------------------------------------------------------
	BaseLink* GetBaseLink(Int32 id) const;

	//----------------------------------------------------------------------------------------
	/// Gets the CustomDataType value at the specified @formatParam{id}.
	/// @param[in] id									The ID of the requested custom datatype.
	/// @param[in] datatype						The datatype type ID.
	/// @return												The custom datatype, or @formatConstant{nullptr} if it does not exist or the wrong @formatParam{datatype} was specified. @theOwnsPointed{container,custom datatype}
	//----------------------------------------------------------------------------------------
	const CustomDataType* GetCustomDataType(Int32 id, Int32 datatype) const;

	/// @}

	/// @name Get Type
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets the type of the element at the specified @formatParam{id}.
	/// @param[in] id									The ID of the element.
	/// @return												The type of the element: @enumerateEnum{DA_TYPES}
	//----------------------------------------------------------------------------------------
	Int32 GetType(Int32 id) const;

	/// @}

	/// @name Set Data
	/// @{

	//----------------------------------------------------------------------------------------
	/// Sets the ::Bool value at the specified @formatParam{id}, or inserts it if it does not exist.
	/// @param[in] id									The ID of the value to set.
	/// @param[in] b									The new or inserted value.
	//----------------------------------------------------------------------------------------
	void SetBool(Int32 id, Bool b) { return BcCall(SetBool) (id, b); }

	//----------------------------------------------------------------------------------------
	/// Sets the ::Int32 value at the specified @formatParam{id}, or inserts it if it does not exist.
	/// @param[in] id									The ID of the value to set.
	/// @param[in] l									The new or inserted value.
	//----------------------------------------------------------------------------------------
	void SetInt32(Int32 id, Int32 l) { return BcCall(SetInt32) (id, l); }

	//----------------------------------------------------------------------------------------
	/// Sets the ::UInt32 value at the specified @formatParam{id}, or inserts it if it does not exist.
	/// @param[in] id									The ID of the value to set.
	/// @param[in] l									The new or inserted value.
	//----------------------------------------------------------------------------------------
	void SetUInt32(Int32 id, UInt32 l) { return BcCall(SetUInt32) (id, l); }

	//----------------------------------------------------------------------------------------
	/// Sets the ::Int64 value at the specified @formatParam{id}, or inserts it if it does not exist.
	/// @param[in] id									The ID of the value to set.
	/// @param[in] l									The new or inserted value.
	//----------------------------------------------------------------------------------------
	void SetInt64(Int32 id, Int64 l) { return BcCall(SetInt64) (id, l); }

	//----------------------------------------------------------------------------------------
	/// Sets the ::UInt64 value at the specified @formatParam{id}, or inserts it if it does not exist.
	/// @param[in] id									The ID of the value to set.
	/// @param[in] l									The new or inserted value.
	//----------------------------------------------------------------------------------------
	void SetUInt64(Int32 id, UInt64 l) { return BcCall(SetUInt64) (id, l); }

	//----------------------------------------------------------------------------------------
	/// Sets the ::Float value at the specified @formatParam{id}, or inserts it if it does not exist.
	/// @param[in] id									The ID of the value to set.
	/// @param[in] r									The new or inserted value.
	//----------------------------------------------------------------------------------------
	void SetFloat(Int32 id, Float r) { return BcCall(SetFloat) (id, r); }

	//----------------------------------------------------------------------------------------
	/// Sets the @c void* value at the specified @formatParam{id}, or inserts it if it does not exist.
	/// @param[in] id									The ID of the value to set.
	/// @param[in] v									The new or inserted value.
	//----------------------------------------------------------------------------------------
	void SetVoid(Int32 id, void* v) { return BcCall(SetVoid) (id, v); }

	//----------------------------------------------------------------------------------------
	/// Sets the memory block at the specified @formatParam{id} to @formatParam{mem}, or inserts it if it did not exist.
	/// @param[in] id									The ID of the value to set.
	/// @param[in] mem								The memory buffer. The container takes the ownership over the memory buffer.
	/// @param[in] count							The number of bytes in @formatParam{mem}.
	//----------------------------------------------------------------------------------------
	void SetMemory(Int32 id, void* mem, Int count) { return BcCall(SetMemory) (id, mem, count); }

	//----------------------------------------------------------------------------------------
	/// Sets the ::Vector value at the specified @formatParam{id}, or inserts it if it does not exist.
	/// @param[in] id									The ID of the value to set.
	/// @param[in] v									The new or inserted value.
	//----------------------------------------------------------------------------------------
	void SetVector(Int32 id, const Vector& v) { return BcCall(SetVector) (id, v); }

	//----------------------------------------------------------------------------------------
	/// Sets the ::Matrix value at the specified @formatParam{id}, or inserts it if it does not exist.
	/// @param[in] id									The ID of the value to set.
	/// @param[in] m									The new or inserted value.
	//----------------------------------------------------------------------------------------
	void SetMatrix(Int32 id, const Matrix& m) { return BcCall(SetMatrix) (id, m); }

	//----------------------------------------------------------------------------------------
	/// Sets the String value at the specified @formatParam{id}, or inserts it if it does not exist.
	/// @param[in] id									The ID of the value to set.
	/// @param[in] s									The new or inserted value.
	//----------------------------------------------------------------------------------------
	void SetString(Int32 id, const maxon::String& s) { return BcCall(SetString) (id, s); }

	//----------------------------------------------------------------------------------------
	/// Sets the C4DUuid value at the specified @formatParam{id}, or inserts it if it does not exist.
	/// @param[in] id									The ID of the value to set.
	/// @param[in] u									The new or inserted value.
	//----------------------------------------------------------------------------------------
	void SetUuid(Int32 id, const C4DUuid& u) { return BcCall(SetUuid) (id, u); }

	//----------------------------------------------------------------------------------------
	/// Sets the Filename value at the specified @formatParam{id}, or inserts it if it does not exist.
	/// @param[in] id									The ID of the value to set.
	/// @param[in] f									The new or inserted value.
	//----------------------------------------------------------------------------------------
	void SetFilename(Int32 id, const Filename& f) { return BcCall(SetFilename) (id, f); }

	//----------------------------------------------------------------------------------------
	/// Sets the BaseTime value at the specified @formatParam{id}, or inserts it if it does not exist.
	/// @param[in] id									The ID of the value to set.
	/// @param[in] b									The new or inserted value.
	//----------------------------------------------------------------------------------------
	void SetTime(Int32 id, const BaseTime& b) { return BcCall(SetTime) (id, b); }

	//----------------------------------------------------------------------------------------
	/// Sets the sub-container value at the specified @formatParam{id}, or inserts it if it does not exist.
	/// @param[in] id									The ID of the value to set.
	/// @param[in] s									The new or inserted value.
	//----------------------------------------------------------------------------------------
	void SetContainer(Int32 id, const BaseContainer& s) { return BcCall(SetContainer) (id, s); }

	//----------------------------------------------------------------------------------------
	/// Sets the link value at the specified @formatParam{id}, or inserts it if it does not exist.
	/// @param[in] id									The ID of the value to set.
	/// @param[in] link								The new or inserted value.
	//----------------------------------------------------------------------------------------
	void SetLink(Int32 id, C4DAtomGoal* link) { return BcCall(SetLink) (id, link); }

	/// @}

	/// @name Merge Container
	/// @{

	//----------------------------------------------------------------------------------------
	/// Stores the values from @formatParam{src} in the container, overwriting any elements with the same IDs and keeping the rest.
	/// @param[in] src								The source container to merge.
	//----------------------------------------------------------------------------------------
	void MergeContainer(const BaseContainer& src);

	/// @}

	/// @name Get/Set Parameter
	/// @{

	//----------------------------------------------------------------------------------------
	/// Retrieves the GeData for the specified parameter description @formatParam{id}.
	/// @param[in] id									The ID of the requested data.
	/// @param[out] t_data						Assigned the retrieved data.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool GetParameter(const DescID& id, GeData& t_data) const { return BcCall(GetParameter) (id, t_data); }

	//----------------------------------------------------------------------------------------
	/// Sets the GeData for the specified parameter description @formatParam{id}.
	/// @param[in] id									The ID of the parameter to set.
	/// @param[in] t_data							The data to set or insert.
	//----------------------------------------------------------------------------------------
	Bool SetParameter(const DescID& id, const GeData& t_data) { return BcCall(SetParameter) (id, t_data); }

	/// @}

	/// @name Sort
	/// @{

	//----------------------------------------------------------------------------------------
	/// Sorts the container entries by ID.
	/// @note This function sorts the strings and remove any other value. (keeping the ID)
	//----------------------------------------------------------------------------------------
	void Sort() { BcCall(Sort) (); };

	/// @}
};

#ifdef CINEWARE_NAMESPACE_ENABLE
	CINEWARE_NAMESPACE_END
#endif

#endif // __API_INTERN__

#endif // C4D_BASECONTAINER_H__
