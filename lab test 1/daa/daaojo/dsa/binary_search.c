#include <stdio.h>

int binsearch(int a[], int n, int num);

int main () {
	int n, q, i, index, item;
	scanf("%d %d", &n, &q);
	int a[n];

	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	while (q--) {
		scanf("%d", &item);
		index = binsearch(a, n, item);
		printf("%d\n", index);
	}
	return 0;
}
int binsearch(int a[], int n, int item) {
	int low, up, mid;
	low = 0;
	up = n-1;
	while (low <= up) {
		mid = (low+up)/2;
		if (item < a[mid])
			up = mid-1;
		else if (item > a[mid]) 
			low = mid+1;
		else
			return mid;
	}
	return -1;
}

