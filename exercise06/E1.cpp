#include <iostream>

using namespace std;

int main() {
    char c;
    cin >> c;

    switch (tolower(c)) {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            cout << "vowel" << endl;
            break;
        default:
            cout << "consonant" << endl;
            break;
    }
    return 0;
}