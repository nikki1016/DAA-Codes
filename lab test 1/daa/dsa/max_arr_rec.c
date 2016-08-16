#include <stdio.h>

int maxarr(int a[],int max,int n, int i);

int main()
{
	int i;
	int max;
	int n;
	int a[25];

	printf("Enter the size of an array: ");
	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	i = 0;
	max = maxarr(a,0, n, i);
	printf("the biggest number in the array is %d", max);

}

int maxarr(int a[],int max, int n, int i )
{
	if(i==0)
		max = a[0];
	if (i == n-1)
		return max;

	if ( a[i+1] > max)
		max = a[i+1];

	maxarr( a,max, n, i+1);
}




