#include <stdio.h>
#include "sort_algoritmo.h"

int main()
{
    int tamanhos[] = {1000, 10000, 100000, 200000, 500000};
    int num_testes = sizeof(tamanhos) / sizeof(tamanhos[0]);

    for (int i = 0; i < num_testes; i++)
    {
        printf("Tamanho do vetor: %d\n", tamanhos[i]);
        medir_tempo(tamanhos[i]);
        printf("\n");
    }

    return 0;
}