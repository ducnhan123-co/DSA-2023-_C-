#include<iostream>
using namespace std;

void merge(int a[],int left,int mid ,int right)
{
	int n1=mid-left+1;
	int n2=right-mid;
	
	int L[n1];
	int R[n2];
	for(int i=0;i<n1;i++)
	{
		L[i]=a[left+i];
	}
	for(int j=0;j<n2;j++)
	{
		R[j]=a[mid+j+1];
	}
	
	int i=0;
	int j=0;
	int k=left;
	//1 cái while thui + 1 + 1
	while(i<n1 && j<n2)
	{
		if(L[i]<R[j])
		{
			a[k++]=L[i++];
		}
		else
		{
			a[k++]=R[j++];
		}
}
	while(i<n1)
	{
		a[k++]=L[i++];
	}
	while (j<n2)
	{
		a[k++]=R[j++];
	}

	
}
void merge_sort(int a[],int left,int right)
{
	if(left<right)
	{
		int m=(left+right)/2;
		merge_sort(a,left,m);
		merge_sort(a,m+1,right);
		merge(a,left,m,right);
	}
	
}
int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	merge_sort(a,0,n-1);
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
}
