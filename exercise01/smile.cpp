#include <iostream>

void smile() {
    std::cout << "Smile!";
}

int main() {

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3 - i; ++j) {
            smile();
        }
        std::cout << std::endl;
    }

    return 0;
}
