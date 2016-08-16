#include<stdio.h>
void merge_sort(int a[],int size);
void mergepass(int a[],int temp[],int size,int n);
void merge(int a[],int temp[],int low1,int up1,int low2,int up2);
void copy(int a[],int temp[],int size);
int main()
{
	int i, n;
	printf("enter no. of elements to be sorted : ");
	scanf("%d" , &n);
	int a[n];
	for(i = 0; i < n; i++)
	{
		scanf("%d" , &a[i]);
	}
	merge_sort(a,n);
	printf("sorted list is : ");
	for(i = 0; i < n; i++)
	{
		printf("%d " , a[i]);
	}
	printf("\n");
	return 0;
}
void merge_sort(int a[],int n)
{
	int temp[50];
	int size =1;
	while(size < n)
	{
		mergepass(a,temp,size,n);
		size = size * 2;
	}

}
void mergepass(int a[],int t[],int size,int n)
{
	int low1,up1,low2,up2;
	low1 = 0;
	while(low1+size<n){
		up1 = low1+size-1;
		low2= up1+1;
		up2 = low2+size -1;
		if(up2>=n){
			up2 = n-1;
		}
		merge(a,t,low1,up1,low2,up2);
		low1=up2+1;
	}
	int i;
	for(i=low1;i<n;i++){
		t[i]=a[i];
	}
	copy(a,t,n);
}
void merge(int a[],int temp[],int low1,int up1,int low2,int up2)
{
	int i = low1;
	int j = low2;
	int k = low1;
	while((i <= up1) && (j <= up2))
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

void copy(int a[],int temp[],int size)
{
	int i;
	for (i = 0 ; i < size; i++)
	{
		a[i] = temp[i];
	}

}



