#include <iostream>

int main() {

    int x = 10;
    int y = 5;

    std::cout << "Result:" << std::endl;
    std::cout << "x value y value Expressions     Result" << std::endl;
    std::cout << x << " |    " << y << " |     x=y+3           |x=" << y + 3 << std::endl;
    std::cout << x << " |    " << y << " |     x=y-2           |x=" << y - 2 << std::endl;
    std::cout << x << " |    " << y << " |     x=y*5           |x=" << y * 5 << std::endl;
    std::cout << x << " |    " << y << " |     x=x/y3           |x=" << x / y << std::endl;
    std::cout << x << " |    " << y << " |     x=x%y3           |x=" << x % y << std::endl;

    return 0;
}
