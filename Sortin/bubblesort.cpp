#include<iostream>
using namespace std;
void bubble_sort(int a[],int &n)
{
	for(int i=0;i<n-1;i++)
	{
		for(int j=n-1;j>i;j--)
		{
			if(a[j-1]>a[j])
			{
				swap(a[j-1],a[j]);
			}
		}
	}
}
void bubble_sort_2(int a[],int &n)
{
	for(int i=0;i<n-1;i++)
	{
		for(int j=n-1;j>i;j--)
		{
			if(a[j+1]<a[j])
			{
				swap(a[j+1],a[j]);
			}
		}
	}
}

void bubble_sort_2d(int b[][100],int rows,int cols)
{
	//sap xep tang dan theo hang
	for(int i=0;i<rows;i++)
	{
		bubble_sort(b[i],cols);
	}
}
int main()
{
	int n;
	cout <<"Nhap kich thuoc mang 1 chieu n ";
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	bubble_sort(a,n);

	cout <<"Sau khi sap xep : ";
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
	
int rows, cols;
cout<<"Nhap so dong va cot : ";
    cin >> rows >> cols;
    int b[100][100]; // Giả sử kích thước tối đa của mảng 2 chiều là 100x100

    // Nhập mảng 2 chiều
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            cin >> b[i][j];
        }
    }

    // Sắp xếp từng hàng của mảng 2 chiều
    bubble_sort_2d(b, rows, cols);
cout <<"Mang 2 chieu sau sap xep : ";
    // Xuất mảng 2 chiều đã sắp xếp
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            cout << b[i][j] << " ";
        }
        cout << endl;
    }
}