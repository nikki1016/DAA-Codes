#include <stdio.h>

int main()
{
	int n, i, j, t, min;

	printf("Enter the no of elements in the array: ");
	scanf("%d", &n);

	int arr[n];

	for (i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	for (i = 0; i < n-1; i++) {
		min = i;

		for (j = i+1; j < n; j++) {
			if (arr[min] > arr[j])
				min = j;
		}

			if (i != min) {
				t = arr[i];
				arr[i] = arr[min];
				arr[min] = t;
			}
	}

	printf("Sorted list:\n");

	for (i = 0; i < n; i++) {
		printf("%d\n", arr[i]);
	}

	return 0;
}

			

