#include <iostream>

using namespace std;

void turnLeft(int &x, int &y) {
    if (x == -1) {
        x = 0;
        y = 1;
    } else if (y == 1) {
        y = 0;
        x = 1;
    } else if (x == 1) {
        x = 0;
        y = -1;
    } else {
        y = 0;
        x = -1;
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    if (cin.fail() || n < 1 || m < 1) {
        cout << "error input, exit" << endl;
        return 0;
    }

    using line = int[m];

    int *arr = new int[n * m]();
    line *map = reinterpret_cast<line *>(arr);

    int x = m, y = 0;
    int dx = -1, dy = 0;

    for (int i = 1; i <= n * m; ++i) {
        x += dx, y += dy;
        map[y][x] = i;

        int nx = x + dx;
        int ny = y + dy;
        if (nx < 0 || nx >= m || ny < 0 || ny >= n || map[ny][nx] != 0) {
            turnLeft(dx, dy);
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int it = map[i][j];
            cout << it;
            int spaceCount = to_string(m * n).size() - to_string(it).size() + 1;
            for (int k = 0; k < spaceCount; ++k) {
                cout << " ";
            }
        }
        cout << endl;
    }

    return 0;

}