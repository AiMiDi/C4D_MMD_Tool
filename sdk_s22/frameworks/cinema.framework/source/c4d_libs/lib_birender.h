/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef LIB_BIRENDER_H__
#define LIB_BIRENDER_H__

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

#include "c4d_raytrace.h"

#define LIBRARY_BIRENDER	1029004

const Int32 MSG_BIRENDER_ADDMPBUFFER = 1031173;

class BiRenderObject;
class BiRenderVideoPost;

namespace birender
{
const UInt32 segmentMask = 0x7FFFFFFF;
const UInt32 segmentClosed = 0x80000000;

enum class FLAG_STATE
{
	NONE	= 0,
	ADD		= 1,
	DEL		= 2,
	SET		= 3,
} MAXON_ENUM_LIST(FLAG_STATE);

enum class SHADING_CALLBACK_FLAG
{
	NONE = 0,
	INIT = (1 << 0),
	EXIT = (1 << 1),
	SHADER = (1 << 2),
	THICKNESS = (1 << 3),
	SHADOWS = (1 << 4)
} MAXON_ENUM_FLAGS(SHADING_CALLBACK_FLAG);

enum class RENDER_CALLBACK_FLAG
{
	NONE = 0,
	DRAW = (1 << 0),
	FIRST = (1 << 1),
	CALCVOL = (1 << 2),
	CALCVOL_EXIT = (1 << 3)
} MAXON_ENUM_FLAGS(RENDER_CALLBACK_FLAG);

enum class RENDER_CALLBACK_RETURN_FLAG
{
	NONE = 0,
	EXIT = (1 << 0),
	SKIP_Z = (1 << 1),
	SKIP_SET = (1 << 2),
	SAMPLED = (1 << 3),
} MAXON_ENUM_FLAGS(RENDER_CALLBACK_RETURN_FLAG);

enum class OBJECT_FLAG
{
	NONE = 0,
	NORMALS = (1 << 0),
	WORLD_THICKNESS = (1 << 1),
	CUSTOM_THICKNESS = (1 << 2),
	CUSTOM_WORLD_THICKNESS = (1 << 3),
	NO_SHADOWS = (1 << 4),
	NO_REFRACTION = (1 << 5),
	NO_REFLECTION = (1 << 6),
	NO_PRECULL = (1 << 7),
	REQUEST_SCREEN = (1 << 8),
	REQUEST_WORLD = (1 << 9),
	REQUEST_CAMERA = (1 << 10),
	REQUEST_TANGENTS = (1 << 11),
	VERTEX_COL_SAMPLING = (1 << 12),
	SAMPLING_AA = (1 << 13),
	RAYTRACED = (1 << 14),
	MP_NO_DEPTH = (1 << 15)
} MAXON_ENUM_FLAGS(OBJECT_FLAG);

enum class COORD_SPACE
{
	NONE = 0,
	LOCAL = 1,
	WORLD,
	CAMERA,
	SCREEN,
	CUSTOM
} MAXON_ENUM_LIST(COORD_SPACE);

enum class JOINT_TYPE
{
	NONE = 0,
	BEVEL = 1,
	ROUND,
	MITER
} MAXON_ENUM_LIST(JOINT_TYPE);

enum class INTERPOLATION_TYPE
{
	NONE = 0,
	LINEAR = 1
} MAXON_ENUM_LIST(INTERPOLATION_TYPE);

enum class CAP_TYPE
{
	NONE = 0,
	ROUND = 1,
	FLAT,
	SQUARE,
	LINEAR,
	ARROW,
	CUSTOM
} MAXON_ENUM_LIST(CAP_TYPE);

enum class RENDER_TYPE
{
	NONE = 0,
	RASTER = 1,
	CONE,
	RAY,
	RASTER_TILES,
	RASTER_NO_MP,
} MAXON_ENUM_LIST(RENDER_TYPE);

enum class SHADOW_TYPE
{
	NONE = 0,
	AUTO = 1,
	SOFT,
	HARD,
} MAXON_ENUM_LIST(SHADOW_TYPE);

enum class RENDER_FLAG
{
	NONE = 0,
	RENDER_CALLBACK = (1 << 0),
	RENDER_ALPHA_ONLY = (1 << 1),
	RENDER_NO_TRACER = (1 << 2),
	RENDER_BLENDING = (1 << 3),
	RENDER_SHADOWS = (1 << 4),
	RENDER_ERROR = (1 << 5),
	RENDER_UNINIT = (1 << 6),
	RENDER_REFRACTION = (1 << 7),
	RENDER_REFLECTION = (1 << 8),
	RENDER_BUCKETS = (1 << 9),
	RENDER_READY = (1 << 10)
} MAXON_ENUM_FLAGS(RENDER_FLAG);

enum class BLEND_MODE
{
	NONE = 0,
	AVERAGE = 1,
	NORMAL,
	MULTIPLY,
	SCREEN,
	DARKEN,
	LIGHT,
	DIFFERENCE,
	NEGATIVE,
	EXCLUSION,
	OVERLAY,
	HARDLIGHT,
	SOFTLIGHT,
	DODGE,
	BURN,
	REFLECT,
	GLOW,
	FREEZE,
	HEAT,
	ADD,
	SUB,
	STAMP,
	XOR,
	HUE,
	SATURATION,
	LUMINANCE,
	RED,
	GREEN,
	BLUE,
	OVERWRITE,
	LEVR,
} MAXON_ENUM_LIST(BLEND_MODE);

enum class RENDERDATA_FLAG
{
	NONE = 0,
	SCREEN = (1 << 0),
	WORLD = (1 << 1),
	CAMERA = (1 << 2),
	LINE = (1 << 3),
	TRACING = (1 << 4),
	REDUCED = (1 << 5),
	TANGENT = (1 << 6),
} MAXON_ENUM_FLAGS(RENDERDATA_FLAG);

enum class SETCURVE_FLAGS
{
	NONE = 0,
	CLONE = (1 << 0),
	OWN = (1 << 1)
} MAXON_ENUM_FLAGS(SETCURVE_FLAGS);

enum class MPBUFFER_FLAGS
{
	NONE = 0,
	MUL = (1 << 0),
	DEPTH = (1 << 1),
	ALPHA = (1 << 2),
	INVERT = (1 << 3),
} MAXON_ENUM_FLAGS(MPBUFFER_FLAGS);

class JointData
{
public:

	JointData()
	{
		m_Theta = 0.0;
		m_CosTheta = 0.0;
		m_BevelHeight = 0.0;
		m_MiterHeight = 0.0;
		_isJoint = false;
		_radius = 0.0;
		_worldRadius = 0.0;
	}

	Float m_Theta;
	Float m_CosTheta;
	Float32 m_BevelHeight, m_MiterHeight;

	Vector32 m_Normal, m_Axis;
	Vector32 m_LineNormal;

	Bool _isJoint;
	Float32 _radius;
	Float32 _worldRadius;
};

class LineData
{
public:

	LineData()
	{
		_screenLength = 0.0;
	}

	Vector32 GetNormal() const
	{
		return Vector32(_screenDirection.y, -_screenDirection.x , 0.0);
	}

	Vector32 _screenVertices[2];

	Vector32 _screenLine;
	Vector32 _screenDirection;

	Float32 _screenLength;

	Vector _cameraVertices[2];
	Vector32 _cameraNormal;
};

class Segment
{
public:

	Segment()
	{
		_count = 0;
	}

	explicit Segment(Int32 count, Bool closed = false)
	{
		Set(count, closed);
	}

	void Set(Int32 count, Bool closed = false)
	{
		_count = count;
		if (closed)
			_count |= segmentClosed;
	}
	UInt32 Get() { return _count; }

	Int32 GetCount() const { return _count & segmentMask; }
	Bool IsClosed() const  { return (_count & segmentClosed) != 0; }

private:

	UInt32 _count;
};

class LineRenderData
{
public:

	LineRenderData()
	{
		_object = nullptr;
		_lineRadius[0] = 0.0;
		_lineRadius[1] = 0.0;
		_thickness = 0.0;
		_worldThickness = 0.0;
		_curveIndex = NOTOK;
		_lineIndex = NOTOK;
		_vertexIndex = NOTOK;
		_baseIndex = NOTOK;
		_delta = 0.0;
		_curveDelta = 0.0;
		_lineCameraLen = 0.0;
		_deltaErr[0] = 0.0;
		_deltaErr[1] = 0.0;
		_prevLineCameraLen = 0.0;
		_nextLineCameraLen = 0.0;
		_jointData[0] = nullptr;
		_jointData[1] = nullptr;
		_lineData = nullptr;
		_toLineDist = 0.0;
		_toLineDistSigned = 0.0;
		_lineID = (UInt32)-1;
		_flags = RENDERDATA_FLAG::NONE;
		_vertices = nullptr;
		_screenVertices = nullptr;
		_cameraVertices = nullptr;
		_tangents = nullptr;
	}

	RENDERDATA_FLAG _flags;
	BiRenderObject *_object;

	Float32 _delta;					// delta position along the line segment
	Float32 _curveDelta;			// delta position along the entire curve (0-1), based on vertex position only

	Segment _segmentCount;

	Int32 _curveIndex;
	Int32 _lineIndex;			// line vertex index within the current curve
	Int32 _vertexIndex;		// vertex index within the main vertices (all curves)
	Int32 _baseIndex;			// index of the curves first vertex

	UInt32 _lineID;

	// world space (only valid if _flags & RENDERDATA_FLAG_WORLD)

	Vector _rayPosition;
	Vector _rayDirection;

	Vector _worldPosition;				// ray to curve intersection point in world space
	Vector _worldNormal;					// ray to curve intersection normal in world space
	Vector _worldLinePosition;		// _linePoint in world coordinates
	Vector _worldRenderPosition;	// render position in world coordinates
	Float32 _worldThickness;				// radius of line at the rendering (intersection) point

	// camera space (only valid if _flags & RENDERDATA_FLAG_CAMERA)

	Vector	_vertexCamera[4];		// line vertices in camera space, [0]-[1] is the current line, [2] previous vertex (only if a joint), [3] next vertex (only if a joint)
	Vector _normalCamera[2];		// joint normal in camera space

	Vector _jointAxisCamera[2]; // joint Z axis

	Float		_lineRadius[2];			// line radius
	Float		_lineCameraLen;			// line length

	Vector	_lineCameraDn;			// direction vector for the line
	Vector	_lineCameraNormal;	// line normal

	Float		_deltaErr[2];				// pixel error radius

	Vector _prevLineCameraDn;		// previous lines direction
	Float _prevLineCameraLen;		// previous lines length

	Vector _nextLineCameraDn;		// next lines direction
	Float _nextLineCameraLen;		// next lines length

	// screen space (only valid if _flags & RENDERDATA_FLAG_SCREEN)

	Vector32 _renderPosition;		// rendering pixel coordinate
	Vector32 _linePoint;				// position on the line segment

	Float32 _thickness;
	Float32 _toLineDist;				// distance to the rendering line

	JointData* _jointData[2];	// can be nullptr, always check
	LineData* _lineData;			// can be nullptr, always check

	// line space (only valid if _flags & RENDERDATA_FLAG_LINE)

	Matrix	_lineMg, _lineMi;		// camera to/from line space

	Vector _rayLinePosition;		// ray within coord space of the line (_lineMg)
	Vector _rayLineDirection;		// ray within coord space of the line (_lineMg)

	//  curve data

	const Vector *_vertices;
	const Vector32 *_screenVertices;
	const Vector *_cameraVertices;
	const Vector *_tangents;	// only valid RENDERDATA_FLAG_TANGENT, may also be nullptr

	Float32 _toLineDistSigned;	// signed distance to rendering line. Required for UVs
};

class CallbackData
{
public:
	virtual ~CallbackData() { }
	virtual void Flush() = 0;
};

class RenderCallbackLineData
{
public:
	Vector _p;

	Int32 _baseIndex;
	Int32 _vertexIndex;
	Int32 _lineIndex;
	Int32 _curveIndex;

	Segment _segmentCount;

	Float32 _pixelAlpha;
	Vector32 _pixelCol;
	Float32 _pixelZ;

	Vector32* _col;
	Float32* _alpha;
};

typedef void ShadingCallback(BiRenderObject *biObject, BiRenderVideoPost *bivp, VolumeData *volData, LineRenderData* lineData, Int32 cpuIndex, Vector32* col, Float32* alpha, Vector32 *mpData, SHADING_CALLBACK_FLAG flags, CallbackData* customData);
typedef RENDER_CALLBACK_RETURN_FLAG RenderCallback(BiRenderObject *biObject, BiRenderVideoPost *bivp, VolumeData *volData, RenderCallbackLineData *lineData, Int32 cpuIndex, RENDER_CALLBACK_FLAG flags, CallbackData* customData);

} // BIRENDER_END

class BiRenderObject
{
private:

	BiRenderObject();
	~BiRenderObject();

public:

	Int32 GetVertexCount();
	Vector *GetVertices();
	Int32 GetCurveCount();
	Bool SetCurveCount(Int32 curvecount, Int32 segmentcount, const birender::Segment *segments, const Vector *vertices, const Float32 *thickness, birender::SETCURVE_FLAGS flags);
	Int32 GetSegmentCount();
	birender::Segment *GetSegments();
	Float32 *GetThickness();

	birender::INTERPOLATION_TYPE GetInterpolation();
	void SetInterpolation(birender::INTERPOLATION_TYPE itype);

	birender::COORD_SPACE GetCoordSpace();
	Bool SetCoordSpace(birender::COORD_SPACE coord, BiRenderVideoPost *bipost);

	birender::JOINT_TYPE GetJointType();
	void SetJointType(birender::JOINT_TYPE jtype);
	void SetMiterLimit(Float theta);
	Float GetMiterLimit();

	birender::CAP_TYPE GetStartCapType();
	void SetStartCapType(birender::CAP_TYPE ctype);
	void SetStartCapSize(Float capw, Float caph);
	Vector GetStartCapSize();
	void SetStartCapCustom(BaseShader *shader);

	birender::CAP_TYPE GetEndCapType();
	void SetEndCapType(birender::CAP_TYPE ctype);
	void SetEndCapSize(Float capw, Float caph);
	Vector GetEndCapSize();
	void SetEndCapCustom(BaseShader *shader);

	void SetShadingCallback(birender::ShadingCallback* callback, birender::CallbackData* calldata);
	void SetRenderCallback(birender::RenderCallback* callback, birender::CallbackData* calldata);

	birender::OBJECT_FLAG GetFlags();
	void SetFlags(birender::OBJECT_FLAG flags, birender::FLAG_STATE state);

	birender::BLEND_MODE GetBlend();
	birender::BLEND_MODE GetSelfBlend();
	void SetBlend(birender::BLEND_MODE mode);
	void SetSelfBlend(birender::BLEND_MODE mode);

	void SetRayObject(const RayObject *rayObject);
	const RayObject *GetRayObject();

	void SetObject(BaseList2D *object);
	BaseList2D *GetObject(BaseDocument *doc);

	void Sample(birender::LineRenderData& lineData, VolumeData* voldata, BiRenderVideoPost* bipost, Vector32* pxCol, Float32* pxAlpha, Int32 cpuIndex);

	void SetOwner(Int32 id);
	Int32 GetOwner();
};

class BiRenderVideoPost : public BaseVideoPost
{
#ifndef __API_INTERN__
private:

	BiRenderVideoPost();
	~BiRenderVideoPost();

public:

	static BiRenderVideoPost *Alloc() { return (BiRenderVideoPost*)BaseVideoPost::Alloc(VPbirender); }
	static void Free(BiRenderVideoPost *&pPost) { BaseVideoPost *vp = pPost; BaseVideoPost::Free(vp); pPost = nullptr; }

#else
public:
#endif

	BiRenderObject *Append();

	Bool RemoveObject(Int32 index);
	void Flush();

	Int32 GetCount();
	BiRenderObject *GetObject(Int32 index);
	Float GetAAWidth();
	void SetAAWidth(Float aaw);
	birender::RENDER_TYPE GetRenderer();
	void SetRenderer(birender::RENDER_TYPE type);
	void SetShadow(birender::SHADOW_TYPE type, Float transDelta, Float distDelta, Int32 resolution, Int32 samples, Float aa);

	birender::RENDER_FLAG GetFlags();
	void SetFlags(birender::RENDER_FLAG flags, birender::FLAG_STATE state);

	Vector CalcShadow(const RayLight* light, VolumeData *volData, Int32 cpuIndex, const Vector &p, const Vector &n, const Vector &rayv, Float delta);

	Int32 AddBuffer(const String &name, birender::MPBUFFER_FLAGS flags, Int32 vpID);

	static BiRenderVideoPost *GetVideoPost(BaseDocument *doc);
	static BiRenderVideoPost *GetVideoPost(VolumeData *vd);

	void SetShadowState(Int32 cpuIndex, bool enabled);
};

struct BiRenderLib : public C4DLibrary
{
	BiRenderObject *(*bivpAppend)(BiRenderVideoPost *bivp);
	Bool (*bivpRemove)(BiRenderVideoPost *bivp, Int32 index);
	void (*bivpFlush)(BiRenderVideoPost *bivp);
	Int32 (*bivpGetCount)(BiRenderVideoPost *bivp);
	BiRenderObject *(*bivpGetObject)(BiRenderVideoPost *bivp, Int32 index);
	Float (*bivpGetAAWidth)(BiRenderVideoPost *bivp);
	void (*bivpSetAAWidth)(BiRenderVideoPost *bivp, Float aaw);
	birender::RENDER_TYPE (*bivpGetRenderer)(BiRenderVideoPost *bivp);
	void (*bivpSetRenderer)(BiRenderVideoPost *bivp, birender::RENDER_TYPE type);
	birender::RENDER_FLAG (*bivpGetFlags)(BiRenderVideoPost *bivp);
	void (*bivpSetFlags)(BiRenderVideoPost *bivp, birender::RENDER_FLAG flags, birender::FLAG_STATE state);
	Vector (*bivpCalcShadow)(BiRenderVideoPost *bivp, const RayLight* light, VolumeData *volData, Int32 cpuIndex, const Vector &p, const Vector &n, const Vector &rayv, Float delta);
	void (*bivpSetShadow)(BiRenderVideoPost *bivp, birender::SHADOW_TYPE type, Float transDelta, Float distDelta, Int32 resolution, Int32 samples, Float aa);
	Int32 (*bivpAddBuffer)(BiRenderVideoPost *bivp, const String &name, birender::MPBUFFER_FLAGS, Int32 vpID);

	Int32 (*biopGetVertexCount)(BiRenderObject *biobject);
	Vector *(*biopGetVertices)(BiRenderObject *biobject);
	Int32 (*biopGetCurveCount)(BiRenderObject *biobject);
	Bool (*biopSetCurveCount)(BiRenderObject *biobject, Int32 curvecount, Int32 segmentcount, const birender::Segment *segments, const Vector *vertices, const Float32 *thickness, birender::SETCURVE_FLAGS flags);
	Int32 (*biopGetSegmentCount)(BiRenderObject *biobject);
	birender::Segment *(*biopGetSegments)(BiRenderObject *biobject);
	birender::INTERPOLATION_TYPE (*biopGetInterpolation)(BiRenderObject *biobject);
	void (*biopSetInterpolation)(BiRenderObject *biobject, birender::INTERPOLATION_TYPE itype);
	birender::COORD_SPACE (*biopGetCoordSpace)(BiRenderObject *biobject);
	Bool (*biopSetCoordSpace)(BiRenderObject *biobject, birender::COORD_SPACE coord, BiRenderVideoPost *bipost);
	birender::JOINT_TYPE (*biopGetJointType)(BiRenderObject *biobject);
	void (*biopSetJointType)(BiRenderObject *biobject, birender::JOINT_TYPE jtype);
	birender::CAP_TYPE (*biopGetStartCapType)(BiRenderObject *biobject);
	void (*biopSetStartCapType)(BiRenderObject *biobject, birender::CAP_TYPE ctype);
	Float32 *(*biopGetThickness)(BiRenderObject *biobject);
	void (*biopSetMiterLimit)(BiRenderObject *biobject, Float theta);
	void (*biopSetStartCapSize)(BiRenderObject *biobject, Float capw, Float caph);
	Vector (*biopGetStartCapSize)(BiRenderObject *biobject);
	void (*biopSetShadingCallback)(BiRenderObject *biobject, birender::ShadingCallback* callback, birender::CallbackData* calldata);
	void (*biopSetRenderCallback)(BiRenderObject *biobject, birender::RenderCallback* callback, birender::CallbackData* calldata);
	birender::OBJECT_FLAG (*biopGetFlags)(BiRenderObject *biobject);
	void (*biopSetFlags)(BiRenderObject *biobject, birender::OBJECT_FLAG flags, birender::FLAG_STATE state);
	birender::BLEND_MODE (*biopGetBlend)(BiRenderObject *biobject);
	birender::BLEND_MODE (*biopGetSelfBlend)(BiRenderObject *biobject);
	void (*biopSetBlend)(BiRenderObject *biobject, birender::BLEND_MODE mode);
	void (*biopSetSelfBlend)(BiRenderObject *biobject, birender::BLEND_MODE mode);
	void (*biopSetRayObject)(BiRenderObject *biobject, const RayObject *rayObject);
	const RayObject* (*biopGetRayObject)(BiRenderObject *biobject);
	void (*biopSample)(BiRenderObject *biobject, birender::LineRenderData& lineData, VolumeData* voldata, BiRenderVideoPost* bipost, Vector32* pxCol, Float32* pxAlpha, Int32 cpuIndex);
	void (*biopSetObject)(BiRenderObject *biobject, BaseList2D *object);
	BaseList2D *(*biopGetObject)(BiRenderObject *biobject, BaseDocument *doc);
	birender::CAP_TYPE (*biopGetEndCapType)(BiRenderObject *biobject);
	void (*biopSetEndCapType)(BiRenderObject *biobject, birender::CAP_TYPE ctype);
	void (*biopSetEndCapSize)(BiRenderObject *biobject, Float capw, Float caph);
	Vector (*biopGetEndCapSize)(BiRenderObject *biobject);
	Float (*biopGetMiterLimit)(BiRenderObject *biobject);
	void (*biopSetStartCapCustom)(BiRenderObject *biobject, BaseShader *shader);
	void (*biopSetEndCapCustom)(BiRenderObject *biobject, BaseShader *shader);
	void (*biopSetOwner)(BiRenderObject *biobject, Int32 id);
	Int32 (*biopGetOwner)(BiRenderObject *biobject);

	void (*bivpSetShadowState)(BiRenderVideoPost *bivp, Int32 cpuIndex, bool enabled);
};

#endif // LIB_BIRENDER_H__
