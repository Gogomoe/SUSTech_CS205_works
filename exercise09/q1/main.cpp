#include <iostream>
#include "fun.h"

using namespace std;

int main() {

    double arr1[5]{1.1, 2.2, 3.3, 4.4, 5.5}, arr2[5], arr3[5], arr4[5];

    CopyArray(arr2, arr1);

    CopyArray(arr3, arr1, 5);

    CopyArray(arr4, begin(arr1), end(arr1));

    PrintArray(arr2, arr3, arr4, 5);

    return 0;
}