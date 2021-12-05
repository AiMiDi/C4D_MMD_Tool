#ifndef C4D_PMAIN_H__
#define C4D_PMAIN_H__

extern "C"
{
	#define C4D_MAIN MAXON_ATTRIBUTE_DLL_PUBLIC Int32 c4d_main(Int32 action, void* p1, void* p2, void* p3)
	C4D_MAIN;
}

#endif // C4D_PMAIN_H__
