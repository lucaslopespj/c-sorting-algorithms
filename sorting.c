#include <stdio.h>
#include <stdlib.h>
#include <math.h>
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

/* Bubble Sort Algorithm */
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

/* Merge function is used in the Merge Sort Algorithm*/
void merge(int *v, int begin, int middle, int end) {
    int *temp, p1, p2, size, i, j, k;
    int end1 = 0, end2 = 0;

    size = end - begin + 1;
    p1 = begin;
    p2 = middle + 1;
    temp = (int *) malloc(size * sizeof(int));

    if (temp != NULL) {
        for (i = 0; i < size; i++) {
            if (!end1 && !end2) {
                if (v[p1] < v[p2])
                    temp[i] = v[p1++];
                else
                    temp[i] = v[p2++];

                if (p1 > middle)
                    end1 = 1;
                if (p2 > end)
                    end2 = 1;
            }
            else {
                if (!end1)
                    temp[i] = v[p1++];
                else
                    temp[i] = v[p2++];
            }
        }
        for (j = 0, k = begin; j < size; j++, k++)
            v[k] = temp[j];
    }
    free(temp);
}

/* Merge Sort Algorithm itself*/
void mergeSort(int *v, int begin, int end) {
    int middle;

    if (begin < end) {
        middle = floor((begin + end) / 2);
        mergeSort(v, begin, middle);
        mergeSort(v, middle+1, end);
        merge(v, begin, middle, end);
    }
}

/* Partition function is used in the Quick Sort Algorithm */
int partition(int *v, int begin, int end) {
    int left, right, pivot, aux;
    
    left = begin;
    right = end;
    pivot = v[begin];

    while (left < right) {
        while (v[left] <= pivot)
            left++;
        
        while (v[right] > pivot)
            right--;
        
        if (left < right) {
            aux = v[left];
            v[left] = v[right];
            v[right] = aux;
        }
    }
    
    v[begin] = v[right];
    v[right] = pivot;
    
    return right;
}

/* Quick Sort Algorithm itself */
void quickSort(int *v, int begin, int end) {
    int pivot;

    if (end > begin) {
        pivot = partition(v, begin, end);
        quickSort(v, begin, pivot-1);
        quickSort(v, pivot+1, end);
    }
}



int main() {
    /*int v[10] = {5, 3, -1, 0, 4, 10, -35, 150, 2, 7};
    int tam = 10;*/
    int i = 0;
    int **v = malloc(sizeof(int *));
    int tam = 0;
    int vet[10];
    int *t = NULL;
    const char *output = "output.txt";

    *v = malloc(sizeof(int));

    tam = readNumFromFile(&t, "input.txt");

    /*printf("Original vector: ");
    for (i = 0; i < tam; i++)
        printf("%d ", (*v)[i]);

    printf("\nSorted vector: ");*/
    /*insertionSort(v, tam);
    selectionSort(v, tam);*/
    /*bubbleSort(v, tam);*/
    /*mergeSort(*v, 0, tam-1);*/
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