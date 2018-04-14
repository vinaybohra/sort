#include<stdio.h>
#include<stdlib.h>
void Swap(int *a,int c,int d)
{
	int x;
	x=a[c];
	a[c]=a[d];
	a[d]=x;
}
void QuickSort(int *a,int low,int high)
{
	int last,mid,i;
	if(low>high)
	return ;
	mid=(low+high)/2;
	Swap(a,low,mid);
	last=low;
	for(i=low+1;i<high;i++)
	{
		if(a[i]<a[low])
		{
			last=last+1;
			Swap(a,i,last);
		}
	}
	Swap(a,low,last);
	QuickSort(a,low,last-1);
	QuickSort(a,last+1,high);
}
int main()
{
	int i,a[1000000],n,low,last;
	printf("Enter the number of elements in the array\n");
	scanf("%d",&n);
	printf("Enter the elements\n");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	low=0;
	last=n;
	QuickSort(a,low,last);
	for(i=0;i<n;i++)
	printf("%d ",a[i]);
	printf("\n");
}
