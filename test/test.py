import FWCore.ParameterSet.Config as cms

from FWCore.ParameterSet.VarParsing import VarParsing

#from BackgroundEstimationABCDv1.BackgroundEstimationABCD.BpBpToBHBHinc.BprimeBprimeTobHbHinc_M_800_cfi import * 
#from BackgroundEstimationABCDv1.BackgroundEstimationABCD.Data.JetHT_Run2012BCD_cfi import * 
from inputFiles_cfi import * 
#from inputFiles_0_cfi import * 

FileNames = [
	#'file:/raid1/w/jtsai/bpTobH/skim_Nominal/SAMPLENAME.root'
	'file:/raid1/w/jtsai/bpTobH/NoSF/skim/SAMPLENAME.root'
]
#FileNames = [
##'file:BprimeTobH_v1_10_1_HIn.root'
#'file:/afs/cern.ch/user/j/jtsai/eos/cms/store/user/devdatta/NtuplesBprimeTobH_v1/BprimeBprimeToBHBHinc_M-700_TuneZ2star_8TeV-madgraph/BprimeTobH_v1_10_1_HIn.root',
#'file:/afs/cern.ch/user/j/jtsai/eos/cms/store/user/devdatta/NtuplesBprimeTobH_v1/BprimeBprimeToBHBHinc_M-700_TuneZ2star_8TeV-madgraph/BprimeTobH_v1_1_1_Pf5.root',
#'file:/afs/cern.ch/user/j/jtsai/eos/cms/store/user/devdatta/NtuplesBprimeTobH_v1/BprimeBprimeToBHBHinc_M-700_TuneZ2star_8TeV-madgraph/BprimeTobH_v1_2_1_Y96.root',
#'file:/afs/cern.ch/user/j/jtsai/eos/cms/store/user/devdatta/NtuplesBprimeTobH_v1/BprimeBprimeToBHBHinc_M-700_TuneZ2star_8TeV-madgraph/BprimeTobH_v1_3_1_h6K.root',
#'file:/afs/cern.ch/user/j/jtsai/eos/cms/store/user/devdatta/NtuplesBprimeTobH_v1/BprimeBprimeToBHBHinc_M-700_TuneZ2star_8TeV-madgraph/BprimeTobH_v1_4_1_gI9.root',
#'file:/afs/cern.ch/user/j/jtsai/eos/cms/store/user/devdatta/NtuplesBprimeTobH_v1/BprimeBprimeToBHBHinc_M-700_TuneZ2star_8TeV-madgraph/BprimeTobH_v1_5_1_QTk.root',
#'file:/afs/cern.ch/user/j/jtsai/eos/cms/store/user/devdatta/NtuplesBprimeTobH_v1/BprimeBprimeToBHBHinc_M-700_TuneZ2star_8TeV-madgraph/BprimeTobH_v1_6_1_H6G.root',
#'file:/afs/cern.ch/user/j/jtsai/eos/cms/store/user/devdatta/NtuplesBprimeTobH_v1/BprimeBprimeToBHBHinc_M-700_TuneZ2star_8TeV-madgraph/BprimeTobH_v1_7_1_YrU.root',
#'file:/afs/cern.ch/user/j/jtsai/eos/cms/store/user/devdatta/NtuplesBprimeTobH_v1/BprimeBprimeToBHBHinc_M-700_TuneZ2star_8TeV-madgraph/BprimeTobH_v1_8_1_KTf.root',
#'file:/afs/cern.ch/user/j/jtsai/eos/cms/store/user/devdatta/NtuplesBprimeTobH_v1/BprimeBprimeToBHBHinc_M-700_TuneZ2star_8TeV-madgraph/BprimeTobH_v1_9_1_G4q.root'
#]

#FileNames = [
#    'file:/afs/cern.ch/user/j/jtsai/eos/cms/store/user/devdatta/NtuplesBprimeTobH_v1/Data_bugfix/Jet_Run2012A/BprimeTobH_v1_86_1_aXM.root',
#    'file:/afs/cern.ch/user/j/jtsai/eos/cms/store/user/devdatta/NtuplesBprimeTobH_v1/Data_bugfix/Jet_Run2012A/BprimeTobH_v1_87_1_S4O.root',
#    'file:/afs/cern.ch/user/j/jtsai/eos/cms/store/user/devdatta/NtuplesBprimeTobH_v1/Data_bugfix/Jet_Run2012A/BprimeTobH_v1_88_1_0vB.root',
#    'file:/afs/cern.ch/user/j/jtsai/eos/cms/store/user/devdatta/NtuplesBprimeTobH_v1/Data_bugfix/Jet_Run2012A/BprimeTobH_v1_89_1_hm3.root',
#]


options = VarParsing('python')

options.register('outFilename', 'test.root',
    VarParsing.multiplicity.singleton,
    VarParsing.varType.string,
    "Output file name"
    )
options.register('reportEvery', 1000,
    VarParsing.multiplicity.singleton,
    VarParsing.varType.int,
    "Report every N events (default is N=1000)"
    )
options.register('jetPtMin', 50.,
    VarParsing.multiplicity.singleton,
    VarParsing.varType.float,
    "Minimum jet Pt"
    )
options.register('jetPtMax', 1.E6,
    VarParsing.multiplicity.singleton,
    VarParsing.varType.float,
    "Maximum jet Pt"
    )
options.register('bJetPtMin', 80.,
    VarParsing.multiplicity.singleton,
    VarParsing.varType.float,
    "Minimum b jet Pt"
    )
options.register('bJetCSV', 0.679,
    VarParsing.multiplicity.singleton,
    VarParsing.varType.float,
    "CSV discriminate b jet"
    )
options.register('fatJetPtMin', 300.,
    VarParsing.multiplicity.singleton,
    VarParsing.varType.float,
    "Minimum fat jet Pt"
    )
options.register('fatJetPtMax', 1.E6,
    VarParsing.multiplicity.singleton,
    VarParsing.varType.float,
    "Maximum fat jet Pt"
    )
options.register('fatJetMassMin', 100.,
    VarParsing.multiplicity.singleton,
    VarParsing.varType.float,
    "Minimum fat jet mass"
    )
options.register('fatJetMassMax', 150.,
    VarParsing.multiplicity.singleton,
    VarParsing.varType.float,
    "Maximum fat jet mass"
    )
options.register('fatJetPrunedMassMin', 75.,
    VarParsing.multiplicity.singleton,
    VarParsing.varType.float,
    "Minimum fat jet pruned mass"
    )
options.register('fatJetPrunedMassMax', 1.E6,
    VarParsing.multiplicity.singleton,
    VarParsing.varType.float,
    "Maximum fat jet pruned mass"
    )
options.register('fatJetTau2ByTau1Max', 0.5,
    VarParsing.multiplicity.singleton,
    VarParsing.varType.float,
    "Maximum fat jet tau2/tau1"
    )
options.register('subjet1CSVDiscMin', 0.679,
    VarParsing.multiplicity.singleton,
    VarParsing.varType.float,
    "Minimum subjet1 b discriminator"
    )
options.register('subjet1CSVDiscMax', 1.000,
    VarParsing.multiplicity.singleton,
    VarParsing.varType.float,
    "Maximum subjet1 b discriminator"
    )
options.register('subjet2CSVDiscMin', 0.679,
    VarParsing.multiplicity.singleton,
    VarParsing.varType.float,
    "Minimum subjet2 b discriminator"
    )
options.register('subjet2CSVDiscMax', 1.000,
    VarParsing.multiplicity.singleton,
    VarParsing.varType.float,
    "Maximum subjet2 b discriminator"
    )
options.register('hTMin', 1000,
    VarParsing.multiplicity.singleton,
    VarParsing.varType.float,
    "Minimum HT"
    )
options.register('hTMax', 1.E6,
    VarParsing.multiplicity.singleton,
    VarParsing.varType.float,
    "Maximum HT"
    )

options.register('doPUReweighting', True,
    VarParsing.multiplicity.singleton,
    VarParsing.varType.bool,
    "Do pileup reweighting"
)
options.register('JESShift', 0.0,
    VarParsing.multiplicity.singleton,
    VarParsing.varType.float,
    "JES shift in unit of sigmas" 
    )
options.register('JERShift', 0.0,
    VarParsing.multiplicity.singleton,
    VarParsing.varType.float,
    "JER shift in unit of sigmas" 
    )
options.register('SFbShift', 0.0,
    VarParsing.multiplicity.singleton,
    VarParsing.varType.float,
    "SFb shift in unit of sigmas" 
    )
options.register('SFlShift', 0.0,
    VarParsing.multiplicity.singleton,
    VarParsing.varType.float,
    "SFl shift in unit of sigmas" 
    )
if options.SFbShift != 0.0 and options.SFlShift != 0.0: 
  print "SFbshift = ",  options.SFbShift, " and SFlshift = ", options.SFlShift
  print "Warning: must be varied independently."

options.setDefault('maxEvents', -1000) 

options.parseArguments()

process = cms.Process("BprimebH")

process.load("FWCore.MessageService.MessageLogger_cfi")
process.MessageLogger.cout = cms.untracked.PSet(
    threshold = cms.untracked.string('INFO'), 
    ) 
process.MessageLogger.cerr.FwkReport.reportEvery = cms.untracked.int32(1)

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(1) ) # Leave it this way. 
#process.options   = cms.untracked.PSet( wantSummary = cms.untracked.bool(True) ) # show cpu time
process.source = cms.Source("EmptySource")

process.TFileService = cms.Service("TFileService",
    fileName = cms.string(options.outFilename) 
    )

#from BpbH.BprimeTobH.TriggerSelector_cfi import * 
#from BpbH.BprimeTobH.HiggsJetSelector_cfi import * 
#from BpbH.BprimeTobH.HTSelector_cfi import * 
from BpbH.BprimeTobHAnalysis.EventSelector_cfi import * 
from BpbH.BprimeTobHAnalysis.JMEUncertUntilParameters_cfi import * 

process.BprimebH = cms.EDAnalyzer('BackgroundEstimationABCD',
    MaxEvents           = cms.int32(options.maxEvents),
    ReportEvery         = cms.int32(options.reportEvery),  
    InputTTree          = cms.string('BprimebH/tree'),
    InputFiles          = cms.vstring(FileNames), 
    HLTPaths            = defaultTriggerSelectionParameters.clone(), 
    DoPUReweighting     = cms.bool(options.doPUReweighting),
    File_PUDistMC       = cms.string('pileup_Data_Summer12_53X_S10.root'),
    File_PUDistData     = cms.string('pileup_Data_Summer12_53X_S10.root'),
    Hist_PUDistMC       = cms.string('pileup_mc'),
    Hist_PUDistData     = cms.string('pileup_data'),
	
    JetPtMin            = cms.double(options.jetPtMin),
    JetPtMax            = cms.double(options.jetPtMax),
    BJetPtMin           = cms.double(options.bJetPtMin),
    BJetCSV           	= cms.double(options.bJetCSV),

    JetSelParams        = defaultJetSelectionParameters.clone(
    		IsJetIDLoose        = cms.bool(False), 
   		IsJetIDTight        = cms.bool(True), 
		jetPtMin = cms.double(50)
	),
    BJetSelParams       = defaultBJetSelectionParameters.clone(),
#    FatJetSelParams     = defaultFatJetSelectionParameters.clone(
#	), 
    HiggsJetSelParams   = defaultHiggsJetSelectionParameters.clone(
    		fatJetPtMin         = cms.double(300.),
		fatJetPrunedMassMin = cms.double(75.),
    		fatJetMassMin       = cms.double(100.),
    		fatJetMassMax       = cms.double(150.),
    		fatJetTau2ByTau1Max = cms.double(0.5),
    		dRSubjetsMin        = cms.double(0.4), 
		dRSubjetsMax        = cms.double(0.8), 
    		subjet1CSVDiscMin   = cms.double(0.244),
    		subjet2CSVDiscMin   = cms.double(0.244),
    		subjet1CSVDiscMax   = cms.double(1.1),
    		subjet2CSVDiscMax   = cms.double(1.1),
	), 
    HTSelParams         = defaultHTSelectionParameters.clone(),
    EvtSelParams        = defaultEventSelectionParameters.clone(),

    JMEParams           = defaultJMEUncertUntilParameters.clone(),
    JESShift            = cms.double(options.JESShift), 
    JERShift            = cms.double(options.JERShift), 
    SFbShift            = cms.double(options.SFbShift), 
    SFlShift            = cms.double(options.SFlShift),

    ) 
process.SimpleMemoryCheck = cms.Service("SimpleMemoryCheck",ignoreTotal = cms.untracked.int32(1) )
process.p = cms.Path(process.BprimebH)

