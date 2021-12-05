/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef LIB_HAIR_H__
#define LIB_HAIR_H__

#include "c4d_library.h"

#ifdef __API_INTERN__
#include "pluginobject.h"
#include "plugintag.h"
#include "pluginvideopost.h"
#else
#include "c4d_baseobject.h"
#include "c4d_basetag.h"
#include "c4d_videopost.h"
#endif

/// @addtogroup group_hairlibrary Hair
/// @ingroup group_library
/// @{

class ChainBase;
class HairManager;

/// @addtogroup Hair Type IDs
/// @ingroup group_enumeration
/// @{
#define Ohair						1017305			///< Hair object type ID.
#define Thairselection	1017746			///< Hair selection tag type ID.
#define Thairvertex			1018329			///< Hair vertex tag type ID.
#define VPhair					1017325			///< Hair video post type ID.
#define Mhair						1017730			///< Hair material type ID.
#define Thairmaterial		1017729			///< Hair material tag type ID.
#define Thaircollider		1017326			///< Hair collider tag type ID.
#define Thairtangent		1017671			///< Hair tangent tag type ID.
#define Thairlight			1017874			///< Hair light tag type ID.
/// @}

/// @addtogroup HAIR_ROOT_TYPE
/// @ingroup group_enumeration
/// @{
#define HAIR_ROOT_TYPE_INVALID		-1			///< Invalid root type.
#define HAIR_ROOT_TYPE_NONE				0				///< None root type.
#define HAIR_ROOT_TYPE_VERTEX			1				///< Vertex root type.
#define HAIR_ROOT_TYPE_POLY				2				///< Polygon root type.
#define HAIR_ROOT_TYPE_SEGMENT		3				///< Segment root type.
#define HAIR_ROOT_TYPE_SPLINE2D		4				///< 2D spline root type.
#define HAIR_ROOT_TYPE_SPLINE3D		5				///< 3D spline root type.
#define HAIR_ROOT_TYPE_GUIDES			6				///< Guide root type.
#define HAIR_ROOT_TYPE_NULL				7				///< Null root type.
#define HAIR_ROOT_TYPE_CLONE			8				///< Clone root type.
/// @}

/// @addtogroup HAIR_GENERATE_FLAGS
/// @ingroup group_enumeration
/// @{
#define HAIR_GENERATE_FLAGS_NONE					0							///< None.
#define HAIR_GENERATE_FLAGS_NO_MATERIAL		(1 << 0)			///< No material.
#define HAIR_GENERATE_FLAGS_NO_DYNAMICS		(1 << 1)			///< No dynamics.
#define HAIR_GENERATE_FLAGS_NO_TRANSFORM	(1 << 2)			///< No transformation.
#define HAIR_GENERATE_FLAGS_NO_DEFORMERS	(1 << 3)			///< No deformers.
/// @}

/// @addtogroup HAIR_MODE
/// @ingroup group_enumeration
/// @{
#define HAIR_MODE_LOCKED	-2			///< Locked mode.
#define HAIR_MODE_HIDDEN	-1			///< Hidden mode.

#define HAIR_MODE_TIPS		0				///< Tips mode.
#define HAIR_MODE_POINTS	1				///< Points mode.
#define HAIR_MODE_GUIDES	2				///< Guides mode.
#define HAIR_MODE_ROOTS		3				///< Roots mode.
#define HAIR_MODE_VERTEX	4				///< Vertex mode.
/// @}

/// @addtogroup HAIR_MPARAMETER
/// @ingroup group_enumeration
/// @{
#define HAIR_MPARAMETER_THICKNESS			1			///< ::Float Thickness.
#define HAIR_MPARAMETER_COLOR					2			///< ::Vector Color.
#define HAIR_MPARAMETER_BACKCOLOR			3			///< ::Vector Back color.
#define HAIR_MPARAMETER_TRANSPARENCY	4			///< ::Float Transparency.
/// @}

/// @addtogroup HAIR_LOCK_FLAGS
/// @ingroup group_enumeration
/// @{
#define HAIR_LOCK_FLAGS_ANIMATING			(1 << 2)			///< Animating.
#define HAIR_LOCK_FLAGS_FULL_UPDATE		(1 << 4)			///< Full update.
#define HAIR_LOCK_FLAGS_NO_TRANSFORM	(1 << 5)			///< No transformation.
/// @}

class Neighbor;
class HairGuides;
class HairObject;
class iHairCollider;
class HairColliderData;

struct HairRootData
{
	//----------------------------------------------------------------------------------------
	/// Constructor.
	//----------------------------------------------------------------------------------------
	HairRootData() { m_Type = HAIR_ROOT_TYPE_INVALID; }

	Int32		m_ID,				///< Root ID.
					m_Type;			///< Root type: @enumerateEnum{HAIR_ROOT_TYPE}
	Float		m_S,				///< S parameter.
					m_T;				///< T parameter.
	Vector	m_P,				///< Point.
m_N;
};

struct HairPolygonHit
{
	BaseObject	*m_pObject;			///< Object that was hit.

	Int32				m_gID;					///< Guide ID.
	Int32				m_sID;					///< Segment ID.
	Float				m_sT;						///< Position along segment.

	Int32				m_ID;						///< Polygon index.
	Vector			m_P;						///< Hit point.

	Vector			m_Vin,					///< Velocity in of hit.
							m_Vout;					///< Velocity out of hit.
							Float	m_T;			///< Frame delta of hit.
};

struct RootObjectData
{
	BaseObject			*pObject;						///< Root object.
	BaseTag					*pTag;							///< Root tag.

	Neighbor				*pNeighbor;					///< Neighbor information.

	const Vector		*pPoint;						///< Points.
	const Vector		*pOriginPoints;			///< Original points.

	const CPolygon	*pPolygon;					///< Polygons.
	const Segment		*pSegment;					///< Segments.
};

class HairGuideWeight
{
public:
	//----------------------------------------------------------------------------------------
	/// Constructor.
	//----------------------------------------------------------------------------------------
	HairGuideWeight() { m_Index = NOTOK; m_Weight = 0.0; }

	Int32	m_Index;			///< Index of the guide that this weight refers to. If the index is @ref NOTOK, this entry is not used.
	Float	m_Weight;			///< Weight. A low weight means that this hair is closely tied to the @ref m_Index guide.
};

class HairInterpolationMap
{
	friend class ChainBase;
	friend class HairManager;

public:

	//----------------------------------------------------------------------------------------
	/// Constructor.
	//----------------------------------------------------------------------------------------
	HairInterpolationMap()
	{
		m_pMap = nullptr;
		m_GuideCount = 0;
		m_Count = 0;
		m_WeightCount = 0;
	}

	//----------------------------------------------------------------------------------------
	/// Destructor.
	//----------------------------------------------------------------------------------------
	~HairInterpolationMap()
	{
		Free();
	}

	//----------------------------------------------------------------------------------------
	/// Frees the allocated memory. Called by the destructor.
	//----------------------------------------------------------------------------------------
	void Free()
	{
		DeleteMem(m_pMap);
		m_GuideCount = 0;
		m_Count = 0;
		m_WeightCount = 0;
	}

	//----------------------------------------------------------------------------------------
	/// Gets the hair interpolation map with GetWeightCount() instances of HairGuideWeight for each of the GetHairCount() hairs.\n
	/// @note Not all of these have HairGuideWeight::m_Index set to not @ref NOTOK, so check for that.
	/// @return												The hair interpolation map.
	//----------------------------------------------------------------------------------------
	HairGuideWeight *GetMap() { return m_pMap; }

	//----------------------------------------------------------------------------------------
	/// Retrieves a pointer into the hair interpolation map at the offset for the specified hair @formatParam{index}.
	/// @param[in] index							A hair index: @em 0 <= @formatParam{index} < GetHairCount()
	/// @return												An offset into the hair interpolation map with GetWeightCount() instances for the specified hair.
	//----------------------------------------------------------------------------------------
	HairGuideWeight *GetGuides(Int32 index)
	{
		if (!m_pMap) return nullptr;
		return &m_pMap[index*m_WeightCount];
	}

	//----------------------------------------------------------------------------------------
	/// Gets the number of hairs.
	/// @return												The hair count.
	//----------------------------------------------------------------------------------------
	Int32 GetHairCount() { return m_Count; }

	//----------------------------------------------------------------------------------------
	/// Gets the number of guides.
	/// @return												The guide count.
	//----------------------------------------------------------------------------------------
	Int32 GetGuideCount() { return m_GuideCount; }

	//----------------------------------------------------------------------------------------
	/// Gets the maximum number of weights per hair in the interpolation map array, not necessarily used all of them.
	/// @return												The maximum number of weights per hair.
	//----------------------------------------------------------------------------------------
	Int32 GetWeightCount() { return m_WeightCount; }

	//----------------------------------------------------------------------------------------
	/// Gets the total weight for the specified hair @formatParam{index}.
	/// @param[in] index							A hair index: @em 0 <= @formatParam{index} < GetHairCount()
	/// @return												The sum of all active weights for the specified hair.
	//----------------------------------------------------------------------------------------
	Float64 GetTotalWeight(Int32 index);

	//----------------------------------------------------------------------------------------
	/// Gets the total inverse weight for the specified hair @formatParam{index}.
	/// @param[in] index							A hair index: @em 0 <= @formatParam{index} < GetHairCount()
	/// @return												The sum of the inverse of all active weights for the specified hair.
	//----------------------------------------------------------------------------------------
	Float64 GetTotalInvWeight(Int32 index);

	//----------------------------------------------------------------------------------------
	/// Interpolates ::Float32 values for the specified hair @formatParam{index} using the information in the hair interpolation map.
	/// @param[in] index							A hair index: @em 0 <= @formatParam{index} < GetHairCount()
	/// @param[in] v									An array with GetWeightCount() elements for each of the possible guides of the specified hair.
	/// @return												The interpolation result.
	//----------------------------------------------------------------------------------------
	Float32 GetInterpolateReal(Int32 index, Float32 *v);

	//----------------------------------------------------------------------------------------
	/// Interpolates ::Float64 values for the specified hair @formatParam{index} using the information in the hair interpolation map.
	/// @param[in] index							A hair index: @em 0 <= @formatParam{index} < GetHairCount()
	/// @param[in] v									An array with GetWeightCount() elements for each of the possible guides of the specified hair.
	/// @return												The interpolation result.
	//----------------------------------------------------------------------------------------
	Float64 GetInterpolateReal(Int32 index, Float64 *v);

	//----------------------------------------------------------------------------------------
	/// Interpolates ::Vector32 values for the specified hair @formatParam{index} using the information in the hair interpolation map.
	/// @param[in] index							A hair index: @em 0 <= @formatParam{index} < GetHairCount()
	/// @param[in] v									An array with GetWeightCount() elements for each of the possible guides of the specified hair.
	/// @return												The interpolation result.
	//----------------------------------------------------------------------------------------
	Vector32 GetInterpolatedVector(Int32 index, Vector32 *v);

	//----------------------------------------------------------------------------------------
	/// Interpolates ::Vector64 values for the specified hair @formatParam{index} using the information in the hair interpolation map.
	/// @param[in] index							A hair index: @em 0 <= @formatParam{index} < GetHairCount()
	/// @param[in] v									An array with GetWeightCount() elements for each of the possible guides of the specified hair.
	/// @return												The interpolation result.
	//----------------------------------------------------------------------------------------
	Vector64 GetInterpolatedVector(Int32 index, Vector64 *v);

private:

	HairGuideWeight *m_pMap;

	Int32 m_WeightCount;
	Int32 m_GuideCount;
	Int32 m_Count;
};

//----------------------------------------------------------------------------------------
/// Contains information about hair materials. Cannot be allocated.
//----------------------------------------------------------------------------------------
class HairMaterialData
{
private:
	HairMaterialData();
	~HairMaterialData();
public:

	//----------------------------------------------------------------------------------------
	/// Gets the number of hair material tags.
	/// @return												The hair material count.
	//----------------------------------------------------------------------------------------
	Int32 GetCount();

	//----------------------------------------------------------------------------------------
	/// Gets the material index for the specified hair index @formatParam{i}, optionally looking for more materials by specifying @formatParam{prev}.
	/// @param[in] i									The hair index.
	/// @param[in] prev								The index of the previous material of the hair.
	/// @return												The material index, or @ref NOTOK if there are no more materials for the hair.
	//----------------------------------------------------------------------------------------
	Int32 GetGuideMaterial(Int32 i, Int32 prev = NOTOK);

	//----------------------------------------------------------------------------------------
	/// Gets the material tag corresponding to the specified hair index @formatParam{i}.
	/// @param[in] i									The hair index.
	/// @return												The material tag.
	//----------------------------------------------------------------------------------------
	BaseTag *GetMaterialTag(Int32 i);

	//----------------------------------------------------------------------------------------
	/// Applies a single material to the specified hair index @formatParam{i}.
	/// @param[in] i									The hair index.
	/// @param[in] guides							The hair guide data.
	/// @param[in] vd									The optional volume data.
	/// @param[in] vindex							The material index.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool ApplyMaterial(Int32 i, HairGuides *guides, VolumeData *vd = nullptr, Int32 vindex = 0);

	//----------------------------------------------------------------------------------------
	/// Applies a material to all hairs.
	/// @param[in] guides							The hair guide data.
	/// @param[in] vd									The optional volume data.
	/// @param[in] vindex							The material index.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool ApplyMaterials(HairGuides *guides, VolumeData *vd = nullptr, Int32 vindex = 0);

	//----------------------------------------------------------------------------------------
	/// Gets the thickness at position @formatParam{t} along the specified @formatParam{guide}.
	/// @param[in] guide							The guide/hair index.
	/// @param[in] t									The position along guide/hair: @em 0 <= @formatParam{t} <= @em 1
	/// @param[in] i									Pass @ref NOTOK to use all materials, or a specific material index.
	/// @return												The thickness.
	//----------------------------------------------------------------------------------------
	Float GetThickness(Int32 guide, Float t, Int32 i = NOTOK);

	//----------------------------------------------------------------------------------------
	/// Gets the color at position @formatParam{t} along the specified @formatParam{guide}.
	/// @param[in] guide							The guide/hair index.
	/// @param[in] t									The position along guide/hair: @em 0 <= @formatParam{t} <= @em 1
	/// @param[in] r									The root world coordinate.
	/// @param[in] wp									The world coordinate of the sampling point.
	/// @param[in] p									The UV coordinate.
	/// @param[in] n									The surface normal at the root.
	/// @param[in] vd									The volume data. Can be @formatConstant{nullptr}.
	/// @param[in] plyid							The global RayHitID for the root.
	/// @param[in] i									Pass @ref NOTOK to use all materials, or a specific material index.
	/// @return												The color.
	//----------------------------------------------------------------------------------------
	Vector GetColor(Int32 guide, Float t, const Vector &r, const Vector &wp, const Vector &p, const Vector &n, VolumeData *vd, const RayHitID &plyid, Int32 i = NOTOK);

	//----------------------------------------------------------------------------------------
	/// Gets the back color at position @formatParam{t} along the specified @formatParam{guide}.
	/// @param[in] guide							The guide/hair index.
	/// @param[in] t									The position along guide/hair: @em 0 <= @formatParam{t} <= @em 1
	/// @param[in] col								The color.
	/// @param[in] r									The root world coordinate.
	/// @param[in] wp									The world coordinate of the sampling point.
	/// @param[in] p									The UV coordinate.
	/// @param[in] n									The surface normal at the root.
	/// @param[in] vd									The volume data. Can be @formatConstant{nullptr}.
	/// @param[in] plyid							The global RayHitID for the root.
	/// @param[in] i									Pass @ref NOTOK to use all materials, or a specific material index.
	/// @return												The back color.
	//----------------------------------------------------------------------------------------
	Vector GetBackColor(Int32 guide, Float t, const Vector &col, const Vector &r, const Vector &wp, const Vector &p, const Vector &n, VolumeData *vd, const RayHitID &plyid, Int32 i = NOTOK);

	//----------------------------------------------------------------------------------------
	/// Gets the specular color at position @formatParam{t} along the specified @formatParam{guide}.
	/// @param[in] guide							The guide/hair index.
	/// @param[in] t									The position along guide/hair: @em 0 <= @formatParam{t} <= @em 1
	/// @param[in] wp									The world coordinate of the sampling point.
	/// @param[in] p									The UV coordinate.
	/// @param[in] n									The surface normal at the root.
	/// @param[in] vd									The volume data. Can be @formatConstant{nullptr}.
	/// @param[in] plyid							The global RayHitID for the root.
	/// @param[out] speccol						Assigned the primary specular color.
	/// @param[out] ispeccol					Assigned the secondary specular color.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool GetSpecularColor(Int32 guide, Float t, const Vector &wp, const Vector &p, const Vector &n, VolumeData *vd, const RayHitID &plyid, Vector &speccol, Vector &ispeccol);

	//----------------------------------------------------------------------------------------
	/// Gets the transparency at position @formatParam{t} along the specified @formatParam{guide}.
	/// @param[in] guide							The guide/hair index.
	/// @param[in] t									The position along guide/hair: @em 0 <= @formatParam{t} <= @em 1
	/// @param[in] p									The UV coordinate.
	/// @param[in] n									The surface normal at the root.
	/// @param[in] vd									The volume data. Can be @formatConstant{nullptr}.
	/// @param[in] i									Pass @ref NOTOK to use all materials, or a specific material index.
	/// @return												The transparency.
	//----------------------------------------------------------------------------------------
	Float GetTransparency(Int32 guide, Float t, const Vector &p, const Vector &n, VolumeData* vd, Int32 i = NOTOK);

	//----------------------------------------------------------------------------------------
	/// Finds out which guides the specified material index @formatParam{i} is applied to.
	/// @param[in] i									The material index.
	/// @param[out] bs								Filled with the guide indices the material is applied to.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool GetTagSelection(Int32 i, BaseSelect *bs);

	//----------------------------------------------------------------------------------------
	/// Gets the settings of the hair material.
	/// @param[in] guide							The guide/hair index.
	/// @param[out] shadows						Assigned the shadows strength.
	/// @param[out] selfshadows				Assigned the self shadows strength.
	/// @param[out] backshadows				Assigned the back shadows strength.
	/// @param[out] transparency			Assigned the transparency strength.
	/// @param[out] diffuse						Assigned the diffuse value.
	/// @param[out] reflect						Assigned the reflectiveness strength.
	/// @param[out] transmit					Assigned the translucence strength.
	/// @param[out] roughenable				Assigned roughness on/off state.
	/// @param[out] roughvar					Assigned the roughness variation strength.
	/// @param[out] roughness					Assigned the roughness strength.
	/// @param[out] specularenable		Assigned the primary specular on/off state.
	/// @param[out] specular					Assigned the primary specular strength.
	/// @param[out] specularpower			Assigned the primary specular sharpness strength.
	/// @param[out] specularback			Assigned the back specular strength.
	/// @param[out] ispecularenable		Assigned the secondary specular on/off state.
	/// @param[out] ispecularshader		Assigned the secondary specular shader on/off state.
	/// @param[out] ispecular					Assigned the secondary specular strength.
	/// @param[out] ispecularpower		Assigned the secondary specular sharpness strength.
	/// @param[out] ispecularmix			Assigned the secondary specular mix strength.
	/// @param[out] ispecularblend		Assigned the secondary specular blend strength.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool GetMaterialData(Int32 guide, Float &shadows, Float &selfshadows, Float &backshadows, Float &transparency, Float &diffuse, Float &reflect, Float &transmit, Bool &roughenable, Float &roughvar, Float &roughness, Bool &specularenable, Float &specular, Float &specularpower, Float &specularback, Bool &ispecularenable, Bool &ispecularshader, Float &ispecular, Float &ispecularpower, Float &ispecularmix, Float &ispecularblend);

	//----------------------------------------------------------------------------------------
	/// Gets the Global Illumination (GI) settings of the hair material.
	/// @param[in] guide							The guide/hair index.
	/// @param[out] receive						Assigned the receive GI on/off state.
	/// @param[out] strength					Assigned the receive GI strength.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool GetGIData(Int32 guide, Bool &receive, Float &strength);

	//----------------------------------------------------------------------------------------
	/// Gets the hair UVs for a specified Hair guide and position along the guide.
	/// @param[in] guide							The guide/hair index.
	/// @param[out] huv								Assigned the Hair UV coordinates.
	/// @param[in] tline							The position along the hair: @em 0 <= @formatParam{tline} <= @em 1.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool AdjustHUV(Int32 guide, Vector &huv, Float tline);
};

//----------------------------------------------------------------------------------------
/// Contains hair dynamics information. Cannot be allocated.
//----------------------------------------------------------------------------------------
class HairGuideDynamics
{
private:
	HairGuideDynamics();
	~HairGuideDynamics();
public:
	//----------------------------------------------------------------------------------------
	/// Gets the corresponding hair guide data.
	/// @return												The hair guide data.
	//----------------------------------------------------------------------------------------
	HairGuides *GetGuides();

	//----------------------------------------------------------------------------------------
	/// Gets the position of the specified guide @formatParam{i}.
	/// @param[in] i									The guide index.
	/// @return												The position.
	//----------------------------------------------------------------------------------------
	Vector GetPosition(Int32 i);

	//----------------------------------------------------------------------------------------
	/// Sets the position of the specified guide @formatParam{i}.
	/// @param[in] i									The guide index.
	/// @param[in] p									The new position.
	//----------------------------------------------------------------------------------------
	void SetPosition(Int32 i, const Vector &p);

	//----------------------------------------------------------------------------------------
	/// Gets the last position of the specified guide @formatParam{i}.
	/// @param[in] i									The guide index.
	/// @return												The last position.
	//----------------------------------------------------------------------------------------
	Vector GetLastPosition(Int32 i);

	//----------------------------------------------------------------------------------------
	/// Sets the last position of the specified guide @formatParam{i}.
	/// @param[in] i									The guide index.
	/// @param[in] p									The new last position.
	//----------------------------------------------------------------------------------------
	void SetLastPosition(Int32 i, const Vector &p);

	//----------------------------------------------------------------------------------------
	/// Gets the velocity of the specified guide @formatParam{i}.
	/// @param[in] i									The guide index.
	/// @return												The velocity.
	//----------------------------------------------------------------------------------------
	Vector GetVelocity(Int32 i);

	//----------------------------------------------------------------------------------------
	/// Sets the velocity of the specified guide @formatParam{i}.
	/// @param[in] i									The guide index.
	/// @param[in] v									The new velocity.
	//----------------------------------------------------------------------------------------
	void SetVelocity(Int32 i, const Vector &v);

	//----------------------------------------------------------------------------------------
	/// Gets the mass of the specified guide @formatParam{i}.
	/// @param[in] i									The guide index.
	/// @return												The mass.
	//----------------------------------------------------------------------------------------
	Float GetMass(Int32 i);

	//----------------------------------------------------------------------------------------
	/// Sets the mass of the specified guide @formatParam{i}.
	/// @param[in] i									The guide index.
	/// @param[in] m									The new mass.
	//----------------------------------------------------------------------------------------
	void SetMass(Int32 i, Float m);

	//----------------------------------------------------------------------------------------
	/// Gets the force of the specified guide @formatParam{i}.
	/// @param[in] i									The guide index.
	/// @return												The force.
	//----------------------------------------------------------------------------------------
	Vector GetForce(Int32 i);

	//----------------------------------------------------------------------------------------
	/// Adds the force of the specified guide @formatParam{i}.
	/// @param[in] i									The guide index.
	/// @param[in] f									The force to add.
	//----------------------------------------------------------------------------------------
	void AddForce(Int32 i, const Vector &f);

	//----------------------------------------------------------------------------------------
	/// Gets the polygon intersection data.
	/// @param[out] hits							Filled with a pointer to an array of polygon hits. Need to be freed with DeleteMem() by the caller.
	/// @return												The number of hits or @ref NOTOK if an error occurred.
	//----------------------------------------------------------------------------------------
	Int32 GetPolygonIntersections(HairPolygonHit **hits);
};

/// @addtogroup HAIR_GUIDE_FLAGS
/// @ingroup group_enumeration
/// @{
#define HAIR_GUIDE_FLAGS_LOCAL				(1 << 0)			///< Chains are in local object space
#define HAIR_GUIDE_FLAGS_AS_GUIDES		(1 << 1)			///< Special case guides.
#define HAIR_GUIDE_FLAGS_INITIAL			(1 << 3)			///< Chains are in their original initial space (like a pin material tag).
#define HAIR_GUIDE_FLAGS_HAIRS				(1 << 4)			///< Created for hairs.
#define HAIR_GUIDE_FLAGS_INITIALAXIS	(1 << 6)			///< Initial space and root axis aligned.
/// @}

//----------------------------------------------------------------------------------------
/// Helper class for guides/hair.
/// @addAllocFreeAutoAllocNote
//----------------------------------------------------------------------------------------
class HairGuides
{
private:
	HairGuides();
	~HairGuides();
public:

	//----------------------------------------------------------------------------------------
	/// @allocatesA{hair guides helper}
	/// @param[in] count							The number of guides.
	/// @param[in] segments						The number of segments per guide.
	/// @return												@allocReturn{hair guides helper}
	//----------------------------------------------------------------------------------------
	static HairGuides *Alloc(Int32 count, Int32 segments);

	//----------------------------------------------------------------------------------------
	/// @destructsAlloc{hair guides helpers}
	/// @param[in,out] guides					@theToDestruct{hair guides helper}
	//----------------------------------------------------------------------------------------
	static void Free(HairGuides *&guides);

	//----------------------------------------------------------------------------------------
	/// Gets the number of guides.
	/// @return												The guide count.
	//----------------------------------------------------------------------------------------
	Int32 GetCount();

	//----------------------------------------------------------------------------------------
	/// Gets the number of segments per guide.
	/// @note The number of points is GetSegmentCount() + @em 1.
	/// @return												The segment count.
	//----------------------------------------------------------------------------------------
	Int32 GetSegmentCount();

	//----------------------------------------------------------------------------------------
	/// Gets the total number of points for all guides.
	/// @return												The point count.
	//----------------------------------------------------------------------------------------
	Int32 GetPointCount() { return GetCount()*GetGuidePointCount(); }

	//----------------------------------------------------------------------------------------
	/// Gets the number of points per segment i.e. GetSegmentCount() + @em 1.
	/// @return												The number of points per segment.
	//----------------------------------------------------------------------------------------
	Int32 GetGuidePointCount() { Int32 s = GetSegmentCount(); return (s == 0)?0:(s+1); }

	//----------------------------------------------------------------------------------------
	/// Retrieves a pointer to the point vectors for the guides.
	/// @return												The points array.
	//----------------------------------------------------------------------------------------
	Vector *GetPoints();

	//----------------------------------------------------------------------------------------
	/// Gets the dynamics.
	/// @return												The dynamics. Can be @formatConstant{nullptr}.
	//----------------------------------------------------------------------------------------
	HairGuideDynamics *GetDynamics();

	//----------------------------------------------------------------------------------------
	/// Gets the global matrix.
	/// @return												The global matrix.
	//----------------------------------------------------------------------------------------
	Matrix GetMg();

	//----------------------------------------------------------------------------------------
	/// Sets the global matrix.
	/// @param[in] mg									The new global matrix.
	//----------------------------------------------------------------------------------------
	void SetMg(const Matrix &mg);

	//----------------------------------------------------------------------------------------
	/// Gets the root data for the specified guide @formatParam{index}.
	/// @param[in] index							The guide index: @em 0 <= @formatParam{index} < GetCount()
	/// @return												The root data.
	//----------------------------------------------------------------------------------------
	HairRootData GetRoot(Int32 index);

	//----------------------------------------------------------------------------------------
	/// Sets the root data for the specified guide @formatParam{index}.
	/// @param[in] index							The guide index: @em 0 <= @formatParam{index} < GetCount()
	/// @param[in] root								The new root data.
	/// @param[in] update							If @formatConstant{true} then an update is made.
	//----------------------------------------------------------------------------------------
	void SetRoot(Int32 index, const HairRootData &root, Bool update);

	//----------------------------------------------------------------------------------------
	/// Gets the corresponding hair object.
	/// @return												The hair object.
	//----------------------------------------------------------------------------------------
	HairObject *GetObject();

	//----------------------------------------------------------------------------------------
	/// Gets the selection state.
	/// @param[in] mode								The selection mode: @enumerateEnum{HAIR_MODE}
	/// @param[out] select						Assigned the selection.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool GetSelected(Int32 mode, BaseSelect *select);

	//----------------------------------------------------------------------------------------
	/// Sets the selection state.
	/// @param[in] mode								The selection mode: @enumerateEnum{HAIR_MODE}
	/// @param[out] select						The new selection.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool SetSelected(Int32 mode, BaseSelect *select);

	//----------------------------------------------------------------------------------------
	/// Converts selection state.
	/// @param[in] from_mode					The source selection mode: @enumerateEnum{HAIR_MODE}
	/// @param[in] to_mode						The destination selection mode: @enumerateEnum{HAIR_MODE}
	/// @param[in] from_select				The source selection.
	/// @param[out] to_select					The destination selection.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool ConvertSelection(Int32 from_mode, Int32 to_mode, BaseSelect *from_select, BaseSelect *to_select);

	//----------------------------------------------------------------------------------------
	/// Copies the guide data from @formatParam{src}.
	/// @param[in] src								The source hair guides helper.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool CopyFrom(const HairGuides *src);

	//----------------------------------------------------------------------------------------
	/// Gets the tangent of @formatParam{guide} at @formatParam{segment} and @formatParam{t}.
	/// @param[in] guide							The guide index: @em 0 <= @formatParam{guide} < GetCount()
	/// @param[in] segment						The segment index: @em 0 <= @formatParam{segment} < GetSegmentCount()
	/// @param[in] t									The T coordinate.
	/// @return												The tangent.
	//----------------------------------------------------------------------------------------
	Vector GetTangent(Int32 guide, Int32 segment, Float t);

	//----------------------------------------------------------------------------------------
	/// Creates splines from the guides.
	/// @return												The created spline object.
	//----------------------------------------------------------------------------------------
	SplineObject *CreateSpline();

	//----------------------------------------------------------------------------------------
	/// Changes all the points for the guides into a local coordinate system.
	//----------------------------------------------------------------------------------------
	void ToLocal();

	//----------------------------------------------------------------------------------------
	/// Changes all the points for the guides into the world coordinate system.
	//----------------------------------------------------------------------------------------
	void ToWorld();

	//----------------------------------------------------------------------------------------
	/// Changes the coordinate space and transforms the points back to their initial state.\n
	/// This is useful when applying coordinate Dependant changes to the points, by moving them back to an initial state the changes are not affecting when the guide roots move due to animation.
	/// @param[in] align							If @formatConstant{true} the guides are rotated from their root back to their initial orientation.
	//----------------------------------------------------------------------------------------
	void ToInitial(Bool align);

	//----------------------------------------------------------------------------------------
	/// Used when HNs have affected the guide roots. Call DisplaceRoots() and it will ensure they are in the correct displaced state for HNs, UndisplaceRoots() will make sure they are not.\n
	/// Generally not needed if using ToInitial(), as the initial state is undisplaced.
	//----------------------------------------------------------------------------------------
	void DisplaceRoots();

	//----------------------------------------------------------------------------------------
	/// @see DisplaceRoots()
	//----------------------------------------------------------------------------------------
	void UndisplaceRoots();

	//----------------------------------------------------------------------------------------
	/// Gets the root axis of guide @formatParam{index}.
	/// @param[in] index							The guide index: @em 0 <= @formatParam{index} < GetCount()
	/// @param[out] m									Filled with the root axis.
	/// @param[in] bAlign							Aligned.
	/// @param[in] bLocal							Local.
	/// @param[in] bInitial						Initial.
	/// @param[in] bZAxis							If @formatConstant{true} then the alignment is done along the Z axis, otherwise it is Y.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool GetRootAxis(Int32 index, Matrix &m, Bool bAlign = false, Bool bLocal = true, Bool bInitial = false, Bool bZAxis = false);

	//----------------------------------------------------------------------------------------
	/// Gets the root UV for guide @formatParam{index}.
	/// @param[in] index							The guide index: @em 0 <= @formatParam{index} < GetCount()
	/// @return												The root UV.
	//----------------------------------------------------------------------------------------
	Vector GetRootUV(Int32 index);

	//----------------------------------------------------------------------------------------
	/// Gets the root data.
	/// @param[in] index							The guide index: @em 0 <= @formatParam{index} < GetCount()
	/// @param[out] p									Assigned the point.
	/// @param[out] n									Assigned the normal.
	/// @param[out] ply_id						Assigned the polygon ID..
	/// @param[in] bLocal							Local.
	/// @param[in] bDisplaced					Displaced.
	/// @param[in] bInitial						Initial.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool GetRootData(Int32 index, Vector *p = nullptr, Vector *n = nullptr, Int32 *ply_id = nullptr, Bool bLocal = true, Bool bDisplaced = true, Bool bInitial = false);

	//----------------------------------------------------------------------------------------
	/// Gets the transformation matrix array.
	/// @return												The transformation matrix array. Each matrix element is an axis at the root of each guide.\n
	/// 															Needs to be freed with DeleteMem() afterwards.
	//----------------------------------------------------------------------------------------
	Matrix *GetTransformMatrix();

	//----------------------------------------------------------------------------------------
	/// Sets a new array of transformation matrices.
	/// @param[in] tm									The new transformation matrix array. Each matrix element is an axis at the root of each guide.
	//----------------------------------------------------------------------------------------
	void SetTransformMatrix(Matrix *tm);

	//----------------------------------------------------------------------------------------
	/// Deletes the guide selection.
	/// @param[out] bs								The selection to delete.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool Delete(BaseSelect *bs);

	//----------------------------------------------------------------------------------------
	/// Adds a root.
	/// @note Invalidates any pointers or arrays returned before as the guides will have changed.
	/// @param[in] ply_id							The polygon ID.
	/// @param[in] s									The S coordinate.
	/// @param[in] t									The T coordinate.
	/// @param[in] len								The length.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool AddRoot(Int32 ply_id, Float s, Float t, Float len);

	//----------------------------------------------------------------------------------------
	/// Gets the root object data.
	/// @param[out] pData							Filled with the root object data.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool GetRootObject(RootObjectData *pData);

	//----------------------------------------------------------------------------------------
	/// Links this to a specific HairObject.
	/// @param[in] pHair							A hair object.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool LinkToObject(HairObject *pHair);

	//----------------------------------------------------------------------------------------
	/// Gets the flags.
	/// @return												The flags: @enumerateEnum{HAIR_GUIDE_FLAGS}
	//----------------------------------------------------------------------------------------
	Int32 GetFlags();

	//----------------------------------------------------------------------------------------
	/// Sets the flags.
	/// @param[in] flags							The new flags: @enumerateEnum{HAIR_GUIDE_FLAGS}
	/// @return												The old flags.
	//----------------------------------------------------------------------------------------
	Int32 SetFlags(Int32 flags);
};

//----------------------------------------------------------------------------------------
/// Hair object.
/// @addAllocFreeAutoAllocNote
//----------------------------------------------------------------------------------------
class HairObject : public BaseObject
{
#ifndef __API_INTERN__
private:
	HairObject();
	~HairObject();
public:
	//----------------------------------------------------------------------------------------
	/// @allocatesA{hair object}
	/// @return												@allocReturn{hair object}
	//----------------------------------------------------------------------------------------
	static HairObject *Alloc() { return (HairObject*)BaseObject::Alloc(Ohair); }

	//----------------------------------------------------------------------------------------
	/// @destructsAlloc{hair objects}
	/// @param[in,out] pObject				@theToDestruct{hair object}
	//----------------------------------------------------------------------------------------
	static void Free(HairObject *&pObject) { BaseObject *op = pObject; BaseObject::Free(op); pObject = nullptr; }

	//----------------------------------------------------------------------------------------
	/// Locks the hair object.
	/// @param[in] pDoc								The document.
	/// @param[in] pThread						The thread.
	/// @param[in] bValidate					Validate the lock.
	/// @param[in] flags							Lock flags: @enumerateEnum{HAIR_LOCK_FLAGS}
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool Lock(BaseDocument *pDoc, BaseThread *pThread, Bool bValidate, Int32 flags);

	//----------------------------------------------------------------------------------------
	/// Checks if the hair object is locked.
	/// @return												@trueIfOtherwiseFalse{the hair object is locked}
	//----------------------------------------------------------------------------------------
	Bool IsLocked();

	//----------------------------------------------------------------------------------------
	/// Unlocks the hair object.
	//----------------------------------------------------------------------------------------
	void Unlock();

#else
public:
#endif

	//----------------------------------------------------------------------------------------
	/// Gets the guides of the hair object.
	/// @return												The guides.
	//----------------------------------------------------------------------------------------
	HairGuides *GetGuides();

	//----------------------------------------------------------------------------------------
	/// Gets the dynamic guides of the hair object.
	/// @return												The dynamic guides.
	//----------------------------------------------------------------------------------------
	HairGuides *GetDynamicGuides();

	//----------------------------------------------------------------------------------------
	/// Generates hair for the hair object.
	/// @param[in] flags							The generate flags: @enumerateEnum{HAIR_GENERATE_FLAGS}
	/// @param[in] count							The hair count.
	/// @param[in] segments						The segments.
	/// @param[out] pMaterial					Filled with material data if not @formatConstant{nullptr}.
	/// @param[in] pMap								Optional hair interpolation map.
	/// @return												The generated hair.
	//----------------------------------------------------------------------------------------
	HairGuides *GenerateHair(Int32 flags = HAIR_GENERATE_FLAGS_NONE, Int32 count = NOTOK, Int32 segments = NOTOK, HairMaterialData **pMaterial = nullptr, HairInterpolationMap *pMap = nullptr);

	//----------------------------------------------------------------------------------------
	/// Gets the root object for the hair object.
	/// @param[out] pObject						Assigned the root object.
	/// @param[out] pTag							Assigned the tag.
	/// @param[out] pData							Assigned the root object data.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool GetRootObject(BaseObject **pObject, BaseTag **pTag, RootObjectData *pData);

	//----------------------------------------------------------------------------------------
	/// Sets guides for the hair object.
	/// @param[in] guides							The guides to set.
	/// @param[in] clone							@formatConstant{true} to clone the supplied guides.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool SetGuides(HairGuides *guides, Bool clone);

	//----------------------------------------------------------------------------------------
	/// Removes the guides of the hair object.
	//----------------------------------------------------------------------------------------
	void RemoveGuides();

	//----------------------------------------------------------------------------------------
	/// Updates the hair object.
	/// @note Do not use within a Lock().
	/// @param[in] doc								The document.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool Update(BaseDocument *doc);

	//----------------------------------------------------------------------------------------
	/// Initializes materials.
	/// @param[in] irs								Optional InitRenderStruct.
	/// @param[in] pDoc								The document.
	/// @param[in] guides							Optional guide data.
	/// @param[in] vd									Optional VolumeData.
	/// @return												The initialized material data.
	//----------------------------------------------------------------------------------------
	HairMaterialData *InitMaterials(const InitRenderStruct &irs, BaseDocument *pDoc, HairGuides *guides = nullptr, VolumeData *vd = nullptr);

	//----------------------------------------------------------------------------------------
	/// Frees materials.
	/// @param[in,out] pMaterials			The material data to free.
	//----------------------------------------------------------------------------------------
	void FreeMaterials(HairMaterialData *&pMaterials);
};

//----------------------------------------------------------------------------------------
/// Hair vertex map tag.
/// @addAllocFreeAutoAllocNote
//----------------------------------------------------------------------------------------
class HairVertexMapTag : public BaseTag
{
#ifndef __API_INTERN__
private:
	HairVertexMapTag();
	~HairVertexMapTag();
public:
	//----------------------------------------------------------------------------------------
	/// @allocatesA{hair vertex map tag}
	/// @return												@allocReturn{hair vertex map tag}
	//----------------------------------------------------------------------------------------
	static HairVertexMapTag *Alloc() { return (HairVertexMapTag*)BaseTag::Alloc(Thairvertex); }

	//----------------------------------------------------------------------------------------
	/// @destructsAlloc{hair vertex map tags}
	/// @param[in,out] pTag						@theToDestruct{hair vertex map tag}
	//----------------------------------------------------------------------------------------
	static void Free(HairVertexMapTag *&pTag) { BaseTag *tag = pTag; BaseTag::Free(tag); pTag = nullptr; }
#else
public:
#endif

	//----------------------------------------------------------------------------------------
	/// Gets the hair count.
	/// @return												The hair count.
	//----------------------------------------------------------------------------------------
	Int32 GetCount();

	//----------------------------------------------------------------------------------------
	/// Gets the segments count.
	/// @return												The segments count.
	//----------------------------------------------------------------------------------------
	Int32 GetSegments();

	//----------------------------------------------------------------------------------------
	/// Gets the point count.
	/// @return												The point count.
	//----------------------------------------------------------------------------------------
	Int32 GetPointCount();

	//----------------------------------------------------------------------------------------
	/// Gets the vertex map.
	/// @return												The vertex map. To get the real value, divide by @em 65535.
	//----------------------------------------------------------------------------------------
	UInt16 *GetMap();
};

//----------------------------------------------------------------------------------------
/// Hair selection tag.
/// @addAllocFreeAutoAllocNote
//----------------------------------------------------------------------------------------
class HairSelectionTag : public BaseTag
{
#ifndef __API_INTERN__
private:
	HairSelectionTag();
	~HairSelectionTag();

public:
	//----------------------------------------------------------------------------------------
	/// @allocatesA{hair selection tag}
	/// @return												@allocReturn{hair selection tag}
	//----------------------------------------------------------------------------------------
	static HairSelectionTag *Alloc() { return (HairSelectionTag*)BaseTag::Alloc(Thairselection); }

	//----------------------------------------------------------------------------------------
	/// @destructsAlloc{hair selection tag}
	/// @param[in,out] pTag						@theToDestruct{hair selection tag}
	//----------------------------------------------------------------------------------------
	static void Free(HairSelectionTag *&pTag) { BaseTag *tag = pTag; BaseTag::Free(tag); pTag = nullptr; }
#else
public:
#endif

	//----------------------------------------------------------------------------------------
	/// Gets the selection.
	/// @param[out] bs								Filled with the current selection.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool GetSelected(BaseSelect *bs);

	//----------------------------------------------------------------------------------------
	/// Sets the selection.
	/// @param[in] bs									The new selection.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool SetSelected(BaseSelect *bs);

	//----------------------------------------------------------------------------------------
	/// Gets the selection type.
	/// @return												The selection mode: @enumerateEnum{HAIR_MODE}
	//----------------------------------------------------------------------------------------
	Int32 GetSelectionType();

	//----------------------------------------------------------------------------------------
	/// Sets the selection type.
	/// @param[in] mode								The new selection mode: @enumerateEnum{HAIR_MODE}
	//----------------------------------------------------------------------------------------
	void SetSelectionType(Int32 mode);

	//----------------------------------------------------------------------------------------
	/// Gets the count.
	/// @return												The number of elements.
	//----------------------------------------------------------------------------------------
	Int32 GetCount();

	//----------------------------------------------------------------------------------------
	/// Gets the segment count.
	/// @return												The number of segments.
	//----------------------------------------------------------------------------------------
	Int32 GetSegments();
};

//----------------------------------------------------------------------------------------
/// Hair tangent tag.
/// @addAllocFreeAutoAllocNote
//----------------------------------------------------------------------------------------
class HairTangentTag : public BaseTag
{
#ifndef __API_INTERN__
private:
	HairTangentTag();
	~HairTangentTag();
public:
	//----------------------------------------------------------------------------------------
	/// @allocatesA{hair tangent tag}
	/// @return												@allocReturn{hair tangent tag}
	//----------------------------------------------------------------------------------------
	static HairTangentTag *Alloc() { return (HairTangentTag*)BaseTag::Alloc(Thairtangent); }

	//----------------------------------------------------------------------------------------
	/// @destructsAlloc{hair tangent tag}
	/// @param[in,out] pTag						@theToDestruct{hair tangent tag}
	//----------------------------------------------------------------------------------------
	static void Free(HairTangentTag *&pTag) { BaseTag *tag = pTag; BaseTag::Free(tag); pTag = nullptr; }
#else
public:
#endif

	//----------------------------------------------------------------------------------------
	/// Gets the number of polygon segments.
	/// @return												The number of polygons segments.
	//----------------------------------------------------------------------------------------
	Int32 GetPolygonsSegments();

	//----------------------------------------------------------------------------------------
	/// Gets the number of points.
	/// @return												The number of points.
	//----------------------------------------------------------------------------------------
	Int32 GetPointCount();

	//----------------------------------------------------------------------------------------
	/// Gets the number of tangents.
	/// @return												The number of tangents.
	//----------------------------------------------------------------------------------------
	Int32 GetCount();

	//----------------------------------------------------------------------------------------
	/// Gets the number of segments.
	/// @return												The number of segments.
	//----------------------------------------------------------------------------------------
	Int32 GetSegments();

	//----------------------------------------------------------------------------------------
	/// Gets the tangent array.
	/// @return												The tangent array.
	//----------------------------------------------------------------------------------------
	Vector *GetTangent();
};

class HairRenderObject
{
public:
	//----------------------------------------------------------------------------------------
	/// Default constructor.
	/// @since R17.032
	//----------------------------------------------------------------------------------------
	HairRenderObject()
	{
		m_pGuideObject		= nullptr;
		m_pHairObject			= nullptr;
		m_pHair						= nullptr;
		m_pBase						= nullptr;
		m_pRayObject			= nullptr;
		m_pRayObjectHair	= nullptr;
		m_pMaterial				= nullptr;
		m_pThickness			= nullptr;
	}

public:
	HairObject				*m_pGuideObject;				///< Guide object.
	HairObject				*m_pHairObject;					///< Hair object.
	HairGuides				*m_pHair;								///< Hair guides.
	BaseList2D				*m_pBase;								///< Base.
	const RayObject		*m_pRayObject;					///< Ray object.
	const RayObject		*m_pRayObjectHair;			///< Hair "dummy" ray object. Can be @formatConstant{nullptr}.
	HairMaterialData	*m_pMaterial;						///< %Material data.
	Float32						*m_pThickness;					///< Thickness.
};

struct HairFragment
{
	Vector	col;				///< Color.
	Float		trans;			///< Transparency.
	Float		z;					///< Z distance.
};

struct HairFragmentLink
{
	Vector	col;				///< Color.
	Float		trans;			///< Transparency.
	Float		z;					///< Z distance.
	void		*link;			///< Link pointer. @markPrivate
};

struct HairHitData
{
	Int32				oindex;
	Int32				lid;
	Int32				seg;
	Int32				p;
	HairGuides	*hair;
	BaseList2D	*object;
};

/// No hooks.
#define HAIR_VP_FLAG_NOHOOKS	(1 << 0)

//----------------------------------------------------------------------------------------
/// Hair video post effect.
/// @addAllocFreeAutoAllocNote
//----------------------------------------------------------------------------------------
class HairVideoPost : public BaseVideoPost
{
#ifndef __API_INTERN__
private:
	HairVideoPost();
	~HairVideoPost();
public:
	//----------------------------------------------------------------------------------------
	/// @allocatesA{hair video post}
	/// @return												@allocReturn{hair video post}
	//----------------------------------------------------------------------------------------
	static HairVideoPost *Alloc() { return (HairVideoPost*)BaseVideoPost::Alloc(VPhair); }

	//----------------------------------------------------------------------------------------
	/// @destructsAlloc{hair video posts}
	/// @param[in,out] pPost					@theToDestruct{hair video post}
	//----------------------------------------------------------------------------------------
	static void Free(HairVideoPost *&pPost) { BaseVideoPost *vp = pPost; BaseVideoPost::Free(vp); pPost = nullptr; }
#else
public:
#endif

	//----------------------------------------------------------------------------------------
	/// Gets the number of hair render objects.
	/// @return												The object count.
	//----------------------------------------------------------------------------------------
	Int32 GetObjectCount();

	//----------------------------------------------------------------------------------------
	/// Gets a hair render object.
	/// @param[in] i									The index of the hair render object: @em 0 <= @formatParam{index} < GetObjectCount()
	/// @param[out] hro								Assigned the hair render object.
	//----------------------------------------------------------------------------------------
	void GetObject(Int32 i, HairRenderObject *hro);

	//----------------------------------------------------------------------------------------
	/// Finds the index of a hair render object for a scene object.
	/// @param[in] bl									The scene object to find.
	/// @return												The hair render object index of @formatParam{bl}, or @ref NOTOK.
	//----------------------------------------------------------------------------------------
	Int32 FindObject(BaseList2D *bl);

	//----------------------------------------------------------------------------------------
	/// Checks if tracer is enabled.
	/// @note Always returns @formatConstant{false}.
	//----------------------------------------------------------------------------------------
	Bool TracerEnabled()
	{
		return false;
	}

	//----------------------------------------------------------------------------------------
	/// Traces a ray.
	/// @note Always returns @ref NOTOK.
	//----------------------------------------------------------------------------------------
	Int32 TraceRay(const Vector &p, const Vector &v, Vector &hit, Float &d, Int32 cpu, Float tf, Int32 flags)
	{
		return NOTOK;
	}

	//----------------------------------------------------------------------------------------
	/// @markTODO
	//----------------------------------------------------------------------------------------
	void Sample(Int32 oindex, VolumeData *vd, Int32 cpu, Int32 lid, Int32 seg, Int32 p, Float lined, const Vector &linep, const Vector &v, Vector &col, const Vector &n, const Vector &lp, const Vector &t, const Vector &r, Vector huv, Int32 flags);

	//----------------------------------------------------------------------------------------
	/// @markTODO
	//----------------------------------------------------------------------------------------
	Float SampleTransparency(Int32 oindex, VolumeData *vd, Int32 lid, Int32 seg, Int32 p, Float lined, const Vector &n, const Vector &linep, const Vector &lp, Vector huv, Int32 cpu, Int32 flags, const RayLight *light);

	//----------------------------------------------------------------------------------------
	/// Sample shadows.
	/// @note Always returns @em 0.0.
	//----------------------------------------------------------------------------------------
	Float SampleShadow(VolumeData *vd, const RayLight *light, const Vector &p, Float delta, Int32 cpu, Int32 flags)
	{
		return 0.0;
	}

	//----------------------------------------------------------------------------------------
	/// Gets a top fragment.
	/// @note Always returns @formatConstant{false}.
	//----------------------------------------------------------------------------------------
	Bool GetTopFragment(Int32 x, Int32 y, HairFragment *frag, Int32 cpu)
	{
		return false;
	}

	//----------------------------------------------------------------------------------------
	/// Accesses a fragment link.
	/// @note Always returns @formatConstant{false}.
	//----------------------------------------------------------------------------------------
	Bool GetFragmentLink(Int32 x, Int32 y, HairFragmentLink *frag, Int32 cpu, Bool first)
	{
		return false;
	}

	//----------------------------------------------------------------------------------------
	/// Gets fragments.
	/// @note Always returns @formatConstant{nullptr}.
	//----------------------------------------------------------------------------------------
	HairFragment *GetFragments(Int32 x, Int32 y, Int32 &cnt, Int32 cpu)
	{
		return nullptr;
	}

	//----------------------------------------------------------------------------------------
	/// Sets fragments.
	/// @note Always returns @formatConstant{false}.
	//----------------------------------------------------------------------------------------
	Bool SetFragments(Int32 x, Int32 y, HairFragment *frag, Int32 cnt, Int32 cpu)
	{
		return false;
	}

	//----------------------------------------------------------------------------------------
	/// Inserts fragments.
	/// @note Always returns @formatConstant{false}.
	//----------------------------------------------------------------------------------------
	Bool InsertFragment(Int32 x, Int32 y, HairFragment *frag, Int32 cnt, Int32 cpu)
	{
		return false;
	}

	//----------------------------------------------------------------------------------------
	/// Inserts a fragment line.
	/// @note Always returns @formatConstant{false}.
	//----------------------------------------------------------------------------------------
	Bool InsertFragmentLine(Int32 x, Int32 y, Int32 xcnt, HairFragment **frag, Int32 *cnt, Int32 cpu)
	{
		return false;
	}

	//----------------------------------------------------------------------------------------
	/// Gets hair hit data.
	/// @note Does nothing.
	//----------------------------------------------------------------------------------------
	void GetHitInfo(Int32 id, HairHitData *hdata)
	{
	}

	//----------------------------------------------------------------------------------------
	/// Checks if a light source is enabled for hair rendering.
	/// @note Always returns @formatConstant{true}.
	//----------------------------------------------------------------------------------------
	Bool IsLightEnabled(Int32 oindex, const RayLight *light, Bool *nodiff, Bool *nospec)
	{
		return true;
	}

	//----------------------------------------------------------------------------------------
	/// Checks if shadows are enabled.
	/// @note Always returns @formatConstant{true}.
	//----------------------------------------------------------------------------------------
	Bool ShadowsEnabled()
	{
		return true;
	}

	//----------------------------------------------------------------------------------------
	/// Gets the compositing flags for hair objects.
	/// @param[in] oindex							The hair object index.
	/// @return												The compositing flags, internally defined as:
	/// 															@code
	/// 															#define COMPOSITEFLAG_ALL (COMPOSITEFLAG_CASTSHADOW|COMPOSITEFLAG_RECSHADOW|COMPOSITEFLAG_SEENCAMERA|COMPOSITEFLAG_SEENGI|COMPOSITEFLAG_SEENREFLECT|COMPOSITEFLAG_SEENREFRACT|COMPOSITEFLAG_SEENTRANS)
	///
	///																#define COMPOSITEFLAG_CASTSHADOW	(1 << 0)
	///																#define COMPOSITEFLAG_RECSHADOW		(1 << 1)
	///																#define COMPOSITEFLAG_SEENCAMERA	(1 << 2)
	///																#define COMPOSITEFLAG_SEENGI			(1 << 3)
	///																#define COMPOSITEFLAG_SEENREFLECT	(1 << 4)
	///																#define COMPOSITEFLAG_SEENREFRACT	(1 << 5)
	///																#define COMPOSITEFLAG_SEENTRANS		(1 << 6)
	///																@endcode
	//----------------------------------------------------------------------------------------
	UInt32 GetCompositeFlags(Int32 oindex);
};

/// @addtogroup MSG_HAIR
/// @ingroup group_enumeration
/// @{
#define MSG_HAIR_GET_OBJECT_TYPE	1018952		///< Sent to get callback data.\n
																						///< All plugin objects in the scene get this message, as well as any extra objects specified by @ref MSG_HAIR_GET_OBJECTS.\n
																						///< The corresponding message @c data is HairPluginMessageData. Fill in a HairPluginObjectData in the @c data pointer for the message.
#define MSG_HAIR_GET_OBJECTS			1018959		///< Sent to all tags on hair objects and to all scene hooks.\n
																						///< The corresponding @c data is an AtomArray in to fill with the BaseList2D objects that should be sent @ref MSG_HAIR_GET_OBJECT_TYPE (e.g. so it could be sent to materials or objects not in the document).
/// @}

/// @addtogroup HAIR_CALC_FLAG
/// @ingroup group_enumeration
/// @{
#define HAIR_CALC_FLAG_APPLYMATERIALS	(1 << 0)			///< Apply materials.
#define HAIR_CALC_FLAG_APPLYDEFORMERS	(1 << 1)			///< Apply deformers.
#define HAIR_CALC_FLAG_DISPLACE				(1 << 2)			///< Displace.
#define HAIR_CALC_FLAG_SKIP						(1 << 3)			///< Skip.
#define HAIR_CALC_FLAG_NOMEMORY				(1 << 4)			///< No memory.
#define HAIR_CALC_FLAG_BREAK					(1 << 5)			///< Break.
/// @}

/// @addtogroup HAIR_PLUGIN_TYPE
/// @ingroup group_enumeration
/// @{
#define HAIR_PLUGIN_TYPE_FORCE			1			///< Force plugin.
#define HAIR_PLUGIN_TYPE_CONSTRAINT	2			///< Constraint plugin.
#define HAIR_PLUGIN_TYPE_COLLIDER		3			///< Collider plugin.
#define HAIR_PLUGIN_TYPE_DEFORMER		4			///< Deformer plugin.
#define HAIR_PLUGIN_TYPE_GENERATOR	5			///< Generator plugin.
#define HAIR_PLUGIN_TYPE_SHADER			6			///< Shader plugin.
#define HAIR_PLUGIN_TYPE_STYLING		7			///< Styling plugin.
/// @}

/// @addtogroup HAIR_GENERATE_PASS
/// @ingroup group_enumeration
/// @{
#define HAIR_GENERATE_PASS_INIT				0			///< Initial pass.
#define HAIR_GENERATE_PASS_BUILD			1			///< Build pass.
#define HAIR_GENERATE_PASS_FREE				2			///< Free pass.
#define HAIR_GENERATE_PASS_THICKNESS	3			///< Thickness pass.
/// @}

/// @addtogroup HAIR_GENERATE_HOOK
/// @ingroup group_enumeration
/// @{
#define HAIR_GENERATE_HOOK_BUILD			1			///< Build hook.
#define HAIR_GENERATE_HOOK_DYNAMICS		2			///< Dynamics hook.
/// @}

/// @addtogroup HAIR_HOOK_TYPE
/// @ingroup group_enumeration
/// @{
#define HAIR_HOOK_TYPE_SAMPLE_COLOR		1			///< Sample color hook: HrSampleHairColorHook()
#define HAIR_HOOK_TYPE_SAMPLE_TRANS		2			///< Sample transparency hook: HrSampleHairTransparencyHook()
#define HAIR_HOOK_TYPE_SAMPLE_SHADOWS	3			///< Sample shadows hook: HrSampleShadowBufferHook()
#define HAIR_HOOK_TYPE_GENERATE_HAIR	4			///< Generate hair hook: HrGenerateHairHook()
#define HAIR_HOOK_TYPE_ILLUMINATE			5			///< Illuminate hook: HrIlluminateHook()
/// @}

/// @addtogroup HAIR_RENDER_INIT_PASS
/// @ingroup group_enumeration
/// @{
#define HAIR_RENDER_INIT_PASS_PRE			1			///< Pre-init pass.
#define HAIR_RENDER_INIT_PASS_BUILD		2			///< Build init pass.
#define HAIR_RENDER_INIT_PASS_POST		3			///< Post init pass.
/// @}


typedef Bool (*HrDeform)(BaseDocument *doc, BaseList2D *op, HairObject *hair, HairGuides *guides, Vector *padr, Int32 cnt, Int32 scnt);
typedef Bool (*HrStyle)(BaseDocument *doc, BaseList2D *op, HairObject *hair, HairGuides *guides, Vector *padr, Int32 cnt, Int32 scnt);
typedef Bool (*HrForce)(BaseDocument *doc, BaseList2D *op, HairObject *hair, HairGuides *guides, HairGuideDynamics *dyn, Vector *force, Float *invmass, Vector *padr, Int32 pcnt, Int32 cnt, Int32 scnt, Float t1, Float t2);
typedef Bool (*HrConstraint)(BaseDocument *doc, BaseList2D *op, HairObject *hair, HairGuides *guides, HairGuideDynamics *dyn, Vector *oldpnt, Vector *newpnt, Float *invmass, Int32 pcnt, Int32 cnt, Int32 scnt);
typedef Bool (*HrCollision)(BaseDocument *doc, BaseList2D *op, HairObject *hair, HairGuides *guides, HairGuideDynamics *dyn, const Vector &bmin, const Vector &bmax, Float t1, Float t2, Float pr, Vector *oldpnt, Vector *newpnt, Vector *vel, Float *invmass, Int32 pcnt, Int32 cnt, Int32 scnt);

typedef HairGuides *(*HrGenerate)(BaseDocument *doc, BaseList2D *op, HairObject *hair, BaseThread *thd, VolumeData *vd, Int32 pass, void *data);
typedef Int32 (*HrCalcHair)(Int32 index, Int32 oindex, NodeData *node, HairGuides *guides, Vector *guide_pnts, Vector *rend_pnts, Float32 *thickness, VolumeData *vd, Vector *n);
typedef Int32 (*HrGenerateAdd)(BaseDocument *doc, BaseList2D *op);
typedef Vector (*HrGenerateColor)(HairVideoPost *vp, Int32 oindex, HairMaterialData *mat, const RayObject *ro, HairObject *op, HairGuides *guides, BaseList2D *bl, Float32 *thk, VolumeData *vd, Int32 cpu, Int32 lid, Int32 seg, Int32 p, Float lined, const Vector &linep, const Vector &v, const Vector &n, const Vector &lp, const Vector &t, const Vector &r, const Vector &huv, const RayHitID &ply_hit);
typedef Float (*HrGenerateTransparency)(HairVideoPost *vp, Int32 oindex, HairMaterialData *mat, const RayObject *ro, HairObject *op, HairGuides *guides, BaseList2D *bl, Float32 *thk, VolumeData *vd, Int32 cpu, Int32 lid, Int32 seg, Int32 p, Float lined, const Vector &linep, const Vector &n, const Vector &lp, const Vector &huv, const RayHitID &ply_hit, const RayLight *light);

typedef Vector (*HrSampleExt)(BaseShader *shader, NodeData *node, ChannelData* cd, HairGuides *guides, Int32 i, Float t);

typedef Vector (*HrSampleHairColorHook)(HairVideoPost *vp, Int32 oindex, HairMaterialData *mat, const RayObject *ro, HairObject *op, HairGuides *guides, BaseList2D *bl, Float32 *thk, VolumeData *vd, Int32 cpu, Int32 lid, Int32 seg, Int32 p, Float lined, const Vector &linep, const Vector &v, const Vector &n, const Vector &lp, const Vector &t, const Vector &r, const Vector &huv, const RayHitID &ply_hit);
typedef Float (*HrSampleHairTransparencyHook)(HairVideoPost *vp, Int32 oindex, HairMaterialData *mat, const RayObject *ro, HairObject *op, HairGuides *guides, BaseList2D *bl, Float32 *thk, VolumeData *vd, Int32 cpu, Int32 lid, Int32 seg, Int32 p, Float lined, const Vector &linep, const Vector &n, const Vector &lp, const Vector &huv, const RayHitID &ply_hit, const RayLight *light);
typedef Float (*HrSampleShadowBufferHook)(HairVideoPost *vp, VolumeData *vd, const RayLight *light, const Vector &p, Float delta, Int32 cpu);

typedef Bool (*HrGenerateHairHook)(HairObject *op, HairGuides *guides, HairGuides *hair, Int32 pass);
typedef Bool (*HrIlluminateHook)(HairVideoPost *vp, VolumeData *vd, const RayLight *light, Vector &colshad, Vector &col, Vector &lv, const Vector &p, const Vector &v);

typedef Bool (*HrInitRender)(HairVideoPost *vp, VolumeData *vd, BaseDocument *doc, BaseList2D *bl, HairObject *op, HairGuides *guides, Int32 oindex, Int32 pass);
typedef void (*HrFreeRender)(HairVideoPost *vp, BaseList2D *bl);

typedef Float (*HrModifyHairShadowTransparency)(HairVideoPost *vp, Int32 oindex, HairMaterialData *mat, const RayObject *ro, HairObject *op, HairGuides *guides, BaseList2D *bl, Float32 *thk, VolumeData *vd, Int32 cpu, Int32 lid, Int32 seg, Int32 p, Float lined, const Vector &linep, const Vector &n, const Vector &lp, const Vector &huv, const RayHitID &ply_hit, const RayLight *light, Float trans);


/// Hair plugin data version.
#define HAIR_PLUGIN_DATA_VERSION	1000

class HairPluginObjectData
{
public:
	//----------------------------------------------------------------------------------------
	/// Destructor.
	//----------------------------------------------------------------------------------------
	HairPluginObjectData()
	{
		ClearMem(this, sizeof(HairPluginObjectData));
		version = HAIR_PLUGIN_DATA_VERSION;
		size = sizeof(HairPluginObjectData);
	}

	Int32	version,			///< Version.
				size;					///< Size.
	Int32	flags;				///< Not used.

	HrForce													calc_force;						///< Force calculation hook.
	HrConstraint										calc_constraint;			///< Constraint calculation hook.
	HrCollision											calc_collision;				///< Collision calculation hook.
	HrDeform												calc_deform;					///< Deform calculation hook.
	HrGenerate											calc_generate;				///< Generate hook.
	HrGenerateAdd										add_generate;					///< Generate add hook.
	HrCalcHair											calc_hair;						///< Hair calculation hook.
	HrSampleExt											calc_sample;					///< Sample hook.
	HrGenerateColor									calc_col;							///< Color calculation hook.
	HrGenerateTransparency					calc_trans;						///< Transparency calculation hook.
	HrStyle													calc_style;						///< Style calculation hook.
	HrInitRender										init_render;					///< Init render hook.
	HrFreeRender										free_render;					///< Free render hook.
	HrModifyHairShadowTransparency	calc_shad;						///< Shadow calculation hook.
};

/// @markPrivate
#define HAIR_MSG_DATA_VERSION	1000

/// @addtogroup HAIR_MSG_DATA_FLAG
/// @ingroup group_enumeration
/// @{
/// @markPrivate
enum class HAIR_MSG_DATA_FLAG
{
	TEXTURETAG	= (1 << 0),

	NONE = 0
} MAXON_ENUM_FLAGS(HAIR_MSG_DATA_FLAG);
/// @}

/// @addtogroup HAIR_MSG_DATA_TYPE
/// @ingroup group_enumeration
/// @{
/// @markPrivate
enum class HAIR_MSG_DATA_TYPE
{
	GETMATERIAL		= 1,
	ADDOBJECT			= 2,
	INIT					= 3,
	INITRENDER		= 4,
	FREERENDER		= 5,

	NONE					= 0
} MAXON_ENUM_LIST(HAIR_MSG_DATA_TYPE);
/// @}

class HairPluginMessageData
{
public:
	//----------------------------------------------------------------------------------------
	/// Default constructor.
	//----------------------------------------------------------------------------------------
	HairPluginMessageData()
	{
		size = sizeof(HairPluginMessageData);
		version = HAIR_MSG_DATA_VERSION;
		data = nullptr;
		flags = HAIR_MSG_DATA_FLAG::NONE;
		bl = nullptr;
		type = HAIR_MSG_DATA_TYPE::NONE;
	}

	Int32	version,								///< Version. Read only.
				size;										///< Size. Read only.

	HAIR_MSG_DATA_FLAG	flags;									///< The flags. @markPrivate
	void	*data;									///< The plugin data.

	HAIR_MSG_DATA_TYPE type;			///< The message type. @markPrivate
	BaseList2D *bl;								///< @markPrivate
};

class HairLibrary
{
public:
	//----------------------------------------------------------------------------------------
	/// Gets the hair mode.
	/// @param[in] doc								The document.
	/// @return												The hair mode: @enumerateEnum{HAIR_MODE}
	//----------------------------------------------------------------------------------------
	Int32 GetMode(BaseDocument *doc);

	//----------------------------------------------------------------------------------------
	/// Sets the hair mode.
	/// @param[in] doc								The document.
	/// @param[in] mode								The new hair mode: @enumerateEnum{HAIR_MODE}
	//----------------------------------------------------------------------------------------
	void SetMode(BaseDocument *doc, Int32 mode);

	//----------------------------------------------------------------------------------------
	/// Checks the hair global settings enable state.
	/// @param[in] doc								The document.
	/// @return												The hair global enable state.
	//----------------------------------------------------------------------------------------
	Bool GetHairGlobal(BaseDocument* doc);

	//----------------------------------------------------------------------------------------
	/// Sets the hair global settings enable state.
	/// @param[in] doc								The document.
	/// @param[in] enable							@trueOtherwiseFalse{to enable the hair global settings}
	//----------------------------------------------------------------------------------------
	void SetHairGlobal(BaseDocument* doc, Bool enable);

	//----------------------------------------------------------------------------------------
	/// Blend colors.
	/// @param[in] mode								The blend mode. See description/mhairmaterial.h for modes, e.g. @ref HAIRMATERIAL_BLENDMODE_AVERAGE.
	/// @param[in] colA								The first color.
	/// @param[in] colB								The second color.
	/// @return												The resulting color.
	//----------------------------------------------------------------------------------------
	Vector BlendColors(Int32 mode, const Vector &colA, const Vector &colB);

	//----------------------------------------------------------------------------------------
	/// Mixes by the @formatParam{s} and @formatParam{t} coordinates among @formatParam{pa}, @formatParam{pb}, @formatParam{pc} and @formatParam{pd}.
	/// @param[in] s									The S coordinate.
	/// @param[in] t									The T coordinate.
	/// @param[in] pa									The first point value.
	/// @param[in] pb									The second point value.
	/// @param[in] pc									The third point value.
	/// @param[in] pd									The fourth point value.
	/// @param[in] bQuad							@formatConstant{true} means quadrangle, @formatConstant{false} means triangle.
	/// @return												The resulting vector.
	//----------------------------------------------------------------------------------------
	Vector MixST(Float s, Float t, const Vector &pa, const Vector &pb, const Vector &pc, const Vector &pd, Bool bQuad);

	//----------------------------------------------------------------------------------------
	/// Mixes by the @formatParam{s} and @formatParam{t} coordinates among @formatParam{va}, @formatParam{vb}, @formatParam{vc} and @formatParam{vd}.
	/// @param[in] s									The S coordinate.
	/// @param[in] t									The T coordinate.
	/// @param[in] va									The first value.
	/// @param[in] vb									The second value.
	/// @param[in] vc									The third value.
	/// @param[in] vd									The fourth value.
	/// @param[in] bQuad							@formatConstant{true} means quadrangle, @formatConstant{false} means triangle.
	/// @return												The resulting value.
	//----------------------------------------------------------------------------------------
	Float MixST(Float s, Float t, Float va, Float vb, Float vc, Float vd, Bool bQuad);

	//----------------------------------------------------------------------------------------
	/// Calculates the @formatParam{s} and @formatParam{t} coordinates of the point @formatParam{p} in the polygon described by @formatParam{pa}, @formatParam{pb}, @formatParam{pc} and @formatParam{pd}.
	/// @param[in] p									The point to get the coordinates for.
	/// @param[out] s									Assigned the S coordinate.
	/// @param[out] t									Assigned the T coordinate.
	/// @param[in] pa									The first point value.
	/// @param[in] pb									The second point value.
	/// @param[in] pc									The third point value.
	/// @param[in] pd									The fourth point value.
	/// @param[in] bQuad							@formatConstant{true} means quadrangle, @formatConstant{false} means triangle.
	//----------------------------------------------------------------------------------------
	void GetPolyPointST(const Vector &p, Float &s, Float &t, const Vector &pa, const Vector &pb, const Vector &pc, const Vector &pd, Bool bQuad);

	//----------------------------------------------------------------------------------------
	/// Retrieves a hair hook.
	/// @param[in] doc								The document.
	/// @param[in] type								The hair hook type: @enumerateEnum{HAIR_HOOK_TYPE}
	/// @return												The retrieved hair hook.
	//----------------------------------------------------------------------------------------
	void *GetHook(BaseDocument *doc, Int32 type);

	//----------------------------------------------------------------------------------------
	/// Sets a hair hook.
	/// @param[in] doc								The document.
	/// @param[in] type								The hair hook type: @enumerateEnum{HAIR_HOOK_TYPE}
	/// @param[in] fn									The new hair hook.
	/// @return												The old hair hook.
	//----------------------------------------------------------------------------------------
	void *SetHook(BaseDocument *doc, Int32 type, void *fn);

	//----------------------------------------------------------------------------------------
	/// Retrieves the hair preferences container.
	/// @return												The hair preferences container. See @em Thairprefs.res.
	//----------------------------------------------------------------------------------------
	BaseContainer *GetPrefsInstance();

	//----------------------------------------------------------------------------------------
	/// Gets the hair version number.
	/// @return												The hair version.
	//----------------------------------------------------------------------------------------
	Int32 GetHairVersion();
};

//----------------------------------------------------------------------------------------
/// Hair collider class.
/// @addAllocFreeAutoAllocNote
//----------------------------------------------------------------------------------------
class HairCollider
{
private:
	HairColliderData *m_pData;

	HairCollider();
	~HairCollider();
public:
	//----------------------------------------------------------------------------------------
	/// @allocatesA{hair collider}
	/// @return												@allocReturn{hair collider}
	//----------------------------------------------------------------------------------------
	static HairCollider *Alloc();

	//----------------------------------------------------------------------------------------
	/// @destructsAlloc{hair colliders}
	/// @param[in,out] p							@theToDestruct{hair collider}
	//----------------------------------------------------------------------------------------
	static void Free(HairCollider *&p);

	//----------------------------------------------------------------------------------------
	/// Initializes the hair collider.
	/// @param[in] hair								The hair to initialize with.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool Init(HairGuides *hair);

	//----------------------------------------------------------------------------------------
	/// Releases allocated memory. Called automatically by Free().
	//----------------------------------------------------------------------------------------
	void Release();

	//----------------------------------------------------------------------------------------
	/// Gets the closest point to @formatParam{p}.
	/// @param[in] p									The point to search for.
	/// @return												The closest point or @ref NOTOK if an error occurred.
	//----------------------------------------------------------------------------------------
	Int32 GetClosestPoint(const Vector &p);

	//----------------------------------------------------------------------------------------
	/// Gets the closest segment to @formatParam{p}.
	/// @param[in] p									The point to search for.
	/// @param[out] guide							Assigned the guide index.
	/// @param[out] segment						Assigned the segment index.
	/// @param[out] segt							Assigned the segment t coordinate.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool GetClosestSegment(const Vector &p, Int32 *guide, Int32* segment, Float* segt);

	//----------------------------------------------------------------------------------------
	/// Gets the intersection of particle @formatParam{p} with vector @formatParam{v}, looking within a distance radius of @formatParam{r}.
	/// @param[in] p									The point to search for.
	/// @param[in] v									The vector of particle to search for.
	/// @param[in] r									The search distance radius.
	/// @param[out] guide							Assigned the guide index.
	/// @param[out] segment						Assigned the segment index.
	/// @param[out] segt							Assigned the segment t coordinate.
	/// @param[out] rayt							Assigned the ray coordinate.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool GetParticleIntersection(const Vector &p, const Vector &v, Float r, Int32 *guide, Int32 *segment, Float *segt, Float *rayt);
};

/// Hair library ID.
#define LIBRARY_HAIR 1018173

/// Hair collider library ID.
#define LIBRARY_HAIR_COLLIDER 1018174

/// @}

/// @cond IGNORE

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

struct HairObjectLib : public C4DLibrary
{
	HairGuides *(*GetGuides)(BaseObject *hop);
	HairGuides *(*GetDynamicGuides)(BaseObject *hop);
	Bool (*GetRootObject)(BaseObject *hop, BaseObject **pObject, BaseTag **pTag, RootObjectData *pData);
	Bool (*Lock)(BaseObject *hop, BaseDocument *pDoc, BaseThread *pThread, Bool bValidate, Int32 flags);
	void (*Unlock)(BaseObject *hop);
	HairGuides *(*GenerateHair)(BaseObject *hop, Int32 flags, Int32 count, Int32 segments, HairMaterialData **pMaterial, HairInterpolationMap *pMap);
	Bool (*SetGuides)(BaseObject *hop, HairGuides *guides, Bool clone);
	void (*RemoveGuides)(BaseObject *hop);
	HairMaterialData *(*InitMaterials)(const InitRenderStruct &irs, BaseObject *hop, BaseDocument *pDoc, HairGuides *guides, VolumeData *vd);
	void (*FreeMaterials)(BaseObject *hop, HairMaterialData *&pMaterials);
	Int32 (*GetGuideCount)(HairGuides *guides);
	Int32 (*GetGuideSegmentCount)(HairGuides *guides);
	Vector *(*GetGuidePoints)(HairGuides *guides);
	HairGuideDynamics *(*GetGuideDynamics)(HairGuides *guides);
	Matrix (*GetGuideMg)(HairGuides *guides);
	void (*SetGuideMg)(HairGuides *guides, const Matrix &mg);
	HairRootData (*GetGuideRoot)(HairGuides *guides, Int32 index);
	void (*SetGuideRoot)(HairGuides *guides, Int32 index, const HairRootData &root, Bool update);
	HairObject *(*GetGuideObject)(HairGuides *guides);
	HairGuides *(*AllocGuides)(Int32 count, Int32 segments);
	void (*FreeGuides)(HairGuides *&guides);
	Bool (*GetGuideSelected)(HairGuides *guides, Int32 mode, BaseSelect *select);
	Bool (*CopyGuidesFrom)(HairGuides *guides, const HairGuides *src);
	Bool (*SetGuideSelected)(HairGuides *guides, Int32 mode, BaseSelect *select);
	Bool (*ConvertGuideSelection)(HairGuides *guides, Int32 from_mode, Int32 to_mode, BaseSelect *from_select, BaseSelect *to_select);
	Vector (*GetGuideTangent)(HairGuides *guides, Int32 guide, Int32 segment, Float t);
	SplineObject *(*CreateGuideSpline)(HairGuides *guides);
	void (*guideToLocal)(HairGuides *guides);
	void (*guideToWorld)(HairGuides *guides);
	void (*guideToInitial)(HairGuides *guides, Bool align);
	void (*guideUndisplaceRoots)(HairGuides *guides);
	void (*guideDisplaceRoots)(HairGuides *guides);
	Bool (*guideGetRootAxis)(HairGuides *guides, Int32 index, Matrix &m, Bool bAlign, Bool bLocal, Bool bInitial, Bool bZAxis);
	Vector (*guideGetRootUV)(HairGuides *guides, Int32 index);
	Bool (*guideGetRootData)(HairGuides *guides, Int32 index, Vector *p, Vector *n, Int32 *ply_id, Bool bLocal, Bool bDisplaced, Bool bInitial);
	Matrix *(*guideGetTransformMatrix)(HairGuides *guides);
	void (*guideSetTransformMatrix)(HairGuides *guides, Matrix *tm);
	Bool (*guideDelete)(HairGuides *guides, BaseSelect *bs);
	Bool (*guideAddRoot)(HairGuides *guides, Int32 ply_id, Float s, Float t, Float len);
	Bool (*guideGetRootObject)(HairGuides *guides, RootObjectData *pData);
	HairGuides *(*GetDynamicsGuides)(HairGuideDynamics *dynamics);
	Vector (*GetDynamicsPosition)(HairGuideDynamics *dynamics, Int32 i);
	void (*SetDynamicsPosition)(HairGuideDynamics *dynamics, Int32 i, const Vector &p);
	Vector (*GetDynamicsLastPosition)(HairGuideDynamics *dynamics, Int32 i);
	void (*SetDynamicsLastPosition)(HairGuideDynamics *dynamics, Int32 i, const Vector &p);
	Vector (*GetDynamicsVelocity)(HairGuideDynamics *dynamics, Int32 i);
	void (*SetDynamicsVelocity)(HairGuideDynamics *dynamics, Int32 i, const Vector &v);
	Float (*GetDynamicsMass)(HairGuideDynamics *dynamics, Int32 i);
	void (*SetDynamicsMass)(HairGuideDynamics *dynamics, Int32 i, Float m);
	Vector (*GetDynamicsForce)(HairGuideDynamics *dynamics, Int32 i);
	void (*AddDynamicsForce)(HairGuideDynamics *dynamics, Int32 i, const Vector &f);
	Int32 (*GetDynamicsPolygonIntersections)(HairGuideDynamics *dynamics, HairPolygonHit **hits);
	Int32 (*hairGetMode)(BaseDocument *doc);
	void (*hairSetMode)(BaseDocument *doc, Int32 mode);
	Bool (*hairGetHairGlobal)(BaseDocument* doc);
	void (*hairSetHairGlobal)(BaseDocument* doc, Bool enable);
	Vector (*hairBlendColors)(Int32 mode, const Vector &colA, const Vector &colB);
	Vector (*hairMixST)(Float s, Float t, const Vector &pa, const Vector &pb, const Vector &pc, const Vector &pd, Bool bQuad);
	Float (*hairMixSTReal)(Float s, Float t, Float va, Float vb, Float vc, Float vd, Bool bQuad);
	void (*hairGetPolyPointST)(const Vector &p, Float &s, Float &t, const Vector &pa, const Vector &pb, const Vector &pc, const Vector &pd, Bool bQuad);
	Bool (*HairSelectionGetSelected)(HairSelectionTag *stag, BaseSelect *bs);
	Bool (*HairSelectionSetSelected)(HairSelectionTag *stag, BaseSelect *bs);
	Int32 (*HairSelectionGetType)(HairSelectionTag *stag);
	void (*HairSelectionSetType)(HairSelectionTag *stag, Int32 mode);
	Int32 (*HairSelectionGetCount)(HairSelectionTag *stag);
	Int32 (*HairSelectionGetSegments)(HairSelectionTag *stag);
	Int32 (*HairVertexGetCount)(HairVertexMapTag *vtag);
	Int32 (*HairVertexGetSegments)(HairVertexMapTag *vtag);
	Int32 (*HairVertexGetPointCount)(HairVertexMapTag *vtag);
	UInt16 *(*HairVertexGetMap)(HairVertexMapTag *vtag);
	Int32 (*matGetCount)(HairMaterialData *mat);
	Int32 (*matGetGuideMaterial)(HairMaterialData *mat, Int32 i, Int32 prev);
	BaseTag *(*matGetMaterialTag)(HairMaterialData *mat, Int32 i);
	Bool (*matApplyMaterial)(HairMaterialData *mat, Int32 i, HairGuides *guides, VolumeData *vd, Int32 vindex);
	Bool (*matApplyMaterials)(HairMaterialData *mat, HairGuides *guides, VolumeData *vd, Int32 vindex);
	Float (*matGetThickness)(HairMaterialData *mat, Int32 guide, Float t, Int32 i);
	Vector (*matGetColor)(HairMaterialData *mat, Int32 guide, Float t, const Vector &r, const Vector &wp, const Vector &p, const Vector &n, VolumeData *vd, const RayHitID &plyid, Int32 i);
	Vector (*matGetBackColor)(HairMaterialData *mat, Int32 guide, Float t, const Vector &col, const Vector &r, const Vector &wp, const Vector &p, const Vector &n, VolumeData *vd, const RayHitID &plyid, Int32 i);
	Bool (*matGetSpecularColor)(HairMaterialData *mat, Int32 guide, Float t, const Vector &wp, const Vector &p, const Vector &n, VolumeData *vd, const RayHitID &plyid, Vector &speccol, Vector &ispeccol);
	Float (*matGetTransparencyEx)(HairMaterialData *mat, Int32 guide, Float t, const Vector &p, const Vector &n, Int32 i);
	Bool (*matGetTagSelection)(HairMaterialData *mat, Int32 i, BaseSelect *bs);
	Bool (*matGetMaterialData)(HairMaterialData *mat, Int32 guide, Float &shadows, Float &selfshadows, Float &backshadows, Float &transparency, Float &diffuse, Float &reflect, Float &transmit, Bool &roughenable, Float &roughvar, Float &roughness, Bool &specularenable, Float &specular, Float &specularpower, Float &specularback, Bool &ispecularenable, Bool &ispecularshader, Float &ispecular, Float &ispecularpower, Float &ispecularmix, Float &ispecularblend);
	Bool (*matGetGIData)(HairMaterialData *mat, Int32 guide, Bool &receive, Float &strength);
	Bool (*matAdjustHUV)(HairMaterialData *mat, Int32 guide, Vector &huv, Float tline);
	Int32 (*HairTangentGetPolygonsSegments)(HairTangentTag *ttag);
	Int32 (*HairTangentGetPointCount)(HairTangentTag *ttag);
	Int32 (*HairTangentGetCount)(HairTangentTag *ttag);
	Int32 (*HairTangentGetSegments)(HairTangentTag *ttag);
	Vector *(*HairTangentGetTangent)(HairTangentTag *ttag);
	void *(*hairGetHook)(BaseDocument *doc, Int32 type);
	void *(*hairSetHook)(BaseDocument *doc, Int32 type, void *fn);
	BaseContainer *(*hairGetPrefsInstance)();
	Int32 (*vpGetObjectCount)(HairVideoPost *vp);
	Int32 (*vpFindObject)(HairVideoPost *vp, BaseList2D *bl);
	Bool (*vpTracerEnabled)(HairVideoPost *vp);
	Int32 (*vpTraceRay)(HairVideoPost *vp, const Vector &p, const Vector &v, Vector &hit, Float &d, Int32 cpu, Float tf, Int32 flags);
	Bool (*hairIsLocked)(HairObject *op);
	Bool (*guideLinkToObject)(HairGuides *guide, HairObject *pHair);
	void (*vpSample)(HairVideoPost *vp, Int32 oindex, VolumeData *vd, Int32 cpu, Int32 lid, Int32 seg, Int32 p, Float lined, const Vector &linep, const Vector &v, Vector &col, const Vector &n, const Vector &lp, const Vector &t, const Vector &r, Vector huv, Int32 flags);
	Float (*vpSampleTransparency)(HairVideoPost *vp, Int32 oindex, VolumeData *vd, Int32 lid, Int32 seg, Int32 p, Float lined, const Vector &n, const Vector &linep, const Vector &lp, Vector huv, Int32 cpu, Int32 flags, const RayLight *light);
	Float (*vpSampleShadow)(HairVideoPost *vp, VolumeData *vd, const RayLight *light, const Vector &p, Float delta, Int32 cpu, Int32 flags);
	Bool (*vpGetTopFragment)(HairVideoPost *vp, Int32 x, Int32 y, HairFragment *frag, Int32 cpu);
	Bool (*vpSetFragments)(HairVideoPost *vp, Int32 x, Int32 y, HairFragment *frag, Int32 cnt, Int32 cpu);
	Bool (*vpGetFragmentLink)(HairVideoPost *vp, Int32 x, Int32 y, HairFragmentLink *frag, Int32 cpu, Bool first);
	HairFragment *(*vpGetFragments)(HairVideoPost *vp, Int32 x, Int32 y, Int32 &cnt, Int32 cpu);
	Bool (*vpInsertFragment)(HairVideoPost *vp, Int32 x, Int32 y, HairFragment *frag, Int32 cnt, Int32 cpu);
	Bool (*vpInsertFragmentLine)(HairVideoPost *vp, Int32 x, Int32 y, Int32 xcnt, HairFragment **frag, Int32 *cnt, Int32 cpu);
	Int32 (*hairGetHairVersion)();
	Int32 (*guideGetFlags)(HairGuides *guide);
	Int32 (*guideSetFlags)(HairGuides *guide, Int32 flags);
	void (*vpGetHitInfo)(HairVideoPost *vp, Int32 id, HairHitData *hdata);
	Bool (*vpIsLightEnabled)(HairVideoPost *vp, Int32 oindex, const RayLight *light, Bool *nodiff, Bool *nospec);
	Bool (*vpShadowsEnabled)(HairVideoPost *vp);
	UInt32 (*vpGetCompositeFlags)(HairVideoPost *vp, Int32 oindex);
	void (*vpGetObject)(HairVideoPost *vp, Int32 i, HairRenderObject *hro);
	Float (*matGetTransparency)(HairMaterialData *mat, Int32 guide, Float t, const Vector &p, const Vector &n, VolumeData *vd, Int32 i);
};

struct HairColliderLib : public C4DLibrary
{
	iHairCollider *(*Alloc)();
	void (*Free)(iHairCollider *&p);

	Bool (iHairCollider::*Init)(HairGuides *hair);
	void (iHairCollider::*Release)();
	Int32 (iHairCollider::*GetClosestPoint)(const Vector &p);
	Bool (iHairCollider::*GetClosestSegment)(const Vector &p, Int32 *guide, Int32* segment, Float* segt);
	Bool (iHairCollider::*GetParticleIntersection)(const Vector &p, const Vector &v, Float r, Int32 *guide, Int32 *segment, Float *segt, Float *rayt);
};

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

/// @endcond

#endif // LIB_HAIR_H__
