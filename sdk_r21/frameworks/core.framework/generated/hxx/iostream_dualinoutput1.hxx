#if 1
class IoDualInOutputStreamRef;

struct IoDualInOutputStreamInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, IoDualInOutputStreamInterface>::value || InOutputStreamInterface::HasBase::template Check<I>::value; static I* Cast(IoDualInOutputStreamInterface* ptr) { return static_cast<I*>(static_cast<maxon::ObjectInterface*>(ptr)); } }; };
struct IoDualInOutputStreamInterface::Hxx1
{
	class Reference;
	using ReferenceClass = IoDualInOutputStreamRef;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<InOutputStreamInterface>;
	/// Intermediate helper class for IoDualInOutputStreamInterface.
	template <typename S> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
	{
	public:
		ConstReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
/// Returns the handle used for reading.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<InputStreamRef>, InputStreamRef>::type GetInputStream() const;
/// Returns the handle used for writing.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<OutputStreamRef>, OutputStreamRef>::type GetOutputStream() const;
	};
	/// Intermediate helper class for IoDualInOutputStreamInterface.
	template <typename S> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
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
	template <typename S> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
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
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename InOutputStreamInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename InOutputStreamInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, ReferenceFunctionsImpl<typename InOutputStreamInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>>::type> { };
};
class IoDualInOutputStreamInterface::Hxx1::Reference :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<IoDualInOutputStreamRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<IoDualInOutputStreamInterface, maxon::StrongRefHandler, IoDualInOutputStreamRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<IoDualInOutputStreamInterface, maxon::StrongRefHandler, IoDualInOutputStreamRef>>>>);
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
};

#endif
