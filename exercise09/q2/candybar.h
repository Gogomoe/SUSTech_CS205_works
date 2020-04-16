#ifndef EXC_CANDYBAR_H
#define EXC_CANDYBAR_H

#include <iostream>

const int Len = 40;
struct CandyBar {
    char brand[Len];
    double weight;
    int calorie;
};

int setCandyBar(CandyBar &snack);

void showCandyBar(const CandyBar &snack);

#endif

