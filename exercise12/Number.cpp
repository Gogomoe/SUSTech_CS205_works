#include <iostream>

class Number {
private:
    int num;
public:
    Number() : num(0) {}

    Number(int n) : num(n) {}

    Number operator++() {
        num++;
        return *this;

    }

    Number operator--() {
        num--;
        return *this;
    }


    Number operator++(int) {
        Number copy = *this;
        ++(*this);
        return copy;
    }

    Number operator--(int) {
        Number copy = *this;
        --(*this);
        return copy;
    }

    friend std::ostream &operator<<(std::ostream &out, const Number &n) {
        out << n.num;
        return out;
    }
};