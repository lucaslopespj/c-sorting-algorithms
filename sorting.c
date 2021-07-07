#include <stdio.h>
#include <stdlib.h>

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

/* Selection Sorte Algorithm */
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

int main() {
    int v[6] = {5, 3, -1, 0, 4, 10};
    int i;

    printf("Original vector: ");
    for (i = 0; i < 6; i++)
        printf("%d ", v[i]);

    printf("\nSorted vector: ");
    /*insertionSort(v, 6);*/
    selectionSort(v, 6);

    for (i = 0; i < 6; i++)
        printf("%d ", v[i]);

    printf("\n");
    return 0;
}