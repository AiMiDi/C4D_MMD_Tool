#ifndef OBEND_H__
#define OBEND_H__

enum
{
	BENDOBJECT_SIZE			 = 1000, // Vector
	BENDOBJECT_MODE			 = 1001, // LONG 0=limited, 1=half limited, 2=unlimited
		BENDOBJECT_MODE_LIMIT 		= 1,
		BENDOBJECT_MODE_BOX   		= 0,
		BENDOBJECT_MODE_UNLIMITED	= 2,
	BENDOBJECT_STRENGTH  	= 1002, // Real
	BENDOBJECT_ANGLE     	= 1003, // Real
	BENDOBJECT_KEEPYAXIS	= 1006
};

#endif // OBEND_H__
