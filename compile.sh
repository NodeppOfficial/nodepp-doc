#!/bin/bash
clear
echo "http://xgrfzxnqemazpcs2eoraaagxia52at4g2bdso54yysyvhxrrj454fnqd.onion"
ulimit -n 524288 10485760 ; VAL=$( ulimit -Sn ) ; echo -e "MAX_FILENO: $VAL" 

 LIST=( prxy pm ) ; Y="${#LIST[@]}" ; X=0
flags="-lssl -lcrypto -lz"

for item in "${LIST[@]}" ; do
    $( killall "$item" )
done

echo -e "\nCompiling Services"
for item in "${LIST[@]}" ; do

    tempfile=$(mktemp) ; (( X=$X+1 )) 

    if [ -f "$item" ] ; then 
       echo "-$item Compilled $X/$Y"
       continue 
    fi

    echo "-$item Compilling $X/$Y"

    if !( g++ -o $item ./Services/$item.cpp -I ./Modules $flags ) 2> "$tempfile"; then
         echo -e "\n" ; cat "$tempfile" >&2 ; exit
    fi

    rm "$tempfile"

done

echo -e "\nRunning Services" ; ./pm ; exit;

for item in "${LIST[@]}" ; do
    ./"$item" & sleep 0.1s ;
done