#include <stdio.h>
#include <time.h>

clock_t begin, end;
double time_spent;

int main()
{
	int n, i, j, k = 0, fg;
	scanf("%d", &n);

	int a[n];
	int b[n];

	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	
	begin = clock();

	for (i = 0; i < n-1; i++) {
		fg = 0;
		for (j = i+1; j < n; j++) {
			if (a[i] > a[j]) 
				continue;
			else{
				fg = 1;
				break;
			}
		}
		if (fg == 0)
		b[k++] = a[i];
	}

	end = clock();
	time_spent = (double)(end - begin)/CLOCKS_PER_SEC;

	for (i = 0; i < k; i++) {
		printf("%d\n", b[i]);
	}

	printf("%lf\n", time_spent);

	return 0;
}


