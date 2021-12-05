#if 1
namespace maxon
{
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	static maxon::InterfaceDefinition s_HierarchyObjectInterface(HierarchyObjectInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION);
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	class HierarchyObjectInterface::ProxyComponent : public maxon::Component<ProxyComponent, HierarchyObjectInterface>
	{
		MAXON_COMPONENT();
	public:
		using typename maxon::Component<ProxyComponent, HierarchyObjectInterface>::_Wrapper;
		static const maxon::Bool PROXY = true;
		maxon::reflection::ProxyHandler _handler;
		Result<void> InsertBefore(const typename HIERARCHY::template Sibling<Interface>::type& nextSibling) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<HierarchyObjectInterface>();
			Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._HierarchyObjectInterface_InsertBefore_Offset), maxon::reflection::Argument::ByReference(nextSibling)};
			(*handler_)(_fn_HierarchyObjectInterface_InsertBefore, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<void>, maxon::GenericComponent*, const typename HIERARCHY::template Sibling<Interface>::type&>::Invoke, (const void*) mt_._HierarchyObjectInterface_InsertBefore));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_HierarchyObjectInterface_InsertBefore;
		Result<void> InsertAfter(const typename HIERARCHY::template Sibling<Interface>::type& prevSibling) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<HierarchyObjectInterface>();
			Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._HierarchyObjectInterface_InsertAfter_Offset), maxon::reflection::Argument::ByReference(prevSibling)};
			(*handler_)(_fn_HierarchyObjectInterface_InsertAfter, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<void>, maxon::GenericComponent*, const typename HIERARCHY::template Sibling<Interface>::type&>::Invoke, (const void*) mt_._HierarchyObjectInterface_InsertAfter));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_HierarchyObjectInterface_InsertAfter;
		Result<void> InsertAsFirstChildOf(const typename HIERARCHY::template Parent<Interface>::type& parent, const ConstDataPtr& branchId) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<HierarchyObjectInterface>();
			Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._HierarchyObjectInterface_InsertAsFirstChildOf_Offset), maxon::reflection::Argument::ByReference(parent), maxon::reflection::Argument::ByReference(branchId)};
			(*handler_)(_fn_HierarchyObjectInterface_InsertAsFirstChildOf, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<void>, maxon::GenericComponent*, const typename HIERARCHY::template Parent<Interface>::type&, const ConstDataPtr&>::Invoke, (const void*) mt_._HierarchyObjectInterface_InsertAsFirstChildOf));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_HierarchyObjectInterface_InsertAsFirstChildOf;
		Result<void> InsertAsLastChildOf(const typename HIERARCHY::template Parent<Interface>::type& parent, const ConstDataPtr& branchId) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<HierarchyObjectInterface>();
			Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._HierarchyObjectInterface_InsertAsLastChildOf_Offset), maxon::reflection::Argument::ByReference(parent), maxon::reflection::Argument::ByReference(branchId)};
			(*handler_)(_fn_HierarchyObjectInterface_InsertAsLastChildOf, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<void>, maxon::GenericComponent*, const typename HIERARCHY::template Parent<Interface>::type&, const ConstDataPtr&>::Invoke, (const void*) mt_._HierarchyObjectInterface_InsertAsLastChildOf));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_HierarchyObjectInterface_InsertAsLastChildOf;
		Result<void> InsertAsChildAt(const typename HIERARCHY::template Parent<Interface>::type& parent, Int position, const ConstDataPtr& branchId) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<HierarchyObjectInterface>();
			Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._HierarchyObjectInterface_InsertAsChildAt_Offset), maxon::reflection::Argument::ByReference(parent), maxon::reflection::Argument::ByValue(position), maxon::reflection::Argument::ByReference(branchId)};
			(*handler_)(_fn_HierarchyObjectInterface_InsertAsChildAt, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<void>, maxon::GenericComponent*, const typename HIERARCHY::template Parent<Interface>::type&, Int, const ConstDataPtr&>::Invoke, (const void*) mt_._HierarchyObjectInterface_InsertAsChildAt));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_HierarchyObjectInterface_InsertAsChildAt;
		Result<void> InsertChildAsFirst(const typename HIERARCHY::template Child<Interface>::type& child, const ConstDataPtr& branchId) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<HierarchyObjectInterface>();
			Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._HierarchyObjectInterface_InsertChildAsFirst_Offset), maxon::reflection::Argument::ByReference(child), maxon::reflection::Argument::ByReference(branchId)};
			(*handler_)(_fn_HierarchyObjectInterface_InsertChildAsFirst, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<void>, maxon::GenericComponent*, const typename HIERARCHY::template Child<Interface>::type&, const ConstDataPtr&>::Invoke, (const void*) mt_._HierarchyObjectInterface_InsertChildAsFirst));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_HierarchyObjectInterface_InsertChildAsFirst;
		Result<void> InsertChildAsLast(const typename HIERARCHY::template Child<Interface>::type& child, const ConstDataPtr& branchId) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<HierarchyObjectInterface>();
			Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._HierarchyObjectInterface_InsertChildAsLast_Offset), maxon::reflection::Argument::ByReference(child), maxon::reflection::Argument::ByReference(branchId)};
			(*handler_)(_fn_HierarchyObjectInterface_InsertChildAsLast, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<void>, maxon::GenericComponent*, const typename HIERARCHY::template Child<Interface>::type&, const ConstDataPtr&>::Invoke, (const void*) mt_._HierarchyObjectInterface_InsertChildAsLast));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_HierarchyObjectInterface_InsertChildAsLast;
		Result<void> InsertChildAt(const typename HIERARCHY::template Child<Interface>::type& child, Int position, const ConstDataPtr& branchId) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<HierarchyObjectInterface>();
			Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._HierarchyObjectInterface_InsertChildAt_Offset), maxon::reflection::Argument::ByReference(child), maxon::reflection::Argument::ByValue(position), maxon::reflection::Argument::ByReference(branchId)};
			(*handler_)(_fn_HierarchyObjectInterface_InsertChildAt, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<void>, maxon::GenericComponent*, const typename HIERARCHY::template Child<Interface>::type&, Int, const ConstDataPtr&>::Invoke, (const void*) mt_._HierarchyObjectInterface_InsertChildAt));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_HierarchyObjectInterface_InsertChildAt;
		Result<void> InsertChildrenAsFirst(const Block<const typename HIERARCHY::template Child<Interface>::type>& children, const ConstDataPtr& branchId) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<HierarchyObjectInterface>();
			Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._HierarchyObjectInterface_InsertChildrenAsFirst_Offset), maxon::reflection::Argument::ByReference(children), maxon::reflection::Argument::ByReference(branchId)};
			(*handler_)(_fn_HierarchyObjectInterface_InsertChildrenAsFirst, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<void>, maxon::GenericComponent*, const Block<const typename HIERARCHY::template Child<Interface>::type>&, const ConstDataPtr&>::Invoke, (const void*) mt_._HierarchyObjectInterface_InsertChildrenAsFirst));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_HierarchyObjectInterface_InsertChildrenAsFirst;
		Result<void> InsertChildrenAsLast(const Block<const typename HIERARCHY::template Child<Interface>::type>& children, const ConstDataPtr& branchId) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<HierarchyObjectInterface>();
			Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._HierarchyObjectInterface_InsertChildrenAsLast_Offset), maxon::reflection::Argument::ByReference(children), maxon::reflection::Argument::ByReference(branchId)};
			(*handler_)(_fn_HierarchyObjectInterface_InsertChildrenAsLast, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<void>, maxon::GenericComponent*, const Block<const typename HIERARCHY::template Child<Interface>::type>&, const ConstDataPtr&>::Invoke, (const void*) mt_._HierarchyObjectInterface_InsertChildrenAsLast));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_HierarchyObjectInterface_InsertChildrenAsLast;
		Result<void> InsertChildrenAt(const Block<const typename HIERARCHY::template Child<Interface>::type>& children, Int position, const ConstDataPtr& branchId) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<HierarchyObjectInterface>();
			Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._HierarchyObjectInterface_InsertChildrenAt_Offset), maxon::reflection::Argument::ByReference(children), maxon::reflection::Argument::ByValue(position), maxon::reflection::Argument::ByReference(branchId)};
			(*handler_)(_fn_HierarchyObjectInterface_InsertChildrenAt, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<void>, maxon::GenericComponent*, const Block<const typename HIERARCHY::template Child<Interface>::type>&, Int, const ConstDataPtr&>::Invoke, (const void*) mt_._HierarchyObjectInterface_InsertChildrenAt));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_HierarchyObjectInterface_InsertChildrenAt;
		Result<void> Replace(const typename HIERARCHY::template Sibling<Interface>::type& newObject) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<HierarchyObjectInterface>();
			Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._HierarchyObjectInterface_Replace_Offset), maxon::reflection::Argument::ByReference(newObject)};
			(*handler_)(_fn_HierarchyObjectInterface_Replace, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<void>, maxon::GenericComponent*, const typename HIERARCHY::template Sibling<Interface>::type&>::Invoke, (const void*) mt_._HierarchyObjectInterface_Replace));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_HierarchyObjectInterface_Replace;
		HierarchyObjectRef<> Remove() 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<HierarchyObjectInterface>();
			HierarchyObjectRef<> proxy_result = maxon::PrivateNullReturnValue<HierarchyObjectRef<>>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._HierarchyObjectInterface_Remove_Offset)};
			(*handler_)(_fn_HierarchyObjectInterface_Remove, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<HierarchyObjectRef<>, maxon::GenericComponent*>::Invoke, (const void*) mt_._HierarchyObjectInterface_Remove));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_HierarchyObjectInterface_Remove;
		typename HIERARCHY::template Child<Interface>::type RemoveChildren(const ConstDataPtr& branchId) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<HierarchyObjectInterface>();
			typename HIERARCHY::template Child<Interface>::type proxy_result = maxon::PrivateNullReturnValue<typename HIERARCHY::template Child<Interface>::type>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._HierarchyObjectInterface_RemoveChildren_Offset), maxon::reflection::Argument::ByReference(branchId)};
			(*handler_)(_fn_HierarchyObjectInterface_RemoveChildren, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<typename HIERARCHY::template Child<Interface>::type, maxon::GenericComponent*, const ConstDataPtr&>::Invoke, (const void*) mt_._HierarchyObjectInterface_RemoveChildren));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_HierarchyObjectInterface_RemoveChildren;
		void RemoveAllChildren() 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<HierarchyObjectInterface>();
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._HierarchyObjectInterface_RemoveAllChildren_Offset)};
			(*handler_)(_fn_HierarchyObjectInterface_RemoveAllChildren, o_, maxon::reflection::ProxyInvocation(nullptr, proxy_args, &maxon::reflection::Invocation<void, maxon::GenericComponent*>::Invoke, (const void*) mt_._HierarchyObjectInterface_RemoveAllChildren));
		}
		static const maxon::reflection::Function* _fn_HierarchyObjectInterface_RemoveAllChildren;
		Result<Data> GetOwner() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<HierarchyObjectInterface>();
			Result<Data> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._HierarchyObjectInterface_GetOwner_Offset)};
			(*handler_)(_fn_HierarchyObjectInterface_GetOwner, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<Data>, const maxon::GenericComponent*>::Invoke, (const void*) mt_._HierarchyObjectInterface_GetOwner));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_HierarchyObjectInterface_GetOwner;
		typename HIERARCHY::template Child<Interface>::type GetFirstChild(const ConstDataPtr& branchId) const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<HierarchyObjectInterface>();
			typename HIERARCHY::template Child<Interface>::type proxy_result = maxon::PrivateNullReturnValue<typename HIERARCHY::template Child<Interface>::type>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._HierarchyObjectInterface_GetFirstChild_Offset), maxon::reflection::Argument::ByReference(branchId)};
			(*handler_)(_fn_HierarchyObjectInterface_GetFirstChild, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<typename HIERARCHY::template Child<Interface>::type, const maxon::GenericComponent*, const ConstDataPtr&>::Invoke, (const void*) mt_._HierarchyObjectInterface_GetFirstChild));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_HierarchyObjectInterface_GetFirstChild;
		typename HIERARCHY::template Child<Interface>::type GetLastChild(const ConstDataPtr& branchId) const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<HierarchyObjectInterface>();
			typename HIERARCHY::template Child<Interface>::type proxy_result = maxon::PrivateNullReturnValue<typename HIERARCHY::template Child<Interface>::type>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._HierarchyObjectInterface_GetLastChild_Offset), maxon::reflection::Argument::ByReference(branchId)};
			(*handler_)(_fn_HierarchyObjectInterface_GetLastChild, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<typename HIERARCHY::template Child<Interface>::type, const maxon::GenericComponent*, const ConstDataPtr&>::Invoke, (const void*) mt_._HierarchyObjectInterface_GetLastChild));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_HierarchyObjectInterface_GetLastChild;
		typename HIERARCHY::template Child<Interface>::type GetChildAt(Int position, const ConstDataPtr& branchId) const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<HierarchyObjectInterface>();
			typename HIERARCHY::template Child<Interface>::type proxy_result = maxon::PrivateNullReturnValue<typename HIERARCHY::template Child<Interface>::type>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._HierarchyObjectInterface_GetChildAt_Offset), maxon::reflection::Argument::ByValue(position), maxon::reflection::Argument::ByReference(branchId)};
			(*handler_)(_fn_HierarchyObjectInterface_GetChildAt, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<typename HIERARCHY::template Child<Interface>::type, const maxon::GenericComponent*, Int, const ConstDataPtr&>::Invoke, (const void*) mt_._HierarchyObjectInterface_GetChildAt));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_HierarchyObjectInterface_GetChildAt;
		Result<BaseArray<typename HIERARCHY::template Child<Interface>::type>> GetChildren(const ConstDataPtr& branchId) const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<HierarchyObjectInterface>();
			Result<BaseArray<typename HIERARCHY::template Child<Interface>::type>> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._HierarchyObjectInterface_GetChildren_Offset), maxon::reflection::Argument::ByReference(branchId)};
			(*handler_)(_fn_HierarchyObjectInterface_GetChildren, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<BaseArray<typename HIERARCHY::template Child<Interface>::type>>, const maxon::GenericComponent*, const ConstDataPtr&>::Invoke, (const void*) mt_._HierarchyObjectInterface_GetChildren));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_HierarchyObjectInterface_GetChildren;
		Result<BaseArray<ConstDataPtr>> GetBranches() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<HierarchyObjectInterface>();
			Result<BaseArray<ConstDataPtr>> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._HierarchyObjectInterface_GetBranches_Offset)};
			(*handler_)(_fn_HierarchyObjectInterface_GetBranches, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<BaseArray<ConstDataPtr>>, const maxon::GenericComponent*>::Invoke, (const void*) mt_._HierarchyObjectInterface_GetBranches));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_HierarchyObjectInterface_GetBranches;
		typename HIERARCHY::template Parent<Interface>::type GetParent() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<HierarchyObjectInterface>();
			typename HIERARCHY::template Parent<Interface>::type proxy_result = maxon::PrivateNullReturnValue<typename HIERARCHY::template Parent<Interface>::type>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._HierarchyObjectInterface_GetParent_Offset)};
			(*handler_)(_fn_HierarchyObjectInterface_GetParent, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<typename HIERARCHY::template Parent<Interface>::type, const maxon::GenericComponent*>::Invoke, (const void*) mt_._HierarchyObjectInterface_GetParent));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_HierarchyObjectInterface_GetParent;
		typename HIERARCHY::template Sibling<Interface>::type GetNext() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<HierarchyObjectInterface>();
			typename HIERARCHY::template Sibling<Interface>::type proxy_result = maxon::PrivateNullReturnValue<typename HIERARCHY::template Sibling<Interface>::type>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._HierarchyObjectInterface_GetNext_Offset)};
			(*handler_)(_fn_HierarchyObjectInterface_GetNext, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<typename HIERARCHY::template Sibling<Interface>::type, const maxon::GenericComponent*>::Invoke, (const void*) mt_._HierarchyObjectInterface_GetNext));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_HierarchyObjectInterface_GetNext;
		typename HIERARCHY::template Sibling<Interface>::type GetPrev() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<HierarchyObjectInterface>();
			typename HIERARCHY::template Sibling<Interface>::type proxy_result = maxon::PrivateNullReturnValue<typename HIERARCHY::template Sibling<Interface>::type>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._HierarchyObjectInterface_GetPrev_Offset)};
			(*handler_)(_fn_HierarchyObjectInterface_GetPrev, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<typename HIERARCHY::template Sibling<Interface>::type, const maxon::GenericComponent*>::Invoke, (const void*) mt_._HierarchyObjectInterface_GetPrev));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_HierarchyObjectInterface_GetPrev;
		void ParentChanged(Bool removed) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<HierarchyObjectInterface>();
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._HierarchyObjectInterface_ParentChanged_Offset), maxon::reflection::Argument::ByValue(removed)};
			(*handler_)(_fn_HierarchyObjectInterface_ParentChanged, o_, maxon::reflection::ProxyInvocation(nullptr, proxy_args, &maxon::reflection::Invocation<void, maxon::GenericComponent*, Bool>::Invoke, (const void*) mt_._HierarchyObjectInterface_ParentChanged));
		}
		static const maxon::reflection::Function* _fn_HierarchyObjectInterface_ParentChanged;
		maxon::ObservableRef<ObservableHierarchyInsertDelegate> ObservableHierarchyInsert() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<HierarchyObjectInterface>();
			maxon::ObservableRef<ObservableHierarchyInsertDelegate> proxy_result = maxon::ObservableRef<ObservableHierarchyInsertDelegate>::NullValue();
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._HierarchyObjectInterface_ObservableHierarchyInsert_Offset)};
			(*handler_)(_fn_HierarchyObjectInterface_ObservableHierarchyInsert, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<maxon::ObservableRef<ObservableHierarchyInsertDelegate>, const maxon::GenericComponent*>::Invoke, (const void*) mt_._HierarchyObjectInterface_ObservableHierarchyInsert));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_HierarchyObjectInterface_ObservableHierarchyInsert;
		maxon::ObservableRef<ObservableHierarchyRemoveDelegate> ObservableHierarchyRemove() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<HierarchyObjectInterface>();
			maxon::ObservableRef<ObservableHierarchyRemoveDelegate> proxy_result = maxon::ObservableRef<ObservableHierarchyRemoveDelegate>::NullValue();
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._HierarchyObjectInterface_ObservableHierarchyRemove_Offset)};
			(*handler_)(_fn_HierarchyObjectInterface_ObservableHierarchyRemove, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<maxon::ObservableRef<ObservableHierarchyRemoveDelegate>, const maxon::GenericComponent*>::Invoke, (const void*) mt_._HierarchyObjectInterface_ObservableHierarchyRemove));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_HierarchyObjectInterface_ObservableHierarchyRemove;
	};
	const maxon::reflection::Function* HierarchyObjectInterface::ProxyComponent::_fn_HierarchyObjectInterface_InsertBefore;
	const maxon::reflection::Function* HierarchyObjectInterface::ProxyComponent::_fn_HierarchyObjectInterface_InsertAfter;
	const maxon::reflection::Function* HierarchyObjectInterface::ProxyComponent::_fn_HierarchyObjectInterface_InsertAsFirstChildOf;
	const maxon::reflection::Function* HierarchyObjectInterface::ProxyComponent::_fn_HierarchyObjectInterface_InsertAsLastChildOf;
	const maxon::reflection::Function* HierarchyObjectInterface::ProxyComponent::_fn_HierarchyObjectInterface_InsertAsChildAt;
	const maxon::reflection::Function* HierarchyObjectInterface::ProxyComponent::_fn_HierarchyObjectInterface_InsertChildAsFirst;
	const maxon::reflection::Function* HierarchyObjectInterface::ProxyComponent::_fn_HierarchyObjectInterface_InsertChildAsLast;
	const maxon::reflection::Function* HierarchyObjectInterface::ProxyComponent::_fn_HierarchyObjectInterface_InsertChildAt;
	const maxon::reflection::Function* HierarchyObjectInterface::ProxyComponent::_fn_HierarchyObjectInterface_InsertChildrenAsFirst;
	const maxon::reflection::Function* HierarchyObjectInterface::ProxyComponent::_fn_HierarchyObjectInterface_InsertChildrenAsLast;
	const maxon::reflection::Function* HierarchyObjectInterface::ProxyComponent::_fn_HierarchyObjectInterface_InsertChildrenAt;
	const maxon::reflection::Function* HierarchyObjectInterface::ProxyComponent::_fn_HierarchyObjectInterface_Replace;
	const maxon::reflection::Function* HierarchyObjectInterface::ProxyComponent::_fn_HierarchyObjectInterface_Remove;
	const maxon::reflection::Function* HierarchyObjectInterface::ProxyComponent::_fn_HierarchyObjectInterface_RemoveChildren;
	const maxon::reflection::Function* HierarchyObjectInterface::ProxyComponent::_fn_HierarchyObjectInterface_RemoveAllChildren;
	const maxon::reflection::Function* HierarchyObjectInterface::ProxyComponent::_fn_HierarchyObjectInterface_GetOwner;
	const maxon::reflection::Function* HierarchyObjectInterface::ProxyComponent::_fn_HierarchyObjectInterface_GetFirstChild;
	const maxon::reflection::Function* HierarchyObjectInterface::ProxyComponent::_fn_HierarchyObjectInterface_GetLastChild;
	const maxon::reflection::Function* HierarchyObjectInterface::ProxyComponent::_fn_HierarchyObjectInterface_GetChildAt;
	const maxon::reflection::Function* HierarchyObjectInterface::ProxyComponent::_fn_HierarchyObjectInterface_GetChildren;
	const maxon::reflection::Function* HierarchyObjectInterface::ProxyComponent::_fn_HierarchyObjectInterface_GetBranches;
	const maxon::reflection::Function* HierarchyObjectInterface::ProxyComponent::_fn_HierarchyObjectInterface_GetParent;
	const maxon::reflection::Function* HierarchyObjectInterface::ProxyComponent::_fn_HierarchyObjectInterface_GetNext;
	const maxon::reflection::Function* HierarchyObjectInterface::ProxyComponent::_fn_HierarchyObjectInterface_GetPrev;
	const maxon::reflection::Function* HierarchyObjectInterface::ProxyComponent::_fn_HierarchyObjectInterface_ParentChanged;
	const maxon::reflection::Function* HierarchyObjectInterface::ProxyComponent::_fn_HierarchyObjectInterface_ObservableHierarchyInsert;
	const maxon::reflection::Function* HierarchyObjectInterface::ProxyComponent::_fn_HierarchyObjectInterface_ObservableHierarchyRemove;
	PRIVATE_MAXON_COMPONENT_REGISTER(HierarchyObjectInterface::ProxyComponent, , typename, maxon::EntityBase::FLAGS::PROXY, ::MaxonRegistry, maxon::LiteralId());
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	static maxon::Result<void> RegisterReflection_HierarchyObjectInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "nextSibling\0", 1LL, HierarchyObjectInterface, _HierarchyObjectInterface_InsertBefore),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "prevSibling\0", 1LL, HierarchyObjectInterface, _HierarchyObjectInterface_InsertAfter),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "parent\0branchId\0", 5LL, HierarchyObjectInterface, _HierarchyObjectInterface_InsertAsFirstChildOf),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "parent\0branchId\0", 5LL, HierarchyObjectInterface, _HierarchyObjectInterface_InsertAsLastChildOf),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "parent\0position\0branchId\0", 21LL, HierarchyObjectInterface, _HierarchyObjectInterface_InsertAsChildAt),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "child\0branchId\0", 5LL, HierarchyObjectInterface, _HierarchyObjectInterface_InsertChildAsFirst),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "child\0branchId\0", 5LL, HierarchyObjectInterface, _HierarchyObjectInterface_InsertChildAsLast),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "child\0position\0branchId\0", 21LL, HierarchyObjectInterface, _HierarchyObjectInterface_InsertChildAt),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "children\0branchId\0", 5LL, HierarchyObjectInterface, _HierarchyObjectInterface_InsertChildrenAsFirst),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "children\0branchId\0", 5LL, HierarchyObjectInterface, _HierarchyObjectInterface_InsertChildrenAsLast),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "children\0position\0branchId\0", 21LL, HierarchyObjectInterface, _HierarchyObjectInterface_InsertChildrenAt),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "newObject\0", 0LL, HierarchyObjectInterface, _HierarchyObjectInterface_Replace),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, HierarchyObjectInterface, _HierarchyObjectInterface_Remove),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "branchId\0", 1LL, HierarchyObjectInterface, _HierarchyObjectInterface_RemoveChildren),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, HierarchyObjectInterface, _HierarchyObjectInterface_RemoveAllChildren),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, HierarchyObjectInterface, _HierarchyObjectInterface_GetOwner),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "branchId\0", 1LL, HierarchyObjectInterface, _HierarchyObjectInterface_GetFirstChild),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "branchId\0", 1LL, HierarchyObjectInterface, _HierarchyObjectInterface_GetLastChild),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "position\0branchId\0", 5LL, HierarchyObjectInterface, _HierarchyObjectInterface_GetChildAt),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "branchId\0", 1LL, HierarchyObjectInterface, _HierarchyObjectInterface_GetChildren),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, HierarchyObjectInterface, _HierarchyObjectInterface_GetBranches),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, HierarchyObjectInterface, _HierarchyObjectInterface_GetParent),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, HierarchyObjectInterface, _HierarchyObjectInterface_GetNext),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, HierarchyObjectInterface, _HierarchyObjectInterface_GetPrev),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "removed\0", 1LL, HierarchyObjectInterface, _HierarchyObjectInterface_ParentChanged),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, HierarchyObjectInterface, _HierarchyObjectInterface_ObservableHierarchyInsert),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, HierarchyObjectInterface, _HierarchyObjectInterface_ObservableHierarchyRemove),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&HierarchyObjectInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	static maxon::reflection::ContainerInfo g_reflection_HierarchyObjectInterface(nullptr, &HierarchyObjectInterface::ProxyComponent::_descriptor, &RegisterReflection_HierarchyObjectInterface, &PRIVATE_MAXON_MODULE);
#endif
}
#endif
