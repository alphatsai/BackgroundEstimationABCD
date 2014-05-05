#ifndef TH2INFO_H
#define TH2INFO_H

enum th2flist_{
	ABCDana_2D_, 				//01-13
	ABCDval_2D_, 				//01-13
	TH2_Size_
};

struct TH2Info_{
	bool Output;
	std::string 	Name;
	std::string 	Title;
	std::string 	xTitle;
	std::string 	yTitle;
	std::string 	xUnit;
	std::string 	yUnit;
	int 	xBin;
	double 	xMin;
	double 	xMax;
	int 	yBin;
	double 	yMin;
	double 	yMax;
};

struct TH2Info_ TH2Info[TH2_Size_] = {
	{ 1, "ABCDana_2D",			"",	"",	"Pruned Mass(Higgs)", 		"", "GeV/c^{2}",	2, 0, 2, 151, 0, 151,}, //06-06
	{ 1, "ABCDval_2D",			"",	"",	"Pruned Mass(Higgs)", 		"", "GeV/c^{2}",	2, 0, 2, 151, 0, 151,}, //06-06
};

#endif  
