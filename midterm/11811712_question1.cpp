#include <iostream>
#include <map>
#include <string>

using namespace std;

int evaluate(const char *s, const int k);


int main() {
    cout << "input the text, use enter to finish a input" << endl;

    string line;
    getline(cin, line);

    bool last_is_space = false;
    for (char const &c: line) {
        if (!(('a' <= c && c <= 'z') || c == ' ')) {
            cout << "input contains not lowercase letters or space, program exit" << endl;
            exit(1);
        }

        if (c == ' ' && last_is_space) {
            cout << "input contains more than 1 space,  program exit" << endl;
            exit(1);
        }

        last_is_space = c == ' ';
    }

    std::cout << "input the k, a positive integer: ";

    int k;
    cin >> k;

    if (cin.fail() || k <= 0) {
        cout << "input error, exit" << endl;
        exit(1);
    }

    int result = evaluate(line.c_str(), k);

    if (result == 1) {
        cout << "good lyrics" << endl;
    } else {
        cout << "not good lyrics" << endl;
    }

    return 0;
}

int evaluate(const char *s, const int k) {

    map<string, int> counts;

    if (*s == ' ') { // skip if there is a blank before all words
        s++;
    }

    const char *start = s;
    int len = 0;

    while (*s != 0) {
        if (*s == ' ') {
            string str;

            while (start != s) {
                str.push_back(*start);
                start++;
            }

            if (counts.find(str) == counts.end()) {
                counts.insert(pair<string, int>(str, 0));
            }

            counts.find(str)->second++;

            len = 0;
            start = s + 1;

        } else {
            len++;
        }
        s++;

    }

    // add the last word
    if (len > 0) {
        string str;

        while (start != s) {
            str.push_back(*start);
            start++;
        }

        if (counts.find(str) == counts.end()) {
            counts.insert(pair<string, int>(str, 0));
        }

        counts.find(str)->second++;
    }

    // max count

    int max_count = 0;
    for (auto &it: counts) {
        max_count = max(max_count, it.second);
//        cout << it.first << ": " << it.second << endl;
    }

    return max_count >= k ? 1 : 0;

}