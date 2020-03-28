#include <iostream>

using namespace std;

int main() {
    int quiz, midterm, final;
    cout << "please input quiz score: ";
    cin >> quiz;
    cout << "please input midterm score: ";
    cin >> midterm;
    cout << "please input final score: ";
    cin >> final;

    double average = (quiz + midterm + final) / 3.0;

    if (average >= 90) {
        cout << "grade A" << endl;
    } else if (average >= 70) {
        cout << "grade B" << endl;
    } else if (average >= 50) {
        cout << "grade C" << endl;
    } else {
        cout << "grade F" << endl;
    }

    return 0;

}