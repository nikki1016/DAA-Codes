#include <stdio.h>

void insertion_sort(float a[],int n)
{
	int j,i;
	float key;
	for(j=1;j<n;j++)
	{
		key=a[j];
		i=j-1;
		while(i>=0&&a[i]>key)
		{
			a[i+1]=a[i];
			i=i-1;
		}
		a[i+1]=key;
	}
}
void bucketSort(float arr[], int n)
{
    float b[10][n];
	int bi,i,a[10]={0},j;
    
    for (i=0; i<n; i++)
    {
       bi = 10*arr[i];
       b[bi][a[bi]]=(arr[i]);
       a[bi]++;
    }
    
    for (i=0; i<10; i++)
       insertion_sort(b[i],a[i]);
      int index = 0;
    for (i = 0; i < 10; i++)
        for (j = 0; j <a[i]; j++)
          arr[index++] = b[i][j];
}
 
int main()
{
    int n,k,i;
	scanf("%d",&n);
	float arr[n];
	for(i=0;i<n;i++)
	{
		scanf("%f",&arr[i]);
	}
    bucketSort(arr, n);
 
    printf("Sorted array is \n");
    for (i=0; i<n; i++)
       printf("%f\t",arr[i]);
    return 0;
}
