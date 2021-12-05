/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef C4D_SHADERDATA_H__
#define C4D_SHADERDATA_H__

#include "ge_prepass.h"
#include "c4d_nodedata.h"
#include "operatingsystem.h"

class BaseShader;
class BaseObject;
class BaseDraw;
class BaseDrawHelp;
class BaseDocument;
class BaseBitmap;
class String;
class BaseTag;
class BaseThread;
struct InitRenderStruct;
struct VolumeData;
struct ChannelData;

//----------------------------------------------------------------------------------------
/// A data class for creating shader (channel shader) plugins.\n
/// Shader plugins appear in the popup menu of the channels in the %Material Manager.
///
/// Use RegisterShaderPlugin() to register a scene hook plugin.
///
/// Here are some general comments on the shader API:
/// - Coordinate Systems: if there is no further note, all elements like points, normals etc. are always given in global coordinates.
/// - Angle Systems: all angle values are always given in radians. Use maxon::RadToDeg() macro for conversion if needed.
/// - Vectors: all normals and ray vectors must be normalized. Also, all normals and ray vectors given by @C4D are normalized.
//----------------------------------------------------------------------------------------
class ShaderData : public NodeData
{
public:
	// Inherited from NodeData
	// virtual Bool Init(GeListNode *node);
	// virtual void Free(GeListNode *node);
	// virtual Bool Read(GeListNode *node, HyperFile *hf, Int32 level);
	// virtual Bool Write(GeListNode *node, HyperFile *hf);
	// virtual Bool Message(GeListNode *node, Int32 type, void *data);
	// virtual Bool CopyTo(NodeData *dest, GeListNode *snode, GeListNode *dnode, COPYFLAGS flags, AliasTrans *trn);
	// virtual void GetBubbleHelp(GeListNode *node, maxon::String &str);
	// virtual BaseDocument* GetDocument(GeListNode *node);
	// virtual Int32 GetBranchInfo(GeListNode *node, BranchInfo *info, Int32 max, GETBRANCHINFO flags);
	// virtual Bool GetDDescription(GeListNode *node, Description *description, DESCFLAGS_DESC &flags);
	// virtual Bool GetDParameter(GeListNode *node, const DescID &id,GeData &t_data,DESCFLAGS_GET &flags);
	// virtual Bool GetDEnabling(GeListNode *node, const DescID &id,const GeData &t_data,DESCFLAGS_ENABLE flags,const BaseContainer *itemdesc);
	// virtual Bool SetDParameter(GeListNode *node, const DescID &id,const GeData &t_data,DESCFLAGS_SET &flags);
	// static NodeData *Alloc(void) { return NewObjClear(MyNodeData); }
	// Inherited from NodeData

	// For use with glProgramFactory::GetDescriptionData
	// static void* AllocCgDescription();
	// static void FreeCgDescription(void* pData);
	// static Bool ReadCgDescription(GlReadDescriptionData* pFile, void* pData);
	// static Bool WriteCgDescription(GlWriteDescriptionData* pFile, const void* pData);

	/// @name Draw
	/// @{

	//----------------------------------------------------------------------------------------
	/// Called to draw additional information for the shader in the editor's view.
	/// @param[in] sh									The BaseShader connected with the ShaderData instance. Equal to <tt>static_cast</tt><@ref ShaderData*>Get(). Provided for speed and convenience. @cinemaOwnsPointed{shader}
	/// @param[in] op									The active object. @cinemaOwnsPointed{object}
	/// @param[in] tag								The active tag. @callerOwnsPointed{tag}
	/// @param[in] bd									The editor's view. @callerOwnsPointed{view}
	/// @param[in] bh									The helper for the editor's view. @callerOwnsPointed{base draw helper}
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	virtual Bool Draw(BaseShader* sh, BaseObject* op, BaseTag* tag, BaseDraw* bd, BaseDrawHelp* bh);

	/// @name Init/Free Render
	/// @{

	//----------------------------------------------------------------------------------------
	/// Called to initialize resources for the render.
	/// @param[in] sh									The BaseShader connected with the ShaderData instance. Equal to <tt>static_cast</tt><@ref ShaderData*>Get(). Provided for speed and convenience. @cinemaOwnsPointed{shader}
	/// @param[in] irs								A struct with information about the upcoming rendering.
	/// @return												The result of the initialization: @enumerateEnum{INITRENDERRESULT}
	//----------------------------------------------------------------------------------------
	virtual INITRENDERRESULT InitRender(BaseShader* sh, const InitRenderStruct& irs);

	//----------------------------------------------------------------------------------------
	/// Called to free any resources allocated in @ref InitRender.
	/// @param[in] sh									The BaseShader connected with the ShaderData instance. Equal to <tt>static_cast</tt><@ref ShaderData*>Get(). Provided for speed and convenience. @cinemaOwnsPointed{shader}
	//----------------------------------------------------------------------------------------
	virtual void FreeRender(BaseShader* sh);

	/// @}

	/// @name Output
	/// @{

	//----------------------------------------------------------------------------------------
	/// Called for each point of the visible surface of a shaded object to calculate and return the channel color for the point @formatParam{cd}->@link ChannelData::p p@endlink.
	/// @calledThreadContext
	/// @param[in] sh									The BaseShader connected with the ShaderData instance. Equal to <tt>static_cast</tt><@ref ShaderData*>Get(). Provided for speed and convenience. @cinemaOwnsPointed{shader}
	/// @param[in] cd									The channel data to use and/or modify. @callerOwnsPointed{channel data}
	/// @return												The calculated color.
	//----------------------------------------------------------------------------------------
	virtual Vector Output(BaseShader* sh, ChannelData* cd);

	/// @}

	/// @name Miscellaneous
	/// @{

	//----------------------------------------------------------------------------------------
	/// Called to get information about what the shader plugin requires from the render and what it will return.
	/// @calledThreadContext
	/// @param[in] sh									The BaseShader connected with the ShaderData instance. Equal to <tt>static_cast</tt><@ref ShaderData*>Get(). Provided for speed and convenience. @cinemaOwnsPointed{shader}
	/// @return												The shader info: @enumerateEnum{SHADERINFO}
	//----------------------------------------------------------------------------------------
	virtual SHADERINFO GetRenderInfo(BaseShader* sh);

	//----------------------------------------------------------------------------------------
	/// Called to return the best SSS sub-shader for the shader.
	/// @note If the shader uses sub-shaders it is crucial that it calls their GetSubsurfaceShader() method override so if any sub-shaders are SSS shaders they are used and initialized properly.\n
	/// For example here is the implementation of @ref GetSubsurfaceShader from SLA (which uses 2 sub-shaders: Texture and Distorter):
	/// @code
	/// BaseShader* CSLADistorter::GetSubsurfaceShader(BaseShader *sh, Float &bestmpl)
	/// {
	/// 	BaseShader *pBestShader = nullptr;
	///
	/// 	if (m_pTexture != nullptr)
	/// 	{
	/// 		BaseShader *pShaderTexture = m_pTexture->GetSubsurfaceShader(bestmpl);
	/// 		if (pShaderTexture != nullptr)
	/// 			pBestShader = pShaderTexture;
	/// 	}
	///
	/// 	if (m_pDistorter != nullptr)
	/// 	{
	/// 		BaseShader *pShaderDistorter = m_pDistorter->GetSubsurfaceShader(bestmpl);
	/// 		if (pShaderDistorter != nullptr)
	/// 			pBestShader = pShaderDistorter;
	/// 	}
	///
	/// 	return pBestShader;
	/// }
	/// @endcode
	/// @param[in] sh									The BaseShader connected with the ShaderData instance. Equal to <tt>static_cast</tt><@ref ShaderData*>Get(). Provided for speed and convenience. @cinemaOwnsPointed{shader}
	/// @param[in] bestmpl						The current best (smallest) Median Path Length found so far.\n
	///																This value should @b never be changed by the code; it is auto adjusted only by the SSS shader and should be passed directly to the subshaders (see example code above).
	/// @return												The best SSS shader found so far.
	//----------------------------------------------------------------------------------------
	virtual BaseShader* GetSubsurfaceShader(BaseShader* sh, Float& bestmpl);

	/// @}

	/// @name OpenGl Mode
	/// @{

	//----------------------------------------------------------------------------------------
	/// @extOpenGlMode
	//----------------------------------------------------------------------------------------
	virtual GL_MESSAGE GlMessage(BaseShader* sh, Int32 type, void* msgdata);

	//----------------------------------------------------------------------------------------
	/// @extOpenGlMode
	//----------------------------------------------------------------------------------------
	virtual Int32 InitGLImage(BaseShader* sh, BaseDocument* doc, BaseThread* th, BaseBitmap* bmp, Bool alpha, Int32 doccolorspace, Bool linearworkflow);

	//----------------------------------------------------------------------------------------
	/// @extOpenGlMode
	//----------------------------------------------------------------------------------------
	virtual void DestroyGLImage(BaseShader* sh, BaseDocument* doc);

	//----------------------------------------------------------------------------------------
	/// @extOpenGlMode
	//----------------------------------------------------------------------------------------
	virtual void InvalidateGLImage(BaseShader* sh, BaseDocument* doc);

	//----------------------------------------------------------------------------------------
	/// Called before the preview image for the shader is calculated.
	/// @param[in] sh									The BaseShader connected with the ShaderData instance. Equal to <tt>static_cast</tt><@ref ShaderData*>Get(). Provided for speed and convenience. @cinemaOwnsPointed{shader}
	/// @param[in] doc								The host document of the shader. @cinemaOwnsPointed{document}
	/// @param[in] s									The exponent of the maximum texture size chosen in the @em Preferences or the %Material Editor tab. (@em 2 ^ @formatParam{s} = maximum preview size)
	/// @param[in] noScale						@formatConstant{true} if the user has selected the "No Scaling" option in the material.
	/// @param[in] w									Assign the width for the preview image.
	/// @param[in] h									Assign the height for the preview image.
	/// @return												@formatConstant{true} to set the preview image size to the assigned (@formatParam{w}, @formatParam{h}).
	//----------------------------------------------------------------------------------------
	virtual Bool GetGLImageSize(BaseShader* sh, BaseDocument* doc, Int32 s, Bool noScale, Int32& w, Int32& h);

	/// @}
};

//----------------------------------------------------------------------------------------
/// Registers a shader plugin.
/// @param[in] id									@uniquePluginID
/// @param[in] str								The name of the plugin.\n
///																To affect the order that plugins are displayed in menus add <i>"#$n"</i> as a prefix to this name, where @em n is a number.\n
///																Lower numbers are displayed before higher numbers. If name is <i>"--"</i> it will show up as a menu separator.
/// @param[in] info								The node plugin info flags: @enumerateEnum{PLUGINFLAG_MATERIAL} @enumerateEnum{PLUGINFLAG}
/// @param[in] g									The allocator for the shader plugin. This is a pointer to a function that creates a new instance of ShaderData with NewObj().
/// @param[in] description				The name of the description resource file to use for the material plugin without @em .res extension, for example @em "Xshadername".\n
///																The name has to be unique, i.e. @em "Tdisplay" cannot be used for 2 different descriptions. See Description Resource for more information.
/// @param[in] disklevel					The plugin level is similar to a version number. The default level is @em 0.\n
///																Increase this for new revisions of a plugin to allow for forward and backward compatibility.\n\n
///																As an example you may have updated a plugin. If you now need to write additional information for new settings or changed types for old settings increase the level.\n
///																During loading either a @em 0 is passed (if the file was written by the old plugin) or @em 1 (if the file was written by the new plugin). This allows to easily write/read new values.\n
///																For forward and backward compatibility to work any existing read order from a given level must not be changed. @C4D skips any new settings automatically if they have not been read.\n\n
///																@formatParam{disklevel} is only useful if variables are written/read in @ref NodeData::Write/@ref NodeData::Read.
/// @return												@trueIfOtherwiseFalse{the shader plugin was registered}
//----------------------------------------------------------------------------------------
Bool RegisterShaderPlugin(Int32 id, const maxon::String& str, Int32 info, DataAllocator* g, const maxon::String& description, Int32 disklevel);

#endif // C4D_SHADERDATA_H__
