/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef CUSTOMGUI_KERNING_H__
#define CUSTOMGUI_KERNING_H__

#include "customgui_base.h"
#include "c4d_customguidata.h"
#include "c4d_basecontainer.h"
#include "c4d_customdatatype.h"
#include "c4d_objectdata.h"
#include "maxon/basearray.h"

#ifdef __API_INTERN__
#include "hyperfile.h"
#include "baseobject.h"
#else
#include "c4d_baseobject.h"
#include "c4d_file.h"
#endif

/// Plugin ID for the KerningData type.
#define CUSTOMDATATYPE_KERNING							1028639

/// Plugin ID for the KerningCustomGui.
#define CUSTOMGUI_KERNING										1028640

#define TEXTSPLINE_RESULTS									1029376			///< Container ID for the text spline generation results.
#define MSG_DESCRIPTION_KERNINGDATACHANGED	1029460			///< ID for the message that sends changed KerningData to an object after a handle has been moved.
#define MSG_KERNING_GETGUIHELPER						1029466			///< ID for the message that fetches the KerningVpGuiHelper pointer of an object.

/// @addtogroup TEXTSPLINE_RESULT
/// @ingroup group_enumeration
/// @{
/// %Kerning result container set IDs.
#define TEXTSPLINE_RESULT_X						'trsx'			///< ::Float The X coordinate of a character's left border (including kerning, tracking, et cetera).
#define TEXTSPLINE_RESULT_Y						'trsy'			///< ::Float The Y coordinate of a character's bottom border (including baseline shift).
#define TEXTSPLINE_RESULT_Y_BASE			'trby'			///< ::Float The Y coordinate of a character's line's bottom border (no baseline shift).
#define TEXTSPLINE_RESULT_HEIGHT_BASE	'trbh'			///< ::Float The basic height of a character's line (no scale, no baseline shift).
#define TEXTSPLINE_RESULT_WIDTH				'trsw'			///< ::Float The actual width of a character.
#define TEXTSPLINE_RESULT_HEIGHT			'trsh'			///< ::Float The actual height of a character (including scale).
/// @}

//----------------------------------------------------------------------------------------
/// Holds the kerning parameters for one character in a string.
//----------------------------------------------------------------------------------------
struct Kerning
{
	Float _kerning;					///< Moves the character along its X axis, to create (or remove) space before the character.
	Float _tracking;				///< Like @ref _kerning, but for a group of characters.
	Float _scale;						///< Scales the character.
	Float _scaleH;					///< Scales the character along its X axis.
	Float _scaleV;					///< Scales the character along its Y axis.
	Float _baselineShift;		///< Moves the character along its Y axis.
	Float _leading;					///< Not used currently.

	//----------------------------------------------------------------------------------------
	/// Default constructor.
	//----------------------------------------------------------------------------------------
	Kerning() :
		_kerning(0.0),
		_tracking(0.0),
		_scale(1.0),
		_scaleH(1.0),
		_scaleV(1.0),
		_baselineShift(0.0),
		_leading(0.0)
	{ }

	//----------------------------------------------------------------------------------------
	/// Copy constructor.
	/// @param[in] source							The Kerning object to copy members from.
	//----------------------------------------------------------------------------------------
	Kerning(const Kerning& source) :
		_kerning(source._kerning),
		_tracking(source._tracking),
		_scale(source._scale),
		_scaleH(source._scaleH),
		_scaleV(source._scaleV),
		_baselineShift(source._baselineShift),
		_leading(source._leading)
	{ }

	//----------------------------------------------------------------------------------------
	/// Constructor with parameters.
	/// @param[in] kerning						Assigned to @ref _kerning.
	/// @param[in] tracking						Assigned to @ref _tracking.
	/// @param[in] scale							Assigned to @ref _scale.
	/// @param[in] scaleH							Assigned to @ref _scaleH.
	/// @param[in] scaleV							Assigned to @ref _scaleV.
	/// @param[in] baselineShift			Assigned to @ref _baselineShift.
	/// @param[in] leading						Assigned to @ref _leading.
	//----------------------------------------------------------------------------------------
	Kerning(Float kerning, Float tracking, Float scale, Float scaleH, Float scaleV, Float baselineShift, Float leading) :
		_kerning(kerning),
		_tracking(tracking),
		_scale(scale),
		_scaleH(scaleH),
		_scaleV(scaleV),
		_baselineShift(baselineShift),
		_leading(leading)
	{ }

	//----------------------------------------------------------------------------------------
	/// Equality operator.
	/// @return												@trueIfOtherwiseFalse{equal}
	//----------------------------------------------------------------------------------------
	friend Bool operator == (const Kerning &k1, const Kerning &k2)
	{
		return	((k1._kerning == k2._kerning) &&
						(k1._tracking == k2._tracking) &&
						(k1._scale == k2._scale) &&
						(k1._scaleH == k2._scaleH) &&
						(k1._scaleV == k2._scaleV) &&
						(k1._baselineShift == k2._baselineShift) &&
						(k1._leading == k2._leading));
	}

	//----------------------------------------------------------------------------------------
	/// Inequality operator.
	/// @return												@trueIfOtherwiseFalse{not equal}
	//----------------------------------------------------------------------------------------
	friend Bool operator != (const Kerning &k1, const Kerning &k2)
	{
		return	((k1._kerning != k2._kerning) ||
						(k1._tracking != k2._tracking) ||
						(k1._scale != k2._scale) ||
						(k1._scaleH != k2._scaleH) ||
						(k1._scaleV != k2._scaleV) ||
						(k1._baselineShift != k2._baselineShift) ||
						(k1._leading != k2._leading));
	}

	//----------------------------------------------------------------------------------------
	/// Combines two Kerning objects.
	/// @note Offsets are added, scales are taken from second Kerning object.
	/// @param[in] k1									The first Kerning object.
	/// @param[in] k2									The second Kerning object.
	/// @return												The resulting Kerning object.
	//----------------------------------------------------------------------------------------
	friend Kerning Combine(const Kerning &k1, const Kerning &k2)
	{
		return Kerning(	k1._kerning + k2._kerning,
										k1._tracking + k2._tracking,
										k2._scale,
										k2._scaleH,
										k2._scaleV,
										k1._baselineShift + k2._baselineShift,
										k1._leading + k2._leading);
	}

	//----------------------------------------------------------------------------------------
	/// Reads the Kerning object from a HyperFile.
	/// @param[in] hf									The HyperFile to read from. @callerOwnsPointed{HyperFile}
	/// @param[in] level							The file level.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool ReadHF(HyperFile* hf, Int32 level);

	//----------------------------------------------------------------------------------------
	/// Writes the Kerning object to a HyperFile.
	/// @param[in] hf									The HyperFile to write to. @callerOwnsPointed{HyperFile}
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool WriteHF(HyperFile* hf) const;

	//----------------------------------------------------------------------------------------
	/// Computes a vector that combines kerning, tracking, baseline shift and leading.
	/// @return												The offset vector.
	//----------------------------------------------------------------------------------------
	Vector GetOffsetVector() const;

	//----------------------------------------------------------------------------------------
	/// Computes a vector that combines scale, horizontal scale and vertical scale.
	/// @return												The scale vector.
	//----------------------------------------------------------------------------------------
	Vector GetScaleVector() const;

	//----------------------------------------------------------------------------------------
	/// Converts the Kerning value to a readable string.
	/// @return												The string.
	//----------------------------------------------------------------------------------------
	String ToString() const;
};


//----------------------------------------------------------------------------------------
/// TriState helper for class Kerning.
//----------------------------------------------------------------------------------------
struct KerningTriState
{
	TriState<Float>		_kerning;						///< TriState for %Kerning.
	TriState<Float>		_tracking;					///< TriState for Tracking.
	TriState<Float>		_scale;							///< TriState for Scale.
	TriState<Float>		_scaleH;						///< TriState for Horizontal Scale.
	TriState<Float>		_scaleV;						///< TriState for Vertical Scale.
	TriState<Float>		_baselineShift;			///< TriState for Baseline Shift.
	TriState<Float>		_leading;						///< TriState for Leading.

	//----------------------------------------------------------------------------------------
	/// Default constructor
	//----------------------------------------------------------------------------------------
	KerningTriState()
	{ }

	//----------------------------------------------------------------------------------------
	/// Copy constructor.
	/// @param[in] k									The KerningTriState object to copy members from.
	//----------------------------------------------------------------------------------------
	explicit KerningTriState(const Kerning& k) :
		_kerning(TriState<Float>(k._kerning)),
		_tracking(TriState<Float>(k._tracking)),
		_scale(TriState<Float>(k._scale)),
		_scaleH(TriState<Float>(k._scaleH)),
		_scaleV(TriState<Float>(k._scaleV)),
		_baselineShift(TriState<Float>(k._baselineShift)),
		_leading(TriState<Float>(k._leading))
	{ }

	//----------------------------------------------------------------------------------------
	/// Adds a Kerning object to the TriState.
	/// @param[in] k									The Kerning object to add.
	//----------------------------------------------------------------------------------------
	void Add(const Kerning& k)
	{
		_kerning.Add(k._kerning);
		_tracking.Add(k._tracking);
		_scale.Add(k._scale);
		_scaleH.Add(k._scaleH);
		_scaleV.Add(k._scaleV);
		_baselineShift.Add(k._baselineShift);
		_leading.Add(k._leading);
	}

	//----------------------------------------------------------------------------------------
	/// Retrieves the TriState's value.
	/// @return												The TriState's value.
	//----------------------------------------------------------------------------------------
	Kerning GetValue() const
	{
		return Kerning(_kerning.GetValue(),
			_tracking.GetValue(),
			_scale.GetValue(),
			_scaleH.GetValue(),
			_scaleV.GetValue(),
			_baselineShift.GetValue(),
			_leading.GetValue());
	}

	//----------------------------------------------------------------------------------------
	/// Retrieves the TriState status.
	/// @return												@trueIfOtherwiseFalse{the TriState is ambiguous}
	//----------------------------------------------------------------------------------------
	Bool GetTri() const
	{
		return	_kerning.GetTri() ||
						_tracking.GetTri() ||
						_scale.GetTri() ||
						_scaleH.GetTri() ||
						_scaleV.GetTri() ||
						_baselineShift.GetTri() ||
						_leading.GetTri();
	}
};


//----------------------------------------------------------------------------------------
/// The CustomDataType that contains an array of Kerning objects.
/// @addAllocFreeAutoAllocNote
//----------------------------------------------------------------------------------------
class KerningData : public CustomDataType
{
public:

	/// @name Alloc/Free
	/// @{

	//----------------------------------------------------------------------------------------
	/// @allocatesA{KerningData object}
	/// @return												@allocReturn{KerningData object}
	//----------------------------------------------------------------------------------------
	static KerningData* Alloc();

	//----------------------------------------------------------------------------------------
	/// @destructsAlloc{KerningData objects}
	/// @param[in,out] pData					@theToDestruct{KerningData object}
	//----------------------------------------------------------------------------------------
	static void Free(KerningData *&pData);

	/// @}

	/// @name Constructor/Destructor
	/// @{

	//----------------------------------------------------------------------------------------
	/// Constructor.
	//----------------------------------------------------------------------------------------
	KerningData()
	{ }

	//----------------------------------------------------------------------------------------
	/// Destructor.
	//----------------------------------------------------------------------------------------
	~KerningData()
	{ }

	/// @}

	/// @name Kerning
	/// @{

	//----------------------------------------------------------------------------------------
	/// Retrieves the Kerning object with the settings at @formatParam{index}.
	/// @param[in] index							The index of the Kerning object.
	/// @return												The Kerning object for @formatParam{index}.
	//----------------------------------------------------------------------------------------
	Kerning GetKerning(Int32 index) const;

	//----------------------------------------------------------------------------------------
	/// Calculates the actual Kerning for @formatParam{index}.
	/// @note All offsets and scale of the previous array elements will be taken into account.
	/// @param[in] index							The index of the Kerning object.
	/// @param[in] s									Pass a string to consider line breaks.
	/// @return												The Kerning object for @formatParam{index}.
	//----------------------------------------------------------------------------------------
	Kerning CalculateKerning(Int32 index, const maxon::String& s) const;

	//----------------------------------------------------------------------------------------
	/// Sets the Kerning data for @formatParam{index}.
	/// @param[in] index							The index of the Kerning object.
	/// @param[in] kerning						The Kerning data to set.
	/// @param[in] combine						If @formatConstant{false}, existing Kerning data will be overwritten with new one. If @formatConstant{true}, both will be combined.
	/// @return												True if successful.
	//----------------------------------------------------------------------------------------
	Bool SetKerning(Int32 index, const Kerning& kerning, Bool combine = false);

	//----------------------------------------------------------------------------------------
	/// Sets Kerning values for a range of indices.
	/// @param[in] index_start				The range start index.
	/// @param[in] index_end					The range end index.
	/// @param[in] kerning						The Kerning data to set.
	/// @param[in] combine						If @formatConstant{false}, existing Kerning datasets will be overwritten with new one. If @formatConstant{true}, they will be combined.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool SetKerning(Int32 index_start, Int32 index_end, const Kerning& kerning, Bool combine = false);

	//----------------------------------------------------------------------------------------
	/// Sets KerningTriState values for a range of indices.
	/// @param[in] index_start				The range start index.
	/// @param[in] index_end					The range end index.
	/// @param[in] tristate						The Kerning TriState.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool SetKerning(Int32 index_start, Int32 index_end, const KerningTriState& tristate);

	//----------------------------------------------------------------------------------------
	/// Resets Kerning data for @formatParam{index} to default values.
	/// @param[in] index							The index of the Kerning data to reset.
	//----------------------------------------------------------------------------------------
	void ResetKerning(Int32 index);

	//----------------------------------------------------------------------------------------
	/// Resets all Kerning data objects in array to default values (count is preserved).
	//----------------------------------------------------------------------------------------
	void ResetKerning();

	/// @}

	/// @name Array
	/// @{

	//----------------------------------------------------------------------------------------
	/// Initializes Kerning data array with length of string @formatParam{s}.
	/// @param[in] s									The length of the Kerning data array will be set to length of @formatParam{s}.
	/// @param[in] preserve						@formatConstant{true} to keep existing Kerning data. @formatConstant{false} for default values in all elements.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool Init(const maxon::String& s, Bool preserve);

	//----------------------------------------------------------------------------------------
	/// Initializes Kerning data array with length @formatParam{count}.
	/// @param[in] count							The length of the Kerning data array.
	/// @param[in] preserve						@formatConstant{true} to keep existing Kerning data. @formatConstant{false} for default values in all elements.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool Init(Int32 count, Bool preserve = false);

	//----------------------------------------------------------------------------------------
	/// Gets the length of Kerning data array.
	/// @return												The Kerning data array's length.
	//----------------------------------------------------------------------------------------
	Int32 GetCount() const;

	//----------------------------------------------------------------------------------------
	/// Clears all Kerning data. Length is reset to @em 0.
	//----------------------------------------------------------------------------------------
	void Clear();

	/// @}

	/// @name CopyTo
	/// @{

	//----------------------------------------------------------------------------------------
	/// Copies the KerningData object to another one.
	/// @param[in] pDest							The pointer to the destination KerningData object.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool CopyTo(KerningData* pDest) const;

	/// @}

	/// @name String
	/// @{

	//----------------------------------------------------------------------------------------
	/// Retrieves the string that the KerningData has been initialized with.
	/// @return												The string.
	//----------------------------------------------------------------------------------------
	String GetString() const;

	/// @}

	/// @name Selection
	/// @{

	//----------------------------------------------------------------------------------------
	/// Sets the index of the selection start.
	/// @param[in] start							The index of the selection start: @em 0 <= @formatParam{start} < @c GetString().GetLength()
	//----------------------------------------------------------------------------------------
	void SetSelectionStart(Int32 start);

	//----------------------------------------------------------------------------------------
	/// Gets the index of the selection start.
	/// @return												The index of the selection start.
	//----------------------------------------------------------------------------------------
	Int32 GetSelectionStart() const;

	//----------------------------------------------------------------------------------------
	/// Sets the index of the selection end.
	/// @param[in] end								The index of the selection end: @em 0 <= @formatParam{end} < @c GetString().GetLength()
	//----------------------------------------------------------------------------------------
	void SetSelectionEnd(Int32 end);

	//----------------------------------------------------------------------------------------
	/// Gets the index of the selection end.
	/// @return												The index of the selection end.
	//----------------------------------------------------------------------------------------
	Int32 GetSelectionEnd() const;

	//----------------------------------------------------------------------------------------
	/// Sets the indexes of the selection start and end.
	/// @param[in] start							The index of the selection start.
	/// @param[in] end								The index of the selection end.
	//----------------------------------------------------------------------------------------
	void SetSelection(Int32 start, Int32 end);

	//----------------------------------------------------------------------------------------
	/// Gets the length of the selection (GetSelectionEnd() - GetSelectionStart()).
	/// @return												The selection's length.
	//----------------------------------------------------------------------------------------
	Int32 GetSelectionLength() const;

	/// @}

	/// @name Edit Mode
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets the edit mode state.
	/// @return												@trueIfOtherwiseFalse{edit mode is enabled}
	//----------------------------------------------------------------------------------------
	Bool GetEditmode() const;

	//----------------------------------------------------------------------------------------
	/// Sets the edit mode state.
	/// @param[in] editmode						@trueOtherwiseFalse{to enable edit mode}
	//----------------------------------------------------------------------------------------
	void SetEditmode(Bool editmode);

	/// @}
};


//----------------------------------------------------------------------------------------
/// The custom GUI to display and edit Kerning data.
//----------------------------------------------------------------------------------------
class KerningCustomGui : public BaseCustomGui<CUSTOMGUI_KERNING>
{
	//----------------------------------------------------------------------------------------
	/// Constructor.
	//----------------------------------------------------------------------------------------
	KerningCustomGui();

	//----------------------------------------------------------------------------------------
	/// Destructor.
	//----------------------------------------------------------------------------------------
	~KerningCustomGui();
};


//----------------------------------------------------------------------------------------
/// A helper class that does all the drawing and handle management.
/// @addAllocFreeAutoAllocNote
//----------------------------------------------------------------------------------------
class KerningVpGuiHelper
{
public:

	/// @name Alloc/Free
	/// @{

	//----------------------------------------------------------------------------------------
	/// @allocatesA{KerningVpGuiHelper object}
	/// @return												@allocReturn{KerningVpGuiHelper object}
	//----------------------------------------------------------------------------------------
	static KerningVpGuiHelper* Alloc();

	//----------------------------------------------------------------------------------------
	/// @destructsAlloc{KerningVpGuiHelper objects}
	/// @param[in,out] pData					@theToDestruct{KerningVpGuiHelper objects}
	//----------------------------------------------------------------------------------------
	static void Free(KerningVpGuiHelper*& pData);

	/// @}

	/// @name Constructor/Destructor
	/// @{

	//----------------------------------------------------------------------------------------
	/// Constructor.
	//----------------------------------------------------------------------------------------
	KerningVpGuiHelper();

	//----------------------------------------------------------------------------------------
	/// Destructor.
	//----------------------------------------------------------------------------------------
	~KerningVpGuiHelper();

	/// @}

	/// @name Init
	/// @{

	//----------------------------------------------------------------------------------------
	/// Initializes the KerningVpGuiHelper.
	/// @note Must be called after each successful generation of a text spline, and before calling Draw(), GetHandleCount(), GetHandle(), SetHandle().
	/// @param[in] s									The string that the text spline was generated from.
	/// @param[in] generationresults	A pointer to the BaseContainer with generation results (get the container with @c GetContainer(TEXTSPLINE_RESULTS) from the text spline's container).
	/// @param[in] kd									A pointer to the KerningData that was used for text spline generation.
	/// @param[in] plane							Indicates the spline generation plane. Value from @ref PRIM_PLANE can be used.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool Init(const maxon::String& s, BaseContainer* generationresults, KerningData* kd, Int32 plane);

	/// @}

	/// @name Draw
	/// @{

	//----------------------------------------------------------------------------------------
	/// Draws the complete %Kerning Viewport GUI into the current @em drawpass.
	/// @note	Drawing is automatically skipped if the KerningData's edit mode is inactive.\n
	///				Call this from an ObjectData's @link ObjectData::Draw Draw()@endlink function.
	/// @warning Init() must be called before calling this function.
	/// @param[in] op									Pass @c op from an ObjectData::Draw.
	/// @param[in] bd									Pass @c bd from an ObjectData::Draw.
	/// @param[in] bh									Pass @c bh from an ObjectData::Draw.
	/// @return												The draw result. It is possible to return this in an ObjectData's @link ObjectData::Draw Draw()@endlink function.
	//----------------------------------------------------------------------------------------
	DRAWRESULT Draw(BaseObject *op, BaseDraw *bd, BaseDrawHelp *bh);

	/// @}

	/// @name Handle
	/// @{

	//----------------------------------------------------------------------------------------
	/// Manages the %Kerning handles.
	/// @note Call this from an ObjectData's @link ObjectData::DetectHandle DetectHandle()@endlink function.
	/// @warning Init() must be called before calling this function.
	/// @param[in] op									Pass @c op from an ObjectData::DetectHandle.
	/// @param[in] bd									Pass @c bd from an ObjectData::DetectHandle.
	/// @param[in] x									Pass @c x from an ObjectData::DetectHandle.
	/// @param[in] y									Pass @c y from an ObjectData::DetectHandle.
	/// @param[in] qualifier					Pass @c qualifier from an ObjectData::DetectHandle.
	/// @return												The handle ID. Return this in an ObjectData's @link ObjectData::DetectHandle DetectHandle()@endlink function.
	//----------------------------------------------------------------------------------------
	Int32 DetectHandle(BaseObject *op, BaseDraw *bd, Int32 x, Int32 y, QUALIFIER qualifier);

	//----------------------------------------------------------------------------------------
	/// Manages the %Kerning handles.
	/// @note Call this from an ObjectData's @link ObjectData::MoveHandle MoveHandle()@endlink function.
	/// @warning Init() must be called before calling this function.
	/// @param[in] op									Pass @c op from an ObjectData::MoveHandle.
	/// @param[in] undo								Pass @c undo from an ObjectData::MoveHandle.
	/// @param[in] mouse_pos					Pass @c mouse_pos from an ObjectData::MoveHandle.
	/// @param[in] hit_id							Pass @c hit_id from an ObjectData::MoveHandle.
	/// @param[in] qualifier					Pass @c qualifier from anObjectData::MoveHandle.
	/// @param[in] bd									Pass @c bd from an ObjectData::MoveHandle.
	/// @return												@trueIfOtherwiseFalse{the handle was moved} Return this in an ObjectData's @link ObjectData::MoveHandle MoveHandle()@endlink function.
	//----------------------------------------------------------------------------------------
	Bool MoveHandle(BaseObject *op, BaseObject *undo, const Vector &mouse_pos, Int32 hit_id, QUALIFIER qualifier, BaseDraw *bd);

	//----------------------------------------------------------------------------------------
	/// Manages the %Kerning handles.
	/// @note Call this from an ObjectData's @link ObjectData::GetHandle GetHandle()@endlink function.
	/// @warning Init() must be called before calling this function.
	/// @param[in] op									Pass @c op from an ObjectData::GetHandle.
	/// @param[in] i									Pass @c i from an ObjectData::GetHandle.
	/// @param[in] info								Pass @c info from an ObjectData::GetHandle.
	//----------------------------------------------------------------------------------------
	void GetHandle(BaseObject *op, Int32 i, HandleInfo &info);

	/// @}

	/// @name Miscellaneous
	/// @{

	//----------------------------------------------------------------------------------------
	/// Copies all data of the class to another KerningVpGuiHelper object.
	/// @param[in] dest								A pointer to the destination KerningVpGuiHelper object. Must not be @formatConstant{nullptr}. @callerOwnsPointed{KerningVpGuiHelper}
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool CopyTo(KerningVpGuiHelper* dest);

	//----------------------------------------------------------------------------------------
	/// Used internally by HandleKerningMessages() to handle drag-less clicks on handles.
	/// @param[in] release						@formatConstant{false} on MouseDown, @formatConstant{true} on MouseUp.
	/// @param[in] op									The BaseObject from which the HandleKerningMessages() call originated. @callerOwnsPointed{object}
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool ClickHandle(Bool release, BaseObject* op);

	//----------------------------------------------------------------------------------------
	/// Sets all sizes but @ref TEXTSPLINE_RESULT_HEIGHT_BASE to zero. Specially useful when scaling down kerning by handlers to zero until text spline is so small that text spline generator returns a null spline. @see TEXTSPLINE_RESULT
	//----------------------------------------------------------------------------------------
	void SetZeroSize();

	/// @}
};

//----------------------------------------------------------------------------------------
/// Message data struct for @ref MSG_KERNING_GETGUIHELPER.\n
/// Used internally by HandleKerningMessages() to retrieve the pointer to the KerningVpGuiHelper object of a NodeData.
//----------------------------------------------------------------------------------------
struct KerningGetGuiHelperMsg
{
	KerningVpGuiHelper* _ptr;			///< The pointer

	//----------------------------------------------------------------------------------------
	/// Default constructor.
	//----------------------------------------------------------------------------------------
	KerningGetGuiHelperMsg() : _ptr(nullptr)
	{}

	//----------------------------------------------------------------------------------------
	/// Copy constructor.
	/// @param[in] src								The KerningGetGuiHelperMsg to copy member from.
	//----------------------------------------------------------------------------------------
	KerningGetGuiHelperMsg(const KerningGetGuiHelperMsg& src) : _ptr(src._ptr)
	{}
};


//----------------------------------------------------------------------------------------
/// Blends the values of two Kerning objects, using simple linear interpolation.
/// @param[in] k1									The first Kerning object.
/// @param[in] k2									The second Kerning object.
/// @param[in] mix								The blend weight: @em 0.0 <= @formatParam{mix} <= @em 1.0.
/// @return												A Kerning object with the blended values.
//----------------------------------------------------------------------------------------
Kerning BlendKerning(const Kerning& k1, const Kerning& k2, Float mix);

//----------------------------------------------------------------------------------------
/// Takes care of all the messages that are important for the kerning viewport GUI to work.
/// @note Simply call this from within a NodeData's @link NodeData::Message Message@endlink function.
/// @param[in] node								Pass @c node from a NodeData::Message.
/// @param[in] msgId							Pass @c msgId from a NodeData::Message.
/// @param[in] kerningDescID			Pass @c descID from a NodeData::Message.
/// @param[in] textDescID					The description ID of the text's string.
/// @param[in] msgData						Pass @c msgData from a NodeData::Message.
/// @param[in] guihelper					Pass the pointer to an allocated instance of a NodeData's KerningVpGuiHelper.
/// @return												@trueIfOtherwiseFalse{successful}
//----------------------------------------------------------------------------------------
Bool HandleKerningMessages(GeListNode *node, Int32 msgId, Int32 kerningDescID, Int32 textDescID, void* msgData, KerningVpGuiHelper* guihelper);


/// @cond IGNORE

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

#ifndef _INTERNAL_KERNING_DEF_
	class iKerningGui : public iBaseCustomGui
	{
		iKerningGui(const BaseContainer &settings, CUSTOMGUIPLUGIN *plugin) : iBaseCustomGui(settings, plugin) { }
	};
	class iKerningData
	{
	};
	class iKerningVpGuiHelper
	{
	};
#else
	class iKerningGui;
	class iKerningData;
	class iKerningVpGuiHelper;
#endif

struct KerningLib : public BaseCustomGuiLib
{
	// KerningData member functions
	Bool					(iKerningGui::*GuiGetEditMode)() const;
	void					(iKerningGui::*GuiGetRange)(UInt32& index_start, UInt32& index_end) const;
	void					(iKerningGui::*GuiSetEditMode)(Bool active);
	void					(iKerningGui::*GuiSetRange)(UInt32 index_start, UInt32 index_end);

	KerningData*	(*KerningData_Alloc)();
	void					(*KerningData_Free)(KerningData *&pData);
	Kerning				(iKerningData::*GetKerning)(Int32 index) const;
	Kerning				(iKerningData::*CalculateKerning)(Int32 index, const maxon::String& s) const;
	Bool					(iKerningData::*SetKerning1)(Int32 index, const Kerning& kerning, Bool combine);
	Bool					(iKerningData::*SetKerning2)(Int32 index_start, Int32 index_end, const Kerning& kerning, Bool combine);
	Bool					(iKerningData::*SetKerning3)(Int32 index_start, Int32 index_end, const KerningTriState& tristate);
	void					(iKerningData::*ResetKerning1)(Int32 index);
	void					(iKerningData::*ResetKerning2)();
	Bool					(iKerningData::*Init1)(const maxon::String& s, Bool preserve);
	Bool					(iKerningData::*Init2)(Int32 count, Bool preserve);
	Int32					(iKerningData::*GetCount)() const;
	void					(iKerningData::*Clear)();
	Bool					(iKerningData::*CopyTo)(iKerningData* pDest) const;
	String				(iKerningData::*GetString)()const;
	void					(iKerningData::*SetSelectionStart)(Int32 start);
	Int32					(iKerningData::*GetSelectionStart)() const;
	void					(iKerningData::*SetSelectionEnd)(Int32 start);
	Int32					(iKerningData::*GetSelectionEnd)() const;
	void					(iKerningData::*SetSelection)(Int32 start, Int32 end);
	Int32					(iKerningData::*GetSelectionLength)() const;
	Bool					(iKerningData::*GetEditmode)() const;
	void					(iKerningData::*SetEditmode)(Bool editmode);

	// VpGuiHelper member functions
	KerningVpGuiHelper*	(*VpGuiHelper_Alloc)();
	void					(*VpGuiHelper_Free)(KerningVpGuiHelper*& pData);
	Bool					(iKerningVpGuiHelper::*VpGuiHelper_Init)(const maxon::String& s, BaseContainer* generationresults, KerningData* kd, Int32 plane);
	DRAWRESULT		(iKerningVpGuiHelper::*VpGuiHelper_Draw)(BaseObject *op, BaseDraw *bd, BaseDrawHelp *bh) const;
	Int32					(iKerningVpGuiHelper::*VpGuiHelper_DetectHandle)(BaseObject *op, BaseDraw *bd, Int32 x, Int32 y, QUALIFIER qualifier);
	Bool					(iKerningVpGuiHelper::*VpGuiHelper_MoveHandle)(BaseObject *op, BaseObject *undo, const Vector &mouse_pos, Int32 hit_id, QUALIFIER qualifier, BaseDraw *bd);
	void					(iKerningVpGuiHelper::*VpGuiHelper_GetHandle)(BaseObject *op, Int32 i, HandleInfo &info);
	Bool					(iKerningVpGuiHelper::*VpGuiHelper_CopyTo)(iKerningVpGuiHelper* dest) const;
	Bool					(iKerningVpGuiHelper::*VpGuiHelper_ClickHandle)(Bool release, BaseObject* op);

	// Kerning member functions
	Bool					(*Kerning_ReadHF)(Kerning* k, HyperFile* hf, Int32 level);
	Bool					(*Kerning_WriteHF)(const Kerning* k, HyperFile* hf);

	// Helper functions
	Bool					(*HandleKerningMessages)(GeListNode *node, Int32 msgId, Int32 kerningDescID, Int32 textDescID, void* msgData, KerningVpGuiHelper* guihelper);
	Kerning				(*BlendKerning)(const Kerning& k1, const Kerning& k2, Float mix);

	// VpGuiHelper member function, added since R18 SP3.
	void					(iKerningVpGuiHelper::*VpGuiHelper_SetZeroSize)();

};

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

/// @endcond

#endif // CUSTOMGUI_KERNING_H__
