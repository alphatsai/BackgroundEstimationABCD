import FWCore.ParameterSet.Config as cms

from FWCore.ParameterSet.VarParsing import VarParsing

from inputFiles_cfi import * 

options = VarParsing('python')

options.register('outFilename', 'bprimeTobH.root',
    VarParsing.multiplicity.singleton,
    VarParsing.varType.string,
    "Output file name"
    )
options.register('reportEvery', 1000,
    VarParsing.multiplicity.singleton,
    VarParsing.varType.int,
    "Report every N events (default is N=1000)"
    )
options.register('doHLTselection', True,
    VarParsing.multiplicity.singleton,
    VarParsing.varType.bool,
    "Do HLT selection"
)
options.register('doGoodVertex', True,
    VarParsing.multiplicity.singleton,
    VarParsing.varType.bool,
    "Do good vertex selection"
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
#options.setDefault('maxEvents', 1000) 

options.parseArguments()

process = cms.Process("ABCD")

process.load("FWCore.MessageService.MessageLogger_cfi")
process.MessageLogger.cout = cms.untracked.PSet(
    threshold = cms.untracked.string('INFO'), 
    ) 
process.MessageLogger.cerr.FwkReport.reportEvery = cms.untracked.int32(1)

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(1) ) # Leave it this way. 

process.source = cms.Source("EmptySource")

process.TFileService = cms.Service("TFileService",
    fileName = cms.string(options.outFilename) 
    )

from BpbH.BprimeTobHAnalysis.EventSelector_cfi import * 
from BpbH.BprimeTobHAnalysis.JMEUncertUntilParameters_cfi import * 

process.ABCD = cms.EDAnalyzer('BackgroundEstimationABCD',
    MaxEvents           = cms.int32(options.maxEvents),
    ReportEvery         = cms.int32(options.reportEvery),  
    InputTTree          = cms.string('ntuple/tree'),
    InputFiles          = cms.vstring(FileNames), 

    HLTPaths            = defaultTriggerSelectionParameters.clone(), 
    DoHLTSelect     	= cms.bool(options.doHLTselection),
    DoGoodVtxSelect     = cms.bool(options.doGoodVertex),
    DoPUReweighting     = cms.bool(options.doPUReweighting),
    File_PUDistMC       = cms.string('pileup_Data_Summer12_53X_S10.root'),
    File_PUDistData     = cms.string('pileup_Data_Summer12_53X_S10.root'),
    Hist_PUDistMC       = cms.string('pileup_mc'),
    Hist_PUDistData     = cms.string('pileup_data'),

    HTAK5Min		= cms.double(900),
    HTAK5Max		= cms.double(100000),

    HJetPtMin		= cms.double(300),
    HJetPtMax		= cms.double(100000),
    HJetAbsEtaMin	= cms.double(-1),
    HJetAbsEtaMax	= cms.double(2.4),
    HJetMassMin 	= cms.double(100),	
    HJetMassMax 	= cms.double(150),	
    HJetPrunedMassMin = cms.double(90),	
    HJetPrunedMassMax = cms.double(140),	
    HJetTau2ByTau1Min = cms.double(-1),
    HJetTau2ByTau1Max = cms.double(0.5),
    Subjet1CSVDiscMin   = cms.double(0.679),
    Subjet1CSVDiscMax   = cms.double(2),
    Subjet2CSVDiscMin   = cms.double(0.679),
    Subjet2CSVDiscMax   = cms.double(2),
    dRSubjetsMin 	= cms.double(0.3),
    dRSubjetsMax 	= cms.double(1000),

    HJetSBMassMin = cms.double(-1),	
    HJetSBMassMax = cms.double(80),
	
    JetPtMin		= cms.double(50),
    JetPtMax		= cms.double(100000),
    JetAbsEtaMin	= cms.double(-1),
    JetAbsEtaMax	= cms.double(2.4),
    bJetPtMin		= cms.double(80),
    bJetPtMax		= cms.double(100000),
    bJetCSVDiscMin  	= cms.double(0.679),
    bJetCSVDiscMax   	= cms.double(2),

    bVetoJetPtMin	= cms.double(30),
    bVetoJetPtMax	= cms.double(100000),
    bVetoJetAbsEtaMin	= cms.double(-1),
    bVetoJetAbsEtaMax	= cms.double(2.4),
    bVetoJetCSVDiscMin 	= cms.double(0.244),
    bVetoJetCSVDiscMax 	= cms.double(2),

    numbJet		= cms.int32(1),
    numHiggsJet		= cms.int32(1),

  #  HTSelParams         = defaultHTSelectionParameters.clone(),
  #  EvtSelParams        = defaultEventSelectionParameters.clone(),

    	
  #  JMEParams           = defaultJMEUncertUntilParameters.clone(),
  #  JESShift            = cms.double(options.JESShift), 
  #  JERShift            = cms.double(options.JERShift), 
  #  SFbShift            = cms.double(options.SFbShift), 
  #  SFlShift            = cms.double(options.SFlShift),

    #BuildMinTree        = cms.bool(False),
    BuildMinTree        = cms.bool(True),
    ) 

process.SimpleMemoryCheck = cms.Service("SimpleMemoryCheck",ignoreTotal = cms.untracked.int32(1) )
process.p = cms.Path(process.ABCD)

