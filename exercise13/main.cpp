#include <iostream>
#include "shape.cpp"

using namespace std;

int main() {

    CCube cube(4.0, 5.0, 6.0);
    CSphere sphere(7.9);

    CStereoShape *p;

    p = &cube;
    p->Show();

    cout << endl;

    p = &sphere;
    p->Show();

    cout << endl;

    cout << "num of obj: " << CStereoShape::GetNumOfObject() << endl;

    return 0;
}
