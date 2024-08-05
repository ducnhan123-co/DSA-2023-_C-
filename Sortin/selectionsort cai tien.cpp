#include<iostream>
#include<cmath>
using namespace std;

void selection_sort_cai_tien(int a[], int n) {
    int left = 0;
    int right = n - 1;

    while (left < right) {
        int min_index = left;
        int max_index = right;

        // Tìm phần tử nhỏ nhất và lớn nhất trong khoảng từ left đến right
        for (int i = left; i <= right; i++) {
            if (a[i] < a[min_index]) {
                min_index = i;
            }
            if (a[i] > a[max_index]) {
                max_index = i;
            }
        }

        // Đưa phần tử nhỏ nhất về đầu dãy
        swap(a[left], a[min_index]);

        // Kiểm tra nếu phần tử lớn nhất đã bị đổi chỗ
        if (max_index == left) {
            max_index = min_index;
        }

        // Đưa phần tử lớn nhất về cuối dãy
        swap(a[right], a[max_index]);

        // Thu hẹp phạm vi sắp xếp
        left++;
        right--;
    }
}


int main()
{
	int n;
	cout<<"Nhap n :";
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	selection_sort_cai_tien(a,n);
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	return 0;
}