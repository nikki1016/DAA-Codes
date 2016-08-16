#include<stdio.h>

void merge(int a[],int temp [],int low1,int up1,int low2,int up2)
{
	int i = low1;
	int j = low2;
	int k = low1;
	while(i <= up1&&j <= up2)
	{
		if(a[i] <= a[j])
		{
			temp[k++] = a[i++];
		}
		else {
			temp[k++] = a[j++];
		}
	}
	while(i <= up1)
	{
		temp[k++] = a[i++];
	}
	while(j <= up2)
	{
		temp[k++] = a[j++];
	}
}
void copy(int a[],int temp[],int n)
{
	int i;
	for(i = 0;i < n; i++)
	{
		a[i] = temp[i];
	}
}
void mergepass(int a[],int temp[],int size,int n)
{
	int low1,low2,up1,up2,i;
	low1 = 0;
	while(low1+size < n)
	{
		up1 = low1+size - 1;
		low2 = low1+size;
		up2 = low2+size-1;
		if(up2 >= n)
		{
			up2 = n-1;
		}
		merge(a,temp,low1,up1,low2,up2);
		low1 = up2+1;
	}
	for(i = low1; i <= n-1; i++)
	{
		temp[i] = a[i];
	}
	copy(a,temp,n);
}
void merge_sort(int a[],int n)
{
	int temp[100];
	int size = 1;
	while(size < n)
	{
		mergepass(a,temp,size,n);
		size = size*2;
	}
}

int main()
{
	int a[100],i,n;
	printf("Enter the number of elements:\n");
	scanf("%d",&n);
	printf("Enter the elements\n");
	for(i = 0; i < n; i++)
	{
		scanf("%d",&a[i]);
	}
	merge_sort(a,n);
	printf("Sorted List is:\n");
	for(i = 0; i < n; i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
	return 0;
}
