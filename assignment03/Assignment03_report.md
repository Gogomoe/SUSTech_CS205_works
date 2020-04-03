# Assignment 03 Report

**Name:** 江川 (Jiang Chuan)

**SID**: 11811712

## Part1 - Analysis

design a function to read csv data, then ask user input city name and calc distance.

## Part2 - Code

```cpp
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
```

```cpp
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
```

```cpp
#include <iostream>
#include <algorithm>
#include <cctype>
#include <vector>
#include <fstream>
#include <map>
#include "utf8.c"

using namespace std;

const string BLOCKS_FILE = "Blocks.txt";

//trim source from stackoverflow
static inline void ltrim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](int ch) {
        return !std::isspace(ch);
    }));
}

static inline void rtrim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), [](int ch) {
        return !std::isspace(ch);
    }).base(), s.end());
}

static inline void trim(std::string &s) {
    ltrim(s);
    rtrim(s);
}

int utf8_char_length(unsigned char c) {
    int len = -1;
    if (c < 0xc0) {
        len = 1;
    } else if ((c & 0xe0u) == 0xc0) {
        len = 2;
    } else if ((c & 0xf0u) == 0xe0) {
        len = 3;
    } else if ((c & 0xf8u) == 0xf0) {
        len = 4;
    }
    return len;
}

struct utf8_block {
    string name;
    unsigned int start;
    unsigned int end;
    unsigned int char_count = 0;
};

vector<utf8_block> &read_utf8_blocks(const string filename) {
    ifstream file(filename);
    if (!file.good()) {
        cout << "cannot open the file: " << filename << endl;
        exit(1);
    }

    vector<utf8_block> &blocks = *(new vector<utf8_block>());

    string line;

    while (getline(file, line)) {
        trim(line);
        if (line.empty() || line[0] == '#') {
            continue;
        }
        utf8_block block = utf8_block{};

        int dots = line.find('.');
        int semicolon = line.find(';');

        block.start = stoi(line.substr(0, dots), nullptr, 16);
        block.end = stoi(line.substr(dots + 2, semicolon - dots - 2), nullptr, 16);
        block.name = line.substr(semicolon + 2);

//        cout << block.start << "-" << block.end << " " << block.name << endl;

        blocks.push_back(block);
    }

    return blocks;
}

int main() {

    vector<utf8_block> &blocks = read_utf8_blocks(BLOCKS_FILE);

    unsigned char chars[10] = {};
    char first;
    int char_len = 0;
    while ((first = cin.get()) != char_traits<char>::eof()) {
        char_len = utf8_char_length(first);

        chars[0] = first;
        for (int i = 1; i < char_len; ++i) {
            chars[i] = cin.get();
        }
        unsigned int code = utf8_to_codepoint(chars, &char_len);
//        cout << code << "  " << char_len << endl;

        for (auto &block:blocks) {
            if (code >= block.start && code <= block.end) {
                block.char_count++;
            }
        }

        for (int i = 0; i < char_len; ++i) {
            chars[i] = 0;
        }
    }

    auto *max = &(blocks[0]);
    for (auto &block:blocks) {
        if (block.char_count > max->char_count){
            max = &block;
        }
    }

    cout << max->name << " with " << max->char_count << " chars" << endl;

    return 0;

}


```

## Part 3 - Result & Verification


#### Test case #1:

input and output: 
```plain
3 4 5
1 1 1 -1
1 1 -1 1
0 3 1 0
0 2 1 0
0 0 -1 -1
3
```

#### Test case #2:

input and output:
```plain
5 3
3  2  1  
4  13 12 
5  14 11 
6  15 10 
7  8  9  
```

#### Test case #3:

input and output: 
```plain
4 4
4  3  2  1  
5  14 13 12 
6  15 16 11 
7  8  9  10 
```

#### Test case #4:

input and output: 
```plain
../cmake-build-debug/assignment03_A3 < "TEST DATA FOR LAB 4"/sample.txt
Armenian with 3230 chars
```

#### Test case #5:

input and output: 
```plain
../cmake-build-debug/assignment03_A3 < "TEST DATA FOR LAB 4"/sample2.txt
Georgian with 1127 chars
```


## Part 4 - Difficulties & Solutions

nullptr