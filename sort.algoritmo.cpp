#include "sort_algoritmo.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void preencher(int V[], int n)
{
    srand(time(NULL));
    for (int i = 0; i < n; i++)
        V[i] = rand() % 100;
}

void merge(int v[], int ini, int meio, int fim)
{
    int *vaux = (int *)malloc((fim - ini + 1) * sizeof(int));
    int i = ini, j = meio + 1, k = 0;
    while (i <= meio && j <= fim)
    {
        if (v[i] <= v[j])
        {
            vaux[k++] = v[i++];
        }
        else
        {
            vaux[k++] = v[j++];
        }
    }
    while (i <= meio)
        vaux[k++] = v[i++];
    while (j <= fim)
        vaux[k++] = v[j++];
    for (k = 0; k < (fim - ini + 1); k++)
        v[ini + k] = vaux[k];
    free(vaux);
}

void mergesort(int v[], int ini, int fim)
{
    if (ini < fim)
    {
        int meio = (ini + fim) / 2;
        mergesort(v, ini, meio);
        mergesort(v, meio + 1, fim);
        merge(v, ini, meio, fim);
    }
}

void insertion_sort(int v[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = v[i];
        int j = i - 1;
        while (j >= 0 && v[j] > key)
        {
            v[j + 1] = v[j];
            j = j - 1;
        }
        v[j + 1] = key;
    }
}

void troca(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selection_sort(int v[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (v[j] < min_idx)
            {
                min_idx = j;
            }
        }
        troca(&v[min_idx], &v[i]);
    }
}

int particiona(int v[], int inicio, int fim)
{
    int pivo = v[fim];
    int i = inicio - 1;
    for (int j = inicio; j <= fim - 1; j++)
    {
        if (v[j] < pivo)
        {
            i++;
            troca(&v[i], &v[j]);
        }
    }
    troca(&v[i + 1], &v[fim]);
    return i + 1;
}

void quick_sort(int v[], int inicio, int fim)
{
    if (inicio < fim)
    {
        int pi = particiona(v, inicio, fim);
        quick_sort(v, inicio, pi - 1);
        quick_sort(v, pi + 1, fim);
    }
}

void medir_tempo(int n)
{
    int *v = (int *)malloc(n * sizeof(int));
    int *v_copy = (int *)malloc(n * sizeof(int));

    preencher(v, n);

    clock_t start, end;
    double cpu_time_used;

    // Insertion Sort
    memcpy(v_copy, v, n * sizeof(int));
    start = clock();
    insertion_sort(v_copy, n);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Insertion Sort: %f segundos\n", cpu_time_used);

    // Selection Sort
    memcpy(v_copy, v, n * sizeof(int));
    start = clock();
    selection_sort(v_copy, n);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Selection Sort: %f segundos\n", cpu_time_used);

    // Merge Sort
    memcpy(v_copy, v, n * sizeof(int));
    start = clock();
    mergesort(v_copy, 0, n - 1);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Merge Sort: %f segundos\n", cpu_time_used);

    // Quick Sort
    memcpy(v_copy, v, n * sizeof(int));
    start = clock();
    quick_sort(v_copy, 0, n - 1);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Quick Sort: %f segundos\n", cpu_time_used);

    free(v);
    free(v_copy);
}