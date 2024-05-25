/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

// Base Effector class
#ifndef C4D_BASEEFFECTORDATA_H__
#define C4D_BASEEFFECTORDATA_H__

#ifdef __API_INTERN__
	#error "Not in the kernel"
#endif

#include "lib_description.h"
#include "c4d_thread.h"
#include "c4d_objectdata.h"
#include "c4d_basedocument.h"
#include "c4d_baseobject.h"

#ifdef CINEWARE_NAMESPACE_ENABLE
	CINEWARE_NAMESPACE_BEGIN
#endif

/// @addtogroup group_effector_id Effector ID
/// @ingroup group_enumeration
/// @{
#define Obaseeffector			1018560			///< Base effector object ID.
#define Obasemogen				1018639			///< Base mogen object ID.
#define ID_BASE_EDEFORMER	1019305			///< Base effector deformer ID.
#define ID_MOTAGDATA			1018625			///< ID of the tag containing the MoData on a MoGraph object.
#define ID_MOBAKETAG			1019337			///< MoGraph bake tag ID.
#define Tmgselection			1021338			///< MoGraph selection tag ID.
#define Tmgweight					440000231		///< MoGraph weights tag ID. @since R18
/// @}

/// @addtogroup group_effector_libid Effector Library ID
/// @ingroup group_enumeration
/// @{
#define BASEEFFECTORLIB_ID	1019554				///< Base effector library ID.
#define MODATALIB_ID				440000059			///< MoGraph data library ID.
/// @}

/// @addtogroup group_msg_effector MSG Effector
/// @ingroup group_enumeration
/// @{
#define MSG_EXECUTE_EFFECTOR			1018630			///< Sent to execute the effector. The corresponding data is Effector_PassData.
#define MSG_SAMPLE_EFFECTOR_VALUE	1019294			///< Sent to sample the effector's strength for any particular point in space. The corresponding data is Effector_PassValueData.
#define MSG_GET_MODATA						1019522			///< Sent to get the MoData. Sent to the MoData tag (ID is @ref ID_MOTAGDATA) of the MoGraph object to get the MoData for. The corresponding data is GetMoDataMessage.
#define MSG_GET_MODATASELECTION		1021339			///< Send to retrieve the data of MoGraph selection tags. The corresponding data is GetMGSelectionMessage.
#define MSG_GET_MODATAWEIGHTS			440000230		///< Send to retrieve the weights of MoGraph weights tags. The corresponding data is GetMGWeightMessage. @since R18
#define BC_ID_MODATAINDEX					440000062		///< The index of the clone corresponding to its MoData particle index.
#define BC_ID_MODATATAGINDEX			440000063		///< The MoData tag index. Set in the clones container.
#define BC_ID_CLONE_DATA_ARRAY		1019427			///< maxon::Data(maxon::BaseArray<MultiInstanceEntry>). 1 mograph entry per instance. used by Multi-instance and cloner
#define BC_ID_COLOR_MODE					440000075		///< Color mode.

// ids for the color shader tag
struct MultiInstanceEntry
{
	MultiInstanceEntry(const Vector& color, const Vector& indexRatio, Int32 instIndex)
		: _color(color),
			_indexRatio(indexRatio),
			_instIndex(instIndex)
	{
	}
	MultiInstanceEntry(const maxon::Color64& color, const Vector& indexRatio, Int32 instIndex)
		: _color(Vector(color)),
			_indexRatio(indexRatio),
			_instIndex(instIndex)
	{
	}
	
public:
	Vector _color;
	Vector _indexRatio;
	Int32	 _instIndex = NOTOK;

	MAXON_STRUCT_TUPLE(MultiInstanceEntry, _color, _indexRatio, _instIndex);
};

inline const MultiInstanceEntry* GetMographMultiEntry(const BaseContainer& motagBC, Int index)
{
	const GeData* allCloneInstanceBC = motagBC.GetDataPointer(BC_ID_CLONE_DATA_ARRAY);
	if (!allCloneInstanceBC)
		return nullptr;
	iferr (maxon::Array<MultiInstanceEntry> cloneBC = allCloneInstanceBC->GetData().Get<maxon::Array<MultiInstanceEntry>>())
		return nullptr;
	if ((UInt)index >= (UInt)cloneBC.GetCount())
		return nullptr;
	return &cloneBC[index];
}

inline const MultiInstanceEntry* GetMographMultiEntry(const BaseContainer* motagBC, Int index)
{
	if (!motagBC)
		return nullptr;
	return GetMographMultiEntry(*motagBC, index);
}


#define MSG_DISABLE_DELAY_EFFECTOR	440000146			///< @markPrivate
#define MSG_ENABLE_DELAY_EFFECTOR		440000147			///< @markPrivate
#define MSG_MOGRAPH_REEVALUATE			440000197			///< @markPrivate
/// @}

#define BLEND_COUNT 21 ///< The number of values that a value driven effector has to calculate; normally hard coded (do not change).

/// @addtogroup EFFECTORFLAGS
/// @ingroup group_enumeration
/// @{
/// Effector flags.
/// @see EffectorData::GetEffectorFlags()
#define EFFECTORFLAGS_HASFALLOFF			(1 << 0)			///< A falloff control panel will be added to the effector and a falloff will be available to sample.
#define EFFECTORFLAGS_TIMEDEPENDENT		(1 << 1)			///< The effector will be forced to update with changes to the time.
#define EFFECTORFLAGS_CAMERADEPENDENT	(1 << 2)			///< The effector will always be dirty and forced to update.
/// @}

/// @addtogroup MOGENFLAG
/// @ingroup group_enumeration
/// @{
/// MoData flags.
/// @see MODATA_FLAGS
#define MOGENFLAG_CLONE_ON	(1 << 0)			///< Particle is visible.
#define MOGENFLAG_DISABLE		(1 << 1)			///< Particle is permanently disabled.
#define MOGENFLAG_BORN			(1 << 2)			///< Particle is just generated. @markInternal
#define MOGENFLAG_MODATASET	(1 << 3)			///< The MoData has been set and does not need the input of the transform panel.
#define MOGENFLAG_COLORSET	(1 << 4)			///< The MoData color has been set and does not need to be updated.
#define MOGENFLAG_TIMESET		(1 << 5)			///< The MoData time has been set and does not need to be updated.
/// @}

/// @addtogroup MDDIRTY
/// @ingroup group_enumeration
/// @{
/// MoData dirty flags.
enum class MDDIRTY
{
	NONE				= 0,
	ALL					= ~0,
	ARRAYCOUNT	= (1 << 0),			///< Array count itself changed (number of different arrays rather than length of arrays).
	COUNT				= (1 << 1),			///< Length of the arrays changed.
	DATA				= (1 << 2)			///< Data in the arrays changed, must be manually set.
} MAXON_ENUM_FLAGS(MDDIRTY);
/// @}

class C4D_Falloff;

/// @addtogroup MD_TYPE
/// @ingroup group_enumeration
/// @{
enum class MD_TYPE
{
	MD_NONE		= DA_NIL,						///< None.
	MD_CHAR		= 40000000,					///< ::Char type.
	MD_UCHAR	= 40000001,					///< ::UChar type.
	MD_LONG		= DTYPE_LONG,				///< ::Int32 type.
	MD_ULONG	= 40000002,					///< ::UInt32 type.
	MD_LLONG	= DA_LLONG,					///< ::Int64 type.
	MD_MATRIX	= DA_MATRIX,				///< ::Matrix type.
	MD_COLOR	= DTYPE_COLOR,			///< Color type (::Vector).
	MD_VECTOR	= DTYPE_VECTOR,			///< ::Vector type.
	MD_NORMAL	= DTYPE_NORMAL,			///< Normal type (::Vector).
	MD_REAL		= DTYPE_REAL,				///< ::Float type.
	MD_BOOL		= DTYPE_BOOL				///< ::Bool type.
} MAXON_ENUM_LIST(MD_TYPE);
/// @}

/// @addtogroup MODATA_IDS
/// @ingroup group_enumeration
/// @{
/// MoData arrays ID.
enum
{
	MODATA_MATRIX = 40000000,			///< ::Matrix. Matrix of the clone.
	MODATA_COLOR,									///< ::Vector. Color of the clone.
	MODATA_SIZE,									///< ::Vector. Size of the clone.
	MODATA_UVW,										///< ::Vector. UV position of the clone.
	MODATA_FLAGS,									///< ::Int32. MoData flags: @enumerateEnum{MOGENFLAG}
	MODATA_WEIGHT,								///< ::Float. Weight of the clone.
	MODATA_CLONE,									///< ::Float. Clone offset (picks which child of the Cloner gets cloned or the blending between those children).
	MODATA_TIME,									///< ::Float. Time offset of the clone.
	MODATA_LASTMAT,								///< ::Matrix. Previous frame particle matrix.
	MODATA_STARTMAT,							///< ::Matrix. Matrix at the particle's birth.
	MODATA_ALT_INDEX,							///< ::Int32. Alternative index value that can be used for instance by the Step Effector when cloned over a spline with an offset.
	MODATA_FALLOFF_WGT,						///< ::Float. Falloff weight.
	MODATA_GROWTH									///< ::Float. Offset of growth for the particle on the MoSpline (currently unused).
};
/// @}


//----------------------------------------------------------------------------------------
/// Retrieves the default value for the specified MoData array @formatParam{id}.
/// @param[in] id									The MoData array ID: @enumerateEnum{MODATA_IDS}
/// @return												The MoData default value.
//----------------------------------------------------------------------------------------
inline Vector GetMoDataDefaultVector(Int32 id, const Vector& default_value = Vector(0.0))
{
	switch (id)
	{
		case MODATA_COLOR: return Vector(0.5);
		case MODATA_SIZE: return Vector(1.0);
		case MODATA_UVW: return Vector(0.0);
	}

	return default_value;
}

inline Matrix GetMoDataDefaultMatrix(Int32 id, const Matrix& default_value = Matrix())
{
	return default_value;
}

inline Float GetMoDataDefaultFloat(Int32 id, Float default_value = 0.0)
{
	switch (id)
	{
		case MODATA_WEIGHT:
		case MODATA_CLONE:
		case MODATA_TIME: 
			return 0.0;

		case MODATA_FALLOFF_WGT:
		case MODATA_GROWTH:
			return 1.0;
	}

	return default_value;
}

inline Int32 GetMoDataDefaultInt32(Int32 id, Int32 default_value = 0)
{
	switch (id)
	{
		case MODATA_FLAGS: 
			return MOGENFLAG_CLONE_ON | MOGENFLAG_BORN;

		case MODATA_ALT_INDEX: 
			return NOTOK;
	}

	return default_value;
}

inline Int64 GetMoDataDefaultInt64(Int32 id, Int64 default_value = 0)
{
	return default_value;
}

inline GeData GetMoDataDefault(Int32 id)
{
	switch (id)
	{
		case MODATA_LASTMAT:
		case MODATA_STARTMAT:
		
		case MODATA_MATRIX: 
			return GeData(GetMoDataDefaultMatrix(id));

		case MODATA_COLOR: 
		case MODATA_SIZE:
		case MODATA_UVW:
			return GeData(GetMoDataDefaultVector(id));

		case MODATA_FLAGS: 
		case MODATA_ALT_INDEX:
			return GeData(GetMoDataDefaultInt32(id));

		case MODATA_WEIGHT:
		case MODATA_CLONE:
		case MODATA_TIME: 
		case MODATA_FALLOFF_WGT:
		case MODATA_GROWTH:
			return GeData(GetMoDataDefaultFloat(id));
	}

	return GeData();
}

//----------------------------------------------------------------------------------------
/// Retrieves the default type for the specified MoData array @formatParam{id}.
/// @param[in] id									The MoData array ID: @enumerateEnum{MODATA_IDS}
/// @return												The default type: @enumerateEnum{MD_TYPE}
//----------------------------------------------------------------------------------------
inline MD_TYPE GetMoDataDefaultType(Int32 id)
{
	switch (id)
	{
		case MODATA_LASTMAT:
		case MODATA_STARTMAT:
		case MODATA_MATRIX: 
			return MD_TYPE::MD_MATRIX;

		case MODATA_COLOR: 
			return MD_TYPE::MD_COLOR;

		case MODATA_SIZE:
		case MODATA_UVW: 
			return MD_TYPE::MD_VECTOR;

		case MODATA_ALT_INDEX:
		case MODATA_FLAGS: 
			return MD_TYPE::MD_LONG;

		case MODATA_WEIGHT:
		case MODATA_CLONE:
		case MODATA_FALLOFF_WGT:
		case MODATA_GROWTH:
		case MODATA_TIME: 
			return MD_TYPE::MD_REAL;
	}

	return MD_TYPE::MD_NONE;
};

/// @addtogroup MDARRAYFLAG
/// @ingroup group_enumeration
/// @{
#define MDARRAYFLAG_NOTSEENBYEFFECTOR		(1 << 0)			///< Data is not seen and modified by the effector.
#define MDARRAYFLAG_SEPERATECOMPONENTS	(1 << 1)			///< Vector should have separate components in effector (e.g. UV).
#define MDARRAYFLAG_2DVECTOR						(1 << 2)			///< Vector is a @em 2D vector rather than @em 3D (e.g. UV).
/// @}

/// @addtogroup ID_MODATA_PASS
/// @ingroup group_enumeration
/// @{
enum
{
/// This is used to allow the delay effector to work with the MoGraph extrude deformer, each level of extrusion gets a pass index which is set in the MoData's own container (MoData::GetDataInstance()):
/// @code
/// Int32 pass = md->GetDataInstanceRef().GetInt32(ID_MODATA_PASS, 0);
/// @endcode
/// By doing this the delay effector can differentiate the levels and create a reasonable effect.\n
/// The idea is simply that there can be multiple passes through the effectors within a single execution.\n
/// And if @ref ID_MODATA_PASS is set to a pass number then the delay effector (and anything else that wants to use it) should work.
	ID_MODATA_PASS = 100
};
/// @}


//----------------------------------------------------------------------------------------
/// Motion particle transformation data.
//----------------------------------------------------------------------------------------
struct Dpoint
{
	Matrix m; ///< Particle raw matrix.

	//----------------------------------------------------------------------------------------
	/// Gets the particle position.
	/// @return												The particle position.
	//----------------------------------------------------------------------------------------
	inline Vector GetPos() const
	{
		return m.off;
	}

	//----------------------------------------------------------------------------------------
	/// Gets the particle size.
	/// @return												The particle size.
	//----------------------------------------------------------------------------------------
	inline Vector GetSize() const
	{
		return m.sqmat.GetScale();
	}

	//----------------------------------------------------------------------------------------
	/// Gets the particle matrix.
	/// @param[out] h									Assigned the particle matrix.
	/// @param[out] size							Assigned the particle size.
	//----------------------------------------------------------------------------------------
	inline void GetMatrix(Matrix& h, const Vector& size) const
	{
		h = m;
		h.sqmat.v1 -= h.off;
		h.sqmat.v2 -= h.off;
		h.sqmat.v3 -= h.off;
		h.sqmat.v1	= !Cross(h.sqmat.v2, h.sqmat.v3) * size.x;
		h.sqmat.v2	= !Cross(h.sqmat.v3, h.sqmat.v1) * size.y;
		h.sqmat.v3	= !Cross(h.sqmat.v1, h.sqmat.v2) * size.z;
	}
};


//----------------------------------------------------------------------------------------
/// Struct that holds the information for each particle.
//----------------------------------------------------------------------------------------
struct Ipoint
{
public:
	//----------------------------------------------------------------------------------------
	/// Default constructor.
	//----------------------------------------------------------------------------------------
	Ipoint()
	{
		flags = MOGENFLAG_CLONE_ON | MOGENFLAG_BORN;
		color = Vector(0.5);
		size = Vector(1.0);
		weight = 0.0;
		clone = 1.0;
		uvw = Vector(0.0);
		time = 0.0;
		alt_index = NOTOK;
	}

	//----------------------------------------------------------------------------------------
	/// Destructor.
	//----------------------------------------------------------------------------------------
	~Ipoint()
	{
	}

	Vector color;			///< Color of the particle.
	Vector size;			///< Size of the particle.
	Vector uvw;				///< Particle direct UVW position.
	Int32 flags;			///< Particle flags: @enumerateEnum{MOGENFLAG}
	Float weight;			///< Offset against falloff value to allow effectors to drive other effectors.
	Float clone;			///< Index of the child that will be cloned in the cloner object.
	Float time;				///< Delta time for each clone.
	Matrix lastmat;		///< Last position.
	Matrix startmat;	///< Starting position.
	Int32 alt_index;	///< Alternative index for particles, instances etc. with some effectors, e.g. step.
};


//----------------------------------------------------------------------------------------
/// Template array class used for arrays filled by MoData.
//----------------------------------------------------------------------------------------
template <class TYPE> class MDArray
{
private:
	TYPE* ptr;
	mutable TYPE dv;
	Int count;

public:
	//----------------------------------------------------------------------------------------
	/// Default constructor.
	//----------------------------------------------------------------------------------------
	MDArray() { ptr = nullptr; dv = TYPE(); count = 0; }

	//----------------------------------------------------------------------------------------
	/// Constructor with the array pointer and the default value.
	/// @param[in] array_pointer			The array pointer.
	/// @param[in] array_count				The number of elements in @formatParam{array_pointer}.
	/// @param[in] default_value			The default value.
	//----------------------------------------------------------------------------------------
	MDArray(TYPE* array_pointer, Int32 array_count, TYPE default_value/*= TYPE()*/)
	{
		ptr = array_pointer;
		dv = default_value;
		count = array_count;
	}

	//----------------------------------------------------------------------------------------
	/// Default destructor.
	//----------------------------------------------------------------------------------------
	~MDArray() { }

	//----------------------------------------------------------------------------------------
	/// Fills the elements of the array with @formatParam{default_value}.
	/// @param[in] default_value			The value to fill with.
	//----------------------------------------------------------------------------------------
	void Fill(const TYPE& default_value)
	{
		if (ptr && count)
		{
			Int i = 0;
			for (i = count - 1; i >= 0; --i)
				ptr[i] = default_value;
		}
		dv = default_value;
	}

	//----------------------------------------------------------------------------------------
	/// Conversion operator.
	//----------------------------------------------------------------------------------------
	operator TYPE* ()
	{
		return ptr;
	}
	operator const TYPE* () const
	{
		return ptr;
	}

	//----------------------------------------------------------------------------------------
	/// Gets the array pointer.
	/// @return												The array pointer.
	//----------------------------------------------------------------------------------------
	TYPE* GetPointer() { return ptr; }

	//----------------------------------------------------------------------------------------
	/// Gets the const array pointer.
	/// @return												The array pointer.
	//----------------------------------------------------------------------------------------
	const TYPE* GetPointer() const { return ptr; }

	//----------------------------------------------------------------------------------------
	/// Checks if the array contains any elements.
	/// @return												@trueIfOtherwiseFalse{the array is empty}
	//----------------------------------------------------------------------------------------
	Bool operator!() const { return ptr == nullptr; }

	//----------------------------------------------------------------------------------------
	/// Array access operator.
	/// @param[in] i									The element index in the array.
	/// @return												The element reference at @formatParam{i} in the array.
	//----------------------------------------------------------------------------------------
	TYPE& operator[] (Int32 i) { DebugAssert(!ptr || (i >= 0 && i < count)); return (!ptr || i < 0 || i >= count) ? dv : ptr[i]; }

	//----------------------------------------------------------------------------------------
	/// Const array access operator.
	/// @param[in] i									The element index in the array.
	/// @return												The element reference at @formatParam{i} in the array.
	//----------------------------------------------------------------------------------------
	const TYPE& operator[] (Int32 i) const { return (const_cast<MDArray<TYPE>&>(*this))[i]; }

	//----------------------------------------------------------------------------------------
	/// Array access operator.
	/// @param[in] i									The element index in the array.
	/// @return												The element reference at @formatParam{i} in the array.
	//----------------------------------------------------------------------------------------
	TYPE& operator[] (Int64 i) { DebugAssert(!ptr || (i >= 0 && i < count)); return (!ptr || i < 0 || i >= count) ? dv : ptr[i]; }

	//----------------------------------------------------------------------------------------
	/// Const array access operator.
	/// @param[in] i									The element index in the array.
	/// @return												The element reference at @formatParam{i} in the array.
	//----------------------------------------------------------------------------------------
	const TYPE& operator[] (Int64 i) const { return (const_cast<MDArray<TYPE>&>(*this))[i]; }
};

struct MoDataEx;


//----------------------------------------------------------------------------------------
/// Class for handling MoGraph motion data.
//----------------------------------------------------------------------------------------
class MoData
{
private:
	MoData();
	~MoData();

	MoData& operator = (const MoData& d);
	MoData* operator = (MoData* d);

public:

	/// @name Alloc/Free
	/// @{

	//----------------------------------------------------------------------------------------
	/// @allocatesA{motion data}
	/// @return												@allocReturn{motion data}
	//----------------------------------------------------------------------------------------
	static MoData* Alloc();

	//----------------------------------------------------------------------------------------
	/// @destructsAlloc{motion data}
	/// @param[in,out] d							@theToDestruct{motion data}
	//----------------------------------------------------------------------------------------
	static void Free(MoData*& d);

	/// @}

	/// @name Dirty
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets the dirty count. Can be used to check if something has changed.
	/// @param[in] mask								The dirty flag mask. Can be a combination of: @enumerateEnum{DIRTYFLAGS}
	/// @return												The dirty count.
	//----------------------------------------------------------------------------------------
	UInt32 GetDirty(MDDIRTY mask = MDDIRTY::NONE) const;

	//----------------------------------------------------------------------------------------
	/// Marks the data as dirty.
	/// @param[in] mask								The dirty flag mask. Can be a combination of: @enumerateEnum{DIRTYFLAGS}
	//----------------------------------------------------------------------------------------
	void SetDirty(MDDIRTY mask = MDDIRTY::NONE);

	/// @}

	//----------------------------------------------------------------------------------------
	/// Initializes the data with MoDataEx.
	/// @param[in] md									The data to use for initializing.
	/// @return												@trueIfOtherwiseFalse{motion data was successfully initialized}
	//----------------------------------------------------------------------------------------
	Bool SetWithEx(const MoDataEx& md);

	//----------------------------------------------------------------------------------------
	/// Clears the data in the arrays.
	/// @param[in] reset							If @formatConstant{true}, the arrays will be filled with their default values.
	//----------------------------------------------------------------------------------------
	void Clear(Bool reset);

	/// @name Read/Write
	/// @{

	//----------------------------------------------------------------------------------------
	/// Reads the data from a hyper file.
	/// @param[in] hf									The hyper file to read from. @callerOwnsPointed{hyper file}
	/// @return												@trueIfOtherwiseFalse{the data was read}
	//----------------------------------------------------------------------------------------
	Bool Read(HyperFile* hf);

	//----------------------------------------------------------------------------------------
	/// Writes the data to a hyper file.
	/// @param[in] hf									The hyper file to write to. @callerOwnsPointed{hyper file}
	/// @return												@trueIfOtherwiseFalse{the data was written}
	//----------------------------------------------------------------------------------------
	Bool Write(HyperFile* hf) const;

	/// @}

	//----------------------------------------------------------------------------------------
	/// Gets the size of the data in bytes.
	/// @return												The size of the data.
	//----------------------------------------------------------------------------------------
	Int GetMemorySize() const;

	/// @name Arrays Length & Number
	/// @{

	//----------------------------------------------------------------------------------------
	/// Sets the length of the arrays.
	/// @param[in] cnt								The new length of the arrays.
	/// @return												@trueIfOtherwiseFalse{the length was set}
	//----------------------------------------------------------------------------------------
	Bool SetCount(Int cnt);

	//----------------------------------------------------------------------------------------
	/// Gets the length of the arrays.
	/// @return												The length of the arrays.
	//----------------------------------------------------------------------------------------
	Int GetCount() const;

	//----------------------------------------------------------------------------------------
	/// Gets the number of arrays.
	/// @return												The number of arrays.
	//----------------------------------------------------------------------------------------
	Int32 GetArrayCount() const;

	/// @}

	/// @name Array Information
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets the description ID for the specified array @formatParam{index}.
	/// @param[in] index							The array index. @em 0 <= @formatParam{index} < GetArrayCount()
	/// @return												The description ID.
	//----------------------------------------------------------------------------------------
	DescID GetArrayDescID(Int32 index) const;

	//----------------------------------------------------------------------------------------
	/// Gets the ID for the specified array @formatParam{index}.
	/// @param[in] index							The array index. @em 0 <= @formatParam{index} < GetArrayCount()
	/// @return												The array ID: @enumerateEnum{MODATA_IDS}
	//----------------------------------------------------------------------------------------
	Int32 GetArrayID(Int32 index) const;

	//----------------------------------------------------------------------------------------
	/// Gets the data type of the specified array @formatParam{index}.
	/// @param[in] index							The array index. @em 0 <= @formatParam{index} < GetArrayCount()
	/// @return												The data type: @link DTYPE_NONE DTYPE@endlink
	//----------------------------------------------------------------------------------------
	Int32 GetArrayIndexType(Int32 index);

	//----------------------------------------------------------------------------------------
	/// Gets the data type of the specified array @formatParam{id}.
	/// @param[in] id									The array ID: @enumerateEnum{MODATA_IDS}
	/// @return												The type: @link DTYPE_NONE DTYPE@endlink
	//----------------------------------------------------------------------------------------
	Int32 GetArrayType(Int32 id);

	//----------------------------------------------------------------------------------------
	/// Gets the array index for the specified description @formatParam{id}.
	/// @param[in] id									The description ID.
	/// @return												The array index.
	//----------------------------------------------------------------------------------------
	Int GetArrayIndex(const DescID& id);

	//----------------------------------------------------------------------------------------
	/// Gets the array index for the specified array @formatParam{id}.
	/// @param[in] id									The array ID: @enumerateEnum{MODATA_IDS}
	/// @return												The array index.
	//----------------------------------------------------------------------------------------
	Int GetArrayIndex(Int32 id);

	/// @}

	/// @name Get/Set Data Container
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets a pointer to the container for the specified array description @formatParam{id}.
	/// @param[in] id									The description ID.
	/// @return												A pointer to the internal container. @theOwnsPointed{motion data object, container}
	//----------------------------------------------------------------------------------------
	BaseContainer* GetDataInstance(const DescID& id);

	//----------------------------------------------------------------------------------------
	/// Gets a pointer to the container for the specified array @formatParam{id}.
	/// @param[in] id									The array ID: @enumerateEnum{MODATA_IDS}
	/// @return												A pointer to the internal container. @theOwnsPointed{motion data object, container}
	//----------------------------------------------------------------------------------------
	BaseContainer* GetDataInstance(Int32 id = NOTOK);

	//----------------------------------------------------------------------------------------
	/// Gets a pointer to the container for the specified array @formatParam{index}.
	/// @param[in] index							The array index. @em 0 <= @formatParam{index} < GetArrayCount()
	/// @return												A pointer to the internal container. @theOwnsPointed{motion data object, container}
	//----------------------------------------------------------------------------------------
	BaseContainer* GetDataIndexInstance(Int32 index);

	//----------------------------------------------------------------------------------------
	/// Gets a copy of the container for the specified array @formatParam{id}.
	/// @param[in] id									The array ID: @enumerateEnum{MODATA_IDS}
	/// @return												A copy of the array's container.
	//----------------------------------------------------------------------------------------
	BaseContainer GetData(Int32 id = NOTOK);

	//----------------------------------------------------------------------------------------
	/// Sets the the container for the specified array @formatParam{id}.
	/// @param[in] bc									The container to set.
	/// @param[in] id									The array ID: @enumerateEnum{MODATA_IDS}
	//----------------------------------------------------------------------------------------
	void SetData(const BaseContainer& bc, Int32 id = NOTOK);

	/// @}

	//----------------------------------------------------------------------------------------
	/// Must be used to lock the class with AutoLocker prior to accessing the MoData values directly to prevent threading issues and therefore crashes.
	/// @code AutoLocker al(modata.GetAutoLock()); @endcode
	/// @return												The AutoLock used for locking the class.
	//----------------------------------------------------------------------------------------
	AutoLock& GetAutoLock();

	/// @name Add/Remove Array
	/// @{

	//----------------------------------------------------------------------------------------
	/// Adds the specified array.
	/// @param[in] id									The description ID of the array.
	/// @param[in] name								The name of the array.
	/// @param[in] default_flags			The default flags: @enumerateEnum{MOGENFLAG}
	/// @return												The index of the added array or @ref NOTOK if the method failed.
	//----------------------------------------------------------------------------------------
	Int32 AddArray(const DescID& id, const maxon::String& name = maxon::String(), Int32 default_flags = 0);

	//----------------------------------------------------------------------------------------
	/// Adds the specified array.
	/// @param[in] id									The array ID: @enumerateEnum{MODATA_IDS}
	/// @param[in] type								The type: @link DTYPE_NONE DTYPE@endlink
	/// @param[in] name								The name of the array.
	/// @param[in] default_flags			The default flags: @enumerateEnum{MOGENFLAG}
	/// @return												The index of the added array or @ref NOTOK if the method failed.
	//----------------------------------------------------------------------------------------
	Int32 AddArray(Int32 id, Int32 type, const maxon::String& name = maxon::String(), Int32 default_flags = 0);

	//----------------------------------------------------------------------------------------
	/// Removes the specified array.
	/// @param[in] id									The description ID of the array.
	/// @return												@trueIfOtherwiseFalse{the array was removed}
	//----------------------------------------------------------------------------------------
	Bool RemoveArray(const DescID& id);

	//----------------------------------------------------------------------------------------
	/// Removes the specified array.
	/// @param[in] id									The array ID: @enumerateEnum{MODATA_IDS}
	/// @return												@trueIfOtherwiseFalse{the array was removed}
	//----------------------------------------------------------------------------------------
	Bool RemoveArray(Int32 id);

	/// @}

	/// @name Array Flags
	/// @{

	//----------------------------------------------------------------------------------------
	/// @markUnused
	//----------------------------------------------------------------------------------------
	Int32 GetFlags(const DescID& id);

	//----------------------------------------------------------------------------------------
	/// @markUnused
	//----------------------------------------------------------------------------------------
	Int32 GetFlags(Int32 id);

	//----------------------------------------------------------------------------------------
	/// @markUnused
	//----------------------------------------------------------------------------------------
	Int32 GetIndexFlags(Int32 index);

	//----------------------------------------------------------------------------------------
	/// @markUnused
	//----------------------------------------------------------------------------------------
	void SetFlags(const DescID& id, Int32 flags);

	//----------------------------------------------------------------------------------------
	/// @markUnused
	//----------------------------------------------------------------------------------------
	void SetFlags(Int32 id, Int32 flags);

	//----------------------------------------------------------------------------------------
	/// @markUnused
	//----------------------------------------------------------------------------------------
	void SetIndexFlags(Int32 index, Int32 flags);

	//----------------------------------------------------------------------------------------
	/// @markUnused
	//----------------------------------------------------------------------------------------
	void SetFlag(const DescID& id, Int32 flag);

	//----------------------------------------------------------------------------------------
	/// @markUnused
	//----------------------------------------------------------------------------------------
	void SetFlag(Int32 id, Int32 flag);

	//----------------------------------------------------------------------------------------
	/// @markUnused
	//----------------------------------------------------------------------------------------
	void SetIndexFlag(Int32 index, Int32 flag);

	//----------------------------------------------------------------------------------------
	/// @markUnused
	//----------------------------------------------------------------------------------------
	void DelFlag(const DescID& id, Int32 flag);

	//----------------------------------------------------------------------------------------
	/// @markUnused
	//----------------------------------------------------------------------------------------
	void DelFlag(Int32 id, Int32 flag);

	//----------------------------------------------------------------------------------------
	/// @markUnused
	//----------------------------------------------------------------------------------------
	void DelIndexFlag(Int32 index, Int32 flag);

	/// @}

	/// @name Array name
	/// @{

	//----------------------------------------------------------------------------------------
	/// Sets the name for the specified array description @formatParam{id}.
	/// @param[in] id									The description ID of the array.
	/// @param[in] name								The name of the array to set.
	//----------------------------------------------------------------------------------------
	void SetName(const DescID& id, const maxon::String& name);

	//----------------------------------------------------------------------------------------
	/// Sets the name for the specified array @formatParam{id}.
	/// @param[in] id									The array ID: @enumerateEnum{MODATA_IDS}
	/// @param[in] name								The name of the array to set.
	//----------------------------------------------------------------------------------------
	void SetName(Int32 id, const maxon::String& name);

	//----------------------------------------------------------------------------------------
	/// Sets the name for the specified array @formatParam{index}.
	/// @param[in] index							The array index. @em 0 <= @formatParam{index} < GetArrayCount()
	/// @param[in] name								The name of the array to set.
	//----------------------------------------------------------------------------------------
	void SetIndexName(Int32 index, const maxon::String& name);

	//----------------------------------------------------------------------------------------
	/// Gets the name of the specified array description @formatParam{id}.
	/// @param[in] id									The description ID of the array.
	/// @return												The name of the array.
	//----------------------------------------------------------------------------------------
	String GetName(const DescID& id);

	//----------------------------------------------------------------------------------------
	/// Gets the name of the specified array @formatParam{id}.
	/// @param[in] id									The array ID: @enumerateEnum{MODATA_IDS}
	/// @return												The name of the array.
	//----------------------------------------------------------------------------------------
	String GetName(Int32 id);

	//----------------------------------------------------------------------------------------
	/// Gets the name of the specified array @formatParam{index}.
	/// @param[in] index							The array index. @em 0 <= @formatParam{index} < GetArrayCount()
	/// @return												The name of the array.
	//----------------------------------------------------------------------------------------
	String GetIndexName(Int32 index);

	/// @}

	/// @name Get Array By DescID
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets a void pointer to an array.
	/// @param[in] id									The description ID of the array.
	/// @return												The pointer to the array.
	//----------------------------------------------------------------------------------------
	void* GetArray(const DescID& id) const;

	//----------------------------------------------------------------------------------------
	/// Gets a ::Char array.
	/// @param[in] id									The description ID of the array.
	/// @param[in] default_value			The default value of the array.
	/// @return												The retrieved array.
	//----------------------------------------------------------------------------------------
	MDArray<Char> GetCharArray(const DescID& id, Char default_value = 0) const;

	//----------------------------------------------------------------------------------------
	/// Gets a ::UChar array.
	/// @param[in] id									The description ID of the array.
	/// @param[in] default_value			The default value of the array.
	/// @return												The retrieved array.
	//----------------------------------------------------------------------------------------
	MDArray<UChar> GetUCharArray(const DescID& id, UChar default_value = 0) const;

	//----------------------------------------------------------------------------------------
	/// Gets an ::Int32/@c Long array.
	/// @param[in] id									The description ID of the array.
	/// @param[in] default_value			The default value of the array.
	/// @return												The retrieved array.
	//----------------------------------------------------------------------------------------
	MDArray<Int32> GetLongArray(const DescID& id, Int32 default_value = 0) const;

	//----------------------------------------------------------------------------------------
	/// Gets a ::UInt32/@c ULong array.
	/// @param[in] id									The description ID of the array.
	/// @param[in] default_value			The default value of the array.
	/// @return												The retrieved array.
	//----------------------------------------------------------------------------------------
	MDArray<UInt32> GetULongArray(const DescID& id, UInt32 default_value = 0) const;

	//----------------------------------------------------------------------------------------
	/// Gets a ::Bool array.
	/// @param[in] id									The description ID of the array.
	/// @param[in] default_value			The default value of the array.
	/// @return												The retrieved array.
	//----------------------------------------------------------------------------------------
	MDArray<Bool> GetBoolArray(const DescID& id, Bool default_value = true) const;

	//----------------------------------------------------------------------------------------
	/// Gets an ::Int64/@c LLong array.
	/// @param[in] id									The description ID of the array.
	/// @param[in] default_value			The default value of the array.
	/// @return												The retrieved array.
	//----------------------------------------------------------------------------------------
	MDArray<Int64> GetLLongArray(const DescID& id, Int64 default_value = 0) const;

	//----------------------------------------------------------------------------------------
	/// Gets a ::Float/Real array.
	/// @param[in] id									The description ID of the array.
	/// @param[in] default_value			The default value of the array.
	/// @return												The retrieved array.
	//----------------------------------------------------------------------------------------
	MDArray<Float> GetRealArray(const DescID& id, Float default_value = 1.0) const;

	//----------------------------------------------------------------------------------------
	/// Gets a ::Matrix array.
	/// @param[in] id									The description ID of the array.
	/// @param[in] default_value			The default value of the array.
	/// @return												The retrieved array.
	//----------------------------------------------------------------------------------------
	MDArray<Matrix> GetMatrixArray(const DescID& id, Matrix default_value = Matrix()) const;

	//----------------------------------------------------------------------------------------
	/// Gets a ::Vector array.
	/// @param[in] id									The description ID of the array.
	/// @param[in] default_value			The default value of the array.
	/// @return												The retrieved array.
	//----------------------------------------------------------------------------------------
	MDArray<Vector> GetVectorArray(const DescID& id, Vector default_value = Vector()) const;

	/// @}

	/// @name Get Array By ID
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets a void pointer to an array.
	/// @param[in] id									The ID of the array: @enumerateEnum{MODATA_IDS}
	/// @param[in] type								The type of the array: @enumerateEnum{MD_TYPE}
	/// @return												The pointer to the array.
	//----------------------------------------------------------------------------------------
	void* GetArray(Int32 id, MD_TYPE type = MD_TYPE::MD_NONE) const;

	//----------------------------------------------------------------------------------------
	/// Gets a ::Char array.
	/// @param[in] id									The ID of the array: @enumerateEnum{MODATA_IDS}
	/// @param[in] default_value			The default value of the array.
	/// @return												The retrieved array.
	//----------------------------------------------------------------------------------------
	MDArray<Char> GetCharArray(Int32 id, Char default_value = 0) const;

	//----------------------------------------------------------------------------------------
	/// Gets a ::UChar array.
	/// @param[in] id									The ID of the array: @enumerateEnum{MODATA_IDS}
	/// @param[in] default_value			The default value of the array.
	/// @return												The retrieved array.
	//----------------------------------------------------------------------------------------
	MDArray<UChar> GetUCharArray(Int32 id, UChar default_value = 0) const;

	//----------------------------------------------------------------------------------------
	/// Gets an ::Int32/Long array.
	/// @param[in] id									The ID of the array: @enumerateEnum{MODATA_IDS}
	/// @param[in] default_value			The default value of the array.
	/// @return												The retrieved array.
	//----------------------------------------------------------------------------------------
	MDArray<Int32> GetLongArray(Int32 id, Int32 default_value = 0) const;

	//----------------------------------------------------------------------------------------
	/// Gets a ::UInt32/ULong array.
	/// @param[in] id									The ID of the array: @enumerateEnum{MODATA_IDS}
	/// @param[in] default_value			The default value of the array.
	/// @return												The retrieved array.
	//----------------------------------------------------------------------------------------
	MDArray<UInt32> GetULongArray(Int32 id, UInt32 default_value = 0) const;

	//----------------------------------------------------------------------------------------
	/// Gets a ::Bool array.
	/// @param[in] id									The ID of the array: @enumerateEnum{MODATA_IDS}
	/// @param[in] default_value			The default value of the array.
	/// @return												The retrieved array.
	//----------------------------------------------------------------------------------------
	MDArray<Bool> GetBoolArray(Int32 id, Bool default_value = true) const;

	//----------------------------------------------------------------------------------------
	/// Gets a ::Int64/LLong array.
	/// @param[in] id									The ID of the array: @enumerateEnum{MODATA_IDS}
	/// @param[in] default_value			The default value of the array.
	/// @return												The retrieved array.
	//----------------------------------------------------------------------------------------
	MDArray<Int64> GetLLongArray(Int32 id, Int64 default_value = 0) const;

	//----------------------------------------------------------------------------------------
	/// Gets a ::Float/Real array.
	/// @param[in] id									The ID of the array: @enumerateEnum{MODATA_IDS}
	/// @param[in] default_value			The default value of the array.
	/// @return												The retrieved array.
	//----------------------------------------------------------------------------------------
	MDArray<Float> GetRealArray(Int32 id, Float default_value = 1.0) const;

	//----------------------------------------------------------------------------------------
	/// Gets a ::Matrix array.
	/// @param[in] id									The ID of the array: @enumerateEnum{MODATA_IDS}
	/// @param[in] default_value			The default value of the array.
	/// @return												The retrieved array.
	//----------------------------------------------------------------------------------------
	MDArray<Matrix> GetMatrixArray(Int32 id, Matrix default_value = Matrix()) const;

	//----------------------------------------------------------------------------------------
	/// Gets a ::Vector array.
	/// @param[in] id									The ID of the array: @enumerateEnum{MODATA_IDS}
	/// @param[in] default_value			The default value of the array.
	/// @return												The retrieved array.
	//----------------------------------------------------------------------------------------
	MDArray<Vector> GetVectorArray(Int32 id, Vector default_value = Vector()) const;

	/// @}

	/// @name Get Array By Index
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets a void pointer to an array.
	/// @param[in] index							The index of the array: @em 0 <= @formatParam{index} < GetArrayCount()
	/// @return												The pointer to the array.
	//----------------------------------------------------------------------------------------
	void* GetIndexArray(Int32 index) const;

	//----------------------------------------------------------------------------------------
	/// Gets a ::Char array.
	/// @param[in] index							The index of the array: @em 0 <= @formatParam{index} < GetArrayCount()
	/// @return												The retrieved array.
	//----------------------------------------------------------------------------------------
	MDArray<Char> GetCharIndexArray(Int32 index) const;

	//----------------------------------------------------------------------------------------
	/// Gets a ::UChar array.
	/// @param[in] index							The index of the array: @em 0 <= @formatParam{index} < GetArrayCount()
	/// @return												The retrieved array.
	//----------------------------------------------------------------------------------------
	MDArray<UChar> GetUCharIndexArray(Int32 index) const;

	//----------------------------------------------------------------------------------------
	/// Gets an ::Int32/Long array.
	/// @param[in] index							The index of the array: @em 0 <= @formatParam{index} < GetArrayCount()
	/// @return												The retrieved array.
	//----------------------------------------------------------------------------------------
	MDArray<Int32> GetLongIndexArray(Int32 index) const;

	//----------------------------------------------------------------------------------------
	/// Gets a ::UInt32/ULong array.
	/// @param[in] index							The index of the array: @em 0 <= @formatParam{index} < GetArrayCount()
	/// @return												The retrieved array.
	//----------------------------------------------------------------------------------------
	MDArray<UInt32> GetULongIndexArray(Int32 index) const;

	//----------------------------------------------------------------------------------------
	/// Gets a ::Bool array.
	/// @param[in] index							The index of the array: @em 0 <= @formatParam{index} < GetArrayCount()
	/// @return												The retrieved array.
	//----------------------------------------------------------------------------------------
	MDArray<Bool> GetBoolIndexArray(Int32 index) const;

	//----------------------------------------------------------------------------------------
	/// Gets a ::Int64/LLong array.
	/// @param[in] index							The index of the array: @em 0 <= @formatParam{index} < GetArrayCount()
	/// @return												The retrieved array.
	//----------------------------------------------------------------------------------------
	MDArray<Int64> GetLLongIndexArray(Int32 index) const;

	//----------------------------------------------------------------------------------------
	/// Gets a ::Float/Real array.
	/// @param[in] index							The index of the array: @em 0 <= @formatParam{index} < GetArrayCount()
	/// @return												The retrieved array.
	//----------------------------------------------------------------------------------------
	MDArray<Float> GetRealIndexArray(Int32 index) const;

	//----------------------------------------------------------------------------------------
	/// Gets a ::Matrix array.
	/// @param[in] index							The index of the array: @em 0 <= @formatParam{index} < GetArrayCount()
	/// @return												The retrieved array.
	//----------------------------------------------------------------------------------------
	MDArray<Matrix> GetMatrixIndexArray(Int32 index) const;

	//----------------------------------------------------------------------------------------
	/// Gets a ::Vector array.
	/// @param[in] index							The index of the array: @em 0 <= @formatParam{index} < GetArrayCount()
	/// @return												The retrieved array.
	//----------------------------------------------------------------------------------------
	MDArray<Vector> GetVectorIndexArray(Int32 index) const;

	/// @}

	/// @name Copy/Merge
	/// @{

	//----------------------------------------------------------------------------------------
	/// Copies the MoGraph data to @formatParam{dest}.
	/// @param[in] dest								The destination MoGraph data. @callerOwnsPointed{data}
	/// @param[in] merge_data					If @formatConstant{true} the source and destination data are merged. If @formatConstant{false} a straight one-to-one copy is made.\n
	/// 															For instance if the source contains a matrix array and the destination a matrix and a real array the real array will still exist after the merge action.
	/// @param[in] max_count					The maximum number of array elements to copy. This limits the array size of the copy.
	/// @return												@trueIfOtherwiseFalse{the MoGraph data was copied}
	//----------------------------------------------------------------------------------------
	Bool CopyTo(MoData* dest, Bool merge_data = false, Int max_count = NOTOK) const;

	//----------------------------------------------------------------------------------------
	/// Merges the MoGraph data with another.
	/// @param[in] source							The source MoGraph data. @callerOwnsPointed{data}
	/// @param[in] percent						The blend factor for the merge of the data, going from @em 0.0 to @em 1.0 (@em 0 to @em 100%).
	/// @return												@trueIfOtherwiseFalse{the MoGraph data was merged}
	//----------------------------------------------------------------------------------------
	Bool MergeData(MoData* source, Float percent);

	/// @}

	/// @name Miscellaneous
	/// @{

	//----------------------------------------------------------------------------------------
	/// Flushes the MoGraph data.\n
	/// All data is cleared and the arrays are freed.
	//----------------------------------------------------------------------------------------
	void Flush();

	//----------------------------------------------------------------------------------------
	/// Sets an offset from the beginning of the arrays, for example array[0] becomes array[offset].
	/// @param[in] offset							The array offset: @em 0 <= @formatParam{offset} < GetCount()
	//----------------------------------------------------------------------------------------
	void SetOffset(Int offset = 0);

	//----------------------------------------------------------------------------------------
	/// Sets a limit for the array. All data is kept internally. Can be useful for certain cases for instance merging.
	/// @param[in] limit							The array limit: @em 0 <= @formatParam{limit} < GetCount()
	//----------------------------------------------------------------------------------------
	void SetLimit(Int limit = NOTOK);

	//----------------------------------------------------------------------------------------
	/// Sets the color mode.
	/// @param[in] colorMode					The new color mode.
	//----------------------------------------------------------------------------------------
	void SetColorMode(Int32 colorMode);

	//----------------------------------------------------------------------------------------
	/// Gets the color mode.
	/// @return												The new color mode.
	//----------------------------------------------------------------------------------------
	Int32 GetColorMode() const;

	/// @}
};

//----------------------------------------------------------------------------------------
/// Structure for passing MoData around
//----------------------------------------------------------------------------------------
struct GetMoDataMessage
{
	//----------------------------------------------------------------------------------------
	/// Default constructor.
	//----------------------------------------------------------------------------------------
	GetMoDataMessage() { index = 0; modata = nullptr; user_owned = false; }

	//----------------------------------------------------------------------------------------
	/// Destructor.
	//----------------------------------------------------------------------------------------
	~GetMoDataMessage()
	{
		if (user_owned && modata)
			MoData::Free(modata);
	}

	MoData*	modata;					///< The returned MoData.
	Int32		index;					///< The index of the modata.\n
													///< There can be multiple MoData on an object; e.g. the Text object for instance has 4 MoData, one for the whole, then for lines, words and finally characters.\n
													///< Can be used to retrieve the other MoData from the motion data tag. Should be usually set to @em 0.
	Bool		user_owned;			///< The modata is either owned by @C4D or by the user. If it is user owned then the user must free the modata.

	//----------------------------------------------------------------------------------------
	/// Releases the MoData to the user. The user must then free the result afterward.
	/// @return												The released modata. @callerOwnsPointed{motion data}
	//----------------------------------------------------------------------------------------
	MoData* Release()
	{
		if (!user_owned)
		{
			MoData* md = MoData::Alloc();
			if (!md)
				return nullptr;
			if (!modata->CopyTo(md))
			{
				MoData::Free(md);
				return nullptr;
			}
			modata = md;
		}
		user_owned = false;
		return modata;
	}
};

//----------------------------------------------------------------------------------------
/// Message struct for the @ref MSG_GET_MODATASELECTION message.
//----------------------------------------------------------------------------------------
struct GetMGSelectionMessage
{
	GetMGSelectionMessage() :sel(nullptr) {}
	~GetMGSelectionMessage() {}

	BaseSelect* sel;			///< The selected clones.
};

/// Holds weight information for MoGraph weight tags. @since R18
struct MGWeightData
{
	maxon::BaseArray<Float> _weight;
};

//----------------------------------------------------------------------------------------
/// Message struct for the @ref MSG_GET_MODATAWEIGHTS message. @since R18
//----------------------------------------------------------------------------------------
struct GetMGWeightMessage
{
	GetMGWeightMessage() :_weightInfo(nullptr) {}
	~GetMGWeightMessage() {}

	MGWeightData* _weightInfo;			///< The clones weights.
};

//----------------------------------------------------------------------------------------
/// Data structure for an effector's internal data, filled from its container.\n
//----------------------------------------------------------------------------------------
struct EffectorDataStruct
{
	Float		falloff_time = 0.0_f;				///< Falloff time.
	Vector	pos,												///< Position.
					scale,											///< Scale.
					rot,												///< Rotation.
					col;												///< Color.
	Float		strength = 1.0_f;						///< Effector strength.
	Float		maxstrength = 1.0_f;				///< Effector maximum strength.
	Float		minstrength = 0.0_f;				///< Effector minimum strength
	Int32		trans_mode = 0;							///< Transform mode. (See @em obaseeffector.res)
	Int32		col_mode = 0;								///< Color mode. (See @em obaseeffector.res)
	Int32		blend_mode = 0;							///< Blending mode (See @em obaseeffector.res)
};

enum class STRENGTHMASK
{
	NONE = 0,

	POS_X = (1 << 0),
	POS_Y = (1 << 1),
	POS_Z = (1 << 2),
	POS = POS_X | POS_Y | POS_Z,

	SCALE_X = (1 << 3),
	SCALE_Y = (1 << 4),
	SCALE_Z = (1 << 5),
	SCALE = SCALE_X | SCALE_Y | SCALE_Z,

	ROT_X = (1 << 6),
	ROT_Y = (1 << 7),
	ROT_Z = (1 << 8),
	ROT = ROT_X | ROT_Y | ROT_Z,

	COL_X = (1 << 9),
	COL_Y = (1 << 10),
	COL_Z = (1 << 11),
	COL = COL_X | COL_Y | COL_Z,

	OTHER_X = (1 << 12),
	OTHER_Y = (1 << 13),
	OTHER_Z = (1 << 14),
	OTHER = OTHER_X | OTHER_Y | OTHER_Z,

	OTHER2_X = (1 << 15),
	OTHER2_Y = (1 << 16),
	OTHER2_Z = (1 << 17),
	OTHER2 = OTHER2_X | OTHER2_Y | OTHER2_Z,

	OTHER3_X = (1 << 18),
	OTHER3_Y = (1 << 19),
	OTHER3_Z = (1 << 20),
	OTHER3 = OTHER3_X | OTHER3_Y | OTHER3_Z,
} MAXON_ENUM_FLAGS(STRENGTHMASK);

//----------------------------------------------------------------------------------------
/// Data structure for mutable data which is set up in EffectorData::CalcPointValue.
/// See @em obaseeffector.res and @em obaseeffector.h for the IDs.\n
/// To get it filled make sure that the IDs for strength etc. match those in @em obaseeffector.h.
//----------------------------------------------------------------------------------------
struct MutableEffectorDataStruct
{
	MutableEffectorDataStruct()
	{
		ClearMemType(_strengths, BLEND_COUNT);
	};

	MAXON_ATTRIBUTE_FORCE_INLINE Bool IsUsed(STRENGTHMASK mask) const
	{
		return (_strengthUsed & mask) != STRENGTHMASK::NONE;
	}

	MAXON_ATTRIBUTE_FORCE_INLINE Bool IsUsed(Int32 channel) const 
	{
		return IsUsed(STRENGTHMASK(1 << channel));
	}
	
	STRENGTHMASK _strengthUsed = STRENGTHMASK::NONE; ///< bit "1 << i" equals true indicates if the value in strengths[i] is used/required/calculated

	union
	{
		// strength values as c++ structure
		struct
		{
			Vector pos, ///< Position
				scale,		///< Scale
				rot,			///< Rotation.
				col,			///< Color.
				other,		///< First other.
				other2,		///< Second other.
				other3;		///< Third other.
		} _strengthValues;

		// strength values as float array
		Float _strengths[BLEND_COUNT];	///< Amount of strengths for each value, of in order, position, scale, rotation, color (and anything else to affect).\n
																		///< Strength value are set by the effector in EffectorData::CalcPointValue.
	};
};

//----------------------------------------------------------------------------------------
/// Message struct for the @ref MSG_EXECUTE_EFFECTOR message.\n
/// Either @ref op or @ref md must be filled, and @ref weight should be normally set to @em 1.0.
//----------------------------------------------------------------------------------------
struct Effector_PassData
{
	//----------------------------------------------------------------------------------------
	/// Default constructor.
	//----------------------------------------------------------------------------------------
	Effector_PassData()
	{
		op = nullptr;
		md = nullptr;
		weight = 1.0;
		thread = nullptr;
	}

	const BaseObject*	op;					///< The object that the MoData belongs to. Used for its matrix.
	MoData*			md;					///< The motion data to be modified.
	Float				weight;			///< An additional strength value for the effector. The result is @ref weight * effectors_own_strength * its_falloff * effector_values = end_strength of effect on any particular particle.
	BaseThread*	thread;			///< The thread the effector is being executed in.
	EffectorDataStruct effectorData; ///< Internal effector data, this has to be used for Effector_PassValueData::effectorData for a following MSG_SAMPLE_EFFECTOR_VALUE message.
};

//----------------------------------------------------------------------------------------
/// Message struct for the @ref MSG_SAMPLE_EFFECTOR_VALUE message.\n
/// Allows the sampling of the effector strength for a particular point.
//----------------------------------------------------------------------------------------
struct Effector_PassValueData
{
	Float		value = 0.0_f;			///< The strength at @ref pos.
	Vector	pos;				///< The position in world coordinates.
	const EffectorDataStruct* effectorData = nullptr; ///< Internal effector data from Effector_PassData::effectorData of a previous execution of the MSG_EXECUTE_EFFECTOR message.
};

struct EffectorDataParameters;

//----------------------------------------------------------------------------------------
/// A data class for creating effector plugins.\n
/// Effectors are objects that modifies motion data particles in the MoGraph module, and uses the same controls for deformation. (Effectors cannot run without the MoGraph module.)\n
/// @note Effectors are executed by messaging them @ref MSG_EXECUTE_EFFECTOR and passing an Effector_PassData structure.
/// Use RegisterEffectorPlugin() to register an effector plugin.
//----------------------------------------------------------------------------------------
class EffectorData : public ObjectData
{
public:
	maxon::BaseRef<EffectorDataParameters, maxon::DeepConstnessPointerHandler> edata;			///< @markPrivate @markInternal

	/// @name Inherited from NodeData/ObjectData
	/// @{

	virtual Bool Init(GeListNode* node, Bool isCloneInit);
	virtual void Free(GeListNode* node);
	virtual Bool GetDDescription(const GeListNode* node, Description* description, DESCFLAGS_DESC& flags) const;
	virtual DRAWRESULT Draw(BaseObject* op, DRAWPASS drawpass, BaseDraw* bd, BaseDrawHelp* bh);
	virtual void GetDimension(const BaseObject* op, Vector* mp, Vector* rad) const;
	virtual Bool AddToExecution(BaseObject* op, PriorityList* list) final;
	virtual EXECUTIONRESULT Execute(BaseObject* op, BaseDocument* doc, BaseThread* bt, Int32 priority, EXECUTIONFLAGS flags);
	virtual Bool ModifyObject(const BaseObject* mod, const BaseDocument* doc, BaseObject* op, const Matrix& op_mg, const Matrix& mod_mg, Float lod, Int32 flags, BaseThread* thread) const;
	virtual maxon::Result<Bool> GetAccessedObjects(const BaseList2D* node, METHOD_ID method, AccessedObjectsCallback& access) const;
	virtual Bool Message(GeListNode* node, Int32 type, void* t_data);
	virtual Int32 GetHandleCount(const BaseObject* op) const;
	virtual void GetHandle(BaseObject* op, Int32 i, HandleInfo& info);
	virtual void SetHandle(BaseObject* op, Int32 i, Vector p, const HandleInfo& info);
	virtual Bool CopyTo(NodeData* dest, const GeListNode* snode, GeListNode* dnode, COPYFLAGS flags, AliasTrans* trn) const;
	virtual Bool IsInstanceOf(const GeListNode* node, Int32 type) const;
	virtual Bool GetDEnabling(const GeListNode *node, const DescID &id, const GeData &t_data, DESCFLAGS_ENABLE flags, const BaseContainer *itemdesc) const;

	/// @}

	/// @name Effector
	/// @{

	//----------------------------------------------------------------------------------------
	/// Called to initialize the effector. Replacement NodeData::Init function for effectors.\n
	/// Called when effector is first created.
	/// @note It is not needed to call @link EffectorData SUPER@endlink::@ref InitEffector()
	/// @param[in] node								Equal to Get(). Provided for speed and convenience. @cinemaOwnsPointed{node}
	/// @return												@trueIfOtherwiseFalse{the node was initialized}
	//----------------------------------------------------------------------------------------
	virtual Bool InitEffector(GeListNode* node, Bool isCloneInit);

	//----------------------------------------------------------------------------------------
	/// Called to free the effector. Replacement NodeData::Free function for effectors.\n
	/// Called when effector is deleted.
	/// @note It is not needed to call @link EffectorData SUPER@endlink::@ref FreeEffector()
	/// @param[in] node								Equal to Get(). Provided for speed and convenience. @cinemaOwnsPointed{node}
	//----------------------------------------------------------------------------------------
	virtual void FreeEffector(GeListNode* node);

	//----------------------------------------------------------------------------------------
	/// Gets the falloff of the effector, this may be null if the effector is using Fields instead, in which case make use of CalcFields.
	/// @note ::EFFECTORFLAGS_HASFALLOFF needs to be set.
	/// @return												The falloff.
	//----------------------------------------------------------------------------------------
	C4D_Falloff* GetFalloff();

	/// @copydoc GetFalloff
	const C4D_Falloff* GetFalloff() const
	{
		return const_cast<EffectorData*>(this)->GetFalloff();
	}

	//----------------------------------------------------------------------------------------
	/// Adds a dependence on another object's dirty state to the effector.\n
	/// This way if the other object becomes dirty then the effector will be forced to update.\n
	/// Normally used in either ExecuteEffector or InitPoints. (See @em DropEffector SDK example.)
	/// @param[in] op									The object to add a dependency on. @callerOwnsPointed{object}
	//----------------------------------------------------------------------------------------
	void AddEffectorDependence(const BaseObject* op) const;

	//----------------------------------------------------------------------------------------
	/// Called to get the effector flags.
	/// @return												The effectors flags: @enumerateEnum{EFFECTORFLAGS}
	//----------------------------------------------------------------------------------------
	virtual Int32 GetEffectorFlags() const;

	//----------------------------------------------------------------------------------------
	/// Called to modify the description of the effector.\n
	/// Convenience function so it is not needed to overload NodeData::GetDDescription to show/hide elements or change the description.
	/// @param[in] node								Equal to Get(). Provided for speed and convenience. @cinemaOwnsPointed{node}
	/// @param[in,out] description		The description to modify. @cinemaOwnsPointed{description}
	/// @param[in] ar									The atom array to pass along. @cinemaOwnsPointed{atom array}
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	virtual Bool ModifyDDescription(const GeListNode* node, Description* description, AtomArray* ar) const;

	//----------------------------------------------------------------------------------------
	/// Called to execute the effector.\n
	/// Called first of all in the effector execution pipeline. Fill the EffectorDataStruct and call InitPoints().
	/// @warning Do not override unless strictly necessary.
	/// @note Needs to call @link EffectorData SUPER@endlink::@ref ExecuteEffector() as last return.
	/// @param[in] op									The effector object. @cinemaOwnsPointed{object}
	/// @param[in] doc								The document. @cinemaOwnsPointed{document}
	/// @param[in] gen								The object that owns the MoData (motion particle generator). @cinemaOwnsPointed{object}\n
	/// 															Can sometimes be the same as the effector, mostly used for matrix, internally used to get MoData when no MoData is sent.
	/// @param[in] md									The motion data sent to the effector, may be @formatConstant{nullptr}. @cinemaOwnsPointed{motion data}
	/// @param[in] strength						The strength value.
	/// @param[in] thread							The thread the effector is being executed in. @cinemaOwnsPointed{thread}
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	virtual Bool ExecuteEffector(const BaseObject* op, const BaseDocument* doc, const BaseObject* gen, EffectorDataStruct& data, MoData* md, Float strength, BaseThread* thread) const;

	//----------------------------------------------------------------------------------------
	/// Called to initialize the points/particles just before the effector body is calculated in @ref ModifyPoints.\n
	/// Allows to setup and retrieve any necessary data from the effector's container.
	/// @param[in] op									The effector object. @cinemaOwnsPointed{object}
	/// @param[in] gen								The object that owns the MoData (motion particle generator). @cinemaOwnsPointed{object}\n
	/// 															Can sometimes be the same as the effector, mostly used for matrix, internally used to get MoData when no MoData is sent.
	/// @param[in] doc								The document. @cinemaOwnsPointed{document}
	/// @param[in] data								The effector's internal data, filled in. @cinemaOwnsPointed{data}
	/// @param[in] md									The MoData the effector will modify. @cinemaOwnsPointed{motion data}
	/// @param[in] thread							The thread the effector is being executed in. @cinemaOwnsPointed{thread}
	//----------------------------------------------------------------------------------------
	virtual maxon::Result<maxon::GenericData> InitPoints(const BaseObject* op, const BaseObject* gen, const BaseDocument* doc, const EffectorDataStruct& data, MoData* md, BaseThread* thread) const;

	//----------------------------------------------------------------------------------------
	/// Called to modify the MoData particles.\n All falloff values should be evaluated if overridden using the falloff of the effector (retrieved with
	/// @ref GetFalloff).\n
	/// @em DropEffector SDK example shows how to overload @ref ModifyPoints correctly.
	/// @note If overridden then CalcPlacebo(), CalcPointValue() and CalcPointColor() will not get called (unless the effector explicitly calls them).
	/// @param[in] op									The effector object. @cinemaOwnsPointed{object}
	/// @param[in] gen								The object that owns the MoData (motion particle generator). @cinemaOwnsPointed{object}\n Can be sometimes the same as the
	/// 															effector, mostly used for matrix, internally used to get MoData when no MoData is sent.
	/// @param[in] doc								The document. @cinemaOwnsPointed{document}
	/// @param[in] data								The effector's internal data, filled in. @cinemaOwnsPointed{data}
	/// @param[in] md									The MoData the effector will modify. @cinemaOwnsPointed{motion data}
	/// @param[in] thread							The thread the effector is being executed in. @cinemaOwnsPointed{thread}
	//----------------------------------------------------------------------------------------
	virtual void ModifyPoints(const BaseObject* op, const BaseObject* gen, const BaseDocument* doc, const EffectorDataStruct& data, const maxon::GenericData& extraData, MutableEffectorDataStruct& mdata, MoData* md, BaseThread* thread) const;

	//----------------------------------------------------------------------------------------
	/// Called in a value driven effector for each point/particle that is not needed (where @ref ModifyPoints has not been override).\n
	/// Called when a MoData index should not be calculated/evaluated itself, but certain values may be needed to be incremented internally.\n
	/// For instance if a "random" value is used, makes sure it is called the same number of times as particles (to avoid skipping/jumping around values).
	/// @param[in] op									The effector object. @cinemaOwnsPointed{object}
	/// @param[in] gen								The object that owns the MoData (motion particle generator). @cinemaOwnsPointed{object}\n
	/// 															Can sometimes be the same as the effector, mostly used for matrix, internally used to get MoData when no MoData is sent.
	/// @param[in] doc								The document. @cinemaOwnsPointed{document}
	/// @param[in] data								The effector's internal data, filled in. @cinemaOwnsPointed{data}
	/// @param[in] index							The current point/particle index.
	/// @param[in] md									The MoData. @cinemaOwnsPointed{motion data}
	/// @param[in] globalpos					The global space position of the current point/particle.
	/// @param[in] fall_weight				The falloff strength for the current particle.
	//----------------------------------------------------------------------------------------
	virtual void CalcPlacebo(const BaseObject* op, const BaseObject* gen, const BaseDocument* doc, const EffectorDataStruct& data, const maxon::GenericData& extraData, MutableEffectorDataStruct& mdata, Int32 index, MoData* md, const Vector& globalpos, Float fall_weight) const;

	//----------------------------------------------------------------------------------------
	/// Called in a value driven effector for each point/particle that is needed (where @ref ModifyPoints has not been override).\n
	/// Assign the EffectorDataStruct's @link EffectorDataStruct::strengths strengths@endlink (see @em NoiseEffector SDK example) to set the values that drive the effector.
	/// @param[in] op									The effector object. @cinemaOwnsPointed{object}
	/// @param[in] gen								The object that owns the MoData (motion particle generator). @cinemaOwnsPointed{object}\n
	/// 															Can sometimes be the same as the effector, mostly used for matrix, internally used to get MoData when no MoData is sent.
	/// @param[in] doc								The document. @cinemaOwnsPointed{document}
	/// @param[in] data								The effector's internal data, filled in. @cinemaOwnsPointed{data}
	/// @param[in] index							The current point/particle index.
	/// @param[in] md									The MoData. @cinemaOwnsPointed{motion data}
	/// @param[in] globalpos					The global space position of the current point/particle.
	/// @param[in] fall_weight				The falloff strength for the current point.
	//----------------------------------------------------------------------------------------
	virtual void CalcPointValue(const BaseObject* op, const BaseObject* gen, const BaseDocument* doc, const EffectorDataStruct& data, const maxon::GenericData& extraData, MutableEffectorDataStruct& mdata, Int32 index, MoData* md, const Vector& globalpos, Float fall_weight) const;

	//----------------------------------------------------------------------------------------
	/// Called in a value driven effector for each point/particle that is needed (where @ref ModifyPoints has not been override).\n
	/// @note Only has an effect when the effector is set to change the point/particle's color.
	/// @param[in] op									The effector object. @cinemaOwnsPointed{object}
	/// @param[in] gen								The object that owns the MoData (motion particle generator). @cinemaOwnsPointed{object}\n
	/// 															Can sometimes be the same as the effector, mostly used for matrix, internally used to get MoData when no MoData is sent.
	/// @param[in] doc								The document. @cinemaOwnsPointed{document}
	/// @param[in] data								The effector's internal data, filled in. @cinemaOwnsPointed{data}
	/// @param[in] index							The current point/particle index.
	/// @param[in] md									The MoData. @cinemaOwnsPointed{motion data}
	/// @param[in] globalpos					The global space position of the current point/particle.
	/// @param[in] fall_weight				The falloff strength for the current particle.
	/// @return												The color for a point.
	//----------------------------------------------------------------------------------------
	virtual Vector CalcPointColor(const BaseObject* op, const BaseObject* gen, const BaseDocument* doc, const EffectorDataStruct& data, const maxon::GenericData& extraData, const MutableEffectorDataStruct& mdata, Int32 index, MoData* md, const Vector& globalpos, Float fall_weight) const;

	//----------------------------------------------------------------------------------------
	/// Retrieves the FieldResult calculation from an Effector.  This if there is no C4DFalloff then
	/// this should be used instead.
	///
	/// @param[in] doc								The active document.
	/// @param[in] generatorObject		The generator object calling the Effector.
	/// @param[in] md									The MoData that you want to sample.
	/// @param[in] flags							The FEILDSAMPLE_FLAG flags that determine what will be sampled.
	///
	/// @return												Null if it fails, else a FieldOutput structure pointer (Effector owns the data) containing sampled values for the passed MoData matrices.
	//----------------------------------------------------------------------------------------
	Bool CalcFields(const BaseDocument* doc, const BaseObject* generatorObject, MoData* md, FIELDSAMPLE_FLAG flags, FieldOutput& result) const;


	static maxon::Result<Bool> GetAccessedObjectsEffectorBase(const BaseList2D* node, METHOD_ID method, AccessedObjectsCallback& access, ACCESSED_OBJECTS_MASK ensureReadable = ACCESSED_OBJECTS_MASK(0));
};

//----------------------------------------------------------------------------------------
/// Registers an effector plugin.
/// @param[in] id									@uniquePluginID
/// @param[in] str								The name of the plugin.\n
/// 															To affect the order that plugins are displayed in menus add <i>"#$n"</i> as a prefix to this name, where @em n is a number.\n
/// 															Lower numbers are displayed before higher numbers. If name is <i>"--"</i> it will show up as a menu separator.
/// @param[in] info								The plugin info flags: @enumerateEnum{OBJECT} @enumerateEnum{PLUGINFLAG}
/// @param[in] g									The allocator for the effector plugin. This is a pointer to a function that creates a new instance of EffectorData with NewObj().
/// @param[in] description				The name of the description resource file to use for the effector plugin without @em .res extension, for example @em "oespline".\n
/// 															The name has to be unique, i.e. @em "Tdisplay" cannot be used for 2 different descriptions. See Description Resource for more information.
/// @param[in] icon								The icon for the command. The bitmap is copied. \n
/// 															The icon should be of size @em 32x@em 32, but will be scaled if needed.\n
/// 															It must also be @em 24 bits and should if possible include an alpha to support pattern backgrounds.
/// @param[in] disklevel					The plugin level is similar to a version number. The default level is @em 0.\n
/// 															Increase this for new revisions of a plugin to allow for forward and backward compatibility.\n\n
/// 															As an example you may have updated a plugin. If you now need to write additional information for new settings or changed types for old settings you can increase the level.\n
/// 															During loading either a @em 0 is passed (if the file was written by the old plugin) or @em 1 (if the file was written by the new plugin). This allows to easily write/read new values.\n
/// 															For forward and backward compatibility to work any existing read order from a given level must not be changed. @C4D skips any new settings automatically if they have not been read.\n\n
/// 															@formatParam{disklevel} is only useful if variables are written/read in @ref NodeData::Write/@ref NodeData::Read.
/// @return												@trueIfOtherwiseFalse{the effector plugin was registered}
//----------------------------------------------------------------------------------------
Bool RegisterEffectorPlugin(Int32 id, const maxon::String& str, Int32 info, DataAllocator* g, const maxon::String& description, BaseBitmap* icon, Int32 disklevel);

#ifdef CINEWARE_NAMESPACE_ENABLE
	CINEWARE_NAMESPACE_END
#endif

#endif // C4D_BASEEFFECTORDATA_H__
