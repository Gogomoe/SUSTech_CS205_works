#include <iostream>
#include <cstring>

using std::string;
using std::cin;
using std::cout;
using std::endl;

void exercise01();

void exercise02();

void exercise03();

void exercise04();

int main() {
    string _;
    exercise01();
    cout << endl;
    cin.ignore(1000, '\n');
    exercise02();
    cout << endl;
    cin.ignore(1000, '\n');
    exercise03();
    cout << endl;
    cin.ignore(1000, '\n');
    exercise04();

    return 0;
}

void exercise01() {
    int c;
    int sum = 0;
    do {
        cout << "Enter integer number: ";
        cin >> c;
        sum += c;
        cout << "The cumulative sum of the entries to data is :" << sum << endl;
    } while (c != 0);
}

void exercise02() {
    cout << "Enter words (to stop, type the word done):" << endl;
    int count = 0;
    char str[100];
    do {
        cin >> str;
        count++;
    } while (strcmp(str, "done") != 0);
    cout << "You entered a total of " << (count - 1) << " words." << endl;
}

void exercise03() {
    cout << "Enter a positive number" << endl;
    int c;
    cin >> c;
    cout << "Fibonacci Series: 0 ";
    int a = 0;
    int b = 1;
    while (b <= c) {
        cout << b << " ";
        int temp = a;
        a = b;
        b = temp + b;
    }
    cout << endl;
}

void exercise04() {
    for (int i = 1; i <= 7; ++i) {
        for (int j = 1; j <= 7; ++j) {
            if (j <= i) {
                cout << j;
            } else {
                cout << "*";
            }
        }
        cout << endl;
    }

}