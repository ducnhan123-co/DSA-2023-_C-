#include <iostream>
using namespace std;

void insertion_sort(int a[], int n) {
    for (int i = 1; i < n; i++) {
        int vitri = i - 1;
        int giatri = a[i];
        while (vitri >= 0 && a[vitri] < giatri) { // Sắp xếp giảm dần
            a[vitri + 1] = a[vitri];
            vitri--;
        }
        a[vitri + 1] = giatri;
    }
}

void insertion_sort_2(int b[][100], int d, int c) {
    int k = d * c;
    int a[k];
    int index = 0;
    
    // Chuyển đổi mảng 2 chiều thành mảng 1 chiều
    for (int i = 0; i < d; i++) {
        for (int j = 0; j < c; j++) {
            a[index] = b[i][j];
            index++;
        }
    }

    // Sắp xếp mảng 1 chiều theo thứ tự giảm dần bằng thuật toán sắp xếp chèn
    for (int i = 1; i < k; i++) {
        int giatri = a[i];
        int vitri = i - 1;
        while (vitri >= 0 && a[vitri] < giatri) { // Sắp xếp giảm dần
            a[vitri + 1] = a[vitri];
            vitri--;
        }
        a[vitri + 1] = giatri;
    }

    // Chuyển đổi mảng 1 chiều đã sắp xếp trở lại thành mảng 2 chiều
    index = 0;
    for (int i = 0; i < d; i++) {
        for (int j = 0; j < c; j++) {
            b[i][j] = a[index];
            index++;
        }
    }
}

void sap_xep_mang_2_chieu_insertion_sort(int a[][],int m,int n)
{
	for(int i=0;i<m;i+=)
	{
		for(int j=1;j<n;j++)
		{
			int vitri=j-1;
			int giatri=a[i][j];
			while(vitri>=0 && a[i][vitri]<giatri)
			{
				a[i][vitri+1]=a[i][j];
				vitri--;
			}
			a[i][vitri+1]=giatri;
		}
	}
}

int find_min(int a[][],int m,int n)
{
	int min=a[0][n-1];
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(a[i][j]<min)
			{
				min=a[i][j];
			}
		}
	}
	return min;
}

int main() {
    int n;
    cout << "Nhap so phan tu mang 1 chieu: ";
    cin >> n;
    int a[n];
    cout << "Nhap cac phan tu cua mang 1 chieu: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    insertion_sort(a, n);
    cout << "Mang 1 chieu sau khi sap xep: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    int b[100][100];
    int d, c;
    cout << "Nhap so dong: ";
    cin >> d;
    cout << "Nhap so cot: ";
    cin >> c;
    cout << "Nhap cac phan tu cua mang 2 chieu: ";
    for (int i = 0; i < d; i++) {
        for (int j = 0; j < c; j++) {
            cin >> b[i][j];
        }
    }
    
    cout << "Mang 2 chieu truoc khi sap xep: " << endl;
    for (int i = 0; i < d; i++) {
        for (int j = 0; j < c; j++) {
            cout << b[i][j] << " ";
        }
        cout << endl;
    }

    insertion_sort_2(b, d, c);

    cout << "Mang 2 chieu sau khi sap xep: " << endl;
    for (int i = 0; i < d; i++) {
        for (int j = 0; j < c; j++) {
            cout << b[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
