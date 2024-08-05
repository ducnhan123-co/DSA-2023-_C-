//test 
#include <iostream>
using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int partition(int a[], int left, int right) {
    int pivot = a[left]; // Chọn phần tử đầu tiên làm pivot
    int pindex = left + 1; // Chỉ số lưu trữ

    for (int i = pindex; i <= right; ++i) {
        if (a[i] <= pivot) {
            swap(a[i], a[pindex]); // Hoán đổi arr[i] với arr[pindex]
            ++pindex; // Tăng chỉ số lưu trữ
        }
    }
    swap(a[left], a[pindex - 1]); // Hoán đổi pivot với phần tử cuối cùng nhỏ hơn pivot
    return pindex - 1; // Trả về vị trí mới của pivot
}

void quickSort(int a[], int left, int right) {
    if (left < right) {
        int pivotIndex = partition(a, left, right);
        quickSort(a, left, pivotIndex - 1); // Sắp xếp phần bên trái của pivot
        quickSort(a, pivotIndex + 1, right); // Sắp xếp phần bên phải của pivot
    }
}

void printArray(int a[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main() {
    int a[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(a) / sizeof(a[0]);
    quickSort(a, 0, n - 1);
    cout << "Sorted array: ";
    printArray(a, n);
    return 0;
}
