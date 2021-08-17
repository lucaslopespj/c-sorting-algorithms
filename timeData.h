#include <stdio.h>
#include <stdlib.h>

/* Defines a tf abstract data type (ADT) */
typedef struct timeFormat tf;

/* It receives a double 'seconds' that represents an amount of time 
and returns a tf ADT pointer. In the backgrounds it partitionalizes 
theses seconds into days, hours, minutes, seconds, miliseconds and microseconds */
tf *timeInit(double seconds);

/* It receives a tf pointer 'time' and
prints the time*/
void printTime(tf *time);

/* It kills a tf time */
void timeKill(tf *time);

/* It receives a tf time pointer
and returns the its number of days */
int getDays(tf *time);

/* It receives a tf time pointer
and returns the its number of hours */
int getHours(tf *time);

/* It receives a tf time pointer
and returns the its number of minutes */
int getMins(tf *time);

/* It receives a tf time pointer
and returns the its number of seconds */
int getSecs(tf *time);

/* It receives a tf time pointer
and returns the its number of miliseconds */
int get_ms(tf *time);

/* It receives a tf time pointer
and returns the its number of microseconds */
int get_us(tf *time);