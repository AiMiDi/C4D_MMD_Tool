#if 1
namespace APPMESSAGE
{
#ifndef PRIVATE_MAXON_GUARD_maxon_APPMESSAGE
#define PRIVATE_MAXON_GUARD_maxon_APPMESSAGE
	class RESTRICT : public maxon::RESTRICT { }; template <typename T> RESTRICT TestRestriction(T y, maxon::OverloadRank1);
#endif
	namespace OPENFILES
	{
	#ifndef PRIVATE_MAXON_GUARD_maxon_APPMESSAGE_OPENFILES
	#define PRIVATE_MAXON_GUARD_maxon_APPMESSAGE_OPENFILES
		class RESTRICT : public APPMESSAGE::RESTRICT { }; template <typename T> RESTRICT TestRestriction(T y, maxon::OverloadRank1);
	#endif
	}
}
#ifdef MAXON_TARGET_WINDOWS
#endif
class Application::ObservableApplicationMessageDelegate : public maxon::Delegate<Result<Bool>(const Id&,const DataDictionary&)>
{
public:
	using Super = maxon::Delegate<Result<Bool>(const Id&,const DataDictionary&)>;
	MAXON_MEMBERFUNCTION_DETECTOR(HandleApplicationMessage);
	ObservableApplicationMessageDelegate() = default;
	template <typename FN> static maxon::ResultOk<Super> Create(FN&& src, typename std::enable_if<HasHandleApplicationMessage<typename maxon::Dereference<typename std::decay<FN>::type, false>::type>::value, void>::type* = nullptr) { return Super::CreateByReference(std::forward<FN>(src), &maxon::Dereference<typename std::decay<FN>::type, false>::type::HandleApplicationMessage); }
	template <typename FN> static maxon::Result<Super> Create(FN&& src, typename std::enable_if<!HasHandleApplicationMessage<typename maxon::Dereference<typename std::decay<FN>::type, false>::type>::value, void>::type* = nullptr){ return Super::Create(std::forward<FN>(src)); }
	using OBSERVABLECOMBINER = ObservableCombinerRunAllBoolUntilFalsePrivateHelper;
};

#endif
