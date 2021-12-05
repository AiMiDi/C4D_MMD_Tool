/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef C4D_CUSTOMDATATYPE_H__
#define C4D_CUSTOMDATATYPE_H__

#include "ge_prepass.h"
#include "c4d_basedata.h"
#include "c4d_memory.h"
#include "c4d_customguidata.h"
#include "c4d_graphview_enum.h"

class String;
class HyperFile;
class AliasTrans;
class GeData;
class DescID;
class Description;
struct GV_VALUE_HANDLER;

/// @addtogroup CUSTOMDATATYPE_INFO
/// @ingroup group_enumeration
/// @{
#define CUSTOMDATATYPE_INFO_HASSUBDESCRIPTION					(1 << 0)										///< The data type has additional channels, added by CustomDataTypeClass::_GetDescription.
#define CUSTOMDATATYPE_INFO_NEEDDATAFORSUBDESC				(1 << 1)										///< Some data types have an 'easy to calculate' sub-description.\n
																																									///< For instance a vector always has @em 3 components (X/Y/Z), similar to matrices, colors etc.\n
																																									///< On the other side there are datatypes like Gradients that have a variable number of sub-description parameters (for every needle). These types need the actual data to compute their sub-descriptions.
#define CUSTOMDATATYPE_INFO_TOGGLEDISPLAY							(1 << 2)										///< Show the display toggle.
#define CUSTOMDATATYPE_INFO_DONTREGISTERGVTYPE				(1 << 3)										///< Do not register a Graph View type.
#define CUSTOMDATATYPE_INFO_SUBDESCRIPTIONDISABLEGUI	(1 << 4)										///< Hide GUI when showing sub-description.
#define CUSTOMDATATYPE_INFO_UNDOSAMECUSTOMGUI					(1 << 5)										///< If set, the Attribute Manager tracks every undo of this element.\n
																																									///< If it is not set and the user makes several subsequent (not interrupted by anything else) changes, they will all be restored by a single undo.\n
																																									///< Float fields are such an example (of the flag not being set); if the up/down spinner is pressed @em 100 times just a single undo will be created.\n
																																									///< Gradients, however, have the bit set, so that they generate undo for every change (e.g. needles).
#define CUSTOMDATATYPE_INFO_HASSUBDESCRIPTION_NOANIM	((1 << 0) | (1 << 6))				///< Same as @ref CUSTOMDATATYPE_INFO_HASSUBDESCRIPTION but with no animation.
#define CUSTOMDATATYPE_INFO_LOADSAVE									(1 << 7)										///< The custom data type can be loaded/saved from the Attribute Manager.
#define CUSTOMDATATYPE_INFO_NO_GUI_COPY								(1 << 8)										///< @markPrivate
/// @}

//----------------------------------------------------------------------------------------
/// Base class for custom data types.
//----------------------------------------------------------------------------------------
struct CustomDataType
{
};

//----------------------------------------------------------------------------------------
/// Used to access custom data types in Graph View @c void* variables:
/// @code
/// SplineData* spline = static_cast<SplineData*>(static_cast<GvHelper*>(src)->data[cpu_id]);
/// @endcode
//----------------------------------------------------------------------------------------
struct GvHelper
{
	CustomDataType** data;			///< Points to an array of CustomDataType pointers.
};

//----------------------------------------------------------------------------------------
/// The base class for data types with Alloc() and Free() for use in libraries. Pass the public data type as template parameter.
/// @note The advantage of this class is to not need to provide library functions for Alloc() and Free(), as the internal and external type will share this functionality.
//----------------------------------------------------------------------------------------
template <class X> struct iCustomDataType : public CustomDataType
{
	//----------------------------------------------------------------------------------------
	/// @allocatesAN{X data type}
	/// @return												@allocReturn{X data type}
	//----------------------------------------------------------------------------------------
	static X* Alloc() { return NewObjClear(X); }
	//----------------------------------------------------------------------------------------
	/// @destructsAlloc{X data types}
	/// @param[in,out] data						@theToDestruct{X data type}
	//----------------------------------------------------------------------------------------
	static void Free(X*& data) { DeleteObj(data); }
};

//----------------------------------------------------------------------------------------
/// A data class for creating custom data types.\n
/// These can be used in descriptions and container just like built-in data types.
/// Use RegisterCustomDataTypePlugin() to register a custom data type plugin.
//----------------------------------------------------------------------------------------
class CustomDataTypeClass : public BaseData
{
	Int32 defaultconversiontype;
	GV_VALUE_HANDLER* valuehandler;

public:
	//----------------------------------------------------------------------------------------
	/// Default constructor.
	/// @since R17.032
	//----------------------------------------------------------------------------------------
	CustomDataTypeClass() : defaultconversiontype(0), valuehandler(nullptr) { }

	//----------------------------------------------------------------------------------------
	/// Called to get the plugin ID of the custom data type.
	/// @return												@uniquePluginID
	//----------------------------------------------------------------------------------------
	virtual Int32 GetId() = 0;

	//----------------------------------------------------------------------------------------
	/// Called to get the plugin ID used for the custom data type.
	/// @note Normally it is not needed to override this. By default it returns GetId().
	/// @return												@uniquePluginID
	//----------------------------------------------------------------------------------------
	virtual Int32 GetDataID();

	//----------------------------------------------------------------------------------------
	/// Called to get the plugin ID used for Graph View values.
	/// @return												@uniquePluginID
	//----------------------------------------------------------------------------------------
	virtual Int32 GetValueID();

	//----------------------------------------------------------------------------------------
	/// Called to allocate an instance of the internal data type class and return it.
	/// @return												A custom data type instance.
	//----------------------------------------------------------------------------------------
	virtual CustomDataType* AllocData() = 0;

	//----------------------------------------------------------------------------------------
	/// Called to free an instance of the custom data type.
	/// @param[in,out] data						The custom data type instance to free.
	//----------------------------------------------------------------------------------------
	virtual void FreeData(CustomDataType* data) = 0;

	//----------------------------------------------------------------------------------------
	/// Called to copy an instance of the custom data type. Copy the data from @formatParam{src} to @formatParam{dest}.
	/// @param[in] src								The source custom data type.
	/// @param[out] dest							The destination custom data type.
	/// @param[in] aliastrans					An alias translator for the operation. Can be @formatConstant{nullptr}. @callerOwnsPointed{alias translator}
	/// @return												@trueIfOtherwiseFalse{the custom data type was copied}
	//----------------------------------------------------------------------------------------
	virtual Bool CopyData(const CustomDataType* src, CustomDataType* dest, AliasTrans* aliastrans) = 0;

	//----------------------------------------------------------------------------------------
	/// Called to compare a pair of custom data types.
	/// @param[in] d1									The first data.
	/// @param[in] d2									The second data.
	/// @return												The result of the comparison:
	///																@code
	///																if (d1 == d2) return 0;
	///																if (d1 < d2) return -1;
	///																if (d1 > d2) return 1;
	///																@endcode
	//----------------------------------------------------------------------------------------
	virtual Int32 Compare(const CustomDataType* d1, const CustomDataType* d2) = 0;

	//----------------------------------------------------------------------------------------
	/// Called to write the custom data type to a file.
	/// @param[in] d									The custom data type instance to write. @cinemaOwnsPointed{data}
	/// @param[in] hf									The hyper file to write the custom data type to. @cinemaOwnsPointed{hyper file}
	/// @return												@trueIfOtherwiseFalse{the custom data type was written successfully}
	//----------------------------------------------------------------------------------------
	virtual Bool WriteData(const CustomDataType* d, HyperFile* hf) = 0;

	//----------------------------------------------------------------------------------------
	/// Called to read the custom data type from a file.
	/// @param[in,out] d							The custom data type instance to read. @cinemaOwnsPointed{data}
	/// @param[in] hf									The hyper file to read the custom data type from. @cinemaOwnsPointed{hyper file}
	/// @param[in] level							The plugin level is similar to a version number. The default level is @em 0.\n
	/// 															Increase this for new revisions of a plugin to allow for forward and backward compatibility.\n\n
	/// 															As an example you may have updated a plugin. If you now need to write additional information for new settings or changed types for old settings increase the level.\n
	/// 															During loading either a @em 0 is passed (if the file was written by the old plugin) or @em 1 (if the file was written by the new plugin). This allows to easily write/read new values.\n
	/// 															For forward and backward compatibility to work any existing read order from a given level must not be changed. @C4D skips any new settings automatically if they have not been read.
	/// @return												@trueIfOtherwiseFalse{the custom data type was read successfully}
	//----------------------------------------------------------------------------------------
	virtual Bool ReadData(CustomDataType* d, HyperFile* hf, Int32 level) = 0;

	//----------------------------------------------------------------------------------------
	/// Called to get the symbol to use in resource files, for example @em "GRADIENT".\n
	/// @note Only 7-bit ASCII characters are allowed, hence the @em Char type.
	/// @return												A pointer to a global <tt>const Char*</tt> string with the resource symbol.
	//----------------------------------------------------------------------------------------
	virtual const Char* GetResourceSym() = 0;

	//----------------------------------------------------------------------------------------
	/// Called to get the properties that the custom data type accepts in resource files.
	/// @see CustomProperty.
	/// @return												A pointer to a global array of CustomProperty elements, ended with a @ref CUSTOMTYPE::END property:
	/// @code
	/// CustomProperty bitmapbuttonprops[] =
	/// {
	/// 	{ CUSTOMTYPE::FLAG, BITMAPBUTTON_BORDER, "BORDER" },
	/// 	{ CUSTOMTYPE::FLAG, BITMAPBUTTON_BUTTON, "BUTTON" },
	/// 	{ CUSTOMTYPE::END, 0, nullptr }
	/// };
	/// @endcode
	//----------------------------------------------------------------------------------------
	virtual CustomProperty* GetProperties();

	//----------------------------------------------------------------------------------------
	/// Called to provide default properties for the custom data type.\n
	/// These properties will be used if the user does not specify anything else.\n
	/// It is common to add @ref DESC_ANIMATE and @ref DESC_CUSTOMGUI to the default properties:
	/// @code
	/// virtual void GetDefaultProperties(BaseContainer &data)
	/// {
	/// 	data.SetInt32(GRADIENTPROPERTY_ALPHA_WITH_COLOR, false);
	/// 	data.SetInt32(GRADIENTPROPERTY_ALPHA, false);
	/// 	data.SetInt32(DESC_ANIMATE, DESC_ANIMATE_ON);
	/// 	data.SetInt32(DESC_CUSTOMGUI, CUSTOMGUI_GRADIENT);
	/// }
	/// @endcode
	/// @param[in] data								The container to fill with the default properties.
	//----------------------------------------------------------------------------------------
	virtual void GetDefaultProperties(BaseContainer& data);

	//----------------------------------------------------------------------------------------
	/// Called to retrieve a pointer to a global array representing the data types that the custom data type can be converted from.\n
	/// @note	Include the custom data type ID, since it is a possible conversion.\n
	///				Here is an example:
	///				@code
	///				static Int32 MyDataTypeConversionsFrom[] =
	///				{
	///					MYDATATYPE_ID,
	///					DA_STRING,
	///					DA_LONG,
	///				};
	///
	///				Int32 MyDataTypeClass::GetConversionsFrom(Int32*& table)
	///				{
	///					table = MyDataTypeConversionsFrom;
	///					return CUSTOMGUIARRAY_SIZE(MyDataTypeConversionsFrom);
	///				}
	///				@endcode
	/// @param[out] table							Set this to point to the custom data type conversion from table.
	/// @return												The size of the assigned conversion from table.\n
	/// 															Use @ref CUSTOMGUIARRAY_SIZE for convenience. See example above.
	//----------------------------------------------------------------------------------------
	virtual Int32 GetConversionsFrom(Int32*& table);

	//----------------------------------------------------------------------------------------
	/// Converts the Graph View data given by @formatParam{src_type} and @formatParam{src}[@formatParam{cpu_id}] to the custom data type in @formatParam{dst}.
	/// @param[in] src_type						The source type. One of the IDs given by GetConversionsFrom().
	/// @param[in] src								The source data array. Depends on @formatParam{src_type}. @cinemaOwnsPointed{array}
	/// @param[in] cpu_id							The CPU index, i.e. the position in the @formatParam{src} array.
	/// @param[out] dst								The destination custom data type. Points to an instance of the internal data type. Write the converted data to this object. @cinemaOwnsPointed{data}
	/// @return												The conversion result: @enumerateEnum{GvError}
	//----------------------------------------------------------------------------------------
	virtual GvError ConvertFromGv(Int32 src_type, const void* const src, Int32 cpu_id, CustomDataType* dst);

	//----------------------------------------------------------------------------------------
	/// Called to retrieve a pointer to a global array representing the data types that the custom data type can be converted to.\n
	/// @note It is not need to include the custom data type ID.
	///
	/// Here is an example:
	/// @code
	/// Int32 MyDataTypeConversionsTo[] =
	/// {
	/// 	DA_STRING,
	/// 	DA_LONG,
	/// };
	///
	/// Int32 MyDataTypeClass::GetConversionsTo(Int32 *&table)
	/// {
	/// 	table = MyDataTypeConversionsTo;
	/// 	return CUSTOMGUIARRAY_SIZE(MyDataTypeConversionsTo);
	/// }
	/// @endcode
	/// @param[out] table							Set this to point to the custom data type conversion to table.
	/// @return												The size of the assigned conversion to table.\n
	/// 															Use @ref CUSTOMGUIARRAY_SIZE for convenience. See example above.
	//----------------------------------------------------------------------------------------
	virtual Int32 GetConversionsTo(Int32*& table);

	//----------------------------------------------------------------------------------------
	/// Called to convert the custom data type in @formatParam{src} to the Graph View data given by @formatParam{dst_type} and @formatParam{dst}[@formatParam{cpu_id}].
	/// @param[in] dst_type						The destination type. One of the IDs given by GetConversionsTo().
	/// @param[in] src								The source custom data type. Points to an instance of the internal data type. @cinemaOwnsPointed{data}
	/// @param[out] dst								The destination data array. Depends on @formatParam{dst_type}. Write the converted data to this object. @cinemaOwnsPointed{array}
	/// @param[in] cpu_id							The CPU index, i.e. the position in the @formatParam{dst} array.
	/// @return												The conversion result: @enumerateEnum{GvError}
	//----------------------------------------------------------------------------------------
	virtual GvError ConvertToGv(Int32 dst_type, const CustomDataType* src, void* dst, Int32 cpu_id);

	//----------------------------------------------------------------------------------------
	/// Called to convert the custom data type in @formatParam{src} to GeData @formatParam{dst}.
	/// @param[in] dst_type						The destination type. One of the IDs given by GetConversionsTo().
	/// @param[in] src								The source custom data type. Points to an instance of the internal data type. @cinemaOwnsPointed{data}
	/// @param[out] dst								The destination data. Depends on @formatParam{dst_type}. Write the converted data to this object. @cinemaOwnsPointed{data}
	/// @return												The conversion result: @enumerateEnum{GvError}
	//----------------------------------------------------------------------------------------
	virtual GvError ConvertToGeData(Int32 dst_type, const CustomDataType* src, GeData& dst);

	//----------------------------------------------------------------------------------------
	/// Called to retrieve the valid calculations for the custom data type.
	/// @note Used for calls to Calculate().
	/// @return												A combination of the following: @enumerateEnum{GvValueFlags}
	//----------------------------------------------------------------------------------------
	virtual GvValueFlags GetCalculationFlags();

	//----------------------------------------------------------------------------------------
	/// Called to carry out a @formatParam{calculation}.
	/// @param[in] calculation				The calculation: @enumerateEnum{GvValueFlags}
	/// @param[in] src1								The first source custom data type. Depends on @formatParam{calculation}. @cinemaOwnsPointed{data}
	/// @param[in] src2								The second source custom data type. Depends on @formatParam{calculation}. @cinemaOwnsPointed{data}
	/// @param[out] dst								The destination custom data type. Depends on @formatParam{calculation}. @cinemaOwnsPointed{data}
	/// @param[in] parm1							A ::Float parameter. Depends on @formatParam{calculation}.
	/// @return												The calculation result: @enumerateEnum{GvError}
	//----------------------------------------------------------------------------------------
	virtual GvError Calculate(Int32 calculation, const CustomDataType* src1, const CustomDataType* src2, CustomDataType* dst, Float parm1);

	//----------------------------------------------------------------------------------------
	/// Called to retrieve the internal GV_VALUE_HANDLER struct for the custom data type.
	/// @warning It is normally never needed to override this method.
	/// @return												The internal GV_VALUE_HANDLER struct.
	//----------------------------------------------------------------------------------------
	virtual GV_VALUE_HANDLER* GetGvValueHandler();

	//----------------------------------------------------------------------------------------
	/// Called to convert the data in @formatParam{src} to the Graph View data given by @formatParam{dst}[@formatParam{cpu_id}].
	/// @warning It is normally never needed to override this method.
	/// @param[in] src								The source data. @cinemaOwnsPointed{data}
	/// @param[out] dst								The destination data array. @cinemaOwnsPointed{array}
	/// @param[in] cpu_id							The CPU index, i.e. the position in the @formatParam{dst} array.
	/// @return												@trueIfOtherwiseFalse{the conversion was successful}
	//----------------------------------------------------------------------------------------
	virtual Bool ConvertGeDataToGv(const GeData& src, void* dst, Int32 cpu_id);

	//----------------------------------------------------------------------------------------
	/// Called to convert the internal data in @formatParam{src} as an array referenced by @formatParam{cpu_id} to a GeData in @formatParam{dst}.
	/// @warning It is normally never needed to override this method.
	/// @param[in] src								The source data array. @cinemaOwnsPointed{array}
	/// @param[in] cpu_id							The CPU index, i.e. the position in the @formatParam{src} array.
	/// @param[out] dst								The destination data. @cinemaOwnsPointed{data}
	/// @return												@trueIfOtherwiseFalse{the conversion was successful}
	//----------------------------------------------------------------------------------------
	virtual Bool ConvertGvToGeData(const void* const src, Int32 cpu_id, GeData& dst);

	//----------------------------------------------------------------------------------------
	/// Dummy virtual method to get the virtual warning.
	/// @return												Always @formatConstant{false}.
	//----------------------------------------------------------------------------------------
	virtual Bool GetDescription() { return false; }

	//----------------------------------------------------------------------------------------
	/// Called to add sub-parameters to the description for the custom data type.\n
	/// Modify the passed description @formatParam{res} object as needed, set the appropriate @formatParam{flags} and then make sure to include a call to the parent at the end:
	/// @code
	/// return SUPER::GetDescription(data, description, flags, parentdescription);
	/// @endcode
	/// @param[in] data								The custom data type to get the description for. Points to an instance of the internal data type. @cinemaOwnsPointed{data}
	/// @param[out] res								The description to add the parameters to.
	/// @param[in,out] flags					The flags for the description operation: @enumerateEnum{DESCFLAGS_DESC}
	/// @param[in] parentdescription	The description container for the parent's description, encoded as described in Description.
	/// @param[out] singledescid			@markPrivate
	/// @return												@trueIfOtherwiseFalse{successful} It is recommended to include a call to the parent function as last return.
	//----------------------------------------------------------------------------------------
	virtual Bool _GetDescription(const CustomDataType* data, Description& res, DESCFLAGS_DESC& flags, const BaseContainer& parentdescription, DescID* singledescid);

	//----------------------------------------------------------------------------------------
	/// Called to override the reading of parameters.\n
	/// Modify the passed @formatParam{t_data} if the right @formatParam{id} was provided, and set the appropriate @formatParam{flags}. Then make sure to include a call to the parent at the end:
	/// @code
	/// return SUPER::GetParameter(data, id, t_data, flags);
	/// @endcode
	/// @param[in] data								The custom data type to get the parameters for. Points to an instance of the internal data type. @cinemaOwnsPointed{data}
	/// @param[in] id									The ID of the parameter.
	/// @param[out] t_data						The current data for the parameter.
	/// @param[in,out] flags					The flags for the description operation: @enumerateEnum{DESCFLAGS_DESC}
	/// @return												@trueIfOtherwiseFalse{successful} It is recommended to include a call to the parent function as last return.
	//----------------------------------------------------------------------------------------
	virtual Bool GetParameter(const CustomDataType* data, const DescID& id, GeData& t_data, DESCFLAGS_GET& flags);

	//----------------------------------------------------------------------------------------
	/// Called to override the writing of parameters.\n
	/// Read the passed @formatParam{t_data} if the right @formatParam{id} was provided, store the data, and set the appropriate @formatParam{flags}. Then make sure to include a call to the parent at the end:
	/// @code
	/// return SUPER::SetDParameter(data, id, t_data, flags);
	/// @endcode
	/// @param[in] data								The data to set the parameter for. Points to an instance of the internal data type. @cinemaOwnsPointed{data}
	/// @param[in] id									The ID of the parameter.
	/// @param[out] t_data						The data to write.
	/// @param[in,out] flags					The flags for the description operation: @enumerateEnum{DESCFLAGS_DESC}
	/// @return												@trueIfOtherwiseFalse{successful} It is recommended to include a call to the parent function as last return.
	//----------------------------------------------------------------------------------------
	virtual Bool SetDParameter(CustomDataType* data, const DescID& id, const GeData& t_data, DESCFLAGS_SET& flags);

	//----------------------------------------------------------------------------------------
	/// Called to decide which parameters should be enabled or disabled.\n
	/// Read the passed @formatParam{t_data} if the right @formatParam{id} was provided, and return @formatConstant{true} to enable the parameter or @formatConstant{false} to disable it depending on the value. Then make sure to include a call to the parent at the end:
	/// @code
	/// return SUPER::GetEnabling(data, id, t_data, flags, itemdesc);
	/// @endcode
	/// @param[in] data								The data to enable or disable. Points to an instance of the internal data type. @cinemaOwnsPointed{data}
	/// @param[in] id									The ID of the parameter.
	/// @param[in] t_data							The current data for the parameter.
	/// @param[in] flags							Not used.
	/// @param[in] itemdesc						The description, encoded to a container as described in Description.
	/// @return												@trueIfOtherwiseFalse{the parameter should be enabled} It is recommended to include a call to the parent function as last return.
	//----------------------------------------------------------------------------------------
	virtual Bool GetEnabling(const CustomDataType* data, const DescID& id, const GeData& t_data, DESCFLAGS_ENABLE& flags, const BaseContainer* itemdesc);

	//----------------------------------------------------------------------------------------
	/// Override this method to animate the custom data type.\n
	/// Set @formatParam{res} to @formatParam{t_data1}*@formatParam{mix} + @formatParam{t_data2}*(1-@formatParam{mix}) in a way that makes sense for the custom data type.
	/// @param[in] res								The animated value.
	/// @param[in] t_data1						The first value.
	/// @param[in] t_data2						The second value.
	/// @param[in] mix								The mixing factor.
	/// @param[in] flags							Not used.
	/// @return												@trueIfOtherwiseFalse{the data was animated}
	//----------------------------------------------------------------------------------------
	virtual Bool InterpolateKeys(GeData& res, const GeData& t_data1, const GeData& t_data2, Float mix, Int32 flags);

	//----------------------------------------------------------------------------------------
	/// Called to let validate the values of data with the settings in bc.\n
	/// Modify data accordingly so that it is valid.
	/// @param[in] bc									The settings container.
	/// @param[in,out] data						The data value to check.
	//----------------------------------------------------------------------------------------
	virtual void CheckData(const BaseContainer& bc, GeData& data);
};

struct CUSTOMDATATYPEPLUGIN;

//----------------------------------------------------------------------------------------
/// A data class for creating custom data types' aliases.\n
/// These can be used in descriptions as a shortcut for a custom data type with certain options, for example like @em VECTOR and @em COLOR.\n
/// Use RegisterResourceDataTypePlugin() to register a resourse data type plugin.
//----------------------------------------------------------------------------------------
class ResourceDataTypeClass : public BaseData
{
	Int32 datatypeid;
	CUSTOMDATATYPEPLUGIN* datatype;

public:
	//----------------------------------------------------------------------------------------
	/// Constructor. Pass the ID and plugin structure for the custom data type to create an alias for.\n
	/// The easiest way to get the plugin structure is to call FindCustomDataTypePlugin(), for example:
	/// @code
	/// ResourceDataTypeClass(MY_CUSTOM_DATA_TYPE, FindCustomDataTypePlugin(MY_CUSTOM_DATA_TYPE));
	/// @endcode
	/// @param[in] datatypeid					The custom data type ID.
	/// @param[in] datatype						The custom data type plugin structure.
	//----------------------------------------------------------------------------------------
	ResourceDataTypeClass(Int32 datatypeid, CUSTOMDATATYPEPLUGIN* datatype);

	//----------------------------------------------------------------------------------------
	/// Called to get the plugin ID of the resource data type.
	/// @return												@uniquePluginID
	//----------------------------------------------------------------------------------------
	virtual Int32 GetId() = 0;

	//----------------------------------------------------------------------------------------
	/// Called to get the plugin ID of the custom data type that this is an alias for.
	/// @note By default returns the value passed to the constructor.
	/// @return												The custom data type ID for the resource type.
	//----------------------------------------------------------------------------------------
	virtual Int32 GetCustomDataType();

	//----------------------------------------------------------------------------------------
	/// Called to get the internal plugin structure of the custom data type that this is an alias for.
	/// @note By default returns the value passed to the constructor.
	/// @return												The plugin structure of the custom data of the resource type. @cinemaOwnsPointed{plugin structure}
	//----------------------------------------------------------------------------------------
	virtual CUSTOMDATATYPEPLUGIN* GetCustomDataTypePlugin();

	//----------------------------------------------------------------------------------------
	/// Called to provide default properties for the data type.\n
	/// These properties will be used if the user does not specify anything else.\n
	/// It is common to add @ref DESC_ANIMATE and @ref DESC_CUSTOMGUI to the default properties:
	/// @code
	/// virtual void GetDefaultProperties(BaseContainer &data)
	/// {
	/// 	data.SetInt32(GRADIENTPROPERTY_ALPHA_WITH_COLOR, false);
	/// 	data.SetInt32(GRADIENTPROPERTY_ALPHA, false);
	/// 	data.SetInt32(DESC_ANIMATE, DESC_ANIMATE_ON);
	/// 	data.SetInt32(DESC_CUSTOMGUI, CUSTOMGUI_GRADIENT);
	/// }
	/// @endcode
	/// @note This is normally the very reason for using ResourceDataTypeClass.
	/// @param[in] data								Filled with the default properties for the data type in the resource.
	//----------------------------------------------------------------------------------------
	virtual void GetDefaultProperties(BaseContainer& data);

	//----------------------------------------------------------------------------------------
	/// Called to get the symbol to use in resource files, for example @em "GRADIENT".
	/// @note Only 7-bit ASCII characters are allowed, hence the @em Char type.
	/// @return												A pointer to a global <tt>const Char*</tt> string with the resource symbol.
	//----------------------------------------------------------------------------------------
	virtual const Char* GetResourceSym();

	//----------------------------------------------------------------------------------------
	/// Called to get the properties that the data type accepts in resource files.
	/// @see CustomProperty.
	/// @return												A pointer to a global array of CustomProperty elements, ended with a @ref CUSTOMTYPE::END property:
	/// @code
	/// CustomProperty bitmapbuttonprops[] =
	/// {
	/// 	{ CUSTOMTYPE::FLAG, BITMAPBUTTON_BORDER, "BORDER" },
	/// 	{ CUSTOMTYPE::FLAG, BITMAPBUTTON_BUTTON, "BUTTON" },
	/// 	{ CUSTOMTYPE::END, 0, nullptr }
	/// };
	/// @endcode
	//----------------------------------------------------------------------------------------
	virtual CustomProperty* GetProperties();

	//----------------------------------------------------------------------------------------
	/// Called to add sub-parameters to the description for the data.\n
	/// Modify the passed description @formatParam{res} object as needed, set the appropriate @formatParam{flags} and then make sure to include a call to the parent at the end:
	/// @code
	/// return SUPER::GetDescription(data, description, flags, parentdescription);
	/// @endcode
	/// @param[in] data								The custom data type to get the description for. Points to an instance of the internal data type. @cinemaOwnsPointed{data}
	/// @param[out] res								The description to add the parameters to.
	/// @param[in,out] flags					The flags for the description operation: @enumerateEnum{DESCFLAGS_DESC}
	/// @param[in] parentdescription	The description container for the parent's description, encoded as described in Description.
	/// @param[out] singledescid			@markPrivate
	/// @return												@trueIfOtherwiseFalse{successful} It is recommended to include a call to the parent function as last return.
	//----------------------------------------------------------------------------------------
	virtual Bool GetDescription(const CustomDataType* data, Description& res, DESCFLAGS_DESC& flags, const BaseContainer& parentdescription, DescID* singledescid);

	//----------------------------------------------------------------------------------------
	/// Called to let validate the values of data with the settings in bc.\n
	/// Modify data accordingly so that it is valid.
	/// @param[in] bc									The settings container.
	/// @param[in,out] data						The data value to check.
	//----------------------------------------------------------------------------------------
	virtual void CheckData(const BaseContainer& bc, GeData& data);
};

//----------------------------------------------------------------------------------------
/// Registers a custom data type plugin.
/// @param[in] str								The name of the plugin.
/// @param[in] info								The custom data type plugin info flags: @enumerateEnum{CUSTOMDATATYPE_INFO} @enumerateEnum{PLUGINFLAG}
/// @param[in] dat								An instance for the custom data type plugin. @C4D takes over the ownership of the pointed data instance.
/// @param[in] disclevel					The plugin level is similar to a version number. The default level is @em 0.\n
/// 															Increase this for new revisions of a plugin to allow for forward and backward compatibility.\n\n
/// 															As an example you may have updated a plugin. If you now need to write additional information for new settings or changed types for old settings increase the level.\n
/// 															During loading either a @em 0 is passed (if the file was written by the old plugin) or @em 1 (if the file was written by the new plugin). This allows to easily write/read new values.\n
/// 															For forward and backward compatibility to work any existing read order from a given level must not be changed. @C4D skips any new settings automatically if they have not been read.\n\n
/// 															@formatParam{disklevel} is only useful if variables are written/read in @ref CustomDataTypeClass::WriteData/@ref CustomDataTypeClass::ReadData.
/// @return												@trueIfOtherwiseFalse{the custom data type plugin was registered}
//----------------------------------------------------------------------------------------
Bool RegisterCustomDataTypePlugin(const maxon::String& str, Int32 info, CustomDataTypeClass* dat, Int32 disclevel);

//----------------------------------------------------------------------------------------
/// Registers a resource data type plugin.
/// @param[in] str								The name of the plugin.
/// @param[in] info								The resource data type plugin info flags: @enumerateEnum{PLUGINFLAG}
/// @param[in] dat								An instance for the resource data type plugin. @C4D takes over the ownership of the pointed data instance.
/// @param[in] disclevel					The plugin level is similar to a version number. The default level is @em 0.\n
/// 															Increase this for new revisions of a plugin to allow for forward and backward compatibility.\n\n
/// 															As an example you may have updated a plugin. If you now need to write additional information for new settings or changed types for old settings increase the level.\n
/// 															During loading either a @em 0 is passed (if the file was written by the old plugin) or @em 1 (if the file was written by the new plugin). This allows to easily write/read new values.\n
/// 															For forward and backward compatibility to work any existing read order from a given level must not be changed. @C4D skips any new settings automatically if they have not been read.\n\n
/// 															@formatParam{disklevel} is only useful if variables are written/read in @ref CustomDataTypeClass::WriteData/@ref CustomDataTypeClass::ReadData.
/// @return												@trueIfOtherwiseFalse{the resource data type plugin was registered}
//----------------------------------------------------------------------------------------
Bool RegisterResourceDataTypePlugin(const maxon::String& str, Int32 info, ResourceDataTypeClass* dat, Int32 disclevel);

#endif // C4D_CUSTOMDATATYPE_H__
