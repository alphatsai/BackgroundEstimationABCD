#!/bin/tcsh
cmsenv
if ( $3 == "" ) then
	echo "Please input FolderCardm, EOS_Path and output folder"
	echo " EX: source haddFromEOS.csh [FolderCard] [inputEOSForder] [outputEOSForder]"
	exit
endif
set mainForder='eos/cms/store/user/jtsai'
set subForder='bpTobH/backgroundEstimationSkim'
set eosPath=`echo $HOME/$mainForder`
set eosPath2=`echo $HOME/$mainForder/$subForder/$2`
set eosPath3=`echo $HOME/$mainForder/$subForder/$3`
if ( !( -e $eosPath ) ) then
	echo "ERROR: Please check eos if mount in home director"
	echo "		EX: eosmount ~/eos"
	exit
endif
if ( !( -e $eosPath2 ) ) then
	echo "ERROR: Here is no $eosPath2"
	echo "	     Please check input EOS forder exist"
	exit
endif
if ( !( -e $eosPath3 ) ) then
	/afs/cern.ch/project/eos/installation/0.3.15/bin/eos.select mkdir -p $mainForder/$subForder/$3
endif
set eosPath_=`echo $eosPath2 | sed 's/\//\\\//g'`
set fs=`cat $1 | grep -v '#'`
foreach f($fs)
	set if=`echo $f | awk -F ';' '{print $1}'`
	set of=`echo $f | awk -F ';' '{print $2}'`
	set roots=`/afs/cern.ch/project/eos/installation/0.3.15/bin/eos.select ls -l $mainForder/$subForder/$2/$if | awk '{print $9}' | sed "s/^/$eosPath_\/$if\//g"`
	#echo $roots
	set output=`echo $of'.root'`
	echo "hadd $if to $output "
	hadd -f $output $roots
	./eoscp.csh $output $mainForder/$subForder/$3
	rm -f $output
end

