#ifndef SORT_ALGORITMO_H
#define SORT_ALGORIMO_H

void preencher(int V[], int n);
void merge(int v[], int ini, int meio, int fim);
void mergesort(int v[], int ini, int fim);
void insertion_sort(int v[], int n);
void troca(int *a, int *b);
void selection_sort(int v[], int n);
int particiona(int v[], int inicio, int fim);
void quick_sort(int v[], int inicio, int fim);
void medir_tempo(int n);

#endif // SORT_ALGORITHMS_H