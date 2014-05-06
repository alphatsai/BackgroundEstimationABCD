// -*- C++ -*-
//
// Package:    BackgroundEstimationABCD
// Class:      BackgroundEstimationABCD
// 
/**\class BackgroundEstimationABCD BackgroundEstimationABCD.cc Bprime_kit/BackgroundEstimationABCD/src/BackgroundEstimationABCD.cc

Description: 
Analyzer class for Bprime -> b Higgs studies 
- National Taiwan University - 

Implementation:
[Notes on implementation]
 */
//
// Original Author:  Jui-Fa Tsai
//         Created:  Tue Jul 16 19:48:47 CEST 2013
// Second Author:    Devdatta Majumder 
// $Id$
//
//

// system include files
#include <memory>
#include <iostream>
#include <cmath>
#include <ctime>
#include <fstream>
#include <assert.h>
#include <vector>
#include <map>
#include <string>

// Root headers 
#include <TLorentzVector.h>
#include <TChain.h>
#include <TTree.h>
#include <TFile.h>
#include <TMath.h>
#include <TH1D.h>
#include <TH2D.h>
#include <TH1I.h>
#include <TEfficiency.h>

// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "DataFormats/Math/interface/deltaR.h"

#include "FWCore/ServiceRegistry/interface/Service.h"
#include "CommonTools/UtilAlgos/interface/TFileService.h"

//#include "../interface/format.h"
#include "BpbH/BprimeTobH/interface/format.h"
#include "BpbH/BprimeTobH/interface/TriggerBooking.h"

#include "PhysicsTools/Utilities/interface/LumiReWeighting.h"
#include "PhysicsTools/Utilities/interface/LumiReweightingStandAlone.h" 

//Plots information
#include "BpbH/BackgroundEstimationABCD/interface/TH2InfoClass.h"
#include "BpbH/BackgroundEstimationABCD/interface/TH1InfoClass.h"

//Evt selection
#include "BpbH/BprimeTobHAnalysis/interface/EventSelector.h"
#include "BpbH/BprimeTobHAnalysis/interface/HiggsBRscaleFactors.h" 

///// Jet Correction
//#include "BpbH/BprimeTobHAnalysis/src/JMEUncertUtil.cc"
//#include "BpbH/BprimeTobHAnalysis/src/BTagSFUtil.cc"
//#include "BpbH/BprimeTobHAnalysis/src/ApplyBTagSF.cc"
//#include "BpbH/BprimeTobHAnalysis/src/ApplyHiggsTagSF.cc"

//#include "BpbH/BprimeTobHAnalysis/interface/JMEUncertUtil.h"
//#include "BpbH/BprimeTobHAnalysis/interface/ApplyBTagSF.h"
//#include "BpbH/BprimeTobHAnalysis/interface/ApplyHiggsTagSF.h"

//
// class declaration
//

class BackgroundEstimationABCD : public edm::EDAnalyzer{
	public:
		explicit BackgroundEstimationABCD(const edm::ParameterSet&);
		~BackgroundEstimationABCD();

		static void fillDescriptions(edm::ConfigurationDescriptions& descriptions);

	private:
		virtual void beginJob();
		virtual void analyze(const edm::Event&, const edm::EventSetup&);
		virtual void endJob();

		int CloseJetIndex( JetCollection jets_, const Jet myJet_ );
		void isolateCollection( JetCollection control_, JetCollection input_, JetCollection& output_, double dR_=1.2 );
		void recoBprime( JetInfoBranches& JetInfo, JetCollection bjets_, const Jet H_, vector<TLorentzVector>& p4_output );
		template <typename TH1>
		void setABCDcutRegion(TH1* h1);
	
		edm::LumiReWeighting LumiWeights_; 

		// ----------member data ---------------------------

		//// Configurables 

		int                             maxEvents_; 
		const int                       reportEvery_; 
		const std::string               inputTTree_;
		const std::vector<std::string>  inputFiles_;
		const edm::ParameterSet         hltPaths_; 
		const bool     DoHLTSelect_;
		const bool     DoGoodVtxSelect_;
		const bool     DoPUReweighting_;
		const std::string               file_PUDistMC_;
		const std::string               file_PUDistData_;
		const std::string               hist_PUDistMC_;
		const std::string               hist_PUDistData_;
		const double     HTAK5Min_;
		const double     HTAK5Max_;

		const double     HJetPtMin_;
		const double     HJetPtMax_;
		const double     HJetAbsEtaMin_;
		const double     HJetAbsEtaMax_;
		const double     HJetMassMin_;	
		const double     HJetMassMax_;	
		const double     HJetPrunedMassMin_;	
		const double     HJetPrunedMassMax_;	
		const double     HJetTau2ByTau1Min_;
		const double     HJetTau2ByTau1Max_;
		const double     Subjet1CSVDiscMin_;
		const double     Subjet1CSVDiscMax_;
		const double     Subjet2CSVDiscMin_;
		const double     Subjet2CSVDiscMax_;
		const double     dRSubjetsMin_;
		const double     dRSubjetsMax_;

		const double     HJetSBMassMin_;	
		const double     HJetSBMassMax_;

		const double     JetPtMin_;
		const double     JetPtMax_;
		const double     JetAbsEtaMin_;
		const double     JetAbsEtaMax_;
		const double     bJetPtMin_;
		const double     bJetPtMax_;
		const double     bJetCSVDiscMin_;
		const double     bJetCSVDiscMax_;

		const double     bVetoJetPtMin_;
		const double     bVetoJetPtMax_;
		const double     bVetoJetAbsEtaMin_;
		const double     bVetoJetAbsEtaMax_;
		const double     bVetoJetCSVDiscMin_;
		const double     bVetoJetCSVDiscMax_;

		const int     numbJet_;
		const int     numHiggsJet_;

		//const double jesShift_;
		//const double jerShift_; 
		//const double SFbShift_;
		//const double SFlShift_;

		bool BuildMinTree_;

		TChain*            chain_;
		TTree*             newtree_ana;

		GenInfoBranches GenInfo;
		EvtInfoBranches    EvtInfo;
		VertexInfoBranches VtxInfo;
		JetInfoBranches CA8JetInfo, HiggsJetInfoAna, AntiHiggsJetInfoAna;
		JetInfoBranches AK5JetInfo, bJetInfoAna;
		JetInfoBranches SubJetInfo, HiggsSubJet1InfoAna, HiggsSubJet2InfoAna, AntiHiggsSubJet1InfoAna, AntiHiggsSubJet2InfoAna;

		edm::Service<TFileService> fs; 
		
		TH2InfoClass<TH2D> h2;
		TH1InfoClass<TH1D> h1;

		bool isData_; 
		bool evtwt_;
		double puweight_;
		double higgsTagCorr_;

		// New branch
		int GenEvt_;
		bool McFlagana;
		//double xsec_;
		double PUana;
		double evtWtana;
		double HTak5, HThiggsbjet;

		//variables
		int	evtPass_ana;
		int 	evtPass_val;

};

//
// constructors and destructor
//
BackgroundEstimationABCD::BackgroundEstimationABCD(const edm::ParameterSet& iConfig) : 
	maxEvents_(iConfig.getParameter<int>("MaxEvents")), 
	reportEvery_(iConfig.getParameter<int>("ReportEvery")),
	inputTTree_(iConfig.getParameter<std::string>("InputTTree")),
	inputFiles_(iConfig.getParameter<std::vector<std::string> >("InputFiles")),

	hltPaths_(iConfig.getParameter<edm::ParameterSet>("HLTPaths")),

	DoHLTSelect_(iConfig.getParameter<bool>("DoHLTSelect")),
	DoGoodVtxSelect_(iConfig.getParameter<bool>("DoGoodVtxSelect")),
	DoPUReweighting_(iConfig.getParameter<bool>("DoPUReweighting")),
	file_PUDistMC_(iConfig.getParameter<std::string>("File_PUDistMC")),
	file_PUDistData_(iConfig.getParameter<std::string>("File_PUDistData")),
	hist_PUDistMC_(iConfig.getParameter<std::string>("Hist_PUDistMC")),
	hist_PUDistData_(iConfig.getParameter<std::string>("Hist_PUDistData")),

	HTAK5Min_(iConfig.getParameter<double>("HTAK5Min")),
	HTAK5Max_(iConfig.getParameter<double>("HTAK5Max")),

	HJetPtMin_(iConfig.getParameter<double>("HJetPtMin")),
	HJetPtMax_(iConfig.getParameter<double>("HJetPtMax")),
	HJetAbsEtaMin_(iConfig.getParameter<double>("HJetAbsEtaMin")),
	HJetAbsEtaMax_(iConfig.getParameter<double>("HJetAbsEtaMax")),
	HJetMassMin_(iConfig.getParameter<double>("HJetMassMin")),	
	HJetMassMax_(iConfig.getParameter<double>("HJetMassMax")),	
	HJetPrunedMassMin_(iConfig.getParameter<double>("HJetPrunedMassMin")),	
	HJetPrunedMassMax_(iConfig.getParameter<double>("HJetPrunedMassMax")),	
	HJetTau2ByTau1Min_(iConfig.getParameter<double>("HJetTau2ByTau1Min")),
	HJetTau2ByTau1Max_(iConfig.getParameter<double>("HJetTau2ByTau1Max")),
	Subjet1CSVDiscMin_(iConfig.getParameter<double>("Subjet1CSVDiscMin")),
	Subjet1CSVDiscMax_(iConfig.getParameter<double>("Subjet1CSVDiscMax")),
	Subjet2CSVDiscMin_(iConfig.getParameter<double>("Subjet2CSVDiscMin")),
	Subjet2CSVDiscMax_(iConfig.getParameter<double>("Subjet2CSVDiscMax")),
	dRSubjetsMin_(iConfig.getParameter<double>("dRSubjetsMin")),
	dRSubjetsMax_(iConfig.getParameter<double>("dRSubjetsMax")),

	HJetSBMassMin_(iConfig.getParameter<double>("HJetSBMassMin")),	
	HJetSBMassMax_(iConfig.getParameter<double>("HJetSBMassMax")),

	JetPtMin_(iConfig.getParameter<double>("JetPtMin")),
	JetPtMax_(iConfig.getParameter<double>("JetPtMax")),
	JetAbsEtaMin_(iConfig.getParameter<double>("JetAbsEtaMin")),
	JetAbsEtaMax_(iConfig.getParameter<double>("JetAbsEtaMax")),
	bJetPtMin_(iConfig.getParameter<double>("bJetPtMin")),
	bJetPtMax_(iConfig.getParameter<double>("bJetPtMax")),
	bJetCSVDiscMin_(iConfig.getParameter<double>("bJetCSVDiscMin")),
	bJetCSVDiscMax_(iConfig.getParameter<double>("bJetCSVDiscMax")),

	bVetoJetPtMin_(iConfig.getParameter<double>("bVetoJetPtMin")),
	bVetoJetPtMax_(iConfig.getParameter<double>("bVetoJetPtMax")),
	bVetoJetAbsEtaMin_(iConfig.getParameter<double>("bVetoJetAbsEtaMin")),
	bVetoJetAbsEtaMax_(iConfig.getParameter<double>("bVetoJetAbsEtaMax")),
	bVetoJetCSVDiscMin_(iConfig.getParameter<double>("bVetoJetCSVDiscMin")),
	bVetoJetCSVDiscMax_(iConfig.getParameter<double>("bVetoJetCSVDiscMax")),

	numbJet_(iConfig.getParameter<int>("numbJet")),
	numHiggsJet_(iConfig.getParameter<int>("numHiggsJet")),

	BuildMinTree_(iConfig.getParameter<bool>("BuildMinTree")),
/*	higgsJetSelParame_(iConfig.getParameter<edm::ParameterSet>("HiggsJetSelParams")),
	jetSelParams_(iConfig.getParameter<edm::ParameterSet>("JetSelParams")), 
	bjetSelParams_(iConfig.getParameter<edm::ParameterSet>("BJetSelParams")), 
	evtSelParams_(iConfig.getParameter<edm::ParameterSet>("EvtSelParams")),
	jmeParams_(iConfig.getParameter<edm::ParameterSet>("JMEParams")),
	jesShift_(iConfig.getParameter<double>("JESShift")),
	jerShift_(iConfig.getParameter<double>("JERShift")),
	SFbShift_(iConfig.getParameter<double>("SFbShift")),
	SFlShift_(iConfig.getParameter<double>("SFlShift")),
*/
	isData_(0),
	evtwt_(1),
	puweight_(1),
	higgsTagCorr_(1),
	evtPass_ana(0),  
	evtPass_val(0) 
{ 
	if( DoPUReweighting_) LumiWeights_ = edm::LumiReWeighting(file_PUDistMC_, file_PUDistData_, hist_PUDistMC_, hist_PUDistData_);
}


BackgroundEstimationABCD::~BackgroundEstimationABCD(){ 
	delete chain_;
}

// ------------ Other function -------------
template <typename TH1>
void BackgroundEstimationABCD::setABCDcutRegion(TH1* h1){
	h1->GetXaxis()->SetBinLabel(1,"A");
	h1->GetXaxis()->SetBinLabel(2,"B");
	h1->GetXaxis()->SetBinLabel(3,"C");
	h1->GetXaxis()->SetBinLabel(4,"D");
}
int BackgroundEstimationABCD::CloseJetIndex( JetCollection jets_, const Jet myJet_ ){
	int min_index(-1);
	for( JetCollection::const_iterator ijet = jets_.begin(); ijet != jets_.end(); ++ijet ){
		float DR_min = 100.;
		if( myJet_.DeltaR(*ijet) < DR_min){
			DR_min = myJet_.DeltaR(*ijet);
			min_index = ijet->Index();   
			//cout<<min_index<<" "<<ijet->Index()<<endl;	 
		}
	}
	return min_index;
}
void BackgroundEstimationABCD::isolateCollection( JetCollection control_, JetCollection input_, JetCollection& output_, double dR_ ){
	for( JetCollection::const_iterator _i = input_.begin(); _i != input_.end(); ++_i ){
		bool isControl(false); 
		for( JetCollection::const_iterator _c = control_.begin(); _c != control_.end(); ++_c ){
			if( _c->DeltaR(*_i) < dR_ ){
				isControl = true; 
				break; 
			}else {
				isControl = false; 
			} 
		}
		if( !isControl ){
			output_.push_back(*_i);
		} 
	}
}
void BackgroundEstimationABCD::recoBprime( JetInfoBranches& JetInfo, JetCollection bjets_, const Jet H_, vector<TLorentzVector>& p4_output ){
	int bi = CloseJetIndex( bjets_, H_ );
	TLorentzVector p4_bp, p4_H, p4_b;
	p4_H.SetPtEtaPhiM(H_.Pt(), H_.Eta(), H_.Phi(), H_.Mass());
	p4_b.SetPtEtaPhiM(JetInfo.Pt[bi], JetInfo.Eta[bi], JetInfo.Phi[bi], JetInfo.Mass[bi]);
	p4_bp = p4_H + p4_b;
	p4_output.push_back( p4_bp );
}
// ------------ method called once each job just before starting event loop  ------------
void BackgroundEstimationABCD::beginJob(){ 
	chain_  = new TChain(inputTTree_.c_str());

	for(unsigned i=0; i<inputFiles_.size(); ++i){
		chain_->Add(inputFiles_.at(i).c_str());
		TFile *f = TFile::Open(inputFiles_.at(i).c_str(),"READ");
		f->Close();
	}

	EvtInfo.Register(chain_);
	VtxInfo.Register(chain_);
	GenInfo.Register(chain_);
	AK5JetInfo.Register(chain_,"JetInfo");
	CA8JetInfo.Register(chain_,"FatJetInfo");
	SubJetInfo.Register(chain_,"SubJetInfo");

	if(  maxEvents_<0 || maxEvents_>chain_->GetEntries()) maxEvents_ = chain_->GetEntries();

	if( BuildMinTree_ ){
		newtree_ana = fs->make<TTree>("tree", "");
		newtree_ana->Branch("EvtInfo.GenEvents",	&GenEvt_, 	"EvtInfo.GenEvents/I"); 
		newtree_ana->Branch("EvtInfo.McFlag", 		&McFlagana, 	"EvtInfo.McFlag/O"); // store weight of evt and pu for each event
		//newtree_ana->Branch("EvtInfo.XSec", 		&xsec_, 	"EvtInfo.XSec/D"); 
		newtree_ana->Branch("EvtInfo.PU", 		&PUana, 	"EvtInfo.PU/D"); // store weight of evt and pu for each event
		newtree_ana->Branch("EvtInfo.WeightEvt",	&evtWtana, 	"EvtInfo.WeightEvt/D"); 	
		newtree_ana->Branch("EvtInfo.HT_AK5",		&HTak5, 	"EvtInfo.HT_AK5/D"); 	
		newtree_ana->Branch("EvtInfo.HT_HiggsbJets",	&HThiggsbjet, 	"EvtInfo.HT_HiggsbJets/D"); 	
		HiggsJetInfoAna.RegisterTree(newtree_ana,"HiggsJetInfo");
		AntiHiggsJetInfoAna.RegisterTree(newtree_ana,"AntiHiggsJetInfo");
		bJetInfoAna.RegisterTree(newtree_ana,"bJetInfo");
		HiggsSubJet1InfoAna.RegisterTree(newtree_ana,"HiggsSubJet1Info");
		HiggsSubJet2InfoAna.RegisterTree(newtree_ana,"HiggsSubJet2Info");
		AntiHiggsSubJet1InfoAna.RegisterTree(newtree_ana,"AntiHiggsSubJet1Info");
		AntiHiggsSubJet2InfoAna.RegisterTree(newtree_ana,"AntiHiggsSubJet2Info");
	}

	h2.CreateTH2(fs); h2.Sumw2();
	h1.CreateTH1(fs); h1.Sumw2();
	
	h1.GetTH1("ABCDana_CutFlow")->GetXaxis()->SetBinLabel(1,"All_Evt");	
	h1.GetTH1("ABCDana_CutFlow")->GetXaxis()->SetBinLabel(2,"Trigger_Sel");	
	h1.GetTH1("ABCDana_CutFlow")->GetXaxis()->SetBinLabel(3,"Vertex_Sel");	
	h1.GetTH1("ABCDana_CutFlow")->GetXaxis()->SetBinLabel(4,"HT_Sel");	
	h1.GetTH1("ABCDana_CutFlow")->GetXaxis()->SetBinLabel(5,"ABCD_Sel");
	
	h1.GetTH1("ABCDval_CutFlow")->GetXaxis()->SetBinLabel(1,"All_Evt");	
	h1.GetTH1("ABCDval_CutFlow")->GetXaxis()->SetBinLabel(2,"Trigger_Sel");	
	h1.GetTH1("ABCDval_CutFlow")->GetXaxis()->SetBinLabel(3,"Vertex_Sel");	
	h1.GetTH1("ABCDval_CutFlow")->GetXaxis()->SetBinLabel(4,"HT_Sel");	
	h1.GetTH1("ABCDval_CutFlow")->GetXaxis()->SetBinLabel(5,"ABCD_Sel");	

	setABCDcutRegion(h1.GetTH1("ABCDana_CutRegion"));	
	setABCDcutRegion(h1.GetTH1("ABCDana_CutRegion_1b"));	
	setABCDcutRegion(h1.GetTH1("ABCDana_CutRegion_2b"));	
	setABCDcutRegion(h1.GetTH1("ABCDval_CutRegion"));
	
	return;  
}

// ------------ method called for each event  ------------
void BackgroundEstimationABCD::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup){ 
	using namespace edm;
	using namespace std;

	if(  chain_ == 0) return;

	ofstream fout("Evt_NoJets.txt"); 
	if(  isData_ ){
		fout << "EvtInfo.RunNo " << " EvtInfo.LumiNo " << " EvtInfo.EvtNo " << std::endl;
	}

	edm::LogInfo("StartingAnalysisLoop") << "Starting analysis loop\n";
	
	//// Roop events ==================================================================================================	
	for(int entry=0; entry<maxEvents_; entry++){
		if( (entry%reportEvery_) == 0) edm::LogInfo("Event") << entry << " of " << maxEvents_;
		chain_->GetEntry(entry);

		bool passHLT(false); 
		int nGoodVtxs(0);
		double HT_AK5(0);	
		double HT_HiggsBJets(0); 
		double weight_(1);
		double sumw2_a, sumw2_b, sumw2_c, sumw2_d; 
		double sumw2_a_1b, sumw2_b_1b, sumw2_c_1b, sumw2_d_1b; 
		double sumw2_a_2b, sumw2_b_2b, sumw2_c_2b, sumw2_d_2b; 
		double sumw2_av, sumw2_bv, sumw2_cv, sumw2_dv;
		sumw2_a = sumw2_b = sumw2_c = sumw2_d = sumw2_a_1b = sumw2_b_1b = sumw2_c_1b = sumw2_d_1b = sumw2_a_2b = sumw2_b_2b = sumw2_c_2b = sumw2_d_2b = sumw2_av= sumw2_bv= sumw2_cv= sumw2_dv = 0.;

		isData_  = EvtInfo.McFlag ? 0 : 1; 
		if( !isData_ ) evtwt_ = EvtInfo.Weight; 
		if( DoPUReweighting_ && !isData_ ) puweight_ = LumiWeights_.weight(EvtInfo.TrueIT[0]); 

		//// Higgs BR reweighting, for b'b'>bHbH sample
		double br_=1.;
		if ( !isData_ ) {
			//int nbprimeBH(0), nbprimeBZ(0), nbprimeTW(0); 
			for (int igen=0; igen < GenInfo.Size; ++igen) {
				if ( GenInfo.Status[igen] == 3 && TMath::Abs(GenInfo.PdgID[igen]) == 25 && GenInfo.nDa[igen] >= 2 ) { //// H found
					int higgsDau0 = abs(GenInfo.Da0PdgID[igen]);
					int higgsDau1 = abs(GenInfo.Da1PdgID[igen]);
					int higgsDau = higgsDau0+higgsDau1; 
					if(higgsDau==10) br_ *= HiggsBRscaleFactors::higgsBBSf;
					if(higgsDau==30) br_ *= HiggsBRscaleFactors::higgsTauTauSf;
					if(higgsDau==26) br_ *= HiggsBRscaleFactors::higgsMuMuSf;
					if(higgsDau==8)  br_ *= HiggsBRscaleFactors::higgsCCSf;
					if(higgsDau==6)  br_ *= HiggsBRscaleFactors::higgsSSSf;
					if(higgsDau==16) br_ *= HiggsBRscaleFactors::higgsTTSf;
					if(higgsDau==42) br_ *= HiggsBRscaleFactors::higgsGGSf;
					if(higgsDau==44) br_ *= HiggsBRscaleFactors::higgsGammaGammaSf;
					if(higgsDau==45) br_ *= HiggsBRscaleFactors::higgsZGammaSf;
					if(higgsDau==48) br_ *= HiggsBRscaleFactors::higgsWWSf;
					if(higgsDau==46) br_ *= HiggsBRscaleFactors::higgsZZSf; 
				}
			}
		}
		weight_ = puweight_*br_*evtwt_;
		double w2_ = weight_*weight_;
		//weight_=1;	

		h1.GetTH1("ABCDana_CutFlow")->Fill(0);	
		h1.GetTH1("ABCDval_CutFlow")->Fill(0);
	
		//// Trigger selection =====================================================================================
		TriggerSelector trigSel(hltPaths_); 
		passHLT = trigSel.getTrigDecision(EvtInfo); 
		if( !passHLT ) continue; 
		h1.GetTH1("ABCDana_CutFlow")->Fill(double(1),weight_);	
		h1.GetTH1("ABCDval_CutFlow")->Fill(double(1),weight_);

		//// Vertex selection =====================================================================================
		VertexSelector vtxSel(VtxInfo); 
		nGoodVtxs = vtxSel.NGoodVtxs(); 
		if( nGoodVtxs < 1){ edm::LogInfo("NoGoodPrimaryVertex") << " No good primary vertex "; continue; }
		h1.GetTH1("ABCDana_CutFlow")->Fill(double(2),weight_);	
		h1.GetTH1("ABCDval_CutFlow")->Fill(double(2),weight_);

		//// Recall data no Jet =====================================================================================
		if( isData_ ){
			if( AK5JetInfo.Size == 0 ) fout << EvtInfo.RunNo << " " << EvtInfo.LumiNo << " " << EvtInfo.EvtNo << std::endl; 
		}

		////  Higgs jets selection ================================================================================ 
		JetCollection HiggsJets, HiggsLikeJets, AllHiggsJets, AllHiggsJetsDRCut;
		JetCollection AntiHiggsJets, AntiHiggsLikeJets, AllAntiHiggsJets, AllAntiHiggsJetsDRCut;
		for( int i=0; i < CA8JetInfo.Size; ++i ){
			if( CA8JetInfo.NHF[i]>=0.99 || CA8JetInfo.NEF[i]>=0.99 || CA8JetInfo.NConstituents[i]<=1 || fabs(CA8JetInfo.Eta[i]) >=2.4 || CA8JetInfo.CHF[i]<=0 || CA8JetInfo.CEF[i]>=0.99 ||  CA8JetInfo.NCH[i]<=0 ) continue; //// apply loose jet ID
			if( fabs(CA8JetInfo.Eta[i]) > HJetAbsEtaMax_ ) continue; 
			if( CA8JetInfo.Pt[i] < HJetPtMin_ || CA8JetInfo.Pt[i] > HJetPtMax_ ) continue; //// apply jet pT cut

			//// Get subjets of fat jets
			int iSub1 = CA8JetInfo.Jet_SubJet1Idx[i];
			int iSub2 = CA8JetInfo.Jet_SubJet2Idx[i];
			if( iSub1 > 25 || iSub2 > 25) continue; //// skip fat jets only one subjet 
			if( SubJetInfo.Pt[iSub1]==0. || SubJetInfo.Pt[iSub2]==0. ) continue; //// skip fat jets for which one of the subjets has pT=0
			TLorentzVector Subjet1, Subjet2;
			Subjet1.SetPtEtaPhiM(SubJetInfo.Pt[iSub1], SubJetInfo.Eta[iSub1], SubJetInfo.Phi[iSub1], SubJetInfo.Mass[iSub1]);
			Subjet2.SetPtEtaPhiM(SubJetInfo.Pt[iSub2], SubJetInfo.Eta[iSub2], SubJetInfo.Phi[iSub2], SubJetInfo.Mass[iSub2]);
			double subjet_dy = Subjet1.Rapidity() - Subjet2.Rapidity();
			double subjet_dphi = Subjet1.DeltaPhi(Subjet2);
			double subjet_dyphi = sqrt( subjet_dy*subjet_dy + subjet_dphi*subjet_dphi );

			if( subjet_dyphi <(CA8JetInfo.Mass[i]/CA8JetInfo.Pt[i]) ) continue; //// skip infrared unsafe configurations
			if( CA8JetInfo.tau2[i]/CA8JetInfo.tau1[i] > HJetTau2ByTau1Max_ ) continue;
			if( SubJetInfo.CombinedSVBJetTags[iSub1]<0.244 || SubJetInfo.CombinedSVBJetTags[iSub2]<0.244 )  continue;

			if( SubJetInfo.CombinedSVBJetTags[iSub1] < Subjet1CSVDiscMin_ && SubJetInfo.CombinedSVBJetTags[iSub2]< Subjet2CSVDiscMin_){ //Anti-Higgs
				Jet CA8Jet(CA8JetInfo, i);
				AllAntiHiggsJets.push_back(CA8Jet);
				if( CA8JetInfo.MassPruned[i] > HJetPrunedMassMin_ && CA8JetInfo.MassPruned[i] < HJetPrunedMassMax_ ){  //// apply pruned jet mass cut 
					if( subjet_dyphi >= dRSubjetsMin_ && subjet_dyphi <= dRSubjetsMax_  ){
						AntiHiggsJets.push_back(CA8Jet);
						AllAntiHiggsJetsDRCut.push_back(CA8Jet);
					}
				}else{
					AntiHiggsLikeJets.push_back(CA8Jet);
					AllAntiHiggsJetsDRCut.push_back(CA8Jet);
				}
			}else if( SubJetInfo.CombinedSVBJetTags[iSub1] >= Subjet1CSVDiscMin_ && SubJetInfo.CombinedSVBJetTags[iSub2] >= Subjet2CSVDiscMin_ ){ //Higgs
				Jet CA8Jet(CA8JetInfo, i);
				AllHiggsJets.push_back(CA8Jet);
				if( CA8JetInfo.MassPruned[i] > HJetPrunedMassMin_ && CA8JetInfo.MassPruned[i] < HJetPrunedMassMax_ ){  //// apply pruned jet mass cut 
					if( subjet_dyphi >= dRSubjetsMin_ && subjet_dyphi <= dRSubjetsMax_  ){
						HiggsJets.push_back(CA8Jet);
						AllHiggsJetsDRCut.push_back(CA8Jet);
						HT_HiggsBJets = HT_HiggsBJets + CA8JetInfo.Pt[i]; 
					}
				}else{
					HiggsLikeJets.push_back(CA8Jet);
					AllHiggsJetsDRCut.push_back(CA8Jet);
				}
			}
		}//CA8

		//// bJet and bVeto selection ================================================================================
		JetCollection bJets;
		JetCollection bJets_Veto;
		for( int i=0; i<AK5JetInfo.Size; ++i){ 
			if( AK5JetInfo.NHF[i]>=0.90 || AK5JetInfo.NEF[i]>=0.90 || AK5JetInfo.NConstituents[i]<=1 || fabs(AK5JetInfo.Eta[i]) >=2.4 || AK5JetInfo.CHF[i]<=0 || AK5JetInfo.CEF[i]>=0.99 ||  AK5JetInfo.NCH[i]<=0 ) continue; //// apply loose jet ID
			if( fabs(AK5JetInfo.Eta[i]) > JetAbsEtaMax_ ) continue; 
			if( AK5JetInfo.Pt[i] < JetPtMin_ || AK5JetInfo.Pt[i] > JetPtMax_ ) continue; 

			HT_AK5 = HT_AK5 + AK5JetInfo.Pt[i];

			if( AK5JetInfo.CombinedSVBJetTags[i] <= bJetCSVDiscMin_ ) continue;
			if( AK5JetInfo.Pt[i] <= bJetPtMin_ ) continue;
			Jet bJet(AK5JetInfo, i);
			bJets.push_back(bJet);
		}//bJet end
		for( int i=0; i<AK5JetInfo.Size; ++i){ 
			if( AK5JetInfo.NHF[i]>=0.90 || AK5JetInfo.NEF[i]>=0.90 || AK5JetInfo.NConstituents[i]<=1 || fabs(AK5JetInfo.Eta[i]) >=2.4 || AK5JetInfo.CHF[i]<=0 || AK5JetInfo.CEF[i]>=0.99 ||  AK5JetInfo.NCH[i]<=0 ) continue; //// apply loose jet ID
			if( fabs(AK5JetInfo.Eta[i]) > bVetoJetAbsEtaMax_ ) continue; 
			if( AK5JetInfo.Pt[i] < bVetoJetPtMin_ ) continue; 
			if( AK5JetInfo.CombinedSVBJetTags[i] <= bVetoJetCSVDiscMin_ ) continue;
			Jet bJet(AK5JetInfo, i);
			bJets_Veto.push_back(bJet);
		}//bVeto's bJet selection end

		// dR(b, H)>1.2 to Isolate bJet and HJet //================================================================================================================
		JetCollection bJetsNotHiggs;
		JetCollection bJetsNotAllHiggs;
		JetCollection bJetsNotAllHiggsAllAntiHiggs;
		JetCollection bJetsNotAllHiggs_Veto;
		JetCollection bJetsNotAllHiggsAllAntiHiggs_Veto;
		// isolateCollection( control_collection, input_collection, output_collection, dR(control, input)>1.2 )
		isolateCollection( HiggsJets, 		bJets, 			bJetsNotHiggs, 			1.2);
		isolateCollection( AllHiggsJets, 	bJets, 			bJetsNotAllHiggs, 		1.2);
		isolateCollection( AllAntiHiggsJets, 	bJetsNotAllHiggs, 	bJetsNotAllHiggsAllAntiHiggs, 	1.2);
		isolateCollection( AllHiggsJets, 	bJets_Veto, 		bJetsNotAllHiggs_Veto, 			1.2);
		isolateCollection( AllAntiHiggsJets, 	bJetsNotAllHiggs_Veto,	bJetsNotAllHiggsAllAntiHiggs_Veto, 	1.2);

		for( JetCollection::const_iterator AK5 = bJetsNotHiggs.begin(); AK5 != bJetsNotHiggs.end(); ++AK5 ){
			HT_HiggsBJets = HT_HiggsBJets + AK5->Pt();
		}

		///// Fill evt and ABCD plots //==================================================================================================================================================	
		int A=0, Av=0;
		int B=0, Bv=0;
		int C=0, C_all=0, Cv=0;
		int D=0, D_all=0, Dv=0;

		if( HT_AK5 < HTAK5Min_ ) continue;
		h1.GetTH1("ABCDana_CutFlow")->Fill(double(3),weight_);	
		h1.GetTH1("ABCDval_CutFlow")->Fill(double(3),weight_);

		vector<TLorentzVector> p4_bprimes_A, p4_bprimes_B, p4_bprimes_C, p4_bprimes_D; 
		JetCollection HiggsJets_ABCD, HiggsSubJet1_ABCD, HiggsSubJet2_ABCD;
		JetCollection AntiHiggsJets_ABCD, AntiHiggsSubJet1_ABCD, AntiHiggsSubJet2_ABCD;

		//// Higgs region
		for( JetCollection::const_iterator H = AllHiggsJetsDRCut.begin(); H != AllHiggsJetsDRCut.end(); H++ ){
			int iSub1, iSub2;
			if( SubJetInfo.Pt[H->Jet_SubJet1Idx()] > SubJetInfo.Pt[H->Jet_SubJet2Idx()] ){
				iSub1 = H->Jet_SubJet1Idx();
				iSub2 = H->Jet_SubJet2Idx();
			}else{
				iSub1 = H->Jet_SubJet2Idx();
				iSub2 = H->Jet_SubJet1Idx();
			}
			TLorentzVector Subjet1, Subjet2;
			Subjet1.SetPtEtaPhiM(SubJetInfo.Pt[iSub1], SubJetInfo.Eta[iSub1], SubJetInfo.Phi[iSub1], SubJetInfo.Mass[iSub1]);
			Subjet2.SetPtEtaPhiM(SubJetInfo.Pt[iSub2], SubJetInfo.Eta[iSub2], SubJetInfo.Phi[iSub2], SubJetInfo.Mass[iSub2]);
			double subjet_dy = Subjet1.Rapidity() - Subjet2.Rapidity();
			double subjet_dphi = Subjet1.DeltaPhi(Subjet2);
			double subjet_dyphi = sqrt( subjet_dy*subjet_dy + subjet_dphi*subjet_dphi );

			Jet SubJet1(SubJetInfo, iSub1);
			Jet SubJet2(SubJetInfo, iSub2);

			//// B region 
			if( H->MassPruned() > HJetPrunedMassMin_ && H->MassPruned() < HJetPrunedMassMax_ ){
				if ( bJetsNotAllHiggsAllAntiHiggs.size() >= unsigned(numbJet_) ){
					B++; 
					HiggsJets_ABCD.push_back(*H);
					HiggsSubJet1_ABCD.push_back(SubJet1);
					HiggsSubJet2_ABCD.push_back(SubJet2);
					recoBprime( AK5JetInfo, bJetsNotAllHiggsAllAntiHiggs, *H, p4_bprimes_B);
					h1.GetTH1("ABCDana_HiggsMass")->Fill( H->MassPruned(), weight_);
					h1.GetTH1("ABCDana_HiggsMass_B")->Fill( H->MassPruned(), weight_);
					h1.GetTH1("ABCDana_CA8Pt")->Fill( H->Pt(), weight_);
					h1.GetTH1("ABCDana_CA8Pt_B")->Fill( H->Pt(), weight_);
					h1.GetTH1("ABCDana_dRSubJets_B")->Fill( subjet_dyphi, weight_);
					h1.GetTH1("ABCDana_Tau2ByTau1_B")->Fill( H->tau2()/H->tau1(), weight_);
					h1.GetTH1("ABCDana_Sub1Mass_B")->Fill( SubJetInfo.Mass[iSub1], weight_);
					h1.GetTH1("ABCDana_Sub2Mass_B")->Fill( SubJetInfo.Mass[iSub2], weight_);
					h1.GetTH1("ABCDana_Sub1Pt_B")->Fill( SubJetInfo.Pt[iSub1], weight_);
					h1.GetTH1("ABCDana_Sub2Pt_B")->Fill( SubJetInfo.Pt[iSub2], weight_);
					h1.GetTH1("ABCDana_Sub1CSV_B")->Fill( SubJetInfo.CombinedSVBJetTags[iSub1], weight_);
					h1.GetTH1("ABCDana_Sub2CSV_B")->Fill( SubJetInfo.CombinedSVBJetTags[iSub2], weight_);
					h2.GetTH2("ABCDana_2D")->Fill( 1., H->MassPruned(), weight_);
					/*cout<<"================================="<<endl;
					cout<<"[Alpha] PrunedMass "<<H->MassPruned()<<endl;
					cout<<"[Alpha] Pt "<<H->Pt()<<endl;
					cout<<"[Alpha] dRSubJets "<<subjet_dyphi<<endl;
					cout<<"[Alpha] Tau2ByTau1 "<<H->tau2()/H->tau1()<<endl;
					cout<<"[Alpha] Sub1Mass "<<SubJetInfo.Mass[iSub1]<<endl;
					cout<<"[Alpha] Sub2Mass "<<SubJetInfo.Mass[iSub2]<<endl;
					cout<<"[Alpha] Sub1Pt "<<SubJetInfo.Pt[iSub1]<<endl;
					cout<<"[Alpha] Sub2Pt "<<SubJetInfo.Pt[iSub2]<<endl;
					cout<<"[Alpha] Sub1CSV "<<SubJetInfo.CombinedSVBJetTags[iSub1]<<endl;
					cout<<"[Alpha] Sub2CSV "<<SubJetInfo.CombinedSVBJetTags[iSub2]<<endl;*/
				}
				if ( bJetsNotAllHiggsAllAntiHiggs_Veto.size() == 0 ){ //b-Veto
					Bv++; 
					recoBprime( AK5JetInfo, bJetsNotAllHiggsAllAntiHiggs_Veto, *H, p4_bprimes_B);
					h1.GetTH1("ABCDval_HiggsMass")->Fill( H->MassPruned(), weight_);
					h1.GetTH1("ABCDval_HiggsMass_B")->Fill( H->MassPruned(), weight_);
					h1.GetTH1("ABCDval_CA8Pt")->Fill( H->Pt(), weight_);
					h1.GetTH1("ABCDval_CA8Pt_B")->Fill( H->Pt(), weight_);
					h1.GetTH1("ABCDval_dRSubJets_B")->Fill( subjet_dyphi, weight_);
					h1.GetTH1("ABCDval_Tau2ByTau1_B")->Fill( H->tau2()/H->tau1(), weight_);
					h1.GetTH1("ABCDval_Sub1Mass_B")->Fill( SubJetInfo.Mass[iSub1], weight_);
					h1.GetTH1("ABCDval_Sub2Mass_B")->Fill( SubJetInfo.Mass[iSub2], weight_);
					h1.GetTH1("ABCDval_Sub1Pt_B")->Fill( SubJetInfo.Pt[iSub1], weight_);
					h1.GetTH1("ABCDval_Sub2Pt_B")->Fill( SubJetInfo.Pt[iSub2], weight_);
					h1.GetTH1("ABCDval_Sub1CSV_B")->Fill( SubJetInfo.CombinedSVBJetTags[iSub1], weight_);
					h1.GetTH1("ABCDval_Sub2CSV_B")->Fill( SubJetInfo.CombinedSVBJetTags[iSub2], weight_);
					h2.GetTH2("ABCDval_2D")->Fill( 1., H->MassPruned(), weight_);
				}
			}
			//// D region 
			if( H->MassPruned() <= HJetPrunedMassMin_ || H->MassPruned() >= HJetPrunedMassMax_ ){
				if ( bJetsNotAllHiggsAllAntiHiggs.size() >= unsigned(numbJet_) ){
					if( H->MassPruned() <= HJetSBMassMax_ && H->MassPruned() > HJetSBMassMin_ ){ 
						D++; 
						HiggsJets_ABCD.push_back(*H);
						HiggsSubJet1_ABCD.push_back(SubJet1);
						HiggsSubJet2_ABCD.push_back(SubJet2);
						recoBprime( AK5JetInfo, bJetsNotAllHiggsAllAntiHiggs, *H, p4_bprimes_D);
					}
					D_all++; 
					h1.GetTH1("ABCDana_HiggsMass")->Fill( H->MassPruned(), weight_);
					h1.GetTH1("ABCDana_HiggsMass_D")->Fill( H->MassPruned(), weight_);
					h1.GetTH1("ABCDana_CA8Pt")->Fill( H->Pt(), weight_);
					h1.GetTH1("ABCDana_CA8Pt_D")->Fill( H->Pt(), weight_);
					h1.GetTH1("ABCDana_dRSubJets_D")->Fill( subjet_dyphi, weight_);
					h1.GetTH1("ABCDana_Tau2ByTau1_D")->Fill( H->tau2()/H->tau1(), weight_);
					h1.GetTH1("ABCDana_Sub1Mass_D")->Fill( SubJetInfo.Mass[iSub1], weight_);
					h1.GetTH1("ABCDana_Sub2Mass_D")->Fill( SubJetInfo.Mass[iSub2], weight_);
					h1.GetTH1("ABCDana_Sub1Pt_D")->Fill( SubJetInfo.Pt[iSub1], weight_);
					h1.GetTH1("ABCDana_Sub2Pt_D")->Fill( SubJetInfo.Pt[iSub2], weight_);
					h1.GetTH1("ABCDana_Sub1CSV_D")->Fill( SubJetInfo.CombinedSVBJetTags[iSub1], weight_);
					h1.GetTH1("ABCDana_Sub2CSV_D")->Fill( SubJetInfo.CombinedSVBJetTags[iSub2], weight_);
					h2.GetTH2("ABCDana_2D")->Fill( 1., H->MassPruned(), weight_);
				}
				if ( bJetsNotAllHiggsAllAntiHiggs_Veto.size() == 0 ){ //b-Veto
					if( H->MassPruned() <= HJetSBMassMax_ && H->MassPruned() > HJetSBMassMin_ ){ 
						Dv++; 
					} 
					h1.GetTH1("ABCDval_HiggsMass")->Fill( H->MassPruned(), weight_);
					h1.GetTH1("ABCDval_HiggsMass_D")->Fill( H->MassPruned(), weight_);
					h1.GetTH1("ABCDval_CA8Pt")->Fill( H->Pt(), weight_);
					h1.GetTH1("ABCDval_CA8Pt_D")->Fill( H->Pt(), weight_);
					h1.GetTH1("ABCDval_dRSubJets_D")->Fill( subjet_dyphi, weight_);
					h1.GetTH1("ABCDval_Tau2ByTau1_D")->Fill( H->tau2()/H->tau1(), weight_);
					h1.GetTH1("ABCDval_Sub1Mass_D")->Fill( SubJetInfo.Mass[iSub1], weight_);
					h1.GetTH1("ABCDval_Sub2Mass_D")->Fill( SubJetInfo.Mass[iSub2], weight_);
					h1.GetTH1("ABCDval_Sub1Pt_D")->Fill( SubJetInfo.Pt[iSub1], weight_);
					h1.GetTH1("ABCDval_Sub2Pt_D")->Fill( SubJetInfo.Pt[iSub2], weight_);
					h1.GetTH1("ABCDval_Sub1CSV_D")->Fill( SubJetInfo.CombinedSVBJetTags[iSub1], weight_);
					h1.GetTH1("ABCDval_Sub2CSV_D")->Fill( SubJetInfo.CombinedSVBJetTags[iSub2], weight_);
					h2.GetTH2("ABCDval_2D")->Fill( 1., H->MassPruned(), weight_);
				}
			}
		}

		//// AntiHiggs region 
		for( JetCollection::const_iterator H = AllAntiHiggsJetsDRCut.begin(); H != AllAntiHiggsJetsDRCut.end(); H++ ){
			int iSub1, iSub2;
			if( SubJetInfo.Pt[H->Jet_SubJet1Idx()] > SubJetInfo.Pt[H->Jet_SubJet2Idx()] ){
				iSub1 = H->Jet_SubJet1Idx();
				iSub2 = H->Jet_SubJet2Idx();
			}else{
				iSub1 = H->Jet_SubJet2Idx();
				iSub2 = H->Jet_SubJet1Idx();
			}
			TLorentzVector Subjet1, Subjet2;
			Subjet1.SetPtEtaPhiM(SubJetInfo.Pt[iSub1], SubJetInfo.Eta[iSub1], SubJetInfo.Phi[iSub1], SubJetInfo.Mass[iSub1]);
			Subjet2.SetPtEtaPhiM(SubJetInfo.Pt[iSub2], SubJetInfo.Eta[iSub2], SubJetInfo.Phi[iSub2], SubJetInfo.Mass[iSub2]);
			double subjet_dy = Subjet1.Rapidity() - Subjet2.Rapidity();
			double subjet_dphi = Subjet1.DeltaPhi(Subjet2);
			double subjet_dyphi = sqrt( subjet_dy*subjet_dy + subjet_dphi*subjet_dphi );

			Jet SubJet1(SubJetInfo, iSub1);
			Jet SubJet2(SubJetInfo, iSub2);

			//// A region	
			if( H->MassPruned() > HJetPrunedMassMin_ && H->MassPruned() < HJetPrunedMassMax_ ){
				if ( bJetsNotAllHiggsAllAntiHiggs.size() >= unsigned(numbJet_) ){
					A++;
					AntiHiggsJets_ABCD.push_back(*H); 
					AntiHiggsSubJet1_ABCD.push_back(SubJet1);
					AntiHiggsSubJet2_ABCD.push_back(SubJet2);
					recoBprime( AK5JetInfo, bJetsNotAllHiggsAllAntiHiggs, *H, p4_bprimes_A);
					h1.GetTH1("ABCDana_HiggsMass")->Fill( H->MassPruned(), weight_);
					h1.GetTH1("ABCDana_HiggsMass_A")->Fill( H->MassPruned(), weight_);
					h1.GetTH1("ABCDana_CA8Pt")->Fill( H->Pt(), weight_);
					h1.GetTH1("ABCDana_CA8Pt_A")->Fill( H->Pt(), weight_);
					h1.GetTH1("ABCDana_dRSubJets_A")->Fill( subjet_dyphi, weight_);
					h1.GetTH1("ABCDana_Tau2ByTau1_A")->Fill( H->tau2()/H->tau1(), weight_);
					h1.GetTH1("ABCDana_Sub1Mass_A")->Fill( SubJetInfo.Mass[iSub1], weight_);
					h1.GetTH1("ABCDana_Sub2Mass_A")->Fill( SubJetInfo.Mass[iSub2], weight_);
					h1.GetTH1("ABCDana_Sub1Pt_A")->Fill( SubJetInfo.Pt[iSub1], weight_);
					h1.GetTH1("ABCDana_Sub2Pt_A")->Fill( SubJetInfo.Pt[iSub2], weight_);
					h1.GetTH1("ABCDana_Sub1CSV_A")->Fill( SubJetInfo.CombinedSVBJetTags[iSub1], weight_);
					h1.GetTH1("ABCDana_Sub2CSV_A")->Fill( SubJetInfo.CombinedSVBJetTags[iSub2], weight_);
					h2.GetTH2("ABCDana_2D")->Fill( 0., H->MassPruned(), weight_);
				}
				if ( bJetsNotAllHiggsAllAntiHiggs_Veto.size() == 0 ){
					Av++; 
					h1.GetTH1("ABCDval_HiggsMass")->Fill( H->MassPruned(), weight_);
					h1.GetTH1("ABCDval_HiggsMass_A")->Fill( H->MassPruned(), weight_);
					h1.GetTH1("ABCDval_CA8Pt")->Fill( H->Pt(), weight_);
					h1.GetTH1("ABCDval_CA8Pt_A")->Fill( H->Pt(), weight_);
					h1.GetTH1("ABCDval_dRSubJets_A")->Fill( subjet_dyphi, weight_);
					h1.GetTH1("ABCDval_Tau2ByTau1_A")->Fill( H->tau2()/H->tau1(), weight_);
					h1.GetTH1("ABCDval_Sub1Mass_A")->Fill( SubJetInfo.Mass[iSub1], weight_);
					h1.GetTH1("ABCDval_Sub2Mass_A")->Fill( SubJetInfo.Mass[iSub2], weight_);
					h1.GetTH1("ABCDval_Sub1Pt_A")->Fill( SubJetInfo.Pt[iSub1], weight_);
					h1.GetTH1("ABCDval_Sub2Pt_A")->Fill( SubJetInfo.Pt[iSub2], weight_);
					h1.GetTH1("ABCDval_Sub1CSV_A")->Fill( SubJetInfo.CombinedSVBJetTags[iSub1], weight_);
					h1.GetTH1("ABCDval_Sub2CSV_A")->Fill( SubJetInfo.CombinedSVBJetTags[iSub2], weight_);
					h2.GetTH2("ABCDval_2D")->Fill( 0., H->MassPruned(), weight_);
				}
			}
			//// C region
			if( H->MassPruned() <= HJetPrunedMassMin_ || H->MassPruned() >= HJetPrunedMassMax_ ){
				if ( bJetsNotAllHiggsAllAntiHiggs.size() >= unsigned(numbJet_) ){
					if( H->MassPruned() <= HJetSBMassMax_ && H->MassPruned() > HJetSBMassMin_ ){ 
						C++; 
						AntiHiggsJets_ABCD.push_back(*H); 
						AntiHiggsSubJet1_ABCD.push_back(SubJet1);
						AntiHiggsSubJet2_ABCD.push_back(SubJet2);
						recoBprime( AK5JetInfo, bJetsNotAllHiggsAllAntiHiggs, *H, p4_bprimes_C);
					} 
					C_all++; 
					h1.GetTH1("ABCDana_HiggsMass")->Fill( H->MassPruned(), weight_);
					h1.GetTH1("ABCDana_HiggsMass_C")->Fill( H->MassPruned(), weight_);
					h1.GetTH1("ABCDana_CA8Pt")->Fill( H->Pt(), weight_);
					h1.GetTH1("ABCDana_CA8Pt_C")->Fill( H->Pt(), weight_);
					h1.GetTH1("ABCDana_dRSubJets_C")->Fill( subjet_dyphi, weight_);
					h1.GetTH1("ABCDana_Tau2ByTau1_C")->Fill( H->tau2()/H->tau1(), weight_);
					h1.GetTH1("ABCDana_Sub1Mass_C")->Fill( SubJetInfo.Mass[iSub1], weight_);
					h1.GetTH1("ABCDana_Sub2Mass_C")->Fill( SubJetInfo.Mass[iSub2], weight_);
					h1.GetTH1("ABCDana_Sub1Pt_C")->Fill( SubJetInfo.Pt[iSub1], weight_);
					h1.GetTH1("ABCDana_Sub2Pt_C")->Fill( SubJetInfo.Pt[iSub2], weight_);
					h1.GetTH1("ABCDana_Sub1CSV_C")->Fill( SubJetInfo.CombinedSVBJetTags[iSub1], weight_);
					h1.GetTH1("ABCDana_Sub2CSV_C")->Fill( SubJetInfo.CombinedSVBJetTags[iSub2], weight_);
					h2.GetTH2("ABCDana_2D")->Fill( 0., H->MassPruned(), weight_);
				}
				if ( bJetsNotAllHiggsAllAntiHiggs_Veto.size() == 0){ // b-Veto
					if( H->MassPruned() <= HJetSBMassMax_ && H->MassPruned() > HJetSBMassMin_ ){ 
						Cv++; 
					} 
					h1.GetTH1("ABCDval_HiggsMass")->Fill( H->MassPruned(), weight_);
					h1.GetTH1("ABCDval_HiggsMass_C")->Fill( H->MassPruned(), weight_);
					h1.GetTH1("ABCDval_CA8Pt")->Fill( H->Pt(), weight_);
					h1.GetTH1("ABCDval_CA8Pt_C")->Fill( H->Pt(), weight_);
					h1.GetTH1("ABCDval_dRSubJets_C")->Fill( subjet_dyphi, weight_);
					h1.GetTH1("ABCDval_Tau2ByTau1_C")->Fill( H->tau2()/H->tau1(), weight_);
					h1.GetTH1("ABCDval_Sub1Mass_C")->Fill( SubJetInfo.Mass[iSub1], weight_);
					h1.GetTH1("ABCDval_Sub2Mass_C")->Fill( SubJetInfo.Mass[iSub2], weight_);
					h1.GetTH1("ABCDval_Sub1Pt_C")->Fill( SubJetInfo.Pt[iSub1], weight_);
					h1.GetTH1("ABCDval_Sub2Pt_C")->Fill( SubJetInfo.Pt[iSub2], weight_);
					h1.GetTH1("ABCDval_Sub1CSV_C")->Fill( SubJetInfo.CombinedSVBJetTags[iSub1], weight_);
					h1.GetTH1("ABCDval_Sub2CSV_C")->Fill( SubJetInfo.CombinedSVBJetTags[iSub2], weight_);
					h2.GetTH2("ABCDval_2D")->Fill( 0., H->MassPruned(), weight_);
				}
			}
			///////===================================================================================
		}

		h1.GetTH1("ABCDana_NumCA8")->Fill(AllHiggsJets.size()+AllAntiHiggsJets.size());
		h1.GetTH1("ABCDana_Numbjet")->Fill(bJetsNotAllHiggsAllAntiHiggs.size());
		if( A+B+C+D > 0){ 
			h1.GetTH1("ABCDana_Numbjet_ABCD")->Fill(bJetsNotAllHiggsAllAntiHiggs.size());
			h1.GetTH1("ABCDana_NumCA8_ABCD")->Fill(A+B+C+D);
		}

		if( B > 0 ){
			sumw2_b += w2_;
			h1.GetTH1("ABCDana_CutRegion")->Fill("B", weight_); evtPass_ana++;
			h1.GetTH1("ABCDana_HT_B")->Fill( HT_AK5, weight_);
			h1.GetTH1("ABCDana_HT")->Fill( HT_AK5, weight_);
			h1.GetTH1("ABCDana_NumCA8_B")->Fill(B);
			h1.GetTH1("ABCDana_Numbjet_B")->Fill(bJetsNotAllHiggsAllAntiHiggs.size());
			for( vector<TLorentzVector>::const_iterator bp_ = p4_bprimes_B.begin(); bp_ != p4_bprimes_B.end(); bp_++ ){
				h1.GetTH1("ABCDana_bpMass_B")->Fill( bp_->M(), weight_);
				h1.GetTH1("ABCDana_bpPt_B")->Fill( bp_->Pt(), weight_);
				h1.GetTH1("ABCDana_bpEta_B")->Fill( bp_->Eta(), weight_);
			}
			if( bJetsNotAllHiggsAllAntiHiggs.size() == 1 ){
				sumw2_b_1b += w2_;
				h1.GetTH1("ABCDana_CutRegion_1b")->Fill("B", weight_); 
				h1.GetTH1("ABCDana_1b_HT_B")->Fill( HT_AK5, weight_);
				for( vector<TLorentzVector>::const_iterator bp_ = p4_bprimes_B.begin(); bp_ != p4_bprimes_B.end(); bp_++ ){
					h1.GetTH1("ABCDana_1b_bpMass_B")->Fill( bp_->M(), weight_);
					h1.GetTH1("ABCDana_1b_bpPt_B")->Fill( bp_->Pt(), weight_);
					h1.GetTH1("ABCDana_1b_bpEta_B")->Fill( bp_->Eta(), weight_);
				}
			}else if( bJetsNotAllHiggsAllAntiHiggs.size()>= 2 ){
				sumw2_b_2b += w2_;
				h1.GetTH1("ABCDana_CutRegion_2b")->Fill("B", weight_); 
				h1.GetTH1("ABCDana_2b_HT_B")->Fill( HT_AK5, weight_);
				for( vector<TLorentzVector>::const_iterator bp_ = p4_bprimes_B.begin(); bp_ != p4_bprimes_B.end(); bp_++ ){
					h1.GetTH1("ABCDana_2b_bpMass_B")->Fill( bp_->M(), weight_);
					h1.GetTH1("ABCDana_2b_bpPt_B")->Fill( bp_->Pt(), weight_);
					h1.GetTH1("ABCDana_2b_bpEta_B")->Fill( bp_->Eta(), weight_);
				}
			}	
		}else if( D > 0 ){ 
			sumw2_d += w2_;
			h1.GetTH1("ABCDana_CutRegion")->Fill("D", weight_);
			h1.GetTH1("ABCDana_HT_D")->Fill( HT_AK5, weight_);
			h1.GetTH1("ABCDana_HT")->Fill( HT_AK5, weight_);
			h1.GetTH1("ABCDana_NumCA8_D")->Fill(D);
			h1.GetTH1("ABCDana_Numbjet_D")->Fill(bJetsNotAllHiggsAllAntiHiggs.size());
			for( vector<TLorentzVector>::const_iterator bp_ = p4_bprimes_D.begin(); bp_ != p4_bprimes_D.end(); bp_++ ){
				h1.GetTH1("ABCDana_bpMass_D")->Fill( bp_->M(), weight_);
				h1.GetTH1("ABCDana_bpPt_D")->Fill( bp_->Pt(), weight_);
				h1.GetTH1("ABCDana_bpEta_D")->Fill( bp_->Eta(), weight_);
			}
			if( bJetsNotAllHiggsAllAntiHiggs.size() == 1 ){
				sumw2_d_1b += w2_;
				h1.GetTH1("ABCDana_CutRegion_1b")->Fill("D", weight_); 
				h1.GetTH1("ABCDana_1b_HT_D")->Fill( HT_AK5, weight_);
				for( vector<TLorentzVector>::const_iterator bp_ = p4_bprimes_D.begin(); bp_ != p4_bprimes_D.end(); bp_++ ){
					h1.GetTH1("ABCDana_1b_bpMass_D")->Fill( bp_->M(), weight_);
					h1.GetTH1("ABCDana_1b_bpPt_D")->Fill( bp_->Pt(), weight_);
					h1.GetTH1("ABCDana_1b_bpEta_D")->Fill( bp_->Eta(), weight_);
				}
			}else if( bJetsNotAllHiggsAllAntiHiggs.size()>= 2 ){
				sumw2_d_2b += w2_;
				h1.GetTH1("ABCDana_CutRegion_2b")->Fill("D", weight_); 
				h1.GetTH1("ABCDana_2b_HT_D")->Fill( HT_AK5, weight_);
				for( vector<TLorentzVector>::const_iterator bp_ = p4_bprimes_D.begin(); bp_ != p4_bprimes_D.end(); bp_++ ){
					h1.GetTH1("ABCDana_2b_bpMass_D")->Fill( bp_->M(), weight_);
					h1.GetTH1("ABCDana_2b_bpPt_D")->Fill( bp_->Pt(), weight_);
					h1.GetTH1("ABCDana_2b_bpEta_D")->Fill( bp_->Eta(), weight_);
				}
			}	
		}else if( A > 0 ){
			sumw2_a += w2_;
			h1.GetTH1("ABCDana_CutRegion")->Fill("A", weight_);
			h1.GetTH1("ABCDana_HT_A")->Fill( HT_AK5, weight_);
			h1.GetTH1("ABCDana_HT")->Fill( HT_AK5, weight_);
			h1.GetTH1("ABCDana_NumCA8_A")->Fill(A);
			h1.GetTH1("ABCDana_Numbjet_A")->Fill(bJetsNotAllHiggsAllAntiHiggs.size());
			for( vector<TLorentzVector>::const_iterator bp_ = p4_bprimes_A.begin(); bp_ != p4_bprimes_A.end(); bp_++ ){
				h1.GetTH1("ABCDana_bpMass_A")->Fill( bp_->M(), weight_);
				h1.GetTH1("ABCDana_bpPt_A")->Fill( bp_->Pt(), weight_);
				h1.GetTH1("ABCDana_bpEta_A")->Fill( bp_->Eta(), weight_);
			}
			if( bJetsNotAllHiggsAllAntiHiggs.size() == 1 ){
				sumw2_a_1b += w2_;
				h1.GetTH1("ABCDana_CutRegion_1b")->Fill("A", weight_); 
				h1.GetTH1("ABCDana_1b_HT_A")->Fill( HT_AK5, weight_);
				for( vector<TLorentzVector>::const_iterator bp_ = p4_bprimes_A.begin(); bp_ != p4_bprimes_A.end(); bp_++ ){
					h1.GetTH1("ABCDana_1b_bpMass_A")->Fill( bp_->M(), weight_);
					h1.GetTH1("ABCDana_1b_bpPt_A")->Fill( bp_->Pt(), weight_);
					h1.GetTH1("ABCDana_1b_bpEta_A")->Fill( bp_->Eta(), weight_);
				}
			}else if( bJetsNotAllHiggsAllAntiHiggs.size()>= 2 ){
				sumw2_a_2b += w2_;
				h1.GetTH1("ABCDana_CutRegion_2b")->Fill("A", weight_); 
				h1.GetTH1("ABCDana_2b_HT_A")->Fill( HT_AK5, weight_);
				for( vector<TLorentzVector>::const_iterator bp_ = p4_bprimes_A.begin(); bp_ != p4_bprimes_A.end(); bp_++ ){
					h1.GetTH1("ABCDana_2b_bpMass_A")->Fill( bp_->M(), weight_);
					h1.GetTH1("ABCDana_2b_bpPt_A")->Fill( bp_->Pt(), weight_);
					h1.GetTH1("ABCDana_2b_bpEta_A")->Fill( bp_->Eta(), weight_);
				}
			}	
		}else if( C > 0 ){
			sumw2_c += w2_;
			h1.GetTH1("ABCDana_CutRegion")->Fill("C", weight_);
			h1.GetTH1("ABCDana_HT_C")->Fill( HT_AK5, weight_);
			h1.GetTH1("ABCDana_HT")->Fill( HT_AK5, weight_);
			h1.GetTH1("ABCDana_NumCA8_C")->Fill(C);
			h1.GetTH1("ABCDana_Numbjet_C")->Fill(bJetsNotAllHiggsAllAntiHiggs.size());
			for( vector<TLorentzVector>::const_iterator bp_ = p4_bprimes_C.begin(); bp_ != p4_bprimes_C.end(); bp_++ ){
				h1.GetTH1("ABCDana_bpMass_C")->Fill( bp_->M(), weight_);
				h1.GetTH1("ABCDana_bpPt_C")->Fill( bp_->Pt(), weight_);
				h1.GetTH1("ABCDana_bpEta_C")->Fill( bp_->Eta(), weight_);
			}
			if( bJetsNotAllHiggsAllAntiHiggs.size() == 1 ){
				sumw2_c_1b += w2_;
				h1.GetTH1("ABCDana_CutRegion_1b")->Fill("C", weight_); 
				h1.GetTH1("ABCDana_1b_HT_C")->Fill( HT_AK5, weight_);
				for( vector<TLorentzVector>::const_iterator bp_ = p4_bprimes_C.begin(); bp_ != p4_bprimes_C.end(); bp_++ ){
					h1.GetTH1("ABCDana_1b_bpMass_C")->Fill( bp_->M(), weight_);
					h1.GetTH1("ABCDana_1b_bpPt_C")->Fill( bp_->Pt(), weight_);
					h1.GetTH1("ABCDana_1b_bpEta_C")->Fill( bp_->Eta(), weight_);
				}
			}else if( bJetsNotAllHiggsAllAntiHiggs.size()>= 2 ){
				sumw2_c_2b += w2_;
				h1.GetTH1("ABCDana_CutRegion_2b")->Fill("C", weight_); 
				h1.GetTH1("ABCDana_2b_HT_C")->Fill( HT_AK5, weight_);
				for( vector<TLorentzVector>::const_iterator bp_ = p4_bprimes_C.begin(); bp_ != p4_bprimes_C.end(); bp_++ ){
					h1.GetTH1("ABCDana_2b_bpMass_C")->Fill( bp_->M(), weight_);
					h1.GetTH1("ABCDana_2b_bpPt_C")->Fill( bp_->Pt(), weight_);
					h1.GetTH1("ABCDana_2b_bpEta_C")->Fill( bp_->Eta(), weight_);
				}
			}	
		}

		if( Bv > 0 ){
			h1.GetTH1("ABCDval_CutRegion")->Fill("B", weight_); evtPass_val++;
			h1.GetTH1("ABCDval_HT_B")->Fill( HT_AK5, weight_);
			h1.GetTH1("ABCDval_HT")->Fill( HT_AK5, weight_);
			h1.GetTH1("ABCDval_NumCA8_B")->Fill(Bv);
			sumw2_bv += w2_;
		}else if( Dv > 0 ){ 
			h1.GetTH1("ABCDval_CutRegion")->Fill("D", weight_);
			h1.GetTH1("ABCDval_HT_D")->Fill( HT_AK5, weight_);
			h1.GetTH1("ABCDval_HT")->Fill( HT_AK5, weight_);
			h1.GetTH1("ABCDval_NumCA8_D")->Fill(Dv);
			sumw2_dv += w2_;
		}else if( Av > 0 ){
			h1.GetTH1("ABCDval_CutRegion")->Fill("A", weight_);
			h1.GetTH1("ABCDval_HT_A")->Fill( HT_AK5, weight_);
			h1.GetTH1("ABCDval_HT")->Fill( HT_AK5, weight_);
			h1.GetTH1("ABCDval_NumCA8_A")->Fill(Av);
			sumw2_av += w2_;
		}else if( Cv > 0 ){
			h1.GetTH1("ABCDval_CutRegion")->Fill("C", weight_);
			h1.GetTH1("ABCDval_HT_C")->Fill( HT_AK5, weight_);
			h1.GetTH1("ABCDval_HT")->Fill( HT_AK5, weight_);
			h1.GetTH1("ABCDval_NumCA8_C")->Fill(Cv);
			sumw2_cv += w2_;
		}

		if( B  != 0 ) h1.GetTH1("ABCDana_CutFlow")->Fill(double(4), weight_);
		if( Bv != 0 ) h1.GetTH1("ABCDval_CutFlow")->Fill(double(4), weight_);

		h1.GetTH1("ABCDana_Sumw2_A")->Fill( 0., sumw2_a);
		h1.GetTH1("ABCDana_Sumw2_B")->Fill( 0., sumw2_b);
		h1.GetTH1("ABCDana_Sumw2_C")->Fill( 0., sumw2_c);
		h1.GetTH1("ABCDana_Sumw2_D")->Fill( 0., sumw2_d);
		h1.GetTH1("ABCDana_Sumw2_1b_A")->Fill( 0., sumw2_a_1b);
		h1.GetTH1("ABCDana_Sumw2_1b_B")->Fill( 0., sumw2_b_1b);
		h1.GetTH1("ABCDana_Sumw2_1b_C")->Fill( 0., sumw2_c_1b);
		h1.GetTH1("ABCDana_Sumw2_1b_D")->Fill( 0., sumw2_d_1b);
		h1.GetTH1("ABCDana_Sumw2_2b_A")->Fill( 0., sumw2_a_2b);
		h1.GetTH1("ABCDana_Sumw2_2b_B")->Fill( 0., sumw2_b_2b);
		h1.GetTH1("ABCDana_Sumw2_2b_C")->Fill( 0., sumw2_c_2b);
		h1.GetTH1("ABCDana_Sumw2_2b_D")->Fill( 0., sumw2_d_2b);
		h1.GetTH1("ABCDval_Sumw2_A")->Fill( 0., sumw2_av);
		h1.GetTH1("ABCDval_Sumw2_B")->Fill( 0., sumw2_bv);
		h1.GetTH1("ABCDval_Sumw2_C")->Fill( 0., sumw2_cv);
		h1.GetTH1("ABCDval_Sumw2_D")->Fill( 0., sumw2_dv);
		//// Store new tree, new branch with Jet correction  ====================================================================================================
	} //// entry loop 

	fout.close(); 

}

// ------------ method called once each job just after ending the event loop  ------------
void BackgroundEstimationABCD::endJob(){
	std::cout<<std::endl;	
	std::cout<<"evtPass_ana "<<evtPass_ana<<"/"<<maxEvents_<<std::endl;	
	std::cout<<"evtPass_val "<<evtPass_val<<"/"<<maxEvents_<<std::endl;	
}

// ------------ method fills 'descriptions' with the allowed parameters for the module  ------------
void BackgroundEstimationABCD::fillDescriptions(edm::ConfigurationDescriptions& descriptions){
	//The following says we do not know what parameters are allowed so do no validation
	// Please change this to state exactly what you do use, even if it is no parameters
	edm::ParameterSetDescription desc;
	desc.setUnknown();
	descriptions.addDefault(desc);
}

//define this as a plug-in
DEFINE_FWK_MODULE(BackgroundEstimationABCD);
