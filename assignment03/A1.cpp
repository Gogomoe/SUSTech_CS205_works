#include <iostream>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    if (cin.fail() || n < 1 || m < 1 || k < 0) {
        cout << "error input, exit" << endl;
        return 0;
    }

    using line = int[n];

    int *arr = new int[n * m]();
    line *map = reinterpret_cast<line *>(arr);


    for (int i = 0; i < k; ++i) {
        int x, y, dx, dy;
        cin >> x >> y >> dx >> dy;

        if (cin.fail()) {
            cout << "error input, exit" << endl;
            return 0;
        }
        if (x < 0 || x >= n || y < 0 || y >= m) {
            cout << "bullet not in screen, exit" << endl;
            return 0;
        }

        if (abs(dx) > 1 || abs(dy) > 1) {
            cout << "direction error, exit" << endl;
            return 0;
        }

        while ((x >= 0 && x < n) && (y >= 0 && y < m)) {
            map[y][x] = 1;
            x += dx;
            y += dy;
        }
    }

    int count = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (map[i][j] == 0) {
                count++;
            }
        }
    }

    cout << count;

    return 0;

}