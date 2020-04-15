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
