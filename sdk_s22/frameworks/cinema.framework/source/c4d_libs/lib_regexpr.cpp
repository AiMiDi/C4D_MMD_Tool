#include "c4d_library.h"
#include "lib_regexpr.h"
#include "c4d_basecontainer.h"

RegExprLib* lib_regexpr = nullptr;

static RegExprLib *CheckLibRegExpr(Int32 offset)
{
	return (RegExprLib*)CheckLib(REG_EXP_PARSER, offset, (C4DLibrary**)&lib_regexpr);
}

#define RegExprLibCall(b) 		RegExprLib *lib = CheckLibRegExpr(LIBOFFSET(RegExprLib, b)); \
															if (!lib || !lib->b) return; \
															(((RegExpParser*)this)->*lib->b)

#define RegExprLibCallR(a, b)  RegExprLib *lib = CheckLibRegExpr(LIBOFFSET(RegExprLib, b)); \
															if (!lib || !lib->b) return a; \
															return (((RegExpParser*)this)->*lib->b)

RegularExprParser* RegularExprParser::Alloc()
{
	RegExprLib *lib = CheckLibRegExpr(LIBOFFSET(RegExprLib, RegExprLib_Alloc)); if (!lib) return nullptr;
	return (RegularExprParser*)lib->RegExprLib_Alloc();
}

void RegularExprParser::Free(RegularExprParser* p)
{
	if (!p) return;
	RegExprLib *lib = CheckLibRegExpr(LIBOFFSET(RegExprLib, RegExprLib_Free)); if (!lib) return;
	RegExpParser* i = (RegExpParser*)p;
	lib->RegExprLib_Free(i);
	p = nullptr;
}

Bool RegularExprParser::Init(const String &strExprssion)
{
	RegExprLibCallR(false, Init)(strExprssion);
}

Bool RegularExprParser::FindFirst(const String &strText, REGPARSEMODE mode, Bool bOnlyFirst, Int32 &lPos, String &strPattern)
{
	RegExprLibCallR(false, FindFirst)(strText, mode, bOnlyFirst, lPos, strPattern);
}

Bool RegularExprParser::FindNext(Int32 &lPos, String &strPattern)
{
	RegExprLibCallR(false, FindNext)(lPos, strPattern);
}

void RegularExprParser::CleanUp()
{
	RegExprLibCall(CleanUp)();
}
