#include <stdio.h>
#include <stdlib.h>

/* Defines a df abstract data type (ADT) */
typedef struct dateForm df;

/* It receives a double 'seconds' that represents an amount of time 
and returns a df ADT pointer. In the backgrounds it partitionalizes 
theses seconds into days, hours, minutes, seconds, miliseconds and microseconds */
df *dateInit(double seconds);

/* It receives a df pointer 'date' and
prints the time*/
void printTime(df *date);

/* It kills a df date */
void dateKill(df *date);

/* It receives a df date pointer
and returns the its number of days */
int getDays(df *date);

/* It receives a df date pointer
and returns the its number of hours */
int getHours(df *date);

/* It receives a df date pointer
and returns the its number of minutes */
int getMins(df *date);

/* It receives a df date pointer
and returns the its number of seconds */
int getSecs(df *date);

/* It receives a df date pointer
and returns the its number of miliseconds */
int get_ms(df *date);

/* It receives a df date pointer
and returns the its number of microseconds */
int get_us(df *date);