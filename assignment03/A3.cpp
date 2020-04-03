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

