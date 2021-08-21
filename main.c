#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "fileHandling.h"
#include "sorting.h"
#include "timeData.h"


int main(int argc, char const *argv[]) {
    int i, size = 0;
    int *v = NULL;
    const char *output = "output.txt";
    const char *input = "input.txt";
    int v_size = atoi(argv[1]);
    int num_quantity = atoi(argv[2]);
    
    double aux_time = 0, total_time = 0, reading_time = 0;
    clock_t before = 0, after = 0, totalBefore = 0, totalAfter = 0;
    tf *tf_insertion, *tf_selection, *tf_bubble, *tf_merge, *tf_quick, *tf_heap;
    tf *tf_total, *tf_input, *tf_output, *tf_random, *tf_reading;

    if (v_size <= 0) {
        printf("ERROR: You must choose a number greater than zero\n");
        return 0;
    }

    /* Allocates memory to a quantity of "v_size" numbers */
    v = malloc(v_size * sizeof (int));
    
    before = clock();
    /* Gets all the random numbers */
    for (i = 0; i < v_size; i++) {  
        v[i] = randNum(num_quantity);
    }
    after = clock();
    aux_time = (double) (after - before) / CLOCKS_PER_SEC;
    tf_random = timeInit(aux_time);
    before = after = aux_time = 0;

    before = clock();
    /* Writes all random numbers in the "input.txt" file */
    writeOnFile(v, v_size, input);
    after = clock();
    aux_time = (double) (after - before) / CLOCKS_PER_SEC;
    tf_input = timeInit(aux_time);
    before = after = aux_time = 0;

    /* Free all memory allocated to v */
    free(v);
    v = NULL;

    /* Gets the number of clocks before all sorting algorithms */
    totalBefore = clock();

    /* Read file computation time */
    before = clock();
    size = readNumFromFile(&v, input);
    after = clock();
    reading_time += (double) (after - before) / CLOCKS_PER_SEC;
    before = after = 0;

    /* Insertion Sort Computing Time */
    before = clock();
    insertionSort(v, size);
    after = clock();
    aux_time = (double) (after - before) / CLOCKS_PER_SEC;
    total_time += aux_time;
    tf_insertion = timeInit(aux_time);
    before = after = aux_time = 0;

    /* Free all memory allocated to v */
    free(v);
    v = NULL;

    /* Read file computation time */
    before = clock();
    size = readNumFromFile(&v, input);
    after = clock();
    reading_time += (double) (after - before) / CLOCKS_PER_SEC;
    before = after = 0;

    /* Selection Sort Computing Time */
    before = clock();
    selectionSort(v, size);
    after = clock();
    aux_time = (double) (after - before) / CLOCKS_PER_SEC;
    total_time += aux_time;
    tf_selection = timeInit(aux_time);
    before = after = aux_time = 0;

    /* Free all memory allocated to v */
    free(v);
    v = NULL;

    /* Read file computation time */
    before = clock();
    size = readNumFromFile(&v, input);
    after = clock();
    reading_time += (double) (after - before) / CLOCKS_PER_SEC;
    before = after = 0;

    /* Bubble Sort Computing Time */
    before = clock();
    bubbleSort(v, size);
    after = clock();
    aux_time = (double) (after - before) / CLOCKS_PER_SEC;
    before = after = 0;
    total_time += aux_time;
    tf_bubble = timeInit(aux_time);
    before = after = aux_time = 0;

    /* Free all memory allocated to v */
    free(v);
    v = NULL;

    /* Read file computation time */
    before = clock();
    size = readNumFromFile(&v, input);
    after = clock();
    reading_time += (double) (after - before) / CLOCKS_PER_SEC;
    before = after = 0;

    /* Merge Sort Computing Time */
    before = clock();
    mergeSort(v, 0, size-1);
    after = clock();
    aux_time = (double) (after - before) / CLOCKS_PER_SEC;
    total_time += aux_time;
    tf_merge = timeInit(aux_time);
    before = after = aux_time = 0;

    /* Free all memory allocated to v */
    free(v);
    v = NULL;

    /* Read file computation time */
    before = clock();
    size = readNumFromFile(&v, input);
    after = clock();
    reading_time += (double) (after - before) / CLOCKS_PER_SEC;
    before = after = 0;

    /* Quick Sort Computing Time */
    before = clock();
    quickSort(v, 0, size-1);
    after = clock();
    aux_time = (double) (after - before) / CLOCKS_PER_SEC;
    total_time += aux_time;
    tf_quick = timeInit(aux_time);
    before = after = aux_time = 0;

    /* Free all memory allocated to v */
    free(v);
    v = NULL;

    /* Read file computation time */
    before = clock();
    size = readNumFromFile(&v, input);
    after = clock();
    reading_time += (double) (after - before) / CLOCKS_PER_SEC / 6;
    tf_reading = timeInit(reading_time);
    before = after = 0;

    /* Heap Sort Computing Time */
    before = clock();
    heapSort(v, size);
    after = clock();
    aux_time = (double) (after - before) / CLOCKS_PER_SEC;
    total_time += aux_time;
    tf_heap = timeInit(aux_time);
    before = after = aux_time = 0;
    
    /* Gets the number of clocks after all sorting algoritms */
    totalAfter = clock();
    aux_time = (double) (totalAfter - totalBefore) / CLOCKS_PER_SEC;
    tf_total = timeInit(total_time);

    before = clock();
    /* Writes all sorted numbers in the "output.txt" file*/
    writeOnFile(v, size, output);
    after = clock();
    aux_time = (double) (after - before) / CLOCKS_PER_SEC;
    tf_output = timeInit(aux_time);

    /* Free all memory allocated to v */
    free(v);
    v = NULL;

    printf("\n");
    printf("+----------------------------------------- STATISTICS ------------------------------------------+\n\n");
    printf("         You have sorted %d random numbers.\n", v_size);
    printf("         The 'input.txt' file contains all random numbers.\n");
    printf("         The 'output.txt' file contains all sorted numbers.\n");
    printf("\n         Time of each algorithm:\n");
    
    printf("             Insertion Sort:");
    printTime(tf_insertion);
    
    printf("             Selection Sort:");
    printTime(tf_selection);

    printf("             Bubble Sort:");
    printTime(tf_bubble);

    printf("             Merge Sort:");
    printTime(tf_merge);
    
    printf("             Quick Sort:");
    printTime(tf_quick);    
    
    printf("             Heap Sort:");
    printTime(tf_heap);
    
    printf("\n         Running time of all sorting algorithms :");
    printTime(tf_total);

    printf("\n\n         Time to get the random numbers:");
    printTime(tf_random);

    printf("         Writing time of the 'input.txt' file:");
    printTime(tf_input);
    
    printf("         Writing time of the 'output.txt' file:");
    printTime(tf_output);

    printf("         Mean reading time of the 'input.txt' file:");
    printTime(tf_reading);


    printf("\n+------------------------------------------------------------------------------------------------+\n\n");

    timeKill(tf_insertion);
    timeKill(tf_selection);
    timeKill(tf_bubble);
    timeKill(tf_merge);
    timeKill(tf_quick);
    timeKill(tf_heap);
    timeKill(tf_random);
    timeKill(tf_input);
    timeKill(tf_output);
    timeKill(tf_total);
    timeKill(tf_reading);

    return 0;
}