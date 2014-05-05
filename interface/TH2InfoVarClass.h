#ifndef TH2INFOVARCLASS_H
#define TH2INFOVARCLASS_H

class TH2InfoVarClass{
	public:
		std::string  	Name;
		std::string	Title;
		std::string	xTitle;
		std::string	yTitle;
		std::string	xUnit;
		std::string	yUnit;
                int     xBin;
                int     yBin;
                double  xMin;
                double  yMin;
                double  xMax;
                double  yMax;
};

#endif
