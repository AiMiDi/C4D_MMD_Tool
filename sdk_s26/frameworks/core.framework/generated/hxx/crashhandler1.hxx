#if 1
class CrashHandler::ObservableCrashDataDirectoryDelegate : public maxon::Delegate<void(const Url&)>
{
public:
	using Super = maxon::Delegate<void(const Url&)>;
	MAXON_MEMBERFUNCTION_DETECTOR(HandleCrashDataDirectory);
	ObservableCrashDataDirectoryDelegate() = default;
	template <typename FN> static maxon::ResultOk<Super> Create(FN&& src, typename std::enable_if<HasHandleCrashDataDirectory<typename maxon::Dereference<typename std::decay<FN>::type, false>::type>::value, void>::type* = nullptr) { return Super::CreateByReference(std::forward<FN>(src), &maxon::Dereference<typename std::decay<FN>::type, false>::type::HandleCrashDataDirectory); }
	template <typename FN> static maxon::Result<Super> Create(FN&& src, typename std::enable_if<!HasHandleCrashDataDirectory<typename maxon::Dereference<typename std::decay<FN>::type, false>::type>::value, void>::type* = nullptr){ return Super::Create(std::forward<FN>(src)); }
	using OBSERVABLECOMBINER = ObservableCombinerRunAllComponentPrivateHelper;
};

#endif
