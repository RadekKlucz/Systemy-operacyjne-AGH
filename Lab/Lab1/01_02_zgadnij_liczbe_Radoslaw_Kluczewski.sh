#!/bin/bash

if [[ $1 > $2 ]]
then
	echo "Podano zly zakres liczbowy"
	exit 1 
fi

random=$(($RANDOM % $2 + $1)) #generowanie liczby z zakresu
attempt=0
echo $random 

while [[ $attempt != 5 ]]
do
	attempt=$(( $attempt + 1 ))
	echo "Podaj liczbe"
	read number
	if [[ $number != $random ]]
	then
		echo "Nie trafiles!"
	else
		echo "Trafiony zatopiony"
		exit 1
	fi 
done
