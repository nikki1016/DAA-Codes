#include <iostream>
#include <stdio.h>
#include <math.h>
//#include <limits.h>
using namespace std;

struct node {
	double distance;
	int x1;
	int y1;
	int x2;
	int y2;
};

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
struct node merg(int x[],int y[],int l,int u,int m,struct node ldist,struct node rdist)
{
	int i, j,min_x,min_y;
	double mid,dis,d;
	struct node min; //= NULL;//*dis=NULL;
	mid = (x[l]+x[u])/2.0;
	if (ldist.distance<=rdist.distance)
		min = ldist;
	else
		min = rdist;
		
	for(i = m;i>=l;i--){
		d = min.distance;
		if (abs(mid-x[i]) > d) break;
		for(j=m+1;j<=u;j++){
			if(abs(x[j]-mid) > d) break;
			else {
				dis = distance(x,y,i,j);
				if(dis<d){
					min.distance = dis;
					min.x1 = x[i];
					min.y1 = y[i];
					min.x2 = x[j];
					min.y2 = y[j];
				}		
			}
		}
	}
	return min;
}

struct node closestpair(int x[],int y[],int n,int l,int u)
{
	struct node dis,ldis,rdis;
	int med;
	med = (x[l]+x[u])/2;
	int i,m;
	if (l == u){
		cout<<"l = u\n";
			dis.distance = 9999999999;
			dis.x1 = x[l];
			dis.y1 = y[l];
			dis.x2 = x[u];
			dis.y2 = y[u];
			cout<<"Returning\n";
			return dis;
	}
	
	else if (l == u-1) {
			dis.distance = distance(x, y,l,u);
			dis.x1 = x[l];
			dis.y1 = y[l];
			dis.x2 = x[u];		dis.y2 = y[u];
			return dis;
	}
	else {	cout<<"x[l] = "<<x[l]<<"l = "<<l<<" x[u] = "<<x[u]<<"\n";
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
			cout<<"Value of m :"<<m<<endl;
	
		ldis = closestpair(x,y,n,l,m);
		cout<<"Returning\n";
		rdis = closestpair(x,y,n,m+1,u);
		dis = merg(x, y, l, u, m, ldis, rdis);
	}
	return dis;
}
int main()
{
	int n, i;
	struct node dist;
	scanf("%d", &n);
	int x[n];
	int y[n];
/*n = 3;
int x[3] = {1,1,1};
int y[3] = {1,2,6};*/
	for (i = 0; i < n; i++) {
		scanf("%d%d", &x[i],&y[i]);
	}
	quick(x,y, 0, n-1);
//	for (i = 0; i < n; i++) {
//		printf("x = %dy =%d\n", x[i],y[i]);
//	}
	dist = closestpair(x,y,n,0,n-1);
	//if(dist==NULL) printf("Empty\n");
	printf("Minimum Distance = %lf (x1,y2) = (%d,%d) (x2,y2) = (%d,%d)\n",dist.distance,dist.x1,dist.y1,dist.x2,dist.y2);
	return 0;
}

