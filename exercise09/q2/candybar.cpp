#include <string>
#include <cstring>
#include "candybar.h"

int setCandyBar(CandyBar &snack) {
    using namespace std;
    cout << "Enter brand name of a Candy bar: ";
    string line;
    getline(cin, line);
    if (line.size() == 0) {
        cout << "empty name detected!" << endl;
        return -1;
    }
    strcpy(snack.brand, line.c_str());

    cout << "Enter weight of the candy bar: ";
    cin >> snack.weight;

    cout << "Enter calories (an integer value) in the candy bar: ";
    cin >> snack.calorie;

    cin.ignore(1000, '\n');

    return 0;
}


void showCandyBar(const CandyBar &snack) {
    using namespace std;

    cout << "brand: " << snack.brand << endl
         << "weight: " << snack.weight << endl
         << "calories: " << snack.calorie << endl;
}