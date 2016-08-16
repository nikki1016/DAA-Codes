#include <stdio.h>
void quick(int a[],int low,int up);
int partition(int a[],int low,int up);
int key;
int main()
{
	int i, n;
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
{	
	int pivloc,i;
	if(low > up)
		return;
	pivloc = partition(a,low,up);
/*	printf("pivloc = %d\n",pivloc);
	for(i=low;i<=up;i++) {
		printf("%d\t",a[i]);
	}
	printf("\n");*/
	if(pivloc==key-1) {//pivloc =low
		printf("%d\n",a[pivloc]);
		return;
	}
	else if(pivloc>key-1){	//(pivloc - low)
		quick(a,low,pivloc-1);
	}
	else if(pivloc<key-1) {
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

