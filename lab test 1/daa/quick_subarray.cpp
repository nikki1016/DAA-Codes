#include <stdio.h>
#include <math.h>

void quick(int a[], int low, int up, int n);
int partition(int a[], int low, int up);
int partition_cormen(int a[], int low, int up);
void display(int a[], int n);
 
int a[5001];

int main() {

	int i, n;
	scanf("%d", &n);
	
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	quick(a, 0, n-1, n);
	
	/*for (i = 0; i < n; i++) {
		printf("%d\n", a[i]);
	}*/
	
	return 0;
}

void quick(int a[], int low, int up, int n) {

	int pivloc;
	if (low >= up)
		return;
	pivloc = partition_cormen(a, low, up);
	display(a, n);
	quick(a, low, pivloc-1, n);
	quick(a, pivloc+1, up, n);
}

void display(int a[], int n) {
	int i;
	
	for (i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
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
		}
	}
	a[up] = a[i+1];
	a[i+1] = pivot;
	
	return (i+1);
}
