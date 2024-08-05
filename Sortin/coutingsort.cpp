#include<iostream>
#include<limits.h>
using namespace std;
void input(int a[],int &n,int &max)
{
	do
	{
		cout<<"Nhap so luong phan tu cua mang : ";
		cin>>n;
	}while(n<=0 || n>100);
	
	max=INT_MIN;
	
	for(int i=0;i<n;i++)
	{
		cout<<"Nhap a["<< i<<"] = ";
		cin>>a[i];
		if(max < a[i])
		max=a[i];
	}
}
void output(int a[],int n)
{
	cout<<"Mang dang luu tru :\n";
	for(int i=0;i<n;i++)
	{
		cout<<"a["<<i <<"] = "<<a[i]<<endl;
	}
}
void countingSort(int a[], int b[], int n, int k)
{
    // Bu?c 1: T?o và kh?i t?o m?ng d?m `c` v?i kích thu?c `k+1`
    int *c = new int[k+1];
    for (int i = 0; i <= k; i++)
    {
        c[i] = 0; // Kh?i t?o t?t c? các ph?n t? c?a `c` b?ng 0
    }

    // Bu?c 2: Ð?m s? lu?ng m?i ph?n t? trong m?ng `a`
    for (int i = 0; i < n; i++)
    {
        c[a[i]]++; // Tang giá tr? d?m tuong ?ng v?i giá tr? `a[i]`
    }

    // Bu?c 3: S?p x?p các ph?n t? vào m?ng `b` d?a trên m?ng d?m `c`
    int j = 0;
    for (int i = 0; i <= k; i++)
    {
        while (c[i] > 0)
        {
            b[j++] = i; // Ð?t giá tr? `i` vào v? trí ti?p theo trong m?ng `b`
            c[i]--;    // Gi?m s? lu?ng d?m
        }
    }

    // Gi?i phóng b? nh? dã c?p phát cho m?ng d?m `c`
    delete[] c;
}
/*
a = [4, 2, 2, 8, 3, 3, 1]

Bu?c 1: Kh?i t?o m?ng d?m c

css
Copy code
c = [0, 0, 0, 0, 0, 0, 0, 0, 0]
Bu?c 2: Ð?m s? lu?ng m?i ph?n t? trong a

css
Copy code
a[0] = 4 => c[4] += 1 => c = [0, 0, 0, 0, 1, 0, 0, 0, 0]
a[1] = 2 => c[2] += 1 => c = [0, 0, 1, 0, 1, 0, 0, 0, 0]
a[2] = 2 => c[2] += 1 => c = [0, 0, 2, 0, 1, 0, 0, 0, 0]
a[3] = 8 => c[8] += 1 => c = [0, 0, 2, 0, 1, 0, 0, 0, 1]
a[4] = 3 => c[3] += 1 => c = [0, 0, 2, 1, 1, 0, 0, 0, 1]
a[5] = 3 => c[3] += 1 => c = [0, 0, 2, 2, 1, 0, 0, 0, 1]
a[6] = 1 => c[1] += 1 => c = [0, 1, 2, 2, 1, 0, 0, 0, 1]
Bu?c 3: S?p x?p các ph?n t? vào m?ng b

css
Copy code
b = []
c[1] > 0 => b = [1], c[1] -= 1 => c = [0, 0, 2, 2, 1, 0, 0, 0, 1]
c[2] > 0 => b = [1, 2], c[2] -= 1 => c = [0, 0, 1, 2, 1, 0, 0, 0, 1]
c[2] > 0 => b = [1, 2, 2], c[2] -= 1 => c = [0, 0, 0, 2, 1, 0, 0, 0, 1]
c[3] > 0 => b = [1, 2, 2, 3], c[3] -= 1 => c = [0, 0, 0, 1, 1, 0, 0, 0, 1]
c[3] > 0 => b = [1, 2, 2, 3, 3], c[3] -= 1 => c = [0, 0, 0, 0, 1, 0, 0, 0, 1]
c[4] > 0 => b = [1, 2, 2, 3, 3, 4], c[4] -= 1 => c = [0, 0, 0, 0, 0, 0, 0, 0, 1]
c[8] > 0 => b = [1, 2, 2, 3, 3, 4, 8], c[8] -= 1 => c = [0, 0, 0, 0, 0, 0, 0, 0, 0]
K?t qu? cu?i cùng: b = [1, 2, 2, 3, 3, 4, 8]

i = 0: c[0] = 0, không có ph?n t? 0 trong m?ng g?c.
i = 1: c[1] = 1, có m?t ph?n t? 1 trong m?ng g?c:
b[0] = 1
j tang lên 1, c[1] gi?m xu?ng 0
i = 2: c[2] = 2, có hai ph?n t? 2 trong m?ng g?c:
b[1] = 2
b[2] = 2
j tang lên 3, c[2] gi?m xu?ng 0
i = 3: c[3] = 2, có hai ph?n t? 3 trong m?ng g?c:
b[3] = 3
b[4] = 3
j tang lên 5, c[3] gi?m xu?ng 0
i = 4: c[4] = 1, có m?t ph?n t? 4 trong m?ng g?c:
b[5] = 4
j tang lên 6, c[4] gi?m xu?ng 0
i = 5 d?n i = 7: c[5] = 0, c[6] = 0, c[7] = 0, không có ph?n t? 5, 6, ho?c 7 trong m?ng g?c.
i = 8: c[8] = 1, có m?t ph?n t? 8 trong m?ng g?c:
b[6] = 8
j tang lên 7, c[8] gi?m xu?ng 0
Cu?i cùng, m?ng b s? là: [1, 2, 2, 3, 3, 4, 8], dây là m?ng dã du?c s?p x?p t? m?ng g?c a.
*/





int main()
{
	int a[100],n,k;
	int b[100];
	input(a,n,k);
	output(a,n);
	countingSort(a,b,n,k);
		output(b,n);

	
}
