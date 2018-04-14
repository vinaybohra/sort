#include<stdio.h>
#include<stdlib.h>
void Merge(int *a,int *l,int lc,int *r,int rc)
{
	int i,j,k;
	i=0;
	j=0;
	k=0;
	while(i<lc && j<rc)
	{
		if(l[i]<r[j])
		a[k++]=l[i++];
		else
		a[k++]=r[j++];
	}
	while(i<lc)
	a[k++]=l[i++];
	while(j<rc)
	a[k++]=r[j++];
}
void MergeSort(int *a,int n)
{
	int *l,*r,i,mid;
	if(n<2)
	return ;
	mid=n/2;
	l=(int*)malloc(mid*sizeof(int));
	r=(int*)malloc(mid*sizeof(int));
	for(i=0;i<mid;i++)
	l[i]=a[i];
	for(i=mid;i<n;i++)
	r[i-mid]=a[i];
	MergeSort(l,mid);
	MergeSort(r,n-mid);
	Merge(a,l,mid,r,n-mid);
	free(l);
	free(r);
}
int main()
{
	int i,a[1000000],n;
	printf("Enter the number of elements in the array\n");
	scanf("%d",&n);
	printf("Enter the elements\n");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	MergeSort(a,n);
	for(i=0;i<n;i++)
	printf("%d ",a[i]);
	printf("\n");
}
	
