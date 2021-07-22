#include <stdio.h>
#include <stdlib.h>
#include "dateData.h"

struct dateForm {
    int days;
    int hours;
    int mins;
    int secs;
    int ms;
    int us;
};


 df *dateInit(double seconds) {
    df *date = malloc(sizeof (df));
    date->days = date->hours = date->secs = date->ms = date->us = 0;

    date->days = (int) seconds / (3600 * 24);
    if (date->days > 0) {
        seconds -=  date->days * 3600 * 24;
    }

    date->hours = (int) seconds / 3600;
    if (date->hours > 0) {
        seconds -=  date->hours * 3600;
    }

    date->mins = (int) seconds / 60;
    if (date->mins > 0) {
        seconds -= date->mins * 60;
    }


    date->secs = seconds;
    if (date->secs > 0) {
        seconds -= date->secs;
    } 

    if (seconds > 0) {
        date->ms = 1000 * seconds;
        seconds *= 1000;
        seconds -= date->ms;
        date->us = 1000 * seconds;
    }

    return date;
}


void printTime(df *date) {
    if (getDays(date) > 0)
        printf(" %d days,", getDays(date));
    if (getHours(date) > 0)
        printf("  %d hours,", getHours(date));
    if (getMins(date) > 0)
        printf("  %d min,", getMins(date));
    if (getSecs(date) > 0)
        printf("  %d s", getSecs(date));
    if (get_ms(date) > 0)
        printf("  %d ms", get_ms(date));
    if (get_us(date) > 0)
        printf("  %d µs", get_us(date));
    
    printf("\n");
}

int getDays(df *date) {
    return date->days;
}

int getHours(df *date) {
    return date->hours;
}

int getMins(df *date) {
    return date->mins;
}

int getSecs(df *date) {
    return date->secs;
}

int get_ms(df *date) {
    return date->ms;
}

int get_us(df *date) {
    return date->us;
}

void dateKill(df *date) {
    free(date);
    date = NULL;
}