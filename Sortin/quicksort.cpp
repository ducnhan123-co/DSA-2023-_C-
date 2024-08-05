#include<iostream>
using namespace std;

void quick_sort(int a[], int left, int right) {
    if (left < right) { // Điều kiện dừng, chỉ tiếp tục nếu đoạn cần sắp xếp có nhiều hơn một phần tử
        int pivot = a[(left + right) / 2];
        int i = left;
        int j = right;
        while (i <= j) { // 3 cái while và cái if luôn(while tổng + 2 while nhỏ + if (đổi) và 2 if còn lại (ở ngoài while)
            while (a[i] < pivot) {
                i++;    
            }    
            while (a[j] > pivot) {
                j--;
            }
            if (i <= j) {
                swap(a[i], a[j]);
                i++;
                j--;
            }            
        }    
        // Đệ quy sắp xếp hai phần bên trái và bên phải
        if (left < j) {
            quick_sort(a, left, j);
        }
        if (i < right) { // Điều kiện chính xác để tránh so sánh dư thừa
            quick_sort(a, i, right);
        }
    }
}
//quick sort voi pivot la phan tu cuoi
int partition (int a[],int left,int right)
{
	int pivot = a[right];//dat phan tu cuoi
	int	pindex=left;//vi tri dau
	for(int i=0;i<right;i++)//chay tu vi tri dau toi cuoi
	{
		if(a[i]<=pivot)//neu thay a[i] nho hon bang pivot
		{
			swap(a[i],a[pindex]);//hoan vi
			pindex++;//tang cai pindex len
		}
	}
	swap(a[pindex],a[right]);//huan vi ataipindex voi phan tu cuoi cung de quoc pivot
	return pindex;//tra ve vi tri pindex
}

//quick sort voi pivot la phan tu dau 
int partition_2(int a[], int left, int right) {
    int pivot = a[left];//dat phan tu dau
    int i = left ;//co ca i theo doi dau
    int j = right;//co ca j theo doi cuoi ve

    while (i <= j) {
        while (i <= j && a[i] <= pivot) {
            i++;
        }
        while (i <= j && a[j] > pivot) {
            j--;
        }
        if (i < j) {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }
    swap(a[left], a[j]);
    return j;
}
void quick_sort_2(int a[],int left,int right)
{
	if(left<right)
	{
		int pivot=partition(a,left,right);
		quick_sort_2(a,left,pivot-1);
		quick_sort_2(a,pivot+1,right);
	}
}

void quick_sort_3(int a[],int left,int right)
{
	if(left<right)
	{
		int pivot=partition_2(a,left,right);
		quick_sort_3(a,left,pivot-1);
		quick_sort_3(a,pivot+1,right);
	}
}
int main() {
    int n;
    cin >> n;
    int* a = new int[n]; // Cấp phát động mảng
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    quick_sort(a, 0, n - 1);
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout<<endl;
    
    
    quick_sort_2(a,0,n-1);
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout<<endl;
    quick_sort_3(a,0,n-1);
     for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    delete[] a; // Giải phóng bộ nhớ đã cấp phát động
    return 0;
}
