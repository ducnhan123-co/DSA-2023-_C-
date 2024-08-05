#include<iostream>
using namespace std;

void quick_sort(int a[], int left ,int right)
{
	if(left <=right)
   {
   	  int pivot=a[(left+right)/2];
	   int i=left;
	   int j=right;
	   while(i<=j)
	   {
	   	while (a[i]<pivot)
	   	{
	   		i++;
		   }
		   while (a[j]>pivot)
		   {
		   	j--;
		   }
		
		if(i<=j)
		{
			swap(a[i],a[j]);
			i++;
			j--;
	}
		}
			   if(left <j)
			   {
			   	quick_sort(a,left,j);
			   }
			   if(i<right)
			   {
			   	quick_sort(a,i,right);
			   }
			      	
   	
   }
		
	
}
int main()
{
	int n;
	cout <<"nhap n :";
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
		for(int i=0;i<n;i++)
	{
		cout<<a[i];
	}
	quick_sort(a,0,n-1);
		for(int i=0;i<n;i++)
	{
		cout<<a[i];
	}
}