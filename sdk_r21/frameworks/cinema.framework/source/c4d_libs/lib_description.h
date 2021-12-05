/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef LIB_DESCRIPTION_H__
#define LIB_DESCRIPTION_H__

#include "c4d_library.h"
#include "c4d_basecontainer.h"

/// @addtogroup group_descriptionlibrary Description
/// @ingroup group_library
/// @{

/// Root description ID.
#define DESCID_ROOT						DescID(DescLevel(1000491, 0, 0))

/// %User data ID.
#define ID_USERDATA						700

/// %User data/dynamic parameters description level.
#define DESCID_DYNAMICSUB			DescLevel(ID_USERDATA, DTYPE_SUBCONTAINER, 0)

/// Page mode for boolean elements. If set it means that this boolean will have no checkbox. (Used for the %Material Editor navigation.)
#define BOOL_PAGEMODE					'bpmd'

/// @markPrivate Restricts the displayed vector to two instead of three components.
#define VECTOR_NO_Z_COMPONENT 'vnZc'

class BaseList2D;
class SubDialog;
class BCResourceObj;
class DescEntry;
class DescriptionCustomGui;
class TakeData;
class BaseTake;
class GeDialog;

struct RESOURCEDATATYPEPLUGIN;

/// @addtogroup DTYPE
/// @ingroup group_enumeration
/// @{
/// Parameter description types.
enum DTYPE
{
	DTYPE_NONE					= 0,					///< None.

	DTYPE_CHILDREN			= 0,					///< Children.
	DTYPE_GROUP					= 1,					///< Group.
	DTYPE_COLOR					= 3,					///< Color.
	DTYPE_SUBCONTAINER  = 5,					///< Sub-container.
	DTYPE_MULTIPLEDATA  = 6,					///< Multiple data entry.
	DTYPE_TEXTURE				= 7,					///< Texture name.
	DTYPE_BUTTON				= 8,					///< Button.
	DTYPE_DYNAMIC				= 10,					///< GV dynamic.
	DTYPE_SEPARATOR			= 11,					///< Separator.
	DTYPE_STATICTEXT		= 12,					///< Static text.
	DTYPE_POPUP					= 13,					///< Popup.

	DTYPE_LONG					= 15,					///< ::Int32
	DTYPE_REAL					= 19,					///< ::Float
	DTYPE_TIME					= 22,					///< BaseTime
	DTYPE_VECTOR				= 23,					///< ::Vector
	DTYPE_MATRIX				= 25,					///< ::Matrix
	DTYPE_STRING				= 130,				///< String
	DTYPE_FILENAME			= 131,				///< Filename
	DTYPE_BASELISTLINK	= 133,				///< BaseLink
	DTYPE_BOOL					= 400006001,	///< GV Bool. ::ID_GV_DATA_TYPE_BOOL
	DTYPE_NORMAL				= 400006005,	///< GV Normal. ::ID_GV_DATA_TYPE_NORMAL
	DTYPE_COLORA				= 400007013,	///< Color with Alpha.
	DTYPE_VECTOR4D			= 1040682,		///< Vector with 4 components.
	DTYPE_VECTOR2D			= 1050090,		///< @markPrivate

	DTYPE_
};
/// @}

/// @addtogroup DESC
/// @ingroup group_containerid
/// @{
/// IDs into the information container for a description parameter.
enum DESC
{
	DESC_NAME						= 1,					///< String Name for standalone use.
	DESC_SHORT_NAME			= 2,					///< String Short name, for attributes dialog.

	DESC_VERSION				= 3,					///< ::Int32 Show in versions:
		DESC_VERSION_DEMO		= (1 << 0),																///< Demo versions.
		DESC_VERSION_XL			= (1 << 1),																///< XL Versions.
		DESC_VERSION_ALL		= DESC_VERSION_DEMO|DESC_VERSION_XL,			///< All versions.
	DESC_CHILDREN				= 4,					///< BaseContainer @markInternal
	DESC_MIN						= 5,					///< ::Int32/::Float/::Vector Minimum value.
	DESC_MAX						= 6,					///< ::Int32/::Float/::Vector Maximum value.
	DESC_MINEX					= 7,					///< ::Bool @formatConstant{true} if @ref DESC_MIN is exclusive, otherwise it is inclusive.
	DESC_MAXEX					= 8,					///< ::Bool @formatConstant{true} if @ref DESC_MAX is exclusive, otherwise it is inclusive.
	DESC_STEP						= 9,					///< ::Int32/::Float/::Vector The step for the edit field arrows.
	DESC_ANIMATE				= 10,					///< ::Int32 Animation mode:
		DESC_ANIMATE_OFF		= 0,				///< Parameter is not animatable.
		DESC_ANIMATE_ON			= 1,				///< Parameter is animatable.
		DESC_ANIMATE_MIX		= 2,				///< Parameter is animatable, but needs to know the left and right data element.\n
																		///< An example is the Target expression that interpolates the Name parameter. If MIX is specified, the expression can at any time call BaseList2D::GetAnimatedParameter() to get the left, right and mix values.
	DESC_ASKOBJECT			= 11,					///< ::Bool @formatConstant{true} means ask object for this parameter, @formatConstant{false} means look in container.
	DESC_UNIT						= 12,					///< ::Int32 Unit for @link DTYPE_REAL@endlink/@link DTYPE_VECTOR@endlink:
		DESC_UNIT_FLOAT			= 'frea',		///< ::FORMAT_FLOAT
		DESC_UNIT_INT			= 'flng',			///< ::FORMAT_INT
		DESC_UNIT_PERCENT		= 'fpct',		///< ::FORMAT_PERCENT
		DESC_UNIT_DEGREE		= 'fdgr',		///< ::FORMAT_DEGREE
		DESC_UNIT_METER			= 'fmet',		///< ::FORMAT_METER
		DESC_UNIT_TIME			= 'ffrm',		///< ::FORMAT_FRAMES
	DESC_PARENTGROUP		= 13,					///< ::Int32/@link DescID@endlink Parent ID.
	DESC_CYCLE					= 14,					///< BaseContainer Contains members of cycle as string. (E.g. @c GetString(10041) == "-X".)
	DESC_HIDE						= 15,					///< ::Bool Indicates whether the property is hidden or not.
	DESC_DEFAULT				= 16,					///< ::Int32/::Float/::Vector Default numeric value.
	DESC_ACCEPT					= 17,					///< BaseContainer Contains the accepted IDs as strings. For C4DAtom::IsInstanceOf() checks. (E.g. @c GetString(5155) == "Obase".)
	DESC_SEPARATORLINE	= 18,					///< ::Bool @formatConstant{true} if separators should have a visible line.
	DESC_REFUSE					= 19,					///< BaseContainer Contains the refused IDs as strings. For C4DAtom::IsInstanceOf() checks. (E.g. @c GetString(5155) == "Obase".)
	DESC_PARENTID				= 20,					///< ::Int32 The ID of the parent element used for indentation and animation track.
	DESC_CUSTOMGUI			= 21,					///< ::Int32 The ID of the GUI for this element. Either a custom ID or one of: @enumerateEnum{CUSTOMGUI}

	DESC_COLUMNS					= 22,					///< ::Int32 Number of columns for layout groups (DTYPE_GROUP).
	DESC_LAYOUTGROUP			= 23,					///< ::Bool @formatConstant{true} for layout groups (LAYOUTGROUP).
	DESC_REMOVEABLE				= 24,					///< ::Bool @formatConstant{true} if entry is removable.
	DESC_GUIOPEN					= 25,					///< ::Bool @formatConstant{true} if the maximized GUI is shown by default.
	DESC_EDITABLE					= 26,					///< ::Bool @formatConstant{true} if entry is editable.
	DESC_MINSLIDER				= 27,					///< ::Int32/::Float/::Vector Minimum value for slider.
	DESC_MAXSLIDER				= 28,					///< ::Int32/::Float/::Vector Maximum value for slider.
	DESC_GROUPSCALEV			= 29,					///< ::Bool Allow the group height to be scaled.
	DESC_SCALEH						= 30,					///< ::Bool Scale element horizontally.
	DESC_LAYOUTVERSION		= 31,					///< ::Int32 Layout version.
	DESC_ALIGNLEFT				= 32,					///< ::Bool Align element left.
	DESC_FITH							= 33,					///< ::Bool Fit element.
	DESC_NEWLINE        	= 34,					///< ::Bool Line break.
	DESC_TITLEBAR					= 35,					///< ::Bool Main group title bar.
	DESC_CYCLEICONS				= 36,					///< BaseContainer Icon IDs for cycle.
	DESC_CYCLESYMBOLS			= 37,					///< BaseContainer String identifiers for help symbol export.
	DESC_PARENT_COLLAPSE	= 38,					///< ::Int32 Parent collapse ID.
	DESC_FORBID_INLINE_FOLDING = 39,		///< ::Bool Instructs the Attribute Manager to not allow expanding inline objects for entry.
	DESC_FORBID_SCALING		= 40,					///< ::Bool Prevents auto-scaling of the parameter with the scale tool (for ::DESC_UNIT_METER).
	DESC_ANGULAR_XYZ			= 41,					///< ::Bool @formatConstant{true} for XYZ as angular representation, or @formatConstant{false} for HPB.

	DESC_INPORT					= 50,						///< ::Bool GV in port.
	DESC_OUTPORT				= 51,						///< ::Bool GV out port.
	DESC_STATICPORT			= 52,						///< ::Bool GV static port.
	DESC_NEEDCONNECTION	= 53,						///< ::Bool GV needs connection.
	DESC_MULTIPLE				= 54,						///< ::Bool GV multiple ports allowed.
	DESC_PORTONLY				= 55,						///< ::Bool GV port only.
	DESC_CREATEPORT			= 56,						///< ::Bool GV create port.
	DESC_PORTSMIN				= 57,						///< ::Int32 GV minimum number of ports.
	DESC_PORTSMAX				= 58,						///< ::Int32 GV maximum number of ports.
	DESC_NOTMOVABLE			= 59,						///< ::Bool GV not movable.
	DESC_EDITPORT				= 60,						///< ::Bool GV editable.
	DESC_ITERATOR				= 61,						///< ::Bool GV iterator port.

	DESC_PARENTMSG			= 62,						///< ::DescID Used in the %Material Editor on the boolean tabs to specify which section to open.
	DESC_MATEDNOTEXT		= 63,						///< ::Bool No text in %Material Editor window.
	DESC_COLUMNSMATED		= 64,						///< ::Int32 Number of columns in left %Material Editor window.
	DESC_SHADERLINKFLAG	= 65,						///< ::Bool Specifies that this element is a shader link. (Only if datatype==::DTYPE_BASELISTLINK.)
	DESC_NOGUISWITCH		= 66,						///< ::Bool Disables GUI switching for this description element.

	DESC_COLORALWAYSLINEAR = 70,				///< :: treat color field always as linear input.
	DESC_HIDE_WHEN_INLINE = 71,					///< ::Bool True to hide this attribute in inline descriptions
	DESC_MATERIALEDITOR_LEFTSIDE = 72,	///< ::Bool True if the property should appear on the left side of the material editor.

	DESC_CHANGED				= 73,						///< ::Bool @formatConstant{true} if entry is changed.
	DESC_HIDEINFIELDS		= 74,						///< ::Bool @formatConstant{true} if group is visible in fields UI.
	DESC_SHOWINFIELDS		= 75,						///< ::Bool @formatConstant{true} if group is shown in fields UI even though group may be hidden
	DESC_FIELDCOLORCHANNEL = 76,				///< ::Bool @formatConstant{true} if the group belongs only to the color channel in the fields list (so will be hidden when the channel is disabled in the UI)
	DESC_FIELDDIRECTIONCHANNEL = 77,		///< ::Bool @formatConstant{true} if the group belongs only to the direction channel in the fields list (so will be hidden when the channel is disabled in the UI)
	DESC_FIELDVALUECHANNEL = 78,				///< ::Bool @formatConstant{true} if the group belongs only to the value channel in the fields list (so will be hidden when the channel is disabled in the UI)
	DESC_FIELDROTATIONCHANNEL = 79,			///< ::Bool @formatConstant{true} if the group belongs only to the rotation channel in the fields list (so will be hidden when the channel is disabled in the UI)

	DESC_NODEPORT = 80,									///< ::Bool True to indicate a nodeport.
	DESC_NODEPORTSTATE = 81,						///< ::Int32 0: not connected, 1: connected, 2: connected but muted, 4: error, 8: warning, 16: limitation.
	DESC_REPLACECOMPLEXUI = 82,					///< ::BaseContainer filled with descids of props to replace.
	DESC_REPLACE_HIDE = 83,							///< ::Bool property hidden because replaced by a complex ui replaces this entry

	DESC_RESOURCEPATH		= 400006007,		///< @markPrivate @since R18
	DESC_RESOURCELINE		= 400006008,		///< @markPrivate @since R18

	DESC_TEMPDESCID			= 998,					///< @markInternal Used internally to store the preferred description ID.
	DESC_IDENT					= 999,					///< String Resource identifier, e.g. @c ID_BASEOBJECT_REL_POSITION.
	DESC_IDENT_ORIGIN		= 997,					///< Origin Resource identifier, e.g. @c ID_BASEOBJECT_REL_POSITION.

	DESC_DISABLELAYOUTSWITCH = 84,			///< Hides the Layout Switch arrow displayed on CUSTOMGUI elements

	DESC_
};
/// @}

/// @addtogroup CUSTOMGUI
/// @ingroup group_enumeration
/// @{
#define CUSTOMGUI_REAL						DTYPE_REAL						///< ::Float edit field.
#define CUSTOMGUI_REALSLIDER			1000489								///< ::Float edit field with slider.
#define CUSTOMGUI_REALSLIDERONLY	200000006							///< ::Float slider only.
#define CUSTOMGUI_VECTOR					DTYPE_VECTOR					///< ::Vector.
#define CUSTOMGUI_VECTOR4D				DTYPE_VECTOR4D				///< ::Vector 4D.
#define CUSTOMGUI_STRING					DTYPE_STRING					///< String field.
#define CUSTOMGUI_STRINGMULTI			200000007							///< Multiple line string field.
#define CUSTOMGUI_STATICTEXT			DTYPE_STATICTEXT			///< Static text field.
#define CUSTOMGUI_CYCLE						200000180							///< Selection list field.
#define CUSTOMGUI_CYCLEBUTTON			200000255							///< Selection field list with button functionality, e.g. the function of a button can be changed through a selection field list.
#define CUSTOMGUI_LONG						DTYPE_LONG						///< ::Int32 edit field.
#define CUSTOMGUI_LONGSLIDER			1000490								///< ::Int32 edit field with slider.
#define CUSTOMGUI_BOOL						DTYPE_BOOL						///< Checkbox.
#define CUSTOMGUI_TIME						DTYPE_TIME						///< Time edit field.
#define CUSTOMGUI_COLOR						1000492								///< Color chooser.
#define CUSTOMGUI_MATRIX					DTYPE_MATRIX					///< Matrix edit fields.
#define CUSTOMGUI_BUTTON					DTYPE_BUTTON					///< Button.
#define CUSTOMGUI_POPUP						DTYPE_POPUP						///< Popup field.
#define CUSTOMGUI_SEPARATOR				DTYPE_SEPARATOR				///< Separator.
#define CUSTOMGUI_SUBDESCRIPTION	0											///< Sub-description.
#define CUSTOMGUI_PROGRESSBAR			200000265							///< Progress bar.
/// @}

/// @addtogroup COLORA
/// @ingroup group_enumeration
/// @{
enum
{
	COLORA_R			= 1000,			///< R component.
	COLORA_G			= 1001,			///< G component.
	COLORA_B			= 1002,			///< B component.
	COLORA_A			= 1003			///< Alpha component.
};
/// @}

/// @addtogroup VECTOR4D
/// @ingroup group_enumeration
/// @{
enum
{
	VECTOR4D_X		= 1000,			///< X component.
	VECTOR4D_Y		= 1001,			///< Y component.
	VECTOR4D_Z		= 1002,			///< Z component.
	VECTOR4D_W		= 1003			///< W component.
};
/// @}

#ifndef __API_INTERN__

#include "c4d_customdatatype.h"

/// DescID custom data type ID.
#define CUSTOMDATATYPE_DESCID		1000486

/// @addtogroup VECTOR
/// @ingroup group_enumeration
/// @{
enum
{
	VECTOR_X		= 1000,			///< X component.
	VECTOR_Y		= 1001,			///< Y component.
	VECTOR_Z		= 1002			///< Z component.
};
/// @}

/// @addtogroup COLOR
/// @ingroup group_enumeration
/// @{
enum
{

	COLOR_R			= 1000,			///< R component.
	COLOR_G			= 1001,			///< G component.
	COLOR_B			= 1002			///< B component.
};
/// @}

/// Represents a level within a DescID.
struct DescLevel
{
	Int32 id;						///< ID of the level.
	Int32 dtype;				///< Data type. Either a custom ID or one of these: @link DTYPE_NONE DTYPE@endlink.
	Int32 creator;			///< Creator ID.

	//----------------------------------------------------------------------------------------
	/// Constructor, specifying only the ID.
	/// @param[in] t_id								Initial value for @ref id.
	//----------------------------------------------------------------------------------------
	DescLevel(Int32 t_id) : id(t_id), dtype(0), creator(0) { }

	//----------------------------------------------------------------------------------------
	///
	/// @param[in] t_id								Initial value for @ref id.
	/// @param[in] t_datatype					Initial value for @ref dtype.
	/// @param[in] t_creator					Initial value for @ref creator.
	//----------------------------------------------------------------------------------------
	DescLevel(Int32 t_id, Int32 t_datatype, Int32 t_creator) : id(t_id), dtype(t_datatype), creator(t_creator) { }

	//----------------------------------------------------------------------------------------
	/// Equality operator. Checks if description levels are equals i.e all vales are equal.
	/// @param[in] d									A description level to compare with.
	/// @return												@trueIfOtherwiseFalse{description levels are equal}
	//----------------------------------------------------------------------------------------
	Bool operator == (const DescLevel &d) const;

	//----------------------------------------------------------------------------------------
	/// Inequality operator. Checks if description levels are not equal i.e any vales is different.
	/// @param[in] d									A description level to compare with.
	/// @return												@trueIfOtherwiseFalse{description levels are not equal}
	//----------------------------------------------------------------------------------------
	Bool operator != (const DescLevel &d) const;
};

//----------------------------------------------------------------------------------------
/// An ID class for description elements. Contains a stack of DescLevel objects.\n
/// A description ID is used to exactly identify a parameter value.
/// - For first-level values (like a REAL (description element) or LONG (description element) value) it only consists of one DescLevel.
/// - For more complex datatypes like VECTOR (description element) and GRADIENT (description element) it can consist of @em 2 or more levels.
//----------------------------------------------------------------------------------------
class DescID : public iCustomDataType<DescID> // iCustomDataType is OK here since the size is the same
{
		Int32 temp1;
		Int32 *temp2;

	public:
	/// @name Constructor/Destructor
	/// @{

	//----------------------------------------------------------------------------------------
	/// Default constructor.
	//----------------------------------------------------------------------------------------
		DescID();

	//----------------------------------------------------------------------------------------
	/// Copy constructor.
	/// @param[in] src								Source DescID.
	//----------------------------------------------------------------------------------------
		DescID(const DescID &src);

	//----------------------------------------------------------------------------------------
	/// Creates a description ID with one level.
	/// @param[in] id1								First level.
	//----------------------------------------------------------------------------------------
		DescID(Int32 id1);

	//----------------------------------------------------------------------------------------
	/// Creates a description ID with one level.
	/// @param[in] id1								First level.
	//----------------------------------------------------------------------------------------
		DescID(const DescLevel &id1);

	//----------------------------------------------------------------------------------------
	/// Creates a description ID with two levels.
	/// @param[in] id1								First level.
	/// @param[in] id2								Second level.
	//----------------------------------------------------------------------------------------
		DescID(const DescLevel &id1, const DescLevel &id2);

	//----------------------------------------------------------------------------------------
	/// Creates an ID with three levels.
	/// @param[in] id1								First level.
	/// @param[in] id2								Second level.
	/// @param[in] id3								Third level.
	//----------------------------------------------------------------------------------------
		DescID(const DescLevel &id1, const DescLevel &id2, const DescLevel &id3);

	//----------------------------------------------------------------------------------------
	/// Default destructor.
	//----------------------------------------------------------------------------------------
		~DescID();

	/// @}

	/// @name Set/Push/Pop Level
	/// @{

	//----------------------------------------------------------------------------------------
	/// Sets the highest level to @formatParam{subid}.
	/// @param[in] subid							New top level.
	//----------------------------------------------------------------------------------------
		void SetId(const DescLevel &subid);

	//----------------------------------------------------------------------------------------
	/// Pushes a new level onto the stack.
	/// @param[in] subid							Level to push.
	//----------------------------------------------------------------------------------------
		void PushId(const DescLevel &subid);

	//----------------------------------------------------------------------------------------
	/// Pop the highest level from the stack.
	//----------------------------------------------------------------------------------------
		void PopId();

	/// @}

	/// @name Operator
	/// @{

	//----------------------------------------------------------------------------------------
	/// Accesses the level at position @formatParam{pos} in the stack.
	/// @param[in] pos								The position: @em 0 <= @formatParam{pos} < GetDepth()
	/// @return												The level at the specified position.
	//----------------------------------------------------------------------------------------
		const DescLevel &operator[] (Int32 pos) const;

	//----------------------------------------------------------------------------------------
	/// Assignment operator. Assigns @formatParam{id} to the description ID.
	/// @param[in] id									Right operand. Source description ID.
	/// @return												Left operant.
	//----------------------------------------------------------------------------------------
		const DescID& operator = (const DescID &id);

	//----------------------------------------------------------------------------------------
	/// Equality operator. Checks if all levels are equal.
	/// @param[in] d									Right operand description ID.
	/// @return												@trueIfOtherwiseFalse{description IDs are equal}
	//----------------------------------------------------------------------------------------
		Bool operator == (const DescID &d) const;

	//----------------------------------------------------------------------------------------
	/// Inequality operator. Checks if any level is different.
	/// @param[in] d									Right operand description ID.
	/// @return												@trueIfOtherwiseFalse{description IDs are not equal}
	//----------------------------------------------------------------------------------------
		Bool operator != (const DescID &d) const;

	//----------------------------------------------------------------------------------------
	/// Get the result of popping levels from the bottom of the stack.
	///
	/// @param[in] shift							Number of levels to pop. @em 0 <= @formatParam{shift} < GetDepth().
	/// @return												Resulting description ID after popping level(s).
	//----------------------------------------------------------------------------------------
		const DescID operator << (Int32 shift) const;

		//----------------------------------------------------------------------------------------
		/// Add operator. Merges two description IDs.
		/// @param[in] s									Right operand. Source description ID.
		/// @return												Left operant.
		//----------------------------------------------------------------------------------------
		const DescID & operator += (const DescID &s);

		//----------------------------------------------------------------------------------------
		/// Add operator. Merges two description IDs.
		/// @param[in] v1									Left operand.
		/// @param[in] v2									Right operand.
		/// @return												Result.
		//----------------------------------------------------------------------------------------
		friend const DescID operator + (const DescID &v1, const DescID &v2);

	/// @}

	/// @name Read/Write
	/// @{

		//----------------------------------------------------------------------------------------
		/// Reads the description ID from @formatParam{hf}.
		/// @param[in] hf									The hyper file to read from. @callerOwnsPointed{hyper file}
		/// @return												@trueIfOtherwiseFalse{successful}
		//----------------------------------------------------------------------------------------
		Bool Read(HyperFile *hf);

		//----------------------------------------------------------------------------------------
		/// Writes the description ID to @formatParam{hf}.
		/// @param[in] hf									The hyper file to write to. @callerOwnsPointed{hyper file}
		/// @return												@trueIfOtherwiseFalse{successful}
		//----------------------------------------------------------------------------------------
		Bool Write(HyperFile *hf);

	/// @}

	/// @name Miscellaneous
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets the depth of the stack, i.e. the number of levels.
	/// @return												The depth of the stack.
	//----------------------------------------------------------------------------------------
		Int32 GetDepth() const;

	//----------------------------------------------------------------------------------------
	/// Checks if the description ID is part of @formatParam{cmp} and assigns the length of the match to @formatParam{pos}.
	/// @param[in] cmp								The super description ID.
	/// @param[out] pos								If not @formatConstant{nullptr} this is assigned the length of the match.
	/// @return												@trueIfOtherwiseFalse{the description ID matches the lowest part of @formatParam{cmp}}
	//----------------------------------------------------------------------------------------
		Bool IsPartOf(const DescID &cmp, Int32 *pos) const;

		//----------------------------------------------------------------------------------------
		/// Gets a hash code for the description ID.
		/// @since R17.032
		/// @return												The hash code.
		//----------------------------------------------------------------------------------------
		UInt GetHashCode() const;

	/// @}
};

//----------------------------------------------------------------------------------------
/// The description class contains information for all description ID of an object.\n
/// For example it stores a BaseContainer for ::ID_BASEOBJECT_REL_POSITION that describes that this value is a Vector, has minimum and maximum values XYZ etc.\n
/// To access the actual values of these description parameters you will have to ask the object itself, for example with C4DAtom::GetParameter().\n
/// Example to get the name of a description, for example "Landscape Object":
/// @code
/// String GetTypeName(C4DAtom *op)
/// {
/// 	if (op)
/// 	{
/// 		AutoAlloc<Description> desc;
/// 		if (!desc)
/// 			return String();
/// 		if (!op->GetDescription(desc, DESCFLAGS_DESC::NONE))
/// 			return String();
/// 		const BaseContainer *bc = desc->GetParameterI(DESCID_ROOT, nullptr);
/// 		if (bc)
/// 			return bc->GetString(DESC_NAME);
/// 	}
/// 	return String();
/// }
/// @endcode
//----------------------------------------------------------------------------------------
class Description
{
	private:
		Description();
		~Description();

	public:
		/// @name Alloc/Free
		/// @{

	//----------------------------------------------------------------------------------------
	/// @allocatesA{description}
	/// @return												@allocReturn{description}
	//----------------------------------------------------------------------------------------
		static Description *Alloc();

	//----------------------------------------------------------------------------------------
	/// @destructsAlloc{descriptions}
	/// @param[in,out] description		@theToDestruct{description}
	//----------------------------------------------------------------------------------------
		static void Free(Description *&description);

		/// @}

		//----------------------------------------------------------------------------------------
		/// Loads a description from a @c BCResourceObj, such as the one returned from GetDescription().
		/// @warning Existing entries are lost.
		/// @param[in] bc									The @c BCResourceObj to load the description from.
		/// @param[in] copy								@formatConstant{true} if the description should be copied, otherwise the objects will share the same internal data so that changes to one affects the other.
		/// @return												@trueIfOtherwiseFalse{the description was loaded}
		//----------------------------------------------------------------------------------------
		Bool LoadDescription(const BCResourceObj *bc, Bool copy);

		//----------------------------------------------------------------------------------------
		/// Loads a description by ID. The ID must have been registered with RegisterDescription().
		/// @warning Existing entries are lost.
		/// @param[in] id									The description ID, for example @c Obase.
		/// @return												@trueIfOtherwiseFalse{the description was loaded}
		//----------------------------------------------------------------------------------------
		Bool LoadDescription(Int32 id);

		//----------------------------------------------------------------------------------------
		/// Loads a description by name. The description name must have been registered with RegisterDescription().
		/// @warning Existing entries are lost.
		/// @param[in] id									The description name, for example @em "Obase".
		/// @return												@trueIfOtherwiseFalse{the description was loaded}
		//----------------------------------------------------------------------------------------
		Bool LoadDescription(const String &id);

		//----------------------------------------------------------------------------------------
		/// @markPrivate
		//----------------------------------------------------------------------------------------
		Bool SortGroups();

		//----------------------------------------------------------------------------------------
		/// Retrieves the internal pointer of the description.
		/// @return												The internal description pointer.
		//----------------------------------------------------------------------------------------
		const BCResourceObj* GetDescription();

		//----------------------------------------------------------------------------------------
		/// Retrieves the information container for a description parameter.
		/// @param[in] id									The description ID.
		/// @param[out] temp							When the parameter is of a dynamic type that does not already exist as predefined container, i.e. not returnable as pointer, the result is the address of @formatParam{temp}, where @formatParam{temp} allows to store the data.\n
		/// 															In this case @formatConstant{nullptr} is returned.
		/// @param[out] ar								Most of the time this can be just AtomArray(). However dynamic descriptions (like sub-descriptions of a gradient or dynamic XPresso node) need an array of elements the parameter is assigned to.
		/// @return												The information container, or @formatConstant{nullptr} if @formatParam{temp} was used. @theOwnsPointed{description,container}
		//----------------------------------------------------------------------------------------
		const BaseContainer* GetParameter(const DescID &id, BaseContainer &temp, AtomArray *ar) const;

		//----------------------------------------------------------------------------------------
		/// Retrieves a pointer to the information container for a description parameter.
		/// @param[in] id									The description ID.
		/// @param[out] ar								Most of the time this can be just AtomArray(). However dynamic descriptions (like sub-descriptions of a gradient or dynamic XPresso node) need an array of elements the parameter is assigned to.
		/// @return												The information container. @theOwnsPointed{description,container}
		//----------------------------------------------------------------------------------------
		BaseContainer* GetParameterI(const DescID &id, AtomArray *ar);

		//----------------------------------------------------------------------------------------
		/// Inserts a description parameter into the collection.
		/// @param[in] id									The description ID.
		/// @param[in] param							The settings for the new parameter.
		/// @param[in] groupid						The ID of the parameter's group, or ::DESCID_ROOT.
		/// @return												@trueIfOtherwiseFalse{the parameter was inserted}
		//----------------------------------------------------------------------------------------
		Bool SetParameter(const DescID &id, const BaseContainer &param, const DescID &groupid);

		//----------------------------------------------------------------------------------------
		/// Starts browsing the parameters linearly.
		/// @warning After browsing is done done BrowseFree() must be called.
		/// @return												The browse handle.
		//----------------------------------------------------------------------------------------
		void *BrowseInit();

		//----------------------------------------------------------------------------------------
		/// Retrieves the next parameter in a browse sequence initialized with BrowseInit().
		/// @param[in] handle							The browse handle returned by BrowseInit().
		/// @param[out] bc								Assigned the settings for the retrieved parameter. @callerOwnsPointed{base container}
		/// @param[out] id								Assigned the ID of the retrieved parameter.
		/// @param[out] groupid						Assigned the group ID of the retrieved parameter.
		/// @return												@formatConstant{true} if a new parameter was retrieved, otherwise the sequence is finished.
		//----------------------------------------------------------------------------------------
		Bool GetNext(void *handle, const BaseContainer **bc, DescID &id, DescID &groupid);

		//----------------------------------------------------------------------------------------
		/// Frees browse handles from BrowseInit().
		/// @param[in,out] handle					The handle to free. Assigned @formatConstant{nullptr}.
		//----------------------------------------------------------------------------------------
		void BrowseFree(void *&handle);

		//----------------------------------------------------------------------------------------
		/// Gets a handle to the first description entry. Use GetDescEntry() to access the information and GetNext() or GetDown() to browse the hierarchy.
		/// @param[in] op									Most of the time this can be just AtomArray(). However dynamic descriptions (like sub-descriptions of a gradient or dynamic XPresso node) need an array of elements the parameter is assigned to.
		/// @return												The description entry handle.
		//----------------------------------------------------------------------------------------
		DescEntry *GetFirst(const AtomArray &op);

		//----------------------------------------------------------------------------------------
		/// Gets the next description entry handle.
		/// @param[in] de									The current description entry handle.
		/// @return												The next description entry handle.
		//----------------------------------------------------------------------------------------
		DescEntry *GetNext(DescEntry *de);

		//----------------------------------------------------------------------------------------
		/// Gets the child description entry handle.
		/// @param[in] de									The current description entry handle.
		/// @return												The child description entry handle.
		//----------------------------------------------------------------------------------------
		DescEntry *GetDown(DescEntry *de);

		//----------------------------------------------------------------------------------------
		/// Retrieves the data for a description entry handle.
		/// @param[in] de									The current description entry handle.
		/// @param[out] bc								Assigned the settings for the retrieved parameter. @callerOwnsPointed{base container}
		/// @param[out] descid						Assigned the ID of the retrieved parameter.
		//----------------------------------------------------------------------------------------
		void GetDescEntry(DescEntry *de, const BaseContainer **bc, DescID &descid);

		//----------------------------------------------------------------------------------------
		/// @markPrivate
		//----------------------------------------------------------------------------------------
		SubDialog *CreateDialogI();

		//----------------------------------------------------------------------------------------
		/// @markPrivate
		//----------------------------------------------------------------------------------------
		void FreeDialog(SubDialog *dlg);

		//----------------------------------------------------------------------------------------
		/// Builds a popup menu for choosing a parameter in the description.
		/// @param[out] menu							Assigned the menu container.
		/// @return												@trueIfOtherwiseFalse{the menu was built}
		//----------------------------------------------------------------------------------------
		Bool CreatePopupMenu(BaseContainer &menu);

		//----------------------------------------------------------------------------------------
		/// @markPrivate
		//----------------------------------------------------------------------------------------
		Bool GetPopupId(Int32 id, const DescID &descid);

		//----------------------------------------------------------------------------------------
		/// Checks if a description ID @formatParam{searchid} exists for the given objects @formatParam{ops} (usually only one single object is passed as otherwise the smallest common nominator is returned).\n
		/// If @formatParam{completeid} != @formatConstant{nullptr} and the return value is @formatConstant{true} the complete ID will be assigned to @formatParam{completeid}.
		/// @note Complete ID means that all parts of the DescLevel are filled with appropriate data.\n
		/// For example if the DescID passed is:
		/// @code
		/// DescID(DescLevel(ID_BASEOBJECT_POSITION, 0, 0), DescLevel(VECTOR_X, 0, 0))
		/// @endcode
		/// CheckDescID() will return:
		/// @code
		/// DescID(DescLevel(ID_BASEOBJECT_POSITION, DTYPE_VECTOR, ID_BASEOBJECT_GROUP1), DescLevel(VECTOR_X, DTYPE_REAL, ...))
		/// @endcode
		/// @param[in] searchid						The partial ID.
		/// @param[in] ops								Most of the time this can be just AtomArray(). However dynamic descriptions (like sub-descriptions of a gradient or dynamic XPresso node) need an array of elements the parameter is assigned to.
		/// @param[out] completeid				Assigned the complete ID.
		/// @return												@trueIfOtherwiseFalse{a description ID @formatParam{searchid} exists}
		//----------------------------------------------------------------------------------------
		Bool CheckDescID(const DescID &searchid, const AtomArray &ops, DescID *completeid);

		//----------------------------------------------------------------------------------------
		/// Retrieves dynamic sub-description data (e.g. the gradient data type).
		/// @param[in] did								The description ID.
		/// @param[in] op									The current objects.
		/// @param[in] resdatatypeplugin	The resource data type plug, retrieved with ::FindResourceDataTypePlugin().
		/// @param[out] bc								The existing container for the data type.
		/// @param[in] singledescid				Should be @formatConstant{nullptr}.
		/// @return												@trueIfOtherwiseFalse{successful}
		//----------------------------------------------------------------------------------------
		Bool GetSubDescriptionWithData(const DescID &did, const AtomArray &op, RESOURCEDATATYPEPLUGIN  *resdatatypeplugin, const BaseContainer &bc, DescID *singledescid);

		//----------------------------------------------------------------------------------------
		/// @markPrivate
		//----------------------------------------------------------------------------------------
		const DescID *GetSingleDescID();

		//----------------------------------------------------------------------------------------
		/// @markPrivate
		//----------------------------------------------------------------------------------------
		void SetSingleDescriptionMode(const DescID &descid);
};

//----------------------------------------------------------------------------------------
/// The dynamic description class stores user data values. See Description for its container format.
/// @note Use ::EditDescription() to let the user edit the container settings.
//----------------------------------------------------------------------------------------
class DynamicDescription
{
		DynamicDescription();
		~DynamicDescription();

	public:

		//----------------------------------------------------------------------------------------
		/// Allocates a new user data and return its ID.
		/// @param[in] datadescription		The settings of the new user data.
		/// @return												The ID of the new user data.
		//----------------------------------------------------------------------------------------
		DescID Alloc(const BaseContainer &datadescription);

		//----------------------------------------------------------------------------------------
		/// Inserts a new user data with the specified ID.
		/// @param[in] descid							The ID of the new user data.
		/// @param[in] datadescription		The settings of the new user data.
		/// @param[in] bl									@markTODO
		/// @return												@trueIfOtherwiseFalse{the user data was inserted}
		//----------------------------------------------------------------------------------------
		Bool Set(const DescID &descid, const BaseContainer &datadescription, BaseList2D *bl);

		//----------------------------------------------------------------------------------------
		/// Finds user data settings from its description ID.
		/// @param[in] descid							The ID of the user data.
		/// @return												The found settings, or @formatConstant{nullptr}. @theOwnsPointed{description,base container}
		//----------------------------------------------------------------------------------------
		const BaseContainer* Find(const DescID &descid);

		//----------------------------------------------------------------------------------------
		/// Removes user data by ID.
		/// @param[in] descid							The ID of the user data.
		/// @return												@trueIfOtherwiseFalse{the user data was removed}
		//----------------------------------------------------------------------------------------
		Bool Remove(const DescID &descid);

		//----------------------------------------------------------------------------------------
		/// Copies the dynamic description.
		/// @param[in] dest								The destination dynamic description. @callerOwnsPointed{dynamic description}
		/// @return												@trueIfOtherwiseFalse{the description was copied}
		//----------------------------------------------------------------------------------------
		Bool CopyTo(DynamicDescription *dest);

		//----------------------------------------------------------------------------------------
		/// Starts browsing the parameters linearly.
		/// @warning After browsing is done done BrowseFree() must be called.
		/// @return												The browse handle.
		//----------------------------------------------------------------------------------------
		void* BrowseInit(void);

		//----------------------------------------------------------------------------------------
		/// Retrieves the next parameter in a browse sequence initialized with BrowseInit().
		/// @param[in] handle							The browse handle returned by BrowseInit().
		/// @param[out] id								Assigned the ID of the retrieved parameter.
		/// @param[out] data							Assigned the settings for the retrieved parameter. @callerOwnsPointed{base container}
		/// @return												@formatConstant{true} if a new parameter was retrieved, otherwise the sequence is finished.
		//----------------------------------------------------------------------------------------
		Bool BrowseGetNext(void* handle, DescID *id, const BaseContainer **data);

		//----------------------------------------------------------------------------------------
		/// Frees browse handles from BrowseInit().
		/// @param[in,out] handle					The handle to free. Assigned @formatConstant{nullptr}.
		//----------------------------------------------------------------------------------------
		void BrowseFree(void* &handle);

		//----------------------------------------------------------------------------------------
		/// Fills the default settings container for a certain data @formatParam{type} with the specified @formatParam{name}.
		/// @param[out] res								Assigned the default settings.
		/// @param[in] type								The datatype ID. Either a custom ID or one of: @link DTYPE_NONE DTYPE@endlink.
		/// @param[in] name								The name of the user data.
		/// @return												@trueIfOtherwiseFalse{the settings were filled}
		//----------------------------------------------------------------------------------------
		Bool FillDefaultContainer(BaseContainer &res, Int32 type, const String &name);

		//----------------------------------------------------------------------------------------
		/// Gets the dirty count. Can be used to check if something has changed.
		/// @return												The dirty counter, incremented when something changes in the system.
		//----------------------------------------------------------------------------------------
		UInt32 GetDirty() const;
};
#else
	#include "res_basecontainer.h"
#endif

/// Macro that handles GetParameter() calls for Vector. (For an example of usage see @em datatype.cpp SDK example.)
#define HandleDescGetVector(tid, vector, t_data, flags) \
	switch (tid[1].id) \
	{ \
		case 0:			t_data = GeData(vector);   flags |= DESCFLAGS_GET::PARAM_GET; break; \
		case 1000:	t_data = GeData(vector.x); flags |= DESCFLAGS_GET::PARAM_GET; break; \
		case 1001:	t_data = GeData(vector.y); flags |= DESCFLAGS_GET::PARAM_GET; break; \
		case 1002:	t_data = GeData(vector.z); flags |= DESCFLAGS_GET::PARAM_GET; break; \
	} \

/// Macro that handles SetParameter() calls for Vector. (For an example of usage see @em datatype.cpp SDK example.)
#define HandleDescSetVector(v, tid, vector, t_data, flags) \
	switch (tid[1].id) \
	{ \
		case 0:			v = t_data.GetVector(); flags |= DESCFLAGS_SET::PARAM_SET; break; \
		case 1000:	v = Vector(t_data.GetFloat(), vector.y, vector.z); flags |= DESCFLAGS_SET::PARAM_SET; break; \
		case 1001:	v = Vector(vector.x, t_data.GetFloat(), vector.z); flags |= DESCFLAGS_SET::PARAM_SET; break; \
		case 1002:	v = Vector(vector.x, vector.y, t_data.GetFloat()); flags |= DESCFLAGS_SET::PARAM_SET; break; \
	} \

//----------------------------------------------------------------------------------------
/// Message struct for some message types.
//----------------------------------------------------------------------------------------
struct DescriptionBaseMessage
{
	DescID _descId;														///< Description ID of the parameter that triggered the command.
	GeDialog* _parentDialog = nullptr;				///< Parent dialog. @since R20
};

//----------------------------------------------------------------------------------------
/// Message struct for ::MSG_DESCRIPTION_COMMAND.
//----------------------------------------------------------------------------------------
struct DescriptionCommand : public DescriptionBaseMessage
{
	const BaseContainer		*_msg = nullptr;						///< Original message container.
	DescriptionCustomGui	*_descgui = nullptr;				///< Description GUI of the element that triggered the corresponding message.
	BaseContainer _data;															///< Auxiiar data container
};

//----------------------------------------------------------------------------------------
/// Message struct for ::MSG_DESCRIPTION_POPUP.
//----------------------------------------------------------------------------------------
struct DescriptionPopup : public DescriptionBaseMessage
{
	Int32								_chosen = 0;				///< Selected element of the popup.
	const BaseContainer	*_msg = nullptr;		///< Original message container.
	BaseContainer				_popup;						///< Popup container.
};
//----------------------------------------------------------------------------------------
/// Message struct for ::MSG_DESCRIPTION_CHECKDRAGANDDROP.
//----------------------------------------------------------------------------------------
struct DescriptionCheckDragAndDrop : public DescriptionBaseMessage
{
	GeListNode	*_element = nullptr;			///< Element to drop.
	Bool				_result = true;						///< [out] Set to @formatConstant{true} if the drop is acceptable, otherwise to @formatConstant{false}.
	Int32				_dragType = 0;						///< [in] Type of the result of the call of GeDialog::GetDragObject
	void*				_dragObject = nullptr;		///< [in] Object of the result of the call of GeDialog::GetDragObject
	Bool				_dndFinished = false;			///< [in] If the value is true the drag and drop is finished and should be performed.
};

//----------------------------------------------------------------------------------------
/// Message struct for ::MSG_DESCRIPTION_INEX_DELETED.
/// @since R18
//----------------------------------------------------------------------------------------
struct DescriptionInExDeleted : public DescriptionBaseMessage
{
	GeListNode	*_element = nullptr;			///< Deleted element.
	Int32				_index = 0;							///< Index in the list before delete.
};

//----------------------------------------------------------------------------------------
/// Message struct for ::MSG_DESCRIPTION_INEX_ADDED.
/// @since R18
//----------------------------------------------------------------------------------------
struct DescriptionInExAdded : public DescriptionBaseMessage
{
	GeListNode	*_element = nullptr;			///< Added element.
	Int32				_index = 0;							///< Index in the list after add.
};

//----------------------------------------------------------------------------------------
/// Message struct for ::MSG_DESCRIPTION_INEX_SELCHANGED.
/// @since R18
//----------------------------------------------------------------------------------------
struct DescriptionInExSelChanged : public DescriptionBaseMessage
{
};

//----------------------------------------------------------------------------------------
/// Message struct for ::MSG_DESCRIPTION_CUSTOMGUI_NOTIFICATION.
/// @since R19
//----------------------------------------------------------------------------------------
struct DescriptionCustomGuiNotification : public DescriptionBaseMessage
{
	Int32 								_customGuiId = NOTOK;			///< The custom GUI plugin ID.
	Int32 								_subId = NOTOK;						///< The message type sub-ID. Depending on the custom GUI implementation a different sub-ID can be passed with different data.
	const BaseContainer*	_data = nullptr;					///< The data of the message, can be @formatConstant{nullptr}.
};

//----------------------------------------------------------------------------------------
/// Message struct for ::MSG_DESCRIPTION_GETBITMAP.
//----------------------------------------------------------------------------------------
struct DescriptionGetBitmap : public DescriptionBaseMessage
{
	BaseBitmap*		_bmp = nullptr;										///< Recipient should allocate a bitmap and assign this pointer. The sender must ensure that the bitmap is freed properly. (Normally this means that @C4D does the freeing.)
	ICONDATAFLAGS	_bmpflags = ICONDATAFLAGS::NONE;	///< Flags: @enumerateEnum{ICONDATAFLAGS}
	Int32					_width = 0;												///< The width of the GUI the bitmap is being drawn into
};

/// @markPrivate
struct DescriptionGetObjects : public DescriptionBaseMessage
{
	BaseContainer	_bc;
};

//----------------------------------------------------------------------------------------
/// Message struct for the @ref MSG_DESCRIPTION_ALLOWOVERRIDE message.
/// @since R17.032
/// @see Take System @ref page_manual_baseoverride_takesystem_additional_messages.
//----------------------------------------------------------------------------------------
struct DescriptionAllowOverride
{
	//----------------------------------------------------------------------------------------
	/// Default constructor.
	/// @param[in] takeData						The take system context. @callerOwnsPointed{TakeData}
	/// @param[in] overrideTake				The take asking for the override. @callerOwnsPointed{BaseTake}
	/// @param[in] descId							The description ID to be overridden.
	//----------------------------------------------------------------------------------------
	DescriptionAllowOverride(TakeData* takeData = nullptr, BaseTake* overrideTake = nullptr, const DescID* descId = nullptr): _takeData(takeData), _overrideTake(overrideTake), _descId(descId), _parent(nullptr), _parentId(DescID()), _allow(false), _overrideEnabled(true) { }

	TakeData*						_takeData;					///< Take system context. @cinemaOwnsPointed{TakeData}
	BaseTake*						_overrideTake;			///< Take asking for the override.
	const DescID*				_descId;						///< %Description ID to be overridden.
	BaseList2D*					_parent;						///< Parent node if the override must be assigned to it and not to the original node. Especially useful in case of branched structures.
	DescID							_parentId;					///< If @ref _parent is set also a translated parameter ID needs to be set.
	Bool								_allow;							///< @trueIfOtherwiseFalse{the parameter can be overridden}
	Bool								_overrideEnabled;		///< @trueIfOtherwiseFalse{the global switch allows the override}
};

//----------------------------------------------------------------------------------------
/// Message struct for the @ref MSG_DESCRIPTION_TAKECHANGED message.
/// @since R17.032
/// @see Take System @ref page_manual_baseoverride_takesystem_additional_messages.
//----------------------------------------------------------------------------------------
struct DescriptionTakeChanged
{
	//----------------------------------------------------------------------------------------
	/// Default constructor.
	//----------------------------------------------------------------------------------------
	DescriptionTakeChanged(TakeData* takeData = nullptr, BaseTake* overrideTake = nullptr, BaseOverride* overrideNode = nullptr, Bool store = false, const DescID* descId = nullptr): _takeData(takeData), _overrideTake(overrideTake), _overrideNode(overrideNode), _store(store), _descId(descId) { }

	TakeData*			_takeData;					///< The take system context. @cinemaOwnsPointed{takedata}
	BaseTake*			_overrideTake;			///< The take used for the operation.
	BaseOverride*	_overrideNode;			///< The the override for this node.
	Bool					_store;							///< If true the data is going to be stored in a take, else the data are going to be sent to the document.
	const DescID*	_descId;						///< The description ID for the message, can be nullptr so is sent at the end of the operation just once.
};

//----------------------------------------------------------------------------------------
/// @markInternal Use RegisterDescription() instead.
//----------------------------------------------------------------------------------------
Bool Description_Register(Int32 id, const String &idstr, LocalResource *res);

/// @}


/// @cond IGNORE

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

#define LIBRARY_DESCRIPTIONLIB		1000467

struct DescriptionLib : public C4DLibrary
{
	Bool (*Register )(Int32 id, const String &idstr, LocalResource *res);

	Description*					(*Alloc)();
	void									(*Free)(Description *&description);

	Bool									(*LoadDescriptionBc)(Description *desc, const BCResourceObj *bc, Bool copy);
	Bool									(*LoadDescriptionId)(Description *desc, Int32 id);
	Bool									(*LoadDescriptionStr)(Description *desc, const String *id);
	Bool									(*SortGroups)(Description *desc);

	const BCResourceObj*	(*GetDescription)(Description *desc);
	const BaseContainer*	(*GetParameter)(const Description *desc, const DescID &id, BaseContainer &temp, AtomArray *ar);
	BaseContainer*				(*GetParameterI)(Description *desc, const DescID &id, AtomArray *ar);
	Bool									(*SetParameter)(Description *desc, const DescID &id, const BaseContainer &param, const DescID &groupid);	// returns the specified property

	void *								(*BrowseInit)(Description *desc);
	Bool									(*GetNext)(Description *desc, void *handle, const BaseContainer **bc, DescID &id, DescID &groupid);
	void									(*BrowseFree)(Description *desc, void *&handle);
	void									(*EX_01)(Description *desc);

	SubDialog *						(*CreateDialogI)(Description *desc);
	void									(*FreeDialog)(Description *desc, SubDialog *dlg);

	Bool									(*CreatePopupMenu)(Description *desc, BaseContainer *menu);
	Bool									(*GetPopupId)(Description *desc, Int32 id, const DescID &descid);

	const DescID*					(*GetSingleDescID)(Description *desc);
	void									(*SetSingleDescriptionMode)(Description *desc, const DescID &descid);

	void									(*DescID_Init)(DescID *id);
	void									(*DescID_Free)(DescID *id);
	void									(*DescID_SetId)(DescID *id, const DescLevel &subid);
	void									(*DescID_PushId)(DescID *id, const DescLevel &subid);
	void									(*DescID_PopId)(DescID *id);
	const DescLevel&			(*DescID_operator1)(DescID *id, Int32 pos);
	const DescID					(*DescID_operator2)(DescID *id, Int32 pos);
	void									(*DescID_CopyTo)(DescID *src, DescID *dest);
	Bool									(*DescID_Compare)(DescID *d1, DescID *d2);

	DescID								(DynamicDescription::*DDAlloc					)(const BaseContainer &datadescription);
	Bool									(DynamicDescription::*DDSetObsolete		)(const DescID &descid, const BaseContainer &datadescription);
	const BaseContainer*	(DynamicDescription::*DDFind					)(const DescID &descid);
	Bool									(DynamicDescription::*DDRemove				)(const DescID &descid);
	Bool									(DynamicDescription::*DDCopyTo				)(DynamicDescription *dest) const;
	void*									(DynamicDescription::*DDBrowseInit		)(void) const;
	Bool									(DynamicDescription::*DDBrowseGetNext	)(void* handle, DescID *id, const BaseContainer **data) const;
	void									(DynamicDescription::*DDBrowseFree		)(void* &handle) const;
	Bool									(DynamicDescription::*FillDefaultContainer)(BaseContainer &res, Int32 type, const String &name) const;

	Bool									(*GetSubDescriptionWithData						)(Description *desc, const DescID &did, const AtomArray &op, RESOURCEDATATYPEPLUGIN *resdatatypeplugin, const BaseContainer &bc, DescID *singledescid);
	Bool									(*CheckDescID													)(Description *desc, const DescID &searchid, const AtomArray &ops, DescID *completeid);

	DescEntry*						(*DescEntryGetFirst										)(Description *desc, const AtomArray &op);
	DescEntry*						(*DescEntryGetNext										)(Description *desc, DescEntry *de);
	DescEntry*						(*DescEntryGetDown										)(Description *desc, DescEntry *de);
	void									(*DescEntryGetDescEntry								)(Description *desc, DescEntry *de, const BaseContainer **bc, DescID &descid);
	String								(*DescGenerateTitle										)(AtomArray *arr);

	Bool									(*DescID_Read)(DescID *id, HyperFile *hf);
	Bool									(*DescID_Write)(DescID *id, HyperFile *hf);
	Bool									(DynamicDescription::*DDSet						)(const DescID &descid, const BaseContainer &datadescription, BaseList2D *bl);

	UInt32								(DynamicDescription::*GetDirty				)() const;

	const DescID					(*DescID_AddTo)(DescID *d1, DescID *d2);
	DescID								(*DescID_Add)(DescID *d1, DescID *d2);
	UInt									(*DescID_GetHashCode)(const DescID *d);
};

String DescGenerateTitle(AtomArray *arr);

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

/// @endcond

#endif // LIB_DESCRIPTION_H__
