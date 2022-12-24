#!/bin/bash

#potegowanie operatorem 
result=$( echo $1^$2 | bc ) # nie dwa (()) bo to nie jest wyrazenie matematyczne 
echo "Metoda na operator: $result"

a=$1
b=$1
for ((i=1; i<$2; i++))
do
	#echo $b
	result_loop=$(( a * b ))
	b=$result_loop
done
echo "Metoda na petle: $b"
