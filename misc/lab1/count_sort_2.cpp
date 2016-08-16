#include <stdio.h>

void counting_sort(int a[], int b[], int n, int k);

int main()
{
	int i, n, k;
	//printf("Enter the no of elements in the array: ");
	scanf("%d", &n);
	int a[n], b[n];
	
	//printf("Enter the elements: \n");
	for (i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	
	//printf("Enter the value of k: ");
	scanf("%d", &k);
	
	
	counting_sort(a, b, n, 99);
	
	//printf("The sorted array: \n");
	for (i = 1; i <= n; i++) {
		printf("%d ", b[i]);
	}
	printf("\n");
	
	return 0;
	
}

void counting_sort(int a[], int b[], int n, int k)
{
	int i;
	int c[k+1];
	
	for (i = 0; i <= k; i++) {
		c[i] = 0;
	}
	
	for (i = 1; i <= n; i++) {
		c[a[i]] = c[a[i]] + 1;
	}
	
	for (i = 1; i <= k; i++) {
		c[i] = c[i] + c[i-1];
	}
	
	for (i = n; i >= 1; i--) {
		b[c[a[i]]] = a[i];
		c[a[i]] = c[a[i]] - 1;
	}
}
