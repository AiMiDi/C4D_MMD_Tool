#ifndef OBSERVERSCOPEGUARD_H__
#define OBSERVERSCOPEGUARD_H__

namespace maxon
{

//----------------------------------------------------------------------------------------
// ObserverScopeGuard is a RAII object, that hold the responsibility of deregistering an observer from an observable.
//----------------------------------------------------------------------------------------
class ObserverScopeGuard
{
	MAXON_DISALLOW_COPY_AND_ASSIGN(ObserverScopeGuard);

public:
	ObserverScopeGuard() : _deregisterCallable(), _isEnabled(false) {}


	MAXON_IMPLICIT ObserverScopeGuard(ObserverScopeGuard&& src) : _deregisterCallable(std::move(src._deregisterCallable)), _isEnabled(src._isEnabled)
	{
		src._isEnabled = false;
	}


	template <typename LAMBDA, typename OBSERVABLE>
	MAXON_IMPLICIT ObserverScopeGuard(LAMBDA&& lambda, OBSERVABLE& observable)
	{
		Init(lambda, observable) iferr_ignore("Cannot throw in constructor");
	}


	~ObserverScopeGuard()
	{
		if (_isEnabled && _deregisterCallable.IsPopulated())
		{
			_deregisterCallable() iferr_ignore("Cannot throw in destructors.");
		}
	}


	template <typename LAMBDA, typename OBSERVABLE>
	Result<void> Init(LAMBDA&& lambda, OBSERVABLE&& observable)
	{
		iferr_scope;

		if (_isEnabled && _deregisterCallable.IsPopulated())
		{
			_deregisterCallable() iferr_ignore("We are not interested if deregistering fails, we are just doing this for safety reasons.");
		}

		WeakRef<OBSERVABLE> observableWeakRef = observable;

		FunctionBaseRef observerHandle = observable.AddObserver(std::forward<LAMBDA>(lambda)) iferr_return;
		_deregisterCallable = [observableWeakRef, observerHandle]() -> Result<void>
		{
			OBSERVABLE observableRef = observableWeakRef.GetReference();
			if (observableRef)
			{
				observableRef.RemoveObserver(observerHandle);
			}

			return OK;
		};

		_isEnabled = true;

		return OK;
	}


	void operator=(ObserverScopeGuard&& other)
	{
		iferr_scope_handler
		{
			return;
		};

		if (&other == this)
		{
			return;
		}

		if (_deregisterCallable.IsPopulated())
		{
			_deregisterCallable() iferr_return;
		}

		_deregisterCallable = std::move(other._deregisterCallable);
		_isEnabled = other._isEnabled;
		other._isEnabled = false;
	}


	void Disable()
	{
		_isEnabled = false;
	}


	void Enable()
	{
		_isEnabled = true;
	}


	Result<void> operator ()()
	{
		return RemoveObserver();
	}


	void Reset()
	{
		_isEnabled = false;
		_deregisterCallable.Reset();
	}


	Result<void> RemoveObserver()
	{
		iferr_scope;

		if (_isEnabled)
		{
			_isEnabled = false;

			if (_deregisterCallable.IsPopulated())
			{
				_deregisterCallable() iferr_return;
			}

			Reset();
		}

		return OK;
	}

private:

	Delegate<Result<void>()> _deregisterCallable;
	Bool _isEnabled;
};

} // namespace maxon

#endif // OBSERVERSCOPEGUARD_H__
