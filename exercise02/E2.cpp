#include <iostream>

const int HOURS_PER_DAY = 24;
const int MINUTES_PER_HOUR = 60;
const int SECOND_PER_MINUTE = 60;

int main() {

    long long second;

    std::cout << "Enter the number of seconds:";
    std::cin >> second;
    std::cout << second << " seconds = "
              << second / HOURS_PER_DAY / MINUTES_PER_HOUR / SECOND_PER_MINUTE << " days, "
              << (second / MINUTES_PER_HOUR / SECOND_PER_MINUTE) % HOURS_PER_DAY << " hours, "
              << (second / SECOND_PER_MINUTE) % SECOND_PER_MINUTE << " minutes, "
              << second % SECOND_PER_MINUTE << " seconds "
              << std::endl;

}
