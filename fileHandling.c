/* Code in this library is to help read and write data in files */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int randNum(int digits) {
    struct timespec {
        time_t   tv_sec;        
        long     tv_nsec;       
    } ts;

    timespec_get(&ts, 1);
    srand(ts.tv_nsec);

    switch (digits) {
        case 1:
            return rand() % 9;
        
        case 2:
            return rand() % 99;
        
        case 3:
            return rand() % 999;
        
        case 4:
            return rand() % 9999;
        
        case 5:
            return rand() % 99999;   

        case 6:
            return rand() % 999999;

        case 7: 
            return rand() % 99999999;         
        
        default:
            return rand() % 100;
    }
}

int readNumFromFile(int **v, const char *fileName) {
    int i = 0, t = 0, neg = 0, num = 0;
    char ch = 0;
    FILE *fs = NULL;
    int *more = NULL;

    fs = fopen(fileName, "r");

    *v = (int *) malloc(sizeof(int));

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
                *v = realloc(*v, t * sizeof(*v));   
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

void writeOnFile(int *v, int n, const char *fileName) {
    int i;
    FILE *fs;

    fs = fopen(fileName, "w");

    if (fs == NULL) {
        printf("Error on open the file\n");
        return;
    }

    for (i = 0; i < n; i++) {
        fprintf(fs, "%d", v[i]);

        if (i < n-1) {
            fprintf(fs, ",");
            fprintf(fs, " ");
        }
    }
    
    fclose(fs);
}