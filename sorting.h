/* A file to write the header file (interface) */
#include <stdio.h>
#include <stdlib.h>
#include "fileHandling.h"

/* This function receives an array of integers of 
size n and sorts it by performing the Insertion Sort Algorithm */
void insertionSort(int *v, int n);

/* This function receives an array of integers of 
size n and sorts it by performing the Selection Sort Algorithm */
void selectionSort(int *v, int n);

/* This function receives an array of integers of 
size n and sorts it by performing the Bubble Sort Algorithm */
void bubbleSort(int *v, int n);

/* This function receives an array of integers of 
size where begin and end are variables that represents
the beginning of the array and the end variable its final
and sorts the array by performing the Merge Sort Algorithm */
void mergeSort(int *v, int begin, int end);

/* This function receives an array of integers of 
size where begin and end are variables that represents
the beginning of the array and the end variable its final
and sorts the array by performing the Quick Sort Algorithm */
void quickSort(int *v, int begin, int end);