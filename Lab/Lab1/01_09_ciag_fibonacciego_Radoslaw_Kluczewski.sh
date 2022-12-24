#!/bin/bash

N=$1
# Pierwszy numer ciagu 
a=0
# Drugi numer ciagu 
b=1

echo "Ciag fibonaciego dla dla okreslonych $1 miejsc to: " 
for(( i=0; i<N; i++ )) 
do 
	echo -n "$a "
	Fn=$((a + b))
	a=$b
	b=$Fn
done
