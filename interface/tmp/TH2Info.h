#ifndef TH2INFO_H
#define TH2INFO_H

#include <string>
#include "enumList.h"

struct TH2Info_{
	string 	Name;
	string 	Title;
	string 	xTitle;
	string 	yTitle;
	string 	xUnit;
	string 	yUnit;
	int 	xBin;
	double 	xMin;
	double 	xMax;
	int 	yBin;
	double 	yMin;
	double 	yMax;
};

struct TH2Info_ TH2Info[TH2_Size_] = {
	{ "HitsMap", 	"Hits Map", 	"Column", "Row", 	"", "",	53, 0, 53, 81, 0, 81},
};




#endif  
