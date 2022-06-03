#ifndef CHANGELIST_H__
#define CHANGELIST_H__

#include "maxon/object.h"

namespace maxon
{

class ChangeList;

class ChangeListInterface : MAXON_INTERFACE_BASES(ObjectInterface)
{
	MAXON_INTERFACE(ChangeListInterface, MAXON_REFERENCE_COPY_ON_WRITE, "net.maxon.interface.changelist");

public:
	MAXON_METHOD Bool IsPopulated() const;

	MAXON_FUNCTION Bool IsEmpty() const
	{
		return !IsPopulated();
	}

	MAXON_METHOD Result<void> MergeAppend(ChangeList&& list);
};


#include "changelist1.hxx"
#include "changelist2.hxx"

}

#endif // CHANGELIST_H__
