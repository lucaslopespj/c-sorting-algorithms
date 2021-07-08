/* Code in this library is to help read and write data in files */
#include <stdio.h>
#include <stdlib.h>

int main() {
    /*int v[6] = {5, 3, -1, 0, 4, 10};*/
    int tam = 15;
    int v[15];
    int num = 0;
    int i = 0;
    int neg = 0;
    int digits = 1;
    char ch = 0;
    FILE *fs = NULL;

    fs = fopen("input.txt", "r");

    if (fs == NULL) {
        printf("Error on open the file\n");
        return -1;
    }

    while (1) {
        ch = getc(fs);

        switch (ch) {
            case '-':
                neg = 1;
                break;
            
            case ',':
                if (neg) {
                    num = -num;
                    neg = 0;
                }
                v[i++] = num;
                num = 0;
                break;
        
            default:
                if (ch != ' ') {
                    num *= 10;
                    num += atoi(&ch);
                }
        }

        if (ch == EOF)
            break;
    }

    fclose(fs);

    printf("Original vector: ");
    for (i = 0; i < tam; i++)
        printf("%d ", v[i]);

    /*
    printf("\nSorted vector: ");
    insertionSort(v, 6);
    selectionSort(v, 6);

    for (i = 0; i < tam; i++)
        printf("%d ", v[i]);

    fs = fopen("output.txt", "w");
    
    if (fs == NULL) {
        printf("Error on open the file\n");
        return -1;
    }*/

    /*for (i = 0; i < 6; i++)
        putc(v[i], fs);*/

    /*for (i = 0; i < tam; i++) {
        if (i < tam-1)
            fprintf(fs, "%d, ", v[i]);
        else
            fprintf(fs, "%d", v[i]);
    }    


    fclose(fs);*/

    return 0;
}