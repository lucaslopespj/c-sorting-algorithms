/* Code in this library is to help read and write data in files */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* It receives an integer 'digits' from 1 to 5 which means the number 
of digits and returns a random integer number */
int randNum(int digits);


/* It receives the address of an integer array 'v' and a 'fileName' 
string to the file's path that contains the numbers to be read.
It reads all numbers in the file pointed by the 'fileName' string,
puts them all in 'v' and returns the new size of the array 'v'. */
int readNumFromFile(int **v, const char *fileName);

