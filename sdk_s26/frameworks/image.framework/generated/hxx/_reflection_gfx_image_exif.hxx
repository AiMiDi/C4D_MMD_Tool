#if 1
namespace maxon
{
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	static maxon::InterfaceDefinition s_ExifInterface(ExifInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION,"maxon::ExifRef");
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	class ExifInterface::ProxyComponent : public maxon::Component<ProxyComponent, ExifInterface>
	{
		MAXON_COMPONENT();
	public:
		using typename maxon::Component<ProxyComponent, ExifInterface>::_Wrapper;
		static const maxon::Bool PROXY = true;
		maxon::reflection::ProxyHandler _handler;
		Result<DataDictionary> GetExifDictionary() const 
		{
			const maxon::ComponentInfo* proxy_info;
			maxon::ObjectInterface* o_;
			const maxon::reflection::ProxyHandler* handler_;
			if (maxon::UInt(this) & (SIZEOF(void*)-1))
			{
				o_ = (maxon::ObjectInterface*) (maxon::UInt(this) & ~maxon::DefaultAllocator::MIN_ALIGNMENT_MASK);
				proxy_info = &maxon::ClassInfo::PrivateGetClassProxyComponentInfo(o_, _descriptor, reinterpret_cast<const maxon::GenericComponent*>(this));
				handler_ = reinterpret_cast<const maxon::reflection::ProxyHandler*>(proxy_info->_classProxyHandler.GetPointer());
			}
			else
			{
				o_ = (maxon::ObjectInterface*) this->self.GetPointer();
				proxy_info = &o_->GetClassInfo()->PrivateGetComponentInfo(_descriptor);
				handler_ = &_handler;
			}
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<ExifInterface>();
			Result<DataDictionary> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ExifInterface_GetExifDictionary_Offset)};
			(*handler_)(_fn_ExifInterface_GetExifDictionary, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<DataDictionary>, const maxon::GenericComponent*>::Invoke, (const void*) mt_.ExifInterface_GetExifDictionary));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_ExifInterface_GetExifDictionary;
	};
	const maxon::reflection::Function* ExifInterface::ProxyComponent::_fn_ExifInterface_GetExifDictionary;
	PRIVATE_MAXON_COMPONENT_REGISTER(ExifInterface::ProxyComponent, , typename, maxon::EntityBase::FLAGS::PROXY, &maxon::g_translationUnit, ::MaxonRegistry, maxon::LiteralId());
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	static maxon::Result<void> RegisterReflection_ExifInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, ExifInterface, ExifInterface_GetExifDictionary),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&ExifInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	static maxon::reflection::ContainerInfo g_reflection_ExifInterface(nullptr, &ExifInterface::ProxyComponent::_descriptor, &RegisterReflection_ExifInterface, &PRIVATE_MAXON_MODULE);
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL)
	static maxon::Result<void> RegisterReflection_ExifStaticInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ExifStaticInterface::MTable::_instance.ExifStaticInterface_OpenFromMemory)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "exifChunk\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ExifStaticInterface::MTable::_instance.ExifStaticInterface_OpenJpgFromUrl)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "fileName\0", 1LL, nullptr),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&ExifStaticInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL
	static maxon::reflection::ContainerInfo g_reflection_ExifStaticInterface("net.maxon.image.interface.exifstatic", nullptr, &RegisterReflection_ExifStaticInterface, &PRIVATE_MAXON_MODULE);
#endif
}
#endif
