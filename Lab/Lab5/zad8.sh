#!/bin/bash

if [[ $# -ne 1 ]]; then 
    echo "Invalid input arguments. Try $0 <directory>"
    exit 1
fi 

if [ ! -d $1 ]; then
    echo "$1 is not directory."
    exit 1
fi

find "$1" -printf "%M %p\n" | awk '{count[$1]++;}END{for (i in count) {if (count[i] > 0) print i, count[i]}}' | sort