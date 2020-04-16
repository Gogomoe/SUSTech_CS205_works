#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct BookRecording {
    string name;
    string id;
    vector<int> books;
};

double calc_cost(const BookRecording &recording);

int main() {
    cout << "Please input the number of students: ";
    int student_count;
    cin >> student_count;
    if (cin.fail() || student_count < 0) {
        cout << "input error, program exit" << endl;
        exit(1);
    }

    cin.ignore(1000, '\n');

    vector<BookRecording> students;

    for (int student_i = 0; student_i < student_count; ++student_i) {
        BookRecording b;

        cout << "Please input the name of student: ";
        string name;
        getline(cin, name);
        b.name = name;

        cout << "Please input the student ID of this student: ";
        string id;
        getline(cin, id);
        b.id = id;

        cout << "Number of books this student borrowed: ";
        int number;
        cin >> number;
        if (cin.fail() || number < 0) {
            cout << "input error, program exit" << endl;
            exit(1);
        }
        cin.ignore(1000, '\n');

        if (number > 0) {
            cout << "The borrowing days are: ";
            for (int i = 0; i < number; ++i) {
                int num;
                cin >> num;
                if (cin.fail() || num < 0) {
                    cout << "input error, program exit" << endl;
                    exit(1);
                }
                b.books.push_back(num);
            }
            cin.ignore(1000, '\n');
        }

        students.push_back(b);


        double cost = calc_cost(b);

        cout << "If this student returns all the books today, he should pay: " << cost << " RMB." << endl;
        cout << endl;
    }

    return 0;
}

double calc_cost(const BookRecording &recording) {
    double cost = 0;
    for (auto day : recording.books) {
        if (day <= 30) {
            continue;
        }
        cost += max(min(day - 30, 30) * 0.5, 0.0);
        cost += max((day - 60) * 1.0, 0.0);
    }
    return cost;
}
