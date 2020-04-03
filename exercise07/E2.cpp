#include <iostream>
#include <cstring>

using namespace std;

struct box {
    char maker[40];
    float height;
    float width;
    float length;
    float volume;
};


void setVolume(box *b) {
    b->volume = b->width * b->height * b->length;
}

void printBox(const box b) {
    cout << "maker: " << b.maker << endl
         << "width: " << b.width << endl
         << "height: " << b.height << endl
         << "length: " << b.length << endl
         << "volume: " << b.volume << endl;
}

int main() {
    box b{};

    strcpy(b.maker, "A.B.");
    b.width = 3.2;
    b.height = 4.5;
    b.length = 5;

    cout << "Before setting volume:" << endl;
    printBox(b);

    setVolume(&b);
    cout << "After setting volume:" << endl;
    printBox(b);
}