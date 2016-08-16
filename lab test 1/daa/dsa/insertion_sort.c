#include <stdio.h>

int main() {
	int a[30];
	int i;
	int j;
	int k;
	int n;

	printf("Enter the size(<31) of an array : ");
	scanf("%d" , &n);

	printf("\n ENTER THE ELEMENTS OF AN ARRAY\n");

	for(i =0; i <n; i++)
		scanf("%d" , &a[i]);

	for(i = 0 ; i <n; i++) {
		k = a[i];
		for(j =  i-1; j >= 0 && k < a[j]; j--) {
			a[j+1] = a[j];
			a[j] = k;

		}
	}

	for ( i = 0; i<n ; i++ ) {
		printf("%d \t", a[i]);
	}
	return 0;
}

