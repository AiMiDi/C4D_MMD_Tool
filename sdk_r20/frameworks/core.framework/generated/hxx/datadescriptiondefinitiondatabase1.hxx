#if 1
class DataDescriptionDefinitionDatabaseInterface::ObservableSaveDatabaseDelegate : public maxon::Delegate<Result<void>(const Id&,const Url&,Bool)>
{
public:
	using Super = maxon::Delegate<Result<void>(const Id&,const Url&,Bool)>;
	MAXON_MEMBERFUNCTION_DETECTOR(HandleSaveDatabase);
	ObservableSaveDatabaseDelegate() = default;
	template <typename FN> static maxon::ResultOk<Super> Create(FN&& src, typename std::enable_if<HasHandleSaveDatabase<typename maxon::Dereference<typename std::decay<FN>::type, false>::type>::value, void>::type* = nullptr) { return Super::CreateByReference(std::forward<FN>(src), &maxon::Dereference<typename std::decay<FN>::type, false>::type::HandleSaveDatabase); }
	template <typename FN> static maxon::Result<Super> Create(FN&& src, typename std::enable_if<!HasHandleSaveDatabase<typename maxon::Dereference<typename std::decay<FN>::type, false>::type>::value, void>::type* = nullptr){ return Super::Create(std::forward<FN>(src)); }
	using OBSERVABLECOMBINER = ObservableCombinerRunAllComponentPrivateHelper;
};

class DataDescriptionDefinitionDatabaseInterface::ObservableDatabaseRegistrationChangeDelegate : public maxon::Delegate<Result<void>(const Id&,Bool)>
{
public:
	using Super = maxon::Delegate<Result<void>(const Id&,Bool)>;
	MAXON_MEMBERFUNCTION_DETECTOR(HandleDatabaseRegistrationChange);
	ObservableDatabaseRegistrationChangeDelegate() = default;
	template <typename FN> static maxon::ResultOk<Super> Create(FN&& src, typename std::enable_if<HasHandleDatabaseRegistrationChange<typename maxon::Dereference<typename std::decay<FN>::type, false>::type>::value, void>::type* = nullptr) { return Super::CreateByReference(std::forward<FN>(src), &maxon::Dereference<typename std::decay<FN>::type, false>::type::HandleDatabaseRegistrationChange); }
	template <typename FN> static maxon::Result<Super> Create(FN&& src, typename std::enable_if<!HasHandleDatabaseRegistrationChange<typename maxon::Dereference<typename std::decay<FN>::type, false>::type>::value, void>::type* = nullptr){ return Super::Create(std::forward<FN>(src)); }
	using OBSERVABLECOMBINER = ObservableCombinerRunAllComponentPrivateHelper;
};

#endif
