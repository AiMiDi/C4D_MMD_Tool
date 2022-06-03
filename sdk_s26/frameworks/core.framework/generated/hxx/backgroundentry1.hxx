#if 1
class BackgroundEntryRef;

struct BackgroundEntryInterface::HasBaseDetector { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, BackgroundEntryInterface>::value || ObjectInterface::HasBaseDetector::template Check<I>::value; static I* Cast(BackgroundEntryInterface* ptr) { return reinterpret_cast<I*>(ptr); } }; };
struct BackgroundEntryInterface::Hxx1
{
	class Reference;
	using ReferenceClass = BackgroundEntryRef;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<ObjectInterface>;
	/// Intermediate helper class for BackgroundEntryInterface.
	template <typename S> class ConstFn DOXYGEN_SWITCH_REVERSED(, : public S)
	{
	public:
		ConstFn() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateBaseClass::PrivateLookupFn;
		static ConstFn PrivateLookupFn(BackgroundEntryInterface**);
		using STATE = BackgroundEntryInterface::STATE;
/// GetName returns the name of the entry.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type GetName() const;
/// GetStartTime returns the time when the entry has been created (so it is the start time).
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<UniversalDateTime>, UniversalDateTime>::type GetStartTime() const;
/// GetDuration returns the duration of the entry.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<TimeValue>, TimeValue>::type GetDuration() const;
/// GetStates iterates over all state entries and calls the value receiver for each.
/// @param[in] state							ValueReceiver which is called for every entry in the list. Return false to stop the iteration immediately.
/// @return                       The return value of the ValueReceiver. True if all values were iterated and the callback did not stop the iteration.
		inline Result<Bool> GetStates(const ValueReceiver<STATE, const String&>& state) const;
/// GetStateCount description.
/// @return                       OK on success.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type GetStateCount() const;
	};
	/// Intermediate helper class for BackgroundEntryInterface.
	template <typename S> class Fn : public ConstFn<S>
	{
	public:
		Fn() = default;
		using PrivateBaseClass = ConstFn<S>;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateBaseClass::PrivateLookupFn;
		static Fn PrivateLookupFn(BackgroundEntryInterface**);
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, BackgroundEntryRef, true>::type&() const { return reinterpret_cast<const BackgroundEntryRef&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, BackgroundEntryRef, false>::type&() { return reinterpret_cast<const BackgroundEntryRef&>(this->GetBaseRef()); }
/// GetState returns the overall state of the entry. The highest level (e.g. error) defines the state.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<STATE>, STATE>::type GetState() const;
/// AddState adds a new state message to the entry.
/// @param[in] state							see STATE.
/// @param[in] message						Text of the message.
/// @return                       OK on success.
		inline Result<void> AddState(STATE state, const String& message) const;
	};
	/// Intermediate helper class for BackgroundEntryInterface.
	template <typename S> class COWFn : public ConstFn<S>
	{
	public:
		COWFn() = default;
		using PrivateBaseClass = ConstFn<S>;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateBaseClass::PrivateLookupFn;
		static COWFn PrivateLookupFn(BackgroundEntryInterface**);
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, BackgroundEntryRef, false>::type&() { return reinterpret_cast<const BackgroundEntryRef&>(this->GetBaseRef()); }
/// GetState returns the overall state of the entry. The highest level (e.g. error) defines the state.
		inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), STATE, maxon::Result<STATE>>::type GetState();
/// AddState adds a new state message to the entry.
/// @param[in] state							see STATE.
/// @param[in] message						Text of the message.
/// @return                       OK on success.
		inline Result<void> AddState(STATE state, const String& message);
	};
	template <typename ST> struct FnHelper : public std::conditional<
	maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)),
	COWFn<typename ObjectInterface::Hxx1::template FnHelper<ST>::type>,
	typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstFn<typename ObjectInterface::Hxx1::template FnHelper<ST>::type>, Fn<typename ObjectInterface::Hxx1::template FnHelper<ST>::type>>::type
	> { };
};
class BackgroundEntryInterface::Hxx1::Reference :
#ifdef DOXYGEN
public FnDoxy<BackgroundEntryRef>
#else
public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<BackgroundEntryInterface, maxon::StrongRefHandler, BackgroundEntryRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<BackgroundEntryInterface, maxon::StrongRefHandler, BackgroundEntryRef>>>>);
	using NonConst = typename Super::ReferenceClass;
};

/// BackgroundEntryRef is the reference class of BackgroundEntryInterface.
///
/// BackgroundEntryInterface provides informations about a background entry. It's the base class for BackgroundProgressInterface.
class BackgroundEntryRef : public BackgroundEntryInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(BackgroundEntryRef, typename BackgroundEntryInterface::Hxx1::Reference);
	using ConstPtr = typename BackgroundEntryInterface::ConstPtr;
};

class BackgroundProgressRef;

struct BackgroundProgressInterface::HasBaseDetector { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, BackgroundProgressInterface>::value || ProgressInterface::HasBaseDetector::template Check<I>::value || BackgroundEntryInterface::HasBaseDetector::template Check<I>::value; static I* Cast(BackgroundProgressInterface* ptr) { return reinterpret_cast<I*>(ptr); } }; };
struct BackgroundProgressInterface::Hxx1
{
	class Reference;
	using ReferenceClass = BackgroundProgressRef;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<ProgressInterface, BackgroundEntryInterface>;
	/// Intermediate helper class for BackgroundProgressInterface.
	template <typename S> class ConstFn DOXYGEN_SWITCH_REVERSED(, : public S)
	{
	public:
		ConstFn() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateBaseClass::PrivateLookupFn;
		static ConstFn PrivateLookupFn(BackgroundProgressInterface**);
		using STATECHANGE = BackgroundProgressInterface::STATECHANGE;
/// GetMaster returns the master instance of this implementation. this instance is used to visualize entries in the task manager.
		static inline BackgroundProgressRef GetMaster();
/// GetActiveEntries calls the ValueReceiver for each active entry.
/// @param[in] entry							Delegate which is called for every entry in the list.
/// @return                       Result of the delegate.
		inline Result<Bool> GetActiveEntries(const ValueReceiver<const BackgroundProgressRef&>& entry) const;
/// GetActiveCount returns the number of active elements.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type GetActiveCount() const;
/// GetHistoryEntries calls the ValueReceiver for each history entry.
/// @param[in] entry							Delegate which is called for every entry in the list.
/// @return                       OK on success.
		inline Result<Bool> GetHistoryEntries(const ValueReceiver<const BackgroundEntryRef&>& entry) const;
/// GetHistoryCount returns the number of history entries.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type GetHistoryCount() const;
/// ObservableStateChanged observable is called if the object adds or removes entries.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<maxon::ObservableRef<ObservableStateChangedDelegate>>, maxon::ObservableRef<ObservableStateChangedDelegate>>::type ObservableStateChanged() const;
/// ObservableTotalProgressNotification observable is called if the overall progress of one of the elements changed.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<maxon::ObservableRef<ObservableTotalProgressNotificationDelegate>>, maxon::ObservableRef<ObservableTotalProgressNotificationDelegate>>::type ObservableTotalProgressNotification() const;
	};
	/// Intermediate helper class for BackgroundProgressInterface.
	template <typename S> class Fn : public ConstFn<S>
	{
	public:
		Fn() = default;
		using PrivateBaseClass = ConstFn<S>;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateBaseClass::PrivateLookupFn;
		static Fn PrivateLookupFn(BackgroundProgressInterface**);
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, BackgroundProgressRef, true>::type&() const { return reinterpret_cast<const BackgroundProgressRef&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, BackgroundProgressRef, false>::type&() { return reinterpret_cast<const BackgroundProgressRef&>(this->GetBaseRef()); }
/// AddActiveEntry adds a new active entry to the list. The object is stored only as WeakRef. So you take the ownership.
/// Important: The last reference to the object will remove the object from the active list.
/// @param[in] title							Text with the human readable name of the action.
/// @param[in] sendToHistory			True if the entry should be moved to the history list after it's done.
/// @return                       New BackgroundProgressRef entry on success.
		inline Result<BackgroundProgressRef> AddActiveEntry(const String& title, Bool sendToHistory = true) const;
/// RemoveActiveEntry removes the entry from the active list and moves it to the history.
/// You can use this before the the last reference dies.
/// @param[in] entry							Entry to remove from the active list.
/// @return                       OK on success.
		inline Result<void> RemoveActiveEntry(const BackgroundProgressRef& entry) const;
/// RemoveHistoryEntry removes the given entry from the history
/// @param[in] entry							Entry to remove.
/// @return                       OK on success.
		inline Result<void> RemoveHistoryEntry(const BackgroundEntryRef& entry) const;
/// ClearHistory removes all history entries.
/// @return                       OK on success.
		inline Result<void> ClearHistory() const;
	};
	/// Intermediate helper class for BackgroundProgressInterface.
	template <typename S> class COWFn : public ConstFn<S>
	{
	public:
		COWFn() = default;
		using PrivateBaseClass = ConstFn<S>;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateBaseClass::PrivateLookupFn;
		static COWFn PrivateLookupFn(BackgroundProgressInterface**);
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, BackgroundProgressRef, false>::type&() { return reinterpret_cast<const BackgroundProgressRef&>(this->GetBaseRef()); }
/// AddActiveEntry adds a new active entry to the list. The object is stored only as WeakRef. So you take the ownership.
/// Important: The last reference to the object will remove the object from the active list.
/// @param[in] title							Text with the human readable name of the action.
/// @param[in] sendToHistory			True if the entry should be moved to the history list after it's done.
/// @return                       New BackgroundProgressRef entry on success.
		inline Result<BackgroundProgressRef> AddActiveEntry(const String& title, Bool sendToHistory = true);
/// RemoveActiveEntry removes the entry from the active list and moves it to the history.
/// You can use this before the the last reference dies.
/// @param[in] entry							Entry to remove from the active list.
/// @return                       OK on success.
		inline Result<void> RemoveActiveEntry(const BackgroundProgressRef& entry);
/// RemoveHistoryEntry removes the given entry from the history
/// @param[in] entry							Entry to remove.
/// @return                       OK on success.
		inline Result<void> RemoveHistoryEntry(const BackgroundEntryRef& entry);
/// ClearHistory removes all history entries.
/// @return                       OK on success.
		inline Result<void> ClearHistory();
	};
	template <typename ST> struct FnHelper : public std::conditional<
	maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)),
	COWFn<typename BackgroundEntryInterface::Hxx1::template FnHelper<typename ProgressInterface::Hxx1::template FnHelper<ST>>::type>,
	typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstFn<typename BackgroundEntryInterface::Hxx1::template FnHelper<typename ProgressInterface::Hxx1::template FnHelper<ST>>::type>, Fn<typename BackgroundEntryInterface::Hxx1::template FnHelper<typename ProgressInterface::Hxx1::template FnHelper<ST>>::type>>::type
	> { };
};
class BackgroundProgressInterface::Hxx1::Reference :
#ifdef DOXYGEN
public FnDoxy<BackgroundProgressRef>
#else
public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<BackgroundProgressInterface, maxon::StrongRefHandler, BackgroundProgressRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<BackgroundProgressInterface, maxon::StrongRefHandler, BackgroundProgressRef>>>>);
	using NonConst = typename Super::ReferenceClass;
};

/// BackgroundProgressRef is the reference class of BackgroundProgressInterface.
///
/// Interface to announce background entries with progress management.
class BackgroundProgressRef : public BackgroundProgressInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(BackgroundProgressRef, typename BackgroundProgressInterface::Hxx1::Reference);
	using ConstPtr = typename BackgroundProgressInterface::ConstPtr;
};

class BackgroundProgressInterface::ObservableStateChangedDelegate : public maxon::Delegate<void(STATECHANGE,const BackgroundEntryRef&)>
{
public:
	using Super = maxon::Delegate<void(STATECHANGE,const BackgroundEntryRef&)>;
	MAXON_MEMBERFUNCTION_DETECTOR(HandleStateChanged);
	ObservableStateChangedDelegate() = default;
	template <typename FN> static maxon::ResultOk<Super> Create(FN&& src, typename std::enable_if<HasHandleStateChanged<typename maxon::Dereference<typename std::decay<FN>::type, false>::type>::value, void>::type* = nullptr) { return Super::CreateByReference(std::forward<FN>(src), &maxon::Dereference<typename std::decay<FN>::type, false>::type::HandleStateChanged); }
	template <typename FN> static maxon::Result<Super> Create(FN&& src, typename std::enable_if<!HasHandleStateChanged<typename maxon::Dereference<typename std::decay<FN>::type, false>::type>::value, void>::type* = nullptr){ return Super::Create(std::forward<FN>(src)); }
	using OBSERVABLECOMBINER = ObservableCombinerRunAllComponentPrivateHelper;
};

class BackgroundProgressInterface::ObservableTotalProgressNotificationDelegate : public maxon::Delegate<void(const BackgroundProgressRef&,Float)>
{
public:
	using Super = maxon::Delegate<void(const BackgroundProgressRef&,Float)>;
	MAXON_MEMBERFUNCTION_DETECTOR(HandleTotalProgressNotification);
	ObservableTotalProgressNotificationDelegate() = default;
	template <typename FN> static maxon::ResultOk<Super> Create(FN&& src, typename std::enable_if<HasHandleTotalProgressNotification<typename maxon::Dereference<typename std::decay<FN>::type, false>::type>::value, void>::type* = nullptr) { return Super::CreateByReference(std::forward<FN>(src), &maxon::Dereference<typename std::decay<FN>::type, false>::type::HandleTotalProgressNotification); }
	template <typename FN> static maxon::Result<Super> Create(FN&& src, typename std::enable_if<!HasHandleTotalProgressNotification<typename maxon::Dereference<typename std::decay<FN>::type, false>::type>::value, void>::type* = nullptr){ return Super::Create(std::forward<FN>(src)); }
	using OBSERVABLECOMBINER = ObservableCombinerRunAllComponentPrivateHelper;
};

constexpr inline const maxon::Char* DT_BackgroundEntryTuple_CppName() { return "maxon::BackgroundEntryTuple"; }
namespace URLFLAGS
{
#ifndef PRIVATE_MAXON_GUARD_maxon_URLFLAGS
#define PRIVATE_MAXON_GUARD_maxon_URLFLAGS
	class RESTRICT : public maxon::RESTRICT { }; template <typename T> RESTRICT TestRestriction(T y, maxon::OverloadRank1);
#endif
}
#endif
