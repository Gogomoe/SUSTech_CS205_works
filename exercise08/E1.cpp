#include <iostream>

using namespace std;

struct CandyBar {
    char brand[30];
    double weight;
    int calorie;
};

void set(CandyBar &cb) {
    cout << "Enter brand name of a Candy bar: ";
    cin.getline(cb.brand, 30);
    cout << "Enter weight of the candy bar: ";
    cin >> cb.weight;
    cout << "Enter calories (an integer value) in the candy bar: ";
    cin >> cb.calorie;
    cin.ignore(100, '\n');
}

void set(CandyBar *const cb) {
    set(*cb);
}

void show(const CandyBar &cb) {
    cout << "Brand: " << cb.brand << endl
         << "Weight: " << cb.weight << endl
         << "Calories: " << cb.calorie << endl;
}

void show(const CandyBar *cb) {
    show(*cb);
}


int main() {
    CandyBar c{};

    cout << "Call the set function of Passing by pointer:" << endl;
    set(&c);
    cout << endl;

    cout << "Call the show function of Passing by pointer:" << endl;
    show(&c);
    cout << endl;

    cout << "Call the set function of Passing by reference:" << endl;
    set(c);
    cout << endl;

    cout << "Call the show function of Passing by reference:" << endl;
    show(c);

    return 0;
}