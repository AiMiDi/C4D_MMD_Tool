#if 1
namespace maxon
{
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	static maxon::InterfaceDefinition s_StreamConversionInterface(StreamConversionInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION);
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	class StreamConversionInterface::ProxyComponent : public maxon::Component<ProxyComponent, StreamConversionInterface>
	{
		MAXON_COMPONENT();
	public:
		using typename maxon::Component<ProxyComponent, StreamConversionInterface>::_Wrapper;
		static const maxon::Bool PROXY = true;
		maxon::reflection::ProxyHandler _handler;
		Int GetBatchSize() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<StreamConversionInterface>();
			Int proxy_result = 0;
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._StreamConversionInterface_GetBatchSize_Offset)};
			(*handler_)(_fn_StreamConversionInterface_GetBatchSize, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Int, const maxon::GenericComponent*>::Invoke, (const void*) mt_._StreamConversionInterface_GetBatchSize));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_StreamConversionInterface_GetBatchSize;
		Int GetBlockSize() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<StreamConversionInterface>();
			Int proxy_result = 0;
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._StreamConversionInterface_GetBlockSize_Offset)};
			(*handler_)(_fn_StreamConversionInterface_GetBlockSize, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Int, const maxon::GenericComponent*>::Invoke, (const void*) mt_._StreamConversionInterface_GetBlockSize));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_StreamConversionInterface_GetBlockSize;
		Id GetCounterpart() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<StreamConversionInterface>();
			Id proxy_result = maxon::PrivateIncompleteNullReturnValue<Id>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._StreamConversionInterface_GetCounterpart_Offset)};
			(*handler_)(_fn_StreamConversionInterface_GetCounterpart, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Id, const maxon::GenericComponent*>::Invoke, (const void*) mt_._StreamConversionInterface_GetCounterpart));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_StreamConversionInterface_GetCounterpart;
		const DataType& GetSourceType() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<StreamConversionInterface>();
			const DataType* proxy_result = &maxon::PrivateIncompleteNullReturnValue<const DataType&>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._StreamConversionInterface_GetSourceType_Offset)};
			(*handler_)(_fn_StreamConversionInterface_GetSourceType, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<const DataType&, const maxon::GenericComponent*>::Invoke, (const void*) mt_._StreamConversionInterface_GetSourceType));
			return *proxy_result;
		}
		static const maxon::reflection::Function* _fn_StreamConversionInterface_GetSourceType;
		const DataType& GetDestinationType() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<StreamConversionInterface>();
			const DataType* proxy_result = &maxon::PrivateIncompleteNullReturnValue<const DataType&>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._StreamConversionInterface_GetDestinationType_Offset)};
			(*handler_)(_fn_StreamConversionInterface_GetDestinationType, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<const DataType&, const maxon::GenericComponent*>::Invoke, (const void*) mt_._StreamConversionInterface_GetDestinationType));
			return *proxy_result;
		}
		static const maxon::reflection::Function* _fn_StreamConversionInterface_GetDestinationType;
		Bool SupportInplaceConversion() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<StreamConversionInterface>();
			Bool proxy_result = maxon::PrivateLogNullptrError(false);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._StreamConversionInterface_SupportInplaceConversion_Offset)};
			(*handler_)(_fn_StreamConversionInterface_SupportInplaceConversion, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Bool, const maxon::GenericComponent*>::Invoke, (const void*) mt_._StreamConversionInterface_SupportInplaceConversion));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_StreamConversionInterface_SupportInplaceConversion;
		Result<Int> ConvertImpl(const Block<const Generic>& src, WritableArrayInterface<Generic>& dst, Int dstLimitHint, Bool inputFinished, Bool& outputFinished) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<StreamConversionInterface>();
			Result<Int> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._StreamConversionInterface_ConvertImpl_Offset), maxon::reflection::Argument::ByReference(src), maxon::reflection::Argument::ByReference(dst), maxon::reflection::Argument::ByValue(dstLimitHint), maxon::reflection::Argument::ByValue(inputFinished), maxon::reflection::Argument::ByReference(outputFinished)};
			(*handler_)(_fn_StreamConversionInterface_ConvertImpl, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<Int>, maxon::GenericComponent*, const Block<const Generic>&, WritableArrayInterface<Generic>&, Int, Bool, Bool&>::Invoke, (const void*) mt_._StreamConversionInterface_ConvertImpl));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_StreamConversionInterface_ConvertImpl;
		Result<InputStreamRef> ConvertToStream(const InputStreamRef& in) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<StreamConversionInterface>();
			Result<InputStreamRef> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._StreamConversionInterface_ConvertToStream_Offset), maxon::reflection::Argument::ByReference(in)};
			(*handler_)(_fn_StreamConversionInterface_ConvertToStream, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<InputStreamRef>, maxon::GenericComponent*, const InputStreamRef&>::Invoke, (const void*) mt_._StreamConversionInterface_ConvertToStream));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_StreamConversionInterface_ConvertToStream;
		Result<InputStreamRef> ConvertToStream(const DataFormatBaseReaderRef& in) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<StreamConversionInterface>();
			Result<InputStreamRef> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._StreamConversionInterface_ConvertToStream_1_Offset), maxon::reflection::Argument::ByReference(in)};
			(*handler_)(_fn_StreamConversionInterface_ConvertToStream_1, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<InputStreamRef>, maxon::GenericComponent*, const DataFormatBaseReaderRef&>::Invoke, (const void*) mt_._StreamConversionInterface_ConvertToStream_1));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_StreamConversionInterface_ConvertToStream_1;
		Result<DataFormatBaseReaderRef> ConvertToReader(const InputStreamRef& in) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<StreamConversionInterface>();
			Result<DataFormatBaseReaderRef> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._StreamConversionInterface_ConvertToReader_Offset), maxon::reflection::Argument::ByReference(in)};
			(*handler_)(_fn_StreamConversionInterface_ConvertToReader, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<DataFormatBaseReaderRef>, maxon::GenericComponent*, const InputStreamRef&>::Invoke, (const void*) mt_._StreamConversionInterface_ConvertToReader));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_StreamConversionInterface_ConvertToReader;
		Result<DataFormatBaseReaderRef> ConvertToReader(const DataFormatBaseReaderRef& in) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<StreamConversionInterface>();
			Result<DataFormatBaseReaderRef> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._StreamConversionInterface_ConvertToReader_1_Offset), maxon::reflection::Argument::ByReference(in)};
			(*handler_)(_fn_StreamConversionInterface_ConvertToReader_1, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<DataFormatBaseReaderRef>, maxon::GenericComponent*, const DataFormatBaseReaderRef&>::Invoke, (const void*) mt_._StreamConversionInterface_ConvertToReader_1));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_StreamConversionInterface_ConvertToReader_1;
		Result<OutputStreamRef> ConvertToStream(const OutputStreamRef& out) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<StreamConversionInterface>();
			Result<OutputStreamRef> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._StreamConversionInterface_ConvertToStream_2_Offset), maxon::reflection::Argument::ByReference(out)};
			(*handler_)(_fn_StreamConversionInterface_ConvertToStream_2, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<OutputStreamRef>, maxon::GenericComponent*, const OutputStreamRef&>::Invoke, (const void*) mt_._StreamConversionInterface_ConvertToStream_2));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_StreamConversionInterface_ConvertToStream_2;
		Result<OutputStreamRef> ConvertToStream(const DataFormatBaseWriterRef& out) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<StreamConversionInterface>();
			Result<OutputStreamRef> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._StreamConversionInterface_ConvertToStream_3_Offset), maxon::reflection::Argument::ByReference(out)};
			(*handler_)(_fn_StreamConversionInterface_ConvertToStream_3, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<OutputStreamRef>, maxon::GenericComponent*, const DataFormatBaseWriterRef&>::Invoke, (const void*) mt_._StreamConversionInterface_ConvertToStream_3));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_StreamConversionInterface_ConvertToStream_3;
		Result<DataFormatBaseWriterRef> ConvertToWriter(const OutputStreamRef& out) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<StreamConversionInterface>();
			Result<DataFormatBaseWriterRef> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._StreamConversionInterface_ConvertToWriter_Offset), maxon::reflection::Argument::ByReference(out)};
			(*handler_)(_fn_StreamConversionInterface_ConvertToWriter, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<DataFormatBaseWriterRef>, maxon::GenericComponent*, const OutputStreamRef&>::Invoke, (const void*) mt_._StreamConversionInterface_ConvertToWriter));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_StreamConversionInterface_ConvertToWriter;
		Result<DataFormatBaseWriterRef> ConvertToWriter(const DataFormatBaseWriterRef& out) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<StreamConversionInterface>();
			Result<DataFormatBaseWriterRef> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._StreamConversionInterface_ConvertToWriter_1_Offset), maxon::reflection::Argument::ByReference(out)};
			(*handler_)(_fn_StreamConversionInterface_ConvertToWriter_1, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<DataFormatBaseWriterRef>, maxon::GenericComponent*, const DataFormatBaseWriterRef&>::Invoke, (const void*) mt_._StreamConversionInterface_ConvertToWriter_1));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_StreamConversionInterface_ConvertToWriter_1;
	};
	const maxon::reflection::Function* StreamConversionInterface::ProxyComponent::_fn_StreamConversionInterface_GetBatchSize;
	const maxon::reflection::Function* StreamConversionInterface::ProxyComponent::_fn_StreamConversionInterface_GetBlockSize;
	const maxon::reflection::Function* StreamConversionInterface::ProxyComponent::_fn_StreamConversionInterface_GetCounterpart;
	const maxon::reflection::Function* StreamConversionInterface::ProxyComponent::_fn_StreamConversionInterface_GetSourceType;
	const maxon::reflection::Function* StreamConversionInterface::ProxyComponent::_fn_StreamConversionInterface_GetDestinationType;
	const maxon::reflection::Function* StreamConversionInterface::ProxyComponent::_fn_StreamConversionInterface_SupportInplaceConversion;
	const maxon::reflection::Function* StreamConversionInterface::ProxyComponent::_fn_StreamConversionInterface_ConvertImpl;
	const maxon::reflection::Function* StreamConversionInterface::ProxyComponent::_fn_StreamConversionInterface_ConvertToStream;
	const maxon::reflection::Function* StreamConversionInterface::ProxyComponent::_fn_StreamConversionInterface_ConvertToStream_1;
	const maxon::reflection::Function* StreamConversionInterface::ProxyComponent::_fn_StreamConversionInterface_ConvertToReader;
	const maxon::reflection::Function* StreamConversionInterface::ProxyComponent::_fn_StreamConversionInterface_ConvertToReader_1;
	const maxon::reflection::Function* StreamConversionInterface::ProxyComponent::_fn_StreamConversionInterface_ConvertToStream_2;
	const maxon::reflection::Function* StreamConversionInterface::ProxyComponent::_fn_StreamConversionInterface_ConvertToStream_3;
	const maxon::reflection::Function* StreamConversionInterface::ProxyComponent::_fn_StreamConversionInterface_ConvertToWriter;
	const maxon::reflection::Function* StreamConversionInterface::ProxyComponent::_fn_StreamConversionInterface_ConvertToWriter_1;
	PRIVATE_MAXON_COMPONENT_REGISTER(StreamConversionInterface::ProxyComponent, , typename, maxon::EntityBase::FLAGS::PROXY, ::MaxonRegistry, maxon::LiteralId());
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	static maxon::Result<void> RegisterReflection_StreamConversionInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, StreamConversionInterface, _StreamConversionInterface_GetBatchSize),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, StreamConversionInterface, _StreamConversionInterface_GetBlockSize),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, StreamConversionInterface, _StreamConversionInterface_GetCounterpart),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, StreamConversionInterface, _StreamConversionInterface_GetSourceType),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, StreamConversionInterface, _StreamConversionInterface_GetDestinationType),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, StreamConversionInterface, _StreamConversionInterface_SupportInplaceConversion),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "src\0dst\0dstLimitHint\0inputFinished\0outputFinished\0", 601LL, StreamConversionInterface, _StreamConversionInterface_ConvertImpl),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "in\0", 0LL, StreamConversionInterface, _StreamConversionInterface_ConvertToStream),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "in\0", 0LL, StreamConversionInterface, _StreamConversionInterface_ConvertToStream_1),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "in\0", 0LL, StreamConversionInterface, _StreamConversionInterface_ConvertToReader),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "in\0", 0LL, StreamConversionInterface, _StreamConversionInterface_ConvertToReader_1),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "out\0", 0LL, StreamConversionInterface, _StreamConversionInterface_ConvertToStream_2),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "out\0", 0LL, StreamConversionInterface, _StreamConversionInterface_ConvertToStream_3),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "out\0", 0LL, StreamConversionInterface, _StreamConversionInterface_ConvertToWriter),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "out\0", 0LL, StreamConversionInterface, _StreamConversionInterface_ConvertToWriter_1),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&StreamConversionInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	static maxon::reflection::ContainerInfo g_reflection_StreamConversionInterface(nullptr, &StreamConversionInterface::ProxyComponent::_descriptor, &RegisterReflection_StreamConversionInterface, &PRIVATE_MAXON_MODULE);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	PRIVATE_MAXON_REGISTRY_DEFINE(StreamConversions);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	PRIVATE_MAXON_REGISTRY_DEFINE(StreamConversionTests);
#endif
}
#endif
