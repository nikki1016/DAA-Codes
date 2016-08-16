#include <stdio.h>
int quick(int a[],int low,int up);
int partition(int a[],int low,int up);
int key;
int main()
{
	int i, n;
//	printf("enter no. of elements to be sorted: \n");
	scanf("%d" , &n);
	int a[n];
	for(i = 0; i < n; i++)
	{
		scanf("%d" , &a[i]);
	}
	printf("enter no.  \n");
	scanf("%d" , &key);
	int pos = quick(a,0,n-1);
	if(pos == -1) printf("Not found\n");
	else printf("Element found at: %d",pos+1);
	
	return 0;
}
int quick(int a[],int low,int up)
{
	int pivloc;
	if(low > up)
		return -1;
	pivloc = partition(a,low,up);
	if(a[pivloc] == key) return pivloc;
	if(a[pivloc>key]){
		return quick(a,low,pivloc-1);
	}
	else {
	return quick(a,pivloc+1,up);	
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

