# Assignment 01 Report

**Name:** 江川 (Jiang Chuan)

**SID**: 11811712

## Part1 - Analysis

Define some functions to handle input, then follow instructions to compute the result.

## Part2 - Code

```cpp
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

```

## Part 3 - Result & Verification


#### Test case #1:

input: 
```plain
The first city: Shenzhen
The latitude and longitude of first city: 22.55 114.1
The second city: Beijing
The latitude and longitude of second city: 39.9139 116.3917
```

output:
```plain
The distance between Shenzhen and Beijing is 1942.84 km
```

#### Test case #2:

input: 
```plain
The first city: Shenzhen
The latitude and longitude of first city: 100000 -2000
```

output:
```plain
number error, must in range [-90, 90].
program exit
```

#### Test case #3:

input: 
```plain
The first city: abc123
```

output:
```plain
string error, must in [A-Za-z]
program exit
```

## Part 4 - Difficulties & Solutions
NULL
