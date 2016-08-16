#include<stdio.h>
void merge_sort(int a[],int low,int up);
void merge(int a[],int temp[],int low1,int up1,int low2,int up2);
void copy(int a[],int temp[],int low,int up);
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
	merge_sort(a,0,n-1);
	printf("sorted list is : ");
	for(i = 0; i < n; i++)
	{
		printf("%d " , a[i]);
	}
	printf("\n");
	return 0;
}
void merge_sort(int a[],int low,int up)
{
	int mid;
	int temp[50];
	if(low < up)
	{
		mid = (low + up)/2;
		merge_sort(a,low,mid);
		merge_sort(a,mid+1,up);
		merge(a,temp,low,mid,mid+1,up);
		copy(a,temp,low,up);
	}

}
int merge(int a[],int temp[],int low1,int up1,int low2,int up2)
{	int invct=0;
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
			invct = invct + (low2-i);
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
	return invct;
}

void copy(int a[],int temp[],int low,int up)
{
	int i;
	for (i = low ; i < up; i++)
	{
		a[i] = temp[i];
	}

}



