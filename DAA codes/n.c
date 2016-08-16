#include <stdio.h>
#include <time.h>

clock_t begin, end;
double time_spent;

int main()
{
	int n, i, j, max, k = 0, temp, t;
	scanf("%d", &n);
	int a[n];
	int b[n];

	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	
	max = a[n-1];
	k = 0;
	begin = clock();
	for (i = n-2; i >= 0; i--) {
		if (a[i] > max) {
			max = a[i];
			b[k++] = a[i];
		}
	}
	end = clock();
	time_spent = (double)(end-begin)/CLOCKS_PER_SEC;

	for (i = 0; i < k; i++) {
		printf("%d\n", b[i]);
	}
	printf("%lf\n", time_spent);

	return 0;
}
		
