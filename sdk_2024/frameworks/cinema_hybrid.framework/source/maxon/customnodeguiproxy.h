#ifndef CUSTOMNODEGUIPROXY_H__
#define CUSTOMNODEGUIPROXY_H__

#include "maxon/datatype.h"
#include "maxon/graph.h"

#define DESCTRANSLATION_FORWARD
#include "maxon/desctranslation.h"

class DescID;
class BaseContainer;
class BaseDocument;
class BaseList2D;
class iBaseCustomGui;
class DescriptionPropertyCustomGui;
class GeDialog;
class GeData;
class Description;

namespace maxon
{

#if 0
using DescTranslationRef MAXON_FORWARD();
#endif

namespace ATTRIBUTEMANAGER
{
	//----------------------------------------------------------------------------------------
	/// Used in CreateAttribute().
	//----------------------------------------------------------------------------------------
	enum class CREATEATTRIBUTEFLAGS
	{
		NONE = 0,
		SHOWTEXT = 1 << 0,
		SHOWTRIANGLE = 1 << 1,
		SHOWPORT = 1 << 2,
		DONTSETVALUE = 1 << 3,
		DEFAULT = (SHOWTEXT | SHOWTRIANGLE | SHOWPORT),
	} MAXON_ENUM_FLAGS(CREATEATTRIBUTEFLAGS);

	using SetValueCallback = Delegate<Result<void>(Bool triState, const GeData& value)>;
	using ChangeValueCallback = Delegate<Result<void>(const DescID& id, const BaseContainer& msg, GeData& resultValue)>;

	//----------------------------------------------------------------------------------------
	/// Start index that should be used for ui elements used in combination with the ConnectAttributeValue.
	//----------------------------------------------------------------------------------------
	static const Int32 ID_GADGET_START_INDEX = 1000000;

} // namespace ATTRIBUTEMANAGER

//----------------------------------------------------------------------------------------
/// Gives access to the attribute manager and its node-based elements that are associated with a custom gui.
//----------------------------------------------------------------------------------------
class AttributeManagerProxyRef;
class AttributeManagerProxyInterface : MAXON_INTERFACE_BASES(ObjectInterface)
{
	MAXON_INTERFACE(AttributeManagerProxyInterface, MAXON_REFERENCE_NORMAL, "net.maxon.interface.attributemanagerproxy");

public:

	//----------------------------------------------------------------------------------------
	/// Creates an attribute manager attribute. This is just the "control dot", not the value itself.
	/// Note that no artificial (or virtual) elements can be created. Only existing elements can be reordered.
	/// This routine is should be called within CreateLayout.
	/// @param[in] id											A valid DescID for the element. 
	/// @param[out] resNeedsUnfoldGroup		Returns information if the element requires an open/close unfold element.
	/// @param[in] objects								Optional parameter to set objects list. Nullptr to auto detect objects.
	/// @param[in] flags									See ATTRIBUTEMANAGER::CREATEATTRIBUTEFLAGS.
	/// @return														The created CustomGui element if successful.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<DescriptionPropertyCustomGui*> CreateAttribute(const DescID& id, Bool& resNeedsUnfoldGroup, const BaseArray<BaseList2D*>& objects, ATTRIBUTEMANAGER::CREATEATTRIBUTEFLAGS flags);

	//----------------------------------------------------------------------------------------
	/// Returns the gadget base id of the attribute manager object.
	/// @param[in] id											A valid DescID for the element. 
	/// @return														Int32 with the gadget base id on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Int32> GetAttributeGadgetBaseId(const DescID& id);

	//----------------------------------------------------------------------------------------
	/// Creates an attribute manager value. This is data value, not the "control dot".
	/// Note that no artificial (or virtual) elements can be created. Only existing elements can be reordered.
	/// This routine is should be called within CreateLayout.
	/// @param[in] id											A valid DescID for the element. 
	/// @param[in] objects								Optional parameter to set objects list. Nullptr to auto detect objects.
	/// @return														OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> CreateAttributeValue(const DescID& id, const BaseArray<BaseList2D*>& objects);

	//----------------------------------------------------------------------------------------
	/// Removes an attribute manager value from the current layout.
	/// This routine is should be called between LayoutFlushGroup and LayoutChanged.
	/// @param[in] id											A valid DescID for the element. 
	/// @return														OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> RemoveAttributeValue(const DescID& id);

	//----------------------------------------------------------------------------------------
	/// Creates an open/close unfolding group.
	/// This routine is should be called within CreateLayout.
	/// @param[in] id											A valid DescID for the element. 
	/// @param[in] objects								Optional parameter to set objects list. Nullptr to auto detect objects.
	/// @param[in] setValues							True to set the parameters immediately (e.g. on update layouts). Should be false in CreateLayout calls.
	/// @return														OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> CreateUnfoldGroup(const DescID& id, const BaseArray<BaseList2D*>* objects, Bool setValues);

	/// Installs callbacks to intercept an element's data access.
	/// This routine is should be called within CreateLayout.
	/// @param[in] id											A valid DescID for the element. 
	/// @param[in] gadId									The dialog gadget Id. 
	/// @param[in] setValueCallback				The callback that will be called when values are set. 
	/// @param[in] changeValueCallback		The callback that will be called when values are modified. 
	/// @return														OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> ConnectAttributeValue(const DescID& id, Int32 gadId, const ATTRIBUTEMANAGER::SetValueCallback& setValueCallback, const ATTRIBUTEMANAGER::ChangeValueCallback& changeValueCallback);

	//----------------------------------------------------------------------------------------
	/// Forwards UI messages to the original element. This is necessary, so that e.g. the "control dot"
	/// can work.
	/// It is called within a CustomGui's Message (typically for BFM_ACTION).
	/// @param[in] msg										The message to be forwarded.
	/// @param[out] result								The result of the message. 
	/// @return														The result value to be returned in Message().
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Int32> ForwardMessage(const BaseContainer& msg, BaseContainer& result);

	//----------------------------------------------------------------------------------------
	/// Returns the list of objects that are currently shown in the attribute manager.
	/// @param[in] baseDocument						The document.
	/// @return														Array of objects.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<BaseArray<BaseList2D*>> GetObjects(const BaseDocument& baseDocument) const;

	/// @MAXON_ANNOTATION{methodId="DeprecatedGetDescTranslation@8c496b8a71c5a2b6"->"GetDescTranslation@8c496b8a71c5a2b6"}
	MAXON_METHOD Result<const DescTranslation&> DeprecatedGetDescTranslation(const BaseList2D& baseList) const;

	//----------------------------------------------------------------------------------------
	/// Returns a node for an object that is shown in the attribute manager.
	/// @param[in] baseList								A valid object that is currently shown in the attribute manager.
	/// @return														The corresponding node.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<GraphNode> GetNode(const BaseList2D& baseList) const;

	//----------------------------------------------------------------------------------------
	/// Returns a translation map for an object that is shown in the attribute manager.
	/// The translation map holds information to map e.g. DescIDs to port IDs of nodes.
	/// @param[in] baseList								A valid object that is currently shown in the attribute manager.
	/// @param[out] desc									When set, a call to bl.GetDescription() is made at first to update the translation structure,
	/// 																	and the resulting description is written to desc.
	/// @return														The translation map, will never be a null reference on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<DescTranslationRef> GetDescTranslation(const BaseList2D& baseList, Description* desc = nullptr) const;
};

//----------------------------------------------------------------------------------------
/// Manages a connection between the attribute manager and a custom gui for nodes.
//----------------------------------------------------------------------------------------
class CustomNodeGuiProxyRef;
class CustomNodeGuiProxyInterface
{
	MAXON_INTERFACE_NONVIRTUAL(CustomNodeGuiProxyInterface, MAXON_REFERENCE_NORMAL, "net.maxon.interface.customnodeguiproxy");

public:

	/// Creates the proxy to gain access to node-based elements in the attribute manager. 
	/// @param[in] settings						The settings container.
	/// @return												The reference to the proxy, can be nullptr on error.
	static MAXON_METHOD CustomNodeGuiProxyRef Create(const BaseContainer& settings);

	/// Returns the DescIDs of all currently existing elements in the attribute manager that are associated with this gui proxy. 
	/// @param[out] replacementIds		The container for the DescID collection.
	/// @return												OK on success.
	MAXON_METHOD Result<void> GetReplacementIds(BaseArray<DescID>& replacementIds) const;

	//----------------------------------------------------------------------------------------
	/// Returns the attribute manager proxy which gives access to node-based attribute handling.
	/// @param[in] dialog							The dialog to handle attributes for.
	/// @return												The attribute manager proxy.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<AttributeManagerProxyRef> GetAttributeManager(GeDialog& dialog) const;

	//----------------------------------------------------------------------------------------
	/// Call to forward messages that need to be received received by gui elements that are
	/// created through the AttributeManagerProxyRef.
	/// @param[in] gui								The gui that should receive messages that have not been consumed by the attribute manager proxy.
	/// @param[in] msg								The readable message container.
	/// @param[out] result						The writable message result container.
	/// @return												The message receive status.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Int32 Message(iBaseCustomGui& gui, const BaseContainer& msg, BaseContainer& result);
};

#include "customnodeguiproxy1.hxx"
#include "customnodeguiproxy2.hxx"

} // namespace maxon

#endif // #define CUSTOMNODEGUIPROXY_H__
