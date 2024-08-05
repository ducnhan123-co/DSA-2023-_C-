#include <iostream>
using namespace std;

// Hàm tìm giá tr? l?n nh?t trong m?ng
int getMax(int a[], int n)
{
    int max = a[0];
    for (int i = 1; i < n; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
        }
    }
    return max;
}

// Hàm th?c hi?n Counting Sort theo ch? s? hi?n t?i (du?c xác d?nh b?i exp)
void countSort(int a[], int n, int exp)
{
    int output[n]; // M?ng k?t qu? t?m th?i
    int count[10] = {0}; // M?ng d?m cho các ch? s? (0-9)

    // Bu?c 1: Ð?m s? lu?ng các ch? s? xu?t hi?n
    for (int i = 0; i < n; i++)
    {
        count[(a[i] / exp) % 10]++;
    }

    // Bu?c 2: Thay d?i count[i] d? ch?a v? trí th?c c?a ch? s? này trong output
    for (int i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }

    // Bu?c 3: Xây d?ng m?ng output
    for (int i = n - 1; i >= 0; i--)
    {
        int index = (a[i] / exp) % 10;
        output[count[index] - 1] = a[i];
        count[index]--;
    }

    // Bu?c 4: Sao chép m?ng output tr? l?i m?ng a
    for (int i = 0; i < n; i++)
    {
        a[i] = output[i];
    }
}

// Hàm th?c hi?n Radix Sort
void radixsort(int a[], int n)
{
    // Bu?c 1: Tìm s? l?n nh?t d? bi?t s? lu?ng ch? s?
    int m = getMax(a, n);

    // Bu?c 2: S? d?ng Counting Sort cho t?ng ch? s?, t? don v? d?n ch? s? l?n nh?t
    for (int exp = 1; m / exp > 0; exp *= 10)
    {
        countSort(a, n, exp);
    }
}

// Hàm chính d? ki?m tra Radix Sort
int main()
{
    int a[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(a) / sizeof(a[0]);

    cout << "Mang ban dau: ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    radixsort(a, n);

    cout << "Mang sau khi sap xep: ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}

