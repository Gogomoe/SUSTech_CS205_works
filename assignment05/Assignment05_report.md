# Assignment 05 Report

**Name:** 江川 (Jiang Chuan)

**SID**: 11811712

## Part1 - Analysis

Define some a class and some function to finish the target.

## Part2 - Code

UTF8string.hpp

```cpp
#include <iostream>
#include <vector>

class UTF8string {

    friend std::ostream &operator<<(std::ostream &out, const UTF8string &str);

    friend UTF8string operator+(const UTF8string &u1, const UTF8string &u2);

    friend UTF8string &operator+=(UTF8string &u1, const UTF8string &u2);

    friend UTF8string operator*(const UTF8string &str, size_t times);

    friend UTF8string operator*(size_t times, const UTF8string &str);

    friend UTF8string operator!(const UTF8string &str);


private:
    std::string str;

public:

    UTF8string(const std::string &s) : str(s) {};

    UTF8string(const char *s) : str(s) {};

    size_t length() const;

    size_t bytes() const;

    size_t find(const std::string &to_find) const;

    void replace(const UTF8string &to_remove, const UTF8string &replacement);

    std::vector<unsigned int> codepoints() const;

};
```

UTF8string.cpp

```cpp
#include "UTF8string.hpp"
#include "utf8.h"
#include <string>
#include <vector>
#include <memory>
#include <algorithm>

size_t UTF8string::length() const {
    return utf8_charlen((unsigned char *) str.c_str());
}

size_t UTF8string::bytes() const {
    return str.length();
}

size_t UTF8string::find(const std::string &to_find) const {
    std::vector<unsigned int> vec1 = codepoints();
    std::vector<unsigned int> vec2 = UTF8string(to_find).codepoints();
    auto res = std::search(vec1.begin(), vec1.end(), vec2.begin(), vec2.end());
    return res == vec1.end() ? -1 : res - vec1.begin();
}

void UTF8string::replace(const UTF8string &to_remove, const UTF8string &replacement) {
    const std::string &from = to_remove.str;
    const std::string &to = replacement.str;

    size_t start_pos = str.find(from);
    while (start_pos != std::string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos = str.find(from);
    }
}

std::ostream &operator<<(std::ostream &out, const UTF8string &str) {
    return out << str.str;
}

UTF8string operator+(const UTF8string &u1, const UTF8string &u2) {
    return u1.str + u2.str;
}

UTF8string &operator+=(UTF8string &u1, const UTF8string &u2) {
    u1.str.append(u2.str);
    return u1;
}

UTF8string operator*(const UTF8string &str, size_t times) {
    std::string s;
    while (times-- > 0) {
        s.append(str.str);
    }
    return s;
}

UTF8string operator*(size_t times, const UTF8string &str) {
    return str * times;
}

UTF8string operator!(const UTF8string &str) {
    std::vector<unsigned int> vec = str.codepoints();

    std::unique_ptr<unsigned char[]> res_ptr =
            std::unique_ptr<unsigned char[]>(new unsigned char[str.str.length() + 1]);

    unsigned char *res = res_ptr.get();
    unsigned char *end = res + str.str.length();

    while (res != end) {
        unsigned int cp = vec.back();
        vec.pop_back();
        codepoint_to_utf8(cp, res);
        while (*res != 0) {
            res++;
        }
    }

    return UTF8string(std::string(reinterpret_cast<const char *>(res_ptr.get())));
}

std::vector<unsigned int> UTF8string::codepoints() const {
    std::vector<unsigned int> vec;
    unsigned char *src_str = (unsigned char *) str.c_str();
    unsigned char *u = src_str;
    int len;
    while (*u != 0) {
        vec.push_back(utf8_to_codepoint(u, &len));
        u += len;
    }
    return vec;
}
```

## Part 3 - Result & Verification


#### Test case #1:

output:

```plain
test contains: Mais où sont les neiges d'antan?
length in bytes of test: 33
number of characters (one 2-byte character): 32
position of "sont": 8
test2 before replacement: Всё хорошо́, что хорошо́ конча́ется
test2 after replacement: Всё просто, что просто конча́ется
test + test2: Mais où sont les neiges d'antan?Всё просто, что просто конча́ется
Appending !!! to test
Result: Mais où sont les neiges d'antan?!!!
Testing operator *: hip hip hip hurray
Testing operator !: Никола́й Васи́льевич Го́голь -> ьлоѓоГ чивеьл́исаВ й́алокиН

```

## Part 4 - Difficulties & Solutions

NULL
