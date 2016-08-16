#include <stdio.h>
void quick(int a[],int low,int up);
int partition(int a[],int low,int up);
int main()
{
	int i, n;
	printf("enter no. of elements to be sorted: \n");
	scanf("%d" , &n);
	int a[n];
	for(i = 0; i < n; i++)
	{
		scanf("%d" , &a[i]);
	}
	quick(a,0,n-1);
	printf("sorted list is: ");
	for(i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	return 0;
}
void quick(int a[],int low,int up)
{
	int pivloc;
	if(low >= up)
		return;
	pivloc = partition(a,low,up);
	quick(a,low,pivloc-1);
	quick(a,pivloc+1,up);
}
int partition(int a[],int low,int up){
	int i = low -1;
	int j;
	int x=a[up];
	int temp;
	for(j=low;j<up;j++){
		if(a[j]<=x){
			i++;
			temp = a[j];
			a[j]=a[i];
			a[i]=temp;
		}
	}
	i++;
	a[up]=a[i];
	a[i] = x;
	return i;
}
