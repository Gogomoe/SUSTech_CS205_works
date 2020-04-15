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
