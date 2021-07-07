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

int main() {
    int v[6] = {5, 3, -1, 0, 4, 10};
    int i;

    printf("Original vector: ");
    for (i = 0; i < 6; i++)
        printf("%d ", v[i]);

    printf("\nSorted vector: ");
    insertionSort(v, 6);

    for (i = 0; i < 6; i++)
        printf("%d ", v[i]);

    printf("\n");
    return 0;
}