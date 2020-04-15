# Assignment 04 Report

**Name:** 江川 (Jiang Chuan)

**SID**: 11811712

## Part1 - Analysis

following instructions to finish some functions and programs.

## Part2 - Code

```cpp
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

```

```cpp
#include <iostream>
#include <vector>
#include <set>
#include <random>
#include <algorithm>
#include <fstream>

using namespace std;

const string read_file = "lab_records.csv"; // filename for Q4 to read

using namespace std;

int main() {

    // Q4 read file and calculate low score lab

    ifstream fin(read_file);
    if (!fin.good()) {
        cout << "cannot open the file: " << read_file << endl;
        exit(0);
    }

    string line;
    int student_count = 0;
    int lab_scores[15]{};
    int total_score = 0;

    while (getline(fin, line)) {
        size_t pos = 0;
        string delimiter = ",";
        int column = 0;
        string token[15];

        while ((pos = line.find(delimiter)) != string::npos) {
            token[column++] = line.substr(0, pos);
            line.erase(0, pos + delimiter.length());
        }
        token[column] = line;

        student_count++;
        for (int i = 1; i <= 14; ++i) {
            int it_score = stoi(token[i]);
            lab_scores[i] += it_score;
            total_score += it_score;
        }
    }
    fin.close();

    double total_average = ((double) total_score) / student_count / 14;

    cout << "follow labs has lower average scores, less than " << total_average << endl;

    for (int i = 1; i <= 14; ++i) {
        double average = ((double) lab_scores[i]) / student_count;
        if (average < total_average) {
            cout << "lab" << i << " for average score " << average << endl;
        }
    }
    cout << endl;


    return 0;
}

```

```cpp
#include <iostream>

using namespace std;

int index_of(string *start, string *end, const string &toSearch);

int main() {

    string commands[] = {"start", "stop", "restart", "reload", "status", "exit"};

    string input;
    while (true) {
        cout << "> ";
        getline(cin, input);
        int index = index_of(begin(commands), end(commands), input);
        switch (index) {
            case 5:
                cout << "program exit" << endl;
                return 0;
            case -1:
                cout << "Invalid command" << endl;
                break;
            default:
                cout << "command " << input << " recognized" << endl;
                break;
        }
    }

}

int index_of(string *start, string *end, const string &toSearch) {
    int i = 0;
    while (start != end) {
        if (*start == toSearch) {
            return i;
        }
        i++;
        start++;
    }
    return -1;
}

```

## Part 3 - Result & Verification


#### Test case #1:

input and output: 
```plain
please input student count: 10
20179665: 2, 1, 4, 0, 1, 1, 5, 5, 3, 5, 2, 0, 2, 2
20194252: 5, 3, 2, 5, 3, 3, 1, 3, 2, 3, 2, 3, 2, 4
20115722: 4, 0, 4, 4, 2, 5, 2, 1, 2, 1, 2, 2, 2, 1
20134688: 3, 0, 4, 1, 2, 3, 1, 5, 3, 0, 3, 0, 5, 5
20122222: 5, 3, 5, 1, 4, 2, 4, 5, 0, 0, 5, 5, 2, 3
20120055: 4, 2, 4, 4, 1, 1, 4, 4, 0, 1, 2, 2, 5, 0
20132626: 0, 1, 5, 4, 5, 5, 3, 0, 1, 4, 2, 1, 3, 2
20203621: 4, 3, 4, 0, 5, 4, 5, 5, 0, 0, 3, 0, 5, 5
20187140: 2, 4, 1, 5, 3, 2, 1, 5, 5, 4, 1, 1, 0, 1
20204831: 5, 0, 5, 4, 1, 0, 1, 0, 5, 5, 1, 5, 3, 0

following students was absent equal to or greater than twice
20179665 is absent for 2 times
20134688 is absent for 3 times
20122222 is absent for 2 times
20120055 is absent for 2 times
20132626 is absent for 2 times
20203621 is absent for 4 times
20204831 is absent for 4 times

write file to lab_records.csv success


```

#### Test case #2:

input and output:
```plain
follow labs has lower average scores, less than 2.62857
lab2 for average score 1.7
lab6 for average score 2.6
lab9 for average score 2.1
lab10 for average score 2.3
lab11 for average score 2.3
lab12 for average score 1.9
lab14 for average score 2.3
```

#### Test case #3:

input and output: 
```plain
> start
command start recognized
> restart
command restart recognized
> stop
command stop recognized
> status
command status recognized
> ssssss
Invalid command
> 123 456
Invalid command
> exop
Invalid command
> stop
command stop recognized
> exit
program exit
```

## Part 4 - Difficulties & Solutions

nullptr