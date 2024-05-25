#if 1
namespace maxon
{
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	static maxon::InterfaceDefinition s_ParserInterface(ParserInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION,"maxon::ParserRef");
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	class ParserInterface::ProxyComponent : public maxon::Component<ProxyComponent, ParserInterface>
	{
		MAXON_COMPONENT();
	public:
		using typename maxon::Component<ProxyComponent, ParserInterface>::_Wrapper;
		static const maxon::Bool PROXY = true;
		maxon::reflection::ProxyHandler _handler;
		Result<void> Read(UrlOrInputStream&& nameOrStream, PARSERFLAGS flags, const StringDecodingRef& stringDecoding, const ValueReceiver<const DataDictionary&>& objects, BaseArray<Char>* originalToken) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<ParserInterface>();
			Result<void> proxy_result = HXXRET1(NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ParserInterface_Read_Offset), maxon::reflection::Argument::ByReference(nameOrStream), maxon::reflection::Argument::ByValue(flags), maxon::reflection::Argument::ByReference(stringDecoding), maxon::reflection::Argument::ByReference(objects), maxon::reflection::Argument::ByValue(originalToken)};
			(*handler_)(_fn_ParserInterface_Read, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((Result<void>), UrlOrInputStream&&, PARSERFLAGS, const StringDecodingRef&, const ValueReceiver<const DataDictionary&>&, BaseArray<Char>*), reinterpret_cast<const void* const&>(mt_.ParserInterface_Read)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_ParserInterface_Read;
		Result<void> Write(const DataDictionary& object, String& string, Bool niceFormatting) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<ParserInterface>();
			Result<void> proxy_result = HXXRET1(NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ParserInterface_Write_Offset), maxon::reflection::Argument::ByReference(object), maxon::reflection::Argument::ByReference(string), maxon::reflection::Argument::ByValue(niceFormatting)};
			(*handler_)(_fn_ParserInterface_Write, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((Result<void>), const DataDictionary&, String&, Bool), reinterpret_cast<const void* const&>(mt_.ParserInterface_Write)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_ParserInterface_Write;
		Result<void> WriteFile(UrlOrOutputStream&& out, const StringEncodingRef& stringEncoding, const DataDictionary& dict, Bool niceFormatting) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<ParserInterface>();
			Result<void> proxy_result = HXXRET1(NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ParserInterface_WriteFile_Offset), maxon::reflection::Argument::ByReference(out), maxon::reflection::Argument::ByReference(stringEncoding), maxon::reflection::Argument::ByReference(dict), maxon::reflection::Argument::ByValue(niceFormatting)};
			(*handler_)(_fn_ParserInterface_WriteFile, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((Result<void>), UrlOrOutputStream&&, const StringEncodingRef&, const DataDictionary&, Bool), reinterpret_cast<const void* const&>(mt_.ParserInterface_WriteFile)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_ParserInterface_WriteFile;
		String GetFileExtension() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<ParserInterface>();
			String proxy_result = HXXRET3(NULLIMPL, String);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ParserInterface_GetFileExtension_Offset)};
			(*handler_)(_fn_ParserInterface_GetFileExtension, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((String)), reinterpret_cast<const void* const&>(mt_.ParserInterface_GetFileExtension)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_ParserInterface_GetFileExtension;
	};
	const maxon::reflection::Function* ParserInterface::ProxyComponent::_fn_ParserInterface_Read;
	const maxon::reflection::Function* ParserInterface::ProxyComponent::_fn_ParserInterface_Write;
	const maxon::reflection::Function* ParserInterface::ProxyComponent::_fn_ParserInterface_WriteFile;
	const maxon::reflection::Function* ParserInterface::ProxyComponent::_fn_ParserInterface_GetFileExtension;
	PRIVATE_MAXON_COMPONENT_REGISTER(ParserInterface::ProxyComponent, , typename, maxon::EntityBase::FLAGS::PROXY, &maxon::g_translationUnit, ::MaxonRegistry, maxon::LiteralId());
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	static maxon::Result<void> RegisterReflection_ParserInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "nameOrStream\0flags\0stringDecoding\0objects\0originalToken\0", 581LL, ParserInterface, ParserInterface_Read),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "object\0string\0niceFormatting\0", 25LL, ParserInterface, ParserInterface_Write),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "out\0stringEncoding\0dict\0niceFormatting\0", 85LL, ParserInterface, ParserInterface_WriteFile),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, ParserInterface, ParserInterface_GetFileExtension),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&ParserInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	static maxon::reflection::ContainerInfo g_reflection_ParserInterface(nullptr, &ParserInterface::ProxyComponent::_descriptor, &RegisterReflection_ParserInterface, &PRIVATE_MAXON_MODULE);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	PRIVATE_MAXON_REGISTRY_DEFINE(ParserClasses);
#endif
}
#endif
