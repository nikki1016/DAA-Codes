#include <stdio.h>
#include <math.h>

void quick(int a[], int low, int up,int size);
int partition_cormen(int a[], int low, int up);
int n;
int main() {

	int  i,s;
	scanf("%d", &n);
	scanf("%d",&s);
	int a[n];
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	quick(a, 0, n-1,s);
	
	for (i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
	return 0;
}

void quick(int a[], int low, int up,int k) 
{
	int p,i;
	if (low >= up)
		return;
	p = partition_cormen(a, low, up);
	if((n-k) == p)
	{
		printf("%d is %d largest number\n",a[n-k],k);
	}
	else if((k-1) < p)
	{
		quick(a, low, p-1,k);
	}
	else if((k-1) > p)
	{
	quick(a, p+1, up,k);
	}
}

int partition_cormen(int a[], int low, int up)
{
	int i, j, pivot, temp;
	pivot = a[up];
	i = low-1;
	
	for (j = low; j <= (up-1); j++) {
		if (a[j] <= pivot) {
			i = i+1;
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
	}
	a[up] = a[i+1];
	a[i+1] = pivot;
	
	return (i+1);
}
