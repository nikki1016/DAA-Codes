#include <stdio.h>

void counting_sort(int a[], int b[], int n, int k);

int main()
{
	int i, n, k;
	scanf("%d", &n);
	int a[n], c[100];
	char str[100];
	
	for (i = 0; i < n; i++) {
		scanf("%d %s", &a[i], str);
		
	}
	
	for (i = 0; i <= 99; i++) {
		c[i] = 0;
	}
	
	for (i = 0; i < n; i++) {
		c[a[i]] = c[a[i]] + 1;
	}
	
	for (i = 1; i <= 99; i++) {
		c[i] = c[i] + c[i-1];
	}
	
	for (i = 0; i <= 99 ; i++) {
		printf("%d ", c[i]);
	}
	
	return 0;
}
	
	
