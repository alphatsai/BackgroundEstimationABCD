#!/bin/tcsh
if ( $1 == "" ) then
	echo "Please input the list.txt"
	echo "The list.txt's structure should be 'fullName;name;'\n"
	exit	
endif
set list_=`cat $1`
foreach list($list_)
	set root=`echo $list | awk -F ";" '{print $1}'`
	set name=`echo $list | awk -F ";" '{print $2}'`
	if ( -e $root ) then
		echo "change $root to $name.root..."
		mv $root $name.root
	endif
end

