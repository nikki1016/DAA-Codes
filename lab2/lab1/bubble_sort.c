#include <stdio.h>

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
	scanf("%d", &n);
	int a[n];
	
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	bubblesort(a, n);
	
	for (i = 0; i < n; i++) {
		printf("%d\n", a[i]);
	}
	
	return 0;
}

