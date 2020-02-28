#include <iostream>

int main() {

    int second;

    std::cout << "Enter the number of seconds:";
    std::cin >> second;
    std::cout << second << " seconds = "
              << second / (3600 * 24) << " days, "
              << (second / 3600) % 24 << " hours, "
              << (second / 60) % 60 << " minutes, "
              << second % 60 << " seconds "
              << std::endl;

}
