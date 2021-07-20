#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "fileHandling.h"

int main() {
    /*int v[10] = {5, 3, -1, 0, 4, 10, -35, 150, 2, 7};
    int tam = 10;*/
    int i = 0;
    int **v = malloc(sizeof(int *));
    int tam = 0;
    int vet[60000];
    int *t = NULL;
    const char *output = "output.txt";
    /*int num = 10000000;*/
    int num = 1000000;
    *v = malloc(sizeof(int));
    t = malloc(num * sizeof (int));
    
    for (i = 0; i < num; i++) {
        t[i] = randNum(7);
    }

    writeOnFile(t, num, "input.txt");

    free(t);
    t = NULL;

    tam = readNumFromFile(&t, "input.txt");

    /*printf("Original vector: ");
    for (i = 0; i < tam; i++)
        printf("%d ", (*v)[i]);

    printf("\nSorted vector: ");*/
    /*insertionSort(t, tam);*/
    /*selectionSort(v, tam);*/
    /*bubbleSort(v, tam);*/
    /*mergeSort(t, 0, tam-1);*/
    quickSort(t, 0, tam-1);

    /*for (i = 0; i < tam; i++) {
        if (i < tam-1)
            printf("%d, ", (*v)[i]);
        else
            printf("%d\n", (*v)[i]);
    }       

    for (i = 0; i < tam; i++)
        vet[i] = (*v)[i];*/

    /*for (i = 0; i < tam; i++)
        printf("%d, ", vet[i]);
    printf("\n"); */
    
    writeOnFile(t, tam, output);

    free(*v);
    free(v);
    free(t);
    t = NULL;
    *v = NULL;
    v = NULL;

    return 0;
}