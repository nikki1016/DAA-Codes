#include <stdio.h>
#include <math.h>

void quick(int arr[],int b[], int low, int up);
int partition(int arr[],int b[],int low, int up);

void quick(int a[],int b[], int low, int up)
{
	int pivloc;
	if(low >= up)
		return ;
	pivloc = partition(a,b, low, up);
	quick(a,b, low, pivloc-1);
	quick(a,b, pivloc+1, up);
}

int partition(int a[],int b[], int low, int up)
{
	int temp, i, j, pivot;
	i = low+1;
	j = up;
	pivot = a[low];
	while (i <= j) {
		while ((a[i] < pivot) && (i < up))
			i++;
		while (a[j] > pivot)
			j--;
		if (i < j) {
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			temp = b[i];
			b[i] = b[j];
			b[j] = temp;
			i++;j--;
		}
		else
			i++;
	}
	a[low] = a[j];
	a[j] = pivot;
	temp = b[low];
	b[low] = b[j];
	b[j] = temp;
	return j;
}
//
//void merge(int arr[],int b[],int temp[],int low1,int up1,int low2,int up2);
/*void copy(int arr[],int temp[],int low,int up)
{
	int i;
	for(i=low;i<=up;i++)
	arr[i]=temp[i];
}
void merge_sort(int arr[],int b[],int low,int up)
{
	int temp[100],mid;
	if(low<up)
	{
	mid=(low+up)/2;
	merge_sort(arr,b,low,mid);
	merge_sort(arr,b,mid+1,up);
	merge(arr,b,temp,low,mid,mid+1,up);
	copy(arr,temp,low,up);
	}
}
void merge(int arr[],int b[],int temp[],int low1,int up1,int low2,int up2)
{
	int i,j,k;
	i=low1;
	j=low2;
	k=low1;
	while(i<=up1&&j<=up2)
	{
		if(arr[i]<=arr[j])
		{
			temp[k]=arr[i];
			b[k]=b[i];
			k++;
			i++;
		}
		else
		{
			temp[k]=arr[j];
			b[k]=b[j];
			k++;
			j++;
		}
	}
	while(i<=up1)
	{
		temp[k]=arr[i];
		b[k]=b[i];
		k++;
		i++;
	}
	while(j<=up2)
	{
		temp[k]=arr[j];
		b[k]=b[j];
		k++;
		j++;
	}
}*/

double distance(int x[],int y[],int i,int j){
	double dist = sqrt(((y[j]-y[i])*(y[j]-y[i]))+((x[j]-x[i])*(x[j]-x[i])));
	return dist;
}
double merg(int x[],int y[],int l,int u,int m,double ldist,double rdist)
{
	int i, j,min_x,min_y;
	double min, mid, dis;
	int start,end;
//	mid = (x[l]+x[u])/2.0;
	if (ldist<=rdist)
		min = ldist;
	else
		min = rdist;
	quick(y,x,l,m);
	quick(y,x,m+1,u);
	start = m+1;
	end = start+5;
	for(i = l;i<=m;i++){
		for(j = start;j<=end&&j<=u;j++){
			dis = distance(x,y,i,j);
			if(dis<min){
				min = dis;
			}
		}
		while(abs(y[start]-y[i+1])>min)
		start++;
		end = start+5;
	}
	return min;
}

double closestpair(int x[],int y[],int n,int l,int u)
{
	double dis,xm,ldis,rdis;
	int med;
	med = (x[l]+x[u])/2.0;
	int i,m;
	if (l == u)
		return 999999999;
	else if (l == u-1) {
		return distance(x, y,l,u);
	}
	else {	
			for(i=l;i<=u;i++){
				if(x[i]==med) {
					m = i;
					break;	
				}
				if(x[i]>med){
					m = i-1;
					break;
				}
			}
		ldis = closestpair(x,y,n,l,m);
		rdis = closestpair(x,y,n,m+1,u);
		dis = merg(x, y, l, u, m, ldis, rdis);	
	}
	return dis;
}
int main()
{
	int n, i;
	double dist;
	scanf("%d", &n);
	int x[n];
	int y[n];
	for (i = 0; i < n; i++) {
		scanf("%d%d", &x[i],&y[i]);
	}
	quick(x,y, 0, n-1);
	for (i = 0; i < n; i++) {
		printf("x = %dy =%d\n", x[i],y[i]);
	}
	dist = closestpair(x,y,n,0,n-1);
	printf("%lf\n",dist);
	return 0;
}

