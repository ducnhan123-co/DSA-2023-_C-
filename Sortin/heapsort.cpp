#include<iostream>
using namespace std;

void heapify(int a[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && a[left] > a[largest]) {
        largest = left;
    }
    if (right < n && a[right] > a[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(a[i], a[largest]);
        // Gọi đệ quy heapify trên cây con
        heapify(a, n, largest);
    }
}

void heap_sort(int a[], int n) {
    // Xây dựng heap tối đa
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(a, n, i);
    }
    // Trích xuất từng phần tử từ heap
    for (int i = n - 1; i >= 0; i--) {
        // Di chuyển nút gốc hiện tại đến cuối
        swap(a[0], a[i]);
        // Gọi heapify trên heap bị giảm
        heapify(a, i, 0);
    }
}

int main() {
    int n;
    cout << "Nhap n: ";
    cin >> n;
    int a[n];
    cout << "Nhap cac phan tu cua mang: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    heap_sort(a, n);
    cout << "Mang sau khi sap xep: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}

void heap_sort(int a[],int n)
{
	for(int i=n/2-1;i>=0;i--)
	{
		heapify(a,n,i);
	}
	for(int i=n-1;i>=0;i--)
	{
		swap(a[0],a[i]);
		heapify(a,i,0);
	}
}

void heapify(int a[],int n,int i)
{
	int largerst=i;
	int left=2*i+1;
	int right=2*i+2;
	while(left < n && a[left]>a[largest])
	{
		largest=left;
	}
	while(right<n && a[right]>a[largest])
	{
		largest=right;
	}
	if(largest !=i)
	{
		swap(a[largest],a[i]);
		heapify(a,n,largest);
	}
}