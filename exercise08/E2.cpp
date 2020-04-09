#include <iostream>

using namespace std;

template<typename T>
T max5(T ts[5]) {
    T max = ts[0];
    for (int i = 1; i < 5; ++i) {
        if (ts[i] > max) {
            max = ts[i];
        }
    }
    return max;
}


int main() {

    int intMax = max5(new int[5]{1, 2, 3, 4, 5});
    double doubleMax = max5(new double[5]{1.1, 2.0, 3.0, 4.0, 5.5});

    cout << "Max int = " << intMax << endl
         << "Max double = " << doubleMax << endl;

    return 0;
}