# Assignment 02 Report

**Name:** 江川 (Jiang Chuan)

**SID**: 11811712

## Part1 - Analysis

design a function to read csv data, then ask user input city name and calc distance.

## Part2 - Code

```cpp
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <vector>
#include <cstring>
#include <algorithm>

#define MAX_NAME_LENGTH 35
#define MAX_ARRAY_SIZE 1000
#define DATA_CSV_FILE "world_cities.csv"

using std::string;
using std::cin;
using std::cout;
using std::vector;
using std::endl;

struct City {
    string name;
    string province;
    string country;
    double latitude;
    double longitude;
};

double toRadians(double it);

vector<City> readCSVFile(const string &filename);

bool readCity(const City **p, const vector<City> &cities);

double calcDistance(const City &c1, const City &c2);

int main() {
    vector<City> cities = readCSVFile(DATA_CSV_FILE);
    if (cities.empty()) {
        return 0;
    }

    while (true) {
        const City *c1 = nullptr, *c2 = nullptr;
        while (c1 == nullptr) {
            cout << "please input the first city name: ";
            if (!readCity(&c1, cities)) {
                return 0;
            }
        }
        while (c2 == nullptr) {
            cout << "please input the second city name: ";
            if (!readCity(&c2, cities)) {
                return 0;
            }
        }
        double distance = calcDistance(*c1, *c2);
        cout << "The distance between " << c1->name << " and " << c2->name
             << " is " << distance << "km" << endl;
    }

    return 0;
}

double calcDistance(const City &c1, const City &c2) {
    double la1 = c1.latitude, lo1 = c1.longitude;
    double phi1 = toRadians(90 - la1);
    double theta1 = toRadians(lo1);

    double la2 = c2.latitude, lo2 = c2.longitude;
    double phi2 = toRadians(90 - la2);
    double theta2 = toRadians(lo2);

    double c = sin(phi1) * sin(phi2) * cos(theta1 - theta2) + cos(phi1) * cos(phi2);

    double result = 6371.0 * acos(c);
    return result;
}

bool readCity(const City **p, const vector<City> &cities) {
    const City *res = nullptr;
    string s;
    getline(cin, s);
    std::transform(s.begin(), s.end(), s.begin(), ::toupper);

    if (s == "BYE") {
        return false;
    }
    if (s.size() < 3) {
        cout << "city name is too short" << endl;
        return true;
    }

    bool multipleCity = false;
    for (auto city = cities.begin(); city != cities.end(); city++) {
        if (city->name.rfind(s, 0) == 0) {
            if (res == nullptr) {
                res = &(*city);
            } else if (!multipleCity) {
                multipleCity = true;
                cout << "there exist multiple cities" << endl;
                cout << res->name << ", " << res->country << endl;
                cout << city->name << ", " << city->country << endl;
            } else {
                cout << city->name << ", " << city->country << endl;
            }
        }
    }

    if (multipleCity) {
        return true;
    }

    if (res == nullptr) {
        cout << "not found any city" << endl;
        return true;
    }

    *p = res;
    return true;

}

vector<City> readCSVFile(const string &filename) {
    vector<City> cities;

    std::ifstream file(filename);
    if (!file.good()) {
        cout << "cannot open the file: " << filename << endl;
        return cities;
    }

    int cnt = 0;
    string line;

    while (std::getline(file, line)) {

        if (cnt == MAX_ARRAY_SIZE) {
            cout << "cannot load the file into array with size " << MAX_ARRAY_SIZE << endl;
            return cities;
        }

        string delimiter = ",";
        size_t pos = 0;
        int column = 0;
        string token[5];

        while ((pos = line.find(delimiter)) != string::npos) {
            token[column++] = line.substr(0, pos);
            line.erase(0, pos + delimiter.length());
        }
        token[column] = line;

        cities.push_back(City{});
        City &city = cities[cnt];

        if (token[0].size() >= MAX_NAME_LENGTH || token[2].size() >= MAX_NAME_LENGTH) {
            cout << "cannot load the name into char array with size " << MAX_NAME_LENGTH << endl;
            return cities;
        }

        std::transform(token[0].begin(), token[0].end(), token[0].begin(), ::toupper);

        if (token[1].size() < MAX_NAME_LENGTH) {
            city.province = token[1];
        }

        city.name = token[0];
        city.country = token[2];
        city.latitude = std::stod(token[3]);
        city.longitude = std::stod(token[4]);

        cnt++;

    }

    return cities;
}

double toRadians(double it) {
    return it / 180.0 * 3.1415926535;
}
```

## Part 3 - Result & Verification


#### Test case #1:

input and output: 
```plain
please input the first city name: Beijing
please input the second city name: SHANGhai
The distance between BEIJING and SHANGHAI is 1071.29km
please input the first city name: BEIJING
please input the second city name: shenzhen
The distance between BEIJING and SHENZHEN is 1941.39km
please input the first city name: bye
```

#### Test case #2:

input and output:
```plain
please input the first city name: beij
please input the second city name: shang
The distance between BEIJING and SHANGHAI is 1071.29km
please input the first city name: cam
there exist multiple cities
CAMBRIDGE, United Kingdom
CAMPINA GRANDE, Brazil
CAMPINAS, Brazil
CAMPO GRANDE, Brazil
please input the first city name: abcd
not found any city
please input the first city name: bye
```

#### Test case #3:

input and output: 
```plain
cannot load the name into char array with size 25
```

```plain
cannot load the file into array with size 800
```

```plain
cannot open the file: world_cities.csv
```


## Part 4 - Difficulties & Solutions
NULL
