#include <stdio.h>
int partition ( int a[], int first, int last,int k )
{
	int i,j,pivot,temp;

	if ( first <= last ) 
	{
		i = first;
		j = last;
		pivot = last;
		while ( i < j ) 
		{
			while ( a[i] <= a[pivot] && i < last ) 
			{
				i++;
			}
			while ( a[j] > a[pivot] ) 
			{
				j--;
			}
			
			if ( i < j ) 
			{	
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}

		temp = a[j];
		a[j] = a[pivot];
		a[pivot] = temp;

		if ( k == pivot ) 
		{
			return a[k];
		}

		if ( j < k ) 
		{
			partition ( a,j+1,last,k);
		}
		
		else 
		{
			partition ( a,first,j-1,k );
		}
	}	
}

int main()
{
	int n,k,i;
	printf("enter the number of elements\n");
	scanf ( "%d",&n );
	int a[n];
	for ( i = 0; i < n; i++) 
	{
		scanf ( "%d", &a[i] );
	}

	printf ( "enter the element u want to find ?\n");
	scanf ( "%d", &k );
	int index = partition ( a, 0,n-1,k-1 );

	printf ( "%dth smallest no. is %d\n", k,index );
	return 0;
}
			
