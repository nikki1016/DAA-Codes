#include <stdio.h>
#include <time.h>
int a[1000000];
int main() {
	time_t seconds;
	srand((unsigned int) seconds);
	int n, i;
	n=1000000;
	for (i = 0; i < n; i++) {
	a[i]= rand() %1000;
	printf("%d\t",a[i]);	
}
	return 0;
}
