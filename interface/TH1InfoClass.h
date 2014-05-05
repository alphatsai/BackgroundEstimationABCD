#ifndef TH1INFOCLASS_H
#define TH1INFOCLASS_H

#include <map>
#include <string>
#include "TFile.h"
#include "TH1Info.h"
#include "TH1InfoVarClass.h"

using namespace std;

template<typename TH1> 
class TH1InfoClass{
        public:
                //Fun. of initial TH1
                TH1InfoClass();
		void CreateTH1();
		void CreateTH1(edm::Service<TFileService> f);
		void CreateTH1(TFile* f, std::string dirName ); // dirName, ex: "BprimeBH/"
		void SetTitles(); 
                void Sumw2();
                TH1* GetTH1(std::string Name_);
                TH1InfoVarClass GetVar(std::string Name_);
                TH1InfoVarClass GetVar(int index);

	private:
                //Detail info
                map<std::string, TH1*> mapTH1;
                map<std::string, int> indexTH1;
		TH1InfoVarClass Var[TH1_Size_];
};

/////// Define function ==============================================
// Constructor
template<typename TH1> 
TH1InfoClass<TH1>::TH1InfoClass(){
        for(int i=0; i<TH1_Size_; i++){ //Loop all kind of TH1
                Var[i].Name  = TH1Info[i].Name;
		Var[i].Title = TH1Info[i].Title;
		Var[i].xTitle = TH1Info[i].xTitle;
		Var[i].yTitle = TH1Info[i].yTitle;
		Var[i].Unit = TH1Info[i].Unit;
                Var[i].Bin  = TH1Info[i].Bin;
                Var[i].Max  = TH1Info[i].Max;
                Var[i].Min  = TH1Info[i].Min;
		indexTH1[Var[i].Name]=i;
        }

}

// Create Histogram
template<typename TH1> 
void TH1InfoClass<TH1>::CreateTH1(){
        for(int i=0; i<TH1_Size_; i++){
                mapTH1[Var[i].Name] = new TH1(Var[i].Name.c_str(),"",Var[i].Bin, Var[i].Min, Var[i].Max);
        }
}

template<typename TH1> 
void TH1InfoClass<TH1>::CreateTH1(edm::Service<TFileService> f){
        for(int i=0; i<TH1_Size_; i++){
                mapTH1[Var[i].Name] =f->make<TH1>(Var[i].Name.c_str(),"",Var[i].Bin, Var[i].Min, Var[i].Max);
        }
}

template<typename TH1> 
void TH1InfoClass<TH1>::CreateTH1( TFile* f, std::string dirName="" ){
        for(int i=0; i<TH1_Size_; i++){ 
                mapTH1[Var[i].Name] =(TH1*)f->Get( (dirName+Var[i].Name).c_str() );
        }

}

// Set some option for Histogram
template<typename TH1> 
void TH1InfoClass<TH1>::SetTitles(){
        for(int i=0; i<TH1_Size_; i++){ 
                //mapTH1[Var[i].Name]->SetTile(Var[i].Title.c_str());
                mapTH1[Var[i].Name]->SetXTitle( (Var[i].xTitle+" ["+Var[i].Unit+"]").c_str());
                mapTH1[Var[i].Name]->SetYTitle( Var[i].yTitle.c_str() );
        }
}
 
template<typename TH1> 
void TH1InfoClass<TH1>::Sumw2(){
        for(int i=0; i<TH1_Size_; i++){ 
                mapTH1.find(Var[i].Name)->second->Sumw2();
        }
}

// Get Histogram
template<typename TH1> 
TH1* TH1InfoClass<TH1>::GetTH1(std::string Name_){
        return mapTH1.find(Name_)->second;
}

// Get Variables
template<typename TH1> 
TH1InfoVarClass TH1InfoClass<TH1>::GetVar(std::string Name_){
        return Var[indexTH1.find(Name_)->second];
}
template<typename TH1> 
TH1InfoVarClass TH1InfoClass<TH1>::GetVar(int index){
        return Var[index];
}

#endif
