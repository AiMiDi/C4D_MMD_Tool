#ifndef CONDITIONVARIABLE_DEP_H__
#define CONDITIONVARIABLE_DEP_H__

#include "maxon/apibase.h"
#include "maxon/conditionvariable.h"


namespace maxon
{

//----------------------------------------------------------------------------------------
/// This class represents a dependency on a condition variable with unique ownership semantics.
//----------------------------------------------------------------------------------------
class ConditionVariableDependency
{
public:
	//----------------------------------------------------------------------------------------
	/// Default constructor.
	/// Creates an 'null dependency' that is not associated with any condition variable.
	//----------------------------------------------------------------------------------------
	ConditionVariableDependency() = default;

	//----------------------------------------------------------------------------------------
	/// Deleted copy constructor.
	//----------------------------------------------------------------------------------------
	ConditionVariableDependency(const ConditionVariableDependency&) = delete;

	//----------------------------------------------------------------------------------------
	/// Deleted copy assignment.
	//----------------------------------------------------------------------------------------
	void operator =(const ConditionVariableDependency&) = delete;

	//----------------------------------------------------------------------------------------
	/// Move constructor.
	/// Transfers ownership of dependency @c src to the created instance.
	/// Afterwards, src represents a 'null dependency' that is no longer associated with a condition variable.
	//----------------------------------------------------------------------------------------
	ConditionVariableDependency(ConditionVariableDependency&& src) = default;

	//----------------------------------------------------------------------------------------
	/// Move assignment.
	/// Transfers ownership of the depending condition variable to this instance.
	/// Transfers ownership of dependency @c src to this instance.
	/// If this instance already holds a dependency, it is released by calling Set() on it.
	/// Afterwards, src no longer holds a dependency.
	//----------------------------------------------------------------------------------------
	ConditionVariableDependency& operator =(ConditionVariableDependency&& src)
	{
		if (_cond)
			_cond.Set();

		_cond = std::move(src._cond);
		return *this;
	}

	//----------------------------------------------------------------------------------------
	/// Constructs a new dependency of the given condition variable.
	//----------------------------------------------------------------------------------------
	explicit ConditionVariableDependency(ConditionVariableRef& cond) : _cond(cond)
	{
		_cond.AddDependency();
	}

	//----------------------------------------------------------------------------------------
	/// Assigns this instance as a dependency of the given condition variable.
	/// If this instance already holds a dependency, it is released before that.
	//----------------------------------------------------------------------------------------
	ConditionVariableDependency& operator =(ConditionVariableRef& newCond)
	{
		newCond.AddDependency();
		_cond.Set();
		_cond = newCond;
		return *this;
	}

	//----------------------------------------------------------------------------------------
	/// Releases this dependency.
	//----------------------------------------------------------------------------------------
	~ConditionVariableDependency()
	{
		if (_cond)
			_cond.Set();
	}

	//----------------------------------------------------------------------------------------
	/// Releases this dependency.
	/// Afterwards, the instance represents a 'null dependency' that is no longer associated
	/// with a condition variable.
	//----------------------------------------------------------------------------------------
	void Reset()
	{
		if (_cond)
		{
			_cond.Set();
			_cond = nullptr;
		}
	}

private:
	ConditionVariableRef	_cond;
};

} // namespace maxon

#endif // CONDITIONVARIABLE_DEP_H__
