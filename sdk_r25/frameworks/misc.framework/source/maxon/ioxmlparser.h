#ifndef IOXMLPARSER_H__
#define IOXMLPARSER_H__

#include "maxon/registry.h"
#include "maxon/url.h"


namespace maxon
{

/// @addtogroup IO
/// @{

//----------------------------------------------------------------------------------------
/// XML node/property object
//----------------------------------------------------------------------------------------
class IoXmlNodeInterface
{
	MAXON_INTERFACE_NONVIRTUAL(IoXmlNodeInterface, MAXON_REFERENCE_NORMAL, "net.maxon.interface.ioxmlnode");

public:
	static MAXON_METHOD IoXmlNodeInterface* Alloc(MAXON_SOURCE_LOCATION_DECLARATION);

// TODO: (Ole) doesn't work currently with references, we'd need something like ConstIoXmlNodeRef
	/// @MAXON_ANNOTATION{refclass=false}
	MAXON_METHOD const IoXmlNodeInterface* GetPrev() const;
	/// @MAXON_ANNOTATION{refclass=false}
	MAXON_METHOD const IoXmlNodeInterface* GetNext() const;
	/// @MAXON_ANNOTATION{refclass=false}
	MAXON_METHOD const IoXmlNodeInterface* GetUp() const;
	/// @MAXON_ANNOTATION{refclass=false}
	MAXON_METHOD const IoXmlNodeInterface* GetDown() const;

	//----------------------------------------------------------------------------------------
	/// Returns the previous object.
	/// @return												Previous object or nullptr if non-existent.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD IoXmlNodeInterface* GetPrev();

	//----------------------------------------------------------------------------------------
	/// Returns the next object.
	/// @return												Next object or nullptr if non-existent.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD IoXmlNodeInterface* GetNext();

	//----------------------------------------------------------------------------------------
	/// Returns the parent object.
	/// @return												Parent object or nullptr if non-existent.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD IoXmlNodeInterface* GetUp();

	//----------------------------------------------------------------------------------------
	/// Returns the child object.
	/// @return												Child object or nullptr if non-existent.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD IoXmlNodeInterface* GetDown();

	//----------------------------------------------------------------------------------------
	/// Returns the XML name property.
	/// @return												Name of this node.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD const String& GetName() const;

	//----------------------------------------------------------------------------------------
	/// Returns the XML value property.
	/// @return												Value of this node.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD const String& GetValue() const;

	//----------------------------------------------------------------------------------------
	/// Returns the XML attribute property.
	/// @return												Attribute of this node.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD const String& GetAttributes() const;

	//----------------------------------------------------------------------------------------
	/// Reads an XML 32-bit integer value.
	/// @param[out] val								The variable that will be filled with the XML value.
	/// @return												True if the value was properly defined.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> GetInt(Int32& val) const;

	//----------------------------------------------------------------------------------------
	/// Reads an XML 32-bit unsigned integer value.
	/// @param[out] val								The variable that will be filled with the XML value.
	/// @return												True if the value was properly defined.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> GetUInt(UInt32& val) const;

	//----------------------------------------------------------------------------------------
	/// Reads an XML 64-bit integer value.
	/// @param[out] val								The variable that will be filled with the XML value.
	/// @return												True if the value was properly defined.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> GetInt(Int64& val) const;

	//----------------------------------------------------------------------------------------
	/// Reads an XML 64-bit unsigned integer value.
	/// @param[out] val								The variable that will be filled with the XML value.
	/// @return												True if the value was properly defined.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> GetUInt(UInt64& val) const;

	//----------------------------------------------------------------------------------------
	/// Reads an XML floating point value.
	/// @param[out] val								The variable that will be filled with the XML value.
	/// @return												True if the value was properly defined.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> GetFloat(Float& val) const;

	//----------------------------------------------------------------------------------------
	/// Add a child to the current node. The child will be added at the end of the child chain.
	/// @param[in] strName						Name to set.
	/// @return												The new child node or nullptr in case of not enough memory.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD IoXmlNodeInterface* AddChild(const String& strName);

	//----------------------------------------------------------------------------------------
	/// Removes a node.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void Remove();

	//----------------------------------------------------------------------------------------
	/// Sets the XML name property.
	/// Keep in mind that you need to follow XML naming rules:
	/// http://www.w3schools.com/xml/xml_elements.asp.
	/// @param[in] strName						Name to set.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void SetName(const String& strName);

	//----------------------------------------------------------------------------------------
	/// Sets the XML attribute property.
	/// See more here: http://www.w3schools.com/xml/xml_attributes.asp.
	/// @param[in] strAttribute				Attribute to set.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void SetAttribute(const String& strAttribute);

	//----------------------------------------------------------------------------------------
	/// Sets the XML value property.
	/// @param[in] strValue						Value to set.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void SetValue(const String& strValue);

	//----------------------------------------------------------------------------------------
	/// Sets the XML value property.
	/// @param[in] strValue						C-String to set.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void SetValue(const Char* strValue);
};

class IoXmlNodeRef;

//----------------------------------------------------------------------------------------
/// XML parser class. Use this class to read an XML file into memory or write an XML file to disc.
//----------------------------------------------------------------------------------------
class IoXmlParser
{
	MAXON_INTERFACE_NONVIRTUAL(IoXmlParser, MAXON_REFERENCE_NONE, "net.maxon.interface.ioxmlparser");

public:
	//----------------------------------------------------------------------------------------
	/// Reads an XML document and transforms it into a memory representation.
	/// @param[in] xmlFile						Input path of the file.
	/// @param[out] line							Line number in which an error occurred. This value will be zero if error is not XMLERROR::PARSE.
	/// @return												Root node of the read XML document or nullptr in case of an error.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<IoXmlNodeInterface*> ReadDocument(const Url& xmlFile, Int& line);

	//----------------------------------------------------------------------------------------
	/// Reads an XML document and transforms it into a memory representation.
	/// @param[in] xmlFile						Input memory block.
	/// @param[in] length							Length of the input block.
	/// @param[out] line							Line number in which an error occurred. This value will be zero if error is not XMLERROR::PARSE.
	/// @return												Root node of the read XML document or nullptr in case of an error.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<IoXmlNodeInterface*> ReadDocument(const Char* xmlFile, Int length, Int& line);

	//----------------------------------------------------------------------------------------
	/// Writes an XML document.
	/// @param[in] file								Output path of the file.
	/// @param[in] rootNode						Root node of the XML document in memory.
	/// @param[in] tabs								If true a tab stop will be written instead of two spaces for indentation.
	/// @param[in] header							Can be nullptr. If provided, this text will be written as header (the first line) instead of the regular header.
	/// @return												Success of operation.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> WriteDocument(const Url& file, const IoXmlNodeRef& rootNode, Bool tabs, const Char* header);
};


// include autogenerated headerfile here
#include "ioxmlparser1.hxx"

// include autogenerated headerfile here
#include "ioxmlparser2.hxx"

/// @}

} // namespace maxon


#endif // IOXMLPARSER_H__
