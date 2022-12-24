#!/bin/bash

if [ $# -ne 2 ] #-ne not equal
then
	echo "Too many arguments"
	echo "Correct use: ./skrypt01.sh <directory> <size>"
	exit 1
fi
       	
if [ ! -d $1 ] 
then 
	echo "$1 to nie katalog"
	exit 1
fi 
final=$(find $1 -type f -size $2 -mtime -1) #-mtime -1 mniej niz jeden dzien temu 
echo $final
