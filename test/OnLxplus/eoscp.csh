#!/bin/tcsh
if ( $2 == "" ) then
	echo "ERROR: No input file or path"
	echo "Example: eoscp fileName eos/cms/store/user/jtsai/"
	exit
endif
cmsenv
xrdcp -f $1 xroot://eoscms.cern.ch//$2/$1
echo ""
echo "The files in $2 "
eos ls -l $2
