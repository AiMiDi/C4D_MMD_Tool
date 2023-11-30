
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1

struct DecoratorInterface::MTable
{
	PRIVATE_MAXON_IMPLEMENTS_CHECK(PrivateGetDecoratedObject);
	static const maxon::Char* const _ids;
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	PRIVATE_MAXON_MF_POINTER(DecoratorInterface_PrivateGetDecoratedObject, PrivateGetDecoratedObject, true, maxon::GenericComponent, const, (ObjectRef));
	maxon::Int DecoratorInterface_PrivateGetDecoratedObject_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DecoratorInterface, PrivateGetDecoratedObject))
	{
		maxon::Tie(DecoratorInterface_PrivateGetDecoratedObject, DecoratorInterface_PrivateGetDecoratedObject_Offset) = DecoratorInterface_PrivateGetDecoratedObject_GetPtr<W>(offset, true);
	}
	}
	template <typename S> using CombinedMTable = maxon::PrivateCombinedMTable<DecoratorInterface, typename ObjectInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<DecoratorInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct DecoratorInterface::Hxx2
{
	template <typename S> class CWrapper : public ObjectInterface::Hxx2::template CWrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(PrivateGetDecoratedObject);
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename ObjectInterface::Hxx2::template CWrapper<S>;
			if constexpr (!S::Implementation::PROXY)
			{
				if (!(Super0::InitMTablesWithBases(info, offset))) return false;
			}
			auto* vt = (DecoratorInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, DecoratorInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		PRIVATE_MAXON_MF_WRAPPER(DecoratorInterface_PrivateGetDecoratedObject, maxon::GenericComponent, const, (ObjectRef)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->PrivateGetDecoratedObject(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto DecoratorInterface::PrivateGetDecoratedObject() const -> ObjectRef
{
	const DecoratorInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DecoratorInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.DecoratorInterface_PrivateGetDecoratedObject_Offset), mt_.DecoratorInterface_PrivateGetDecoratedObject);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DecoratorInterface::Hxx1::ConstFn<S>::PrivateGetDecoratedObject() const -> HXXADDRET2(ObjectRef)
{
	HXXRETURN0(HXXADDRET2(ObjectRef)); HXXINVOKE("DecoratorInterface::PrivateGetDecoratedObject"); HXXRES; HXXCONST(HXXRET3(NULLPTR, ObjectRef)) HXXTABLE(DecoratorInterface_PrivateGetDecoratedObject); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.DecoratorInterface_PrivateGetDecoratedObject_Offset), mt_.DecoratorInterface_PrivateGetDecoratedObject));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DecoratorInterface::Hxx1::ConstFn<S>::GetDecoratedObject() const -> HXXADDRET2(ObjectBaseRef<maxon::details::GetPrivateReferencedType<S>>)
{
	HXXRETURN0(HXXADDRET2(ObjectBaseRef<maxon::details::GetPrivateReferencedType<S>>)); HXXSUPER("DecoratorInterface::GetDecoratedObject"); HXXRES; HXXCONST(maxon::PrivateDefaultReturnValue<ObjectBaseRef<maxon::details::GetPrivateReferencedType<S>>>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK)) 
	return (o_->GetDecoratedObject<maxon::details::GetPrivateReferencedType<S>>());
}
auto DecoratorInterface::GetPtr() -> Ptr { return Ptr(this); }
auto DecoratorInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_decorator)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_DecoratorInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_DecoratorInterface() { new (s_ui_maxon_DecoratorInterface) maxon::EntityUse(DecoratorInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/decorator.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_DecoratorInterface(DecoratorInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/decorator.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif

struct EagerDecoratorInterface::MTable
{
	PRIVATE_MAXON_IMPLEMENTS_CHECK(PrivateSetDecoratedObject);
	static const maxon::Char* const _ids;
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	PRIVATE_MAXON_MF_POINTER(EagerDecoratorInterface_PrivateSetDecoratedObject, PrivateSetDecoratedObject, true, maxon::GenericComponent,, (void), const ObjectRef& object);
	maxon::Int EagerDecoratorInterface_PrivateSetDecoratedObject_Offset;
	PRIVATE_MAXON_MF_POINTER(EagerDecoratorInterface_PrivateSetDecoratedObject_1, PrivateSetDecoratedObject, true, maxon::GenericComponent,, (void), ObjectRef&& object);
	maxon::Int EagerDecoratorInterface_PrivateSetDecoratedObject_1_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, EagerDecoratorInterface, PrivateSetDecoratedObject))
	{
		maxon::Tie(EagerDecoratorInterface_PrivateSetDecoratedObject, EagerDecoratorInterface_PrivateSetDecoratedObject_Offset) = EagerDecoratorInterface_PrivateSetDecoratedObject_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, EagerDecoratorInterface, PrivateSetDecoratedObject))
	{
		maxon::Tie(EagerDecoratorInterface_PrivateSetDecoratedObject_1, EagerDecoratorInterface_PrivateSetDecoratedObject_1_Offset) = EagerDecoratorInterface_PrivateSetDecoratedObject_1_GetPtr<W>(offset, true);
	}
	}
	template <typename S> using CombinedMTable = maxon::PrivateCombinedMTable<EagerDecoratorInterface, typename DecoratorInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<EagerDecoratorInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct EagerDecoratorInterface::Hxx2
{
	template <typename S> class CWrapper : public DecoratorInterface::Hxx2::template CWrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(PrivateSetDecoratedObject);
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename DecoratorInterface::Hxx2::template CWrapper<S>;
			if constexpr (!S::Implementation::PROXY)
			{
				if (!(Super0::InitMTablesWithBases(info, offset))) return false;
			}
			auto* vt = (EagerDecoratorInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, EagerDecoratorInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		PRIVATE_MAXON_MF_WRAPPER(EagerDecoratorInterface_PrivateSetDecoratedObject, maxon::GenericComponent,, (void), const ObjectRef& object) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->PrivateSetDecoratedObject(object); }
		PRIVATE_MAXON_MF_WRAPPER(EagerDecoratorInterface_PrivateSetDecoratedObject_1, maxon::GenericComponent,, (void), ObjectRef&& object) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->PrivateSetDecoratedObject(std::forward<ObjectRef>(object)); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto EagerDecoratorInterface::PrivateSetDecoratedObject(const ObjectRef& object) -> void
{
	const EagerDecoratorInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(EagerDecoratorInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.EagerDecoratorInterface_PrivateSetDecoratedObject_Offset), mt_.EagerDecoratorInterface_PrivateSetDecoratedObject, object);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto EagerDecoratorInterface::PrivateSetDecoratedObject(ObjectRef&& object) -> void
{
	const EagerDecoratorInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(EagerDecoratorInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.EagerDecoratorInterface_PrivateSetDecoratedObject_1_Offset), mt_.EagerDecoratorInterface_PrivateSetDecoratedObject_1, std::forward<ObjectRef>(object));
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto EagerDecoratorInterface::Hxx1::Fn<S>::PrivateSetDecoratedObject(const ObjectRef& object) const -> HXXADDRET2(void)
{
	HXXRETURN0(HXXADDRET2(void)); HXXINVOKE("EagerDecoratorInterface::PrivateSetDecoratedObject"); HXXRES; HXXNONCONST(DebugStop(), , false, maxon::PrivateLogNullptrError()) HXXTABLE(EagerDecoratorInterface_PrivateSetDecoratedObject); 
	PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.EagerDecoratorInterface_PrivateSetDecoratedObject_Offset), mt_.EagerDecoratorInterface_PrivateSetDecoratedObject, object);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto EagerDecoratorInterface::Hxx1::COWFn<S>::PrivateSetDecoratedObject(const ObjectRef& object) -> HXXADDRET1(void)
{
	HXXRETURN0(HXXADDRET1(void)); HXXINVOKE("EagerDecoratorInterface::PrivateSetDecoratedObject"); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(EagerDecoratorInterface_PrivateSetDecoratedObject); 
	PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.EagerDecoratorInterface_PrivateSetDecoratedObject_Offset), mt_.EagerDecoratorInterface_PrivateSetDecoratedObject, object);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto EagerDecoratorInterface::Hxx1::Fn<S>::SetDecoratedObject(const ObjectBaseRef<maxon::details::GetPrivateReferencedType<S>>& object) const -> HXXADDRET2(void)
{
	HXXRETURN0(HXXADDRET2(void)); HXXRES; HXXNONCONST(DebugStop(), , false, maxon::PrivateLogNullptrError()) 
	o_->SetDecoratedObject<maxon::details::GetPrivateReferencedType<S>>(object);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto EagerDecoratorInterface::Hxx1::COWFn<S>::SetDecoratedObject(const ObjectBaseRef<maxon::details::GetPrivateReferencedType<S>>& object) -> HXXADDRET1(void)
{
	HXXRETURN0(HXXADDRET1(void)); HXXSUPER("EagerDecoratorInterface::SetDecoratedObject"); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) 
	o_->SetDecoratedObject<maxon::details::GetPrivateReferencedType<S>>(object);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto EagerDecoratorInterface::Hxx1::Fn<S>::PrivateSetDecoratedObject(ObjectRef&& object) const -> HXXADDRET2(void)
{
	HXXRETURN0(HXXADDRET2(void)); HXXINVOKE("EagerDecoratorInterface::PrivateSetDecoratedObject"); HXXRES; HXXNONCONST(DebugStop(), , false, maxon::PrivateLogNullptrError()) HXXTABLE(EagerDecoratorInterface_PrivateSetDecoratedObject_1); 
	PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.EagerDecoratorInterface_PrivateSetDecoratedObject_1_Offset), mt_.EagerDecoratorInterface_PrivateSetDecoratedObject_1, std::forward<ObjectRef>(object));
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto EagerDecoratorInterface::Hxx1::COWFn<S>::PrivateSetDecoratedObject(ObjectRef&& object) -> HXXADDRET1(void)
{
	HXXRETURN0(HXXADDRET1(void)); HXXINVOKE("EagerDecoratorInterface::PrivateSetDecoratedObject"); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(EagerDecoratorInterface_PrivateSetDecoratedObject_1); 
	PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.EagerDecoratorInterface_PrivateSetDecoratedObject_1_Offset), mt_.EagerDecoratorInterface_PrivateSetDecoratedObject_1, std::forward<ObjectRef>(object));
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto EagerDecoratorInterface::Hxx1::Fn<S>::SetDecoratedObject(ObjectBaseRef<maxon::details::GetPrivateReferencedType<S>>&& object) const -> HXXADDRET2(void)
{
	HXXRETURN0(HXXADDRET2(void)); HXXRES; HXXNONCONST(DebugStop(), , false, maxon::PrivateLogNullptrError()) 
	o_->SetDecoratedObject<maxon::details::GetPrivateReferencedType<S>>(std::forward<ObjectBaseRef<maxon::details::GetPrivateReferencedType<S>>>(object));
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto EagerDecoratorInterface::Hxx1::COWFn<S>::SetDecoratedObject(ObjectBaseRef<maxon::details::GetPrivateReferencedType<S>>&& object) -> HXXADDRET1(void)
{
	HXXRETURN0(HXXADDRET1(void)); HXXSUPER("EagerDecoratorInterface::SetDecoratedObject"); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) 
	o_->SetDecoratedObject<maxon::details::GetPrivateReferencedType<S>>(std::forward<ObjectBaseRef<maxon::details::GetPrivateReferencedType<S>>>(object));
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
auto EagerDecoratorInterface::GetPtr() -> Ptr { return Ptr(this); }
auto EagerDecoratorInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_decorator)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_EagerDecoratorInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_EagerDecoratorInterface() { new (s_ui_maxon_EagerDecoratorInterface) maxon::EntityUse(EagerDecoratorInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/decorator.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_EagerDecoratorInterface(EagerDecoratorInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/decorator.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif

struct WeakDecoratorInterface::MTable
{
	PRIVATE_MAXON_IMPLEMENTS_CHECK(PrivateSetDecoratedObject);
	static const maxon::Char* const _ids;
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	PRIVATE_MAXON_MF_POINTER(WeakDecoratorInterface_PrivateSetDecoratedObject, PrivateSetDecoratedObject, true, maxon::GenericComponent,, (void), const ObjectRef& object);
	maxon::Int WeakDecoratorInterface_PrivateSetDecoratedObject_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, WeakDecoratorInterface, PrivateSetDecoratedObject))
	{
		maxon::Tie(WeakDecoratorInterface_PrivateSetDecoratedObject, WeakDecoratorInterface_PrivateSetDecoratedObject_Offset) = WeakDecoratorInterface_PrivateSetDecoratedObject_GetPtr<W>(offset, true);
	}
	}
	template <typename S> using CombinedMTable = maxon::PrivateCombinedMTable<WeakDecoratorInterface, typename DecoratorInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<WeakDecoratorInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct WeakDecoratorInterface::Hxx2
{
	template <typename S> class CWrapper : public DecoratorInterface::Hxx2::template CWrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(PrivateSetDecoratedObject);
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename DecoratorInterface::Hxx2::template CWrapper<S>;
			if constexpr (!S::Implementation::PROXY)
			{
				if (!(Super0::InitMTablesWithBases(info, offset))) return false;
			}
			auto* vt = (WeakDecoratorInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, WeakDecoratorInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		PRIVATE_MAXON_MF_WRAPPER(WeakDecoratorInterface_PrivateSetDecoratedObject, maxon::GenericComponent,, (void), const ObjectRef& object) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->PrivateSetDecoratedObject(object); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto WeakDecoratorInterface::PrivateSetDecoratedObject(const ObjectRef& object) -> void
{
	const WeakDecoratorInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(WeakDecoratorInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.WeakDecoratorInterface_PrivateSetDecoratedObject_Offset), mt_.WeakDecoratorInterface_PrivateSetDecoratedObject, object);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto WeakDecoratorInterface::Hxx1::Fn<S>::PrivateSetDecoratedObject(const ObjectRef& object) const -> HXXADDRET2(void)
{
	HXXRETURN0(HXXADDRET2(void)); HXXINVOKE("WeakDecoratorInterface::PrivateSetDecoratedObject"); HXXRES; HXXNONCONST(DebugStop(), , false, maxon::PrivateLogNullptrError()) HXXTABLE(WeakDecoratorInterface_PrivateSetDecoratedObject); 
	PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.WeakDecoratorInterface_PrivateSetDecoratedObject_Offset), mt_.WeakDecoratorInterface_PrivateSetDecoratedObject, object);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto WeakDecoratorInterface::Hxx1::COWFn<S>::PrivateSetDecoratedObject(const ObjectRef& object) -> HXXADDRET1(void)
{
	HXXRETURN0(HXXADDRET1(void)); HXXINVOKE("WeakDecoratorInterface::PrivateSetDecoratedObject"); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(WeakDecoratorInterface_PrivateSetDecoratedObject); 
	PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.WeakDecoratorInterface_PrivateSetDecoratedObject_Offset), mt_.WeakDecoratorInterface_PrivateSetDecoratedObject, object);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto WeakDecoratorInterface::Hxx1::Fn<S>::SetDecoratedObject(const ObjectBaseRef<maxon::details::GetPrivateReferencedType<S>>& object) const -> HXXADDRET2(void)
{
	HXXRETURN0(HXXADDRET2(void)); HXXRES; HXXNONCONST(DebugStop(), , false, maxon::PrivateLogNullptrError()) 
	o_->SetDecoratedObject<maxon::details::GetPrivateReferencedType<S>>(object);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto WeakDecoratorInterface::Hxx1::COWFn<S>::SetDecoratedObject(const ObjectBaseRef<maxon::details::GetPrivateReferencedType<S>>& object) -> HXXADDRET1(void)
{
	HXXRETURN0(HXXADDRET1(void)); HXXSUPER("WeakDecoratorInterface::SetDecoratedObject"); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) 
	o_->SetDecoratedObject<maxon::details::GetPrivateReferencedType<S>>(object);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
auto WeakDecoratorInterface::GetPtr() -> Ptr { return Ptr(this); }
auto WeakDecoratorInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_decorator)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_WeakDecoratorInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_WeakDecoratorInterface() { new (s_ui_maxon_WeakDecoratorInterface) maxon::EntityUse(WeakDecoratorInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/decorator.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_WeakDecoratorInterface(WeakDecoratorInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/decorator.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

