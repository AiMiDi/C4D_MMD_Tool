/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef CUSTOMGUI_MATPREVIEW_H__
#define CUSTOMGUI_MATPREVIEW_H__

#include "c4d_library.h"
#include "c4d_basecontainer.h"
#include "c4d_gui.h"
#include "c4d_customdatatype.h"
#include "customgui_base.h"
#include "c4d_baselist.h"
#include "c4d_thread.h"

/// %Material preview custom GUI ID.
#define CUSTOMGUI_MATPREVIEW					1011152

/// %Material preview custom data type ID.
#define CUSTOMDATATYPE_MATPREVIEW			1011153

/// @addtogroup MATPREVIEW_CUSTOMGUISETTINGS
/// @ingroup CUSTOMGUISETTINGS
/// @{
#define MATPREVIEW_MIN_WIDTH					1000			///< ::Int32 Minimum width.
#define MATPREVIEW_MIN_HEIGHT					1001			///< ::Int32 Minimum height.
#define MATPREVIEW_NO_SIZE_POPUP			1002			///< ::Bool No size popup.
#define MATPREVIEW_NO_BORDER					1003			///< ::Bool No border.
#define MATPREVIEW_NO_ANIMATION				1004			///< ::Bool No animation.
#define MATPREVIEW_NO_FLOATWINDOW			1005			///< ::Bool No floating window.
#define MATPREVIEW_NO_SCENESETTINGS		1006			///< ::Bool No scene settings.
#define MATPREVIEW_RECTSELECT					1007			///< ::Bool Allow rectangle selection by the user, accessed with @ref MaterialPreviewData::GetRegion/@ref MaterialPreviewData::SetRegion.\n
																								///< Only used if a callback function is used to render the preview.
#define MATPREVIEW_NO_SCENESELECTION	1008			///< ::Bool No scene selection is possible.
/// @}

/// @addtogroup MATPREVIEW
/// @ingroup group_enumeration
/// @{
/// Overriding NodeData::Message it is not recommended to check for a @formatConstant{nullptr} pointer in @c node->GetDocument() if it is a @ref MATPREVIEW message.\n
/// For those messages the document might be @formatConstant{nullptr} in some cases, but the method should not be aborted.
#define MATPREVIEW_GET_OBJECT_INFO			1011147				///< Sent by the material preview to get object information from the host. The corresponding @em data is MatPreviewObjectInfo.
#define MATPREVIEW_GENERATE_IMAGE				1011148				///< Sent by the material preview when the host object is responsible for the rendering (MatPreviewObjectInfo::bHandlePreview is @formatConstant{true}). The corresponding @em data is MatPreviewGenerateImage.
#define MATPREVIEW_MODIFY_CACHE_SCENE		1011149				///< Sent by the material preview to let the host modify the preview scene. A pointer to a scene inside the preview scene cache is sent. The corresponding @em data is MatPreviewModifyCacheScene.
#define MATPREVIEW_PREPARE_SCENE				1011142				///< Sent each time the preview wants to render the host scene. The corresponding @em data is MatPreviewPrepareScene.
#define MATPREVIEW_GET_PREVIEW_ID				1011143				///< The corresponding @em data is ::Int32. Set it to the ID of the material preview.
#define MATPREVIEW_GET_POPUP_OPTIONS		1011141				///< Let add extra material preview popup menu items to a custom sub-menu.\n
																											///< The corresponding @em data is a BaseContainer which represents the menu. Insert the menu items. Set the name of the sub-menu with @ref MATPREVIEW_POPUP_NAME.\n
																											///< @b Example:
																											/// @code
																											/// case MATPREVIEW_GET_POPUP_OPTIONS:
																											/// {
																											/// 	BaseContainer* bc = static_cast<BaseContainer*>(data);
																											///
																											/// 	// Element with index MATPREVIEW_POPUP_NAME is the text of the popup item.
																											/// 	bc->SetString(MATPREVIEW_POPUP_NAME, GeLoadString(IDS_PARTICLEVOLUME));
																											///
																											/// 	// A menu item. (Container entries should start with 1.)
																											/// 	bc->SetString(1, GeLoadString(IDS_PARTICLEVOLUME_HIGH_DENSITY) + (highDensity ? "&c&" : ""));
																											///
																											/// 	// Add an example separator.
																											/// 	bc->SetString(0, "");
																											///
																											/// 	// Yet another menu item.
																											/// 	bc->SetString(2, GeLoadString(IDS_PARTICLEVOLUME_LOW_DENSITY) + (!highDensity ? "&c&" : ""));
																											/// 	return true;
																											/// }
																											/// break;
																											/// @endcode
#define MATPREVIEW_HANDLE_POPUP_MSG			1011144				///< Sent when the user has selected any of the options in the material preview popup. The corresponding data is an ::Int32 which is the menu item ID.
#define MATPREVIEW_FREE_USERDATA				450000029			///< Sent to free the user data. (Only sent when the preview is initialized with a callback.)
#define MATPREVIEW_COPY_USERDATA				450000030			///< Sent to copy the user data. The corresponding @em data is a MatPreviewCopyUserData. Set MatPreviewCopyUserData::dst to a clone of MatPreviewCopyUserData::src. (Only sent when the preview is initialized with a callback.)
#define MATPREVIEW_DRAGNDROP_RECV				450000062			///< Preview has received drag and drop. The corresponding @em data is MatPreviewHandleDragnDrop.
#define MATPREVIEW_DRAGNDROP_START			450000063			///< Start drag and drop (fill in the MatPreviewHandleDragnDrop structure). The corresponding @em data is MatPreviewHandleDragnDrop.
#define MATPREVIEW_DRAGNDROP_END				450000064			///< Drag and drop finished, free @em data. The corresponding @em data is MatPreviewHandleDragnDrop.
#define MATPREVIEW_GET_DIRTY_COUNT			450000065			///< Let return a dirty count for the preview.

#define MATPREVIEW_POPUP_NAME						99999					///< String Popup name.

#define MATPREVIEW_NULL_SIZE_NAME				"null-size"			///<
/// @}

/// @addtogroup MATPREVIEW_FLAG
/// @ingroup group_enumeration
/// @{
#define MATPREVIEW_FLAG_HIDE_ROTATION					1				///< Hide rotation.
#define MATPREVIEW_FLAG_HIDE_SCENES						2				///< Hide scenes.
#define MATPREVIEW_FLAG_HIDE_ANIMATE					4				///< Hide animation.
#define MATPREVIEW_FLAG_HIDE_SIZE							8				///< Hide size.
#define MATPREVIEW_FLAG_HIDE_OPEN							16			///< Hide open.
#define MATPREVIEW_FLAG_HIDE_SCENE_SETTINGS		32			///< Hide scene settings.
#define MATPREVIEW_FLAG_ALLOW_DRAGNDROP				64			///< Allow drag and drop.
/// @}

class MaterialPreviewData;

/// @addtogroup MatPreviewType
/// @ingroup group_enumeration
/// @{
enum MatPreviewType
{
	MatPreviewDefault = 999,					///< Default.
	MatPreviewFlat2D = 1000,					///< Flat 2D
	MatPreviewCube,										///< Cube.
	MatPreviewPlane,									///< Plane.
	MatPreviewCylinder,								///< Cylinder.
	MatPreviewTorus,									///< Torus.
	MatPreviewPlaneBack,							///< Plane Backlight.
	MatPreviewSphere,									///< Sphere.
	MatPreview2Torus,									///< Double Torus.
	MatPreviewRoundedCube,						///< Rounded Cube.
	MatPreviewKnot,										///< Knot.
	MatPreviewMultipleObjects,				///< Multiple Objects.
	MatPreviewCandle,									///< Candle.
	MatPreviewCloth,									///< Cloth.
	MatPreviewGem,										///< Gem.
	MatPreviewObjectAnim,							///< Animated Object.
	MatPreviewObject,									///< Object.
	MatPreviewUser = 1050							///< %User.
};
/// @}

/// @addtogroup MatPreviewSize
/// @ingroup group_enumeration
/// @{
enum MatPreviewSize
{
	MatPreviewSizeDefault = 2000,			///< Use system default.
	MatPreviewSizeSmall,							///< Small.
	MatPreviewSizeMedium,							///< Medium.
	MatPreviewSizeBig,								///< Big.
	MatPreviewSizeLarge								///< Large.
};
/// @}

//----------------------------------------------------------------------------------------
/// Message struct for @ref MATPREVIEW_GET_OBJECT_INFO.
//----------------------------------------------------------------------------------------
struct MatPreviewObjectInfo
{
	Bool bHandlePreview;				///< Set to @formatConstant{true} if the material has its own preview handler.
	Bool bNeedsOwnScene;				///< Set to @formatConstant{true} if the material modifies the default scene.
	Bool bNoStandardScene;			///< Set to @formatConstant{true} if no scene should appear in the popup menu and a custom preview scene will be created. @ref bNeedsOwnScene has to be @formatConstant{true} if the standard scene is not used.\n
															///< An empty scene is then passed for the message @ref MATPREVIEW_MODIFY_CACHE_SCENE to build one.
	Int32 lFlags;								///< A combination of the following flags: (Only evaluated if @ref bHandlePreview is set to @formatConstant{true}.) @enumerateEnum{MATPREVIEW_FLAG}
};

//----------------------------------------------------------------------------------------
/// Message struct for @ref MATPREVIEW_MODIFY_CACHE_SCENE.
//----------------------------------------------------------------------------------------
struct MatPreviewModifyCacheScene
{
	MatPreviewType t;					///< The preview type: @enumerateEnum{MatPreviewType}
	String strUserScene;			///< The name of the preview scene. (File name without path and extension.)
	BaseDocument* pDoc;				///< The preview document. @callerOwnsPointed{document}
};

//----------------------------------------------------------------------------------------
/// Message struct for @ref MATPREVIEW_PREPARE_SCENE.
//----------------------------------------------------------------------------------------
struct MatPreviewPrepareScene
{
	Bool bScenePrepared;										///< Set to @formatConstant{true} if you modified the scene; the preview will do this for you otherwise.
	BaseLink* pLink;												///< Point this link the cloned material object you insert into the scene.May be @formatConstant{nullptr}. @callerOwnsPointed{link}
	BaseDocument* pDoc;											///< The preview document (a clone of the scene cache entry). @callerOwnsPointed{document}
	Matrix matrDefault;											///< The default object matrix.
	MaterialPreviewData* pPreviewData;			///< The preview data. May be @formatConstant{nullptr}. @callerOwnsPointed{data}
	BaseDocument* pOriginalDoc;							///< The original document. Only access it if there is no other way. @callerOwnsPointed{document}
};

//----------------------------------------------------------------------------------------
/// Message struct for @ref MATPREVIEW_GENERATE_IMAGE.
//----------------------------------------------------------------------------------------
struct MatPreviewGenerateImage
{
	BaseDocument* pDoc;				///< The document. May be @formatConstant{nullptr}. @callerOwnsPointed{document}
	BaseBitmap* pDest;				///< An initialized bitmap to render to. @callerOwnsPointed{bitmap}
	BaseThread* pThread;			///< The rendering thread. May be @formatConstant{nullptr}. @callerOwnsPointed{thread}
	Float rTime;							///< The current preview time.
	Bool bEditorPreview;			///< Never used. Always @formatConstant{false}.
	Float rWorldSize;					///< Scale the scene (usually the object named @ref MATPREVIEW_NULL_SIZE_NAME) by @ref rWorldSize. Scale it by @em 1.0 after render is complete.
	Bool bLowQuality;					///< @formatConstant{true} if you may render in low quality (e.g. during rotating the object).
	RENDERRESULT lResult;			///< Return one of the possible return values from RenderDocument(): @enumerateEnum{RENDERRESULT}
	Bool bIsAnimating;				///< Indicates whether the user has chosen @em Animate in the preview.
};

//----------------------------------------------------------------------------------------
/// Message struct for @ref MATPREVIEW_COPY_USERDATA.
//----------------------------------------------------------------------------------------
struct MatPreviewCopyUserData
{
	void* src;			///< The source.
	void* dst;			///< The destination.
};

//----------------------------------------------------------------------------------------
/// Message struct for @ref MATPREVIEW_DRAGNDROP_START, @ref MATPREVIEW_DRAGNDROP_RECV and @ref MATPREVIEW_DRAGNDROP_END.
/// @see The article @link page_manual_guimessages_messages_dragdrop Drag and Drop@endlink for more information.
//----------------------------------------------------------------------------------------
struct MatPreviewHandleDragnDrop
{
	Int32 lType;												///< The drag type.
	void* pObj;													///< The drag object.
	GeDialog* pDlg;											///< The drag dialog.
	const BaseContainer* pDragData;			///< The drag data container.
	Int32 lReturn;											///< The drag return.
};

//----------------------------------------------------------------------------------------
/// Called to process host message for the MaterialPreviewData when initialized with this callback.
/// @param[in] lMessage						The message: @enumerateEnum{MATPREVIEW}
/// @param[in] pData							The message data.
/// @param[in] pUserData					A clone of the user data.
/// @return												@trueIfOtherwiseFalse{successful}
//----------------------------------------------------------------------------------------
typedef Bool (*RenderPreviewImageCallback)(Int32 lMessage, void* pData, void* pUserData);

//----------------------------------------------------------------------------------------
/// %Material preview data type (@ref CUSTOMDATATYPE_MATPREVIEW) for MaterialPreviewCustomGui.
//----------------------------------------------------------------------------------------
class MaterialPreviewData : public CustomDataType
{
private:
	MaterialPreviewData();
	~MaterialPreviewData();
public:
	/// @name Init
	/// @{

	//----------------------------------------------------------------------------------------
	/// Initializes the material preview with @formatParam{pChannel}.
	/// @param[in] pChannel						The initial preview source. @callerOwnsPointed{channel}
	/// @param[in] lCount							The dirty count. Used to detect changes.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool Init(BaseChannel *pChannel, Int32 lCount);

	//----------------------------------------------------------------------------------------
	/// Initializes the material preview with @formatParam{pShader}.
	/// @param[in] pShader						The initial preview source. @callerOwnsPointed{shader}
	/// @param[in] lCount							The dirty count. Used to detect changes.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool Init(BaseShader* pShader, Int32 lCount);

	//----------------------------------------------------------------------------------------
	/// Initializes the material preview with @formatParam{pMaterial}.
	/// @param[in] pMaterial					The initial preview source. @callerOwnsPointed{material}
	/// @param[in] lCount							The dirty count. Used to detect changes.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool Init(BaseMaterial* pMaterial, Int32 lCount);

	//----------------------------------------------------------------------------------------
	/// Initializes the material preview with @formatParam{pImage}.
	/// @param[in] pImage							The initial preview source. @callerOwnsPointed{bitmap}
	/// @param[in] lCount							The dirty count. Used to detect changes.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool Init(BaseBitmap* pImage, Int32 lCount);

	//----------------------------------------------------------------------------------------
	/// Initializes the material preview with a custom image hook. The hook will handle all host messages.
	/// @param[in] fn									The callback for the preview.
	/// @param[in] pUserData					The user data. Passed along to the hook. May be deleted after the function has finished.
	/// @param[in] lUserID						A user ID for the material preview. Used to identify the callback.
	/// @param[in] lCount							The dirty count. Increment this whenever a parameter has been changed.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool Init(RenderPreviewImageCallback fn, void* pUserData, Int32 lUserID, Int32 lCount);

	/// @}

	//----------------------------------------------------------------------------------------
	/// Sets the preview animation state.
	/// @param[in] bAnimate						The new animation state.
	//----------------------------------------------------------------------------------------
	void AnimatePreview(Bool bAnimate);

	//----------------------------------------------------------------------------------------
	/// Checks the preview animation state.
	/// @return												The preview animation state.
	//----------------------------------------------------------------------------------------
	Bool PreviewIsAnimated();

	//----------------------------------------------------------------------------------------
	/// Sets the preview type.
	/// @param[in] t									The new preview type: @enumerateEnum{MatPreviewType}
	//----------------------------------------------------------------------------------------
	void SetPreviewType(MatPreviewType t);

	//----------------------------------------------------------------------------------------
	/// Checks the preview type.
	/// @return												The preview type: @enumerateEnum{MatPreviewType}
	//----------------------------------------------------------------------------------------
	MatPreviewType GetPreviewType();

	//----------------------------------------------------------------------------------------
	/// Sets the user preview scene name.
	/// @param[in] strName						The new user preview scene name.
	//----------------------------------------------------------------------------------------
	void SetUserPreviewSceneName(const maxon::String &strName);

	//----------------------------------------------------------------------------------------
	/// Retrieves the user preview scene name.
	/// @return												The user preview scene name.
	//----------------------------------------------------------------------------------------
	String GetUserPreviewSceneName();

	//----------------------------------------------------------------------------------------
	/// Sets the preview size.
	/// @param[in] s									The new preview size: @enumerateEnum{MatPreviewSize}
	//----------------------------------------------------------------------------------------
	void SetPreviewSize(MatPreviewSize s);

	//----------------------------------------------------------------------------------------
	/// Retrieves the preview size.
	/// @return												The preview size.
	//----------------------------------------------------------------------------------------
	MatPreviewSize GetPreviewSize();

	//----------------------------------------------------------------------------------------
	/// Sets the object matrix.
	/// @param[in] m									The new object matrix.
	//----------------------------------------------------------------------------------------
	void SetObjectMatrix(const Matrix &m);

	//----------------------------------------------------------------------------------------
	/// Retrieves the object matrix.
	/// @param[out] m									Assigned the object matrix, if not cleared.
	/// @return												@formatConstant{true} if successful, @formatConstant{false} if the object matrix is not initialized.
	//----------------------------------------------------------------------------------------
	Bool GetObjectMatrix(Matrix &m);

	//----------------------------------------------------------------------------------------
	/// Clears the object matrix, i.e to an uninitialized state.
	//----------------------------------------------------------------------------------------
	void ClearObjectMatrix();

	//----------------------------------------------------------------------------------------
	/// Retrieves the world size.
	/// @return												The world size.
	//----------------------------------------------------------------------------------------
	Float GetWorldSize();

	//----------------------------------------------------------------------------------------
	/// Sets the world size.
	/// @param[in] r									The new world size.
	//----------------------------------------------------------------------------------------
	void SetWorldSize(Float r);

	//----------------------------------------------------------------------------------------
	/// Retrieves the preview start time.
	/// @return												The preview start time.
	//----------------------------------------------------------------------------------------
	Float GetPreviewStartTime();

	//----------------------------------------------------------------------------------------
	/// Sets the preview start time.
	/// @param[in] r									The new start time.
	//----------------------------------------------------------------------------------------
	void SetPreviewStartTime(Float r);

	//----------------------------------------------------------------------------------------
	/// Gets the environment data.
	/// @param[out] col								Assigned the environment color.
	/// @param[out] strength					Assigned the environment strength.
	//----------------------------------------------------------------------------------------
	void GetEnvironment(Vector &col, Float &strength);

	//----------------------------------------------------------------------------------------
	/// Sets the environment data.
	/// @param[in] col								The new environment color.
	/// @param[in] strength						The new environment strength.
	//----------------------------------------------------------------------------------------
	void SetEnvironment(const Vector &col, const Float &strength);

	//----------------------------------------------------------------------------------------
	/// Retrieves the dirty count for the preview.
	/// @return												The dirty count.
	//----------------------------------------------------------------------------------------
	Int32 GetDirtyCount();

	//----------------------------------------------------------------------------------------
	/// Retrieves the current selection region.
	/// @param[out] l									Assigned the left boundary, between @em 0 and @em 1.
	/// @param[out] t									Assigned the top boundary, between @em 0 and @em 1.
	/// @param[out] r									Assigned the right boundary, between @em 0 and @em 1.
	/// @param[out] b									Assigned the bottom boundary, between @em 0 and @em 1.
	/// @return												@trueIfOtherwiseFalse{the region could be retrieved}
	//----------------------------------------------------------------------------------------
	Bool GetRegion(Float &l, Float &t, Float &r, Float &b);

	//----------------------------------------------------------------------------------------
	/// Sets a selection region in the preview.
	/// @param[in] bActive						Determines if the rectangle is active or not.
	/// @param[in] l									The new left boundary, between @em 0 and @em 1.
	/// @param[in] t									The new top boundary, between @em 0 and @em 1.
	/// @param[in] r									The new right boundary, between @em 0 and @em 1.
	/// @param[in] b									The new bottom boundary, between @em 0 and @em 1.
	//----------------------------------------------------------------------------------------
	void SetRegion(Bool bActive, Float l, Float t, Float r, Float b);

	//----------------------------------------------------------------------------------------
	/// Retrieves the channel used for preview.
	/// @return												The channel: @enumerateEnum{CHANNEL}
	//----------------------------------------------------------------------------------------
	Int32 GetPreviewChannel();

	//----------------------------------------------------------------------------------------
	/// Sets the channel used for preview.
	/// @param[in] lChannel						The new channel: @enumerateEnum{CHANNEL}
	//----------------------------------------------------------------------------------------
	void SetPreviewChannel(Int32 lChannel);

	//----------------------------------------------------------------------------------------
	/// Retrieves the reflection layer used for preview.
	/// @since R16
	/// @return												The reflection layer ID or ::NOTOK if unset.
	//----------------------------------------------------------------------------------------
	Int32 GetReflectionLayer();

	//----------------------------------------------------------------------------------------
	/// Sets the reflection layer used for preview.
	/// @note	Suited to test a specific reflectance layer. This disables several material properties in the preview like color and transparency. It also only shows the effect of the reflectance layer with ID @formatParam{lLayer} if any.\n
	///				Make sure to check the layer with ID @formatParam{lLayer} exists before setting this, otherwise one may get a pure-black material preview.\n
	///				Keep always in mind that reflection layers can be removed any time (both by user and via API), therefore a specific layer ID could be no longer valid.
	/// @since R16
	/// @param[in] lLayer							The reflection layer ID to set. Pass ::NOTOK to revert back to normal behavior i.e. to show all material properties and all reflection layers.
	//----------------------------------------------------------------------------------------
	void SetReflectionLayer(Int32 lLayer);
};

//----------------------------------------------------------------------------------------
/// Convenience function to use in NodeData::SetDParameter() of nodes with a material preview in the description:
/// @code
/// Bool SimpleMaterial::SetDParameter(GeListNode *node, const DescID &id, const GeData &t_data, DESCFLAGS_SET &flags)
/// {
/// 	BaseMaterial* mat = static_cast<BaseMaterial*>(node);
/// 	BaseContainer* data = mat->GetDataInstance();
///
/// 	updatecount++;
///
/// 	switch (id[0].id)
/// 	{
/// 	case SIMPLEMATERIAL_MAT_PREVIEW:
/// 		return SetDParameterPreview(data, &t_data, flags, SIMPLEMATERIAL_MAT_PREVIEW);
/// 	}
///
/// 	return MaterialData::SetDParameter(node, id, t_data, flags);
/// }
/// @endcode
/// @param[in] pContainer					The container of the node sent to NodeData::SetDParameter(). @callerOwnsPointed{container}
/// @param[in] pData							The @em t_data sent to NodeData::SetDParameter(). @callerOwnsPointed{data}
/// @param[in] lFlags							The @em flags sent to NodeData::SetDParameter().
/// @param[in] lID								The ID of the material preview.
/// @return												@trueIfOtherwiseFalse{successful}
//----------------------------------------------------------------------------------------
Bool SetDParameterPreview(BaseContainer* pContainer, const GeData* pData, DESCFLAGS_SET &lFlags, Int32 lID);

//----------------------------------------------------------------------------------------
/// Convenience function to use in NodeData::GetDParameter() of material nodes with a material preview in the description:
/// @code
/// Bool SimpleMaterial::GetDParameter(GeListNode *node, const DescID &id, GeData &t_data, DESCFLAGS_GET &flags)
/// {
/// 	BaseMaterial* mat = static_cast<BaseMaterial*>(node);
/// 	BaseContainer* data = mat->GetDataInstance();
///
/// 	switch (id[0].id)
/// 	{
/// 	case SIMPLEMATERIAL_MAT_PREVIEW:
/// 		return GetDParameterPreview(data, &t_data, flags, SIMPLEMATERIAL_MAT_PREVIEW, updatecount, mat);
/// 	}
///
/// 	return MaterialData::GetDParameter(node, id, t_data, flags);
/// }
/// @endcode
/// @param[in] pContainer					The container of the node sent to NodeData::GetDParameter(). @callerOwnsPointed{container}
/// @param[in] pData							The @em t_data sent to NodeData::GetDParameter(). @callerOwnsPointed{data}.
/// @param[in] lFlags							The @em flags sent to NodeData::GetDParameter().
/// @param[in] lID								The ID of the material preview.
/// @param[in] lCount							The dirty count.
/// @param[in] pMaterial					The material. @callerOwnsPointed{material}
/// @return												@trueIfOtherwiseFalse{successful}
//----------------------------------------------------------------------------------------
Bool GetDParameterPreview(BaseContainer* pContainer, GeData* pData, DESCFLAGS_GET &lFlags, Int32 lID, Int32 lCount, BaseMaterial* pMaterial);

//----------------------------------------------------------------------------------------
/// Convenience function to use in NodeData::GetDParameter() of shader nodes with a material preview in the description:
/// @code
/// Bool SimpleShader::GetDParameter(GeListNode *node, const DescID &id, GeData &t_data, DESCFLAGS_GET &flags)
/// {
/// 	BaseShader* shd = static_cast<BaseMaterial*>(node);
/// 	BaseContainer* data = shd->GetDataInstance();
///
/// 	switch (id[0].id)
/// 	{
/// 	case SIMPLEMATERIAL_MAT_PREVIEW:
/// 		return GetDParameterPreview(data, &t_data, flags, SIMPLEMATERIAL_MAT_PREVIEW, updatecount, shd);
/// 	}
///
/// 	return ShaderData::GetDParameter(node, id, t_data, flags);
/// }
/// @endcode
/// @param[in] pContainer					The container of the node sent to NodeData::GetDParameter(). @callerOwnsPointed{container}
/// @param[in] pData							The @em t_data sent to NodeData::GetDParameter(). @callerOwnsPointed{data}.
/// @param[in] lFlags							The @em flags sent to NodeData::GetDParameter().
/// @param[in] lID								The ID of the material preview.
/// @param[in] lCount							The dirty count.
/// @param[in] pShader						The shader. @callerOwnsPointed{shader}
/// @return												@trueIfOtherwiseFalse{successful}
//----------------------------------------------------------------------------------------
Bool GetDParameterPreview(BaseContainer* pContainer, GeData* pData, DESCFLAGS_GET &lFlags, Int32 lID, Int32 lCount, BaseShader* pShader);

//----------------------------------------------------------------------------------------
/// Retrieves a list of preview scenes. Use the returned container's elements in menus.
/// @param[in] bIncludeFlat2D			Include Flat 2D.
/// @param[in] bIncludeDefault		Include Default.
/// @param[in] lObjectID					An object ID.
/// @return												The generated menu container.
//----------------------------------------------------------------------------------------
BaseContainer GetPreviewScenes(Bool bIncludeFlat2D, Bool bIncludeDefault = false, Int32 lObjectID = -1);

//----------------------------------------------------------------------------------------
/// Generates the type and the scene name from the menu item generated by GetPreviewScenes().
/// @param[in] lID								The selected menu ID.
/// @param[out] t									Assigned the preview type.
/// @param[out] strScene					Assigned the scene name.
/// @return												@trueIfOtherwiseFalse{successful}
//----------------------------------------------------------------------------------------
Bool HandlePreviewSceneMessage(Int32 lID, MatPreviewType &t, maxon::String &strScene);

//----------------------------------------------------------------------------------------
/// Adds a user scene that optionally only shows up in materials with type lID. The pstrName may be nullptr, in which case the file name is used.
/// @note The scene has to contain an object named "Object" (which may well be a Null containing a group of objects) in order to be used by this function.
/// @param[in] fn									The user scene name.
/// @param[in] lID								The material ID, or @em -1 to make the preview scene available for all materials.
/// @param[in] pstrName						An optional user scene name. The string is copied. @callerOwnsPointed{string}
/// @return												@trueIfOtherwiseFalse{successful}
//----------------------------------------------------------------------------------------
Bool AddUserPreviewScene(const Filename &fn, Int32 lID, maxon::String* pstrName);

/// Renders in full bitmap size, ignoring the settings in the material or shader data. (For RenderMaterialPreview() and RenderShaderPreview().)
#define RENDER_PREVIEW_USE_BMP_SIZE	1

//----------------------------------------------------------------------------------------
/// Called by @C4D to calculate the material preview for the %Material Manager. @markPrivate
//----------------------------------------------------------------------------------------
RENDERRESULT RenderMaterialPreview(const Filename &docpath, BaseMaterial* pMatClone, BaseMaterial* pOrigMat, BaseThread* pThread, BaseBitmap* pDest, BaseDocument *pOriginalDoc, Float rCurrentTime, Int32 lFlags = 0);

//----------------------------------------------------------------------------------------
/// Called by @C4D to calculate the shader preview for the %Material Manager. @markPrivate
//----------------------------------------------------------------------------------------
RENDERRESULT RenderShaderPreview(const Filename &docpath, BaseShader* pShaderClone, BaseShader* pOrigShader, BaseThread* pThread, BaseBitmap* pDest, BaseDocument *pOriginalDoc, Float rCurrentTime, Int32 lFlags = 0);

//----------------------------------------------------------------------------------------
/// Called by @C4D to calculate a custom preview. @markPrivate
//----------------------------------------------------------------------------------------
RENDERRESULT RenderCustomPreview(RenderPreviewImageCallback fn, void* pUserData, Int32 lUserID, BaseThread* pThread, BaseBitmap* pDest, Int32 lFlags = 0);

//----------------------------------------------------------------------------------------
/// %Material preview custom GUI (@ref CUSTOMGUI_MATPREVIEW) for the MaterialPreviewData data type.\n
/// Here are the settings: @enumerateEnum{MATPREVIEW_CUSTOMGUISETTINGS}
//----------------------------------------------------------------------------------------
class MaterialPreviewCustomGui : public BaseCustomGui<CUSTOMGUI_MATPREVIEW>
{
		MaterialPreviewCustomGui();
		~MaterialPreviewCustomGui();
};

/// @cond IGNORE

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

#ifndef _MATPREVIEW_INTERNAL_DEF_
	class iMatPreviewCustomGui
	{
	};
	class iMatPreviewData
	{
	};
#else
	class iMatPreviewCustomGui;
	class iMatPreviewData;
#endif

struct CustomGuiMatPreviewLib : public BaseCustomGuiLib
{
	Bool						(iMatPreviewData::*InitChannel)(BaseChannel *pChannel, Int32 lCount);
	Bool						(iMatPreviewData::*InitShader)(BaseShader* pShader, Int32 lCount);
	Bool						(iMatPreviewData::*InitMaterial)(BaseMaterial* pMaterial, Int32 lCount);
	Bool						(iMatPreviewData::*InitBitmap)(BaseBitmap* pImage, Int32 lCount);
	void						(iMatPreviewData::*AnimatePreview)(Bool bAnimate);
	Bool						(iMatPreviewData::*PreviewIsAnimated)();
	void						(iMatPreviewData::*SetPreviewType)(MatPreviewType t);
	MatPreviewType	(iMatPreviewData::*GetPreviewType)();
	void						(iMatPreviewData::*SetPreviewSize)(MatPreviewSize s);
	MatPreviewSize	(iMatPreviewData::*GetPreviewSize)();
	void						(iMatPreviewData::*SetObjectMatrix)(const Matrix &m);
	Bool						(iMatPreviewData::*GetObjectMatrix)(Matrix &m);
	void						(iMatPreviewData::*SetUserPreviewSceneName)(const maxon::String &strName);
	String					(iMatPreviewData::*GetUserPreviewSceneName)();
	void						(iMatPreviewData::*ClearObjectMatrix)();

	Bool					(*MatPreview_SetDParameterPreview)(BaseContainer* pContainer, const GeData* pData, DESCFLAGS_SET &lFlags, Int32 lID);
	Bool					(*MatPreview_GetDParameterPreviewMat)(BaseContainer* pContainer, GeData* pData, DESCFLAGS_GET &lFlags, Int32 lID, Int32 lCount, BaseMaterial* pMaterial);
	Bool					(*MatPreview_GetDParameterPreviewShd)(BaseContainer* pContainer, GeData* pData, DESCFLAGS_GET &lFlags, Int32 lID, Int32 lCount, BaseShader* pShader);
	BaseContainer	(*MatPreview_GetPreviewScenes)(Bool bIncludeFlat2D, Bool bIncludeDefault, Int32 lObjectID);
	Bool					(*MatPreview_HandlePreviewSceneMessage)(const Int32 lID, MatPreviewType &t, maxon::String &strScene);
	Bool					(*MatPreview_AddUserPreviewScene)(const Filename &fn, Int32 lID, maxon::String* pstrName);

	Float				(iMatPreviewData::*GetWorldSize)();
	void				(iMatPreviewData::*SetWorldSize)(Float r);
	Float				(iMatPreviewData::*GetPreviewStartTime)();
	void				(iMatPreviewData::*SetPreviewStartTime)(Float r);
	void				(iMatPreviewData::*GetEnvironment)(Vector &col, Float &strength);
	void				(iMatPreviewData::*SetEnvironment)(const Vector &col, const Float &strength);

	Int32				(iMatPreviewData::*GetDirtyCount)();
	Bool				(iMatPreviewData::*InitFunction)(RenderPreviewImageCallback fn, void* pUserData, Int32 lUserID, Int32 lCount);
	Bool				(iMatPreviewData::*GetRegion)(Float &l, Float &t, Float &r, Float &b);
	void				(iMatPreviewData::*SetRegion)(Bool bActive, Float l, Float t, Float r, Float b);

	RENDERRESULT	(*MatPreview_RenderMaterialPreview)(const Filename &docpath, BaseMaterial* pMatClone, BaseMaterial* pOrigMat, BaseThread* pThread, BaseBitmap* pDest, BaseDocument *pOriginalDoc, Float rCurrentTime, Int32 lFlags);
	RENDERRESULT	(*MatPreview_RenderShaderPreview)(const Filename &docpath, BaseShader* pShaderClone, BaseShader* pOrigShader, BaseThread* pThread, BaseBitmap* pDest, BaseDocument *pOriginalDoc, Float rCurrentTime, Int32 lFlags);
	RENDERRESULT	(*MatPreview_RenderCustomPreview)(RenderPreviewImageCallback fn, void* pUserData, Int32 lUserID, BaseThread* pThread, BaseBitmap* pDest, Int32 lFlags);

	Int32				(iMatPreviewData::*GetPreviewChannel)();
	void				(iMatPreviewData::*SetPreviewChannel)(Int32 lChannel);
	Int32				(iMatPreviewData::*GetReflectionLayer)();
	void				(iMatPreviewData::*SetReflectionLayer)(Int32 lLayer);
};

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

/// @endcond

#endif // CUSTOMGUI_MATPREVIEW_H__
