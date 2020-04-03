#include <iostream>

using namespace std;


int Fill_array(double arr[], int size) {
    cout << "Enter the size of the array:";
    int act;
    cin >> act;

    if (act > size) {
        cout << "cannot save so much number input, only " << size << " numbers";
    }

    for (int i = 0; i < min(act, size); ++i) {
        cout << "Enter value #" << i << ": ";
        cin >> arr[i];
    }

    return min(act, size);
}

void Show_Array(double *arr, int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void Reverse_array(double *arr, int size) {
    if (size <= 1) {
        return;
    }
    double tmp = arr[0];
    arr[0] = arr[size - 1];
    arr[size - 1] = tmp;
    Reverse_array(arr + 1, size - 2);
}

int main() {
    double arr[20];
    int size = Fill_array(arr, 20);
    Show_Array(arr, size);

    Reverse_array(arr, size);
    Show_Array(arr, size);


    Reverse_array(arr + 1, size - 2);
    Show_Array(arr, size);
}