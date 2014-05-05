#ifndef TH2INFOCLASS_H
#define TH2INFOCLASS_H

#include <map>
#include <string>
#include "TFile.h"
#include "TH2Info.h"
#include "TH2InfoVarClass.h"
using namespace std;

template<typename TH2> 
class TH2InfoClass{
        public:
                //Fun. of initial TH2
                TH2InfoClass();
		void CreateTH2();
		void CreateTH2(edm::Service<TFileService> f);
		void CreateTH2( TFile* f, std::string dirName ); // dirName, ex: "ROC_1/"
		void SetTitles(); 
                void Sumw2();
                TH2* GetTH2(std::string Name_);
                TH2InfoVarClass GetVar(std::string Name_);
                TH2InfoVarClass GetVar(int index);

	private:
                //Detail info
                map<std::string, TH2*> mapTH2;
                map<std::string, int> indexTH2;
		TH2InfoVarClass Var[TH2_Size_];
		
};

// Define function
// Constructor
template<typename TH2> 
TH2InfoClass<TH2>::TH2InfoClass(){
        for(int i=0; i<TH2_Size_; i++){ //Loop all kind of TH2
                Var[i].Name = TH2Info[i].Name;
		Var[i].Title = TH2Info[i].Title;
		Var[i].xTitle = TH2Info[i].xTitle;
		Var[i].yTitle = TH2Info[i].yTitle;
		Var[i].xUnit = TH2Info[i].xUnit;
		Var[i].yUnit = TH2Info[i].yUnit;
                Var[i].xBin  = TH2Info[i].xBin;
               	Var[i].yBin  = TH2Info[i].yBin;
                Var[i].xMax  = TH2Info[i].xMax;
                Var[i].yMax  = TH2Info[i].yMax;
                Var[i].xMin  = TH2Info[i].xMin;
                Var[i].yMin  = TH2Info[i].yMin;
		indexTH2[Var[i].Name]=i;
        }
}

// Create Histogram
template<typename TH2> 
void TH2InfoClass<TH2>::CreateTH2(){
        for(int i=0; i<TH2_Size_; i++){ 
                mapTH2[Var[i].Name] = new TH2(Var[i].Name.c_str(),"",Var[i].xBin, Var[i].xMin, Var[i].xMax, Var[i].yBin, Var[i].yMin, Var[i].yMax);
        }

}
template<typename TH2> 
void TH2InfoClass<TH2>::CreateTH2(edm::Service<TFileService> f){
        for(int i=0; i<TH2_Size_; i++){ 
                mapTH2[Var[i].Name] = f->make<TH2>(Var[i].Name.c_str(),"",Var[i].xBin, Var[i].xMin, Var[i].xMax, Var[i].yBin, Var[i].yMin, Var[i].yMax);
        }
}
template<typename TH2> 
void TH2InfoClass<TH2>::CreateTH2( TFile* f, std::string dirName="" ){
        for(int i=0; i<TH2_Size_; i++){ 
                mapTH2[Var[i].Name] = (TH2*)f->Get( (dirName+Var[i].Name).c_str());
        }
}

// Set some option for Histogram
template<typename TH2> 
void TH2InfoClass<TH2>::SetTitles(){
        for(int i=0; i<TH2_Size_; i++){ 
                //mapTH2[Var[i].Name]->SetTitle(    Var[i].Title.c_str());
                mapTH2[Var[i].Name]->SetXTitle( Var[i].xTitle.c_str());
                mapTH2[Var[i].Name]->SetYTitle( Var[i].yTitle.c_str());
        }
}

template<typename TH2> 
void TH2InfoClass<TH2>::Sumw2(){
        for(int i=0; i<TH2_Size_; i++){ 
                mapTH2.find(Var[i].Name)->second->Sumw2();
        }
}

// Get Histogram
template<typename TH2> 
TH2* TH2InfoClass<TH2>::GetTH2(std::string Name_){
        return mapTH2.find(Name_)->second;
}

// Get Variables
template<typename TH2> 
TH2InfoVarClass TH2InfoClass<TH2>::GetVar(std::string Name_){
        return Var[indexTH2.find(Name_)->second];
}
template<typename TH2> 
TH2InfoVarClass TH2InfoClass<TH2>::GetVar(int index){
        return Var[index];
}
#endif
