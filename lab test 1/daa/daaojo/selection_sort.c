#include <stdio.h>
int main ()
{
	int n, i, j, min, temp;
	printf("enter no. of elements to be sorted \n");
	scanf("%d" , &n);
	int a[n];
	for (i = 0; i < n; i++)
	{
		scanf("%d" ,&a[i]);
	}
	for(i = 0; i< n; i++)
	{
		min = i;
		for(j = i+1; j < n; j++)
		{
			if(a[min] > a[j])
				min = j;
		}
		if(i != min)
		{
			temp = a[i];
			a[i] = a[min];
			a[min] = temp;
		}
	}

	printf("sorted list is : ");
	for (i = 0; i < n; i++)
		{
			printf("%d " , a[i]);
		}
	printf("\n");

	return 0;
}








































