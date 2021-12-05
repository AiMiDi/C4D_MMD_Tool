/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef LIB_CLOUD_H__
#define LIB_CLOUD_H__

#include "c4d_baseobject.h"
#include "customgui_splinecontrol.h"

/// @addtogroup group_cloudlibrary Cloud
/// @ingroup group_library
/// @{

#define CLOUD_NODE						1011196				///< Cloud node ID.
#define CLOUD_GROUP_NODE			1011194				///< Cloud group ID.
#define SKY_OBJECT						1011146				///< Sky object ID.
#define MSG_SKY_INIALIZED			450000094			///< Sky initialized message ID.

/// @addtogroup CLOUD_CELL_SIZE
/// @ingroup group_enumeration
/// @{
#define CLOUD_CELL_SIZE_X		150			///< X cell size.
#define CLOUD_CELL_SIZE_Y		150			///< Y cell size.
#define CLOUD_CELL_SIZE_Z		150			///< Z cell size.
/// @}

//----------------------------------------------------------------------------------------
/// Finds the sky object in @formatParam{pDoc}.
/// @param[in] pDoc								The document to search in. @callerOwnsPointed{document}
/// @return												The sky object found, or @formatConstant{nullptr}.
//----------------------------------------------------------------------------------------
BaseObject* FindSkyObject(BaseDocument* pDoc);

class CloudObject;

#ifndef __SKY_INTERN__
//----------------------------------------------------------------------------------------
/// Cloud draw callback.
/// @param[in] op									The object.
/// @param[in] pDraw							The draw view.
/// @param[in] pDrawHelp					The draw helper.
/// @param[in] lGrid							The grid.
/// @param[in] rQuality						The quality.
/// @param[in] vScale							The scale.
/// @param[in] pSun								The sun object.
/// @param[in] bDrawPlane					The draw plane option.
/// @return												@trueIfOtherwiseFalse{successful}
//----------------------------------------------------------------------------------------
typedef Bool (*CloudDrawFn)(BaseObject* op, BaseDraw* pDraw, BaseDrawHelp* pDrawHelp, Int32 lGrid, Float rQuality, const Vector &vScale, BaseObject* pSun, Bool bDrawPlane);

//----------------------------------------------------------------------------------------
/// Cloud data allocator callback.
/// @param[in] pCloud							The cloud object.
/// @return												The allocated data.
//----------------------------------------------------------------------------------------
typedef void* (*CloudDataAllocator)(BaseObject* pCloud);

//----------------------------------------------------------------------------------------
/// Cloud data deleter callback.
/// @param[in] pCloud							The cloud object.
/// @param[in] pData							The data to delete.
//----------------------------------------------------------------------------------------
typedef void (*ClodDataDeleter)(BaseObject* pCloud, void* &pData);
#endif

//----------------------------------------------------------------------------------------
/// Cloud object.
//----------------------------------------------------------------------------------------
class CloudObject : public BaseObject
{
private:
	CloudObject();
	~CloudObject();

public:
	/// @name Alloc/Free
	/// @{

	//----------------------------------------------------------------------------------------
	/// @allocatesA{cloud object}
	/// @return												@allocReturn{cloud object}
	//----------------------------------------------------------------------------------------
	static CloudObject* Alloc();

	//----------------------------------------------------------------------------------------
	/// @destructsAlloc{cloud objects}
	/// @param[in,out] pObj						@theToDestruct{cloud object}
	//----------------------------------------------------------------------------------------
	static void Free(CloudObject *&pObj);

	/// @}

	/// @name Size/Density
	/// @{

	//----------------------------------------------------------------------------------------
	/// Retrieves the size in the vector @formatParam{vSize}.
	/// @param[out] vSize							The size.
	//----------------------------------------------------------------------------------------
	void GetSize(Vector& vSize);

	//----------------------------------------------------------------------------------------
	/// Retrieves the grid size.
	/// @note The cloud has <tt>(@formatParam{x} + @em 1) * (@formatParam{y} + @em 1) * (@formatParam{z} + @em 1)</tt> grid points.
	/// @param[out] x									Assigned the X size.
	/// @param[out] y									Assigned the Y size.
	/// @param[out] z									Assigned the Z size.
	//----------------------------------------------------------------------------------------
	void GetSize(Int32 &x, Int32 &y, Int32 &z);

	//----------------------------------------------------------------------------------------
	/// Gets the density array.
	/// @return												The density array.
	//----------------------------------------------------------------------------------------
	UChar* GetDensity();

	//----------------------------------------------------------------------------------------
	/// Gets the density size.
	/// @return												The density size.
	//----------------------------------------------------------------------------------------
	Int GetDensitySize();

	//----------------------------------------------------------------------------------------
	/// Resizes the cloud object.
	/// @param[in] x									The new X size.
	/// @param[in] y									The new Y size.
	/// @param[in] z									The new Z size.
	/// @param[in] bResample					If @formatConstant{true} the cloud data is resampled.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool Resize(Int32 x, Int32 y, Int32 z, Bool bResample);

	/// @}

	/// @name Tool Data
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets the tool data.
	/// @return												The tool data.
	//----------------------------------------------------------------------------------------
	UChar* GetToolData();

	//----------------------------------------------------------------------------------------
	/// Allocates the tool data.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool AllocToolData();

	//----------------------------------------------------------------------------------------
	/// Frees the tool data.
	//----------------------------------------------------------------------------------------
	void FreeToolData();

	/// @}

	/// @name Altitude
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets the altitude of a cloud group.
	/// @param[in] pCloudGroup				The cloud group object. @callerOwnsPointed{object}
	/// @return												The altitude.
	//----------------------------------------------------------------------------------------
	Float GetAltitude(BaseObject* pCloudGroup);

	/// @}

	/// @name Smooth/Clear/Fill
	/// @{

	//----------------------------------------------------------------------------------------
	/// Smooths borders.
	/// @param[in] rDist							The distance.
	/// @param[in] rVariance					The variance.
	/// @param[in] pSpline						The spline to smooth along.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool SmoothBorders(Float rDist, Float rVariance, SplineData* pSpline);

	//----------------------------------------------------------------------------------------
	/// Smooths all of the cloud object.
	/// @param[in] rStrength					The strength.
	/// @param[in] rVariance					The variance.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool SmoothAll(Float rStrength, Float rVariance);

	//----------------------------------------------------------------------------------------
	/// Clears the cloud object to @formatParam{chDensity}.
	/// @param[in] chDensity					The clear density.
	//----------------------------------------------------------------------------------------
	void Clear(UChar chDensity);

	//----------------------------------------------------------------------------------------
	/// Fills the plane.
	/// @param[in] rRadius						The radius.
	/// @param[in] chDensity					The density.
	//----------------------------------------------------------------------------------------
	void FillPlane(Float rRadius, UChar chDensity);

	//----------------------------------------------------------------------------------------
	/// Fills a sphere.
	/// @param[in] rRadius						The radius.
	/// @param[in] chDensity					The density.
	//----------------------------------------------------------------------------------------
	void FillSphere(Float rRadius, UChar chDensity);

	/// @}

	/// @name Visible/Lock
	/// @{

	//----------------------------------------------------------------------------------------
	/// Checks for visibility.
	/// @param[in] bEditor						The editor mode.
	/// @param[out] bDrawBox					Assigned the draw box visibility.
	/// @param[out] pSkyObject				Assigned the sky object.
	/// @param[in] ppGroup						Optional array of cloud groups.
	/// @return												@trueIfOtherwiseFalse{visible}
	//----------------------------------------------------------------------------------------
	Bool IsVisible(Bool bEditor, Bool &bDrawBox, BaseObject *&pSkyObject, BaseObject** ppGroup = nullptr);

	//----------------------------------------------------------------------------------------
	/// Checks if the cloud object is locked.
	/// @return												@trueIfOtherwiseFalse{the cloud object is locked}
	//----------------------------------------------------------------------------------------
	Bool IsLocked();

	/// @}

	/// @name Draw
	/// @{

	//----------------------------------------------------------------------------------------
	/// Draws the cloud object.
	/// @param[in] pBaseDraw					The draw view.
	/// @param[in] pDrawHelp					The draw helper.
	/// @param[in] lGrid							The grid size.
	/// @param[in] rQuality						The quality.
	/// @param[in] bDrawPlane					The draw plane option.
	//----------------------------------------------------------------------------------------
	void Draw(BaseDraw* pBaseDraw, BaseDrawHelp* pDrawHelp, Int32 lGrid, Float rQuality, Bool bDrawPlane);

	/// @}

	/// @name Plane Index/Position
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets the plane index.
	/// @return												The plane index.
	//----------------------------------------------------------------------------------------
	Int32 GetPlaneIndex();

	//----------------------------------------------------------------------------------------
	/// Sets the plane index.
	/// @param[in] lPlane							The new plane index.
	//----------------------------------------------------------------------------------------
	void SetPlaneIndex(Int32 lPlane);

	//----------------------------------------------------------------------------------------
	/// Gets the plane position.
	/// @return												The plane position.
	//----------------------------------------------------------------------------------------
	Int32 GetPlanePosition();

	//----------------------------------------------------------------------------------------
	/// Sets the plane position.
	/// @param[in] lPos								The new plane position.
	//----------------------------------------------------------------------------------------
	void SetPlanePosition(Int32 lPos);

	/// @}

	/// @name Miscellaneous
	/// @{

	//----------------------------------------------------------------------------------------
	/// Retrieves the cloud private data.
	/// @param[in] fnAlloc						The data allocator hook.
	/// @param[in] fnFree							The data deleter hook.
	/// @return												The private data.
	//----------------------------------------------------------------------------------------
	void* GetPrivateData(CloudDataAllocator fnAlloc, ClodDataDeleter fnFree);

	//----------------------------------------------------------------------------------------
	/// Sets the cloud draw hook.
	/// @param[in] fn									The draw hook.
	//----------------------------------------------------------------------------------------
	static void SetDrawHook(CloudDrawFn fn);

	/// @}
};

/// Cloud library ID.
#define LIB_CLOUD		450000111

/// @}

/// @cond IGNORE

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

class iCloudObject;

struct CloudObjectLib : public C4DLibrary
{
	CloudObject*	(*Alloc)();
	void					(*Free)(CloudObject *&pObj);
	void					(*SetDrawHook)(CloudDrawFn fn);

	void					(iCloudObject::*GetSize1)(Vector& vSize);
	void					(iCloudObject::*GetSize2)(Int32 &x, Int32 &y, Int32 &z);
	UChar*				(iCloudObject::*GetDensity)();
	UChar*				(iCloudObject::*GetToolData)();
	Bool					(iCloudObject::*AllocToolData)();
	void					(iCloudObject::*FreeToolData)();
	Int						(iCloudObject::*GetDensitySize)();

	Float					(iCloudObject::*GetAltitude)(BaseObject* pCloudGroup);

	Bool					(iCloudObject::*Resize)(Int32 x, Int32 y, Int32 z, Bool bResample);
	Bool					(iCloudObject::*SmoothBorders)(Float rDist, Float rVariance, SplineData* pSpline);
	Bool					(iCloudObject::*SmoothAll)(Float rStrength, Float rVariance);
	void					(iCloudObject::*Clear)(UChar chDensity);
	void					(iCloudObject::*FillPlane)(Float rRadius, UChar chDensity);
	void					(iCloudObject::*FillSphere)(Float rRadius, UChar chDensity);
	Bool					(iCloudObject::*IsVisible)(Bool bEditor, Bool &bDrawBox, BaseObject *&pSkyObject, BaseObject** ppGroup);
	Bool					(iCloudObject::*IsLocked)();
	Int32					(iCloudObject::*GetPlaneIndex)();
	void					(iCloudObject::*SetPlaneIndex)(Int32 lPlane);
	Int32					(iCloudObject::*GetPlanePosition)();
	void					(iCloudObject::*SetPlanePosition)(Int32 lPos);
	void					(iCloudObject::*Draw)(BaseDraw* pBaseDraw, BaseDrawHelp* pDrawHelp, Int32 lGrid, Float rQuality, Bool bDrawPlane);

	BaseObject*		(*FindSkyObject)(BaseDocument* pDoc);
	void*					(iCloudObject::*GetPrivateData)(CloudDataAllocator fnAlloc, ClodDataDeleter fnFree);
};

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

/// @endcond

#endif // LIB_CLOUD_H__
