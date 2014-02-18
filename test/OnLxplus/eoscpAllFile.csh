#!/bin/tcsh
if ( $2 == "" ) then
	echo "ERROR: No input data card or eos path"
	echo "Example: source eoscpAllFile.csh dataCard eos/cms/store/user/jtsai"
	exit
endif
set dataCard=`cat $1`
foreach file($dataCard)
	source eoscp.csh $file $2
end
