#include <iostream>

using std::string;
using std::cin;
using std::cout;
using std::endl;

struct CandyBar {
    string name;
    double weight;
    int calories;
};

void exercise01();

void exercise02();

void exercise03();

void print_candybar(CandyBar &bar);

int main() {
    exercise01();
    cout << endl;
    exercise02();
    cout << endl;
    exercise03();
    cout << endl;

    return 0;
}

void exercise01() {
    CandyBar snack{
            "Mocha Munch",
            2.3,
            350
    };
    print_candybar(snack);

}

void exercise02() {
    CandyBar candybar;
    cout << "Enter brand name of a candy bar: ";
    getline(cin, candybar.name);
    cout << "Enter weight of the candy bar: ";
    cin >> candybar.weight;
    cout << "Enter calories (an integer value) in the candy bar: ";
    cin >> candybar.calories;
    print_candybar(candybar);
}

void exercise03() {
    CandyBar candyBars[] = {
            {"A", 1.0, 210},
            {"B", 1.2, 250},
            {"C", 1.4, 290}
    };
    print_candybar(candyBars[0]);
    print_candybar(candyBars[1]);
    print_candybar(candyBars[2]);
}

void print_candybar(CandyBar &it) {
    cout << "Brand: " << it.name << endl
         << "Weight: " << it.weight << endl
         << "Calorie: " << it.calories << endl;
}