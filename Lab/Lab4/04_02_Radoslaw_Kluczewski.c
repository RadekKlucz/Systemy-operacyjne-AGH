#include <stdio.h>
#include <stdlib.h>


int main() {
    int rozmiar;
    printf("Podaj rozmiar: ");
    scanf("%d", &rozmiar);

    double *tablica;
    tablica = (double*) malloc(rozmiar * sizeof(*tablica));
    free(tablica);
    getchar();
    
    return 0;
}