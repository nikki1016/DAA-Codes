#include <stdio.h>
#include <math.h>

void quick(int a[], int low, int up);
int partition(int a[], int low, int up);

int ctr = 0;

int main() {

	int n, i;
	scanf("%d", &n);
	
	int a[n];
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	quick(a, 0, n-1);
	
	for (i = 0; i < n; i++) {
		printf("%d\n", a[i]);
	}
	printf("%d\n", ctr);
	
	return 0;
}

void quick(int a[], int low, int up) {

	int pivloc;
	if (low >= up)
		return;
	pivloc = partition(a, low, up);
	quick(a, low, pivloc-1);
	quick(a, pivloc+1, up);
}

int partition(int a[], int low, int up) {

	int i, j, pivot, t;
	i = low;
	j = up-1;
	pivot = a[up];
	while (i <= j) {
		while ((a[i] < pivot) && (i < up))
			i++;
		while (a[j] > pivot) 
			j--;
		if (i < j) {
			ctr++;
			t = a[i];
			a[i] = a[j];
			a[j] = t;
			i++;
			j--;
		}
		else 
			i++;
	}
	a[up] = a[j];
	a[j] = pivot;
	ctr++;
	return j;
}


