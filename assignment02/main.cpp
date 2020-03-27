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

vector<const City *> toSelect{};

double toRadians(double it);

vector<City> readCSVFile(const string &filename);

bool readCity(const City **p, const vector<City> &cities);

double calcDistance(const City &c1, const City &c2);

bool is_number(const std::string &s);

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
    string s;
    getline(cin, s);
    std::transform(s.begin(), s.end(), s.begin(), ::toupper);

    if (s == "BYE") {
        return false;
    }
    if (is_number(s) && !cities.empty()) {
        int num = std::stoi(s);
        if (num < 0 || num >= toSelect.size()) {
            cout << "please enter a correct number" << endl;
            return true;
        }
        *p = toSelect[num];
        toSelect.clear();
        return true;
    }

    if (s.size() < 3) {
        cout << "city name is too short" << endl;
        return true;
    }

    toSelect.clear();
    for (auto city = cities.begin(); city != cities.end(); city++) {
        if (city->name.rfind(s, 0) == 0) {
            if (toSelect.size() == 1) {
                cout << "there exist multiple cities, you can input number as city name" << endl;
                cout << "0. " << toSelect[0]->name << ", " << toSelect[0]->country << endl;
                cout << "1. " << city->name << ", " << city->country << endl;
            } else if (toSelect.size() > 1) {
                cout << toSelect.size() << ". " << city->name << ", " << city->country << endl;
            }
            toSelect.push_back(&*city);

        }
    }

    if (toSelect.size() >= 2) {
        return true;
    }

    if (toSelect.empty()) {
        cout << "not found any city" << endl;
        return true;
    }

    *p = toSelect[0];
    return true;

}

vector<City> readCSVFile(const string &filename) {
    vector<City> cities;

    std::ifstream file(filename);
    if (!file.good()) {
        cout << "cannot open the file: " << filename << endl;
        return cities;
    }

    int lineCnt = 1;
    string line;

    while (std::getline(file, line)) {

        if (cities.size() == MAX_ARRAY_SIZE) {
            cout << "the file is larger than " << MAX_ARRAY_SIZE << " lines, skip remaining lines" << endl;
            break;
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


        if (token[0].size() >= MAX_NAME_LENGTH || token[2].size() >= MAX_NAME_LENGTH) {
            cout << lineCnt << ": cannot load the name into char array with size " << MAX_NAME_LENGTH
                 << ", skip the line" << endl;
        }

        std::transform(token[0].begin(), token[0].end(), token[0].begin(), ::toupper);

        City city = City{};

        if (token[1].size() < MAX_NAME_LENGTH) {
            city.province = token[1];
        }

        city.name = token[0];
        city.country = token[2];
        city.latitude = std::stod(token[3]);
        city.longitude = std::stod(token[4]);

        cities.push_back(city);

        lineCnt++;

    }

    return cities;
}

double toRadians(double it) {
    return it / 180.0 * 3.1415926535;
}

bool is_number(const std::string &s) {
    return !s.empty() && std::find_if(
            s.begin(), s.end(),
            [](unsigned char c) { return !std::isdigit(c); }
    ) == s.end();
}