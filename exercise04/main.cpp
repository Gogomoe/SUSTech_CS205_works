#include <iostream>

using std::string;
using std::cin;
using std::cout;
using std::endl;

struct Pizza {
    string company;
    double diameter{};
    double weight{};
};

struct CandyBar {
    string name;
    double weight;
    int calories;
};

void print_pizza(const Pizza &pizza);

void print_candybar(const CandyBar &bar);

void exercise01();

void exercise02();

void exercise03();

int main() {
    string _;
    exercise01();
    cout << endl;
    getline(cin, _);
    exercise02();
    cout << endl;
    getline(cin, _);
    exercise03();

    return 0;
}

void exercise01() {
    auto *pizza = new Pizza;
    cout << "Enter the company of the pizza : ";
    getline(cin, pizza->company);
    cout << "Enter the diameter of the pizza : ";
    cin >> pizza->diameter;
    cout << "Enter the weight of the pizza : ";
    cin >> pizza->weight;

    print_pizza(*pizza);
}

void exercise02() {
    CandyBar *candybar = new CandyBar;
    cout << "Enter brand name of a candy bar: ";
    getline(cin, candybar->name);
    cout << "Enter weight of the candy bar: ";
    cin >> candybar->weight;
    cout << "Enter calories (an integer value) in the candy bar: ";
    cin >> candybar->calories;

    print_candybar(*candybar);
}

void exercise03() {
    int nums[5];
    int *p = nums;

    cout << "Enter 5 integers: ";
    for (int i = 0; i < 5; ++i) {
        cin >> *p;
        p++;
    }

    p--;
    for (int i = 0; i < 5; ++i) {
        cout << *p << " ";
        p--;
    }
    cout << endl;
}

void print_pizza(const Pizza &pizza) {
    cout << "Company: " << pizza.company << endl
         << "Diameter: " << pizza.diameter << endl
         << "Weight: " << pizza.weight << endl;
}

void print_candybar(const CandyBar &it) {
    cout << "Brand: " << it.name << endl
         << "Weight: " << it.weight << endl
         << "Calorie: " << it.calories << endl;
}