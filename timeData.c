#include <stdio.h>
#include <stdlib.h>
#include "timeData.h"

struct timeFormat {
    int days;
    int hours;
    int mins;
    int secs;
    int ms;
    int us;
};


 tf *timeInit(double seconds) {
    tf *time = malloc(sizeof (tf));
    time->days = time->hours = time->secs = time->ms = time->us = 0;

    time->days = (int) seconds / (3600 * 24);
    if (time->days > 0) {
        seconds -=  time->days * 3600 * 24;
    }

    time->hours = (int) seconds / 3600;
    if (time->hours > 0) {
        seconds -=  time->hours * 3600;
    }

    time->mins = (int) seconds / 60;
    if (time->mins > 0) {
        seconds -= time->mins * 60;
    }


    time->secs = seconds;
    if (time->secs > 0) {
        seconds -= time->secs;
    } 

    if (seconds > 0) {
        time->ms = 1000 * seconds;
        seconds *= 1000;
        seconds -= time->ms;
        time->us = 1000 * seconds;
    }

    return time;
}


void printTime(tf *time) {
    if (getDays(time) > 0)
        printf(" %d days,", getDays(time));
    if (getHours(time) > 0)
        printf("  %d hours,", getHours(time));
    if (getMins(time) > 0)
        printf("  %d min,", getMins(time));
    if (getSecs(time) > 0)
        printf("  %d s", getSecs(time));
    if (get_ms(time) > 0)
        printf("  %d ms", get_ms(time));
    if (get_us(time) > 0)
        printf("  %d µs", get_us(time));
    
    printf("\n");
}

int getDays(tf *time) {
    return time->days;
}

int getHours(tf *time) {
    return time->hours;
}

int getMins(tf *time) {
    return time->mins;
}

int getSecs(tf *time) {
    return time->secs;
}

int get_ms(tf *time) {
    return time->ms;
}

int get_us(tf *time) {
    return time->us;
}

void timeKill(tf *time) {
    free(time);
    time = NULL;
}