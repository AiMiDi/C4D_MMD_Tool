/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef C4D_BASECHANNEL_H__
#define C4D_BASECHANNEL_H__

#ifdef __API_INTERN__
	#error "not in the kernel"
#endif

#include "ge_math.h"
#include "c4d_basebitmap.h"
#include "c4d_gui.h"
#include "c4d_baselist.h"

class Filename;
class BaseBitmap;
class BaseContainer;
class GeDialog;
struct VolumeData;

#define PsBaCall(fnc) (this->*C4DOS.Ba->fnc)

//-------------------------------------------------------------------------------------------------
/// Represents a shader in the shader tree of a channel. Call BaseChannel::GetShader() to retrieve an instance.
/// @addAllocFreeAutoAllocNote
//-------------------------------------------------------------------------------------------------
class BaseShader : public BaseList2D
{
private:
	BaseShader();
	~BaseShader();

public:

	/// @name Alloc/Free
	/// @{

	//----------------------------------------------------------------------------------------
	/// @allocatesA{shader}
	/// @param[in] type								The shader type: @enumerateEnum{ShaderTypes}
	/// @return												@allocReturn{shader}
	//----------------------------------------------------------------------------------------
	static BaseShader* Alloc(Int32 type);

	//----------------------------------------------------------------------------------------
	/// @destructsAlloc{shaders}
	/// @param[in] ps									@theToDestruct{shader}
	//----------------------------------------------------------------------------------------
	static void Free(BaseShader*& ps);

	/// @}

	/// @name Navigation
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets the next shader in the list. Convenience version of GeListNode::GetNext() returning a @ref BaseShader*.
	/// @return												The next shader, or @formatConstant{nullptr} if there is none. @cinemaOwnsPointed{shader}
	//----------------------------------------------------------------------------------------
	BaseShader* GetNext(void) { return (BaseShader*)AtCall(GetNext) (); }

	//----------------------------------------------------------------------------------------
	/// Gets the previous shader in the list. Convenience version of GeListNode::GetPred() returning a @ref BaseShader*.
	/// @return												The previous shader, or @formatConstant{nullptr} if there is none. @cinemaOwnsPointed{shader}
	//----------------------------------------------------------------------------------------
	BaseShader* GetPred(void) { return (BaseShader*)AtCall(GetPred) (); }

	//----------------------------------------------------------------------------------------
	/// Gets the parent shader of the list node. Convenience version of GeListNode::GetUp() returning a @ref BaseShader*.
	/// @return												The parent shader, or @formatConstant{nullptr} if there is none. @cinemaOwnsPointed{shader}
	//----------------------------------------------------------------------------------------
	BaseShader* GetUp(void) { return (BaseShader*)AtCall(GetUp) (); }

	//----------------------------------------------------------------------------------------
	/// Gets the first child shader of the list node. Convenience version of GeListNode::GetDown() returning a @ref BaseShader*.
	/// @return												The first child shader, or @formatConstant{nullptr} if there is none. @cinemaOwnsPointed{shader}
	//----------------------------------------------------------------------------------------
	BaseShader* GetDown(void) { return (BaseShader*)AtCall(GetDown) (); }

	//----------------------------------------------------------------------------------------
	/// Gets the last child shader of the list node. Convenience version of GeListNode::GetDownLast() returning a @ref BaseShader*.
	/// @return												The last child shader, or @formatConstant{nullptr} if there is none. @cinemaOwnsPointed{shader}
	//----------------------------------------------------------------------------------------
	BaseShader* GetDownLast(void) { return (BaseShader*)AtCall(GetDownLast) (); }

	/// @}

	/// @name Init/Free Render
	/// @{

	//----------------------------------------------------------------------------------------
	/// Calls ShaderData::InitRender() for the corresponding shader plugin.
	/// @warning It is mandatory to call this method before any Sample(), SampleBump() or GetBitmap() functions.
	/// @param[in] is									A struct with information about the upcoming render. @callerOwnsPointed{struct}
	/// @return												The result of the initialization: @enumerateEnum{INITRENDERRESULT}
	//----------------------------------------------------------------------------------------
	INITRENDERRESULT InitRender(const InitRenderStruct& is) { return PsBaCall(InitRender) (is); }

	//-------------------------------------------------------------------------------------------------
	/// Frees all resources used by this shader that were allocated by calling InitRender().
	//-------------------------------------------------------------------------------------------------
	void FreeRender(void) { PsBaCall(FreeRender) (); }

	/// @}

	/// @name Sample
	/// @{

	//----------------------------------------------------------------------------------------
	/// Calls ShaderData::Output() for the corresponding shader plugin. The channel color for the point @formatParam{cd}->@link ChannelData::p p@endlink is calculated.
	/// @addCallWithinPairOfNote{InitRender(),FreeRender()}
	/// @param[in] cd									A pointer to a channel data struct to use for the sampling. @callerOwnsPointed{ChannelData}
	/// @return												The calculated color.
	//----------------------------------------------------------------------------------------
	Vector Sample(ChannelData* cd) { return PsBaCall(Sample) (cd); }

	//----------------------------------------------------------------------------------------
	/// This function allows you to calculate bump mapping for a shader (and its children) with the same algorithm as @C4D does.\n
	/// The method returns the delta vector that is added to the normal. The resulting normal is calculated by
	/// @code
	/// n_dst = !(n_src + SampleBump(SAMPLEBUMP _0));			// Normalize result
	/// @endcode
	/// where @c n_src is the original normal and @c n_dst is the bumped normal.
	/// @addCallWithinPairOfNote{InitRender(),FreeRender()}\n
	/// Also, the BaseVolumeData::ddu and BaseVolumeData::ddv vectors have to be initialized. Use VolumeData::GetDUDV() or set them manually.
	/// @param[in] cd									A pointer to a channel data struct to use for the sampling the bump. @callerOwnsPointed{ChannelData}
	/// @param[in] bumpflags					The flags: @enumerateEnum{SAMPLEBUMP}
	/// @return												The delta normal.
	//----------------------------------------------------------------------------------------
	Vector SampleBump(ChannelData* cd, SAMPLEBUMP bumpflags) { return PsBaCall(SampleBump) (cd, bumpflags); }

	/// @}

	/// @name Miscellaneous
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets the bitmap for shaders of type ::Xbitmap.
	/// @addCallWithinPairOfNote{InitRender(),FreeRender()}
	/// @return												The bitmap of shaders of type ::Xbitmap, otherwise @formatConstant{nullptr}.
	/// @warning The return bitmap must be accessed as read-only.
	//----------------------------------------------------------------------------------------
	BaseBitmap* GetBitmap(void) { return PsBaCall(GetBitmap) (); }

	//----------------------------------------------------------------------------------------
	/// Calls ShaderData::GetRenderInfo() for the corresponding shader plugin. This retrieves information about what the plugin requires from the raytracer and what it will return.
	/// @return												The return values are: @enumerateEnum{SHADERINFO}
	//----------------------------------------------------------------------------------------
	SHADERINFO GetRenderInfo(void) { return PsBaCall(GetRenderInfo) (); }

	//----------------------------------------------------------------------------------------
	/// Checks if @c *this is similar to @formatParam{*dst}.
	/// @param[in] dst								The shader to compare with. @callerOwnsPointed{shader}
	/// @return												@trueIfOtherwiseFalse{the shaders are the same}
	//----------------------------------------------------------------------------------------
	Bool Compare(BaseShader* dst) { return PsBaCall(PsCompare) (dst); }

	//----------------------------------------------------------------------------------------
	/// Checks if color management is disabled for shaders within reflectance, bump, alpha, displacement or normal channels when linear workflow is enabled.
	/// @param[in] doc								The document to check color management. @callerOwnsPointed{document}
	/// @return												@trueIfOtherwiseFalse{color management is disabled}
	//----------------------------------------------------------------------------------------
	Bool IsColorManagementOff(BaseDocument* doc) { return PsBaCall(IsColorManagementOff) (doc); }

	//----------------------------------------------------------------------------------------
	/// Gets the best SSS shader.
	/// @note If the shader uses subshaders it is crucial to call their GetSubsurfaceShader() method override so if any subshaders are in fact SSS shaders they are used and initialized properly.
	/// @see ShaderData::GetSubsurfaceShader()
	/// @param[in] bestmpl						The current best (smallest) Median Path Length.
	/// @return												The best SSS shader.
	//----------------------------------------------------------------------------------------
	BaseShader* GetSubsurfaceShader(Float& bestmpl) { return PsBaCall(GetSubsurfaceShader) (bestmpl); }

	//----------------------------------------------------------------------------------------
	/// Checks if the shader is supported by the GPU Renderer.
	/// @since R19
	/// @return												@trueIfOtherwiseFalse{the shader is natively supported by the GPU Renderer}
	//----------------------------------------------------------------------------------------
	Bool HasGPURendererSupport() const { return PsBaCall(HasGPURendererSupport) (); }

	//----------------------------------------------------------------------------------------
	/// Bakes the shader into a BaseBitmap
	/// @since R21
	/// @param[out] outBmp						The BaseBitmap that is baked into.
	/// @param[in] 	doc								The document.
	/// @param[in] 	parentThread			The parent thread used to check for interruption @callerOwnsPointed{BaseThread}
	/// @param[in] 	doAlpha						Pass true if alpha should be considered.
	/// @param[in] 	colorSpace				The documents colorspace.
	/// @param[in] 	linearworkflow		Pass true when LWF is enabled.
	/// @param[in] 	useHDR						Pass true when HDR should be considered.
	/// @param[in] 	xmin							The min in x.
	/// @param[in] 	xmax							The max in x.
	/// @param[in] 	ymin							The min in y.
	/// @param[in] 	ymax							The max in y.
	/// @return												@trueIfOtherwiseFalse{baking succeeded}
	//----------------------------------------------------------------------------------------
	Bool BakeShaderIntoBaseBitmap(BaseBitmap& outBmp, BaseDocument& doc, BaseThread* parentThread, Bool doAlpha, Int32 colorSpace, Bool linearworkflow, Bool useHDR, Int xmin, Int xmax, Int ymin, Int ymax)
	{
		return PsBaCall(BakeShaderIntoBaseBitmap) (outBmp, doc, parentThread, doAlpha, colorSpace, linearworkflow, useHDR, xmin, xmax, ymin, ymax);
	}
	
	/// @}

	/// @name Extended OpenGL mode
	/// @{

	//-------------------------------------------------------------------------------------------------
	/// @extOpenGlMode
	//-------------------------------------------------------------------------------------------------
	GL_MESSAGE GlMessage(Int32 type, void* data) { return PsBaCall(GlMessage) (type, data); }

	//-------------------------------------------------------------------------------------------------
	/// @extOpenGlMode
	//-------------------------------------------------------------------------------------------------
	void DestroyGLImage(BaseDocument* doc) { PsBaCall(DestroyGLImage) (doc); }

	//-------------------------------------------------------------------------------------------------
	/// @extOpenGlMode
	//-------------------------------------------------------------------------------------------------
	void InvalidateGLImage(BaseDocument* doc) { PsBaCall(InvalidateGLImage) (doc); }

	/// @}
};

//-------------------------------------------------------------------------------------------------
/// Represents a channel in a material. Call BaseMaterial::GetChannel() to retrieve an instance.
/// @addAllocFreeAutoAllocNote
//-------------------------------------------------------------------------------------------------
class BaseChannel : public C4DAtom
{
private:
	BaseChannel();
	~BaseChannel();

public:

	/// @name Alloc/Free
	/// @{

	//----------------------------------------------------------------------------------------
	/// @allocatesA{channel}
	/// @return												@allocReturn{channel}
	//----------------------------------------------------------------------------------------
	static BaseChannel* Alloc(void);

	//----------------------------------------------------------------------------------------
	/// @destructsAlloc{channels}
	///
	/// @param[in] bc									@theToDestruct{channel}
	//----------------------------------------------------------------------------------------
	static void Free(BaseChannel*& bc);

	/// @}

	/// @name Init/Free Texture
	/// @{

	//----------------------------------------------------------------------------------------
	/// Initializes the channel texture, loading any files required.
	/// @note InitTexture() can only be called once before releasing it with FreeTexture(), this includes using it from multiple threads.
	/// @param[in] irs								A structure with information about the upcoming rendering.
	/// @return												The result of the initialization: @enumerateEnum{INITRENDERRESULT}
	//----------------------------------------------------------------------------------------
	INITRENDERRESULT InitTexture(const InitRenderStruct& irs);

	//----------------------------------------------------------------------------------------
	/// Frees all resources used by this channel.
	/// @note	The texture itself might still be in memory, only the lock to the texture or the data required by a shader is freed. The texture will only be flushed if no other channel holds a lock.\n
	///				The texture may also be flushed at certain times such as a call to FlushUnusedTextures(), after starting the renderer, when opening a new document or during low memory conditions.
	//----------------------------------------------------------------------------------------
	void FreeTexture(void);

	/// @}

	/// @name Get/Set Data
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets the settings container for the channel with these IDs: @enumerateEnum{BASECHANNEL}
	/// @return												The container with the settings for this channel.
	//----------------------------------------------------------------------------------------
	BaseContainer GetData(void);

	//----------------------------------------------------------------------------------------
	/// Sets the settings for this channel.
	/// @note The container is always merged.
	/// @param[in] ct									The settings container for the channel with these IDs: @enumerateEnum{BASECHANNEL}
	//----------------------------------------------------------------------------------------
	void SetData(const BaseContainer& ct);

	/// @}

	/// @name Shader/Bitmap Access
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets the ID of the shader.
	/// @return												The shader ID, or @formatConstant{nullptr} if it is a texture.
	//----------------------------------------------------------------------------------------
	Int32 GetShaderID(void);

	//----------------------------------------------------------------------------------------
	/// Retrieves the shader of a channel.
	/// @return												The shader, or @formatConstant{nullptr} if the channel does not contain a shader. @theOwnsPointed{channel,shader}
	//----------------------------------------------------------------------------------------
	BaseShader* GetShader(void);

	//----------------------------------------------------------------------------------------
	/// Retrieves the bitmap of a texture image.
	/// @addCallWithinPairOfNote{InitTexture(),FreeTexture()}
	/// @return												The bitmap, or @formatConstant{nullptr} if no bitmap is used. @theOwnsPointed{channel,bitmap}
	//----------------------------------------------------------------------------------------
	BaseBitmap* GetBitmap(void) { return C4DOS.Ba->BCGetBitmap(this); }

	/// @}

	/// @name Sampling
	/// @{

	//----------------------------------------------------------------------------------------
	/// Retrieves the color vector for a position in the texture.
	/// @addCallWithinPairOfNote{InitTexture(),FreeTexture()}
	/// @param[in] vd									A pointer to the structure containing information for volumetric shaders. This can be @formatConstant{nullptr} for evaluation of a preview image. @callerOwnsPointed{VolumeData}
	/// @param[in] p									The UVW coordinate to sample the color value for in world coordinates. @callerOwnsPointed{Vector}
	/// @param[in] delta							The MIP sample radius in UVW coordinates. @callerOwnsPointed{Vector}
	/// @param[in] n									The surface normal at the UVW coordinate for the sample. @callerOwnsPointed{Vector}
	/// @param[in] t									The current time in seconds.
	/// @param[in] tflag							The texture flags: @enumerateEnum{TEX}
	/// @param[in] off								The MIP blur offset.
	/// @param[in] scale							The MIP blur scale.
	/// @return												The color at the given point.
	//----------------------------------------------------------------------------------------
	Vector Sample(VolumeData* vd, Vector* p, Vector* delta, Vector* n, Float t, Int32 tflag, Float off, Float scale) { return C4DOS.Ba->BcSample(this, vd, p, delta, n, t, tflag, off, scale); }

	/// @}

	/// @name Miscellaneous
	/// @{

	//----------------------------------------------------------------------------------------
	/// Checks if @c *this is similar to @formatParam{*dst}. For plugin shaders this means an automatic comparison of container values.
	/// @param[in] dst								The channel to compare with. @callerOwnsPointed{channel}
	/// @return												@trueIfOtherwiseFalse{the channels have the same settings}
	//----------------------------------------------------------------------------------------
	Bool Compare(BaseChannel* dst);

	//-------------------------------------------------------------------------------------------------
	/// @markPrivate
	//-------------------------------------------------------------------------------------------------
	Bool Attach(GeListNode* element);

	/// @}
};

//----------------------------------------------------------------------------------------
/// Simplifies the task of shader operations: undo handling, removing existing shaders, keeping track of the shader trees etc. ('I' stands for isolated.)
/// @see HandleShaderPopup()
/// @param[in] parent							Element that carries the shaders. @callerOwnsPointed{object}
/// @param[in] current						Currently set element, might be deleted, in which case the pointer is set to @formatConstant{nullptr}. @callerOwnsPointed{shader}
/// @param[in] value							The operation: @enumerateEnum{SHADERPOPUP}
/// @param[in] param							The parameter. Depends on @formatParam{value}
/// @return												@trueIfOtherwiseFalse{successful}
//----------------------------------------------------------------------------------------
inline Bool HandleShaderPopupI(BaseList2D* parent, BaseShader*& current, Int32 value, Int param) { return C4DOS.Ba->HandleShaderPopupI(parent, current, value, param); }

//-------------------------------------------------------------------------------------------------
/// @markPrivate
//-------------------------------------------------------------------------------------------------
inline Bool BuildShaderPopupMenuI(BaseContainer* menu, BaseList2D* parent, BaseShader* current, Int param) { return C4DOS.Ba->BuildShaderPopupMenuI(menu, parent, current, param); }

//----------------------------------------------------------------------------------------
/// Simplifies the task of shader operations: undo handling, removing existing shaders, keeping track of the shader trees etc.
/// @see HandleShaderPopupI().
/// @param[in] bc									A container with links to BaseList2D elements. These must be stored under increasing IDs (starting with @em 1).
/// @param[in] descid							The description ID under which the shaders are stored.
/// @param[in] value							The operation: @enumerateEnum{SHADERPOPUP}
/// @param[in] param							The parameter. Depends on @formatParam{value}
/// @return												@trueIfOtherwiseFalse{successful}
//----------------------------------------------------------------------------------------
inline Bool HandleShaderPopup(const BaseContainer& bc, const DescID& descid, Int32 value, Int param) { return C4DOS.Ba->HandleShaderPopup(bc, descid, value, param); }

//-------------------------------------------------------------------------------------------------
/// @markPrivate
//-------------------------------------------------------------------------------------------------
inline Bool BuildShaderPopupMenu(BaseContainer* menu, const BaseContainer& bc, const DescID& descid, Int param) { return C4DOS.Ba->BuildShaderPopupMenu(menu, bc, descid, param); }

//----------------------------------------------------------------------------------------
/// Retrieves the name for the given channel type ID.
/// @param[in] channelid					The channel type: @enumerateEnum{CHANNEL}
/// @return												The name for the channel type.
//----------------------------------------------------------------------------------------
inline String GetChannelName(Int32 channelid) { return C4DOS.Ba->GetChannelName(channelid); }

#endif // C4D_BASECHANNEL_H__
