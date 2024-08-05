#include<iostream>
#include<cmath>
#include<limits.h>
using namespace std;

void selection_sort(int a[100],int n)
{
	for(int i=0;i<n-1;i++)
	{
		int vtmin=i;
		for(int j=i+1;j<n;j++)
		{
			if(a[j]<a[vtmin])
			{
				vtmin=j;
			}
		}
		if(vtmin!=i)
		{
			swap(a[i],a[vtmin]);	
		}
	}
}
void selection_sort_dequy(int a[100],int n,int index=0)

{
	if(n<=1) return ;
	int min_index=index;
	for(int j=index+1;j<n;j++)
	{
		if(a[j]<a[min_index])
		{
			min_index=j;
		}
	}
	if(min_index!=index)
	{
		swap(a[index],a[min_index]);
	}
	selection_sort_dequy(a,n,index+1);
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
	
	selection_sort(a,n);
	
	
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}

	// Khởi tạo giá trị cho biến index
	int index = 0;
	
	selection_sort_dequy(a,n,index);
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
}
