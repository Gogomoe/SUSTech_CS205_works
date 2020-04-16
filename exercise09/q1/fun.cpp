#include <iostream>
#include <iomanip>
#include "fun.h"

// copy with reference notation
void CopyArray(double(&target)[5], double (&source)[5]) {
    for (int i = 0; i < 5; ++i) {
        target[i] = source[i];
    }
}

// copy with pointer notation
void CopyArray(double *target, double *source, int len) {
    for (int i = 0; i < len; ++i) {
        target[i] = source[i];
    }
}

// copy with two pointers
void CopyArray(double *target, double *source_start, double *source_end) {
    while (source_start != source_end) {
        *target = *source_start;
        target++;
        source_start++;
    }
}

//Print the values of three arrays in format
void PrintArray(double *target1, double *target2, double *target3, int len) {
    using namespace std;

    cout << "target1|        target2|        target3|" << endl;
    cout << fixed << setprecision(3);
    for (int i = 0; i < len; ++i) {
        cout << "  "
             << target1[i] << "|          "
             << target2[i] << "|          "
             << target3[i] << "|" << endl;
    }
}