/* author @Abhimanyu Singh
	Rit2011001
*/

#include <stdio.h>

int main()
{
	int a[] = {21, 5, 6, 11, 9, 4, 3, 1, 19};
	int n = 9;
	int min_index;

	int i;
	int j;

	for (i = 0; i < n; i++) {
		for (j = 0; j < n - 1; j++) {
			if (a[j] > a[j + 1]) {
				int t;
		
				t = a[j];
				a[j] = a[j + 1];
				a[j + 1] = t;
			}
		}
	}

	printf("bubble sort : ");

	for (i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}

	printf("\n");

	return 0;
}
