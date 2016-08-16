#include <stdio.h>
void quick(int a[],int low,int up);
int partition(int a[],int low,int up);
int key,n;
int main()
{
	int i;
	scanf("%d" , &n);
	int a[n];
	for(i = 0; i < n; i++)
	{
		scanf("%d" , &a[i]);
	}
	printf("enter no.  \n");
	scanf("%d" , &key);
	quick(a,0,n-1);
	
	
	return 0;
}
void quick(int a[],int low,int up)
{	//pivloc =low
	int pivloc;
	if(low > up)//low>=up
		return;
	pivloc = partition(a,low,up);
	if(pivloc==n-key) {//pivloc =low
		printf("Largest %d = %d\n",key,a[pivloc]);
		return;
	}
	else if(pivloc>n-key){ //pivloc =low
		quick(a,low,pivloc-1);
	}
	else {//pivloc =low
		quick(a,pivloc+1,up);
	}	
}
int partition(int a[],int low,int up)
{
	int temp,i,j,pivot;
	i = low+1;
	j = up;
	pivot = a[low];
	while(i <= j)
	{
		while((a[i] < pivot) &&(i < up))
			i++;
		while (a[j] > pivot)
			j--;
		if(i < j)
		{
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			i++;
			j--;
		}
		else
			i++;
	}
	a[low] = a[j];
	a[j] = pivot;
	return j;
}

