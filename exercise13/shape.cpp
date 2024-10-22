#include <iostream>
#include <math.h>

using namespace std;

class CStereoShape {
public:

    CStereoShape() {
        numberOfObject++;
    }

    virtual double GetArea() {
        cout << "CStereoShape :: GetArea()" << endl;
        return 0.0;
    }

    virtual double GetVolume() {
        cout << "CStereoShape :: GetVolume()" << endl;
        return 0.0;
    }

    virtual void Show() {
        cout << "CStereoShape :: Show()" << endl;
    }

    static int GetNumOfObject() {
        return numberOfObject;
    }

private:
    static int numberOfObject;
};

int CStereoShape::numberOfObject = 0;


class CCube : public CStereoShape {
public:
    double length;
    double width;
    double height;

    CCube() : length(0), width(0), height(0) {}

    CCube(double length, double width, double height)
            : length(length), width(width), height(height) {}

    CCube(const CCube &c) : length(c.length), width(c.width), height(c.height) {}

    double GetArea() override {
        return 2 * (length * width + length * height + width * height);
    }

    double GetVolume() override {
        return length * width * height;
    }

    void Show() override {
        cout << "CCube" << endl
             << "length: " << length << endl
             << "width: " << width << endl
             << "height: " << height << endl
             << "area: " << GetArea() << endl
             << "volume: " << GetVolume() << endl;
    }

};

class CSphere : public CStereoShape {
public:
    double radius;

    CSphere() : radius(0) {}

    CSphere(double radius) : radius(radius) {}

    CSphere(const CSphere &c) : radius(c.radius) {}

    double GetArea() override {
        return 4 * radius * radius * M_PI;
    }

    double GetVolume() override {
        return 4.0 / 3.0 * M_PI * radius * radius * radius;
    }

    void Show() override {
        cout << "CSphere" << endl
             << "radius: " << radius << endl
             << "area: " << GetArea() << endl
             << "volume: " << GetVolume() << endl;
    }

};