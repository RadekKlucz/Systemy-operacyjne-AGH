#!/bin/bash

# Przypisuje liczbe parametrow 
numbers=$#

# Przypisuje parametry 
params=($*)

# Wywolanie parametrow
#echo ${params[*]}

# Wypisanie w odwrotnej kolejnosci 
for(( i=$numbers-1; i>=0; i-- ))
do
	echo -n "${params[$i]} "
done

