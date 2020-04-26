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