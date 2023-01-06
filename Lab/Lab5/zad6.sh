#!/bin/bash

# sprawdzanie czy podano katalog
if [[ $# -ne 1 ]]; then 
    echo "Nieprawidlowe parametry"
    exit 1
fi 

directory=$1
loopsInformation=""

# funkcja do wyszukiwania zapetlonych linkow miekkich
find_loops() {
    local dir=$1
    for file in "$dir"/*; do
        if [[ -L "$file" ]]; then 
            target=$(readlink "$file")
            if [[-L "$target" ]]; then 
                loopsInformation="$loopsInformation$file -> $target\n"

                find_loops "$target"
            fi
        fi
    done
}

# wywolanie funkcji
find_loops "$directory"

# wypisanie zapetlonych linkow miekkich
echo "Zapetlone linki:"
echo -e "$loopsInformation"

# liczba zapetlen
echo "Liczba zapetlen:" 
echo -e "$loopsInformation" | wc -l

# dlugosc zapetlen
echo "Dlugosc zapetlen:"
echo -e "$loopsInformation" | awk '{print length($0)}'