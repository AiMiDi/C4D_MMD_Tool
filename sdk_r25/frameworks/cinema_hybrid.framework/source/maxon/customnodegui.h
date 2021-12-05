#ifndef CUSTOMNODEGUI_H__
#define CUSTOMNODEGUI_H__

#ifndef CUSTOMGUI_BASE_H__
#error "Please include customgui_base.h first"
#endif

#include "maxon/customnodeguiproxy.h"

namespace maxon
{

//----------------------------------------------------------------------------------------
/// Base class for custom GUIs that require re-arrangement of node-based attributes in
/// the attribute manager.
/// This class provides the accessors to implement complex GUIs for non-variadic and variadic
/// port bundles like the gradient, spline mapper or BSDF layer.
//----------------------------------------------------------------------------------------
class CustomNodeGuiBase : public iBaseCustomGui
{
	INSTANCEOF(CustomNodeGuiBase, iBaseCustomGui);

public:

	//----------------------------------------------------------------------------------------
	/// Constructor.
	/// @param[in] settings						The settings container.
	/// @param[in] plugin							The plugin structure.
	//----------------------------------------------------------------------------------------
	CustomNodeGuiBase(const BaseContainer& settings, CUSTOMGUIPLUGIN* plugin) : iBaseCustomGui(settings, plugin)
	{
		_proxy = CustomNodeGuiProxyInterface::Create(settings);
	}

	//----------------------------------------------------------------------------------------
	/// Called when a message is received.
	/// @note Some messages must be consumed by the node gui proxy in order to have functional
	/// gui elements that are created through the AttributeManagerProxyRef.
	/// @param[in] msg								The readable message container.
	/// @param[out] result						The writable message result container.
	/// @return												The message receive status.
	//----------------------------------------------------------------------------------------
	virtual Int32 Message(const BaseContainer& msg, BaseContainer& result) override
	{
		if (_proxy != nullptr)
		{
			return _proxy.Message(*this, msg, result);
		}
		else
		{
			return SUPER::Message(msg, result);
		}
	}

	//----------------------------------------------------------------------------------------
	/// Returns the DescIDs of all currently existing elements in the attribute manager that are associated with this gui.
	/// @return												The container holding the DescIDs on success.
	//----------------------------------------------------------------------------------------
	Result<BaseArray<DescID>> GetReplacementIds() const
	{
		iferr_scope;
		CheckState(_proxy != nullptr);

		BaseArray<DescID> replacementIds;
		_proxy.GetReplacementIds(replacementIds) iferr_return;
		return std::move(replacementIds);
	}

	//----------------------------------------------------------------------------------------
	/// Returns the attribute manager proxy which gives access to node-based attribute handling.
	/// Please note that access to the attribute manager proxy is only safe during lifetime
	/// of this gui instance.
	/// @return												The attribute manager proxy on success.
	//----------------------------------------------------------------------------------------
	Result<AttributeManagerProxyRef> GetAttributeManager()
	{
		iferr_scope;
		CheckState(_proxy != nullptr);
		return _proxy.GetAttributeManager(*this);
	}

protected:
	CustomNodeGuiProxyRef _proxy; // the accessor to node-based elements in the attribute manager.
};

} // namespace maxon

#endif // CUSTOMNODEGUI_H__
