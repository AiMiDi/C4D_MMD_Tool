#ifndef TOOLSCULPTBRUSHMULTI_H__
#define TOOLSCULPTBRUSHMULTI_H__

enum
{
	ToolSculptBrushMulti_Start = 20000,

	MDATA_SCULPTBRUSH_MULTI_ORDER = 20100,
	MDATA_SCULPTBRUSH_MULTI_ORDER_SEQ = 0,				//Use each stamp sequentially. When the last stamp is used start again from the first
	MDATA_SCULPTBRUSH_MULTI_ORDER_RANDOMALL = 1,  //Randomly select a stamp from the list and use each stamp only once until they are all used. Then start again.
	MDATA_SCULPTBRUSH_MULTI_ORDER_RANDOM = 2,			//Always randomly select stamp. Stamps can repeat themselves before all stamps are used.

	MDATA_SCULPTBRUSH_MULTI_STROKE = 20200,
	MDATA_SCULPTBRUSH_MULTI_STROKE_MIRROR = 0,		//Make all other strokes the same as the main stroke.
	MDATA_SCULPTBRUSH_MULTI_STROKE_SAMELIST = 1,  //Select a different stamp for each stroke from the same list.  
	MDATA_SCULPTBRUSH_MULTI_STROKE_PERSTROKE = 2,		//Each stroke has its own list of stamps from which the stamps are chose sequentially, randomly etc...

	MDATA_SCULPTBRUSH_MULTI_REPEAT = 20301, //Repeat a stamp X number of times before selecting the next stamp.

};

#endif // TOOLSCULPTBRUSHMULTI_H__
