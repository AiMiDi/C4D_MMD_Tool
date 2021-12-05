#ifndef MESH_ATTRIBUTE_BASE_H__
#define MESH_ATTRIBUTE_BASE_H__

#include "maxon/apibase.h"
#include "maxon/objectbase.h"
#include "maxon/interfacebase.h"
#include "maxon/string.h"
#include "maxon/basearray.h"
#include "maxon/datatype.h"

#include "maxon/vertexwrapper.h"
#include "maxon/mesh_attribute_utilities.h"

class BaseTag;
class BaseObject;
class BaseDraw;
class BaseDrawHelp;
class BaseDocument;
class BaseSceneHook;
class AtomArray;
class HyperFile;
struct GetCustomIconData;
struct ControlDisplayStruct;

namespace maxon
{

class CustomDataTagDisplayRef;

//----------------------------------------------------------------------------------------
/// A compatible datatype must be defined for each MeshAttributeClassInterface.
/// This macro automatically generates a compatible data type out of the passed T.
/// After this macro call, it is also necessary to declare and register the resulting DataType using MAXON_DATATYPE and MAXON_DATATYPE_REGISTER.
/// MAXON_DATATYPE must be invoked by using as a name the passed name followed by _MESHATTRIBUTE.
/// @param[in] T									The type to register.
/// @param[in] Name								The name to be used for the registration.
///
/// In the header file:
/// @code
///	namespace maxon
///	{
///		MAXON_MESHATTRIBUTE(ColorA32, VERTEXCOLOR);
///		MAXON_DATATYPE(VERTEXCOLOR_MESHATTRIBUTE, "net.maxon.meshattribute.vertexcolor");
///	}
/// @endcode
///
/// in the source file:
/// @code
///	namespace maxon
///	{
///		MAXON_DATATYPE_REGISTER(VERTEXCOLOR_MESHATTRIBUTE);
///	}
/// @endcode
//----------------------------------------------------------------------------------------
#define MAXON_MESHATTRIBUTE(T, Name) \
	namespace Name \
	{ \
		class TYPE : public maxon::details::PrivateVertexWrapper<T> \
		{ \
			MAXON_DISALLOW_COPY_AND_ASSIGN(TYPE); \
			public: \
			TYPE() { } \
			TYPE(TYPE&& src)	{ MoveContent(&src); } \
			MAXON_OPERATOR_MOVE_ASSIGNMENT(TYPE); \
		}; \
	}\
	using Name##_MESHATTRIBUTE = Name::TYPE;

//----------------------------------------------------------------------------------------
/// CustomDataTagDisplayInterface can be optionally implemented for each CustomDataTagClassInterface implementation and defines
/// if and how a CustomDataTag should be displayed in the viewport.
//----------------------------------------------------------------------------------------
class CustomDataTagDisplayInterface : MAXON_INTERFACE_BASES(ObjectInterface)
{
	MAXON_INTERFACE(CustomDataTagDisplayInterface, MAXON_REFERENCE_NORMAL, "net.maxon.mesh_misc.interface.customdatatagdisplay");

public:

	//----------------------------------------------------------------------------------------
	/// Initializes the class after creation.
	/// @param[in] tag								The tag that owns the attributes.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Init(BaseTag* tag);

	//----------------------------------------------------------------------------------------
	/// Draws the visual representation of the tag data in 3D views.
	/// @calledThreadContext
	/// @note To get the current drawpass call @formatParam{bd}->@link BaseDraw::GetDrawPass GetDrawPass()@endlink.
	/// @warning Only draw in @ref DRAWPASS::HIGHLIGHTS if you really know what you are doing. Otherwise always check the drawpass and then do not draw if it is @ref DRAWPASS::HIGHLIGHTS.
	/// @param[in] tag								The BaseTag connected with the TagData instance. Equal to <tt>static_cast</tt><@ref TagData*>Get(). Provided for speed and convenience. @cinemaOwnsPointed{tag}
	/// @param[in] op									The host object of the tag. @cinemaOwnsPointed{object}
	/// @param[in] bd									The editor's view. @callerOwnsPointed{view}
	/// @param[in] bh									The helper for the editor's view. @callerOwnsPointed{view helper}
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Draw(BaseTag* tag, BaseObject* op, BaseDraw* bd, BaseDrawHelp* bh);

	//----------------------------------------------------------------------------------------
	/// Sets information about how the active object should be displayed.
	/// @param[in] tag								The BaseTag connected with the TagData instance. Equal to <tt>static_cast</tt><@ref TagData*>Get(). Provided for speed and convenience. @cinemaOwnsPointed{tag}
	/// @param[in] doc								The active document. @cinemaOwnsPointed{document}
	/// @param[in] op									The active object. @cinemaOwnsPointed{object}
	/// @param[in] bd									The active editor view. @cinemaOwnsPointed{base draw}
	/// @param[in] bh									The helper for active the editor view. @callerOwnsPointed{view helper}
	/// @param[in] cds								The display control settings.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> DisplayControl(BaseTag* tag, BaseDocument* doc, BaseObject* op, BaseDraw* bd, BaseDrawHelp* bh, ControlDisplayStruct& cds);

	//----------------------------------------------------------------------------------------
	/// Initializes resources for the display control used in @ref DisplayControl.
	/// @param[in] tag								The BaseTag connected with the TagData instance. Equal to <tt>static_cast</tt><@ref TagData*>Get(). Provided for speed and convenience. @cinemaOwnsPointed{tag}
	/// @param[in] doc								The active document. @cinemaOwnsPointed{document}
	/// @param[in] bd									The active editor view. @cinemaOwnsPointed{base draw}
	/// @param[in] active							The active objects array. @cinemaOwnsPointed{array}
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> InitDisplayControl(BaseTag* tag, BaseDocument* doc, BaseDraw* bd, const AtomArray* active);

	//----------------------------------------------------------------------------------------
	/// Frees resources allocated by @ref InitDisplayControl.
	/// @param[in] tag								The BaseTag connected with the TagData instance. Equal to <tt>static_cast</tt><@ref TagData*>Get(). Provided for speed and convenience. @cinemaOwnsPointed{tag}
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void FreeDisplayControl(BaseTag* tag);

	//----------------------------------------------------------------------------------------
	/// Resets any local data before destroying the class instance.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void Reset();
};

//----------------------------------------------------------------------------------------
/// By implementing this interface, it is possible to define a new mesh attribute type so that a data type can be attached to mesh vertices or to mesh polyvertices.
/// The interface needs to be implemented with the data type description, which has to be registered using MAXON_MESHATTRIBUTE and MAXON_DATATYPE, and all arithmetic and comparison functions.
//----------------------------------------------------------------------------------------
class MeshAttributeClassInterface : MAXON_INTERFACE_BASES(ObjectInterface)
{
	MAXON_INTERFACE(MeshAttributeClassInterface, MAXON_REFERENCE_CONST, "net.maxon.mesh_misc.interface.meshattributeclass");

public:

	//----------------------------------------------------------------------------------------
	/// Returns the DataType this class manages, e.g. Vector2d32 for UV maps.
	/// @return												The DataType.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD const DataType& GetDataType() const;

	//----------------------------------------------------------------------------------------
	/// Interpolates linearly between two values. Both addresses need to be cast to the appropriate data type.
	/// @param[in,out] data1					The address of the first value. The value will be overwritten with the result.
	/// @param[in] data2							The address of the second value.
	/// @param[in] blend							The blend percentage [0.0..blend..1.0]
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void InterpolateLinear(void* data1, const void* data2, Float blend) const;

	//----------------------------------------------------------------------------------------
	/// Interpolates a value in the outline using the specified weights. The addresses in data and outline need to be cast to the appropriate data type.
	/// @param[in,out] data						The address of the value. The value will be overwritten with the result.
	/// @param[in] outline						The outline data used to perform the interpolation.
	/// @param[in] weights						Weights to be used for the interpolation, represent the interpolation distance from each outline edge.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void InterpolateInOutline(void* data, const Block<void*>& outline, const Block<Float>& weights) const;

	//----------------------------------------------------------------------------------------
	/// Returns the default value for this attribute. The caller owns the passed pointer.
	/// @param[out] data							A pointer filled with the default value.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void GetDefaultValue(void* data) const;

	//----------------------------------------------------------------------------------------
	/// Compares two data values for "less than".
	/// In most cases this returns the MeshAttributeClassInterface::GetDataType()::Compare() but the developer is free to customize comparison if needed.
	/// @param[in] data1							First data to compare.
	/// @param[in] data2							Second data to compare.
	/// @return												True if the content of data1 is smaller then data2.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Bool AtrLessThen(const void* data1, const void* data2) const;

	//----------------------------------------------------------------------------------------
	/// Compares two data values for equality.
	/// In most of cases just returns the MeshAttributeClassInterface::GetDataType()::IsEqual() but the developer is free to customize comparison if needed.
	/// @param[in] data1							First data to compare.
	/// @param[in] data2							Second data to compare.
	/// @return												True if the content of data1 is equal to data2.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Bool AtrIsEqual(const void* data1, const void* data2) const;

	//----------------------------------------------------------------------------------------
	/// Defines how to add two data values.
	/// @param[in,out] data1					The address of the first value. The value will be overwritten with the result.
	/// @param[in] data2							The address of the second value.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void AtrAdd(void* data1, const void* data2) const;

	//----------------------------------------------------------------------------------------
	/// Defines how to subtract two data values.
	/// @param[in,out] data1					The address of the first value. The value will be overwritten with the result.
	/// @param[in] data2							The address of the second value.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void AtrSubstract(void* data1, const void* data2) const;

	//----------------------------------------------------------------------------------------
	/// Defines how to multiply two data values.
	/// @param[in,out] data1					The address of the first value. The value will be overwritten with the result.
	/// @param[in] data2							The address of the second value.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void AtrMultiply(void* data1, const void* data2) const;

	//----------------------------------------------------------------------------------------
	/// Defines how to multiply a data value by a float value.
	/// @param[in,out] data						The address of the data value. The value will be overwritten with the result.
	/// @param[in] value							The value to be used for the multiplication.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void AtrMultiply(void* data, Float value) const;

	//----------------------------------------------------------------------------------------
	/// Defines how to divide two data values.
	/// @param[in,out] data1					The address of the first value. The value will be overwritten with the result.
	/// @param[in] data2							The address of the second value.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void AtrDivide(void* data1, const void* data2) const;

	//----------------------------------------------------------------------------------------
	/// Defines how to divide a data value by a float value.
	/// @param[in,out] data						The address of the data value. The value will be overwritten with the result.
	/// @param[in] value							The value to be used for the division.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void AtrDivide(void* data, Float value) const;

	//----------------------------------------------------------------------------------------
	/// Returns a readable string of the content of a data pointer.
	/// @param[in,out] data						The address of the data value.
	/// @param[in] formatStatement		Nullptr or additional formatting instructions. Currently no additional formatting instructions are supported.
	/// @return												The converted result.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD String AtrToString(const void* data, const FormatStatement* formatStatement) const;
};

//----------------------------------------------------------------------------------------
/// This macro simplifies the process of describing the CustomDataTag information used for registration.
/// This macro implements many of the CustomDataTagClassInterface methods automatically.
/// @param[in] pluginID						An unique plugin id used to register the CustomDataTag.
/// @param[in] name								The CustomDataTag name.
/// @param[in] resurceID					The resource id string.
/// @param[in] displayID					The display implementation id. See CustomDataTagDisplay.
/// @param[in] level							The disk level for the CustomDataTag.
/// @param[in] floatValueCount		The count of values used for each entry; e.g. a vector will have a floatSize = 3, this is needed to define if the tag is compatible with sds.
/// 															If it is not compatible (no float based data type) pass NOTOK.
/// @param[in] flags							Tag registration flags.
//----------------------------------------------------------------------------------------
#define MAXON_CUSTOMDATATAG(pluginID, name, resurceID, displayID, level, floatValueCount, flags) \
	public: \
	MAXON_METHOD maxon::Int32 GetTagPluginId() const \
	{ \
		return pluginID; \
	} \
	MAXON_METHOD const maxon::String& GetTagPluginName() const \
	{ \
		return name; \
	} \
	MAXON_METHOD const maxon::String& GetResourceId() const \
	{ \
		return resurceID; \
	} \
	MAXON_METHOD maxon::Int32 GetTagPluginLevel() const \
	{ \
		return level; \
	} \
	MAXON_METHOD maxon::Id GetDisplayClassId() const \
	{ \
		return displayID; \
	} \
	MAXON_METHOD maxon::Bool IsSdsCompatible(maxon::Int32& floatSize) const \
	{	\
		floatSize = floatValueCount; \
		return floatValueCount != NOTOK;	\
	} \
	MAXON_METHOD Int32 GetTagPluginFlags() const \
	{	\
		return flags; \
	} \

//----------------------------------------------------------------------------------------
/// CustomDataTagClassInterface uses MeshAttributeClassInterface as a base interface and allows to add informations and functionality to the mesh attribute to be used as tag.
/// It mainly contains the information about the CustomDataTag registration, read/write, icons and the optional display implementation.
/// By using the MAXON_CUSTOMDATATAG macro, only the Read, Write and GetIcon methods need to be implemented.
///
/// @code
///	class VertexColorImpl : public Component<VertexColorImpl, CustomDataTagClassInterface>
///	{
///		MAXON_COMPONENT();
///		MAXON_CUSTOMDATATAG(ID_CUSTOMDATA_TAG_VC, "Vertex Color Tag"_s, ""_s, Id("net.maxon.mesh_misc.meshattibutedisplay.vertxecolor"), 0, 1, flags);
///
///	public:
///
///		...
///		MAXON_METHOD Result<void> Read(void* data, HyperFile* hf, Int32 level) const;
///
///		MAXON_METHOD Result<void> Write(const void* data, HyperFile* hf) const;
///
///		MAXON_METHOD Int32 GetIcon(Bool perPolyVertex) const;
///
///	};
/// @endcode
//----------------------------------------------------------------------------------------
class CustomDataTagClassInterface : MAXON_INTERFACE_BASES(MeshAttributeClassInterface)
{
	MAXON_INTERFACE(CustomDataTagClassInterface, MAXON_REFERENCE_CONST, "net.maxon.mesh_misc.interface.customdatattag")
public:

	//----------------------------------------------------------------------------------------
	/// Returns the Tag plugin ID to be registered with this implementation.
	/// @return												A unique plugin ID.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Int32 GetTagPluginId() const;

	//----------------------------------------------------------------------------------------
	/// Returns the Tag string name to be registered with this implementation.
	/// @return												A string that represent the tag in the interface.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD const String& GetTagPluginName() const;

	//----------------------------------------------------------------------------------------
	/// Returns the resource id for the Tag.
	/// @return												A string that represent the tag res ID.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD const String& GetResourceId() const;

	//----------------------------------------------------------------------------------------
	/// Returns the Tag level to be used as data versioning system.
	/// @return												The disk level.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Int32 GetTagPluginLevel() const;

	//----------------------------------------------------------------------------------------
	/// Get the Id of the display implementation or an empty Id if display is not implemented.
	/// @return												The id of the associated display implementation.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Id GetDisplayClassId()const;

	//----------------------------------------------------------------------------------------
	/// Returns if the datatype is compatible with the SDS interpolation.
	/// SDS implementations, both internal and OSD, are only able to interpolate float values.
	/// The floatSize allows to define how many values are used for each entry, for example a vector will have a floatSize = 3.
	/// @param[out] floatSize					The number of float values that the datatype contains.
	/// @return												True if this interface can be processed for SDS interpolations.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Bool IsSdsCompatible(Int32& floatSize) const;

	//----------------------------------------------------------------------------------------
	/// Reads a single data entry from a file.
	/// @param[in] data								The data pointer.
	/// @param[in] hf									The file handle to read.
	/// @param[in] level							The disk level.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Read(void* data, HyperFile* hf, Int32 level) const;

	//----------------------------------------------------------------------------------------
	/// Writes a single data entry to a fil.
	/// @param[in] data								The data pointer.
	/// @param[in] hf									The file handle to write on.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Write(const void* data, HyperFile* hf) const;

	//----------------------------------------------------------------------------------------
	/// Gets the icon id according to the data location (per vertex vs. per polyvertex).
	/// @param[in] perPolyVertex			If true the polyvertex icon id is returned.
	/// @return												The icon id or NOTOK if there is no icon.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Int32 GetIcon(Bool perPolyVertex) const;

	//----------------------------------------------------------------------------------------
	/// By default, all implementations provide a standard UI.
	/// Gets the default resource id in case a custom AM UI is not needed.
	/// @return												The description string identifier.
	//----------------------------------------------------------------------------------------
	MAXON_FUNCTION const String& GetDefaultResourceId() const;

	//----------------------------------------------------------------------------------------
	/// Returns the tag flags to be registered with this implementation.
	/// @return												The tag flgas.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Int32 GetTagPluginFlags() const;
};

#include "mesh_attribute_base1.hxx"

MAXON_REGISTRY(CustomDataTagClass, CustomDataTagClasses, "net.maxon.mesh_misc.registry.customdatatagclasses");

namespace CustomDataTagClasses
{
}

MAXON_REGISTRY(Class<CustomDataTagDisplayRef>, CustomDataTagDisplayClasses, "net.maxon.mesh_misc.registry.customdatatagdisplayclasses");

namespace CustomDataTagDisplayClasses
{
}

#include "mesh_attribute_base2.hxx"

//----------------------------------------------------------------------------------------
/// A simple wrapper class which contains a data pointer and a reference to the MeshAttribute implementation class.
/// Implements all the arithmetic operators to simplify usage independently of the data type itself.
//----------------------------------------------------------------------------------------
class MeshAttribute
{
public:

	MeshAttribute() = default;
	MeshAttribute(MeshAttributeClass cls, void* valuePtr) : _cls(cls), _valuePtr(valuePtr) {	}
	MeshAttribute(MeshAttributeClass cls, const void* valuePtr) : _cls(cls), _valuePtr(const_cast<void*>(valuePtr)) {	}
	MeshAttribute(const MeshAttribute& src, void* valuePtr) : _cls(src._cls), _valuePtr(valuePtr) {	}

	Bool operator ==(const MeshAttribute& b) const;
	Bool operator !=(const MeshAttribute& b) const;
	Bool operator <(const MeshAttribute& b) const;
	Bool operator >(const MeshAttribute& b) const;

	MeshAttribute operator +(const MeshAttribute& b) const;
	MeshAttribute operator -(const MeshAttribute& b) const;
	MeshAttribute operator *(const MeshAttribute& b) const;
	MeshAttribute operator *(Float value) const;
	MeshAttribute operator /(const MeshAttribute& b) const;
	MeshAttribute operator /(Float value) const;

	MeshAttribute operator +=(const MeshAttribute& b);
	MeshAttribute operator -=(const MeshAttribute& b);
	MeshAttribute operator *=(const MeshAttribute& b);
	MeshAttribute operator *=(Float value);
	MeshAttribute operator /=(const MeshAttribute& b);
	MeshAttribute operator /=(Float value);

	MeshAttributeClass 	_cls;
	void* 							_valuePtr = nullptr;
};

MAXON_DATATYPE(MeshAttribute, "net.maxon.mesh_misc.datatype.meshattribute");

} // namespace maxon

#endif // MESH_ATTRIBUTE_BASE_H__
