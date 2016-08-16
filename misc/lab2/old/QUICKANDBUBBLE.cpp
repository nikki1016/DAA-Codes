#include <stdio.h>
#include <math.h>

int a[10000];

void quick(int a[], int low, int up);
int partition(int a[], int low, int up);

void bubblesort(int a[],int n)
{
	int i,j,excg,t;

	for (i = 0; i < n; i++) {
		excg = 0;
		for (j = 0; j < n - 1; j++) {
			if (a[j] > a[j + 1]) {	
				t = a[j];
				a[j] = a[j + 1];
				a[j + 1] = t;
				excg++;
			}
		}
		if (excg == 0)
			break;
	}
}

int main() {

	int n, i;
	//scanf("%d", &n);
	n=10000;
	
	for (i = 0; i < n; i++) {
		//a[i]=3*(1000-i);
	}
	quick(a, 0, n-1);
	
	/*for (i = 0; i < n; i++) {
		printf("%d\n", a[i]);
	}*/
	
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


