#include "candybar.h"

using namespace std;

int main() {
    cout << "Please enter the number of candybar: ";
    unsigned int number;
    cin >> number;

    cin.ignore(1000, '\n');

    CandyBar *candybars = new CandyBar[number];

    for (int i = 0; i < number; ++i) {
        cout << "CandyBar[" << i << "]" << endl;
        int res = setCandyBar(candybars[i]);

        if (res == -1) {
            number = i;
            break;
        }
    }

    cout << endl << "show candybars" << endl;

    for (int i = 0; i < number; ++i) {
        cout << "CandyBar[" << i << "]" << endl;
        showCandyBar(candybars[i]);
    }

    return 0;
}