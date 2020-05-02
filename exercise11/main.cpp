#include <iostream>

using namespace std;

class CandyBar {
private:
    string name;
    double weight;
    int calories;
public:
    void setCandyBar() {
        cout << "Enter brand name of a Candy bar: ";
        cin >> name;
        cout << "Enter weight of the candy bar: ";
        cin >> weight;
        cout << "Enter calories (an integer value) in the candy bar: ";
        cin >> calories;
    }

    void showCandyBar() {
        cout << "Brand: " << name << endl;
        cout << "Weight: " << weight << endl;
        cout << "Calorie: " << calories << endl;
    }
};

class Rectangle {
private:
    double width;
    double height;
public:
    Rectangle() : width(1), height(1) {}

    Rectangle(double width, double height) : width(width), height(height) {}

    double getArea() {
        return width * height;
    }

    double getPerimeter() {
        return 2 * width + 2 * height;
    }

    void display() {
        cout << "Width:     " << width << endl;
        cout << "Height:    " << height << endl;
        cout << "Area:      " << this->getArea() << endl;
        cout << "Perimeter: " << this->getPerimeter() << endl;
    }
};

int main() {

    CandyBar candybar{};
    candybar.setCandyBar();
    candybar.showCandyBar();

    Rectangle r1(4, 40);
    Rectangle r2(3.5, 35.9);

    cout << "Rectangle1" << endl;
    cout << "------------" << endl;
    r1.display();

    cout << "Rectangle2" << endl;
    cout << "------------" << endl;
    r2.display();

    return 0;
}
