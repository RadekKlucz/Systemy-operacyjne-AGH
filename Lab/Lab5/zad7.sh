#!/bin/bash

if [[ $# -ne 1 ]]; then 
    echo "Invalid input arguments. Try $0 <directory>"
    exit 1
fi 

if [ ! -d $1 ]; then 
    echo "$1 in not directory"
    exit 1 
fi 

find "$1" -type f -exec stat -c "%h %n" {} + | awk '{count[$1]++;}END{for (i in count) {if (count[i] > 1) print i, count[i]}}'