/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef C4D_FALLOFFDATA_H__
#define C4D_FALLOFFDATA_H__

#include "ge_math.h"
#include "ofalloff_standard.h"
#include "c4d_basedata.h"
#include "c4d_basecontainer.h"
#include "customgui_field.h"

#ifdef CINEWARE_NAMESPACE_ENABLE
	CINEWARE_NAMESPACE_BEGIN
#endif

class HandleInfo;
class C4D_Falloff;

/// @addtogroup ID_C4DFALLOFF
/// @ingroup group_enumeration
/// @{
#define ID_C4DFALLDATALIB			1019551 ///< Falloff data library ID.
#define ID_C4DFALLOFFLIB			1019541 ///< Falloff library ID.
#define ID_BASE_FALLOFF				1018684 ///< Base Falloff GUI. @since R9.6
#define ID_STANDARD_FALLOFF		1019559 ///< Standard Falloff GUI. @sinze R9.6
#define ID_FIELDSONLY_FALLOFF 1060447 ///< Fields only standard gui
/// @}

/// @addtogroup ID_C4DFALLOFF
/// @ingroup group_enumeration
/// @{
#define MSG_COLLECTC4DFALLOFF	440000221	///< Message sent to a BaseList that might contain a C4DFalloff. BaseList should fill out the passed FalloffCollectMessage. @markPrivate @since R18

/// Structure sent to BaseList2D with the message ::MSG_COLLECTC4DFALLOFF. @markPrivate
/// @since R18
struct FalloffCollectMessage
{
	C4D_Falloff* _falloff;	///< Falloff to be filled by the object owning the C4D_Falloff on ::MSG_COLLECTC4DFALLOFF.
};
/// @}

//----------------------------------------------------------------------------------------
/// Holds the data for FalloffData plugins.\n Structure is read-only. The only exception is @link
/// FalloffDataData::_userData _userData@endlink, which can be set to whatever.\n
/// @link FalloffDataData::_userData _userData@endlink must be checked before it is accessed as it can be
/// reset to @formatConstant{nullptr}.\n
/// It is not normally reset to @formatConstant{nullptr} in-between switches to a different falloff, so it
/// should be cleared in FalloffData::FreeFalloff if it has been set before.\n
/// @note @link FalloffDataData::_userData _userData@endlink is usually filled and used for speed within
/// FalloffData::Sample.
//----------------------------------------------------------------------------------------
struct FalloffDataData
{
public:

	MAXON_OPERATOR_EQUALITY(FalloffDataData, _mat, _imat, _falloff, _scale, _strength, _size, _invert, _clamped, _visible, _useSpline, _nodemat,
													_inverseNodeMat, _offset, _axis, _slice, _torusRadius, _function, _spherical, _radius, _inverseRadius, _inverseFalloff, _animTime);

	//----------------------------------------------------------------------------------------
	/// Inequality operator. Checks if two FalloffDataDatas are different.
	/// @param[in] b									The FalloffDataData to compare with.
	/// @return												@trueIfOtherwiseFalse{the FalloffDataDatas are not equal}
	//----------------------------------------------------------------------------------------
	Bool operator !=(const FalloffDataData& b)
	{
		return !(*this == b);
	}

	Bool SetMg(const Matrix& mg, Bool force = false);

	Matrix _mat;																	///< Falloff matrix.
	Matrix _imat;																	///< Inverse falloff matrix.
	Float	 _falloff = 1.0_f;											///< Falloff.
	Float	 _scale = 1.0_f;												///< Scale.
	Float	 _strength = 1.0_f;											///< Strength.
	Vector _size = Vector(1.0_f);									///< Size.
	Bool	 _invert	= false;											///< Invert.
	Bool	 _clamped = false;											///< Clamped.
	Bool	 _visible = true;												///< Visible.
	Bool	 _useSpline = false;										///< Use spline.
	Matrix _nodemat;															///< The node's matrix.
	Matrix _inverseNodeMat;												///< The node's inverse matrix.
	Vector _offset;																///< Offset.
	Int32	 _axis	= 2;														///< Axis orientation: @enumerateEnum{FALLOFF_SHAPE_AXIS}
	Float	 _slice = 1.0_f;												///< Slice @em 0-@em 360&deg;.
	Float	 _torusRadius = 1.0_f;									///< Torus radius.
	Int32	 _function	= FALLOFF_FUNCTION_SPLINE;	///< Falloff function: @enumerateEnum{FALLOFF_FUNCTION}
	Bool	 _spherical = false;										///< @markDeprecated
	Float	 _radius = 1.0_f;												///< @markDeprecated
	Float	 _inverseRadius	 = 1.0_f;								///< @markDeprecated
	Float	 _inverseFalloff = 1.0_f;								///< Inverse falloff.
	Float	 _animTime = 0.0_f;											///< Animation to to use for the falloff, this includes the effect of the animation speed.
	maxon::GenericDataRef _splineData;						///< Internal spline-related data set up by InitFalloff.
	maxon::GenericDataRef _userData;							///< User data set up by InitFalloff.
};

//----------------------------------------------------------------------------------------
/// A data class for creating falloff plugins.\n
/// Falloffs appear in any falloff description (unless the flag @ref PLUGINFLAG_HIDE is set during registration) and extend the functionality of effectors and anything that uses falloffs.\n
/// Use RegisterFalloffPlugin() to register a falloff plugin.
//----------------------------------------------------------------------------------------
class FalloffData : public BaseData
{
public:
	/// @name Init/Sample/Free
	/// @{

	//----------------------------------------------------------------------------------------
	/// Called to initialize the falloff when it is first created.
	/// @param[in,out] bc							The falloff's container; normally this is the owning object's container.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	virtual Bool Init(BaseContainer* bc);

	//----------------------------------------------------------------------------------------
	/// Called to initialize the falloff just before sampling. Allows to setup any necessary data in falldata or bc.
	/// @param[in,out] bc							The falloff's data.
	/// @param[in,out] falldata				The falloff's container; normally this is the container of the object owning the falloff.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	virtual Bool InitFalloff(const BaseDocument* doc, const BaseContainer* bc, FalloffDataData& falldata) const;

	//----------------------------------------------------------------------------------------
	/// Called to sample any point. Assign res to return the sampled value.
	/// @param[in] p									The position of the point to sample in falloff space.
	/// @param[in] data								The falloff's data.
	/// @param[out] res								Set to the sampled value.
	//----------------------------------------------------------------------------------------
	virtual void Sample(const Vector& p, const FalloffDataData& data, Float* res) const;

	/// @}

	//----------------------------------------------------------------------------------------
	/// Called to check for a change in the falloff.
	/// @param[in] bc									The falloff's container; normally this is the container of the object owning the falloff.
	/// @return												@trueIfOtherwiseFalse{the falloff is dirty}
	//----------------------------------------------------------------------------------------
	virtual Bool CheckDirty(const BaseDocument* doc, const BaseContainer* bc);

	//----------------------------------------------------------------------------------------
	/// Called to check the visibility of any element in the falloff description.
	/// Just return @formatConstant{true} or @formatConstant{false} for the @formatParam{id} (like NodeData::GetDEnabling).
	/// @param[in] id									The description ID.
	/// @param[in,out] bc							The falloff's container; normally this is the container of the object owning the falloff.
	/// @param[in,out] desc_bc				The description element's container.
	/// @return												@trueIfOtherwiseFalse{the description element should be visible}
	//----------------------------------------------------------------------------------------
	virtual Bool GetDVisible(const DescID& id, const BaseContainer* bc, BaseContainer* desc_bc) const;

	/// @name Handle
	/// @{

	//----------------------------------------------------------------------------------------
	/// Called to get the number of handles for the falloff.\n
	/// Same as ObjectData::GetHandleCount with additional FalloffDataData.
	/// @param[in,out] bc							The falloff's container; normally this is the container of the object owning the falloff.
	/// @param[in,out] data						The falloff's data.
	/// @return												The handle count.
	//----------------------------------------------------------------------------------------
	virtual Int32 GetHandleCount(BaseContainer* bc, const FalloffDataData& data);

	//----------------------------------------------------------------------------------------
	/// Called to get a handle for the falloff.\n
	/// Same as ObjectData::GetHandle with additional FalloffDataData.
	/// @param[in,out] bc							The falloff's container; normally this is the container of the object owning the falloff.
	/// @param[in] i									The handle index.
	/// @param[out] info							Filled with the information for handle @formatParam{i}.
	/// @param[in,out] data						The falloff's data.
	//----------------------------------------------------------------------------------------
	virtual void GetHandle(BaseContainer* bc, Int32 i, HandleInfo& info, const FalloffDataData& data);

	//----------------------------------------------------------------------------------------
	/// Called to set a handle for the falloff.\n
	/// Same as ObjectData::SetHandle with additional FalloffDataData.\n
	/// Called when the user has moved handle @formatParam{i} to position @formatParam{p}. Constrain the movement and update the internal data.
	/// @param[in,out] bc							The falloff's container; normally this is the container of the object owning the falloff.
	/// @param[in] i									The handle index.
	/// @param[in] p									The new position for handle @formatParam{i}.
	/// @param[in,out] data						The falloff's data.
	//----------------------------------------------------------------------------------------
	virtual void SetHandle(BaseContainer* bc, Int32 i, Vector p, const FalloffDataData& data);

	/// @}

	//----------------------------------------------------------------------------------------
	/// Called to draw the falloff in the viewport.\n
	/// Same as ObjectData::Draw with additional FalloffDataData.\n
	/// These predefined color constants should be used: @enumerateEnum{FALLOFFCOLORS}
	/// @param[in,out] data						The falloff's data.
	/// @param[in] drawpass						The draw pass: @enumerateEnum{DRAWPASS}
	/// @param[in] bd									The editor's view. @callerOwnsPointed{base draw}
	/// @param[in] bh									The editor's view help. @callerOwnsPointed{base draw help}
	/// @return												The result of drawing into the editor view: @enumerateEnum{DRAWRESULT}
	//----------------------------------------------------------------------------------------
	virtual DRAWRESULT Draw(const FalloffDataData& data, DRAWPASS drawpass, BaseDraw* bd, BaseDrawHelp* bh);

	//----------------------------------------------------------------------------------------
	/// Called to process messages sent to the falloff.
	/// @param[in] type								The message type: @enumerateEnum{MSG}
	/// @param[in,out] bc							The falloff's container; normally this is the container of the object owning the falloff.
	/// @param[in,out] m_data					The message data. @senderOwnsPointed{data}
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	virtual Bool Message(Int32 type, BaseContainer* bc, void* m_data);

	virtual maxon::Result<Bool> GetAccessedObjects(const BaseList2D* op, METHOD_ID method, AccessedObjectsCallback& access) const;
};

//----------------------------------------------------------------------------------------
/// @markprivate
/// Represents a falloff. Allows to sample falloffs.\n
/// It is very simple in use: allocate it, call InitFalloff() first then Sample() giving it a point in world space.
///
/// Many of the methods are there for use within @ref NodeData/@ref ObjectData/@ref ToolData plugins and should be called within their likewise counterparts.\n
/// For instance @link C4D_Falloff::Draw Draw@endlink should be called from within the corresponding @ref NodeData/@ref ObjectData/@ref ToolData Draw override, then the falloff will be drawn in the viewport.
///
/// C4D_Falloff normally needs a container, this is usually the object's container, from this it gets and sets its own parameters for the description (though they can be set directly using the helper functions).
///
/// @note To add a falloff to a description use @link C4D_Falloff::AddFalloffToDescription AddFalloffToDescription@endlink.
//----------------------------------------------------------------------------------------
class C4D_Falloff
{
private:
	C4D_Falloff() { }
	~C4D_Falloff() { }

public:
	using IsAllocType = std::true_type;

	/// @name Alloc/Free
	/// @{

	//----------------------------------------------------------------------------------------
	/// @allocatesA{falloff}
	/// @param[in] parentBc						Container of the parent object where all data is stored
	/// @param[in] cType							(Optional) the type.
	/// @return												@allocReturn{falloff}
	//----------------------------------------------------------------------------------------
	static C4D_Falloff* Alloc(BaseContainer* parentBc, Int cType = 0);

	//----------------------------------------------------------------------------------------
	/// @destructsAlloc{falloffs}
	/// @param[in,out] node						@theToDestruct{falloff}
	//----------------------------------------------------------------------------------------
	static void Free(C4D_Falloff*& node);

	static void Free(const C4D_Falloff*& node)
	{
		return Free(const_cast<C4D_Falloff*&>(node));
	}

	/// @}

	//----------------------------------------------------------------------------------------
	/// Gets the last container the falloff should try to use.\n
	/// @note If the falloff has not been given a container at any point it will generate one
	/// internally.
	/// @warning Can be @formatConstant{nullptr}. If the falloff has been initialized at some point
	/// with a container, but subsequently the original container is no longer available this could be
	/// a bad pointer.
	///
	/// @return												The container instance.
	//----------------------------------------------------------------------------------------
	BaseContainer* GetContainerInstance();

	/// @name Dirty
	/// @{

	//----------------------------------------------------------------------------------------
	/// Sets the falloff dirty.
	//----------------------------------------------------------------------------------------
	void SetDirty();

	//----------------------------------------------------------------------------------------
	/// Gets the falloff dirty value.
	/// @note Useful for checking if the falloff needs to be resampled.
	/// @param[in] doc								The document.
	/// @return												The dirty value.
	//----------------------------------------------------------------------------------------
	Int32 GetDirty(BaseList2D* op, const BaseDocument* doc);

	/// @}

	/// @name Matrix
	/// @{

	//----------------------------------------------------------------------------------------
	/// Sets the falloff's matrix.
	/// @param[in] mg									The new matrix.
	//----------------------------------------------------------------------------------------
	void SetMg(const Matrix& mg);

	//----------------------------------------------------------------------------------------
	/// Gets the falloff's matrix.
	/// @return												The matrix.
	//----------------------------------------------------------------------------------------
	const Matrix& GetMg() const;

	/// @}

	/// @name Mode
	/// @{

	//----------------------------------------------------------------------------------------
	/// Sets the falloff mode.\n
	/// @note The falloff mode is normally the falloff's ID (see @em ofalloff_panel.h).
	/// @param[in] type								The new falloff mode.
	/// @return												@trueIfOtherwiseFalse{the mode was set}
	//----------------------------------------------------------------------------------------
	Bool SetMode(Int32 type);

	//----------------------------------------------------------------------------------------
	/// Gets the falloff mode.\n
	/// @note The fallof's mode is normally the falloff's ID (see @em ofalloff_panel.h).
	/// @return												The falloff's mode.
	//----------------------------------------------------------------------------------------
	Int32 GetMode() const;

	/// @}

	//----------------------------------------------------------------------------------------
	/// Sets the current falloff time.\n
	/// Used for the animated Spline GUI offset, not for any other values currently.
	/// @param[in] time								The new falloff time.
	//----------------------------------------------------------------------------------------
	void SetTime(BaseTime time);

	//----------------------------------------------------------------------------------------
	/// Initializes the falloff.
	/// @warning Always call before the sample routines.
	/// @note It is recommended to fill at least one of the settings, however not compulsory.
	/// @param[in] doc								Optional document used to retrieve the current time for the animation of the Spline GUI offset.
	/// @param[in] op									Optional object used to set the matrix if given, and if no container is given for @formatParam{bc}, its container will be used instead.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool InitFalloff(BaseDocument* doc = nullptr, BaseObject* op = nullptr);

	Bool InitFalloff(const BaseDocument* doc, const BaseObject* op, FalloffDataData& data) const;

	//----------------------------------------------------------------------------------------
	/// Pre-samples an array of points for much faster usage with fields.
	/// Sampling result will be stored internally until the next call to PreSample.
	/// Use GetSamples() to read pre-sampling result.
	/// Only used with fields. If falloff is in legacy mode, PreSample will return true
	/// and do mothing.
	/// Use PreSample to allow calls to Sample within parallel for loops.
	/// @param[in] doc								The document.
	/// @param[in] op									The object.
	/// @param[in] inputs							The point array to sample.
	/// @param[in] flags							The sampling flags.
	/// @return												true if it succeeds, false if it fails.
	//----------------------------------------------------------------------------------------
	Bool PreSample(const BaseList2D* op, const BaseDocument* doc, const FieldInput& inputs, FieldOutput& result, const FalloffDataData& data, FIELDSAMPLE_FLAG flags) const;

	//----------------------------------------------------------------------------------------
	/// Samples the falloff for any point in space.
	/// NOTE: Do not call Sample within a parallel for loop when using fields without PreSample called first.
	/// When using fields:
	///		-If user calls PreSample first, Sample will quickly return the pre-sampled result. This case is thread safe.
	///		-If PreSample was not called, Sample will sample the fields. This case is not thread safe.
	/// When using legacy falloffs:
	///		-Sample supports parallel for loops.
	/// @param[in] p									The point to sample in global space (ignored with pre-sampling).
	/// @param[out] result						Assigned the sampled value.
	/// @param[in] usespline					Use the GUI spline if it exists (default, ignored with pre-sampling).
	/// @param[in] weight							Weight offset. Equivalent of adding this value to the falloff result
	/// 															before clamping (optional, ignored with fields).
	/// @param[in] op									the object (ignored with pre-sampling).
	/// @param[in] index							zero-based index of the sample (when using pre-sampling).
	//----------------------------------------------------------------------------------------
	void Sample(const BaseList2D* op, const Vector& p, Float* result, const FieldOutput* fieldSamples, const FalloffDataData& data, Bool usespline = true, Float weight = 0.0_f, Int index = NOTOK) const;

	//----------------------------------------------------------------------------------------
	/// Samples the falloff for an array of points in space.
	/// The result will be returned in the Float array but also stored internally, overwriting the
	/// last PreSample call result.
	/// @param[in] p									The array of points to sample. @callerOwnsPointed{array}
	/// @param[out] result						Assigned the sampled values.
	/// @param[in] count							The size of array @formatParam{p}.
	/// @param[in] usespline					Use the GUI spline if it exists (default).
	/// @param[in] weight							An optional weight offset. Equivalent of adding this value to the falloff result
	/// 															before clamping.
	/// @param[in] op									(Optional) the object.
	//----------------------------------------------------------------------------------------
	void MultiSample(const BaseList2D* op, const Vector* p, Float* result, Int count, const FalloffDataData& data, Bool usespline = true, Float weight = 0.0_f) const;

	//----------------------------------------------------------------------------------------
	/// Checks to see whether the Falloff has any sampling content.
	/// @return												True if content, false if not.
	//----------------------------------------------------------------------------------------
	Bool HasContent() const;
	/// @}

	//----------------------------------------------------------------------------------------
	/// Adds the falloff to a description.
	/// @note Use this function within the implementation of NodeData::GetDDescription.
	/// @param[in] description				The description to add the falloff GUI to.
	/// @param[in] flags							GetDescription flags.
	/// @param[in] showValue					(Optional) True to show, false to hide the value channel of the FieldList.
	/// @param[in] showColor					(Optional) True to show, false to hide the color channel of the FieldList.
	/// @param[in] showDirection			(Optional) True to show, false to hide the direction channel of the FieldList.
	/// @param[in] showRotation				(Optional) True to show, false to hide the rotation channel of the FieldList.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool AddFalloffToDescription(const BaseList2D* op, Description* description, DESCFLAGS_DESC flags, Bool showValue = true, Bool showColor = false, Bool showDirection = false, Bool showRotation = false) const;

	//----------------------------------------------------------------------------------------
	/// Sends messages to the falloff.
	/// @note Use this function from within the implementation of NodeData::Message to pass all messages on to the falloff, or just send a message with it normally as needed.
	/// @param[in] id									The message type: @enumerateEnum{MSG}
	/// @param[in,out] m_data					The message data. @senderOwnsPointed{data}
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool Message(BaseList2D* op, Int32 id, void* m_data = nullptr);

	/// @name Handle
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets the number of handles for the falloff.
	/// @note Use this function from within the implementation of ObjectData::GetHandleCount.
	/// @return												The handle count.
	//----------------------------------------------------------------------------------------
	Int32 GetHandleCount() const;

	//----------------------------------------------------------------------------------------
	/// Gets a handle for the falloff.
	/// @note Use this function from within the implementation of ObjectData::GetHandle.
	/// @param[in] i									The handle index.
	/// @param[out] info							Filled with the information for handle @formatParam{i}.
	//----------------------------------------------------------------------------------------
	void GetHandle(Int32 i, HandleInfo& info) const;

	//----------------------------------------------------------------------------------------
	/// Called to set a handle for the falloff.
	/// @note Use this function from within the implementation of ObjectData::SetHandle.
	/// @param[in] i									The handle index.
	/// @param[in] p									The new position for handle @formatParam{i}.
	/// @param[out] info							The information for handle @formatParam{i}.
	//----------------------------------------------------------------------------------------
	void SetHandle(Int32 i, Vector p, const HandleInfo& info);

	/// @}

	//----------------------------------------------------------------------------------------
	/// Draws the falloff in the viewport.
	/// @note Use this function from within the implementation of ObjectData::Draw or ToolData::Draw.
	/// @param[in] bd									The editor's view. @callerOwnsPointed{base draw}
	/// @param[in] bh									The editor's view help. @callerOwnsPointed{base draw help}
	/// @param[in] drawpass						The draw pass: @enumerateEnum{DRAWPASS}
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool Draw(BaseList2D* op, BaseDraw* bd, BaseDrawHelp* bh, DRAWPASS drawpass);

	//----------------------------------------------------------------------------------------
	/// Copies the falloff.
	/// @note Use this function from within the implementation of NodeData::CopyTo; necessary for handles to work correctly with the undo system in @C4D.
	/// @param[out] dest							The destination falloff.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool CopyTo(C4D_Falloff* dest, BaseList2D* destPtr) const;

	//----------------------------------------------------------------------------------------
	/// Disables falloff parameters when falloff type is infinite.
	/// @since R19.SP2
	/// @note Use this function within the implementation of NodeData::GetDEnabling():
	/// @code
	/// Bool MyNodeDataObject::GetDEnabling(const GeListNode *node, const DescID &id, const GeData &t_data, DESCFLAGS_ENABLE flags, const BaseContainer *itemdesc) const
	/// {
	///   if (!node)
	///     return true;
	///
	///   if (_fallOff) // _fallOff is C4D_Falloff* type
	///   {
	///     BaseObject* op = (BaseObject*)node;
	///     if (op)
	///     {
	///       const BaseContainer& bc = op->GetDataInstanceRef();
	///       Bool enabled = true;
	///       Bool handled = m_pFallOff->GetDEnabling(id, bc, enabled);
	///       if (handled)
	///         return enabled;
	///     }
	///   }
	///
	///   return SUPER::GetDEnabling(node, id, t_data, flags, itemdesc);
	/// }
	/// @endcode
	/// @param[in] id									The parameter id.
	/// @param[out] enabled						The parameter enabled state.
	/// @return												@trueIfOtherwiseFalse{handled}
	//----------------------------------------------------------------------------------------
	Bool GetDEnabling(const DescID& id, Bool& enabled) const;

	//----------------------------------------------------------------------------------------
	/// Checks whether the Falloff is using fields or not.
	/// @return												@true if the falloff is using fields rather than old falloffs}
	//----------------------------------------------------------------------------------------
	Bool IsFields() const;

	//----------------------------------------------------------------------------------------
	/// When working with Fields this retrieves the current display channel flags for the FieldList
	/// @return												The channel flags.
	//----------------------------------------------------------------------------------------
	FIELDLIST_FLAGS GetChannelFlags() const;

	//----------------------------------------------------------------------------------------
	/// When working with Fields this sets the channel flags that control how the FieldLIst will display.
	/// @param[in] flags							The flags to set.
	//----------------------------------------------------------------------------------------
	void SetChannelFlags(FIELDLIST_FLAGS flags);

	maxon::Result<Bool> GetAccessedObjects(const BaseList2D* op, METHOD_ID method, AccessedObjectsCallback& access) const;
};

struct FALLOFFPLUGIN;

/// FalloffData allocator.
typedef FalloffData* FalloffDataAllocator ();

/// @markPrivate
void FillFalloffPlugin(FALLOFFPLUGIN* fp, Int32 info, FalloffDataAllocator* g);

//----------------------------------------------------------------------------------------
/// Registers a falloff plugin.
/// @param[in] id									@uniquePluginID.
/// @param[in] str								The name of the plugin.
/// @param[in] info								The falloff plugin info flags: @enumerateEnum{PLUGINFLAG}
/// @param[in] g									The allocator for the falloff plugin. This is a pointer to a function that
/// 															creates a new instance of FalloffData with NewObj().
/// @param[in] description				The name of the description resource file to use for the falloff plugin without
/// 															<i>.res</i> extension, for example @em "ofalloff_falloffname".\n The name has to be
/// 															unique, i.e. @em "ofalloff_falloffname" cannot be used for 2 different
/// 															descriptions. See Description Resource for more information.
/// @return												@trueIfOtherwiseFalse{the falloff plugin was registered}
//----------------------------------------------------------------------------------------
Bool RegisterFalloffPlugin(Int32 id, const maxon::String& str, Int32 info, FalloffDataAllocator* g, const maxon::String& description);

//----------------------------------------------------------------------------------------
/// Allocates a falloff.
/// @param[in] type								The falloff type.
/// @return												@allocReturn{falloff}
//----------------------------------------------------------------------------------------
void* AllocFalloff(Int32 type);

#ifdef CINEWARE_NAMESPACE_ENABLE
	CINEWARE_NAMESPACE_END
#endif

#endif // C4D_FALLOFFDATA_H__
