#include <stdio.h>
#define display(a,n) for(i=0;i<n;i++) printf("%d\t",a[i]);
int quick(int a[],int up);

int main()
{
	int i, n;
//	printf("enter no. of elements to be sorted: \n");
	scanf("%d" , &n);
	int a[1001];
	for(i = 0; i < n; i++)
	{
		scanf("%d" , &a[i]);
	}
	i = quick(a,n);
//	if(i==1) printf("%d\n",a[0]);
/*	printf("sorted list is: ");
	for(i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");*/
	return 0;
}
int quick(int a[],int size)
{
	
	if(size <= 1) return size;
	int pivot= a[0];
	int l[1000];
	int r[1000];
	int j,i,k;
	j=k=0;
	for(i=1;i<size;i++) {
		if(a[i]<=pivot){
			l[j] = a[i];
			j++;
		}
		else {
			r[k++]=a[i];		
		}
	}
	j = quick(l,j);
	k = quick(r,k);
	l[j]=pivot;
	j++;
	for(i=0;i<k;i++) {
		l[j]=r[i];
		j++;
	}
	for(i=0;i<j;i++){
		a[i]=l[i];
		printf("%d ",a[i]);
	}	
	printf("\n");
	return j;
	
}

