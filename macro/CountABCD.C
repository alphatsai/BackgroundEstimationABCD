#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <vector>
#include "TFile.h"
#include "TH1D.h"
#include "TStyle.h"
#include "TROOT.h"
using namespace std;
void countAndStore( string title, string h_name, string h_fname, fstream& f, bool showVSBkg=0, string bkg_name="", string bkg_fname="" );
void CountABCD(){

	string loadpath = "../test/OnLxplus/";
	string savepath = "results/";
	vector<string> workspace, fileName;	
	workspace.push_back("14May_PU_Mean"); 	fileName.push_back("Final_histograms_ABCD.root");
	workspace.push_back("14May_PU_UP");	fileName.push_back("Final_histograms_ABCD.root");
	workspace.push_back("14May_PU_Down");	fileName.push_back("Final_histograms_ABCD.root");
	
	vector<string> hName;
	hName.push_back("ABCDana_CutRegion");
	hName.push_back("ABCDana_CutRegion_1b");
	hName.push_back("ABCDana_CutRegion_2b");

	vector<string> Title, fullName; 
	Title.push_back("BHBH450"); 	fullName.push_back("BprimeBprimeToBHBHinc_M-450");
	Title.push_back("BHBH500"); 	fullName.push_back("BprimeBprimeToBHBHinc_M-500");
	Title.push_back("BHBH550"); 	fullName.push_back("BprimeBprimeToBHBHinc_M-550");
	Title.push_back("BHBH600"); 	fullName.push_back("BprimeBprimeToBHBHinc_M-600");
	Title.push_back("BHBH650");	fullName.push_back("BprimeBprimeToBHBHinc_M-650");
	Title.push_back("BHBH700"); 	fullName.push_back("BprimeBprimeToBHBHinc_M-700");
	Title.push_back("BHBH750"); 	fullName.push_back("BprimeBprimeToBHBHinc_M-750");
	Title.push_back("BHBH800"); 	fullName.push_back("BprimeBprimeToBHBHinc_M-800");
	Title.push_back("BHBH1000"); 	fullName.push_back("BprimeBprimeToBHBHinc_M-1000");
	Title.push_back("BHBH1200"); 	fullName.push_back("BprimeBprimeToBHBHinc_M-1200");
	Title.push_back("BHBH1500"); 	fullName.push_back("BprimeBprimeToBHBHinc_M-1500");

	const int workspaceSize = workspace.size();
	const int hSize = hName.size();
	const int titleSize = Title.size();
	
	fstream output[workspaceSize][hSize];

	for( int i=0; i<workspaceSize; i++ ){
		cout<<"[Workspace] "<<workspace[i]<<endl;
		for( int j=0; j<hSize; j++ ){
			cout<<hName[j]<<"..."<<endl;
			string save = savepath + workspace[i]+"_"+hName[j]+".txt";	
			output[i][j].open(save.c_str(),ios_base::out);
			for( int k=0; k<titleSize; k++){
				string hname = fullName[k]+"__"+hName[j];
				string fname = loadpath + workspace[i] + "/" + fileName[i]; 
				countAndStore( Title[k], hname, fname, output[i][j]);
			}
		}
	}

}
void countAndStore( string title, string h_name, string h_fname, fstream& f, bool showVSBkg, string bkg_name, string bkg_fname){

	TFile* hf = new TFile(h_fname.c_str());
	TH1D* h  = (TH1D*)hf->Get(h_name.c_str());

	float A, B, C, D, eA, eB, eC, eD;
	A = h->GetBinContent(1);
	B = h->GetBinContent(2);
	C = h->GetBinContent(3);
	D = h->GetBinContent(4);
	eA = h->GetBinError(1);  
	eB = h->GetBinError(2);
	eC = h->GetBinError(3);
	eD = h->GetBinError(4);

	float Ab, Bb, Cb, Db;
	if( showVSBkg && bkg_fname != "" && bkg_name != "" ){
		TFile* fbkg = new TFile(bkg_fname.c_str());
		TH1D* hbkg  = (TH1D*)fbkg->Get(bkg_name.c_str());
		Ab = hbkg->GetBinContent(1);
		Bb = hbkg->GetBinContent(2);
		Cb = hbkg->GetBinContent(3);
		Db = hbkg->GetBinContent(4);
	}

	float sigmaA=eA/A;
	float sigmaB=eB/B;
	float sigmaC=eC/C;
	float sigmaD=eD/D;
	float eBbyA = sqrt(sigmaA*sigmaA+sigmaB*sigmaB)*B/A;
	float eDbyC = sqrt(sigmaC*sigmaC+sigmaD*sigmaD)*D/C;
	float eBbyD = sqrt(sigmaB*sigmaB+sigmaD*sigmaD)*B/D;
	float eAbyC = sqrt(sigmaA*sigmaA+sigmaC*sigmaC)*A/C;
	float eADbyC = sqrt(sigmaA*sigmaA+sigmaC*sigmaC+sigmaD*sigmaD)*A*(D/C);	
	float eCBbyA = sqrt(sigmaC*sigmaC+sigmaB*sigmaB+sigmaA*sigmaA)*C*(B/A);	

	f<<"***************************************"<<endl;
	f<<"************* "<<title<<" **************"<<endl;
	f<<"***************************************"<<endl;
	f<<"Region\t"<<"Num\t\t"<<"Error(+/-)"<<endl;
	f<<"A\t"<<A<<"\t\t"<<eA<<endl;
	f<<"B\t"<<B<<"\t\t"<<eB<<endl;
	f<<"C\t"<<C<<"\t\t"<<eC<<endl;
	f<<"D\t"<<D<<"\t\t"<<eD<<endl;
	f<<endl;
	f<<"Form\t"<<"Ratio\t\t"<<"Error(+/-)"<<endl;
	f<<"B/A\t"<<B/A<<"\t\t"<<eBbyA<<endl;
	f<<"D/C\t"<<D/C<<"\t\t"<<eDbyC<<endl;
	f<<"B/D\t"<<B/D<<"\t\t"<<eBbyD<<endl;
	f<<"A/C\t"<<A/C<<"\t\t"<<eAbyC<<endl;
	f<<endl;
	f<<"Form\t"<<"Yields\t\t"<<"Error(+/-)"<<endl;
	f<<"A(D/C)\t"<<A*(D/C)<<"\t\t"<<eADbyC<<endl;
	f<<"C(B/A)\t"<<C*(B/A)<<"\t\t"<<eCBbyA<<endl;
	f<<endl;
	if( showVSBkg && bkg_fname != "" && bkg_name != "" ){
		f<<"Sig(A,C,D)/Sig(A,B,C,D): "<<(A+D+C)/(A+B+C+D)*100<<"%"<<endl;
		f<<"Sig(A,C,D)/Bkg(A,C,D)+Sig(A,C,D): "<<(A+D+C)/(A+D+C+Ab+Db+Cb)*100<<"%"<<endl;
	}
	f<<endl;
}
