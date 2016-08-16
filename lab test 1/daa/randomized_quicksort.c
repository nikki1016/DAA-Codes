#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void quick(int a[], int low, int up);
int partition(int a[], int low, int up);
//int partition_cormen(int a[], int low, int up);

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
	
	return 0;
}

void quick(int a[], int low, int up) {

	int pivloc;
	if (low >= up)
		return;
	pivloc = partition(a, low, up);
	quick(a, low, pivloc-1);
	quick(a, pivloc+1, up);
	//display(a, low, up);
}

void display(int a[], int low, int up) {
	int i;
	
	for (i = low; i <= up; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}

int partition(int a[], int low, int up) {
	time_t ti;
	int l;	
	int i, j, pivot, t;
//	int tim = 10;
	srand((unsigned)(&ti));
	l = (rand()%(up-low+1))+low;
	t=a[low];
	a[low]=a[l];
	a[l]=t;
	
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
}

/*int partition_cormen(int a[], int low, int up)
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
}*/
