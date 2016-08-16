#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int a[100000];
void quick(int a[], int low, int up, int x);
int partition(int a[], int low, int up);
clock_t start,end;

void bubblesort(int a[],int low, int up)
{
	int i,j,excg,t;

	for (i = low; i < up+1; i++) {
		excg = 0;
		for (j = 0; j < up; j++) {
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
	time_t seconds;
	int n, i,j;
	double diff;
	n=100000;
	int x;
	for(i=1;i<=50;i++){
	x=i;
	srand((unsigned) &seconds);
	for (j = 0; j < n; j++){
	a[i]= rand()%107;
	}
	start=clock();
	quick(a, 0, n-1,x);
	end =clock();
	diff=(double)((end-start));
	printf("%d %0.0lf\n",x,diff);
	}
	return 0;
}

void quick(int a[], int low, int up, int x) {

	int pivloc;
	if (low >= up)
		return;
	pivloc = partition(a, low, up);
	if ((pivloc - low - 1) > x)
		quick(a, low, pivloc-1, x);
	else
		bubblesort(a, low, pivloc-1);
	if ((up - pivloc - 1) > x)
		quick(a, pivloc+1, up, x);
	else
		bubblesort(a, pivloc+1, up);
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

