
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1

struct IoDualInOutputStreamInterface::MTable
{
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetInputStream);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetOutputStream);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(SetInputStream);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(SetOutputStream);
	static const maxon::Char* const _ids;
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	PRIVATE_MAXON_MF_POINTER(IoDualInOutputStreamInterface_SetInputStream, SetInputStream, true, maxon::GenericComponent,, (Result<void>), const InputStreamRef& inputStream);
	maxon::Int IoDualInOutputStreamInterface_SetInputStream_Offset;
	PRIVATE_MAXON_MF_POINTER(IoDualInOutputStreamInterface_SetOutputStream, SetOutputStream, true, maxon::GenericComponent,, (Result<void>), const OutputStreamRef& outputStream);
	maxon::Int IoDualInOutputStreamInterface_SetOutputStream_Offset;
	PRIVATE_MAXON_MF_POINTER(IoDualInOutputStreamInterface_GetInputStream, GetInputStream, true, maxon::GenericComponent, const, (InputStreamRef));
	maxon::Int IoDualInOutputStreamInterface_GetInputStream_Offset;
	PRIVATE_MAXON_MF_POINTER(IoDualInOutputStreamInterface_GetOutputStream, GetOutputStream, true, maxon::GenericComponent, const, (OutputStreamRef));
	maxon::Int IoDualInOutputStreamInterface_GetOutputStream_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, IoDualInOutputStreamInterface, SetInputStream))
	{
		maxon::Tie(IoDualInOutputStreamInterface_SetInputStream, IoDualInOutputStreamInterface_SetInputStream_Offset) = IoDualInOutputStreamInterface_SetInputStream_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, IoDualInOutputStreamInterface, SetOutputStream))
	{
		maxon::Tie(IoDualInOutputStreamInterface_SetOutputStream, IoDualInOutputStreamInterface_SetOutputStream_Offset) = IoDualInOutputStreamInterface_SetOutputStream_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, IoDualInOutputStreamInterface, GetInputStream))
	{
		maxon::Tie(IoDualInOutputStreamInterface_GetInputStream, IoDualInOutputStreamInterface_GetInputStream_Offset) = IoDualInOutputStreamInterface_GetInputStream_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, IoDualInOutputStreamInterface, GetOutputStream))
	{
		maxon::Tie(IoDualInOutputStreamInterface_GetOutputStream, IoDualInOutputStreamInterface_GetOutputStream_Offset) = IoDualInOutputStreamInterface_GetOutputStream_GetPtr<W>(offset, true);
	}
	}
	template <typename S> using CombinedMTable = maxon::PrivateCombinedMTable<IoDualInOutputStreamInterface, typename InOutputStreamInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<IoDualInOutputStreamInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct IoDualInOutputStreamInterface::Hxx2
{
	template <typename S> class CWrapper : public InOutputStreamInterface::Hxx2::template CWrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetInputStream);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetOutputStream);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(SetInputStream);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(SetOutputStream);
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename InOutputStreamInterface::Hxx2::template CWrapper<S>;
			if constexpr (!S::Implementation::PROXY)
			{
				if (!(Super0::InitMTablesWithBases(info, offset))) return false;
			}
			auto* vt = (IoDualInOutputStreamInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, IoDualInOutputStreamInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		PRIVATE_MAXON_MF_WRAPPER(IoDualInOutputStreamInterface_SetInputStream, maxon::GenericComponent,, (Result<void>), const InputStreamRef& inputStream) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->SetInputStream(inputStream); }
		PRIVATE_MAXON_MF_WRAPPER(IoDualInOutputStreamInterface_SetOutputStream, maxon::GenericComponent,, (Result<void>), const OutputStreamRef& outputStream) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->SetOutputStream(outputStream); }
		PRIVATE_MAXON_MF_WRAPPER(IoDualInOutputStreamInterface_GetInputStream, maxon::GenericComponent, const, (InputStreamRef)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetInputStream(); }
		PRIVATE_MAXON_MF_WRAPPER(IoDualInOutputStreamInterface_GetOutputStream, maxon::GenericComponent, const, (OutputStreamRef)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetOutputStream(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto IoDualInOutputStreamInterface::SetInputStream(const InputStreamRef& inputStream) -> Result<void>
{
	const IoDualInOutputStreamInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(IoDualInOutputStreamInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.IoDualInOutputStreamInterface_SetInputStream_Offset), mt_.IoDualInOutputStreamInterface_SetInputStream, inputStream);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto IoDualInOutputStreamInterface::SetOutputStream(const OutputStreamRef& outputStream) -> Result<void>
{
	const IoDualInOutputStreamInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(IoDualInOutputStreamInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.IoDualInOutputStreamInterface_SetOutputStream_Offset), mt_.IoDualInOutputStreamInterface_SetOutputStream, outputStream);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto IoDualInOutputStreamInterface::GetInputStream() const -> InputStreamRef
{
	const IoDualInOutputStreamInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(IoDualInOutputStreamInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.IoDualInOutputStreamInterface_GetInputStream_Offset), mt_.IoDualInOutputStreamInterface_GetInputStream);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto IoDualInOutputStreamInterface::GetOutputStream() const -> OutputStreamRef
{
	const IoDualInOutputStreamInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(IoDualInOutputStreamInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.IoDualInOutputStreamInterface_GetOutputStream_Offset), mt_.IoDualInOutputStreamInterface_GetOutputStream);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoDualInOutputStreamInterface::Hxx1::Fn<S>::SetInputStream(const InputStreamRef& inputStream) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) HXXTABLE(IoDualInOutputStreamInterface_SetInputStream); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.IoDualInOutputStreamInterface_SetInputStream_Offset), mt_.IoDualInOutputStreamInterface_SetInputStream, inputStream));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoDualInOutputStreamInterface::Hxx1::COWFn<S>::SetInputStream(const InputStreamRef& inputStream) -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(IoDualInOutputStreamInterface_SetInputStream); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.IoDualInOutputStreamInterface_SetInputStream_Offset), mt_.IoDualInOutputStreamInterface_SetInputStream, inputStream));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoDualInOutputStreamInterface::Hxx1::Fn<S>::SetOutputStream(const OutputStreamRef& outputStream) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) HXXTABLE(IoDualInOutputStreamInterface_SetOutputStream); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.IoDualInOutputStreamInterface_SetOutputStream_Offset), mt_.IoDualInOutputStreamInterface_SetOutputStream, outputStream));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoDualInOutputStreamInterface::Hxx1::COWFn<S>::SetOutputStream(const OutputStreamRef& outputStream) -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(IoDualInOutputStreamInterface_SetOutputStream); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.IoDualInOutputStreamInterface_SetOutputStream_Offset), mt_.IoDualInOutputStreamInterface_SetOutputStream, outputStream));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoDualInOutputStreamInterface::Hxx1::ConstFn<S>::GetInputStream() const -> HXXADDRET2(InputStreamRef)
{
	HXXRETURN0(HXXADDRET2(InputStreamRef)); HXXRES; HXXCONST(HXXRET3(NULLPTR, InputStreamRef)) HXXTABLE(IoDualInOutputStreamInterface_GetInputStream); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.IoDualInOutputStreamInterface_GetInputStream_Offset), mt_.IoDualInOutputStreamInterface_GetInputStream));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoDualInOutputStreamInterface::Hxx1::ConstFn<S>::GetOutputStream() const -> HXXADDRET2(OutputStreamRef)
{
	HXXRETURN0(HXXADDRET2(OutputStreamRef)); HXXRES; HXXCONST(HXXRET3(NULLPTR, OutputStreamRef)) HXXTABLE(IoDualInOutputStreamInterface_GetOutputStream); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.IoDualInOutputStreamInterface_GetOutputStream_Offset), mt_.IoDualInOutputStreamInterface_GetOutputStream));
}
auto IoDualInOutputStreamInterface::GetPtr() -> Ptr { return Ptr(this); }
auto IoDualInOutputStreamInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_iostream_dualinoutput)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_IoDualInOutputStreamInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_IoDualInOutputStreamInterface() { new (s_ui_maxon_IoDualInOutputStreamInterface) maxon::EntityUse(IoDualInOutputStreamInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/iostream_dualinoutput.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_IoDualInOutputStreamInterface(IoDualInOutputStreamInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/iostream_dualinoutput.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

