#include "countingdays.h"

int t = 0;
int day = 1;

void lookAtClock(int hours, int minutes) {
    int t2 = hours * 60 + minutes;
    day += t2 < t;
    t = t2;
}

int getDay() {
    return day;
}
