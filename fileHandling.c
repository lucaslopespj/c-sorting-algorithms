/* Code in this library is to help read and write data in files */
#include <stdio.h>
#include <stdlib.h>

int readNumFromFile(int **v, const char *fileName) {
    int i = 0, t = 0, neg = 0, num = 0;
    char ch = 0;
    FILE *fs = NULL;

    fs = fopen(fileName, "r");

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
                t++;
                *v = realloc(*v, t * sizeof(int));    
                (*v)[i++] = num;
                num = 0;
                break;
        
            default:
                if (ch != ' ' && ch != EOF) {
                    num *= 10;
                    num += atoi(&ch);
                }
                else if (ch == EOF) {
                    (*v)[i] = num;
                }
        }

        if (ch == EOF)
            break;
    }

    fclose(fs);
    return ++t;
}

int main() {
    /*int v[6] = {5, 3, -1, 0, 4, 10};
    int tam = 15;
    int v[15];
    int num = 0;
    int t = 0;
    int i = 0;
    int neg = 0;
    int digits = 1;
    char ch = 0;
    FILE *fs = NULL;
    int *vet;

    fs = fopen("input.txt", "r");

    if (fs == NULL) {
        printf("Error on open the file\n");
        return -1;
    }

    vet = malloc(sizeof(int));

    while (1) {
        ch = getc(fs);
        t++;
        vet = realloc(vet, t * sizeof(int));

        switch (ch) {
            case '-':
                neg = 1;
                break;
            
            case ',':
                if (neg) {
                    num = -num;
                    neg = 0;
                }
                t++;
                vet = realloc(vet, (t+1) * sizeof(int));
                v[i++] = num;
                vet[i] = num;
                num = 0;
                break;
        
            default:
                if (ch != ' ' && ch != EOF) {
                    num *= 10;
                    num += atoi(&ch);
                }
                
                else if (ch == EOF) {
                    v[i] = num;
                    vet[i] = num;
                }
        }

        if (ch == EOF)
            break;
    }

    fclose(fs);*/
    int *vet = NULL;
    int t, i;
    const char *file = "input.txt";
    printf("%s\n", file);
    t = readNumFromFile(&vet, file);

    printf("Original vector: ");
    for (i = 0; i < t; i++) {
        printf("%d ", vet[i]);
    }

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

    free(vet);
    vet = NULL;
    printf("\n\nt = %d\n", t);

    return 0;
}