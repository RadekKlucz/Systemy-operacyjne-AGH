#include <stdio.h>
#include <stdlib.h>

void statyczna() {
    double tablica[1000000];
    getchar();
}

void dynamiczna() {
    double *tablica = new double[1000000];
    getchar();
    free(tablica);
}

int main() {
    statyczna();
    getchar();
    dynamiczna();
    
    return 0;
}