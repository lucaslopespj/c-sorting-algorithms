#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "fileHandling.h"
#include "sorting.h"
#include <time.h>

int main() {
    int i, tam = 0;
    int *v = NULL;
    const char *output = "output.txt";
    const char *input = "input.txt";
    int num = 100000;
    double t_insertion, t_selection, t_bubble, t_merge, t_quick;
    clock_t before, after;

    /* Alocates memory to a quantity of "num" numbers */
    v = malloc(num * sizeof (int));
    
    /* Get all the random numbers */
    for (i = 0; i < num; i++) {
        v[i] = randNum(7);
    }

    /* Writes all random numbers in the "input.txt" file */
    writeOnFile(v, num, input);

    /* Free all memory alocated to v */
    free(v);
    v = NULL;

    /* Insertion Sort Computing Time */
    tam = readNumFromFile(&v, input);
    before = clock();
    insertionSort(v, tam);
    after = clock();
    t_insertion = (double) (after - before) / CLOCKS_PER_SEC;

    /* Selection Sort Computing Time */
    tam = readNumFromFile(&v, input);
    before = clock();
    selectionSort(v, tam);
    after = clock();
    t_selection = (double) (after - before) / CLOCKS_PER_SEC;

    /* Bubble Sort Computing Time */
    tam = readNumFromFile(&v, input);
    before = clock();
    bubbleSort(v, tam);
    after = clock();
    t_bubble = (double) (after - before) / CLOCKS_PER_SEC;

    /* Merge Sort Computing Time */
    tam = readNumFromFile(&v, input);
    before = clock();
    mergeSort(v, 0, tam-1);
    after = clock();
    t_merge = (double) (after - before) / CLOCKS_PER_SEC;

    /* Quick Sort Computing Time */
    tam = readNumFromFile(&v, input);
    before = clock();
    quickSort(v, 0, tam-1);
    after = clock();
    t_quick = (double) (after - before) / CLOCKS_PER_SEC;

    /* Writes all sorted numbers in the "output.txt" file*/
    writeOnFile(v, tam, output);

    /* Free all memory alocated to v */
    free(v);
    v = NULL;

    printf("\n");
    printf("+-------------------------- STATISTICS ---------------------------+\n\n");
    printf("         You have sorted %d random numbers.\n", num);
    printf("         The 'input.txt' file contains all random numbers.\n");
    printf("         The 'output.txt' file contains all sorted numbers.\n");
    printf("         Time of each algorithm (seconds):\n");
    printf("             Insertion Sort: %f s\n", t_insertion);
    printf("             Selection Sort: %f s\n", t_selection);
    printf("             Bubble Sort: %f s\n", t_bubble);
    printf("             Merge Sort: %f s\n", t_merge);
    printf("             Quick Sort: %f s\n\n", t_quick);
    printf("+-----------------------------------------------------------------+\n\n");

    return 0;
}