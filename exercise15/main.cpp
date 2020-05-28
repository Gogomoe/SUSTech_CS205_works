#include <iostream>
#include <exception>

using namespace std;

class Exp : public exception {
public:
    string message;

    explicit Exp(string message) : message(std::move(message)) {}
};

void handleInput();

int main() {
    string line;
    cout << "please enter marks for 4 courses:";
    while (!cin.eof()) {
        try {
            handleInput();
        } catch (const Exp &e) {
            cerr << e.message << endl;
            cin.ignore(1000, '\n');
        }
        cout << "please enter marks for 4 courses:";
    }
    return 0;
}

void handleInput() {
    double sum = 0;
    for (int i = 1; i <= 4; ++i) {
        int it;
        cin >> it;
        if (it < 0 || it > 100) {
            throw Exp("The parameter" + to_string(i) +
                      " is " + to_string(it) +
                      " which out of range(0-100)");
        }
        sum += it;
    }
    cout << "The average of the four courses is " << sum / 4 << endl;
}
