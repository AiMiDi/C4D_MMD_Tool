#include "maxon/reflection_registration.h"

namespace maxon
{

const ComponentInfo& ClassInfo::PrivateGetClassProxyComponentInfo(const ObjectInterface* o, const ComponentDescriptor& d, const GenericComponent* comp)
{
	const ClassInfo* i = o->GetClassInfo();
	const ComponentDescriptor& pd = *d._classProxy;
	UInt offset = UInt(comp) & DefaultAllocator::MIN_ALIGNMENT_MASK;
	UInt hash = pd._hashCode + offset;
	if (MAXON_UNLIKELY(hash >= ClassInfo::HASH_TABLE_SIZE))
		hash -= ClassInfo::HASH_TABLE_SIZE;
#ifdef MAXON_COMPONENT_HASHTABLE
	for (const ComponentInfo* e = i->_componentInfos[hash]; ; ++e)
	{
		if (MAXON_LIKELY(&pd == e->_descriptor && Int32(offset) == e->_offset))
		{
			return *e;
		}
	}
#else
	for (auto it = i->_infoArray.Begin(); ; ++it)
	{
		if (it->_descriptor == &pd && it->_offset == Int32(offset))
			return *it;
	}
#endif
}

namespace reflection
{

String ParameterType::ToString(const FormatStatement* fmt) const
{
	if (!_type)
		return "nullptr"_s;
	String s = _type->GetId().ToString(fmt);
	if (_flags & FLAGS::EXPLICIT_INPUT_OUTPUT)
	{
		switch (_flags & (FLAGS::INPUT | FLAGS::OUTPUT))
		{
			case FLAGS::INPUT:
				s += "[in]"_s;
				break;
			case FLAGS::OUTPUT:
				s += "[out]"_s;
				break;
			default:
				s += "[in,out]"_s;
				break;
		}
	}
	return s;
}

Result<void> Argument::MoveFrom(const ParameterType& type, Data& data, BaseArray<Data>& storage)
{
	iferr_scope;
	if (type.GetType()->GetValueKind() & VALUEKIND::SCALAR)
	{
		// Note: By C++ standard it is guaranteed that all members of the value union have the same address as the Argument.
		type.MoveFromData(*reinterpret_cast<Generic*>(this), data, storage) iferr_return;
	}
	else
	{
		CheckAssert(type.GetType() == type.GetTypeForData());
		if ((type.GetTypeForData() == data.GetType()) || (type.GetTypeForData()->GetValueKind() & VALUEKIND::DATA))
		{
			_pointerValue = (Generic*)data.PrivateGetPtr(type.GetTypeForData());
		}
		else
		{
			return IllegalArgumentError(MAXON_SOURCE_LOCATION, FormatString("Data value of type @ doesn't match parameter type @.", data.GetType(), type));
		}
	}
	return OK;
}

Result<Data> Argument::ToData(const ParameterType& type) const
{
	iferr_scope;
	if (type.GetType()->GetValueKind() & VALUEKIND::SCALAR)
	{
		// Note: By C++ standard it is guaranteed that all members of the value union have the same address as the Argument.
		return type.ToData(*reinterpret_cast<const Generic*>(this));
	}
	else
	{
		CheckAssert(type.GetType() == type.GetTypeForData());
		Data result;
		result.CopyFrom(ConstDataPtr(type.GetType(), reinterpret_cast<const Generic*>(_pointerValue))) iferr_return;
		return std::move(result);
	}
}

Result<Argument> Argument::FromData(const ParameterType& type, Data& data, BaseArray<Data>& storage)
{
	iferr_scope;
	Argument arg;
	arg.MoveFrom(type, data, storage) iferr_return;
	return arg;
}


static ParameterType::FLAGS GetFlags(const ParameterType& t, Int inOut)
{
	ParameterType::FLAGS f = t.GetFlags();
	if (inOut != 0)
	{
		f &= ~(ParameterType::FLAGS::INPUT | ParameterType::FLAGS::OUTPUT);
		if (inOut & 1)
			f |= ParameterType::FLAGS::INPUT | ParameterType::FLAGS::EXPLICIT_INPUT_OUTPUT;
		if (inOut & 2)
			f |= ParameterType::FLAGS::OUTPUT | ParameterType::FLAGS::EXPLICIT_INPUT_OUTPUT;
	}
	return f;
}

FunctionInfo::FunctionInfo(const Char* n, Member::KIND k, const ParameterType& ret, const Block<const ParameterType>& paramTypes, const Char* paramNames, Int64 inOut, void* nat, InvocationWrapper wrap) : name(n), kind(k), returnType(ret), native(nat), wrapper(wrap)
{
	Bool hasThis = (Bool)(k & (Member::KIND::INSTANCE_FUNCTION | Member::KIND::CONST_INSTANCE_FUNCTION));
	for (const ParameterType& t : paramTypes.Slice(hasThis ? 1 : 0))
	{
		iferr (parameters.Append(Parameter(ParameterType(t.GetType(), GetFlags(t, Int(inOut & 3))), Id(paramNames))))
		{
			name = nullptr;
			break;
		}
		paramNames += strlen(paramNames) + 1;
		inOut >>= 2;
	}
}

ContainerInfo::ContainerInfo(const Char* n, const ComponentDescriptor* pr, ReflectionRegistration reg, ModuleInfo* module) : cid(n),
	proxy(pr), registration(reg), next(module->_containerInfos)
{
	module->_containerInfos = this;
}

}

}
