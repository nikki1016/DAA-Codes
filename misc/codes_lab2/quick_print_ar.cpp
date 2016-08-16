#include <stdio.h>
#include <math.h>

void quick(int a[], int low, int up,int size);
int partition_cormen(int a[], int low, int up);
void display (int a[], int up);
int main() {

	int n, i;
	scanf("%d", &n);
	
	int a[n];
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	quick(a, 0, n-1,n);
	
	/*for (i = 0; i < n; i++) {
		printf("%d\n", a[i]);
	}*/
	
	return 0;
}

void quick(int a[], int low, int up,int size) 
{
	int pivloc,i;
	if (low >= up)
		return;
	pivloc = partition_cormen(a, low, up);
	display(a,size);
	quick(a, low, pivloc-1,size);
	quick(a, pivloc+1, up,size);
}

void display(int a[], int size) {
	int i;
	
	for (i = 0; i < size; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
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
