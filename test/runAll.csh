#!/bin/tcsh
set sampleNmae='TTJets
		QCD_Pt-800to1000
		QCD_Pt-600to800
		QCD_Pt-470to600
		QCD_Pt-300to470
		QCD_Pt-1800
		QCD_Pt-170to300
		QCD_Pt-1400to1800
		QCD_Pt-1000to1400
		BH_500
		BH_800
		BH_750
		BH_700
		BH_650
		BH_600
		BH_550
		BH_450
		BH_1500
		BH_1200
		BH_1000'
cmsenv
if ( !( -e ./log ) ) then
	mkdir log
endif
if ( !( -e ./root ) ) then
	mkdir root
endif
foreach sample($sampleNmae) 
	rm -f ./log/"$sample".log	
	sed -i "s/SAMPLENAME/$sample.root/g" test.py
	cmsRun test.py | tee ./log/$sample.log
	mv test.root ./root/$sample.root	
	sed -i "s/$sample.root/SAMPLENAME/g" test.py
end
