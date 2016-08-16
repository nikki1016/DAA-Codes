#include <stdio.h>
#include <math.h>

void quick(int a[], int low, int up);
int partition_cormen(int a[], int low, int up);
void insertion(int a[], int n);
 
int a[1001];
int b[1001];
int ctr = 0;
int c = 0;

int main() {

	int i, n;
	scanf("%d", &n);
	
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		b[i] = a[i];
	}
	quick(a, 0, n-1);
	insertion(b, n);
	
	printf("%d\n", c-ctr);
	
	return 0;
}

void quick(int a[], int low, int up) {

	int pivloc;
	if (low >= up)
		return;
	pivloc = partition_cormen(a, low, up);
	quick(a, low, pivloc-1);
	quick(a, pivloc+1, up);
}

/*int partition(int a[], int low, int up) {

	int i, j, pivot, t;
	i = low+1;
	j = up;
	pivot = a[low];
	while (i <= j) {
		while ((a[i] < pivot) && (i < up))
			i++;
		while (a[j] > pivot) 
			j--;
		if (i < j) {
			t = a[i];
			a[i] = a[j];
			a[j] = t;
			i++;
			j--;
		}
		else 
			i++;
	}
	a[low] = a[j];
	a[j] = pivot;
	return j;
}*/

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
			ctr++;
		}
	}
	a[up] = a[i+1];
	a[i+1] = pivot;
	ctr++;
	
	return (i+1);
}

void insertion(int a[], int n)
{
	int i, j, key;
	
	for (j = 1; j < n; j++) {
		key = a[j];
			
		i = j-1;
		while (i >= 0 && a[i] > key) {
			a[i+1] = a[i];
			c++;
			i = i-1;
		}
		a[i+1] = key;
	}
}
