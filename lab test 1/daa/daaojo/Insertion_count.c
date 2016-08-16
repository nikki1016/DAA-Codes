#include<stdio.h>
int main()
{
	int i, j, k, n;
	printf("enter the no. of elements to be sorted : ");
	scanf("%d" , &n);
	int a[n];
	for (i = 0; i < n; i++)
	{
		scanf("%d" , &a[i]);
	}
	int c =0;
	for(i = 1; i < n; i++)
	{
		k = a[i];
		for(j = i-1; j >= 0 && k < a[j]; j--)
		{
			c++;
			a[j+1] = a[j];
		}			
		a[j+1] = k;
	}
	printf("Number of Swaps = %d .Sorted list is: ",c);
	for(i = 0; i < n; i++)
	{
		printf("%d " , a[i]);
	}
	printf("\n");
	return 0;
}


