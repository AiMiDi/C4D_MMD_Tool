#if 1
class DataDescriptionObjectRef;

struct DataDescriptionObjectInterface::HasBaseDetector { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, DataDescriptionObjectInterface>::value || ObjectInterface::HasBaseDetector::template Check<I>::value; static I* Cast(DataDescriptionObjectInterface* ptr) { return reinterpret_cast<I*>(ptr); } }; };
struct DataDescriptionObjectInterface::Hxx1
{
	class Reference;
	using ReferenceClass = DataDescriptionObjectRef;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<ObjectInterface>;
	/// Intermediate helper class for DataDescriptionObjectInterface.
	template <typename S> class ConstFn DOXYGEN_SWITCH_REVERSED(, : public S)
	{
	public:
		ConstFn() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateBaseClass::PrivateLookupFn;
		static ConstFn PrivateLookupFn(DataDescriptionObjectInterface**);
/// GetObjectDescription returns the description of the object.
/// @param[in] category						Description category to load (DATADESCRIPTION_CATEGORY_DATA/DATADESCRIPTION_CATEGORY_UI).
/// @param[in] language						Language (only valid for category DATADESCRIPTION_CATEGORY_STRING).
/// @param[in] objectData					Data of the object to use for evaluation.
/// @return												DataDescription on success. If the Description could not be found an empty description is returned but no error.
		inline Result<DataDescription> GetObjectDescription(const Id& category, const LanguageRef& language, const DataDictionaryObjectRef& objectData) const;
/// GetObjectName returns the localized name of the description (OBJECT::BASE::NAME).
/// @param[in] classId						Id of the class to determine.
/// @param[in] language						Language to use. "nullptr" for current language.
/// @return												String on success.
		static inline Result<String> GetObjectName(const Id& classId, const LanguageRef& language);
	};
	/// Intermediate helper class for DataDescriptionObjectInterface.
	template <typename S> class Fn : public ConstFn<S>
	{
	public:
		Fn() = default;
		using PrivateBaseClass = ConstFn<S>;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateBaseClass::PrivateLookupFn;
		static Fn PrivateLookupFn(DataDescriptionObjectInterface**);
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, DataDescriptionObjectRef, true>::type&() const { return reinterpret_cast<const DataDescriptionObjectRef&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, DataDescriptionObjectRef, false>::type&() { return reinterpret_cast<const DataDescriptionObjectRef&>(this->GetBaseRef()); }
	};
	/// Intermediate helper class for DataDescriptionObjectInterface.
	template <typename S> class COWFn : public ConstFn<S>
	{
	public:
		COWFn() = default;
		using PrivateBaseClass = ConstFn<S>;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateBaseClass::PrivateLookupFn;
		static COWFn PrivateLookupFn(DataDescriptionObjectInterface**);
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, DataDescriptionObjectRef, false>::type&() { return reinterpret_cast<const DataDescriptionObjectRef&>(this->GetBaseRef()); }
	};
	template <typename ST> struct FnHelper : public std::conditional<
	maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)),
	COWFn<typename ObjectInterface::Hxx1::template FnHelper<ST>::type>,
	typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstFn<typename ObjectInterface::Hxx1::template FnHelper<ST>::type>, Fn<typename ObjectInterface::Hxx1::template FnHelper<ST>::type>>::type
	> { };
};
class DataDescriptionObjectInterface::Hxx1::Reference :
#ifdef DOXYGEN
public FnDoxy<DataDescriptionObjectRef>
#else
public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<DataDescriptionObjectInterface, maxon::StrongRefHandler, DataDescriptionObjectRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<DataDescriptionObjectInterface, maxon::StrongRefHandler, DataDescriptionObjectRef>>>>);
	using NonConst = typename Super::ReferenceClass;
};

/// DataDescriptionObjectRef is the reference class of DataDescriptionObjectInterface.
///
/// Interface and base implementation to allow objects to access descriptions. The base implementation automatically loads resources from
/// the data description databases.
class DataDescriptionObjectRef : public DataDescriptionObjectInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(DataDescriptionObjectRef, typename DataDescriptionObjectInterface::Hxx1::Reference);
	using ConstPtr = typename DataDescriptionObjectInterface::ConstPtr;
};

#endif
