/* Code in this library is to help read and write data in files */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* It receives an integer 'digits' from 1 to 7 which means the number 
of digits and returns a random integer number. */
int randNum(int digits);

/* It receives the address of an integer array 'v' and a 'fileName' 
string to the file's path that contains the numbers to be read.
It reads all numbers in the file pointed by the 'fileName' string,
puts them all in 'v' and returns the new size of the array 'v'. */
int readNumFromFile(int **v, const char *fileName);


/* It receives an integer array 'v', the array's size 'n' and also
a string 'fileName' which means the name of the output file, for
example it could be "output.txt".
The function writes all the numbers of 'v' in the 'fileName' file.
If the file does not exist it will be creates. If already exists it
will be completely rewrited (previous content is erased).*/
void writeOnFile(int *v, int n, const char *fileName);

