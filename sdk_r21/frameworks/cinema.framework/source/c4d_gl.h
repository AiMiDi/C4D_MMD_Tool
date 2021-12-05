#ifndef C4D_GL_H__
#define C4D_GL_H__


#ifdef __API_INTERN__
	#include "maxon/crc32c.h"
	#include "matrix4.h"
#else
	#include "c4d_basedocument.h"
	#include "ge_math.h"
	#include "matrix4.h"
#endif	// __API_INTERN__

#ifndef C4D_GL_VARS_DEFINED
enum GlVertexBufferSubBufferType { VBArrayBuffer = 0, VBElementArrayBuffer = 1, VBTextureBuffer = 3 };
enum GlVertexBufferAccessFlags { VBReadWrite = 0, VBReadOnly = 1, VBWriteOnly = 2 };
#if defined MAXON_TARGET_WINDOWS
typedef	UINT C4DGLuint;
typedef INT C4DGLint;
#elif defined MAXON_TARGET_MACOS
typedef unsigned int	C4DGLuint;
typedef int						C4DGLint;
#elif defined MAXON_TARGET_LINUX
typedef	UINT C4DGLuint;
typedef INT C4DGLint;
	#endif
typedef Int GlProgramParameter;
	#define C4D_GL_VARS_DEFINED
#endif

// use as program parameters (while processing the GL_GET_IDENTITY message)
#define GL_PROGRAM_PARAM_OBJECTCOORD					0x0000000000000001
#define GL_PROGRAM_PARAM_WORLDCOORD						0x0000000000000002
#define GL_PROGRAM_PARAM_NORMALS							0x0000000000000004
#define GL_PROGRAM_PARAM_DUDV									0x0000000000000008
#define GL_PROGRAM_PARAM_UV										0x0000000000000010
#define GL_PROGRAM_PARAM_UVW									0x0000000000000030 // implies GL_PROGRAM_PARAM_UV
#define GL_PROGRAM_PARAM_COLOR								0x0000000000000040
#define GL_PROGRAM_PARAM_EYEPOSITION					0x0000000000000100
#define GL_PROGRAM_PARAM_POLYNORMALS					0x0000000000000200
#define GL_PROGRAM_PARAM_POLYNORMALS_FP				0x0000000000000600 // implies GL_PROGRAM_PARAM_POLYNORMALS
#define GL_PROGRAM_PARAM_EYEDIRECTION					0x0000000000000800
#define GL_PROGRAM_PARAM_IGNORECOLORSPACE			0x0000000000001000
#define GL_PROGRAM_PARAM_UVW4_FP							0x0000000000010000 // pass 4-component UVW coordinates to the fragment program
#define GL_PROGRAM_PARAM_OBJECTMATRIX_FP			0x0000000000020000 // pass object matrix to the fragment program
#define GL_PROGRAM_PARAM_STICKTEXTURECOORD		0x0000000000040000 // pass stick texture coordinates to the fragment program (if present, don't set this flag if GlGetIdentity::bHasStickTexture is false)
#define GL_PROGRAM_PARAM_DONT_RECEIVE_SHD			0x0000000000080000 // set, if you don't want the object to receive shadows
#define GL_PROGRAM_PARAM_CHANGE_NORMAL				0x0000000000100000 // execute GL_PASS_BEFORE_LIGHT pass
#define GL_PROGRAM_PARAM_AFTER_LIGHT					0x0000000000200000 // execute GL_PASS_AFTER_LIGHT pass
#define GL_PROGRAM_PARAM_DISPLACE							0x0000000000400000 // execute GL_PASS_DISPLACE pass, you must set GL_PROGRAM_PARAM_DUDV, too
#define GL_PROGRAM_PARAM_DISPLACE_NORMAL			0x0000000000800000 // program requires displace normals
#define GL_PROGRAM_PARAM_NOISE_VERTEX					0x0000000001000000 // the vertex program needs a noise function
#define GL_PROGRAM_PARAM_NOISE_FRAGMENT				0x0000000002000000 // the fragment program needs a noise function
#define GL_PROGRAM_PARAM_NOISE_GEOMETRY				0x0000000004000000 // the geometry program needs a noise function
#define GL_PROGRAM_PARAM_NOISE_TESSEVAL				0x0000000008000000 // the tessellation evaluation program needs a noise function
#define GL_PROGRAM_PARAM_FRAGMENT_COORD				0x0000000010000000 // make fragment coordinates available in the fragment shader
#define GL_PROGRAM_PARAM_COLOR_DATA						0x0000000020000040 // implies GL_PROGRAM_PARAM_COLOR, don't store data in VBO, but pass it between the programs
#define GL_PROGRAM_PARAM_FORCE_GET_IDENT			0x0000000080000000
#define GL_PROGRAM_PARAM_NEEDS_CORRECTEDUVS		0x0000000100000000 //Uses GeometryShader and Quadrilateral Interpolation for Quads
#define GL_PROGRAM_PARAM_POLYCOLOR						0x0000000200000000
#define GL_PROGRAM_PARAM_WORLD_TO_CLIP				0x0000000400000000 // Make the world-to-clip transformation matrix available to the fragment stage.

// returned by GetLanguageFeatures
#define GL_PROGRAM_FEATURE_VAR_LEN_LOOP	0x00000001	// variable-length loop
#define GL_PROGRAM_FEATURE_DERIVATES		0x00000002	// support for dFdx and dFdy
#define GL_PROGRAM_FEATURE_UINT					0x00000004	// unsigned integer

// use for AddParameters (format)
#define GL_FORMAT_NORMAL_FLOAT 0x00000001	// request normal vector as float values
#define GL_FORMAT_UV_FLOAT		 0x00000002	// request UV(W) coordinates as float values
#define GL_FORMAT_DUDV_FLOAT	 0x00000004	// request DU and DV vectors as float values
#define GL_FORMAT_COLOR_FLOAT	 0x00000008	// request color (RGBA) as float values

// GetFlags
#define GL_PROGRAM_FACTORY_STATUS_OK							  0x00000001	// program compiled and linked successfully and runs in hardware
#define GL_PROGRAM_FACTORY_STATUS_PARAM_UNIFORM_V	  0x00000002	// too many uniform parameters in the vertex program
#define GL_PROGRAM_FACTORY_STATUS_PARAM_UNIFORM_F	  0x00000004	// too many uniform parameters in the fragment program
#define GL_PROGRAM_FACTORY_STATUS_PARAM_TEXTURE_V	  0x00000008	// too many textures used in the vertex program
#define GL_PROGRAM_FACTORY_STATUS_PARAM_TEXTURE_F	  0x00000010	// too many textures used in the fragment program
#define GL_PROGRAM_FACTORY_STATUS_COMPILE_ERR_V		  0x00000020	// vertex program compilation error
#define GL_PROGRAM_FACTORY_STATUS_COMPILE_ERR_F		  0x00000040	// fragment program compilation error
#define GL_PROGRAM_FACTORY_STATUS_PARAM_UNIFORM_G	  0x00000080	// too many uniform parameters in the geometry program
#define GL_PROGRAM_FACTORY_STATUS_PARAM_TEXTURE_G	  0x00000100	// too many textures used in the geometry program
#define GL_PROGRAM_FACTORY_STATUS_COMPILE_ERR_G		  0x00000200	// geometry program compilation error
#define GL_PROGRAM_FACTORY_STATUS_LOAD_PROGRAM		  0x00000400	// internal error during loading the programs
#define GL_PROGRAM_FACTORY_STATUS_LINK_ERROR			  0x00000800	// linking failed
#define GL_PROGRAM_FACTORY_STATUS_PARAM_UNIFORM_TC	0x00001000	// too many uniform parameters in the tessellation control program
#define GL_PROGRAM_FACTORY_STATUS_PARAM_TEXTURE_TC	0x00002000	// too many textures used in the tessellation control program
#define GL_PROGRAM_FACTORY_STATUS_COMPILE_ERR_TC		0x00004000	// tessellation control program compilation error
#define GL_PROGRAM_FACTORY_STATUS_PARAM_UNIFORM_TE	0x00008000	// too many uniform parameters in the tessellation evaluation program
#define GL_PROGRAM_FACTORY_STATUS_PARAM_TEXTURE_TE	0x00010000	// too many textures used in the tessellation evaluation program
#define GL_PROGRAM_FACTORY_STATUS_COMPILE_ERR_TE		0x00020000	// tessellation evaluation program compilation error


// SetParameterTexture flags
#define GL_PROGRAM_FACTORY_TEXTURE_TILE				0x00000001						// tile
#define GL_PROGRAM_FACTORY_TEXTURE_SEAMLESS		0x00000002						// seamless
#define GL_PROGRAM_FACTORY_TEXTURE_CORRECTION	0x00000004						// apply color correction
// nearest, interpolate and mipmap are mutually exclusive and override default settings
#define GL_PROGRAM_FACTORY_TEXTURE_NEAREST							 0x00000010	// nearest
#define GL_PROGRAM_FACTORY_TEXTURE_INTERPOLATE					 0x00000020	// interpolate
#define GL_PROGRAM_FACTORY_TEXTURE_MIPMAP								 0x00000040	// mipmap
#define GL_PROGRAM_FACTORY_TEXTURE_KEEPSIZE							 0x00000080	// does not scale down the image if GL_EXT_texture_array is available
#define GL_PROGRAM_FACTORY_TEXTURE_SRGB									 0x00000100	// allow SRGB texture format (requires GL_EXT_texture_sRGB)
#define GL_PROGRAM_FACTORY_TEXTURE_COLOR_IMAGE_TO_LINEAR 0x00001000	// convert from embedded profile to linear
#define GL_PROGRAM_FACTORY_TEXTURE_COLOR_SRGB_TO_LINEAR	 0x00002000	// convert from SRGB to linear
#define GL_PROGRAM_FACTORY_TEXTURE_COLOR_IMAGE_TO_SRGB	 0x00003000	// convert from embedded profile to SRGB
#define GL_PROGRAM_FACTORY_TEXTURE_COLOR_LINEAR_TO_SRGB	 0x00004000	// convert from linear to SRGB
#define GL_PROGRAM_FACTORY_TEXTURE_COLOR_MASK						 0x000ff000

#define GL_PROGRAM_FACTORY_GEOMETRY_IN_LINES							 1
#define GL_PROGRAM_FACTORY_GEOMETRY_IN_TRIANGLES					 2
#define GL_PROGRAM_FACTORY_GEOMETRY_IN_LINES_ADJACENCY		 3
#define GL_PROGRAM_FACTORY_GEOMETRY_IN_TRIANGLES_ADJACENCY 4
#define GL_PROGRAM_FACTORY_GEOMETRY_IN_POINTS							 5
#define GL_PROGRAM_FACTORY_GEOMETRY_OUT_LINE_STRIP				 1
#define GL_PROGRAM_FACTORY_GEOMETRY_OUT_TRIANGLE_STRIP		 2

// messages
#define GL_GET_IDENTITY						450000200
#define GL_ADD_UNIFORM_PARAMETERS	450000201
#define GL_ADD_PROGRAM_CODE				450000202
#define GL_INIT_DESCRIPTION				450000203
#define GL_SET_UNIFORM_PARAMETERS	450000204
#define GL_COMPILE_CGFX						450000238
#define GL_BIND_CGFX							450000239
#define GL_DELETE_VBO_CACHE_ITEM				450000240

// framebuffer flags
#define C4D_FRAMEBUFFER_COLOR						0x00000001
#define C4D_FRAMEBUFFER_DEPTH						0x00000002
#define C4D_FRAMEBUFFER_ALPHA						0x00000004
#define C4D_FRAMEBUFFER_SCALEUP					0x00000100
#define C4D_FRAMEBUFFER_SCALEDOWN				0x00000200
#define C4D_FRAMEBUFFER_ALLOW_NPOT			0x00000400
#define C4D_FRAMEBUFFER_16BIT						0x00000800
#define C4D_FRAMEBUFFER_RG32F_TEXTURE		0x00001000
#define C4D_FRAMEBUFFER_COLOR_ALPHA			(C4D_FRAMEBUFFER_COLOR | C4D_FRAMEBUFFER_ALPHA)	// may only be used for GlFrameBuffer::CopyToBitmap and GlFrameBuffer::SaveTextureToDisk
#define C4D_FRAMEBUFFER_CUBE_POSITIVE_X	0x00010000																			// only allowed for SetRenderTarget
#define C4D_FRAMEBUFFER_CUBE_POSITIVE_Y	0x00020000
#define C4D_FRAMEBUFFER_CUBE_POSITIVE_Z	0x00040000
#define C4D_FRAMEBUFFER_CUBE_NEGATIVE_X	0x00080000
#define C4D_FRAMEBUFFER_CUBE_NEGATIVE_Y	0x00100000
#define C4D_FRAMEBUFFER_CUBE_NEGATIVE_Z	0x00200000
#define C4D_FRAMEBUFFER_CUBE_MASK				0x003f0000
#define C4D_FRAMEBUFFER_ALPHA_NOBLEND		0x00400000

// additional Framebuffer textures
#define C4D_FRAMEBUFFER_UV							0x0000008
#define C4D_FRAMEBUFFER_DU							0x0000010
#define C4D_FRAMEBUFFER_DV							0x0000020
#define C4D_FRAMEBUFFER_NORMAL					0x0000040	// requires GL_ARB_texture_float
#define C4D_FRAMEBUFFER_WORLDCOORD			0x0000080	// requires GL_ARB_texture_float
#define C4D_FRAMEBUFFER_MATERIAL_ID			0x0000100	// requires the GL_EXT_texture_integer and GL_EXT_gpu_shader4 extensions, this must be an unsigned integer texture
#define C4D_FRAMEBUFFER_OBJECT_MAT_ID		0x0000200	// requires the GL_EXT_texture_integer and GL_EXT_gpu_shader4 extensions, this must be an unsigned integer texture
#define C4D_FRAMEBUFFER_UV_MAT_FLOAT		0x0000400	// UVW and material ID packed into a floating-point RGBA value, requires GL_ARB_texture_float
#define C4D_FRAMEBUFFER_TEXEL_SELECTION	0x0000800	// Per-pixel texel selection state {-1: unselected, 0: uncovered, 1:selected} stored in a signed integer integer

// additional framebuffer data types
#define C4D_FRAMEBUFFER_8_BIT_INT		 1
#define C4D_FRAMEBUFFER_16_BIT_INT	 2
#define C4D_FRAMEBUFFER_32_BIT_INT	 3
#define C4D_FRAMEBUFFER_8_BIT_UINT	 4
#define C4D_FRAMEBUFFER_16_BIT_UINT	 5
#define C4D_FRAMEBUFFER_32_BIT_UINT	 6
#define C4D_FRAMEBUFFER_16_BIT_FLOAT 7
#define C4D_FRAMEBUFFER_32_BIT_FLOAT 8

// allowed as texture and flags for SetRenderTarget
#define C4D_FRAMEBUFFER_TARGET_TEX_ADDITIONAL	-1
#define C4D_FRAMEBUFFER_TARGET_FLAG_ACTIVE		1

// noise types
// don't forget to set GL_PROGRAM_PARAM_NOISE
#define GL_NOISE_SNOISE_1D						 -1		// SNoise1D(float pos)
#define GL_NOISE_SNOISE_2D						 -2		// SNoise2D(vec2 pos)
#define GL_NOISE_SNOISE_3D						 -3		// SNoise3D(vec3 pos)
#define GL_NOISE_SNOISE_4D						 -4		// SNoise4D(vec4 pos, float repeat)
#define GL_NOISE_TURBULENCE_3D				 -8		// Turbulence3D(vec3 pos, float octaves)
#define GL_NOISE_TURBULENCE_4D				 -9		// Turbulence4D(vec4 pos, float octaves, float repeat)
#define GL_NOISE_FBM_3D								 -12	// Fbm3D(vec3 pos, float octaves)
#define GL_NOISE_FBM_4D								 -13	// Fbm4D(vec4 pos, float octaves, float repeat)
#define GL_NOISE_RIDGEDMULTIFRACTAL_3D -14	// RidgedMultifractal3D(vec3 pos, float octaves, float offset, float gain)
#define GL_NOISE_RIDGEDMULTIFRACTAL_4D -15	// RidgedMultifractal4D(vec4 pos, float octaves, float offset, float gain, float repeat)
#define GL_NOISE_FAST_SNOISE					 -16	// FastSNoise(vec3 pos)
#define GL_NOISE_FAST_TURBULENCE			 -17	// FastTurbulence(vec3 pos, float octave)
// allowed noises from lib_noise.h:
// NOISE_BOX_NOISE NoiseBoxNoise(vec4 pos, float repeat)
// NOISE_BLIST_TURB NoiseBisteredTurb(vec4 pos, float octaves, float repeat)
// NOISE_BUYA NoiseBuya(vec4 pos, float octaves, float repeat)
// NOISE_CELL_NOISE NoiseCellNoise(vec4 pos, float repeat)
// NOISE_CRANAL NoiseCranal(vec4 pos, float octaves, float repeat)
// NOISE_DENTS NoiseDents(vec4 pos, float octaves, float repeat)
// NOISE_DISPL_TURB NoiseDisplTurbulence(vec4 pos, float octaves, float repeat)
// NOISE_FBM NoiseFbm(vec4 pos, float octaves, float repeat)
// NOISE_HAMA NoiseHama(vec4 pos, float octaves, float repeat)
// NOISE_LUKA NoiseLuka(vec4 pos, float octaves, float repeat)
// NOISE_MOD_NOISE NoiseModNoise(vec4 pos, float repeat)
// NOISE_NAKI NoiseNaki(vec4 pos, float octaves, float repeat)
// NOISE_NOISE NoiseNoise(vec4 pos, float repeat)
// NOISE_NUTOUS NoiseNutous(vec4 pos, float octaves, float repeat)
// NOISE_OBER NoiseOber(vec4 pos, float octaves, float repeat)
// NOISE_PEZO NoisePezo(vec4 pos, float octaves, float repeat)
// NOISE_POXO NoisePoxo(vec4 pos, float octaves, float repeat)
// NOISE_RANDOM NoiseRandom(float pos)
// NOISE_SEMA NoiseSema(vec4 pos, float octaves, float repeat)
// NOISE_STUPL NoiseStupl(vec4 pos, float octaves, float repeat)
// NOISE_TURBULENCE NoiseTurbulence(vec4 pos, float octaves, float repeat)
// NOISE_VL_NOISE NoiseVlNoise(vec4 pos, float repeat)
// NOISE_WAVY_TURB NoiseWavyTurbulence(vec4 pos, float octaves, float repeat)
// NOISE_FIRE NoiseFire(vec4 pos, float octaves, float repeat)
// NOISE_ELECTRIC NoiseElectric(vec4 pos, float repeat)
// NOISE_GASEOUS NoiseGaseous(vec4 pos, float repeat)
// NOISE_ZADA NoiseZada(vec4 pos, float octaves, float repeat)

// flags for AddNoiseFunction
#define GL_ADD_NOISE_FUNCTION_ABSOLUTE			1
#define GL_ADD_NOISE_FUNCTION_COMPATIBILITY	2

// for return values for GlMessage see GL_MESSAGE

// color conversion constants for DrawBuffer
#define DRAW_BUFFER_COLOR_NO_CHANGE			 0
#define DRAW_BUFFER_COLOR_SRGB_TO_LINEAR 1
#define DRAW_BUFFER_COLOR_LINEAR_TO_SRGB 2
#define DRAW_BUFFER_COLOR_USE_TEXTURE_1D 3
#define DRAW_BUFFER_COLOR_USE_TEXTURE_3D 4

// Flags for DrawSubbuffer
#define DRAW_SUBBUFFER_FLAGS											 0
#define DRAW_SUBBUFFER_FLAGS_PRIMITIVERESTARTINDEX (1 << 0)
#define DRAW_SUBBUFFER_FLAGS_SHADER_POINT_SIZE		 (1 << 1)

class BaseDocument;
class BaseDraw;
class BaseMaterial;
class BaseObject;
class BaseTag;
class GlString;
class Gradient;
class TextureTag;
class UVWTag;

class GlProgramFactory;
struct GlFBAdditionalTextureInfo;

#define LightHasAspect(_type_) (_type_ == RT_LT_SPOT || _type_ == RT_LT_SPOTRECT || _type_ ==	RT_LT_PARSPOT || _type_ == RT_LT_PARSPOTRECT)
#define LightHasEdgeFalloff(_type_) (_type_ == RT_LT_SPOT || _type_ == RT_LT_SPOTRECT || _type_ ==	RT_LT_PARSPOT || _type_ == RT_LT_PARSPOTRECT)
#define LightHasFalloff(_f_) ((_f_) == RT_FALLOFF_STEP || (_f_) == RT_FALLOFF_LINEAR || (_f_) == RT_FALLOFF_INVERSE || \
															(_f_) == RT_FALLOFF_INVERSE_CLAMPED || (_f_) == RT_FALLOFF_SQUARE || (_f_) == RT_FALLOFF_SQUARE_CLAMPED || (_f_) == 2 || (_f_) == 3)
#define GlShaderAddCodeBump(_pass_, _channel_) (((_channel_) == CHANNEL_BUMP && (_pass_) == GL_PASS_BEFORE_LIGHT) || ((_channel_) == CHANNEL_DISPLACEMENT && (_pass_) == GL_PASS_DISPLACE_BUMP))
#define GlShaderAddCodeColor(_pass_, _channel_) ( \
																								((_pass_) == GL_PASS_BEFORE_LIGHT && (((_channel_) == CHANNEL_NORMAL) || ((_channel_) == CHANNEL_DIFFUSION) || ((_channel_) == CHANNEL_REFLECTION))) || \
																								((_pass_) == GL_PASS_LIGHT && (((_channel_) == CHANNEL_COLOR) || ((_channel_) == CHANNEL_SPECULARCOLOR))) || \
																								((_pass_) == GL_PASS_AFTER_LIGHT && (((_channel_) == CHANNEL_ENVIRONMENT) || ((_channel_) == CHANNEL_LUMINANCE)))  \
																								)
#define GlShaderAddCodeTransp(_pass_, _channel_) ((_channel_) == CHANNEL_TRANSPARENCY && (_pass_) == GL_PASS_AFTER_LIGHT)
#define GlShaderAddCodeAlpha(_pass_, _channel_) ((_channel_) == CHANNEL_ALPHA && (_pass_) == GL_PASS_AFTER_LIGHT)
#define GlShaderAddCodeDisplace(_pass_, _channel_) ((_channel_) == CHANNEL_DISPLACEMENT && ((_pass_) == GL_PASS_DISPLACE || (_pass_) == GL_PASS_SUBDIVIDE_SAMPLE))

// vertex buffer defines
// keep this order in your data structure for maximal performance
#define C4D_VERTEX_BUFFER_VERTEX		 0	// 2, 3, 4 elements
#define C4D_VERTEX_BUFFER_NORMAL		 2	// has always 3 elements
#define C4D_VERTEX_BUFFER_COLOR			 3	// 3, 4
#define C4D_VERTEX_BUFFER_POLYNORMAL 4	// 3 (secondary color)
// #define C4D_VERTEX_BUFFER_FOG_COORD		5
// #define C4D_VERTEX_BUFFER_POINTSIZE	6
#define C4D_VERTEX_BUFFER_TEX_COORD_0	8	// 1, 2, 3, 4
#define C4D_VERTEX_BUFFER_TEX_COORD_1	9
#define C4D_VERTEX_BUFFER_TEX_COORD_2	10
#define C4D_VERTEX_BUFFER_TEX_COORD_3	11
#define C4D_VERTEX_BUFFER_TEX_COORD_4	12
#define C4D_VERTEX_BUFFER_TEX_COORD_5	13
#define C4D_VERTEX_BUFFER_TEX_COORD_6	14
#define C4D_VERTEX_BUFFER_TEX_COORD_7	15
#define C4D_VERTEX_BUFFER_MAX_VALUE		15

#define C4D_VERTEX_BUFFER_TRIANGLES								 0
#define C4D_VERTEX_BUFFER_QUADS										 1
#define C4D_VERTEX_BUFFER_TRIANGLES_WIRE					 2
#define C4D_VERTEX_BUFFER_QUADS_WIRE							 3
#define C4D_VERTEX_BUFFER_TRIANGLE_FAN						 4
#define C4D_VERTEX_BUFFER_POINTS									 5
#define C4D_VERTEX_BUFFER_LINES										 6
#define C4D_VERTEX_BUFFER_LINE_STRIP							 7
#define C4D_VERTEX_BUFFER_TRIANGLE_STRIP					 8
#define C4D_VERTEX_BUFFER_LINES_ADJACENCY					 9
#define C4D_VERTEX_BUFFER_LINE_STRIP_ADJACENCY		 10
#define C4D_VERTEX_BUFFER_TRIANGLE_STRIP_ADJACENCY 11
#define C4D_VERTEX_BUFFER_TRIANGLES_ADJACENCY			 12
#define C4D_VERTEX_BUFFER_PATCHES                  13
#define C4D_VERTEXBUFFER_MAX_DATACOUNT						 16

#ifdef __API_INTERN__
	#include "gl_string.h"
#else
class GlString
{
private:
	C4D_RESERVE_PRIVATE_TYPE(void*, dummy1);
	C4D_RESERVE_PRIVATE_TYPE(Int, dummy2);
	C4D_RESERVE_PRIVATE_TYPE(Int, dummy3);
	C4D_RESERVE_PRIVATE_TYPE(Int, dummy4);
	C4D_RESERVE_PRIVATE_TYPE(Int, dummy5);
	C4D_RESERVE_PRIVATE_TYPE(Int, dummy6);

public:
	GlString();
	GlString(const char* pszString);
	GlString(const GlString& str);
	explicit GlString(Int32 n);
	explicit GlString(Float r, const char* pszFormat);
	~GlString();

	const GlString& operator = (const GlString& str);
	const GlString& operator = (const char* pszString);

	friend const GlString operator + (const GlString& str1, const GlString& str2);
	const GlString& operator += (const GlString& str);
	friend const GlString operator + (const GlString& str1, const char* str2);
	const GlString& operator += (const char* str);

	friend Bool operator == (const GlString& a, const GlString& b) { return a.Compare(b) == 0; }
	Int32 Compare(const GlString& s) const;

	const char* GetCString() const;
	Int GetLength() const;
	maxon::Block<const Char> ToBlock() const
	{
		return maxon::Block<const Char>(GetCString(), GetLength());
	}

	Int32 Replace(const GlString& strSearch, const GlString& strReplace, Int lStart = 0, Bool bReplaceAll = true, Bool bOnlyWord = true);
};
#endif

struct GlVertexBufferDrawSubbuffer
{
	GlVertexBufferDrawSubbuffer() { }

	GlVertexBufferDrawSubbuffer(Int32 _lType, Int32 _lCount, Int32 _lOffset, Int32 _lPatchVertices = 0)
	{
		lType		        = _lType;
		lCount	        = _lCount;
		lOffset         = _lOffset;
		lPatchVertices  = _lPatchVertices;
	}

	Int32 lType;
	Int32 lCount;
	Int32 lOffset;
	Int32 lPatchVertices;
};

class GlVertexBufferAttributeInfo
{
public:
#ifdef __API_INTERN__
	void UpdateCrc(maxon::Crc32C& crc) const { crc.Update(lVector); crc.Update(lIndex); crc.Update(strDeclaration.ToBlock()); }
#endif
	GlVertexBufferAttributeInfo()
	{
		bContinuous = false;
		ulData = 0;
		lCount = 0;
	}
	GlString strDeclaration, strName;
	Bool	 bContinuous;	// true, if the vector is continuous (starts at lIndex[0])
	UInt32 ulData;			// one of the POLYOBJECT_VBO_* constants
	Int32	 lVector[4], lIndex[4];
	Int32	 lCount;
};

class GlVertexBufferVectorInfo
{
public:
#ifdef __API_INTERN__
	void UpdateCrc(maxon::Crc32C& crc) const
	{
		crc.UpdateInt32(lDataType);
		crc.UpdateInt32(lCount);
		crc.UpdateInt32(nAttribLocation);
		crc.UpdateInt(lOffset);
		crc.UpdateInt(lStride);
		crc.UpdateBool(bNormalize != 0);
		crc.Update(strType.ToBlock());
		crc.Update(strName.ToBlock());
	}
#endif
	GlVertexBufferVectorInfo() { lDataType = lCount = 0; lOffset = lStride = 0; bNormalize = true; nAttribLocation = nUniformLocation = -1; }

	GlString strType, strName;
	Int32		 lDataType, lCount;
	Int			 lOffset, lStride;
	Bool		 bNormalize;

	C4DGLint nAttribLocation, nUniformLocation;	// private
};

// the same like the OpenGL types
#define C4D_GL_DATATYPE_BYTE					 0x1400
#define C4D_GL_DATATYPE_UNSIGNED_BYTE	 0x1401
#define C4D_GL_DATATYPE_SHORT					 0x1402
#define C4D_GL_DATATYPE_UNSIGNED_SHORT 0x1403
#define C4D_GL_DATATYPE_INT						 0x1404
#define C4D_GL_DATATYPE_UNSIGNED_INT	 0x1405
#define C4D_GL_DATATYPE_FLOAT					 0x1406
#define C4D_GL_DATATYPE_2_BYTES				 0x1407
#define C4D_GL_DATATYPE_3_BYTES				 0x1408
#define C4D_GL_DATATYPE_4_BYTES				 0x1409
#define C4D_GL_DATATYPE_DOUBLE				 0x140A

#define C4D_VERTEX_BUFFER_FORCE_DELETE 0x00000001
#define C4D_VERTEX_BUFFER_GET_ANY			 0x00000002

// for GlProgramFactory::GetFactory
#define GL_GET_PROGRAM_FACTORY_ALLOW_SHARING 1
#define GL_GET_PROGRAM_FACTORY_CGFX					 2

#ifndef C4D_ALIGN
#if defined MAXON_TARGET_WINDOWS
#define C4D_ALIGN(_x_, _a_)		__declspec(align(_a_)) _x_
#else
#define C4D_ALIGN(_x_, _a_)		_x_ __attribute__((aligned(_a_)))
#endif
#endif

struct RayLgt;
enum GlShadowType { GlShadowTypeOff = 0, GlShadowTypeHard = 1, GlShadowTypeSoft = 2 };
struct GlLight
{
	GlLight() { ulLastBufferCRC = (UInt32) - 1; lFlags = 0; }
	UInt32		ulDataCRC;				// must be the first structure member
	UInt32		ulStructureCRC;
	UInt32		ulLastBufferCRC;	// private (-1)
	RayLgt*		pRayLight;				// private (nullptr)
	C4DGLuint nBufferBinding;		// private (-1)

	Int				lSize;

	// affect Cg program
	C4DGLuint		 nBuffer;	// private (0)
	Int32				 lType;
	GlShadowType shadowType;
	Gradient*		 pEdgeFalloff;
	BaseObject*	 pLight;
	Int32				 lFalloff;

#ifdef MAXON_TARGET_WINDOWS
	#pragma warning(push)
	#pragma warning(disable: 4201)	// nonstandard extension used : nameless struct/union
#endif
	union
	{
		struct
		{
			UInt32 bUseAspectRatioShader	: 1,	// Aspect ratio has influences the shader code
						 bUseInner							: 1,
						 bSpecular							: 1,
						 bDiffuse								: 1,
						 bUseShadowColor				: 1,
						 bAmbient								: 1,	// the Ambient flag of the light source
						 bOnlyZ									: 1,	// Z-direction only
						 bShadowCaster					: 1,
						 bVSM										: 1,
						 bShowInReflection			: 1;
		};
		Int32 lFlags;
	};
#ifdef MAXON_TARGET_WINDOWS
	#pragma warning(pop)
#endif

	// state variables
	union
	{
		// alignment in these structures must match the alignment in the uniform buffer object
		// RT_LT_OMNI
		struct
		{
			C4D_ALIGN(Float32 color[4], 16);	// r, g, b, contrast
			C4D_ALIGN(Float32 position[3], 16);
			C4D_ALIGN(Float32 direction[3], 16);
			C4D_ALIGN(Float32 falloff[4], 16);
		} OmniLight;

		// RT_LT_SPOT
		struct
		{
			C4D_ALIGN(Float32 color[4], 16);	// r, g, b, contrast
			C4D_ALIGN(Float32 position[3], 16);
			C4D_ALIGN(Float32 direction[3], 16);
			C4D_ALIGN(Float32 inoutcos[2], 16);	// inner / outer cosine
			C4D_ALIGN(Float32 falloff[4], 16);
			C4D_ALIGN(Float32 aspect[12], 16);	// 3x3 matrix -> m
		} SpotLight;

		// RT_LT_SPOTRECT
		struct
		{
			C4D_ALIGN(Float32 color[4], 16);		// r, g, b, contrast
			C4D_ALIGN(Float32 position[3], 16);
			C4D_ALIGN(Float32 inoutsin[2], 16);	// inner / outer sine
			C4D_ALIGN(Float32 falloff[4], 16);
			C4D_ALIGN(Float32 m[12], 16);				// 3x3 matrix
		} SpotRectLight;

		// RT_LT_DISTANT
		// RT_LT_DEFAULT
		struct
		{
			C4D_ALIGN(Float32 color[4], 16);	// r, g, b, contrast
			C4D_ALIGN(Float32 direction[3], 16);
			C4D_ALIGN(Float32 falloff[4], 16);
		} DistantLight;

		// RT_LT_PARALLEL
		struct
		{
			C4D_ALIGN(Float32 color[4], 16);	// r, g, b, contrast
			C4D_ALIGN(Float32 position[3], 16);
			C4D_ALIGN(Float32 direction[3], 16);
			C4D_ALIGN(Float32 falloff[4], 16);
		} ParallelLight;

		// RT_LT_PARSPOT
		// RT_LT_PARSPOTRECT
		struct
		{
			C4D_ALIGN(Float32 color[4], 16);	// r, g, b, contrast
			C4D_ALIGN(Float32 position[3], 16);
			C4D_ALIGN(Float32 direction[3], 16);
			C4D_ALIGN(Float32 inoutsize[2], 16);	// inner / outer size
			C4D_ALIGN(Float32 falloff[4], 16);
			C4D_ALIGN(Float32 m[12], 16);					// 3x4 matrix
		} ParallelSpotLight;

		// RT_LT_AMBIENT
		struct
		{
			C4D_ALIGN(Float32 color[4], 16);	// r, g, b, contrast
		} AmbientLight;

		// RT_LT_AREA
		struct
		{
			C4D_ALIGN(Float32 color[4], 16);	// r, g, b, contrast
			C4D_ALIGN(Float32 position[4], 16);
			C4D_ALIGN(Float32 falloff[4], 16);
			C4D_ALIGN(Float32 size[2], 16);
			C4D_ALIGN(Float32 m[12], 16);					// 3x3 matrix
			C4D_ALIGN(Float32 doublesided, 16);
			C4D_ALIGN(Float32 color2[4], 16);	// r, g, b, contrast (for the back side of the area light)
			C4D_ALIGN(Float32 invm[12], 16);					// 3x3 matrix
		} AreaLight;
	};
	Matrix32	 m, img;
	Matrix		 mg;
	Float32		 rContrast, rAspect;

	Vector		 vShadowColor;
	Float32		 rShadowIntensity;
	UINT			 nShadowTexture;
	Matrix4d32 mLightProjections[6];
	Vector4d32 vInvCoeffs[6];
	Float32		 rNear[6], rFar[6];
	Float32		 rGradientMultiplier;
	Float32		 rVSMAttenuation;

	UInt32		 ulIESChecksum;

	Vector	_arearadius;
	Int32		_areashape = 0;
	Bool		_areadoublesided = false;
	Float32	_areavisibility = 1;
	Bool		bUseAspectRatioData;
};

#ifndef GLPROGRAMTYPE_DEFINED
#define GLPROGRAMTYPE_DEFINED

enum GlProgramType : int { VertexProgram = 1, FragmentProgram = 2, CompiledProgram = 3, GeometryProgram = 4, TessControlProgram = 5, TessEvalProgram = 6 };
enum GlUniformParamType { UniformFloat1					 = 0, UniformFloat2 = 1, UniformFloat3 = 2, UniformFloat4 = 3,
													UniformInt1						 = 4, UniformInt2 = 5, UniformInt3 = 6, UniformInt4 = 7,
													UniformUint1					 = 8, UniformUint2 = 9, UniforUint3 = 10, UniformUint4 = 11,
													UniformFloatMatrix2		 = 12, UniformFloatMatrix3 = 13, UniformFloatMatrix4 = 14,
													UniformTexture1D			 = 15, UniformTexture2D = 16, UniformTexture3D = 17, UniformTextureCube = 18,
													UniformTexture1Di			 = 19, UniformTexture2Di = 20, UniformTexture3Di = 21, UniformTextureCubei = 22,
													UniformTexture1Du			 = 23, UniformTexture2Du = 24, UniformTexture3Du = 25, UniformTextureCubeu = 26,
													UniformTexture1DArray	 = 27, UniformTexture2DArray = 28,
													UniformTexture1DArrayi = 29, UniformTexture2DArrayi = 30,
													UniformTexture1DArrayu = 31, UniformTexture2DArrayu = 32 };

typedef void* (*GlProgramFactoryAllocPrivate)();
typedef void (*GlProgramFactoryFreePrivate)(void* pData);
typedef void* (*GlProgramFactoryAllocDescription)();
typedef void (*GlProgramFactoryFreeDescription)(void* pData);
typedef void (*GlProgramFactoryCreateTextureFunctionCallback)(const Float* prIn, Float* prOut, void* pData);
typedef void (*GlProgramFactoryMessageCallback)(Int32 lMessage, const void* pObj, UInt64 ulIndex, GlProgramFactory* pFactory);
typedef Int32 (*GlProgramFactoryErrorHandler)(GlProgramType type, const char* pszError);
typedef void (*GlVertexBufferDrawElementCallback)(Int32 lElement, void* pData);

#endif

#define FACTORY_CACHE_ITEM_CALLBACK_DELETE				1

struct GlGetIdentity
{
	GlGetIdentity()
	{
		pData = nullptr;
		lDataSize = 0;
		lMaxDataSize = 0;
		ulParameters = 0;
		bSetTransparency = false;
		lSubdivisionCount = 0;
		needsCorrectedUVs = false;
		bUseTessellation = false;
		bOpenSubdivAdaptivePatches = false;
		ulOpenSubdivPatchHashCode = 0;
		bUseMatCapReflections = false;
		_needsSelectionTexture = false;
		_applyScreenSpaceReflections = false;
		_flatShading = false;
	}

	~GlGetIdentity()
	{
		DeleteMem(pData);
	}

	// read-only information
	GlProgramType type;
	BaseDraw*			pBaseDraw;
	BaseDocument* pDoc;
	BaseMaterial* pMaterial;
	BaseObject*		pObj;
	TextureTag*		pTextureTag;
	UVWTag*				pUVWTag;
	Int32					lChannel;
	Bool					bDontShade;
	Bool					bXRay;
	Bool					bTintedSelection;
	Bool					bImageAlpha;	// only valid if the shader is in the alpha channel
	Bool					bIsShadowPass;
	Bool					bAccurate;
	Bool					bTile, bSeamless, bRepeat;
	Bool					bObjHandle;
	Bool					bAnimatePreview;	// filled by the material
	Bool					bDontScale;
	Bool					bUseTextures;
	Bool					bHasStickTexture;
	Bool					bOnlyGeometry;	// used during PickObject, only pass geometry, no shading and lighting
	Int32					lPreviewSize;		// filled by the material
	Int32					lCompiler;
	Int32					lDocumentColorProfile;
	Bool					bLinearWorkflow;

	// may be written to
	void*	 pData;
	Int		 lDataSize, lMaxDataSize;
	UInt64 ulParameters;
	Bool bSetTransparency;
	Int32 lSubdivisionCount;
	Bool needsCorrectedUVs;

	Bool		bUseTessellation;							// read only
	Bool		bOpenSubdivAdaptivePatches;		// read only
	UInt32	ulOpenSubdivPatchHashCode;		// read only
	Bool		bUseMatCapReflections;				// read only
	Bool 		_needsSelectionTexture; 			// read-only
	Bool		_applyScreenSpaceReflections;	// read-only
	Bool		_flatShading;									// read-only
};

struct GlTextureInfo
{
	Int32 lWidth, lHeight;
	Int32 lDepth;
	Int32 lTilesX, lTilesY;
	Float rScaleLastU, rScaleLastV;
};
Bool operator == (const GlTextureInfo& a, const GlTextureInfo& b);

inline void SetUnalignedLong(UChar* pDest, Int32 l) { pDest[0] = (UChar)((l >> 24) & 0xff); pDest[1] = (UChar)((l >> 16) & 0xff); pDest[2] = (UChar)((l >> 8) & 0xff); pDest[3] = (UChar)(l & 0xff); }
inline Int32 GetUnalignedLong(const UChar* pSrc) { return Int32((((UInt32)pSrc[0]) << 24) | (((UInt32)pSrc[1]) << 16) | (((UInt32)pSrc[2]) << 8) | (((UInt32)pSrc[3]))); }

#ifndef __API_INTERN__
	#define IncreaseBufferSize(_ident_, _size_) _IncreaseBufferSize(_ident_, _size_, __LINE__, __FILE__)
	#define AlignedBufferSize(_size_)						((_size_ + 3) & ~3)

class GlProgramFactory
{
private:
	GlProgramFactory();
	~GlProgramFactory();

public:
	static GlProgramFactory* GetFactory(const BaseDraw* pBaseDraw, C4DAtom* pObj, Int32 lIndex, GlProgramFactoryMessageCallback fnCallback, void* pIdentity, Int lIdentityLength,
																			const GlLight* const* pLights, Int32 lLightCount, UInt64 ulFlags,
																			const GlVertexBufferAttributeInfo* const* ppBufferAttributeInfo, Int32 lBufferAttributeInfoCount,
																			const GlVertexBufferVectorInfo* const* ppBufferVectorInfo, Int32 lBufferVectorInfoCount,
																			GlFBAdditionalTextureInfo* pAdditionalTextures);	// lIndex must be positive
	static void RemoveReference(C4DAtom* pObj, UInt64 ulIndex = (UInt64)NOTOK);
	static void RemoveTextureReference(C4DAtom* pObj, Int32 lIndex);											// this may not be called in a ::Draw function
	static void RemoveTextureReference(const Filename& fn);
	static void* _IncreaseBufferSize(GlGetIdentity* pIdentity, Int lNeededSize, Int32 lLine, const char* pszFile);

	Bool BindToView(const BaseDraw* pDraw);
	Bool CompilePrograms();
	Bool CompileCgFX(const Filename& fn, UInt32 ulFlags);
	Bool IsPrecompiled() const;
	Bool BindPrograms();
	Bool BindCgFXPrograms(Int32 lTechnique, Int32 lPass);
	Bool UnbindPrograms();
	Bool DestroyPrograms();
	void LockFactory();
	void UnlockFactory();
	void* GetPrivateData(const void* pObj, Int32 lDataIndex, GlProgramFactoryAllocPrivate fnAlloc = nullptr, GlProgramFactoryFreePrivate fnFree = nullptr);
	void* GetDescriptionData(Int32 lObjIndex, Int32 lDataIndex, GlProgramFactoryAllocDescription fnAlloc = nullptr, GlProgramFactoryFreeDescription fnFree = nullptr, GlProgramFactoryReadDescription fnRead = nullptr, GlProgramFactoryWriteDescription fnWrite = nullptr);
	Bool IsProgram(GlProgramType t);
	Bool InitLightParameters();
	Int32 GetMaxLights();
	Bool AddLightProjection();
	const UChar* GetIdentity() const;
	GlProgramParameter GetParameterHandle(GlProgramType t, const char* pszName) const;
	Bool GetCgFXDescription(BaseContainer* pbcDescription);

	void InitSetParameters();
	void SetScreenCoordinates(BaseDraw* pBaseDraw);
	void AddErrorHandler(GlProgramFactoryErrorHandler fn);

	// set functions
	Bool SetParameterMatrixTransform(GlProgramParameter param); // sets the modelview-projection matrix of the current view
	Bool SetParameterMatrix(GlProgramParameter param, const Matrix4d32 &m);
	Bool SetParameterMatrix(GlProgramParameter paramOffset, GlProgramParameter paramAxes, GlProgramParameter paramNormalTrans, const Matrix32 &m);
	Bool SetParameterMatrix3x3(GlProgramParameter param, const Float32* r);
	Bool SetParameterMatrix4x4(GlProgramParameter param, const Float32* r);
	Bool SetParameterVector(GlProgramParameter param, const Vector32& v);
	Bool SetParameterVector(GlProgramParameter param, const Vector4d32& v);
	Bool SetParameterVector(GlProgramParameter param, const Vector32& v, Float32 w);
	Bool SetParameterColor(GlProgramParameter param, const Vector& v, Float rBrightness = 1.0f);
	Bool SetParameterColor(GlProgramParameter param, const Vector& v, Float rBrightness, Float32 rAlpha);
	Bool SetParameterColorReverse(GlProgramParameter param, const Vector& v, Float rBrightness = 1.0f);
	Bool SetParameterColorReverse(GlProgramParameter param, const Vector& v, Float rBrightness, Float32 rAlpha);
	Bool SetParameterReal(GlProgramParameter param, Float32 a);
	Bool SetParameterReal2(GlProgramParameter param, Float32 a, Float32 b);
	Bool SetParameterReal2(GlProgramParameter param, const Float32* v);
	Bool SetParameterReal3(GlProgramParameter param, Float32 a, Float32 b, Float32 c);
	Bool SetParameterReal3(GlProgramParameter param, const Float32* v);
	Bool SetParameterReal4(GlProgramParameter param, Float32 a, Float32 b, Float32 c, Float32 d);
	Bool SetParameterReal4(GlProgramParameter param, const Float32* v);
	Bool SetParameterInt(GlProgramParameter param, int a);
	Bool SetParameterInt2(GlProgramParameter param, int a, int b);
	Bool SetParameterInt2(GlProgramParameter param, const int* v);
	Bool SetParameterInt3(GlProgramParameter param, int a, int b, int c);
	Bool SetParameterInt3(GlProgramParameter param, const int* v);
	Bool SetParameterInt4(GlProgramParameter param, int a, int b, int c, int d);
	Bool SetParameterInt4(GlProgramParameter param, const int* v);
	Bool SetParameterUint(GlProgramParameter param, unsigned int l);
	Bool SetParameterUint2(GlProgramParameter param, unsigned int a, unsigned int b);
	Bool SetParameterUint2(GlProgramParameter param, const unsigned int* v);
	Bool SetParameterUint3(GlProgramParameter param, unsigned int a, unsigned int b, unsigned int c);
	Bool SetParameterUint3(GlProgramParameter param, const unsigned int* v);
	Bool SetParameterUint4(GlProgramParameter param, unsigned int a, unsigned int b, unsigned int c, unsigned int d);
	Bool SetParameterUint4(GlProgramParameter param, const unsigned int* v);
	Bool SetParameterRealArray(GlProgramParameter param, Int32 lElements, const Float32* r);
	Bool SetParameterTexture2D(GlProgramParameter param, const BaseBitmap* pBmp, Int32 lFlags, DRAW_ALPHA alphamode, C4DGLuint* pnHandle = nullptr);
	Bool SetParameterTexture2D(GlProgramParameter param, const Filename& fn, Int32 lFrame, C4DAtom* pObj, Int32 lIndex, Int32 lFlags, DRAW_ALPHA alphamode, Int32 lMaxSize, const LayerSet* pLayerSet = nullptr, GlTextureInfo* pInfo = nullptr, C4DGLuint* pnHandle = nullptr);
	Bool SetParameterTexture2D(GlProgramParameter param, const BaseBitmap* pBmp, UInt32 ulDirty, C4DAtom* pObj, Int32 lIndex, Int32 lFlags, DRAW_ALPHA alphamode, Int32 lMaxSize, GlTextureInfo* pInfo = nullptr, C4DGLuint* pnHandle = nullptr);
	Bool SetParameterTexture(GlProgramParameter param, Int32 lDimension, C4DGLuint nTexture);
	Bool SetParameterTextureCube(GlProgramParameter param, C4DGLuint nTexture);
	Bool SetParameterTexture2DDepth(GlProgramParameter param, C4DGLuint nTexture);
	Bool SetParameterTextureCubeDepth(GlProgramParameter param, C4DGLuint nTexture);
	Bool SetParameterTextureGradient(GlProgramParameter param, const Gradient* pGradient, C4DAtom* pObj, Int32 lIndex, Int32 lFlags, C4DGLuint* pnHandle = nullptr);
	Bool SetParameterTextureFunction(GlProgramParameter param, C4DAtom* pObj, Int32 lIndex, Int32 lFlags, Int32 lDataType, GlProgramFactoryCreateTextureFunctionCallback fn, void* pData, Int lDataLen,
																	 Int32 lInParams, Int32 lOutParams, Int32 lCycle, Bool bInterpolate, Int32 lSizeX, Int32 lSizeY, Int32 lSizeZ, Bool bParallel, C4DGLuint* pnHandle = nullptr);
	Bool SetParameterTextureRaw(GlProgramParameter param, C4DAtom* pObj, Int32 lIndex, Int32 lFlags, Int32 lDataType, const void* pData, Int lDataLen, UInt32 ulDirty,
															Int32 lDimension, Int32 lComponents, Int32 lCycle, Bool bInterpolate, Int32 lSizeX, Int32 lSizeY, Int32 lSizeZ, C4DGLuint* pnHandle = nullptr);
	Bool SetParameterTextureCubeMap(GlProgramParameter param, C4DAtom* pObj, Int32 lIndex, Int32 lFlags, Int32 lDataType, GlProgramFactoryCreateTextureFunctionCallback fn, void* pData, Int lDataLen,
																	Int32 lOutParams, Int32 lCycle, Bool bInterpolate, Int32 lSize, Bool bParallel, C4DGLuint* pnHandle = nullptr);
	Bool SetParameterTextureNormalizeCube(GlProgramParameter param);

	static Bool CacheTextureFn(BaseDraw* pBaseDraw, const Filename& fn, Int32 lFrame, C4DAtom* pObj, Int32 lIndex, Int32 lFlags, DRAW_ALPHA alphamode, Int32 lMaxSize, GlProgramType progType, const LayerSet* pLayerSet = nullptr, GlTextureInfo* pInfo = nullptr, C4DGLuint* pnHandle = nullptr);
	static Bool CacheTextureBmp(BaseDraw* pBaseDraw, const BaseBitmap* pBmp, UInt32 ulDirty, C4DAtom* pObj, Int32 lIndex, Int32 lFlags, DRAW_ALPHA alphamode, Int32 lMaxSize, GlProgramType progType, GlTextureInfo* pInfo = nullptr, C4DGLuint* pnHandle = nullptr);

	Bool SetLightParameters(const GlLight* const* ppLights, Int32 lLightCount, const Matrix4d32& mObject);

	UInt64 Init(Int32 lSubdivisionCount, Int32 lGeometryTypeIn = 0, Int32 lGeometryTypeOut = 0, Int32 lMaxOutVertices = -1);
	void AddParameters(UInt64 ulParameters, UInt64 ulFormat = 0);
	UInt64 GetParameters() const;
	UInt64 GetParameterFormats() const;
	GlString AddUniformParameter(GlProgramType t, GlUniformParamType p, const char* pszName);
	GlString AddUniformParameter(GlProgramType t, GlUniformParamType p, Int32 lCount, const char* pszName);
	Bool HeaderFinished();
	void AddLine(GlProgramType t, const GlString& strLine);
	void AddDepthCompareCondition(GlProgramType t, const GlString& strPeelTexture);
	Bool AddEncryptedBlock(GlProgramType t, const char* pchData, Int lDataLength, const UChar* pchKey, Int32 lKeyLength);
	GlString AddColorBlendFunction(GlProgramType t, Int32 lBlendMode);
	GlString AddRGBToHSVFunction(GlProgramType t);	// vec3 hsv = RGBtoHLS(vec3 rgb) h is 0 to 360 degreee
	GlString AddHSVToRGBFunction(GlProgramType t);	// vec3 rgb = HSVtoRGB(vec3 hsv) h is 0 to 360 degreee
	GlString AddRGBToHSLFunction(GlProgramType t);	// vec3 hsl = RGBtoHLS(vec3 rgb)
	GlString AddHSLToRGBFunction(GlProgramType t);	// vec3 rgb = HLStoRGB(vec3 hsl)
	Bool AddFunction(GlProgramType t, const GlString& strFunction);
	Bool AddEmitVertex();
	void StartLightLoop();
	Bool EndLightLoop();
	GlString GetUniqueID();
	static Bool HasNoiseSupport(GlProgramType t, Int32 lNoise, BaseDraw* pBaseDraw, Int32 lCompiler);
	const GlString& AddNoiseFunction(GlProgramType t, Int32 lNoise, Int32 lFlags);
	void GetVectorInfo(Int32& lVectorCount, const GlVertexBufferVectorInfo* const*& ppVectorInfo) const;

	static UInt32 GetLanguageFeatures(BaseDraw* bd, Int32 lCompiler, Int32 lFlags);
	static Bool WriteParameter(GlWriteDescriptionData* pFile, GlProgramParameter param);
	static Bool ReadParameter(GlReadDescriptionData* pFile, GlProgramParameter& param);
	Int32 GetCompiler();
	Int32 GetUniqueIDCount();
};

class GlFrameBuffer
{
private:
	GlFrameBuffer();
	~GlFrameBuffer();

public:
	static GlFrameBuffer* GetFrameBuffer(BaseDraw* pBaseDraw, UInt lID1, Int32 lID2, UINT nWidth, UINT nHeight, Int32 lColorTextureCount,
																			 Int32 lDepthTextureCount, Int32 lColorCubeCount, Int32 lDepthCubeCount, UInt32 ulFlags, Int32 lAAMode, GlFBAdditionalTextureInfo* pAdditionalTextures);
	static GlFrameBuffer* FindFrameBuffer(BaseDraw* pBaseDraw, UInt lID1, Int32 lID2);

	static void RemoveObject(BaseDraw* pBaseDraw, UInt lID1, Int32 lID2);

	void PrepareForRendering(BaseDraw* pBaseDraw, Int32 lTexture = NOTOK);
	void SetInterpolation(BaseDraw* pBaseDraw, Int32 lInterpolate, Int32 lTexture, Int32 lFlags);	// use GL_FRAMEBUFFER_INTERPOLATE_* for interpolation
	Bool Activate(BaseDraw* pBaseDraw);
	void Deactivate(BaseDraw* pBaseDraw);
	Bool SetRenderTarget(Int32 lTexture, Int32 lFlags);												// lFlags may be C4D_FRAMEBUFFER_COLOR or C4D_FRAMEBUFFER_DEPTH
	void GetRatios(Int32 lType, Float& rWidth, Float& rHeight);								// C4D_FRAMEBUFFER_COLOR and C4D_FRAMEBUFFER_CUBE_MASK are allowed for lType
	void GetSize(Int32 lType, UINT& nWidth, UINT& nHeight, Bool bFramesize);	// C4D_FRAMEBUFFER_COLOR and C4D_FRAMEBUFFER_CUBE_MASK are allowed for lType

	C4DGLuint GetTexture(Int32 lTexture, Int32 lFlags) const;
	GlFBAdditionalTextureInfo* GetAdditionalTexture(Int32 lType, void* pBuffer = nullptr) const;
	IMAGERESULT SaveTextureToDisk(BaseDraw* pBaseDraw, const Filename& fn, Int32 lTexture, Int32 lFlags);	// mainly for debugging purposes, the texture is saved as a .tif image
	Bool CopyToBitmap(BaseDraw* pBaseDraw, BaseBitmap* pBmp, Int32 lTexture, Int32 lFlags);
	Bool GetTextureData(BaseDraw* pBaseDraw, Int32 x1, Int32 y1, Int32 x2, Int32 y2, void* pData, Int32 lTexture, Int32 lFlags) const;
	Bool CopyToBuffer(void* pBuffer, Int lBufferSize, Int32 lTexture, Int32 lFlags) const;
	void Clear();
	void Clear(const Vector32& vColor, Float32 rAlpha);
	Bool IsNPOTBuffer();
	Bool DrawBuffer(Int32 lTexture, Int32 lFlags, Bool bCopyAlpha = false, Int32 lColorConversion = DRAW_BUFFER_COLOR_NO_CHANGE, C4DGLint nConversionTexture = 0, Float32 rAlpha = 1.0f, const Vector32& vColor = Vector32(1.0f),
									Float32 xs1 = 0.0f, Float32 ys1 = 0.0f, Float32 xs2 = 1.0f, Float32 ys2 = 1.0f,
									Float32 xd1 = 0.0f, Float32 yd1 = 0.0f, Float32 xd2 = 1.0f, Float32 yd2 = 1.0f);
};

class GlVertexBuffer
{
private:
	GlVertexBuffer();
	~GlVertexBuffer();

public:
	static GlVertexBuffer* GetVertexBuffer(const BaseDraw* pBaseDraw, C4DAtom* pObj, Int32 lIndex, void* pIdentity, Int lIdentityLen, UInt32 ulFlags = 0);
	static void RemoveObject(C4DAtom* pObj, Int32 lIndex);

	Bool IsDirty();
	void SetDirty(Bool bDirty = true);

	// it is not allowed to draw anything in the callback function since this might destroy the OpenGL state
	static Bool DrawSubBuffer(const BaseDraw* pBaseDraw, const GlVertexSubBufferData* pVertexSubBuffer, const GlVertexSubBufferData* pElementSubBuffer,
														Int32 lDrawinfoCount, const GlVertexBufferDrawSubbuffer* pDrawInfo,
														Int32 lVectorCount, const GlVertexBufferVectorInfo* const* ppVectorInfo, UInt32 flags = 0,
														GlVertexBufferDrawElementCallback fnCallback = nullptr, void* pCallbackData = nullptr);

	GlVertexSubBufferData* AllocSubBuffer(const BaseDraw* pBaseDraw, GlVertexBufferSubBufferType type, Int lSize, const void* pData);
	GlVertexSubBufferData* AllocIndexSubBuffer(const BaseDraw* pBaseDraw, Int32 lCount, UInt32* pulIndex, Int32 lMaxIndex = -1);	// pulIndex will be modified
	GlVertexSubBufferData* AllocIndexSubBuffer(const BaseDraw* pBaseDraw, Int32 lCount, const UInt16* puwIndex);									// creates an unsigned short index buffer
	Bool FlushAllSubBuffers(const BaseDraw* pBaseDraw);
	Bool FreeBuffers(const BaseDraw* pBaseDraw, GlVertexBufferSubBufferType type);
	Bool FreeBuffer(const BaseDraw* pBaseDraw, GlVertexSubBufferData* pBuffer);
	Bool MarkAllForDelete();
	Bool MarkBuffersForDelete(GlVertexBufferSubBufferType type);
	Bool MarkBufferForDelete(GlVertexSubBufferData* pBuffer);
	Bool DeleteMarkedBuffers(const BaseDraw* pBaseDraw);
	Bool SetSubBufferData(const BaseDraw* pBaseDraw, GlVertexSubBufferData* pSubBuffer, Int lSize, const void* pData);
	Int32 GetSubBufferCount() const;
	GlVertexSubBufferData* GetSubBuffer(Int32 n);

	void* MapBuffer(const BaseDraw* pBaseDraw, GlVertexSubBufferData* pSubBuffer, GlVertexBufferAccessFlags flags);
	Bool UnmapBuffer(const BaseDraw* pBaseDraw, GlVertexSubBufferData* pSubBuffer);
};

#endif	// __API_INTERN__

struct GlAddUniformParametersMsg
{
	// read-only values
	BaseDraw*					pBaseDraw;
	BaseDocument*			pDoc;
	BaseObject*				pObj;
	TextureTag*				pTextureTag;
	GlProgramFactory* pFactory;
	Int32							lChannel;
	Bool							bDontShade;
	GlProgramType			type;

	// must be modified by the shader
	Int32				 lObjIndex;
	const UChar* pchIdentity;

	Bool		bUseTessellation = false;			// read only
};

struct GlInitDescriptionMsg
{
	// read-only values
	BaseDraw*					pBaseDraw;
	BaseDocument*			pDoc;
	BaseObject*				pObj;
	TextureTag*				pTextureTag;
	GlProgramFactory* pFactory;
	GlProgramType			type;
	Int32							lChannel;
	Bool							bDontShade;

	// must be modified by the shader
	Int32				 lObjIndex;
	const UChar* pchIdentity;

	Bool		bUseTessellation = false;			// read only
};

struct GlCompileCgFXMsg
{
	// read-only values
	BaseDraw*					pBaseDraw;
	BaseDocument*			pDoc;
	GlProgramFactory* pFactory;
};

struct GlBindCgFXMsg
{
	// read-only values
	BaseDraw*					pBaseDraw;
	BaseDocument*			pDoc;
	GlProgramFactory* pFactory;
};

#define GL_PASS_DISPLACE					 1
#define GL_PASS_BEFORE_LIGHT			 2
#define GL_PASS_LIGHT							 3
#define GL_PASS_AFTER_LIGHT				 4
#define GL_PASS_SUBDIVIDE_SAMPLE	 5
#define GL_PASS_SUBDIVIDE_DISPLACE 6
#define GL_PASS_DISPLACE_BUMP			 7

struct PassthroughTagVariableRetriever
{
	virtual const GlString* GetVariable(const BaseTag*) const = 0;
};

struct GlAddProgramCodeMsg
{
	// read-only values
	BaseDraw*					pBaseDraw;
	BaseDocument*			pDoc;
	BaseObject*				pObj;
	TextureTag*				pTextureTag;
	GlProgramFactory* pFactory;
	GlProgramType			type;
	Int32							lChannel;
	Int32							lPass;					// one of GL_PASS_*
	GlString					strColorVar;		// shaders must create a new variable (e.g. "color"+GetUniqueID()) and return it here
	Bool							bReturnAlpha;		// set this if you only return a value in the alpha channel
	GlString					strDisplaceVar;	// shaders must create a new variable (e.g. "displace"+GetUniqueID()) and return it here
	UInt64						ulParameters;		// factory parameters (it's the same like pFactory->GetParameters)
	Bool							bDontShade, bTile, bSeamless, bRepeat, bImageAlpha;

	// must be modified by the shader
	Int32				 lObjIndex;
	const UChar* pchIdentity;

	// Read-only.
	const PassthroughTagVariableRetriever* passthroughTagVariableRetriever;

	Bool		bUseTessellation = false;			// read only
};

struct GlSetUniformParametersMsg
{
	// read-only values
	BaseDraw*							pBaseDraw;
	BaseDocument*					pDoc;
	BaseObject*						pObj;
	BaseMaterial*					pMaterial;
	TextureTag*						pTextureTag;
	GlProgramFactory*			pFactory;
	GlProgramType					type;
	Int32									lChannel;
	Bool									bAnimatePreview;
	Bool									bDontShade;
	Bool									bDontScale;
	Bool									bObjHandle;
	Int32									lPreviewSize;
	Vector								vObjectColor;
	Float									rObjectAlpha;
	Bool									bImageAlpha;	// only valid if the shader is in the alpha channel
	Int32									lDocumentColorProfile;
	Bool									bLinearWorkflow;
	const GlLight* const* ppLights;
	Int32									lLightCount;
	const Matrix*					mg;	// never NULL

	// must be modified by the shader
	Int32				 lObjIndex;
	const UChar* pchIdentity;

	Bool bUseTessellation = false;						// read only
	Bool _disableStipple = false;
};

// for GlFramebuffer::SetInterpolation
#define GL_FRAMEBUFFER_INTERPOLATE_MIN_LINEAR		0x00000001
#define GL_FRAMEBUFFER_INTERPOLATE_MAG_LINEAR		0x00000002
#define GL_FRAMEBUFFER_INTERPOLATE_ADD_TEXTURES	0x00000100

#ifdef __API_INTERN__
	#include "gl_string.h"
#endif

// use these formats:
// C4D_FRAMEBUFFER_UV: 32 bit, 3 components

struct GlFBAdditionalTextureInfo
{
	GlFBAdditionalTextureInfo* pNext;							// pointer to the next element of the list

	Int32											 lDataType;					// may be one of the C4D_FRAMEBUFFER_* constants
	Int32											 lComponents;				// 1, 3 or 4
	Int32											 lType;							// C4D_FRAMEBUFFER_UV
	Int32											 bIsIntegerTexture;	// 1: integer, 2: unsigned integer - GL_EXT_texture_integer is required

	// will be filled out by GlFrameBuffer::GetFrameBuffer - leave empty
	Int				lLineSize, lBufferSize, lElementSize;
	GlString	strName;
	C4DGLuint nTexture;
};

#endif // C4D_GL_H__
