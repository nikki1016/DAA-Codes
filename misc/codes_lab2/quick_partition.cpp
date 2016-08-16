#include<stdio.h>

int a[1001];
int size;

int quick(int a[],int size)
{
	int i, j,k,l,r,pivot;
	int left[1001];
	int right[1001];
	
	if(size <= 1)
	{
		return size;
	}	
	
	pivot = a[0];
	j = 0;
	k = 0;
	for(i = 1; i < size; i++)
	{
		if (a[i] <= pivot) {
            left[j++] = a[i] ;
        } 
		else {
            right[k++] = a[i];
        }
	}
	
	l = quick(left,j);
	r = quick(right,k);
	
	left[j++] = pivot;
	for(i = 0;i < k; i++)
	{
		left[j++] = right[i];
	}
	for(i = 0; i < j; i++)
	{
		a[i] = left[i];
		printf("%d ",a[i]);
	}
	printf("\n");
	
	return l;
}

int main()
{
	int n,m;
	scanf("%d",&n);
	for(m = 0; m < n; m++)
	{
		scanf("%d",&a[m]);
	}
	quick(a,n);
	return 0;
}
