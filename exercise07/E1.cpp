#include <iostream>

void displaymenu();

using namespace std;

void displaymenu() {
    cout << "=====================================" << endl
         << "                MENU              " << endl
         << "=====================================" << endl
         << "   1.Add" << endl
         << "   2.Subtract" << endl
         << "   3.Multiply" << endl
         << "   4.Divide" << endl
         << "   5.Modulus" << endl;
}

int main(int argc, char *argv[]) {
    //show menu
    displaymenu();
    int yourchoice;
    int a;
    int b;
    char confirm;
    {
        cout << "Enter your choice(1-5):";
        cin >> yourchoice;
        cout << "Enter your two integer numbers:";
        cin >> a >> b;
        cout << "\n";
        switch (yourchoice) {
            case 1:
                cout << "Result: " << a + b << endl;
                break;
            case 2:
                cout << "Result: " << a - b << endl;
                break;
            case 3:
                cout << "Result: " << a * b << endl;
                break;
            case 4:
                cout << "Result: " << a / b << endl;
                break;
            case 5:
                cout << "Result: " << a % b << endl;
                break;
        }
        cout << "\nPress y or Y to continue:";
        cin >> confirm;
    }
    while (confirm == 'y' || confirm == 'Y');
    return EXIT_SUCCESS;
}