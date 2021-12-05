/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef C4D_GEDATA_H__
#define C4D_GEDATA_H__

#ifdef __API_INTERN__
	#error "Not in the kernel"
#endif

#include "ge_math.h"
#include "operatingsystem.h"
#include "c4d_string.h"

class C4DAtomGoal;
class BaseContainer;
class BaseTime;
class String;
class Filename;
class AliasTrans;
class BaseLink;
class BaseList2D;
class BaseDocument;
struct CustomDataType;

/// @addtogroup DA_TYPES
/// @ingroup group_enumeration
/// @{
enum DA
{
	DA_NIL						= 0,				///< No value.
	DA_VOID						= 14,				///< @c void*.
	DA_LONG						= 15,				///< ::Int32.
	DA_REAL						= 19,				///< ::Float.
	DA_TIME						= 22,				///< BaseTime.
	DA_VECTOR					= 23,				///< ::Vector.
	DA_MATRIX					= 25,				///< ::Matrix.
	DA_LLONG					= 26,				///< ::Int64.
	DA_BYTEARRAY			= 128,			///< @markInternal Mainly for QuickTime.
	DA_STRING					= 130,			///< String.
	DA_FILENAME				= 131,			///< Filename.
	DA_CONTAINER			= 132,			///< BaseContainer.
	DA_ALIASLINK			= 133,			///< BaseLink.
	DA_MARKER					= 256,			///< Not used.
	DA_MISSINGPLUG		= 257,			///< Denotes a missing datatype plugin.
	DA_UUID						= 258,			///< C4DUuid @since R17.048
	DA_TRISTATE				= 259,			///< No single value @Since R20

	DA_CUSTOMDATATYPE = 1000000,	///< DataTypes > @em 1000000 are custom.

	DA_END
};
/// @}

enum DEFAULTVALUETYPE
{
	DEFAULTVALUE			///< Dummy value for the default value GeData constructor.
};

enum VOIDVALUETYPE
{
	VOIDVALUE			///< Dummy value for the @c void* GeData constructor.
};

enum LLONGVALUETYPE
{
	LLONGVALUE			///< Dummy value for the <tt>long long</tt> (64-bit integer) GeData constructor.
};

//----------------------------------------------------------------------------------------
/// The GeData class can hold values of many different types, including custom data types.\n
/// It is used by many parts of the API, and can be stored in BaseContainer objects.
//----------------------------------------------------------------------------------------
class GeData
{
private:
	Int32 Type;
	Int32 dummy;	// Necessary for Linux alignment of structure

	union
	{
		Int32 DInteger;
		Float DReal;
		void* Ddata;
		Int64 DLLong;
	};

public:
	/// @name Constructor/Destructor
	/// @{

	//----------------------------------------------------------------------------------------
	/// Creates a @ref DA_NIL data with no value.
	//----------------------------------------------------------------------------------------
	GeData(void)
	{
		Type			= DA_NIL;
		DInteger	= 0;
	}

	//----------------------------------------------------------------------------------------
	/// Creates a @c float data.
	/// @param[in] n									The initial value.
	//----------------------------------------------------------------------------------------
	GeData(double n)
	{
		Type	= DA_REAL;
		DReal	= (Float)n;
	}

	//----------------------------------------------------------------------------------------
	/// Copy constructor.
	/// @param[in] n									The data to copy.
	//----------------------------------------------------------------------------------------
	GeData(const GeData& n)
	{
		Type	= DA_NIL;
		Ddata	= nullptr;
		C4DOS.Gd->CopyData(this, &n, nullptr);
	}

	//----------------------------------------------------------------------------------------
	/// Creates an ::Int32 data.
	/// @param[in] n									The initial value.
	//----------------------------------------------------------------------------------------
	GeData(Int32 n)
	{
		Type			= DA_LONG;
		DInteger	= n;
	}

	//----------------------------------------------------------------------------------------
	/// Creates a ::Float32 data.
	/// @param[in] n									The initial value.
	//----------------------------------------------------------------------------------------
	GeData(Float32 n)
	{
		Type	= DA_REAL;
		DReal	= n;
	}

	//----------------------------------------------------------------------------------------
	/// Creates a @c void* data.
	/// @param[in] v									The initial @c void* value.
	/// @param[in] xdummy							The dummy parameter. Should always be @ref VOIDVALUE.
	//----------------------------------------------------------------------------------------
	GeData(void* v, VOIDVALUETYPE xdummy)
	{
		Type	= DA_VOID;
		Ddata	= v;
	}

	//----------------------------------------------------------------------------------------
	/// Creates a <tt>long long</tt> (64-bit integer) data.
	/// @param[in] v									The initial value.
	/// @param[in] xdummy							The dummy parameter. Should always be @ref LLONGVALUE.
	//----------------------------------------------------------------------------------------
	GeData(Int64 v, LLONGVALUETYPE xdummy)
	{
		Type		= DA_LLONG;
		DLLong	= v;
	}

	//----------------------------------------------------------------------------------------
	/// Creates a ::Vector data.
	/// @param[in] n									The initial value.
	//----------------------------------------------------------------------------------------
	GeData(const Vector& n)
	{
		Type	= DA_NIL;
		Ddata	= nullptr;
		C4DOS.Gd->SetVector(this, n);
	}

	//----------------------------------------------------------------------------------------
	/// Creates a C4DUuid data.
	/// @param[in] n									The initial value.
	//----------------------------------------------------------------------------------------
	GeData(const C4DUuid& n)
	{
		Type	= DA_NIL;
		Ddata	= nullptr;
		C4DOS.Gd->SetUuid(this, &n);
	}

	//----------------------------------------------------------------------------------------
	/// Creates a Matrix data.
	/// @param[in] n									The initial value.
	//----------------------------------------------------------------------------------------
	GeData(const Matrix& n)
	{
		Type	= DA_NIL;
		Ddata	= nullptr;
		C4DOS.Gd->SetMatrix(this, n);
	}

	//----------------------------------------------------------------------------------------
	/// Creates a String data from a character buffer.
	/// @param[in] n									The initial value.
	//----------------------------------------------------------------------------------------
	GeData(const Char* n)
	{
		String str(n);
		Type	= DA_NIL;
		Ddata	= nullptr;
		C4DOS.Gd->SetString(this, str);
	}

	//----------------------------------------------------------------------------------------
	/// Creates a String data.
	/// @param[in] n									The initial value.
	//----------------------------------------------------------------------------------------
	GeData(const maxon::String& n)
	{
		Type	= DA_NIL;
		Ddata	= nullptr;
		C4DOS.Gd->SetString(this, n);
	}

	//----------------------------------------------------------------------------------------
	/// Creates a memory buffer data.
	/// @param[in] mem								The initial memory buffer value.
	/// @param[in] count							The number of bytes in the initial buffer.
	//----------------------------------------------------------------------------------------
	GeData(void* mem, Int count)
	{
		Type	= DA_NIL;
		Ddata	= nullptr;
		C4DOS.Gd->SetMemory(this, mem, count);
	}

	//----------------------------------------------------------------------------------------
	/// Creates a Filename data.
	/// @param[in] n									The initial value.
	//----------------------------------------------------------------------------------------
	GeData(const Filename& n)
	{
		Type	= DA_NIL;
		Ddata	= nullptr;
		C4DOS.Gd->SetFilename(this, &n);
	}

	//----------------------------------------------------------------------------------------
	/// Creates a BaseTime data.
	/// @param[in] n									The initial value.
	//----------------------------------------------------------------------------------------
	GeData(const BaseTime& n)
	{
		Type	= DA_NIL;
		Ddata	= nullptr;
		C4DOS.Gd->SetBaseTime(this, n);
	}

	//----------------------------------------------------------------------------------------
	/// Creates a BaseContainer data.
	/// @param[in] n									The initial value.
	//----------------------------------------------------------------------------------------
	GeData(const BaseContainer& n)
	{
		Type	= DA_NIL;
		Ddata	= nullptr;
		C4DOS.Gd->SetBaseContainer(this, &n);
	}

	//----------------------------------------------------------------------------------------
	/// Creates a BaseLink data.
	/// @param[in] n									The initial value.
	//----------------------------------------------------------------------------------------
	GeData(const BaseLink* n)
	{
		Type	= DA_NIL;
		Ddata	= nullptr;
		C4DOS.Gd->SetLink(this, *n);
	}

	//----------------------------------------------------------------------------------------
	/// Creates a BaseList2D data.
	/// @param[in] bl									The initial value.
	//----------------------------------------------------------------------------------------
	GeData(BaseList2D* bl)
	{
		Type	= DA_NIL;
		Ddata	= nullptr;
		C4DOS.Gd->SetBlLink(this, bl);
	}

	//----------------------------------------------------------------------------------------
	/// Creates a data with a custom data type.
	/// @param[in] type								The custom data type ID.
	/// @param[in] data								The custom data.
	//----------------------------------------------------------------------------------------
	GeData(Int32 type, const CustomDataType& data)
	{
		Type	= DA_NIL;
		Ddata	= nullptr;
		C4DOS.Gd->SetCustomData(this, type, data);
	}

	//----------------------------------------------------------------------------------------
	/// Creates a custom data type with the default value for the type.\n
	/// The second parameter is simply a typing trick so that the compiler chooses this constructor:
	/// @code
	/// GeData d(DATETIME_DATA, DEFAULTVALUE);
	/// @endcode
	/// @param[in] type								The custom data type ID.
	/// @param[in] v									The dummy parameter. Should always be @ref DEFAULTVALUE.
	//----------------------------------------------------------------------------------------
	GeData(Int32 type, DEFAULTVALUETYPE v)
	{
		Type	= DA_NIL;
		Ddata	= nullptr;
		C4DOS.Gd->InitCustomData(this, type);
	}

	//----------------------------------------------------------------------------------------
	/// Deletes the internal data and sets the type to @ref DA_NIL.
	//----------------------------------------------------------------------------------------
	void Free(void)
	{
		if (&C4DOS && C4DOS.Gd)
			C4DOS.Gd->Free(this);
	}

	//----------------------------------------------------------------------------------------
	/// Destructor.
	//----------------------------------------------------------------------------------------
	~GeData(void)
	{
		if (&C4DOS && C4DOS.Gd)
			C4DOS.Gd->Free(this);
	}

	/// @}

	/// @name Operator
	/// @{

	//----------------------------------------------------------------------------------------
	/// Assignment operator.
	/// @param[in] n									The data to assign.
	/// @return												The assigned data.
	//----------------------------------------------------------------------------------------
	const GeData& operator = (const GeData& n)
	{
		n.CopyData(this, nullptr);
		return *this;
	}

	//----------------------------------------------------------------------------------------
	/// Equality operator.
	/// @param[in] d									The data to compare with.
	/// @return												@trueIfOtherwiseFalse{the data are equal}
	//----------------------------------------------------------------------------------------
	Bool operator == (const GeData& d) const
	{
		return C4DOS.Gd->IsEqual(this, &d);
	}

	//----------------------------------------------------------------------------------------
	/// Inequality operator.
	/// @param[in] d									The data to compare with.
	/// @return												@trueIfOtherwiseFalse{the data are different}
	//----------------------------------------------------------------------------------------
	Bool operator != (const GeData& d) const
	{
		return !C4DOS.Gd->IsEqual(this, &d);
	}

	/// @}

	/// @name Type
	/// @{

	//----------------------------------------------------------------------------------------
	/// Sets the default value for the data type.
	/// @param[in] type								The type ID: @enumerateEnum{DA}
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool SetDefault(Int32 type)
	{
		return C4DOS.Gd->InitCustomData(this, type);
	}

	//----------------------------------------------------------------------------------------
	/// Retrieves the type of the data.
	/// @return												The data type: @enumerateEnum{DA}
	//----------------------------------------------------------------------------------------
	Int32 GetType(void) const
	{
		return C4DOS.Gd->GetType(this);
	}

	/// @}

	/// @name Get Data
	/// @{

	//----------------------------------------------------------------------------------------
	/// Retrieves the value of ::Bool data objects. Forbidden for other data.
	/// @return												The value. Only valid as long as the GeData value exists.
	//----------------------------------------------------------------------------------------
	Bool GetBool(void) const { return C4DOS.Gd->GetInt32(this) != 0; }

	//----------------------------------------------------------------------------------------
	/// Retrieves the value of ::Int32 data objects. Forbidden for other data.
	/// @return												The value. Only valid as long as the GeData value exists.
	//----------------------------------------------------------------------------------------
	Int32 GetInt32(void) const { return C4DOS.Gd->GetInt32(this); }

	//----------------------------------------------------------------------------------------
	/// Retrieves the value of ::Int64 data objects. Forbidden for other data.
	/// @return												The value. Only valid as long as the GeData value exists.
	//----------------------------------------------------------------------------------------
	Int64 GetInt64(void) const { return C4DOS.Gd->GetInt64(this); }

	//----------------------------------------------------------------------------------------
	/// Retrieves the value of ::Float data objects. Forbidden for other data.
	/// @return												The value. Only valid as long as the GeData value exists.
	//----------------------------------------------------------------------------------------
	Float GetFloat(void) const { return C4DOS.Gd->GetFloat(this); }

	//----------------------------------------------------------------------------------------
	/// Retrieves the value of @c void* data objects. Forbidden for other data.
	/// @return												The value. Only valid as long as the GeData value exists.
	//----------------------------------------------------------------------------------------
	void* GetVoid(void) const { return C4DOS.Gd->GetCustomData(this, DA_VOID); }

	//----------------------------------------------------------------------------------------
	/// Retrieves the value of ::Vector data objects. Forbidden for other data.
	/// @return												The value. Only valid as long as the GeData value exists.
	//----------------------------------------------------------------------------------------
	const Vector& GetVector(void) const { return C4DOS.Gd->GetVector(this); }

	//----------------------------------------------------------------------------------------
	/// Retrieves the value of ::Matrix data objects. Forbidden for other data.
	/// @return												The value. Only valid as long as the GeData value exists.
	//----------------------------------------------------------------------------------------
	const Matrix& GetMatrix(void) const { return C4DOS.Gd->GetMatrix(this); }

	//----------------------------------------------------------------------------------------
	/// Retrieves the value of String data objects. Forbidden for other data.
	/// @return												The value. Only valid as long as the GeData value exists.
	//----------------------------------------------------------------------------------------
	const String& GetString(void) const { return C4DOS.Gd->GetString(this); }

	//----------------------------------------------------------------------------------------
	/// Retrieves the value of C4DUuid data objects. Forbidden for other data.
	/// @return												The value. Only valid as long as the GeData value exists.
	//----------------------------------------------------------------------------------------
	const C4DUuid& GetUuid(void) const { return C4DOS.Gd->GetUuid(this); }

	//----------------------------------------------------------------------------------------
	/// Retrieves the value of Filename data objects. Forbidden for other data.
	/// @return												The value. Only valid as long as the GeData value exists.
	//----------------------------------------------------------------------------------------
	const Filename& GetFilename (void) const { return C4DOS.Gd->GetFilename(this); }

	//----------------------------------------------------------------------------------------
	/// Retrieves the value of BaseTime data objects. Forbidden for other data.
	/// @return												The value. Only valid as long as the GeData value exists.
	//----------------------------------------------------------------------------------------
	const BaseTime& GetTime(void) const { return C4DOS.Gd->GetTime(this); }

	//----------------------------------------------------------------------------------------
	/// Retrieves the value of BaseContainer data objects. Forbidden for other data.
	/// @return												The value. Only valid as long as the GeData value exists.
	//----------------------------------------------------------------------------------------
	BaseContainer* GetContainer(void) const { return C4DOS.Gd->GetContainer(this); }

	//----------------------------------------------------------------------------------------
	/// Retrieves the value of BaseLink data objects. Forbidden for other data.
	/// @return												The value. Only valid as long as the GeData value exists.
	//----------------------------------------------------------------------------------------
	BaseLink* GetBaseLink(void) const { return C4DOS.Gd->GetLink(this); }

	//----------------------------------------------------------------------------------------
	/// Retrieves the value of a CustomDataType, or @formatConstant{nullptr} if the wrong data type was specified. Forbidden for other data types.
	/// @param[in] datatype						The data type ID.
	/// @return												The custom data type value, or @formatConstant{nullptr} if the types do not match. @theOwnsPointed{data,value}\n
	/// 															Only valid as long as the GeData value exists.
	//----------------------------------------------------------------------------------------
	CustomDataType* GetCustomDataType(Int32 datatype) const { return C4DOS.Gd->GetCustomData(this, datatype); }

	//----------------------------------------------------------------------------------------
	/// Evaluates the link of @ref DA_ALIASLINK data objects. Equivalent to GetBaseLink()->@link BaseLink::GetLink GetLink()@endlink.\n
	/// If @formatParam{instanceof} is specified, @formatConstant{nullptr} is returned if the object is not of this type. Forbidden for other data.
	/// @param[in] doc								The document to evaluate the link in. @callerOwnsPointed{document}
	/// @param[in] instanceof					Set this to a node type to only return the link if it is of this type.
	/// @return												The evaluated link. @cinemaOwnsPointed{link}\n
	/// 															Only valid as long as the GeData value exists.
	//----------------------------------------------------------------------------------------
	BaseList2D* GetLink(const BaseDocument* doc, Int32 instanceof = 0) const;

	//----------------------------------------------------------------------------------------
	/// Evaluates the atom link of @ref DA_ALIASLINK data objects. Equivalent to GetBaseLink()->@link BaseLink::GetLinkAtom GetLinkAtom()@endlink.\n
	/// If @formatParam{instanceof} is specified, @formatConstant{nullptr} is returned if the object is not of this type. Forbidden for other data.
	/// @param[in] doc								The document to evaluate the atom link in. @callerOwnsPointed{document}
	/// @param[in] instanceof					Set this to a node type to only return the atom link if it is of this type.
	/// @return												The evaluated atom link. @cinemaOwnsPointed{atom link}\n
	/// 															Only valid as long as the GeData value exists.
	//----------------------------------------------------------------------------------------
	C4DAtomGoal* GetLinkAtom(const BaseDocument* doc, Int32 instanceof = 0) const;

	//----------------------------------------------------------------------------------------
	/// Retrieves the value of memory buffer data objects. Forbidden for other data.\n
	/// @note In this version of GetMemory() the caller takes over the ownership of the memory block.\n
	///				The memory block must be allocated with NewMem() and deallocated with DeleteMem().
	/// @param[in] count							Assigned the number of bytes in the returned memory buffer.
	/// @return												The memory buffer. The caller takes over the ownership of the memory block.\n
	/// 															Only valid as long as the GeData value exists.
	//----------------------------------------------------------------------------------------
	void* GetMemoryAndRelease(Int& count) { return C4DOS.Gd->GetMemoryAndRelease(this, count); }

	//----------------------------------------------------------------------------------------
	/// Retrieves the value of memory buffer data objects. Forbidden for other data.
	/// @note The memory block must be allocated with NewMem() and deallocated with DeleteMem().
	/// @param[in] count							Assigned the number of bytes in the returned memory buffer.
	/// @return												The memory buffer. @theOwnsPointed{data,memory block}\n
	/// 															Only valid as long as the GeData value exists.
	//----------------------------------------------------------------------------------------
	void* GetMemory(Int& count) { return C4DOS.Gd->GetMemory(this, count); }

	/// @}

	/// @name Set Data
	/// @{

	//----------------------------------------------------------------------------------------
	/// Copies the data to another with an alias translator for the links.
	/// @param[in] dest								The destination data. @callerOwnsPointed{data}
	/// @param[in] aliastrans					An alias translator for the operation. Can be @formatConstant{nullptr}. @callerOwnsPointed{alias translator}
	//----------------------------------------------------------------------------------------
	void CopyData(GeData* dest, AliasTrans* aliastrans) const
	{
		C4DOS.Gd->CopyData(dest, this, aliastrans);
	}

	//----------------------------------------------------------------------------------------
	/// Sets the ::Float value and changes the data type accordingly.
	/// @param[in] v									The new value.
	//----------------------------------------------------------------------------------------
	void SetFloat(Float v) { C4DOS.Gd->SetFloat(this, v); }

	//----------------------------------------------------------------------------------------
	/// Sets the ::Int32 value and changes the data type accordingly.
	/// @param[in] v									The new value.
	//----------------------------------------------------------------------------------------
	void SetInt32(Int32 v) { C4DOS.Gd->SetInt32(this, v); }

	//----------------------------------------------------------------------------------------
	/// Sets the ::Int64 value and changes the data type accordingly.
	/// @param[in] v									The new value.
	//----------------------------------------------------------------------------------------
	void SetInt64(const Int64& v) { C4DOS.Gd->SetInt64(this, v); }

	//----------------------------------------------------------------------------------------
	/// Sets the @c void* value and changes the data type accordingly.
	/// @param[in] v									The new value.
	//----------------------------------------------------------------------------------------
	void SetVoid(void* v) { C4DOS.Gd->SetVoid(this, v); }

	//----------------------------------------------------------------------------------------
	/// Sets the memory buffer value and changes the data type accordingly.
	/// @param[in] data								The new memory buffer value.
	/// @param[in] count							The number of bytes in the memory buffer.
	//----------------------------------------------------------------------------------------
	void SetMemory(void* data, Int count) { C4DOS.Gd->SetMemory(this, data, count); }

	//----------------------------------------------------------------------------------------
	/// Sets the ::Vector value and changes the data type accordingly.
	/// @param[in] v									The new value.
	//----------------------------------------------------------------------------------------
	void SetVector(const Vector& v) { C4DOS.Gd->SetVector(this, v); }

	//----------------------------------------------------------------------------------------
	/// Sets the ::Matrix value and changes the data type accordingly.
	/// @param[in] v									The new value.
	//----------------------------------------------------------------------------------------
	void SetMatrix(const Matrix& v) { C4DOS.Gd->SetMatrix(this, v); }

	//----------------------------------------------------------------------------------------
	/// Sets the String value and changes the data type accordingly.
	/// @param[in] v									The new value.
	//----------------------------------------------------------------------------------------
	void SetString(const maxon::String& v) { C4DOS.Gd->SetString(this, v); }

	//----------------------------------------------------------------------------------------
	/// Sets the C4DUuid value and changes the data type accordingly.
	/// @param[in] v									The new value.
	//----------------------------------------------------------------------------------------
	void SetUuid(const C4DUuid& v) { C4DOS.Gd->SetUuid(this, &v); }

	//----------------------------------------------------------------------------------------
	/// Sets data type accordingly (and clears the internal value)
	//----------------------------------------------------------------------------------------
	void SetTristate() { C4DOS.Gd->SetTristate(this); }

	//----------------------------------------------------------------------------------------
	/// Sets the Filename value and changes the data type accordingly.
	/// @param[in] v									The new value.
	//----------------------------------------------------------------------------------------
	void SetFilename(const Filename& v) { C4DOS.Gd->SetFilename(this, &v); }

	//----------------------------------------------------------------------------------------
	/// Sets the BaseTime value and changes the data type accordingly.
	/// @param[in] v									The new value.
	//----------------------------------------------------------------------------------------
	void SetBaseTime(const BaseTime& v) { C4DOS.Gd->SetBaseTime(this, v); }

	//----------------------------------------------------------------------------------------
	/// Sets the BaseContainer value and changes the data type accordingly.
	/// @param[in] v									The new value.
	//----------------------------------------------------------------------------------------
	void SetContainer(const BaseContainer& v) { C4DOS.Gd->SetBaseContainer(this, &v); }

	//----------------------------------------------------------------------------------------
	/// Sets the BaseLink value and changes the data type accordingly.
	/// @param[in] v									The new value.
	//----------------------------------------------------------------------------------------
	void SetBaseLink(const BaseLink& v) { C4DOS.Gd->SetLink(this, v); }

	//----------------------------------------------------------------------------------------
	/// Sets the BaseList2D value and changes the data type accordingly.
	/// @param[in] bl									The new value.
	//----------------------------------------------------------------------------------------
	void SetBaseList2D(BaseList2D* bl) { C4DOS.Gd->SetBlLink(this, bl); }

	//----------------------------------------------------------------------------------------
	/// Sets the value for custom data type and changes the data type accordingly.
	/// @param[in] datatype						The custom data type ID.
	/// @param[in] v									The new custom data type value.
	//----------------------------------------------------------------------------------------
	void SetCustomDataType(Int32 datatype, const CustomDataType& v) { C4DOS.Gd->SetCustomData(this, datatype, v); }

	/// @}
};

//----------------------------------------------------------------------------------------
/// A convenience class for browsing through the items in a BaseContainer.
/// @warning It is not allowed to add or remove elements while browsing the container.
//----------------------------------------------------------------------------------------
class BrowseContainer
{
private:
	BaseContainer* t_bc;
	void* handle;

public:
	//----------------------------------------------------------------------------------------
	/// Constructs the browser with the passed container.
	/// @param[in] bc									The container to browse. @callerOwnsPointed{container}
	//----------------------------------------------------------------------------------------
	BrowseContainer(const BaseContainer* bc);

	//----------------------------------------------------------------------------------------
	/// Resets the browser to the construction state.
	//----------------------------------------------------------------------------------------
	void Reset(void);

	//----------------------------------------------------------------------------------------
	/// Retrieves the next item in the container.
	/// @warning It is not allowed to modify the retrieved @formatParam{data}.
	/// @param[out] id								Assigned the ID of the item.
	/// @param[out] data							Assigned the item's data. @theOwnsPointed{container,data}
	/// @return												@trueIfOtherwiseFalse{the next item was retrieved}
	//----------------------------------------------------------------------------------------
	Bool GetNext(Int32* id, GeData** data);
};

#endif // C4D_GEDATA_H__
