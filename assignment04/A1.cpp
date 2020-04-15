#include <iostream>
#include <vector>
#include <set>
#include <random>
#include <algorithm>
#include <fstream>

using namespace std;

struct Student {
    int sid;
    int labs[14];
};

const string save_file = "lab_records.csv"; // filename for Q3 to save

int readInt(int below, int upper);

int generateSID();

Student generateStudent();

int randomInt(int below, int upper);

using namespace std;

int main() {

    cout << "please input student count: ";

    // Q1 generate and print students

    int n = readInt(1, INT32_MAX);

    vector<Student> students{};

    for (int i = 0; i < n; ++i) {
        students.push_back(generateStudent());
    }

    for (auto &student : students) {
        cout << student.sid << ": ";

        cout << student.labs[0];

        for (int i = 1; i < 14; i++) {
            cout << ", " << student.labs[i];
        }

        cout << endl;
    }

    cout << endl;

    // Q2 output absent students

    cout << "following students was absent equal to or greater than twice" << endl;

    for (auto &student : students) {
        int absent_times = 0;
        for (auto &lab : student.labs) {
            if (lab == 0) {
                absent_times++;
            }
        }

        if (absent_times >= 2) {
            cout << student.sid << " is absent for " << absent_times << " times" << endl;
        }
    }

    cout << endl;

    // Q3 save csv

    ofstream fout(save_file);
    if (!fout.good()) {
        cout << "cannot save the file: " << save_file << endl;
        exit(0);
    }
    for (auto &student : students) {
        fout << student.sid << ",";
        fout << student.labs[0];

        for (int i = 1; i < 14; i++) {
            fout << "," << student.labs[i];
        }
        fout << endl;
    }

    fout.close();

    cout << "write file to " << save_file << " success" << endl;
    cout << endl;

    return 0;
}

Student generateStudent() {
    static set<int> sids{};

    Student s{};
    int sid = generateSID();
    while (sids.find(sid) != sids.end()) {
        sid = generateSID();
    }

    s.sid = sid;
    for (auto &lab : s.labs) {
        lab = randomInt(0, 5);
    }

    return s;
}

int randomInt(int below, int upper) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<> dis{};

    return below + dis(gen) % (upper - below + 1);
}

int generateSID() {
    int year = randomInt(2011, 2020);
    int num = randomInt(0, 9999);

    return year * 10000 + num;
}

int readInt(int below, int upper) {
    try {
        string input;
        cin >> input;
        int i = stoi(input);
        if (i < below || i > upper) {
            throw exception();
        }
        return i;
    } catch (const exception &e) {
        cout << "input error, program exit" << endl;
        exit(0);
    }
}
