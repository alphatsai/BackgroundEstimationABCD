#!/bin/csh

cmsenv

set logName=$1

if ( $1 == "" ) then
echo "Please input log name : ./check.csh log_name"
exit
endif

if (! -e $1 ) then
echo "Please check if the $1 file exists or not"
exit
endif

set items=`grep "MemoryCheck: module" $logName | awk '{print $3}' | sort -u`
set Nitems=`grep "MemoryCheck: module" $logName | awk '{print $3}' | sort -u|wc | awk '{print $1}'`

if ( -e draw.C ) then 
rm draw.C
endif
echo "void draw(){ ">& draw.C
echo 'TCanvas *c1 = new TCanvas("c1","",640,640);' >> draw.C

@ counter=1
foreach item_($items)
    if ( -e .logRSS ) then
       rm .logRSS
    endif
    if ( -e .logEvent ) then
       rm .logEvent
    endif

    set item__=`echo $item_|sed 's/:/_/g'`
    if ( -e .$item__ ) then
       rm .$item__
    endif

    grep "MemoryCheck: module" $logName | grep "$item_" | awk '{print $9}' >& .logRSS
    set N__=`wc .logRSS|awk '{print $1}'`
    seq 1 $N__ >& .logEvent
    paste .logEvent .logRSS >& .$item__

    echo 'TGraph *TG'$item__' = new TGraph(".'$item__'");' >> draw.C
    echo 'TG'$item__'->SetTitle("'$item_'");' >> draw.C
    echo 'TG'$item__'->GetXaxis()->SetTitle("EventNumber");'>> draw.C
    echo 'TG'$item__'->GetYaxis()->SetTitle("RSS (Resident Set Size)");'>> draw.C
    echo 'TG'$item__'->Draw("APL");'>> draw.C
    if ( $counter == 1 ) then
       echo 'c1->Print("check.pdf(");' >> draw.C
#    else if ( $counter == $Nitems ) then
#       echo 'c1->Print("check.pdf)");' >> draw.C
    else 
       echo 'c1->Print("check.pdf");' >> draw.C
    endif

    @ counter++
end

if ( -e .logRSS ) then
rm .logRSS
endif
if ( -e .logEvent ) then
rm .logEvent
endif

set item_=Summary
set item__=Summary
if ( -e .$item__ ) then
rm .$item__
endif

grep "MemoryCheck: module" $logName | grep "bprimeKit:bprimeKit" | awk '{print $8}' >& .logRSS
set N__=`wc .logRSS|awk '{print $1}'`
seq 1 $N__ >& .logEvent
paste .logEvent .logRSS >& .$item__

echo 'TGraph *TG'$item__' = new TGraph(".'$item__'");' >> draw.C
echo 'TG'$item__'->SetTitle("'$item_'");' >> draw.C
echo 'TG'$item__'->GetXaxis()->SetTitle("EventNumber");'>> draw.C
echo 'TG'$item__'->GetYaxis()->SetTitle("RSS (Resident Set Size)");'>> draw.C
echo 'TG'$item__'->Draw("APL");'>> draw.C
echo 'c1->Print("check.pdf)");' >> draw.C

echo "} ">> draw.C

root -l -b -q draw.C
cp check.pdf ~/public/html/
