#if 1
class IoDualInOutputStreamRef;

struct IoDualInOutputStreamInterface::HasBaseDetector { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, IoDualInOutputStreamInterface>::value || InOutputStreamInterface::HasBaseDetector::template Check<I>::value; static I* Cast(IoDualInOutputStreamInterface* ptr) { return reinterpret_cast<I*>(ptr); } }; };
struct IoDualInOutputStreamInterface::Hxx1
{
	class Reference;
	using ReferenceClass = IoDualInOutputStreamRef;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<InOutputStreamInterface>;
	/// Intermediate helper class for IoDualInOutputStreamInterface.
	template <typename S> class ConstFn DOXYGEN_SWITCH_REVERSED(, : public S)
	{
	public:
		ConstFn() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateInterface = IoDualInOutputStreamInterface;
		using PrivateBaseClass::PrivateLookupFn;
		static ConstFn PrivateLookupFn(IoDualInOutputStreamInterface**);
/// Returns the handle used for reading.
		inline HXXADDRET2(InputStreamRef) GetInputStream() const;
/// Returns the handle used for writing.
		inline HXXADDRET2(OutputStreamRef) GetOutputStream() const;
	};
	/// Intermediate helper class for IoDualInOutputStreamInterface.
	template <typename S> class Fn : public ConstFn<S>
	{
	public:
		Fn() = default;
		using PrivateBaseClass = ConstFn<S>;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateInterface = IoDualInOutputStreamInterface;
		using PrivateBaseClass::PrivateLookupFn;
		static Fn PrivateLookupFn(IoDualInOutputStreamInterface**);
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, IoDualInOutputStreamRef, true>::type&() const { return reinterpret_cast<const IoDualInOutputStreamRef&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, IoDualInOutputStreamRef, false>::type&() { return reinterpret_cast<const IoDualInOutputStreamRef&>(this->GetBaseRef()); }
/// Sets the handle for the input stream used for reading.
/// @param[in] inputStream				Reference to the stream used for read.
/// @return												OK on success.
		inline Result<void> SetInputStream(const InputStreamRef& inputStream) const;
/// Sets the handle for the output stream used for writing.
/// @param[in] outputStream				Reference to the stream used for write.
/// @return												OK on success.
		inline Result<void> SetOutputStream(const OutputStreamRef& outputStream) const;
	};
	/// Intermediate helper class for IoDualInOutputStreamInterface.
	template <typename S> class COWFn : public ConstFn<S>
	{
	public:
		COWFn() = default;
		using PrivateBaseClass = ConstFn<S>;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateInterface = IoDualInOutputStreamInterface;
		using PrivateBaseClass::PrivateLookupFn;
		static COWFn PrivateLookupFn(IoDualInOutputStreamInterface**);
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, IoDualInOutputStreamRef, false>::type&() { return reinterpret_cast<const IoDualInOutputStreamRef&>(this->GetBaseRef()); }
/// Sets the handle for the input stream used for reading.
/// @param[in] inputStream				Reference to the stream used for read.
/// @return												OK on success.
		inline Result<void> SetInputStream(const InputStreamRef& inputStream);
/// Sets the handle for the output stream used for writing.
/// @param[in] outputStream				Reference to the stream used for write.
/// @return												OK on success.
		inline Result<void> SetOutputStream(const OutputStreamRef& outputStream);
	};
	template <typename ST> struct FnHelper : public std::conditional<
	maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)),
	COWFn<typename InOutputStreamInterface::Hxx1::template FnHelper<ST>::type>,
	typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstFn<typename InOutputStreamInterface::Hxx1::template FnHelper<ST>::type>, Fn<typename InOutputStreamInterface::Hxx1::template FnHelper<ST>::type>>::type
	> { };
};
class IoDualInOutputStreamInterface::Hxx1::Reference :
#ifdef DOXYGEN
public FnDoxy<IoDualInOutputStreamRef>
#else
public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<IoDualInOutputStreamInterface, maxon::StrongRefHandler, IoDualInOutputStreamRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<IoDualInOutputStreamInterface, maxon::StrongRefHandler, IoDualInOutputStreamRef>>>>);
	using NonConst = typename Super::ReferenceClass;
};

/// IoDualInOutputStreamRef is the reference class of IoDualInOutputStreamInterface.
///
/// Advanced Interface of InOutputStreamInterface which allows to create an InOutputStreamInterface where the read and write has two different stream handles.
/// One stream is for reading, the other for writing data.<br>
/// - GetError() returns the error code of the input stream and if this has no error, of the output stream.<br>
/// - SetError() sets the error code in both streams.<br>
/// - GetPosition(), GetLength(), SeekSupported(), Seek() are not allowed to call because it's not defined which stream is meant. Use GetInputStream().function() instead.<br>
/// - Close() closes both streams.<br>
class IoDualInOutputStreamRef : public IoDualInOutputStreamInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(IoDualInOutputStreamRef, typename IoDualInOutputStreamInterface::Hxx1::Reference);
	using ConstPtr = typename IoDualInOutputStreamInterface::ConstPtr;
};

#endif
