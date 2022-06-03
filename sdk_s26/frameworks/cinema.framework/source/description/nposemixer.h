#ifndef NPOSEMIXER_H__
#define NPOSEMIXER_H__

enum
{
	PMIX_LINK = 1000,
//	PMIX_VALUE,
	PMIX_ORIG, // link
	PMIX_DEST, // link

	PMIX_POS, // bool
	PMIX_SCL, // bool
	PMIX_ROT, // bool
	PMIX_PNT, // bool
	PMIX_XCL, // bool

	PMIX_ADD,  // button
	PMIX_REC,  // button
	PMIX_RES,  // button

	PMIX_DIRTY_HACK,

	PMIX_SGROUP,  //

	PMIX_DATA_USE    = 3000,
	PMIX_DATA_VALUE  = 3001,
	PMIX_DATA_LINK   = 3002,




	PMIX_DUMMY
};

#endif // NPOSEMIXER_H__
