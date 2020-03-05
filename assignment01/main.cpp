#include <iostream>
#include <string>
#include <cmath>

using std::string;
using std::cin;
using std::cout;
using std::endl;

double toRadians(double it);

string readString();

double readDouble(int start, int end);

int main() {

    cout << "The first city: ";
    string city1 = readString();

    cout << "The latitude and longitude of first city: ";
    double la1 = readDouble(-90, 90), lo1 = readDouble(-180, 180);

    double phi1 = toRadians(90 - la1);
    double theta1 = toRadians(lo1);

    cout << "The second city: ";
    string city2 = readString();

    cout << "The latitude and longitude of second city: ";
    double la2 = readDouble(-90, 90), lo2 = readDouble(-180, 180);

    double phi2 = toRadians(90 - la2);
    double theta2 = toRadians(lo2);

    double c = sin(phi1) * sin(phi2) * cos(theta1 - theta2) + cos(phi1) * cos(phi2);

    double result = 6371.0 * acos(c);
    cout << "The distance between " << city1 << " and " << city2 << " is " << result << " km" << endl;

    return 0;
}

double toRadians(double it) {
    return it / 180.0 * 3.1415926535;
}

double readDouble(int start, int end) {
    double num;
    cin >> num;

    if (cin.fail() || num < start || num > end) {
        cout << "number error, must in range [" << start << ", " << end << "]." << endl;
        cout << "program exit" << endl;
        exit(1);
    }

    return num;
}

string readString() {
    string it;
    cin >> it;
    for (char const &c: it) {
        if (!isalpha(c)) {
            cout << "string error, must in [A-Za-z]" << endl;
            cout << "program exit" << endl;
            exit(1);
        }
    }
    return it;
}
