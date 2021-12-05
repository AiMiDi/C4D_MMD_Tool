#ifndef FACTORY_H__
#define FACTORY_H__

#include "maxon/object.h"
#include "maxon/datadictionaryobject.h"

namespace maxon
{

//----------------------------------------------------------------------------------------
/// Interface for factories. Factories create new objects based on parameters.
/// @see Factory
/// @MAXON_ANNOTATION{refprefix=Generic}
//----------------------------------------------------------------------------------------
class FactoryInterface : MAXON_INTERFACE_BASES(DataDictionaryObjectInterface)
{
	MAXON_INTERFACE(FactoryInterface, MAXON_REFERENCE_CONST, "net.maxon.interface.factory");
public:
	//----------------------------------------------------------------------------------------
	/// Returns the delegate which implements the factory function.
	/// @MAXON_ANNOTATION{refclass=false}
	//----------------------------------------------------------------------------------------
	MAXON_METHOD const DelegateBase* PrivateGetDelegate() const;

	/// Doc for attribute.
	MAXON_ATTRIBUTE_CLASS(DataDictionary, Parameters, "net.maxon.factoryparams");
};


#include "factory1.hxx"

class FactoryFactory;

//----------------------------------------------------------------------------------------
/// This class defines the Create function for Factory.
//----------------------------------------------------------------------------------------
template <typename T, typename... ARGS, typename SUPER> class FactoryFunctions<Factory<T(ARGS...)>, SUPER> : public MAXON_IF_SOURCEPROCESSOR(GenericFactory, SUPER::type)
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(FactoryFunctions, typename SUPER::type);
	using type = FactoryFunctions;
	using DelegateType = Delegate<Result<T>(FactoryInterface::ConstPtr, ARGS...)>;

	//----------------------------------------------------------------------------------------
	/// Creates a new object of type T given the arguments args.
	/// @param[in] args								Arguments for the creation of the new object.
	/// @return												Created object.
	//----------------------------------------------------------------------------------------
	Result<T> Create(ARGS... args) const
	{
		const FactoryInterface* f = this->GetPointer();
		if (!f || !f->PrivateGetDelegate())
			return NullptrError(MAXON_SOURCE_LOCATION, "Factory is nullptr."_s);
		return reinterpret_cast<const DelegateType&>(*f->PrivateGetDelegate())(f, std::forward<ARGS>(args)...);
	}
};

//----------------------------------------------------------------------------------------
/// Specialization for the case of a Factory with single DataDictionary argument.
/// It allows to call the Create function without any argument, then an empty DataDictionary is used.
//----------------------------------------------------------------------------------------
template <typename T, typename SUPER> class FactoryFunctions<Factory<T(const DataDictionary&)>, SUPER> : public MAXON_IF_SOURCEPROCESSOR(GenericFactory, SUPER::type)
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(FactoryFunctions, typename SUPER::type);
	using type = FactoryFunctions;
	using DelegateType = Delegate<Result<T>(FactoryInterface::ConstPtr, const DataDictionary&)>;

	//----------------------------------------------------------------------------------------
	/// Creates a new object of type T given the arguments args.
	/// @param[in] args								Arguments for the creation of the new object.
	/// @return												Created object.
	//----------------------------------------------------------------------------------------
	Result<T> Create(const DataDictionary& args = NullValue<const DataDictionary&>()) const
	{
		const FactoryInterface* f = this->GetPointer();
		if (!f || !f->PrivateGetDelegate())
			return NullptrError(MAXON_SOURCE_LOCATION, "Factory is nullptr."_s);
		return reinterpret_cast<const DelegateType&>(*f->PrivateGetDelegate())(f, args);
	}

	//----------------------------------------------------------------------------------------
	/// Creates a new object of type T given the arguments args.
	/// If args has an error, this is returned immediately.
	/// @param[in] args								Arguments for the creation of the new object.
	/// @return												Created object.
	//----------------------------------------------------------------------------------------
	Result<T> Create(Result<DataDictionary>&& args) const
	{
		iferr_scope;
		DataDictionary dict = args iferr_return;
		const FactoryInterface* f = this->GetPointer();
		if (!f || !f->PrivateGetDelegate())
			return NullptrError(MAXON_SOURCE_LOCATION, "Factory is nullptr."_s);
		return reinterpret_cast<const DelegateType&>(*f->PrivateGetDelegate())(f, dict);
	}
};

/// @private
template <typename FACTORY> using FactoryBase = ReferenceBase<FactoryFunctions<FACTORY, FactoryInterface::ReferenceFunctions<RefBaseFunctions<DirectRef<const FactoryInterface, StrongRefHandler, FACTORY>>>>>;


//----------------------------------------------------------------------------------------
/// Reference class for factories which return an object of type T based on the arguments ARGS.
/// Typically you declare a factory in a header file as in
/// @code
/// namespace DataFormatBaseReader
/// {
///   MAXON_DECLARATION(Factory<DataFormatBaseReaderRef(const Url&)>, FromUrl, "net.maxon.dataformatbasereader.fromurl");
/// }
/// @endcode
/// The factory can then be used to create new DataFormatBaseReaderRef objects given an Url:
/// @code
///	DataFormatBaseReaderRef stream = DataFormatBaseReader::FromUrl().Create(url) iferr_return;
/// @endcode
/// The definition of a factory can be done with the help of one of the static `Create*Factory` functions of Factory.
///
/// @tparam T											The type of objects created by the factory.
/// @tparam ARGS									The arguments which the factory expects for object creation.
//----------------------------------------------------------------------------------------
template <typename T, typename... ARGS> class Factory<T(ARGS...)> : public MAXON_IF_SOURCEPROCESSOR(FactoryFunctions, FactoryBase)<Factory<T(ARGS...)>>
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Factory, FactoryBase<Factory<T(ARGS...)>>);

	/// @private
	class NonConst : public ReferenceBase<FactoryInterface::ReferenceFunctions<RefBaseFunctions<DirectRef<FactoryInterface, StrongRefHandler, NonConst>>>>
	{
	public:
		// An Intel compiler bug prohibits the use of MAXON_DEFAULT_REFERENCE_CONSTRUCTORS here.
		using Super = ReferenceBase<FactoryInterface::ReferenceFunctions<RefBaseFunctions<DirectRef<FactoryInterface, StrongRefHandler, NonConst>>>>;

		NonConst() = default;
		NonConst(const NonConst&) = default;
		NonConst& operator =(const NonConst&) = default;
		NonConst(NonConst&&) = default;
		NonConst& operator =(NonConst&&) = default;

		template <typename ARG> explicit NonConst(ARG&& arg) : Super(std::forward<ARG>(arg))
		{
		}

		using ReferenceClass = NonConst;

		static const NonConst& NullValue()
		{
			return *reinterpret_cast<const NonConst*>(&GenericFactory::NullValue());
		}
	};

	/// @private
	static const Factory& NullValue()
	{
		return GetPtrSizedZeroRef<Factory>();
	}

	/// @private
	using ReferenceClass = Factory;

	/// @private
	using NewInstanceType = T;

	/// @private
	using DelegateType = typename Super::DelegateType;

	//----------------------------------------------------------------------------------------
	/// Creates a factory which creates objects through a Delegate<Result<T>(FactoryInterface::ConstPtr, ARGS...)>.
	/// Note the first extra parameter for the delegate, it receives a pointer to the called factory.
	///
	/// The returned factory doesn't use caching, so each call will return a new object.
	/// If you want to cache created objects, use CreateCachedObjectFactory.
	///
	/// @param[in] delegate						Delegate to which the created factory delegates the object creation.
	/// @param[in] params							Parameters to store at the created factory itself. They can be accessed through the base interface DataDictionaryObject of the factory.
	/// @return												Factory which uses #delegate when called.
	//----------------------------------------------------------------------------------------
	static Result<NonConst> CreateFactory(DelegateType&& delegate, const DataDictionary& params = maxon::NullValue<const DataDictionary&>())
	{
		return SFINAEHelper<FactoryFactory, T>::type::template Create<Factory>(std::move(delegate), params);
	}

	//----------------------------------------------------------------------------------------
	/// Creates a factory which creates cached objects through a Delegate<Result<T>(FactoryInterface::ConstPtr, ARGS...)>.
	/// This function is used in the same way as CreateFactory, but the returned factory caches the created objects based on the arguments.
	/// So whenever the factory is called multiple times with equal arguments, it will return the same object.
	///
	/// @param[in] delegate						Delegate to which the created factory delegates the object creation.
	/// @param[in] cacheSize					The cache size of the factory. This should be large enough because the performance of the cache degrades when there are more than cacheSize entries.
	/// @param[in] params							Parameters to store at the created factory itself. They can be accessed through the base interface DataDictionaryObject of the factory.
	/// @return												Factory which uses #initFunc when called.
	//----------------------------------------------------------------------------------------
	static Result<NonConst> CreateCachedFactory(DelegateType&& delegate, Int cacheSize, const DataDictionary& params = maxon::NullValue<const DataDictionary&>())
	{
		return SFINAEHelper<FactoryFactory, T>::type::template CreateCached<T>(std::move(delegate), cacheSize, params);
	}

	//----------------------------------------------------------------------------------------
	/// Creates a factory which creates virtual objects from a component implementation COMP.
	/// If the factory's return type T is an interface reference class as in
	/// @code
	/// MAXON_DECLARATION(Factory<DataFormatBaseReaderRef(const Url&)>, FromUrl, "net.maxon.dataformatbasereader.fromurl");
	/// @endcode
	/// you can implement such a factory by a component which implements the interface and has an additional
	/// member function #initFunc which expects the factory as first parameter and then ARGS:
	/// @code
	/// class DataFormatReaderUniCharImpl : public Component<DataFormatReaderUniCharImpl, DataFormatBaseReaderInterface>
	/// {
	/// 	MAXON_COMPONENT(NORMAL, DataDictionaryObjectClass);
	///
	/// public:
	/// 	Result<void> InitFromUrl(FactoryInterface::ConstPtr factory, const Url& url);
	///   ...
	/// };
	/// @endcode
	/// Then CreateObjectFactory takes #initFunc and creates a corresponding factory:
	/// @code
	/// MAXON_DECLARATION_REGISTER(DataFormatBaseReader::FromUrl)
	/// {
	/// 	return decltype(DataFormatBaseReader::FromUrl)::Type::CreateObjectFactory(&DataFormatReaderUniCharImpl::InitFromUrl);
	/// }
	/// @endcode
	/// The returned factory doesn't use caching, so each call will return a new object.
	/// If you want to cache created objects, use CreateCachedObjectFactory.
	///
	/// @tparam COMP									Component class.
	/// @param[in] initFunc						Member function of COMP which initializes the object with the arguments given to the factory.
	/// @param[in] params							Parameters to store at the created factory itself. They can be accessed through the base interface DataDictionaryObject of the factory.
	/// @return												Factory which uses #initFunc when called.
	//----------------------------------------------------------------------------------------
	template <typename COMP, typename = typename COMP::_Wrapper> static Result<NonConst> CreateObjectFactory(Result<void>(COMP::* initFunc)(FactoryInterface::ConstPtr, ARGS...), const DataDictionary& params = maxon::NullValue<const DataDictionary&>())
	{
		return SFINAEHelper<FactoryFactory, T>::type::template Create<Factory>([initFunc](FactoryInterface::ConstPtr factory, ARGS... args) -> Result<T>
		{
			iferr_scope;
			auto res = COMP::GetClass().Create() iferr_return;
			(COMP::Get(res)->*initFunc)(factory, std::forward<ARGS>(args)...) iferr_return;
			static_assert(maxon::HasBase<typename COMP::Interface, typename T::ReferencedType>::value, "Component doesn't implement interface of factory result.");
			return std::move(reinterpret_cast<T&>(res));
		}, params);
	}

	//----------------------------------------------------------------------------------------
	/// Creates a factory which creates cached virtual objects from a component implementation COMP.
	/// This function is used in the same way as CreateObjectFactory, but the returned factory caches the created objects based on the arguments.
	/// So whenever the factory is called multiple times with equal arguments, it will return the same object.
	///
	/// @tparam COMP									Component class.
	/// @param[in] initFunc						Member function of COMP which initializes the object with the arguments given to the factory.
	/// @param[in] cacheSize					The cache size of the factory. This should be large enough because the performance of the cache degrades when there are more than cacheSize entries.
	/// @param[in] params							Parameters to store at the created factory itself. They can be accessed through the base interface DataDictionaryObject of the factory.
	/// @return												Factory which uses #initFunc when called.
	//----------------------------------------------------------------------------------------
	template <typename COMP, typename = typename COMP::_Wrapper> static Result<NonConst> CreateCachedObjectFactory(Result<void> (COMP::* initFunc)(FactoryInterface::ConstPtr, ARGS...), Int cacheSize, const DataDictionary& params = maxon::NullValue<const DataDictionary&>())
	{
		return SFINAEHelper<FactoryFactory, T>::type::template CreateCached<T>([initFunc] (FactoryInterface::ConstPtr factory, ARGS... args) -> Result<T>
		{
			iferr_scope;
			auto res = COMP::GetClass().Create() iferr_return;
			(COMP::Get(res)->*initFunc)(factory, std::forward<ARGS>(args)...) iferr_return;
			static_assert(maxon::HasBase<typename COMP::Interface, typename T::ReferencedType>::value, "Component doesn't implement interface of factory result.");
			return std::move(reinterpret_cast<T&>(res));
		}, cacheSize, params);
	}
};


//----------------------------------------------------------------------------------------
/// Helper interface for the `Create*Factory` functions of Factory.
/// @private
//----------------------------------------------------------------------------------------
class FactoryFactory
{
	MAXON_INTERFACE_NONVIRTUAL(FactoryFactory, MAXON_REFERENCE_NONE, "net.maxon.interface.factoryfactory");
public:
	template <typename FACTORY> static Result<typename FACTORY::NonConst> Create(typename FACTORY::DelegateType&& delegate, const DataDictionary& params = DataDictionary())
	{
		Result<GenericFactory::NonConst> res = PrivateCreate(std::move(delegate), params);
		return std::move(reinterpret_cast<Result<typename FACTORY::NonConst>&>(res));
	}

	template <typename T> static Result<typename Factory<T(const DataDictionary&)>::NonConst> CreateCached(typename Factory<T(const DataDictionary&)>::DelegateType&& delegate, Int size, const DataDictionary& params = DataDictionary())
	{
		Result<GenericFactory::NonConst> res = PrivateCreateCached(typename Factory<T(const DataDictionary&)>::DelegateType(&CreateCachedImpl<T>), std::move(delegate), size, params);
		return std::move(reinterpret_cast<Result<typename Factory<T(const DataDictionary&)>::NonConst>&>(res));
	}

	using DataCreator = Result<Data>(const FactoryInterface*, const DataDictionary&, const DelegateBase&);

private:
	static MAXON_METHOD Result<GenericFactory::NonConst> PrivateCreate(DelegateBase&& func, const DataDictionary& params);

	static MAXON_METHOD Result<GenericFactory::NonConst> PrivateCreateCached(DelegateBase&& func, DelegateBase&& creator, Int size, const DataDictionary& params);

	static MAXON_METHOD Result<const Data&> CreateDataCached(const FactoryInterface* factory, const DataDictionary& params, DataCreator* dc);

	template <typename T> static Result<Data> CreateData(const FactoryInterface* factory, const DataDictionary& params, const DelegateBase& creator)
	{
		Result<T> res = static_cast<const typename Factory<T(const DataDictionary&)>::DelegateType&>(creator)(factory, params);
		if (res == FAILED)
			return res.GetErrorStorage();
		return Data(std::move(res.GetValue()));
	}

	template <typename T> static Result<T> CreateCachedImpl(FactoryInterface::ConstPtr factory, const DataDictionary& params)
	{
		Result<const Data&> res = CreateDataCached(factory, params, &CreateData<T>);
		if (res == FAILED)
			return res.GetErrorStorage();
		return res.GetValue().Get<T>();
	}
};

#include "factory2.hxx"

} // namespace maxon

#endif // FACTORY_H__

