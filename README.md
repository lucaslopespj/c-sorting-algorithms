# C Sorting Algorithms
## About this repository

It contains a library that implements the most important sorting algorithms in C language. Set your numbers in an input file and get them sorted in an output file with measurements time statistics. 

## About the files
There are 7 files: main.c, sorting.h, sorting.c, fileHandling.h, fileHandling.c, dateData.h, dateData.c

All the **.h** fiels (interface files) contains an explanation of how to use all functions. The **main.c** file it's the program sample that uses all the functions in the **.h** files. All the others **.c** files have the functions' implementations.

## Using the sample
You first must to compile the files in order to use them. You'll need a C Compiler program to do it. For example, I'm using the GCC.

You also need to compile with C99 (see below).

To compile the file:
```bash
$ gcc main.c sorting.c fileHandling.c dateData.c -o program -std=c99 -ansi -pedantic -O2 -lm 
```

After it you can run the program. In a GNU/Linux terminal you can do:
```
$ ./program
```

## What does the main.c file?
Basically it gets a quantity of **v_size** random numbers, put all them in a **input.txt** file. After it the program runs all _sorting algorithms_ getting the numbers from the input file and computes the time of each one.
After all algorithms had been executed the program puts all the sorted numbers in the **output.txt** file and print the statistics on the screen.

For example, for 500.000 numbers it will print something like this:

    +-------------------------- STATISTICS ---------------------------+

         You have sorted 500000 random numbers.
         The 'input.txt' file contains all random numbers.
         The 'output.txt' file contains all sorted numbers.
         Time of each algorithm:
             Insertion Sort:  26 s  300 ms  107 µs
             Selection Sort:  4 min,  23 s  477 ms  708 µs
             Bubble Sort:  5 min,  16 s  753 ms  312 µs
             Merge Sort:  58 ms  878 µs
             Quick Sort:  41 ms  166 µs
             Heap Sort:  61 ms  109 µs
    +-----------------------------------------------------------------+

You can also use the functions in the **.h** files to write other programs.

#### Tips:
You can modify the _v_size_ variable to set the quantity of numbers you want.
Also you can set the max quantity of numbers' digits.

```c
int v_size = 1000; /* Set the quantity of numbers you want to sort*/

int number_of_digits = 5; /* Quantity of digits [1, 7] */

/* num variable will contain ONE random number with 'number_of_digits' digits*/
int num = randNum(number_of_digits);

```


## Sorting Algorithms
You can use the following algorithms to sort your numbers:

---
- **Insertion Sort** 
    - Best case: n
    - Average case: n²
    - Worst case: n²
---
- **Selection Sort**
    - Best case: n²
    - Average case: n²
    - Worst case: n²
---
- **Bubble Sort**
    - Best case: n
    - Average case: n²
    - Worst case: n²
---
- **Merge Sort**
    - Best case: n log n
    - Average case: n log n
    - Worst case: n log n
---
- **Quick Sort**
    - Best case: n log n
    - Average case: n log n
    - Worst case: n²
---
- **Heap Sort**
    - Best case: n log n
    - Average case: n log n
    - Worst case: n log n
---