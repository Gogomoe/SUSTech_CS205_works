#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

struct Matrix {
    int m;
    int n;
    unsigned int **p; // assuming p is int[n][m], where n is rows, m is colunms
};

string encode(const Matrix &m);

Matrix decode(const string &s);

int main() {

    while (true) {
        cout << "input 0 to exit, 1 to encode matrix, 2 to decode matrix: ";
        int choose;
        cin >> choose;
        if (cin.fail() || choose < 0 || choose > 2) {
            cout << "input error, program exit" << endl;
            exit(1);
        }
        cin.ignore(1000, '\n');
        if (choose == 0) {
            break;
        }
        if (choose == 1) {
            cout << "input rows of matrix (n) : ";
            int n;
            cin >> n;
            if (cin.fail() || n <= 0) {
                cout << "input error, program exit" << endl;
                exit(1);
            }

            cout << "input columns of matrix (m) : ";
            int m;
            cin >> m;
            if (cin.fail() || m <= 0) {
                cout << "input error, program exit" << endl;
                exit(1);
            }

            Matrix mat{};
            mat.m = m;
            mat.n = n;
            mat.p = new unsigned int *[n];
            for (int i = 0; i < n; ++i) {
                mat.p[i] = new unsigned int[m];
            }

            cin.ignore(1000, '\n');
            cout << "input the matrix row by row" << endl;

            for (int j = 0; j < n; ++j) {
                string line;
                getline(cin, line);
                stringstream ss(line);
                for (int k = 0; k < m; ++k) {
                    unsigned int ceil_num;
                    ss >> ceil_num;
                    if (ceil_num > 1) {
                        cout << "input error, program exit" << endl;
                        exit(1);
                    }
                    if (j + k == 0 && ceil_num == 0) {
                        cout << "input error, the first number must be 1, program exit" << endl;
                        exit(1);
                    }
                    mat.p[j][k] = ceil_num;
                }
            }

            cout << "the encoding of matrix is: " << encode(mat) << endl;

        } else if (choose == 2) {
            cout << "input the encoding string of matrix: ";
            string matstr;
            getline(cin, matstr);

            Matrix mat = decode(matstr);
            for (int j = 0; j < mat.n; ++j) {
                for (int k = 0; k < mat.m; ++k) {
                    cout << mat.p[j][k] << " ";
                }
                cout << endl;
            }
        }
    }

    return 0;
}

string encode(const Matrix &mat) {

    int n = mat.n;
    int m = mat.m;

    stringstream s;
    s << n << "," << m;

    unsigned int type = 1;
    int count = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (mat.p[i][j] == type) {
                count++;
            } else {
                s << "," << count;

                type = 1 - type;
                count = 0;
            }
        }
    }
    s << "," << count;

    return s.str();
}

Matrix decode(const string &s) {
    stringstream ss(s);
    string token;

    getline(ss, token, ',');
    int n = stoi(token);
    getline(ss, token, ',');
    int m = stoi(token);

    Matrix mat{};
    mat.n = n;
    mat.m = m;
    mat.p = new unsigned int *[n];
    for (int i = 0; i < n; ++i) {
        mat.p[i] = new unsigned int[m];
    }

    unsigned int type = 1;
    int i = 0, j = 0;
    while (getline(ss, token, ',')) {
        int count = stoi(token);
        for (int k = 0; k < count; ++k) {
            mat.p[i][j] = type;

            i += (j == m - 1) ? 1 : 0;
            j = (j + 1) % m;
        }
        type = 1 - type;
    }

    return mat;
}