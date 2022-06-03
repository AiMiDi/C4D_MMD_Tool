#ifndef TDRIVER_H__
#define TDRIVER_H__

enum
{
	DRIVERTAG_SOURCEMODE_OFF		=	0,
	DRIVERTAG_TARGETMODE_OFF		= 0,

	DRIVERTAG_MODE_SINGLES			=	0,
	DRIVERTAG_MODE_RELATIVES		= 1,

	DRIVERTAG_DRIVERVECTORMODEX	=	0,
	DRIVERTAG_DRIVERVECTORMODEY	=	1,
	DRIVERTAG_DRIVERVECTORMODEZ	=	2,

	DRIVERTAG_ABSMODE_NORMAL		= 0,
	DRIVERTAG_ABSMODE_ADD				=	1,
	DRIVERTAG_ABSMODE_MULTIPLY	=	2,

	DRIVERTAG_GROUPDRIVER				=	990,
	DRIVERTAG_GROUPDRIVING			=	991,
	DRIVERTAG_GROUPRELATIVE			=	992,

	DRIVERTAG_DRIVENOBJECT			=	1000,
	DRIVERTAG_DRIVERPARAMETER,
	DRIVERTAG_DRIVERVECTORMODE,
	DRIVERTAG_DRIVERGRIDX,
	DRIVERTAG_DRIVERGRIDY,
	DRIVERTAG_DRIVERGRID,
	DRIVERTAG_DRIVENPARAMETER,
	DRIVERTAG_DRIVERMIX,
	DRIVERTAG_DRIVERRELATIVE,
	DRIVERTAG_DRIVERMIN,
	DRIVERTAG_DRIVERMAX,
	DRIVERTAG_DRIVERVECTORMIN,
	DRIVERTAG_DRIVERVECTORMAX,
	DRIVERTAG_MODE,
	DRIVERTAG_CLAMP,
	DRIVERTAG_ABSMODE
};

#endif // TDRIVER_H__
