#ifndef NODE_OR_TEMPLATE_H__
#define NODE_OR_TEMPLATE_H__

#include "maxon/nodes_all.h"

namespace maxon
{

namespace nodes
{

class NodeOrTemplate
{
public:
	NodeOrTemplate() = default;

	NodeOrTemplate(const NodeSystem& sys, const NodeTemplate& templ, const TemplateArguments& args) : _system(sys), _template(templ), _arguments(args)
	{
	}

	Bool IsPopulated() const
	{
		return _system || _template;
	}

	Bool IsEmpty() const
	{
		return !IsPopulated();
	}

	const NodeSystem& GetNodeSystem() const
	{
		return _system;
	}

	const NodeTemplate& GetTemplate() const
	{
		return _template;
	}

	const Id& GetId() const
	{
		// If we have a template instance, get the id there, otherwise take it from template to return the original template's id in all cases.
		return _system ? _system.GetTemplate().GetId() : _template.GetId();
	}

	const TemplateArguments& GetArguments() const
	{
		return _arguments;
	}

	void SetTemplate(const NodeTemplate& templ)
	{
		_template = templ;
	}

	TemplateArguments& GetArguments()
	{
		return _arguments;
	}


	Result<NodeSystem> Instantiate(const InstantiationTrace& parent, const TemplateArguments& args, const NodeTemplate& instantiator, const TemplateArguments& instantiatorArgs) const
	{
		iferr_scope;
		if (_template && (!_system || args != _arguments))
		{
			return _template.Instantiate(InstantiationTrace(parent, instantiator, instantiatorArgs, nullptr), args);
		}
		return _system;
	}

	Result<NodeSystem> GetTemplateNodeSystem(const InstantiationTrace& parent) const
	{
		StrongCOWRef<ObjectInterface> o = _template;
		while (o)
		{
			NodeSystemBasedNodeTemplate nbt = Cast<NodeSystemBasedNodeTemplate>(o);
			if (nbt)
			{
				return nbt.GetNodeSystem(parent.GetNodeSystemClass());
			}
			const StrongCOWRef<DecoratorInterface>& d = Cast<StrongCOWRef<DecoratorInterface>>(o);
			if (!d)
				break;
			o = DecoratorInterface::ConstPtr(d).GetDecoratedObject();
		}
		return {};
	}

private:
	NodeSystem _system;
	NodeTemplate _template;
	TemplateArguments _arguments;

	friend class NodeOrTemplateHelper;

public:
	MAXON_OPERATOR_STRUCT(NodeOrTemplate, _system, _template, _arguments);
};

MAXON_DATATYPE(NodeOrTemplate, "net.maxon.node.datatype.nodeortemplate");

MAXON_INTERNED_ID("net.maxon.node.port.nodesystem", NodeSystemPort);

}

#include "node_or_template1.hxx"
#include "node_or_template2.hxx"

}

#endif // NODE_OR_TEMPLATE_H__
