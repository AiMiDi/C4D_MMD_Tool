/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef CUSTOMGUI_FIELD_H__
#define CUSTOMGUI_FIELD_H__

#include "customgui_base.h"
#include "c4d_fielddata.h"
#include "c4d_customdatatype.h"

#ifdef USE_API_MAXON
	#include "maxon/errorbase.h"
#else
	#include "maxon/basearray.h"
#endif

/// Field custom GUI ID.
#define CUSTOMGUI_FIELDLIST				440000224
#define CUSTOMDATATYPE_FIELDLIST	440000246

/// FieldList custom GUI Description Flags
#define DESC_FIELDLIST_MULTISELECT	1019921			///< @markprivate
#define DESC_FIELDLIST_HIERARCHICAL 1019922			///< @markprivate
#define DESC_FIELDLIST_DRAGTYPE			1019923			///< Accepted drag types for the list (Int32) default value is DRAGTYPE_ATOMARRAY
#define DESC_FIELDLIST_NOCOLOR			440000316		///< Disable the Color channel for the list (Bool)
#define DESC_FIELDLIST_NODIRECTION	440000317		///< Disable the Direction channel for the list (Bool)
#define DESC_FIELDLIST_NOROTATION		440000336		///< Disable the Rotation channel for the list (Bool)
#define DESC_FIELDLIST_NOVALUE			440000318		///< Disable the Value channel for the list (Bool)
#define DESC_FIELDLIST_NOHEADER			440000329		///< Disable the list header (Bool)

static const Int32 ID_FIELDSUBLIST_ICON = 440000349;	///< The generic icon for sublists
static const Int32 ID_FIELDMASK_ICON = 440000348;			///< The icon for the mask sublist

enum class FIELDLIST_FLAGS
{
	NONE											= 0,					///< No flags
	CLAMPOUTPUT								= (1 << 0),		///< Clamp the output values from the FieldList
	ENABLEDIRECTIONBYDEFAULT	= (1 << 4),		///< Have direction enabled by default on new layers
	ENABLECOLORBYDEFAULT			= (1 << 5),		///< Have color enabled by default on new layers
	DISABLEVALUEBYDEFAULT			= (1 << 6),		///< Disable the value channel by default on new layers
	SIMPLEGUI									= (1 << 7),		///< Use a simplified GUI, this is only possible if there is only a single standard fieldlayer in the datatype
	ENABLEROTATIONBYDEFAULT		= (1 << 8)		///< Have direction enabled by default on new layers
} MAXON_ENUM_FLAGS(FIELDLIST_FLAGS);

typedef maxon::Delegate<maxon::Result<void>(FieldInput&, const FieldInfo&)> FieldLambdaInput;
typedef maxon::Delegate<maxon::Result<void>(const FieldInput&, const FieldOutputBlock&, const FieldInfo&)> FieldLambdaOutput;

//----------------------------------------------------------------------------------------
/// Field custom GUI (@ref CUSTOMDATATYPE_FIELDLIST) for the Field list data.
//----------------------------------------------------------------------------------------
class FieldList : public CustomDataType
{
	/// Default constructor.
	FieldList() = default;
	/// Destructor.
	~FieldList() = default;

public:
	/// @name Alloc/Free
	/// @{

	//----------------------------------------------------------------------------------------
	/// @allocatesA{field list data}
	/// @return												@allocReturn{field list data}
	//----------------------------------------------------------------------------------------
	static FieldList* Alloc();

	//----------------------------------------------------------------------------------------
	/// @destructsAlloc{field list data}
	/// @param[in,out] list						@theToDestruct{field list data}
	//----------------------------------------------------------------------------------------
	static void Free(FieldList*& list);

	/// @}

	//----------------------------------------------------------------------------------------
	/// Sample a block of values.
	/// Use this method to avoid to avoid having to pre create FieldInfo and FieldOuput structures.
	/// Sampling will be performed in the caller's document with default FieldInfo parameters.
	/// @param[in] caller							The caller object, simply pass the BaseList2D you are invoking the sampling from.
	/// @param[in] inputs							The inputs to sample from.
	/// @param[in] flags							The channels to sample.
	/// @return												The sampled FieldOutput.
	//----------------------------------------------------------------------------------------
	maxon::Result<FieldOutput> SampleListSimple(BaseList2D& caller, const FieldInput& inputs, FIELDSAMPLE_FLAG flags = FIELDSAMPLE_FLAG::ALL);

	//----------------------------------------------------------------------------------------
	/// Sample a block of values. Allows full parameter control to the user.
	/// You can supply a simple Vector as inputs to sample just one position.
	/// User needs to supply a valid FieldInfo filled with all parameters.
	/// @param[in] info								The sampling informations, document, threading, flags... Should succeed IsPopulated().
	/// @param[in] inputs							The inputs to sample from.
	/// @param[out] outputs						Arrays that hold the sampling results, based on sampling flags.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	maxon::Result<void> SampleList(const FieldInfo& info, const FieldInput& inputs, FieldOutput& outputs);

	//----------------------------------------------------------------------------------------
	/// Sample a block of specified length using the passed lambda's to initialize the FieldInput and apply the final FieldOutputBlock.
	/// @param[in] info								The information required for execution. Should succeed IsPopulated().
	/// @param[in] inputFunc					The input function, fill the passed FieldInput arrays within this function.
	/// @param[in] outputFunc					The output function, make use of the calculated FieldOutputBlock within this function.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	maxon::Result<void> SampleListWithLambda(const FieldInfo& info, const FieldLambdaInput&& inputFunc, const FieldLambdaOutput&& outputFunc);

	//----------------------------------------------------------------------------------------
	/// Direct initialize to be used only with DirectSample function, DirectFree must be called afterwards.
	/// @param[in] info								The pre-filled FieldInfo, caller owns the object.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	maxon::Result<void> DirectInitSampling(const FieldInfo& info);

	//----------------------------------------------------------------------------------------
	/// Direct sample function, DirectInitSampling must be called before and DirectFree afterwards.
	/// @param[in] inputs							The points to sample, caller owns the object.
	/// @param[out] outputs						The output, caller owns the object.
	/// @param[in] info								The pre-filled FieldInfo, caller owns the object.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	maxon::Result<void> DirectSample(const FieldInput& inputs, FieldOutputBlock& outputs, const FieldInfo& info);

	//----------------------------------------------------------------------------------------
	/// Direct free, must be called after DirectInitSampling
	/// @param[in] info								The pre-filled FieldInfo, caller owns the object.
	//----------------------------------------------------------------------------------------
	void DirectFreeSampling(const FieldInfo& info);

	//----------------------------------------------------------------------------------------
	/// Gets the dirtiness of the field GUI and it's objects.
	/// @param[in] doc								The document.
	/// @return												The dirty.
	//----------------------------------------------------------------------------------------
	UInt32 GetDirty(BaseDocument* doc) const;

	//----------------------------------------------------------------------------------------
	/// Retrieves the total number of fields and groups in the list.
	/// @return												The count.
	//----------------------------------------------------------------------------------------
	Int32 GetCount() const;

	//----------------------------------------------------------------------------------------
	/// Empties the list of all entries, frees any used memory and resets the FieldList back to it's
	/// default state.
	//----------------------------------------------------------------------------------------
	void Flush();

	//----------------------------------------------------------------------------------------
	/// Inserts a pre-existing layer into the FieldList.
	/// @param[in] layer							The layer to insert into the .FieldList.  The caller must own this layer and it must
	/// 															not be already inserted in any other FieldList (or in the current fieldList in another
	/// 															location)
	/// @param[in] parent							The layer that will be the parent of the layer being inserted.
	/// @param[in] prev								The previous layer to the one being inserted.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	maxon::Result<void> InsertLayer(FieldLayer* layer, FieldLayer* parent = nullptr, FieldLayer* prev = nullptr);

	//----------------------------------------------------------------------------------------
	/// Retrieves the root GeListHead that owns the layers in the FieldList.
	/// @return												Null if it fails, else the root GeListHead for the FieldList.  THe FieldList owns the passed
	/// 				object.
	//----------------------------------------------------------------------------------------
	GeListHead* GetLayersRoot() const;

	//----------------------------------------------------------------------------------------
	/// Retrieves a list of all the selected layers in the FieldList, this may include the background layer.
	/// @param[out] selected					[out] The selected FieldLayers in the FieldList.
	/// @param[in] includeChildren		(Optional) True to include, false to exclude the children.
	/// @return												A maxon::Result&lt;void&gt;
	//----------------------------------------------------------------------------------------
	maxon::Result<void> GetSelected(maxon::BaseArray<FieldLayer*>& selected, Bool includeChildren = true) const;

	//----------------------------------------------------------------------------------------
	/// Searches for the field Layers that match the passed Reference.
	/// @param[in] link								The FieldLayerLink, this follows the same type of format as Drag &amp;
	/// 															Drop data.
	/// @param[in] doc								The document.
	/// @param[out] found							[out] The list of FieldLayers found by the passed reference.
	/// @return												A maxon::Result&lt;void&gt;
	//----------------------------------------------------------------------------------------
	maxon::Result<void> FindByReference(FieldLayerLink link, BaseDocument* doc, maxon::BaseArray<FieldLayer*>& found) const;

	//----------------------------------------------------------------------------------------
	/// Sets the state of the FIELDLIST_FLAGS for this FieldList
	/// @param[in] flags							The flags to set or clear.
	/// @param[in] state							True to set the flag, false to clear it.
	//----------------------------------------------------------------------------------------
	void SetFlags(FIELDLIST_FLAGS flags, Bool state);

	//----------------------------------------------------------------------------------------
	/// Gets the FIELDLIST_FLAGS for this FieldList
	/// @return												The complete set of flags.
	//----------------------------------------------------------------------------------------
	FIELDLIST_FLAGS GetFlags() const;

	//----------------------------------------------------------------------------------------
	/// Checks a specific flag (or combination) to see if they are set, all flags must be set to return a true
	/// result i.e. this is functionally the equivalent of (GetFlags()&amp;flag) == flag rather than just a check
	/// for any set flag within the passed flag value.
	/// @param[in] flag								The flag(s) to check.
	/// @return												True if the flag is set, false if it has not been set.
	//----------------------------------------------------------------------------------------
	Bool CheckFlag(FIELDLIST_FLAGS flag) const;

	//----------------------------------------------------------------------------------------
	/// Query if the FieldList has content i.e. any FieldLayers in it in order to determine if it's worth evaluation
	/// @param[in] channel						(Optional) The channels to check that content exists for.
	/// @return												True if there are FieldLayers in the FieldList, false if not.
	//----------------------------------------------------------------------------------------
	Bool HasContent(FIELDLAYER_CHANNELFLAG channel = FIELDLAYER_CHANNELFLAG::COLOR | FIELDLAYER_CHANNELFLAG::DIRECTION | FIELDLAYER_CHANNELFLAG::VALUE | FIELDLAYER_CHANNELFLAG::ROTATION) const;
};

class FieldListGui : public BaseCustomGui<CUSTOMGUI_FIELDLIST>
{
private:
	FieldListGui();
	~FieldListGui();

public:
};

/// @cond IGNORE

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

#ifndef INT_CUSTOMDATATYPE_FIELD_H__
class iFieldListDialog : public iBaseCustomGui
{
	iFieldListDialog(const BaseContainer& settings, CUSTOMGUIPLUGIN* plugin) : iBaseCustomGui(settings, plugin) { }
};
class iFieldCustomDatatype
{
};
#else
class iFieldListDialog;
class iFieldCustomDatatype;
#endif

struct CustomGuiFieldLib : public BaseCustomGuiLib
{
	maxon::Result<FieldOutput>(iFieldCustomDatatype::*SampleListSimple		)(BaseList2D& caller, const FieldInput& inputs, FIELDSAMPLE_FLAG flags);
	maxon::Result<void>				(iFieldCustomDatatype::*SampleList					)(const FieldInfo& info, const FieldInput& inputs, FieldOutput& outputs);
	maxon::Result<void>				(iFieldCustomDatatype::*SampleListWithLambda)(const FieldInfo& info, const FieldLambdaInput&& inputFunc, const FieldLambdaOutput&& outputFunc);

	maxon::Result<void>				(iFieldCustomDatatype::*DirectInitSampling	)(const FieldInfo& info);
	maxon::Result<void>				(iFieldCustomDatatype::*DirectSample				)(const FieldInput& inputs, FieldOutputBlock& outputs, const FieldInfo& info);
	void											(iFieldCustomDatatype::*DirectFreeSampling	)(const FieldInfo& info);
	UInt32										(iFieldCustomDatatype::*GetDirty						)(BaseDocument* doc) const;
	Int32											(iFieldCustomDatatype::*GetCount						)() const;
	void											(iFieldCustomDatatype::*Flush								)();
	maxon::Result<void>				(iFieldCustomDatatype::*InsertLayer					)(FieldLayer* layer, FieldLayer* parent, FieldLayer* prev);
	GeListHead*								(iFieldCustomDatatype::*GetLayersRoot				)() const;
	maxon::Result<void>				(iFieldCustomDatatype::*GetSelected					)(maxon::BaseArray<FieldLayer*>& selected, Bool includeChildren) const;
	maxon::Result<void>				(iFieldCustomDatatype::*FindByReference			)(FieldLayerLink link, BaseDocument* doc, maxon::BaseArray<FieldLayer*>& found) const;
	void											(iFieldCustomDatatype::*SetFlags						)(FIELDLIST_FLAGS flags, Bool state);
	FIELDLIST_FLAGS						(iFieldCustomDatatype::*GetFlags						)() const;
	Bool											(iFieldCustomDatatype::*CheckFlag						)(FIELDLIST_FLAGS flag) const;
	Bool											(iFieldCustomDatatype::*HasContent					)(FIELDLAYER_CHANNELFLAG channel) const;

	FieldList*								 (* AllocFieldList)();
	void											 (* FreeFieldList)(FieldList* list);
};

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

/// @endcond

#endif // CUSTOMGUI_FIELD_H__
