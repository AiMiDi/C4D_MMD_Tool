#if 1
class RunLoop::ObservableExitLoopDelegate : public maxon::Delegate<Result<void>()>
{
public:
	using Super = maxon::Delegate<Result<void>()>;
	MAXON_MEMBERFUNCTION_DETECTOR(HandleExitLoop);
	ObservableExitLoopDelegate() = default;
	template <typename FN> static maxon::ResultOk<Super> Create(FN&& src, typename std::enable_if<HasHandleExitLoop<typename maxon::Dereference<typename std::decay<FN>::type, false>::type>::value, void>::type* = nullptr) { return Super::CreateByReference(std::forward<FN>(src), &maxon::Dereference<typename std::decay<FN>::type, false>::type::HandleExitLoop); }
	template <typename FN> static maxon::Result<Super> Create(FN&& src, typename std::enable_if<!HasHandleExitLoop<typename maxon::Dereference<typename std::decay<FN>::type, false>::type>::value, void>::type* = nullptr){ return Super::Create(std::forward<FN>(src)); }
	using OBSERVABLECOMBINER = ObservableCombinerRunAllAggregateErrorsComponentPrivateHelper;
};

class RunLoop::ObservableActivationChangeDelegate : public maxon::Delegate<Result<void>(Bool)>
{
public:
	using Super = maxon::Delegate<Result<void>(Bool)>;
	MAXON_MEMBERFUNCTION_DETECTOR(HandleActivationChange);
	ObservableActivationChangeDelegate() = default;
	template <typename FN> static maxon::ResultOk<Super> Create(FN&& src, typename std::enable_if<HasHandleActivationChange<typename maxon::Dereference<typename std::decay<FN>::type, false>::type>::value, void>::type* = nullptr) { return Super::CreateByReference(std::forward<FN>(src), &maxon::Dereference<typename std::decay<FN>::type, false>::type::HandleActivationChange); }
	template <typename FN> static maxon::Result<Super> Create(FN&& src, typename std::enable_if<!HasHandleActivationChange<typename maxon::Dereference<typename std::decay<FN>::type, false>::type>::value, void>::type* = nullptr){ return Super::Create(std::forward<FN>(src)); }
	using OBSERVABLECOMBINER = ObservableCombinerRunAllAggregateErrorsComponentPrivateHelper;
};

class RunLoop::ObservableRunLoopMessageDelegate : public maxon::Delegate<Bool(const void*)>
{
public:
	using Super = maxon::Delegate<Bool(const void*)>;
	MAXON_MEMBERFUNCTION_DETECTOR(HandleRunLoopMessage);
	ObservableRunLoopMessageDelegate() = default;
	template <typename FN> static maxon::ResultOk<Super> Create(FN&& src, typename std::enable_if<HasHandleRunLoopMessage<typename maxon::Dereference<typename std::decay<FN>::type, false>::type>::value, void>::type* = nullptr) { return Super::CreateByReference(std::forward<FN>(src), &maxon::Dereference<typename std::decay<FN>::type, false>::type::HandleRunLoopMessage); }
	template <typename FN> static maxon::Result<Super> Create(FN&& src, typename std::enable_if<!HasHandleRunLoopMessage<typename maxon::Dereference<typename std::decay<FN>::type, false>::type>::value, void>::type* = nullptr){ return Super::Create(std::forward<FN>(src)); }
	using OBSERVABLECOMBINER = ObservableCombinerRunAllBoolUntilTruePrivateHelper;
};

#endif
