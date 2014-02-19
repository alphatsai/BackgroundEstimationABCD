void evt(){
	TFile* f = new TFile("SAMPLENAME.root");
	TH1F* h = (TH1F*)f->Get("BprimebH/EvtInfo.CutFlow");
	cout<<"SAMPLENAME :"<<h->GetBinContent(1)<<" > "<<h->GetBinContent(2)<<" > "<<h->GetBinContent(3)<<" > "<<h->GetBinContent(4)<<endl;
}
