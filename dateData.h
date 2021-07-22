#include <stdio.h>
#include <stdlib.h>

typedef struct dateForm df;

df *dateInit(double seconds);

void printTime(df *date);

void dateKill(df *date);

int getDays(df *date);

int getHours(df *date);

int getMins(df *date);

int getSecs(df *date);

int get_ms(df *date);

int get_us(df *date);