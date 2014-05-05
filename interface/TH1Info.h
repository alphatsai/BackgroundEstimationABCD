#ifndef TH1INFO_H
#define TH1INFO_H

/////// Set Struct of All variables(TH1F) //////====================================================================================
enum th1flist_{
	ABCDana_CutFlow_, 		//01-13
	ABCDval_CutFlow_, 		//01-13

	ABCDana_CutRegion_, 		//01-13
	ABCDana_CutRegion_1b, 		//01-13
	ABCDana_CutRegion_2b, 		//01-13
	ABCDval_CutRegion_, 		//01-13

	ABCDana_Sumw2_A,
	ABCDana_Sumw2_B,
	ABCDana_Sumw2_C,
	ABCDana_Sumw2_D,
	ABCDana_Sumw2_A_1b,
	ABCDana_Sumw2_B_1b,
	ABCDana_Sumw2_C_1b,
	ABCDana_Sumw2_D_1b,
	ABCDana_Sumw2_A_2b,
	ABCDana_Sumw2_B_2b,
	ABCDana_Sumw2_C_2b,
	ABCDana_Sumw2_D_2b,
	ABCDval_Sumw2_A,
	ABCDval_Sumw2_B,
	ABCDval_Sumw2_C,
	ABCDval_Sumw2_D,

	ABCDana_Numbjet,
	ABCDana_Numbjet_ABCD,
	ABCDana_Numbjet_A,
	ABCDana_Numbjet_B,
	ABCDana_Numbjet_C,
	ABCDana_Numbjet_D,
	ABCDana_NumCA8,
	ABCDana_NumCA8_ABCD,
	ABCDana_NumCA8_A,
	ABCDana_NumCA8_B,
	ABCDana_NumCA8_C,
	ABCDana_NumCA8_D,
	ABCDana_bpMass_A,
	ABCDana_bpMass_B,
	ABCDana_bpMass_C,
	ABCDana_bpMass_D,
	ABCDana_bpPt_A,
	ABCDana_bpPt_B,
	ABCDana_bpPt_C,
	ABCDana_bpPt_D,
	ABCDana_bpEta_A,
	ABCDana_bpEta_B,
	ABCDana_bpEta_C,
	ABCDana_bpEta_D,
	ABCDana_HT_,  		//10-21
	ABCDana_HT_A,  		//10-21
	ABCDana_HT_B,  		//10-21
	ABCDana_HT_C,  		//10-21
	ABCDana_HT_D,  		//10-21
	ABCDana_HiggsMass_A,  		//10-21
	ABCDana_HiggsMass_B,  		//10-21
	ABCDana_HiggsMass_C,  		//10-21
	ABCDana_HiggsMass_D,  		//10-21
	ABCDana_CA8Pt_A, 	//10-21
	ABCDana_CA8Pt_B, 	//10-21
	ABCDana_CA8Pt_C, 	//10-21
	ABCDana_CA8Pt_D, 	//10-21
	ABCDana_CA8PrMass_A, 	//10-21
	ABCDana_CA8PrMass_B, 	//10-21
	ABCDana_CA8PrMass_C, 	//10-21
	ABCDana_CA8PrMass_D, 	//10-21
	ABCDana_dRSubJets_A, 	//10-21
	ABCDana_dRSubJets_B, 	//10-21
	ABCDana_dRSubJets_C, 	//10-21
	ABCDana_dRSubJets_D, 	//10-21
	ABCDana_Tau2ByTau1_A, 	//10-21
	ABCDana_Tau2ByTau1_B, 	//10-21
	ABCDana_Tau2ByTau1_C, 	//10-21
	ABCDana_Tau2ByTau1_D, 	//10-21
	ABCDana_Sub1Pt_A, 	//10-21
	ABCDana_Sub1Pt_B, 	//10-21
	ABCDana_Sub1Pt_C, 	//10-21
	ABCDana_Sub1Pt_D, 	//10-21
	ABCDana_Sub2Pt_A, 	//10-21
	ABCDana_Sub2Pt_B, 	//10-21
	ABCDana_Sub2Pt_C, 	//10-21
	ABCDana_Sub2Pt_D, 	//10-21
	ABCDana_Sub1Mass_A, 	//10-21
	ABCDana_Sub1Mass_B, 	//10-21
	ABCDana_Sub1Mass_C, 	//10-21
	ABCDana_Sub1Mass_D, 	//10-21
	ABCDana_Sub2Mass_A, 	//10-21
	ABCDana_Sub2Mass_B, 	//10-21
	ABCDana_Sub2Mass_C, 	//10-21
	ABCDana_Sub2Mass_D, 	//10-21
	ABCDana_Sub1CSV_A, 	//10-21
	ABCDana_Sub1CSV_B, 	//10-21
	ABCDana_Sub1CSV_C, 	//10-21
	ABCDana_Sub1CSV_D, 	//10-21
	ABCDana_Sub2CSV_A, 	//10-21
	ABCDana_Sub2CSV_B, 	//10-21
	ABCDana_Sub2CSV_C, 	//10-21
	ABCDana_Sub2CSV_D, 	//10-21
	ABCDana_JetFlavor_A,  		//10-21
	ABCDana_JetFlavor_B,  		//10-21
	ABCDana_JetFlavor_C,  		//10-21
	ABCDana_JetFlavor_D,  		//10-21
	ABCDana_HiggsMass_,  		//10-21
	ABCDana_JetFlavor_,  		//10-21
	ABCDana_LeadCA8_Pt_,  		//10-21

	ABCDana_1b_bpMass_A,
	ABCDana_1b_bpMass_B,
	ABCDana_1b_bpMass_C,
	ABCDana_1b_bpMass_D,
	ABCDana_1b_bpPt_A,
	ABCDana_1b_bpPt_B,
	ABCDana_1b_bpPt_C,
	ABCDana_1b_bpPt_D,
	ABCDana_1b_bpEta_A,
	ABCDana_1b_bpEta_B,
	ABCDana_1b_bpEta_C,
	ABCDana_1b_bpEta_D,
	ABCDana_1b_HT_A,  		//10-21
	ABCDana_1b_HT_B,  		//10-21
	ABCDana_1b_HT_C,  		//10-21
	ABCDana_1b_HT_D,  		//10-21
	ABCDana_2b_bpMass_A,
	ABCDana_2b_bpMass_B,
	ABCDana_2b_bpMass_C,
	ABCDana_2b_bpMass_D,
	ABCDana_2b_bpPt_A,
	ABCDana_2b_bpPt_B,
	ABCDana_2b_bpPt_C,
	ABCDana_2b_bpPt_D,
	ABCDana_2b_bpEta_A,
	ABCDana_2b_bpEta_B,
	ABCDana_2b_bpEta_C,
	ABCDana_2b_bpEta_D,
	ABCDana_2b_HT_A,  		//10-21
	ABCDana_2b_HT_B,  		//10-21
	ABCDana_2b_HT_C,  		//10-21
	ABCDana_2b_HT_D,  		//10-21

	ABCDval_NumCA8_A,
	ABCDval_NumCA8_B,
	ABCDval_NumCA8_C,
	ABCDval_NumCA8_D,
	ABCDval_HT_,  		//10-21
	ABCDval_HT_A,  		//10-21
	ABCDval_HT_B,  		//10-21
	ABCDval_HT_C,  		//10-21
	ABCDval_HT_D,  		//10-21
	ABCDval_HiggsMass_A,  		//10-21
	ABCDval_HiggsMass_B,  		//10-21
	ABCDval_HiggsMass_C,  		//10-21
	ABCDval_HiggsMass_D,  		//10-21
	ABCDval_CA8Pt_A, 	//10-21
	ABCDval_CA8Pt_B, 	//10-21
	ABCDval_CA8Pt_C, 	//10-21
	ABCDval_CA8Pt_D, 	//10-21
	ABCDval_CA8PrMass_A, 	//10-21
	ABCDval_CA8PrMass_B, 	//10-21
	ABCDval_CA8PrMass_C, 	//10-21
	ABCDval_CA8PrMass_D, 	//10-21
	ABCDval_dRSubJets_A, 	//10-21
	ABCDval_dRSubJets_B, 	//10-21
	ABCDval_dRSubJets_C, 	//10-21
	ABCDval_dRSubJets_D, 	//10-21
	ABCDval_Tau2ByTau1_A, 	//10-21
	ABCDval_Tau2ByTau1_B, 	//10-21
	ABCDval_Tau2ByTau1_C, 	//10-21
	ABCDval_Tau2ByTau1_D, 	//10-21
	ABCDval_Sub1Pt_A, 	//10-21
	ABCDval_Sub1Pt_B, 	//10-21
	ABCDval_Sub1Pt_C, 	//10-21
	ABCDval_Sub1Pt_D, 	//10-21
	ABCDval_Sub2Pt_A, 	//10-21
	ABCDval_Sub2Pt_B, 	//10-21
	ABCDval_Sub2Pt_C, 	//10-21
	ABCDval_Sub2Pt_D, 	//10-21
	ABCDval_Sub1Mass_A, 	//10-21
	ABCDval_Sub1Mass_B, 	//10-21
	ABCDval_Sub1Mass_C, 	//10-21
	ABCDval_Sub1Mass_D, 	//10-21
	ABCDval_Sub2Mass_A, 	//10-21
	ABCDval_Sub2Mass_B, 	//10-21
	ABCDval_Sub2Mass_C, 	//10-21
	ABCDval_Sub2Mass_D, 	//10-21
	ABCDval_Sub1CSV_A, 	//10-21
	ABCDval_Sub1CSV_B, 	//10-21
	ABCDval_Sub1CSV_C, 	//10-21
	ABCDval_Sub1CSV_D, 	//10-21
	ABCDval_Sub2CSV_A, 	//10-21
	ABCDval_Sub2CSV_B, 	//10-21
	ABCDval_Sub2CSV_C, 	//10-21
	ABCDval_Sub2CSV_D, 	//10-21
	ABCDval_JetFlavor_A,  		//10-21
	ABCDval_JetFlavor_B,  		//10-21
	ABCDval_JetFlavor_C,  		//10-21
	ABCDval_JetFlavor_D,  		//10-21
	ABCDval_HiggsMass_,  		//10-21
	ABCDval_JetFlavor_,  		//10-21
	ABCDval_LeadCA8_Pt_,  		//10-21

	GenInfo_HiggsDaPdgID_,  	//11-06
	GenInfo_NumHiggsTobb_,  	//11-06
	GenInfo_NumHiggsToOther_,  	//11-06

	TH1_Size_
};

struct TH1Info_{
	bool 	Output;
	std::string	Name;
	std::string	Title;
	std::string 	xTitle;
	std::string	yTitle;
	std::string	Unit;
	int  	Bin;
	double  Min;
	double  Max;
};

struct TH1Info_ TH1Info[TH1_Size_] = {
	{ 0,	"ABCDana_CutFlow",			"",	"Cut flow", 			"Yields", "", 		5, 0, 5}, 	//10-21
	{ 0,	"ABCDval_CutFlow",			"",	"Cut flow", 			"Yields", "", 		5, 0, 5}, 	//10-21
	
	{ 0,	"ABCDana_CutRegion",			"",	"Cut Region", 			"Yields", "", 		4, 0, 4}, 	//10-21
	{ 0,	"ABCDana_CutRegion_1b",			"",	"Cut Region, 1bjet", 		"Yields", "", 		4, 0, 4}, 	//10-21
	{ 0,	"ABCDana_CutRegion_2b",			"",	"Cut Region, over 1bjet", 	"Yields", "", 		4, 0, 4}, 	//10-21
	{ 0,	"ABCDval_CutRegion",			"",	"Cut Region", 			"Yields", "", 		4, 0, 4}, 	//10-21

	{ 0,	"ABCDana_Sumw2_A",			"",	"SumW2 for A", 			"Yields", "", 		1, 0, 1}, 	//10-21
	{ 0,	"ABCDana_Sumw2_B",			"",	"SumW2 for B", 			"Yields", "", 		1, 0, 1}, 	//10-21
	{ 0,	"ABCDana_Sumw2_C",			"",	"SumW2 for C", 			"Yields", "", 		1, 0, 1}, 	//10-21
	{ 0,	"ABCDana_Sumw2_D",			"",	"SumW2 for D", 			"Yields", "", 		1, 0, 1}, 	//10-21
	{ 0,	"ABCDana_Sumw2_1b_A",			"",	"SumW2 for A, 1bjet",		"Yields", "", 		1, 0, 1}, 	//10-21
	{ 0,	"ABCDana_Sumw2_1b_B",			"",	"SumW2 for B, 1bjet", 		"Yields", "", 		1, 0, 1}, 	//10-21
	{ 0,	"ABCDana_Sumw2_1b_C",			"",	"SumW2 for C, 1bjet", 		"Yields", "", 		1, 0, 1}, 	//10-21
	{ 0,	"ABCDana_Sumw2_1b_D",			"",	"SumW2 for D, 1bjet", 		"Yields", "", 		1, 0, 1}, 	//10-21
	{ 0,	"ABCDana_Sumw2_2b_A",			"",	"SumW2 for A, over 1bjet",	"Yields", "", 		1, 0, 1}, 	//10-21
	{ 0,	"ABCDana_Sumw2_2b_B",			"",	"SumW2 for B, over 1bjet", 	"Yields", "", 		1, 0, 1}, 	//10-21
	{ 0,	"ABCDana_Sumw2_2b_C",			"",	"SumW2 for C, over 1bjet", 	"Yields", "", 		1, 0, 1}, 	//10-21
	{ 0,	"ABCDana_Sumw2_2b_D",			"",	"SumW2 for D, over 1bjet", 	"Yields", "", 		1, 0, 1}, 	//10-21
	{ 0,	"ABCDval_Sumw2_A",			"",	"SumW2 for A", 			"Yields", "", 		1, 0, 1}, 	//10-21
	{ 0,	"ABCDval_Sumw2_B",			"",	"SumW2 for B", 			"Yields", "", 		1, 0, 1}, 	//10-21
	{ 0,	"ABCDval_Sumw2_C",			"",	"SumW2 for C", 			"Yields", "", 		1, 0, 1}, 	//10-21
	{ 0,	"ABCDval_Sumw2_D",			"",	"SumW2 for D", 			"Yields", "", 		1, 0, 1}, 	//10-21

	{ 0,	"ABCDana_Numbjet",			"",	"Num of bjet, before ABCD", 	"Events", "", 		4, 0, 4}, 	//10-21
	{ 0,	"ABCDana_Numbjet_ABCD",			"",	"Num of bjet, ABCD region", 	"Events", "", 		4, 0, 4}, 	//10-21
	{ 0,	"ABCDana_Numbjet_A",			"",	"Num of bjet, A region", 	"Events", "", 		4, 0, 4}, 	//10-21
	{ 0,	"ABCDana_Numbjet_B",			"",	"Num of bjet, B region", 	"Events", "", 		4, 0, 4}, 	//10-21
	{ 0,	"ABCDana_Numbjet_C",			"",	"Num of bjet, C region", 	"Events", "", 		4, 0, 4}, 	//10-21
	{ 0,	"ABCDana_Numbjet_D",			"",	"Num of bjet, D region", 	"Events", "", 		4, 0, 4}, 	//10-21
	{ 0,	"ABCDana_NumCA8",			"",	"Num of CA8, before ABCD", 	"Events", "", 		4, 0, 4}, 	//10-21
	{ 0,	"ABCDana_NumCA8_ABCD",			"",	"Num of CA8, ABCD region", 	"Events", "", 		4, 0, 4}, 	//10-21
	{ 0,	"ABCDana_NumCA8_A",			"",	"Num of CA8, A region", 	"Events", "", 		4, 0, 4}, 	//10-21
	{ 0,	"ABCDana_NumCA8_B",			"",	"Num of CA8, B region", 	"Events", "", 		4, 0, 4}, 	//10-21
	{ 0,	"ABCDana_NumCA8_C",			"",	"Num of CA8, C region", 	"Events", "", 		4, 0, 4}, 	//10-21
	{ 0,	"ABCDana_NumCA8_D",			"",	"Num of CA8, D region", 	"Events", "", 		4, 0, 4}, 	//10-21
	{ 0,	"ABCDana_bpMass_A",		 	"",	"M(b'), A region",		"Yields", "GeV/c^{2}", 	2000, 0, 2000}, 	//10-21
	{ 0,	"ABCDana_bpMass_B",		 	"",	"M(b'), B region",		"Yields", "GeV/c^{2}", 	2000, 0, 2000}, 	//10-21
	{ 0,	"ABCDana_bpMass_C",		 	"",	"M(b'), C region",		"Yields", "GeV/c^{2}", 	2000, 0, 2000}, 	//10-21
	{ 0,	"ABCDana_bpMass_D",		 	"",	"M(b'), D region",		"Yields", "GeV/c^{2}", 	2000, 0, 2000}, 	//10-21
	{ 0,	"ABCDana_bpPt_A",		 	"",	"p_{T}(b'), A region",		"Yields", "GeV/c", 	1500, 0, 1500}, 	//10-21
	{ 0,	"ABCDana_bpPt_B",		 	"",	"p_{T}(b'), B region",		"Yields", "GeV/c", 	1500, 0, 1500}, 	//10-21
	{ 0,	"ABCDana_bpPt_C",		 	"",	"p_{T}(b'), C region",		"Yields", "GeV/c", 	1500, 0, 1500}, 	//10-21
	{ 0,	"ABCDana_bpPt_D",		 	"",	"p_{T}(b'), D region",		"Yields", "GeV/c", 	1500, 0, 1500}, 	//10-21
	{ 0,	"ABCDana_bpEta_A",		 	"",	"Eta, A region",		"Yields", "", 	800, -4., 4.}, 	//10-21
	{ 0,	"ABCDana_bpEta_B",		 	"",	"Eta, B region",		"Yields", "", 	800, -4., 4.}, 	//10-21
	{ 0,	"ABCDana_bpEta_C",		 	"",	"Eta, C region",		"Yields", "", 	800, -4., 4.}, 	//10-21
	{ 0,	"ABCDana_bpEta_D",		 	"",	"Eta, D region",		"Yields", "", 	800, -4., 4.}, 	//10-21
	{ 0,	"ABCDana_HT", 				"",	"HT(AK5)", 			"Yields", "GeV/c", 	2500, 0, 2500}, 	//10-21
	{ 0,	"ABCDana_HT_A", 				"",	"HT(AK5)", 			"Yields", "GeV/c", 	2500, 0, 2500}, 	//10-21
	{ 0,	"ABCDana_HT_B", 				"",	"HT(AK5)", 			"Yields", "GeV/c", 	2500, 0, 2500}, 	//10-21
	{ 0,	"ABCDana_HT_C", 				"",	"HT(AK5)", 			"Yields", "GeV/c", 	2500, 0, 2500}, 	//10-21
	{ 0,	"ABCDana_HT_D", 				"",	"HT(AK5)", 			"Yields", "GeV/c", 	2500, 0, 2500}, 	//10-21
	{ 0,	"ABCDana_HiggsMass_A",		 	"",	"Pruned Mass(Higgs), A region",		"Yields", "GeV/c^{2}", 	200, 0, 200}, 	//10-21
	{ 0,	"ABCDana_HiggsMass_B",	 		"",	"Pruned Mass(Higgs), B region",		"Yields", "GeV/c^{2}", 	200, 0, 200}, 	//10-21
	{ 0,	"ABCDana_HiggsMass_C",		 	"",	"Pruned Mass(Higgs), C region",		"Yields", "GeV/c^{2}", 	200, 0, 200}, 	//10-21
	{ 0,	"ABCDana_HiggsMass_D",	 		"",	"Pruned Mass(Higgs), D region",		"Yields", "GeV/c^{2}", 	200, 0, 200}, 	//10-21
	{ 0,	"ABCDana_CA8Pt_A",	 		"",	"",				"Yields", "GeV/c", 	700, 0, 700}, 	//10-21
	{ 0,	"ABCDana_CA8Pt_B",	 		"",	"",				"Yields", "GeV/c", 	700, 0, 700}, 	//10-21
	{ 0,	"ABCDana_CA8Pt_C",	 		"",	"",				"Yields", "GeV/c", 	700, 0, 700}, 	//10-21
	{ 0,	"ABCDana_CA8Pt_D",	 		"",	"",				"Yields", "GeV/c", 	700, 0, 700}, 	//10-21
	{ 0,	"ABCDana_CA8PrMass_A",	 	"",	"",				"Yields", "GeV/c^{2}", 	200, 0, 200}, 	//10-21
	{ 0,	"ABCDana_CA8PrMass_B",	 	"",	"",				"Yields", "GeV/c^{2}", 	200, 0, 200}, 	//10-21
	{ 0,	"ABCDana_CA8PrMass_C",	 	"",	"",				"Yields", "GeV/c^{2}", 	200, 0, 200}, 	//10-21
	{ 0,	"ABCDana_CA8PrMass_D",	 	"",	"",				"Yields", "GeV/c^{2}", 	200, 0, 200}, 	//10-21
	{ 0,	"ABCDana_dRSubJets_A",	 	"",	"",				"Yields", "", 	100, 0, 1}, 	//10-21
	{ 0,	"ABCDana_dRSubJets_B",	 	"",	"",				"Yields", "", 	100, 0, 1}, 	//10-21
	{ 0,	"ABCDana_dRSubJets_C",	 	"",	"",				"Yields", "", 	100, 0, 1}, 	//10-21
	{ 0,	"ABCDana_dRSubJets_D",	 	"",	"",				"Yields", "", 	100, 0, 1}, 	//10-21
	{ 0,	"ABCDana_Tau2ByTau1_A",	 	"",	"",				"Yields", "", 	100, 0, 1}, 	//10-21
	{ 0,	"ABCDana_Tau2ByTau1_B",	 	"",	"",				"Yields", "", 	100, 0, 1}, 	//10-21
	{ 0,	"ABCDana_Tau2ByTau1_C",	 	"",	"",				"Yields", "", 	100, 0, 1}, 	//10-21
	{ 0,	"ABCDana_Tau2ByTau1_D",	 	"",	"",				"Yields", "", 	100, 0, 1}, 	//10-21
	{ 0,	"ABCDana_Sub1Pt_A",	 		"",	"",				"Yields", "GeV/c", 	700, 0, 700}, 	//10-21
	{ 0,	"ABCDana_Sub1Pt_B",	 		"",	"",				"Yields", "GeV/c", 	700, 0, 700}, 	//10-21
	{ 0,	"ABCDana_Sub1Pt_C",	 		"",	"",				"Yields", "GeV/c", 	700, 0, 700}, 	//10-21
	{ 0,	"ABCDana_Sub1Pt_D",	 		"",	"",				"Yields", "GeV/c", 	700, 0, 700}, 	//10-21
	{ 0,	"ABCDana_Sub2Pt_A",	 		"",	"",				"Yields", "GeV/c", 	700, 0, 700}, 	//10-21
	{ 0,	"ABCDana_Sub2Pt_B",	 		"",	"",				"Yields", "GeV/c", 	700, 0, 700}, 	//10-21
	{ 0,	"ABCDana_Sub2Pt_C",	 		"",	"",				"Yields", "GeV/c", 	700, 0, 700}, 	//10-21
	{ 0,	"ABCDana_Sub2Pt_D",	 		"",	"",				"Yields", "GeV/c", 	700, 0, 700}, 	//10-21
	{ 0,	"ABCDana_Sub1Mass_A",	 	"",	"",				"Yields", "GeV/c^{2}", 	200, 0, 200}, 	//10-21
	{ 0,	"ABCDana_Sub1Mass_B",	 	"",	"",				"Yields", "GeV/c^{2}", 	200, 0, 200}, 	//10-21
	{ 0,	"ABCDana_Sub1Mass_C",	 	"",	"",				"Yields", "GeV/c^{2}", 	200, 0, 200}, 	//10-21
	{ 0,	"ABCDana_Sub1Mass_D",	 	"",	"",				"Yields", "GeV/c^{2}", 	200, 0, 200}, 	//10-21
	{ 0,	"ABCDana_Sub2Mass_A",	 	"",	"",				"Yields", "GeV/c^{2}", 	200, 0, 200}, 	//10-21
	{ 0,	"ABCDana_Sub2Mass_B",	 	"",	"",				"Yields", "GeV/c^{2}", 	200, 0, 200}, 	//10-21
	{ 0,	"ABCDana_Sub2Mass_C",	 	"",	"",				"Yields", "GeV/c^{2}", 	200, 0, 200}, 	//10-21
	{ 0,	"ABCDana_Sub2Mass_D",	 	"",	"",				"Yields", "GeV/c^{2}", 	200, 0, 200}, 	//10-21
	{ 0,	"ABCDana_Sub1CSV_A",	 	"",	"",				"Yields", "", 	100, 0, 1}, 	//10-21
	{ 0,	"ABCDana_Sub1CSV_B",	 	"",	"",				"Yields", "", 	100, 0, 1}, 	//10-21
	{ 0,	"ABCDana_Sub1CSV_C",	 	"",	"",				"Yields", "", 	100, 0, 1}, 	//10-21
	{ 0,	"ABCDana_Sub1CSV_D",	 	"",	"",				"Yields", "", 	100, 0, 1}, 	//10-21
	{ 0,	"ABCDana_Sub2CSV_A",	 	"",	"",				"Yields", "", 	100, 0, 1}, 	//10-21
	{ 0,	"ABCDana_Sub2CSV_B",	 	"",	"",				"Yields", "", 	100, 0, 1}, 	//10-21
	{ 0,	"ABCDana_Sub2CSV_C",	 	"",	"",				"Yields", "", 	100, 0, 1}, 	//10-21
	{ 0,	"ABCDana_Sub2CSV_D",	 	"",	"",				"Yields", "", 	100, 0, 1}, 	//10-21
	{ 0,	"ABCDana_JetFlavor_A",	 	"",	"Jet Flavor, A region",		"Yields", "", 		50, -25, 25}, 	//10-21
	{ 0,	"ABCDana_JetFlavor_B",	 	"",	"Jet Flavor, B region",		"Yields", "", 		50, -25, 25}, 	//10-21
	{ 0,	"ABCDana_JetFlavor_C",	 	"",	"Jet Flavor, C region",		"Yields", "", 		50, -25, 25}, 	//10-21
	{ 0,	"ABCDana_JetFlavor_D",	 	"",	"Jet Flavor, D region",		"Yields", "", 		50, -25, 25}, 	//10-21
	{ 0,	"ABCDana_HiggsMass", 		"",	"Pruned Mass(Higgs)", 			"Yields", "GeV/c^{2}", 	200, 0, 200}, 	//10-21
	{ 0,	"ABCDana_JetFlavor",	 	"",	"Jet Flavor",			"Yields", "", 		50, -25, 25}, 	//10-21
	{ 0,	"ABCDana_CA8Pt", 			"",	"CA8 Pt", 		"Yields", "GeV/c", 	1500,  0, 1500}, 	//10-21

	{ 0,	"ABCDana_1b_bpMass_A",		 		"",	"M(b'), A region",		"Yields", "GeV/c^{2}", 	2000, 0, 2000}, 	//10-21
	{ 0,	"ABCDana_1b_bpMass_B",			 	"",	"M(b'), B region",		"Yields", "GeV/c^{2}", 	2000, 0, 2000}, 	//10-21
	{ 0,	"ABCDana_1b_bpMass_C",		 		"",	"M(b'), C region",		"Yields", "GeV/c^{2}", 	2000, 0, 2000}, 	//10-21
	{ 0,	"ABCDana_1b_bpMass_D",			 	"",	"M(b'), D region",		"Yields", "GeV/c^{2}", 	2000, 0, 2000}, 	//10-21
	{ 0,	"ABCDana_1b_bpPt_A",			 	"",	"p_{T}(b'), A region",		"Yields", "GeV/c", 	1500, 0, 1500}, 	//10-21
	{ 0,	"ABCDana_1b_bpPt_B",			 	"",	"p_{T}(b'), B region",		"Yields", "GeV/c", 	1500, 0, 1500}, 	//10-21
	{ 0,	"ABCDana_1b_bpPt_C",			 	"",	"p_{T}(b'), C region",		"Yields", "GeV/c", 	1500, 0, 1500}, 	//10-21
	{ 0,	"ABCDana_1b_bpPt_D",			 	"",	"p_{T}(b'), D region",		"Yields", "GeV/c", 	1500, 0, 1500}, 	//10-21
	{ 0,	"ABCDana_1b_bpEta_A",			 	"",	"Eta, A region",		"Yields", "", 	800, -4., 4.}, 	//10-21
	{ 0,	"ABCDana_1b_bpEta_B",			 	"",	"Eta, B region",		"Yields", "", 	800, -4., 4.}, 	//10-21
	{ 0,	"ABCDana_1b_bpEta_C",			 	"",	"Eta, C region",		"Yields", "", 	800, -4., 4.}, 	//10-21
	{ 0,	"ABCDana_1b_bpEta_D",			 	"",	"Eta, D region",		"Yields", "", 	800, -4., 4.}, 	//10-21
	{ 0,	"ABCDana_1b_HT_A", 				"",	"HT(AK5)", 			"Yields", "GeV/c", 	2500, 0, 2500}, 	//10-21
	{ 0,	"ABCDana_1b_HT_B", 				"",	"HT(AK5)", 			"Yields", "GeV/c", 	2500, 0, 2500}, 	//10-21
	{ 0,	"ABCDana_1b_HT_C", 				"",	"HT(AK5)", 			"Yields", "GeV/c", 	2500, 0, 2500}, 	//10-21
	{ 0,	"ABCDana_1b_HT_D", 				"",	"HT(AK5)", 			"Yields", "GeV/c", 	2500, 0, 2500}, 	//10-21
	{ 0,	"ABCDana_2b_bpMass_A",			 	"",	"M(b'), A region",		"Yields", "GeV/c^{2}", 	2000, 0, 2000}, 	//10-21
	{ 0,	"ABCDana_2b_bpMass_B",			 	"",	"M(b'), B region",		"Yields", "GeV/c^{2}", 	2000, 0, 2000}, 	//10-21
	{ 0,	"ABCDana_2b_bpMass_C",			 	"",	"M(b'), C region",		"Yields", "GeV/c^{2}", 	2000, 0, 2000}, 	//10-21
	{ 0,	"ABCDana_2b_bpMass_D",		 		"",	"M(b'), D region",		"Yields", "GeV/c^{2}", 	2000, 0, 2000}, 	//10-21
	{ 0,	"ABCDana_2b_bpPt_A",			 	"",	"p_{T}(b'), A region",		"Yields", "GeV/c", 	1500, 0, 1500}, 	//10-21
	{ 0,	"ABCDana_2b_bpPt_B",			 	"",	"p_{T}(b'), B region",		"Yields", "GeV/c", 	1500, 0, 1500}, 	//10-21
	{ 0,	"ABCDana_2b_bpPt_C",			 	"",	"p_{T}(b'), C region",		"Yields", "GeV/c", 	1500, 0, 1500}, 	//10-21
	{ 0,	"ABCDana_2b_bpPt_D",			 	"",	"p_{T}(b'), D region",		"Yields", "GeV/c", 	1500, 0, 1500}, 	//10-21
	{ 0,	"ABCDana_2b_bpEta_A",			 	"",	"Eta, A region",		"Yields", "", 	800, -4., 4.}, 	//10-21
	{ 0,	"ABCDana_2b_bpEta_B",			 	"",	"Eta, B region",		"Yields", "", 	800, -4., 4.}, 	//10-21
	{ 0,	"ABCDana_2b_bpEta_C",			 	"",	"Eta, C region",		"Yields", "", 	800, -4., 4.}, 	//10-21
	{ 0,	"ABCDana_2b_bpEta_D",			 	"",	"Eta, D region",		"Yields", "", 	800, -4., 4.}, 	//10-21
	{ 0,	"ABCDana_2b_HT_A", 				"",	"HT(AK5)", 			"Yields", "GeV/c", 	2500, 0, 2500}, 	//10-21
	{ 0,	"ABCDana_2b_HT_B", 				"",	"HT(AK5)", 			"Yields", "GeV/c", 	2500, 0, 2500}, 	//10-21
	{ 0,	"ABCDana_2b_HT_C", 				"",	"HT(AK5)", 			"Yields", "GeV/c", 	2500, 0, 2500}, 	//10-21
	{ 0,	"ABCDana_2b_HT_D", 				"",	"HT(AK5)", 			"Yields", "GeV/c", 	2500, 0, 2500}, 	//10-21

	{ 0,	"ABCDval_NumCA8_A",			"",	"Num of CA8, A region", 	"Events", "", 		3, 1, 4}, 	//10-21
	{ 0,	"ABCDval_NumCA8_B",			"",	"Num of CA8, B region", 	"Events", "", 		3, 1, 4}, 	//10-21
	{ 0,	"ABCDval_NumCA8_C",			"",	"Num of CA8, C region", 	"Events", "", 		3, 1, 4}, 	//10-21
	{ 0,	"ABCDval_NumCA8_D",			"",	"Num of CA8, D region", 	"Events", "", 		3, 1, 4}, 	//10-21
	{ 0,	"ABCDval_HT", 				"",	"HT(AK5)", 			"Yields", "GeV/c", 	2500, 0, 2500}, 	//10-21
	{ 0,	"ABCDval_HT_A", 				"",	"HT(AK5)", 			"Yields", "GeV/c", 	2500, 0, 2500}, 	//10-21
	{ 0,	"ABCDval_HT_B", 				"",	"HT(AK5)", 			"Yields", "GeV/c", 	2500, 0, 2500}, 	//10-21
	{ 0,	"ABCDval_HT_C", 				"",	"HT(AK5)", 			"Yields", "GeV/c", 	2500, 0, 2500}, 	//10-21
	{ 0,	"ABCDval_HT_D", 				"",	"HT(AK5)", 			"Yields", "GeV/c", 	2500, 0, 2500}, 	//10-21
	{ 0,	"ABCDval_HiggsMass_A",		 	"",	"Pruned Mass(Higgs), A region",		"Yields", "GeV/c^{2}", 	200, 0, 200}, 	//10-21
	{ 0,	"ABCDval_HiggsMass_B",	 		"",	"Pruned Mass(Higgs), B region",		"Yields", "GeV/c^{2}", 	200, 0, 200}, 	//10-21
	{ 0,	"ABCDval_HiggsMass_C",		 	"",	"Pruned Mass(Higgs), C region",		"Yields", "GeV/c^{2}", 	200, 0, 200}, 	//10-21
	{ 0,	"ABCDval_HiggsMass_D",	 		"",	"Pruned Mass(Higgs), D region",		"Yields", "GeV/c^{2}", 	200, 0, 200}, 	//10-21
	{ 0,	"ABCDval_CA8Pt_A",	 		"",	"",				"Yields", "GeV/c", 	700, 0, 700}, 	//10-21
	{ 0,	"ABCDval_CA8Pt_B",	 		"",	"",				"Yields", "GeV/c", 	700, 0, 700}, 	//10-21
	{ 0,	"ABCDval_CA8Pt_C",	 		"",	"",				"Yields", "GeV/c", 	700, 0, 700}, 	//10-21
	{ 0,	"ABCDval_CA8Pt_D",	 		"",	"",				"Yields", "GeV/c", 	700, 0, 700}, 	//10-21
	{ 0,	"ABCDval_CA8PrMass_A",	 	"",	"",				"Yields", "GeV/c^{2}", 	200, 0, 200}, 	//10-21
	{ 0,	"ABCDval_CA8PrMass_B",	 	"",	"",				"Yields", "GeV/c^{2}", 	200, 0, 200}, 	//10-21
	{ 0,	"ABCDval_CA8PrMass_C",	 	"",	"",				"Yields", "GeV/c^{2}", 	200, 0, 200}, 	//10-21
	{ 0,	"ABCDval_CA8PrMass_D",	 	"",	"",				"Yields", "GeV/c^{2}", 	200, 0, 200}, 	//10-21
	{ 0,	"ABCDval_dRSubJets_A",	 	"",	"",				"Yields", "", 	100, 0, 1}, 	//10-21
	{ 0,	"ABCDval_dRSubJets_B",	 	"",	"",				"Yields", "", 	100, 0, 1}, 	//10-21
	{ 0,	"ABCDval_dRSubJets_C",	 	"",	"",				"Yields", "", 	100, 0, 1}, 	//10-21
	{ 0,	"ABCDval_dRSubJets_D",	 	"",	"",				"Yields", "", 	100, 0, 1}, 	//10-21
	{ 0,	"ABCDval_Tau2ByTau1_A",	 	"",	"",				"Yields", "", 	100, 0, 1}, 	//10-21
	{ 0,	"ABCDval_Tau2ByTau1_B",	 	"",	"",				"Yields", "", 	100, 0, 1}, 	//10-21
	{ 0,	"ABCDval_Tau2ByTau1_C",	 	"",	"",				"Yields", "", 	100, 0, 1}, 	//10-21
	{ 0,	"ABCDval_Tau2ByTau1_D",	 	"",	"",				"Yields", "", 	100, 0, 1}, 	//10-21
	{ 0,	"ABCDval_Sub1Pt_A",	 		"",	"",				"Yields", "GeV/c", 	700, 0, 700}, 	//10-21
	{ 0,	"ABCDval_Sub1Pt_B",	 		"",	"",				"Yields", "GeV/c", 	700, 0, 700}, 	//10-21
	{ 0,	"ABCDval_Sub1Pt_C",	 		"",	"",				"Yields", "GeV/c", 	700, 0, 700}, 	//10-21
	{ 0,	"ABCDval_Sub1Pt_D",	 		"",	"",				"Yields", "GeV/c", 	700, 0, 700}, 	//10-21
	{ 0,	"ABCDval_Sub2Pt_A",	 		"",	"",				"Yields", "GeV/c", 	700, 0, 700}, 	//10-21
	{ 0,	"ABCDval_Sub2Pt_B",	 		"",	"",				"Yields", "GeV/c", 	700, 0, 700}, 	//10-21
	{ 0,	"ABCDval_Sub2Pt_C",	 		"",	"",				"Yields", "GeV/c", 	700, 0, 700}, 	//10-21
	{ 0,	"ABCDval_Sub2Pt_D",	 		"",	"",				"Yields", "GeV/c", 	700, 0, 700}, 	//10-21
	{ 0,	"ABCDval_Sub1Mass_A",	 	"",	"",				"Yields", "GeV/c^{2}", 	200, 0, 200}, 	//10-21
	{ 0,	"ABCDval_Sub1Mass_B",	 	"",	"",				"Yields", "GeV/c^{2}", 	200, 0, 200}, 	//10-21
	{ 0,	"ABCDval_Sub1Mass_C",	 	"",	"",				"Yields", "GeV/c^{2}", 	200, 0, 200}, 	//10-21
	{ 0,	"ABCDval_Sub1Mass_D",	 	"",	"",				"Yields", "GeV/c^{2}", 	200, 0, 200}, 	//10-21
	{ 0,	"ABCDval_Sub2Mass_A",	 	"",	"",				"Yields", "GeV/c^{2}", 	200, 0, 200}, 	//10-21
	{ 0,	"ABCDval_Sub2Mass_B",	 	"",	"",				"Yields", "GeV/c^{2}", 	200, 0, 200}, 	//10-21
	{ 0,	"ABCDval_Sub2Mass_C",	 	"",	"",				"Yields", "GeV/c^{2}", 	200, 0, 200}, 	//10-21
	{ 0,	"ABCDval_Sub2Mass_D",	 	"",	"",				"Yields", "GeV/c^{2}", 	200, 0, 200}, 	//10-21
	{ 0,	"ABCDval_Sub1CSV_A",	 	"",	"",				"Yields", "", 	100, 0, 1}, 	//10-21
	{ 0,	"ABCDval_Sub1CSV_B",	 	"",	"",				"Yields", "", 	100, 0, 1}, 	//10-21
	{ 0,	"ABCDval_Sub1CSV_C",	 	"",	"",				"Yields", "", 	100, 0, 1}, 	//10-21
	{ 0,	"ABCDval_Sub1CSV_D",	 	"",	"",				"Yields", "", 	100, 0, 1}, 	//10-21
	{ 0,	"ABCDval_Sub2CSV_A",	 	"",	"",				"Yields", "", 	100, 0, 1}, 	//10-21
	{ 0,	"ABCDval_Sub2CSV_B",	 	"",	"",				"Yields", "", 	100, 0, 1}, 	//10-21
	{ 0,	"ABCDval_Sub2CSV_C",	 	"",	"",				"Yields", "", 	100, 0, 1}, 	//10-21
	{ 0,	"ABCDval_Sub2CSV_D",	 	"",	"",				"Yields", "", 	100, 0, 1}, 	//10-21
	{ 0,	"ABCDval_JetFlavor_A",	 	"",	"Jet Flavor, A region",		"Yields", "", 		50, -25, 25}, 	//10-21
	{ 0,	"ABCDval_JetFlavor_B",	 	"",	"Jet Flavor, B region",		"Yields", "", 		50, -25, 25}, 	//10-21
	{ 0,	"ABCDval_JetFlavor_C",	 	"",	"Jet Flavor, C region",		"Yields", "", 		50, -25, 25}, 	//10-21
	{ 0,	"ABCDval_JetFlavor_D",	 	"",	"Jet Flavor, D region",		"Yields", "", 		50, -25, 25}, 	//10-21
	{ 0,	"ABCDval_HiggsMass", 		"",	"Pruned Mass(Higgs)", 			"Yields", "GeV/c^{2}", 	200, 0, 200}, 	//10-21
	{ 0,	"ABCDval_JetFlavor",	 	"",	"Jet Flavor",			"Yields", "", 		50, -25, 25}, 	//10-21
	{ 0,	"ABCDval_CA8Pt", 			"",	"CA8 Pt", 		"Yields", "GeV/c", 	1500,  0, 1500}, 	//10-21

	{ 0,	"GenInfo.HiggsDaPdgID", 		"",	"PdgID", 			"Yields", "", 		52, -26, 26}, 	//11-06
	{ 0,	"GenInfo.NumHiggsTobb", 		"",	"Number", 			"Yields", "", 		3, 0, 3}, 	//11-06
	{ 0,	"GenInfo.NumHiggsToOther", 		"",	"Number", 			"Yields", "", 		3, 0, 3}, 	//11-06

};

#endif
