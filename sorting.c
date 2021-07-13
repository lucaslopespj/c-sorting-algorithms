#include <stdio.h>
#include <stdlib.h>
#include "fileHandling.h"

/* Insertion Sort Algorithm */
void insertionSort(int *v, int n) {
    int i, j, x;
    
    for (i = 1; i < n; i++) {
        x = v[i];
        for (j = i; (j > 0) && (x < v[j-1]); j--)
            v[j] = v[j-1];
        v[j] = x;
    }
}

/* Selection Sort Algorithm */
void selectionSort(int *v, int n) {
    int i, j, less, replace;

    for (i = 0; i < n-1; i++) {
        less = i;

        for (j = i+1; j < n; j++) {
            if (v[j] < v[less])
                less = j;
        }
        
        if (i != less) {
            replace = v[i];
            v[i] = v[less];
            v[less] = replace;
        }
    }
}

/* Selection Sorte Algorithm */
void bubbleSort(int *v, int n) {
    int i, next, aux, fim = n;

    do {
        next = 0;
        for (i = 0; i < fim-1; i++) {
            if (v[i] > v[i+1]) {
                aux = v[i];
                v[i] = v[i+1];
                v[i+1] = aux;
                next = i;
            }
        }
        fim--;
    } while (next != 0);
}

int main() {
    int v[10] = {5, 3, -1, 0, 4, 10, -35, 150, 2, 7};
    int i = 0, tam = 10;

    printf("Original vector: ");
    for (i = 0; i < tam; i++)
        printf("%d ", v[i]);

    printf("\nSorted vector: ");
    /*insertionSort(v, tam);
    selectionSort(v, tam);*/
    bubbleSort(v, tam);

    for (i = 0; i < tam; i++) {
        if (i < tam-1)
            printf("%d, ", v[i]);
        else
            printf("%d\n", v[i]);
    }       

    return 0;
}