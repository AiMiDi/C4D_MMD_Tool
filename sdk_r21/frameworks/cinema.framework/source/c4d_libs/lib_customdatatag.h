/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef LIB_CUSTOMDATATAG_H__
#define LIB_CUSTOMDATATAG_H__

#include "c4d_library.h"
#include "lib_description.h"

#include "maxon/mesh_attribute_base.h"

#ifdef __API_INTERN__
#include "pluginobject.h"
#include "plugintag.h"

#else
#include "c4d_baseobject.h"
#include "c4d_basetag.h"
#endif

static const Int32 ID_CUSTOMDATA_TAG_LIB = 431000187;

struct CustomaDataTagLibrary;

CustomaDataTagLibrary* CheckCustomaDataTagLibrary(Int32 offset);

enum class CUSTOMDATATAG_MODE
{
	VERTEX = 0,
	POLYVERTEX,
} MAXON_ENUM_LIST(CUSTOMDATATAG_MODE);

//----------------------------------------------------------------------------------------
/// CustomDataTag contains data attached to each mesh vertex or each polyvertex.
/// The CustomDataTag is automatically registered by implementing CustomDataTagClassInterface.
/// While each CustomDataTagClassInterface implementation registers a specific CustomdataTag whith the provided plugin id (returned by BaseTag::GetType())
/// all CustomDataTags are instances of Tmeshattribute.
/// In the case of polyvertex data storage the indexing follows the CPolygon pattern.
//----------------------------------------------------------------------------------------
class CustomDataTag : public BaseTag
{
	INSTANCEOF(CustomDataTag, BaseTag)

private:
	CustomDataTag();
	~CustomDataTag();

public:

	//----------------------------------------------------------------------------------------
	/// Allocates a new instance of a specific type of CustomDataTag.
	/// @param[in] tagId							The plugin id for the new instance.
	/// @return												A new CustomDataTag pointer.
	//----------------------------------------------------------------------------------------
	static CustomDataTag* Alloc(Int32 tagId);

	//----------------------------------------------------------------------------------------
	/// Destroys a CustomDataTag instance and frees all resources.
	/// @param[in,out] tag						The tag to destroy.
	//----------------------------------------------------------------------------------------
	static void Free(CustomDataTag*& tag);

	//----------------------------------------------------------------------------------------
	/// Initializes the data with the correct component count based on the mesh vertex or PolygonCount.
	/// Must be called after BaseObject::InsertTag().
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	maxon::Result<void> InitData();

	//----------------------------------------------------------------------------------------
	/// Returns a reference to the underlying CustomDataTagClass.
	/// @return												MeshAttributeClass reference or an error.
	//----------------------------------------------------------------------------------------
	maxon::Result<maxon::CustomDataTagClass> GetCustomDataTagClass() const;

	//----------------------------------------------------------------------------------------
	/// Returns a pointer to the datatype used by the CustomDataTag.
	/// @return												The dataType pointer or an error.
	//----------------------------------------------------------------------------------------
	maxon::Result<maxon::DataType> GetDataType() const;

	//----------------------------------------------------------------------------------------
	/// Returns the component mode, i.e. if it is attached to mesh vertices or to mesh polyvertices.
	/// @return												The current mode.
	//----------------------------------------------------------------------------------------
	CUSTOMDATATAG_MODE GetMode() const;

	//----------------------------------------------------------------------------------------
	/// Sets the component mode and translates existing data (e.g. from CUSTOMDATATAG_MODE::POLYVERTEX to CUSTOMDATATAG_MODE::VERTEX each vertex will receive the average value of all attached polyvertices)
	/// @param[in] mode								The new CUSTOMDATATAG_MODE.
	//----------------------------------------------------------------------------------------
	void SetMode(CUSTOMDATATAG_MODE mode);

	//----------------------------------------------------------------------------------------
	/// Resizes the data count.
	/// @param[in] newCount						The new data count.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	maxon::Result<void> Resize(Int newCount);

	//----------------------------------------------------------------------------------------
	/// Gets the component count.
	/// @return												The data count.
	//----------------------------------------------------------------------------------------
	Int GetComponentCount() const;

	//----------------------------------------------------------------------------------------
	/// Gets a read-only pointer to the data at the passed vertex index. Must be called only if GetMode() == CUSTOMDATATAG_MODE::VERTEX.
	/// @param[in] vertexIndex				The vertex index.
	/// @return												A read-only pointer to the data at vertexIndex.
	//----------------------------------------------------------------------------------------
	const void* GetConstVertexDataPtr(Int32 vertexIndex) const;

	//----------------------------------------------------------------------------------------
	/// Gets a writable pointer to the data at the passed vertex index. Must be called only if GetMode() == CUSTOMDATATAG_MODE::VERTEX.
	/// @param[in] vertexIndex				The vertex index.
	/// @return												A writable pointer to the data at vertexIndex.
	//----------------------------------------------------------------------------------------
	void* GetVertexDataPtr(Int32 vertexIndex);

	//----------------------------------------------------------------------------------------
	/// Sets data at vertexIndex. Must be called only if GetMode() == CUSTOMDATATAG_MODE::VERTEX.
	/// Data is copied.
	/// @param[in] data								A pointer to the original data.
	/// @param[in] vertexIndex				The vertex index.
	//----------------------------------------------------------------------------------------
	void SetVertexDataPtr(void* data, Int32 vertexIndex);

	//----------------------------------------------------------------------------------------
	/// Gets a read-only pointer to the data at the passed polyVertexIndex in polygonIndex. Must be called only if GetMode() == CUSTOMDATATAG_MODE::POLYVERTEX.
	/// @param[in] polygonIndex				The polygon index.
	/// @param[in] polyVertexIndex		The polygon vertex index in range 0 to 3.
	/// @return												A read-only pointer to the data at polyVertexIndex in polygonIndex.
	//----------------------------------------------------------------------------------------
	const void* GetConstPolyVertexDataPtr(Int32 polygonIndex, Int32 polyVertexIndex) const;

	//----------------------------------------------------------------------------------------
	/// Gets a writable pointer to the data at the passed polyVertexIndex in polygonIndex. Must be called only if GetMode() == CUSTOMDATATAG_MODE::POLYVERTEX.
	/// @param[in] polygonIndex				The polygon index.
	/// @param[in] polyVertexIndex		The polygon vertex index in range 0 to 3.
	/// @return												A writable pointer to the data at polyVertexIndex in polygonIndex.
	//----------------------------------------------------------------------------------------
	void* GetPolyVertexDataPtr(Int32 polygonIndex, Int32 polyVertexIndex);

	//----------------------------------------------------------------------------------------
	/// Sets data at polyVertexIndex in polygonIndex. Must be called only if GetMode() == CUSTOMDATATAG_MODE::POLYVERTEX.
	/// Data is copied.
	/// @param[in] data								A pointer to the original data.
	/// @param[in] polygonIndex				The polygon index.
	/// @param[in] polyVertexIndex		The polygon vertex index in range 0 to 3.
	//----------------------------------------------------------------------------------------
	void SetPolyVertexDataPtr(const void* data, Int32 polygonIndex, Int32 polyVertexIndex);

	//----------------------------------------------------------------------------------------
	/// Retrieves read-only PolyData pointers to the data at the passed polygonIndex. Must be called only if GetMode() == CUSTOMDATATAG_MODE::POLYVERTEX.
	/// @param[in] polygonIndex				The polygon index.
	/// @return												A PolyData that contains read-only pointers.
	//----------------------------------------------------------------------------------------
	const maxon::PolyData<const void*> GetConstPolygonDataPtr(Int32 polygonIndex) const;

	//----------------------------------------------------------------------------------------
	/// Retrieves writable PolyData pointers to the data at the passed polygonIndex. Must be called only if GetMode() == CUSTOMDATATAG_MODE::POLYVERTEX.
	/// @param[in] polygonIndex				The polygon index.
	/// @return												A PolyData that contains writable pointers.
	//----------------------------------------------------------------------------------------
	maxon::PolyData<void*> GetPolygonDataPtr(Int32 polygonIndex);

	//----------------------------------------------------------------------------------------
	/// Sets data for a polygon. Must be called only if GetMode() == CUSTOMDATATAG_MODE::POLYVERTEX.
	/// Data is copied.
	/// @param[in] data								A PolyData that contains to the original data.
	/// @param[in] polygonIndex				The polygon index.
	//----------------------------------------------------------------------------------------
	void SetPolygonDataPtr(maxon::PolyData<void*> data, Int32 polygonIndex);

	//----------------------------------------------------------------------------------------
	/// Gets a writable MeshAttribute at the passed vertex index. Must be called only if GetMode() == CUSTOMDATATAG_MODE::VERTEX.
	/// @param[in] vertexIndex				The vertex index.
	/// @return												A writable MeshAttribute at vertexIndex.
	//----------------------------------------------------------------------------------------
	maxon::MeshAttribute GetVertexAttribute(Int32 vertexIndex);

	//----------------------------------------------------------------------------------------
	/// Sets MeshAttribute at vertexIndex. Must be called only if GetMode() == CUSTOMDATATAG_MODE::VERTEX.
	/// Data is copied.
	/// @param[in] data								A MeshAttribute which contains the original data.
	/// @param[in] vertexIndex				The vertex index.
	//----------------------------------------------------------------------------------------
	void SetVertexAttribute(const maxon::MeshAttribute& data, Int32 vertexIndex);

	//----------------------------------------------------------------------------------------
	/// Gets a writable MeshAttribute to the data at the passed polyVertexIndex in polygonIndex. Must be called only if GetMode() == CUSTOMDATATAG_MODE::POLYVERTEX.
	/// @param[in] polygonIndex				The polygon index.
	/// @param[in] polyVertexIndex		The polygon vertex index in range 0 to 3.
	/// @return												A writable MeshAttribute at polyVertexIndex in polygonIndex.
	//----------------------------------------------------------------------------------------
	maxon::MeshAttribute GetPolyVertexAttribute(Int32 polygonIndex, Int32 polyVertexIndex);

	//----------------------------------------------------------------------------------------
	/// Sets MeshAttribute at polyVertexIndex in polygonIndex. Must be called only if GetMode() == CUSTOMDATATAG_MODE::POLYVERTEX.
	/// Data is copied.
	/// @param[in] data								A MeshAttribute which contains the original data.
	/// @param[in] polygonIndex				The polygon index.
	/// @param[in] polyVertexIndex		The polygon vertex index in range 0 to 3.
	//----------------------------------------------------------------------------------------
	void SetPolyVertexAttribute(const maxon::MeshAttribute& data, Int32 polygonIndex, Int32 polyVertexIndex);

	//----------------------------------------------------------------------------------------
	/// Retrieves writable PolyData of MeshAttributes at the passed polygonIndex. Must be called only if GetMode() == CUSTOMDATATAG_MODE::POLYVERTEX.
	/// @param[in] polygonIndex				The polygon index.
	/// @return												A writable PolyData of MeshAttributes.
	//----------------------------------------------------------------------------------------
	maxon::PolyData<maxon::MeshAttribute> GetPolygonAttribute(Int32 polygonIndex);

	//----------------------------------------------------------------------------------------
	/// Sets MeshAttribute data for a polygon. Must be called only if GetMode() == CUSTOMDATATAG_MODE::POLYVERTEX.
	/// Data is copied.
	/// @param[in] data								A PolyData of MeshAttribute which contains the original data.
	/// @param[in] polygonIndex				The polygon index.
	//----------------------------------------------------------------------------------------
	void SetPolygonAttribute(maxon::PolyData<maxon::MeshAttribute> data, Int32 polygonIndex);

	//----------------------------------------------------------------------------------------
	/// @markPrivate
	//----------------------------------------------------------------------------------------
	maxon::Result<void> DisplayControl(BaseDocument* doc, BaseObject* op, BaseDraw* bd, BaseDrawHelp* bh, ControlDisplayStruct& cds);

	//----------------------------------------------------------------------------------------
	/// @markPrivate
	//----------------------------------------------------------------------------------------
	maxon::Result<void> InitDisplayControl(BaseDocument* doc, BaseDraw* bd, const AtomArray* active);

	//----------------------------------------------------------------------------------------
	/// @markPrivate
	//----------------------------------------------------------------------------------------
	void FreeDisplayControl();

	//----------------------------------------------------------------------------------------
	/// Gets a read-only data reference for the given index. The specified type must match, otherwise this will crash.
	/// Must be called only if GetMode() == CUSTOMDATATAG_MODE::VERTEX.
	/// @tparam TYPE									The type that will be returned.
	/// @param[in] vertexIndex				The vertex index.
	/// @return												Reference to the data at vertexIndex.
	//----------------------------------------------------------------------------------------
	template <typename TYPE> const TYPE& GetVertexData(Int32 vertexIndex) const
	{
		const void* v = GetConstVertexDataPtr(vertexIndex);
		return *((const TYPE*)(v));
	}

	//----------------------------------------------------------------------------------------
	/// Gets a writable data reference for the given index. The specified type must match, otherwise this will crash.
	/// Must be called only if GetMode() == CUSTOMDATATAG_MODE::VERTEX.
	/// @tparam TYPE									The type that will be returned.
	/// @param[in] vertexIndex				The vertex index.
	/// @return												Reference to the data at vertexIndex.
	//----------------------------------------------------------------------------------------
	template <typename TYPE> maxon::ResultRef<TYPE> GetVertexDataRef(Int32 vertexIndex)
	{
		void* v = GetVertexDataPtr(vertexIndex);
		return *((TYPE*)(v));
	}

	//----------------------------------------------------------------------------------------
	/// Sets a data value at vertexIndex. The operation always succeeds as the datatype either needs to be
	/// trivially copyable or support move semantics.
	/// Must be called only if GetMode() == CUSTOMDATATAG_MODE::VERTEX.
	/// @tparam TYPE									The type that will be set.
	/// @param[in] vertexIndex				The vertex index.
	/// @param[in] value							The new data value.
	//----------------------------------------------------------------------------------------
	template <typename TYPE> void SetVertexData(Int32 vertexIndex, TYPE&& value)
	{
		ifnoerr (TYPE& r = GetVertexDataRef<TYPE>(vertexIndex))
		{
			r = std::move(value);
			void* v = GetVertexDataPtr(vertexIndex);
			if (v)
				*((Int*)v) &= ~1;
		}
	}

	//----------------------------------------------------------------------------------------
	/// Gets a read-only data reference for the given polygonIndex and polyVertexIndex. The specified type must match, otherwise this will crash.
	/// Must be called only if GetMode() == CUSTOMDATATAG_MODE::POLYVERTEX.
	/// @tparam TYPE									The type that will be returned.
	/// @param[in] polygonIndex				The polygon index.
	/// @param[in] polyVertexIndex		The polygon vertex index in range 0 to 3.
	/// @return												Reference to the data at polyVertexIndex in polygonIndex.
	//----------------------------------------------------------------------------------------
	template <typename TYPE> const TYPE& GetPolyVertexData(Int32 polygonIndex, Int32 polyVertexIndex) const
	{
		const void* v = GetConstPolyVertexDataPtr(polygonIndex, polyVertexIndex);
		return *((const TYPE*)(v));
	}

	//----------------------------------------------------------------------------------------
	/// Gets a writable data reference for the given polygonIndex and polyVertexIndex. The specified type must match, otherwise this will crash.
	/// Must be called only if GetMode() == CUSTOMDATATAG_MODE::POLYVERTEX.
	/// @tparam TYPE									The type that will be returned.
	/// @param[in] polygonIndex				The polygon index.
	/// @param[in] polyVertexIndex		The polygon vertex index in range 0 to 3.
	/// @return												Reference to the data at polyVertexIndex in polygonIndex.
	//----------------------------------------------------------------------------------------
	template <typename TYPE> maxon::ResultRef<TYPE> GetPolyVertexDataRef(Int32 polygonIndex, Int32 polyVertexIndex)
	{
		void* v = GetPolyVertexDataPtr(polygonIndex, polyVertexIndex);
		return *((TYPE*)(v));
	}

	//----------------------------------------------------------------------------------------
	/// Sets a data value for a given polygonIndex and polyVertexIndex. The operation always succeeds as the datatype either needs to be
	/// trivially copyable or support move semantics.
	/// Must be called only if GetMode() == CUSTOMDATATAG_MODE::POLYVERTEX.
	/// @tparam TYPE									The type that will be set.
	/// @param[in] polygonIndex				The polygon index.
	/// @param[in] polyVertexIndex		The polygon vertex index in range 0 to 3.
	/// @param[in] value							The new data value.
	//----------------------------------------------------------------------------------------
	template <typename TYPE> void SetPolyVertexData(Int32 polygonIndex, Int32 polyVertexIndex, TYPE&& value)
	{
		ifnoerr (TYPE& r = GetPolyVertexDataRef<TYPE>(polygonIndex, polyVertexIndex))
		{
			r = std::move(value);
			void* v = GetPolyVertexDataPtr(polygonIndex, polyVertexIndex);
			if (v)
				*((Int*)v) &= ~1;
		}
	}

	//----------------------------------------------------------------------------------------
	/// Gets a read-only PolyData data reference for the given polygonIndex. The specified type must match, otherwise this will crash.
	/// Must be called only if GetMode() == CUSTOMDATATAG_MODE::POLYVERTEX.
	/// @tparam TYPE									The type that will be returned.
	/// @param[in] polygonIndex				The polygon index.
	/// @return												Reference to the PolyData at polygonIndex.
	//----------------------------------------------------------------------------------------
	template <typename TYPE> const maxon::PolyData<TYPE>& GetPolygonData(Int32 polygonIndex) const
	{
		const maxon::PolyData<const void*> data = GetConstPolygonDataPtr(polygonIndex);
		return std::move(maxon::PolyData<TYPE>(*(TYPE*)(data.a), *(TYPE*)(data.b), *(TYPE*)(data.c), *(TYPE*)(data.d)));
	}

	//----------------------------------------------------------------------------------------
	/// Gets a writable PolyData data reference for the given polygonIndex. The specified type must match, otherwise this will crash.
	/// Must be called only if GetMode() == CUSTOMDATATAG_MODE::POLYVERTEX.
	/// @tparam TYPE									The type that will be returned.
	/// @param[in] polygonIndex				The polygon index.
	/// @return												Reference to the PolyData at polygonIndex.
	//----------------------------------------------------------------------------------------
	template <typename TYPE> maxon::Result<maxon::PolyData<TYPE&>> GetPolygonDataRef(Int32 polygonIndex)
	{
		maxon::PolyData<void*> data = GetPolygonDataPtr(polygonIndex);
		return std::move(maxon::PolyData<TYPE>(*(TYPE*)(data.a), *(TYPE*)(data.b), *(TYPE*)(data.c), *(TYPE*)(data.d)));
	}

	//----------------------------------------------------------------------------------------
	/// Sets a polygon data value. The operation always succeeds as the datatype either needs to be
	/// trivially copyable or support move semantics.
	/// Must be called only if GetMode() == CUSTOMDATATAG_MODE::POLYVERTEX.
	/// @tparam TYPE									The type that will be set.
	/// @param[in] polygonIndex				The polygon index.
	/// @param[in] value							The new data values.
	//----------------------------------------------------------------------------------------
	template <typename TYPE> void SetPolygonData(Int32 polygonIndex, maxon::PolyData<TYPE>&& value)
	{
		ifnoerr (TYPE& r = GetPolygonDataRef<TYPE>(polygonIndex))
		{
			r = std::move(value);
			maxon::PolyData<void*> data = GetPolygonDataPtr(polygonIndex);
			for (Int32 i = 0; i < 4; ++i)
			{
				if (data[i])
					*((Int*)data[i]) &= ~1;
			}
		}
	}
};

/// @cond IGNORE

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

class iCustomDataTag;

struct CustomaDataTagLibrary : public C4DLibrary
{
	CustomDataTag*														(*Alloc) 																		(Int32 tagId);
	void 																			(*Free) 																		(CustomDataTag*& p);
	maxon::Result<void> 											(iCustomDataTag::*InitData)									();
	maxon::Result<maxon::CustomDataTagClass>	(iCustomDataTag::*GetCustomDataTagClass)		() const;
	maxon::Result<maxon::DataType>						(iCustomDataTag::*GetDataType)							() const;
	CUSTOMDATATAG_MODE 												(iCustomDataTag::*GetMode)									() const;
	void 																			(iCustomDataTag::*SetMode)									(CUSTOMDATATAG_MODE mode);
	maxon::Result<void> 											(iCustomDataTag::*Resize)										(Int newCount);
	Int 																			(iCustomDataTag::*GetComponentCount)				() const;
	const void*  															(iCustomDataTag::*GetConstVertexDataPtr)		(Int32 vertexIndex) const;
	void* 																		(iCustomDataTag::*GetVertexDataPtr)					(Int32 vertexIndex);
	void  																		(iCustomDataTag::*SetVertexDataPtr)					(void* data, Int32 vertexIndex);
	const void* 															(iCustomDataTag::*GetConstPolyVertexDataPtr)(Int32 polygonIndex, Int32 polyVertexIndex) const;
	void* 																		(iCustomDataTag::*GetPolyVertexDataPtr)			(Int32 polygonIndex, Int32 polyVertexIndex);
	void 																			(iCustomDataTag::*SetPolyVertexDataPtr)			(const void* data, Int32 polygonIndex, Int32 polyVertexIndex);
	const maxon::PolyData<const void*> 				(iCustomDataTag::*GetConstPolygonDataPtr)		(Int32 polygonIndex) const;
	maxon::PolyData<void*>  									(iCustomDataTag::*GetPolygonDataPtr)				(Int32 polygonIndex);
	void 																			(iCustomDataTag::*SetPolygonDataPtr)				(maxon::PolyData<void*> data, Int32 polygonIndex);
	maxon::MeshAttribute  										(iCustomDataTag::*GetVertexAttribute)				(Int32 vertexIndex);
	void 																			(iCustomDataTag::*SetVertexAttribute)				(const maxon::MeshAttribute& data, Int32 vertexIndex);
	maxon::MeshAttribute 											(iCustomDataTag::*GetPolyVertexAttribute)		(Int32 polygonIndex, Int32 polyVertexIndex);
	void 																			(iCustomDataTag::*SetPolyVertexAttribute)		(const maxon::MeshAttribute& data, Int32 polygonIndex, Int32 polyVertexIndex);
	maxon::PolyData<maxon::MeshAttribute> 		(iCustomDataTag::*GetPolygonAttribute)			(Int32 polygonIndex);
	void 																			(iCustomDataTag::*SetPolygonAttribute)			(maxon::PolyData<maxon::MeshAttribute> data, Int32 polygonIndex);

	maxon::Result<void> 											(iCustomDataTag::*DisplayControl)						(BaseDocument* doc, BaseObject* op, BaseDraw* bd, BaseDrawHelp* bh, ControlDisplayStruct& cds);
	maxon::Result<void> 											(iCustomDataTag::*InitDisplayControl)				(BaseDocument* doc, BaseDraw* bd, const AtomArray* active);
	void 																			(iCustomDataTag::*FreeDisplayControl)				();
};

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

/// @endcond

#endif // LIB_CUSTOMDATATAG_H__
